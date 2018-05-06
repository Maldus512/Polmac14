#include "HardwareProfile.h"
#include "main.h"
#include "displayDriver.h"
#include "pwmBacklight.h"
#include "peripherals.h"
#include "HardwareProfile.h"
#include "parameterStore.h"

_INLINE void disabilitaIntPulsanti() {
    _CN26IE = 0;
    _CN27IE = 0;
    _CN28IE = 0;
    _CN29IE = 0;
    _CN9IE = 0;
    _CNIE = 0;
}

_INLINE void abilitaIntPulsanti() {
    _CN26IE = 1;
    _CN27IE = 1;
    _CN28IE = 1;
    _CN29IE = 1;
    _CN9IE = 1;
    _CNIE = 1;
}

volatile int contaT1;
extern unsigned char gotosleep;
extern volatile unsigned long long cont;
extern char chiuso; //TODO sostituire con force init
extern tParameter paramStore[PARAM_NUM];

void initSleep() {
    disabilitaIntPulsanti();
    contaT1 = paramStore[T_SLEEP].value.ui16;

    //Timer 1 : timeout per entrare in sleep
#if MHZ==1
    T1CON = 0x0010; // abilita in idle, gated accumulation off, prescaler 8,  clock source internal, in STOP
    PR1 = 62500; // 1 secondo
#elif MHZ==2
    T1CON = 0x0020; // abilita in idle, gated accumulation off, prescaler 64,  clock source internal, in STOP
    PR1 = 15625; // 1 secondo
#elif MHZ==4
    T1CON = 0x0020; // abilita in idle, gated accumulation off, prescaler 64,  clock source internal, in STOP
    PR1 = 31250; // 1 secondo
#elif MHZ==8
    T1CON = 0x0020; // abilita in idle, gated accumulation off, prescaler 64,  clock source internal, in STOP
    PR1 = 62500; // 1 secondo
#else
#error Invalid clock frequency;
#endif
    TMR1 = 0;
    _T1IE = 1;
    _T1IP = 4; // default
    T1CONbits.TON = 1;

    _EXTR = 0; //azzero i flag
    _BOR = 0;
    _POR = 0;
    _VDDPOR = 0;
    _VDDBOR = 0;
    _VBPOR = 0;
    _VBAT = 0;
}

_INLINE void azzera_sleep_func(void) {
    //azzeramento timeout sleep
    TMR1 = 0;
    contaT1 = paramStore[T_SLEEP].value.ui16;
}

void _ISR_NO_PSV _T1Interrupt(void) {
    // è passato un secondo
    _T1IF = 0;
    TMR1 = 0;
    contaT1--;

    if (contaT1 == 0) {
        gotosleep = TRUE;
        contaT1 = paramStore[T_SLEEP].value.ui16;
    }
}

void wakeUp() {
    // risveglio da sleep
    RCONbits.DPSLP = 0;
    RCONbits.SLEEP = 0;
    //stato = DISPLAY;
    disabilitaIntPulsanti();
    chiuso = TRUE;
    T2CONbits.TON = 1;
}

void goToSleep() {
    // funzione per entrare in sleep

    T2CONbits.TON = 0;
    gotosleep = FALSE;
    //SPEGNI IL DISPLAY
    LCDshutdown();
    //spegni la retroilluminazione
    PWMledLCD_OFF_quick();
    abifotores = 0;
    abicoperchio = 0;

    //writeParam(COUNTER);

    abilitaIntPulsanti();
    Sleep();

    //deep sleep eliminato perchè permette il risveglio solo con INT0
    //    asm("bset DSCON, #15");
    //    asm("nop");
    //    asm("nop");
    //    asm("nop");
    //    asm("bset DSCON, #15");
    //    asm("pwrsav #0");
    
    wakeUp();
}


// le sue ISR seguenti non fanno nulla in quanto hanno solo lo scopo di risvegliare la scheda

void _ISR_NO_PSV
_INT0Interrupt(void) {
    IFS0bits.INT0IF = 0; // Clear Interrupt Flag
}

void _ISR_NO_PSV _CNInterrupt(void) {
    _CNIF = 0;
}
