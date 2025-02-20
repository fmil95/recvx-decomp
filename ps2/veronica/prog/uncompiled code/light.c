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
typedef struct _anon44;

typedef void(*type_84)(void*);

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
typedef BH_PWORK type_11[0];
typedef _anon0* type_12[512];
typedef _anon1* type_13[1300];
typedef char type_14[32];
typedef _anon0 type_15[0];
typedef float type_16[32];
typedef _anon0* type_17[512];
typedef _anon1* type_18[200];
typedef short type_19[32];
typedef _anon24 type_20[1];
typedef _anon0* type_21[128];
typedef unsigned int type_22[1];
typedef _anon7 type_23[256];
typedef _anon1* type_24[8];
typedef int* type_25[16];
typedef _anon0* type_26[128];
typedef _anon44 type_27[16];
typedef npobj* type_28[16];
typedef _anon0* type_29[128];
typedef int type_30[4];
typedef _anon1* type_31[16];
typedef unsigned int type_32[4];
typedef float type_33[4];
typedef _anon14 type_34[16];
typedef _anon0* type_35[512];
typedef float type_36[4];
typedef char type_37[256];
typedef float type_38[4];
typedef float type_39[4];
typedef float type_40[4];
typedef float type_41[4];
typedef _anon5* type_42[128];
typedef float type_43[3];
typedef unsigned char type_44[64];
typedef float type_45[3][20];
typedef float type_46[3];
typedef float type_47[3][20];
typedef float type_48[3];
typedef float type_49[3][20];
typedef char type_50[8];
typedef float type_51[3];
typedef float type_52[3][20];
typedef void* type_53[2];
typedef _anon1* type_54[256];
typedef int type_55[4];
typedef unsigned char* type_56[256];
typedef unsigned int type_57[2];
typedef short type_58[256];
typedef _anon9 type_59[4];
typedef float type_60[3];
typedef short type_61[256];
typedef int type_62[3];
typedef int type_63[8];
typedef float type_64[3];
typedef _anon1* type_65[256];
typedef _anon11 type_66[256];
typedef _anon24 type_67[450];
typedef _anon32 type_68[16];
typedef short type_69[256];
typedef char type_70[3];
typedef int type_71[64];
typedef _anon14 type_72[450];
typedef unsigned int type_73[16];
typedef char type_74[4];
typedef unsigned int type_75[8];
typedef _anon35 type_76[4];
typedef _anon2 type_77[4];
typedef int type_78[450];
typedef unsigned int type_79[8];
typedef unsigned char type_80[450];
typedef float type_81[128];
typedef char type_82[16];
typedef char type_83[4];
typedef unsigned int type_85[32];
typedef _anon17 type_86[2];
typedef unsigned char type_87[256];
typedef unsigned int type_88[16];
typedef _anon21 type_89[64];
typedef unsigned int type_90[16];
typedef _anon21 type_91[64];
typedef unsigned int type_92[32];
typedef _anon21 type_93[64];
typedef unsigned int type_94[16];
typedef unsigned int type_95[3];
typedef BH_PWORK* type_96[16];
typedef unsigned int type_97[8];
typedef unsigned int type_98[1];
typedef unsigned int type_99[384];
typedef unsigned int type_100[2];
typedef unsigned char type_101[2];
typedef int* type_102[16];
typedef unsigned int type_103[4];
typedef char type_104[32];
typedef npobj* type_105[16];
typedef char type_106[64];
typedef _anon1* type_107[16];
typedef char type_108[4];
typedef _anon14 type_109[16];
typedef short type_110[4];
typedef unsigned char type_111[4];
typedef _anon33 type_112[16];
typedef unsigned int type_113[8];
typedef unsigned int type_114[32];
typedef unsigned int type_115[4];
typedef _anon4 type_116[32];
typedef _anon0* type_117[512];
typedef _anon0* type_118[128];
typedef _anon0* type_119[512];
typedef _anon40 type_120[5];
typedef unsigned char type_121[64];
typedef _anon0* type_122[512];

struct npobj
{
	unsigned int evalflags;
	_anon31* model;
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
	_anon42 cspr;
	int pn;
	_anon35* pvp;
	_anon2* tvp;
	_anon35 pv[4];
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
	_anon43 watr;
	_anon25* cpcl;
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
	_anon24* textures;
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
	float x;
	float y;
	float z;
};

struct _anon5
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon23* md2P;
	unsigned short* atrP;
};

struct _anon6
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon44 keyf[16];
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
	_anon13* cutp;
	_anon12* lgtp;
	_anon18* enep;
	_anon18* objp;
	_anon18* itmp;
	_anon20* effp;
	_anon21* walp;
	_anon21* etcp;
	_anon21* flrp;
	_anon3* posp;
	_anon21* rutp;
	unsigned char* ruttp;
	_anon27* evtp;
	_anon6* evcp;
	unsigned int* mesp;
	_anon12* evlp;
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

struct _anon9
{
	_anon4 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon10
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

struct _anon11
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon12
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
	_anon17 cam[2];
	unsigned char exd[256];
};

struct _anon14
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon29* owP;
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
	_anon39* info;
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

struct _anon18
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

struct _anon19
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

struct _anon20
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

struct _anon21
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

struct _anon22
{
	void* texaddr;
	_anon10 texsurface;
};

struct _anon23
{
	void* p[2];
};

struct _anon24
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon25
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon26
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
	_anon4 ply_pos;
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
	_anon11 txbp[256];
	unsigned char* ef_psp;
	_anon24 ef_tex[450];
	_anon1 ef_tlist;
	_anon36 ef;
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
	_anon22 ren_info;
	_anon24 ren_tex[1];
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
	_anon38 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon12* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon9 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon32 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon21* pl_htp;
	int costume;
	_anon4 hd_pos;
	_anon4 apos;
	_anon21* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon21 mwalp[64];
	_anon21 metcp[64];
	_anon21 mflrp[64];
	int dla_n;
	_anon21* htp;
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
	_anon19 door;
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
	_anon4 ufo_pos;
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
	_anon33 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon4 ghtp[32];
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

struct _anon27
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon28
{
	float a;
	float r;
	float g;
	float b;
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
	_anon4 pnt;
	_anon4 vctr;
	int stat;
	int reserve;
	_anon34 ltcal;
	_anon41 attr;
};

struct _anon31
{
	int* vlist;
	short* plist;
	_anon4 center;
	float r;
};

