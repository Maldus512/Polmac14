#include "main.h"
#include "HardwareProfile.h"
#include "p24FJ128GA306.h"

//INGRESSI
// pin 21
#define setbtn          PORTBbits.RB8	
// pin 22
#define modebtn         PORTBbits.RB9	
// pin 23
#define upbtn           PORTBbits.RB11	
// pin 24
#define downbtn         PORTBbits.RB10	
// pin 13
#define coperchio       PORTBbits.RB3	
//#define fc_valve5 	_RB14	// pin 29
//#define fc_valve1 	_RF4	// pin 31
//#define fc_valve2 	_RF5	// pin 32
//#define fc_valve4 	_RB12	// pin 27
//#define fc_valve3 	_RB13	// pin 28
// pin 4
#define impulso         PORTGbits.RG7; 	
//#define impulsoquad     _RG9    // pin
// canale adc AN0 pin 16 (RB0)
#define ADC_fotores         0 	
// canale adc AN1 pin 15 (RB1)
#define ADC_batterysense    1 	
//#define ADC_carbattery      6 	// canale adc AN6 pin 17 (RB6)
//#define ADC_posiz_mot       7 	// canale adc AN7 pin 18 (RB7)
#define IN2             PORTBbits.RB15 	// di scorta, pin 30
//ICSP: PGEC3 PIN 11 PGED3 PIN 12

//USCITE
//pin 35   
#define abicoperchio    LATFbits.LATF3
//pin 36
#define abifotores      LATGbits.LATG3       
//#define abipila       LATBbits.LATB2          //RB2 pin 14
//pin 5
#define ledLCD          LATGbits.LATG6        
//#define motP2         LATFbits.LATF2            //RF2 pin 34
//#define motP1         LATFbits.LATF3            //RF3 pin 33
//#define motN1         LATDbits.LATD8            //RD8 pin 42
//#define motN2         LATDbits.LATD9            //RD9 pin 43
//#define abiinnalz     LATGbits.LATG2        //RG2 pin 37
//#define eninnalz      LATGbits.LATG8         //RG8 pin 6
//#define relais1       LATDbits.LATD1          //RD1 pin 49
//#define relais2       LATFbits.LATF1          //RF1 pin 59


void initIC1(void);
void initPorts(void);
void initPeripherals(void);

_INLINE void alzabit(unsigned char* var, unsigned char nbit);
_INLINE void abbassabit(unsigned char* var, unsigned char nbit);
