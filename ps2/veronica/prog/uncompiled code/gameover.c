typedef struct _anon0;
typedef struct npobj;
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
typedef union _anon15;
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

typedef void(*type_71)();
typedef void(*type_88)(void*);

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
typedef _anon27 type_10[32];
typedef _anon1* type_11[32];
typedef _anon1* type_12[512];
typedef _anon2* type_13[1300];
typedef _anon15 type_14[32];
typedef char type_15[32];
typedef _anon1* type_16[512];
typedef _anon15 type_17[32];
typedef _anon2* type_18[200];
typedef short type_19[32];
typedef _anon17 type_20[1];
typedef _anon1* type_21[128];
typedef unsigned int type_22[1];
typedef unsigned short type_23[7];
typedef _anon6 type_24[256];
typedef _anon2* type_25[8];
typedef unsigned short type_26[7][3];
typedef int* type_27[16];
typedef _anon1* type_28[128];
typedef unsigned short type_29[7][3][2];
typedef npobj* type_30[16];
typedef _anon1* type_31[128];
typedef int type_32[4];
typedef _anon2* type_33[16];
typedef unsigned int type_34[4];
typedef _anon9 type_35[16];
typedef _anon1* type_36[512];
typedef char type_37[256];
typedef float type_38[4];
typedef float type_39[4];
typedef float type_40[4];
typedef _anon5* type_41[128];
typedef float type_42[3];
typedef unsigned char type_43[64];
typedef float type_44[3][20];
typedef float type_45[3];
typedef float type_46[3][20];
typedef _anon27 type_47[256];
typedef _anon15 type_48[256];
typedef float type_49[3];
typedef float type_50[3][20];
typedef _anon15 type_51[256];
typedef char type_52[8];
typedef float type_53[3];
typedef _anon27 type_54[256];
typedef float type_55[3][20];
typedef _anon27 type_56[256];
typedef void* type_57[2];
typedef _anon23 type_58[7];
typedef _anon2* type_59[256];
typedef int type_60[4];
typedef unsigned char* type_61[256];
typedef unsigned int type_62[2];
typedef short type_63[256];
typedef _anon24 type_64[4];
typedef float type_65[3];
typedef short type_66[256];
typedef int type_67[3];
typedef int type_68[8];
typedef float type_69[3];
typedef _anon2* type_70[256];
typedef void(*type_72)()[4];
typedef _anon8 type_73[256];
typedef _anon17 type_74[450];
typedef _anon26 type_75[16];
typedef short type_76[256];
typedef char type_77[3];
typedef int type_78[64];
typedef _anon9 type_79[450];
typedef _anon30 type_80[4];
typedef _anon3 type_81[4];
typedef int type_82[450];
typedef unsigned int type_83[8];
typedef unsigned char type_84[450];
typedef char type_85[16];
typedef char type_86[4];
typedef unsigned short type_87[17];
typedef unsigned int type_89[32];
typedef unsigned int type_90[16];
typedef _anon33 type_91[64];
typedef unsigned int type_92[16];
typedef _anon33 type_93[64];
typedef unsigned int type_94[32];
typedef _anon33 type_95[64];
typedef unsigned int type_96[16];
typedef unsigned int type_97[3];
typedef BH_PWORK* type_98[16];
typedef unsigned int type_99[8];
typedef unsigned int type_100[1];
typedef unsigned int type_101[384];
typedef unsigned int type_102[2];
typedef unsigned char type_103[2];
typedef int* type_104[16];
typedef unsigned int type_105[4];
typedef char type_106[32];
typedef npobj* type_107[16];
typedef char type_108[64];
typedef _anon2* type_109[16];
typedef char type_110[4];
typedef _anon9 type_111[16];
typedef short type_112[4];
typedef unsigned char type_113[4];
typedef _anon28 type_114[16];
typedef unsigned int type_115[32];
typedef _anon27 type_116[32];
typedef _anon1* type_117[512];
typedef float type_118[16];
typedef _anon1* type_119[128];
typedef _anon1* type_120[512];
typedef unsigned char type_121[64];
typedef _anon1* type_122[512];

struct _anon0
{
	_anon32 p3c;
	_anon27 pt[256];
	_anon15 cl[256];
	_anon15 uv[256];
	_anon27 cp[256];
	_anon27 op[256];
	float pz;
	float scl;
	float tfn;
	float tnn;
	int cont_x;
	int count;
	int cur_ct;
	int exp_ct;
};

struct npobj
{
	unsigned int evalflags;
	_anon25* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
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
	_anon9 mdl[16];
	_anon9* mlwP;
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
	_anon38 cspr;
	int pn;
	_anon30* pvp;
	_anon3* tvp;
	_anon30 pv[4];
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
	_anon9 mdl[16];
	_anon9* mlwP;
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
	_anon39 watr;
	_anon18* cpcl;
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
	_anon17* textures;
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
	_anon27 ply_pos;
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
	_anon10* p1per;
	_anon10* p2per;
	_anon10* kbper;
	_anon10* msper;
	_anon10 ms_per;
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
	_anon8 txbp[256];
	unsigned char* ef_psp;
	_anon17 ef_tex[450];
	_anon2 ef_tlist;
	_anon31 ef;
	short efid[256];
	_anon9 efm[450];
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
	_anon14 ren_info;
	_anon17 ren_tex[1];
	_anon2 ren_tlist;
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
	_anon35 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon19* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon24 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon26 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon33* pl_htp;
	int costume;
	_anon27 hd_pos;
	_anon27 apos;
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
	_anon11 door;
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
	_anon27 ufo_pos;
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
	_anon28 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon27 ghtp[32];
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
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon16* md2P;
	unsigned short* atrP;
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
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon2* texP;
	_anon21* owP;
};

struct _anon10
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
	_anon36* info;
};

struct _anon11
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

struct _anon12
{
	short u;
	short v;
};

struct _anon13
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct _anon14
{
	void* texaddr;
	_anon7 texsurface;
};

union _anon15
{
	unsigned int color;
	_anon12 tex;
	_anon13 argb;
};

