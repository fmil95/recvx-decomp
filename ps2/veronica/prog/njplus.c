#include "njplus.h"

typedef struct npobj;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef union _anon10;
typedef struct _anon11;
typedef struct _anon12;
typedef struct _anon13;
typedef struct _anon14;
typedef struct BH_PWORK;
typedef struct _anon15;
typedef struct _anon16;
typedef struct _anon17;
typedef struct _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;


typedef _anon1 type_0[8];
typedef _anon1 type_1[4];
typedef _anon10 type_2[8];
typedef unsigned char type_3[64];
typedef float type_4[16];
typedef char type_5[8];
typedef _anon1 type_6[8];
typedef float type_7[10];
typedef _anon1 type_8[8];
typedef _anon10 type_9[16];
typedef float type_10[16][0];
typedef _anon1 type_11[4];
typedef unsigned char type_12[64];
typedef _anon1 type_13[3];
typedef _anon1 type_14[2];
typedef _anon10 type_15[3];
typedef _anon10 type_16[2];
typedef _anon10 type_17[8];
typedef unsigned char type_18[64];
typedef void* type_19[2];
typedef unsigned int type_20[2];
typedef _anon1 type_21[16];
typedef float type_22[3];
typedef int type_23[3];
typedef _anon1 type_24[16];
typedef float type_25[3];
typedef _anon1 type_26[4];
typedef _anon1 type_27[4];
typedef _anon1 type_28[4];
typedef float type_29[3];
typedef _anon10 type_30[4];
typedef _anon10 type_31[4];
typedef int type_32[64];
typedef _anon1 type_33[4];
typedef _anon10 type_34[16];
typedef _anon1 type_35[4];
typedef _anon10 type_36[4];
typedef float type_37[16][0];
typedef _anon10 type_38[4];
typedef unsigned char type_39[64];
typedef unsigned char type_40[56];
typedef int* type_41[128];
typedef _anon1 type_42[128];
typedef npobj* type_43[128];
typedef int* type_44[128];
typedef int* type_45[128];
typedef float type_46[16][10];
typedef float type_47[10];
typedef float type_48[16][10][128];
typedef _anon1 type_49[8];
typedef unsigned int type_50[1];
typedef _anon1 type_51[8];
typedef _anon17 type_52[128];
typedef unsigned int type_53[2];
typedef int* type_54[16];
typedef _anon1 type_55[4];
typedef int* type_56[128];
typedef npobj* type_57[16];
typedef char type_58[256];
typedef _anon12* type_59[16];
typedef float type_60[10];
typedef _anon15 type_61[16];
typedef _anon1 type_62[8];
typedef _anon1 type_63[8];
typedef _anon1 type_64[8];

struct npobj
{
	unsigned int evalflags;
	_anon16* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon0
{
	float x;
	float y;
	float z;
	float w;
};

struct _anon1
{
	float x;
	float y;
	float z;
};

struct _anon2
{
	unsigned char ucType;
	unsigned char ucAttr;
	unsigned short usSize;
	unsigned short usIndexOfs;
	unsigned short usIndexMax;
};

struct _anon3
{
	unsigned char ucType;
	unsigned char ucAttr;
	unsigned short usSize;
	unsigned short usIndexOfs;
	unsigned short usIndexMax;
	unsigned char ucPadding[56];
};

struct _anon4
{
	_anon1 c1;
	_anon1 c2;
	float r;
};

struct _anon5
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon13* md2P;
	unsigned short* atrP;
};

struct _anon6
{
	_anon1 c;
	float r;
};

struct _anon7
{
	short u;
	short v;
};

struct _anon8
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct _anon9
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

union _anon10
{
	unsigned int color;
	_anon7 tex;
	_anon8 argb;
};

struct _anon11
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon12
{
	_anon11* textures;
	unsigned int nbTexture;
};

struct _anon13
{
	void* p[2];
};

struct _anon14
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct BH_PWORK
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	char flr_nob;
	unsigned char mdlver;
	unsigned char param;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	float px;
	float py;
	float pz;
	int ax;
	int ay;
	int az;
	float ar;
	float aw;
	float ah;
	float ad;
	float car;
	float cah;
	float pxb;
	float pyb;
	float pzb;
	int axb;
	int ayb;
	int azb;
	float gpx;
	float gpy;
	float gpz;
	float lox;
	float loy;
	float loz;
	float aox;
	float aoy;
	float aoz;
	float spd;
	unsigned int flg2;
	unsigned int mdflg;
	unsigned int stflg;
	unsigned int Dummy3;
	int draw_tp;
	int mdl_n;
	void* mskp;
	unsigned int Dummy[1];
	int* skp[16];
	npobj* mbp[16];
	_anon12* txp[16];
	_anon15 mdl[16];
	_anon15* mlwP;
	unsigned int mdl_no;
	int lkono;
	unsigned char* lkwkp;
	unsigned char* exp0;
	unsigned char* exp1;
	unsigned char* exp2;
	unsigned char* exp3;
	unsigned char mtxbuf[64];
	float mtx[16];
	npobj* obj_a;
	npobj* obj_b;
	float shp_ct;
	char clp_jno[8];
	int lok_jno;
	_anon5* mnwP;
	_anon5* mnwPb;
	unsigned int mtn_attr;
	unsigned int mtn_no;
	int frm_no;
	unsigned int frm_mode;
	int hokan_rate;
	unsigned int hokan_count;
	unsigned int hokan_ctbak;
	int mtn_add;
	unsigned int mtn_md;
	unsigned char* mtn_tp;
	int axp;
	int ayp;
	int azp;
	short psh_ct;
	short psh_idx;
	int idx_ct;
	int mtn_chk;
	float ofx;
	float ofy;
	float ofz;
	float sx;
	float sy;
	float sz;
	float sxb;
	float syb;
	float szb;
	float xn;
	float yn;
	float zn;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	int wpnr_no;
	int wpnl_no;
	unsigned int at_flg;
	_anon4 watr;
	_anon14* cpcl;
	short wax;
	short way;
	short waz;
	short waxp;
	short wayp;
	short wazp;
	int hp;
	int dam[64];
	int djnt_no;
	int cpcl_no;
	int dax;
	int day;
	float dpx;
	float dpy;
	float dpz;
	float dvx;
	float dvy;
	float dvz;
	int flr_snd;
	int ko_num;
	int footeff;
	int src_no;
	unsigned char* kdnp;
	int kdnidx;
	void* dan_ap;
	unsigned int comb_flg;
	unsigned int comb_wep;
	int comb_pnt;
	int comb_timeout;
	int total_dam;
	unsigned int Dummy2[2];
};

struct _anon15
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon12* texP;
	_anon9* owP;
};

struct _anon16
{
	int* vlist;
	short* plist;
	_anon1 center;
	float r;
};

struct _anon17
{
	float pos[3];
	int* vlist;
	short* plist;
};

struct _anon18
{
	_anon1 c1;
	_anon1 c2;
	float r1;
	float r2;
};

struct _anon19
{
	_anon1* p;
	_anon10* col;
	_anon10* tex;
	unsigned int num;
};

struct _anon20
{
	int* sknp;
	int obj_now;
	int obj_cnt;
	unsigned char* buff;
	unsigned char* bp;
	int* vlist[128];
	_anon1 op[128];
	npobj* cobj[128];
	int* sktp[128];
	int* vlp[128];
	float mxp[16][10][128];
	void* wkp;
	unsigned char* buff2;
	unsigned char* bp2;
	_anon17 mdlstr2[128];
	int* vlp2[128];
	char mes[256];
};

struct _anon21
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

NP_WORK np;
unsigned char* njpmemp;
float lcmat[16][0];
float lcmat[16][0];

void npPlusInit();
int npCollisionCheckCC(_anon4* cpa, _anon4* cpb);
int npCollisionCheckCCEx(_anon4* cpa, _anon4* cpb, _anon1* pos);
int npCollisionCheckSC(_anon6* sa, _anon4* cpb);
void npDistanceP2C(_anon1* pos, _anon4* cap, _anon1* htp);
void npDrawPlane(_anon1* ps0, _anon1* ps1, _anon1* ps2, _anon1* ps3, unsigned int argb);
void npCalcMorphing(npobj* obj_a, npobj* obj_b, float no, int obj_n);
void npTransform(npobj* srcobj, npobj* dstobj, float no, int ono);
void npPushMdlstr(npobj* objp, int obj_n);
void npPopMdlstr(npobj* objp, int obj_n);
void npPushMdlstr2(npobj* objp, int obj_n);
void npPopMdlstr2(npobj* objp, int obj_n);
void npCnkFlatOff(npobj* objp);
void npClrTranslate();
void npSetMemory(unsigned char* memp, unsigned int size, char dat);
void npSetMemoryL(unsigned int* memp, unsigned int size, int dat);
void npCopyMemory(unsigned char* dst, unsigned char* src, unsigned int size);
void npGetWHDSizeSub(npobj* objp, _anon1* whd);
void npGetWHDSize(npobj* objp, _anon1* whd);
void npSkinConvPreparation(npobj* objp);
void npSkinConvSub(NJS_CNK_OBJECT* objp);
void npSkinConvMain(npobj* objp);
void npSkinConvert(npobj* objp, int* sknp);
void npRetSkinConvMain(npobj* objp);
void npRetSkinConvert(npobj* objp, int* sknp);
unsigned int npGetMatColor(npobj* objp, int obj_n);
void npSetAllMatColor(npobj* objp, int obj_n, unsigned int argb);
void npChangeMatAlphaColor(npobj* objp, int obj_n, unsigned char alpha);
void npSetAllMatAlphaColor(npobj* objp, int obj_n, unsigned char alpha);
void npSetOffsetUV(_anon16* mdlp, short offu, short offv);
void npSetOffsetUV2(_anon16* mdlp, short offu, short offv);
int npCopyVlist(int* dstp, int* srcp);
void npCutSkin();
void npInitCalcSkin(void* pwp, int obj_n, int* sknp);
void npCalcSkin(void* pwp, int obj_n, int* sknp);
void npInitCalcSkinFM(void* pwp, int obj_n, int* sknp);
void npCalcSkinFM(void* pwp, int obj_n, int* sknp);

// 
// Start address: 0x12b670
void npPlusInit()
{
	int j;
	int i;
	// Line 67, Address: 0x12b670, Func Offset: 0
	// Line 73, Address: 0x12b680, Func Offset: 0x10
	// Line 67, Address: 0x12b684, Func Offset: 0x14
	// Line 68, Address: 0x12b68c, Func Offset: 0x1c
	// Line 70, Address: 0x12b69c, Func Offset: 0x2c
	// Line 71, Address: 0x12b6ac, Func Offset: 0x3c
	// Line 74, Address: 0x12b6bc, Func Offset: 0x4c
	// Line 75, Address: 0x12b6c8, Func Offset: 0x58
	// Line 77, Address: 0x12b6d0, Func Offset: 0x60
	// Line 75, Address: 0x12b6d8, Func Offset: 0x68
	// Line 76, Address: 0x12b6dc, Func Offset: 0x6c
	// Line 77, Address: 0x12b6f0, Func Offset: 0x80
	// Line 78, Address: 0x12b6f8, Func Offset: 0x88
	// Line 79, Address: 0x12b708, Func Offset: 0x98
	// Func End, Address: 0x12b710, Func Offset: 0xa0
}

