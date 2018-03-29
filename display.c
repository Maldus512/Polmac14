#include "HardwareProfile.h"
#include <string.h>
#include <stdio.h>
#include "Display.h"
#include "peripherals.h"
#include "timers.h"
#include "main.h"
#include "dizionario.h"
#include "pageFactory.h"
#include "parameterStore.h"
#include "flowMeter.h"




extern tPageInfo *activePage;
extern tPageInfo userPages[3];
extern tPageInfo adminPages[7];
extern tParameter paramStore[21];
extern unsigned char display_reverse; // flag display in reverse se 1, 1 bit per riga
extern unsigned char LCD_changed;

extern unsigned long long litritot; // ml, max 4Ml
extern unsigned long long litriparz; // ml, max 4Ml
extern unsigned long long flusso; // ml/s max 65l/s
extern unsigned int sole;
extern unsigned int pila;
//extern unsigned int batteria;
extern unsigned long long secondi;
extern unsigned long long contaimpulsi;
char oldlowbatt = 0;

extern char mode; // pulsante in alto a sinistra
extern char set; // pulsante in basso a sinistra
extern char up; // pulsante in alto a destra
extern char down; // pulsante in basso a destra
extern char chiuso;

extern unsigned char pause;



void putstring(unsigned char pagina[8][16], char *stringa, unsigned char rightalign, unsigned char row);
void puttesti(unsigned char pagina[8][16], const unsigned char *stringa, unsigned char row);
void putvarInt(unsigned char pagina[8][16], varInt numero, paramSize size, unsigned char rightalign, unsigned char row);
void putint(unsigned char pagina[8][16], int numero, unsigned char rightalign, unsigned char row);
void putlongint(unsigned char pagina[8][16], unsigned long long numero, unsigned char rightalign, unsigned char row);
//void putfloat (unsigned char pagina[8][16],float numero,unsigned char rightalign, unsigned char row);
void putmillis(unsigned char pagina[8][16], unsigned long long numero, unsigned char rightalign, unsigned char row);
void puttenths(unsigned char pagina[8][16], unsigned long long numero, unsigned char rightalign, unsigned char row);
void clearrow(unsigned char pagina[8][16], unsigned char y);
void clearpage(unsigned char pagina[8][16]);





