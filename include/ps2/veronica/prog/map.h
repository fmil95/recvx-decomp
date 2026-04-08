#ifndef _MAP_H_
#define _MAP_H_

#include "types.h"
#include "enums.h"

void bhInitMap(enum_2 set_mod);
void bhSetMap();
void bhExitMap();
int bhReadMapData(char* namP);
void MapCnvStatus2Flag();
int bhControlMap();
void MapPadMain();
void MapViewMain();
void MapLightMain();
void MapPaletteMain();
void MapCodeProcess();
void MapBoolSet(int bol, int mod);
/*void MapDrawMarker(int mrk_no, _anon14* posP, int pal_no);
void MapDrawBackground(float depth, _anon5* p0P, _anon5* p1P);
void MapDrawSprite(_anon14* posP, int col, _enum_4 spr_no);*/
int MapGetFloorNo(void* datP, int rom_no, float pos_y);
/*void MapPurgeTree(_anon19* mlwP);*/
void MapFuncInit(int func_num);
/*_func_wrk_typ* MapFuncAlloc(int(*funcP)(_func_wrk_typ*), int param0);
void MapFuncFree(_func_wrk_typ* fwP);
void MapFuncDel(_func_wrk_typ* fwP);
_func_wrk_typ* MapFuncIns(_func_wrk_typ* bsP, _func_wrk_typ* fwP);
void MapFuncExec();
int FsubMapDraw(_func_wrk_typ* fwP);*/
int FsubBackDraw();
/*void MapEntrySprite(_enum_0 set_no, int mode);
int FsprSpriteDraw(_anon22* fsP);
int FsprSilhouetteDraw(_anon22* fsP);
int FsprArrowDraw(_anon22* fsP);
int FsprArrowDraw2(_anon22* fsP);
_anon56* MapEntryTask(int(*tskP)(_anon35*), _enum_1 chg_mde, int param0);
int FsubTaskMain(_anon56* ftP);*/
int FtskMapWait();
int FtskMapExit();
/*int FtskMapRead(_anon35* ftsP);
int FtskMapNormal(_anon35* ftsP);
int FtskMapZoom(_anon35* ftsP);
int FsubGaugeDrawZ(_anon3* fgP);
int FsubGaugeDrawX(_anon3* fgP);
int FsubGaugeDraw(_anon3* fgP);*/
void MapTagInit(int tag_num);
/*void MapTagEntry(float basP[16], int rom_no, _anon14* posP);
_tag_wrk_typ* MapTagConnect(int rom_no);
_tag_wrk_typ* MapTagCenter();
void MapDrawLine2(_anon5* srcP, _anon5* dstP, float pri, int pal);
void MapDrawLine(_anon5* srcP, _anon5* dstP, float pri, int pal);
void MapDrawFill(_anon5* srcP, _anon5* dstP, float pri, int pal);
void MapDrawPolyFill(_anon5* pnt, float pri, int pal);*/
void MapDrawMessage();
/*int FsubZoomCursor(_anon8* fzP);
int FsubZoomInfomation(_anon21* fiP);
_anon39 MapCnvArgb2Color(_anon11* argbP);
int FsubZoomScreen(_anon30* fsP);
int FsubCompass(_anon38* fcP);
int FsubModeMessage(_anon49* fmP);*/
void MapCncInit(int map_num, int flr_num);
/*_cnc_wrk_typ* MapCncGet(int map_no, int flr_no);
void MapCnc(_enum_3 dst, _enum_3 src, int status);*/
void MapCncConnect(unsigned short* datP);
/*_anon1* MapCheckNextMap(_anon1* mnP);*/
int GetGameMode();

