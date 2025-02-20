typedef struct npobj;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct BH_PWORK;
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

typedef void(*type_70)(void*);
typedef void(*type_98)();

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
typedef _anon4 type_19[256];
typedef _anon1* type_20[8];
typedef int* type_21[16];
typedef _anon0* type_22[128];
typedef npobj* type_23[16];
typedef _anon0* type_24[128];
typedef int type_25[4];
typedef _anon1* type_26[16];
typedef unsigned int type_27[4];
typedef _anon7 type_28[16];
typedef _anon0* type_29[512];
typedef char type_30[256];
typedef float type_31[4];
typedef float type_32[4];
typedef float type_33[4];
typedef _anon3* type_34[128];
typedef unsigned char type_35[64];
typedef float type_36[16];
typedef char type_37[8];
typedef void* type_38[2];
typedef unsigned char type_39[2];
typedef unsigned char type_40[2][32];
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
typedef _anon13 type_54[450];
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
typedef unsigned short type_65[7];
typedef char type_66[16];
typedef unsigned short type_67[7][3];
typedef unsigned short type_68[7][3][2];
typedef char type_69[4];
typedef unsigned int type_71[32];
typedef unsigned int type_72[16];
typedef _anon27 type_73[64];
typedef unsigned int type_74[16];
typedef char type_75[7];
typedef char type_76[7][2];
typedef char type_77[7][2][0];
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
typedef unsigned int type_89[4];
typedef int* type_90[16];
typedef char type_91[32];
typedef npobj* type_92[16];
typedef char type_93[64];
typedef _anon1* type_94[16];
typedef char type_95[4];
typedef _anon7 type_96[16];
typedef short type_97[4];
typedef void(*type_99)()[10];
typedef unsigned char type_100[4];
typedef _anon23 type_101[16];
typedef unsigned int type_102[32];
typedef _anon22 type_103[32];
typedef _anon0* type_104[512];
typedef _anon0* type_105[128];
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

unsigned char basic_motion_pl[2][32];
void(*bhCPM0_event_tbl)()[10];
BH_PWORK* plp;
unsigned short PlMtnAct[7][3][2];
char PlFootSnd[7][2][0];
_anon10* sys;

void bhCPM0_event();
void pl_smove00();
void pl_smove01();
void pl_smove02();
void pl_smove03();
void pl_smove04();
void pl_smove05();
void pl_smove06();
void pl_smove07();
void pl_smove08();

// 
// Start address: 0x171e50
void bhCPM0_event()
{
	// Line 148, Address: 0x171e50, Func Offset: 0
	// Func End, Address: 0x171e78, Func Offset: 0x28
}

// 
// Start address: 0x171e80
void pl_smove00()
{
	// Line 169, Address: 0x171e80, Func Offset: 0
	// Line 181, Address: 0x171eb4, Func Offset: 0x34
	// Line 183, Address: 0x171ebc, Func Offset: 0x3c
	// Line 182, Address: 0x171ec0, Func Offset: 0x40
	// Line 183, Address: 0x171ec4, Func Offset: 0x44
	// Line 181, Address: 0x171ec8, Func Offset: 0x48
	// Line 182, Address: 0x171ed0, Func Offset: 0x50
	// Line 184, Address: 0x171ed4, Func Offset: 0x54
	// Line 185, Address: 0x171ed8, Func Offset: 0x58
	// Line 186, Address: 0x171edc, Func Offset: 0x5c
	// Line 182, Address: 0x171ee0, Func Offset: 0x60
	// Line 183, Address: 0x171ee4, Func Offset: 0x64
	// Line 182, Address: 0x171ee8, Func Offset: 0x68
	// Line 183, Address: 0x171ef4, Func Offset: 0x74
	// Line 184, Address: 0x171efc, Func Offset: 0x7c
	// Line 183, Address: 0x171f00, Func Offset: 0x80
	// Line 184, Address: 0x171f38, Func Offset: 0xb8
	// Line 185, Address: 0x171f40, Func Offset: 0xc0
	// Line 186, Address: 0x171f4c, Func Offset: 0xcc
	// Line 187, Address: 0x171f58, Func Offset: 0xd8
	// Line 188, Address: 0x171f64, Func Offset: 0xe4
	// Line 189, Address: 0x171f70, Func Offset: 0xf0
	// Line 188, Address: 0x171f74, Func Offset: 0xf4
	// Line 189, Address: 0x171f78, Func Offset: 0xf8
	// Line 191, Address: 0x171f88, Func Offset: 0x108
	// Line 192, Address: 0x171fc8, Func Offset: 0x148
	// Line 193, Address: 0x171fd0, Func Offset: 0x150
	// Line 194, Address: 0x171fd8, Func Offset: 0x158
	// Line 192, Address: 0x171fdc, Func Offset: 0x15c
	// Line 197, Address: 0x171fe8, Func Offset: 0x168
	// Line 192, Address: 0x171fec, Func Offset: 0x16c
	// Line 195, Address: 0x172018, Func Offset: 0x198
	// Line 192, Address: 0x17201c, Func Offset: 0x19c
	// Line 193, Address: 0x172024, Func Offset: 0x1a4
	// Line 194, Address: 0x17202c, Func Offset: 0x1ac
	// Line 195, Address: 0x172038, Func Offset: 0x1b8
	// Line 196, Address: 0x172044, Func Offset: 0x1c4
	// Line 197, Address: 0x172050, Func Offset: 0x1d0
	// Line 204, Address: 0x17205c, Func Offset: 0x1dc
	// Func End, Address: 0x172064, Func Offset: 0x1e4
}

