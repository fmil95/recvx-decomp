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

typedef void(*type_1)(BH_PWORK*);
typedef void(*type_3)(BH_PWORK*);

typedef char type_0[8];
typedef void(*type_2)(BH_PWORK*)[1];
typedef void(*type_4)(BH_PWORK*)[3];
typedef void* type_5[2];
typedef unsigned int type_6[2];
typedef _anon9 type_7[3];
typedef float type_8[3];
typedef int type_9[3];
typedef int type_10[3];
typedef float type_11[3];
typedef _anon9 type_12[3];
typedef int type_13[64];
typedef float type_14[16];
typedef unsigned int type_15[1];
typedef unsigned int type_16[2];
typedef int* type_17[16];
typedef npobj* type_18[16];
typedef _anon4* type_19[16];
typedef _anon7 type_20[16];
typedef unsigned char type_21[64];

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
	_anon9 center;
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

void(*bhEne03s_Mode0)(BH_PWORK*)[3];
void(*bhEne03s_MoveMode2)(BH_PWORK*)[1];

void bhEne03s(BH_PWORK* epw);
void bhEne03s_Init(BH_PWORK* epw);
void bhEne03s_Move(BH_PWORK* epw);
void bhEne03s_MV00(BH_PWORK* epw);
void bhEne03s_Dummy();
void bhEne03s_WallCheck(BH_PWORK* epw);
void bhEne03s_WallCheck2(BH_PWORK* epw);
void bhEne03s_InitCollision(BH_PWORK* epw);

// 
// Start address: 0x1a3c60
void bhEne03s(BH_PWORK* epw)
{
	// Line 103, Address: 0x1a3c60, Func Offset: 0
	// Func End, Address: 0x1a3c80, Func Offset: 0x20
}

// 
// Start address: 0x1a3c80
void bhEne03s_Init(BH_PWORK* epw)
{
	// Line 114, Address: 0x1a3c80, Func Offset: 0
	// Line 116, Address: 0x1a3c88, Func Offset: 0x8
	// Line 114, Address: 0x1a3c8c, Func Offset: 0xc
	// Line 116, Address: 0x1a3c90, Func Offset: 0x10
	// Line 117, Address: 0x1a3c98, Func Offset: 0x18
	// Line 118, Address: 0x1a3c9c, Func Offset: 0x1c
	// Line 119, Address: 0x1a3ca0, Func Offset: 0x20
	// Line 122, Address: 0x1a3ca4, Func Offset: 0x24
	// Line 123, Address: 0x1a3cac, Func Offset: 0x2c
	// Line 124, Address: 0x1a3cb0, Func Offset: 0x30
	// Line 125, Address: 0x1a3cb4, Func Offset: 0x34
	// Line 128, Address: 0x1a3cb8, Func Offset: 0x38
	// Line 129, Address: 0x1a3cc4, Func Offset: 0x44
	// Line 132, Address: 0x1a3cd4, Func Offset: 0x54
	// Line 133, Address: 0x1a3cdc, Func Offset: 0x5c
	// Func End, Address: 0x1a3cec, Func Offset: 0x6c
}

// 
// Start address: 0x1a3cf0
void bhEne03s_Move(BH_PWORK* epw)
{
	// Line 143, Address: 0x1a3cf0, Func Offset: 0
	// Line 145, Address: 0x1a3d00, Func Offset: 0x10
	// Line 148, Address: 0x1a3d20, Func Offset: 0x30
	// Line 149, Address: 0x1a3d30, Func Offset: 0x40
	// Line 151, Address: 0x1a3d44, Func Offset: 0x54
	// Line 152, Address: 0x1a3d4c, Func Offset: 0x5c
	// Line 154, Address: 0x1a3d54, Func Offset: 0x64
	// Line 157, Address: 0x1a3d60, Func Offset: 0x70
	// Func End, Address: 0x1a3d70, Func Offset: 0x80
}

