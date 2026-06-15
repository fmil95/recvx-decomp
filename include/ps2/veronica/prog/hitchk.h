#ifndef _HITCHK_H_
#define _HITCHK_H_

#include "types.h"
#include "macros.h"

void bhCheckWall(BH_PWORK* pw);
int bhCheckWallEx(BH_PWORK* pw, NJS_POINT3* npos, NJS_POINT3* opos, float par, float pah);
void bhCheckWall2Box(BH_PWORK* pw);
ATR_WORK* bhCheckWallType(NJS_POINT3* pos, unsigned int flg, float ar, float ah);
ATR_WORK* bhCheckWallType2(NJS_POINT3* pos, unsigned int flg, float aw, float ad, float ah, int idx_ct);
ATR_WORK* bhCheckWallRefAngle(NJS_POINT3* pos, unsigned int flg, float ar, float ah, int* ay);
void bhSetWallRefAngle(ATR_WORK* hp, NJS_POINT3* pos, float ar, float ah, int* ay);
float bhGetGroundPosition(NJS_POINT3* pos); 
int bhCheckInnerTriangle(ATR_WORK* hp, NJS_POINT3* pos, float ar, float ah);
int bhCheckInnerTriangle2(ATR_WORK* hp, NJS_POINT3* pos, float aw, float ad, float ah);
int bhCheckInnerTriangle3(ATR_WORK* hp, NJS_POINT3* pos);
int bhCheckBox(ATR_WORK* hp, NJS_POINT3* pos, float ar, float ah, unsigned int aflg);
int bhCheckBox2Box(ATR_WORK* hp, NJS_POINT3* pos, float aw, float ad, float ah);
int bhCheckInnerP4(NJS_POINT2* pos, NJS_POINT2* p0, NJS_POINT2* p1, NJS_POINT2* p2, NJS_POINT2* p3);
void bhCheckExmAtari(BH_PWORK* pp);
void bhSetUseKaidanFlag(BH_PWORK* pp, ATR_WORK* exp, int idx);
void bhClrUseKaidanFlag(BH_PWORK* pp);
void bhSetDansaLimitAtari(BH_PWORK* pp);
ATR_WORK* bhCheckDansaAtari(int flr_no, float px, float pz);
void bhCheckFloorP(BH_PWORK* pp);
void bhCheckDansa(BH_PWORK* pp);
int bhCheckFloorSound(BH_PWORK* pp, int flr_no, float px, float pz);
ATR_WORK* bhCheckFloorEnemy(int flr_no, float px, float pz);
ATR_WORK* bhCheckFloorEffect(int flr_no, float px, float pz);
ATR_WORK* bhCheckWater(NJS_POINT3* pos);
ATR_WORK* bhCheckL2Water(NJS_LINE* lp, NJS_POINT3* pos);
void bhResetAtariAttr();
void bhCheckPlayer(BH_PWORK* pp);
void bhCheckEnemies(BH_PWORK* pp);
int bhCheckWallAttrB89(ATR_WORK* hp);

#endif
