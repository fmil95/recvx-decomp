#ifndef _EN24_H_
#define _EN24_H_

#include "types.h"

void bhEne24(BH_PWORK* epw);
void bhEne24_Init(BH_PWORK* epw);
void bhEne24_Brain(BH_PWORK* epw);
void bhEne24_BR00(BH_PWORK* epw);
void bhEne24_Move(BH_PWORK* epw);
void bhEne24_MV00();
void bhEne24_MV01(BH_PWORK* epw);
void bhEne24_MV02(BH_PWORK* epw);
void bhEne24_MV03(BH_PWORK* epw);
void bhEne24_MV04(BH_PWORK* epw);
void bhEne24_MV05(BH_PWORK* epw);
void bhEne24_Nage();
void bhEne24_Damage();
void bhEne24_Die();
void bhEne24_Dummy();
void bhEne24_CollisionWalls(BH_PWORK* epw);
void bhEne24_CollisionLine(BH_PWORK* epw);
int bhEne24_DeadCheck(BH_PWORK* epw);

#endif
