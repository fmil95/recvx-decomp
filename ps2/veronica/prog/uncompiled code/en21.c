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
typedef struct _anon34;

typedef void(*type_26)(BH_PWORK*);
typedef void(*type_34)(BH_PWORK*);
typedef void(*type_42)(BH_PWORK*);
typedef void(*type_49)(BH_PWORK*);
typedef void(*type_76)(BH_PWORK*);
typedef void(*type_81)(BH_PWORK*);
typedef void(*type_84)(void*);

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
typedef char type_15[4];
typedef short type_16[32];
typedef _anon14 type_17[1];
typedef _anon0* type_18[128];
typedef unsigned int type_19[1];
typedef _anon5 type_20[256];
typedef _anon1* type_21[8];
typedef int* type_22[16];
typedef _anon0* type_23[128];
typedef npobj* type_24[16];
typedef _anon0* type_25[128];
typedef int type_27[4];
typedef void(*type_28)(BH_PWORK*)[1];
typedef _anon1* type_29[16];
typedef unsigned int type_30[4];
typedef _anon9 type_31[16];
typedef _anon0* type_32[512];
typedef char type_33[4];
typedef void(*type_35)(BH_PWORK*)[1];
typedef char type_36[256];
typedef float type_37[4];
typedef float type_38[4];
typedef float type_39[4];
typedef _anon4* type_40[128];
typedef unsigned char type_41[64];
typedef float type_43[16];
typedef void(*type_44)(BH_PWORK*)[1];
typedef char type_45[8];
typedef void* type_46[2];
typedef float type_47[19];
typedef _anon1* type_48[256];
typedef int type_50[4];
typedef unsigned char* type_51[256];
typedef void(*type_52)(BH_PWORK*)[6];
typedef unsigned int type_53[2];
typedef short type_54[256];
typedef _anon20 type_55[4];
typedef float type_56[3];
typedef short type_57[256];
typedef int type_58[3];
typedef int type_59[8];
typedef float type_60[3];
typedef _anon1* type_61[256];
typedef _anon8 type_62[256];
typedef _anon14 type_63[450];
typedef _anon22 type_64[16];
typedef short type_65[256];
typedef char type_66[3];
typedef int type_67[64];
typedef _anon9 type_68[450];
typedef _anon3* type_69[4];
typedef char type_70[2];
typedef _anon26 type_71[4];
typedef _anon2 type_72[4];
typedef int type_73[450];
typedef unsigned int type_74[8];
typedef unsigned char type_75[450];
typedef void(*type_77)(BH_PWORK*)[9];
typedef BH_PWORK type_78[0];
typedef char type_79[16];
typedef _anon0 type_80[0];
typedef void(*type_82)(BH_PWORK*)[1];
typedef char type_83[4];
typedef unsigned char type_85[15];
typedef unsigned int type_86[32];
typedef unsigned int type_87[16];
typedef _anon28 type_88[64];
typedef unsigned int type_89[16];
typedef _anon28 type_90[64];
typedef unsigned int type_91[32];
typedef _anon28 type_92[64];
typedef unsigned int type_93[16];
typedef unsigned int type_94[3];
typedef BH_PWORK* type_95[16];
typedef unsigned int type_96[8];
typedef unsigned int type_97[1];
typedef unsigned int type_98[384];
typedef unsigned int type_99[2];
typedef _anon3 type_100[12];
typedef unsigned char type_101[2];
typedef unsigned int type_102[4];
typedef int* type_103[16];
typedef char type_104[32];
typedef npobj* type_105[16];
typedef char type_106[64];
typedef _anon1* type_107[16];
typedef char type_108[4];
typedef _anon9 type_109[16];
typedef short type_110[4];
typedef float type_111[5];
typedef unsigned char type_112[4];
typedef _anon24 type_113[16];
typedef int type_114[5];
typedef unsigned int type_115[32];
typedef _anon23 type_116[32];
typedef _anon0* type_117[512];
typedef _anon15 type_118[9];
typedef _anon0* type_119[128];
typedef _anon0* type_120[512];
typedef unsigned char type_121[64];
typedef _anon0* type_122[512];

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
	_anon9 mdl[16];
	_anon9* mlwP;
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
	_anon32 cspr;
	int pn;
	_anon26* pvp;
	_anon2* tvp;
	_anon26 pv[4];
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
	_anon14* textures;
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
	_anon9 mdl[16];
	_anon9* mlwP;
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
	_anon34 watr;
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
	int u;
	int v;
	int sx;
	int sy;
};

struct _anon4
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon13* md2P;
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
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
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
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon6* owP;
};

struct _anon10
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

struct _anon11
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

struct _anon12
{
	void* texaddr;
	_anon7 texsurface;
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
	_anon10* p1per;
	_anon10* p2per;
	_anon10* kbper;
	_anon10* msper;
	_anon10 ms_per;
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
	_anon14 ef_tex[450];
	_anon1 ef_tlist;
	_anon27 ef;
	short efid[256];
	_anon9 efm[450];
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
	_anon29 mr_pl;
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
	_anon28* pl_htp;
	int costume;
	_anon23 hd_pos;
	_anon23 apos;
	_anon28* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon28 mwalp[64];
	_anon28 metcp[64];
	_anon28 mflrp[64];
	int dla_n;
	_anon28* htp;
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
	_anon11 door;
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
	_anon24 gatc[16];
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

struct _anon18
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon19
{
	float mtrx[16];
	_anon23 pnt;
	_anon23 vctr;
	int stat;
	int reserve;
	_anon25 ltcal;
	_anon31 attr;
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
	_anon23 c1;
	_anon23 c2;
	float r1;
	float r2;
};

struct _anon25
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
	_anon18 atten;
	_anon18 amb;
	_anon18 dif;
	_anon18 spc;
	_anon18 mamb;
	_anon18 mdif;
	_anon18 mspc;
};

struct _anon26
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon27
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

struct _anon28
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
	_anon18 argb;
};

struct _anon32
{
	_anon23 c;
	float r;
};

struct _anon33
{
	_anon23 off_pos;
	int srd_dir;
	float srd_pos;
	float bld_spd;
	float srt_spd[5];
	int srt_dir[5];
};

struct _anon34
{
	_anon23 c1;
	_anon23 c2;
	float r;
};

_anon33 BloodParam;
char En21SdwTab[2];
_anon15 CapColTab[9];
float En21SpdAddTbl[19];
unsigned char En21SparkTbl[15];
void(*bhEne21_Mode0)(BH_PWORK*)[6];
void(*bhEne21_BrainType)(BH_PWORK*)[1];
void(*bhEne21_MoveMode2)(BH_PWORK*)[9];
void(*bhEne21_NageMode2)(BH_PWORK*)[1];
void(*bhEne21_DamageMode2)(BH_PWORK*)[1];
void(*bhEne21_DieMode2)(BH_PWORK*)[1];
_anon17* sys;
BH_PWORK* plp;
BH_PWORK ene[0];
_anon0 eff[0];

void bhEne21(BH_PWORK* epw);
void bhEne21_Init(BH_PWORK* epw);
void bhEne21_SearchPlayer(BH_PWORK* epw);
void bhEne21_Brain(BH_PWORK* epw);
void bhEne21_BR00(BH_PWORK* epw);
void bhEne21_Move(BH_PWORK* epw);
void bhEne21_MV00(BH_PWORK* epw);
void bhEne21_MV01(BH_PWORK* epw);
void bhEne21_MV02(BH_PWORK* epw);
void bhEne21_MV03(BH_PWORK* epw);
void bhEne21_MV04(BH_PWORK* epw);
void bhEne21_MV05(BH_PWORK* epw);
void bhEne21_MV06(BH_PWORK* epw);
void bhEne21_MV07();
void bhEne21_MV08(BH_PWORK* epw);
void bhEne21_Nage(BH_PWORK* epw);
void bhEne21_NG00(BH_PWORK* epw);
void bhEne21_Damage(BH_PWORK* epw);
void bhEne21_Die(BH_PWORK* epw);
void bhEne21_DD00(BH_PWORK* epw);
void bhEne21_PlayerControl(BH_PWORK* epw);
unsigned char bhEne21_AllWayWallCheck(BH_PWORK* epw, float dist);
void bhEne21_SetSparkEff(BH_PWORK* epw, int num, int flg, unsigned int ofy);
void bhEff_E21_Spark(_anon0* op);
void bhEne21_SetMarkEff(BH_PWORK* epw);
void bhEff_E21_Mark(_anon0* op);

// 
// Start address: 0x1f7e20
void bhEne21(BH_PWORK* epw)
{
	int i;
	_anon6* owk;
	// Line 264, Address: 0x1f7e20, Func Offset: 0
	// Line 269, Address: 0x1f7e30, Func Offset: 0x10
	// Line 272, Address: 0x1f7e50, Func Offset: 0x30
	// Line 276, Address: 0x1f7e64, Func Offset: 0x44
	// Line 277, Address: 0x1f7e84, Func Offset: 0x64
	// Line 278, Address: 0x1f7ea8, Func Offset: 0x88
	// Line 282, Address: 0x1f7eb0, Func Offset: 0x90
	// Line 283, Address: 0x1f7ec0, Func Offset: 0xa0
	// Line 284, Address: 0x1f7ec8, Func Offset: 0xa8
	// Line 285, Address: 0x1f7ee4, Func Offset: 0xc4
	// Line 289, Address: 0x1f7ef4, Func Offset: 0xd4
	// Line 290, Address: 0x1f7f14, Func Offset: 0xf4
	// Line 292, Address: 0x1f7f20, Func Offset: 0x100
	// Line 293, Address: 0x1f7f28, Func Offset: 0x108
	// Line 295, Address: 0x1f7f38, Func Offset: 0x118
	// Line 297, Address: 0x1f7f40, Func Offset: 0x120
	// Line 301, Address: 0x1f7f4c, Func Offset: 0x12c
	// Line 304, Address: 0x1f7f58, Func Offset: 0x138
	// Line 305, Address: 0x1f7f68, Func Offset: 0x148
	// Line 315, Address: 0x1f7f6c, Func Offset: 0x14c
	// Line 305, Address: 0x1f7f74, Func Offset: 0x154
	// Line 306, Address: 0x1f7f78, Func Offset: 0x158
	// Line 307, Address: 0x1f7f80, Func Offset: 0x160
	// Line 308, Address: 0x1f7f88, Func Offset: 0x168
	// Line 310, Address: 0x1f7f90, Func Offset: 0x170
	// Line 311, Address: 0x1f7f98, Func Offset: 0x178
	// Line 312, Address: 0x1f7fa0, Func Offset: 0x180
	// Line 313, Address: 0x1f7fa8, Func Offset: 0x188
	// Line 315, Address: 0x1f7fb0, Func Offset: 0x190
	// Line 318, Address: 0x1f7fb4, Func Offset: 0x194
	// Line 319, Address: 0x1f7fc8, Func Offset: 0x1a8
	// Line 322, Address: 0x1f7fd0, Func Offset: 0x1b0
	// Line 323, Address: 0x1f7fe4, Func Offset: 0x1c4
	// Line 324, Address: 0x1f7ff0, Func Offset: 0x1d0
	// Func End, Address: 0x1f8000, Func Offset: 0x1e0
}

