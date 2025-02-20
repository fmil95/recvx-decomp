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

typedef void(*type_1)(BH_PWORK*);
typedef void(*type_4)(BH_PWORK*);

typedef char type_0[8];
typedef void(*type_2)(BH_PWORK*)[8];
typedef void* type_3[2];
typedef void(*type_5)(BH_PWORK*)[6];
typedef unsigned int type_6[2];
typedef float type_7[3];
typedef int type_8[3];
typedef float type_9[3];
typedef int type_10[64];
typedef float type_11[16];
typedef unsigned int type_12[1];
typedef unsigned int type_13[2];
typedef int* type_14[16];
typedef npobj* type_15[16];
typedef _anon4* type_16[16];
typedef _anon7 type_17[16];
typedef unsigned char type_18[64];

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

struct _anon0
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon1* md2P;
	unsigned short* atrP;
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
	_anon9 watr;
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
	_anon8 c1;
	_anon8 c2;
	float r;
};

void(*bhEne20_Mode0)(BH_PWORK*)[6];
void(*bhEne20_MoveMode2)(BH_PWORK*)[8];

void bhEne20(BH_PWORK* epw);
void bhEne20_Init(BH_PWORK* epw);
void bhEne20_Move(BH_PWORK* epw);
void bhEne20_MV00(BH_PWORK* epw);
void bhEne20_MV01(BH_PWORK* epw);
void bhEne20_MV02(BH_PWORK* epw);
void bhEne20_MV03(BH_PWORK* epw);
void bhEne20_MV04(BH_PWORK* epw);
void bhEne20_MV05(BH_PWORK* epw);
void bhEne20_MV06(BH_PWORK* epw);
void bhEne20_MV07(BH_PWORK* epw);
void bhEne20_Nage();
void bhEne20_Damage();
void bhEne20_Die();

// 
// Start address: 0x1f74a0
void bhEne20(BH_PWORK* epw)
{
	// Line 132, Address: 0x1f74a0, Func Offset: 0
	// Line 134, Address: 0x1f74b0, Func Offset: 0x10
	// Line 137, Address: 0x1f74d0, Func Offset: 0x30
	// Line 140, Address: 0x1f74e4, Func Offset: 0x44
	// Line 141, Address: 0x1f74ec, Func Offset: 0x4c
	// Func End, Address: 0x1f74fc, Func Offset: 0x5c
}

// 
// Start address: 0x1f7500
void bhEne20_Init(BH_PWORK* epw)
{
	float dz;
	float dx;
	// Line 152, Address: 0x1f7500, Func Offset: 0
	// Line 157, Address: 0x1f750c, Func Offset: 0xc
	// Line 158, Address: 0x1f7518, Func Offset: 0x18
	// Line 162, Address: 0x1f7528, Func Offset: 0x28
	// Line 164, Address: 0x1f752c, Func Offset: 0x2c
	// Line 170, Address: 0x1f7530, Func Offset: 0x30
	// Line 162, Address: 0x1f7534, Func Offset: 0x34
	// Line 163, Address: 0x1f753c, Func Offset: 0x3c
	// Line 164, Address: 0x1f7548, Func Offset: 0x48
	// Line 166, Address: 0x1f7554, Func Offset: 0x54
	// Line 167, Address: 0x1f7558, Func Offset: 0x58
	// Line 168, Address: 0x1f755c, Func Offset: 0x5c
	// Line 169, Address: 0x1f7560, Func Offset: 0x60
	// Line 170, Address: 0x1f7564, Func Offset: 0x64
	// Line 172, Address: 0x1f7568, Func Offset: 0x68
	// Line 176, Address: 0x1f7574, Func Offset: 0x74
	// Line 177, Address: 0x1f7578, Func Offset: 0x78
	// Line 176, Address: 0x1f757c, Func Offset: 0x7c
	// Line 178, Address: 0x1f7584, Func Offset: 0x84
	// Line 176, Address: 0x1f7588, Func Offset: 0x88
	// Line 178, Address: 0x1f758c, Func Offset: 0x8c
	// Line 179, Address: 0x1f7590, Func Offset: 0x90
	// Line 183, Address: 0x1f75b0, Func Offset: 0xb0
	// Line 184, Address: 0x1f75b4, Func Offset: 0xb4
	// Line 185, Address: 0x1f75b8, Func Offset: 0xb8
	// Line 186, Address: 0x1f75bc, Func Offset: 0xbc
	// Line 187, Address: 0x1f75c4, Func Offset: 0xc4
	// Line 191, Address: 0x1f75c8, Func Offset: 0xc8
	// Line 188, Address: 0x1f75cc, Func Offset: 0xcc
	// Line 191, Address: 0x1f75d0, Func Offset: 0xd0
	// Line 192, Address: 0x1f75d4, Func Offset: 0xd4
	// Line 193, Address: 0x1f75d8, Func Offset: 0xd8
	// Line 194, Address: 0x1f75dc, Func Offset: 0xdc
	// Line 198, Address: 0x1f75e0, Func Offset: 0xe0
	// Line 197, Address: 0x1f75e4, Func Offset: 0xe4
	// Line 198, Address: 0x1f75e8, Func Offset: 0xe8
	// Line 199, Address: 0x1f75ec, Func Offset: 0xec
	// Line 200, Address: 0x1f75fc, Func Offset: 0xfc
	// Func End, Address: 0x1f760c, Func Offset: 0x10c
}

