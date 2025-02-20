typedef struct npobj;
typedef struct BH_PWORK;
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
typedef struct _anon30;
typedef struct _anon31;
typedef struct _anon32;

typedef void(*type_0)(BH_PWORK*);
typedef void(*type_63)(BH_PWORK*);
typedef void(*type_73)(void*);
typedef void(*type_78)(BH_PWORK*);

typedef unsigned int type_1[4];
typedef void(*type_2)(BH_PWORK*)[10];
typedef _anon0* type_3[512];
typedef _anon0* type_4[32];
typedef _anon1* type_5[16];
typedef _anon0* type_6[32];
typedef _anon0* type_7[512];
typedef _anon1* type_8[16][16];
typedef _anon1* type_9[16][16][100];
typedef char type_10[8];
typedef _anon3 type_11[4];
typedef _anon0* type_12[32];
typedef _anon0* type_13[512];
typedef _anon1* type_14[1300];
typedef _anon3 type_15[4];
typedef char type_16[32];
typedef _anon0* type_17[512];
typedef _anon1* type_18[200];
typedef short type_19[32];
typedef _anon13 type_20[1];
typedef _anon0* type_21[128];
typedef unsigned int type_22[1];
typedef _anon5 type_23[256];
typedef _anon1* type_24[8];
typedef int* type_25[16];
typedef _anon0* type_26[128];
typedef npobj* type_27[16];
typedef _anon0* type_28[128];
typedef int type_29[4];
typedef _anon1* type_30[16];
typedef unsigned int type_31[4];
typedef _anon8 type_32[16];
typedef _anon0* type_33[512];
typedef char type_34[256];
typedef float type_35[4];
typedef float type_36[4];
typedef float type_37[4];
typedef _anon4* type_38[128];
typedef unsigned char type_39[64];
typedef float type_40[16];
typedef char type_41[8];
typedef int type_42[4];
typedef void* type_43[2];
typedef _anon1* type_44[256];
typedef int type_45[4];
typedef unsigned char* type_46[256];
typedef unsigned int type_47[2];
typedef short type_48[256];
typedef _anon20 type_49[4];
typedef float type_50[3];
typedef short type_51[256];
typedef int type_52[3];
typedef int type_53[8];
typedef float type_54[3];
typedef _anon1* type_55[256];
typedef _anon7 type_56[256];
typedef _anon13 type_57[450];
typedef _anon22 type_58[16];
typedef short type_59[256];
typedef char type_60[3];
typedef int type_61[64];
typedef _anon8 type_62[450];
typedef void(*type_64)(BH_PWORK*)[1];
typedef _anon0 type_65[0];
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
typedef void(*type_79)(BH_PWORK*)[6];
typedef _anon27 type_80[64];
typedef unsigned int type_81[32];
typedef _anon27 type_82[64];
typedef unsigned int type_83[16];
typedef unsigned int type_84[3];
typedef BH_PWORK* type_85[16];
typedef unsigned int type_86[8];
typedef unsigned int type_87[1];
typedef unsigned int type_88[384];
typedef unsigned int type_89[2];
typedef unsigned char type_90[2];
typedef unsigned int type_91[4];
typedef int* type_92[16];
typedef char type_93[32];
typedef npobj* type_94[16];
typedef char type_95[64];
typedef _anon1* type_96[16];
typedef char type_97[4];
typedef _anon8 type_98[16];
typedef short type_99[4];
typedef unsigned char type_100[4];
typedef _anon23 type_101[16];
typedef unsigned int type_102[32];
typedef _anon3 type_103[32];
typedef _anon0* type_104[512];
typedef _anon0* type_105[128];
typedef _anon0* type_106[512];
typedef unsigned char type_107[64];
typedef _anon0* type_108[512];

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
	_anon32 watr;
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
	_anon31 cspr;
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
	float x;
	float y;
	float z;
};

struct _anon4
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon12* md2P;
	unsigned short* atrP;
};

struct _anon5
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon6
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

struct _anon7
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
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
	_anon29* info;
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
	void* texaddr;
	_anon6 texsurface;
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
	_anon19* light;
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
	_anon3 ply_pos;
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
	_anon7 txbp[256];
	unsigned char* ef_psp;
	_anon13 ef_tex[450];
	_anon1 ef_tlist;
	_anon26 ef;
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
	_anon11 ren_info;
	_anon13 ren_tex[1];
	_anon1 ren_tlist;
	_anon5 rpb[256];
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
	_anon28 mr_pl;
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
	_anon27* pl_htp;
	int costume;
	_anon3 hd_pos;
	_anon3 apos;
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
	_anon3 ufo_pos;
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
	_anon3 ghtp[32];
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
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon19
{
	float mtrx[16];
	_anon3 pnt;
	_anon3 vctr;
	int stat;
	int reserve;
	_anon24 ltcal;
	_anon30 attr;
};

struct _anon20
{
	_anon3 ps;
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
	_anon3 center;
	float r;
};

struct _anon22
{
	float x;
	float y;
};

