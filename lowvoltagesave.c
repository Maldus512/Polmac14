#include "HardwareProfile.h"
#include "displayDriver.h"
#include "pwmBacklight.h"
#include "main.h"
#include "parameterStore.h"


extern char en_hlvd;
extern volatile unsigned long long cont;
volatile unsigned int a,b;
extern tParameter paramStore[21];



void initHLVD(void) {
    if (paramStore[EN_HLVD].value.uc8) {
        _LVDMD = 0;
    } else {
        _LVDMD = 1;
    }
    HLVDCONbits.HLVDL = 0b1001; //2.7V level
    HLVDCONbits.LSIDL = 0; //continua in idle
    HLVDCONbits.VDIR = 0; //int se V<soglia
    if (paramStore[EN_HLVD].value.uc8) {
        _LVDIE = 1;
        HLVDCONbits.HLVDEN = 1;
    } else {
        _LVDIE = 0;
        HLVDCONbits.HLVDEN = 0;
    }
    IFS4bits.LVDIF = 0;
    IPC18bits.LVDIP = 7;//massima
}

void _ISR_NO_PSV _LVDInterrupt(void) {
    IFS4bits.LVDIF = 0;
    PWMledLCD_OFF_quick();
    paramStore[COUNTER].value.ui32 = cont;
    paramStore[COUNTER].oldvalue.ui32 = cont + 1;//forza scrittura sempre
    writeParam(COUNTER);
    LCDshutdown();
    //TODO reset mcu
}
