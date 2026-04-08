#ifndef _NJPLUS_H_
#define _NJPLUS_H_

#include "types.h"

typedef struct MDLSTR2
{
    // total size: 0x14
    float pos[3]; // offset 0x0, size 0xC
    int* vlist;   // offset 0xC, size 0x4
    short* plist; // offset 0x10, size 0x4
} MDLSTR2;

typedef struct NP_WORK
{
    // total size: 0x2F20
	int* sknp;                 // offset 0x0, size 0x4
    int obj_now;               // offset 0x4, size 0x4
    int obj_cnt;               // offset 0x8, size 0x4
    unsigned char* buff;       // offset 0xC, size 0x4
    unsigned char* bp;         // offset 0x10, size 0x4
    int* vlist[128];           // offset 0x14, size 0x200
	NJS_POINT3 op[128];        // offset 0x214, size 0x600
	NJS_CNK_OBJECT* cobj[128]; // offset 0x814, size 0x200
	int* sktp[128];            // offset 0xA14, size 0x200
    int* vlp[128];             // offset 0xC14, size 0x200
	NJS_MATRIX* mxp[128][10];  // offset 0xE14, size 0x1400
	void* wkp;                 // offset 0x2214, size 0x4
    unsigned char* buff2;      // offset 0x2218, size 0x4
    unsigned char* bp2;        // offset 0x221C, size 0x4
	MDLSTR2 mdlstr2[128];      // offset 0x2220, size 0xA00
	int* vlp2[128];            // offset 0x2C20, size 0x200
    char mes[256];             // offset 0x2E20, size 0x100
} NP_WORK;

typedef struct HDR_PS
{
	// total size: 0x40
    unsigned char ucType;        // offset 0x0, size 0x1
    unsigned char ucAttr;        // offset 0x1, size 0x1
    unsigned short usSize;       // offset 0x2, size 0x2
    unsigned short usIndexOfs;   // offset 0x4, size 0x2
    unsigned short usIndexMax;   // offset 0x6, size 0x2
    unsigned char ucPadding[56]; // offset 0x8, size 0x38
} HDR_PS;

typedef struct HDR_CV
{
	// total size: 0x8
    unsigned char ucType;      // offset 0x0, size 0x1
    unsigned char ucAttr;      // offset 0x1, size 0x1
    unsigned short usSize;     // offset 0x2, size 0x2
    unsigned short usIndexOfs; // offset 0x4, size 0x2
    unsigned short usIndexMax; // offset 0x6, size 0x2
} HDR_CV;

void npPlusInit();
int npCollisionCheckCC(NJS_CAPSULE* cpa, NJS_CAPSULE* cpb);
int npCollisionCheckCCEx(NJS_CAPSULE* cpa, NJS_CAPSULE* cpb, NJS_POINT3* pos);
int npCollisionCheckSC(NJS_SPHERE* sa, NJS_CAPSULE* cpb);
void npDistanceP2C(NJS_POINT3* pos, NJS_CAPSULE* cap, NJS_POINT3* htp);
void npDrawPlane(NJS_POINT3* ps0, NJS_POINT3* ps1, NJS_POINT3* ps2, NJS_POINT3* ps3, unsigned int argb);
void npCalcMorphing(NJS_CNK_OBJECT* obj_a, NJS_CNK_OBJECT* obj_b, float no, int obj_n);
void npTransform(NJS_CNK_OBJECT* srcobj, NJS_CNK_OBJECT* dstobj, register float no, int ono);
void npPushMdlstr(NJS_CNK_OBJECT* objp, int obj_n);
void npPopMdlstr(NJS_CNK_OBJECT* objp, int obj_n);
void npPushMdlstr2(NJS_CNK_OBJECT* objp, int obj_n);
void npPopMdlstr2(NJS_CNK_OBJECT* objp, int obj_n);
void npCnkFlatOff(NJS_CNK_OBJECT* objp);
void npClrTranslate();
void npSetMemory(unsigned char* memp, unsigned int size, char dat);
void npSetMemoryL(unsigned int* memp, unsigned int size, int dat);
void npCopyMemory(unsigned char* dst, unsigned char* src, unsigned int size);
void npGetWHDSizeSub(NJS_CNK_OBJECT* objp, NJS_POINT3* whd);
void npGetWHDSize(NJS_CNK_OBJECT* objp, NJS_POINT3* whd);
void npSkinConvPreparation(NJS_CNK_OBJECT* objp);
void npSkinConvSub(NJS_CNK_OBJECT* objp);
void npSkinConvMain(NJS_CNK_OBJECT* objp);
void npSkinConvert(NJS_CNK_OBJECT* objp, int* sknp);
void npRetSkinConvMain(NJS_CNK_OBJECT* objp);
void npRetSkinConvert(NJS_CNK_OBJECT* objp, int* sknp);
unsigned int npGetMatColor(NJS_CNK_OBJECT* objp, int obj_n);
void npSetAllMatColor(NJS_CNK_OBJECT* objp, int obj_n, unsigned int argb);
void npChangeMatAlphaColor(NJS_CNK_OBJECT* objp, int obj_n, unsigned char alpha);
void npSetAllMatAlphaColor(NJS_CNK_OBJECT* objp, int obj_n, unsigned char alpha);
void npSetOffsetUV(NJS_CNK_MODEL* mdlp, short offu, short offv);
void npSetOffsetUV2(NJS_CNK_MODEL* mdlp, short offu, short offv);
int npCopyVlist(int* dstp, int* srcp);
void npCutSkin();
void npInitCalcSkin(void* pwp, int obj_n, int* sknp);
void npCalcSkin(void* pwp, int obj_n, int* sknp);
void npInitCalcSkinFM(void* pwp, int obj_n, int* sknp);
void npCalcSkinFM(void* pwp, int obj_n, int* sknp);

#endif
