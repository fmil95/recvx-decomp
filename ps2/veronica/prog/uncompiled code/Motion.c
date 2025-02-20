typedef struct npobj;
typedef struct _anon0;
typedef struct BH_PWORK;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;
typedef struct _anon11;


typedef char type_0[8];
typedef int type_1[3];
typedef float type_2[3];
typedef unsigned short type_3[3];
typedef int type_4[3];
typedef void* type_5[2];
typedef char type_6[64];
typedef int type_7[3];
typedef unsigned int type_8[2];
typedef float type_9[3];
typedef int type_10[3];
typedef float type_11[3];
typedef int type_12[64];
typedef float type_13[16];
typedef unsigned int type_14[1];
typedef unsigned int type_15[2];
typedef int* type_16[16];
typedef npobj* type_17[16];
typedef _anon7* type_18[16];
typedef _anon9 type_19[16];
typedef unsigned char type_20[64];

struct npobj
{
	unsigned int evalflags;
	_anon8* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon0
{
	float key[3];
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
	_anon7* txp[16];
	_anon9 mdl[16];
	_anon9* mlwP;
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
	_anon1* mnwP;
	_anon1* mnwPb;
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
	_anon11 watr;
	_anon5* cpcl;
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

struct _anon1
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon2* md2P;
	unsigned short* atrP;
};

struct _anon2
{
	void* p[2];
};

struct _anon3
{
	unsigned short key[3];
};

struct _anon4
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon5
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon6
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon7
{
	_anon4* textures;
	unsigned int nbTexture;
};

struct _anon8
{
	int* vlist;
	short* plist;
	_anon10 center;
	float r;
};

struct _anon9
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon7* texP;
	_anon6* owP;
};

struct _anon10
{
	float x;
	float y;
	float z;
};

struct _anon11
{
	_anon10 c1;
	_anon10 c2;
	float r;
};

char NormalTbl[64];
_anon3 NullMka;
int mka_ang[3];

int bhSetMotion(BH_PWORK* ewP, int add, int mode, void* datP);
void SetMtnNormal(BH_PWORK* ewP, char* datP, int mode);
void SetMtnNormalHokan(BH_PWORK* ewP, char* datP, int mode, float rate);
void SetMtnFast(BH_PWORK* ewP, char* datP, int mode);
void SetMtnFastHokan(BH_PWORK* ewP, char* datP, int mode, float rate);
void SetMtnSlow(BH_PWORK* ewP, char* datP, int mode);
void SetMtnSlowHokan(BH_PWORK* ewP, char* datP, int mode, float rate);
void bhFixPosition(BH_PWORK* ewP, char* datP);
void bhCalcFixOffset(BH_PWORK* ewP, char* datP, _anon10* offP, _anon10* rtnP);
void bhGetObjMotion(BH_PWORK* ewP, int obj_no, float* pos, int* ang);
void AngZyxToYzx(int* zyx, int* yzx);
void AngYzxToZyx(int* yzx, int* zyx);

// 
// Start address: 0x12f510
int bhSetMotion(BH_PWORK* ewP, int add, int mode, void* datP)
{
	int frm_num;
	unsigned short* atrP;
	unsigned int* flgP;
	float rate;
	// Line 83, Address: 0x12f510, Func Offset: 0
	// Line 84, Address: 0x12f524, Func Offset: 0x14
	// Line 91, Address: 0x12f550, Func Offset: 0x40
	// Line 93, Address: 0x12f5e0, Func Offset: 0xd0
	// Line 95, Address: 0x12f5fc, Func Offset: 0xec
	// Line 96, Address: 0x12f620, Func Offset: 0x110
	// Line 97, Address: 0x12f630, Func Offset: 0x120
	// Line 98, Address: 0x12f638, Func Offset: 0x128
	// Line 100, Address: 0x12f644, Func Offset: 0x134
	// Line 101, Address: 0x12f668, Func Offset: 0x158
	// Line 102, Address: 0x12f678, Func Offset: 0x168
	// Line 104, Address: 0x12f680, Func Offset: 0x170
	// Line 105, Address: 0x12f6a4, Func Offset: 0x194
	// Line 112, Address: 0x12f6b4, Func Offset: 0x1a4
	// Line 113, Address: 0x12f6d0, Func Offset: 0x1c0
	// Line 118, Address: 0x12f6f0, Func Offset: 0x1e0
	// Line 120, Address: 0x12f6f8, Func Offset: 0x1e8
	// Line 118, Address: 0x12f6fc, Func Offset: 0x1ec
	// Line 120, Address: 0x12f710, Func Offset: 0x200
	// Line 121, Address: 0x12f734, Func Offset: 0x224
	// Line 124, Address: 0x12f740, Func Offset: 0x230
	// Line 126, Address: 0x12f748, Func Offset: 0x238
	// Line 127, Address: 0x12f76c, Func Offset: 0x25c
	// Line 128, Address: 0x12f774, Func Offset: 0x264
	// Line 130, Address: 0x12f77c, Func Offset: 0x26c
	// Line 131, Address: 0x12f788, Func Offset: 0x278
	// Line 132, Address: 0x12f790, Func Offset: 0x280
	// Line 134, Address: 0x12f798, Func Offset: 0x288
	// Line 135, Address: 0x12f7a4, Func Offset: 0x294
	// Line 136, Address: 0x12f7ac, Func Offset: 0x29c
	// Line 142, Address: 0x12f7b4, Func Offset: 0x2a4
	// Line 143, Address: 0x12f7b8, Func Offset: 0x2a8
	// Func End, Address: 0x12f7d0, Func Offset: 0x2c0
}