// 
// Start address: 0x12b710
int npCollisionCheckCC(_anon4* cpa, _anon4* cpb)
{
	float sca;
	float lenb;
	float lena;
	float inn;
	_anon1 vec;
	_anon6 sb;
	_anon6 sa;
	_anon4* capb;
	_anon4* capa;
	_anon21 lnc;
	_anon21 lnb;
	_anon21 lna;
	// Line 91, Address: 0x12b710, Func Offset: 0
	// Line 97, Address: 0x12b748, Func Offset: 0x38
	// Line 98, Address: 0x12b74c, Func Offset: 0x3c
	// Line 99, Address: 0x12b750, Func Offset: 0x40
	// Line 100, Address: 0x12b754, Func Offset: 0x44
	// Line 97, Address: 0x12b758, Func Offset: 0x48
	// Line 98, Address: 0x12b75c, Func Offset: 0x4c
	// Line 104, Address: 0x12b760, Func Offset: 0x50
	// Line 105, Address: 0x12b764, Func Offset: 0x54
	// Line 106, Address: 0x12b768, Func Offset: 0x58
	// Line 98, Address: 0x12b76c, Func Offset: 0x5c
	// Line 99, Address: 0x12b770, Func Offset: 0x60
	// Line 100, Address: 0x12b780, Func Offset: 0x70
	// Line 101, Address: 0x12b790, Func Offset: 0x80
	// Line 102, Address: 0x12b7a0, Func Offset: 0x90
	// Line 109, Address: 0x12b7a8, Func Offset: 0x98
	// Line 102, Address: 0x12b7ac, Func Offset: 0x9c
	// Line 103, Address: 0x12b7b4, Func Offset: 0xa4
	// Line 104, Address: 0x12b7bc, Func Offset: 0xac
	// Line 105, Address: 0x12b7c4, Func Offset: 0xb4
	// Line 106, Address: 0x12b7cc, Func Offset: 0xbc
	// Line 107, Address: 0x12b7dc, Func Offset: 0xcc
	// Line 108, Address: 0x12b7ec, Func Offset: 0xdc
	// Line 109, Address: 0x12b7f8, Func Offset: 0xe8
	// Line 110, Address: 0x12b804, Func Offset: 0xf4
	// Line 111, Address: 0x12b810, Func Offset: 0x100
	// Line 115, Address: 0x12b820, Func Offset: 0x110
	// Line 118, Address: 0x12b824, Func Offset: 0x114
	// Line 115, Address: 0x12b828, Func Offset: 0x118
	// Line 119, Address: 0x12b834, Func Offset: 0x124
	// Line 116, Address: 0x12b838, Func Offset: 0x128
	// Line 120, Address: 0x12b83c, Func Offset: 0x12c
	// Line 113, Address: 0x12b840, Func Offset: 0x130
	// Line 115, Address: 0x12b844, Func Offset: 0x134
	// Line 116, Address: 0x12b84c, Func Offset: 0x13c
	// Line 117, Address: 0x12b85c, Func Offset: 0x14c
	// Line 121, Address: 0x12b868, Func Offset: 0x158
	// Line 122, Address: 0x12b870, Func Offset: 0x160
	// Line 123, Address: 0x12b874, Func Offset: 0x164
	// Line 127, Address: 0x12b878, Func Offset: 0x168
	// Line 128, Address: 0x12b88c, Func Offset: 0x17c
	// Line 131, Address: 0x12b890, Func Offset: 0x180
	// Line 132, Address: 0x12b894, Func Offset: 0x184
	// Line 128, Address: 0x12b89c, Func Offset: 0x18c
	// Line 131, Address: 0x12b8a0, Func Offset: 0x190
	// Line 129, Address: 0x12b8a4, Func Offset: 0x194
	// Line 133, Address: 0x12b8a8, Func Offset: 0x198
	// Line 134, Address: 0x12b8ac, Func Offset: 0x19c
	// Line 131, Address: 0x12b8b0, Func Offset: 0x1a0
	// Line 129, Address: 0x12b8b4, Func Offset: 0x1a4
	// Line 131, Address: 0x12b8b8, Func Offset: 0x1a8
	// Line 132, Address: 0x12b8bc, Func Offset: 0x1ac
	// Line 133, Address: 0x12b8d0, Func Offset: 0x1c0
	// Line 134, Address: 0x12b8e0, Func Offset: 0x1d0
	// Line 135, Address: 0x12b8e8, Func Offset: 0x1d8
	// Line 136, Address: 0x12b8f4, Func Offset: 0x1e4
	// Line 137, Address: 0x12b8fc, Func Offset: 0x1ec
	// Line 138, Address: 0x12b908, Func Offset: 0x1f8
	// Line 139, Address: 0x12b920, Func Offset: 0x210
	// Line 140, Address: 0x12b930, Func Offset: 0x220
	// Line 141, Address: 0x12b938, Func Offset: 0x228
	// Line 142, Address: 0x12b940, Func Offset: 0x230
	// Line 144, Address: 0x12b944, Func Offset: 0x234
	// Line 145, Address: 0x12b94c, Func Offset: 0x23c
	// Line 146, Address: 0x12b954, Func Offset: 0x244
	// Line 147, Address: 0x12b95c, Func Offset: 0x24c
	// Line 150, Address: 0x12b964, Func Offset: 0x254
	// Line 151, Address: 0x12b96c, Func Offset: 0x25c
	// Line 152, Address: 0x12b974, Func Offset: 0x264
	// Line 150, Address: 0x12b978, Func Offset: 0x268
	// Line 153, Address: 0x12b97c, Func Offset: 0x26c
	// Line 150, Address: 0x12b980, Func Offset: 0x270
	// Line 151, Address: 0x12b984, Func Offset: 0x274
	// Line 152, Address: 0x12b994, Func Offset: 0x284
	// Line 153, Address: 0x12b9a4, Func Offset: 0x294
	// Line 154, Address: 0x12b9ac, Func Offset: 0x29c
	// Line 155, Address: 0x12b9b8, Func Offset: 0x2a8
	// Line 156, Address: 0x12b9c0, Func Offset: 0x2b0
	// Line 157, Address: 0x12b9cc, Func Offset: 0x2bc
	// Line 158, Address: 0x12b9e4, Func Offset: 0x2d4
	// Line 159, Address: 0x12b9f4, Func Offset: 0x2e4
	// Line 160, Address: 0x12b9fc, Func Offset: 0x2ec
	// Line 161, Address: 0x12ba04, Func Offset: 0x2f4
	// Line 163, Address: 0x12ba08, Func Offset: 0x2f8
	// Line 164, Address: 0x12ba10, Func Offset: 0x300
	// Line 165, Address: 0x12ba18, Func Offset: 0x308
	// Line 166, Address: 0x12ba20, Func Offset: 0x310
	// Line 177, Address: 0x12ba28, Func Offset: 0x318
	// Line 180, Address: 0x12ba44, Func Offset: 0x334
	// Line 183, Address: 0x12ba48, Func Offset: 0x338
	// Line 180, Address: 0x12ba54, Func Offset: 0x344
	// Line 181, Address: 0x12ba58, Func Offset: 0x348
	// Line 182, Address: 0x12ba60, Func Offset: 0x350
	// Line 183, Address: 0x12ba64, Func Offset: 0x354
	// Line 185, Address: 0x12ba6c, Func Offset: 0x35c
	// Line 186, Address: 0x12ba74, Func Offset: 0x364
	// Line 188, Address: 0x12ba78, Func Offset: 0x368
	// Line 185, Address: 0x12ba7c, Func Offset: 0x36c
	// Line 186, Address: 0x12ba84, Func Offset: 0x374
	// Line 187, Address: 0x12ba94, Func Offset: 0x384
	// Line 188, Address: 0x12baa4, Func Offset: 0x394
	// Line 189, Address: 0x12baac, Func Offset: 0x39c
	// Line 190, Address: 0x12bab8, Func Offset: 0x3a8
	// Line 191, Address: 0x12bac4, Func Offset: 0x3b4
	// Line 192, Address: 0x12badc, Func Offset: 0x3cc
	// Line 193, Address: 0x12baec, Func Offset: 0x3dc
	// Line 194, Address: 0x12baf4, Func Offset: 0x3e4
	// Line 195, Address: 0x12bafc, Func Offset: 0x3ec
	// Line 197, Address: 0x12bb00, Func Offset: 0x3f0
	// Line 198, Address: 0x12bb08, Func Offset: 0x3f8
	// Line 199, Address: 0x12bb10, Func Offset: 0x400
	// Line 200, Address: 0x12bb18, Func Offset: 0x408
	// Line 210, Address: 0x12bb20, Func Offset: 0x410
	// Line 213, Address: 0x12bb3c, Func Offset: 0x42c
	// Line 216, Address: 0x12bb40, Func Offset: 0x430
	// Line 213, Address: 0x12bb4c, Func Offset: 0x43c
	// Line 214, Address: 0x12bb50, Func Offset: 0x440
	// Line 215, Address: 0x12bb58, Func Offset: 0x448
	// Line 216, Address: 0x12bb5c, Func Offset: 0x44c
	// Line 218, Address: 0x12bb64, Func Offset: 0x454
	// Line 219, Address: 0x12bb6c, Func Offset: 0x45c
	// Line 221, Address: 0x12bb70, Func Offset: 0x460
	// Line 218, Address: 0x12bb74, Func Offset: 0x464
	// Line 219, Address: 0x12bb7c, Func Offset: 0x46c
	// Line 220, Address: 0x12bb8c, Func Offset: 0x47c
	// Line 221, Address: 0x12bb9c, Func Offset: 0x48c
	// Line 222, Address: 0x12bba4, Func Offset: 0x494
	// Line 223, Address: 0x12bbb0, Func Offset: 0x4a0
	// Line 224, Address: 0x12bbbc, Func Offset: 0x4ac
	// Line 225, Address: 0x12bbd4, Func Offset: 0x4c4
	// Line 226, Address: 0x12bbe4, Func Offset: 0x4d4
	// Line 227, Address: 0x12bbec, Func Offset: 0x4dc
	// Line 228, Address: 0x12bbf4, Func Offset: 0x4e4
	// Line 230, Address: 0x12bbf8, Func Offset: 0x4e8
	// Line 231, Address: 0x12bc00, Func Offset: 0x4f0
	// Line 232, Address: 0x12bc08, Func Offset: 0x4f8
	// Line 233, Address: 0x12bc10, Func Offset: 0x500
	// Line 243, Address: 0x12bc18, Func Offset: 0x508
	// Line 246, Address: 0x12bc30, Func Offset: 0x520
	// Func End, Address: 0x12bc6c, Func Offset: 0x55c
}

// 
// Start address: 0x12bc70
int npCollisionCheckCCEx(_anon4* cpa, _anon4* cpb, _anon1* pos)
{
	_anon1 scl;
	_anon1 scl;
	_anon1 scl;
	float sca;
	float lenb;
	float lena;
	float inn;
	_anon1 vec;
	_anon6 sb;
	_anon6 sa;
	_anon4* capb;
	_anon4* capa;
	_anon21 lnc;
	_anon21 lnb;
	_anon21 lna;
	// Line 256, Address: 0x12bc70, Func Offset: 0
	// Line 262, Address: 0x12bca8, Func Offset: 0x38
	// Line 263, Address: 0x12bcac, Func Offset: 0x3c
	// Line 264, Address: 0x12bcb0, Func Offset: 0x40
	// Line 265, Address: 0x12bcb4, Func Offset: 0x44
	// Line 262, Address: 0x12bcb8, Func Offset: 0x48
	// Line 263, Address: 0x12bcbc, Func Offset: 0x4c
	// Line 271, Address: 0x12bcc0, Func Offset: 0x50
	// Line 263, Address: 0x12bcd0, Func Offset: 0x60
	// Line 264, Address: 0x12bcd4, Func Offset: 0x64
	// Line 265, Address: 0x12bcdc, Func Offset: 0x6c
	// Line 266, Address: 0x12bcec, Func Offset: 0x7c
	// Line 269, Address: 0x12bcf4, Func Offset: 0x84
	// Line 266, Address: 0x12bcf8, Func Offset: 0x88
	// Line 267, Address: 0x12bd00, Func Offset: 0x90
	// Line 274, Address: 0x12bd08, Func Offset: 0x98
	// Line 267, Address: 0x12bd0c, Func Offset: 0x9c
	// Line 268, Address: 0x12bd14, Func Offset: 0xa4
	// Line 269, Address: 0x12bd1c, Func Offset: 0xac
	// Line 270, Address: 0x12bd24, Func Offset: 0xb4
	// Line 271, Address: 0x12bd30, Func Offset: 0xc0
	// Line 272, Address: 0x12bd38, Func Offset: 0xc8
	// Line 271, Address: 0x12bd3c, Func Offset: 0xcc
	// Line 272, Address: 0x12bd44, Func Offset: 0xd4
	// Line 273, Address: 0x12bd4c, Func Offset: 0xdc
	// Line 272, Address: 0x12bd50, Func Offset: 0xe0
	// Line 273, Address: 0x12bd58, Func Offset: 0xe8
	// Line 274, Address: 0x12bd64, Func Offset: 0xf4
	// Line 275, Address: 0x12bd70, Func Offset: 0x100
	// Line 276, Address: 0x12bd7c, Func Offset: 0x10c
	// Line 280, Address: 0x12bd8c, Func Offset: 0x11c
	// Line 283, Address: 0x12bd90, Func Offset: 0x120
	// Line 280, Address: 0x12bd94, Func Offset: 0x124
	// Line 284, Address: 0x12bda0, Func Offset: 0x130
	// Line 281, Address: 0x12bda4, Func Offset: 0x134
	// Line 285, Address: 0x12bda8, Func Offset: 0x138
	// Line 278, Address: 0x12bdac, Func Offset: 0x13c
	// Line 280, Address: 0x12bdb0, Func Offset: 0x140
	// Line 281, Address: 0x12bdb8, Func Offset: 0x148
	// Line 282, Address: 0x12bdc8, Func Offset: 0x158
	// Line 286, Address: 0x12bdd4, Func Offset: 0x164
	// Line 287, Address: 0x12bddc, Func Offset: 0x16c
	// Line 288, Address: 0x12bde0, Func Offset: 0x170
	// Line 292, Address: 0x12bde4, Func Offset: 0x174
	// Line 293, Address: 0x12bdf8, Func Offset: 0x188
	// Line 297, Address: 0x12be00, Func Offset: 0x190
	// Line 293, Address: 0x12be08, Func Offset: 0x198
	// Line 296, Address: 0x12be0c, Func Offset: 0x19c
	// Line 294, Address: 0x12be14, Func Offset: 0x1a4
	// Line 298, Address: 0x12be18, Func Offset: 0x1a8
	// Line 299, Address: 0x12be1c, Func Offset: 0x1ac
	// Line 296, Address: 0x12be20, Func Offset: 0x1b0
	// Line 294, Address: 0x12be24, Func Offset: 0x1b4
	// Line 296, Address: 0x12be28, Func Offset: 0x1b8
	// Line 297, Address: 0x12be2c, Func Offset: 0x1bc
	// Line 298, Address: 0x12be40, Func Offset: 0x1d0
	// Line 299, Address: 0x12be50, Func Offset: 0x1e0
	// Line 300, Address: 0x12be58, Func Offset: 0x1e8
	// Line 301, Address: 0x12be64, Func Offset: 0x1f4
	// Line 302, Address: 0x12be6c, Func Offset: 0x1fc
	// Line 303, Address: 0x12be78, Func Offset: 0x208
	// Line 304, Address: 0x12be90, Func Offset: 0x220
	// Line 305, Address: 0x12bea0, Func Offset: 0x230
	// Line 306, Address: 0x12bea8, Func Offset: 0x238
	// Line 307, Address: 0x12beb0, Func Offset: 0x240
	// Line 309, Address: 0x12beb4, Func Offset: 0x244
	// Line 310, Address: 0x12bebc, Func Offset: 0x24c
	// Line 311, Address: 0x12bec4, Func Offset: 0x254
	// Line 312, Address: 0x12becc, Func Offset: 0x25c
	// Line 315, Address: 0x12bed4, Func Offset: 0x264
	// Line 316, Address: 0x12bedc, Func Offset: 0x26c
	// Line 317, Address: 0x12bee4, Func Offset: 0x274
	// Line 315, Address: 0x12bee8, Func Offset: 0x278
	// Line 318, Address: 0x12beec, Func Offset: 0x27c
	// Line 315, Address: 0x12bef0, Func Offset: 0x280
	// Line 316, Address: 0x12bef4, Func Offset: 0x284
	// Line 317, Address: 0x12bf08, Func Offset: 0x298
	// Line 318, Address: 0x12bf1c, Func Offset: 0x2ac
	// Line 319, Address: 0x12bf24, Func Offset: 0x2b4
	// Line 320, Address: 0x12bf30, Func Offset: 0x2c0
	// Line 321, Address: 0x12bf38, Func Offset: 0x2c8
	// Line 322, Address: 0x12bf44, Func Offset: 0x2d4
	// Line 323, Address: 0x12bf5c, Func Offset: 0x2ec
	// Line 324, Address: 0x12bf6c, Func Offset: 0x2fc
	// Line 325, Address: 0x12bf74, Func Offset: 0x304
	// Line 326, Address: 0x12bf7c, Func Offset: 0x30c
	// Line 328, Address: 0x12bf80, Func Offset: 0x310
	// Line 329, Address: 0x12bf88, Func Offset: 0x318
	// Line 330, Address: 0x12bf90, Func Offset: 0x320
	// Line 331, Address: 0x12bf98, Func Offset: 0x328
	// Line 353, Address: 0x12bfa0, Func Offset: 0x330
	// Line 355, Address: 0x12bfb4, Func Offset: 0x344
	// Line 356, Address: 0x12bfbc, Func Offset: 0x34c
	// Line 357, Address: 0x12bfc0, Func Offset: 0x350
	// Line 358, Address: 0x12bfc4, Func Offset: 0x354
	// Line 355, Address: 0x12bfc8, Func Offset: 0x358
	// Line 356, Address: 0x12bfd0, Func Offset: 0x360
	// Line 357, Address: 0x12bfe0, Func Offset: 0x370
	// Line 358, Address: 0x12bfec, Func Offset: 0x37c
	// Line 359, Address: 0x12c008, Func Offset: 0x398
	// Line 360, Address: 0x12c010, Func Offset: 0x3a0
	// Line 361, Address: 0x12c028, Func Offset: 0x3b8
	// Line 362, Address: 0x12c040, Func Offset: 0x3d0
	// Line 363, Address: 0x12c054, Func Offset: 0x3e4
	// Line 364, Address: 0x12c05c, Func Offset: 0x3ec
	// Line 365, Address: 0x12c064, Func Offset: 0x3f4
	// Line 366, Address: 0x12c06c, Func Offset: 0x3fc
	// Line 368, Address: 0x12c074, Func Offset: 0x404
	// Line 372, Address: 0x12c07c, Func Offset: 0x40c
	// Line 375, Address: 0x12c080, Func Offset: 0x410
	// Line 372, Address: 0x12c08c, Func Offset: 0x41c
	// Line 373, Address: 0x12c090, Func Offset: 0x420
	// Line 374, Address: 0x12c098, Func Offset: 0x428
	// Line 375, Address: 0x12c09c, Func Offset: 0x42c
	// Line 377, Address: 0x12c0a4, Func Offset: 0x434
	// Line 378, Address: 0x12c0ac, Func Offset: 0x43c
	// Line 380, Address: 0x12c0b0, Func Offset: 0x440
	// Line 377, Address: 0x12c0b4, Func Offset: 0x444
	// Line 378, Address: 0x12c0bc, Func Offset: 0x44c
	// Line 379, Address: 0x12c0d0, Func Offset: 0x460
	// Line 380, Address: 0x12c0e4, Func Offset: 0x474
	// Line 381, Address: 0x12c0ec, Func Offset: 0x47c
	// Line 382, Address: 0x12c0f8, Func Offset: 0x488
	// Line 383, Address: 0x12c104, Func Offset: 0x494
	// Line 384, Address: 0x12c11c, Func Offset: 0x4ac
	// Line 385, Address: 0x12c12c, Func Offset: 0x4bc
	// Line 386, Address: 0x12c134, Func Offset: 0x4c4
	// Line 387, Address: 0x12c13c, Func Offset: 0x4cc
	// Line 389, Address: 0x12c140, Func Offset: 0x4d0
	// Line 390, Address: 0x12c148, Func Offset: 0x4d8
	// Line 391, Address: 0x12c150, Func Offset: 0x4e0
	// Line 392, Address: 0x12c158, Func Offset: 0x4e8
	// Line 408, Address: 0x12c160, Func Offset: 0x4f0
	// Line 410, Address: 0x12c174, Func Offset: 0x504
	// Line 411, Address: 0x12c17c, Func Offset: 0x50c
	// Line 412, Address: 0x12c180, Func Offset: 0x510
	// Line 413, Address: 0x12c184, Func Offset: 0x514
	// Line 410, Address: 0x12c188, Func Offset: 0x518
	// Line 411, Address: 0x12c190, Func Offset: 0x520
	// Line 412, Address: 0x12c1a0, Func Offset: 0x530
	// Line 413, Address: 0x12c1ac, Func Offset: 0x53c
	// Line 414, Address: 0x12c1c8, Func Offset: 0x558
	// Line 415, Address: 0x12c1d0, Func Offset: 0x560
	// Line 416, Address: 0x12c1e8, Func Offset: 0x578
	// Line 417, Address: 0x12c200, Func Offset: 0x590
	// Line 418, Address: 0x12c214, Func Offset: 0x5a4
	// Line 419, Address: 0x12c21c, Func Offset: 0x5ac
	// Line 420, Address: 0x12c224, Func Offset: 0x5b4
	// Line 421, Address: 0x12c22c, Func Offset: 0x5bc
	// Line 423, Address: 0x12c234, Func Offset: 0x5c4
	// Line 427, Address: 0x12c23c, Func Offset: 0x5cc
	// Line 430, Address: 0x12c240, Func Offset: 0x5d0
	// Line 427, Address: 0x12c24c, Func Offset: 0x5dc
	// Line 428, Address: 0x12c250, Func Offset: 0x5e0
	// Line 429, Address: 0x12c258, Func Offset: 0x5e8
	// Line 430, Address: 0x12c25c, Func Offset: 0x5ec
	// Line 432, Address: 0x12c264, Func Offset: 0x5f4
	// Line 433, Address: 0x12c26c, Func Offset: 0x5fc
	// Line 435, Address: 0x12c270, Func Offset: 0x600
	// Line 432, Address: 0x12c274, Func Offset: 0x604
	// Line 433, Address: 0x12c27c, Func Offset: 0x60c
	// Line 434, Address: 0x12c290, Func Offset: 0x620
	// Line 435, Address: 0x12c2a4, Func Offset: 0x634
	// Line 436, Address: 0x12c2ac, Func Offset: 0x63c
	// Line 437, Address: 0x12c2b8, Func Offset: 0x648
	// Line 438, Address: 0x12c2c4, Func Offset: 0x654
	// Line 439, Address: 0x12c2dc, Func Offset: 0x66c
	// Line 440, Address: 0x12c2ec, Func Offset: 0x67c
	// Line 441, Address: 0x12c2f4, Func Offset: 0x684
	// Line 442, Address: 0x12c2fc, Func Offset: 0x68c
	// Line 444, Address: 0x12c300, Func Offset: 0x690
	// Line 445, Address: 0x12c308, Func Offset: 0x698
	// Line 446, Address: 0x12c310, Func Offset: 0x6a0
	// Line 447, Address: 0x12c318, Func Offset: 0x6a8
	// Line 463, Address: 0x12c320, Func Offset: 0x6b0
	// Line 465, Address: 0x12c334, Func Offset: 0x6c4
	// Line 466, Address: 0x12c33c, Func Offset: 0x6cc
	// Line 467, Address: 0x12c340, Func Offset: 0x6d0
	// Line 468, Address: 0x12c344, Func Offset: 0x6d4
	// Line 465, Address: 0x12c348, Func Offset: 0x6d8
	// Line 466, Address: 0x12c350, Func Offset: 0x6e0
	// Line 467, Address: 0x12c360, Func Offset: 0x6f0
	// Line 468, Address: 0x12c36c, Func Offset: 0x6fc
	// Line 469, Address: 0x12c388, Func Offset: 0x718
	// Line 470, Address: 0x12c390, Func Offset: 0x720
	// Line 471, Address: 0x12c3a8, Func Offset: 0x738
	// Line 472, Address: 0x12c3c0, Func Offset: 0x750
	// Line 473, Address: 0x12c3d4, Func Offset: 0x764
	// Line 474, Address: 0x12c3dc, Func Offset: 0x76c
	// Line 475, Address: 0x12c3e4, Func Offset: 0x774
	// Line 476, Address: 0x12c3ec, Func Offset: 0x77c
	// Line 478, Address: 0x12c3f4, Func Offset: 0x784
	// Line 481, Address: 0x12c3fc, Func Offset: 0x78c
	// Line 482, Address: 0x12c400, Func Offset: 0x790
	// Func End, Address: 0x12c43c, Func Offset: 0x7cc
}

