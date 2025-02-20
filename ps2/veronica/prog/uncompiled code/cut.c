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

typedef void(*type_83)(void*);

typedef float type_0[16];
typedef unsigned int type_1[4];
typedef _anon0* type_2[512];
typedef _anon0* type_3[32];
typedef _anon1* type_4[16];
typedef _anon0* type_5[32];
typedef _anon0* type_6[512];
typedef _anon1* type_7[16][16];
typedef _anon1* type_8[16][16][100];
typedef char type_9[8];
typedef _anon0* type_10[32];
typedef float type_11[3];
typedef _anon0* type_12[512];
typedef _anon1* type_13[1300];
typedef char type_14[32];
typedef float type_15[32];
typedef _anon0* type_16[512];
typedef _anon1* type_17[200];
typedef short type_18[32];
typedef _anon23 type_19[1];
typedef _anon0* type_20[128];
typedef unsigned int type_21[1];
typedef _anon6 type_22[256];
typedef _anon1* type_23[8];
typedef int* type_24[16];
typedef _anon0* type_25[128];
typedef _anon17 type_26[16];
typedef npobj* type_27[16];
typedef _anon0* type_28[128];
typedef int type_29[4];
typedef _anon1* type_30[16];
typedef unsigned int type_31[4];
typedef float type_32[4];
typedef _anon11 type_33[16];
typedef _anon0* type_34[512];
typedef float type_35[4];
typedef char type_36[256];
typedef float type_37[4];
typedef float type_38[4];
typedef float type_39[4];
typedef float type_40[4];
typedef _anon4* type_41[128];
typedef float type_42[3];
typedef unsigned char type_43[64];
typedef float type_44[3][20];
typedef float type_45[3];
typedef float type_46[3][20];
typedef float type_47[3];
typedef float type_48[3][20];
typedef char type_49[8];
typedef float type_50[3];
typedef float type_51[3][20];
typedef void* type_52[2];
typedef _anon1* type_53[256];
typedef int type_54[4];
typedef unsigned char* type_55[256];
typedef unsigned int type_56[2];
typedef short type_57[256];
typedef _anon31 type_58[4];
typedef float type_59[3];
typedef short type_60[256];
typedef int type_61[3];
typedef int type_62[8];
typedef float type_63[3];
typedef _anon1* type_64[256];
typedef _anon8 type_65[256];
typedef _anon23 type_66[450];
typedef _anon33 type_67[16];
typedef short type_68[256];
typedef char type_69[3];
typedef int type_70[64];
typedef _anon11 type_71[450];
typedef unsigned int type_72[16];
typedef char type_73[4];
typedef unsigned int type_74[8];
typedef _anon36 type_75[4];
typedef _anon2 type_76[4];
typedef int type_77[450];
typedef unsigned int type_78[8];
typedef unsigned char type_79[450];
typedef float type_80[128];
typedef char type_81[16];
typedef char type_82[4];
typedef unsigned int type_84[32];
typedef _anon21 type_85[2];
typedef BH_PWORK type_86[0];
typedef unsigned char type_87[256];
typedef unsigned int type_88[16];
typedef _anon19 type_89[64];
typedef unsigned int type_90[16];
typedef _anon0 type_91[0];
typedef _anon19 type_92[64];
typedef unsigned int type_93[32];
typedef _anon19 type_94[64];
typedef unsigned int type_95[16];
typedef unsigned int type_96[3];
typedef BH_PWORK* type_97[16];
typedef unsigned int type_98[8];
typedef unsigned int type_99[1];
typedef unsigned int type_100[384];
typedef unsigned int type_101[2];
typedef unsigned char type_102[2];
typedef unsigned int type_103[4];
typedef int* type_104[16];
typedef char type_105[32];
typedef npobj* type_106[16];
typedef char type_107[64];
typedef _anon1* type_108[16];
typedef char type_109[4];
typedef _anon11 type_110[16];
typedef short type_111[4];
typedef unsigned char type_112[4];
typedef _anon34 type_113[16];
typedef unsigned int type_114[8];
typedef unsigned int type_115[32];
typedef unsigned int type_116[4];
typedef _anon28 type_117[32];
typedef _anon0* type_118[512];
typedef _anon0* type_119[128];
typedef _anon0* type_120[512];
typedef unsigned char type_121[64];
typedef _anon0* type_122[512];

struct npobj
{
	unsigned int evalflags;
	_anon32* model;
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
	_anon1* txp[16];
	_anon11 mdl[16];
	_anon11* mlwP;
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
	_anon4* mnwP;
	_anon4* mnwPb;
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
	_anon42 cspr;
	int pn;
	_anon36* pvp;
	_anon2* tvp;
	_anon36 pv[4];
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
	_anon11 mdl[16];
	_anon11* mlwP;
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
	_anon4* mnwP;
	_anon4* mnwPb;
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
	_anon43 watr;
	_anon24* cpcl;
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
	_anon23* textures;
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
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon22* md2P;
	unsigned short* atrP;
};

struct _anon5
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon17 keyf[16];
};

struct _anon6
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon7
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

struct _anon8
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon9
{
	_anon10* cutp;
	_anon14* lgtp;
	_anon15* enep;
	_anon15* objp;
	_anon15* itmp;
	_anon18* effp;
	_anon19* walp;
	_anon19* etcp;
	_anon19* flrp;
	_anon3* posp;
	_anon19* rutp;
	unsigned char* ruttp;
	_anon26* evtp;
	_anon5* evcp;
	unsigned int* mesp;
	_anon14* evlp;
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
	_anon11 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};

struct _anon10
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon13* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon21 cam[2];
	unsigned char exd[256];
};

struct _anon11
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon29* owP;
};

struct _anon12
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
	_anon40* info;
};

struct _anon13
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

struct _anon14
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
	_anon30* light;
};

struct _anon15
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

struct _anon16
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

struct _anon17
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

struct _anon18
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

struct _anon19
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

struct _anon20
{
	void* texaddr;
	_anon7 texsurface;
};

struct _anon21
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

struct _anon22
{
	void* p[2];
};

struct _anon23
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon24
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon25
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
	_anon28 ply_pos;
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
	_anon12* p1per;
	_anon12* p2per;
	_anon12* kbper;
	_anon12* msper;
	_anon12 ms_per;
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
	_anon4* emtp[128];
	_anon4* rmthp;
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
	_anon8 txbp[256];
	unsigned char* ef_psp;
	_anon23 ef_tex[450];
	_anon1 ef_tlist;
	_anon37 ef;
	short efid[256];
	_anon11 efm[450];
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
	_anon20 ren_info;
	_anon23 ren_tex[1];
	_anon1 ren_tlist;
	_anon6 rpb[256];
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
	_anon39 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon14* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon31 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon33 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon19* pl_htp;
	int costume;
	_anon28 hd_pos;
	_anon28 apos;
	_anon19* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon19 mwalp[64];
	_anon19 metcp[64];
	_anon19 mflrp[64];
	int dla_n;
	_anon19* htp;
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
	_anon16 door;
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
	_anon28 ufo_pos;
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
	_anon34 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon28 ghtp[32];
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

struct _anon26
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon27
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon28
{
	float x;
	float y;
	float z;
};

struct _anon29
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon30
{
	float mtrx[16];
	_anon28 pnt;
	_anon28 vctr;
	int stat;
	int reserve;
	_anon35 ltcal;
	_anon41 attr;
};

struct _anon31
{
	_anon28 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon32
{
	int* vlist;
	short* plist;
	_anon28 center;
	float r;
};

struct _anon33
{
	float x;
	float y;
};

struct _anon34
{
	_anon28 c1;
	_anon28 c2;
	float r1;
	float r2;
};

struct _anon35
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
	_anon28 lpnt;
	_anon28 lvctr;
	_anon28 lmvctr;
	_anon27 atten;
	_anon27 amb;
	_anon27 dif;
	_anon27 spc;
	_anon27 mamb;
	_anon27 mdif;
	_anon27 mspc;
};

struct _anon36
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon37
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

struct _anon38
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

struct _anon39
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon40
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

struct _anon41
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
	_anon27 argb;
};

struct _anon42
{
	_anon28 c;
	float r;
};

struct _anon43
{
	_anon28 c1;
	_anon28 c2;
	float r;
};

_anon38 cam;
_anon9* rom;
BH_PWORK* plp;
_anon25* sys;
_anon0 eff[0];
BH_PWORK ene[0];

void bhCheckCut(int flg);
int bhCheckCutArea(float px, float pz, char flr_no);
int bhCheckCutAreaInnerTriangle(float px, float pz, _anon13* ct);
unsigned int bhCheckCutAttribute(float px, float pz, int flr_no);
void bhSetCut(int cno, int flg);
void bhSetFixedCut(int cno);
void bhSetRenderCut(int cno);
void bhSetHideObjLgt(int cno);
void bhSetHideObject(int offset);
void bhInitActiveCamera(int flg);
void bhCheckNearAttrOffCutRange(_anon10* cp, unsigned int sft, float* px, float* pz);
void bhControlActiveCamera();
void bhSetEventCamera(int evc_no, int key_no);
void bhSetEventFixedCut(int cno, int kno);
void bhSetEventHideObjLgt(int cno, int kno);
void bhInitEventCamera();
void bhControlEventCamera();
void bhCheckEvtCamLockPosition();
void bhGetEvtCamLockPosition(_anon17* kfp, _anon28* pos);
void bhControlPlEyeCamera(unsigned int attr);
void bhInitPlEyeCamera();
void bhSetPlEyeCamera();
void bhControlMonitorCamera();
float bhCalcActiveYpos(_anon10* cp);
short bhCalcActiveZang(_anon10* cp);
short bhCalcActivePers(_anon10* cp);

// 
// Start address: 0x27a2d0
void bhCheckCut(int flg)
{
	int p3;
	int p2;
	int p1;
	int p0;
	int pp;
	float gpz;
	float gpx;
	// Line 112, Address: 0x27a2d0, Func Offset: 0
	// Line 116, Address: 0x27a2f0, Func Offset: 0x20
	// Line 142, Address: 0x27a300, Func Offset: 0x30
	// Line 116, Address: 0x27a304, Func Offset: 0x34
	// Line 142, Address: 0x27a30c, Func Offset: 0x3c
	// Line 143, Address: 0x27a320, Func Offset: 0x50
	// Line 144, Address: 0x27a330, Func Offset: 0x60
	// Line 145, Address: 0x27a340, Func Offset: 0x70
	// Line 146, Address: 0x27a348, Func Offset: 0x78
	// Line 147, Address: 0x27a350, Func Offset: 0x80
	// Line 146, Address: 0x27a358, Func Offset: 0x88
	// Line 147, Address: 0x27a360, Func Offset: 0x90
	// Line 148, Address: 0x27a378, Func Offset: 0xa8
	// Line 149, Address: 0x27a384, Func Offset: 0xb4
	// Line 148, Address: 0x27a390, Func Offset: 0xc0
	// Line 149, Address: 0x27a398, Func Offset: 0xc8
	// Line 150, Address: 0x27a3a0, Func Offset: 0xd0
	// Line 149, Address: 0x27a3a4, Func Offset: 0xd4
	// Line 150, Address: 0x27a3ac, Func Offset: 0xdc
	// Line 153, Address: 0x27a3bc, Func Offset: 0xec
	// Line 155, Address: 0x27a3e8, Func Offset: 0x118
	// Line 156, Address: 0x27a3ec, Func Offset: 0x11c
	// Line 157, Address: 0x27a3f4, Func Offset: 0x124
	// Line 156, Address: 0x27a3f8, Func Offset: 0x128
	// Line 157, Address: 0x27a3fc, Func Offset: 0x12c
	// Line 159, Address: 0x27a408, Func Offset: 0x138
	// Line 165, Address: 0x27a410, Func Offset: 0x140
	// Line 162, Address: 0x27a414, Func Offset: 0x144
	// Line 159, Address: 0x27a41c, Func Offset: 0x14c
	// Line 160, Address: 0x27a428, Func Offset: 0x158
	// Line 161, Address: 0x27a434, Func Offset: 0x164
	// Line 162, Address: 0x27a440, Func Offset: 0x170
	// Line 163, Address: 0x27a44c, Func Offset: 0x17c
	// Line 164, Address: 0x27a458, Func Offset: 0x188
	// Line 163, Address: 0x27a45c, Func Offset: 0x18c
	// Line 164, Address: 0x27a464, Func Offset: 0x194
	// Line 165, Address: 0x27a468, Func Offset: 0x198
	// Line 166, Address: 0x27a46c, Func Offset: 0x19c
	// Line 169, Address: 0x27a474, Func Offset: 0x1a4
	// Line 171, Address: 0x27a47c, Func Offset: 0x1ac
	// Line 172, Address: 0x27a484, Func Offset: 0x1b4
	// Line 173, Address: 0x27a48c, Func Offset: 0x1bc
	// Line 172, Address: 0x27a494, Func Offset: 0x1c4
	// Line 173, Address: 0x27a49c, Func Offset: 0x1cc
	// Line 174, Address: 0x27a4b4, Func Offset: 0x1e4
	// Line 175, Address: 0x27a4c0, Func Offset: 0x1f0
	// Line 174, Address: 0x27a4cc, Func Offset: 0x1fc
	// Line 175, Address: 0x27a4d4, Func Offset: 0x204
	// Line 176, Address: 0x27a4dc, Func Offset: 0x20c
	// Line 175, Address: 0x27a4e0, Func Offset: 0x210
	// Line 176, Address: 0x27a4e8, Func Offset: 0x218
	// Line 178, Address: 0x27a4f8, Func Offset: 0x228
	// Line 179, Address: 0x27a500, Func Offset: 0x230
	// Line 178, Address: 0x27a508, Func Offset: 0x238
	// Line 179, Address: 0x27a510, Func Offset: 0x240
	// Line 180, Address: 0x27a520, Func Offset: 0x250
	// Line 181, Address: 0x27a534, Func Offset: 0x264
	// Line 182, Address: 0x27a544, Func Offset: 0x274
	// Line 183, Address: 0x27a598, Func Offset: 0x2c8
	// Line 184, Address: 0x27a5a0, Func Offset: 0x2d0
	// Line 185, Address: 0x27a5b4, Func Offset: 0x2e4
	// Line 184, Address: 0x27a5b8, Func Offset: 0x2e8
	// Line 185, Address: 0x27a5bc, Func Offset: 0x2ec
	// Line 186, Address: 0x27a5d4, Func Offset: 0x304
	// Line 188, Address: 0x27a5fc, Func Offset: 0x32c
	// Line 189, Address: 0x27a604, Func Offset: 0x334
	// Line 190, Address: 0x27a608, Func Offset: 0x338
	// Line 192, Address: 0x27a610, Func Offset: 0x340
	// Line 193, Address: 0x27a614, Func Offset: 0x344
	// Line 195, Address: 0x27a61c, Func Offset: 0x34c
	// Line 196, Address: 0x27a638, Func Offset: 0x368
	// Line 197, Address: 0x27a65c, Func Offset: 0x38c
	// Line 198, Address: 0x27a680, Func Offset: 0x3b0
	// Line 199, Address: 0x27a6a0, Func Offset: 0x3d0
	// Line 203, Address: 0x27a6c8, Func Offset: 0x3f8
	// Line 204, Address: 0x27a6d0, Func Offset: 0x400
	// Line 205, Address: 0x27a728, Func Offset: 0x458
	// Line 206, Address: 0x27a730, Func Offset: 0x460
	// Line 210, Address: 0x27a740, Func Offset: 0x470
	// Line 211, Address: 0x27a760, Func Offset: 0x490
	// Line 212, Address: 0x27a768, Func Offset: 0x498
	// Line 213, Address: 0x27a798, Func Offset: 0x4c8
	// Line 214, Address: 0x27a7a8, Func Offset: 0x4d8
	// Line 215, Address: 0x27a7b8, Func Offset: 0x4e8
	// Line 218, Address: 0x27a7c0, Func Offset: 0x4f0
	// Func End, Address: 0x27a7e4, Func Offset: 0x514
}

// 
// Start address: 0x27a7f0
int bhCheckCutArea(float px, float pz, char flr_no)
{
	int j;
	int i;
	_anon13* ct;
	_anon10* cp;
	// Line 229, Address: 0x27a7f0, Func Offset: 0
	// Line 233, Address: 0x27a814, Func Offset: 0x24
	// Line 234, Address: 0x27a830, Func Offset: 0x40
	// Line 235, Address: 0x27a838, Func Offset: 0x48
	// Line 236, Address: 0x27a848, Func Offset: 0x58
	// Line 237, Address: 0x27a84c, Func Offset: 0x5c
	// Line 238, Address: 0x27a854, Func Offset: 0x64
	// Line 239, Address: 0x27a860, Func Offset: 0x70
	// Line 241, Address: 0x27a86c, Func Offset: 0x7c
	// Line 244, Address: 0x27a8bc, Func Offset: 0xcc
	// Line 247, Address: 0x27a8c4, Func Offset: 0xd4
	// Line 250, Address: 0x27a8e4, Func Offset: 0xf4
	// Line 252, Address: 0x27a900, Func Offset: 0x110
	// Line 253, Address: 0x27a920, Func Offset: 0x130
	// Line 254, Address: 0x27a924, Func Offset: 0x134
	// Func End, Address: 0x27a94c, Func Offset: 0x15c
}

// 
// Start address: 0x27a950
int bhCheckCutAreaInnerTriangle(float px, float pz, _anon13* ct)
{
	float d;
	// Line 266, Address: 0x27a950, Func Offset: 0
	// Line 271, Address: 0x27a964, Func Offset: 0x14
	// Line 272, Address: 0x27a9b4, Func Offset: 0x64
	// Line 274, Address: 0x27a9c0, Func Offset: 0x70
	// Line 276, Address: 0x27a9fc, Func Offset: 0xac
	// Line 277, Address: 0x27aa00, Func Offset: 0xb0
	// Line 278, Address: 0x27aa04, Func Offset: 0xb4
	// Line 280, Address: 0x27aa08, Func Offset: 0xb8
	// Line 282, Address: 0x27aa10, Func Offset: 0xc0
	// Line 283, Address: 0x27aa14, Func Offset: 0xc4
	// Line 284, Address: 0x27aa18, Func Offset: 0xc8
	// Line 286, Address: 0x27aa1c, Func Offset: 0xcc
	// Line 288, Address: 0x27aa24, Func Offset: 0xd4
	// Line 289, Address: 0x27aa28, Func Offset: 0xd8
	// Line 290, Address: 0x27aa2c, Func Offset: 0xdc
	// Line 292, Address: 0x27aa30, Func Offset: 0xe0
	// Line 294, Address: 0x27aa38, Func Offset: 0xe8
	// Line 295, Address: 0x27aa3c, Func Offset: 0xec
	// Line 296, Address: 0x27aa40, Func Offset: 0xf0
	// Line 297, Address: 0x27aa44, Func Offset: 0xf4
	// Line 303, Address: 0x27aa48, Func Offset: 0xf8
	// Line 301, Address: 0x27aa54, Func Offset: 0x104
	// Line 303, Address: 0x27aa58, Func Offset: 0x108
	// Line 304, Address: 0x27aa74, Func Offset: 0x124
	// Line 306, Address: 0x27aaa0, Func Offset: 0x150
	// Func End, Address: 0x27aab8, Func Offset: 0x168
}

// 
// Start address: 0x27aac0
unsigned int bhCheckCutAttribute(float px, float pz, int flr_no)
{
	int j;
	int i;
	_anon13* ct;
	_anon10* cp;
	// Line 321, Address: 0x27aac0, Func Offset: 0
	// Line 322, Address: 0x27aac8, Func Offset: 0x8
	// Line 321, Address: 0x27aad0, Func Offset: 0x10
	// Line 322, Address: 0x27aad4, Func Offset: 0x14
	// Line 323, Address: 0x27aae0, Func Offset: 0x20
	// Line 324, Address: 0x27aaf8, Func Offset: 0x38
	// Line 325, Address: 0x27aafc, Func Offset: 0x3c
	// Line 326, Address: 0x27ab08, Func Offset: 0x48
	// Line 330, Address: 0x27ab64, Func Offset: 0xa4
	// Line 331, Address: 0x27ab6c, Func Offset: 0xac
	// Line 332, Address: 0x27ab84, Func Offset: 0xc4
	// Line 333, Address: 0x27ab88, Func Offset: 0xc8
	// Line 334, Address: 0x27ab9c, Func Offset: 0xdc
	// Line 335, Address: 0x27aba8, Func Offset: 0xe8
	// Func End, Address: 0x27abb0, Func Offset: 0xf0
}

