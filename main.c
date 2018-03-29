/******************************************************************************/
/*                                                                            */
/*      H   H      SSSS     W   W                                             */
/*      H   H     S         W   W                                             */
/*      HHHHH      SSS      W   W                                             */
/*      H   H         S     W W W                                             */
/*      H   H  *  SSSS   *   W W   *  snc                                     */
/*                                                                            */
/*      *********************************                                     */
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  programma:  CONTALITRI                                                    */
/*                                                                            */
/*  cliente:                                                                  */
/*                                                                            */
/*  ver. 00:    29/02/2012                                                    */
/*                                                                            */
/*  ver. att.:  07/02/2018 v13.0                                              */
/*                                                                            */
/*  BY:         Fabio BARALDI & Massimo ZANNA                                 */
/*                                                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  (micro:     MICROCHIP PIC24FJ128GA306	freq 32Mhz                        */
/*              128K Flash - 0K EERam - 8K Ram                                */
/*              131072 b     0000 b     8192 b                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  rev.:   13.0 del 08/02/2018                                               */
/*                                                                            */
/*      - aggiunta funzionalita' STOP CONTEGGIO con [RESET]+[-] in TOGGLE     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  rev.:   12.0 del 14/05/2017                                               */
/*                                                                            */
/*      - corretto errore NEL SALVATAGGIO LINGUA ITALIANA                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                                                            */
/*  rev.:   11.0 del 07/10/2016                                               */
/*                                                                            */
/*      - corretto errore NEL CAMBIO UNITA' DI MISURA (non adattava il flusso)*/
/*      - migliorato contrasto LCD (nella displayDriver.c)                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  rev.:   10.0 del 21/07/2016                                               */
/*                                                                            */
/*      - INTRODOTTA VISUALIZZAZIONE a "NUMERONI" e LIFTING al SW             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  rev.:   09.1 del 18/05/2014                                               */
/*                                                                            */
/*      - modificata "gestione impulsi litro": nella variabile relativa si    */
/*        mettono sempre "impulsi litro" mentre cambiando "unita' misura"     */
/*        cambia solo la visualizzazione nella pagina principale, in modo     */
/*        congruo (negli impulsi rimane "per litro")                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  rev.:   09.0 del 16/05/2014                                               */
/*                                                                            */
/*      - modificata "gestione impulsi litro": nella variabile relativa si    */
/*        mettono sempre "impulsi litro" mentre cambiando "unita' misura"     */
/*        cambia solo la visualizzazione nella pagina principale, in modo     */
/*        congruo (negli impulsi rimane "per litro")                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  rev.:   09.0 del 07/05/2014                                               */
/*                                                                            */
/*      - modificata impostazione "impulsi per litro" mettendo un decimale    */
/*      - messa "accellerazione" nella variabile "impulsi per litro"          */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  rev.:   NN.N del GG/MM/AAAA                                               */
/*                                                                            */
/*      - versioni di "assestamento"                                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  rev.:   00.0 del 29/02/2012                                               */
/*                                                                            */
/*      - versione di partenza "da SPECIFICHE"                                */
/*                                                                            */
/******************************************************************************/



/******************************************************************************/
/*                                                                            */
/*  DISPOSIZIONE TASTI PONY FLOW 5.                                           */
/*  ===============================                                           */
/*                                                                            */
/*                ________________________________________                    */
/*                |                                      |                    */
/*                |  -----   ------------------   -----  |                    */
/*     ENTER      |  | E |   |                |   | + |  |      PIU'          */
/*                |  -----   |                |   -----  |                    */
/*                |          |                |          |                    */
/*                |  -----   |                |   -----  |                    */
/*     RESET      |  | R |   |                |   | - |  |      MENO          */
/*                |  -----   ------------------   -----  |                    */
/*                |                                      |                    */
/*                ----------------------------------------                    */
/*                                                                            */
/******************************************************************************/

