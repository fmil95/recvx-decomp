typedef struct npobj;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct BH_PWORK;
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

typedef void(*type_11)(BH_PWORK*);
typedef void(*type_65)(BH_PWORK*);
typedef void(*type_67)(BH_PWORK*);
typedef void(*type_78)(BH_PWORK*);
typedef void(*type_86)(BH_PWORK*);
typedef void(*type_88)(void*);
typedef void(*type_121)(BH_PWORK*);

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
typedef _anon1* type_12[1300];
typedef void(*type_13)(BH_PWORK*)[1];
typedef char type_14[32];
typedef _anon0* type_15[512];
typedef _anon1* type_16[200];
typedef short type_17[32];
typedef _anon16 type_18[1];
typedef _anon0* type_19[128];
typedef unsigned int type_20[1];
typedef int type_21[16];
typedef _anon6 type_22[256];
typedef _anon1* type_23[8];
typedef int* type_24[16];
typedef _anon0* type_25[128];
typedef npobj* type_26[16];
typedef _anon0* type_27[128];
typedef int type_28[4];
typedef _anon1* type_29[16];
typedef unsigned int type_30[4];
typedef _anon10 type_31[16];
typedef _anon0* type_32[512];
typedef char type_33[256];
typedef float type_34[4];
typedef float type_35[4];
typedef float type_36[4];
typedef _anon4* type_37[128];
typedef unsigned char type_38[64];
typedef char type_39[5];
typedef float type_40[16];
typedef float type_41[3];
typedef unsigned short type_42[3];
typedef char type_43[8];
typedef void* type_44[2];
typedef BH_PWORK type_45[0];
typedef _anon1* type_46[256];
typedef _anon0 type_47[0];
typedef int type_48[4];
typedef unsigned char* type_49[256];
typedef unsigned int type_50[2];
typedef short type_51[256];
typedef unsigned int type_52[3];
typedef _anon22 type_53[4];
typedef unsigned int type_54[3][3];
typedef float type_55[3];
typedef short type_56[256];
typedef int type_57[3];
typedef int type_58[8];
typedef float type_59[3];
typedef _anon1* type_60[256];
typedef _anon8 type_61[256];
typedef char type_62[6];
typedef char type_63[6][1];
typedef _anon16 type_64[450];
typedef void(*type_66)(BH_PWORK*)[2];
typedef _anon24 type_68[16];
typedef void(*type_69)(BH_PWORK*)[7];
typedef short type_70[256];
typedef char type_71[3];
typedef int type_72[64];
typedef _anon10 type_73[450];
typedef float type_74[5];
typedef int type_75[5];
typedef _anon28 type_76[4];
typedef _anon2 type_77[4];
typedef int type_79[450];
typedef void(*type_80)(BH_PWORK*)[2];
typedef unsigned int type_81[8];
typedef unsigned char type_82[450];
typedef _anon5 type_83[5];
typedef char type_84[16];
typedef char type_85[4];
typedef void(*type_87)(BH_PWORK*)[6];
typedef unsigned int type_89[32];
typedef unsigned int type_90[16];
typedef _anon29 type_91[64];
typedef _anon17 type_92[5];
typedef unsigned int type_93[16];
typedef _anon29 type_94[64];
typedef unsigned int type_95[32];
typedef _anon29 type_96[64];
typedef unsigned int type_97[16];
typedef unsigned int type_98[3];
typedef BH_PWORK* type_99[16];
typedef unsigned int type_100[8];
typedef unsigned int type_101[1];
typedef unsigned int type_102[384];
typedef unsigned int type_103[2];
typedef unsigned char type_104[2];
typedef unsigned int type_105[4];
typedef int* type_106[16];
typedef char type_107[32];
typedef npobj* type_108[16];
typedef char type_109[64];
typedef _anon1* type_110[16];
typedef char type_111[4];
typedef _anon10 type_112[16];
typedef short type_113[4];
typedef char type_114[3];
typedef unsigned char type_115[4];
typedef _anon26 type_116[16];
typedef unsigned int type_117[32];
typedef _anon5 type_118[32];
typedef _anon0* type_119[512];
typedef _anon0* type_120[128];
typedef void(*type_122)(BH_PWORK*)[9];
typedef _anon0* type_123[512];
typedef unsigned char type_124[64];
typedef int type_125[5];
typedef _anon0* type_126[512];

struct npobj
{
	unsigned int evalflags;
	_anon23* model;
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
	_anon34 cspr;
	int pn;
	_anon28* pvp;
	_anon2* tvp;
	_anon28 pv[4];
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
	_anon16* textures;
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
	float key[3];
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
	_anon35 watr;
	_anon17* cpcl;
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

struct _anon4
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon15* md2P;
	unsigned short* atrP;
};

struct _anon5
{
	float x;
	float y;
	float z;
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
	unsigned short key[3];
};

struct _anon10
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon20* owP;
};

struct _anon11
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
	_anon32* info;
};

struct _anon12
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
	_anon5 ply_pos;
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
	_anon11* p1per;
	_anon11* p2per;
	_anon11* kbper;
	_anon11* msper;
	_anon11 ms_per;
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
	_anon16 ef_tex[450];
	_anon1 ef_tlist;
	_anon30 ef;
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
	_anon14 ren_info;
	_anon16 ren_tex[1];
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
	_anon31 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon18* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon22 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon24 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon29* pl_htp;
	int costume;
	_anon5 hd_pos;
	_anon5 apos;
	_anon29* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon29 mwalp[64];
	_anon29 metcp[64];
	_anon29 mflrp[64];
	int dla_n;
	_anon29* htp;
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
	_anon13 door;
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
	_anon5 ufo_pos;
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
	_anon26 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon5 ghtp[32];
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

struct _anon13
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

struct _anon14
{
	void* texaddr;
	_anon7 texsurface;
};

struct _anon15
{
	void* p[2];
};

struct _anon16
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon17
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon18
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
	_anon21* light;
};

struct _anon19
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon20
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon21
{
	float mtrx[16];
	_anon5 pnt;
	_anon5 vctr;
	int stat;
	int reserve;
	_anon27 ltcal;
	_anon33 attr;
};

struct _anon22
{
	_anon5 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon23
{
	int* vlist;
	short* plist;
	_anon5 center;
	float r;
};

struct _anon24
{
	float x;
	float y;
};

struct _anon25
{
	_anon5 off_pos;
	int srd_dir;
	float srd_pos;
	float bld_spd;
	float srt_spd[5];
	int srt_dir[5];
};

struct _anon26
{
	_anon5 c1;
	_anon5 c2;
	float r1;
	float r2;
};

struct _anon27
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
	_anon5 lpnt;
	_anon5 lvctr;
	_anon5 lmvctr;
	_anon19 atten;
	_anon19 amb;
	_anon19 dif;
	_anon19 spc;
	_anon19 mamb;
	_anon19 mdif;
	_anon19 mspc;
};

struct _anon28
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon29
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

struct _anon30
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

struct _anon31
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon32
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

struct _anon33
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
	_anon19 argb;
};

struct _anon34
{
	_anon5 c;
	float r;
};

struct _anon35
{
	_anon5 c1;
	_anon5 c2;
	float r;
};

int ENE07_HITPOINT[16];
char junction_tree[6][1];
char SdwTab[3];
char AtkPos[5];
_anon5 AtkOffset[5];
int AtkAngle[5];
_anon25 BloodParam;
_anon17 CapColTab[5];
void(*bhEne07_Mode0)(BH_PWORK*)[6];
void(*bhEne07_BrainType)(BH_PWORK*)[2];
void(*bhEne07_MoveMode2)(BH_PWORK*)[9];
void(*bhEne07_NageMode2)(BH_PWORK*)[2];
void(*bhEne07_DamageMode2)(BH_PWORK*)[1];
void(*bhEne07_DeadMode2)(BH_PWORK*)[7];
BH_PWORK* plp;
_anon12* sys;
_anon0 eff[0];
BH_PWORK ene[0];

void bhEne07(BH_PWORK* epw);
void bhEne07_Init(BH_PWORK* epw);
void bhEne07_Brain(BH_PWORK* epw);
void bhEne07_BR00(BH_PWORK* epw);
void bhEne07_BR01(BH_PWORK* epw);
void bhEne07_Move(BH_PWORK* epw);
void bhEne07_MV00(BH_PWORK* epw);
void bhEne07_MV01(BH_PWORK* epw);
void bhEne07_MV02(BH_PWORK* epw);
void bhEne07_MV03(BH_PWORK* epw);
void bhEne07_MV04(BH_PWORK* epw);
void bhEne07_MV05(BH_PWORK* epw);
void bhEne07_MV06();
void bhEne07_MV07();
void bhEne07_MV08(BH_PWORK* epw);
void bhEne07_Nage(BH_PWORK* epw);
void bhEne07_NG00(BH_PWORK* epw);
void bhEne07_NG01(BH_PWORK* epw);
void bhEne07_Damage(BH_PWORK* epw);
void bhEne07_Die(BH_PWORK* epw);
void bhEne07_DD00(BH_PWORK* epw);
void bhEne07_DD01(BH_PWORK* epw);
void bhEne07_DD02(BH_PWORK* epw);
void bhEne07_DD03(BH_PWORK* epw);
void bhEne07_DD04(BH_PWORK* epw);
void bhEne07_DD05(BH_PWORK* epw);
void bhEne07_DD06(BH_PWORK* epw);
void bhEne07_SearchPlayer(BH_PWORK* epw);
void bhEne07_CollisionWalls(BH_PWORK* epw);
void bhEne07_FloorCollision(BH_PWORK* epw);
int bhEne07_CheckLeaningWall();
int bhEne07_CheckHangingWall(BH_PWORK* epw);
int bhEne07_AvoidWall(BH_PWORK* epw, int dir);
void bhEne07_PlayerBloodEffect(BH_PWORK* epw, unsigned char size);
void bhEne07_PlayerControl(BH_PWORK* epw);
int bhEne07_ObjEdge(BH_PWORK* epw);
void bhEne07_CalcAtariOffset(BH_PWORK* epw, _anon5* ofp);

// 
// Start address: 0x1bfe80
void bhEne07(BH_PWORK* epw)
{
	// Line 304, Address: 0x1bfe80, Func Offset: 0
	// Line 306, Address: 0x1bfe90, Func Offset: 0x10
	// Line 309, Address: 0x1bfeb0, Func Offset: 0x30
	// Line 312, Address: 0x1bfec4, Func Offset: 0x44
	// Line 316, Address: 0x1bfed4, Func Offset: 0x54
	// Line 312, Address: 0x1bfed8, Func Offset: 0x58
	// Line 313, Address: 0x1bfeec, Func Offset: 0x6c
	// Line 316, Address: 0x1bff08, Func Offset: 0x88
	// Line 317, Address: 0x1bff10, Func Offset: 0x90
	// Line 318, Address: 0x1bff18, Func Offset: 0x98
	// Line 319, Address: 0x1bff20, Func Offset: 0xa0
	// Line 320, Address: 0x1bff28, Func Offset: 0xa8
	// Line 323, Address: 0x1bff30, Func Offset: 0xb0
	// Line 326, Address: 0x1bff38, Func Offset: 0xb8
	// Line 329, Address: 0x1bff50, Func Offset: 0xd0
	// Line 330, Address: 0x1bff74, Func Offset: 0xf4
	// Line 331, Address: 0x1bff8c, Func Offset: 0x10c
	// Line 333, Address: 0x1bff94, Func Offset: 0x114
	// Line 335, Address: 0x1bffb4, Func Offset: 0x134
	// Func End, Address: 0x1bffc4, Func Offset: 0x144
}

// 
// Start address: 0x1bffd0
void bhEne07_Init(BH_PWORK* epw)
{
	_anon5 p;
	int sdw;
	BH_PWORK* ep;
	int i;
	// Line 345, Address: 0x1bffd0, Func Offset: 0
	// Line 350, Address: 0x1bffe0, Func Offset: 0x10
	// Line 351, Address: 0x1bffe4, Func Offset: 0x14
	// Line 355, Address: 0x1bffec, Func Offset: 0x1c
	// Line 357, Address: 0x1bfff0, Func Offset: 0x20
	// Line 350, Address: 0x1bfff4, Func Offset: 0x24
	// Line 351, Address: 0x1bfffc, Func Offset: 0x2c
	// Line 352, Address: 0x1c000c, Func Offset: 0x3c
	// Line 355, Address: 0x1c0018, Func Offset: 0x48
	// Line 357, Address: 0x1c002c, Func Offset: 0x5c
	// Line 359, Address: 0x1c0030, Func Offset: 0x60
	// Line 360, Address: 0x1c0080, Func Offset: 0xb0
	// Line 361, Address: 0x1c0084, Func Offset: 0xb4
	// Line 359, Address: 0x1c0088, Func Offset: 0xb8
	// Line 360, Address: 0x1c008c, Func Offset: 0xbc
	// Line 361, Address: 0x1c0090, Func Offset: 0xc0
	// Line 363, Address: 0x1c0094, Func Offset: 0xc4
	// Line 365, Address: 0x1c00a4, Func Offset: 0xd4
	// Line 366, Address: 0x1c00ac, Func Offset: 0xdc
	// Line 367, Address: 0x1c00b0, Func Offset: 0xe0
	// Line 368, Address: 0x1c00b8, Func Offset: 0xe8
	// Line 371, Address: 0x1c00bc, Func Offset: 0xec
	// Line 372, Address: 0x1c00c4, Func Offset: 0xf4
	// Line 373, Address: 0x1c00c8, Func Offset: 0xf8
	// Line 374, Address: 0x1c00cc, Func Offset: 0xfc
	// Line 375, Address: 0x1c00d0, Func Offset: 0x100
	// Line 377, Address: 0x1c00d4, Func Offset: 0x104
	// Line 379, Address: 0x1c00dc, Func Offset: 0x10c
	// Line 380, Address: 0x1c00e4, Func Offset: 0x114
	// Line 381, Address: 0x1c00e8, Func Offset: 0x118
	// Line 382, Address: 0x1c00ec, Func Offset: 0x11c
	// Line 385, Address: 0x1c00f0, Func Offset: 0x120
	// Line 387, Address: 0x1c00f8, Func Offset: 0x128
	// Line 386, Address: 0x1c00fc, Func Offset: 0x12c
	// Line 387, Address: 0x1c0100, Func Offset: 0x130
	// Line 388, Address: 0x1c0104, Func Offset: 0x134
	// Line 389, Address: 0x1c0108, Func Offset: 0x138
	// Line 390, Address: 0x1c010c, Func Offset: 0x13c
	// Line 394, Address: 0x1c0110, Func Offset: 0x140
	// Line 395, Address: 0x1c011c, Func Offset: 0x14c
	// Line 398, Address: 0x1c0128, Func Offset: 0x158
	// Line 395, Address: 0x1c0130, Func Offset: 0x160
	// Line 399, Address: 0x1c0134, Func Offset: 0x164
	// Line 400, Address: 0x1c0154, Func Offset: 0x184
	// Line 401, Address: 0x1c0170, Func Offset: 0x1a0
	// Line 403, Address: 0x1c017c, Func Offset: 0x1ac
	// Line 404, Address: 0x1c0184, Func Offset: 0x1b4
	// Line 406, Address: 0x1c0190, Func Offset: 0x1c0
	// Line 408, Address: 0x1c0198, Func Offset: 0x1c8
	// Line 409, Address: 0x1c01ac, Func Offset: 0x1dc
	// Line 412, Address: 0x1c01b0, Func Offset: 0x1e0
	// Line 415, Address: 0x1c01b4, Func Offset: 0x1e4
	// Line 412, Address: 0x1c01b8, Func Offset: 0x1e8
	// Line 413, Address: 0x1c01bc, Func Offset: 0x1ec
	// Line 414, Address: 0x1c01c4, Func Offset: 0x1f4
	// Line 415, Address: 0x1c01cc, Func Offset: 0x1fc
	// Line 418, Address: 0x1c01e8, Func Offset: 0x218
	// Line 420, Address: 0x1c01f8, Func Offset: 0x228
	// Line 421, Address: 0x1c0224, Func Offset: 0x254
	// Line 422, Address: 0x1c024c, Func Offset: 0x27c
	// Line 424, Address: 0x1c0258, Func Offset: 0x288
	// Line 427, Address: 0x1c0260, Func Offset: 0x290
	// Line 428, Address: 0x1c0264, Func Offset: 0x294
	// Line 424, Address: 0x1c0268, Func Offset: 0x298
	// Line 427, Address: 0x1c0270, Func Offset: 0x2a0
	// Line 429, Address: 0x1c0274, Func Offset: 0x2a4
	// Line 428, Address: 0x1c0278, Func Offset: 0x2a8
	// Line 430, Address: 0x1c027c, Func Offset: 0x2ac
	// Line 429, Address: 0x1c0280, Func Offset: 0x2b0
	// Line 430, Address: 0x1c0284, Func Offset: 0x2b4
	// Line 431, Address: 0x1c0288, Func Offset: 0x2b8
	// Line 432, Address: 0x1c0290, Func Offset: 0x2c0
	// Line 435, Address: 0x1c0298, Func Offset: 0x2c8
	// Line 436, Address: 0x1c02a4, Func Offset: 0x2d4
	// Line 438, Address: 0x1c02ac, Func Offset: 0x2dc
	// Line 439, Address: 0x1c02f0, Func Offset: 0x320
	// Line 438, Address: 0x1c02f8, Func Offset: 0x328
	// Line 439, Address: 0x1c02fc, Func Offset: 0x32c
	// Line 440, Address: 0x1c0304, Func Offset: 0x334
	// Line 441, Address: 0x1c0314, Func Offset: 0x344
	// Line 442, Address: 0x1c0318, Func Offset: 0x348
	// Line 443, Address: 0x1c0324, Func Offset: 0x354
	// Line 444, Address: 0x1c0338, Func Offset: 0x368
	// Line 445, Address: 0x1c033c, Func Offset: 0x36c
	// Line 446, Address: 0x1c0348, Func Offset: 0x378
	// Line 450, Address: 0x1c0350, Func Offset: 0x380
	// Line 451, Address: 0x1c0354, Func Offset: 0x384
	// Line 450, Address: 0x1c0364, Func Offset: 0x394
	// Line 451, Address: 0x1c0368, Func Offset: 0x398
	// Line 454, Address: 0x1c036c, Func Offset: 0x39c
	// Line 451, Address: 0x1c0374, Func Offset: 0x3a4
	// Line 452, Address: 0x1c037c, Func Offset: 0x3ac
	// Line 454, Address: 0x1c0380, Func Offset: 0x3b0
	// Line 455, Address: 0x1c0390, Func Offset: 0x3c0
	// Line 456, Address: 0x1c0398, Func Offset: 0x3c8
	// Line 457, Address: 0x1c03a0, Func Offset: 0x3d0
	// Line 458, Address: 0x1c03a8, Func Offset: 0x3d8
	// Line 460, Address: 0x1c03b0, Func Offset: 0x3e0
	// Line 463, Address: 0x1c03c0, Func Offset: 0x3f0
	// Line 464, Address: 0x1c03d0, Func Offset: 0x400
	// Line 468, Address: 0x1c03d4, Func Offset: 0x404
	// Line 471, Address: 0x1c03e0, Func Offset: 0x410
	// Line 472, Address: 0x1c03ec, Func Offset: 0x41c
	// Line 473, Address: 0x1c03f8, Func Offset: 0x428
	// Func End, Address: 0x1c040c, Func Offset: 0x43c
}

// 
// Start address: 0x1c0410
void bhEne07_Brain(BH_PWORK* epw)
{
	// Line 484, Address: 0x1c0410, Func Offset: 0
	// Func End, Address: 0x1c0430, Func Offset: 0x20
}