// 
// Start address: 0x12c440
int npCollisionCheckSC(_anon6* sa, _anon4* cpb)
{
	float sca;
	float lenb;
	float lr;
	float inn;
	_anon1 vec;
	_anon6 sb;
	_anon21 lnb;
	// Line 493, Address: 0x12c440, Func Offset: 0
	// Line 498, Address: 0x12c470, Func Offset: 0x30
	// Line 499, Address: 0x12c478, Func Offset: 0x38
	// Line 500, Address: 0x12c47c, Func Offset: 0x3c
	// Line 501, Address: 0x12c480, Func Offset: 0x40
	// Line 498, Address: 0x12c484, Func Offset: 0x44
	// Line 499, Address: 0x12c488, Func Offset: 0x48
	// Line 500, Address: 0x12c48c, Func Offset: 0x4c
	// Line 502, Address: 0x12c490, Func Offset: 0x50
	// Line 505, Address: 0x12c498, Func Offset: 0x58
	// Line 500, Address: 0x12c49c, Func Offset: 0x5c
	// Line 501, Address: 0x12c4a0, Func Offset: 0x60
	// Line 502, Address: 0x12c4ac, Func Offset: 0x6c
	// Line 503, Address: 0x12c4bc, Func Offset: 0x7c
	// Line 504, Address: 0x12c4cc, Func Offset: 0x8c
	// Line 505, Address: 0x12c4d4, Func Offset: 0x94
	// Line 504, Address: 0x12c4d8, Func Offset: 0x98
	// Line 505, Address: 0x12c4dc, Func Offset: 0x9c
	// Line 506, Address: 0x12c4e4, Func Offset: 0xa4
	// Line 507, Address: 0x12c4e8, Func Offset: 0xa8
	// Line 509, Address: 0x12c4f8, Func Offset: 0xb8
	// Line 510, Address: 0x12c500, Func Offset: 0xc0
	// Line 511, Address: 0x12c504, Func Offset: 0xc4
	// Line 512, Address: 0x12c508, Func Offset: 0xc8
	// Line 509, Address: 0x12c50c, Func Offset: 0xcc
	// Line 510, Address: 0x12c514, Func Offset: 0xd4
	// Line 511, Address: 0x12c524, Func Offset: 0xe4
	// Line 512, Address: 0x12c530, Func Offset: 0xf0
	// Line 513, Address: 0x12c538, Func Offset: 0xf8
	// Line 514, Address: 0x12c544, Func Offset: 0x104
	// Line 515, Address: 0x12c54c, Func Offset: 0x10c
	// Line 516, Address: 0x12c558, Func Offset: 0x118
	// Line 517, Address: 0x12c570, Func Offset: 0x130
	// Line 518, Address: 0x12c58c, Func Offset: 0x14c
	// Line 519, Address: 0x12c59c, Func Offset: 0x15c
	// Line 520, Address: 0x12c5a4, Func Offset: 0x164
	// Line 521, Address: 0x12c5ac, Func Offset: 0x16c
	// Line 523, Address: 0x12c5b0, Func Offset: 0x170
	// Line 524, Address: 0x12c5b8, Func Offset: 0x178
	// Line 525, Address: 0x12c5d0, Func Offset: 0x190
	// Line 526, Address: 0x12c5d8, Func Offset: 0x198
	// Line 527, Address: 0x12c5e0, Func Offset: 0x1a0
	// Line 538, Address: 0x12c5e8, Func Offset: 0x1a8
	// Line 540, Address: 0x12c600, Func Offset: 0x1c0
	// Func End, Address: 0x12c634, Func Offset: 0x1f4
}

// 
// Start address: 0x12c640
void npDistanceP2C(_anon1* pos, _anon4* cap, _anon1* htp)
{
	float sca;
	float len;
	float inn;
	_anon1 vec;
	_anon21 ln;
	// Line 549, Address: 0x12c640, Func Offset: 0
	// Line 553, Address: 0x12c670, Func Offset: 0x30
	// Line 554, Address: 0x12c674, Func Offset: 0x34
	// Line 555, Address: 0x12c678, Func Offset: 0x38
	// Line 556, Address: 0x12c67c, Func Offset: 0x3c
	// Line 553, Address: 0x12c680, Func Offset: 0x40
	// Line 554, Address: 0x12c684, Func Offset: 0x44
	// Line 555, Address: 0x12c698, Func Offset: 0x58
	// Line 556, Address: 0x12c6a0, Func Offset: 0x60
	// Line 557, Address: 0x12c6b0, Func Offset: 0x70
	// Line 558, Address: 0x12c6c0, Func Offset: 0x80
	// Line 559, Address: 0x12c6c8, Func Offset: 0x88
	// Line 558, Address: 0x12c6cc, Func Offset: 0x8c
	// Line 559, Address: 0x12c6d0, Func Offset: 0x90
	// Line 560, Address: 0x12c6d8, Func Offset: 0x98
	// Line 562, Address: 0x12c6e4, Func Offset: 0xa4
	// Line 563, Address: 0x12c6ec, Func Offset: 0xac
	// Line 564, Address: 0x12c6f0, Func Offset: 0xb0
	// Line 565, Address: 0x12c6f4, Func Offset: 0xb4
	// Line 562, Address: 0x12c6f8, Func Offset: 0xb8
	// Line 563, Address: 0x12c700, Func Offset: 0xc0
	// Line 564, Address: 0x12c710, Func Offset: 0xd0
	// Line 565, Address: 0x12c71c, Func Offset: 0xdc
	// Line 566, Address: 0x12c724, Func Offset: 0xe4
	// Line 567, Address: 0x12c730, Func Offset: 0xf0
	// Line 568, Address: 0x12c738, Func Offset: 0xf8
	// Line 569, Address: 0x12c744, Func Offset: 0x104
	// Line 570, Address: 0x12c75c, Func Offset: 0x11c
	// Line 571, Address: 0x12c76c, Func Offset: 0x12c
	// Line 572, Address: 0x12c774, Func Offset: 0x134
	// Line 573, Address: 0x12c77c, Func Offset: 0x13c
	// Line 575, Address: 0x12c780, Func Offset: 0x140
	// Line 576, Address: 0x12c788, Func Offset: 0x148
	// Line 577, Address: 0x12c790, Func Offset: 0x150
	// Line 578, Address: 0x12c798, Func Offset: 0x158
	// Line 580, Address: 0x12c7a0, Func Offset: 0x160
	// Line 583, Address: 0x12c7a8, Func Offset: 0x168
	// Line 580, Address: 0x12c7ac, Func Offset: 0x16c
	// Line 581, Address: 0x12c7b4, Func Offset: 0x174
	// Line 582, Address: 0x12c7c4, Func Offset: 0x184
	// Line 583, Address: 0x12c7d0, Func Offset: 0x190
	// Line 584, Address: 0x12c7d8, Func Offset: 0x198
	// Line 585, Address: 0x12c7ec, Func Offset: 0x1ac
	// Line 586, Address: 0x12c7f4, Func Offset: 0x1b4
	// Line 587, Address: 0x12c80c, Func Offset: 0x1cc
	// Line 588, Address: 0x12c824, Func Offset: 0x1e4
	// Line 589, Address: 0x12c838, Func Offset: 0x1f8
	// Line 590, Address: 0x12c840, Func Offset: 0x200
	// Line 591, Address: 0x12c848, Func Offset: 0x208
	// Line 592, Address: 0x12c850, Func Offset: 0x210
	// Line 594, Address: 0x12c858, Func Offset: 0x218
	// Func End, Address: 0x12c88c, Func Offset: 0x24c
}