// 
// Start address: 0x172070
void pl_smove01()
{
	// Line 214, Address: 0x172070, Func Offset: 0
	// Line 217, Address: 0x17207c, Func Offset: 0xc
	// Line 219, Address: 0x1720b0, Func Offset: 0x40
	// Line 221, Address: 0x1720cc, Func Offset: 0x5c
	// Line 228, Address: 0x1720d8, Func Offset: 0x68
	// Line 221, Address: 0x1720e0, Func Offset: 0x70
	// Line 228, Address: 0x1720e4, Func Offset: 0x74
	// Line 221, Address: 0x1720e8, Func Offset: 0x78
	// Line 222, Address: 0x1720ec, Func Offset: 0x7c
	// Line 223, Address: 0x1720f4, Func Offset: 0x84
	// Line 221, Address: 0x1720f8, Func Offset: 0x88
	// Line 224, Address: 0x172124, Func Offset: 0xb4
	// Line 221, Address: 0x172128, Func Offset: 0xb8
	// Line 222, Address: 0x17212c, Func Offset: 0xbc
	// Line 223, Address: 0x172134, Func Offset: 0xc4
	// Line 224, Address: 0x172140, Func Offset: 0xd0
	// Line 225, Address: 0x17214c, Func Offset: 0xdc
	// Line 226, Address: 0x172158, Func Offset: 0xe8
	// Line 227, Address: 0x172164, Func Offset: 0xf4
	// Line 228, Address: 0x172170, Func Offset: 0x100
	// Line 227, Address: 0x172174, Func Offset: 0x104
	// Line 228, Address: 0x172178, Func Offset: 0x108
	// Line 229, Address: 0x172184, Func Offset: 0x114
	// Line 228, Address: 0x172188, Func Offset: 0x118
	// Line 229, Address: 0x172198, Func Offset: 0x128
	// Line 230, Address: 0x1721a4, Func Offset: 0x134
	// Line 229, Address: 0x1721a8, Func Offset: 0x138
	// Line 230, Address: 0x1721b8, Func Offset: 0x148
	// Line 232, Address: 0x1721c8, Func Offset: 0x158
	// Line 233, Address: 0x1721dc, Func Offset: 0x16c
	// Line 234, Address: 0x1721ec, Func Offset: 0x17c
	// Line 235, Address: 0x1721f4, Func Offset: 0x184
	// Line 236, Address: 0x172200, Func Offset: 0x190
	// Line 237, Address: 0x172208, Func Offset: 0x198
	// Line 236, Address: 0x17220c, Func Offset: 0x19c
	// Line 237, Address: 0x172218, Func Offset: 0x1a8
	// Line 241, Address: 0x17222c, Func Offset: 0x1bc
	// Line 243, Address: 0x172234, Func Offset: 0x1c4
	// Line 245, Address: 0x172250, Func Offset: 0x1e0
	// Line 246, Address: 0x17225c, Func Offset: 0x1ec
	// Line 245, Address: 0x172268, Func Offset: 0x1f8
	// Line 246, Address: 0x172270, Func Offset: 0x200
	// Line 247, Address: 0x172274, Func Offset: 0x204
	// Line 248, Address: 0x172278, Func Offset: 0x208
	// Line 249, Address: 0x17227c, Func Offset: 0x20c
	// Line 246, Address: 0x172280, Func Offset: 0x210
	// Line 247, Address: 0x172284, Func Offset: 0x214
	// Line 246, Address: 0x172288, Func Offset: 0x218
	// Line 247, Address: 0x1722c0, Func Offset: 0x250
	// Line 248, Address: 0x1722c8, Func Offset: 0x258
	// Line 249, Address: 0x1722d4, Func Offset: 0x264
	// Line 250, Address: 0x1722e0, Func Offset: 0x270
	// Line 251, Address: 0x1722ec, Func Offset: 0x27c
	// Line 252, Address: 0x1722f8, Func Offset: 0x288
	// Line 251, Address: 0x1722fc, Func Offset: 0x28c
	// Line 252, Address: 0x172300, Func Offset: 0x290
	// Line 256, Address: 0x172310, Func Offset: 0x2a0
	// Line 257, Address: 0x172348, Func Offset: 0x2d8
	// Line 258, Address: 0x172350, Func Offset: 0x2e0
	// Line 256, Address: 0x172354, Func Offset: 0x2e4
	// Line 257, Address: 0x17235c, Func Offset: 0x2ec
	// Line 258, Address: 0x172364, Func Offset: 0x2f4
	// Line 260, Address: 0x1723a4, Func Offset: 0x334
	// Line 261, Address: 0x1723b4, Func Offset: 0x344
	// Line 263, Address: 0x1723bc, Func Offset: 0x34c
	// Line 265, Address: 0x1723dc, Func Offset: 0x36c
	// Line 266, Address: 0x1723e8, Func Offset: 0x378
	// Line 265, Address: 0x1723f4, Func Offset: 0x384
	// Line 266, Address: 0x1723fc, Func Offset: 0x38c
	// Line 267, Address: 0x172400, Func Offset: 0x390
	// Line 268, Address: 0x172404, Func Offset: 0x394
	// Line 269, Address: 0x172408, Func Offset: 0x398
	// Line 266, Address: 0x17240c, Func Offset: 0x39c
	// Line 267, Address: 0x172410, Func Offset: 0x3a0
	// Line 266, Address: 0x172414, Func Offset: 0x3a4
	// Line 267, Address: 0x17244c, Func Offset: 0x3dc
	// Line 268, Address: 0x172454, Func Offset: 0x3e4
	// Line 269, Address: 0x172460, Func Offset: 0x3f0
	// Line 270, Address: 0x17246c, Func Offset: 0x3fc
	// Line 271, Address: 0x172478, Func Offset: 0x408
	// Line 272, Address: 0x172484, Func Offset: 0x414
	// Line 271, Address: 0x172488, Func Offset: 0x418
	// Line 272, Address: 0x17248c, Func Offset: 0x41c
	// Line 276, Address: 0x17249c, Func Offset: 0x42c
	// Line 277, Address: 0x1724d4, Func Offset: 0x464
	// Line 278, Address: 0x1724dc, Func Offset: 0x46c
	// Line 276, Address: 0x1724e0, Func Offset: 0x470
	// Line 277, Address: 0x1724e8, Func Offset: 0x478
	// Line 278, Address: 0x1724f0, Func Offset: 0x480
	// Line 280, Address: 0x172530, Func Offset: 0x4c0
	// Line 283, Address: 0x172540, Func Offset: 0x4d0
	// Line 284, Address: 0x17255c, Func Offset: 0x4ec
	// Func End, Address: 0x17256c, Func Offset: 0x4fc
}

