#ifndef _ADV_H_
#define _ADV_H_

#include "types.h"

void InitAdvSystem();
float AutoSaveLoadEasyDispMessage(float PosX, float PosY, unsigned char* ucpMsbTop, unsigned int MessageNo);

/*typedef struct _anon0;
typedef struct BH_PWORK;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct npobj;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;
typedef struct _anon11;
typedef struct _anon12;
typedef struct _anon13;
typedef struct _anon14;
typedef struct _anon15;
typedef struct _anon16;
typedef struct _anon17;
typedef union _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct tagSYSLOAD_SCREEN;
typedef struct _anon21;
typedef struct _anon22;
typedef struct _anon23;
typedef struct _anon24;
typedef struct tagMEMORYCARDSTATE;
typedef struct _anon25;
typedef struct _anon26;
typedef struct _anon27;
typedef struct _anon28;
typedef struct _anon29;
typedef struct tagCONFIGFILE;
typedef struct _anon30;
typedef struct _anon31;
typedef struct _anon32;
typedef struct _anon33;
typedef struct tagSAVEFILE;
typedef struct _anon34;
typedef struct tagICONINFORMATION;
typedef struct _anon35;
typedef struct _anon36;
typedef struct tagSYSSAVE_SCREEN;
typedef struct _anon37;
typedef struct _anon38;
typedef struct tagSELECTFILEINFO;
typedef struct _anon39;
typedef struct tagSELECTFILEWINDOW;
typedef struct _anon40;
typedef struct _anon41;
typedef struct _anon42;
typedef struct _anon43;
typedef struct _anon44;
typedef struct _anon45;
typedef struct _anon46;
typedef struct tagMEMORYCARDPORT;
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

typedef void(*type_190)(void*);

typedef unsigned int type_0[16];
typedef _anon4 type_1[64];
typedef BH_PWORK* type_2[16];
typedef _anon1* type_3[512];
typedef unsigned int type_4[8];
typedef int type_5[3];
typedef _anon4 type_6[64];
typedef unsigned int type_7[1];
typedef unsigned int type_8[384];
typedef _anon1* type_9[128];
typedef unsigned int type_10[2];
typedef _anon4 type_11[64];
typedef int* type_12[16];
typedef unsigned int type_13[4];
typedef _anon1* type_14[512];
typedef npobj* type_15[16];
typedef _anon1* type_16[512];
typedef _anon6* type_17[16];
typedef char type_18[4];
typedef _anon1* type_19[512];
typedef _anon10 type_20[16];
typedef short type_21[4];
typedef unsigned int type_22[3];
typedef _anon1* type_23[512];
typedef unsigned char type_24[4];
typedef _anon1* type_25[512];
typedef char type_26[4];
typedef unsigned int type_27[8];
typedef unsigned int type_28[4];
typedef _anon1* type_29[512];
typedef char type_30[2];
typedef _anon46 type_31[16];
typedef _anon1* type_32[128];
typedef char type_33[7];
typedef unsigned int type_34[32];
typedef _anon1* type_35[128];
typedef char type_36[3];
typedef _anon32 type_37[32];
typedef char type_38[3];
typedef _anon1* type_39[128];
typedef unsigned char type_40[64];
typedef char type_41[4];
typedef char type_42[4][4];
typedef _anon1* type_43[512];
typedef float type_44[16];
typedef char type_45[4];
typedef unsigned int type_46[4];
typedef int type_47[3];
typedef int type_48[3][3];
typedef _anon6* type_49[16];
typedef _anon6* type_50[16][16];
typedef _anon6* type_51[16][16][100];
typedef char type_52[8];
typedef _anon1* type_53[32];
typedef _anon6* type_54[1300];
typedef _anon1* type_55[32];
typedef void* type_56[2];
typedef float type_57[32];
typedef _anon6* type_58[200];
typedef _anon13 type_59[4];
typedef unsigned int type_60[3];
typedef _anon1* type_61[32];
typedef unsigned int type_62[1];
typedef _anon6* type_63[8];
typedef char type_64[32];
typedef int* type_65[16];
typedef float type_66[12];
typedef _anon7 type_67[16];
typedef _anon28 type_68[8];
typedef npobj* type_69[16];
typedef short type_70[32];
typedef _anon20 type_71[1];
typedef _anon6* type_72[16];
typedef unsigned int type_73[2];
typedef float type_74[4];
typedef _anon10 type_75[16];
typedef _anon19 type_76[256];
typedef int type_77[3];
typedef char type_78[8];
typedef float type_79[4];
typedef char type_80[8][2];
typedef unsigned int type_81[3];
typedef float type_82[4];
typedef int type_83[4];
typedef unsigned int type_84[4];
typedef float type_85[128];
typedef _anon0 type_86[16];
typedef float type_87[12];
typedef float type_88[3];
typedef int type_89[4];
typedef _anon31 type_90[21];
typedef _anon25* type_91[128];
typedef int type_92[3];
typedef char type_93[256];
typedef float type_94[3];
typedef unsigned char type_95[64];
typedef float type_96[4];
typedef float type_97[4];
typedef char type_98[50];
typedef float type_99[4];
typedef float type_100[4];
typedef char type_101[32];
typedef unsigned char type_102[4];
typedef unsigned char type_103[3];
typedef char type_104[8];
typedef int type_105[2];
typedef unsigned char type_106[10956];
typedef _anon27 type_107[0];
typedef float type_108[12];
typedef int type_109[8];
typedef tagMEMORYCARDPORT type_110[2];
typedef _anon13 type_111[4];
typedef int type_112[4][4];
typedef float type_113[4][3];
typedef float type_114[2];
typedef unsigned int type_115[0];
typedef unsigned char type_116[2];
typedef float type_117[4][3];
typedef _anon6* type_118[256];
typedef _anon13 type_119[4];
typedef unsigned int type_120[3];
typedef unsigned char* type_121[256];
typedef int type_122[4];
typedef unsigned char type_123[68];
typedef float type_124[4];
typedef float type_125[12];
typedef short type_126[256];
typedef char type_127[4];
typedef unsigned char type_128[64];
typedef unsigned char type_129[0];
typedef unsigned char type_130[2];
typedef unsigned char type_131[64];
typedef unsigned int type_132[4];
typedef int type_133[4];
typedef float type_134[2];
typedef short type_135[256];
typedef char type_136[32];
typedef unsigned char type_137[64];
typedef int type_138[8];
typedef int type_139[3];
typedef char type_140[64];
typedef unsigned char type_141[512];
typedef _anon6* type_142[256];
typedef unsigned int type_143[3];
typedef _anon50 type_144[4];
typedef _anon33 type_145[256];
typedef unsigned char* type_146[8];
typedef float type_147[4];
typedef float type_148[4][2];
typedef float type_149[12];
typedef _anon20 type_150[450];
typedef _anon47 type_151[0];
typedef _anon13 type_152[4];
typedef int type_153[3];
typedef short type_154[256];
typedef int type_155[64];
typedef _anon10 type_156[450];
typedef unsigned int type_157[16];
typedef _anon29 type_158[16];
typedef float type_159[4];
typedef float type_160[12];
typedef char type_161[4];
typedef unsigned int type_162[8];
typedef float type_163[4][2];
typedef float type_164[2];
typedef float type_165[2][2];
typedef _anon13 type_166[4];
typedef char type_167[3];
typedef _anon15 type_168[4];
typedef int type_169[450];
typedef unsigned int type_170[32];
typedef unsigned int type_171[8];
typedef unsigned char type_172[450];
typedef int type_173[0];
typedef unsigned int type_174[16];
typedef unsigned int type_175[16];
typedef _anon20 type_176[8];
typedef _anon20 type_177[8][2];
typedef unsigned int type_178[32];
typedef unsigned int type_179[16];
typedef unsigned int type_180[8];
typedef unsigned int type_181[384];
typedef _anon16 type_182[8];
typedef _anon16 type_183[8][2];
typedef unsigned int type_184[4];
typedef char type_185[16];
typedef char type_186[4];
typedef _anon53 type_187[7];
typedef char type_188[4];
typedef _anon29 type_189[4];
typedef _anon6 type_191[2];
typedef _anon44 type_192[2];
typedef unsigned int type_193[32];
typedef short type_194[4];
typedef _anon18 type_195[4];
typedef unsigned char type_196[4];
typedef unsigned char type_197[256];
typedef unsigned int type_198[16];
typedef _anon18 type_199[4];
typedef unsigned int type_200[16];
typedef unsigned int type_201[32];

struct _anon0
{
	float x1;
	float y1;
	float x2;
	float y2;
	float u1;
	float v1;
	float u2;
	float v2;
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
	_anon10 mdl[16];
	_anon10* mlwP;
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
	_anon25* mnwP;
	_anon25* mnwPb;
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
	_anon54 watr;
	_anon45* cpcl;
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
	_anon10 mdl[16];
	_anon10* mlwP;
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
	_anon25* mnwP;
	_anon25* mnwPb;
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
	_anon52 cspr;
	int pn;
	_anon13* pvp;
	_anon15* tvp;
	_anon13 pv[4];
	_anon15 tv[4];
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

struct _anon2
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon3
{
	float mtrx[16];
	_anon32 pnt;
	_anon32 vctr;
	int stat;
	int reserve;
	_anon51 ltcal;
	_anon56 attr;
};

struct npobj
{
	unsigned int evalflags;
	_anon9* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon4
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

struct _anon5
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

struct _anon6
{
	_anon20* textures;
	unsigned int nbTexture;
};

struct _anon7
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

struct _anon8
{
	int PatId;
	int Mode;
	int Mode2;
	int NextMode;
	int NextReturnCode;
	int PortId;
	int OptIndex;
	int OptLevel;
	int NextOptLevel;
	int OptScrX;
	int OptScrY;
	unsigned int PalNo;
	unsigned int PalMode;
	unsigned int FontBaseColor;
	unsigned char* SysMemPtr;
	unsigned char* MsgPtr;
	unsigned char* ptr[8];
	float Timer;
	float FadeRate;
	float FadeSpeed;
	float SaverTimer;
	float SaverRate;
	float FlushCount;
	float FlushSpeed;
	float FlushCount2;
	float FlushSpeed2;
	float ScrollPlatePosX[2][2];
	char Active;
	char AppMode;
	char ExtraFlag;
	char FadeType;
	char SaverCommand;
	char Count;
	char LastLevel;
	char FromTitle;
	char CurrentDiscId;
	char NextDiscId;
	char ErrorId;
	unsigned char ErrorMsgFlushCount;
	char AnimId;
	unsigned char AnimTime;
	char GenFlag;
	char PalFlag;
	char SrFlag;
	char OptFadeType;
	char TexFlag;
	char SoundMode;
	char vibration;
	char keytype;
	char adjust_x;
	char adjust_y;
	char OptSaveFlag;
	char vMode;
	char DriveNo;
	char MsgNo;
	char DepthLevel;
	char OldVmOpMode;
	char VmOpMode;
	char SetTexture[2];
	char KeyCommandCount[7];
	char Cursor[3];
	char CursorMax[3];
	char CursorFlag[4][4];
	char ModeCommandId[4];
};

struct _anon9
{
	int* vlist;
	short* plist;
	_anon32 center;
	float r;
};

struct _anon10
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon6* texP;
	_anon30* owP;
};

struct _anon11
{
	char ppStrPvpl[4];
	unsigned int ppNextTag;
	unsigned short ppCategoryCode;
	unsigned short ppBankId;
	unsigned short ppEntryOffset;
	unsigned short ppEntryCount;
};

struct _anon12
{
	short u;
	short v;
};

struct _anon13
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon14
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct _anon15
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon16
{
	void* texaddr;
	_anon5 texsurface;
};

struct _anon17
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
	_anon3* light;
};

union _anon18
{
	unsigned int color;
	_anon12 tex;
	_anon14 argb;
};

struct _anon19
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon20
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct tagSYSLOAD_SCREEN
{
	unsigned int ulState;
	unsigned int ulSubState;
	unsigned int ulMemCheckCountTimer;
	unsigned int ulFileSize;
	unsigned short usExitFlag;
	unsigned short usLoopCount;
	int lCardState;
	char cMesFlag;
	tagCONFIGFILE* pConfigFile;
	tagSAVEFILE* pSaveFile;
	tagICONINFORMATION* pIconInfo;
	tagMEMORYCARDSTATE* pMcState;
	tagSELECTFILEINFO* pSelectFileInfo;
	tagSELECTFILEWINDOW* pSelectFileWindow;
	void* vpReadBuffer;
};

struct _anon21
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon22
{
	float px;
	float py;
	float pz;
	int ay;
};

struct _anon23
{
	unsigned int TotalSize;
	unsigned int ClutSize;
	unsigned int ImageSize;
	unsigned short HeaderSize;
	unsigned short ClutColors;
	unsigned char PictFormat;
	unsigned char MipMapTextures;
	unsigned char ClutType;
	unsigned char ImageType;
	unsigned short ImageWidth;
	unsigned short ImageHeight;
	unsigned long GsTex0;
	unsigned long GsTex1;
	unsigned int GsRegs;
	unsigned int GsTexClut;
};

struct _anon24
{
	void* p[2];
};

struct tagMEMORYCARDSTATE
{
	unsigned int ulState;
	unsigned int ulError;
	unsigned int ulMcSubState;
	unsigned int ulFileSize;
	int lCurrentPort;
	int lOpenFileNumber;
	int lSelectFileNumber;
	int lOpenMode;
	unsigned short usMcSysState;
	void* vpAddr;
	char cCurrentDir[50];
	char cOpenFileName[32];
	char cRetryCount;
	char cMcCheckFlag;
	char cCheckMcFlag;
	tagMEMORYCARDPORT Port[2];
};

struct _anon25
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon24* md2P;
	unsigned short* atrP;
};

struct _anon26
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon7 keyf[16];
};

struct _anon27
{
	unsigned int globalIndex;
	unsigned int bank;
	unsigned int tspparambuffer;
	unsigned int texparambuffer;
	unsigned int texaddr;
	_anon16 texinfo;
	unsigned short count;
	unsigned short dummy;
};

struct _anon28
{
	unsigned int col1;
	unsigned int col2;
};

struct _anon29
{
	float x;
	float y;
};

struct tagCONFIGFILE
{
	unsigned int ssd_ver;
	unsigned int ssd_flg;
	unsigned int ssd_reserve;
	char keytype;
	char adjust_x;
	char adjust_y;
	char vibration;
	int best_tm[8];
	unsigned int Check_Sam;
};

struct _anon30
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon31
{
	float Sx;
	float Sy;
	int StartMsgNo;
	int NaviMsgNo;
	int MsgType;
};

struct _anon32
{
	float x;
	float y;
	float z;
};

struct _anon33
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct tagSAVEFILE
{
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
	_anon32 ply_pos;
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
	unsigned int CheckSam;
};

struct _anon34
{
	_anon35* cutp;
	_anon17* lgtp;
	_anon38* enep;
	_anon38* objp;
	_anon38* itmp;
	_anon41* effp;
	_anon4* walp;
	_anon4* etcp;
	_anon4* flrp;
	_anon22* posp;
	_anon4* rutp;
	unsigned char* ruttp;
	_anon2* evtp;
	_anon26* evcp;
	unsigned int* mesp;
	_anon17* evlp;
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
	_anon10 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};

struct tagICONINFORMATION
{
	_anon42 icon;
};

struct _anon35
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon37* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon44 cam[2];
	unsigned char exd[256];
};

struct _anon36
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
	_anon48* info;
};

struct tagSYSSAVE_SCREEN
{
	unsigned int ulState;
	unsigned int ulSubState;
	unsigned int ulMemCheckCountTimer;
	unsigned int ulFileSize;
	int lCardState;
	short sSelectCur;
	unsigned short usExitFlag;
	unsigned short usMesMode;
	unsigned short usSaveMode;
	unsigned short usLoopCount;
	char cMesFlag;
	tagCONFIGFILE* pConfigFile;
	tagSAVEFILE* pSaveFile;
	tagICONINFORMATION* pIconInfo;
	tagMEMORYCARDSTATE* pMcState;
	tagSELECTFILEINFO* pSelectFileInfo;
	tagSELECTFILEWINDOW* pSelectFileWindow;
	void* vpReadBuffer;
};

struct _anon37
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

struct _anon38
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

struct tagSELECTFILEINFO
{
	int FileNumber;
	int save_ct;
	int gm_mode;
	char ply_id;
	char saveroom;
};

struct _anon39
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

struct tagSELECTFILEWINDOW
{
	unsigned int ulFileState;
	tagSELECTFILEINFO* pRecordTop;
	int lRecordMax;
	short slDispTopNumber;
	short slDispRecordNumber;
	short sMesCur;
	short sCursol;
	short sWaitMesTimer;
	float slLineNumber;
	int slDispWriteMesMax;
	int slDispWriteMes;
	unsigned int ulfoundationColor;
};

struct _anon40
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
	_anon32 ply_pos;
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
	_anon6* et_lp[16][16][100];
	_anon6* ot_lp[1300];
	_anon6* it_lp[200];
	int eft_n;
	_anon6* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon36* p1per;
	_anon36* p2per;
	_anon36* kbper;
	_anon36* msper;
	_anon36 ms_per;
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
	_anon1* obwp;
	_anon1* itwp;
	_anon25* emtp[128];
	_anon25* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	_anon6* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon6* txblp[256];
	_anon33 txbp[256];
	unsigned char* ef_psp;
	_anon20 ef_tex[450];
	_anon6 ef_tlist;
	_anon55 ef;
	short efid[256];
	_anon10 efm[450];
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
	_anon1* ef_pol[512];
	_anon1* ef_mdf[128];
	_anon1* ef_lin[512];
	_anon1* ef_ntx[512];
	_anon1* ef_trs[512];
	_anon1* ef_pnc[512];
	_anon1* ef_opq[512];
	_anon1* ef_thl[512];
	_anon1* ef_ntx2d[128];
	_anon1* ef_trs2d[128];
	_anon1* ef_pnc2d[128];
	_anon1* ef_fnc[512];
	int ob_nlgn;
	int ob_hlgn;
	int ob_spcn;
	_anon1* ob_nlg[32];
	_anon1* ob_hlg[32];
	_anon1* ob_spc[32];
	unsigned int ren_gid;
	_anon16 ren_info;
	_anon20 ren_tex[1];
	_anon6 ren_tlist;
	_anon19 rpb[256];
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
	_anon49 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon17* lgtp;
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
	_anon29 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon4* pl_htp;
	int costume;
	_anon32 hd_pos;
	_anon32 apos;
	_anon4* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon4 mwalp[64];
	_anon4 metcp[64];
	_anon4 mflrp[64];
	int dla_n;
	_anon4* htp;
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
	_anon6* sb_tlist;
	int ddmd;
	_anon39 door;
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
	_anon32 ufo_pos;
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
	_anon46 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon32 ghtp[32];
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

struct _anon41
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

struct _anon42
{
	unsigned char Head[4];
	unsigned short Reserv1;
	unsigned short OffsLF;
	unsigned int Reserv2;
	unsigned int TransRate;
	int BgColor[4][4];
	float LightDir[4][3];
	float LightColor[4][3];
	float Ambient[4];
	unsigned char TitleName[68];
	unsigned char FnameView[64];
	unsigned char FnameCopy[64];
	unsigned char FnameDel[64];
	unsigned char Reserve3[512];
};

struct _anon43
{
	_anon29* p;
	_anon18* col;
	_anon18* tex;
	unsigned int num;
};

struct _anon44
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

struct _anon45
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon46
{
	_anon32 c1;
	_anon32 c2;
	float r1;
	float r2;
};

struct tagMEMORYCARDPORT
{
	int lCrntType;
	int lPrevType;
	int lFreeSize;
	int lFormatType;
};

struct _anon47
{
	int PerType;
	int OldPerType;
	int PerTypeEx;
	unsigned int Flag;
	int SoftReset;
	unsigned int on;
	unsigned int press;
	unsigned int Rept;
	unsigned int on2;
	unsigned int on2old;
	unsigned int press2;
	unsigned short l;
	unsigned short r;
	short x1;
	short y1;
	short x2;
	short y2;
	short Calibrate;
};

struct _anon48
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

struct _anon49
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon50
{
	_anon32 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon51
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
	_anon32 lpnt;
	_anon32 lvctr;
	_anon32 lmvctr;
	_anon21 atten;
	_anon21 amb;
	_anon21 dif;
	_anon21 spc;
	_anon21 mamb;
	_anon21 mdif;
	_anon21 mspc;
};

struct _anon52
{
	_anon32 c;
	float r;
};

struct _anon53
{
	char Item;
	char MaxItem;
	char Item2;
	char MaxItem2;
	char SelectFlag;
	char NextLevel;
	char ReturnLevel;
	char Switch;
	char NextFadeType;
};

struct _anon54
{
	_anon32 c1;
	_anon32 c2;
	float r;
};

struct _anon55
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

struct _anon56
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
	_anon21 argb;
};*/

#endif
