#include "../../../ps2/veronica/prog/en04.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/zonzon.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/sdfunc.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/rutchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"


/*typedef struct npobj;
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
typedef struct _anon11;
typedef struct _anon12;
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

typedef void(*type_4)(BH_PWORK*);
typedef void(*type_13)(BH_PWORK*);
typedef void(*type_58)(BH_PWORK*);
typedef void(*type_61)(BH_PWORK*);
typedef void(*type_64)(BH_PWORK*);
typedef void(*type_65)(BH_PWORK*);
typedef void(*type_72)(BH_PWORK*);
typedef void(*type_86)(BH_PWORK*, BH_PWORK*);
typedef void(*type_92)(BH_PWORK*);
typedef void(*type_106)(BH_PWORK*);
typedef void(*type_118)(void*);
typedef void(*type_141)(BH_PWORK*);
typedef void(*type_153)(BH_PWORK*);

typedef void(*type_0)(BH_PWORK*)[1];
typedef _anon36 type_1[10];
typedef unsigned int type_2[4];
typedef _anon0* type_3[512];
typedef _anon0* type_5[32];
typedef _anon1* type_6[16];
typedef _anon0* type_7[32];
typedef _anon0* type_8[512];
typedef _anon1* type_9[16][16];
typedef _anon1* type_10[16][16][100];
typedef char type_11[8];
typedef _anon0* type_12[32];
typedef void(*type_14)(BH_PWORK*)[2];
typedef _anon32 type_15[30];
typedef _anon0* type_16[512];
typedef _anon1* type_17[1300];
typedef _anon22 type_18[0];
typedef char type_19[32];
typedef float type_20[32];
typedef _anon0* type_21[512];
typedef _anon1* type_22[200];
typedef short type_23[32];
typedef _anon27 type_24[1];
typedef _anon0* type_25[128];
typedef _anon28 type_26[17];
typedef float type_27[16][0];
typedef unsigned int type_28[1];
typedef _anon7 type_29[256];
typedef _anon1* type_30[8];
typedef int* type_31[16];
typedef _anon0* type_32[128];
typedef _anon49 type_33[16];
typedef npobj* type_34[16];
typedef _anon0* type_35[128];
typedef int type_36[4];
typedef int type_37[0];
typedef _anon1* type_38[16];
typedef unsigned int type_39[4];
typedef float type_40[4];
typedef _anon14 type_41[16];
typedef _anon0* type_42[512];
typedef float type_43[4];
typedef int type_44[10];
typedef char type_45[256];
typedef float type_46[4];
typedef float type_47[4];
typedef char type_48[6];
typedef float type_49[4];
typedef float type_50[4];
typedef _anon5* type_51[128];
typedef _anon36 type_52[4];
typedef unsigned char type_53[64];
typedef int type_54[16];
typedef float type_55[16];
typedef int type_56[16][2];
typedef char type_57[8];
typedef void(*type_59)(BH_PWORK*)[12];
typedef void* type_60[2];
typedef void(*type_62)(BH_PWORK*)[4];
typedef _anon46 type_63[21];
typedef void(*type_66)(BH_PWORK*)[13];
typedef void(*type_67)(BH_PWORK*)[3];
typedef _anon1* type_68[256];
typedef BH_PWORK type_69[0];
typedef int type_70[4];
typedef unsigned char* type_71[256];
typedef unsigned int type_73[2];
typedef short type_74[256];
typedef void(*type_75)(BH_PWORK*)[3];
typedef _anon33 type_76[4];
typedef float type_77[3];
typedef int type_78[3];
typedef short type_79[256];
typedef int type_80[3];
typedef int type_81[8];
typedef float type_82[3];
typedef _anon1* type_83[256];
typedef _anon32 type_84[6];
typedef int type_85[4];
typedef void(*type_87)(BH_PWORK*, BH_PWORK*)[2];
typedef _anon10 type_88[256];
typedef _anon27 type_89[450];
typedef int type_90[3];
typedef _anon35 type_91[16];
typedef void(*type_93)(BH_PWORK*)[3];
typedef short type_94[256];
typedef char type_95[3];
typedef int type_96[64];
typedef _anon14 type_97[450];
typedef unsigned int type_98[16];
typedef char type_99[7];
typedef float type_100[5];
typedef char type_101[4];
typedef unsigned int type_102[8];
typedef int type_103[5];
typedef _anon40 type_104[4];
typedef _anon2 type_105[4];
typedef int type_107[450];
typedef void(*type_108)(BH_PWORK*)[6];
typedef unsigned int type_109[8];
typedef unsigned char type_110[450];
typedef float type_111[128];
typedef char type_112[20];
typedef _anon41 type_113[4];
typedef int type_114[4];
typedef char type_115[16];
typedef char type_116[4];
typedef _anon18 type_117[22];
typedef unsigned int type_119[32];
typedef _anon25 type_120[2];
typedef unsigned char type_121[256];
typedef unsigned int type_122[16];
typedef _anon50 type_123[19];
typedef _anon12 type_124[64];
typedef unsigned int type_125[16];
typedef _anon12 type_126[64];
typedef unsigned int type_127[32];
typedef _anon12 type_128[64];
typedef unsigned int type_129[16];
typedef unsigned int type_130[3];
typedef _anon12* type_131[32];
typedef BH_PWORK* type_132[16];
typedef unsigned int type_133[8];
typedef unsigned int type_134[1];
typedef unsigned int type_135[384];
typedef unsigned int type_136[2];
typedef int type_137[3];
typedef unsigned char type_138[2];
typedef unsigned int type_139[4];
typedef int* type_140[16];
typedef char type_142[8];
typedef void(*type_143)(BH_PWORK*)[3];
typedef char type_144[8][1];
typedef char type_145[32];
typedef npobj* type_146[16];
typedef char type_147[64];
typedef _anon1* type_148[16];
typedef char type_149[4];
typedef _anon14 type_150[16];
typedef _anon8 type_151[19];
typedef short type_152[4];
typedef void(*type_154)(BH_PWORK*)[3];
typedef unsigned char type_155[4];
typedef _anon38 type_156[16];
typedef unsigned int type_157[8];
typedef unsigned int type_158[32];
typedef unsigned int type_159[4];
typedef _anon36 type_160[32];
typedef _anon0* type_161[512];
typedef _anon0* type_162[128];
typedef _anon0* type_163[512];
typedef unsigned char type_164[64];
typedef _anon0* type_165[512];

struct npobj
{
	unsigned int evalflags;
	_anon34* model;
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
	_anon1* txp[16];
	_anon14 mdl[16];
	_anon14* mlwP;
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
	_anon48 watr;
	_anon28* cpcl;
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
	_anon1* txp[16];
	_anon14 mdl[16];
	_anon14* mlwP;
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
	unsigned char* objbak;
	_anon47 cspr;
	int pn;
	_anon40* pvp;
	_anon2* tvp;
	_anon40 pv[4];
	_anon2 tv[4];
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
	_anon27* textures;
	unsigned int nbTexture;
};

struct _anon2
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon3
{
	float px;
	float py;
	float pz;
	int ay;
};

struct _anon4
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon5
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon26* md2P;
	unsigned short* atrP;
};

struct _anon6
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon49 keyf[16];
};

struct _anon7
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon8
{
	int lnk_obj;
	float x;
	float y;
	float z;
	float xlen;
	float ylen;
	float size;
	float len;
};

struct _anon9
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

struct _anon10
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon11
{
	_anon13* cutp;
	_anon17* lgtp;
	_anon20* enep;
	_anon20* objp;
	_anon20* itmp;
	_anon23* effp;
	_anon12* walp;
	_anon12* etcp;
	_anon12* flrp;
	_anon3* posp;
	_anon12* rutp;
	unsigned char* ruttp;
	_anon29* evtp;
	_anon6* evcp;
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
	_anon14 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};

struct _anon12
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


struct _anon13
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon16* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon25 cam[2];
	unsigned char exd[256];
};

struct _anon14
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon4* owP;
};

struct _anon15
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
	_anon44* info;
};

struct _anon16
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
	_anon31* light;
};

struct _anon18
{
	int flg;
	int nm_act;
	int nm_blood;
	int cb_act;
	int cb_blood;
};

struct _anon19
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
	_anon36 ply_pos;
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
	_anon1* et_lp[16][16][100];
	_anon1* ot_lp[1300];
	_anon1* it_lp[200];
	int eft_n;
	_anon1* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon15* p1per;
	_anon15* p2per;
	_anon15* kbper;
	_anon15* msper;
	_anon15 ms_per;
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
	_anon5* emtp[128];
	_anon5* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	_anon1* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon1* txblp[256];
	_anon10 txbp[256];
	unsigned char* ef_psp;
	_anon27 ef_tex[450];
	_anon1 ef_tlist;
	_anon42 ef;
	short efid[256];
	_anon14 efm[450];
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
	_anon24 ren_info;
	_anon27 ren_tex[1];
	_anon1 ren_tlist;
	_anon7 rpb[256];
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
	_anon43 mr_pl;
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
	_anon33 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon35 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon12* pl_htp;
	int costume;
	_anon36 hd_pos;
	_anon36 apos;
	_anon12* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon12 mwalp[64];
	_anon12 metcp[64];
	_anon12 mflrp[64];
	int dla_n;
	_anon12* htp;
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
	_anon1* sb_tlist;
	int ddmd;
	_anon21 door;
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
	_anon36 ufo_pos;
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
	_anon38 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon36 ghtp[32];
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

struct _anon20
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

struct _anon21
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

struct _anon22
{
	unsigned int flg;
	unsigned int atack_ct;
	unsigned int fend_ct;
	unsigned int at_cct;
	short ef_yct;
	short act_ct0;
	short act_ct1;
	short act_ct2;
	float r;
	float l;
	float rn;
	float rmax;
	_anon36 wp_fps1;
	_anon36 wp_fps2;
	_anon36 wp_cps;
	unsigned char ltp;
	unsigned char lr;
	unsigned char lg;
	unsigned char lb;
	unsigned short lnr;
	unsigned short lfr;
	float hrate;
	float ef_scale;
	short snd_wpno;
	short hiteff;
	unsigned short seno0;
	unsigned short seno1;
	char vib_tp;
	char vib_ct;
	char reserve1;
	char reserve2;
};

struct _anon23
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

struct _anon24
{
	void* texaddr;
	_anon9 texsurface;
};

struct _anon25
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

struct _anon26
{
	void* p[2];
};

struct _anon27
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon28
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon29
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon30
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon31
{
	float mtrx[16];
	_anon36 pnt;
	_anon36 vctr;
	int stat;
	int reserve;
	_anon39 ltcal;
	_anon45 attr;
};

struct _anon32
{
	int no;
	_anon41 atb[4];
};

struct _anon33
{
	_anon36 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon34
{
	int* vlist;
	short* plist;
	_anon36 center;
	float r;
};

struct _anon35
{
	float x;
	float y;
};

struct _anon36
{
	float x;
	float y;
	float z;
};

struct _anon37
{
	_anon36 off_pos;
	int srd_dir;
	float srd_pos;
	float bld_spd;
	float srt_spd[5];
	int srt_dir[5];
};

struct _anon38
{
	_anon36 c1;
	_anon36 c2;
	float r1;
	float r2;
};

struct _anon39
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
	_anon36 lpnt;
	_anon36 lvctr;
	_anon36 lmvctr;
	_anon30 atten;
	_anon30 amb;
	_anon30 dif;
	_anon30 spc;
	_anon30 mamb;
	_anon30 mdif;
	_anon30 mspc;
};

struct _anon40
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon41
{
	int frm;
	unsigned int act;
};

struct _anon42
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

struct _anon43
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon44
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

struct _anon45
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
	_anon30 argb;
};

struct _anon46
{
	int crit;
	int pt[3];
	int timeout;
	int bonus;
};

struct _anon47
{
	_anon36 c;
	float r;
};

struct _anon48
{
	_anon36 c1;
	_anon36 c2;
	float r;
};

struct _anon49
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

struct _anon50
{
	int flg;
	int correct;
};
*/
int En04_PlyMtn_OffsetTbl[4] =
{
    0x64,
    0x69,
    0x64,
    0x69
};
/*
_anon32 en04_mtn_tbl[30];
_anon32 en04_mtn_tbl2[6];
char en04_tree[8][1];
*/
char En04SdwTab[6] =
{
    0x05, 0x0F, 0x12, 0x08, 0x0B, 0xFF
};
/*
_anon18 En04_WpnDamageTbl[22];
*/
static COMBWEP_WORK CombWepTbl[21] =
{
    {0, {0, 0, 0}, 0, 0}, 
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0},
    {0, {0, 0, 0}, 0, 0}
};

static COMBJOINT_WORK CombJointTbl[19] =
{
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0}
};

CPCL Ene04CapColTab[17] =
{
    { 1,  2,  13 }, 
    { 2,  3,  13 }, 
    { 4,  4,  14 }, 
    { 0,  4,  -6 }, 
    { 5,  5,  12 }, 
    { 0,  2,  -8 }, 
    { 12, 12, 15 }, 
    { 0,  0,  10 }, 
    { 6,  7,   8 }, 
    { 7,  8,   4 },
    { 9,  10,  8 },
    { 10, 11,  4 },
    { 13, 14,  8 },
    { 14, 15,  4 },
    { 16, 17,  8 },
    { 17, 18,  4 },
    { 0,  0,   0 } 
};

BP_WORK en04_BldTbl =
{
    {0.0f, 0.1f, 0.0f},                     /* off_pos */
    0,                                      /* srd_dir */
    0.0f,                                   /* srd_pos */
    0.08f,                                  /* bld_spd */
    {0.8f, 0.6f, 0.0f, 0.8f, 0.9f},         /* srt_spd */
    {0, 4, 8, 12, 14}                       /* srt_dir */
};

/*
_anon8 en04prt_blood_tbl[19];
*/

const int en04_hp_tbl[2][16] =
{
    { 60, 60, 60, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 120, 120, 120 },
    { 30, 30, 30, 45, 45, 45, 45, 45, 60, 60, 60, 60, 60,  75,  75,  75 } 
};

char en04_flipTree[20] =
{
    0x00, 0x01, 0x02, 0x03, 0x04,
    0x05, 0x09, 0x0A, 0x0B, 0x06,
    0x07, 0x08, 0x0C, 0x10, 0x11,
    0x12, 0x0D, 0x0E, 0x0F, 0xFF
};

static int en04_contact_flg;
static int en04_atari_flg;

void (*bhEne04_Mode0[6])(BH_PWORK*) =
{
    bhEne04_Init,
    bhEne04_Move,
    bhEne04_Nage,
    bhEne04_Damage,
    bhEne04_Die,
    bhEne_Event
};

void (*bhEne04_MoveType[3])(BH_PWORK*) =
{
    bhEne04_MVType00,
    bhEne04_MVType01,
    bhEne04_MVType02
};

void (*bhEne04_NageType[3])(BH_PWORK*) =
{
    bhEne04_NGType00,
    bhEne04_NGType00,
    bhEne04_NGType00
};

void (*bhEne04_DamageType[3])(BH_PWORK*) =
{
    bhEne04_DGType00, 
    bhEne04_DGType00, 
    bhEne04_DGType00  
};

void (*bhEne04_DieType[3])(BH_PWORK*) = 
{
    bhEne04_DDType00,
    bhEne04_DDType00,
    bhEne04_DDType00
};

void (*bhEne04_BrainMode2[12])(BH_PWORK*) =
{
    bhEne04_Brain00,
    bhEne04_Brain01,
    bhEne04_Brain02,
    bhEne04_DmmyBrain,
    bhEne04_Brain04,
    bhEne04_DmmyBrain,
    bhEne04_Brain06,
    bhEne04_DmmyBrain,
    bhEne04_DmmyBrain,
    bhEne04_DmmyBrain,
    bhEne04_DmmyBrain,
    bhEne04_DmmyBrain
};

void (*bhEne04_MoveMode2[13])(BH_PWORK*) =
{
    bhEne04_MV00,  
    bhEne04_MV01,
    bhEne04_MV02,
    bhEne04_MV03, 
    bhEne04_MV04,
    bhEne04_MV05,
    bhEne04_MV06,
    bhEne04_MV07,
    bhEne04_MV08,
    bhEne04_MV09,
    bhEne04_MV10,
    bhEne04_MV11,
    bhEne04_MV12
};

void (*bhEne04_NageMode2[2])(BH_PWORK*) =
{
    bhEne04_NG00,
    bhEne04_NG01
};

void (*bhEne04_DamageMode2[3])(BH_PWORK*) =
{
    bhEne04_DG00, 
    bhEne04_DG01,
    bhEne04_DG00
};

void (*bhEne04_DieMode2[1])(BH_PWORK*) = 
{
    bhEne04_DD00
};

void (*bhEne04_PlyDmgMode[2])(BH_PWORK*, BH_PWORK*) = 
{
    bhEne04_PlyDG00, 
    bhEne04_PlyDG01  
};
/*
_anon11* rom;
_anon19* sys;
BH_PWORK* plp;
_anon22 WpnTab[0];
float lcmat[16][0];
BH_PWORK ene[0];
*/

/* extern */ int kaidan_ang[4]; // this belongs to en01?

/*
void(*bhEne04Sub_Mode0)(BH_PWORK*)[4];
*/


// 100% matching!
void bhEne04_DmmyBrain(void)
{

}

// 100% matching!
void bhEne04(BH_PWORK* epw) {
    int i;
    O_WRK* op;

    bhEne04_DmgChk(epw);
    bhEne04_MainLoop(epw);
    
    if (epw->flg & 0x4)
    {
        for (i = 0; i < 64; i++)
        {
            epw->dam[i] = 0;
        }
        
        epw->flg &= ~0x4;
    }
    
    bhEne04_CollisionCheck(epw);
    bhEne04_PlayerLink(plp, epw);
    bhCalcModel(epw);
    bhEne04_SetCollision(epw);
    
    for (i = 4, op = &sys->obwp[i]; i < (rom->obj_n - 1); i++, op++)
    {
        if ((op->flg & 0x1) && (op->id == 52) && (op->flg2 & 0x1))
        {
            bhEne04_ShakeWire(op);
        }
    }

    if (EXP0_I(0x14) > 0)
    {
        EXP0_I(0x14)--;
    }

    if (EXP0_I(0x18) > 0)
    {
        EXP0_I(0x18)--;
    }
}