// 
// Start address: 0x27abb0
void bhSetCut(int cno, int flg)
{
	int i;
	unsigned int attr;
	npobj* obj;
	_anon14* lp;
	_anon21* ci;
	// Line 341, Address: 0x27abb0, Func Offset: 0
	// Line 349, Address: 0x27abcc, Func Offset: 0x1c
	// Line 350, Address: 0x27abe8, Func Offset: 0x38
	// Line 351, Address: 0x27abf0, Func Offset: 0x40
	// Line 352, Address: 0x27abf8, Func Offset: 0x48
	// Line 356, Address: 0x27ac00, Func Offset: 0x50
	// Line 358, Address: 0x27ac10, Func Offset: 0x60
	// Line 356, Address: 0x27ac18, Func Offset: 0x68
	// Line 358, Address: 0x27ac24, Func Offset: 0x74
	// Line 363, Address: 0x27ac28, Func Offset: 0x78
	// Line 358, Address: 0x27ac2c, Func Offset: 0x7c
	// Line 363, Address: 0x27ac34, Func Offset: 0x84
	// Line 364, Address: 0x27ac48, Func Offset: 0x98
	// Line 365, Address: 0x27ac60, Func Offset: 0xb0
	// Line 366, Address: 0x27ac68, Func Offset: 0xb8
	// Line 367, Address: 0x27ac84, Func Offset: 0xd4
	// Line 371, Address: 0x27ac8c, Func Offset: 0xdc
	// Line 373, Address: 0x27acb0, Func Offset: 0x100
	// Line 371, Address: 0x27acb8, Func Offset: 0x108
	// Line 373, Address: 0x27acd8, Func Offset: 0x128
	// Line 374, Address: 0x27ace0, Func Offset: 0x130
	// Line 375, Address: 0x27ace8, Func Offset: 0x138
	// Line 376, Address: 0x27acf4, Func Offset: 0x144
	// Line 377, Address: 0x27ad08, Func Offset: 0x158
	// Line 378, Address: 0x27ad10, Func Offset: 0x160
	// Line 379, Address: 0x27ad18, Func Offset: 0x168
	// Line 382, Address: 0x27ad2c, Func Offset: 0x17c
	// Line 384, Address: 0x27ad48, Func Offset: 0x198
	// Line 385, Address: 0x27ad4c, Func Offset: 0x19c
	// Line 386, Address: 0x27ad58, Func Offset: 0x1a8
	// Line 387, Address: 0x27ad6c, Func Offset: 0x1bc
	// Line 388, Address: 0x27ad78, Func Offset: 0x1c8
	// Line 389, Address: 0x27ad80, Func Offset: 0x1d0
	// Line 390, Address: 0x27ad8c, Func Offset: 0x1dc
	// Line 391, Address: 0x27ad90, Func Offset: 0x1e0
	// Line 397, Address: 0x27adb0, Func Offset: 0x200
	// Line 394, Address: 0x27adb8, Func Offset: 0x208
	// Line 395, Address: 0x27adc4, Func Offset: 0x214
	// Line 396, Address: 0x27add0, Func Offset: 0x220
	// Line 397, Address: 0x27addc, Func Offset: 0x22c
	// Line 402, Address: 0x27adfc, Func Offset: 0x24c
	// Line 403, Address: 0x27ae18, Func Offset: 0x268
	// Line 405, Address: 0x27ae3c, Func Offset: 0x28c
	// Line 406, Address: 0x27ae58, Func Offset: 0x2a8
	// Line 407, Address: 0x27ae60, Func Offset: 0x2b0
	// Line 406, Address: 0x27ae64, Func Offset: 0x2b4
	// Line 407, Address: 0x27ae6c, Func Offset: 0x2bc
	// Line 409, Address: 0x27ae8c, Func Offset: 0x2dc
	// Line 410, Address: 0x27ae9c, Func Offset: 0x2ec
	// Line 415, Address: 0x27aea4, Func Offset: 0x2f4
	// Line 417, Address: 0x27aeb0, Func Offset: 0x300
	// Line 421, Address: 0x27aec4, Func Offset: 0x314
	// Line 424, Address: 0x27aef8, Func Offset: 0x348
	// Line 425, Address: 0x27af04, Func Offset: 0x354
	// Line 426, Address: 0x27af10, Func Offset: 0x360
	// Line 427, Address: 0x27af1c, Func Offset: 0x36c
	// Line 428, Address: 0x27af28, Func Offset: 0x378
	// Line 429, Address: 0x27af34, Func Offset: 0x384
	// Line 430, Address: 0x27af40, Func Offset: 0x390
	// Line 431, Address: 0x27af54, Func Offset: 0x3a4
	// Line 432, Address: 0x27af58, Func Offset: 0x3a8
	// Line 434, Address: 0x27af60, Func Offset: 0x3b0
	// Line 442, Address: 0x27af68, Func Offset: 0x3b8
	// Line 434, Address: 0x27af6c, Func Offset: 0x3bc
	// Line 435, Address: 0x27af78, Func Offset: 0x3c8
	// Line 436, Address: 0x27af8c, Func Offset: 0x3dc
	// Line 437, Address: 0x27afa0, Func Offset: 0x3f0
	// Line 438, Address: 0x27afb4, Func Offset: 0x404
	// Line 439, Address: 0x27afc8, Func Offset: 0x418
	// Line 440, Address: 0x27afdc, Func Offset: 0x42c
	// Line 441, Address: 0x27afe8, Func Offset: 0x438
	// Line 442, Address: 0x27aff4, Func Offset: 0x444
	// Line 443, Address: 0x27b008, Func Offset: 0x458
	// Line 446, Address: 0x27b010, Func Offset: 0x460
	// Line 447, Address: 0x27b020, Func Offset: 0x470
	// Line 448, Address: 0x27b028, Func Offset: 0x478
	// Line 447, Address: 0x27b030, Func Offset: 0x480
	// Line 448, Address: 0x27b03c, Func Offset: 0x48c
	// Line 449, Address: 0x27b04c, Func Offset: 0x49c
	// Line 450, Address: 0x27b060, Func Offset: 0x4b0
	// Line 451, Address: 0x27b068, Func Offset: 0x4b8
	// Line 454, Address: 0x27b080, Func Offset: 0x4d0
	// Line 455, Address: 0x27b0a8, Func Offset: 0x4f8
	// Line 457, Address: 0x27b0c0, Func Offset: 0x510
	// Line 458, Address: 0x27b0e8, Func Offset: 0x538
	// Line 460, Address: 0x27b100, Func Offset: 0x550
	// Line 462, Address: 0x27b108, Func Offset: 0x558
	// Line 463, Address: 0x27b110, Func Offset: 0x560
	// Func End, Address: 0x27b130, Func Offset: 0x580
}

// 
// Start address: 0x27b130
void bhSetFixedCut(int cno)
{
	_anon21* ci;
	// Line 469, Address: 0x27b130, Func Offset: 0
	// Line 476, Address: 0x27b140, Func Offset: 0x10
	// Line 488, Address: 0x27b148, Func Offset: 0x18
	// Line 478, Address: 0x27b150, Func Offset: 0x20
	// Line 476, Address: 0x27b15c, Func Offset: 0x2c
	// Line 478, Address: 0x27b170, Func Offset: 0x40
	// Line 488, Address: 0x27b174, Func Offset: 0x44
	// Line 480, Address: 0x27b180, Func Offset: 0x50
	// Line 478, Address: 0x27b184, Func Offset: 0x54
	// Line 480, Address: 0x27b18c, Func Offset: 0x5c
	// Line 485, Address: 0x27b194, Func Offset: 0x64
	// Line 480, Address: 0x27b198, Func Offset: 0x68
	// Line 485, Address: 0x27b1a0, Func Offset: 0x70
	// Line 488, Address: 0x27b1a8, Func Offset: 0x78
	// Line 485, Address: 0x27b1ac, Func Offset: 0x7c
	// Line 488, Address: 0x27b1b4, Func Offset: 0x84
	// Line 489, Address: 0x27b1e0, Func Offset: 0xb0
	// Line 495, Address: 0x27b1e8, Func Offset: 0xb8
	// Line 492, Address: 0x27b1f0, Func Offset: 0xc0
	// Line 493, Address: 0x27b1fc, Func Offset: 0xcc
	// Line 494, Address: 0x27b208, Func Offset: 0xd8
	// Line 495, Address: 0x27b214, Func Offset: 0xe4
	// Line 500, Address: 0x27b234, Func Offset: 0x104
	// Line 501, Address: 0x27b250, Func Offset: 0x120
	// Line 503, Address: 0x27b274, Func Offset: 0x144
	// Line 504, Address: 0x27b284, Func Offset: 0x154
	// Line 509, Address: 0x27b28c, Func Offset: 0x15c
	// Line 511, Address: 0x27b298, Func Offset: 0x168
	// Line 515, Address: 0x27b2ac, Func Offset: 0x17c
	// Line 525, Address: 0x27b2b4, Func Offset: 0x184
	// Line 515, Address: 0x27b2b8, Func Offset: 0x188
	// Line 516, Address: 0x27b2c0, Func Offset: 0x190
	// Line 517, Address: 0x27b2c8, Func Offset: 0x198
	// Line 518, Address: 0x27b2dc, Func Offset: 0x1ac
	// Line 519, Address: 0x27b2f0, Func Offset: 0x1c0
	// Line 520, Address: 0x27b304, Func Offset: 0x1d4
	// Line 521, Address: 0x27b318, Func Offset: 0x1e8
	// Line 522, Address: 0x27b32c, Func Offset: 0x1fc
	// Line 523, Address: 0x27b340, Func Offset: 0x210
	// Line 524, Address: 0x27b354, Func Offset: 0x224
	// Line 525, Address: 0x27b368, Func Offset: 0x238
	// Line 526, Address: 0x27b37c, Func Offset: 0x24c
	// Line 528, Address: 0x27b384, Func Offset: 0x254
	// Line 529, Address: 0x27b394, Func Offset: 0x264
	// Line 530, Address: 0x27b39c, Func Offset: 0x26c
	// Line 529, Address: 0x27b3a4, Func Offset: 0x274
	// Line 530, Address: 0x27b3b0, Func Offset: 0x280
	// Line 531, Address: 0x27b3c0, Func Offset: 0x290
	// Line 532, Address: 0x27b3d4, Func Offset: 0x2a4
	// Line 533, Address: 0x27b3dc, Func Offset: 0x2ac
	// Line 536, Address: 0x27b3f4, Func Offset: 0x2c4
	// Line 537, Address: 0x27b41c, Func Offset: 0x2ec
	// Line 539, Address: 0x27b434, Func Offset: 0x304
	// Line 540, Address: 0x27b45c, Func Offset: 0x32c
	// Line 542, Address: 0x27b474, Func Offset: 0x344
	// Line 543, Address: 0x27b48c, Func Offset: 0x35c
	// Line 544, Address: 0x27b494, Func Offset: 0x364
	// Line 545, Address: 0x27b49c, Func Offset: 0x36c
	// Line 548, Address: 0x27b4a4, Func Offset: 0x374
	// Func End, Address: 0x27b4b8, Func Offset: 0x388
}

// 
// Start address: 0x27b4c0
void bhSetRenderCut(int cno)
{
	_anon21* ci;
	// Line 554, Address: 0x27b4c0, Func Offset: 0
	// Line 559, Address: 0x27b4cc, Func Offset: 0xc
	// Line 560, Address: 0x27b4ec, Func Offset: 0x2c
	// Line 559, Address: 0x27b4f0, Func Offset: 0x30
	// Line 560, Address: 0x27b4f4, Func Offset: 0x34
	// Line 561, Address: 0x27b4f8, Func Offset: 0x38
	// Line 559, Address: 0x27b4fc, Func Offset: 0x3c
	// Line 562, Address: 0x27b500, Func Offset: 0x40
	// Line 564, Address: 0x27b508, Func Offset: 0x48
	// Line 565, Address: 0x27b51c, Func Offset: 0x5c
	// Line 566, Address: 0x27b530, Func Offset: 0x70
	// Line 567, Address: 0x27b544, Func Offset: 0x84
	// Line 568, Address: 0x27b558, Func Offset: 0x98
	// Line 569, Address: 0x27b56c, Func Offset: 0xac
	// Line 570, Address: 0x27b580, Func Offset: 0xc0
	// Line 571, Address: 0x27b58c, Func Offset: 0xcc
	// Line 572, Address: 0x27b598, Func Offset: 0xd8
	// Func End, Address: 0x27b5a8, Func Offset: 0xe8
}

// 
// Start address: 0x27b5b0
void bhSetHideObjLgt(int cno)
{
	int i;
	npobj* obj;
	_anon14* lp;
	_anon21* ci;
	// Line 578, Address: 0x27b5b0, Func Offset: 0
	// Line 585, Address: 0x27b5c8, Func Offset: 0x18
	// Line 587, Address: 0x27b5ec, Func Offset: 0x3c
	// Line 585, Address: 0x27b5f4, Func Offset: 0x44
	// Line 587, Address: 0x27b614, Func Offset: 0x64
	// Line 588, Address: 0x27b61c, Func Offset: 0x6c
	// Line 589, Address: 0x27b624, Func Offset: 0x74
	// Line 590, Address: 0x27b630, Func Offset: 0x80
	// Line 591, Address: 0x27b644, Func Offset: 0x94
	// Line 592, Address: 0x27b64c, Func Offset: 0x9c
	// Line 593, Address: 0x27b654, Func Offset: 0xa4
	// Line 595, Address: 0x27b664, Func Offset: 0xb4
	// Line 593, Address: 0x27b668, Func Offset: 0xb8
	// Line 596, Address: 0x27b66c, Func Offset: 0xbc
	// Line 598, Address: 0x27b688, Func Offset: 0xd8
	// Line 599, Address: 0x27b68c, Func Offset: 0xdc
	// Line 600, Address: 0x27b698, Func Offset: 0xe8
	// Line 601, Address: 0x27b6ac, Func Offset: 0xfc
	// Line 602, Address: 0x27b6b8, Func Offset: 0x108
	// Line 603, Address: 0x27b6c0, Func Offset: 0x110
	// Line 604, Address: 0x27b6cc, Func Offset: 0x11c
	// Line 605, Address: 0x27b6d0, Func Offset: 0x120
	// Line 606, Address: 0x27b6f0, Func Offset: 0x140
	// Func End, Address: 0x27b70c, Func Offset: 0x15c
}

// 
// Start address: 0x27b710
void bhSetHideObject(int offset)
{
	int i;
	npobj* obj;
	// Line 612, Address: 0x27b710, Func Offset: 0
	// Line 619, Address: 0x27b728, Func Offset: 0x18
	// Line 623, Address: 0x27b754, Func Offset: 0x44
	// Line 624, Address: 0x27b7a0, Func Offset: 0x90
	// Line 625, Address: 0x27b7a8, Func Offset: 0x98
	// Line 626, Address: 0x27b7b4, Func Offset: 0xa4
	// Line 627, Address: 0x27b7c8, Func Offset: 0xb8
	// Line 628, Address: 0x27b7d0, Func Offset: 0xc0
	// Line 629, Address: 0x27b7d8, Func Offset: 0xc8
	// Line 632, Address: 0x27b7ec, Func Offset: 0xdc
	// Line 633, Address: 0x27b808, Func Offset: 0xf8
	// Line 637, Address: 0x27b814, Func Offset: 0x104
	// Line 638, Address: 0x27b874, Func Offset: 0x164
	// Line 639, Address: 0x27b87c, Func Offset: 0x16c
	// Line 640, Address: 0x27b888, Func Offset: 0x178
	// Line 641, Address: 0x27b89c, Func Offset: 0x18c
	// Line 642, Address: 0x27b8a4, Func Offset: 0x194
	// Line 643, Address: 0x27b8ac, Func Offset: 0x19c
	// Line 645, Address: 0x27b8bc, Func Offset: 0x1ac
	// Line 643, Address: 0x27b8c0, Func Offset: 0x1b0
	// Line 646, Address: 0x27b8c4, Func Offset: 0x1b4
	// Line 648, Address: 0x27b8e0, Func Offset: 0x1d0
	// Func End, Address: 0x27b8fc, Func Offset: 0x1ec
}

