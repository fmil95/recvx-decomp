#ifndef _EN25_H_
#define _EN25_H_

#include "types.h"

void bhEne25(BH_PWORK* epw);
void bhEne25_Init(BH_PWORK* epw);
void bhEne25_Brain();
void bhEne25_Move(BH_PWORK* epw);
void bhEne25_MV00(BH_PWORK* epw);
void bhEne25_MV01(BH_PWORK* epw);
void bhEne25_MV02(BH_PWORK* epw);
void bhEne25_MV03(BH_PWORK* epw);
void bhEne25_Nage();
void bhEne25_Damage();
void bhEne25_Die();
void bhEne25_SetEffect(BH_PWORK* epw);
void bhEne25_PlayerControl(BH_PWORK* epw);

#endif
