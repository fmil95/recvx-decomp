typedef struct npobj;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct BH_PWORK;
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

typedef void(*type_38)(BH_PWORK*);
typedef void(*type_54)(BH_PWORK*);
typedef void(*type_69)(void*);
typedef void(*type_76)(BH_PWORK*);

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
typedef char type_12[32];
typedef _anon0* type_13[512];
typedef _anon1* type_14[200];
typedef short type_15[32];
typedef _anon13 type_16[1];
typedef _anon0* type_17[128];
typedef unsigned int type_18[1];
typedef _anon5 type_19[256];
typedef _anon1* type_20[8];
typedef int* type_21[16];
typedef _anon0* type_22[128];
typedef npobj* type_23[16];
typedef _anon0* type_24[128];
typedef int type_25[4];
typedef _anon1* type_26[16];
typedef unsigned int type_27[4];
typedef _anon8 type_28[16];
typedef _anon0* type_29[512];
typedef char type_30[256];
typedef float type_31[4];
typedef float type_32[4];
typedef float type_33[4];
typedef _anon3* type_34[128];
typedef unsigned char type_35[64];
typedef float type_36[16];
typedef char type_37[8];
typedef void* type_39[2];
typedef void(*type_40)(BH_PWORK*)[1];
typedef _anon1* type_41[256];
typedef int type_42[4];
typedef unsigned char* type_43[256];
typedef unsigned int type_44[2];
typedef short type_45[256];
typedef _anon19 type_46[4];
typedef float type_47[3];
typedef short type_48[256];
typedef int type_49[3];
typedef int type_50[8];
typedef float type_51[3];
typedef _anon1* type_52[256];
typedef _anon7 type_53[256];
typedef void(*type_55)(BH_PWORK*)[6];
typedef _anon13 type_56[450];
typedef _anon21 type_57[16];
typedef short type_58[256];
typedef char type_59[3];
typedef int type_60[64];
typedef _anon8 type_61[450];
typedef _anon25 type_62[4];
typedef _anon2 type_63[4];
typedef int type_64[450];
typedef unsigned int type_65[8];
typedef unsigned char type_66[450];
typedef char type_67[16];
typedef char type_68[4];
typedef unsigned int type_70[32];
typedef unsigned int type_71[16];
typedef _anon27 type_72[64];
typedef unsigned int type_73[16];
typedef _anon27 type_74[64];
typedef unsigned int type_75[32];
typedef _anon27 type_77[64];
typedef void(*type_78)(BH_PWORK*)[2];
typedef unsigned int type_79[16];
typedef unsigned int type_80[3];
typedef BH_PWORK* type_81[16];
typedef unsigned int type_82[8];
typedef unsigned int type_83[1];
typedef unsigned int type_84[384];
typedef unsigned int type_85[2];
typedef unsigned char type_86[2];
typedef unsigned int type_87[4];
typedef int* type_88[16];
typedef char type_89[32];
typedef npobj* type_90[16];
typedef char type_91[64];
typedef _anon1* type_92[16];
typedef char type_93[4];
typedef _anon8 type_94[16];
typedef short type_95[4];
typedef unsigned char type_96[4];
typedef _anon23 type_97[16];
typedef unsigned int type_98[32];
typedef _anon22 type_99[32];
typedef _anon0* type_100[512];
typedef _anon0* type_101[128];
typedef _anon0* type_102[512];
typedef unsigned char type_103[64];
typedef int type_104[6];
typedef _anon0* type_105[512];

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
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
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
	_anon4* owP;
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
	_anon30 attr;
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
	_anon22 c;
	float r;
};

struct _anon32
{
	_anon22 c1;
	_anon22 c2;
	float r;
};

void(*bhEne13B_Mode0)(BH_PWORK*)[6];
void(*bhEne13B_BrainType)(BH_PWORK*)[1];
void(*bhEne13B_MoveMode2)(BH_PWORK*)[2];
_anon16* sys;
BH_PWORK* plp;

