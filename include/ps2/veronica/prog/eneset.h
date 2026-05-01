#ifndef _ENESET_H_
#define _ENESET_H_

#include "types.h"

void bhInitEnemy();
BH_PWORK* bhSetEnemy(EGG_WORK* etp, int unused);
void bhCheckEneWorkNum();
void bhControlEnemy();
void bhEne00(BH_PWORK* ep);
void bhEne56(BH_PWORK* ep);
void bhDrawEnemy();
void bhDrawEneObject();
void* bhEne_CallocWork(int size, int param);
void bhEne_SetCallFunc(void(*func)(BH_PWORK*), unsigned int no);

#endif
