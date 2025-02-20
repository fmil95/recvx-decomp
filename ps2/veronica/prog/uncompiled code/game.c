typedef struct npobj;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct BH_PWORK;
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

typedef void(*type_82)(void*);

typedef float type_0[16];
typedef unsigned int type_1[4];
typedef _anon1* type_2[512];
typedef _anon1* type_3[32];
typedef _anon2* type_4[16];
typedef _anon1* type_5[32];
typedef _anon1* type_6[512];
typedef _anon2* type_7[16][16];
typedef _anon2* type_8[16][16][100];
typedef char type_9[8];
typedef _anon1* type_10[32];
typedef _anon1* type_11[512];
typedef _anon2* type_12[1300];
typedef char type_13[32];
typedef float type_14[32];
typedef _anon1* type_15[512];
typedef _anon2* type_16[200];
typedef short type_17[32];
typedef _anon23 type_18[1];
typedef _anon1* type_19[128];
typedef unsigned int type_20[1];
typedef _anon7 type_21[256];
typedef _anon2* type_22[8];
typedef int* type_23[16];
typedef _anon1* type_24[128];
typedef _anon43 type_25[16];
typedef npobj* type_26[16];
typedef _anon1* type_27[128];
typedef int type_28[4];
typedef _anon2* type_29[16];
typedef unsigned int type_30[4];
typedef float type_31[4];
typedef _anon12 type_32[16];
typedef _anon1* type_33[512];
typedef float type_34[4];
typedef char type_35[256];
typedef float type_36[4];
typedef float type_37[4];
typedef float type_38[4];
typedef float type_39[4];
typedef _anon5* type_40[128];
typedef float type_41[3];
typedef unsigned char type_42[64];
typedef float type_43[3][20];
typedef float type_44[3];
typedef float type_45[3][20];
typedef float type_46[3];
typedef float type_47[3][20];
typedef char type_48[8];
typedef float type_49[3];
typedef float type_50[3][20];
typedef void* type_51[2];
typedef _anon2* type_52[256];
typedef int type_53[4];
typedef unsigned char* type_54[256];
typedef unsigned int type_55[2];
typedef short type_56[256];
typedef _anon29 type_57[4];
typedef float type_58[3];
typedef short type_59[256];
typedef int type_60[3];
typedef int type_61[8];
typedef float type_62[3];
typedef _anon2* type_63[256];
typedef _anon9 type_64[256];
typedef _anon23 type_65[450];
typedef _anon31 type_66[16];
typedef short type_67[256];
typedef char type_68[3];
typedef int type_69[64];
typedef _anon12 type_70[450];
typedef unsigned int type_71[16];
typedef char type_72[4];
typedef unsigned int type_73[8];
typedef _anon35 type_74[4];
typedef _anon3 type_75[4];
typedef int type_76[450];
typedef unsigned int type_77[8];
typedef unsigned char type_78[450];
typedef float type_79[128];
typedef char type_80[16];
typedef char type_81[4];
typedef _anon21 type_83[2];
typedef unsigned int type_84[32];
typedef unsigned char type_85[256];
typedef unsigned int type_86[16];
typedef _anon19 type_87[64];
typedef unsigned int type_88[16];
typedef _anon19 type_89[64];
typedef unsigned int type_90[32];
typedef _anon19 type_91[64];
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
typedef _anon2* type_105[16];
typedef char type_106[4];
typedef _anon12 type_107[16];
typedef short type_108[4];
typedef unsigned char type_109[4];
typedef _anon33 type_110[16];
typedef unsigned int type_111[8];
typedef unsigned int type_112[32];
typedef unsigned int type_113[4];
typedef _anon32 type_114[32];
typedef _anon1* type_115[512];
typedef _anon1* type_116[128];
typedef _anon1* type_117[512];
typedef unsigned char type_118[64];
typedef _anon1* type_119[512];

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
	_anon2* et_lp[16][16][100];
	_anon2* ot_lp[1300];
	_anon2* it_lp[200];
	int eft_n;
	_anon2* eft_lp[8];
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
	_anon1* obwp;
	_anon1* itwp;
	_anon5* emtp[128];
	_anon5* rmthp;
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
	_anon9 txbp[256];
	unsigned char* ef_psp;
	_anon23 ef_tex[450];
	_anon2 ef_tlist;
	_anon36 ef;
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
	_anon20 ren_info;
	_anon23 ren_tex[1];
	_anon2 ren_tlist;
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
	_anon15* lgtp;
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
	_anon19* pl_htp;
	int costume;
	_anon32 hd_pos;
	_anon32 apos;
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
	_anon2* sb_tlist;
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
	_anon2* txp[16];
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
	_anon41 cspr;
	int pn;
	_anon35* pvp;
	_anon3* tvp;
	_anon35 pv[4];
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

