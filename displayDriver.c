#include "HardwareProfile.h"
#include "peripherals.h"
#include "splash.h"
#include "splash2.h"
#include "splash3.h"
#include "ponderosa8.h"
#include "ponderosa16.h"
#include "pageFactory.h"
#include "parameterStore.h"
#include "fontBigBig.h"



//modalità 6800


#define D_LCD_DATA      TRISE
#define LCD_DATA        LATE
#define D_LCD_COMM      TRISD
#define LCD_COMM        LATD
#define LCD_COMM_E     LATDbits.LATD5 //3  // attivo alto, dati validi sul bus
#define LCD_COMM_RW     LATDbits.LATD4  // 1=read 0=write
#define LCD_COMM_CS     LATDbits.LATD1 //7  // chip select attivo basso
#define LCD_COMM_RES    LATDbits.LATD2 //6  // reset attivo basso
#define LCD_COMM_CD     LATDbits.LATD3 //5  // 0=comando, 1=dato
#define LCD_COMM_PWR    LATDbits.LATD6 //2	// mosfet alimentazione attivo basso



unsigned char display_reverse = 0; // flag display in reverse se 1, 1 bit per riga
unsigned char LCD_changed = 0; // 1 bit per riga
unsigned char nextrow;
extern tPageInfo *activePage;
extern tParameter paramStore[21];

_INLINE void pushData() {
    LCD_COMM_E = 1;
    //    Nop();
    //    Nop();
    LCD_COMM_E = 0;
}



/***********************************************************************/
/*      COMANDI				                                           */

/***********************************************************************/

void lcd_on_off(unsigned char enable) {
    LCD_COMM_CD = 0;
    LCD_COMM_RW = 0;
    if (!enable) {
        LCD_DATA = 0xAE; //disable -> sleep
    } else {
        LCD_DATA = 0xAF; //enable
    }
    pushData();
}

void init_LCD(void) {
    //si inizializza da solo all'accensione. Vanno bene i valori di default.

    D_LCD_DATA = 0x00; // tutti output
    D_LCD_COMM = 0x00; // tutti output
    LCD_DATA = 0x00; // azzero porta DATA
    LCD_COMM = 0x5A; //FC; // azzero i comandi

    //    Nop();
    LCD_COMM_PWR = 0; // alimento il chip
    delay_ms(10);

    LCD_COMM_RES = 1;

    //    Nop();

    LCD_COMM_CS = 0;
    LCD_COMM_CD = 0;
    LCD_COMM_RW = 0;

    LCD_DATA = 0xA2;    //bias                  A2
    pushData();

    LCD_DATA = 0xA0;    // ADC                  A0
    pushData();

    LCD_DATA = 0xCF;    // COM reverse          CF
    pushData();

    LCD_DATA = 0x24;    // resistor ratio       24
    pushData();

    LCD_DATA = 0x81;    // electonic volume     81
    pushData();

    LCD_DATA = 0x18;    // CONTRAST             20 ****
    pushData();

    LCD_DATA = 0x2F;    // power control        2F
    pushData();


    lcd_on_off(1);      // Turn the display ON

    LCD_COMM_CS = 1;
    LCD_DATA = 0;
}//Init_LCD

//void LCDinverse(unsigned char enable) {
//    LCD_COMM_CS = 0;
//    LCD_COMM_CD = 0;
//    LCD_COMM_WR = 0;
//    if (!enable) {
//        LCD_DATA = 0xA6; //disable
//    } else {
//        LCD_DATA = 0xA7; //enable
//    }
//    LCD_COMM_RD = 1;
//    Nop();
//    Nop();
//    LCD_COMM_RD = 0;
//    LCD_COMM_CS = 1;
//    LCD_DATA = 0;
//}

void LCDsoftreset(void) {
    LCD_COMM_CS = 0;
    LCD_COMM_CD = 0;
    LCD_COMM_RW = 0;
    LCD_DATA = 0xE2;
    pushData();
    delay_us(3200);
    LCD_COMM_CS = 1;
    LCD_DATA = 0;
}

