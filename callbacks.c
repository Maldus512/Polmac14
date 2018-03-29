#include "main.h"
#include "parameterStore.h"
#include "display.h"
#include "displayDriver.h"
#include "HardwareProfile.h"
#include "pageFactory.h"
#include "peripherals.h"
#include "flowMeter.h"
#include "clock.h"


extern tParameter paramStore[21];

extern unsigned int pila;
extern char oldlowbatt;
extern unsigned char LCD_changed;
extern unsigned int sole,pila;


void c_lingua() {
    initPagine();
    if (pila < paramStore[AUTO_PILA].value.ui16)
        oldlowbatt = FALSE;
    else
        oldlowbatt = TRUE;

    LCD_changed = 0xFF;
}

void c_impulsi() {
    initFlowMeter();
    convertImpulsi();
}

void c_unita() {
    //TODO migliorare, non c'è bisogno di rifare tutto
    initPagine();
    initFlowMeter();
    LCD_changed = LCD_changed | 8; //valore impulsi per litro
}

void c_evidenzia() {
    //TODO migliorare, solo pagina 0
    initPagine();
}

void c_password() {
    if ((paramStore[PASSWORD].value.ui16 == 12345) || (paramStore[PASSWORD].value.ui16 == 71)) {
        //reset litri totali
        resetTotalCounter();
        paramStore[PASSWORD].value.ui16 = 0;
        LCD_changed = LCD_changed | 0x02;
        refresh_values_p3();
    } else if ((paramStore[PASSWORD].value.ui16 == 22222) || (paramStore[PASSWORD].value.ui16 == 69)) {
        paramStore[PASSWORD].value.ui16 = 0;
        //refresh_values_p3();
        cambioPagina(TRUE);
    }
}

void c_abReed() {
    abicoperchio = paramStore[AB_REED].value.uc8;
}

void c_abFotores() {
    abifotores = paramStore[AB_FOTORES].value.uc8;
}

void c_sole_up() {
    //TODO fare funzione reset
    sole = 100;
    paramStore[AUTO_SOLE].value.ui16 = sole;
}

void c_sole_down() {
    //TODO fare funzione get soglia
    abifotores = 1;
    delay_us(1600);
    sole = readADC(ADC_fotores);
    delay_us(1600);
    abifotores = 0;
    paramStore[AUTO_SOLE].value.ui16 = sole;
}

void c_pila_up() {
    pila = 330;
    paramStore[AUTO_PILA].value.ui16 = pila;
}

void c_pila_down() {
    //abipila         = 1                     ;
    //delay_us(1600);
    pila = readADC(ADC_batterysense);
    //delay_us(1600);
    //abipila         = 0                     ;
    paramStore[AUTO_PILA].value.ui16 = pila;
}

void c_clock_tune()
{
    clockTune();
}

void c_low_v_save()
{
    if(paramStore[EN_HLVD].value.uc8 == FALSE)
    {
        paramStore[COUNTER].value.ui32 = 0;
        writeParam(COUNTER);
    }
    initHLVD();
}