// 
// Start address: 0x12f7d0
void SetMtnNormal(BH_PWORK* ewP, char* datP, int mode)
{
	int* dstP;
	_anon3* mkaP;
	float* posP;
	_anon0* mkfP;
	_anon6* owP;
	_anon2* md2P;
	int obj_no;
	float flp_f;
	int flp_s;
	// Line 157, Address: 0x12f7d0, Func Offset: 0
	// Line 162, Address: 0x12f7e4, Func Offset: 0x14
	// Line 163, Address: 0x12f7fc, Func Offset: 0x2c
	// Line 165, Address: 0x12f800, Func Offset: 0x30
	// Line 166, Address: 0x12f808, Func Offset: 0x38
	// Line 167, Address: 0x12f810, Func Offset: 0x40
	// Line 168, Address: 0x12f818, Func Offset: 0x48
	// Line 171, Address: 0x12f824, Func Offset: 0x54
	// Line 172, Address: 0x12f82c, Func Offset: 0x5c
	// Line 174, Address: 0x12f848, Func Offset: 0x78
	// Line 178, Address: 0x12f858, Func Offset: 0x88
	// Line 180, Address: 0x12f85c, Func Offset: 0x8c
	// Line 181, Address: 0x12f864, Func Offset: 0x94
	// Line 183, Address: 0x12f878, Func Offset: 0xa8
	// Line 181, Address: 0x12f87c, Func Offset: 0xac
	// Line 183, Address: 0x12f884, Func Offset: 0xb4
	// Line 186, Address: 0x12f898, Func Offset: 0xc8
	// Line 187, Address: 0x12f8a4, Func Offset: 0xd4
	// Line 188, Address: 0x12f8ac, Func Offset: 0xdc
	// Line 189, Address: 0x12f8b4, Func Offset: 0xe4
	// Line 192, Address: 0x12f8b8, Func Offset: 0xe8
	// Line 196, Address: 0x12f8c8, Func Offset: 0xf8
	// Line 195, Address: 0x12f8d0, Func Offset: 0x100
	// Line 196, Address: 0x12f8d4, Func Offset: 0x104
	// Line 198, Address: 0x12f8f0, Func Offset: 0x120
	// Line 199, Address: 0x12f8f8, Func Offset: 0x128
	// Line 202, Address: 0x12f910, Func Offset: 0x140
	// Line 203, Address: 0x12f918, Func Offset: 0x148
	// Line 204, Address: 0x12f924, Func Offset: 0x154
	// Line 205, Address: 0x12f92c, Func Offset: 0x15c
	// Line 206, Address: 0x12f934, Func Offset: 0x164
	// Line 211, Address: 0x12f940, Func Offset: 0x170
	// Line 212, Address: 0x12f944, Func Offset: 0x174
	// Line 214, Address: 0x12f948, Func Offset: 0x178
	// Line 217, Address: 0x12f958, Func Offset: 0x188
	// Func End, Address: 0x12f960, Func Offset: 0x190
}