// 
// Start address: 0x1f8000
void bhEne21_Init(BH_PWORK* epw)
{
	// Line 335, Address: 0x1f8000, Func Offset: 0
	// Line 339, Address: 0x1f800c, Func Offset: 0xc
	// Line 340, Address: 0x1f8018, Func Offset: 0x18
	// Line 343, Address: 0x1f8028, Func Offset: 0x28
	// Line 344, Address: 0x1f8038, Func Offset: 0x38
	// Line 345, Address: 0x1f803c, Func Offset: 0x3c
	// Line 351, Address: 0x1f8040, Func Offset: 0x40
	// Line 352, Address: 0x1f8044, Func Offset: 0x44
	// Line 344, Address: 0x1f8048, Func Offset: 0x48
	// Line 345, Address: 0x1f8050, Func Offset: 0x50
	// Line 361, Address: 0x1f8054, Func Offset: 0x54
	// Line 358, Address: 0x1f805c, Func Offset: 0x5c
	// Line 368, Address: 0x1f8060, Func Offset: 0x60
	// Line 345, Address: 0x1f8064, Func Offset: 0x64
	// Line 350, Address: 0x1f806c, Func Offset: 0x6c
	// Line 372, Address: 0x1f8070, Func Offset: 0x70
	// Line 350, Address: 0x1f8074, Func Offset: 0x74
	// Line 351, Address: 0x1f807c, Func Offset: 0x7c
	// Line 352, Address: 0x1f8088, Func Offset: 0x88
	// Line 354, Address: 0x1f8094, Func Offset: 0x94
	// Line 355, Address: 0x1f8098, Func Offset: 0x98
	// Line 356, Address: 0x1f809c, Func Offset: 0x9c
	// Line 357, Address: 0x1f80a0, Func Offset: 0xa0
	// Line 358, Address: 0x1f80a4, Func Offset: 0xa4
	// Line 360, Address: 0x1f80a8, Func Offset: 0xa8
	// Line 361, Address: 0x1f80b0, Func Offset: 0xb0
	// Line 362, Address: 0x1f80b8, Func Offset: 0xb8
	// Line 363, Address: 0x1f80c0, Func Offset: 0xc0
	// Line 364, Address: 0x1f80c8, Func Offset: 0xc8
	// Line 365, Address: 0x1f80d0, Func Offset: 0xd0
	// Line 367, Address: 0x1f80d8, Func Offset: 0xd8
	// Line 368, Address: 0x1f80e0, Func Offset: 0xe0
	// Line 369, Address: 0x1f80e8, Func Offset: 0xe8
	// Line 372, Address: 0x1f80f0, Func Offset: 0xf0
	// Line 373, Address: 0x1f80f4, Func Offset: 0xf4
	// Line 374, Address: 0x1f80f8, Func Offset: 0xf8
	// Line 375, Address: 0x1f80fc, Func Offset: 0xfc
	// Line 376, Address: 0x1f8100, Func Offset: 0x100
	// Line 377, Address: 0x1f8104, Func Offset: 0x104
	// Line 380, Address: 0x1f8108, Func Offset: 0x108
	// Line 381, Address: 0x1f810c, Func Offset: 0x10c
	// Line 382, Address: 0x1f8110, Func Offset: 0x110
	// Line 384, Address: 0x1f8114, Func Offset: 0x114
	// Line 386, Address: 0x1f811c, Func Offset: 0x11c
	// Line 393, Address: 0x1f8120, Func Offset: 0x120
	// Line 392, Address: 0x1f8128, Func Offset: 0x128
	// Line 396, Address: 0x1f812c, Func Offset: 0x12c
	// Line 386, Address: 0x1f8130, Func Offset: 0x130
	// Line 391, Address: 0x1f8138, Func Offset: 0x138
	// Line 400, Address: 0x1f813c, Func Offset: 0x13c
	// Line 397, Address: 0x1f8144, Func Offset: 0x144
	// Line 401, Address: 0x1f8148, Func Offset: 0x148
	// Line 403, Address: 0x1f814c, Func Offset: 0x14c
	// Line 391, Address: 0x1f8150, Func Offset: 0x150
	// Line 392, Address: 0x1f8158, Func Offset: 0x158
	// Line 393, Address: 0x1f8164, Func Offset: 0x164
	// Line 396, Address: 0x1f8170, Func Offset: 0x170
	// Line 397, Address: 0x1f8174, Func Offset: 0x174
	// Line 398, Address: 0x1f8178, Func Offset: 0x178
	// Line 399, Address: 0x1f817c, Func Offset: 0x17c
	// Line 400, Address: 0x1f8180, Func Offset: 0x180
	// Line 401, Address: 0x1f8184, Func Offset: 0x184
	// Line 402, Address: 0x1f8188, Func Offset: 0x188
	// Line 403, Address: 0x1f818c, Func Offset: 0x18c
	// Line 404, Address: 0x1f819c, Func Offset: 0x19c
	// Line 406, Address: 0x1f81a8, Func Offset: 0x1a8
	// Line 408, Address: 0x1f81b0, Func Offset: 0x1b0
	// Line 409, Address: 0x1f81b4, Func Offset: 0x1b4
	// Line 416, Address: 0x1f81bc, Func Offset: 0x1bc
	// Line 423, Address: 0x1f81c0, Func Offset: 0x1c0
	// Line 408, Address: 0x1f81c4, Func Offset: 0x1c4
	// Line 409, Address: 0x1f81c8, Func Offset: 0x1c8
	// Line 410, Address: 0x1f81d0, Func Offset: 0x1d0
	// Line 411, Address: 0x1f81d8, Func Offset: 0x1d8
	// Line 412, Address: 0x1f81e0, Func Offset: 0x1e0
	// Line 413, Address: 0x1f81e8, Func Offset: 0x1e8
	// Line 415, Address: 0x1f81f0, Func Offset: 0x1f0
	// Line 416, Address: 0x1f81f8, Func Offset: 0x1f8
	// Line 417, Address: 0x1f8200, Func Offset: 0x200
	// Line 420, Address: 0x1f8208, Func Offset: 0x208
	// Line 424, Address: 0x1f820c, Func Offset: 0x20c
	// Line 426, Address: 0x1f821c, Func Offset: 0x21c
	// Line 431, Address: 0x1f8220, Func Offset: 0x220
	// Line 441, Address: 0x1f8224, Func Offset: 0x224
	// Line 424, Address: 0x1f8228, Func Offset: 0x228
	// Line 437, Address: 0x1f822c, Func Offset: 0x22c
	// Line 424, Address: 0x1f8234, Func Offset: 0x234
	// Line 425, Address: 0x1f8238, Func Offset: 0x238
	// Line 426, Address: 0x1f823c, Func Offset: 0x23c
	// Line 427, Address: 0x1f8240, Func Offset: 0x240
	// Line 428, Address: 0x1f8244, Func Offset: 0x244
	// Line 431, Address: 0x1f8248, Func Offset: 0x248
	// Line 432, Address: 0x1f824c, Func Offset: 0x24c
	// Line 433, Address: 0x1f8250, Func Offset: 0x250
	// Line 434, Address: 0x1f8254, Func Offset: 0x254
	// Line 437, Address: 0x1f8258, Func Offset: 0x258
	// Line 440, Address: 0x1f825c, Func Offset: 0x25c
	// Line 441, Address: 0x1f8260, Func Offset: 0x260
	// Line 442, Address: 0x1f8264, Func Offset: 0x264
	// Line 445, Address: 0x1f8274, Func Offset: 0x274
	// Line 446, Address: 0x1f8284, Func Offset: 0x284
	// Line 447, Address: 0x1f82b0, Func Offset: 0x2b0
	// Line 450, Address: 0x1f82bc, Func Offset: 0x2bc
	// Func End, Address: 0x1f82cc, Func Offset: 0x2cc
}

// 
// Start address: 0x1f82d0
void bhEne21_SearchPlayer(BH_PWORK* epw)
{
	float dz;
	float dx;
	int ang;
	// Line 460, Address: 0x1f82d0, Func Offset: 0
	// Line 465, Address: 0x1f82e4, Func Offset: 0x14
	// Line 466, Address: 0x1f82f0, Func Offset: 0x20
	// Line 465, Address: 0x1f82f8, Func Offset: 0x28
	// Line 466, Address: 0x1f82fc, Func Offset: 0x2c
	// Line 465, Address: 0x1f8300, Func Offset: 0x30
	// Line 466, Address: 0x1f8304, Func Offset: 0x34
	// Line 467, Address: 0x1f8308, Func Offset: 0x38
	// Line 468, Address: 0x1f8318, Func Offset: 0x48
	// Line 473, Address: 0x1f831c, Func Offset: 0x4c
	// Line 467, Address: 0x1f8324, Func Offset: 0x54
	// Line 468, Address: 0x1f8328, Func Offset: 0x58
	// Line 469, Address: 0x1f8334, Func Offset: 0x64
	// Line 468, Address: 0x1f8338, Func Offset: 0x68
	// Line 469, Address: 0x1f833c, Func Offset: 0x6c
	// Line 470, Address: 0x1f8348, Func Offset: 0x78
	// Line 469, Address: 0x1f834c, Func Offset: 0x7c
	// Line 470, Address: 0x1f8350, Func Offset: 0x80
	// Line 473, Address: 0x1f835c, Func Offset: 0x8c
	// Line 474, Address: 0x1f8378, Func Offset: 0xa8
	// Line 475, Address: 0x1f837c, Func Offset: 0xac
	// Line 474, Address: 0x1f8380, Func Offset: 0xb0
	// Line 475, Address: 0x1f838c, Func Offset: 0xbc
	// Line 477, Address: 0x1f8390, Func Offset: 0xc0
	// Line 478, Address: 0x1f83a8, Func Offset: 0xd8
	// Line 479, Address: 0x1f83b0, Func Offset: 0xe0
	// Line 480, Address: 0x1f83b8, Func Offset: 0xe8
	// Line 482, Address: 0x1f83c0, Func Offset: 0xf0
	// Func End, Address: 0x1f83d8, Func Offset: 0x108
}