// 
// Start address: 0x27b900
void bhInitActiveCamera(int flg)
{
	_anon28 sca;
	short ay;
	short ax;
	int yr;
	int xr;
	unsigned int attr;
	float d;
	float w;
	float pz;
	float py;
	float px;
	float nrz;
	float nrx;
	_anon21* ci;
	_anon10* cp;
	// Line 656, Address: 0x27b900, Func Offset: 0
	// Line 664, Address: 0x27b920, Func Offset: 0x20
	// Line 665, Address: 0x27b938, Func Offset: 0x38
	// Line 664, Address: 0x27b940, Func Offset: 0x40
	// Line 667, Address: 0x27b950, Func Offset: 0x50
	// Line 664, Address: 0x27b958, Func Offset: 0x58
	// Line 667, Address: 0x27b960, Func Offset: 0x60
	// Line 665, Address: 0x27b970, Func Offset: 0x70
	// Line 667, Address: 0x27b978, Func Offset: 0x78
	// Line 665, Address: 0x27b97c, Func Offset: 0x7c
	// Line 668, Address: 0x27b984, Func Offset: 0x84
	// Line 665, Address: 0x27b98c, Func Offset: 0x8c
	// Line 668, Address: 0x27b994, Func Offset: 0x94
	// Line 665, Address: 0x27b998, Func Offset: 0x98
	// Line 668, Address: 0x27b99c, Func Offset: 0x9c
	// Line 669, Address: 0x27b9b4, Func Offset: 0xb4
	// Line 671, Address: 0x27b9d0, Func Offset: 0xd0
	// Line 673, Address: 0x27b9e8, Func Offset: 0xe8
	// Line 674, Address: 0x27ba18, Func Offset: 0x118
	// Line 675, Address: 0x27ba24, Func Offset: 0x124
	// Line 676, Address: 0x27ba38, Func Offset: 0x138
	// Line 677, Address: 0x27ba40, Func Offset: 0x140
	// Line 676, Address: 0x27ba44, Func Offset: 0x144
	// Line 677, Address: 0x27ba48, Func Offset: 0x148
	// Line 678, Address: 0x27ba4c, Func Offset: 0x14c
	// Line 679, Address: 0x27ba54, Func Offset: 0x154
	// Line 680, Address: 0x27ba68, Func Offset: 0x168
	// Line 682, Address: 0x27ba74, Func Offset: 0x174
	// Line 683, Address: 0x27ba84, Func Offset: 0x184
	// Line 682, Address: 0x27ba88, Func Offset: 0x188
	// Line 683, Address: 0x27ba94, Func Offset: 0x194
	// Line 682, Address: 0x27ba98, Func Offset: 0x198
	// Line 683, Address: 0x27ba9c, Func Offset: 0x19c
	// Line 682, Address: 0x27baa0, Func Offset: 0x1a0
	// Line 684, Address: 0x27baa8, Func Offset: 0x1a8
	// Line 683, Address: 0x27baac, Func Offset: 0x1ac
	// Line 684, Address: 0x27bab0, Func Offset: 0x1b0
	// Line 683, Address: 0x27bab4, Func Offset: 0x1b4
	// Line 682, Address: 0x27bab8, Func Offset: 0x1b8
	// Line 683, Address: 0x27babc, Func Offset: 0x1bc
	// Line 684, Address: 0x27bac0, Func Offset: 0x1c0
	// Line 687, Address: 0x27bb00, Func Offset: 0x200
	// Line 688, Address: 0x27bb08, Func Offset: 0x208
	// Line 689, Address: 0x27bb10, Func Offset: 0x210
	// Line 693, Address: 0x27bb24, Func Offset: 0x224
	// Line 694, Address: 0x27bb54, Func Offset: 0x254
	// Line 695, Address: 0x27bb60, Func Offset: 0x260
	// Line 696, Address: 0x27bb74, Func Offset: 0x274
	// Line 697, Address: 0x27bb7c, Func Offset: 0x27c
	// Line 696, Address: 0x27bb80, Func Offset: 0x280
	// Line 697, Address: 0x27bb84, Func Offset: 0x284
	// Line 698, Address: 0x27bb88, Func Offset: 0x288
	// Line 699, Address: 0x27bb90, Func Offset: 0x290
	// Line 700, Address: 0x27bba4, Func Offset: 0x2a4
	// Line 702, Address: 0x27bbb0, Func Offset: 0x2b0
	// Line 703, Address: 0x27bbc0, Func Offset: 0x2c0
	// Line 702, Address: 0x27bbc4, Func Offset: 0x2c4
	// Line 703, Address: 0x27bbd0, Func Offset: 0x2d0
	// Line 702, Address: 0x27bbd4, Func Offset: 0x2d4
	// Line 703, Address: 0x27bbd8, Func Offset: 0x2d8
	// Line 702, Address: 0x27bbdc, Func Offset: 0x2dc
	// Line 704, Address: 0x27bbe4, Func Offset: 0x2e4
	// Line 703, Address: 0x27bbe8, Func Offset: 0x2e8
	// Line 704, Address: 0x27bbec, Func Offset: 0x2ec
	// Line 703, Address: 0x27bbf0, Func Offset: 0x2f0
	// Line 702, Address: 0x27bbf4, Func Offset: 0x2f4
	// Line 703, Address: 0x27bbf8, Func Offset: 0x2f8
	// Line 704, Address: 0x27bbfc, Func Offset: 0x2fc
	// Line 707, Address: 0x27bc3c, Func Offset: 0x33c
	// Line 708, Address: 0x27bc44, Func Offset: 0x344
	// Line 709, Address: 0x27bc4c, Func Offset: 0x34c
	// Line 713, Address: 0x27bc60, Func Offset: 0x360
	// Line 714, Address: 0x27bcb8, Func Offset: 0x3b8
	// Line 715, Address: 0x27bcc4, Func Offset: 0x3c4
	// Line 716, Address: 0x27bcd8, Func Offset: 0x3d8
	// Line 717, Address: 0x27bce0, Func Offset: 0x3e0
	// Line 716, Address: 0x27bce4, Func Offset: 0x3e4
	// Line 717, Address: 0x27bce8, Func Offset: 0x3e8
	// Line 718, Address: 0x27bcec, Func Offset: 0x3ec
	// Line 719, Address: 0x27bcf4, Func Offset: 0x3f4
	// Line 720, Address: 0x27bd08, Func Offset: 0x408
	// Line 722, Address: 0x27bd14, Func Offset: 0x414
	// Line 725, Address: 0x27bd5c, Func Offset: 0x45c
	// Line 726, Address: 0x27bd74, Func Offset: 0x474
	// Line 727, Address: 0x27bd7c, Func Offset: 0x47c
	// Line 731, Address: 0x27bda0, Func Offset: 0x4a0
	// Line 732, Address: 0x27bdd0, Func Offset: 0x4d0
	// Line 733, Address: 0x27bddc, Func Offset: 0x4dc
	// Line 734, Address: 0x27bdf0, Func Offset: 0x4f0
	// Line 735, Address: 0x27bdf8, Func Offset: 0x4f8
	// Line 734, Address: 0x27bdfc, Func Offset: 0x4fc
	// Line 735, Address: 0x27be00, Func Offset: 0x500
	// Line 736, Address: 0x27be04, Func Offset: 0x504
	// Line 737, Address: 0x27be0c, Func Offset: 0x50c
	// Line 738, Address: 0x27be20, Func Offset: 0x520
	// Line 740, Address: 0x27be2c, Func Offset: 0x52c
	// Line 743, Address: 0x27be74, Func Offset: 0x574
	// Line 744, Address: 0x27be94, Func Offset: 0x594
	// Line 745, Address: 0x27be9c, Func Offset: 0x59c
	// Line 749, Address: 0x27bec8, Func Offset: 0x5c8
	// Line 750, Address: 0x27bed8, Func Offset: 0x5d8
	// Line 751, Address: 0x27bee4, Func Offset: 0x5e4
	// Line 752, Address: 0x27bef8, Func Offset: 0x5f8
	// Line 753, Address: 0x27bf00, Func Offset: 0x600
	// Line 752, Address: 0x27bf04, Func Offset: 0x604
	// Line 753, Address: 0x27bf08, Func Offset: 0x608
	// Line 754, Address: 0x27bf0c, Func Offset: 0x60c
	// Line 755, Address: 0x27bf14, Func Offset: 0x614
	// Line 756, Address: 0x27bf28, Func Offset: 0x628
	// Line 758, Address: 0x27bf34, Func Offset: 0x634
	// Line 761, Address: 0x27bf7c, Func Offset: 0x67c
	// Line 762, Address: 0x27bf94, Func Offset: 0x694
	// Line 763, Address: 0x27bf9c, Func Offset: 0x69c
	// Line 767, Address: 0x27bfc0, Func Offset: 0x6c0
	// Line 769, Address: 0x27bfd0, Func Offset: 0x6d0
	// Line 770, Address: 0x27bfdc, Func Offset: 0x6dc
	// Line 771, Address: 0x27bff0, Func Offset: 0x6f0
	// Line 772, Address: 0x27bff8, Func Offset: 0x6f8
	// Line 771, Address: 0x27bffc, Func Offset: 0x6fc
	// Line 772, Address: 0x27c000, Func Offset: 0x700
	// Line 773, Address: 0x27c004, Func Offset: 0x704
	// Line 774, Address: 0x27c00c, Func Offset: 0x70c
	// Line 775, Address: 0x27c020, Func Offset: 0x720
	// Line 777, Address: 0x27c02c, Func Offset: 0x72c
	// Line 778, Address: 0x27c03c, Func Offset: 0x73c
	// Line 777, Address: 0x27c044, Func Offset: 0x744
	// Line 779, Address: 0x27c048, Func Offset: 0x748
	// Line 778, Address: 0x27c04c, Func Offset: 0x74c
	// Line 779, Address: 0x27c058, Func Offset: 0x758
	// Line 781, Address: 0x27c060, Func Offset: 0x760
	// Line 783, Address: 0x27c098, Func Offset: 0x798
	// Line 786, Address: 0x27c0e0, Func Offset: 0x7e0
	// Line 787, Address: 0x27c0e8, Func Offset: 0x7e8
	// Line 788, Address: 0x27c0f0, Func Offset: 0x7f0
	// Line 791, Address: 0x27c104, Func Offset: 0x804
	// Line 792, Address: 0x27c110, Func Offset: 0x810
	// Line 793, Address: 0x27c124, Func Offset: 0x824
	// Line 794, Address: 0x27c12c, Func Offset: 0x82c
	// Line 793, Address: 0x27c130, Func Offset: 0x830
	// Line 794, Address: 0x27c134, Func Offset: 0x834
	// Line 795, Address: 0x27c138, Func Offset: 0x838
	// Line 796, Address: 0x27c140, Func Offset: 0x840
	// Line 797, Address: 0x27c154, Func Offset: 0x854
	// Line 801, Address: 0x27c160, Func Offset: 0x860
	// Line 803, Address: 0x27c1a8, Func Offset: 0x8a8
	// Line 801, Address: 0x27c1ac, Func Offset: 0x8ac
	// Line 803, Address: 0x27c1b4, Func Offset: 0x8b4
	// Line 806, Address: 0x27c1f8, Func Offset: 0x8f8
	// Line 807, Address: 0x27c200, Func Offset: 0x900
	// Line 808, Address: 0x27c208, Func Offset: 0x908
	// Line 810, Address: 0x27c218, Func Offset: 0x918
	// Line 811, Address: 0x27c220, Func Offset: 0x920
	// Line 814, Address: 0x27c22c, Func Offset: 0x92c
	// Line 816, Address: 0x27c238, Func Offset: 0x938
	// Line 817, Address: 0x27c244, Func Offset: 0x944
	// Line 818, Address: 0x27c258, Func Offset: 0x958
	// Line 819, Address: 0x27c260, Func Offset: 0x960
	// Line 818, Address: 0x27c264, Func Offset: 0x964
	// Line 819, Address: 0x27c268, Func Offset: 0x968
	// Line 820, Address: 0x27c26c, Func Offset: 0x96c
	// Line 821, Address: 0x27c274, Func Offset: 0x974
	// Line 822, Address: 0x27c288, Func Offset: 0x988
	// Line 824, Address: 0x27c294, Func Offset: 0x994
	// Line 825, Address: 0x27c2a4, Func Offset: 0x9a4
	// Line 824, Address: 0x27c2ac, Func Offset: 0x9ac
	// Line 826, Address: 0x27c2b0, Func Offset: 0x9b0
	// Line 825, Address: 0x27c2b4, Func Offset: 0x9b4
	// Line 826, Address: 0x27c2c0, Func Offset: 0x9c0
	// Line 828, Address: 0x27c2c8, Func Offset: 0x9c8
	// Line 831, Address: 0x27c2f8, Func Offset: 0x9f8
	// Line 828, Address: 0x27c2fc, Func Offset: 0x9fc
	// Line 829, Address: 0x27c308, Func Offset: 0xa08
	// Line 831, Address: 0x27c310, Func Offset: 0xa10
	// Line 829, Address: 0x27c318, Func Offset: 0xa18
	// Line 831, Address: 0x27c31c, Func Offset: 0xa1c
	// Line 832, Address: 0x27c334, Func Offset: 0xa34
	// Line 833, Address: 0x27c350, Func Offset: 0xa50
	// Line 836, Address: 0x27c398, Func Offset: 0xa98
	// Line 837, Address: 0x27c3a0, Func Offset: 0xaa0
	// Line 838, Address: 0x27c3a8, Func Offset: 0xaa8
	// Line 842, Address: 0x27c3bc, Func Offset: 0xabc
	// Line 844, Address: 0x27c3c8, Func Offset: 0xac8
	// Line 845, Address: 0x27c3d4, Func Offset: 0xad4
	// Line 846, Address: 0x27c3e8, Func Offset: 0xae8
	// Line 847, Address: 0x27c3f0, Func Offset: 0xaf0
	// Line 846, Address: 0x27c3f4, Func Offset: 0xaf4
	// Line 847, Address: 0x27c3f8, Func Offset: 0xaf8
	// Line 848, Address: 0x27c3fc, Func Offset: 0xafc
	// Line 849, Address: 0x27c404, Func Offset: 0xb04
	// Line 850, Address: 0x27c418, Func Offset: 0xb18
	// Line 854, Address: 0x27c424, Func Offset: 0xb24
	// Line 857, Address: 0x27c46c, Func Offset: 0xb6c
	// Line 854, Address: 0x27c470, Func Offset: 0xb70
	// Line 855, Address: 0x27c47c, Func Offset: 0xb7c
	// Line 857, Address: 0x27c484, Func Offset: 0xb84
	// Line 855, Address: 0x27c48c, Func Offset: 0xb8c
	// Line 857, Address: 0x27c490, Func Offset: 0xb90
	// Line 858, Address: 0x27c4a8, Func Offset: 0xba8
	// Line 859, Address: 0x27c4c4, Func Offset: 0xbc4
	// Line 862, Address: 0x27c50c, Func Offset: 0xc0c
	// Line 863, Address: 0x27c514, Func Offset: 0xc14
	// Line 864, Address: 0x27c51c, Func Offset: 0xc1c
	// Line 867, Address: 0x27c52c, Func Offset: 0xc2c
	// Line 870, Address: 0x27c534, Func Offset: 0xc34
	// Line 872, Address: 0x27c540, Func Offset: 0xc40
	// Line 873, Address: 0x27c54c, Func Offset: 0xc4c
	// Line 874, Address: 0x27c560, Func Offset: 0xc60
	// Line 875, Address: 0x27c568, Func Offset: 0xc68
	// Line 874, Address: 0x27c56c, Func Offset: 0xc6c
	// Line 875, Address: 0x27c570, Func Offset: 0xc70
	// Line 876, Address: 0x27c574, Func Offset: 0xc74
	// Line 877, Address: 0x27c57c, Func Offset: 0xc7c
	// Line 878, Address: 0x27c590, Func Offset: 0xc90
	// Line 880, Address: 0x27c59c, Func Offset: 0xc9c
	// Line 881, Address: 0x27c5ac, Func Offset: 0xcac
	// Line 880, Address: 0x27c5b4, Func Offset: 0xcb4
	// Line 882, Address: 0x27c5b8, Func Offset: 0xcb8
	// Line 881, Address: 0x27c5bc, Func Offset: 0xcbc
	// Line 882, Address: 0x27c5c8, Func Offset: 0xcc8
	// Line 884, Address: 0x27c5d0, Func Offset: 0xcd0
	// Line 888, Address: 0x27c600, Func Offset: 0xd00
	// Line 884, Address: 0x27c604, Func Offset: 0xd04
	// Line 885, Address: 0x27c610, Func Offset: 0xd10
	// Line 886, Address: 0x27c618, Func Offset: 0xd18
	// Line 888, Address: 0x27c61c, Func Offset: 0xd1c
	// Line 885, Address: 0x27c624, Func Offset: 0xd24
	// Line 888, Address: 0x27c628, Func Offset: 0xd28
	// Line 889, Address: 0x27c638, Func Offset: 0xd38
	// Line 891, Address: 0x27c640, Func Offset: 0xd40
	// Line 892, Address: 0x27c654, Func Offset: 0xd54
	// Line 894, Address: 0x27c65c, Func Offset: 0xd5c
	// Line 897, Address: 0x27c6a4, Func Offset: 0xda4
	// Line 898, Address: 0x27c6ac, Func Offset: 0xdac
	// Line 899, Address: 0x27c6b4, Func Offset: 0xdb4
	// Line 903, Address: 0x27c6c8, Func Offset: 0xdc8
	// Line 905, Address: 0x27c6d4, Func Offset: 0xdd4
	// Line 906, Address: 0x27c6e0, Func Offset: 0xde0
	// Line 907, Address: 0x27c6f4, Func Offset: 0xdf4
	// Line 908, Address: 0x27c6fc, Func Offset: 0xdfc
	// Line 907, Address: 0x27c700, Func Offset: 0xe00
	// Line 908, Address: 0x27c704, Func Offset: 0xe04
	// Line 909, Address: 0x27c708, Func Offset: 0xe08
	// Line 910, Address: 0x27c710, Func Offset: 0xe10
	// Line 911, Address: 0x27c724, Func Offset: 0xe24
	// Line 915, Address: 0x27c730, Func Offset: 0xe30
	// Line 917, Address: 0x27c778, Func Offset: 0xe78
	// Line 915, Address: 0x27c77c, Func Offset: 0xe7c
	// Line 919, Address: 0x27c780, Func Offset: 0xe80
	// Line 915, Address: 0x27c784, Func Offset: 0xe84
	// Line 916, Address: 0x27c78c, Func Offset: 0xe8c
	// Line 919, Address: 0x27c798, Func Offset: 0xe98
	// Line 920, Address: 0x27c7b0, Func Offset: 0xeb0
	// Line 922, Address: 0x27c7b8, Func Offset: 0xeb8
	// Line 923, Address: 0x27c7cc, Func Offset: 0xecc
	// Line 925, Address: 0x27c7d4, Func Offset: 0xed4
	// Line 928, Address: 0x27c81c, Func Offset: 0xf1c
	// Line 929, Address: 0x27c824, Func Offset: 0xf24
	// Line 930, Address: 0x27c82c, Func Offset: 0xf2c
	// Line 936, Address: 0x27c840, Func Offset: 0xf40
	// Line 938, Address: 0x27c850, Func Offset: 0xf50
	// Line 939, Address: 0x27c858, Func Offset: 0xf58
	// Line 942, Address: 0x27c864, Func Offset: 0xf64
	// Line 940, Address: 0x27c868, Func Offset: 0xf68
	// Line 939, Address: 0x27c86c, Func Offset: 0xf6c
	// Line 940, Address: 0x27c870, Func Offset: 0xf70
	// Line 939, Address: 0x27c874, Func Offset: 0xf74
	// Line 940, Address: 0x27c878, Func Offset: 0xf78
	// Line 941, Address: 0x27c87c, Func Offset: 0xf7c
	// Line 940, Address: 0x27c884, Func Offset: 0xf84
	// Line 941, Address: 0x27c88c, Func Offset: 0xf8c
	// Line 942, Address: 0x27c894, Func Offset: 0xf94
	// Line 943, Address: 0x27c89c, Func Offset: 0xf9c
	// Line 945, Address: 0x27c8a8, Func Offset: 0xfa8
	// Line 946, Address: 0x27c8e0, Func Offset: 0xfe0
	// Line 947, Address: 0x27c904, Func Offset: 0x1004
	// Line 949, Address: 0x27c928, Func Offset: 0x1028
	// Func End, Address: 0x27c94c, Func Offset: 0x104c
}

// 
// Start address: 0x27c950
void bhCheckNearAttrOffCutRange(_anon10* cp, unsigned int sft, float* px, float* pz)
{
	float nr;
	float ln;
	float hz;
	float hx;
	float zz;
	float xx;
	int i;
	_anon13* ct;
	// Line 956, Address: 0x27c950, Func Offset: 0
	// Line 961, Address: 0x27c97c, Func Offset: 0x2c
	// Line 960, Address: 0x27c980, Func Offset: 0x30
	// Line 962, Address: 0x27c99c, Func Offset: 0x4c
	// Line 963, Address: 0x27c9a4, Func Offset: 0x54
	// Line 964, Address: 0x27c9c0, Func Offset: 0x70
	// Line 965, Address: 0x27c9cc, Func Offset: 0x7c
	// Line 964, Address: 0x27c9d4, Func Offset: 0x84
	// Line 967, Address: 0x27c9d8, Func Offset: 0x88
	// Line 964, Address: 0x27c9dc, Func Offset: 0x8c
	// Line 967, Address: 0x27c9e0, Func Offset: 0x90
	// Line 964, Address: 0x27c9e4, Func Offset: 0x94
	// Line 967, Address: 0x27c9e8, Func Offset: 0x98
	// Line 965, Address: 0x27c9ec, Func Offset: 0x9c
	// Line 968, Address: 0x27c9f0, Func Offset: 0xa0
	// Line 965, Address: 0x27c9f4, Func Offset: 0xa4
	// Line 968, Address: 0x27c9f8, Func Offset: 0xa8
	// Line 967, Address: 0x27c9fc, Func Offset: 0xac
	// Line 969, Address: 0x27ca00, Func Offset: 0xb0
	// Line 970, Address: 0x27ca0c, Func Offset: 0xbc
	// Line 971, Address: 0x27ca1c, Func Offset: 0xcc
	// Line 972, Address: 0x27ca20, Func Offset: 0xd0
	// Line 973, Address: 0x27ca24, Func Offset: 0xd4
	// Line 974, Address: 0x27ca2c, Func Offset: 0xdc
	// Line 976, Address: 0x27ca30, Func Offset: 0xe0
	// Line 977, Address: 0x27ca40, Func Offset: 0xf0
	// Line 976, Address: 0x27ca44, Func Offset: 0xf4
	// Line 977, Address: 0x27ca48, Func Offset: 0xf8
	// Line 978, Address: 0x27ca4c, Func Offset: 0xfc
	// Line 979, Address: 0x27ca58, Func Offset: 0x108
	// Line 980, Address: 0x27ca68, Func Offset: 0x118
	// Line 981, Address: 0x27ca6c, Func Offset: 0x11c
	// Line 982, Address: 0x27ca74, Func Offset: 0x124
	// Line 985, Address: 0x27ca78, Func Offset: 0x128
	// Line 986, Address: 0x27ca88, Func Offset: 0x138
	// Line 985, Address: 0x27ca8c, Func Offset: 0x13c
	// Line 986, Address: 0x27ca90, Func Offset: 0x140
	// Line 987, Address: 0x27ca94, Func Offset: 0x144
	// Line 988, Address: 0x27caa0, Func Offset: 0x150
	// Line 989, Address: 0x27cab0, Func Offset: 0x160
	// Line 990, Address: 0x27cab4, Func Offset: 0x164
	// Line 991, Address: 0x27cabc, Func Offset: 0x16c
	// Line 994, Address: 0x27cac0, Func Offset: 0x170
	// Line 995, Address: 0x27cac8, Func Offset: 0x178
	// Line 994, Address: 0x27cacc, Func Offset: 0x17c
	// Line 995, Address: 0x27cad0, Func Offset: 0x180
	// Line 994, Address: 0x27cad4, Func Offset: 0x184
	// Line 995, Address: 0x27cad8, Func Offset: 0x188
	// Line 996, Address: 0x27cadc, Func Offset: 0x18c
	// Line 997, Address: 0x27cae8, Func Offset: 0x198
	// Line 999, Address: 0x27cb08, Func Offset: 0x1b8
	// Line 998, Address: 0x27cb0c, Func Offset: 0x1bc
	// Line 1000, Address: 0x27cb10, Func Offset: 0x1c0
	// Line 1003, Address: 0x27cb18, Func Offset: 0x1c8
	// Line 1004, Address: 0x27cb30, Func Offset: 0x1e0
	// Func End, Address: 0x27cb60, Func Offset: 0x210
}