// 
// Start address: 0x12f960
void SetMtnNormalHokan(BH_PWORK* ewP, char* datP, int mode, float rate)
{
	short dlt;
	int* dstP;
	int sum;
	_anon3* mkaP;
	int* angP;
	float* posP;
	_anon0* mkfP;
	_anon6* owP;
	_anon2* md2P;
	int obj_no;
	float flp_f;
	int flp_s;
	// Line 229, Address: 0x12f960, Func Offset: 0
	// Line 231, Address: 0x12f988, Func Offset: 0x28
	// Line 229, Address: 0x12f98c, Func Offset: 0x2c
	// Line 231, Address: 0x12f998, Func Offset: 0x38
	// Line 236, Address: 0x12f9a8, Func Offset: 0x48
	// Line 237, Address: 0x12f9c0, Func Offset: 0x60
	// Line 239, Address: 0x12f9c4, Func Offset: 0x64
	// Line 240, Address: 0x12f9cc, Func Offset: 0x6c
	// Line 241, Address: 0x12f9d4, Func Offset: 0x74
	// Line 242, Address: 0x12f9dc, Func Offset: 0x7c
	// Line 245, Address: 0x12f9e8, Func Offset: 0x88
	// Line 246, Address: 0x12f9f4, Func Offset: 0x94
	// Line 248, Address: 0x12fa10, Func Offset: 0xb0
	// Line 251, Address: 0x12fa20, Func Offset: 0xc0
	// Line 253, Address: 0x12fa24, Func Offset: 0xc4
	// Line 254, Address: 0x12fa2c, Func Offset: 0xcc
	// Line 256, Address: 0x12fa40, Func Offset: 0xe0
	// Line 254, Address: 0x12fa44, Func Offset: 0xe4
	// Line 256, Address: 0x12fa50, Func Offset: 0xf0
	// Line 259, Address: 0x12fa60, Func Offset: 0x100
	// Line 260, Address: 0x12fa68, Func Offset: 0x108
	// Line 261, Address: 0x12fa74, Func Offset: 0x114
	// Line 262, Address: 0x12fa7c, Func Offset: 0x11c
	// Line 263, Address: 0x12fa80, Func Offset: 0x120
	// Line 264, Address: 0x12fa88, Func Offset: 0x128
	// Line 265, Address: 0x12faa4, Func Offset: 0x144
	// Line 266, Address: 0x12fabc, Func Offset: 0x15c
	// Line 268, Address: 0x12fad4, Func Offset: 0x174
	// Line 271, Address: 0x12fad8, Func Offset: 0x178
	// Line 273, Address: 0x12fae8, Func Offset: 0x188
	// Line 278, Address: 0x12faf0, Func Offset: 0x190
	// Line 273, Address: 0x12faf4, Func Offset: 0x194
	// Line 280, Address: 0x12fb10, Func Offset: 0x1b0
	// Line 281, Address: 0x12fb34, Func Offset: 0x1d4
	// Line 286, Address: 0x12fb40, Func Offset: 0x1e0
	// Line 296, Address: 0x12fb48, Func Offset: 0x1e8
	// Line 286, Address: 0x12fb4c, Func Offset: 0x1ec
	// Line 287, Address: 0x12fb50, Func Offset: 0x1f0
	// Line 288, Address: 0x12fb60, Func Offset: 0x200
	// Line 299, Address: 0x12fb70, Func Offset: 0x210
	// Line 300, Address: 0x12fbac, Func Offset: 0x24c
	// Line 302, Address: 0x12fbc0, Func Offset: 0x260
	// Line 303, Address: 0x12fbd4, Func Offset: 0x274
	// Line 305, Address: 0x12fbe8, Func Offset: 0x288
	// Line 308, Address: 0x12fc10, Func Offset: 0x2b0
	// Line 309, Address: 0x12fc48, Func Offset: 0x2e8
	// Line 311, Address: 0x12fc60, Func Offset: 0x300
	// Line 314, Address: 0x12fc68, Func Offset: 0x308
	// Line 315, Address: 0x12fc70, Func Offset: 0x310
	// Line 314, Address: 0x12fc74, Func Offset: 0x314
	// Line 315, Address: 0x12fc80, Func Offset: 0x320
	// Line 316, Address: 0x12fc8c, Func Offset: 0x32c
	// Line 324, Address: 0x12fca0, Func Offset: 0x340
	// Line 325, Address: 0x12fcd0, Func Offset: 0x370
	// Line 324, Address: 0x12fcd4, Func Offset: 0x374
	// Line 325, Address: 0x12fcdc, Func Offset: 0x37c
	// Line 326, Address: 0x12fd08, Func Offset: 0x3a8
	// Line 325, Address: 0x12fd0c, Func Offset: 0x3ac
	// Line 326, Address: 0x12fd14, Func Offset: 0x3b4
	// Line 333, Address: 0x12fd48, Func Offset: 0x3e8
	// Line 332, Address: 0x12fd4c, Func Offset: 0x3ec
	// Line 334, Address: 0x12fd50, Func Offset: 0x3f0
	// Line 338, Address: 0x12fd58, Func Offset: 0x3f8
	// Line 339, Address: 0x12fd64, Func Offset: 0x404
	// Func End, Address: 0x12fd94, Func Offset: 0x434
}

