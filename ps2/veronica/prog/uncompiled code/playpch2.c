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

typedef void(*type_74)(void*);

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
typedef _anon0* type_11[512];
typedef _anon1* type_12[1300];
typedef char type_13[32];
typedef _anon0* type_14[512];
typedef _anon1* type_15[200];
typedef short type_16[32];
typedef _anon14 type_17[1];
typedef _anon0* type_18[128];
typedef unsigned int type_19[1];
typedef _anon4 type_20[256];
typedef _anon1* type_21[8];
typedef int* type_22[16];
typedef _anon0* type_23[128];
typedef npobj* type_24[16];
typedef _anon0* type_25[128];
typedef int type_26[4];
typedef _anon1* type_27[16];
typedef unsigned int type_28[4];
typedef _anon8 type_29[16];
typedef _anon0* type_30[512];
typedef char type_31[256];
typedef float type_32[4];
typedef float type_33[4];
typedef float type_34[4];
typedef _anon3* type_35[128];
typedef float type_36[3];
typedef unsigned char type_37[64];
typedef float type_38[3][20];
typedef float type_39[3];
typedef float type_40[3][20];
typedef float type_41[3];
typedef float type_42[3][20];
typedef char type_43[8];
typedef float type_44[3];
typedef float type_45[3][20];
typedef void* type_46[2];
typedef _anon1* type_47[256];
typedef int type_48[4];
typedef unsigned char* type_49[256];
typedef unsigned int type_50[2];
typedef short type_51[256];
typedef _anon20 type_52[4];
typedef float type_53[3];
typedef short type_54[256];
typedef int type_55[3];
typedef int type_56[8];
typedef float type_57[3];
typedef _anon1* type_58[256];
typedef _anon6 type_59[256];
typedef _anon14 type_60[450];
typedef _anon22 type_61[16];
typedef short type_62[256];
typedef char type_63[3];
typedef int type_64[64];
typedef _anon8 type_65[450];
typedef _anon28 type_66[4];
typedef _anon2 type_67[4];
typedef int type_68[450];
typedef unsigned int type_69[8];
typedef unsigned char type_70[450];
typedef unsigned short type_71[5];
typedef char type_72[16];
typedef char type_73[4];
typedef _anon11 type_75[0];
typedef unsigned int type_76[32];
typedef unsigned int type_77[16];
typedef _anon29 type_78[64];
typedef unsigned int type_79[16];
typedef _anon29 type_80[64];
typedef unsigned int type_81[32];
typedef _anon29 type_82[64];
typedef unsigned int type_83[16];
typedef unsigned int type_84[3];
typedef BH_PWORK* type_85[16];
typedef unsigned int type_86[8];
typedef _anon24 type_87[4];
typedef unsigned int type_88[1];
typedef _anon24 type_89[4][0];
typedef unsigned int type_90[384];
typedef unsigned int type_91[2];
typedef unsigned char type_92[2];
typedef unsigned int type_93[4];
typedef int* type_94[16];
typedef char type_95[32];
typedef npobj* type_96[16];
typedef char type_97[64];
typedef _anon1* type_98[16];
typedef char type_99[4];
typedef _anon8 type_100[16];
typedef short type_101[4];
typedef unsigned char type_102[4];
typedef _anon25 type_103[16];
typedef unsigned int type_104[32];
typedef _anon23 type_105[32];
typedef _anon0* type_106[512];
typedef _anon0* type_107[128];
typedef _anon0* type_108[512];
typedef unsigned char type_109[64];
typedef _anon0* type_110[512];

struct npobj
{
	unsigned int evalflags;
	_anon21* model;
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
	_anon8 mdl[16];
	_anon8* mlwP;
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
	_anon3* mnwP;
	_anon3* mnwPb;
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
	_anon8 mdl[16];
	_anon8* mlwP;
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
	_anon3* mnwP;
	_anon3* mnwPb;
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
	_anon15* cpcl;
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
	_anon14* textures;
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
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon13* md2P;
	unsigned short* atrP;
};

