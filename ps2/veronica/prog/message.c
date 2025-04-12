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
typedef union _anon23;
typedef struct _anon24;
typedef struct _anon25;
typedef struct _anon26;
typedef struct _anon27;
typedef struct _anon28;
typedef struct _anon29;
typedef struct _anon30;
typedef struct _anon31;
typedef struct _anon32;
typedef struct BH_PWORK;
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

typedef void(*type_82)(void*);

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
typedef unsigned char type_12[126];
typedef char type_13[32];
typedef float type_14[32];
typedef _anon0* type_15[512];
typedef _anon1* type_16[200];
typedef short type_17[32];
typedef _anon26 type_18[1];
typedef _anon2 type_19[4];
typedef _anon0* type_20[128];
typedef unsigned int type_21[1];
typedef _anon23 type_22[4];
typedef _anon7 type_23[256];
typedef _anon1* type_24[8];
typedef int* type_25[16];
typedef _anon0* type_26[128];
typedef _anon46 type_27[16];
typedef npobj* type_28[16];
typedef _anon23 type_29[4];
typedef _anon0* type_30[128];
typedef int type_31[4];
typedef _anon1* type_32[16];
typedef unsigned int type_33[4];
typedef float type_34[4];
typedef _anon12 type_35[16];
typedef _anon0* type_36[512];
typedef float type_37[4];
typedef char type_38[256];
typedef float type_39[4];
typedef float type_40[4];
typedef float type_41[4];
typedef float type_42[4];
typedef _anon5* type_43[128];
typedef unsigned char type_44[64];
typedef float type_45[16];
typedef int type_46[10];
typedef char type_47[8];
typedef void* type_48[2];
typedef _anon1* type_49[256];
typedef int type_50[4];
typedef unsigned char* type_51[256];
typedef unsigned int type_52[2];
typedef short type_53[256];
typedef _anon33 type_54[4];
typedef float type_55[3];
typedef short type_56[256];
typedef int type_57[3];
typedef int type_58[8];
typedef float type_59[3];
typedef _anon1* type_60[256];
typedef _anon9 type_61[256];
typedef _anon26 type_62[450];
typedef _anon2 type_63[16];
typedef short type_64[256];
typedef char type_65[3];
typedef int type_66[64];
typedef _anon12 type_67[450];
typedef unsigned int type_68[16];
typedef char type_69[4];
typedef unsigned int type_70[8];
typedef _anon38 type_71[4];
typedef _anon3 type_72[4];
typedef int type_73[450];
typedef int type_74[10];
typedef unsigned int type_75[8];
typedef unsigned char type_76[450];
typedef float type_77[128];
typedef char type_78[16];
typedef float type_79[4];
typedef float type_80[4][3];
typedef char type_81[4];
typedef _anon24 type_83[2];
typedef unsigned int type_84[32];
typedef unsigned char type_85[256];
typedef unsigned int type_86[16];
typedef _anon20 type_87[64];
typedef unsigned int type_88[16];
typedef _anon20 type_89[64];
typedef unsigned int type_90[32];
typedef _anon20 type_91[64];
typedef unsigned int type_92[16];
typedef unsigned int type_93[3];
typedef BH_PWORK* type_94[16];
typedef unsigned int type_95[8];
typedef unsigned int type_96[1];
typedef unsigned int type_97[384];
typedef unsigned int type_98[2];
typedef unsigned char type_99[2];
typedef int* type_100[16];
typedef unsigned int type_101[4];
typedef char type_102[32];
typedef npobj* type_103[16];
typedef char type_104[64];
typedef _anon1* type_105[16];
typedef char type_106[4];
typedef _anon12 type_107[16];
typedef short type_108[4];
typedef unsigned char type_109[4];
typedef _anon36 type_110[16];
typedef unsigned int type_111[8];
typedef unsigned int type_112[32];
typedef unsigned int type_113[4];
typedef _anon35 type_114[32];
typedef _anon0* type_115[512];
typedef _anon0* type_116[128];
typedef _anon2 type_117[4];
typedef _anon0* type_118[512];
typedef _anon23 type_119[4];
typedef unsigned char type_120[64];
typedef _anon23 type_121[4];
typedef _anon0* type_122[512];

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
	_anon12 mdl[16];
	_anon12* mlwP;
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
	_anon44 cspr;
	int pn;
	_anon38* pvp;
	_anon3* tvp;
	_anon38 pv[4];
	_anon3 tv[4];
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
	_anon26* textures;
	unsigned int nbTexture;
};

struct _anon2
{
	float x;
	float y;
};

struct _anon3
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon4
{
	float px;
	float py;
	float pz;
	int ay;
};

struct _anon5
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon25* md2P;
	unsigned short* atrP;
};

struct _anon6
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon46 keyf[16];
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

struct _anon9
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon10
{
	_anon11* cutp;
	_anon15* lgtp;
	_anon16* enep;
	_anon16* objp;
	_anon16* itmp;
	_anon19* effp;
	_anon20* walp;
	_anon20* etcp;
	_anon20* flrp;
	_anon4* posp;
	_anon20* rutp;
	unsigned char* ruttp;
	_anon29* evtp;
	_anon6* evcp;
	unsigned int* mesp;
	_anon15* evlp;
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
	_anon12 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};

struct _anon11
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon14* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon24 cam[2];
	unsigned char exd[256];
};

struct _anon12
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon31* owP;
};

struct _anon13
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
	_anon42* info;
};

struct _anon14
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

struct _anon15
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
	_anon32* light;
};

struct _anon16
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

struct _anon17
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

struct _anon18
{
	short u;
	short v;
};

struct _anon19
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

struct _anon20
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

struct _anon21
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct _anon22
{
	void* texaddr;
	_anon8 texsurface;
};

union _anon23
{
	unsigned int color;
	_anon18 tex;
	_anon21 argb;
};

struct _anon24
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

