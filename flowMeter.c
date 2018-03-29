#include "main.h"
#include "HardwareProfile.h"
#include "parameterStore.h"
#include <limits.h>




//flussometro
unsigned long long litritot = 0; // ml, max 4Ml
unsigned long long litriparz = 0; // ml, max 4Ml
unsigned long long flusso = 0; // ml/min max 65l/min
volatile unsigned long long cont = 0;
//volatile unsigned long long oldcont     = 0             ;
volatile unsigned long long contaimpulsi = 0;
volatile unsigned long long parzcont = 0;
volatile unsigned long long temp = 0;
float magic = 1;

volatile unsigned long long flussi[10];
volatile unsigned char idxflusso = 0;
volatile unsigned char mineqmax = 0;
volatile float flussoF = 0;

unsigned long long oldimpulsi = 1000;


extern tParameter paramStore[21];

void initCont(void) {
    //Timer3 : contatore di impulsi
    T3CON = 0x8002; // abilita in idle, gated accumulation off, prescaler 1, 32bit mode off, clock source internal, in RUN
    TMR3 = 0;
    PR3 = 65535;
    _T3IE = 0;
    _T3IP = 2; // bassa
    RPINR3bits.T3CKR = 26; //21;
    T3CONbits.TON = 1;

    int i;
    for (i = 0; i < 10; i++)
        flussi[i] = 0;
}

void initFlowMeter() {
    // calcolo il fattore di conversione da impulsi a l/min o gal/min o m3/h
    // *4 perchè ho un campione ogni 250ms, *60 secondi in un minuto
    // 1000 faccio i conti in millesimi
    // 10?????
    switch (paramStore[UNITA].value.uc8) {
        case LITRI:
            magic = 2400000.0 / (float) paramStore[IMPULSI].value.ui16;
            break;
        case GALLONI:
            //1gal=3.785411784 l
            magic = 634012.9256595562 / (float) paramStore[IMPULSI].value.ui16;
            break;
        case METRICUBI:
            // 10000 litri in un m3, 60 min in 1h
            magic = 144000.0 / (float) paramStore[IMPULSI].value.ui16;
            break;
    }
    
    oldimpulsi = paramStore[IMPULSI].value.ui16;
}

_INLINE void refreshFlowMeter() {
    temp = TMR3; //contatore impulsi
    TMR3 -= temp;
    cont += temp;
    contaimpulsi += temp;
    parzcont += temp;
    // mod 30/12/2013: media mobile per il calcolo del flusso
    if (temp > 0) {
        flussi[idxflusso] = temp;
        azzera_sleep_func();
        if (paramStore[T_BACKLIGHT].value.ui16 == 600)
            azzera_backlight_func();
    } else
        flussi[idxflusso] = 0;
    idxflusso = (idxflusso + 1) % paramStore[N_MEDIA].value.uc8;
    if (idxflusso == 0)
        idxflusso = idxflusso;

    unsigned long long max = flussi[0]; //0
    unsigned long long min = flussi[0]; //ULLONG_MAX
    int imax = 0;
    int imin = 0;
    int i;
    if (paramStore[N_MEDIA].value.uc8 > 1) {
        for (i = 1; i < paramStore[N_MEDIA].value.uc8; i++) {
            if (flussi[i] > max) {
                max = flussi[i];
                imax = i;
            }
            if (flussi[i] < min) {
                min = flussi[i];
                imin = i;
            }
        }
    }
    flussoF = 0;
    for (i = 0; i < paramStore[N_MEDIA].value.uc8; i++) {
        if ((i != imax && i != imin) || paramStore[N_MEDIA].value.uc8 < 3)
            flussoF += (float) flussi[i];
    }
    if (imin == imax)
        mineqmax = TRUE;
    else
        mineqmax = FALSE;
}

_INLINE void calculateFlow() {
    //calcolo del flusso nuova versione
    float temp = flussoF;
    if (paramStore[N_MEDIA].value.uc8 < 3)
        temp = magic * temp / (float) (paramStore[N_MEDIA].value.uc8);
    else {
        if (mineqmax == TRUE)
            temp = magic * temp / (float) (paramStore[N_MEDIA].value.uc8 - 1);
        else
            temp = magic * temp / (float) (paramStore[N_MEDIA].value.uc8 - 2);
    }
    if ((temp <= (float) ULLONG_MAX) && (temp >= 0.0)) {
        flusso = (unsigned long long) temp;
        //if (paramStore[UNITA].value.uc8 == METRICUBI)
        //    flusso *= 60;
    } else
        flusso = 0;
}

_INLINE void calculateTotals() {
    switch (paramStore[UNITA].value.uc8) {
        case LITRI:
            litritot = (unsigned long long) (10000 * cont / paramStore[IMPULSI].value.ui16); //ml passati
            litriparz = (unsigned long long) (10000 * parzcont / paramStore[IMPULSI].value.ui16); //ml passati
            break;
        case GALLONI:
            //1gal=3.785411784l
            //arrotondamento di 0.01%
            litritot = (unsigned long long) (2642 * cont / paramStore[IMPULSI].value.ui16); //ml passati
            litriparz = (unsigned long long) (2642 * parzcont / paramStore[IMPULSI].value.ui16); //ml passati
            break;
        case METRICUBI:
            litritot = (unsigned long long) (10 * cont / paramStore[IMPULSI].value.ui16); //ml passati
            litriparz = (unsigned long long) (10 * parzcont / paramStore[IMPULSI].value.ui16); //ml passati
            break;
    }
}

void convertImpulsi() {
    cont = (unsigned long long) ((float) cont * (float) paramStore[IMPULSI].value.ui16 / (float) oldimpulsi);
    parzcont = (unsigned long long) ((float) parzcont * (float) paramStore[IMPULSI].value.ui16 / (float) oldimpulsi);
    oldimpulsi = paramStore[IMPULSI].value.ui16;
}

_INLINE void resetTotalCounter() {
    TMR3 = 0;
    cont = 0;
    //parzcont=0;
    contaimpulsi = 0;
}
