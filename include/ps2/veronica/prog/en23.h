#ifndef _EN23_H_
#define _EN23_H_

#include "types.h"

void bhEne23(BH_PWORK* epw);
void bhEne23_Init(BH_PWORK* epw);
void bhEne23_Brain(BH_PWORK* epw);
void bhEne23_BR00(BH_PWORK* epw);
void bhEne23_BR01(BH_PWORK* epw);
void bhEne23_Move(BH_PWORK* epw);
void bhEne23_MV00(BH_PWORK* epw);
void bhEne23_MV01(BH_PWORK* epw);
void bhEne23_MV02(BH_PWORK* epw);
void bhEne23_MV03(BH_PWORK* epw);
void bhEne23_MV04();
void bhEne23_MV05(BH_PWORK* epw);
void bhEne23_MV06(BH_PWORK* epw);
void bhEne23_MV07();
void bhEne23_MV08();
void bhEne23_MV09(BH_PWORK* epw);
void bhEne23_MV10(BH_PWORK* epw);
void bhEne23_MV11(BH_PWORK* epw);
void bhEne23_MV12(BH_PWORK* epw);
void bhEne23_Nage(BH_PWORK* epw);
void bhEne23_NG00();
void bhEne23_Damage(BH_PWORK* epw);
void bhEne23_DG00();
void bhEne23_DG01(BH_PWORK* epw);
void bhEne23_DG02();
void bhEne23_DG03(BH_PWORK* epw);
void bhEne23_DG04(BH_PWORK* epw);
void bhEne23_DG05();
void bhEne23_DG06(BH_PWORK* epw);
void bhEne23_DG07(BH_PWORK* epw);
void bhEne23_Die(BH_PWORK* epw);
void bhEne23_DD00(BH_PWORK* epw);
void bhEne23_DD01(BH_PWORK* epw);
void bhEne23_DD02();
void bhEne23_DD03(BH_PWORK* epw);
void bhEne23_CollisionWalls(BH_PWORK* epw);
void bhEne23_CollisionLine(BH_PWORK* epw);
int bhEne23_CheckClimbWall(BH_PWORK* epw, int flg);
int bhEne23_CheckDiving(BH_PWORK* epw);
void bhEne23_DamageInit(BH_PWORK* epw);
void bhEne23_LegBreak(BH_PWORK* epw);
void bhEne23_InitChild(BH_PWORK* epw);
void bhEne23_PlayerControl(BH_PWORK* epw);
void bhEne23_Acid(BH_PWORK* epw);
unsigned int bhEne23_SearchPlayer(BH_PWORK* epw, int ang);
void bhEne23_Shape(BH_PWORK* epw);
void bhEne23_CallSE(BH_PWORK* epw);
void bhEne23_HitMark(BH_PWORK* epw);

#endif
