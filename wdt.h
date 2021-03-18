#ifndef WDT_H_INCLUDED
#define WDT_H_INCLUDED

typedef enum {
    WDT_FLAG_MAIN = 0,
    WDT_FLAG_TIMER1 = 1,
    WDT_FLAG_TIMER2 = 2,
    WDT_FLAGS,
} wdt_flag_t;

void wdt_set_flag(wdt_flag_t flag);

#endif