// 
// Start address: 0x27cb60
void bhControlActiveCamera()
{
	_anon28 sca;
	short ahkn;
	float hkn;
	short aa;
	short ay;
	short ax;
	int yr;
	int xr;
	unsigned int attr;
	float fa1;
	float fa0;
	float aa_spd;
	float pz;
	float py;
	float px;
	_anon21* ci;
	_anon10* cp;
	// Line 1011, Address: 0x27cb60, Func Offset: 0
	// Line 1019, Address: 0x27cb80, Func Offset: 0x20
	// Line 1022, Address: 0x27cb88, Func Offset: 0x28
	// Line 1019, Address: 0x27cb8c, Func Offset: 0x2c
	// Line 1020, Address: 0x27cb98, Func Offset: 0x38
	// Line 1019, Address: 0x27cba0, Func Offset: 0x40
	// Line 1022, Address: 0x27cbb0, Func Offset: 0x50
	// Line 1019, Address: 0x27cbb8, Func Offset: 0x58
	// Line 1020, Address: 0x27cbc0, Func Offset: 0x60
	// Line 1022, Address: 0x27cbd8, Func Offset: 0x78
	// Line 1024, Address: 0x27cc20, Func Offset: 0xc0
	// Line 1026, Address: 0x27cc30, Func Offset: 0xd0
	// Line 1027, Address: 0x27cc44, Func Offset: 0xe4
	// Line 1028, Address: 0x27cc60, Func Offset: 0x100
	// Line 1029, Address: 0x27cc70, Func Offset: 0x110
	// Line 1031, Address: 0x27cc78, Func Offset: 0x118
	// Line 1033, Address: 0x27cca4, Func Offset: 0x144
	// Line 1034, Address: 0x27ccc4, Func Offset: 0x164
	// Line 1036, Address: 0x27cce4, Func Offset: 0x184
	// Line 1037, Address: 0x27ccec, Func Offset: 0x18c
	// Line 1039, Address: 0x27ccf8, Func Offset: 0x198
	// Line 1040, Address: 0x27cd0c, Func Offset: 0x1ac
	// Line 1041, Address: 0x27cd28, Func Offset: 0x1c8
	// Line 1047, Address: 0x27cd3c, Func Offset: 0x1dc
	// Line 1048, Address: 0x27cd58, Func Offset: 0x1f8
	// Line 1049, Address: 0x27cd60, Func Offset: 0x200
	// Line 1052, Address: 0x27cd70, Func Offset: 0x210
	// Line 1053, Address: 0x27cd78, Func Offset: 0x218
	// Line 1056, Address: 0x27cd7c, Func Offset: 0x21c
	// Line 1070, Address: 0x27cd88, Func Offset: 0x228
	// Line 1056, Address: 0x27cd90, Func Offset: 0x230
	// Line 1070, Address: 0x27cda0, Func Offset: 0x240
	// Line 1073, Address: 0x27cdd0, Func Offset: 0x270
	// Line 1077, Address: 0x27ce10, Func Offset: 0x2b0
	// Line 1080, Address: 0x27ce4c, Func Offset: 0x2ec
	// Line 1084, Address: 0x27ce98, Func Offset: 0x338
	// Line 1085, Address: 0x27cef0, Func Offset: 0x390
	// Line 1086, Address: 0x27cefc, Func Offset: 0x39c
	// Line 1094, Address: 0x27cf14, Func Offset: 0x3b4
	// Line 1096, Address: 0x27cf24, Func Offset: 0x3c4
	// Line 1097, Address: 0x27cf30, Func Offset: 0x3d0
	// Line 1098, Address: 0x27cf40, Func Offset: 0x3e0
	// Line 1097, Address: 0x27cf48, Func Offset: 0x3e8
	// Line 1099, Address: 0x27cf4c, Func Offset: 0x3ec
	// Line 1098, Address: 0x27cf50, Func Offset: 0x3f0
	// Line 1099, Address: 0x27cf5c, Func Offset: 0x3fc
	// Line 1101, Address: 0x27cf64, Func Offset: 0x404
	// Line 1103, Address: 0x27cfa0, Func Offset: 0x440
	// Line 1107, Address: 0x27cfac, Func Offset: 0x44c
	// Line 1110, Address: 0x27cfb8, Func Offset: 0x458
	// Line 1112, Address: 0x27d00c, Func Offset: 0x4ac
	// Line 1115, Address: 0x27d014, Func Offset: 0x4b4
	// Line 1117, Address: 0x27d01c, Func Offset: 0x4bc
	// Line 1120, Address: 0x27d028, Func Offset: 0x4c8
	// Line 1121, Address: 0x27d034, Func Offset: 0x4d4
	// Line 1123, Address: 0x27d040, Func Offset: 0x4e0
	// Line 1122, Address: 0x27d048, Func Offset: 0x4e8
	// Line 1123, Address: 0x27d04c, Func Offset: 0x4ec
	// Line 1124, Address: 0x27d054, Func Offset: 0x4f4
	// Line 1123, Address: 0x27d05c, Func Offset: 0x4fc
	// Line 1125, Address: 0x27d060, Func Offset: 0x500
	// Line 1124, Address: 0x27d064, Func Offset: 0x504
	// Line 1125, Address: 0x27d070, Func Offset: 0x510
	// Line 1127, Address: 0x27d078, Func Offset: 0x518
	// Line 1130, Address: 0x27d0a8, Func Offset: 0x548
	// Line 1127, Address: 0x27d0ac, Func Offset: 0x54c
	// Line 1128, Address: 0x27d0b8, Func Offset: 0x558
	// Line 1130, Address: 0x27d0c0, Func Offset: 0x560
	// Line 1128, Address: 0x27d0c8, Func Offset: 0x568
	// Line 1130, Address: 0x27d0cc, Func Offset: 0x56c
	// Line 1131, Address: 0x27d0e4, Func Offset: 0x584
	// Line 1132, Address: 0x27d100, Func Offset: 0x5a0
	// Line 1137, Address: 0x27d10c, Func Offset: 0x5ac
	// Line 1138, Address: 0x27d118, Func Offset: 0x5b8
	// Line 1142, Address: 0x27d124, Func Offset: 0x5c4
	// Line 1139, Address: 0x27d12c, Func Offset: 0x5cc
	// Line 1142, Address: 0x27d130, Func Offset: 0x5d0
	// Line 1145, Address: 0x27d170, Func Offset: 0x610
	// Line 1142, Address: 0x27d174, Func Offset: 0x614
	// Line 1143, Address: 0x27d180, Func Offset: 0x620
	// Line 1145, Address: 0x27d188, Func Offset: 0x628
	// Line 1143, Address: 0x27d190, Func Offset: 0x630
	// Line 1145, Address: 0x27d194, Func Offset: 0x634
	// Line 1146, Address: 0x27d1ac, Func Offset: 0x64c
	// Line 1147, Address: 0x27d1c8, Func Offset: 0x668
	// Line 1151, Address: 0x27d1d0, Func Offset: 0x670
	// Line 1154, Address: 0x27d1d8, Func Offset: 0x678
	// Line 1155, Address: 0x27d1e4, Func Offset: 0x684
	// Line 1157, Address: 0x27d1f0, Func Offset: 0x690
	// Line 1156, Address: 0x27d1f8, Func Offset: 0x698
	// Line 1157, Address: 0x27d1fc, Func Offset: 0x69c
	// Line 1158, Address: 0x27d204, Func Offset: 0x6a4
	// Line 1157, Address: 0x27d20c, Func Offset: 0x6ac
	// Line 1159, Address: 0x27d210, Func Offset: 0x6b0
	// Line 1158, Address: 0x27d214, Func Offset: 0x6b4
	// Line 1159, Address: 0x27d220, Func Offset: 0x6c0
	// Line 1161, Address: 0x27d228, Func Offset: 0x6c8
	// Line 1163, Address: 0x27d258, Func Offset: 0x6f8
	// Line 1161, Address: 0x27d260, Func Offset: 0x700
	// Line 1165, Address: 0x27d26c, Func Offset: 0x70c
	// Line 1162, Address: 0x27d270, Func Offset: 0x710
	// Line 1164, Address: 0x27d274, Func Offset: 0x714
	// Line 1162, Address: 0x27d27c, Func Offset: 0x71c
	// Line 1165, Address: 0x27d284, Func Offset: 0x724
	// Line 1166, Address: 0x27d29c, Func Offset: 0x73c
	// Line 1167, Address: 0x27d2a4, Func Offset: 0x744
	// Line 1166, Address: 0x27d2ac, Func Offset: 0x74c
	// Line 1167, Address: 0x27d2b0, Func Offset: 0x750
	// Line 1168, Address: 0x27d2c4, Func Offset: 0x764
	// Line 1169, Address: 0x27d2cc, Func Offset: 0x76c
	// Line 1170, Address: 0x27d2e0, Func Offset: 0x780
	// Line 1171, Address: 0x27d2e8, Func Offset: 0x788
	// Line 1170, Address: 0x27d2f0, Func Offset: 0x790
	// Line 1171, Address: 0x27d2f4, Func Offset: 0x794
	// Line 1174, Address: 0x27d30c, Func Offset: 0x7ac
	// Line 1179, Address: 0x27d318, Func Offset: 0x7b8
	// Line 1180, Address: 0x27d324, Func Offset: 0x7c4
	// Line 1184, Address: 0x27d330, Func Offset: 0x7d0
	// Line 1181, Address: 0x27d338, Func Offset: 0x7d8
	// Line 1184, Address: 0x27d33c, Func Offset: 0x7dc
	// Line 1186, Address: 0x27d374, Func Offset: 0x814
	// Line 1184, Address: 0x27d37c, Func Offset: 0x81c
	// Line 1188, Address: 0x27d384, Func Offset: 0x824
	// Line 1184, Address: 0x27d388, Func Offset: 0x828
	// Line 1187, Address: 0x27d38c, Func Offset: 0x82c
	// Line 1184, Address: 0x27d390, Func Offset: 0x830
	// Line 1185, Address: 0x27d398, Func Offset: 0x838
	// Line 1188, Address: 0x27d3a0, Func Offset: 0x840
	// Line 1187, Address: 0x27d3a8, Func Offset: 0x848
	// Line 1185, Address: 0x27d3ac, Func Offset: 0x84c
	// Line 1188, Address: 0x27d3b0, Func Offset: 0x850
	// Line 1189, Address: 0x27d3c0, Func Offset: 0x860
	// Line 1190, Address: 0x27d3c8, Func Offset: 0x868
	// Line 1189, Address: 0x27d3d0, Func Offset: 0x870
	// Line 1190, Address: 0x27d3d4, Func Offset: 0x874
	// Line 1191, Address: 0x27d3e8, Func Offset: 0x888
	// Line 1192, Address: 0x27d3f0, Func Offset: 0x890
	// Line 1193, Address: 0x27d404, Func Offset: 0x8a4
	// Line 1194, Address: 0x27d40c, Func Offset: 0x8ac
	// Line 1193, Address: 0x27d414, Func Offset: 0x8b4
	// Line 1194, Address: 0x27d418, Func Offset: 0x8b8
	// Line 1197, Address: 0x27d430, Func Offset: 0x8d0
	// Line 1204, Address: 0x27d43c, Func Offset: 0x8dc
	// Line 1205, Address: 0x27d46c, Func Offset: 0x90c
	// Line 1206, Address: 0x27d478, Func Offset: 0x918
	// Line 1211, Address: 0x27d498, Func Offset: 0x938
	// Line 1212, Address: 0x27d4a8, Func Offset: 0x948
	// Line 1213, Address: 0x27d4b4, Func Offset: 0x954
	// Line 1215, Address: 0x27d4c8, Func Offset: 0x968
	// Line 1216, Address: 0x27d4d0, Func Offset: 0x970
	// Line 1219, Address: 0x27d4dc, Func Offset: 0x97c
	// Line 1221, Address: 0x27d4f0, Func Offset: 0x990
	// Line 1227, Address: 0x27d4f8, Func Offset: 0x998
	// Line 1221, Address: 0x27d500, Func Offset: 0x9a0
	// Line 1230, Address: 0x27d504, Func Offset: 0x9a4
	// Line 1221, Address: 0x27d50c, Func Offset: 0x9ac
	// Line 1222, Address: 0x27d528, Func Offset: 0x9c8
	// Line 1230, Address: 0x27d534, Func Offset: 0x9d4
	// Line 1222, Address: 0x27d538, Func Offset: 0x9d8
	// Line 1223, Address: 0x27d554, Func Offset: 0x9f4
	// Line 1224, Address: 0x27d57c, Func Offset: 0xa1c
	// Line 1225, Address: 0x27d584, Func Offset: 0xa24
	// Line 1226, Address: 0x27d58c, Func Offset: 0xa2c
	// Line 1228, Address: 0x27d598, Func Offset: 0xa38
	// Line 1227, Address: 0x27d59c, Func Offset: 0xa3c
	// Line 1228, Address: 0x27d5a0, Func Offset: 0xa40
	// Line 1227, Address: 0x27d5a4, Func Offset: 0xa44
	// Line 1228, Address: 0x27d5a8, Func Offset: 0xa48
	// Line 1227, Address: 0x27d5ac, Func Offset: 0xa4c
	// Line 1228, Address: 0x27d5b0, Func Offset: 0xa50
	// Line 1229, Address: 0x27d5b4, Func Offset: 0xa54
	// Line 1230, Address: 0x27d5b8, Func Offset: 0xa58
	// Line 1232, Address: 0x27d5c8, Func Offset: 0xa68
	// Line 1233, Address: 0x27d5d0, Func Offset: 0xa70
	// Line 1236, Address: 0x27d5d8, Func Offset: 0xa78
	// Line 1239, Address: 0x27d5e0, Func Offset: 0xa80
	// Line 1234, Address: 0x27d5e8, Func Offset: 0xa88
	// Line 1239, Address: 0x27d5f0, Func Offset: 0xa90
	// Line 1235, Address: 0x27d5f4, Func Offset: 0xa94
	// Line 1237, Address: 0x27d600, Func Offset: 0xaa0
	// Line 1236, Address: 0x27d604, Func Offset: 0xaa4
	// Line 1237, Address: 0x27d608, Func Offset: 0xaa8
	// Line 1236, Address: 0x27d60c, Func Offset: 0xaac
	// Line 1237, Address: 0x27d610, Func Offset: 0xab0
	// Line 1236, Address: 0x27d614, Func Offset: 0xab4
	// Line 1237, Address: 0x27d618, Func Offset: 0xab8
	// Line 1238, Address: 0x27d61c, Func Offset: 0xabc
	// Line 1239, Address: 0x27d620, Func Offset: 0xac0
	// Line 1241, Address: 0x27d630, Func Offset: 0xad0
	// Line 1243, Address: 0x27d638, Func Offset: 0xad8
	// Line 1245, Address: 0x27d640, Func Offset: 0xae0
	// Line 1250, Address: 0x27d648, Func Offset: 0xae8
	// Line 1245, Address: 0x27d650, Func Offset: 0xaf0
	// Line 1247, Address: 0x27d654, Func Offset: 0xaf4
	// Line 1245, Address: 0x27d658, Func Offset: 0xaf8
	// Line 1247, Address: 0x27d65c, Func Offset: 0xafc
	// Line 1245, Address: 0x27d660, Func Offset: 0xb00
	// Line 1250, Address: 0x27d664, Func Offset: 0xb04
	// Line 1247, Address: 0x27d668, Func Offset: 0xb08
	// Line 1250, Address: 0x27d684, Func Offset: 0xb24
	// Line 1251, Address: 0x27d69c, Func Offset: 0xb3c
	// Line 1252, Address: 0x27d6b8, Func Offset: 0xb58
	// Line 1254, Address: 0x27d6d0, Func Offset: 0xb70
	// Line 1256, Address: 0x27d6e4, Func Offset: 0xb84
	// Line 1258, Address: 0x27d6ec, Func Offset: 0xb8c
	// Line 1262, Address: 0x27d6f4, Func Offset: 0xb94
	// Line 1258, Address: 0x27d6fc, Func Offset: 0xb9c
	// Line 1260, Address: 0x27d700, Func Offset: 0xba0
	// Line 1258, Address: 0x27d704, Func Offset: 0xba4
	// Line 1260, Address: 0x27d708, Func Offset: 0xba8
	// Line 1258, Address: 0x27d70c, Func Offset: 0xbac
	// Line 1262, Address: 0x27d710, Func Offset: 0xbb0
	// Line 1260, Address: 0x27d714, Func Offset: 0xbb4
	// Line 1262, Address: 0x27d730, Func Offset: 0xbd0
	// Line 1265, Address: 0x27d744, Func Offset: 0xbe4
	// Line 1270, Address: 0x27d74c, Func Offset: 0xbec
	// Line 1276, Address: 0x27d758, Func Offset: 0xbf8
	// Line 1270, Address: 0x27d760, Func Offset: 0xc00
	// Line 1274, Address: 0x27d768, Func Offset: 0xc08
	// Line 1270, Address: 0x27d76c, Func Offset: 0xc0c
	// Line 1276, Address: 0x27d770, Func Offset: 0xc10
	// Line 1270, Address: 0x27d778, Func Offset: 0xc18
	// Line 1276, Address: 0x27d77c, Func Offset: 0xc1c
	// Line 1277, Address: 0x27d7a0, Func Offset: 0xc40
	// Line 1278, Address: 0x27d7d4, Func Offset: 0xc74
	// Line 1284, Address: 0x27d808, Func Offset: 0xca8
	// Line 1285, Address: 0x27d818, Func Offset: 0xcb8
	// Line 1288, Address: 0x27d820, Func Offset: 0xcc0
	// Line 1291, Address: 0x27d828, Func Offset: 0xcc8
	// Line 1286, Address: 0x27d830, Func Offset: 0xcd0
	// Line 1291, Address: 0x27d838, Func Offset: 0xcd8
	// Line 1287, Address: 0x27d83c, Func Offset: 0xcdc
	// Line 1289, Address: 0x27d848, Func Offset: 0xce8
	// Line 1288, Address: 0x27d84c, Func Offset: 0xcec
	// Line 1289, Address: 0x27d850, Func Offset: 0xcf0
	// Line 1288, Address: 0x27d854, Func Offset: 0xcf4
	// Line 1289, Address: 0x27d858, Func Offset: 0xcf8
	// Line 1288, Address: 0x27d85c, Func Offset: 0xcfc
	// Line 1289, Address: 0x27d860, Func Offset: 0xd00
	// Line 1290, Address: 0x27d864, Func Offset: 0xd04
	// Line 1291, Address: 0x27d868, Func Offset: 0xd08
	// Line 1293, Address: 0x27d878, Func Offset: 0xd18
	// Line 1294, Address: 0x27d880, Func Offset: 0xd20
	// Line 1297, Address: 0x27d888, Func Offset: 0xd28
	// Line 1300, Address: 0x27d890, Func Offset: 0xd30
	// Line 1295, Address: 0x27d898, Func Offset: 0xd38
	// Line 1300, Address: 0x27d8a0, Func Offset: 0xd40
	// Line 1296, Address: 0x27d8a4, Func Offset: 0xd44
	// Line 1298, Address: 0x27d8b0, Func Offset: 0xd50
	// Line 1297, Address: 0x27d8b4, Func Offset: 0xd54
	// Line 1298, Address: 0x27d8b8, Func Offset: 0xd58
	// Line 1297, Address: 0x27d8bc, Func Offset: 0xd5c
	// Line 1298, Address: 0x27d8c0, Func Offset: 0xd60
	// Line 1297, Address: 0x27d8c4, Func Offset: 0xd64
	// Line 1298, Address: 0x27d8c8, Func Offset: 0xd68
	// Line 1299, Address: 0x27d8cc, Func Offset: 0xd6c
	// Line 1300, Address: 0x27d8d0, Func Offset: 0xd70
	// Line 1302, Address: 0x27d8e0, Func Offset: 0xd80
	// Line 1304, Address: 0x27d8e8, Func Offset: 0xd88
	// Line 1306, Address: 0x27d8f0, Func Offset: 0xd90
	// Line 1311, Address: 0x27d8f8, Func Offset: 0xd98
	// Line 1306, Address: 0x27d900, Func Offset: 0xda0
	// Line 1308, Address: 0x27d904, Func Offset: 0xda4
	// Line 1306, Address: 0x27d908, Func Offset: 0xda8
	// Line 1308, Address: 0x27d90c, Func Offset: 0xdac
	// Line 1306, Address: 0x27d910, Func Offset: 0xdb0
	// Line 1311, Address: 0x27d914, Func Offset: 0xdb4
	// Line 1308, Address: 0x27d918, Func Offset: 0xdb8
	// Line 1311, Address: 0x27d934, Func Offset: 0xdd4
	// Line 1312, Address: 0x27d948, Func Offset: 0xde8
	// Line 1313, Address: 0x27d950, Func Offset: 0xdf0
	// Line 1316, Address: 0x27d958, Func Offset: 0xdf8
	// Line 1323, Address: 0x27d960, Func Offset: 0xe00
	// Line 1314, Address: 0x27d968, Func Offset: 0xe08
	// Line 1315, Address: 0x27d970, Func Offset: 0xe10
	// Line 1318, Address: 0x27d97c, Func Offset: 0xe1c
	// Line 1322, Address: 0x27d980, Func Offset: 0xe20
	// Line 1318, Address: 0x27d984, Func Offset: 0xe24
	// Line 1322, Address: 0x27d988, Func Offset: 0xe28
	// Line 1318, Address: 0x27d98c, Func Offset: 0xe2c
	// Line 1316, Address: 0x27d990, Func Offset: 0xe30
	// Line 1322, Address: 0x27d994, Func Offset: 0xe34
	// Line 1316, Address: 0x27d998, Func Offset: 0xe38
	// Line 1318, Address: 0x27d99c, Func Offset: 0xe3c
	// Line 1316, Address: 0x27d9a0, Func Offset: 0xe40
	// Line 1322, Address: 0x27d9a4, Func Offset: 0xe44
	// Line 1323, Address: 0x27d9ac, Func Offset: 0xe4c
	// Line 1325, Address: 0x27d9c0, Func Offset: 0xe60
	// Line 1326, Address: 0x27d9c8, Func Offset: 0xe68
	// Line 1329, Address: 0x27d9d0, Func Offset: 0xe70
	// Line 1336, Address: 0x27d9d8, Func Offset: 0xe78
	// Line 1327, Address: 0x27d9e0, Func Offset: 0xe80
	// Line 1328, Address: 0x27d9e8, Func Offset: 0xe88
	// Line 1331, Address: 0x27d9f4, Func Offset: 0xe94
	// Line 1335, Address: 0x27d9f8, Func Offset: 0xe98
	// Line 1331, Address: 0x27d9fc, Func Offset: 0xe9c
	// Line 1335, Address: 0x27da00, Func Offset: 0xea0
	// Line 1331, Address: 0x27da04, Func Offset: 0xea4
	// Line 1329, Address: 0x27da08, Func Offset: 0xea8
	// Line 1335, Address: 0x27da0c, Func Offset: 0xeac
	// Line 1329, Address: 0x27da10, Func Offset: 0xeb0
	// Line 1331, Address: 0x27da14, Func Offset: 0xeb4
	// Line 1329, Address: 0x27da18, Func Offset: 0xeb8
	// Line 1335, Address: 0x27da1c, Func Offset: 0xebc
	// Line 1336, Address: 0x27da24, Func Offset: 0xec4
	// Line 1338, Address: 0x27da38, Func Offset: 0xed8
	// Line 1340, Address: 0x27da40, Func Offset: 0xee0
	// Line 1342, Address: 0x27da48, Func Offset: 0xee8
	// Line 1351, Address: 0x27da50, Func Offset: 0xef0
	// Line 1342, Address: 0x27da58, Func Offset: 0xef8
	// Line 1348, Address: 0x27da5c, Func Offset: 0xefc
	// Line 1342, Address: 0x27da60, Func Offset: 0xf00
	// Line 1348, Address: 0x27da64, Func Offset: 0xf04
	// Line 1342, Address: 0x27da68, Func Offset: 0xf08
	// Line 1348, Address: 0x27da6c, Func Offset: 0xf0c
	// Line 1351, Address: 0x27da74, Func Offset: 0xf14
	// Line 1348, Address: 0x27da78, Func Offset: 0xf18
	// Line 1351, Address: 0x27da98, Func Offset: 0xf38
	// Line 1354, Address: 0x27dab0, Func Offset: 0xf50
	// Line 1361, Address: 0x27dabc, Func Offset: 0xf5c
	// Line 1369, Address: 0x27dac4, Func Offset: 0xf64
	// Line 1354, Address: 0x27dac8, Func Offset: 0xf68
	// Line 1369, Address: 0x27dad4, Func Offset: 0xf74
	// Line 1354, Address: 0x27dad8, Func Offset: 0xf78
	// Line 1359, Address: 0x27daf0, Func Offset: 0xf90
	// Line 1369, Address: 0x27daf8, Func Offset: 0xf98
	// Line 1361, Address: 0x27dafc, Func Offset: 0xf9c
	// Line 1367, Address: 0x27db00, Func Offset: 0xfa0
	// Line 1361, Address: 0x27db08, Func Offset: 0xfa8
	// Line 1367, Address: 0x27db0c, Func Offset: 0xfac
	// Line 1361, Address: 0x27db10, Func Offset: 0xfb0
	// Line 1367, Address: 0x27db14, Func Offset: 0xfb4
	// Line 1369, Address: 0x27db3c, Func Offset: 0xfdc
	// Line 1372, Address: 0x27db54, Func Offset: 0xff4
	// Line 1377, Address: 0x27db5c, Func Offset: 0xffc
	// Line 1372, Address: 0x27db64, Func Offset: 0x1004
	// Line 1377, Address: 0x27db70, Func Offset: 0x1010
	// Line 1379, Address: 0x27db84, Func Offset: 0x1024
	// Line 1383, Address: 0x27db9c, Func Offset: 0x103c
	// Line 1385, Address: 0x27dbac, Func Offset: 0x104c
	// Line 1389, Address: 0x27dbb4, Func Offset: 0x1054
	// Line 1385, Address: 0x27dbb8, Func Offset: 0x1058
	// Line 1386, Address: 0x27dbbc, Func Offset: 0x105c
	// Line 1385, Address: 0x27dbc0, Func Offset: 0x1060
	// Line 1386, Address: 0x27dbc8, Func Offset: 0x1068
	// Line 1387, Address: 0x27dbd0, Func Offset: 0x1070
	// Line 1386, Address: 0x27dbd4, Func Offset: 0x1074
	// Line 1387, Address: 0x27dbd8, Func Offset: 0x1078
	// Line 1386, Address: 0x27dbdc, Func Offset: 0x107c
	// Line 1387, Address: 0x27dbe0, Func Offset: 0x1080
	// Line 1388, Address: 0x27dbe4, Func Offset: 0x1084
	// Line 1387, Address: 0x27dbec, Func Offset: 0x108c
	// Line 1388, Address: 0x27dbf4, Func Offset: 0x1094
	// Line 1389, Address: 0x27dbfc, Func Offset: 0x109c
	// Line 1390, Address: 0x27dc04, Func Offset: 0x10a4
	// Line 1392, Address: 0x27dc10, Func Offset: 0x10b0
	// Line 1393, Address: 0x27dc48, Func Offset: 0x10e8
	// Line 1394, Address: 0x27dc6c, Func Offset: 0x110c
	// Line 1401, Address: 0x27dc90, Func Offset: 0x1130
	// Func End, Address: 0x27dcb4, Func Offset: 0x1154
}