/******************************************************************************/
/*                                                                            */
/*      FUNZIONI CUSTOM		                                              */
/*                                                                            */
/******************************************************************************/
void initPagine(void)
{
    //prepara le schermate con le scritte nella paramStore[LINGUA].value.uc8 in uso
    clearpage(userPages[0].textBuffer);
    clearpage(userPages[1].textBuffer);
    clearpage(userPages[2].textBuffer);
    clearpage(userPages[3].textBuffer);
    clearpage(adminPages[0].textBuffer);
    clearpage(adminPages[1].textBuffer);
    clearpage(adminPages[2].textBuffer);
    clearpage(adminPages[3].textBuffer);
    clearpage(adminPages[4].textBuffer);
    clearpage(adminPages[5].textBuffer);
    clearpage(adminPages[6].textBuffer);

    switch (paramStore[EVIDENZIA].value.uc8) {
        case 0: // TOT
            switch (paramStore[UNITA].value.uc8) {
                case LITRI:
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][0], 1);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][3], 3);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][6], 6);
                    // puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][0], 1);//parziale l
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][6], 1);//parziale l
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][3], 3);//totale l
                    break;
                case GALLONI:
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][2], 1);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][5], 3);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][8], 6);
                    // puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][2], 1);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][8], 1);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][5], 3);
                    break;
                case METRICUBI:
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][1], 1);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][4], 3);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][7], 6);
                    // puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][1], 1);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][7], 1);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][4], 3);
                    break;
            }
            break;
        case 1: // PAR
            switch (paramStore[UNITA].value.uc8) {
                case LITRI:
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][3], 1);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][0], 3);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][6], 6);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][6], 1);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][0], 3);//parziale l
                    break;
                case GALLONI:
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][5], 1);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][2], 3);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][8], 6);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][8], 1);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][2], 3);
                    break;
                case METRICUBI:
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][4], 1);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][1], 3);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][7], 6);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][7], 1);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][1], 3);
                    break;
            }
            break;
        case 2: // FLU
            switch (paramStore[UNITA].value.uc8) {
                case LITRI:
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][3], 1);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][6], 3);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][0], 6);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][0], 1);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][6], 3);//flusso
                    break;
                case GALLONI:
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][5], 1);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][8], 3);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][2], 6);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][2], 1);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][8], 3);
                    break;
                case METRICUBI:
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][4], 1);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][7], 3);
                    puttesti(userPages[0].textBuffer, testi[paramStore[LINGUA].value.uc8][1], 6);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][1], 1);
                    puttesti(userPages[3].textBuffer, testi[paramStore[LINGUA].value.uc8][7], 3);
                    break;
            }
            break;
    }

    puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][9], 0);
    //    switch (paramStore[UNITA].value.uc8) {
    //        case LITRI:
    puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][10], 2);
    //            break;
    //        case GALLONI:
    //            puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][12], 2);
    //            break;
    //        case METRICUBI:
    //            puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][11], 2);
    //            break;
    //    }
    puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][13], 4);
    puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][17], 6);
    puttesti(userPages[2].textBuffer, testi[paramStore[LINGUA].value.uc8][21], 0);
    puttesti(userPages[2].textBuffer, testi[paramStore[LINGUA].value.uc8][22], 2);
    puttesti(userPages[2].textBuffer, testi[paramStore[LINGUA].value.uc8][23], 4);
    puttesti(userPages[2].textBuffer, testi[paramStore[LINGUA].value.uc8][25], 6);

    //pagina tecnico
    putstring(adminPages[0].textBuffer, "Total Reset", 0, 0);
    //  putstring(adminPages[0].textBuffer, "Reverse princip.", 0, 2);
    putstring(adminPages[0].textBuffer, "Reverse highlig.", 0, 2);
    putstring(adminPages[0].textBuffer, "Reverse splash", 0, 4);
    putstring(adminPages[0].textBuffer, VERSIONE, 0, 7);

    //pagine hsw
    putstring(adminPages[1].textBuffer, "Tara soglia luce", 0, 0);
    putstring(adminPages[1].textBuffer, "Tara soglia pila", 0, 2);
    putstring(adminPages[1].textBuffer, "Refr. pila+luce", 0, 4);
    putstring(adminPages[1].textBuffer, "Ab low volt save", 0, 6);
    putstring(adminPages[2].textBuffer, "Pti media flusso", 0, 0);
    //     putstring(adminPages[2].textBuffer, "Reverse princip.", 0, 2);
    //     putstring(adminPages[2].textBuffer, "Reverse splash", 0, 4);
    putstring(adminPages[2].textBuffer, "Flusso", 0, 4);
    putstring(adminPages[2].textBuffer, "RC tuning", 0, 2);
    putstring(adminPages[3].textBuffer, "Pila", 0, 0);
    putstring(adminPages[3].textBuffer, "Fotores", 0, 2);
    //putstring(adminPages[3].textBuffer, "Batteria", 0, 4);
    putstring(adminPages[4].textBuffer, "P1 PAG         0", 0, 0);
    putstring(adminPages[4].textBuffer, "P2 SET         0", 0, 1);
    putstring(adminPages[4].textBuffer, "P3 UP          0", 0, 2);
    putstring(adminPages[4].textBuffer, "P4 DOWN        0", 0, 3);
    putstring(adminPages[4].textBuffer, "REED           0", 0, 4);
    putstring(adminPages[4].textBuffer, "LIBERO         0", 0, 5);
    //putstring(adminPages[5].textBuffer, "AB PILA", 0, 0);
    putstring(adminPages[5].textBuffer, "AB REED", 0, 0);
    putstring(adminPages[5].textBuffer, "AB FOTORES", 0, 1);
    putstring(adminPages[6].textBuffer, "Impulsi", 0, 0);
    putstring(adminPages[6].textBuffer, "Tot Litri", 0, 2);
    putstring(adminPages[6].textBuffer, "Secondi", 0, 4);

    refresh_values_p0();
    refresh_values_p1();
    refresh_values_p2();
    refresh_values_p3();
    refresh_values_p4();
    refresh_values_p5();
    refresh_values_p6();
    refresh_values_p7();
    refresh_values_p8();
    refresh_values_p9();
    refresh_values_p10();
}