// 
// Start address: 0x1f7610
void bhEne20_Move(BH_PWORK* epw)
{
	// Line 223, Address: 0x1f7610, Func Offset: 0
	// Line 225, Address: 0x1f7618, Func Offset: 0x8
	// Line 226, Address: 0x1f7628, Func Offset: 0x18
	// Line 227, Address: 0x1f7648, Func Offset: 0x38
	// Func End, Address: 0x1f7654, Func Offset: 0x44
}

// 
// Start address: 0x1f7660
void bhEne20_MV00(BH_PWORK* epw)
{
	unsigned int rnd;
	// Line 237, Address: 0x1f7660, Func Offset: 0
	// Line 240, Address: 0x1f7670, Func Offset: 0x10
	// Line 243, Address: 0x1f7690, Func Offset: 0x30
	// Line 244, Address: 0x1f769c, Func Offset: 0x3c
	// Line 246, Address: 0x1f76a0, Func Offset: 0x40
	// Line 245, Address: 0x1f76a4, Func Offset: 0x44
	// Line 246, Address: 0x1f76a8, Func Offset: 0x48
	// Line 247, Address: 0x1f76ac, Func Offset: 0x4c
	// Line 251, Address: 0x1f76b4, Func Offset: 0x54
	// Line 253, Address: 0x1f76d8, Func Offset: 0x78
	// Line 255, Address: 0x1f76e4, Func Offset: 0x84
	// Line 256, Address: 0x1f76f4, Func Offset: 0x94
	// Line 258, Address: 0x1f76fc, Func Offset: 0x9c
	// Line 259, Address: 0x1f7718, Func Offset: 0xb8
	// Line 260, Address: 0x1f7720, Func Offset: 0xc0
	// Line 261, Address: 0x1f7728, Func Offset: 0xc8
	// Line 262, Address: 0x1f7734, Func Offset: 0xd4
	// Line 264, Address: 0x1f7740, Func Offset: 0xe0
	// Line 265, Address: 0x1f7744, Func Offset: 0xe4
	// Line 269, Address: 0x1f7748, Func Offset: 0xe8
	// Func End, Address: 0x1f7758, Func Offset: 0xf8
}

