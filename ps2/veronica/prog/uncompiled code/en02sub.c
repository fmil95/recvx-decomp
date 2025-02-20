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

typedef void(*type_2)(BH_PWORK*);
typedef void(*type_11)(BH_PWORK*);

typedef char type_0[8];
typedef void* type_1[2];
typedef void(*type_3)(BH_PWORK*)[5];
typedef unsigned int type_4[2];
typedef float type_5[3];
typedef int type_6[3];
typedef float type_7[3];
typedef _anon10 type_8[4];
typedef int type_9[64];
typedef float type_10[16];
typedef void(*type_12)(BH_PWORK*)[2];
typedef unsigned int type_13[1];
typedef unsigned int type_14[2];
typedef int* type_15[16];
typedef npobj* type_16[16];
typedef _anon10 type_17[3];
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

struct _anon10
{
	int key;
	float cnt;
};

_anon10 Open[4];
_anon10 Close[3];
void(*bhEne02sub_Mode0)(BH_PWORK*)[2];
void(*bhEne02sub_MoveMode2)(BH_PWORK*)[5];
BH_PWORK* plp;

void bhEne02sub(BH_PWORK* epw);
void bhEne02sub_Init(BH_PWORK* epw);
void bhEne02sub_Move(BH_PWORK* epw);
void bhEne02sub_MV00();
void bhEne02sub_MV01(BH_PWORK* epw);
void bhEne02sub_MV02(BH_PWORK* epw);
void bhEne02sub_MV03(BH_PWORK* epw);
void bhEne02sub_MV04(BH_PWORK* epw);

// 
// Start address: 0x196330
void bhEne02sub(BH_PWORK* epw)
{
	// Line 128, Address: 0x196330, Func Offset: 0
	// Func End, Address: 0x196350, Func Offset: 0x20
}

// 
// Start address: 0x196350
void bhEne02sub_Init(BH_PWORK* epw)
{
	// Line 141, Address: 0x196350, Func Offset: 0
	// Line 142, Address: 0x19635c, Func Offset: 0xc
	// Line 143, Address: 0x196368, Func Offset: 0x18
	// Line 145, Address: 0x196374, Func Offset: 0x24
	// Line 146, Address: 0x196380, Func Offset: 0x30
	// Line 147, Address: 0x196388, Func Offset: 0x38
	// Line 151, Address: 0x196390, Func Offset: 0x40
	// Line 152, Address: 0x196398, Func Offset: 0x48
	// Line 153, Address: 0x19639c, Func Offset: 0x4c
	// Line 176, Address: 0x1963a0, Func Offset: 0x50
	// Func End, Address: 0x1963a8, Func Offset: 0x58
}

// 
// Start address: 0x1963b0
void bhEne02sub_Move(BH_PWORK* epw)
{
	// Line 188, Address: 0x1963b0, Func Offset: 0
	// Func End, Address: 0x1963d0, Func Offset: 0x20
}

// 
// Start address: 0x1963d0
void bhEne02sub_MV00()
{
	// Line 200, Address: 0x1963d0, Func Offset: 0
	// Func End, Address: 0x1963d8, Func Offset: 0x8
}

// 
// Start address: 0x1963e0
void bhEne02sub_MV01(BH_PWORK* epw)
{
	BH_PWORK* ep;
	// Line 210, Address: 0x1963e0, Func Offset: 0
	// Line 213, Address: 0x1963f0, Func Offset: 0x10
	// Line 215, Address: 0x196410, Func Offset: 0x30
	// Line 226, Address: 0x196414, Func Offset: 0x34
	// Line 217, Address: 0x196418, Func Offset: 0x38
	// Line 226, Address: 0x19641c, Func Offset: 0x3c
	// Line 215, Address: 0x196420, Func Offset: 0x40
	// Line 216, Address: 0x196428, Func Offset: 0x48
	// Line 217, Address: 0x196434, Func Offset: 0x54
	// Line 218, Address: 0x196440, Func Offset: 0x60
	// Line 220, Address: 0x196444, Func Offset: 0x64
	// Line 221, Address: 0x196448, Func Offset: 0x68
	// Line 222, Address: 0x196450, Func Offset: 0x70
	// Line 223, Address: 0x196458, Func Offset: 0x78
	// Line 224, Address: 0x196460, Func Offset: 0x80
	// Line 226, Address: 0x196470, Func Offset: 0x90
	// Line 228, Address: 0x196474, Func Offset: 0x94
	// Line 230, Address: 0x196480, Func Offset: 0xa0
	// Line 231, Address: 0x196494, Func Offset: 0xb4
	// Line 233, Address: 0x1964a4, Func Offset: 0xc4
	// Line 237, Address: 0x1964a8, Func Offset: 0xc8
	// Line 239, Address: 0x1964d0, Func Offset: 0xf0
	// Line 242, Address: 0x1964dc, Func Offset: 0xfc
	// Func End, Address: 0x1964ec, Func Offset: 0x10c
}