// 
// Start address: 0x1c0430
void bhEne07_BR00(BH_PWORK* epw)
{
	// Line 495, Address: 0x1c0430, Func Offset: 0
	// Line 497, Address: 0x1c043c, Func Offset: 0xc
	// Line 500, Address: 0x1c0444, Func Offset: 0x14
	// Line 501, Address: 0x1c047c, Func Offset: 0x4c
	// Line 502, Address: 0x1c0490, Func Offset: 0x60
	// Line 503, Address: 0x1c0494, Func Offset: 0x64
	// Line 505, Address: 0x1c0498, Func Offset: 0x68
	// Line 508, Address: 0x1c04a0, Func Offset: 0x70
	// Line 509, Address: 0x1c04b0, Func Offset: 0x80
	// Line 514, Address: 0x1c04fc, Func Offset: 0xcc
	// Line 515, Address: 0x1c0514, Func Offset: 0xe4
	// Line 519, Address: 0x1c053c, Func Offset: 0x10c
	// Line 520, Address: 0x1c055c, Func Offset: 0x12c
	// Line 521, Address: 0x1c0570, Func Offset: 0x140
	// Line 522, Address: 0x1c0574, Func Offset: 0x144
	// Line 524, Address: 0x1c0578, Func Offset: 0x148
	// Line 527, Address: 0x1c0580, Func Offset: 0x150
	// Line 528, Address: 0x1c0590, Func Offset: 0x160
	// Line 536, Address: 0x1c05dc, Func Offset: 0x1ac
	// Line 537, Address: 0x1c05f4, Func Offset: 0x1c4
	// Line 538, Address: 0x1c0608, Func Offset: 0x1d8
	// Line 539, Address: 0x1c060c, Func Offset: 0x1dc
	// Line 541, Address: 0x1c0610, Func Offset: 0x1e0
	// Line 544, Address: 0x1c0618, Func Offset: 0x1e8
	// Line 553, Address: 0x1c0660, Func Offset: 0x230
	// Line 560, Address: 0x1c0678, Func Offset: 0x248
	// Line 562, Address: 0x1c06ac, Func Offset: 0x27c
	// Line 565, Address: 0x1c06b4, Func Offset: 0x284
	// Line 567, Address: 0x1c06c8, Func Offset: 0x298
	// Line 572, Address: 0x1c0744, Func Offset: 0x314
	// Line 573, Address: 0x1c076c, Func Offset: 0x33c
	// Line 575, Address: 0x1c07c0, Func Offset: 0x390
	// Line 577, Address: 0x1c07c8, Func Offset: 0x398
	// Line 579, Address: 0x1c07cc, Func Offset: 0x39c
	// Line 575, Address: 0x1c07d0, Func Offset: 0x3a0
	// Line 585, Address: 0x1c07dc, Func Offset: 0x3ac
	// Line 582, Address: 0x1c07e0, Func Offset: 0x3b0
	// Line 585, Address: 0x1c07e4, Func Offset: 0x3b4
	// Line 575, Address: 0x1c07e8, Func Offset: 0x3b8
	// Line 577, Address: 0x1c07ec, Func Offset: 0x3bc
	// Line 578, Address: 0x1c07f0, Func Offset: 0x3c0
	// Line 579, Address: 0x1c07f4, Func Offset: 0x3c4
	// Line 580, Address: 0x1c07f8, Func Offset: 0x3c8
	// Line 582, Address: 0x1c07fc, Func Offset: 0x3cc
	// Line 585, Address: 0x1c0800, Func Offset: 0x3d0
	// Line 582, Address: 0x1c0804, Func Offset: 0x3d4
	// Line 585, Address: 0x1c0808, Func Offset: 0x3d8
	// Line 586, Address: 0x1c0810, Func Offset: 0x3e0
	// Line 585, Address: 0x1c0814, Func Offset: 0x3e4
	// Line 586, Address: 0x1c081c, Func Offset: 0x3ec
	// Line 588, Address: 0x1c0828, Func Offset: 0x3f8
	// Line 593, Address: 0x1c0830, Func Offset: 0x400
	// Line 594, Address: 0x1c0844, Func Offset: 0x414
	// Line 596, Address: 0x1c084c, Func Offset: 0x41c
	// Line 599, Address: 0x1c0850, Func Offset: 0x420
	// Line 596, Address: 0x1c0858, Func Offset: 0x428
	// Line 599, Address: 0x1c0868, Func Offset: 0x438
	// Line 600, Address: 0x1c0874, Func Offset: 0x444
	// Line 599, Address: 0x1c0878, Func Offset: 0x448
	// Line 600, Address: 0x1c0880, Func Offset: 0x450
	// Line 603, Address: 0x1c0890, Func Offset: 0x460
	// Line 605, Address: 0x1c0898, Func Offset: 0x468
	// Line 603, Address: 0x1c089c, Func Offset: 0x46c
	// Line 605, Address: 0x1c08a4, Func Offset: 0x474
	// Line 606, Address: 0x1c08a8, Func Offset: 0x478
	// Line 607, Address: 0x1c08ac, Func Offset: 0x47c
	// Line 608, Address: 0x1c08b0, Func Offset: 0x480
	// Line 610, Address: 0x1c08b4, Func Offset: 0x484
	// Line 611, Address: 0x1c08c0, Func Offset: 0x490
	// Line 615, Address: 0x1c08c8, Func Offset: 0x498
	// Line 616, Address: 0x1c08cc, Func Offset: 0x49c
	// Line 617, Address: 0x1c08d0, Func Offset: 0x4a0
	// Line 619, Address: 0x1c08d4, Func Offset: 0x4a4
	// Func End, Address: 0x1c08e4, Func Offset: 0x4b4
}

// 
// Start address: 0x1c08f0
void bhEne07_BR01(BH_PWORK* epw)
{
	// Line 629, Address: 0x1c08f0, Func Offset: 0
	// Line 631, Address: 0x1c08fc, Func Offset: 0xc
	// Line 632, Address: 0x1c0914, Func Offset: 0x24
	// Line 633, Address: 0x1c0928, Func Offset: 0x38
	// Line 635, Address: 0x1c092c, Func Offset: 0x3c
	// Line 634, Address: 0x1c0930, Func Offset: 0x40
	// Line 635, Address: 0x1c0934, Func Offset: 0x44
	// Line 636, Address: 0x1c0938, Func Offset: 0x48
	// Line 639, Address: 0x1c093c, Func Offset: 0x4c
	// Line 641, Address: 0x1c094c, Func Offset: 0x5c
	// Line 644, Address: 0x1c0954, Func Offset: 0x64
	// Line 647, Address: 0x1c099c, Func Offset: 0xac
	// Func End, Address: 0x1c09ac, Func Offset: 0xbc
}

// 
// Start address: 0x1c09b0
void bhEne07_Move(BH_PWORK* epw)
{
	// Line 657, Address: 0x1c09b0, Func Offset: 0
	// Line 659, Address: 0x1c09c0, Func Offset: 0x10
	// Line 662, Address: 0x1c09e0, Func Offset: 0x30
	// Line 664, Address: 0x1c09fc, Func Offset: 0x4c
	// Line 665, Address: 0x1c0a08, Func Offset: 0x58
	// Line 666, Address: 0x1c0a10, Func Offset: 0x60
	// Line 670, Address: 0x1c0a18, Func Offset: 0x68
	// Line 671, Address: 0x1c0a28, Func Offset: 0x78
	// Line 672, Address: 0x1c0a30, Func Offset: 0x80
	// Func End, Address: 0x1c0a40, Func Offset: 0x90
}

// 
// Start address: 0x1c0a40
void bhEne07_MV00(BH_PWORK* epw)
{
	// Line 682, Address: 0x1c0a40, Func Offset: 0
	// Line 683, Address: 0x1c0a54, Func Offset: 0x14
	// Line 686, Address: 0x1c0a80, Func Offset: 0x40
	// Line 687, Address: 0x1c0a88, Func Offset: 0x48
	// Line 688, Address: 0x1c0b14, Func Offset: 0xd4
	// Line 689, Address: 0x1c0b18, Func Offset: 0xd8
	// Line 692, Address: 0x1c0b24, Func Offset: 0xe4
	// Line 693, Address: 0x1c0b68, Func Offset: 0x128
	// Line 695, Address: 0x1c0b74, Func Offset: 0x134
	// Line 696, Address: 0x1c0b84, Func Offset: 0x144
	// Line 698, Address: 0x1c0bc8, Func Offset: 0x188
	// Line 700, Address: 0x1c0bd0, Func Offset: 0x190
	// Line 699, Address: 0x1c0bd4, Func Offset: 0x194
	// Line 700, Address: 0x1c0bd8, Func Offset: 0x198
	// Line 701, Address: 0x1c0bdc, Func Offset: 0x19c
	// Line 704, Address: 0x1c0be4, Func Offset: 0x1a4
	// Line 707, Address: 0x1c0be8, Func Offset: 0x1a8
	// Line 704, Address: 0x1c0bf0, Func Offset: 0x1b0
	// Line 707, Address: 0x1c0bf4, Func Offset: 0x1b4
	// Line 704, Address: 0x1c0bf8, Func Offset: 0x1b8
	// Line 707, Address: 0x1c0c0c, Func Offset: 0x1cc
	// Line 704, Address: 0x1c0c10, Func Offset: 0x1d0
	// Line 705, Address: 0x1c0c18, Func Offset: 0x1d8
	// Line 707, Address: 0x1c0c20, Func Offset: 0x1e0
	// Line 708, Address: 0x1c0c28, Func Offset: 0x1e8
	// Line 709, Address: 0x1c0c30, Func Offset: 0x1f0
	// Line 712, Address: 0x1c0c40, Func Offset: 0x200
	// Line 714, Address: 0x1c0c48, Func Offset: 0x208
	// Line 716, Address: 0x1c0c58, Func Offset: 0x218
	// Line 720, Address: 0x1c0c5c, Func Offset: 0x21c
	// Func End, Address: 0x1c0c70, Func Offset: 0x230
}

// 
// Start address: 0x1c0c70
void bhEne07_MV01(BH_PWORK* epw)
{
	_anon5 pos;
	// Line 730, Address: 0x1c0c70, Func Offset: 0
	// Line 731, Address: 0x1c0c7c, Func Offset: 0xc
	// Line 734, Address: 0x1c0ca8, Func Offset: 0x38
	// Line 735, Address: 0x1c0ce8, Func Offset: 0x78
	// Line 737, Address: 0x1c0cf4, Func Offset: 0x84
	// Line 739, Address: 0x1c0d04, Func Offset: 0x94
	// Line 741, Address: 0x1c0d0c, Func Offset: 0x9c
	// Line 740, Address: 0x1c0d10, Func Offset: 0xa0
	// Line 741, Address: 0x1c0d14, Func Offset: 0xa4
	// Line 742, Address: 0x1c0d18, Func Offset: 0xa8
	// Line 744, Address: 0x1c0d20, Func Offset: 0xb0
	// Line 745, Address: 0x1c0d24, Func Offset: 0xb4
	// Line 744, Address: 0x1c0d28, Func Offset: 0xb8
	// Line 745, Address: 0x1c0d2c, Func Offset: 0xbc
	// Line 751, Address: 0x1c0d30, Func Offset: 0xc0
	// Line 744, Address: 0x1c0d34, Func Offset: 0xc4
	// Line 745, Address: 0x1c0d3c, Func Offset: 0xcc
	// Line 751, Address: 0x1c0d40, Func Offset: 0xd0
	// Line 745, Address: 0x1c0d4c, Func Offset: 0xdc
	// Line 748, Address: 0x1c0d54, Func Offset: 0xe4
	// Line 749, Address: 0x1c0d78, Func Offset: 0x108
	// Line 751, Address: 0x1c0d80, Func Offset: 0x110
	// Line 753, Address: 0x1c0d88, Func Offset: 0x118
	// Line 755, Address: 0x1c0d90, Func Offset: 0x120
	// Line 759, Address: 0x1c0da0, Func Offset: 0x130
	// Line 760, Address: 0x1c0db0, Func Offset: 0x140
	// Line 775, Address: 0x1c0db4, Func Offset: 0x144
	// Line 764, Address: 0x1c0db8, Func Offset: 0x148
	// Line 767, Address: 0x1c0dbc, Func Offset: 0x14c
	// Line 768, Address: 0x1c0dc0, Func Offset: 0x150
	// Line 760, Address: 0x1c0dc4, Func Offset: 0x154
	// Line 761, Address: 0x1c0dc8, Func Offset: 0x158
	// Line 775, Address: 0x1c0dcc, Func Offset: 0x15c
	// Line 761, Address: 0x1c0dd0, Func Offset: 0x160
	// Line 762, Address: 0x1c0dd4, Func Offset: 0x164
	// Line 764, Address: 0x1c0ddc, Func Offset: 0x16c
	// Line 765, Address: 0x1c0de4, Func Offset: 0x174
	// Line 767, Address: 0x1c0dec, Func Offset: 0x17c
	// Line 768, Address: 0x1c0df0, Func Offset: 0x180
	// Line 769, Address: 0x1c0df4, Func Offset: 0x184
	// Line 771, Address: 0x1c0df8, Func Offset: 0x188
	// Line 772, Address: 0x1c0dfc, Func Offset: 0x18c
	// Line 773, Address: 0x1c0e00, Func Offset: 0x190
	// Line 775, Address: 0x1c0e04, Func Offset: 0x194
	// Line 777, Address: 0x1c0e0c, Func Offset: 0x19c
	// Line 781, Address: 0x1c0e54, Func Offset: 0x1e4
	// Func End, Address: 0x1c0e64, Func Offset: 0x1f4
}

// 
// Start address: 0x1c0e70
void bhEne07_MV02(BH_PWORK* epw)
{
	// Line 791, Address: 0x1c0e70, Func Offset: 0
	// Line 792, Address: 0x1c0e80, Func Offset: 0x10
	// Line 795, Address: 0x1c0ea0, Func Offset: 0x30
	// Line 796, Address: 0x1c0eac, Func Offset: 0x3c
	// Line 798, Address: 0x1c0eb0, Func Offset: 0x40
	// Line 797, Address: 0x1c0eb4, Func Offset: 0x44
	// Line 798, Address: 0x1c0eb8, Func Offset: 0x48
	// Line 799, Address: 0x1c0ebc, Func Offset: 0x4c
	// Line 802, Address: 0x1c0ec4, Func Offset: 0x54
	// Line 803, Address: 0x1c0ecc, Func Offset: 0x5c
	// Line 805, Address: 0x1c0ed4, Func Offset: 0x64
	// Line 802, Address: 0x1c0edc, Func Offset: 0x6c
	// Line 803, Address: 0x1c0ee4, Func Offset: 0x74
	// Line 805, Address: 0x1c0ee8, Func Offset: 0x78
	// Line 806, Address: 0x1c0ef8, Func Offset: 0x88
	// Line 807, Address: 0x1c0f38, Func Offset: 0xc8
	// Line 808, Address: 0x1c0f40, Func Offset: 0xd0
	// Line 810, Address: 0x1c0f48, Func Offset: 0xd8
	// Line 811, Address: 0x1c0fa4, Func Offset: 0x134
	// Line 815, Address: 0x1c0fe8, Func Offset: 0x178
	// Line 817, Address: 0x1c102c, Func Offset: 0x1bc
	// Line 820, Address: 0x1c1038, Func Offset: 0x1c8
	// Line 821, Address: 0x1c1078, Func Offset: 0x208
	// Line 822, Address: 0x1c10c4, Func Offset: 0x254
	// Line 823, Address: 0x1c10cc, Func Offset: 0x25c
	// Line 826, Address: 0x1c10f4, Func Offset: 0x284
	// Line 827, Address: 0x1c1100, Func Offset: 0x290
	// Line 828, Address: 0x1c1114, Func Offset: 0x2a4
	// Line 829, Address: 0x1c1124, Func Offset: 0x2b4
	// Line 830, Address: 0x1c112c, Func Offset: 0x2bc
	// Line 831, Address: 0x1c1138, Func Offset: 0x2c8
	// Line 832, Address: 0x1c113c, Func Offset: 0x2cc
	// Line 833, Address: 0x1c1144, Func Offset: 0x2d4
	// Line 838, Address: 0x1c116c, Func Offset: 0x2fc
	// Line 840, Address: 0x1c11ac, Func Offset: 0x33c
	// Line 841, Address: 0x1c11b4, Func Offset: 0x344
	// Line 842, Address: 0x1c11bc, Func Offset: 0x34c
	// Line 846, Address: 0x1c11c0, Func Offset: 0x350
	// Line 847, Address: 0x1c11f0, Func Offset: 0x380
	// Line 850, Address: 0x1c120c, Func Offset: 0x39c
	// Line 852, Address: 0x1c121c, Func Offset: 0x3ac
	// Line 853, Address: 0x1c1230, Func Offset: 0x3c0
	// Line 857, Address: 0x1c1274, Func Offset: 0x404
	// Func End, Address: 0x1c1284, Func Offset: 0x414
}

// 
// Start address: 0x1c1290
void bhEne07_MV03(BH_PWORK* epw)
{
	// Line 867, Address: 0x1c1290, Func Offset: 0
	// Line 868, Address: 0x1c12a0, Func Offset: 0x10
	// Line 871, Address: 0x1c12c0, Func Offset: 0x30
	// Line 872, Address: 0x1c12d0, Func Offset: 0x40
	// Line 874, Address: 0x1c12d4, Func Offset: 0x44
	// Line 873, Address: 0x1c12d8, Func Offset: 0x48
	// Line 874, Address: 0x1c12dc, Func Offset: 0x4c
	// Line 875, Address: 0x1c12e0, Func Offset: 0x50
	// Line 878, Address: 0x1c12e8, Func Offset: 0x58
	// Line 881, Address: 0x1c12f4, Func Offset: 0x64
	// Line 882, Address: 0x1c1338, Func Offset: 0xa8
	// Line 884, Address: 0x1c1344, Func Offset: 0xb4
	// Line 886, Address: 0x1c136c, Func Offset: 0xdc
	// Line 887, Address: 0x1c137c, Func Offset: 0xec
	// Line 888, Address: 0x1c1384, Func Offset: 0xf4
	// Line 889, Address: 0x1c138c, Func Offset: 0xfc
	// Line 893, Address: 0x1c1390, Func Offset: 0x100
	// Func End, Address: 0x1c13a0, Func Offset: 0x110
}

// 
// Start address: 0x1c13a0
void bhEne07_MV04(BH_PWORK* epw)
{
	int dir;
	// Line 903, Address: 0x1c13a0, Func Offset: 0
	// Line 906, Address: 0x1c13b4, Func Offset: 0x14
	// Line 909, Address: 0x1c13d4, Func Offset: 0x34
	// Line 910, Address: 0x1c13e0, Func Offset: 0x40
	// Line 912, Address: 0x1c13e4, Func Offset: 0x44
	// Line 911, Address: 0x1c13e8, Func Offset: 0x48
	// Line 912, Address: 0x1c13ec, Func Offset: 0x4c
	// Line 913, Address: 0x1c13f0, Func Offset: 0x50
	// Line 916, Address: 0x1c13f8, Func Offset: 0x58
	// Line 917, Address: 0x1c1400, Func Offset: 0x60
	// Line 916, Address: 0x1c1408, Func Offset: 0x68
	// Line 919, Address: 0x1c1410, Func Offset: 0x70
	// Line 920, Address: 0x1c1450, Func Offset: 0xb0
	// Line 921, Address: 0x1c1494, Func Offset: 0xf4
	// Line 924, Address: 0x1c1498, Func Offset: 0xf8
	// Line 925, Address: 0x1c14c0, Func Offset: 0x120
	// Line 926, Address: 0x1c14e0, Func Offset: 0x140
	// Line 927, Address: 0x1c14e4, Func Offset: 0x144
	// Line 928, Address: 0x1c14ec, Func Offset: 0x14c
	// Line 932, Address: 0x1c14f4, Func Offset: 0x154
	// Line 934, Address: 0x1c153c, Func Offset: 0x19c
	// Line 937, Address: 0x1c1548, Func Offset: 0x1a8
	// Line 938, Address: 0x1c1588, Func Offset: 0x1e8
	// Line 939, Address: 0x1c15d4, Func Offset: 0x234
	// Line 940, Address: 0x1c15dc, Func Offset: 0x23c
	// Line 943, Address: 0x1c1604, Func Offset: 0x264
	// Line 944, Address: 0x1c1610, Func Offset: 0x270
	// Line 945, Address: 0x1c163c, Func Offset: 0x29c
	// Line 947, Address: 0x1c1690, Func Offset: 0x2f0
	// Line 948, Address: 0x1c16c4, Func Offset: 0x324
	// Line 949, Address: 0x1c16d8, Func Offset: 0x338
	// Line 950, Address: 0x1c16e8, Func Offset: 0x348
	// Line 951, Address: 0x1c16f0, Func Offset: 0x350
	// Line 952, Address: 0x1c16fc, Func Offset: 0x35c
	// Line 953, Address: 0x1c1700, Func Offset: 0x360
	// Line 954, Address: 0x1c1708, Func Offset: 0x368
	// Line 958, Address: 0x1c1728, Func Offset: 0x388
	// Line 959, Address: 0x1c1738, Func Offset: 0x398
	// Line 960, Address: 0x1c1740, Func Offset: 0x3a0
	// Line 961, Address: 0x1c1748, Func Offset: 0x3a8
	// Line 964, Address: 0x1c174c, Func Offset: 0x3ac
	// Line 966, Address: 0x1c175c, Func Offset: 0x3bc
	// Line 967, Address: 0x1c1770, Func Offset: 0x3d0
	// Line 970, Address: 0x1c17b4, Func Offset: 0x414
	// Line 972, Address: 0x1c17d8, Func Offset: 0x438
	// Line 975, Address: 0x1c17ec, Func Offset: 0x44c
	// Line 974, Address: 0x1c17f0, Func Offset: 0x450
	// Line 975, Address: 0x1c17f4, Func Offset: 0x454
	// Line 976, Address: 0x1c17f8, Func Offset: 0x458
	// Line 982, Address: 0x1c17fc, Func Offset: 0x45c
	// Func End, Address: 0x1c1810, Func Offset: 0x470
}