// 
// Start address: 0x12c890
void npDrawPlane(_anon1* ps0, _anon1* ps1, _anon1* ps2, _anon1* ps3, unsigned int argb)
{
	_anon10 col[4];
	_anon1 p3[4];
	_anon19 p3c;
	// Line 1112, Address: 0x12c890, Func Offset: 0
	// Line 1117, Address: 0x12c894, Func Offset: 0x4
	// Line 1119, Address: 0x12c8a4, Func Offset: 0x14
	// Line 1120, Address: 0x12c8ac, Func Offset: 0x1c
	// Line 1122, Address: 0x12c8b8, Func Offset: 0x28
	// Line 1121, Address: 0x12c8bc, Func Offset: 0x2c
	// Line 1122, Address: 0x12c8c0, Func Offset: 0x30
	// Line 1123, Address: 0x12c8c4, Func Offset: 0x34
	// Line 1124, Address: 0x12c8cc, Func Offset: 0x3c
	// Line 1125, Address: 0x12c8d4, Func Offset: 0x44
	// Line 1126, Address: 0x12c8dc, Func Offset: 0x4c
	// Line 1127, Address: 0x12c8e4, Func Offset: 0x54
	// Line 1128, Address: 0x12c8ec, Func Offset: 0x5c
	// Line 1129, Address: 0x12c8f4, Func Offset: 0x64
	// Line 1130, Address: 0x12c8fc, Func Offset: 0x6c
	// Line 1139, Address: 0x12c900, Func Offset: 0x70
	// Line 1130, Address: 0x12c904, Func Offset: 0x74
	// Line 1131, Address: 0x12c908, Func Offset: 0x78
	// Line 1132, Address: 0x12c910, Func Offset: 0x80
	// Line 1133, Address: 0x12c918, Func Offset: 0x88
	// Line 1139, Address: 0x12c91c, Func Offset: 0x8c
	// Line 1133, Address: 0x12c920, Func Offset: 0x90
	// Line 1134, Address: 0x12c924, Func Offset: 0x94
	// Line 1135, Address: 0x12c92c, Func Offset: 0x9c
	// Line 1136, Address: 0x12c934, Func Offset: 0xa4
	// Line 1139, Address: 0x12c938, Func Offset: 0xa8
	// Line 1136, Address: 0x12c93c, Func Offset: 0xac
	// Line 1137, Address: 0x12c940, Func Offset: 0xb0
	// Line 1138, Address: 0x12c948, Func Offset: 0xb8
	// Line 1139, Address: 0x12c94c, Func Offset: 0xbc
	// Line 1140, Address: 0x12c954, Func Offset: 0xc4
	// Func End, Address: 0x12c960, Func Offset: 0xd0
}

// 
// Start address: 0x12c960
void npCalcMorphing(npobj* obj_a, npobj* obj_b, float no, int obj_n)
{
	unsigned int ulSize;
	int nb;
	int i;
	// Line 1794, Address: 0x12c960, Func Offset: 0
	// Line 1800, Address: 0x12c990, Func Offset: 0x30
	// Line 1801, Address: 0x12c998, Func Offset: 0x38
	// Line 1802, Address: 0x12c9a8, Func Offset: 0x48
	// Line 1813, Address: 0x12c9bc, Func Offset: 0x5c
	// Line 1814, Address: 0x12c9d8, Func Offset: 0x78
	// Line 1823, Address: 0x12c9ec, Func Offset: 0x8c
	// Line 1825, Address: 0x12c9f0, Func Offset: 0x90
	// Line 1814, Address: 0x12c9f4, Func Offset: 0x94
	// Line 1827, Address: 0x12c9f8, Func Offset: 0x98
	// Line 1814, Address: 0x12ca04, Func Offset: 0xa4
	// Line 1816, Address: 0x12ca14, Func Offset: 0xb4
	// Line 1827, Address: 0x12ca1c, Func Offset: 0xbc
	// Line 1816, Address: 0x12ca20, Func Offset: 0xc0
	// Line 1818, Address: 0x12ca34, Func Offset: 0xd4
	// Line 1822, Address: 0x12ca50, Func Offset: 0xf0
	// Line 1823, Address: 0x12ca54, Func Offset: 0xf4
	// Line 1822, Address: 0x12ca58, Func Offset: 0xf8
	// Line 1826, Address: 0x12ca5c, Func Offset: 0xfc
	// Line 1822, Address: 0x12ca60, Func Offset: 0x100
	// Line 1823, Address: 0x12ca64, Func Offset: 0x104
	// Line 1824, Address: 0x12ca68, Func Offset: 0x108
	// Line 1826, Address: 0x12ca70, Func Offset: 0x110
	// Line 1825, Address: 0x12ca74, Func Offset: 0x114
	// Line 1826, Address: 0x12ca80, Func Offset: 0x120
	// Line 1827, Address: 0x12ca88, Func Offset: 0x128
	// Line 1829, Address: 0x12ca90, Func Offset: 0x130
	// Line 1827, Address: 0x12ca94, Func Offset: 0x134
	// Line 1829, Address: 0x12ca98, Func Offset: 0x138
	// Line 1830, Address: 0x12caa8, Func Offset: 0x148
	// Line 1831, Address: 0x12cab0, Func Offset: 0x150
	// Func End, Address: 0x12cad4, Func Offset: 0x174
}

// 
// Start address: 0x12cae0
void npTransform(npobj* srcobj, npobj* dstobj, float no, int ono)
{
	int s_nb;
	_anon0* fp;
	_anon0* dp;
	_anon0* sp;
	_anon3* pDst;
	_anon3* pSrc;
	// Line 1891, Address: 0x12cae0, Func Offset: 0
	// Line 1887, Address: 0x12cae4, Func Offset: 0x4
	// Line 1891, Address: 0x12cae8, Func Offset: 0x8
	// Line 1887, Address: 0x12caec, Func Offset: 0xc
	// Line 1895, Address: 0x12caf0, Func Offset: 0x10
	// Line 1889, Address: 0x12caf4, Func Offset: 0x14
	// Line 1895, Address: 0x12caf8, Func Offset: 0x18
	// Line 1909, Address: 0x12cb00, Func Offset: 0x20
	// Line 1913, Address: 0x12cb08, Func Offset: 0x28
	// Line 1909, Address: 0x12cb0c, Func Offset: 0x2c
	// Line 1898, Address: 0x12cb14, Func Offset: 0x34
	// Line 1909, Address: 0x12cb18, Func Offset: 0x38
	// Line 1911, Address: 0x12cb1c, Func Offset: 0x3c
	// Line 1897, Address: 0x12cb20, Func Offset: 0x40
	// Line 1926, Address: 0x12cb24, Func Offset: 0x44
	// Line 1911, Address: 0x12cb30, Func Offset: 0x50
	// Line 1913, Address: 0x12cb34, Func Offset: 0x54
	// Line 1914, Address: 0x12cb38, Func Offset: 0x58
	// Line 1926, Address: 0x12cb3c, Func Offset: 0x5c
	// Line 1914, Address: 0x12cb40, Func Offset: 0x60
	// Line 1915, Address: 0x12cb44, Func Offset: 0x64
	// Line 1916, Address: 0x12cb4c, Func Offset: 0x6c
	// Line 1917, Address: 0x12cb54, Func Offset: 0x74
	// Line 1928, Address: 0x12cb58, Func Offset: 0x78
	// Line 1929, Address: 0x12cb60, Func Offset: 0x80
	// Line 1951, Address: 0x12cba8, Func Offset: 0xc8
	// Line 1952, Address: 0x12cbac, Func Offset: 0xcc
	// Line 1953, Address: 0x12cbb0, Func Offset: 0xd0
	// Line 1954, Address: 0x12cbb4, Func Offset: 0xd4
	// Line 1955, Address: 0x12cbb8, Func Offset: 0xd8
	// Line 1956, Address: 0x12cbbc, Func Offset: 0xdc
	// Line 1957, Address: 0x12cbc0, Func Offset: 0xe0
	// Line 1958, Address: 0x12cbc4, Func Offset: 0xe4
	// Line 1959, Address: 0x12cbc8, Func Offset: 0xe8
	// Line 1960, Address: 0x12cbcc, Func Offset: 0xec
	// Line 1961, Address: 0x12cbd0, Func Offset: 0xf0
	// Line 1962, Address: 0x12cbd4, Func Offset: 0xf4
	// Line 1963, Address: 0x12cbd8, Func Offset: 0xf8
	// Line 1964, Address: 0x12cbdc, Func Offset: 0xfc
	// Line 1966, Address: 0x12cbe0, Func Offset: 0x100
	// Line 1967, Address: 0x12cbe4, Func Offset: 0x104
	// Line 1970, Address: 0x12cbe8, Func Offset: 0x108
	// Line 1988, Address: 0x12cbf0, Func Offset: 0x110
	// Line 1989, Address: 0x12cbf4, Func Offset: 0x114
	// Line 1990, Address: 0x12cbf8, Func Offset: 0x118
	// Line 1991, Address: 0x12cbfc, Func Offset: 0x11c
	// Line 1993, Address: 0x12cc00, Func Offset: 0x120
	// Line 1994, Address: 0x12cc04, Func Offset: 0x124
	// Line 1995, Address: 0x12cc08, Func Offset: 0x128
	// Line 1997, Address: 0x12cc0c, Func Offset: 0x12c
	// Line 1998, Address: 0x12cc10, Func Offset: 0x130
	// Line 2000, Address: 0x12cc20, Func Offset: 0x140
	// Line 2002, Address: 0x12cc28, Func Offset: 0x148
	// Line 2003, Address: 0x12cc44, Func Offset: 0x164
	// Func End, Address: 0x12cc4c, Func Offset: 0x16c
}

// 
// Start address: 0x12cc50
void npPushMdlstr(npobj* objp, int obj_n)
{
	int i;
	// Line 2174, Address: 0x12cc50, Func Offset: 0
	// Line 2175, Address: 0x12cc64, Func Offset: 0x14
	// Line 2176, Address: 0x12cc78, Func Offset: 0x28
	// Line 2175, Address: 0x12cc7c, Func Offset: 0x2c
	// Line 2176, Address: 0x12cc80, Func Offset: 0x30
	// Line 2177, Address: 0x12cc90, Func Offset: 0x40
	// Func End, Address: 0x12cc98, Func Offset: 0x48
}

// 
// Start address: 0x12cca0
void npPopMdlstr(npobj* objp, int obj_n)
{
	int i;
	// Line 2185, Address: 0x12cca0, Func Offset: 0
	// Line 2186, Address: 0x12ccb4, Func Offset: 0x14
	// Line 2187, Address: 0x12ccc8, Func Offset: 0x28
	// Line 2186, Address: 0x12cccc, Func Offset: 0x2c
	// Line 2187, Address: 0x12ccd0, Func Offset: 0x30
	// Line 2188, Address: 0x12cce0, Func Offset: 0x40
	// Func End, Address: 0x12cce8, Func Offset: 0x48
}

// 
// Start address: 0x12ccf0
void npPushMdlstr2(npobj* objp, int obj_n)
{
	int i;
	// Line 2196, Address: 0x12ccf0, Func Offset: 0
	// Line 2197, Address: 0x12cd04, Func Offset: 0x14
	// Line 2199, Address: 0x12cd20, Func Offset: 0x30
	// Line 2200, Address: 0x12cd28, Func Offset: 0x38
	// Line 2201, Address: 0x12cd30, Func Offset: 0x40
	// Line 2202, Address: 0x12cd38, Func Offset: 0x48
	// Line 2203, Address: 0x12cd44, Func Offset: 0x54
	// Line 2205, Address: 0x12cd50, Func Offset: 0x60
	// Line 2203, Address: 0x12cd54, Func Offset: 0x64
	// Line 2205, Address: 0x12cd58, Func Offset: 0x68
	// Line 2206, Address: 0x12cd68, Func Offset: 0x78
	// Func End, Address: 0x12cd70, Func Offset: 0x80
}

// 
// Start address: 0x12cd70
void npPopMdlstr2(npobj* objp, int obj_n)
{
	int i;
	// Line 2214, Address: 0x12cd70, Func Offset: 0
	// Line 2215, Address: 0x12cd84, Func Offset: 0x14
	// Line 2217, Address: 0x12cda0, Func Offset: 0x30
	// Line 2218, Address: 0x12cda8, Func Offset: 0x38
	// Line 2219, Address: 0x12cdb0, Func Offset: 0x40
	// Line 2220, Address: 0x12cdb8, Func Offset: 0x48
	// Line 2221, Address: 0x12cdc4, Func Offset: 0x54
	// Line 2223, Address: 0x12cdd0, Func Offset: 0x60
	// Line 2221, Address: 0x12cdd4, Func Offset: 0x64
	// Line 2223, Address: 0x12cdd8, Func Offset: 0x68
	// Line 2224, Address: 0x12cde8, Func Offset: 0x78
	// Func End, Address: 0x12cdf0, Func Offset: 0x80
}

// 
// Start address: 0x12cdf0
void npCnkFlatOff(npobj* objp)
{
	short head;
	short* plP;
	int offset;
	// Line 2268, Address: 0x12cdf0, Func Offset: 0
	// Line 2272, Address: 0x12cdfc, Func Offset: 0xc
	// Line 2273, Address: 0x12ce08, Func Offset: 0x18
	// Line 2281, Address: 0x12ce10, Func Offset: 0x20
	// Line 2277, Address: 0x12ce14, Func Offset: 0x24
	// Line 2291, Address: 0x12ce18, Func Offset: 0x28
	// Line 2275, Address: 0x12ce1c, Func Offset: 0x2c
	// Line 2276, Address: 0x12ce28, Func Offset: 0x38
	// Line 2277, Address: 0x12ce40, Func Offset: 0x50
	// Line 2278, Address: 0x12ce4c, Func Offset: 0x5c
	// Line 2279, Address: 0x12ce54, Func Offset: 0x64
	// Line 2280, Address: 0x12ce58, Func Offset: 0x68
	// Line 2281, Address: 0x12ce60, Func Offset: 0x70
	// Line 2283, Address: 0x12ce70, Func Offset: 0x80
	// Line 2284, Address: 0x12ce88, Func Offset: 0x98
	// Line 2285, Address: 0x12ce90, Func Offset: 0xa0
	// Line 2286, Address: 0x12ce94, Func Offset: 0xa4
	// Line 2287, Address: 0x12ce9c, Func Offset: 0xac
	// Line 2288, Address: 0x12ceb4, Func Offset: 0xc4
	// Line 2289, Address: 0x12cebc, Func Offset: 0xcc
	// Line 2290, Address: 0x12cec0, Func Offset: 0xd0
	// Line 2291, Address: 0x12cec8, Func Offset: 0xd8
	// Line 2294, Address: 0x12ced0, Func Offset: 0xe0
	// Line 2295, Address: 0x12cee4, Func Offset: 0xf4
	// Line 2296, Address: 0x12cef8, Func Offset: 0x108
	// Func End, Address: 0x12cf08, Func Offset: 0x118
}

