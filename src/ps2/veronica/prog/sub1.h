#ifndef _SUB1_H_
#define _SUB1_H_

#include "types.h"

unsigned int* ItemSearch(unsigned short itemid);

/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct npobj;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;
typedef struct _anon11;
typedef struct _anon12;
typedef struct _anon13;
typedef union _anon14;
typedef struct _anon15;
typedef struct _anon16;
typedef struct _anon17;
typedef struct _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct _anon23;
typedef struct _anon24;
typedef struct _anon25;
typedef struct _anon26;
typedef struct _anon27;
typedef struct _anon28;
typedef struct _anon29;
typedef struct _anon30;
typedef struct _anon31;
typedef struct _anon32;
typedef struct _anon33;
typedef struct _anon34;
typedef struct _anon35;
typedef struct _anon36;
typedef struct _anon37;
typedef struct _anon38;
typedef struct _anon39;
typedef struct _anon40;
typedef struct BH_PWORK;
typedef struct _anon41;
typedef struct _anon42;
typedef struct _anon43;
typedef struct _anon44;
typedef struct _anon45;
typedef struct _anon46;
typedef struct _anon47;
typedef struct _anon48;
typedef struct _anon49;
typedef struct _anon50;
typedef struct _anon51;
typedef struct _anon52;
typedef struct _anon53;
typedef struct _anon54;
typedef struct _anon55;
typedef struct _anon56;
typedef struct _anon57;
typedef struct _anon58;
typedef struct _anon59;
typedef struct _anon60;

typedef void(*type_185)(void*);

