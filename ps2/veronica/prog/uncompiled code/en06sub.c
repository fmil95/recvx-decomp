typedef struct npobj;
typedef struct BH_PWORK;
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
typedef struct _anon10;

typedef void(*type_0)(BH_PWORK*);
typedef void(*type_12)(BH_PWORK*);

typedef void(*type_1)(BH_PWORK*)[3];
typedef char type_2[8];
typedef _anon8 type_3[3];
typedef _anon8 type_4[3][4];
typedef void* type_5[2];
typedef unsigned int type_6[2];
typedef float type_7[3];
typedef int type_8[3];
typedef float type_9[3];
typedef int type_10[64];
typedef float type_11[16];
typedef void(*type_13)(BH_PWORK*)[2];
typedef unsigned int type_14[1];
typedef unsigned int type_15[2];
typedef int* type_16[16];
typedef npobj* type_17[16];
typedef _anon4* type_18[16];
typedef _anon7 type_19[16];
typedef unsigned char type_20[64];

struct npobj
{
	unsigned int evalflags;
	_anon6* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
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
	_anon4* txp[16];
	_anon7 mdl[16];
	_anon7* mlwP;
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
	_anon0* mnwP;
	_anon0* mnwPb;
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
	_anon10 watr;
	_anon3* cpcl;
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

struct _anon0
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon1* md2P;
	unsigned short* atrP;
};

struct _anon1
{
	void* p[2];
};

struct _anon2
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon3
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon4
{
	_anon2* textures;
	unsigned int nbTexture;
};

struct _anon5
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon6
{
	int* vlist;
	short* plist;
	_anon8 center;
	float r;
};

struct _anon7
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon4* texP;
	_anon5* owP;
};

struct _anon8
{
	float x;
	float y;
	float z;
};

struct _anon9
{
	unsigned char flg;
	unsigned char type;
	unsigned char id;
	char flr_no;
	unsigned int attr;
	float px;
	float py;
	float pz;
	float w;
	float h;
	float d;
	unsigned char prm0;
	unsigned char prm1;
	unsigned char prm2;
	unsigned char prm3;
};

struct _anon10
{
	_anon8 c1;
	_anon8 c2;
	float r;
};

void(*bhEne06s_Mode0)(BH_PWORK*)[3];
void(*bhEne06s_MoveMode2)(BH_PWORK*)[2];
_anon8 CollisionOffset[3][4];

void bhEne06s(BH_PWORK* epw);
void bhEne06s_Init(BH_PWORK* epw);
void bhEne06s_Move(BH_PWORK* epw);
void bhEne06s_MV00(BH_PWORK* epw);
void bhEne06s_MV01(BH_PWORK* epw);
void bhEne06s_Dummy();
void bhEne06s_FloorCollision(BH_PWORK* epw);
void bhEne06s_WallCheck(BH_PWORK* epw);

// 
// Start address: 0x1bf2b0
void bhEne06s(BH_PWORK* epw)
{
	// Line 108, Address: 0x1bf2b0, Func Offset: 0
	// Line 110, Address: 0x1bf2c0, Func Offset: 0x10
	// Line 113, Address: 0x1bf2e0, Func Offset: 0x30
	// Line 114, Address: 0x1bf2f0, Func Offset: 0x40
	// Line 115, Address: 0x1bf300, Func Offset: 0x50
	// Line 116, Address: 0x1bf308, Func Offset: 0x58
	// Line 117, Address: 0x1bf310, Func Offset: 0x60
	// Line 118, Address: 0x1bf31c, Func Offset: 0x6c
	// Line 121, Address: 0x1bf324, Func Offset: 0x74
	// Func End, Address: 0x1bf334, Func Offset: 0x84
}

