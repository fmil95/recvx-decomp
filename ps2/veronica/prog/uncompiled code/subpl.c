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

typedef void(*type_1)(BH_PWORK*);
typedef void(*type_3)(BH_PWORK*);
typedef void(*type_15)(BH_PWORK*);
typedef void(*type_20)(BH_PWORK*);
typedef void(*type_22)(BH_PWORK*);

typedef char type_0[8];
typedef void(*type_2)(BH_PWORK*)[1];
typedef void(*type_4)(BH_PWORK*)[15];
typedef void* type_5[2];
typedef unsigned int type_6[2];
typedef float type_7[3];
typedef int type_8[3];
typedef float type_9[3];
typedef int type_10[64];
typedef float type_11[16];
typedef unsigned int type_12[1];
typedef unsigned int type_13[2];
typedef int* type_14[16];
typedef void(*type_16)(BH_PWORK*)[15];
typedef npobj* type_17[16];
typedef _anon4* type_18[16];
typedef _anon7 type_19[16];
typedef void(*type_21)(BH_PWORK*)[120];
typedef void(*type_23)(BH_PWORK*)[7];
typedef unsigned char type_24[64];

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
	_anon8 c1;
	_anon8 c2;
	float r;
};

void(*Subpl_tbl)(BH_PWORK*)[7];
void(*subpl_init_tbl)(BH_PWORK*)[120];
void(*subpl_mv_tbl)(BH_PWORK*)[1];
void(*subpl_mv00_tbl)(BH_PWORK*)[15];
void(*subpl_mv01_tbl)(BH_PWORK*)[15];

void bhSubpl(BH_PWORK* epw);
void init_subpl(BH_PWORK* epw);
void em60_init(BH_PWORK* epw);
void move_subpl(BH_PWORK* epw);
void em_sce(BH_PWORK* epw);
void bhEne_Event(BH_PWORK* epw);
void bhEne_Event2(BH_PWORK* epw);
void mv00_subpl0(BH_PWORK* epw);
void mv00_subpl0Ex(BH_PWORK* epw);
void mv00_subpl1(BH_PWORK* epw);
void mv00_subpl2(BH_PWORK* epw);
void mv00_subpl2_0(BH_PWORK* epw);
void mv00_subpl3(BH_PWORK* epw);
void mv00_subpl3_0(BH_PWORK* epw);
void mv00_subpl5(BH_PWORK* epw);
void mv00_subpl6(BH_PWORK* epw);
void mv00_subpl0_1(BH_PWORK* epw);
int bhSub_DirTarget(BH_PWORK* epw, float x, float z, int ay);
void mv00_subpl10(BH_PWORK* epw);

// 
// Start address: 0x173ec0
void bhSubpl(BH_PWORK* epw)
{
	// Line 101, Address: 0x173ec0, Func Offset: 0
	// Line 104, Address: 0x173ecc, Func Offset: 0xc
	// Line 108, Address: 0x173ed0, Func Offset: 0x10
	// Line 106, Address: 0x173ed4, Func Offset: 0x14
	// Line 108, Address: 0x173edc, Func Offset: 0x1c
	// Line 104, Address: 0x173ee0, Func Offset: 0x20
	// Line 106, Address: 0x173ee8, Func Offset: 0x28
	// Line 108, Address: 0x173ef4, Func Offset: 0x34
	// Line 111, Address: 0x173f0c, Func Offset: 0x4c
	// Line 113, Address: 0x173f14, Func Offset: 0x54
	// Func End, Address: 0x173f24, Func Offset: 0x64
}

// 
// Start address: 0x173f30
void init_subpl(BH_PWORK* epw)
{
	// Line 161, Address: 0x173f30, Func Offset: 0
	// Line 163, Address: 0x173f38, Func Offset: 0x8
	// Func End, Address: 0x173f58, Func Offset: 0x28
}

