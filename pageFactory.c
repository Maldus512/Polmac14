#include "display.h"
#include "displayDriver.h"
#include <string.h>
#include "parameterStore.h"
#include "pageFactory.h"

extern unsigned char display_reverse;
extern unsigned char LCD_changed;

tPageInfo userPages[4];
tPageInfo adminPages[7];
tPageInfo *activePage;
extern tParameter paramStore[PARAM_NUM];
extern unsigned char nextrow;





void pageFactoryInit()
{
    userPages[0].name = "MAIN";
    userPages[0].key = 0;

    if (paramStore[REVERSE_MAIN].value.uc8)
        userPages[0].displayReverse = 56;
    else
        userPages[0].displayReverse = 0;

    userPages[0].nextPage = &userPages[1];
    userPages[0].prevPage = &adminPages[0];
    userPages[0].paramNumber = 0;
    userPages[0].displayFunction = &refresh_values_p0;

    userPages[1].name = "USER1";
    userPages[1].key = 1;
    userPages[1].displayReverse = 1;
    userPages[1].nextPage = &userPages[2];
    userPages[1].prevPage = &userPages[1];
    userPages[1].paramNumber = 4;
    userPages[1].params[0] = &paramStore[LINGUA];
    userPages[1].params[1] = &paramStore[IMPULSI];
    userPages[1].params[2] = &paramStore[UNITA];
    userPages[1].params[3] = &paramStore[EVIDENZIA];
    userPages[1].displayFunction = &refresh_values_p1;

    userPages[2].name = "USER2";
    userPages[2].key = 2;
    userPages[2].displayReverse = 1;
    userPages[2].nextPage = &userPages[0];
    userPages[2].prevPage = &userPages[2];
    userPages[2].paramNumber = 4;
    userPages[2].params[0] = &paramStore[T_BACKLIGHT];
    userPages[2].params[1] = &paramStore[LUMINOSITA];
    userPages[2].params[2] = &paramStore[T_SLEEP];
    userPages[2].params[3] = &paramStore[DECIMALI];
    userPages[2].displayFunction = &refresh_values_p2;

    userPages[3].name = "MAIN2";
    userPages[3].key = 10;

    if (paramStore[REVERSE_MAIN].value.uc8)
        userPages[3].displayReverse = 248;
    else
        userPages[3].displayReverse = 0;

    userPages[3].nextPage = &userPages[1];
    userPages[3].prevPage = &adminPages[0];
    userPages[3].paramNumber = 0;
    userPages[3].displayFunction = &refresh_values_p10;

    adminPages[0].name = "TECNICO";
    adminPages[0].key = 3;
    adminPages[0].displayReverse = 1;
    adminPages[0].nextPage = &userPages[0];
    adminPages[0].prevPage = &adminPages[1];
    adminPages[0].paramNumber = 3;
    adminPages[0].params[0] = &paramStore[PASSWORD];
    adminPages[0].params[1] = &paramStore[REVERSE_MAIN];
    adminPages[0].params[2] = &paramStore[REVERSE_SPLASH];
    adminPages[0].displayFunction = &refresh_values_p3;

    adminPages[1].name = "HSW1";
    adminPages[1].key = 4;
    adminPages[1].displayReverse = 1;
    adminPages[1].nextPage = &adminPages[2];
    adminPages[1].prevPage = &adminPages[1];
    adminPages[1].paramNumber = 4;
    adminPages[1].params[0] = &paramStore[AUTO_SOLE];
    adminPages[1].params[1] = &paramStore[AUTO_PILA];
    adminPages[1].params[2] = &paramStore[SEC_PILA_FOTORES];
    adminPages[1].params[3] = &paramStore[EN_HLVD];
    adminPages[1].displayFunction = &refresh_values_p4;

    adminPages[2].name = "HSW2";
    adminPages[2].key = 5;
    adminPages[2].displayReverse = 1;
    adminPages[2].nextPage = &adminPages[3];
    adminPages[2].prevPage = &adminPages[2];
    adminPages[2].paramNumber = 2;
    adminPages[2].params[0] = &paramStore[N_MEDIA];
    adminPages[2].params[1] = &paramStore[CLK_TUNE];
    adminPages[2].displayFunction = &refresh_values_p5;

    adminPages[3].name = "TEST AD";
    adminPages[3].key = 6;
    adminPages[3].displayReverse = 0;
    adminPages[3].nextPage = &adminPages[4];
    adminPages[3].prevPage = &adminPages[3];
    adminPages[3].displayFunction = &refresh_values_p6;
    adminPages[3].paramNumber = 0;

    adminPages[4].name = "TEST IN";
    adminPages[4].key = 7;
    adminPages[4].displayReverse = 0;
    adminPages[4].nextPage = &adminPages[5];
    adminPages[4].prevPage = &adminPages[4];
    adminPages[4].displayFunction = &refresh_values_p7;
    adminPages[4].paramNumber = 0;

    adminPages[5].name = "TEST OUT";
    adminPages[5].key = 8;
    adminPages[5].displayReverse = 1;
    adminPages[5].nextPage = &adminPages[6];
    adminPages[5].prevPage = &adminPages[5];
    adminPages[5].displayFunction = &refresh_values_p8;
    adminPages[5].paramNumber = 5;
    adminPages[5].params[0] = &paramStore[AB_REED];
    adminPages[5].params[1] = &paramStore[AB_FOTORES];
    adminPages[5].params[2] = &paramStore[VUOTO];
    adminPages[5].params[3] = &paramStore[AB_STOP];
    adminPages[5].params[4] = &paramStore[LCD_CONTRAST];

    adminPages[6].name = "CONTATORE";
    adminPages[6].key = 9;
    adminPages[6].displayReverse = 0;
    adminPages[6].nextPage = &adminPages[1];
    adminPages[6].prevPage = &userPages[0];
    adminPages[6].displayFunction = &refresh_values_p9;
    adminPages[6].paramNumber = 0;

    activePage = &userPages[0];
}