// 100% matching!
void bhEne04_MainLoop(BH_PWORK* epw)
{
    bhEne04_Mode0[epw->mode0](epw); 
    
    bhEne04_PlayerControl(plp, epw);
    
    if (!(EXP0_I(0x10) & 0x40))
    {
        bhEne04_SetMtn(epw);
    }   
    if (epw->mode0 != 5)
    {        
        if (EXP0_I(0x10) & 0x80)
        {
            bhEne04_SearchNeck(epw);           
            return;
        }
        if (EXP0_I(0x1C) != 0)
        {
            if ((EXP0_I(0x1C) & 0xFFFF) < 32768)
            {
                EXP0_I(0x1C) -= 256;                
                if (EXP0_I(0x1C) < 0)
                {
                    EXP0_I(0x1C) = 0;
                }
            } 
            else
            {
                EXP0_I(0x1C) += 256;
                
                if (EXP0_I(0x1C) >= 0)
                {
                  EXP0_I(0x1C) = 0;  
                }
            }
            bhEne04_RotNeck(epw, 0, EXP0_I(0x1C), 0); // signature differs from DWARF
        }
    }
}

// 100% matching!
void bhEne04_SetCollision(BH_PWORK* epw)
{
	NJS_POINT3 pd;
	NJS_POINT3 ps;

    njGetTranslation(&epw->mlwP->owP[1].mtx, &epw->watr.c1);
    njGetTranslation(&epw->mlwP->owP[4].mtx, &epw->watr.c2);
    
    epw->watr.r = 2.0f;
    
    njUnitMatrix(NULL);
    
    njTranslate(NULL, epw->px, epw->py, epw->pz);
    njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
    
    pd.x = 0.0f;
    pd.y = 0.0f;
    pd.z = -3.0f;
    
    njCalcPoint(NULL, &pd, &ps);
    
    epw->aox = ps.x - epw->px;
    epw->aoz = ps.z - epw->pz;
}

// 100% matching!
void bhEne04_DmgChk(BH_PWORK* epw)
{
    if ((epw->flg & 4) && !(epw->flg & 2) && (bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl), (epw->total_dam != 0)))
{        
        if (!(EXP0_I(0x10) & 0x2000000) || 
            (epw->flr_no > plp->flr_no) || 
            ((WpnTab[epw->wpnr_no].flg & 0x20) != 0) || 
            (WpnTab[epw->wpnr_no].flg & 0x20000000) || 
            !(plp->at_flg & 2))
        {            
            bhEne04_DamageAdd(epw);
            if (epw->type != 0)
            {
                epw->type = 0;
            }
            if (epw->mode0 < 3)
            {
                epw->flg |= 0x40;
                if (epw->comb_flg & 4)
                {
                    EXP0_I(0x10) |= 0x100;
                }
                else
                {
                    EXP0_I(0x10) &= ~0x100;
                }
                bhEne04_ChgDmgMode(epw);
                if (EXP0_I(0x10) & 0x4000000)
                {
                    EXP0_I(0x10) &= ~0x40C0000;
                    *(unsigned int*)plp->exp1 |= 4;
                    sys->pad_on &= ~0xF;
                    plp->flg &= ~0x10000;
                    plp->flg |= 8;
                    plp->stflg &= ~0x50000;
                    plp->at_flg = 0;
                    plp->mnwP = plp->mnwPb;
                    if (plp->flg2 & 0x200)
                    {
                        plp->mode0 = 2;
                        plp->mode2 = 1;
                        plp->mode3 = 0;
                        if (bhDGCdirCheck((NJS_VECTOR*)&plp->dvx, plp->ay) == 0)
                        {
                            plp->mode1 = 0;
                        }
                        else
                        {
                            plp->mode1 = 1;
                        }
                        plp->flg |= 4;
                        return;
                    }
                    *(int*)&plp->mode0 = 1;
                    plp->flg &= ~4;
                }
            }
        }
    }
}