// 
// Start address: 0x173f60
void em60_init(BH_PWORK* epw)
{
	// Line 171, Address: 0x173f60, Func Offset: 0
	// Line 174, Address: 0x173f6c, Func Offset: 0xc
	// Line 175, Address: 0x173f70, Func Offset: 0x10
	// Line 177, Address: 0x173f74, Func Offset: 0x14
	// Line 179, Address: 0x173f7c, Func Offset: 0x1c
	// Line 184, Address: 0x173f80, Func Offset: 0x20
	// Line 180, Address: 0x173f84, Func Offset: 0x24
	// Line 184, Address: 0x173f88, Func Offset: 0x28
	// Line 185, Address: 0x173f8c, Func Offset: 0x2c
	// Line 188, Address: 0x173f90, Func Offset: 0x30
	// Line 186, Address: 0x173f94, Func Offset: 0x34
	// Line 188, Address: 0x173f98, Func Offset: 0x38
	// Line 191, Address: 0x173f9c, Func Offset: 0x3c
	// Line 193, Address: 0x173fac, Func Offset: 0x4c
	// Line 194, Address: 0x173fbc, Func Offset: 0x5c
	// Line 195, Address: 0x173fcc, Func Offset: 0x6c
	// Line 197, Address: 0x173fdc, Func Offset: 0x7c
	// Line 199, Address: 0x173fec, Func Offset: 0x8c
	// Line 200, Address: 0x173ffc, Func Offset: 0x9c
	// Line 201, Address: 0x17400c, Func Offset: 0xac
	// Line 203, Address: 0x17401c, Func Offset: 0xbc
	// Line 204, Address: 0x174030, Func Offset: 0xd0
	// Func End, Address: 0x174040, Func Offset: 0xe0
}

// 
// Start address: 0x174040
void move_subpl(BH_PWORK* epw)
{
	// Line 222, Address: 0x174040, Func Offset: 0
	// Func End, Address: 0x174060, Func Offset: 0x20
}

// 
// Start address: 0x174060
void em_sce(BH_PWORK* epw)
{
	// Line 256, Address: 0x174060, Func Offset: 0
	// Func End, Address: 0x174080, Func Offset: 0x20
}

// 
// Start address: 0x174080
void bhEne_Event(BH_PWORK* epw)
{
	// Line 262, Address: 0x174080, Func Offset: 0
	// Func End, Address: 0x1740a0, Func Offset: 0x20
}

// 
// Start address: 0x1740a0
void bhEne_Event2(BH_PWORK* epw)
{
	// Line 267, Address: 0x1740a0, Func Offset: 0
	// Func End, Address: 0x1740c0, Func Offset: 0x20
}

// 
// Start address: 0x1740c0
void mv00_subpl0(BH_PWORK* epw)
{
	// Line 273, Address: 0x1740c0, Func Offset: 0
	// Line 274, Address: 0x1740c8, Func Offset: 0x8
	// Line 276, Address: 0x1740e8, Func Offset: 0x28
	// Line 277, Address: 0x1740ec, Func Offset: 0x2c
	// Line 278, Address: 0x1740f0, Func Offset: 0x30
	// Line 285, Address: 0x1740f4, Func Offset: 0x34
	// Line 277, Address: 0x1740f8, Func Offset: 0x38
	// Line 278, Address: 0x1740fc, Func Offset: 0x3c
	// Line 281, Address: 0x174100, Func Offset: 0x40
	// Line 285, Address: 0x174104, Func Offset: 0x44
	// Line 288, Address: 0x174110, Func Offset: 0x50
	// Line 306, Address: 0x174114, Func Offset: 0x54
	// Line 308, Address: 0x174124, Func Offset: 0x64
	// Func End, Address: 0x174130, Func Offset: 0x70
}

// 
// Start address: 0x174130
void mv00_subpl0Ex(BH_PWORK* epw)
{
	// Line 313, Address: 0x174130, Func Offset: 0
	// Line 314, Address: 0x174138, Func Offset: 0x8
	// Line 316, Address: 0x174158, Func Offset: 0x28
	// Line 317, Address: 0x17415c, Func Offset: 0x2c
	// Line 325, Address: 0x174160, Func Offset: 0x30
	// Line 317, Address: 0x174164, Func Offset: 0x34
	// Line 321, Address: 0x174168, Func Offset: 0x38
	// Line 325, Address: 0x17416c, Func Offset: 0x3c
	// Line 328, Address: 0x174178, Func Offset: 0x48
	// Line 346, Address: 0x17417c, Func Offset: 0x4c
	// Line 348, Address: 0x17418c, Func Offset: 0x5c
	// Func End, Address: 0x174198, Func Offset: 0x68
}