// 
// Start address: 0x1c1810
void bhEne07_MV05(BH_PWORK* epw)
{
	// Line 992, Address: 0x1c1810, Func Offset: 0
	// Line 993, Address: 0x1c1824, Func Offset: 0x14
	// Line 996, Address: 0x1c1844, Func Offset: 0x34
	// Line 998, Address: 0x1c184c, Func Offset: 0x3c
	// Line 997, Address: 0x1c1850, Func Offset: 0x40
	// Line 998, Address: 0x1c1854, Func Offset: 0x44
	// Line 999, Address: 0x1c1858, Func Offset: 0x48
	// Line 1001, Address: 0x1c1860, Func Offset: 0x50
	// Line 1002, Address: 0x1c1868, Func Offset: 0x58
	// Line 1005, Address: 0x1c18a8, Func Offset: 0x98
	// Line 1007, Address: 0x1c18f0, Func Offset: 0xe0
	// Line 1008, Address: 0x1c1944, Func Offset: 0x134
	// Line 1009, Address: 0x1c1964, Func Offset: 0x154
	// Line 1011, Address: 0x1c1984, Func Offset: 0x174
	// Line 1012, Address: 0x1c1998, Func Offset: 0x188
	// Line 1013, Address: 0x1c19b8, Func Offset: 0x1a8
	// Line 1014, Address: 0x1c19cc, Func Offset: 0x1bc
	// Line 1016, Address: 0x1c19e0, Func Offset: 0x1d0
	// Line 1017, Address: 0x1c1a08, Func Offset: 0x1f8
	// Line 1020, Address: 0x1c1a30, Func Offset: 0x220
	// Line 1021, Address: 0x1c1a70, Func Offset: 0x260
	// Line 1022, Address: 0x1c1abc, Func Offset: 0x2ac
	// Line 1023, Address: 0x1c1ac4, Func Offset: 0x2b4
	// Line 1026, Address: 0x1c1aec, Func Offset: 0x2dc
	// Line 1027, Address: 0x1c1afc, Func Offset: 0x2ec
	// Line 1029, Address: 0x1c1b00, Func Offset: 0x2f0
	// Line 1027, Address: 0x1c1b04, Func Offset: 0x2f4
	// Line 1028, Address: 0x1c1b0c, Func Offset: 0x2fc
	// Line 1029, Address: 0x1c1b10, Func Offset: 0x300
	// Line 1030, Address: 0x1c1b14, Func Offset: 0x304
	// Line 1033, Address: 0x1c1b18, Func Offset: 0x308
	// Func End, Address: 0x1c1b2c, Func Offset: 0x31c
}

// 
// Start address: 0x1c1b30
void bhEne07_MV06()
{
	// Line 1045, Address: 0x1c1b30, Func Offset: 0
	// Func End, Address: 0x1c1b38, Func Offset: 0x8
}

// 
// Start address: 0x1c1b40
void bhEne07_MV07()
{
	// Line 1057, Address: 0x1c1b40, Func Offset: 0
	// Func End, Address: 0x1c1b48, Func Offset: 0x8
}

// 
// Start address: 0x1c1b50
void bhEne07_MV08(BH_PWORK* epw)
{
	_anon5 pos;
	// Line 1067, Address: 0x1c1b50, Func Offset: 0
	// Line 1070, Address: 0x1c1b60, Func Offset: 0x10
	// Line 1072, Address: 0x1c1b80, Func Offset: 0x30
	// Line 1073, Address: 0x1c1b88, Func Offset: 0x38
	// Line 1076, Address: 0x1c1b8c, Func Offset: 0x3c
	// Line 1078, Address: 0x1c1b90, Func Offset: 0x40
	// Line 1072, Address: 0x1c1b94, Func Offset: 0x44
	// Line 1073, Address: 0x1c1b9c, Func Offset: 0x4c
	// Line 1079, Address: 0x1c1ba0, Func Offset: 0x50
	// Line 1073, Address: 0x1c1ba4, Func Offset: 0x54
	// Line 1074, Address: 0x1c1bac, Func Offset: 0x5c
	// Line 1076, Address: 0x1c1bb8, Func Offset: 0x68
	// Line 1077, Address: 0x1c1bbc, Func Offset: 0x6c
	// Line 1078, Address: 0x1c1bc0, Func Offset: 0x70
	// Line 1079, Address: 0x1c1bc4, Func Offset: 0x74
	// Line 1080, Address: 0x1c1bc8, Func Offset: 0x78
	// Line 1081, Address: 0x1c1be8, Func Offset: 0x98
	// Line 1083, Address: 0x1c1bf4, Func Offset: 0xa4
	// Line 1085, Address: 0x1c1c04, Func Offset: 0xb4
	// Line 1086, Address: 0x1c1c18, Func Offset: 0xc8
	// Line 1090, Address: 0x1c1c1c, Func Offset: 0xcc
	// Line 1093, Address: 0x1c1c20, Func Offset: 0xd0
	// Line 1095, Address: 0x1c1c24, Func Offset: 0xd4
	// Line 1086, Address: 0x1c1c28, Func Offset: 0xd8
	// Line 1087, Address: 0x1c1c2c, Func Offset: 0xdc
	// Line 1088, Address: 0x1c1c34, Func Offset: 0xe4
	// Line 1090, Address: 0x1c1c3c, Func Offset: 0xec
	// Line 1091, Address: 0x1c1c40, Func Offset: 0xf0
	// Line 1093, Address: 0x1c1c44, Func Offset: 0xf4
	// Line 1095, Address: 0x1c1c50, Func Offset: 0x100
	// Line 1096, Address: 0x1c1c54, Func Offset: 0x104
	// Line 1098, Address: 0x1c1c58, Func Offset: 0x108
	// Line 1099, Address: 0x1c1c60, Func Offset: 0x110
	// Line 1100, Address: 0x1c1c84, Func Offset: 0x134
	// Line 1101, Address: 0x1c1ca0, Func Offset: 0x150
	// Line 1102, Address: 0x1c1cbc, Func Offset: 0x16c
	// Line 1106, Address: 0x1c1cd4, Func Offset: 0x184
	// Func End, Address: 0x1c1ce4, Func Offset: 0x194
}

// 
// Start address: 0x1c1cf0
void bhEne07_Nage(BH_PWORK* epw)
{
	// Line 1117, Address: 0x1c1cf0, Func Offset: 0
	// Func End, Address: 0x1c1d10, Func Offset: 0x20
}

// 
// Start address: 0x1c1d10
void bhEne07_NG00(BH_PWORK* epw)
{
	_anon5 v;
	_anon5 pos;
	// Line 1128, Address: 0x1c1d10, Func Offset: 0
	// Line 1132, Address: 0x1c1d24, Func Offset: 0x14
	// Line 1135, Address: 0x1c1d44, Func Offset: 0x34
	// Line 1138, Address: 0x1c1d48, Func Offset: 0x38
	// Line 1135, Address: 0x1c1d4c, Func Offset: 0x3c
	// Line 1138, Address: 0x1c1d50, Func Offset: 0x40
	// Line 1136, Address: 0x1c1d54, Func Offset: 0x44
	// Line 1135, Address: 0x1c1d58, Func Offset: 0x48
	// Line 1136, Address: 0x1c1d60, Func Offset: 0x50
	// Line 1141, Address: 0x1c1d64, Func Offset: 0x54
	// Line 1136, Address: 0x1c1d68, Func Offset: 0x58
	// Line 1138, Address: 0x1c1d70, Func Offset: 0x60
	// Line 1141, Address: 0x1c1d7c, Func Offset: 0x6c
	// Line 1142, Address: 0x1c1d9c, Func Offset: 0x8c
	// Line 1148, Address: 0x1c1da8, Func Offset: 0x98
	// Line 1142, Address: 0x1c1dac, Func Offset: 0x9c
	// Line 1143, Address: 0x1c1db0, Func Offset: 0xa0
	// Line 1144, Address: 0x1c1dbc, Func Offset: 0xac
	// Line 1145, Address: 0x1c1dc8, Func Offset: 0xb8
	// Line 1148, Address: 0x1c1dcc, Func Offset: 0xbc
	// Line 1152, Address: 0x1c1dd4, Func Offset: 0xc4
	// Line 1154, Address: 0x1c1ddc, Func Offset: 0xcc
	// Line 1153, Address: 0x1c1de0, Func Offset: 0xd0
	// Line 1154, Address: 0x1c1de4, Func Offset: 0xd4
	// Line 1155, Address: 0x1c1de8, Func Offset: 0xd8
	// Line 1158, Address: 0x1c1df0, Func Offset: 0xe0
	// Line 1164, Address: 0x1c1df8, Func Offset: 0xe8
	// Line 1158, Address: 0x1c1e00, Func Offset: 0xf0
	// Line 1164, Address: 0x1c1e14, Func Offset: 0x104
	// Line 1158, Address: 0x1c1e18, Func Offset: 0x108
	// Line 1160, Address: 0x1c1e24, Func Offset: 0x114
	// Line 1161, Address: 0x1c1e28, Func Offset: 0x118
	// Line 1164, Address: 0x1c1e30, Func Offset: 0x120
	// Line 1168, Address: 0x1c1e38, Func Offset: 0x128
	// Line 1172, Address: 0x1c1e50, Func Offset: 0x140
	// Line 1168, Address: 0x1c1e54, Func Offset: 0x144
	// Line 1172, Address: 0x1c1e5c, Func Offset: 0x14c
	// Line 1168, Address: 0x1c1e60, Func Offset: 0x150
	// Line 1172, Address: 0x1c1e6c, Func Offset: 0x15c
	// Line 1168, Address: 0x1c1e78, Func Offset: 0x168
	// Line 1172, Address: 0x1c1e94, Func Offset: 0x184
	// Line 1176, Address: 0x1c1edc, Func Offset: 0x1cc
	// Line 1178, Address: 0x1c1ef8, Func Offset: 0x1e8
	// Line 1179, Address: 0x1c1f08, Func Offset: 0x1f8
	// Line 1178, Address: 0x1c1f10, Func Offset: 0x200
	// Line 1179, Address: 0x1c1f1c, Func Offset: 0x20c
	// Line 1180, Address: 0x1c1f28, Func Offset: 0x218
	// Line 1183, Address: 0x1c1f38, Func Offset: 0x228
	// Line 1180, Address: 0x1c1f3c, Func Offset: 0x22c
	// Line 1183, Address: 0x1c1f40, Func Offset: 0x230
	// Line 1180, Address: 0x1c1f44, Func Offset: 0x234
	// Line 1183, Address: 0x1c1f4c, Func Offset: 0x23c
	// Line 1184, Address: 0x1c1f64, Func Offset: 0x254
	// Line 1185, Address: 0x1c1f7c, Func Offset: 0x26c
	// Line 1187, Address: 0x1c1f94, Func Offset: 0x284
	// Line 1189, Address: 0x1c1fa8, Func Offset: 0x298
	// Line 1191, Address: 0x1c1fe8, Func Offset: 0x2d8
	// Line 1193, Address: 0x1c200c, Func Offset: 0x2fc
	// Line 1194, Address: 0x1c2010, Func Offset: 0x300
	// Line 1195, Address: 0x1c2014, Func Offset: 0x304
	// Line 1198, Address: 0x1c2018, Func Offset: 0x308
	// Line 1194, Address: 0x1c2020, Func Offset: 0x310
	// Line 1195, Address: 0x1c2024, Func Offset: 0x314
	// Line 1199, Address: 0x1c2028, Func Offset: 0x318
	// Line 1195, Address: 0x1c202c, Func Offset: 0x31c
	// Line 1198, Address: 0x1c2030, Func Offset: 0x320
	// Line 1199, Address: 0x1c2038, Func Offset: 0x328
	// Line 1200, Address: 0x1c2044, Func Offset: 0x334
	// Line 1204, Address: 0x1c2050, Func Offset: 0x340
	// Line 1205, Address: 0x1c2054, Func Offset: 0x344
	// Line 1208, Address: 0x1c2058, Func Offset: 0x348
	// Line 1210, Address: 0x1c205c, Func Offset: 0x34c
	// Line 1204, Address: 0x1c2060, Func Offset: 0x350
	// Line 1205, Address: 0x1c2068, Func Offset: 0x358
	// Line 1214, Address: 0x1c206c, Func Offset: 0x35c
	// Line 1205, Address: 0x1c2070, Func Offset: 0x360
	// Line 1208, Address: 0x1c2078, Func Offset: 0x368
	// Line 1209, Address: 0x1c207c, Func Offset: 0x36c
	// Line 1210, Address: 0x1c2080, Func Offset: 0x370
	// Line 1211, Address: 0x1c2084, Func Offset: 0x374
	// Line 1214, Address: 0x1c2088, Func Offset: 0x378
	// Line 1218, Address: 0x1c2090, Func Offset: 0x380
	// Line 1219, Address: 0x1c20a4, Func Offset: 0x394
	// Line 1221, Address: 0x1c20b0, Func Offset: 0x3a0
	// Line 1224, Address: 0x1c20c4, Func Offset: 0x3b4
	// Line 1227, Address: 0x1c20d0, Func Offset: 0x3c0
	// Line 1228, Address: 0x1c20dc, Func Offset: 0x3cc
	// Line 1227, Address: 0x1c20e0, Func Offset: 0x3d0
	// Line 1228, Address: 0x1c20e8, Func Offset: 0x3d8
	// Line 1229, Address: 0x1c20fc, Func Offset: 0x3ec
	// Line 1233, Address: 0x1c2104, Func Offset: 0x3f4
	// Func End, Address: 0x1c211c, Func Offset: 0x40c
}

// 
// Start address: 0x1c2120
void bhEne07_NG01(BH_PWORK* epw)
{
	_anon20* owk;
	_anon5 v;
	_anon5 offset;
	_anon5 pos;
	// Line 1243, Address: 0x1c2120, Func Offset: 0
	// Line 1246, Address: 0x1c2130, Func Offset: 0x10
	// Line 1249, Address: 0x1c2150, Func Offset: 0x30
	// Line 1252, Address: 0x1c2154, Func Offset: 0x34
	// Line 1249, Address: 0x1c2158, Func Offset: 0x38
	// Line 1252, Address: 0x1c215c, Func Offset: 0x3c
	// Line 1250, Address: 0x1c2160, Func Offset: 0x40
	// Line 1249, Address: 0x1c2164, Func Offset: 0x44
	// Line 1250, Address: 0x1c216c, Func Offset: 0x4c
	// Line 1255, Address: 0x1c2170, Func Offset: 0x50
	// Line 1258, Address: 0x1c2174, Func Offset: 0x54
	// Line 1263, Address: 0x1c2178, Func Offset: 0x58
	// Line 1250, Address: 0x1c217c, Func Offset: 0x5c
	// Line 1252, Address: 0x1c2184, Func Offset: 0x64
	// Line 1265, Address: 0x1c2188, Func Offset: 0x68
	// Line 1266, Address: 0x1c218c, Func Offset: 0x6c
	// Line 1269, Address: 0x1c2190, Func Offset: 0x70
	// Line 1252, Address: 0x1c2194, Func Offset: 0x74
	// Line 1255, Address: 0x1c219c, Func Offset: 0x7c
	// Line 1274, Address: 0x1c21a0, Func Offset: 0x80
	// Line 1255, Address: 0x1c21a8, Func Offset: 0x88
	// Line 1258, Address: 0x1c21ac, Func Offset: 0x8c
	// Line 1259, Address: 0x1c21b4, Func Offset: 0x94
	// Line 1260, Address: 0x1c21c0, Func Offset: 0xa0
	// Line 1263, Address: 0x1c21cc, Func Offset: 0xac
	// Line 1264, Address: 0x1c21d0, Func Offset: 0xb0
	// Line 1265, Address: 0x1c21d4, Func Offset: 0xb4
	// Line 1266, Address: 0x1c21d8, Func Offset: 0xb8
	// Line 1268, Address: 0x1c21dc, Func Offset: 0xbc
	// Line 1269, Address: 0x1c21fc, Func Offset: 0xdc
	// Line 1270, Address: 0x1c2200, Func Offset: 0xe0
	// Line 1271, Address: 0x1c2204, Func Offset: 0xe4
	// Line 1274, Address: 0x1c220c, Func Offset: 0xec
	// Line 1277, Address: 0x1c2214, Func Offset: 0xf4
	// Line 1279, Address: 0x1c221c, Func Offset: 0xfc
	// Line 1284, Address: 0x1c2228, Func Offset: 0x108
	// Line 1285, Address: 0x1c223c, Func Offset: 0x11c
	// Line 1288, Address: 0x1c2240, Func Offset: 0x120
	// Line 1285, Address: 0x1c2244, Func Offset: 0x124
	// Line 1284, Address: 0x1c2248, Func Offset: 0x128
	// Line 1285, Address: 0x1c224c, Func Offset: 0x12c
	// Line 1284, Address: 0x1c2250, Func Offset: 0x130
	// Line 1285, Address: 0x1c2254, Func Offset: 0x134
	// Line 1289, Address: 0x1c225c, Func Offset: 0x13c
	// Line 1285, Address: 0x1c2260, Func Offset: 0x140
	// Line 1288, Address: 0x1c2268, Func Offset: 0x148
	// Line 1289, Address: 0x1c2278, Func Offset: 0x158
	// Line 1291, Address: 0x1c2280, Func Offset: 0x160
	// Line 1292, Address: 0x1c228c, Func Offset: 0x16c
	// Line 1293, Address: 0x1c22b0, Func Offset: 0x190
	// Line 1294, Address: 0x1c22d0, Func Offset: 0x1b0
	// Line 1296, Address: 0x1c22f0, Func Offset: 0x1d0
	// Line 1297, Address: 0x1c22fc, Func Offset: 0x1dc
	// Line 1298, Address: 0x1c2308, Func Offset: 0x1e8
	// Line 1299, Address: 0x1c2318, Func Offset: 0x1f8
	// Line 1300, Address: 0x1c2334, Func Offset: 0x214
	// Line 1302, Address: 0x1c2358, Func Offset: 0x238
	// Line 1303, Address: 0x1c238c, Func Offset: 0x26c
	// Line 1305, Address: 0x1c23c0, Func Offset: 0x2a0
	// Line 1306, Address: 0x1c23c8, Func Offset: 0x2a8
	// Line 1308, Address: 0x1c23d0, Func Offset: 0x2b0
	// Line 1309, Address: 0x1c23d8, Func Offset: 0x2b8
	// Line 1310, Address: 0x1c23e0, Func Offset: 0x2c0
	// Line 1313, Address: 0x1c23e8, Func Offset: 0x2c8
	// Line 1314, Address: 0x1c23f4, Func Offset: 0x2d4
	// Line 1315, Address: 0x1c2400, Func Offset: 0x2e0
	// Line 1316, Address: 0x1c240c, Func Offset: 0x2ec
	// Line 1320, Address: 0x1c2414, Func Offset: 0x2f4
	// Line 1316, Address: 0x1c2420, Func Offset: 0x300
	// Line 1317, Address: 0x1c2424, Func Offset: 0x304
	// Line 1318, Address: 0x1c2430, Func Offset: 0x310
	// Line 1320, Address: 0x1c2438, Func Offset: 0x318
	// Line 1321, Address: 0x1c2440, Func Offset: 0x320
	// Line 1322, Address: 0x1c245c, Func Offset: 0x33c
	// Line 1326, Address: 0x1c2480, Func Offset: 0x360
	// Line 1328, Address: 0x1c2494, Func Offset: 0x374
	// Line 1330, Address: 0x1c24c8, Func Offset: 0x3a8
	// Line 1331, Address: 0x1c24cc, Func Offset: 0x3ac
	// Line 1334, Address: 0x1c24d0, Func Offset: 0x3b0
	// Line 1336, Address: 0x1c24d4, Func Offset: 0x3b4
	// Line 1330, Address: 0x1c24d8, Func Offset: 0x3b8
	// Line 1331, Address: 0x1c24e0, Func Offset: 0x3c0
	// Line 1340, Address: 0x1c24e4, Func Offset: 0x3c4
	// Line 1343, Address: 0x1c24e8, Func Offset: 0x3c8
	// Line 1331, Address: 0x1c24ec, Func Offset: 0x3cc
	// Line 1334, Address: 0x1c24f4, Func Offset: 0x3d4
	// Line 1335, Address: 0x1c24f8, Func Offset: 0x3d8
	// Line 1336, Address: 0x1c24fc, Func Offset: 0x3dc
	// Line 1337, Address: 0x1c2500, Func Offset: 0x3e0
	// Line 1339, Address: 0x1c2504, Func Offset: 0x3e4
	// Line 1340, Address: 0x1c250c, Func Offset: 0x3ec
	// Line 1343, Address: 0x1c2514, Func Offset: 0x3f4
	// Line 1347, Address: 0x1c251c, Func Offset: 0x3fc
	// Line 1348, Address: 0x1c253c, Func Offset: 0x41c
	// Line 1350, Address: 0x1c2548, Func Offset: 0x428
	// Line 1352, Address: 0x1c255c, Func Offset: 0x43c
	// Line 1353, Address: 0x1c2568, Func Offset: 0x448
	// Line 1352, Address: 0x1c256c, Func Offset: 0x44c
	// Line 1353, Address: 0x1c2574, Func Offset: 0x454
	// Line 1354, Address: 0x1c2588, Func Offset: 0x468
	// Line 1358, Address: 0x1c2590, Func Offset: 0x470
	// Func End, Address: 0x1c25a4, Func Offset: 0x484
}

