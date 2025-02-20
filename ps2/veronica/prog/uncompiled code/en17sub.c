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

typedef void(*type_3)(BH_PWORK*);
typedef void(*type_10)(BH_PWORK*);

typedef char type_0[8];
typedef void* type_1[2];
typedef unsigned int type_2[2];
typedef void(*type_4)(BH_PWORK*)[4];
typedef float type_5[3];
typedef int type_6[3];
typedef float type_7[3];
typedef int type_8[64];
typedef float type_9[16];
typedef void(*type_11)(BH_PWORK*)[4];
typedef float type_12[3];
typedef float type_13[3][6];
typedef unsigned int type_14[1];
typedef unsigned int type_15[2];
typedef int* type_16[16];
typedef npobj* type_17[16];
typedef _anon6* type_18[16];
typedef _anon8 type_19[16];
typedef unsigned char type_20[64];

struct npobj
{
	unsigned int evalflags;
	_anon7* model;
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
	_anon6* txp[16];
	_anon8 mdl[16];
	_anon8* mlwP;
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

struct _anon0
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon3* md2P;
	unsigned short* atrP;
};

struct _anon1
{
	int keys;
	int* iparam;
	float* fparam;
};

struct _anon2
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon3
{
	void* p[2];
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
	_anon4* textures;
	unsigned int nbTexture;
};

struct _anon7
{
	int* vlist;
	short* plist;
	_anon9 center;
	float r;
};

struct _anon8
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon6* texP;
	_anon2* owP;
};

struct _anon9
{
	float x;
	float y;
	float z;
};

struct _anon10
{
	_anon9 c1;
	_anon9 c2;
	float r;
};

void(*bhEne17LArm_Mode0)(BH_PWORK*)[4];
void(*bhEne17RArm_Mode0)(BH_PWORK*)[4];

void bhEne17LArm(BH_PWORK* epw);
void bhEne17LArm_Init(BH_PWORK* epw);
void bhEne17LArm_Move();
void bhEne17RArm(BH_PWORK* epw);
void bhEne17RArm_Init(BH_PWORK* epw);
void bhEne17RArm_Move();
void bhEne17_AxsCheck(BH_PWORK* epw);

// 
// Start address: 0x1ee700
void bhEne17LArm(BH_PWORK* epw)
{
	npobj* obj;
	BH_PWORK* epp;
	// Line 96, Address: 0x1ee700, Func Offset: 0
	// Line 101, Address: 0x1ee714, Func Offset: 0x14
	// Line 103, Address: 0x1ee734, Func Offset: 0x34
	// Line 105, Address: 0x1ee73c, Func Offset: 0x3c
	// Line 107, Address: 0x1ee750, Func Offset: 0x50
	// Line 108, Address: 0x1ee768, Func Offset: 0x68
	// Line 111, Address: 0x1ee770, Func Offset: 0x70
	// Line 115, Address: 0x1ee77c, Func Offset: 0x7c
	// Line 116, Address: 0x1ee780, Func Offset: 0x80
	// Line 115, Address: 0x1ee788, Func Offset: 0x88
	// Line 116, Address: 0x1ee78c, Func Offset: 0x8c
	// Line 118, Address: 0x1ee794, Func Offset: 0x94
	// Line 119, Address: 0x1ee79c, Func Offset: 0x9c
	// Line 122, Address: 0x1ee7a4, Func Offset: 0xa4
	// Line 136, Address: 0x1ee7b4, Func Offset: 0xb4
	// Func End, Address: 0x1ee7c8, Func Offset: 0xc8
}