// 
// Start address: 0x12cf10
void npClrTranslate()
{
	// Line 2337, Address: 0x12cf10, Func Offset: 0
	// Line 2339, Address: 0x12cf14, Func Offset: 0x4
	// Line 2337, Address: 0x12cf18, Func Offset: 0x8
	// Line 2339, Address: 0x12cf1c, Func Offset: 0xc
	// Line 2340, Address: 0x12cf24, Func Offset: 0x14
	// Line 2341, Address: 0x12cf2c, Func Offset: 0x1c
	// Line 2343, Address: 0x12cf30, Func Offset: 0x20
	// Line 2341, Address: 0x12cf34, Func Offset: 0x24
	// Line 2342, Address: 0x12cf38, Func Offset: 0x28
	// Line 2343, Address: 0x12cf3c, Func Offset: 0x2c
	// Line 2344, Address: 0x12cf4c, Func Offset: 0x3c
	// Func End, Address: 0x12cf58, Func Offset: 0x48
}

// 100% matching!
void npSetMemory(unsigned char* memp, unsigned int size, char dat)
{
    while (size-- != 0) 
    {
        *memp++ = dat;
    }
}

// 100% matching!
void npSetMemoryL(unsigned int* memp, unsigned int size, int dat) 
{ 
    while (size-- != 0) 
    {
        *memp++ = dat;
    }
}

// 100% matching!
void npCopyMemory(unsigned char* dst, unsigned char* src, unsigned int size)
{
    while (size-- != 0)
    {
        *dst++ = *src++;
    }
}

// 
// Start address: 0x12cff0
void npGetWHDSizeSub(npobj* objp, _anon1* whd)
{
	_anon3* pHdrPs;
	_anon2* pHdrCv;
	int i;
	_anon0 pd4;
	_anon0* ps4;
	_anon1 pd3;
	_anon1* ps3;
	// Line 2389, Address: 0x12cff0, Func Offset: 0
	// Line 2397, Address: 0x12d010, Func Offset: 0x20
	// Line 2398, Address: 0x12d01c, Func Offset: 0x2c
	// Line 2399, Address: 0x12d030, Func Offset: 0x40
	// Line 2402, Address: 0x12d044, Func Offset: 0x54
	// Line 2404, Address: 0x12d060, Func Offset: 0x70
	// Line 2420, Address: 0x12d064, Func Offset: 0x74
	// Line 2424, Address: 0x12d074, Func Offset: 0x84
	// Line 2423, Address: 0x12d078, Func Offset: 0x88
	// Line 2425, Address: 0x12d07c, Func Offset: 0x8c
	// Line 2427, Address: 0x12d084, Func Offset: 0x94
	// Line 2428, Address: 0x12d094, Func Offset: 0xa4
	// Line 2429, Address: 0x12d0c0, Func Offset: 0xd0
	// Line 2430, Address: 0x12d0f0, Func Offset: 0x100
	// Line 2446, Address: 0x12d120, Func Offset: 0x130
	// Line 2445, Address: 0x12d124, Func Offset: 0x134
	// Line 2446, Address: 0x12d128, Func Offset: 0x138
	// Line 2447, Address: 0x12d130, Func Offset: 0x140
	// Line 2451, Address: 0x12d138, Func Offset: 0x148
	// Line 2450, Address: 0x12d13c, Func Offset: 0x14c
	// Line 2452, Address: 0x12d140, Func Offset: 0x150
	// Line 2454, Address: 0x12d148, Func Offset: 0x158
	// Line 2455, Address: 0x12d158, Func Offset: 0x168
	// Line 2456, Address: 0x12d180, Func Offset: 0x190
	// Line 2457, Address: 0x12d1b0, Func Offset: 0x1c0
	// Line 2477, Address: 0x12d1e0, Func Offset: 0x1f0
	// Line 2476, Address: 0x12d1e4, Func Offset: 0x1f4
	// Line 2477, Address: 0x12d1e8, Func Offset: 0x1f8
	// Line 2492, Address: 0x12d1f0, Func Offset: 0x200
	// Line 2493, Address: 0x12d204, Func Offset: 0x214
	// Line 2494, Address: 0x12d210, Func Offset: 0x220
	// Line 2495, Address: 0x12d224, Func Offset: 0x234
	// Func End, Address: 0x12d244, Func Offset: 0x254
}

// 
// Start address: 0x12d250
void npGetWHDSize(npobj* objp, _anon1* whd)
{
	// Line 2529, Address: 0x12d250, Func Offset: 0
	// Line 2530, Address: 0x12d260, Func Offset: 0x10
	// Line 2531, Address: 0x12d274, Func Offset: 0x24
	// Line 2532, Address: 0x12d27c, Func Offset: 0x2c
	// Line 2533, Address: 0x12d288, Func Offset: 0x38
	// Func End, Address: 0x12d29c, Func Offset: 0x4c
}

// 
// Start address: 0x12d2a0
void npSkinConvPreparation(npobj* objp)
{
	int nb;
	int mno;
	int flg;
	_anon1 ps;
	// Line 2539, Address: 0x12d2a0, Func Offset: 0
	// Line 2540, Address: 0x12d2b0, Func Offset: 0x10
	// Line 2539, Address: 0x12d2b4, Func Offset: 0x14
	// Line 2540, Address: 0x12d2b8, Func Offset: 0x18
	// Line 2539, Address: 0x12d2bc, Func Offset: 0x1c
	// Line 2540, Address: 0x12d2c0, Func Offset: 0x20
	// Line 2542, Address: 0x12d2d0, Func Offset: 0x30
	// Line 2543, Address: 0x12d2dc, Func Offset: 0x3c
	// Line 2544, Address: 0x12d2f0, Func Offset: 0x50
	// Line 2545, Address: 0x12d304, Func Offset: 0x64
	// Line 2546, Address: 0x12d30c, Func Offset: 0x6c
	// Line 2547, Address: 0x12d318, Func Offset: 0x78
	// Line 2549, Address: 0x12d320, Func Offset: 0x80
	// Line 2550, Address: 0x12d328, Func Offset: 0x88
	// Line 2547, Address: 0x12d330, Func Offset: 0x90
	// Line 2548, Address: 0x12d340, Func Offset: 0xa0
	// Line 2549, Address: 0x12d348, Func Offset: 0xa8
	// Line 2550, Address: 0x12d350, Func Offset: 0xb0
	// Line 2548, Address: 0x12d354, Func Offset: 0xb4
	// Line 2549, Address: 0x12d364, Func Offset: 0xc4
	// Line 2550, Address: 0x12d368, Func Offset: 0xc8
	// Line 2551, Address: 0x12d370, Func Offset: 0xd0
	// Line 2550, Address: 0x12d374, Func Offset: 0xd4
	// Line 2551, Address: 0x12d378, Func Offset: 0xd8
	// Line 2552, Address: 0x12d388, Func Offset: 0xe8
	// Line 2553, Address: 0x12d390, Func Offset: 0xf0
	// Line 2556, Address: 0x12d3a8, Func Offset: 0x108
	// Line 2558, Address: 0x12d3bc, Func Offset: 0x11c
	// Line 2559, Address: 0x12d3c8, Func Offset: 0x128
	// Line 2562, Address: 0x12d3f0, Func Offset: 0x150
	// Line 2563, Address: 0x12d404, Func Offset: 0x164
	// Line 2564, Address: 0x12d410, Func Offset: 0x170
	// Line 2565, Address: 0x12d424, Func Offset: 0x184
	// Func End, Address: 0x12d43c, Func Offset: 0x19c
}

// 
// Start address: 0x12d440
void npSkinConvSub(NJS_CNK_OBJECT* objp)
{
	_anon3* pHdr;
	int mno;
	int flg;
	int dt;
	int i;
	int nb;
	int* skp;
	_anon0* p0;
	_anon0 pd;
	_anon0 ps;
	// Line 2569, Address: 0x12d440, Func Offset: 0
	// Line 2571, Address: 0x12d44c, Func Offset: 0xc
	// Line 2569, Address: 0x12d450, Func Offset: 0x10
	// Line 2571, Address: 0x12d454, Func Offset: 0x14
	// Line 2569, Address: 0x12d458, Func Offset: 0x18
	// Line 2571, Address: 0x12d460, Func Offset: 0x20
	// Line 2581, Address: 0x12d468, Func Offset: 0x28
	// Line 2571, Address: 0x12d46c, Func Offset: 0x2c
	// Line 2581, Address: 0x12d470, Func Offset: 0x30
	// Line 2582, Address: 0x12d480, Func Offset: 0x40
	// Line 2583, Address: 0x12d488, Func Offset: 0x48
	// Line 2584, Address: 0x12d494, Func Offset: 0x54
	// Line 2585, Address: 0x12d49c, Func Offset: 0x5c
	// Line 2584, Address: 0x12d4a0, Func Offset: 0x60
	// Line 2585, Address: 0x12d4a8, Func Offset: 0x68
	// Line 2586, Address: 0x12d4bc, Func Offset: 0x7c
	// Line 2588, Address: 0x12d4d4, Func Offset: 0x94
	// Line 2589, Address: 0x12d4e8, Func Offset: 0xa8
	// Line 2590, Address: 0x12d4f0, Func Offset: 0xb0
	// Line 2592, Address: 0x12d508, Func Offset: 0xc8
	// Line 2594, Address: 0x12d520, Func Offset: 0xe0
	// Line 2596, Address: 0x12d534, Func Offset: 0xf4
	// Line 2597, Address: 0x12d540, Func Offset: 0x100
	// Line 2598, Address: 0x12d544, Func Offset: 0x104
	// Line 2597, Address: 0x12d54c, Func Offset: 0x10c
	// Line 2598, Address: 0x12d550, Func Offset: 0x110
	// Line 2599, Address: 0x12d558, Func Offset: 0x118
	// Line 2601, Address: 0x12d564, Func Offset: 0x124
	// Line 2605, Address: 0x12d578, Func Offset: 0x138
	// Line 2601, Address: 0x12d57c, Func Offset: 0x13c
	// Line 2603, Address: 0x12d584, Func Offset: 0x144
	// Line 2605, Address: 0x12d588, Func Offset: 0x148
	// Line 2606, Address: 0x12d5ac, Func Offset: 0x16c
	// Line 2608, Address: 0x12d5b0, Func Offset: 0x170
	// Line 2612, Address: 0x12d5c4, Func Offset: 0x184
	// Line 2610, Address: 0x12d5d0, Func Offset: 0x190
	// Line 2611, Address: 0x12d5d8, Func Offset: 0x198
	// Line 2612, Address: 0x12d5e0, Func Offset: 0x1a0
	// Line 2613, Address: 0x12d5ec, Func Offset: 0x1ac
	// Line 2610, Address: 0x12d5f0, Func Offset: 0x1b0
	// Line 2611, Address: 0x12d5f4, Func Offset: 0x1b4
	// Line 2613, Address: 0x12d5f8, Func Offset: 0x1b8
	// Line 2614, Address: 0x12d600, Func Offset: 0x1c0
	// Line 2615, Address: 0x12d60c, Func Offset: 0x1cc
	// Line 2618, Address: 0x12d610, Func Offset: 0x1d0
	// Line 2620, Address: 0x12d620, Func Offset: 0x1e0
	// Func End, Address: 0x12d638, Func Offset: 0x1f8
}

// 100% matching!
void npSkinConvMain(NJS_CNK_OBJECT* objp)
{
    njPushMatrix(NULL);
    
    if (!(objp->evalflags & 0x20000000)) 
    {
        npSkinConvSub(objp);
        
        np.obj_now++;
    }
    
    if (objp->child != NULL) 
    {
        npSkinConvMain(objp->child);
    }
    
    njPopMatrix(1);
    
    if (objp->sibling != NULL) 
    {
        npSkinConvMain(objp->sibling);
    }
}

// 
// Start address: 0x12d6d0
void npSkinConvert(npobj* objp, int* sknp)
{
	// Line 2686, Address: 0x12d6d0, Func Offset: 0
	// Line 2687, Address: 0x12d6e8, Func Offset: 0x18
	// Line 2688, Address: 0x12d6ec, Func Offset: 0x1c
	// Line 2689, Address: 0x12d6f8, Func Offset: 0x28
	// Line 2690, Address: 0x12d700, Func Offset: 0x30
	// Line 2691, Address: 0x12d708, Func Offset: 0x38
	// Line 2692, Address: 0x12d70c, Func Offset: 0x3c
	// Line 2693, Address: 0x12d718, Func Offset: 0x48
	// Line 2694, Address: 0x12d720, Func Offset: 0x50
	// Func End, Address: 0x12d734, Func Offset: 0x64
}

// 
// Start address: 0x12d740
void npRetSkinConvMain(npobj* objp)
{
	_anon3* pHdr;
	int mno;
	int flg;
	int dt;
	int i;
	int nb;
	int* skp;
	_anon0* p0;
	_anon0 pd;
	_anon0 ps;
	// Line 2701, Address: 0x12d740, Func Offset: 0
	// Line 2703, Address: 0x12d750, Func Offset: 0x10
	// Line 2701, Address: 0x12d754, Func Offset: 0x14
	// Line 2703, Address: 0x12d758, Func Offset: 0x18
	// Line 2701, Address: 0x12d75c, Func Offset: 0x1c
	// Line 2703, Address: 0x12d760, Func Offset: 0x20
	// Line 2712, Address: 0x12d76c, Func Offset: 0x2c
	// Line 2713, Address: 0x12d778, Func Offset: 0x38
	// Line 2715, Address: 0x12d78c, Func Offset: 0x4c
	// Line 2716, Address: 0x12d7a0, Func Offset: 0x60
	// Line 2717, Address: 0x12d7a8, Func Offset: 0x68
	// Line 2718, Address: 0x12d7b4, Func Offset: 0x74
	// Line 2719, Address: 0x12d7cc, Func Offset: 0x8c
	// Line 2720, Address: 0x12d7e4, Func Offset: 0xa4
	// Line 2721, Address: 0x12d7f8, Func Offset: 0xb8
	// Line 2722, Address: 0x12d800, Func Offset: 0xc0
	// Line 2724, Address: 0x12d818, Func Offset: 0xd8
	// Line 2726, Address: 0x12d830, Func Offset: 0xf0
	// Line 2727, Address: 0x12d844, Func Offset: 0x104
	// Line 2728, Address: 0x12d850, Func Offset: 0x110
	// Line 2729, Address: 0x12d854, Func Offset: 0x114
	// Line 2728, Address: 0x12d85c, Func Offset: 0x11c
	// Line 2729, Address: 0x12d860, Func Offset: 0x120
	// Line 2730, Address: 0x12d868, Func Offset: 0x128
	// Line 2732, Address: 0x12d874, Func Offset: 0x134
	// Line 2736, Address: 0x12d888, Func Offset: 0x148
	// Line 2732, Address: 0x12d88c, Func Offset: 0x14c
	// Line 2734, Address: 0x12d894, Func Offset: 0x154
	// Line 2736, Address: 0x12d898, Func Offset: 0x158
	// Line 2737, Address: 0x12d8bc, Func Offset: 0x17c
	// Line 2739, Address: 0x12d8c0, Func Offset: 0x180
	// Line 2740, Address: 0x12d8d4, Func Offset: 0x194
	// Line 2741, Address: 0x12d8ec, Func Offset: 0x1ac
	// Line 2742, Address: 0x12d904, Func Offset: 0x1c4
	// Line 2743, Address: 0x12d91c, Func Offset: 0x1dc
	// Line 2746, Address: 0x12d920, Func Offset: 0x1e0
	// Line 2749, Address: 0x12d930, Func Offset: 0x1f0
	// Line 2751, Address: 0x12d944, Func Offset: 0x204
	// Line 2752, Address: 0x12d958, Func Offset: 0x218
	// Line 2753, Address: 0x12d964, Func Offset: 0x224
	// Line 2754, Address: 0x12d978, Func Offset: 0x238
	// Func End, Address: 0x12d994, Func Offset: 0x254
}