// 
// Start address: 0x1c25b0
void bhEne07_Damage(BH_PWORK* epw)
{
	_anon5 ofp;
	_anon5 ofp;
	int dam;
	int i;
	// Line 1368, Address: 0x1c25b0, Func Offset: 0
	// Line 1372, Address: 0x1c25cc, Func Offset: 0x1c
	// Line 1373, Address: 0x1c25dc, Func Offset: 0x2c
	// Line 1374, Address: 0x1c25e8, Func Offset: 0x38
	// Line 1375, Address: 0x1c25ec, Func Offset: 0x3c
	// Line 1377, Address: 0x1c25f4, Func Offset: 0x44
	// Line 1378, Address: 0x1c260c, Func Offset: 0x5c
	// Line 1381, Address: 0x1c2618, Func Offset: 0x68
	// Line 1383, Address: 0x1c2624, Func Offset: 0x74
	// Line 1384, Address: 0x1c2630, Func Offset: 0x80
	// Line 1387, Address: 0x1c2638, Func Offset: 0x88
	// Line 1390, Address: 0x1c263c, Func Offset: 0x8c
	// Line 1387, Address: 0x1c2648, Func Offset: 0x98
	// Line 1388, Address: 0x1c264c, Func Offset: 0x9c
	// Line 1389, Address: 0x1c2654, Func Offset: 0xa4
	// Line 1390, Address: 0x1c2658, Func Offset: 0xa8
	// Line 1391, Address: 0x1c2660, Func Offset: 0xb0
	// Line 1396, Address: 0x1c2670, Func Offset: 0xc0
	// Line 1397, Address: 0x1c2688, Func Offset: 0xd8
	// Line 1398, Address: 0x1c2690, Func Offset: 0xe0
	// Line 1400, Address: 0x1c26a4, Func Offset: 0xf4
	// Line 1402, Address: 0x1c26b8, Func Offset: 0x108
	// Line 1403, Address: 0x1c26c0, Func Offset: 0x110
	// Line 1404, Address: 0x1c26d4, Func Offset: 0x124
	// Line 1405, Address: 0x1c26d8, Func Offset: 0x128
	// Line 1406, Address: 0x1c26e0, Func Offset: 0x130
	// Line 1409, Address: 0x1c26e4, Func Offset: 0x134
	// Line 1411, Address: 0x1c26ec, Func Offset: 0x13c
	// Line 1412, Address: 0x1c2700, Func Offset: 0x150
	// Line 1413, Address: 0x1c2704, Func Offset: 0x154
	// Line 1414, Address: 0x1c270c, Func Offset: 0x15c
	// Line 1415, Address: 0x1c2720, Func Offset: 0x170
	// Line 1416, Address: 0x1c2724, Func Offset: 0x174
	// Line 1417, Address: 0x1c272c, Func Offset: 0x17c
	// Line 1422, Address: 0x1c2734, Func Offset: 0x184
	// Line 1425, Address: 0x1c274c, Func Offset: 0x19c
	// Line 1430, Address: 0x1c276c, Func Offset: 0x1bc
	// Line 1431, Address: 0x1c27a0, Func Offset: 0x1f0
	// Line 1433, Address: 0x1c27b8, Func Offset: 0x208
	// Line 1431, Address: 0x1c27c0, Func Offset: 0x210
	// Line 1432, Address: 0x1c27c4, Func Offset: 0x214
	// Line 1431, Address: 0x1c27c8, Func Offset: 0x218
	// Line 1433, Address: 0x1c27cc, Func Offset: 0x21c
	// Line 1431, Address: 0x1c27d0, Func Offset: 0x220
	// Line 1433, Address: 0x1c27dc, Func Offset: 0x22c
	// Line 1435, Address: 0x1c2830, Func Offset: 0x280
	// Line 1436, Address: 0x1c2864, Func Offset: 0x2b4
	// Line 1438, Address: 0x1c287c, Func Offset: 0x2cc
	// Line 1436, Address: 0x1c2880, Func Offset: 0x2d0
	// Line 1438, Address: 0x1c2884, Func Offset: 0x2d4
	// Line 1436, Address: 0x1c2888, Func Offset: 0x2d8
	// Line 1438, Address: 0x1c2894, Func Offset: 0x2e4
	// Line 1440, Address: 0x1c28e8, Func Offset: 0x338
	// Line 1441, Address: 0x1c291c, Func Offset: 0x36c
	// Line 1443, Address: 0x1c294c, Func Offset: 0x39c
	// Line 1446, Address: 0x1c29a8, Func Offset: 0x3f8
	// Line 1449, Address: 0x1c29b8, Func Offset: 0x408
	// Line 1450, Address: 0x1c29ec, Func Offset: 0x43c
	// Line 1452, Address: 0x1c2a04, Func Offset: 0x454
	// Line 1450, Address: 0x1c2a10, Func Offset: 0x460
	// Line 1452, Address: 0x1c2a14, Func Offset: 0x464
	// Line 1450, Address: 0x1c2a18, Func Offset: 0x468
	// Line 1452, Address: 0x1c2a1c, Func Offset: 0x46c
	// Line 1450, Address: 0x1c2a20, Func Offset: 0x470
	// Line 1452, Address: 0x1c2a28, Func Offset: 0x478
	// Line 1457, Address: 0x1c2a30, Func Offset: 0x480
	// Line 1458, Address: 0x1c2a34, Func Offset: 0x484
	// Line 1460, Address: 0x1c2a38, Func Offset: 0x488
	// Line 1464, Address: 0x1c2a3c, Func Offset: 0x48c
	// Line 1457, Address: 0x1c2a40, Func Offset: 0x490
	// Line 1458, Address: 0x1c2a48, Func Offset: 0x498
	// Line 1460, Address: 0x1c2a54, Func Offset: 0x4a4
	// Line 1461, Address: 0x1c2a5c, Func Offset: 0x4ac
	// Line 1464, Address: 0x1c2a64, Func Offset: 0x4b4
	// Line 1465, Address: 0x1c2a68, Func Offset: 0x4b8
	// Line 1466, Address: 0x1c2a6c, Func Offset: 0x4bc
	// Line 1468, Address: 0x1c2a70, Func Offset: 0x4c0
	// Func End, Address: 0x1c2a8c, Func Offset: 0x4dc
}

// 
// Start address: 0x1c2a90
void bhEne07_Die(BH_PWORK* epw)
{
	// Line 1490, Address: 0x1c2a90, Func Offset: 0
	// Func End, Address: 0x1c2ab0, Func Offset: 0x20
}

// 
// Start address: 0x1c2ab0
void bhEne07_DD00(BH_PWORK* epw)
{
	_anon5 trans;
	_anon3* mkfP;
	// Line 1501, Address: 0x1c2ab0, Func Offset: 0
	// Line 1502, Address: 0x1c2ac4, Func Offset: 0x14
	// Line 1505, Address: 0x1c2b08, Func Offset: 0x58
	// Line 1507, Address: 0x1c2b10, Func Offset: 0x60
	// Line 1506, Address: 0x1c2b14, Func Offset: 0x64
	// Line 1507, Address: 0x1c2b18, Func Offset: 0x68
	// Line 1508, Address: 0x1c2b1c, Func Offset: 0x6c
	// Line 1509, Address: 0x1c2b24, Func Offset: 0x74
	// Line 1510, Address: 0x1c2b2c, Func Offset: 0x7c
	// Line 1509, Address: 0x1c2b34, Func Offset: 0x84
	// Line 1510, Address: 0x1c2b3c, Func Offset: 0x8c
	// Line 1512, Address: 0x1c2b48, Func Offset: 0x98
	// Line 1513, Address: 0x1c2b54, Func Offset: 0xa4
	// Line 1514, Address: 0x1c2b60, Func Offset: 0xb0
	// Line 1515, Address: 0x1c2b6c, Func Offset: 0xbc
	// Line 1516, Address: 0x1c2b78, Func Offset: 0xc8
	// Line 1532, Address: 0x1c2b84, Func Offset: 0xd4
	// Line 1533, Address: 0x1c2b88, Func Offset: 0xd8
	// Line 1516, Address: 0x1c2b8c, Func Offset: 0xdc
	// Line 1535, Address: 0x1c2b90, Func Offset: 0xe0
	// Line 1516, Address: 0x1c2b94, Func Offset: 0xe4
	// Line 1517, Address: 0x1c2b9c, Func Offset: 0xec
	// Line 1518, Address: 0x1c2ba0, Func Offset: 0xf0
	// Line 1521, Address: 0x1c2bac, Func Offset: 0xfc
	// Line 1522, Address: 0x1c2bb4, Func Offset: 0x104
	// Line 1529, Address: 0x1c2bbc, Func Offset: 0x10c
	// Line 1530, Address: 0x1c2bc4, Func Offset: 0x114
	// Line 1529, Address: 0x1c2bc8, Func Offset: 0x118
	// Line 1530, Address: 0x1c2bdc, Func Offset: 0x12c
	// Line 1529, Address: 0x1c2be8, Func Offset: 0x138
	// Line 1530, Address: 0x1c2bec, Func Offset: 0x13c
	// Line 1531, Address: 0x1c2bf4, Func Offset: 0x144
	// Line 1532, Address: 0x1c2bfc, Func Offset: 0x14c
	// Line 1533, Address: 0x1c2c04, Func Offset: 0x154
	// Line 1535, Address: 0x1c2c08, Func Offset: 0x158
	// Line 1536, Address: 0x1c2c10, Func Offset: 0x160
	// Line 1537, Address: 0x1c2c1c, Func Offset: 0x16c
	// Line 1539, Address: 0x1c2c2c, Func Offset: 0x17c
	// Line 1545, Address: 0x1c2c34, Func Offset: 0x184
	// Line 1539, Address: 0x1c2c40, Func Offset: 0x190
	// Line 1540, Address: 0x1c2c48, Func Offset: 0x198
	// Line 1541, Address: 0x1c2c58, Func Offset: 0x1a8
	// Line 1545, Address: 0x1c2c64, Func Offset: 0x1b4
	// Line 1547, Address: 0x1c2c6c, Func Offset: 0x1bc
	// Line 1548, Address: 0x1c2c74, Func Offset: 0x1c4
	// Line 1550, Address: 0x1c2c80, Func Offset: 0x1d0
	// Line 1552, Address: 0x1c2c94, Func Offset: 0x1e4
	// Line 1554, Address: 0x1c2cec, Func Offset: 0x23c
	// Line 1553, Address: 0x1c2cf0, Func Offset: 0x240
	// Line 1554, Address: 0x1c2cf4, Func Offset: 0x244
	// Line 1555, Address: 0x1c2cf8, Func Offset: 0x248
	// Line 1556, Address: 0x1c2cfc, Func Offset: 0x24c
	// Line 1559, Address: 0x1c2d00, Func Offset: 0x250
	// Line 1556, Address: 0x1c2d04, Func Offset: 0x254
	// Line 1559, Address: 0x1c2d08, Func Offset: 0x258
	// Line 1556, Address: 0x1c2d10, Func Offset: 0x260
	// Line 1557, Address: 0x1c2d2c, Func Offset: 0x27c
	// Line 1559, Address: 0x1c2d34, Func Offset: 0x284
	// Line 1561, Address: 0x1c2d3c, Func Offset: 0x28c
	// Line 1562, Address: 0x1c2d40, Func Offset: 0x290
	// Line 1563, Address: 0x1c2d48, Func Offset: 0x298
	// Line 1561, Address: 0x1c2d50, Func Offset: 0x2a0
	// Line 1562, Address: 0x1c2d5c, Func Offset: 0x2ac
	// Line 1563, Address: 0x1c2d64, Func Offset: 0x2b4
	// Line 1564, Address: 0x1c2d74, Func Offset: 0x2c4
	// Line 1566, Address: 0x1c2d80, Func Offset: 0x2d0
	// Line 1568, Address: 0x1c2d88, Func Offset: 0x2d8
	// Line 1570, Address: 0x1c2d9c, Func Offset: 0x2ec
	// Line 1573, Address: 0x1c2da4, Func Offset: 0x2f4
	// Line 1576, Address: 0x1c2ddc, Func Offset: 0x32c
	// Line 1577, Address: 0x1c2de0, Func Offset: 0x330
	// Line 1576, Address: 0x1c2de4, Func Offset: 0x334
	// Line 1577, Address: 0x1c2dec, Func Offset: 0x33c
	// Line 1578, Address: 0x1c2df8, Func Offset: 0x348
	// Line 1579, Address: 0x1c2e00, Func Offset: 0x350
	// Line 1580, Address: 0x1c2e08, Func Offset: 0x358
	// Line 1581, Address: 0x1c2e10, Func Offset: 0x360
	// Line 1584, Address: 0x1c2e1c, Func Offset: 0x36c
	// Line 1585, Address: 0x1c2e28, Func Offset: 0x378
	// Line 1586, Address: 0x1c2e30, Func Offset: 0x380
	// Line 1590, Address: 0x1c2e3c, Func Offset: 0x38c
	// Line 1592, Address: 0x1c2e44, Func Offset: 0x394
	// Line 1593, Address: 0x1c2e54, Func Offset: 0x3a4
	// Line 1594, Address: 0x1c2e74, Func Offset: 0x3c4
	// Line 1595, Address: 0x1c2e78, Func Offset: 0x3c8
	// Line 1596, Address: 0x1c2e80, Func Offset: 0x3d0
	// Line 1597, Address: 0x1c2ea4, Func Offset: 0x3f4
	// Line 1599, Address: 0x1c2eac, Func Offset: 0x3fc
	// Line 1601, Address: 0x1c2eb4, Func Offset: 0x404
	// Line 1602, Address: 0x1c2ec4, Func Offset: 0x414
	// Line 1603, Address: 0x1c2ec8, Func Offset: 0x418
	// Line 1605, Address: 0x1c2ecc, Func Offset: 0x41c
	// Line 1603, Address: 0x1c2ed4, Func Offset: 0x424
	// Line 1605, Address: 0x1c2edc, Func Offset: 0x42c
	// Line 1611, Address: 0x1c2ee8, Func Offset: 0x438
	// Line 1612, Address: 0x1c2efc, Func Offset: 0x44c
	// Line 1615, Address: 0x1c2f00, Func Offset: 0x450
	// Line 1612, Address: 0x1c2f08, Func Offset: 0x458
	// Line 1615, Address: 0x1c2f0c, Func Offset: 0x45c
	// Line 1612, Address: 0x1c2f10, Func Offset: 0x460
	// Line 1613, Address: 0x1c2f1c, Func Offset: 0x46c
	// Line 1614, Address: 0x1c2f30, Func Offset: 0x480
	// Line 1615, Address: 0x1c2f44, Func Offset: 0x494
	// Line 1617, Address: 0x1c2f54, Func Offset: 0x4a4
	// Func End, Address: 0x1c2f6c, Func Offset: 0x4bc
}

