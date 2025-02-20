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

typedef void(*type_12)(BH_PWORK*);
typedef void(*type_40)(BH_PWORK*);
typedef void(*type_58)(BH_PWORK*);
typedef void(*type_72)(void*);

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
typedef char type_13[32];
typedef void(*type_14)(BH_PWORK*)[1];
typedef _anon0* type_15[512];
typedef _anon1* type_16[200];
typedef short type_17[32];
typedef _anon15 type_18[1];
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
typedef void(*type_41)(BH_PWORK*)[6];
typedef void* type_42[2];
typedef _anon1* type_43[256];
typedef int type_44[4];
typedef unsigned char* type_45[256];
typedef unsigned int type_46[2];
typedef short type_47[256];
typedef _anon22 type_48[4];
typedef float type_49[3];
typedef short type_50[256];
typedef int type_51[3];
typedef int type_52[8];
typedef float type_53[3];
typedef _anon1* type_54[256];
typedef _anon6 type_55[256];
typedef _anon15 type_56[450];
typedef _anon24 type_57[16];
typedef void(*type_59)(BH_PWORK*)[3];
typedef short type_60[256];
typedef char type_61[3];
typedef int type_62[64];
typedef _anon7 type_63[450];
typedef _anon28 type_64[4];
typedef _anon2 type_65[4];
typedef int type_66[450];
typedef unsigned int type_67[8];
typedef unsigned char type_68[450];
typedef _anon10 type_69[0];
typedef char type_70[16];
typedef char type_71[4];
typedef unsigned int type_73[32];
typedef unsigned int type_74[16];
typedef _anon11 type_75[64];
typedef unsigned int type_76[16];
typedef _anon11 type_77[64];
typedef unsigned int type_78[32];
typedef _anon0 type_79[0];
typedef _anon11 type_80[64];
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
typedef unsigned char type_98[4];
typedef _anon25 type_99[16];
typedef unsigned int type_100[32];
typedef _anon14 type_101[32];
typedef _anon0* type_102[512];
typedef _anon0* type_103[128];
typedef _anon0* type_104[512];
typedef unsigned char type_105[64];
typedef _anon0* type_106[512];

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
	_anon33 cspr;
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
	_anon15* textures;
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
	_anon34 watr;
	_anon16* cpcl;
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
	_anon20* owP;
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
	_anon31* info;
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
	_anon14 wp_fps1;
	_anon14 wp_fps2;
	_anon14 wp_cps;
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

struct _anon11
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
	float x;
	float y;
	float z;
};

struct _anon15
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon16
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon17
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

struct _anon18
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
	_anon14 ply_pos;
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
	_anon15 ef_tex[450];
	_anon1 ef_tlist;
	_anon29 ef;
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
	_anon12 ren_info;
	_anon15 ren_tex[1];
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
	_anon30 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon17* lgtp;
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
	_anon11* pl_htp;
	int costume;
	_anon14 hd_pos;
	_anon14 apos;
	_anon11* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon11 mwalp[64];
	_anon11 metcp[64];
	_anon11 mflrp[64];
	int dla_n;
	_anon11* htp;
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
	_anon14 ufo_pos;
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
	_anon14 ghtp[32];
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
	_anon14 pnt;
	_anon14 vctr;
	int stat;
	int reserve;
	_anon26 ltcal;
	_anon32 attr;
};

struct _anon22
{
	_anon14 ps;
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
	_anon14 center;
	float r;
};

struct _anon24
{
	float x;
	float y;
};

