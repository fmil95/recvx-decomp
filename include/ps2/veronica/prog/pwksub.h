#ifndef _PWKSUB_H_
#define _PWKSUB_H_

#include "types.h"

typedef struct SC_WORK 
{
    // total size: 0x8
    int idx;  // offset 0x0, size 0x4
    float ln; // offset 0x4, size 0x4
} SC_WORK;

unsigned char* bhGetFreeMemory(int size, int param);
void bhCalcLinkModel(BH_PWORK* pp);
void bhSetFloorNum(BH_PWORK* pp);
int bhCheckFloorNum(float py);
void bhAddSpeed(BH_PWORK* pp, int r);
int bhGetFrameNum(unsigned int fnm_old, unsigned int fnm_new, int fno_now);
int bhCalcLockEneYR(BH_PWORK* pp, int idx);
int bhSearchNearEnemy(BH_PWORK* pp, int* r, float* h, int* id);
int bhSearchNearEnemyB(NJS_POINT3* pos, int ay, int ar, float len);
int bhSearchNearEnemy2(BH_PWORK* pp, int* r, float* h, int* id);
int bhSearchNextEnemy(BH_PWORK* pp, int r, float h);
int bhSearchPlayer(BH_PWORK* pp, int r);
int bhCheckL2Wall(NJS_LINE* lp, unsigned int flg, float* len);
int bhCheckC2Wall(NJS_CAPSULE* cap);
int bhCheckC2WallN(NJS_CAPSULE* cap, unsigned int flg);
int bhCheckClipModel(BH_PWORK* pp);
int bhCheckClipPoint(NJS_POINT3* pos);
void bhSetWaterSplash(BH_PWORK* pp, int jno, int type, float sx, float sy, float sz);
void bhSetWaterSplash2(BH_PWORK* pp, NJS_POINT3* pos, int type, float sx, float sy, float sz);
void bhSetWaterSplash3(NJS_POINT3* pos, int ang, int type, float sx, float sy, float sz);
void bhSetWaterSplash4(NJS_POINT3* pos, int ang, int type, float sx, float sy, float sz);
void bhSetGunFire(BH_PWORK* pp, int wno, int jno, int hand, int ang);
void bhSetYakkyou(BH_PWORK* pp, int wno, int jno, int hand, int ang);
void bhSetMagazine(BH_PWORK* pp, int wno, int jno, int hand, int ang);
void bhSetLighterFire(O_WRK* op, int flg);

#endif