void refresh_values_p0(void)
{
    calculateTotals();
    calculateFlow();

    // scritta grossa alla riga 4
    switch (paramStore[EVIDENZIA].value.uc8)
    {
        case 0: // TOT
            putmillis(userPages[0].textBuffer, litritot, 1, 4);
            putmillis(userPages[0].textBuffer, litriparz, 1, 2);
            putmillis(userPages[0].textBuffer, flusso, 1, 7);
            break;
        case 1: // PAR
            putmillis(userPages[0].textBuffer, litriparz, 1, 4);
            putmillis(userPages[0].textBuffer, litritot, 1, 2);
            putmillis(userPages[0].textBuffer, flusso, 1, 7);
            break;
        case 2: // FLU
            putmillis(userPages[0].textBuffer, flusso, 1, 4);
            putmillis(userPages[0].textBuffer, litritot, 1, 2);
            putmillis(userPages[0].textBuffer, litriparz, 1, 7);
            break;
    }
    
    if (pause)
    {
        putstring(userPages[0].textBuffer,"---=# STOP #=---",0,7);
        display_reverse = display_reverse | 0x80;
    }
    else
    {
        display_reverse = display_reverse & ~0x80;
    }

    if ((pila < paramStore[AUTO_PILA].value.ui16) && !oldlowbatt)
    {
        puttesti(userPages[0].textBuffer, strlowbatt, 0);
        LCD_changed = LCD_changed | 1;
        oldlowbatt = 1;
    }
    else if ((pila >= paramStore[AUTO_PILA].value.ui16) && oldlowbatt)
    {
        putstring(userPages[0].textBuffer, "        ", 1, 0);
        LCD_changed = LCD_changed | 1;
        oldlowbatt = 0;
    }

    if (flusso > 0 && activePage->key == 0)
        cambioPaginaAlt(&userPages[3]);
}

void refresh_values_p10(void)
{
    calculateTotals();
    calculateFlow();

    // scritta grossa alla riga 4
    switch (paramStore[EVIDENZIA].value.uc8) {
        case 0:
            putmillis(userPages[3].textBuffer, litritot, 1, 4);
            //putmillis(userPages[3].textBuffer, litriparz, 1, 2); // io
            putmillis(userPages[3].textBuffer, flusso, 1, 2); // io
            break;
        case 1:
            putmillis(userPages[3].textBuffer, litriparz, 1, 4);
            //putmillis(userPages[3].textBuffer, litritot, 1, 2);
            putmillis(userPages[3].textBuffer, flusso, 1, 2);
            break;
        case 2:
            putmillis(userPages[3].textBuffer, flusso, 1, 4);
            //putmillis(userPages[3].textBuffer, litritot, 1, 2);
            putmillis(userPages[3].textBuffer, litriparz, 1, 2);
            break;
    }


    if ((pila < paramStore[AUTO_PILA].value.ui16) && !oldlowbatt)
    {
        puttesti(userPages[3].textBuffer, strlowbatt, 0);
        LCD_changed = LCD_changed | 1;
        oldlowbatt = 1;
    }
    else if ((pila >= paramStore[AUTO_PILA].value.ui16) && oldlowbatt)
    {
        putstring(userPages[3].textBuffer, "        ", 1, 0);
        LCD_changed = LCD_changed | 1;
        oldlowbatt = 0;
    }
    
    if (flusso == 0LL && activePage->key == 10)
        cambioPaginaAlt(&userPages[0]);

}

