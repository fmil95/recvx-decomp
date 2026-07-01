#ifndef _EN06SUB_H_
#define _EN06SUB_H_

#include "types.h"
#include "macros.h"

void bhEne06s(BH_PWORK* epw);
void bhEne06s_Init(BH_PWORK* epw);
void bhEne06s_Move(BH_PWORK* epw);
void bhEne06s_MV00(BH_PWORK* epw);
void bhEne06s_MV01(BH_PWORK* epw);
void bhEne06s_Dummy();
void bhEne06s_FloorCollision(BH_PWORK* epw);
void bhEne06s_WallCheck(BH_PWORK* epw);

#endif