struct _anon2
{
	_anon23* textures;
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
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon22* md2P;
	unsigned short* atrP;
};

struct _anon6
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon43 keyf[16];
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
	_anon42 watr;
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
	_anon18* effp;
	_anon19* walp;
	_anon19* etcp;
	_anon19* flrp;
	_anon4* posp;
	_anon19* rutp;
	unsigned char* ruttp;
	_anon25* evtp;
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
	_anon21 cam[2];
	unsigned char exd[256];
};

struct _anon12
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon2* texP;
	_anon27* owP;
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
	_anon39* info;
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
	_anon28* light;
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
	_anon8 texsurface;
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
	_anon40 attr;
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

struct _anon41
{
	_anon32 c;
	float r;
};

struct _anon42
{
	_anon32 c1;
	_anon32 c2;
	float r;
};

struct _anon43
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

_anon0* sys;
_anon10* rom;
_anon37 cam;
BH_PWORK* plp;
unsigned char pl_sleep_cnt;
unsigned int Ps2_albinoid_flag;

void bhMainSequence();
void bhAllDrawModel();
void bhAllEasyDrawModel();
void bhEtcMirrorDrawModel();

// 
// Start address: 0x137600
void bhMainSequence()
{
	int i;
	// Line 120, Address: 0x137600, Func Offset: 0
	// Line 123, Address: 0x13760c, Func Offset: 0xc
	// Line 132, Address: 0x13762c, Func Offset: 0x2c
	// Line 134, Address: 0x137650, Func Offset: 0x50
	// Line 135, Address: 0x13765c, Func Offset: 0x5c
	// Line 137, Address: 0x137668, Func Offset: 0x68
	// Line 139, Address: 0x137688, Func Offset: 0x88
	// Line 155, Address: 0x1376c8, Func Offset: 0xc8
	// Line 156, Address: 0x1376d0, Func Offset: 0xd0
	// Line 157, Address: 0x1376d8, Func Offset: 0xd8
	// Line 158, Address: 0x1376e0, Func Offset: 0xe0
	// Line 170, Address: 0x1376e8, Func Offset: 0xe8
	// Line 173, Address: 0x137720, Func Offset: 0x120
	// Line 174, Address: 0x137728, Func Offset: 0x128
	// Line 175, Address: 0x137730, Func Offset: 0x130
	// Line 177, Address: 0x137738, Func Offset: 0x138
	// Line 191, Address: 0x137758, Func Offset: 0x158
	// Line 197, Address: 0x137770, Func Offset: 0x170
	// Line 203, Address: 0x137798, Func Offset: 0x198
	// Line 206, Address: 0x1377a0, Func Offset: 0x1a0
	// Line 207, Address: 0x1377b8, Func Offset: 0x1b8
	// Line 208, Address: 0x1377bc, Func Offset: 0x1bc
	// Line 207, Address: 0x1377c0, Func Offset: 0x1c0
	// Line 208, Address: 0x1377c8, Func Offset: 0x1c8
	// Line 209, Address: 0x1377d8, Func Offset: 0x1d8
	// Line 210, Address: 0x1377f8, Func Offset: 0x1f8
	// Line 211, Address: 0x137800, Func Offset: 0x200
	// Line 212, Address: 0x137808, Func Offset: 0x208
	// Line 213, Address: 0x13781c, Func Offset: 0x21c
	// Line 214, Address: 0x137834, Func Offset: 0x234
	// Line 216, Address: 0x137838, Func Offset: 0x238
	// Line 218, Address: 0x137868, Func Offset: 0x268
	// Line 220, Address: 0x137890, Func Offset: 0x290
	// Line 223, Address: 0x1378b8, Func Offset: 0x2b8
	// Line 233, Address: 0x1378e8, Func Offset: 0x2e8
	// Line 234, Address: 0x137914, Func Offset: 0x314
	// Line 235, Address: 0x137920, Func Offset: 0x320
	// Line 234, Address: 0x137928, Func Offset: 0x328
	// Line 235, Address: 0x137930, Func Offset: 0x330
	// Line 236, Address: 0x137948, Func Offset: 0x348
	// Line 237, Address: 0x13794c, Func Offset: 0x34c
	// Line 236, Address: 0x137958, Func Offset: 0x358
	// Line 237, Address: 0x137960, Func Offset: 0x360
	// Line 239, Address: 0x137970, Func Offset: 0x370
	// Line 240, Address: 0x137998, Func Offset: 0x398
	// Line 242, Address: 0x1379a4, Func Offset: 0x3a4
	// Line 240, Address: 0x1379a8, Func Offset: 0x3a8
	// Line 241, Address: 0x1379ac, Func Offset: 0x3ac
	// Line 242, Address: 0x1379b8, Func Offset: 0x3b8
	// Line 241, Address: 0x1379bc, Func Offset: 0x3bc
	// Line 242, Address: 0x1379c4, Func Offset: 0x3c4
	// Line 243, Address: 0x1379d8, Func Offset: 0x3d8
	// Line 244, Address: 0x1379e0, Func Offset: 0x3e0
	// Line 243, Address: 0x1379e4, Func Offset: 0x3e4
	// Line 244, Address: 0x1379ec, Func Offset: 0x3ec
	// Line 245, Address: 0x1379fc, Func Offset: 0x3fc
	// Line 246, Address: 0x137a00, Func Offset: 0x400
	// Line 247, Address: 0x137a20, Func Offset: 0x420
	// Line 248, Address: 0x137a40, Func Offset: 0x440
	// Line 251, Address: 0x137a60, Func Offset: 0x460
	// Line 252, Address: 0x137a8c, Func Offset: 0x48c
	// Line 253, Address: 0x137a9c, Func Offset: 0x49c
	// Line 254, Address: 0x137aa0, Func Offset: 0x4a0
	// Line 253, Address: 0x137aac, Func Offset: 0x4ac
	// Line 254, Address: 0x137ab4, Func Offset: 0x4b4
	// Line 255, Address: 0x137ac4, Func Offset: 0x4c4
	// Line 256, Address: 0x137ac8, Func Offset: 0x4c8
	// Line 257, Address: 0x137ae4, Func Offset: 0x4e4
	// Line 258, Address: 0x137af0, Func Offset: 0x4f0
	// Line 259, Address: 0x137af8, Func Offset: 0x4f8
	// Line 260, Address: 0x137b04, Func Offset: 0x504
	// Line 259, Address: 0x137b08, Func Offset: 0x508
	// Line 260, Address: 0x137b10, Func Offset: 0x510
	// Line 261, Address: 0x137b24, Func Offset: 0x524
	// Line 262, Address: 0x137b2c, Func Offset: 0x52c
	// Line 263, Address: 0x137b3c, Func Offset: 0x53c
	// Line 262, Address: 0x137b40, Func Offset: 0x540
	// Line 263, Address: 0x137b48, Func Offset: 0x548
	// Line 264, Address: 0x137b70, Func Offset: 0x570
	// Line 265, Address: 0x137b90, Func Offset: 0x590
	// Line 266, Address: 0x137bb0, Func Offset: 0x5b0
	// Line 268, Address: 0x137bd0, Func Offset: 0x5d0
	// Line 269, Address: 0x137bec, Func Offset: 0x5ec
	// Line 270, Address: 0x137bf4, Func Offset: 0x5f4
	// Line 271, Address: 0x137bf8, Func Offset: 0x5f8
	// Line 269, Address: 0x137bfc, Func Offset: 0x5fc
	// Line 270, Address: 0x137c04, Func Offset: 0x604
	// Line 271, Address: 0x137c0c, Func Offset: 0x60c
	// Line 270, Address: 0x137c10, Func Offset: 0x610
	// Line 271, Address: 0x137c18, Func Offset: 0x618
	// Line 272, Address: 0x137c2c, Func Offset: 0x62c
	// Line 273, Address: 0x137c34, Func Offset: 0x634
	// Line 272, Address: 0x137c38, Func Offset: 0x638
	// Line 273, Address: 0x137c40, Func Offset: 0x640
	// Line 279, Address: 0x137c50, Func Offset: 0x650
	// Line 280, Address: 0x137c6c, Func Offset: 0x66c
	// Line 281, Address: 0x137c74, Func Offset: 0x674
	// Line 280, Address: 0x137c78, Func Offset: 0x678
	// Line 281, Address: 0x137c80, Func Offset: 0x680
	// Line 283, Address: 0x137c88, Func Offset: 0x688
	// Line 284, Address: 0x137c94, Func Offset: 0x694
	// Line 283, Address: 0x137c98, Func Offset: 0x698
	// Line 284, Address: 0x137ca0, Func Offset: 0x6a0
	// Line 285, Address: 0x137cc8, Func Offset: 0x6c8
	// Line 286, Address: 0x137ce8, Func Offset: 0x6e8
	// Line 288, Address: 0x137cf0, Func Offset: 0x6f0
	// Line 286, Address: 0x137cf8, Func Offset: 0x6f8
	// Line 288, Address: 0x137d00, Func Offset: 0x700
	// Line 289, Address: 0x137d14, Func Offset: 0x714
	// Line 290, Address: 0x137d18, Func Offset: 0x718
	// Line 291, Address: 0x137d38, Func Offset: 0x738
	// Line 294, Address: 0x137d48, Func Offset: 0x748
	// Line 295, Address: 0x137d74, Func Offset: 0x774
	// Line 297, Address: 0x137d78, Func Offset: 0x778
	// Line 298, Address: 0x137d90, Func Offset: 0x790
	// Line 299, Address: 0x137db4, Func Offset: 0x7b4
	// Line 300, Address: 0x137dc0, Func Offset: 0x7c0
	// Line 301, Address: 0x137df0, Func Offset: 0x7f0
	// Line 305, Address: 0x137e00, Func Offset: 0x800
	// Line 306, Address: 0x137e1c, Func Offset: 0x81c
	// Line 307, Address: 0x137e24, Func Offset: 0x824
	// Line 306, Address: 0x137e28, Func Offset: 0x828
	// Line 307, Address: 0x137e30, Func Offset: 0x830
	// Line 309, Address: 0x137e38, Func Offset: 0x838
	// Line 310, Address: 0x137e44, Func Offset: 0x844
	// Line 309, Address: 0x137e48, Func Offset: 0x848
	// Line 310, Address: 0x137e50, Func Offset: 0x850
	// Line 312, Address: 0x137e64, Func Offset: 0x864
	// Line 313, Address: 0x137e68, Func Offset: 0x868
	// Line 312, Address: 0x137e6c, Func Offset: 0x86c
	// Line 313, Address: 0x137e74, Func Offset: 0x874
	// Line 314, Address: 0x137e9c, Func Offset: 0x89c
	// Line 315, Address: 0x137ea0, Func Offset: 0x8a0
	// Line 316, Address: 0x137ecc, Func Offset: 0x8cc
	// Line 318, Address: 0x137ed0, Func Offset: 0x8d0
	// Line 322, Address: 0x137f00, Func Offset: 0x900
	// Line 326, Address: 0x137f40, Func Offset: 0x940
	// Line 327, Address: 0x137f48, Func Offset: 0x948
	// Line 328, Address: 0x137f4c, Func Offset: 0x94c
	// Line 326, Address: 0x137f50, Func Offset: 0x950
	// Line 327, Address: 0x137f58, Func Offset: 0x958
	// Line 328, Address: 0x137f60, Func Offset: 0x960
	// Line 327, Address: 0x137f64, Func Offset: 0x964
	// Line 328, Address: 0x137f6c, Func Offset: 0x96c
	// Line 330, Address: 0x137f7c, Func Offset: 0x97c
	// Line 332, Address: 0x137f80, Func Offset: 0x980
	// Line 333, Address: 0x137f98, Func Offset: 0x998
	// Line 334, Address: 0x137fc0, Func Offset: 0x9c0
	// Line 335, Address: 0x137fdc, Func Offset: 0x9dc
	// Line 336, Address: 0x137fe4, Func Offset: 0x9e4
	// Line 338, Address: 0x137ff8, Func Offset: 0x9f8
	// Line 339, Address: 0x138020, Func Offset: 0xa20
	// Line 342, Address: 0x138030, Func Offset: 0xa30
	// Line 344, Address: 0x138050, Func Offset: 0xa50
	// Line 345, Address: 0x138060, Func Offset: 0xa60
	// Line 346, Address: 0x138080, Func Offset: 0xa80
	// Line 347, Address: 0x13808c, Func Offset: 0xa8c
	// Line 349, Address: 0x138090, Func Offset: 0xa90
	// Line 351, Address: 0x138098, Func Offset: 0xa98
	// Line 352, Address: 0x1380c0, Func Offset: 0xac0
	// Func End, Address: 0x1380d0, Func Offset: 0xad0
}