// 
// Start address: 0x1f83e0
void bhEne21_Brain(BH_PWORK* epw)
{
	// Line 494, Address: 0x1f83e0, Func Offset: 0
	// Func End, Address: 0x1f83e8, Func Offset: 0x8
}

// 
// Start address: 0x1f83f0
void bhEne21_BR00(BH_PWORK* epw)
{
	// Line 505, Address: 0x1f83f0, Func Offset: 0
	// Line 509, Address: 0x1f83fc, Func Offset: 0xc
	// Line 513, Address: 0x1f8440, Func Offset: 0x50
	// Line 516, Address: 0x1f8448, Func Offset: 0x58
	// Line 518, Address: 0x1f8450, Func Offset: 0x60
	// Line 521, Address: 0x1f846c, Func Offset: 0x7c
	// Line 523, Address: 0x1f848c, Func Offset: 0x9c
	// Line 525, Address: 0x1f84a0, Func Offset: 0xb0
	// Line 526, Address: 0x1f84a8, Func Offset: 0xb8
	// Line 527, Address: 0x1f84ac, Func Offset: 0xbc
	// Line 531, Address: 0x1f84b0, Func Offset: 0xc0
	// Line 533, Address: 0x1f84bc, Func Offset: 0xcc
	// Line 535, Address: 0x1f84c4, Func Offset: 0xd4
	// Line 537, Address: 0x1f84d4, Func Offset: 0xe4
	// Line 538, Address: 0x1f84dc, Func Offset: 0xec
	// Line 539, Address: 0x1f84e0, Func Offset: 0xf0
	// Line 541, Address: 0x1f84e8, Func Offset: 0xf8
	// Line 543, Address: 0x1f84f0, Func Offset: 0x100
	// Line 544, Address: 0x1f84f4, Func Offset: 0x104
	// Line 545, Address: 0x1f84f8, Func Offset: 0x108
	// Line 546, Address: 0x1f8500, Func Offset: 0x110
	// Line 553, Address: 0x1f8504, Func Offset: 0x114
	// Func End, Address: 0x1f8514, Func Offset: 0x124
}

// 
// Start address: 0x1f8520
void bhEne21_Move(BH_PWORK* epw)
{
	// Line 564, Address: 0x1f8520, Func Offset: 0
	// Line 566, Address: 0x1f852c, Func Offset: 0xc
	// Line 567, Address: 0x1f853c, Func Offset: 0x1c
	// Line 570, Address: 0x1f8544, Func Offset: 0x24
	// Line 571, Address: 0x1f8560, Func Offset: 0x40
	// Line 574, Address: 0x1f8568, Func Offset: 0x48
	// Line 575, Address: 0x1f8578, Func Offset: 0x58
	// Line 576, Address: 0x1f8598, Func Offset: 0x78
	// Func End, Address: 0x1f85a8, Func Offset: 0x88
}

// 
// Start address: 0x1f85b0
void bhEne21_MV00(BH_PWORK* epw)
{
	// Line 586, Address: 0x1f85b0, Func Offset: 0
	// Line 589, Address: 0x1f85c0, Func Offset: 0x10
	// Line 592, Address: 0x1f85e0, Func Offset: 0x30
	// Line 594, Address: 0x1f85f0, Func Offset: 0x40
	// Line 595, Address: 0x1f860c, Func Offset: 0x5c
	// Line 594, Address: 0x1f8610, Func Offset: 0x60
	// Line 596, Address: 0x1f8614, Func Offset: 0x64
	// Line 595, Address: 0x1f8618, Func Offset: 0x68
	// Line 596, Address: 0x1f861c, Func Offset: 0x6c
	// Line 600, Address: 0x1f8620, Func Offset: 0x70
	// Line 601, Address: 0x1f863c, Func Offset: 0x8c
	// Line 600, Address: 0x1f8644, Func Offset: 0x94
	// Line 601, Address: 0x1f864c, Func Offset: 0x9c
	// Line 603, Address: 0x1f8650, Func Offset: 0xa0
	// Line 606, Address: 0x1f865c, Func Offset: 0xac
	// Line 608, Address: 0x1f8668, Func Offset: 0xb8
	// Line 609, Address: 0x1f8678, Func Offset: 0xc8
	// Line 611, Address: 0x1f8690, Func Offset: 0xe0
	// Line 614, Address: 0x1f86a4, Func Offset: 0xf4
	// Line 615, Address: 0x1f86b4, Func Offset: 0x104
	// Line 616, Address: 0x1f86bc, Func Offset: 0x10c
	// Line 617, Address: 0x1f86c0, Func Offset: 0x110
	// Line 618, Address: 0x1f86c4, Func Offset: 0x114
	// Line 622, Address: 0x1f86c8, Func Offset: 0x118
	// Func End, Address: 0x1f86d8, Func Offset: 0x128
}

// 
// Start address: 0x1f86e0
void bhEne21_MV01(BH_PWORK* epw)
{
	unsigned int rnd;
	_anon23 pos;
	// Line 632, Address: 0x1f86e0, Func Offset: 0
	// Line 638, Address: 0x1f86f0, Func Offset: 0x10
	// Line 641, Address: 0x1f8710, Func Offset: 0x30
	// Line 643, Address: 0x1f8720, Func Offset: 0x40
	// Line 644, Address: 0x1f873c, Func Offset: 0x5c
	// Line 643, Address: 0x1f8740, Func Offset: 0x60
	// Line 645, Address: 0x1f8744, Func Offset: 0x64
	// Line 644, Address: 0x1f8748, Func Offset: 0x68
	// Line 645, Address: 0x1f874c, Func Offset: 0x6c
	// Line 649, Address: 0x1f8750, Func Offset: 0x70
	// Line 650, Address: 0x1f876c, Func Offset: 0x8c
	// Line 649, Address: 0x1f8770, Func Offset: 0x90
	// Line 650, Address: 0x1f8778, Func Offset: 0x98
	// Line 652, Address: 0x1f877c, Func Offset: 0x9c
	// Line 655, Address: 0x1f8788, Func Offset: 0xa8
	// Line 656, Address: 0x1f8790, Func Offset: 0xb0
	// Line 657, Address: 0x1f87a0, Func Offset: 0xc0
	// Line 656, Address: 0x1f87a8, Func Offset: 0xc8
	// Line 657, Address: 0x1f87bc, Func Offset: 0xdc
	// Line 659, Address: 0x1f87c4, Func Offset: 0xe4
	// Line 660, Address: 0x1f87d4, Func Offset: 0xf4
	// Line 662, Address: 0x1f87e8, Func Offset: 0x108
	// Line 663, Address: 0x1f880c, Func Offset: 0x12c
	// Line 665, Address: 0x1f8814, Func Offset: 0x134
	// Line 667, Address: 0x1f8824, Func Offset: 0x144
	// Line 669, Address: 0x1f884c, Func Offset: 0x16c
	// Line 670, Address: 0x1f8858, Func Offset: 0x178
	// Line 671, Address: 0x1f8860, Func Offset: 0x180
	// Line 673, Address: 0x1f8868, Func Offset: 0x188
	// Line 674, Address: 0x1f8878, Func Offset: 0x198
	// Line 673, Address: 0x1f887c, Func Offset: 0x19c
	// Line 674, Address: 0x1f8880, Func Offset: 0x1a0
	// Line 676, Address: 0x1f8890, Func Offset: 0x1b0
	// Line 677, Address: 0x1f88b0, Func Offset: 0x1d0
	// Line 678, Address: 0x1f88b8, Func Offset: 0x1d8
	// Line 680, Address: 0x1f88c0, Func Offset: 0x1e0
	// Line 682, Address: 0x1f88f4, Func Offset: 0x214
	// Line 685, Address: 0x1f88fc, Func Offset: 0x21c
	// Line 686, Address: 0x1f890c, Func Offset: 0x22c
	// Line 688, Address: 0x1f8914, Func Offset: 0x234
	// Line 689, Address: 0x1f8930, Func Offset: 0x250
	// Line 690, Address: 0x1f8938, Func Offset: 0x258
	// Line 691, Address: 0x1f8940, Func Offset: 0x260
	// Line 692, Address: 0x1f894c, Func Offset: 0x26c
	// Line 693, Address: 0x1f8958, Func Offset: 0x278
	// Line 694, Address: 0x1f8964, Func Offset: 0x284
	// Line 696, Address: 0x1f896c, Func Offset: 0x28c
	// Line 697, Address: 0x1f8970, Func Offset: 0x290
	// Line 700, Address: 0x1f8974, Func Offset: 0x294
	// Func End, Address: 0x1f8984, Func Offset: 0x2a4
}