// 
// Start address: 0x1a3d70
void bhEne03s_MV00(BH_PWORK* epw)
{
	BH_PWORK* ep;
	int ang;
	float spd;
	float out;
	_anon9 ov;
	_anon9 vd;
	_anon9 v;
	_anon9 c;
	// Line 167, Address: 0x1a3d70, Func Offset: 0
	// Line 174, Address: 0x1a3d88, Func Offset: 0x18
	// Line 177, Address: 0x1a3dc0, Func Offset: 0x50
	// Line 178, Address: 0x1a3dc4, Func Offset: 0x54
	// Line 179, Address: 0x1a3ddc, Func Offset: 0x6c
	// Line 180, Address: 0x1a3df4, Func Offset: 0x84
	// Line 181, Address: 0x1a3e0c, Func Offset: 0x9c
	// Line 182, Address: 0x1a3e18, Func Offset: 0xa8
	// Line 183, Address: 0x1a3e24, Func Offset: 0xb4
	// Line 185, Address: 0x1a3e50, Func Offset: 0xe0
	// Line 186, Address: 0x1a3e6c, Func Offset: 0xfc
	// Line 185, Address: 0x1a3e70, Func Offset: 0x100
	// Line 186, Address: 0x1a3e80, Func Offset: 0x110
	// Line 185, Address: 0x1a3e84, Func Offset: 0x114
	// Line 186, Address: 0x1a3e88, Func Offset: 0x118
	// Line 187, Address: 0x1a3e90, Func Offset: 0x120
	// Line 188, Address: 0x1a3e9c, Func Offset: 0x12c
	// Line 189, Address: 0x1a3ee0, Func Offset: 0x170
	// Line 191, Address: 0x1a3ee8, Func Offset: 0x178
	// Line 192, Address: 0x1a3f04, Func Offset: 0x194
	// Line 191, Address: 0x1a3f08, Func Offset: 0x198
	// Line 192, Address: 0x1a3f18, Func Offset: 0x1a8
	// Line 191, Address: 0x1a3f1c, Func Offset: 0x1ac
	// Line 192, Address: 0x1a3f20, Func Offset: 0x1b0
	// Line 193, Address: 0x1a3f28, Func Offset: 0x1b8
	// Line 194, Address: 0x1a3f38, Func Offset: 0x1c8
	// Line 195, Address: 0x1a3f3c, Func Offset: 0x1cc
	// Line 200, Address: 0x1a3f44, Func Offset: 0x1d4
	// Line 201, Address: 0x1a3f60, Func Offset: 0x1f0
	// Line 200, Address: 0x1a3f64, Func Offset: 0x1f4
	// Line 201, Address: 0x1a3f74, Func Offset: 0x204
	// Line 200, Address: 0x1a3f78, Func Offset: 0x208
	// Line 201, Address: 0x1a3f7c, Func Offset: 0x20c
	// Line 202, Address: 0x1a3f84, Func Offset: 0x214
	// Line 203, Address: 0x1a3f94, Func Offset: 0x224
	// Line 206, Address: 0x1a3fa0, Func Offset: 0x230
	// Line 207, Address: 0x1a3fa8, Func Offset: 0x238
	// Line 208, Address: 0x1a3fc4, Func Offset: 0x254
	// Line 207, Address: 0x1a3fc8, Func Offset: 0x258
	// Line 208, Address: 0x1a3fd8, Func Offset: 0x268
	// Line 207, Address: 0x1a3fdc, Func Offset: 0x26c
	// Line 208, Address: 0x1a3fe0, Func Offset: 0x270
	// Line 209, Address: 0x1a3fe8, Func Offset: 0x278
	// Line 210, Address: 0x1a3ff8, Func Offset: 0x288
	// Line 213, Address: 0x1a4008, Func Offset: 0x298
	// Line 216, Address: 0x1a400c, Func Offset: 0x29c
	// Line 213, Address: 0x1a4010, Func Offset: 0x2a0
	// Line 216, Address: 0x1a4018, Func Offset: 0x2a8
	// Line 219, Address: 0x1a4020, Func Offset: 0x2b0
	// Line 221, Address: 0x1a4064, Func Offset: 0x2f4
	// Line 222, Address: 0x1a406c, Func Offset: 0x2fc
	// Line 224, Address: 0x1a4074, Func Offset: 0x304
	// Line 225, Address: 0x1a4088, Func Offset: 0x318
	// Line 226, Address: 0x1a4094, Func Offset: 0x324
	// Line 227, Address: 0x1a40ac, Func Offset: 0x33c
	// Line 228, Address: 0x1a40b4, Func Offset: 0x344
	// Line 230, Address: 0x1a40d0, Func Offset: 0x360
	// Line 232, Address: 0x1a40e4, Func Offset: 0x374
	// Line 233, Address: 0x1a40f8, Func Offset: 0x388
	// Line 234, Address: 0x1a4108, Func Offset: 0x398
	// Line 235, Address: 0x1a4110, Func Offset: 0x3a0
	// Line 236, Address: 0x1a4124, Func Offset: 0x3b4
	// Line 237, Address: 0x1a4130, Func Offset: 0x3c0
	// Line 238, Address: 0x1a4138, Func Offset: 0x3c8
	// Line 239, Address: 0x1a4148, Func Offset: 0x3d8
	// Line 240, Address: 0x1a4150, Func Offset: 0x3e0
	// Line 241, Address: 0x1a4158, Func Offset: 0x3e8
	// Line 245, Address: 0x1a4164, Func Offset: 0x3f4
	// Line 246, Address: 0x1a4174, Func Offset: 0x404
	// Line 247, Address: 0x1a41b4, Func Offset: 0x444
	// Line 246, Address: 0x1a41c0, Func Offset: 0x450
	// Line 247, Address: 0x1a41c4, Func Offset: 0x454
	// Line 249, Address: 0x1a41d0, Func Offset: 0x460
	// Line 252, Address: 0x1a41d8, Func Offset: 0x468
	// Line 253, Address: 0x1a41e4, Func Offset: 0x474
	// Line 256, Address: 0x1a41e8, Func Offset: 0x478
	// Line 253, Address: 0x1a41ec, Func Offset: 0x47c
	// Line 254, Address: 0x1a41f4, Func Offset: 0x484
	// Line 255, Address: 0x1a4200, Func Offset: 0x490
	// Line 256, Address: 0x1a420c, Func Offset: 0x49c
	// Line 257, Address: 0x1a4218, Func Offset: 0x4a8
	// Line 258, Address: 0x1a4234, Func Offset: 0x4c4
	// Line 259, Address: 0x1a424c, Func Offset: 0x4dc
	// Line 260, Address: 0x1a4258, Func Offset: 0x4e8
	// Line 262, Address: 0x1a4264, Func Offset: 0x4f4
	// Line 263, Address: 0x1a4278, Func Offset: 0x508
	// Line 264, Address: 0x1a4284, Func Offset: 0x514
	// Line 267, Address: 0x1a42a0, Func Offset: 0x530
	// Line 264, Address: 0x1a42a4, Func Offset: 0x534
	// Line 267, Address: 0x1a42a8, Func Offset: 0x538
	// Line 268, Address: 0x1a42cc, Func Offset: 0x55c
	// Line 269, Address: 0x1a42d4, Func Offset: 0x564
	// Line 270, Address: 0x1a42f4, Func Offset: 0x584
	// Line 271, Address: 0x1a4300, Func Offset: 0x590
	// Line 272, Address: 0x1a4308, Func Offset: 0x598
	// Line 274, Address: 0x1a4330, Func Offset: 0x5c0
	// Line 275, Address: 0x1a4338, Func Offset: 0x5c8
	// Line 277, Address: 0x1a4340, Func Offset: 0x5d0
	// Line 278, Address: 0x1a4348, Func Offset: 0x5d8
	// Line 279, Address: 0x1a4350, Func Offset: 0x5e0
	// Line 280, Address: 0x1a4358, Func Offset: 0x5e8
	// Line 282, Address: 0x1a4368, Func Offset: 0x5f8
	// Line 284, Address: 0x1a437c, Func Offset: 0x60c
	// Line 288, Address: 0x1a4388, Func Offset: 0x618
	// Line 290, Address: 0x1a43a0, Func Offset: 0x630
	// Line 292, Address: 0x1a43a8, Func Offset: 0x638
	// Line 294, Address: 0x1a43bc, Func Offset: 0x64c
	// Line 295, Address: 0x1a43c0, Func Offset: 0x650
	// Line 296, Address: 0x1a43c8, Func Offset: 0x658
	// Line 297, Address: 0x1a43d8, Func Offset: 0x668
	// Line 300, Address: 0x1a43f4, Func Offset: 0x684
	// Func End, Address: 0x1a440c, Func Offset: 0x69c
}