// 
// Start address: 0x1380d0
void bhAllDrawModel()
{
	// Line 358, Address: 0x1380d0, Func Offset: 0
	// Line 361, Address: 0x1380d8, Func Offset: 0x8
	// Line 364, Address: 0x1380e0, Func Offset: 0x10
	// Line 365, Address: 0x1380e8, Func Offset: 0x18
	// Line 368, Address: 0x13810c, Func Offset: 0x3c
	// Line 371, Address: 0x138130, Func Offset: 0x60
	// Line 372, Address: 0x13815c, Func Offset: 0x8c
	// Line 374, Address: 0x138164, Func Offset: 0x94
	// Line 402, Address: 0x138174, Func Offset: 0xa4
	// Line 403, Address: 0x1381a0, Func Offset: 0xd0
	// Line 404, Address: 0x1381b0, Func Offset: 0xe0
	// Line 406, Address: 0x1381c0, Func Offset: 0xf0
	// Line 410, Address: 0x1381c8, Func Offset: 0xf8
	// Line 412, Address: 0x1381d4, Func Offset: 0x104
	// Line 415, Address: 0x138208, Func Offset: 0x138
	// Line 416, Address: 0x138218, Func Offset: 0x148
	// Line 417, Address: 0x138230, Func Offset: 0x160
	// Line 421, Address: 0x138238, Func Offset: 0x168
	// Line 423, Address: 0x138240, Func Offset: 0x170
	// Line 424, Address: 0x138248, Func Offset: 0x178
	// Line 427, Address: 0x13826c, Func Offset: 0x19c
	// Line 432, Address: 0x138290, Func Offset: 0x1c0
	// Line 433, Address: 0x1382a0, Func Offset: 0x1d0
	// Line 434, Address: 0x1382b8, Func Offset: 0x1e8
	// Line 438, Address: 0x1382c0, Func Offset: 0x1f0
	// Line 439, Address: 0x1382cc, Func Offset: 0x1fc
	// Line 440, Address: 0x1382d4, Func Offset: 0x204
	// Line 442, Address: 0x1382f4, Func Offset: 0x224
	// Line 447, Address: 0x138300, Func Offset: 0x230
	// Line 449, Address: 0x138360, Func Offset: 0x290
	// Line 451, Address: 0x13837c, Func Offset: 0x2ac
	// Line 461, Address: 0x138394, Func Offset: 0x2c4
	// Line 462, Address: 0x1383a0, Func Offset: 0x2d0
	// Line 463, Address: 0x1383bc, Func Offset: 0x2ec
	// Line 487, Address: 0x1383cc, Func Offset: 0x2fc
	// Line 488, Address: 0x1383f8, Func Offset: 0x328
	// Line 490, Address: 0x138400, Func Offset: 0x330
	// Line 491, Address: 0x138410, Func Offset: 0x340
	// Line 493, Address: 0x138418, Func Offset: 0x348
	// Line 494, Address: 0x138420, Func Offset: 0x350
	// Line 496, Address: 0x138428, Func Offset: 0x358
	// Func End, Address: 0x138434, Func Offset: 0x364
}

