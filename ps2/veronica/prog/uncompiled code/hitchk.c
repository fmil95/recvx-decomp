typedef struct npobj;
typedef struct _anon0;
typedef struct _anon1;
typedef struct BH_PWORK;
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

typedef void(*type_87)(void*);

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
typedef _anon25 type_18[1];
typedef _anon1* type_19[128];
typedef unsigned int type_20[1];
typedef _anon9 type_21[256];
typedef _anon2* type_22[8];
typedef int* type_23[16];
typedef _anon1* type_24[128];
typedef _anon43 type_25[16];
typedef BH_PWORK type_26[0];
typedef npobj* type_27[16];
typedef _anon1* type_28[128];
typedef int type_29[4];
typedef _anon2* type_30[16];
typedef unsigned int type_31[4];
typedef float type_32[4];
typedef _anon1 type_33[0];
typedef _anon14 type_34[16];
typedef _anon1* type_35[512];
typedef float type_36[4];
typedef char type_37[256];
typedef float type_38[4];
typedef float type_39[4];
typedef float type_40[4];
typedef float type_41[4];
typedef _anon6* type_42[128];
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
typedef _anon2* type_54[256];
typedef int type_55[4];
typedef unsigned char* type_56[256];
typedef unsigned int type_57[2];
typedef short type_58[256];
typedef _anon31 type_59[4];
typedef float type_60[3];
typedef float type_61[5];
typedef short type_62[256];
typedef int type_63[3];
typedef int type_64[8];
typedef float type_65[3];
typedef float type_66[5];
typedef _anon2* type_67[256];
typedef _anon11 type_68[256];
typedef _anon25 type_69[450];
typedef _anon33 type_70[16];
typedef short type_71[256];
typedef char type_72[3];
typedef int type_73[64];
typedef _anon14 type_74[450];
typedef unsigned int type_75[16];
typedef char type_76[4];
typedef unsigned int type_77[8];
typedef _anon36 type_78[4];
typedef _anon3 type_79[4];
typedef int type_80[450];
typedef _anon20 type_81[128];
typedef unsigned int type_82[8];
typedef unsigned char type_83[450];
typedef float type_84[128];
typedef char type_85[16];
typedef char type_86[4];
typedef _anon23 type_88[2];
typedef unsigned int type_89[32];
typedef unsigned char type_90[256];
typedef unsigned int type_91[16];
typedef _anon0 type_92[64];
typedef unsigned int type_93[16];
typedef _anon0 type_94[64];
typedef unsigned int type_95[32];
typedef _anon0 type_96[64];
typedef unsigned int type_97[16];
typedef unsigned int type_98[3];
typedef BH_PWORK* type_99[16];
typedef unsigned int type_100[8];
typedef unsigned int type_101[1];
typedef unsigned int type_102[384];
typedef unsigned int type_103[2];
typedef unsigned char type_104[2];
typedef int* type_105[16];
typedef unsigned int type_106[4];
typedef char type_107[32];
typedef npobj* type_108[16];
typedef char type_109[64];
typedef _anon2* type_110[16];
typedef char type_111[4];
typedef _anon14 type_112[16];
typedef short type_113[4];
typedef _anon20 type_114[8];
typedef unsigned char type_115[4];
typedef _anon34 type_116[16];
typedef unsigned int type_117[8];
typedef unsigned int type_118[32];
typedef unsigned int type_119[4];
typedef _anon20 type_120[32];
typedef _anon1* type_121[512];
typedef _anon1* type_122[128];
typedef _anon1* type_123[512];
typedef unsigned char type_124[64];
typedef _anon1* type_125[512];

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
	_anon6* mnwP;
	_anon6* mnwPb;
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
	_anon7 cspr;
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
	_anon6* mnwP;
	_anon6* mnwPb;
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
	_anon26* cpcl;
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

struct _anon2
{
	_anon25* textures;
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
	_anon20 ply_pos;
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
	_anon1* obwp;
	_anon1* itwp;
	_anon6* emtp[128];
	_anon6* rmthp;
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
	_anon11 txbp[256];
	unsigned char* ef_psp;
	_anon25 ef_tex[450];
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
	_anon22 ren_info;
	_anon25 ren_tex[1];
	_anon2 ren_tlist;
	_anon9 rpb[256];
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
	_anon17* lgtp;
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
	_anon0* pl_htp;
	int costume;
	_anon20 hd_pos;
	_anon20 apos;
	_anon0* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon0 mwalp[64];
	_anon0 metcp[64];
	_anon0 mflrp[64];
	int dla_n;
	_anon0* htp;
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
	_anon20 ufo_pos;
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
	_anon20 ghtp[32];
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

struct _anon5
{
	float px;
	float py;
	float pz;
	int ay;
};

struct _anon6
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon24* md2P;
	unsigned short* atrP;
};

struct _anon7
{
	_anon20 c;
	float r;
};

struct _anon8
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon43 keyf[16];
};

struct _anon9
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
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
	_anon13* cutp;
	_anon17* lgtp;
	_anon18* enep;
	_anon18* objp;
	_anon18* itmp;
	_anon21* effp;
	_anon0* walp;
	_anon0* etcp;
	_anon0* flrp;
	_anon5* posp;
	_anon0* rutp;
	unsigned char* ruttp;
	_anon27* evtp;
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
	_anon40* info;
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
	_anon30* light;
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
	float x;
	float y;
	float z;
};

struct _anon21
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