// 
// Start address: 0x1f7760
void bhEne20_MV01(BH_PWORK* epw)
{
	unsigned int rnd;
	// Line 279, Address: 0x1f7760, Func Offset: 0
	// Line 284, Address: 0x1f7770, Func Offset: 0x10
	// Line 287, Address: 0x1f7790, Func Offset: 0x30
	// Line 288, Address: 0x1f77a0, Func Offset: 0x40
	// Line 290, Address: 0x1f77a4, Func Offset: 0x44
	// Line 289, Address: 0x1f77a8, Func Offset: 0x48
	// Line 290, Address: 0x1f77ac, Func Offset: 0x4c
	// Line 291, Address: 0x1f77b0, Func Offset: 0x50
	// Line 295, Address: 0x1f77b8, Func Offset: 0x58
	// Line 296, Address: 0x1f77dc, Func Offset: 0x7c
	// Line 298, Address: 0x1f77e0, Func Offset: 0x80
	// Line 301, Address: 0x1f77ec, Func Offset: 0x8c
	// Line 302, Address: 0x1f77f8, Func Offset: 0x98
	// Line 303, Address: 0x1f7808, Func Offset: 0xa8
	// Line 305, Address: 0x1f7810, Func Offset: 0xb0
	// Line 306, Address: 0x1f782c, Func Offset: 0xcc
	// Line 307, Address: 0x1f7838, Func Offset: 0xd8
	// Line 308, Address: 0x1f7840, Func Offset: 0xe0
	// Line 309, Address: 0x1f784c, Func Offset: 0xec
	// Line 310, Address: 0x1f7858, Func Offset: 0xf8
	// Line 311, Address: 0x1f7864, Func Offset: 0x104
	// Line 313, Address: 0x1f786c, Func Offset: 0x10c
	// Line 314, Address: 0x1f7874, Func Offset: 0x114
	// Line 317, Address: 0x1f7878, Func Offset: 0x118
	// Func End, Address: 0x1f7888, Func Offset: 0x128
}

// 
// Start address: 0x1f7890
void bhEne20_MV02(BH_PWORK* epw)
{
	// Line 327, Address: 0x1f7890, Func Offset: 0
	// Line 328, Address: 0x1f78a0, Func Offset: 0x10
	// Line 330, Address: 0x1f78c0, Func Offset: 0x30
	// Line 332, Address: 0x1f78d0, Func Offset: 0x40
	// Line 334, Address: 0x1f78d4, Func Offset: 0x44
	// Line 333, Address: 0x1f78d8, Func Offset: 0x48
	// Line 334, Address: 0x1f78dc, Func Offset: 0x4c
	// Line 335, Address: 0x1f78e0, Func Offset: 0x50
	// Line 337, Address: 0x1f78e8, Func Offset: 0x58
	// Line 338, Address: 0x1f790c, Func Offset: 0x7c
	// Line 339, Address: 0x1f7910, Func Offset: 0x80
	// Line 343, Address: 0x1f791c, Func Offset: 0x8c
	// Line 344, Address: 0x1f7928, Func Offset: 0x98
	// Line 345, Address: 0x1f7938, Func Offset: 0xa8
	// Line 346, Address: 0x1f7940, Func Offset: 0xb0
	// Line 347, Address: 0x1f7944, Func Offset: 0xb4
	// Line 348, Address: 0x1f7948, Func Offset: 0xb8
	// Line 352, Address: 0x1f794c, Func Offset: 0xbc
	// Func End, Address: 0x1f795c, Func Offset: 0xcc
}

// 
// Start address: 0x1f7960
void bhEne20_MV03(BH_PWORK* epw)
{
	// Line 362, Address: 0x1f7960, Func Offset: 0
	// Line 363, Address: 0x1f7970, Func Offset: 0x10
	// Line 365, Address: 0x1f7990, Func Offset: 0x30
	// Line 367, Address: 0x1f79a0, Func Offset: 0x40
	// Line 369, Address: 0x1f79a4, Func Offset: 0x44
	// Line 368, Address: 0x1f79a8, Func Offset: 0x48
	// Line 369, Address: 0x1f79ac, Func Offset: 0x4c
	// Line 370, Address: 0x1f79b0, Func Offset: 0x50
	// Line 372, Address: 0x1f79b8, Func Offset: 0x58
	// Line 373, Address: 0x1f79dc, Func Offset: 0x7c
	// Line 374, Address: 0x1f79e0, Func Offset: 0x80
	// Line 378, Address: 0x1f79ec, Func Offset: 0x8c
	// Line 379, Address: 0x1f79f8, Func Offset: 0x98
	// Line 380, Address: 0x1f7a08, Func Offset: 0xa8
	// Line 381, Address: 0x1f7a10, Func Offset: 0xb0
	// Line 382, Address: 0x1f7a14, Func Offset: 0xb4
	// Line 383, Address: 0x1f7a18, Func Offset: 0xb8
	// Line 387, Address: 0x1f7a1c, Func Offset: 0xbc
	// Func End, Address: 0x1f7a2c, Func Offset: 0xcc
}

