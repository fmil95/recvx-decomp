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
typedef struct BH_PWORK;
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

typedef void(*type_73)(void*);
typedef void(*type_104)();

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
typedef _anon13 type_17[1];
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
typedef _anon7 type_29[16];
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
typedef _anon19 type_52[4];
typedef float type_53[3];
typedef short type_54[256];
typedef int type_55[3];
typedef int type_56[8];
typedef float type_57[3];
typedef _anon1* type_58[256];
typedef _anon6 type_59[256];
typedef _anon13 type_60[450];
typedef _anon21 type_61[16];
typedef short type_62[256];
typedef char type_63[3];
typedef int type_64[64];
typedef _anon7 type_65[450];
typedef _anon25 type_66[4];
typedef _anon2 type_67[4];
typedef int type_68[450];
typedef unsigned int type_69[8];
typedef unsigned char type_70[450];
typedef char type_71[16];
typedef char type_72[4];
typedef unsigned int type_74[32];
typedef unsigned int type_75[16];
typedef _anon27 type_76[64];
typedef unsigned int type_77[16];
typedef _anon27 type_78[64];
typedef unsigned int type_79[32];
typedef _anon27 type_80[64];
typedef unsigned int type_81[16];
typedef unsigned int type_82[3];
typedef BH_PWORK* type_83[16];
typedef unsigned int type_84[8];
typedef unsigned int type_85[1];
typedef unsigned int type_86[384];
typedef unsigned int type_87[2];
typedef unsigned char type_88[2];
typedef int* type_89[16];
typedef unsigned int type_90[4];
typedef char type_91[32];
typedef npobj* type_92[16];
typedef char type_93[64];
typedef _anon1* type_94[16];
typedef char type_95[4];
typedef _anon7 type_96[16];
typedef short type_97[4];
typedef unsigned char type_98[4];
typedef _anon23 type_99[16];
typedef unsigned int type_100[32];
typedef _anon22 type_101[32];
typedef _anon0* type_102[512];
typedef _anon0* type_103[128];
typedef void(*type_105)()[4];
typedef _anon0* type_106[512];
typedef unsigned char type_107[64];
typedef _anon0* type_108[512];

struct npobj
{
	unsigned int evalflags;
	_anon20* model;
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
	_anon7 mdl[16];
	_anon7* mlwP;
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
	_anon32 cspr;
	int pn;
	_anon25* pvp;
	_anon2* tvp;
	_anon25 pv[4];
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
	_anon13* textures;
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
	_anon12* md2P;
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
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon10* owP;
};

struct _anon8
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
	_anon30* info;
};

struct _anon9
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
	_anon7 mdl[16];
	_anon7* mlwP;
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
	_anon33 watr;
	_anon14* cpcl;
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

struct _anon10
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon11
{
	void* texaddr;
	_anon5 texsurface;
};

struct _anon12
{
	void* p[2];
};

struct _anon13
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon14
{
	short jnt_a;
	short jnt_b;
	int cap_r;
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
	_anon18* light;
};

struct _anon16
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
	_anon22 ply_pos;
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
	_anon8* p1per;
	_anon8* p2per;
	_anon8* kbper;
	_anon8* msper;
	_anon8 ms_per;
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
	_anon13 ef_tex[450];
	_anon1 ef_tlist;
	_anon26 ef;
	short efid[256];
	_anon7 efm[450];
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
	_anon11 ren_info;
	_anon13 ren_tex[1];
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
	_anon29 mr_pl;
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
	_anon19 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon21 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon27* pl_htp;
	int costume;
	_anon22 hd_pos;
	_anon22 apos;
	_anon27* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon27 mwalp[64];
	_anon27 metcp[64];
	_anon27 mflrp[64];
	int dla_n;
	_anon27* htp;
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
	_anon9 door;
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
	_anon22 ufo_pos;
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
	_anon23 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon22 ghtp[32];
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

struct _anon17
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon18
{
	float mtrx[16];
	_anon22 pnt;
	_anon22 vctr;
	int stat;
	int reserve;
	_anon24 ltcal;
	_anon31 attr;
};

