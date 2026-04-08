#ifndef _EN06_H_
#define _EN06_H_

#include "types.h"

void bhEne06(BH_PWORK* epw);
void bhEne06_Init(BH_PWORK* epw);
void bhEne06_Brain(BH_PWORK* epw);
void bhEne06_BR00(BH_PWORK* epw);
void bhEne06_Move(BH_PWORK* epw);
void bhEne06_MV00(BH_PWORK* epw);
void bhEne06_MV01(BH_PWORK* epw);
void bhEne06_MV02(BH_PWORK* epw);
void bhEne06_MV03(BH_PWORK* epw);
void bhEne06_MV04();
void bhEne06_MV05(BH_PWORK* epw);
void bhEne06_MV06();
void bhEne06_MV07();
void bhEne06_MV08(BH_PWORK* epw);
void bhEne06_MV09(BH_PWORK* epw);
void bhEne06_MV10(BH_PWORK* epw);
void bhEne06_Nage(BH_PWORK* epw);
void bhEne06_NG00(BH_PWORK* epw);
void bhEne06_Damage(BH_PWORK* epw);
void bhEne06_DG00(BH_PWORK* epw);
void bhEne06_DG01(BH_PWORK* epw);
void bhEne06_Die(BH_PWORK* epw);
void bhEne06_DD00(BH_PWORK* epw);
void bhEne06_DD01(BH_PWORK* epw);
void bhEne06_DD02(BH_PWORK* epw);
void bhEne06_DD03(BH_PWORK* epw);
void bhEne06_DD04(BH_PWORK* epw);
void bhEne06_SearchPlayer(BH_PWORK* epw);
void bhEne06_CollisionWalls(BH_PWORK* epw);
void bhEne06_FloorCollision(BH_PWORK* epw);
int bhEne06_CheckLeaningWall(BH_PWORK* epw);
int bhEne06_AvoidWall(BH_PWORK* epw, int dir);
void bhEne06_PlayerControl(BH_PWORK* epw);
void bhEne06_SetRinpunEffect(BH_PWORK* epw, int num, int flg);
void bhEne06_HitMark(BH_PWORK* epw);
int bhEne06_DeadCheck(BH_PWORK* epw);

#endif
