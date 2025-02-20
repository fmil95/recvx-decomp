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

typedef void(*type_2)(BH_PWORK*);
typedef void(*type_36)(BH_PWORK*);
typedef void(*type_69)(void*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef _anon0* type_3[32];
typedef void(*type_4)(BH_PWORK*)[4];
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
typedef _anon3* type_37[128];
typedef void(*type_38)(BH_PWORK*)[6];
typedef unsigned char type_39[64];
typedef float type_40[16];
typedef char type_41[8];
typedef void* type_42[2];
typedef _anon1* type_43[256];
typedef int type_44[4];
typedef unsigned char* type_45[256];
typedef unsigned int type_46[2];
typedef short type_47[256];
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
typedef short type_58[256];
typedef char type_59[3];
typedef int type_60[64];
typedef _anon7 type_61[450];
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
typedef _anon27 type_76[64];
typedef unsigned int type_77[16];
typedef unsigned int type_78[3];
typedef BH_PWORK* type_79[16];
typedef unsigned int type_80[8];
typedef unsigned int type_81[1];
typedef unsigned int type_82[384];
typedef unsigned int type_83[2];
typedef unsigned char type_84[2];
typedef unsigned int type_85[4];
typedef int* type_86[16];
typedef char type_87[32];
typedef npobj* type_88[16];
typedef char type_89[64];
typedef _anon1* type_90[16];
typedef char type_91[4];
typedef _anon7 type_92[16];
typedef short type_93[4];
typedef unsigned char type_94[4];
typedef _anon23 type_95[16];
typedef unsigned int type_96[32];
typedef float type_97[5];
typedef _anon22 type_98[32];
typedef int type_99[5];
typedef _anon0* type_100[512];
typedef _anon0* type_101[128];
typedef _anon0* type_102[512];
typedef unsigned char type_103[64];
typedef _anon0* type_104[512];

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

struct _anon33
{
	_anon22 off_pos;
	int srd_dir;
	float srd_pos;
	float bld_spd;
	float srt_spd[5];
	int srt_dir[5];
};

_anon33 BloodParam;
void(*bhEne25_Mode0)(BH_PWORK*)[6];
void(*bhEne25_MoveMode2)(BH_PWORK*)[4];
_anon15* sys;
BH_PWORK* plp;

void bhEne25(BH_PWORK* epw);
void bhEne25_Init(BH_PWORK* epw);
void bhEne25_Brain();
void bhEne25_Move(BH_PWORK* epw);
void bhEne25_MV00(BH_PWORK* epw);
void bhEne25_MV01(BH_PWORK* epw);
void bhEne25_MV02(BH_PWORK* epw);
void bhEne25_MV03(BH_PWORK* epw);
void bhEne25_Nage();
void bhEne25_Damage();
void bhEne25_Die();
void bhEne25_SetEffect(BH_PWORK* epw);
void bhEne25_PlayerControl(BH_PWORK* epw);

// 
// Start address: 0x208950
void bhEne25(BH_PWORK* epw)
{
	// Line 137, Address: 0x208950, Func Offset: 0
	// Line 139, Address: 0x208960, Func Offset: 0x10
	// Line 142, Address: 0x208980, Func Offset: 0x30
	// Line 145, Address: 0x208994, Func Offset: 0x44
	// Line 148, Address: 0x20899c, Func Offset: 0x4c
	// Line 149, Address: 0x2089b0, Func Offset: 0x60
	// Line 150, Address: 0x2089b8, Func Offset: 0x68
	// Func End, Address: 0x2089c8, Func Offset: 0x78
}

// 
// Start address: 0x2089d0
void bhEne25_Init(BH_PWORK* epw)
{
	// Line 161, Address: 0x2089d0, Func Offset: 0
	// Line 163, Address: 0x2089dc, Func Offset: 0xc
	// Line 164, Address: 0x2089e8, Func Offset: 0x18
	// Line 167, Address: 0x2089f8, Func Offset: 0x28
	// Line 171, Address: 0x208a00, Func Offset: 0x30
	// Line 167, Address: 0x208a04, Func Offset: 0x34
	// Line 168, Address: 0x208a4c, Func Offset: 0x7c
	// Line 169, Address: 0x208a60, Func Offset: 0x90
	// Line 170, Address: 0x208a6c, Func Offset: 0x9c
	// Line 171, Address: 0x208a78, Func Offset: 0xa8
	// Line 172, Address: 0x208a84, Func Offset: 0xb4
	// Line 176, Address: 0x208ab4, Func Offset: 0xe4
	// Line 177, Address: 0x208ab8, Func Offset: 0xe8
	// Line 176, Address: 0x208ac0, Func Offset: 0xf0
	// Line 181, Address: 0x208ac4, Func Offset: 0xf4
	// Line 176, Address: 0x208acc, Func Offset: 0xfc
	// Line 179, Address: 0x208ad0, Func Offset: 0x100
	// Line 193, Address: 0x208ad4, Func Offset: 0x104
	// Line 176, Address: 0x208ad8, Func Offset: 0x108
	// Line 177, Address: 0x208adc, Func Offset: 0x10c
	// Line 187, Address: 0x208ae4, Func Offset: 0x114
	// Line 177, Address: 0x208ae8, Func Offset: 0x118
	// Line 179, Address: 0x208af4, Func Offset: 0x124
	// Line 180, Address: 0x208b00, Func Offset: 0x130
	// Line 181, Address: 0x208b0c, Func Offset: 0x13c
	// Line 182, Address: 0x208b20, Func Offset: 0x150
	// Line 185, Address: 0x208b34, Func Offset: 0x164
	// Line 186, Address: 0x208b40, Func Offset: 0x170
	// Line 187, Address: 0x208b4c, Func Offset: 0x17c
	// Line 189, Address: 0x208b58, Func Offset: 0x188
	// Line 190, Address: 0x208b5c, Func Offset: 0x18c
	// Line 191, Address: 0x208b60, Func Offset: 0x190
	// Line 192, Address: 0x208b64, Func Offset: 0x194
	// Line 193, Address: 0x208b68, Func Offset: 0x198
	// Line 196, Address: 0x208b6c, Func Offset: 0x19c
	// Line 197, Address: 0x208b74, Func Offset: 0x1a4
	// Line 198, Address: 0x208b7c, Func Offset: 0x1ac
	// Line 201, Address: 0x208b84, Func Offset: 0x1b4
	// Line 202, Address: 0x208b88, Func Offset: 0x1b8
	// Line 203, Address: 0x208b8c, Func Offset: 0x1bc
	// Line 204, Address: 0x208b90, Func Offset: 0x1c0
	// Line 205, Address: 0x208b94, Func Offset: 0x1c4
	// Line 208, Address: 0x208b98, Func Offset: 0x1c8
	// Line 209, Address: 0x208ba4, Func Offset: 0x1d4
	// Line 210, Address: 0x208bac, Func Offset: 0x1dc
	// Line 211, Address: 0x208bb0, Func Offset: 0x1e0
	// Line 213, Address: 0x208bb4, Func Offset: 0x1e4
	// Line 214, Address: 0x208bc8, Func Offset: 0x1f8
	// Line 215, Address: 0x208bd0, Func Offset: 0x200
	// Line 216, Address: 0x208bd4, Func Offset: 0x204
	// Line 217, Address: 0x208bd8, Func Offset: 0x208
	// Line 221, Address: 0x208bdc, Func Offset: 0x20c
	// Line 222, Address: 0x208be8, Func Offset: 0x218
	// Func End, Address: 0x208bf8, Func Offset: 0x228
}

// 
// Start address: 0x208c00
void bhEne25_Brain()
{
	// Line 234, Address: 0x208c00, Func Offset: 0
	// Func End, Address: 0x208c08, Func Offset: 0x8
}

// 
// Start address: 0x208c10
void bhEne25_Move(BH_PWORK* epw)
{
	float bz;
	float bx;
	float tz;
	float tx;
	// Line 245, Address: 0x208c10, Func Offset: 0
	// Line 250, Address: 0x208c1c, Func Offset: 0xc
	// Line 255, Address: 0x208c2c, Func Offset: 0x1c
	// Line 251, Address: 0x208c34, Func Offset: 0x24
	// Line 250, Address: 0x208c3c, Func Offset: 0x2c
	// Line 255, Address: 0x208c40, Func Offset: 0x30
	// Line 252, Address: 0x208c44, Func Offset: 0x34
	// Line 251, Address: 0x208c48, Func Offset: 0x38
	// Line 255, Address: 0x208c4c, Func Offset: 0x3c
	// Line 257, Address: 0x208c90, Func Offset: 0x80
	// Line 258, Address: 0x208c98, Func Offset: 0x88
	// Line 259, Address: 0x208ca0, Func Offset: 0x90
	// Line 263, Address: 0x208ca8, Func Offset: 0x98
	// Line 268, Address: 0x208cb8, Func Offset: 0xa8
	// Line 264, Address: 0x208cbc, Func Offset: 0xac
	// Line 268, Address: 0x208cc0, Func Offset: 0xb0
	// Line 263, Address: 0x208cc4, Func Offset: 0xb4
	// Line 265, Address: 0x208cc8, Func Offset: 0xb8
	// Line 268, Address: 0x208ccc, Func Offset: 0xbc
	// Line 264, Address: 0x208cd0, Func Offset: 0xc0
	// Line 268, Address: 0x208cd4, Func Offset: 0xc4
	// Line 270, Address: 0x208d18, Func Offset: 0x108
	// Line 271, Address: 0x208d20, Func Offset: 0x110
	// Line 272, Address: 0x208d28, Func Offset: 0x118
	// Line 276, Address: 0x208d30, Func Offset: 0x120
	// Line 277, Address: 0x208d40, Func Offset: 0x130
	// Line 280, Address: 0x208d48, Func Offset: 0x138
	// Line 281, Address: 0x208d58, Func Offset: 0x148
	// Line 282, Address: 0x208d78, Func Offset: 0x168
	// Func End, Address: 0x208d88, Func Offset: 0x178
}

// 
// Start address: 0x208d90
void bhEne25_MV00(BH_PWORK* epw)
{
	// Line 294, Address: 0x208d90, Func Offset: 0
	// Line 297, Address: 0x208db0, Func Offset: 0x20
	// Line 298, Address: 0x208db4, Func Offset: 0x24
	// Line 300, Address: 0x208db8, Func Offset: 0x28
	// Func End, Address: 0x208dc0, Func Offset: 0x30
}

// 
// Start address: 0x208dc0
void bhEne25_MV01(BH_PWORK* epw)
{
	// Line 310, Address: 0x208dc0, Func Offset: 0
	// Line 314, Address: 0x208dd0, Func Offset: 0x10
	// Line 317, Address: 0x208e14, Func Offset: 0x54
	// Line 318, Address: 0x208e1c, Func Offset: 0x5c
	// Line 320, Address: 0x208e28, Func Offset: 0x68
	// Line 322, Address: 0x208e38, Func Offset: 0x78
	// Line 323, Address: 0x208e40, Func Offset: 0x80
	// Line 325, Address: 0x208e48, Func Offset: 0x88
	// Line 329, Address: 0x208e50, Func Offset: 0x90
	// Line 332, Address: 0x208e58, Func Offset: 0x98
	// Line 329, Address: 0x208e5c, Func Offset: 0x9c
	// Line 332, Address: 0x208e6c, Func Offset: 0xac
	// Line 334, Address: 0x208e90, Func Offset: 0xd0
	// Line 336, Address: 0x208e9c, Func Offset: 0xdc
	// Line 337, Address: 0x208ec8, Func Offset: 0x108
	// Line 338, Address: 0x208ed8, Func Offset: 0x118
	// Line 339, Address: 0x208ee0, Func Offset: 0x120
	// Line 338, Address: 0x208ee8, Func Offset: 0x128
	// Line 339, Address: 0x208ef0, Func Offset: 0x130
	// Line 340, Address: 0x208ef8, Func Offset: 0x138
	// Line 339, Address: 0x208efc, Func Offset: 0x13c
	// Line 340, Address: 0x208f04, Func Offset: 0x144
	// Line 342, Address: 0x208f14, Func Offset: 0x154
	// Line 343, Address: 0x208f24, Func Offset: 0x164
	// Line 342, Address: 0x208f2c, Func Offset: 0x16c
	// Line 343, Address: 0x208f30, Func Offset: 0x170
	// Line 342, Address: 0x208f34, Func Offset: 0x174
	// Line 343, Address: 0x208f3c, Func Offset: 0x17c
	// Line 344, Address: 0x208f44, Func Offset: 0x184
	// Line 343, Address: 0x208f48, Func Offset: 0x188
	// Line 344, Address: 0x208f50, Func Offset: 0x190
	// Line 347, Address: 0x208f60, Func Offset: 0x1a0
	// Line 350, Address: 0x208f64, Func Offset: 0x1a4
	// Line 351, Address: 0x208f6c, Func Offset: 0x1ac
	// Line 347, Address: 0x208f70, Func Offset: 0x1b0
	// Line 350, Address: 0x208f78, Func Offset: 0x1b8
	// Line 353, Address: 0x208f7c, Func Offset: 0x1bc
	// Line 354, Address: 0x208f80, Func Offset: 0x1c0
	// Line 356, Address: 0x208f84, Func Offset: 0x1c4
	// Line 350, Address: 0x208f88, Func Offset: 0x1c8
	// Line 351, Address: 0x208f8c, Func Offset: 0x1cc
	// Line 350, Address: 0x208f90, Func Offset: 0x1d0
	// Line 351, Address: 0x208f98, Func Offset: 0x1d8
	// Line 354, Address: 0x208fa0, Func Offset: 0x1e0
	// Line 351, Address: 0x208fa4, Func Offset: 0x1e4
	// Line 353, Address: 0x208fac, Func Offset: 0x1ec
	// Line 354, Address: 0x208fb4, Func Offset: 0x1f4
	// Line 355, Address: 0x208fbc, Func Offset: 0x1fc
	// Line 356, Address: 0x208fc8, Func Offset: 0x208
	// Line 359, Address: 0x208fd4, Func Offset: 0x214
	// Line 361, Address: 0x208fe8, Func Offset: 0x228
	// Line 363, Address: 0x208ff0, Func Offset: 0x230
	// Line 365, Address: 0x208ffc, Func Offset: 0x23c
	// Line 367, Address: 0x20900c, Func Offset: 0x24c
	// Line 370, Address: 0x20903c, Func Offset: 0x27c
	// Line 373, Address: 0x209048, Func Offset: 0x288
	// Line 374, Address: 0x209050, Func Offset: 0x290
	// Line 375, Address: 0x209054, Func Offset: 0x294
	// Line 377, Address: 0x20905c, Func Offset: 0x29c
	// Line 379, Address: 0x209064, Func Offset: 0x2a4
	// Line 384, Address: 0x209094, Func Offset: 0x2d4
	// Line 381, Address: 0x209098, Func Offset: 0x2d8
	// Line 384, Address: 0x20909c, Func Offset: 0x2dc
	// Line 385, Address: 0x2090a0, Func Offset: 0x2e0
	// Line 387, Address: 0x2090a8, Func Offset: 0x2e8
	// Line 389, Address: 0x2090b0, Func Offset: 0x2f0
	// Line 391, Address: 0x2090c0, Func Offset: 0x300
	// Line 392, Address: 0x2090c8, Func Offset: 0x308
	// Line 396, Address: 0x2090cc, Func Offset: 0x30c
	// Func End, Address: 0x2090dc, Func Offset: 0x31c
}

// 
// Start address: 0x2090e0
void bhEne25_MV02(BH_PWORK* epw)
{
	// Line 406, Address: 0x2090e0, Func Offset: 0
	// Line 407, Address: 0x2090f0, Func Offset: 0x10
	// Line 410, Address: 0x209110, Func Offset: 0x30
	// Line 411, Address: 0x209118, Func Offset: 0x38
	// Line 414, Address: 0x20911c, Func Offset: 0x3c
	// Line 417, Address: 0x209124, Func Offset: 0x44
	// Line 419, Address: 0x209134, Func Offset: 0x54
	// Line 423, Address: 0x209140, Func Offset: 0x60
	// Line 424, Address: 0x209158, Func Offset: 0x78
	// Line 426, Address: 0x209188, Func Offset: 0xa8
	// Line 429, Address: 0x209198, Func Offset: 0xb8
	// Line 426, Address: 0x20919c, Func Offset: 0xbc
	// Line 428, Address: 0x2091a8, Func Offset: 0xc8
	// Line 429, Address: 0x2091ac, Func Offset: 0xcc
	// Line 430, Address: 0x2091b0, Func Offset: 0xd0
	// Line 434, Address: 0x2091b4, Func Offset: 0xd4
	// Func End, Address: 0x2091c4, Func Offset: 0xe4
}

// 
// Start address: 0x2091d0
void bhEne25_MV03(BH_PWORK* epw)
{
	// Line 445, Address: 0x2091d0, Func Offset: 0
	// Line 448, Address: 0x2091f0, Func Offset: 0x20
	// Line 449, Address: 0x2091f4, Func Offset: 0x24
	// Line 450, Address: 0x2091f8, Func Offset: 0x28
	// Line 451, Address: 0x2091fc, Func Offset: 0x2c
	// Line 454, Address: 0x209200, Func Offset: 0x30
	// Line 452, Address: 0x209204, Func Offset: 0x34
	// Line 454, Address: 0x209208, Func Offset: 0x38
	// Line 455, Address: 0x20920c, Func Offset: 0x3c
	// Line 457, Address: 0x209218, Func Offset: 0x48
	// Line 459, Address: 0x209228, Func Offset: 0x58
	// Line 460, Address: 0x20922c, Func Offset: 0x5c
	// Line 464, Address: 0x209230, Func Offset: 0x60
	// Func End, Address: 0x209238, Func Offset: 0x68
}

// 
// Start address: 0x209240
void bhEne25_Nage()
{
	// Line 476, Address: 0x209240, Func Offset: 0
	// Func End, Address: 0x209248, Func Offset: 0x8
}

// 
// Start address: 0x209250
void bhEne25_Damage()
{
	// Line 488, Address: 0x209250, Func Offset: 0
	// Func End, Address: 0x209258, Func Offset: 0x8
}

// 
// Start address: 0x209260
void bhEne25_Die()
{
	// Line 500, Address: 0x209260, Func Offset: 0
	// Func End, Address: 0x209268, Func Offset: 0x8
}

// 
// Start address: 0x209270
void bhEne25_SetEffect(BH_PWORK* epw)
{
	int i;
	// Line 511, Address: 0x209270, Func Offset: 0
	// Line 514, Address: 0x209288, Func Offset: 0x18
	// Line 516, Address: 0x20928c, Func Offset: 0x1c
	// Line 517, Address: 0x209294, Func Offset: 0x24
	// Line 526, Address: 0x20929c, Func Offset: 0x2c
	// Line 516, Address: 0x2092a4, Func Offset: 0x34
	// Line 526, Address: 0x2092a8, Func Offset: 0x38
	// Line 516, Address: 0x2092ac, Func Offset: 0x3c
	// Line 526, Address: 0x2092b4, Func Offset: 0x44
	// Line 516, Address: 0x2092b8, Func Offset: 0x48
	// Line 517, Address: 0x2092bc, Func Offset: 0x4c
	// Line 526, Address: 0x2092c4, Func Offset: 0x54
	// Line 518, Address: 0x2092c8, Func Offset: 0x58
	// Line 526, Address: 0x2092cc, Func Offset: 0x5c
	// Line 522, Address: 0x2092d0, Func Offset: 0x60
	// Line 527, Address: 0x2092d4, Func Offset: 0x64
	// Line 517, Address: 0x2092d8, Func Offset: 0x68
	// Line 526, Address: 0x2092e0, Func Offset: 0x70
	// Line 517, Address: 0x2092e4, Func Offset: 0x74
	// Line 518, Address: 0x2092e8, Func Offset: 0x78
	// Line 529, Address: 0x2092f0, Func Offset: 0x80
	// Line 518, Address: 0x2092fc, Func Offset: 0x8c
	// Line 519, Address: 0x209308, Func Offset: 0x98
	// Line 520, Address: 0x20931c, Func Offset: 0xac
	// Line 521, Address: 0x209330, Func Offset: 0xc0
	// Line 522, Address: 0x209358, Func Offset: 0xe8
	// Line 523, Address: 0x20936c, Func Offset: 0xfc
	// Line 524, Address: 0x209380, Func Offset: 0x110
	// Line 526, Address: 0x209394, Func Offset: 0x124
	// Line 527, Address: 0x2093b4, Func Offset: 0x144
	// Line 528, Address: 0x2093c8, Func Offset: 0x158
	// Line 529, Address: 0x2093e4, Func Offset: 0x174
	// Line 531, Address: 0x2093fc, Func Offset: 0x18c
	// Line 532, Address: 0x209410, Func Offset: 0x1a0
	// Line 534, Address: 0x209414, Func Offset: 0x1a4
	// Line 531, Address: 0x20941c, Func Offset: 0x1ac
	// Line 534, Address: 0x209420, Func Offset: 0x1b0
	// Line 531, Address: 0x209424, Func Offset: 0x1b4
	// Line 532, Address: 0x209430, Func Offset: 0x1c0
	// Line 533, Address: 0x209444, Func Offset: 0x1d4
	// Line 534, Address: 0x209464, Func Offset: 0x1f4
	// Line 536, Address: 0x20947c, Func Offset: 0x20c
	// Line 537, Address: 0x209490, Func Offset: 0x220
	// Line 536, Address: 0x209494, Func Offset: 0x224
	// Line 539, Address: 0x209498, Func Offset: 0x228
	// Line 536, Address: 0x2094a4, Func Offset: 0x234
	// Line 537, Address: 0x2094b4, Func Offset: 0x244
	// Line 538, Address: 0x2094c8, Func Offset: 0x258
	// Line 539, Address: 0x2094e4, Func Offset: 0x274
	// Line 541, Address: 0x2094fc, Func Offset: 0x28c
	// Line 542, Address: 0x209510, Func Offset: 0x2a0
	// Line 544, Address: 0x209514, Func Offset: 0x2a4
	// Line 541, Address: 0x20951c, Func Offset: 0x2ac
	// Line 544, Address: 0x209520, Func Offset: 0x2b0
	// Line 541, Address: 0x209524, Func Offset: 0x2b4
	// Line 542, Address: 0x209530, Func Offset: 0x2c0
	// Line 543, Address: 0x209544, Func Offset: 0x2d4
	// Line 544, Address: 0x209564, Func Offset: 0x2f4
	// Line 545, Address: 0x20957c, Func Offset: 0x30c
	// Line 546, Address: 0x20958c, Func Offset: 0x31c
	// Func End, Address: 0x2095a4, Func Offset: 0x334
}

// 
// Start address: 0x2095b0
void bhEne25_PlayerControl(BH_PWORK* epw)
{
	_anon22 pos;
	// Line 557, Address: 0x2095b0, Func Offset: 0
	// Line 560, Address: 0x2095b8, Func Offset: 0x8
	// Line 562, Address: 0x2095d0, Func Offset: 0x20
	// Line 564, Address: 0x2095fc, Func Offset: 0x4c
	// Line 565, Address: 0x209608, Func Offset: 0x58
	// Line 569, Address: 0x209610, Func Offset: 0x60
	// Line 564, Address: 0x209614, Func Offset: 0x64
	// Line 565, Address: 0x20961c, Func Offset: 0x6c
	// Line 569, Address: 0x209624, Func Offset: 0x74
	// Line 572, Address: 0x209628, Func Offset: 0x78
	// Line 565, Address: 0x209630, Func Offset: 0x80
	// Line 566, Address: 0x209634, Func Offset: 0x84
	// Line 565, Address: 0x209638, Func Offset: 0x88
	// Line 566, Address: 0x209640, Func Offset: 0x90
	// Line 570, Address: 0x209648, Func Offset: 0x98
	// Line 566, Address: 0x20964c, Func Offset: 0x9c
	// Line 569, Address: 0x209654, Func Offset: 0xa4
	// Line 570, Address: 0x209658, Func Offset: 0xa8
	// Line 569, Address: 0x20965c, Func Offset: 0xac
	// Line 570, Address: 0x209664, Func Offset: 0xb4
	// Line 571, Address: 0x20966c, Func Offset: 0xbc
	// Line 572, Address: 0x209674, Func Offset: 0xc4
	// Line 574, Address: 0x209680, Func Offset: 0xd0
	// Line 576, Address: 0x209694, Func Offset: 0xe4
	// Line 577, Address: 0x2096a4, Func Offset: 0xf4
	// Line 583, Address: 0x2096b8, Func Offset: 0x108
	// Func End, Address: 0x2096c4, Func Offset: 0x114
}