// 
// Start address: 0x27dcc0
void bhSetEventCamera(int evc_no, int key_no)
{
	float pz;
	float px;
	_anon28 pos;
	_anon17* kfp;
	// Line 1408, Address: 0x27dcc0, Func Offset: 0
	// Line 1415, Address: 0x27dcd8, Func Offset: 0x18
	// Line 1425, Address: 0x27dce0, Func Offset: 0x20
	// Line 1415, Address: 0x27dcf0, Func Offset: 0x30
	// Line 1417, Address: 0x27dcf4, Func Offset: 0x34
	// Line 1425, Address: 0x27dcfc, Func Offset: 0x3c
	// Line 1415, Address: 0x27dd00, Func Offset: 0x40
	// Line 1417, Address: 0x27dd08, Func Offset: 0x48
	// Line 1418, Address: 0x27dd24, Func Offset: 0x64
	// Line 1420, Address: 0x27dd44, Func Offset: 0x84
	// Line 1421, Address: 0x27dd58, Func Offset: 0x98
	// Line 1423, Address: 0x27dd6c, Func Offset: 0xac
	// Line 1425, Address: 0x27dd74, Func Offset: 0xb4
	// Line 1426, Address: 0x27dd7c, Func Offset: 0xbc
	// Line 1425, Address: 0x27dd84, Func Offset: 0xc4
	// Line 1426, Address: 0x27dd88, Func Offset: 0xc8
	// Line 1425, Address: 0x27dd90, Func Offset: 0xd0
	// Line 1426, Address: 0x27dd98, Func Offset: 0xd8
	// Line 1427, Address: 0x27dd9c, Func Offset: 0xdc
	// Line 1428, Address: 0x27dda8, Func Offset: 0xe8
	// Line 1429, Address: 0x27ddbc, Func Offset: 0xfc
	// Line 1430, Address: 0x27ddd0, Func Offset: 0x110
	// Line 1431, Address: 0x27dde4, Func Offset: 0x124
	// Line 1432, Address: 0x27ddf8, Func Offset: 0x138
	// Line 1433, Address: 0x27de0c, Func Offset: 0x14c
	// Line 1434, Address: 0x27de20, Func Offset: 0x160
	// Line 1435, Address: 0x27de28, Func Offset: 0x168
	// Line 1437, Address: 0x27de34, Func Offset: 0x174
	// Line 1440, Address: 0x27de40, Func Offset: 0x180
	// Line 1442, Address: 0x27de4c, Func Offset: 0x18c
	// Line 1443, Address: 0x27de54, Func Offset: 0x194
	// Line 1442, Address: 0x27de58, Func Offset: 0x198
	// Line 1443, Address: 0x27de5c, Func Offset: 0x19c
	// Line 1442, Address: 0x27de68, Func Offset: 0x1a8
	// Line 1444, Address: 0x27de6c, Func Offset: 0x1ac
	// Line 1443, Address: 0x27de70, Func Offset: 0x1b0
	// Line 1444, Address: 0x27de74, Func Offset: 0x1b4
	// Line 1446, Address: 0x27de7c, Func Offset: 0x1bc
	// Line 1450, Address: 0x27debc, Func Offset: 0x1fc
	// Line 1452, Address: 0x27df10, Func Offset: 0x250
	// Line 1453, Address: 0x27df1c, Func Offset: 0x25c
	// Line 1456, Address: 0x27df24, Func Offset: 0x264
	// Line 1454, Address: 0x27df2c, Func Offset: 0x26c
	// Line 1453, Address: 0x27df34, Func Offset: 0x274
	// Line 1454, Address: 0x27df40, Func Offset: 0x280
	// Line 1456, Address: 0x27df48, Func Offset: 0x288
	// Line 1458, Address: 0x27df50, Func Offset: 0x290
	// Line 1459, Address: 0x27df78, Func Offset: 0x2b8
	// Line 1460, Address: 0x27df84, Func Offset: 0x2c4
	// Line 1461, Address: 0x27df90, Func Offset: 0x2d0
	// Line 1466, Address: 0x27df9c, Func Offset: 0x2dc
	// Line 1467, Address: 0x27dfb8, Func Offset: 0x2f8
	// Line 1469, Address: 0x27dfd8, Func Offset: 0x318
	// Line 1470, Address: 0x27dfe0, Func Offset: 0x320
	// Line 1471, Address: 0x27dfec, Func Offset: 0x32c
	// Line 1472, Address: 0x27dff8, Func Offset: 0x338
	// Line 1473, Address: 0x27e004, Func Offset: 0x344
	// Line 1475, Address: 0x27e010, Func Offset: 0x350
	// Line 1476, Address: 0x27e018, Func Offset: 0x358
	// Line 1475, Address: 0x27e01c, Func Offset: 0x35c
	// Line 1476, Address: 0x27e020, Func Offset: 0x360
	// Line 1475, Address: 0x27e024, Func Offset: 0x364
	// Line 1476, Address: 0x27e02c, Func Offset: 0x36c
	// Line 1477, Address: 0x27e038, Func Offset: 0x378
	// Line 1478, Address: 0x27e040, Func Offset: 0x380
	// Func End, Address: 0x27e05c, Func Offset: 0x39c
}

// 
// Start address: 0x27e060
void bhSetEventFixedCut(int cno, int kno)
{
	_anon17* kfp;
	// Line 1486, Address: 0x27e060, Func Offset: 0
	// Line 1493, Address: 0x27e06c, Func Offset: 0xc
	// Line 1505, Address: 0x27e074, Func Offset: 0x14
	// Line 1516, Address: 0x27e080, Func Offset: 0x20
	// Line 1493, Address: 0x27e084, Func Offset: 0x24
	// Line 1495, Address: 0x27e08c, Func Offset: 0x2c
	// Line 1505, Address: 0x27e090, Func Offset: 0x30
	// Line 1516, Address: 0x27e094, Func Offset: 0x34
	// Line 1493, Address: 0x27e098, Func Offset: 0x38
	// Line 1495, Address: 0x27e0a0, Func Offset: 0x40
	// Line 1497, Address: 0x27e0a8, Func Offset: 0x48
	// Line 1495, Address: 0x27e0ac, Func Offset: 0x4c
	// Line 1497, Address: 0x27e0b4, Func Offset: 0x54
	// Line 1498, Address: 0x27e0c4, Func Offset: 0x64
	// Line 1500, Address: 0x27e0d8, Func Offset: 0x78
	// Line 1501, Address: 0x27e0f4, Func Offset: 0x94
	// Line 1503, Address: 0x27e108, Func Offset: 0xa8
	// Line 1505, Address: 0x27e110, Func Offset: 0xb0
	// Line 1506, Address: 0x27e118, Func Offset: 0xb8
	// Line 1505, Address: 0x27e120, Func Offset: 0xc0
	// Line 1506, Address: 0x27e124, Func Offset: 0xc4
	// Line 1505, Address: 0x27e12c, Func Offset: 0xcc
	// Line 1506, Address: 0x27e134, Func Offset: 0xd4
	// Line 1507, Address: 0x27e138, Func Offset: 0xd8
	// Line 1505, Address: 0x27e140, Func Offset: 0xe0
	// Line 1507, Address: 0x27e144, Func Offset: 0xe4
	// Line 1508, Address: 0x27e148, Func Offset: 0xe8
	// Line 1509, Address: 0x27e15c, Func Offset: 0xfc
	// Line 1510, Address: 0x27e170, Func Offset: 0x110
	// Line 1511, Address: 0x27e184, Func Offset: 0x124
	// Line 1512, Address: 0x27e198, Func Offset: 0x138
	// Line 1513, Address: 0x27e1ac, Func Offset: 0x14c
	// Line 1514, Address: 0x27e1c0, Func Offset: 0x160
	// Line 1515, Address: 0x27e1c8, Func Offset: 0x168
	// Line 1516, Address: 0x27e1d4, Func Offset: 0x174
	// Line 1517, Address: 0x27e1d8, Func Offset: 0x178
	// Line 1518, Address: 0x27e1e0, Func Offset: 0x180
	// Line 1517, Address: 0x27e1e8, Func Offset: 0x188
	// Line 1518, Address: 0x27e1f4, Func Offset: 0x194
	// Line 1520, Address: 0x27e1fc, Func Offset: 0x19c
	// Line 1522, Address: 0x27e204, Func Offset: 0x1a4
	// Line 1523, Address: 0x27e22c, Func Offset: 0x1cc
	// Line 1524, Address: 0x27e238, Func Offset: 0x1d8
	// Line 1525, Address: 0x27e244, Func Offset: 0x1e4
	// Line 1530, Address: 0x27e250, Func Offset: 0x1f0
	// Line 1531, Address: 0x27e26c, Func Offset: 0x20c
	// Line 1533, Address: 0x27e28c, Func Offset: 0x22c
	// Line 1534, Address: 0x27e294, Func Offset: 0x234
	// Line 1535, Address: 0x27e2a0, Func Offset: 0x240
	// Line 1536, Address: 0x27e2ac, Func Offset: 0x24c
	// Line 1537, Address: 0x27e2b8, Func Offset: 0x258
	// Line 1539, Address: 0x27e2c4, Func Offset: 0x264
	// Line 1540, Address: 0x27e2cc, Func Offset: 0x26c
	// Line 1539, Address: 0x27e2d0, Func Offset: 0x270
	// Line 1540, Address: 0x27e2d4, Func Offset: 0x274
	// Line 1539, Address: 0x27e2d8, Func Offset: 0x278
	// Line 1540, Address: 0x27e2e0, Func Offset: 0x280
	// Line 1542, Address: 0x27e2e4, Func Offset: 0x284
	// Line 1540, Address: 0x27e2ec, Func Offset: 0x28c
	// Line 1542, Address: 0x27e2f8, Func Offset: 0x298
	// Line 1543, Address: 0x27e310, Func Offset: 0x2b0
	// Line 1544, Address: 0x27e330, Func Offset: 0x2d0
	// Line 1546, Address: 0x27e338, Func Offset: 0x2d8
	// Func End, Address: 0x27e348, Func Offset: 0x2e8
}

// 
// Start address: 0x27e350
void bhSetEventHideObjLgt(int cno, int kno)
{
	int i;
	_anon14* lp;
	_anon17* kfp;
	npobj* obj;
	// Line 1552, Address: 0x27e350, Func Offset: 0
	// Line 1559, Address: 0x27e368, Func Offset: 0x18
	// Line 1561, Address: 0x27e380, Func Offset: 0x30
	// Line 1559, Address: 0x27e388, Func Offset: 0x38
	// Line 1561, Address: 0x27e394, Func Offset: 0x44
	// Line 1562, Address: 0x27e39c, Func Offset: 0x4c
	// Line 1563, Address: 0x27e3a4, Func Offset: 0x54
	// Line 1564, Address: 0x27e3b0, Func Offset: 0x60
	// Line 1565, Address: 0x27e3c4, Func Offset: 0x74
	// Line 1566, Address: 0x27e3cc, Func Offset: 0x7c
	// Line 1567, Address: 0x27e3d4, Func Offset: 0x84
	// Line 1569, Address: 0x27e3e4, Func Offset: 0x94
	// Line 1567, Address: 0x27e3e8, Func Offset: 0x98
	// Line 1570, Address: 0x27e3ec, Func Offset: 0x9c
	// Line 1572, Address: 0x27e408, Func Offset: 0xb8
	// Line 1573, Address: 0x27e40c, Func Offset: 0xbc
	// Line 1574, Address: 0x27e414, Func Offset: 0xc4
	// Line 1575, Address: 0x27e428, Func Offset: 0xd8
	// Line 1576, Address: 0x27e434, Func Offset: 0xe4
	// Line 1577, Address: 0x27e43c, Func Offset: 0xec
	// Line 1579, Address: 0x27e448, Func Offset: 0xf8
	// Line 1580, Address: 0x27e468, Func Offset: 0x118
	// Func End, Address: 0x27e484, Func Offset: 0x134
}

