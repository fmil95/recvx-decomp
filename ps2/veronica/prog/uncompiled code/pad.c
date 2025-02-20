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
typedef struct BH_PWORK;
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

typedef void(*type_70)(void*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef unsigned int type_2[18];
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
typedef _anon12 type_17[1];
typedef _anon0* type_18[128];
typedef unsigned int type_19[1];
typedef _anon4 type_20[256];
typedef _anon1* type_21[8];
typedef int* type_22[16];
typedef _anon0* type_23[128];
typedef npobj* type_24[16];
typedef _anon0* type_25[128];
typedef unsigned int type_26[18];
typedef int type_27[4];
typedef _anon1* type_28[16];
typedef unsigned int type_29[4];
typedef _anon7 type_30[16];
typedef _anon0* type_31[512];
typedef char type_32[256];
typedef float type_33[4];
typedef float type_34[4];
typedef float type_35[4];
typedef _anon3* type_36[128];
typedef unsigned char type_37[64];
typedef float type_38[16];
typedef char type_39[8];
typedef void* type_40[2];
typedef unsigned short type_41[19];
typedef _anon1* type_42[256];
typedef int type_43[4];
typedef unsigned char* type_44[256];
typedef unsigned int type_45[2];
typedef short type_46[256];
typedef unsigned int type_47[18];
typedef _anon19 type_48[4];
typedef float type_49[3];
typedef short type_50[256];
typedef int type_51[3];
typedef int type_52[8];
typedef float type_53[3];
typedef _anon1* type_54[256];
typedef _anon6 type_55[256];
typedef _anon12 type_56[450];
typedef _anon21 type_57[16];
typedef unsigned int* type_58[4];
typedef short type_59[256];
typedef char type_60[3];
typedef int type_61[64];
typedef _anon7 type_62[450];
typedef _anon25 type_63[4];
typedef _anon2 type_64[4];
typedef int type_65[450];
typedef unsigned int type_66[8];
typedef unsigned char type_67[450];
typedef char type_68[16];
typedef char type_69[4];
typedef unsigned int type_71[32];
typedef unsigned int type_72[16];
typedef _anon27 type_73[64];
typedef unsigned int type_74[16];
typedef _anon27 type_75[64];
typedef unsigned int type_76[32];
typedef _anon27 type_77[64];
typedef unsigned int type_78[16];
typedef unsigned int type_79[18];
typedef unsigned int type_80[3];
typedef BH_PWORK* type_81[16];
typedef unsigned int type_82[8];
typedef unsigned int type_83[1];
typedef unsigned int type_84[384];
typedef unsigned int type_85[2];
typedef unsigned char type_86[2];
typedef int* type_87[16];
typedef unsigned int type_88[4];
typedef char type_89[32];
typedef unsigned int type_90[18];
typedef npobj* type_91[16];
typedef char type_92[64];
typedef _anon1* type_93[16];
typedef char type_94[4];
typedef _anon7 type_95[16];
typedef short type_96[4];
typedef unsigned char type_97[4];
typedef _anon23 type_98[16];
typedef unsigned int type_99[32];
typedef _anon22 type_100[32];
typedef _anon0* type_101[512];
typedef _anon0* type_102[128];
typedef unsigned short type_103[10];
typedef _anon0* type_104[512];
typedef unsigned char type_105[64];
typedef _anon0* type_106[512];

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
	_anon12* textures;
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
	_anon11* md2P;
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
	_anon17* owP;
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
	_anon29* info;
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

struct _anon10
{
	void* texaddr;
	_anon5 texsurface;
};

struct _anon11
{
	void* p[2];
};

struct _anon12
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon13
{
	short jnt_a;
	short jnt_b;
	int cap_r;
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
	_anon18* light;
};

struct _anon15
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
	_anon12 ef_tex[450];
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
	_anon10 ren_info;
	_anon12 ren_tex[1];
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
	_anon28 mr_pl;
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

struct _anon16
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon17
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon18
{
	float mtrx[16];
	_anon22 pnt;
	_anon22 vctr;
	int stat;
	int reserve;
	_anon24 ltcal;
	_anon30 attr;
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
	_anon32 watr;
	_anon13* cpcl;
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
	_anon16 atten;
	_anon16 amb;
	_anon16 dif;
	_anon16 spc;
	_anon16 mamb;
	_anon16 mdif;
	_anon16 mspc;
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
	_anon16 argb;
};

struct _anon31
{
	_anon22 c;
	float r;
};

struct _anon32
{
	_anon22 c1;
	_anon22 c2;
	float r;
};

unsigned int pad_tab_a[18];
unsigned int pad_tab_b[18];
unsigned int pad_tab_c[18];
unsigned int pad_tab_d[18];
unsigned int* pad_type[4];
unsigned short pdm_mes[10];
unsigned short pdm_palmes[19];
_anon15* sys;
int pd_port;

void bhSetPad();

// 
// Start address: 0x1312b0
void bhSetPad()
{
	unsigned int padtbl[18];
	unsigned int padwork;
	unsigned int argb;
	unsigned int pon;
	unsigned int pad;
	int i;
	unsigned int* pd;
	// Line 395, Address: 0x1312b0, Func Offset: 0
	// Line 417, Address: 0x1312c0, Func Offset: 0x10
	// Line 418, Address: 0x1312dc, Func Offset: 0x2c
	// Line 420, Address: 0x1312ec, Func Offset: 0x3c
	// Line 421, Address: 0x1312f4, Func Offset: 0x44
	// Line 422, Address: 0x1312fc, Func Offset: 0x4c
	// Line 423, Address: 0x13130c, Func Offset: 0x5c
	// Line 424, Address: 0x131314, Func Offset: 0x64
	// Line 425, Address: 0x131328, Func Offset: 0x78
	// Line 424, Address: 0x13132c, Func Offset: 0x7c
	// Line 425, Address: 0x131334, Func Offset: 0x84
	// Line 426, Address: 0x13133c, Func Offset: 0x8c
	// Line 425, Address: 0x131340, Func Offset: 0x90
	// Line 426, Address: 0x131348, Func Offset: 0x98
	// Line 428, Address: 0x131360, Func Offset: 0xb0
	// Line 430, Address: 0x131368, Func Offset: 0xb8
	// Line 432, Address: 0x131374, Func Offset: 0xc4
	// Line 433, Address: 0x131394, Func Offset: 0xe4
	// Line 434, Address: 0x1313b0, Func Offset: 0x100
	// Line 437, Address: 0x1313b8, Func Offset: 0x108
	// Line 434, Address: 0x1313c8, Func Offset: 0x118
	// Line 437, Address: 0x1313d4, Func Offset: 0x124
	// Line 434, Address: 0x1313d8, Func Offset: 0x128
	// Line 437, Address: 0x1313dc, Func Offset: 0x12c
	// Line 443, Address: 0x1313e4, Func Offset: 0x134
	// Line 434, Address: 0x1313e8, Func Offset: 0x138
	// Line 437, Address: 0x1313ec, Func Offset: 0x13c
	// Line 443, Address: 0x131400, Func Offset: 0x150
	// Line 444, Address: 0x131408, Func Offset: 0x158
	// Line 445, Address: 0x13140c, Func Offset: 0x15c
	// Line 446, Address: 0x131410, Func Offset: 0x160
	// Line 447, Address: 0x131430, Func Offset: 0x180
	// Line 448, Address: 0x131440, Func Offset: 0x190
	// Line 451, Address: 0x131444, Func Offset: 0x194
	// Line 452, Address: 0x131448, Func Offset: 0x198
	// Line 451, Address: 0x13144c, Func Offset: 0x19c
	// Line 452, Address: 0x131450, Func Offset: 0x1a0
	// Line 458, Address: 0x131494, Func Offset: 0x1e4
	// Line 459, Address: 0x1314b8, Func Offset: 0x208
	// Line 462, Address: 0x1314c0, Func Offset: 0x210
	// Line 459, Address: 0x1314c8, Func Offset: 0x218
	// Line 462, Address: 0x1314cc, Func Offset: 0x21c
	// Line 459, Address: 0x1314d0, Func Offset: 0x220
	// Line 460, Address: 0x1314d4, Func Offset: 0x224
	// Line 459, Address: 0x1314d8, Func Offset: 0x228
	// Line 460, Address: 0x1314e0, Func Offset: 0x230
	// Line 461, Address: 0x1314e8, Func Offset: 0x238
	// Line 462, Address: 0x1314f8, Func Offset: 0x248
	// Line 463, Address: 0x131500, Func Offset: 0x250
	// Line 467, Address: 0x131510, Func Offset: 0x260
	// Line 469, Address: 0x131518, Func Offset: 0x268
	// Line 470, Address: 0x131528, Func Offset: 0x278
	// Line 471, Address: 0x13153c, Func Offset: 0x28c
	// Line 477, Address: 0x13158c, Func Offset: 0x2dc
	// Line 481, Address: 0x1315d8, Func Offset: 0x328
	// Line 483, Address: 0x131628, Func Offset: 0x378
	// Line 484, Address: 0x131638, Func Offset: 0x388
	// Line 483, Address: 0x131640, Func Offset: 0x390
	// Line 484, Address: 0x131648, Func Offset: 0x398
	// Line 489, Address: 0x131690, Func Offset: 0x3e0
	// Line 493, Address: 0x131698, Func Offset: 0x3e8
	// Line 494, Address: 0x1316b4, Func Offset: 0x404
	// Line 496, Address: 0x1316d0, Func Offset: 0x420
	// Line 497, Address: 0x1316ec, Func Offset: 0x43c
	// Line 498, Address: 0x131730, Func Offset: 0x480
	// Line 499, Address: 0x131744, Func Offset: 0x494
	// Line 500, Address: 0x131758, Func Offset: 0x4a8
	// Line 501, Address: 0x13176c, Func Offset: 0x4bc
	// Line 502, Address: 0x13177c, Func Offset: 0x4cc
	// Line 505, Address: 0x131784, Func Offset: 0x4d4
	// Line 507, Address: 0x131788, Func Offset: 0x4d8
	// Line 508, Address: 0x131798, Func Offset: 0x4e8
	// Line 515, Address: 0x1317bc, Func Offset: 0x50c
	// Line 516, Address: 0x1317e4, Func Offset: 0x534
	// Line 520, Address: 0x13180c, Func Offset: 0x55c
	// Line 522, Address: 0x131814, Func Offset: 0x564
	// Line 521, Address: 0x13181c, Func Offset: 0x56c
	// Line 526, Address: 0x131820, Func Offset: 0x570
	// Line 520, Address: 0x131824, Func Offset: 0x574
	// Line 522, Address: 0x13183c, Func Offset: 0x58c
	// Line 530, Address: 0x131858, Func Offset: 0x5a8
	// Line 531, Address: 0x131878, Func Offset: 0x5c8
	// Line 532, Address: 0x131888, Func Offset: 0x5d8
	// Line 535, Address: 0x1318a0, Func Offset: 0x5f0
	// Line 536, Address: 0x1318bc, Func Offset: 0x60c
	// Line 537, Address: 0x1318c8, Func Offset: 0x618
	// Line 538, Address: 0x1318e0, Func Offset: 0x630
	// Line 541, Address: 0x1318ec, Func Offset: 0x63c
	// Line 542, Address: 0x131900, Func Offset: 0x650
	// Line 544, Address: 0x131914, Func Offset: 0x664
	// Line 545, Address: 0x131920, Func Offset: 0x670
	// Line 546, Address: 0x13192c, Func Offset: 0x67c
	// Line 547, Address: 0x131950, Func Offset: 0x6a0
	// Line 549, Address: 0x131954, Func Offset: 0x6a4
	// Line 550, Address: 0x131960, Func Offset: 0x6b0
	// Line 551, Address: 0x13198c, Func Offset: 0x6dc
	// Line 553, Address: 0x131990, Func Offset: 0x6e0
	// Line 554, Address: 0x1319bc, Func Offset: 0x70c
	// Line 555, Address: 0x1319e0, Func Offset: 0x730
	// Line 556, Address: 0x1319e8, Func Offset: 0x738
	// Line 558, Address: 0x1319fc, Func Offset: 0x74c
	// Line 559, Address: 0x131a08, Func Offset: 0x758
	// Line 560, Address: 0x131a14, Func Offset: 0x764
	// Line 561, Address: 0x131a40, Func Offset: 0x790
	// Line 563, Address: 0x131a44, Func Offset: 0x794
	// Line 564, Address: 0x131a50, Func Offset: 0x7a0
	// Line 565, Address: 0x131a7c, Func Offset: 0x7cc
	// Line 567, Address: 0x131a80, Func Offset: 0x7d0
	// Line 568, Address: 0x131aac, Func Offset: 0x7fc
	// Line 569, Address: 0x131ad0, Func Offset: 0x820
	// Line 570, Address: 0x131ad8, Func Offset: 0x828
	// Line 573, Address: 0x131af4, Func Offset: 0x844
	// Line 574, Address: 0x131b1c, Func Offset: 0x86c
	// Line 575, Address: 0x131b50, Func Offset: 0x8a0
	// Line 576, Address: 0x131b78, Func Offset: 0x8c8
	// Func End, Address: 0x131b8c, Func Offset: 0x8dc
}