// 
// Start address: 0x1c2f70
void bhEne07_DD01(BH_PWORK* epw)
{
	_anon5 trans;
	_anon3* mkfP;
	// Line 1627, Address: 0x1c2f70, Func Offset: 0
	// Line 1628, Address: 0x1c2f84, Func Offset: 0x14
	// Line 1631, Address: 0x1c2fc8, Func Offset: 0x58
	// Line 1633, Address: 0x1c2fd0, Func Offset: 0x60
	// Line 1632, Address: 0x1c2fd4, Func Offset: 0x64
	// Line 1633, Address: 0x1c2fd8, Func Offset: 0x68
	// Line 1634, Address: 0x1c2fdc, Func Offset: 0x6c
	// Line 1635, Address: 0x1c2fe4, Func Offset: 0x74
	// Line 1636, Address: 0x1c2fec, Func Offset: 0x7c
	// Line 1635, Address: 0x1c2ff4, Func Offset: 0x84
	// Line 1636, Address: 0x1c2ffc, Func Offset: 0x8c
	// Line 1638, Address: 0x1c3008, Func Offset: 0x98
	// Line 1639, Address: 0x1c3014, Func Offset: 0xa4
	// Line 1640, Address: 0x1c3020, Func Offset: 0xb0
	// Line 1641, Address: 0x1c302c, Func Offset: 0xbc
	// Line 1642, Address: 0x1c3038, Func Offset: 0xc8
	// Line 1658, Address: 0x1c3044, Func Offset: 0xd4
	// Line 1659, Address: 0x1c3048, Func Offset: 0xd8
	// Line 1642, Address: 0x1c304c, Func Offset: 0xdc
	// Line 1661, Address: 0x1c3050, Func Offset: 0xe0
	// Line 1642, Address: 0x1c3054, Func Offset: 0xe4
	// Line 1643, Address: 0x1c305c, Func Offset: 0xec
	// Line 1644, Address: 0x1c3060, Func Offset: 0xf0
	// Line 1647, Address: 0x1c306c, Func Offset: 0xfc
	// Line 1648, Address: 0x1c3074, Func Offset: 0x104
	// Line 1655, Address: 0x1c307c, Func Offset: 0x10c
	// Line 1656, Address: 0x1c3084, Func Offset: 0x114
	// Line 1655, Address: 0x1c3088, Func Offset: 0x118
	// Line 1656, Address: 0x1c309c, Func Offset: 0x12c
	// Line 1655, Address: 0x1c30a8, Func Offset: 0x138
	// Line 1656, Address: 0x1c30ac, Func Offset: 0x13c
	// Line 1657, Address: 0x1c30b4, Func Offset: 0x144
	// Line 1658, Address: 0x1c30bc, Func Offset: 0x14c
	// Line 1659, Address: 0x1c30c4, Func Offset: 0x154
	// Line 1661, Address: 0x1c30c8, Func Offset: 0x158
	// Line 1662, Address: 0x1c30d0, Func Offset: 0x160
	// Line 1663, Address: 0x1c30dc, Func Offset: 0x16c
	// Line 1665, Address: 0x1c30ec, Func Offset: 0x17c
	// Line 1671, Address: 0x1c30f4, Func Offset: 0x184
	// Line 1665, Address: 0x1c3100, Func Offset: 0x190
	// Line 1666, Address: 0x1c3108, Func Offset: 0x198
	// Line 1667, Address: 0x1c3118, Func Offset: 0x1a8
	// Line 1671, Address: 0x1c3124, Func Offset: 0x1b4
	// Line 1673, Address: 0x1c312c, Func Offset: 0x1bc
	// Line 1674, Address: 0x1c3134, Func Offset: 0x1c4
	// Line 1676, Address: 0x1c3140, Func Offset: 0x1d0
	// Line 1677, Address: 0x1c3154, Func Offset: 0x1e4
	// Line 1679, Address: 0x1c31ac, Func Offset: 0x23c
	// Line 1678, Address: 0x1c31b0, Func Offset: 0x240
	// Line 1679, Address: 0x1c31b4, Func Offset: 0x244
	// Line 1680, Address: 0x1c31b8, Func Offset: 0x248
	// Line 1681, Address: 0x1c31bc, Func Offset: 0x24c
	// Line 1684, Address: 0x1c31c0, Func Offset: 0x250
	// Line 1681, Address: 0x1c31c4, Func Offset: 0x254
	// Line 1684, Address: 0x1c31c8, Func Offset: 0x258
	// Line 1681, Address: 0x1c31d0, Func Offset: 0x260
	// Line 1682, Address: 0x1c31ec, Func Offset: 0x27c
	// Line 1684, Address: 0x1c31f4, Func Offset: 0x284
	// Line 1686, Address: 0x1c31fc, Func Offset: 0x28c
	// Line 1687, Address: 0x1c3200, Func Offset: 0x290
	// Line 1688, Address: 0x1c3208, Func Offset: 0x298
	// Line 1686, Address: 0x1c3210, Func Offset: 0x2a0
	// Line 1687, Address: 0x1c321c, Func Offset: 0x2ac
	// Line 1688, Address: 0x1c3224, Func Offset: 0x2b4
	// Line 1689, Address: 0x1c3234, Func Offset: 0x2c4
	// Line 1691, Address: 0x1c3240, Func Offset: 0x2d0
	// Line 1693, Address: 0x1c3248, Func Offset: 0x2d8
	// Line 1695, Address: 0x1c325c, Func Offset: 0x2ec
	// Line 1698, Address: 0x1c3264, Func Offset: 0x2f4
	// Line 1701, Address: 0x1c329c, Func Offset: 0x32c
	// Line 1702, Address: 0x1c32a0, Func Offset: 0x330
	// Line 1701, Address: 0x1c32a4, Func Offset: 0x334
	// Line 1702, Address: 0x1c32ac, Func Offset: 0x33c
	// Line 1703, Address: 0x1c32b8, Func Offset: 0x348
	// Line 1704, Address: 0x1c32c0, Func Offset: 0x350
	// Line 1705, Address: 0x1c32c8, Func Offset: 0x358
	// Line 1706, Address: 0x1c32d0, Func Offset: 0x360
	// Line 1709, Address: 0x1c32dc, Func Offset: 0x36c
	// Line 1710, Address: 0x1c32e8, Func Offset: 0x378
	// Line 1711, Address: 0x1c32f0, Func Offset: 0x380
	// Line 1715, Address: 0x1c32fc, Func Offset: 0x38c
	// Line 1717, Address: 0x1c3304, Func Offset: 0x394
	// Line 1718, Address: 0x1c3314, Func Offset: 0x3a4
	// Line 1719, Address: 0x1c3334, Func Offset: 0x3c4
	// Line 1720, Address: 0x1c3338, Func Offset: 0x3c8
	// Line 1721, Address: 0x1c3340, Func Offset: 0x3d0
	// Line 1722, Address: 0x1c3364, Func Offset: 0x3f4
	// Line 1724, Address: 0x1c336c, Func Offset: 0x3fc
	// Line 1726, Address: 0x1c3374, Func Offset: 0x404
	// Line 1727, Address: 0x1c3384, Func Offset: 0x414
	// Line 1728, Address: 0x1c3388, Func Offset: 0x418
	// Line 1730, Address: 0x1c338c, Func Offset: 0x41c
	// Line 1728, Address: 0x1c3394, Func Offset: 0x424
	// Line 1730, Address: 0x1c339c, Func Offset: 0x42c
	// Line 1736, Address: 0x1c33a8, Func Offset: 0x438
	// Line 1737, Address: 0x1c33bc, Func Offset: 0x44c
	// Line 1740, Address: 0x1c33c0, Func Offset: 0x450
	// Line 1737, Address: 0x1c33c8, Func Offset: 0x458
	// Line 1740, Address: 0x1c33cc, Func Offset: 0x45c
	// Line 1737, Address: 0x1c33d0, Func Offset: 0x460
	// Line 1738, Address: 0x1c33dc, Func Offset: 0x46c
	// Line 1739, Address: 0x1c33f0, Func Offset: 0x480
	// Line 1740, Address: 0x1c3404, Func Offset: 0x494
	// Line 1742, Address: 0x1c3414, Func Offset: 0x4a4
	// Func End, Address: 0x1c342c, Func Offset: 0x4bc
}

// 
// Start address: 0x1c3430
void bhEne07_DD02(BH_PWORK* epw)
{
	_anon9* mkaP;
	_anon5 trans;
	_anon3* mkfP;
	_anon5 pos;
	// Line 1752, Address: 0x1c3430, Func Offset: 0
	// Line 1755, Address: 0x1c3444, Func Offset: 0x14
	// Line 1757, Address: 0x1c3470, Func Offset: 0x40
	// Line 1759, Address: 0x1c3478, Func Offset: 0x48
	// Line 1758, Address: 0x1c347c, Func Offset: 0x4c
	// Line 1759, Address: 0x1c3480, Func Offset: 0x50
	// Line 1760, Address: 0x1c3484, Func Offset: 0x54
	// Line 1762, Address: 0x1c348c, Func Offset: 0x5c
	// Line 1763, Address: 0x1c3494, Func Offset: 0x64
	// Line 1762, Address: 0x1c349c, Func Offset: 0x6c
	// Line 1763, Address: 0x1c34a4, Func Offset: 0x74
	// Line 1765, Address: 0x1c34b0, Func Offset: 0x80
	// Line 1766, Address: 0x1c34bc, Func Offset: 0x8c
	// Line 1767, Address: 0x1c34c8, Func Offset: 0x98
	// Line 1768, Address: 0x1c34d4, Func Offset: 0xa4
	// Line 1769, Address: 0x1c34e0, Func Offset: 0xb0
	// Line 1780, Address: 0x1c34ec, Func Offset: 0xbc
	// Line 1769, Address: 0x1c34f4, Func Offset: 0xc4
	// Line 1780, Address: 0x1c34f8, Func Offset: 0xc8
	// Line 1769, Address: 0x1c34fc, Func Offset: 0xcc
	// Line 1770, Address: 0x1c3504, Func Offset: 0xd4
	// Line 1771, Address: 0x1c3508, Func Offset: 0xd8
	// Line 1774, Address: 0x1c3514, Func Offset: 0xe4
	// Line 1775, Address: 0x1c351c, Func Offset: 0xec
	// Line 1777, Address: 0x1c3524, Func Offset: 0xf4
	// Line 1780, Address: 0x1c3540, Func Offset: 0x110
	// Line 1782, Address: 0x1c3548, Func Offset: 0x118
	// Line 1783, Address: 0x1c3550, Func Offset: 0x120
	// Line 1786, Address: 0x1c355c, Func Offset: 0x12c
	// Line 1791, Address: 0x1c356c, Func Offset: 0x13c
	// Line 1792, Address: 0x1c3580, Func Offset: 0x150
	// Line 1796, Address: 0x1c3584, Func Offset: 0x154
	// Line 1803, Address: 0x1c3588, Func Offset: 0x158
	// Line 1804, Address: 0x1c358c, Func Offset: 0x15c
	// Line 1792, Address: 0x1c3590, Func Offset: 0x160
	// Line 1793, Address: 0x1c3594, Func Offset: 0x164
	// Line 1806, Address: 0x1c3598, Func Offset: 0x168
	// Line 1793, Address: 0x1c359c, Func Offset: 0x16c
	// Line 1794, Address: 0x1c35a0, Func Offset: 0x170
	// Line 1796, Address: 0x1c35a8, Func Offset: 0x178
	// Line 1797, Address: 0x1c35ac, Func Offset: 0x17c
	// Line 1800, Address: 0x1c35b0, Func Offset: 0x180
	// Line 1801, Address: 0x1c35b8, Func Offset: 0x188
	// Line 1800, Address: 0x1c35bc, Func Offset: 0x18c
	// Line 1801, Address: 0x1c35d0, Func Offset: 0x1a0
	// Line 1800, Address: 0x1c35dc, Func Offset: 0x1ac
	// Line 1801, Address: 0x1c35e0, Func Offset: 0x1b0
	// Line 1802, Address: 0x1c35e8, Func Offset: 0x1b8
	// Line 1803, Address: 0x1c35f0, Func Offset: 0x1c0
	// Line 1804, Address: 0x1c35f8, Func Offset: 0x1c8
	// Line 1806, Address: 0x1c35fc, Func Offset: 0x1cc
	// Line 1807, Address: 0x1c3604, Func Offset: 0x1d4
	// Line 1808, Address: 0x1c3610, Func Offset: 0x1e0
	// Line 1810, Address: 0x1c3620, Func Offset: 0x1f0
	// Line 1817, Address: 0x1c3628, Func Offset: 0x1f8
	// Line 1810, Address: 0x1c362c, Func Offset: 0x1fc
	// Line 1811, Address: 0x1c3634, Func Offset: 0x204
	// Line 1812, Address: 0x1c3644, Func Offset: 0x214
	// Line 1814, Address: 0x1c3654, Func Offset: 0x224
	// Line 1817, Address: 0x1c3660, Func Offset: 0x230
	// Line 1821, Address: 0x1c366c, Func Offset: 0x23c
	// Line 1826, Address: 0x1c3680, Func Offset: 0x250
	// Line 1827, Address: 0x1c3688, Func Offset: 0x258
	// Line 1828, Address: 0x1c368c, Func Offset: 0x25c
	// Line 1831, Address: 0x1c3690, Func Offset: 0x260
	// Line 1826, Address: 0x1c3694, Func Offset: 0x264
	// Line 1827, Address: 0x1c36a8, Func Offset: 0x278
	// Line 1826, Address: 0x1c36b4, Func Offset: 0x284
	// Line 1827, Address: 0x1c36b8, Func Offset: 0x288
	// Line 1828, Address: 0x1c36c0, Func Offset: 0x290
	// Line 1831, Address: 0x1c36cc, Func Offset: 0x29c
	// Line 1832, Address: 0x1c36d8, Func Offset: 0x2a8
	// Line 1833, Address: 0x1c36e0, Func Offset: 0x2b0
	// Line 1835, Address: 0x1c3744, Func Offset: 0x314
	// Line 1834, Address: 0x1c3748, Func Offset: 0x318
	// Line 1835, Address: 0x1c374c, Func Offset: 0x31c
	// Line 1836, Address: 0x1c3750, Func Offset: 0x320
	// Line 1837, Address: 0x1c3754, Func Offset: 0x324
	// Line 1838, Address: 0x1c375c, Func Offset: 0x32c
	// Line 1839, Address: 0x1c37b4, Func Offset: 0x384
	// Line 1840, Address: 0x1c37b8, Func Offset: 0x388
	// Line 1843, Address: 0x1c37bc, Func Offset: 0x38c
	// Line 1845, Address: 0x1c37d0, Func Offset: 0x3a0
	// Line 1849, Address: 0x1c37d4, Func Offset: 0x3a4
	// Line 1845, Address: 0x1c37dc, Func Offset: 0x3ac
	// Line 1846, Address: 0x1c37e0, Func Offset: 0x3b0
	// Line 1845, Address: 0x1c37e4, Func Offset: 0x3b4
	// Line 1848, Address: 0x1c37f8, Func Offset: 0x3c8
	// Line 1850, Address: 0x1c37fc, Func Offset: 0x3cc
	// Line 1845, Address: 0x1c3804, Func Offset: 0x3d4
	// Line 1846, Address: 0x1c380c, Func Offset: 0x3dc
	// Line 1848, Address: 0x1c3810, Func Offset: 0x3e0
	// Line 1849, Address: 0x1c381c, Func Offset: 0x3ec
	// Line 1850, Address: 0x1c3824, Func Offset: 0x3f4
	// Line 1851, Address: 0x1c3834, Func Offset: 0x404
	// Line 1853, Address: 0x1c3840, Func Offset: 0x410
	// Line 1855, Address: 0x1c3848, Func Offset: 0x418
	// Line 1857, Address: 0x1c385c, Func Offset: 0x42c
	// Line 1860, Address: 0x1c3864, Func Offset: 0x434
	// Line 1863, Address: 0x1c389c, Func Offset: 0x46c
	// Line 1864, Address: 0x1c38a0, Func Offset: 0x470
	// Line 1863, Address: 0x1c38a4, Func Offset: 0x474
	// Line 1864, Address: 0x1c38ac, Func Offset: 0x47c
	// Line 1865, Address: 0x1c38b8, Func Offset: 0x488
	// Line 1866, Address: 0x1c38c0, Func Offset: 0x490
	// Line 1867, Address: 0x1c38c8, Func Offset: 0x498
	// Line 1868, Address: 0x1c38d0, Func Offset: 0x4a0
	// Line 1871, Address: 0x1c38dc, Func Offset: 0x4ac
	// Line 1872, Address: 0x1c38e8, Func Offset: 0x4b8
	// Line 1873, Address: 0x1c38f0, Func Offset: 0x4c0
	// Line 1877, Address: 0x1c38fc, Func Offset: 0x4cc
	// Line 1879, Address: 0x1c3904, Func Offset: 0x4d4
	// Line 1880, Address: 0x1c3914, Func Offset: 0x4e4
	// Line 1881, Address: 0x1c3934, Func Offset: 0x504
	// Line 1882, Address: 0x1c3938, Func Offset: 0x508
	// Line 1883, Address: 0x1c3940, Func Offset: 0x510
	// Line 1884, Address: 0x1c3964, Func Offset: 0x534
	// Line 1886, Address: 0x1c396c, Func Offset: 0x53c
	// Line 1888, Address: 0x1c3974, Func Offset: 0x544
	// Line 1889, Address: 0x1c3984, Func Offset: 0x554
	// Line 1890, Address: 0x1c3988, Func Offset: 0x558
	// Line 1892, Address: 0x1c398c, Func Offset: 0x55c
	// Line 1890, Address: 0x1c3994, Func Offset: 0x564
	// Line 1892, Address: 0x1c399c, Func Offset: 0x56c
	// Line 1898, Address: 0x1c39a8, Func Offset: 0x578
	// Line 1899, Address: 0x1c39bc, Func Offset: 0x58c
	// Line 1902, Address: 0x1c39c0, Func Offset: 0x590
	// Line 1899, Address: 0x1c39c8, Func Offset: 0x598
	// Line 1902, Address: 0x1c39cc, Func Offset: 0x59c
	// Line 1899, Address: 0x1c39d0, Func Offset: 0x5a0
	// Line 1900, Address: 0x1c39dc, Func Offset: 0x5ac
	// Line 1901, Address: 0x1c39f0, Func Offset: 0x5c0
	// Line 1902, Address: 0x1c3a04, Func Offset: 0x5d4
	// Line 1904, Address: 0x1c3a14, Func Offset: 0x5e4
	// Func End, Address: 0x1c3a2c, Func Offset: 0x5fc
}