void bhEne13B(BH_PWORK* epw);
void bhEne13B_Init(BH_PWORK* epw);
void bhEne13B_Move(BH_PWORK* epw);
void bhEne13B_MV00();
void bhEne13B_MV01(BH_PWORK* epw);
void bhEne13B_Nage();
void bhEne13B_Damage();
void bhEne13B_Die(BH_PWORK* epw);
void bhEne13B_SetHittab(BH_PWORK* epw);

// 
// Start address: 0x1dcd00
void bhEne13B(BH_PWORK* epw)
{
	_anon4* owk;
	int i;
	int i;
	// Line 136, Address: 0x1dcd00, Func Offset: 0
	// Line 138, Address: 0x1dcd10, Func Offset: 0x10
	// Line 141, Address: 0x1dcd30, Func Offset: 0x30
	// Line 143, Address: 0x1dcd48, Func Offset: 0x48
	// Line 145, Address: 0x1dcd4c, Func Offset: 0x4c
	// Line 143, Address: 0x1dcd54, Func Offset: 0x54
	// Line 145, Address: 0x1dcd58, Func Offset: 0x58
	// Line 146, Address: 0x1dcd60, Func Offset: 0x60
	// Line 147, Address: 0x1dcd64, Func Offset: 0x64
	// Line 146, Address: 0x1dcd68, Func Offset: 0x68
	// Line 147, Address: 0x1dcd78, Func Offset: 0x78
	// Line 148, Address: 0x1dcd8c, Func Offset: 0x8c
	// Line 155, Address: 0x1dcd90, Func Offset: 0x90
	// Line 156, Address: 0x1dcd94, Func Offset: 0x94
	// Line 155, Address: 0x1dcd98, Func Offset: 0x98
	// Line 156, Address: 0x1dcd9c, Func Offset: 0x9c
	// Line 157, Address: 0x1dcda4, Func Offset: 0xa4
	// Line 158, Address: 0x1dcdb4, Func Offset: 0xb4
	// Line 157, Address: 0x1dcdb8, Func Offset: 0xb8
	// Line 158, Address: 0x1dcdc8, Func Offset: 0xc8
	// Line 157, Address: 0x1dcdcc, Func Offset: 0xcc
	// Line 158, Address: 0x1dcdd0, Func Offset: 0xd0
	// Line 162, Address: 0x1dcde4, Func Offset: 0xe4
	// Line 165, Address: 0x1dcdf8, Func Offset: 0xf8
	// Line 168, Address: 0x1dce00, Func Offset: 0x100
	// Line 169, Address: 0x1dce08, Func Offset: 0x108
	// Func End, Address: 0x1dce18, Func Offset: 0x118
}