typedef unsigned short type_0[0];
typedef _anon14 type_1[6];
typedef _anon0* type_2[128];
typedef _anon0* type_3[512];
typedef char type_4[32];
typedef unsigned int type_5[32];
typedef _anon0* type_6[128];
typedef _anon49 type_7[4];
typedef unsigned int type_8[4];
typedef _anon0* type_9[128];
typedef char type_10[64];
typedef _anon3 type_11[40];
typedef short type_12[16];
typedef _anon54 type_13[32];
typedef unsigned int type_14[4][0];
typedef _anon7 type_15[16];
typedef _anon11 type_16[4];
typedef _anon0* type_17[128];
typedef short type_18[16];
typedef _anon0* type_19[512];
typedef _anon14 type_20[4];
typedef unsigned char type_21[64];
typedef _anon0* type_22[512];
typedef _anon3 type_23[8];
typedef unsigned char type_24[8];
typedef _anon7 type_25[4];
typedef unsigned char type_26[8][0];
typedef float type_27[16];
typedef _anon11 type_28[4];
typedef _anon0* type_29[512];
typedef int type_30[3];
typedef _anon14 type_31[4];
typedef unsigned int type_32[4];
typedef _anon14 type_33[4];
typedef _anon0* type_34[512];
typedef _anon3 type_35[24];
typedef _anon10* type_36[16];
typedef _anon14 type_37[4];
typedef _anon0* type_38[512];
typedef _anon10* type_39[16][16];
typedef _anon10* type_40[16][16][100];
typedef _anon0* type_41[32];
typedef char type_42[8];
typedef _anon0* type_43[512];
typedef _anon7 type_44[8];
typedef _anon10* type_45[1300];
typedef _anon0* type_46[32];
typedef float type_47[32];
typedef _anon0* type_48[512];
typedef _anon10* type_49[200];
typedef float type_50[6];
typedef _anon0* type_51[32];
typedef float type_52[6][12];
typedef unsigned short type_53[4];
typedef _anon11 type_54[2];
typedef unsigned int type_55[1];
typedef _anon3 type_56[16];
typedef char type_57[32];
typedef _anon7 type_58[4];
typedef _anon7 type_59[8];
typedef _anon10* type_60[8];
typedef int* type_61[16];
typedef unsigned short type_62[4];
typedef unsigned short type_63[4][4];
typedef _anon57 type_64[16];
typedef short type_65[32];
typedef _anon50 type_66[1];
typedef npobj* type_67[16];
typedef _anon3 type_68[8];
typedef _anon10* type_69[16];
typedef _anon7 type_70[8];
typedef _anon49 type_71[256];
typedef float type_72[4];
typedef _anon24 type_73[16];
typedef _anon11 type_74[4];
typedef float type_75[4];
typedef _anon14 type_76[4];
typedef int type_77[4];
typedef float type_78[4];
typedef unsigned int type_79[4];
typedef _anon3* type_80[14];
typedef _anon14 type_81[4];
typedef char type_82[256];
typedef _anon15* type_83[128];
typedef _anon3 type_84[40];
typedef _anon7 type_85[24];
typedef float type_86[3];
typedef float type_87[3][20];
typedef float type_88[4];
typedef unsigned char type_89[64];
typedef float type_90[4];
typedef float type_91[3];
typedef unsigned short type_92[5];
typedef float type_93[3][20];
typedef _anon49 type_94[4];
typedef unsigned short type_95[5][3];
typedef float type_96[4];
typedef _anon3 type_97[24];
typedef float type_98[3];
typedef _anon7 type_99[8];
typedef float type_100[3];
typedef _anon3* type_101[1];
typedef float type_102[3][20];
typedef float type_103[3];
typedef char type_104[8];
typedef int type_105[16];
typedef float type_106[3][20];
typedef _anon3 type_107[16];
typedef float type_108[3];
typedef int type_109[16][5];
typedef _anon7 type_110[8];
typedef void* type_111[2];
typedef _anon3 type_112[6];
typedef _anon7 type_113[16];
typedef _anon10* type_114[256];
typedef _anon3 type_115[16];
typedef _anon7 type_116[23];
typedef _anon7 type_117[32];
typedef unsigned char* type_118[256];
typedef float type_119[5];
typedef float type_120[5][5];
typedef short type_121[256];
typedef unsigned int type_122[2];
typedef _anon3 type_123[8];
typedef _anon50 type_124[5];
typedef int type_125[4];
typedef short type_126[256];
typedef _anon7 type_127[16];
typedef int type_128[8];
typedef _anon10* type_129[256];
typedef _anon43 type_130[4];
typedef _anon19 type_131[256];
typedef unsigned char type_132[4];
typedef unsigned char type_133[4][3];
typedef _anon3 type_134[10];
typedef _anon7 type_135[4];
typedef _anon11 type_136[5];
typedef int type_137[32];
typedef _anon50 type_138[450];
typedef int type_139[32][2];
typedef _anon11 type_140[5];
typedef _anon3 type_141[8];
typedef _anon3 type_142[24];
typedef _anon11 type_143[5];
typedef short type_144[256];
typedef int type_145[64];
typedef _anon24 type_146[450];
typedef unsigned int type_147[16];
typedef _anon11 type_148[16];
typedef _anon14 type_149[5];
typedef char type_150[4];
typedef unsigned int type_151[8];
typedef _anon11 type_152[4];
typedef char type_153[3];
typedef _anon14 type_154[5];
typedef _anon44 type_155[4];
typedef _anon14 type_156[4];
typedef _anon3* type_157[15];
typedef int type_158[32];
typedef int type_159[32][2];
typedef _anon47 type_160[4];
typedef _anon14 type_161[5];
typedef _anon3 type_162[8];
typedef int type_163[450];
typedef _anon7 type_164[8];
typedef _anon14 type_165[4];
typedef _anon14 type_166[5];
typedef unsigned int type_167[8];
typedef unsigned char type_168[450];
typedef unsigned int type_169[5];
typedef _anon3 type_170[8];
typedef _anon7 type_171[4];
typedef unsigned int type_172[5];
typedef unsigned short type_173[5];
typedef _anon3 type_174[16];
typedef unsigned short type_175[5];
typedef short type_176[2];
typedef _anon49 type_177[4];
typedef short type_178[5];
typedef short type_179[2][3];
typedef char type_180[16];
typedef unsigned int type_181[0];
typedef _anon7 type_182[9];
typedef char type_183[4];
typedef short type_184[5];
typedef float type_186[6];
typedef _anon32 type_187[2];
typedef unsigned int type_188[5];
typedef unsigned int type_189[32];
typedef float type_190[6][12];
typedef unsigned char type_191[256];
typedef short type_192[5];
typedef unsigned int type_193[16];
typedef float type_194[128];
typedef _anon3 type_195[64];
typedef unsigned int type_196[16];
typedef _anon7 type_197[20];
typedef _anon50 type_198[1];
typedef _anon7 type_199[16];
typedef short type_200[5];
typedef unsigned int type_201[32];
typedef _anon3 type_202[24];
typedef short type_203[5];
typedef _anon50 type_204[1];
typedef unsigned int type_205[16];
typedef _anon31 type_206[64];
typedef BH_PWORK* type_207[16];
typedef unsigned int type_208[8];
typedef _anon31 type_209[64];
typedef short type_210[5];
typedef unsigned int type_211[1];
typedef unsigned int type_212[384];
typedef _anon31 type_213[64];
typedef _anon7 type_214[5];
typedef unsigned int type_215[2];
typedef _anon58 type_216[0];
typedef _anon11 type_217[2];
typedef int* type_218[16];
typedef unsigned int type_219[4];
typedef short type_220[5];
typedef _anon11 type_221[4];
typedef unsigned int type_222[10];
typedef float type_223[3];
typedef npobj* type_224[16];
typedef int type_225[3];
typedef short type_226[5];
typedef _anon14 type_227[4];
typedef short type_228[0];
typedef float type_229[3];
typedef _anon7* type_230[23];
typedef _anon10* type_231[16];
typedef _anon3 type_232[16];
typedef _anon11 type_233[4];
typedef char type_234[4];
typedef _anon7 type_235[4];
typedef _anon14 type_236[4];
typedef _anon24 type_237[16];
typedef short type_238[4];
typedef _anon14 type_239[4];
typedef unsigned char type_240[0];
typedef _anon3 type_241[8];
typedef float type_242[2];
typedef unsigned char type_243[4];
typedef unsigned int type_244[3];
typedef _anon56 type_245[6];
typedef _anon60 type_246[0];
typedef unsigned int type_247[8];
typedef _anon3 type_248[24];
typedef _anon11 type_249[6];
typedef unsigned int type_250[4];
typedef _anon1 type_251[16];
typedef unsigned char type_252[2];