// 
// Start address: 0x1f7a30
void bhEne20_MV04(BH_PWORK* epw)
{
	// Line 397, Address: 0x1f7a30, Func Offset: 0
	// Line 398, Address: 0x1f7a40, Func Offset: 0x10
	// Line 400, Address: 0x1f7a60, Func Offset: 0x30
	// Line 402, Address: 0x1f7a70, Func Offset: 0x40
	// Line 404, Address: 0x1f7a74, Func Offset: 0x44
	// Line 403, Address: 0x1f7a78, Func Offset: 0x48
	// Line 404, Address: 0x1f7a7c, Func Offset: 0x4c
	// Line 405, Address: 0x1f7a80, Func Offset: 0x50
	// Line 407, Address: 0x1f7a88, Func Offset: 0x58
	// Line 408, Address: 0x1f7aa8, Func Offset: 0x78
	// Line 409, Address: 0x1f7aac, Func Offset: 0x7c
	// Line 413, Address: 0x1f7ab8, Func Offset: 0x88
	// Line 414, Address: 0x1f7ac4, Func Offset: 0x94
	// Line 415, Address: 0x1f7ad4, Func Offset: 0xa4
	// Line 416, Address: 0x1f7adc, Func Offset: 0xac
	// Line 417, Address: 0x1f7ae0, Func Offset: 0xb0
	// Line 418, Address: 0x1f7ae4, Func Offset: 0xb4
	// Line 422, Address: 0x1f7ae8, Func Offset: 0xb8
	// Func End, Address: 0x1f7af8, Func Offset: 0xc8
}

// 
// Start address: 0x1f7b00
void bhEne20_MV05(BH_PWORK* epw)
{
	// Line 432, Address: 0x1f7b00, Func Offset: 0
	// Line 433, Address: 0x1f7b10, Func Offset: 0x10
	// Line 435, Address: 0x1f7b30, Func Offset: 0x30
	// Line 437, Address: 0x1f7b40, Func Offset: 0x40
	// Line 439, Address: 0x1f7b44, Func Offset: 0x44
	// Line 438, Address: 0x1f7b48, Func Offset: 0x48
	// Line 439, Address: 0x1f7b4c, Func Offset: 0x4c
	// Line 440, Address: 0x1f7b50, Func Offset: 0x50
	// Line 442, Address: 0x1f7b58, Func Offset: 0x58
	// Line 443, Address: 0x1f7b78, Func Offset: 0x78
	// Line 444, Address: 0x1f7b7c, Func Offset: 0x7c
	// Line 448, Address: 0x1f7b88, Func Offset: 0x88
	// Line 449, Address: 0x1f7b94, Func Offset: 0x94
	// Line 450, Address: 0x1f7ba4, Func Offset: 0xa4
	// Line 451, Address: 0x1f7bac, Func Offset: 0xac
	// Line 452, Address: 0x1f7bb0, Func Offset: 0xb0
	// Line 453, Address: 0x1f7bb4, Func Offset: 0xb4
	// Line 457, Address: 0x1f7bb8, Func Offset: 0xb8
	// Func End, Address: 0x1f7bc8, Func Offset: 0xc8
}