#include <xc.h>
#include "display.h"
#include "displayDriver.h"
#include "peripherals.h"
#include "lowvoltagesave.h"
#include "pwmBacklight.h"
#include "timers.h"
#include "adc.h"
#include "main.h"
#include "sleep.h"
#include "HardwareProfile.h"
#include "keyboard.h"
#include "parameterStore.h"
#include "pageFactory.h"
#include "flowMeter.h"


// <editor-fold defaultstate="collapsed" desc="configuration bits">

// CONFIG4
#pragma config DSWDTPS = DSWDTPS1F      // Deep Sleep Watchdog Timer Postscale Select bits (1:68719476736 (25.7 Days))
#pragma config DSWDTOSC = LPRC          // DSWDT Reference Clock Select (DSWDT uses LPRC as reference clock)
#pragma config DSBOREN = OFF            // Deep Sleep BOR Enable bit (DSBOR Disabled)
#pragma config DSWDTEN = OFF            // Deep Sleep Watchdog Timer Enable (DSWDT Disabled)
#pragma config DSSWEN = OFF             // DSEN Bit Enable (Deep Sleep operation is always disabled)

// CONFIG3
#pragma config WPFP = WPFP127           // Write Protection Flash Page Segment Boundary (Page 127 (0x1FC00))
#pragma config VBTBOR = OFF             // VBAT BOR enable bit (VBAT BOR disabled)
#pragma config SOSCSEL = ON             // SOSC Selection bits (SOSC circuit selected)
#pragma config WDTWIN = PS25_0          // Watch Dog Timer Window Width (Watch Dog Timer Window Width is 25 percent)
#pragma config BOREN = OFF              // Brown-out Reset Enable (Brown-out Reset Disabled)
#pragma config WPDIS = WPDIS            // Segment Write Protection Disable (Disabled)
#pragma config WPCFG = WPCFGDIS         // Write Protect Configuration Page Select (Disabled)
#pragma config WPEND = WPENDMEM         // Segment Write Protection End Page Select (Write Protect from WPFP to the last page of memory)

// CONFIG2
#ifdef USE_XT
#pragma config POSCMD = XT              // Primary Oscillator Select (XT Oscillator Enabled)
#else
#pragma config POSCMD = NONE            // Primary Oscillator Select (Primary Oscillator Disabled)
#endif
#pragma config BOREN1 = DIS             // BOR Override bit (BOR Disabled [When BOREN=0])
#pragma config IOL1WAY = ON             // IOLOCK One-Way Set Enable bit (Once set, the IOLOCK bit cannot be cleared)
#pragma config OSCIOFCN = OFF           // OSCO Pin Configuration (OSCO/CLKO/RC15 functions as CLKO (FOSC/2))
#pragma config FCKSM = CSDCMD           // Clock Switching and Fail-Safe Clock Monitor Configuration bits (Clock switching and Fail-Safe Clock Monitor are disabled)
#ifdef USE_XT
#pragma config FNOSC = PRI              // Initial Oscillator Select (Primary Oscillator (XT, HS, EC))
#else
#pragma config FNOSC = FRCDIV           // Initial Oscillator Select (Fast RC Oscillator with Postscaler (FRCDIV))
#endif
#pragma config ALTVREF = DLT_AV_DLT_CV  // Alternate VREF/CVREF Pins Selection bit (Voltage reference input, ADC =RA9/RA10 Comparator =RA9,RA10)
#pragma config IESO = OFF               // Internal External Switchover (Disabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler Select (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler Ratio Select (1:128)
#pragma config FWDTEN = WDT_ACT         // Watchdog Timer Enable (WDT enabled only while device active and disabled in Sleep)
#pragma config WINDIS = OFF             // Windowed WDT Disable (Standard Watchdog Timer)
#pragma config ICS = PGx3               // Emulator Pin Placement Select bits (Emulator functions are shared with PGEC3/PGED3)
#pragma config LPCFG = ON               // Low power regulator control (Enabled)
#pragma config GWRP = OFF               // General Segment Write Protect (Disabled)
#pragma config GCP = OFF                // General Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF             // JTAG Port Enable (Disabled)


// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="variables">

//parametri utente e valori di default
extern tParameter paramStore[21];

//variabili di stato
extern tPageInfo *activePage;
extern char chiuso; // coperchio
unsigned int sole = 0; // livello da ADC
unsigned int pila = 0; // livello da ADC
//unsigned int batteria			= 0		; // livello da ADC
volatile unsigned long long secondi = 0;
unsigned char retro_flag = FALSE;
extern volatile unsigned long long cont;


// flag dello scheduler
volatile char refresh_batt = TRUE; // boolean flag
volatile char refresh_LCD = TRUE; // boolean flag
volatile unsigned char refresh_cont = 0;
volatile unsigned char refresh_values = 0;
volatile unsigned char refresh_keys = 0;
volatile unsigned char gotosleep = 0;
unsigned char pause = 0;

// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Initialization">

static void InitializeSystem(void) {

    initClock();
    initPeripherals();
    initPorts();
    initParameters();
    if (paramStore[EN_HLVD].value.uc8)
      cont = paramStore[COUNTER].value.ui32;
    clockTune();
    initFlowMeter();
    initTimers();
    initPWM();
    initIC1();
    initADC(0x0003); // 00C3 selezionare i pin analogici
    initHLVD();
    init_LCD();
    initSleep();
    pageFactoryInit();
    initPagine();
    initCont();

    //    PWMledLCD_ON();
    //    /* SPLASH */
    //    paint_splash();
    //    for (i = 0; i < 10; i++) {
    //        delay_ms(400);
    //        retro_level();
    //    }
    //    delay_ms(1000);

    //SPEGNI IL DISPLAY
    LCDshutdown();
    //spegni la retroilluminazione
    PWMledLCD_OFF_quick();

}

// </editor-fold>





int main(void)
{
    InitializeSystem();

    while (TRUE)
    {
        ClrWdt(); // è disabilitato ???
        
        if (RCONbits.DPSLP != 0 || RCONbits.SLEEP != 0)  // mi sto svegliando
        {
            wakeUp();
        }
        
        
        
        if (gotosleep == TRUE && (activePage->key < 4 || activePage->key == 10)) // mi sto addormentando
        {
            goToSleep();
        }
        
        
        
        if (refresh_keys)
        {
            if (activePage->key != 7 && activePage->key != 8)// 7 test ingressi, 8 test uscite
            {
                gestioneCoperchio();
            }
            
            if (!chiuso)
            {
                leggiPulsanti();
            }
            refresh_keys = FALSE;
        }
        
        
        
        if (!chiuso)
        {
            if (refresh_batt)
            {
                pila = readADC(ADC_batterysense);
                
                if ((pila < paramStore[AUTO_PILA].value.ui16) && (paramStore[LUMINOSITA].value.uc8 > 3))
                {
                    paramStore[LUMINOSITA].value.uc8 = 3;
                }
                //batteria        = readADC(ADC_carbattery)   ;
                refresh_batt = FALSE;
                // pagina 8 test uscite: mi spegnerebbe l'uscita
                refreshSole(activePage->key != 8);
            }
            
            if (refresh_values)
            {
                refresh_values = FALSE;
                
                switch (activePage->key)
                {
                    case 0:
                        refresh_values_p0();
                        break;
                        
                    case 10:
                        refresh_values_p10();
                        break;
                        //                case 4:
                        //                    refresh_values_p4();
                        //                    break;
                        
                    case 5:
                        refresh_values_p5();
                        break;
                        
                    case 6:
                        refresh_values_p6();
                        break;
                        
                    case 7:
                        refresh_values_p7();
                        break;
                        
                    case 8:
                        refresh_values_p8();
                    case 9:
                        refresh_values_p9();
                    default:
                        break;
                }
                Nop();
            }

            if (refresh_LCD)
            {
                refresh_LCD = FALSE;
                retro_level();
                refresh_changed();
                Nop();
            }

        }//If
    }//main loop
}//main