struct _anon16
{
	void* p[2];
};

struct _anon17
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon18
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon19
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
	_anon22* light;
};

struct _anon20
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon21
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon22
{
	float mtrx[16];
	_anon27 pnt;
	_anon27 vctr;
	int stat;
	int reserve;
	_anon29 ltcal;
	_anon37 attr;
};

struct _anon23
{
	int frm;
	float px;
	float py;
	float pz;
};

struct _anon24
{
	_anon27 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon25
{
	int* vlist;
	short* plist;
	_anon27 center;
	float r;
};

struct _anon26
{
	float x;
	float y;
};

struct _anon27
{
	float x;
	float y;
	float z;
};

struct _anon28
{
	_anon27 c1;
	_anon27 c2;
	float r1;
	float r2;
};

struct _anon29
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
	_anon27 lpnt;
	_anon27 lvctr;
	_anon27 lmvctr;
	_anon20 atten;
	_anon20 amb;
	_anon20 dif;
	_anon20 spc;
	_anon20 mamb;
	_anon20 mdif;
	_anon20 mspc;
};

struct _anon30
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon31
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

struct _anon32
{
	_anon27* p;
	_anon15* col;
	_anon15* tex;
	unsigned int num;
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

struct _anon35
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon36
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

struct _anon37
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
	_anon20 argb;
};

struct _anon38
{
	_anon27 c;
	float r;
};

struct _anon39
{
	_anon27 c1;
	_anon27 c2;
	float r;
};

void(*bhCtrGov_mode0)()[4];
float gov_yn[16];
_anon23 gov_etb[7];
unsigned short cnt_mes[17];
_anon4* sys;
float cmat[16];
BH_PWORK* plp;
_anon34 cam;
unsigned short PlMtnAct[7][3][2];

void bhControlGameOver();
void bhSelectContinue();
void bhInitGameOver();
void bhMainGameOver();
void bhExitGameOver();
void bhDrawGameOver();

// 
// Start address: 0x2b9a70
void bhControlGameOver()
{
	// Line 179, Address: 0x2b9a70, Func Offset: 0
	// Func End, Address: 0x2b9aa0, Func Offset: 0x30
}

// 
// Start address: 0x2b9aa0
void bhSelectContinue()
{
	_anon0* gv;
	// Line 188, Address: 0x2b9aa0, Func Offset: 0
	// Line 191, Address: 0x2b9aa4, Func Offset: 0x4
	// Line 188, Address: 0x2b9aa8, Func Offset: 0x8
	// Line 191, Address: 0x2b9aac, Func Offset: 0xc
	// Line 196, Address: 0x2b9abc, Func Offset: 0x1c
	// Line 191, Address: 0x2b9ac0, Func Offset: 0x20
	// Line 192, Address: 0x2b9acc, Func Offset: 0x2c
	// Line 193, Address: 0x2b9ae0, Func Offset: 0x40
	// Line 194, Address: 0x2b9ae4, Func Offset: 0x44
	// Line 195, Address: 0x2b9ae8, Func Offset: 0x48
	// Line 196, Address: 0x2b9aec, Func Offset: 0x4c
	// Line 197, Address: 0x2b9b00, Func Offset: 0x60
	// Line 198, Address: 0x2b9b14, Func Offset: 0x74
	// Func End, Address: 0x2b9b20, Func Offset: 0x80
}