// 
// Start address: 0x1f8990
void bhEne21_MV02(BH_PWORK* epw)
{
	// Line 710, Address: 0x1f8990, Func Offset: 0
	// Line 711, Address: 0x1f89a0, Func Offset: 0x10
	// Line 713, Address: 0x1f89c0, Func Offset: 0x30
	// Line 716, Address: 0x1f89d0, Func Offset: 0x40
	// Line 717, Address: 0x1f89ec, Func Offset: 0x5c
	// Line 716, Address: 0x1f89f0, Func Offset: 0x60
	// Line 718, Address: 0x1f89f4, Func Offset: 0x64
	// Line 717, Address: 0x1f89f8, Func Offset: 0x68
	// Line 718, Address: 0x1f89fc, Func Offset: 0x6c
	// Line 720, Address: 0x1f8a00, Func Offset: 0x70
	// Line 721, Address: 0x1f8a1c, Func Offset: 0x8c
	// Line 720, Address: 0x1f8a20, Func Offset: 0x90
	// Line 721, Address: 0x1f8a28, Func Offset: 0x98
	// Line 722, Address: 0x1f8a2c, Func Offset: 0x9c
	// Line 725, Address: 0x1f8a38, Func Offset: 0xa8
	// Line 727, Address: 0x1f8a3c, Func Offset: 0xac
	// Line 726, Address: 0x1f8a40, Func Offset: 0xb0
	// Line 727, Address: 0x1f8a44, Func Offset: 0xb4
	// Line 728, Address: 0x1f8a48, Func Offset: 0xb8
	// Line 725, Address: 0x1f8a4c, Func Offset: 0xbc
	// Line 726, Address: 0x1f8a54, Func Offset: 0xc4
	// Line 727, Address: 0x1f8a58, Func Offset: 0xc8
	// Line 728, Address: 0x1f8a60, Func Offset: 0xd0
	// Line 727, Address: 0x1f8a64, Func Offset: 0xd4
	// Line 728, Address: 0x1f8a78, Func Offset: 0xe8
	// Line 730, Address: 0x1f8a80, Func Offset: 0xf0
	// Line 731, Address: 0x1f8a90, Func Offset: 0x100
	// Line 734, Address: 0x1f8aa4, Func Offset: 0x114
	// Line 735, Address: 0x1f8ac8, Func Offset: 0x138
	// Line 737, Address: 0x1f8ad0, Func Offset: 0x140
	// Line 738, Address: 0x1f8ae0, Func Offset: 0x150
	// Line 739, Address: 0x1f8ae8, Func Offset: 0x158
	// Line 740, Address: 0x1f8aec, Func Offset: 0x15c
	// Line 741, Address: 0x1f8af0, Func Offset: 0x160
	// Line 745, Address: 0x1f8af4, Func Offset: 0x164
	// Func End, Address: 0x1f8b04, Func Offset: 0x174
}

// 
// Start address: 0x1f8b10
void bhEne21_MV03(BH_PWORK* epw)
{
	// Line 755, Address: 0x1f8b10, Func Offset: 0
	// Line 756, Address: 0x1f8b20, Func Offset: 0x10
	// Line 758, Address: 0x1f8b40, Func Offset: 0x30
	// Line 761, Address: 0x1f8b50, Func Offset: 0x40
	// Line 762, Address: 0x1f8b6c, Func Offset: 0x5c
	// Line 761, Address: 0x1f8b70, Func Offset: 0x60
	// Line 763, Address: 0x1f8b74, Func Offset: 0x64
	// Line 762, Address: 0x1f8b78, Func Offset: 0x68
	// Line 763, Address: 0x1f8b7c, Func Offset: 0x6c
	// Line 765, Address: 0x1f8b80, Func Offset: 0x70
	// Line 766, Address: 0x1f8b9c, Func Offset: 0x8c
	// Line 765, Address: 0x1f8ba0, Func Offset: 0x90
	// Line 766, Address: 0x1f8ba8, Func Offset: 0x98
	// Line 767, Address: 0x1f8bac, Func Offset: 0x9c
	// Line 770, Address: 0x1f8bb8, Func Offset: 0xa8
	// Line 772, Address: 0x1f8bbc, Func Offset: 0xac
	// Line 771, Address: 0x1f8bc0, Func Offset: 0xb0
	// Line 772, Address: 0x1f8bc4, Func Offset: 0xb4
	// Line 773, Address: 0x1f8bc8, Func Offset: 0xb8
	// Line 770, Address: 0x1f8bcc, Func Offset: 0xbc
	// Line 771, Address: 0x1f8bd4, Func Offset: 0xc4
	// Line 772, Address: 0x1f8bd8, Func Offset: 0xc8
	// Line 773, Address: 0x1f8be0, Func Offset: 0xd0
	// Line 772, Address: 0x1f8be4, Func Offset: 0xd4
	// Line 773, Address: 0x1f8bf8, Func Offset: 0xe8
	// Line 775, Address: 0x1f8c00, Func Offset: 0xf0
	// Line 776, Address: 0x1f8c10, Func Offset: 0x100
	// Line 779, Address: 0x1f8c24, Func Offset: 0x114
	// Line 780, Address: 0x1f8c48, Func Offset: 0x138
	// Line 782, Address: 0x1f8c50, Func Offset: 0x140
	// Line 783, Address: 0x1f8c60, Func Offset: 0x150
	// Line 784, Address: 0x1f8c68, Func Offset: 0x158
	// Line 785, Address: 0x1f8c6c, Func Offset: 0x15c
	// Line 786, Address: 0x1f8c70, Func Offset: 0x160
	// Line 790, Address: 0x1f8c74, Func Offset: 0x164
	// Func End, Address: 0x1f8c84, Func Offset: 0x174
}

// 
// Start address: 0x1f8c90
void bhEne21_MV04(BH_PWORK* epw)
{
	// Line 800, Address: 0x1f8c90, Func Offset: 0
	// Line 801, Address: 0x1f8ca0, Func Offset: 0x10
	// Line 803, Address: 0x1f8cc0, Func Offset: 0x30
	// Line 806, Address: 0x1f8cd0, Func Offset: 0x40
	// Line 807, Address: 0x1f8cec, Func Offset: 0x5c
	// Line 806, Address: 0x1f8cf0, Func Offset: 0x60
	// Line 808, Address: 0x1f8cf4, Func Offset: 0x64
	// Line 807, Address: 0x1f8cf8, Func Offset: 0x68
	// Line 808, Address: 0x1f8cfc, Func Offset: 0x6c
	// Line 810, Address: 0x1f8d00, Func Offset: 0x70
	// Line 811, Address: 0x1f8d1c, Func Offset: 0x8c
	// Line 810, Address: 0x1f8d24, Func Offset: 0x94
	// Line 811, Address: 0x1f8d2c, Func Offset: 0x9c
	// Line 812, Address: 0x1f8d30, Func Offset: 0xa0
	// Line 815, Address: 0x1f8d3c, Func Offset: 0xac
	// Line 816, Address: 0x1f8d40, Func Offset: 0xb0
	// Line 815, Address: 0x1f8d48, Func Offset: 0xb8
	// Line 816, Address: 0x1f8d4c, Func Offset: 0xbc
	// Line 818, Address: 0x1f8d54, Func Offset: 0xc4
	// Line 819, Address: 0x1f8d64, Func Offset: 0xd4
	// Line 821, Address: 0x1f8d78, Func Offset: 0xe8
	// Line 822, Address: 0x1f8d88, Func Offset: 0xf8
	// Line 823, Address: 0x1f8d90, Func Offset: 0x100
	// Line 824, Address: 0x1f8d94, Func Offset: 0x104
	// Line 825, Address: 0x1f8d98, Func Offset: 0x108
	// Line 829, Address: 0x1f8d9c, Func Offset: 0x10c
	// Func End, Address: 0x1f8dac, Func Offset: 0x11c
}

// 
// Start address: 0x1f8db0
void bhEne21_MV05(BH_PWORK* epw)
{
	// Line 839, Address: 0x1f8db0, Func Offset: 0
	// Line 840, Address: 0x1f8dc0, Func Offset: 0x10
	// Line 842, Address: 0x1f8de0, Func Offset: 0x30
	// Line 845, Address: 0x1f8df0, Func Offset: 0x40
	// Line 846, Address: 0x1f8e0c, Func Offset: 0x5c
	// Line 845, Address: 0x1f8e10, Func Offset: 0x60
	// Line 847, Address: 0x1f8e14, Func Offset: 0x64
	// Line 846, Address: 0x1f8e18, Func Offset: 0x68
	// Line 847, Address: 0x1f8e1c, Func Offset: 0x6c
	// Line 849, Address: 0x1f8e20, Func Offset: 0x70
	// Line 850, Address: 0x1f8e3c, Func Offset: 0x8c
	// Line 849, Address: 0x1f8e44, Func Offset: 0x94
	// Line 850, Address: 0x1f8e4c, Func Offset: 0x9c
	// Line 851, Address: 0x1f8e50, Func Offset: 0xa0
	// Line 854, Address: 0x1f8e5c, Func Offset: 0xac
	// Line 855, Address: 0x1f8e60, Func Offset: 0xb0
	// Line 854, Address: 0x1f8e68, Func Offset: 0xb8
	// Line 855, Address: 0x1f8e6c, Func Offset: 0xbc
	// Line 857, Address: 0x1f8e74, Func Offset: 0xc4
	// Line 858, Address: 0x1f8e84, Func Offset: 0xd4
	// Line 860, Address: 0x1f8e98, Func Offset: 0xe8
	// Line 861, Address: 0x1f8ea8, Func Offset: 0xf8
	// Line 862, Address: 0x1f8eb0, Func Offset: 0x100
	// Line 863, Address: 0x1f8eb4, Func Offset: 0x104
	// Line 864, Address: 0x1f8eb8, Func Offset: 0x108
	// Line 868, Address: 0x1f8ebc, Func Offset: 0x10c
	// Func End, Address: 0x1f8ecc, Func Offset: 0x11c
}