struct _anon0
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
	_anon10* txp[16];
	_anon24 mdl[16];
	_anon24* mlwP;
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
	_anon15* mnwP;
	_anon15* mnwPb;
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
	unsigned char* objbak;
	_anon9 cspr;
	int pn;
	_anon44* pvp;
	_anon47* tvp;
	_anon44 pv[4];
	_anon47 tv[4];
	int bl_src;
	int bl_dst;
	int ani_ct;
	int tex_id;
	int aspd;
	unsigned int gidx;
	int bank;
	char jno[16];
	char hide[4];
	void(*func)(void*);
	int idx;
	int Dummy2;
};

struct _anon1
{
	_anon54 c1;
	_anon54 c2;
	float r1;
	float r2;
};

struct _anon2
{
	float ratten;
	float ipd;
	float nrr;
	float frr;
	float cosi;
	float cose;
	float idev;
	float odev;
	float rate;
	float intns;
	int exp;
	int reserve;
	_anon54 lpnt;
	_anon54 lvctr;
	_anon54 lmvctr;
	_anon51 atten;
	_anon51 amb;
	_anon51 dif;
	_anon51 spc;
	_anon51 mamb;
	_anon51 mdif;
	_anon51 mspc;
};

struct _anon3
{
	float pos[3];
	short ang;
	unsigned char atr;
	char anim;
	unsigned char cen_no;
	unsigned char parts_num;
	float move;
	unsigned char setnum;
	_anon51 col;
	unsigned char color;
};

struct _anon4
{
	_anon50 subtx[5];
	_anon10 subtx_list;
	unsigned short subscreenmode;
	unsigned int statusflg;
	unsigned short testmode;
	unsigned int itmwrk;
	unsigned int itemid;
	unsigned short cmbitm;
	short open1;
	short open2;
	unsigned short mode;
	short ips1;
	short ipsdisp;
	unsigned int listcsr_0;
	unsigned int listcsr_1;
	unsigned int listcsr_2;
	unsigned int listcsr_3;
	float color00;
	unsigned short colorcount;
	unsigned short colorflg;
	unsigned char maincsr;
	unsigned char subcsr;
	unsigned int* pip;
	unsigned int* bxp;
	unsigned int* gb;
	unsigned char* ssp;
	char wait_;
	char wait;
	char number;
	char flag;
	unsigned char hp;
	unsigned char abc;
	unsigned char dnum;
	char dflg;
	unsigned char keywait;
	unsigned char boxwait;
	short actioncount;
	_anon33 scr;
	_anon11 clip[2];
	unsigned char flgchk;
	unsigned char flgtest;
	unsigned char* sspb;
	unsigned char sprflg;
	char number_;
	char flag_;
	unsigned short mesid;
	unsigned short taskloop;
	unsigned short wn;
	unsigned short wn_num;
	unsigned char* subp;
};