// 
// Start address: 0x1c3a30
void bhEne07_DD03(BH_PWORK* epw)
{
	_anon9* mkaP;
	_anon5 trans;
	_anon3* mkfP;
	_anon5 pos;
	// Line 1914, Address: 0x1c3a30, Func Offset: 0
	// Line 1917, Address: 0x1c3a44, Func Offset: 0x14
	// Line 1919, Address: 0x1c3a70, Func Offset: 0x40
	// Line 1921, Address: 0x1c3a78, Func Offset: 0x48
	// Line 1920, Address: 0x1c3a7c, Func Offset: 0x4c
	// Line 1921, Address: 0x1c3a80, Func Offset: 0x50
	// Line 1922, Address: 0x1c3a84, Func Offset: 0x54
	// Line 1924, Address: 0x1c3a8c, Func Offset: 0x5c
	// Line 1925, Address: 0x1c3a94, Func Offset: 0x64
	// Line 1924, Address: 0x1c3a9c, Func Offset: 0x6c
	// Line 1925, Address: 0x1c3aa4, Func Offset: 0x74
	// Line 1927, Address: 0x1c3ab0, Func Offset: 0x80
	// Line 1928, Address: 0x1c3abc, Func Offset: 0x8c
	// Line 1929, Address: 0x1c3ac8, Func Offset: 0x98
	// Line 1930, Address: 0x1c3ad4, Func Offset: 0xa4
	// Line 1931, Address: 0x1c3ae0, Func Offset: 0xb0
	// Line 1942, Address: 0x1c3aec, Func Offset: 0xbc
	// Line 1931, Address: 0x1c3af4, Func Offset: 0xc4
	// Line 1942, Address: 0x1c3af8, Func Offset: 0xc8
	// Line 1931, Address: 0x1c3afc, Func Offset: 0xcc
	// Line 1932, Address: 0x1c3b04, Func Offset: 0xd4
	// Line 1933, Address: 0x1c3b08, Func Offset: 0xd8
	// Line 1936, Address: 0x1c3b14, Func Offset: 0xe4
	// Line 1937, Address: 0x1c3b1c, Func Offset: 0xec
	// Line 1939, Address: 0x1c3b24, Func Offset: 0xf4
	// Line 1942, Address: 0x1c3b40, Func Offset: 0x110
	// Line 1944, Address: 0x1c3b48, Func Offset: 0x118
	// Line 1945, Address: 0x1c3b50, Func Offset: 0x120
	// Line 1948, Address: 0x1c3b5c, Func Offset: 0x12c
	// Line 1953, Address: 0x1c3b6c, Func Offset: 0x13c
	// Line 1954, Address: 0x1c3b80, Func Offset: 0x150
	// Line 1958, Address: 0x1c3b84, Func Offset: 0x154
	// Line 1965, Address: 0x1c3b88, Func Offset: 0x158
	// Line 1966, Address: 0x1c3b8c, Func Offset: 0x15c
	// Line 1954, Address: 0x1c3b90, Func Offset: 0x160
	// Line 1955, Address: 0x1c3b94, Func Offset: 0x164
	// Line 1968, Address: 0x1c3b98, Func Offset: 0x168
	// Line 1955, Address: 0x1c3b9c, Func Offset: 0x16c
	// Line 1956, Address: 0x1c3ba0, Func Offset: 0x170
	// Line 1958, Address: 0x1c3ba8, Func Offset: 0x178
	// Line 1959, Address: 0x1c3bac, Func Offset: 0x17c
	// Line 1962, Address: 0x1c3bb0, Func Offset: 0x180
	// Line 1963, Address: 0x1c3bb8, Func Offset: 0x188
	// Line 1962, Address: 0x1c3bbc, Func Offset: 0x18c
	// Line 1963, Address: 0x1c3bd0, Func Offset: 0x1a0
	// Line 1962, Address: 0x1c3bdc, Func Offset: 0x1ac
	// Line 1963, Address: 0x1c3be0, Func Offset: 0x1b0
	// Line 1964, Address: 0x1c3be8, Func Offset: 0x1b8
	// Line 1965, Address: 0x1c3bf0, Func Offset: 0x1c0
	// Line 1966, Address: 0x1c3bf8, Func Offset: 0x1c8
	// Line 1968, Address: 0x1c3bfc, Func Offset: 0x1cc
	// Line 1969, Address: 0x1c3c04, Func Offset: 0x1d4
	// Line 1970, Address: 0x1c3c10, Func Offset: 0x1e0
	// Line 1972, Address: 0x1c3c20, Func Offset: 0x1f0
	// Line 1979, Address: 0x1c3c28, Func Offset: 0x1f8
	// Line 1972, Address: 0x1c3c2c, Func Offset: 0x1fc
	// Line 1973, Address: 0x1c3c34, Func Offset: 0x204
	// Line 1974, Address: 0x1c3c44, Func Offset: 0x214
	// Line 1976, Address: 0x1c3c54, Func Offset: 0x224
	// Line 1979, Address: 0x1c3c60, Func Offset: 0x230
	// Line 1983, Address: 0x1c3c6c, Func Offset: 0x23c
	// Line 1988, Address: 0x1c3c80, Func Offset: 0x250
	// Line 1989, Address: 0x1c3c88, Func Offset: 0x258
	// Line 1990, Address: 0x1c3c8c, Func Offset: 0x25c
	// Line 1993, Address: 0x1c3c90, Func Offset: 0x260
	// Line 1988, Address: 0x1c3c94, Func Offset: 0x264
	// Line 1989, Address: 0x1c3ca8, Func Offset: 0x278
	// Line 1988, Address: 0x1c3cb4, Func Offset: 0x284
	// Line 1989, Address: 0x1c3cb8, Func Offset: 0x288
	// Line 1990, Address: 0x1c3cc0, Func Offset: 0x290
	// Line 1993, Address: 0x1c3ccc, Func Offset: 0x29c
	// Line 1994, Address: 0x1c3cd8, Func Offset: 0x2a8
	// Line 1995, Address: 0x1c3ce0, Func Offset: 0x2b0
	// Line 1997, Address: 0x1c3d44, Func Offset: 0x314
	// Line 1996, Address: 0x1c3d48, Func Offset: 0x318
	// Line 1997, Address: 0x1c3d4c, Func Offset: 0x31c
	// Line 1998, Address: 0x1c3d50, Func Offset: 0x320
	// Line 1999, Address: 0x1c3d54, Func Offset: 0x324
	// Line 2000, Address: 0x1c3d5c, Func Offset: 0x32c
	// Line 2001, Address: 0x1c3db4, Func Offset: 0x384
	// Line 2002, Address: 0x1c3db8, Func Offset: 0x388
	// Line 2005, Address: 0x1c3dbc, Func Offset: 0x38c
	// Line 2007, Address: 0x1c3dd0, Func Offset: 0x3a0
	// Line 2011, Address: 0x1c3dd4, Func Offset: 0x3a4
	// Line 2007, Address: 0x1c3ddc, Func Offset: 0x3ac
	// Line 2008, Address: 0x1c3de0, Func Offset: 0x3b0
	// Line 2007, Address: 0x1c3de4, Func Offset: 0x3b4
	// Line 2010, Address: 0x1c3df8, Func Offset: 0x3c8
	// Line 2012, Address: 0x1c3dfc, Func Offset: 0x3cc
	// Line 2007, Address: 0x1c3e04, Func Offset: 0x3d4
	// Line 2008, Address: 0x1c3e0c, Func Offset: 0x3dc
	// Line 2010, Address: 0x1c3e10, Func Offset: 0x3e0
	// Line 2011, Address: 0x1c3e1c, Func Offset: 0x3ec
	// Line 2012, Address: 0x1c3e24, Func Offset: 0x3f4
	// Line 2013, Address: 0x1c3e34, Func Offset: 0x404
	// Line 2015, Address: 0x1c3e40, Func Offset: 0x410
	// Line 2017, Address: 0x1c3e48, Func Offset: 0x418
	// Line 2019, Address: 0x1c3e5c, Func Offset: 0x42c
	// Line 2022, Address: 0x1c3e64, Func Offset: 0x434
	// Line 2025, Address: 0x1c3e9c, Func Offset: 0x46c
	// Line 2026, Address: 0x1c3ea0, Func Offset: 0x470
	// Line 2025, Address: 0x1c3ea4, Func Offset: 0x474
	// Line 2026, Address: 0x1c3eac, Func Offset: 0x47c
	// Line 2027, Address: 0x1c3eb8, Func Offset: 0x488
	// Line 2028, Address: 0x1c3ec0, Func Offset: 0x490
	// Line 2029, Address: 0x1c3ec8, Func Offset: 0x498
	// Line 2030, Address: 0x1c3ed0, Func Offset: 0x4a0
	// Line 2033, Address: 0x1c3edc, Func Offset: 0x4ac
	// Line 2034, Address: 0x1c3ee8, Func Offset: 0x4b8
	// Line 2035, Address: 0x1c3ef0, Func Offset: 0x4c0
	// Line 2039, Address: 0x1c3efc, Func Offset: 0x4cc
	// Line 2041, Address: 0x1c3f04, Func Offset: 0x4d4
	// Line 2042, Address: 0x1c3f14, Func Offset: 0x4e4
	// Line 2043, Address: 0x1c3f34, Func Offset: 0x504
	// Line 2044, Address: 0x1c3f38, Func Offset: 0x508
	// Line 2045, Address: 0x1c3f40, Func Offset: 0x510
	// Line 2046, Address: 0x1c3f64, Func Offset: 0x534
	// Line 2048, Address: 0x1c3f6c, Func Offset: 0x53c
	// Line 2050, Address: 0x1c3f74, Func Offset: 0x544
	// Line 2051, Address: 0x1c3f84, Func Offset: 0x554
	// Line 2052, Address: 0x1c3f88, Func Offset: 0x558
	// Line 2054, Address: 0x1c3f8c, Func Offset: 0x55c
	// Line 2052, Address: 0x1c3f94, Func Offset: 0x564
	// Line 2054, Address: 0x1c3f9c, Func Offset: 0x56c
	// Line 2060, Address: 0x1c3fa8, Func Offset: 0x578
	// Line 2061, Address: 0x1c3fbc, Func Offset: 0x58c
	// Line 2064, Address: 0x1c3fc0, Func Offset: 0x590
	// Line 2061, Address: 0x1c3fc8, Func Offset: 0x598
	// Line 2064, Address: 0x1c3fcc, Func Offset: 0x59c
	// Line 2061, Address: 0x1c3fd0, Func Offset: 0x5a0
	// Line 2062, Address: 0x1c3fdc, Func Offset: 0x5ac
	// Line 2063, Address: 0x1c3ff0, Func Offset: 0x5c0
	// Line 2064, Address: 0x1c4004, Func Offset: 0x5d4
	// Line 2066, Address: 0x1c4014, Func Offset: 0x5e4
	// Func End, Address: 0x1c402c, Func Offset: 0x5fc
}

// 
// Start address: 0x1c4030
void bhEne07_DD04(BH_PWORK* epw)
{
	_anon5 trans;
	_anon3* mkfP;
	_anon5 pos;
	// Line 2076, Address: 0x1c4030, Func Offset: 0
	// Line 2079, Address: 0x1c4044, Func Offset: 0x14
	// Line 2081, Address: 0x1c4088, Func Offset: 0x58
	// Line 2083, Address: 0x1c4090, Func Offset: 0x60
	// Line 2082, Address: 0x1c4094, Func Offset: 0x64
	// Line 2083, Address: 0x1c4098, Func Offset: 0x68
	// Line 2084, Address: 0x1c409c, Func Offset: 0x6c
	// Line 2086, Address: 0x1c40a4, Func Offset: 0x74
	// Line 2087, Address: 0x1c40ac, Func Offset: 0x7c
	// Line 2096, Address: 0x1c40b4, Func Offset: 0x84
	// Line 2086, Address: 0x1c40b8, Func Offset: 0x88
	// Line 2087, Address: 0x1c40c0, Func Offset: 0x90
	// Line 2096, Address: 0x1c40c4, Func Offset: 0x94
	// Line 2087, Address: 0x1c40c8, Func Offset: 0x98
	// Line 2089, Address: 0x1c40d0, Func Offset: 0xa0
	// Line 2090, Address: 0x1c40d8, Func Offset: 0xa8
	// Line 2091, Address: 0x1c40e0, Func Offset: 0xb0
	// Line 2093, Address: 0x1c40e8, Func Offset: 0xb8
	// Line 2096, Address: 0x1c4104, Func Offset: 0xd4
	// Line 2098, Address: 0x1c410c, Func Offset: 0xdc
	// Line 2101, Address: 0x1c4118, Func Offset: 0xe8
	// Line 2102, Address: 0x1c4120, Func Offset: 0xf0
	// Line 2101, Address: 0x1c4128, Func Offset: 0xf8
	// Line 2102, Address: 0x1c4140, Func Offset: 0x110
	// Line 2103, Address: 0x1c415c, Func Offset: 0x12c
	// Line 2106, Address: 0x1c4178, Func Offset: 0x148
	// Line 2111, Address: 0x1c4188, Func Offset: 0x158
	// Line 2112, Address: 0x1c419c, Func Offset: 0x16c
	// Line 2116, Address: 0x1c41a0, Func Offset: 0x170
	// Line 2123, Address: 0x1c41a4, Func Offset: 0x174
	// Line 2124, Address: 0x1c41a8, Func Offset: 0x178
	// Line 2112, Address: 0x1c41ac, Func Offset: 0x17c
	// Line 2113, Address: 0x1c41b0, Func Offset: 0x180
	// Line 2126, Address: 0x1c41b4, Func Offset: 0x184
	// Line 2113, Address: 0x1c41b8, Func Offset: 0x188
	// Line 2114, Address: 0x1c41bc, Func Offset: 0x18c
	// Line 2116, Address: 0x1c41c4, Func Offset: 0x194
	// Line 2117, Address: 0x1c41c8, Func Offset: 0x198
	// Line 2120, Address: 0x1c41cc, Func Offset: 0x19c
	// Line 2121, Address: 0x1c41d4, Func Offset: 0x1a4
	// Line 2120, Address: 0x1c41d8, Func Offset: 0x1a8
	// Line 2121, Address: 0x1c41ec, Func Offset: 0x1bc
	// Line 2120, Address: 0x1c41f8, Func Offset: 0x1c8
	// Line 2121, Address: 0x1c41fc, Func Offset: 0x1cc
	// Line 2122, Address: 0x1c4204, Func Offset: 0x1d4
	// Line 2123, Address: 0x1c420c, Func Offset: 0x1dc
	// Line 2124, Address: 0x1c4214, Func Offset: 0x1e4
	// Line 2126, Address: 0x1c4218, Func Offset: 0x1e8
	// Line 2127, Address: 0x1c4220, Func Offset: 0x1f0
	// Line 2128, Address: 0x1c422c, Func Offset: 0x1fc
	// Line 2130, Address: 0x1c423c, Func Offset: 0x20c
	// Line 2137, Address: 0x1c4244, Func Offset: 0x214
	// Line 2130, Address: 0x1c4248, Func Offset: 0x218
	// Line 2131, Address: 0x1c4250, Func Offset: 0x220
	// Line 2132, Address: 0x1c4260, Func Offset: 0x230
	// Line 2134, Address: 0x1c4270, Func Offset: 0x240
	// Line 2137, Address: 0x1c427c, Func Offset: 0x24c
	// Line 2139, Address: 0x1c4284, Func Offset: 0x254
	// Line 2142, Address: 0x1c428c, Func Offset: 0x25c
	// Line 2143, Address: 0x1c42a0, Func Offset: 0x270
	// Line 2144, Address: 0x1c42a8, Func Offset: 0x278
	// Line 2145, Address: 0x1c42ac, Func Offset: 0x27c
	// Line 2146, Address: 0x1c42b0, Func Offset: 0x280
	// Line 2149, Address: 0x1c42b4, Func Offset: 0x284
	// Line 2146, Address: 0x1c42bc, Func Offset: 0x28c
	// Line 2149, Address: 0x1c42c0, Func Offset: 0x290
	// Line 2146, Address: 0x1c42c4, Func Offset: 0x294
	// Line 2147, Address: 0x1c42e0, Func Offset: 0x2b0
	// Line 2149, Address: 0x1c42e8, Func Offset: 0x2b8
	// Line 2151, Address: 0x1c42f0, Func Offset: 0x2c0
	// Line 2152, Address: 0x1c42f8, Func Offset: 0x2c8
	// Line 2153, Address: 0x1c42fc, Func Offset: 0x2cc
	// Line 2152, Address: 0x1c4304, Func Offset: 0x2d4
	// Line 2153, Address: 0x1c4308, Func Offset: 0x2d8
	// Line 2152, Address: 0x1c430c, Func Offset: 0x2dc
	// Line 2153, Address: 0x1c4318, Func Offset: 0x2e8
	// Line 2155, Address: 0x1c4324, Func Offset: 0x2f4
	// Line 2157, Address: 0x1c432c, Func Offset: 0x2fc
	// Line 2158, Address: 0x1c433c, Func Offset: 0x30c
	// Line 2159, Address: 0x1c4344, Func Offset: 0x314
	// Line 2160, Address: 0x1c4348, Func Offset: 0x318
	// Line 2161, Address: 0x1c4350, Func Offset: 0x320
	// Line 2162, Address: 0x1c4374, Func Offset: 0x344
	// Line 2164, Address: 0x1c437c, Func Offset: 0x34c
	// Line 2166, Address: 0x1c4384, Func Offset: 0x354
	// Line 2167, Address: 0x1c4394, Func Offset: 0x364
	// Line 2168, Address: 0x1c4398, Func Offset: 0x368
	// Line 2170, Address: 0x1c439c, Func Offset: 0x36c
	// Line 2168, Address: 0x1c43a4, Func Offset: 0x374
	// Line 2170, Address: 0x1c43ac, Func Offset: 0x37c
	// Line 2174, Address: 0x1c43b8, Func Offset: 0x388
	// Func End, Address: 0x1c43d0, Func Offset: 0x3a0
}

// 
// Start address: 0x1c43d0
void bhEne07_DD05(BH_PWORK* epw)
{
	_anon5 trans;
	_anon3* mkfP;
	_anon5 pos;
	// Line 2184, Address: 0x1c43d0, Func Offset: 0
	// Line 2187, Address: 0x1c43e4, Func Offset: 0x14
	// Line 2189, Address: 0x1c4428, Func Offset: 0x58
	// Line 2191, Address: 0x1c4430, Func Offset: 0x60
	// Line 2190, Address: 0x1c4434, Func Offset: 0x64
	// Line 2191, Address: 0x1c4438, Func Offset: 0x68
	// Line 2192, Address: 0x1c443c, Func Offset: 0x6c
	// Line 2194, Address: 0x1c4444, Func Offset: 0x74
	// Line 2195, Address: 0x1c444c, Func Offset: 0x7c
	// Line 2204, Address: 0x1c4454, Func Offset: 0x84
	// Line 2194, Address: 0x1c4458, Func Offset: 0x88
	// Line 2195, Address: 0x1c4460, Func Offset: 0x90
	// Line 2204, Address: 0x1c4464, Func Offset: 0x94
	// Line 2195, Address: 0x1c4468, Func Offset: 0x98
	// Line 2197, Address: 0x1c4470, Func Offset: 0xa0
	// Line 2198, Address: 0x1c4478, Func Offset: 0xa8
	// Line 2199, Address: 0x1c4480, Func Offset: 0xb0
	// Line 2201, Address: 0x1c4488, Func Offset: 0xb8
	// Line 2204, Address: 0x1c44a4, Func Offset: 0xd4
	// Line 2206, Address: 0x1c44ac, Func Offset: 0xdc
	// Line 2209, Address: 0x1c44b8, Func Offset: 0xe8
	// Line 2210, Address: 0x1c44c0, Func Offset: 0xf0
	// Line 2209, Address: 0x1c44c8, Func Offset: 0xf8
	// Line 2210, Address: 0x1c44e0, Func Offset: 0x110
	// Line 2211, Address: 0x1c44fc, Func Offset: 0x12c
	// Line 2214, Address: 0x1c4518, Func Offset: 0x148
	// Line 2219, Address: 0x1c4528, Func Offset: 0x158
	// Line 2220, Address: 0x1c453c, Func Offset: 0x16c
	// Line 2224, Address: 0x1c4540, Func Offset: 0x170
	// Line 2231, Address: 0x1c4544, Func Offset: 0x174
	// Line 2232, Address: 0x1c4548, Func Offset: 0x178
	// Line 2220, Address: 0x1c454c, Func Offset: 0x17c
	// Line 2221, Address: 0x1c4550, Func Offset: 0x180
	// Line 2234, Address: 0x1c4554, Func Offset: 0x184
	// Line 2221, Address: 0x1c4558, Func Offset: 0x188
	// Line 2222, Address: 0x1c455c, Func Offset: 0x18c
	// Line 2224, Address: 0x1c4564, Func Offset: 0x194
	// Line 2225, Address: 0x1c4568, Func Offset: 0x198
	// Line 2228, Address: 0x1c456c, Func Offset: 0x19c
	// Line 2229, Address: 0x1c4574, Func Offset: 0x1a4
	// Line 2228, Address: 0x1c4578, Func Offset: 0x1a8
	// Line 2229, Address: 0x1c458c, Func Offset: 0x1bc
	// Line 2228, Address: 0x1c4598, Func Offset: 0x1c8
	// Line 2229, Address: 0x1c459c, Func Offset: 0x1cc
	// Line 2230, Address: 0x1c45a4, Func Offset: 0x1d4
	// Line 2231, Address: 0x1c45ac, Func Offset: 0x1dc
	// Line 2232, Address: 0x1c45b4, Func Offset: 0x1e4
	// Line 2234, Address: 0x1c45b8, Func Offset: 0x1e8
	// Line 2235, Address: 0x1c45c0, Func Offset: 0x1f0
	// Line 2236, Address: 0x1c45cc, Func Offset: 0x1fc
	// Line 2238, Address: 0x1c45dc, Func Offset: 0x20c
	// Line 2245, Address: 0x1c45e4, Func Offset: 0x214
	// Line 2238, Address: 0x1c45e8, Func Offset: 0x218
	// Line 2239, Address: 0x1c45f0, Func Offset: 0x220
	// Line 2240, Address: 0x1c4600, Func Offset: 0x230
	// Line 2242, Address: 0x1c4610, Func Offset: 0x240
	// Line 2245, Address: 0x1c461c, Func Offset: 0x24c
	// Line 2247, Address: 0x1c4624, Func Offset: 0x254
	// Line 2250, Address: 0x1c462c, Func Offset: 0x25c
	// Line 2251, Address: 0x1c4640, Func Offset: 0x270
	// Line 2252, Address: 0x1c4648, Func Offset: 0x278
	// Line 2253, Address: 0x1c464c, Func Offset: 0x27c
	// Line 2254, Address: 0x1c4650, Func Offset: 0x280
	// Line 2257, Address: 0x1c4654, Func Offset: 0x284
	// Line 2254, Address: 0x1c465c, Func Offset: 0x28c
	// Line 2257, Address: 0x1c4660, Func Offset: 0x290
	// Line 2254, Address: 0x1c4664, Func Offset: 0x294
	// Line 2255, Address: 0x1c4680, Func Offset: 0x2b0
	// Line 2257, Address: 0x1c4688, Func Offset: 0x2b8
	// Line 2259, Address: 0x1c4690, Func Offset: 0x2c0
	// Line 2260, Address: 0x1c4698, Func Offset: 0x2c8
	// Line 2261, Address: 0x1c469c, Func Offset: 0x2cc
	// Line 2260, Address: 0x1c46a4, Func Offset: 0x2d4
	// Line 2261, Address: 0x1c46a8, Func Offset: 0x2d8
	// Line 2260, Address: 0x1c46ac, Func Offset: 0x2dc
	// Line 2261, Address: 0x1c46b8, Func Offset: 0x2e8
	// Line 2263, Address: 0x1c46c4, Func Offset: 0x2f4
	// Line 2265, Address: 0x1c46cc, Func Offset: 0x2fc
	// Line 2266, Address: 0x1c46dc, Func Offset: 0x30c
	// Line 2267, Address: 0x1c46e4, Func Offset: 0x314
	// Line 2268, Address: 0x1c46e8, Func Offset: 0x318
	// Line 2269, Address: 0x1c46f0, Func Offset: 0x320
	// Line 2270, Address: 0x1c4714, Func Offset: 0x344
	// Line 2272, Address: 0x1c471c, Func Offset: 0x34c
	// Line 2274, Address: 0x1c4724, Func Offset: 0x354
	// Line 2275, Address: 0x1c4734, Func Offset: 0x364
	// Line 2276, Address: 0x1c4738, Func Offset: 0x368
	// Line 2278, Address: 0x1c473c, Func Offset: 0x36c
	// Line 2276, Address: 0x1c4744, Func Offset: 0x374
	// Line 2278, Address: 0x1c474c, Func Offset: 0x37c
	// Line 2282, Address: 0x1c4758, Func Offset: 0x388
	// Func End, Address: 0x1c4770, Func Offset: 0x3a0
}