// 
// Start address: 0x1dce20
void bhEne13B_Init(BH_PWORK* epw)
{
	int i;
	// Line 179, Address: 0x1dce20, Func Offset: 0
	// Line 183, Address: 0x1dce2c, Func Offset: 0xc
	// Line 184, Address: 0x1dce30, Func Offset: 0x10
	// Line 188, Address: 0x1dce34, Func Offset: 0x14
	// Line 189, Address: 0x1dce38, Func Offset: 0x18
	// Line 190, Address: 0x1dce3c, Func Offset: 0x1c
	// Line 183, Address: 0x1dce40, Func Offset: 0x20
	// Line 184, Address: 0x1dce48, Func Offset: 0x28
	// Line 193, Address: 0x1dce4c, Func Offset: 0x2c
	// Line 199, Address: 0x1dce50, Func Offset: 0x30
	// Line 201, Address: 0x1dce54, Func Offset: 0x34
	// Line 184, Address: 0x1dce58, Func Offset: 0x38
	// Line 185, Address: 0x1dce60, Func Offset: 0x40
	// Line 186, Address: 0x1dce70, Func Offset: 0x50
	// Line 187, Address: 0x1dce7c, Func Offset: 0x5c
	// Line 188, Address: 0x1dce88, Func Offset: 0x68
	// Line 189, Address: 0x1dce8c, Func Offset: 0x6c
	// Line 190, Address: 0x1dce90, Func Offset: 0x70
	// Line 193, Address: 0x1dce94, Func Offset: 0x74
	// Line 194, Address: 0x1dce98, Func Offset: 0x78
	// Line 195, Address: 0x1dce9c, Func Offset: 0x7c
	// Line 196, Address: 0x1dcea0, Func Offset: 0x80
	// Line 199, Address: 0x1dcea4, Func Offset: 0x84
	// Line 200, Address: 0x1dcea8, Func Offset: 0x88
	// Line 201, Address: 0x1dceac, Func Offset: 0x8c
	// Line 202, Address: 0x1dceb0, Func Offset: 0x90
	// Line 203, Address: 0x1dceb4, Func Offset: 0x94
	// Line 204, Address: 0x1dceb8, Func Offset: 0x98
	// Line 207, Address: 0x1dcebc, Func Offset: 0x9c
	// Line 210, Address: 0x1dcecc, Func Offset: 0xac
	// Line 213, Address: 0x1dced4, Func Offset: 0xb4
	// Line 214, Address: 0x1dcee0, Func Offset: 0xc0
	// Line 217, Address: 0x1dceec, Func Offset: 0xcc
	// Line 214, Address: 0x1dcef0, Func Offset: 0xd0
	// Line 217, Address: 0x1dcef4, Func Offset: 0xd4
	// Line 218, Address: 0x1dcf08, Func Offset: 0xe8
	// Line 230, Address: 0x1dcf14, Func Offset: 0xf4
	// Line 218, Address: 0x1dcf18, Func Offset: 0xf8
	// Line 219, Address: 0x1dcf48, Func Offset: 0x128
	// Line 220, Address: 0x1dcf6c, Func Offset: 0x14c
	// Line 221, Address: 0x1dcf7c, Func Offset: 0x15c
	// Line 222, Address: 0x1dcf8c, Func Offset: 0x16c
	// Line 223, Address: 0x1dcf9c, Func Offset: 0x17c
	// Line 224, Address: 0x1dcfac, Func Offset: 0x18c
	// Line 225, Address: 0x1dcfbc, Func Offset: 0x19c
	// Line 227, Address: 0x1dcfcc, Func Offset: 0x1ac
	// Line 228, Address: 0x1dcfe8, Func Offset: 0x1c8
	// Line 229, Address: 0x1dd004, Func Offset: 0x1e4
	// Line 230, Address: 0x1dd024, Func Offset: 0x204
	// Line 231, Address: 0x1dd03c, Func Offset: 0x21c
	// Line 232, Address: 0x1dd040, Func Offset: 0x220
	// Func End, Address: 0x1dd050, Func Offset: 0x230
}

// 
// Start address: 0x1dd050
void bhEne13B_Move(BH_PWORK* epw)
{
	// Line 267, Address: 0x1dd050, Func Offset: 0
	// Func End, Address: 0x1dd070, Func Offset: 0x20
}

// 
// Start address: 0x1dd070
void bhEne13B_MV00()
{
	// Line 279, Address: 0x1dd070, Func Offset: 0
	// Func End, Address: 0x1dd078, Func Offset: 0x8
}