struct _anon22
{
	void* texaddr;
	_anon10 texsurface;
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
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon26
{
	short jnt_a;
	short jnt_b;
	int cap_r;
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
	_anon20 pnt;
	_anon20 vctr;
	int stat;
	int reserve;
	_anon35 ltcal;
	_anon41 attr;
};

struct _anon31
{
	_anon20 ps;
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
	_anon20 center;
	float r;
};

struct _anon33
{
	float x;
	float y;
};

struct _anon34
{
	_anon20 c1;
	_anon20 c2;
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
	_anon20 lpnt;
	_anon20 lvctr;
	_anon20 lmvctr;
	_anon28 atten;
	_anon28 amb;
	_anon28 dif;
	_anon28 spc;
	_anon28 mamb;
	_anon28 mdif;
	_anon28 mspc;
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
	_anon28 argb;
};

struct _anon42
{
	_anon20 c1;
	_anon20 c2;
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

struct _anon44
{
	_anon20 v[8];
};

_anon4* sys;
_anon12* rom;
_anon1 eff[0];
BH_PWORK* plp;
_anon38 cam;
BH_PWORK ene[0];

void bhCheckWall(BH_PWORK* pw);
int bhCheckWallEx(BH_PWORK* pw, _anon20* npos, _anon20* opos, float par, float pah);
void bhCheckWall2Box(BH_PWORK* pw);
_anon0* bhCheckWallType(_anon20* pos, unsigned int flg, float ar, float ah);
_anon0* bhCheckWallType2(_anon20* pos, unsigned int flg, float aw, float ad, float ah, int idx_ct);
_anon0* bhCheckWallRefAngle(_anon20* pos, unsigned int flg, float ar, float ah, int* ay);
void bhSetWallRefAngle(_anon0* hp, _anon20* pos, float ar, float ah, int* ay);
float bhGetGroundPosition(_anon20* pos);
int bhCheckInnerTriangle(_anon0* hp, _anon20* pos, float ar, float ah);
int bhCheckInnerTriangle2(_anon0* hp, _anon20* pos, float aw, float ad, float ah);
int bhCheckInnerTriangle3(_anon0* hp, _anon20* pos);
int bhCheckBox(_anon0* hp, _anon20* pos, float ar, float ah, unsigned int aflg);
int bhCheckBox2Box(_anon0* hp, _anon20* pos, float aw, float ad, float ah);
int bhCheckInnerP4(_anon33* pos, _anon33* p0, _anon33* p1, _anon33* p2, _anon33* p3);
void bhCheckExmAtari(BH_PWORK* pp);
void bhSetUseKaidanFlag(BH_PWORK* pp, _anon0* exp, int idx);
void bhClrUseKaidanFlag(BH_PWORK* pp);
void bhSetDansaLimitAtari(BH_PWORK* pp);
_anon0* bhCheckDansaAtari(int flr_no, float px, float pz);
void bhCheckFloorP(BH_PWORK* pp);
void bhCheckDansa(BH_PWORK* pp);
int bhCheckFloorSound(BH_PWORK* pp, int flr_no, float px, float pz);
_anon0* bhCheckFloorEnemy(int flr_no, float px, float pz);
_anon0* bhCheckFloorEffect(int flr_no, float px, float pz);
_anon0* bhCheckWater(_anon20* pos);
_anon0* bhCheckL2Water(_anon39* lp, _anon20* pos);
void bhResetAtariAttr();
void bhCheckPlayer(BH_PWORK* pp);
void bhCheckEnemies(BH_PWORK* pp);
int bhCheckWallAttrB89(_anon0* hp);

// 
// Start address: 0x25d590
void bhCheckWall(BH_PWORK* pw)
{
	float inn;
	_anon20 vec1;
	_anon20 vec0;
	int r;
	float abz;
	float abx;
	float wpz;
	float wpx;
	float pah;
	float par;
	float ln;
	float zn;
	float xn;
	float pz;
	float px;
	float hd;
	float hh;
	float hw;
	float hpz;
	float hpy;
	float hpx;
	float* psp;
	unsigned int attr;
	int wal_n;
	int hit;
	int j;
	int i;
	_anon0 ht;
	_anon0* hp;
	_anon39 l;
	_anon20 pd;
	_anon20* npos;
	// Line 102, Address: 0x25d590, Func Offset: 0
	// Line 120, Address: 0x25d5ec, Func Offset: 0x5c
	// Line 117, Address: 0x25d608, Func Offset: 0x78
	// Line 120, Address: 0x25d60c, Func Offset: 0x7c
	// Line 124, Address: 0x25d624, Func Offset: 0x94
	// Line 120, Address: 0x25d628, Func Offset: 0x98
	// Line 124, Address: 0x25d638, Func Offset: 0xa8
	// Line 123, Address: 0x25d63c, Func Offset: 0xac
	// Line 124, Address: 0x25d640, Func Offset: 0xb0
	// Line 126, Address: 0x25d654, Func Offset: 0xc4
	// Line 125, Address: 0x25d65c, Func Offset: 0xcc
	// Line 126, Address: 0x25d660, Func Offset: 0xd0
	// Line 127, Address: 0x25d680, Func Offset: 0xf0
	// Line 129, Address: 0x25d6a0, Func Offset: 0x110
	// Line 130, Address: 0x25d6ec, Func Offset: 0x15c
	// Line 137, Address: 0x25d6fc, Func Offset: 0x16c
	// Line 131, Address: 0x25d70c, Func Offset: 0x17c
	// Line 137, Address: 0x25d710, Func Offset: 0x180
	// Line 133, Address: 0x25d718, Func Offset: 0x188
	// Line 132, Address: 0x25d71c, Func Offset: 0x18c
	// Line 137, Address: 0x25d720, Func Offset: 0x190
	// Line 141, Address: 0x25d738, Func Offset: 0x1a8
	// Line 139, Address: 0x25d73c, Func Offset: 0x1ac
	// Line 140, Address: 0x25d740, Func Offset: 0x1b0
	// Line 142, Address: 0x25d744, Func Offset: 0x1b4
	// Line 137, Address: 0x25d748, Func Offset: 0x1b8
	// Line 143, Address: 0x25d74c, Func Offset: 0x1bc
	// Line 137, Address: 0x25d754, Func Offset: 0x1c4
	// Line 143, Address: 0x25d760, Func Offset: 0x1d0
	// Line 144, Address: 0x25d778, Func Offset: 0x1e8
	// Line 146, Address: 0x25d7a4, Func Offset: 0x214
	// Line 147, Address: 0x25d7a8, Func Offset: 0x218
	// Line 152, Address: 0x25d828, Func Offset: 0x298
	// Line 158, Address: 0x25d830, Func Offset: 0x2a0
	// Line 152, Address: 0x25d834, Func Offset: 0x2a4
	// Line 153, Address: 0x25d83c, Func Offset: 0x2ac
	// Line 154, Address: 0x25d840, Func Offset: 0x2b0
	// Line 153, Address: 0x25d844, Func Offset: 0x2b4
	// Line 158, Address: 0x25d848, Func Offset: 0x2b8
	// Line 155, Address: 0x25d850, Func Offset: 0x2c0
	// Line 156, Address: 0x25d854, Func Offset: 0x2c4
	// Line 158, Address: 0x25d858, Func Offset: 0x2c8
	// Line 162, Address: 0x25d8cc, Func Offset: 0x33c
	// Line 163, Address: 0x25d8dc, Func Offset: 0x34c
	// Line 165, Address: 0x25d8ec, Func Offset: 0x35c
	// Line 166, Address: 0x25d8f8, Func Offset: 0x368
	// Line 167, Address: 0x25d904, Func Offset: 0x374
	// Line 169, Address: 0x25d924, Func Offset: 0x394
	// Line 170, Address: 0x25d928, Func Offset: 0x398
	// Line 169, Address: 0x25d92c, Func Offset: 0x39c
	// Line 170, Address: 0x25d930, Func Offset: 0x3a0
	// Line 171, Address: 0x25d934, Func Offset: 0x3a4
	// Line 172, Address: 0x25d940, Func Offset: 0x3b0
	// Line 173, Address: 0x25d950, Func Offset: 0x3c0
	// Line 175, Address: 0x25d970, Func Offset: 0x3e0
	// Line 176, Address: 0x25d980, Func Offset: 0x3f0
	// Line 177, Address: 0x25d990, Func Offset: 0x400
	// Line 184, Address: 0x25d9a0, Func Offset: 0x410
	// Line 186, Address: 0x25d9a8, Func Offset: 0x418
	// Line 188, Address: 0x25d9b8, Func Offset: 0x428
	// Line 191, Address: 0x25d9c0, Func Offset: 0x430
	// Line 193, Address: 0x25d9c8, Func Offset: 0x438
	// Line 194, Address: 0x25d9d4, Func Offset: 0x444
	// Line 195, Address: 0x25d9e4, Func Offset: 0x454
	// Line 197, Address: 0x25da04, Func Offset: 0x474
	// Line 198, Address: 0x25da08, Func Offset: 0x478
	// Line 197, Address: 0x25da10, Func Offset: 0x480
	// Line 198, Address: 0x25da14, Func Offset: 0x484
	// Line 199, Address: 0x25da18, Func Offset: 0x488
	// Line 200, Address: 0x25da24, Func Offset: 0x494
	// Line 201, Address: 0x25da34, Func Offset: 0x4a4
	// Line 203, Address: 0x25da54, Func Offset: 0x4c4
	// Line 204, Address: 0x25da64, Func Offset: 0x4d4
	// Line 205, Address: 0x25da74, Func Offset: 0x4e4
	// Line 210, Address: 0x25da84, Func Offset: 0x4f4
	// Line 212, Address: 0x25da88, Func Offset: 0x4f8
	// Line 214, Address: 0x25da90, Func Offset: 0x500
	// Line 216, Address: 0x25daa0, Func Offset: 0x510
	// Line 220, Address: 0x25daa8, Func Offset: 0x518
	// Line 221, Address: 0x25dab0, Func Offset: 0x520
	// Line 223, Address: 0x25dac0, Func Offset: 0x530
	// Line 224, Address: 0x25dad0, Func Offset: 0x540
	// Line 225, Address: 0x25dadc, Func Offset: 0x54c
	// Line 227, Address: 0x25dafc, Func Offset: 0x56c
	// Line 228, Address: 0x25db00, Func Offset: 0x570
	// Line 227, Address: 0x25db04, Func Offset: 0x574
	// Line 228, Address: 0x25db0c, Func Offset: 0x57c
	// Line 229, Address: 0x25db10, Func Offset: 0x580
	// Line 230, Address: 0x25db1c, Func Offset: 0x58c
	// Line 231, Address: 0x25db2c, Func Offset: 0x59c
	// Line 233, Address: 0x25db4c, Func Offset: 0x5bc
	// Line 234, Address: 0x25db5c, Func Offset: 0x5cc
	// Line 235, Address: 0x25db6c, Func Offset: 0x5dc
	// Line 240, Address: 0x25db7c, Func Offset: 0x5ec
	// Line 242, Address: 0x25db80, Func Offset: 0x5f0
	// Line 244, Address: 0x25db88, Func Offset: 0x5f8
	// Line 246, Address: 0x25db98, Func Offset: 0x608
	// Line 249, Address: 0x25dba0, Func Offset: 0x610
	// Line 251, Address: 0x25dba8, Func Offset: 0x618
	// Line 252, Address: 0x25dbb4, Func Offset: 0x624
	// Line 251, Address: 0x25dbb8, Func Offset: 0x628
	// Line 252, Address: 0x25dbbc, Func Offset: 0x62c
	// Line 253, Address: 0x25dbc8, Func Offset: 0x638
	// Line 255, Address: 0x25dbe8, Func Offset: 0x658
	// Line 256, Address: 0x25dbec, Func Offset: 0x65c
	// Line 255, Address: 0x25dbf0, Func Offset: 0x660
	// Line 256, Address: 0x25dbf4, Func Offset: 0x664
	// Line 255, Address: 0x25dbf8, Func Offset: 0x668
	// Line 256, Address: 0x25dbfc, Func Offset: 0x66c
	// Line 257, Address: 0x25dc00, Func Offset: 0x670
	// Line 258, Address: 0x25dc0c, Func Offset: 0x67c
	// Line 259, Address: 0x25dc1c, Func Offset: 0x68c
	// Line 261, Address: 0x25dc3c, Func Offset: 0x6ac
	// Line 262, Address: 0x25dc4c, Func Offset: 0x6bc
	// Line 263, Address: 0x25dc5c, Func Offset: 0x6cc
	// Line 268, Address: 0x25dc6c, Func Offset: 0x6dc
	// Line 270, Address: 0x25dc70, Func Offset: 0x6e0
	// Line 272, Address: 0x25dc78, Func Offset: 0x6e8
	// Line 274, Address: 0x25dc88, Func Offset: 0x6f8
	// Line 280, Address: 0x25dc90, Func Offset: 0x700
	// Line 283, Address: 0x25dc98, Func Offset: 0x708
	// Line 288, Address: 0x25dd34, Func Offset: 0x7a4
	// Line 289, Address: 0x25dd38, Func Offset: 0x7a8
	// Line 290, Address: 0x25dd3c, Func Offset: 0x7ac
	// Line 289, Address: 0x25dd40, Func Offset: 0x7b0
	// Line 290, Address: 0x25dd44, Func Offset: 0x7b4
	// Line 291, Address: 0x25dd48, Func Offset: 0x7b8
	// Line 292, Address: 0x25dd54, Func Offset: 0x7c4
	// Line 296, Address: 0x25dd94, Func Offset: 0x804
	// Line 303, Address: 0x25ddc8, Func Offset: 0x838
	// Line 304, Address: 0x25ddd8, Func Offset: 0x848
	// Line 306, Address: 0x25dddc, Func Offset: 0x84c
	// Line 315, Address: 0x25dde0, Func Offset: 0x850
	// Line 304, Address: 0x25dde4, Func Offset: 0x854
	// Line 305, Address: 0x25ddec, Func Offset: 0x85c
	// Line 306, Address: 0x25ddf0, Func Offset: 0x860
	// Line 312, Address: 0x25ddfc, Func Offset: 0x86c
	// Line 313, Address: 0x25de00, Func Offset: 0x870
	// Line 315, Address: 0x25de04, Func Offset: 0x874
	// Line 316, Address: 0x25de0c, Func Offset: 0x87c
	// Line 317, Address: 0x25de18, Func Offset: 0x888
	// Line 318, Address: 0x25de30, Func Offset: 0x8a0
	// Line 320, Address: 0x25de44, Func Offset: 0x8b4
	// Line 321, Address: 0x25de58, Func Offset: 0x8c8
	// Line 324, Address: 0x25de68, Func Offset: 0x8d8
	// Line 321, Address: 0x25de70, Func Offset: 0x8e0
	// Line 322, Address: 0x25de74, Func Offset: 0x8e4
	// Line 324, Address: 0x25de78, Func Offset: 0x8e8
	// Line 321, Address: 0x25de7c, Func Offset: 0x8ec
	// Line 322, Address: 0x25de84, Func Offset: 0x8f4
	// Line 324, Address: 0x25de8c, Func Offset: 0x8fc
	// Line 322, Address: 0x25de90, Func Offset: 0x900
	// Line 324, Address: 0x25de98, Func Offset: 0x908
	// Line 325, Address: 0x25deb0, Func Offset: 0x920
	// Line 326, Address: 0x25ded8, Func Offset: 0x948
	// Line 325, Address: 0x25dedc, Func Offset: 0x94c
	// Line 326, Address: 0x25dee4, Func Offset: 0x954
	// Line 329, Address: 0x25def0, Func Offset: 0x960
	// Line 332, Address: 0x25df10, Func Offset: 0x980
	// Line 333, Address: 0x25df20, Func Offset: 0x990
	// Line 334, Address: 0x25df30, Func Offset: 0x9a0
	// Line 340, Address: 0x25df3c, Func Offset: 0x9ac
	// Line 343, Address: 0x25df44, Func Offset: 0x9b4
	// Line 349, Address: 0x25dfc0, Func Offset: 0xa30
	// Line 351, Address: 0x25dfdc, Func Offset: 0xa4c
	// Line 352, Address: 0x25dfe4, Func Offset: 0xa54
	// Line 354, Address: 0x25e01c, Func Offset: 0xa8c
	// Line 356, Address: 0x25e020, Func Offset: 0xa90
	// Line 358, Address: 0x25e028, Func Offset: 0xa98
	// Line 360, Address: 0x25e02c, Func Offset: 0xa9c
	// Line 362, Address: 0x25e034, Func Offset: 0xaa4
	// Line 364, Address: 0x25e038, Func Offset: 0xaa8
	// Line 366, Address: 0x25e040, Func Offset: 0xab0
	// Line 367, Address: 0x25e044, Func Offset: 0xab4
	// Line 371, Address: 0x25e048, Func Offset: 0xab8
	// Line 370, Address: 0x25e04c, Func Offset: 0xabc
	// Line 374, Address: 0x25e050, Func Offset: 0xac0
	// Line 371, Address: 0x25e054, Func Offset: 0xac4
	// Line 374, Address: 0x25e058, Func Offset: 0xac8
	// Line 373, Address: 0x25e05c, Func Offset: 0xacc
	// Line 372, Address: 0x25e060, Func Offset: 0xad0
	// Line 374, Address: 0x25e064, Func Offset: 0xad4
	// Line 375, Address: 0x25e070, Func Offset: 0xae0
	// Line 376, Address: 0x25e078, Func Offset: 0xae8
	// Line 377, Address: 0x25e07c, Func Offset: 0xaec
	// Line 380, Address: 0x25e084, Func Offset: 0xaf4
	// Line 383, Address: 0x25e0bc, Func Offset: 0xb2c
	// Line 384, Address: 0x25e0c0, Func Offset: 0xb30
	// Line 386, Address: 0x25e0c4, Func Offset: 0xb34
	// Line 389, Address: 0x25e0c8, Func Offset: 0xb38
	// Line 385, Address: 0x25e0cc, Func Offset: 0xb3c
	// Line 387, Address: 0x25e0d0, Func Offset: 0xb40
	// Line 389, Address: 0x25e0d4, Func Offset: 0xb44
	// Line 386, Address: 0x25e0d8, Func Offset: 0xb48
	// Line 388, Address: 0x25e0dc, Func Offset: 0xb4c
	// Line 387, Address: 0x25e0e0, Func Offset: 0xb50
	// Line 389, Address: 0x25e0e4, Func Offset: 0xb54
	// Line 390, Address: 0x25e100, Func Offset: 0xb70
	// Line 392, Address: 0x25e108, Func Offset: 0xb78
	// Line 393, Address: 0x25e10c, Func Offset: 0xb7c
	// Line 395, Address: 0x25e110, Func Offset: 0xb80
	// Line 397, Address: 0x25e134, Func Offset: 0xba4
	// Line 402, Address: 0x25e13c, Func Offset: 0xbac
	// Line 400, Address: 0x25e140, Func Offset: 0xbb0
	// Line 402, Address: 0x25e144, Func Offset: 0xbb4
	// Line 401, Address: 0x25e148, Func Offset: 0xbb8
	// Line 402, Address: 0x25e14c, Func Offset: 0xbbc
	// Line 403, Address: 0x25e150, Func Offset: 0xbc0
	// Line 405, Address: 0x25e154, Func Offset: 0xbc4
	// Line 404, Address: 0x25e158, Func Offset: 0xbc8
	// Line 406, Address: 0x25e15c, Func Offset: 0xbcc
	// Line 403, Address: 0x25e160, Func Offset: 0xbd0
	// Line 405, Address: 0x25e164, Func Offset: 0xbd4
	// Line 406, Address: 0x25e168, Func Offset: 0xbd8
	// Line 404, Address: 0x25e16c, Func Offset: 0xbdc
	// Line 406, Address: 0x25e170, Func Offset: 0xbe0
	// Line 405, Address: 0x25e178, Func Offset: 0xbe8
	// Line 406, Address: 0x25e17c, Func Offset: 0xbec
	// Line 407, Address: 0x25e18c, Func Offset: 0xbfc
	// Line 409, Address: 0x25e190, Func Offset: 0xc00
	// Line 413, Address: 0x25e194, Func Offset: 0xc04
	// Line 409, Address: 0x25e198, Func Offset: 0xc08
	// Line 413, Address: 0x25e19c, Func Offset: 0xc0c
	// Line 409, Address: 0x25e1a4, Func Offset: 0xc14
	// Line 410, Address: 0x25e1a8, Func Offset: 0xc18
	// Line 411, Address: 0x25e1ac, Func Offset: 0xc1c
	// Line 413, Address: 0x25e1b0, Func Offset: 0xc20
	// Line 415, Address: 0x25e1c8, Func Offset: 0xc38
	// Line 418, Address: 0x25e1d0, Func Offset: 0xc40
	// Line 421, Address: 0x25e1dc, Func Offset: 0xc4c
	// Line 422, Address: 0x25e1e0, Func Offset: 0xc50
	// Line 424, Address: 0x25e1e4, Func Offset: 0xc54
	// Line 418, Address: 0x25e1e8, Func Offset: 0xc58
	// Line 419, Address: 0x25e1ec, Func Offset: 0xc5c
	// Line 420, Address: 0x25e1f0, Func Offset: 0xc60
	// Line 421, Address: 0x25e1f4, Func Offset: 0xc64
	// Line 423, Address: 0x25e1f8, Func Offset: 0xc68
	// Line 424, Address: 0x25e1fc, Func Offset: 0xc6c
	// Line 422, Address: 0x25e200, Func Offset: 0xc70
	// Line 424, Address: 0x25e204, Func Offset: 0xc74
	// Line 425, Address: 0x25e21c, Func Offset: 0xc8c
	// Line 427, Address: 0x25e220, Func Offset: 0xc90
	// Line 431, Address: 0x25e224, Func Offset: 0xc94
	// Line 427, Address: 0x25e230, Func Offset: 0xca0
	// Line 428, Address: 0x25e234, Func Offset: 0xca4
	// Line 429, Address: 0x25e23c, Func Offset: 0xcac
	// Line 431, Address: 0x25e240, Func Offset: 0xcb0
	// Line 433, Address: 0x25e258, Func Offset: 0xcc8
	// Line 436, Address: 0x25e260, Func Offset: 0xcd0
	// Line 438, Address: 0x25e26c, Func Offset: 0xcdc
	// Line 439, Address: 0x25e270, Func Offset: 0xce0
	// Line 442, Address: 0x25e274, Func Offset: 0xce4
	// Line 436, Address: 0x25e278, Func Offset: 0xce8
	// Line 438, Address: 0x25e27c, Func Offset: 0xcec
	// Line 437, Address: 0x25e280, Func Offset: 0xcf0
	// Line 440, Address: 0x25e284, Func Offset: 0xcf4
	// Line 438, Address: 0x25e288, Func Offset: 0xcf8
	// Line 439, Address: 0x25e28c, Func Offset: 0xcfc
	// Line 441, Address: 0x25e290, Func Offset: 0xd00
	// Line 440, Address: 0x25e298, Func Offset: 0xd08
	// Line 442, Address: 0x25e29c, Func Offset: 0xd0c
	// Line 443, Address: 0x25e2b8, Func Offset: 0xd28
	// Line 446, Address: 0x25e2c0, Func Offset: 0xd30
	// Line 445, Address: 0x25e2c4, Func Offset: 0xd34
	// Line 450, Address: 0x25e2cc, Func Offset: 0xd3c
	// Line 446, Address: 0x25e2d0, Func Offset: 0xd40
	// Line 445, Address: 0x25e2d4, Func Offset: 0xd44
	// Line 450, Address: 0x25e2d8, Func Offset: 0xd48
	// Line 447, Address: 0x25e2dc, Func Offset: 0xd4c
	// Line 446, Address: 0x25e2e0, Func Offset: 0xd50
	// Line 447, Address: 0x25e2e4, Func Offset: 0xd54
	// Line 448, Address: 0x25e2e8, Func Offset: 0xd58
	// Line 450, Address: 0x25e2ec, Func Offset: 0xd5c
	// Line 456, Address: 0x25e308, Func Offset: 0xd78
	// Line 458, Address: 0x25e310, Func Offset: 0xd80
	// Line 483, Address: 0x25e3a0, Func Offset: 0xe10
	// Line 485, Address: 0x25e3d8, Func Offset: 0xe48
	// Line 486, Address: 0x25e3dc, Func Offset: 0xe4c
	// Line 487, Address: 0x25e3e0, Func Offset: 0xe50
	// Line 488, Address: 0x25e3e8, Func Offset: 0xe58
	// Line 489, Address: 0x25e3ec, Func Offset: 0xe5c
	// Line 491, Address: 0x25e3f0, Func Offset: 0xe60
	// Line 495, Address: 0x25e3f8, Func Offset: 0xe68
	// Line 493, Address: 0x25e3fc, Func Offset: 0xe6c
	// Line 494, Address: 0x25e400, Func Offset: 0xe70
	// Line 495, Address: 0x25e404, Func Offset: 0xe74
	// Line 496, Address: 0x25e408, Func Offset: 0xe78
	// Line 497, Address: 0x25e40c, Func Offset: 0xe7c
	// Line 498, Address: 0x25e410, Func Offset: 0xe80
	// Line 499, Address: 0x25e414, Func Offset: 0xe84
	// Line 501, Address: 0x25e41c, Func Offset: 0xe8c
	// Line 502, Address: 0x25e420, Func Offset: 0xe90
	// Line 503, Address: 0x25e424, Func Offset: 0xe94
	// Line 504, Address: 0x25e428, Func Offset: 0xe98
	// Line 505, Address: 0x25e42c, Func Offset: 0xe9c
	// Line 507, Address: 0x25e430, Func Offset: 0xea0
	// Line 509, Address: 0x25e438, Func Offset: 0xea8
	// Line 510, Address: 0x25e440, Func Offset: 0xeb0
	// Line 511, Address: 0x25e444, Func Offset: 0xeb4
	// Line 512, Address: 0x25e448, Func Offset: 0xeb8
	// Line 511, Address: 0x25e44c, Func Offset: 0xebc
	// Line 512, Address: 0x25e450, Func Offset: 0xec0
	// Line 513, Address: 0x25e454, Func Offset: 0xec4
	// Line 514, Address: 0x25e458, Func Offset: 0xec8
	// Line 516, Address: 0x25e45c, Func Offset: 0xecc
	// Line 517, Address: 0x25e460, Func Offset: 0xed0
	// Line 518, Address: 0x25e470, Func Offset: 0xee0
	// Line 519, Address: 0x25e474, Func Offset: 0xee4
	// Line 518, Address: 0x25e47c, Func Offset: 0xeec
	// Line 520, Address: 0x25e480, Func Offset: 0xef0
	// Line 522, Address: 0x25e4e0, Func Offset: 0xf50
	// Line 524, Address: 0x25e4e8, Func Offset: 0xf58
	// Line 525, Address: 0x25e4f8, Func Offset: 0xf68
	// Line 526, Address: 0x25e508, Func Offset: 0xf78
	// Line 527, Address: 0x25e530, Func Offset: 0xfa0
	// Line 528, Address: 0x25e538, Func Offset: 0xfa8
	// Line 529, Address: 0x25e53c, Func Offset: 0xfac
	// Line 532, Address: 0x25e544, Func Offset: 0xfb4
	// Line 533, Address: 0x25e54c, Func Offset: 0xfbc
	// Line 535, Address: 0x25e550, Func Offset: 0xfc0
	// Line 533, Address: 0x25e554, Func Offset: 0xfc4
	// Line 534, Address: 0x25e558, Func Offset: 0xfc8
	// Line 535, Address: 0x25e560, Func Offset: 0xfd0
	// Line 541, Address: 0x25e588, Func Offset: 0xff8
	// Line 543, Address: 0x25e590, Func Offset: 0x1000
	// Line 544, Address: 0x25e5ac, Func Offset: 0x101c
	// Line 545, Address: 0x25e5b0, Func Offset: 0x1020
	// Line 551, Address: 0x25e5b8, Func Offset: 0x1028
	// Line 545, Address: 0x25e5bc, Func Offset: 0x102c
	// Line 547, Address: 0x25e5c4, Func Offset: 0x1034
	// Line 546, Address: 0x25e5c8, Func Offset: 0x1038
	// Line 551, Address: 0x25e5cc, Func Offset: 0x103c
	// Line 546, Address: 0x25e5d8, Func Offset: 0x1048
	// Line 548, Address: 0x25e5dc, Func Offset: 0x104c
	// Line 549, Address: 0x25e5e0, Func Offset: 0x1050
	// Line 551, Address: 0x25e5e4, Func Offset: 0x1054
	// Line 560, Address: 0x25e6f8, Func Offset: 0x1168
	// Line 561, Address: 0x25e708, Func Offset: 0x1178
	// Line 563, Address: 0x25e71c, Func Offset: 0x118c
	// Line 565, Address: 0x25e744, Func Offset: 0x11b4
	// Line 568, Address: 0x25e74c, Func Offset: 0x11bc
	// Line 570, Address: 0x25e754, Func Offset: 0x11c4
	// Line 572, Address: 0x25e780, Func Offset: 0x11f0
	// Line 576, Address: 0x25e788, Func Offset: 0x11f8
	// Line 577, Address: 0x25e790, Func Offset: 0x1200
	// Line 579, Address: 0x25e7a4, Func Offset: 0x1214
	// Line 581, Address: 0x25e7d0, Func Offset: 0x1240
	// Line 584, Address: 0x25e7d8, Func Offset: 0x1248
	// Line 586, Address: 0x25e7e0, Func Offset: 0x1250
	// Line 588, Address: 0x25e810, Func Offset: 0x1280
	// Line 589, Address: 0x25e818, Func Offset: 0x1288
	// Line 596, Address: 0x25e81c, Func Offset: 0x128c
	// Line 597, Address: 0x25e838, Func Offset: 0x12a8
	// Line 598, Address: 0x25e84c, Func Offset: 0x12bc
	// Line 599, Address: 0x25e864, Func Offset: 0x12d4
	// Line 601, Address: 0x25e880, Func Offset: 0x12f0
	// Line 605, Address: 0x25e8c4, Func Offset: 0x1334
	// Func End, Address: 0x25e924, Func Offset: 0x1394
}

// 
// Start address: 0x25e930
int bhCheckWallEx(BH_PWORK* pw, _anon20* npos, _anon20* opos, float par, float pah)
{
	float inn;
	_anon20 vec1;
	_anon20 vec0;
	int ayp;
	int r;
	float pzz;
	float pxx;
	float abz;
	float abx;
	float wpz;
	float wpx;
	float ln;
	float zn;
	float xn;
	float pz;
	float px;
	float hd;
	float hh;
	float hw;
	float hpz;
	float hpy;
	float hpx;
	float* psp;
	unsigned int attr;
	int pcflg;
	int wal_n;
	int hit;
	int j;
	int i;
	_anon0 ht;
	_anon0* hp;
	_anon39 l;
	_anon20 pd;
	// Line 622, Address: 0x25e930, Func Offset: 0
	// Line 636, Address: 0x25e98c, Func Offset: 0x5c
	// Line 638, Address: 0x25e9b8, Func Offset: 0x88
	// Line 637, Address: 0x25e9c0, Func Offset: 0x90
	// Line 638, Address: 0x25e9c4, Func Offset: 0x94
	// Line 639, Address: 0x25e9e4, Func Offset: 0xb4
	// Line 641, Address: 0x25ea08, Func Offset: 0xd8
	// Line 642, Address: 0x25ea50, Func Offset: 0x120
	// Line 649, Address: 0x25ea60, Func Offset: 0x130
	// Line 651, Address: 0x25ea64, Func Offset: 0x134
	// Line 645, Address: 0x25ea68, Func Offset: 0x138
	// Line 646, Address: 0x25ea6c, Func Offset: 0x13c
	// Line 647, Address: 0x25ea70, Func Offset: 0x140
	// Line 648, Address: 0x25ea74, Func Offset: 0x144
	// Line 650, Address: 0x25ea78, Func Offset: 0x148
	// Line 651, Address: 0x25ea7c, Func Offset: 0x14c
	// Line 652, Address: 0x25ea98, Func Offset: 0x168
	// Line 655, Address: 0x25eac0, Func Offset: 0x190
	// Line 660, Address: 0x25eb40, Func Offset: 0x210
	// Line 666, Address: 0x25eb48, Func Offset: 0x218
	// Line 660, Address: 0x25eb4c, Func Offset: 0x21c
	// Line 661, Address: 0x25eb58, Func Offset: 0x228
	// Line 662, Address: 0x25eb5c, Func Offset: 0x22c
	// Line 661, Address: 0x25eb60, Func Offset: 0x230
	// Line 666, Address: 0x25eb64, Func Offset: 0x234
	// Line 661, Address: 0x25eb68, Func Offset: 0x238
	// Line 664, Address: 0x25eb6c, Func Offset: 0x23c
	// Line 666, Address: 0x25eb70, Func Offset: 0x240
	// Line 663, Address: 0x25eb74, Func Offset: 0x244
	// Line 664, Address: 0x25eb78, Func Offset: 0x248
	// Line 666, Address: 0x25eb7c, Func Offset: 0x24c
	// Line 671, Address: 0x25ebf0, Func Offset: 0x2c0
	// Line 673, Address: 0x25ec0c, Func Offset: 0x2dc
	// Line 675, Address: 0x25ec14, Func Offset: 0x2e4
	// Line 673, Address: 0x25ec18, Func Offset: 0x2e8
	// Line 675, Address: 0x25ec20, Func Offset: 0x2f0
	// Line 677, Address: 0x25ec54, Func Offset: 0x324
	// Line 678, Address: 0x25ec60, Func Offset: 0x330
	// Line 680, Address: 0x25ec68, Func Offset: 0x338
	// Line 681, Address: 0x25ec74, Func Offset: 0x344
	// Line 683, Address: 0x25ec7c, Func Offset: 0x34c
	// Line 684, Address: 0x25ec88, Func Offset: 0x358
	// Line 686, Address: 0x25ec90, Func Offset: 0x360
	// Line 688, Address: 0x25eca4, Func Offset: 0x374
	// Line 689, Address: 0x25eca8, Func Offset: 0x378
	// Line 691, Address: 0x25ecb0, Func Offset: 0x380
	// Line 693, Address: 0x25ecb8, Func Offset: 0x388
	// Line 694, Address: 0x25ecc0, Func Offset: 0x390
	// Line 695, Address: 0x25eccc, Func Offset: 0x39c
	// Line 694, Address: 0x25ecd0, Func Offset: 0x3a0
	// Line 695, Address: 0x25ece0, Func Offset: 0x3b0
	// Line 700, Address: 0x25ece8, Func Offset: 0x3b8
	// Line 695, Address: 0x25ecec, Func Offset: 0x3bc
	// Line 700, Address: 0x25ecf0, Func Offset: 0x3c0
	// Line 702, Address: 0x25ed38, Func Offset: 0x408
	// Line 703, Address: 0x25ed40, Func Offset: 0x410
	// Line 705, Address: 0x25ed4c, Func Offset: 0x41c
	// Line 706, Address: 0x25ed50, Func Offset: 0x420
	// Line 708, Address: 0x25ed70, Func Offset: 0x440
	// Line 709, Address: 0x25ed7c, Func Offset: 0x44c
	// Line 711, Address: 0x25ed80, Func Offset: 0x450
	// Line 712, Address: 0x25ed98, Func Offset: 0x468
	// Line 714, Address: 0x25edb0, Func Offset: 0x480
	// Line 715, Address: 0x25edc0, Func Offset: 0x490
	// Line 716, Address: 0x25edcc, Func Offset: 0x49c
	// Line 718, Address: 0x25edec, Func Offset: 0x4bc
	// Line 719, Address: 0x25edf0, Func Offset: 0x4c0
	// Line 718, Address: 0x25edf4, Func Offset: 0x4c4
	// Line 719, Address: 0x25edf8, Func Offset: 0x4c8
	// Line 720, Address: 0x25edfc, Func Offset: 0x4cc
	// Line 721, Address: 0x25ee08, Func Offset: 0x4d8
	// Line 722, Address: 0x25ee18, Func Offset: 0x4e8
	// Line 724, Address: 0x25ee34, Func Offset: 0x504
	// Line 725, Address: 0x25ee44, Func Offset: 0x514
	// Line 726, Address: 0x25ee54, Func Offset: 0x524
	// Line 731, Address: 0x25ee64, Func Offset: 0x534
	// Line 733, Address: 0x25ee68, Func Offset: 0x538
	// Line 735, Address: 0x25ee70, Func Offset: 0x540
	// Line 736, Address: 0x25ee80, Func Offset: 0x550
	// Line 737, Address: 0x25ee8c, Func Offset: 0x55c
	// Line 739, Address: 0x25ee9c, Func Offset: 0x56c
	// Line 742, Address: 0x25eea4, Func Offset: 0x574
	// Line 744, Address: 0x25eeac, Func Offset: 0x57c
	// Line 745, Address: 0x25eebc, Func Offset: 0x58c
	// Line 746, Address: 0x25eecc, Func Offset: 0x59c
	// Line 748, Address: 0x25eeec, Func Offset: 0x5bc
	// Line 749, Address: 0x25eef0, Func Offset: 0x5c0
	// Line 748, Address: 0x25eef8, Func Offset: 0x5c8
	// Line 749, Address: 0x25eefc, Func Offset: 0x5cc
	// Line 750, Address: 0x25ef00, Func Offset: 0x5d0
	// Line 751, Address: 0x25ef0c, Func Offset: 0x5dc
	// Line 752, Address: 0x25ef1c, Func Offset: 0x5ec
	// Line 754, Address: 0x25ef38, Func Offset: 0x608
	// Line 755, Address: 0x25ef48, Func Offset: 0x618
	// Line 756, Address: 0x25ef58, Func Offset: 0x628
	// Line 763, Address: 0x25ef68, Func Offset: 0x638
	// Line 765, Address: 0x25ef70, Func Offset: 0x640
	// Line 766, Address: 0x25ef80, Func Offset: 0x650
	// Line 767, Address: 0x25ef8c, Func Offset: 0x65c
	// Line 769, Address: 0x25ef9c, Func Offset: 0x66c
	// Line 773, Address: 0x25efa4, Func Offset: 0x674
	// Line 774, Address: 0x25efac, Func Offset: 0x67c
	// Line 776, Address: 0x25efc4, Func Offset: 0x694
	// Line 777, Address: 0x25efdc, Func Offset: 0x6ac
	// Line 778, Address: 0x25efe8, Func Offset: 0x6b8
	// Line 780, Address: 0x25f008, Func Offset: 0x6d8
	// Line 781, Address: 0x25f00c, Func Offset: 0x6dc
	// Line 780, Address: 0x25f010, Func Offset: 0x6e0
	// Line 781, Address: 0x25f018, Func Offset: 0x6e8
	// Line 782, Address: 0x25f01c, Func Offset: 0x6ec
	// Line 783, Address: 0x25f028, Func Offset: 0x6f8
	// Line 784, Address: 0x25f038, Func Offset: 0x708
	// Line 786, Address: 0x25f054, Func Offset: 0x724
	// Line 787, Address: 0x25f064, Func Offset: 0x734
	// Line 788, Address: 0x25f074, Func Offset: 0x744
	// Line 793, Address: 0x25f084, Func Offset: 0x754
	// Line 795, Address: 0x25f088, Func Offset: 0x758
	// Line 797, Address: 0x25f090, Func Offset: 0x760
	// Line 798, Address: 0x25f0a0, Func Offset: 0x770
	// Line 799, Address: 0x25f0ac, Func Offset: 0x77c
	// Line 801, Address: 0x25f0bc, Func Offset: 0x78c
	// Line 804, Address: 0x25f0c4, Func Offset: 0x794
	// Line 806, Address: 0x25f0cc, Func Offset: 0x79c
	// Line 807, Address: 0x25f0e0, Func Offset: 0x7b0
	// Line 806, Address: 0x25f0e4, Func Offset: 0x7b4
	// Line 807, Address: 0x25f0e8, Func Offset: 0x7b8
	// Line 808, Address: 0x25f0f4, Func Offset: 0x7c4
	// Line 810, Address: 0x25f114, Func Offset: 0x7e4
	// Line 811, Address: 0x25f118, Func Offset: 0x7e8
	// Line 810, Address: 0x25f11c, Func Offset: 0x7ec
	// Line 811, Address: 0x25f120, Func Offset: 0x7f0
	// Line 810, Address: 0x25f124, Func Offset: 0x7f4
	// Line 811, Address: 0x25f128, Func Offset: 0x7f8
	// Line 812, Address: 0x25f12c, Func Offset: 0x7fc
	// Line 813, Address: 0x25f138, Func Offset: 0x808
	// Line 814, Address: 0x25f148, Func Offset: 0x818
	// Line 816, Address: 0x25f164, Func Offset: 0x834
	// Line 817, Address: 0x25f174, Func Offset: 0x844
	// Line 818, Address: 0x25f184, Func Offset: 0x854
	// Line 823, Address: 0x25f194, Func Offset: 0x864
	// Line 825, Address: 0x25f198, Func Offset: 0x868
	// Line 827, Address: 0x25f1a0, Func Offset: 0x870
	// Line 828, Address: 0x25f1b0, Func Offset: 0x880
	// Line 829, Address: 0x25f1bc, Func Offset: 0x88c
	// Line 831, Address: 0x25f1cc, Func Offset: 0x89c
	// Line 837, Address: 0x25f1d4, Func Offset: 0x8a4
	// Line 840, Address: 0x25f1dc, Func Offset: 0x8ac
	// Line 845, Address: 0x25f274, Func Offset: 0x944
	// Line 846, Address: 0x25f278, Func Offset: 0x948
	// Line 847, Address: 0x25f27c, Func Offset: 0x94c
	// Line 846, Address: 0x25f280, Func Offset: 0x950
	// Line 847, Address: 0x25f284, Func Offset: 0x954
	// Line 848, Address: 0x25f288, Func Offset: 0x958
	// Line 849, Address: 0x25f294, Func Offset: 0x964
	// Line 853, Address: 0x25f2d0, Func Offset: 0x9a0
	// Line 860, Address: 0x25f304, Func Offset: 0x9d4
	// Line 861, Address: 0x25f314, Func Offset: 0x9e4
	// Line 872, Address: 0x25f318, Func Offset: 0x9e8
	// Line 861, Address: 0x25f31c, Func Offset: 0x9ec
	// Line 862, Address: 0x25f324, Func Offset: 0x9f4
	// Line 863, Address: 0x25f328, Func Offset: 0x9f8
	// Line 869, Address: 0x25f334, Func Offset: 0xa04
	// Line 870, Address: 0x25f338, Func Offset: 0xa08
	// Line 872, Address: 0x25f33c, Func Offset: 0xa0c
	// Line 873, Address: 0x25f344, Func Offset: 0xa14
	// Line 874, Address: 0x25f350, Func Offset: 0xa20
	// Line 875, Address: 0x25f368, Func Offset: 0xa38
	// Line 877, Address: 0x25f37c, Func Offset: 0xa4c
	// Line 878, Address: 0x25f388, Func Offset: 0xa58
	// Line 881, Address: 0x25f398, Func Offset: 0xa68
	// Line 878, Address: 0x25f3a0, Func Offset: 0xa70
	// Line 879, Address: 0x25f3a4, Func Offset: 0xa74
	// Line 881, Address: 0x25f3a8, Func Offset: 0xa78
	// Line 878, Address: 0x25f3ac, Func Offset: 0xa7c
	// Line 879, Address: 0x25f3b4, Func Offset: 0xa84
	// Line 881, Address: 0x25f3bc, Func Offset: 0xa8c
	// Line 879, Address: 0x25f3c0, Func Offset: 0xa90
	// Line 881, Address: 0x25f3c8, Func Offset: 0xa98
	// Line 882, Address: 0x25f3e0, Func Offset: 0xab0
	// Line 883, Address: 0x25f404, Func Offset: 0xad4
	// Line 882, Address: 0x25f408, Func Offset: 0xad8
	// Line 883, Address: 0x25f410, Func Offset: 0xae0
	// Line 885, Address: 0x25f41c, Func Offset: 0xaec
	// Line 886, Address: 0x25f420, Func Offset: 0xaf0
	// Line 889, Address: 0x25f440, Func Offset: 0xb10
	// Line 890, Address: 0x25f450, Func Offset: 0xb20
	// Line 891, Address: 0x25f460, Func Offset: 0xb30
	// Line 897, Address: 0x25f46c, Func Offset: 0xb3c
	// Line 900, Address: 0x25f474, Func Offset: 0xb44
	// Line 906, Address: 0x25f4f0, Func Offset: 0xbc0
	// Line 908, Address: 0x25f50c, Func Offset: 0xbdc
	// Line 909, Address: 0x25f514, Func Offset: 0xbe4
	// Line 913, Address: 0x25f54c, Func Offset: 0xc1c
	// Line 917, Address: 0x25f554, Func Offset: 0xc24
	// Line 921, Address: 0x25f55c, Func Offset: 0xc2c
	// Line 923, Address: 0x25f564, Func Offset: 0xc34
	// Line 924, Address: 0x25f568, Func Offset: 0xc38
	// Line 926, Address: 0x25f56c, Func Offset: 0xc3c
	// Line 928, Address: 0x25f570, Func Offset: 0xc40
	// Line 927, Address: 0x25f574, Func Offset: 0xc44
	// Line 931, Address: 0x25f578, Func Offset: 0xc48
	// Line 928, Address: 0x25f57c, Func Offset: 0xc4c
	// Line 931, Address: 0x25f580, Func Offset: 0xc50
	// Line 930, Address: 0x25f584, Func Offset: 0xc54
	// Line 929, Address: 0x25f588, Func Offset: 0xc58
	// Line 931, Address: 0x25f58c, Func Offset: 0xc5c
	// Line 932, Address: 0x25f598, Func Offset: 0xc68
	// Line 933, Address: 0x25f5a0, Func Offset: 0xc70
	// Line 934, Address: 0x25f5a4, Func Offset: 0xc74
	// Line 937, Address: 0x25f5ac, Func Offset: 0xc7c
	// Line 940, Address: 0x25f5dc, Func Offset: 0xcac
	// Line 941, Address: 0x25f5e0, Func Offset: 0xcb0
	// Line 943, Address: 0x25f5e4, Func Offset: 0xcb4
	// Line 946, Address: 0x25f5e8, Func Offset: 0xcb8
	// Line 942, Address: 0x25f5ec, Func Offset: 0xcbc
	// Line 944, Address: 0x25f5f0, Func Offset: 0xcc0
	// Line 946, Address: 0x25f5f4, Func Offset: 0xcc4
	// Line 943, Address: 0x25f5f8, Func Offset: 0xcc8
	// Line 945, Address: 0x25f5fc, Func Offset: 0xccc
	// Line 944, Address: 0x25f600, Func Offset: 0xcd0
	// Line 946, Address: 0x25f604, Func Offset: 0xcd4
	// Line 947, Address: 0x25f620, Func Offset: 0xcf0
	// Line 952, Address: 0x25f628, Func Offset: 0xcf8
	// Line 949, Address: 0x25f62c, Func Offset: 0xcfc
	// Line 950, Address: 0x25f630, Func Offset: 0xd00
	// Line 952, Address: 0x25f634, Func Offset: 0xd04
	// Line 954, Address: 0x25f654, Func Offset: 0xd24
	// Line 957, Address: 0x25f65c, Func Offset: 0xd2c
	// Line 959, Address: 0x25f660, Func Offset: 0xd30
	// Line 958, Address: 0x25f664, Func Offset: 0xd34
	// Line 959, Address: 0x25f668, Func Offset: 0xd38
	// Line 960, Address: 0x25f66c, Func Offset: 0xd3c
	// Line 962, Address: 0x25f670, Func Offset: 0xd40
	// Line 961, Address: 0x25f674, Func Offset: 0xd44
	// Line 963, Address: 0x25f678, Func Offset: 0xd48
	// Line 960, Address: 0x25f67c, Func Offset: 0xd4c
	// Line 962, Address: 0x25f680, Func Offset: 0xd50
	// Line 963, Address: 0x25f684, Func Offset: 0xd54
	// Line 961, Address: 0x25f688, Func Offset: 0xd58
	// Line 963, Address: 0x25f68c, Func Offset: 0xd5c
	// Line 962, Address: 0x25f694, Func Offset: 0xd64
	// Line 963, Address: 0x25f698, Func Offset: 0xd68
	// Line 964, Address: 0x25f6a8, Func Offset: 0xd78
	// Line 966, Address: 0x25f6b0, Func Offset: 0xd80
	// Line 970, Address: 0x25f6bc, Func Offset: 0xd8c
	// Line 966, Address: 0x25f6c8, Func Offset: 0xd98
	// Line 967, Address: 0x25f6cc, Func Offset: 0xd9c
	// Line 970, Address: 0x25f6d0, Func Offset: 0xda0
	// Line 967, Address: 0x25f6d4, Func Offset: 0xda4
	// Line 968, Address: 0x25f6d8, Func Offset: 0xda8
	// Line 970, Address: 0x25f6dc, Func Offset: 0xdac
	// Line 972, Address: 0x25f6f0, Func Offset: 0xdc0
	// Line 975, Address: 0x25f6f8, Func Offset: 0xdc8
	// Line 979, Address: 0x25f704, Func Offset: 0xdd4
	// Line 980, Address: 0x25f708, Func Offset: 0xdd8
	// Line 981, Address: 0x25f70c, Func Offset: 0xddc
	// Line 975, Address: 0x25f710, Func Offset: 0xde0
	// Line 976, Address: 0x25f714, Func Offset: 0xde4
	// Line 978, Address: 0x25f718, Func Offset: 0xde8
	// Line 981, Address: 0x25f71c, Func Offset: 0xdec
	// Line 977, Address: 0x25f720, Func Offset: 0xdf0
	// Line 978, Address: 0x25f724, Func Offset: 0xdf4
	// Line 979, Address: 0x25f728, Func Offset: 0xdf8
	// Line 981, Address: 0x25f72c, Func Offset: 0xdfc
	// Line 982, Address: 0x25f744, Func Offset: 0xe14
	// Line 984, Address: 0x25f748, Func Offset: 0xe18
	// Line 988, Address: 0x25f74c, Func Offset: 0xe1c
	// Line 984, Address: 0x25f754, Func Offset: 0xe24
	// Line 985, Address: 0x25f758, Func Offset: 0xe28
	// Line 986, Address: 0x25f764, Func Offset: 0xe34
	// Line 988, Address: 0x25f768, Func Offset: 0xe38
	// Line 990, Address: 0x25f784, Func Offset: 0xe54
	// Line 993, Address: 0x25f78c, Func Offset: 0xe5c
	// Line 997, Address: 0x25f798, Func Offset: 0xe68
	// Line 998, Address: 0x25f79c, Func Offset: 0xe6c
	// Line 999, Address: 0x25f7a0, Func Offset: 0xe70
	// Line 993, Address: 0x25f7a4, Func Offset: 0xe74
	// Line 995, Address: 0x25f7a8, Func Offset: 0xe78
	// Line 994, Address: 0x25f7b0, Func Offset: 0xe80
	// Line 995, Address: 0x25f7b4, Func Offset: 0xe84
	// Line 996, Address: 0x25f7b8, Func Offset: 0xe88
	// Line 998, Address: 0x25f7bc, Func Offset: 0xe8c
	// Line 996, Address: 0x25f7c0, Func Offset: 0xe90
	// Line 997, Address: 0x25f7c4, Func Offset: 0xe94
	// Line 999, Address: 0x25f7c8, Func Offset: 0xe98
	// Line 1000, Address: 0x25f7e4, Func Offset: 0xeb4
	// Line 1002, Address: 0x25f7e8, Func Offset: 0xeb8
	// Line 1007, Address: 0x25f7ec, Func Offset: 0xebc
	// Line 1003, Address: 0x25f7f0, Func Offset: 0xec0
	// Line 1002, Address: 0x25f7f8, Func Offset: 0xec8
	// Line 1003, Address: 0x25f7fc, Func Offset: 0xecc
	// Line 1007, Address: 0x25f804, Func Offset: 0xed4
	// Line 1004, Address: 0x25f808, Func Offset: 0xed8
	// Line 1003, Address: 0x25f80c, Func Offset: 0xedc
	// Line 1004, Address: 0x25f810, Func Offset: 0xee0
	// Line 1007, Address: 0x25f814, Func Offset: 0xee4
	// Line 1004, Address: 0x25f818, Func Offset: 0xee8
	// Line 1005, Address: 0x25f81c, Func Offset: 0xeec
	// Line 1007, Address: 0x25f820, Func Offset: 0xef0
	// Line 1013, Address: 0x25f838, Func Offset: 0xf08
	// Line 1079, Address: 0x25f840, Func Offset: 0xf10
	// Line 1080, Address: 0x25f85c, Func Offset: 0xf2c
	// Line 1081, Address: 0x25f860, Func Offset: 0xf30
	// Line 1087, Address: 0x25f868, Func Offset: 0xf38
	// Line 1081, Address: 0x25f86c, Func Offset: 0xf3c
	// Line 1082, Address: 0x25f874, Func Offset: 0xf44
	// Line 1083, Address: 0x25f878, Func Offset: 0xf48
	// Line 1082, Address: 0x25f87c, Func Offset: 0xf4c
	// Line 1087, Address: 0x25f880, Func Offset: 0xf50
	// Line 1084, Address: 0x25f888, Func Offset: 0xf58
	// Line 1085, Address: 0x25f88c, Func Offset: 0xf5c
	// Line 1087, Address: 0x25f890, Func Offset: 0xf60
	// Line 1096, Address: 0x25f9a8, Func Offset: 0x1078
	// Line 1097, Address: 0x25f9bc, Func Offset: 0x108c
	// Line 1099, Address: 0x25f9d0, Func Offset: 0x10a0
	// Line 1101, Address: 0x25f9fc, Func Offset: 0x10cc
	// Line 1104, Address: 0x25fa04, Func Offset: 0x10d4
	// Line 1106, Address: 0x25fa0c, Func Offset: 0x10dc
	// Line 1108, Address: 0x25fa3c, Func Offset: 0x110c
	// Line 1112, Address: 0x25fa44, Func Offset: 0x1114
	// Line 1113, Address: 0x25fa4c, Func Offset: 0x111c
	// Line 1115, Address: 0x25fa60, Func Offset: 0x1130
	// Line 1117, Address: 0x25fa90, Func Offset: 0x1160
	// Line 1120, Address: 0x25fa98, Func Offset: 0x1168
	// Line 1122, Address: 0x25faa0, Func Offset: 0x1170
	// Line 1124, Address: 0x25fad4, Func Offset: 0x11a4
	// Line 1125, Address: 0x25fadc, Func Offset: 0x11ac
	// Line 1132, Address: 0x25fae0, Func Offset: 0x11b0
	// Line 1133, Address: 0x25faf8, Func Offset: 0x11c8
	// Line 1134, Address: 0x25fb0c, Func Offset: 0x11dc
	// Line 1135, Address: 0x25fb24, Func Offset: 0x11f4
	// Line 1137, Address: 0x25fb40, Func Offset: 0x1210
	// Line 1141, Address: 0x25fb84, Func Offset: 0x1254
	// Line 1143, Address: 0x25fb88, Func Offset: 0x1258
	// Func End, Address: 0x25fbec, Func Offset: 0x12bc
}

// 
// Start address: 0x25fbf0
void bhCheckWall2Box(BH_PWORK* pw)
{
	int r;
	float pzz;
	float pxx;
	float abz;
	float abx;
	float h;
	float wpz;
	float wpx;
	float ln;
	float zn;
	float xn;
	float pz;
	float px;
	int wal_n;
	int hit;
	int j;
	int i;
	_anon0 ht;
	_anon0* hp;
	_anon39 l;
	_anon20 pd;
	// Line 1154, Address: 0x25fbf0, Func Offset: 0
	// Line 1168, Address: 0x25fc38, Func Offset: 0x48
	// Line 1167, Address: 0x25fc40, Func Offset: 0x50
	// Line 1168, Address: 0x25fc44, Func Offset: 0x54
	// Line 1169, Address: 0x25fc60, Func Offset: 0x70
	// Line 1171, Address: 0x25fc70, Func Offset: 0x80
	// Line 1172, Address: 0x25fcbc, Func Offset: 0xcc
	// Line 1174, Address: 0x25fccc, Func Offset: 0xdc
	// Line 1175, Address: 0x25fcf8, Func Offset: 0x108
	// Line 1177, Address: 0x25fd24, Func Offset: 0x134
	// Line 1178, Address: 0x25fd28, Func Offset: 0x138
	// Line 1183, Address: 0x25fda8, Func Offset: 0x1b8
	// Line 1186, Address: 0x25fdd8, Func Offset: 0x1e8
	// Line 1188, Address: 0x25fde8, Func Offset: 0x1f8
	// Line 1187, Address: 0x25fdec, Func Offset: 0x1fc
	// Line 1186, Address: 0x25fdf0, Func Offset: 0x200
	// Line 1187, Address: 0x25fdf4, Func Offset: 0x204
	// Line 1189, Address: 0x25fdf8, Func Offset: 0x208
	// Line 1192, Address: 0x25fdfc, Func Offset: 0x20c
	// Line 1190, Address: 0x25fe00, Func Offset: 0x210
	// Line 1186, Address: 0x25fe04, Func Offset: 0x214
	// Line 1187, Address: 0x25fe08, Func Offset: 0x218
	// Line 1188, Address: 0x25fe0c, Func Offset: 0x21c
	// Line 1187, Address: 0x25fe10, Func Offset: 0x220
	// Line 1192, Address: 0x25fe14, Func Offset: 0x224
	// Line 1190, Address: 0x25fe18, Func Offset: 0x228
	// Line 1189, Address: 0x25fe1c, Func Offset: 0x22c
	// Line 1190, Address: 0x25fe20, Func Offset: 0x230
	// Line 1191, Address: 0x25fe28, Func Offset: 0x238
	// Line 1192, Address: 0x25fe2c, Func Offset: 0x23c
	// Line 1196, Address: 0x25feb0, Func Offset: 0x2c0
	// Line 1200, Address: 0x25fec8, Func Offset: 0x2d8
	// Line 1201, Address: 0x25fee4, Func Offset: 0x2f4
	// Line 1202, Address: 0x25fef0, Func Offset: 0x300
	// Line 1201, Address: 0x25fef4, Func Offset: 0x304
	// Line 1202, Address: 0x25ff04, Func Offset: 0x314
	// Line 1207, Address: 0x25ff10, Func Offset: 0x320
	// Line 1202, Address: 0x25ff14, Func Offset: 0x324
	// Line 1207, Address: 0x25ff18, Func Offset: 0x328
	// Line 1209, Address: 0x25ff74, Func Offset: 0x384
	// Line 1210, Address: 0x25ff7c, Func Offset: 0x38c
	// Line 1212, Address: 0x25ff88, Func Offset: 0x398
	// Line 1214, Address: 0x25ffac, Func Offset: 0x3bc
	// Line 1215, Address: 0x25ffb4, Func Offset: 0x3c4
	// Line 1217, Address: 0x25ffb8, Func Offset: 0x3c8
	// Line 1218, Address: 0x25ffcc, Func Offset: 0x3dc
	// Line 1220, Address: 0x25ffe0, Func Offset: 0x3f0
	// Line 1221, Address: 0x25ffec, Func Offset: 0x3fc
	// Line 1222, Address: 0x25fff8, Func Offset: 0x408
	// Line 1224, Address: 0x260008, Func Offset: 0x418
	// Line 1227, Address: 0x260010, Func Offset: 0x420
	// Line 1229, Address: 0x260018, Func Offset: 0x428
	// Line 1230, Address: 0x260024, Func Offset: 0x434
	// Line 1229, Address: 0x260028, Func Offset: 0x438
	// Line 1230, Address: 0x26002c, Func Offset: 0x43c
	// Line 1231, Address: 0x260038, Func Offset: 0x448
	// Line 1233, Address: 0x260048, Func Offset: 0x458
	// Line 1237, Address: 0x260050, Func Offset: 0x460
	// Line 1238, Address: 0x260058, Func Offset: 0x468
	// Line 1240, Address: 0x26006c, Func Offset: 0x47c
	// Line 1241, Address: 0x26007c, Func Offset: 0x48c
	// Line 1242, Address: 0x260088, Func Offset: 0x498
	// Line 1244, Address: 0x260098, Func Offset: 0x4a8
	// Line 1247, Address: 0x2600a0, Func Offset: 0x4b0
	// Line 1249, Address: 0x2600a8, Func Offset: 0x4b8
	// Line 1250, Address: 0x2600b4, Func Offset: 0x4c4
	// Line 1249, Address: 0x2600b8, Func Offset: 0x4c8
	// Line 1250, Address: 0x2600bc, Func Offset: 0x4cc
	// Line 1251, Address: 0x2600c8, Func Offset: 0x4d8
	// Line 1253, Address: 0x2600d8, Func Offset: 0x4e8
	// Line 1259, Address: 0x2600e0, Func Offset: 0x4f0
	// Line 1262, Address: 0x2600e8, Func Offset: 0x4f8
	// Line 1267, Address: 0x260184, Func Offset: 0x594
	// Line 1268, Address: 0x260188, Func Offset: 0x598
	// Line 1270, Address: 0x260190, Func Offset: 0x5a0
	// Line 1268, Address: 0x260194, Func Offset: 0x5a4
	// Line 1269, Address: 0x260198, Func Offset: 0x5a8
	// Line 1270, Address: 0x2601a0, Func Offset: 0x5b0
	// Line 1268, Address: 0x2601a4, Func Offset: 0x5b4
	// Line 1272, Address: 0x2601a8, Func Offset: 0x5b8
	// Line 1268, Address: 0x2601ac, Func Offset: 0x5bc
	// Line 1269, Address: 0x2601b0, Func Offset: 0x5c0
	// Line 1271, Address: 0x2601b8, Func Offset: 0x5c8
	// Line 1270, Address: 0x2601bc, Func Offset: 0x5cc
	// Line 1271, Address: 0x2601c8, Func Offset: 0x5d8
	// Line 1272, Address: 0x2601cc, Func Offset: 0x5dc
	// Line 1276, Address: 0x260254, Func Offset: 0x664
	// Line 1278, Address: 0x260264, Func Offset: 0x674
	// Line 1280, Address: 0x260274, Func Offset: 0x684
	// Line 1281, Address: 0x260284, Func Offset: 0x694
	// Line 1280, Address: 0x26028c, Func Offset: 0x69c
	// Line 1281, Address: 0x260290, Func Offset: 0x6a0
	// Line 1282, Address: 0x2602a8, Func Offset: 0x6b8
	// Line 1283, Address: 0x2602b8, Func Offset: 0x6c8
	// Line 1285, Address: 0x2602dc, Func Offset: 0x6ec
	// Line 1284, Address: 0x2602e8, Func Offset: 0x6f8
	// Line 1285, Address: 0x2602ec, Func Offset: 0x6fc
	// Line 1287, Address: 0x2602f4, Func Offset: 0x704
	// Line 1288, Address: 0x2602fc, Func Offset: 0x70c
	// Line 1290, Address: 0x260320, Func Offset: 0x730
	// Line 1289, Address: 0x26032c, Func Offset: 0x73c
	// Line 1290, Address: 0x260330, Func Offset: 0x740
	// Line 1293, Address: 0x260338, Func Offset: 0x748
	// Line 1295, Address: 0x260340, Func Offset: 0x750
	// Line 1296, Address: 0x260354, Func Offset: 0x764
	// Line 1297, Address: 0x260360, Func Offset: 0x770
	// Line 1298, Address: 0x260370, Func Offset: 0x780
	// Line 1300, Address: 0x260394, Func Offset: 0x7a4
	// Line 1299, Address: 0x2603a0, Func Offset: 0x7b0
	// Line 1300, Address: 0x2603a4, Func Offset: 0x7b4
	// Line 1302, Address: 0x2603ac, Func Offset: 0x7bc
	// Line 1303, Address: 0x2603b4, Func Offset: 0x7c4
	// Line 1304, Address: 0x2603d8, Func Offset: 0x7e8
	// Line 1309, Address: 0x2603dc, Func Offset: 0x7ec
	// Line 1311, Address: 0x2603e4, Func Offset: 0x7f4
	// Line 1313, Address: 0x2603f4, Func Offset: 0x804
	// Line 1314, Address: 0x2603fc, Func Offset: 0x80c
	// Line 1313, Address: 0x260404, Func Offset: 0x814
	// Line 1314, Address: 0x260408, Func Offset: 0x818
	// Line 1315, Address: 0x260420, Func Offset: 0x830
	// Line 1316, Address: 0x260430, Func Offset: 0x840
	// Line 1317, Address: 0x260454, Func Offset: 0x864
	// Line 1320, Address: 0x260458, Func Offset: 0x868
	// Line 1321, Address: 0x260460, Func Offset: 0x870
	// Line 1323, Address: 0x260484, Func Offset: 0x894
	// Line 1322, Address: 0x260490, Func Offset: 0x8a0
	// Line 1323, Address: 0x260494, Func Offset: 0x8a4
	// Line 1326, Address: 0x26049c, Func Offset: 0x8ac
	// Line 1328, Address: 0x2604a4, Func Offset: 0x8b4
	// Line 1329, Address: 0x2604b0, Func Offset: 0x8c0
	// Line 1330, Address: 0x2604bc, Func Offset: 0x8cc
	// Line 1331, Address: 0x2604cc, Func Offset: 0x8dc
	// Line 1332, Address: 0x2604f0, Func Offset: 0x900
	// Line 1335, Address: 0x2604f4, Func Offset: 0x904
	// Line 1336, Address: 0x2604fc, Func Offset: 0x90c
	// Line 1337, Address: 0x260520, Func Offset: 0x930
	// Line 1338, Address: 0x260524, Func Offset: 0x934
	// Line 1344, Address: 0x260528, Func Offset: 0x938
	// Line 1345, Address: 0x260530, Func Offset: 0x940
	// Line 1344, Address: 0x260538, Func Offset: 0x948
	// Line 1345, Address: 0x26053c, Func Offset: 0x94c
	// Line 1344, Address: 0x260540, Func Offset: 0x950
	// Line 1345, Address: 0x260544, Func Offset: 0x954
	// Line 1344, Address: 0x260548, Func Offset: 0x958
	// Line 1345, Address: 0x26054c, Func Offset: 0x95c
	// Line 1346, Address: 0x260550, Func Offset: 0x960
	// Line 1347, Address: 0x26055c, Func Offset: 0x96c
	// Line 1348, Address: 0x260570, Func Offset: 0x980
	// Line 1349, Address: 0x260574, Func Offset: 0x984
	// Line 1351, Address: 0x260594, Func Offset: 0x9a4
	// Line 1352, Address: 0x2605a4, Func Offset: 0x9b4
	// Line 1353, Address: 0x2605c4, Func Offset: 0x9d4
	// Line 1358, Address: 0x2605e0, Func Offset: 0x9f0
	// Line 1360, Address: 0x2605e8, Func Offset: 0x9f8
	// Line 1361, Address: 0x2605f0, Func Offset: 0xa00
	// Line 1360, Address: 0x2605f8, Func Offset: 0xa08
	// Line 1361, Address: 0x2605fc, Func Offset: 0xa0c
	// Line 1360, Address: 0x260600, Func Offset: 0xa10
	// Line 1361, Address: 0x260604, Func Offset: 0xa14
	// Line 1360, Address: 0x260608, Func Offset: 0xa18
	// Line 1361, Address: 0x26060c, Func Offset: 0xa1c
	// Line 1362, Address: 0x260610, Func Offset: 0xa20
	// Line 1363, Address: 0x26061c, Func Offset: 0xa2c
	// Line 1364, Address: 0x260630, Func Offset: 0xa40
	// Line 1365, Address: 0x260634, Func Offset: 0xa44
	// Line 1367, Address: 0x260654, Func Offset: 0xa64
	// Line 1368, Address: 0x260664, Func Offset: 0xa74
	// Line 1369, Address: 0x260684, Func Offset: 0xa94
	// Line 1374, Address: 0x2606a0, Func Offset: 0xab0
	// Line 1376, Address: 0x2606a8, Func Offset: 0xab8
	// Line 1377, Address: 0x2606b0, Func Offset: 0xac0
	// Line 1376, Address: 0x2606b8, Func Offset: 0xac8
	// Line 1377, Address: 0x2606bc, Func Offset: 0xacc
	// Line 1376, Address: 0x2606c0, Func Offset: 0xad0
	// Line 1377, Address: 0x2606c4, Func Offset: 0xad4
	// Line 1376, Address: 0x2606c8, Func Offset: 0xad8
	// Line 1377, Address: 0x2606cc, Func Offset: 0xadc
	// Line 1378, Address: 0x2606d0, Func Offset: 0xae0
	// Line 1379, Address: 0x2606dc, Func Offset: 0xaec
	// Line 1380, Address: 0x2606f0, Func Offset: 0xb00
	// Line 1381, Address: 0x2606f4, Func Offset: 0xb04
	// Line 1383, Address: 0x260714, Func Offset: 0xb24
	// Line 1384, Address: 0x260724, Func Offset: 0xb34
	// Line 1385, Address: 0x260744, Func Offset: 0xb54
	// Line 1390, Address: 0x260760, Func Offset: 0xb70
	// Line 1392, Address: 0x260768, Func Offset: 0xb78
	// Line 1393, Address: 0x260770, Func Offset: 0xb80
	// Line 1392, Address: 0x260778, Func Offset: 0xb88
	// Line 1393, Address: 0x26077c, Func Offset: 0xb8c
	// Line 1392, Address: 0x260780, Func Offset: 0xb90
	// Line 1393, Address: 0x260784, Func Offset: 0xb94
	// Line 1392, Address: 0x260788, Func Offset: 0xb98
	// Line 1393, Address: 0x26078c, Func Offset: 0xb9c
	// Line 1394, Address: 0x260790, Func Offset: 0xba0
	// Line 1395, Address: 0x26079c, Func Offset: 0xbac
	// Line 1396, Address: 0x2607b0, Func Offset: 0xbc0
	// Line 1397, Address: 0x2607b4, Func Offset: 0xbc4
	// Line 1399, Address: 0x2607d4, Func Offset: 0xbe4
	// Line 1400, Address: 0x2607e4, Func Offset: 0xbf4
	// Line 1401, Address: 0x260804, Func Offset: 0xc14
	// Line 1406, Address: 0x260820, Func Offset: 0xc30
	// Line 1411, Address: 0x260828, Func Offset: 0xc38
	// Line 1416, Address: 0x2608a8, Func Offset: 0xcb8
	// Line 1418, Address: 0x2608c8, Func Offset: 0xcd8
	// Line 1419, Address: 0x2608d0, Func Offset: 0xce0
	// Line 1421, Address: 0x260908, Func Offset: 0xd18
	// Line 1422, Address: 0x260910, Func Offset: 0xd20
	// Line 1421, Address: 0x260918, Func Offset: 0xd28
	// Line 1423, Address: 0x26091c, Func Offset: 0xd2c
	// Line 1425, Address: 0x260924, Func Offset: 0xd34
	// Line 1426, Address: 0x26092c, Func Offset: 0xd3c
	// Line 1425, Address: 0x260934, Func Offset: 0xd44
	// Line 1427, Address: 0x260938, Func Offset: 0xd48
	// Line 1429, Address: 0x260940, Func Offset: 0xd50
	// Line 1430, Address: 0x260948, Func Offset: 0xd58
	// Line 1429, Address: 0x260950, Func Offset: 0xd60
	// Line 1431, Address: 0x260954, Func Offset: 0xd64
	// Line 1433, Address: 0x26095c, Func Offset: 0xd6c
	// Line 1434, Address: 0x260964, Func Offset: 0xd74
	// Line 1433, Address: 0x26096c, Func Offset: 0xd7c
	// Line 1434, Address: 0x260970, Func Offset: 0xd80
	// Line 1436, Address: 0x260974, Func Offset: 0xd84
	// Line 1437, Address: 0x260978, Func Offset: 0xd88
	// Line 1438, Address: 0x26097c, Func Offset: 0xd8c
	// Line 1441, Address: 0x260980, Func Offset: 0xd90
	// Line 1438, Address: 0x26098c, Func Offset: 0xd9c
	// Line 1439, Address: 0x260994, Func Offset: 0xda4
	// Line 1440, Address: 0x26099c, Func Offset: 0xdac
	// Line 1441, Address: 0x2609a4, Func Offset: 0xdb4
	// Line 1442, Address: 0x2609ac, Func Offset: 0xdbc
	// Line 1443, Address: 0x2609b4, Func Offset: 0xdc4
	// Line 1444, Address: 0x2609b8, Func Offset: 0xdc8
	// Line 1446, Address: 0x2609c0, Func Offset: 0xdd0
	// Line 1449, Address: 0x2609f8, Func Offset: 0xe08
	// Line 1452, Address: 0x2609fc, Func Offset: 0xe0c
	// Line 1453, Address: 0x260a00, Func Offset: 0xe10
	// Line 1454, Address: 0x260a04, Func Offset: 0xe14
	// Line 1449, Address: 0x260a08, Func Offset: 0xe18
	// Line 1450, Address: 0x260a0c, Func Offset: 0xe1c
	// Line 1455, Address: 0x260a10, Func Offset: 0xe20
	// Line 1450, Address: 0x260a14, Func Offset: 0xe24
	// Line 1451, Address: 0x260a18, Func Offset: 0xe28
	// Line 1452, Address: 0x260a20, Func Offset: 0xe30
	// Line 1453, Address: 0x260a24, Func Offset: 0xe34
	// Line 1454, Address: 0x260a2c, Func Offset: 0xe3c
	// Line 1455, Address: 0x260a34, Func Offset: 0xe44
	// Line 1456, Address: 0x260a50, Func Offset: 0xe60
	// Line 1458, Address: 0x260a58, Func Offset: 0xe68
	// Line 1461, Address: 0x260a5c, Func Offset: 0xe6c
	// Line 1458, Address: 0x260a60, Func Offset: 0xe70
	// Line 1459, Address: 0x260a64, Func Offset: 0xe74
	// Line 1460, Address: 0x260a6c, Func Offset: 0xe7c
	// Line 1461, Address: 0x260a70, Func Offset: 0xe80
	// Line 1463, Address: 0x260a8c, Func Offset: 0xe9c
	// Line 1466, Address: 0x260a94, Func Offset: 0xea4
	// Line 1468, Address: 0x260a98, Func Offset: 0xea8
	// Line 1469, Address: 0x260a9c, Func Offset: 0xeac
	// Line 1470, Address: 0x260aa0, Func Offset: 0xeb0
	// Line 1466, Address: 0x260aa4, Func Offset: 0xeb4
	// Line 1467, Address: 0x260aa8, Func Offset: 0xeb8
	// Line 1471, Address: 0x260aac, Func Offset: 0xebc
	// Line 1472, Address: 0x260ab0, Func Offset: 0xec0
	// Line 1467, Address: 0x260ab4, Func Offset: 0xec4
	// Line 1468, Address: 0x260ab8, Func Offset: 0xec8
	// Line 1469, Address: 0x260ac8, Func Offset: 0xed8
	// Line 1470, Address: 0x260acc, Func Offset: 0xedc
	// Line 1471, Address: 0x260ad4, Func Offset: 0xee4
	// Line 1472, Address: 0x260ae0, Func Offset: 0xef0
	// Line 1473, Address: 0x260afc, Func Offset: 0xf0c
	// Line 1475, Address: 0x260b00, Func Offset: 0xf10
	// Line 1479, Address: 0x260b0c, Func Offset: 0xf1c
	// Line 1475, Address: 0x260b10, Func Offset: 0xf20
	// Line 1476, Address: 0x260b18, Func Offset: 0xf28
	// Line 1477, Address: 0x260b20, Func Offset: 0xf30
	// Line 1478, Address: 0x260b28, Func Offset: 0xf38
	// Line 1479, Address: 0x260b2c, Func Offset: 0xf3c
	// Line 1481, Address: 0x260b48, Func Offset: 0xf58
	// Line 1484, Address: 0x260b50, Func Offset: 0xf60
	// Line 1487, Address: 0x260b5c, Func Offset: 0xf6c
	// Line 1484, Address: 0x260b60, Func Offset: 0xf70
	// Line 1488, Address: 0x260b64, Func Offset: 0xf74
	// Line 1489, Address: 0x260b68, Func Offset: 0xf78
	// Line 1484, Address: 0x260b6c, Func Offset: 0xf7c
	// Line 1485, Address: 0x260b70, Func Offset: 0xf80
	// Line 1490, Address: 0x260b74, Func Offset: 0xf84
	// Line 1485, Address: 0x260b78, Func Offset: 0xf88
	// Line 1486, Address: 0x260b7c, Func Offset: 0xf8c
	// Line 1487, Address: 0x260b84, Func Offset: 0xf94
	// Line 1488, Address: 0x260b88, Func Offset: 0xf98
	// Line 1489, Address: 0x260b90, Func Offset: 0xfa0
	// Line 1490, Address: 0x260b98, Func Offset: 0xfa8
	// Line 1491, Address: 0x260bb4, Func Offset: 0xfc4
	// Line 1493, Address: 0x260bb8, Func Offset: 0xfc8
	// Line 1497, Address: 0x260bc4, Func Offset: 0xfd4
	// Line 1493, Address: 0x260bc8, Func Offset: 0xfd8
	// Line 1494, Address: 0x260bd0, Func Offset: 0xfe0
	// Line 1495, Address: 0x260bdc, Func Offset: 0xfec
	// Line 1496, Address: 0x260be4, Func Offset: 0xff4
	// Line 1497, Address: 0x260be8, Func Offset: 0xff8
	// Line 1499, Address: 0x260c04, Func Offset: 0x1014
	// Line 1502, Address: 0x260c0c, Func Offset: 0x101c
	// Line 1505, Address: 0x260c18, Func Offset: 0x1028
	// Line 1502, Address: 0x260c1c, Func Offset: 0x102c
	// Line 1506, Address: 0x260c20, Func Offset: 0x1030
	// Line 1507, Address: 0x260c24, Func Offset: 0x1034
	// Line 1502, Address: 0x260c28, Func Offset: 0x1038
	// Line 1503, Address: 0x260c2c, Func Offset: 0x103c
	// Line 1504, Address: 0x260c30, Func Offset: 0x1040
	// Line 1508, Address: 0x260c34, Func Offset: 0x1044
	// Line 1503, Address: 0x260c38, Func Offset: 0x1048
	// Line 1504, Address: 0x260c3c, Func Offset: 0x104c
	// Line 1505, Address: 0x260c4c, Func Offset: 0x105c
	// Line 1506, Address: 0x260c50, Func Offset: 0x1060
	// Line 1507, Address: 0x260c58, Func Offset: 0x1068
	// Line 1508, Address: 0x260c64, Func Offset: 0x1074
	// Line 1509, Address: 0x260c80, Func Offset: 0x1090
	// Line 1511, Address: 0x260c88, Func Offset: 0x1098
	// Line 1512, Address: 0x260c94, Func Offset: 0x10a4
	// Line 1516, Address: 0x260c98, Func Offset: 0x10a8
	// Line 1511, Address: 0x260c9c, Func Offset: 0x10ac
	// Line 1512, Address: 0x260ca4, Func Offset: 0x10b4
	// Line 1513, Address: 0x260cb4, Func Offset: 0x10c4
	// Line 1514, Address: 0x260cc0, Func Offset: 0x10d0
	// Line 1515, Address: 0x260cc8, Func Offset: 0x10d8
	// Line 1516, Address: 0x260ccc, Func Offset: 0x10dc
	// Line 1521, Address: 0x260ce8, Func Offset: 0x10f8
	// Line 1523, Address: 0x260cf0, Func Offset: 0x1100
	// Line 1528, Address: 0x260d98, Func Offset: 0x11a8
	// Line 1530, Address: 0x260dd0, Func Offset: 0x11e0
	// Line 1531, Address: 0x260dd4, Func Offset: 0x11e4
	// Line 1532, Address: 0x260ddc, Func Offset: 0x11ec
	// Line 1533, Address: 0x260de4, Func Offset: 0x11f4
	// Line 1534, Address: 0x260dec, Func Offset: 0x11fc
	// Line 1536, Address: 0x260df4, Func Offset: 0x1204
	// Line 1538, Address: 0x260dfc, Func Offset: 0x120c
	// Line 1539, Address: 0x260e00, Func Offset: 0x1210
	// Line 1540, Address: 0x260e08, Func Offset: 0x1218
	// Line 1541, Address: 0x260e18, Func Offset: 0x1228
	// Line 1542, Address: 0x260e1c, Func Offset: 0x122c
	// Line 1543, Address: 0x260e24, Func Offset: 0x1234
	// Line 1544, Address: 0x260e2c, Func Offset: 0x123c
	// Line 1546, Address: 0x260e34, Func Offset: 0x1244
	// Line 1547, Address: 0x260e38, Func Offset: 0x1248
	// Line 1548, Address: 0x260e40, Func Offset: 0x1250
	// Line 1549, Address: 0x260e48, Func Offset: 0x1258
	// Line 1550, Address: 0x260e4c, Func Offset: 0x125c
	// Line 1551, Address: 0x260e54, Func Offset: 0x1264
	// Line 1552, Address: 0x260e58, Func Offset: 0x1268
	// Line 1554, Address: 0x260e60, Func Offset: 0x1270
	// Line 1555, Address: 0x260e68, Func Offset: 0x1278
	// Line 1556, Address: 0x260e70, Func Offset: 0x1280
	// Line 1557, Address: 0x260e78, Func Offset: 0x1288
	// Line 1558, Address: 0x260e84, Func Offset: 0x1294
	// Line 1559, Address: 0x260e8c, Func Offset: 0x129c
	// Line 1562, Address: 0x260e90, Func Offset: 0x12a0
	// Line 1563, Address: 0x260ea0, Func Offset: 0x12b0
	// Line 1564, Address: 0x260ea4, Func Offset: 0x12b4
	// Line 1563, Address: 0x260eac, Func Offset: 0x12bc
	// Line 1565, Address: 0x260eb0, Func Offset: 0x12c0
	// Line 1567, Address: 0x260f10, Func Offset: 0x1320
	// Line 1569, Address: 0x260f18, Func Offset: 0x1328
	// Line 1570, Address: 0x260f28, Func Offset: 0x1338
	// Line 1571, Address: 0x260f38, Func Offset: 0x1348
	// Line 1572, Address: 0x260f60, Func Offset: 0x1370
	// Line 1573, Address: 0x260f68, Func Offset: 0x1378
	// Line 1574, Address: 0x260f6c, Func Offset: 0x137c
	// Line 1577, Address: 0x260f74, Func Offset: 0x1384
	// Line 1578, Address: 0x260f7c, Func Offset: 0x138c
	// Line 1580, Address: 0x260f80, Func Offset: 0x1390
	// Line 1578, Address: 0x260f84, Func Offset: 0x1394
	// Line 1579, Address: 0x260f88, Func Offset: 0x1398
	// Line 1580, Address: 0x260f90, Func Offset: 0x13a0
	// Line 1585, Address: 0x260fb8, Func Offset: 0x13c8
	// Line 1587, Address: 0x260fc0, Func Offset: 0x13d0
	// Line 1589, Address: 0x260fe0, Func Offset: 0x13f0
	// Line 1590, Address: 0x260fec, Func Offset: 0x13fc
	// Line 1592, Address: 0x260ff4, Func Offset: 0x1404
	// Line 1589, Address: 0x260ff8, Func Offset: 0x1408
	// Line 1591, Address: 0x261000, Func Offset: 0x1410
	// Line 1593, Address: 0x261004, Func Offset: 0x1414
	// Line 1595, Address: 0x261008, Func Offset: 0x1418
	// Line 1590, Address: 0x26100c, Func Offset: 0x141c
	// Line 1592, Address: 0x261014, Func Offset: 0x1424
	// Line 1591, Address: 0x261018, Func Offset: 0x1428
	// Line 1589, Address: 0x26101c, Func Offset: 0x142c
	// Line 1593, Address: 0x261020, Func Offset: 0x1430
	// Line 1595, Address: 0x261024, Func Offset: 0x1434
	// Line 1593, Address: 0x261028, Func Offset: 0x1438
	// Line 1594, Address: 0x261030, Func Offset: 0x1440
	// Line 1595, Address: 0x261034, Func Offset: 0x1444
	// Line 1604, Address: 0x261160, Func Offset: 0x1570
	// Line 1605, Address: 0x261170, Func Offset: 0x1580
	// Line 1607, Address: 0x261184, Func Offset: 0x1594
	// Line 1609, Address: 0x2611ac, Func Offset: 0x15bc
	// Line 1612, Address: 0x2611b4, Func Offset: 0x15c4
	// Line 1614, Address: 0x2611bc, Func Offset: 0x15cc
	// Line 1616, Address: 0x2611e8, Func Offset: 0x15f8
	// Line 1620, Address: 0x2611f0, Func Offset: 0x1600
	// Line 1621, Address: 0x2611f8, Func Offset: 0x1608
	// Line 1623, Address: 0x26120c, Func Offset: 0x161c
	// Line 1625, Address: 0x261238, Func Offset: 0x1648
	// Line 1628, Address: 0x261240, Func Offset: 0x1650
	// Line 1630, Address: 0x261248, Func Offset: 0x1658
	// Line 1632, Address: 0x261278, Func Offset: 0x1688
	// Line 1633, Address: 0x261280, Func Offset: 0x1690
	// Line 1640, Address: 0x261284, Func Offset: 0x1694
	// Line 1641, Address: 0x261298, Func Offset: 0x16a8
	// Line 1642, Address: 0x2612ac, Func Offset: 0x16bc
	// Line 1643, Address: 0x2612c4, Func Offset: 0x16d4
	// Line 1645, Address: 0x2612e0, Func Offset: 0x16f0
	// Line 1646, Address: 0x2612e8, Func Offset: 0x16f8
	// Line 1654, Address: 0x2612ec, Func Offset: 0x16fc
	// Func End, Address: 0x261334, Func Offset: 0x1744
}

// 
// Start address: 0x261340
_anon0* bhCheckWallType(_anon20* pos, unsigned int flg, float ar, float ah)
{
	float h;
	float ln;
	float zn;
	float xn;
	float pz;
	float px;
	int wal_n;
	int i;
	_anon0* hp;
	// Line 1667, Address: 0x261340, Func Offset: 0
	// Line 1673, Address: 0x261374, Func Offset: 0x34
	// Line 1674, Address: 0x2613a4, Func Offset: 0x64
	// Line 1676, Address: 0x2613c8, Func Offset: 0x88
	// Line 1677, Address: 0x261414, Func Offset: 0xd4
	// Line 1679, Address: 0x261424, Func Offset: 0xe4
	// Line 1680, Address: 0x261450, Func Offset: 0x110
	// Line 1682, Address: 0x26147c, Func Offset: 0x13c
	// Line 1683, Address: 0x261480, Func Offset: 0x140
	// Line 1688, Address: 0x261498, Func Offset: 0x158
	// Line 1685, Address: 0x26149c, Func Offset: 0x15c
	// Line 1686, Address: 0x2614a0, Func Offset: 0x160
	// Line 1687, Address: 0x2614a4, Func Offset: 0x164
	// Line 1688, Address: 0x2614a8, Func Offset: 0x168
	// Line 1685, Address: 0x2614b8, Func Offset: 0x178
	// Line 1686, Address: 0x2614bc, Func Offset: 0x17c
	// Line 1688, Address: 0x2614c0, Func Offset: 0x180
	// Line 1691, Address: 0x261538, Func Offset: 0x1f8
	// Line 1696, Address: 0x261540, Func Offset: 0x200
	// Line 1697, Address: 0x261558, Func Offset: 0x218
	// Line 1698, Address: 0x261560, Func Offset: 0x220
	// Line 1697, Address: 0x261568, Func Offset: 0x228
	// Line 1698, Address: 0x26156c, Func Offset: 0x22c
	// Line 1699, Address: 0x261570, Func Offset: 0x230
	// Line 1700, Address: 0x26157c, Func Offset: 0x23c
	// Line 1702, Address: 0x2615c4, Func Offset: 0x284
	// Line 1707, Address: 0x2615cc, Func Offset: 0x28c
	// Line 1709, Address: 0x2615e0, Func Offset: 0x2a0
	// Line 1710, Address: 0x2615fc, Func Offset: 0x2bc
	// Line 1714, Address: 0x261604, Func Offset: 0x2c4
	// Line 1717, Address: 0x261698, Func Offset: 0x358
	// Line 1725, Address: 0x2616a0, Func Offset: 0x360
	// Line 1722, Address: 0x2616a4, Func Offset: 0x364
	// Line 1723, Address: 0x2616a8, Func Offset: 0x368
	// Line 1724, Address: 0x2616ac, Func Offset: 0x36c
	// Line 1725, Address: 0x2616b0, Func Offset: 0x370
	// Line 1722, Address: 0x2616c0, Func Offset: 0x380
	// Line 1723, Address: 0x2616c4, Func Offset: 0x384
	// Line 1725, Address: 0x2616c8, Func Offset: 0x388
	// Line 1733, Address: 0x2617d0, Func Offset: 0x490
	// Line 1737, Address: 0x2617dc, Func Offset: 0x49c
	// Line 1738, Address: 0x2617f0, Func Offset: 0x4b0
	// Line 1739, Address: 0x2617f4, Func Offset: 0x4b4
	// Func End, Address: 0x26182c, Func Offset: 0x4ec
}

// 
// Start address: 0x261830
_anon0* bhCheckWallType2(_anon20* pos, unsigned int flg, float aw, float ad, float ah, int idx_ct)
{
	float h;
	float zn;
	float xn;
	float pz;
	float px;
	int wal_n;
	int i;
	_anon0* hp;
	_anon44 box;
	_anon7 sph;
	// Line 1755, Address: 0x261830, Func Offset: 0
	// Line 1763, Address: 0x261870, Func Offset: 0x40
	// Line 1764, Address: 0x2618a4, Func Offset: 0x74
	// Line 1766, Address: 0x2618d4, Func Offset: 0xa4
	// Line 1767, Address: 0x261920, Func Offset: 0xf0
	// Line 1771, Address: 0x261948, Func Offset: 0x118
	// Line 1772, Address: 0x261974, Func Offset: 0x144
	// Line 1775, Address: 0x2619a0, Func Offset: 0x170
	// Line 1776, Address: 0x2619b8, Func Offset: 0x188
	// Line 1778, Address: 0x2619dc, Func Offset: 0x1ac
	// Line 1783, Address: 0x2619e0, Func Offset: 0x1b0
	// Line 1780, Address: 0x2619e4, Func Offset: 0x1b4
	// Line 1781, Address: 0x2619e8, Func Offset: 0x1b8
	// Line 1782, Address: 0x2619ec, Func Offset: 0x1bc
	// Line 1783, Address: 0x2619f0, Func Offset: 0x1c0
	// Line 1780, Address: 0x261a04, Func Offset: 0x1d4
	// Line 1781, Address: 0x261a08, Func Offset: 0x1d8
	// Line 1783, Address: 0x261a0c, Func Offset: 0x1dc
	// Line 1786, Address: 0x261a84, Func Offset: 0x254
	// Line 1791, Address: 0x261a8c, Func Offset: 0x25c
	// Line 1792, Address: 0x261aa0, Func Offset: 0x270
	// Line 1794, Address: 0x261aa4, Func Offset: 0x274
	// Line 1792, Address: 0x261aa8, Func Offset: 0x278
	// Line 1796, Address: 0x261aac, Func Offset: 0x27c
	// Line 1793, Address: 0x261ab0, Func Offset: 0x280
	// Line 1794, Address: 0x261ab4, Func Offset: 0x284
	// Line 1792, Address: 0x261ab8, Func Offset: 0x288
	// Line 1796, Address: 0x261ac0, Func Offset: 0x290
	// Line 1793, Address: 0x261ac4, Func Offset: 0x294
	// Line 1794, Address: 0x261acc, Func Offset: 0x29c
	// Line 1796, Address: 0x261ad0, Func Offset: 0x2a0
	// Line 1794, Address: 0x261ad4, Func Offset: 0x2a4
	// Line 1796, Address: 0x261ad8, Func Offset: 0x2a8
	// Line 1800, Address: 0x261b50, Func Offset: 0x320
	// Line 1801, Address: 0x261b54, Func Offset: 0x324
	// Line 1804, Address: 0x261b58, Func Offset: 0x328
	// Line 1814, Address: 0x261b60, Func Offset: 0x330
	// Line 1801, Address: 0x261b68, Func Offset: 0x338
	// Line 1802, Address: 0x261b6c, Func Offset: 0x33c
	// Line 1803, Address: 0x261b74, Func Offset: 0x344
	// Line 1804, Address: 0x261b78, Func Offset: 0x348
	// Line 1805, Address: 0x261b88, Func Offset: 0x358
	// Line 1803, Address: 0x261b94, Func Offset: 0x364
	// Line 1805, Address: 0x261b98, Func Offset: 0x368
	// Line 1806, Address: 0x261b9c, Func Offset: 0x36c
	// Line 1807, Address: 0x261bac, Func Offset: 0x37c
	// Line 1808, Address: 0x261bbc, Func Offset: 0x38c
	// Line 1809, Address: 0x261bcc, Func Offset: 0x39c
	// Line 1810, Address: 0x261bdc, Func Offset: 0x3ac
	// Line 1811, Address: 0x261bec, Func Offset: 0x3bc
	// Line 1812, Address: 0x261bfc, Func Offset: 0x3cc
	// Line 1813, Address: 0x261c0c, Func Offset: 0x3dc
	// Line 1814, Address: 0x261c18, Func Offset: 0x3e8
	// Line 1818, Address: 0x261c30, Func Offset: 0x400
	// Line 1819, Address: 0x261c48, Func Offset: 0x418
	// Line 1820, Address: 0x261c68, Func Offset: 0x438
	// Line 1824, Address: 0x261c70, Func Offset: 0x440
	// Line 1827, Address: 0x261d08, Func Offset: 0x4d8
	// Line 1835, Address: 0x261d10, Func Offset: 0x4e0
	// Line 1832, Address: 0x261d14, Func Offset: 0x4e4
	// Line 1833, Address: 0x261d18, Func Offset: 0x4e8
	// Line 1834, Address: 0x261d1c, Func Offset: 0x4ec
	// Line 1835, Address: 0x261d20, Func Offset: 0x4f0
	// Line 1832, Address: 0x261d30, Func Offset: 0x500
	// Line 1833, Address: 0x261d34, Func Offset: 0x504
	// Line 1835, Address: 0x261d38, Func Offset: 0x508
	// Line 1843, Address: 0x261e40, Func Offset: 0x610
	// Line 1847, Address: 0x261e4c, Func Offset: 0x61c
	// Line 1848, Address: 0x261e60, Func Offset: 0x630
	// Line 1849, Address: 0x261e64, Func Offset: 0x634
	// Func End, Address: 0x261ea8, Func Offset: 0x678
}

// 
// Start address: 0x261eb0
_anon0* bhCheckWallRefAngle(_anon20* pos, unsigned int flg, float ar, float ah, int* ay)
{
	int r;
	float abz;
	float aby;
	float abx;
	float h;
	float wpz;
	float wpx;
	float ln2;
	float ln;
	float zn;
	float xn;
	float pz;
	float py;
	float px;
	int wal_n;
	int i;
	_anon0 ht;
	_anon0* hp;
	_anon39 l;
	_anon20 pd;
	// Line 1865, Address: 0x261eb0, Func Offset: 0
	// Line 1875, Address: 0x261f08, Func Offset: 0x58
	// Line 1876, Address: 0x261f3c, Func Offset: 0x8c
	// Line 1877, Address: 0x261f64, Func Offset: 0xb4
	// Line 1878, Address: 0x261f88, Func Offset: 0xd8
	// Line 1879, Address: 0x261fb0, Func Offset: 0x100
	// Line 1881, Address: 0x261fc0, Func Offset: 0x110
	// Line 1882, Address: 0x261fec, Func Offset: 0x13c
	// Line 1885, Address: 0x262018, Func Offset: 0x168
	// Line 1888, Address: 0x262048, Func Offset: 0x198
	// Line 1889, Address: 0x262058, Func Offset: 0x1a8
	// Line 1888, Address: 0x262060, Func Offset: 0x1b0
	// Line 1894, Address: 0x262064, Func Offset: 0x1b4
	// Line 1888, Address: 0x262068, Func Offset: 0x1b8
	// Line 1889, Address: 0x26206c, Func Offset: 0x1bc
	// Line 1890, Address: 0x262070, Func Offset: 0x1c0
	// Line 1889, Address: 0x262074, Func Offset: 0x1c4
	// Line 1894, Address: 0x262078, Func Offset: 0x1c8
	// Line 1891, Address: 0x262080, Func Offset: 0x1d0
	// Line 1892, Address: 0x262084, Func Offset: 0x1d4
	// Line 1894, Address: 0x262088, Func Offset: 0x1d8
	// Line 1897, Address: 0x262100, Func Offset: 0x250
	// Line 1898, Address: 0x262108, Func Offset: 0x258
	// Line 1899, Address: 0x26211c, Func Offset: 0x26c
	// Line 1901, Address: 0x262130, Func Offset: 0x280
	// Line 1902, Address: 0x26213c, Func Offset: 0x28c
	// Line 1903, Address: 0x262148, Func Offset: 0x298
	// Line 1904, Address: 0x262158, Func Offset: 0x2a8
	// Line 1906, Address: 0x262178, Func Offset: 0x2c8
	// Line 1907, Address: 0x26217c, Func Offset: 0x2cc
	// Line 1909, Address: 0x262188, Func Offset: 0x2d8
	// Line 1910, Address: 0x262190, Func Offset: 0x2e0
	// Line 1912, Address: 0x2621b0, Func Offset: 0x300
	// Line 1913, Address: 0x2621b4, Func Offset: 0x304
	// Line 1916, Address: 0x2621bc, Func Offset: 0x30c
	// Line 1918, Address: 0x2621c4, Func Offset: 0x314
	// Line 1919, Address: 0x2621d4, Func Offset: 0x324
	// Line 1920, Address: 0x2621e4, Func Offset: 0x334
	// Line 1921, Address: 0x2621f4, Func Offset: 0x344
	// Line 1923, Address: 0x262214, Func Offset: 0x364
	// Line 1924, Address: 0x262218, Func Offset: 0x368
	// Line 1926, Address: 0x262224, Func Offset: 0x374
	// Line 1927, Address: 0x26222c, Func Offset: 0x37c
	// Line 1929, Address: 0x26224c, Func Offset: 0x39c
	// Line 1930, Address: 0x262250, Func Offset: 0x3a0
	// Line 1934, Address: 0x262258, Func Offset: 0x3a8
	// Line 1935, Address: 0x262260, Func Offset: 0x3b0
	// Line 1937, Address: 0x262274, Func Offset: 0x3c4
	// Line 1938, Address: 0x262284, Func Offset: 0x3d4
	// Line 1939, Address: 0x262290, Func Offset: 0x3e0
	// Line 1940, Address: 0x2622a0, Func Offset: 0x3f0
	// Line 1942, Address: 0x2622c0, Func Offset: 0x410
	// Line 1943, Address: 0x2622c4, Func Offset: 0x414
	// Line 1945, Address: 0x2622d0, Func Offset: 0x420
	// Line 1946, Address: 0x2622d8, Func Offset: 0x428
	// Line 1948, Address: 0x2622f8, Func Offset: 0x448
	// Line 1949, Address: 0x2622fc, Func Offset: 0x44c
	// Line 1952, Address: 0x262304, Func Offset: 0x454
	// Line 1954, Address: 0x26230c, Func Offset: 0x45c
	// Line 1955, Address: 0x26231c, Func Offset: 0x46c
	// Line 1956, Address: 0x26232c, Func Offset: 0x47c
	// Line 1957, Address: 0x26233c, Func Offset: 0x48c
	// Line 1959, Address: 0x26235c, Func Offset: 0x4ac
	// Line 1960, Address: 0x262360, Func Offset: 0x4b0
	// Line 1962, Address: 0x26236c, Func Offset: 0x4bc
	// Line 1963, Address: 0x262374, Func Offset: 0x4c4
	// Line 1965, Address: 0x262394, Func Offset: 0x4e4
	// Line 1966, Address: 0x262398, Func Offset: 0x4e8
	// Line 1972, Address: 0x2623a4, Func Offset: 0x4f4
	// Line 1977, Address: 0x2623ac, Func Offset: 0x4fc
	// Line 1980, Address: 0x2623d8, Func Offset: 0x528
	// Line 1981, Address: 0x2623e0, Func Offset: 0x530
	// Line 1980, Address: 0x2623e8, Func Offset: 0x538
	// Line 1981, Address: 0x2623ec, Func Offset: 0x53c
	// Line 1982, Address: 0x2623f0, Func Offset: 0x540
	// Line 1983, Address: 0x262400, Func Offset: 0x550
	// Line 1985, Address: 0x262448, Func Offset: 0x598
	// Line 1987, Address: 0x262468, Func Offset: 0x5b8
	// Line 1986, Address: 0x26246c, Func Offset: 0x5bc
	// Line 1987, Address: 0x262470, Func Offset: 0x5c0
	// Line 1985, Address: 0x262474, Func Offset: 0x5c4
	// Line 1987, Address: 0x262478, Func Offset: 0x5c8
	// Line 1986, Address: 0x26247c, Func Offset: 0x5cc
	// Line 1987, Address: 0x262480, Func Offset: 0x5d0
	// Line 1988, Address: 0x262488, Func Offset: 0x5d8
	// Line 1990, Address: 0x2624a4, Func Offset: 0x5f4
	// Line 1991, Address: 0x2624b4, Func Offset: 0x604
	// Line 1997, Address: 0x2624b8, Func Offset: 0x608
	// Line 1991, Address: 0x2624bc, Func Offset: 0x60c
	// Line 1997, Address: 0x2624c0, Func Offset: 0x610
	// Line 1991, Address: 0x2624c4, Func Offset: 0x614
	// Line 1992, Address: 0x2624d0, Func Offset: 0x620
	// Line 1997, Address: 0x2624e4, Func Offset: 0x634
	// Line 1998, Address: 0x2624f0, Func Offset: 0x640
	// Line 1999, Address: 0x2624f8, Func Offset: 0x648
	// Line 2002, Address: 0x262504, Func Offset: 0x654
	// Line 2007, Address: 0x26250c, Func Offset: 0x65c
	// Line 2011, Address: 0x262538, Func Offset: 0x688
	// Line 2012, Address: 0x262554, Func Offset: 0x6a4
	// Line 2013, Address: 0x26255c, Func Offset: 0x6ac
	// Line 2015, Address: 0x262594, Func Offset: 0x6e4
	// Line 2016, Address: 0x262598, Func Offset: 0x6e8
	// Line 2015, Address: 0x26259c, Func Offset: 0x6ec
	// Line 2017, Address: 0x2625a0, Func Offset: 0x6f0
	// Line 2019, Address: 0x2625a8, Func Offset: 0x6f8
	// Line 2020, Address: 0x2625ac, Func Offset: 0x6fc
	// Line 2019, Address: 0x2625b0, Func Offset: 0x700
	// Line 2021, Address: 0x2625b4, Func Offset: 0x704
	// Line 2023, Address: 0x2625bc, Func Offset: 0x70c
	// Line 2024, Address: 0x2625c0, Func Offset: 0x710
	// Line 2023, Address: 0x2625c4, Func Offset: 0x714
	// Line 2025, Address: 0x2625c8, Func Offset: 0x718
	// Line 2027, Address: 0x2625d0, Func Offset: 0x720
	// Line 2028, Address: 0x2625d4, Func Offset: 0x724
	// Line 2027, Address: 0x2625d8, Func Offset: 0x728
	// Line 2028, Address: 0x2625dc, Func Offset: 0x72c
	// Line 2031, Address: 0x2625e0, Func Offset: 0x730
	// Line 2032, Address: 0x2625e4, Func Offset: 0x734
	// Line 2035, Address: 0x2625e8, Func Offset: 0x738
	// Line 2032, Address: 0x2625f4, Func Offset: 0x744
	// Line 2033, Address: 0x2625fc, Func Offset: 0x74c
	// Line 2034, Address: 0x262604, Func Offset: 0x754
	// Line 2035, Address: 0x26260c, Func Offset: 0x75c
	// Line 2037, Address: 0x262614, Func Offset: 0x764
	// Line 2036, Address: 0x262618, Func Offset: 0x768
	// Line 2037, Address: 0x262620, Func Offset: 0x770
	// Line 2036, Address: 0x262628, Func Offset: 0x778
	// Line 2037, Address: 0x26262c, Func Offset: 0x77c
	// Line 2038, Address: 0x262630, Func Offset: 0x780
	// Line 2039, Address: 0x262640, Func Offset: 0x790
	// Line 2040, Address: 0x262654, Func Offset: 0x7a4
	// Line 2041, Address: 0x262664, Func Offset: 0x7b4
	// Line 2042, Address: 0x26266c, Func Offset: 0x7bc
	// Line 2043, Address: 0x262674, Func Offset: 0x7c4
	// Line 2044, Address: 0x262694, Func Offset: 0x7e4
	// Line 2045, Address: 0x2626a8, Func Offset: 0x7f8
	// Line 2046, Address: 0x2626b0, Func Offset: 0x800
	// Line 2049, Address: 0x2626bc, Func Offset: 0x80c
	// Line 2052, Address: 0x2626c4, Func Offset: 0x814
	// Line 2055, Address: 0x2626fc, Func Offset: 0x84c
	// Line 2058, Address: 0x262700, Func Offset: 0x850
	// Line 2061, Address: 0x262704, Func Offset: 0x854
	// Line 2055, Address: 0x262714, Func Offset: 0x864
	// Line 2056, Address: 0x262718, Func Offset: 0x868
	// Line 2061, Address: 0x26271c, Func Offset: 0x86c
	// Line 2056, Address: 0x262720, Func Offset: 0x870
	// Line 2057, Address: 0x262724, Func Offset: 0x874
	// Line 2058, Address: 0x26272c, Func Offset: 0x87c
	// Line 2059, Address: 0x262730, Func Offset: 0x880
	// Line 2060, Address: 0x26273c, Func Offset: 0x88c
	// Line 2061, Address: 0x262744, Func Offset: 0x894
	// Line 2063, Address: 0x262754, Func Offset: 0x8a4
	// Line 2064, Address: 0x262758, Func Offset: 0x8a8
	// Line 2063, Address: 0x26275c, Func Offset: 0x8ac
	// Line 2064, Address: 0x262760, Func Offset: 0x8b0
	// Line 2067, Address: 0x262768, Func Offset: 0x8b8
	// Line 2070, Address: 0x262770, Func Offset: 0x8c0
	// Line 2067, Address: 0x262780, Func Offset: 0x8d0
	// Line 2068, Address: 0x262784, Func Offset: 0x8d4
	// Line 2070, Address: 0x26278c, Func Offset: 0x8dc
	// Line 2068, Address: 0x262790, Func Offset: 0x8e0
	// Line 2069, Address: 0x262794, Func Offset: 0x8e4
	// Line 2070, Address: 0x262798, Func Offset: 0x8e8
	// Line 2072, Address: 0x2627a8, Func Offset: 0x8f8
	// Line 2073, Address: 0x2627ac, Func Offset: 0x8fc
	// Line 2072, Address: 0x2627b0, Func Offset: 0x900
	// Line 2073, Address: 0x2627b4, Func Offset: 0x904
	// Line 2078, Address: 0x2627bc, Func Offset: 0x90c
	// Line 2080, Address: 0x2627c0, Func Offset: 0x910
	// Line 2084, Address: 0x2627c4, Func Offset: 0x914
	// Line 2078, Address: 0x2627d4, Func Offset: 0x924
	// Line 2079, Address: 0x2627d8, Func Offset: 0x928
	// Line 2084, Address: 0x2627dc, Func Offset: 0x92c
	// Line 2079, Address: 0x2627e0, Func Offset: 0x930
	// Line 2080, Address: 0x2627e4, Func Offset: 0x934
	// Line 2081, Address: 0x2627f4, Func Offset: 0x944
	// Line 2082, Address: 0x2627fc, Func Offset: 0x94c
	// Line 2083, Address: 0x262808, Func Offset: 0x958
	// Line 2084, Address: 0x262814, Func Offset: 0x964
	// Line 2086, Address: 0x262824, Func Offset: 0x974
	// Line 2087, Address: 0x262828, Func Offset: 0x978
	// Line 2086, Address: 0x26282c, Func Offset: 0x97c
	// Line 2087, Address: 0x262830, Func Offset: 0x980
	// Line 2090, Address: 0x262838, Func Offset: 0x988
	// Line 2094, Address: 0x262844, Func Offset: 0x994
	// Line 2090, Address: 0x262850, Func Offset: 0x9a0
	// Line 2094, Address: 0x262854, Func Offset: 0x9a4
	// Line 2090, Address: 0x26285c, Func Offset: 0x9ac
	// Line 2091, Address: 0x262860, Func Offset: 0x9b0
	// Line 2092, Address: 0x26286c, Func Offset: 0x9bc
	// Line 2093, Address: 0x262878, Func Offset: 0x9c8
	// Line 2094, Address: 0x26287c, Func Offset: 0x9cc
	// Line 2096, Address: 0x26288c, Func Offset: 0x9dc
	// Line 2097, Address: 0x262890, Func Offset: 0x9e0
	// Line 2096, Address: 0x262894, Func Offset: 0x9e4
	// Line 2097, Address: 0x262898, Func Offset: 0x9e8
	// Line 2102, Address: 0x2628a0, Func Offset: 0x9f0
	// Line 2108, Address: 0x2628ac, Func Offset: 0x9fc
	// Line 2102, Address: 0x2628b8, Func Offset: 0xa08
	// Line 2108, Address: 0x2628bc, Func Offset: 0xa0c
	// Line 2102, Address: 0x2628c0, Func Offset: 0xa10
	// Line 2103, Address: 0x2628c4, Func Offset: 0xa14
	// Line 2105, Address: 0x2628c8, Func Offset: 0xa18
	// Line 2103, Address: 0x2628cc, Func Offset: 0xa1c
	// Line 2104, Address: 0x2628d0, Func Offset: 0xa20
	// Line 2105, Address: 0x2628d8, Func Offset: 0xa28
	// Line 2106, Address: 0x2628dc, Func Offset: 0xa2c
	// Line 2107, Address: 0x2628e8, Func Offset: 0xa38
	// Line 2108, Address: 0x2628f0, Func Offset: 0xa40
	// Line 2110, Address: 0x262900, Func Offset: 0xa50
	// Line 2111, Address: 0x262904, Func Offset: 0xa54
	// Line 2110, Address: 0x262908, Func Offset: 0xa58
	// Line 2111, Address: 0x26290c, Func Offset: 0xa5c
	// Line 2114, Address: 0x262914, Func Offset: 0xa64
	// Line 2118, Address: 0x262920, Func Offset: 0xa70
	// Line 2114, Address: 0x262930, Func Offset: 0xa80
	// Line 2118, Address: 0x262934, Func Offset: 0xa84
	// Line 2114, Address: 0x262938, Func Offset: 0xa88
	// Line 2115, Address: 0x26293c, Func Offset: 0xa8c
	// Line 2116, Address: 0x26294c, Func Offset: 0xa9c
	// Line 2117, Address: 0x262958, Func Offset: 0xaa8
	// Line 2118, Address: 0x26295c, Func Offset: 0xaac
	// Line 2120, Address: 0x26296c, Func Offset: 0xabc
	// Line 2121, Address: 0x262970, Func Offset: 0xac0
	// Line 2120, Address: 0x262974, Func Offset: 0xac4
	// Line 2121, Address: 0x262978, Func Offset: 0xac8
	// Line 2126, Address: 0x262980, Func Offset: 0xad0
	// Line 2132, Address: 0x26298c, Func Offset: 0xadc
	// Line 2126, Address: 0x262998, Func Offset: 0xae8
	// Line 2132, Address: 0x26299c, Func Offset: 0xaec
	// Line 2126, Address: 0x2629a0, Func Offset: 0xaf0
	// Line 2127, Address: 0x2629a4, Func Offset: 0xaf4
	// Line 2128, Address: 0x2629a8, Func Offset: 0xaf8
	// Line 2127, Address: 0x2629ac, Func Offset: 0xafc
	// Line 2128, Address: 0x2629b0, Func Offset: 0xb00
	// Line 2129, Address: 0x2629c0, Func Offset: 0xb10
	// Line 2130, Address: 0x2629c8, Func Offset: 0xb18
	// Line 2131, Address: 0x2629d4, Func Offset: 0xb24
	// Line 2132, Address: 0x2629e0, Func Offset: 0xb30
	// Line 2134, Address: 0x2629f0, Func Offset: 0xb40
	// Line 2135, Address: 0x2629f4, Func Offset: 0xb44
	// Line 2134, Address: 0x2629f8, Func Offset: 0xb48
	// Line 2135, Address: 0x2629fc, Func Offset: 0xb4c
	// Line 2138, Address: 0x262a04, Func Offset: 0xb54
	// Line 2139, Address: 0x262a10, Func Offset: 0xb60
	// Line 2143, Address: 0x262a14, Func Offset: 0xb64
	// Line 2138, Address: 0x262a20, Func Offset: 0xb70
	// Line 2143, Address: 0x262a24, Func Offset: 0xb74
	// Line 2138, Address: 0x262a28, Func Offset: 0xb78
	// Line 2139, Address: 0x262a2c, Func Offset: 0xb7c
	// Line 2143, Address: 0x262a34, Func Offset: 0xb84
	// Line 2139, Address: 0x262a38, Func Offset: 0xb88
	// Line 2140, Address: 0x262a40, Func Offset: 0xb90
	// Line 2141, Address: 0x262a50, Func Offset: 0xba0
	// Line 2142, Address: 0x262a5c, Func Offset: 0xbac
	// Line 2143, Address: 0x262a60, Func Offset: 0xbb0
	// Line 2145, Address: 0x262a70, Func Offset: 0xbc0
	// Line 2146, Address: 0x262a74, Func Offset: 0xbc4
	// Line 2145, Address: 0x262a78, Func Offset: 0xbc8
	// Line 2146, Address: 0x262a7c, Func Offset: 0xbcc
	// Line 2153, Address: 0x262a84, Func Offset: 0xbd4
	// Line 2156, Address: 0x262b18, Func Offset: 0xc68
	// Line 2159, Address: 0x262b50, Func Offset: 0xca0
	// Line 2160, Address: 0x262b64, Func Offset: 0xcb4
	// Line 2163, Address: 0x262b6c, Func Offset: 0xcbc
	// Line 2164, Address: 0x262b80, Func Offset: 0xcd0
	// Line 2167, Address: 0x262b88, Func Offset: 0xcd8
	// Line 2168, Address: 0x262b9c, Func Offset: 0xcec
	// Line 2171, Address: 0x262ba4, Func Offset: 0xcf4
	// Line 2173, Address: 0x262bbc, Func Offset: 0xd0c
	// Line 2174, Address: 0x262bc0, Func Offset: 0xd10
	// Line 2176, Address: 0x262bd0, Func Offset: 0xd20
	// Line 2177, Address: 0x262bd8, Func Offset: 0xd28
	// Line 2176, Address: 0x262bec, Func Offset: 0xd3c
	// Line 2183, Address: 0x262bf0, Func Offset: 0xd40
	// Line 2177, Address: 0x262bf4, Func Offset: 0xd44
	// Line 2178, Address: 0x262bf8, Func Offset: 0xd48
	// Line 2177, Address: 0x262c00, Func Offset: 0xd50
	// Line 2179, Address: 0x262c04, Func Offset: 0xd54
	// Line 2183, Address: 0x262c08, Func Offset: 0xd58
	// Line 2178, Address: 0x262c0c, Func Offset: 0xd5c
	// Line 2181, Address: 0x262c10, Func Offset: 0xd60
	// Line 2180, Address: 0x262c14, Func Offset: 0xd64
	// Line 2178, Address: 0x262c18, Func Offset: 0xd68
	// Line 2183, Address: 0x262c1c, Func Offset: 0xd6c
	// Line 2184, Address: 0x262c24, Func Offset: 0xd74
	// Line 2186, Address: 0x262c38, Func Offset: 0xd88
	// Line 2187, Address: 0x262c44, Func Offset: 0xd94
	// Line 2188, Address: 0x262c50, Func Offset: 0xda0
	// Line 2189, Address: 0x262c60, Func Offset: 0xdb0
	// Line 2191, Address: 0x262c78, Func Offset: 0xdc8
	// Line 2192, Address: 0x262c7c, Func Offset: 0xdcc
	// Line 2194, Address: 0x262c88, Func Offset: 0xdd8
	// Line 2195, Address: 0x262c90, Func Offset: 0xde0
	// Line 2197, Address: 0x262ca8, Func Offset: 0xdf8
	// Line 2198, Address: 0x262cac, Func Offset: 0xdfc
	// Line 2201, Address: 0x262cb4, Func Offset: 0xe04
	// Line 2203, Address: 0x262cbc, Func Offset: 0xe0c
	// Line 2204, Address: 0x262cc8, Func Offset: 0xe18
	// Line 2203, Address: 0x262ccc, Func Offset: 0xe1c
	// Line 2204, Address: 0x262cd0, Func Offset: 0xe20
	// Line 2205, Address: 0x262cdc, Func Offset: 0xe2c
	// Line 2206, Address: 0x262cec, Func Offset: 0xe3c
	// Line 2208, Address: 0x262d04, Func Offset: 0xe54
	// Line 2209, Address: 0x262d08, Func Offset: 0xe58
	// Line 2211, Address: 0x262d14, Func Offset: 0xe64
	// Line 2212, Address: 0x262d1c, Func Offset: 0xe6c
	// Line 2214, Address: 0x262d34, Func Offset: 0xe84
	// Line 2215, Address: 0x262d38, Func Offset: 0xe88
	// Line 2219, Address: 0x262d40, Func Offset: 0xe90
	// Line 2220, Address: 0x262d48, Func Offset: 0xe98
	// Line 2222, Address: 0x262d5c, Func Offset: 0xeac
	// Line 2223, Address: 0x262d6c, Func Offset: 0xebc
	// Line 2224, Address: 0x262d78, Func Offset: 0xec8
	// Line 2225, Address: 0x262d88, Func Offset: 0xed8
	// Line 2227, Address: 0x262da0, Func Offset: 0xef0
	// Line 2228, Address: 0x262da4, Func Offset: 0xef4
	// Line 2230, Address: 0x262db0, Func Offset: 0xf00
	// Line 2231, Address: 0x262db8, Func Offset: 0xf08
	// Line 2233, Address: 0x262dd0, Func Offset: 0xf20
	// Line 2234, Address: 0x262dd4, Func Offset: 0xf24
	// Line 2237, Address: 0x262ddc, Func Offset: 0xf2c
	// Line 2239, Address: 0x262de4, Func Offset: 0xf34
	// Line 2240, Address: 0x262df0, Func Offset: 0xf40
	// Line 2239, Address: 0x262df4, Func Offset: 0xf44
	// Line 2240, Address: 0x262df8, Func Offset: 0xf48
	// Line 2241, Address: 0x262e04, Func Offset: 0xf54
	// Line 2242, Address: 0x262e14, Func Offset: 0xf64
	// Line 2244, Address: 0x262e2c, Func Offset: 0xf7c
	// Line 2245, Address: 0x262e30, Func Offset: 0xf80
	// Line 2247, Address: 0x262e3c, Func Offset: 0xf8c
	// Line 2248, Address: 0x262e44, Func Offset: 0xf94
	// Line 2250, Address: 0x262e5c, Func Offset: 0xfac
	// Line 2251, Address: 0x262e60, Func Offset: 0xfb0
	// Line 2256, Address: 0x262e6c, Func Offset: 0xfbc
	// Line 2261, Address: 0x262e74, Func Offset: 0xfc4
	// Line 2262, Address: 0x262e90, Func Offset: 0xfe0
	// Line 2263, Address: 0x262ea0, Func Offset: 0xff0
	// Line 2262, Address: 0x262ea8, Func Offset: 0xff8
	// Line 2268, Address: 0x262eac, Func Offset: 0xffc
	// Line 2262, Address: 0x262eb0, Func Offset: 0x1000
	// Line 2263, Address: 0x262eb4, Func Offset: 0x1004
	// Line 2264, Address: 0x262eb8, Func Offset: 0x1008
	// Line 2263, Address: 0x262ebc, Func Offset: 0x100c
	// Line 2268, Address: 0x262ec0, Func Offset: 0x1010
	// Line 2265, Address: 0x262ec8, Func Offset: 0x1018
	// Line 2266, Address: 0x262ecc, Func Offset: 0x101c
	// Line 2268, Address: 0x262ed0, Func Offset: 0x1020
	// Line 2276, Address: 0x262fd8, Func Offset: 0x1128
	// Line 2277, Address: 0x262fe8, Func Offset: 0x1138
	// Line 2278, Address: 0x262ffc, Func Offset: 0x114c
	// Line 2280, Address: 0x263010, Func Offset: 0x1160
	// Line 2281, Address: 0x26301c, Func Offset: 0x116c
	// Line 2282, Address: 0x263028, Func Offset: 0x1178
	// Line 2283, Address: 0x263038, Func Offset: 0x1188
	// Line 2284, Address: 0x263048, Func Offset: 0x1198
	// Line 2285, Address: 0x26304c, Func Offset: 0x119c
	// Line 2286, Address: 0x263054, Func Offset: 0x11a4
	// Line 2287, Address: 0x263058, Func Offset: 0x11a8
	// Line 2289, Address: 0x263064, Func Offset: 0x11b4
	// Line 2290, Address: 0x26306c, Func Offset: 0x11bc
	// Line 2291, Address: 0x26307c, Func Offset: 0x11cc
	// Line 2292, Address: 0x263080, Func Offset: 0x11d0
	// Line 2293, Address: 0x263088, Func Offset: 0x11d8
	// Line 2294, Address: 0x26308c, Func Offset: 0x11dc
	// Line 2297, Address: 0x263094, Func Offset: 0x11e4
	// Line 2299, Address: 0x26309c, Func Offset: 0x11ec
	// Line 2300, Address: 0x2630ac, Func Offset: 0x11fc
	// Line 2301, Address: 0x2630bc, Func Offset: 0x120c
	// Line 2302, Address: 0x2630cc, Func Offset: 0x121c
	// Line 2303, Address: 0x2630dc, Func Offset: 0x122c
	// Line 2304, Address: 0x2630e0, Func Offset: 0x1230
	// Line 2305, Address: 0x2630e8, Func Offset: 0x1238
	// Line 2306, Address: 0x2630ec, Func Offset: 0x123c
	// Line 2308, Address: 0x2630f8, Func Offset: 0x1248
	// Line 2309, Address: 0x263100, Func Offset: 0x1250
	// Line 2310, Address: 0x263110, Func Offset: 0x1260
	// Line 2311, Address: 0x263114, Func Offset: 0x1264
	// Line 2312, Address: 0x26311c, Func Offset: 0x126c
	// Line 2313, Address: 0x263120, Func Offset: 0x1270
	// Line 2317, Address: 0x263128, Func Offset: 0x1278
	// Line 2318, Address: 0x263130, Func Offset: 0x1280
	// Line 2320, Address: 0x263144, Func Offset: 0x1294
	// Line 2321, Address: 0x263154, Func Offset: 0x12a4
	// Line 2322, Address: 0x263160, Func Offset: 0x12b0
	// Line 2323, Address: 0x263170, Func Offset: 0x12c0
	// Line 2324, Address: 0x263180, Func Offset: 0x12d0
	// Line 2325, Address: 0x263184, Func Offset: 0x12d4
	// Line 2326, Address: 0x26318c, Func Offset: 0x12dc
	// Line 2327, Address: 0x263190, Func Offset: 0x12e0
	// Line 2329, Address: 0x26319c, Func Offset: 0x12ec
	// Line 2330, Address: 0x2631a4, Func Offset: 0x12f4
	// Line 2332, Address: 0x2631c0, Func Offset: 0x1310
	// Line 2333, Address: 0x2631c4, Func Offset: 0x1314
	// Line 2336, Address: 0x2631cc, Func Offset: 0x131c
	// Line 2338, Address: 0x2631d4, Func Offset: 0x1324
	// Line 2339, Address: 0x2631e4, Func Offset: 0x1334
	// Line 2340, Address: 0x2631f4, Func Offset: 0x1344
	// Line 2341, Address: 0x263204, Func Offset: 0x1354
	// Line 2342, Address: 0x263214, Func Offset: 0x1364
	// Line 2343, Address: 0x263218, Func Offset: 0x1368
	// Line 2344, Address: 0x263220, Func Offset: 0x1370
	// Line 2345, Address: 0x263224, Func Offset: 0x1374
	// Line 2347, Address: 0x263230, Func Offset: 0x1380
	// Line 2348, Address: 0x263238, Func Offset: 0x1388
	// Line 2349, Address: 0x263248, Func Offset: 0x1398
	// Line 2350, Address: 0x26324c, Func Offset: 0x139c
	// Line 2351, Address: 0x263254, Func Offset: 0x13a4
	// Line 2352, Address: 0x263258, Func Offset: 0x13a8
	// Line 2358, Address: 0x263264, Func Offset: 0x13b4
	// Line 2362, Address: 0x26326c, Func Offset: 0x13bc
	// Line 2363, Address: 0x263280, Func Offset: 0x13d0
	// Line 2364, Address: 0x263284, Func Offset: 0x13d4
	// Func End, Address: 0x2632e0, Func Offset: 0x1430
}

// 
// Start address: 0x2632e0
void bhSetWallRefAngle(_anon0* hp, _anon20* pos, float ar, float ah, int* ay)
{
	int r;
	float abz;
	float aby;
	float abx;
	float h;
	float wpz;
	float wpx;
	float ln2;
	float ln;
	float zn;
	float xn;
	float pz;
	float py;
	float px;
	_anon0 ht;
	_anon39 l;
	_anon20 pd;
	// Line 2378, Address: 0x2632e0, Func Offset: 0
	// Line 2388, Address: 0x2632e4, Func Offset: 0x4
	// Line 2378, Address: 0x2632e8, Func Offset: 0x8
	// Line 2388, Address: 0x26332c, Func Offset: 0x4c
	// Line 2389, Address: 0x263368, Func Offset: 0x88
	// Line 2392, Address: 0x263394, Func Offset: 0xb4
	// Line 2393, Address: 0x2633a4, Func Offset: 0xc4
	// Line 2398, Address: 0x2633a8, Func Offset: 0xc8
	// Line 2392, Address: 0x2633ac, Func Offset: 0xcc
	// Line 2396, Address: 0x2633b0, Func Offset: 0xd0
	// Line 2393, Address: 0x2633b4, Func Offset: 0xd4
	// Line 2398, Address: 0x2633b8, Func Offset: 0xd8
	// Line 2392, Address: 0x2633bc, Func Offset: 0xdc
	// Line 2396, Address: 0x2633c0, Func Offset: 0xe0
	// Line 2393, Address: 0x2633c4, Func Offset: 0xe4
	// Line 2396, Address: 0x2633c8, Func Offset: 0xe8
	// Line 2398, Address: 0x2633cc, Func Offset: 0xec
	// Line 2394, Address: 0x2633d0, Func Offset: 0xf0
	// Line 2395, Address: 0x2633d4, Func Offset: 0xf4
	// Line 2393, Address: 0x2633d8, Func Offset: 0xf8
	// Line 2396, Address: 0x2633dc, Func Offset: 0xfc
	// Line 2397, Address: 0x2633e0, Func Offset: 0x100
	// Line 2398, Address: 0x2633e4, Func Offset: 0x104
	// Line 2399, Address: 0x2633ec, Func Offset: 0x10c
	// Line 2400, Address: 0x263400, Func Offset: 0x120
	// Line 2402, Address: 0x263414, Func Offset: 0x134
	// Line 2403, Address: 0x263420, Func Offset: 0x140
	// Line 2404, Address: 0x26342c, Func Offset: 0x14c
	// Line 2405, Address: 0x26343c, Func Offset: 0x15c
	// Line 2407, Address: 0x26345c, Func Offset: 0x17c
	// Line 2408, Address: 0x263460, Func Offset: 0x180
	// Line 2410, Address: 0x26346c, Func Offset: 0x18c
	// Line 2411, Address: 0x263474, Func Offset: 0x194
	// Line 2413, Address: 0x263494, Func Offset: 0x1b4
	// Line 2414, Address: 0x263498, Func Offset: 0x1b8
	// Line 2417, Address: 0x2634a0, Func Offset: 0x1c0
	// Line 2419, Address: 0x2634a8, Func Offset: 0x1c8
	// Line 2420, Address: 0x2634b4, Func Offset: 0x1d4
	// Line 2419, Address: 0x2634b8, Func Offset: 0x1d8
	// Line 2420, Address: 0x2634bc, Func Offset: 0x1dc
	// Line 2421, Address: 0x2634c8, Func Offset: 0x1e8
	// Line 2422, Address: 0x2634d8, Func Offset: 0x1f8
	// Line 2424, Address: 0x2634f8, Func Offset: 0x218
	// Line 2425, Address: 0x2634fc, Func Offset: 0x21c
	// Line 2427, Address: 0x263508, Func Offset: 0x228
	// Line 2428, Address: 0x263510, Func Offset: 0x230
	// Line 2430, Address: 0x263530, Func Offset: 0x250
	// Line 2431, Address: 0x263534, Func Offset: 0x254
	// Line 2435, Address: 0x26353c, Func Offset: 0x25c
	// Line 2436, Address: 0x263544, Func Offset: 0x264
	// Line 2438, Address: 0x263558, Func Offset: 0x278
	// Line 2439, Address: 0x263568, Func Offset: 0x288
	// Line 2440, Address: 0x263574, Func Offset: 0x294
	// Line 2441, Address: 0x263584, Func Offset: 0x2a4
	// Line 2443, Address: 0x2635a4, Func Offset: 0x2c4
	// Line 2444, Address: 0x2635a8, Func Offset: 0x2c8
	// Line 2446, Address: 0x2635b4, Func Offset: 0x2d4
	// Line 2447, Address: 0x2635bc, Func Offset: 0x2dc
	// Line 2449, Address: 0x2635dc, Func Offset: 0x2fc
	// Line 2450, Address: 0x2635e0, Func Offset: 0x300
	// Line 2453, Address: 0x2635e8, Func Offset: 0x308
	// Line 2455, Address: 0x2635f0, Func Offset: 0x310
	// Line 2456, Address: 0x2635fc, Func Offset: 0x31c
	// Line 2455, Address: 0x263600, Func Offset: 0x320
	// Line 2456, Address: 0x263604, Func Offset: 0x324
	// Line 2457, Address: 0x263610, Func Offset: 0x330
	// Line 2458, Address: 0x263620, Func Offset: 0x340
	// Line 2460, Address: 0x263640, Func Offset: 0x360
	// Line 2461, Address: 0x263644, Func Offset: 0x364
	// Line 2463, Address: 0x263650, Func Offset: 0x370
	// Line 2464, Address: 0x263658, Func Offset: 0x378
	// Line 2466, Address: 0x263678, Func Offset: 0x398
	// Line 2467, Address: 0x26367c, Func Offset: 0x39c
	// Line 2472, Address: 0x263684, Func Offset: 0x3a4
	// Line 2475, Address: 0x26368c, Func Offset: 0x3ac
	// Line 2476, Address: 0x263694, Func Offset: 0x3b4
	// Line 2475, Address: 0x26369c, Func Offset: 0x3bc
	// Line 2476, Address: 0x2636a0, Func Offset: 0x3c0
	// Line 2477, Address: 0x2636a4, Func Offset: 0x3c4
	// Line 2478, Address: 0x2636b0, Func Offset: 0x3d0
	// Line 2480, Address: 0x2636d4, Func Offset: 0x3f4
	// Line 2479, Address: 0x2636d8, Func Offset: 0x3f8
	// Line 2480, Address: 0x2636dc, Func Offset: 0x3fc
	// Line 2478, Address: 0x2636e0, Func Offset: 0x400
	// Line 2480, Address: 0x2636e4, Func Offset: 0x404
	// Line 2479, Address: 0x2636e8, Func Offset: 0x408
	// Line 2480, Address: 0x2636ec, Func Offset: 0x40c
	// Line 2481, Address: 0x2636f4, Func Offset: 0x414
	// Line 2483, Address: 0x263710, Func Offset: 0x430
	// Line 2484, Address: 0x263720, Func Offset: 0x440
	// Line 2490, Address: 0x263724, Func Offset: 0x444
	// Line 2484, Address: 0x263728, Func Offset: 0x448
	// Line 2490, Address: 0x26372c, Func Offset: 0x44c
	// Line 2484, Address: 0x263730, Func Offset: 0x450
	// Line 2485, Address: 0x26373c, Func Offset: 0x45c
	// Line 2490, Address: 0x263750, Func Offset: 0x470
	// Line 2491, Address: 0x26375c, Func Offset: 0x47c
	// Line 2492, Address: 0x263764, Func Offset: 0x484
	// Line 2494, Address: 0x26376c, Func Offset: 0x48c
	// Line 2498, Address: 0x263774, Func Offset: 0x494
	// Line 2499, Address: 0x263790, Func Offset: 0x4b0
	// Line 2500, Address: 0x263798, Func Offset: 0x4b8
	// Line 2502, Address: 0x2637d0, Func Offset: 0x4f0
	// Line 2503, Address: 0x2637d4, Func Offset: 0x4f4
	// Line 2502, Address: 0x2637d8, Func Offset: 0x4f8
	// Line 2504, Address: 0x2637dc, Func Offset: 0x4fc
	// Line 2506, Address: 0x2637e4, Func Offset: 0x504
	// Line 2507, Address: 0x2637e8, Func Offset: 0x508
	// Line 2506, Address: 0x2637ec, Func Offset: 0x50c
	// Line 2508, Address: 0x2637f0, Func Offset: 0x510
	// Line 2510, Address: 0x2637f8, Func Offset: 0x518
	// Line 2511, Address: 0x2637fc, Func Offset: 0x51c
	// Line 2510, Address: 0x263800, Func Offset: 0x520
	// Line 2512, Address: 0x263804, Func Offset: 0x524
	// Line 2514, Address: 0x26380c, Func Offset: 0x52c
	// Line 2515, Address: 0x263810, Func Offset: 0x530
	// Line 2514, Address: 0x263814, Func Offset: 0x534
	// Line 2515, Address: 0x263818, Func Offset: 0x538
	// Line 2518, Address: 0x26381c, Func Offset: 0x53c
	// Line 2519, Address: 0x263820, Func Offset: 0x540
	// Line 2522, Address: 0x263824, Func Offset: 0x544
	// Line 2519, Address: 0x263830, Func Offset: 0x550
	// Line 2520, Address: 0x263838, Func Offset: 0x558
	// Line 2521, Address: 0x263840, Func Offset: 0x560
	// Line 2522, Address: 0x263848, Func Offset: 0x568
	// Line 2524, Address: 0x263850, Func Offset: 0x570
	// Line 2523, Address: 0x263854, Func Offset: 0x574
	// Line 2524, Address: 0x26385c, Func Offset: 0x57c
	// Line 2523, Address: 0x263864, Func Offset: 0x584
	// Line 2524, Address: 0x263868, Func Offset: 0x588
	// Line 2525, Address: 0x26386c, Func Offset: 0x58c
	// Line 2526, Address: 0x26387c, Func Offset: 0x59c
	// Line 2527, Address: 0x263890, Func Offset: 0x5b0
	// Line 2528, Address: 0x2638a0, Func Offset: 0x5c0
	// Line 2529, Address: 0x2638a8, Func Offset: 0x5c8
	// Line 2530, Address: 0x2638b0, Func Offset: 0x5d0
	// Line 2531, Address: 0x2638d0, Func Offset: 0x5f0
	// Line 2532, Address: 0x2638e4, Func Offset: 0x604
	// Line 2533, Address: 0x2638ec, Func Offset: 0x60c
	// Line 2535, Address: 0x2638f4, Func Offset: 0x614
	// Line 2537, Address: 0x2638fc, Func Offset: 0x61c
	// Line 2540, Address: 0x263934, Func Offset: 0x654
	// Line 2543, Address: 0x263938, Func Offset: 0x658
	// Line 2546, Address: 0x26393c, Func Offset: 0x65c
	// Line 2544, Address: 0x263940, Func Offset: 0x660
	// Line 2546, Address: 0x263944, Func Offset: 0x664
	// Line 2545, Address: 0x263948, Func Offset: 0x668
	// Line 2540, Address: 0x26394c, Func Offset: 0x66c
	// Line 2541, Address: 0x263950, Func Offset: 0x670
	// Line 2546, Address: 0x263954, Func Offset: 0x674
	// Line 2541, Address: 0x263960, Func Offset: 0x680
	// Line 2542, Address: 0x263964, Func Offset: 0x684
	// Line 2543, Address: 0x26396c, Func Offset: 0x68c
	// Line 2544, Address: 0x263970, Func Offset: 0x690
	// Line 2545, Address: 0x263978, Func Offset: 0x698
	// Line 2546, Address: 0x26397c, Func Offset: 0x69c
	// Line 2547, Address: 0x26398c, Func Offset: 0x6ac
	// Line 2548, Address: 0x263994, Func Offset: 0x6b4
	// Line 2551, Address: 0x26399c, Func Offset: 0x6bc
	// Line 2554, Address: 0x2639a0, Func Offset: 0x6c0
	// Line 2551, Address: 0x2639b4, Func Offset: 0x6d4
	// Line 2552, Address: 0x2639b8, Func Offset: 0x6d8
	// Line 2554, Address: 0x2639c0, Func Offset: 0x6e0
	// Line 2555, Address: 0x2639d0, Func Offset: 0x6f0
	// Line 2556, Address: 0x2639d8, Func Offset: 0x6f8
	// Line 2561, Address: 0x2639e0, Func Offset: 0x700
	// Line 2563, Address: 0x2639e4, Func Offset: 0x704
	// Line 2567, Address: 0x2639e8, Func Offset: 0x708
	// Line 2564, Address: 0x2639ec, Func Offset: 0x70c
	// Line 2567, Address: 0x2639f0, Func Offset: 0x710
	// Line 2565, Address: 0x2639f4, Func Offset: 0x714
	// Line 2561, Address: 0x2639f8, Func Offset: 0x718
	// Line 2562, Address: 0x2639fc, Func Offset: 0x71c
	// Line 2566, Address: 0x263a00, Func Offset: 0x720
	// Line 2567, Address: 0x263a04, Func Offset: 0x724
	// Line 2562, Address: 0x263a0c, Func Offset: 0x72c
	// Line 2563, Address: 0x263a10, Func Offset: 0x730
	// Line 2567, Address: 0x263a18, Func Offset: 0x738
	// Line 2563, Address: 0x263a1c, Func Offset: 0x73c
	// Line 2564, Address: 0x263a24, Func Offset: 0x744
	// Line 2565, Address: 0x263a28, Func Offset: 0x748
	// Line 2566, Address: 0x263a30, Func Offset: 0x750
	// Line 2567, Address: 0x263a38, Func Offset: 0x758
	// Line 2568, Address: 0x263a48, Func Offset: 0x768
	// Line 2569, Address: 0x263a50, Func Offset: 0x770
	// Line 2572, Address: 0x263a58, Func Offset: 0x778
	// Line 2576, Address: 0x263a60, Func Offset: 0x780
	// Line 2572, Address: 0x263a70, Func Offset: 0x790
	// Line 2576, Address: 0x263a74, Func Offset: 0x794
	// Line 2572, Address: 0x263a78, Func Offset: 0x798
	// Line 2573, Address: 0x263a7c, Func Offset: 0x79c
	// Line 2574, Address: 0x263a84, Func Offset: 0x7a4
	// Line 2576, Address: 0x263a8c, Func Offset: 0x7ac
	// Line 2577, Address: 0x263a9c, Func Offset: 0x7bc
	// Line 2578, Address: 0x263aa4, Func Offset: 0x7c4
	// Line 2583, Address: 0x263aac, Func Offset: 0x7cc
	// Line 2589, Address: 0x263ab8, Func Offset: 0x7d8
	// Line 2586, Address: 0x263abc, Func Offset: 0x7dc
	// Line 2589, Address: 0x263ac0, Func Offset: 0x7e0
	// Line 2583, Address: 0x263ac4, Func Offset: 0x7e4
	// Line 2587, Address: 0x263ac8, Func Offset: 0x7e8
	// Line 2588, Address: 0x263acc, Func Offset: 0x7ec
	// Line 2583, Address: 0x263ad0, Func Offset: 0x7f0
	// Line 2584, Address: 0x263ad4, Func Offset: 0x7f4
	// Line 2589, Address: 0x263ad8, Func Offset: 0x7f8
	// Line 2584, Address: 0x263ae0, Func Offset: 0x800
	// Line 2585, Address: 0x263ae4, Func Offset: 0x804
	// Line 2586, Address: 0x263aec, Func Offset: 0x80c
	// Line 2587, Address: 0x263af0, Func Offset: 0x810
	// Line 2588, Address: 0x263af8, Func Offset: 0x818
	// Line 2589, Address: 0x263afc, Func Offset: 0x81c
	// Line 2590, Address: 0x263b0c, Func Offset: 0x82c
	// Line 2591, Address: 0x263b14, Func Offset: 0x834
	// Line 2594, Address: 0x263b1c, Func Offset: 0x83c
	// Line 2598, Address: 0x263b24, Func Offset: 0x844
	// Line 2594, Address: 0x263b38, Func Offset: 0x858
	// Line 2595, Address: 0x263b40, Func Offset: 0x860
	// Line 2596, Address: 0x263b4c, Func Offset: 0x86c
	// Line 2598, Address: 0x263b54, Func Offset: 0x874
	// Line 2599, Address: 0x263b64, Func Offset: 0x884
	// Line 2600, Address: 0x263b6c, Func Offset: 0x88c
	// Line 2605, Address: 0x263b74, Func Offset: 0x894
	// Line 2611, Address: 0x263b80, Func Offset: 0x8a0
	// Line 2607, Address: 0x263b84, Func Offset: 0x8a4
	// Line 2611, Address: 0x263b88, Func Offset: 0x8a8
	// Line 2605, Address: 0x263b8c, Func Offset: 0x8ac
	// Line 2608, Address: 0x263b90, Func Offset: 0x8b0
	// Line 2609, Address: 0x263b94, Func Offset: 0x8b4
	// Line 2605, Address: 0x263b98, Func Offset: 0x8b8
	// Line 2606, Address: 0x263b9c, Func Offset: 0x8bc
	// Line 2610, Address: 0x263ba0, Func Offset: 0x8c0
	// Line 2611, Address: 0x263ba4, Func Offset: 0x8c4
	// Line 2606, Address: 0x263bac, Func Offset: 0x8cc
	// Line 2607, Address: 0x263bb0, Func Offset: 0x8d0
	// Line 2608, Address: 0x263bc0, Func Offset: 0x8e0
	// Line 2609, Address: 0x263bc4, Func Offset: 0x8e4
	// Line 2610, Address: 0x263bcc, Func Offset: 0x8ec
	// Line 2611, Address: 0x263bd4, Func Offset: 0x8f4
	// Line 2612, Address: 0x263be4, Func Offset: 0x904
	// Line 2613, Address: 0x263bec, Func Offset: 0x90c
	// Line 2616, Address: 0x263bf4, Func Offset: 0x914
	// Line 2617, Address: 0x263bfc, Func Offset: 0x91c
	// Line 2621, Address: 0x263c00, Func Offset: 0x920
	// Line 2616, Address: 0x263c10, Func Offset: 0x930
	// Line 2621, Address: 0x263c14, Func Offset: 0x934
	// Line 2616, Address: 0x263c18, Func Offset: 0x938
	// Line 2617, Address: 0x263c1c, Func Offset: 0x93c
	// Line 2618, Address: 0x263c28, Func Offset: 0x948
	// Line 2619, Address: 0x263c34, Func Offset: 0x954
	// Line 2621, Address: 0x263c3c, Func Offset: 0x95c
	// Line 2622, Address: 0x263c4c, Func Offset: 0x96c
	// Line 2623, Address: 0x263c54, Func Offset: 0x974
	// Line 2630, Address: 0x263c5c, Func Offset: 0x97c
	// Line 2633, Address: 0x263c94, Func Offset: 0x9b4
	// Line 2634, Address: 0x263cb0, Func Offset: 0x9d0
	// Line 2637, Address: 0x263cb8, Func Offset: 0x9d8
	// Line 2638, Address: 0x263cd8, Func Offset: 0x9f8
	// Line 2641, Address: 0x263ce0, Func Offset: 0xa00
	// Line 2642, Address: 0x263cfc, Func Offset: 0xa1c
	// Line 2645, Address: 0x263d04, Func Offset: 0xa24
	// Line 2648, Address: 0x263d28, Func Offset: 0xa48
	// Line 2649, Address: 0x263d3c, Func Offset: 0xa5c
	// Line 2650, Address: 0x263d44, Func Offset: 0xa64
	// Line 2651, Address: 0x263d54, Func Offset: 0xa74
	// Line 2656, Address: 0x263d58, Func Offset: 0xa78
	// Line 2650, Address: 0x263d5c, Func Offset: 0xa7c
	// Line 2651, Address: 0x263d60, Func Offset: 0xa80
	// Line 2654, Address: 0x263d64, Func Offset: 0xa84
	// Line 2650, Address: 0x263d68, Func Offset: 0xa88
	// Line 2649, Address: 0x263d6c, Func Offset: 0xa8c
	// Line 2654, Address: 0x263d70, Func Offset: 0xa90
	// Line 2656, Address: 0x263d78, Func Offset: 0xa98
	// Line 2651, Address: 0x263d7c, Func Offset: 0xa9c
	// Line 2654, Address: 0x263d80, Func Offset: 0xaa0
	// Line 2652, Address: 0x263d84, Func Offset: 0xaa4
	// Line 2653, Address: 0x263d88, Func Offset: 0xaa8
	// Line 2651, Address: 0x263d8c, Func Offset: 0xaac
	// Line 2654, Address: 0x263d90, Func Offset: 0xab0
	// Line 2656, Address: 0x263d94, Func Offset: 0xab4
	// Line 2657, Address: 0x263d9c, Func Offset: 0xabc
	// Line 2659, Address: 0x263db0, Func Offset: 0xad0
	// Line 2660, Address: 0x263dbc, Func Offset: 0xadc
	// Line 2661, Address: 0x263dc8, Func Offset: 0xae8
	// Line 2662, Address: 0x263dd8, Func Offset: 0xaf8
	// Line 2664, Address: 0x263df0, Func Offset: 0xb10
	// Line 2665, Address: 0x263df4, Func Offset: 0xb14
	// Line 2667, Address: 0x263e00, Func Offset: 0xb20
	// Line 2668, Address: 0x263e08, Func Offset: 0xb28
	// Line 2670, Address: 0x263e20, Func Offset: 0xb40
	// Line 2671, Address: 0x263e24, Func Offset: 0xb44
	// Line 2674, Address: 0x263e2c, Func Offset: 0xb4c
	// Line 2676, Address: 0x263e34, Func Offset: 0xb54
	// Line 2677, Address: 0x263e40, Func Offset: 0xb60
	// Line 2676, Address: 0x263e44, Func Offset: 0xb64
	// Line 2677, Address: 0x263e48, Func Offset: 0xb68
	// Line 2678, Address: 0x263e54, Func Offset: 0xb74
	// Line 2679, Address: 0x263e64, Func Offset: 0xb84
	// Line 2681, Address: 0x263e7c, Func Offset: 0xb9c
	// Line 2682, Address: 0x263e80, Func Offset: 0xba0
	// Line 2684, Address: 0x263e8c, Func Offset: 0xbac
	// Line 2685, Address: 0x263e94, Func Offset: 0xbb4
	// Line 2687, Address: 0x263eac, Func Offset: 0xbcc
	// Line 2688, Address: 0x263eb0, Func Offset: 0xbd0
	// Line 2692, Address: 0x263eb8, Func Offset: 0xbd8
	// Line 2693, Address: 0x263ec0, Func Offset: 0xbe0
	// Line 2695, Address: 0x263ed4, Func Offset: 0xbf4
	// Line 2696, Address: 0x263ee4, Func Offset: 0xc04
	// Line 2697, Address: 0x263ef0, Func Offset: 0xc10
	// Line 2698, Address: 0x263f00, Func Offset: 0xc20
	// Line 2700, Address: 0x263f18, Func Offset: 0xc38
	// Line 2701, Address: 0x263f1c, Func Offset: 0xc3c
	// Line 2703, Address: 0x263f28, Func Offset: 0xc48
	// Line 2704, Address: 0x263f30, Func Offset: 0xc50
	// Line 2706, Address: 0x263f48, Func Offset: 0xc68
	// Line 2707, Address: 0x263f4c, Func Offset: 0xc6c
	// Line 2710, Address: 0x263f54, Func Offset: 0xc74
	// Line 2712, Address: 0x263f5c, Func Offset: 0xc7c
	// Line 2713, Address: 0x263f68, Func Offset: 0xc88
	// Line 2712, Address: 0x263f6c, Func Offset: 0xc8c
	// Line 2713, Address: 0x263f70, Func Offset: 0xc90
	// Line 2714, Address: 0x263f7c, Func Offset: 0xc9c
	// Line 2715, Address: 0x263f8c, Func Offset: 0xcac
	// Line 2717, Address: 0x263fa4, Func Offset: 0xcc4
	// Line 2718, Address: 0x263fa8, Func Offset: 0xcc8
	// Line 2720, Address: 0x263fb4, Func Offset: 0xcd4
	// Line 2721, Address: 0x263fbc, Func Offset: 0xcdc
	// Line 2723, Address: 0x263fd4, Func Offset: 0xcf4
	// Line 2724, Address: 0x263fd8, Func Offset: 0xcf8
	// Line 2730, Address: 0x263fe0, Func Offset: 0xd00
	// Line 2738, Address: 0x263fe8, Func Offset: 0xd08
	// Line 2732, Address: 0x263ff0, Func Offset: 0xd10
	// Line 2733, Address: 0x263ff8, Func Offset: 0xd18
	// Line 2732, Address: 0x264000, Func Offset: 0xd20
	// Line 2738, Address: 0x264004, Func Offset: 0xd24
	// Line 2736, Address: 0x264008, Func Offset: 0xd28
	// Line 2732, Address: 0x26400c, Func Offset: 0xd2c
	// Line 2733, Address: 0x264010, Func Offset: 0xd30
	// Line 2736, Address: 0x264018, Func Offset: 0xd38
	// Line 2732, Address: 0x26401c, Func Offset: 0xd3c
	// Line 2736, Address: 0x264020, Func Offset: 0xd40
	// Line 2734, Address: 0x264024, Func Offset: 0xd44
	// Line 2732, Address: 0x264028, Func Offset: 0xd48
	// Line 2735, Address: 0x26402c, Func Offset: 0xd4c
	// Line 2736, Address: 0x264030, Func Offset: 0xd50
	// Line 2738, Address: 0x264034, Func Offset: 0xd54
	// Line 2739, Address: 0x26403c, Func Offset: 0xd5c
	// Line 2740, Address: 0x264050, Func Offset: 0xd70
	// Line 2742, Address: 0x264064, Func Offset: 0xd84
	// Line 2743, Address: 0x264070, Func Offset: 0xd90
	// Line 2744, Address: 0x26407c, Func Offset: 0xd9c
	// Line 2745, Address: 0x26408c, Func Offset: 0xdac
	// Line 2746, Address: 0x26409c, Func Offset: 0xdbc
	// Line 2747, Address: 0x2640a0, Func Offset: 0xdc0
	// Line 2748, Address: 0x2640a8, Func Offset: 0xdc8
	// Line 2749, Address: 0x2640ac, Func Offset: 0xdcc
	// Line 2751, Address: 0x2640b8, Func Offset: 0xdd8
	// Line 2752, Address: 0x2640c0, Func Offset: 0xde0
	// Line 2753, Address: 0x2640d0, Func Offset: 0xdf0
	// Line 2754, Address: 0x2640d4, Func Offset: 0xdf4
	// Line 2755, Address: 0x2640dc, Func Offset: 0xdfc
	// Line 2756, Address: 0x2640e0, Func Offset: 0xe00
	// Line 2759, Address: 0x2640e8, Func Offset: 0xe08
	// Line 2761, Address: 0x2640f0, Func Offset: 0xe10
	// Line 2762, Address: 0x264100, Func Offset: 0xe20
	// Line 2763, Address: 0x264110, Func Offset: 0xe30
	// Line 2764, Address: 0x264120, Func Offset: 0xe40
	// Line 2765, Address: 0x264130, Func Offset: 0xe50
	// Line 2766, Address: 0x264134, Func Offset: 0xe54
	// Line 2767, Address: 0x26413c, Func Offset: 0xe5c
	// Line 2768, Address: 0x264140, Func Offset: 0xe60
	// Line 2770, Address: 0x26414c, Func Offset: 0xe6c
	// Line 2771, Address: 0x264154, Func Offset: 0xe74
	// Line 2772, Address: 0x264164, Func Offset: 0xe84
	// Line 2773, Address: 0x264168, Func Offset: 0xe88
	// Line 2774, Address: 0x264170, Func Offset: 0xe90
	// Line 2775, Address: 0x264174, Func Offset: 0xe94
	// Line 2779, Address: 0x26417c, Func Offset: 0xe9c
	// Line 2780, Address: 0x264184, Func Offset: 0xea4
	// Line 2782, Address: 0x264198, Func Offset: 0xeb8
	// Line 2783, Address: 0x2641a8, Func Offset: 0xec8
	// Line 2784, Address: 0x2641b4, Func Offset: 0xed4
	// Line 2785, Address: 0x2641c4, Func Offset: 0xee4
	// Line 2786, Address: 0x2641d4, Func Offset: 0xef4
	// Line 2787, Address: 0x2641d8, Func Offset: 0xef8
	// Line 2788, Address: 0x2641e0, Func Offset: 0xf00
	// Line 2789, Address: 0x2641e4, Func Offset: 0xf04
	// Line 2791, Address: 0x2641f0, Func Offset: 0xf10
	// Line 2792, Address: 0x2641f8, Func Offset: 0xf18
	// Line 2794, Address: 0x264214, Func Offset: 0xf34
	// Line 2795, Address: 0x264218, Func Offset: 0xf38
	// Line 2798, Address: 0x264220, Func Offset: 0xf40
	// Line 2800, Address: 0x264228, Func Offset: 0xf48
	// Line 2801, Address: 0x264238, Func Offset: 0xf58
	// Line 2802, Address: 0x264248, Func Offset: 0xf68
	// Line 2803, Address: 0x264258, Func Offset: 0xf78
	// Line 2804, Address: 0x264268, Func Offset: 0xf88
	// Line 2805, Address: 0x26426c, Func Offset: 0xf8c
	// Line 2806, Address: 0x264274, Func Offset: 0xf94
	// Line 2807, Address: 0x264278, Func Offset: 0xf98
	// Line 2809, Address: 0x264284, Func Offset: 0xfa4
	// Line 2810, Address: 0x26428c, Func Offset: 0xfac
	// Line 2811, Address: 0x26429c, Func Offset: 0xfbc
	// Line 2812, Address: 0x2642a0, Func Offset: 0xfc0
	// Line 2813, Address: 0x2642a8, Func Offset: 0xfc8
	// Line 2814, Address: 0x2642ac, Func Offset: 0xfcc
	// Line 2821, Address: 0x2642b8, Func Offset: 0xfd8
	// Func End, Address: 0x264304, Func Offset: 0x1024
}

// 
// Start address: 0x264310
float bhGetGroundPosition(_anon20* pos)
{
	float nr;
	float yn;
	float yy;
	float h;
	float ln;
	float pz;
	float px;
	int wal_n;
	int i;
	_anon0* hp;
	_anon20 pd;
	// Line 2834, Address: 0x264310, Func Offset: 0
	// Line 2843, Address: 0x264340, Func Offset: 0x30
	// Line 2844, Address: 0x264348, Func Offset: 0x38
	// Line 2845, Address: 0x264354, Func Offset: 0x44
	// Line 2843, Address: 0x26435c, Func Offset: 0x4c
	// Line 2845, Address: 0x264364, Func Offset: 0x54
	// Line 2843, Address: 0x264368, Func Offset: 0x58
	// Line 2846, Address: 0x26436c, Func Offset: 0x5c
	// Line 2847, Address: 0x264390, Func Offset: 0x80
	// Line 2849, Address: 0x2643a0, Func Offset: 0x90
	// Line 2850, Address: 0x2643ec, Func Offset: 0xdc
	// Line 2852, Address: 0x2643fc, Func Offset: 0xec
	// Line 2853, Address: 0x264428, Func Offset: 0x118
	// Line 2855, Address: 0x26446c, Func Offset: 0x15c
	// Line 2856, Address: 0x264470, Func Offset: 0x160
	// Line 2855, Address: 0x264478, Func Offset: 0x168
	// Line 2856, Address: 0x26447c, Func Offset: 0x16c
	// Line 2855, Address: 0x264480, Func Offset: 0x170
	// Line 2856, Address: 0x264484, Func Offset: 0x174
	// Line 2859, Address: 0x2644ec, Func Offset: 0x1dc
	// Line 2862, Address: 0x2644fc, Func Offset: 0x1ec
	// Line 2860, Address: 0x264504, Func Offset: 0x1f4
	// Line 2861, Address: 0x264508, Func Offset: 0x1f8
	// Line 2862, Address: 0x26450c, Func Offset: 0x1fc
	// Line 2865, Address: 0x264514, Func Offset: 0x204
	// Line 2867, Address: 0x26451c, Func Offset: 0x20c
	// Line 2868, Address: 0x264520, Func Offset: 0x210
	// Line 2869, Address: 0x264528, Func Offset: 0x218
	// Line 2867, Address: 0x264530, Func Offset: 0x220
	// Line 2868, Address: 0x264538, Func Offset: 0x228
	// Line 2869, Address: 0x26453c, Func Offset: 0x22c
	// Line 2870, Address: 0x264540, Func Offset: 0x230
	// Line 2867, Address: 0x264544, Func Offset: 0x234
	// Line 2870, Address: 0x264548, Func Offset: 0x238
	// Line 2871, Address: 0x264550, Func Offset: 0x240
	// Line 2873, Address: 0x26457c, Func Offset: 0x26c
	// Line 2876, Address: 0x26458c, Func Offset: 0x27c
	// Line 2875, Address: 0x264590, Func Offset: 0x280
	// Line 2876, Address: 0x264594, Func Offset: 0x284
	// Line 2874, Address: 0x264598, Func Offset: 0x288
	// Line 2875, Address: 0x26459c, Func Offset: 0x28c
	// Line 2876, Address: 0x2645a0, Func Offset: 0x290
	// Line 2879, Address: 0x2645a8, Func Offset: 0x298
	// Line 2881, Address: 0x2645b0, Func Offset: 0x2a0
	// Line 2882, Address: 0x2645b8, Func Offset: 0x2a8
	// Line 2885, Address: 0x2645bc, Func Offset: 0x2ac
	// Line 2881, Address: 0x2645c4, Func Offset: 0x2b4
	// Line 2882, Address: 0x2645c8, Func Offset: 0x2b8
	// Line 2883, Address: 0x2645cc, Func Offset: 0x2bc
	// Line 2881, Address: 0x2645d0, Func Offset: 0x2c0
	// Line 2883, Address: 0x2645d4, Func Offset: 0x2c4
	// Line 2884, Address: 0x2645d8, Func Offset: 0x2c8
	// Line 2885, Address: 0x2645dc, Func Offset: 0x2cc
	// Line 2887, Address: 0x264604, Func Offset: 0x2f4
	// Line 2890, Address: 0x264614, Func Offset: 0x304
	// Line 2889, Address: 0x264618, Func Offset: 0x308
	// Line 2890, Address: 0x26461c, Func Offset: 0x30c
	// Line 2888, Address: 0x264620, Func Offset: 0x310
	// Line 2889, Address: 0x264624, Func Offset: 0x314
	// Line 2890, Address: 0x264628, Func Offset: 0x318
	// Line 2893, Address: 0x264630, Func Offset: 0x320
	// Line 2896, Address: 0x264638, Func Offset: 0x328
	// Line 2895, Address: 0x264640, Func Offset: 0x330
	// Line 2896, Address: 0x264648, Func Offset: 0x338
	// Line 2899, Address: 0x2646b4, Func Offset: 0x3a4
	// Line 2902, Address: 0x2646ec, Func Offset: 0x3dc
	// Line 2903, Address: 0x264700, Func Offset: 0x3f0
	// Line 2906, Address: 0x264708, Func Offset: 0x3f8
	// Line 2907, Address: 0x26471c, Func Offset: 0x40c
	// Line 2910, Address: 0x264724, Func Offset: 0x414
	// Line 2911, Address: 0x264738, Func Offset: 0x428
	// Line 2914, Address: 0x264740, Func Offset: 0x430
	// Line 2917, Address: 0x264758, Func Offset: 0x448
	// Line 2918, Address: 0x26475c, Func Offset: 0x44c
	// Line 2921, Address: 0x26476c, Func Offset: 0x45c
	// Line 2919, Address: 0x264774, Func Offset: 0x464
	// Line 2920, Address: 0x264778, Func Offset: 0x468
	// Line 2921, Address: 0x26477c, Func Offset: 0x46c
	// Line 2924, Address: 0x264784, Func Offset: 0x474
	// Line 2926, Address: 0x26478c, Func Offset: 0x47c
	// Line 2928, Address: 0x264794, Func Offset: 0x484
	// Line 2926, Address: 0x26479c, Func Offset: 0x48c
	// Line 2928, Address: 0x2647a0, Func Offset: 0x490
	// Line 2930, Address: 0x2647d8, Func Offset: 0x4c8
	// Line 2933, Address: 0x26484c, Func Offset: 0x53c
	// Line 2936, Address: 0x26485c, Func Offset: 0x54c
	// Line 2934, Address: 0x264864, Func Offset: 0x554
	// Line 2935, Address: 0x264868, Func Offset: 0x558
	// Line 2936, Address: 0x26486c, Func Offset: 0x55c
	// Line 2941, Address: 0x264878, Func Offset: 0x568
	// Line 2945, Address: 0x264888, Func Offset: 0x578
	// Line 2946, Address: 0x26488c, Func Offset: 0x57c
	// Func End, Address: 0x2648c0, Func Offset: 0x5b0
}

// 
// Start address: 0x2648c0
int bhCheckInnerTriangle(_anon0* hp, _anon20* pos, float ar, float ah)
{
	float h;
	float pz;
	float px;
	_anon33 pd;
	_anon33 pc;
	_anon33 pb;
	_anon33 pa;
	_anon33 ps;
	// Line 2961, Address: 0x2648c0, Func Offset: 0
	// Line 2966, Address: 0x2648c4, Func Offset: 0x4
	// Line 2961, Address: 0x2648c8, Func Offset: 0x8
	// Line 2966, Address: 0x2648e8, Func Offset: 0x28
	// Line 2968, Address: 0x26491c, Func Offset: 0x5c
	// Line 2970, Address: 0x264958, Func Offset: 0x98
	// Line 2971, Address: 0x264974, Func Offset: 0xb4
	// Line 2972, Address: 0x264978, Func Offset: 0xb8
	// Line 2973, Address: 0x26497c, Func Offset: 0xbc
	// Line 2974, Address: 0x264984, Func Offset: 0xc4
	// Line 2977, Address: 0x264990, Func Offset: 0xd0
	// Line 2978, Address: 0x2649ac, Func Offset: 0xec
	// Line 2979, Address: 0x2649b0, Func Offset: 0xf0
	// Line 2980, Address: 0x2649b4, Func Offset: 0xf4
	// Line 2981, Address: 0x2649bc, Func Offset: 0xfc
	// Line 2984, Address: 0x2649c8, Func Offset: 0x108
	// Line 2985, Address: 0x264a10, Func Offset: 0x150
	// Line 2987, Address: 0x264a1c, Func Offset: 0x15c
	// Line 2989, Address: 0x264a34, Func Offset: 0x174
	// Line 2990, Address: 0x264a60, Func Offset: 0x1a0
	// Line 2994, Address: 0x264a90, Func Offset: 0x1d0
	// Line 2995, Address: 0x264a94, Func Offset: 0x1d4
	// Line 2998, Address: 0x264a98, Func Offset: 0x1d8
	// Line 2996, Address: 0x264a9c, Func Offset: 0x1dc
	// Line 2997, Address: 0x264aa0, Func Offset: 0x1e0
	// Line 2998, Address: 0x264aa8, Func Offset: 0x1e8
	// Line 3000, Address: 0x264adc, Func Offset: 0x21c
	// Line 3001, Address: 0x264ae0, Func Offset: 0x220
	// Line 3005, Address: 0x264ae4, Func Offset: 0x224
	// Line 3008, Address: 0x264ae8, Func Offset: 0x228
	// Line 3000, Address: 0x264aec, Func Offset: 0x22c
	// Line 3008, Address: 0x264af0, Func Offset: 0x230
	// Line 3000, Address: 0x264af8, Func Offset: 0x238
	// Line 3001, Address: 0x264afc, Func Offset: 0x23c
	// Line 3002, Address: 0x264b00, Func Offset: 0x240
	// Line 3008, Address: 0x264b04, Func Offset: 0x244
	// Line 3002, Address: 0x264b0c, Func Offset: 0x24c
	// Line 3003, Address: 0x264b14, Func Offset: 0x254
	// Line 3004, Address: 0x264b1c, Func Offset: 0x25c
	// Line 3003, Address: 0x264b20, Func Offset: 0x260
	// Line 3005, Address: 0x264b24, Func Offset: 0x264
	// Line 3006, Address: 0x264b30, Func Offset: 0x270
	// Line 3007, Address: 0x264b3c, Func Offset: 0x27c
	// Line 3008, Address: 0x264b44, Func Offset: 0x284
	// Line 3011, Address: 0x264b5c, Func Offset: 0x29c
	// Line 3009, Address: 0x264b60, Func Offset: 0x2a0
	// Line 3011, Address: 0x264b64, Func Offset: 0x2a4
	// Line 3014, Address: 0x264b90, Func Offset: 0x2d0
	// Line 3015, Address: 0x264b94, Func Offset: 0x2d4
	// Line 3019, Address: 0x264b98, Func Offset: 0x2d8
	// Line 3014, Address: 0x264b9c, Func Offset: 0x2dc
	// Line 3015, Address: 0x264ba0, Func Offset: 0x2e0
	// Line 3019, Address: 0x264ba4, Func Offset: 0x2e4
	// Line 3022, Address: 0x264ba8, Func Offset: 0x2e8
	// Line 3015, Address: 0x264bb0, Func Offset: 0x2f0
	// Line 3022, Address: 0x264bb4, Func Offset: 0x2f4
	// Line 3015, Address: 0x264bbc, Func Offset: 0x2fc
	// Line 3022, Address: 0x264bc0, Func Offset: 0x300
	// Line 3015, Address: 0x264bc4, Func Offset: 0x304
	// Line 3016, Address: 0x264bc8, Func Offset: 0x308
	// Line 3017, Address: 0x264bd4, Func Offset: 0x314
	// Line 3018, Address: 0x264be0, Func Offset: 0x320
	// Line 3019, Address: 0x264bf0, Func Offset: 0x330
	// Line 3020, Address: 0x264bf4, Func Offset: 0x334
	// Line 3021, Address: 0x264c00, Func Offset: 0x340
	// Line 3022, Address: 0x264c08, Func Offset: 0x348
	// Line 3025, Address: 0x264c20, Func Offset: 0x360
	// Line 3023, Address: 0x264c24, Func Offset: 0x364
	// Line 3025, Address: 0x264c28, Func Offset: 0x368
	// Line 3028, Address: 0x264c54, Func Offset: 0x394
	// Line 3029, Address: 0x264c58, Func Offset: 0x398
	// Line 3033, Address: 0x264c5c, Func Offset: 0x39c
	// Line 3036, Address: 0x264c60, Func Offset: 0x3a0
	// Line 3028, Address: 0x264c64, Func Offset: 0x3a4
	// Line 3036, Address: 0x264c68, Func Offset: 0x3a8
	// Line 3028, Address: 0x264c70, Func Offset: 0x3b0
	// Line 3029, Address: 0x264c74, Func Offset: 0x3b4
	// Line 3030, Address: 0x264c78, Func Offset: 0x3b8
	// Line 3036, Address: 0x264c7c, Func Offset: 0x3bc
	// Line 3030, Address: 0x264c84, Func Offset: 0x3c4
	// Line 3031, Address: 0x264c8c, Func Offset: 0x3cc
	// Line 3032, Address: 0x264c94, Func Offset: 0x3d4
	// Line 3031, Address: 0x264c98, Func Offset: 0x3d8
	// Line 3033, Address: 0x264c9c, Func Offset: 0x3dc
	// Line 3034, Address: 0x264ca8, Func Offset: 0x3e8
	// Line 3035, Address: 0x264cb4, Func Offset: 0x3f4
	// Line 3036, Address: 0x264cbc, Func Offset: 0x3fc
	// Line 3039, Address: 0x264cd4, Func Offset: 0x414
	// Line 3037, Address: 0x264cd8, Func Offset: 0x418
	// Line 3039, Address: 0x264cdc, Func Offset: 0x41c
	// Line 3042, Address: 0x264d08, Func Offset: 0x448
	// Line 3043, Address: 0x264d0c, Func Offset: 0x44c
	// Line 3047, Address: 0x264d10, Func Offset: 0x450
	// Line 3042, Address: 0x264d14, Func Offset: 0x454
	// Line 3043, Address: 0x264d18, Func Offset: 0x458
	// Line 3047, Address: 0x264d1c, Func Offset: 0x45c
	// Line 3050, Address: 0x264d20, Func Offset: 0x460
	// Line 3043, Address: 0x264d28, Func Offset: 0x468
	// Line 3050, Address: 0x264d2c, Func Offset: 0x46c
	// Line 3043, Address: 0x264d34, Func Offset: 0x474
	// Line 3050, Address: 0x264d38, Func Offset: 0x478
	// Line 3043, Address: 0x264d3c, Func Offset: 0x47c
	// Line 3044, Address: 0x264d40, Func Offset: 0x480
	// Line 3045, Address: 0x264d4c, Func Offset: 0x48c
	// Line 3046, Address: 0x264d58, Func Offset: 0x498
	// Line 3047, Address: 0x264d68, Func Offset: 0x4a8
	// Line 3048, Address: 0x264d6c, Func Offset: 0x4ac
	// Line 3049, Address: 0x264d78, Func Offset: 0x4b8
	// Line 3050, Address: 0x264d80, Func Offset: 0x4c0
	// Line 3053, Address: 0x264d98, Func Offset: 0x4d8
	// Line 3051, Address: 0x264d9c, Func Offset: 0x4dc
	// Line 3053, Address: 0x264da0, Func Offset: 0x4e0
	// Line 3057, Address: 0x264dcc, Func Offset: 0x50c
	// Line 3058, Address: 0x264df4, Func Offset: 0x534
	// Line 3057, Address: 0x264dfc, Func Offset: 0x53c
	// Line 3058, Address: 0x264e00, Func Offset: 0x540
	// Line 3060, Address: 0x264e20, Func Offset: 0x560
	// Line 3061, Address: 0x264e24, Func Offset: 0x564
	// Func End, Address: 0x264e4c, Func Offset: 0x58c
}

// 
// Start address: 0x264e50
int bhCheckInnerTriangle2(_anon0* hp, _anon20* pos, float aw, float ad, float ah)
{
	float h;
	float pz;
	float px;
	_anon33 pd;
	_anon33 pc;
	_anon33 pb;
	_anon33 pa;
	_anon33 ps;
	// Line 3077, Address: 0x264e50, Func Offset: 0
	// Line 3082, Address: 0x264e54, Func Offset: 0x4
	// Line 3077, Address: 0x264e58, Func Offset: 0x8
	// Line 3082, Address: 0x264e7c, Func Offset: 0x2c
	// Line 3084, Address: 0x264eb4, Func Offset: 0x64
	// Line 3086, Address: 0x264ef0, Func Offset: 0xa0
	// Line 3087, Address: 0x264f0c, Func Offset: 0xbc
	// Line 3088, Address: 0x264f10, Func Offset: 0xc0
	// Line 3089, Address: 0x264f14, Func Offset: 0xc4
	// Line 3090, Address: 0x264f1c, Func Offset: 0xcc
	// Line 3093, Address: 0x264f28, Func Offset: 0xd8
	// Line 3094, Address: 0x264f44, Func Offset: 0xf4
	// Line 3095, Address: 0x264f48, Func Offset: 0xf8
	// Line 3096, Address: 0x264f4c, Func Offset: 0xfc
	// Line 3097, Address: 0x264f54, Func Offset: 0x104
	// Line 3100, Address: 0x264f60, Func Offset: 0x110
	// Line 3101, Address: 0x264fa8, Func Offset: 0x158
	// Line 3103, Address: 0x264fb4, Func Offset: 0x164
	// Line 3105, Address: 0x264fdc, Func Offset: 0x18c
	// Line 3106, Address: 0x265008, Func Offset: 0x1b8
	// Line 3110, Address: 0x265038, Func Offset: 0x1e8
	// Line 3111, Address: 0x26503c, Func Offset: 0x1ec
	// Line 3114, Address: 0x265040, Func Offset: 0x1f0
	// Line 3112, Address: 0x265044, Func Offset: 0x1f4
	// Line 3113, Address: 0x265048, Func Offset: 0x1f8
	// Line 3114, Address: 0x265050, Func Offset: 0x200
	// Line 3116, Address: 0x265084, Func Offset: 0x234
	// Line 3117, Address: 0x265088, Func Offset: 0x238
	// Line 3121, Address: 0x26508c, Func Offset: 0x23c
	// Line 3124, Address: 0x265090, Func Offset: 0x240
	// Line 3116, Address: 0x265094, Func Offset: 0x244
	// Line 3124, Address: 0x265098, Func Offset: 0x248
	// Line 3116, Address: 0x2650a0, Func Offset: 0x250
	// Line 3117, Address: 0x2650a4, Func Offset: 0x254
	// Line 3118, Address: 0x2650a8, Func Offset: 0x258
	// Line 3124, Address: 0x2650ac, Func Offset: 0x25c
	// Line 3118, Address: 0x2650b4, Func Offset: 0x264
	// Line 3119, Address: 0x2650bc, Func Offset: 0x26c
	// Line 3120, Address: 0x2650c4, Func Offset: 0x274
	// Line 3119, Address: 0x2650c8, Func Offset: 0x278
	// Line 3121, Address: 0x2650cc, Func Offset: 0x27c
	// Line 3122, Address: 0x2650d8, Func Offset: 0x288
	// Line 3123, Address: 0x2650e4, Func Offset: 0x294
	// Line 3124, Address: 0x2650ec, Func Offset: 0x29c
	// Line 3127, Address: 0x265104, Func Offset: 0x2b4
	// Line 3125, Address: 0x265108, Func Offset: 0x2b8
	// Line 3127, Address: 0x26510c, Func Offset: 0x2bc
	// Line 3130, Address: 0x265138, Func Offset: 0x2e8
	// Line 3131, Address: 0x26513c, Func Offset: 0x2ec
	// Line 3135, Address: 0x265140, Func Offset: 0x2f0
	// Line 3130, Address: 0x265144, Func Offset: 0x2f4
	// Line 3131, Address: 0x265148, Func Offset: 0x2f8
	// Line 3135, Address: 0x26514c, Func Offset: 0x2fc
	// Line 3138, Address: 0x265150, Func Offset: 0x300
	// Line 3131, Address: 0x265158, Func Offset: 0x308
	// Line 3138, Address: 0x26515c, Func Offset: 0x30c
	// Line 3131, Address: 0x265164, Func Offset: 0x314
	// Line 3138, Address: 0x265168, Func Offset: 0x318
	// Line 3131, Address: 0x26516c, Func Offset: 0x31c
	// Line 3132, Address: 0x265170, Func Offset: 0x320
	// Line 3133, Address: 0x26517c, Func Offset: 0x32c
	// Line 3134, Address: 0x265188, Func Offset: 0x338
	// Line 3135, Address: 0x265198, Func Offset: 0x348
	// Line 3136, Address: 0x26519c, Func Offset: 0x34c
	// Line 3137, Address: 0x2651a8, Func Offset: 0x358
	// Line 3138, Address: 0x2651b0, Func Offset: 0x360
	// Line 3141, Address: 0x2651c8, Func Offset: 0x378
	// Line 3139, Address: 0x2651cc, Func Offset: 0x37c
	// Line 3141, Address: 0x2651d0, Func Offset: 0x380
	// Line 3144, Address: 0x2651fc, Func Offset: 0x3ac
	// Line 3145, Address: 0x265200, Func Offset: 0x3b0
	// Line 3149, Address: 0x265204, Func Offset: 0x3b4
	// Line 3152, Address: 0x265208, Func Offset: 0x3b8
	// Line 3144, Address: 0x26520c, Func Offset: 0x3bc
	// Line 3152, Address: 0x265210, Func Offset: 0x3c0
	// Line 3144, Address: 0x265218, Func Offset: 0x3c8
	// Line 3145, Address: 0x26521c, Func Offset: 0x3cc
	// Line 3146, Address: 0x265220, Func Offset: 0x3d0
	// Line 3152, Address: 0x265224, Func Offset: 0x3d4
	// Line 3146, Address: 0x26522c, Func Offset: 0x3dc
	// Line 3147, Address: 0x265234, Func Offset: 0x3e4
	// Line 3148, Address: 0x26523c, Func Offset: 0x3ec
	// Line 3147, Address: 0x265240, Func Offset: 0x3f0
	// Line 3149, Address: 0x265244, Func Offset: 0x3f4
	// Line 3150, Address: 0x265250, Func Offset: 0x400
	// Line 3151, Address: 0x26525c, Func Offset: 0x40c
	// Line 3152, Address: 0x265264, Func Offset: 0x414
	// Line 3155, Address: 0x26527c, Func Offset: 0x42c
	// Line 3153, Address: 0x265280, Func Offset: 0x430
	// Line 3155, Address: 0x265284, Func Offset: 0x434
	// Line 3158, Address: 0x2652b0, Func Offset: 0x460
	// Line 3159, Address: 0x2652b4, Func Offset: 0x464
	// Line 3163, Address: 0x2652b8, Func Offset: 0x468
	// Line 3158, Address: 0x2652bc, Func Offset: 0x46c
	// Line 3159, Address: 0x2652c0, Func Offset: 0x470
	// Line 3163, Address: 0x2652c4, Func Offset: 0x474
	// Line 3166, Address: 0x2652c8, Func Offset: 0x478
	// Line 3159, Address: 0x2652d0, Func Offset: 0x480
	// Line 3166, Address: 0x2652d4, Func Offset: 0x484
	// Line 3159, Address: 0x2652dc, Func Offset: 0x48c
	// Line 3166, Address: 0x2652e0, Func Offset: 0x490
	// Line 3159, Address: 0x2652e4, Func Offset: 0x494
	// Line 3160, Address: 0x2652e8, Func Offset: 0x498
	// Line 3161, Address: 0x2652f4, Func Offset: 0x4a4
	// Line 3162, Address: 0x265300, Func Offset: 0x4b0
	// Line 3163, Address: 0x265310, Func Offset: 0x4c0
	// Line 3164, Address: 0x265314, Func Offset: 0x4c4
	// Line 3165, Address: 0x265320, Func Offset: 0x4d0
	// Line 3166, Address: 0x265328, Func Offset: 0x4d8
	// Line 3169, Address: 0x265340, Func Offset: 0x4f0
	// Line 3167, Address: 0x265344, Func Offset: 0x4f4
	// Line 3169, Address: 0x265348, Func Offset: 0x4f8
	// Line 3173, Address: 0x265374, Func Offset: 0x524
	// Line 3174, Address: 0x26539c, Func Offset: 0x54c
	// Line 3173, Address: 0x2653a4, Func Offset: 0x554
	// Line 3174, Address: 0x2653a8, Func Offset: 0x558
	// Line 3176, Address: 0x2653c8, Func Offset: 0x578
	// Line 3177, Address: 0x2653cc, Func Offset: 0x57c
	// Func End, Address: 0x2653f8, Func Offset: 0x5a8
}

// 
// Start address: 0x265400
int bhCheckInnerTriangle3(_anon0* hp, _anon20* pos)
{
	float h;
	// Line 3190, Address: 0x265400, Func Offset: 0
	// Line 3194, Address: 0x265404, Func Offset: 0x4
	// Line 3190, Address: 0x265408, Func Offset: 0x8
	// Line 3194, Address: 0x265418, Func Offset: 0x18
	// Line 3196, Address: 0x265448, Func Offset: 0x48
	// Line 3198, Address: 0x265480, Func Offset: 0x80
	// Line 3199, Address: 0x26549c, Func Offset: 0x9c
	// Line 3201, Address: 0x2654a0, Func Offset: 0xa0
	// Line 3202, Address: 0x2654a8, Func Offset: 0xa8
	// Line 3205, Address: 0x2654b0, Func Offset: 0xb0
	// Line 3206, Address: 0x2654cc, Func Offset: 0xcc
	// Line 3208, Address: 0x2654d0, Func Offset: 0xd0
	// Line 3209, Address: 0x2654d8, Func Offset: 0xd8
	// Line 3212, Address: 0x2654e0, Func Offset: 0xe0
	// Line 3213, Address: 0x265528, Func Offset: 0x128
	// Line 3216, Address: 0x265534, Func Offset: 0x134
	// Line 3217, Address: 0x265560, Func Offset: 0x160
	// Line 3219, Address: 0x265594, Func Offset: 0x194
	// Func End, Address: 0x2655ac, Func Offset: 0x1ac
}

// 
// Start address: 0x2655b0
int bhCheckBox(_anon0* hp, _anon20* pos, float ar, float ah, unsigned int aflg)
{
	int r;
	float abz;
	float abx;
	float h;
	float wpz;
	float wpx;
	float ln;
	float zn;
	float xn;
	float pz;
	float px;
	// Line 3260, Address: 0x2655b0, Func Offset: 0
	// Line 3266, Address: 0x2655b4, Func Offset: 0x4
	// Line 3260, Address: 0x2655b8, Func Offset: 0x8
	// Line 3266, Address: 0x2655dc, Func Offset: 0x2c
	// Line 3267, Address: 0x265614, Func Offset: 0x64
	// Line 3268, Address: 0x265624, Func Offset: 0x74
	// Line 3271, Address: 0x265628, Func Offset: 0x78
	// Line 3267, Address: 0x26562c, Func Offset: 0x7c
	// Line 3268, Address: 0x265630, Func Offset: 0x80
	// Line 3273, Address: 0x265634, Func Offset: 0x84
	// Line 3269, Address: 0x265638, Func Offset: 0x88
	// Line 3267, Address: 0x26563c, Func Offset: 0x8c
	// Line 3268, Address: 0x265640, Func Offset: 0x90
	// Line 3271, Address: 0x265644, Func Offset: 0x94
	// Line 3268, Address: 0x26564c, Func Offset: 0x9c
	// Line 3271, Address: 0x265650, Func Offset: 0xa0
	// Line 3272, Address: 0x265658, Func Offset: 0xa8
	// Line 3273, Address: 0x26565c, Func Offset: 0xac
	// Line 3276, Address: 0x2656e0, Func Offset: 0x130
	// Line 3277, Address: 0x2656f0, Func Offset: 0x140
	// Line 3280, Address: 0x265700, Func Offset: 0x150
	// Line 3281, Address: 0x26570c, Func Offset: 0x15c
	// Line 3282, Address: 0x265718, Func Offset: 0x168
	// Line 3284, Address: 0x265744, Func Offset: 0x194
	// Line 3285, Address: 0x26574c, Func Offset: 0x19c
	// Line 3284, Address: 0x265754, Func Offset: 0x1a4
	// Line 3285, Address: 0x265758, Func Offset: 0x1a8
	// Line 3286, Address: 0x26575c, Func Offset: 0x1ac
	// Line 3287, Address: 0x265768, Func Offset: 0x1b8
	// Line 3288, Address: 0x265778, Func Offset: 0x1c8
	// Line 3290, Address: 0x265798, Func Offset: 0x1e8
	// Line 3291, Address: 0x2657a8, Func Offset: 0x1f8
	// Line 3297, Address: 0x2657b0, Func Offset: 0x200
	// Line 3291, Address: 0x2657b4, Func Offset: 0x204
	// Line 3292, Address: 0x2657c0, Func Offset: 0x210
	// Line 3297, Address: 0x2657d0, Func Offset: 0x220
	// Line 3299, Address: 0x2657d8, Func Offset: 0x228
	// Line 3309, Address: 0x2657e4, Func Offset: 0x234
	// Line 3310, Address: 0x2657fc, Func Offset: 0x24c
	// Line 3311, Address: 0x265800, Func Offset: 0x250
	// Line 3315, Address: 0x265808, Func Offset: 0x258
	// Line 3316, Address: 0x265810, Func Offset: 0x260
	// Line 3315, Address: 0x265814, Func Offset: 0x264
	// Line 3316, Address: 0x265818, Func Offset: 0x268
	// Line 3317, Address: 0x265824, Func Offset: 0x274
	// Line 3320, Address: 0x265850, Func Offset: 0x2a0
	// Line 3319, Address: 0x265858, Func Offset: 0x2a8
	// Line 3320, Address: 0x265860, Func Offset: 0x2b0
	// Line 3319, Address: 0x265868, Func Offset: 0x2b8
	// Line 3320, Address: 0x26586c, Func Offset: 0x2bc
	// Line 3321, Address: 0x265870, Func Offset: 0x2c0
	// Line 3322, Address: 0x26587c, Func Offset: 0x2cc
	// Line 3323, Address: 0x26588c, Func Offset: 0x2dc
	// Line 3325, Address: 0x2658ac, Func Offset: 0x2fc
	// Line 3326, Address: 0x2658bc, Func Offset: 0x30c
	// Line 3332, Address: 0x2658c4, Func Offset: 0x314
	// Line 3326, Address: 0x2658c8, Func Offset: 0x318
	// Line 3327, Address: 0x2658d4, Func Offset: 0x324
	// Line 3332, Address: 0x2658e8, Func Offset: 0x338
	// Line 3334, Address: 0x2658f0, Func Offset: 0x340
	// Line 3344, Address: 0x2658fc, Func Offset: 0x34c
	// Line 3345, Address: 0x265914, Func Offset: 0x364
	// Line 3346, Address: 0x265918, Func Offset: 0x368
	// Line 3349, Address: 0x265920, Func Offset: 0x370
	// Line 3352, Address: 0x265930, Func Offset: 0x380
	// Line 3353, Address: 0x265940, Func Offset: 0x390
	// Line 3354, Address: 0x26594c, Func Offset: 0x39c
	// Line 3356, Address: 0x265978, Func Offset: 0x3c8
	// Line 3357, Address: 0x265984, Func Offset: 0x3d4
	// Line 3356, Address: 0x26598c, Func Offset: 0x3dc
	// Line 3357, Address: 0x265994, Func Offset: 0x3e4
	// Line 3358, Address: 0x265998, Func Offset: 0x3e8
	// Line 3359, Address: 0x2659a4, Func Offset: 0x3f4
	// Line 3360, Address: 0x2659b4, Func Offset: 0x404
	// Line 3362, Address: 0x2659d4, Func Offset: 0x424
	// Line 3363, Address: 0x2659e4, Func Offset: 0x434
	// Line 3369, Address: 0x2659f0, Func Offset: 0x440
	// Line 3363, Address: 0x2659f4, Func Offset: 0x444
	// Line 3364, Address: 0x265a00, Func Offset: 0x450
	// Line 3369, Address: 0x265a10, Func Offset: 0x460
	// Line 3371, Address: 0x265a18, Func Offset: 0x468
	// Line 3381, Address: 0x265a24, Func Offset: 0x474
	// Line 3382, Address: 0x265a3c, Func Offset: 0x48c
	// Line 3383, Address: 0x265a40, Func Offset: 0x490
	// Line 3387, Address: 0x265a48, Func Offset: 0x498
	// Line 3388, Address: 0x265a54, Func Offset: 0x4a4
	// Line 3387, Address: 0x265a58, Func Offset: 0x4a8
	// Line 3388, Address: 0x265a5c, Func Offset: 0x4ac
	// Line 3389, Address: 0x265a68, Func Offset: 0x4b8
	// Line 3391, Address: 0x265a94, Func Offset: 0x4e4
	// Line 3392, Address: 0x265a9c, Func Offset: 0x4ec
	// Line 3391, Address: 0x265aa4, Func Offset: 0x4f4
	// Line 3392, Address: 0x265aa8, Func Offset: 0x4f8
	// Line 3391, Address: 0x265aac, Func Offset: 0x4fc
	// Line 3392, Address: 0x265ab0, Func Offset: 0x500
	// Line 3391, Address: 0x265ab4, Func Offset: 0x504
	// Line 3392, Address: 0x265ab8, Func Offset: 0x508
	// Line 3393, Address: 0x265abc, Func Offset: 0x50c
	// Line 3394, Address: 0x265ac8, Func Offset: 0x518
	// Line 3395, Address: 0x265ad8, Func Offset: 0x528
	// Line 3397, Address: 0x265af8, Func Offset: 0x548
	// Line 3398, Address: 0x265b08, Func Offset: 0x558
	// Line 3404, Address: 0x265b14, Func Offset: 0x564
	// Line 3398, Address: 0x265b18, Func Offset: 0x568
	// Line 3399, Address: 0x265b24, Func Offset: 0x574
	// Line 3404, Address: 0x265b38, Func Offset: 0x588
	// Line 3406, Address: 0x265b40, Func Offset: 0x590
	// Line 3416, Address: 0x265b4c, Func Offset: 0x59c
	// Line 3417, Address: 0x265b64, Func Offset: 0x5b4
	// Line 3418, Address: 0x265b68, Func Offset: 0x5b8
	// Line 3422, Address: 0x265b70, Func Offset: 0x5c0
	// Line 3423, Address: 0x265b74, Func Offset: 0x5c4
	// Func End, Address: 0x265ba0, Func Offset: 0x5f0
}

// 
// Start address: 0x265ba0
int bhCheckBox2Box(_anon0* hp, _anon20* pos, float aw, float ad, float ah)
{
	float abz;
	float abx;
	float h;
	float wpz;
	float wpx;
	float zn;
	float xn;
	float pz;
	float px;
	// Line 3438, Address: 0x265ba0, Func Offset: 0
	// Line 3443, Address: 0x265ba4, Func Offset: 0x4
	// Line 3438, Address: 0x265ba8, Func Offset: 0x8
	// Line 3443, Address: 0x265bc0, Func Offset: 0x20
	// Line 3444, Address: 0x265bec, Func Offset: 0x4c
	// Line 3445, Address: 0x265bfc, Func Offset: 0x5c
	// Line 3448, Address: 0x265c00, Func Offset: 0x60
	// Line 3444, Address: 0x265c04, Func Offset: 0x64
	// Line 3445, Address: 0x265c08, Func Offset: 0x68
	// Line 3450, Address: 0x265c0c, Func Offset: 0x6c
	// Line 3446, Address: 0x265c10, Func Offset: 0x70
	// Line 3444, Address: 0x265c14, Func Offset: 0x74
	// Line 3445, Address: 0x265c18, Func Offset: 0x78
	// Line 3448, Address: 0x265c20, Func Offset: 0x80
	// Line 3449, Address: 0x265c28, Func Offset: 0x88
	// Line 3448, Address: 0x265c30, Func Offset: 0x90
	// Line 3450, Address: 0x265c38, Func Offset: 0x98
	// Line 3453, Address: 0x265cbc, Func Offset: 0x11c
	// Line 3454, Address: 0x265ccc, Func Offset: 0x12c
	// Line 3456, Address: 0x265cdc, Func Offset: 0x13c
	// Line 3457, Address: 0x265ce8, Func Offset: 0x148
	// Line 3458, Address: 0x265cf4, Func Offset: 0x154
	// Line 3459, Address: 0x265d0c, Func Offset: 0x16c
	// Line 3460, Address: 0x265d10, Func Offset: 0x170
	// Line 3463, Address: 0x265d18, Func Offset: 0x178
	// Line 3464, Address: 0x265d20, Func Offset: 0x180
	// Line 3463, Address: 0x265d24, Func Offset: 0x184
	// Line 3464, Address: 0x265d28, Func Offset: 0x188
	// Line 3465, Address: 0x265d34, Func Offset: 0x194
	// Line 3466, Address: 0x265d4c, Func Offset: 0x1ac
	// Line 3467, Address: 0x265d50, Func Offset: 0x1b0
	// Line 3470, Address: 0x265d58, Func Offset: 0x1b8
	// Line 3472, Address: 0x265d68, Func Offset: 0x1c8
	// Line 3473, Address: 0x265d78, Func Offset: 0x1d8
	// Line 3474, Address: 0x265d84, Func Offset: 0x1e4
	// Line 3475, Address: 0x265d9c, Func Offset: 0x1fc
	// Line 3476, Address: 0x265da0, Func Offset: 0x200
	// Line 3479, Address: 0x265da8, Func Offset: 0x208
	// Line 3480, Address: 0x265db4, Func Offset: 0x214
	// Line 3479, Address: 0x265db8, Func Offset: 0x218
	// Line 3480, Address: 0x265dbc, Func Offset: 0x21c
	// Line 3481, Address: 0x265dc8, Func Offset: 0x228
	// Line 3482, Address: 0x265de0, Func Offset: 0x240
	// Line 3483, Address: 0x265de4, Func Offset: 0x244
	// Line 3487, Address: 0x265dec, Func Offset: 0x24c
	// Line 3488, Address: 0x265df0, Func Offset: 0x250
	// Func End, Address: 0x265e10, Func Offset: 0x270
}

// 
// Start address: 0x265e10
int bhCheckInnerP4(_anon33* pos, _anon33* p0, _anon33* p1, _anon33* p2, _anon33* p3)
{
	float y3;
	float y2;
	float y1;
	float y0;
	float x1;
	float x0;
	float nn;
	float swp;
	float max;
	float min;
	// Line 3509, Address: 0x265e10, Func Offset: 0
	// Line 3510, Address: 0x265e48, Func Offset: 0x38
	// Line 3512, Address: 0x265e50, Func Offset: 0x40
	// Line 3513, Address: 0x265e54, Func Offset: 0x44
	// Line 3511, Address: 0x265e58, Func Offset: 0x48
	// Line 3510, Address: 0x265e64, Func Offset: 0x54
	// Line 3512, Address: 0x265e68, Func Offset: 0x58
	// Line 3513, Address: 0x265e6c, Func Offset: 0x5c
	// Line 3514, Address: 0x265e70, Func Offset: 0x60
	// Line 3516, Address: 0x265e74, Func Offset: 0x64
	// Line 3517, Address: 0x265e84, Func Offset: 0x74
	// Line 3518, Address: 0x265ea0, Func Offset: 0x90
	// Line 3519, Address: 0x265ecc, Func Offset: 0xbc
	// Line 3520, Address: 0x265ed4, Func Offset: 0xc4
	// Line 3521, Address: 0x265ef0, Func Offset: 0xe0
	// Line 3523, Address: 0x265f14, Func Offset: 0x104
	// Line 3524, Address: 0x265f24, Func Offset: 0x114
	// Line 3525, Address: 0x265f2c, Func Offset: 0x11c
	// Line 3524, Address: 0x265f30, Func Offset: 0x120
	// Line 3525, Address: 0x265f34, Func Offset: 0x124
	// Line 3526, Address: 0x265f38, Func Offset: 0x128
	// Line 3527, Address: 0x265f48, Func Offset: 0x138
	// Line 3528, Address: 0x265f4c, Func Offset: 0x13c
	// Line 3529, Address: 0x265f50, Func Offset: 0x140
	// Line 3531, Address: 0x265f54, Func Offset: 0x144
	// Line 3533, Address: 0x265f84, Func Offset: 0x174
	// Line 3534, Address: 0x265f94, Func Offset: 0x184
	// Line 3535, Address: 0x265fac, Func Offset: 0x19c
	// Line 3537, Address: 0x265fd4, Func Offset: 0x1c4
	// Line 3538, Address: 0x265fd8, Func Offset: 0x1c8
	// Line 3537, Address: 0x265fdc, Func Offset: 0x1cc
	// Line 3538, Address: 0x265fe0, Func Offset: 0x1d0
	// Line 3537, Address: 0x265fe4, Func Offset: 0x1d4
	// Line 3538, Address: 0x265fe8, Func Offset: 0x1d8
	// Line 3539, Address: 0x265fec, Func Offset: 0x1dc
	// Line 3540, Address: 0x265ffc, Func Offset: 0x1ec
	// Line 3541, Address: 0x266000, Func Offset: 0x1f0
	// Line 3542, Address: 0x266004, Func Offset: 0x1f4
	// Line 3544, Address: 0x266008, Func Offset: 0x1f8
	// Line 3546, Address: 0x266038, Func Offset: 0x228
	// Line 3548, Address: 0x266060, Func Offset: 0x250
	// Line 3549, Address: 0x266064, Func Offset: 0x254
	// Line 3548, Address: 0x266068, Func Offset: 0x258
	// Line 3549, Address: 0x26606c, Func Offset: 0x25c
	// Line 3548, Address: 0x266070, Func Offset: 0x260
	// Line 3549, Address: 0x266074, Func Offset: 0x264
	// Line 3550, Address: 0x266078, Func Offset: 0x268
	// Line 3551, Address: 0x266088, Func Offset: 0x278
	// Line 3552, Address: 0x26608c, Func Offset: 0x27c
	// Line 3553, Address: 0x266090, Func Offset: 0x280
	// Line 3555, Address: 0x266094, Func Offset: 0x284
	// Line 3558, Address: 0x2660c4, Func Offset: 0x2b4
	// Line 3559, Address: 0x2660dc, Func Offset: 0x2cc
	// Line 3561, Address: 0x266104, Func Offset: 0x2f4
	// Line 3563, Address: 0x266138, Func Offset: 0x328
	// Line 3564, Address: 0x26613c, Func Offset: 0x32c
	// Line 3563, Address: 0x266140, Func Offset: 0x330
	// Line 3564, Address: 0x266148, Func Offset: 0x338
	// Line 3563, Address: 0x26614c, Func Offset: 0x33c
	// Line 3564, Address: 0x266150, Func Offset: 0x340
	// Line 3565, Address: 0x266154, Func Offset: 0x344
	// Line 3566, Address: 0x266164, Func Offset: 0x354
	// Line 3567, Address: 0x266168, Func Offset: 0x358
	// Line 3568, Address: 0x26616c, Func Offset: 0x35c
	// Line 3570, Address: 0x266170, Func Offset: 0x360
	// Line 3572, Address: 0x2661a0, Func Offset: 0x390
	// Line 3574, Address: 0x2661c8, Func Offset: 0x3b8
	// Line 3576, Address: 0x2661fc, Func Offset: 0x3ec
	// Line 3577, Address: 0x266200, Func Offset: 0x3f0
	// Line 3576, Address: 0x266208, Func Offset: 0x3f8
	// Line 3577, Address: 0x26620c, Func Offset: 0x3fc
	// Line 3576, Address: 0x266210, Func Offset: 0x400
	// Line 3577, Address: 0x266214, Func Offset: 0x404
	// Line 3578, Address: 0x266218, Func Offset: 0x408
	// Line 3579, Address: 0x266228, Func Offset: 0x418
	// Line 3580, Address: 0x26622c, Func Offset: 0x41c
	// Line 3581, Address: 0x266230, Func Offset: 0x420
	// Line 3583, Address: 0x266234, Func Offset: 0x424
	// Line 3587, Address: 0x266264, Func Offset: 0x454
	// Line 3588, Address: 0x266268, Func Offset: 0x458
	// Func End, Address: 0x266270, Func Offset: 0x460
}

// 
// Start address: 0x266270
void bhCheckExmAtari(BH_PWORK* pp)
{
	int ang;
	int danf;
	int etc_n;
	int i;
	float pzn[5];
	float pxn[5];
	float pzz;
	float pxx;
	float pz;
	float px;
	_anon1* op;
	_anon0* ckp;
	_anon0* exp;
	_anon20 ps;
	// Line 3599, Address: 0x266270, Func Offset: 0
	// Line 3610, Address: 0x266288, Func Offset: 0x18
	// Line 3612, Address: 0x266298, Func Offset: 0x28
	// Line 3615, Address: 0x2662b8, Func Offset: 0x48
	// Line 3655, Address: 0x2662c0, Func Offset: 0x50
	// Line 3618, Address: 0x2662c4, Func Offset: 0x54
	// Line 3612, Address: 0x2662cc, Func Offset: 0x5c
	// Line 3655, Address: 0x2662d0, Func Offset: 0x60
	// Line 3613, Address: 0x2662d4, Func Offset: 0x64
	// Line 3615, Address: 0x2662d8, Func Offset: 0x68
	// Line 3612, Address: 0x2662dc, Func Offset: 0x6c
	// Line 3624, Address: 0x2662e0, Func Offset: 0x70
	// Line 3655, Address: 0x2662e4, Func Offset: 0x74
	// Line 3612, Address: 0x2662e8, Func Offset: 0x78
	// Line 3656, Address: 0x2662ec, Func Offset: 0x7c
	// Line 3654, Address: 0x2662f0, Func Offset: 0x80
	// Line 3621, Address: 0x2662f4, Func Offset: 0x84
	// Line 3612, Address: 0x2662f8, Func Offset: 0x88
	// Line 3616, Address: 0x2662fc, Func Offset: 0x8c
	// Line 3612, Address: 0x266300, Func Offset: 0x90
	// Line 3613, Address: 0x26630c, Func Offset: 0x9c
	// Line 3615, Address: 0x26631c, Func Offset: 0xac
	// Line 3618, Address: 0x266320, Func Offset: 0xb0
	// Line 3615, Address: 0x266324, Func Offset: 0xb4
	// Line 3618, Address: 0x26632c, Func Offset: 0xbc
	// Line 3616, Address: 0x266330, Func Offset: 0xc0
	// Line 3619, Address: 0x266334, Func Offset: 0xc4
	// Line 3618, Address: 0x266338, Func Offset: 0xc8
	// Line 3616, Address: 0x26633c, Func Offset: 0xcc
	// Line 3619, Address: 0x266340, Func Offset: 0xd0
	// Line 3616, Address: 0x266344, Func Offset: 0xd4
	// Line 3619, Address: 0x266348, Func Offset: 0xd8
	// Line 3621, Address: 0x26634c, Func Offset: 0xdc
	// Line 3622, Address: 0x266358, Func Offset: 0xe8
	// Line 3624, Address: 0x266360, Func Offset: 0xf0
	// Line 3622, Address: 0x266368, Func Offset: 0xf8
	// Line 3624, Address: 0x26636c, Func Offset: 0xfc
	// Line 3625, Address: 0x266378, Func Offset: 0x108
	// Line 3655, Address: 0x266384, Func Offset: 0x114
	// Line 3656, Address: 0x266390, Func Offset: 0x120
	// Line 3657, Address: 0x2663b0, Func Offset: 0x140
	// Line 3659, Address: 0x2663c0, Func Offset: 0x150
	// Line 3660, Address: 0x266408, Func Offset: 0x198
	// Line 3661, Address: 0x266418, Func Offset: 0x1a8
	// Line 3662, Address: 0x26642c, Func Offset: 0x1bc
	// Line 3663, Address: 0x266430, Func Offset: 0x1c0
	// Line 3662, Address: 0x266434, Func Offset: 0x1c4
	// Line 3663, Address: 0x266444, Func Offset: 0x1d4
	// Line 3666, Address: 0x2664b0, Func Offset: 0x240
	// Line 3668, Address: 0x2664b4, Func Offset: 0x244
	// Line 3666, Address: 0x2664b8, Func Offset: 0x248
	// Line 3667, Address: 0x2664bc, Func Offset: 0x24c
	// Line 3666, Address: 0x2664c0, Func Offset: 0x250
	// Line 3667, Address: 0x2664c8, Func Offset: 0x258
	// Line 3668, Address: 0x2664d8, Func Offset: 0x268
	// Line 3671, Address: 0x26650c, Func Offset: 0x29c
	// Line 3672, Address: 0x266510, Func Offset: 0x2a0
	// Line 3671, Address: 0x266514, Func Offset: 0x2a4
	// Line 3672, Address: 0x26651c, Func Offset: 0x2ac
	// Line 3676, Address: 0x266590, Func Offset: 0x320
	// Line 3677, Address: 0x2665a4, Func Offset: 0x334
	// Line 3684, Address: 0x2665ac, Func Offset: 0x33c
	// Line 3685, Address: 0x2665c8, Func Offset: 0x358
	// Line 3686, Address: 0x2665d0, Func Offset: 0x360
	// Line 3685, Address: 0x2665d4, Func Offset: 0x364
	// Line 3686, Address: 0x2665dc, Func Offset: 0x36c
	// Line 3687, Address: 0x2665e4, Func Offset: 0x374
	// Line 3686, Address: 0x2665e8, Func Offset: 0x378
	// Line 3687, Address: 0x2665f0, Func Offset: 0x380
	// Line 3688, Address: 0x2665f8, Func Offset: 0x388
	// Line 3687, Address: 0x2665fc, Func Offset: 0x38c
	// Line 3688, Address: 0x266604, Func Offset: 0x394
	// Line 3689, Address: 0x266614, Func Offset: 0x3a4
	// Line 3690, Address: 0x26662c, Func Offset: 0x3bc
	// Line 3691, Address: 0x266644, Func Offset: 0x3d4
	// Line 3692, Address: 0x26665c, Func Offset: 0x3ec
	// Line 3693, Address: 0x266674, Func Offset: 0x404
	// Line 3695, Address: 0x266688, Func Offset: 0x418
	// Line 3702, Address: 0x266690, Func Offset: 0x420
	// Line 3704, Address: 0x2666b4, Func Offset: 0x444
	// Line 3706, Address: 0x2666bc, Func Offset: 0x44c
	// Line 3707, Address: 0x2666c8, Func Offset: 0x458
	// Line 3708, Address: 0x2666d0, Func Offset: 0x460
	// Line 3706, Address: 0x2666d4, Func Offset: 0x464
	// Line 3707, Address: 0x2666dc, Func Offset: 0x46c
	// Line 3709, Address: 0x2666e0, Func Offset: 0x470
	// Line 3707, Address: 0x2666e4, Func Offset: 0x474
	// Line 3708, Address: 0x2666ec, Func Offset: 0x47c
	// Line 3709, Address: 0x2666f8, Func Offset: 0x488
	// Line 3710, Address: 0x266700, Func Offset: 0x490
	// Line 3709, Address: 0x266704, Func Offset: 0x494
	// Line 3710, Address: 0x26670c, Func Offset: 0x49c
	// Line 3711, Address: 0x26671c, Func Offset: 0x4ac
	// Line 3713, Address: 0x266728, Func Offset: 0x4b8
	// Line 3714, Address: 0x266730, Func Offset: 0x4c0
	// Line 3715, Address: 0x266734, Func Offset: 0x4c4
	// Line 3716, Address: 0x266744, Func Offset: 0x4d4
	// Line 3718, Address: 0x266750, Func Offset: 0x4e0
	// Line 3720, Address: 0x266754, Func Offset: 0x4e4
	// Line 3722, Address: 0x26675c, Func Offset: 0x4ec
	// Line 3723, Address: 0x266760, Func Offset: 0x4f0
	// Line 3724, Address: 0x266764, Func Offset: 0x4f4
	// Line 3725, Address: 0x266774, Func Offset: 0x504
	// Line 3727, Address: 0x266780, Func Offset: 0x510
	// Line 3728, Address: 0x266784, Func Offset: 0x514
	// Line 3729, Address: 0x266788, Func Offset: 0x518
	// Line 3732, Address: 0x2667d8, Func Offset: 0x568
	// Line 3739, Address: 0x2667e0, Func Offset: 0x570
	// Line 3741, Address: 0x2667fc, Func Offset: 0x58c
	// Line 3745, Address: 0x266804, Func Offset: 0x594
	// Line 3741, Address: 0x266808, Func Offset: 0x598
	// Line 3745, Address: 0x266814, Func Offset: 0x5a4
	// Line 3746, Address: 0x266820, Func Offset: 0x5b0
	// Line 3747, Address: 0x266834, Func Offset: 0x5c4
	// Line 3752, Address: 0x266838, Func Offset: 0x5c8
	// Line 3746, Address: 0x26683c, Func Offset: 0x5cc
	// Line 3747, Address: 0x26684c, Func Offset: 0x5dc
	// Line 3752, Address: 0x266858, Func Offset: 0x5e8
	// Line 3747, Address: 0x26685c, Func Offset: 0x5ec
	// Line 3752, Address: 0x266860, Func Offset: 0x5f0
	// Line 3756, Address: 0x2668d4, Func Offset: 0x664
	// Line 3757, Address: 0x2668e8, Func Offset: 0x678
	// Line 3758, Address: 0x266904, Func Offset: 0x694
	// Line 3757, Address: 0x266908, Func Offset: 0x698
	// Line 3758, Address: 0x26690c, Func Offset: 0x69c
	// Line 3757, Address: 0x266910, Func Offset: 0x6a0
	// Line 3758, Address: 0x26691c, Func Offset: 0x6ac
	// Line 3759, Address: 0x266930, Func Offset: 0x6c0
	// Line 3767, Address: 0x26694c, Func Offset: 0x6dc
	// Line 3768, Address: 0x266960, Func Offset: 0x6f0
	// Line 3770, Address: 0x266978, Func Offset: 0x708
	// Line 3773, Address: 0x266984, Func Offset: 0x714
	// Line 3774, Address: 0x26698c, Func Offset: 0x71c
	// Line 3770, Address: 0x266990, Func Offset: 0x720
	// Line 3773, Address: 0x266998, Func Offset: 0x728
	// Line 3775, Address: 0x26699c, Func Offset: 0x72c
	// Line 3778, Address: 0x2669a0, Func Offset: 0x730
	// Line 3780, Address: 0x2669a4, Func Offset: 0x734
	// Line 3773, Address: 0x2669a8, Func Offset: 0x738
	// Line 3774, Address: 0x2669b0, Func Offset: 0x740
	// Line 3775, Address: 0x2669bc, Func Offset: 0x74c
	// Line 3776, Address: 0x2669c4, Func Offset: 0x754
	// Line 3775, Address: 0x2669c8, Func Offset: 0x758
	// Line 3776, Address: 0x2669d0, Func Offset: 0x760
	// Line 3778, Address: 0x2669e0, Func Offset: 0x770
	// Line 3779, Address: 0x2669e4, Func Offset: 0x774
	// Line 3780, Address: 0x2669e8, Func Offset: 0x778
	// Line 3784, Address: 0x2669ec, Func Offset: 0x77c
	// Line 3786, Address: 0x2669f4, Func Offset: 0x784
	// Line 3787, Address: 0x266a08, Func Offset: 0x798
	// Line 3790, Address: 0x266a10, Func Offset: 0x7a0
	// Line 3791, Address: 0x266a14, Func Offset: 0x7a4
	// Line 3790, Address: 0x266a18, Func Offset: 0x7a8
	// Line 3791, Address: 0x266a20, Func Offset: 0x7b0
	// Line 3795, Address: 0x266a90, Func Offset: 0x820
	// Line 3796, Address: 0x266aa4, Func Offset: 0x834
	// Line 3802, Address: 0x266aac, Func Offset: 0x83c
	// Line 3806, Address: 0x266ac0, Func Offset: 0x850
	// Line 3807, Address: 0x266ad0, Func Offset: 0x860
	// Line 3808, Address: 0x266ae0, Func Offset: 0x870
	// Line 3809, Address: 0x266af8, Func Offset: 0x888
	// Line 3810, Address: 0x266b10, Func Offset: 0x8a0
	// Line 3811, Address: 0x266b30, Func Offset: 0x8c0
	// Line 3812, Address: 0x266b50, Func Offset: 0x8e0
	// Line 3813, Address: 0x266b70, Func Offset: 0x900
	// Line 3814, Address: 0x266b84, Func Offset: 0x914
	// Line 3815, Address: 0x266b98, Func Offset: 0x928
	// Line 3816, Address: 0x266bc4, Func Offset: 0x954
	// Line 3817, Address: 0x266bdc, Func Offset: 0x96c
	// Line 3818, Address: 0x266be8, Func Offset: 0x978
	// Line 3817, Address: 0x266bec, Func Offset: 0x97c
	// Line 3818, Address: 0x266bf4, Func Offset: 0x984
	// Line 3819, Address: 0x266bfc, Func Offset: 0x98c
	// Line 3818, Address: 0x266c00, Func Offset: 0x990
	// Line 3819, Address: 0x266c08, Func Offset: 0x998
	// Line 3820, Address: 0x266c10, Func Offset: 0x9a0
	// Line 3819, Address: 0x266c14, Func Offset: 0x9a4
	// Line 3820, Address: 0x266c1c, Func Offset: 0x9ac
	// Line 3822, Address: 0x266c3c, Func Offset: 0x9cc
	// Line 3823, Address: 0x266c4c, Func Offset: 0x9dc
	// Line 3824, Address: 0x266c58, Func Offset: 0x9e8
	// Line 3825, Address: 0x266c68, Func Offset: 0x9f8
	// Line 3826, Address: 0x266c88, Func Offset: 0xa18
	// Line 3827, Address: 0x266ca8, Func Offset: 0xa38
	// Line 3828, Address: 0x266cc8, Func Offset: 0xa58
	// Line 3830, Address: 0x266cdc, Func Offset: 0xa6c
	// Line 3831, Address: 0x266ce8, Func Offset: 0xa78
	// Line 3830, Address: 0x266cec, Func Offset: 0xa7c
	// Line 3831, Address: 0x266cf4, Func Offset: 0xa84
	// Line 3832, Address: 0x266cfc, Func Offset: 0xa8c
	// Line 3831, Address: 0x266d00, Func Offset: 0xa90
	// Line 3832, Address: 0x266d08, Func Offset: 0xa98
	// Line 3846, Address: 0x266d14, Func Offset: 0xaa4
	// Line 3850, Address: 0x266d1c, Func Offset: 0xaac
	// Line 3851, Address: 0x266d20, Func Offset: 0xab0
	// Line 3850, Address: 0x266d24, Func Offset: 0xab4
	// Line 3851, Address: 0x266d2c, Func Offset: 0xabc
	// Line 3855, Address: 0x266da0, Func Offset: 0xb30
	// Line 3856, Address: 0x266db4, Func Offset: 0xb44
	// Line 3864, Address: 0x266dbc, Func Offset: 0xb4c
	// Line 3866, Address: 0x266dcc, Func Offset: 0xb5c
	// Line 3867, Address: 0x266dd8, Func Offset: 0xb68
	// Line 3869, Address: 0x266df0, Func Offset: 0xb80
	// Line 3870, Address: 0x266e20, Func Offset: 0xbb0
	// Line 3871, Address: 0x266e30, Func Offset: 0xbc0
	// Line 3872, Address: 0x266e40, Func Offset: 0xbd0
	// Line 3873, Address: 0x266e50, Func Offset: 0xbe0
	// Line 3875, Address: 0x266e58, Func Offset: 0xbe8
	// Line 3877, Address: 0x266e5c, Func Offset: 0xbec
	// Line 3879, Address: 0x266e60, Func Offset: 0xbf0
	// Line 3873, Address: 0x266e64, Func Offset: 0xbf4
	// Line 3874, Address: 0x266e6c, Func Offset: 0xbfc
	// Line 3875, Address: 0x266e78, Func Offset: 0xc08
	// Line 3877, Address: 0x266e88, Func Offset: 0xc18
	// Line 3878, Address: 0x266e8c, Func Offset: 0xc1c
	// Line 3879, Address: 0x266e90, Func Offset: 0xc20
	// Line 3881, Address: 0x266e94, Func Offset: 0xc24
	// Line 3882, Address: 0x266e9c, Func Offset: 0xc2c
	// Line 3883, Address: 0x266ea8, Func Offset: 0xc38
	// Line 3882, Address: 0x266eac, Func Offset: 0xc3c
	// Line 3883, Address: 0x266eb4, Func Offset: 0xc44
	// Line 3885, Address: 0x266ec4, Func Offset: 0xc54
	// Line 3889, Address: 0x266ecc, Func Offset: 0xc5c
	// Line 3890, Address: 0x266ed4, Func Offset: 0xc64
	// Line 3891, Address: 0x266ef8, Func Offset: 0xc88
	// Line 3894, Address: 0x266f0c, Func Offset: 0xc9c
	// Line 3895, Address: 0x266f1c, Func Offset: 0xcac
	// Line 3896, Address: 0x266f30, Func Offset: 0xcc0
	// Line 3897, Address: 0x266f38, Func Offset: 0xcc8
	// Line 3898, Address: 0x266f64, Func Offset: 0xcf4
	// Line 3899, Address: 0x266f74, Func Offset: 0xd04
	// Line 3900, Address: 0x266f78, Func Offset: 0xd08
	// Line 3901, Address: 0x266f7c, Func Offset: 0xd0c
	// Line 3902, Address: 0x266f84, Func Offset: 0xd14
	// Line 3903, Address: 0x266f88, Func Offset: 0xd18
	// Line 3905, Address: 0x266f8c, Func Offset: 0xd1c
	// Line 3901, Address: 0x266f90, Func Offset: 0xd20
	// Line 3902, Address: 0x266f98, Func Offset: 0xd28
	// Line 3903, Address: 0x266fa4, Func Offset: 0xd34
	// Line 3905, Address: 0x266fb4, Func Offset: 0xd44
	// Line 3906, Address: 0x266fb8, Func Offset: 0xd48
	// Line 3907, Address: 0x266fbc, Func Offset: 0xd4c
	// Line 3908, Address: 0x266fc0, Func Offset: 0xd50
	// Line 3911, Address: 0x266fc4, Func Offset: 0xd54
	// Line 3916, Address: 0x266fcc, Func Offset: 0xd5c
	// Line 3938, Address: 0x266fe0, Func Offset: 0xd70
	// Line 3940, Address: 0x267004, Func Offset: 0xd94
	// Line 3942, Address: 0x267008, Func Offset: 0xd98
	// Line 3940, Address: 0x26700c, Func Offset: 0xd9c
	// Line 3942, Address: 0x267010, Func Offset: 0xda0
	// Line 3940, Address: 0x267014, Func Offset: 0xda4
	// Line 3942, Address: 0x267020, Func Offset: 0xdb0
	// Line 3943, Address: 0x26702c, Func Offset: 0xdbc
	// Line 3944, Address: 0x267048, Func Offset: 0xdd8
	// Line 3943, Address: 0x26704c, Func Offset: 0xddc
	// Line 3944, Address: 0x267050, Func Offset: 0xde0
	// Line 3943, Address: 0x267054, Func Offset: 0xde4
	// Line 3944, Address: 0x267060, Func Offset: 0xdf0
	// Line 3945, Address: 0x267074, Func Offset: 0xe04
	// Line 3951, Address: 0x267090, Func Offset: 0xe20
	// Line 3952, Address: 0x2670a4, Func Offset: 0xe34
	// Line 3954, Address: 0x2670bc, Func Offset: 0xe4c
	// Line 3955, Address: 0x2670c8, Func Offset: 0xe58
	// Line 3956, Address: 0x2670d0, Func Offset: 0xe60
	// Line 3954, Address: 0x2670d4, Func Offset: 0xe64
	// Line 3955, Address: 0x2670dc, Func Offset: 0xe6c
	// Line 3957, Address: 0x2670e0, Func Offset: 0xe70
	// Line 3959, Address: 0x2670e4, Func Offset: 0xe74
	// Line 3961, Address: 0x2670e8, Func Offset: 0xe78
	// Line 3955, Address: 0x2670ec, Func Offset: 0xe7c
	// Line 3956, Address: 0x2670f4, Func Offset: 0xe84
	// Line 3957, Address: 0x267100, Func Offset: 0xe90
	// Line 3959, Address: 0x267110, Func Offset: 0xea0
	// Line 3960, Address: 0x267114, Func Offset: 0xea4
	// Line 3961, Address: 0x267118, Func Offset: 0xea8
	// Line 3962, Address: 0x26711c, Func Offset: 0xeac
	// Line 3965, Address: 0x267120, Func Offset: 0xeb0
	// Func End, Address: 0x267138, Func Offset: 0xec8
}

// 
// Start address: 0x267140
void bhSetUseKaidanFlag(BH_PWORK* pp, _anon0* exp, int idx)
{
	_anon0* exp2;
	// Line 3978, Address: 0x267140, Func Offset: 0
	// Line 3979, Address: 0x267144, Func Offset: 0x4
	// Line 3980, Address: 0x267148, Func Offset: 0x8
	// Line 3982, Address: 0x267150, Func Offset: 0x10
	// Line 3980, Address: 0x267154, Func Offset: 0x14
	// Line 3982, Address: 0x26715c, Func Offset: 0x1c
	// Line 3984, Address: 0x267168, Func Offset: 0x28
	// Line 3985, Address: 0x267198, Func Offset: 0x58
	// Line 3986, Address: 0x2671c0, Func Offset: 0x80
	// Line 3987, Address: 0x2671d4, Func Offset: 0x94
	// Line 3988, Address: 0x2671d8, Func Offset: 0x98
	// Line 3989, Address: 0x2671e4, Func Offset: 0xa4
	// Line 3992, Address: 0x2671ec, Func Offset: 0xac
	// Line 3994, Address: 0x267218, Func Offset: 0xd8
	// Func End, Address: 0x267220, Func Offset: 0xe0
}

// 
// Start address: 0x267220
void bhClrUseKaidanFlag(BH_PWORK* pp)
{
	int idx;
	_anon0* exp2;
	_anon0* exp;
	// Line 4006, Address: 0x267220, Func Offset: 0
	// Line 4007, Address: 0x267224, Func Offset: 0x4
	// Line 4008, Address: 0x26722c, Func Offset: 0xc
	// Line 4009, Address: 0x267230, Func Offset: 0x10
	// Line 4011, Address: 0x267238, Func Offset: 0x18
	// Line 4009, Address: 0x26723c, Func Offset: 0x1c
	// Line 4011, Address: 0x267248, Func Offset: 0x28
	// Line 4013, Address: 0x267254, Func Offset: 0x34
	// Line 4014, Address: 0x267284, Func Offset: 0x64
	// Line 4015, Address: 0x2672ac, Func Offset: 0x8c
	// Line 4016, Address: 0x2672c0, Func Offset: 0xa0
	// Line 4017, Address: 0x2672c4, Func Offset: 0xa4
	// Line 4018, Address: 0x2672d4, Func Offset: 0xb4
	// Line 4021, Address: 0x2672dc, Func Offset: 0xbc
	// Line 4023, Address: 0x267308, Func Offset: 0xe8
	// Func End, Address: 0x267310, Func Offset: 0xf0
}

// 
// Start address: 0x267310
void bhSetDansaLimitAtari(BH_PWORK* pp)
{
	int etc_n;
	int i;
	float arh;
	float px3;
	float pz2;
	float px1;
	float pz0;
	float px0;
	_anon0* pop;
	_anon0* exp;
	_anon0* hp;
	// Line 4054, Address: 0x267310, Func Offset: 0
	// Line 4062, Address: 0x26733c, Func Offset: 0x2c
	// Line 4072, Address: 0x267344, Func Offset: 0x34
	// Line 4073, Address: 0x267350, Func Offset: 0x40
	// Line 4075, Address: 0x267354, Func Offset: 0x44
	// Line 4062, Address: 0x267358, Func Offset: 0x48
	// Line 4074, Address: 0x267364, Func Offset: 0x54
	// Line 4063, Address: 0x26736c, Func Offset: 0x5c
	// Line 4064, Address: 0x267370, Func Offset: 0x60
	// Line 4074, Address: 0x267378, Func Offset: 0x68
	// Line 4072, Address: 0x267380, Func Offset: 0x70
	// Line 4074, Address: 0x267384, Func Offset: 0x74
	// Line 4064, Address: 0x267390, Func Offset: 0x80
	// Line 4074, Address: 0x267394, Func Offset: 0x84
	// Line 4065, Address: 0x267398, Func Offset: 0x88
	// Line 4074, Address: 0x26739c, Func Offset: 0x8c
	// Line 4068, Address: 0x2673a0, Func Offset: 0x90
	// Line 4075, Address: 0x2673a4, Func Offset: 0x94
	// Line 4069, Address: 0x2673a8, Func Offset: 0x98
	// Line 4075, Address: 0x2673ac, Func Offset: 0x9c
	// Line 4078, Address: 0x2673b8, Func Offset: 0xa8
	// Line 4077, Address: 0x2673bc, Func Offset: 0xac
	// Line 4078, Address: 0x2673f8, Func Offset: 0xe8
	// Line 4082, Address: 0x267430, Func Offset: 0x120
	// Line 4085, Address: 0x267488, Func Offset: 0x178
	// Line 4088, Address: 0x267490, Func Offset: 0x180
	// Line 4089, Address: 0x2674a0, Func Offset: 0x190
	// Line 4090, Address: 0x2674b0, Func Offset: 0x1a0
	// Line 4092, Address: 0x2674b4, Func Offset: 0x1a4
	// Line 4093, Address: 0x2674bc, Func Offset: 0x1ac
	// Line 4094, Address: 0x2674cc, Func Offset: 0x1bc
	// Line 4098, Address: 0x2674d4, Func Offset: 0x1c4
	// Line 4099, Address: 0x2674e4, Func Offset: 0x1d4
	// Line 4105, Address: 0x2674ec, Func Offset: 0x1dc
	// Line 4108, Address: 0x2674f4, Func Offset: 0x1e4
	// Line 4105, Address: 0x2674f8, Func Offset: 0x1e8
	// Line 4101, Address: 0x2674fc, Func Offset: 0x1ec
	// Line 4099, Address: 0x267500, Func Offset: 0x1f0
	// Line 4108, Address: 0x267508, Func Offset: 0x1f8
	// Line 4099, Address: 0x26750c, Func Offset: 0x1fc
	// Line 4104, Address: 0x267510, Func Offset: 0x200
	// Line 4107, Address: 0x267514, Func Offset: 0x204
	// Line 4109, Address: 0x267518, Func Offset: 0x208
	// Line 4099, Address: 0x26751c, Func Offset: 0x20c
	// Line 4108, Address: 0x267524, Func Offset: 0x214
	// Line 4099, Address: 0x267528, Func Offset: 0x218
	// Line 4100, Address: 0x267530, Func Offset: 0x220
	// Line 4101, Address: 0x267578, Func Offset: 0x268
	// Line 4102, Address: 0x26757c, Func Offset: 0x26c
	// Line 4103, Address: 0x267580, Func Offset: 0x270
	// Line 4104, Address: 0x267588, Func Offset: 0x278
	// Line 4105, Address: 0x26758c, Func Offset: 0x27c
	// Line 4106, Address: 0x267598, Func Offset: 0x288
	// Line 4107, Address: 0x2675a0, Func Offset: 0x290
	// Line 4108, Address: 0x2675ac, Func Offset: 0x29c
	// Line 4109, Address: 0x2675b8, Func Offset: 0x2a8
	// Line 4110, Address: 0x2675bc, Func Offset: 0x2ac
	// Line 4111, Address: 0x2675c0, Func Offset: 0x2b0
	// Line 4117, Address: 0x2675d0, Func Offset: 0x2c0
	// Line 4118, Address: 0x2675e8, Func Offset: 0x2d8
	// Line 4126, Address: 0x2675f0, Func Offset: 0x2e0
	// Line 4120, Address: 0x2675f8, Func Offset: 0x2e8
	// Line 4126, Address: 0x2675fc, Func Offset: 0x2ec
	// Line 4129, Address: 0x267600, Func Offset: 0x2f0
	// Line 4118, Address: 0x267604, Func Offset: 0x2f4
	// Line 4129, Address: 0x267610, Func Offset: 0x300
	// Line 4123, Address: 0x267614, Func Offset: 0x304
	// Line 4128, Address: 0x267618, Func Offset: 0x308
	// Line 4129, Address: 0x26761c, Func Offset: 0x30c
	// Line 4118, Address: 0x267620, Func Offset: 0x310
	// Line 4119, Address: 0x267630, Func Offset: 0x320
	// Line 4120, Address: 0x267678, Func Offset: 0x368
	// Line 4121, Address: 0x26767c, Func Offset: 0x36c
	// Line 4122, Address: 0x267680, Func Offset: 0x370
	// Line 4123, Address: 0x267688, Func Offset: 0x378
	// Line 4124, Address: 0x26768c, Func Offset: 0x37c
	// Line 4125, Address: 0x2676a0, Func Offset: 0x390
	// Line 4126, Address: 0x2676a8, Func Offset: 0x398
	// Line 4127, Address: 0x2676b4, Func Offset: 0x3a4
	// Line 4128, Address: 0x2676b8, Func Offset: 0x3a8
	// Line 4129, Address: 0x2676bc, Func Offset: 0x3ac
	// Line 4130, Address: 0x2676c8, Func Offset: 0x3b8
	// Line 4136, Address: 0x2676d8, Func Offset: 0x3c8
	// Line 4137, Address: 0x2676f0, Func Offset: 0x3e0
	// Line 4143, Address: 0x2676f8, Func Offset: 0x3e8
	// Line 4146, Address: 0x267700, Func Offset: 0x3f0
	// Line 4143, Address: 0x267704, Func Offset: 0x3f4
	// Line 4139, Address: 0x267708, Func Offset: 0x3f8
	// Line 4137, Address: 0x26770c, Func Offset: 0x3fc
	// Line 4146, Address: 0x267714, Func Offset: 0x404
	// Line 4137, Address: 0x267718, Func Offset: 0x408
	// Line 4142, Address: 0x26771c, Func Offset: 0x40c
	// Line 4146, Address: 0x267720, Func Offset: 0x410
	// Line 4147, Address: 0x267724, Func Offset: 0x414
	// Line 4137, Address: 0x267728, Func Offset: 0x418
	// Line 4138, Address: 0x267738, Func Offset: 0x428
	// Line 4139, Address: 0x267780, Func Offset: 0x470
	// Line 4140, Address: 0x267784, Func Offset: 0x474
	// Line 4141, Address: 0x267788, Func Offset: 0x478
	// Line 4142, Address: 0x267790, Func Offset: 0x480
	// Line 4143, Address: 0x267794, Func Offset: 0x484
	// Line 4144, Address: 0x2677a0, Func Offset: 0x490
	// Line 4145, Address: 0x2677a8, Func Offset: 0x498
	// Line 4146, Address: 0x2677bc, Func Offset: 0x4ac
	// Line 4147, Address: 0x2677c8, Func Offset: 0x4b8
	// Line 4148, Address: 0x2677cc, Func Offset: 0x4bc
	// Line 4149, Address: 0x2677d0, Func Offset: 0x4c0
	// Line 4155, Address: 0x2677e0, Func Offset: 0x4d0
	// Line 4156, Address: 0x2677f8, Func Offset: 0x4e8
	// Line 4162, Address: 0x267800, Func Offset: 0x4f0
	// Line 4158, Address: 0x267808, Func Offset: 0x4f8
	// Line 4162, Address: 0x26780c, Func Offset: 0x4fc
	// Line 4167, Address: 0x267810, Func Offset: 0x500
	// Line 4156, Address: 0x267814, Func Offset: 0x504
	// Line 4167, Address: 0x267820, Func Offset: 0x510
	// Line 4161, Address: 0x267824, Func Offset: 0x514
	// Line 4162, Address: 0x267828, Func Offset: 0x518
	// Line 4166, Address: 0x26782c, Func Offset: 0x51c
	// Line 4156, Address: 0x267830, Func Offset: 0x520
	// Line 4167, Address: 0x267838, Func Offset: 0x528
	// Line 4156, Address: 0x26783c, Func Offset: 0x52c
	// Line 4157, Address: 0x267844, Func Offset: 0x534
	// Line 4158, Address: 0x26788c, Func Offset: 0x57c
	// Line 4159, Address: 0x267890, Func Offset: 0x580
	// Line 4160, Address: 0x267894, Func Offset: 0x584
	// Line 4161, Address: 0x26789c, Func Offset: 0x58c
	// Line 4162, Address: 0x2678a0, Func Offset: 0x590
	// Line 4163, Address: 0x2678ac, Func Offset: 0x59c
	// Line 4164, Address: 0x2678b4, Func Offset: 0x5a4
	// Line 4165, Address: 0x2678c0, Func Offset: 0x5b0
	// Line 4166, Address: 0x2678c4, Func Offset: 0x5b4
	// Line 4167, Address: 0x2678c8, Func Offset: 0x5b8
	// Line 4168, Address: 0x2678d4, Func Offset: 0x5c4
	// Line 4173, Address: 0x2678e4, Func Offset: 0x5d4
	// Func End, Address: 0x267914, Func Offset: 0x604
}

// 
// Start address: 0x267920
_anon0* bhCheckDansaAtari(int flr_no, float px, float pz)
{
	int etc_n;
	int i;
	_anon0* exp;
	// Line 4189, Address: 0x267920, Func Offset: 0
	// Line 4190, Address: 0x267944, Func Offset: 0x24
	// Line 4193, Address: 0x267954, Func Offset: 0x34
	// Line 4192, Address: 0x267958, Func Offset: 0x38
	// Line 4193, Address: 0x267994, Func Offset: 0x74
	// Line 4194, Address: 0x2679bc, Func Offset: 0x9c
	// Line 4197, Address: 0x267a20, Func Offset: 0x100
	// Line 4200, Address: 0x267a28, Func Offset: 0x108
	// Line 4201, Address: 0x267a38, Func Offset: 0x118
	// Line 4202, Address: 0x267a3c, Func Offset: 0x11c
	// Func End, Address: 0x267a44, Func Offset: 0x124
}

// 
// Start address: 0x267a50
void bhCheckFloorP(BH_PWORK* pp)
{
	int ang;
	int flr_n;
	int i;
	float* dp;
	float spz;
	float spx;
	float pz;
	float py;
	float px;
	_anon0* fp;
	// Line 4212, Address: 0x267a50, Func Offset: 0
	// Line 4219, Address: 0x267a68, Func Offset: 0x18
	// Line 4220, Address: 0x267a6c, Func Offset: 0x1c
	// Line 4221, Address: 0x267a70, Func Offset: 0x20
	// Line 4223, Address: 0x267a78, Func Offset: 0x28
	// Line 4224, Address: 0x267a88, Func Offset: 0x38
	// Line 4233, Address: 0x267a9c, Func Offset: 0x4c
	// Line 4224, Address: 0x267aa4, Func Offset: 0x54
	// Line 4235, Address: 0x267aa8, Func Offset: 0x58
	// Line 4226, Address: 0x267aac, Func Offset: 0x5c
	// Line 4234, Address: 0x267ab0, Func Offset: 0x60
	// Line 4235, Address: 0x267ab4, Func Offset: 0x64
	// Line 4224, Address: 0x267ab8, Func Offset: 0x68
	// Line 4235, Address: 0x267ac0, Func Offset: 0x70
	// Line 4224, Address: 0x267ac4, Func Offset: 0x74
	// Line 4226, Address: 0x267ad8, Func Offset: 0x88
	// Line 4233, Address: 0x267af8, Func Offset: 0xa8
	// Line 4234, Address: 0x267b04, Func Offset: 0xb4
	// Line 4235, Address: 0x267b10, Func Offset: 0xc0
	// Line 4236, Address: 0x267b18, Func Offset: 0xc8
	// Line 4235, Address: 0x267b1c, Func Offset: 0xcc
	// Line 4236, Address: 0x267b24, Func Offset: 0xd4
	// Line 4237, Address: 0x267b44, Func Offset: 0xf4
	// Line 4239, Address: 0x267b54, Func Offset: 0x104
	// Line 4240, Address: 0x267b9c, Func Offset: 0x14c
	// Line 4241, Address: 0x267bac, Func Offset: 0x15c
	// Line 4243, Address: 0x267bc8, Func Offset: 0x178
	// Line 4246, Address: 0x267c38, Func Offset: 0x1e8
	// Line 4249, Address: 0x267c54, Func Offset: 0x204
	// Line 4250, Address: 0x267c58, Func Offset: 0x208
	// Line 4249, Address: 0x267c5c, Func Offset: 0x20c
	// Line 4250, Address: 0x267c64, Func Offset: 0x214
	// Line 4256, Address: 0x267cc0, Func Offset: 0x270
	// Line 4257, Address: 0x267ccc, Func Offset: 0x27c
	// Line 4256, Address: 0x267cd0, Func Offset: 0x280
	// Line 4257, Address: 0x267cd8, Func Offset: 0x288
	// Line 4259, Address: 0x267ce4, Func Offset: 0x294
	// Line 4260, Address: 0x267cec, Func Offset: 0x29c
	// Line 4263, Address: 0x267d70, Func Offset: 0x320
	// Line 4265, Address: 0x267d94, Func Offset: 0x344
	// Line 4268, Address: 0x267db0, Func Offset: 0x360
	// Line 4269, Address: 0x267db4, Func Offset: 0x364
	// Line 4268, Address: 0x267db8, Func Offset: 0x368
	// Line 4269, Address: 0x267dc0, Func Offset: 0x370
	// Line 4274, Address: 0x267e2c, Func Offset: 0x3dc
	// Line 4275, Address: 0x267e30, Func Offset: 0x3e0
	// Line 4276, Address: 0x267e3c, Func Offset: 0x3ec
	// Line 4275, Address: 0x267e40, Func Offset: 0x3f0
	// Line 4276, Address: 0x267e48, Func Offset: 0x3f8
	// Line 4277, Address: 0x267e54, Func Offset: 0x404
	// Line 4279, Address: 0x267e5c, Func Offset: 0x40c
	// Line 4280, Address: 0x267e7c, Func Offset: 0x42c
	// Line 4281, Address: 0x267e80, Func Offset: 0x430
	// Line 4282, Address: 0x267e84, Func Offset: 0x434
	// Line 4284, Address: 0x267e8c, Func Offset: 0x43c
	// Line 4286, Address: 0x267eb4, Func Offset: 0x464
	// Line 4287, Address: 0x267ec0, Func Offset: 0x470
	// Line 4289, Address: 0x267ec8, Func Offset: 0x478
	// Line 4290, Address: 0x267ecc, Func Offset: 0x47c
	// Line 4289, Address: 0x267ed0, Func Offset: 0x480
	// Line 4291, Address: 0x267ed8, Func Offset: 0x488
	// Line 4293, Address: 0x267ee0, Func Offset: 0x490
	// Line 4294, Address: 0x267ee4, Func Offset: 0x494
	// Line 4293, Address: 0x267ee8, Func Offset: 0x498
	// Line 4294, Address: 0x267ef4, Func Offset: 0x4a4
	// Line 4295, Address: 0x267f04, Func Offset: 0x4b4
	// Line 4304, Address: 0x267f18, Func Offset: 0x4c8
	// Line 4306, Address: 0x267f28, Func Offset: 0x4d8
	// Line 4307, Address: 0x267f34, Func Offset: 0x4e4
	// Line 4306, Address: 0x267f38, Func Offset: 0x4e8
	// Line 4307, Address: 0x267f40, Func Offset: 0x4f0
	// Line 4308, Address: 0x267f54, Func Offset: 0x504
	// Line 4309, Address: 0x267f60, Func Offset: 0x510
	// Line 4311, Address: 0x267f68, Func Offset: 0x518
	// Line 4312, Address: 0x267f84, Func Offset: 0x534
	// Line 4313, Address: 0x267f90, Func Offset: 0x540
	// Line 4315, Address: 0x267f98, Func Offset: 0x548
	// Line 4316, Address: 0x267fb4, Func Offset: 0x564
	// Line 4317, Address: 0x267fc0, Func Offset: 0x570
	// Line 4319, Address: 0x267fc8, Func Offset: 0x578
	// Line 4320, Address: 0x267fe4, Func Offset: 0x594
	// Line 4321, Address: 0x267ff0, Func Offset: 0x5a0
	// Line 4323, Address: 0x267ff8, Func Offset: 0x5a8
	// Line 4324, Address: 0x268014, Func Offset: 0x5c4
	// Line 4327, Address: 0x268024, Func Offset: 0x5d4
	// Func End, Address: 0x268040, Func Offset: 0x5f0
}

// 
// Start address: 0x268040
void bhCheckDansa(BH_PWORK* pp)
{
	int etc_n;
	int i;
	float* dp;
	float pz;
	float px;
	_anon0* exp;
	// Line 4345, Address: 0x268040, Func Offset: 0
	// Line 4342, Address: 0x268044, Func Offset: 0x4
	// Line 4344, Address: 0x268048, Func Offset: 0x8
	// Line 4345, Address: 0x26804c, Func Offset: 0xc
	// Line 4346, Address: 0x268054, Func Offset: 0x14
	// Line 4345, Address: 0x268058, Func Offset: 0x18
	// Line 4346, Address: 0x268060, Func Offset: 0x20
	// Line 4347, Address: 0x268080, Func Offset: 0x40
	// Line 4354, Address: 0x268090, Func Offset: 0x50
	// Line 4358, Address: 0x268094, Func Offset: 0x54
	// Line 4349, Address: 0x268098, Func Offset: 0x58
	// Line 4350, Address: 0x2680e4, Func Offset: 0xa4
	// Line 4351, Address: 0x2680f4, Func Offset: 0xb4
	// Line 4354, Address: 0x26815c, Func Offset: 0x11c
	// Line 4356, Address: 0x268170, Func Offset: 0x130
	// Line 4358, Address: 0x26818c, Func Offset: 0x14c
	// Line 4363, Address: 0x268194, Func Offset: 0x154
	// Line 4364, Address: 0x268198, Func Offset: 0x158
	// Line 4365, Address: 0x2681a8, Func Offset: 0x168
	// Func End, Address: 0x2681b0, Func Offset: 0x170
}

// 
// Start address: 0x2681b0
int bhCheckFloorSound(BH_PWORK* pp, int flr_no, float px, float pz)
{
	int sno;
	int flr_n;
	int i;
	_anon0* fp;
	// Line 4383, Address: 0x2681b0, Func Offset: 0
	// Line 4382, Address: 0x2681b8, Func Offset: 0x8
	// Line 4383, Address: 0x2681bc, Func Offset: 0xc
	// Line 4384, Address: 0x2681d8, Func Offset: 0x28
	// Line 4387, Address: 0x2681e8, Func Offset: 0x38
	// Line 4386, Address: 0x2681ec, Func Offset: 0x3c
	// Line 4387, Address: 0x268228, Func Offset: 0x78
	// Line 4388, Address: 0x268244, Func Offset: 0x94
	// Line 4391, Address: 0x2682a8, Func Offset: 0xf8
	// Line 4394, Address: 0x2682c8, Func Offset: 0x118
	// Line 4396, Address: 0x2682d0, Func Offset: 0x120
	// Line 4397, Address: 0x2682d8, Func Offset: 0x128
	// Line 4401, Address: 0x2682e0, Func Offset: 0x130
	// Line 4403, Address: 0x2682f0, Func Offset: 0x140
	// Func End, Address: 0x2682f8, Func Offset: 0x148
}

// 
// Start address: 0x268300
_anon0* bhCheckFloorEnemy(int flr_no, float px, float pz)
{
	int flr_n;
	int i;
	_anon0* fp;
	// Line 4419, Address: 0x268300, Func Offset: 0
	// Line 4420, Address: 0x268324, Func Offset: 0x24
	// Line 4423, Address: 0x268334, Func Offset: 0x34
	// Line 4422, Address: 0x268338, Func Offset: 0x38
	// Line 4423, Address: 0x268374, Func Offset: 0x74
	// Line 4424, Address: 0x268390, Func Offset: 0x90
	// Line 4427, Address: 0x2683f4, Func Offset: 0xf4
	// Line 4430, Address: 0x2683fc, Func Offset: 0xfc
	// Line 4431, Address: 0x268410, Func Offset: 0x110
	// Line 4432, Address: 0x268414, Func Offset: 0x114
	// Func End, Address: 0x26841c, Func Offset: 0x11c
}

// 
// Start address: 0x268420
_anon0* bhCheckFloorEffect(int flr_no, float px, float pz)
{
	int flr_n;
	int i;
	_anon0* fp;
	// Line 4448, Address: 0x268420, Func Offset: 0
	// Line 4449, Address: 0x268444, Func Offset: 0x24
	// Line 4452, Address: 0x268454, Func Offset: 0x34
	// Line 4451, Address: 0x268458, Func Offset: 0x38
	// Line 4452, Address: 0x268494, Func Offset: 0x74
	// Line 4453, Address: 0x2684b0, Func Offset: 0x90
	// Line 4456, Address: 0x268514, Func Offset: 0xf4
	// Line 4459, Address: 0x26851c, Func Offset: 0xfc
	// Line 4460, Address: 0x268530, Func Offset: 0x110
	// Line 4461, Address: 0x268534, Func Offset: 0x114
	// Func End, Address: 0x26853c, Func Offset: 0x11c
}

// 
// Start address: 0x268540
_anon0* bhCheckWater(_anon20* pos)
{
	int flr_n;
	int i;
	_anon0* fp;
	// Line 4475, Address: 0x268540, Func Offset: 0
	// Line 4476, Address: 0x268564, Func Offset: 0x24
	// Line 4479, Address: 0x268574, Func Offset: 0x34
	// Line 4478, Address: 0x26857c, Func Offset: 0x3c
	// Line 4479, Address: 0x2685b8, Func Offset: 0x78
	// Line 4480, Address: 0x2685e0, Func Offset: 0xa0
	// Line 4483, Address: 0x268670, Func Offset: 0x130
	// Line 4486, Address: 0x268678, Func Offset: 0x138
	// Line 4487, Address: 0x268688, Func Offset: 0x148
	// Line 4488, Address: 0x26868c, Func Offset: 0x14c
	// Func End, Address: 0x268694, Func Offset: 0x154
}

// 
// Start address: 0x2686a0
_anon0* bhCheckL2Water(_anon39* lp, _anon20* pos)
{
	int flr_n;
	int i;
	float sca;
	float pz;
	float px;
	_anon20 ll;
	_anon20 pt;
	_anon20 ps;
	_anon39 pl;
	_anon0* fp;
	// Line 4499, Address: 0x2686a0, Func Offset: 0
	// Line 4505, Address: 0x2686cc, Func Offset: 0x2c
	// Line 4507, Address: 0x2686dc, Func Offset: 0x3c
	// Line 4505, Address: 0x2686e4, Func Offset: 0x44
	// Line 4507, Address: 0x2686e8, Func Offset: 0x48
	// Line 4508, Address: 0x268704, Func Offset: 0x64
	// Line 4510, Address: 0x268714, Func Offset: 0x74
	// Line 4511, Address: 0x268760, Func Offset: 0xc0
	// Line 4513, Address: 0x268790, Func Offset: 0xf0
	// Line 4517, Address: 0x268794, Func Offset: 0xf4
	// Line 4519, Address: 0x268798, Func Offset: 0xf8
	// Line 4513, Address: 0x2687a0, Func Offset: 0x100
	// Line 4514, Address: 0x2687a4, Func Offset: 0x104
	// Line 4519, Address: 0x2687ac, Func Offset: 0x10c
	// Line 4514, Address: 0x2687b0, Func Offset: 0x110
	// Line 4515, Address: 0x2687b8, Func Offset: 0x118
	// Line 4516, Address: 0x2687c0, Func Offset: 0x120
	// Line 4517, Address: 0x2687c4, Func Offset: 0x124
	// Line 4519, Address: 0x2687c8, Func Offset: 0x128
	// Line 4520, Address: 0x2687e8, Func Offset: 0x148
	// Line 4521, Address: 0x2687f0, Func Offset: 0x150
	// Line 4522, Address: 0x2687f4, Func Offset: 0x154
	// Line 4523, Address: 0x2687f8, Func Offset: 0x158
	// Line 4520, Address: 0x2687fc, Func Offset: 0x15c
	// Line 4523, Address: 0x268800, Func Offset: 0x160
	// Line 4520, Address: 0x268804, Func Offset: 0x164
	// Line 4521, Address: 0x268808, Func Offset: 0x168
	// Line 4522, Address: 0x268818, Func Offset: 0x178
	// Line 4523, Address: 0x268824, Func Offset: 0x184
	// Line 4524, Address: 0x268844, Func Offset: 0x1a4
	// Line 4526, Address: 0x26884c, Func Offset: 0x1ac
	// Line 4525, Address: 0x268850, Func Offset: 0x1b0
	// Line 4524, Address: 0x268858, Func Offset: 0x1b8
	// Line 4526, Address: 0x26885c, Func Offset: 0x1bc
	// Line 4525, Address: 0x268864, Func Offset: 0x1c4
	// Line 4527, Address: 0x268868, Func Offset: 0x1c8
	// Line 4529, Address: 0x268870, Func Offset: 0x1d0
	// Line 4527, Address: 0x268874, Func Offset: 0x1d4
	// Line 4528, Address: 0x26887c, Func Offset: 0x1dc
	// Line 4529, Address: 0x268884, Func Offset: 0x1e4
	// Line 4533, Address: 0x2688dc, Func Offset: 0x23c
	// Line 4536, Address: 0x2688e0, Func Offset: 0x240
	// Line 4533, Address: 0x2688e4, Func Offset: 0x244
	// Line 4534, Address: 0x2688e8, Func Offset: 0x248
	// Line 4535, Address: 0x2688f0, Func Offset: 0x250
	// Line 4536, Address: 0x2688f4, Func Offset: 0x254
	// Line 4541, Address: 0x2688fc, Func Offset: 0x25c
	// Line 4542, Address: 0x268910, Func Offset: 0x270
	// Line 4543, Address: 0x268914, Func Offset: 0x274
	// Func End, Address: 0x268944, Func Offset: 0x2a4
}

// 
// Start address: 0x268950
void bhResetAtariAttr()
{
	int atr_n;
	int i;
	_anon0* hp;
	// Line 4550, Address: 0x268950, Func Offset: 0
	// Line 4554, Address: 0x268968, Func Offset: 0x18
	// Line 4555, Address: 0x26898c, Func Offset: 0x3c
	// Line 4557, Address: 0x26899c, Func Offset: 0x4c
	// Line 4558, Address: 0x2689e8, Func Offset: 0x98
	// Line 4559, Address: 0x2689f8, Func Offset: 0xa8
	// Line 4561, Address: 0x268a10, Func Offset: 0xc0
	// Line 4563, Address: 0x268a20, Func Offset: 0xd0
	// Line 4564, Address: 0x268a40, Func Offset: 0xf0
	// Line 4565, Address: 0x268a68, Func Offset: 0x118
	// Line 4564, Address: 0x268a6c, Func Offset: 0x11c
	// Line 4565, Address: 0x268a70, Func Offset: 0x120
	// Line 4569, Address: 0x268a98, Func Offset: 0x148
	// Line 4571, Address: 0x268aa8, Func Offset: 0x158
	// Line 4572, Address: 0x268acc, Func Offset: 0x17c
	// Line 4573, Address: 0x268adc, Func Offset: 0x18c
	// Line 4574, Address: 0x268b00, Func Offset: 0x1b0
	// Line 4575, Address: 0x268b28, Func Offset: 0x1d8
	// Line 4576, Address: 0x268b30, Func Offset: 0x1e0
	// Line 4577, Address: 0x268b48, Func Offset: 0x1f8
	// Line 4578, Address: 0x268b70, Func Offset: 0x220
	// Line 4577, Address: 0x268b74, Func Offset: 0x224
	// Line 4578, Address: 0x268b78, Func Offset: 0x228
	// Line 4579, Address: 0x268b94, Func Offset: 0x244
	// Line 4578, Address: 0x268b98, Func Offset: 0x248
	// Line 4579, Address: 0x268ba0, Func Offset: 0x250
	// Line 4581, Address: 0x268bb0, Func Offset: 0x260
	// Line 4582, Address: 0x268bd4, Func Offset: 0x284
	// Line 4583, Address: 0x268be4, Func Offset: 0x294
	// Line 4584, Address: 0x268c08, Func Offset: 0x2b8
	// Line 4585, Address: 0x268c30, Func Offset: 0x2e0
	// Line 4586, Address: 0x268c38, Func Offset: 0x2e8
	// Line 4587, Address: 0x268c50, Func Offset: 0x300
	// Line 4588, Address: 0x268c78, Func Offset: 0x328
	// Line 4587, Address: 0x268c7c, Func Offset: 0x32c
	// Line 4588, Address: 0x268c80, Func Offset: 0x330
	// Line 4589, Address: 0x268c9c, Func Offset: 0x34c
	// Line 4588, Address: 0x268ca0, Func Offset: 0x350
	// Line 4589, Address: 0x268ca8, Func Offset: 0x358
	// Line 4590, Address: 0x268cb8, Func Offset: 0x368
	// Func End, Address: 0x268cd4, Func Offset: 0x384
}

// 
// Start address: 0x268ce0
void bhCheckPlayer(BH_PWORK* pp)
{
	int r;
	float ppz;
	float ppy;
	float ppx;
	float ln;
	float ey;
	float pz;
	float px;
	_anon20 vec;
	// Line 4609, Address: 0x268ce0, Func Offset: 0
	// Line 4617, Address: 0x268d08, Func Offset: 0x28
	// Line 4620, Address: 0x268d44, Func Offset: 0x64
	// Line 4622, Address: 0x268d4c, Func Offset: 0x6c
	// Line 4623, Address: 0x268d60, Func Offset: 0x80
	// Line 4624, Address: 0x268d68, Func Offset: 0x88
	// Line 4625, Address: 0x268d6c, Func Offset: 0x8c
	// Line 4623, Address: 0x268d70, Func Offset: 0x90
	// Line 4624, Address: 0x268d74, Func Offset: 0x94
	// Line 4625, Address: 0x268d78, Func Offset: 0x98
	// Line 4623, Address: 0x268d7c, Func Offset: 0x9c
	// Line 4624, Address: 0x268d80, Func Offset: 0xa0
	// Line 4626, Address: 0x268d84, Func Offset: 0xa4
	// Line 4627, Address: 0x268d8c, Func Offset: 0xac
	// Line 4628, Address: 0x268d94, Func Offset: 0xb4
	// Line 4629, Address: 0x268d9c, Func Offset: 0xbc
	// Line 4627, Address: 0x268da4, Func Offset: 0xc4
	// Line 4628, Address: 0x268da8, Func Offset: 0xc8
	// Line 4629, Address: 0x268dac, Func Offset: 0xcc
	// Line 4634, Address: 0x268db0, Func Offset: 0xd0
	// Line 4635, Address: 0x268db8, Func Offset: 0xd8
	// Line 4632, Address: 0x268dc0, Func Offset: 0xe0
	// Line 4634, Address: 0x268dc8, Func Offset: 0xe8
	// Line 4635, Address: 0x268dcc, Func Offset: 0xec
	// Line 4634, Address: 0x268dd0, Func Offset: 0xf0
	// Line 4635, Address: 0x268dd4, Func Offset: 0xf4
	// Line 4636, Address: 0x268dd8, Func Offset: 0xf8
	// Line 4632, Address: 0x268ddc, Func Offset: 0xfc
	// Line 4636, Address: 0x268de0, Func Offset: 0x100
	// Line 4637, Address: 0x268de8, Func Offset: 0x108
	// Line 4639, Address: 0x268e3c, Func Offset: 0x15c
	// Line 4640, Address: 0x268e5c, Func Offset: 0x17c
	// Line 4641, Address: 0x268e78, Func Offset: 0x198
	// Line 4643, Address: 0x268e84, Func Offset: 0x1a4
	// Line 4641, Address: 0x268e8c, Func Offset: 0x1ac
	// Line 4643, Address: 0x268e90, Func Offset: 0x1b0
	// Line 4644, Address: 0x268e9c, Func Offset: 0x1bc
	// Line 4645, Address: 0x268eb4, Func Offset: 0x1d4
	// Line 4650, Address: 0x268ec8, Func Offset: 0x1e8
	// Line 4651, Address: 0x268ed0, Func Offset: 0x1f0
	// Line 4652, Address: 0x268ed4, Func Offset: 0x1f4
	// Line 4654, Address: 0x268ed8, Func Offset: 0x1f8
	// Line 4651, Address: 0x268edc, Func Offset: 0x1fc
	// Line 4653, Address: 0x268ee0, Func Offset: 0x200
	// Line 4651, Address: 0x268ee4, Func Offset: 0x204
	// Line 4655, Address: 0x268ee8, Func Offset: 0x208
	// Line 4656, Address: 0x268ef4, Func Offset: 0x214
	// Line 4658, Address: 0x268ef8, Func Offset: 0x218
	// Line 4656, Address: 0x268efc, Func Offset: 0x21c
	// Line 4657, Address: 0x268f04, Func Offset: 0x224
	// Line 4658, Address: 0x268f10, Func Offset: 0x230
	// Line 4659, Address: 0x268f1c, Func Offset: 0x23c
	// Line 4658, Address: 0x268f20, Func Offset: 0x240
	// Line 4659, Address: 0x268f28, Func Offset: 0x248
	// Line 4660, Address: 0x268f3c, Func Offset: 0x25c
	// Line 4661, Address: 0x268f4c, Func Offset: 0x26c
	// Line 4663, Address: 0x268f5c, Func Offset: 0x27c
	// Line 4664, Address: 0x268f60, Func Offset: 0x280
	// Line 4663, Address: 0x268f64, Func Offset: 0x284
	// Line 4664, Address: 0x268f6c, Func Offset: 0x28c
	// Line 4667, Address: 0x268f7c, Func Offset: 0x29c
	// Func End, Address: 0x268fa8, Func Offset: 0x2c8
}

// 
// Start address: 0x268fb0
void bhCheckEnemies(BH_PWORK* pp)
{
	_anon20 ps[128];
	int hct;
	int i;
	int r;
	float ez1;
	float ey1;
	float ex1;
	float ez0;
	float ey0;
	float ex0;
	float ln;
	float pz;
	float px;
	// Line 4691, Address: 0x268fb0, Func Offset: 0
	// Line 4698, Address: 0x268fec, Func Offset: 0x3c
	// Line 4699, Address: 0x268ffc, Func Offset: 0x4c
	// Line 4700, Address: 0x269004, Func Offset: 0x54
	// Line 4701, Address: 0x26900c, Func Offset: 0x5c
	// Line 4819, Address: 0x269018, Func Offset: 0x68
	// Line 4699, Address: 0x26901c, Func Offset: 0x6c
	// Line 4700, Address: 0x269028, Func Offset: 0x78
	// Line 4818, Address: 0x26902c, Func Offset: 0x7c
	// Line 4819, Address: 0x269030, Func Offset: 0x80
	// Line 4701, Address: 0x269038, Func Offset: 0x88
	// Line 4819, Address: 0x26903c, Func Offset: 0x8c
	// Line 4821, Address: 0x269044, Func Offset: 0x94
	// Line 4825, Address: 0x269084, Func Offset: 0xd4
	// Line 4827, Address: 0x2690a8, Func Offset: 0xf8
	// Line 4829, Address: 0x2690cc, Func Offset: 0x11c
	// Line 4830, Address: 0x2690d0, Func Offset: 0x120
	// Line 4832, Address: 0x2690d8, Func Offset: 0x128
	// Line 4831, Address: 0x2690e0, Func Offset: 0x130
	// Line 4830, Address: 0x2690e8, Func Offset: 0x138
	// Line 4832, Address: 0x2690ec, Func Offset: 0x13c
	// Line 4833, Address: 0x2690f0, Func Offset: 0x140
	// Line 4835, Address: 0x2690f4, Func Offset: 0x144
	// Line 4834, Address: 0x2690f8, Func Offset: 0x148
	// Line 4831, Address: 0x2690fc, Func Offset: 0x14c
	// Line 4835, Address: 0x269100, Func Offset: 0x150
	// Line 4836, Address: 0x269108, Func Offset: 0x158
	// Line 4841, Address: 0x269154, Func Offset: 0x1a4
	// Line 4842, Address: 0x269174, Func Offset: 0x1c4
	// Line 4844, Address: 0x26917c, Func Offset: 0x1cc
	// Line 4845, Address: 0x269190, Func Offset: 0x1e0
	// Line 4865, Address: 0x269198, Func Offset: 0x1e8
	// Line 4864, Address: 0x26919c, Func Offset: 0x1ec
	// Line 4845, Address: 0x2691a0, Func Offset: 0x1f0
	// Line 4846, Address: 0x2691b0, Func Offset: 0x200
	// Line 4865, Address: 0x2691c8, Func Offset: 0x218
	// Line 4866, Address: 0x2691d4, Func Offset: 0x224
	// Line 4867, Address: 0x2691dc, Func Offset: 0x22c
	// Line 4868, Address: 0x2691e4, Func Offset: 0x234
	// Line 4872, Address: 0x2691f4, Func Offset: 0x244
	// Line 4873, Address: 0x269218, Func Offset: 0x268
	// Line 4874, Address: 0x269220, Func Offset: 0x270
	// Line 4875, Address: 0x26922c, Func Offset: 0x27c
	// Line 4876, Address: 0x269230, Func Offset: 0x280
	// Line 4877, Address: 0x269240, Func Offset: 0x290
	// Line 4878, Address: 0x269244, Func Offset: 0x294
	// Line 4879, Address: 0x269248, Func Offset: 0x298
	// Line 4877, Address: 0x269250, Func Offset: 0x2a0
	// Line 4878, Address: 0x269254, Func Offset: 0x2a4
	// Line 4879, Address: 0x269258, Func Offset: 0x2a8
	// Line 4880, Address: 0x269260, Func Offset: 0x2b0
	// Line 4881, Address: 0x269274, Func Offset: 0x2c4
	// Line 4882, Address: 0x269280, Func Offset: 0x2d0
	// Line 4883, Address: 0x269288, Func Offset: 0x2d8
	// Line 4884, Address: 0x269290, Func Offset: 0x2e0
	// Line 4888, Address: 0x269298, Func Offset: 0x2e8
	// Func End, Address: 0x2692d8, Func Offset: 0x328
}

// 
// Start address: 0x2692e0
int bhCheckWallAttrB89(_anon0* hp)
{
	unsigned char* cnop;
	int i;
	// Line 4902, Address: 0x2692e0, Func Offset: 0
	// Line 4903, Address: 0x269308, Func Offset: 0x28
	// Line 4905, Address: 0x269314, Func Offset: 0x34
	// Line 4908, Address: 0x269328, Func Offset: 0x48
	// Line 4907, Address: 0x269330, Func Offset: 0x50
	// Line 4908, Address: 0x269334, Func Offset: 0x54
	// Line 4909, Address: 0x269338, Func Offset: 0x58
	// Line 4910, Address: 0x26934c, Func Offset: 0x6c
	// Line 4912, Address: 0x26935c, Func Offset: 0x7c
	// Line 4913, Address: 0x269360, Func Offset: 0x80
	// Func End, Address: 0x269368, Func Offset: 0x88
}