struct _anon25
{
	void* p[2];
};

struct _anon26
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon27
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon28
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
	_anon35 ply_pos;
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
	_anon13* p1per;
	_anon13* p2per;
	_anon13* kbper;
	_anon13* msper;
	_anon13 ms_per;
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
	_anon9 txbp[256];
	unsigned char* ef_psp;
	_anon26 ef_tex[450];
	_anon1 ef_tlist;
	_anon40 ef;
	short efid[256];
	_anon12 efm[450];
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
	_anon26 ren_tex[1];
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
	_anon41 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon15* lgtp;
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
	_anon2 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon20* pl_htp;
	int costume;
	_anon35 hd_pos;
	_anon35 apos;
	_anon20* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon20 mwalp[64];
	_anon20 metcp[64];
	_anon20 mflrp[64];
	int dla_n;
	_anon20* htp;
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
	_anon17 door;
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
	_anon35 ufo_pos;
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
	_anon36 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon35 ghtp[32];
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
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon32
{
	float mtrx[16];
	_anon35 pnt;
	_anon35 vctr;
	int stat;
	int reserve;
	_anon37 ltcal;
	_anon43 attr;
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
	_anon12 mdl[16];
	_anon12* mlwP;
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
	_anon45 watr;
	_anon27* cpcl;
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

struct _anon33
{
	_anon35 ps;
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
	_anon35 center;
	float r;
};

struct _anon35
{
	float x;
	float y;
	float z;
};

struct _anon36
{
	_anon35 c1;
	_anon35 c2;
	float r1;
	float r2;
};

struct _anon37
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
	_anon35 lpnt;
	_anon35 lvctr;
	_anon35 lmvctr;
	_anon30 atten;
	_anon30 amb;
	_anon30 dif;
	_anon30 spc;
	_anon30 mamb;
	_anon30 mdif;
	_anon30 mspc;
};

struct _anon38
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon39
{
	_anon2* p;
	_anon23* col;
	_anon23* tex;
	unsigned int num;
};

struct _anon40
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

struct _anon41
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon42
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

struct _anon43
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

struct _anon44
{
	_anon35 c;
	float r;
};

struct _anon45
{
	_anon35 c1;
	_anon35 c2;
	float r;
};

struct _anon46
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

float mes_spos[4][3];*/
unsigned char FontSz[126];
SYS_WORK* sys;
ROM_WORK* rom;
float FontScaleX;
float FontScaleCR;
float FontScaleY;

/*void bhSetMessage(int mes_typ, int mes_idx);
void bhControlMessage(int mode);
void bhDispFont(_anon2* pos, int code, int color, float pri);
void bhDispFontEx(_anon2* pos, int code, unsigned int argb, float pri);
int bhDispItemName(_anon2* pos, int id, int color, int count, float pri);
int bhDispMessage(float px, float py, float pri, int mes_typ, int mes_idx, int color, int count);
int bhDispMessageEx(float px, float py, float pri, int mes_typ, int mes_idx, unsigned int argb, int count);
void bhDispTime(_anon2* pos, unsigned int flg, int time, int color, float pri);
void bhDispTimeEx(_anon2* pos, unsigned int flg, int time, unsigned int argb, float pri);*/
float bhGetFontSize(unsigned short code);
/*float bhMesLen(unsigned short* dp);
void bhFontScaleSet(float ScaleX, float ScaleY, float ScaleCR);

// 
// Start address: 0x2b7510
void bhSetMessage(int mes_typ, int mes_idx)
{
	// Line 119, Address: 0x2b7510, Func Offset: 0
	// Line 121, Address: 0x2b752c, Func Offset: 0x1c
	// Line 122, Address: 0x2b7548, Func Offset: 0x38
	// Line 124, Address: 0x2b7550, Func Offset: 0x40
	// Line 125, Address: 0x2b756c, Func Offset: 0x5c
	// Line 127, Address: 0x2b7574, Func Offset: 0x64
	// Line 130, Address: 0x2b757c, Func Offset: 0x6c
	// Line 145, Address: 0x2b7588, Func Offset: 0x78
	// Line 146, Address: 0x2b7590, Func Offset: 0x80
	// Line 130, Address: 0x2b7598, Func Offset: 0x88
	// Line 131, Address: 0x2b75a4, Func Offset: 0x94
	// Line 135, Address: 0x2b75d4, Func Offset: 0xc4
	// Line 131, Address: 0x2b75d8, Func Offset: 0xc8
	// Line 135, Address: 0x2b75e0, Func Offset: 0xd0
	// Line 136, Address: 0x2b75f0, Func Offset: 0xe0
	// Line 137, Address: 0x2b7604, Func Offset: 0xf4
	// Line 138, Address: 0x2b7618, Func Offset: 0x108
	// Line 139, Address: 0x2b762c, Func Offset: 0x11c
	// Line 145, Address: 0x2b7638, Func Offset: 0x128
	// Line 139, Address: 0x2b763c, Func Offset: 0x12c
	// Line 145, Address: 0x2b7644, Func Offset: 0x134
	// Line 146, Address: 0x2b764c, Func Offset: 0x13c
	// Line 145, Address: 0x2b7650, Func Offset: 0x140
	// Line 146, Address: 0x2b7658, Func Offset: 0x148
	// Line 147, Address: 0x2b7668, Func Offset: 0x158
	// Func End, Address: 0x2b7670, Func Offset: 0x160
}*/

