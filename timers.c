#include "HardwareProfile.h"
#include "peripherals.h"
#include "display.h"
#include "main.h"
#include "timers.h"
#include "pwmBacklight.h"
#include <limits.h>
#include "sleep.h"
#include "parameterStore.h"


volatile int contaT2;

extern volatile unsigned char refresh_batt, refresh_LCD, refresh_values, refresh_keys;

extern volatile unsigned long long secondi, secondi_set;

extern unsigned char currpage;
extern unsigned char target_led_level;

extern tParameter paramStore[PARAM_NUM];

volatile unsigned char planner = 0;



//NOTA
//TIMER1 timeout per sleep. 1sec
//TIMER2 refresh display, batteria e fotores + conteggio impulsi e calcolo flusso. 250ms
//TIMER3 usato come contatore impulsi
//TIMER4 10ms
//TIMER5 timeout retroilluminazione. 1sec

void initTimers(void) {
    

    //Timer2 : Refresh LCD e (ogni 600 volte) batteria e fotores
    // flusso!!!!
#if MHZ==1
    T2CON = 0x0010; // abilita in idle, gated accumulation off, prescaler 8, 32bit mode off, clock source internal, in STOP
    PR2 = 15624; // 250ms
#elif MHZ==2
    T2CON = 0x0010; // abilita in idle, gated accumulation off, prescaler 8, 32bit mode off, clock source internal, in STOP
    PR2 = 31249; // 250ms
#elif MHZ==4
    T2CON = 0x0010; // abilita in idle, gated accumulation off, prescaler 8, 32bit mode off, clock source internal, in STOP
    PR2 = 62499; // 250ms
#elif MHZ==8
    T2CON = 0x0020; // abilita in idle, gated accumulation off, prescaler 64, 32bit mode off, clock source internal, in STOP
    PR2 = 15624; // 250ms
#else
#error Invalid clock frequency;
#endif
    TMR2 = 0;
    _T2IE = 1;
    _T2IP = 6; // alta
    T2CONbits.TON = 1;
    contaT2 = paramStore[SEC_PILA_FOTORES].value.uc8 * 4;


    //Timer4 : 10ms scheduler
#if MHZ==1
    //16us
    T4CON = 0xA000; // disabilita in idle, gated accumulation off, prescaler 1, 32bit mode off, clock source internal, in RUN
    PR4 = 4999;
#elif MHZ==2
    //8us
    T4CON = 0xA000; // disabilita in idle, gated accumulation off, prescaler 1, 32bit mode off, clock source internal, in RUN
    PR4 = 9999;
#elif MHZ==4
    T4CON = 0xA000; // disabilita in idle, gated accumulation off, prescaler 1, 32bit mode off, clock source internal, in RUN
    PR4 = 19999;
#elif MHZ==8
    //16us
    T4CON = 0xA010; // disabilita in idle, gated accumulation off, prescaler 8, 32bit mode off, clock source internal, in RUN
    PR4 = 4999;
#else
#error Invalid clock frequency;
#endif
    TMR4 = 0;
    _T4IE = 1;
    _T4IP = 4; // alta
    T4CONbits.TON = 1;

}//initTimers



void _ISR_NO_PSV _T2Interrupt(void) {
    //alza i flag per indicare se è necessario rinfrescare LCD e livello batteria
    _T2IF = 0;

    //refresh_LCD = TRUE;

    contaT2--;
    if (contaT2 == 0) {
        contaT2 = paramStore[SEC_PILA_FOTORES].value.uc8 * 4;
        refresh_batt = TRUE;
    }

    refreshFlowMeter();

}

void _ISR_NO_PSV _T4Interrupt(void) {
    //10 ms clock
    _T4IF = 0;

    refresh_keys = TRUE;
    
    //ogni 20ms scarico una riga
    if((planner & 0x01) == 0x00)
        refresh_LCD = TRUE;

    switch(planner)
    {
        case 25:
            refresh_values = TRUE;
            break;
 
    }

    planner++;
    if (planner == 26)
        planner = 1;
}


