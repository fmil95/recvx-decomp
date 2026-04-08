#ifndef _EN14_H_
#define _EN14_H_

#include "types.h"

void bhEne14(BH_PWORK* epw);
void bhEne14_Init(BH_PWORK* epw);
void bhEne14_Brain(BH_PWORK* epw);
void bhEne14_BR00();
void bhEne14_BR01();
void bhEne14_Move(BH_PWORK* epw);
void bhEne14_MV00(BH_PWORK* epw);
void bhEne14_MV01(BH_PWORK* epw);
void bhEne14_MV02(BH_PWORK* epw);
void bhEne14_MV03();
void bhEne14_MV04(BH_PWORK* epw);
void bhEne14_MV05();
void bhEne14_MV06();
void bhEne14_MV07();
void bhEne14_MV08();
void bhEne14_MV09();
void bhEne14_MV10();
void bhEne14_MV11(BH_PWORK* epw);
void bhEne14_Nage(BH_PWORK* epw);
void bhEne14_NG00();
void bhEne14_Damage(BH_PWORK* epw);
void bhEne14_DG00(BH_PWORK* epw);
void bhEne14_DG01(BH_PWORK* epw);
void bhEne14_Die();
void bhEne14_InitDamage(BH_PWORK* epw);
void bhEne14_LookPlayaer(BH_PWORK* epw);
void bhEne14_TailInit(BH_PWORK* epw);
void bhEne14_TailSwing(BH_PWORK* epw);
int bhEne14_HitMark(BH_PWORK* epw);
void bhEne14_Acid(BH_PWORK* epw, int se);
void bhEne14_SetMotion(BH_PWORK* epw);
void bhEne14_CheckWall(BH_PWORK* epw);
void bhEne14_PlayerControl(BH_PWORK* epw);
void bhEne14_CallSE(BH_PWORK* epw);

#endif
