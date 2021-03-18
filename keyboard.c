#include "HardwareProfile.h"
#include "peripherals.h"
#include "main.h"
#include "pwmBacklight.h"
#include "display.h"
#include "displayDriver.h"
#include "adc.h"
#include "peripherals.h"
#include "sleep.h"
#include "pageFactory.h"
#include "wdt.h"


char mode = FALSE; // pulsante in alto a sinistra
char set = FALSE; // pulsante in basso a sinistra
char up = FALSE; // pulsante in alto a destra
char down = FALSE; // pulsante in basso a destra
char chiuso = TRUE; // coperchio
char oldmode = FALSE, oldset = FALSE, oldup = FALSE, olddown = FALSE, oldchiuso = TRUE; // boolean
//unsigned long long oldimpulsi = 1000;

extern unsigned int pila, sole; // livello da ADC
//extern unsigned int batteria			= 0		; // livello da ADC
extern volatile unsigned char refresh_batt, refresh_keys; // boolean flag
extern unsigned short soglia_batteria;

extern unsigned char display_reverse;
extern unsigned char reverse_splash;
int i;
extern unsigned char LCD_changed;
extern unsigned char nextrow;
unsigned int incremento = 1;
unsigned int aggiungi = 1;
volatile unsigned long long secondi_set = 0; // per contare i 3 secondi per azzerare litri tot
extern volatile unsigned long long parzcont;
varInt amount;

unsigned char debounce;
extern tPageInfo *activePage;
extern tPageInfo userPages[0];
extern tParameter paramStore[19];

extern unsigned char pause;




void gestioneCoperchio()
{
    oldchiuso = chiuso;

    abicoperchio = 1;
    delay_us(1600);
    chiuso = coperchio;
    delay_us(1600);
    abicoperchio = 0;

    if (chiuso) //test ingressi
    {
        if (!oldchiuso)
        {
            //SPEGNI IL DISPLAY
            LCDshutdown();
            //spegni la retroilluminazione
            PWMledLCD_OFF_quick();
        }
    }
    else
    {
        if (oldchiuso)
        {
            //ACCENDI IL DISPLAY
            //T2CONbits.TON = 1;
            init_LCD();
            activePage = &userPages[0];
            activePage->selectedVar = 0;

            if (paramStore[REVERSE_MAIN].value.uc8)
                display_reverse = 56;
            else
                display_reverse = 0;

            paint_splash();
            //accendi retroilluminazione se fotores<soglia
            azzera_backlight_func();
            refreshSole(TRUE);

            for (i = 0; i < 10; i++)
            {
                wdt_set_flag(WDT_FLAG_MAIN); // Attiva WDT per evitare un reset
                delay_ms(400);
                if (retro_level())
                    ; //break;
            }
            refresh_values_p0(); //TODO
            //refresh_display();
            LCD_changed = 0xFF;
            nextrow = 0;
        }
    }
}