// 
// Start address: 0x2b9b20
void bhInitGameOver()
{
	int rn;
	int ct;
	int y;
	int x;
	int j;
	int i;
	float ar;
	float scl;
	_anon0* gv;
	// Line 204, Address: 0x2b9b20, Func Offset: 0
	// Line 208, Address: 0x2b9b54, Func Offset: 0x34
	// Line 209, Address: 0x2b9b5c, Func Offset: 0x3c
	// Line 212, Address: 0x2b9b60, Func Offset: 0x40
	// Line 215, Address: 0x2b9b64, Func Offset: 0x44
	// Line 208, Address: 0x2b9b68, Func Offset: 0x48
	// Line 209, Address: 0x2b9b6c, Func Offset: 0x4c
	// Line 208, Address: 0x2b9b70, Func Offset: 0x50
	// Line 209, Address: 0x2b9b78, Func Offset: 0x58
	// Line 211, Address: 0x2b9b80, Func Offset: 0x60
	// Line 209, Address: 0x2b9b84, Func Offset: 0x64
	// Line 211, Address: 0x2b9b8c, Func Offset: 0x6c
	// Line 212, Address: 0x2b9b9c, Func Offset: 0x7c
	// Line 213, Address: 0x2b9bb0, Func Offset: 0x90
	// Line 215, Address: 0x2b9bc4, Func Offset: 0xa4
	// Line 216, Address: 0x2b9bd4, Func Offset: 0xb4
	// Line 217, Address: 0x2b9be8, Func Offset: 0xc8
	// Line 218, Address: 0x2b9bfc, Func Offset: 0xdc
	// Line 220, Address: 0x2b9c04, Func Offset: 0xe4
	// Line 218, Address: 0x2b9c08, Func Offset: 0xe8
	// Line 219, Address: 0x2b9c14, Func Offset: 0xf4
	// Line 220, Address: 0x2b9c28, Func Offset: 0x108
	// Line 222, Address: 0x2b9c4c, Func Offset: 0x12c
	// Line 224, Address: 0x2b9c60, Func Offset: 0x140
	// Line 230, Address: 0x2b9c68, Func Offset: 0x148
	// Line 232, Address: 0x2b9c70, Func Offset: 0x150
	// Line 228, Address: 0x2b9c74, Func Offset: 0x154
	// Line 224, Address: 0x2b9c78, Func Offset: 0x158
	// Line 231, Address: 0x2b9c80, Func Offset: 0x160
	// Line 224, Address: 0x2b9c88, Func Offset: 0x168
	// Line 232, Address: 0x2b9c8c, Func Offset: 0x16c
	// Line 229, Address: 0x2b9c94, Func Offset: 0x174
	// Line 232, Address: 0x2b9c98, Func Offset: 0x178
	// Line 225, Address: 0x2b9c9c, Func Offset: 0x17c
	// Line 226, Address: 0x2b9ca4, Func Offset: 0x184
	// Line 227, Address: 0x2b9cac, Func Offset: 0x18c
	// Line 228, Address: 0x2b9cb4, Func Offset: 0x194
	// Line 229, Address: 0x2b9cb8, Func Offset: 0x198
	// Line 230, Address: 0x2b9cbc, Func Offset: 0x19c
	// Line 231, Address: 0x2b9cc0, Func Offset: 0x1a0
	// Line 233, Address: 0x2b9cc4, Func Offset: 0x1a4
	// Line 232, Address: 0x2b9ccc, Func Offset: 0x1ac
	// Line 233, Address: 0x2b9cd0, Func Offset: 0x1b0
	// Line 234, Address: 0x2b9cf0, Func Offset: 0x1d0
	// Line 235, Address: 0x2b9d00, Func Offset: 0x1e0
	// Line 237, Address: 0x2b9d20, Func Offset: 0x200
	// Line 244, Address: 0x2b9d40, Func Offset: 0x220
	// Line 237, Address: 0x2b9d44, Func Offset: 0x224
	// Line 238, Address: 0x2b9d4c, Func Offset: 0x22c
	// Line 239, Address: 0x2b9d50, Func Offset: 0x230
	// Line 240, Address: 0x2b9d54, Func Offset: 0x234
	// Line 241, Address: 0x2b9d6c, Func Offset: 0x24c
	// Line 242, Address: 0x2b9d70, Func Offset: 0x250
	// Line 244, Address: 0x2b9d74, Func Offset: 0x254
	// Line 245, Address: 0x2b9d7c, Func Offset: 0x25c
	// Line 246, Address: 0x2b9d8c, Func Offset: 0x26c
	// Line 250, Address: 0x2b9d9c, Func Offset: 0x27c
	// Line 252, Address: 0x2b9da4, Func Offset: 0x284
	// Line 251, Address: 0x2b9da8, Func Offset: 0x288
	// Line 274, Address: 0x2b9db0, Func Offset: 0x290
	// Line 249, Address: 0x2b9db4, Func Offset: 0x294
	// Line 247, Address: 0x2b9db8, Func Offset: 0x298
	// Line 274, Address: 0x2b9dbc, Func Offset: 0x29c
	// Line 252, Address: 0x2b9dd4, Func Offset: 0x2b4
	// Line 274, Address: 0x2b9ddc, Func Offset: 0x2bc
	// Line 254, Address: 0x2b9de8, Func Offset: 0x2c8
	// Line 274, Address: 0x2b9df0, Func Offset: 0x2d0
	// Line 253, Address: 0x2b9df4, Func Offset: 0x2d4
	// Line 255, Address: 0x2b9df8, Func Offset: 0x2d8
	// Line 254, Address: 0x2b9dfc, Func Offset: 0x2dc
	// Line 274, Address: 0x2b9e20, Func Offset: 0x300
	// Line 255, Address: 0x2b9e2c, Func Offset: 0x30c
	// Line 256, Address: 0x2b9e30, Func Offset: 0x310
	// Line 274, Address: 0x2b9e38, Func Offset: 0x318
	// Line 256, Address: 0x2b9e3c, Func Offset: 0x31c
	// Line 274, Address: 0x2b9e58, Func Offset: 0x338
	// Line 256, Address: 0x2b9e60, Func Offset: 0x340
	// Line 274, Address: 0x2b9e64, Func Offset: 0x344
	// Line 257, Address: 0x2b9e80, Func Offset: 0x360
	// Line 256, Address: 0x2b9e84, Func Offset: 0x364
	// Line 274, Address: 0x2b9e88, Func Offset: 0x368
	// Line 257, Address: 0x2b9e94, Func Offset: 0x374
	// Line 274, Address: 0x2b9e98, Func Offset: 0x378
	// Line 260, Address: 0x2b9ec8, Func Offset: 0x3a8
	// Line 274, Address: 0x2b9ed0, Func Offset: 0x3b0
	// Line 260, Address: 0x2b9ed4, Func Offset: 0x3b4
	// Line 274, Address: 0x2b9ef0, Func Offset: 0x3d0
	// Line 260, Address: 0x2b9ef8, Func Offset: 0x3d8
	// Line 274, Address: 0x2b9efc, Func Offset: 0x3dc
	// Line 260, Address: 0x2b9f14, Func Offset: 0x3f4
	// Line 274, Address: 0x2b9f18, Func Offset: 0x3f8
	// Line 261, Address: 0x2b9f1c, Func Offset: 0x3fc
	// Line 260, Address: 0x2b9f20, Func Offset: 0x400
	// Line 274, Address: 0x2b9f24, Func Offset: 0x404
	// Line 261, Address: 0x2b9f30, Func Offset: 0x410
	// Line 274, Address: 0x2b9f34, Func Offset: 0x414
	// Line 264, Address: 0x2b9f68, Func Offset: 0x448
	// Line 274, Address: 0x2b9f70, Func Offset: 0x450
	// Line 264, Address: 0x2b9f74, Func Offset: 0x454
	// Line 274, Address: 0x2b9f90, Func Offset: 0x470
	// Line 264, Address: 0x2b9f98, Func Offset: 0x478
	// Line 274, Address: 0x2b9f9c, Func Offset: 0x47c
	// Line 265, Address: 0x2b9fb8, Func Offset: 0x498
	// Line 264, Address: 0x2b9fbc, Func Offset: 0x49c
	// Line 274, Address: 0x2b9fc0, Func Offset: 0x4a0
	// Line 265, Address: 0x2b9fcc, Func Offset: 0x4ac
	// Line 274, Address: 0x2b9fd0, Func Offset: 0x4b0
	// Line 268, Address: 0x2b9ff8, Func Offset: 0x4d8
	// Line 274, Address: 0x2ba000, Func Offset: 0x4e0
	// Line 268, Address: 0x2ba004, Func Offset: 0x4e4
	// Line 274, Address: 0x2ba020, Func Offset: 0x500
	// Line 268, Address: 0x2ba028, Func Offset: 0x508
	// Line 274, Address: 0x2ba02c, Func Offset: 0x50c
	// Line 268, Address: 0x2ba044, Func Offset: 0x524
	// Line 274, Address: 0x2ba048, Func Offset: 0x528
	// Line 269, Address: 0x2ba04c, Func Offset: 0x52c
	// Line 268, Address: 0x2ba050, Func Offset: 0x530
	// Line 274, Address: 0x2ba054, Func Offset: 0x534
	// Line 269, Address: 0x2ba060, Func Offset: 0x540
	// Line 274, Address: 0x2ba064, Func Offset: 0x544
	// Line 275, Address: 0x2ba0b8, Func Offset: 0x598
	// Func End, Address: 0x2ba0f0, Func Offset: 0x5d0
}