// 
// Start address: 0x1f8ed0
void bhEne21_MV06(BH_PWORK* epw)
{
	unsigned char wall;
	// Line 878, Address: 0x1f8ed0, Func Offset: 0
	// Line 881, Address: 0x1f8edc, Func Offset: 0xc
	// Line 884, Address: 0x1f8f08, Func Offset: 0x38
	// Line 886, Address: 0x1f8f1c, Func Offset: 0x4c
	// Line 888, Address: 0x1f8f28, Func Offset: 0x58
	// Line 889, Address: 0x1f8f5c, Func Offset: 0x8c
	// Line 890, Address: 0x1f8f60, Func Offset: 0x90
	// Line 891, Address: 0x1f8f68, Func Offset: 0x98
	// Line 892, Address: 0x1f8f6c, Func Offset: 0x9c
	// Line 894, Address: 0x1f8f84, Func Offset: 0xb4
	// Line 895, Address: 0x1f8fb4, Func Offset: 0xe4
	// Line 897, Address: 0x1f8fc4, Func Offset: 0xf4
	// Line 898, Address: 0x1f8fc8, Func Offset: 0xf8
	// Line 900, Address: 0x1f8fdc, Func Offset: 0x10c
	// Line 901, Address: 0x1f8fe0, Func Offset: 0x110
	// Line 903, Address: 0x1f8fe8, Func Offset: 0x118
	// Line 904, Address: 0x1f8ff0, Func Offset: 0x120
	// Line 905, Address: 0x1f8ff4, Func Offset: 0x124
	// Line 908, Address: 0x1f8ff8, Func Offset: 0x128
	// Line 911, Address: 0x1f9000, Func Offset: 0x130
	// Line 913, Address: 0x1f9008, Func Offset: 0x138
	// Line 914, Address: 0x1f900c, Func Offset: 0x13c
	// Line 911, Address: 0x1f9010, Func Offset: 0x140
	// Line 912, Address: 0x1f9028, Func Offset: 0x158
	// Line 913, Address: 0x1f902c, Func Offset: 0x15c
	// Line 915, Address: 0x1f9030, Func Offset: 0x160
	// Line 918, Address: 0x1f9038, Func Offset: 0x168
	// Line 919, Address: 0x1f9044, Func Offset: 0x174
	// Line 921, Address: 0x1f9080, Func Offset: 0x1b0
	// Line 923, Address: 0x1f90b8, Func Offset: 0x1e8
	// Line 924, Address: 0x1f90c8, Func Offset: 0x1f8
	// Line 925, Address: 0x1f90dc, Func Offset: 0x20c
	// Line 926, Address: 0x1f90ec, Func Offset: 0x21c
	// Line 927, Address: 0x1f90f4, Func Offset: 0x224
	// Line 928, Address: 0x1f90f8, Func Offset: 0x228
	// Line 931, Address: 0x1f90fc, Func Offset: 0x22c
	// Line 934, Address: 0x1f9104, Func Offset: 0x234
	// Line 935, Address: 0x1f9114, Func Offset: 0x244
	// Line 937, Address: 0x1f9150, Func Offset: 0x280
	// Line 939, Address: 0x1f9188, Func Offset: 0x2b8
	// Line 940, Address: 0x1f9198, Func Offset: 0x2c8
	// Line 941, Address: 0x1f91ac, Func Offset: 0x2dc
	// Line 942, Address: 0x1f91bc, Func Offset: 0x2ec
	// Line 943, Address: 0x1f91c4, Func Offset: 0x2f4
	// Line 944, Address: 0x1f91c8, Func Offset: 0x2f8
	// Line 945, Address: 0x1f91cc, Func Offset: 0x2fc
	// Line 949, Address: 0x1f91d0, Func Offset: 0x300
	// Func End, Address: 0x1f91e0, Func Offset: 0x310
}

// 
// Start address: 0x1f91e0
void bhEne21_MV07()
{
	// Line 961, Address: 0x1f91e0, Func Offset: 0
	// Func End, Address: 0x1f91e8, Func Offset: 0x8
}

// 
// Start address: 0x1f91f0
void bhEne21_MV08(BH_PWORK* epw)
{
	// Line 976, Address: 0x1f91f0, Func Offset: 0
	// Line 977, Address: 0x1f91f8, Func Offset: 0x8
	// Line 978, Address: 0x1f91fc, Func Offset: 0xc
	// Line 980, Address: 0x1f9200, Func Offset: 0x10
	// Func End, Address: 0x1f9208, Func Offset: 0x18
}

// 
// Start address: 0x1f9210
void bhEne21_Nage(BH_PWORK* epw)
{
	// Line 992, Address: 0x1f9210, Func Offset: 0
	// Func End, Address: 0x1f9230, Func Offset: 0x20
}

// 
// Start address: 0x1f9230
void bhEne21_NG00(BH_PWORK* epw)
{
	int i;
	BH_PWORK* ep;
	// Line 1003, Address: 0x1f9230, Func Offset: 0
	// Line 1008, Address: 0x1f923c, Func Offset: 0xc
	// Line 1010, Address: 0x1f9244, Func Offset: 0x14
	// Line 1008, Address: 0x1f9248, Func Offset: 0x18
	// Line 1010, Address: 0x1f9250, Func Offset: 0x20
	// Line 1013, Address: 0x1f9284, Func Offset: 0x54
	// Line 1014, Address: 0x1f9288, Func Offset: 0x58
	// Line 1016, Address: 0x1f9294, Func Offset: 0x64
	// Line 1013, Address: 0x1f9298, Func Offset: 0x68
	// Line 1014, Address: 0x1f929c, Func Offset: 0x6c
	// Line 1015, Address: 0x1f92a4, Func Offset: 0x74
	// Line 1014, Address: 0x1f92a8, Func Offset: 0x78
	// Line 1015, Address: 0x1f92b0, Func Offset: 0x80
	// Line 1016, Address: 0x1f92b8, Func Offset: 0x88
	// Line 1015, Address: 0x1f92bc, Func Offset: 0x8c
	// Line 1016, Address: 0x1f92c4, Func Offset: 0x94
	// Line 1017, Address: 0x1f92cc, Func Offset: 0x9c
	// Line 1019, Address: 0x1f92d8, Func Offset: 0xa8
	// Line 1020, Address: 0x1f9304, Func Offset: 0xd4
	// Line 1021, Address: 0x1f9314, Func Offset: 0xe4
	// Line 1022, Address: 0x1f9320, Func Offset: 0xf0
	// Line 1023, Address: 0x1f9328, Func Offset: 0xf8
	// Line 1024, Address: 0x1f9334, Func Offset: 0x104
	// Line 1026, Address: 0x1f9354, Func Offset: 0x124
	// Line 1029, Address: 0x1f935c, Func Offset: 0x12c
	// Line 1031, Address: 0x1f9360, Func Offset: 0x130
	// Line 1032, Address: 0x1f9364, Func Offset: 0x134
	// Line 1026, Address: 0x1f9368, Func Offset: 0x138
	// Line 1029, Address: 0x1f936c, Func Offset: 0x13c
	// Line 1030, Address: 0x1f9370, Func Offset: 0x140
	// Line 1031, Address: 0x1f9374, Func Offset: 0x144
	// Line 1032, Address: 0x1f9378, Func Offset: 0x148
	// Line 1038, Address: 0x1f937c, Func Offset: 0x14c
	// Line 1040, Address: 0x1f9394, Func Offset: 0x164
	// Line 1043, Address: 0x1f93a0, Func Offset: 0x170
	// Line 1044, Address: 0x1f93c4, Func Offset: 0x194
	// Line 1047, Address: 0x1f93d8, Func Offset: 0x1a8
	// Line 1049, Address: 0x1f93e8, Func Offset: 0x1b8
	// Line 1051, Address: 0x1f93fc, Func Offset: 0x1cc
	// Line 1052, Address: 0x1f9408, Func Offset: 0x1d8
	// Line 1051, Address: 0x1f940c, Func Offset: 0x1dc
	// Line 1052, Address: 0x1f9414, Func Offset: 0x1e4
	// Line 1053, Address: 0x1f9424, Func Offset: 0x1f4
	// Line 1054, Address: 0x1f9428, Func Offset: 0x1f8
	// Line 1056, Address: 0x1f9430, Func Offset: 0x200
	// Line 1057, Address: 0x1f9438, Func Offset: 0x208
	// Line 1068, Address: 0x1f9444, Func Offset: 0x214
	// Line 1057, Address: 0x1f9448, Func Offset: 0x218
	// Line 1058, Address: 0x1f944c, Func Offset: 0x21c
	// Line 1060, Address: 0x1f9458, Func Offset: 0x228
	// Line 1061, Address: 0x1f9464, Func Offset: 0x234
	// Line 1062, Address: 0x1f9470, Func Offset: 0x240
	// Line 1061, Address: 0x1f9474, Func Offset: 0x244
	// Line 1062, Address: 0x1f9478, Func Offset: 0x248
	// Line 1063, Address: 0x1f9484, Func Offset: 0x254
	// Line 1062, Address: 0x1f9488, Func Offset: 0x258
	// Line 1063, Address: 0x1f9490, Func Offset: 0x260
	// Line 1064, Address: 0x1f949c, Func Offset: 0x26c
	// Line 1063, Address: 0x1f94a0, Func Offset: 0x270
	// Line 1064, Address: 0x1f94a8, Func Offset: 0x278
	// Line 1068, Address: 0x1f94b8, Func Offset: 0x288
	// Line 1070, Address: 0x1f94c0, Func Offset: 0x290
	// Line 1073, Address: 0x1f94cc, Func Offset: 0x29c
	// Line 1075, Address: 0x1f94dc, Func Offset: 0x2ac
	// Line 1077, Address: 0x1f94e4, Func Offset: 0x2b4
	// Line 1080, Address: 0x1f94ec, Func Offset: 0x2bc
	// Line 1081, Address: 0x1f94f4, Func Offset: 0x2c4
	// Line 1082, Address: 0x1f94f8, Func Offset: 0x2c8
	// Line 1086, Address: 0x1f9500, Func Offset: 0x2d0
	// Line 1087, Address: 0x1f9508, Func Offset: 0x2d8
	// Line 1083, Address: 0x1f9510, Func Offset: 0x2e0
	// Line 1087, Address: 0x1f9514, Func Offset: 0x2e4
	// Line 1088, Address: 0x1f951c, Func Offset: 0x2ec
	// Line 1090, Address: 0x1f9538, Func Offset: 0x308
	// Line 1092, Address: 0x1f9540, Func Offset: 0x310
	// Line 1094, Address: 0x1f9568, Func Offset: 0x338
	// Line 1095, Address: 0x1f9574, Func Offset: 0x344
	// Line 1094, Address: 0x1f9578, Func Offset: 0x348
	// Line 1095, Address: 0x1f957c, Func Offset: 0x34c
	// Line 1096, Address: 0x1f9588, Func Offset: 0x358
	// Line 1097, Address: 0x1f9594, Func Offset: 0x364
	// Line 1098, Address: 0x1f959c, Func Offset: 0x36c
	// Line 1103, Address: 0x1f95a4, Func Offset: 0x374
	// Line 1101, Address: 0x1f95a8, Func Offset: 0x378
	// Line 1103, Address: 0x1f95ac, Func Offset: 0x37c
	// Line 1104, Address: 0x1f95b0, Func Offset: 0x380
	// Line 1105, Address: 0x1f95b4, Func Offset: 0x384
	// Line 1106, Address: 0x1f95b8, Func Offset: 0x388
	// Line 1109, Address: 0x1f95bc, Func Offset: 0x38c
	// Func End, Address: 0x1f95cc, Func Offset: 0x39c
}