void leggiPulsanti()
{
    oldup = up;
    olddown = down;
    oldmode = mode;
    oldset = set;

    up = !upbtn;        //attivi bassi
    down = !downbtn;
    mode = !modebtn;
    set = !setbtn;

    if (debounce == 0)
    {
        if (mode || set || up || down)
        {
            azzera_sleep_func();
            azzera_backlight_func();
            refreshSole(FALSE);
        }

        if (mode && !oldmode && !set && !up && !down)
        {
            //cambio pagina next
            cambioPagina(FALSE);
            debounce = 5; //50ms
        } else if (set && !oldset && !mode && !up && !down)
        {
            //cambio var
            cambioVariabile();
            debounce = 5; //50ms
        }
        else if (up && !oldup && !mode && !set && !down)
        {
            // var ++
            if (activePage->paramNumber > 0)
            {
                incremento = 1;
                amount.uc8 = 1;
                amount.ui16 = 1;
                amount.ui32 = 1;
                amount.si16 = 1;
                increment(activePage->params[activePage->selectedVar]->key, amount);
                debounce = 25; //TODO o 5 se bool?
                (*activePage->displayFunction)();
                if (activePage->key == 8) // test uscite - una riga per parametro
                    LCD_changed = LCD_changed | (1 << (activePage->selectedVar << 0));
                else
                    LCD_changed = LCD_changed | (2 << (activePage->selectedVar << 1));
            }
        }
        else if (down && !olddown && !mode && !set && !up)
        {
            // var --
            if (activePage->paramNumber > 0)
            {
                incremento = 1;
                amount.uc8 = 1;
                amount.ui16 = 1;
                amount.ui32 = 1;
                amount.si16 = 1;
                decrement(activePage->params[activePage->selectedVar]->key, amount);
                debounce = 25; //TODO o 5 se bool
                (*activePage->displayFunction)();
                if (activePage->key == 8) // test uscite - una riga per parametro
                    LCD_changed = LCD_changed | (1 << (activePage->selectedVar << 0));
                else
                    LCD_changed = LCD_changed | (2 << (activePage->selectedVar << 1));
            }
        }
        else if (up && oldup && !mode && !set && !down)
        {
            // var ++++
            if (activePage->paramNumber > 0)
            {
                if (activePage->params[activePage->selectedVar]->key == PASSWORD ||
                        activePage->params[activePage->selectedVar]->key == IMPULSI ||
                        activePage->params[activePage->selectedVar]->key == T_BACKLIGHT ||
                        activePage->params[activePage->selectedVar]->key == T_SLEEP ||
                        activePage->params[activePage->selectedVar]->key == SEC_PILA_FOTORES)
                {
                    incremento++;

                    if (incremento < 10)
                        aggiungi = 1;
                    else
                        if (incremento < 20)
                        aggiungi = 10;
                    else
                        if (incremento < 30)
                        aggiungi = 100;
                    else
                        aggiungi = 1000;
                    amount.uc8 = aggiungi; //TODO con 1000 errore
                    amount.ui16 = aggiungi;
                    amount.ui32 = aggiungi;
                    amount.si16 = aggiungi;
                    increment(activePage->params[activePage->selectedVar]->key, amount);
                    debounce = 25;
                    (*activePage->displayFunction)();
                    if (activePage->key == 8) // test uscite - una riga per parametro
                        LCD_changed = LCD_changed | (1 << (activePage->selectedVar << 0));
                    else
                        LCD_changed = LCD_changed | (2 << (activePage->selectedVar << 1));
                }
            }
        }
        else if (down && olddown && !mode && !set && !up)
        {
            // var ----
            if (activePage->paramNumber > 0)
            {
                if (activePage->params[activePage->selectedVar]->key == PASSWORD ||
                        activePage->params[activePage->selectedVar]->key == IMPULSI ||
                        activePage->params[activePage->selectedVar]->key == T_BACKLIGHT ||
                        activePage->params[activePage->selectedVar]->key == T_SLEEP ||
                        activePage->params[activePage->selectedVar]->key == SEC_PILA_FOTORES)
                {
                    incremento++;
                    if (incremento < 10)
                        aggiungi = 1;
                    else
                        if (incremento < 20)
                        aggiungi = 10;
                    else
                        if (incremento < 30)
                        aggiungi = 100;
                    else
                        aggiungi = 1000;
                    amount.uc8 = aggiungi; //TODO con 1000 errore
                    amount.ui16 = aggiungi;
                    amount.ui32 = aggiungi;
                    amount.si16 = aggiungi;
                    decrement(activePage->params[activePage->selectedVar]->key, amount);
                    debounce = 25;
                    (*activePage->displayFunction)();
                    if (activePage->key == 8) // test uscite - una riga per parametro
                        LCD_changed = LCD_changed | (1 << (activePage->selectedVar << 0));
                    else
                        LCD_changed = LCD_changed | (2 << (activePage->selectedVar << 1));
                }
            }
            if (activePage->key == 9)
                cambioPagina(TRUE); //ritorna a main
        }
        else
        {
            //nessun pulsante
            switch (activePage->key)
            {
                case 0:
                    LCD_changed = LCD_changed | 0xB4; //righe 2,4, 5 e 7
                    break;

                case 5:
                    LCD_changed = LCD_changed | 32;
                    break;

                case 6:
                    LCD_changed = LCD_changed | 0x0F; //righe 1-3 ---0x2A; //righe 1,3,5
                    break;

                case 7:
                    LCD_changed = LCD_changed | 0x3F; //righe 1-6
                    break;

                case 8:
                    LCD_changed = LCD_changed | 0x03; //righe 0-1   ---0x0F; //righe 1-3
                    break;

                case 9:
                    LCD_changed = LCD_changed | 0x2A; //righe 1,3,5  ---0xAA; //righe 1,3,5,7
                    break;

                case 10:
                    LCD_changed = LCD_changed | 0xF4; //righe 2,4, 5 6 7
                    break;
            }

        }

        // ****** COMBINAZIONI PARTICOLARI IN PAGINA PRINCIPALE

        if (activePage->key == 0 || activePage->key == 10)
        {
            if (((up != oldup) || (down != olddown)) || ((mode != oldmode) || (set != oldset)))
                secondi_set = 0;

            if (mode && set && up && down && secondi_set > 3)
            {
                cambioPagina(TRUE);
                debounce = 5; //50ms
            }
            else if (set && !mode && !up && !down && secondi_set > 3)
            {
                //azzero il parziale
                parzcont = 0;
            }
            else if (set && !mode && !up && down && secondi_set > 3)
            {
                secondi_set = 0;
                // pausa conteggio
                if (pause)
                {
                    pause = 0;
                    T3CONbits.TON = 1;
                }
                else
                {
                    pause = 1;
                    T3CONbits.TON = 0;
                }
            }
        }
        else if (activePage->key == 3)
        {
            if (((up != oldup) || (down != olddown)) || ((mode != oldmode) || (set != oldset)))
                secondi_set = 0;

            if (!mode && !set && up && down && secondi_set > 3)
            {
                //reset litri totali
                resetTotalCounter();
                secondi_set = 0;
                cambioPagina(FALSE);
            }
        }
    }
    else
    {
        debounce--;
    }
}