// 
// Start address: 0x1a5510
void bhEne04_ChgDmgMode(BH_PWORK* epw)
{
	int act;
	//_anon18* wp_tbl;
	// Line 865, Address: 0x1a5510, Func Offset: 0
	// Line 869, Address: 0x1a551c, Func Offset: 0xc
	// Line 866, Address: 0x1a5524, Func Offset: 0x14
	// Line 875, Address: 0x1a552c, Func Offset: 0x1c
	// Line 869, Address: 0x1a5534, Func Offset: 0x24
	// Line 875, Address: 0x1a5544, Func Offset: 0x34
	// Line 878, Address: 0x1a5560, Func Offset: 0x50
	// Line 879, Address: 0x1a556c, Func Offset: 0x5c
	// Line 880, Address: 0x1a5570, Func Offset: 0x60
	// Line 883, Address: 0x1a5574, Func Offset: 0x64
	// Line 886, Address: 0x1a5584, Func Offset: 0x74
	// Line 889, Address: 0x1a559c, Func Offset: 0x8c
	// Line 888, Address: 0x1a55a0, Func Offset: 0x90
	// Line 889, Address: 0x1a55a4, Func Offset: 0x94
	// Line 890, Address: 0x1a55a8, Func Offset: 0x98
	// Line 892, Address: 0x1a55ac, Func Offset: 0x9c
	// Line 891, Address: 0x1a55b0, Func Offset: 0xa0
	// Line 893, Address: 0x1a55b4, Func Offset: 0xa4
	// Line 892, Address: 0x1a55bc, Func Offset: 0xac
	// Line 893, Address: 0x1a55c0, Func Offset: 0xb0
	// Line 894, Address: 0x1a55cc, Func Offset: 0xbc
	// Line 895, Address: 0x1a55e0, Func Offset: 0xd0
	// Line 899, Address: 0x1a55e8, Func Offset: 0xd8
	// Line 904, Address: 0x1a55f0, Func Offset: 0xe0
	// Line 909, Address: 0x1a55fc, Func Offset: 0xec
	// Line 910, Address: 0x1a5604, Func Offset: 0xf4
	// Line 911, Address: 0x1a5608, Func Offset: 0xf8
	// Line 912, Address: 0x1a560c, Func Offset: 0xfc
	// Line 915, Address: 0x1a5610, Func Offset: 0x100
	// Line 917, Address: 0x1a5628, Func Offset: 0x118
	// Line 920, Address: 0x1a5630, Func Offset: 0x120
	// Func End, Address: 0x1a5640, Func Offset: 0x130
    scePrintf("bhEne04_ChgDmgMode - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1a5640
void bhEne04_DamageAdd(BH_PWORK* epw)
{
	//_anon4* owk;
	int i;
	int* d;
	//_anon36 ofp;
	//_anon18* wp_tbl;
	// Line 938, Address: 0x1a5640, Func Offset: 0
	// Line 939, Address: 0x1a5658, Func Offset: 0x18
	// Line 940, Address: 0x1a5660, Func Offset: 0x20
	// Line 946, Address: 0x1a567c, Func Offset: 0x3c
	// Line 948, Address: 0x1a5688, Func Offset: 0x48
	// Line 949, Address: 0x1a5694, Func Offset: 0x54
	// Line 952, Address: 0x1a5698, Func Offset: 0x58
	// Line 949, Address: 0x1a569c, Func Offset: 0x5c
	// Line 952, Address: 0x1a56a8, Func Offset: 0x68
	// Line 953, Address: 0x1a56b0, Func Offset: 0x70
	// Line 955, Address: 0x1a56c4, Func Offset: 0x84
	// Line 957, Address: 0x1a56d0, Func Offset: 0x90
	// Line 958, Address: 0x1a56d4, Func Offset: 0x94
	// Line 960, Address: 0x1a56dc, Func Offset: 0x9c
	// Line 962, Address: 0x1a56e8, Func Offset: 0xa8
	// Line 964, Address: 0x1a56ec, Func Offset: 0xac
	// Line 966, Address: 0x1a56fc, Func Offset: 0xbc
	// Line 969, Address: 0x1a5718, Func Offset: 0xd8
	// Line 970, Address: 0x1a572c, Func Offset: 0xec
	// Line 974, Address: 0x1a5734, Func Offset: 0xf4
	// Line 978, Address: 0x1a5748, Func Offset: 0x108
	// Line 981, Address: 0x1a5764, Func Offset: 0x124
	// Line 985, Address: 0x1a5790, Func Offset: 0x150
	// Line 989, Address: 0x1a5798, Func Offset: 0x158
	// Line 985, Address: 0x1a57a0, Func Offset: 0x160
	// Line 986, Address: 0x1a57b0, Func Offset: 0x170
	// Line 989, Address: 0x1a57b4, Func Offset: 0x174
	// Line 986, Address: 0x1a57c0, Func Offset: 0x180
	// Line 987, Address: 0x1a57c4, Func Offset: 0x184
	// Line 988, Address: 0x1a57cc, Func Offset: 0x18c
	// Line 989, Address: 0x1a57d0, Func Offset: 0x190
	// Line 994, Address: 0x1a57d8, Func Offset: 0x198
	// Line 997, Address: 0x1a57f4, Func Offset: 0x1b4
	// Line 999, Address: 0x1a5808, Func Offset: 0x1c8
	// Line 1000, Address: 0x1a5810, Func Offset: 0x1d0
	// Line 1002, Address: 0x1a5820, Func Offset: 0x1e0
	// Line 1003, Address: 0x1a5838, Func Offset: 0x1f8
	// Line 1005, Address: 0x1a5844, Func Offset: 0x204
	// Line 1006, Address: 0x1a5850, Func Offset: 0x210
	// Line 1008, Address: 0x1a5864, Func Offset: 0x224
	// Line 1011, Address: 0x1a586c, Func Offset: 0x22c
	// Line 1017, Address: 0x1a5884, Func Offset: 0x244
	// Line 1019, Address: 0x1a5894, Func Offset: 0x254
	// Line 1021, Address: 0x1a58a8, Func Offset: 0x268
	// Line 1022, Address: 0x1a58b0, Func Offset: 0x270
	// Line 1025, Address: 0x1a58c4, Func Offset: 0x284
	// Func End, Address: 0x1a58e0, Func Offset: 0x2a0
    scePrintf("bhEne04_DamageAdd - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne04_PlayerControl(BH_PWORK* pl, BH_PWORK* epw)
{
    if ((EXP0_I(0x10) & 0x40000) && (pl->mode0 == 4 || pl->mode0 == 6))
    {
        bhEne04_PlyDmgMode[pl->mode1](pl, epw);
    }
}

// 100% matching!
void bhEne04_PlayerLink(BH_PWORK* pl, BH_PWORK* epw)
{
    NJS_POINT3 pd;

    if (EXP0_I(0x10) & 0x80000)
    {
        njUnitMatrix(NULL);
        njTranslate(NULL, epw->px, epw->py, epw->pz);
        njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
        njCalcPoint(NULL, (NJS_POINT3*) &EXP0_UC(0x30), &pd);
        pl->px = pd.x;
        pl->pz = pd.z;
        pl->ay = (epw->ay + epw->waxp) & 0xFFFF;
    }
}

// 100% matching!
void bhEne04_CollisionCheck(BH_PWORK* epw) {
    if (!(epw->flg & 2))
    {
        if ((EXP0_I(0x10) & 0x20) && (plp->hp >= 0))
        {
            bhCheckPlayer(epw);
        }
        bhCheckEnemies(epw);
    }
    bhEne04_CollCheckWall(epw);
}

// 
// Start address: 0x1a5a70
void bhEne04_CollCheckWall(BH_PWORK* epw)
{
	char ply_tree[7];
	//_anon4* owk;
	//_anon36 pd;
	//_anon36 ops;
	//_anon36 ps;
	//_anon12* hp;
	// Line 1196, Address: 0x1a5a70, Func Offset: 0
	// Line 1204, Address: 0x1a5a8c, Func Offset: 0x1c
	// Line 1206, Address: 0x1a5ab0, Func Offset: 0x40
	// Line 1209, Address: 0x1a5ab8, Func Offset: 0x48
	// Line 1210, Address: 0x1a5abc, Func Offset: 0x4c
	// Line 1206, Address: 0x1a5ac0, Func Offset: 0x50
	// Line 1209, Address: 0x1a5ac8, Func Offset: 0x58
	// Line 1212, Address: 0x1a5acc, Func Offset: 0x5c
	// Line 1209, Address: 0x1a5ad4, Func Offset: 0x64
	// Line 1210, Address: 0x1a5adc, Func Offset: 0x6c
	// Line 1211, Address: 0x1a5ae4, Func Offset: 0x74
	// Line 1212, Address: 0x1a5ae8, Func Offset: 0x78
	// Line 1215, Address: 0x1a5af8, Func Offset: 0x88
	// Line 1216, Address: 0x1a5b0c, Func Offset: 0x9c
	// Line 1219, Address: 0x1a5b2c, Func Offset: 0xbc
	// Line 1223, Address: 0x1a5b3c, Func Offset: 0xcc
	// Line 1230, Address: 0x1a5b54, Func Offset: 0xe4
	// Line 1232, Address: 0x1a5b6c, Func Offset: 0xfc
	// Line 1233, Address: 0x1a5b90, Func Offset: 0x120
	// Line 1240, Address: 0x1a5b94, Func Offset: 0x124
	// Line 1233, Address: 0x1a5ba4, Func Offset: 0x134
	// Line 1235, Address: 0x1a5ba8, Func Offset: 0x138
	// Line 1240, Address: 0x1a5bac, Func Offset: 0x13c
	// Line 1235, Address: 0x1a5bb0, Func Offset: 0x140
	// Line 1236, Address: 0x1a5bb4, Func Offset: 0x144
	// Line 1237, Address: 0x1a5bbc, Func Offset: 0x14c
	// Line 1238, Address: 0x1a5bc4, Func Offset: 0x154
	// Line 1240, Address: 0x1a5bcc, Func Offset: 0x15c
	// Line 1242, Address: 0x1a5be0, Func Offset: 0x170
	// Line 1244, Address: 0x1a5be8, Func Offset: 0x178
	// Line 1245, Address: 0x1a5bf8, Func Offset: 0x188
	// Line 1246, Address: 0x1a5c08, Func Offset: 0x198
	// Line 1247, Address: 0x1a5c14, Func Offset: 0x1a4
	// Line 1248, Address: 0x1a5c1c, Func Offset: 0x1ac
	// Line 1250, Address: 0x1a5c28, Func Offset: 0x1b8
	// Line 1256, Address: 0x1a5c40, Func Offset: 0x1d0
	// Line 1258, Address: 0x1a5c44, Func Offset: 0x1d4
	// Line 1250, Address: 0x1a5c48, Func Offset: 0x1d8
	// Line 1256, Address: 0x1a5c54, Func Offset: 0x1e4
	// Line 1260, Address: 0x1a5c58, Func Offset: 0x1e8
	// Line 1259, Address: 0x1a5c60, Func Offset: 0x1f0
	// Line 1256, Address: 0x1a5c64, Func Offset: 0x1f4
	// Line 1260, Address: 0x1a5c68, Func Offset: 0x1f8
	// Line 1256, Address: 0x1a5c70, Func Offset: 0x200
	// Line 1257, Address: 0x1a5c74, Func Offset: 0x204
	// Line 1258, Address: 0x1a5c7c, Func Offset: 0x20c
	// Line 1259, Address: 0x1a5c84, Func Offset: 0x214
	// Line 1260, Address: 0x1a5c88, Func Offset: 0x218
	// Line 1261, Address: 0x1a5c90, Func Offset: 0x220
	// Line 1262, Address: 0x1a5c98, Func Offset: 0x228
	// Line 1261, Address: 0x1a5ca0, Func Offset: 0x230
	// Line 1262, Address: 0x1a5ca8, Func Offset: 0x238
	// Line 1263, Address: 0x1a5cb8, Func Offset: 0x248
	// Line 1271, Address: 0x1a5cc0, Func Offset: 0x250
	// Line 1264, Address: 0x1a5cc4, Func Offset: 0x254
	// Line 1267, Address: 0x1a5cc8, Func Offset: 0x258
	// Line 1271, Address: 0x1a5ccc, Func Offset: 0x25c
	// Line 1263, Address: 0x1a5cd0, Func Offset: 0x260
	// Line 1271, Address: 0x1a5cd4, Func Offset: 0x264
	// Line 1263, Address: 0x1a5cdc, Func Offset: 0x26c
	// Line 1264, Address: 0x1a5ce0, Func Offset: 0x270
	// Line 1271, Address: 0x1a5ce8, Func Offset: 0x278
	// Line 1264, Address: 0x1a5cf0, Func Offset: 0x280
	// Line 1267, Address: 0x1a5cf8, Func Offset: 0x288
	// Line 1268, Address: 0x1a5d04, Func Offset: 0x294
	// Line 1269, Address: 0x1a5d0c, Func Offset: 0x29c
	// Line 1270, Address: 0x1a5d14, Func Offset: 0x2a4
	// Line 1271, Address: 0x1a5d18, Func Offset: 0x2a8
	// Line 1272, Address: 0x1a5d20, Func Offset: 0x2b0
	// Line 1273, Address: 0x1a5d28, Func Offset: 0x2b8
	// Line 1272, Address: 0x1a5d30, Func Offset: 0x2c0
	// Line 1273, Address: 0x1a5d38, Func Offset: 0x2c8
	// Line 1274, Address: 0x1a5d48, Func Offset: 0x2d8
	// Line 1275, Address: 0x1a5d58, Func Offset: 0x2e8
	// Line 1278, Address: 0x1a5d68, Func Offset: 0x2f8
	// Func End, Address: 0x1a5d88, Func Offset: 0x318
    scePrintf("bhEne04_CollCheckWall - UNIMPLEMENTED!\n");
}

// 99.90% matching
void bhEne04_Init(BH_PWORK* epw)
{
    int i;
    u_char* addr;
    int size;

    en04_contact_flg = 0;
    en04_atari_flg = 0;
    epw->ar = 3.0f;
    epw->ah = 4.0f;
    epw->aw = 0.0f;
    epw->ad = 0.0f;
    epw->car = 3.5f;
    epw->cah = 4.0f;
    epw->stflg = 0;
    if (sys->gm_mode != 2)
    {
        epw->hp = en04_hp_tbl[0][rand() % 16];
    }
    else
    {
        epw->hp = en04_hp_tbl[1][rand() % 16];
    }

    for (i = 0; i < 64; i++)
    {
        epw->dam[i] = 0;
    }
    
    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    epw->mtn_no = 0;
    epw->mtn_add = 0;
    epw->frm_no = 0;
    epw->mtn_tp = (unsigned char*) en04_flipTree;
    epw->mtn_md = 0;

    if (epw->exp0 == NULL)
    {
        epw->exp0 = bhEne_CallocWork(88, 8);
    }
    else
    {
        size = 88;
        addr = epw->exp0;
        while (size--)
        {
            *addr++ = 0;
        }
    }

    EXP0_I(0x10) |= 0x21;
    epw->flg |= 0x178;
    epw->flg &= ~2;
    epw->cpcl = Ene04CapColTab;
    if (!(epw->flg & 0x800))
    {
        bhSetShadow(En04SdwTab, (unsigned char*)epw, 1, 3.0f, 3.0f, 6.0f);
        epw->flg |= 0x800;
    }
    epw->mdflg &= ~0x400;

    npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, 0xFFB2B2B2);
    
    epw->clp_jno[0] = 4;
    epw->clp_jno[1] = 5;
    epw->clp_jno[2] = 6;
    epw->clp_jno[3] = 9;
    epw->clp_jno[4] = 15;
    epw->clp_jno[5] = 15;
    epw->clp_jno[6] = -1;
    epw->clp_jno[7] = 0;
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
    
    epw->lok_jno = 4;
}
// 100% matching!
void bhEne04_Move(BH_PWORK* epw) 
{
    EXP0_I(0x10) &= ~0x80;    
    bhEne04_MoveType[epw->type](epw);
}

// 100% matching!
void bhEne04_Nage(BH_PWORK* epw)
{
    EXP0_I(0x10) &= ~0x80;
    bhEne04_NageType[epw->type](epw);
}

// 100% matching!
void bhEne04_Damage(BH_PWORK* epw)
{
    EXP0_I(0x10) &= ~0x80;
    bhEne04_DamageType[epw->type](epw);
}

// 100% matching!
void bhEne04_Die(BH_PWORK* epw)
{
    EXP0_I(0x10) &= ~0x80;
    bhEne04_DieType[epw->type](epw);
}

// 100% matching!
void bhEne04_MVType00(BH_PWORK* epw)
{
    int ang_tbl[4] =
    {
        0,          // 0°
        49152,      // 270°
        32768,      // 180°
        16384       // 90°
    };

	O_WORK* owk;
	NJS_POINT3 pos;    
	ATR_WORK* hp;

    owk = plp->mlwP->owP;
    pos.x = owk[1].mtx[12];
    pos.y = epw->py;
    pos.z = owk[1].mtx[14];
    
    EXP0_F(0x20) = njDistanceP2P(&pos, (NJS_POINT3*)&epw->px);
    
    if (bhEne_EnemyAtariCheck((NJS_POINT3*)&plp->px, plp->flr_no, epw->id, 0) != NULL)
    {
        EXP0_I(0x10) |= 0x200000;
    }
    else
    {
        EXP0_I(0x10) &= ~0x200000;
    }
    
    if (epw->mode1 == 1)
    {
        bhEne04_Brain(epw);
    }
    
    if (epw->mode0 == 1)
    {
        pos.x = epw->px - (6.0f * njSin(epw->ay));
        pos.z = epw->pz - (6.0f * njCos(epw->ay));
        pos.y = 0.0f;
        if (bhEne_EnemyAtariCheck(&pos, epw->flr_no, epw->id, 5) != NULL)
        {
            EXP0_I(0x10) |= 0x8000;
        } 
        else
        {
            EXP0_I(0x10) &= ~0x8000;
        }

        if ((epw->mode2 == 2) || (epw->mode2 == 3))
        {
            hp = bhEne_EnemyAtariCheck(&pos, epw->flr_no, epw->id, 4);
            if ((hp != NULL) && (hp->prm1 == 4))
            {
                if (sys->obwp[hp->prm2].mode1 == 0)
                {
                    sys->obwp[hp->prm2].ayp = ang_tbl[hp->prm3];
                    sys->obwp[hp->prm2].mode3 = 0;
                    sys->obwp[hp->prm2].flg2 |= 1;

                    bhEne04_SePlay(epw, 70415);
                }
            }
        }
        bhEne04_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne04_MVType01(BH_PWORK* epw)
{
    O_WORK* owk;
    NJS_POINT3 pos;
    ATR_WORK* hp;
	unsigned char no;
    
    owk = &plp->mlwP->owP[1];   
    pos.x = owk->mtx[12];
    pos.y = epw->py;
    pos.z = owk->mtx[14];
    
    EXP0_F(0x20) = njDistanceP2P(&pos, (NJS_POINT3*)&epw->px);
    
    hp = bhEne_EnemyAtariCheck((NJS_POINT3*)&plp->px, plp->flr_no, epw->id, 1);    
    if (hp != NULL)
    {
        no = hp->prm3;
        hp = bhEne_EnemyAtariCheck((NJS_POINT3*) &epw->px, epw->flr_no, epw->id, 2);
        if ((hp != NULL) && (hp->prm3 == no))
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->type = 0;
        }
    }
    
    if (epw->mode0 == 1)
    {
        bhEne04_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
void bhEne04_MVType02(BH_PWORK* epw)
{
    O_WORK* owk;
    NJS_POINT3 pos;

    owk = &plp->mlwP->owP[1];   
    pos.x = owk->mtx[12];
    pos.y = epw->py;
    pos.z = owk->mtx[14];
    
    EXP0_F(0x20) = njDistanceP2P(&pos, (NJS_POINT3*)&epw->px);
    
    if (en04_contact_flg & 1)
    {
        bhEne04_AtariCheck2(epw);
        epw->mode1 = 1;
        epw->mode2 = 2;
        epw->mode3 = 0;
        epw->type = 0;
    }
    else if (bhEne04_AtariCheck(epw) != 0)
    {
        epw->mode1 = 1;
        epw->mode2 = 2;
        epw->mode3 = 0;
        epw->type = 0;
    }
    
    if (epw->mode0 == 1)
    {
        bhEne04_MoveMode2[epw->mode2](epw);
    }
}

// 100% matching!
int bhEne04_AtariCheck(BH_PWORK* epw)
{
    ATR_WORK* hp; 
    ATR_WORK* hp2;   
    ATR_WORK* fp;
    int flr_n;
    int atr_num;
    int i;
   
    hp = bhEne_EnemyAtariCheck((NJS_POINT3*)&plp->px, plp->flr_no, epw->id, 6);
    if (hp == NULL)
    {
        return 0;
    }

    if (32 < hp->prm3)
    {
        return 0;
    }

    if (en04_atari_flg & (1 << hp->prm3))
    {
        return 0;
    }
    
    en04_atari_flg |= (1 << hp->prm3);

    atr_num = 0;
    flr_n = rom->flr_n + sys->mflr_n;

    for (i = 0; i < flr_n; i++)
    {
        if (i < rom->flr_n)
        {
            fp = &rom->flrp[i];
        } 
        else
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if ((fp->flg & 1) && 
            fp->type == 2 && 
            fp != hp && 
            fp->flr_no == epw->flr_no && 
            fp->prm0 == epw->id && 
            fp->prm1 == 6 && 
            !(en04_atari_flg & (1 << fp->prm3))) 
        { 
            atr_num++; 
        }
    }
    
    if ((atr_num == 0) || ((rand() % 2) == 0))
    {
        hp2 = bhEne04_EnemyAtariCheck2(epw, 7, hp->prm3);
        if (hp2 != NULL)
        {
            epw->px = hp2->px + (hp2->w / 2.0f);
            epw->pz = hp2->pz + (hp2->d / 2.0f);
            
            epw->ay = kaidan_ang[hp2->prm2];
            
            sys->rm_flg |= 1 << (hp2->prm3 + 16);
            
            en04_contact_flg |= 1;
            
            return 1;
        }
    }
    return 0;
}


// 
// Start address: 0x1a6830
int bhEne04_AtariCheck2(BH_PWORK* epw)
{
	int i;
	int atr_num;
	int flr_n;
	ATR_WORK* work[32];
	ATR_WORK* fp;
	ATR_WORK* hp2;
	ATR_WORK* hp;
	// Line 1957, Address: 0x1a6830, Func Offset: 0
	// Line 1965, Address: 0x1a6840, Func Offset: 0x10
	// Line 1967, Address: 0x1a6860, Func Offset: 0x30
	// Line 1970, Address: 0x1a6870, Func Offset: 0x40
	// Line 1974, Address: 0x1a6888, Func Offset: 0x58
	// Line 1973, Address: 0x1a6890, Func Offset: 0x60
	// Line 1974, Address: 0x1a6894, Func Offset: 0x64
	// Line 1975, Address: 0x1a68b0, Func Offset: 0x80
	// Line 1979, Address: 0x1a68c4, Func Offset: 0x94
	// Line 1978, Address: 0x1a68cc, Func Offset: 0x9c
	// Line 1979, Address: 0x1a6908, Func Offset: 0xd8
	// Line 1986, Address: 0x1a6958, Func Offset: 0x128
	// Line 1987, Address: 0x1a6960, Func Offset: 0x130
	// Line 1988, Address: 0x1a6964, Func Offset: 0x134
	// Line 1989, Address: 0x1a6968, Func Offset: 0x138
	// Line 1991, Address: 0x1a6978, Func Offset: 0x148
	// Line 1993, Address: 0x1a6980, Func Offset: 0x150
	// Line 1996, Address: 0x1a698c, Func Offset: 0x15c
	// Line 1999, Address: 0x1a6994, Func Offset: 0x164
	// Line 2003, Address: 0x1a69bc, Func Offset: 0x18c
	// Line 2005, Address: 0x1a69d0, Func Offset: 0x1a0
	// Line 2008, Address: 0x1a69d8, Func Offset: 0x1a8
	// Line 2010, Address: 0x1a69e8, Func Offset: 0x1b8
	// Line 2008, Address: 0x1a69f0, Func Offset: 0x1c0
	// Line 2009, Address: 0x1a69fc, Func Offset: 0x1cc
	// Line 2010, Address: 0x1a6a10, Func Offset: 0x1e0
	// Line 2013, Address: 0x1a6a20, Func Offset: 0x1f0
	// Line 2016, Address: 0x1a6a44, Func Offset: 0x214
	// Line 2018, Address: 0x1a6a68, Func Offset: 0x238
	// Line 2022, Address: 0x1a6a74, Func Offset: 0x244
	// Line 2023, Address: 0x1a6a78, Func Offset: 0x248
	// Func End, Address: 0x1a6a8c, Func Offset: 0x25c
    scePrintf("bhEne04_AtariCheck2 - UNIMPLEMENTED!\n");
}

// 100% matching! 
ATR_WORK* bhEne04_EnemyAtariCheck2(BH_PWORK* epw, unsigned char type, unsigned char ip)
{
    ATR_WORK* fp;
    int i;
    int flr_n;

    flr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < flr_n; i++)
    {
        if (i < rom->flr_n)
        {
            fp = &rom->flrp[i];
        }
        else
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if ((fp->flg & 1) && 
            (fp->type == 2) && 
            (fp->flr_no == epw->flr_no) && 
            (fp->prm0 == epw->id) && 
            (fp->prm1 == type) && 
            (fp->prm3 == ip))
        {            
            return fp;
        }
    }

    return NULL;
}

// 100% matching! 
void bhEne04_EneSearch(BH_PWORK* epw)
{
    EXP0_UC(0) |= 0x80;

    if ((EXP0_UC(0) & 0x1F) < 4)
    {
        if (bhSearchPlayer(epw, 18204) != -1)
        {
            if ((unsigned char*)EXP0_I(0x44) == NULL)
            {
                EXP0_UC(0) |= 0x20;
            }
            else
            {
                if (*(unsigned char*)(EXP0_I(0x44) + 1) == 1 || 
                    *(unsigned char*)(EXP0_I(0x44) + 1) == 3 || 
                    *(unsigned char*)(EXP0_I(0x44) + 1) == 5) 
                {
                    EXP0_UC(0) |= 0x20;
                }
            }
        }

        if ((EXP0_UC(0) & 0x1F) == 3)
        {
            if (EXP0_UC(0) & 0x20)
            {
                EXP0_UC(0) |= 0x40;
            }
            else
            {
                EXP0_UC(0) &= ~0x40;
            }
            EXP0_UC(0) &= 0x5F;
        }
    }

    EXP0_UC(0)++;

    if (15 < (EXP0_UC(0) & 0x1F))
    {
        EXP0_UC(0) &= 0xE0;
    }
}

// 100% matching!
void bhEne04_Brain(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    bhEne04_EneSearch(epw);

    if (!(EXP0_UC(0) & 0x80))
    {
        if (EXP0_UC(0) & 0x40)
        {
            if ((EXP0_F(0x20) < 50.0f) && (EXP0_I(0x44) == 0) && (epw->flr_no == plp->flr_no))
            {
                EXP0_F(0x24) = plp->px;
                EXP0_F(0x2C) = plp->pz;
            }
            else
            {
                bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, &pos);
                EXP0_F(0x24) = pos.x;
                EXP0_F(0x2C) = pos.z;
            }
        }
        else
        {
            bhCheckRoute((NJS_POINT3*)&epw->px,(NJS_POINT3*) &plp->px, &pos);
            EXP0_F(0x24) = pos.x;
            EXP0_F(0x2C) = pos.z;
        }
    }
    bhEne04_BrainMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne04_Brain00(BH_PWORK* epw)
{
    if (((ikou3(epw, (NJS_POINT3*)&plp->px, 12288) == 0) && (EXP0_F(0x20) < 35.0f)) ||
        ((plp->mode1 == 1) && (plp->mode2 == 69)) ||
        ((plp->mode2 == 6) && (EXP0_F(0x20) < 40.0f)))
    {
        EXP0_I(0x10) |= 0x400000;
    }
}

// 100% matching!
void bhEne04_Brain01(BH_PWORK* epw)
{
    if (((ikou3(epw, (NJS_POINT3*)&plp->px, 8192) == 0) && (EXP0_F(0x20) < 20.0f)) ||
        ((plp->mode1 == 1) && (plp->mode2 == 69)) ||
        ((plp->mode2 == 6) && (EXP0_F(0x20) < 40.0f)) ||
        (EXP0_I(0x10) & 0x8000)) 
    {
        epw->mode1 = 1;
        epw->mode2 = 2;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne04_Brain02(BH_PWORK* epw) {
    NJS_POINT3 pos;
    NJS_POINT3 pos2;
    int back_flg;

    if (EXP0_F(0x20) < 20.0f && !(EXP0_I(0x10) & 0x8000) && !(plp->flg & 0x4) && (epw->flr_no == plp->flr_no))
    {        
        if (EXP0_F(0x20) > 11.0f)
        {            
            if (!ikou3(epw, (NJS_POINT3*)&plp->px, 1024))
            {
                back_flg = bhCdirCheck(epw->ay, plp->ay);
                
                if (back_flg == 0 || (back_flg == 1 && plp->mode2 != 6))
                { 
                    pos.x = epw->px;
                    pos.y = epw->py;
                    pos.z = epw->pz;
                    pos2.x = plp->px;
                    pos2.y = plp->py;
                    pos2.z = plp->pz;
                    
                    if (!bhCollisionCheckLine(&pos, &pos2))
                    {
                        epw->mode1 = 0;
                        epw->mode2 = 7;
                        epw->mode3 = 0;
                    }
                }
            }
        } 
        else
        {
            if (!ikou3(epw, (NJS_POINT3*)&plp->px, 2048))
            {
                back_flg = bhCdirCheck(epw->ay, plp->ay);
                
                if (!(EXP0_I(0x10) & 0x200000) && !(plp->flg & 0x6) && !(plp->stflg & 0x80000000) && back_flg == 0)
                {
                    epw->mode0 = 2;
                    epw->mode1 = 0;
                    epw->mode2 = 0;
                    epw->mode3 = 0;
                    plp->flg |= 0x4;
                    plp->flg |= 0x10000;
                    EXP0_I(0x10) |= 0x4000000; 
                    return;
                }
                
                epw->mode1 = 0;
                epw->mode2 = 9;
                epw->mode3 = 0;
            }
        }

        if (!ikou3(epw, (NJS_POINT3*)&plp->px, 16384))
        {
            EXP0_I(0x10) |= 0x2000;
        }
        else
        {
            if (EXP0_I(0x10) & 0x2000)
            {
                if (56 < (rand() % 64))
                {
                    EXP0_I(0x10) &= ~0x2000; 
                    EXP0_I(0x10) |= 0x1800;
                }
            }
        }
    }

    if (EXP0_F(0x20) >= 8.0f && EXP0_F(0x20) <= 15.0f && (plp->flg & 0x4))
    {
        if (!ikou3(epw, (NJS_POINT3*)&plp->px, 4096))
        {
            epw->mode1 = 0;
            epw->mode2 = 4;
            epw->mode3 = 0;
        }
    }

    if (bhEne04_KaidanCheck(epw))
    {
        EXP0_I(0x10) |= 0x20000;
        epw->mode1 = 0;
        epw->mode2 = 11;
        epw->mode3 = 0;
        EXP0_F(0x30) = epw->px;
        EXP0_F(0x34) = epw->py;
        EXP0_F(0x38) = epw->pz;
    }
}

// 100% matching!
void bhEne04_Brain04(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	NJS_POINT3 pos2;

    if (plp->hp < 0)
    {
        epw->mode1 = 0;
        epw->mode2 = 12;
        epw->mode3 = 0;
        EXP0_I(0x10) &= ~0x2000000;
        return;
    }
    
    if ((EXP0_F(0x20) < 20.0f) && !(EXP0_I(0x10) & 0x8000) && !(plp->flg & 4) && (epw->flr_no == plp->flr_no))
    {
        if (!(EXP0_F(0x20) <= 11.0f))
        {
            if (ikou3(epw, (NJS_POINT3*)&plp->px, 1024) == 0)
            {
                pos.x = epw->px;
                pos.y = epw->py;
                pos.z = epw->pz;
                
                pos2.x = plp->px;
                pos2.y = plp->py;
                pos2.z = plp->pz;
                
                if (bhCollisionCheckLine(&pos, &pos2) == NULL)
                {
                    epw->mode1 = 0;
                    epw->mode2 = 7;
                    epw->mode3 = 0;
                    EXP0_I(0x10) &= ~0x2000000;
                }
            }
        }
        else if (ikou3(epw, (NJS_POINT3*)&plp->px, 2048) == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 9;
            epw->mode3 = 0;
            EXP0_I(0x10) &= ~0x2000000;
        }
    }
}

// 100% matching!
void bhEne04_Brain06(BH_PWORK* epw)
{
    if (EXP0_F(0x20) < 11.0f)
    {
        epw->ct1++;
        if ((plp->spd >= 0.9f))
        {
            epw->ct1 += 20;
        }
        if ((ikou3(epw, (NJS_POINT3*)&plp->px, 2048) == 0) && !(plp->flg & 4) && (epw->flr_no == plp->flr_no) && !(EXP0_F(0x20) <= 8.0f))
        {
            epw->mode1 = 0;
            epw->mode2 = 7;
            epw->mode3 = 0;
            en04_contact_flg |= 2;
        }
    }
    else
    {
        epw->ct1 -= epw->ct2 > 0;
        if ((ikou3(epw, (NJS_POINT3*)&plp->px, 2048) == 0) && (plp->spd >= 0.9f))
        {
            epw->ct1 += 6;
        }
    }
    
    if ((epw->ct1 >= 65) || ((plp->mode1 == 1) && (plp->mode2 == 69)) || (en04_contact_flg & 2) || (EXP0_I(0x10) & 0x8000))
    {
        epw->mode1 = 1;
        epw->mode2 = 2;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne04_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->type == 0)
        {
            bhEne04_ChgMtn(epw, 47, 0, 7);
        }
        else
        {
            bhEne04_ChgMtn(epw, 49, 0, 7);
        }
        epw->ct0 = (rand() % 128) + 100;
        epw->mode1 = 1;
        epw->mode3++;

    case 1:
        EXP0_I(0x10) |= 0x80;
        EXP0_I(0x1C) = 4096;
        epw->ct0--;
        if (((epw->ct0 <= 0) || (EXP0_I(0x10) & 0x400000)) && (epw->type == 0))
        {
            bhEne04_ChgMtn(epw, 48, 0, 10);
            if (!(EXP0_I(0x10) & 0x400000))
            {
                EXP0_I(0x10) &= ~0x80;
                EXP0_I(0x1C) = 0;
            }
            epw->mode3++;
        }
        break;
        
    case 2:
        if (EXP0_I(0x10) & 0x400000)
        {
            EXP0_I(0x10) |= 0x80;
        }
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1)) 
        {
            if (EXP0_I(0x10) & 0x400000)
            {
                epw->mode1 = 1;
                epw->mode2 = 2;
                epw->mode3 = 0;
            }
            else 
            {
                epw->mode1 = 1;
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
        }
    }
}

// 100% matching!
void bhEne04_MV01(BH_PWORK* epw)
{
    int hit;

    if ((EXP0_UC(0x0) & 0x40) && (EXP0_F(0x20) < 35.0f))
    {
        EXP0_I(0x10) |= 0x80;
    }
    
    switch (epw->mode3)
    {
    case 0:
        bhEne04_ChgMtn(epw, 0, 0, 7);
        
        epw->way = 256;
        epw->ct0 = (rand() % 32) + 75;
        epw->ct2 = 0;

        EXP0_F(0x24) = plp->px; 
        EXP0_F(0x2C) = plp->pz; 

        epw->mode3++; 

    case 1:
        epw->spd = 0.15f;

        if ((EXP0_UC(0x0) & 0x40) && (EXP0_F(0x20) < 35.0f))
        {
            ikou(epw, (NJS_POINT3*)&EXP0_UC(0x24), epw->way);
        }

        bhAddSpeed(epw, 0);

        if (EXP0_I(0x3C) != 0 || epw->ct0 == 0)
        {
            hit = bhEne_CheckSideWall(epw, 10.0f, 0);
            
            if (hit == 0)
            {
                epw->way = ((rand() % 2) != 0) ? 256 : -256;
            } 
            else
            {
                epw->way = hit * 256;
            }

            epw->ct0 = 16384;
            epw->ct1 = 256;
            epw->mode3++;
        } 
        else
        {
            epw->ct0--;
        }
        break;

    case 2:
        epw->spd = 0.08f;
        bhAddSpeed(epw, 16);

        epw->ay += epw->way;
        epw->ct0 -= 256;

        if (epw->ct0 < 0)
        {
            epw->mode3 = 1;
            epw->ct0 = (rand() % 32) + 75;
        }
    }

    epw->ct2++;
    
    if ((epw->ct2 % 90) == 0)
    {
        bhEne04_SePlay(epw, 16851714);
    }
}

// 
// Start address: 0x1a7b60
void bhEne04_MV02(BH_PWORK* epw)
{
	int ang;
	int rot;
	// Line 2685, Address: 0x1a7b60, Func Offset: 0
	// Line 2690, Address: 0x1a7b70, Func Offset: 0x10
	// Line 2693, Address: 0x1a7b9c, Func Offset: 0x3c
	// Line 2694, Address: 0x1a7bac, Func Offset: 0x4c
	// Line 2696, Address: 0x1a7bc8, Func Offset: 0x68
	// Line 2698, Address: 0x1a7bdc, Func Offset: 0x7c
	// Line 2699, Address: 0x1a7be4, Func Offset: 0x84
	// Line 2700, Address: 0x1a7be8, Func Offset: 0x88
	// Line 2701, Address: 0x1a7bec, Func Offset: 0x8c
	// Line 2702, Address: 0x1a7bf0, Func Offset: 0x90
	// Line 2703, Address: 0x1a7bf4, Func Offset: 0x94
	// Line 2705, Address: 0x1a7bf8, Func Offset: 0x98
	// Line 2706, Address: 0x1a7c0c, Func Offset: 0xac
	// Line 2708, Address: 0x1a7c30, Func Offset: 0xd0
	// Line 2710, Address: 0x1a7c34, Func Offset: 0xd4
	// Line 2708, Address: 0x1a7c38, Func Offset: 0xd8
	// Line 2709, Address: 0x1a7c3c, Func Offset: 0xdc
	// Line 2708, Address: 0x1a7c40, Func Offset: 0xe0
	// Line 2710, Address: 0x1a7c44, Func Offset: 0xe4
	// Line 2711, Address: 0x1a7c48, Func Offset: 0xe8
	// Line 2708, Address: 0x1a7c4c, Func Offset: 0xec
	// Line 2709, Address: 0x1a7c54, Func Offset: 0xf4
	// Line 2710, Address: 0x1a7c64, Func Offset: 0x104
	// Line 2711, Address: 0x1a7c68, Func Offset: 0x108
	// Line 2712, Address: 0x1a7c74, Func Offset: 0x114
	// Line 2711, Address: 0x1a7c78, Func Offset: 0x118
	// Line 2712, Address: 0x1a7c7c, Func Offset: 0x11c
	// Line 2713, Address: 0x1a7c8c, Func Offset: 0x12c
	// Line 2718, Address: 0x1a7c98, Func Offset: 0x138
	// Line 2720, Address: 0x1a7cac, Func Offset: 0x14c
	// Line 2721, Address: 0x1a7cb0, Func Offset: 0x150
	// Line 2725, Address: 0x1a7cb8, Func Offset: 0x158
	// Line 2727, Address: 0x1a7cd8, Func Offset: 0x178
	// Line 2730, Address: 0x1a7d18, Func Offset: 0x1b8
	// Line 2731, Address: 0x1a7d34, Func Offset: 0x1d4
	// Line 2733, Address: 0x1a7d38, Func Offset: 0x1d8
	// Line 2731, Address: 0x1a7d3c, Func Offset: 0x1dc
	// Line 2733, Address: 0x1a7d48, Func Offset: 0x1e8
	// Line 2734, Address: 0x1a7d5c, Func Offset: 0x1fc
	// Line 2736, Address: 0x1a7d70, Func Offset: 0x210
	// Line 2739, Address: 0x1a7d78, Func Offset: 0x218
	// Line 2742, Address: 0x1a7d88, Func Offset: 0x228
	// Line 2744, Address: 0x1a7da4, Func Offset: 0x244
	// Line 2742, Address: 0x1a7da8, Func Offset: 0x248
	// Line 2744, Address: 0x1a7db8, Func Offset: 0x258
	// Line 2747, Address: 0x1a7dc8, Func Offset: 0x268
	// Line 2748, Address: 0x1a7dcc, Func Offset: 0x26c
	// Line 2749, Address: 0x1a7dd8, Func Offset: 0x278
	// Line 2751, Address: 0x1a7dec, Func Offset: 0x28c
	// Line 2752, Address: 0x1a7df4, Func Offset: 0x294
	// Line 2758, Address: 0x1a7e08, Func Offset: 0x2a8
	// Line 2760, Address: 0x1a7e1c, Func Offset: 0x2bc
	// Line 2762, Address: 0x1a7e28, Func Offset: 0x2c8
	// Line 2765, Address: 0x1a7e40, Func Offset: 0x2e0
	// Line 2767, Address: 0x1a7e48, Func Offset: 0x2e8
	// Line 2772, Address: 0x1a7e50, Func Offset: 0x2f0
	// Line 2782, Address: 0x1a7e54, Func Offset: 0x2f4
	// Line 2786, Address: 0x1a7eb8, Func Offset: 0x358
	// Line 2787, Address: 0x1a7ec4, Func Offset: 0x364
	// Line 2790, Address: 0x1a7ed4, Func Offset: 0x374
	// Line 2789, Address: 0x1a7ed8, Func Offset: 0x378
	// Line 2790, Address: 0x1a7edc, Func Offset: 0x37c
	// Line 2793, Address: 0x1a7ee0, Func Offset: 0x380
	// Line 2796, Address: 0x1a7ee8, Func Offset: 0x388
	// Line 2809, Address: 0x1a7ef8, Func Offset: 0x398
	// Line 2810, Address: 0x1a7f04, Func Offset: 0x3a4
	// Line 2813, Address: 0x1a7f0c, Func Offset: 0x3ac
	// Line 2814, Address: 0x1a7f10, Func Offset: 0x3b0
	// Line 2815, Address: 0x1a7f14, Func Offset: 0x3b4
	// Line 2818, Address: 0x1a7f20, Func Offset: 0x3c0
	// Line 2819, Address: 0x1a7f38, Func Offset: 0x3d8
	// Line 2821, Address: 0x1a7f44, Func Offset: 0x3e4
	// Line 2824, Address: 0x1a7f50, Func Offset: 0x3f0
	// Line 2825, Address: 0x1a7f70, Func Offset: 0x410
	// Line 2827, Address: 0x1a7f94, Func Offset: 0x434
	// Line 2829, Address: 0x1a7f9c, Func Offset: 0x43c
	// Line 2833, Address: 0x1a7fa4, Func Offset: 0x444
	// Line 2836, Address: 0x1a7fc4, Func Offset: 0x464
	// Line 2840, Address: 0x1a7fc8, Func Offset: 0x468
	// Line 2836, Address: 0x1a7fcc, Func Offset: 0x46c
	// Line 2837, Address: 0x1a7fd4, Func Offset: 0x474
	// Line 2840, Address: 0x1a7fe0, Func Offset: 0x480
	// Line 2842, Address: 0x1a7ff8, Func Offset: 0x498
	// Line 2845, Address: 0x1a8000, Func Offset: 0x4a0
	// Line 2842, Address: 0x1a8004, Func Offset: 0x4a4
	// Line 2843, Address: 0x1a8010, Func Offset: 0x4b0
	// Line 2844, Address: 0x1a8014, Func Offset: 0x4b4
	// Line 2847, Address: 0x1a8018, Func Offset: 0x4b8
	// Line 2851, Address: 0x1a8020, Func Offset: 0x4c0
	// Line 2853, Address: 0x1a8040, Func Offset: 0x4e0
	// Line 2854, Address: 0x1a804c, Func Offset: 0x4ec
	// Line 2856, Address: 0x1a8060, Func Offset: 0x500
	// Line 2858, Address: 0x1a8074, Func Offset: 0x514
	// Line 2861, Address: 0x1a809c, Func Offset: 0x53c
	// Line 2865, Address: 0x1a80a4, Func Offset: 0x544
	// Line 2867, Address: 0x1a80b0, Func Offset: 0x550
	// Line 2870, Address: 0x1a80bc, Func Offset: 0x55c
	// Line 2871, Address: 0x1a80dc, Func Offset: 0x57c
	// Line 2873, Address: 0x1a8100, Func Offset: 0x5a0
	// Line 2875, Address: 0x1a8108, Func Offset: 0x5a8
	// Line 2879, Address: 0x1a8110, Func Offset: 0x5b0
	// Line 2882, Address: 0x1a8130, Func Offset: 0x5d0
	// Line 2886, Address: 0x1a8134, Func Offset: 0x5d4
	// Line 2882, Address: 0x1a8138, Func Offset: 0x5d8
	// Line 2883, Address: 0x1a8140, Func Offset: 0x5e0
	// Line 2886, Address: 0x1a814c, Func Offset: 0x5ec
	// Line 2888, Address: 0x1a815c, Func Offset: 0x5fc
	// Line 2889, Address: 0x1a8164, Func Offset: 0x604
	// Line 2890, Address: 0x1a8188, Func Offset: 0x628
	// Line 2891, Address: 0x1a818c, Func Offset: 0x62c
	// Line 2892, Address: 0x1a8190, Func Offset: 0x630
	// Line 2900, Address: 0x1a8194, Func Offset: 0x634
	// Line 2901, Address: 0x1a81ac, Func Offset: 0x64c
	// Line 2902, Address: 0x1a81bc, Func Offset: 0x65c
	// Line 2904, Address: 0x1a81e8, Func Offset: 0x688
	// Line 2906, Address: 0x1a81ec, Func Offset: 0x68c
	// Line 2907, Address: 0x1a81f8, Func Offset: 0x698
	// Func End, Address: 0x1a820c, Func Offset: 0x6ac
    scePrintf("bhEne04_MV02 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne04_MV03(BH_PWORK* epw)
{
    int hit;
    int rot; 
    
    switch (epw->mode3)
    { 
    case 0:
        hit = bhEne_CheckSideWall(epw, 10.0f, 0);
        
        if (hit == 0)
        {
            rot = ikou3(epw, (NJS_POINT3*)&EXP0_UC(0x24), 1536);
            rot = (rot == 0) ? ((rand() % 2) ? 1536 : -1536) : rot;
        } 
        else
        {
            rot = hit * 1536;
        }
        
        epw->way = rot;
        
        epw->ct0 = 8;
        epw->ct1 = 0;
        epw->mode3++;
        
    case 1:
        epw->ay += epw->way;
        bhAddSpeed(epw, 0);
        
        if (epw->ct0 > 0)
        {
            epw->ct0--;
        }
        else if (EXP0_I(0x3C) == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;

            epw->way = 1152;
        }
        break;
        
    case 2:
        epw->ay += epw->way;
        bhAddSpeed(epw, 0);
        
        if (EXP0_I(0x3C) == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            
            epw->way = 1152;
            break;
        }

        if (epw->ct0++ >= 8)
        {
            epw->ct0 = 19;
            epw->spd = 0.3f;
            epw->mode3++;
        }
        break;
        
    case 3:
        bhEne04_SpeedDown(&epw->spd, 0.1f, 0.08f);
        ikou(epw, (NJS_POINT3*)&EXP0_UC(0x24), 256);

        if (epw->ct0-- <= 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            
            epw->way = 1152;
            break;
        }
        break;
    }
    
    bhEne04_RunMotion(epw, epw->way);
}

// 100% matching!
void bhEne04_MV04(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        bhEne04_ChgMtn(epw, 7, 0, 7);
        EXP0_I(0x10) |= 0x40000000;
        epw->mode1 = 0;
        epw->mode3++;
    case 1:
        epw->ay += ikou3(epw, (NJS_POINT3*)&plp->mlwP->owP->mtx[12], 512);
        if (epw->flg & 0x2000000)
        {
            bhEne04_ChgMtn(epw, 49, 0, 0);
            EXP0_I(0x10) &= ~0x40000000;
            epw->mode1 = 1;
            epw->mode3++;
        }
        break;
    case 2:
        epw->ay += ikou3(epw, (NJS_POINT3*)&plp->mlwP->owP->mtx[12], 512);
        if (!(plp->flg & 4))
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            EXP0_I(0x10) &= ~0x2000000;
        }
        break;
    }
}

// 100% matching!
void bhEne04_MV05(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no == 45)
        {
            epw->ay += 32768;
        }
        if (EXP0_I(0x10) & 0x8000)
        {
            bhEne04_ChgMtn(epw, 46, 0, 0);
            EXP0_I(0x10) &= ~0x40000000;
        }
        else
        {
            bhEne04_ChgMtn(epw, 15, 0, 0);
        }
        EXP0_I(0x10) |= 0x100000;
        epw->flg2 |= 1;
        epw->mode3++;
    case 1:
        epw->ay += ikou3(epw, (NJS_POINT3*)&plp->px, 512);
        if ((epw->frm_no / 65536) >= 30)
        {
            EXP0_I(0x10) &= ~0x100000;
        }
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            if (EXP0_I(0x10) & 0x8000)
            {
                epw->mode1 = 1;
                epw->mode2 = 2;
                epw->mode3 = 0;
                EXP0_I(0x10) &= ~0x2000000;
            }
            else
            {
                epw->mode1 = 0;
                epw->mode2 = 4;
                epw->mode3 = 0;
            }
            epw->flg2 &= ~1;
        }
        break;
    }
}

void bhEne04_MV06(BH_PWORK* epw)
{
	int rot;
    
    EXP0_I(0x10) |= 0x80;

    switch (epw->mode3)
    {
    case 0:
        bhEne04_ChgMtn(epw, 0, 0, 7);
        
        epw->way = 256 - ((int)(rand() % 7) * 16);       
        epw->ct0 = (rand() % 32) + 45;        
        epw->ct1 = 0;
        
        EXP0_F(0x24) = plp->px;
        EXP0_F(0x2C) = plp->pz;
        EXP0_I(0x10) &= ~0x4000;
        
        epw->mode3++;

    case 1:
        epw->spd = 0.15f;
        bhAddSpeed(epw, 0);

        epw->ay += epw->way;
        
        if (--epw->ct0 == 0)
        {
            epw->ct0 = (rand() % 32) + 15;
            epw->mode3++;
        }
        break;
    case 2:
        bhAddSpeed(epw, 0);
        if ((--epw->ct0 == 0) || (EXP0_I(0x3C) != 0))
        {
            epw->way = ikou3(epw, (NJS_POINT3*)&plp->px, 256 - ((rand() % 7) * 16));
            epw->ct0 = 2;
            epw->mode3 = 1;
            epw->ct0 = (rand() % 32) + 45;
        }
        break;
    case 3:
        bhAddSpeed(epw, 0);
        bhEne04_Escape(epw, 600, 256);
        if (EXP0_I(0x10) & 0x4000)
        {
            epw->mode3 = 0;
        }
        break;
    }
    
    if (epw->mode3 != 3)
    {
        rot = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        
        if (bhEne_CheckDirWall(epw, rot, 8.0f) != NULL)
        {
            EXP0_I(0x50) = 0;
            EXP0_I(0x4C)= 0;
            EXP0_I(0x48) = 0;
            epw->mode3 = 3;
        }
    }
}

// 
// Start address: 0x1a8a40
void bhEne04_MV07(BH_PWORK* epw)
{
	int ret;
	//_anon36 pos3;
	//_anon36 pos2;
	//_anon36 pos;
	//_anon4* owk;
	//_anon12* hp;
	// Line 3275, Address: 0x1a8a40, Func Offset: 0
	// Line 3282, Address: 0x1a8a54, Func Offset: 0x14
	// Line 3285, Address: 0x1a8a80, Func Offset: 0x40
	// Line 3286, Address: 0x1a8a94, Func Offset: 0x54
	// Line 3287, Address: 0x1a8aa0, Func Offset: 0x60
	// Line 3288, Address: 0x1a8aa8, Func Offset: 0x68
	// Line 3291, Address: 0x1a8ab4, Func Offset: 0x74
	// Line 3292, Address: 0x1a8ac0, Func Offset: 0x80
	// Line 3293, Address: 0x1a8acc, Func Offset: 0x8c
	// Line 3295, Address: 0x1a8ad8, Func Offset: 0x98
	// Line 3296, Address: 0x1a8adc, Func Offset: 0x9c
	// Line 3298, Address: 0x1a8ae8, Func Offset: 0xa8
	// Line 3296, Address: 0x1a8af0, Func Offset: 0xb0
	// Line 3297, Address: 0x1a8af4, Func Offset: 0xb4
	// Line 3298, Address: 0x1a8b04, Func Offset: 0xc4
	// Line 3299, Address: 0x1a8b08, Func Offset: 0xc8
	// Line 3301, Address: 0x1a8b10, Func Offset: 0xd0
	// Line 3304, Address: 0x1a8b18, Func Offset: 0xd8
	// Line 3306, Address: 0x1a8b20, Func Offset: 0xe0
	// Line 3307, Address: 0x1a8b50, Func Offset: 0x110
	// Line 3310, Address: 0x1a8b5c, Func Offset: 0x11c
	// Line 3312, Address: 0x1a8b84, Func Offset: 0x144
	// Line 3313, Address: 0x1a8b90, Func Offset: 0x150
	// Line 3316, Address: 0x1a8b9c, Func Offset: 0x15c
	// Line 3318, Address: 0x1a8ba0, Func Offset: 0x160
	// Line 3317, Address: 0x1a8ba4, Func Offset: 0x164
	// Line 3318, Address: 0x1a8ba8, Func Offset: 0x168
	// Line 3319, Address: 0x1a8bac, Func Offset: 0x16c
	// Line 3320, Address: 0x1a8bb0, Func Offset: 0x170
	// Line 3321, Address: 0x1a8bb8, Func Offset: 0x178
	// Line 3323, Address: 0x1a8bbc, Func Offset: 0x17c
	// Line 3324, Address: 0x1a8bc0, Func Offset: 0x180
	// Line 3320, Address: 0x1a8bc4, Func Offset: 0x184
	// Line 3321, Address: 0x1a8bd0, Func Offset: 0x190
	// Line 3323, Address: 0x1a8be0, Func Offset: 0x1a0
	// Line 3324, Address: 0x1a8be8, Func Offset: 0x1a8
	// Line 3323, Address: 0x1a8bec, Func Offset: 0x1ac
	// Line 3324, Address: 0x1a8bf4, Func Offset: 0x1b4
	// Line 3325, Address: 0x1a8c00, Func Offset: 0x1c0
	// Line 3327, Address: 0x1a8c08, Func Offset: 0x1c8
	// Line 3330, Address: 0x1a8c14, Func Offset: 0x1d4
	// Line 3332, Address: 0x1a8c28, Func Offset: 0x1e8
	// Line 3331, Address: 0x1a8c2c, Func Offset: 0x1ec
	// Line 3332, Address: 0x1a8c30, Func Offset: 0x1f0
	// Line 3333, Address: 0x1a8c34, Func Offset: 0x1f4
	// Line 3334, Address: 0x1a8c38, Func Offset: 0x1f8
	// Line 3335, Address: 0x1a8c48, Func Offset: 0x208
	// Line 3341, Address: 0x1a8c50, Func Offset: 0x210
	// Line 3344, Address: 0x1a8c64, Func Offset: 0x224
	// Line 3346, Address: 0x1a8c78, Func Offset: 0x238
	// Line 3345, Address: 0x1a8c7c, Func Offset: 0x23c
	// Line 3346, Address: 0x1a8c80, Func Offset: 0x240
	// Line 3347, Address: 0x1a8c84, Func Offset: 0x244
	// Line 3348, Address: 0x1a8c8c, Func Offset: 0x24c
	// Line 3349, Address: 0x1a8c9c, Func Offset: 0x25c
	// Line 3354, Address: 0x1a8ca4, Func Offset: 0x264
	// Line 3357, Address: 0x1a8cb8, Func Offset: 0x278
	// Line 3358, Address: 0x1a8ccc, Func Offset: 0x28c
	// Line 3361, Address: 0x1a8cd4, Func Offset: 0x294
	// Line 3364, Address: 0x1a8cdc, Func Offset: 0x29c
	// Line 3366, Address: 0x1a8ce4, Func Offset: 0x2a4
	// Line 3371, Address: 0x1a8d04, Func Offset: 0x2c4
	// Line 3372, Address: 0x1a8d08, Func Offset: 0x2c8
	// Line 3366, Address: 0x1a8d0c, Func Offset: 0x2cc
	// Line 3367, Address: 0x1a8d1c, Func Offset: 0x2dc
	// Line 3369, Address: 0x1a8d28, Func Offset: 0x2e8
	// Line 3370, Address: 0x1a8d30, Func Offset: 0x2f0
	// Line 3371, Address: 0x1a8d38, Func Offset: 0x2f8
	// Line 3372, Address: 0x1a8d40, Func Offset: 0x300
	// Line 3373, Address: 0x1a8d48, Func Offset: 0x308
	// Line 3374, Address: 0x1a8d68, Func Offset: 0x328
	// Line 3383, Address: 0x1a8d80, Func Offset: 0x340
	// Line 3374, Address: 0x1a8d88, Func Offset: 0x348
	// Line 3375, Address: 0x1a8d90, Func Offset: 0x350
	// Line 3383, Address: 0x1a8d94, Func Offset: 0x354
	// Line 3385, Address: 0x1a8da4, Func Offset: 0x364
	// Line 3388, Address: 0x1a8db0, Func Offset: 0x370
	// Line 3390, Address: 0x1a8db4, Func Offset: 0x374
	// Line 3389, Address: 0x1a8db8, Func Offset: 0x378
	// Line 3390, Address: 0x1a8dbc, Func Offset: 0x37c
	// Line 3391, Address: 0x1a8dc0, Func Offset: 0x380
	// Line 3392, Address: 0x1a8dc4, Func Offset: 0x384
	// Line 3393, Address: 0x1a8dcc, Func Offset: 0x38c
	// Line 3395, Address: 0x1a8dd0, Func Offset: 0x390
	// Line 3396, Address: 0x1a8dd4, Func Offset: 0x394
	// Line 3392, Address: 0x1a8dd8, Func Offset: 0x398
	// Line 3393, Address: 0x1a8de4, Func Offset: 0x3a4
	// Line 3395, Address: 0x1a8df4, Func Offset: 0x3b4
	// Line 3396, Address: 0x1a8dfc, Func Offset: 0x3bc
	// Line 3395, Address: 0x1a8e00, Func Offset: 0x3c0
	// Line 3396, Address: 0x1a8e08, Func Offset: 0x3c8
	// Line 3397, Address: 0x1a8e14, Func Offset: 0x3d4
	// Line 3399, Address: 0x1a8e1c, Func Offset: 0x3dc
	// Line 3402, Address: 0x1a8e28, Func Offset: 0x3e8
	// Line 3404, Address: 0x1a8e3c, Func Offset: 0x3fc
	// Line 3403, Address: 0x1a8e40, Func Offset: 0x400
	// Line 3404, Address: 0x1a8e44, Func Offset: 0x404
	// Line 3405, Address: 0x1a8e48, Func Offset: 0x408
	// Line 3406, Address: 0x1a8e4c, Func Offset: 0x40c
	// Line 3407, Address: 0x1a8e5c, Func Offset: 0x41c
	// Line 3413, Address: 0x1a8e64, Func Offset: 0x424
	// Line 3415, Address: 0x1a8e78, Func Offset: 0x438
	// Line 3417, Address: 0x1a8e88, Func Offset: 0x448
	// Line 3418, Address: 0x1a8e90, Func Offset: 0x450
	// Line 3421, Address: 0x1a8ea8, Func Offset: 0x468
	// Line 3422, Address: 0x1a8ecc, Func Offset: 0x48c
	// Line 3423, Address: 0x1a8ed4, Func Offset: 0x494
	// Line 3422, Address: 0x1a8ed8, Func Offset: 0x498
	// Line 3423, Address: 0x1a8ee4, Func Offset: 0x4a4
	// Line 3425, Address: 0x1a8f00, Func Offset: 0x4c0
	// Line 3429, Address: 0x1a8f14, Func Offset: 0x4d4
	// Line 3431, Address: 0x1a8f1c, Func Offset: 0x4dc
	// Line 3436, Address: 0x1a8f24, Func Offset: 0x4e4
	// Line 3438, Address: 0x1a8f34, Func Offset: 0x4f4
	// Line 3439, Address: 0x1a8f48, Func Offset: 0x508
	// Line 3442, Address: 0x1a8f50, Func Offset: 0x510
	// Line 3446, Address: 0x1a8f58, Func Offset: 0x518
	// Line 3448, Address: 0x1a8f60, Func Offset: 0x520
	// Line 3450, Address: 0x1a8f80, Func Offset: 0x540
	// Line 3448, Address: 0x1a8f84, Func Offset: 0x544
	// Line 3450, Address: 0x1a8f94, Func Offset: 0x554
	// Line 3452, Address: 0x1a8fbc, Func Offset: 0x57c
	// Line 3453, Address: 0x1a8fc0, Func Offset: 0x580
	// Line 3452, Address: 0x1a8fc4, Func Offset: 0x584
	// Line 3453, Address: 0x1a8fcc, Func Offset: 0x58c
	// Line 3455, Address: 0x1a8fe4, Func Offset: 0x5a4
	// Line 3457, Address: 0x1a8fe8, Func Offset: 0x5a8
	// Line 3455, Address: 0x1a8fec, Func Offset: 0x5ac
	// Line 3457, Address: 0x1a8ff4, Func Offset: 0x5b4
	// Line 3459, Address: 0x1a9004, Func Offset: 0x5c4
	// Line 3460, Address: 0x1a9008, Func Offset: 0x5c8
	// Line 3459, Address: 0x1a900c, Func Offset: 0x5cc
	// Line 3460, Address: 0x1a9014, Func Offset: 0x5d4
	// Line 3463, Address: 0x1a9020, Func Offset: 0x5e0
	// Line 3466, Address: 0x1a9028, Func Offset: 0x5e8
	// Line 3467, Address: 0x1a9030, Func Offset: 0x5f0
	// Line 3468, Address: 0x1a9050, Func Offset: 0x610
	// Line 3470, Address: 0x1a9080, Func Offset: 0x640
	// Line 3471, Address: 0x1a9088, Func Offset: 0x648
	// Line 3474, Address: 0x1a9090, Func Offset: 0x650
	// Line 3477, Address: 0x1a9098, Func Offset: 0x658
	// Line 3479, Address: 0x1a90ac, Func Offset: 0x66c
	// Line 3481, Address: 0x1a90c0, Func Offset: 0x680
	// Line 3482, Address: 0x1a90fc, Func Offset: 0x6bc
	// Line 3483, Address: 0x1a9108, Func Offset: 0x6c8
	// Line 3485, Address: 0x1a910c, Func Offset: 0x6cc
	// Line 3483, Address: 0x1a9110, Func Offset: 0x6d0
	// Line 3485, Address: 0x1a9118, Func Offset: 0x6d8
	// Line 3487, Address: 0x1a9128, Func Offset: 0x6e8
	// Line 3488, Address: 0x1a9130, Func Offset: 0x6f0
	// Line 3489, Address: 0x1a913c, Func Offset: 0x6fc
	// Line 3491, Address: 0x1a9144, Func Offset: 0x704
	// Line 3494, Address: 0x1a914c, Func Offset: 0x70c
	// Line 3495, Address: 0x1a9154, Func Offset: 0x714
	// Line 3498, Address: 0x1a9174, Func Offset: 0x734
	// Line 3500, Address: 0x1a9194, Func Offset: 0x754
	// Line 3498, Address: 0x1a9198, Func Offset: 0x758
	// Line 3500, Address: 0x1a91a8, Func Offset: 0x768
	// Line 3502, Address: 0x1a91d0, Func Offset: 0x790
	// Line 3504, Address: 0x1a91d8, Func Offset: 0x798
	// Line 3502, Address: 0x1a91dc, Func Offset: 0x79c
	// Line 3503, Address: 0x1a91e8, Func Offset: 0x7a8
	// Line 3504, Address: 0x1a91f4, Func Offset: 0x7b4
	// Line 3506, Address: 0x1a920c, Func Offset: 0x7cc
	// Line 3508, Address: 0x1a9210, Func Offset: 0x7d0
	// Line 3506, Address: 0x1a9214, Func Offset: 0x7d4
	// Line 3508, Address: 0x1a921c, Func Offset: 0x7dc
	// Line 3513, Address: 0x1a922c, Func Offset: 0x7ec
	// Line 3514, Address: 0x1a9230, Func Offset: 0x7f0
	// Line 3513, Address: 0x1a923c, Func Offset: 0x7fc
	// Line 3514, Address: 0x1a9240, Func Offset: 0x800
	// Line 3515, Address: 0x1a924c, Func Offset: 0x80c
	// Line 3516, Address: 0x1a9250, Func Offset: 0x810
	// Line 3517, Address: 0x1a9254, Func Offset: 0x814
	// Line 3515, Address: 0x1a9258, Func Offset: 0x818
	// Line 3516, Address: 0x1a9264, Func Offset: 0x824
	// Line 3517, Address: 0x1a9268, Func Offset: 0x828
	// Line 3518, Address: 0x1a926c, Func Offset: 0x82c
	// Line 3522, Address: 0x1a9270, Func Offset: 0x830
	// Func End, Address: 0x1a9288, Func Offset: 0x848
    scePrintf("bhEne04_MV07 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1a9290
void bhEne04_MV08(BH_PWORK* epw)
{
	float jump;
	int frm;
	//_anon36 pos;
	// Line 3542, Address: 0x1a9290, Func Offset: 0
	// Line 3549, Address: 0x1a92a4, Func Offset: 0x14
	// Line 3552, Address: 0x1a92d0, Func Offset: 0x40
	// Line 3555, Address: 0x1a92d4, Func Offset: 0x44
	// Line 3557, Address: 0x1a92dc, Func Offset: 0x4c
	// Line 3553, Address: 0x1a92e4, Func Offset: 0x54
	// Line 3552, Address: 0x1a92e8, Func Offset: 0x58
	// Line 3554, Address: 0x1a92ec, Func Offset: 0x5c
	// Line 3558, Address: 0x1a92f0, Func Offset: 0x60
	// Line 3552, Address: 0x1a92f4, Func Offset: 0x64
	// Line 3553, Address: 0x1a92fc, Func Offset: 0x6c
	// Line 3554, Address: 0x1a9300, Func Offset: 0x70
	// Line 3555, Address: 0x1a9304, Func Offset: 0x74
	// Line 3556, Address: 0x1a930c, Func Offset: 0x7c
	// Line 3557, Address: 0x1a9310, Func Offset: 0x80
	// Line 3558, Address: 0x1a9314, Func Offset: 0x84
	// Line 3559, Address: 0x1a9318, Func Offset: 0x88
	// Line 3562, Address: 0x1a9324, Func Offset: 0x94
	// Line 3563, Address: 0x1a932c, Func Offset: 0x9c
	// Line 3565, Address: 0x1a9338, Func Offset: 0xa8
	// Line 3566, Address: 0x1a938c, Func Offset: 0xfc
	// Line 3567, Address: 0x1a9398, Func Offset: 0x108
	// Line 3570, Address: 0x1a93a4, Func Offset: 0x114
	// Line 3572, Address: 0x1a93bc, Func Offset: 0x12c
	// Line 3573, Address: 0x1a93c4, Func Offset: 0x134
	// Line 3574, Address: 0x1a93e4, Func Offset: 0x154
	// Line 3573, Address: 0x1a93e8, Func Offset: 0x158
	// Line 3574, Address: 0x1a93f8, Func Offset: 0x168
	// Line 3576, Address: 0x1a9420, Func Offset: 0x190
	// Line 3578, Address: 0x1a9428, Func Offset: 0x198
	// Line 3576, Address: 0x1a942c, Func Offset: 0x19c
	// Line 3577, Address: 0x1a9438, Func Offset: 0x1a8
	// Line 3578, Address: 0x1a9444, Func Offset: 0x1b4
	// Line 3579, Address: 0x1a9458, Func Offset: 0x1c8
	// Line 3582, Address: 0x1a9460, Func Offset: 0x1d0
	// Line 3583, Address: 0x1a946c, Func Offset: 0x1dc
	// Line 3585, Address: 0x1a9478, Func Offset: 0x1e8
	// Line 3588, Address: 0x1a9484, Func Offset: 0x1f4
	// Line 3593, Address: 0x1a9498, Func Offset: 0x208
	// Line 3594, Address: 0x1a949c, Func Offset: 0x20c
	// Line 3593, Address: 0x1a94a8, Func Offset: 0x218
	// Line 3594, Address: 0x1a94ac, Func Offset: 0x21c
	// Line 3595, Address: 0x1a94b8, Func Offset: 0x228
	// Line 3596, Address: 0x1a94bc, Func Offset: 0x22c
	// Line 3597, Address: 0x1a94c0, Func Offset: 0x230
	// Line 3595, Address: 0x1a94c4, Func Offset: 0x234
	// Line 3596, Address: 0x1a94d0, Func Offset: 0x240
	// Line 3597, Address: 0x1a94d4, Func Offset: 0x244
	// Line 3600, Address: 0x1a94d8, Func Offset: 0x248
	// Line 3603, Address: 0x1a94e0, Func Offset: 0x250
	// Line 3608, Address: 0x1a94e4, Func Offset: 0x254
	// Line 3618, Address: 0x1a94ec, Func Offset: 0x25c
	// Line 3605, Address: 0x1a94f4, Func Offset: 0x264
	// Line 3603, Address: 0x1a94f8, Func Offset: 0x268
	// Line 3606, Address: 0x1a94fc, Func Offset: 0x26c
	// Line 3612, Address: 0x1a9500, Func Offset: 0x270
	// Line 3613, Address: 0x1a9504, Func Offset: 0x274
	// Line 3603, Address: 0x1a9508, Func Offset: 0x278
	// Line 3604, Address: 0x1a9510, Func Offset: 0x280
	// Line 3605, Address: 0x1a9514, Func Offset: 0x284
	// Line 3606, Address: 0x1a9518, Func Offset: 0x288
	// Line 3614, Address: 0x1a951c, Func Offset: 0x28c
	// Line 3617, Address: 0x1a9520, Func Offset: 0x290
	// Line 3618, Address: 0x1a9524, Func Offset: 0x294
	// Line 3606, Address: 0x1a9528, Func Offset: 0x298
	// Line 3607, Address: 0x1a952c, Func Offset: 0x29c
	// Line 3608, Address: 0x1a9530, Func Offset: 0x2a0
	// Line 3611, Address: 0x1a9534, Func Offset: 0x2a4
	// Line 3612, Address: 0x1a953c, Func Offset: 0x2ac
	// Line 3613, Address: 0x1a9544, Func Offset: 0x2b4
	// Line 3614, Address: 0x1a954c, Func Offset: 0x2bc
	// Line 3615, Address: 0x1a9554, Func Offset: 0x2c4
	// Line 3614, Address: 0x1a9558, Func Offset: 0x2c8
	// Line 3615, Address: 0x1a955c, Func Offset: 0x2cc
	// Line 3616, Address: 0x1a9564, Func Offset: 0x2d4
	// Line 3615, Address: 0x1a9568, Func Offset: 0x2d8
	// Line 3616, Address: 0x1a956c, Func Offset: 0x2dc
	// Line 3618, Address: 0x1a9578, Func Offset: 0x2e8
	// Line 3619, Address: 0x1a9584, Func Offset: 0x2f4
	// Line 3620, Address: 0x1a958c, Func Offset: 0x2fc
	// Line 3621, Address: 0x1a9594, Func Offset: 0x304
	// Line 3623, Address: 0x1a959c, Func Offset: 0x30c
	// Line 3624, Address: 0x1a95c0, Func Offset: 0x330
	// Line 3625, Address: 0x1a95dc, Func Offset: 0x34c
	// Line 3627, Address: 0x1a95e0, Func Offset: 0x350
	// Line 3624, Address: 0x1a95e4, Func Offset: 0x354
	// Line 3625, Address: 0x1a95ec, Func Offset: 0x35c
	// Line 3627, Address: 0x1a9608, Func Offset: 0x378
	// Line 3630, Address: 0x1a9614, Func Offset: 0x384
	// Line 3633, Address: 0x1a961c, Func Offset: 0x38c
	// Line 3634, Address: 0x1a9624, Func Offset: 0x394
	// Line 3635, Address: 0x1a962c, Func Offset: 0x39c
	// Line 3639, Address: 0x1a9630, Func Offset: 0x3a0
	// Line 3635, Address: 0x1a9638, Func Offset: 0x3a8
	// Line 3636, Address: 0x1a9640, Func Offset: 0x3b0
	// Line 3637, Address: 0x1a964c, Func Offset: 0x3bc
	// Line 3639, Address: 0x1a9654, Func Offset: 0x3c4
	// Line 3641, Address: 0x1a9664, Func Offset: 0x3d4
	// Line 3643, Address: 0x1a9668, Func Offset: 0x3d8
	// Line 3645, Address: 0x1a9674, Func Offset: 0x3e4
	// Line 3647, Address: 0x1a9680, Func Offset: 0x3f0
	// Line 3650, Address: 0x1a969c, Func Offset: 0x40c
	// Line 3653, Address: 0x1a96a8, Func Offset: 0x418
	// Line 3654, Address: 0x1a96b0, Func Offset: 0x420
	// Line 3656, Address: 0x1a96c8, Func Offset: 0x438
	// Line 3659, Address: 0x1a96d8, Func Offset: 0x448
	// Line 3661, Address: 0x1a96e4, Func Offset: 0x454
	// Line 3662, Address: 0x1a972c, Func Offset: 0x49c
	// Line 3663, Address: 0x1a9734, Func Offset: 0x4a4
	// Line 3666, Address: 0x1a973c, Func Offset: 0x4ac
	// Line 3667, Address: 0x1a9758, Func Offset: 0x4c8
	// Line 3666, Address: 0x1a975c, Func Offset: 0x4cc
	// Line 3667, Address: 0x1a9764, Func Offset: 0x4d4
	// Line 3666, Address: 0x1a976c, Func Offset: 0x4dc
	// Line 3670, Address: 0x1a9770, Func Offset: 0x4e0
	// Line 3671, Address: 0x1a9774, Func Offset: 0x4e4
	// Line 3670, Address: 0x1a9778, Func Offset: 0x4e8
	// Line 3671, Address: 0x1a9780, Func Offset: 0x4f0
	// Line 3673, Address: 0x1a97a8, Func Offset: 0x518
	// Line 3675, Address: 0x1a97b0, Func Offset: 0x520
	// Line 3673, Address: 0x1a97b4, Func Offset: 0x524
	// Line 3674, Address: 0x1a97c0, Func Offset: 0x530
	// Line 3675, Address: 0x1a97cc, Func Offset: 0x53c
	// Line 3678, Address: 0x1a97e4, Func Offset: 0x554
	// Line 3680, Address: 0x1a97f0, Func Offset: 0x560
	// Line 3683, Address: 0x1a97fc, Func Offset: 0x56c
	// Line 3684, Address: 0x1a9800, Func Offset: 0x570
	// Line 3688, Address: 0x1a9808, Func Offset: 0x578
	// Line 3690, Address: 0x1a9810, Func Offset: 0x580
	// Line 3691, Address: 0x1a9824, Func Offset: 0x594
	// Line 3692, Address: 0x1a982c, Func Offset: 0x59c
	// Line 3693, Address: 0x1a9838, Func Offset: 0x5a8
	// Line 3695, Address: 0x1a983c, Func Offset: 0x5ac
	// Line 3698, Address: 0x1a9844, Func Offset: 0x5b4
	// Line 3701, Address: 0x1a9854, Func Offset: 0x5c4
	// Line 3702, Address: 0x1a985c, Func Offset: 0x5cc
	// Line 3703, Address: 0x1a9860, Func Offset: 0x5d0
	// Line 3701, Address: 0x1a9864, Func Offset: 0x5d4
	// Line 3702, Address: 0x1a9868, Func Offset: 0x5d8
	// Line 3703, Address: 0x1a986c, Func Offset: 0x5dc
	// Line 3704, Address: 0x1a9870, Func Offset: 0x5e0
	// Line 3708, Address: 0x1a9874, Func Offset: 0x5e4
	// Line 3709, Address: 0x1a9894, Func Offset: 0x604
	// Line 3710, Address: 0x1a98a0, Func Offset: 0x610
	// Line 3711, Address: 0x1a98ac, Func Offset: 0x61c
	// Line 3715, Address: 0x1a98b4, Func Offset: 0x624
	// Line 3717, Address: 0x1a98bc, Func Offset: 0x62c
	// Line 3720, Address: 0x1a98c8, Func Offset: 0x638
	// Line 3721, Address: 0x1a98e8, Func Offset: 0x658
	// Line 3723, Address: 0x1a990c, Func Offset: 0x67c
	// Line 3725, Address: 0x1a9914, Func Offset: 0x684
	// Line 3729, Address: 0x1a991c, Func Offset: 0x68c
	// Line 3732, Address: 0x1a993c, Func Offset: 0x6ac
	// Line 3736, Address: 0x1a9940, Func Offset: 0x6b0
	// Line 3732, Address: 0x1a9944, Func Offset: 0x6b4
	// Line 3733, Address: 0x1a994c, Func Offset: 0x6bc
	// Line 3736, Address: 0x1a9958, Func Offset: 0x6c8
	// Line 3738, Address: 0x1a9968, Func Offset: 0x6d8
	// Line 3739, Address: 0x1a9970, Func Offset: 0x6e0
	// Line 3740, Address: 0x1a9978, Func Offset: 0x6e8
	// Line 3742, Address: 0x1a997c, Func Offset: 0x6ec
	// Line 3745, Address: 0x1a9988, Func Offset: 0x6f8
	// Func End, Address: 0x1a99a0, Func Offset: 0x710
    scePrintf("bhEne04_MV08 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne04_MV09(BH_PWORK* epw)
{
    int frm;

    switch (epw->mode3)
    {
    case 0:
        bhEne04_ChgMtn(epw, 36, 0, 5);
        epw->spd = 0.0f;
        epw->way = -546;
        EXP0_I(0x10) |= 0x40000000;
        epw->mode3++;

    case 1:
        frm = epw->frm_no / 65536;
        if ((frm >= 4) && (frm < 14))
        {
            epw->ay += epw->way;
            
            if (bhEne04_PlyDamageCheck(epw, 0) != 0)
            {
                plp->hp -= 6;
            }
        }
        
        if (epw->flg & 0x2000000)
        {
            EXP0_I(0x10) &= ~0x40000000;
            
            bhEne04_ChgMtn(epw, 1, 0, 0);
            
            epw->wax = 0;
            
            epw->ct0 = 0;
            epw->ct1 = 0;
            epw->ct2 = 0;
            
            if (EXP0_I(0x10) & 0x800)
            {
                epw->ct1 = (rand() % 15) + 20;
            }
            
            EXP0_I(0x10) &= ~0x3000;
            EXP0_I(0x10) &= ~0x4000;
            
            epw->spd = 0.6f;
            
            EXP0_F(0x24) = plp->px;
            EXP0_F(0x2C) = plp->pz;
            
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 1;
        }
        break;
    }
}

// 99.64% matching
void bhEne04_MV10(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        bhEne04_ChgMtn(epw, 33, 0, 5);
      
    case 1:
        if ((epw->frm_no / 65536) < 8)
        {
            epw->ay += epw->ayp / 8;
        }

        bhEne04_SpeedUp(&epw->spd, 0.1f, 1.2f); // float memes? :(
        bhAddSpeed(epw, 0);

        if (epw->flg & 0x2000000)
        {
            bhEne04_ChgMtn(epw, 1, 0, 0);

            epw->wax = 0;

            epw->ct0 = 0;
            epw->ct1 = 0;
            epw->ct2 = 0;

            if (EXP0_I(0x10) & 0x800)
            {
                epw->ct1 = (rand() % 15) + 20;
            }

            EXP0_I(0x10) &= ~0x3000;
            EXP0_I(0x10) &= ~0x4000;

            epw->spd = 0.6f;

            EXP0_F(0x24) = plp->px;
            EXP0_F(0x2C) = plp->pz;

            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 1;
        }
    }
}

// 100% matching!
void bhEne04_MV11(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (*(unsigned char*)((char*)EXP0_I(0x40) + 0x20) == 0)
        {
            EXP0_UC(0x5) = 0;
            epw->yn = epw->py + (*(unsigned char*)((char*)EXP0_I(0x40) + 0x22) * 2);
            EXP0_I(0x10) |= 0x10000;
        } 
        else
        {
            EXP0_C(0x5) = *(unsigned char*)((char*)EXP0_I(0x40) + 0x22);
            epw->yn = epw->py - (*(unsigned char*)((char*)EXP0_I(0x40) + 0x22) * 2);
            EXP0_I(0x10) &= ~0x10000;
        }
        
        EXP0_C(0x4) = epw->flr_no;
        EXP0_I(0x10) |= 0x10;
        
        epw->axp = kaidan_ang[*(unsigned char*)((char*)EXP0_I(0x40) + 0x21)];
        epw->ayp = (epw->axp - epw->ay) & 0xFFFF;
        if (epw->ayp > 32768)
        {
            epw->ayp -= 65536;
        }
        epw->ayp /= 10;
        epw->ct0 = 10;
        epw->mode3++;
    case 1:
        epw->ay += epw->ayp;
        if (--epw->ct0 < 0)
        {
            bhEne04_ChgMtn(epw, (EXP0_I(0x10) & 0x10000) ? 37 : 38, 0, 5);
            
            EXP0_I(0x10) |= 0x40000000;
            EXP0_I(0x10) |= 0x20000;
            EXP0_I(0x10) &= ~0x20;
            
            epw->flg2 |= 1;
            
            EXP0_F(0x30) = epw->px;
            EXP0_F(0x34) = epw->py;
            EXP0_F(0x38) = epw->pz;
            
            epw->ay = epw->axp;
            epw->mode3++;
        }
        break;
    case 2:
        if (EXP0_I(0x10) & 0x10000)
        {
            epw->cah = epw->mlwP->owP[5].mtx[13] - epw->py;
        }
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->flr_no = bhCheckFloorNum(epw->yn);            
            epw->py = rom->grand[2 + epw->flr_no];            
            epw->flg2 &= ~1;            
            bhEne04_ChgMtn(epw, 1, 0, 10);           
            epw->mtn_md |= 0x100;            
            bhClrUseKaidanFlag(epw);
            epw->cah = 4.0f;
            
            EXP0_I(0x10) &= ~0x10;
            EXP0_I(0x10) &= ~0x40000000;
            EXP0_I(0x10) &= ~0x20000;
            EXP0_I(0x10) |= 0x20;
            
            epw->mode1 = 1;            
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne04_MV12(BH_PWORK* epw)
{
    O_WORK* owk;

    switch (epw->mode3)
    {
    case 0:
        bhEne04_ChgMtn(epw, 0, 0, 7);
        epw->mode3++;

    case 1:
        owk = &plp->mlwP->owP[1];
        epw->spd = 0.15f;
        bhAddSpeed(epw, 0);
        epw->ay += ikou3(epw, (NJS_POINT3*)&owk->mtx[12], 256);
        if (EXP0_F(0x20) <= 9.0f)
        {
            bhEne04_ChgMtn(epw, 42, 0, 7);
            EXP0_I(0x10) |= 0x40000000;
            epw->mode3++;
        }
        break;
        
    case 2:
        epw->ay += ikou3(epw, (NJS_POINT3*)&plp->mlwP->owP[1].mtx[12], 256);
        if (epw->flg & 0x2000000)
        {
            EXP0_I(0x10) &= ~0x40000000;
            bhEne04_ChgMtn(epw, 43, 0, 7);
            epw->mode3++;
        } 
        
    case 3:
        break;    
    }
}

// 
// Start address: 0x1aa220
int bhEne04_Escape(BH_PWORK* epw, int res, int r)
{
	int rot;
	int d_tmp;
	//_anon12* hp;
	// Line 4233, Address: 0x1aa220, Func Offset: 0
	// Line 4238, Address: 0x1aa238, Func Offset: 0x18
	// Line 4241, Address: 0x1aa28c, Func Offset: 0x6c
	// Line 4243, Address: 0x1aa2b0, Func Offset: 0x90
	// Line 4245, Address: 0x1aa2b4, Func Offset: 0x94
	// Line 4246, Address: 0x1aa2c8, Func Offset: 0xa8
	// Line 4247, Address: 0x1aa2d0, Func Offset: 0xb0
	// Line 4250, Address: 0x1aa2e0, Func Offset: 0xc0
	// Line 4252, Address: 0x1aa2f0, Func Offset: 0xd0
	// Line 4253, Address: 0x1aa2fc, Func Offset: 0xdc
	// Line 4255, Address: 0x1aa304, Func Offset: 0xe4
	// Line 4256, Address: 0x1aa320, Func Offset: 0x100
	// Line 4259, Address: 0x1aa328, Func Offset: 0x108
	// Line 4261, Address: 0x1aa338, Func Offset: 0x118
	// Line 4264, Address: 0x1aa33c, Func Offset: 0x11c
	// Line 4261, Address: 0x1aa348, Func Offset: 0x128
	// Line 4262, Address: 0x1aa350, Func Offset: 0x130
	// Line 4264, Address: 0x1aa354, Func Offset: 0x134
	// Line 4265, Address: 0x1aa370, Func Offset: 0x150
	// Line 4267, Address: 0x1aa378, Func Offset: 0x158
	// Line 4270, Address: 0x1aa384, Func Offset: 0x164
	// Line 4273, Address: 0x1aa394, Func Offset: 0x174
	// Line 4274, Address: 0x1aa3b0, Func Offset: 0x190
	// Line 4277, Address: 0x1aa3b8, Func Offset: 0x198
	// Line 4278, Address: 0x1aa3cc, Func Offset: 0x1ac
	// Line 4281, Address: 0x1aa3f8, Func Offset: 0x1d8
	// Line 4283, Address: 0x1aa400, Func Offset: 0x1e0
	// Line 4284, Address: 0x1aa404, Func Offset: 0x1e4
	// Line 4281, Address: 0x1aa408, Func Offset: 0x1e8
	// Line 4282, Address: 0x1aa40c, Func Offset: 0x1ec
	// Line 4283, Address: 0x1aa414, Func Offset: 0x1f4
	// Line 4285, Address: 0x1aa418, Func Offset: 0x1f8
	// Line 4288, Address: 0x1aa420, Func Offset: 0x200
	// Line 4289, Address: 0x1aa424, Func Offset: 0x204
	// Line 4288, Address: 0x1aa428, Func Offset: 0x208
	// Line 4290, Address: 0x1aa430, Func Offset: 0x210
	// Line 4293, Address: 0x1aa438, Func Offset: 0x218
	// Line 4294, Address: 0x1aa44c, Func Offset: 0x22c
	// Line 4296, Address: 0x1aa45c, Func Offset: 0x23c
	// Line 4298, Address: 0x1aa46c, Func Offset: 0x24c
	// Line 4299, Address: 0x1aa474, Func Offset: 0x254
	// Line 4301, Address: 0x1aa47c, Func Offset: 0x25c
	// Line 4324, Address: 0x1aa484, Func Offset: 0x264
	// Line 4325, Address: 0x1aa4a0, Func Offset: 0x280
	// Line 4328, Address: 0x1aa4d0, Func Offset: 0x2b0
	// Line 4329, Address: 0x1aa4d4, Func Offset: 0x2b4
	// Line 4333, Address: 0x1aa4e4, Func Offset: 0x2c4
	// Line 4335, Address: 0x1aa4fc, Func Offset: 0x2dc
	// Line 4339, Address: 0x1aa504, Func Offset: 0x2e4
	// Line 4340, Address: 0x1aa52c, Func Offset: 0x30c
	// Line 4339, Address: 0x1aa540, Func Offset: 0x320
	// Line 4340, Address: 0x1aa544, Func Offset: 0x324
	// Func End, Address: 0x1aa54c, Func Offset: 0x32c
    scePrintf("bhEne04_Escape - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne04_NGType00(BH_PWORK* epw)
{
    if (epw->mode3 == 0)
    {
        if (bhCdirCheck(plp->ay, epw->ay) == 0)
        {
            EXP0_I(0x10) |= 0x200;
        } 
        else
        {
            EXP0_I(0x10) &= ~0x200;
        }
    }
    bhEne04_NageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne04_NG00(BH_PWORK* epw)
{
    O_WORK* owk;
	NJS_POINT3 pos;

    switch (epw->mode3)
    {        
    case 0:
        bhEne04_ChgMtn(epw, 17, 0, 5);
        
        epw->ay = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        
        epw->flg &= ~0x40;
        
        EXP0_I(0x10) |= 0x40000;
        EXP0_I(0x10) |= 0x80000;
        
        plp->mode0 = 4;
        plp->mode1 = 0;
        plp->mode2 = 0;
        plp->mode3 = 0;
        
        epw->ct0 = 60;
        
        epw->mode3++;
        
    case 1:
        if ((epw->frm_no / 65536) == 12)
        {
            pos.x = 0.0f;
            pos.y = 0.0f;
            pos.z = -1.0f;
            njCalcPoint(&epw->mlwP->owP[5].mtx, &pos, (NJS_POINT3*)&plp->dpx);
            
            plp->djnt_no = 12;
            
            bhEne_SetBlood(plp, 1, NULL);
            
            bhEne04_SePlay(epw, 16847622);
        }
        
        if (epw->flg & 0x2000000)
        {
            bhEne04_ChgMtn(epw, 18, 0, 0);
            epw->mode3++;
            break;
        }
        break;
    case 2:
        if ((epw->frm_no / 65536) == 1)
        {
            plp->hp -= 8;
            if (plp->hp < 0)
            {
                plp->hp = 0;
            }
        }
        
        epw->ct0 -= bhEne_LeverCheck() + 1;
        
        if ((epw->ct0 < 0) && (epw->flg & 0x2000000))
        {
            bhEne04_ChgMtn(epw, 19, 0, 0);
            
            epw->mode3++;
            plp->mode3++;
            
            epw->flg |= 0x20;
            
            break;
        }
        break;
    case 3:
        if (epw->flg & 0x2000000)
        {
            njUnitMatrix(NULL);
            njTranslate(NULL, epw->px, epw->py, epw->pz);
            njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
            
            pos.x = 1.633476f;
            pos.z = -1.806519f;
            pos.y = 0.0f;
            njCalcPoint(NULL, &pos, (NJS_POINT3*)&epw->px);
            
            owk = epw->mlwP->owP;
            epw->px = owk->mtx[12];
            epw->pz = owk->mtx[14];
            
            EXP0_I(0x10) &= ~0x80000;
            
            bhEne04_ChgMtn(epw, 14, 0, 0);
            
            epw->mode3++;
            
            break;
        }
        break;
    case 4:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->flg |= 0x40;
            
            epw->mtn_add = 0;
            
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
            
            EXP0_I(0x10) |= 0x2100000;
        }
        break;
    }
}

// 100% matching!
void bhEne04_NG01(BH_PWORK* epw)
{
    O_WORK* owk;

    switch (epw->mode3)
    {
    case 0:
        epw->py = rom->grand[epw->flr_no + 2];
        
        bhEne04_ChgMtn(epw, 16, 0, 5);
        
        epw->ay = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
        
        epw->flg &= ~0x40;
        
        EXP0_I(0x10) |= 0x40000;
        EXP0_I(0x10) |= 0x80000;
        EXP0_I(0x10) &= ~0xF;
        EXP0_I(0x10) |= 2;

        plp->mode0 = 6;
        plp->mode1 = 1;
        plp->mode2 = 0;
        plp->mode3 = 0;
        epw->mode3++;

    case 1:
        if (epw->flg & 0x02000000)
        {
            owk = epw->mlwP->owP;
            epw->px = owk->mtx[12];
            epw->pz = owk->mtx[14];
            
            bhEne04_ChgMtn(epw, 25, 0, 0);
            
            EXP0_I(0x10) &= ~0x40C0000;
            
            epw->flg |= 0x20;
            
            epw->mode3++;
        }

    case 2:
        break;
    }
}

// 100% matching!
void bhEne04_DGType00(BH_PWORK* epw)
{
    bhEne04_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne04_DG00(BH_PWORK* epw) {
    int h_cnt;
	int mtn_no;

    switch (epw->mode3)
    {
    case 0:
        epw->ct0 = 0;
        bhClrUseKaidanFlag(epw);

        if (EXP0_I(0x10) & 0x400)
        {
            epw->flg &= ~0x100;
            EXP0_I(0x10) &= ~0x8400;
            epw->py += 3.8f;
            EXP0_F(0x48) = 1.0f;
            bhEne04_ChgMtn(epw, 12, 0, 5);
        }
        else if (EXP0_I(0x10) & 0x8000)
        {
            if (EXP0_I(0x10) & 0x100)
            {
                epw->spd = 0.0f;
                epw->way = -28672;
                mtn_no = 45;                
            }
            else
            {
                epw->spd = 0.0f;
                epw->way = 4096;                
                mtn_no = 44;
            }
            
            epw->mode3 = 2;

            bhEne04_ChgMtn(epw, mtn_no, 0, 5);
            EXP0_I(0x10) |= 0x40000000;
            return;
        }
        else
        {
            if (EXP0_I(0x10) & 0x100)
            {
                epw->spd = 0.0f;
                epw->way = -28672;
                mtn_no = 10;
            }
            else
            {
                epw->spd = 0.0f;
                epw->way = 4096;
                mtn_no = 11;
            }

            bhEne04_ChgMtn(epw, mtn_no, 0, 5);
            EXP0_I(0x10) &= ~0x40000000;

        }
        epw->mode3++;

    case 1:        
        if (epw->mtn_no == 12)
        {
            epw->py += (fabsf(EXP0_F(0x48)) * njSin(8192)) - 0.2f * epw->ct0;
            
            if (rom->grand[epw->flr_no + 2] > epw->py)
            {
                epw->py = rom->grand[epw->flr_no + 2];
            } 
            else
            {
                float tmp = njCos(8192); // cant find a way to match it without a variable
                epw->spd = EXP0_F(0x48) * tmp;
                bhAddSpeed(epw, 32768);
            }
            
            epw->ct0++;
        } 
        else
        {
            if (3 < (epw->frm_no / 65536))
            {
                epw->spd += (0.25f - (0.05f * epw->ct0));
                
                if (epw->spd < 0.0f)
                {
                    epw->spd = 0.0f;
                }
                
                bhAddSpeed(epw, epw->way);
                epw->ct0++;
            }
        }

        if ((epw->flg & 0x2000000) != 0)
        {
            epw->flg |= 0x100;
            h_cnt = 0;
            
            if (epw->mtn_no == 11)
            {
                epw->ay += 32768;
            } 
            else if(epw->mtn_no == 12)
            {
                h_cnt = 5; 
            }
            
            bhEne04_ChgMtn(epw, 14, 0, h_cnt);
            epw->py = rom->grand[epw->flr_no + 2];
            epw->mode3++;
        }
        break;

    case 2:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {            
            epw->mtn_add = 0;
            
            if (epw->hp < 0)
            {
                epw->mode0 = 4;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
                break;
            }
            
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
            
            EXP0_I(0x10) |= 0x2100000;
        }
        break;
    }
}

// 100% matching!
void bhEne04_DG01(BH_PWORK* epw)
{
	NJS_POINT3 p1;
	NJS_POINT3 p2;   
    float dist;
    float px;
	float pz;

    switch (epw->mode3)
    {
    case 0:
        bhClrUseKaidanFlag(epw);
        
        EXP0_I(0x10) &= ~0x40000000;
        EXP0_I(0x10) &= ~0x20000;
        EXP0_I(0x10) &= ~0x20;
        
        epw->flg2 |= 1;
        epw->ay = kaidan_ang[*(unsigned char*)((char*)EXP0_I(0x40) + 0x21)];
        epw->py = 3.8f + epw->mlwP->owP->mtx[13];
        
        if (EXP0_I(0x10) & 0x10000)
        {
            bhEne04_ChgMtn(epw, 12, 0, 5);
            px = epw->px - EXP0_F(0x30);
            pz = epw->pz - EXP0_F(0x38);
        } 
        else
        {
            epw->flr_no = bhCheckFloorNum(epw->yn);
            bhEne04_ChgMtn(epw, 39, 0, 5);
            
            njUnitMatrix(NULL);
            njTranslate(NULL, EXP0_F(0x30), EXP0_F(0x34), EXP0_F(0x38));
            njRotateXYZ(NULL, epw->ax, epw->ay, epw->az);
            
            p1.x = 0.0f;
            p1.y = -8.027999f;
            p1.z = -22.000042f;
            njCalcPoint(NULL, &p1, &p2);
            
            px = p2.x - epw->px;
            pz = p2.z - epw->pz;
        }
        
        dist = njSqrt((px * px) + (pz * pz));
        EXP0_F(0x48) = dist * 0.033333335f + 1.0f;
        
        epw->flg &= ~0x100;
        epw->ct0 = 0;
        epw->mode3++;

    case 1:
        epw->py += (fabsf(EXP0_F(0x48)) * njSin(8192)) - 0.2f * epw->ct0;
        if (rom->grand[epw->flr_no + 2] > epw->py)
        {
            epw->py = rom->grand[epw->flr_no + 2];
        } 
        else
        {
            float tmp = njCos(8192); // cant find a way to match it without a variable
            epw->spd = EXP0_F(0x48) * tmp;
            if (EXP0_I(0x10) & 0x10000)
            {
                bhAddSpeed(epw, 32768);
            } 
            else
            {
                bhAddSpeed(epw, 0);
            }
        }
        
        epw->ct0++;
        
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mtn_add = 0;
        }
        
        if ((epw->mtn_add == 0) && (epw->py == 0.0f))
        {
            epw->flg |= 0x100;
            if (!(EXP0_I(0x10) & 0x10000))
            {
                epw->ay += 32768;
            }
            bhEne04_ChgMtn(epw, 14, 0, 0);
            epw->mode3++;
            break;
        }
        break;
    case 2:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mtn_add = 0;
            epw->flg2 &= ~1;
            EXP0_I(0x10) &= ~0x30;
            
            if (epw->hp < 0)
            {
                epw->mode0 = 4;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
                break;
            }
            
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 5;
            epw->mode3 = 0;
            
            EXP0_I(0x10) |= 0x2100000;
        }
        break;
    }
}

// 100% matching!
void bhEne04_DDType00(BH_PWORK* epw)
{
    bhEne04_DieMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne04_DD00(BH_PWORK* epw)
 {
    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 2;
        
        epw->flg &= ~0x28;
        
        bhSetBloodPoolLnk(epw, (NJS_POINT3*)&epw->px, epw->ay, &en04_BldTbl, 0);
        
        epw->mode3++;
        
    case 1:
        break;
    }
}


// 
// Start address: 0x1ab450
void bhEne04_PlyDG00(BH_PWORK* pl, BH_PWORK* epw)
{
	//_anon4* owk;
	//npobj* obj;
	//_anon36 ply_ofs_pos[4];
	// Line 4960, Address: 0x1ab450, Func Offset: 0
	// Line 4974, Address: 0x1ab45c, Func Offset: 0xc
	// Line 4977, Address: 0x1ab488, Func Offset: 0x38
	// Line 4983, Address: 0x1ab48c, Func Offset: 0x3c
	// Line 4979, Address: 0x1ab494, Func Offset: 0x44
	// Line 4980, Address: 0x1ab498, Func Offset: 0x48
	// Line 4977, Address: 0x1ab49c, Func Offset: 0x4c
	// Line 4978, Address: 0x1ab4a0, Func Offset: 0x50
	// Line 4979, Address: 0x1ab4a4, Func Offset: 0x54
	// Line 4980, Address: 0x1ab4a8, Func Offset: 0x58
	// Line 4981, Address: 0x1ab4ac, Func Offset: 0x5c
	// Line 4986, Address: 0x1ab4b0, Func Offset: 0x60
	// Line 4983, Address: 0x1ab4b8, Func Offset: 0x68
	// Line 4987, Address: 0x1ab4bc, Func Offset: 0x6c
	// Line 4986, Address: 0x1ab4c4, Func Offset: 0x74
	// Line 4983, Address: 0x1ab4c8, Func Offset: 0x78
	// Line 4986, Address: 0x1ab4d0, Func Offset: 0x80
	// Line 4988, Address: 0x1ab4d4, Func Offset: 0x84
	// Line 4989, Address: 0x1ab4dc, Func Offset: 0x8c
	// Line 4986, Address: 0x1ab4e4, Func Offset: 0x94
	// Line 4987, Address: 0x1ab4e8, Func Offset: 0x98
	// Line 4991, Address: 0x1ab4ec, Func Offset: 0x9c
	// Line 4986, Address: 0x1ab4f0, Func Offset: 0xa0
	// Line 4987, Address: 0x1ab500, Func Offset: 0xb0
	// Line 4988, Address: 0x1ab50c, Func Offset: 0xbc
	// Line 4987, Address: 0x1ab510, Func Offset: 0xc0
	// Line 4988, Address: 0x1ab528, Func Offset: 0xd8
	// Line 4989, Address: 0x1ab534, Func Offset: 0xe4
	// Line 4988, Address: 0x1ab538, Func Offset: 0xe8
	// Line 4989, Address: 0x1ab550, Func Offset: 0x100
	// Line 4991, Address: 0x1ab574, Func Offset: 0x124
	// Line 4992, Address: 0x1ab578, Func Offset: 0x128
	// Line 4993, Address: 0x1ab580, Func Offset: 0x130
	// Line 4996, Address: 0x1ab588, Func Offset: 0x138
	// Line 4999, Address: 0x1ab59c, Func Offset: 0x14c
	// Line 5002, Address: 0x1ab5a8, Func Offset: 0x158
	// Line 5004, Address: 0x1ab5b8, Func Offset: 0x168
	// Line 5005, Address: 0x1ab5bc, Func Offset: 0x16c
	// Line 5006, Address: 0x1ab5c0, Func Offset: 0x170
	// Line 5007, Address: 0x1ab5e8, Func Offset: 0x198
	// Line 5009, Address: 0x1ab5f0, Func Offset: 0x1a0
	// Line 5015, Address: 0x1ab5f8, Func Offset: 0x1a8
	// Line 5016, Address: 0x1ab5fc, Func Offset: 0x1ac
	// Line 5017, Address: 0x1ab600, Func Offset: 0x1b0
	// Line 5018, Address: 0x1ab628, Func Offset: 0x1d8
	// Line 5019, Address: 0x1ab630, Func Offset: 0x1e0
	// Line 5022, Address: 0x1ab638, Func Offset: 0x1e8
	// Line 5024, Address: 0x1ab648, Func Offset: 0x1f8
	// Line 5027, Address: 0x1ab64c, Func Offset: 0x1fc
	// Line 5036, Address: 0x1ab650, Func Offset: 0x200
	// Line 5037, Address: 0x1ab654, Func Offset: 0x204
	// Line 5038, Address: 0x1ab658, Func Offset: 0x208
	// Line 5024, Address: 0x1ab65c, Func Offset: 0x20c
	// Line 5025, Address: 0x1ab660, Func Offset: 0x210
	// Line 5026, Address: 0x1ab668, Func Offset: 0x218
	// Line 5027, Address: 0x1ab670, Func Offset: 0x220
	// Line 5028, Address: 0x1ab67c, Func Offset: 0x22c
	// Line 5027, Address: 0x1ab680, Func Offset: 0x230
	// Line 5028, Address: 0x1ab684, Func Offset: 0x234
	// Line 5031, Address: 0x1ab694, Func Offset: 0x244
	// Line 5032, Address: 0x1ab69c, Func Offset: 0x24c
	// Line 5034, Address: 0x1ab6a4, Func Offset: 0x254
	// Line 5035, Address: 0x1ab6ac, Func Offset: 0x25c
	// Line 5036, Address: 0x1ab6b0, Func Offset: 0x260
	// Line 5037, Address: 0x1ab6b4, Func Offset: 0x264
	// Line 5038, Address: 0x1ab6b8, Func Offset: 0x268
	// Line 5039, Address: 0x1ab6bc, Func Offset: 0x26c
	// Line 5041, Address: 0x1ab6c0, Func Offset: 0x270
	// Line 5043, Address: 0x1ab6c8, Func Offset: 0x278
	// Line 5047, Address: 0x1ab6d0, Func Offset: 0x280
	// Line 5050, Address: 0x1ab6e4, Func Offset: 0x294
	// Line 5051, Address: 0x1ab6ec, Func Offset: 0x29c
	// Line 5060, Address: 0x1ab6f4, Func Offset: 0x2a4
	// Line 5050, Address: 0x1ab6f8, Func Offset: 0x2a8
	// Line 5056, Address: 0x1ab708, Func Offset: 0x2b8
	// Line 5059, Address: 0x1ab70c, Func Offset: 0x2bc
	// Line 5060, Address: 0x1ab710, Func Offset: 0x2c0
	// Line 5050, Address: 0x1ab714, Func Offset: 0x2c4
	// Line 5051, Address: 0x1ab724, Func Offset: 0x2d4
	// Line 5052, Address: 0x1ab730, Func Offset: 0x2e0
	// Line 5054, Address: 0x1ab73c, Func Offset: 0x2ec
	// Line 5056, Address: 0x1ab740, Func Offset: 0x2f0
	// Line 5059, Address: 0x1ab744, Func Offset: 0x2f4
	// Line 5060, Address: 0x1ab750, Func Offset: 0x300
	// Line 5064, Address: 0x1ab760, Func Offset: 0x310
	// Func End, Address: 0x1ab770, Func Offset: 0x320
    scePrintf("bhEne04_PlyDG00 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne04_PlyDG01(BH_PWORK* pl, BH_PWORK* epw)
{
	int frm;

    switch (pl->mode3)
    {
    case 0:
        if (EXP0_I(0x10) & 0x200)
        {
            pl->mtn_no = En04_PlyMtn_OffsetTbl[sys->ply_id] + 3;
            
            EXP0_F(0x30) = 0.000104f;
            EXP0_F(0x34) = 0.0f;
            EXP0_F(0x38) = -5.032532f;
            
            epw->waxp = -0x8000;
        }
        else
        {
            pl->mtn_no = En04_PlyMtn_OffsetTbl[sys->ply_id] + 4;
            
            EXP0_F(0x30) = -0.785082;
            EXP0_F(0x34) = 0;
            EXP0_F(0x38) = -4.901211;
            
            epw->waxp = 0;
        }
        EXP1_I(0) |= 0x1E0;      
        EXP1_I(0) &= ~4;
        
        pl->stflg |= 0x40000;
        pl->hp = -1;
        
        pl->flg &= ~0x40000;
        
        pl->mnwP = epw->mnwP;
        
        pl->frm_no = 0;
        
        pl->hokan_count = 5;
        
        pl->mtn_add = 0x10000;
        pl->mtn_md = 0;
        
        pl->mode3++;
        
        break;
        
    case 1:
        frm = pl->frm_no / 65536;
        if (frm == 3)
        {
            bhEne_PlayerSePlay(epw, 1025);
        }
        
        if ((EXP0_I(0x10) & 0x200))
        {
            if ((frm == 20) || (frm == 29))
            {
                bhEne04_SePlay(epw, 70408);
            }
        } 
        else if ((frm == 9) || (frm == 15) || (frm == 22))
        {
            bhEne04_SePlay(epw, 70408);
        }
        
        if ((pl->frm_no / 65536) == (pl->mnwP[pl->mtn_no].frm_num - 1))
        {
            pl->mtn_add = 0;
            
            pl->flg &= ~8;
            pl->flg |= 2;
        }
        
    case 2:
        break;
    }
}

// 
// Start address: 0x1aba10
int bhEne04_PlyDamageCheck(BH_PWORK* epw, int type)
{
	int rot;
	//_anon36 pos;
	int hit;
	//_anon47 at;
	// Line 5191, Address: 0x1aba10, Func Offset: 0
	// Line 5196, Address: 0x1aba28, Func Offset: 0x18
	// Line 5200, Address: 0x1aba64, Func Offset: 0x54
	// Line 5204, Address: 0x1aba70, Func Offset: 0x60
	// Line 5205, Address: 0x1aba90, Func Offset: 0x80
	// Line 5210, Address: 0x1aba9c, Func Offset: 0x8c
	// Line 5212, Address: 0x1abab8, Func Offset: 0xa8
	// Line 5216, Address: 0x1abac0, Func Offset: 0xb0
	// Line 5219, Address: 0x1abadc, Func Offset: 0xcc
	// Line 5222, Address: 0x1abae0, Func Offset: 0xd0
	// Line 5225, Address: 0x1abb04, Func Offset: 0xf4
	// Line 5230, Address: 0x1abb0c, Func Offset: 0xfc
	// Line 5233, Address: 0x1abb20, Func Offset: 0x110
	// Line 5230, Address: 0x1abb24, Func Offset: 0x114
	// Line 5233, Address: 0x1abb2c, Func Offset: 0x11c
	// Line 5234, Address: 0x1abb38, Func Offset: 0x128
	// Line 5236, Address: 0x1abb44, Func Offset: 0x134
	// Line 5237, Address: 0x1abb4c, Func Offset: 0x13c
	// Line 5236, Address: 0x1abb50, Func Offset: 0x140
	// Line 5238, Address: 0x1abb54, Func Offset: 0x144
	// Line 5241, Address: 0x1abb5c, Func Offset: 0x14c
	// Line 5242, Address: 0x1abb64, Func Offset: 0x154
	// Line 5241, Address: 0x1abb68, Func Offset: 0x158
	// Line 5242, Address: 0x1abb6c, Func Offset: 0x15c
	// Line 5241, Address: 0x1abb70, Func Offset: 0x160
	// Line 5244, Address: 0x1abb78, Func Offset: 0x168
	// Line 5247, Address: 0x1abb94, Func Offset: 0x184
	// Line 5249, Address: 0x1abb9c, Func Offset: 0x18c
	// Line 5250, Address: 0x1abba4, Func Offset: 0x194
	// Line 5251, Address: 0x1abba8, Func Offset: 0x198
	// Line 5249, Address: 0x1abbac, Func Offset: 0x19c
	// Line 5250, Address: 0x1abbb0, Func Offset: 0x1a0
	// Line 5249, Address: 0x1abbb4, Func Offset: 0x1a4
	// Line 5250, Address: 0x1abbbc, Func Offset: 0x1ac
	// Line 5251, Address: 0x1abbc4, Func Offset: 0x1b4
	// Line 5252, Address: 0x1abbd0, Func Offset: 0x1c0
	// Line 5253, Address: 0x1abbd8, Func Offset: 0x1c8
	// Line 5254, Address: 0x1abbf0, Func Offset: 0x1e0
	// Line 5256, Address: 0x1abbfc, Func Offset: 0x1ec
	// Line 5257, Address: 0x1abc00, Func Offset: 0x1f0
	// Func End, Address: 0x1abc18, Func Offset: 0x208
    scePrintf("bhEne04_PlyDamageCheck - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne04_SpeedUp(float* spd, float g, float limit)
{
    if (*spd < limit)
    {
        *spd += g;       
        if (*spd > limit)
        {
            *spd = limit;
        }
    }
}

// 100% matching!
void bhEne04_SpeedDown(float* spd, float g, float limit)
{
    if (*spd > limit)
    {
        *spd -= g;       
        if (*spd < limit)
        {
            *spd = limit;
        }
    }
}

// 100% matching!
void bhEne04_RunMotion(BH_PWORK* epw, int rot)
{    
    int mtn_tbl[3] = { 3, 1, 2 };     
    int mtn_tbl2[3] = { 41, 34, 40 }; 
	int no;                          
    int idx;                          // not from DWARF

    if (EXP0_I(0x10) & 0x8000)
    {        
        if (rot != 0)
        {
            idx = (rot > 0) ? 0 : 2;
        }
        else
        {
            idx = 1;
        }
        no = mtn_tbl2[idx];
    }
    else
    {
        if (rot != 0) 
        {
            idx = (rot > 0) ? 0 : 2;
        }
        else
        {
            idx = 1;
        }
        no = mtn_tbl[idx];
    }

    if (epw->mtn_no != no)
    {
        epw->mtn_no = no;

        if (epw->hokan_count < 8)
        {
            epw->hokan_count = 7;
            epw->hokan_rate = 0;
            epw->mtn_md = 32;
        }
    }
}

// 100% matching!
int bhEne04_ChgMtn(BH_PWORK* epw, unsigned int no, int frm, int rate)
{
    epw->mtn_add = 65536; 
    if (epw->mtn_no != no)
    {
        epw->mtn_no = no;
        epw->frm_no = frm;            
        epw->hokan_count = rate;
        epw->hokan_rate = 32768;            
        epw->mtn_md = 0;    
        epw->flg &= ~0x40000;
        epw->flg &= ~0x2000000;         
        return 0;
    }

    return -1;
}

// 
// Start address: 0x1abe10
int bhEne04_SetMtn(BH_PWORK* epw)
{
	//_anon36 pos;
	int frm;
	int ret;
	//npobj* obj;
	// Line 5429, Address: 0x1abe10, Func Offset: 0
	// Line 5435, Address: 0x1abe28, Func Offset: 0x18
	// Line 5436, Address: 0x1abe2c, Func Offset: 0x1c
	// Line 5437, Address: 0x1abe40, Func Offset: 0x30
	// Line 5436, Address: 0x1abe44, Func Offset: 0x34
	// Line 5437, Address: 0x1abe48, Func Offset: 0x38
	// Line 5439, Address: 0x1abe5c, Func Offset: 0x4c
	// Line 5441, Address: 0x1abe60, Func Offset: 0x50
	// Line 5439, Address: 0x1abe6c, Func Offset: 0x5c
	// Line 5440, Address: 0x1abe70, Func Offset: 0x60
	// Line 5441, Address: 0x1abe74, Func Offset: 0x64
	// Line 5445, Address: 0x1abe7c, Func Offset: 0x6c
	// Line 5446, Address: 0x1abe84, Func Offset: 0x74
	// Line 5448, Address: 0x1abe98, Func Offset: 0x88
	// Line 5450, Address: 0x1abeac, Func Offset: 0x9c
	// Line 5453, Address: 0x1abebc, Func Offset: 0xac
	// Line 5459, Address: 0x1abf44, Func Offset: 0x134
	// Line 5460, Address: 0x1abf48, Func Offset: 0x138
	// Line 5461, Address: 0x1abf4c, Func Offset: 0x13c
	// Line 5462, Address: 0x1abf54, Func Offset: 0x144
	// Line 5463, Address: 0x1abf58, Func Offset: 0x148
	// Line 5462, Address: 0x1abf60, Func Offset: 0x150
	// Line 5463, Address: 0x1abf64, Func Offset: 0x154
	// Line 5464, Address: 0x1abf70, Func Offset: 0x160
	// Line 5467, Address: 0x1abf94, Func Offset: 0x184
	// Line 5469, Address: 0x1abfa4, Func Offset: 0x194
	// Line 5472, Address: 0x1abfb0, Func Offset: 0x1a0
	// Line 5479, Address: 0x1abfb4, Func Offset: 0x1a4
	// Line 5472, Address: 0x1abfb8, Func Offset: 0x1a8
	// Line 5479, Address: 0x1abfc0, Func Offset: 0x1b0
	// Line 5481, Address: 0x1abfc8, Func Offset: 0x1b8
	// Line 5482, Address: 0x1abfd0, Func Offset: 0x1c0
	// Line 5485, Address: 0x1abfdc, Func Offset: 0x1cc
	// Line 5486, Address: 0x1abfe4, Func Offset: 0x1d4
	// Line 5487, Address: 0x1abfec, Func Offset: 0x1dc
	// Line 5489, Address: 0x1abff8, Func Offset: 0x1e8
	// Line 5492, Address: 0x1ac004, Func Offset: 0x1f4
	// Line 5499, Address: 0x1ac008, Func Offset: 0x1f8
	// Line 5492, Address: 0x1ac00c, Func Offset: 0x1fc
	// Line 5499, Address: 0x1ac014, Func Offset: 0x204
	// Line 5500, Address: 0x1ac01c, Func Offset: 0x20c
	// Line 5503, Address: 0x1ac024, Func Offset: 0x214
	// Line 5505, Address: 0x1ac02c, Func Offset: 0x21c
	// Line 5506, Address: 0x1ac034, Func Offset: 0x224
	// Line 5508, Address: 0x1ac040, Func Offset: 0x230
	// Line 5510, Address: 0x1ac044, Func Offset: 0x234
	// Line 5508, Address: 0x1ac048, Func Offset: 0x238
	// Line 5509, Address: 0x1ac04c, Func Offset: 0x23c
	// Line 5510, Address: 0x1ac050, Func Offset: 0x240
	// Line 5512, Address: 0x1ac058, Func Offset: 0x248
	// Line 5513, Address: 0x1ac05c, Func Offset: 0x24c
	// Line 5514, Address: 0x1ac068, Func Offset: 0x258
	// Line 5517, Address: 0x1ac070, Func Offset: 0x260
	// Line 5519, Address: 0x1ac078, Func Offset: 0x268
	// Line 5520, Address: 0x1ac080, Func Offset: 0x270
	// Line 5522, Address: 0x1ac08c, Func Offset: 0x27c
	// Line 5524, Address: 0x1ac090, Func Offset: 0x280
	// Line 5522, Address: 0x1ac094, Func Offset: 0x284
	// Line 5523, Address: 0x1ac098, Func Offset: 0x288
	// Line 5524, Address: 0x1ac09c, Func Offset: 0x28c
	// Line 5526, Address: 0x1ac0a4, Func Offset: 0x294
	// Line 5527, Address: 0x1ac0a8, Func Offset: 0x298
	// Line 5528, Address: 0x1ac0b4, Func Offset: 0x2a4
	// Line 5531, Address: 0x1ac0bc, Func Offset: 0x2ac
	// Line 5533, Address: 0x1ac0c4, Func Offset: 0x2b4
	// Line 5534, Address: 0x1ac0cc, Func Offset: 0x2bc
	// Line 5537, Address: 0x1ac0dc, Func Offset: 0x2cc
	// Line 5538, Address: 0x1ac0e4, Func Offset: 0x2d4
	// Line 5539, Address: 0x1ac0e8, Func Offset: 0x2d8
	// Line 5540, Address: 0x1ac0f0, Func Offset: 0x2e0
	// Line 5542, Address: 0x1ac0fc, Func Offset: 0x2ec
	// Line 5544, Address: 0x1ac100, Func Offset: 0x2f0
	// Line 5542, Address: 0x1ac104, Func Offset: 0x2f4
	// Line 5543, Address: 0x1ac108, Func Offset: 0x2f8
	// Line 5544, Address: 0x1ac10c, Func Offset: 0x2fc
	// Line 5546, Address: 0x1ac114, Func Offset: 0x304
	// Line 5547, Address: 0x1ac118, Func Offset: 0x308
	// Line 5548, Address: 0x1ac124, Func Offset: 0x314
	// Line 5551, Address: 0x1ac12c, Func Offset: 0x31c
	// Line 5553, Address: 0x1ac134, Func Offset: 0x324
	// Line 5554, Address: 0x1ac13c, Func Offset: 0x32c
	// Line 5557, Address: 0x1ac148, Func Offset: 0x338
	// Line 5559, Address: 0x1ac158, Func Offset: 0x348
	// Line 5560, Address: 0x1ac160, Func Offset: 0x350
	// Line 5562, Address: 0x1ac16c, Func Offset: 0x35c
	// Line 5564, Address: 0x1ac170, Func Offset: 0x360
	// Line 5562, Address: 0x1ac178, Func Offset: 0x368
	// Line 5563, Address: 0x1ac17c, Func Offset: 0x36c
	// Line 5564, Address: 0x1ac188, Func Offset: 0x378
	// Line 5569, Address: 0x1ac18c, Func Offset: 0x37c
	// Line 5571, Address: 0x1ac198, Func Offset: 0x388
	// Line 5572, Address: 0x1ac19c, Func Offset: 0x38c
	// Func End, Address: 0x1ac1b4, Func Offset: 0x3a4
    scePrintf("bhEne04_SetMtn - UNIMPLEMENTED!\n");
}
/*
// 
// Start address: 0x1ac1c0
void bhEne04_CheckMtnTbl(BH_PWORK* epw, int frm)
{
	int i;
	_anon32* mtbl2;
	_anon32* mtbl;
	// Line 5591, Address: 0x1ac1c0, Func Offset: 0
	// Line 5596, Address: 0x1ac1e0, Func Offset: 0x20
	// Line 5593, Address: 0x1ac1ec, Func Offset: 0x2c
	// Line 5596, Address: 0x1ac1f0, Func Offset: 0x30
	// Line 5592, Address: 0x1ac1f4, Func Offset: 0x34
	// Line 5596, Address: 0x1ac1fc, Func Offset: 0x3c
	// Line 5601, Address: 0x1ac21c, Func Offset: 0x5c
	// Line 5603, Address: 0x1ac228, Func Offset: 0x68
	// Line 5605, Address: 0x1ac230, Func Offset: 0x70
	// Line 5607, Address: 0x1ac240, Func Offset: 0x80
	// Line 5609, Address: 0x1ac248, Func Offset: 0x88
	// Line 5610, Address: 0x1ac254, Func Offset: 0x94
	// Line 5611, Address: 0x1ac258, Func Offset: 0x98
	// Line 5613, Address: 0x1ac268, Func Offset: 0xa8
	// Line 5614, Address: 0x1ac26c, Func Offset: 0xac
	// Line 5616, Address: 0x1ac280, Func Offset: 0xc0
	// Line 5619, Address: 0x1ac290, Func Offset: 0xd0
	// Line 5621, Address: 0x1ac298, Func Offset: 0xd8
	// Line 5623, Address: 0x1ac2a4, Func Offset: 0xe4
	// Line 5625, Address: 0x1ac2b0, Func Offset: 0xf0
	// Line 5627, Address: 0x1ac2c0, Func Offset: 0x100
	// Line 5629, Address: 0x1ac2c8, Func Offset: 0x108
	// Line 5631, Address: 0x1ac2d0, Func Offset: 0x110
	// Line 5633, Address: 0x1ac2e0, Func Offset: 0x120
	// Line 5634, Address: 0x1ac2e4, Func Offset: 0x124
	// Line 5636, Address: 0x1ac2f8, Func Offset: 0x138
	// Func End, Address: 0x1ac31c, Func Offset: 0x15c
}
*/
// 100% matching!
int bhEne04_KaidanCheck(BH_PWORK* epw)
{
    ATR_WORK* hp;
    BH_PWORK* ep;
    int i;
	int idx;
    
    ep = ene;
    if (plp->stflg & 0x80000000)
    {
        return 0;
    }
   
    for (i = 0; i < sys->ewk_n; i++, ep++)
    {
        if (ep->id == 4 &&
            (ep->flg & 1) &&
            !(ep->flg & 2) &&
            ep->exp0 != NULL &&
            ep != epw &&
            (EP_EXP0_I(0x10) & 0x20000))
        {
            return 0;
        }
    }

    hp = bhKaidanAtrCheck(epw, 7.0f, &idx);

    if (hp != NULL) 
    {
        if (hp->prm2 != 4)
        {
            return 0;
        }
        if (hp->prm0 == 0)
        {
            if (plp->flr_no > epw->flr_no)
            {
                EXP0_I(0x40) = (int)hp;
                bhSetUseKaidanFlag(epw, hp, idx);
                return 1;
            }
        } 
        else if (plp->flr_no < epw->flr_no)
        {
            EXP0_I(0x40) = (int)hp;
            bhSetUseKaidanFlag(epw, hp, idx);
            return 1;
        }
    }
    return 0;
}

// 100% matching!
void bhEne04_ShakeWire(O_WRK* obwp)
{
    NJS_POINT3 pos[10] =
    {
        { 0.0f,   0.1f,   0.05f },
        { 0.0f,  -0.1f,   0.1f  },
        { 0.0f,   0.1f,   0.35f },
        { 0.0f,  -0.1f,   0.0f  },
        { 0.0f,   0.1f,   0.0f  },   
        { 0.0f,  -0.1f,  -0.2f  },   
        { 0.0f,   0.1f,  -0.15f }, 
        { 0.0f,  -0.1f,  -0.1f  },
        { 0.0f,   0.1f,  -0.05f },
        { 0.0f,  -0.1f,   0.0f  }
    };
    
    switch (obwp->mode3)
    {
    case 0:
        obwp->ct0 = 0;
        obwp->mode1 = 1;
        obwp->mode3++;
    case 1:
        obwp->py += pos[obwp->ct0].y;
        
        obwp->px -= pos[obwp->ct0].z * njSin(obwp->ay + obwp->ayp);
        obwp->pz -= pos[obwp->ct0].z * njCos(obwp->ay + obwp->ayp);

        obwp->ct0++;

        if (obwp->ct0 >= 10) {
            obwp->mode3++;
            obwp->flg2 &= ~1;
        }
        break;

    case 2:
        obwp->mode1 = 0;
    }
}

// 100% matching!
void bhEne04_RotNeck(BH_PWORK* epw, int rx, int ry, int rz) // signature differs from DWARF
{ 
    NJS_CNK_OBJECT* obj;

    obj = epw->mlwP->objP;
    obj[2].ang[1] = ry;
    obj[3].ang[1] = (ry + (ry / 4));
    obj[4].ang[1] = (ry + (ry / 2));
}

// 100% matching!
int bhEne04_SearchNeck(BH_PWORK* epw)
{
    int rot;
    int rot2;
    int d_tmp;
    int lim;
   
    lim = 0;
    bhEne04_RotNeck(epw, 0, EXP0_I(0x1C), 0); // signature differs from DWARF
    rot = epw->ay + EXP0_I(0x1C);
    d_tmp = NitenDir_ck(epw->px, epw->pz, plp->px, plp->pz);
    rot2 = ((d_tmp - rot) + 512) & 0xFFFF;
    
    if (1024 < rot2)
    {
        if (32768 >= rot2)
        {
            EXP0_I(0x1C) += 256;
        }
        else
        {
            EXP0_I(0x1C) -= 256;
        }
    }

    if (EXP0_I(0x1C) < -4096)
    {
        lim = 1;
        EXP0_I(0x1C) = -4096;
    }

    if (4096 < EXP0_I(0x1C))
    {
        EXP0_I(0x1C) = 4096;
        lim = 1;
    }
    return lim;
}

// 100% matching!
void bhEne04_SePlay(BH_PWORK* epw, int no)
{
    if (!(epw->flg & 0x10000))
    {
        RequestEnemySe(sys->enow, (NJS_POINT3*)&epw->px, no);
    }
}
