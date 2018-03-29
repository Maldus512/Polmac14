#include "main.h"
#include "DEE Emulation 16-bit\DEE Emulation 16-bit.h"
#include "parameterStore.h"
#include "callbacks.h"
#include <limits.h>



tParameter paramStore[21];
unsigned char firstBoot;
unsigned char init = TRUE;

void writeParam(unsigned int index) {
    unsigned int a, b;
    switch (paramStore[index].size) {
        case UINT8:
            if (paramStore[index].value.uc8 != paramStore[index].oldvalue.uc8 || init) {
                if (paramStore[index].inEeprom)
                    DataEEWrite(paramStore[index].value.uc8, paramStore[index].address);
                paramStore[index].oldvalue.uc8 = paramStore[index].value.uc8;
                if (paramStore[index].wCallEnable && !init)
                    (*paramStore[index].writeCallback)();
            }
            break;
        case UINT16:
            if (paramStore[index].value.ui16 != paramStore[index].oldvalue.ui16 || init) {
                if (paramStore[index].inEeprom)
                    DataEEWrite(paramStore[index].value.ui16, paramStore[index].address);
                paramStore[index].oldvalue.ui16 = paramStore[index].value.ui16;
                if (paramStore[index].wCallEnable && !init)
                    (*paramStore[index].writeCallback)();
            }
            break;
        case UINT32:
            if (paramStore[index].value.ui32 != paramStore[index].oldvalue.ui32 || init) {
                if (paramStore[index].inEeprom) {
                    a = (unsigned int) (paramStore[index].value.ui32 >> 16);//high byte
                    b = (unsigned int) (paramStore[index].value.ui32 & 0x0000FFFF);//low byte
                    DataEEWrite(a, paramStore[index].address);
                    DataEEWrite(b, paramStore[index].address + 2);
                }
                paramStore[index].oldvalue.ui32 = paramStore[index].value.ui32;
                if (paramStore[index].wCallEnable && !init)
                    (*paramStore[index].writeCallback)();
            }
            break;
        case SINT16:
            if (paramStore[index].value.si16 != paramStore[index].oldvalue.si16 || init) {
                //TODO + 32768 oppure usare ui16
                if (paramStore[index].inEeprom)
                    DataEEWrite(paramStore[index].value.ui16, paramStore[index].address);
                paramStore[index].oldvalue.si16 = paramStore[index].value.si16;
                if (paramStore[index].wCallEnable && !init)
                    (*paramStore[index].writeCallback)();
            }
            break;
    }

}

void readParam(unsigned int index) {
    if (paramStore[index].inEeprom) {
        unsigned int a, b;
        switch (paramStore[index].size) {
            case UINT8:
                paramStore[index].value.uc8 = DataEERead(paramStore[index].address);
                paramStore[index].oldvalue.uc8 = paramStore[index].value.uc8;
                break;
            case UINT16:
                paramStore[index].value.ui16 = DataEERead(paramStore[index].address);
                paramStore[index].oldvalue.ui16 = paramStore[index].value.ui16;
                break;
            case UINT32:
                a = DataEERead(paramStore[index].address);
                b = DataEERead(paramStore[index].address + 2);
                paramStore[index].value.ui32 = (unsigned long long int) a << 16 | (unsigned long long int) b;
                paramStore[index].oldvalue.ui32 = paramStore[index].value.ui32;
                break;
            case SINT16:
                //TODO -32768
                paramStore[index].value.ui16 = DataEERead(paramStore[index].address);
                paramStore[index].oldvalue.si16 = paramStore[index].value.si16;
                break;
        }
    }
}

