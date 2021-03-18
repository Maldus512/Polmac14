/* 
 * File:   eepromStore.h
 * Author: Sabbiolino
 *
 * Created on 12 giugno 2016, 11.40
 */

#ifndef EEPROMSTORE_H
#define	EEPROMSTORE_H

#define LINGUA              0
#define IMPULSI             1
#define UNITA               2
#define EVIDENZIA           11
#define T_BACKLIGHT         3
#define T_SLEEP             4
#define LUMINOSITA          6
#define DECIMALI            13
#define PASSWORD            18
#define REVERSE_MAIN        14
#define REVERSE_SPLASH      15
#define AUTO_SOLE           5
#define AUTO_PILA           7
#define SEC_PILA_FOTORES    8
#define EN_HLVD             9
#define N_MEDIA             12
#define CLK_TUNE            16
//#define AB_PILA           21
#define AB_REED             19
#define AB_FOTORES          20
#define COUNTER             10
#define CHKSUM              17
#define AB_STOP             21
#define LCD_CONTRAST        22
#define VUOTO               23

#define PARAM_NUM           24


typedef enum {
    UINT8, UINT16, UINT32, SINT16, UINT64
} paramSize;

typedef union {
    unsigned char uc8;
    unsigned int ui16;
    unsigned long int ui32;
    unsigned long long int ui64;
    int si16;
} varInt;

typedef struct parameter {
    char *name;
    unsigned char key;
    paramSize size;
    unsigned char inEeprom;
    unsigned char readOnly;
    unsigned int address;
    varInt value;
    varInt oldvalue;
    varInt minValue;
    varInt maxValue;
    varInt defaultValue;
    unsigned char enRollOver;
    void (*writeCallback)();
    unsigned char wCallEnable;
    void (*upCallback)();
    unsigned char upCallEnable;
    void (*downCallback)();
    unsigned char downCallEnable;
} tParameter;

void initParameters();
void writeParam(unsigned int index);
void readParam(unsigned int index);
void increment(unsigned int index,varInt amount);
void decrement(unsigned int index,varInt amount);
void writeCounterWithoutPack(void);

#endif	/* EEPROMSTORE_H */