void LCDshutdown(void) {
    LCDsoftreset();
    LCD_COMM_PWR = 1;
    Nop();
    LCD_DATA = 0;
    LCD_COMM_E = 0;
    LCD_COMM_RW = 0;
    LCD_COMM_CS = 0;
    LCD_COMM_RES = 0;
    LCD_COMM_CD = 0;
}

void lcd_write_byte(unsigned char data) {
    LCD_COMM_RW = 0;
    LCD_DATA = (data);
    pushData();
}//LCDwritedata


/***********************************************************************/
/*      FRAME BUFFER		                                           */

/***********************************************************************/

void refresh_row(unsigned char pagina[8][16], unsigned char row) {
    unsigned char j, k;
    unsigned char ascii;

    if (row > 7)
        row = 0;

    LCD_COMM_CS = 0;
    LCD_COMM_CD = 0;
    LCD_COMM_RW = 0;

    LCD_DATA = 0x10; // ColumnAddress MSB =0 0x10 | (x >> 4)
    pushData();

    LCD_DATA = 0x00; // ColumnAddress LSB =0 (x & 0x0f)
    pushData();

    LCD_DATA = 0xB0 | row; // PageAddress 0xB0 | (y >> 3)
    pushData();

    LCD_COMM_CD = 1; // Set for DATA

    if ((activePage->key == 0) && (row == 4)) {
        // Loop through the vertical sections
        for (j = 0; j < 16; ++j) {//6 a 16
//            if ((pagina[row][j] < 44) || (pagina[row][j] > 57))
//                pagina[row][j] = 45;
//            if (pagina[row][j] == 44)
//                pagina[row][j] = 47;
//            ascii = pagina[row][j] - 45;
            //caratteri permessi spazio punto virgola 0-9
            switch (pagina[4][j]) {
                case 44:
                    ascii = 2;
                    break;
                case 46:
                    ascii = 1;
                    break;
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                case 56:
                case 57:
                    ascii = pagina[4][j] - 45;
                    break;
                default:
                    ascii = 0;
                    break;
            }
            if (display_reverse & (1 << row)) {
                for (k = 0; k < 8; k++) {//0 a 12
                    lcd_write_byte(~fontBig[ascii][k]);
                }
            } else {
                for (k = 0; k < 8; k++) {//0 a 12
                    lcd_write_byte(fontBig[ascii][k]);
                }
            }
        }
        //        //avanzano 8 colonne
        //        for (k = 0; k < 8; k++)
        //            lcd_write_byte(0b00000000);
    } else if ((activePage->key == 0) && (row == 5)) {
        // Loop through the vertical sections
        for (j = 0; j < 16; ++j) {//6 a 16
//            if ((pagina[row][j] < 44) || (pagina[row][j] > 57))
//                pagina[row][j] = 45;
//            if (pagina[row][j] == 44)
//                pagina[row][j] = 47;
//            ascii = pagina[row][j] - 45;
            //caratteri permessi spazio punto virgola 0-9
            switch (pagina[4][j]) {
                case 44:
                    ascii = 2;
                    break;
                case 46:
                    ascii = 1;
                    break;
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                case 56:
                case 57:
                    ascii = pagina[4][j] - 45;
                    break;
                default:
                    ascii = 0;
                    break;
            }
            if (display_reverse & (1 << row)) {
                for (k = 0; k < 8; k++) {//0 a 12
                    lcd_write_byte(~fontBig2[ascii][k]);
                }
            } else {
                for (k = 0; k < 8; k++) {//0 a 12
                    lcd_write_byte(fontBig2[ascii][k]);
                }
            }
        }
        //        //avanzano 8 colonne
        //        for (k = 0; k < 8; k++)
        //            lcd_write_byte(0b00000000);
        
        
        //*********** FONT GRANDISSIMO
    } else if ((activePage->key == 10) && (row == 4 || row == 5 || row == 6 || row == 7)) {
        unsigned char block = row - 4;
        for (j = 8; j < 16; ++j) {

            //caratteri permessi spazio punto virgola 0-9
            switch (pagina[4][j]) {
                case 44:
                    ascii = 2;
                    break;
                case 46:
                    ascii = 1;
                    break;
                case 48:
                case 49:
                case 50:
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                case 56:
                case 57:
                    ascii = pagina[4][j] - 45;
                    break;
                default:
                    ascii = 0;
                    break;
            }

            if (display_reverse & (1 << row)) {//questa riga è invertita
                for (k = 0; k < 16; k++) {
                    lcd_write_byte(~fontBigBig[ascii][block][k]);
                }
            } else {
                for (k = 0; k < 16; k++) {
                    lcd_write_byte(fontBigBig[ascii][block][k]);
                }
            }
        }
        
        
        
    } else {
        // Loop through the vertical sections
        for (j = 0; j < 16; ++j) {
            ascii = pagina[row][j]; //********- 32
            if (display_reverse & (1 << row)) {
                for (k = 0; k < 8; k++) {
                    lcd_write_byte(~font2[ascii][k]);
                }
            } else {
                for (k = 0; k < 8; k++) {
                    lcd_write_byte(font2[ascii][k]);
                }
            }
        }
    }

    LCD_COMM_CS = 1;
    LCD_DATA = 0x00;
    abbassabit(&LCD_changed, row);
}//update_display

