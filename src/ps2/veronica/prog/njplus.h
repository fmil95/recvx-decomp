#ifndef _NJPLUS_H_
#define _NJPLUS_H_

/*typedef struct npobj;
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
};*/

#endif