// 
// Start address: 0x27e490
void bhInitEventCamera()
{
	short az1;
	short az0;
	short ay1;
	short ay0;
	short ax1;
	short ax0;
	int j;
	int i;
	unsigned int r;
	float faz;
	float fay;
	float fax;
	float* cr;
	float* pf;
	float* an;
	float* ps;
	_anon17* jkfp;
	_anon17* kfp;
	_anon5* jecp;
	_anon5* ecp;
	// Line 1587, Address: 0x27e490, Func Offset: 0
	// Line 1605, Address: 0x27e49c, Func Offset: 0xc
	// Line 1606, Address: 0x27e4c0, Func Offset: 0x30
	// Line 1607, Address: 0x27e4d0, Func Offset: 0x40
	// Line 1608, Address: 0x27e4e0, Func Offset: 0x50
	// Line 1609, Address: 0x27e4e4, Func Offset: 0x54
	// Line 1608, Address: 0x27e4e8, Func Offset: 0x58
	// Line 1610, Address: 0x27e4f4, Func Offset: 0x64
	// Line 1611, Address: 0x27e4fc, Func Offset: 0x6c
	// Line 1612, Address: 0x27e500, Func Offset: 0x70
	// Line 1613, Address: 0x27e508, Func Offset: 0x78
	// Line 1614, Address: 0x27e518, Func Offset: 0x88
	// Line 1618, Address: 0x27e51c, Func Offset: 0x8c
	// Line 1617, Address: 0x27e520, Func Offset: 0x90
	// Line 1619, Address: 0x27e524, Func Offset: 0x94
	// Line 1620, Address: 0x27e528, Func Offset: 0x98
	// Line 1627, Address: 0x27e530, Func Offset: 0xa0
	// Line 1623, Address: 0x27e534, Func Offset: 0xa4
	// Line 1621, Address: 0x27e53c, Func Offset: 0xac
	// Line 1620, Address: 0x27e540, Func Offset: 0xb0
	// Line 1622, Address: 0x27e544, Func Offset: 0xb4
	// Line 1627, Address: 0x27e548, Func Offset: 0xb8
	// Line 1621, Address: 0x27e54c, Func Offset: 0xbc
	// Line 1624, Address: 0x27e550, Func Offset: 0xc0
	// Line 1625, Address: 0x27e554, Func Offset: 0xc4
	// Line 1626, Address: 0x27e558, Func Offset: 0xc8
	// Line 1624, Address: 0x27e55c, Func Offset: 0xcc
	// Line 1628, Address: 0x27e560, Func Offset: 0xd0
	// Line 1620, Address: 0x27e564, Func Offset: 0xd4
	// Line 1625, Address: 0x27e568, Func Offset: 0xd8
	// Line 1636, Address: 0x27e56c, Func Offset: 0xdc
	// Line 1626, Address: 0x27e570, Func Offset: 0xe0
	// Line 1628, Address: 0x27e574, Func Offset: 0xe4
	// Line 1629, Address: 0x27e578, Func Offset: 0xe8
	// Line 1622, Address: 0x27e57c, Func Offset: 0xec
	// Line 1629, Address: 0x27e580, Func Offset: 0xf0
	// Line 1620, Address: 0x27e584, Func Offset: 0xf4
	// Line 1629, Address: 0x27e588, Func Offset: 0xf8
	// Line 1621, Address: 0x27e58c, Func Offset: 0xfc
	// Line 1630, Address: 0x27e590, Func Offset: 0x100
	// Line 1622, Address: 0x27e594, Func Offset: 0x104
	// Line 1631, Address: 0x27e598, Func Offset: 0x108
	// Line 1632, Address: 0x27e59c, Func Offset: 0x10c
	// Line 1633, Address: 0x27e5a0, Func Offset: 0x110
	// Line 1632, Address: 0x27e5a4, Func Offset: 0x114
	// Line 1633, Address: 0x27e5a8, Func Offset: 0x118
	// Line 1634, Address: 0x27e5bc, Func Offset: 0x12c
	// Line 1635, Address: 0x27e5c4, Func Offset: 0x134
	// Line 1636, Address: 0x27e5cc, Func Offset: 0x13c
	// Line 1639, Address: 0x27e5d8, Func Offset: 0x148
	// Line 1640, Address: 0x27e608, Func Offset: 0x178
	// Line 1641, Address: 0x27e640, Func Offset: 0x1b0
	// Line 1642, Address: 0x27e678, Func Offset: 0x1e8
	// Line 1644, Address: 0x27e684, Func Offset: 0x1f4
	// Line 1645, Address: 0x27e688, Func Offset: 0x1f8
	// Line 1646, Address: 0x27e68c, Func Offset: 0x1fc
	// Line 1647, Address: 0x27e690, Func Offset: 0x200
	// Line 1643, Address: 0x27e698, Func Offset: 0x208
	// Line 1647, Address: 0x27e69c, Func Offset: 0x20c
	// Line 1648, Address: 0x27e6a0, Func Offset: 0x210
	// Line 1649, Address: 0x27e6a4, Func Offset: 0x214
	// Line 1647, Address: 0x27e6a8, Func Offset: 0x218
	// Line 1648, Address: 0x27e6ac, Func Offset: 0x21c
	// Line 1649, Address: 0x27e6b0, Func Offset: 0x220
	// Line 1647, Address: 0x27e6b4, Func Offset: 0x224
	// Line 1648, Address: 0x27e6b8, Func Offset: 0x228
	// Line 1649, Address: 0x27e6bc, Func Offset: 0x22c
	// Line 1652, Address: 0x27e6c0, Func Offset: 0x230
	// Line 1651, Address: 0x27e6c4, Func Offset: 0x234
	// Line 1653, Address: 0x27e6c8, Func Offset: 0x238
	// Line 1659, Address: 0x27e6cc, Func Offset: 0x23c
	// Line 1662, Address: 0x27e6d4, Func Offset: 0x244
	// Line 1653, Address: 0x27e6d8, Func Offset: 0x248
	// Line 1654, Address: 0x27e6dc, Func Offset: 0x24c
	// Line 1655, Address: 0x27e6e4, Func Offset: 0x254
	// Line 1656, Address: 0x27e6ec, Func Offset: 0x25c
	// Line 1657, Address: 0x27e6f0, Func Offset: 0x260
	// Line 1658, Address: 0x27e6f4, Func Offset: 0x264
	// Line 1659, Address: 0x27e6f8, Func Offset: 0x268
	// Line 1655, Address: 0x27e6fc, Func Offset: 0x26c
	// Line 1658, Address: 0x27e700, Func Offset: 0x270
	// Line 1659, Address: 0x27e704, Func Offset: 0x274
	// Line 1660, Address: 0x27e718, Func Offset: 0x288
	// Line 1661, Address: 0x27e720, Func Offset: 0x290
	// Line 1662, Address: 0x27e728, Func Offset: 0x298
	// Line 1665, Address: 0x27e734, Func Offset: 0x2a4
	// Line 1666, Address: 0x27e764, Func Offset: 0x2d4
	// Line 1667, Address: 0x27e79c, Func Offset: 0x30c
	// Line 1668, Address: 0x27e7d4, Func Offset: 0x344
	// Line 1672, Address: 0x27e7e4, Func Offset: 0x354
	// Line 1669, Address: 0x27e7e8, Func Offset: 0x358
	// Line 1673, Address: 0x27e7ec, Func Offset: 0x35c
	// Line 1670, Address: 0x27e7f0, Func Offset: 0x360
	// Line 1679, Address: 0x27e7f4, Func Offset: 0x364
	// Line 1669, Address: 0x27e7fc, Func Offset: 0x36c
	// Line 1671, Address: 0x27e800, Func Offset: 0x370
	// Line 1679, Address: 0x27e804, Func Offset: 0x374
	// Line 1674, Address: 0x27e80c, Func Offset: 0x37c
	// Line 1679, Address: 0x27e810, Func Offset: 0x380
	// Line 1670, Address: 0x27e814, Func Offset: 0x384
	// Line 1675, Address: 0x27e818, Func Offset: 0x388
	// Line 1671, Address: 0x27e81c, Func Offset: 0x38c
	// Line 1680, Address: 0x27e820, Func Offset: 0x390
	// Line 1679, Address: 0x27e824, Func Offset: 0x394
	// Line 1681, Address: 0x27e828, Func Offset: 0x398
	// Line 1679, Address: 0x27e82c, Func Offset: 0x39c
	// Line 1680, Address: 0x27e830, Func Offset: 0x3a0
	// Line 1681, Address: 0x27e834, Func Offset: 0x3a4
	// Line 1680, Address: 0x27e838, Func Offset: 0x3a8
	// Line 1681, Address: 0x27e83c, Func Offset: 0x3ac
	// Line 1680, Address: 0x27e840, Func Offset: 0x3b0
	// Line 1681, Address: 0x27e844, Func Offset: 0x3b4
	// Line 1680, Address: 0x27e848, Func Offset: 0x3b8
	// Line 1682, Address: 0x27e84c, Func Offset: 0x3bc
	// Line 1683, Address: 0x27e854, Func Offset: 0x3c4
	// Line 1684, Address: 0x27e870, Func Offset: 0x3e0
	// Line 1687, Address: 0x27e874, Func Offset: 0x3e4
	// Line 1690, Address: 0x27e878, Func Offset: 0x3e8
	// Line 1688, Address: 0x27e87c, Func Offset: 0x3ec
	// Line 1696, Address: 0x27e880, Func Offset: 0x3f0
	// Line 1687, Address: 0x27e888, Func Offset: 0x3f8
	// Line 1689, Address: 0x27e88c, Func Offset: 0x3fc
	// Line 1696, Address: 0x27e890, Func Offset: 0x400
	// Line 1691, Address: 0x27e898, Func Offset: 0x408
	// Line 1696, Address: 0x27e89c, Func Offset: 0x40c
	// Line 1688, Address: 0x27e8a0, Func Offset: 0x410
	// Line 1692, Address: 0x27e8a4, Func Offset: 0x414
	// Line 1689, Address: 0x27e8a8, Func Offset: 0x418
	// Line 1685, Address: 0x27e8ac, Func Offset: 0x41c
	// Line 1696, Address: 0x27e8b0, Func Offset: 0x420
	// Line 1697, Address: 0x27e8b4, Func Offset: 0x424
	// Line 1698, Address: 0x27e8b8, Func Offset: 0x428
	// Line 1686, Address: 0x27e8bc, Func Offset: 0x42c
	// Line 1696, Address: 0x27e8c0, Func Offset: 0x430
	// Line 1697, Address: 0x27e8c4, Func Offset: 0x434
	// Line 1698, Address: 0x27e8c8, Func Offset: 0x438
	// Line 1697, Address: 0x27e8cc, Func Offset: 0x43c
	// Line 1698, Address: 0x27e8d0, Func Offset: 0x440
	// Line 1697, Address: 0x27e8d4, Func Offset: 0x444
	// Line 1698, Address: 0x27e8d8, Func Offset: 0x448
	// Line 1697, Address: 0x27e8dc, Func Offset: 0x44c
	// Line 1698, Address: 0x27e8e0, Func Offset: 0x450
	// Line 1700, Address: 0x27e8e4, Func Offset: 0x454
	// Line 1701, Address: 0x27e8e8, Func Offset: 0x458
	// Line 1702, Address: 0x27e8f8, Func Offset: 0x468
	// Func End, Address: 0x27e908, Func Offset: 0x478
}

// 
// Start address: 0x27e910
void bhControlEventCamera()
{
	float pz;
	float px;
	float ans[3];
	_anon28 pos;
	_anon17* kfp;
	_anon5* ecp;
	// Line 1709, Address: 0x27e910, Func Offset: 0
	// Line 1718, Address: 0x27e92c, Func Offset: 0x1c
	// Line 1720, Address: 0x27e95c, Func Offset: 0x4c
	// Line 1721, Address: 0x27e964, Func Offset: 0x54
	// Line 1720, Address: 0x27e968, Func Offset: 0x58
	// Line 1721, Address: 0x27e96c, Func Offset: 0x5c
	// Line 1720, Address: 0x27e970, Func Offset: 0x60
	// Line 1721, Address: 0x27e978, Func Offset: 0x68
	// Line 1722, Address: 0x27e990, Func Offset: 0x80
	// Line 1723, Address: 0x27e99c, Func Offset: 0x8c
	// Line 1722, Address: 0x27e9a8, Func Offset: 0x98
	// Line 1723, Address: 0x27e9b0, Func Offset: 0xa0
	// Line 1724, Address: 0x27e9b8, Func Offset: 0xa8
	// Line 1723, Address: 0x27e9bc, Func Offset: 0xac
	// Line 1724, Address: 0x27e9c4, Func Offset: 0xb4
	// Line 1726, Address: 0x27e9d4, Func Offset: 0xc4
	// Line 1729, Address: 0x27e9e0, Func Offset: 0xd0
	// Line 1726, Address: 0x27e9e4, Func Offset: 0xd4
	// Line 1727, Address: 0x27e9f0, Func Offset: 0xe0
	// Line 1728, Address: 0x27e9f8, Func Offset: 0xe8
	// Line 1729, Address: 0x27ea00, Func Offset: 0xf0
	// Line 1730, Address: 0x27ea04, Func Offset: 0xf4
	// Line 1731, Address: 0x27ea0c, Func Offset: 0xfc
	// Line 1733, Address: 0x27ea18, Func Offset: 0x108
	// Line 1731, Address: 0x27ea1c, Func Offset: 0x10c
	// Line 1733, Address: 0x27ea24, Func Offset: 0x114
	// Line 1735, Address: 0x27ea34, Func Offset: 0x124
	// Line 1736, Address: 0x27ea48, Func Offset: 0x138
	// Line 1735, Address: 0x27ea50, Func Offset: 0x140
	// Line 1736, Address: 0x27ea60, Func Offset: 0x150
	// Line 1737, Address: 0x27ea68, Func Offset: 0x158
	// Line 1738, Address: 0x27ea70, Func Offset: 0x160
	// Line 1739, Address: 0x27ea7c, Func Offset: 0x16c
	// Line 1741, Address: 0x27eaac, Func Offset: 0x19c
	// Line 1743, Address: 0x27eab4, Func Offset: 0x1a4
	// Line 1748, Address: 0x27eaec, Func Offset: 0x1dc
	// Line 1752, Address: 0x27eaf4, Func Offset: 0x1e4
	// Line 1749, Address: 0x27eaf8, Func Offset: 0x1e8
	// Line 1750, Address: 0x27eafc, Func Offset: 0x1ec
	// Line 1748, Address: 0x27eb00, Func Offset: 0x1f0
	// Line 1749, Address: 0x27eb04, Func Offset: 0x1f4
	// Line 1752, Address: 0x27eb0c, Func Offset: 0x1fc
	// Line 1749, Address: 0x27eb14, Func Offset: 0x204
	// Line 1750, Address: 0x27eb18, Func Offset: 0x208
	// Line 1752, Address: 0x27eb20, Func Offset: 0x210
	// Line 1750, Address: 0x27eb24, Func Offset: 0x214
	// Line 1752, Address: 0x27eb28, Func Offset: 0x218
	// Line 1754, Address: 0x27eb50, Func Offset: 0x240
	// Line 1755, Address: 0x27eb70, Func Offset: 0x260
	// Line 1756, Address: 0x27eb90, Func Offset: 0x280
	// Line 1758, Address: 0x27ebb0, Func Offset: 0x2a0
	// Line 1766, Address: 0x27ec50, Func Offset: 0x340
	// Line 1768, Address: 0x27ec5c, Func Offset: 0x34c
	// Line 1769, Address: 0x27ec64, Func Offset: 0x354
	// Line 1768, Address: 0x27ec68, Func Offset: 0x358
	// Line 1769, Address: 0x27ec6c, Func Offset: 0x35c
	// Line 1768, Address: 0x27ec78, Func Offset: 0x368
	// Line 1770, Address: 0x27ec7c, Func Offset: 0x36c
	// Line 1769, Address: 0x27ec80, Func Offset: 0x370
	// Line 1770, Address: 0x27ec84, Func Offset: 0x374
	// Line 1772, Address: 0x27ec8c, Func Offset: 0x37c
	// Line 1776, Address: 0x27ecc4, Func Offset: 0x3b4
	// Line 1779, Address: 0x27ed10, Func Offset: 0x400
	// Line 1781, Address: 0x27ed48, Func Offset: 0x438
	// Line 1782, Address: 0x27ed68, Func Offset: 0x458
	// Line 1785, Address: 0x27ed70, Func Offset: 0x460
	// Line 1782, Address: 0x27ed7c, Func Offset: 0x46c
	// Line 1783, Address: 0x27ed80, Func Offset: 0x470
	// Line 1785, Address: 0x27ed88, Func Offset: 0x478
	// Line 1783, Address: 0x27ed8c, Func Offset: 0x47c
	// Line 1785, Address: 0x27ed90, Func Offset: 0x480
	// Line 1787, Address: 0x27edb8, Func Offset: 0x4a8
	// Line 1788, Address: 0x27edd8, Func Offset: 0x4c8
	// Line 1789, Address: 0x27edfc, Func Offset: 0x4ec
	// Line 1790, Address: 0x27ee1c, Func Offset: 0x50c
	// Line 1791, Address: 0x27ee40, Func Offset: 0x530
	// Line 1792, Address: 0x27ee60, Func Offset: 0x550
	// Line 1796, Address: 0x27ee84, Func Offset: 0x574
	// Line 1797, Address: 0x27eeb4, Func Offset: 0x5a4
	// Line 1798, Address: 0x27eee0, Func Offset: 0x5d0
	// Line 1800, Address: 0x27eef8, Func Offset: 0x5e8
	// Line 1801, Address: 0x27ef00, Func Offset: 0x5f0
	// Line 1802, Address: 0x27ef08, Func Offset: 0x5f8
	// Line 1811, Address: 0x27ef1c, Func Offset: 0x60c
	// Line 1812, Address: 0x27ef38, Func Offset: 0x628
	// Line 1813, Address: 0x27ef44, Func Offset: 0x634
	// Line 1814, Address: 0x27ef58, Func Offset: 0x648
	// Line 1815, Address: 0x27ef60, Func Offset: 0x650
	// Line 1817, Address: 0x27ef68, Func Offset: 0x658
	// Line 1818, Address: 0x27ef74, Func Offset: 0x664
	// Line 1819, Address: 0x27ef88, Func Offset: 0x678
	// Line 1820, Address: 0x27ef8c, Func Offset: 0x67c
	// Line 1826, Address: 0x27ef94, Func Offset: 0x684
	// Line 1828, Address: 0x27efa8, Func Offset: 0x698
	// Line 1830, Address: 0x27efb0, Func Offset: 0x6a0
	// Line 1832, Address: 0x27efc8, Func Offset: 0x6b8
	// Line 1834, Address: 0x27efd0, Func Offset: 0x6c0
	// Line 1832, Address: 0x27efd4, Func Offset: 0x6c4
	// Line 1834, Address: 0x27efdc, Func Offset: 0x6cc
	// Line 1835, Address: 0x27f00c, Func Offset: 0x6fc
	// Line 1836, Address: 0x27f014, Func Offset: 0x704
	// Line 1838, Address: 0x27f01c, Func Offset: 0x70c
	// Line 1840, Address: 0x27f054, Func Offset: 0x744
	// Line 1844, Address: 0x27f05c, Func Offset: 0x74c
	// Line 1841, Address: 0x27f060, Func Offset: 0x750
	// Line 1842, Address: 0x27f064, Func Offset: 0x754
	// Line 1840, Address: 0x27f068, Func Offset: 0x758
	// Line 1841, Address: 0x27f06c, Func Offset: 0x75c
	// Line 1844, Address: 0x27f074, Func Offset: 0x764
	// Line 1841, Address: 0x27f07c, Func Offset: 0x76c
	// Line 1842, Address: 0x27f080, Func Offset: 0x770
	// Line 1844, Address: 0x27f088, Func Offset: 0x778
	// Line 1842, Address: 0x27f08c, Func Offset: 0x77c
	// Line 1844, Address: 0x27f090, Func Offset: 0x780
	// Line 1846, Address: 0x27f0b8, Func Offset: 0x7a8
	// Line 1847, Address: 0x27f0d8, Func Offset: 0x7c8
	// Line 1848, Address: 0x27f0f8, Func Offset: 0x7e8
	// Line 1850, Address: 0x27f118, Func Offset: 0x808
	// Line 1857, Address: 0x27f1a0, Func Offset: 0x890
	// Line 1859, Address: 0x27f1ac, Func Offset: 0x89c
	// Line 1860, Address: 0x27f1b4, Func Offset: 0x8a4
	// Line 1859, Address: 0x27f1b8, Func Offset: 0x8a8
	// Line 1860, Address: 0x27f1bc, Func Offset: 0x8ac
	// Line 1859, Address: 0x27f1c8, Func Offset: 0x8b8
	// Line 1861, Address: 0x27f1cc, Func Offset: 0x8bc
	// Line 1860, Address: 0x27f1d0, Func Offset: 0x8c0
	// Line 1861, Address: 0x27f1d4, Func Offset: 0x8c4
	// Line 1863, Address: 0x27f1dc, Func Offset: 0x8cc
	// Line 1867, Address: 0x27f214, Func Offset: 0x904
	// Line 1870, Address: 0x27f260, Func Offset: 0x950
	// Line 1872, Address: 0x27f298, Func Offset: 0x988
	// Line 1873, Address: 0x27f2b8, Func Offset: 0x9a8
	// Line 1876, Address: 0x27f2c0, Func Offset: 0x9b0
	// Line 1873, Address: 0x27f2cc, Func Offset: 0x9bc
	// Line 1874, Address: 0x27f2d0, Func Offset: 0x9c0
	// Line 1876, Address: 0x27f2d8, Func Offset: 0x9c8
	// Line 1874, Address: 0x27f2dc, Func Offset: 0x9cc
	// Line 1876, Address: 0x27f2e0, Func Offset: 0x9d0
	// Line 1878, Address: 0x27f308, Func Offset: 0x9f8
	// Line 1879, Address: 0x27f328, Func Offset: 0xa18
	// Line 1880, Address: 0x27f34c, Func Offset: 0xa3c
	// Line 1881, Address: 0x27f36c, Func Offset: 0xa5c
	// Line 1882, Address: 0x27f390, Func Offset: 0xa80
	// Line 1883, Address: 0x27f3b0, Func Offset: 0xaa0
	// Line 1887, Address: 0x27f3d4, Func Offset: 0xac4
	// Line 1919, Address: 0x27f404, Func Offset: 0xaf4
	// Func End, Address: 0x27f424, Func Offset: 0xb14
}