// 
// Start address: 0x1bf340
void bhEne06s_Init(BH_PWORK* epw)
{
	// Line 131, Address: 0x1bf340, Func Offset: 0
	// Line 133, Address: 0x1bf34c, Func Offset: 0xc
	// Line 135, Address: 0x1bf354, Func Offset: 0x14
	// Line 134, Address: 0x1bf358, Func Offset: 0x18
	// Line 135, Address: 0x1bf35c, Func Offset: 0x1c
	// Line 133, Address: 0x1bf360, Func Offset: 0x20
	// Line 134, Address: 0x1bf368, Func Offset: 0x28
	// Line 135, Address: 0x1bf36c, Func Offset: 0x2c
	// Line 136, Address: 0x1bf370, Func Offset: 0x30
	// Line 137, Address: 0x1bf374, Func Offset: 0x34
	// Line 140, Address: 0x1bf378, Func Offset: 0x38
	// Line 141, Address: 0x1bf380, Func Offset: 0x40
	// Line 142, Address: 0x1bf384, Func Offset: 0x44
	// Line 143, Address: 0x1bf388, Func Offset: 0x48
	// Line 146, Address: 0x1bf38c, Func Offset: 0x4c
	// Line 147, Address: 0x1bf398, Func Offset: 0x58
	// Line 149, Address: 0x1bf3a8, Func Offset: 0x68
	// Func End, Address: 0x1bf3b8, Func Offset: 0x78
}

// 
// Start address: 0x1bf3c0
void bhEne06s_Move(BH_PWORK* epw)
{
	// Line 161, Address: 0x1bf3c0, Func Offset: 0
	// Func End, Address: 0x1bf3e0, Func Offset: 0x20
}

// 
// Start address: 0x1bf3e0
void bhEne06s_MV00(BH_PWORK* epw)
{
	int ang;
	float out;
	_anon8 ov;
	_anon8 vd;
	_anon8 v;
	// Line 172, Address: 0x1bf3e0, Func Offset: 0
	// Line 173, Address: 0x1bf3f8, Func Offset: 0x18
	// Line 175, Address: 0x1bf424, Func Offset: 0x44
	// Line 176, Address: 0x1bf434, Func Offset: 0x54
	// Line 177, Address: 0x1bf444, Func Offset: 0x64
	// Line 180, Address: 0x1bf450, Func Offset: 0x70
	// Line 181, Address: 0x1bf488, Func Offset: 0xa8
	// Line 182, Address: 0x1bf4c4, Func Offset: 0xe4
	// Line 187, Address: 0x1bf4e4, Func Offset: 0x104
	// Line 182, Address: 0x1bf4e8, Func Offset: 0x108
	// Line 184, Address: 0x1bf500, Func Offset: 0x120
	// Line 186, Address: 0x1bf510, Func Offset: 0x130
	// Line 187, Address: 0x1bf51c, Func Offset: 0x13c
	// Line 188, Address: 0x1bf520, Func Offset: 0x140
	// Line 190, Address: 0x1bf52c, Func Offset: 0x14c
	// Line 191, Address: 0x1bf540, Func Offset: 0x160
	// Line 192, Address: 0x1bf55c, Func Offset: 0x17c
	// Line 193, Address: 0x1bf570, Func Offset: 0x190
	// Line 194, Address: 0x1bf584, Func Offset: 0x1a4
	// Line 195, Address: 0x1bf594, Func Offset: 0x1b4
	// Line 196, Address: 0x1bf59c, Func Offset: 0x1bc
	// Line 199, Address: 0x1bf5a8, Func Offset: 0x1c8
	// Line 200, Address: 0x1bf5b4, Func Offset: 0x1d4
	// Line 201, Address: 0x1bf5c0, Func Offset: 0x1e0
	// Line 202, Address: 0x1bf5c8, Func Offset: 0x1e8
	// Line 205, Address: 0x1bf5d0, Func Offset: 0x1f0
	// Line 210, Address: 0x1bf5dc, Func Offset: 0x1fc
	// Line 213, Address: 0x1bf5e0, Func Offset: 0x200
	// Line 210, Address: 0x1bf5e4, Func Offset: 0x204
	// Line 211, Address: 0x1bf5ec, Func Offset: 0x20c
	// Line 212, Address: 0x1bf5f8, Func Offset: 0x218
	// Line 213, Address: 0x1bf604, Func Offset: 0x224
	// Line 214, Address: 0x1bf610, Func Offset: 0x230
	// Line 215, Address: 0x1bf62c, Func Offset: 0x24c
	// Line 216, Address: 0x1bf644, Func Offset: 0x264
	// Line 217, Address: 0x1bf650, Func Offset: 0x270
	// Line 219, Address: 0x1bf65c, Func Offset: 0x27c
	// Line 220, Address: 0x1bf66c, Func Offset: 0x28c
	// Line 223, Address: 0x1bf678, Func Offset: 0x298
	// Line 224, Address: 0x1bf680, Func Offset: 0x2a0
	// Line 225, Address: 0x1bf6a0, Func Offset: 0x2c0
	// Line 226, Address: 0x1bf6c0, Func Offset: 0x2e0
	// Line 227, Address: 0x1bf6cc, Func Offset: 0x2ec
	// Line 228, Address: 0x1bf6d4, Func Offset: 0x2f4
	// Line 229, Address: 0x1bf6e0, Func Offset: 0x300
	// Line 230, Address: 0x1bf6e8, Func Offset: 0x308
	// Line 229, Address: 0x1bf6ec, Func Offset: 0x30c
	// Line 230, Address: 0x1bf6f4, Func Offset: 0x314
	// Line 232, Address: 0x1bf6f8, Func Offset: 0x318
	// Line 234, Address: 0x1bf704, Func Offset: 0x324
	// Line 235, Address: 0x1bf710, Func Offset: 0x330
	// Line 236, Address: 0x1bf71c, Func Offset: 0x33c
	// Line 238, Address: 0x1bf728, Func Offset: 0x348
	// Func End, Address: 0x1bf740, Func Offset: 0x360
}