struct _anon4
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon5
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

struct _anon6
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon7
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
	_anon23 ply_pos;
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
	_anon9* p1per;
	_anon9* p2per;
	_anon9* kbper;
	_anon9* msper;
	_anon9 ms_per;
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
	_anon3* emtp[128];
	_anon3* rmthp;
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
	_anon6 txbp[256];
	unsigned char* ef_psp;
	_anon14 ef_tex[450];
	_anon1 ef_tlist;
	_anon24 ef;
	short efid[256];
	_anon8 efm[450];
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
	_anon12 ren_info;
	_anon14 ren_tex[1];
	_anon1 ren_tlist;
	_anon4 rpb[256];
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
	_anon16* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon20 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon22 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon29* pl_htp;
	int costume;
	_anon23 hd_pos;
	_anon23 apos;
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
	_anon10 door;
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
	_anon23 ufo_pos;
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
	_anon25 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon23 ghtp[32];
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

struct _anon8
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon18* owP;
};

struct _anon9
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

struct _anon10
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

struct _anon11
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
	_anon23 wp_fps1;
	_anon23 wp_fps2;
	_anon23 wp_cps;
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

struct _anon12
{
	void* texaddr;
	_anon5 texsurface;
};

struct _anon13
{
	void* p[2];
};

struct _anon14
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon15
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon16
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
	_anon19* light;
};

struct _anon17
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon18
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon19
{
	float mtrx[16];
	_anon23 pnt;
	_anon23 vctr;
	int stat;
	int reserve;
	_anon26 ltcal;
	_anon33 attr;
};

struct _anon20
{
	_anon23 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon21
{
	int* vlist;
	short* plist;
	_anon23 center;
	float r;
};

struct _anon22
{
	float x;
	float y;
};

struct _anon23
{
	float x;
	float y;
	float z;
};

struct _anon24
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

struct _anon25
{
	_anon23 c1;
	_anon23 c2;
	float r1;
	float r2;
};

struct _anon26
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
	_anon23 lpnt;
	_anon23 lvctr;
	_anon23 lmvctr;
	_anon17 atten;
	_anon17 amb;
	_anon17 dif;
	_anon17 spc;
	_anon17 mamb;
	_anon17 mdif;
	_anon17 mspc;
};

struct _anon27
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
	float gx;
	float gy;
	float gz;
	unsigned int at_flg;
	int wpn_no;
	float r;
	float l;
	float rn;
	float rmax;
	int ax;
	int ay;
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
	_anon17 argb;
};

struct _anon34
{
	_anon23 c;
	float r;
};

struct _anon35
{
	_anon23 c1;
	_anon23 c2;
	float r;
};

BH_PWORK* plp;
_anon7* sys;
_anon30 cam;
unsigned short PlMtnWpn[5];
_anon24 WpnEffTab[4][0];
_anon11 WpnTab[0];

void bhCPM2_act_scp();