// 
// Start address: 0x12fda0
void SetMtnFast(BH_PWORK* ewP, char* datP, int mode)
{
	int* dstP;
	_anon3* mkaP;
	_anon6* owP;
	_anon2* md2P;
	int obj_no;
	int flp;
	float* posP;
	float* keyP;
	// Line 353, Address: 0x12fda0, Func Offset: 0
	// Line 358, Address: 0x12fdb4, Func Offset: 0x14
	// Line 359, Address: 0x12fdb8, Func Offset: 0x18
	// Line 358, Address: 0x12fdbc, Func Offset: 0x1c
	// Line 359, Address: 0x12fdc4, Func Offset: 0x24
	// Line 358, Address: 0x12fdc8, Func Offset: 0x28
	// Line 359, Address: 0x12fdd0, Func Offset: 0x30
	// Line 358, Address: 0x12fdd4, Func Offset: 0x34
	// Line 359, Address: 0x12fdf4, Func Offset: 0x54
	// Line 358, Address: 0x12fe08, Func Offset: 0x68
	// Line 359, Address: 0x12fe0c, Func Offset: 0x6c
	// Line 363, Address: 0x12fe10, Func Offset: 0x70
	// Line 373, Address: 0x12fe34, Func Offset: 0x94
	// Line 363, Address: 0x12fe40, Func Offset: 0xa0
	// Line 364, Address: 0x12fe48, Func Offset: 0xa8
	// Line 365, Address: 0x12fe50, Func Offset: 0xb0
	// Line 370, Address: 0x12fe58, Func Offset: 0xb8
	// Line 375, Address: 0x12fe74, Func Offset: 0xd4
	// Line 376, Address: 0x12fe7c, Func Offset: 0xdc
	// Line 378, Address: 0x12fe98, Func Offset: 0xf8
	// Line 379, Address: 0x12fea8, Func Offset: 0x108
	// Line 383, Address: 0x12feb4, Func Offset: 0x114
	// Line 382, Address: 0x12fec8, Func Offset: 0x128
	// Line 383, Address: 0x12fecc, Func Offset: 0x12c
	// Line 385, Address: 0x12fed4, Func Offset: 0x134
	// Line 386, Address: 0x12fedc, Func Offset: 0x13c
	// Line 390, Address: 0x12fef4, Func Offset: 0x154
	// Line 391, Address: 0x12fefc, Func Offset: 0x15c
	// Line 392, Address: 0x12ff08, Func Offset: 0x168
	// Line 393, Address: 0x12ff10, Func Offset: 0x170
	// Line 394, Address: 0x12ff18, Func Offset: 0x178
	// Line 395, Address: 0x12ff1c, Func Offset: 0x17c
	// Line 396, Address: 0x12ff20, Func Offset: 0x180
	// Line 398, Address: 0x12ff24, Func Offset: 0x184
	// Line 400, Address: 0x12ff28, Func Offset: 0x188
	// Line 401, Address: 0x12ff2c, Func Offset: 0x18c
	// Line 403, Address: 0x12ff30, Func Offset: 0x190
	// Line 406, Address: 0x12ff40, Func Offset: 0x1a0
	// Func End, Address: 0x12ff48, Func Offset: 0x1a8
}

// 
// Start address: 0x12ff50
void SetMtnFastHokan(BH_PWORK* ewP, char* datP, int mode, float rate)
{
	short dlt;
	int* dstP;
	int sum;
	_anon3* mkaP;
	int* angP;
	_anon6* owP;
	_anon2* md2P;
	int obj_no;
	int flp;
	float* posP;
	float* keyP;
	float flp;
	int tmpS[3];
	int tmpD[3];
	// Line 418, Address: 0x12ff50, Func Offset: 0
	// Line 420, Address: 0x12ff74, Func Offset: 0x24
	// Line 425, Address: 0x12ff90, Func Offset: 0x40
	// Line 426, Address: 0x12ff94, Func Offset: 0x44
	// Line 425, Address: 0x12ff98, Func Offset: 0x48
	// Line 426, Address: 0x12ffa0, Func Offset: 0x50
	// Line 425, Address: 0x12ffa4, Func Offset: 0x54
	// Line 426, Address: 0x12ffac, Func Offset: 0x5c
	// Line 425, Address: 0x12ffb0, Func Offset: 0x60
	// Line 426, Address: 0x12ffd0, Func Offset: 0x80
	// Line 425, Address: 0x12ffe8, Func Offset: 0x98
	// Line 428, Address: 0x12ffec, Func Offset: 0x9c
	// Line 430, Address: 0x13000c, Func Offset: 0xbc
	// Line 431, Address: 0x130018, Func Offset: 0xc8
	// Line 432, Address: 0x130024, Func Offset: 0xd4
	// Line 433, Address: 0x13002c, Func Offset: 0xdc
	// Line 434, Address: 0x130030, Func Offset: 0xe0
	// Line 435, Address: 0x130038, Func Offset: 0xe8
	// Line 436, Address: 0x130054, Func Offset: 0x104
	// Line 437, Address: 0x13006c, Func Offset: 0x11c
	// Line 444, Address: 0x130084, Func Offset: 0x134
	// Line 447, Address: 0x130088, Func Offset: 0x138
	// Line 444, Address: 0x13008c, Func Offset: 0x13c
	// Line 447, Address: 0x130090, Func Offset: 0x140
	// Line 444, Address: 0x130098, Func Offset: 0x148
	// Line 449, Address: 0x1300ac, Func Offset: 0x15c
	// Line 450, Address: 0x1300b4, Func Offset: 0x164
	// Line 452, Address: 0x1300d0, Func Offset: 0x180
	// Line 453, Address: 0x1300e0, Func Offset: 0x190
	// Line 454, Address: 0x1300ec, Func Offset: 0x19c
	// Line 459, Address: 0x130100, Func Offset: 0x1b0
	// Line 454, Address: 0x130104, Func Offset: 0x1b4
	// Line 461, Address: 0x13010c, Func Offset: 0x1bc
	// Line 462, Address: 0x130130, Func Offset: 0x1e0
	// Line 467, Address: 0x130138, Func Offset: 0x1e8
	// Line 477, Address: 0x130140, Func Offset: 0x1f0
	// Line 467, Address: 0x130144, Func Offset: 0x1f4
	// Line 468, Address: 0x130148, Func Offset: 0x1f8
	// Line 469, Address: 0x130158, Func Offset: 0x208
	// Line 480, Address: 0x130168, Func Offset: 0x218
	// Line 481, Address: 0x1301a4, Func Offset: 0x254
	// Line 483, Address: 0x1301b8, Func Offset: 0x268
	// Line 484, Address: 0x1301cc, Func Offset: 0x27c
	// Line 486, Address: 0x1301e0, Func Offset: 0x290
	// Line 489, Address: 0x130208, Func Offset: 0x2b8
	// Line 490, Address: 0x130240, Func Offset: 0x2f0
	// Line 492, Address: 0x130258, Func Offset: 0x308
	// Line 495, Address: 0x130260, Func Offset: 0x310
	// Line 496, Address: 0x130268, Func Offset: 0x318
	// Line 495, Address: 0x13026c, Func Offset: 0x31c
	// Line 496, Address: 0x130278, Func Offset: 0x328
	// Line 497, Address: 0x130284, Func Offset: 0x334
	// Line 501, Address: 0x130298, Func Offset: 0x348
	// Line 506, Address: 0x1302a8, Func Offset: 0x358
	// Line 507, Address: 0x1302d8, Func Offset: 0x388
	// Line 506, Address: 0x1302dc, Func Offset: 0x38c
	// Line 507, Address: 0x1302e4, Func Offset: 0x394
	// Line 508, Address: 0x130310, Func Offset: 0x3c0
	// Line 507, Address: 0x130314, Func Offset: 0x3c4
	// Line 508, Address: 0x13031c, Func Offset: 0x3cc
	// Line 509, Address: 0x13034c, Func Offset: 0x3fc
	// Line 513, Address: 0x130354, Func Offset: 0x404
	// Line 514, Address: 0x130364, Func Offset: 0x414
	// Line 519, Address: 0x130378, Func Offset: 0x428
	// Line 520, Address: 0x1303b0, Func Offset: 0x460
	// Line 519, Address: 0x1303b8, Func Offset: 0x468
	// Line 520, Address: 0x1303c4, Func Offset: 0x474
	// Line 521, Address: 0x1303f4, Func Offset: 0x4a4
	// Line 520, Address: 0x1303fc, Func Offset: 0x4ac
	// Line 521, Address: 0x130408, Func Offset: 0x4b8
	// Line 523, Address: 0x130438, Func Offset: 0x4e8
	// Line 521, Address: 0x130444, Func Offset: 0x4f4
	// Line 523, Address: 0x13044c, Func Offset: 0x4fc
	// Line 526, Address: 0x130454, Func Offset: 0x504
	// Line 527, Address: 0x130458, Func Offset: 0x508
	// Line 528, Address: 0x13045c, Func Offset: 0x50c
	// Line 530, Address: 0x130460, Func Offset: 0x510
	// Line 534, Address: 0x130470, Func Offset: 0x520
	// Line 535, Address: 0x13047c, Func Offset: 0x52c
	// Func End, Address: 0x1304a4, Func Offset: 0x554
}