// 
// Start address: 0x1ee7d0
void bhEne17LArm_Init(BH_PWORK* epw)
{
	int i;
	float* ax_p2;
	float* ax_p1;
	BH_PWORK* epp;
	// Line 155, Address: 0x1ee7d0, Func Offset: 0
	// Line 166, Address: 0x1ee7d4, Func Offset: 0x4
	// Line 159, Address: 0x1ee7d8, Func Offset: 0x8
	// Line 160, Address: 0x1ee7dc, Func Offset: 0xc
	// Line 161, Address: 0x1ee7e8, Func Offset: 0x18
	// Line 164, Address: 0x1ee7f4, Func Offset: 0x24
	// Line 165, Address: 0x1ee7f8, Func Offset: 0x28
	// Line 170, Address: 0x1ee7fc, Func Offset: 0x2c
	// Line 168, Address: 0x1ee800, Func Offset: 0x30
	// Line 169, Address: 0x1ee804, Func Offset: 0x34
	// Line 170, Address: 0x1ee808, Func Offset: 0x38
	// Line 171, Address: 0x1ee818, Func Offset: 0x48
	// Line 173, Address: 0x1ee81c, Func Offset: 0x4c
	// Line 171, Address: 0x1ee820, Func Offset: 0x50
	// Line 172, Address: 0x1ee824, Func Offset: 0x54
	// Line 177, Address: 0x1ee828, Func Offset: 0x58
	// Line 175, Address: 0x1ee82c, Func Offset: 0x5c
	// Line 176, Address: 0x1ee830, Func Offset: 0x60
	// Line 177, Address: 0x1ee834, Func Offset: 0x64
	// Line 178, Address: 0x1ee844, Func Offset: 0x74
	// Line 179, Address: 0x1ee84c, Func Offset: 0x7c
	// Line 180, Address: 0x1ee850, Func Offset: 0x80
	// Line 182, Address: 0x1ee854, Func Offset: 0x84
	// Func End, Address: 0x1ee85c, Func Offset: 0x8c
}

// 
// Start address: 0x1ee860
void bhEne17LArm_Move()
{
	// Line 201, Address: 0x1ee860, Func Offset: 0
	// Func End, Address: 0x1ee868, Func Offset: 0x8
}

// 
// Start address: 0x1ee870
void bhEne17RArm(BH_PWORK* epw)
{
	// Line 219, Address: 0x1ee870, Func Offset: 0
	// Line 220, Address: 0x1ee880, Func Offset: 0x10
	// Line 222, Address: 0x1ee8a0, Func Offset: 0x30
	// Line 223, Address: 0x1ee8a8, Func Offset: 0x38
	// Func End, Address: 0x1ee8b8, Func Offset: 0x48
}

// 
// Start address: 0x1ee8c0
void bhEne17RArm_Init(BH_PWORK* epw)
{
	// Line 242, Address: 0x1ee8c0, Func Offset: 0
	// Line 243, Address: 0x1ee8c4, Func Offset: 0x4
	// Line 246, Address: 0x1ee8c8, Func Offset: 0x8
	// Line 243, Address: 0x1ee8cc, Func Offset: 0xc
	// Line 244, Address: 0x1ee8d4, Func Offset: 0x14
	// Line 246, Address: 0x1ee8e0, Func Offset: 0x20
	// Line 247, Address: 0x1ee8e4, Func Offset: 0x24
	// Line 248, Address: 0x1ee8e8, Func Offset: 0x28
	// Line 250, Address: 0x1ee8ec, Func Offset: 0x2c
	// Func End, Address: 0x1ee8f4, Func Offset: 0x34
}

// 
// Start address: 0x1ee900
void bhEne17RArm_Move()
{
	// Line 269, Address: 0x1ee900, Func Offset: 0
	// Func End, Address: 0x1ee908, Func Offset: 0x8
}