void cambioPagina(unsigned char prev)
{
    //salvataggio parametri
    if (activePage->paramNumber > 0)
    {
        int i = 0;
        for (i = 0; i < activePage->paramNumber; i++)
            writeParam(activePage->params[i]->key);
    }

    if (prev)
        activePage = activePage->prevPage;
    else
        activePage = activePage->nextPage;

    activePage->selectedVar = 0;

    if (activePage->key == 0)
    {
        if (paramStore[REVERSE_MAIN].value.uc8)
            display_reverse = 56;
        else
            display_reverse = 0;

    }
    else if (activePage->key == 10)
    {
        if (paramStore[REVERSE_MAIN].value.uc8)
            display_reverse = 248;
        else
            display_reverse = 0;
    }
    else
    {
        display_reverse = activePage->displayReverse;
    }
    //refresh_display();
    LCD_changed = 0xFF;
    nextrow = 0;
}



void cambioPaginaAlt(tPageInfo *newPage)
{
    //salvataggio parametri
    if (activePage->paramNumber > 0)
    {
        int i = 0;
        for (i = 0; i < activePage->paramNumber; i++)
            writeParam(activePage->params[i]->key);
    }
    activePage = newPage;
    activePage->selectedVar = 0;

    if (activePage->key == 0)
    {
        if (paramStore[REVERSE_MAIN].value.uc8)
            display_reverse = 56;
        else
            display_reverse = 0;

    }
    else if (activePage->key == 10)
    {
        if (paramStore[REVERSE_MAIN].value.uc8)
            display_reverse = 248;
        else
            display_reverse = 0;
    }
    else
    {
        display_reverse = activePage->displayReverse;
    }
    //refresh_display();
    LCD_changed = 0xFF;
    nextrow = 0;
}



void cambioVariabile()
{
    if (activePage->paramNumber > 0)
    {
        writeParam(activePage->params[activePage->selectedVar]->key);
        unsigned char step = 1;

        if (activePage->key == 8)
            step = 0;

        LCD_changed = LCD_changed | (1 << (activePage->selectedVar << step));
        activePage->selectedVar = (activePage->selectedVar + 1) % activePage->paramNumber;
        //evidenzio la variabile in edit nel display
        display_reverse = (1 << (activePage->selectedVar << step));
        LCD_changed = LCD_changed | (1 << (activePage->selectedVar << step));
        //        if (activePage->key == 5)
        //            LCD_changed = LCD_changed | 32; //aggiornare sempre il flusso
        //        if (activePage->key == 3)
        //            LCD_changed = LCD_changed | 2;//per beccare quando password diventa 0?
        return;
    }

}