struct _anon32
{
	float x;
	float y;
};

struct _anon33
{
	_anon4 c1;
	_anon4 c2;
	float r1;
	float r2;
};

struct _anon34
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
	_anon4 lpnt;
	_anon4 lvctr;
	_anon4 lmvctr;
	_anon28 atten;
	_anon28 amb;
	_anon28 dif;
	_anon28 spc;
	_anon28 mamb;
	_anon28 mdif;
	_anon28 mspc;
};

struct _anon35
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon36
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

struct _anon37
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

struct _anon38
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon39
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

struct _anon40
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
	_anon28 argb;
};

struct _anon42
{
	_anon4 c;
	float r;
};

struct _anon43
{
	_anon4 c1;
	_anon4 c2;
	float r;
};

struct _anon44
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

_anon40 lgttab[5];
_anon8* rom;
_anon26* sys;
_anon37 cam;
float fNaViwOffsetY;
float fNaViwOffsetX;
_anon0 eff[0];
BH_PWORK ene[0];
BH_PWORK* plp;

void bhInitLight();
void bhSetLightTab(_anon40* lt, int lno);
void bhSetEasyDirLight(float it);
void bhControlLight();
void bhSetLight();
void bhSetHalfLight();
void bhGetLightVector(int xr, int yr, int zr, _anon4* vec);

// 
// Start address: 0x280ed0
void bhInitLight()
{
	int i;
	_anon12* lp;
	// Line 75, Address: 0x280ed0, Func Offset: 0
	// Line 76, Address: 0x280ed8, Func Offset: 0x8
	// Line 75, Address: 0x280edc, Func Offset: 0xc
	// Line 76, Address: 0x280ee0, Func Offset: 0x10
	// Line 77, Address: 0x280ee8, Func Offset: 0x18
	// Line 78, Address: 0x280ef4, Func Offset: 0x24
	// Line 80, Address: 0x280f00, Func Offset: 0x30
	// Line 81, Address: 0x280f04, Func Offset: 0x34
	// Line 82, Address: 0x280f14, Func Offset: 0x44
	// Line 83, Address: 0x280f18, Func Offset: 0x48
	// Line 84, Address: 0x280f38, Func Offset: 0x68
	// Func End, Address: 0x280f40, Func Offset: 0x70
}

// 
// Start address: 0x280f40
void bhSetLightTab(_anon40* lt, int lno)
{
	_anon12* lp;
	// Line 184, Address: 0x280f40, Func Offset: 0
	// Line 186, Address: 0x280f54, Func Offset: 0x14
	// Line 184, Address: 0x280f5c, Func Offset: 0x1c
	// Line 186, Address: 0x280f64, Func Offset: 0x24
	// Line 187, Address: 0x280f68, Func Offset: 0x28
	// Line 233, Address: 0x280f6c, Func Offset: 0x2c
	// Line 187, Address: 0x280f70, Func Offset: 0x30
	// Line 188, Address: 0x280f74, Func Offset: 0x34
	// Line 189, Address: 0x280f7c, Func Offset: 0x3c
	// Line 190, Address: 0x280f84, Func Offset: 0x44
	// Line 191, Address: 0x280f8c, Func Offset: 0x4c
	// Line 192, Address: 0x280f94, Func Offset: 0x54
	// Line 193, Address: 0x280f9c, Func Offset: 0x5c
	// Line 194, Address: 0x280fa4, Func Offset: 0x64
	// Line 195, Address: 0x280fac, Func Offset: 0x6c
	// Line 196, Address: 0x280fb4, Func Offset: 0x74
	// Line 197, Address: 0x280fbc, Func Offset: 0x7c
	// Line 198, Address: 0x280fc4, Func Offset: 0x84
	// Line 199, Address: 0x280fcc, Func Offset: 0x8c
	// Line 200, Address: 0x280fd4, Func Offset: 0x94
	// Line 201, Address: 0x280fdc, Func Offset: 0x9c
	// Line 202, Address: 0x280fe4, Func Offset: 0xa4
	// Line 203, Address: 0x280fec, Func Offset: 0xac
	// Line 204, Address: 0x280ff4, Func Offset: 0xb4
	// Line 205, Address: 0x280ffc, Func Offset: 0xbc
	// Line 206, Address: 0x281004, Func Offset: 0xc4
	// Line 207, Address: 0x28100c, Func Offset: 0xcc
	// Line 208, Address: 0x281014, Func Offset: 0xd4
	// Line 209, Address: 0x28101c, Func Offset: 0xdc
	// Line 210, Address: 0x281024, Func Offset: 0xe4
	// Line 211, Address: 0x28102c, Func Offset: 0xec
	// Line 212, Address: 0x281034, Func Offset: 0xf4
	// Line 213, Address: 0x28103c, Func Offset: 0xfc
	// Line 214, Address: 0x281044, Func Offset: 0x104
	// Line 216, Address: 0x28104c, Func Offset: 0x10c
	// Line 217, Address: 0x281050, Func Offset: 0x110
	// Line 218, Address: 0x281060, Func Offset: 0x120
	// Line 219, Address: 0x281068, Func Offset: 0x128
	// Line 220, Address: 0x281070, Func Offset: 0x130
	// Line 221, Address: 0x281078, Func Offset: 0x138
	// Line 222, Address: 0x281080, Func Offset: 0x140
	// Line 223, Address: 0x281088, Func Offset: 0x148
	// Line 224, Address: 0x281090, Func Offset: 0x150
	// Line 225, Address: 0x281098, Func Offset: 0x158
	// Line 226, Address: 0x2810a0, Func Offset: 0x160
	// Line 227, Address: 0x2810a8, Func Offset: 0x168
	// Line 228, Address: 0x2810b0, Func Offset: 0x170
	// Line 229, Address: 0x2810b8, Func Offset: 0x178
	// Line 230, Address: 0x2810c0, Func Offset: 0x180
	// Line 231, Address: 0x2810c8, Func Offset: 0x188
	// Line 232, Address: 0x2810cc, Func Offset: 0x18c
	// Line 233, Address: 0x2810d0, Func Offset: 0x190
	// Func End, Address: 0x2810e0, Func Offset: 0x1a0
}

