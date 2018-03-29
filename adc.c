#include "HardwareProfile.h"
#include "main.h"

void initADC(int amask) {
    //AD1PCFG 			= amask	;	// per altri modelli di pic
    ANSB = amask; // 1=analog, 0=digital, NB TRIS deve essere 1
    AD1CON1 = 0x2070; // avvio automatico della conversione dopo il campionamento
    AD1CSSL = 0; // non utilizzare scansione
    AD1CON2 = 0; //0x0400;	// usa MUXA, come rif di tensione usa AVss e AVdd
    AD1CON3 = 0x1F02; // Tsamp = 32 x Tad = 256us; Tad=4Tcy=8us
    AD1CON1bits.ADON = 1; // abilita l'ADC
} //initADC

int readADC(int ch) {
    AD1CHS = ch; // seleziona il canale analogico
    AD1CON1bits.SAMP = 1; // avvia il campionamento
    while (!AD1CON1bits.DONE); // attendi la fine della conversione
    //AD1CON1bits.SAMP 	= 0		;
    AD1CON1bits.DONE = 0;
    return ADC1BUF0; //leggi il risultato della conversione
} // readADC

