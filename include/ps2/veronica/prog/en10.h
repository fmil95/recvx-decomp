#ifndef _EN10_H_
#define _EN10_H_

#include "types.h"

void bhEne10(BH_PWORK* epw);
void bhEne10_Init(BH_PWORK* epw);
void bhEne10_CheckPos(BH_PWORK* epw);
void bhEne10_Brain(BH_PWORK* epw);
void bhEne10_Move(BH_PWORK* epw);
void bhEne10_MV00();
void bhEne10_MV01(BH_PWORK* epw);
void bhEne10_MV02(BH_PWORK* epw);
void bhEne10_Nage(BH_PWORK* epw);
void bhEne10_Damage();
void bhEne10_Die();

#endif