// 
// Start address: 0x2810e0
void bhSetEasyDirLight(float it)
{
	float fl;
	_anon12* lp;
	// Line 240, Address: 0x2810e0, Func Offset: 0
	// Line 245, Address: 0x2810f0, Func Offset: 0x10
	// Line 247, Address: 0x2810fc, Func Offset: 0x1c
	// Line 248, Address: 0x28110c, Func Offset: 0x2c
	// Line 250, Address: 0x281130, Func Offset: 0x50
	// Line 253, Address: 0x281150, Func Offset: 0x70
	// Line 252, Address: 0x281158, Func Offset: 0x78
	// Line 254, Address: 0x281160, Func Offset: 0x80
	// Line 256, Address: 0x281168, Func Offset: 0x88
	// Line 259, Address: 0x281170, Func Offset: 0x90
	// Line 261, Address: 0x281178, Func Offset: 0x98
	// Line 262, Address: 0x281188, Func Offset: 0xa8
	// Line 263, Address: 0x28119c, Func Offset: 0xbc
	// Line 264, Address: 0x2811ac, Func Offset: 0xcc
	// Line 271, Address: 0x2811bc, Func Offset: 0xdc
	// Line 272, Address: 0x2811d4, Func Offset: 0xf4
	// Line 273, Address: 0x2811e8, Func Offset: 0x108
	// Line 275, Address: 0x28120c, Func Offset: 0x12c
	// Line 276, Address: 0x281224, Func Offset: 0x144
	// Line 277, Address: 0x281238, Func Offset: 0x158
	// Line 278, Address: 0x28125c, Func Offset: 0x17c
	// Func End, Address: 0x281270, Func Offset: 0x190
}