// 
// Start address: 0x14d250
void bhCPM2_act_scp()
{
	_anon23 fpsb;
	_anon23 fps;
	_anon24* eft;
	_anon23 pos;
	short bn;
	_anon27 gap;
	_anon23 ps;
	// Line 44, Address: 0x14d250, Func Offset: 0
	// Line 50, Address: 0x14d264, Func Offset: 0x14
	// Line 52, Address: 0x14d2a4, Func Offset: 0x54
	// Line 53, Address: 0x14d2ac, Func Offset: 0x5c
	// Line 54, Address: 0x14d2b0, Func Offset: 0x60
	// Line 58, Address: 0x14d2b4, Func Offset: 0x64
	// Line 52, Address: 0x14d2b8, Func Offset: 0x68
	// Line 53, Address: 0x14d2c0, Func Offset: 0x70
	// Line 54, Address: 0x14d2d0, Func Offset: 0x80
	// Line 55, Address: 0x14d2dc, Func Offset: 0x8c
	// Line 56, Address: 0x14d2e8, Func Offset: 0x98
	// Line 57, Address: 0x14d2f4, Func Offset: 0xa4
	// Line 58, Address: 0x14d300, Func Offset: 0xb0
	// Line 59, Address: 0x14d30c, Func Offset: 0xbc
	// Line 58, Address: 0x14d310, Func Offset: 0xc0
	// Line 59, Address: 0x14d314, Func Offset: 0xc4
	// Line 60, Address: 0x14d31c, Func Offset: 0xcc
	// Line 62, Address: 0x14d330, Func Offset: 0xe0
	// Line 63, Address: 0x14d33c, Func Offset: 0xec
	// Line 64, Address: 0x14d340, Func Offset: 0xf0
	// Line 62, Address: 0x14d344, Func Offset: 0xf4
	// Line 63, Address: 0x14d348, Func Offset: 0xf8
	// Line 62, Address: 0x14d34c, Func Offset: 0xfc
	// Line 63, Address: 0x14d354, Func Offset: 0x104
	// Line 64, Address: 0x14d35c, Func Offset: 0x10c
	// Line 63, Address: 0x14d360, Func Offset: 0x110
	// Line 64, Address: 0x14d368, Func Offset: 0x118
	// Line 65, Address: 0x14d370, Func Offset: 0x120
	// Line 64, Address: 0x14d374, Func Offset: 0x124
	// Line 65, Address: 0x14d37c, Func Offset: 0x12c
	// Line 66, Address: 0x14d398, Func Offset: 0x148
	// Line 68, Address: 0x14d3b0, Func Offset: 0x160
	// Line 70, Address: 0x14d3e8, Func Offset: 0x198
	// Line 71, Address: 0x14d400, Func Offset: 0x1b0
	// Line 72, Address: 0x14d410, Func Offset: 0x1c0
	// Line 73, Address: 0x14d418, Func Offset: 0x1c8
	// Line 74, Address: 0x14d424, Func Offset: 0x1d4
	// Line 73, Address: 0x14d428, Func Offset: 0x1d8
	// Line 74, Address: 0x14d430, Func Offset: 0x1e0
	// Line 76, Address: 0x14d444, Func Offset: 0x1f4
	// Line 77, Address: 0x14d44c, Func Offset: 0x1fc
	// Line 76, Address: 0x14d450, Func Offset: 0x200
	// Line 77, Address: 0x14d454, Func Offset: 0x204
	// Line 76, Address: 0x14d458, Func Offset: 0x208
	// Line 77, Address: 0x14d460, Func Offset: 0x210
	// Line 78, Address: 0x14d468, Func Offset: 0x218
	// Line 79, Address: 0x14d474, Func Offset: 0x224
	// Line 80, Address: 0x14d47c, Func Offset: 0x22c
	// Line 83, Address: 0x14d484, Func Offset: 0x234
	// Line 84, Address: 0x14d4ac, Func Offset: 0x25c
	// Line 91, Address: 0x14d4b8, Func Offset: 0x268
	// Line 92, Address: 0x14d4c0, Func Offset: 0x270
	// Line 91, Address: 0x14d4c8, Func Offset: 0x278
	// Line 92, Address: 0x14d4cc, Func Offset: 0x27c
	// Line 101, Address: 0x14d56c, Func Offset: 0x31c
	// Line 104, Address: 0x14d574, Func Offset: 0x324
	// Line 105, Address: 0x14d5a4, Func Offset: 0x354
	// Line 106, Address: 0x14d5b0, Func Offset: 0x360
	// Line 105, Address: 0x14d5b8, Func Offset: 0x368
	// Line 106, Address: 0x14d5c0, Func Offset: 0x370
	// Line 107, Address: 0x14d5c8, Func Offset: 0x378
	// Line 108, Address: 0x14d5d0, Func Offset: 0x380
	// Line 111, Address: 0x14d5d8, Func Offset: 0x388
	// Line 114, Address: 0x14d61c, Func Offset: 0x3cc
	// Line 115, Address: 0x14d62c, Func Offset: 0x3dc
	// Line 117, Address: 0x14d634, Func Offset: 0x3e4
	// Line 119, Address: 0x14d640, Func Offset: 0x3f0
	// Line 117, Address: 0x14d648, Func Offset: 0x3f8
	// Line 119, Address: 0x14d650, Func Offset: 0x400
	// Line 120, Address: 0x14d654, Func Offset: 0x404
	// Line 119, Address: 0x14d658, Func Offset: 0x408
	// Line 120, Address: 0x14d65c, Func Offset: 0x40c
	// Line 121, Address: 0x14d668, Func Offset: 0x418
	// Line 120, Address: 0x14d66c, Func Offset: 0x41c
	// Line 121, Address: 0x14d674, Func Offset: 0x424
	// Line 122, Address: 0x14d67c, Func Offset: 0x42c
	// Line 121, Address: 0x14d680, Func Offset: 0x430
	// Line 122, Address: 0x14d688, Func Offset: 0x438
	// Line 123, Address: 0x14d690, Func Offset: 0x440
	// Line 127, Address: 0x14d698, Func Offset: 0x448
	// Line 131, Address: 0x14d6a0, Func Offset: 0x450
	// Line 128, Address: 0x14d6a8, Func Offset: 0x458
	// Line 127, Address: 0x14d6ac, Func Offset: 0x45c
	// Line 128, Address: 0x14d6b4, Func Offset: 0x464
	// Line 131, Address: 0x14d6b8, Func Offset: 0x468
	// Line 128, Address: 0x14d6bc, Func Offset: 0x46c
	// Line 129, Address: 0x14d6c0, Func Offset: 0x470
	// Line 128, Address: 0x14d6c4, Func Offset: 0x474
	// Line 129, Address: 0x14d6c8, Func Offset: 0x478
	// Line 131, Address: 0x14d6d0, Func Offset: 0x480
	// Line 129, Address: 0x14d6d4, Func Offset: 0x484
	// Line 131, Address: 0x14d6dc, Func Offset: 0x48c
	// Line 135, Address: 0x14d730, Func Offset: 0x4e0
	// Line 137, Address: 0x14d734, Func Offset: 0x4e4
	// Line 136, Address: 0x14d73c, Func Offset: 0x4ec
	// Line 138, Address: 0x14d740, Func Offset: 0x4f0
	// Line 135, Address: 0x14d744, Func Offset: 0x4f4
	// Line 136, Address: 0x14d748, Func Offset: 0x4f8
	// Line 137, Address: 0x14d750, Func Offset: 0x500
	// Line 138, Address: 0x14d76c, Func Offset: 0x51c
	// Line 140, Address: 0x14d77c, Func Offset: 0x52c
	// Line 144, Address: 0x14d784, Func Offset: 0x534
	// Line 140, Address: 0x14d788, Func Offset: 0x538
	// Line 141, Address: 0x14d78c, Func Offset: 0x53c
	// Line 140, Address: 0x14d790, Func Offset: 0x540
	// Line 141, Address: 0x14d798, Func Offset: 0x548
	// Line 142, Address: 0x14d7a0, Func Offset: 0x550
	// Line 141, Address: 0x14d7a4, Func Offset: 0x554
	// Line 142, Address: 0x14d7b0, Func Offset: 0x560
	// Line 143, Address: 0x14d7b8, Func Offset: 0x568
	// Line 142, Address: 0x14d7bc, Func Offset: 0x56c
	// Line 143, Address: 0x14d7c8, Func Offset: 0x578
	// Line 144, Address: 0x14d7d8, Func Offset: 0x588
	// Line 145, Address: 0x14d7e0, Func Offset: 0x590
	// Line 153, Address: 0x14d7fc, Func Offset: 0x5ac
	// Line 154, Address: 0x14d800, Func Offset: 0x5b0
	// Line 155, Address: 0x14d804, Func Offset: 0x5b4
	// Line 156, Address: 0x14d80c, Func Offset: 0x5bc
	// Line 158, Address: 0x14d814, Func Offset: 0x5c4
	// Line 156, Address: 0x14d820, Func Offset: 0x5d0
	// Line 157, Address: 0x14d824, Func Offset: 0x5d4
	// Line 156, Address: 0x14d828, Func Offset: 0x5d8
	// Line 157, Address: 0x14d82c, Func Offset: 0x5dc
	// Line 158, Address: 0x14d834, Func Offset: 0x5e4
	// Line 159, Address: 0x14d83c, Func Offset: 0x5ec
	// Line 162, Address: 0x14d844, Func Offset: 0x5f4
	// Line 159, Address: 0x14d854, Func Offset: 0x604
	// Line 160, Address: 0x14d85c, Func Offset: 0x60c
	// Line 161, Address: 0x14d86c, Func Offset: 0x61c
	// Line 162, Address: 0x14d878, Func Offset: 0x628
	// Line 163, Address: 0x14d880, Func Offset: 0x630
	// Line 164, Address: 0x14d898, Func Offset: 0x648
	// Line 169, Address: 0x14d8a4, Func Offset: 0x654
	// Line 170, Address: 0x14d8e4, Func Offset: 0x694
	// Line 172, Address: 0x14d8e8, Func Offset: 0x698
	// Line 173, Address: 0x14d8f0, Func Offset: 0x6a0
	// Line 170, Address: 0x14d8f8, Func Offset: 0x6a8
	// Line 171, Address: 0x14d8fc, Func Offset: 0x6ac
	// Line 174, Address: 0x14d900, Func Offset: 0x6b0
	// Line 175, Address: 0x14d908, Func Offset: 0x6b8
	// Line 173, Address: 0x14d90c, Func Offset: 0x6bc
	// Line 171, Address: 0x14d910, Func Offset: 0x6c0
	// Line 172, Address: 0x14d914, Func Offset: 0x6c4
	// Line 175, Address: 0x14d918, Func Offset: 0x6c8
	// Line 179, Address: 0x14d91c, Func Offset: 0x6cc
	// Line 180, Address: 0x14d920, Func Offset: 0x6d0
	// Line 172, Address: 0x14d924, Func Offset: 0x6d4
	// Line 173, Address: 0x14d944, Func Offset: 0x6f4
	// Line 174, Address: 0x14d968, Func Offset: 0x718
	// Line 175, Address: 0x14d98c, Func Offset: 0x73c
	// Line 176, Address: 0x14d9b0, Func Offset: 0x760
	// Line 177, Address: 0x14d9b8, Func Offset: 0x768
	// Line 178, Address: 0x14d9c0, Func Offset: 0x770
	// Line 179, Address: 0x14d9c8, Func Offset: 0x778
	// Line 180, Address: 0x14d9d0, Func Offset: 0x780
	// Line 182, Address: 0x14d9e8, Func Offset: 0x798
	// Line 181, Address: 0x14d9ec, Func Offset: 0x79c
	// Line 182, Address: 0x14d9f0, Func Offset: 0x7a0
	// Line 183, Address: 0x14d9f8, Func Offset: 0x7a8
	// Line 184, Address: 0x14da04, Func Offset: 0x7b4
	// Line 185, Address: 0x14da24, Func Offset: 0x7d4
	// Line 191, Address: 0x14da28, Func Offset: 0x7d8
	// Line 185, Address: 0x14da2c, Func Offset: 0x7dc
	// Line 186, Address: 0x14da30, Func Offset: 0x7e0
	// Line 187, Address: 0x14da38, Func Offset: 0x7e8
	// Line 191, Address: 0x14da3c, Func Offset: 0x7ec
	// Line 192, Address: 0x14da44, Func Offset: 0x7f4
	// Line 193, Address: 0x14da60, Func Offset: 0x810
	// Line 194, Address: 0x14da64, Func Offset: 0x814
	// Line 195, Address: 0x14da68, Func Offset: 0x818
	// Line 196, Address: 0x14da6c, Func Offset: 0x81c
	// Line 195, Address: 0x14da78, Func Offset: 0x828
	// Line 196, Address: 0x14da7c, Func Offset: 0x82c
	// Line 197, Address: 0x14da84, Func Offset: 0x834
	// Line 198, Address: 0x14da8c, Func Offset: 0x83c
	// Line 201, Address: 0x14da94, Func Offset: 0x844
	// Line 202, Address: 0x14dacc, Func Offset: 0x87c
	// Line 205, Address: 0x14dad4, Func Offset: 0x884
	// Line 206, Address: 0x14db0c, Func Offset: 0x8bc
	// Line 208, Address: 0x14db24, Func Offset: 0x8d4
	// Line 211, Address: 0x14db38, Func Offset: 0x8e8
	// Line 214, Address: 0x14dba4, Func Offset: 0x954
	// Line 216, Address: 0x14dbb4, Func Offset: 0x964
	// Line 217, Address: 0x14dbd0, Func Offset: 0x980
	// Line 218, Address: 0x14dbd4, Func Offset: 0x984
	// Line 220, Address: 0x14dbd8, Func Offset: 0x988
	// Line 225, Address: 0x14dbdc, Func Offset: 0x98c
	// Line 217, Address: 0x14dbe0, Func Offset: 0x990
	// Line 218, Address: 0x14dbe8, Func Offset: 0x998
	// Line 219, Address: 0x14dbf0, Func Offset: 0x9a0
	// Line 218, Address: 0x14dbf4, Func Offset: 0x9a4
	// Line 219, Address: 0x14dbf8, Func Offset: 0x9a8
	// Line 220, Address: 0x14dc08, Func Offset: 0x9b8
	// Line 221, Address: 0x14dc14, Func Offset: 0x9c4
	// Line 222, Address: 0x14dc20, Func Offset: 0x9d0
	// Line 223, Address: 0x14dc2c, Func Offset: 0x9dc
	// Line 224, Address: 0x14dc38, Func Offset: 0x9e8
	// Line 225, Address: 0x14dc44, Func Offset: 0x9f4
	// Line 226, Address: 0x14dc4c, Func Offset: 0x9fc
	// Line 228, Address: 0x14dc54, Func Offset: 0xa04
	// Line 229, Address: 0x14dc74, Func Offset: 0xa24
	// Line 232, Address: 0x14dc84, Func Offset: 0xa34
	// Line 234, Address: 0x14dce4, Func Offset: 0xa94
	// Line 238, Address: 0x14dcfc, Func Offset: 0xaac
	// Line 243, Address: 0x14dd14, Func Offset: 0xac4
	// Line 245, Address: 0x14dd38, Func Offset: 0xae8
	// Line 246, Address: 0x14dd40, Func Offset: 0xaf0
	// Line 247, Address: 0x14dd48, Func Offset: 0xaf8
	// Line 249, Address: 0x14dd54, Func Offset: 0xb04
	// Line 251, Address: 0x14dd64, Func Offset: 0xb14
	// Line 256, Address: 0x14dda0, Func Offset: 0xb50
	// Line 258, Address: 0x14ddc0, Func Offset: 0xb70
	// Line 259, Address: 0x14ddf4, Func Offset: 0xba4
	// Line 261, Address: 0x14de08, Func Offset: 0xbb8
	// Line 264, Address: 0x14de40, Func Offset: 0xbf0
	// Line 266, Address: 0x14de60, Func Offset: 0xc10
	// Line 271, Address: 0x14de98, Func Offset: 0xc48
	// Line 273, Address: 0x14deb8, Func Offset: 0xc68
	// Line 274, Address: 0x14deec, Func Offset: 0xc9c
	// Line 276, Address: 0x14df00, Func Offset: 0xcb0
	// Line 279, Address: 0x14df38, Func Offset: 0xce8
	// Line 280, Address: 0x14df5c, Func Offset: 0xd0c
	// Line 282, Address: 0x14df80, Func Offset: 0xd30
	// Line 283, Address: 0x14df90, Func Offset: 0xd40
	// Func End, Address: 0x14dfa8, Func Offset: 0xd58
}