struct _anon5
{
	_anon54 pos;
	void* tex_p;
	void* mdl_p;
	int ang[3];
	int rdid;
	int ax1;
	int ay1;
	int az1;
	unsigned short flg;
};

struct _anon6
{
	unsigned int flg;
	unsigned int type;
	int aspd;
	int lkflg;
	int lkno;
	int lkono;
	int lsrc;
	float px;
	float py;
	float pz;
	float lx;
	float ly;
	float lz;
	float vx;
	float vy;
	float vz;
	float spc;
	float dif;
	float amb;
	float r;
	float g;
	float b;
	float nr;
	float fr;
	int iang;
	int oang;
	int ax;
	int ay;
	int az;
	unsigned int mode;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	float wpx;
	float wpy;
	float wpz;
	float wvx;
	float wvy;
	float wvz;
	float wspc;
	float wdif;
	float wamb;
	float wr;
	float wg;
	float wb;
	float wnr;
	float wfr;
	int wiang;
	int woang;
	int wax;
	int way;
	int waz;
	unsigned char* lkwkp;
	unsigned char* exp;
	_anon36* light;
};

struct _anon7
{
	short sx;
	short sy;
	short cx;
	short cy;
	short u1;
	short v1;
	short u2;
	short v2;
	short texid;
	short attr;
};

struct npobj
{
	unsigned int evalflags;
	_anon42* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon8
{
	unsigned int id;
	unsigned int support;
	unsigned int on;
	unsigned int off;
	unsigned int press;
	unsigned int release;
	unsigned short r;
	unsigned short l;
	short x1;
	short y1;
	short x2;
	short y2;
	char* name;
	void* extend;
	unsigned int old;
	_anon18* info;
};

struct _anon9
{
	_anon54 c;
	float r;
};

struct _anon10
{
	_anon50* textures;
	unsigned int nbTexture;
};

struct _anon11
{
	float x;
	float y;
};

struct _anon12
{
	_anon54 c1;
	_anon54 c2;
	float r;
};

struct _anon13
{
	float px;
	float py;
	float pz;
	int ay;
};

union _anon14
{
	unsigned int color;
	_anon45 tex;
	_anon46 argb;
};

struct _anon15
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon35* md2P;
	unsigned short* atrP;
};

struct _anon16
{
	_anon24 mdl;
	_anon5 mw;
	unsigned char* keep;
	unsigned char* keepbackup;
};

struct _anon17
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon57 keyf[16];
};

struct _anon18
{
	unsigned int type;
	unsigned int reserved[3];
	unsigned char is_root;
	unsigned char area_code;
	unsigned char connector_dir[2];
	char product_name[32];
	char license[64];
	unsigned short stdby_pow;
	unsigned short max_pow;
};

struct _anon19
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon20
{
	float cmat1[16];
	float rotmat[16];
	_anon54 pos_0;
	_anon54 pos_1;
	int ax;
	int ay;
	int az;
	int cax;
	int cay;
	int caz;
	float dis;
	float Dummy[3];
};

struct _anon21
{
	_anon22* cutp;
	_anon6* lgtp;
	_anon26* enep;
	_anon26* objp;
	_anon26* itmp;
	_anon30* effp;
	_anon31* walp;
	_anon31* etcp;
	_anon31* flrp;
	_anon13* posp;
	_anon31* rutp;
	unsigned char* ruttp;
	_anon39* evtp;
	_anon17* evcp;
	unsigned int* mesp;
	_anon6* evlp;
	unsigned char* dmp00;
	unsigned char* dmp01;
	unsigned char* dmp02;
	unsigned char* dmp03;
	unsigned char* dmp04;
	unsigned char* dmp05;
	unsigned char* dmp06;
	unsigned char* dmp07;
	unsigned char* dmp08;
	unsigned char* dmp09;
	unsigned char* dmp10;
	unsigned char* dmp11;
	unsigned char* dmp12;
	unsigned char* dmp13;
	unsigned char* dmp14;
	unsigned char* dmp15;
	int cut_n;
	int lgt_n;
	int ene_n;
	int obj_n;
	int itm_n;
	int eff_n;
	int wal_n;
	int etc_n;
	int flr_n;
	int pos_n;
	int rut_n;
	int evc_n;
	int mes_n;
	int evl_n;
	int dmy00;
	int dmy01;
	int dmy02;
	int dmy03;
	int dmy04;
	int dmy05;
	int dmy06;
	int dmy07;
	int dmy08;
	int dmy09;
	int dmy10;
	int dmy11;
	int dmy12;
	int dmy13;
	int dmy14;
	int dmy15;
	int dmy16;
	int dmy17;
	unsigned int flg;
	unsigned int bak_col;
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	float w;
	float h;
	float d;
	float grand[32];
	_anon24 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};