// 
// Start address: 0x1f95d0
void bhEne21_Damage(BH_PWORK* epw)
{
	_anon23 pos;
	unsigned int dam;
	unsigned int i;
	// Line 1120, Address: 0x1f95d0, Func Offset: 0
	// Line 1125, Address: 0x1f95e4, Func Offset: 0x14
	// Line 1126, Address: 0x1f95f4, Func Offset: 0x24
	// Line 1127, Address: 0x1f9600, Func Offset: 0x30
	// Line 1128, Address: 0x1f9604, Func Offset: 0x34
	// Line 1130, Address: 0x1f960c, Func Offset: 0x3c
	// Line 1131, Address: 0x1f9624, Func Offset: 0x54
	// Line 1133, Address: 0x1f962c, Func Offset: 0x5c
	// Line 1132, Address: 0x1f9630, Func Offset: 0x60
	// Line 1133, Address: 0x1f9634, Func Offset: 0x64
	// Line 1136, Address: 0x1f963c, Func Offset: 0x6c
	// Line 1141, Address: 0x1f9654, Func Offset: 0x84
	// Line 1144, Address: 0x1f9664, Func Offset: 0x94
	// Line 1146, Address: 0x1f9674, Func Offset: 0xa4
	// Line 1147, Address: 0x1f967c, Func Offset: 0xac
	// Line 1148, Address: 0x1f9680, Func Offset: 0xb0
	// Line 1150, Address: 0x1f9684, Func Offset: 0xb4
	// Line 1151, Address: 0x1f968c, Func Offset: 0xbc
	// Line 1152, Address: 0x1f9694, Func Offset: 0xc4
	// Line 1154, Address: 0x1f96a0, Func Offset: 0xd0
	// Func End, Address: 0x1f96b4, Func Offset: 0xe4
}

// 
// Start address: 0x1f96c0
void bhEne21_Die(BH_PWORK* epw)
{
	// Line 1177, Address: 0x1f96c0, Func Offset: 0
	// Func End, Address: 0x1f96e0, Func Offset: 0x20
}

// 
// Start address: 0x1f96e0
void bhEne21_DD00(BH_PWORK* epw)
{
	int i;
	BH_PWORK* ep;
	// Line 1188, Address: 0x1f96e0, Func Offset: 0
	// Line 1192, Address: 0x1f96f0, Func Offset: 0x10
	// Line 1195, Address: 0x1f971c, Func Offset: 0x3c
	// Line 1199, Address: 0x1f9724, Func Offset: 0x44
	// Line 1200, Address: 0x1f9728, Func Offset: 0x48
	// Line 1195, Address: 0x1f972c, Func Offset: 0x4c
	// Line 1197, Address: 0x1f9734, Func Offset: 0x54
	// Line 1204, Address: 0x1f9738, Func Offset: 0x58
	// Line 1197, Address: 0x1f973c, Func Offset: 0x5c
	// Line 1198, Address: 0x1f9744, Func Offset: 0x64
	// Line 1199, Address: 0x1f9748, Func Offset: 0x68
	// Line 1200, Address: 0x1f974c, Func Offset: 0x6c
	// Line 1201, Address: 0x1f9750, Func Offset: 0x70
	// Line 1205, Address: 0x1f9774, Func Offset: 0x94
	// Line 1206, Address: 0x1f9784, Func Offset: 0xa4
	// Line 1207, Address: 0x1f979c, Func Offset: 0xbc
	// Line 1208, Address: 0x1f97a4, Func Offset: 0xc4
	// Line 1209, Address: 0x1f97b0, Func Offset: 0xd0
	// Line 1211, Address: 0x1f97cc, Func Offset: 0xec
	// Line 1212, Address: 0x1f97dc, Func Offset: 0xfc
	// Line 1213, Address: 0x1f97e0, Func Offset: 0x100
	// Line 1215, Address: 0x1f9808, Func Offset: 0x128
	// Line 1217, Address: 0x1f9814, Func Offset: 0x134
	// Line 1219, Address: 0x1f9824, Func Offset: 0x144
	// Line 1221, Address: 0x1f9828, Func Offset: 0x148
	// Line 1222, Address: 0x1f9840, Func Offset: 0x160
	// Line 1224, Address: 0x1f9848, Func Offset: 0x168
	// Line 1227, Address: 0x1f9850, Func Offset: 0x170
	// Line 1228, Address: 0x1f9858, Func Offset: 0x178
	// Line 1231, Address: 0x1f9864, Func Offset: 0x184
	// Func End, Address: 0x1f9874, Func Offset: 0x194
}

// 
// Start address: 0x1f9880
void bhEne21_PlayerControl(BH_PWORK* epw)
{
	// Line 1244, Address: 0x1f9880, Func Offset: 0
	// Line 1246, Address: 0x1f98b4, Func Offset: 0x34
	// Line 1247, Address: 0x1f98c0, Func Offset: 0x40
	// Line 1248, Address: 0x1f98cc, Func Offset: 0x4c
	// Line 1247, Address: 0x1f98d8, Func Offset: 0x58
	// Line 1248, Address: 0x1f98e0, Func Offset: 0x60
	// Line 1250, Address: 0x1f98e8, Func Offset: 0x68
	// Line 1248, Address: 0x1f98ec, Func Offset: 0x6c
	// Line 1250, Address: 0x1f98f4, Func Offset: 0x74
	// Line 1251, Address: 0x1f98fc, Func Offset: 0x7c
	// Line 1250, Address: 0x1f9900, Func Offset: 0x80
	// Line 1251, Address: 0x1f9908, Func Offset: 0x88
	// Line 1253, Address: 0x1f9910, Func Offset: 0x90
	// Line 1251, Address: 0x1f9914, Func Offset: 0x94
	// Line 1253, Address: 0x1f991c, Func Offset: 0x9c
	// Line 1254, Address: 0x1f9930, Func Offset: 0xb0
	// Line 1255, Address: 0x1f993c, Func Offset: 0xbc
	// Line 1256, Address: 0x1f9948, Func Offset: 0xc8
	// Line 1258, Address: 0x1f9954, Func Offset: 0xd4
	// Line 1259, Address: 0x1f995c, Func Offset: 0xdc
	// Line 1260, Address: 0x1f9964, Func Offset: 0xe4
	// Line 1261, Address: 0x1f9968, Func Offset: 0xe8
	// Line 1259, Address: 0x1f996c, Func Offset: 0xec
	// Line 1260, Address: 0x1f9970, Func Offset: 0xf0
	// Line 1261, Address: 0x1f997c, Func Offset: 0xfc
	// Line 1263, Address: 0x1f9988, Func Offset: 0x108
	// Line 1265, Address: 0x1f9998, Func Offset: 0x118
	// Line 1267, Address: 0x1f99a0, Func Offset: 0x120
	// Line 1270, Address: 0x1f99bc, Func Offset: 0x13c
	// Line 1271, Address: 0x1f99c8, Func Offset: 0x148
	// Line 1272, Address: 0x1f99cc, Func Offset: 0x14c
	// Line 1273, Address: 0x1f99d4, Func Offset: 0x154
	// Line 1275, Address: 0x1f99dc, Func Offset: 0x15c
	// Line 1276, Address: 0x1f99e4, Func Offset: 0x164
	// Line 1277, Address: 0x1f99e8, Func Offset: 0x168
	// Line 1275, Address: 0x1f99ec, Func Offset: 0x16c
	// Line 1276, Address: 0x1f99f0, Func Offset: 0x170
	// Line 1277, Address: 0x1f99fc, Func Offset: 0x17c
	// Line 1279, Address: 0x1f9a08, Func Offset: 0x188
	// Line 1280, Address: 0x1f9a18, Func Offset: 0x198
	// Line 1279, Address: 0x1f9a1c, Func Offset: 0x19c
	// Line 1280, Address: 0x1f9a34, Func Offset: 0x1b4
	// Line 1281, Address: 0x1f9a40, Func Offset: 0x1c0
	// Line 1280, Address: 0x1f9a44, Func Offset: 0x1c4
	// Line 1281, Address: 0x1f9a60, Func Offset: 0x1e0
	// Line 1284, Address: 0x1f9a70, Func Offset: 0x1f0
	// Line 1285, Address: 0x1f9a84, Func Offset: 0x204
	// Line 1287, Address: 0x1f9ab8, Func Offset: 0x238
	// Line 1288, Address: 0x1f9ad0, Func Offset: 0x250
	// Line 1289, Address: 0x1f9ae8, Func Offset: 0x268
	// Line 1290, Address: 0x1f9af4, Func Offset: 0x274
	// Line 1291, Address: 0x1f9b00, Func Offset: 0x280
	// Line 1293, Address: 0x1f9b0c, Func Offset: 0x28c
	// Line 1294, Address: 0x1f9b14, Func Offset: 0x294
	// Line 1295, Address: 0x1f9b1c, Func Offset: 0x29c
	// Line 1296, Address: 0x1f9b20, Func Offset: 0x2a0
	// Line 1294, Address: 0x1f9b24, Func Offset: 0x2a4
	// Line 1295, Address: 0x1f9b28, Func Offset: 0x2a8
	// Line 1296, Address: 0x1f9b34, Func Offset: 0x2b4
	// Line 1298, Address: 0x1f9b40, Func Offset: 0x2c0
	// Line 1302, Address: 0x1f9b50, Func Offset: 0x2d0
	// Line 1305, Address: 0x1f9b58, Func Offset: 0x2d8
	// Line 1307, Address: 0x1f9b64, Func Offset: 0x2e4
	// Line 1305, Address: 0x1f9b6c, Func Offset: 0x2ec
	// Line 1307, Address: 0x1f9b74, Func Offset: 0x2f4
	// Line 1309, Address: 0x1f9b78, Func Offset: 0x2f8
	// Line 1313, Address: 0x1f9b7c, Func Offset: 0x2fc
	// Line 1307, Address: 0x1f9b80, Func Offset: 0x300
	// Line 1308, Address: 0x1f9b84, Func Offset: 0x304
	// Line 1307, Address: 0x1f9b88, Func Offset: 0x308
	// Line 1308, Address: 0x1f9b90, Func Offset: 0x310
	// Line 1309, Address: 0x1f9b98, Func Offset: 0x318
	// Line 1308, Address: 0x1f9b9c, Func Offset: 0x31c
	// Line 1309, Address: 0x1f9ba4, Func Offset: 0x324
	// Line 1310, Address: 0x1f9bac, Func Offset: 0x32c
	// Line 1309, Address: 0x1f9bb0, Func Offset: 0x330
	// Line 1310, Address: 0x1f9bb8, Func Offset: 0x338
	// Line 1313, Address: 0x1f9bc0, Func Offset: 0x340
	// Line 1316, Address: 0x1f9bcc, Func Offset: 0x34c
	// Line 1319, Address: 0x1f9bd4, Func Offset: 0x354
	// Func End, Address: 0x1f9bdc, Func Offset: 0x35c
}