// 
// Start address: 0x1bf740
void bhEne06s_MV01(BH_PWORK* epw)
{
	int ang;
	float out;
	_anon8 ov;
	_anon8 vd;
	_anon8 avec;
	// Line 248, Address: 0x1bf740, Func Offset: 0
	// Line 251, Address: 0x1bf754, Func Offset: 0x14
	// Line 253, Address: 0x1bf784, Func Offset: 0x44
	// Line 254, Address: 0x1bf794, Func Offset: 0x54
	// Line 255, Address: 0x1bf7a4, Func Offset: 0x64
	// Line 258, Address: 0x1bf7b0, Func Offset: 0x70
	// Line 259, Address: 0x1bf7e8, Func Offset: 0xa8
	// Line 260, Address: 0x1bf824, Func Offset: 0xe4
	// Line 266, Address: 0x1bf840, Func Offset: 0x100
	// Line 260, Address: 0x1bf844, Func Offset: 0x104
	// Line 266, Address: 0x1bf848, Func Offset: 0x108
	// Line 260, Address: 0x1bf84c, Func Offset: 0x10c
	// Line 266, Address: 0x1bf85c, Func Offset: 0x11c
	// Line 260, Address: 0x1bf860, Func Offset: 0x120
	// Line 262, Address: 0x1bf868, Func Offset: 0x128
	// Line 263, Address: 0x1bf878, Func Offset: 0x138
	// Line 266, Address: 0x1bf884, Func Offset: 0x144
	// Line 268, Address: 0x1bf8a8, Func Offset: 0x168
	// Line 270, Address: 0x1bf8b4, Func Offset: 0x174
	// Line 272, Address: 0x1bf8c8, Func Offset: 0x188
	// Line 271, Address: 0x1bf8cc, Func Offset: 0x18c
	// Line 274, Address: 0x1bf8d0, Func Offset: 0x190
	// Line 272, Address: 0x1bf8d4, Func Offset: 0x194
	// Line 274, Address: 0x1bf8d8, Func Offset: 0x198
	// Line 275, Address: 0x1bf8e0, Func Offset: 0x1a0
	// Line 276, Address: 0x1bf8f0, Func Offset: 0x1b0
	// Line 277, Address: 0x1bf90c, Func Offset: 0x1cc
	// Line 280, Address: 0x1bf920, Func Offset: 0x1e0
	// Line 281, Address: 0x1bf92c, Func Offset: 0x1ec
	// Line 282, Address: 0x1bf938, Func Offset: 0x1f8
	// Line 284, Address: 0x1bf944, Func Offset: 0x204
	// Line 286, Address: 0x1bf968, Func Offset: 0x228
	// Line 287, Address: 0x1bf97c, Func Offset: 0x23c
	// Line 288, Address: 0x1bf990, Func Offset: 0x250
	// Line 289, Address: 0x1bf9a0, Func Offset: 0x260
	// Line 290, Address: 0x1bf9a8, Func Offset: 0x268
	// Line 291, Address: 0x1bf9ac, Func Offset: 0x26c
	// Line 290, Address: 0x1bf9b0, Func Offset: 0x270
	// Line 291, Address: 0x1bf9b8, Func Offset: 0x278
	// Line 294, Address: 0x1bf9bc, Func Offset: 0x27c
	// Line 295, Address: 0x1bf9c8, Func Offset: 0x288
	// Line 296, Address: 0x1bf9d4, Func Offset: 0x294
	// Line 297, Address: 0x1bf9dc, Func Offset: 0x29c
	// Line 301, Address: 0x1bf9e4, Func Offset: 0x2a4
	// Line 306, Address: 0x1bf9f0, Func Offset: 0x2b0
	// Line 307, Address: 0x1bfa14, Func Offset: 0x2d4
	// Line 308, Address: 0x1bfa24, Func Offset: 0x2e4
	// Line 309, Address: 0x1bfa40, Func Offset: 0x300
	// Line 310, Address: 0x1bfa58, Func Offset: 0x318
	// Line 311, Address: 0x1bfa64, Func Offset: 0x324
	// Line 313, Address: 0x1bfa70, Func Offset: 0x330
	// Line 314, Address: 0x1bfa7c, Func Offset: 0x33c
	// Line 315, Address: 0x1bfa90, Func Offset: 0x350
	// Line 318, Address: 0x1bfa9c, Func Offset: 0x35c
	// Line 319, Address: 0x1bfac4, Func Offset: 0x384
	// Line 320, Address: 0x1bfae4, Func Offset: 0x3a4
	// Line 321, Address: 0x1bfaec, Func Offset: 0x3ac
	// Line 322, Address: 0x1bfb0c, Func Offset: 0x3cc
	// Line 323, Address: 0x1bfb18, Func Offset: 0x3d8
	// Line 324, Address: 0x1bfb20, Func Offset: 0x3e0
	// Line 331, Address: 0x1bfb48, Func Offset: 0x408
	// Line 332, Address: 0x1bfb54, Func Offset: 0x414
	// Line 333, Address: 0x1bfb60, Func Offset: 0x420
	// Line 335, Address: 0x1bfb6c, Func Offset: 0x42c
	// Line 336, Address: 0x1bfb74, Func Offset: 0x434
	// Line 338, Address: 0x1bfb7c, Func Offset: 0x43c
	// Line 339, Address: 0x1bfb80, Func Offset: 0x440
	// Line 342, Address: 0x1bfb90, Func Offset: 0x450
	// Line 343, Address: 0x1bfb9c, Func Offset: 0x45c
	// Line 344, Address: 0x1bfba8, Func Offset: 0x468
	// Line 346, Address: 0x1bfbb4, Func Offset: 0x474
	// Func End, Address: 0x1bfbcc, Func Offset: 0x48c
}