// 
// Start address: 0x1a4410
void bhEne03s_Dummy()
{
	// Line 311, Address: 0x1a4410, Func Offset: 0
	// Func End, Address: 0x1a4418, Func Offset: 0x8
}

// 
// Start address: 0x1a4420
void bhEne03s_WallCheck(BH_PWORK* epw)
{
	_anon9 p[3];
	int last;
	int flgZ;
	int flgY;
	int flgX;
	_anon8* hp;
	int flg[3];
	int i;
	_anon9 n[3];
	_anon9 v;
	// Line 321, Address: 0x1a4420, Func Offset: 0
	// Line 328, Address: 0x1a4450, Func Offset: 0x30
	// Line 331, Address: 0x1a4454, Func Offset: 0x34
	// Line 332, Address: 0x1a4458, Func Offset: 0x38
	// Line 328, Address: 0x1a4460, Func Offset: 0x40
	// Line 332, Address: 0x1a4468, Func Offset: 0x48
	// Line 328, Address: 0x1a4470, Func Offset: 0x50
	// Line 329, Address: 0x1a4474, Func Offset: 0x54
	// Line 327, Address: 0x1a4478, Func Offset: 0x58
	// Line 329, Address: 0x1a4484, Func Offset: 0x64
	// Line 330, Address: 0x1a448c, Func Offset: 0x6c
	// Line 333, Address: 0x1a4498, Func Offset: 0x78
	// Line 334, Address: 0x1a449c, Func Offset: 0x7c
	// Line 335, Address: 0x1a44b4, Func Offset: 0x94
	// Line 336, Address: 0x1a44bc, Func Offset: 0x9c
	// Line 337, Address: 0x1a44c0, Func Offset: 0xa0
	// Line 335, Address: 0x1a44c4, Func Offset: 0xa4
	// Line 336, Address: 0x1a44cc, Func Offset: 0xac
	// Line 337, Address: 0x1a44dc, Func Offset: 0xbc
	// Line 338, Address: 0x1a44ec, Func Offset: 0xcc
	// Line 339, Address: 0x1a4500, Func Offset: 0xe0
	// Line 340, Address: 0x1a4510, Func Offset: 0xf0
	// Line 341, Address: 0x1a4518, Func Offset: 0xf8
	// Line 342, Address: 0x1a4520, Func Offset: 0x100
	// Line 343, Address: 0x1a4528, Func Offset: 0x108
	// Line 344, Address: 0x1a4530, Func Offset: 0x110
	// Line 346, Address: 0x1a454c, Func Offset: 0x12c
	// Line 347, Address: 0x1a4554, Func Offset: 0x134
	// Line 348, Address: 0x1a4558, Func Offset: 0x138
	// Line 350, Address: 0x1a4574, Func Offset: 0x154
	// Line 351, Address: 0x1a4598, Func Offset: 0x178
	// Line 352, Address: 0x1a459c, Func Offset: 0x17c
	// Line 353, Address: 0x1a45a4, Func Offset: 0x184
	// Line 356, Address: 0x1a45a8, Func Offset: 0x188
	// Line 357, Address: 0x1a45cc, Func Offset: 0x1ac
	// Line 358, Address: 0x1a45d4, Func Offset: 0x1b4
	// Line 362, Address: 0x1a45d8, Func Offset: 0x1b8
	// Line 363, Address: 0x1a45e4, Func Offset: 0x1c4
	// Line 366, Address: 0x1a45ec, Func Offset: 0x1cc
	// Line 365, Address: 0x1a45f0, Func Offset: 0x1d0
	// Line 363, Address: 0x1a45f8, Func Offset: 0x1d8
	// Line 365, Address: 0x1a45fc, Func Offset: 0x1dc
	// Line 363, Address: 0x1a4600, Func Offset: 0x1e0
	// Line 364, Address: 0x1a4604, Func Offset: 0x1e4
	// Line 365, Address: 0x1a4614, Func Offset: 0x1f4
	// Line 366, Address: 0x1a4620, Func Offset: 0x200
	// Line 367, Address: 0x1a4628, Func Offset: 0x208
	// Line 368, Address: 0x1a4634, Func Offset: 0x214
	// Line 369, Address: 0x1a4640, Func Offset: 0x220
	// Line 371, Address: 0x1a464c, Func Offset: 0x22c
	// Line 372, Address: 0x1a4674, Func Offset: 0x254
	// Line 373, Address: 0x1a469c, Func Offset: 0x27c
	// Line 375, Address: 0x1a46c0, Func Offset: 0x2a0
	// Line 376, Address: 0x1a46c8, Func Offset: 0x2a8
	// Line 380, Address: 0x1a46cc, Func Offset: 0x2ac
	// Line 376, Address: 0x1a46d0, Func Offset: 0x2b0
	// Line 377, Address: 0x1a46dc, Func Offset: 0x2bc
	// Line 378, Address: 0x1a46ec, Func Offset: 0x2cc
	// Line 380, Address: 0x1a46fc, Func Offset: 0x2dc
	// Line 381, Address: 0x1a4710, Func Offset: 0x2f0
	// Line 392, Address: 0x1a471c, Func Offset: 0x2fc
	// Line 381, Address: 0x1a4724, Func Offset: 0x304
	// Line 382, Address: 0x1a4730, Func Offset: 0x310
	// Line 383, Address: 0x1a4748, Func Offset: 0x328
	// Line 392, Address: 0x1a4760, Func Offset: 0x340
	// Line 410, Address: 0x1a4768, Func Offset: 0x348
	// Line 411, Address: 0x1a4778, Func Offset: 0x358
	// Line 414, Address: 0x1a4784, Func Offset: 0x364
	// Line 418, Address: 0x1a4790, Func Offset: 0x370
	// Line 419, Address: 0x1a4794, Func Offset: 0x374
	// Line 414, Address: 0x1a4798, Func Offset: 0x378
	// Line 420, Address: 0x1a47a4, Func Offset: 0x384
	// Line 426, Address: 0x1a47a8, Func Offset: 0x388
	// Line 414, Address: 0x1a47ac, Func Offset: 0x38c
	// Line 415, Address: 0x1a47bc, Func Offset: 0x39c
	// Line 416, Address: 0x1a47dc, Func Offset: 0x3bc
	// Line 418, Address: 0x1a47fc, Func Offset: 0x3dc
	// Line 419, Address: 0x1a480c, Func Offset: 0x3ec
	// Line 420, Address: 0x1a481c, Func Offset: 0x3fc
	// Line 422, Address: 0x1a482c, Func Offset: 0x40c
	// Line 423, Address: 0x1a483c, Func Offset: 0x41c
	// Line 424, Address: 0x1a484c, Func Offset: 0x42c
	// Line 426, Address: 0x1a485c, Func Offset: 0x43c
	// Line 427, Address: 0x1a4868, Func Offset: 0x448
	// Line 428, Address: 0x1a4874, Func Offset: 0x454
	// Line 435, Address: 0x1a48a8, Func Offset: 0x488
	// Line 428, Address: 0x1a48b0, Func Offset: 0x490
	// Line 435, Address: 0x1a48b8, Func Offset: 0x498
	// Line 437, Address: 0x1a48c0, Func Offset: 0x4a0
	// Line 438, Address: 0x1a48c8, Func Offset: 0x4a8
	// Line 439, Address: 0x1a48d8, Func Offset: 0x4b8
	// Line 441, Address: 0x1a48dc, Func Offset: 0x4bc
	// Line 439, Address: 0x1a48ec, Func Offset: 0x4cc
	// Line 441, Address: 0x1a48f0, Func Offset: 0x4d0
	// Line 439, Address: 0x1a48f4, Func Offset: 0x4d4
	// Line 440, Address: 0x1a48fc, Func Offset: 0x4dc
	// Line 441, Address: 0x1a4904, Func Offset: 0x4e4
	// Line 442, Address: 0x1a4920, Func Offset: 0x500
	// Line 443, Address: 0x1a4928, Func Offset: 0x508
	// Line 446, Address: 0x1a4930, Func Offset: 0x510
	// Func End, Address: 0x1a4964, Func Offset: 0x544
}

