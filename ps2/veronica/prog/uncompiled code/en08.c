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
typedef void(*type_10)(BH_PWORK*);

typedef char type_0[8];
typedef void(*type_2)(BH_PWORK*)[1];
typedef void(*type_4)(BH_PWORK*)[6];
typedef void* type_5[2];
typedef unsigned int type_6[2];
typedef float type_7[3];
typedef int type_8[3];
typedef float type_9[3];
typedef void(*type_11)(BH_PWORK*)[3];
typedef int type_12[64];
typedef float type_13[16];
typedef unsigned int type_14[1];
typedef unsigned int type_15[2];
typedef int* type_16[16];
typedef npobj* type_17[16];
typedef _anon5* type_18[16];
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
	_anon5* txp[16];
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
	_anon4* cpcl;
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
	_anon2* md2P;
	unsigned short* atrP;
};

struct _anon1
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

struct _anon2
{
	void* p[2];
};

struct _anon3
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon4
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon5
{
	_anon3* textures;
	unsigned int nbTexture;
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
	_anon5* texP;
	_anon6* owP;
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

void(*bhEne08_Mode0)(BH_PWORK*)[6];
void(*bhEne08_BrainType)(BH_PWORK*)[1];
void(*bhEne08_MoveMode2)(BH_PWORK*)[3];

void bhEne08(BH_PWORK* epw);
void bhEne08_Init(BH_PWORK* epw);
void bhEne08_Move(BH_PWORK* epw);
void bhEne08_MV00(BH_PWORK* epw);
void bhEne08_MV01(BH_PWORK* epw);
void bhEne08_MV02(BH_PWORK* epw);
void bhEne08_Nage();
void bhEne08_Damage();
void bhEne08_Die();

// 
// Start address: 0x1c5f70
void bhEne08(BH_PWORK* epw)
{
	// Line 128, Address: 0x1c5f70, Func Offset: 0
	// Line 130, Address: 0x1c5f80, Func Offset: 0x10
	// Line 133, Address: 0x1c5fa0, Func Offset: 0x30
	// Line 136, Address: 0x1c5fb4, Func Offset: 0x44
	// Line 137, Address: 0x1c5fbc, Func Offset: 0x4c
	// Line 140, Address: 0x1c5fc4, Func Offset: 0x54
	// Line 143, Address: 0x1c5fcc, Func Offset: 0x5c
	// Line 144, Address: 0x1c5fd4, Func Offset: 0x64
	// Func End, Address: 0x1c5fe4, Func Offset: 0x74
}

// 
// Start address: 0x1c5ff0
void bhEne08_Init(BH_PWORK* epw)
{
	// Line 154, Address: 0x1c5ff0, Func Offset: 0
	// Line 156, Address: 0x1c5ffc, Func Offset: 0xc
	// Line 157, Address: 0x1c6000, Func Offset: 0x10
	// Line 158, Address: 0x1c6004, Func Offset: 0x14
	// Line 159, Address: 0x1c6008, Func Offset: 0x18
	// Line 160, Address: 0x1c600c, Func Offset: 0x1c
	// Line 156, Address: 0x1c6010, Func Offset: 0x20
	// Line 157, Address: 0x1c6018, Func Offset: 0x28
	// Line 163, Address: 0x1c601c, Func Offset: 0x2c
	// Line 169, Address: 0x1c6020, Func Offset: 0x30
	// Line 178, Address: 0x1c6024, Func Offset: 0x34
	// Line 157, Address: 0x1c6028, Func Offset: 0x38
	// Line 158, Address: 0x1c6030, Func Offset: 0x40
	// Line 159, Address: 0x1c6034, Func Offset: 0x44
	// Line 160, Address: 0x1c6038, Func Offset: 0x48
	// Line 163, Address: 0x1c603c, Func Offset: 0x4c
	// Line 164, Address: 0x1c6040, Func Offset: 0x50
	// Line 165, Address: 0x1c6044, Func Offset: 0x54
	// Line 166, Address: 0x1c6048, Func Offset: 0x58
	// Line 169, Address: 0x1c604c, Func Offset: 0x5c
	// Line 170, Address: 0x1c6050, Func Offset: 0x60
	// Line 171, Address: 0x1c6054, Func Offset: 0x64
	// Line 172, Address: 0x1c6058, Func Offset: 0x68
	// Line 173, Address: 0x1c605c, Func Offset: 0x6c
	// Line 174, Address: 0x1c6060, Func Offset: 0x70
	// Line 177, Address: 0x1c6064, Func Offset: 0x74
	// Line 178, Address: 0x1c6068, Func Offset: 0x78
	// Line 179, Address: 0x1c606c, Func Offset: 0x7c
	// Line 182, Address: 0x1c607c, Func Offset: 0x8c
	// Line 183, Address: 0x1c60d0, Func Offset: 0xe0
	// Func End, Address: 0x1c60e0, Func Offset: 0xf0
}

// 
// Start address: 0x1c60e0
void bhEne08_Move(BH_PWORK* epw)
{
	// Line 218, Address: 0x1c60e0, Func Offset: 0
	// Func End, Address: 0x1c6100, Func Offset: 0x20
}

// 
// Start address: 0x1c6100
void bhEne08_MV00(BH_PWORK* epw)
{
	_anon9 vec;
	_anon1* hp;
	float dy;
	_anon9 pos;
	// Line 229, Address: 0x1c6100, Func Offset: 0
	// Line 235, Address: 0x1c6114, Func Offset: 0x14
	// Line 238, Address: 0x1c6134, Func Offset: 0x34
	// Line 240, Address: 0x1c6138, Func Offset: 0x38
	// Line 239, Address: 0x1c613c, Func Offset: 0x3c
	// Line 240, Address: 0x1c6140, Func Offset: 0x40
	// Line 241, Address: 0x1c6144, Func Offset: 0x44
	// Line 242, Address: 0x1c6148, Func Offset: 0x48
	// Line 243, Address: 0x1c6188, Func Offset: 0x88
	// Line 245, Address: 0x1c61dc, Func Offset: 0xdc
	// Line 246, Address: 0x1c61e4, Func Offset: 0xe4
	// Line 247, Address: 0x1c6238, Func Offset: 0x138
	// Line 249, Address: 0x1c6280, Func Offset: 0x180
	// Line 252, Address: 0x1c628c, Func Offset: 0x18c
	// Line 254, Address: 0x1c6298, Func Offset: 0x198
	// Line 255, Address: 0x1c62a8, Func Offset: 0x1a8
	// Line 256, Address: 0x1c62b0, Func Offset: 0x1b0
	// Line 262, Address: 0x1c62b4, Func Offset: 0x1b4
	// Line 261, Address: 0x1c62bc, Func Offset: 0x1bc
	// Line 266, Address: 0x1c62c0, Func Offset: 0x1c0
	// Line 261, Address: 0x1c62c8, Func Offset: 0x1c8
	// Line 266, Address: 0x1c62cc, Func Offset: 0x1cc
	// Line 261, Address: 0x1c62d0, Func Offset: 0x1d0
	// Line 262, Address: 0x1c62e8, Func Offset: 0x1e8
	// Line 264, Address: 0x1c6300, Func Offset: 0x200
	// Line 265, Address: 0x1c6314, Func Offset: 0x214
	// Line 266, Address: 0x1c6318, Func Offset: 0x218
	// Line 267, Address: 0x1c6338, Func Offset: 0x238
	// Line 270, Address: 0x1c6358, Func Offset: 0x258
	// Line 271, Address: 0x1c6370, Func Offset: 0x270
	// Line 270, Address: 0x1c6374, Func Offset: 0x274
	// Line 271, Address: 0x1c637c, Func Offset: 0x27c
	// Line 272, Address: 0x1c6384, Func Offset: 0x284
	// Line 273, Address: 0x1c639c, Func Offset: 0x29c
	// Line 272, Address: 0x1c63a4, Func Offset: 0x2a4
	// Line 273, Address: 0x1c63ac, Func Offset: 0x2ac
	// Line 274, Address: 0x1c63cc, Func Offset: 0x2cc
	// Line 278, Address: 0x1c63e4, Func Offset: 0x2e4
	// Line 279, Address: 0x1c6404, Func Offset: 0x304
	// Line 280, Address: 0x1c640c, Func Offset: 0x30c
	// Line 281, Address: 0x1c6424, Func Offset: 0x324
	// Line 280, Address: 0x1c642c, Func Offset: 0x32c
	// Line 281, Address: 0x1c6430, Func Offset: 0x330
	// Line 282, Address: 0x1c6438, Func Offset: 0x338
	// Line 283, Address: 0x1c6440, Func Offset: 0x340
	// Line 284, Address: 0x1c6448, Func Offset: 0x348
	// Line 285, Address: 0x1c6450, Func Offset: 0x350
	// Line 286, Address: 0x1c6458, Func Offset: 0x358
	// Line 287, Address: 0x1c6468, Func Offset: 0x368
	// Line 289, Address: 0x1c6478, Func Offset: 0x378
	// Line 290, Address: 0x1c6494, Func Offset: 0x394
	// Line 291, Address: 0x1c6498, Func Offset: 0x398
	// Line 292, Address: 0x1c64a0, Func Offset: 0x3a0
	// Line 294, Address: 0x1c64a8, Func Offset: 0x3a8
	// Line 296, Address: 0x1c64c4, Func Offset: 0x3c4
	// Line 294, Address: 0x1c64c8, Func Offset: 0x3c8
	// Line 296, Address: 0x1c64cc, Func Offset: 0x3cc
	// Line 297, Address: 0x1c64d0, Func Offset: 0x3d0
	// Line 299, Address: 0x1c64d4, Func Offset: 0x3d4
	// Func End, Address: 0x1c64ec, Func Offset: 0x3ec
}

// 
// Start address: 0x1c64f0
void bhEne08_MV01(BH_PWORK* epw)
{
	_anon9 vec;
	_anon1* hp;
	float dy;
	_anon9 pos;
	// Line 309, Address: 0x1c64f0, Func Offset: 0
	// Line 316, Address: 0x1c6504, Func Offset: 0x14
	// Line 319, Address: 0x1c6524, Func Offset: 0x34
	// Line 321, Address: 0x1c6528, Func Offset: 0x38
	// Line 320, Address: 0x1c652c, Func Offset: 0x3c
	// Line 321, Address: 0x1c6530, Func Offset: 0x40
	// Line 322, Address: 0x1c6534, Func Offset: 0x44
	// Line 323, Address: 0x1c6538, Func Offset: 0x48
	// Line 325, Address: 0x1c6578, Func Offset: 0x88
	// Line 326, Address: 0x1c65b0, Func Offset: 0xc0
	// Line 327, Address: 0x1c6604, Func Offset: 0x114
	// Line 328, Address: 0x1c664c, Func Offset: 0x15c
	// Line 329, Address: 0x1c6654, Func Offset: 0x164
	// Line 331, Address: 0x1c665c, Func Offset: 0x16c
	// Line 332, Address: 0x1c6668, Func Offset: 0x178
	// Line 334, Address: 0x1c666c, Func Offset: 0x17c
	// Line 333, Address: 0x1c6670, Func Offset: 0x180
	// Line 334, Address: 0x1c6674, Func Offset: 0x184
	// Line 335, Address: 0x1c6678, Func Offset: 0x188
	// Line 337, Address: 0x1c6680, Func Offset: 0x190
	// Line 338, Address: 0x1c6690, Func Offset: 0x1a0
	// Line 339, Address: 0x1c6694, Func Offset: 0x1a4
	// Line 345, Address: 0x1c6698, Func Offset: 0x1a8
	// Line 346, Address: 0x1c66a4, Func Offset: 0x1b4
	// Line 347, Address: 0x1c66b4, Func Offset: 0x1c4
	// Line 346, Address: 0x1c66b8, Func Offset: 0x1c8
	// Line 347, Address: 0x1c66bc, Func Offset: 0x1cc
	// Line 352, Address: 0x1c66dc, Func Offset: 0x1ec
	// Line 350, Address: 0x1c66e4, Func Offset: 0x1f4
	// Line 354, Address: 0x1c66e8, Func Offset: 0x1f8
	// Line 350, Address: 0x1c66f0, Func Offset: 0x200
	// Line 354, Address: 0x1c66f4, Func Offset: 0x204
	// Line 350, Address: 0x1c66f8, Func Offset: 0x208
	// Line 352, Address: 0x1c6710, Func Offset: 0x220
	// Line 353, Address: 0x1c6724, Func Offset: 0x234
	// Line 354, Address: 0x1c6728, Func Offset: 0x238
	// Line 355, Address: 0x1c6748, Func Offset: 0x258
	// Line 358, Address: 0x1c6768, Func Offset: 0x278
	// Line 359, Address: 0x1c6780, Func Offset: 0x290
	// Line 358, Address: 0x1c6784, Func Offset: 0x294
	// Line 359, Address: 0x1c678c, Func Offset: 0x29c
	// Line 360, Address: 0x1c6794, Func Offset: 0x2a4
	// Line 361, Address: 0x1c67ac, Func Offset: 0x2bc
	// Line 360, Address: 0x1c67b4, Func Offset: 0x2c4
	// Line 361, Address: 0x1c67bc, Func Offset: 0x2cc
	// Line 362, Address: 0x1c67dc, Func Offset: 0x2ec
	// Line 366, Address: 0x1c67f4, Func Offset: 0x304
	// Line 367, Address: 0x1c6814, Func Offset: 0x324
	// Line 368, Address: 0x1c681c, Func Offset: 0x32c
	// Line 369, Address: 0x1c6834, Func Offset: 0x344
	// Line 368, Address: 0x1c683c, Func Offset: 0x34c
	// Line 369, Address: 0x1c6840, Func Offset: 0x350
	// Line 370, Address: 0x1c6848, Func Offset: 0x358
	// Line 371, Address: 0x1c6850, Func Offset: 0x360
	// Line 372, Address: 0x1c6858, Func Offset: 0x368
	// Line 373, Address: 0x1c6860, Func Offset: 0x370
	// Line 374, Address: 0x1c6868, Func Offset: 0x378
	// Line 375, Address: 0x1c6878, Func Offset: 0x388
	// Line 377, Address: 0x1c6888, Func Offset: 0x398
	// Line 378, Address: 0x1c68a4, Func Offset: 0x3b4
	// Line 379, Address: 0x1c68a8, Func Offset: 0x3b8
	// Line 380, Address: 0x1c68b0, Func Offset: 0x3c0
	// Line 382, Address: 0x1c68b8, Func Offset: 0x3c8
	// Line 384, Address: 0x1c68d4, Func Offset: 0x3e4
	// Line 382, Address: 0x1c68d8, Func Offset: 0x3e8
	// Line 384, Address: 0x1c68dc, Func Offset: 0x3ec
	// Line 385, Address: 0x1c68e0, Func Offset: 0x3f0
	// Line 387, Address: 0x1c68e4, Func Offset: 0x3f4
	// Func End, Address: 0x1c68fc, Func Offset: 0x40c
}

// 
// Start address: 0x1c6900
void bhEne08_MV02(BH_PWORK* epw)
{
	// Line 397, Address: 0x1c6900, Func Offset: 0
	// Line 400, Address: 0x1c6910, Func Offset: 0x10
	// Line 403, Address: 0x1c6930, Func Offset: 0x30
	// Line 406, Address: 0x1c6990, Func Offset: 0x90
	// Line 407, Address: 0x1c699c, Func Offset: 0x9c
	// Line 408, Address: 0x1c69a0, Func Offset: 0xa0
	// Line 409, Address: 0x1c69a8, Func Offset: 0xa8
	// Line 412, Address: 0x1c69b0, Func Offset: 0xb0
	// Line 411, Address: 0x1c69b4, Func Offset: 0xb4
	// Line 412, Address: 0x1c69b8, Func Offset: 0xb8
	// Line 413, Address: 0x1c69bc, Func Offset: 0xbc
	// Line 414, Address: 0x1c69c4, Func Offset: 0xc4
	// Line 416, Address: 0x1c69cc, Func Offset: 0xcc
	// Line 417, Address: 0x1c69d8, Func Offset: 0xd8
	// Line 420, Address: 0x1c69e4, Func Offset: 0xe4
	// Line 421, Address: 0x1c69f0, Func Offset: 0xf0
	// Line 422, Address: 0x1c6a00, Func Offset: 0x100
	// Line 421, Address: 0x1c6a04, Func Offset: 0x104
	// Line 422, Address: 0x1c6a08, Func Offset: 0x108
	// Line 424, Address: 0x1c6a28, Func Offset: 0x128
	// Line 425, Address: 0x1c6a38, Func Offset: 0x138
	// Line 426, Address: 0x1c6a40, Func Offset: 0x140
	// Line 431, Address: 0x1c6a44, Func Offset: 0x144
	// Line 433, Address: 0x1c6a4c, Func Offset: 0x14c
	// Line 431, Address: 0x1c6a54, Func Offset: 0x154
	// Line 433, Address: 0x1c6a60, Func Offset: 0x160
	// Line 434, Address: 0x1c6a98, Func Offset: 0x198
	// Func End, Address: 0x1c6aa8, Func Offset: 0x1a8
}

// 
// Start address: 0x1c6ab0
void bhEne08_Nage()
{
	// Line 445, Address: 0x1c6ab0, Func Offset: 0
	// Func End, Address: 0x1c6ab8, Func Offset: 0x8
}

// 
// Start address: 0x1c6ac0
void bhEne08_Damage()
{
	// Line 456, Address: 0x1c6ac0, Func Offset: 0
	// Func End, Address: 0x1c6ac8, Func Offset: 0x8
}

// 
// Start address: 0x1c6ad0
void bhEne08_Die()
{
	// Line 467, Address: 0x1c6ad0, Func Offset: 0
	// Func End, Address: 0x1c6ad8, Func Offset: 0x8
}

