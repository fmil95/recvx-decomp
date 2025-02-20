typedef struct npobj;
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
typedef struct BH_PWORK;
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

typedef void(*type_68)(BH_PWORK*);
typedef void(*type_72)();
typedef void(*type_79)(void*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef _anon0* type_2[32];
typedef _anon1* type_3[16];
typedef _anon0* type_4[32];
typedef _anon0* type_5[512];
typedef _anon1* type_6[16][16];
typedef _anon1* type_7[16][16][100];
typedef char type_8[8];
typedef _anon0* type_9[32];
typedef _anon0* type_10[512];
typedef _anon1* type_11[1300];
typedef char type_12[32];
typedef float type_13[32];
typedef _anon0* type_14[512];
typedef _anon1* type_15[200];
typedef short type_16[32];
typedef _anon22 type_17[1];
typedef _anon0* type_18[128];
typedef unsigned int type_19[1];
typedef _anon6 type_20[256];
typedef _anon1* type_21[8];
typedef int* type_22[16];
typedef _anon0* type_23[128];
typedef _anon42 type_24[16];
typedef npobj* type_25[16];
typedef _anon0* type_26[128];
typedef int type_27[4];
typedef _anon1* type_28[16];
typedef unsigned int type_29[4];
typedef float type_30[4];
typedef _anon11 type_31[16];
typedef _anon0* type_32[512];
typedef float type_33[4];
typedef char type_34[256];
typedef float type_35[4];
typedef float type_36[4];
typedef float type_37[4];
typedef float type_38[4];
typedef _anon4* type_39[128];
typedef unsigned char type_40[64];
typedef float type_41[16];
typedef char type_42[8];
typedef void* type_43[2];
typedef _anon1* type_44[256];
typedef int type_45[4];
typedef unsigned char* type_46[256];
typedef unsigned int type_47[2];
typedef short type_48[256];
typedef _anon29 type_49[4];
typedef _anon23 type_50[5];
typedef float type_51[3];
typedef short type_52[256];
typedef int type_53[3];
typedef int type_54[8];
typedef float type_55[3];
typedef _anon1* type_56[256];
typedef _anon8 type_57[256];
typedef _anon22 type_58[450];
typedef _anon31 type_59[16];
typedef short type_60[256];
typedef char type_61[3];
typedef int type_62[64];
typedef _anon11 type_63[450];
typedef unsigned int type_64[16];
typedef BH_PWORK type_65[0];
typedef unsigned int type_66[8];
typedef char type_67[4];
typedef _anon35 type_69[4];
typedef _anon2 type_70[4];
typedef int type_71[450];
typedef unsigned int type_73[8];
typedef unsigned char type_74[450];
typedef void(*type_75)()[100];
typedef float type_76[128];
typedef char type_77[16];
typedef char type_78[4];
typedef _anon20 type_80[2];
typedef unsigned int type_81[32];
typedef unsigned char type_82[256];
typedef unsigned int type_83[16];
typedef _anon17 type_84[64];
typedef unsigned int type_85[16];
typedef _anon17 type_86[64];
typedef unsigned int type_87[32];
typedef _anon17 type_88[64];
typedef unsigned int type_89[16];
typedef unsigned int type_90[3];
typedef BH_PWORK* type_91[16];
typedef unsigned int type_92[8];
typedef unsigned int type_93[1];
typedef unsigned int type_94[384];
typedef unsigned int type_95[2];
typedef unsigned char type_96[2];
typedef unsigned int type_97[4];
typedef int* type_98[16];
typedef char type_99[32];
typedef npobj* type_100[16];
typedef char type_101[64];
typedef _anon1* type_102[16];
typedef char type_103[4];
typedef _anon11 type_104[16];
typedef short type_105[4];
typedef unsigned char type_106[4];
typedef _anon33 type_107[16];
typedef unsigned int type_108[8];
typedef unsigned int type_109[32];
typedef unsigned int type_110[4];
typedef _anon32 type_111[32];
typedef _anon0* type_112[512];
typedef _anon0* type_113[128];
typedef _anon0* type_114[512];
typedef unsigned char type_115[64];
typedef _anon0* type_116[512];

struct npobj
{
	unsigned int evalflags;
	_anon30* model;
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
	_anon40 cspr;
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

struct _anon1
{
	_anon22* textures;
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
	_anon21* md2P;
	unsigned short* atrP;
};

struct _anon5
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon42 keyf[16];
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
	_anon17* walp;
	_anon17* etcp;
	_anon17* flrp;
	_anon3* posp;
	_anon17* rutp;
	unsigned char* ruttp;
	_anon25* evtp;
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
	_anon20 cam[2];
	unsigned char exd[256];
};

struct _anon11
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon27* owP;
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
	_anon38* info;
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
	_anon28* light;
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
	_anon41 watr;
	_anon23* cpcl;
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

struct _anon17
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
	void* texaddr;
	_anon7 texsurface;
};

struct _anon20
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

struct _anon21
{
	void* p[2];
};

struct _anon22
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon23
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon24
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
	_anon22 ef_tex[450];
	_anon1 ef_tlist;
	_anon36 ef;
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
	_anon19 ren_info;
	_anon22 ren_tex[1];
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
	_anon37 mr_pl;
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
	_anon29 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon31 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon17* pl_htp;
	int costume;
	_anon32 hd_pos;
	_anon32 apos;
	_anon17* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon17 mwalp[64];
	_anon17 metcp[64];
	_anon17 mflrp[64];
	int dla_n;
	_anon17* htp;
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
	_anon33 gatc[16];
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