void initParameters() {

    //pag1
    paramStore[LINGUA].name = "Language        ";
    paramStore[LINGUA].size = UINT8;
    paramStore[LINGUA].defaultValue.uc8 = 1;
    paramStore[LINGUA].enRollOver = TRUE;
    paramStore[LINGUA].minValue.uc8 = 0;
    paramStore[LINGUA].maxValue.uc8 = 7;
    paramStore[LINGUA].inEeprom = TRUE;
    paramStore[LINGUA].readOnly = FALSE;
    paramStore[LINGUA].wCallEnable = TRUE;
    paramStore[LINGUA].writeCallback = &c_lingua;
    paramStore[LINGUA].upCallEnable = FALSE;
    paramStore[LINGUA].downCallEnable = FALSE;

    paramStore[IMPULSI].name = "Pulses per Liter";
    paramStore[IMPULSI].size = UINT16;
    paramStore[IMPULSI].defaultValue.ui16 = 1000;
    paramStore[IMPULSI].enRollOver = TRUE;
    paramStore[IMPULSI].minValue.ui16 = 1;
    paramStore[IMPULSI].maxValue.ui16 = 65535;
    paramStore[IMPULSI].inEeprom = TRUE;
    paramStore[IMPULSI].readOnly = FALSE;
    paramStore[IMPULSI].wCallEnable = TRUE;
    paramStore[IMPULSI].writeCallback = &c_impulsi;
    paramStore[IMPULSI].upCallEnable = FALSE;
    paramStore[IMPULSI].downCallEnable = FALSE;

    paramStore[UNITA].name = "Unit of Measure ";
    paramStore[UNITA].size = UINT8;
    paramStore[UNITA].defaultValue.uc8 = 0;
    paramStore[UNITA].enRollOver = TRUE;
    paramStore[UNITA].minValue.uc8 = 0;
    paramStore[UNITA].maxValue.uc8 = 2;
    paramStore[UNITA].inEeprom = TRUE;
    paramStore[UNITA].readOnly = FALSE;
    paramStore[UNITA].wCallEnable = TRUE;
    paramStore[UNITA].writeCallback = &c_unita;
    paramStore[UNITA].upCallEnable = FALSE;
    paramStore[UNITA].downCallEnable = FALSE;

    paramStore[EVIDENZIA].name = "Evidenzia";
    paramStore[EVIDENZIA].size = UINT8;
    paramStore[EVIDENZIA].defaultValue.uc8 = 2;
    paramStore[EVIDENZIA].enRollOver = TRUE;
    paramStore[EVIDENZIA].minValue.uc8 = 0;
    paramStore[EVIDENZIA].maxValue.uc8 = 2;
    paramStore[EVIDENZIA].inEeprom = TRUE;
    paramStore[EVIDENZIA].readOnly = FALSE;
    paramStore[EVIDENZIA].wCallEnable = TRUE;
    paramStore[EVIDENZIA].writeCallback = &c_evidenzia;
    paramStore[EVIDENZIA].upCallEnable = FALSE;
    paramStore[EVIDENZIA].downCallEnable = FALSE;

    //pag2

    paramStore[T_BACKLIGHT].name = "Backlight Time  ";
    paramStore[T_BACKLIGHT].size = UINT16;
    paramStore[T_BACKLIGHT].defaultValue.ui16 = 8;
    paramStore[T_BACKLIGHT].enRollOver = TRUE;
    paramStore[T_BACKLIGHT].minValue.ui16 = 0;
    paramStore[T_BACKLIGHT].maxValue.ui16 = 600;
    paramStore[T_BACKLIGHT].inEeprom = TRUE;
    paramStore[T_BACKLIGHT].readOnly = FALSE;
    paramStore[T_BACKLIGHT].wCallEnable = FALSE;
    paramStore[T_BACKLIGHT].upCallEnable = FALSE;
    paramStore[T_BACKLIGHT].downCallEnable = FALSE;

    paramStore[T_SLEEP].name = "Shutdown Timeout";
    paramStore[T_SLEEP].size = UINT16;
    paramStore[T_SLEEP].defaultValue.ui16 = 60;
    paramStore[T_SLEEP].enRollOver = TRUE;
    paramStore[T_SLEEP].minValue.ui16 = 5;
    paramStore[T_SLEEP].maxValue.ui16 = 600;
    paramStore[T_SLEEP].inEeprom = TRUE;
    paramStore[T_SLEEP].readOnly = FALSE;
    paramStore[T_SLEEP].wCallEnable = FALSE;
    paramStore[T_SLEEP].upCallEnable = FALSE;
    paramStore[T_SLEEP].downCallEnable = FALSE;

    paramStore[LUMINOSITA].name = "Brightness      ";
    paramStore[LUMINOSITA].size = UINT8;
    paramStore[LUMINOSITA].defaultValue.uc8 = 2;
    paramStore[LUMINOSITA].enRollOver = TRUE;
    paramStore[LUMINOSITA].minValue.uc8 = 0;
    paramStore[LUMINOSITA].maxValue.uc8 = 10;
    paramStore[LUMINOSITA].inEeprom = TRUE;
    paramStore[LUMINOSITA].readOnly = FALSE;
    paramStore[LUMINOSITA].wCallEnable = FALSE;
    paramStore[LUMINOSITA].upCallEnable = FALSE;
    paramStore[LUMINOSITA].downCallEnable = FALSE;

    paramStore[DECIMALI].name = "Decimali";
    paramStore[DECIMALI].size = UINT8;
    paramStore[DECIMALI].defaultValue.uc8 = 0;
    paramStore[DECIMALI].enRollOver = TRUE;
    paramStore[DECIMALI].minValue.uc8 = 0;
    paramStore[DECIMALI].maxValue.uc8 = 2;
    paramStore[DECIMALI].inEeprom = TRUE;
    paramStore[DECIMALI].readOnly = FALSE;
    paramStore[DECIMALI].wCallEnable = FALSE;
    paramStore[DECIMALI].upCallEnable = FALSE;
    paramStore[DECIMALI].downCallEnable = FALSE;

    //pag3

    paramStore[PASSWORD].name = "Password";
    paramStore[PASSWORD].size = UINT16;
    paramStore[PASSWORD].defaultValue.ui16 = 0;
    paramStore[PASSWORD].value.ui16 = 0;
    paramStore[PASSWORD].enRollOver = FALSE;
    paramStore[PASSWORD].minValue.ui16 = 0;
    paramStore[PASSWORD].maxValue.ui16 = 29999;
    paramStore[PASSWORD].inEeprom = FALSE;
    paramStore[PASSWORD].readOnly = FALSE;
    paramStore[PASSWORD].wCallEnable = TRUE;
    paramStore[PASSWORD].writeCallback = &c_password;
    paramStore[PASSWORD].upCallEnable = FALSE;
    paramStore[PASSWORD].downCallEnable = FALSE;

    paramStore[REVERSE_MAIN].name = "Reverse Main";
    paramStore[REVERSE_MAIN].size = UINT8;
    paramStore[REVERSE_MAIN].defaultValue.uc8 = 0;
    paramStore[REVERSE_MAIN].enRollOver = FALSE;
    paramStore[REVERSE_MAIN].minValue.uc8 = 0;
    paramStore[REVERSE_MAIN].maxValue.uc8 = 1;
    paramStore[REVERSE_MAIN].inEeprom = TRUE;
    paramStore[REVERSE_MAIN].readOnly = FALSE;
    paramStore[REVERSE_MAIN].wCallEnable = FALSE;
    paramStore[REVERSE_MAIN].upCallEnable = FALSE;
    paramStore[REVERSE_MAIN].downCallEnable = FALSE;

    paramStore[REVERSE_SPLASH].name = "Reverse Splash";
    paramStore[REVERSE_SPLASH].size = UINT8;
    paramStore[REVERSE_SPLASH].defaultValue.uc8 = 0;
    paramStore[REVERSE_SPLASH].enRollOver = FALSE;
    paramStore[REVERSE_SPLASH].minValue.uc8 = 0;
    paramStore[REVERSE_SPLASH].maxValue.uc8 = 1;
    paramStore[REVERSE_SPLASH].inEeprom = TRUE;
    paramStore[REVERSE_SPLASH].readOnly = FALSE;
    paramStore[REVERSE_SPLASH].wCallEnable = FALSE;
    paramStore[REVERSE_SPLASH].upCallEnable = FALSE;
    paramStore[REVERSE_SPLASH].downCallEnable = FALSE;

    //pag4

    paramStore[AUTO_SOLE].name = "Soglia sole";
    paramStore[AUTO_SOLE].size = UINT16;
    paramStore[AUTO_SOLE].defaultValue.ui16 = 100;
    paramStore[AUTO_SOLE].enRollOver = TRUE;
    paramStore[AUTO_SOLE].minValue.ui16 = 0;
    paramStore[AUTO_SOLE].maxValue.ui16 = 1023;
    paramStore[AUTO_SOLE].inEeprom = TRUE;
    paramStore[AUTO_SOLE].readOnly = FALSE;
    paramStore[AUTO_SOLE].wCallEnable = FALSE;
    paramStore[AUTO_SOLE].upCallEnable = TRUE;
    paramStore[AUTO_SOLE].upCallback = &c_sole_up;
    paramStore[AUTO_SOLE].downCallEnable = TRUE;
    paramStore[AUTO_SOLE].downCallback = &c_sole_down;

    paramStore[AUTO_PILA].name = "Soglia batteria";
    paramStore[AUTO_PILA].size = UINT16;
    paramStore[AUTO_PILA].defaultValue.ui16 = 330;
    paramStore[AUTO_PILA].enRollOver = TRUE;
    paramStore[AUTO_PILA].minValue.ui16 = 0;
    paramStore[AUTO_PILA].maxValue.ui16 = 1023;
    paramStore[AUTO_PILA].inEeprom = TRUE;
    paramStore[AUTO_PILA].readOnly = FALSE;
    paramStore[AUTO_PILA].wCallEnable = FALSE;
    paramStore[AUTO_PILA].upCallEnable = TRUE;
    paramStore[AUTO_PILA].upCallback = &c_pila_up;
    paramStore[AUTO_PILA].downCallEnable = TRUE;
    paramStore[AUTO_PILA].downCallback = &c_pila_down;

    paramStore[SEC_PILA_FOTORES].name = "Sec batt sole";
    paramStore[SEC_PILA_FOTORES].size = UINT16;
    paramStore[SEC_PILA_FOTORES].defaultValue.ui16 = 2;
    paramStore[SEC_PILA_FOTORES].enRollOver = TRUE;
    paramStore[SEC_PILA_FOTORES].minValue.ui16 = 0;
    paramStore[SEC_PILA_FOTORES].maxValue.ui16 = 600;
    paramStore[SEC_PILA_FOTORES].inEeprom = TRUE;
    paramStore[SEC_PILA_FOTORES].readOnly = FALSE;
    paramStore[SEC_PILA_FOTORES].wCallEnable = FALSE;
    paramStore[SEC_PILA_FOTORES].upCallEnable = FALSE;
    paramStore[SEC_PILA_FOTORES].downCallEnable = FALSE;

    paramStore[EN_HLVD].name = "En HLVD";
    paramStore[EN_HLVD].size = UINT8;
    paramStore[EN_HLVD].defaultValue.uc8 = 1;
    paramStore[EN_HLVD].enRollOver = TRUE;
    paramStore[EN_HLVD].minValue.uc8 = 0;
    paramStore[EN_HLVD].maxValue.uc8 = 1;
    paramStore[EN_HLVD].inEeprom = TRUE;
    paramStore[EN_HLVD].readOnly = FALSE;
    paramStore[EN_HLVD].wCallEnable = TRUE;
    paramStore[EN_HLVD].writeCallback = &c_low_v_save;
    paramStore[EN_HLVD].upCallEnable = FALSE;
    paramStore[EN_HLVD].downCallEnable = FALSE;

    //pag5

    paramStore[N_MEDIA].name = "Media";
    paramStore[N_MEDIA].size = UINT8;
    paramStore[N_MEDIA].defaultValue.uc8 = 10;
    paramStore[N_MEDIA].enRollOver = TRUE;
    paramStore[N_MEDIA].minValue.uc8 = 1;
    paramStore[N_MEDIA].maxValue.uc8 = 10;
    paramStore[N_MEDIA].inEeprom = TRUE;
    paramStore[N_MEDIA].readOnly = FALSE;
    paramStore[N_MEDIA].wCallEnable = FALSE;
    paramStore[N_MEDIA].upCallEnable = FALSE;
    paramStore[N_MEDIA].downCallEnable = FALSE;

    paramStore[CLK_TUNE].name = "Clock Tune";
    paramStore[CLK_TUNE].size = SINT16;
    paramStore[CLK_TUNE].defaultValue.si16 = 0;
    paramStore[CLK_TUNE].enRollOver = TRUE;
    paramStore[CLK_TUNE].minValue.si16 = -32;
    paramStore[CLK_TUNE].maxValue.si16 = 31;
    paramStore[CLK_TUNE].inEeprom = TRUE;
    paramStore[CLK_TUNE].readOnly = FALSE;
    paramStore[CLK_TUNE].wCallEnable = TRUE;
    paramStore[CLK_TUNE].writeCallback = &c_clock_tune;
    paramStore[CLK_TUNE].upCallEnable = FALSE;
    paramStore[CLK_TUNE].downCallEnable = FALSE;

    //pag8
    paramStore[AB_REED].name = "Abi Reed";
    paramStore[AB_REED].size = UINT8;
    paramStore[AB_REED].defaultValue.uc8 = 0;
    paramStore[AB_REED].enRollOver = FALSE;
    paramStore[AB_REED].minValue.uc8 = 0;
    paramStore[AB_REED].maxValue.uc8 = 1;
    paramStore[AB_REED].inEeprom = FALSE;
    paramStore[AB_REED].readOnly = FALSE;
    paramStore[AB_REED].wCallEnable = FALSE;
    //paramStore[AB_REED].writeCallback = &c_abReed;
    paramStore[AB_REED].upCallEnable = TRUE;
    paramStore[AB_REED].upCallback = &c_abReed;
    paramStore[AB_REED].downCallEnable = TRUE;
    paramStore[AB_REED].downCallback = &c_abReed;

    paramStore[AB_FOTORES].name = "Abi Reed";
    paramStore[AB_FOTORES].size = UINT8;
    paramStore[AB_FOTORES].defaultValue.uc8 = 0;
    paramStore[AB_FOTORES].enRollOver = FALSE;
    paramStore[AB_FOTORES].minValue.uc8 = 0;
    paramStore[AB_FOTORES].maxValue.uc8 = 1;
    paramStore[AB_FOTORES].inEeprom = FALSE;
    paramStore[AB_FOTORES].readOnly = FALSE;
    paramStore[AB_FOTORES].wCallEnable = FALSE;
    //paramStore[AB_FOTORES].writeCallback = &c_abFotores;
    paramStore[AB_FOTORES].upCallEnable = TRUE;
    paramStore[AB_FOTORES].upCallback = &c_abFotores;
    paramStore[AB_FOTORES].downCallEnable = TRUE;
    paramStore[AB_FOTORES].downCallback = &c_abFotores;


    //altri

    paramStore[COUNTER].name = "Counter";
    paramStore[COUNTER].size = UINT32;
    paramStore[COUNTER].defaultValue.ui32 = 0;
    paramStore[COUNTER].enRollOver = TRUE;
    paramStore[COUNTER].minValue.ui32 = 0;
    paramStore[COUNTER].maxValue.ui32 = 4294967295LL;
    paramStore[COUNTER].inEeprom = TRUE;
    paramStore[COUNTER].readOnly = TRUE;
    paramStore[COUNTER].wCallEnable = FALSE;
    paramStore[COUNTER].upCallEnable = FALSE;
    paramStore[COUNTER].downCallEnable = FALSE;


    paramStore[CHKSUM].name = "Check EEProm";
    paramStore[CHKSUM].size = UINT16;
    paramStore[CHKSUM].defaultValue.ui16 = 12345;
    paramStore[CHKSUM].enRollOver = TRUE;
    paramStore[CHKSUM].minValue.ui16 = 0;
    paramStore[CHKSUM].maxValue.ui16 = 65535;
    paramStore[CHKSUM].inEeprom = TRUE;
    paramStore[CHKSUM].readOnly = TRUE;
    paramStore[CHKSUM].wCallEnable = FALSE;
    paramStore[CHKSUM].upCallEnable = FALSE;
    paramStore[CHKSUM].downCallEnable = FALSE;


    DataEEInit();
    dataEEFlags.val = 0;
    int i;
    unsigned int indirizzo = 0;
    for (i = 0; i < 21; i++) {
        paramStore[i].key = i;
        if (paramStore[i].inEeprom) {
            switch (paramStore[i].size) {
                case UINT8:
                    paramStore[i].address = indirizzo + 1;
                    break;
                case UINT16:
                    paramStore[i].address = indirizzo;
                    break;
                case UINT32:
                    paramStore[i].address = indirizzo;
                    indirizzo += 2;
                    break;
                case SINT16:
                    paramStore[i].address = indirizzo;
                    break;
            }
            indirizzo += 2;
        }
    }

    readParam(17);
    if (paramStore[17].value.ui16 == 12345)
        firstBoot = FALSE;
    else
        firstBoot = TRUE;

    for (i = 0; i < 21; i++) {
        if (firstBoot) {
            paramStore[i].value = paramStore[i].defaultValue;
            writeParam(i);
        } else {
            readParam(i);
        }
    }

    init = FALSE;
}