// 
// Start address: 0x281270
void bhControlLight()
{
	float clp;
	_anon32 lpos;
	_anon4 npos;
	float fl;
	int dirf;
	int lct;
	int i;
	int lgt_n;
	float fr;
	float nr;
	float b;
	float g;
	float r;
	float vz;
	float vy;
	float vx;
	float pz;
	float py;
	float px;
	_anon4 vec;
	_anon17* ci;
	_anon9* lptb;
	_anon12* lp;
	BH_PWORK* pwp;
	// Line 284, Address: 0x281270, Func Offset: 0
	// Line 308, Address: 0x2812cc, Func Offset: 0x5c
	// Line 309, Address: 0x2812e0, Func Offset: 0x70
	// Line 310, Address: 0x2812e8, Func Offset: 0x78
	// Line 309, Address: 0x2812ec, Func Offset: 0x7c
	// Line 310, Address: 0x281304, Func Offset: 0x94
	// Line 311, Address: 0x281314, Func Offset: 0xa4
	// Line 312, Address: 0x28131c, Func Offset: 0xac
	// Line 313, Address: 0x281324, Func Offset: 0xb4
	// Line 312, Address: 0x28132c, Func Offset: 0xbc
	// Line 313, Address: 0x281344, Func Offset: 0xd4
	// Line 319, Address: 0x281358, Func Offset: 0xe8
	// Line 320, Address: 0x28136c, Func Offset: 0xfc
	// Line 321, Address: 0x281384, Func Offset: 0x114
	// Line 322, Address: 0x281394, Func Offset: 0x124
	// Line 327, Address: 0x28139c, Func Offset: 0x12c
	// Line 332, Address: 0x2813a8, Func Offset: 0x138
	// Line 328, Address: 0x2813ac, Func Offset: 0x13c
	// Line 330, Address: 0x2813b4, Func Offset: 0x144
	// Line 328, Address: 0x2813b8, Func Offset: 0x148
	// Line 332, Address: 0x281400, Func Offset: 0x190
	// Line 333, Address: 0x281428, Func Offset: 0x1b8
	// Line 334, Address: 0x28143c, Func Offset: 0x1cc
	// Line 335, Address: 0x281458, Func Offset: 0x1e8
	// Line 336, Address: 0x281478, Func Offset: 0x208
	// Line 337, Address: 0x281494, Func Offset: 0x224
	// Line 338, Address: 0x28149c, Func Offset: 0x22c
	// Line 339, Address: 0x2814ac, Func Offset: 0x23c
	// Line 340, Address: 0x2814b0, Func Offset: 0x240
	// Line 342, Address: 0x2814c0, Func Offset: 0x250
	// Line 343, Address: 0x2814cc, Func Offset: 0x25c
	// Line 356, Address: 0x2814dc, Func Offset: 0x26c
	// Line 345, Address: 0x2814e0, Func Offset: 0x270
	// Line 346, Address: 0x2814e4, Func Offset: 0x274
	// Line 347, Address: 0x2814e8, Func Offset: 0x278
	// Line 348, Address: 0x2814ec, Func Offset: 0x27c
	// Line 349, Address: 0x2814f0, Func Offset: 0x280
	// Line 350, Address: 0x2814f4, Func Offset: 0x284
	// Line 351, Address: 0x2814f8, Func Offset: 0x288
	// Line 352, Address: 0x2814fc, Func Offset: 0x28c
	// Line 353, Address: 0x281500, Func Offset: 0x290
	// Line 354, Address: 0x281504, Func Offset: 0x294
	// Line 356, Address: 0x281508, Func Offset: 0x298
	// Line 360, Address: 0x2815cc, Func Offset: 0x35c
	// Line 364, Address: 0x2815dc, Func Offset: 0x36c
	// Line 360, Address: 0x2815e0, Func Offset: 0x370
	// Line 361, Address: 0x2815e4, Func Offset: 0x374
	// Line 362, Address: 0x2815ec, Func Offset: 0x37c
	// Line 363, Address: 0x2815f0, Func Offset: 0x380
	// Line 361, Address: 0x2815f4, Func Offset: 0x384
	// Line 364, Address: 0x2815f8, Func Offset: 0x388
	// Line 361, Address: 0x281600, Func Offset: 0x390
	// Line 362, Address: 0x281608, Func Offset: 0x398
	// Line 363, Address: 0x281610, Func Offset: 0x3a0
	// Line 364, Address: 0x281614, Func Offset: 0x3a4
	// Line 363, Address: 0x281618, Func Offset: 0x3a8
	// Line 364, Address: 0x28161c, Func Offset: 0x3ac
	// Line 365, Address: 0x281620, Func Offset: 0x3b0
	// Line 367, Address: 0x281628, Func Offset: 0x3b8
	// Line 368, Address: 0x281638, Func Offset: 0x3c8
	// Line 367, Address: 0x28163c, Func Offset: 0x3cc
	// Line 371, Address: 0x281640, Func Offset: 0x3d0
	// Line 370, Address: 0x281648, Func Offset: 0x3d8
	// Line 369, Address: 0x28164c, Func Offset: 0x3dc
	// Line 368, Address: 0x281650, Func Offset: 0x3e0
	// Line 371, Address: 0x281658, Func Offset: 0x3e8
	// Line 369, Address: 0x281660, Func Offset: 0x3f0
	// Line 370, Address: 0x281668, Func Offset: 0x3f8
	// Line 371, Address: 0x28166c, Func Offset: 0x3fc
	// Line 370, Address: 0x281670, Func Offset: 0x400
	// Line 372, Address: 0x281674, Func Offset: 0x404
	// Line 374, Address: 0x28167c, Func Offset: 0x40c
	// Line 375, Address: 0x281684, Func Offset: 0x414
	// Line 376, Address: 0x281688, Func Offset: 0x418
	// Line 377, Address: 0x28168c, Func Offset: 0x41c
	// Line 378, Address: 0x281690, Func Offset: 0x420
	// Line 375, Address: 0x281698, Func Offset: 0x428
	// Line 378, Address: 0x28169c, Func Offset: 0x42c
	// Line 376, Address: 0x2816a4, Func Offset: 0x434
	// Line 378, Address: 0x2816a8, Func Offset: 0x438
	// Line 379, Address: 0x2816b0, Func Offset: 0x440
	// Line 381, Address: 0x2816b8, Func Offset: 0x448
	// Line 382, Address: 0x2816c8, Func Offset: 0x458
	// Line 381, Address: 0x2816cc, Func Offset: 0x45c
	// Line 382, Address: 0x2816d0, Func Offset: 0x460
	// Line 384, Address: 0x2816d4, Func Offset: 0x464
	// Line 383, Address: 0x2816d8, Func Offset: 0x468
	// Line 382, Address: 0x2816dc, Func Offset: 0x46c
	// Line 383, Address: 0x2816ec, Func Offset: 0x47c
	// Line 384, Address: 0x2816f4, Func Offset: 0x484
	// Line 385, Address: 0x2816f8, Func Offset: 0x488
	// Line 386, Address: 0x281740, Func Offset: 0x4d0
	// Line 388, Address: 0x281748, Func Offset: 0x4d8
	// Line 389, Address: 0x281758, Func Offset: 0x4e8
	// Line 388, Address: 0x28175c, Func Offset: 0x4ec
	// Line 391, Address: 0x281760, Func Offset: 0x4f0
	// Line 390, Address: 0x281764, Func Offset: 0x4f4
	// Line 389, Address: 0x281768, Func Offset: 0x4f8
	// Line 390, Address: 0x281770, Func Offset: 0x500
	// Line 391, Address: 0x281778, Func Offset: 0x508
	// Line 392, Address: 0x28177c, Func Offset: 0x50c
	// Line 393, Address: 0x2817c4, Func Offset: 0x554
	// Line 395, Address: 0x2817cc, Func Offset: 0x55c
	// Line 396, Address: 0x2817d4, Func Offset: 0x564
	// Line 397, Address: 0x2817d8, Func Offset: 0x568
	// Line 398, Address: 0x2817dc, Func Offset: 0x56c
	// Line 396, Address: 0x2817e0, Func Offset: 0x570
	// Line 397, Address: 0x2817e4, Func Offset: 0x574
	// Line 399, Address: 0x2817e8, Func Offset: 0x578
	// Line 400, Address: 0x281830, Func Offset: 0x5c0
	// Line 402, Address: 0x281838, Func Offset: 0x5c8
	// Line 403, Address: 0x281854, Func Offset: 0x5e4
	// Line 404, Address: 0x281858, Func Offset: 0x5e8
	// Line 406, Address: 0x28185c, Func Offset: 0x5ec
	// Line 408, Address: 0x281864, Func Offset: 0x5f4
	// Line 409, Address: 0x28189c, Func Offset: 0x62c
	// Line 411, Address: 0x2818b0, Func Offset: 0x640
	// Line 412, Address: 0x2818b4, Func Offset: 0x644
	// Line 413, Address: 0x2818b8, Func Offset: 0x648
	// Line 415, Address: 0x2818c0, Func Offset: 0x650
	// Line 416, Address: 0x2818f8, Func Offset: 0x688
	// Line 418, Address: 0x28190c, Func Offset: 0x69c
	// Line 419, Address: 0x281910, Func Offset: 0x6a0
	// Line 420, Address: 0x281914, Func Offset: 0x6a4
	// Line 422, Address: 0x28191c, Func Offset: 0x6ac
	// Line 424, Address: 0x281954, Func Offset: 0x6e4
	// Line 425, Address: 0x281958, Func Offset: 0x6e8
	// Line 426, Address: 0x281960, Func Offset: 0x6f0
	// Line 427, Address: 0x281968, Func Offset: 0x6f8
	// Line 428, Address: 0x281970, Func Offset: 0x700
	// Line 430, Address: 0x281978, Func Offset: 0x708
	// Line 431, Address: 0x28197c, Func Offset: 0x70c
	// Line 432, Address: 0x281984, Func Offset: 0x714
	// Line 433, Address: 0x281988, Func Offset: 0x718
	// Line 435, Address: 0x281a04, Func Offset: 0x794
	// Line 439, Address: 0x281a48, Func Offset: 0x7d8
	// Line 441, Address: 0x281a50, Func Offset: 0x7e0
	// Line 443, Address: 0x281a58, Func Offset: 0x7e8
	// Line 444, Address: 0x281a88, Func Offset: 0x818
	// Line 445, Address: 0x281aa4, Func Offset: 0x834
	// Line 446, Address: 0x281ac0, Func Offset: 0x850
	// Line 447, Address: 0x281acc, Func Offset: 0x85c
	// Line 448, Address: 0x281ad8, Func Offset: 0x868
	// Line 449, Address: 0x281ae0, Func Offset: 0x870
	// Line 450, Address: 0x281ae8, Func Offset: 0x878
	// Line 452, Address: 0x281aec, Func Offset: 0x87c
	// Line 456, Address: 0x281b30, Func Offset: 0x8c0
	// Line 458, Address: 0x281b38, Func Offset: 0x8c8
	// Line 460, Address: 0x281b40, Func Offset: 0x8d0
	// Line 461, Address: 0x281b70, Func Offset: 0x900
	// Line 462, Address: 0x281b8c, Func Offset: 0x91c
	// Line 463, Address: 0x281ba8, Func Offset: 0x938
	// Line 464, Address: 0x281bb4, Func Offset: 0x944
	// Line 465, Address: 0x281bc0, Func Offset: 0x950
	// Line 468, Address: 0x281bc4, Func Offset: 0x954
	// Line 465, Address: 0x281bc8, Func Offset: 0x958
	// Line 466, Address: 0x281bcc, Func Offset: 0x95c
	// Line 467, Address: 0x281bd4, Func Offset: 0x964
	// Line 468, Address: 0x281bdc, Func Offset: 0x96c
	// Line 472, Address: 0x281be0, Func Offset: 0x970
	// Line 474, Address: 0x281be4, Func Offset: 0x974
	// Line 475, Address: 0x281be8, Func Offset: 0x978
	// Line 477, Address: 0x281bf0, Func Offset: 0x980
	// Line 479, Address: 0x281c1c, Func Offset: 0x9ac
	// Line 480, Address: 0x281c20, Func Offset: 0x9b0
	// Line 481, Address: 0x281c28, Func Offset: 0x9b8
	// Line 482, Address: 0x281c30, Func Offset: 0x9c0
	// Line 483, Address: 0x281c38, Func Offset: 0x9c8
	// Line 485, Address: 0x281c40, Func Offset: 0x9d0
	// Line 486, Address: 0x281c70, Func Offset: 0xa00
	// Line 487, Address: 0x281c8c, Func Offset: 0xa1c
	// Line 488, Address: 0x281ca4, Func Offset: 0xa34
	// Line 489, Address: 0x281d20, Func Offset: 0xab0
	// Line 490, Address: 0x281d28, Func Offset: 0xab8
	// Line 491, Address: 0x281d30, Func Offset: 0xac0
	// Line 493, Address: 0x281d34, Func Offset: 0xac4
	// Line 497, Address: 0x281d78, Func Offset: 0xb08
	// Line 499, Address: 0x281d80, Func Offset: 0xb10
	// Line 501, Address: 0x281d88, Func Offset: 0xb18
	// Line 502, Address: 0x281db8, Func Offset: 0xb48
	// Line 503, Address: 0x281dd4, Func Offset: 0xb64
	// Line 504, Address: 0x281df0, Func Offset: 0xb80
	// Line 505, Address: 0x281dfc, Func Offset: 0xb8c
	// Line 506, Address: 0x281e08, Func Offset: 0xb98
	// Line 509, Address: 0x281e0c, Func Offset: 0xb9c
	// Line 506, Address: 0x281e10, Func Offset: 0xba0
	// Line 507, Address: 0x281e14, Func Offset: 0xba4
	// Line 508, Address: 0x281e1c, Func Offset: 0xbac
	// Line 509, Address: 0x281e24, Func Offset: 0xbb4
	// Line 513, Address: 0x281e28, Func Offset: 0xbb8
	// Line 515, Address: 0x281e2c, Func Offset: 0xbbc
	// Line 516, Address: 0x281e30, Func Offset: 0xbc0
	// Line 518, Address: 0x281e38, Func Offset: 0xbc8
	// Line 520, Address: 0x281e58, Func Offset: 0xbe8
	// Line 521, Address: 0x281e64, Func Offset: 0xbf4
	// Line 522, Address: 0x281e70, Func Offset: 0xc00
	// Line 523, Address: 0x281eb4, Func Offset: 0xc44
	// Line 525, Address: 0x281ebc, Func Offset: 0xc4c
	// Line 527, Address: 0x281ec4, Func Offset: 0xc54
	// Line 530, Address: 0x281ecc, Func Offset: 0xc5c
	// Line 527, Address: 0x281ed0, Func Offset: 0xc60
	// Line 530, Address: 0x281ed4, Func Offset: 0xc64
	// Line 528, Address: 0x281ed8, Func Offset: 0xc68
	// Line 530, Address: 0x281edc, Func Offset: 0xc6c
	// Line 531, Address: 0x281ee0, Func Offset: 0xc70
	// Line 532, Address: 0x281eec, Func Offset: 0xc7c
	// Line 537, Address: 0x281f30, Func Offset: 0xcc0
	// Line 539, Address: 0x281f38, Func Offset: 0xcc8
	// Line 543, Address: 0x281f40, Func Offset: 0xcd0
	// Line 540, Address: 0x281f48, Func Offset: 0xcd8
	// Line 541, Address: 0x281f4c, Func Offset: 0xcdc
	// Line 542, Address: 0x281f50, Func Offset: 0xce0
	// Line 543, Address: 0x281f54, Func Offset: 0xce4
	// Line 540, Address: 0x281f5c, Func Offset: 0xcec
	// Line 543, Address: 0x281f60, Func Offset: 0xcf0
	// Line 544, Address: 0x281f64, Func Offset: 0xcf4
	// Line 541, Address: 0x281f68, Func Offset: 0xcf8
	// Line 544, Address: 0x281f6c, Func Offset: 0xcfc
	// Line 545, Address: 0x281f78, Func Offset: 0xd08
	// Line 547, Address: 0x281f84, Func Offset: 0xd14
	// Line 549, Address: 0x281f8c, Func Offset: 0xd1c
	// Line 551, Address: 0x281fac, Func Offset: 0xd3c
	// Line 552, Address: 0x281fb0, Func Offset: 0xd40
	// Line 554, Address: 0x281fb8, Func Offset: 0xd48
	// Line 557, Address: 0x281fc0, Func Offset: 0xd50
	// Line 559, Address: 0x281fc8, Func Offset: 0xd58
	// Line 563, Address: 0x281fd0, Func Offset: 0xd60
	// Line 560, Address: 0x281fd8, Func Offset: 0xd68
	// Line 561, Address: 0x281fdc, Func Offset: 0xd6c
	// Line 562, Address: 0x281fe0, Func Offset: 0xd70
	// Line 563, Address: 0x281fe4, Func Offset: 0xd74
	// Line 560, Address: 0x281fec, Func Offset: 0xd7c
	// Line 563, Address: 0x281ff0, Func Offset: 0xd80
	// Line 564, Address: 0x281ff4, Func Offset: 0xd84
	// Line 561, Address: 0x281ff8, Func Offset: 0xd88
	// Line 564, Address: 0x281ffc, Func Offset: 0xd8c
	// Line 565, Address: 0x282008, Func Offset: 0xd98
	// Line 569, Address: 0x282014, Func Offset: 0xda4
	// Line 570, Address: 0x28201c, Func Offset: 0xdac
	// Line 571, Address: 0x282020, Func Offset: 0xdb0
	// Line 572, Address: 0x282024, Func Offset: 0xdb4
	// Line 573, Address: 0x282028, Func Offset: 0xdb8
	// Line 574, Address: 0x28202c, Func Offset: 0xdbc
	// Line 575, Address: 0x282030, Func Offset: 0xdc0
	// Line 576, Address: 0x282034, Func Offset: 0xdc4
	// Line 577, Address: 0x282038, Func Offset: 0xdc8
	// Line 578, Address: 0x28203c, Func Offset: 0xdcc
	// Line 579, Address: 0x282040, Func Offset: 0xdd0
	// Line 580, Address: 0x282044, Func Offset: 0xdd4
	// Line 581, Address: 0x28204c, Func Offset: 0xddc
	// Line 583, Address: 0x282050, Func Offset: 0xde0
	// Line 586, Address: 0x28207c, Func Offset: 0xe0c
	// Line 590, Address: 0x282080, Func Offset: 0xe10
	// Line 591, Address: 0x282084, Func Offset: 0xe14
	// Line 597, Address: 0x28208c, Func Offset: 0xe1c
	// Line 598, Address: 0x2820cc, Func Offset: 0xe5c
	// Line 604, Address: 0x2820d4, Func Offset: 0xe64
	// Line 605, Address: 0x282100, Func Offset: 0xe90
	// Line 611, Address: 0x282108, Func Offset: 0xe98
	// Line 612, Address: 0x282134, Func Offset: 0xec4
	// Line 618, Address: 0x28213c, Func Offset: 0xecc
	// Line 619, Address: 0x282178, Func Offset: 0xf08
	// Line 621, Address: 0x282180, Func Offset: 0xf10
	// Line 622, Address: 0x282184, Func Offset: 0xf14
	// Line 625, Address: 0x282188, Func Offset: 0xf18
	// Line 626, Address: 0x282194, Func Offset: 0xf24
	// Line 628, Address: 0x2821a4, Func Offset: 0xf34
	// Line 630, Address: 0x2821b0, Func Offset: 0xf40
	// Line 632, Address: 0x2821b8, Func Offset: 0xf48
	// Line 634, Address: 0x2821c4, Func Offset: 0xf54
	// Line 636, Address: 0x2821d4, Func Offset: 0xf64
	// Line 642, Address: 0x2821dc, Func Offset: 0xf6c
	// Line 644, Address: 0x282204, Func Offset: 0xf94
	// Line 645, Address: 0x282208, Func Offset: 0xf98
	// Line 646, Address: 0x28220c, Func Offset: 0xf9c
	// Line 647, Address: 0x282210, Func Offset: 0xfa0
	// Line 650, Address: 0x282218, Func Offset: 0xfa8
	// Line 652, Address: 0x28223c, Func Offset: 0xfcc
	// Line 654, Address: 0x282244, Func Offset: 0xfd4
	// Line 653, Address: 0x28224c, Func Offset: 0xfdc
	// Line 654, Address: 0x282250, Func Offset: 0xfe0
	// Line 655, Address: 0x28225c, Func Offset: 0xfec
	// Line 656, Address: 0x282270, Func Offset: 0x1000
	// Line 657, Address: 0x282284, Func Offset: 0x1014
	// Line 658, Address: 0x282298, Func Offset: 0x1028
	// Line 659, Address: 0x2822ac, Func Offset: 0x103c
	// Line 661, Address: 0x2822bc, Func Offset: 0x104c
	// Line 663, Address: 0x2822c4, Func Offset: 0x1054
	// Line 665, Address: 0x2822d0, Func Offset: 0x1060
	// Line 670, Address: 0x2822fc, Func Offset: 0x108c
	// Line 671, Address: 0x282300, Func Offset: 0x1090
	// Line 672, Address: 0x282304, Func Offset: 0x1094
	// Line 674, Address: 0x282308, Func Offset: 0x1098
	// Line 678, Address: 0x282344, Func Offset: 0x10d4
	// Line 674, Address: 0x28234c, Func Offset: 0x10dc
	// Line 678, Address: 0x282350, Func Offset: 0x10e0
	// Line 686, Address: 0x28235c, Func Offset: 0x10ec
	// Line 701, Address: 0x282408, Func Offset: 0x1198
	// Line 702, Address: 0x28241c, Func Offset: 0x11ac
	// Line 703, Address: 0x28242c, Func Offset: 0x11bc
	// Line 704, Address: 0x282440, Func Offset: 0x11d0
	// Line 706, Address: 0x28244c, Func Offset: 0x11dc
	// Line 707, Address: 0x282460, Func Offset: 0x11f0
	// Line 708, Address: 0x282470, Func Offset: 0x1200
	// Line 709, Address: 0x282484, Func Offset: 0x1214
	// Line 710, Address: 0x282490, Func Offset: 0x1220
	// Line 711, Address: 0x282494, Func Offset: 0x1224
	// Line 712, Address: 0x282498, Func Offset: 0x1228
	// Line 713, Address: 0x28249c, Func Offset: 0x122c
	// Line 714, Address: 0x2824a0, Func Offset: 0x1230
	// Line 715, Address: 0x2824a4, Func Offset: 0x1234
	// Line 716, Address: 0x2824a8, Func Offset: 0x1238
	// Line 717, Address: 0x2824ac, Func Offset: 0x123c
	// Line 719, Address: 0x2824b0, Func Offset: 0x1240
	// Line 718, Address: 0x2824b8, Func Offset: 0x1248
	// Line 720, Address: 0x2824bc, Func Offset: 0x124c
	// Line 719, Address: 0x2824c0, Func Offset: 0x1250
	// Line 723, Address: 0x2824dc, Func Offset: 0x126c
	// Line 724, Address: 0x2824e0, Func Offset: 0x1270
	// Line 725, Address: 0x2824f8, Func Offset: 0x1288
	// Line 726, Address: 0x2824fc, Func Offset: 0x128c
	// Line 727, Address: 0x282500, Func Offset: 0x1290
	// Line 728, Address: 0x282504, Func Offset: 0x1294
	// Line 729, Address: 0x282508, Func Offset: 0x1298
	// Line 730, Address: 0x28250c, Func Offset: 0x129c
	// Line 731, Address: 0x282510, Func Offset: 0x12a0
	// Line 732, Address: 0x282514, Func Offset: 0x12a4
	// Line 733, Address: 0x282518, Func Offset: 0x12a8
	// Line 734, Address: 0x28251c, Func Offset: 0x12ac
	// Line 735, Address: 0x282520, Func Offset: 0x12b0
	// Line 738, Address: 0x282524, Func Offset: 0x12b4
	// Line 740, Address: 0x282540, Func Offset: 0x12d0
	// Line 742, Address: 0x282550, Func Offset: 0x12e0
	// Line 743, Address: 0x282558, Func Offset: 0x12e8
	// Line 745, Address: 0x282560, Func Offset: 0x12f0
	// Line 743, Address: 0x282564, Func Offset: 0x12f4
	// Line 745, Address: 0x28256c, Func Offset: 0x12fc
	// Line 743, Address: 0x282574, Func Offset: 0x1304
	// Line 745, Address: 0x282578, Func Offset: 0x1308
	// Line 743, Address: 0x28257c, Func Offset: 0x130c
	// Line 745, Address: 0x282580, Func Offset: 0x1310
	// Line 746, Address: 0x282588, Func Offset: 0x1318
	// Line 748, Address: 0x282594, Func Offset: 0x1324
	// Line 749, Address: 0x2825a8, Func Offset: 0x1338
	// Line 751, Address: 0x2825b4, Func Offset: 0x1344
	// Line 752, Address: 0x2825c8, Func Offset: 0x1358
	// Line 753, Address: 0x2825d4, Func Offset: 0x1364
	// Line 755, Address: 0x2825e8, Func Offset: 0x1378
	// Line 756, Address: 0x2825fc, Func Offset: 0x138c
	// Line 757, Address: 0x282608, Func Offset: 0x1398
	// Line 758, Address: 0x28261c, Func Offset: 0x13ac
	// Line 759, Address: 0x282630, Func Offset: 0x13c0
	// Line 760, Address: 0x282644, Func Offset: 0x13d4
	// Line 761, Address: 0x282658, Func Offset: 0x13e8
	// Line 762, Address: 0x28266c, Func Offset: 0x13fc
	// Line 763, Address: 0x282680, Func Offset: 0x1410
	// Line 764, Address: 0x282690, Func Offset: 0x1420
	// Line 765, Address: 0x282698, Func Offset: 0x1428
	// Line 767, Address: 0x2826a8, Func Offset: 0x1438
	// Line 765, Address: 0x2826ac, Func Offset: 0x143c
	// Line 767, Address: 0x2826b4, Func Offset: 0x1444
	// Line 768, Address: 0x2826e4, Func Offset: 0x1474
	// Line 769, Address: 0x282714, Func Offset: 0x14a4
	// Line 771, Address: 0x282720, Func Offset: 0x14b0
	// Line 772, Address: 0x282754, Func Offset: 0x14e4
	// Line 773, Address: 0x282784, Func Offset: 0x1514
	// Line 775, Address: 0x282790, Func Offset: 0x1520
	// Line 776, Address: 0x2827b4, Func Offset: 0x1544
	// Line 777, Address: 0x2827e4, Func Offset: 0x1574
	// Line 778, Address: 0x2827f8, Func Offset: 0x1588
	// Line 780, Address: 0x282810, Func Offset: 0x15a0
	// Line 781, Address: 0x282840, Func Offset: 0x15d0
	// Line 782, Address: 0x282854, Func Offset: 0x15e4
	// Line 785, Address: 0x282864, Func Offset: 0x15f4
	// Line 786, Address: 0x282870, Func Offset: 0x1600
	// Line 787, Address: 0x28287c, Func Offset: 0x160c
	// Line 788, Address: 0x282888, Func Offset: 0x1618
	// Line 789, Address: 0x282894, Func Offset: 0x1624
	// Line 790, Address: 0x2828a4, Func Offset: 0x1634
	// Line 792, Address: 0x2828a8, Func Offset: 0x1638
	// Line 793, Address: 0x2828b4, Func Offset: 0x1644
	// Line 795, Address: 0x2828bc, Func Offset: 0x164c
	// Line 796, Address: 0x2828c4, Func Offset: 0x1654
	// Line 797, Address: 0x2828cc, Func Offset: 0x165c
	// Func End, Address: 0x28292c, Func Offset: 0x16bc
}

