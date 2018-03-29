#include "HardwareProfile.h"
#include "peripherals.h"
#include "display.h"
#include "main.h"
#include "HardwareProfile.h"
#include "adc.h"
#include "pageFactory.h"
#include "parameterStore.h"




unsigned char target_led_level = 0; // può essere = backled_level o 0
unsigned char current_led_level = 0;
volatile unsigned char ledisonflag = 0; // abilitazione della retro
volatile int contaT5;
extern volatile unsigned long long secondi; // conteggio secondi per verificare la precisione del clock
extern volatile unsigned long long secondi_set; // per contare i 3 secondi per azzerare litri tot
extern unsigned int sole; // livello da ADC

extern tPageInfo *activePage;
extern tParameter paramStore[21];

//reset timeout spegnimento retro

_INLINE void azzera_backlight_func(void) {
    contaT5 = paramStore[T_BACKLIGHT].value.ui16 + paramStore[LUMINOSITA].value.uc8 / 2;
}

void initPWM(void) {

    //modulo pwm
    OC1CON1 = 0;
    OC1CON2 = 0;
    _RP21R = 0; // 18= OC1, 0=niente

    OC1RS = 25 * MHZ - 1;
    OC1R = 8 * MHZ;

    OC1CON2bits.SYNCSEL = 0x1F; // sè stesso
    OC1CON2bits.OCTRIG = 0;
    OC1CON2bits.OCINV = 0; // attivo basso?
    OC1CON1bits.OCTSEL = 7; // uso il clock come timer
    OC1CON1bits.OCM = 0; // 6=PWM senza fault, 0=disabilitato

    azzera_backlight_func();

    //Timer5 : retroilluminazione LCD
#if MHZ==1
    T5CON = 0x0010; // abilita in idle, gated accumulation off, prescaler 8,  clock source internal, in STOP
    PR5 = 62500; // 1 secondo
#elif MHZ==2
    T5CON = 0x0020; // abilita in idle, gated accumulation off, prescaler 64,  clock source internal, in STOP
    PR5 = 15625; // 1 secondo
#elif MHZ==4
    T5CON = 0x0020; // abilita in idle, gated accumulation off, prescaler 64,  clock source internal, in STOP
    PR5 = 31250; // 1 secondo
#elif MHZ==8
    T5CON = 0x0020; // abilita in idle, gated accumulation off, prescaler 64,  clock source internal, in STOP
    PR5 = 62500; // 1 secondo
#else
#error Invalid clock frequency;
#endif
    TMR5 = 0;
    _T5IE = 1;
    _T5IP = 4; // default
    T5CONbits.TON = 1;

}//initPWM

//spegnimento istantaneo della retro

void PWMledLCD_OFF_quick(void) {
    if (ledisonflag) {
        OC1CON1bits.OCM = 0;
        _RP21R = 0;
        ledLCD = 1;
        ledisonflag = 0;
    }
    target_led_level = 0;
    current_led_level = 0;
}

// rinfresco del livello di luminosità

unsigned char retro_level(void) {
    if (current_led_level == 0 && target_led_level > 0 && !ledisonflag) {
        OC1R = (25 - 5 / 2) * MHZ;
        _RP21R = 18;
        OC1CON1bits.OCM = 6;
        azzera_backlight_func();
        ledisonflag = 1;
    }
    
    if (current_led_level < target_led_level) {
        current_led_level++;
        OC1R = (25 - 5 * current_led_level / 2) * MHZ;
    } else if (current_led_level > target_led_level) {
        current_led_level--;
        OC1R = (25 - 5 * current_led_level / 2) * MHZ;
    }

    //spengo il modulo pwm se il livello è 0
    if (current_led_level == 0 && target_led_level == 0 && ledisonflag) {
        OC1CON1bits.OCM = 0;
        _RP21R = 0;
        ledLCD = 1;
        ledisonflag = 0;
    }

    return (current_led_level == target_led_level);
}

void refreshSole(unsigned char withSensor) {
    if (withSensor) {
        abifotores = 1;
        delay_us(1600);
        sole = readADC(ADC_fotores);
        delay_us(1600);
        abifotores = 0;
    }
    if (sole > paramStore[AUTO_SOLE].value.ui16)
        target_led_level = 0;
    else if(contaT5 > 0)
        target_led_level = paramStore[LUMINOSITA].value.uc8;
}

void _ISR_NO_PSV _T5Interrupt(void) {
    //timeout retroilluminazione
    _T5IF = 0;
    secondi++;
    secondi_set++;
    if (contaT5 > 0)
        contaT5--;
    if (contaT5 == 0) {
        // se sono nella pagina 0, spengo gradualmente la retro
        if (activePage->key == 0 || activePage->key == 10) 
            target_led_level = 0;
//        else
//            azzera_backlight_func();
    }

}
