/* 
 * File:   pageFactory.h
 * Author: Sabbiolino
 *
 * Created on 11 giugno 2016, 17.50
 */

#ifndef PAGEFACTORY_H
#define	PAGEFACTORY_H

#include "parameterStore.h"

typedef struct pageInfo {
    char *name;
    unsigned char key;
    unsigned char paramNumber;
    void (*displayFunction)();
    struct pageInfo *nextPage;
    struct pageInfo *prevPage;
    unsigned char selectedVar;
    unsigned char displayReverse;

    unsigned char textBuffer[8][16];
    tParameter* params[4];

} tPageInfo;

void pageFactoryInit();
void cambioPagina(unsigned char prev);
void cambioPaginaAlt(tPageInfo *newPage);
void cambioVariabile();


#endif	/* PAGEFACTORY_H */