// 
// Start address: 0x1bfbd0
void bhEne06s_Dummy()
{
	// Line 358, Address: 0x1bfbd0, Func Offset: 0
	// Func End, Address: 0x1bfbd8, Func Offset: 0x8
}

// 
// Start address: 0x1bfbe0
void bhEne06s_FloorCollision(BH_PWORK* epw)
{
	_anon9* hp;
	// Line 368, Address: 0x1bfbe0, Func Offset: 0
	// Line 371, Address: 0x1bfbec, Func Offset: 0xc
	// Line 373, Address: 0x1bfc00, Func Offset: 0x20
	// Line 374, Address: 0x1bfc0c, Func Offset: 0x2c
	// Line 375, Address: 0x1bfc14, Func Offset: 0x34
	// Line 376, Address: 0x1bfc20, Func Offset: 0x40
	// Line 377, Address: 0x1bfc2c, Func Offset: 0x4c
	// Line 378, Address: 0x1bfc48, Func Offset: 0x68
	// Line 380, Address: 0x1bfc54, Func Offset: 0x74
	// Line 382, Address: 0x1bfc70, Func Offset: 0x90
	// Line 384, Address: 0x1bfc74, Func Offset: 0x94
	// Line 386, Address: 0x1bfc90, Func Offset: 0xb0
	// Line 387, Address: 0x1bfc94, Func Offset: 0xb4
	// Line 391, Address: 0x1bfc9c, Func Offset: 0xbc
	// Line 392, Address: 0x1bfca8, Func Offset: 0xc8
	// Line 393, Address: 0x1bfcb4, Func Offset: 0xd4
	// Line 394, Address: 0x1bfcc0, Func Offset: 0xe0
	// Func End, Address: 0x1bfcd0, Func Offset: 0xf0
}

