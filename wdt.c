#include <xc.h>
#include <assert.h>
#include "wdt.h"


static int wdt_flags[WDT_FLAGS] = {0};


void wdt_set_flag(wdt_flag_t flag) {
    assert(flag < WDT_FLAGS);
    wdt_flags[flag] = 1;
    
    int i = 0;
    for (i = 0; i < WDT_FLAGS; i++) {
        if (wdt_flags[i] == 0)
            return;
    }
    
    ClrWdt();

    for (i = 0; i < WDT_FLAGS; i++)
        wdt_flags[i] = 0;
}