// 
// Start address: 0x12d9a0
void npRetSkinConvert(npobj* objp, int* sknp)
{
	// Line 2810, Address: 0x12d9a0, Func Offset: 0
	// Line 2811, Address: 0x12d9b8, Func Offset: 0x18
	// Line 2812, Address: 0x12d9bc, Func Offset: 0x1c
	// Line 2813, Address: 0x12d9c8, Func Offset: 0x28
	// Line 2814, Address: 0x12d9d0, Func Offset: 0x30
	// Line 2815, Address: 0x12d9d8, Func Offset: 0x38
	// Line 2816, Address: 0x12d9dc, Func Offset: 0x3c
	// Line 2817, Address: 0x12d9e8, Func Offset: 0x48
	// Line 2818, Address: 0x12d9f0, Func Offset: 0x50
	// Func End, Address: 0x12da04, Func Offset: 0x64
}

// 
// Start address: 0x12da10
unsigned int npGetMatColor(npobj* objp, int obj_n)
{
	unsigned int* pnt;
	int i;
	// Line 2832, Address: 0x12da10, Func Offset: 0
	// Line 2833, Address: 0x12da1c, Func Offset: 0xc
	// Line 2834, Address: 0x12da38, Func Offset: 0x28
	// Line 2835, Address: 0x12da40, Func Offset: 0x30
	// Line 2837, Address: 0x12da48, Func Offset: 0x38
	// Line 2838, Address: 0x12da58, Func Offset: 0x48
	// Line 2839, Address: 0x12da5c, Func Offset: 0x4c
	// Func End, Address: 0x12da64, Func Offset: 0x54
}

// 
// Start address: 0x12da70
void npSetAllMatColor(npobj* objp, int obj_n, unsigned int argb)
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
	unsigned char* mat;
	short* plp;
	short head;
	int offset;
	int i;
	// Line 2877, Address: 0x12da70, Func Offset: 0
	// Line 2878, Address: 0x12da80, Func Offset: 0x10
	// Line 2871, Address: 0x12da90, Func Offset: 0x20
	// Line 2879, Address: 0x12da94, Func Offset: 0x24
	// Line 2871, Address: 0x12da9c, Func Offset: 0x2c
	// Line 2879, Address: 0x12daa0, Func Offset: 0x30
	// Line 2881, Address: 0x12daa4, Func Offset: 0x34
	// Line 2871, Address: 0x12daa8, Func Offset: 0x38
	// Line 2880, Address: 0x12daac, Func Offset: 0x3c
	// Line 2881, Address: 0x12dab0, Func Offset: 0x40
	// Line 2895, Address: 0x12dab8, Func Offset: 0x48
	// Line 2890, Address: 0x12dac8, Func Offset: 0x58
	// Line 2923, Address: 0x12dacc, Func Offset: 0x5c
	// Line 2882, Address: 0x12dad0, Func Offset: 0x60
	// Line 2883, Address: 0x12daec, Func Offset: 0x7c
	// Line 2884, Address: 0x12daf4, Func Offset: 0x84
	// Line 2885, Address: 0x12daf8, Func Offset: 0x88
	// Line 2886, Address: 0x12db04, Func Offset: 0x94
	// Line 2887, Address: 0x12db1c, Func Offset: 0xac
	// Line 2888, Address: 0x12db24, Func Offset: 0xb4
	// Line 2889, Address: 0x12db28, Func Offset: 0xb8
	// Line 2890, Address: 0x12db30, Func Offset: 0xc0
	// Line 2892, Address: 0x12db40, Func Offset: 0xd0
	// Line 2895, Address: 0x12db58, Func Offset: 0xe8
	// Line 2898, Address: 0x12db80, Func Offset: 0x110
	// Line 2899, Address: 0x12db84, Func Offset: 0x114
	// Line 2900, Address: 0x12db88, Func Offset: 0x118
	// Line 2901, Address: 0x12db8c, Func Offset: 0x11c
	// Line 2902, Address: 0x12db98, Func Offset: 0x128
	// Line 2905, Address: 0x12dba0, Func Offset: 0x130
	// Line 2906, Address: 0x12dba4, Func Offset: 0x134
	// Line 2907, Address: 0x12dba8, Func Offset: 0x138
	// Line 2908, Address: 0x12dbac, Func Offset: 0x13c
	// Line 2909, Address: 0x12dbc0, Func Offset: 0x150
	// Line 2910, Address: 0x12dbc4, Func Offset: 0x154
	// Line 2911, Address: 0x12dbc8, Func Offset: 0x158
	// Line 2912, Address: 0x12dbcc, Func Offset: 0x15c
	// Line 2914, Address: 0x12dbdc, Func Offset: 0x16c
	// Line 2915, Address: 0x12dbe0, Func Offset: 0x170
	// Line 2916, Address: 0x12dbe8, Func Offset: 0x178
	// Line 2917, Address: 0x12dbec, Func Offset: 0x17c
	// Line 2918, Address: 0x12dbf4, Func Offset: 0x184
	// Line 2920, Address: 0x12dc0c, Func Offset: 0x19c
	// Line 2921, Address: 0x12dc14, Func Offset: 0x1a4
	// Line 2922, Address: 0x12dc18, Func Offset: 0x1a8
	// Line 2923, Address: 0x12dc20, Func Offset: 0x1b0
	// Line 2926, Address: 0x12dc28, Func Offset: 0x1b8
	// Line 2927, Address: 0x12dc38, Func Offset: 0x1c8
	// Func End, Address: 0x12dc48, Func Offset: 0x1d8
}

// 
// Start address: 0x12dc50
void npChangeMatAlphaColor(npobj* objp, int obj_n, unsigned char alpha)
{
	unsigned char* pnt;
	int i;
	// Line 2941, Address: 0x12dc50, Func Offset: 0
	// Line 2942, Address: 0x12dc5c, Func Offset: 0xc
	// Line 2943, Address: 0x12dc78, Func Offset: 0x28
	// Line 2944, Address: 0x12dc7c, Func Offset: 0x2c
	// Line 2945, Address: 0x12dc80, Func Offset: 0x30
	// Line 2946, Address: 0x12dc84, Func Offset: 0x34
	// Line 2947, Address: 0x12dc88, Func Offset: 0x38
	// Line 2948, Address: 0x12dc98, Func Offset: 0x48
	// Func End, Address: 0x12dca0, Func Offset: 0x50
}

// 
// Start address: 0x12dca0
void npSetAllMatAlphaColor(npobj* objp, int obj_n, unsigned char alpha)
{
	unsigned char* mat;
	short* plp;
	short head;
	int offset;
	int i;
	// Line 2965, Address: 0x12dca0, Func Offset: 0
	// Line 2979, Address: 0x12dcac, Func Offset: 0xc
	// Line 2974, Address: 0x12dcbc, Func Offset: 0x1c
	// Line 2998, Address: 0x12dcc0, Func Offset: 0x20
	// Line 2966, Address: 0x12dcc4, Func Offset: 0x24
	// Line 2967, Address: 0x12dce0, Func Offset: 0x40
	// Line 2969, Address: 0x12dce8, Func Offset: 0x48
	// Line 2970, Address: 0x12dcf4, Func Offset: 0x54
	// Line 2971, Address: 0x12dd0c, Func Offset: 0x6c
	// Line 2972, Address: 0x12dd14, Func Offset: 0x74
	// Line 2973, Address: 0x12dd18, Func Offset: 0x78
	// Line 2974, Address: 0x12dd20, Func Offset: 0x80
	// Line 2976, Address: 0x12dd30, Func Offset: 0x90
	// Line 2979, Address: 0x12dd48, Func Offset: 0xa8
	// Line 2983, Address: 0x12dd70, Func Offset: 0xd0
	// Line 2986, Address: 0x12dd78, Func Offset: 0xd8
	// Line 2987, Address: 0x12dd7c, Func Offset: 0xdc
	// Line 2990, Address: 0x12dd80, Func Offset: 0xe0
	// Line 2991, Address: 0x12dd88, Func Offset: 0xe8
	// Line 2992, Address: 0x12dd8c, Func Offset: 0xec
	// Line 2993, Address: 0x12dd94, Func Offset: 0xf4
	// Line 2995, Address: 0x12ddac, Func Offset: 0x10c
	// Line 2996, Address: 0x12ddb4, Func Offset: 0x114
	// Line 2997, Address: 0x12ddb8, Func Offset: 0x118
	// Line 2998, Address: 0x12ddc0, Func Offset: 0x120
	// Line 3001, Address: 0x12ddc8, Func Offset: 0x128
	// Line 3002, Address: 0x12ddd8, Func Offset: 0x138
	// Func End, Address: 0x12dde0, Func Offset: 0x140
}

// 
// Start address: 0x12dde0
void npSetOffsetUV(_anon16* mdlp, short offu, short offv)
{
	short* plp;
	short head;
	int usr_num;
	int srp_num;
	int offset;
	// Line 3018, Address: 0x12dde0, Func Offset: 0
	// Line 3045, Address: 0x12dde8, Func Offset: 0x8
	// Line 3024, Address: 0x12ddf0, Func Offset: 0x10
	// Line 3072, Address: 0x12ddf8, Func Offset: 0x18
	// Line 3025, Address: 0x12ddfc, Func Offset: 0x1c
	// Line 3084, Address: 0x12de00, Func Offset: 0x20
	// Line 3045, Address: 0x12de04, Func Offset: 0x24
	// Line 3020, Address: 0x12de0c, Func Offset: 0x2c
	// Line 3021, Address: 0x12de18, Func Offset: 0x38
	// Line 3022, Address: 0x12de38, Func Offset: 0x58
	// Line 3023, Address: 0x12de40, Func Offset: 0x60
	// Line 3024, Address: 0x12de48, Func Offset: 0x68
	// Line 3023, Address: 0x12de4c, Func Offset: 0x6c
	// Line 3025, Address: 0x12de50, Func Offset: 0x70
	// Line 3026, Address: 0x12de58, Func Offset: 0x78
	// Line 3027, Address: 0x12de5c, Func Offset: 0x7c
	// Line 3047, Address: 0x12de64, Func Offset: 0x84
	// Line 3048, Address: 0x12de68, Func Offset: 0x88
	// Line 3049, Address: 0x12de6c, Func Offset: 0x8c
	// Line 3051, Address: 0x12de74, Func Offset: 0x94
	// Line 3053, Address: 0x12de78, Func Offset: 0x98
	// Line 3054, Address: 0x12de7c, Func Offset: 0x9c
	// Line 3055, Address: 0x12de80, Func Offset: 0xa0
	// Line 3056, Address: 0x12de84, Func Offset: 0xa4
	// Line 3057, Address: 0x12de88, Func Offset: 0xa8
	// Line 3058, Address: 0x12de8c, Func Offset: 0xac
	// Line 3059, Address: 0x12de90, Func Offset: 0xb0
	// Line 3060, Address: 0x12de94, Func Offset: 0xb4
	// Line 3062, Address: 0x12de9c, Func Offset: 0xbc
	// Line 3063, Address: 0x12dea0, Func Offset: 0xc0
	// Line 3064, Address: 0x12dea4, Func Offset: 0xc4
	// Line 3066, Address: 0x12deac, Func Offset: 0xcc
	// Line 3071, Address: 0x12deb0, Func Offset: 0xd0
	// Line 3072, Address: 0x12deb8, Func Offset: 0xd8
	// Line 3074, Address: 0x12ded0, Func Offset: 0xf0
	// Line 3076, Address: 0x12dee8, Func Offset: 0x108
	// Line 3077, Address: 0x12def0, Func Offset: 0x110
	// Line 3078, Address: 0x12def4, Func Offset: 0x114
	// Line 3079, Address: 0x12defc, Func Offset: 0x11c
	// Line 3081, Address: 0x12df1c, Func Offset: 0x13c
	// Line 3082, Address: 0x12df24, Func Offset: 0x144
	// Line 3083, Address: 0x12df28, Func Offset: 0x148
	// Line 3084, Address: 0x12df30, Func Offset: 0x150
	// Line 3086, Address: 0x12df40, Func Offset: 0x160
	// Func End, Address: 0x12df48, Func Offset: 0x168
}

// 
// Start address: 0x12df50
void npSetOffsetUV2(_anon16* mdlp, short offu, short offv)
{
	short* plp;
	short head;
	int usr_num;
	int srp_num;
	// Line 3097, Address: 0x12df50, Func Offset: 0
	// Line 3142, Address: 0x12df58, Func Offset: 0x8
	// Line 3100, Address: 0x12df5c, Func Offset: 0xc
	// Line 3099, Address: 0x12df60, Func Offset: 0x10
	// Line 3100, Address: 0x12df6c, Func Offset: 0x1c
	// Line 3101, Address: 0x12df74, Func Offset: 0x24
	// Line 3102, Address: 0x12df7c, Func Offset: 0x2c
	// Line 3116, Address: 0x12df84, Func Offset: 0x34
	// Line 3102, Address: 0x12df90, Func Offset: 0x40
	// Line 3101, Address: 0x12df94, Func Offset: 0x44
	// Line 3102, Address: 0x12df98, Func Offset: 0x48
	// Line 3116, Address: 0x12df9c, Func Offset: 0x4c
	// Line 3101, Address: 0x12dfa0, Func Offset: 0x50
	// Line 3118, Address: 0x12dfa4, Func Offset: 0x54
	// Line 3119, Address: 0x12dfa8, Func Offset: 0x58
	// Line 3120, Address: 0x12dfac, Func Offset: 0x5c
	// Line 3122, Address: 0x12dfb4, Func Offset: 0x64
	// Line 3124, Address: 0x12dfb8, Func Offset: 0x68
	// Line 3125, Address: 0x12dfbc, Func Offset: 0x6c
	// Line 3126, Address: 0x12dfc0, Func Offset: 0x70
	// Line 3127, Address: 0x12dfc4, Func Offset: 0x74
	// Line 3128, Address: 0x12dfc8, Func Offset: 0x78
	// Line 3129, Address: 0x12dfcc, Func Offset: 0x7c
	// Line 3130, Address: 0x12dfd0, Func Offset: 0x80
	// Line 3131, Address: 0x12dfd4, Func Offset: 0x84
	// Line 3133, Address: 0x12dfdc, Func Offset: 0x8c
	// Line 3134, Address: 0x12dfe0, Func Offset: 0x90
	// Line 3135, Address: 0x12dfe4, Func Offset: 0x94
	// Line 3140, Address: 0x12dfec, Func Offset: 0x9c
	// Line 3142, Address: 0x12dff4, Func Offset: 0xa4
	// Line 3145, Address: 0x12e004, Func Offset: 0xb4
	// Line 3146, Address: 0x12e00c, Func Offset: 0xbc
	// Func End, Address: 0x12e014, Func Offset: 0xc4
}