// 
// Start address: 0x282930
void bhSetLight()
{
	int i;
	_anon4 vec;
	_anon9* lptb;
	// Line 1059, Address: 0x282930, Func Offset: 0
	// Line 1070, Address: 0x282940, Func Offset: 0x10
	// Line 1071, Address: 0x282958, Func Offset: 0x28
	// Line 1072, Address: 0x282968, Func Offset: 0x38
	// Line 1078, Address: 0x282970, Func Offset: 0x40
	// Line 1080, Address: 0x282984, Func Offset: 0x54
	// Line 1081, Address: 0x282998, Func Offset: 0x68
	// Line 1083, Address: 0x2829a4, Func Offset: 0x74
	// Line 1084, Address: 0x2829b8, Func Offset: 0x88
	// Line 1086, Address: 0x2829c4, Func Offset: 0x94
	// Line 1087, Address: 0x2829d8, Func Offset: 0xa8
	// Line 1088, Address: 0x2829e4, Func Offset: 0xb4
	// Line 1090, Address: 0x2829f8, Func Offset: 0xc8
	// Line 1091, Address: 0x282a0c, Func Offset: 0xdc
	// Line 1092, Address: 0x282a18, Func Offset: 0xe8
	// Line 1093, Address: 0x282a2c, Func Offset: 0xfc
	// Line 1095, Address: 0x282a34, Func Offset: 0x104
	// Line 1096, Address: 0x282a60, Func Offset: 0x130
	// Line 1097, Address: 0x282a90, Func Offset: 0x160
	// Line 1099, Address: 0x282a9c, Func Offset: 0x16c
	// Line 1100, Address: 0x282ad0, Func Offset: 0x1a0
	// Line 1101, Address: 0x282b00, Func Offset: 0x1d0
	// Line 1103, Address: 0x282b0c, Func Offset: 0x1dc
	// Line 1104, Address: 0x282b30, Func Offset: 0x200
	// Line 1105, Address: 0x282b60, Func Offset: 0x230
	// Line 1106, Address: 0x282b74, Func Offset: 0x244
	// Line 1108, Address: 0x282b8c, Func Offset: 0x25c
	// Line 1109, Address: 0x282bbc, Func Offset: 0x28c
	// Line 1110, Address: 0x282bd0, Func Offset: 0x2a0
	// Line 1113, Address: 0x282be0, Func Offset: 0x2b0
	// Line 1114, Address: 0x282be8, Func Offset: 0x2b8
	// Line 1113, Address: 0x282bec, Func Offset: 0x2bc
	// Line 1114, Address: 0x282bf4, Func Offset: 0x2c4
	// Line 1116, Address: 0x282bfc, Func Offset: 0x2cc
	// Line 1118, Address: 0x282c10, Func Offset: 0x2e0
	// Line 1119, Address: 0x282c24, Func Offset: 0x2f4
	// Line 1121, Address: 0x282c50, Func Offset: 0x320
	// Line 1123, Address: 0x282c60, Func Offset: 0x330
	// Line 1125, Address: 0x282c68, Func Offset: 0x338
	// Line 1126, Address: 0x282c70, Func Offset: 0x340
	// Func End, Address: 0x282c84, Func Offset: 0x354
}