struct _anon25
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon26
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon27
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon28
{
	float mtrx[16];
	_anon32 pnt;
	_anon32 vctr;
	int stat;
	int reserve;
	_anon34 ltcal;
	_anon39 attr;
};

struct _anon29
{
	_anon32 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon30
{
	int* vlist;
	short* plist;
	_anon32 center;
	float r;
};

struct _anon31
{
	float x;
	float y;
};

struct _anon32
{
	float x;
	float y;
	float z;
};

struct _anon33
{
	_anon32 c1;
	_anon32 c2;
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
	_anon32 lpnt;
	_anon32 lvctr;
	_anon32 lmvctr;
	_anon26 atten;
	_anon26 amb;
	_anon26 dif;
	_anon26 spc;
	_anon26 mamb;
	_anon26 mdif;
	_anon26 mspc;
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
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon38
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

struct _anon39
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
	_anon26 argb;
};

struct _anon40
{
	_anon32 c;
	float r;
};

struct _anon41
{
	_anon32 c1;
	_anon32 c2;
	float r;
};

struct _anon42
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

struct _anon43
{
	float px;
	float py;
	float pz;
	float ox;
	float oy;
	float oz;
};

void(*bhJumpEnemy)()[100];
_anon23 En00CapColTab[5];
BH_PWORK ene[0];
_anon24* sys;
BH_PWORK* plp;
_anon9* rom;

void bhInitEnemy();
BH_PWORK* bhSetEnemy(_anon15* etp);
void bhCheckEneWorkNum();
void bhControlEnemy();
void bhEne00(BH_PWORK* ep);
void bhEne56(BH_PWORK* ep);
void bhDrawEnemy();
void bhDrawEneObject();
void* bhEne_CallocWork(int size);
void bhEne_SetCallFunc(void(*func)(BH_PWORK*), unsigned int no);

// 
// Start address: 0x174700
void bhInitEnemy()
{
	// Line 317, Address: 0x174700, Func Offset: 0
	// Func End, Address: 0x174718, Func Offset: 0x18
}

// 
// Start address: 0x174720
BH_PWORK* bhSetEnemy(_anon15* etp)
{
	int i;
	BH_PWORK* epp;
	// Line 323, Address: 0x174720, Func Offset: 0
	// Line 326, Address: 0x174734, Func Offset: 0x14
	// Line 327, Address: 0x174740, Func Offset: 0x20
	// Line 328, Address: 0x174744, Func Offset: 0x24
	// Line 329, Address: 0x174754, Func Offset: 0x34
	// Line 330, Address: 0x174764, Func Offset: 0x44
	// Line 331, Address: 0x17476c, Func Offset: 0x4c
	// Line 332, Address: 0x174774, Func Offset: 0x54
	// Line 334, Address: 0x174784, Func Offset: 0x64
	// Line 337, Address: 0x174788, Func Offset: 0x68
	// Line 334, Address: 0x17478c, Func Offset: 0x6c
	// Line 337, Address: 0x174794, Func Offset: 0x74
	// Line 347, Address: 0x17485c, Func Offset: 0x13c
	// Line 346, Address: 0x174860, Func Offset: 0x140
	// Line 347, Address: 0x174864, Func Offset: 0x144
	// Line 348, Address: 0x174868, Func Offset: 0x148
	// Line 349, Address: 0x174870, Func Offset: 0x150
	// Line 350, Address: 0x174878, Func Offset: 0x158
	// Line 351, Address: 0x174880, Func Offset: 0x160
	// Line 352, Address: 0x174888, Func Offset: 0x168
	// Line 353, Address: 0x174890, Func Offset: 0x170
	// Line 354, Address: 0x174894, Func Offset: 0x174
	// Line 364, Address: 0x17489c, Func Offset: 0x17c
	// Line 363, Address: 0x1748a0, Func Offset: 0x180
	// Line 364, Address: 0x1748a4, Func Offset: 0x184
	// Line 365, Address: 0x1748a8, Func Offset: 0x188
	// Line 366, Address: 0x1748b0, Func Offset: 0x190
	// Line 367, Address: 0x1748b8, Func Offset: 0x198
	// Line 368, Address: 0x1748c0, Func Offset: 0x1a0
	// Line 369, Address: 0x1748c8, Func Offset: 0x1a8
	// Line 370, Address: 0x1748d0, Func Offset: 0x1b0
	// Line 373, Address: 0x1748d8, Func Offset: 0x1b8
	// Line 381, Address: 0x1748e4, Func Offset: 0x1c4
	// Line 383, Address: 0x1748f4, Func Offset: 0x1d4
	// Line 385, Address: 0x174900, Func Offset: 0x1e0
	// Line 403, Address: 0x174904, Func Offset: 0x1e4
	// Line 412, Address: 0x174908, Func Offset: 0x1e8
	// Line 421, Address: 0x17490c, Func Offset: 0x1ec
	// Line 425, Address: 0x174910, Func Offset: 0x1f0
	// Line 385, Address: 0x174914, Func Offset: 0x1f4
	// Line 387, Address: 0x174918, Func Offset: 0x1f8
	// Line 426, Address: 0x17491c, Func Offset: 0x1fc
	// Line 427, Address: 0x174920, Func Offset: 0x200
	// Line 387, Address: 0x174924, Func Offset: 0x204
	// Line 388, Address: 0x174928, Func Offset: 0x208
	// Line 389, Address: 0x174930, Func Offset: 0x210
	// Line 390, Address: 0x174938, Func Offset: 0x218
	// Line 391, Address: 0x174940, Func Offset: 0x220
	// Line 392, Address: 0x174948, Func Offset: 0x228
	// Line 393, Address: 0x17494c, Func Offset: 0x22c
	// Line 394, Address: 0x174954, Func Offset: 0x234
	// Line 395, Address: 0x174958, Func Offset: 0x238
	// Line 396, Address: 0x174964, Func Offset: 0x244
	// Line 397, Address: 0x174968, Func Offset: 0x248
	// Line 398, Address: 0x174978, Func Offset: 0x258
	// Line 399, Address: 0x17497c, Func Offset: 0x25c
	// Line 400, Address: 0x174980, Func Offset: 0x260
	// Line 401, Address: 0x174984, Func Offset: 0x264
	// Line 402, Address: 0x174988, Func Offset: 0x268
	// Line 403, Address: 0x17498c, Func Offset: 0x26c
	// Line 404, Address: 0x174994, Func Offset: 0x274
	// Line 405, Address: 0x17499c, Func Offset: 0x27c
	// Line 407, Address: 0x1749a4, Func Offset: 0x284
	// Line 408, Address: 0x1749a8, Func Offset: 0x288
	// Line 409, Address: 0x1749ac, Func Offset: 0x28c
	// Line 412, Address: 0x1749b0, Func Offset: 0x290
	// Line 418, Address: 0x1749b4, Func Offset: 0x294
	// Line 419, Address: 0x1749c0, Func Offset: 0x2a0
	// Line 420, Address: 0x1749cc, Func Offset: 0x2ac
	// Line 421, Address: 0x1749d0, Func Offset: 0x2b0
	// Line 422, Address: 0x1749d4, Func Offset: 0x2b4
	// Line 423, Address: 0x1749d8, Func Offset: 0x2b8
	// Line 424, Address: 0x1749dc, Func Offset: 0x2bc
	// Line 425, Address: 0x1749e0, Func Offset: 0x2c0
	// Line 427, Address: 0x1749e4, Func Offset: 0x2c4
	// Line 428, Address: 0x1749ec, Func Offset: 0x2cc
	// Line 429, Address: 0x1749f4, Func Offset: 0x2d4
	// Line 431, Address: 0x1749fc, Func Offset: 0x2dc
	// Line 432, Address: 0x174a0c, Func Offset: 0x2ec
	// Line 433, Address: 0x174a14, Func Offset: 0x2f4
	// Line 434, Address: 0x174a18, Func Offset: 0x2f8
	// Func End, Address: 0x174a30, Func Offset: 0x310
}

// 
// Start address: 0x174a30
void bhCheckEneWorkNum()
{
	int i;
	BH_PWORK* epp;
	// Line 443, Address: 0x174a30, Func Offset: 0
	// Line 444, Address: 0x174a38, Func Offset: 0x8
	// Line 445, Address: 0x174a40, Func Offset: 0x10
	// Line 443, Address: 0x174a44, Func Offset: 0x14
	// Line 446, Address: 0x174a50, Func Offset: 0x20
	// Line 447, Address: 0x174a60, Func Offset: 0x30
	// Line 449, Address: 0x174a78, Func Offset: 0x48
	// Line 450, Address: 0x174a88, Func Offset: 0x58
	// Func End, Address: 0x174a90, Func Offset: 0x60
}

// 
// Start address: 0x174a90
void bhControlEnemy()
{
	unsigned int i;
	BH_PWORK* ep;
	// Line 539, Address: 0x174a90, Func Offset: 0
	// Line 543, Address: 0x174aa0, Func Offset: 0x10
	// Line 565, Address: 0x174ab8, Func Offset: 0x28
	// Line 566, Address: 0x174ad0, Func Offset: 0x40
	// Line 576, Address: 0x174ad8, Func Offset: 0x48
	// Line 566, Address: 0x174ae0, Func Offset: 0x50
	// Line 577, Address: 0x174ae4, Func Offset: 0x54
	// Line 578, Address: 0x174aec, Func Offset: 0x5c
	// Line 579, Address: 0x174af8, Func Offset: 0x68
	// Line 581, Address: 0x174b34, Func Offset: 0xa4
	// Line 582, Address: 0x174b38, Func Offset: 0xa8
	// Line 584, Address: 0x174b44, Func Offset: 0xb4
	// Line 585, Address: 0x174b4c, Func Offset: 0xbc
	// Line 586, Address: 0x174b54, Func Offset: 0xc4
	// Line 588, Address: 0x174b5c, Func Offset: 0xcc
	// Line 589, Address: 0x174b64, Func Offset: 0xd4
	// Line 590, Address: 0x174b6c, Func Offset: 0xdc
	// Line 592, Address: 0x174b74, Func Offset: 0xe4
	// Line 614, Address: 0x174b90, Func Offset: 0x100
	// Line 616, Address: 0x174bb0, Func Offset: 0x120
	// Line 618, Address: 0x174bb8, Func Offset: 0x128
	// Line 620, Address: 0x174c04, Func Offset: 0x174
	// Line 621, Address: 0x174c30, Func Offset: 0x1a0
	// Func End, Address: 0x174c44, Func Offset: 0x1b4
}

// 
// Start address: 0x174c50
void bhEne00(BH_PWORK* ep)
{
	_anon43 pnt;
	int i;
	_anon32 pos;
	_anon17* hp;
	// Line 628, Address: 0x174c50, Func Offset: 0
	// Line 632, Address: 0x174c60, Func Offset: 0x10
	// Line 634, Address: 0x174c8c, Func Offset: 0x3c
	// Line 653, Address: 0x174c90, Func Offset: 0x40
	// Line 640, Address: 0x174c94, Func Offset: 0x44
	// Line 643, Address: 0x174c98, Func Offset: 0x48
	// Line 634, Address: 0x174c9c, Func Offset: 0x4c
	// Line 640, Address: 0x174ca4, Func Offset: 0x54
	// Line 645, Address: 0x174ca8, Func Offset: 0x58
	// Line 646, Address: 0x174cac, Func Offset: 0x5c
	// Line 653, Address: 0x174cb0, Func Offset: 0x60
	// Line 654, Address: 0x174cb4, Func Offset: 0x64
	// Line 640, Address: 0x174cb8, Func Offset: 0x68
	// Line 642, Address: 0x174cc0, Func Offset: 0x70
	// Line 643, Address: 0x174ccc, Func Offset: 0x7c
	// Line 644, Address: 0x174cd8, Func Offset: 0x88
	// Line 645, Address: 0x174ce4, Func Offset: 0x94
	// Line 646, Address: 0x174ce8, Func Offset: 0x98
	// Line 647, Address: 0x174cec, Func Offset: 0x9c
	// Line 648, Address: 0x174cf0, Func Offset: 0xa0
	// Line 649, Address: 0x174cf4, Func Offset: 0xa4
	// Line 650, Address: 0x174cf8, Func Offset: 0xa8
	// Line 651, Address: 0x174cfc, Func Offset: 0xac
	// Line 652, Address: 0x174d00, Func Offset: 0xb0
	// Line 653, Address: 0x174d04, Func Offset: 0xb4
	// Line 654, Address: 0x174d08, Func Offset: 0xb8
	// Line 656, Address: 0x174d18, Func Offset: 0xc8
	// Line 657, Address: 0x174d1c, Func Offset: 0xcc
	// Line 659, Address: 0x174d24, Func Offset: 0xd4
	// Line 660, Address: 0x174d28, Func Offset: 0xd8
	// Line 663, Address: 0x174d2c, Func Offset: 0xdc
	// Line 657, Address: 0x174d30, Func Offset: 0xe0
	// Line 667, Address: 0x174d3c, Func Offset: 0xec
	// Line 680, Address: 0x174d40, Func Offset: 0xf0
	// Line 657, Address: 0x174d48, Func Offset: 0xf8
	// Line 658, Address: 0x174d5c, Func Offset: 0x10c
	// Line 680, Address: 0x174d68, Func Offset: 0x118
	// Line 658, Address: 0x174d70, Func Offset: 0x120
	// Line 659, Address: 0x174d8c, Func Offset: 0x13c
	// Line 660, Address: 0x174d90, Func Offset: 0x140
	// Line 661, Address: 0x174d94, Func Offset: 0x144
	// Line 665, Address: 0x174d98, Func Offset: 0x148
	// Line 661, Address: 0x174d9c, Func Offset: 0x14c
	// Line 663, Address: 0x174da0, Func Offset: 0x150
	// Line 664, Address: 0x174da4, Func Offset: 0x154
	// Line 665, Address: 0x174dac, Func Offset: 0x15c
	// Line 673, Address: 0x174dc0, Func Offset: 0x170
	// Line 665, Address: 0x174dc4, Func Offset: 0x174
	// Line 666, Address: 0x174dc8, Func Offset: 0x178
	// Line 667, Address: 0x174dd0, Func Offset: 0x180
	// Line 668, Address: 0x174dd4, Func Offset: 0x184
	// Line 669, Address: 0x174dd8, Func Offset: 0x188
	// Line 670, Address: 0x174ddc, Func Offset: 0x18c
	// Line 673, Address: 0x174de8, Func Offset: 0x198
	// Line 674, Address: 0x174dfc, Func Offset: 0x1ac
	// Line 675, Address: 0x174e00, Func Offset: 0x1b0
	// Line 676, Address: 0x174e04, Func Offset: 0x1b4
	// Line 677, Address: 0x174e08, Func Offset: 0x1b8
	// Line 678, Address: 0x174e0c, Func Offset: 0x1bc
	// Line 680, Address: 0x174e10, Func Offset: 0x1c0
	// Line 681, Address: 0x174e18, Func Offset: 0x1c8
	// Line 682, Address: 0x174e20, Func Offset: 0x1d0
	// Line 683, Address: 0x174e2c, Func Offset: 0x1dc
	// Line 685, Address: 0x174e30, Func Offset: 0x1e0
	// Line 682, Address: 0x174e34, Func Offset: 0x1e4
	// Line 683, Address: 0x174e50, Func Offset: 0x200
	// Line 685, Address: 0x174e54, Func Offset: 0x204
	// Line 687, Address: 0x174e58, Func Offset: 0x208
	// Line 688, Address: 0x174e5c, Func Offset: 0x20c
	// Line 690, Address: 0x174e64, Func Offset: 0x214
	// Line 691, Address: 0x174e70, Func Offset: 0x220
	// Line 690, Address: 0x174e74, Func Offset: 0x224
	// Line 691, Address: 0x174e8c, Func Offset: 0x23c
	// Line 693, Address: 0x174e98, Func Offset: 0x248
	// Line 698, Address: 0x174ea4, Func Offset: 0x254
	// Line 699, Address: 0x174ea8, Func Offset: 0x258
	// Line 701, Address: 0x174eb0, Func Offset: 0x260
	// Line 698, Address: 0x174eb4, Func Offset: 0x264
	// Line 699, Address: 0x174eb8, Func Offset: 0x268
	// Line 700, Address: 0x174ec4, Func Offset: 0x274
	// Line 701, Address: 0x174ec8, Func Offset: 0x278
	// Line 702, Address: 0x174ed0, Func Offset: 0x280
	// Line 704, Address: 0x174ed4, Func Offset: 0x284
	// Line 709, Address: 0x174ed8, Func Offset: 0x288
	// Line 702, Address: 0x174edc, Func Offset: 0x28c
	// Line 703, Address: 0x174ee4, Func Offset: 0x294
	// Line 704, Address: 0x174ef0, Func Offset: 0x2a0
	// Line 708, Address: 0x174efc, Func Offset: 0x2ac
	// Line 709, Address: 0x174f08, Func Offset: 0x2b8
	// Line 713, Address: 0x174f0c, Func Offset: 0x2bc
	// Line 714, Address: 0x174f14, Func Offset: 0x2c4
	// Line 715, Address: 0x174f1c, Func Offset: 0x2cc
	// Line 721, Address: 0x174f24, Func Offset: 0x2d4
	// Line 722, Address: 0x174f34, Func Offset: 0x2e4
	// Line 723, Address: 0x174f5c, Func Offset: 0x30c
	// Line 726, Address: 0x174f6c, Func Offset: 0x31c
	// Line 727, Address: 0x174f84, Func Offset: 0x334
	// Line 728, Address: 0x174f9c, Func Offset: 0x34c
	// Line 730, Address: 0x174fb4, Func Offset: 0x364
	// Line 732, Address: 0x174fc0, Func Offset: 0x370
	// Line 736, Address: 0x174fc4, Func Offset: 0x374
	// Line 732, Address: 0x174fcc, Func Offset: 0x37c
	// Line 733, Address: 0x174fd8, Func Offset: 0x388
	// Line 734, Address: 0x174fe8, Func Offset: 0x398
	// Line 735, Address: 0x174ff8, Func Offset: 0x3a8
	// Line 736, Address: 0x175000, Func Offset: 0x3b0
	// Line 737, Address: 0x17500c, Func Offset: 0x3bc
	// Line 738, Address: 0x175014, Func Offset: 0x3c4
	// Line 739, Address: 0x17501c, Func Offset: 0x3cc
	// Func End, Address: 0x175030, Func Offset: 0x3e0
}

// 
// Start address: 0x175030
void bhEne56(BH_PWORK* ep)
{
	_anon32 pos;
	_anon0* op;
	// Line 746, Address: 0x175030, Func Offset: 0
	// Line 749, Address: 0x175040, Func Offset: 0x10
	// Line 750, Address: 0x175044, Func Offset: 0x14
	// Line 749, Address: 0x175048, Func Offset: 0x18
	// Line 750, Address: 0x175050, Func Offset: 0x20
	// Line 752, Address: 0x175078, Func Offset: 0x48
	// Line 753, Address: 0x17507c, Func Offset: 0x4c
	// Line 757, Address: 0x175080, Func Offset: 0x50
	// Line 761, Address: 0x175084, Func Offset: 0x54
	// Line 762, Address: 0x175088, Func Offset: 0x58
	// Line 752, Address: 0x17508c, Func Offset: 0x5c
	// Line 753, Address: 0x175094, Func Offset: 0x64
	// Line 754, Address: 0x1750a8, Func Offset: 0x78
	// Line 755, Address: 0x1750ac, Func Offset: 0x7c
	// Line 756, Address: 0x1750b0, Func Offset: 0x80
	// Line 757, Address: 0x1750b4, Func Offset: 0x84
	// Line 758, Address: 0x1750b8, Func Offset: 0x88
	// Line 759, Address: 0x1750bc, Func Offset: 0x8c
	// Line 760, Address: 0x1750c0, Func Offset: 0x90
	// Line 761, Address: 0x1750c4, Func Offset: 0x94
	// Line 762, Address: 0x1750d8, Func Offset: 0xa8
	// Line 763, Address: 0x1750f0, Func Offset: 0xc0
	// Line 765, Address: 0x1750f8, Func Offset: 0xc8
	// Line 763, Address: 0x1750fc, Func Offset: 0xcc
	// Line 765, Address: 0x175100, Func Offset: 0xd0
	// Line 764, Address: 0x175104, Func Offset: 0xd4
	// Line 763, Address: 0x175108, Func Offset: 0xd8
	// Line 764, Address: 0x175118, Func Offset: 0xe8
	// Line 765, Address: 0x175130, Func Offset: 0x100
	// Line 766, Address: 0x175144, Func Offset: 0x114
	// Line 767, Address: 0x17514c, Func Offset: 0x11c
	// Line 768, Address: 0x175158, Func Offset: 0x128
	// Line 769, Address: 0x17515c, Func Offset: 0x12c
	// Line 767, Address: 0x175160, Func Offset: 0x130
	// Line 768, Address: 0x175170, Func Offset: 0x140
	// Line 769, Address: 0x175188, Func Offset: 0x158
	// Line 772, Address: 0x1751a0, Func Offset: 0x170
	// Line 773, Address: 0x1751b0, Func Offset: 0x180
	// Line 774, Address: 0x1751d8, Func Offset: 0x1a8
	// Line 776, Address: 0x1751e4, Func Offset: 0x1b4
	// Line 777, Address: 0x175200, Func Offset: 0x1d0
	// Line 781, Address: 0x175208, Func Offset: 0x1d8
	// Line 784, Address: 0x17520c, Func Offset: 0x1dc
	// Line 777, Address: 0x175210, Func Offset: 0x1e0
	// Line 778, Address: 0x175240, Func Offset: 0x210
	// Line 779, Address: 0x17524c, Func Offset: 0x21c
	// Line 780, Address: 0x175250, Func Offset: 0x220
	// Line 781, Address: 0x175254, Func Offset: 0x224
	// Line 782, Address: 0x175258, Func Offset: 0x228
	// Line 783, Address: 0x17525c, Func Offset: 0x22c
	// Line 785, Address: 0x175260, Func Offset: 0x230
	// Line 787, Address: 0x175268, Func Offset: 0x238
	// Line 790, Address: 0x175270, Func Offset: 0x240
	// Line 793, Address: 0x175278, Func Offset: 0x248
	// Line 790, Address: 0x17527c, Func Offset: 0x24c
	// Line 791, Address: 0x17528c, Func Offset: 0x25c
	// Line 792, Address: 0x1752a4, Func Offset: 0x274
	// Line 793, Address: 0x1752bc, Func Offset: 0x28c
	// Line 794, Address: 0x1752cc, Func Offset: 0x29c
	// Line 795, Address: 0x1752d4, Func Offset: 0x2a4
	// Line 797, Address: 0x175310, Func Offset: 0x2e0
	// Line 798, Address: 0x175324, Func Offset: 0x2f4
	// Line 799, Address: 0x175328, Func Offset: 0x2f8
	// Line 801, Address: 0x175330, Func Offset: 0x300
	// Line 803, Address: 0x175334, Func Offset: 0x304
	// Line 805, Address: 0x17533c, Func Offset: 0x30c
	// Line 807, Address: 0x17535c, Func Offset: 0x32c
	// Line 809, Address: 0x175364, Func Offset: 0x334
	// Line 810, Address: 0x175368, Func Offset: 0x338
	// Line 809, Address: 0x175374, Func Offset: 0x344
	// Line 811, Address: 0x17537c, Func Offset: 0x34c
	// Line 812, Address: 0x175388, Func Offset: 0x358
	// Line 809, Address: 0x17538c, Func Offset: 0x35c
	// Line 812, Address: 0x175398, Func Offset: 0x368
	// Line 809, Address: 0x1753a8, Func Offset: 0x378
	// Line 810, Address: 0x1753b4, Func Offset: 0x384
	// Line 811, Address: 0x1753c0, Func Offset: 0x390
	// Line 812, Address: 0x1753c8, Func Offset: 0x398
	// Line 813, Address: 0x1753d8, Func Offset: 0x3a8
	// Line 814, Address: 0x1753ec, Func Offset: 0x3bc
	// Line 816, Address: 0x1753f4, Func Offset: 0x3c4
	// Line 817, Address: 0x1753f8, Func Offset: 0x3c8
	// Line 816, Address: 0x175404, Func Offset: 0x3d4
	// Line 818, Address: 0x17540c, Func Offset: 0x3dc
	// Line 819, Address: 0x175414, Func Offset: 0x3e4
	// Line 816, Address: 0x175420, Func Offset: 0x3f0
	// Line 819, Address: 0x17542c, Func Offset: 0x3fc
	// Line 816, Address: 0x175434, Func Offset: 0x404
	// Line 817, Address: 0x175440, Func Offset: 0x410
	// Line 818, Address: 0x17544c, Func Offset: 0x41c
	// Line 819, Address: 0x175454, Func Offset: 0x424
	// Line 820, Address: 0x175464, Func Offset: 0x434
	// Line 821, Address: 0x175478, Func Offset: 0x448
	// Line 823, Address: 0x175480, Func Offset: 0x450
	// Line 824, Address: 0x175484, Func Offset: 0x454
	// Line 823, Address: 0x175490, Func Offset: 0x460
	// Line 825, Address: 0x175498, Func Offset: 0x468
	// Line 826, Address: 0x1754a0, Func Offset: 0x470
	// Line 823, Address: 0x1754ac, Func Offset: 0x47c
	// Line 826, Address: 0x1754b8, Func Offset: 0x488
	// Line 823, Address: 0x1754c0, Func Offset: 0x490
	// Line 824, Address: 0x1754cc, Func Offset: 0x49c
	// Line 825, Address: 0x1754d8, Func Offset: 0x4a8
	// Line 826, Address: 0x1754e0, Func Offset: 0x4b0
	// Line 827, Address: 0x1754f0, Func Offset: 0x4c0
	// Line 828, Address: 0x175504, Func Offset: 0x4d4
	// Line 830, Address: 0x17550c, Func Offset: 0x4dc
	// Line 831, Address: 0x175510, Func Offset: 0x4e0
	// Line 830, Address: 0x17551c, Func Offset: 0x4ec
	// Line 832, Address: 0x175524, Func Offset: 0x4f4
	// Line 833, Address: 0x17552c, Func Offset: 0x4fc
	// Line 830, Address: 0x175538, Func Offset: 0x508
	// Line 833, Address: 0x175544, Func Offset: 0x514
	// Line 830, Address: 0x17554c, Func Offset: 0x51c
	// Line 831, Address: 0x175558, Func Offset: 0x528
	// Line 832, Address: 0x175564, Func Offset: 0x534
	// Line 833, Address: 0x17556c, Func Offset: 0x53c
	// Line 834, Address: 0x17557c, Func Offset: 0x54c
	// Line 835, Address: 0x175590, Func Offset: 0x560
	// Line 841, Address: 0x175598, Func Offset: 0x568
	// Line 842, Address: 0x1755b8, Func Offset: 0x588
	// Line 843, Address: 0x1755bc, Func Offset: 0x58c
	// Line 844, Address: 0x1755d8, Func Offset: 0x5a8
	// Line 845, Address: 0x175634, Func Offset: 0x604
	// Line 848, Address: 0x175638, Func Offset: 0x608
	// Line 850, Address: 0x175640, Func Offset: 0x610
	// Line 851, Address: 0x175658, Func Offset: 0x628
	// Line 850, Address: 0x175660, Func Offset: 0x630
	// Line 851, Address: 0x175668, Func Offset: 0x638
	// Line 850, Address: 0x17566c, Func Offset: 0x63c
	// Line 851, Address: 0x175678, Func Offset: 0x648
	// Line 852, Address: 0x175680, Func Offset: 0x650
	// Line 853, Address: 0x175690, Func Offset: 0x660
	// Line 854, Address: 0x175698, Func Offset: 0x668
	// Line 855, Address: 0x17569c, Func Offset: 0x66c
	// Line 856, Address: 0x1756a0, Func Offset: 0x670
	// Line 857, Address: 0x1756b0, Func Offset: 0x680
	// Line 858, Address: 0x1756c0, Func Offset: 0x690
	// Line 860, Address: 0x1756c4, Func Offset: 0x694
	// Line 861, Address: 0x175704, Func Offset: 0x6d4
	// Line 867, Address: 0x17570c, Func Offset: 0x6dc
	// Line 861, Address: 0x175714, Func Offset: 0x6e4
	// Line 862, Address: 0x17571c, Func Offset: 0x6ec
	// Line 863, Address: 0x17572c, Func Offset: 0x6fc
	// Line 864, Address: 0x17573c, Func Offset: 0x70c
	// Line 865, Address: 0x17574c, Func Offset: 0x71c
	// Line 866, Address: 0x175750, Func Offset: 0x720
	// Line 867, Address: 0x175754, Func Offset: 0x724
	// Line 870, Address: 0x175760, Func Offset: 0x730
	// Line 872, Address: 0x175768, Func Offset: 0x738
	// Line 873, Address: 0x175774, Func Offset: 0x744
	// Line 872, Address: 0x175778, Func Offset: 0x748
	// Line 873, Address: 0x17579c, Func Offset: 0x76c
	// Line 875, Address: 0x1757c4, Func Offset: 0x794
	// Line 876, Address: 0x1757cc, Func Offset: 0x79c
	// Line 875, Address: 0x1757d8, Func Offset: 0x7a8
	// Line 876, Address: 0x1757e0, Func Offset: 0x7b0
	// Line 877, Address: 0x17580c, Func Offset: 0x7dc
	// Line 878, Address: 0x175828, Func Offset: 0x7f8
	// Line 879, Address: 0x175830, Func Offset: 0x800
	// Line 880, Address: 0x175838, Func Offset: 0x808
	// Line 882, Address: 0x175848, Func Offset: 0x818
	// Line 884, Address: 0x175850, Func Offset: 0x820
	// Line 885, Address: 0x175868, Func Offset: 0x838
	// Line 886, Address: 0x175870, Func Offset: 0x840
	// Line 884, Address: 0x175878, Func Offset: 0x848
	// Line 885, Address: 0x17588c, Func Offset: 0x85c
	// Line 886, Address: 0x175894, Func Offset: 0x864
	// Line 885, Address: 0x17589c, Func Offset: 0x86c
	// Line 886, Address: 0x1758a0, Func Offset: 0x870
	// Line 887, Address: 0x1758b0, Func Offset: 0x880
	// Line 888, Address: 0x1758b8, Func Offset: 0x888
	// Line 897, Address: 0x1758bc, Func Offset: 0x88c
	// Line 899, Address: 0x1758c4, Func Offset: 0x894
	// Line 900, Address: 0x1758cc, Func Offset: 0x89c
	// Line 901, Address: 0x1758dc, Func Offset: 0x8ac
	// Line 932, Address: 0x1758e4, Func Offset: 0x8b4
	// Func End, Address: 0x1758f8, Func Offset: 0x8c8
}

// 
// Start address: 0x175900
void bhDrawEnemy()
{
	unsigned int argb;
	int i;
	BH_PWORK* ep;
	// Line 938, Address: 0x175900, Func Offset: 0
	// Line 955, Address: 0x175910, Func Offset: 0x10
	// Line 956, Address: 0x175918, Func Offset: 0x18
	// Line 957, Address: 0x175920, Func Offset: 0x20
	// Line 1008, Address: 0x175940, Func Offset: 0x40
	// Line 1011, Address: 0x17599c, Func Offset: 0x9c
	// Line 1022, Address: 0x1759a0, Func Offset: 0xa0
	// Line 1024, Address: 0x1759b8, Func Offset: 0xb8
	// Line 1025, Address: 0x1759c8, Func Offset: 0xc8
	// Line 1028, Address: 0x1759d8, Func Offset: 0xd8
	// Line 1034, Address: 0x1759f8, Func Offset: 0xf8
	// Line 1035, Address: 0x175a10, Func Offset: 0x110
	// Line 1036, Address: 0x175a18, Func Offset: 0x118
	// Line 1038, Address: 0x175a20, Func Offset: 0x120
	// Line 1039, Address: 0x175a38, Func Offset: 0x138
	// Line 1042, Address: 0x175a44, Func Offset: 0x144
	// Line 1044, Address: 0x175a4c, Func Offset: 0x14c
	// Line 1045, Address: 0x175aa0, Func Offset: 0x1a0
	// Line 1046, Address: 0x175aa8, Func Offset: 0x1a8
	// Line 1048, Address: 0x175abc, Func Offset: 0x1bc
	// Line 1049, Address: 0x175ac0, Func Offset: 0x1c0
	// Line 1051, Address: 0x175ad0, Func Offset: 0x1d0
	// Line 1052, Address: 0x175ae0, Func Offset: 0x1e0
	// Line 1056, Address: 0x175af8, Func Offset: 0x1f8
	// Line 1057, Address: 0x175b00, Func Offset: 0x200
	// Line 1058, Address: 0x175b0c, Func Offset: 0x20c
	// Line 1059, Address: 0x175b1c, Func Offset: 0x21c
	// Line 1061, Address: 0x175b24, Func Offset: 0x224
	// Line 1065, Address: 0x175b30, Func Offset: 0x230
	// Line 1066, Address: 0x175b58, Func Offset: 0x258
	// Func End, Address: 0x175b6c, Func Offset: 0x26c
}

// 
// Start address: 0x175b70
void bhDrawEneObject()
{
	int i;
	BH_PWORK* ep;
	// Line 1072, Address: 0x175b70, Func Offset: 0
	// Line 1089, Address: 0x175b84, Func Offset: 0x14
	// Line 1090, Address: 0x175b90, Func Offset: 0x20
	// Line 1091, Address: 0x175ba0, Func Offset: 0x30
	// Line 1092, Address: 0x175bb0, Func Offset: 0x40
	// Line 1103, Address: 0x175bc4, Func Offset: 0x54
	// Line 1105, Address: 0x175be0, Func Offset: 0x70
	// Line 1106, Address: 0x175bf0, Func Offset: 0x80
	// Line 1108, Address: 0x175c00, Func Offset: 0x90
	// Line 1113, Address: 0x175c20, Func Offset: 0xb0
	// Line 1115, Address: 0x175c2c, Func Offset: 0xbc
	// Line 1116, Address: 0x175c38, Func Offset: 0xc8
	// Line 1120, Address: 0x175c50, Func Offset: 0xe0
	// Line 1121, Address: 0x175c58, Func Offset: 0xe8
	// Line 1122, Address: 0x175c64, Func Offset: 0xf4
	// Line 1123, Address: 0x175c74, Func Offset: 0x104
	// Line 1124, Address: 0x175c7c, Func Offset: 0x10c
	// Line 1128, Address: 0x175c8c, Func Offset: 0x11c
	// Line 1129, Address: 0x175cb0, Func Offset: 0x140
	// Func End, Address: 0x175cc8, Func Offset: 0x158
}

// 
// Start address: 0x175cd0
void* bhEne_CallocWork(int size)
{
	unsigned char* addr;
	unsigned char* ret_addr;
	// Line 1205, Address: 0x175cd0, Func Offset: 0
	// Line 1207, Address: 0x175d10, Func Offset: 0x40
	// Line 1210, Address: 0x175d18, Func Offset: 0x48
	// Line 1211, Address: 0x175d28, Func Offset: 0x58
	// Line 1215, Address: 0x175d30, Func Offset: 0x60
	// Line 1211, Address: 0x175d34, Func Offset: 0x64
	// Line 1212, Address: 0x175d44, Func Offset: 0x74
	// Line 1215, Address: 0x175d4c, Func Offset: 0x7c
	// Line 1217, Address: 0x175d58, Func Offset: 0x88
	// Line 1218, Address: 0x175d5c, Func Offset: 0x8c
	// Line 1217, Address: 0x175d60, Func Offset: 0x90
	// Line 1218, Address: 0x175d64, Func Offset: 0x94
	// Line 1220, Address: 0x175d78, Func Offset: 0xa8
	// Func End, Address: 0x175d80, Func Offset: 0xb0
}

// 
// Start address: 0x175d80
void bhEne_SetCallFunc(void(*func)(BH_PWORK*), unsigned int no)
{
	// Line 1231, Address: 0x175d80, Func Offset: 0
	// Line 1232, Address: 0x175d90, Func Offset: 0x10
	// Func End, Address: 0x175d98, Func Offset: 0x18
}