// 
// Start address: 0x2b7670
void bhControlMessage(int mode)
{
	int itn;
	int end;
	int col;
	int mct;
	unsigned short id;
	unsigned short cd;
	unsigned short* dt;
	//_anon2 pos;
	// Line 160, Address: 0x2b7670, Func Offset: 0
	// Line 164, Address: 0x2b7698, Func Offset: 0x28
	// Line 165, Address: 0x2b76ac, Func Offset: 0x3c
	// Line 166, Address: 0x2b76b4, Func Offset: 0x44
	// Line 167, Address: 0x2b76e8, Func Offset: 0x78
	// Line 168, Address: 0x2b76fc, Func Offset: 0x8c
	// Line 167, Address: 0x2b7708, Func Offset: 0x98
	// Line 168, Address: 0x2b770c, Func Offset: 0x9c
	// Line 169, Address: 0x2b7714, Func Offset: 0xa4
	// Line 170, Address: 0x2b7718, Func Offset: 0xa8
	// Line 171, Address: 0x2b771c, Func Offset: 0xac
	// Line 172, Address: 0x2b7720, Func Offset: 0xb0
	// Line 174, Address: 0x2b7728, Func Offset: 0xb8
	// Line 176, Address: 0x2b772c, Func Offset: 0xbc
	// Line 178, Address: 0x2b7838, Func Offset: 0x1c8
	// Line 180, Address: 0x2b7858, Func Offset: 0x1e8
	// Line 179, Address: 0x2b785c, Func Offset: 0x1ec
	// Line 180, Address: 0x2b7860, Func Offset: 0x1f0
	// Line 181, Address: 0x2b7868, Func Offset: 0x1f8
	// Line 183, Address: 0x2b7870, Func Offset: 0x200
	// Line 184, Address: 0x2b7874, Func Offset: 0x204
	// Line 183, Address: 0x2b7884, Func Offset: 0x214
	// Line 184, Address: 0x2b7888, Func Offset: 0x218
	// Line 185, Address: 0x2b7894, Func Offset: 0x224
	// Line 188, Address: 0x2b789c, Func Offset: 0x22c
	// Line 189, Address: 0x2b78b4, Func Offset: 0x244
	// Line 192, Address: 0x2b78bc, Func Offset: 0x24c
	// Line 195, Address: 0x2b78e8, Func Offset: 0x278
	// Line 196, Address: 0x2b78ec, Func Offset: 0x27c
	// Line 198, Address: 0x2b78f4, Func Offset: 0x284
	// Line 199, Address: 0x2b78f8, Func Offset: 0x288
	// Line 198, Address: 0x2b78fc, Func Offset: 0x28c
	// Line 199, Address: 0x2b7900, Func Offset: 0x290
	// Line 201, Address: 0x2b7918, Func Offset: 0x2a8
	// Line 202, Address: 0x2b791c, Func Offset: 0x2ac
	// Line 201, Address: 0x2b7920, Func Offset: 0x2b0
	// Line 203, Address: 0x2b7924, Func Offset: 0x2b4
	// Line 205, Address: 0x2b792c, Func Offset: 0x2bc
	// Line 206, Address: 0x2b7934, Func Offset: 0x2c4
	// Line 209, Address: 0x2b793c, Func Offset: 0x2cc
	// Line 210, Address: 0x2b7940, Func Offset: 0x2d0
	// Line 215, Address: 0x2b7960, Func Offset: 0x2f0
	// Line 217, Address: 0x2b7984, Func Offset: 0x314
	// Line 219, Address: 0x2b798c, Func Offset: 0x31c
	// Line 222, Address: 0x2b7994, Func Offset: 0x324
	// Line 225, Address: 0x2b799c, Func Offset: 0x32c
	// Line 226, Address: 0x2b79ac, Func Offset: 0x33c
	// Line 227, Address: 0x2b79b0, Func Offset: 0x340
	// Line 226, Address: 0x2b79b8, Func Offset: 0x348
	// Line 227, Address: 0x2b79c0, Func Offset: 0x350
	// Line 229, Address: 0x2b79e0, Func Offset: 0x370
	// Line 232, Address: 0x2b79e8, Func Offset: 0x378
	// Line 229, Address: 0x2b79f0, Func Offset: 0x380
	// Line 230, Address: 0x2b7a14, Func Offset: 0x3a4
	// Line 231, Address: 0x2b7a40, Func Offset: 0x3d0
	// Line 232, Address: 0x2b7a64, Func Offset: 0x3f4
	// Line 233, Address: 0x2b7a78, Func Offset: 0x408
	// Line 237, Address: 0x2b7a80, Func Offset: 0x410
	// Line 238, Address: 0x2b7a88, Func Offset: 0x418
	// Line 239, Address: 0x2b7a90, Func Offset: 0x420
	// Line 238, Address: 0x2b7a94, Func Offset: 0x424
	// Line 239, Address: 0x2b7a9c, Func Offset: 0x42c
	// Line 240, Address: 0x2b7aa8, Func Offset: 0x438
	// Line 244, Address: 0x2b7ab0, Func Offset: 0x440
	// Line 248, Address: 0x2b7ab8, Func Offset: 0x448
	// Line 252, Address: 0x2b7ac0, Func Offset: 0x450
	// Line 256, Address: 0x2b7ac8, Func Offset: 0x458
	// Line 260, Address: 0x2b7ad0, Func Offset: 0x460
	// Line 269, Address: 0x2b7ad8, Func Offset: 0x468
	// Line 270, Address: 0x2b7ae8, Func Offset: 0x478
	// Line 271, Address: 0x2b7af4, Func Offset: 0x484
	// Line 272, Address: 0x2b7b00, Func Offset: 0x490
	// Line 271, Address: 0x2b7b04, Func Offset: 0x494
	// Line 273, Address: 0x2b7b0c, Func Offset: 0x49c
	// Line 276, Address: 0x2b7b14, Func Offset: 0x4a4
	// Line 280, Address: 0x2b7b1c, Func Offset: 0x4ac
	// Line 281, Address: 0x2b7b30, Func Offset: 0x4c0
	// Line 282, Address: 0x2b7b34, Func Offset: 0x4c4
	// Line 281, Address: 0x2b7b38, Func Offset: 0x4c8
	// Line 282, Address: 0x2b7b40, Func Offset: 0x4d0
	// Line 284, Address: 0x2b7b58, Func Offset: 0x4e8
	// Line 305, Address: 0x2b7b60, Func Offset: 0x4f0
	// Line 307, Address: 0x2b7b68, Func Offset: 0x4f8
	// Line 308, Address: 0x2b7b84, Func Offset: 0x514
	// Line 309, Address: 0x2b7b98, Func Offset: 0x528
	// Line 308, Address: 0x2b7b9c, Func Offset: 0x52c
	// Line 310, Address: 0x2b7ba8, Func Offset: 0x538
	// Line 311, Address: 0x2b7bd0, Func Offset: 0x560
	// Line 313, Address: 0x2b7bf0, Func Offset: 0x580
	// Line 314, Address: 0x2b7c00, Func Offset: 0x590
	// Line 316, Address: 0x2b7c18, Func Offset: 0x5a8
	// Line 317, Address: 0x2b7c3c, Func Offset: 0x5cc
	// Line 319, Address: 0x2b7c50, Func Offset: 0x5e0
	// Line 317, Address: 0x2b7c54, Func Offset: 0x5e4
	// Line 319, Address: 0x2b7c5c, Func Offset: 0x5ec
	// Line 321, Address: 0x2b7c70, Func Offset: 0x600
	// Line 322, Address: 0x2b7c74, Func Offset: 0x604
	// Line 321, Address: 0x2b7c78, Func Offset: 0x608
	// Line 322, Address: 0x2b7c80, Func Offset: 0x610
	// Line 323, Address: 0x2b7c8c, Func Offset: 0x61c
	// Line 325, Address: 0x2b7c94, Func Offset: 0x624
	// Line 326, Address: 0x2b7cb8, Func Offset: 0x648
	// Line 327, Address: 0x2b7cc4, Func Offset: 0x654
	// Line 328, Address: 0x2b7cd8, Func Offset: 0x668
	// Line 327, Address: 0x2b7cdc, Func Offset: 0x66c
	// Line 328, Address: 0x2b7ce4, Func Offset: 0x674
	// Line 329, Address: 0x2b7d0c, Func Offset: 0x69c
	// Line 332, Address: 0x2b7d20, Func Offset: 0x6b0
	// Line 334, Address: 0x2b7d28, Func Offset: 0x6b8
	// Line 336, Address: 0x2b7d30, Func Offset: 0x6c0
	// Line 334, Address: 0x2b7d34, Func Offset: 0x6c4
	// Line 336, Address: 0x2b7d3c, Func Offset: 0x6cc
	// Line 337, Address: 0x2b7d58, Func Offset: 0x6e8
	// Line 339, Address: 0x2b7d64, Func Offset: 0x6f4
	// Line 337, Address: 0x2b7d6c, Func Offset: 0x6fc
	// Line 338, Address: 0x2b7d7c, Func Offset: 0x70c
	// Line 339, Address: 0x2b7d8c, Func Offset: 0x71c
	// Line 341, Address: 0x2b7d94, Func Offset: 0x724
	// Line 342, Address: 0x2b7db4, Func Offset: 0x744
	// Line 344, Address: 0x2b7dc0, Func Offset: 0x750
	// Line 342, Address: 0x2b7dc8, Func Offset: 0x758
	// Line 343, Address: 0x2b7dd8, Func Offset: 0x768
	// Line 344, Address: 0x2b7de8, Func Offset: 0x778
	// Line 346, Address: 0x2b7df0, Func Offset: 0x780
	// Line 347, Address: 0x2b7e28, Func Offset: 0x7b8
	// Line 348, Address: 0x2b7e58, Func Offset: 0x7e8
	// Line 349, Address: 0x2b7e78, Func Offset: 0x808
	// Line 351, Address: 0x2b7e88, Func Offset: 0x818
	// Line 349, Address: 0x2b7e94, Func Offset: 0x824
	// Line 351, Address: 0x2b7e98, Func Offset: 0x828
	// Line 349, Address: 0x2b7e9c, Func Offset: 0x82c
	// Line 351, Address: 0x2b7eac, Func Offset: 0x83c
	// Line 349, Address: 0x2b7eb4, Func Offset: 0x844
	// Line 350, Address: 0x2b7eb8, Func Offset: 0x848
	// Line 351, Address: 0x2b7ed0, Func Offset: 0x860
	// Line 353, Address: 0x2b7ed8, Func Offset: 0x868
	// Line 354, Address: 0x2b7ef8, Func Offset: 0x888
	// Line 357, Address: 0x2b7f00, Func Offset: 0x890
	// Line 358, Address: 0x2b7f14, Func Offset: 0x8a4
	// Line 359, Address: 0x2b7f1c, Func Offset: 0x8ac
	// Line 358, Address: 0x2b7f20, Func Offset: 0x8b0
	// Line 359, Address: 0x2b7f28, Func Offset: 0x8b8
	// Line 360, Address: 0x2b7f30, Func Offset: 0x8c0
	// Line 359, Address: 0x2b7f34, Func Offset: 0x8c4
	// Line 360, Address: 0x2b7f3c, Func Offset: 0x8cc
	// Line 361, Address: 0x2b7f50, Func Offset: 0x8e0
	// Line 362, Address: 0x2b7f54, Func Offset: 0x8e4
	// Line 363, Address: 0x2b7f64, Func Offset: 0x8f4
	// Line 362, Address: 0x2b7f68, Func Offset: 0x8f8
	// Line 363, Address: 0x2b7f70, Func Offset: 0x900
	// Line 364, Address: 0x2b7f8c, Func Offset: 0x91c
	// Line 365, Address: 0x2b7fac, Func Offset: 0x93c
	// Line 367, Address: 0x2b7fc8, Func Offset: 0x958
	// Line 370, Address: 0x2b7fd0, Func Offset: 0x960
	// Line 371, Address: 0x2b7fe4, Func Offset: 0x974
	// Line 372, Address: 0x2b7ffc, Func Offset: 0x98c
	// Line 373, Address: 0x2b8008, Func Offset: 0x998
	// Line 377, Address: 0x2b8010, Func Offset: 0x9a0
	// Line 373, Address: 0x2b8014, Func Offset: 0x9a4
	// Line 374, Address: 0x2b8020, Func Offset: 0x9b0
	// Line 375, Address: 0x2b8034, Func Offset: 0x9c4
	// Line 376, Address: 0x2b8048, Func Offset: 0x9d8
	// Line 377, Address: 0x2b805c, Func Offset: 0x9ec
	// Line 379, Address: 0x2b8070, Func Offset: 0xa00
	// Line 380, Address: 0x2b8090, Func Offset: 0xa20
	// Line 382, Address: 0x2b80a0, Func Offset: 0xa30
	// Line 381, Address: 0x2b80ac, Func Offset: 0xa3c
	// Line 380, Address: 0x2b80b8, Func Offset: 0xa48
	// Line 381, Address: 0x2b80bc, Func Offset: 0xa4c
	// Line 382, Address: 0x2b80c0, Func Offset: 0xa50
	// Line 384, Address: 0x2b80d4, Func Offset: 0xa64
	// Line 385, Address: 0x2b80f4, Func Offset: 0xa84
	// Line 388, Address: 0x2b80fc, Func Offset: 0xa8c
	// Line 389, Address: 0x2b811c, Func Offset: 0xaac
	// Line 391, Address: 0x2b813c, Func Offset: 0xacc
	// Line 392, Address: 0x2b8150, Func Offset: 0xae0
	// Line 393, Address: 0x2b8158, Func Offset: 0xae8
	// Line 395, Address: 0x2b815c, Func Offset: 0xaec
	// Func End, Address: 0x2b8188, Func Offset: 0xb18
	scePrintf("bhControlMessage - UNIMPLEMENTED!\n");
}

