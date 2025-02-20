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

typedef void(*type_8)(BH_PWORK*);

typedef char type_0[8];
typedef void* type_1[2];
typedef unsigned int type_2[2];
typedef float type_3[3];
typedef int type_4[3];
typedef float type_5[3];
typedef int type_6[64];
typedef float type_7[16];
typedef void(*type_9)(BH_PWORK*)[6];
typedef unsigned int type_10[1];
typedef unsigned int type_11[2];
typedef int* type_12[16];
typedef npobj* type_13[16];
typedef _anon4* type_14[16];
typedef _anon7 type_15[16];
typedef unsigned char type_16[64];

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

void(*bhEne71_Mode0)(BH_PWORK*)[6];

void bhEne71(BH_PWORK* epw);
void bhEne71_Init(BH_PWORK* epw);
void bhEne71_Move();
void bhEne71_Nage();
void bhEne71_Damage();
void bhEne71_Die();

// 
// Start address: 0x21b950
void bhEne71(BH_PWORK* epw)
{
	// Line 121, Address: 0x21b950, Func Offset: 0
	// Line 123, Address: 0x21b960, Func Offset: 0x10
	// Line 126, Address: 0x21b980, Func Offset: 0x30
	// Line 127, Address: 0x21b98c, Func Offset: 0x3c
	// Line 128, Address: 0x21b99c, Func Offset: 0x4c
	// Line 129, Address: 0x21b9a0, Func Offset: 0x50
	// Line 130, Address: 0x21b9ac, Func Offset: 0x5c
	// Line 131, Address: 0x21b9bc, Func Offset: 0x6c
	// Line 133, Address: 0x21b9c0, Func Offset: 0x70
	// Line 136, Address: 0x21b9dc, Func Offset: 0x8c
	// Line 144, Address: 0x21b9f0, Func Offset: 0xa0
	// Line 145, Address: 0x21b9f8, Func Offset: 0xa8
	// Func End, Address: 0x21ba08, Func Offset: 0xb8
}

// 
// Start address: 0x21ba10
void bhEne71_Init(BH_PWORK* epw)
{
	// Line 156, Address: 0x21ba10, Func Offset: 0
	// Line 162, Address: 0x21ba1c, Func Offset: 0xc
	// Line 163, Address: 0x21ba28, Func Offset: 0x18
	// Line 167, Address: 0x21ba38, Func Offset: 0x28
	// Line 170, Address: 0x21ba3c, Func Offset: 0x2c
	// Line 175, Address: 0x21ba40, Func Offset: 0x30
	// Line 167, Address: 0x21ba44, Func Offset: 0x34
	// Line 170, Address: 0x21ba4c, Func Offset: 0x3c
	// Line 174, Address: 0x21ba58, Func Offset: 0x48
	// Line 175, Address: 0x21ba5c, Func Offset: 0x4c
	// Line 176, Address: 0x21ba80, Func Offset: 0x70
	// Line 177, Address: 0x21ba88, Func Offset: 0x78
	// Line 178, Address: 0x21ba8c, Func Offset: 0x7c
	// Line 179, Address: 0x21ba90, Func Offset: 0x80
	// Line 180, Address: 0x21ba98, Func Offset: 0x88
	// Line 181, Address: 0x21ba9c, Func Offset: 0x8c
	// Line 184, Address: 0x21baa0, Func Offset: 0x90
	// Line 185, Address: 0x21babc, Func Offset: 0xac
	// Line 186, Address: 0x21bac8, Func Offset: 0xb8
	// Line 187, Address: 0x21bad8, Func Offset: 0xc8
	// Line 190, Address: 0x21bae0, Func Offset: 0xd0
	// Line 191, Address: 0x21bae8, Func Offset: 0xd8
	// Line 192, Address: 0x21baec, Func Offset: 0xdc
	// Line 193, Address: 0x21baf0, Func Offset: 0xe0
	// Line 197, Address: 0x21baf4, Func Offset: 0xe4
	// Line 196, Address: 0x21baf8, Func Offset: 0xe8
	// Line 197, Address: 0x21bafc, Func Offset: 0xec
	// Line 198, Address: 0x21bb00, Func Offset: 0xf0
	// Line 199, Address: 0x21bb10, Func Offset: 0x100
	// Func End, Address: 0x21bb20, Func Offset: 0x110
}

// 
// Start address: 0x21bb20
void bhEne71_Move()
{
	// Line 223, Address: 0x21bb20, Func Offset: 0
	// Func End, Address: 0x21bb28, Func Offset: 0x8
}

// 
// Start address: 0x21bb30
void bhEne71_Nage()
{
	// Line 235, Address: 0x21bb30, Func Offset: 0
	// Func End, Address: 0x21bb38, Func Offset: 0x8
}

// 
// Start address: 0x21bb40
void bhEne71_Damage()
{
	// Line 247, Address: 0x21bb40, Func Offset: 0
	// Func End, Address: 0x21bb48, Func Offset: 0x8
}

// 
// Start address: 0x21bb50
void bhEne71_Die()
{
	// Line 259, Address: 0x21bb50, Func Offset: 0
	// Func End, Address: 0x21bb58, Func Offset: 0x8
}

