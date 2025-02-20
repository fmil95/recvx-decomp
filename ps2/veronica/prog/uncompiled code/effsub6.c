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
typedef struct BH_PWORK;
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

typedef void(*type_43)(_anon0*);
typedef void(*type_85)(_anon0*);
typedef void(*type_87)(void*);

typedef float type_0[16];
typedef unsigned int type_1[4];
typedef _anon0* type_2[512];
typedef _anon0* type_3[32];
typedef _anon2* type_4[16];
typedef _anon0* type_5[32];
typedef _anon0* type_6[512];
typedef _anon2* type_7[16][16];
typedef _anon2* type_8[16][16][100];
typedef char type_9[8];
typedef _anon0* type_10[32];
typedef _anon0* type_11[512];
typedef _anon2* type_12[1300];
typedef char type_13[32];
typedef float type_14[32];
typedef _anon0* type_15[512];
typedef _anon2* type_16[200];
typedef short type_17[32];
typedef _anon1 type_18[1];
typedef _anon0* type_19[128];
typedef unsigned int type_20[1];
typedef _anon10 type_21[256];
typedef _anon2* type_22[8];
typedef int* type_23[16];
typedef _anon0* type_24[128];
typedef _anon45 type_25[16];
typedef npobj* type_26[16];
typedef _anon0* type_27[128];
typedef int type_28[4];
typedef _anon2* type_29[16];
typedef unsigned int type_30[4];
typedef float type_31[4];
typedef _anon14 type_32[16];
typedef _anon0* type_33[512];
typedef float type_34[4];
typedef char type_35[256];
typedef float type_36[4];
typedef float type_37[4];
typedef float type_38[4];
typedef float type_39[4];
typedef _anon7* type_40[128];
typedef BH_PWORK type_41[0];
typedef float type_42[3];
typedef unsigned char type_44[64];
typedef float type_45[3][20];
typedef _anon0 type_46[0];
typedef float type_47[3];
typedef float type_48[3][20];
typedef float type_49[3];
typedef float type_50[3][20];
typedef char type_51[8];
typedef float type_52[3];
typedef float type_53[3][20];
typedef void* type_54[2];
typedef _anon2* type_55[256];
typedef int type_56[4];
typedef unsigned char* type_57[256];
typedef unsigned int type_58[2];
typedef short type_59[256];
typedef _anon30 type_60[4];
typedef float type_61[3];
typedef short type_62[256];
typedef int type_63[3];
typedef int type_64[8];
typedef float type_65[3];
typedef _anon2* type_66[256];
typedef _anon12 type_67[256];
typedef _anon1 type_68[450];
typedef _anon32 type_69[16];
typedef short type_70[256];
typedef char type_71[3];
typedef int type_72[64];
typedef _anon14 type_73[450];
typedef unsigned int type_74[16];
typedef _anon33 type_75[2];
typedef char type_76[4];
typedef unsigned int type_77[8];
typedef _anon36 type_78[4];
typedef _anon3 type_79[4];
typedef int type_80[450];
typedef unsigned int type_81[8];
typedef unsigned char type_82[450];
typedef float type_83[128];
typedef char type_84[16];
typedef char type_86[4];
typedef unsigned int type_88[32];
typedef _anon23 type_89[2];
typedef _anon33 type_90[48];
typedef _anon33 type_91[48];
typedef unsigned char type_92[256];
typedef unsigned int type_93[16];
typedef _anon20 type_94[64];
typedef unsigned int type_95[16];
typedef _anon20 type_96[64];
typedef unsigned int type_97[32];
typedef _anon20 type_98[64];
typedef unsigned int type_99[16];
typedef unsigned int type_100[3];
typedef BH_PWORK* type_101[16];
typedef unsigned int type_102[8];
typedef unsigned int type_103[1];
typedef unsigned int type_104[384];
typedef _anon39 type_105[10];
typedef unsigned int type_106[2];
typedef unsigned char type_107[2];
typedef unsigned int type_108[4];
typedef int* type_109[16];
typedef char type_110[32];
typedef npobj* type_111[16];
typedef char type_112[64];
typedef _anon2* type_113[16];
typedef char type_114[4];
typedef _anon14 type_115[16];
typedef short type_116[4];
typedef unsigned char type_117[4];
typedef _anon34 type_118[16];
typedef unsigned int type_119[8];
typedef unsigned int type_120[3];
typedef unsigned int type_121[32];
typedef unsigned int type_122[4];
typedef _anon33 type_123[32];
typedef _anon0* type_124[512];
typedef _anon0* type_125[128];
typedef _anon0* type_126[512];
typedef unsigned char type_127[64];
typedef _anon0* type_128[512];

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
	_anon2* txp[16];
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
	_anon43 cspr;
	int pn;
	_anon36* pvp;
	_anon3* tvp;
	_anon36 pv[4];
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
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon2
{
	_anon1* textures;
	unsigned int nbTexture;
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
	_anon33 ply_pos;
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
	_anon12 txbp[256];
	unsigned char* ef_psp;
	_anon1 ef_tex[450];
	_anon2 ef_tlist;
	_anon37 ef;
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
	_anon1 ren_tex[1];
	_anon2 ren_tlist;
	_anon10 rpb[256];
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
	_anon40 mr_pl;
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
	_anon30 lg_ptb[4];
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
	_anon20* pl_htp;
	int costume;
	_anon33 hd_pos;
	_anon33 apos;
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
	_anon2* sb_tlist;
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
	_anon33 ufo_pos;
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
	_anon33 ghtp[32];
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

struct _anon6
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

struct _anon7
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon24* md2P;
	unsigned short* atrP;
};