struct _anon19
{
	_anon22 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon20
{
	int* vlist;
	short* plist;
	_anon22 center;
	float r;
};

struct _anon21
{
	float x;
	float y;
};

struct _anon22
{
	float x;
	float y;
	float z;
};

struct _anon23
{
	_anon22 c1;
	_anon22 c2;
	float r1;
	float r2;
};

struct _anon24
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
	_anon22 lpnt;
	_anon22 lvctr;
	_anon22 lmvctr;
	_anon17 atten;
	_anon17 amb;
	_anon17 dif;
	_anon17 spc;
	_anon17 mamb;
	_anon17 mdif;
	_anon17 mspc;
};

struct _anon25
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon26
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

struct _anon27
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

struct _anon28
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

struct _anon29
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon30
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

struct _anon31
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

struct _anon32
{
	_anon22 c;
	float r;
};

struct _anon33
{
	_anon22 c1;
	_anon22 c2;
	float r;
};

void(*bhJumpCnkDraw)()[4];
_anon28 cam;
unsigned int _nj_control_3d_flag_;
_anon16* sys;

void bhPutModel(BH_PWORK* ewP);
void DrawTreeBsc(npobj* objP, _anon10* owP, int obj_num);
void EasyMultiDrawTreeCnk(BH_PWORK* ewP, npobj* objP, _anon10* owP, int obj_num);
void SimpleMultiDrawTreeCnk(BH_PWORK* ewP, npobj* objP, _anon10* owP, int obj_num);
void EasyDrawTreeCnk(BH_PWORK* ewP, npobj* objP, _anon10* owP, int obj_num);
void SimpleDrawTreeCnk(BH_PWORK* ewP, npobj* objP, _anon10* owP, int obj_num);
void bhCalcModel(BH_PWORK* ewP);
void bhCalcTree(float basP[16], _anon7* mlwP);

// 
// Start address: 0x12ebb0
void bhPutModel(BH_PWORK* ewP)
{
	unsigned int c3df;
	int draw_tp;
	_anon10* owP;
	_anon7* mlwP;
	// Line 65, Address: 0x12ebb0, Func Offset: 0
	// Line 66, Address: 0x12ebcc, Func Offset: 0x1c
	// Line 71, Address: 0x12ebd4, Func Offset: 0x24
	// Line 72, Address: 0x12ebe0, Func Offset: 0x30
	// Line 77, Address: 0x12ebe8, Func Offset: 0x38
	// Line 79, Address: 0x12ec10, Func Offset: 0x60
	// Line 81, Address: 0x12ec20, Func Offset: 0x70
	// Line 84, Address: 0x12ec38, Func Offset: 0x88
	// Line 85, Address: 0x12ec44, Func Offset: 0x94
	// Line 86, Address: 0x12ec54, Func Offset: 0xa4
	// Line 87, Address: 0x12ec70, Func Offset: 0xc0
	// Line 88, Address: 0x12ec78, Func Offset: 0xc8
	// Line 90, Address: 0x12ec94, Func Offset: 0xe4
	// Line 91, Address: 0x12ecbc, Func Offset: 0x10c
	// Line 93, Address: 0x12ece4, Func Offset: 0x134
	// Line 94, Address: 0x12ecf8, Func Offset: 0x148
	// Line 95, Address: 0x12ed18, Func Offset: 0x168
	// Line 96, Address: 0x12ed28, Func Offset: 0x178
	// Line 97, Address: 0x12ed30, Func Offset: 0x180
	// Line 98, Address: 0x12ed38, Func Offset: 0x188
	// Line 99, Address: 0x12ed40, Func Offset: 0x190
	// Line 100, Address: 0x12ed4c, Func Offset: 0x19c
	// Line 101, Address: 0x12ed64, Func Offset: 0x1b4
	// Line 102, Address: 0x12ed6c, Func Offset: 0x1bc
	// Line 103, Address: 0x12ed80, Func Offset: 0x1d0
	// Line 104, Address: 0x12ed90, Func Offset: 0x1e0
	// Line 105, Address: 0x12ed98, Func Offset: 0x1e8
	// Line 107, Address: 0x12eda0, Func Offset: 0x1f0
	// Line 108, Address: 0x12edac, Func Offset: 0x1fc
	// Line 111, Address: 0x12edb4, Func Offset: 0x204
	// Line 112, Address: 0x12eddc, Func Offset: 0x22c
	// Line 114, Address: 0x12ee04, Func Offset: 0x254
	// Line 115, Address: 0x12ee18, Func Offset: 0x268
	// Line 116, Address: 0x12ee38, Func Offset: 0x288
	// Line 117, Address: 0x12ee48, Func Offset: 0x298
	// Line 118, Address: 0x12ee50, Func Offset: 0x2a0
	// Line 119, Address: 0x12ee58, Func Offset: 0x2a8
	// Line 120, Address: 0x12ee60, Func Offset: 0x2b0
	// Line 121, Address: 0x12ee6c, Func Offset: 0x2bc
	// Line 122, Address: 0x12ee84, Func Offset: 0x2d4
	// Line 123, Address: 0x12ee8c, Func Offset: 0x2dc
	// Line 124, Address: 0x12eea0, Func Offset: 0x2f0
	// Line 125, Address: 0x12eeb0, Func Offset: 0x300
	// Line 126, Address: 0x12eeb8, Func Offset: 0x308
	// Line 129, Address: 0x12eec0, Func Offset: 0x310
	// Line 131, Address: 0x12eec8, Func Offset: 0x318
	// Line 134, Address: 0x12eed8, Func Offset: 0x328
	// Func End, Address: 0x12eef8, Func Offset: 0x348
}