// 
// Start address: 0x12e020
int npCopyVlist(int* dstp, int* srcp)
{
	int nb;
	_anon3* pPs;
	// Line 3180, Address: 0x12e020, Func Offset: 0
	// Line 3186, Address: 0x12e02c, Func Offset: 0xc
	// Line 3188, Address: 0x12e03c, Func Offset: 0x1c
	// Line 3189, Address: 0x12e054, Func Offset: 0x34
	// Line 3190, Address: 0x12e05c, Func Offset: 0x3c
	// Line 3193, Address: 0x12e064, Func Offset: 0x44
	// Line 3194, Address: 0x12e070, Func Offset: 0x50
	// Line 3196, Address: 0x12e078, Func Offset: 0x58
	// Line 3197, Address: 0x12e07c, Func Offset: 0x5c
	// Func End, Address: 0x12e08c, Func Offset: 0x6c
}

// 100% matching!
void npCutSkin() 
{
    
}

// 
// Start address: 0x12e0a0
void npInitCalcSkin(void* pwp, int obj_n, int* sknp)
{
	unsigned int ulSize;
	int mno;
	int nb;
	int flg;
	int i;
	npobj* op;
	_anon9* owp;
	float mat[16];
	unsigned char matb[64];
	// Line 3687, Address: 0x12e0a0, Func Offset: 0
	// Line 3704, Address: 0x12e0c0, Func Offset: 0x20
	// Line 3705, Address: 0x12e0c4, Func Offset: 0x24
	// Line 3704, Address: 0x12e0d8, Func Offset: 0x38
	// Line 3705, Address: 0x12e0dc, Func Offset: 0x3c
	// Line 3707, Address: 0x12e0e4, Func Offset: 0x44
	// Line 3708, Address: 0x12e0f0, Func Offset: 0x50
	// Line 3709, Address: 0x12e0f8, Func Offset: 0x58
	// Line 3710, Address: 0x12e100, Func Offset: 0x60
	// Line 3712, Address: 0x12e108, Func Offset: 0x68
	// Line 3713, Address: 0x12e11c, Func Offset: 0x7c
	// Line 3714, Address: 0x12e124, Func Offset: 0x84
	// Line 3715, Address: 0x12e130, Func Offset: 0x90
	// Line 3719, Address: 0x12e138, Func Offset: 0x98
	// Line 3721, Address: 0x12e140, Func Offset: 0xa0
	// Line 3715, Address: 0x12e144, Func Offset: 0xa4
	// Line 3719, Address: 0x12e154, Func Offset: 0xb4
	// Line 3716, Address: 0x12e15c, Func Offset: 0xbc
	// Line 3720, Address: 0x12e174, Func Offset: 0xd4
	// Line 3721, Address: 0x12e17c, Func Offset: 0xdc
	// Line 3717, Address: 0x12e184, Func Offset: 0xe4
	// Line 3721, Address: 0x12e190, Func Offset: 0xf0
	// Line 3717, Address: 0x12e194, Func Offset: 0xf4
	// Line 3719, Address: 0x12e1a0, Func Offset: 0x100
	// Line 3722, Address: 0x12e1ac, Func Offset: 0x10c
	// Line 3723, Address: 0x12e1bc, Func Offset: 0x11c
	// Line 3724, Address: 0x12e1c4, Func Offset: 0x124
	// Line 3738, Address: 0x12e1d8, Func Offset: 0x138
	// Line 3740, Address: 0x12e1fc, Func Offset: 0x15c
	// Line 3741, Address: 0x12e200, Func Offset: 0x160
	// Line 3742, Address: 0x12e204, Func Offset: 0x164
	// Line 3743, Address: 0x12e208, Func Offset: 0x168
	// Line 3744, Address: 0x12e20c, Func Offset: 0x16c
	// Line 3745, Address: 0x12e210, Func Offset: 0x170
	// Line 3746, Address: 0x12e214, Func Offset: 0x174
	// Line 3747, Address: 0x12e218, Func Offset: 0x178
	// Line 3748, Address: 0x12e21c, Func Offset: 0x17c
	// Line 3749, Address: 0x12e220, Func Offset: 0x180
	// Line 3750, Address: 0x12e224, Func Offset: 0x184
	// Line 3751, Address: 0x12e228, Func Offset: 0x188
	// Line 3752, Address: 0x12e22c, Func Offset: 0x18c
	// Line 3753, Address: 0x12e230, Func Offset: 0x190
	// Line 3754, Address: 0x12e234, Func Offset: 0x194
	// Line 3755, Address: 0x12e238, Func Offset: 0x198
	// Line 3756, Address: 0x12e23c, Func Offset: 0x19c
	// Line 3757, Address: 0x12e240, Func Offset: 0x1a0
	// Line 3763, Address: 0x12e244, Func Offset: 0x1a4
	// Line 3766, Address: 0x12e270, Func Offset: 0x1d0
	// Line 3767, Address: 0x12e28c, Func Offset: 0x1ec
	// Func End, Address: 0x12e2ac, Func Offset: 0x20c
}

// 
// Start address: 0x12e2b0
void npCalcSkin(void* pwp, int obj_n, int* sknp)
{
	_anon3* pHdr1;
	_anon3* pHdr0;
	int nb;
	int rg0;
	int flg;
	int j;
	int i;
	float* p1;
	float lv;
	npobj* op;
	_anon0* p0;
	float level[10];
	// Line 3823, Address: 0x12e2b0, Func Offset: 0
	// Line 3849, Address: 0x12e2cc, Func Offset: 0x1c
	// Line 3854, Address: 0x12e2d4, Func Offset: 0x24
	// Line 3860, Address: 0x12e2dc, Func Offset: 0x2c
	// Line 3866, Address: 0x12e2ec, Func Offset: 0x3c
	// Line 3867, Address: 0x12e2f4, Func Offset: 0x44
	// Line 3868, Address: 0x12e2fc, Func Offset: 0x4c
	// Line 3870, Address: 0x12e304, Func Offset: 0x54
	// Line 3871, Address: 0x12e318, Func Offset: 0x68
	// Line 3872, Address: 0x12e320, Func Offset: 0x70
	// Line 3874, Address: 0x12e32c, Func Offset: 0x7c
	// Line 3873, Address: 0x12e334, Func Offset: 0x84
	// Line 3875, Address: 0x12e338, Func Offset: 0x88
	// Line 3876, Address: 0x12e340, Func Offset: 0x90
	// Line 3874, Address: 0x12e344, Func Offset: 0x94
	// Line 3873, Address: 0x12e348, Func Offset: 0x98
	// Line 3874, Address: 0x12e34c, Func Offset: 0x9c
	// Line 3876, Address: 0x12e354, Func Offset: 0xa4
	// Line 3875, Address: 0x12e358, Func Offset: 0xa8
	// Line 3874, Address: 0x12e35c, Func Offset: 0xac
	// Line 3875, Address: 0x12e360, Func Offset: 0xb0
	// Line 3876, Address: 0x12e36c, Func Offset: 0xbc
	// Line 3877, Address: 0x12e370, Func Offset: 0xc0
	// Line 3880, Address: 0x12e374, Func Offset: 0xc4
	// Line 3887, Address: 0x12e378, Func Offset: 0xc8
	// Line 3875, Address: 0x12e37c, Func Offset: 0xcc
	// Line 3876, Address: 0x12e380, Func Offset: 0xd0
	// Line 3899, Address: 0x12e384, Func Offset: 0xd4
	// Line 3877, Address: 0x12e388, Func Offset: 0xd8
	// Line 3880, Address: 0x12e38c, Func Offset: 0xdc
	// Line 3877, Address: 0x12e390, Func Offset: 0xe0
	// Line 3882, Address: 0x12e3a0, Func Offset: 0xf0
	// Line 3893, Address: 0x12e3a4, Func Offset: 0xf4
	// Line 3882, Address: 0x12e3a8, Func Offset: 0xf8
	// Line 3883, Address: 0x12e3ac, Func Offset: 0xfc
	// Line 3884, Address: 0x12e3b4, Func Offset: 0x104
	// Line 3885, Address: 0x12e3bc, Func Offset: 0x10c
	// Line 3886, Address: 0x12e3c4, Func Offset: 0x114
	// Line 3899, Address: 0x12e3c8, Func Offset: 0x118
	// Line 3900, Address: 0x12e3d0, Func Offset: 0x120
	// Line 3901, Address: 0x12e3d8, Func Offset: 0x128
	// Line 3903, Address: 0x12e3e0, Func Offset: 0x130
	// Line 3900, Address: 0x12e3e8, Func Offset: 0x138
	// Line 3901, Address: 0x12e3f8, Func Offset: 0x148
	// Line 3903, Address: 0x12e40c, Func Offset: 0x15c
	// Line 3915, Address: 0x12e41c, Func Offset: 0x16c
	// Line 3917, Address: 0x12e44c, Func Offset: 0x19c
	// Line 3918, Address: 0x12e450, Func Offset: 0x1a0
	// Line 3919, Address: 0x12e454, Func Offset: 0x1a4
	// Line 3920, Address: 0x12e458, Func Offset: 0x1a8
	// Line 3921, Address: 0x12e45c, Func Offset: 0x1ac
	// Line 3922, Address: 0x12e460, Func Offset: 0x1b0
	// Line 3923, Address: 0x12e464, Func Offset: 0x1b4
	// Line 3924, Address: 0x12e468, Func Offset: 0x1b8
	// Line 3925, Address: 0x12e46c, Func Offset: 0x1bc
	// Line 3926, Address: 0x12e470, Func Offset: 0x1c0
	// Line 3927, Address: 0x12e474, Func Offset: 0x1c4
	// Line 3928, Address: 0x12e478, Func Offset: 0x1c8
	// Line 3929, Address: 0x12e47c, Func Offset: 0x1cc
	// Line 3930, Address: 0x12e480, Func Offset: 0x1d0
	// Line 3931, Address: 0x12e484, Func Offset: 0x1d4
	// Line 3932, Address: 0x12e488, Func Offset: 0x1d8
	// Line 3933, Address: 0x12e48c, Func Offset: 0x1dc
	// Line 3934, Address: 0x12e490, Func Offset: 0x1e0
	// Line 3935, Address: 0x12e494, Func Offset: 0x1e4
	// Line 3936, Address: 0x12e498, Func Offset: 0x1e8
	// Line 3937, Address: 0x12e49c, Func Offset: 0x1ec
	// Line 3938, Address: 0x12e4a0, Func Offset: 0x1f0
	// Line 3939, Address: 0x12e4a4, Func Offset: 0x1f4
	// Line 3957, Address: 0x12e4a8, Func Offset: 0x1f8
	// Line 3942, Address: 0x12e4b8, Func Offset: 0x208
	// Line 3943, Address: 0x12e4bc, Func Offset: 0x20c
	// Line 3957, Address: 0x12e4c0, Func Offset: 0x210
	// Line 3959, Address: 0x12e4d4, Func Offset: 0x224
	// Line 3960, Address: 0x12e4d8, Func Offset: 0x228
	// Line 3961, Address: 0x12e4dc, Func Offset: 0x22c
	// Line 3962, Address: 0x12e4e0, Func Offset: 0x230
	// Line 3963, Address: 0x12e4e4, Func Offset: 0x234
	// Line 3964, Address: 0x12e4e8, Func Offset: 0x238
	// Line 3965, Address: 0x12e4ec, Func Offset: 0x23c
	// Line 3966, Address: 0x12e4f0, Func Offset: 0x240
	// Line 3967, Address: 0x12e4f4, Func Offset: 0x244
	// Line 3968, Address: 0x12e4f8, Func Offset: 0x248
	// Line 3969, Address: 0x12e4fc, Func Offset: 0x24c
	// Line 3970, Address: 0x12e500, Func Offset: 0x250
	// Line 3971, Address: 0x12e504, Func Offset: 0x254
	// Line 3972, Address: 0x12e508, Func Offset: 0x258
	// Line 3973, Address: 0x12e50c, Func Offset: 0x25c
	// Line 3974, Address: 0x12e510, Func Offset: 0x260
	// Line 3975, Address: 0x12e514, Func Offset: 0x264
	// Line 3976, Address: 0x12e518, Func Offset: 0x268
	// Line 3977, Address: 0x12e51c, Func Offset: 0x26c
	// Line 3980, Address: 0x12e520, Func Offset: 0x270
	// Line 3992, Address: 0x12e524, Func Offset: 0x274
	// Line 4010, Address: 0x12e52c, Func Offset: 0x27c
	// Line 4012, Address: 0x12e54c, Func Offset: 0x29c
	// Line 4013, Address: 0x12e550, Func Offset: 0x2a0
	// Line 4014, Address: 0x12e554, Func Offset: 0x2a4
	// Line 4015, Address: 0x12e558, Func Offset: 0x2a8
	// Line 4016, Address: 0x12e55c, Func Offset: 0x2ac
	// Line 4017, Address: 0x12e560, Func Offset: 0x2b0
	// Line 4018, Address: 0x12e564, Func Offset: 0x2b4
	// Line 4019, Address: 0x12e568, Func Offset: 0x2b8
	// Line 4020, Address: 0x12e56c, Func Offset: 0x2bc
	// Line 4021, Address: 0x12e570, Func Offset: 0x2c0
	// Line 4022, Address: 0x12e574, Func Offset: 0x2c4
	// Line 4023, Address: 0x12e578, Func Offset: 0x2c8
	// Line 4024, Address: 0x12e57c, Func Offset: 0x2cc
	// Line 4025, Address: 0x12e580, Func Offset: 0x2d0
	// Line 4026, Address: 0x12e584, Func Offset: 0x2d4
	// Line 4029, Address: 0x12e588, Func Offset: 0x2d8
	// Line 4030, Address: 0x12e58c, Func Offset: 0x2dc
	// Line 4033, Address: 0x12e590, Func Offset: 0x2e0
	// Line 4034, Address: 0x12e5a4, Func Offset: 0x2f4
	// Line 4035, Address: 0x12e5a8, Func Offset: 0x2f8
	// Line 4036, Address: 0x12e5b0, Func Offset: 0x300
	// Line 4037, Address: 0x12e5c4, Func Offset: 0x314
	// Line 4039, Address: 0x12e5c8, Func Offset: 0x318
	// Line 4041, Address: 0x12e5dc, Func Offset: 0x32c
	// Line 4046, Address: 0x12e5e4, Func Offset: 0x334
	// Func End, Address: 0x12e5fc, Func Offset: 0x34c
}