// 
// Start address: 0x172570
void pl_smove02()
{
	int fsnd;
	// Line 294, Address: 0x172570, Func Offset: 0
	// Line 298, Address: 0x17257c, Func Offset: 0xc
	// Line 300, Address: 0x1725a4, Func Offset: 0x34
	// Line 301, Address: 0x1725b0, Func Offset: 0x40
	// Line 300, Address: 0x1725b8, Func Offset: 0x48
	// Line 301, Address: 0x1725c0, Func Offset: 0x50
	// Line 302, Address: 0x1725d4, Func Offset: 0x64
	// Line 303, Address: 0x1725d8, Func Offset: 0x68
	// Line 304, Address: 0x1725e0, Func Offset: 0x70
	// Line 308, Address: 0x172668, Func Offset: 0xf8
	// Line 310, Address: 0x172678, Func Offset: 0x108
	// Line 308, Address: 0x172680, Func Offset: 0x110
	// Line 309, Address: 0x172684, Func Offset: 0x114
	// Line 311, Address: 0x172688, Func Offset: 0x118
	// Line 312, Address: 0x17268c, Func Offset: 0x11c
	// Line 313, Address: 0x172690, Func Offset: 0x120
	// Line 308, Address: 0x172694, Func Offset: 0x124
	// Line 309, Address: 0x17269c, Func Offset: 0x12c
	// Line 314, Address: 0x1726a0, Func Offset: 0x130
	// Line 315, Address: 0x1726a4, Func Offset: 0x134
	// Line 309, Address: 0x1726a8, Func Offset: 0x138
	// Line 310, Address: 0x1726ac, Func Offset: 0x13c
	// Line 309, Address: 0x1726b0, Func Offset: 0x140
	// Line 310, Address: 0x1726bc, Func Offset: 0x14c
	// Line 311, Address: 0x1726c4, Func Offset: 0x154
	// Line 310, Address: 0x1726c8, Func Offset: 0x158
	// Line 311, Address: 0x172700, Func Offset: 0x190
	// Line 312, Address: 0x172708, Func Offset: 0x198
	// Line 313, Address: 0x172714, Func Offset: 0x1a4
	// Line 314, Address: 0x172720, Func Offset: 0x1b0
	// Line 315, Address: 0x17272c, Func Offset: 0x1bc
	// Line 314, Address: 0x172730, Func Offset: 0x1c0
	// Line 315, Address: 0x172734, Func Offset: 0x1c4
	// Line 316, Address: 0x172748, Func Offset: 0x1d8
	// Line 317, Address: 0x17275c, Func Offset: 0x1ec
	// Line 320, Address: 0x172770, Func Offset: 0x200
	// Line 327, Address: 0x1727e4, Func Offset: 0x274
	// Line 320, Address: 0x1727e8, Func Offset: 0x278
	// Line 327, Address: 0x1727ec, Func Offset: 0x27c
	// Line 328, Address: 0x172820, Func Offset: 0x2b0
	// Line 330, Address: 0x17284c, Func Offset: 0x2dc
	// Line 331, Address: 0x172880, Func Offset: 0x310
	// Line 333, Address: 0x172888, Func Offset: 0x318
	// Line 337, Address: 0x1728c0, Func Offset: 0x350
	// Line 338, Address: 0x172900, Func Offset: 0x390
	// Line 341, Address: 0x172918, Func Offset: 0x3a8
	// Line 342, Address: 0x172928, Func Offset: 0x3b8
	// Line 343, Address: 0x172930, Func Offset: 0x3c0
	// Line 342, Address: 0x172934, Func Offset: 0x3c4
	// Line 343, Address: 0x172938, Func Offset: 0x3c8
	// Line 342, Address: 0x17293c, Func Offset: 0x3cc
	// Line 343, Address: 0x172944, Func Offset: 0x3d4
	// Line 344, Address: 0x172958, Func Offset: 0x3e8
	// Line 345, Address: 0x17296c, Func Offset: 0x3fc
	// Line 349, Address: 0x172994, Func Offset: 0x424
	// Line 350, Address: 0x1729d4, Func Offset: 0x464
	// Line 353, Address: 0x1729ec, Func Offset: 0x47c
	// Line 354, Address: 0x1729fc, Func Offset: 0x48c
	// Line 355, Address: 0x172a04, Func Offset: 0x494
	// Line 354, Address: 0x172a08, Func Offset: 0x498
	// Line 355, Address: 0x172a0c, Func Offset: 0x49c
	// Line 354, Address: 0x172a10, Func Offset: 0x4a0
	// Line 355, Address: 0x172a18, Func Offset: 0x4a8
	// Line 356, Address: 0x172a2c, Func Offset: 0x4bc
	// Line 357, Address: 0x172a40, Func Offset: 0x4d0
	// Line 362, Address: 0x172a68, Func Offset: 0x4f8
	// Line 364, Address: 0x172a78, Func Offset: 0x508
	// Func End, Address: 0x172a88, Func Offset: 0x518
}