// 
// Start address: 0x1a4970
void bhEne03s_WallCheck2(BH_PWORK* epw)
{
	_anon8* hp;
	_anon9 n;
	_anon9 v;
	// Line 456, Address: 0x1a4970, Func Offset: 0
	// Line 460, Address: 0x1a4984, Func Offset: 0x14
	// Line 464, Address: 0x1a498c, Func Offset: 0x1c
	// Line 460, Address: 0x1a4990, Func Offset: 0x20
	// Line 461, Address: 0x1a4998, Func Offset: 0x28
	// Line 462, Address: 0x1a49a4, Func Offset: 0x34
	// Line 464, Address: 0x1a49b0, Func Offset: 0x40
	// Line 465, Address: 0x1a49c0, Func Offset: 0x50
	// Line 466, Address: 0x1a49c8, Func Offset: 0x58
	// Line 467, Address: 0x1a49cc, Func Offset: 0x5c
	// Line 465, Address: 0x1a49d0, Func Offset: 0x60
	// Line 466, Address: 0x1a49d8, Func Offset: 0x68
	// Line 467, Address: 0x1a49e8, Func Offset: 0x78
	// Line 468, Address: 0x1a49f8, Func Offset: 0x88
	// Line 469, Address: 0x1a4a0c, Func Offset: 0x9c
	// Line 470, Address: 0x1a4a18, Func Offset: 0xa8
	// Line 471, Address: 0x1a4a20, Func Offset: 0xb0
	// Line 472, Address: 0x1a4a28, Func Offset: 0xb8
	// Line 473, Address: 0x1a4a30, Func Offset: 0xc0
	// Line 474, Address: 0x1a4a54, Func Offset: 0xe4
	// Line 478, Address: 0x1a4a64, Func Offset: 0xf4
	// Line 479, Address: 0x1a4a70, Func Offset: 0x100
	// Line 480, Address: 0x1a4a80, Func Offset: 0x110
	// Line 481, Address: 0x1a4a90, Func Offset: 0x120
	// Line 483, Address: 0x1a4aa0, Func Offset: 0x130
	// Line 484, Address: 0x1a4aac, Func Offset: 0x13c
	// Line 485, Address: 0x1a4ab8, Func Offset: 0x148
	// Line 486, Address: 0x1a4ac4, Func Offset: 0x154
	// Line 487, Address: 0x1a4ad8, Func Offset: 0x168
	// Func End, Address: 0x1a4af0, Func Offset: 0x180
}