// 
// Start address: 0x2ba0f0
void bhMainGameOver()
{
	unsigned int argb;
	int rn;
	int ct;
	int y;
	int x;
	int j;
	int i;
	float ar;
	float scn;
	float scl;
	_anon26 cpos;
	_anon0* gv;
	// Line 282, Address: 0x2ba0f0, Func Offset: 0
	// Line 283, Address: 0x2ba12c, Func Offset: 0x3c
	// Line 288, Address: 0x2ba134, Func Offset: 0x44
	// Line 283, Address: 0x2ba138, Func Offset: 0x48
	// Line 288, Address: 0x2ba144, Func Offset: 0x54
	// Line 290, Address: 0x2ba184, Func Offset: 0x94
	// Line 291, Address: 0x2ba19c, Func Offset: 0xac
	// Line 294, Address: 0x2ba1c0, Func Offset: 0xd0
	// Line 296, Address: 0x2ba1c8, Func Offset: 0xd8
	// Line 299, Address: 0x2ba1e4, Func Offset: 0xf4
	// Line 300, Address: 0x2ba210, Func Offset: 0x120
	// Line 301, Address: 0x2ba220, Func Offset: 0x130
	// Line 302, Address: 0x2ba228, Func Offset: 0x138
	// Line 301, Address: 0x2ba230, Func Offset: 0x140
	// Line 302, Address: 0x2ba238, Func Offset: 0x148
	// Line 304, Address: 0x2ba248, Func Offset: 0x158
	// Line 305, Address: 0x2ba258, Func Offset: 0x168
	// Line 304, Address: 0x2ba260, Func Offset: 0x170
	// Line 305, Address: 0x2ba264, Func Offset: 0x174
	// Line 304, Address: 0x2ba268, Func Offset: 0x178
	// Line 305, Address: 0x2ba270, Func Offset: 0x180
	// Line 307, Address: 0x2ba280, Func Offset: 0x190
	// Line 308, Address: 0x2ba298, Func Offset: 0x1a8
	// Line 309, Address: 0x2ba2a8, Func Offset: 0x1b8
	// Line 310, Address: 0x2ba2b8, Func Offset: 0x1c8
	// Line 311, Address: 0x2ba2c8, Func Offset: 0x1d8
	// Line 312, Address: 0x2ba2d8, Func Offset: 0x1e8
	// Line 316, Address: 0x2ba2e0, Func Offset: 0x1f0
	// Line 317, Address: 0x2ba2e8, Func Offset: 0x1f8
	// Line 312, Address: 0x2ba2ec, Func Offset: 0x1fc
	// Line 313, Address: 0x2ba2f0, Func Offset: 0x200
	// Line 314, Address: 0x2ba2fc, Func Offset: 0x20c
	// Line 313, Address: 0x2ba300, Func Offset: 0x210
	// Line 314, Address: 0x2ba308, Func Offset: 0x218
	// Line 315, Address: 0x2ba310, Func Offset: 0x220
	// Line 316, Address: 0x2ba31c, Func Offset: 0x22c
	// Line 315, Address: 0x2ba320, Func Offset: 0x230
	// Line 316, Address: 0x2ba328, Func Offset: 0x238
	// Line 317, Address: 0x2ba330, Func Offset: 0x240
	// Line 316, Address: 0x2ba334, Func Offset: 0x244
	// Line 317, Address: 0x2ba33c, Func Offset: 0x24c
	// Line 318, Address: 0x2ba348, Func Offset: 0x258
	// Line 319, Address: 0x2ba350, Func Offset: 0x260
	// Line 325, Address: 0x2ba360, Func Offset: 0x270
	// Line 319, Address: 0x2ba368, Func Offset: 0x278
	// Line 320, Address: 0x2ba36c, Func Offset: 0x27c
	// Line 323, Address: 0x2ba370, Func Offset: 0x280
	// Line 328, Address: 0x2ba374, Func Offset: 0x284
	// Line 330, Address: 0x2ba378, Func Offset: 0x288
	// Line 319, Address: 0x2ba37c, Func Offset: 0x28c
	// Line 320, Address: 0x2ba384, Func Offset: 0x294
	// Line 334, Address: 0x2ba388, Func Offset: 0x298
	// Line 337, Address: 0x2ba38c, Func Offset: 0x29c
	// Line 338, Address: 0x2ba390, Func Offset: 0x2a0
	// Line 320, Address: 0x2ba394, Func Offset: 0x2a4
	// Line 321, Address: 0x2ba398, Func Offset: 0x2a8
	// Line 346, Address: 0x2ba3a0, Func Offset: 0x2b0
	// Line 344, Address: 0x2ba3a4, Func Offset: 0x2b4
	// Line 345, Address: 0x2ba3a8, Func Offset: 0x2b8
	// Line 346, Address: 0x2ba3ac, Func Offset: 0x2bc
	// Line 321, Address: 0x2ba3b0, Func Offset: 0x2c0
	// Line 322, Address: 0x2ba3b4, Func Offset: 0x2c4
	// Line 323, Address: 0x2ba3c0, Func Offset: 0x2d0
	// Line 324, Address: 0x2ba3cc, Func Offset: 0x2dc
	// Line 325, Address: 0x2ba3d8, Func Offset: 0x2e8
	// Line 324, Address: 0x2ba3dc, Func Offset: 0x2ec
	// Line 325, Address: 0x2ba3e0, Func Offset: 0x2f0
	// Line 326, Address: 0x2ba3e8, Func Offset: 0x2f8
	// Line 325, Address: 0x2ba3ec, Func Offset: 0x2fc
	// Line 326, Address: 0x2ba424, Func Offset: 0x334
	// Line 327, Address: 0x2ba42c, Func Offset: 0x33c
	// Line 328, Address: 0x2ba438, Func Offset: 0x348
	// Line 329, Address: 0x2ba444, Func Offset: 0x354
	// Line 330, Address: 0x2ba450, Func Offset: 0x360
	// Line 329, Address: 0x2ba454, Func Offset: 0x364
	// Line 330, Address: 0x2ba45c, Func Offset: 0x36c
	// Line 331, Address: 0x2ba464, Func Offset: 0x374
	// Line 330, Address: 0x2ba468, Func Offset: 0x378
	// Line 331, Address: 0x2ba478, Func Offset: 0x388
	// Line 332, Address: 0x2ba480, Func Offset: 0x390
	// Line 331, Address: 0x2ba484, Func Offset: 0x394
	// Line 332, Address: 0x2ba494, Func Offset: 0x3a4
	// Line 333, Address: 0x2ba49c, Func Offset: 0x3ac
	// Line 332, Address: 0x2ba4a0, Func Offset: 0x3b0
	// Line 333, Address: 0x2ba4b0, Func Offset: 0x3c0
	// Line 334, Address: 0x2ba4b8, Func Offset: 0x3c8
	// Line 333, Address: 0x2ba4bc, Func Offset: 0x3cc
	// Line 334, Address: 0x2ba4cc, Func Offset: 0x3dc
	// Line 335, Address: 0x2ba4e0, Func Offset: 0x3f0
	// Line 334, Address: 0x2ba4e4, Func Offset: 0x3f4
	// Line 335, Address: 0x2ba4ec, Func Offset: 0x3fc
	// Line 336, Address: 0x2ba500, Func Offset: 0x410
	// Line 335, Address: 0x2ba504, Func Offset: 0x414
	// Line 336, Address: 0x2ba50c, Func Offset: 0x41c
	// Line 337, Address: 0x2ba514, Func Offset: 0x424
	// Line 336, Address: 0x2ba518, Func Offset: 0x428
	// Line 337, Address: 0x2ba520, Func Offset: 0x430
	// Line 338, Address: 0x2ba524, Func Offset: 0x434
	// Line 339, Address: 0x2ba52c, Func Offset: 0x43c
	// Line 340, Address: 0x2ba534, Func Offset: 0x444
	// Line 341, Address: 0x2ba544, Func Offset: 0x454
	// Line 342, Address: 0x2ba554, Func Offset: 0x464
	// Line 343, Address: 0x2ba564, Func Offset: 0x474
	// Line 344, Address: 0x2ba574, Func Offset: 0x484
	// Line 345, Address: 0x2ba584, Func Offset: 0x494
	// Line 346, Address: 0x2ba594, Func Offset: 0x4a4
	// Line 347, Address: 0x2ba5a0, Func Offset: 0x4b0
	// Line 346, Address: 0x2ba5a4, Func Offset: 0x4b4
	// Line 347, Address: 0x2ba5ac, Func Offset: 0x4bc
	// Line 348, Address: 0x2ba5b8, Func Offset: 0x4c8
	// Line 350, Address: 0x2ba5c0, Func Offset: 0x4d0
	// Line 351, Address: 0x2ba5c8, Func Offset: 0x4d8
	// Line 350, Address: 0x2ba5d4, Func Offset: 0x4e4
	// Line 351, Address: 0x2ba5e0, Func Offset: 0x4f0
	// Line 354, Address: 0x2ba5e8, Func Offset: 0x4f8
	// Line 356, Address: 0x2ba5f8, Func Offset: 0x508
	// Line 357, Address: 0x2ba608, Func Offset: 0x518
	// Line 360, Address: 0x2ba610, Func Offset: 0x520
	// Line 357, Address: 0x2ba618, Func Offset: 0x528
	// Line 358, Address: 0x2ba61c, Func Offset: 0x52c
	// Line 359, Address: 0x2ba628, Func Offset: 0x538
	// Line 358, Address: 0x2ba62c, Func Offset: 0x53c
	// Line 359, Address: 0x2ba634, Func Offset: 0x544
	// Line 360, Address: 0x2ba63c, Func Offset: 0x54c
	// Line 362, Address: 0x2ba64c, Func Offset: 0x55c
	// Line 368, Address: 0x2ba654, Func Offset: 0x564
	// Line 369, Address: 0x2ba658, Func Offset: 0x568
	// Line 370, Address: 0x2ba65c, Func Offset: 0x56c
	// Line 371, Address: 0x2ba660, Func Offset: 0x570
	// Line 370, Address: 0x2ba664, Func Offset: 0x574
	// Line 393, Address: 0x2ba668, Func Offset: 0x578
	// Line 367, Address: 0x2ba66c, Func Offset: 0x57c
	// Line 365, Address: 0x2ba670, Func Offset: 0x580
	// Line 393, Address: 0x2ba674, Func Offset: 0x584
	// Line 371, Address: 0x2ba68c, Func Offset: 0x59c
	// Line 393, Address: 0x2ba694, Func Offset: 0x5a4
	// Line 373, Address: 0x2ba6a0, Func Offset: 0x5b0
	// Line 393, Address: 0x2ba6a8, Func Offset: 0x5b8
	// Line 372, Address: 0x2ba6ac, Func Offset: 0x5bc
	// Line 374, Address: 0x2ba6b0, Func Offset: 0x5c0
	// Line 373, Address: 0x2ba6b4, Func Offset: 0x5c4
	// Line 393, Address: 0x2ba6d8, Func Offset: 0x5e8
	// Line 375, Address: 0x2ba6e8, Func Offset: 0x5f8
	// Line 393, Address: 0x2ba6f0, Func Offset: 0x600
	// Line 375, Address: 0x2ba6f4, Func Offset: 0x604
	// Line 393, Address: 0x2ba714, Func Offset: 0x624
	// Line 375, Address: 0x2ba71c, Func Offset: 0x62c
	// Line 393, Address: 0x2ba720, Func Offset: 0x630
	// Line 375, Address: 0x2ba72c, Func Offset: 0x63c
	// Line 393, Address: 0x2ba730, Func Offset: 0x640
	// Line 375, Address: 0x2ba734, Func Offset: 0x644
	// Line 393, Address: 0x2ba738, Func Offset: 0x648
	// Line 376, Address: 0x2ba73c, Func Offset: 0x64c
	// Line 375, Address: 0x2ba740, Func Offset: 0x650
	// Line 393, Address: 0x2ba744, Func Offset: 0x654
	// Line 376, Address: 0x2ba750, Func Offset: 0x660
	// Line 393, Address: 0x2ba754, Func Offset: 0x664
	// Line 378, Address: 0x2ba77c, Func Offset: 0x68c
	// Line 379, Address: 0x2ba780, Func Offset: 0x690
	// Line 393, Address: 0x2ba788, Func Offset: 0x698
	// Line 379, Address: 0x2ba78c, Func Offset: 0x69c
	// Line 393, Address: 0x2ba7ac, Func Offset: 0x6bc
	// Line 379, Address: 0x2ba7b4, Func Offset: 0x6c4
	// Line 393, Address: 0x2ba7b8, Func Offset: 0x6c8
	// Line 379, Address: 0x2ba7c4, Func Offset: 0x6d4
	// Line 393, Address: 0x2ba7cc, Func Offset: 0x6dc
	// Line 379, Address: 0x2ba7d0, Func Offset: 0x6e0
	// Line 393, Address: 0x2ba7d4, Func Offset: 0x6e4
	// Line 380, Address: 0x2ba7d8, Func Offset: 0x6e8
	// Line 379, Address: 0x2ba7dc, Func Offset: 0x6ec
	// Line 393, Address: 0x2ba7e0, Func Offset: 0x6f0
	// Line 380, Address: 0x2ba7ec, Func Offset: 0x6fc
	// Line 393, Address: 0x2ba7f0, Func Offset: 0x700
	// Line 382, Address: 0x2ba81c, Func Offset: 0x72c
	// Line 383, Address: 0x2ba820, Func Offset: 0x730
	// Line 393, Address: 0x2ba828, Func Offset: 0x738
	// Line 383, Address: 0x2ba82c, Func Offset: 0x73c
	// Line 393, Address: 0x2ba84c, Func Offset: 0x75c
	// Line 383, Address: 0x2ba854, Func Offset: 0x764
	// Line 393, Address: 0x2ba858, Func Offset: 0x768
	// Line 383, Address: 0x2ba864, Func Offset: 0x774
	// Line 393, Address: 0x2ba868, Func Offset: 0x778
	// Line 383, Address: 0x2ba86c, Func Offset: 0x77c
	// Line 393, Address: 0x2ba870, Func Offset: 0x780
	// Line 384, Address: 0x2ba874, Func Offset: 0x784
	// Line 383, Address: 0x2ba878, Func Offset: 0x788
	// Line 393, Address: 0x2ba87c, Func Offset: 0x78c
	// Line 384, Address: 0x2ba888, Func Offset: 0x798
	// Line 393, Address: 0x2ba88c, Func Offset: 0x79c
	// Line 386, Address: 0x2ba8ac, Func Offset: 0x7bc
	// Line 387, Address: 0x2ba8b0, Func Offset: 0x7c0
	// Line 393, Address: 0x2ba8b8, Func Offset: 0x7c8
	// Line 387, Address: 0x2ba8bc, Func Offset: 0x7cc
	// Line 393, Address: 0x2ba8dc, Func Offset: 0x7ec
	// Line 387, Address: 0x2ba8e4, Func Offset: 0x7f4
	// Line 393, Address: 0x2ba8e8, Func Offset: 0x7f8
	// Line 387, Address: 0x2ba8f4, Func Offset: 0x804
	// Line 393, Address: 0x2ba8fc, Func Offset: 0x80c
	// Line 387, Address: 0x2ba900, Func Offset: 0x810
	// Line 393, Address: 0x2ba904, Func Offset: 0x814
	// Line 388, Address: 0x2ba908, Func Offset: 0x818
	// Line 387, Address: 0x2ba90c, Func Offset: 0x81c
	// Line 393, Address: 0x2ba910, Func Offset: 0x820
	// Line 388, Address: 0x2ba91c, Func Offset: 0x82c
	// Line 393, Address: 0x2ba920, Func Offset: 0x830
	// Line 394, Address: 0x2ba968, Func Offset: 0x878
	// Line 400, Address: 0x2ba970, Func Offset: 0x880
	// Line 395, Address: 0x2ba980, Func Offset: 0x890
	// Line 397, Address: 0x2ba988, Func Offset: 0x898
	// Line 401, Address: 0x2ba9a0, Func Offset: 0x8b0
	// Line 400, Address: 0x2ba9a8, Func Offset: 0x8b8
	// Line 397, Address: 0x2ba9ac, Func Offset: 0x8bc
	// Line 398, Address: 0x2ba9b4, Func Offset: 0x8c4
	// Line 399, Address: 0x2ba9c4, Func Offset: 0x8d4
	// Line 400, Address: 0x2ba9d4, Func Offset: 0x8e4
	// Line 401, Address: 0x2ba9f8, Func Offset: 0x908
	// Line 402, Address: 0x2baa00, Func Offset: 0x910
	// Line 404, Address: 0x2baa10, Func Offset: 0x920
	// Line 405, Address: 0x2baa30, Func Offset: 0x940
	// Line 406, Address: 0x2baa50, Func Offset: 0x960
	// Line 411, Address: 0x2baa58, Func Offset: 0x968
	// Line 412, Address: 0x2baa80, Func Offset: 0x990
	// Line 414, Address: 0x2baa8c, Func Offset: 0x99c
	// Line 412, Address: 0x2baa90, Func Offset: 0x9a0
	// Line 413, Address: 0x2baaa8, Func Offset: 0x9b8
	// Line 412, Address: 0x2baab0, Func Offset: 0x9c0
	// Line 413, Address: 0x2baab8, Func Offset: 0x9c8
	// Line 414, Address: 0x2baacc, Func Offset: 0x9dc
	// Line 416, Address: 0x2baaec, Func Offset: 0x9fc
	// Line 417, Address: 0x2bab1c, Func Offset: 0xa2c
	// Line 418, Address: 0x2bab28, Func Offset: 0xa38
	// Line 419, Address: 0x2bab38, Func Offset: 0xa48
	// Line 421, Address: 0x2bab40, Func Offset: 0xa50
	// Line 422, Address: 0x2bab48, Func Offset: 0xa58
	// Line 425, Address: 0x2bab50, Func Offset: 0xa60
	// Line 427, Address: 0x2bab58, Func Offset: 0xa68
	// Line 435, Address: 0x2bab68, Func Offset: 0xa78
	// Line 438, Address: 0x2baba8, Func Offset: 0xab8
	// Line 439, Address: 0x2babb8, Func Offset: 0xac8
	// Line 440, Address: 0x2babc0, Func Offset: 0xad0
	// Line 441, Address: 0x2babd0, Func Offset: 0xae0
	// Line 443, Address: 0x2babd8, Func Offset: 0xae8
	// Line 444, Address: 0x2babf4, Func Offset: 0xb04
	// Line 443, Address: 0x2babf8, Func Offset: 0xb08
	// Line 444, Address: 0x2bac04, Func Offset: 0xb14
	// Line 449, Address: 0x2bac10, Func Offset: 0xb20
	// Line 450, Address: 0x2bac28, Func Offset: 0xb38
	// Line 452, Address: 0x2bac30, Func Offset: 0xb40
	// Line 453, Address: 0x2bac38, Func Offset: 0xb48
	// Line 454, Address: 0x2bac50, Func Offset: 0xb60
	// Line 455, Address: 0x2bac7c, Func Offset: 0xb8c
	// Line 456, Address: 0x2bac80, Func Offset: 0xb90
	// Line 455, Address: 0x2bac84, Func Offset: 0xb94
	// Line 456, Address: 0x2bac88, Func Offset: 0xb98
	// Line 458, Address: 0x2bac90, Func Offset: 0xba0
	// Line 459, Address: 0x2bacbc, Func Offset: 0xbcc
	// Line 460, Address: 0x2bacc0, Func Offset: 0xbd0
	// Line 459, Address: 0x2bacc4, Func Offset: 0xbd4
	// Line 460, Address: 0x2bacc8, Func Offset: 0xbd8
	// Line 462, Address: 0x2bacd0, Func Offset: 0xbe0
	// Line 463, Address: 0x2bacf0, Func Offset: 0xc00
	// Line 468, Address: 0x2bacfc, Func Offset: 0xc0c
	// Line 469, Address: 0x2bad0c, Func Offset: 0xc1c
	// Line 470, Address: 0x2bad1c, Func Offset: 0xc2c
	// Line 474, Address: 0x2bad28, Func Offset: 0xc38
	// Line 470, Address: 0x2bad2c, Func Offset: 0xc3c
	// Line 474, Address: 0x2bad34, Func Offset: 0xc44
	// Line 475, Address: 0x2bad3c, Func Offset: 0xc4c
	// Line 476, Address: 0x2bad44, Func Offset: 0xc54
	// Line 477, Address: 0x2bad50, Func Offset: 0xc60
	// Line 478, Address: 0x2bad68, Func Offset: 0xc78
	// Line 480, Address: 0x2bad78, Func Offset: 0xc88
	// Line 482, Address: 0x2bad88, Func Offset: 0xc98
	// Line 486, Address: 0x2bad94, Func Offset: 0xca4
	// Line 488, Address: 0x2bad9c, Func Offset: 0xcac
	// Line 489, Address: 0x2badac, Func Offset: 0xcbc
	// Line 491, Address: 0x2badb4, Func Offset: 0xcc4
	// Line 492, Address: 0x2badbc, Func Offset: 0xccc
	// Line 499, Address: 0x2badc4, Func Offset: 0xcd4
	// Line 500, Address: 0x2badc8, Func Offset: 0xcd8
	// Line 499, Address: 0x2badd0, Func Offset: 0xce0
	// Line 500, Address: 0x2badd8, Func Offset: 0xce8
	// Line 501, Address: 0x2bade8, Func Offset: 0xcf8
	// Line 502, Address: 0x2bae18, Func Offset: 0xd28
	// Line 503, Address: 0x2bae24, Func Offset: 0xd34
	// Line 504, Address: 0x2bae3c, Func Offset: 0xd4c
	// Line 505, Address: 0x2bae64, Func Offset: 0xd74
	// Line 506, Address: 0x2bae70, Func Offset: 0xd80
	// Line 507, Address: 0x2bae8c, Func Offset: 0xd9c
	// Line 508, Address: 0x2bae90, Func Offset: 0xda0
	// Line 507, Address: 0x2bae94, Func Offset: 0xda4
	// Line 508, Address: 0x2bae9c, Func Offset: 0xdac
	// Line 509, Address: 0x2baea8, Func Offset: 0xdb8
	// Line 510, Address: 0x2baeb4, Func Offset: 0xdc4
	// Line 511, Address: 0x2baeb8, Func Offset: 0xdc8
	// Line 509, Address: 0x2baebc, Func Offset: 0xdcc
	// Line 510, Address: 0x2baec0, Func Offset: 0xdd0
	// Line 512, Address: 0x2baec8, Func Offset: 0xdd8
	// Line 510, Address: 0x2baecc, Func Offset: 0xddc
	// Line 511, Address: 0x2baed0, Func Offset: 0xde0
	// Line 512, Address: 0x2baedc, Func Offset: 0xdec
	// Line 513, Address: 0x2baee8, Func Offset: 0xdf8
	// Line 514, Address: 0x2baef4, Func Offset: 0xe04
	// Line 515, Address: 0x2baf04, Func Offset: 0xe14
	// Line 518, Address: 0x2baf14, Func Offset: 0xe24
	// Line 519, Address: 0x2baf38, Func Offset: 0xe48
	// Line 520, Address: 0x2baf58, Func Offset: 0xe68
	// Line 521, Address: 0x2baf64, Func Offset: 0xe74
	// Line 522, Address: 0x2baf6c, Func Offset: 0xe7c
	// Line 521, Address: 0x2baf70, Func Offset: 0xe80
	// Line 522, Address: 0x2baf7c, Func Offset: 0xe8c
	// Line 523, Address: 0x2baf90, Func Offset: 0xea0
	// Line 524, Address: 0x2baf9c, Func Offset: 0xeac
	// Line 525, Address: 0x2bafa8, Func Offset: 0xeb8
	// Line 524, Address: 0x2bafac, Func Offset: 0xebc
	// Line 525, Address: 0x2bafb4, Func Offset: 0xec4
	// Line 530, Address: 0x2bafbc, Func Offset: 0xecc
	// Line 531, Address: 0x2bafc8, Func Offset: 0xed8
	// Line 532, Address: 0x2bafd8, Func Offset: 0xee8
	// Line 536, Address: 0x2bafe0, Func Offset: 0xef0
	// Func End, Address: 0x2bb020, Func Offset: 0xf30
}