// 
// Start address: 0x172a90
void pl_smove03()
{
	int fsnd;
	// Line 374, Address: 0x172a90, Func Offset: 0
	// Line 377, Address: 0x172a9c, Func Offset: 0xc
	// Line 379, Address: 0x172ac4, Func Offset: 0x34
	// Line 381, Address: 0x172ad0, Func Offset: 0x40
	// Line 379, Address: 0x172ad8, Func Offset: 0x48
	// Line 380, Address: 0x172ae0, Func Offset: 0x50
	// Line 381, Address: 0x172aec, Func Offset: 0x5c
	// Line 380, Address: 0x172af0, Func Offset: 0x60
	// Line 381, Address: 0x172afc, Func Offset: 0x6c
	// Line 384, Address: 0x172b7c, Func Offset: 0xec
	// Line 385, Address: 0x172b84, Func Offset: 0xf4
	// Line 386, Address: 0x172b88, Func Offset: 0xf8
	// Line 381, Address: 0x172b8c, Func Offset: 0xfc
	// Line 384, Address: 0x172b90, Func Offset: 0x100
	// Line 387, Address: 0x172b98, Func Offset: 0x108
	// Line 388, Address: 0x172b9c, Func Offset: 0x10c
	// Line 384, Address: 0x172ba0, Func Offset: 0x110
	// Line 385, Address: 0x172ba4, Func Offset: 0x114
	// Line 384, Address: 0x172ba8, Func Offset: 0x118
	// Line 385, Address: 0x172be0, Func Offset: 0x150
	// Line 386, Address: 0x172be8, Func Offset: 0x158
	// Line 387, Address: 0x172bf4, Func Offset: 0x164
	// Line 388, Address: 0x172c00, Func Offset: 0x170
	// Line 389, Address: 0x172c0c, Func Offset: 0x17c
	// Line 388, Address: 0x172c10, Func Offset: 0x180
	// Line 389, Address: 0x172c14, Func Offset: 0x184
	// Line 391, Address: 0x172c24, Func Offset: 0x194
	// Line 393, Address: 0x172c98, Func Offset: 0x208
	// Line 391, Address: 0x172c9c, Func Offset: 0x20c
	// Line 393, Address: 0x172ca0, Func Offset: 0x210
	// Line 394, Address: 0x172cd4, Func Offset: 0x244
	// Line 395, Address: 0x172d0c, Func Offset: 0x27c
	// Line 397, Address: 0x172d38, Func Offset: 0x2a8
	// Line 398, Address: 0x172d6c, Func Offset: 0x2dc
	// Line 400, Address: 0x172d74, Func Offset: 0x2e4
	// Line 404, Address: 0x172dac, Func Offset: 0x31c
	// Line 405, Address: 0x172dec, Func Offset: 0x35c
	// Line 408, Address: 0x172e04, Func Offset: 0x374
	// Line 409, Address: 0x172e14, Func Offset: 0x384
	// Line 410, Address: 0x172e1c, Func Offset: 0x38c
	// Line 409, Address: 0x172e20, Func Offset: 0x390
	// Line 410, Address: 0x172e24, Func Offset: 0x394
	// Line 409, Address: 0x172e28, Func Offset: 0x398
	// Line 410, Address: 0x172e30, Func Offset: 0x3a0
	// Line 411, Address: 0x172e44, Func Offset: 0x3b4
	// Line 412, Address: 0x172e58, Func Offset: 0x3c8
	// Line 416, Address: 0x172e80, Func Offset: 0x3f0
	// Line 417, Address: 0x172ec0, Func Offset: 0x430
	// Line 420, Address: 0x172ed8, Func Offset: 0x448
	// Line 421, Address: 0x172ee8, Func Offset: 0x458
	// Line 422, Address: 0x172ef0, Func Offset: 0x460
	// Line 421, Address: 0x172ef4, Func Offset: 0x464
	// Line 422, Address: 0x172ef8, Func Offset: 0x468
	// Line 421, Address: 0x172efc, Func Offset: 0x46c
	// Line 422, Address: 0x172f04, Func Offset: 0x474
	// Line 423, Address: 0x172f18, Func Offset: 0x488
	// Line 424, Address: 0x172f2c, Func Offset: 0x49c
	// Line 429, Address: 0x172f54, Func Offset: 0x4c4
	// Line 430, Address: 0x172f64, Func Offset: 0x4d4
	// Func End, Address: 0x172f74, Func Offset: 0x4e4
}