// 
// Start address: 0x27f430
void bhCheckEvtCamLockPosition()
{
	short az1;
	short az0;
	short ay1;
	short ay0;
	short ax1;
	short ax0;
	int j;
	int i;
	float faz;
	float fay;
	float fax;
	float pz;
	float px;
	float* an;
	_anon17* jkfp;
	_anon17* kfp;
	_anon5* jecp;
	_anon5* ecp;
	_anon28 pos;
	short az;
	short ay;
	short ax;
	// Line 1923, Address: 0x27f430, Func Offset: 0
	// Line 1940, Address: 0x27f468, Func Offset: 0x38
	// Line 1941, Address: 0x27f48c, Func Offset: 0x5c
	// Line 1942, Address: 0x27f49c, Func Offset: 0x6c
	// Line 1943, Address: 0x27f4b0, Func Offset: 0x80
	// Line 1944, Address: 0x27f4b8, Func Offset: 0x88
	// Line 1943, Address: 0x27f4bc, Func Offset: 0x8c
	// Line 1945, Address: 0x27f4cc, Func Offset: 0x9c
	// Line 1946, Address: 0x27f4d4, Func Offset: 0xa4
	// Line 1947, Address: 0x27f4d8, Func Offset: 0xa8
	// Line 1948, Address: 0x27f4e0, Func Offset: 0xb0
	// Line 1949, Address: 0x27f4f4, Func Offset: 0xc4
	// Line 1952, Address: 0x27f4fc, Func Offset: 0xcc
	// Line 1953, Address: 0x27f508, Func Offset: 0xd8
	// Line 1956, Address: 0x27f514, Func Offset: 0xe4
	// Line 1955, Address: 0x27f518, Func Offset: 0xe8
	// Line 1956, Address: 0x27f520, Func Offset: 0xf0
	// Line 1955, Address: 0x27f528, Func Offset: 0xf8
	// Line 1956, Address: 0x27f52c, Func Offset: 0xfc
	// Line 1957, Address: 0x27f530, Func Offset: 0x100
	// Line 1959, Address: 0x27f53c, Func Offset: 0x10c
	// Line 1963, Address: 0x27f564, Func Offset: 0x134
	// Line 1959, Address: 0x27f574, Func Offset: 0x144
	// Line 1963, Address: 0x27f580, Func Offset: 0x150
	// Line 1964, Address: 0x27f5b0, Func Offset: 0x180
	// Line 1965, Address: 0x27f5b8, Func Offset: 0x188
	// Line 1966, Address: 0x27f5bc, Func Offset: 0x18c
	// Line 1970, Address: 0x27f5c4, Func Offset: 0x194
	// Line 1969, Address: 0x27f5c8, Func Offset: 0x198
	// Line 1970, Address: 0x27f5cc, Func Offset: 0x19c
	// Line 1968, Address: 0x27f5d0, Func Offset: 0x1a0
	// Line 1969, Address: 0x27f5d4, Func Offset: 0x1a4
	// Line 1970, Address: 0x27f5e0, Func Offset: 0x1b0
	// Line 1972, Address: 0x27f5e4, Func Offset: 0x1b4
	// Line 1969, Address: 0x27f5ec, Func Offset: 0x1bc
	// Line 1971, Address: 0x27f5f0, Func Offset: 0x1c0
	// Line 1969, Address: 0x27f5f8, Func Offset: 0x1c8
	// Line 1971, Address: 0x27f5fc, Func Offset: 0x1cc
	// Line 1973, Address: 0x27f600, Func Offset: 0x1d0
	// Line 1974, Address: 0x27f604, Func Offset: 0x1d4
	// Line 1971, Address: 0x27f608, Func Offset: 0x1d8
	// Line 1975, Address: 0x27f60c, Func Offset: 0x1dc
	// Line 1976, Address: 0x27f610, Func Offset: 0x1e0
	// Line 1978, Address: 0x27f61c, Func Offset: 0x1ec
	// Line 1979, Address: 0x27f628, Func Offset: 0x1f8
	// Line 1982, Address: 0x27f634, Func Offset: 0x204
	// Line 1981, Address: 0x27f638, Func Offset: 0x208
	// Line 1982, Address: 0x27f640, Func Offset: 0x210
	// Line 1981, Address: 0x27f648, Func Offset: 0x218
	// Line 1982, Address: 0x27f64c, Func Offset: 0x21c
	// Line 1983, Address: 0x27f650, Func Offset: 0x220
	// Line 1985, Address: 0x27f65c, Func Offset: 0x22c
	// Line 1989, Address: 0x27f684, Func Offset: 0x254
	// Line 1985, Address: 0x27f694, Func Offset: 0x264
	// Line 1989, Address: 0x27f6a0, Func Offset: 0x270
	// Line 1990, Address: 0x27f6d0, Func Offset: 0x2a0
	// Line 1991, Address: 0x27f6d8, Func Offset: 0x2a8
	// Line 1992, Address: 0x27f6dc, Func Offset: 0x2ac
	// Line 1996, Address: 0x27f6e4, Func Offset: 0x2b4
	// Line 1995, Address: 0x27f6e8, Func Offset: 0x2b8
	// Line 1996, Address: 0x27f6ec, Func Offset: 0x2bc
	// Line 1994, Address: 0x27f6f0, Func Offset: 0x2c0
	// Line 1995, Address: 0x27f6f4, Func Offset: 0x2c4
	// Line 1996, Address: 0x27f700, Func Offset: 0x2d0
	// Line 1997, Address: 0x27f704, Func Offset: 0x2d4
	// Line 1995, Address: 0x27f70c, Func Offset: 0x2dc
	// Line 1997, Address: 0x27f710, Func Offset: 0x2e0
	// Line 1995, Address: 0x27f714, Func Offset: 0x2e4
	// Line 1997, Address: 0x27f718, Func Offset: 0x2e8
	// Line 2000, Address: 0x27f71c, Func Offset: 0x2ec
	// Line 1999, Address: 0x27f720, Func Offset: 0x2f0
	// Line 2001, Address: 0x27f724, Func Offset: 0x2f4
	// Line 2002, Address: 0x27f728, Func Offset: 0x2f8
	// Line 2003, Address: 0x27f72c, Func Offset: 0x2fc
	// Line 2004, Address: 0x27f730, Func Offset: 0x300
	// Line 2008, Address: 0x27f740, Func Offset: 0x310
	// Line 2006, Address: 0x27f744, Func Offset: 0x314
	// Line 2009, Address: 0x27f748, Func Offset: 0x318
	// Line 2005, Address: 0x27f74c, Func Offset: 0x31c
	// Line 2007, Address: 0x27f754, Func Offset: 0x324
	// Line 2005, Address: 0x27f758, Func Offset: 0x328
	// Line 2006, Address: 0x27f75c, Func Offset: 0x32c
	// Line 2009, Address: 0x27f760, Func Offset: 0x330
	// Line 2010, Address: 0x27f768, Func Offset: 0x338
	// Line 2013, Address: 0x27f774, Func Offset: 0x344
	// Line 2012, Address: 0x27f778, Func Offset: 0x348
	// Line 2013, Address: 0x27f780, Func Offset: 0x350
	// Line 2012, Address: 0x27f788, Func Offset: 0x358
	// Line 2013, Address: 0x27f78c, Func Offset: 0x35c
	// Line 2014, Address: 0x27f790, Func Offset: 0x360
	// Line 2016, Address: 0x27f79c, Func Offset: 0x36c
	// Line 2020, Address: 0x27f7cc, Func Offset: 0x39c
	// Line 2016, Address: 0x27f7e0, Func Offset: 0x3b0
	// Line 2020, Address: 0x27f7e4, Func Offset: 0x3b4
	// Line 2021, Address: 0x27f814, Func Offset: 0x3e4
	// Line 2022, Address: 0x27f81c, Func Offset: 0x3ec
	// Line 2023, Address: 0x27f820, Func Offset: 0x3f0
	// Line 2026, Address: 0x27f828, Func Offset: 0x3f8
	// Line 2029, Address: 0x27f82c, Func Offset: 0x3fc
	// Line 2026, Address: 0x27f830, Func Offset: 0x400
	// Line 2027, Address: 0x27f834, Func Offset: 0x404
	// Line 2029, Address: 0x27f838, Func Offset: 0x408
	// Line 2026, Address: 0x27f83c, Func Offset: 0x40c
	// Line 2025, Address: 0x27f840, Func Offset: 0x410
	// Line 2026, Address: 0x27f844, Func Offset: 0x414
	// Line 2027, Address: 0x27f848, Func Offset: 0x418
	// Line 2028, Address: 0x27f850, Func Offset: 0x420
	// Line 2029, Address: 0x27f85c, Func Offset: 0x42c
	// Line 2030, Address: 0x27f864, Func Offset: 0x434
	// Line 2029, Address: 0x27f86c, Func Offset: 0x43c
	// Line 2031, Address: 0x27f878, Func Offset: 0x448
	// Line 2030, Address: 0x27f880, Func Offset: 0x450
	// Line 2029, Address: 0x27f888, Func Offset: 0x458
	// Line 2030, Address: 0x27f88c, Func Offset: 0x45c
	// Line 2031, Address: 0x27f898, Func Offset: 0x468
	// Line 2029, Address: 0x27f8a0, Func Offset: 0x470
	// Line 2031, Address: 0x27f8a4, Func Offset: 0x474
	// Line 2032, Address: 0x27f8ac, Func Offset: 0x47c
	// Line 2033, Address: 0x27f8b4, Func Offset: 0x484
	// Line 2038, Address: 0x27f8d4, Func Offset: 0x4a4
	// Line 2034, Address: 0x27f8d8, Func Offset: 0x4a8
	// Line 2040, Address: 0x27f8dc, Func Offset: 0x4ac
	// Line 2037, Address: 0x27f8e0, Func Offset: 0x4b0
	// Line 2039, Address: 0x27f8e8, Func Offset: 0x4b8
	// Line 2035, Address: 0x27f8ec, Func Offset: 0x4bc
	// Line 2036, Address: 0x27f8f0, Func Offset: 0x4c0
	// Line 2037, Address: 0x27f8f4, Func Offset: 0x4c4
	// Line 2038, Address: 0x27f8f8, Func Offset: 0x4c8
	// Line 2040, Address: 0x27f8fc, Func Offset: 0x4cc
	// Line 2041, Address: 0x27f904, Func Offset: 0x4d4
	// Line 2044, Address: 0x27f910, Func Offset: 0x4e0
	// Line 2043, Address: 0x27f914, Func Offset: 0x4e4
	// Line 2044, Address: 0x27f91c, Func Offset: 0x4ec
	// Line 2043, Address: 0x27f924, Func Offset: 0x4f4
	// Line 2044, Address: 0x27f928, Func Offset: 0x4f8
	// Line 2045, Address: 0x27f92c, Func Offset: 0x4fc
	// Line 2047, Address: 0x27f938, Func Offset: 0x508
	// Line 2051, Address: 0x27f968, Func Offset: 0x538
	// Line 2047, Address: 0x27f97c, Func Offset: 0x54c
	// Line 2051, Address: 0x27f980, Func Offset: 0x550
	// Line 2052, Address: 0x27f9b0, Func Offset: 0x580
	// Line 2053, Address: 0x27f9b8, Func Offset: 0x588
	// Line 2054, Address: 0x27f9bc, Func Offset: 0x58c
	// Line 2055, Address: 0x27f9c4, Func Offset: 0x594
	// Line 2057, Address: 0x27f9c8, Func Offset: 0x598
	// Line 2060, Address: 0x27f9cc, Func Offset: 0x59c
	// Line 2057, Address: 0x27f9d0, Func Offset: 0x5a0
	// Line 2058, Address: 0x27f9d4, Func Offset: 0x5a4
	// Line 2060, Address: 0x27f9d8, Func Offset: 0x5a8
	// Line 2057, Address: 0x27f9dc, Func Offset: 0x5ac
	// Line 2056, Address: 0x27f9e0, Func Offset: 0x5b0
	// Line 2057, Address: 0x27f9e4, Func Offset: 0x5b4
	// Line 2058, Address: 0x27f9e8, Func Offset: 0x5b8
	// Line 2059, Address: 0x27f9f0, Func Offset: 0x5c0
	// Line 2060, Address: 0x27f9fc, Func Offset: 0x5cc
	// Line 2061, Address: 0x27fa04, Func Offset: 0x5d4
	// Line 2060, Address: 0x27fa0c, Func Offset: 0x5dc
	// Line 2062, Address: 0x27fa18, Func Offset: 0x5e8
	// Line 2061, Address: 0x27fa20, Func Offset: 0x5f0
	// Line 2060, Address: 0x27fa28, Func Offset: 0x5f8
	// Line 2061, Address: 0x27fa2c, Func Offset: 0x5fc
	// Line 2062, Address: 0x27fa38, Func Offset: 0x608
	// Line 2060, Address: 0x27fa40, Func Offset: 0x610
	// Line 2062, Address: 0x27fa44, Func Offset: 0x614
	// Line 2065, Address: 0x27fa50, Func Offset: 0x620
	// Line 2066, Address: 0x27fa60, Func Offset: 0x630
	// Func End, Address: 0x27fa9c, Func Offset: 0x66c
}

// 
// Start address: 0x27faa0
void bhGetEvtCamLockPosition(_anon17* kfp, _anon28* pos)
{
	_anon3* psp;
	BH_PWORK* pwp;
	// Line 2070, Address: 0x27faa0, Func Offset: 0
	// Line 2075, Address: 0x27faa8, Func Offset: 0x8
	// Line 2077, Address: 0x27fad4, Func Offset: 0x34
	// Line 2078, Address: 0x27fad8, Func Offset: 0x38
	// Line 2079, Address: 0x27fadc, Func Offset: 0x3c
	// Line 2081, Address: 0x27fae4, Func Offset: 0x44
	// Line 2082, Address: 0x27fb04, Func Offset: 0x64
	// Line 2083, Address: 0x27fb24, Func Offset: 0x84
	// Line 2085, Address: 0x27fb2c, Func Offset: 0x8c
	// Line 2086, Address: 0x27fb4c, Func Offset: 0xac
	// Line 2087, Address: 0x27fb78, Func Offset: 0xd8
	// Line 2089, Address: 0x27fb80, Func Offset: 0xe0
	// Line 2090, Address: 0x27fba0, Func Offset: 0x100
	// Line 2091, Address: 0x27fbcc, Func Offset: 0x12c
	// Line 2093, Address: 0x27fbd4, Func Offset: 0x134
	// Line 2094, Address: 0x27fbf4, Func Offset: 0x154
	// Line 2095, Address: 0x27fc30, Func Offset: 0x190
	// Line 2097, Address: 0x27fc38, Func Offset: 0x198
	// Line 2098, Address: 0x27fc3c, Func Offset: 0x19c
	// Line 2099, Address: 0x27fc5c, Func Offset: 0x1bc
	// Line 2100, Address: 0x27fc68, Func Offset: 0x1c8
	// Line 2099, Address: 0x27fc6c, Func Offset: 0x1cc
	// Line 2100, Address: 0x27fc78, Func Offset: 0x1d8
	// Line 2101, Address: 0x27fc84, Func Offset: 0x1e4
	// Line 2102, Address: 0x27fc94, Func Offset: 0x1f4
	// Line 2105, Address: 0x27fca4, Func Offset: 0x204
	// Line 2106, Address: 0x27fcb4, Func Offset: 0x214
	// Line 2107, Address: 0x27fcd0, Func Offset: 0x230
	// Line 2109, Address: 0x27fcdc, Func Offset: 0x23c
	// Line 2110, Address: 0x27fce8, Func Offset: 0x248
	// Line 2113, Address: 0x27fcf0, Func Offset: 0x250
	// Line 2116, Address: 0x27fd1c, Func Offset: 0x27c
	// Func End, Address: 0x27fd28, Func Offset: 0x288
}

