/* 
 * File:   flowMeter.h
 * Author: Sabbiolino
 *
 * Created on 25 giugno 2016, 13.50
 */

#ifndef FLOWMETER_H
#define	FLOWMETER_H

void initFlowMeter();
void initCont (void);
_INLINE void refreshFlowMeter();
_INLINE void calculateFlow();
_INLINE void calculateTotals();
void convertImpulsi();
_INLINE void resetTotalCounter();

#endif	/* FLOWMETER_H */