// 
// Start address: 0x172f80
void pl_smove04()
{
	int fsnd;
	// Line 441, Address: 0x172f80, Func Offset: 0
	// Line 445, Address: 0x172f8c, Func Offset: 0xc
	// Line 447, Address: 0x172fb4, Func Offset: 0x34
	// Line 448, Address: 0x172fc0, Func Offset: 0x40
	// Line 447, Address: 0x172fc4, Func Offset: 0x44
	// Line 448, Address: 0x172fcc, Func Offset: 0x4c
	// Line 449, Address: 0x172fd4, Func Offset: 0x54
	// Line 448, Address: 0x172fd8, Func Offset: 0x58
	// Line 449, Address: 0x172fe4, Func Offset: 0x64
	// Line 451, Address: 0x17301c, Func Offset: 0x9c
	// Line 452, Address: 0x173020, Func Offset: 0xa0
	// Line 453, Address: 0x173028, Func Offset: 0xa8
	// Line 457, Address: 0x1730b8, Func Offset: 0x138
	// Line 458, Address: 0x1730c8, Func Offset: 0x148
	// Line 457, Address: 0x1730d0, Func Offset: 0x150
	// Line 458, Address: 0x1730d4, Func Offset: 0x154
	// Line 459, Address: 0x1730d8, Func Offset: 0x158
	// Line 460, Address: 0x1730dc, Func Offset: 0x15c
	// Line 461, Address: 0x1730e0, Func Offset: 0x160
	// Line 457, Address: 0x1730e4, Func Offset: 0x164
	// Line 458, Address: 0x1730ec, Func Offset: 0x16c
	// Line 463, Address: 0x1730f0, Func Offset: 0x170
	// Line 464, Address: 0x1730f4, Func Offset: 0x174
	// Line 458, Address: 0x1730f8, Func Offset: 0x178
	// Line 459, Address: 0x1730fc, Func Offset: 0x17c
	// Line 458, Address: 0x173100, Func Offset: 0x180
	// Line 459, Address: 0x173138, Func Offset: 0x1b8
	// Line 460, Address: 0x173140, Func Offset: 0x1c0
	// Line 461, Address: 0x17314c, Func Offset: 0x1cc
	// Line 462, Address: 0x173158, Func Offset: 0x1d8
	// Line 463, Address: 0x173164, Func Offset: 0x1e4
	// Line 464, Address: 0x173170, Func Offset: 0x1f0
	// Line 463, Address: 0x173174, Func Offset: 0x1f4
	// Line 464, Address: 0x173178, Func Offset: 0x1f8
	// Line 465, Address: 0x17318c, Func Offset: 0x20c
	// Line 466, Address: 0x1731a0, Func Offset: 0x220
	// Line 484, Address: 0x1731b4, Func Offset: 0x234
	// Line 490, Address: 0x173228, Func Offset: 0x2a8
	// Line 484, Address: 0x17322c, Func Offset: 0x2ac
	// Line 490, Address: 0x173230, Func Offset: 0x2b0
	// Line 492, Address: 0x173264, Func Offset: 0x2e4
	// Line 494, Address: 0x173290, Func Offset: 0x310
	// Line 495, Address: 0x1732c4, Func Offset: 0x344
	// Line 497, Address: 0x1732cc, Func Offset: 0x34c
	// Line 501, Address: 0x173304, Func Offset: 0x384
	// Line 502, Address: 0x173344, Func Offset: 0x3c4
	// Line 505, Address: 0x17335c, Func Offset: 0x3dc
	// Line 506, Address: 0x17336c, Func Offset: 0x3ec
	// Line 507, Address: 0x173374, Func Offset: 0x3f4
	// Line 506, Address: 0x173378, Func Offset: 0x3f8
	// Line 507, Address: 0x17337c, Func Offset: 0x3fc
	// Line 506, Address: 0x173380, Func Offset: 0x400
	// Line 507, Address: 0x173388, Func Offset: 0x408
	// Line 508, Address: 0x17339c, Func Offset: 0x41c
	// Line 509, Address: 0x1733b0, Func Offset: 0x430
	// Line 513, Address: 0x1733d8, Func Offset: 0x458
	// Line 514, Address: 0x173418, Func Offset: 0x498
	// Line 517, Address: 0x173430, Func Offset: 0x4b0
	// Line 518, Address: 0x173440, Func Offset: 0x4c0
	// Line 519, Address: 0x173448, Func Offset: 0x4c8
	// Line 518, Address: 0x17344c, Func Offset: 0x4cc
	// Line 519, Address: 0x173450, Func Offset: 0x4d0
	// Line 518, Address: 0x173454, Func Offset: 0x4d4
	// Line 519, Address: 0x17345c, Func Offset: 0x4dc
	// Line 520, Address: 0x173470, Func Offset: 0x4f0
	// Line 521, Address: 0x173484, Func Offset: 0x504
	// Line 526, Address: 0x1734ac, Func Offset: 0x52c
	// Line 527, Address: 0x1734bc, Func Offset: 0x53c
	// Func End, Address: 0x1734cc, Func Offset: 0x54c
}