// 
// Start address: 0x138440
void bhAllEasyDrawModel()
{
	// Line 502, Address: 0x138440, Func Offset: 0
	// Line 504, Address: 0x138444, Func Offset: 0x4
	// Line 502, Address: 0x138448, Func Offset: 0x8
	// Line 504, Address: 0x13844c, Func Offset: 0xc
	// Line 507, Address: 0x138454, Func Offset: 0x14
	// Line 508, Address: 0x13845c, Func Offset: 0x1c
	// Line 511, Address: 0x138480, Func Offset: 0x40
	// Line 514, Address: 0x1384a4, Func Offset: 0x64
	// Line 515, Address: 0x1384d0, Func Offset: 0x90
	// Line 517, Address: 0x1384d8, Func Offset: 0x98
	// Line 518, Address: 0x1384e8, Func Offset: 0xa8
	// Line 519, Address: 0x138514, Func Offset: 0xd4
	// Line 520, Address: 0x138524, Func Offset: 0xe4
	// Line 522, Address: 0x138534, Func Offset: 0xf4
	// Line 525, Address: 0x13853c, Func Offset: 0xfc
	// Line 532, Address: 0x138544, Func Offset: 0x104
	// Line 533, Address: 0x13854c, Func Offset: 0x10c
	// Line 534, Address: 0x138564, Func Offset: 0x124
	// Line 536, Address: 0x13856c, Func Offset: 0x12c
	// Func End, Address: 0x138578, Func Offset: 0x138
}

