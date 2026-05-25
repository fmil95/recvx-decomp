#ifndef _PLAYPCH_H_
#define _PLAYPCH_H_

#include "types.h"
#include "macros.h"

typedef struct _search
{
    // total size: 0x14
    struct _search* nextP; // offset 0x0, size 0x4
    BH_PWORK* ewP;         // offset 0x4, size 0x4
    int idx;               // offset 0x8, size 0x4
    float dst;             // offset 0xC, size 0x4
    int dir;               // offset 0x10, size 0x4
} search;

typedef struct PP_WORK 
{
    // total size: 0x6B0
    int mode;             // offset 0x0, size 0x4
    int count;            // offset 0x4, size 0x4
    int gun_delay;        // offset 0x8, size 0x4
    NJS_CNK_OBJECT obj_r; // offset 0xC, size 0x34
    NJS_CNK_OBJECT obj_l; // offset 0x40, size 0x34
    int ang_tmp[3];       // offset 0x74, size 0xC
    int arm_dl;           // offset 0x80, size 0x4
    int arm_dr;           // offset 0x84, size 0x4
    int arm_al;           // offset 0x88, size 0x4
    int arm_ar;           // offset 0x8C, size 0x4
    BH_PWORK** endPP;     // offset 0x90, size 0x4
    BH_PWORK* LckTbl[64]; // offset 0x94, size 0x100
    search sch_hed;       // offset 0x194, size 0x14
    search SchLst[64];    // offset 0x1A8, size 0x500
    int hed_rate;         // offset 0x6A8, size 0x4
} PP_WORK;

void PlyPchInit(BH_PWORK* ewP);
void PlyPchMain(BH_PWORK* ewP);
/*void MixSetToJointRot(npobj* basP, char* rutP, npobj* objP, int yaw);*/
void GetOneObjectMotion(BH_PWORK* ewP, int obj_no, int* ang);
/*void SetOneObjectMotion(BH_PWORK* ewP, npobj* objP, int* ang);
_search* bhSearchEnemy(BH_PWORK* pwP, int rng, float hgt);*/
int SetLockOnDirection(int range, int count, int mode, int special);
void bhCPM2_act_suw_pch();
void bhCPM2_act_wsc_pch();
void bhCPM2_act_atk_pch();
/*_anon14* CheckGunHit(_anon1* wtP, int obj_no, int yaw);*/
void bhCPM2_SearchPch();
/*void bhArmIkMdk(BH_PWORK* ewP, int bas_no, _anon27* effP, int rot);*/

#endif