// 
// Start address: 0x1734d0
void pl_smove05()
{
	// Line 540, Address: 0x1734d0, Func Offset: 0
	// Line 542, Address: 0x17351c, Func Offset: 0x4c
	// Line 543, Address: 0x173524, Func Offset: 0x54
	// Line 544, Address: 0x17352c, Func Offset: 0x5c
	// Line 542, Address: 0x173530, Func Offset: 0x60
	// Line 543, Address: 0x173538, Func Offset: 0x68
	// Line 545, Address: 0x17353c, Func Offset: 0x6c
	// Line 543, Address: 0x173540, Func Offset: 0x70
	// Line 544, Address: 0x173544, Func Offset: 0x74
	// Line 545, Address: 0x173550, Func Offset: 0x80
	// Line 548, Address: 0x17355c, Func Offset: 0x8c
	// Line 550, Address: 0x173588, Func Offset: 0xb8
	// Line 552, Address: 0x173590, Func Offset: 0xc0
	// Line 554, Address: 0x173598, Func Offset: 0xc8
	// Line 561, Address: 0x17359c, Func Offset: 0xcc
	// Line 562, Address: 0x1735bc, Func Offset: 0xec
	// Line 565, Address: 0x1735c4, Func Offset: 0xf4
	// Line 566, Address: 0x1735f8, Func Offset: 0x128
	// Line 567, Address: 0x173600, Func Offset: 0x130
	// Line 568, Address: 0x173608, Func Offset: 0x138
	// Line 567, Address: 0x17360c, Func Offset: 0x13c
	// Line 568, Address: 0x173610, Func Offset: 0x140
	// Line 570, Address: 0x17361c, Func Offset: 0x14c
	// Line 572, Address: 0x173624, Func Offset: 0x154
	// Line 577, Address: 0x17362c, Func Offset: 0x15c
	// Line 578, Address: 0x173648, Func Offset: 0x178
	// Line 579, Address: 0x173650, Func Offset: 0x180
	// Line 580, Address: 0x173658, Func Offset: 0x188
	// Line 579, Address: 0x17365c, Func Offset: 0x18c
	// Line 580, Address: 0x173660, Func Offset: 0x190
	// Line 582, Address: 0x17366c, Func Offset: 0x19c
	// Line 584, Address: 0x173680, Func Offset: 0x1b0
	// Line 588, Address: 0x173688, Func Offset: 0x1b8
	// Line 589, Address: 0x17368c, Func Offset: 0x1bc
	// Line 588, Address: 0x173690, Func Offset: 0x1c0
	// Line 589, Address: 0x173698, Func Offset: 0x1c8
	// Line 633, Address: 0x1736ac, Func Offset: 0x1dc
	// Func End, Address: 0x1736b4, Func Offset: 0x1e4
}

