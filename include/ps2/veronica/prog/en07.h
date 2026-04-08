#ifndef _EN07_H_
#define _EN07_H_

#include "types.h"

void bhEne07(BH_PWORK* epw);
void bhEne07_Init(BH_PWORK* epw);
void bhEne07_Brain(BH_PWORK* epw);
void bhEne07_BR00(BH_PWORK* epw);
void bhEne07_BR01(BH_PWORK* epw);
void bhEne07_Move(BH_PWORK* epw);
void bhEne07_MV00(BH_PWORK* epw);
void bhEne07_MV01(BH_PWORK* epw);
void bhEne07_MV02(BH_PWORK* epw);
void bhEne07_MV03(BH_PWORK* epw);
void bhEne07_MV04(BH_PWORK* epw);
void bhEne07_MV05(BH_PWORK* epw);
void bhEne07_MV06();
void bhEne07_MV07();
void bhEne07_MV08(BH_PWORK* epw);
void bhEne07_Nage(BH_PWORK* epw);
void bhEne07_NG00(BH_PWORK* epw);
void bhEne07_NG01(BH_PWORK* epw);
void bhEne07_Damage(BH_PWORK* epw);
void bhEne07_Die(BH_PWORK* epw);
void bhEne07_DD00(BH_PWORK* epw);
void bhEne07_DD01(BH_PWORK* epw);
void bhEne07_DD02(BH_PWORK* epw);
void bhEne07_DD03(BH_PWORK* epw);
void bhEne07_DD04(BH_PWORK* epw);
void bhEne07_DD05(BH_PWORK* epw);
void bhEne07_DD06(BH_PWORK* epw);
void bhEne07_SearchPlayer(BH_PWORK* epw);
void bhEne07_CollisionWalls(BH_PWORK* epw);
void bhEne07_FloorCollision(BH_PWORK* epw);
int bhEne07_CheckLeaningWall();
int bhEne07_CheckHangingWall(BH_PWORK* epw);
int bhEne07_AvoidWall(BH_PWORK* epw, int dir);
void bhEne07_PlayerBloodEffect(BH_PWORK* epw, unsigned char size);
void bhEne07_PlayerControl(BH_PWORK* epw);
int bhEne07_ObjEdge(BH_PWORK* epw);
/*void bhEne07_CalcAtariOffset(BH_PWORK* epw, _anon5* ofp);*/

#endif