// 
// Start address: 0x1bfcd0
void bhEne06s_WallCheck(BH_PWORK* epw)
{
	_anon9* hp;
	int i;
	_anon8 vec;
	// Line 404, Address: 0x1bfcd0, Func Offset: 0
	// Line 409, Address: 0x1bfce4, Func Offset: 0x14
	// Line 411, Address: 0x1bfcf8, Func Offset: 0x28
	// Line 412, Address: 0x1bfd00, Func Offset: 0x30
	// Line 413, Address: 0x1bfd2c, Func Offset: 0x5c
	// Line 414, Address: 0x1bfd38, Func Offset: 0x68
	// Line 415, Address: 0x1bfd4c, Func Offset: 0x7c
	// Line 416, Address: 0x1bfd54, Func Offset: 0x84
	// Line 417, Address: 0x1bfd60, Func Offset: 0x90
	// Line 418, Address: 0x1bfd6c, Func Offset: 0x9c
	// Line 419, Address: 0x1bfd88, Func Offset: 0xb8
	// Line 422, Address: 0x1bfd94, Func Offset: 0xc4
	// Line 423, Address: 0x1bfd9c, Func Offset: 0xcc
	// Line 424, Address: 0x1bfda0, Func Offset: 0xd0
	// Line 426, Address: 0x1bfdbc, Func Offset: 0xec
	// Line 428, Address: 0x1bfdc0, Func Offset: 0xf0
	// Line 430, Address: 0x1bfddc, Func Offset: 0x10c
	// Line 431, Address: 0x1bfde0, Func Offset: 0x110
	// Line 434, Address: 0x1bfde8, Func Offset: 0x118
	// Line 439, Address: 0x1bfdf4, Func Offset: 0x124
	// Line 440, Address: 0x1bfe00, Func Offset: 0x130
	// Line 443, Address: 0x1bfe10, Func Offset: 0x140
	// Line 448, Address: 0x1bfe18, Func Offset: 0x148
	// Line 443, Address: 0x1bfe24, Func Offset: 0x154
	// Line 444, Address: 0x1bfe28, Func Offset: 0x158
	// Line 445, Address: 0x1bfe34, Func Offset: 0x164
	// Line 448, Address: 0x1bfe40, Func Offset: 0x170
	// Line 449, Address: 0x1bfe64, Func Offset: 0x194
	// Func End, Address: 0x1bfe7c, Func Offset: 0x1ac
}

