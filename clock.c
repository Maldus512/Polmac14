#include "main.h"
#include "HardwareProfile.h"
#include "parameterStore.h"


extern tParameter paramStore[PARAM_NUM];

void initClock() {
#if MHZ==1
    CLKDIVbits.RCDIV = 3;
#elif MHZ==2
    CLKDIVbits.RCDIV = 2;
#elif MHZ==4
    CLKDIVbits.RCDIV = 1;
#elif MHZ==8
    CLKDIVbits.RCDIV = 0;
#else
#error Invalid clock frequency;
#endif
    ClrWdt();
    _RETEN = 1;
}

void clockTune() {
    if (paramStore[CLK_TUNE].value.si16 >= 0)
        OSCTUNbits.TUN = paramStore[CLK_TUNE].value.si16;
    else
        OSCTUNbits.TUN = paramStore[CLK_TUNE].value.si16 + 64;
}