// 
// Start address: 0x12ef00
void DrawTreeBsc(npobj* objP, _anon10* owP, int obj_num)
{
	// Line 146, Address: 0x12ef00, Func Offset: 0
	// Line 148, Address: 0x12ef1c, Func Offset: 0x1c
	// Line 149, Address: 0x12ef24, Func Offset: 0x24
	// Line 150, Address: 0x12ef30, Func Offset: 0x30
	// Line 151, Address: 0x12ef3c, Func Offset: 0x3c
	// Line 152, Address: 0x12ef58, Func Offset: 0x58
	// Line 153, Address: 0x12ef60, Func Offset: 0x60
	// Line 154, Address: 0x12ef68, Func Offset: 0x68
	// Line 156, Address: 0x12ef78, Func Offset: 0x78
	// Func End, Address: 0x12ef90, Func Offset: 0x90
}

// 
// Start address: 0x12ef90
void EasyMultiDrawTreeCnk(BH_PWORK* ewP, npobj* objP, _anon10* owP, int obj_num)
{
	// Line 170, Address: 0x12ef90, Func Offset: 0
	// Line 172, Address: 0x12efb4, Func Offset: 0x24
	// Line 173, Address: 0x12efbc, Func Offset: 0x2c
	// Line 174, Address: 0x12efc8, Func Offset: 0x38
	// Line 175, Address: 0x12efdc, Func Offset: 0x4c
	// Line 177, Address: 0x12eff0, Func Offset: 0x60
	// Line 178, Address: 0x12f004, Func Offset: 0x74
	// Line 179, Address: 0x12f008, Func Offset: 0x78
	// Line 180, Address: 0x12f024, Func Offset: 0x94
	// Line 181, Address: 0x12f030, Func Offset: 0xa0
	// Line 182, Address: 0x12f038, Func Offset: 0xa8
	// Line 184, Address: 0x12f048, Func Offset: 0xb8
	// Func End, Address: 0x12f064, Func Offset: 0xd4
}

// 
// Start address: 0x12f070
void SimpleMultiDrawTreeCnk(BH_PWORK* ewP, npobj* objP, _anon10* owP, int obj_num)
{
	// Line 189, Address: 0x12f070, Func Offset: 0
	// Line 191, Address: 0x12f094, Func Offset: 0x24
	// Line 192, Address: 0x12f09c, Func Offset: 0x2c
	// Line 193, Address: 0x12f0a8, Func Offset: 0x38
	// Line 194, Address: 0x12f0bc, Func Offset: 0x4c
	// Line 196, Address: 0x12f0d0, Func Offset: 0x60
	// Line 197, Address: 0x12f0e4, Func Offset: 0x74
	// Line 198, Address: 0x12f0e8, Func Offset: 0x78
	// Line 199, Address: 0x12f104, Func Offset: 0x94
	// Line 200, Address: 0x12f110, Func Offset: 0xa0
	// Line 201, Address: 0x12f118, Func Offset: 0xa8
	// Line 203, Address: 0x12f128, Func Offset: 0xb8
	// Func End, Address: 0x12f144, Func Offset: 0xd4
}