// 
// Start address: 0x1f7bd0
void bhEne20_MV06(BH_PWORK* epw)
{
	// Line 468, Address: 0x1f7bd0, Func Offset: 0
	// Line 470, Address: 0x1f7bfc, Func Offset: 0x2c
	// Line 472, Address: 0x1f7c0c, Func Offset: 0x3c
	// Line 473, Address: 0x1f7c10, Func Offset: 0x40
	// Line 474, Address: 0x1f7c14, Func Offset: 0x44
	// Line 475, Address: 0x1f7c18, Func Offset: 0x48
	// Line 477, Address: 0x1f7c20, Func Offset: 0x50
	// Line 478, Address: 0x1f7c40, Func Offset: 0x70
	// Line 481, Address: 0x1f7c4c, Func Offset: 0x7c
	// Line 482, Address: 0x1f7c5c, Func Offset: 0x8c
	// Line 484, Address: 0x1f7c64, Func Offset: 0x94
	// Line 483, Address: 0x1f7c68, Func Offset: 0x98
	// Line 484, Address: 0x1f7c6c, Func Offset: 0x9c
	// Line 485, Address: 0x1f7c70, Func Offset: 0xa0
	// Line 487, Address: 0x1f7c78, Func Offset: 0xa8
	// Line 488, Address: 0x1f7c9c, Func Offset: 0xcc
	// Line 490, Address: 0x1f7ca4, Func Offset: 0xd4
	// Line 493, Address: 0x1f7cac, Func Offset: 0xdc
	// Line 494, Address: 0x1f7cbc, Func Offset: 0xec
	// Line 495, Address: 0x1f7cc4, Func Offset: 0xf4
	// Line 496, Address: 0x1f7cc8, Func Offset: 0xf8
	// Line 497, Address: 0x1f7ccc, Func Offset: 0xfc
	// Line 501, Address: 0x1f7cd0, Func Offset: 0x100
	// Func End, Address: 0x1f7cd8, Func Offset: 0x108
}

// 
// Start address: 0x1f7ce0
void bhEne20_MV07(BH_PWORK* epw)
{
	// Line 512, Address: 0x1f7ce0, Func Offset: 0
	// Line 514, Address: 0x1f7d0c, Func Offset: 0x2c
	// Line 516, Address: 0x1f7d18, Func Offset: 0x38
	// Line 518, Address: 0x1f7d1c, Func Offset: 0x3c
	// Line 517, Address: 0x1f7d20, Func Offset: 0x40
	// Line 518, Address: 0x1f7d24, Func Offset: 0x44
	// Line 519, Address: 0x1f7d28, Func Offset: 0x48
	// Line 521, Address: 0x1f7d30, Func Offset: 0x50
	// Line 522, Address: 0x1f7d50, Func Offset: 0x70
	// Line 525, Address: 0x1f7d5c, Func Offset: 0x7c
	// Line 526, Address: 0x1f7d6c, Func Offset: 0x8c
	// Line 528, Address: 0x1f7d74, Func Offset: 0x94
	// Line 527, Address: 0x1f7d78, Func Offset: 0x98
	// Line 528, Address: 0x1f7d7c, Func Offset: 0x9c
	// Line 529, Address: 0x1f7d80, Func Offset: 0xa0
	// Line 531, Address: 0x1f7d88, Func Offset: 0xa8
	// Line 532, Address: 0x1f7da8, Func Offset: 0xc8
	// Line 534, Address: 0x1f7db0, Func Offset: 0xd0
	// Line 537, Address: 0x1f7db8, Func Offset: 0xd8
	// Line 538, Address: 0x1f7dc8, Func Offset: 0xe8
	// Line 539, Address: 0x1f7dd0, Func Offset: 0xf0
	// Line 540, Address: 0x1f7dd4, Func Offset: 0xf4
	// Line 541, Address: 0x1f7dd8, Func Offset: 0xf8
	// Line 545, Address: 0x1f7ddc, Func Offset: 0xfc
	// Func End, Address: 0x1f7de4, Func Offset: 0x104
}

// 
// Start address: 0x1f7df0
void bhEne20_Nage()
{
	// Line 557, Address: 0x1f7df0, Func Offset: 0
	// Func End, Address: 0x1f7df8, Func Offset: 0x8
}

// 
// Start address: 0x1f7e00
void bhEne20_Damage()
{
	// Line 569, Address: 0x1f7e00, Func Offset: 0
	// Func End, Address: 0x1f7e08, Func Offset: 0x8
}

// 
// Start address: 0x1f7e10
void bhEne20_Die()
{
	// Line 581, Address: 0x1f7e10, Func Offset: 0
	// Func End, Address: 0x1f7e18, Func Offset: 0x8
}