struct _anon25
{
	_anon14 c1;
	_anon14 c2;
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
	_anon14 lpnt;
	_anon14 lvctr;
	_anon14 lmvctr;
	_anon19 atten;
	_anon19 amb;
	_anon19 dif;
	_anon19 spc;
	_anon19 mamb;
	_anon19 mdif;
	_anon19 mspc;
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

struct _anon30
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon31
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

struct _anon32
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

struct _anon33
{
	_anon14 c;
	float r;
};

struct _anon34
{
	_anon14 c1;
	_anon14 c2;
	float r;
};

void(*bhEne16_Mode0)(BH_PWORK*)[6];
void(*bhEne16_BrainType)(BH_PWORK*)[1];
void(*bhEne16_MoveMode2)(BH_PWORK*)[3];
_anon0 eff[0];
_anon18* sys;
BH_PWORK* plp;
_anon10 WpnTab[0];

void bhEne16(BH_PWORK* epw);
void bhEne16_Init(BH_PWORK* epw);
void bhEne16_Brain(BH_PWORK* epw);
void bhEne16_BR00(BH_PWORK* epw);
void bhEne16_Move(BH_PWORK* epw);
void bhEne16_MV00(BH_PWORK* epw);
void bhEne16_MV01(BH_PWORK* epw);
void bhEne16_MV02(BH_PWORK* epw);
int bhEne16_GetEffNum(BH_PWORK* epw);
_anon14* bhEne16_GetEffPos(BH_PWORK* epw);
void bhEne16_AddEffPos(BH_PWORK* epw, _anon14* pos);

// 
// Start address: 0x1e9cc0
void bhEne16(BH_PWORK* epw)
{
	// Line 126, Address: 0x1e9cc0, Func Offset: 0
	// Line 128, Address: 0x1e9cd0, Func Offset: 0x10
	// Line 130, Address: 0x1e9cf0, Func Offset: 0x30
	// Line 132, Address: 0x1e9cfc, Func Offset: 0x3c
	// Line 136, Address: 0x1e9d10, Func Offset: 0x50
	// Line 137, Address: 0x1e9d20, Func Offset: 0x60
	// Line 142, Address: 0x1e9d28, Func Offset: 0x68
	// Line 143, Address: 0x1e9d34, Func Offset: 0x74
	// Func End, Address: 0x1e9d44, Func Offset: 0x84
}

// 
// Start address: 0x1e9d50
void bhEne16_Init(BH_PWORK* epw)
{
	int eff_id;
	// Line 153, Address: 0x1e9d50, Func Offset: 0
	// Line 157, Address: 0x1e9d5c, Func Offset: 0xc
	// Line 158, Address: 0x1e9d68, Func Offset: 0x18
	// Line 159, Address: 0x1e9d70, Func Offset: 0x20
	// Line 160, Address: 0x1e9d74, Func Offset: 0x24
	// Line 162, Address: 0x1e9d78, Func Offset: 0x28
	// Line 163, Address: 0x1e9d80, Func Offset: 0x30
	// Line 164, Address: 0x1e9d88, Func Offset: 0x38
	// Line 165, Address: 0x1e9d8c, Func Offset: 0x3c
	// Line 166, Address: 0x1e9d94, Func Offset: 0x44
	// Line 170, Address: 0x1e9d98, Func Offset: 0x48
	// Line 171, Address: 0x1e9da4, Func Offset: 0x54
	// Line 174, Address: 0x1e9db4, Func Offset: 0x64
	// Line 175, Address: 0x1e9dc0, Func Offset: 0x70
	// Line 186, Address: 0x1e9dc4, Func Offset: 0x74
	// Line 174, Address: 0x1e9dc8, Func Offset: 0x78
	// Line 175, Address: 0x1e9dd4, Func Offset: 0x84
	// Line 186, Address: 0x1e9ddc, Func Offset: 0x8c
	// Line 175, Address: 0x1e9de4, Func Offset: 0x94
	// Line 176, Address: 0x1e9df0, Func Offset: 0xa0
	// Line 177, Address: 0x1e9e04, Func Offset: 0xb4
	// Line 178, Address: 0x1e9e18, Func Offset: 0xc8
	// Line 179, Address: 0x1e9e2c, Func Offset: 0xdc
	// Line 180, Address: 0x1e9e40, Func Offset: 0xf0
	// Line 181, Address: 0x1e9e54, Func Offset: 0x104
	// Line 182, Address: 0x1e9e68, Func Offset: 0x118
	// Line 183, Address: 0x1e9e7c, Func Offset: 0x12c
	// Line 184, Address: 0x1e9e90, Func Offset: 0x140
	// Line 186, Address: 0x1e9ea4, Func Offset: 0x154
	// Line 187, Address: 0x1e9ebc, Func Offset: 0x16c
	// Line 188, Address: 0x1e9ec4, Func Offset: 0x174
	// Line 189, Address: 0x1e9eec, Func Offset: 0x19c
	// Line 191, Address: 0x1e9ef8, Func Offset: 0x1a8
	// Line 196, Address: 0x1e9f04, Func Offset: 0x1b4
	// Line 200, Address: 0x1e9f08, Func Offset: 0x1b8
	// Line 196, Address: 0x1e9f0c, Func Offset: 0x1bc
	// Line 198, Address: 0x1e9f14, Func Offset: 0x1c4
	// Line 200, Address: 0x1e9f20, Func Offset: 0x1d0
	// Line 201, Address: 0x1e9f24, Func Offset: 0x1d4
	// Func End, Address: 0x1e9f34, Func Offset: 0x1e4
}

// 
// Start address: 0x1e9f40
void bhEne16_Brain(BH_PWORK* epw)
{
	// Line 212, Address: 0x1e9f40, Func Offset: 0
	// Func End, Address: 0x1e9f50, Func Offset: 0x10
}

// 
// Start address: 0x1e9f50
void bhEne16_BR00(BH_PWORK* epw)
{
	_anon11* hp;
	// Line 223, Address: 0x1e9f50, Func Offset: 0
	// Line 227, Address: 0x1e9f5c, Func Offset: 0xc
	// Line 228, Address: 0x1e9f78, Func Offset: 0x28
	// Line 229, Address: 0x1e9f90, Func Offset: 0x40
	// Line 230, Address: 0x1e9f94, Func Offset: 0x44
	// Line 232, Address: 0x1e9f98, Func Offset: 0x48
	// Line 233, Address: 0x1e9fa0, Func Offset: 0x50
	// Line 236, Address: 0x1e9fa4, Func Offset: 0x54
	// Func End, Address: 0x1e9fb4, Func Offset: 0x64
}

// 
// Start address: 0x1e9fc0
void bhEne16_Move(BH_PWORK* epw)
{
	// Line 246, Address: 0x1e9fc0, Func Offset: 0
	// Line 248, Address: 0x1e9fcc, Func Offset: 0xc
	// Line 249, Address: 0x1e9fdc, Func Offset: 0x1c
	// Line 252, Address: 0x1e9fe4, Func Offset: 0x24
	// Line 253, Address: 0x1ea004, Func Offset: 0x44
	// Func End, Address: 0x1ea014, Func Offset: 0x54
}

// 
// Start address: 0x1ea020
void bhEne16_MV00(BH_PWORK* epw)
{
	// Line 264, Address: 0x1ea020, Func Offset: 0
	// Line 265, Address: 0x1ea030, Func Offset: 0x10
	// Line 267, Address: 0x1ea038, Func Offset: 0x18
	// Func End, Address: 0x1ea040, Func Offset: 0x20
}

// 
// Start address: 0x1ea040
void bhEne16_MV01(BH_PWORK* epw)
{
	// Line 278, Address: 0x1ea040, Func Offset: 0
	// Line 279, Address: 0x1ea050, Func Offset: 0x10
	// Line 281, Address: 0x1ea058, Func Offset: 0x18
	// Func End, Address: 0x1ea060, Func Offset: 0x20
}

// 
// Start address: 0x1ea060
void bhEne16_MV02(BH_PWORK* epw)
{
	_anon27 gap;
	_anon11* hp;
	_anon14 pos;
	_anon14 v;
	float spd_now;
	float spd;
	float mov;
	int ay;
	int ax;
	_anon20* owp;
	// Line 291, Address: 0x1ea060, Func Offset: 0
	// Line 298, Address: 0x1ea080, Func Offset: 0x20
	// Line 301, Address: 0x1ea0ac, Func Offset: 0x4c
	// Line 302, Address: 0x1ea0bc, Func Offset: 0x5c
	// Line 304, Address: 0x1ea0c4, Func Offset: 0x64
	// Line 305, Address: 0x1ea0cc, Func Offset: 0x6c
	// Line 308, Address: 0x1ea0d4, Func Offset: 0x74
	// Line 311, Address: 0x1ea0d8, Func Offset: 0x78
	// Line 308, Address: 0x1ea0e0, Func Offset: 0x80
	// Line 310, Address: 0x1ea0e4, Func Offset: 0x84
	// Line 308, Address: 0x1ea0e8, Func Offset: 0x88
	// Line 310, Address: 0x1ea0f0, Func Offset: 0x90
	// Line 311, Address: 0x1ea0fc, Func Offset: 0x9c
	// Line 312, Address: 0x1ea110, Func Offset: 0xb0
	// Line 313, Address: 0x1ea124, Func Offset: 0xc4
	// Line 314, Address: 0x1ea138, Func Offset: 0xd8
	// Line 315, Address: 0x1ea13c, Func Offset: 0xdc
	// Line 316, Address: 0x1ea140, Func Offset: 0xe0
	// Line 325, Address: 0x1ea144, Func Offset: 0xe4
	// Line 327, Address: 0x1ea14c, Func Offset: 0xec
	// Line 328, Address: 0x1ea154, Func Offset: 0xf4
	// Line 331, Address: 0x1ea15c, Func Offset: 0xfc
	// Line 333, Address: 0x1ea16c, Func Offset: 0x10c
	// Line 335, Address: 0x1ea174, Func Offset: 0x114
	// Line 338, Address: 0x1ea17c, Func Offset: 0x11c
	// Line 340, Address: 0x1ea184, Func Offset: 0x124
	// Line 342, Address: 0x1ea1bc, Func Offset: 0x15c
	// Line 343, Address: 0x1ea1c4, Func Offset: 0x164
	// Line 345, Address: 0x1ea1cc, Func Offset: 0x16c
	// Line 348, Address: 0x1ea1d4, Func Offset: 0x174
	// Line 349, Address: 0x1ea1e4, Func Offset: 0x184
	// Line 351, Address: 0x1ea1ec, Func Offset: 0x18c
	// Line 353, Address: 0x1ea1f4, Func Offset: 0x194
	// Line 354, Address: 0x1ea200, Func Offset: 0x1a0
	// Line 357, Address: 0x1ea208, Func Offset: 0x1a8
	// Line 359, Address: 0x1ea218, Func Offset: 0x1b8
	// Line 363, Address: 0x1ea24c, Func Offset: 0x1ec
	// Line 364, Address: 0x1ea254, Func Offset: 0x1f4
	// Line 366, Address: 0x1ea258, Func Offset: 0x1f8
	// Line 363, Address: 0x1ea260, Func Offset: 0x200
	// Line 364, Address: 0x1ea268, Func Offset: 0x208
	// Line 365, Address: 0x1ea278, Func Offset: 0x218
	// Line 364, Address: 0x1ea27c, Func Offset: 0x21c
	// Line 365, Address: 0x1ea280, Func Offset: 0x220
	// Line 366, Address: 0x1ea290, Func Offset: 0x230
	// Line 365, Address: 0x1ea294, Func Offset: 0x234
	// Line 366, Address: 0x1ea298, Func Offset: 0x238
	// Line 369, Address: 0x1ea2b0, Func Offset: 0x250
	// Line 370, Address: 0x1ea2dc, Func Offset: 0x27c
	// Line 371, Address: 0x1ea310, Func Offset: 0x2b0
	// Line 373, Address: 0x1ea318, Func Offset: 0x2b8
	// Line 374, Address: 0x1ea32c, Func Offset: 0x2cc
	// Line 375, Address: 0x1ea330, Func Offset: 0x2d0
	// Line 374, Address: 0x1ea338, Func Offset: 0x2d8
	// Line 375, Address: 0x1ea340, Func Offset: 0x2e0
	// Line 376, Address: 0x1ea348, Func Offset: 0x2e8
	// Line 377, Address: 0x1ea35c, Func Offset: 0x2fc
	// Line 376, Address: 0x1ea360, Func Offset: 0x300
	// Line 377, Address: 0x1ea364, Func Offset: 0x304
	// Line 378, Address: 0x1ea370, Func Offset: 0x310
	// Line 379, Address: 0x1ea378, Func Offset: 0x318
	// Line 383, Address: 0x1ea380, Func Offset: 0x320
	// Line 387, Address: 0x1ea388, Func Offset: 0x328
	// Line 390, Address: 0x1ea38c, Func Offset: 0x32c
	// Line 391, Address: 0x1ea3a4, Func Offset: 0x344
	// Line 398, Address: 0x1ea3ac, Func Offset: 0x34c
	// Line 393, Address: 0x1ea3b8, Func Offset: 0x358
	// Line 391, Address: 0x1ea3bc, Func Offset: 0x35c
	// Line 398, Address: 0x1ea3c0, Func Offset: 0x360
	// Line 391, Address: 0x1ea3cc, Func Offset: 0x36c
	// Line 392, Address: 0x1ea3d0, Func Offset: 0x370
	// Line 398, Address: 0x1ea3d8, Func Offset: 0x378
	// Line 392, Address: 0x1ea3dc, Func Offset: 0x37c
	// Line 393, Address: 0x1ea3e4, Func Offset: 0x384
	// Line 394, Address: 0x1ea3f4, Func Offset: 0x394
	// Line 398, Address: 0x1ea3f8, Func Offset: 0x398
	// Line 394, Address: 0x1ea3fc, Func Offset: 0x39c
	// Line 398, Address: 0x1ea400, Func Offset: 0x3a0
	// Line 394, Address: 0x1ea404, Func Offset: 0x3a4
	// Line 395, Address: 0x1ea40c, Func Offset: 0x3ac
	// Line 396, Address: 0x1ea41c, Func Offset: 0x3bc
	// Line 398, Address: 0x1ea428, Func Offset: 0x3c8
	// Line 400, Address: 0x1ea430, Func Offset: 0x3d0
	// Line 401, Address: 0x1ea438, Func Offset: 0x3d8
	// Line 402, Address: 0x1ea448, Func Offset: 0x3e8
	// Line 417, Address: 0x1ea458, Func Offset: 0x3f8
	// Line 426, Address: 0x1ea468, Func Offset: 0x408
	// Line 417, Address: 0x1ea470, Func Offset: 0x410
	// Line 418, Address: 0x1ea484, Func Offset: 0x424
	// Line 419, Address: 0x1ea4a0, Func Offset: 0x440
	// Line 422, Address: 0x1ea4bc, Func Offset: 0x45c
	// Line 423, Address: 0x1ea4c4, Func Offset: 0x464
	// Line 424, Address: 0x1ea4cc, Func Offset: 0x46c
	// Line 426, Address: 0x1ea4d4, Func Offset: 0x474
	// Line 428, Address: 0x1ea4e0, Func Offset: 0x480
	// Line 431, Address: 0x1ea4ec, Func Offset: 0x48c
	// Line 434, Address: 0x1ea4f4, Func Offset: 0x494
	// Line 435, Address: 0x1ea500, Func Offset: 0x4a0
	// Line 437, Address: 0x1ea510, Func Offset: 0x4b0
	// Line 438, Address: 0x1ea52c, Func Offset: 0x4cc
	// Line 439, Address: 0x1ea538, Func Offset: 0x4d8
	// Line 440, Address: 0x1ea540, Func Offset: 0x4e0
	// Line 442, Address: 0x1ea554, Func Offset: 0x4f4
	// Line 443, Address: 0x1ea578, Func Offset: 0x518
	// Line 444, Address: 0x1ea594, Func Offset: 0x534
	// Line 445, Address: 0x1ea5ac, Func Offset: 0x54c
	// Line 447, Address: 0x1ea5c0, Func Offset: 0x560
	// Line 453, Address: 0x1ea5d4, Func Offset: 0x574
	// Line 447, Address: 0x1ea5d8, Func Offset: 0x578
	// Line 448, Address: 0x1ea5e8, Func Offset: 0x588
	// Line 449, Address: 0x1ea604, Func Offset: 0x5a4
	// Line 453, Address: 0x1ea620, Func Offset: 0x5c0
	// Line 454, Address: 0x1ea628, Func Offset: 0x5c8
	// Line 455, Address: 0x1ea634, Func Offset: 0x5d4
	// Line 454, Address: 0x1ea638, Func Offset: 0x5d8
	// Line 455, Address: 0x1ea650, Func Offset: 0x5f0
	// Line 456, Address: 0x1ea658, Func Offset: 0x5f8
	// Line 457, Address: 0x1ea664, Func Offset: 0x604
	// Line 458, Address: 0x1ea670, Func Offset: 0x610
	// Line 459, Address: 0x1ea678, Func Offset: 0x618
	// Line 460, Address: 0x1ea680, Func Offset: 0x620
	// Line 462, Address: 0x1ea68c, Func Offset: 0x62c
	// Line 463, Address: 0x1ea694, Func Offset: 0x634
	// Line 462, Address: 0x1ea698, Func Offset: 0x638
	// Line 464, Address: 0x1ea6a0, Func Offset: 0x640
	// Line 466, Address: 0x1ea6a8, Func Offset: 0x648
	// Line 467, Address: 0x1ea6b8, Func Offset: 0x658
	// Line 469, Address: 0x1ea6c0, Func Offset: 0x660
	// Line 470, Address: 0x1ea6c8, Func Offset: 0x668
	// Line 473, Address: 0x1ea6d0, Func Offset: 0x670
	// Line 476, Address: 0x1ea6e4, Func Offset: 0x684
	// Line 478, Address: 0x1ea6ec, Func Offset: 0x68c
	// Line 479, Address: 0x1ea6fc, Func Offset: 0x69c
	// Line 480, Address: 0x1ea704, Func Offset: 0x6a4
	// Line 485, Address: 0x1ea708, Func Offset: 0x6a8
	// Line 488, Address: 0x1ea71c, Func Offset: 0x6bc
	// Line 489, Address: 0x1ea724, Func Offset: 0x6c4
	// Line 490, Address: 0x1ea730, Func Offset: 0x6d0
	// Line 488, Address: 0x1ea738, Func Offset: 0x6d8
	// Line 489, Address: 0x1ea73c, Func Offset: 0x6dc
	// Line 488, Address: 0x1ea740, Func Offset: 0x6e0
	// Line 489, Address: 0x1ea744, Func Offset: 0x6e4
	// Line 490, Address: 0x1ea758, Func Offset: 0x6f8
	// Line 491, Address: 0x1ea778, Func Offset: 0x718
	// Line 493, Address: 0x1ea794, Func Offset: 0x734
	// Line 496, Address: 0x1ea7b8, Func Offset: 0x758
	// Line 499, Address: 0x1ea7d4, Func Offset: 0x774
	// Line 500, Address: 0x1ea800, Func Offset: 0x7a0
	// Line 501, Address: 0x1ea820, Func Offset: 0x7c0
	// Line 504, Address: 0x1ea82c, Func Offset: 0x7cc
	// Line 507, Address: 0x1ea83c, Func Offset: 0x7dc
	// Line 508, Address: 0x1ea84c, Func Offset: 0x7ec
	// Line 509, Address: 0x1ea858, Func Offset: 0x7f8
	// Line 508, Address: 0x1ea85c, Func Offset: 0x7fc
	// Line 509, Address: 0x1ea868, Func Offset: 0x808
	// Line 510, Address: 0x1ea870, Func Offset: 0x810
	// Line 511, Address: 0x1ea87c, Func Offset: 0x81c
	// Line 512, Address: 0x1ea888, Func Offset: 0x828
	// Line 517, Address: 0x1ea894, Func Offset: 0x834
	// Line 518, Address: 0x1ea8b0, Func Offset: 0x850
	// Line 519, Address: 0x1ea8cc, Func Offset: 0x86c
	// Line 520, Address: 0x1ea8d8, Func Offset: 0x878
	// Line 525, Address: 0x1ea8e4, Func Offset: 0x884
	// Line 526, Address: 0x1ea93c, Func Offset: 0x8dc
	// Line 527, Address: 0x1ea994, Func Offset: 0x934
	// Line 530, Address: 0x1ea9f0, Func Offset: 0x990
	// Line 532, Address: 0x1ea9f8, Func Offset: 0x998
	// Line 531, Address: 0x1eaa00, Func Offset: 0x9a0
	// Line 530, Address: 0x1eaa08, Func Offset: 0x9a8
	// Line 532, Address: 0x1eaa0c, Func Offset: 0x9ac
	// Line 531, Address: 0x1eaa10, Func Offset: 0x9b0
	// Line 533, Address: 0x1eaa14, Func Offset: 0x9b4
	// Line 534, Address: 0x1eaa20, Func Offset: 0x9c0
	// Line 535, Address: 0x1eaa3c, Func Offset: 0x9dc
	// Line 536, Address: 0x1eaa48, Func Offset: 0x9e8
	// Line 537, Address: 0x1eaa54, Func Offset: 0x9f4
	// Func End, Address: 0x1eaa78, Func Offset: 0xa18
}

// 
// Start address: 0x1eaa80
int bhEne16_GetEffNum(BH_PWORK* epw)
{
	// Line 548, Address: 0x1eaa80, Func Offset: 0
	// Line 549, Address: 0x1eaa84, Func Offset: 0x4
	// Func End, Address: 0x1eaa8c, Func Offset: 0xc
}

// 
// Start address: 0x1eaa90
_anon14* bhEne16_GetEffPos(BH_PWORK* epw)
{
	// Line 560, Address: 0x1eaa90, Func Offset: 0
	// Line 561, Address: 0x1eaa94, Func Offset: 0x4
	// Func End, Address: 0x1eaa9c, Func Offset: 0xc
}

// 
// Start address: 0x1eaaa0
void bhEne16_AddEffPos(BH_PWORK* epw, _anon14* pos)
{
	int i;
	// Line 574, Address: 0x1eaaa0, Func Offset: 0
	// Line 575, Address: 0x1eaabc, Func Offset: 0x1c
	// Line 576, Address: 0x1eaac0, Func Offset: 0x20
	// Line 575, Address: 0x1eaac4, Func Offset: 0x24
	// Line 576, Address: 0x1eaae0, Func Offset: 0x40
	// Line 577, Address: 0x1eaae8, Func Offset: 0x48
	// Line 578, Address: 0x1eab04, Func Offset: 0x64
	// Line 579, Address: 0x1eab28, Func Offset: 0x88
	// Func End, Address: 0x1eab30, Func Offset: 0x90
}

