#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

/******************************************************************************/
/*      COSTANTI			                                      */
/******************************************************************************/

#include <xc.h>

#define _ISR_PSV        __attribute__((interrupt, auto_psv))
#define _ISR_NO_PSV 	__attribute__((interrupt, no_auto_psv))
#define _INLINE         __attribute__((always_inline)) 


#define TRUE 			1
#define FALSE 			0


#define LITRI			0
#define GALLONI			1
#define METRICUBI		2



void save (void);

#endif