// 
// Start address: 0x1741a0
void mv00_subpl1(BH_PWORK* epw)
{
	// Line 353, Address: 0x1741a0, Func Offset: 0
	// Line 357, Address: 0x1741b0, Func Offset: 0x10
	// Line 359, Address: 0x1741d0, Func Offset: 0x30
	// Line 360, Address: 0x1741d4, Func Offset: 0x34
	// Line 361, Address: 0x1741d8, Func Offset: 0x38
	// Line 360, Address: 0x1741dc, Func Offset: 0x3c
	// Line 361, Address: 0x1741e0, Func Offset: 0x40
	// Line 364, Address: 0x1741e4, Func Offset: 0x44
	// Line 368, Address: 0x1741e8, Func Offset: 0x48
	// Line 370, Address: 0x1741ec, Func Offset: 0x4c
	// Line 377, Address: 0x1741f0, Func Offset: 0x50
	// Line 379, Address: 0x17423c, Func Offset: 0x9c
	// Line 377, Address: 0x174248, Func Offset: 0xa8
	// Line 379, Address: 0x174250, Func Offset: 0xb0
	// Line 381, Address: 0x174260, Func Offset: 0xc0
	// Line 382, Address: 0x174274, Func Offset: 0xd4
	// Line 384, Address: 0x174280, Func Offset: 0xe0
	// Func End, Address: 0x174290, Func Offset: 0xf0
}

// 
// Start address: 0x174290
void mv00_subpl2(BH_PWORK* epw)
{
	// Line 390, Address: 0x174290, Func Offset: 0
	// Line 392, Address: 0x1742a4, Func Offset: 0x14
	// Line 393, Address: 0x1742ac, Func Offset: 0x1c
	// Line 394, Address: 0x1742b0, Func Offset: 0x20
	// Line 393, Address: 0x1742b4, Func Offset: 0x24
	// Line 394, Address: 0x1742b8, Func Offset: 0x28
	// Line 402, Address: 0x1742bc, Func Offset: 0x2c
	// Line 403, Address: 0x1742c0, Func Offset: 0x30
	// Line 405, Address: 0x1742c4, Func Offset: 0x34
	// Func End, Address: 0x1742cc, Func Offset: 0x3c
}

// 
// Start address: 0x1742d0
void mv00_subpl2_0(BH_PWORK* epw)
{
	// Line 411, Address: 0x1742d0, Func Offset: 0
	// Line 413, Address: 0x1742e4, Func Offset: 0x14
	// Line 414, Address: 0x1742ec, Func Offset: 0x1c
	// Line 415, Address: 0x1742f4, Func Offset: 0x24
	// Line 423, Address: 0x1742f8, Func Offset: 0x28
	// Line 424, Address: 0x1742fc, Func Offset: 0x2c
	// Line 426, Address: 0x174300, Func Offset: 0x30
	// Func End, Address: 0x174308, Func Offset: 0x38
}

// 
// Start address: 0x174310
void mv00_subpl3(BH_PWORK* epw)
{
	// Line 431, Address: 0x174310, Func Offset: 0
	// Line 435, Address: 0x174320, Func Offset: 0x10
	// Line 437, Address: 0x174340, Func Offset: 0x30
	// Line 438, Address: 0x174344, Func Offset: 0x34
	// Line 439, Address: 0x174348, Func Offset: 0x38
	// Line 438, Address: 0x17434c, Func Offset: 0x3c
	// Line 439, Address: 0x174350, Func Offset: 0x40
	// Line 446, Address: 0x174354, Func Offset: 0x44
	// Line 454, Address: 0x174358, Func Offset: 0x48
	// Line 456, Address: 0x1743a4, Func Offset: 0x94
	// Line 458, Address: 0x1743b0, Func Offset: 0xa0
	// Line 454, Address: 0x1743b8, Func Offset: 0xa8
	// Line 456, Address: 0x1743c0, Func Offset: 0xb0
	// Line 458, Address: 0x1743cc, Func Offset: 0xbc
	// Line 460, Address: 0x1743d4, Func Offset: 0xc4
	// Func End, Address: 0x1743e4, Func Offset: 0xd4
}

// 
// Start address: 0x1743f0
void mv00_subpl3_0(BH_PWORK* epw)
{
	// Line 466, Address: 0x1743f0, Func Offset: 0
	// Line 470, Address: 0x174400, Func Offset: 0x10
	// Line 472, Address: 0x174420, Func Offset: 0x30
	// Line 473, Address: 0x174424, Func Offset: 0x34
	// Line 474, Address: 0x17442c, Func Offset: 0x3c
	// Line 481, Address: 0x174430, Func Offset: 0x40
	// Line 489, Address: 0x174434, Func Offset: 0x44
	// Line 491, Address: 0x174480, Func Offset: 0x90
	// Line 493, Address: 0x17448c, Func Offset: 0x9c
	// Line 489, Address: 0x174494, Func Offset: 0xa4
	// Line 491, Address: 0x17449c, Func Offset: 0xac
	// Line 493, Address: 0x1744a8, Func Offset: 0xb8
	// Line 495, Address: 0x1744b0, Func Offset: 0xc0
	// Func End, Address: 0x1744c0, Func Offset: 0xd0
}