// 100% matching! 
void bhDispFont(NJS_POINT2* pos, int code, int color, float pri)
{
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4];   
    NJS_COLOR col[4];  
    NJS_COLOR uv[4];  
    
    njTextureFilterMode(0);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njSetTexture(&sys->ef_tlist);
    
    njSetTextureNum(code / 324);
    
    p2c.p = p;
    
    p2c.col = col;
    
    p2c.tex = uv;
    
    p2c.num = 1;
    
    p[0].x = pos->x;
    p[0].y = pos->y;
    
    p[1].x = pos->x + (28.0f * FontScaleX);
    p[1].y = pos->y;
    
    p[2].x = pos->x + (28.0f * FontScaleX);
    p[2].y = pos->y + (28.0f * FontScaleY);
    
    p[3].x = pos->x;
    p[3].y = pos->y + (28.0f * FontScaleY);
    
    switch (color) 
    {                              
    case 1:
        col[0].color = 0xFF20E0FF;
        col[1].color = 0xFF20E0FF;
        col[2].color = 0xFF20E0FF;
        col[3].color = 0xFF20E0FF;
        break;
    case 2:
        col[0].color = 0xFFFF2020;
        col[1].color = 0xFFFF2020;
        col[2].color = 0xFFFF2020;
        col[3].color = 0xFFFF2020;
        break;
    case 3:
        col[0].color = 0xFF20FF20;
        col[1].color = 0xFF20FF20;
        col[2].color = 0xFF20FF20;
        col[3].color = 0xFF20FF20;
        break;
    case 4:
        col[0].color = 0xFF606060;
        col[1].color = 0xFF606060;
        col[2].color = 0xFF606060;
        col[3].color = 0xFF606060;
        break;
    default:
        col[0].color = 0xFFFFFFFF;
        col[1].color = 0xFFFFFFFF;
        col[2].color = 0xFFFFFFFF;
        col[3].color = 0xFFFFFFFF;
        break;
    }

    code %= 324;
    
    uv[0].tex.u = (code % 18) * 14;
    uv[0].tex.v = (code / 18) * 14;
    
    uv[1].tex.u = uv[0].tex.u + 14;
    uv[1].tex.v = uv[0].tex.v;
    
    uv[2].tex.u = uv[0].tex.u + 14;
    uv[2].tex.v = uv[0].tex.v + 14;
    
    uv[3].tex.u = uv[0].tex.u; 
    uv[3].tex.v = uv[0].tex.v + 14;
    
    njDrawPolygon2DM(&p2c, 4, pri, 0x80000060);
}

