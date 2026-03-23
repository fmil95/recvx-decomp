#ifndef _ZONZON1_H_
#define _ZONZON1_H_

#include "types.h"

typedef struct BT_WK 
{
    // total size: 0x3
    unsigned char color;  // offset 0x0, size 0x1
    unsigned char mdlno;  // offset 0x1, size 0x1
    unsigned char tex_id; // offset 0x2, size 0x1
} BT_WK;

typedef struct P_WORK
{
    // total size: 0x8
    int key;   // offset 0x0, size 0x4
    float cnt; // offset 0x4, size 0x4
} P_WORK;

typedef struct COMBJOINT_WORK 
{
    // total size: 0x8
    int flg;     // offset 0x0, size 0x4
    int correct; // offset 0x4, size 0x4
} COMBJOINT_WORK;

typedef struct COMBWEP_WORK 
{
    // total size: 0x18
    int crit;    // offset 0x0, size 0x4
    int pt[3];   // offset 0x4, size 0xC
    int timeout; // offset 0x10, size 0x4
    int bonus;   // offset 0x14, size 0x4
} COMBWEP_WORK;

void bhEne_SetMinceEffect(BH_PWORK* epw, int type, int num);
void bhEne_SetMinceEffect2(BH_PWORK* epw, int type, float size, int num);
void bhEne_SetBloodEffect(BH_PWORK* epw, int type);
void bhEne_SetBloodEffect2(BH_PWORK* epw, int type, int jno, NJS_POINT3* ofp);
void bhEne_SetBloodEffect4(NJS_POINT3* pos, NJS_POINT3* vec, int col, int type1, int type2);
void bhEne_SetBloodEffect5(BH_PWORK* epw, int type1, int type2);
void bhEne_SetBloodEffectBurst(BH_PWORK* epw, int type, int jno, NJS_POINT3* pos, int flg);
void bhEne_SetBloodstain(BH_PWORK* epw, int type, int jno, NJS_POINT3* ofp);
void bhEne_SetFireEffect(BH_PWORK* epw, int jno, NJS_POINT3* ofp, float size, int len);
void bhEne_BloodPool(BH_PWORK* epw, NJS_POINT3* pos, int ang, BP_WORK* param);
void bhEne_SetAcidEffect(BH_PWORK* epw, int jno, NJS_POINT3* ofp, float size);
int bhEne_DirTarget(BH_PWORK* epw, float x, float z, int w);
int bhEne_CheckDirTarget(BH_PWORK* epw, float x, float z, int w);
void bhEne_GetPartsPos(BH_PWORK* epw, char* parts, NJS_POINT3* p);
int bhEne_DirCheck(int ay, NJS_VECTOR* vec);
int bhEne_DGDirCheck(BH_PWORK* epw);
void bhEne_CallPlayerVoice(int no);
void bhEne_CheckEnemiesBall(BH_PWORK* epw);
void bhEne_SetWeponAtr(BH_PWORK* epw, char j1, char j2, float r);
unsigned char bhEne_AttackHitCheck(BH_PWORK* pl, NJS_POINT3* pos, float ar);
void bhEne_AddNullTrans(BH_PWORK* epw, NJS_VECTOR* mtn);
void bhEne_AddNullTransDir(BH_PWORK* epw, int ay, NJS_POINT3* mtn);
float bhEne_GetShapeCnt(P_WORK* p, int key);
void bhEne_CalcDamage(BH_PWORK* epw, COMBWEP_WORK* CombWepTbl, COMBJOINT_WORK* CombJointTbl);
void bhEne_InitDamage(BH_PWORK* epw);
void bhEne_CallSE(BH_PWORK* epw, NJS_POINT3* pos, int se);
void bhEne_CallSE_EX(BH_PWORK* epw, NJS_POINT3* pos, int se, int fade);
void bhEne_CallEffectSE(NJS_POINT3* pos, int se);
void bhEne_SetSEPan(int param, NJS_POINT3* pos, int se); // first parameter is not present on DWARF
int bhEne_CheckPlayEffectSE(int se);
int bhArcTan2(float y, float x);
ATR_WORK* bhEne_CheckEventAtr(int flr_no, float px, float pz, int id, int min, int max);
void bhEne_EraseArrow(BH_PWORK* epw, int obj_no);

#endif