struct _anon23
{
	_anon3 c1;
	_anon3 c2;
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
	_anon3 lpnt;
	_anon3 lvctr;
	_anon3 lmvctr;
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
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon29
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

struct _anon30
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

struct _anon31
{
	_anon3 c;
	float r;
};

struct _anon32
{
	_anon3 c1;
	_anon3 c2;
	float r;
};

void(*bhEne11_Mode0)(BH_PWORK*)[6];
void(*bhEne11_BrainType)(BH_PWORK*)[1];
void(*bhEne11_MoveMode2)(BH_PWORK*)[10];
BH_PWORK* plp;
_anon0 eff[0];
_anon16* sys;

void bhEne11(BH_PWORK* epw);
void bhEne11_Init(BH_PWORK* epw);
void bhEne11_Brain(BH_PWORK* epw);
void bhEne11_BR00(BH_PWORK* epw);
void bhEne11_Move(BH_PWORK* epw);
void bhEne11_MV00(BH_PWORK* epw);
void bhEne11_MV01(BH_PWORK* epw);
void bhEne11_MV02(BH_PWORK* epw);
void bhEne11_MV03(BH_PWORK* epw);
void bhEne11_MV04(BH_PWORK* epw);
void bhEne11_MV05(BH_PWORK* epw);
void bhEne11_MV06(BH_PWORK* epw);
void bhEne11_MV07(BH_PWORK* epw);
void bhEne11_MV08(BH_PWORK* epw);
void bhEne11_MV09(BH_PWORK* epw);
void bhEne11_Nage();
void bhEne11_Damage();
void bhEne11_Die();
void bhEne11_GoFoward(BH_PWORK* epw);
void bhEne11_CollisionWalls(BH_PWORK* epw);
int bhEne11_CollisionBoxEdge2(BH_PWORK* epw);
void bhEne11_CameraSet(BH_PWORK* epw, _anon3* vec, int hcnt);
void bhEne11_MoveNearWall(BH_PWORK* epw);
void bhEne11_LightControl(BH_PWORK* epw, int flg);
int bhEne11_SelectDir(BH_PWORK* epw);

// 
// Start address: 0x1d3240
void bhEne11(BH_PWORK* epw)
{
	int ang;
	_anon3 v;
	unsigned int flg;
	// Line 169, Address: 0x1d3240, Func Offset: 0
	// Line 173, Address: 0x1d3254, Func Offset: 0x14
	// Line 175, Address: 0x1d3274, Func Offset: 0x34
	// Line 177, Address: 0x1d3284, Func Offset: 0x44
	// Line 180, Address: 0x1d3290, Func Offset: 0x50
	// Line 181, Address: 0x1d3294, Func Offset: 0x54
	// Line 182, Address: 0x1d32a0, Func Offset: 0x60
	// Line 183, Address: 0x1d32b4, Func Offset: 0x74
	// Line 184, Address: 0x1d32bc, Func Offset: 0x7c
	// Line 186, Address: 0x1d32c0, Func Offset: 0x80
	// Line 187, Address: 0x1d32cc, Func Offset: 0x8c
	// Line 189, Address: 0x1d32d4, Func Offset: 0x94
	// Line 190, Address: 0x1d32e8, Func Offset: 0xa8
	// Line 191, Address: 0x1d32ec, Func Offset: 0xac
	// Line 192, Address: 0x1d32f0, Func Offset: 0xb0
	// Line 193, Address: 0x1d32f4, Func Offset: 0xb4
	// Line 195, Address: 0x1d3308, Func Offset: 0xc8
	// Line 202, Address: 0x1d3314, Func Offset: 0xd4
	// Line 195, Address: 0x1d3318, Func Offset: 0xd8
	// Line 202, Address: 0x1d3320, Func Offset: 0xe0
	// Line 204, Address: 0x1d3360, Func Offset: 0x120
	// Line 205, Address: 0x1d337c, Func Offset: 0x13c
	// Line 206, Address: 0x1d338c, Func Offset: 0x14c
	// Line 205, Address: 0x1d3390, Func Offset: 0x150
	// Line 206, Address: 0x1d3394, Func Offset: 0x154
	// Line 207, Address: 0x1d33a4, Func Offset: 0x164
	// Line 206, Address: 0x1d33a8, Func Offset: 0x168
	// Line 207, Address: 0x1d33ac, Func Offset: 0x16c
	// Line 206, Address: 0x1d33b0, Func Offset: 0x170
	// Line 207, Address: 0x1d33b4, Func Offset: 0x174
	// Line 208, Address: 0x1d33c8, Func Offset: 0x188
	// Line 210, Address: 0x1d33d0, Func Offset: 0x190
	// Line 211, Address: 0x1d33d4, Func Offset: 0x194
	// Line 212, Address: 0x1d33dc, Func Offset: 0x19c
	// Line 213, Address: 0x1d33f8, Func Offset: 0x1b8
	// Line 215, Address: 0x1d3400, Func Offset: 0x1c0
	// Line 216, Address: 0x1d3404, Func Offset: 0x1c4
	// Line 217, Address: 0x1d340c, Func Offset: 0x1cc
	// Line 218, Address: 0x1d3428, Func Offset: 0x1e8
	// Line 220, Address: 0x1d3430, Func Offset: 0x1f0
	// Line 222, Address: 0x1d3438, Func Offset: 0x1f8
	// Line 221, Address: 0x1d3440, Func Offset: 0x200
	// Line 222, Address: 0x1d3444, Func Offset: 0x204
	// Line 223, Address: 0x1d3458, Func Offset: 0x218
	// Line 225, Address: 0x1d3460, Func Offset: 0x220
	// Line 227, Address: 0x1d3468, Func Offset: 0x228
	// Line 226, Address: 0x1d3470, Func Offset: 0x230
	// Line 227, Address: 0x1d3474, Func Offset: 0x234
	// Line 230, Address: 0x1d348c, Func Offset: 0x24c
	// Line 235, Address: 0x1d349c, Func Offset: 0x25c
	// Line 238, Address: 0x1d34a8, Func Offset: 0x268
	// Line 239, Address: 0x1d34b0, Func Offset: 0x270
	// Line 240, Address: 0x1d34c4, Func Offset: 0x284
	// Line 243, Address: 0x1d34d0, Func Offset: 0x290
	// Line 245, Address: 0x1d34d8, Func Offset: 0x298
	// Func End, Address: 0x1d34ec, Func Offset: 0x2ac
}

// 
// Start address: 0x1d34f0
void bhEne11_Init(BH_PWORK* epw)
{
	int eff_id;
	// Line 255, Address: 0x1d34f0, Func Offset: 0
	// Line 259, Address: 0x1d34fc, Func Offset: 0xc
	// Line 268, Address: 0x1d3504, Func Offset: 0x14
	// Line 259, Address: 0x1d350c, Func Offset: 0x1c
	// Line 263, Address: 0x1d3510, Func Offset: 0x20
	// Line 259, Address: 0x1d3514, Func Offset: 0x24
	// Line 264, Address: 0x1d3518, Func Offset: 0x28
	// Line 265, Address: 0x1d351c, Func Offset: 0x2c
	// Line 266, Address: 0x1d3520, Func Offset: 0x30
	// Line 271, Address: 0x1d3524, Func Offset: 0x34
	// Line 259, Address: 0x1d3528, Func Offset: 0x38
	// Line 262, Address: 0x1d3530, Func Offset: 0x40
	// Line 263, Address: 0x1d353c, Func Offset: 0x4c
	// Line 264, Address: 0x1d3548, Func Offset: 0x58
	// Line 265, Address: 0x1d354c, Func Offset: 0x5c
	// Line 266, Address: 0x1d3550, Func Offset: 0x60
	// Line 267, Address: 0x1d3554, Func Offset: 0x64
	// Line 268, Address: 0x1d3558, Func Offset: 0x68
	// Line 271, Address: 0x1d355c, Func Offset: 0x6c
	// Line 272, Address: 0x1d3560, Func Offset: 0x70
	// Line 273, Address: 0x1d3564, Func Offset: 0x74
	// Line 274, Address: 0x1d3568, Func Offset: 0x78
	// Line 277, Address: 0x1d356c, Func Offset: 0x7c
	// Line 278, Address: 0x1d3578, Func Offset: 0x88
	// Line 280, Address: 0x1d3588, Func Offset: 0x98
	// Line 281, Address: 0x1d3590, Func Offset: 0xa0
	// Line 283, Address: 0x1d359c, Func Offset: 0xac
	// Line 284, Address: 0x1d35a8, Func Offset: 0xb8
	// Line 285, Address: 0x1d35b4, Func Offset: 0xc4
	// Line 287, Address: 0x1d35bc, Func Offset: 0xcc
	// Line 288, Address: 0x1d35cc, Func Offset: 0xdc
	// Line 289, Address: 0x1d35d8, Func Offset: 0xe8
	// Line 291, Address: 0x1d35e4, Func Offset: 0xf4
	// Line 294, Address: 0x1d35ec, Func Offset: 0xfc
	// Line 295, Address: 0x1d35fc, Func Offset: 0x10c
	// Line 296, Address: 0x1d3608, Func Offset: 0x118
	// Line 307, Address: 0x1d360c, Func Offset: 0x11c
	// Line 295, Address: 0x1d3610, Func Offset: 0x120
	// Line 296, Address: 0x1d361c, Func Offset: 0x12c
	// Line 307, Address: 0x1d3624, Func Offset: 0x134
	// Line 296, Address: 0x1d362c, Func Offset: 0x13c
	// Line 297, Address: 0x1d3638, Func Offset: 0x148
	// Line 298, Address: 0x1d364c, Func Offset: 0x15c
	// Line 299, Address: 0x1d3660, Func Offset: 0x170
	// Line 300, Address: 0x1d3674, Func Offset: 0x184
	// Line 301, Address: 0x1d3688, Func Offset: 0x198
	// Line 302, Address: 0x1d369c, Func Offset: 0x1ac
	// Line 303, Address: 0x1d36b0, Func Offset: 0x1c0
	// Line 304, Address: 0x1d36c4, Func Offset: 0x1d4
	// Line 305, Address: 0x1d36d8, Func Offset: 0x1e8
	// Line 307, Address: 0x1d36ec, Func Offset: 0x1fc
	// Line 308, Address: 0x1d3704, Func Offset: 0x214
	// Line 309, Address: 0x1d370c, Func Offset: 0x21c
	// Line 310, Address: 0x1d3734, Func Offset: 0x244
	// Line 312, Address: 0x1d373c, Func Offset: 0x24c
	// Line 314, Address: 0x1d3744, Func Offset: 0x254
	// Line 315, Address: 0x1d3748, Func Offset: 0x258
	// Line 319, Address: 0x1d3754, Func Offset: 0x264
	// Line 320, Address: 0x1d375c, Func Offset: 0x26c
	// Line 321, Address: 0x1d3764, Func Offset: 0x274
	// Line 324, Address: 0x1d376c, Func Offset: 0x27c
	// Line 327, Address: 0x1d3774, Func Offset: 0x284
	// Line 328, Address: 0x1d3784, Func Offset: 0x294
	// Func End, Address: 0x1d3794, Func Offset: 0x2a4
}

// 
// Start address: 0x1d37a0
void bhEne11_Brain(BH_PWORK* epw)
{
	// Line 339, Address: 0x1d37a0, Func Offset: 0
	// Func End, Address: 0x1d37b0, Func Offset: 0x10
}

// 
// Start address: 0x1d37b0
void bhEne11_BR00(BH_PWORK* epw)
{
	// Line 352, Address: 0x1d37b0, Func Offset: 0
	// Line 354, Address: 0x1d37cc, Func Offset: 0x1c
	// Line 356, Address: 0x1d37dc, Func Offset: 0x2c
	// Line 357, Address: 0x1d37f4, Func Offset: 0x44
	// Line 359, Address: 0x1d37fc, Func Offset: 0x4c
	// Line 361, Address: 0x1d381c, Func Offset: 0x6c
	// Line 362, Address: 0x1d3830, Func Offset: 0x80
	// Line 363, Address: 0x1d3838, Func Offset: 0x88
	// Line 366, Address: 0x1d3844, Func Offset: 0x94
	// Func End, Address: 0x1d384c, Func Offset: 0x9c
}

// 
// Start address: 0x1d3850
void bhEne11_Move(BH_PWORK* epw)
{
	// Line 376, Address: 0x1d3850, Func Offset: 0
	// Line 378, Address: 0x1d385c, Func Offset: 0xc
	// Line 379, Address: 0x1d386c, Func Offset: 0x1c
	// Line 382, Address: 0x1d3874, Func Offset: 0x24
	// Line 383, Address: 0x1d3894, Func Offset: 0x44
	// Func End, Address: 0x1d38a4, Func Offset: 0x54
}

// 
// Start address: 0x1d38b0
void bhEne11_MV00(BH_PWORK* epw)
{
	// Line 394, Address: 0x1d38b0, Func Offset: 0
	// Line 397, Address: 0x1d38d0, Func Offset: 0x20
	// Line 398, Address: 0x1d38d8, Func Offset: 0x28
	// Line 400, Address: 0x1d38e4, Func Offset: 0x34
	// Line 401, Address: 0x1d38f4, Func Offset: 0x44
	// Line 402, Address: 0x1d38fc, Func Offset: 0x4c
	// Line 404, Address: 0x1d3900, Func Offset: 0x50
	// Line 406, Address: 0x1d390c, Func Offset: 0x5c
	// Line 407, Address: 0x1d3914, Func Offset: 0x64
	// Line 412, Address: 0x1d391c, Func Offset: 0x6c
	// Func End, Address: 0x1d3924, Func Offset: 0x74
}

// 
// Start address: 0x1d3930
void bhEne11_MV01(BH_PWORK* epw)
{
	int ang;
	_anon3 v;
	// Line 422, Address: 0x1d3930, Func Offset: 0
	// Line 423, Address: 0x1d3940, Func Offset: 0x10
	// Line 425, Address: 0x1d3960, Func Offset: 0x30
	// Line 426, Address: 0x1d3968, Func Offset: 0x38
	// Line 427, Address: 0x1d3970, Func Offset: 0x40
	// Line 431, Address: 0x1d3974, Func Offset: 0x44
	// Line 433, Address: 0x1d3980, Func Offset: 0x50
	// Line 435, Address: 0x1d398c, Func Offset: 0x5c
	// Line 437, Address: 0x1d39a8, Func Offset: 0x78
	// Line 444, Address: 0x1d39b4, Func Offset: 0x84
	// Line 445, Address: 0x1d39c8, Func Offset: 0x98
	// Line 446, Address: 0x1d39d8, Func Offset: 0xa8
	// Line 445, Address: 0x1d39dc, Func Offset: 0xac
	// Line 446, Address: 0x1d39e0, Func Offset: 0xb0
	// Line 447, Address: 0x1d39f0, Func Offset: 0xc0
	// Line 446, Address: 0x1d39f4, Func Offset: 0xc4
	// Line 447, Address: 0x1d39f8, Func Offset: 0xc8
	// Line 446, Address: 0x1d39fc, Func Offset: 0xcc
	// Line 447, Address: 0x1d3a00, Func Offset: 0xd0
	// Line 448, Address: 0x1d3a18, Func Offset: 0xe8
	// Line 450, Address: 0x1d3a1c, Func Offset: 0xec
	// Line 448, Address: 0x1d3a20, Func Offset: 0xf0
	// Line 450, Address: 0x1d3a28, Func Offset: 0xf8
	// Line 451, Address: 0x1d3a34, Func Offset: 0x104
	// Line 454, Address: 0x1d3a48, Func Offset: 0x118
	// Line 455, Address: 0x1d3a54, Func Offset: 0x124
	// Line 456, Address: 0x1d3a64, Func Offset: 0x134
	// Line 457, Address: 0x1d3a74, Func Offset: 0x144
	// Line 459, Address: 0x1d3a84, Func Offset: 0x154
	// Line 461, Address: 0x1d3a90, Func Offset: 0x160
	// Line 462, Address: 0x1d3a98, Func Offset: 0x168
	// Line 464, Address: 0x1d3aa0, Func Offset: 0x170
	// Line 466, Address: 0x1d3aa8, Func Offset: 0x178
	// Line 477, Address: 0x1d3ab0, Func Offset: 0x180
	// Line 478, Address: 0x1d3ad8, Func Offset: 0x1a8
	// Line 479, Address: 0x1d3aec, Func Offset: 0x1bc
	// Line 481, Address: 0x1d3af4, Func Offset: 0x1c4
	// Line 487, Address: 0x1d3b08, Func Offset: 0x1d8
	// Line 488, Address: 0x1d3b18, Func Offset: 0x1e8
	// Line 489, Address: 0x1d3b20, Func Offset: 0x1f0
	// Line 490, Address: 0x1d3b28, Func Offset: 0x1f8
	// Line 492, Address: 0x1d3b2c, Func Offset: 0x1fc
	// Func End, Address: 0x1d3b40, Func Offset: 0x210
}

// 
// Start address: 0x1d3b40
void bhEne11_MV02(BH_PWORK* epw)
{
	// Line 502, Address: 0x1d3b40, Func Offset: 0
	// Line 503, Address: 0x1d3b50, Func Offset: 0x10
	// Line 506, Address: 0x1d3b70, Func Offset: 0x30
	// Line 507, Address: 0x1d3b78, Func Offset: 0x38
	// Line 508, Address: 0x1d3b7c, Func Offset: 0x3c
	// Line 507, Address: 0x1d3b84, Func Offset: 0x44
	// Line 508, Address: 0x1d3b8c, Func Offset: 0x4c
	// Line 510, Address: 0x1d3b90, Func Offset: 0x50
	// Line 512, Address: 0x1d3b9c, Func Offset: 0x5c
	// Line 513, Address: 0x1d3bac, Func Offset: 0x6c
	// Line 514, Address: 0x1d3bb4, Func Offset: 0x74
	// Line 516, Address: 0x1d3bb8, Func Offset: 0x78
	// Line 518, Address: 0x1d3bc4, Func Offset: 0x84
	// Line 519, Address: 0x1d3bcc, Func Offset: 0x8c
	// Line 524, Address: 0x1d3bd4, Func Offset: 0x94
	// Line 525, Address: 0x1d3bfc, Func Offset: 0xbc
	// Line 526, Address: 0x1d3c10, Func Offset: 0xd0
	// Line 528, Address: 0x1d3c18, Func Offset: 0xd8
	// Line 532, Address: 0x1d3c2c, Func Offset: 0xec
	// Func End, Address: 0x1d3c3c, Func Offset: 0xfc
}

// 
// Start address: 0x1d3c40
void bhEne11_MV03(BH_PWORK* epw)
{
	_anon3 v;
	// Line 543, Address: 0x1d3c40, Func Offset: 0
	// Line 544, Address: 0x1d3c4c, Func Offset: 0xc
	// Line 546, Address: 0x1d3c6c, Func Offset: 0x2c
	// Line 548, Address: 0x1d3ca4, Func Offset: 0x64
	// Line 550, Address: 0x1d3ca8, Func Offset: 0x68
	// Line 552, Address: 0x1d3cb0, Func Offset: 0x70
	// Line 553, Address: 0x1d3cb8, Func Offset: 0x78
	// Line 556, Address: 0x1d3cc0, Func Offset: 0x80
	// Line 557, Address: 0x1d3cd0, Func Offset: 0x90
	// Line 559, Address: 0x1d3cd8, Func Offset: 0x98
	// Line 560, Address: 0x1d3ce0, Func Offset: 0xa0
	// Line 563, Address: 0x1d3ce8, Func Offset: 0xa8
	// Line 564, Address: 0x1d3cf8, Func Offset: 0xb8
	// Line 566, Address: 0x1d3d00, Func Offset: 0xc0
	// Line 567, Address: 0x1d3d08, Func Offset: 0xc8
	// Line 570, Address: 0x1d3d10, Func Offset: 0xd0
	// Line 573, Address: 0x1d3d20, Func Offset: 0xe0
	// Line 574, Address: 0x1d3d28, Func Offset: 0xe8
	// Line 576, Address: 0x1d3d34, Func Offset: 0xf4
	// Line 577, Address: 0x1d3d40, Func Offset: 0x100
	// Line 578, Address: 0x1d3d50, Func Offset: 0x110
	// Line 579, Address: 0x1d3d58, Func Offset: 0x118
	// Line 581, Address: 0x1d3d5c, Func Offset: 0x11c
	// Line 583, Address: 0x1d3d68, Func Offset: 0x128
	// Line 584, Address: 0x1d3d70, Func Offset: 0x130
	// Line 589, Address: 0x1d3d78, Func Offset: 0x138
	// Line 592, Address: 0x1d3d84, Func Offset: 0x144
	// Line 594, Address: 0x1d3dc0, Func Offset: 0x180
	// Line 595, Address: 0x1d3dc4, Func Offset: 0x184
	// Line 596, Address: 0x1d3dc8, Func Offset: 0x188
	// Line 598, Address: 0x1d3dd0, Func Offset: 0x190
	// Line 599, Address: 0x1d3dd4, Func Offset: 0x194
	// Line 600, Address: 0x1d3dd8, Func Offset: 0x198
	// Line 602, Address: 0x1d3de0, Func Offset: 0x1a0
	// Line 604, Address: 0x1d3de8, Func Offset: 0x1a8
	// Line 606, Address: 0x1d3df0, Func Offset: 0x1b0
	// Line 607, Address: 0x1d3df8, Func Offset: 0x1b8
	// Line 610, Address: 0x1d3dfc, Func Offset: 0x1bc
	// Line 612, Address: 0x1d3e1c, Func Offset: 0x1dc
	// Line 613, Address: 0x1d3e2c, Func Offset: 0x1ec
	// Line 617, Address: 0x1d3e40, Func Offset: 0x200
	// Func End, Address: 0x1d3e50, Func Offset: 0x210
}

// 
// Start address: 0x1d3e50
void bhEne11_MV04(BH_PWORK* epw)
{
	float f;
	_anon3 v;
	// Line 627, Address: 0x1d3e50, Func Offset: 0
	// Line 628, Address: 0x1d3e5c, Func Offset: 0xc
	// Line 630, Address: 0x1d3e7c, Func Offset: 0x2c
	// Line 631, Address: 0x1d3e84, Func Offset: 0x34
	// Line 632, Address: 0x1d3e8c, Func Offset: 0x3c
	// Line 636, Address: 0x1d3e90, Func Offset: 0x40
	// Line 632, Address: 0x1d3e94, Func Offset: 0x44
	// Line 636, Address: 0x1d3eac, Func Offset: 0x5c
	// Line 637, Address: 0x1d3eb4, Func Offset: 0x64
	// Line 639, Address: 0x1d3ec0, Func Offset: 0x70
	// Line 644, Address: 0x1d3ecc, Func Offset: 0x7c
	// Line 647, Address: 0x1d3ee4, Func Offset: 0x94
	// Line 644, Address: 0x1d3ee8, Func Offset: 0x98
	// Line 645, Address: 0x1d3eec, Func Offset: 0x9c
	// Line 647, Address: 0x1d3ef0, Func Offset: 0xa0
	// Line 644, Address: 0x1d3ef4, Func Offset: 0xa4
	// Line 645, Address: 0x1d3ef8, Func Offset: 0xa8
	// Line 646, Address: 0x1d3f08, Func Offset: 0xb8
	// Line 647, Address: 0x1d3f1c, Func Offset: 0xcc
	// Line 648, Address: 0x1d3f34, Func Offset: 0xe4
	// Line 650, Address: 0x1d3f38, Func Offset: 0xe8
	// Line 648, Address: 0x1d3f3c, Func Offset: 0xec
	// Line 650, Address: 0x1d3f44, Func Offset: 0xf4
	// Line 651, Address: 0x1d3f50, Func Offset: 0x100
	// Line 654, Address: 0x1d3f64, Func Offset: 0x114
	// Line 655, Address: 0x1d3f70, Func Offset: 0x120
	// Line 656, Address: 0x1d3f80, Func Offset: 0x130
	// Line 657, Address: 0x1d3f90, Func Offset: 0x140
	// Line 659, Address: 0x1d3fa0, Func Offset: 0x150
	// Line 661, Address: 0x1d3fac, Func Offset: 0x15c
	// Line 662, Address: 0x1d3fb4, Func Offset: 0x164
	// Line 664, Address: 0x1d3fbc, Func Offset: 0x16c
	// Line 666, Address: 0x1d3fc4, Func Offset: 0x174
	// Line 677, Address: 0x1d3fcc, Func Offset: 0x17c
	// Line 678, Address: 0x1d3ff4, Func Offset: 0x1a4
	// Line 679, Address: 0x1d4008, Func Offset: 0x1b8
	// Line 681, Address: 0x1d4010, Func Offset: 0x1c0
	// Line 687, Address: 0x1d4024, Func Offset: 0x1d4
	// Line 688, Address: 0x1d4034, Func Offset: 0x1e4
	// Line 689, Address: 0x1d403c, Func Offset: 0x1ec
	// Line 690, Address: 0x1d4044, Func Offset: 0x1f4
	// Line 692, Address: 0x1d4048, Func Offset: 0x1f8
	// Func End, Address: 0x1d4058, Func Offset: 0x208
}

// 
// Start address: 0x1d4060
void bhEne11_MV05(BH_PWORK* epw)
{
	float f;
	_anon3 v;
	// Line 702, Address: 0x1d4060, Func Offset: 0
	// Line 703, Address: 0x1d406c, Func Offset: 0xc
	// Line 705, Address: 0x1d408c, Func Offset: 0x2c
	// Line 706, Address: 0x1d4094, Func Offset: 0x34
	// Line 707, Address: 0x1d409c, Func Offset: 0x3c
	// Line 711, Address: 0x1d40a0, Func Offset: 0x40
	// Line 712, Address: 0x1d40ac, Func Offset: 0x4c
	// Line 714, Address: 0x1d40b8, Func Offset: 0x58
	// Line 719, Address: 0x1d40c4, Func Offset: 0x64
	// Line 722, Address: 0x1d40dc, Func Offset: 0x7c
	// Line 719, Address: 0x1d40e0, Func Offset: 0x80
	// Line 720, Address: 0x1d40e4, Func Offset: 0x84
	// Line 722, Address: 0x1d40e8, Func Offset: 0x88
	// Line 719, Address: 0x1d40ec, Func Offset: 0x8c
	// Line 720, Address: 0x1d40f0, Func Offset: 0x90
	// Line 721, Address: 0x1d40fc, Func Offset: 0x9c
	// Line 722, Address: 0x1d410c, Func Offset: 0xac
	// Line 723, Address: 0x1d4124, Func Offset: 0xc4
	// Line 725, Address: 0x1d4128, Func Offset: 0xc8
	// Line 723, Address: 0x1d412c, Func Offset: 0xcc
	// Line 725, Address: 0x1d4134, Func Offset: 0xd4
	// Line 726, Address: 0x1d4140, Func Offset: 0xe0
	// Line 729, Address: 0x1d4154, Func Offset: 0xf4
	// Line 730, Address: 0x1d4160, Func Offset: 0x100
	// Line 731, Address: 0x1d4170, Func Offset: 0x110
	// Line 732, Address: 0x1d4180, Func Offset: 0x120
	// Line 734, Address: 0x1d4190, Func Offset: 0x130
	// Line 736, Address: 0x1d419c, Func Offset: 0x13c
	// Line 737, Address: 0x1d41a4, Func Offset: 0x144
	// Line 739, Address: 0x1d41ac, Func Offset: 0x14c
	// Line 741, Address: 0x1d41b4, Func Offset: 0x154
	// Line 753, Address: 0x1d41bc, Func Offset: 0x15c
	// Line 754, Address: 0x1d41e4, Func Offset: 0x184
	// Line 755, Address: 0x1d41f8, Func Offset: 0x198
	// Line 757, Address: 0x1d4200, Func Offset: 0x1a0
	// Line 763, Address: 0x1d4214, Func Offset: 0x1b4
	// Line 764, Address: 0x1d4224, Func Offset: 0x1c4
	// Line 765, Address: 0x1d422c, Func Offset: 0x1cc
	// Line 766, Address: 0x1d4234, Func Offset: 0x1d4
	// Line 768, Address: 0x1d4238, Func Offset: 0x1d8
	// Func End, Address: 0x1d4248, Func Offset: 0x1e8
}

// 
// Start address: 0x1d4250
void bhEne11_MV06(BH_PWORK* epw)
{
	int ang;
	_anon3 v;
	// Line 778, Address: 0x1d4250, Func Offset: 0
	// Line 779, Address: 0x1d4260, Func Offset: 0x10
	// Line 781, Address: 0x1d4280, Func Offset: 0x30
	// Line 782, Address: 0x1d4288, Func Offset: 0x38
	// Line 783, Address: 0x1d4290, Func Offset: 0x40
	// Line 787, Address: 0x1d4298, Func Offset: 0x48
	// Line 788, Address: 0x1d42a4, Func Offset: 0x54
	// Line 790, Address: 0x1d42b0, Func Offset: 0x60
	// Line 797, Address: 0x1d42bc, Func Offset: 0x6c
	// Line 798, Address: 0x1d42e4, Func Offset: 0x94
	// Line 797, Address: 0x1d42e8, Func Offset: 0x98
	// Line 798, Address: 0x1d42ec, Func Offset: 0x9c
	// Line 800, Address: 0x1d4324, Func Offset: 0xd4
	// Line 801, Address: 0x1d4338, Func Offset: 0xe8
	// Line 800, Address: 0x1d433c, Func Offset: 0xec
	// Line 801, Address: 0x1d4340, Func Offset: 0xf0
	// Line 802, Address: 0x1d4358, Func Offset: 0x108
	// Line 804, Address: 0x1d4360, Func Offset: 0x110
	// Line 805, Address: 0x1d4374, Func Offset: 0x124
	// Line 804, Address: 0x1d4378, Func Offset: 0x128
	// Line 805, Address: 0x1d437c, Func Offset: 0x12c
	// Line 806, Address: 0x1d4394, Func Offset: 0x144
	// Line 808, Address: 0x1d439c, Func Offset: 0x14c
	// Line 809, Address: 0x1d43b0, Func Offset: 0x160
	// Line 808, Address: 0x1d43b4, Func Offset: 0x164
	// Line 809, Address: 0x1d43b8, Func Offset: 0x168
	// Line 810, Address: 0x1d43d0, Func Offset: 0x180
	// Line 812, Address: 0x1d43d8, Func Offset: 0x188
	// Line 813, Address: 0x1d43ec, Func Offset: 0x19c
	// Line 812, Address: 0x1d43f0, Func Offset: 0x1a0
	// Line 813, Address: 0x1d43f4, Func Offset: 0x1a4
	// Line 816, Address: 0x1d4410, Func Offset: 0x1c0
	// Line 817, Address: 0x1d4430, Func Offset: 0x1e0
	// Line 819, Address: 0x1d4434, Func Offset: 0x1e4
	// Line 817, Address: 0x1d4438, Func Offset: 0x1e8
	// Line 819, Address: 0x1d4440, Func Offset: 0x1f0
	// Line 820, Address: 0x1d444c, Func Offset: 0x1fc
	// Line 823, Address: 0x1d4460, Func Offset: 0x210
	// Line 824, Address: 0x1d446c, Func Offset: 0x21c
	// Line 825, Address: 0x1d447c, Func Offset: 0x22c
	// Line 826, Address: 0x1d448c, Func Offset: 0x23c
	// Line 828, Address: 0x1d449c, Func Offset: 0x24c
	// Line 830, Address: 0x1d44a8, Func Offset: 0x258
	// Line 831, Address: 0x1d44b0, Func Offset: 0x260
	// Line 833, Address: 0x1d44b8, Func Offset: 0x268
	// Line 835, Address: 0x1d44c0, Func Offset: 0x270
	// Line 847, Address: 0x1d44c8, Func Offset: 0x278
	// Line 848, Address: 0x1d44f0, Func Offset: 0x2a0
	// Line 849, Address: 0x1d4504, Func Offset: 0x2b4
	// Line 851, Address: 0x1d450c, Func Offset: 0x2bc
	// Line 857, Address: 0x1d4520, Func Offset: 0x2d0
	// Line 858, Address: 0x1d4530, Func Offset: 0x2e0
	// Line 859, Address: 0x1d4538, Func Offset: 0x2e8
	// Line 860, Address: 0x1d4540, Func Offset: 0x2f0
	// Line 862, Address: 0x1d4544, Func Offset: 0x2f4
	// Func End, Address: 0x1d4558, Func Offset: 0x308
}

// 
// Start address: 0x1d4560
void bhEne11_MV07(BH_PWORK* epw)
{
	// Line 872, Address: 0x1d4560, Func Offset: 0
	// Line 873, Address: 0x1d456c, Func Offset: 0xc
	// Line 875, Address: 0x1d4580, Func Offset: 0x20
	// Line 876, Address: 0x1d458c, Func Offset: 0x2c
	// Line 878, Address: 0x1d4598, Func Offset: 0x38
	// Func End, Address: 0x1d45a8, Func Offset: 0x48
}

// 
// Start address: 0x1d45b0
void bhEne11_MV08(BH_PWORK* epw)
{
	// Line 888, Address: 0x1d45b0, Func Offset: 0
	// Line 889, Address: 0x1d45bc, Func Offset: 0xc
	// Line 893, Address: 0x1d45d0, Func Offset: 0x20
	// Line 894, Address: 0x1d45dc, Func Offset: 0x2c
	// Line 896, Address: 0x1d45e8, Func Offset: 0x38
	// Func End, Address: 0x1d45f8, Func Offset: 0x48
}

// 
// Start address: 0x1d4600
void bhEne11_MV09(BH_PWORK* epw)
{
	_anon18* owk;
	// Line 906, Address: 0x1d4600, Func Offset: 0
	// Line 910, Address: 0x1d460c, Func Offset: 0xc
	// Line 911, Address: 0x1d4618, Func Offset: 0x18
	// Line 910, Address: 0x1d461c, Func Offset: 0x1c
	// Line 911, Address: 0x1d4620, Func Offset: 0x20
	// Line 912, Address: 0x1d4628, Func Offset: 0x28
	// Line 918, Address: 0x1d462c, Func Offset: 0x2c
	// Line 912, Address: 0x1d4634, Func Offset: 0x34
	// Line 913, Address: 0x1d4638, Func Offset: 0x38
	// Line 914, Address: 0x1d4640, Func Offset: 0x40
	// Line 917, Address: 0x1d4648, Func Offset: 0x48
	// Line 918, Address: 0x1d464c, Func Offset: 0x4c
	// Line 917, Address: 0x1d4650, Func Offset: 0x50
	// Line 918, Address: 0x1d4654, Func Offset: 0x54
	// Line 919, Address: 0x1d4668, Func Offset: 0x68
	// Line 920, Address: 0x1d4680, Func Offset: 0x80
	// Line 923, Address: 0x1d4698, Func Offset: 0x98
	// Line 924, Address: 0x1d46a0, Func Offset: 0xa0
	// Line 925, Address: 0x1d46ac, Func Offset: 0xac
	// Line 926, Address: 0x1d46b4, Func Offset: 0xb4
	// Line 929, Address: 0x1d46c0, Func Offset: 0xc0
	// Line 930, Address: 0x1d46c8, Func Offset: 0xc8
	// Line 931, Address: 0x1d46cc, Func Offset: 0xcc
	// Line 932, Address: 0x1d46d0, Func Offset: 0xd0
	// Line 933, Address: 0x1d46d4, Func Offset: 0xd4
	// Line 937, Address: 0x1d46e8, Func Offset: 0xe8
	// Line 942, Address: 0x1d46f0, Func Offset: 0xf0
	// Line 937, Address: 0x1d46f4, Func Offset: 0xf4
	// Line 939, Address: 0x1d4704, Func Offset: 0x104
	// Line 942, Address: 0x1d4714, Func Offset: 0x114
	// Line 945, Address: 0x1d471c, Func Offset: 0x11c
	// Line 947, Address: 0x1d4728, Func Offset: 0x128
	// Line 949, Address: 0x1d4730, Func Offset: 0x130
	// Line 948, Address: 0x1d4734, Func Offset: 0x134
	// Line 949, Address: 0x1d4738, Func Offset: 0x138
	// Line 951, Address: 0x1d473c, Func Offset: 0x13c
	// Line 950, Address: 0x1d4740, Func Offset: 0x140
	// Line 951, Address: 0x1d4744, Func Offset: 0x144
	// Line 952, Address: 0x1d4748, Func Offset: 0x148
	// Line 954, Address: 0x1d4750, Func Offset: 0x150
	// Line 956, Address: 0x1d4758, Func Offset: 0x158
	// Line 958, Address: 0x1d4760, Func Offset: 0x160
	// Line 957, Address: 0x1d4764, Func Offset: 0x164
	// Line 958, Address: 0x1d4768, Func Offset: 0x168
	// Line 960, Address: 0x1d476c, Func Offset: 0x16c
	// Line 959, Address: 0x1d4770, Func Offset: 0x170
	// Line 960, Address: 0x1d4774, Func Offset: 0x174
	// Line 961, Address: 0x1d4778, Func Offset: 0x178
	// Line 962, Address: 0x1d4780, Func Offset: 0x180
	// Line 966, Address: 0x1d4784, Func Offset: 0x184
	// Line 969, Address: 0x1d4790, Func Offset: 0x190
	// Line 970, Address: 0x1d4798, Func Offset: 0x198
	// Line 966, Address: 0x1d479c, Func Offset: 0x19c
	// Line 970, Address: 0x1d47a4, Func Offset: 0x1a4
	// Line 971, Address: 0x1d47ac, Func Offset: 0x1ac
	// Func End, Address: 0x1d47bc, Func Offset: 0x1bc
}

// 
// Start address: 0x1d47c0
void bhEne11_Nage()
{
	// Line 982, Address: 0x1d47c0, Func Offset: 0
	// Func End, Address: 0x1d47c8, Func Offset: 0x8
}

// 
// Start address: 0x1d47d0
void bhEne11_Damage()
{
	// Line 993, Address: 0x1d47d0, Func Offset: 0
	// Func End, Address: 0x1d47d8, Func Offset: 0x8
}

// 
// Start address: 0x1d47e0
void bhEne11_Die()
{
	// Line 1004, Address: 0x1d47e0, Func Offset: 0
	// Func End, Address: 0x1d47e8, Func Offset: 0x8
}

// 
// Start address: 0x1d47f0
void bhEne11_GoFoward(BH_PWORK* epw)
{
	// Line 1015, Address: 0x1d47f0, Func Offset: 0
	// Line 1016, Address: 0x1d480c, Func Offset: 0x1c
	// Line 1017, Address: 0x1d4828, Func Offset: 0x38
	// Line 1018, Address: 0x1d4840, Func Offset: 0x50
	// Func End, Address: 0x1d4848, Func Offset: 0x58
}

// 
// Start address: 0x1d4850
void bhEne11_CollisionWalls(BH_PWORK* epw)
{
	_anon3 vd;
	_anon3 body;
	// Line 1028, Address: 0x1d4850, Func Offset: 0
	// Line 1029, Address: 0x1d485c, Func Offset: 0xc
	// Line 1028, Address: 0x1d4860, Func Offset: 0x10
	// Line 1029, Address: 0x1d4868, Func Offset: 0x18
	// Line 1032, Address: 0x1d4884, Func Offset: 0x34
	// Line 1034, Address: 0x1d4890, Func Offset: 0x40
	// Line 1035, Address: 0x1d4898, Func Offset: 0x48
	// Line 1036, Address: 0x1d489c, Func Offset: 0x4c
	// Line 1037, Address: 0x1d48a0, Func Offset: 0x50
	// Line 1034, Address: 0x1d48a4, Func Offset: 0x54
	// Line 1035, Address: 0x1d48ac, Func Offset: 0x5c
	// Line 1036, Address: 0x1d48bc, Func Offset: 0x6c
	// Line 1037, Address: 0x1d48c8, Func Offset: 0x78
	// Line 1040, Address: 0x1d48d0, Func Offset: 0x80
	// Line 1041, Address: 0x1d48e0, Func Offset: 0x90
	// Line 1044, Address: 0x1d48e8, Func Offset: 0x98
	// Line 1045, Address: 0x1d48f8, Func Offset: 0xa8
	// Line 1046, Address: 0x1d4908, Func Offset: 0xb8
	// Line 1047, Address: 0x1d4918, Func Offset: 0xc8
	// Func End, Address: 0x1d4930, Func Offset: 0xe0
}

// 
// Start address: 0x1d4930
int bhEne11_CollisionBoxEdge2(BH_PWORK* epw)
{
	int i;
	float ar;
	_anon3 p2[4];
	_anon3 p[4];
	_anon3 v;
	// Line 1057, Address: 0x1d4930, Func Offset: 0
	// Line 1064, Address: 0x1d4954, Func Offset: 0x24
	// Line 1069, Address: 0x1d4960, Func Offset: 0x30
	// Line 1067, Address: 0x1d4964, Func Offset: 0x34
	// Line 1064, Address: 0x1d4968, Func Offset: 0x38
	// Line 1066, Address: 0x1d496c, Func Offset: 0x3c
	// Line 1068, Address: 0x1d4970, Func Offset: 0x40
	// Line 1067, Address: 0x1d4974, Func Offset: 0x44
	// Line 1068, Address: 0x1d497c, Func Offset: 0x4c
	// Line 1069, Address: 0x1d4980, Func Offset: 0x50
	// Line 1072, Address: 0x1d498c, Func Offset: 0x5c
	// Line 1074, Address: 0x1d49bc, Func Offset: 0x8c
	// Line 1084, Address: 0x1d49c0, Func Offset: 0x90
	// Line 1074, Address: 0x1d49c4, Func Offset: 0x94
	// Line 1075, Address: 0x1d49cc, Func Offset: 0x9c
	// Line 1076, Address: 0x1d49d8, Func Offset: 0xa8
	// Line 1077, Address: 0x1d49e4, Func Offset: 0xb4
	// Line 1078, Address: 0x1d49f0, Func Offset: 0xc0
	// Line 1079, Address: 0x1d49fc, Func Offset: 0xcc
	// Line 1080, Address: 0x1d4a08, Func Offset: 0xd8
	// Line 1081, Address: 0x1d4a14, Func Offset: 0xe4
	// Line 1082, Address: 0x1d4a20, Func Offset: 0xf0
	// Line 1083, Address: 0x1d4a34, Func Offset: 0x104
	// Line 1084, Address: 0x1d4a38, Func Offset: 0x108
	// Line 1086, Address: 0x1d4a3c, Func Offset: 0x10c
	// Line 1088, Address: 0x1d4a44, Func Offset: 0x114
	// Line 1089, Address: 0x1d4a50, Func Offset: 0x120
	// Line 1090, Address: 0x1d4a5c, Func Offset: 0x12c
	// Line 1091, Address: 0x1d4a68, Func Offset: 0x138
	// Line 1092, Address: 0x1d4a74, Func Offset: 0x144
	// Line 1093, Address: 0x1d4a80, Func Offset: 0x150
	// Line 1094, Address: 0x1d4a8c, Func Offset: 0x15c
	// Line 1095, Address: 0x1d4a98, Func Offset: 0x168
	// Line 1096, Address: 0x1d4aa4, Func Offset: 0x174
	// Line 1097, Address: 0x1d4ab8, Func Offset: 0x188
	// Line 1098, Address: 0x1d4abc, Func Offset: 0x18c
	// Line 1100, Address: 0x1d4ac0, Func Offset: 0x190
	// Line 1102, Address: 0x1d4ac8, Func Offset: 0x198
	// Line 1103, Address: 0x1d4ad4, Func Offset: 0x1a4
	// Line 1104, Address: 0x1d4ae0, Func Offset: 0x1b0
	// Line 1105, Address: 0x1d4aec, Func Offset: 0x1bc
	// Line 1106, Address: 0x1d4af8, Func Offset: 0x1c8
	// Line 1107, Address: 0x1d4b04, Func Offset: 0x1d4
	// Line 1108, Address: 0x1d4b10, Func Offset: 0x1e0
	// Line 1109, Address: 0x1d4b1c, Func Offset: 0x1ec
	// Line 1110, Address: 0x1d4b28, Func Offset: 0x1f8
	// Line 1111, Address: 0x1d4b38, Func Offset: 0x208
	// Line 1110, Address: 0x1d4b3c, Func Offset: 0x20c
	// Line 1112, Address: 0x1d4b40, Func Offset: 0x210
	// Line 1114, Address: 0x1d4b44, Func Offset: 0x214
	// Line 1116, Address: 0x1d4b4c, Func Offset: 0x21c
	// Line 1125, Address: 0x1d4b50, Func Offset: 0x220
	// Line 1116, Address: 0x1d4b54, Func Offset: 0x224
	// Line 1117, Address: 0x1d4b5c, Func Offset: 0x22c
	// Line 1118, Address: 0x1d4b68, Func Offset: 0x238
	// Line 1119, Address: 0x1d4b74, Func Offset: 0x244
	// Line 1120, Address: 0x1d4b80, Func Offset: 0x250
	// Line 1121, Address: 0x1d4b8c, Func Offset: 0x25c
	// Line 1122, Address: 0x1d4b98, Func Offset: 0x268
	// Line 1123, Address: 0x1d4ba4, Func Offset: 0x274
	// Line 1124, Address: 0x1d4bb0, Func Offset: 0x280
	// Line 1125, Address: 0x1d4bc0, Func Offset: 0x290
	// Line 1124, Address: 0x1d4bc4, Func Offset: 0x294
	// Line 1126, Address: 0x1d4bc8, Func Offset: 0x298
	// Line 1128, Address: 0x1d4bcc, Func Offset: 0x29c
	// Line 1130, Address: 0x1d4bd4, Func Offset: 0x2a4
	// Line 1131, Address: 0x1d4be0, Func Offset: 0x2b0
	// Line 1132, Address: 0x1d4bec, Func Offset: 0x2bc
	// Line 1133, Address: 0x1d4bf8, Func Offset: 0x2c8
	// Line 1134, Address: 0x1d4c04, Func Offset: 0x2d4
	// Line 1135, Address: 0x1d4c10, Func Offset: 0x2e0
	// Line 1136, Address: 0x1d4c1c, Func Offset: 0x2ec
	// Line 1137, Address: 0x1d4c28, Func Offset: 0x2f8
	// Line 1138, Address: 0x1d4c34, Func Offset: 0x304
	// Line 1139, Address: 0x1d4c48, Func Offset: 0x318
	// Line 1140, Address: 0x1d4c4c, Func Offset: 0x31c
	// Line 1142, Address: 0x1d4c50, Func Offset: 0x320
	// Line 1144, Address: 0x1d4c58, Func Offset: 0x328
	// Line 1155, Address: 0x1d4c5c, Func Offset: 0x32c
	// Line 1144, Address: 0x1d4c60, Func Offset: 0x330
	// Line 1145, Address: 0x1d4c68, Func Offset: 0x338
	// Line 1146, Address: 0x1d4c74, Func Offset: 0x344
	// Line 1147, Address: 0x1d4c80, Func Offset: 0x350
	// Line 1148, Address: 0x1d4c8c, Func Offset: 0x35c
	// Line 1149, Address: 0x1d4c98, Func Offset: 0x368
	// Line 1150, Address: 0x1d4ca4, Func Offset: 0x374
	// Line 1151, Address: 0x1d4cb0, Func Offset: 0x380
	// Line 1152, Address: 0x1d4cbc, Func Offset: 0x38c
	// Line 1153, Address: 0x1d4cd0, Func Offset: 0x3a0
	// Line 1154, Address: 0x1d4cd4, Func Offset: 0x3a4
	// Line 1155, Address: 0x1d4cd8, Func Offset: 0x3a8
	// Line 1159, Address: 0x1d4cdc, Func Offset: 0x3ac
	// Line 1160, Address: 0x1d4ce8, Func Offset: 0x3b8
	// Line 1163, Address: 0x1d4cf0, Func Offset: 0x3c0
	// Line 1160, Address: 0x1d4cf8, Func Offset: 0x3c8
	// Line 1161, Address: 0x1d4d00, Func Offset: 0x3d0
	// Line 1162, Address: 0x1d4d10, Func Offset: 0x3e0
	// Line 1163, Address: 0x1d4d1c, Func Offset: 0x3ec
	// Line 1165, Address: 0x1d4d2c, Func Offset: 0x3fc
	// Line 1166, Address: 0x1d4d3c, Func Offset: 0x40c
	// Line 1167, Address: 0x1d4d4c, Func Offset: 0x41c
	// Line 1168, Address: 0x1d4d58, Func Offset: 0x428
	// Line 1171, Address: 0x1d4d60, Func Offset: 0x430
	// Line 1168, Address: 0x1d4d68, Func Offset: 0x438
	// Line 1171, Address: 0x1d4d6c, Func Offset: 0x43c
	// Line 1172, Address: 0x1d4d78, Func Offset: 0x448
	// Func End, Address: 0x1d4da0, Func Offset: 0x470
}

// 
// Start address: 0x1d4da0
void bhEne11_CameraSet(BH_PWORK* epw, _anon3* vec, int hcnt)
{
	int ay;
	int ax;
	int ang;
	float out;
	_anon3 ov;
	_anon3 vb;
	_anon3 v;
	npobj* objP;
	// Line 1184, Address: 0x1d4da0, Func Offset: 0
	// Line 1190, Address: 0x1d4dbc, Func Offset: 0x1c
	// Line 1191, Address: 0x1d4dd0, Func Offset: 0x30
	// Line 1192, Address: 0x1d4dd8, Func Offset: 0x38
	// Line 1193, Address: 0x1d4de8, Func Offset: 0x48
	// Line 1195, Address: 0x1d4df0, Func Offset: 0x50
	// Line 1196, Address: 0x1d4df8, Func Offset: 0x58
	// Line 1199, Address: 0x1d4dfc, Func Offset: 0x5c
	// Line 1201, Address: 0x1d4e00, Func Offset: 0x60
	// Line 1196, Address: 0x1d4e04, Func Offset: 0x64
	// Line 1197, Address: 0x1d4e08, Func Offset: 0x68
	// Line 1198, Address: 0x1d4e0c, Func Offset: 0x6c
	// Line 1196, Address: 0x1d4e10, Func Offset: 0x70
	// Line 1201, Address: 0x1d4e14, Func Offset: 0x74
	// Line 1202, Address: 0x1d4e1c, Func Offset: 0x7c
	// Line 1204, Address: 0x1d4e28, Func Offset: 0x88
	// Line 1205, Address: 0x1d4e34, Func Offset: 0x94
	// Line 1208, Address: 0x1d4e44, Func Offset: 0xa4
	// Line 1209, Address: 0x1d4e54, Func Offset: 0xb4
	// Line 1210, Address: 0x1d4e60, Func Offset: 0xc0
	// Line 1212, Address: 0x1d4e8c, Func Offset: 0xec
	// Line 1213, Address: 0x1d4e94, Func Offset: 0xf4
	// Line 1214, Address: 0x1d4ea4, Func Offset: 0x104
	// Line 1217, Address: 0x1d4eb4, Func Offset: 0x114
	// Line 1218, Address: 0x1d4ecc, Func Offset: 0x12c
	// Line 1217, Address: 0x1d4ed4, Func Offset: 0x134
	// Line 1218, Address: 0x1d4ed8, Func Offset: 0x138
	// Line 1219, Address: 0x1d4ef4, Func Offset: 0x154
	// Line 1222, Address: 0x1d4f00, Func Offset: 0x160
	// Line 1223, Address: 0x1d4f08, Func Offset: 0x168
	// Line 1226, Address: 0x1d4f0c, Func Offset: 0x16c
	// Line 1227, Address: 0x1d4f10, Func Offset: 0x170
	// Func End, Address: 0x1d4f2c, Func Offset: 0x18c
}

// 
// Start address: 0x1d4f30
void bhEne11_MoveNearWall(BH_PWORK* epw)
{
	_anon3 pt;
	_anon3 vd;
	_anon3 vec;
	// Line 1237, Address: 0x1d4f30, Func Offset: 0
	// Line 1242, Address: 0x1d4f44, Func Offset: 0x14
	// Line 1241, Address: 0x1d4f48, Func Offset: 0x18
	// Line 1242, Address: 0x1d4f4c, Func Offset: 0x1c
	// Line 1243, Address: 0x1d4f54, Func Offset: 0x24
	// Line 1244, Address: 0x1d4f58, Func Offset: 0x28
	// Line 1245, Address: 0x1d4f68, Func Offset: 0x38
	// Line 1247, Address: 0x1d4f78, Func Offset: 0x48
	// Line 1248, Address: 0x1d4f80, Func Offset: 0x50
	// Line 1249, Address: 0x1d4f88, Func Offset: 0x58
	// Line 1247, Address: 0x1d4f8c, Func Offset: 0x5c
	// Line 1251, Address: 0x1d4f90, Func Offset: 0x60
	// Line 1247, Address: 0x1d4f98, Func Offset: 0x68
	// Line 1248, Address: 0x1d4f9c, Func Offset: 0x6c
	// Line 1249, Address: 0x1d4fa8, Func Offset: 0x78
	// Line 1251, Address: 0x1d4fb4, Func Offset: 0x84
	// Line 1252, Address: 0x1d4fc4, Func Offset: 0x94
	// Line 1253, Address: 0x1d4fd4, Func Offset: 0xa4
	// Line 1254, Address: 0x1d4fe0, Func Offset: 0xb0
	// Line 1255, Address: 0x1d4fec, Func Offset: 0xbc
	// Line 1257, Address: 0x1d4ff8, Func Offset: 0xc8
	// Func End, Address: 0x1d5010, Func Offset: 0xe0
}

// 
// Start address: 0x1d5010
void bhEne11_LightControl(BH_PWORK* epw, int flg)
{
	// Line 1269, Address: 0x1d5010, Func Offset: 0
	// Line 1272, Address: 0x1d5044, Func Offset: 0x34
	// Line 1273, Address: 0x1d5048, Func Offset: 0x38
	// Line 1272, Address: 0x1d504c, Func Offset: 0x3c
	// Line 1273, Address: 0x1d5054, Func Offset: 0x44
	// Line 1274, Address: 0x1d505c, Func Offset: 0x4c
	// Line 1277, Address: 0x1d5064, Func Offset: 0x54
	// Line 1278, Address: 0x1d506c, Func Offset: 0x5c
	// Line 1281, Address: 0x1d5074, Func Offset: 0x64
	// Line 1282, Address: 0x1d507c, Func Offset: 0x6c
	// Line 1285, Address: 0x1d5084, Func Offset: 0x74
	// Line 1286, Address: 0x1d508c, Func Offset: 0x7c
	// Line 1285, Address: 0x1d5090, Func Offset: 0x80
	// Line 1286, Address: 0x1d5098, Func Offset: 0x88
	// Line 1287, Address: 0x1d50a4, Func Offset: 0x94
	// Line 1290, Address: 0x1d50b0, Func Offset: 0xa0
	// Func End, Address: 0x1d50b8, Func Offset: 0xa8
}

// 
// Start address: 0x1d50c0
int bhEne11_SelectDir(BH_PWORK* epw)
{
	unsigned char ang;
	_anon3 pos;
	float h;
	int flg[4];
	int dir;
	int i;
	_anon3 p3;
	_anon3 p2;
	_anon3 p1;
	// Line 1300, Address: 0x1d50c0, Func Offset: 0
	// Line 1306, Address: 0x1d50e8, Func Offset: 0x28
	// Line 1307, Address: 0x1d5104, Func Offset: 0x44
	// Line 1312, Address: 0x1d510c, Func Offset: 0x4c
	// Line 1308, Address: 0x1d5114, Func Offset: 0x54
	// Line 1307, Address: 0x1d5118, Func Offset: 0x58
	// Line 1309, Address: 0x1d511c, Func Offset: 0x5c
	// Line 1313, Address: 0x1d5120, Func Offset: 0x60
	// Line 1307, Address: 0x1d5128, Func Offset: 0x68
	// Line 1314, Address: 0x1d512c, Func Offset: 0x6c
	// Line 1315, Address: 0x1d5130, Func Offset: 0x70
	// Line 1307, Address: 0x1d5134, Func Offset: 0x74
	// Line 1308, Address: 0x1d5138, Func Offset: 0x78
	// Line 1309, Address: 0x1d514c, Func Offset: 0x8c
	// Line 1312, Address: 0x1d5160, Func Offset: 0xa0
	// Line 1313, Address: 0x1d5178, Func Offset: 0xb8
	// Line 1314, Address: 0x1d5190, Func Offset: 0xd0
	// Line 1315, Address: 0x1d519c, Func Offset: 0xdc
	// Line 1314, Address: 0x1d51a0, Func Offset: 0xe0
	// Line 1315, Address: 0x1d51a8, Func Offset: 0xe8
	// Line 1316, Address: 0x1d51b8, Func Offset: 0xf8
	// Line 1319, Address: 0x1d51c8, Func Offset: 0x108
	// Line 1316, Address: 0x1d51cc, Func Offset: 0x10c
	// Line 1319, Address: 0x1d51d0, Func Offset: 0x110
	// Line 1316, Address: 0x1d51d4, Func Offset: 0x114
	// Line 1317, Address: 0x1d51e0, Func Offset: 0x120
	// Line 1318, Address: 0x1d51f8, Func Offset: 0x138
	// Line 1319, Address: 0x1d520c, Func Offset: 0x14c
	// Line 1320, Address: 0x1d521c, Func Offset: 0x15c
	// Line 1321, Address: 0x1d5228, Func Offset: 0x168
	// Line 1320, Address: 0x1d5234, Func Offset: 0x174
	// Line 1321, Address: 0x1d5238, Func Offset: 0x178
	// Line 1330, Address: 0x1d5250, Func Offset: 0x190
	// Line 1333, Address: 0x1d5260, Func Offset: 0x1a0
	// Line 1330, Address: 0x1d5264, Func Offset: 0x1a4
	// Line 1333, Address: 0x1d5268, Func Offset: 0x1a8
	// Line 1330, Address: 0x1d526c, Func Offset: 0x1ac
	// Line 1331, Address: 0x1d5278, Func Offset: 0x1b8
	// Line 1332, Address: 0x1d5290, Func Offset: 0x1d0
	// Line 1333, Address: 0x1d52a4, Func Offset: 0x1e4
	// Line 1334, Address: 0x1d52b4, Func Offset: 0x1f4
	// Line 1337, Address: 0x1d52c4, Func Offset: 0x204
	// Line 1334, Address: 0x1d52c8, Func Offset: 0x208
	// Line 1337, Address: 0x1d52cc, Func Offset: 0x20c
	// Line 1334, Address: 0x1d52d0, Func Offset: 0x210
	// Line 1335, Address: 0x1d52dc, Func Offset: 0x21c
	// Line 1336, Address: 0x1d52f4, Func Offset: 0x234
	// Line 1337, Address: 0x1d5308, Func Offset: 0x248
	// Line 1338, Address: 0x1d5318, Func Offset: 0x258
	// Line 1339, Address: 0x1d5324, Func Offset: 0x264
	// Line 1338, Address: 0x1d5330, Func Offset: 0x270
	// Line 1339, Address: 0x1d5334, Func Offset: 0x274
	// Line 1348, Address: 0x1d534c, Func Offset: 0x28c
	// Line 1351, Address: 0x1d535c, Func Offset: 0x29c
	// Line 1348, Address: 0x1d5360, Func Offset: 0x2a0
	// Line 1351, Address: 0x1d5364, Func Offset: 0x2a4
	// Line 1348, Address: 0x1d5368, Func Offset: 0x2a8
	// Line 1349, Address: 0x1d5374, Func Offset: 0x2b4
	// Line 1350, Address: 0x1d538c, Func Offset: 0x2cc
	// Line 1351, Address: 0x1d53a0, Func Offset: 0x2e0
	// Line 1352, Address: 0x1d53b0, Func Offset: 0x2f0
	// Line 1355, Address: 0x1d53c0, Func Offset: 0x300
	// Line 1352, Address: 0x1d53c4, Func Offset: 0x304
	// Line 1355, Address: 0x1d53c8, Func Offset: 0x308
	// Line 1352, Address: 0x1d53cc, Func Offset: 0x30c
	// Line 1353, Address: 0x1d53d8, Func Offset: 0x318
	// Line 1354, Address: 0x1d53f0, Func Offset: 0x330
	// Line 1355, Address: 0x1d5404, Func Offset: 0x344
	// Line 1356, Address: 0x1d5414, Func Offset: 0x354
	// Line 1357, Address: 0x1d5420, Func Offset: 0x360
	// Line 1356, Address: 0x1d542c, Func Offset: 0x36c
	// Line 1357, Address: 0x1d5430, Func Offset: 0x370
	// Line 1366, Address: 0x1d5448, Func Offset: 0x388
	// Line 1369, Address: 0x1d5458, Func Offset: 0x398
	// Line 1366, Address: 0x1d545c, Func Offset: 0x39c
	// Line 1369, Address: 0x1d5460, Func Offset: 0x3a0
	// Line 1366, Address: 0x1d5464, Func Offset: 0x3a4
	// Line 1367, Address: 0x1d5470, Func Offset: 0x3b0
	// Line 1368, Address: 0x1d5488, Func Offset: 0x3c8
	// Line 1369, Address: 0x1d549c, Func Offset: 0x3dc
	// Line 1370, Address: 0x1d54ac, Func Offset: 0x3ec
	// Line 1373, Address: 0x1d54bc, Func Offset: 0x3fc
	// Line 1370, Address: 0x1d54c0, Func Offset: 0x400
	// Line 1373, Address: 0x1d54c4, Func Offset: 0x404
	// Line 1370, Address: 0x1d54c8, Func Offset: 0x408
	// Line 1371, Address: 0x1d54d4, Func Offset: 0x414
	// Line 1372, Address: 0x1d54ec, Func Offset: 0x42c
	// Line 1373, Address: 0x1d5500, Func Offset: 0x440
	// Line 1374, Address: 0x1d5510, Func Offset: 0x450
	// Line 1375, Address: 0x1d551c, Func Offset: 0x45c
	// Line 1374, Address: 0x1d5528, Func Offset: 0x468
	// Line 1375, Address: 0x1d552c, Func Offset: 0x46c
	// Line 1383, Address: 0x1d5544, Func Offset: 0x484
	// Line 1388, Address: 0x1d55a0, Func Offset: 0x4e0
	// Line 1389, Address: 0x1d55ac, Func Offset: 0x4ec
	// Line 1390, Address: 0x1d55b4, Func Offset: 0x4f4
	// Line 1391, Address: 0x1d55cc, Func Offset: 0x50c
	// Line 1392, Address: 0x1d55e4, Func Offset: 0x524
	// Line 1393, Address: 0x1d55e8, Func Offset: 0x528
	// Line 1394, Address: 0x1d55f0, Func Offset: 0x530
	// Line 1396, Address: 0x1d562c, Func Offset: 0x56c
	// Line 1397, Address: 0x1d5630, Func Offset: 0x570
	// Line 1401, Address: 0x1d5644, Func Offset: 0x584
	// Line 1400, Address: 0x1d5648, Func Offset: 0x588
	// Line 1401, Address: 0x1d564c, Func Offset: 0x58c
	// Line 1404, Address: 0x1d5658, Func Offset: 0x598
	// Func End, Address: 0x1d5684, Func Offset: 0x5c4
}

