#ifndef _EN12_H_
#define _EN12_H_

#include "types.h"

void bhEne12(BH_PWORK* epw);
void bhEne12_Init(BH_PWORK* epw);
void bhEne12_Brain(BH_PWORK* epw);
void bhEne12_BR00(BH_PWORK* epw);
void bhEne12_Move(BH_PWORK* epw);
void bhEne12_MV00(BH_PWORK* epw);
void bhEne12_MV01(BH_PWORK* epw);
void bhEne12_MV02(BH_PWORK* epw);
void bhEne12_MV03(BH_PWORK* epw);
void bhEne12_MV04(BH_PWORK* epw);
void bhEne12_MV05();
void bhEne12_MV06(BH_PWORK* epw);
void bhEne12_MV07(BH_PWORK* epw);
void bhEne12_Nage(BH_PWORK* epw);
void bhEne12_NG00(BH_PWORK* epw);
void bhEne12_Damage(BH_PWORK* epw);
void bhEne12_DG00(BH_PWORK* epw);
void bhEne12_Die(BH_PWORK* epw);
void bhEne12_DD00(BH_PWORK* epw);
void bhEne12_InitDamage(BH_PWORK* epw);
void bhEne12_LookPlayaer(BH_PWORK* epw);
void bhEne12_HitMark(BH_PWORK* epw);
void bhEne12_FixedLegPos(BH_PWORK* epw);
void bhEne12_PlayerControl(BH_PWORK* epw);
/*void bhEne12_FlameLiquid(BH_PWORK* epw, _anon25* pos, int time);*/
void bhEne12_Acid(BH_PWORK* epw);
void bhEne12_CheckWall(BH_PWORK* epw);
void bhEne12_Blood(BH_PWORK* epw, int num);
int bhEne12_AvoidWall(BH_PWORK* epw);
void bhEne12_CallSE(BH_PWORK* epw);
void bhEne12_CallFootSE(BH_PWORK* epw, int flg);
void bhEne12_SetFireBintaEffect(BH_PWORK* epw, int act);

#endif