// 
// Start address: 0x1736c0
void pl_smove06()
{
	int fsnd;
	// Line 644, Address: 0x1736c0, Func Offset: 0
	// Line 649, Address: 0x1736c8, Func Offset: 0x8
	// Line 651, Address: 0x1736f0, Func Offset: 0x30
	// Line 652, Address: 0x1736f8, Func Offset: 0x38
	// Line 651, Address: 0x173704, Func Offset: 0x44
	// Line 652, Address: 0x17370c, Func Offset: 0x4c
	// Line 653, Address: 0x173710, Func Offset: 0x50
	// Line 652, Address: 0x173718, Func Offset: 0x58
	// Line 653, Address: 0x17371c, Func Offset: 0x5c
	// Line 652, Address: 0x173720, Func Offset: 0x60
	// Line 653, Address: 0x173728, Func Offset: 0x68
	// Line 656, Address: 0x1737a8, Func Offset: 0xe8
	// Line 658, Address: 0x1737b0, Func Offset: 0xf0
	// Line 653, Address: 0x1737b8, Func Offset: 0xf8
	// Line 656, Address: 0x1737bc, Func Offset: 0xfc
	// Line 659, Address: 0x1737c4, Func Offset: 0x104
	// Line 660, Address: 0x1737c8, Func Offset: 0x108
	// Line 661, Address: 0x1737cc, Func Offset: 0x10c
	// Line 663, Address: 0x1737d0, Func Offset: 0x110
	// Line 656, Address: 0x1737d4, Func Offset: 0x114
	// Line 658, Address: 0x1737d8, Func Offset: 0x118
	// Line 656, Address: 0x1737dc, Func Offset: 0x11c
	// Line 658, Address: 0x1737e4, Func Offset: 0x124
	// Line 659, Address: 0x1737f0, Func Offset: 0x130
	// Line 658, Address: 0x1737f4, Func Offset: 0x134
	// Line 659, Address: 0x173828, Func Offset: 0x168
	// Line 660, Address: 0x173830, Func Offset: 0x170
	// Line 661, Address: 0x17383c, Func Offset: 0x17c
	// Line 662, Address: 0x173848, Func Offset: 0x188
	// Line 663, Address: 0x173854, Func Offset: 0x194
	// Line 662, Address: 0x173858, Func Offset: 0x198
	// Line 663, Address: 0x173860, Func Offset: 0x1a0
	// Line 665, Address: 0x173870, Func Offset: 0x1b0
	// Line 672, Address: 0x1738e4, Func Offset: 0x224
	// Line 665, Address: 0x1738f8, Func Offset: 0x238
	// Line 672, Address: 0x1738fc, Func Offset: 0x23c
	// Line 688, Address: 0x17393c, Func Offset: 0x27c
	// Line 672, Address: 0x173940, Func Offset: 0x280
	// Line 688, Address: 0x173944, Func Offset: 0x284
	// Line 672, Address: 0x173948, Func Offset: 0x288
	// Line 688, Address: 0x173950, Func Offset: 0x290
	// Line 689, Address: 0x173964, Func Offset: 0x2a4
	// Line 692, Address: 0x17397c, Func Offset: 0x2bc
	// Line 695, Address: 0x17398c, Func Offset: 0x2cc
	// Line 696, Address: 0x1739a8, Func Offset: 0x2e8
	// Line 699, Address: 0x1739c0, Func Offset: 0x300
	// Line 703, Address: 0x1739d0, Func Offset: 0x310
	// Line 705, Address: 0x1739e0, Func Offset: 0x320
	// Func End, Address: 0x1739ec, Func Offset: 0x32c
}

