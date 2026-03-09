#ifndef _EN18_H_
#define _EN18_H_

#include "types.h"

void bhEne18(BH_PWORK* epw);
void bhEne18_Init(BH_PWORK* epw);
void bhEne18_Move(BH_PWORK* epw);
void bhEne18_MV00(BH_PWORK* epw);
void bhEne18_MV01(BH_PWORK* epw);
void bhEne18_MV02(BH_PWORK* epw);
void bhEne18_MV03();
void bhEne18_MV04(BH_PWORK* epw);
void bhEne18_MV05(BH_PWORK* epw);
void bhEne18_Nage();
void bhEne18_Damage();
void bhEne18_Die(BH_PWORK* epw);
int bhEne18_HitMark(BH_PWORK* epw);

#endif