// 
// Start address: 0x1964f0
void bhEne02sub_MV02(BH_PWORK* epw)
{
	// Line 252, Address: 0x1964f0, Func Offset: 0
	// Line 253, Address: 0x196500, Func Offset: 0x10
	// Line 255, Address: 0x196520, Func Offset: 0x30
	// Line 256, Address: 0x196524, Func Offset: 0x34
	// Line 260, Address: 0x196528, Func Offset: 0x38
	// Line 255, Address: 0x19652c, Func Offset: 0x3c
	// Line 256, Address: 0x196534, Func Offset: 0x44
	// Line 257, Address: 0x196540, Func Offset: 0x50
	// Line 260, Address: 0x196544, Func Offset: 0x54
	// Line 262, Address: 0x196548, Func Offset: 0x58
	// Line 264, Address: 0x196554, Func Offset: 0x64
	// Line 265, Address: 0x196568, Func Offset: 0x78
	// Line 266, Address: 0x196578, Func Offset: 0x88
	// Line 267, Address: 0x19657c, Func Offset: 0x8c
	// Line 266, Address: 0x196580, Func Offset: 0x90
	// Line 267, Address: 0x196588, Func Offset: 0x98
	// Line 269, Address: 0x196594, Func Offset: 0xa4
	// Line 273, Address: 0x196598, Func Offset: 0xa8
	// Line 275, Address: 0x1965b4, Func Offset: 0xc4
	// Line 278, Address: 0x1965c0, Func Offset: 0xd0
	// Func End, Address: 0x1965d0, Func Offset: 0xe0
}

// 
// Start address: 0x1965d0
void bhEne02sub_MV03(BH_PWORK* epw)
{
	_anon8 pos;
	BH_PWORK* ep;
	// Line 288, Address: 0x1965d0, Func Offset: 0
	// Line 289, Address: 0x1965e0, Func Offset: 0x10
	// Line 292, Address: 0x1965e8, Func Offset: 0x18
	// Line 295, Address: 0x196620, Func Offset: 0x50
	// Line 310, Address: 0x196628, Func Offset: 0x58
	// Line 295, Address: 0x19662c, Func Offset: 0x5c
	// Line 312, Address: 0x196634, Func Offset: 0x64
	// Line 313, Address: 0x196674, Func Offset: 0xa4
	// Line 316, Address: 0x196680, Func Offset: 0xb0
	// Line 317, Address: 0x196698, Func Offset: 0xc8
	// Line 319, Address: 0x1966a0, Func Offset: 0xd0
	// Line 320, Address: 0x1966b8, Func Offset: 0xe8
	// Line 321, Address: 0x1966d0, Func Offset: 0x100
	// Line 323, Address: 0x1966e0, Func Offset: 0x110
	// Line 321, Address: 0x1966e4, Func Offset: 0x114
	// Line 322, Address: 0x1966e8, Func Offset: 0x118
	// Line 321, Address: 0x1966ec, Func Offset: 0x11c
	// Line 322, Address: 0x1966f4, Func Offset: 0x124
	// Line 323, Address: 0x1966fc, Func Offset: 0x12c
	// Line 322, Address: 0x196700, Func Offset: 0x130
	// Line 323, Address: 0x196708, Func Offset: 0x138
	// Line 324, Address: 0x196710, Func Offset: 0x140
	// Line 325, Address: 0x19671c, Func Offset: 0x14c
	// Line 326, Address: 0x196728, Func Offset: 0x158
	// Line 329, Address: 0x196734, Func Offset: 0x164
	// Line 330, Address: 0x196740, Func Offset: 0x170
	// Line 329, Address: 0x196744, Func Offset: 0x174
	// Line 330, Address: 0x19674c, Func Offset: 0x17c
	// Line 331, Address: 0x196760, Func Offset: 0x190
	// Line 336, Address: 0x196764, Func Offset: 0x194
	// Line 338, Address: 0x196780, Func Offset: 0x1b0
	// Line 340, Address: 0x19678c, Func Offset: 0x1bc
	// Line 341, Address: 0x1967a0, Func Offset: 0x1d0
	// Line 344, Address: 0x1967a4, Func Offset: 0x1d4
	// Line 347, Address: 0x1967a8, Func Offset: 0x1d8
	// Line 344, Address: 0x1967b4, Func Offset: 0x1e4
	// Line 345, Address: 0x1967b8, Func Offset: 0x1e8
	// Line 346, Address: 0x1967c0, Func Offset: 0x1f0
	// Line 347, Address: 0x1967c4, Func Offset: 0x1f4
	// Line 349, Address: 0x1967cc, Func Offset: 0x1fc
	// Line 351, Address: 0x1967d4, Func Offset: 0x204
	// Line 353, Address: 0x1967dc, Func Offset: 0x20c
	// Line 356, Address: 0x1967e4, Func Offset: 0x214
	// Line 357, Address: 0x196800, Func Offset: 0x230
	// Line 358, Address: 0x196810, Func Offset: 0x240
	// Line 360, Address: 0x19681c, Func Offset: 0x24c
	// Line 368, Address: 0x196820, Func Offset: 0x250
	// Func End, Address: 0x196834, Func Offset: 0x264
}