void increment(unsigned int index, varInt amount) {
    if (!paramStore[index].readOnly) {
        switch (paramStore[index].size) {
            case UINT8:
                if (paramStore[index].value.uc8 == paramStore[index].maxValue.uc8) {
                    if (paramStore[index].enRollOver)
                        paramStore[index].value.uc8 = paramStore[index].minValue.uc8;
                } else {
                    if ((paramStore[index].value.uc8 + amount.uc8 <= paramStore[index].maxValue.uc8) && (UCHAR_MAX - paramStore[index].value.uc8 >  amount.uc8))
                        paramStore[index].value.uc8 = paramStore[index].value.uc8 + amount.uc8;
                    else
                        paramStore[index].value.uc8 = paramStore[index].maxValue.uc8;
                }
                break;
            case UINT16:
                if (paramStore[index].value.ui16 == paramStore[index].maxValue.ui16) {
                    if (paramStore[index].enRollOver)
                        paramStore[index].value.ui16 = paramStore[index].minValue.ui16;
                } else {
                    if ((paramStore[index].value.ui16 + amount.ui16 <= paramStore[index].maxValue.ui16) && (UINT_MAX - paramStore[index].value.ui16 >  amount.ui16))
                        paramStore[index].value.ui16 = paramStore[index].value.ui16 + amount.ui16;
                    else
                        paramStore[index].value.ui16 = paramStore[index].maxValue.ui16;
                }
                break;
            case UINT32:
                if (paramStore[index].value.ui32 == paramStore[index].maxValue.ui32) {
                    if (paramStore[index].enRollOver)
                        paramStore[index].value.ui32 = paramStore[index].minValue.ui32;
                } else {
                    if ((paramStore[index].value.ui32 + amount.ui32 <= paramStore[index].maxValue.ui32) && (ULONG_MAX - paramStore[index].value.ui32 >  amount.ui32))
                        paramStore[index].value.ui32 = paramStore[index].value.ui32 + amount.ui32;
                    else
                        paramStore[index].value.ui32 = paramStore[index].maxValue.ui32;
                }
                break;
            case SINT16:
                if (paramStore[index].value.si16 == paramStore[index].maxValue.si16) {
                    if (paramStore[index].enRollOver)
                        paramStore[index].value.si16 = paramStore[index].minValue.si16;
                } else {
                    // 32767 - 31 
                    if (paramStore[index].value.si16 + amount.si16 <= paramStore[index].maxValue.si16) //&& (INT_MAX - paramStore[index].value.si16 >=  amount.si16))
                        paramStore[index].value.si16 = paramStore[index].value.si16 + amount.si16;
                    else
                        paramStore[index].value.si16 = paramStore[index].maxValue.si16;
                }
                break;
        }
        if (paramStore[index].upCallEnable && !init)
            (*paramStore[index].upCallback)();
    }
}

