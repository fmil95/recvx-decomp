#ifndef _EN27_H_
#define _EN27_H_

#include "types.h"

void bhEne27(BH_PWORK* epw);
void bhEne27_Init(BH_PWORK* epw);
void bhEne27_Brain(BH_PWORK* epw);
void bhEne27_BR00(BH_PWORK* epw);
void bhEne27_Move(BH_PWORK* epw);
void bhEne27_MV00();
void bhEne27_MV01(BH_PWORK* epw);
void bhEne27_MV02(BH_PWORK* epw);
void bhEne27_Nage();
void bhEne27_Damage();
void bhEne27_Die();
void bhEne27_IncubateEffect(BH_PWORK* epw);
void bhEne27_CallSE(BH_PWORK* epw);

#endif
