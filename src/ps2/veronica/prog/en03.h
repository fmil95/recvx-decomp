#ifndef _EN03_H_
#define _EN03_H_

#include "types.h"

void bhEne03(BH_PWORK* epw);
void bhEne03_Init(BH_PWORK* epw);
void bhEne03_Brain(BH_PWORK* epw);
void bhEne03_BR00(BH_PWORK* epw);
void bhEne03_BR01(BH_PWORK* epw);
void bhEne03_BR02(BH_PWORK* epw);
void bhEne03_Move(BH_PWORK* epw);
void bhEne03_MV00(BH_PWORK* epw);
void bhEne03_MV01(BH_PWORK* epw);
void bhEne03_MV02(BH_PWORK* epw);
void bhEne03_MV03(BH_PWORK* epw);
void bhEne03_MV04(BH_PWORK* epw);
void bhEne03_MV05(BH_PWORK* epw);
void bhEne03_MV06(BH_PWORK* epw);
void bhEne03_MV07(BH_PWORK* epw);
void bhEne03_MV08(BH_PWORK* epw);
void bhEne03_MV09(BH_PWORK* epw);
void bhEne03_MV10(BH_PWORK* epw);
void bhEne03_MV11(BH_PWORK* epw);
void bhEne03_MV12();
void bhEne03_MV13();
void bhEne03_MV14(BH_PWORK* epw);
void bhEne03_MV15(BH_PWORK* epw);
void bhEne03_MV16(BH_PWORK* epw);
void bhEne03_MV17(BH_PWORK* epw);
void bhEne03_MV18(BH_PWORK* epw);
void bhEne03_MV19(BH_PWORK* epw);
void bhEne03_Nage(BH_PWORK* epw);
void bhEne03_NG00(BH_PWORK* epw);
void bhEne03_NG01(BH_PWORK* epw);
void bhEne03_Damage(BH_PWORK* epw);
void bhEne03_DG00();
void bhEne03_DG01(BH_PWORK* epw);
void bhEne03_DG02(BH_PWORK* epw);
void bhEne03_DG03(BH_PWORK* epw);
void bhEne03_DG04(BH_PWORK* epw);
void bhEne03_DG05();
void bhEne03_DG06(BH_PWORK* epw);
void bhEne03_DG07(BH_PWORK* epw);
void bhEne03_DG08(BH_PWORK* epw);
void bhEne03_DG09(BH_PWORK* epw);
void bhEne03_DG10(BH_PWORK* epw);
void bhEne03_DG11(BH_PWORK* epw);
void bhEne03_DG12(BH_PWORK* epw);
void bhEne03_Die(BH_PWORK* epw);
void bhEne03_DD00(BH_PWORK* epw);
void bhEne03_DD01(BH_PWORK* epw);
void bhEne03_DD02(BH_PWORK* epw);
void bhEne03_DD03(BH_PWORK* epw);
void bhEne03_DD04(BH_PWORK* epw);
void bhEne03_DD05(BH_PWORK* epw);
int bhEne03_DGDirCheck(BH_PWORK* epw);
void bhEne03_SearchPlayer(BH_PWORK* epw, int ang);
/*int bhEne03_DirTarget(BH_PWORK* epw, _anon21* pos, int w);*/
void bhEne03_GoAHead(BH_PWORK* epw);
/*void bhEne03_GetPartsPos(BH_PWORK* epw, char* parts, _anon21* p);*/
void bhEne03_MakeMatrix(BH_PWORK* epw);
/*void bhEne03_HidePartsSub0(npobj* p);
void bhEne03_HidePartsSub1(npobj* p);*/
void bhEne03_HideParts(BH_PWORK* epw, unsigned short PartsNo, unsigned short flg);
int bhEne03_CollisionWalls(BH_PWORK* epw);
/*_anon0* bhEne03_GetWall(BH_PWORK* epw);
_anon0* bhEne03_Collision(BH_PWORK* epw);
_anon0* bhEne03_Collision2(BH_PWORK* epw, _anon0* gnd);
int bhEne03_CollisionWallBox(_anon0* hp, _anon21* pos, float ar);
int bhEne03_CollisionWallGround(_anon0* hp, _anon21* pos, float ar);
int bhEne03_CollisionWallCylinder(_anon0* hp, _anon21* pos, float ar);
int bhEne03_CollisionWallSlope(_anon0* hp, _anon21* pos, float ar);
int bhEne03_CollisionWallTriangle(_anon0* hp, _anon21* pos, float ar);
int bhEne03_CollisionBoxEdge(_anon0* hp, _anon21* pos, float ar);*/
int bhEne03_CollisionBoxEdge2(BH_PWORK* epw);
void bhEne03_CollisionLine(BH_PWORK* epw);
void bhEne03_CollisionLine2(BH_PWORK* epw);
void bhEne03_SetModelFlg(BH_PWORK* epw, unsigned int and_flg, unsigned int or_flg);
/*void bhEne03_AddNullTrans(BH_PWORK* epw, _anon21* mtn);*/
int bhEne03_CheckClimbWall();
int bhEne03_CheckClimbDownWall();
int bhEne03_AvoidWall();
int bhEne03_DiveSpace(BH_PWORK* epw);
/*int bhEne03_GetWallDir(_anon21* v);*/
void bhEne03_DamageInit(BH_PWORK* epw);
int bhEne03_CheckJumpSpace(BH_PWORK* epw);
void bhEne03_PlayerControl(BH_PWORK* epw);
void bhEne03_CallSE(BH_PWORK* epw);
void bhEne03_Acid(BH_PWORK* epw, int type);
void bhEne03_HitMark(BH_PWORK* epw);

#endif