// 
// Start address: 0x1304b0
void SetMtnSlow(BH_PWORK* ewP, char* datP, int mode)
{
	short* dstP;
	short* srcP;
	_anon3* mkaP;
	int* angP;
	float* posP;
	float* dstP;
	float* srcP;
	_anon0* mkfP;
	_anon6* owP;
	_anon2* md2P;
	int obj_no;
	float flp_f;
	int flp_s;
	int dst_no;
	int src_no;
	_anon1* mnwP;
	float frac;
	// Line 547, Address: 0x1304b0, Func Offset: 0
	// Line 549, Address: 0x1304dc, Func Offset: 0x2c
	// Line 547, Address: 0x1304e0, Func Offset: 0x30
	// Line 549, Address: 0x1304e8, Func Offset: 0x38
	// Line 550, Address: 0x1304f4, Func Offset: 0x44
	// Line 549, Address: 0x130500, Func Offset: 0x50
	// Line 551, Address: 0x130508, Func Offset: 0x58
	// Line 550, Address: 0x13050c, Func Offset: 0x5c
	// Line 549, Address: 0x130514, Func Offset: 0x64
	// Line 550, Address: 0x130518, Func Offset: 0x68
	// Line 554, Address: 0x130520, Func Offset: 0x70
	// Line 552, Address: 0x130524, Func Offset: 0x74
	// Line 554, Address: 0x130528, Func Offset: 0x78
	// Line 555, Address: 0x130538, Func Offset: 0x88
	// Line 562, Address: 0x13054c, Func Offset: 0x9c
	// Line 564, Address: 0x130550, Func Offset: 0xa0
	// Line 565, Address: 0x130558, Func Offset: 0xa8
	// Line 566, Address: 0x130560, Func Offset: 0xb0
	// Line 567, Address: 0x130568, Func Offset: 0xb8
	// Line 570, Address: 0x130574, Func Offset: 0xc4
	// Line 571, Address: 0x1305a8, Func Offset: 0xf8
	// Line 573, Address: 0x1305c4, Func Offset: 0x114
	// Line 575, Address: 0x1305d4, Func Offset: 0x124
	// Line 577, Address: 0x1305d8, Func Offset: 0x128
	// Line 580, Address: 0x1305e0, Func Offset: 0x130
	// Line 578, Address: 0x1305e4, Func Offset: 0x134
	// Line 579, Address: 0x1305ec, Func Offset: 0x13c
	// Line 582, Address: 0x1305f0, Func Offset: 0x140
	// Line 579, Address: 0x1305f4, Func Offset: 0x144
	// Line 582, Address: 0x1305f8, Func Offset: 0x148
	// Line 580, Address: 0x1305fc, Func Offset: 0x14c
	// Line 582, Address: 0x13060c, Func Offset: 0x15c
	// Line 580, Address: 0x130610, Func Offset: 0x160
	// Line 582, Address: 0x130618, Func Offset: 0x168
	// Line 583, Address: 0x130628, Func Offset: 0x178
	// Line 584, Address: 0x130640, Func Offset: 0x190
	// Line 588, Address: 0x130658, Func Offset: 0x1a8
	// Line 590, Address: 0x130668, Func Offset: 0x1b8
	// Line 591, Address: 0x130670, Func Offset: 0x1c0
	// Line 590, Address: 0x130674, Func Offset: 0x1c4
	// Line 593, Address: 0x130690, Func Offset: 0x1e0
	// Line 594, Address: 0x130698, Func Offset: 0x1e8
	// Line 595, Address: 0x13069c, Func Offset: 0x1ec
	// Line 594, Address: 0x1306a0, Func Offset: 0x1f0
	// Line 597, Address: 0x1306a4, Func Offset: 0x1f4
	// Line 598, Address: 0x1306dc, Func Offset: 0x22c
	// Line 599, Address: 0x130720, Func Offset: 0x270
	// Line 600, Address: 0x130760, Func Offset: 0x2b0
	// Line 601, Address: 0x130768, Func Offset: 0x2b8
	// Line 603, Address: 0x130774, Func Offset: 0x2c4
	// Line 605, Address: 0x130778, Func Offset: 0x2c8
	// Line 606, Address: 0x13077c, Func Offset: 0x2cc
	// Line 608, Address: 0x130780, Func Offset: 0x2d0
	// Line 611, Address: 0x130790, Func Offset: 0x2e0
	// Func End, Address: 0x1307c8, Func Offset: 0x318
}