struct _anon22
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon25* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon32 cam[2];
	unsigned char exd[256];
};

struct _anon23
{
	_anon51 col;
	_anon50 fstx[1];
	_anon10 fstx_list;
	_anon50 fbtx[1];
	_anon10 fbtx_list;
	int afsmode;
	int ang00;
	int mode_00;
	int mode_01;
	int mode_02;
	int mode_03;
	unsigned int page;
	int rdsz;
	int tag;
	int move;
	unsigned int part_id;
	int filenum;
	int pagewait00;
	int pagewait01;
	short bufnum;
	short filecsr;
	short roll;
	short j;
	short k;
	short z;
	short koma[16];
	short koma2[16];
	unsigned char scrol;
	unsigned char scrolcnt;
	unsigned char flg;
	unsigned char* fsp;
	unsigned char* fspr;
	unsigned char* fspl;
	unsigned short tex_flg;
};

struct _anon24
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon10* texP;
	_anon41* owP;
};

struct _anon25
{
	unsigned int attr;
	char flr_no;
	char reserve0;
	char reserve1;
	char atr_tp;
	float h;
	float dmy;
	float minx;
	float minz;
	float maxx;
	float maxz;
};

struct _anon26
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	unsigned char mdlver;
	unsigned char wrk_no;
	char prm1;
	float px;
	float py;
	float pz;
	short ax;
	short az;
	short ay;
	short aspd;
	char hide[4];
};

struct _anon27
{
	unsigned int flg;
	char stg_no;
	char rom_no;
	unsigned char pos_no;
	unsigned char dor_tp;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
};

struct _anon28
{
	int lsrc;
	float iamb;
	float idif;
	float ispc;
	float nrang;
	float frang;
	void* func;
	int iang;
	int oang;
	_anon51 argb;
};

struct _anon29
{
	_anon11 pos_00[5];
	_anon11 pos_01[5];
	_anon11 pos_02[5];
	_anon11 heal_pos00;
	_anon11 heal_pos01;
	_anon14 uv_00[5];
	_anon14 uv_01[5];
	_anon14 col00[5];
	_anon14 col01[5];
	unsigned int ocol00[5];
	unsigned int ocol01[5];
	unsigned short fadework00[5];
	unsigned short fadework01[5];
	unsigned int pulseflg;
	unsigned int fadeflg;
	unsigned int count;
};

struct _anon30
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	short flr_no;
	unsigned short mdlver;
	float px;
	float py;
	float pz;
	float sx;
	float sy;
	float sz;
	short ay;
	short ax;
	int lkflg;
	int lkno;
	int lkono;
	float lx;
	float ly;
	float lz;
	int param;
};

struct _anon31
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

struct _anon32
{
	unsigned short flg;
	unsigned char lgtclip;
	char spd;
	float px;
	float py;
	float pz;
	float ln;
	float w;
	float h;
	float d;
	float y0;
	float y1;
	float y2;
	float y3;
	float am_spd;
	int ax;
	int ay;
	int az;
	int lax;
	int lay;
	short laz0;
	short laz1;
	short laz2;
	short laz3;
	char aa_spd;
	char fil_no;
	char fil_rt;
	char reserve;
	int pers;
	unsigned int hidobj[16];
	unsigned int hidlgt[8];
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
};

struct _anon33
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
};

struct _anon34
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon35
{
	void* p[2];
};

struct _anon36
{
	float mtrx[16];
	_anon54 pnt;
	_anon54 vctr;
	int stat;
	int reserve;
	_anon2 ltcal;
	_anon28 attr;
};

struct _anon37
{
	_anon54 p;
	float sx;
	float sy;
	int ang;
	_anon10* tlist;
	_anon7* tanim;
};

