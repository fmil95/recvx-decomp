#ifndef _EN13SUB_H_
#define _EN13SUB_H_

#include "types.h"
#include "macros.h"

void bhEne13B(BH_PWORK* epw);
void bhEne13B_Init(BH_PWORK* epw);
void bhEne13B_Move(BH_PWORK* epw);
void bhEne13B_MV00();
void bhEne13B_MV01(BH_PWORK* epw);
void bhEne13B_Nage();
void bhEne13B_Damage();
void bhEne13B_Die(BH_PWORK* epw);
void bhEne13B_SetHittab(BH_PWORK* epw);

#endif