// 
// Start address: 0x1dd080
void bhEne13B_MV01(BH_PWORK* epw)
{
	_anon22 p1;
	BH_PWORK** ep;
	int num;
	int j;
	int i;
	_anon4* owk;
	int mtn_no[6];
	// Line 289, Address: 0x1dd080, Func Offset: 0
	// Line 290, Address: 0x1dd09c, Func Offset: 0x1c
	// Line 289, Address: 0x1dd0a0, Func Offset: 0x20
	// Line 290, Address: 0x1dd0a8, Func Offset: 0x28
	// Line 298, Address: 0x1dd0b4, Func Offset: 0x34
	// Line 290, Address: 0x1dd0b8, Func Offset: 0x38
	// Line 298, Address: 0x1dd0c4, Func Offset: 0x44
	// Line 300, Address: 0x1dd0e0, Func Offset: 0x60
	// Line 305, Address: 0x1dd0e4, Func Offset: 0x64
	// Line 302, Address: 0x1dd0e8, Func Offset: 0x68
	// Line 305, Address: 0x1dd0ec, Func Offset: 0x6c
	// Line 308, Address: 0x1dd0f0, Func Offset: 0x70
	// Line 300, Address: 0x1dd0f4, Func Offset: 0x74
	// Line 301, Address: 0x1dd104, Func Offset: 0x84
	// Line 302, Address: 0x1dd108, Func Offset: 0x88
	// Line 303, Address: 0x1dd10c, Func Offset: 0x8c
	// Line 308, Address: 0x1dd110, Func Offset: 0x90
	// Line 304, Address: 0x1dd114, Func Offset: 0x94
	// Line 305, Address: 0x1dd118, Func Offset: 0x98
	// Line 308, Address: 0x1dd120, Func Offset: 0xa0
	// Line 310, Address: 0x1dd128, Func Offset: 0xa8
	// Line 311, Address: 0x1dd130, Func Offset: 0xb0
	// Line 314, Address: 0x1dd138, Func Offset: 0xb8
	// Line 317, Address: 0x1dd190, Func Offset: 0x110
	// Line 321, Address: 0x1dd1a4, Func Offset: 0x124
	// Line 323, Address: 0x1dd1c0, Func Offset: 0x140
	// Line 328, Address: 0x1dd218, Func Offset: 0x198
	// Line 331, Address: 0x1dd234, Func Offset: 0x1b4
	// Line 333, Address: 0x1dd264, Func Offset: 0x1e4
	// Line 334, Address: 0x1dd278, Func Offset: 0x1f8
	// Line 337, Address: 0x1dd288, Func Offset: 0x208
	// Line 339, Address: 0x1dd290, Func Offset: 0x210
	// Line 340, Address: 0x1dd2a4, Func Offset: 0x224
	// Line 343, Address: 0x1dd2b4, Func Offset: 0x234
	// Line 345, Address: 0x1dd2bc, Func Offset: 0x23c
	// Line 346, Address: 0x1dd2d0, Func Offset: 0x250
	// Line 349, Address: 0x1dd2e0, Func Offset: 0x260
	// Line 351, Address: 0x1dd2e8, Func Offset: 0x268
	// Line 352, Address: 0x1dd2f8, Func Offset: 0x278
	// Line 353, Address: 0x1dd308, Func Offset: 0x288
	// Line 355, Address: 0x1dd30c, Func Offset: 0x28c
	// Line 356, Address: 0x1dd31c, Func Offset: 0x29c
	// Line 357, Address: 0x1dd328, Func Offset: 0x2a8
	// Line 356, Address: 0x1dd32c, Func Offset: 0x2ac
	// Line 357, Address: 0x1dd334, Func Offset: 0x2b4
	// Line 359, Address: 0x1dd338, Func Offset: 0x2b8
	// Line 360, Address: 0x1dd348, Func Offset: 0x2c8
	// Line 363, Address: 0x1dd358, Func Offset: 0x2d8
	// Line 365, Address: 0x1dd360, Func Offset: 0x2e0
	// Line 366, Address: 0x1dd370, Func Offset: 0x2f0
	// Line 367, Address: 0x1dd380, Func Offset: 0x300
	// Line 369, Address: 0x1dd384, Func Offset: 0x304
	// Line 370, Address: 0x1dd394, Func Offset: 0x314
	// Line 371, Address: 0x1dd3a0, Func Offset: 0x320
	// Line 370, Address: 0x1dd3a4, Func Offset: 0x324
	// Line 371, Address: 0x1dd3ac, Func Offset: 0x32c
	// Line 373, Address: 0x1dd3b0, Func Offset: 0x330
	// Line 374, Address: 0x1dd3c0, Func Offset: 0x340
	// Line 377, Address: 0x1dd3d0, Func Offset: 0x350
	// Line 379, Address: 0x1dd3d8, Func Offset: 0x358
	// Line 380, Address: 0x1dd3e8, Func Offset: 0x368
	// Line 381, Address: 0x1dd3f8, Func Offset: 0x378
	// Line 383, Address: 0x1dd3fc, Func Offset: 0x37c
	// Line 384, Address: 0x1dd40c, Func Offset: 0x38c
	// Line 385, Address: 0x1dd418, Func Offset: 0x398
	// Line 384, Address: 0x1dd41c, Func Offset: 0x39c
	// Line 385, Address: 0x1dd424, Func Offset: 0x3a4
	// Line 387, Address: 0x1dd428, Func Offset: 0x3a8
	// Line 388, Address: 0x1dd438, Func Offset: 0x3b8
	// Line 389, Address: 0x1dd448, Func Offset: 0x3c8
	// Line 395, Address: 0x1dd44c, Func Offset: 0x3cc
	// Line 396, Address: 0x1dd458, Func Offset: 0x3d8
	// Line 397, Address: 0x1dd470, Func Offset: 0x3f0
	// Line 396, Address: 0x1dd474, Func Offset: 0x3f4
	// Line 397, Address: 0x1dd478, Func Offset: 0x3f8
	// Line 402, Address: 0x1dd498, Func Offset: 0x418
	// Line 403, Address: 0x1dd4d4, Func Offset: 0x454
	// Line 409, Address: 0x1dd4ec, Func Offset: 0x46c
	// Line 410, Address: 0x1dd4f0, Func Offset: 0x470
	// Line 411, Address: 0x1dd4f4, Func Offset: 0x474
	// Line 417, Address: 0x1dd4f8, Func Offset: 0x478
	// Line 409, Address: 0x1dd4fc, Func Offset: 0x47c
	// Line 422, Address: 0x1dd500, Func Offset: 0x480
	// Line 409, Address: 0x1dd504, Func Offset: 0x484
	// Line 410, Address: 0x1dd50c, Func Offset: 0x48c
	// Line 411, Address: 0x1dd51c, Func Offset: 0x49c
	// Line 417, Address: 0x1dd52c, Func Offset: 0x4ac
	// Line 414, Address: 0x1dd530, Func Offset: 0x4b0
	// Line 417, Address: 0x1dd534, Func Offset: 0x4b4
	// Line 414, Address: 0x1dd53c, Func Offset: 0x4bc
	// Line 417, Address: 0x1dd540, Func Offset: 0x4c0
	// Line 418, Address: 0x1dd544, Func Offset: 0x4c4
	// Line 414, Address: 0x1dd548, Func Offset: 0x4c8
	// Line 417, Address: 0x1dd54c, Func Offset: 0x4cc
	// Line 414, Address: 0x1dd550, Func Offset: 0x4d0
	// Line 415, Address: 0x1dd554, Func Offset: 0x4d4
	// Line 417, Address: 0x1dd558, Func Offset: 0x4d8
	// Line 418, Address: 0x1dd560, Func Offset: 0x4e0
	// Line 419, Address: 0x1dd570, Func Offset: 0x4f0
	// Line 418, Address: 0x1dd574, Func Offset: 0x4f4
	// Line 419, Address: 0x1dd57c, Func Offset: 0x4fc
	// Line 422, Address: 0x1dd58c, Func Offset: 0x50c
	// Line 419, Address: 0x1dd590, Func Offset: 0x510
	// Line 422, Address: 0x1dd598, Func Offset: 0x518
	// Line 424, Address: 0x1dd5f0, Func Offset: 0x570
	// Line 425, Address: 0x1dd600, Func Offset: 0x580
	// Line 424, Address: 0x1dd604, Func Offset: 0x584
	// Line 425, Address: 0x1dd60c, Func Offset: 0x58c
	// Line 426, Address: 0x1dd618, Func Offset: 0x598
	// Line 425, Address: 0x1dd61c, Func Offset: 0x59c
	// Line 426, Address: 0x1dd624, Func Offset: 0x5a4
	// Line 431, Address: 0x1dd638, Func Offset: 0x5b8
	// Line 432, Address: 0x1dd648, Func Offset: 0x5c8
	// Line 433, Address: 0x1dd658, Func Offset: 0x5d8
	// Line 434, Address: 0x1dd660, Func Offset: 0x5e0
	// Line 435, Address: 0x1dd674, Func Offset: 0x5f4
	// Line 438, Address: 0x1dd678, Func Offset: 0x5f8
	// Line 440, Address: 0x1dd68c, Func Offset: 0x60c
	// Line 441, Address: 0x1dd698, Func Offset: 0x618
	// Line 443, Address: 0x1dd6a0, Func Offset: 0x620
	// Line 440, Address: 0x1dd6a4, Func Offset: 0x624
	// Line 441, Address: 0x1dd6ac, Func Offset: 0x62c
	// Line 443, Address: 0x1dd6b4, Func Offset: 0x634
	// Line 441, Address: 0x1dd6b8, Func Offset: 0x638
	// Line 443, Address: 0x1dd6c0, Func Offset: 0x640
	// Line 444, Address: 0x1dd6c8, Func Offset: 0x648
	// Line 445, Address: 0x1dd6d4, Func Offset: 0x654
	// Line 446, Address: 0x1dd6e8, Func Offset: 0x668
	// Line 447, Address: 0x1dd70c, Func Offset: 0x68c
	// Line 446, Address: 0x1dd710, Func Offset: 0x690
	// Line 447, Address: 0x1dd714, Func Offset: 0x694
	// Line 448, Address: 0x1dd71c, Func Offset: 0x69c
	// Line 449, Address: 0x1dd724, Func Offset: 0x6a4
	// Line 450, Address: 0x1dd744, Func Offset: 0x6c4
	// Line 452, Address: 0x1dd750, Func Offset: 0x6d0
	// Line 453, Address: 0x1dd758, Func Offset: 0x6d8
	// Line 455, Address: 0x1dd760, Func Offset: 0x6e0
	// Line 456, Address: 0x1dd76c, Func Offset: 0x6ec
	// Line 458, Address: 0x1dd770, Func Offset: 0x6f0
	// Line 455, Address: 0x1dd774, Func Offset: 0x6f4
	// Line 456, Address: 0x1dd77c, Func Offset: 0x6fc
	// Line 458, Address: 0x1dd784, Func Offset: 0x704
	// Line 456, Address: 0x1dd788, Func Offset: 0x708
	// Line 458, Address: 0x1dd790, Func Offset: 0x710
	// Line 459, Address: 0x1dd798, Func Offset: 0x718
	// Line 460, Address: 0x1dd7a4, Func Offset: 0x724
	// Line 461, Address: 0x1dd7b8, Func Offset: 0x738
	// Line 462, Address: 0x1dd7dc, Func Offset: 0x75c
	// Line 461, Address: 0x1dd7e0, Func Offset: 0x760
	// Line 462, Address: 0x1dd7e4, Func Offset: 0x764
	// Line 463, Address: 0x1dd7ec, Func Offset: 0x76c
	// Line 464, Address: 0x1dd7f4, Func Offset: 0x774
	// Line 465, Address: 0x1dd814, Func Offset: 0x794
	// Line 467, Address: 0x1dd820, Func Offset: 0x7a0
	// Line 468, Address: 0x1dd82c, Func Offset: 0x7ac
	// Line 471, Address: 0x1dd830, Func Offset: 0x7b0
	// Line 474, Address: 0x1dd838, Func Offset: 0x7b8
	// Line 476, Address: 0x1dd83c, Func Offset: 0x7bc
	// Line 479, Address: 0x1dd840, Func Offset: 0x7c0
	// Line 480, Address: 0x1dd850, Func Offset: 0x7d0
	// Line 481, Address: 0x1dd858, Func Offset: 0x7d8
	// Line 482, Address: 0x1dd86c, Func Offset: 0x7ec
	// Line 483, Address: 0x1dd884, Func Offset: 0x804
	// Line 484, Address: 0x1dd888, Func Offset: 0x808
	// Line 483, Address: 0x1dd88c, Func Offset: 0x80c
	// Line 484, Address: 0x1dd898, Func Offset: 0x818
	// Line 487, Address: 0x1dd8a0, Func Offset: 0x820
	// Line 488, Address: 0x1dd8b8, Func Offset: 0x838
	// Line 487, Address: 0x1dd8bc, Func Offset: 0x83c
	// Line 488, Address: 0x1dd8c4, Func Offset: 0x844
	// Line 489, Address: 0x1dd8cc, Func Offset: 0x84c
	// Line 491, Address: 0x1dd8d0, Func Offset: 0x850
	// Line 492, Address: 0x1dd8dc, Func Offset: 0x85c
	// Line 493, Address: 0x1dd8e0, Func Offset: 0x860
	// Line 494, Address: 0x1dd8e4, Func Offset: 0x864
	// Line 495, Address: 0x1dd8e8, Func Offset: 0x868
	// Line 498, Address: 0x1dd8ec, Func Offset: 0x86c
	// Func End, Address: 0x1dd914, Func Offset: 0x894
}

