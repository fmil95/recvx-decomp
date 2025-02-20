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

typedef void(*type_2)(BH_PWORK*);
typedef void(*type_67)(void*);
typedef void(*type_90)(BH_PWORK*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef _anon0* type_3[32];
typedef void(*type_4)(BH_PWORK*)[6];
typedef _anon1* type_5[16];
typedef _anon0* type_6[32];
typedef _anon0* type_7[512];
typedef _anon1* type_8[16][16];
typedef _anon1* type_9[16][16][100];
typedef char type_10[8];
typedef _anon0* type_11[32];
typedef _anon0* type_12[512];
typedef _anon1* type_13[1300];
typedef char type_14[32];
typedef _anon0* type_15[512];
typedef _anon1* type_16[200];
typedef short type_17[32];
typedef _anon12 type_18[1];
typedef _anon0* type_19[128];
typedef unsigned int type_20[1];
typedef _anon4 type_21[256];
typedef _anon1* type_22[8];
typedef int* type_23[16];
typedef _anon0* type_24[128];
typedef npobj* type_25[16];
typedef _anon0* type_26[128];
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
typedef _anon6 type_53[256];
typedef _anon12 type_54[450];
typedef _anon21 type_55[16];
typedef short type_56[256];
typedef char type_57[3];
typedef int type_58[64];
typedef _anon7 type_59[450];
typedef _anon25 type_60[4];
typedef _anon2 type_61[4];
typedef int type_62[450];
typedef unsigned int type_63[8];
typedef unsigned char type_64[450];
typedef char type_65[16];
typedef char type_66[4];
typedef unsigned int type_68[32];
typedef unsigned int type_69[16];
typedef _anon27 type_70[64];
typedef unsigned int type_71[16];
typedef _anon27 type_72[64];
typedef unsigned int type_73[32];
typedef _anon27 type_74[64];
typedef unsigned int type_75[16];
typedef unsigned int type_76[3];
typedef BH_PWORK* type_77[16];
typedef unsigned int type_78[8];
typedef unsigned int type_79[1];
typedef unsigned int type_80[384];
typedef unsigned int type_81[2];
typedef unsigned char type_82[2];
typedef unsigned int type_83[4];
typedef int* type_84[16];
typedef char type_85[32];
typedef npobj* type_86[16];
typedef char type_87[64];
typedef _anon1* type_88[16];
typedef char type_89[4];
typedef void(*type_91)(BH_PWORK*)[3];
typedef _anon7 type_92[16];
typedef short type_93[4];
typedef unsigned char type_94[4];
typedef _anon23 type_95[16];
typedef unsigned int type_96[32];
typedef _anon22 type_97[32];
typedef _anon0* type_98[512];
typedef _anon0* type_99[128];
typedef _anon0* type_100[512];
typedef unsigned char type_101[64];
typedef _anon0* type_102[512];

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

void(*bhEne10_Mode0)(BH_PWORK*)[6];
void(*bhEne10_MoveMode2)(BH_PWORK*)[3];
BH_PWORK* plp;
_anon15* sys;

void bhEne10(BH_PWORK* epw);
void bhEne10_Init(BH_PWORK* epw);
void bhEne10_CheckPos(BH_PWORK* epw);
void bhEne10_Brain(BH_PWORK* epw);
void bhEne10_Move(BH_PWORK* epw);
void bhEne10_MV00();
void bhEne10_MV01(BH_PWORK* epw);
void bhEne10_MV02(BH_PWORK* epw);
void bhEne10_Nage(BH_PWORK* epw);
void bhEne10_Damage();
void bhEne10_Die();

// 
// Start address: 0x1d2440
void bhEne10(BH_PWORK* epw)
{
	int i;
	_anon17* owk;
	// Line 118, Address: 0x1d2440, Func Offset: 0
	// Line 123, Address: 0x1d2454, Func Offset: 0x14
	// Line 126, Address: 0x1d2474, Func Offset: 0x34
	// Line 127, Address: 0x1d2484, Func Offset: 0x44
	// Line 128, Address: 0x1d2498, Func Offset: 0x58
	// Line 129, Address: 0x1d249c, Func Offset: 0x5c
	// Line 130, Address: 0x1d24ac, Func Offset: 0x6c
	// Line 131, Address: 0x1d24c4, Func Offset: 0x84
	// Line 133, Address: 0x1d24c8, Func Offset: 0x88
	// Line 136, Address: 0x1d24e8, Func Offset: 0xa8
	// Line 137, Address: 0x1d24f8, Func Offset: 0xb8
	// Line 138, Address: 0x1d2500, Func Offset: 0xc0
	// Line 139, Address: 0x1d251c, Func Offset: 0xdc
	// Line 143, Address: 0x1d252c, Func Offset: 0xec
	// Line 144, Address: 0x1d253c, Func Offset: 0xfc
	// Line 145, Address: 0x1d2544, Func Offset: 0x104
	// Line 149, Address: 0x1d254c, Func Offset: 0x10c
	// Line 152, Address: 0x1d2558, Func Offset: 0x118
	// Line 153, Address: 0x1d2560, Func Offset: 0x120
	// Line 154, Address: 0x1d2568, Func Offset: 0x128
	// Line 155, Address: 0x1d25a4, Func Offset: 0x164
	// Line 162, Address: 0x1d25a8, Func Offset: 0x168
	// Line 155, Address: 0x1d25b0, Func Offset: 0x170
	// Line 157, Address: 0x1d25b4, Func Offset: 0x174
	// Line 158, Address: 0x1d25bc, Func Offset: 0x17c
	// Line 159, Address: 0x1d25c4, Func Offset: 0x184
	// Line 160, Address: 0x1d25cc, Func Offset: 0x18c
	// Line 162, Address: 0x1d25d4, Func Offset: 0x194
	// Line 165, Address: 0x1d25d8, Func Offset: 0x198
	// Line 166, Address: 0x1d25ec, Func Offset: 0x1ac
	// Line 169, Address: 0x1d25f8, Func Offset: 0x1b8
	// Line 170, Address: 0x1d2604, Func Offset: 0x1c4
	// Func End, Address: 0x1d2618, Func Offset: 0x1d8
}

// 
// Start address: 0x1d2620
void bhEne10_Init(BH_PWORK* epw)
{
	int ang;
	// Line 181, Address: 0x1d2620, Func Offset: 0
	// Line 185, Address: 0x1d2630, Func Offset: 0x10
	// Line 186, Address: 0x1d263c, Func Offset: 0x1c
	// Line 190, Address: 0x1d264c, Func Offset: 0x2c
	// Line 195, Address: 0x1d2650, Func Offset: 0x30
	// Line 194, Address: 0x1d2658, Func Offset: 0x38
	// Line 199, Address: 0x1d265c, Func Offset: 0x3c
	// Line 190, Address: 0x1d2660, Func Offset: 0x40
	// Line 194, Address: 0x1d2668, Func Offset: 0x48
	// Line 209, Address: 0x1d266c, Func Offset: 0x4c
	// Line 210, Address: 0x1d2674, Func Offset: 0x54
	// Line 203, Address: 0x1d2678, Func Offset: 0x58
	// Line 194, Address: 0x1d267c, Func Offset: 0x5c
	// Line 210, Address: 0x1d2684, Func Offset: 0x64
	// Line 195, Address: 0x1d2688, Func Offset: 0x68
	// Line 198, Address: 0x1d2694, Func Offset: 0x74
	// Line 199, Address: 0x1d26a0, Func Offset: 0x80
	// Line 200, Address: 0x1d26a4, Func Offset: 0x84
	// Line 201, Address: 0x1d26a8, Func Offset: 0x88
	// Line 202, Address: 0x1d26ac, Func Offset: 0x8c
	// Line 203, Address: 0x1d26b0, Func Offset: 0x90
	// Line 206, Address: 0x1d26b4, Func Offset: 0x94
	// Line 207, Address: 0x1d26c0, Func Offset: 0xa0
	// Line 208, Address: 0x1d26cc, Func Offset: 0xac
	// Line 209, Address: 0x1d26d8, Func Offset: 0xb8
	// Line 210, Address: 0x1d26dc, Func Offset: 0xbc
	// Line 211, Address: 0x1d26e4, Func Offset: 0xc4
	// Line 212, Address: 0x1d26ec, Func Offset: 0xcc
	// Line 213, Address: 0x1d26f4, Func Offset: 0xd4
	// Line 216, Address: 0x1d26fc, Func Offset: 0xdc
	// Line 217, Address: 0x1d2700, Func Offset: 0xe0
	// Line 218, Address: 0x1d2704, Func Offset: 0xe4
	// Line 222, Address: 0x1d2708, Func Offset: 0xe8
	// Line 223, Address: 0x1d2760, Func Offset: 0x140
	// Line 227, Address: 0x1d2794, Func Offset: 0x174
	// Line 228, Address: 0x1d2798, Func Offset: 0x178
	// Line 223, Address: 0x1d279c, Func Offset: 0x17c
	// Line 226, Address: 0x1d27a0, Func Offset: 0x180
	// Line 227, Address: 0x1d27a4, Func Offset: 0x184
	// Line 228, Address: 0x1d27a8, Func Offset: 0x188
	// Line 229, Address: 0x1d27b4, Func Offset: 0x194
	// Func End, Address: 0x1d27c8, Func Offset: 0x1a8
}

// 
// Start address: 0x1d27d0
void bhEne10_CheckPos(BH_PWORK* epw)
{
	int ang;
	float dz;
	float dx;
	// Line 239, Address: 0x1d27d0, Func Offset: 0
	// Line 244, Address: 0x1d27e4, Func Offset: 0x14
	// Line 245, Address: 0x1d27ec, Func Offset: 0x1c
	// Line 244, Address: 0x1d27f4, Func Offset: 0x24
	// Line 245, Address: 0x1d27f8, Func Offset: 0x28
	// Line 244, Address: 0x1d27fc, Func Offset: 0x2c
	// Line 245, Address: 0x1d2800, Func Offset: 0x30
	// Line 246, Address: 0x1d2804, Func Offset: 0x34
	// Line 249, Address: 0x1d2814, Func Offset: 0x44
	// Line 246, Address: 0x1d2818, Func Offset: 0x48
	// Line 249, Address: 0x1d281c, Func Offset: 0x4c
	// Line 250, Address: 0x1d2824, Func Offset: 0x54
	// Line 249, Address: 0x1d2828, Func Offset: 0x58
	// Line 250, Address: 0x1d282c, Func Offset: 0x5c
	// Line 249, Address: 0x1d2830, Func Offset: 0x60
	// Line 250, Address: 0x1d2834, Func Offset: 0x64
	// Line 251, Address: 0x1d2838, Func Offset: 0x68
	// Line 252, Address: 0x1d2848, Func Offset: 0x78
	// Line 253, Address: 0x1d286c, Func Offset: 0x9c
	// Line 254, Address: 0x1d2884, Func Offset: 0xb4
	// Func End, Address: 0x1d289c, Func Offset: 0xcc
}

// 
// Start address: 0x1d28a0
void bhEne10_Brain(BH_PWORK* epw)
{
	// Line 265, Address: 0x1d28a0, Func Offset: 0
	// Line 268, Address: 0x1d28ac, Func Offset: 0xc
	// Line 273, Address: 0x1d28f8, Func Offset: 0x58
	// Line 275, Address: 0x1d2908, Func Offset: 0x68
	// Line 278, Address: 0x1d293c, Func Offset: 0x9c
	// Line 279, Address: 0x1d2944, Func Offset: 0xa4
	// Line 280, Address: 0x1d2948, Func Offset: 0xa8
	// Line 284, Address: 0x1d294c, Func Offset: 0xac
	// Line 285, Address: 0x1d2958, Func Offset: 0xb8
	// Line 291, Address: 0x1d2960, Func Offset: 0xc0
	// Line 293, Address: 0x1d2990, Func Offset: 0xf0
	// Line 294, Address: 0x1d2998, Func Offset: 0xf8
	// Line 295, Address: 0x1d299c, Func Offset: 0xfc
	// Line 298, Address: 0x1d29a0, Func Offset: 0x100
	// Line 296, Address: 0x1d29a4, Func Offset: 0x104
	// Line 298, Address: 0x1d29a8, Func Offset: 0x108
	// Line 300, Address: 0x1d29b0, Func Offset: 0x110
	// Func End, Address: 0x1d29c0, Func Offset: 0x120
}

// 
// Start address: 0x1d29c0
void bhEne10_Move(BH_PWORK* epw)
{
	_anon22 pos;
	// Line 311, Address: 0x1d29c0, Func Offset: 0
	// Line 315, Address: 0x1d29cc, Func Offset: 0xc
	// Line 316, Address: 0x1d29dc, Func Offset: 0x1c
	// Line 319, Address: 0x1d29e4, Func Offset: 0x24
	// Line 320, Address: 0x1d29fc, Func Offset: 0x3c
	// Line 321, Address: 0x1d2a24, Func Offset: 0x64
	// Line 333, Address: 0x1d2a58, Func Offset: 0x98
	// Line 338, Address: 0x1d2a64, Func Offset: 0xa4
	// Line 339, Address: 0x1d2a74, Func Offset: 0xb4
	// Line 343, Address: 0x1d2a7c, Func Offset: 0xbc
	// Line 345, Address: 0x1d2a8c, Func Offset: 0xcc
	// Line 348, Address: 0x1d2a9c, Func Offset: 0xdc
	// Line 355, Address: 0x1d2aa0, Func Offset: 0xe0
	// Line 353, Address: 0x1d2aa4, Func Offset: 0xe4
	// Line 355, Address: 0x1d2aa8, Func Offset: 0xe8
	// Line 348, Address: 0x1d2aac, Func Offset: 0xec
	// Line 350, Address: 0x1d2ab0, Func Offset: 0xf0
	// Line 355, Address: 0x1d2ab4, Func Offset: 0xf4
	// Line 350, Address: 0x1d2ac0, Func Offset: 0x100
	// Line 351, Address: 0x1d2ac4, Func Offset: 0x104
	// Line 352, Address: 0x1d2acc, Func Offset: 0x10c
	// Line 353, Address: 0x1d2ad0, Func Offset: 0x110
	// Line 355, Address: 0x1d2ad4, Func Offset: 0x114
	// Line 371, Address: 0x1d2adc, Func Offset: 0x11c
	// Line 372, Address: 0x1d2ae0, Func Offset: 0x120
	// Line 377, Address: 0x1d2ae4, Func Offset: 0x124
	// Line 371, Address: 0x1d2ae8, Func Offset: 0x128
	// Line 372, Address: 0x1d2af0, Func Offset: 0x130
	// Line 373, Address: 0x1d2af4, Func Offset: 0x134
	// Line 374, Address: 0x1d2af8, Func Offset: 0x138
	// Line 375, Address: 0x1d2afc, Func Offset: 0x13c
	// Line 379, Address: 0x1d2b00, Func Offset: 0x140
	// Line 383, Address: 0x1d2b08, Func Offset: 0x148
	// Line 384, Address: 0x1d2b18, Func Offset: 0x158
	// Line 385, Address: 0x1d2b38, Func Offset: 0x178
	// Func End, Address: 0x1d2b48, Func Offset: 0x188
}

// 
// Start address: 0x1d2b50
void bhEne10_MV00()
{
	// Line 396, Address: 0x1d2b50, Func Offset: 0
	// Func End, Address: 0x1d2b58, Func Offset: 0x8
}

// 
// Start address: 0x1d2b60
void bhEne10_MV01(BH_PWORK* epw)
{
	int ang;
	// Line 406, Address: 0x1d2b60, Func Offset: 0
	// Line 409, Address: 0x1d2b74, Func Offset: 0x14
	// Line 412, Address: 0x1d2b94, Func Offset: 0x34
	// Line 413, Address: 0x1d2bb8, Func Offset: 0x58
	// Line 416, Address: 0x1d2bc4, Func Offset: 0x64
	// Line 417, Address: 0x1d2bcc, Func Offset: 0x6c
	// Line 416, Address: 0x1d2bd4, Func Offset: 0x74
	// Line 417, Address: 0x1d2bdc, Func Offset: 0x7c
	// Line 419, Address: 0x1d2be4, Func Offset: 0x84
	// Line 420, Address: 0x1d2bf4, Func Offset: 0x94
	// Line 422, Address: 0x1d2c08, Func Offset: 0xa8
	// Line 424, Address: 0x1d2c18, Func Offset: 0xb8
	// Line 425, Address: 0x1d2c70, Func Offset: 0x110
	// Line 427, Address: 0x1d2ca4, Func Offset: 0x144
	// Line 425, Address: 0x1d2ca8, Func Offset: 0x148
	// Line 427, Address: 0x1d2cac, Func Offset: 0x14c
	// Line 428, Address: 0x1d2cb0, Func Offset: 0x150
	// Line 429, Address: 0x1d2cb4, Func Offset: 0x154
	// Line 430, Address: 0x1d2cb8, Func Offset: 0x158
	// Line 435, Address: 0x1d2cbc, Func Offset: 0x15c
	// Func End, Address: 0x1d2cd0, Func Offset: 0x170
}

// 
// Start address: 0x1d2cd0
void bhEne10_MV02(BH_PWORK* epw)
{
	int ay;
	// Line 445, Address: 0x1d2cd0, Func Offset: 0
	// Line 448, Address: 0x1d2ce0, Func Offset: 0x10
	// Line 451, Address: 0x1d2d0c, Func Offset: 0x3c
	// Line 452, Address: 0x1d2d20, Func Offset: 0x50
	// Line 451, Address: 0x1d2d24, Func Offset: 0x54
	// Line 453, Address: 0x1d2d28, Func Offset: 0x58
	// Line 452, Address: 0x1d2d30, Func Offset: 0x60
	// Line 453, Address: 0x1d2d34, Func Offset: 0x64
	// Line 454, Address: 0x1d2d3c, Func Offset: 0x6c
	// Line 455, Address: 0x1d2d80, Func Offset: 0xb0
	// Line 456, Address: 0x1d2d84, Func Offset: 0xb4
	// Line 455, Address: 0x1d2d8c, Func Offset: 0xbc
	// Line 458, Address: 0x1d2d94, Func Offset: 0xc4
	// Line 461, Address: 0x1d2d9c, Func Offset: 0xcc
	// Line 462, Address: 0x1d2db4, Func Offset: 0xe4
	// Line 461, Address: 0x1d2dbc, Func Offset: 0xec
	// Line 462, Address: 0x1d2dc0, Func Offset: 0xf0
	// Line 464, Address: 0x1d2dc8, Func Offset: 0xf8
	// Line 465, Address: 0x1d2dd8, Func Offset: 0x108
	// Line 466, Address: 0x1d2dec, Func Offset: 0x11c
	// Line 468, Address: 0x1d2e6c, Func Offset: 0x19c
	// Line 470, Address: 0x1d2e74, Func Offset: 0x1a4
	// Line 474, Address: 0x1d2e7c, Func Offset: 0x1ac
	// Line 475, Address: 0x1d2ec4, Func Offset: 0x1f4
	// Line 482, Address: 0x1d2ef8, Func Offset: 0x228
	// Line 477, Address: 0x1d2efc, Func Offset: 0x22c
	// Line 482, Address: 0x1d2f00, Func Offset: 0x230
	// Line 475, Address: 0x1d2f04, Func Offset: 0x234
	// Line 477, Address: 0x1d2f08, Func Offset: 0x238
	// Line 478, Address: 0x1d2f0c, Func Offset: 0x23c
	// Line 479, Address: 0x1d2f10, Func Offset: 0x240
	// Line 480, Address: 0x1d2f14, Func Offset: 0x244
	// Line 482, Address: 0x1d2f18, Func Offset: 0x248
	// Line 485, Address: 0x1d2f1c, Func Offset: 0x24c
	// Func End, Address: 0x1d2f30, Func Offset: 0x260
}

// 
// Start address: 0x1d2f30
void bhEne10_Nage(BH_PWORK* epw)
{
	int ay;
	// Line 496, Address: 0x1d2f30, Func Offset: 0
	// Line 500, Address: 0x1d2f44, Func Offset: 0x14
	// Line 503, Address: 0x1d2f64, Func Offset: 0x34
	// Line 504, Address: 0x1d2f70, Func Offset: 0x40
	// Line 503, Address: 0x1d2f74, Func Offset: 0x44
	// Line 504, Address: 0x1d2f7c, Func Offset: 0x4c
	// Line 505, Address: 0x1d2f84, Func Offset: 0x54
	// Line 504, Address: 0x1d2f88, Func Offset: 0x58
	// Line 505, Address: 0x1d2f90, Func Offset: 0x60
	// Line 506, Address: 0x1d2fa4, Func Offset: 0x74
	// Line 507, Address: 0x1d2fa8, Func Offset: 0x78
	// Line 513, Address: 0x1d2fb4, Func Offset: 0x84
	// Line 516, Address: 0x1d2fb8, Func Offset: 0x88
	// Line 507, Address: 0x1d2fbc, Func Offset: 0x8c
	// Line 508, Address: 0x1d2fc0, Func Offset: 0x90
	// Line 516, Address: 0x1d2fc8, Func Offset: 0x98
	// Line 508, Address: 0x1d2fd4, Func Offset: 0xa4
	// Line 509, Address: 0x1d2fd8, Func Offset: 0xa8
	// Line 510, Address: 0x1d2fe4, Func Offset: 0xb4
	// Line 516, Address: 0x1d2ff0, Func Offset: 0xc0
	// Line 518, Address: 0x1d2ff8, Func Offset: 0xc8
	// Line 520, Address: 0x1d3004, Func Offset: 0xd4
	// Line 524, Address: 0x1d300c, Func Offset: 0xdc
	// Line 520, Address: 0x1d3014, Func Offset: 0xe4
	// Line 525, Address: 0x1d3018, Func Offset: 0xe8
	// Line 520, Address: 0x1d301c, Func Offset: 0xec
	// Line 525, Address: 0x1d3028, Func Offset: 0xf8
	// Line 521, Address: 0x1d3030, Func Offset: 0x100
	// Line 527, Address: 0x1d303c, Func Offset: 0x10c
	// Line 531, Address: 0x1d3040, Func Offset: 0x110
	// Line 521, Address: 0x1d3048, Func Offset: 0x118
	// Line 522, Address: 0x1d3054, Func Offset: 0x124
	// Line 531, Address: 0x1d305c, Func Offset: 0x12c
	// Line 522, Address: 0x1d3060, Func Offset: 0x130
	// Line 523, Address: 0x1d306c, Func Offset: 0x13c
	// Line 524, Address: 0x1d3080, Func Offset: 0x150
	// Line 525, Address: 0x1d309c, Func Offset: 0x16c
	// Line 526, Address: 0x1d30b8, Func Offset: 0x188
	// Line 527, Address: 0x1d30d4, Func Offset: 0x1a4
	// Line 528, Address: 0x1d30e8, Func Offset: 0x1b8
	// Line 529, Address: 0x1d30fc, Func Offset: 0x1cc
	// Line 530, Address: 0x1d3110, Func Offset: 0x1e0
	// Line 531, Address: 0x1d3128, Func Offset: 0x1f8
	// Line 536, Address: 0x1d3140, Func Offset: 0x210
	// Line 538, Address: 0x1d314c, Func Offset: 0x21c
	// Line 540, Address: 0x1d315c, Func Offset: 0x22c
	// Line 542, Address: 0x1d3160, Func Offset: 0x230
	// Line 540, Address: 0x1d3164, Func Offset: 0x234
	// Line 542, Address: 0x1d3170, Func Offset: 0x240
	// Line 544, Address: 0x1d3174, Func Offset: 0x244
	// Line 545, Address: 0x1d31a8, Func Offset: 0x278
	// Line 552, Address: 0x1d31dc, Func Offset: 0x2ac
	// Line 547, Address: 0x1d31e0, Func Offset: 0x2b0
	// Line 552, Address: 0x1d31e4, Func Offset: 0x2b4
	// Line 545, Address: 0x1d31e8, Func Offset: 0x2b8
	// Line 547, Address: 0x1d31ec, Func Offset: 0x2bc
	// Line 548, Address: 0x1d31f0, Func Offset: 0x2c0
	// Line 549, Address: 0x1d31f4, Func Offset: 0x2c4
	// Line 550, Address: 0x1d31f8, Func Offset: 0x2c8
	// Line 552, Address: 0x1d31fc, Func Offset: 0x2cc
	// Line 556, Address: 0x1d3200, Func Offset: 0x2d0
	// Func End, Address: 0x1d3214, Func Offset: 0x2e4
}

// 
// Start address: 0x1d3220
void bhEne10_Damage()
{
	// Line 568, Address: 0x1d3220, Func Offset: 0
	// Func End, Address: 0x1d3228, Func Offset: 0x8
}

// 
// Start address: 0x1d3230
void bhEne10_Die()
{
	// Line 580, Address: 0x1d3230, Func Offset: 0
	// Func End, Address: 0x1d3238, Func Offset: 0x8
}