// 
// Start address: 0x1ee910
void bhEne17_AxsCheck(BH_PWORK* epw)
{
	float fparam;
	int iparam;
	_anon1 attr;
	float idata[3][6];
	int i;
	_anon9 pd;
	_anon9 ps;
	_anon2* owk;
	BH_PWORK* epp;
	// Line 291, Address: 0x1ee910, Func Offset: 0
	// Line 298, Address: 0x1ee928, Func Offset: 0x18
	// Line 292, Address: 0x1ee92c, Func Offset: 0x1c
	// Line 303, Address: 0x1ee930, Func Offset: 0x20
	// Line 304, Address: 0x1ee934, Func Offset: 0x24
	// Line 298, Address: 0x1ee93c, Func Offset: 0x2c
	// Line 300, Address: 0x1ee944, Func Offset: 0x34
	// Line 301, Address: 0x1ee948, Func Offset: 0x38
	// Line 304, Address: 0x1ee94c, Func Offset: 0x3c
	// Line 306, Address: 0x1ee958, Func Offset: 0x48
	// Line 308, Address: 0x1ee960, Func Offset: 0x50
	// Line 315, Address: 0x1ee964, Func Offset: 0x54
	// Line 308, Address: 0x1ee968, Func Offset: 0x58
	// Line 309, Address: 0x1ee974, Func Offset: 0x64
	// Line 310, Address: 0x1ee984, Func Offset: 0x74
	// Line 312, Address: 0x1ee994, Func Offset: 0x84
	// Line 313, Address: 0x1ee9a4, Func Offset: 0x94
	// Line 314, Address: 0x1ee9b4, Func Offset: 0xa4
	// Line 315, Address: 0x1ee9c4, Func Offset: 0xb4
	// Line 316, Address: 0x1ee9cc, Func Offset: 0xbc
	// Line 317, Address: 0x1ee9e8, Func Offset: 0xd8
	// Line 335, Address: 0x1ee9ec, Func Offset: 0xdc
	// Line 317, Address: 0x1ee9f0, Func Offset: 0xe0
	// Line 331, Address: 0x1ee9f4, Func Offset: 0xe4
	// Line 317, Address: 0x1ee9fc, Func Offset: 0xec
	// Line 318, Address: 0x1eea04, Func Offset: 0xf4
	// Line 332, Address: 0x1eea0c, Func Offset: 0xfc
	// Line 333, Address: 0x1eea10, Func Offset: 0x100
	// Line 318, Address: 0x1eea14, Func Offset: 0x104
	// Line 319, Address: 0x1eea1c, Func Offset: 0x10c
	// Line 335, Address: 0x1eea24, Func Offset: 0x114
	// Line 319, Address: 0x1eea30, Func Offset: 0x120
	// Line 320, Address: 0x1eea38, Func Offset: 0x128
	// Line 321, Address: 0x1eea48, Func Offset: 0x138
	// Line 330, Address: 0x1eea58, Func Offset: 0x148
	// Line 331, Address: 0x1eea5c, Func Offset: 0x14c
	// Line 332, Address: 0x1eea60, Func Offset: 0x150
	// Line 333, Address: 0x1eea64, Func Offset: 0x154
	// Line 337, Address: 0x1eea6c, Func Offset: 0x15c
	// Line 340, Address: 0x1eea70, Func Offset: 0x160
	// Line 337, Address: 0x1eea78, Func Offset: 0x168
	// Line 338, Address: 0x1eea84, Func Offset: 0x174
	// Line 339, Address: 0x1eea94, Func Offset: 0x184
	// Line 340, Address: 0x1eeaa8, Func Offset: 0x198
	// Line 342, Address: 0x1eeab0, Func Offset: 0x1a0
	// Line 345, Address: 0x1eeab4, Func Offset: 0x1a4
	// Line 342, Address: 0x1eeabc, Func Offset: 0x1ac
	// Line 343, Address: 0x1eeac4, Func Offset: 0x1b4
	// Line 344, Address: 0x1eead0, Func Offset: 0x1c0
	// Line 347, Address: 0x1eeadc, Func Offset: 0x1cc
	// Line 348, Address: 0x1eeb10, Func Offset: 0x200
	// Line 351, Address: 0x1eeb20, Func Offset: 0x210
	// Line 353, Address: 0x1eeb28, Func Offset: 0x218
	// Line 356, Address: 0x1eeb2c, Func Offset: 0x21c
	// Line 353, Address: 0x1eeb34, Func Offset: 0x224
	// Line 354, Address: 0x1eeb40, Func Offset: 0x230
	// Line 355, Address: 0x1eeb50, Func Offset: 0x240
	// Line 356, Address: 0x1eeb64, Func Offset: 0x254
	// Line 358, Address: 0x1eeb6c, Func Offset: 0x25c
	// Line 361, Address: 0x1eeb70, Func Offset: 0x260
	// Line 358, Address: 0x1eeb78, Func Offset: 0x268
	// Line 359, Address: 0x1eeb80, Func Offset: 0x270
	// Line 360, Address: 0x1eeb8c, Func Offset: 0x27c
	// Line 363, Address: 0x1eeb98, Func Offset: 0x288
	// Line 364, Address: 0x1eebcc, Func Offset: 0x2bc
	// Line 367, Address: 0x1eebdc, Func Offset: 0x2cc
	// Func End, Address: 0x1eebf8, Func Offset: 0x2e8
}