// 
// Start address: 0x1307d0
void SetMtnSlowHokan(BH_PWORK* ewP, char* datP, int mode, float rate)
{
	short dlt;
	int* dstP;
	int sum;
	short* dstP;
	short* srcP;
	int* bufP;
	_anon3* mkaP;
	int* angP;
	float* posP;
	float* dstP;
	float* srcP;
	_anon0* mkfP;
	_anon6* owP;
	_anon2* md2P;
	int obj_no;
	float flp_f;
	int flp_s;
	int dst_no;
	int src_no;
	_anon1* mnwP;
	float frac;
	// Line 623, Address: 0x1307d0, Func Offset: 0
	// Line 625, Address: 0x130800, Func Offset: 0x30
	// Line 623, Address: 0x130804, Func Offset: 0x34
	// Line 625, Address: 0x13080c, Func Offset: 0x3c
	// Line 626, Address: 0x130818, Func Offset: 0x48
	// Line 625, Address: 0x130828, Func Offset: 0x58
	// Line 627, Address: 0x130830, Func Offset: 0x60
	// Line 626, Address: 0x130834, Func Offset: 0x64
	// Line 625, Address: 0x13083c, Func Offset: 0x6c
	// Line 626, Address: 0x130840, Func Offset: 0x70
	// Line 630, Address: 0x130848, Func Offset: 0x78
	// Line 628, Address: 0x13084c, Func Offset: 0x7c
	// Line 630, Address: 0x130850, Func Offset: 0x80
	// Line 631, Address: 0x130860, Func Offset: 0x90
	// Line 638, Address: 0x130874, Func Offset: 0xa4
	// Line 640, Address: 0x130878, Func Offset: 0xa8
	// Line 641, Address: 0x130880, Func Offset: 0xb0
	// Line 642, Address: 0x130888, Func Offset: 0xb8
	// Line 643, Address: 0x130890, Func Offset: 0xc0
	// Line 646, Address: 0x13089c, Func Offset: 0xcc
	// Line 647, Address: 0x1308dc, Func Offset: 0x10c
	// Line 649, Address: 0x1308f8, Func Offset: 0x128
	// Line 652, Address: 0x130908, Func Offset: 0x138
	// Line 654, Address: 0x13090c, Func Offset: 0x13c
	// Line 657, Address: 0x130914, Func Offset: 0x144
	// Line 655, Address: 0x130918, Func Offset: 0x148
	// Line 656, Address: 0x130920, Func Offset: 0x150
	// Line 657, Address: 0x130928, Func Offset: 0x158
	// Line 659, Address: 0x130944, Func Offset: 0x174
	// Line 660, Address: 0x130950, Func Offset: 0x180
	// Line 661, Address: 0x13096c, Func Offset: 0x19c
	// Line 662, Address: 0x130984, Func Offset: 0x1b4
	// Line 663, Address: 0x130998, Func Offset: 0x1c8
	// Line 664, Address: 0x1309a0, Func Offset: 0x1d0
	// Line 665, Address: 0x1309cc, Func Offset: 0x1fc
	// Line 666, Address: 0x1309f4, Func Offset: 0x224
	// Line 668, Address: 0x130a1c, Func Offset: 0x24c
	// Line 672, Address: 0x130a20, Func Offset: 0x250
	// Line 673, Address: 0x130a30, Func Offset: 0x260
	// Line 677, Address: 0x130a34, Func Offset: 0x264
	// Line 673, Address: 0x130a3c, Func Offset: 0x26c
	// Line 676, Address: 0x130a40, Func Offset: 0x270
	// Line 673, Address: 0x130a44, Func Offset: 0x274
	// Line 679, Address: 0x130a60, Func Offset: 0x290
	// Line 680, Address: 0x130a68, Func Offset: 0x298
	// Line 681, Address: 0x130a70, Func Offset: 0x2a0
	// Line 683, Address: 0x130a74, Func Offset: 0x2a4
	// Line 681, Address: 0x130a78, Func Offset: 0x2a8
	// Line 683, Address: 0x130a7c, Func Offset: 0x2ac
	// Line 684, Address: 0x130ab0, Func Offset: 0x2e0
	// Line 685, Address: 0x130af4, Func Offset: 0x324
	// Line 686, Address: 0x130b34, Func Offset: 0x364
	// Line 687, Address: 0x130b3c, Func Offset: 0x36c
	// Line 695, Address: 0x130b48, Func Offset: 0x378
	// Line 698, Address: 0x130b50, Func Offset: 0x380
	// Line 699, Address: 0x130b8c, Func Offset: 0x3bc
	// Line 701, Address: 0x130ba0, Func Offset: 0x3d0
	// Line 702, Address: 0x130bb4, Func Offset: 0x3e4
	// Line 704, Address: 0x130bc8, Func Offset: 0x3f8
	// Line 707, Address: 0x130bf0, Func Offset: 0x420
	// Line 708, Address: 0x130c28, Func Offset: 0x458
	// Line 710, Address: 0x130c40, Func Offset: 0x470
	// Line 713, Address: 0x130c48, Func Offset: 0x478
	// Line 714, Address: 0x130c50, Func Offset: 0x480
	// Line 713, Address: 0x130c54, Func Offset: 0x484
	// Line 714, Address: 0x130c60, Func Offset: 0x490
	// Line 715, Address: 0x130c6c, Func Offset: 0x49c
	// Line 723, Address: 0x130c80, Func Offset: 0x4b0
	// Line 724, Address: 0x130cb0, Func Offset: 0x4e0
	// Line 723, Address: 0x130cb4, Func Offset: 0x4e4
	// Line 724, Address: 0x130cbc, Func Offset: 0x4ec
	// Line 725, Address: 0x130ce8, Func Offset: 0x518
	// Line 724, Address: 0x130cec, Func Offset: 0x51c
	// Line 725, Address: 0x130cf4, Func Offset: 0x524
	// Line 729, Address: 0x130d28, Func Offset: 0x558
	// Line 730, Address: 0x130d2c, Func Offset: 0x55c
	// Line 732, Address: 0x130d30, Func Offset: 0x560
	// Line 736, Address: 0x130d40, Func Offset: 0x570
	// Line 738, Address: 0x130d4c, Func Offset: 0x57c
	// Func End, Address: 0x130d88, Func Offset: 0x5b8
}