// 
// Start address: 0x282c90
void bhSetHalfLight()
{
	int i;
	float b;
	float g;
	float r;
	_anon4 vec;
	_anon9* lptb;
	// Line 1134, Address: 0x282c90, Func Offset: 0
	// Line 1145, Address: 0x282cac, Func Offset: 0x1c
	// Line 1146, Address: 0x282cc4, Func Offset: 0x34
	// Line 1147, Address: 0x282cd8, Func Offset: 0x48
	// Line 1153, Address: 0x282ce0, Func Offset: 0x50
	// Line 1155, Address: 0x282cf4, Func Offset: 0x64
	// Line 1156, Address: 0x282d08, Func Offset: 0x78
	// Line 1158, Address: 0x282d14, Func Offset: 0x84
	// Line 1159, Address: 0x282d28, Func Offset: 0x98
	// Line 1161, Address: 0x282d34, Func Offset: 0xa4
	// Line 1162, Address: 0x282d48, Func Offset: 0xb8
	// Line 1163, Address: 0x282d54, Func Offset: 0xc4
	// Line 1165, Address: 0x282d68, Func Offset: 0xd8
	// Line 1166, Address: 0x282d7c, Func Offset: 0xec
	// Line 1167, Address: 0x282d88, Func Offset: 0xf8
	// Line 1168, Address: 0x282d9c, Func Offset: 0x10c
	// Line 1169, Address: 0x282da4, Func Offset: 0x114
	// Line 1170, Address: 0x282db8, Func Offset: 0x128
	// Line 1169, Address: 0x282dc0, Func Offset: 0x130
	// Line 1170, Address: 0x282dc4, Func Offset: 0x134
	// Line 1173, Address: 0x282dc8, Func Offset: 0x138
	// Line 1171, Address: 0x282dcc, Func Offset: 0x13c
	// Line 1170, Address: 0x282dd4, Func Offset: 0x144
	// Line 1171, Address: 0x282dd8, Func Offset: 0x148
	// Line 1173, Address: 0x282ddc, Func Offset: 0x14c
	// Line 1171, Address: 0x282de4, Func Offset: 0x154
	// Line 1173, Address: 0x282de8, Func Offset: 0x158
	// Line 1174, Address: 0x282df0, Func Offset: 0x160
	// Line 1175, Address: 0x282e20, Func Offset: 0x190
	// Line 1177, Address: 0x282e2c, Func Offset: 0x19c
	// Line 1178, Address: 0x282e40, Func Offset: 0x1b0
	// Line 1179, Address: 0x282e70, Func Offset: 0x1e0
	// Line 1181, Address: 0x282e7c, Func Offset: 0x1ec
	// Line 1182, Address: 0x282ea0, Func Offset: 0x210
	// Line 1183, Address: 0x282eb0, Func Offset: 0x220
	// Line 1184, Address: 0x282ec4, Func Offset: 0x234
	// Line 1186, Address: 0x282edc, Func Offset: 0x24c
	// Line 1187, Address: 0x282eec, Func Offset: 0x25c
	// Line 1188, Address: 0x282f00, Func Offset: 0x270
	// Line 1191, Address: 0x282f10, Func Offset: 0x280
	// Line 1192, Address: 0x282f18, Func Offset: 0x288
	// Line 1191, Address: 0x282f1c, Func Offset: 0x28c
	// Line 1192, Address: 0x282f24, Func Offset: 0x294
	// Line 1193, Address: 0x282f2c, Func Offset: 0x29c
	// Line 1194, Address: 0x282f30, Func Offset: 0x2a0
	// Line 1195, Address: 0x282f34, Func Offset: 0x2a4
	// Line 1193, Address: 0x282f38, Func Offset: 0x2a8
	// Line 1197, Address: 0x282f40, Func Offset: 0x2b0
	// Line 1193, Address: 0x282f44, Func Offset: 0x2b4
	// Line 1194, Address: 0x282f48, Func Offset: 0x2b8
	// Line 1195, Address: 0x282f4c, Func Offset: 0x2bc
	// Line 1197, Address: 0x282f50, Func Offset: 0x2c0
	// Line 1199, Address: 0x282f60, Func Offset: 0x2d0
	// Line 1200, Address: 0x282f74, Func Offset: 0x2e4
	// Line 1202, Address: 0x282fa0, Func Offset: 0x310
	// Line 1204, Address: 0x282fb0, Func Offset: 0x320
	// Line 1206, Address: 0x282fb8, Func Offset: 0x328
	// Line 1207, Address: 0x282fc0, Func Offset: 0x330
	// Func End, Address: 0x282fe0, Func Offset: 0x350
}

// 
// Start address: 0x282fe0
void bhGetLightVector(int xr, int yr, int zr, _anon4* vec)
{
	_anon4 pos;
	// Line 1216, Address: 0x282fe0, Func Offset: 0
	// Line 1217, Address: 0x282ffc, Func Offset: 0x1c
	// Line 1218, Address: 0x283020, Func Offset: 0x40
	// Line 1219, Address: 0x28302c, Func Offset: 0x4c
	// Line 1220, Address: 0x283038, Func Offset: 0x58
	// Line 1221, Address: 0x283044, Func Offset: 0x64
	// Line 1222, Address: 0x283050, Func Offset: 0x70
	// Line 1223, Address: 0x283060, Func Offset: 0x80
	// Func End, Address: 0x28307c, Func Offset: 0x9c
}