// 
// Start address: 0x1f9be0
unsigned char bhEne21_AllWayWallCheck(BH_PWORK* epw, float dist)
{
	float i;
	unsigned char ret;
	int ang;
	_anon23 pos;
	// Line 1334, Address: 0x1f9be0, Func Offset: 0
	// Line 1343, Address: 0x1f9bfc, Func Offset: 0x1c
	// Line 1342, Address: 0x1f9c00, Func Offset: 0x20
	// Line 1343, Address: 0x1f9c04, Func Offset: 0x24
	// Line 1344, Address: 0x1f9c1c, Func Offset: 0x3c
	// Line 1345, Address: 0x1f9c28, Func Offset: 0x48
	// Line 1344, Address: 0x1f9c2c, Func Offset: 0x4c
	// Line 1345, Address: 0x1f9c34, Func Offset: 0x54
	// Line 1346, Address: 0x1f9c4c, Func Offset: 0x6c
	// Line 1348, Address: 0x1f9c54, Func Offset: 0x74
	// Line 1349, Address: 0x1f9c70, Func Offset: 0x90
	// Line 1350, Address: 0x1f9c74, Func Offset: 0x94
	// Line 1352, Address: 0x1f9c7c, Func Offset: 0x9c
	// Line 1355, Address: 0x1f9ca0, Func Offset: 0xc0
	// Line 1356, Address: 0x1f9ca4, Func Offset: 0xc4
	// Line 1355, Address: 0x1f9cb4, Func Offset: 0xd4
	// Line 1356, Address: 0x1f9cb8, Func Offset: 0xd8
	// Line 1357, Address: 0x1f9cc0, Func Offset: 0xe0
	// Line 1358, Address: 0x1f9ccc, Func Offset: 0xec
	// Line 1357, Address: 0x1f9cd0, Func Offset: 0xf0
	// Line 1358, Address: 0x1f9cd8, Func Offset: 0xf8
	// Line 1359, Address: 0x1f9cf0, Func Offset: 0x110
	// Line 1361, Address: 0x1f9cf8, Func Offset: 0x118
	// Line 1362, Address: 0x1f9d14, Func Offset: 0x134
	// Line 1363, Address: 0x1f9d18, Func Offset: 0x138
	// Line 1365, Address: 0x1f9d20, Func Offset: 0x140
	// Line 1368, Address: 0x1f9d40, Func Offset: 0x160
	// Line 1369, Address: 0x1f9d44, Func Offset: 0x164
	// Line 1368, Address: 0x1f9d54, Func Offset: 0x174
	// Line 1369, Address: 0x1f9d58, Func Offset: 0x178
	// Line 1370, Address: 0x1f9d60, Func Offset: 0x180
	// Line 1371, Address: 0x1f9d6c, Func Offset: 0x18c
	// Line 1370, Address: 0x1f9d70, Func Offset: 0x190
	// Line 1371, Address: 0x1f9d78, Func Offset: 0x198
	// Line 1372, Address: 0x1f9d90, Func Offset: 0x1b0
	// Line 1374, Address: 0x1f9d98, Func Offset: 0x1b8
	// Line 1375, Address: 0x1f9db4, Func Offset: 0x1d4
	// Line 1376, Address: 0x1f9db8, Func Offset: 0x1d8
	// Line 1378, Address: 0x1f9dc0, Func Offset: 0x1e0
	// Line 1381, Address: 0x1f9de0, Func Offset: 0x200
	// Line 1382, Address: 0x1f9de4, Func Offset: 0x204
	// Line 1381, Address: 0x1f9df4, Func Offset: 0x214
	// Line 1382, Address: 0x1f9dfc, Func Offset: 0x21c
	// Line 1383, Address: 0x1f9e04, Func Offset: 0x224
	// Line 1384, Address: 0x1f9e10, Func Offset: 0x230
	// Line 1383, Address: 0x1f9e14, Func Offset: 0x234
	// Line 1384, Address: 0x1f9e1c, Func Offset: 0x23c
	// Line 1385, Address: 0x1f9e34, Func Offset: 0x254
	// Line 1387, Address: 0x1f9e3c, Func Offset: 0x25c
	// Line 1388, Address: 0x1f9e58, Func Offset: 0x278
	// Line 1389, Address: 0x1f9e5c, Func Offset: 0x27c
	// Line 1391, Address: 0x1f9e64, Func Offset: 0x284
	// Line 1393, Address: 0x1f9e88, Func Offset: 0x2a8
	// Line 1394, Address: 0x1f9e8c, Func Offset: 0x2ac
	// Func End, Address: 0x1f9eac, Func Offset: 0x2cc
}

// 
// Start address: 0x1f9eb0
void bhEne21_SetSparkEff(BH_PWORK* epw, int num, int flg, unsigned int ofy)
{
	_anon6* owk;
	int i;
	int eno;
	// Line 1408, Address: 0x1f9eb0, Func Offset: 0
	// Line 1414, Address: 0x1f9edc, Func Offset: 0x2c
	// Line 1408, Address: 0x1f9ee0, Func Offset: 0x30
	// Line 1414, Address: 0x1f9eec, Func Offset: 0x3c
	// Line 1416, Address: 0x1f9f00, Func Offset: 0x50
	// Line 1417, Address: 0x1f9f0c, Func Offset: 0x5c
	// Line 1420, Address: 0x1f9f10, Func Offset: 0x60
	// Line 1416, Address: 0x1f9f14, Func Offset: 0x64
	// Line 1417, Address: 0x1f9f20, Func Offset: 0x70
	// Line 1424, Address: 0x1f9f28, Func Offset: 0x78
	// Line 1417, Address: 0x1f9f2c, Func Offset: 0x7c
	// Line 1418, Address: 0x1f9f38, Func Offset: 0x88
	// Line 1420, Address: 0x1f9f4c, Func Offset: 0x9c
	// Line 1421, Address: 0x1f9f60, Func Offset: 0xb0
	// Line 1422, Address: 0x1f9f74, Func Offset: 0xc4
	// Line 1424, Address: 0x1f9f84, Func Offset: 0xd4
	// Line 1427, Address: 0x1f9fb0, Func Offset: 0x100
	// Line 1428, Address: 0x1f9fc4, Func Offset: 0x114
	// Line 1427, Address: 0x1f9fc8, Func Offset: 0x118
	// Line 1428, Address: 0x1f9fd4, Func Offset: 0x124
	// Line 1427, Address: 0x1f9fd8, Func Offset: 0x128
	// Line 1428, Address: 0x1f9fdc, Func Offset: 0x12c
	// Line 1429, Address: 0x1f9ffc, Func Offset: 0x14c
	// Line 1431, Address: 0x1fa018, Func Offset: 0x168
	// Line 1432, Address: 0x1fa02c, Func Offset: 0x17c
	// Line 1434, Address: 0x1fa034, Func Offset: 0x184
	// Line 1436, Address: 0x1fa058, Func Offset: 0x1a8
	// Line 1437, Address: 0x1fa05c, Func Offset: 0x1ac
	// Line 1438, Address: 0x1fa060, Func Offset: 0x1b0
	// Line 1439, Address: 0x1fa0a4, Func Offset: 0x1f4
	// Line 1440, Address: 0x1fa0dc, Func Offset: 0x22c
	// Line 1441, Address: 0x1fa120, Func Offset: 0x270
	// Line 1442, Address: 0x1fa158, Func Offset: 0x2a8
	// Line 1443, Address: 0x1fa19c, Func Offset: 0x2ec
	// Line 1444, Address: 0x1fa1d4, Func Offset: 0x324
	// Line 1446, Address: 0x1fa1dc, Func Offset: 0x32c
	// Line 1447, Address: 0x1fa218, Func Offset: 0x368
	// Line 1448, Address: 0x1fa260, Func Offset: 0x3b0
	// Line 1449, Address: 0x1fa2a4, Func Offset: 0x3f4
	// Line 1450, Address: 0x1fa2ec, Func Offset: 0x43c
	// Line 1451, Address: 0x1fa33c, Func Offset: 0x48c
	// Line 1453, Address: 0x1fa344, Func Offset: 0x494
	// Line 1455, Address: 0x1fa348, Func Offset: 0x498
	// Line 1457, Address: 0x1fa354, Func Offset: 0x4a4
	// Line 1453, Address: 0x1fa35c, Func Offset: 0x4ac
	// Line 1457, Address: 0x1fa360, Func Offset: 0x4b0
	// Line 1455, Address: 0x1fa364, Func Offset: 0x4b4
	// Line 1456, Address: 0x1fa368, Func Offset: 0x4b8
	// Line 1457, Address: 0x1fa36c, Func Offset: 0x4bc
	// Line 1455, Address: 0x1fa374, Func Offset: 0x4c4
	// Line 1457, Address: 0x1fa378, Func Offset: 0x4c8
	// Line 1458, Address: 0x1fa37c, Func Offset: 0x4cc
	// Line 1459, Address: 0x1fa390, Func Offset: 0x4e0
	// Line 1461, Address: 0x1fa3a4, Func Offset: 0x4f4
	// Line 1463, Address: 0x1fa3c4, Func Offset: 0x514
	// Line 1466, Address: 0x1fa3c8, Func Offset: 0x518
	// Line 1467, Address: 0x1fa3ec, Func Offset: 0x53c
	// Line 1468, Address: 0x1fa3f8, Func Offset: 0x548
	// Line 1470, Address: 0x1fa41c, Func Offset: 0x56c
	// Line 1468, Address: 0x1fa420, Func Offset: 0x570
	// Line 1469, Address: 0x1fa428, Func Offset: 0x578
	// Line 1470, Address: 0x1fa434, Func Offset: 0x584
	// Line 1472, Address: 0x1fa438, Func Offset: 0x588
	// Line 1473, Address: 0x1fa448, Func Offset: 0x598
	// Func End, Address: 0x1fa478, Func Offset: 0x5c8
}

