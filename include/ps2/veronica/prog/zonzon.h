#ifndef _ZONZON_H_
#define _ZONZON_H_

#include "types.h"

typedef struct WORK 
{
    // total size: 0x8
    float wk; // offset 0x0, size 0x4
    int indx; // offset 0x4, size 0x4
} WORK; 

typedef struct BT_WORK 
{
    // total size: 0x20
    int lnk_obj; // offset 0x0, size 0x4
    float x;     // offset 0x4, size 0x4
    float y;     // offset 0x8, size 0x4
    float z;     // offset 0xC, size 0x4
    float xlen;  // offset 0x10, size 0x4
    float ylen;  // offset 0x14, size 0x4
    float size;  // offset 0x18, size 0x4
    float len;   // offset 0x1C, size 0x4
} BT_WORK;

typedef struct BT_WRK 
{
    // total size: 0x1C
    NJS_POINT3 ofs; // offset 0x0, size 0xC
    int angX;       // offset 0xC, size 0x4
    int angY;       // offset 0x10, size 0x4
    int type;       // offset 0x14, size 0x4
    int wcnt;       // offset 0x18, size 0x4
} BT_WRK;

void ikou(BH_PWORK* epw, NJS_POINT3* pos, int add_dir);
int ikou3(BH_PWORK* epw, NJS_POINT3* pos, int add_dir);
int NitenDir_ck(float hontai_x, float hontai_z, float target_x, float target_z);
int bhCdirCheck(int my_ang, int trg_ang);
int bhEne_LeverCheck();
int bhDGCdirCheck(NJS_VECTOR* dv, int rot);
int bhDGCdirCheck2(NJS_VECTOR* dv, O_WORK* owk);
int bhDGCdirCheck3(NJS_VECTOR* dv, int rot);
int bhEne_AngleCheck(NJS_VECTOR* vec, int rot, int chk_ang);
void bhEne_GetTranslateMtn(BH_PWORK* epw, int frm, int mode);
void bhEne_GetTranslateMtn2(BH_PWORK* epw, int frm, int mode);
void bhEne_CalcPartsPos(BH_PWORK* epw, NJS_MATRIX* mtx, NJS_POINT3* pos, char* tree, int parts_num, int clr_flg);
ATR_WORK* bhKaidanAtrCheck(BH_PWORK* epw, float len, int* idx);
ATR_WORK* bhEne_EnemyAtariCheck(NJS_POINT3* pos, int flr_no, unsigned char id, unsigned char type);
int bhEne_PosCheck(float px, float pz, float x, float z, float w, float h);
void bhEne_SetBlood(BH_PWORK* epw, unsigned char type, BT_WORK* bt);
void bhEne_SetBlood2(BH_PWORK* epw, unsigned char type, NJS_POINT3* ofp, short ry);
void bhEne_SetBlood3(BH_PWORK* epw, int lnk_obj, NJS_POINT3* ofs, NJS_POINT3* dv, int n, int tex_id, int type, int wcnt);
void bhEne_SetBlood4(BH_PWORK* epw, int lnk_obj, NJS_POINT3* ofs, int tex_id, int type);
void bhEne_SetNikuhenEffect(BH_PWORK* epw, int type, NJS_POINT3* pos, NJS_POINT3* v, int tex_id);
void bhEne_SetNikuhenEffect2(BH_PWORK* epw, int type, NJS_POINT3* pos, int n, int tex_id);
int bhEne_SetDFireEffect(BH_PWORK* epw, int no, BT_WORK* ltbl, int type);
void bhEne_SetDFireEffect2(BH_PWORK* epw, int no, BT_WORK* ltbl, int type);
int bhEne_SetSanEffect(BH_PWORK* epw, int no, BT_WORK* ltbl);
int bhEne_SetSanEffect2(BH_PWORK* epw, int no, BT_WORK* ltbl);
void bhEne_QuickSort(WORK* a, int first, int last);
int bhEne_ChgMtn(BH_PWORK* epw, unsigned int no, int frm, int rate);
int bhEne_CollisionCheckWall(BH_PWORK* pw, NJS_POINT3* ps, NJS_POINT3* pd, float ar, float ah);
ATR_WORK* bhEne_CollisionCheckWall2(BH_PWORK* pw, NJS_POINT3* ps, NJS_POINT3* ops, NJS_POINT3* pd, float ar, float ah);
ATR_WORK* bhEne_CheckDirWall(BH_PWORK* epw, int ang, float step);
ATR_WORK* bhEne_CheckDirWall2(BH_PWORK* epw, int ang, float step);
ATR_WORK* bhEne_CheckDirWall3(BH_PWORK* epw, NJS_POINT3* pos, int ang, float step);
int bhEne_CheckSideWall(BH_PWORK* epw, float step, int both);
int bhEne_CheckSideWall2(BH_PWORK* epw, float step, int both);
int bhEne_CheckSideWall3(BH_PWORK* epw, NJS_POINT3* pos, float step, int both);
void bhEne_SetVibration(int no);
void bhEne_PlayerSePlay(BH_PWORK* epw, int no);
void bhEne_HitCheckParts(BH_PWORK* pp, NJS_POINT3* pos);

#endif
