#ifndef _EN54_H_
#define _EN54_H_

#include "types.h"

void bhEne54(BH_PWORK* epw);
void bhEne54_MainLoop(BH_PWORK* epw);
int bhEne54_SetMtn(BH_PWORK* epw);
void bhEne54_CollCheck(BH_PWORK* epw);
void bhEne54_CalcEnemy(BH_PWORK* epw);
void bhEne54_Init(BH_PWORK* epw);
void bhEne54_Move(BH_PWORK* epw);
void bhEne54_Damage(BH_PWORK* epw);
void bhEne54_MVType00(BH_PWORK* epw);
void bhEne54_MV00(BH_PWORK* epw);
void bhEne54_DGType00(BH_PWORK* epw);
void bhEne54_DG00(BH_PWORK* epw);

#endif