// 
// Start address: 0x1dd920
void bhEne13B_Nage()
{
	// Line 509, Address: 0x1dd920, Func Offset: 0
	// Func End, Address: 0x1dd928, Func Offset: 0x8
}

// 
// Start address: 0x1dd930
void bhEne13B_Damage()
{
	// Line 520, Address: 0x1dd930, Func Offset: 0
	// Func End, Address: 0x1dd938, Func Offset: 0x8
}

// 
// Start address: 0x1dd940
void bhEne13B_Die(BH_PWORK* epw)
{
	int i;
	// Line 533, Address: 0x1dd940, Func Offset: 0
	// Line 537, Address: 0x1dd948, Func Offset: 0x8
	// Line 533, Address: 0x1dd950, Func Offset: 0x10
	// Line 534, Address: 0x1dd958, Func Offset: 0x18
	// Line 537, Address: 0x1dd960, Func Offset: 0x20
	// Line 538, Address: 0x1dd968, Func Offset: 0x28
	// Line 539, Address: 0x1dd96c, Func Offset: 0x2c
	// Line 538, Address: 0x1dd970, Func Offset: 0x30
	// Line 539, Address: 0x1dd980, Func Offset: 0x40
	// Line 540, Address: 0x1dd994, Func Offset: 0x54
	// Line 541, Address: 0x1dd9a4, Func Offset: 0x64
	// Func End, Address: 0x1dd9ac, Func Offset: 0x6c
}