// 
// Start address: 0x196840
void bhEne02sub_MV04(BH_PWORK* epw)
{
	BH_PWORK* ep;
	// Line 378, Address: 0x196840, Func Offset: 0
	// Line 379, Address: 0x196850, Func Offset: 0x10
	// Line 381, Address: 0x196858, Func Offset: 0x18
	// Line 383, Address: 0x196878, Func Offset: 0x38
	// Line 384, Address: 0x19687c, Func Offset: 0x3c
	// Line 383, Address: 0x196880, Func Offset: 0x40
	// Line 384, Address: 0x196888, Func Offset: 0x48
	// Line 385, Address: 0x196894, Func Offset: 0x54
	// Line 386, Address: 0x196898, Func Offset: 0x58
	// Line 387, Address: 0x1968b8, Func Offset: 0x78
	// Line 390, Address: 0x1968d0, Func Offset: 0x90
	// Line 391, Address: 0x1968d4, Func Offset: 0x94
	// Line 387, Address: 0x1968d8, Func Offset: 0x98
	// Line 390, Address: 0x1968e0, Func Offset: 0xa0
	// Line 388, Address: 0x1968e4, Func Offset: 0xa4
	// Line 389, Address: 0x1968e8, Func Offset: 0xa8
	// Line 390, Address: 0x1968f0, Func Offset: 0xb0
	// Line 391, Address: 0x1968fc, Func Offset: 0xbc
	// Line 392, Address: 0x196900, Func Offset: 0xc0
	// Line 395, Address: 0x19690c, Func Offset: 0xcc
	// Line 396, Address: 0x196910, Func Offset: 0xd0
	// Line 395, Address: 0x196918, Func Offset: 0xd8
	// Line 396, Address: 0x19691c, Func Offset: 0xdc
	// Line 399, Address: 0x196924, Func Offset: 0xe4
	// Line 402, Address: 0x196954, Func Offset: 0x114
	// Line 399, Address: 0x19695c, Func Offset: 0x11c
	// Line 402, Address: 0x196960, Func Offset: 0x120
	// Line 404, Address: 0x19696c, Func Offset: 0x12c
	// Line 405, Address: 0x196980, Func Offset: 0x140
	// Line 406, Address: 0x196984, Func Offset: 0x144
	// Line 405, Address: 0x196988, Func Offset: 0x148
	// Line 406, Address: 0x196990, Func Offset: 0x150
	// Line 408, Address: 0x19699c, Func Offset: 0x15c
	// Line 412, Address: 0x1969a0, Func Offset: 0x160
	// Func End, Address: 0x1969b4, Func Offset: 0x174
}