// 
// Start address: 0x138580
void bhEtcMirrorDrawModel()
{
	// Line 542, Address: 0x138580, Func Offset: 0
	// Line 547, Address: 0x138588, Func Offset: 0x8
	// Line 548, Address: 0x138590, Func Offset: 0x10
	// Line 552, Address: 0x13859c, Func Offset: 0x1c
	// Line 553, Address: 0x1385a4, Func Offset: 0x24
	// Line 556, Address: 0x1385c8, Func Offset: 0x48
	// Line 559, Address: 0x1385ec, Func Offset: 0x6c
	// Line 560, Address: 0x138618, Func Offset: 0x98
	// Line 562, Address: 0x138620, Func Offset: 0xa0
	// Line 563, Address: 0x138630, Func Offset: 0xb0
	// Line 564, Address: 0x13865c, Func Offset: 0xdc
	// Line 565, Address: 0x13866c, Func Offset: 0xec
	// Line 567, Address: 0x13867c, Func Offset: 0xfc
	// Line 569, Address: 0x138684, Func Offset: 0x104
	// Line 571, Address: 0x138690, Func Offset: 0x110
	// Line 573, Address: 0x138698, Func Offset: 0x118
	// Line 574, Address: 0x1386b0, Func Offset: 0x130
	// Line 576, Address: 0x1386b8, Func Offset: 0x138
	// Func End, Address: 0x1386c4, Func Offset: 0x144
}