// 
// Start address: 0x12e600
void npInitCalcSkinFM(void* pwp, int obj_n, int* sknp)
{
	unsigned int ulSize;
	int mno;
	int nb;
	int flg;
	int i;
	npobj* op;
	_anon9* owp;
	float mat[16];
	unsigned char matb[64];
	// Line 4150, Address: 0x12e600, Func Offset: 0
	// Line 4168, Address: 0x12e620, Func Offset: 0x20
	// Line 4169, Address: 0x12e624, Func Offset: 0x24
	// Line 4168, Address: 0x12e638, Func Offset: 0x38
	// Line 4169, Address: 0x12e63c, Func Offset: 0x3c
	// Line 4171, Address: 0x12e644, Func Offset: 0x44
	// Line 4172, Address: 0x12e650, Func Offset: 0x50
	// Line 4173, Address: 0x12e658, Func Offset: 0x58
	// Line 4174, Address: 0x12e660, Func Offset: 0x60
	// Line 4175, Address: 0x12e668, Func Offset: 0x68
	// Line 4177, Address: 0x12e680, Func Offset: 0x80
	// Line 4178, Address: 0x12e694, Func Offset: 0x94
	// Line 4179, Address: 0x12e69c, Func Offset: 0x9c
	// Line 4180, Address: 0x12e6a8, Func Offset: 0xa8
	// Line 4184, Address: 0x12e6b0, Func Offset: 0xb0
	// Line 4187, Address: 0x12e6b8, Func Offset: 0xb8
	// Line 4180, Address: 0x12e6bc, Func Offset: 0xbc
	// Line 4184, Address: 0x12e6cc, Func Offset: 0xcc
	// Line 4181, Address: 0x12e6d4, Func Offset: 0xd4
	// Line 4186, Address: 0x12e6ec, Func Offset: 0xec
	// Line 4187, Address: 0x12e6f4, Func Offset: 0xf4
	// Line 4182, Address: 0x12e6fc, Func Offset: 0xfc
	// Line 4187, Address: 0x12e708, Func Offset: 0x108
	// Line 4182, Address: 0x12e70c, Func Offset: 0x10c
	// Line 4184, Address: 0x12e718, Func Offset: 0x118
	// Line 4188, Address: 0x12e724, Func Offset: 0x124
	// Line 4192, Address: 0x12e734, Func Offset: 0x134
	// Line 4193, Address: 0x12e73c, Func Offset: 0x13c
	// Line 4207, Address: 0x12e750, Func Offset: 0x150
	// Line 4209, Address: 0x12e774, Func Offset: 0x174
	// Line 4210, Address: 0x12e778, Func Offset: 0x178
	// Line 4211, Address: 0x12e77c, Func Offset: 0x17c
	// Line 4212, Address: 0x12e780, Func Offset: 0x180
	// Line 4213, Address: 0x12e784, Func Offset: 0x184
	// Line 4214, Address: 0x12e788, Func Offset: 0x188
	// Line 4215, Address: 0x12e78c, Func Offset: 0x18c
	// Line 4216, Address: 0x12e790, Func Offset: 0x190
	// Line 4217, Address: 0x12e794, Func Offset: 0x194
	// Line 4218, Address: 0x12e798, Func Offset: 0x198
	// Line 4219, Address: 0x12e79c, Func Offset: 0x19c
	// Line 4220, Address: 0x12e7a0, Func Offset: 0x1a0
	// Line 4221, Address: 0x12e7a4, Func Offset: 0x1a4
	// Line 4222, Address: 0x12e7a8, Func Offset: 0x1a8
	// Line 4223, Address: 0x12e7ac, Func Offset: 0x1ac
	// Line 4224, Address: 0x12e7b0, Func Offset: 0x1b0
	// Line 4225, Address: 0x12e7b4, Func Offset: 0x1b4
	// Line 4226, Address: 0x12e7b8, Func Offset: 0x1b8
	// Line 4232, Address: 0x12e7bc, Func Offset: 0x1bc
	// Line 4235, Address: 0x12e7e8, Func Offset: 0x1e8
	// Line 4236, Address: 0x12e804, Func Offset: 0x204
	// Func End, Address: 0x12e824, Func Offset: 0x224
}

// 
// Start address: 0x12e830
void npCalcSkinFM(void* pwp, int obj_n, int* sknp)
{
	_anon3* pHdr1;
	_anon3* pHdr0;
	int nb;
	int rg0;
	int flg;
	int j;
	int i;
	float* p1;
	float lv;
	npobj* op;
	_anon0* p0;
	float level[10];
	// Line 4292, Address: 0x12e830, Func Offset: 0
	// Line 4312, Address: 0x12e84c, Func Offset: 0x1c
	// Line 4316, Address: 0x12e854, Func Offset: 0x24
	// Line 4319, Address: 0x12e85c, Func Offset: 0x2c
	// Line 4322, Address: 0x12e86c, Func Offset: 0x3c
	// Line 4323, Address: 0x12e874, Func Offset: 0x44
	// Line 4324, Address: 0x12e87c, Func Offset: 0x4c
	// Line 4325, Address: 0x12e884, Func Offset: 0x54
	// Line 4327, Address: 0x12e8a0, Func Offset: 0x70
	// Line 4328, Address: 0x12e8b4, Func Offset: 0x84
	// Line 4329, Address: 0x12e8bc, Func Offset: 0x8c
	// Line 4331, Address: 0x12e8c8, Func Offset: 0x98
	// Line 4330, Address: 0x12e8d0, Func Offset: 0xa0
	// Line 4332, Address: 0x12e8d4, Func Offset: 0xa4
	// Line 4333, Address: 0x12e8dc, Func Offset: 0xac
	// Line 4331, Address: 0x12e8e0, Func Offset: 0xb0
	// Line 4330, Address: 0x12e8e4, Func Offset: 0xb4
	// Line 4331, Address: 0x12e8e8, Func Offset: 0xb8
	// Line 4333, Address: 0x12e8f0, Func Offset: 0xc0
	// Line 4332, Address: 0x12e8f4, Func Offset: 0xc4
	// Line 4331, Address: 0x12e8f8, Func Offset: 0xc8
	// Line 4332, Address: 0x12e8fc, Func Offset: 0xcc
	// Line 4333, Address: 0x12e908, Func Offset: 0xd8
	// Line 4334, Address: 0x12e90c, Func Offset: 0xdc
	// Line 4337, Address: 0x12e910, Func Offset: 0xe0
	// Line 4344, Address: 0x12e914, Func Offset: 0xe4
	// Line 4332, Address: 0x12e918, Func Offset: 0xe8
	// Line 4333, Address: 0x12e91c, Func Offset: 0xec
	// Line 4346, Address: 0x12e920, Func Offset: 0xf0
	// Line 4334, Address: 0x12e924, Func Offset: 0xf4
	// Line 4337, Address: 0x12e928, Func Offset: 0xf8
	// Line 4334, Address: 0x12e92c, Func Offset: 0xfc
	// Line 4339, Address: 0x12e93c, Func Offset: 0x10c
	// Line 4345, Address: 0x12e940, Func Offset: 0x110
	// Line 4339, Address: 0x12e944, Func Offset: 0x114
	// Line 4340, Address: 0x12e948, Func Offset: 0x118
	// Line 4341, Address: 0x12e950, Func Offset: 0x120
	// Line 4342, Address: 0x12e958, Func Offset: 0x128
	// Line 4343, Address: 0x12e960, Func Offset: 0x130
	// Line 4346, Address: 0x12e964, Func Offset: 0x134
	// Line 4347, Address: 0x12e96c, Func Offset: 0x13c
	// Line 4348, Address: 0x12e974, Func Offset: 0x144
	// Line 4347, Address: 0x12e97c, Func Offset: 0x14c
	// Line 4348, Address: 0x12e98c, Func Offset: 0x15c
	// Line 4349, Address: 0x12e99c, Func Offset: 0x16c
	// Line 4350, Address: 0x12e9a0, Func Offset: 0x170
	// Line 4351, Address: 0x12e9b0, Func Offset: 0x180
	// Line 4363, Address: 0x12e9cc, Func Offset: 0x19c
	// Line 4365, Address: 0x12e9fc, Func Offset: 0x1cc
	// Line 4366, Address: 0x12ea00, Func Offset: 0x1d0
	// Line 4367, Address: 0x12ea04, Func Offset: 0x1d4
	// Line 4368, Address: 0x12ea08, Func Offset: 0x1d8
	// Line 4369, Address: 0x12ea0c, Func Offset: 0x1dc
	// Line 4370, Address: 0x12ea10, Func Offset: 0x1e0
	// Line 4371, Address: 0x12ea14, Func Offset: 0x1e4
	// Line 4372, Address: 0x12ea18, Func Offset: 0x1e8
	// Line 4373, Address: 0x12ea1c, Func Offset: 0x1ec
	// Line 4374, Address: 0x12ea20, Func Offset: 0x1f0
	// Line 4375, Address: 0x12ea24, Func Offset: 0x1f4
	// Line 4376, Address: 0x12ea28, Func Offset: 0x1f8
	// Line 4377, Address: 0x12ea2c, Func Offset: 0x1fc
	// Line 4378, Address: 0x12ea30, Func Offset: 0x200
	// Line 4379, Address: 0x12ea34, Func Offset: 0x204
	// Line 4380, Address: 0x12ea38, Func Offset: 0x208
	// Line 4381, Address: 0x12ea3c, Func Offset: 0x20c
	// Line 4382, Address: 0x12ea40, Func Offset: 0x210
	// Line 4383, Address: 0x12ea44, Func Offset: 0x214
	// Line 4384, Address: 0x12ea48, Func Offset: 0x218
	// Line 4385, Address: 0x12ea4c, Func Offset: 0x21c
	// Line 4386, Address: 0x12ea50, Func Offset: 0x220
	// Line 4387, Address: 0x12ea54, Func Offset: 0x224
	// Line 4403, Address: 0x12ea58, Func Offset: 0x228
	// Line 4390, Address: 0x12ea68, Func Offset: 0x238
	// Line 4391, Address: 0x12ea6c, Func Offset: 0x23c
	// Line 4403, Address: 0x12ea70, Func Offset: 0x240
	// Line 4405, Address: 0x12ea84, Func Offset: 0x254
	// Line 4406, Address: 0x12ea88, Func Offset: 0x258
	// Line 4407, Address: 0x12ea8c, Func Offset: 0x25c
	// Line 4408, Address: 0x12ea90, Func Offset: 0x260
	// Line 4409, Address: 0x12ea94, Func Offset: 0x264
	// Line 4410, Address: 0x12ea98, Func Offset: 0x268
	// Line 4411, Address: 0x12ea9c, Func Offset: 0x26c
	// Line 4412, Address: 0x12eaa0, Func Offset: 0x270
	// Line 4413, Address: 0x12eaa4, Func Offset: 0x274
	// Line 4414, Address: 0x12eaa8, Func Offset: 0x278
	// Line 4415, Address: 0x12eaac, Func Offset: 0x27c
	// Line 4416, Address: 0x12eab0, Func Offset: 0x280
	// Line 4417, Address: 0x12eab4, Func Offset: 0x284
	// Line 4418, Address: 0x12eab8, Func Offset: 0x288
	// Line 4419, Address: 0x12eabc, Func Offset: 0x28c
	// Line 4420, Address: 0x12eac0, Func Offset: 0x290
	// Line 4421, Address: 0x12eac4, Func Offset: 0x294
	// Line 4422, Address: 0x12eac8, Func Offset: 0x298
	// Line 4423, Address: 0x12eacc, Func Offset: 0x29c
	// Line 4426, Address: 0x12ead0, Func Offset: 0x2a0
	// Line 4429, Address: 0x12ead4, Func Offset: 0x2a4
	// Line 4447, Address: 0x12eadc, Func Offset: 0x2ac
	// Line 4449, Address: 0x12eafc, Func Offset: 0x2cc
	// Line 4450, Address: 0x12eb00, Func Offset: 0x2d0
	// Line 4451, Address: 0x12eb04, Func Offset: 0x2d4
	// Line 4452, Address: 0x12eb08, Func Offset: 0x2d8
	// Line 4453, Address: 0x12eb0c, Func Offset: 0x2dc
	// Line 4454, Address: 0x12eb10, Func Offset: 0x2e0
	// Line 4455, Address: 0x12eb14, Func Offset: 0x2e4
	// Line 4456, Address: 0x12eb18, Func Offset: 0x2e8
	// Line 4457, Address: 0x12eb1c, Func Offset: 0x2ec
	// Line 4458, Address: 0x12eb20, Func Offset: 0x2f0
	// Line 4459, Address: 0x12eb24, Func Offset: 0x2f4
	// Line 4460, Address: 0x12eb28, Func Offset: 0x2f8
	// Line 4461, Address: 0x12eb2c, Func Offset: 0x2fc
	// Line 4462, Address: 0x12eb30, Func Offset: 0x300
	// Line 4463, Address: 0x12eb34, Func Offset: 0x304
	// Line 4466, Address: 0x12eb38, Func Offset: 0x308
	// Line 4467, Address: 0x12eb3c, Func Offset: 0x30c
	// Line 4470, Address: 0x12eb40, Func Offset: 0x310
	// Line 4471, Address: 0x12eb54, Func Offset: 0x324
	// Line 4472, Address: 0x12eb58, Func Offset: 0x328
	// Line 4473, Address: 0x12eb60, Func Offset: 0x330
	// Line 4474, Address: 0x12eb74, Func Offset: 0x344
	// Line 4476, Address: 0x12eb78, Func Offset: 0x348
	// Line 4478, Address: 0x12eb8c, Func Offset: 0x35c
	// Line 4482, Address: 0x12eb94, Func Offset: 0x364
	// Func End, Address: 0x12ebac, Func Offset: 0x37c
}

