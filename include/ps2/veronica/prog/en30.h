#ifndef _EN30_H_
#define _EN30_H_

#include "types.h"

void bhEne30(BH_PWORK* epw);
void bhEne30_Init(BH_PWORK* epw);
void bhEne30_Brain(BH_PWORK* epw);
void bhEne30_BR00(BH_PWORK* epw);
void bhEne30_Move(BH_PWORK* epw);
void bhEne30_MV00();
void bhEne30_MV01(BH_PWORK* epw);
void bhEne30_MV02(BH_PWORK* epw);
void bhEne30_MV03(BH_PWORK* epw);
void bhEne30_MV04(BH_PWORK* epw);
void bhEne30_MV05(BH_PWORK* epw);
void bhEne30_MV06(BH_PWORK* epw);
void bhEne30_MV07(BH_PWORK* epw);
void bhEne30_Nage();
void bhEne30_Damage(BH_PWORK* epw);
void bhEne30_DG00(BH_PWORK* epw);
void bhEne30_DG01(BH_PWORK* epw);
void bhEne30_Die(BH_PWORK* epw);
void bhEne30_DD00(BH_PWORK* epw);
void bhEne30_DD01(BH_PWORK* epw);
void bhEne30_CheckEnemies(BH_PWORK* epw);
void bhEne30_DamageInit(BH_PWORK* epw);
void bhEne30_CollisionLine(BH_PWORK* epw);
/*void bhEne30_SetFluidEffect(_anon3* pos, _anon3* vec, int type, float size);*/

#endif