// 
// Start address: 0x2b8430
void bhDispFontEx(NJS_POINT2* pos, int code, unsigned int argb, float pri)
{
	//_anon23 uv[4];
	//_anon23 col[4];
	//_anon2 p[4];
	//_anon39 p2c;
	// Line 488, Address: 0x2b8430, Func Offset: 0
	// Line 496, Address: 0x2b8458, Func Offset: 0x28
	// Line 497, Address: 0x2b8460, Func Offset: 0x30
	// Line 498, Address: 0x2b846c, Func Offset: 0x3c
	// Line 499, Address: 0x2b8478, Func Offset: 0x48
	// Line 500, Address: 0x2b8490, Func Offset: 0x60
	// Line 501, Address: 0x2b84b4, Func Offset: 0x84
	// Line 527, Address: 0x2b84b8, Func Offset: 0x88
	// Line 501, Address: 0x2b84bc, Func Offset: 0x8c
	// Line 502, Address: 0x2b84c0, Func Offset: 0x90
	// Line 503, Address: 0x2b84c8, Func Offset: 0x98
	// Line 504, Address: 0x2b84d0, Func Offset: 0xa0
	// Line 507, Address: 0x2b84d8, Func Offset: 0xa8
	// Line 517, Address: 0x2b84e4, Func Offset: 0xb4
	// Line 507, Address: 0x2b84e8, Func Offset: 0xb8
	// Line 517, Address: 0x2b84ec, Func Offset: 0xbc
	// Line 505, Address: 0x2b84f0, Func Offset: 0xc0
	// Line 527, Address: 0x2b84f4, Func Offset: 0xc4
	// Line 518, Address: 0x2b84f8, Func Offset: 0xc8
	// Line 510, Address: 0x2b84fc, Func Offset: 0xcc
	// Line 507, Address: 0x2b8504, Func Offset: 0xd4
	// Line 505, Address: 0x2b8508, Func Offset: 0xd8
	// Line 527, Address: 0x2b850c, Func Offset: 0xdc
	// Line 510, Address: 0x2b8514, Func Offset: 0xe4
	// Line 527, Address: 0x2b8518, Func Offset: 0xe8
	// Line 506, Address: 0x2b851c, Func Offset: 0xec
	// Line 507, Address: 0x2b8524, Func Offset: 0xf4
	// Line 508, Address: 0x2b8530, Func Offset: 0x100
	// Line 517, Address: 0x2b8534, Func Offset: 0x104
	// Line 519, Address: 0x2b8538, Func Offset: 0x108
	// Line 518, Address: 0x2b8540, Func Offset: 0x110
	// Line 508, Address: 0x2b8544, Func Offset: 0x114
	// Line 509, Address: 0x2b8548, Func Offset: 0x118
	// Line 519, Address: 0x2b854c, Func Offset: 0x11c
	// Line 509, Address: 0x2b8550, Func Offset: 0x120
	// Line 510, Address: 0x2b8558, Func Offset: 0x128
	// Line 511, Address: 0x2b8564, Func Offset: 0x134
	// Line 512, Address: 0x2b856c, Func Offset: 0x13c
	// Line 518, Address: 0x2b8570, Func Offset: 0x140
	// Line 512, Address: 0x2b8574, Func Offset: 0x144
	// Line 513, Address: 0x2b8578, Func Offset: 0x148
	// Line 518, Address: 0x2b857c, Func Offset: 0x14c
	// Line 519, Address: 0x2b8588, Func Offset: 0x158
	// Line 518, Address: 0x2b858c, Func Offset: 0x15c
	// Line 514, Address: 0x2b8590, Func Offset: 0x160
	// Line 515, Address: 0x2b8594, Func Offset: 0x164
	// Line 519, Address: 0x2b8598, Func Offset: 0x168
	// Line 512, Address: 0x2b85a0, Func Offset: 0x170
	// Line 519, Address: 0x2b85a4, Func Offset: 0x174
	// Line 516, Address: 0x2b85b4, Func Offset: 0x184
	// Line 519, Address: 0x2b85b8, Func Offset: 0x188
	// Line 520, Address: 0x2b85c0, Func Offset: 0x190
	// Line 521, Address: 0x2b85cc, Func Offset: 0x19c
	// Line 522, Address: 0x2b85d4, Func Offset: 0x1a4
	// Line 523, Address: 0x2b85e0, Func Offset: 0x1b0
	// Line 524, Address: 0x2b85ec, Func Offset: 0x1bc
	// Line 525, Address: 0x2b85f4, Func Offset: 0x1c4
	// Line 527, Address: 0x2b85fc, Func Offset: 0x1cc
	// Line 529, Address: 0x2b8604, Func Offset: 0x1d4
	// Func End, Address: 0x2b8620, Func Offset: 0x1f0
	scePrintf("bhDispFontEx - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2b8620
int bhDispItemName(_anon2* pos, int id, int color, int count, float pri)
{
	int num;
	int cflg;
	unsigned short cd;
	unsigned short* dp;
	// Line 543, Address: 0x2b8620, Func Offset: 0
	// Line 547, Address: 0x2b8648, Func Offset: 0x28
	// Line 549, Address: 0x2b8654, Func Offset: 0x34
	// Line 547, Address: 0x2b8664, Func Offset: 0x44
	// Line 546, Address: 0x2b8674, Func Offset: 0x54
	// Line 547, Address: 0x2b867c, Func Offset: 0x5c
	// Line 551, Address: 0x2b8688, Func Offset: 0x68
	// Line 552, Address: 0x2b868c, Func Offset: 0x6c
	// Line 559, Address: 0x2b869c, Func Offset: 0x7c
	// Line 560, Address: 0x2b86a8, Func Offset: 0x88
	// Line 561, Address: 0x2b86b8, Func Offset: 0x98
	// Line 562, Address: 0x2b86d4, Func Offset: 0xb4
	// Line 563, Address: 0x2b86dc, Func Offset: 0xbc
	// Line 567, Address: 0x2b86f8, Func Offset: 0xd8
	// Line 568, Address: 0x2b8700, Func Offset: 0xe0
	// Line 569, Address: 0x2b8704, Func Offset: 0xe4
	// Line 572, Address: 0x2b8714, Func Offset: 0xf4
	// Line 573, Address: 0x2b8718, Func Offset: 0xf8
	// Func End, Address: 0x2b8744, Func Offset: 0x124
}*/

// 100% matching! 
int bhDispMessage(float px, float py, float pri, int mes_typ, int mes_idx, int color, int count)
{
    NJS_POINT2 pos;      
    unsigned short* dp;  
    unsigned short cd;   
    int cflg;            
    int num;             
    unsigned int* mes_dp;
    float stx;          
    float sty;          

    switch (mes_typ) 
    {                           
    case 0:
        mes_dp = rom->mesp;
        
        dp = (unsigned short*)((char*)mes_dp + rom->mesp[mes_idx + 1]);
        break;
    case 1:
        mes_dp = sys->mes_sp;
        
        dp = (unsigned short*)((char*)mes_dp + sys->mes_sp[mes_idx + 1]);
        break;
    default:
        dp = sys->mes_tp;
        break;
    }
    
    pos.x = px;
    pos.y = py;
    
    num = 0;
    
    if (count == 0) 
    {
        cflg = 0;
    }
    else 
    {
        cflg = 1;
    }
    
    while (TRUE) 
    {
        cd = *dp++;
        
        switch (cd)
        {
        case 65280:
            pos.x = px;
            pos.y += 30.0f * FontScaleCR;
            continue;
        case 65281:
            pos.x += 14.0f * FontScaleX;
            continue;
        case 65282:
            dp++;
            continue;
        case 65283:
            dp++;
            continue;
        case 65284:
            pos.x += 28.0f * FontScaleX;
            continue;
        case 65024:
        case 65025:
        case 65026:
        case 65027:
        case 65028:
        case 65029:
        case 65030:
        case 65031:
        case 65032:
        case 65033:
        case 65034:
        case 65035:
        case 65036:
        case 65037:
        case 65038:
        case 65039:   
            continue;
        }
        
        if (cd == 65535) 
        {
            break;
        }
        
        bhDispFont(&pos, cd, color, pri);
        
        pos.x += FontScaleX * bhGetFontSize(cd);
        
        num++;
        
        if ((cflg != 0) && (--count <= 0)) 
        {
            return 0;
        }
    }
    
    return num;
}

// 
// Start address: 0x2b89e0
int bhDispMessageEx(float px, float py, float pri, int mes_typ, int mes_idx, unsigned int argb, int count)
{
	float sty;
	float stx;
	unsigned int* mes_dp;
	int num;
	int cflg;
	unsigned short cd;
	unsigned short* dp;
	//_anon2 pos;
	// Line 688, Address: 0x2b89e0, Func Offset: 0
	// Line 694, Address: 0x2b8a0c, Func Offset: 0x2c
	// Line 696, Address: 0x2b8a34, Func Offset: 0x54
	// Line 697, Address: 0x2b8a38, Func Offset: 0x58
	// Line 696, Address: 0x2b8a3c, Func Offset: 0x5c
	// Line 697, Address: 0x2b8a40, Func Offset: 0x60
	// Line 698, Address: 0x2b8a48, Func Offset: 0x68
	// Line 700, Address: 0x2b8a50, Func Offset: 0x70
	// Line 701, Address: 0x2b8a58, Func Offset: 0x78
	// Line 700, Address: 0x2b8a5c, Func Offset: 0x7c
	// Line 701, Address: 0x2b8a68, Func Offset: 0x88
	// Line 702, Address: 0x2b8a70, Func Offset: 0x90
	// Line 704, Address: 0x2b8a78, Func Offset: 0x98
	// Line 711, Address: 0x2b8a8c, Func Offset: 0xac
	// Line 708, Address: 0x2b8a90, Func Offset: 0xb0
	// Line 707, Address: 0x2b8a94, Func Offset: 0xb4
	// Line 708, Address: 0x2b8a98, Func Offset: 0xb8
	// Line 709, Address: 0x2b8a9c, Func Offset: 0xbc
	// Line 713, Address: 0x2b8aa4, Func Offset: 0xc4
	// Line 715, Address: 0x2b8aa8, Func Offset: 0xc8
	// Line 718, Address: 0x2b8b74, Func Offset: 0x194
	// Line 717, Address: 0x2b8b7c, Func Offset: 0x19c
	// Line 718, Address: 0x2b8b80, Func Offset: 0x1a0
	// Line 719, Address: 0x2b8b90, Func Offset: 0x1b0
	// Line 722, Address: 0x2b8b98, Func Offset: 0x1b8
	// Line 723, Address: 0x2b8bb0, Func Offset: 0x1d0
	// Line 724, Address: 0x2b8bb8, Func Offset: 0x1d8
	// Line 725, Address: 0x2b8bbc, Func Offset: 0x1dc
	// Line 731, Address: 0x2b8bcc, Func Offset: 0x1ec
	// Line 735, Address: 0x2b8bd4, Func Offset: 0x1f4
	// Line 738, Address: 0x2b8bdc, Func Offset: 0x1fc
	// Line 739, Address: 0x2b8bf4, Func Offset: 0x214
	// Line 761, Address: 0x2b8bfc, Func Offset: 0x21c
	// Line 762, Address: 0x2b8c04, Func Offset: 0x224
	// Line 763, Address: 0x2b8c14, Func Offset: 0x234
	// Line 764, Address: 0x2b8c28, Func Offset: 0x248
	// Line 763, Address: 0x2b8c2c, Func Offset: 0x24c
	// Line 765, Address: 0x2b8c34, Func Offset: 0x254
	// Line 766, Address: 0x2b8c3c, Func Offset: 0x25c
	// Line 767, Address: 0x2b8c40, Func Offset: 0x260
	// Line 771, Address: 0x2b8c48, Func Offset: 0x268
	// Func End, Address: 0x2b8c78, Func Offset: 0x298
	scePrintf("bhDispMessageEx - UNIMPLEMENTED!\n");
}

// 99.79% matching
void bhDispTime(NJS_POINT2 *pos, unsigned int flg, int time, int color, float pri) 
{ 
    static int ntb[10] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
    NJS_POINT2 dps;
    int hour;
    int min;
    int sec;
    int msc;
    unsigned short cd;

    dps.x = pos->x; 
    dps.y = pos->y; 
    
    hour = time / 216000; 
    
    if (sys->gm_mode == 3) 
    { 
        if (hour >= 1) 
        {
            hour = 0; 
            
            min = 59; 
            sec = 59;
            msc = 99; 
        } 
        else
        {
            hour = 0;
            
            min = (time / 3600) % 60; 
            sec = (time / 60) % 60; 
            msc = ((time % 60) * 10) / 6; 
        }
    } 
    else 
    {
        if (hour > 99) 
        {
            hour = 99; 
            
            min = 59; 
            sec = 59;
        } 
        else 
        { 
            min = (time / 3600) % 60; 
            sec = (time / 60) % 60; 
        }
        
        msc = ((time % 60) * 10) / 6; 
    }

    if ((flg & 0x8)) 
    { 
        bhDispFont(&dps, ntb[hour / 10], color, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        bhDispFont(&dps, ntb[hour % 10], color, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        bhDispFont(&dps, 26, color, pri); 
        dps.x += FontScaleX * bhGetFontSize(26);       
    }
    
    if ((flg & 0x4)) 
    { 
        if (((!(flg & 0x8)) && (min / 10)) || ((flg & 0x8))) 
        { 
            bhDispFont(&dps, ntb[min / 10], color, pri);
        }
        
        dps.x += FontScaleX * 20.0f;
        
        bhDispFont(&dps, ntb[min % 10], color, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        if ((flg & 0x8)) 
        {
            cd = 26;
        }
        else 
        {
            cd = 7;
        }
        
        bhDispFont(&dps, cd, color, pri); 
        dps.x += FontScaleX * bhGetFontSize(cd); 
    }
    
    if ((flg & 0x2)) 
    { 
        bhDispFont(&dps, ntb[sec / 10], color, pri);
        dps.x += FontScaleX * 20.0f;
        
        bhDispFont(&dps, ntb[sec % 10], color, pri);
        dps.x += FontScaleX * 20.0f;
        
        if (!(flg & 0x8)) 
        {
            bhDispFont(&dps, 2, color, pri);
            dps.x += FontScaleX * bhGetFontSize(2);
        }
    }
    
    if ((flg & 0x1))
    { 
        bhDispFont(&dps, ntb[msc / 10], color, pri);
        dps.x += FontScaleX * 20.0f;
        
        bhDispFont(&dps, ntb[msc % 10], color, pri);
    }
}

// 99.79% matching
void bhDispTimeEx(NJS_POINT2* pos, unsigned int flg, int time, unsigned int argb, float pri)
{ 
    static int ntb[10] = { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
    NJS_POINT2 dps;
    int hour;
    int min;
    int sec;
    int msc;
    unsigned short cd;

    dps.x = pos->x; 
    dps.y = pos->y; 
    
    hour = time / 216000; 
    
    if (sys->gm_mode == 3) 
    { 
        if (hour >= 1) 
        {
            hour = 0; 
            
            min = 59; 
            sec = 59;
            msc = 99; 
        } 
        else
        {
            hour = 0;
            
            min = (time / 3600) % 60; 
            sec = (time / 60) % 60; 
            msc = ((time % 60) * 10) / 6; 
        }
    } 
    else 
    {
        if (hour > 99) 
        {
            hour = 99; 
            
            min = 59; 
            sec = 59;
        } 
        else 
        { 
            min = (time / 3600) % 60; 
            sec = (time / 60) % 60; 
        }
        
        msc = ((time % 60) * 10) / 6; 
    }

    if ((flg & 0x8)) 
    { 
        bhDispFontEx(&dps, ntb[hour / 10], argb, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        bhDispFontEx(&dps, ntb[hour % 10], argb, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        bhDispFontEx(&dps, 26, argb, pri); 
        dps.x += FontScaleX * bhGetFontSize(26);       
    }
    
    if ((flg & 0x4)) 
    { 
        if (((!(flg & 0x8)) && (min / 10)) || ((flg & 0x8))) 
        { 
            bhDispFontEx(&dps, ntb[min / 10], argb, pri);
        }
        
        dps.x += FontScaleX * 20.0f;
        
        bhDispFontEx(&dps, ntb[min % 10], argb, pri); 
        dps.x += FontScaleX * 20.0f; 
        
        if ((flg & 0x8)) 
        {
            cd = 26;
        }
        else 
        {
            cd = 7;
        }
        
        bhDispFontEx(&dps, cd, argb, pri); 
        dps.x += FontScaleX * bhGetFontSize(cd); 
    }
    
    if ((flg & 0x2)) 
    { 
        bhDispFontEx(&dps, ntb[sec / 10], argb, pri);
        dps.x += FontScaleX * 20.0f;
        
        bhDispFontEx(&dps, ntb[sec % 10], argb, pri);
        dps.x += FontScaleX * 20.0f;
        
        if (!(flg & 0x8)) 
        {
            bhDispFontEx(&dps, 2, argb, pri);
            dps.x += FontScaleX * bhGetFontSize(2);
        }
    }
    
    if ((flg & 0x1))
    { 
        bhDispFontEx(&dps, ntb[msc / 10], argb, pri);
        dps.x += FontScaleX * 20.0f;
        
        bhDispFontEx(&dps, ntb[msc % 10], argb, pri);
    }
}

// 100% matching!
float bhGetFontSize(unsigned short code)
{
    if (code >= 108) 
    {
        return 0;
    }
    
    return FontSz[code];
}

// 100% matching!
float bhMesLen(unsigned short* dp)
{
    unsigned short cd; 
    float len; 
    
    len = 0;

    while (TRUE) 
    {
        cd = *dp++;

        switch (cd) 
        {
        case 65280:
            continue;
        case 65281:
            len += FontScaleX * 14.0f;
            continue;
        case 65282:
            dp++;
            continue;
        case 65283:
            dp++;
            continue;
        case 65284:
        case 65024:
        case 65025:
        case 65026:
        case 65027:
        case 65028:
        case 65029:
        case 65030:
        case 65031:
        case 65032:
        case 65033:
        case 65034:
        case 65035:
        case 65036:
        case 65037:
        case 65038:
        case 65039:  
            continue;
        }

        if (cd == 65535) 
        {
            break;
        }
        
        len += FontScaleX * bhGetFontSize(cd);
    }

    return len;
}

// 100% matching! 
void bhFontScaleSet(float ScaleX, float ScaleY, float ScaleCR) 
{
    FontScaleX = ScaleX; 
    FontScaleY = ScaleY; 
    
    FontScaleCR = ScaleCR; 
}