struct _anon38
{
	unsigned int ssd_ver;
	unsigned int ssd_flg;
	unsigned int ssd_reserve;
	char keytype;
	char adjust_x;
	char adjust_y;
	char vibration;
	int best_tm[8];
	unsigned int sys_partid;
	unsigned int itm_partid;
	unsigned int fil_partid;
	unsigned int dor_partid;
	unsigned int ss_flg;
	int pdm_no;
	unsigned int typ_flg;
	unsigned short typ_md0;
	unsigned short typ_md1;
	void* typ_exp;
	unsigned int tk_flg;
	unsigned int ts_flg;
	unsigned int gm_flg;
	unsigned int st_flg;
	unsigned int cb_flg;
	unsigned int rm_flg;
	unsigned int pt_flg;
	unsigned int sp_flg;
	unsigned int ef_flg;
	unsigned int error;
	unsigned int version;
	int save_ct;
	char ply_id;
	char stg_no;
	char rom_no;
	char rcase;
	char pos_no;
	char cut_no;
	char flr_no;
	char reserve0;
	int gm_mode;
	unsigned int ev_flg[32];
	unsigned int it_flg[16];
	unsigned int ic_flg[16];
	unsigned int ed_flg[32];
	unsigned int ky_flg[16];
	unsigned int mp_flg[8];
	unsigned int itm[384];
	unsigned int ply_stflg[4];
	_anon54 ply_pos;
	int ply_ang;
	char ply_wno[4];
	short ply_hp[4];
	unsigned char evt_posno[4];
	int time;
	int stv_tm;
	short spray_ct;
	short retry_ct;
	short clear_ct;
	short reserve1;
	unsigned int save_end;
	char stg_nob;
	char rom_nob;
	char pos_nob;
	char rcase_b;
	unsigned int en_flg[4];
	_anon10* et_lp[16][16][100];
	_anon10* ot_lp[1300];
	_anon10* it_lp[200];
	int eft_n;
	_anon10* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon8* p1per;
	_anon8* p2per;
	_anon8* kbper;
	_anon8* msper;
	_anon8 ms_per;
	int pad_port;
	unsigned int pad_on;
	unsigned int pad_oncpy;
	unsigned int pad_ps;
	unsigned int pad_rs;
	unsigned int pad_old;
	unsigned int pad_onb;
	unsigned int pad_psb;
	unsigned int pad_oldb;
	short pad_ax;
	short pad_ay;
	short pad_dx;
	short pad_dy;
	unsigned short pad_ar;
	unsigned short pad_al;
	int fixcno;
	int fixkno;
	unsigned int exm_attr;
	short evc_no;
	short evc_kn;
	short evc_ono;
	short evc_okn;
	int evc_sc;
	unsigned char mn_mode0;
	unsigned char mn_mode1;
	unsigned char mn_mode2;
	unsigned char mn_mode3;
	unsigned char mn_md0;
	unsigned char mn_md1;
	unsigned char mn_md2;
	unsigned char mn_md3;
	int mn_setct;
	unsigned int mn_stack[8];
	unsigned int sdm_flg;
	unsigned int sdm_mode;
	unsigned char* ltc_bp;
	unsigned int ltc_tsbak;
	int ewk_n;
	unsigned int enow;
	unsigned int onow;
	unsigned int efnow;
	int vsyc_ct;
	int vsyc_flg;
	int fog_ct;
	int bcl_ct;
	int gfrm_ct;
	int gframe;
	int eor_ct;
	unsigned int pfm_cts;
	int evt_tmd;
	int evt_tim;
	int evt_tdg;
	int evt_fcd;
	unsigned int evt_fcdct;
	unsigned int fsize;
	unsigned int rdtsz;
	unsigned char* memp;
	unsigned char* mempb;
	unsigned char* endp;
	unsigned char* rdtp;
	unsigned char* plmdlp;
	unsigned char* lmmdlp;
	unsigned char* wrmdlp;
	unsigned char* wlmdlp;
	unsigned char* plmthp;
	unsigned char* plbmtp;
	unsigned char* plwmtp;
	unsigned char* plzmtp;
	unsigned char* plemtp;
	unsigned char* plexwp;
	unsigned char* plhdwp;
	unsigned char* pletcp;
	unsigned char* subtxp;
	unsigned char* doordp;
	unsigned char* sbs_sp;
	_anon0* obwp;
	_anon0* itwp;
	_anon15* emtp[128];
	_anon15* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	_anon10* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon10* txblp[256];
	_anon19 txbp[256];
	unsigned char* ef_psp;
	_anon50 ef_tex[450];
	_anon10 ef_tlist;
	_anon52 ef;
	short efid[256];
	_anon24 efm[450];
	int ef_ct;
	int ef_ctb;
	int ef_extn;
	int ef_tn[450];
	unsigned char ef_pbkb[450];
	int ef_pbnk;
	int ef_slow;
	int ef_ctrn;
	int yk_ct;
	int mg_ct;
	int bl_ct;
	int windr;
	float winds;
	int windrb;
	float windsb;
	unsigned int thunder;
	float gas_py;
	int en_objn;
	BH_PWORK* en_obj[16];
	int ef_poln;
	int ef_mdfn;
	int ef_linn;
	int ef_ntxn;
	int ef_trsn;
	int ef_pncn;
	int ef_opqn;
	int ef_thln;
	int ef_ntx2dn;
	int ef_trs2dn;
	int ef_pnc2dn;
	int ef_fncn;
	_anon0* ef_pol[512];
	_anon0* ef_mdf[128];
	_anon0* ef_lin[512];
	_anon0* ef_ntx[512];
	_anon0* ef_trs[512];
	_anon0* ef_pnc[512];
	_anon0* ef_opq[512];
	_anon0* ef_thl[512];
	_anon0* ef_ntx2d[128];
	_anon0* ef_trs2d[128];
	_anon0* ef_pnc2d[128];
	_anon0* ef_fnc[512];
	int ob_nlgn;
	int ob_hlgn;
	int ob_spcn;
	_anon0* ob_nlg[32];
	_anon0* ob_hlg[32];
	_anon0* ob_spc[32];
	unsigned int ren_gid;
	_anon48 ren_info;
	_anon50 ren_tex[1];
	_anon10 ren_tlist;
	_anon49 rpb[256];
	int ren_n;
	int ren_idx[4];
	int wt_nbpt;
	float wt_px;
	float wt_pz;
	int wt_xp;
	int wt_zp;
	int wt_minx;
	int wt_minz;
	int wt_maxx;
	int wt_maxz;
	unsigned char* wt_wvp;
	_anon59 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon6* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon43 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon11 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon31* pl_htp;
	int costume;
	_anon54 hd_pos;
	_anon54 apos;
	_anon31* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon31 mwalp[64];
	_anon31 metcp[64];
	_anon31 mflrp[64];
	int dla_n;
	_anon31* htp;
	int psh_snd;
	int fog_cngct;
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	float fade_ct;
	float fade_hkn;
	float fade_ao;
	float fade_an;
	float fade_ap;
	float fade_ro;
	float fade_rn;
	float fade_rp;
	float fade_go;
	float fade_gn;
	float fade_gp;
	float fade_bo;
	float fade_bn;
	float fade_bp;
	unsigned int fade_pbk;
	unsigned short ssv_md0;
	unsigned short ssv_md1;
	int ssv_tim;
	float ssv_ct;
	float ssv_hkn;
	float ssv_ao;
	float ssv_an;
	float ssv_ap;
	short fil_no;
	short fil_rt;
	float rvf_sc;
	float rvf_sn;
	unsigned int rvfc[4];
	float cine_an;
	float cine_ap;
	unsigned int sco_flg;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
	int sb_id;
	int sb_cmd;
	int sb_rdid;
	int sb_rdsz;
	void* sb_rdp;
	void* sb_mlb;
	void* sb_ppp;
	_anon10* sb_tlist;
	int ddmd;
	_anon27 door;
	int mpmd;
	int mp_prm[4];
	unsigned short gov_md0;
	unsigned short gov_md1;
	int gov_ct;
	void* gov_exp;
	unsigned int com_flg;
	unsigned short com_md0;
	unsigned short com_md1;
	unsigned int com_num;
	void* com_exp;
	short ond_tnm;
	short ond_ud;
	char ond_cx;
	char ond_n[3];
	unsigned char ufo_md;
	unsigned char ufo_flg;
	short ufo_oidx;
	_anon54 ufo_pos;
	unsigned int opt_flg;
	unsigned short opt_md0;
	unsigned short opt_md1;
	void* opt_exp;
	unsigned int etc_idx;
	unsigned int flr_idx;
	int mvi_no;
	int mvi_tp;
	unsigned short mvi_md;
	unsigned short mvi_flg;
	unsigned int mvi_tsb;
	unsigned int mvi_spb;
	unsigned char* mvi_memp;
	unsigned int dcg_tkbak;
	unsigned int dcg_tsbak;
	unsigned int pau_spbak;
	unsigned int pau_pad_on;
	unsigned int pau_pad_ps;
	unsigned int pau_pad_old;
	unsigned char* pdm_dp;
	unsigned char* pdm_pd;
	int pdm_keytpb;
	int gat_ct;
	_anon1 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon54 ghtp[32];
	unsigned short db_md0;
	unsigned short db_md1;
	char db_stgno;
	char db_romno;
	char db_rcase;
	char db_muteki;
	short db_px;
	short db_py;
	int db_mes;
	int calc_v;
	unsigned int brkfg;
	char brkfg_typ[32];
	short brkfg_bit[32];
	unsigned int brkfg_tkb;
	unsigned int brkfg_tsb;
	int brkfg_ct;
	unsigned int bmt_size;
	unsigned int lmt_size;
	unsigned int emt_size;
	unsigned int wmt_size;
	char mes[256];
	float sfx;
	float sfy;
	float sfxn;
	float sfyn;
	float sfct;
};