// 
// Start address: 0x1739f0
void pl_smove07()
{
	int fsnd;
	// Line 715, Address: 0x1739f0, Func Offset: 0
	// Line 720, Address: 0x1739f8, Func Offset: 0x8
	// Line 722, Address: 0x173a20, Func Offset: 0x30
	// Line 723, Address: 0x173a2c, Func Offset: 0x3c
	// Line 722, Address: 0x173a34, Func Offset: 0x44
	// Line 723, Address: 0x173a3c, Func Offset: 0x4c
	// Line 726, Address: 0x173ac0, Func Offset: 0xd0
	// Line 727, Address: 0x173ac8, Func Offset: 0xd8
	// Line 728, Address: 0x173acc, Func Offset: 0xdc
	// Line 723, Address: 0x173ad0, Func Offset: 0xe0
	// Line 726, Address: 0x173ad4, Func Offset: 0xe4
	// Line 729, Address: 0x173adc, Func Offset: 0xec
	// Line 726, Address: 0x173ae0, Func Offset: 0xf0
	// Line 727, Address: 0x173ae8, Func Offset: 0xf8
	// Line 726, Address: 0x173aec, Func Offset: 0xfc
	// Line 727, Address: 0x173b20, Func Offset: 0x130
	// Line 728, Address: 0x173b28, Func Offset: 0x138
	// Line 729, Address: 0x173b34, Func Offset: 0x144
	// Line 730, Address: 0x173b40, Func Offset: 0x150
	// Line 732, Address: 0x173b54, Func Offset: 0x164
	// Line 739, Address: 0x173bc8, Func Offset: 0x1d8
	// Line 732, Address: 0x173bdc, Func Offset: 0x1ec
	// Line 739, Address: 0x173be0, Func Offset: 0x1f0
	// Line 755, Address: 0x173c20, Func Offset: 0x230
	// Line 739, Address: 0x173c24, Func Offset: 0x234
	// Line 755, Address: 0x173c28, Func Offset: 0x238
	// Line 739, Address: 0x173c2c, Func Offset: 0x23c
	// Line 755, Address: 0x173c34, Func Offset: 0x244
	// Line 756, Address: 0x173c48, Func Offset: 0x258
	// Line 759, Address: 0x173c60, Func Offset: 0x270
	// Line 762, Address: 0x173c70, Func Offset: 0x280
	// Line 763, Address: 0x173c88, Func Offset: 0x298
	// Line 766, Address: 0x173ca0, Func Offset: 0x2b0
	// Line 770, Address: 0x173cb0, Func Offset: 0x2c0
	// Line 771, Address: 0x173cc0, Func Offset: 0x2d0
	// Func End, Address: 0x173ccc, Func Offset: 0x2dc
}

// 
// Start address: 0x173cd0
void pl_smove08()
{
	// Line 783, Address: 0x173cd0, Func Offset: 0
	// Line 785, Address: 0x173d1c, Func Offset: 0x4c
	// Line 786, Address: 0x173d24, Func Offset: 0x54
	// Line 785, Address: 0x173d2c, Func Offset: 0x5c
	// Line 786, Address: 0x173d34, Func Offset: 0x64
	// Line 791, Address: 0x173d3c, Func Offset: 0x6c
	// Line 793, Address: 0x173d68, Func Offset: 0x98
	// Line 795, Address: 0x173d70, Func Offset: 0xa0
	// Line 797, Address: 0x173d78, Func Offset: 0xa8
	// Line 806, Address: 0x173d7c, Func Offset: 0xac
	// Line 807, Address: 0x173d84, Func Offset: 0xb4
	// Line 806, Address: 0x173d88, Func Offset: 0xb8
	// Line 807, Address: 0x173d8c, Func Offset: 0xbc
	// Line 806, Address: 0x173d90, Func Offset: 0xc0
	// Line 807, Address: 0x173d94, Func Offset: 0xc4
	// Line 808, Address: 0x173da4, Func Offset: 0xd4
	// Line 810, Address: 0x173de4, Func Offset: 0x114
	// Line 813, Address: 0x173dec, Func Offset: 0x11c
	// Line 814, Address: 0x173e20, Func Offset: 0x150
	// Line 815, Address: 0x173e28, Func Offset: 0x158
	// Line 818, Address: 0x173e34, Func Offset: 0x164
	// Line 820, Address: 0x173e3c, Func Offset: 0x16c
	// Line 825, Address: 0x173e44, Func Offset: 0x174
	// Line 826, Address: 0x173e60, Func Offset: 0x190
	// Line 827, Address: 0x173e68, Func Offset: 0x198
	// Line 830, Address: 0x173e74, Func Offset: 0x1a4
	// Line 832, Address: 0x173e88, Func Offset: 0x1b8
	// Line 836, Address: 0x173e90, Func Offset: 0x1c0
	// Line 837, Address: 0x173e94, Func Offset: 0x1c4
	// Line 836, Address: 0x173e98, Func Offset: 0x1c8
	// Line 837, Address: 0x173ea0, Func Offset: 0x1d0
	// Line 881, Address: 0x173eb4, Func Offset: 0x1e4
	// Func End, Address: 0x173ebc, Func Offset: 0x1ec
}