// 
// Start address: 0x1dd9b0
void bhEne13B_SetHittab(BH_PWORK* epw)
{
	_anon4* owk;
	int i;
	// Line 555, Address: 0x1dd9b0, Func Offset: 0
	// Line 557, Address: 0x1dd9c4, Func Offset: 0x14
	// Line 558, Address: 0x1dd9d4, Func Offset: 0x24
	// Line 559, Address: 0x1dd9ec, Func Offset: 0x3c
	// Line 563, Address: 0x1dd9f4, Func Offset: 0x44
	// Line 564, Address: 0x1dda0c, Func Offset: 0x5c
	// Line 568, Address: 0x1dda14, Func Offset: 0x64
	// Line 564, Address: 0x1dda18, Func Offset: 0x68
	// Line 565, Address: 0x1dda1c, Func Offset: 0x6c
	// Line 566, Address: 0x1dda30, Func Offset: 0x80
	// Line 567, Address: 0x1dda44, Func Offset: 0x94
	// Line 568, Address: 0x1dda54, Func Offset: 0xa4
	// Line 567, Address: 0x1dda58, Func Offset: 0xa8
	// Line 568, Address: 0x1dda60, Func Offset: 0xb0
	// Line 569, Address: 0x1dda74, Func Offset: 0xc4
	// Line 571, Address: 0x1dda7c, Func Offset: 0xcc
	// Line 572, Address: 0x1dda88, Func Offset: 0xd8
	// Line 573, Address: 0x1dda8c, Func Offset: 0xdc
	// Line 572, Address: 0x1dda90, Func Offset: 0xe0
	// Line 573, Address: 0x1ddaa0, Func Offset: 0xf0
	// Line 574, Address: 0x1ddab4, Func Offset: 0x104
	// Line 576, Address: 0x1ddabc, Func Offset: 0x10c
	// Func End, Address: 0x1ddac4, Func Offset: 0x114
}

