#ifndef _MOTION_H_
#define _MOTION_H_

#include "types.h"

typedef struct NJS_MKEY_A_MOD 
{
    // total size: 0x6
    unsigned short key[3]; // offset 0x0, size 0x6
} NJS_MKEY_A_MOD;

typedef struct NJS_MKEY_F_MOD
{
    // total size: 0xC
    float key[3]; // offset 0x0, size 0xC
} NJS_MKEY_F_MOD;

int bhSetMotion(BH_PWORK* ewP, int add, int mode, void* datP);
static void SetMtnNormal(BH_PWORK* ewP, char* datP, int mode);
static void SetMtnNormalHokan(BH_PWORK* ewP, char* datP, int mode, float rate);
static void SetMtnFast(BH_PWORK* ewP, char* datP, int mode);
static void SetMtnFastHokan(BH_PWORK* ewP, char* datP, int mode, float rate);
static void SetMtnSlow(BH_PWORK* ewP, char* datP, int mode);
static void SetMtnSlowHokan(BH_PWORK* ewP, char* datP, int mode, float rate);
void bhFixPosition(BH_PWORK* ewP, char* datP);
void bhCalcFixOffset(BH_PWORK* ewP, char* datP, NJS_POINT3* offP, NJS_POINT3* rtnP);
void bhGetObjMotion(BH_PWORK* ewP, int obj_no, float* pos, int* ang);
void AngZyxToYzx(int* zyx, int* yzx);
void AngYzxToZyx(int* yzx, int* zyx);

#endif