void refresh_values_p1(void)
{
    puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][24], 1);
    puttenths(userPages[1].textBuffer, paramStore[IMPULSI].value.ui16, 1, 3);

    switch (paramStore[UNITA].value.uc8)
    {
        case LITRI:
            puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][14], 5);
            break;
        case GALLONI:
            puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][15], 5);
            break;
        case METRICUBI:
            puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][16], 5);
            break;
    }

    switch (paramStore[EVIDENZIA].value.uc8)
    {
        case 0:
            puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][18], 7);
            break;
        case 1:
            puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][20], 7);
            break;
        case 2:
            puttesti(userPages[1].textBuffer, testi[paramStore[LINGUA].value.uc8][19], 7);
            break;
    }
}

void refresh_values_p2(void)
{
    putvarInt(userPages[2].textBuffer, paramStore[T_BACKLIGHT].value, paramStore[T_BACKLIGHT].size, 1, 1);
    putvarInt(userPages[2].textBuffer, paramStore[LUMINOSITA].value, paramStore[LUMINOSITA].size, 1, 3);
    putvarInt(userPages[2].textBuffer, paramStore[T_SLEEP].value, paramStore[T_SLEEP].size, 1, 5);
    putvarInt(userPages[2].textBuffer, paramStore[DECIMALI].value, paramStore[DECIMALI].size, 1, 7);
}

void refresh_values_p3(void)
{
    putvarInt(adminPages[0].textBuffer, paramStore[PASSWORD].value, paramStore[PASSWORD].size, 1, 1);

    if (paramStore[REVERSE_MAIN].value.uc8)
        //         putstring(adminPages[0].textBuffer, "SI", 1, 3);
        putstring(adminPages[0].textBuffer, "YES", 1, 3);
    else
        putstring(adminPages[0].textBuffer, "NO", 1, 3);

    if (paramStore[REVERSE_SPLASH].value.uc8)
        //         putstring(adminPages[0].textBuffer, "SI", 1, 5);
        putstring(adminPages[0].textBuffer, "YES", 1, 5);
    else
        putstring(adminPages[0].textBuffer, "NO", 1, 5);
}

void refresh_values_p4(void)
{
    putvarInt(adminPages[1].textBuffer, paramStore[AUTO_SOLE].value, paramStore[AUTO_SOLE].size, 1, 1);
    putvarInt(adminPages[1].textBuffer, paramStore[AUTO_PILA].value, paramStore[AUTO_PILA].size, 1, 3);
    putvarInt(adminPages[1].textBuffer, paramStore[SEC_PILA_FOTORES].value, paramStore[SEC_PILA_FOTORES].size, 1, 5);

    if (paramStore[EN_HLVD].value.uc8)
        putstring(adminPages[1].textBuffer, "SI", 1, 7);
    else
        putstring(adminPages[1].textBuffer, "NO", 1, 7);
}

void refresh_values_p5(void)
{
    putvarInt(adminPages[2].textBuffer, paramStore[N_MEDIA].value, paramStore[N_MEDIA].size, 1, 1);
    putvarInt(adminPages[2].textBuffer, paramStore[CLK_TUNE].value, paramStore[CLK_TUNE].size, 1, 3);
    calculateFlow();
    putmillis(adminPages[2].textBuffer, flusso, 1, 5);
}

void refresh_values_p6(void)
{
    putint(adminPages[3].textBuffer, pila, 1, 1);
    putint(adminPages[3].textBuffer, sole, 1, 3);
    //putint(adminPages[1].textBuffer, batteria, 1, 5);
}