// 
// Start address: 0x130d90
void bhFixPosition(BH_PWORK* ewP, char* datP)
{
	_anon10 pos;
	// Line 752, Address: 0x130d90, Func Offset: 0
	// Line 756, Address: 0x130d9c, Func Offset: 0xc
	// Line 758, Address: 0x130dac, Func Offset: 0x1c
	// Line 760, Address: 0x130dbc, Func Offset: 0x2c
	// Line 762, Address: 0x130dcc, Func Offset: 0x3c
	// Func End, Address: 0x130ddc, Func Offset: 0x4c
}

// 
// Start address: 0x130de0
void bhCalcFixOffset(BH_PWORK* ewP, char* datP, _anon10* offP, _anon10* rtnP)
{
	_anon10 dst;
	_anon10 src;
	npobj* objP;
	_anon9* mlwP;
	_anon10 off;
	// Line 779, Address: 0x130de0, Func Offset: 0
	// Line 782, Address: 0x130dfc, Func Offset: 0x1c
	// Line 785, Address: 0x130e0c, Func Offset: 0x2c
	// Line 787, Address: 0x130e1c, Func Offset: 0x3c
	// Line 789, Address: 0x130e24, Func Offset: 0x44
	// Line 792, Address: 0x130e34, Func Offset: 0x54
	// Line 793, Address: 0x130e60, Func Offset: 0x80
	// Line 794, Address: 0x130e74, Func Offset: 0x94
	// Line 795, Address: 0x130e88, Func Offset: 0xa8
	// Line 796, Address: 0x130e90, Func Offset: 0xb0
	// Line 797, Address: 0x130e9c, Func Offset: 0xbc
	// Line 798, Address: 0x130eb0, Func Offset: 0xd0
	// Line 801, Address: 0x130ec4, Func Offset: 0xe4
	// Line 803, Address: 0x130ecc, Func Offset: 0xec
	// Line 805, Address: 0x130eec, Func Offset: 0x10c
	// Line 806, Address: 0x130f00, Func Offset: 0x120
	// Line 807, Address: 0x130f14, Func Offset: 0x134
	// Line 812, Address: 0x130f28, Func Offset: 0x148
	// Line 813, Address: 0x130f38, Func Offset: 0x158
	// Line 814, Address: 0x130f60, Func Offset: 0x180
	// Line 815, Address: 0x130f6c, Func Offset: 0x18c
	// Line 818, Address: 0x130f84, Func Offset: 0x1a4
	// Line 820, Address: 0x130f8c, Func Offset: 0x1ac
	// Func End, Address: 0x130fac, Func Offset: 0x1cc
}