/*typedef struct npobj;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _cnc_wrk_typ;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _tag_wrk_typ;
typedef struct _anon10;
typedef enum _enum_0;
typedef struct _anon11;
typedef struct _anon12;
typedef struct _func_wrk_typ;
typedef enum _enum_1;
typedef struct _anon13;
typedef struct _anon14;
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
typedef struct BH_PWORK;
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
typedef union _anon39;
typedef struct _anon40;
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
typedef enum _enum_2;
typedef enum _enum_3;
typedef struct _anon58;
typedef struct _anon59;
typedef enum _enum_4;
typedef struct _anon60;
typedef struct _anon61;
typedef struct _anon62;
typedef struct _map_wrk;
typedef struct _anon63;
typedef struct _anon64;
typedef struct _anon65;
typedef struct _anon66;

typedef int(*type_21)(_anon3*);
typedef int(*type_26)(_func_wrk_typ*);
typedef int(*type_53)(_func_wrk_typ*);
typedef int(*type_59)(_func_wrk_typ*);
typedef int(*type_91)(_func_wrk_typ*);
typedef int(*type_97)(_anon35*);
typedef int(*type_105)(_anon56*);
typedef int(*type_106)(_anon8*);
typedef void(*type_112)(void*);
typedef int(*type_113)(_anon35*);
typedef int(*type_116)(_anon21*);
typedef int(*type_121)(_anon35*);
typedef int(*type_134)(_anon35*);
typedef int(*type_153)(_anon30*);
typedef int(*type_155)(_anon35*);
typedef int(*type_160)(_anon38*);
typedef int(*type_161)(_anon35*);
typedef int(*type_165)(_anon35*);
typedef int(*type_167)(_anon49*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef _anon13 type_2[22];
typedef _anon5 type_3[2];
typedef _anon0* type_4[32];
typedef _anon39 type_5[2];
typedef _anon2* type_6[16];
typedef _anon19 type_7[8];
typedef _anon0* type_8[32];
typedef _anon0* type_9[512];
typedef _anon2* type_10[16][16];
typedef _anon2* type_11[16][16][100];
typedef char type_12[8];
typedef float type_13[4];
typedef _anon0* type_14[32];
typedef int type_15[3];
typedef _anon0* type_16[512];
typedef _anon2* type_17[1300];
typedef float type_18[16];
typedef char type_19[32];
typedef float type_20[32];
typedef _anon0* type_22[512];
typedef _anon2* type_23[200];
typedef short type_24[32];
typedef _anon42 type_25[1];
typedef _anon0* type_27[128];
typedef _anon5 type_28[4];
typedef _anon5 type_29[2];
typedef unsigned int type_30[1];
typedef _anon12 type_31[256];
typedef _anon2* type_32[8];
typedef int* type_33[16];
typedef _anon0* type_34[128];
typedef char type_35[64];
typedef int type_36[3];
typedef _anon66 type_37[16];
typedef npobj* type_38[16];
typedef _anon0* type_39[128];
typedef int type_40[4];
typedef _anon2* type_41[16];
typedef unsigned int type_42[4];
typedef float type_43[4];
typedef _anon19 type_44[16];
typedef _anon0* type_45[512];
typedef float type_46[4];
typedef char type_47[256];
typedef float type_48[4];
typedef float type_49[4];
typedef float type_50[4];
typedef float type_51[4];
typedef _anon7* type_52[128];
typedef unsigned char type_54[64];
typedef unsigned int type_55[2];
typedef char type_56[192];
typedef _anon11 type_57[32];
typedef float type_58[16][0];
typedef char type_60[8];
typedef void* type_61[2];
typedef int type_62[1];
typedef _anon2* type_63[256];
typedef int type_64[4];
typedef unsigned char* type_65[256];
typedef unsigned int type_66[2];
typedef short type_67[256];
typedef unsigned short type_68[81];
typedef _anon50 type_69[4];
typedef float type_70[3];
typedef short type_71[256];
typedef int type_72[3];
typedef int type_73[8];
typedef float type_74[3];
typedef _anon2* type_75[256];
typedef _anon16 type_76[256];
typedef _anon52 type_77[6];
typedef _anon55 type_78[4];
typedef _anon42 type_79[450];
typedef _anon11 type_80[32];
typedef _anon5 type_81[16];
typedef _anon39 type_82[3];
typedef short type_83[256];
typedef char type_84[3];
typedef int type_85[64];
typedef _anon19 type_86[450];
typedef unsigned int type_87[16];
typedef int type_88[9];
typedef char type_89[4];
typedef unsigned int type_90[8];
typedef _anon55 type_92[4];
typedef _tag_wrk_typ* type_93[4];
typedef _anon4 type_94[4];
typedef int type_95[450];
typedef _anon39 type_96[2];
typedef unsigned int type_98[8];
typedef unsigned char type_99[450];
typedef float type_100[128];
typedef _anon5 type_101[4];
typedef _anon5 type_102[2];
typedef _anon39 type_103[3];
typedef _anon39 type_104[2];
typedef _anon5 type_107[2];
typedef char type_108[16];
typedef char type_109[4];
typedef _anon5 type_110[4];
typedef unsigned int* type_111[10];
typedef _anon40 type_114[2];
typedef unsigned int type_115[32];
typedef unsigned char type_117[256];
typedef unsigned int type_118[16];
typedef _anon33 type_119[64];
typedef unsigned int type_120[16];
typedef _anon33 type_122[64];
typedef unsigned int type_123[32];
typedef _anon46 type_124[2];
typedef _anon63 type_125[18];
typedef _anon33 type_126[64];
typedef unsigned short type_127[49];
typedef unsigned int type_128[16];
typedef unsigned int type_129[3];
typedef _anon5 type_130[4];
typedef BH_PWORK* type_131[16];
typedef unsigned int type_132[8];
typedef _anon39 type_133[2];
typedef unsigned int type_135[1];
typedef unsigned int type_136[384];
typedef unsigned int type_137[2];
typedef unsigned char type_138[2];
typedef int* type_139[16];
typedef unsigned int type_140[4];
typedef _anon39 type_141[4];
typedef char type_142[32];
typedef npobj* type_143[16];
typedef char type_144[64];
typedef _anon5 type_145[4];
typedef _anon2* type_146[16];
typedef char type_147[4];
typedef _anon5 type_148[2];
typedef _anon19 type_149[16];
typedef short type_150[4];
typedef unsigned int type_151[2];
typedef unsigned char type_152[4];
typedef _anon53 type_154[16];
typedef unsigned int type_156[8];
typedef unsigned int type_157[32];
typedef unsigned int type_158[4];
typedef _anon14 type_159[32];
typedef _anon0* type_162[512];
typedef _anon5 type_163[2];
typedef _anon0* type_164[128];
typedef _anon0* type_166[512];
typedef unsigned char type_168[64];
typedef _anon36 type_169[11];
typedef _anon0* type_170[512];

struct npobj
{
	unsigned int evalflags;
	_anon51* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

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
	_anon2* txp[16];
	_anon19 mdl[16];
	_anon19* mlwP;
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
	_anon7* mnwP;
	_anon7* mnwPb;
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
	_anon62 cspr;
	int pn;
	_anon55* pvp;
	_anon4* tvp;
	_anon55 pv[4];
	_anon4 tv[4];
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
	int map_up;
	int flr_up;
	int map_down;
	int flr_down;
	int map_left;
	int flr_left;
	int map_right;
	int flr_right;
};

struct _anon2
{
	_anon42* textures;
	unsigned int nbTexture;
};

struct _anon3
{
	int mode;
	int param0;
	_anon14 gge_pos;
};

struct _anon4
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _cnc_wrk_typ
{
	int status;
	int map_no;
	int flr_no;
	_cnc_wrk_typ* flr_nextP;
	_cnc_wrk_typ* flr_prevP;
	_cnc_wrk_typ* map_nextP;
	_cnc_wrk_typ* map_prevP;
};

struct _anon5
{
	float x;
	float y;
};

struct _anon6
{
	float px;
	float py;
	float pz;
	int ay;
};

struct _anon7
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon41* md2P;
	unsigned short* atrP;
};

struct _anon8
{
	int mode;
	int time;
	_anon5* dstP;
	_anon5 pos_a0;
	_anon5 pos_a1;
	_anon5 pos_b0;
	_anon5 pos_b1;
};

struct _anon9
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
};

struct _tag_wrk_typ
{
	int rom_no;
	_anon14 pos;
	_tag_wrk_typ* tagPP[4];
};

struct _anon10
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon66 keyf[16];
};

enum _enum_0
{
	MP_SET_SILHOUETTE,
	MP_SET_ARROW_UP,
	MP_SET_ARROW_DOWN,
	MP_SET_ARROW_LEFT,
	MP_SET_ARROW_RIGHT,
	MP_SET_ARROW2_UP,
	MP_SET_ARROW2_DOWN,
	MP_SET_ARROW2_LEFT,
	MP_SET_ARROW2_RIGHT,
	MP_SET_LR_ZOOM,
	MP_SET_TITLE,
	MP_SET_NUM
};

struct _anon11
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon12
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _func_wrk_typ
{
	int mode;
	int param0;
	int param1;
	int param2;
	int FreeWrk[9];
	int(*funcP)(_func_wrk_typ*);
	_func_wrk_typ* prevP;
	_func_wrk_typ* nextP;
};

enum _enum_1
{
	MP_MOD_FIRST,
	MP_MOD_IDX_READ,
	MP_MOD_IDX_ANALYZE,
	MP_MOD_MAP_READ,
	MP_MOD_DAT_SET,
	MP_MOD_VEW_NORMAL,
	MP_MOD_VEW_ZOOM,
	MP_MOD_WAIT_NORMAL,
	MP_MOD_WAIT_ZOOM,
	MP_MOD_EXIT,
	MP_MOD_WAIT,
	MP_MOD_WAIT_NOMAP,
	MP_MOD_UNKNOWN = 0xffffffff
};

struct _anon13
{
	unsigned char itm_no;
	unsigned char flg_no;
};

struct _anon14
{
	float x;
	float y;
	float z;
};

struct _anon15
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

struct _anon16
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon17
{
	_anon18* cutp;
	_anon24* lgtp;
	_anon26* enep;
	_anon26* objp;
	_anon26* itmp;
	_anon32* effp;
	_anon33* walp;
	_anon33* etcp;
	_anon33* flrp;
	_anon6* posp;
	_anon33* rutp;
	unsigned char* ruttp;
	_anon45* evtp;
	_anon10* evcp;
	unsigned int* mesp;
	_anon24* evlp;
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
	_anon19 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};

struct _anon18
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon23* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon40 cam[2];
	unsigned char exd[256];
};

struct _anon19
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon2* texP;
	_anon47* owP;
};

struct _anon20
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
	_anon60* info;
};

struct _anon21
{
	int mode;
	_anon14 pos0;
	_anon5 pos1;
	int time;
};

struct _anon22
{
	int mode;
	_anon25 spr_dsp;
	_anon29 spr_cnt;
};

struct _anon23
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

struct _anon24
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
	_anon48* light;
};

struct _anon25
{
	_enum_1* act_mdeP;
	int act_bit;
	_enum_4 spr_no;
	int spr_col;
	_anon14 spr_pos;
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
	_anon2* txp[16];
	_anon19 mdl[16];
	_anon19* mlwP;
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
	_anon7* mnwP;
	_anon7* mnwPb;
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
	_anon64 watr;
	_anon43* cpcl;
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

struct _anon28
{
	short u;
	short v;
};

struct _anon29
{
	int spr_mde;
	int count;
};

struct _anon30
{
	int mode;
	_anon5 pos0;
	_anon5 pos1;
	float rad;
	int ang;
};

struct _anon31
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
	_anon14 ply_pos;
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
	_anon2* et_lp[16][16][100];
	_anon2* ot_lp[1300];
	_anon2* it_lp[200];
	int eft_n;
	_anon2* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon20* p1per;
	_anon20* p2per;
	_anon20* kbper;
	_anon20* msper;
	_anon20 ms_per;
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
	_anon7* emtp[128];
	_anon7* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	_anon2* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon2* txblp[256];
	_anon16 txbp[256];
	unsigned char* ef_psp;
	_anon42 ef_tex[450];
	_anon2 ef_tlist;
	_anon58 ef;
	short efid[256];
	_anon19 efm[450];
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
	_anon37 ren_info;
	_anon42 ren_tex[1];
	_anon2 ren_tlist;
	_anon12 rpb[256];
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
	_anon24* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon50 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon5 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon33* pl_htp;
	int costume;
	_anon14 hd_pos;
	_anon14 apos;
	_anon33* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon33 mwalp[64];
	_anon33 metcp[64];
	_anon33 mflrp[64];
	int dla_n;
	_anon33* htp;
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
	_anon2* sb_tlist;
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
	_anon14 ufo_pos;
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
	_anon53 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon14 ghtp[32];
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

struct _anon32
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

struct _anon33
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

struct _anon34
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct _anon35
{
	int param0;
	int param1;
	int param2;
	int param3;
};

struct _anon36
{
	_enum_4 spr_no;
	void* funcP;
	int act_bit;
	int spr_col;
	_anon14 spr_pos;
};

struct _anon37
{
	void* texaddr;
	_anon15 texsurface;
};

struct _anon38
{
	int mode;
	_anon14 pos;
	int ang;
	float scl_x;
	float scl_y;
};

union _anon39
{
	unsigned int color;
	_anon28 tex;
	_anon34 argb;
};

struct _anon40
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

struct _anon41
{
	void* p[2];
};

struct _anon42
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon43
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon44
{
	float label;
	short map_no;
	short flr_no;
};

struct _anon45
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon46
{
	_anon14 pos;
	_enum_4 spr;
};

struct _anon47
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon48
{
	float mtrx[16];
	_anon14 pnt;
	_anon14 vctr;
	int stat;
	int reserve;
	_anon54 ltcal;
	_anon61 attr;
};

struct _anon49
{
	int mode;
	_anon46* mdP;
};

struct _anon50
{
	_anon14 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon51
{
	int* vlist;
	short* plist;
	_anon14 center;
	float r;
};

struct _anon52
{
	int mrk_no;
	float scale;
	float offset;
	int pal_no;
};

struct _anon53
{
	_anon14 c1;
	_anon14 c2;
	float r1;
	float r2;
};

struct _anon54
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
	_anon14 lpnt;
	_anon14 lvctr;
	_anon14 lmvctr;
	_anon11 atten;
	_anon11 amb;
	_anon11 dif;
	_anon11 spc;
	_anon11 mamb;
	_anon11 mdif;
	_anon11 mspc;
};

struct _anon55
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon56
{
	int mode;
	_enum_1* map_mdeP;
	int chg_mde;
	int(*tskP)(_anon35*);
	_anon35 tsk_sub;
};

struct _anon57
{
	_anon5* p;
	_anon39* col;
	_anon39* tex;
	unsigned int num;
};

enum _enum_2
{
	MP_SET_GAME,
	MP_SET_EVENT,
	MP_SET_SUB
};

enum _enum_3
{
	MP000,
	MP001,
	MP100 = 0x10,
	MP101,
	MP102,
	MP200 = 0x20,
	MP201,
	MP202,
	MP203,
	MP300 = 0x30,
	MP301,
	MP302,
	MP400 = 0x40,
	MP401,
	MP500 = 0x50,
	MP600 = 0x60,
	MP601,
	MP602,
	MP700 = 0x70,
	MP701,
	MP702,
	MP703,
	MP704,
	MP800 = 0x80,
	MP801,
	MP900 = 0x90,
	MP901,
	MP902,
	MP903,
	MP904,
	MP905,
	MPa00 = 0xa0,
	MPa01,
	MPa02
};

struct _anon58
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

struct _anon59
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

enum _enum_4
{
	MP_SPR_SILHOUETTE,
	MP_SPR_ARROW_DOWN,
	MP_SPR_ARROW_UP,
	MP_SPR_ARROW_LEFT,
	MP_SPR_ARROW_RIGHT,
	MP_SPR_X_BUTTON,
	MP_SPR_B_BUTTON,
	MP_SPR_A_BUTTON,
	MP_SPR_LR_ZOOM,
	MP_SPR_CHANGE,
	MP_SPR_ITEM,
	MP_SPR_BOX,
	MP_SPR_SAVEPOINT,
	MP_SPR_DIAMOND,
	MP_SPR_10M_D,
	MP_SPR_10M_L,
	MP_SPR_0M,
	MP_SPR_TITLE,
	MP_SPR_NUM
};

struct _anon60
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

struct _anon61
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
	_anon11 argb;
};

struct _anon62
{
	_anon14 c;
	float r;
};

struct _map_wrk
{
	int status;
	_enum_1 map_mode;
	int time;
	int fil_mode;
	int prti_no;
	int slot_no;
	unsigned int pad_ps;
	float pad_al;
	float pad_ar;
	float pad_ax;
	float pad_ay;
	int map_no;
	int stg_no;
	int rom_no;
	int flr_no;
	int map_flr;
	int ply_stg;
	int ply_rom;
	int ply_flr;
	_anon19 map_mdl;
	npobj* map_objP;
	_anon19 MrkMdl[8];
	_anon14 vew_pos;
	int vew_ang[3];
	float vew_zom;
	_anon14 vew_max;
	_anon14 vew_min;
	float vew_mtxP[16];
	char Vew_Mtx[64];
	_anon14 vew_pos_bak;
	float vew_zom_bak;
	int cur_rom;
	int chk_rom;
	npobj* cur_objP;
	float cur_mtxP[16];
	float rom_mtxP[16];
	float tmp_mtxP[16];
	unsigned int Dummy2[2];
	char Rom_Mtx[192];
	short* map_cdeP;
	int cde_bol;
	_anon5 bck_p0;
	_anon5 bck_p1;
	float bck_depth;
	float map_scale;
	float lgt_scale;
	void* mem_bakP;
	void* rom_bakP;
	void* map_bufP;
	void* tex_pacP;
	_anon2* rom_texP;
	_anon2* map_texP;
	_anon2* stg_texP;
	float ar;
	float ag;
	float ab;
	float pr;
	float pg;
	float pb;
	int pitch;
	int yaw;
	_anon11 MapPal[32];
	_anon39 MapCol[3];
	_func_wrk_typ* busy_funcP;
	_func_wrk_typ* free_funcP;
	_anon65 map_spr;
	_anon11 map_mtr;
	int bnk_mde;
	int bnk_stg;
	int bnk_flr;
	int bnk_rom;
	int bnk_pal;
	int bnk_tag_rom;
	int bnk_tag_pal;
	int bnk_tag_pal_wal;
	unsigned int* mes_bufPP[10];
	_tag_wrk_typ* tag_wrkP;
	_tag_wrk_typ* cur_tagP;
	_tag_wrk_typ* fcs_tagP;
	int tag_num;
	float dst_zom;
	_anon14 dst_pos;
	_anon1 map_nxt;
	_cnc_wrk_typ* cnc_wrkP;
	_cnc_wrk_typ* cnc_hedP;
	_cnc_wrk_typ* cur_cncP;
	int cnc_map;
	int cnc_flr;
	unsigned int Dummy3[2];
};

struct _anon63
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

struct _anon64
{
	_anon14 c1;
	_anon14 c2;
	float r;
};

struct _anon65
{
	_anon14 p;
	float sx;
	float sy;
	int ang;
	_anon2* tlist;
	_anon63* tanim;
};

struct _anon66
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
};*/

#endif
