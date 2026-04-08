#ifndef _EN55_H_
#define _EN55_H_

#include "types.h"

void bhEne55(BH_PWORK* epw);
void bhEne55_MainLoop(BH_PWORK* epw);
int bhEne55_SetMtn(BH_PWORK* epw);
void bhEne55_CollCheck(BH_PWORK* epw);
void bhEne55_CalcEnemy(BH_PWORK* epw);
void bhEne55_Init(BH_PWORK* epw);
void bhEne55_Move(BH_PWORK* epw);
void bhEne55_Damage(BH_PWORK* epw);
void bhEne55_MVType00(BH_PWORK* epw);
void bhEne55_MV00(BH_PWORK* epw);
void bhEne55_DGType00(BH_PWORK* epw);
void bhEne55_DG00(BH_PWORK* epw);

#endif