// 
// Start address: 0x130fb0
void bhGetObjMotion(BH_PWORK* ewP, int obj_no, float* pos, int* ang)
{
	_anon3* mkaP;
	_anon0* mkfP;
	_anon2* md2P;
	char* rutP;
	int s_flp;
	float f_flp;
	// Line 839, Address: 0x130fb0, Func Offset: 0
	// Line 842, Address: 0x130fc0, Func Offset: 0x10
	// Line 840, Address: 0x130fc4, Func Offset: 0x14
	// Line 841, Address: 0x130fcc, Func Offset: 0x1c
	// Line 843, Address: 0x130fd0, Func Offset: 0x20
	// Line 844, Address: 0x130fd8, Func Offset: 0x28
	// Line 846, Address: 0x130fdc, Func Offset: 0x2c
	// Line 844, Address: 0x130fe0, Func Offset: 0x30
	// Line 846, Address: 0x130fe4, Func Offset: 0x34
	// Line 845, Address: 0x130fe8, Func Offset: 0x38
	// Line 846, Address: 0x130fec, Func Offset: 0x3c
	// Line 851, Address: 0x130ff0, Func Offset: 0x40
	// Line 853, Address: 0x131018, Func Offset: 0x68
	// Line 855, Address: 0x13101c, Func Offset: 0x6c
	// Line 856, Address: 0x131024, Func Offset: 0x74
	// Line 857, Address: 0x13103c, Func Offset: 0x8c
	// Line 859, Address: 0x131044, Func Offset: 0x94
	// Line 860, Address: 0x131050, Func Offset: 0xa0
	// Line 861, Address: 0x131058, Func Offset: 0xa8
	// Line 863, Address: 0x131060, Func Offset: 0xb0
	// Line 864, Address: 0x131068, Func Offset: 0xb8
	// Line 865, Address: 0x131074, Func Offset: 0xc4
	// Line 866, Address: 0x13107c, Func Offset: 0xcc
	// Line 867, Address: 0x131084, Func Offset: 0xd4
	// Line 868, Address: 0x131090, Func Offset: 0xe0
	// Line 872, Address: 0x13109c, Func Offset: 0xec
	// Func End, Address: 0x1310a4, Func Offset: 0xf4
}

// 
// Start address: 0x1310b0
void AngZyxToYzx(int* zyx, int* yzx)
{
	float b;
	float fCos2;
	float fCos1;
	float fCos0;
	float fSin2;
	float fSin1;
	float fSin0;
	// Line 878, Address: 0x1310b0, Func Offset: 0
	// Line 885, Address: 0x1310c4, Func Offset: 0x14
	// Line 886, Address: 0x1310d8, Func Offset: 0x28
	// Line 887, Address: 0x1310e8, Func Offset: 0x38
	// Line 890, Address: 0x1310f8, Func Offset: 0x48
	// Line 893, Address: 0x131100, Func Offset: 0x50
	// Line 890, Address: 0x13110c, Func Offset: 0x5c
	// Line 893, Address: 0x131110, Func Offset: 0x60
	// Line 894, Address: 0x13113c, Func Offset: 0x8c
	// Line 895, Address: 0x131168, Func Offset: 0xb8
	// Line 909, Address: 0x131190, Func Offset: 0xe0
	// Func End, Address: 0x1311a4, Func Offset: 0xf4
}

// 
// Start address: 0x1311b0
void AngYzxToZyx(int* yzx, int* zyx)
{
	float b;
	float fCos2;
	float fCos1;
	float fCos0;
	float fSin2;
	float fSin1;
	float fSin0;
	// Line 915, Address: 0x1311b0, Func Offset: 0
	// Line 922, Address: 0x1311c4, Func Offset: 0x14
	// Line 923, Address: 0x1311d8, Func Offset: 0x28
	// Line 924, Address: 0x1311e8, Func Offset: 0x38
	// Line 927, Address: 0x1311f8, Func Offset: 0x48
	// Line 930, Address: 0x131200, Func Offset: 0x50
	// Line 927, Address: 0x13120c, Func Offset: 0x5c
	// Line 930, Address: 0x131210, Func Offset: 0x60
	// Line 931, Address: 0x13123c, Func Offset: 0x8c
	// Line 932, Address: 0x131264, Func Offset: 0xb4
	// Line 949, Address: 0x131290, Func Offset: 0xe0
	// Func End, Address: 0x1312a4, Func Offset: 0xf4
}

