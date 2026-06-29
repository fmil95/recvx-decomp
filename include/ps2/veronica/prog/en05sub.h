#ifndef _EN05SUB_H_
#define _EN05SUB_H_

#include "types.h"
#include "macros.h"

void bhEne05s(BH_PWORK* epw);
void bhEne05s_Init(BH_PWORK* epw);
void bhEne05s_Move(BH_PWORK* epw);
void bhEne05s_MV00();
void bhEne05s_MV01(BH_PWORK* epw);
void bhEne05s_MV02(BH_PWORK* epw);
void bhEne05s_FloorCollision(BH_PWORK* epw);

#endif