void refresh_values_p7(void)
{
    if (modebtn)
    {
        putstring(adminPages[4].textBuffer, "P1 PAG         1", 0, 0);
    }
    else
    {
        putstring(adminPages[4].textBuffer, "P1 PAG         0", 0, 0);
    }

    if (setbtn)
    {
        putstring(adminPages[4].textBuffer, "P2 SET         1", 0, 1);
    }
    else
    {
        putstring(adminPages[4].textBuffer, "P2 SET         0", 0, 1);
    }
    
    if (upbtn)
    {
        putstring(adminPages[4].textBuffer, "P3 UP          1", 0, 2);
    }
    else
    {
        putstring(adminPages[4].textBuffer, "P3 UP          0", 0, 2);
    }

    if (downbtn)
    {
        putstring(adminPages[4].textBuffer, "P4 DOWN        1", 0, 3);
    }
    else
    {
        putstring(adminPages[4].textBuffer, "P4 DOWN        0", 0, 3);
    }
    abicoperchio = 1;
    delay_us(1600);
    
    if (coperchio)
    {
        putstring(adminPages[4].textBuffer, "REED           1", 0, 4);
    }
    else
    {
        putstring(adminPages[4].textBuffer, "REED           0", 0, 4);
    }
    delay_us(1600);
    abicoperchio = 0;
    
    if (IN2)
    {
        putstring(adminPages[4].textBuffer, "LIBERO         1", 0, 5);
    }
    else
    {
        putstring(adminPages[4].textBuffer, "LIBERO         0", 0, 5);
    }
}

void refresh_values_p8(void)
{
    if (abicoperchio)
    {
        putstring(adminPages[5].textBuffer, "AB REED        1", 0, 0);
    }
    else
    {
        putstring(adminPages[5].textBuffer, "AB REED        0", 0, 0);
    }

    if (abifotores)
    {
        putstring(adminPages[5].textBuffer, "AB FOTORES     1", 0, 1);
    }
    else
    {
        putstring(adminPages[5].textBuffer, "AB FOTORES     0", 0, 1);
    }
}

void refresh_values_p9(void) {
    putlongint(adminPages[6].textBuffer, contaimpulsi, 1, 1);
    putlongint(adminPages[6].textBuffer, litritot, 1, 3);
    putint(adminPages[6].textBuffer, secondi, 1, 5);
}






/***********************************************************************/
/*      FUNZIONI GRAFICHE	                                           */

/***********************************************************************/

void putstring(unsigned char pagina[8][16], char *stringa, unsigned char rightalign, unsigned char row) {//visualizza la stringa sul LCD alla riga row, con allineamento a destra o a sinistra
    unsigned char i;
    unsigned char lung = 0;
    clearrow(pagina, row);
    if (row > 7) row = 7;
    lung = strlen(stringa);
    if (lung > 16) lung = 16;
    if (rightalign)
        for (i = 0; i < lung; i++)
            pagina[row][15 - i] = stringa[lung - 1 - i];
    else
        for (i = 0; i < lung; i++)
            pagina[row][i] = stringa[i];
}

void puttesti(unsigned char pagina[8][16], const unsigned char *stringa, unsigned char row) {//visualizza la stringa sul LCD alla riga row, con allineamento a destra o a sinistra
    unsigned char i;
    for (i = 0; i < 16; i++)
        pagina[row][i] = stringa[i];
}

void putvarInt(unsigned char pagina[8][16], varInt numero, paramSize size, unsigned char rightalign, unsigned char row) {//visualizza la stringa sul LCD alla riga row, con allineamento a destra o a sinistra
    char stringa[16];
    switch (size) {
        case UINT8:
            sprintf(stringa, "%u", numero.uc8);
            break;
        case UINT16:
            sprintf(stringa, "%u", numero.ui16);
            break;
        case UINT32:
            sprintf(stringa, "%llu", numero.ui32);
            break;
        case SINT16:
            sprintf(stringa, "%d", numero.si16);
            break;
    }
    putstring(pagina, stringa, rightalign, row);
}

void putint(unsigned char pagina[8][16], int numero, unsigned char rightalign, unsigned char row) {//visualizza la stringa sul LCD alla riga row, con allineamento a destra o a sinistra
    char stringa[16];
    sprintf(stringa, "%d", numero);
    putstring(pagina, stringa, rightalign, row);
}

void putlongint(unsigned char pagina[8][16], unsigned long long numero, unsigned char rightalign, unsigned char row) {//visualizza la stringa sul LCD alla riga row, con allineamento a destra o a sinistra
    char stringa[16];
    sprintf(stringa, "%llu", numero);
    putstring(pagina, stringa, rightalign, row);
}