struct _anon8
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon45 keyf[16];
};

struct _anon9
{
	_anon13* cutp;
	_anon17* lgtp;
	_anon18* enep;
	_anon18* objp;
	_anon18* itmp;
	_anon6* effp;
	_anon20* walp;
	_anon20* etcp;
	_anon20* flrp;
	_anon4* posp;
	_anon20* rutp;
	unsigned char* ruttp;
	_anon26* evtp;
	_anon8* evcp;
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

struct _anon10
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon11
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

struct _anon12
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
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
	_anon23 cam[2];
	unsigned char exd[256];
};

struct _anon14
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon2* texP;
	_anon28* owP;
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
	_anon41* info;
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
	_anon29* light;
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
	unsigned int flg;
	unsigned int col;
	float sx;
	float sy;
	int num;
	_anon2* txp;
	int tex_id;
	_anon33 pos[48];
	_anon33 vec[48];
};

struct _anon22
{
	void* texaddr;
	_anon11 texsurface;
};

struct _anon23
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

struct _anon24
{
	void* p[2];
};

struct _anon25
{
	short jnt_a;
	short jnt_b;
	int cap_r;
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
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon29
{
	float mtrx[16];
	_anon33 pnt;
	_anon33 vctr;
	int stat;
	int reserve;
	_anon35 ltcal;
	_anon42 attr;
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
	_anon44 watr;
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

struct _anon30
{
	_anon33 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon31
{
	int* vlist;
	short* plist;
	_anon33 center;
	float r;
};

struct _anon32
{
	float x;
	float y;
};

struct _anon33
{
	float x;
	float y;
	float z;
};

struct _anon34
{
	_anon33 c1;
	_anon33 c2;
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
	_anon33 lpnt;
	_anon33 lvctr;
	_anon33 lmvctr;
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
	float u;
	float v;
	float xs;
	float ys;
};

struct _anon40
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon41
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

struct _anon42
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

struct _anon43
{
	_anon33 c;
	float r;
};

struct _anon44
{
	_anon33 c1;
	_anon33 c2;
	float r;
};

struct _anon45
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

_anon33 eye_ofs[2];
BH_PWORK ene[0];
_anon9* rom;
_anon5* sys;
_anon0 eff[0];
void(*bhEff_Draw3DSprite)(_anon0*);
_anon38 cam;
void(*bhEff143_sub)(_anon0*);

void bhEff085(_anon0* op);
void bhEff145(_anon0* op);
void bhEff146_Init(_anon0* op);
void bhEff_Sub146(_anon0* op);
void bhEff147(_anon0* op);
void bhEff148(_anon0* op);
void bhEff149(_anon0* op);
void bhEff144(_anon0* op);
void bhEff143_sub(_anon0* op);
void bhEff143(_anon0* op);

// 
// Start address: 0x2e80b0
void bhEff085(_anon0* op)
{
	_anon6* effp;
	_anon1* tnp2;
	_anon1* tnp;
	// Line 86, Address: 0x2e80b0, Func Offset: 0
	// Line 88, Address: 0x2e80d0, Func Offset: 0x20
	// Line 89, Address: 0x2e80dc, Func Offset: 0x2c
	// Line 90, Address: 0x2e80e0, Func Offset: 0x30
	// Line 91, Address: 0x2e80e4, Func Offset: 0x34
	// Line 92, Address: 0x2e80e8, Func Offset: 0x38
	// Line 94, Address: 0x2e80ec, Func Offset: 0x3c
	// Line 97, Address: 0x2e80f4, Func Offset: 0x44
	// Line 99, Address: 0x2e8100, Func Offset: 0x50
	// Line 101, Address: 0x2e810c, Func Offset: 0x5c
	// Line 103, Address: 0x2e8110, Func Offset: 0x60
	// Line 101, Address: 0x2e8114, Func Offset: 0x64
	// Line 99, Address: 0x2e811c, Func Offset: 0x6c
	// Line 101, Address: 0x2e812c, Func Offset: 0x7c
	// Line 99, Address: 0x2e8130, Func Offset: 0x80
	// Line 101, Address: 0x2e813c, Func Offset: 0x8c
	// Line 99, Address: 0x2e8144, Func Offset: 0x94
	// Line 101, Address: 0x2e8148, Func Offset: 0x98
	// Line 99, Address: 0x2e8150, Func Offset: 0xa0
	// Line 103, Address: 0x2e8158, Func Offset: 0xa8
	// Line 99, Address: 0x2e815c, Func Offset: 0xac
	// Line 103, Address: 0x2e8160, Func Offset: 0xb0
	// Line 105, Address: 0x2e8168, Func Offset: 0xb8
	// Line 107, Address: 0x2e8198, Func Offset: 0xe8
	// Line 108, Address: 0x2e81a0, Func Offset: 0xf0
	// Line 111, Address: 0x2e81a8, Func Offset: 0xf8
	// Line 114, Address: 0x2e81b8, Func Offset: 0x108
	// Line 116, Address: 0x2e81d4, Func Offset: 0x124
	// Line 119, Address: 0x2e81e0, Func Offset: 0x130
	// Line 121, Address: 0x2e8218, Func Offset: 0x168
	// Line 128, Address: 0x2e821c, Func Offset: 0x16c
	// Func End, Address: 0x2e8224, Func Offset: 0x174
}

// 
// Start address: 0x2e8230
void bhEff145(_anon0* op)
{
	// Line 138, Address: 0x2e8230, Func Offset: 0
	// Line 157, Address: 0x2e8238, Func Offset: 0x8
	// Line 159, Address: 0x2e8258, Func Offset: 0x28
	// Line 160, Address: 0x2e825c, Func Offset: 0x2c
	// Line 166, Address: 0x2e8260, Func Offset: 0x30
	// Line 160, Address: 0x2e8264, Func Offset: 0x34
	// Line 162, Address: 0x2e826c, Func Offset: 0x3c
	// Line 163, Address: 0x2e8270, Func Offset: 0x40
	// Line 164, Address: 0x2e8274, Func Offset: 0x44
	// Line 165, Address: 0x2e8278, Func Offset: 0x48
	// Line 167, Address: 0x2e827c, Func Offset: 0x4c
	// Line 170, Address: 0x2e8284, Func Offset: 0x54
	// Line 171, Address: 0x2e8294, Func Offset: 0x64
	// Line 173, Address: 0x2e82b0, Func Offset: 0x80
	// Line 174, Address: 0x2e82b8, Func Offset: 0x88
	// Line 176, Address: 0x2e82c0, Func Offset: 0x90
	// Line 177, Address: 0x2e82c8, Func Offset: 0x98
	// Line 179, Address: 0x2e82d0, Func Offset: 0xa0
	// Line 183, Address: 0x2e82d8, Func Offset: 0xa8
	// Func End, Address: 0x2e82e4, Func Offset: 0xb4
}

// 
// Start address: 0x2e82f0
void bhEff146_Init(_anon0* op)
{
	int eno;
	int i;
	// Line 193, Address: 0x2e82f0, Func Offset: 0
	// Line 202, Address: 0x2e8308, Func Offset: 0x18
	// Line 210, Address: 0x2e8310, Func Offset: 0x20
	// Line 202, Address: 0x2e8314, Func Offset: 0x24
	// Line 210, Address: 0x2e8318, Func Offset: 0x28
	// Line 204, Address: 0x2e831c, Func Offset: 0x2c
	// Line 202, Address: 0x2e8320, Func Offset: 0x30
	// Line 203, Address: 0x2e832c, Func Offset: 0x3c
	// Line 204, Address: 0x2e8344, Func Offset: 0x54
	// Line 210, Address: 0x2e8358, Func Offset: 0x68
	// Line 211, Address: 0x2e836c, Func Offset: 0x7c
	// Line 212, Address: 0x2e8380, Func Offset: 0x90
	// Line 215, Address: 0x2e8394, Func Offset: 0xa4
	// Line 216, Address: 0x2e83a8, Func Offset: 0xb8
	// Line 221, Address: 0x2e83b4, Func Offset: 0xc4
	// Line 225, Address: 0x2e83e4, Func Offset: 0xf4
	// Line 227, Address: 0x2e83e8, Func Offset: 0xf8
	// Line 229, Address: 0x2e8408, Func Offset: 0x118
	// Line 230, Address: 0x2e842c, Func Offset: 0x13c
	// Line 229, Address: 0x2e8430, Func Offset: 0x140
	// Line 230, Address: 0x2e8434, Func Offset: 0x144
	// Line 232, Address: 0x2e8448, Func Offset: 0x158
	// Line 233, Address: 0x2e8490, Func Offset: 0x1a0
	// Line 234, Address: 0x2e84b8, Func Offset: 0x1c8
	// Line 235, Address: 0x2e84e0, Func Offset: 0x1f0
	// Line 236, Address: 0x2e84e4, Func Offset: 0x1f4
	// Line 237, Address: 0x2e84e8, Func Offset: 0x1f8
	// Line 238, Address: 0x2e84f0, Func Offset: 0x200
	// Line 240, Address: 0x2e84f8, Func Offset: 0x208
	// Line 241, Address: 0x2e8508, Func Offset: 0x218
	// Func End, Address: 0x2e8524, Func Offset: 0x234
}

// 
// Start address: 0x2e8530
void bhEff_Sub146(_anon0* op)
{
	// Line 255, Address: 0x2e8530, Func Offset: 0
	// Line 258, Address: 0x2e855c, Func Offset: 0x2c
	// Line 259, Address: 0x2e8568, Func Offset: 0x38
	// Line 260, Address: 0x2e8570, Func Offset: 0x40
	// Line 263, Address: 0x2e8580, Func Offset: 0x50
	// Line 264, Address: 0x2e8588, Func Offset: 0x58
	// Line 266, Address: 0x2e8590, Func Offset: 0x60
	// Line 267, Address: 0x2e8598, Func Offset: 0x68
	// Line 268, Address: 0x2e859c, Func Offset: 0x6c
	// Line 266, Address: 0x2e85a0, Func Offset: 0x70
	// Line 267, Address: 0x2e85a8, Func Offset: 0x78
	// Line 268, Address: 0x2e85ac, Func Offset: 0x7c
	// Line 271, Address: 0x2e85b0, Func Offset: 0x80
	// Line 272, Address: 0x2e85bc, Func Offset: 0x8c
	// Line 273, Address: 0x2e85c0, Func Offset: 0x90
	// Line 274, Address: 0x2e85d4, Func Offset: 0xa4
	// Line 275, Address: 0x2e85d8, Func Offset: 0xa8
	// Line 276, Address: 0x2e85e0, Func Offset: 0xb0
	// Line 279, Address: 0x2e85e8, Func Offset: 0xb8
	// Line 283, Address: 0x2e85ec, Func Offset: 0xbc
	// Line 279, Address: 0x2e85f0, Func Offset: 0xc0
	// Line 280, Address: 0x2e85f4, Func Offset: 0xc4
	// Line 281, Address: 0x2e85fc, Func Offset: 0xcc
	// Line 282, Address: 0x2e8600, Func Offset: 0xd0
	// Line 283, Address: 0x2e8604, Func Offset: 0xd4
	// Line 284, Address: 0x2e8608, Func Offset: 0xd8
	// Line 285, Address: 0x2e860c, Func Offset: 0xdc
	// Line 286, Address: 0x2e8614, Func Offset: 0xe4
	// Line 287, Address: 0x2e861c, Func Offset: 0xec
	// Line 288, Address: 0x2e8624, Func Offset: 0xf4
	// Line 290, Address: 0x2e862c, Func Offset: 0xfc
	// Line 293, Address: 0x2e8638, Func Offset: 0x108
	// Line 294, Address: 0x2e8644, Func Offset: 0x114
	// Line 296, Address: 0x2e8650, Func Offset: 0x120
	// Line 297, Address: 0x2e8658, Func Offset: 0x128
	// Line 305, Address: 0x2e8664, Func Offset: 0x134
	// Line 306, Address: 0x2e8674, Func Offset: 0x144
	// Line 308, Address: 0x2e8684, Func Offset: 0x154
	// Line 309, Address: 0x2e8688, Func Offset: 0x158
	// Line 308, Address: 0x2e8690, Func Offset: 0x160
	// Line 309, Address: 0x2e869c, Func Offset: 0x16c
	// Line 311, Address: 0x2e86b0, Func Offset: 0x180
	// Line 317, Address: 0x2e86b4, Func Offset: 0x184
	// Line 319, Address: 0x2e86c0, Func Offset: 0x190
	// Line 321, Address: 0x2e86cc, Func Offset: 0x19c
	// Line 322, Address: 0x2e86f4, Func Offset: 0x1c4
	// Line 324, Address: 0x2e8718, Func Offset: 0x1e8
	// Line 325, Address: 0x2e8720, Func Offset: 0x1f0
	// Line 326, Address: 0x2e872c, Func Offset: 0x1fc
	// Line 327, Address: 0x2e8754, Func Offset: 0x224
	// Line 331, Address: 0x2e8778, Func Offset: 0x248
	// Func End, Address: 0x2e8780, Func Offset: 0x250
}

// 
// Start address: 0x2e8780
void bhEff147(_anon0* op)
{
	// Line 342, Address: 0x2e8780, Func Offset: 0
	// Line 355, Address: 0x2e878c, Func Offset: 0xc
	// Line 359, Address: 0x2e87a0, Func Offset: 0x20
	// Line 360, Address: 0x2e87a4, Func Offset: 0x24
	// Line 361, Address: 0x2e87a8, Func Offset: 0x28
	// Line 366, Address: 0x2e87ac, Func Offset: 0x2c
	// Line 359, Address: 0x2e87b0, Func Offset: 0x30
	// Line 360, Address: 0x2e87b8, Func Offset: 0x38
	// Line 361, Address: 0x2e87bc, Func Offset: 0x3c
	// Line 362, Address: 0x2e87c0, Func Offset: 0x40
	// Line 363, Address: 0x2e87c4, Func Offset: 0x44
	// Line 364, Address: 0x2e87c8, Func Offset: 0x48
	// Line 365, Address: 0x2e87cc, Func Offset: 0x4c
	// Line 366, Address: 0x2e87d0, Func Offset: 0x50
	// Line 367, Address: 0x2e87d4, Func Offset: 0x54
	// Line 368, Address: 0x2e87d8, Func Offset: 0x58
	// Line 369, Address: 0x2e87dc, Func Offset: 0x5c
	// Line 370, Address: 0x2e87e0, Func Offset: 0x60
	// Line 371, Address: 0x2e87e4, Func Offset: 0x64
	// Line 372, Address: 0x2e87e8, Func Offset: 0x68
	// Line 373, Address: 0x2e87ec, Func Offset: 0x6c
	// Line 374, Address: 0x2e87f8, Func Offset: 0x78
	// Line 375, Address: 0x2e8800, Func Offset: 0x80
	// Line 376, Address: 0x2e8808, Func Offset: 0x88
	// Line 378, Address: 0x2e8814, Func Offset: 0x94
	// Line 379, Address: 0x2e881c, Func Offset: 0x9c
	// Line 380, Address: 0x2e8820, Func Offset: 0xa0
	// Line 378, Address: 0x2e8824, Func Offset: 0xa4
	// Line 379, Address: 0x2e882c, Func Offset: 0xac
	// Line 380, Address: 0x2e8830, Func Offset: 0xb0
	// Line 382, Address: 0x2e8834, Func Offset: 0xb4
	// Line 383, Address: 0x2e8854, Func Offset: 0xd4
	// Line 384, Address: 0x2e8868, Func Offset: 0xe8
	// Line 386, Address: 0x2e888c, Func Offset: 0x10c
	// Func End, Address: 0x2e889c, Func Offset: 0x11c
}

// 
// Start address: 0x2e88a0
void bhEff148(_anon0* op)
{
	_anon33 pos;
	// Line 396, Address: 0x2e88a0, Func Offset: 0
	// Line 416, Address: 0x2e88ac, Func Offset: 0xc
	// Line 417, Address: 0x2e88b8, Func Offset: 0x18
	// Line 418, Address: 0x2e88bc, Func Offset: 0x1c
	// Line 420, Address: 0x2e88c0, Func Offset: 0x20
	// Line 425, Address: 0x2e88c4, Func Offset: 0x24
	// Line 431, Address: 0x2e88c8, Func Offset: 0x28
	// Line 418, Address: 0x2e88cc, Func Offset: 0x2c
	// Line 420, Address: 0x2e88d4, Func Offset: 0x34
	// Line 421, Address: 0x2e88d8, Func Offset: 0x38
	// Line 422, Address: 0x2e88dc, Func Offset: 0x3c
	// Line 423, Address: 0x2e88e0, Func Offset: 0x40
	// Line 425, Address: 0x2e88e4, Func Offset: 0x44
	// Line 426, Address: 0x2e88e8, Func Offset: 0x48
	// Line 432, Address: 0x2e88ec, Func Offset: 0x4c
	// Line 435, Address: 0x2e88f0, Func Offset: 0x50
	// Line 436, Address: 0x2e88f4, Func Offset: 0x54
	// Line 426, Address: 0x2e88f8, Func Offset: 0x58
	// Line 431, Address: 0x2e8904, Func Offset: 0x64
	// Line 432, Address: 0x2e8908, Func Offset: 0x68
	// Line 435, Address: 0x2e890c, Func Offset: 0x6c
	// Line 441, Address: 0x2e8910, Func Offset: 0x70
	// Line 437, Address: 0x2e891c, Func Offset: 0x7c
	// Line 435, Address: 0x2e8920, Func Offset: 0x80
	// Line 436, Address: 0x2e8928, Func Offset: 0x88
	// Line 437, Address: 0x2e892c, Func Offset: 0x8c
	// Line 438, Address: 0x2e8930, Func Offset: 0x90
	// Line 439, Address: 0x2e8934, Func Offset: 0x94
	// Line 441, Address: 0x2e8938, Func Offset: 0x98
	// Line 448, Address: 0x2e893c, Func Offset: 0x9c
	// Line 441, Address: 0x2e8940, Func Offset: 0xa0
	// Line 442, Address: 0x2e8948, Func Offset: 0xa8
	// Line 443, Address: 0x2e8954, Func Offset: 0xb4
	// Line 445, Address: 0x2e8960, Func Offset: 0xc0
	// Line 446, Address: 0x2e8968, Func Offset: 0xc8
	// Line 447, Address: 0x2e8970, Func Offset: 0xd0
	// Line 448, Address: 0x2e8974, Func Offset: 0xd4
	// Line 450, Address: 0x2e8980, Func Offset: 0xe0
	// Line 451, Address: 0x2e8984, Func Offset: 0xe4
	// Line 452, Address: 0x2e8988, Func Offset: 0xe8
	// Line 453, Address: 0x2e8990, Func Offset: 0xf0
	// Line 454, Address: 0x2e8994, Func Offset: 0xf4
	// Line 455, Address: 0x2e899c, Func Offset: 0xfc
	// Line 456, Address: 0x2e89a4, Func Offset: 0x104
	// Line 457, Address: 0x2e89ac, Func Offset: 0x10c
	// Line 473, Address: 0x2e89b4, Func Offset: 0x114
	// Line 476, Address: 0x2e89e0, Func Offset: 0x140
	// Line 477, Address: 0x2e89f0, Func Offset: 0x150
	// Line 482, Address: 0x2e89fc, Func Offset: 0x15c
	// Line 483, Address: 0x2e8a24, Func Offset: 0x184
	// Line 485, Address: 0x2e8a34, Func Offset: 0x194
	// Line 486, Address: 0x2e8a38, Func Offset: 0x198
	// Line 488, Address: 0x2e8a40, Func Offset: 0x1a0
	// Line 489, Address: 0x2e8a78, Func Offset: 0x1d8
	// Line 490, Address: 0x2e8a88, Func Offset: 0x1e8
	// Line 492, Address: 0x2e8a9c, Func Offset: 0x1fc
	// Line 491, Address: 0x2e8aa0, Func Offset: 0x200
	// Line 494, Address: 0x2e8aa4, Func Offset: 0x204
	// Line 496, Address: 0x2e8aac, Func Offset: 0x20c
	// Line 497, Address: 0x2e8ab0, Func Offset: 0x210
	// Line 498, Address: 0x2e8ab8, Func Offset: 0x218
	// Line 543, Address: 0x2e8abc, Func Offset: 0x21c
	// Line 544, Address: 0x2e8ac8, Func Offset: 0x228
	// Line 545, Address: 0x2e8af0, Func Offset: 0x250
	// Line 549, Address: 0x2e8b14, Func Offset: 0x274
	// Func End, Address: 0x2e8b24, Func Offset: 0x284
}

// 
// Start address: 0x2e8b30
void bhEff149(_anon0* op)
{
	_anon39* uvp;
	_anon39 uvtble[10];
	// Line 560, Address: 0x2e8b30, Func Offset: 0
	// Line 585, Address: 0x2e8b3c, Func Offset: 0xc
	// Line 587, Address: 0x2e8b68, Func Offset: 0x38
	// Line 588, Address: 0x2e8b70, Func Offset: 0x40
	// Line 589, Address: 0x2e8b78, Func Offset: 0x48
	// Line 590, Address: 0x2e8b88, Func Offset: 0x58
	// Line 591, Address: 0x2e8b90, Func Offset: 0x60
	// Line 593, Address: 0x2e8b98, Func Offset: 0x68
	// Line 594, Address: 0x2e8ba0, Func Offset: 0x70
	// Line 593, Address: 0x2e8ba8, Func Offset: 0x78
	// Line 594, Address: 0x2e8bac, Func Offset: 0x7c
	// Line 596, Address: 0x2e8bb4, Func Offset: 0x84
	// Line 597, Address: 0x2e8bf4, Func Offset: 0xc4
	// Line 598, Address: 0x2e8bfc, Func Offset: 0xcc
	// Line 601, Address: 0x2e8c04, Func Offset: 0xd4
	// Line 603, Address: 0x2e8c44, Func Offset: 0x114
	// Line 604, Address: 0x2e8c50, Func Offset: 0x120
	// Line 607, Address: 0x2e8c58, Func Offset: 0x128
	// Line 610, Address: 0x2e8c90, Func Offset: 0x160
	// Line 607, Address: 0x2e8c98, Func Offset: 0x168
	// Line 610, Address: 0x2e8c9c, Func Offset: 0x16c
	// Line 613, Address: 0x2e8ca0, Func Offset: 0x170
	// Line 615, Address: 0x2e8ca8, Func Offset: 0x178
	// Line 618, Address: 0x2e8cb0, Func Offset: 0x180
	// Line 619, Address: 0x2e8cc0, Func Offset: 0x190
	// Line 618, Address: 0x2e8cc4, Func Offset: 0x194
	// Line 619, Address: 0x2e8cc8, Func Offset: 0x198
	// Line 620, Address: 0x2e8ce0, Func Offset: 0x1b0
	// Line 621, Address: 0x2e8ce4, Func Offset: 0x1b4
	// Line 623, Address: 0x2e8cec, Func Offset: 0x1bc
	// Line 626, Address: 0x2e8cf4, Func Offset: 0x1c4
	// Line 627, Address: 0x2e8d04, Func Offset: 0x1d4
	// Line 630, Address: 0x2e8d08, Func Offset: 0x1d8
	// Line 632, Address: 0x2e8d18, Func Offset: 0x1e8
	// Line 636, Address: 0x2e8d20, Func Offset: 0x1f0
	// Line 632, Address: 0x2e8d24, Func Offset: 0x1f4
	// Line 636, Address: 0x2e8d28, Func Offset: 0x1f8
	// Line 634, Address: 0x2e8d2c, Func Offset: 0x1fc
	// Line 632, Address: 0x2e8d30, Func Offset: 0x200
	// Line 633, Address: 0x2e8d3c, Func Offset: 0x20c
	// Line 640, Address: 0x2e8d44, Func Offset: 0x214
	// Line 633, Address: 0x2e8d50, Func Offset: 0x220
	// Line 634, Address: 0x2e8d5c, Func Offset: 0x22c
	// Line 635, Address: 0x2e8d70, Func Offset: 0x240
	// Line 636, Address: 0x2e8d88, Func Offset: 0x258
	// Line 637, Address: 0x2e8da4, Func Offset: 0x274
	// Line 638, Address: 0x2e8dbc, Func Offset: 0x28c
	// Line 639, Address: 0x2e8dd0, Func Offset: 0x2a0
	// Line 640, Address: 0x2e8de4, Func Offset: 0x2b4
	// Line 643, Address: 0x2e8dfc, Func Offset: 0x2cc
	// Line 645, Address: 0x2e8e3c, Func Offset: 0x30c
	// Line 647, Address: 0x2e8e44, Func Offset: 0x314
	// Line 648, Address: 0x2e8e54, Func Offset: 0x324
	// Line 647, Address: 0x2e8e58, Func Offset: 0x328
	// Line 648, Address: 0x2e8e5c, Func Offset: 0x32c
	// Line 649, Address: 0x2e8e60, Func Offset: 0x330
	// Line 647, Address: 0x2e8e68, Func Offset: 0x338
	// Line 648, Address: 0x2e8e6c, Func Offset: 0x33c
	// Line 649, Address: 0x2e8e74, Func Offset: 0x344
	// Line 648, Address: 0x2e8e7c, Func Offset: 0x34c
	// Line 649, Address: 0x2e8e84, Func Offset: 0x354
	// Line 650, Address: 0x2e8e98, Func Offset: 0x368
	// Line 651, Address: 0x2e8e9c, Func Offset: 0x36c
	// Line 652, Address: 0x2e8ea8, Func Offset: 0x378
	// Line 653, Address: 0x2e8eb0, Func Offset: 0x380
	// Line 655, Address: 0x2e8eb8, Func Offset: 0x388
	// Line 657, Address: 0x2e8ec0, Func Offset: 0x390
	// Line 658, Address: 0x2e8ec4, Func Offset: 0x394
	// Line 659, Address: 0x2e8ed0, Func Offset: 0x3a0
	// Line 657, Address: 0x2e8ed4, Func Offset: 0x3a4
	// Line 658, Address: 0x2e8edc, Func Offset: 0x3ac
	// Line 659, Address: 0x2e8ee0, Func Offset: 0x3b0
	// Line 658, Address: 0x2e8eec, Func Offset: 0x3bc
	// Line 659, Address: 0x2e8ef4, Func Offset: 0x3c4
	// Line 660, Address: 0x2e8f00, Func Offset: 0x3d0
	// Line 661, Address: 0x2e8f0c, Func Offset: 0x3dc
	// Line 662, Address: 0x2e8f14, Func Offset: 0x3e4
	// Line 664, Address: 0x2e8f1c, Func Offset: 0x3ec
	// Line 665, Address: 0x2e8f2c, Func Offset: 0x3fc
	// Line 667, Address: 0x2e8f34, Func Offset: 0x404
	// Line 668, Address: 0x2e8f3c, Func Offset: 0x40c
	// Line 677, Address: 0x2e8f44, Func Offset: 0x414
	// Line 680, Address: 0x2e8f4c, Func Offset: 0x41c
	// Line 683, Address: 0x2e8f5c, Func Offset: 0x42c
	// Line 687, Address: 0x2e8f64, Func Offset: 0x434
	// Line 689, Address: 0x2e8f70, Func Offset: 0x440
	// Line 687, Address: 0x2e8f7c, Func Offset: 0x44c
	// Line 688, Address: 0x2e8f84, Func Offset: 0x454
	// Line 689, Address: 0x2e8f8c, Func Offset: 0x45c
	// Line 690, Address: 0x2e8fac, Func Offset: 0x47c
	// Line 694, Address: 0x2e8fb0, Func Offset: 0x480
	// Line 703, Address: 0x2e8fb4, Func Offset: 0x484
	// Line 724, Address: 0x2e8fbc, Func Offset: 0x48c
	// Line 694, Address: 0x2e8fc0, Func Offset: 0x490
	// Line 695, Address: 0x2e8fc4, Func Offset: 0x494
	// Line 696, Address: 0x2e8fcc, Func Offset: 0x49c
	// Line 697, Address: 0x2e8fdc, Func Offset: 0x4ac
	// Line 698, Address: 0x2e8fe4, Func Offset: 0x4b4
	// Line 699, Address: 0x2e8fec, Func Offset: 0x4bc
	// Line 700, Address: 0x2e8ffc, Func Offset: 0x4cc
	// Line 701, Address: 0x2e9004, Func Offset: 0x4d4
	// Line 703, Address: 0x2e900c, Func Offset: 0x4dc
	// Line 704, Address: 0x2e9020, Func Offset: 0x4f0
	// Line 705, Address: 0x2e9034, Func Offset: 0x504
	// Line 706, Address: 0x2e9044, Func Offset: 0x514
	// Line 724, Address: 0x2e9054, Func Offset: 0x524
	// Line 725, Address: 0x2e9070, Func Offset: 0x540
	// Line 726, Address: 0x2e9084, Func Offset: 0x554
	// Line 743, Address: 0x2e90a8, Func Offset: 0x578
	// Func End, Address: 0x2e90b8, Func Offset: 0x588
}

// 
// Start address: 0x2e90c0
void bhEff144(_anon0* op)
{
	// Line 967, Address: 0x2e90c0, Func Offset: 0
	// Line 969, Address: 0x2e90e0, Func Offset: 0x20
	// Line 970, Address: 0x2e90e4, Func Offset: 0x24
	// Line 971, Address: 0x2e90e8, Func Offset: 0x28
	// Line 973, Address: 0x2e90f0, Func Offset: 0x30
	// Line 975, Address: 0x2e90f8, Func Offset: 0x38
	// Line 976, Address: 0x2e9104, Func Offset: 0x44
	// Line 977, Address: 0x2e9114, Func Offset: 0x54
	// Line 978, Address: 0x2e9148, Func Offset: 0x88
	// Line 983, Address: 0x2e9150, Func Offset: 0x90
	// Line 985, Address: 0x2e9154, Func Offset: 0x94
	// Line 986, Address: 0x2e918c, Func Offset: 0xcc
	// Func End, Address: 0x2e9194, Func Offset: 0xd4
}

// 
// Start address: 0x2e91a0
void bhEff143_sub(_anon0* op)
{
	_anon21* pp;
	// Line 997, Address: 0x2e91a0, Func Offset: 0
	// Line 1001, Address: 0x2e91b0, Func Offset: 0x10
	// Line 998, Address: 0x2e91b4, Func Offset: 0x14
	// Line 1001, Address: 0x2e91b8, Func Offset: 0x18
	// Line 1002, Address: 0x2e91c4, Func Offset: 0x24
	// Line 1003, Address: 0x2e91dc, Func Offset: 0x3c
	// Line 1004, Address: 0x2e91e4, Func Offset: 0x44
	// Line 1006, Address: 0x2e91ec, Func Offset: 0x4c
	// Line 1007, Address: 0x2e9200, Func Offset: 0x60
	// Line 1008, Address: 0x2e9208, Func Offset: 0x68
	// Line 1009, Address: 0x2e9210, Func Offset: 0x70
	// Line 1013, Address: 0x2e921c, Func Offset: 0x7c
	// Line 1014, Address: 0x2e9228, Func Offset: 0x88
	// Line 1017, Address: 0x2e9234, Func Offset: 0x94
	// Line 1018, Address: 0x2e9244, Func Offset: 0xa4
	// Line 1019, Address: 0x2e9254, Func Offset: 0xb4
	// Line 1020, Address: 0x2e9268, Func Offset: 0xc8
	// Line 1023, Address: 0x2e9270, Func Offset: 0xd0
	// Line 1025, Address: 0x2e927c, Func Offset: 0xdc
	// Line 1027, Address: 0x2e9288, Func Offset: 0xe8
	// Func End, Address: 0x2e929c, Func Offset: 0xfc
}

// 
// Start address: 0x2e92a0
void bhEff143(_anon0* op)
{
	unsigned int col[3];
	int i;
	_anon33* v;
	_anon33* p;
	_anon21* pp;
	// Line 1037, Address: 0x2e92a0, Func Offset: 0
	// Line 1042, Address: 0x2e92b4, Func Offset: 0x14
	// Line 1037, Address: 0x2e92b8, Func Offset: 0x18
	// Line 1042, Address: 0x2e92c0, Func Offset: 0x20
	// Line 1057, Address: 0x2e92dc, Func Offset: 0x3c
	// Line 1059, Address: 0x2e92fc, Func Offset: 0x5c
	// Line 1060, Address: 0x2e9308, Func Offset: 0x68
	// Line 1061, Address: 0x2e930c, Func Offset: 0x6c
	// Line 1062, Address: 0x2e9310, Func Offset: 0x70
	// Line 1063, Address: 0x2e9314, Func Offset: 0x74
	// Line 1066, Address: 0x2e9318, Func Offset: 0x78
	// Line 1067, Address: 0x2e9320, Func Offset: 0x80
	// Line 1069, Address: 0x2e9328, Func Offset: 0x88
	// Line 1072, Address: 0x2e9330, Func Offset: 0x90
	// Line 1073, Address: 0x2e9334, Func Offset: 0x94
	// Line 1075, Address: 0x2e9338, Func Offset: 0x98
	// Line 1076, Address: 0x2e9340, Func Offset: 0xa0
	// Line 1077, Address: 0x2e9344, Func Offset: 0xa4
	// Line 1075, Address: 0x2e9348, Func Offset: 0xa8
	// Line 1076, Address: 0x2e9350, Func Offset: 0xb0
	// Line 1077, Address: 0x2e9354, Func Offset: 0xb4
	// Line 1080, Address: 0x2e9358, Func Offset: 0xb8
	// Line 1081, Address: 0x2e9360, Func Offset: 0xc0
	// Line 1083, Address: 0x2e9368, Func Offset: 0xc8
	// Line 1086, Address: 0x2e936c, Func Offset: 0xcc
	// Line 1084, Address: 0x2e9370, Func Offset: 0xd0
	// Line 1086, Address: 0x2e9374, Func Offset: 0xd4
	// Line 1087, Address: 0x2e937c, Func Offset: 0xdc
	// Line 1088, Address: 0x2e93c0, Func Offset: 0x120
	// Line 1089, Address: 0x2e93f4, Func Offset: 0x154
	// Line 1091, Address: 0x2e9438, Func Offset: 0x198
	// Line 1092, Address: 0x2e9470, Func Offset: 0x1d0
	// Line 1093, Address: 0x2e94b0, Func Offset: 0x210
	// Line 1094, Address: 0x2e94c4, Func Offset: 0x224
	// Line 1095, Address: 0x2e94fc, Func Offset: 0x25c
	// Line 1096, Address: 0x2e950c, Func Offset: 0x26c
	// Line 1095, Address: 0x2e9514, Func Offset: 0x274
	// Line 1096, Address: 0x2e951c, Func Offset: 0x27c
	// Line 1098, Address: 0x2e9530, Func Offset: 0x290
	// Line 1099, Address: 0x2e9538, Func Offset: 0x298
	// Line 1101, Address: 0x2e9540, Func Offset: 0x2a0
	// Line 1104, Address: 0x2e9580, Func Offset: 0x2e0
	// Line 1101, Address: 0x2e9584, Func Offset: 0x2e4
	// Line 1104, Address: 0x2e9588, Func Offset: 0x2e8
	// Line 1105, Address: 0x2e958c, Func Offset: 0x2ec
	// Line 1109, Address: 0x2e9598, Func Offset: 0x2f8
	// Line 1115, Address: 0x2e95b8, Func Offset: 0x318
	// Line 1118, Address: 0x2e95bc, Func Offset: 0x31c
	// Line 1116, Address: 0x2e95c0, Func Offset: 0x320
	// Line 1118, Address: 0x2e95c4, Func Offset: 0x324
	// Line 1119, Address: 0x2e95cc, Func Offset: 0x32c
	// Line 1120, Address: 0x2e9618, Func Offset: 0x378
	// Line 1121, Address: 0x2e9664, Func Offset: 0x3c4
	// Line 1127, Address: 0x2e968c, Func Offset: 0x3ec
	// Line 1121, Address: 0x2e9690, Func Offset: 0x3f0
	// Line 1127, Address: 0x2e96a0, Func Offset: 0x400
	// Line 1130, Address: 0x2e96a4, Func Offset: 0x404
	// Line 1121, Address: 0x2e96a8, Func Offset: 0x408
	// Line 1127, Address: 0x2e96b0, Func Offset: 0x410
	// Line 1121, Address: 0x2e96b4, Func Offset: 0x414
	// Line 1123, Address: 0x2e96c0, Func Offset: 0x420
	// Line 1124, Address: 0x2e96d0, Func Offset: 0x430
	// Line 1125, Address: 0x2e96e0, Func Offset: 0x440
	// Line 1127, Address: 0x2e96f0, Func Offset: 0x450
	// Line 1130, Address: 0x2e96f4, Func Offset: 0x454
	// Line 1127, Address: 0x2e96f8, Func Offset: 0x458
	// Line 1128, Address: 0x2e9700, Func Offset: 0x460
	// Line 1129, Address: 0x2e970c, Func Offset: 0x46c
	// Line 1130, Address: 0x2e9718, Func Offset: 0x478
	// Line 1133, Address: 0x2e9730, Func Offset: 0x490
	// Line 1134, Address: 0x2e977c, Func Offset: 0x4dc
	// Line 1136, Address: 0x2e978c, Func Offset: 0x4ec
	// Line 1137, Address: 0x2e97e4, Func Offset: 0x544
	// Line 1138, Address: 0x2e97f4, Func Offset: 0x554
	// Line 1141, Address: 0x2e9800, Func Offset: 0x560
	// Line 1143, Address: 0x2e9810, Func Offset: 0x570
	// Line 1145, Address: 0x2e9818, Func Offset: 0x578
	// Line 1148, Address: 0x2e9820, Func Offset: 0x580
	// Line 1149, Address: 0x2e9840, Func Offset: 0x5a0
	// Line 1150, Address: 0x2e9854, Func Offset: 0x5b4
	// Line 1153, Address: 0x2e9878, Func Offset: 0x5d8
	// Func End, Address: 0x2e9898, Func Offset: 0x5f8
}