void decrement(unsigned int index, varInt amount) {
    if (!paramStore[index].readOnly) {
        switch (paramStore[index].size) {
            case UINT8:
                if (paramStore[index].value.uc8 == paramStore[index].minValue.uc8) {
                    if (paramStore[index].enRollOver)
                        paramStore[index].value.uc8 = paramStore[index].maxValue.uc8;
                } else {
                    if ((paramStore[index].value.uc8 - amount.uc8 >= paramStore[index].minValue.uc8) && (paramStore[index].value.uc8 > amount.uc8))
                        paramStore[index].value.uc8 = paramStore[index].value.uc8 - amount.uc8;
                    else
                        paramStore[index].value.uc8 = paramStore[index].minValue.uc8;
                }
                break;
            case UINT16:
                if (paramStore[index].value.ui16 == paramStore[index].minValue.ui16) {
                    if (paramStore[index].enRollOver)
                        paramStore[index].value.ui16 = paramStore[index].maxValue.ui16;
                } else {
                    if ((paramStore[index].value.ui16 - amount.ui16 >= paramStore[index].minValue.ui16) && (paramStore[index].value.ui16 > amount.ui16))
                        paramStore[index].value.ui16 = paramStore[index].value.ui16 - amount.ui16;
                    else
                        paramStore[index].value.ui16 = paramStore[index].minValue.ui16;
                }
                break;
            case UINT32:
                if (paramStore[index].value.ui32 == paramStore[index].minValue.ui32) {
                    if (paramStore[index].enRollOver)
                        paramStore[index].value.ui32 = paramStore[index].maxValue.ui32;
                } else {
                    if ((paramStore[index].value.ui32 - amount.ui32 >= paramStore[index].minValue.ui32) && (paramStore[index].value.ui32 > amount.ui32))
                        paramStore[index].value.ui32 = paramStore[index].value.ui32 - amount.ui32;
                    else
                        paramStore[index].value.ui32 = paramStore[index].minValue.ui32;
                }
                break;
            case SINT16:
                if (paramStore[index].value.si16 == paramStore[index].minValue.si16) {
                    if (paramStore[index].enRollOver)
                        paramStore[index].value.si16 = paramStore[index].maxValue.si16;
                } else {
                    if (paramStore[index].value.si16 - amount.si16 >= paramStore[index].minValue.si16)// && (paramStore[index].value.si16 - INT_MIN >=  amount.si16))
                        paramStore[index].value.si16 = paramStore[index].value.si16 - amount.si16;
                    else
                        paramStore[index].value.si16 = paramStore[index].minValue.si16;
                }
                break;
        }
        if (paramStore[index].downCallEnable && !init)
            (*paramStore[index].downCallback)();
    }
    
}