struct _anon39
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon40
{
	unsigned int Type;
	unsigned int BitDepth;
	unsigned int PixelFormat;
	unsigned int nWidth;
	unsigned int nHeight;
	unsigned int TextureSize;
	unsigned int fSurfaceFlags;
	unsigned int* pSurface;
	unsigned int* pVirtual;
	unsigned int* pPhysical;
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
	_anon10* txp[16];
	_anon24 mdl[16];
	_anon24* mlwP;
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
	_anon15* mnwP;
	_anon15* mnwPb;
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
	_anon12 watr;
	_anon34* cpcl;
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

struct _anon41
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon42
{
	int* vlist;
	short* plist;
	_anon54 center;
	float r;
};

struct _anon43
{
	_anon54 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon44
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon45
{
	short u;
	short v;
};

struct _anon46
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct _anon47
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon48
{
	void* texaddr;
	_anon40 texsurface;
};

struct _anon49
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon50
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon51
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon52
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	short flr_no;
	unsigned short mdlver;
	float px;
	float py;
	float pz;
	float sx;
	float sy;
	float sz;
	short ay;
	short ax;
};

struct _anon53
{
	unsigned int flg;
	int camver;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
	float wpx;
	float wpy;
	float wpz;
	float plx;
	float ply;
	float plz;
	float pxp;
	float pyp;
	float pzp;
	float ofx;
	float ofy;
	float ofz;
	int ax;
	int ay;
	int az;
	int axp;
	int ayp;
	int azp;
	float ln;
	float pln;
	float xr;
	float xn;
	float yr;
	float yn;
	int pers;
	int ppers;
	int ncut;
	int ocut;
	unsigned int ocflg;
	unsigned int attr;
	float mtx[16];
	float mtxb[16];
	int evc_no;
	int hct;
	int ct0;
	int ct1;
	int keyf_no;
	float frm;
	float spd;
	float pxn;
	float pyn;
	float pzn;
	int axn;
	int ayn;
	int azn;
	int pe_ax;
	int pe_pers;
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	float ips[3][20];
	float ian[3][20];
	float ipf[3][20];
	float icr[3][20];
};

struct _anon54
{
	float x;
	float y;
	float z;
};

struct _anon55
{
	int flg;
	float alpha;
	float alphaset;
	float cnt00;
	float cnt01;
	float cnt02;
};

struct _anon56
{
	_anon11* p;
	_anon14* col;
	_anon14* tex;
	unsigned int num;
};

struct _anon57
{
	unsigned short flg;
	short frame;
	float px;
	float py;
	float pz;
	short ax;
	short ay;
	short az;
	short pers;
	unsigned int hidobj[8];
	unsigned int hidlgt[4];
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	short lkflg;
	short lkno;
	short lkono;
	short nxt_no;
	float lx;
	float ly;
	float lz;
	float prm_0;
	float prm_1;
	float prm_2;
	float prm_3;
	float prm_4;
	unsigned char* recp;
};

struct _anon58
{
	unsigned short max;
	short cmb;
	unsigned short type;
};

struct _anon59
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon60
{
	short ax;
	short ay;
	short az;
	short hide;
};*/

#endif