// 
// Start address: 0x1c4770
void bhEne07_DD06(BH_PWORK* epw)
{
	// Line 2292, Address: 0x1c4770, Func Offset: 0
	// Line 2293, Address: 0x1c477c, Func Offset: 0xc
	// Line 2299, Address: 0x1c4790, Func Offset: 0x20
	// Line 2305, Address: 0x1c4794, Func Offset: 0x24
	// Line 2299, Address: 0x1c479c, Func Offset: 0x2c
	// Line 2302, Address: 0x1c47ac, Func Offset: 0x3c
	// Line 2305, Address: 0x1c47b4, Func Offset: 0x44
	// Line 2308, Address: 0x1c47bc, Func Offset: 0x4c
	// Line 2310, Address: 0x1c47c8, Func Offset: 0x58
	// Line 2311, Address: 0x1c47cc, Func Offset: 0x5c
	// Line 2313, Address: 0x1c47d8, Func Offset: 0x68
	// Func End, Address: 0x1c47e8, Func Offset: 0x78
}

// 
// Start address: 0x1c47f0
void bhEne07_SearchPlayer(BH_PWORK* epw)
{
	_anon5 pos;
	float dz;
	float dx;
	// Line 2323, Address: 0x1c47f0, Func Offset: 0
	// Line 2327, Address: 0x1c47fc, Func Offset: 0xc
	// Line 2329, Address: 0x1c4808, Func Offset: 0x18
	// Line 2332, Address: 0x1c480c, Func Offset: 0x1c
	// Line 2327, Address: 0x1c4810, Func Offset: 0x20
	// Line 2329, Address: 0x1c4814, Func Offset: 0x24
	// Line 2332, Address: 0x1c4818, Func Offset: 0x28
	// Line 2329, Address: 0x1c481c, Func Offset: 0x2c
	// Line 2330, Address: 0x1c4824, Func Offset: 0x34
	// Line 2331, Address: 0x1c482c, Func Offset: 0x3c
	// Line 2332, Address: 0x1c4830, Func Offset: 0x40
	// Line 2333, Address: 0x1c4840, Func Offset: 0x50
	// Line 2337, Address: 0x1c4848, Func Offset: 0x58
	// Line 2338, Address: 0x1c4854, Func Offset: 0x64
	// Line 2337, Address: 0x1c4858, Func Offset: 0x68
	// Line 2338, Address: 0x1c485c, Func Offset: 0x6c
	// Line 2337, Address: 0x1c4860, Func Offset: 0x70
	// Line 2338, Address: 0x1c4864, Func Offset: 0x74
	// Line 2339, Address: 0x1c4868, Func Offset: 0x78
	// Line 2340, Address: 0x1c487c, Func Offset: 0x8c
	// Func End, Address: 0x1c488c, Func Offset: 0x9c
}

// 
// Start address: 0x1c4890
void bhEne07_CollisionWalls(BH_PWORK* epw)
{
	_anon5 ofp;
	// Line 2350, Address: 0x1c4890, Func Offset: 0
	// Line 2354, Address: 0x1c48a0, Func Offset: 0x10
	// Line 2356, Address: 0x1c48b0, Func Offset: 0x20
	// Line 2357, Address: 0x1c48b8, Func Offset: 0x28
	// Line 2358, Address: 0x1c48bc, Func Offset: 0x2c
	// Line 2359, Address: 0x1c48c0, Func Offset: 0x30
	// Line 2356, Address: 0x1c48c4, Func Offset: 0x34
	// Line 2357, Address: 0x1c48cc, Func Offset: 0x3c
	// Line 2358, Address: 0x1c48dc, Func Offset: 0x4c
	// Line 2359, Address: 0x1c48e8, Func Offset: 0x58
	// Line 2360, Address: 0x1c48f0, Func Offset: 0x60
	// Line 2361, Address: 0x1c4900, Func Offset: 0x70
	// Line 2362, Address: 0x1c4910, Func Offset: 0x80
	// Line 2363, Address: 0x1c4920, Func Offset: 0x90
	// Func End, Address: 0x1c4938, Func Offset: 0xa8
}

// 
// Start address: 0x1c4940
void bhEne07_FloorCollision(BH_PWORK* epw)
{
	_anon29* hp;
	_anon5 n;
	// Line 2373, Address: 0x1c4940, Func Offset: 0
	// Line 2380, Address: 0x1c4950, Func Offset: 0x10
	// Line 2381, Address: 0x1c496c, Func Offset: 0x2c
	// Line 2382, Address: 0x1c4974, Func Offset: 0x34
	// Line 2383, Address: 0x1c497c, Func Offset: 0x3c
	// Line 2384, Address: 0x1c49a4, Func Offset: 0x64
	// Line 2385, Address: 0x1c49b8, Func Offset: 0x78
	// Line 2387, Address: 0x1c49c0, Func Offset: 0x80
	// Line 2389, Address: 0x1c49e4, Func Offset: 0xa4
	// Line 2391, Address: 0x1c49ec, Func Offset: 0xac
	// Line 2393, Address: 0x1c4a08, Func Offset: 0xc8
	// Line 2394, Address: 0x1c4a10, Func Offset: 0xd0
	// Line 2395, Address: 0x1c4a18, Func Offset: 0xd8
	// Line 2398, Address: 0x1c4a20, Func Offset: 0xe0
	// Func End, Address: 0x1c4a34, Func Offset: 0xf4
}

// 
// Start address: 0x1c4a40
int bhEne07_CheckLeaningWall()
{
	// Line 2453, Address: 0x1c4a40, Func Offset: 0
	// Func End, Address: 0x1c4a48, Func Offset: 0x8
}

// 
// Start address: 0x1c4a50
int bhEne07_CheckHangingWall(BH_PWORK* epw)
{
	int i;
	float dist;
	BH_PWORK* ep;
	_anon3* mkfP;
	_anon29* hp;
	_anon5 pos2;
	_anon5 pos;
	_anon5 n;
	_anon5 vec;
	// Line 2463, Address: 0x1c4a50, Func Offset: 0
	// Line 2473, Address: 0x1c4a74, Func Offset: 0x24
	// Line 2472, Address: 0x1c4a78, Func Offset: 0x28
	// Line 2473, Address: 0x1c4a7c, Func Offset: 0x2c
	// Line 2474, Address: 0x1c4a88, Func Offset: 0x38
	// Line 2476, Address: 0x1c4a94, Func Offset: 0x44
	// Line 2477, Address: 0x1c4a9c, Func Offset: 0x4c
	// Line 2478, Address: 0x1c4aa8, Func Offset: 0x58
	// Line 2479, Address: 0x1c4ab8, Func Offset: 0x68
	// Line 2484, Address: 0x1c4ac0, Func Offset: 0x70
	// Line 2480, Address: 0x1c4ac4, Func Offset: 0x74
	// Line 2481, Address: 0x1c4ac8, Func Offset: 0x78
	// Line 2479, Address: 0x1c4acc, Func Offset: 0x7c
	// Line 2484, Address: 0x1c4ad0, Func Offset: 0x80
	// Line 2479, Address: 0x1c4ad8, Func Offset: 0x88
	// Line 2480, Address: 0x1c4adc, Func Offset: 0x8c
	// Line 2481, Address: 0x1c4aec, Func Offset: 0x9c
	// Line 2484, Address: 0x1c4af8, Func Offset: 0xa8
	// Line 2485, Address: 0x1c4b00, Func Offset: 0xb0
	// Line 2486, Address: 0x1c4b28, Func Offset: 0xd8
	// Line 2487, Address: 0x1c4b34, Func Offset: 0xe4
	// Line 2488, Address: 0x1c4b50, Func Offset: 0x100
	// Line 2491, Address: 0x1c4b58, Func Offset: 0x108
	// Line 2493, Address: 0x1c4b80, Func Offset: 0x130
	// Line 2494, Address: 0x1c4b90, Func Offset: 0x140
	// Line 2495, Address: 0x1c4bb8, Func Offset: 0x168
	// Line 2496, Address: 0x1c4bc0, Func Offset: 0x170
	// Line 2498, Address: 0x1c4bc8, Func Offset: 0x178
	// Line 2500, Address: 0x1c4bec, Func Offset: 0x19c
	// Line 2501, Address: 0x1c4bf0, Func Offset: 0x1a0
	// Line 2503, Address: 0x1c4bfc, Func Offset: 0x1ac
	// Line 2500, Address: 0x1c4c00, Func Offset: 0x1b0
	// Line 2501, Address: 0x1c4c04, Func Offset: 0x1b4
	// Line 2503, Address: 0x1c4c08, Func Offset: 0x1b8
	// Line 2501, Address: 0x1c4c18, Func Offset: 0x1c8
	// Line 2502, Address: 0x1c4c20, Func Offset: 0x1d0
	// Line 2503, Address: 0x1c4c24, Func Offset: 0x1d4
	// Line 2505, Address: 0x1c4c34, Func Offset: 0x1e4
	// Line 2511, Address: 0x1c4c38, Func Offset: 0x1e8
	// Line 2505, Address: 0x1c4c3c, Func Offset: 0x1ec
	// Line 2506, Address: 0x1c4c40, Func Offset: 0x1f0
	// Line 2505, Address: 0x1c4c44, Func Offset: 0x1f4
	// Line 2506, Address: 0x1c4c48, Func Offset: 0x1f8
	// Line 2508, Address: 0x1c4c5c, Func Offset: 0x20c
	// Line 2509, Address: 0x1c4c64, Func Offset: 0x214
	// Line 2510, Address: 0x1c4c6c, Func Offset: 0x21c
	// Line 2511, Address: 0x1c4c70, Func Offset: 0x220
	// Line 2512, Address: 0x1c4c78, Func Offset: 0x228
	// Line 2513, Address: 0x1c4c84, Func Offset: 0x234
	// Line 2515, Address: 0x1c4c94, Func Offset: 0x244
	// Line 2521, Address: 0x1c4ca0, Func Offset: 0x250
	// Line 2515, Address: 0x1c4ca4, Func Offset: 0x254
	// Line 2516, Address: 0x1c4cac, Func Offset: 0x25c
	// Line 2517, Address: 0x1c4cc0, Func Offset: 0x270
	// Line 2518, Address: 0x1c4cd4, Func Offset: 0x284
	// Line 2519, Address: 0x1c4cdc, Func Offset: 0x28c
	// Line 2521, Address: 0x1c4ce0, Func Offset: 0x290
	// Line 2526, Address: 0x1c4ce8, Func Offset: 0x298
	// Line 2527, Address: 0x1c4cec, Func Offset: 0x29c
	// Func End, Address: 0x1c4d14, Func Offset: 0x2c4
}

// 
// Start address: 0x1c4d20
int bhEne07_AvoidWall(BH_PWORK* epw, int dir)
{
	npobj* objP;
	_anon9* mkaP;
	float dist;
	float dz;
	float dx;
	float wdist;
	float dist;
	BH_PWORK* ep2;
	BH_PWORK* ep;
	int i;
	_anon5 trans;
	_anon5 vdB;
	_anon5 body;
	_anon29* hp2;
	_anon29* hp1;
	_anon5 pos2;
	_anon5 pos1;
	// Line 2538, Address: 0x1c4d20, Func Offset: 0
	// Line 2551, Address: 0x1c4d4c, Func Offset: 0x2c
	// Line 2538, Address: 0x1c4d54, Func Offset: 0x34
	// Line 2550, Address: 0x1c4d60, Func Offset: 0x40
	// Line 2551, Address: 0x1c4d64, Func Offset: 0x44
	// Line 2552, Address: 0x1c4d6c, Func Offset: 0x4c
	// Line 2553, Address: 0x1c4d74, Func Offset: 0x54
	// Line 2554, Address: 0x1c4da0, Func Offset: 0x80
	// Line 2555, Address: 0x1c4dac, Func Offset: 0x8c
	// Line 2556, Address: 0x1c4dc8, Func Offset: 0xa8
	// Line 2557, Address: 0x1c4dcc, Func Offset: 0xac
	// Line 2560, Address: 0x1c4dd0, Func Offset: 0xb0
	// Line 2561, Address: 0x1c4df8, Func Offset: 0xd8
	// Line 2562, Address: 0x1c4e48, Func Offset: 0x128
	// Line 2563, Address: 0x1c4e60, Func Offset: 0x140
	// Line 2564, Address: 0x1c4e74, Func Offset: 0x154
	// Line 2565, Address: 0x1c4e7c, Func Offset: 0x15c
	// Line 2575, Address: 0x1c4e94, Func Offset: 0x174
	// Line 2576, Address: 0x1c4ea4, Func Offset: 0x184
	// Line 2578, Address: 0x1c4ee4, Func Offset: 0x1c4
	// Line 2579, Address: 0x1c4f04, Func Offset: 0x1e4
	// Line 2578, Address: 0x1c4f08, Func Offset: 0x1e8
	// Line 2579, Address: 0x1c4f10, Func Offset: 0x1f0
	// Line 2580, Address: 0x1c4f38, Func Offset: 0x218
	// Line 2579, Address: 0x1c4f3c, Func Offset: 0x21c
	// Line 2580, Address: 0x1c4f40, Func Offset: 0x220
	// Line 2581, Address: 0x1c4f48, Func Offset: 0x228
	// Line 2582, Address: 0x1c4f64, Func Offset: 0x244
	// Line 2587, Address: 0x1c4f84, Func Offset: 0x264
	// Line 2588, Address: 0x1c4f8c, Func Offset: 0x26c
	// Line 2594, Address: 0x1c4fbc, Func Offset: 0x29c
	// Line 2595, Address: 0x1c4fc4, Func Offset: 0x2a4
	// Line 2596, Address: 0x1c4fd0, Func Offset: 0x2b0
	// Line 2597, Address: 0x1c4fe4, Func Offset: 0x2c4
	// Line 2598, Address: 0x1c4fec, Func Offset: 0x2cc
	// Line 2597, Address: 0x1c4ff0, Func Offset: 0x2d0
	// Line 2598, Address: 0x1c5004, Func Offset: 0x2e4
	// Line 2597, Address: 0x1c5010, Func Offset: 0x2f0
	// Line 2598, Address: 0x1c5014, Func Offset: 0x2f4
	// Line 2599, Address: 0x1c501c, Func Offset: 0x2fc
	// Line 2602, Address: 0x1c5030, Func Offset: 0x310
	// Line 2607, Address: 0x1c5040, Func Offset: 0x320
	// Line 2610, Address: 0x1c5044, Func Offset: 0x324
	// Line 2614, Address: 0x1c5048, Func Offset: 0x328
	// Line 2607, Address: 0x1c504c, Func Offset: 0x32c
	// Line 2609, Address: 0x1c5050, Func Offset: 0x330
	// Line 2610, Address: 0x1c5058, Func Offset: 0x338
	// Line 2611, Address: 0x1c5060, Func Offset: 0x340
	// Line 2614, Address: 0x1c506c, Func Offset: 0x34c
	// Line 2616, Address: 0x1c5080, Func Offset: 0x360
	// Line 2617, Address: 0x1c508c, Func Offset: 0x36c
	// Line 2618, Address: 0x1c5098, Func Offset: 0x378
	// Line 2623, Address: 0x1c50a8, Func Offset: 0x388
	// Line 2624, Address: 0x1c50b4, Func Offset: 0x394
	// Line 2627, Address: 0x1c50b8, Func Offset: 0x398
	// Line 2624, Address: 0x1c50bc, Func Offset: 0x39c
	// Line 2623, Address: 0x1c50c0, Func Offset: 0x3a0
	// Line 2625, Address: 0x1c50c4, Func Offset: 0x3a4
	// Line 2627, Address: 0x1c50c8, Func Offset: 0x3a8
	// Line 2623, Address: 0x1c50cc, Func Offset: 0x3ac
	// Line 2628, Address: 0x1c50d0, Func Offset: 0x3b0
	// Line 2629, Address: 0x1c50d4, Func Offset: 0x3b4
	// Line 2623, Address: 0x1c50d8, Func Offset: 0x3b8
	// Line 2624, Address: 0x1c50dc, Func Offset: 0x3bc
	// Line 2627, Address: 0x1c50e8, Func Offset: 0x3c8
	// Line 2629, Address: 0x1c50ec, Func Offset: 0x3cc
	// Line 2625, Address: 0x1c50f0, Func Offset: 0x3d0
	// Line 2624, Address: 0x1c50f4, Func Offset: 0x3d4
	// Line 2625, Address: 0x1c5100, Func Offset: 0x3e0
	// Line 2626, Address: 0x1c511c, Func Offset: 0x3fc
	// Line 2627, Address: 0x1c5124, Func Offset: 0x404
	// Line 2628, Address: 0x1c5130, Func Offset: 0x410
	// Line 2629, Address: 0x1c5134, Func Offset: 0x414
	// Line 2630, Address: 0x1c5140, Func Offset: 0x420
	// Line 2631, Address: 0x1c5148, Func Offset: 0x428
	// Line 2632, Address: 0x1c5150, Func Offset: 0x430
	// Line 2631, Address: 0x1c5158, Func Offset: 0x438
	// Line 2633, Address: 0x1c515c, Func Offset: 0x43c
	// Line 2631, Address: 0x1c5160, Func Offset: 0x440
	// Line 2632, Address: 0x1c516c, Func Offset: 0x44c
	// Line 2633, Address: 0x1c5188, Func Offset: 0x468
	// Line 2635, Address: 0x1c51a4, Func Offset: 0x484
	// Line 2636, Address: 0x1c51c4, Func Offset: 0x4a4
	// Line 2637, Address: 0x1c51dc, Func Offset: 0x4bc
	// Line 2638, Address: 0x1c51f4, Func Offset: 0x4d4
	// Line 2637, Address: 0x1c51fc, Func Offset: 0x4dc
	// Line 2638, Address: 0x1c5200, Func Offset: 0x4e0
	// Line 2641, Address: 0x1c520c, Func Offset: 0x4ec
	// Line 2645, Address: 0x1c5214, Func Offset: 0x4f4
	// Line 2641, Address: 0x1c521c, Func Offset: 0x4fc
	// Line 2643, Address: 0x1c5220, Func Offset: 0x500
	// Line 2641, Address: 0x1c5224, Func Offset: 0x504
	// Line 2647, Address: 0x1c5228, Func Offset: 0x508
	// Line 2641, Address: 0x1c5230, Func Offset: 0x510
	// Line 2642, Address: 0x1c5238, Func Offset: 0x518
	// Line 2643, Address: 0x1c5250, Func Offset: 0x530
	// Line 2644, Address: 0x1c526c, Func Offset: 0x54c
	// Line 2645, Address: 0x1c5274, Func Offset: 0x554
	// Line 2646, Address: 0x1c5280, Func Offset: 0x560
	// Line 2647, Address: 0x1c5284, Func Offset: 0x564
	// Line 2649, Address: 0x1c528c, Func Offset: 0x56c
	// Line 2650, Address: 0x1c5294, Func Offset: 0x574
	// Line 2651, Address: 0x1c529c, Func Offset: 0x57c
	// Line 2650, Address: 0x1c52a4, Func Offset: 0x584
	// Line 2652, Address: 0x1c52a8, Func Offset: 0x588
	// Line 2650, Address: 0x1c52ac, Func Offset: 0x58c
	// Line 2651, Address: 0x1c52b8, Func Offset: 0x598
	// Line 2652, Address: 0x1c52d4, Func Offset: 0x5b4
	// Line 2654, Address: 0x1c52f0, Func Offset: 0x5d0
	// Line 2655, Address: 0x1c5310, Func Offset: 0x5f0
	// Line 2656, Address: 0x1c5328, Func Offset: 0x608
	// Line 2657, Address: 0x1c5340, Func Offset: 0x620
	// Line 2656, Address: 0x1c5348, Func Offset: 0x628
	// Line 2657, Address: 0x1c534c, Func Offset: 0x62c
	// Line 2660, Address: 0x1c5354, Func Offset: 0x634
	// Line 2661, Address: 0x1c5364, Func Offset: 0x644
	// Line 2662, Address: 0x1c537c, Func Offset: 0x65c
	// Line 2661, Address: 0x1c5380, Func Offset: 0x660
	// Line 2662, Address: 0x1c5384, Func Offset: 0x664
	// Line 2664, Address: 0x1c538c, Func Offset: 0x66c
	// Line 2665, Address: 0x1c539c, Func Offset: 0x67c
	// Line 2666, Address: 0x1c53ac, Func Offset: 0x68c
	// Line 2667, Address: 0x1c53c0, Func Offset: 0x6a0
	// Line 2668, Address: 0x1c53c8, Func Offset: 0x6a8
	// Line 2670, Address: 0x1c53e8, Func Offset: 0x6c8
	// Line 2672, Address: 0x1c5400, Func Offset: 0x6e0
	// Line 2673, Address: 0x1c5410, Func Offset: 0x6f0
	// Line 2674, Address: 0x1c5420, Func Offset: 0x700
	// Line 2675, Address: 0x1c543c, Func Offset: 0x71c
	// Line 2676, Address: 0x1c5444, Func Offset: 0x724
	// Line 2678, Address: 0x1c545c, Func Offset: 0x73c
	// Line 2682, Address: 0x1c5474, Func Offset: 0x754
	// Line 2683, Address: 0x1c5494, Func Offset: 0x774
	// Line 2684, Address: 0x1c54ac, Func Offset: 0x78c
	// Line 2689, Address: 0x1c54c4, Func Offset: 0x7a4
	// Line 2684, Address: 0x1c54d0, Func Offset: 0x7b0
	// Line 2689, Address: 0x1c54d4, Func Offset: 0x7b4
	// Line 2690, Address: 0x1c54e8, Func Offset: 0x7c8
	// Line 2691, Address: 0x1c5500, Func Offset: 0x7e0
	// Line 2690, Address: 0x1c5504, Func Offset: 0x7e4
	// Line 2691, Address: 0x1c5508, Func Offset: 0x7e8
	// Line 2694, Address: 0x1c5510, Func Offset: 0x7f0
	// Line 2695, Address: 0x1c5514, Func Offset: 0x7f4
	// Func End, Address: 0x1c5548, Func Offset: 0x828
}

