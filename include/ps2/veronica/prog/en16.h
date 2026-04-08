#ifndef _EN16_H_
#define _EN16_H_

#include "types.h"

void bhEne16(BH_PWORK* epw);
void bhEne16_Init(BH_PWORK* epw);
void bhEne16_Brain(BH_PWORK* epw);
void bhEne16_BR00(BH_PWORK* epw);
void bhEne16_Move(BH_PWORK* epw);
void bhEne16_MV00(BH_PWORK* epw);
void bhEne16_MV01(BH_PWORK* epw);
void bhEne16_MV02(BH_PWORK* epw);
int bhEne16_GetEffNum(BH_PWORK* epw);
/*_anon14* bhEne16_GetEffPos(BH_PWORK* epw);
void bhEne16_AddEffPos(BH_PWORK* epw, _anon14* pos);*/

#endif