// 
// Start address: 0x1a4af0
void bhEne03s_InitCollision(BH_PWORK* epw)
{
	_anon9 pos;
	int i;
	_anon5* owk;
	// Line 497, Address: 0x1a4af0, Func Offset: 0
	// Line 498, Address: 0x1a4b04, Func Offset: 0x14
	// Line 503, Address: 0x1a4b08, Func Offset: 0x18
	// Line 521, Address: 0x1a4b0c, Func Offset: 0x1c
	// Line 513, Address: 0x1a4b14, Func Offset: 0x24
	// Line 514, Address: 0x1a4b18, Func Offset: 0x28
	// Line 503, Address: 0x1a4b1c, Func Offset: 0x2c
	// Line 504, Address: 0x1a4b20, Func Offset: 0x30
	// Line 505, Address: 0x1a4b28, Func Offset: 0x38
	// Line 506, Address: 0x1a4b30, Func Offset: 0x40
	// Line 507, Address: 0x1a4b3c, Func Offset: 0x4c
	// Line 508, Address: 0x1a4b48, Func Offset: 0x58
	// Line 512, Address: 0x1a4b54, Func Offset: 0x64
	// Line 513, Address: 0x1a4b5c, Func Offset: 0x6c
	// Line 514, Address: 0x1a4b64, Func Offset: 0x74
	// Line 517, Address: 0x1a4b6c, Func Offset: 0x7c
	// Line 518, Address: 0x1a4b7c, Func Offset: 0x8c
	// Line 519, Address: 0x1a4b8c, Func Offset: 0x9c
	// Line 521, Address: 0x1a4b9c, Func Offset: 0xac
	// Line 522, Address: 0x1a4bac, Func Offset: 0xbc
	// Line 523, Address: 0x1a4bbc, Func Offset: 0xcc
	// Line 526, Address: 0x1a4bcc, Func Offset: 0xdc
	// Line 528, Address: 0x1a4bd8, Func Offset: 0xe8
	// Line 529, Address: 0x1a4c00, Func Offset: 0x110
	// Line 531, Address: 0x1a4c08, Func Offset: 0x118
	// Line 533, Address: 0x1a4c10, Func Offset: 0x120
	// Line 534, Address: 0x1a4c38, Func Offset: 0x148
	// Line 535, Address: 0x1a4c40, Func Offset: 0x150
	// Line 537, Address: 0x1a4c44, Func Offset: 0x154
	// Line 538, Address: 0x1a4c54, Func Offset: 0x164
	// Line 539, Address: 0x1a4c60, Func Offset: 0x170
	// Line 540, Address: 0x1a4c6c, Func Offset: 0x17c
	// Line 543, Address: 0x1a4c78, Func Offset: 0x188
	// Line 544, Address: 0x1a4c84, Func Offset: 0x194
	// Line 545, Address: 0x1a4c8c, Func Offset: 0x19c
	// Line 546, Address: 0x1a4ca0, Func Offset: 0x1b0
	// Line 549, Address: 0x1a4cb4, Func Offset: 0x1c4
	// Line 550, Address: 0x1a4ccc, Func Offset: 0x1dc
	// Line 551, Address: 0x1a4cdc, Func Offset: 0x1ec
	// Line 552, Address: 0x1a4cec, Func Offset: 0x1fc
	// Line 557, Address: 0x1a4cf8, Func Offset: 0x208
	// Line 552, Address: 0x1a4d00, Func Offset: 0x210
	// Line 553, Address: 0x1a4d0c, Func Offset: 0x21c
	// Line 554, Address: 0x1a4d1c, Func Offset: 0x22c
	// Line 558, Address: 0x1a4d2c, Func Offset: 0x23c
	// Line 562, Address: 0x1a4d30, Func Offset: 0x240
	// Line 558, Address: 0x1a4d38, Func Offset: 0x248
	// Line 559, Address: 0x1a4d54, Func Offset: 0x264
	// Line 560, Address: 0x1a4d60, Func Offset: 0x270
	// Line 561, Address: 0x1a4d6c, Func Offset: 0x27c
	// Line 562, Address: 0x1a4d78, Func Offset: 0x288
	// Line 565, Address: 0x1a4d80, Func Offset: 0x290
	// Line 566, Address: 0x1a4d88, Func Offset: 0x298
	// Line 567, Address: 0x1a4dd0, Func Offset: 0x2e0
	// Line 568, Address: 0x1a4e18, Func Offset: 0x328
	// Line 569, Address: 0x1a4e1c, Func Offset: 0x32c
	// Line 571, Address: 0x1a4e20, Func Offset: 0x330
	// Line 568, Address: 0x1a4e24, Func Offset: 0x334
	// Line 569, Address: 0x1a4e28, Func Offset: 0x338
	// Line 570, Address: 0x1a4e30, Func Offset: 0x340
	// Line 571, Address: 0x1a4e38, Func Offset: 0x348
	// Line 572, Address: 0x1a4e48, Func Offset: 0x358
	// Line 573, Address: 0x1a4ea0, Func Offset: 0x3b0
	// Func End, Address: 0x1a4eb8, Func Offset: 0x3c8
}