void refresh_display(void) {
    unsigned char i;

    for (i = 0; i < 8; ++i)
        refresh_row(activePage->textBuffer, i);

}//update_all_display

void refresh_changed(void) {
    //    unsigned char row;
    //
    //    for (row = 0; row < 8; row++)
    //        if (LCD_changed & (1 << row)) {
    //            refresh_row(activePage->textBuffer, row);
    //            return;
    //        }

    if (LCD_changed & (1 << nextrow))
        refresh_row(activePage->textBuffer, nextrow);
    nextrow = (nextrow + 1) % 8;
    
    if(activePage->key == 0 && nextrow == 5)
    {
        if (LCD_changed & (1 << nextrow))
            refresh_row(activePage->textBuffer, nextrow);
        nextrow = (nextrow + 1) % 8;
    }
    else if (activePage->key == 10 && nextrow == 5) {
        if (LCD_changed & (1 << nextrow))
            refresh_row(activePage->textBuffer, nextrow);
        nextrow = (nextrow + 1) % 8;
        if (LCD_changed & (1 << nextrow))
            refresh_row(activePage->textBuffer, nextrow);
        nextrow = (nextrow + 1) % 8;
        if (LCD_changed & (1 << nextrow))
            refresh_row(activePage->textBuffer, nextrow);
        nextrow = (nextrow + 1) % 8;
    }

}

void paint_splash(void) {
    unsigned int i, j;

    LCD_COMM_CS = 0;
    LCD_COMM_RW = 0;

    for (i = 0; i < 8; i++) {
        LCD_COMM_CD = 0;

        LCD_DATA = 0x10; // ColumnAddress MSB =0 0x10 | (x >> 4)
        pushData();

        LCD_DATA = 0x00; // ColumnAddress LSB =0 (x & 0x0f)
        pushData();

        LCD_DATA = 0xB0 | i; // PageAddress 0xB0 | (y >> 3)
        pushData();

        LCD_COMM_CD = 1; // Set for DATA
        for (j = 0; j < 132; j++) {
            if (paramStore[REVERSE_SPLASH].value.uc8)
                LCD_DATA = (splash2[i * 132 + j]);
            else
                LCD_DATA = (splash3[i * 132 + j]);
            pushData();
        }
    }

    LCD_COMM_CS = 1;
    LCD_DATA = 0x00;
}