// 
// Start address: 0x27fd30
void bhControlPlEyeCamera(unsigned int attr)
{
	short ahkn;
	short ay;
	short ax;
	int ct;
	float hkn;
	_anon21* ci;
	// Line 2123, Address: 0x27fd30, Func Offset: 0
	// Line 2130, Address: 0x27fd38, Func Offset: 0x8
	// Line 2132, Address: 0x27fd40, Func Offset: 0x10
	// Line 2130, Address: 0x27fd48, Func Offset: 0x18
	// Line 2132, Address: 0x27fd8c, Func Offset: 0x5c
	// Line 2137, Address: 0x27fd90, Func Offset: 0x60
	// Line 2130, Address: 0x27fd98, Func Offset: 0x68
	// Line 2132, Address: 0x27fd9c, Func Offset: 0x6c
	// Line 2138, Address: 0x27fda4, Func Offset: 0x74
	// Line 2132, Address: 0x27fda8, Func Offset: 0x78
	// Line 2136, Address: 0x27fdac, Func Offset: 0x7c
	// Line 2138, Address: 0x27fdb0, Func Offset: 0x80
	// Line 2136, Address: 0x27fdb8, Func Offset: 0x88
	// Line 2132, Address: 0x27fdbc, Func Offset: 0x8c
	// Line 2138, Address: 0x27fdc8, Func Offset: 0x98
	// Line 2140, Address: 0x27fdec, Func Offset: 0xbc
	// Line 2147, Address: 0x27fdf4, Func Offset: 0xc4
	// Line 2159, Address: 0x27fdf8, Func Offset: 0xc8
	// Line 2155, Address: 0x27fdfc, Func Offset: 0xcc
	// Line 2147, Address: 0x27fe04, Func Offset: 0xd4
	// Line 2140, Address: 0x27fe08, Func Offset: 0xd8
	// Line 2156, Address: 0x27fe10, Func Offset: 0xe0
	// Line 2159, Address: 0x27fe14, Func Offset: 0xe4
	// Line 2140, Address: 0x27fe18, Func Offset: 0xe8
	// Line 2144, Address: 0x27fe20, Func Offset: 0xf0
	// Line 2140, Address: 0x27fe24, Func Offset: 0xf4
	// Line 2141, Address: 0x27fe2c, Func Offset: 0xfc
	// Line 2142, Address: 0x27fe40, Func Offset: 0x110
	// Line 2143, Address: 0x27fe54, Func Offset: 0x124
	// Line 2144, Address: 0x27fe5c, Func Offset: 0x12c
	// Line 2145, Address: 0x27fe6c, Func Offset: 0x13c
	// Line 2147, Address: 0x27fe74, Func Offset: 0x144
	// Line 2148, Address: 0x27fe9c, Func Offset: 0x16c
	// Line 2149, Address: 0x27fec4, Func Offset: 0x194
	// Line 2155, Address: 0x27feec, Func Offset: 0x1bc
	// Line 2156, Address: 0x27fef4, Func Offset: 0x1c4
	// Line 2157, Address: 0x27fefc, Func Offset: 0x1cc
	// Line 2158, Address: 0x27ff04, Func Offset: 0x1d4
	// Line 2159, Address: 0x27ff0c, Func Offset: 0x1dc
	// Line 2160, Address: 0x27ff28, Func Offset: 0x1f8
	// Line 2159, Address: 0x27ff2c, Func Offset: 0x1fc
	// Line 2160, Address: 0x27ff3c, Func Offset: 0x20c
	// Line 2161, Address: 0x27ff40, Func Offset: 0x210
	// Line 2162, Address: 0x27ff48, Func Offset: 0x218
	// Line 2163, Address: 0x27ff50, Func Offset: 0x220
	// Line 2164, Address: 0x27ff6c, Func Offset: 0x23c
	// Line 2163, Address: 0x27ff70, Func Offset: 0x240
	// Line 2164, Address: 0x27ff80, Func Offset: 0x250
	// Line 2166, Address: 0x27ff84, Func Offset: 0x254
	// Line 2167, Address: 0x27ff8c, Func Offset: 0x25c
	// Line 2170, Address: 0x27ffb0, Func Offset: 0x280
	// Line 2168, Address: 0x27ffb4, Func Offset: 0x284
	// Line 2167, Address: 0x27ffb8, Func Offset: 0x288
	// Line 2170, Address: 0x27ffbc, Func Offset: 0x28c
	// Line 2167, Address: 0x27ffc0, Func Offset: 0x290
	// Line 2168, Address: 0x27ffcc, Func Offset: 0x29c
	// Line 2170, Address: 0x27ffd0, Func Offset: 0x2a0
	// Line 2174, Address: 0x27fff8, Func Offset: 0x2c8
	// Line 2175, Address: 0x28002c, Func Offset: 0x2fc
	// Line 2176, Address: 0x280040, Func Offset: 0x310
	// Line 2177, Address: 0x280054, Func Offset: 0x324
	// Line 2185, Address: 0x28005c, Func Offset: 0x32c
	// Line 2177, Address: 0x280060, Func Offset: 0x330
	// Line 2178, Address: 0x28006c, Func Offset: 0x33c
	// Line 2179, Address: 0x280080, Func Offset: 0x350
	// Line 2180, Address: 0x280094, Func Offset: 0x364
	// Line 2181, Address: 0x28009c, Func Offset: 0x36c
	// Line 2182, Address: 0x2800ac, Func Offset: 0x37c
	// Line 2183, Address: 0x2800b4, Func Offset: 0x384
	// Line 2184, Address: 0x2800c4, Func Offset: 0x394
	// Line 2185, Address: 0x2800d4, Func Offset: 0x3a4
	// Line 2187, Address: 0x2800d8, Func Offset: 0x3a8
	// Line 2189, Address: 0x2800e0, Func Offset: 0x3b0
	// Line 2190, Address: 0x2800e8, Func Offset: 0x3b8
	// Line 2191, Address: 0x2800fc, Func Offset: 0x3cc
	// Line 2192, Address: 0x280118, Func Offset: 0x3e8
	// Line 2194, Address: 0x280134, Func Offset: 0x404
	// Line 2195, Address: 0x280144, Func Offset: 0x414
	// Line 2204, Address: 0x28014c, Func Offset: 0x41c
	// Line 2195, Address: 0x280150, Func Offset: 0x420
	// Line 2196, Address: 0x28015c, Func Offset: 0x42c
	// Line 2197, Address: 0x280170, Func Offset: 0x440
	// Line 2199, Address: 0x280184, Func Offset: 0x454
	// Line 2200, Address: 0x28018c, Func Offset: 0x45c
	// Line 2201, Address: 0x2801b0, Func Offset: 0x480
	// Line 2202, Address: 0x2801b8, Func Offset: 0x488
	// Line 2203, Address: 0x2801c8, Func Offset: 0x498
	// Line 2204, Address: 0x2801cc, Func Offset: 0x49c
	// Line 2205, Address: 0x2801d4, Func Offset: 0x4a4
	// Line 2213, Address: 0x2801dc, Func Offset: 0x4ac
	// Line 2205, Address: 0x2801e0, Func Offset: 0x4b0
	// Line 2206, Address: 0x2801e4, Func Offset: 0x4b4
	// Line 2207, Address: 0x2801f0, Func Offset: 0x4c0
	// Line 2208, Address: 0x2801fc, Func Offset: 0x4cc
	// Line 2209, Address: 0x280208, Func Offset: 0x4d8
	// Line 2210, Address: 0x280214, Func Offset: 0x4e4
	// Line 2211, Address: 0x280220, Func Offset: 0x4f0
	// Line 2212, Address: 0x28022c, Func Offset: 0x4fc
	// Line 2213, Address: 0x280234, Func Offset: 0x504
	// Line 2214, Address: 0x28023c, Func Offset: 0x50c
	// Line 2215, Address: 0x280248, Func Offset: 0x518
	// Line 2217, Address: 0x28024c, Func Offset: 0x51c
	// Line 2220, Address: 0x280254, Func Offset: 0x524
	// Line 2230, Address: 0x280260, Func Offset: 0x530
	// Line 2220, Address: 0x280264, Func Offset: 0x534
	// Line 2230, Address: 0x280268, Func Offset: 0x538
	// Line 2220, Address: 0x28026c, Func Offset: 0x53c
	// Line 2221, Address: 0x28028c, Func Offset: 0x55c
	// Line 2222, Address: 0x2802b4, Func Offset: 0x584
	// Line 2228, Address: 0x2802dc, Func Offset: 0x5ac
	// Line 2229, Address: 0x2802e4, Func Offset: 0x5b4
	// Line 2230, Address: 0x2802ec, Func Offset: 0x5bc
	// Line 2231, Address: 0x280308, Func Offset: 0x5d8
	// Line 2230, Address: 0x28030c, Func Offset: 0x5dc
	// Line 2231, Address: 0x28031c, Func Offset: 0x5ec
	// Line 2232, Address: 0x280320, Func Offset: 0x5f0
	// Line 2233, Address: 0x280328, Func Offset: 0x5f8
	// Line 2234, Address: 0x280330, Func Offset: 0x600
	// Line 2235, Address: 0x28034c, Func Offset: 0x61c
	// Line 2234, Address: 0x280350, Func Offset: 0x620
	// Line 2235, Address: 0x280360, Func Offset: 0x630
	// Line 2237, Address: 0x280364, Func Offset: 0x634
	// Line 2238, Address: 0x28036c, Func Offset: 0x63c
	// Line 2241, Address: 0x280390, Func Offset: 0x660
	// Line 2239, Address: 0x280394, Func Offset: 0x664
	// Line 2238, Address: 0x280398, Func Offset: 0x668
	// Line 2241, Address: 0x28039c, Func Offset: 0x66c
	// Line 2238, Address: 0x2803a0, Func Offset: 0x670
	// Line 2239, Address: 0x2803ac, Func Offset: 0x67c
	// Line 2241, Address: 0x2803b0, Func Offset: 0x680
	// Line 2245, Address: 0x2803d8, Func Offset: 0x6a8
	// Line 2246, Address: 0x28040c, Func Offset: 0x6dc
	// Line 2247, Address: 0x280420, Func Offset: 0x6f0
	// Line 2248, Address: 0x280434, Func Offset: 0x704
	// Line 2256, Address: 0x28043c, Func Offset: 0x70c
	// Line 2248, Address: 0x280440, Func Offset: 0x710
	// Line 2249, Address: 0x280448, Func Offset: 0x718
	// Line 2250, Address: 0x280458, Func Offset: 0x728
	// Line 2251, Address: 0x280468, Func Offset: 0x738
	// Line 2252, Address: 0x280478, Func Offset: 0x748
	// Line 2253, Address: 0x280488, Func Offset: 0x758
	// Line 2254, Address: 0x280498, Func Offset: 0x768
	// Line 2255, Address: 0x2804a4, Func Offset: 0x774
	// Line 2256, Address: 0x2804b0, Func Offset: 0x780
	// Line 2260, Address: 0x2804c4, Func Offset: 0x794
	// Func End, Address: 0x2804d0, Func Offset: 0x7a0
}

// 
// Start address: 0x2804d0
void bhInitPlEyeCamera()
{
	int i;
	_anon14* lp;
	npobj* obj;
	// Line 2267, Address: 0x2804d0, Func Offset: 0
	// Line 2272, Address: 0x2804d8, Func Offset: 0x8
	// Line 2274, Address: 0x2804e8, Func Offset: 0x18
	// Line 2272, Address: 0x2804ec, Func Offset: 0x1c
	// Line 2274, Address: 0x2804f4, Func Offset: 0x24
	// Line 2275, Address: 0x280508, Func Offset: 0x38
	// Line 2276, Address: 0x280528, Func Offset: 0x58
	// Line 2277, Address: 0x280530, Func Offset: 0x60
	// Line 2276, Address: 0x280538, Func Offset: 0x68
	// Line 2277, Address: 0x280540, Func Offset: 0x70
	// Line 2278, Address: 0x280548, Func Offset: 0x78
	// Line 2277, Address: 0x28054c, Func Offset: 0x7c
	// Line 2278, Address: 0x280554, Func Offset: 0x84
	// Line 2280, Address: 0x280564, Func Offset: 0x94
	// Line 2281, Address: 0x280574, Func Offset: 0xa4
	// Line 2280, Address: 0x28057c, Func Offset: 0xac
	// Line 2281, Address: 0x280580, Func Offset: 0xb0
	// Line 2280, Address: 0x280584, Func Offset: 0xb4
	// Line 2281, Address: 0x28058c, Func Offset: 0xbc
	// Line 2282, Address: 0x280594, Func Offset: 0xc4
	// Line 2281, Address: 0x280598, Func Offset: 0xc8
	// Line 2282, Address: 0x2805a0, Func Offset: 0xd0
	// Line 2283, Address: 0x2805ac, Func Offset: 0xdc
	// Line 2286, Address: 0x2805b4, Func Offset: 0xe4
	// Line 2299, Address: 0x2805bc, Func Offset: 0xec
	// Line 2297, Address: 0x2805c4, Func Offset: 0xf4
	// Line 2286, Address: 0x2805c8, Func Offset: 0xf8
	// Line 2288, Address: 0x2805cc, Func Offset: 0xfc
	// Line 2300, Address: 0x2805d0, Func Offset: 0x100
	// Line 2302, Address: 0x2805d4, Func Offset: 0x104
	// Line 2286, Address: 0x2805d8, Func Offset: 0x108
	// Line 2288, Address: 0x2805e0, Func Offset: 0x110
	// Line 2302, Address: 0x2805e4, Func Offset: 0x114
	// Line 2288, Address: 0x2805ec, Func Offset: 0x11c
	// Line 2290, Address: 0x2805f0, Func Offset: 0x120
	// Line 2288, Address: 0x2805f4, Func Offset: 0x124
	// Line 2290, Address: 0x2805fc, Func Offset: 0x12c
	// Line 2291, Address: 0x280624, Func Offset: 0x154
	// Line 2292, Address: 0x280640, Func Offset: 0x170
	// Line 2293, Address: 0x280664, Func Offset: 0x194
	// Line 2294, Address: 0x28067c, Func Offset: 0x1ac
	// Line 2295, Address: 0x280690, Func Offset: 0x1c0
	// Line 2296, Address: 0x2806a0, Func Offset: 0x1d0
	// Line 2297, Address: 0x2806a8, Func Offset: 0x1d8
	// Line 2298, Address: 0x2806b0, Func Offset: 0x1e0
	// Line 2299, Address: 0x2806c0, Func Offset: 0x1f0
	// Line 2300, Address: 0x2806c4, Func Offset: 0x1f4
	// Line 2302, Address: 0x2806d4, Func Offset: 0x204
	// Line 2303, Address: 0x2806dc, Func Offset: 0x20c
	// Line 2304, Address: 0x2806e4, Func Offset: 0x214
	// Line 2305, Address: 0x2806f0, Func Offset: 0x220
	// Line 2306, Address: 0x2806fc, Func Offset: 0x22c
	// Line 2305, Address: 0x280700, Func Offset: 0x230
	// Line 2307, Address: 0x280704, Func Offset: 0x234
	// Line 2309, Address: 0x280720, Func Offset: 0x250
	// Line 2310, Address: 0x280724, Func Offset: 0x254
	// Line 2311, Address: 0x280734, Func Offset: 0x264
	// Line 2312, Address: 0x280738, Func Offset: 0x268
	// Line 2311, Address: 0x28073c, Func Offset: 0x26c
	// Line 2312, Address: 0x280744, Func Offset: 0x274
	// Line 2314, Address: 0x280760, Func Offset: 0x290
	// Line 2315, Address: 0x280778, Func Offset: 0x2a8
	// Line 2316, Address: 0x280784, Func Offset: 0x2b4
	// Line 2317, Address: 0x280790, Func Offset: 0x2c0
	// Line 2322, Address: 0x28079c, Func Offset: 0x2cc
	// Line 2323, Address: 0x2807b8, Func Offset: 0x2e8
	// Line 2325, Address: 0x2807d8, Func Offset: 0x308
	// Line 2326, Address: 0x2807e0, Func Offset: 0x310
	// Line 2327, Address: 0x2807ec, Func Offset: 0x31c
	// Line 2328, Address: 0x2807f8, Func Offset: 0x328
	// Line 2329, Address: 0x280804, Func Offset: 0x334
	// Line 2331, Address: 0x280810, Func Offset: 0x340
	// Line 2333, Address: 0x280818, Func Offset: 0x348
	// Line 2331, Address: 0x28081c, Func Offset: 0x34c
	// Line 2333, Address: 0x280820, Func Offset: 0x350
	// Line 2331, Address: 0x280824, Func Offset: 0x354
	// Line 2333, Address: 0x28082c, Func Offset: 0x35c
	// Line 2334, Address: 0x280848, Func Offset: 0x378
	// Line 2336, Address: 0x280870, Func Offset: 0x3a0
	// Line 2342, Address: 0x28088c, Func Offset: 0x3bc
	// Func End, Address: 0x280898, Func Offset: 0x3c8
}

// 
// Start address: 0x2808a0
void bhSetPlEyeCamera()
{
	short axn;
	short ay;
	_anon28 pos;
	// Line 2349, Address: 0x2808a0, Func Offset: 0
	// Line 2352, Address: 0x2808ac, Func Offset: 0xc
	// Line 2354, Address: 0x2808c8, Func Offset: 0x28
	// Line 2358, Address: 0x2808d0, Func Offset: 0x30
	// Line 2355, Address: 0x2808d4, Func Offset: 0x34
	// Line 2356, Address: 0x2808d8, Func Offset: 0x38
	// Line 2357, Address: 0x2808e0, Func Offset: 0x40
	// Line 2358, Address: 0x2808e8, Func Offset: 0x48
	// Line 2359, Address: 0x280908, Func Offset: 0x68
	// Line 2360, Address: 0x280920, Func Offset: 0x80
	// Line 2361, Address: 0x280930, Func Offset: 0x90
	// Line 2363, Address: 0x280938, Func Offset: 0x98
	// Line 2364, Address: 0x280940, Func Offset: 0xa0
	// Line 2365, Address: 0x280964, Func Offset: 0xc4
	// Line 2366, Address: 0x280970, Func Offset: 0xd0
	// Line 2368, Address: 0x280978, Func Offset: 0xd8
	// Line 2369, Address: 0x280994, Func Offset: 0xf4
	// Line 2370, Address: 0x2809a0, Func Offset: 0x100
	// Line 2372, Address: 0x2809ac, Func Offset: 0x10c
	// Line 2374, Address: 0x2809b4, Func Offset: 0x114
	// Line 2376, Address: 0x2809bc, Func Offset: 0x11c
	// Line 2375, Address: 0x2809c4, Func Offset: 0x124
	// Line 2376, Address: 0x2809cc, Func Offset: 0x12c
	// Line 2377, Address: 0x2809e8, Func Offset: 0x148
	// Line 2378, Address: 0x2809f0, Func Offset: 0x150
	// Line 2377, Address: 0x2809f4, Func Offset: 0x154
	// Line 2384, Address: 0x2809fc, Func Offset: 0x15c
	// Line 2385, Address: 0x280a00, Func Offset: 0x160
	// Line 2383, Address: 0x280a08, Func Offset: 0x168
	// Line 2386, Address: 0x280a0c, Func Offset: 0x16c
	// Line 2383, Address: 0x280a14, Func Offset: 0x174
	// Line 2387, Address: 0x280a18, Func Offset: 0x178
	// Line 2389, Address: 0x280a34, Func Offset: 0x194
	// Line 2391, Address: 0x280a3c, Func Offset: 0x19c
	// Line 2393, Address: 0x280a50, Func Offset: 0x1b0
	// Line 2391, Address: 0x280a54, Func Offset: 0x1b4
	// Line 2393, Address: 0x280a58, Func Offset: 0x1b8
	// Line 2391, Address: 0x280a5c, Func Offset: 0x1bc
	// Line 2392, Address: 0x280a74, Func Offset: 0x1d4
	// Line 2393, Address: 0x280a7c, Func Offset: 0x1dc
	// Line 2394, Address: 0x280a8c, Func Offset: 0x1ec
	// Line 2395, Address: 0x280a90, Func Offset: 0x1f0
	// Line 2397, Address: 0x280aa8, Func Offset: 0x208
	// Line 2398, Address: 0x280ab0, Func Offset: 0x210
	// Line 2399, Address: 0x280ad4, Func Offset: 0x234
	// Line 2402, Address: 0x280adc, Func Offset: 0x23c
	// Func End, Address: 0x280aec, Func Offset: 0x24c
}

// 
// Start address: 0x280af0
void bhControlMonitorCamera()
{
	// Line 2410, Address: 0x280af0, Func Offset: 0
	// Func End, Address: 0x280af8, Func Offset: 0x8
}

// 
// Start address: 0x280b00
float bhCalcActiveYpos(_anon10* cp)
{
	float yy0;
	_anon21* ci;
	// Line 2419, Address: 0x280b00, Func Offset: 0
	// Line 2420, Address: 0x280b08, Func Offset: 0x8
	// Line 2423, Address: 0x280b0c, Func Offset: 0xc
	// Line 2420, Address: 0x280b10, Func Offset: 0x10
	// Line 2423, Address: 0x280b14, Func Offset: 0x14
	// Line 2420, Address: 0x280b18, Func Offset: 0x18
	// Line 2419, Address: 0x280b20, Func Offset: 0x20
	// Line 2420, Address: 0x280b34, Func Offset: 0x34
	// Line 2419, Address: 0x280b38, Func Offset: 0x38
	// Line 2423, Address: 0x280b3c, Func Offset: 0x3c
	// Line 2420, Address: 0x280b44, Func Offset: 0x44
	// Line 2423, Address: 0x280b4c, Func Offset: 0x4c
	// Line 2420, Address: 0x280b58, Func Offset: 0x58
	// Line 2423, Address: 0x280b68, Func Offset: 0x68
	// Line 2424, Address: 0x280b88, Func Offset: 0x88
	// Func End, Address: 0x280b90, Func Offset: 0x90
}

// 
// Start address: 0x280b90
short bhCalcActiveZang(_anon10* cp)
{
	float ag0;
	float laz1;
	float laz0;
	_anon21* ci;
	// Line 2433, Address: 0x280b90, Func Offset: 0
	// Line 2438, Address: 0x280b98, Func Offset: 0x8
	// Line 2443, Address: 0x280b9c, Func Offset: 0xc
	// Line 2438, Address: 0x280ba0, Func Offset: 0x10
	// Line 2443, Address: 0x280ba4, Func Offset: 0x14
	// Line 2438, Address: 0x280ba8, Func Offset: 0x18
	// Line 2433, Address: 0x280bb0, Func Offset: 0x20
	// Line 2438, Address: 0x280bc4, Func Offset: 0x34
	// Line 2433, Address: 0x280bc8, Func Offset: 0x38
	// Line 2443, Address: 0x280bcc, Func Offset: 0x3c
	// Line 2434, Address: 0x280bd4, Func Offset: 0x44
	// Line 2435, Address: 0x280bd8, Func Offset: 0x48
	// Line 2438, Address: 0x280bdc, Func Offset: 0x4c
	// Line 2443, Address: 0x280be0, Func Offset: 0x50
	// Line 2434, Address: 0x280be8, Func Offset: 0x58
	// Line 2435, Address: 0x280bec, Func Offset: 0x5c
	// Line 2434, Address: 0x280bf0, Func Offset: 0x60
	// Line 2435, Address: 0x280bf4, Func Offset: 0x64
	// Line 2438, Address: 0x280bf8, Func Offset: 0x68
	// Line 2443, Address: 0x280bfc, Func Offset: 0x6c
	// Line 2438, Address: 0x280c00, Func Offset: 0x70
	// Line 2443, Address: 0x280c04, Func Offset: 0x74
	// Line 2438, Address: 0x280c08, Func Offset: 0x78
	// Line 2443, Address: 0x280c0c, Func Offset: 0x7c
	// Line 2438, Address: 0x280c10, Func Offset: 0x80
	// Line 2443, Address: 0x280c14, Func Offset: 0x84
	// Line 2438, Address: 0x280c18, Func Offset: 0x88
	// Line 2443, Address: 0x280c1c, Func Offset: 0x8c
	// Line 2438, Address: 0x280c20, Func Offset: 0x90
	// Line 2443, Address: 0x280c24, Func Offset: 0x94
	// Func End, Address: 0x280c40, Func Offset: 0xb0
}

// 
// Start address: 0x280c40
short bhCalcActivePers(_anon10* cp)
{
	unsigned char* psp;
	float ag0;
	float lap1;
	float lap0;
	// Line 2450, Address: 0x280c40, Func Offset: 0
	// Line 2455, Address: 0x280c60, Func Offset: 0x20
	// Line 2456, Address: 0x280c84, Func Offset: 0x44
	// Line 2457, Address: 0x280cd0, Func Offset: 0x90
	// Line 2460, Address: 0x280d1c, Func Offset: 0xdc
	// Line 2463, Address: 0x280d78, Func Offset: 0x138
	// Line 2460, Address: 0x280d7c, Func Offset: 0x13c
	// Line 2463, Address: 0x280d94, Func Offset: 0x154
	// Line 2464, Address: 0x280e1c, Func Offset: 0x1dc
	// Func End, Address: 0x280e40, Func Offset: 0x200
}