// 
// Start address: 0x12f150
void EasyDrawTreeCnk(BH_PWORK* ewP, npobj* objP, _anon10* owP, int obj_num)
{
	// Line 208, Address: 0x12f150, Func Offset: 0
	// Line 210, Address: 0x12f174, Func Offset: 0x24
	// Line 211, Address: 0x12f17c, Func Offset: 0x2c
	// Line 212, Address: 0x12f188, Func Offset: 0x38
	// Line 213, Address: 0x12f19c, Func Offset: 0x4c
	// Line 215, Address: 0x12f1b0, Func Offset: 0x60
	// Line 216, Address: 0x12f1c4, Func Offset: 0x74
	// Line 217, Address: 0x12f1c8, Func Offset: 0x78
	// Line 218, Address: 0x12f1e4, Func Offset: 0x94
	// Line 219, Address: 0x12f1f0, Func Offset: 0xa0
	// Line 220, Address: 0x12f1f8, Func Offset: 0xa8
	// Line 222, Address: 0x12f208, Func Offset: 0xb8
	// Func End, Address: 0x12f224, Func Offset: 0xd4
}

// 
// Start address: 0x12f230
void SimpleDrawTreeCnk(BH_PWORK* ewP, npobj* objP, _anon10* owP, int obj_num)
{
	// Line 227, Address: 0x12f230, Func Offset: 0
	// Line 229, Address: 0x12f254, Func Offset: 0x24
	// Line 230, Address: 0x12f25c, Func Offset: 0x2c
	// Line 231, Address: 0x12f268, Func Offset: 0x38
	// Line 232, Address: 0x12f27c, Func Offset: 0x4c
	// Line 234, Address: 0x12f290, Func Offset: 0x60
	// Line 235, Address: 0x12f2a4, Func Offset: 0x74
	// Line 236, Address: 0x12f2a8, Func Offset: 0x78
	// Line 237, Address: 0x12f2c4, Func Offset: 0x94
	// Line 238, Address: 0x12f2d0, Func Offset: 0xa0
	// Line 239, Address: 0x12f2d8, Func Offset: 0xa8
	// Line 241, Address: 0x12f2e8, Func Offset: 0xb8
	// Func End, Address: 0x12f304, Func Offset: 0xd4
}

// 
// Start address: 0x12f310
void bhCalcModel(BH_PWORK* ewP)
{
	// Line 251, Address: 0x12f310, Func Offset: 0
	// Line 253, Address: 0x12f31c, Func Offset: 0xc
	// Line 259, Address: 0x12f32c, Func Offset: 0x1c
	// Line 260, Address: 0x12f358, Func Offset: 0x48
	// Line 261, Address: 0x12f36c, Func Offset: 0x5c
	// Line 262, Address: 0x12f384, Func Offset: 0x74
	// Line 263, Address: 0x12f398, Func Offset: 0x88
	// Line 264, Address: 0x12f3a0, Func Offset: 0x90
	// Line 265, Address: 0x12f3ac, Func Offset: 0x9c
	// Line 266, Address: 0x12f3b4, Func Offset: 0xa4
	// Line 267, Address: 0x12f3c8, Func Offset: 0xb8
	// Line 271, Address: 0x12f3dc, Func Offset: 0xcc
	// Line 272, Address: 0x12f3e8, Func Offset: 0xd8
	// Func End, Address: 0x12f3f8, Func Offset: 0xe8
}

// 
// Start address: 0x12f400
void bhCalcTree(float basP[16], _anon7* mlwP)
{
	int obj_num;
	npobj* objP;
	_anon10* owP;
	// Line 286, Address: 0x12f400, Func Offset: 0
	// Line 287, Address: 0x12f418, Func Offset: 0x18
	// Line 288, Address: 0x12f41c, Func Offset: 0x1c
	// Line 291, Address: 0x12f424, Func Offset: 0x24
	// Line 293, Address: 0x12f42c, Func Offset: 0x2c
	// Line 295, Address: 0x12f43c, Func Offset: 0x3c
	// Line 297, Address: 0x12f448, Func Offset: 0x48
	// Line 299, Address: 0x12f460, Func Offset: 0x60
	// Line 300, Address: 0x12f474, Func Offset: 0x74
	// Line 301, Address: 0x12f488, Func Offset: 0x88
	// Line 302, Address: 0x12f4a8, Func Offset: 0xa8
	// Line 304, Address: 0x12f4b8, Func Offset: 0xb8
	// Line 305, Address: 0x12f4d0, Func Offset: 0xd0
	// Line 307, Address: 0x12f4e0, Func Offset: 0xe0
	// Line 309, Address: 0x12f4e8, Func Offset: 0xe8
	// Func End, Address: 0x12f504, Func Offset: 0x104
}