// 
// Start address: 0x1c5550
void bhEne07_PlayerBloodEffect(BH_PWORK* epw, unsigned char size)
{
	_anon5 v;
	_anon5 pos;
	// Line 2706, Address: 0x1c5550, Func Offset: 0
	// Line 2713, Address: 0x1c5564, Func Offset: 0x14
	// Line 2716, Address: 0x1c55c4, Func Offset: 0x74
	// Line 2719, Address: 0x1c55cc, Func Offset: 0x7c
	// Line 2716, Address: 0x1c55d8, Func Offset: 0x88
	// Line 2719, Address: 0x1c55dc, Func Offset: 0x8c
	// Line 2716, Address: 0x1c55e4, Func Offset: 0x94
	// Line 2717, Address: 0x1c55e8, Func Offset: 0x98
	// Line 2718, Address: 0x1c55f4, Func Offset: 0xa4
	// Line 2719, Address: 0x1c55fc, Func Offset: 0xac
	// Line 2720, Address: 0x1c5604, Func Offset: 0xb4
	// Func End, Address: 0x1c5618, Func Offset: 0xc8
}

// 
// Start address: 0x1c5620
void bhEne07_PlayerControl(BH_PWORK* epw)
{
	unsigned int ply_motion[3][3];
	// Line 2731, Address: 0x1c5620, Func Offset: 0
	// Line 2730, Address: 0x1c5634, Func Offset: 0x14
	// Line 2731, Address: 0x1c5638, Func Offset: 0x18
	// Line 2737, Address: 0x1c563c, Func Offset: 0x1c
	// Line 2731, Address: 0x1c5640, Func Offset: 0x20
	// Line 2737, Address: 0x1c564c, Func Offset: 0x2c
	// Line 2742, Address: 0x1c567c, Func Offset: 0x5c
	// Line 2744, Address: 0x1c5698, Func Offset: 0x78
	// Line 2746, Address: 0x1c56a0, Func Offset: 0x80
	// Line 2745, Address: 0x1c56a4, Func Offset: 0x84
	// Line 2746, Address: 0x1c56ac, Func Offset: 0x8c
	// Line 2744, Address: 0x1c56b0, Func Offset: 0x90
	// Line 2745, Address: 0x1c56b8, Func Offset: 0x98
	// Line 2752, Address: 0x1c56bc, Func Offset: 0x9c
	// Line 2753, Address: 0x1c56c0, Func Offset: 0xa0
	// Line 2761, Address: 0x1c56c4, Func Offset: 0xa4
	// Line 2745, Address: 0x1c56c8, Func Offset: 0xa8
	// Line 2746, Address: 0x1c56cc, Func Offset: 0xac
	// Line 2745, Address: 0x1c56d0, Func Offset: 0xb0
	// Line 2746, Address: 0x1c56d8, Func Offset: 0xb8
	// Line 2747, Address: 0x1c56e0, Func Offset: 0xc0
	// Line 2746, Address: 0x1c56e4, Func Offset: 0xc4
	// Line 2747, Address: 0x1c56ec, Func Offset: 0xcc
	// Line 2749, Address: 0x1c56f4, Func Offset: 0xd4
	// Line 2747, Address: 0x1c56f8, Func Offset: 0xd8
	// Line 2749, Address: 0x1c5700, Func Offset: 0xe0
	// Line 2750, Address: 0x1c570c, Func Offset: 0xec
	// Line 2751, Address: 0x1c5734, Func Offset: 0x114
	// Line 2750, Address: 0x1c5738, Func Offset: 0x118
	// Line 2751, Address: 0x1c573c, Func Offset: 0x11c
	// Line 2752, Address: 0x1c5744, Func Offset: 0x124
	// Line 2753, Address: 0x1c5750, Func Offset: 0x130
	// Line 2754, Address: 0x1c575c, Func Offset: 0x13c
	// Line 2757, Address: 0x1c5768, Func Offset: 0x148
	// Line 2761, Address: 0x1c5774, Func Offset: 0x154
	// Line 2757, Address: 0x1c5778, Func Offset: 0x158
	// Line 2761, Address: 0x1c5784, Func Offset: 0x164
	// Line 2763, Address: 0x1c578c, Func Offset: 0x16c
	// Line 2761, Address: 0x1c5790, Func Offset: 0x170
	// Line 2763, Address: 0x1c579c, Func Offset: 0x17c
	// Line 2764, Address: 0x1c57a8, Func Offset: 0x188
	// Line 2763, Address: 0x1c57ac, Func Offset: 0x18c
	// Line 2764, Address: 0x1c57c8, Func Offset: 0x1a8
	// Line 2766, Address: 0x1c57d8, Func Offset: 0x1b8
	// Line 2768, Address: 0x1c57f0, Func Offset: 0x1d0
	// Line 2769, Address: 0x1c57f8, Func Offset: 0x1d8
	// Line 2772, Address: 0x1c5800, Func Offset: 0x1e0
	// Line 2773, Address: 0x1c5804, Func Offset: 0x1e4
	// Line 2768, Address: 0x1c5808, Func Offset: 0x1e8
	// Line 2769, Address: 0x1c580c, Func Offset: 0x1ec
	// Line 2768, Address: 0x1c5810, Func Offset: 0x1f0
	// Line 2769, Address: 0x1c5814, Func Offset: 0x1f4
	// Line 2770, Address: 0x1c581c, Func Offset: 0x1fc
	// Line 2769, Address: 0x1c5820, Func Offset: 0x200
	// Line 2770, Address: 0x1c5828, Func Offset: 0x208
	// Line 2771, Address: 0x1c5830, Func Offset: 0x210
	// Line 2770, Address: 0x1c5834, Func Offset: 0x214
	// Line 2771, Address: 0x1c583c, Func Offset: 0x21c
	// Line 2772, Address: 0x1c5844, Func Offset: 0x224
	// Line 2773, Address: 0x1c5850, Func Offset: 0x230
	// Line 2772, Address: 0x1c5854, Func Offset: 0x234
	// Line 2773, Address: 0x1c585c, Func Offset: 0x23c
	// Line 2775, Address: 0x1c5864, Func Offset: 0x244
	// Line 2778, Address: 0x1c5878, Func Offset: 0x258
	// Line 2783, Address: 0x1c5880, Func Offset: 0x260
	// Line 2784, Address: 0x1c588c, Func Offset: 0x26c
	// Line 2785, Address: 0x1c5894, Func Offset: 0x274
	// Line 2786, Address: 0x1c589c, Func Offset: 0x27c
	// Line 2785, Address: 0x1c58a0, Func Offset: 0x280
	// Line 2784, Address: 0x1c58a4, Func Offset: 0x284
	// Line 2785, Address: 0x1c58ac, Func Offset: 0x28c
	// Line 2786, Address: 0x1c58b0, Func Offset: 0x290
	// Line 2792, Address: 0x1c58b4, Func Offset: 0x294
	// Line 2793, Address: 0x1c58b8, Func Offset: 0x298
	// Line 2801, Address: 0x1c58bc, Func Offset: 0x29c
	// Line 2785, Address: 0x1c58c0, Func Offset: 0x2a0
	// Line 2786, Address: 0x1c58c4, Func Offset: 0x2a4
	// Line 2785, Address: 0x1c58c8, Func Offset: 0x2a8
	// Line 2786, Address: 0x1c58d0, Func Offset: 0x2b0
	// Line 2787, Address: 0x1c58d8, Func Offset: 0x2b8
	// Line 2786, Address: 0x1c58dc, Func Offset: 0x2bc
	// Line 2787, Address: 0x1c58e4, Func Offset: 0x2c4
	// Line 2789, Address: 0x1c58ec, Func Offset: 0x2cc
	// Line 2787, Address: 0x1c58f0, Func Offset: 0x2d0
	// Line 2789, Address: 0x1c58f8, Func Offset: 0x2d8
	// Line 2790, Address: 0x1c5904, Func Offset: 0x2e4
	// Line 2791, Address: 0x1c592c, Func Offset: 0x30c
	// Line 2790, Address: 0x1c5930, Func Offset: 0x310
	// Line 2791, Address: 0x1c5934, Func Offset: 0x314
	// Line 2792, Address: 0x1c593c, Func Offset: 0x31c
	// Line 2793, Address: 0x1c5948, Func Offset: 0x328
	// Line 2794, Address: 0x1c5954, Func Offset: 0x334
	// Line 2797, Address: 0x1c5960, Func Offset: 0x340
	// Line 2801, Address: 0x1c596c, Func Offset: 0x34c
	// Line 2797, Address: 0x1c5970, Func Offset: 0x350
	// Line 2801, Address: 0x1c597c, Func Offset: 0x35c
	// Line 2803, Address: 0x1c5984, Func Offset: 0x364
	// Line 2801, Address: 0x1c5988, Func Offset: 0x368
	// Line 2803, Address: 0x1c5994, Func Offset: 0x374
	// Line 2805, Address: 0x1c59a0, Func Offset: 0x380
	// Line 2810, Address: 0x1c59a8, Func Offset: 0x388
	// Line 2812, Address: 0x1c59c8, Func Offset: 0x3a8
	// Line 2813, Address: 0x1c59cc, Func Offset: 0x3ac
	// Line 2812, Address: 0x1c59d0, Func Offset: 0x3b0
	// Line 2813, Address: 0x1c59d4, Func Offset: 0x3b4
	// Line 2815, Address: 0x1c59d8, Func Offset: 0x3b8
	// Line 2813, Address: 0x1c59dc, Func Offset: 0x3bc
	// Line 2814, Address: 0x1c59fc, Func Offset: 0x3dc
	// Line 2813, Address: 0x1c5a00, Func Offset: 0x3e0
	// Line 2814, Address: 0x1c5a04, Func Offset: 0x3e4
	// Line 2815, Address: 0x1c5a0c, Func Offset: 0x3ec
	// Line 2817, Address: 0x1c5a18, Func Offset: 0x3f8
	// Line 2818, Address: 0x1c5a28, Func Offset: 0x408
	// Line 2817, Address: 0x1c5a2c, Func Offset: 0x40c
	// Line 2818, Address: 0x1c5a48, Func Offset: 0x428
	// Line 2820, Address: 0x1c5a58, Func Offset: 0x438
	// Line 2822, Address: 0x1c5a70, Func Offset: 0x450
	// Line 2823, Address: 0x1c5a78, Func Offset: 0x458
	// Line 2826, Address: 0x1c5a80, Func Offset: 0x460
	// Line 2827, Address: 0x1c5a84, Func Offset: 0x464
	// Line 2822, Address: 0x1c5a88, Func Offset: 0x468
	// Line 2823, Address: 0x1c5a8c, Func Offset: 0x46c
	// Line 2822, Address: 0x1c5a90, Func Offset: 0x470
	// Line 2823, Address: 0x1c5a94, Func Offset: 0x474
	// Line 2824, Address: 0x1c5a9c, Func Offset: 0x47c
	// Line 2823, Address: 0x1c5aa0, Func Offset: 0x480
	// Line 2824, Address: 0x1c5aa8, Func Offset: 0x488
	// Line 2825, Address: 0x1c5ab0, Func Offset: 0x490
	// Line 2824, Address: 0x1c5ab4, Func Offset: 0x494
	// Line 2825, Address: 0x1c5abc, Func Offset: 0x49c
	// Line 2826, Address: 0x1c5ac4, Func Offset: 0x4a4
	// Line 2827, Address: 0x1c5ad0, Func Offset: 0x4b0
	// Line 2826, Address: 0x1c5ad4, Func Offset: 0x4b4
	// Line 2827, Address: 0x1c5adc, Func Offset: 0x4bc
	// Line 2829, Address: 0x1c5ae4, Func Offset: 0x4c4
	// Line 2834, Address: 0x1c5afc, Func Offset: 0x4dc
	// Func End, Address: 0x1c5b08, Func Offset: 0x4e8
}

// 
// Start address: 0x1c5b10
int bhEne07_ObjEdge(BH_PWORK* epw)
{
	_anon5 p2;
	_anon5 p1;
	_anon29* hp;
	int ret;
	// Line 2844, Address: 0x1c5b10, Func Offset: 0
	// Line 2846, Address: 0x1c5b24, Func Offset: 0x14
	// Line 2854, Address: 0x1c5b2c, Func Offset: 0x1c
	// Line 2846, Address: 0x1c5b30, Func Offset: 0x20
	// Line 2854, Address: 0x1c5b34, Func Offset: 0x24
	// Line 2858, Address: 0x1c5b5c, Func Offset: 0x4c
	// Line 2861, Address: 0x1c5bc0, Func Offset: 0xb0
	// Line 2863, Address: 0x1c5bcc, Func Offset: 0xbc
	// Line 2861, Address: 0x1c5bd0, Func Offset: 0xc0
	// Line 2862, Address: 0x1c5bd4, Func Offset: 0xc4
	// Line 2861, Address: 0x1c5bdc, Func Offset: 0xcc
	// Line 2862, Address: 0x1c5be0, Func Offset: 0xd0
	// Line 2864, Address: 0x1c5be4, Func Offset: 0xd4
	// Line 2867, Address: 0x1c5c4c, Func Offset: 0x13c
	// Line 2869, Address: 0x1c5c58, Func Offset: 0x148
	// Line 2867, Address: 0x1c5c5c, Func Offset: 0x14c
	// Line 2868, Address: 0x1c5c60, Func Offset: 0x150
	// Line 2867, Address: 0x1c5c68, Func Offset: 0x158
	// Line 2868, Address: 0x1c5c6c, Func Offset: 0x15c
	// Line 2872, Address: 0x1c5c74, Func Offset: 0x164
	// Line 2875, Address: 0x1c5cd8, Func Offset: 0x1c8
	// Line 2877, Address: 0x1c5ce4, Func Offset: 0x1d4
	// Line 2875, Address: 0x1c5ce8, Func Offset: 0x1d8
	// Line 2876, Address: 0x1c5cec, Func Offset: 0x1dc
	// Line 2875, Address: 0x1c5cf4, Func Offset: 0x1e4
	// Line 2876, Address: 0x1c5cf8, Func Offset: 0x1e8
	// Line 2878, Address: 0x1c5cfc, Func Offset: 0x1ec
	// Line 2881, Address: 0x1c5d64, Func Offset: 0x254
	// Line 2883, Address: 0x1c5d70, Func Offset: 0x260
	// Line 2881, Address: 0x1c5d74, Func Offset: 0x264
	// Line 2882, Address: 0x1c5d78, Func Offset: 0x268
	// Line 2881, Address: 0x1c5d80, Func Offset: 0x270
	// Line 2882, Address: 0x1c5d84, Func Offset: 0x274
	// Line 2889, Address: 0x1c5d8c, Func Offset: 0x27c
	// Line 2892, Address: 0x1c5d94, Func Offset: 0x284
	// Line 2893, Address: 0x1c5d98, Func Offset: 0x288
	// Line 2896, Address: 0x1c5da4, Func Offset: 0x294
	// Line 2892, Address: 0x1c5da8, Func Offset: 0x298
	// Line 2893, Address: 0x1c5dac, Func Offset: 0x29c
	// Line 2899, Address: 0x1c5db0, Func Offset: 0x2a0
	// Line 2893, Address: 0x1c5dbc, Func Offset: 0x2ac
	// Line 2899, Address: 0x1c5dc0, Func Offset: 0x2b0
	// Line 2893, Address: 0x1c5dc4, Func Offset: 0x2b4
	// Line 2894, Address: 0x1c5dc8, Func Offset: 0x2b8
	// Line 2895, Address: 0x1c5dd0, Func Offset: 0x2c0
	// Line 2896, Address: 0x1c5dd8, Func Offset: 0x2c8
	// Line 2897, Address: 0x1c5de4, Func Offset: 0x2d4
	// Line 2899, Address: 0x1c5de8, Func Offset: 0x2d8
	// Line 2900, Address: 0x1c5df8, Func Offset: 0x2e8
	// Line 2901, Address: 0x1c5e10, Func Offset: 0x300
	// Line 2905, Address: 0x1c5e18, Func Offset: 0x308
	// Line 2906, Address: 0x1c5e1c, Func Offset: 0x30c
	// Func End, Address: 0x1c5e34, Func Offset: 0x324
}

// 
// Start address: 0x1c5e40
void bhEne07_CalcAtariOffset(BH_PWORK* epw, _anon5* ofp)
{
	npobj* objP;
	_anon9* mkaP;
	_anon5 trans;
	_anon5 body;
	// Line 2916, Address: 0x1c5e40, Func Offset: 0
	// Line 2919, Address: 0x1c5e50, Func Offset: 0x10
	// Line 2920, Address: 0x1c5e58, Func Offset: 0x18
	// Line 2925, Address: 0x1c5e68, Func Offset: 0x28
	// Line 2926, Address: 0x1c5e70, Func Offset: 0x30
	// Line 2927, Address: 0x1c5e7c, Func Offset: 0x3c
	// Line 2928, Address: 0x1c5e90, Func Offset: 0x50
	// Line 2929, Address: 0x1c5e98, Func Offset: 0x58
	// Line 2928, Address: 0x1c5e9c, Func Offset: 0x5c
	// Line 2929, Address: 0x1c5eb0, Func Offset: 0x70
	// Line 2928, Address: 0x1c5ebc, Func Offset: 0x7c
	// Line 2929, Address: 0x1c5ec0, Func Offset: 0x80
	// Line 2930, Address: 0x1c5ec8, Func Offset: 0x88
	// Line 2932, Address: 0x1c5edc, Func Offset: 0x9c
	// Line 2937, Address: 0x1c5eec, Func Offset: 0xac
	// Line 2940, Address: 0x1c5ef0, Func Offset: 0xb0
	// Line 2944, Address: 0x1c5ef4, Func Offset: 0xb4
	// Line 2937, Address: 0x1c5ef8, Func Offset: 0xb8
	// Line 2939, Address: 0x1c5efc, Func Offset: 0xbc
	// Line 2940, Address: 0x1c5f04, Func Offset: 0xc4
	// Line 2941, Address: 0x1c5f0c, Func Offset: 0xcc
	// Line 2944, Address: 0x1c5f14, Func Offset: 0xd4
	// Line 2946, Address: 0x1c5f28, Func Offset: 0xe8
	// Line 2947, Address: 0x1c5f34, Func Offset: 0xf4
	// Line 2948, Address: 0x1c5f40, Func Offset: 0x100
	// Line 2949, Address: 0x1c5f50, Func Offset: 0x110
	// Line 2951, Address: 0x1c5f5c, Func Offset: 0x11c
	// Func End, Address: 0x1c5f70, Func Offset: 0x130
}