//void putfloat(unsigned char pagina[8][16], float numero, unsigned char rightalign, unsigned char row) {//visualizza la stringa sul LCD alla riga row, con allineamento a destra o a sinistra
//    char stringa[16];
//    sprintf(stringa, "%.3f", numero); //*****
//    putstring(pagina, stringa, rightalign, row);
//}

void putmillis(unsigned char pagina[8][16], unsigned long long numero, unsigned char rightalign, unsigned char row) {//visualizza la stringa sul LCD alla riga row, con allineamento a destra o a sinistra
    unsigned char i;
    char stringa[16];
    char stringa2[16];
    for (i = 0; i < 16; i++) {
        stringa[i] = 0;
        stringa2[i] = 0;
    }
    //scrivo numero con almeno 4 caratteri ad es. 0123 che poi sarà 0,123
    sprintf(stringa, "%4llu", numero);
    unsigned char lung = strlen(stringa);
    for (i = 0; i < lung; i++)
        if (stringa[i] == 32) stringa[i] = 48; //spazio->0

    //scrivo la parte intera
    for (i = 0; i < lung - 3; i++)
        stringa2[i] = stringa[i];

    if (paramStore[DECIMALI].value.uc8 > 0) {
        //aggiungo la virgola
        stringa2[lung - 3] = '.';
        //scrivo i decimali
        for (i = lung - 3; i < lung + paramStore[DECIMALI].value.uc8 - 3; i++)//era <lung
            stringa2[i + 1] = stringa[i];
    }
    //stringa2[lung + decimali - 2] = 0; //terminatore, era lung+1
    putstring(pagina, stringa2, rightalign, row);
}

void puttenths(unsigned char pagina[8][16], unsigned long long numero, unsigned char rightalign, unsigned char row) {//visualizza la stringa sul LCD alla riga row, con allineamento a destra o a sinistra

    //rightalign ignorato
    unsigned char i;
    char stringa[16];
    char stringa2[16];

    for (i = 0; i < 16; i++) {
        stringa[i] = 0;
        stringa2[i] = 0;
    }
    //scrivo numero con almeno 2 caratteri ad es. 01 che poi sarà 0,1
    sprintf(stringa, "%2llu", numero);
    unsigned char lung = strlen(stringa);
    for (i = 0; i < lung; i++)
        if (stringa[i] == 32) stringa[i] = 48; //spazio->0

    //scrivo la parte intera
    for (i = 0; i < lung - 1; i++)
        stringa2[i] = stringa[i];

    //aggiungo la virgola
    stringa2[lung - 1] = '.';
    //scrivo i decimali
    //    for (i = lung - 1; i < lung; i++)
    //        stringa2[i + 1] = stringa[i];
    stringa2[lung] = stringa[lung - 1];


    //    for (i = 0; i < 16; i++) {
    //        stringa[i] = 32;
    //        stringa2[i] = 32;
    //    }
    //    stringa[15] = '\0';
    //    stringa2[15] = '\0';
    //
    //    //scrivo numero con almeno 2 caratteri ad es. 01 che poi sarà 0,1
    //    //sprintf(stringa, "%2llu", numero);
    //    unsigned long long val64 = numero;
    //    for (i = 14; i > 0; i--) {
    //        stringa[i] = (char) ((val64 % 10ULL) + '0');
    //        val64 /= 10;
    //        if (val64 == 0 && i < 14)//almeno 2 char
    //            break;
    //    }
    //    //scrivo la parte intera
    //    for (i = 0; i < 13; i++)
    //        stringa2[i] = stringa[i + 1];
    //    //aggiungo la virgola
    //    stringa2[13] = '.';
    //    stringa2[14] = stringa[14];

    putstring(pagina, stringa2, rightalign, row);
}

void clearrow(unsigned char pagina[8][16], unsigned char row) {
    unsigned char i;
    for (i = 0; i < 16; i++)
        pagina[row][i] = 32;
}

void clearpage(unsigned char pagina[8][16]) {
    char i;
    for (i = 0; i < 8; i++)
        clearrow(pagina, i);
}