// 
// Start address: 0x1fa480
void bhEff_E21_Spark(_anon0* op)
{
	_anon3* uvp;
	_anon3* uvtble[4];
	char flm_tbl[4];
	char pat_tbl[4];
	// Line 1488, Address: 0x1fa480, Func Offset: 0
	// Line 1560, Address: 0x1fa490, Func Offset: 0x10
	// Line 1562, Address: 0x1fa4b0, Func Offset: 0x30
	// Line 1564, Address: 0x1fa4b8, Func Offset: 0x38
	// Line 1566, Address: 0x1fa4c0, Func Offset: 0x40
	// Line 1567, Address: 0x1fa4c4, Func Offset: 0x44
	// Line 1568, Address: 0x1fa4d0, Func Offset: 0x50
	// Line 1567, Address: 0x1fa4d8, Func Offset: 0x58
	// Line 1568, Address: 0x1fa4e4, Func Offset: 0x64
	// Line 1569, Address: 0x1fa4e8, Func Offset: 0x68
	// Line 1568, Address: 0x1fa4ec, Func Offset: 0x6c
	// Line 1569, Address: 0x1fa4f8, Func Offset: 0x78
	// Line 1570, Address: 0x1fa504, Func Offset: 0x84
	// Line 1571, Address: 0x1fa510, Func Offset: 0x90
	// Line 1572, Address: 0x1fa518, Func Offset: 0x98
	// Line 1573, Address: 0x1fa520, Func Offset: 0xa0
	// Line 1574, Address: 0x1fa528, Func Offset: 0xa8
	// Line 1576, Address: 0x1fa52c, Func Offset: 0xac
	// Line 1577, Address: 0x1fa538, Func Offset: 0xb8
	// Line 1579, Address: 0x1fa544, Func Offset: 0xc4
	// Line 1581, Address: 0x1fa54c, Func Offset: 0xcc
	// Line 1582, Address: 0x1fa584, Func Offset: 0x104
	// Line 1584, Address: 0x1fa5b8, Func Offset: 0x138
	// Line 1585, Address: 0x1fa5dc, Func Offset: 0x15c
	// Line 1586, Address: 0x1fa5fc, Func Offset: 0x17c
	// Line 1588, Address: 0x1fa604, Func Offset: 0x184
	// Line 1589, Address: 0x1fa61c, Func Offset: 0x19c
	// Line 1593, Address: 0x1fa624, Func Offset: 0x1a4
	// Line 1594, Address: 0x1fa648, Func Offset: 0x1c8
	// Line 1599, Address: 0x1fa66c, Func Offset: 0x1ec
	// Line 1600, Address: 0x1fa678, Func Offset: 0x1f8
	// Line 1601, Address: 0x1fa67c, Func Offset: 0x1fc
	// Line 1602, Address: 0x1fa680, Func Offset: 0x200
	// Line 1604, Address: 0x1fa684, Func Offset: 0x204
	// Line 1615, Address: 0x1fa690, Func Offset: 0x210
	// Line 1612, Address: 0x1fa694, Func Offset: 0x214
	// Line 1604, Address: 0x1fa69c, Func Offset: 0x21c
	// Line 1605, Address: 0x1fa6a8, Func Offset: 0x228
	// Line 1606, Address: 0x1fa6b8, Func Offset: 0x238
	// Line 1607, Address: 0x1fa6dc, Func Offset: 0x25c
	// Line 1608, Address: 0x1fa6e4, Func Offset: 0x264
	// Line 1609, Address: 0x1fa6ec, Func Offset: 0x26c
	// Line 1610, Address: 0x1fa710, Func Offset: 0x290
	// Line 1611, Address: 0x1fa718, Func Offset: 0x298
	// Line 1612, Address: 0x1fa720, Func Offset: 0x2a0
	// Line 1613, Address: 0x1fa738, Func Offset: 0x2b8
	// Line 1615, Address: 0x1fa750, Func Offset: 0x2d0
	// Line 1616, Address: 0x1fa76c, Func Offset: 0x2ec
	// Line 1617, Address: 0x1fa780, Func Offset: 0x300
	// Line 1620, Address: 0x1fa7a4, Func Offset: 0x324
	// Func End, Address: 0x1fa7b8, Func Offset: 0x338
}

// 
// Start address: 0x1fa7c0
void bhEne21_SetMarkEff(BH_PWORK* epw)
{
	int eno;
	// Line 1631, Address: 0x1fa7c0, Func Offset: 0
	// Line 1637, Address: 0x1fa7cc, Func Offset: 0xc
	// Line 1654, Address: 0x1fa7d4, Func Offset: 0x14
	// Line 1637, Address: 0x1fa7dc, Func Offset: 0x1c
	// Line 1654, Address: 0x1fa7e0, Func Offset: 0x20
	// Line 1638, Address: 0x1fa7e4, Func Offset: 0x24
	// Line 1637, Address: 0x1fa7e8, Func Offset: 0x28
	// Line 1638, Address: 0x1fa7f4, Func Offset: 0x34
	// Line 1641, Address: 0x1fa7fc, Func Offset: 0x3c
	// Line 1659, Address: 0x1fa804, Func Offset: 0x44
	// Line 1662, Address: 0x1fa808, Func Offset: 0x48
	// Line 1638, Address: 0x1fa80c, Func Offset: 0x4c
	// Line 1639, Address: 0x1fa818, Func Offset: 0x58
	// Line 1662, Address: 0x1fa820, Func Offset: 0x60
	// Line 1639, Address: 0x1fa828, Func Offset: 0x68
	// Line 1641, Address: 0x1fa834, Func Offset: 0x74
	// Line 1642, Address: 0x1fa848, Func Offset: 0x88
	// Line 1643, Address: 0x1fa85c, Func Offset: 0x9c
	// Line 1653, Address: 0x1fa870, Func Offset: 0xb0
	// Line 1654, Address: 0x1fa890, Func Offset: 0xd0
	// Line 1655, Address: 0x1fa8b4, Func Offset: 0xf4
	// Line 1658, Address: 0x1fa8d4, Func Offset: 0x114
	// Line 1659, Address: 0x1fa8ec, Func Offset: 0x12c
	// Line 1662, Address: 0x1fa900, Func Offset: 0x140
	// Line 1663, Address: 0x1fa918, Func Offset: 0x158
	// Line 1664, Address: 0x1fa924, Func Offset: 0x164
	// Line 1665, Address: 0x1fa948, Func Offset: 0x188
	// Line 1664, Address: 0x1fa954, Func Offset: 0x194
	// Line 1665, Address: 0x1fa95c, Func Offset: 0x19c
	// Line 1666, Address: 0x1fa960, Func Offset: 0x1a0
	// Line 1665, Address: 0x1fa96c, Func Offset: 0x1ac
	// Line 1666, Address: 0x1fa970, Func Offset: 0x1b0
	// Line 1665, Address: 0x1fa974, Func Offset: 0x1b4
	// Line 1666, Address: 0x1fa978, Func Offset: 0x1b8
	// Line 1668, Address: 0x1fa97c, Func Offset: 0x1bc
	// Func End, Address: 0x1fa98c, Func Offset: 0x1cc
}

// 
// Start address: 0x1fa990
void bhEff_E21_Mark(_anon0* op)
{
	_anon3* uvp;
	_anon3 uvinfo0[12];
	// Line 1700, Address: 0x1fa990, Func Offset: 0
	// Line 1703, Address: 0x1fa9b0, Func Offset: 0x20
	// Line 1706, Address: 0x1fa9b8, Func Offset: 0x28
	// Line 1708, Address: 0x1fa9c0, Func Offset: 0x30
	// Line 1707, Address: 0x1fa9c4, Func Offset: 0x34
	// Line 1708, Address: 0x1fa9c8, Func Offset: 0x38
	// Line 1709, Address: 0x1fa9cc, Func Offset: 0x3c
	// Line 1710, Address: 0x1fa9d0, Func Offset: 0x40
	// Line 1711, Address: 0x1fa9e0, Func Offset: 0x50
	// Line 1712, Address: 0x1fa9ec, Func Offset: 0x5c
	// Line 1713, Address: 0x1fa9f4, Func Offset: 0x64
	// Line 1714, Address: 0x1fa9fc, Func Offset: 0x6c
	// Line 1716, Address: 0x1faa00, Func Offset: 0x70
	// Line 1717, Address: 0x1faa0c, Func Offset: 0x7c
	// Line 1719, Address: 0x1faa18, Func Offset: 0x88
	// Line 1721, Address: 0x1faa20, Func Offset: 0x90
	// Line 1722, Address: 0x1faa3c, Func Offset: 0xac
	// Line 1723, Address: 0x1faa48, Func Offset: 0xb8
	// Line 1726, Address: 0x1faa54, Func Offset: 0xc4
	// Line 1723, Address: 0x1faa60, Func Offset: 0xd0
	// Line 1727, Address: 0x1faa64, Func Offset: 0xd4
	// Line 1728, Address: 0x1faa68, Func Offset: 0xd8
	// Line 1729, Address: 0x1faa6c, Func Offset: 0xdc
	// Line 1723, Address: 0x1faa70, Func Offset: 0xe0
	// Line 1731, Address: 0x1faa74, Func Offset: 0xe4
	// Line 1742, Address: 0x1faa80, Func Offset: 0xf0
	// Line 1739, Address: 0x1faa84, Func Offset: 0xf4
	// Line 1731, Address: 0x1faa8c, Func Offset: 0xfc
	// Line 1732, Address: 0x1faa98, Func Offset: 0x108
	// Line 1733, Address: 0x1faaa8, Func Offset: 0x118
	// Line 1734, Address: 0x1faacc, Func Offset: 0x13c
	// Line 1735, Address: 0x1faad4, Func Offset: 0x144
	// Line 1736, Address: 0x1faadc, Func Offset: 0x14c
	// Line 1737, Address: 0x1fab00, Func Offset: 0x170
	// Line 1738, Address: 0x1fab08, Func Offset: 0x178
	// Line 1739, Address: 0x1fab10, Func Offset: 0x180
	// Line 1740, Address: 0x1fab28, Func Offset: 0x198
	// Line 1742, Address: 0x1fab40, Func Offset: 0x1b0
	// Line 1743, Address: 0x1fab5c, Func Offset: 0x1cc
	// Line 1744, Address: 0x1fab70, Func Offset: 0x1e0
	// Line 1747, Address: 0x1fab94, Func Offset: 0x204
	// Func End, Address: 0x1fab9c, Func Offset: 0x20c
}