// 
// Start address: 0x2bb020
void bhExitGameOver()
{
	// Line 542, Address: 0x2bb020, Func Offset: 0
	// Line 587, Address: 0x2bb028, Func Offset: 0x8
	// Line 588, Address: 0x2bb040, Func Offset: 0x20
	// Line 589, Address: 0x2bb048, Func Offset: 0x28
	// Line 591, Address: 0x2bb050, Func Offset: 0x30
	// Line 592, Address: 0x2bb058, Func Offset: 0x38
	// Line 595, Address: 0x2bb060, Func Offset: 0x40
	// Func End, Address: 0x2bb06c, Func Offset: 0x4c
}

// 
// Start address: 0x2bb070
void bhDrawGameOver()
{
	int y;
	int x;
	_anon15 uv[32];
	_anon15 cl[32];
	_anon27 pt[32];
	_anon32 p3c;
	_anon0* gv;
	// Line 602, Address: 0x2bb070, Func Offset: 0
	// Line 603, Address: 0x2bb084, Func Offset: 0x14
	// Line 609, Address: 0x2bb098, Func Offset: 0x28
	// Line 610, Address: 0x2bb0a0, Func Offset: 0x30
	// Line 611, Address: 0x2bb0ac, Func Offset: 0x3c
	// Line 612, Address: 0x2bb0b8, Func Offset: 0x48
	// Line 613, Address: 0x2bb0d0, Func Offset: 0x60
	// Line 614, Address: 0x2bb0d8, Func Offset: 0x68
	// Line 615, Address: 0x2bb0e0, Func Offset: 0x70
	// Line 616, Address: 0x2bb0e8, Func Offset: 0x78
	// Line 617, Address: 0x2bb0f0, Func Offset: 0x80
	// Line 618, Address: 0x2bb0f8, Func Offset: 0x88
	// Line 619, Address: 0x2bb100, Func Offset: 0x90
	// Line 621, Address: 0x2bb120, Func Offset: 0xb0
	// Line 624, Address: 0x2bb134, Func Offset: 0xc4
	// Line 628, Address: 0x2bb13c, Func Offset: 0xcc
	// Line 621, Address: 0x2bb144, Func Offset: 0xd4
	// Line 622, Address: 0x2bb148, Func Offset: 0xd8
	// Line 628, Address: 0x2bb14c, Func Offset: 0xdc
	// Line 631, Address: 0x2bb154, Func Offset: 0xe4
	// Line 622, Address: 0x2bb15c, Func Offset: 0xec
	// Line 623, Address: 0x2bb160, Func Offset: 0xf0
	// Line 634, Address: 0x2bb164, Func Offset: 0xf4
	// Line 633, Address: 0x2bb16c, Func Offset: 0xfc
	// Line 623, Address: 0x2bb170, Func Offset: 0x100
	// Line 624, Address: 0x2bb174, Func Offset: 0x104
	// Line 633, Address: 0x2bb178, Func Offset: 0x108
	// Line 624, Address: 0x2bb17c, Func Offset: 0x10c
	// Line 625, Address: 0x2bb180, Func Offset: 0x110
	// Line 626, Address: 0x2bb188, Func Offset: 0x118
	// Line 628, Address: 0x2bb190, Func Offset: 0x120
	// Line 629, Address: 0x2bb198, Func Offset: 0x128
	// Line 630, Address: 0x2bb1a0, Func Offset: 0x130
	// Line 631, Address: 0x2bb1a8, Func Offset: 0x138
	// Line 633, Address: 0x2bb1ac, Func Offset: 0x13c
	// Line 631, Address: 0x2bb1b0, Func Offset: 0x140
	// Line 632, Address: 0x2bb1b4, Func Offset: 0x144
	// Line 633, Address: 0x2bb1bc, Func Offset: 0x14c
	// Line 634, Address: 0x2bb1c8, Func Offset: 0x158
	// Line 635, Address: 0x2bb1d0, Func Offset: 0x160
	// Line 639, Address: 0x2bb1e4, Func Offset: 0x174
	// Line 640, Address: 0x2bb1f4, Func Offset: 0x184
	// Func End, Address: 0x2bb20c, Func Offset: 0x19c
}

