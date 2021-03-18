 /* 
 * File:   HardwareProfile.h
 * Author: Sabbiolino
 *
 * Created on 5 giugno 2016, 23.09
 */

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

#include <p24FJ128GA306.h>
#include <libpic30.h>


#define VERSIONE "v14.1 15/03/2021"


//#define MHZ                     1
 #define MHZ                     2
// #define MHZ                     4
// #define MHZ                     8

// abilita l'utilizzo del quarzo esterno come sorgente di clock
//#define USE_XT

#if MHZ==1
#define FOSC  1000000LL  // clock-frequecy in Hz with suffix LL (64-bit-long), eg. 32000000LL for 32MHz
#elif MHZ==2
#define FOSC  2000000LL  // clock-frequecy in Hz with suffix LL (64-bit-long), eg. 32000000LL for 32MHz
#elif MHZ==4
#define FOSC  4000000LL  // clock-frequecy in Hz with suffix LL (64-bit-long), eg. 32000000LL for 32MHz
#elif MHZ==8
#define FOSC  8000000LL  // clock-frequecy in Hz with suffix LL (64-bit-long), eg. 32000000LL for 32MHz
#else
#error Invalid clock frequency;
#endif



#define FCY       (FOSC/2)  // MCU is running at FCY MIPS
#define delay_us(x) __delay32(((x*FCY)/1000000L)) // delays x us
#define delay_ms(x) __delay32(((x*FCY)/1000L))  // delays x ms

#endif	/* HARDWAREPROFILE_H */
