#include "HardwareProfile.h"
#include "peripherals.h"
#include "display.h"
#include "main.h"



void initPeripherals(void)
{
    //disabilito le periferiche non utilizzate
    _DMA0MD = 1;
    _DMA1MD = 1;
    _I2C1MD = 1;
    _I2C2MD = 1;
    _SPI1MD = 1;
    _SPI2MD = 1;
    _SPI3MD = 1;
    _OC2MD = 1;
    _OC3MD = 1;
    _OC4MD = 1;
    _OC5MD = 1;
    _OC6MD = 1;
    _OC7MD = 1;
    _IC1MD = 1;
    _IC2MD = 1;
    _IC3MD = 1;
    _IC4MD = 1;
    _IC5MD = 1;
    _IC6MD = 1;
    _IC7MD = 1;
    _LCDMD = 1;
    //_LVDMD = 1;
    _CTMUMD = 1;
    _CRCMD = 1;
    _PMPMD = 1;
    _RTCCMD = 1;
    _CMPMD = 1;
    _REFOMD = 1; //reference clock output
    _U1MD = 1; //uart
    _U2MD = 1;
    _U3MD = 1;
    _U4MD = 1;

    _UPWMMD = 1; //????
    //_DSMMD=1;

    _INT0IE = 0;
    _INT1IE = 0;
    _INT2IE = 0;
    _INT3IE = 0;
    _INT4IE = 0;
    _AD1IE = 0;
    _DMA1IE = 0;
    _DMA2IE = 0;
    _DMA3IE = 0;
    _DMA4IE = 0;
    _DMA5IE = 0;
    _U1TXIE = 0;
    _U1RXIE = 0;
    _U2TXIE = 0;
    _U2RXIE = 0;
    _U3TXIE = 0;
    _U3RXIE = 0;
    _U4TXIE = 0;
    _U4RXIE = 0;
    _MI2C1IE = 0;
    _SI2C1IE = 0;
    _MI2C2IE = 0;
    _SI2C2IE = 0;
    _SPI1IE = 0;
    _SPF1IE = 0;
    _SPI2IE = 0;
    _SPF2IE = 0;
    _OC1IE = 0;
    _OC2IE = 0;
    _OC3IE = 0;
    _OC4IE = 0;
    _OC5IE = 0;
    _OC6IE = 0;
    _OC7IE = 0;
    _IC1IE = 0;
    _IC2IE = 0;
    _IC3IE = 0;
    _IC4IE = 0;
    _IC5IE = 0;
    _IC6IE = 0;
    _IC7IE = 0;
    _JTAGIE = 0;
    _LCDIE = 0;
    _CRCIE = 0;
    _CTMUIE = 0;
    //_LVDIE = 0;
    _RTCIE = 0;
    _PMPIE = 0;
    _CMIE = 0;
}

void initPorts(void) {
    //indicare se input (1) o output (0), mettere i non usati come output e bassi
    ANSB = 0x00;
    ANSD = 0x00;
    ANSE = 0x00;
    ANSG = 0x00;
    TRISB = 0X0F0B;//FFCF;
    Nop();
    PORTBbits.RB2=0;
    PORTBbits.RB4=0;
    PORTBbits.RB5=0;
    PORTBbits.RB6=0;
    PORTBbits.RB7=0;
    PORTBbits.RB12=0;
    PORTBbits.RB13=0;
    PORTBbits.RB14=0;
    PORTBbits.RB15=0;
    Nop();
    TRISC = 0x0000;
    Nop();
    PORTC = 0x0000;
    //PORTE D ED E GESTITE DA DISPLAY.C
    TRISF = 0X0000;//0030;
    Nop();
    PORTF = 0X0000;
    TRISG = 0X0080;//0240;
    Nop();
    PORTGbits.RG2=0;
    abifotores=0;
    PORTGbits.RG8=0;
    PORTGbits.RG9=0;
    ledLCD = 1;
}

void initIC1(void) {
    CNPU1 = 0;
    CNPU2 = 0;
    CNPU3 = 0;
    CNPU4 = 0;
    CNPU5 = 0;
    CNPU6 = 0;
    CNPD1 = 0;
    CNPD2 = 0;
    CNPD3 = 0;
    CNPD4 = 0;
    CNPD5 = 0;
    CNPD6 = 0;
    CM1CON = 0x00; //comparatore spento
    LCDCON = 0x00; //controller lcd spento
    PMCON1 = 0x00; //PMP spento
    _CN8IE = 0;
    IC1CON1 = 0x0000; //IC spento
    _CNIE = 0;
}



_INLINE void alzabit(unsigned char* var, unsigned char nbit) {
    if (nbit > 7)
        nbit = 7;
    *var = *var | (0x01 << nbit);
}

_INLINE void abbassabit(unsigned char* var, unsigned char nbit) {
    if (nbit > 7)
        nbit = 7;
    *var = *var & (0xFF - (0x01 << nbit));
}