// 
// Start address: 0x1744c0
void mv00_subpl5(BH_PWORK* epw)
{
	// Line 501, Address: 0x1744c0, Func Offset: 0
	// Line 502, Address: 0x1744c8, Func Offset: 0x8
	// Line 504, Address: 0x1744e8, Func Offset: 0x28
	// Line 505, Address: 0x1744ec, Func Offset: 0x2c
	// Line 507, Address: 0x1744f0, Func Offset: 0x30
	// Line 505, Address: 0x1744f4, Func Offset: 0x34
	// Line 506, Address: 0x1744f8, Func Offset: 0x38
	// Line 507, Address: 0x1744fc, Func Offset: 0x3c
	// Line 513, Address: 0x174500, Func Offset: 0x40
	// Line 515, Address: 0x174504, Func Offset: 0x44
	// Line 518, Address: 0x174508, Func Offset: 0x48
	// Line 520, Address: 0x174518, Func Offset: 0x58
	// Func End, Address: 0x174524, Func Offset: 0x64
}

// 
// Start address: 0x174530
void mv00_subpl6(BH_PWORK* epw)
{
	// Line 525, Address: 0x174530, Func Offset: 0
	// Line 526, Address: 0x174538, Func Offset: 0x8
	// Line 528, Address: 0x174558, Func Offset: 0x28
	// Line 529, Address: 0x17455c, Func Offset: 0x2c
	// Line 530, Address: 0x174560, Func Offset: 0x30
	// Line 532, Address: 0x174564, Func Offset: 0x34
	// Line 529, Address: 0x174568, Func Offset: 0x38
	// Line 530, Address: 0x17456c, Func Offset: 0x3c
	// Line 532, Address: 0x174570, Func Offset: 0x40
	// Line 538, Address: 0x174574, Func Offset: 0x44
	// Line 539, Address: 0x174580, Func Offset: 0x50
	// Line 541, Address: 0x174584, Func Offset: 0x54
	// Line 544, Address: 0x174588, Func Offset: 0x58
	// Line 546, Address: 0x174598, Func Offset: 0x68
	// Func End, Address: 0x1745a4, Func Offset: 0x74
}

// 
// Start address: 0x1745b0
void mv00_subpl0_1(BH_PWORK* epw)
{
	// Line 551, Address: 0x1745b0, Func Offset: 0
	// Line 552, Address: 0x1745b8, Func Offset: 0x8
	// Line 554, Address: 0x1745d8, Func Offset: 0x28
	// Line 555, Address: 0x1745dc, Func Offset: 0x2c
	// Line 556, Address: 0x1745e4, Func Offset: 0x34
	// Line 557, Address: 0x1745e8, Func Offset: 0x38
	// Line 559, Address: 0x1745ec, Func Offset: 0x3c
	// Line 561, Address: 0x1745fc, Func Offset: 0x4c
	// Func End, Address: 0x174608, Func Offset: 0x58
}

// 
// Start address: 0x174610
int bhSub_DirTarget(BH_PWORK* epw, float x, float z, int ay)
{
	int ang;
	// Line 565, Address: 0x174610, Func Offset: 0
	// Line 571, Address: 0x174620, Func Offset: 0x10
	// Line 572, Address: 0x174650, Func Offset: 0x40
	// Line 574, Address: 0x174660, Func Offset: 0x50
	// Line 575, Address: 0x174674, Func Offset: 0x64
	// Line 578, Address: 0x17468c, Func Offset: 0x7c
	// Line 579, Address: 0x174690, Func Offset: 0x80
	// Func End, Address: 0x1746a4, Func Offset: 0x94
}

// 
// Start address: 0x1746b0
void mv00_subpl10(BH_PWORK* epw)
{
	// Line 607, Address: 0x1746b0, Func Offset: 0
	// Line 609, Address: 0x1746c4, Func Offset: 0x14
	// Line 610, Address: 0x1746cc, Func Offset: 0x1c
	// Line 619, Address: 0x1746d4, Func Offset: 0x24
	// Line 620, Address: 0x1746d8, Func Offset: 0x28
	// Line 622, Address: 0x1746dc, Func Offset: 0x2c
	// Func End, Address: 0x1746e4, Func Offset: 0x34
}

