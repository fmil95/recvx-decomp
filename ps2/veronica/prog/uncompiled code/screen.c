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
typedef union _anon14;
typedef struct _anon15;
typedef struct _anon16;
typedef struct _anon17;
typedef struct _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct BH_PWORK;
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
typedef struct _anon36;
typedef struct _anon37;
typedef struct _anon38;

typedef void(*type_87)(void*);

typedef _anon14 type_0[4];
typedef float type_1[16];
typedef unsigned int type_2[4];
typedef _anon0* type_3[512];
typedef _anon0* type_4[32];
typedef _anon1* type_5[16];
typedef _anon0* type_6[32];
typedef _anon0* type_7[512];
typedef _anon1* type_8[16][16];
typedef _anon1* type_9[16][16][100];
typedef char type_10[8];
typedef _anon5 type_11[32];
typedef _anon0* type_12[32];
typedef _anon0* type_13[512];
typedef _anon1* type_14[1300];
typedef char type_15[32];
typedef _anon0* type_16[512];
typedef _anon1* type_17[200];
typedef short type_18[32];
typedef _anon16 type_19[1];
typedef _anon0* type_20[128];
typedef unsigned int type_21[1];
typedef _anon5 type_22[256];
typedef _anon1* type_23[8];
typedef int* type_24[16];
typedef _anon0* type_25[128];
typedef npobj* type_26[16];
typedef _anon0* type_27[128];
typedef int type_28[4];
typedef _anon1* type_29[16];
typedef unsigned int type_30[4];
typedef _anon25 type_31[4];
typedef _anon8 type_32[16];
typedef _anon0* type_33[512];
typedef _anon14 type_34[4];
typedef char type_35[256];
typedef float type_36[4];
typedef float type_37[4];
typedef float type_38[4];
typedef _anon3* type_39[128];
typedef float type_40[3];
typedef unsigned char type_41[64];
typedef float type_42[3][20];
typedef float type_43[3];
typedef float type_44[3][20];
typedef float type_45[3];
typedef float type_46[3][20];
typedef char type_47[8];
typedef float type_48[3];
typedef float type_49[3][20];
typedef void* type_50[2];
typedef _anon25 type_51[4];
typedef _anon14 type_52[4];
typedef _anon1* type_53[256];
typedef int type_54[4];
typedef unsigned char* type_55[256];
typedef unsigned int type_56[2];
typedef short type_57[256];
typedef _anon23 type_58[4];
typedef float type_59[3];
typedef short type_60[256];
typedef int type_61[3];
typedef int type_62[8];
typedef float type_63[3];
typedef _anon0 type_64[0];
typedef _anon1* type_65[256];
typedef _anon7 type_66[256];
typedef _anon16 type_67[450];
typedef float type_68[16][0];
typedef _anon25 type_69[16];
typedef short type_70[256];
typedef char type_71[3];
typedef int type_72[64];
typedef _anon8 type_73[450];
typedef short type_74[8];
typedef short type_75[8][18];
typedef _anon29 type_76[4];
typedef _anon2 type_77[4];
typedef int type_78[450];
typedef unsigned int type_79[8];
typedef unsigned char type_80[450];
typedef _anon25 type_81[4];
typedef _anon29 type_82[4];
typedef _anon14 type_83[4];
typedef _anon14 type_84[4];
typedef char type_85[16];
typedef char type_86[4];
typedef unsigned int type_88[32];
typedef _anon25 type_89[4];
typedef unsigned int type_90[16];
typedef _anon32 type_91[64];
typedef unsigned int type_92[16];
typedef _anon32 type_93[64];
typedef unsigned int type_94[32];
typedef _anon14 type_95[4];
typedef _anon32 type_96[64];
typedef unsigned int type_97[16];
typedef unsigned int type_98[3];
typedef _anon14 type_99[4];
typedef BH_PWORK* type_100[16];
typedef unsigned int type_101[8];
typedef unsigned int type_102[1];
typedef short type_103[8];
typedef unsigned int type_104[384];
typedef short type_105[8][10];
typedef unsigned int type_106[2];
typedef unsigned char type_107[2];
typedef int* type_108[16];
typedef unsigned int type_109[4];
typedef _anon25 type_110[4];
typedef char type_111[32];
typedef npobj* type_112[16];
typedef _anon14 type_113[4];
typedef char type_114[64];
typedef _anon1* type_115[16];
typedef char type_116[4];
typedef _anon8 type_117[16];
typedef short type_118[4];
typedef unsigned char type_119[4];
typedef _anon27 type_120[16];
typedef _anon25 type_121[4];
typedef _anon14 type_122[4];
typedef unsigned int type_123[32];
typedef _anon14 type_124[4];
typedef _anon26 type_125[32];
typedef _anon0* type_126[512];
typedef _anon25 type_127[4];
typedef _anon0* type_128[128];
typedef _anon0* type_129[512];
typedef unsigned char type_130[64];
typedef _anon14 type_131[4];
typedef _anon0* type_132[512];

struct npobj
{
	unsigned int evalflags;
	_anon24* model;
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
	_anon37 cspr;
	int pn;
	_anon29* pvp;
	_anon2* tvp;
	_anon29 pv[4];
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
	_anon16* textures;
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
	_anon15* md2P;
	unsigned short* atrP;
};

struct _anon4
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
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
	_anon21* owP;
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
	_anon35* info;
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
	short u;
	short v;
};

struct _anon12
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct _anon13
{
	void* texaddr;
	_anon6 texsurface;
};

union _anon14
{
	unsigned int color;
	_anon11 tex;
	_anon12 argb;
};

struct _anon15
{
	void* p[2];
};

struct _anon16
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon17
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon18
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
	_anon22* light;
};

struct _anon19
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
	_anon26 ply_pos;
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
	_anon16 ef_tex[450];
	_anon1 ef_tlist;
	_anon31 ef;
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
	_anon13 ren_info;
	_anon16 ren_tex[1];
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
	_anon34 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon18* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon23 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon25 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon32* pl_htp;
	int costume;
	_anon26 hd_pos;
	_anon26 apos;
	_anon32* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon32 mwalp[64];
	_anon32 metcp[64];
	_anon32 mflrp[64];
	int dla_n;
	_anon32* htp;
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
	_anon26 ufo_pos;
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
	_anon27 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon26 ghtp[32];
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

struct _anon20
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon21
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon22
{
	float mtrx[16];
	_anon26 pnt;
	_anon26 vctr;
	int stat;
	int reserve;
	_anon28 ltcal;
	_anon36 attr;
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
	_anon38 watr;
	_anon17* cpcl;
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

struct _anon23
{
	_anon26 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon24
{
	int* vlist;
	short* plist;
	_anon26 center;
	float r;
};

struct _anon25
{
	float x;
	float y;
};

struct _anon26
{
	float x;
	float y;
	float z;
};

struct _anon27
{
	_anon26 c1;
	_anon26 c2;
	float r1;
	float r2;
};

struct _anon28
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
	_anon26 lpnt;
	_anon26 lvctr;
	_anon26 lmvctr;
	_anon20 atten;
	_anon20 amb;
	_anon20 dif;
	_anon20 spc;
	_anon20 mamb;
	_anon20 mdif;
	_anon20 mspc;
};

struct _anon29
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon30
{
	_anon25* p;
	_anon14* col;
	_anon14* tex;
	unsigned int num;
};

struct _anon31
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

struct _anon32
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

struct _anon33
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

struct _anon34
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon35
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

struct _anon36
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
	_anon20 argb;
};

struct _anon37
{
	_anon26 c;
	float r;
};

struct _anon38
{
	_anon26 c1;
	_anon26 c2;
	float r;
};

_anon19* sys;
_anon33 cam;
_anon4 _nj_screen_;
float BHD_ASPECT_Y;
float BHD_ASPECT_X;
unsigned int Ps2_rendertex_initflag;
float lcmat[16][0];
_anon0 eff[0];
unsigned int PS2_Render_tex_sub_flag;

void bhSetScreenFade(unsigned int argb, float ct);
void bhControlScreenFade();
void bhDrawScreenFade();
void bhInitScreenSaver();
void bhSetScreenSaver(unsigned int alpha, float ct);
void bhControlScreenSaver();
void bhDrawScreenSaver();
void bhControlCinesco();
void bhDrawCinesco();
void bhDrawScope();
void bhDrawScopeNumber(float px, float py, int num);
void bhDrawThermometer();
void bhDrawThermoNumber(float px, float py, int num, unsigned int argb);
void bhDrawFullScreenRenderTexture();
void bhDrawSmallScreenRenderTexture();

// 
// Start address: 0x26bac0
void bhSetScreenFade(unsigned int argb, float ct)
{
	// Line 95, Address: 0x26bac0, Func Offset: 0
	// Line 96, Address: 0x26bad8, Func Offset: 0x18
	// Line 97, Address: 0x26bae8, Func Offset: 0x28
	// Line 96, Address: 0x26baec, Func Offset: 0x2c
	// Line 97, Address: 0x26baf4, Func Offset: 0x34
	// Line 101, Address: 0x26bb60, Func Offset: 0xa0
	// Line 102, Address: 0x26bb68, Func Offset: 0xa8
	// Line 101, Address: 0x26bb78, Func Offset: 0xb8
	// Line 102, Address: 0x26bb80, Func Offset: 0xc0
	// Line 103, Address: 0x26bba0, Func Offset: 0xe0
	// Line 104, Address: 0x26bbb8, Func Offset: 0xf8
	// Line 108, Address: 0x26bbc0, Func Offset: 0x100
	// Line 104, Address: 0x26bbc4, Func Offset: 0x104
	// Line 105, Address: 0x26bbdc, Func Offset: 0x11c
	// Line 106, Address: 0x26bbfc, Func Offset: 0x13c
	// Line 107, Address: 0x26bc1c, Func Offset: 0x15c
	// Line 108, Address: 0x26bc38, Func Offset: 0x178
	// Line 109, Address: 0x26bc70, Func Offset: 0x1b0
	// Line 108, Address: 0x26bc78, Func Offset: 0x1b8
	// Line 109, Address: 0x26bc80, Func Offset: 0x1c0
	// Line 110, Address: 0x26bcb8, Func Offset: 0x1f8
	// Line 109, Address: 0x26bcc0, Func Offset: 0x200
	// Line 110, Address: 0x26bcc8, Func Offset: 0x208
	// Line 111, Address: 0x26bd00, Func Offset: 0x240
	// Line 110, Address: 0x26bd04, Func Offset: 0x244
	// Line 111, Address: 0x26bd0c, Func Offset: 0x24c
	// Line 112, Address: 0x26bd50, Func Offset: 0x290
	// Func End, Address: 0x26bd6c, Func Offset: 0x2ac
}

// 
// Start address: 0x26bd70
void bhControlScreenFade()
{
	float hkn;
	// Line 121, Address: 0x26bd70, Func Offset: 0
	// Line 122, Address: 0x26bdc0, Func Offset: 0x50
	// Line 123, Address: 0x26bdc4, Func Offset: 0x54
	// Line 124, Address: 0x26bdcc, Func Offset: 0x5c
	// Line 125, Address: 0x26bde8, Func Offset: 0x78
	// Line 126, Address: 0x26bdf0, Func Offset: 0x80
	// Line 125, Address: 0x26bdf4, Func Offset: 0x84
	// Line 126, Address: 0x26bdfc, Func Offset: 0x8c
	// Line 127, Address: 0x26be18, Func Offset: 0xa8
	// Line 128, Address: 0x26be38, Func Offset: 0xc8
	// Line 129, Address: 0x26be58, Func Offset: 0xe8
	// Line 130, Address: 0x26be74, Func Offset: 0x104
	// Line 132, Address: 0x26be7c, Func Offset: 0x10c
	// Line 131, Address: 0x26be84, Func Offset: 0x114
	// Line 132, Address: 0x26be88, Func Offset: 0x118
	// Line 133, Address: 0x26bebc, Func Offset: 0x14c
	// Line 134, Address: 0x26bf00, Func Offset: 0x190
	// Line 135, Address: 0x26bf44, Func Offset: 0x1d4
	// Line 136, Address: 0x26bf88, Func Offset: 0x218
	// Line 137, Address: 0x26bfac, Func Offset: 0x23c
	// Line 138, Address: 0x26bfd0, Func Offset: 0x260
	// Line 139, Address: 0x26bfd8, Func Offset: 0x268
	// Line 138, Address: 0x26bfdc, Func Offset: 0x26c
	// Line 139, Address: 0x26bfe4, Func Offset: 0x274
	// Line 140, Address: 0x26c000, Func Offset: 0x290
	// Line 141, Address: 0x26c020, Func Offset: 0x2b0
	// Line 142, Address: 0x26c040, Func Offset: 0x2d0
	// Line 146, Address: 0x26c060, Func Offset: 0x2f0
	// Func End, Address: 0x26c068, Func Offset: 0x2f8
}

// 
// Start address: 0x26c070
void bhDrawScreenFade()
{
	unsigned int argb;
	_anon14 col[4];
	_anon25 p[4];
	_anon30 p2c;
	// Line 153, Address: 0x26c070, Func Offset: 0
	// Line 158, Address: 0x26c080, Func Offset: 0x10
	// Line 159, Address: 0x26c090, Func Offset: 0x20
	// Line 164, Address: 0x26c09c, Func Offset: 0x2c
	// Line 165, Address: 0x26c0a4, Func Offset: 0x34
	// Line 168, Address: 0x26c0b0, Func Offset: 0x40
	// Line 167, Address: 0x26c0b8, Func Offset: 0x48
	// Line 166, Address: 0x26c0bc, Func Offset: 0x4c
	// Line 167, Address: 0x26c0c0, Func Offset: 0x50
	// Line 168, Address: 0x26c0c4, Func Offset: 0x54
	// Line 172, Address: 0x26c118, Func Offset: 0xa8
	// Line 168, Address: 0x26c11c, Func Offset: 0xac
	// Line 184, Address: 0x26c120, Func Offset: 0xb0
	// Line 178, Address: 0x26c12c, Func Offset: 0xbc
	// Line 172, Address: 0x26c130, Func Offset: 0xc0
	// Line 173, Address: 0x26c134, Func Offset: 0xc4
	// Line 181, Address: 0x26c138, Func Offset: 0xc8
	// Line 184, Address: 0x26c13c, Func Offset: 0xcc
	// Line 173, Address: 0x26c144, Func Offset: 0xd4
	// Line 174, Address: 0x26c148, Func Offset: 0xd8
	// Line 184, Address: 0x26c14c, Func Offset: 0xdc
	// Line 174, Address: 0x26c150, Func Offset: 0xe0
	// Line 175, Address: 0x26c154, Func Offset: 0xe4
	// Line 176, Address: 0x26c15c, Func Offset: 0xec
	// Line 177, Address: 0x26c160, Func Offset: 0xf0
	// Line 178, Address: 0x26c164, Func Offset: 0xf4
	// Line 179, Address: 0x26c168, Func Offset: 0xf8
	// Line 180, Address: 0x26c16c, Func Offset: 0xfc
	// Line 181, Address: 0x26c170, Func Offset: 0x100
	// Line 182, Address: 0x26c174, Func Offset: 0x104
	// Line 184, Address: 0x26c178, Func Offset: 0x108
	// Line 185, Address: 0x26c180, Func Offset: 0x110
	// Line 186, Address: 0x26c18c, Func Offset: 0x11c
	// Line 187, Address: 0x26c198, Func Offset: 0x128
	// Func End, Address: 0x26c1b0, Func Offset: 0x140
}

// 
// Start address: 0x26c1b0
void bhInitScreenSaver()
{
	// Line 281, Address: 0x26c1b0, Func Offset: 0
	// Line 282, Address: 0x26c1c8, Func Offset: 0x18
	// Line 283, Address: 0x26c1dc, Func Offset: 0x2c
	// Line 284, Address: 0x26c1f0, Func Offset: 0x40
	// Line 285, Address: 0x26c204, Func Offset: 0x54
	// Line 286, Address: 0x26c23c, Func Offset: 0x8c
	// Func End, Address: 0x26c244, Func Offset: 0x94
}

// 
// Start address: 0x26c250
void bhSetScreenSaver(unsigned int alpha, float ct)
{
	// Line 297, Address: 0x26c250, Func Offset: 0
	// Line 298, Address: 0x26c268, Func Offset: 0x18
	// Line 299, Address: 0x26c27c, Func Offset: 0x2c
	// Line 300, Address: 0x26c290, Func Offset: 0x40
	// Line 301, Address: 0x26c2ac, Func Offset: 0x5c
	// Line 302, Address: 0x26c2ec, Func Offset: 0x9c
	// Func End, Address: 0x26c2f4, Func Offset: 0xa4
}

// 
// Start address: 0x26c300
void bhControlScreenSaver()
{
	// Line 310, Address: 0x26c300, Func Offset: 0
	// Line 311, Address: 0x26c308, Func Offset: 0x8
	// Line 310, Address: 0x26c310, Func Offset: 0x10
	// Line 311, Address: 0x26c358, Func Offset: 0x58
	// Line 312, Address: 0x26c37c, Func Offset: 0x7c
	// Line 313, Address: 0x26c3b8, Func Offset: 0xb8
	// Line 314, Address: 0x26c3c8, Func Offset: 0xc8
	// Line 316, Address: 0x26c3e8, Func Offset: 0xe8
	// Func End, Address: 0x26c3f0, Func Offset: 0xf0
}

// 
// Start address: 0x26c3f0
void bhDrawScreenSaver()
{
	unsigned int argb;
	_anon29 pol[4];
	// Line 323, Address: 0x26c3f0, Func Offset: 0
	// Line 328, Address: 0x26c3f4, Func Offset: 0x4
	// Line 323, Address: 0x26c3f8, Func Offset: 0x8
	// Line 328, Address: 0x26c3fc, Func Offset: 0xc
	// Line 329, Address: 0x26c404, Func Offset: 0x14
	// Line 337, Address: 0x26c410, Func Offset: 0x20
	// Line 338, Address: 0x26c428, Func Offset: 0x38
	// Line 339, Address: 0x26c42c, Func Offset: 0x3c
	// Line 340, Address: 0x26c430, Func Offset: 0x40
	// Line 337, Address: 0x26c434, Func Offset: 0x44
	// Line 340, Address: 0x26c438, Func Offset: 0x48
	// Line 341, Address: 0x26c43c, Func Offset: 0x4c
	// Line 342, Address: 0x26c440, Func Offset: 0x50
	// Line 343, Address: 0x26c444, Func Offset: 0x54
	// Line 344, Address: 0x26c44c, Func Offset: 0x5c
	// Line 345, Address: 0x26c450, Func Offset: 0x60
	// Line 346, Address: 0x26c454, Func Offset: 0x64
	// Line 347, Address: 0x26c45c, Func Offset: 0x6c
	// Line 348, Address: 0x26c460, Func Offset: 0x70
	// Line 349, Address: 0x26c464, Func Offset: 0x74
	// Line 350, Address: 0x26c468, Func Offset: 0x78
	// Line 351, Address: 0x26c46c, Func Offset: 0x7c
	// Line 352, Address: 0x26c470, Func Offset: 0x80
	// Line 353, Address: 0x26c474, Func Offset: 0x84
	// Line 354, Address: 0x26c478, Func Offset: 0x88
	// Line 355, Address: 0x26c488, Func Offset: 0x98
	// Line 356, Address: 0x26c494, Func Offset: 0xa4
	// Line 357, Address: 0x26c4a0, Func Offset: 0xb0
	// Func End, Address: 0x26c4ac, Func Offset: 0xbc
}

// 
// Start address: 0x26c4b0
void bhControlCinesco()
{
	// Line 365, Address: 0x26c4b0, Func Offset: 0
	// Line 366, Address: 0x26c4e8, Func Offset: 0x38
	// Line 367, Address: 0x26c4f4, Func Offset: 0x44
	// Line 368, Address: 0x26c528, Func Offset: 0x78
	// Line 367, Address: 0x26c52c, Func Offset: 0x7c
	// Line 368, Address: 0x26c538, Func Offset: 0x88
	// Line 369, Address: 0x26c580, Func Offset: 0xd0
	// Func End, Address: 0x26c588, Func Offset: 0xd8
}

// 
// Start address: 0x26c590
void bhDrawCinesco()
{
	unsigned int argb;
	_anon14 col[4];
	_anon25 p[4];
	_anon30 p2c;
	// Line 376, Address: 0x26c590, Func Offset: 0
	// Line 382, Address: 0x26c5ac, Func Offset: 0x1c
	// Line 384, Address: 0x26c5c4, Func Offset: 0x34
	// Line 385, Address: 0x26c5d0, Func Offset: 0x40
	// Line 386, Address: 0x26c5dc, Func Offset: 0x4c
	// Line 387, Address: 0x26c5e4, Func Offset: 0x54
	// Line 391, Address: 0x26c5f0, Func Offset: 0x60
	// Line 389, Address: 0x26c5f8, Func Offset: 0x68
	// Line 388, Address: 0x26c5fc, Func Offset: 0x6c
	// Line 389, Address: 0x26c600, Func Offset: 0x70
	// Line 391, Address: 0x26c604, Func Offset: 0x74
	// Line 398, Address: 0x26c624, Func Offset: 0x94
	// Line 403, Address: 0x26c628, Func Offset: 0x98
	// Line 404, Address: 0x26c62c, Func Offset: 0x9c
	// Line 405, Address: 0x26c630, Func Offset: 0xa0
	// Line 398, Address: 0x26c634, Func Offset: 0xa4
	// Line 399, Address: 0x26c638, Func Offset: 0xa8
	// Line 410, Address: 0x26c63c, Func Offset: 0xac
	// Line 407, Address: 0x26c648, Func Offset: 0xb8
	// Line 399, Address: 0x26c64c, Func Offset: 0xbc
	// Line 400, Address: 0x26c650, Func Offset: 0xc0
	// Line 407, Address: 0x26c654, Func Offset: 0xc4
	// Line 409, Address: 0x26c658, Func Offset: 0xc8
	// Line 410, Address: 0x26c65c, Func Offset: 0xcc
	// Line 400, Address: 0x26c660, Func Offset: 0xd0
	// Line 401, Address: 0x26c664, Func Offset: 0xd4
	// Line 410, Address: 0x26c668, Func Offset: 0xd8
	// Line 401, Address: 0x26c670, Func Offset: 0xe0
	// Line 402, Address: 0x26c674, Func Offset: 0xe4
	// Line 403, Address: 0x26c678, Func Offset: 0xe8
	// Line 404, Address: 0x26c67c, Func Offset: 0xec
	// Line 405, Address: 0x26c680, Func Offset: 0xf0
	// Line 406, Address: 0x26c684, Func Offset: 0xf4
	// Line 407, Address: 0x26c688, Func Offset: 0xf8
	// Line 408, Address: 0x26c68c, Func Offset: 0xfc
	// Line 410, Address: 0x26c690, Func Offset: 0x100
	// Line 411, Address: 0x26c698, Func Offset: 0x108
	// Line 412, Address: 0x26c6a0, Func Offset: 0x110
	// Line 413, Address: 0x26c6a4, Func Offset: 0x114
	// Line 414, Address: 0x26c6ac, Func Offset: 0x11c
	// Line 415, Address: 0x26c6b0, Func Offset: 0x120
	// Line 416, Address: 0x26c6cc, Func Offset: 0x13c
	// Line 417, Address: 0x26c6d8, Func Offset: 0x148
	// Line 418, Address: 0x26c6e4, Func Offset: 0x154
	// Func End, Address: 0x26c704, Func Offset: 0x174
}

// 
// Start address: 0x26c710
void bhDrawScope()
{
	float bai;
	float px;
	int i;
	unsigned int argb;
	_anon14 uv[4];
	_anon14 col[4];
	_anon26 as;
	_anon26 ps;
	_anon25 p[4];
	_anon30 p2c;
	// Line 425, Address: 0x26c710, Func Offset: 0
	// Line 434, Address: 0x26c748, Func Offset: 0x38
	// Line 435, Address: 0x26c75c, Func Offset: 0x4c
	// Line 436, Address: 0x26c768, Func Offset: 0x58
	// Line 437, Address: 0x26c774, Func Offset: 0x64
	// Line 438, Address: 0x26c794, Func Offset: 0x84
	// Line 439, Address: 0x26c79c, Func Offset: 0x8c
	// Line 445, Address: 0x26c7a4, Func Offset: 0x94
	// Line 440, Address: 0x26c7a8, Func Offset: 0x98
	// Line 445, Address: 0x26c7ac, Func Offset: 0x9c
	// Line 440, Address: 0x26c7b0, Func Offset: 0xa0
	// Line 441, Address: 0x26c7b4, Func Offset: 0xa4
	// Line 442, Address: 0x26c7bc, Func Offset: 0xac
	// Line 445, Address: 0x26c7c0, Func Offset: 0xb0
	// Line 442, Address: 0x26c7c4, Func Offset: 0xb4
	// Line 445, Address: 0x26c7c8, Func Offset: 0xb8
	// Line 447, Address: 0x26c7f4, Func Offset: 0xe4
	// Line 446, Address: 0x26c7f8, Func Offset: 0xe8
	// Line 448, Address: 0x26c7fc, Func Offset: 0xec
	// Line 447, Address: 0x26c800, Func Offset: 0xf0
	// Line 449, Address: 0x26c804, Func Offset: 0xf4
	// Line 448, Address: 0x26c808, Func Offset: 0xf8
	// Line 449, Address: 0x26c80c, Func Offset: 0xfc
	// Line 451, Address: 0x26c810, Func Offset: 0x100
	// Line 450, Address: 0x26c814, Func Offset: 0x104
	// Line 451, Address: 0x26c818, Func Offset: 0x108
	// Line 452, Address: 0x26c81c, Func Offset: 0x10c
	// Line 453, Address: 0x26c824, Func Offset: 0x114
	// Line 452, Address: 0x26c828, Func Offset: 0x118
	// Line 454, Address: 0x26c82c, Func Offset: 0x11c
	// Line 453, Address: 0x26c830, Func Offset: 0x120
	// Line 454, Address: 0x26c834, Func Offset: 0x124
	// Line 455, Address: 0x26c838, Func Offset: 0x128
	// Line 456, Address: 0x26c840, Func Offset: 0x130
	// Line 455, Address: 0x26c844, Func Offset: 0x134
	// Line 457, Address: 0x26c848, Func Offset: 0x138
	// Line 456, Address: 0x26c84c, Func Offset: 0x13c
	// Line 457, Address: 0x26c850, Func Offset: 0x140
	// Line 458, Address: 0x26c854, Func Offset: 0x144
	// Line 461, Address: 0x26c870, Func Offset: 0x160
	// Line 462, Address: 0x26c878, Func Offset: 0x168
	// Line 463, Address: 0x26c87c, Func Offset: 0x16c
	// Line 464, Address: 0x26c880, Func Offset: 0x170
	// Line 466, Address: 0x26c884, Func Offset: 0x174
	// Line 465, Address: 0x26c88c, Func Offset: 0x17c
	// Line 466, Address: 0x26c890, Func Offset: 0x180
	// Line 467, Address: 0x26c894, Func Offset: 0x184
	// Line 468, Address: 0x26c89c, Func Offset: 0x18c
	// Line 469, Address: 0x26c8a4, Func Offset: 0x194
	// Line 470, Address: 0x26c8ac, Func Offset: 0x19c
	// Line 471, Address: 0x26c8b8, Func Offset: 0x1a8
	// Line 472, Address: 0x26c8c0, Func Offset: 0x1b0
	// Line 473, Address: 0x26c8c8, Func Offset: 0x1b8
	// Line 474, Address: 0x26c8cc, Func Offset: 0x1bc
	// Line 473, Address: 0x26c8d0, Func Offset: 0x1c0
	// Line 474, Address: 0x26c8d4, Func Offset: 0x1c4
	// Line 475, Address: 0x26c8dc, Func Offset: 0x1cc
	// Line 476, Address: 0x26c8e4, Func Offset: 0x1d4
	// Line 477, Address: 0x26c8e8, Func Offset: 0x1d8
	// Line 478, Address: 0x26c8ec, Func Offset: 0x1dc
	// Line 479, Address: 0x26c8f4, Func Offset: 0x1e4
	// Line 480, Address: 0x26c8f8, Func Offset: 0x1e8
	// Line 481, Address: 0x26c8fc, Func Offset: 0x1ec
	// Line 484, Address: 0x26c91c, Func Offset: 0x20c
	// Line 483, Address: 0x26c924, Func Offset: 0x214
	// Line 484, Address: 0x26c928, Func Offset: 0x218
	// Line 485, Address: 0x26c92c, Func Offset: 0x21c
	// Line 486, Address: 0x26c938, Func Offset: 0x228
	// Line 487, Address: 0x26c940, Func Offset: 0x230
	// Line 488, Address: 0x26c948, Func Offset: 0x238
	// Line 489, Address: 0x26c954, Func Offset: 0x244
	// Line 490, Address: 0x26c95c, Func Offset: 0x24c
	// Line 491, Address: 0x26c964, Func Offset: 0x254
	// Line 492, Address: 0x26c96c, Func Offset: 0x25c
	// Line 493, Address: 0x26c974, Func Offset: 0x264
	// Line 494, Address: 0x26c988, Func Offset: 0x278
	// Line 495, Address: 0x26c98c, Func Offset: 0x27c
	// Line 496, Address: 0x26c994, Func Offset: 0x284
	// Line 497, Address: 0x26c99c, Func Offset: 0x28c
	// Line 496, Address: 0x26c9a4, Func Offset: 0x294
	// Line 497, Address: 0x26c9a8, Func Offset: 0x298
	// Line 498, Address: 0x26c9b0, Func Offset: 0x2a0
	// Line 499, Address: 0x26c9bc, Func Offset: 0x2ac
	// Line 498, Address: 0x26c9c4, Func Offset: 0x2b4
	// Line 500, Address: 0x26c9c8, Func Offset: 0x2b8
	// Line 501, Address: 0x26c9cc, Func Offset: 0x2bc
	// Line 502, Address: 0x26c9d0, Func Offset: 0x2c0
	// Line 499, Address: 0x26c9d4, Func Offset: 0x2c4
	// Line 498, Address: 0x26c9dc, Func Offset: 0x2cc
	// Line 499, Address: 0x26c9e0, Func Offset: 0x2d0
	// Line 502, Address: 0x26c9e8, Func Offset: 0x2d8
	// Line 499, Address: 0x26c9f0, Func Offset: 0x2e0
	// Line 500, Address: 0x26c9f8, Func Offset: 0x2e8
	// Line 502, Address: 0x26c9fc, Func Offset: 0x2ec
	// Line 503, Address: 0x26ca04, Func Offset: 0x2f4
	// Line 505, Address: 0x26ca10, Func Offset: 0x300
	// Line 504, Address: 0x26ca14, Func Offset: 0x304
	// Line 503, Address: 0x26ca20, Func Offset: 0x310
	// Line 506, Address: 0x26ca24, Func Offset: 0x314
	// Line 507, Address: 0x26ca28, Func Offset: 0x318
	// Line 503, Address: 0x26ca2c, Func Offset: 0x31c
	// Line 504, Address: 0x26ca30, Func Offset: 0x320
	// Line 507, Address: 0x26ca34, Func Offset: 0x324
	// Line 504, Address: 0x26ca3c, Func Offset: 0x32c
	// Line 505, Address: 0x26ca44, Func Offset: 0x334
	// Line 507, Address: 0x26ca48, Func Offset: 0x338
	// Line 508, Address: 0x26ca50, Func Offset: 0x340
	// Line 510, Address: 0x26ca5c, Func Offset: 0x34c
	// Line 509, Address: 0x26ca60, Func Offset: 0x350
	// Line 508, Address: 0x26ca6c, Func Offset: 0x35c
	// Line 511, Address: 0x26ca70, Func Offset: 0x360
	// Line 512, Address: 0x26ca74, Func Offset: 0x364
	// Line 508, Address: 0x26ca78, Func Offset: 0x368
	// Line 509, Address: 0x26ca7c, Func Offset: 0x36c
	// Line 512, Address: 0x26ca80, Func Offset: 0x370
	// Line 509, Address: 0x26ca88, Func Offset: 0x378
	// Line 510, Address: 0x26ca90, Func Offset: 0x380
	// Line 512, Address: 0x26ca94, Func Offset: 0x384
	// Line 513, Address: 0x26ca9c, Func Offset: 0x38c
	// Line 515, Address: 0x26caa8, Func Offset: 0x398
	// Line 514, Address: 0x26caac, Func Offset: 0x39c
	// Line 513, Address: 0x26cab0, Func Offset: 0x3a0
	// Line 515, Address: 0x26cab4, Func Offset: 0x3a4
	// Line 513, Address: 0x26cab8, Func Offset: 0x3a8
	// Line 514, Address: 0x26cabc, Func Offset: 0x3ac
	// Line 515, Address: 0x26cac4, Func Offset: 0x3b4
	// Line 514, Address: 0x26cad0, Func Offset: 0x3c0
	// Line 515, Address: 0x26cad4, Func Offset: 0x3c4
	// Line 516, Address: 0x26cae4, Func Offset: 0x3d4
	// Line 517, Address: 0x26caf0, Func Offset: 0x3e0
	// Line 520, Address: 0x26cb00, Func Offset: 0x3f0
	// Line 519, Address: 0x26cb08, Func Offset: 0x3f8
	// Line 520, Address: 0x26cb0c, Func Offset: 0x3fc
	// Line 521, Address: 0x26cb10, Func Offset: 0x400
	// Line 522, Address: 0x26cb1c, Func Offset: 0x40c
	// Line 523, Address: 0x26cb24, Func Offset: 0x414
	// Line 524, Address: 0x26cb2c, Func Offset: 0x41c
	// Line 525, Address: 0x26cb38, Func Offset: 0x428
	// Line 526, Address: 0x26cb40, Func Offset: 0x430
	// Line 527, Address: 0x26cb48, Func Offset: 0x438
	// Line 528, Address: 0x26cb50, Func Offset: 0x440
	// Line 529, Address: 0x26cb58, Func Offset: 0x448
	// Line 530, Address: 0x26cb70, Func Offset: 0x460
	// Line 531, Address: 0x26cb74, Func Offset: 0x464
	// Line 532, Address: 0x26cb7c, Func Offset: 0x46c
	// Line 533, Address: 0x26cb80, Func Offset: 0x470
	// Line 532, Address: 0x26cb88, Func Offset: 0x478
	// Line 533, Address: 0x26cb8c, Func Offset: 0x47c
	// Line 534, Address: 0x26cb94, Func Offset: 0x484
	// Line 536, Address: 0x26cba0, Func Offset: 0x490
	// Line 535, Address: 0x26cba4, Func Offset: 0x494
	// Line 534, Address: 0x26cbb0, Func Offset: 0x4a0
	// Line 535, Address: 0x26cbb4, Func Offset: 0x4a4
	// Line 537, Address: 0x26cbb8, Func Offset: 0x4a8
	// Line 534, Address: 0x26cbbc, Func Offset: 0x4ac
	// Line 535, Address: 0x26cbc0, Func Offset: 0x4b0
	// Line 538, Address: 0x26cbc4, Func Offset: 0x4b4
	// Line 535, Address: 0x26cbd0, Func Offset: 0x4c0
	// Line 536, Address: 0x26cbd8, Func Offset: 0x4c8
	// Line 538, Address: 0x26cbdc, Func Offset: 0x4cc
	// Line 539, Address: 0x26cbe4, Func Offset: 0x4d4
	// Line 541, Address: 0x26cbf0, Func Offset: 0x4e0
	// Line 540, Address: 0x26cbf4, Func Offset: 0x4e4
	// Line 539, Address: 0x26cc00, Func Offset: 0x4f0
	// Line 542, Address: 0x26cc04, Func Offset: 0x4f4
	// Line 543, Address: 0x26cc08, Func Offset: 0x4f8
	// Line 539, Address: 0x26cc0c, Func Offset: 0x4fc
	// Line 540, Address: 0x26cc10, Func Offset: 0x500
	// Line 543, Address: 0x26cc14, Func Offset: 0x504
	// Line 540, Address: 0x26cc1c, Func Offset: 0x50c
	// Line 541, Address: 0x26cc24, Func Offset: 0x514
	// Line 543, Address: 0x26cc28, Func Offset: 0x518
	// Line 544, Address: 0x26cc30, Func Offset: 0x520
	// Line 546, Address: 0x26cc3c, Func Offset: 0x52c
	// Line 545, Address: 0x26cc40, Func Offset: 0x530
	// Line 544, Address: 0x26cc4c, Func Offset: 0x53c
	// Line 547, Address: 0x26cc50, Func Offset: 0x540
	// Line 548, Address: 0x26cc54, Func Offset: 0x544
	// Line 544, Address: 0x26cc58, Func Offset: 0x548
	// Line 545, Address: 0x26cc5c, Func Offset: 0x54c
	// Line 548, Address: 0x26cc60, Func Offset: 0x550
	// Line 545, Address: 0x26cc68, Func Offset: 0x558
	// Line 546, Address: 0x26cc70, Func Offset: 0x560
	// Line 548, Address: 0x26cc74, Func Offset: 0x564
	// Line 549, Address: 0x26cc7c, Func Offset: 0x56c
	// Line 551, Address: 0x26cc88, Func Offset: 0x578
	// Line 550, Address: 0x26cc8c, Func Offset: 0x57c
	// Line 549, Address: 0x26cc90, Func Offset: 0x580
	// Line 551, Address: 0x26cc94, Func Offset: 0x584
	// Line 549, Address: 0x26cc98, Func Offset: 0x588
	// Line 550, Address: 0x26cc9c, Func Offset: 0x58c
	// Line 551, Address: 0x26cca4, Func Offset: 0x594
	// Line 550, Address: 0x26ccb0, Func Offset: 0x5a0
	// Line 551, Address: 0x26ccb4, Func Offset: 0x5a4
	// Line 552, Address: 0x26ccc4, Func Offset: 0x5b4
	// Line 553, Address: 0x26ccd0, Func Offset: 0x5c0
	// Line 555, Address: 0x26cce0, Func Offset: 0x5d0
	// Line 557, Address: 0x26cce8, Func Offset: 0x5d8
	// Line 559, Address: 0x26ccfc, Func Offset: 0x5ec
	// Line 558, Address: 0x26cd04, Func Offset: 0x5f4
	// Line 559, Address: 0x26cd0c, Func Offset: 0x5fc
	// Line 560, Address: 0x26cd20, Func Offset: 0x610
	// Line 559, Address: 0x26cd24, Func Offset: 0x614
	// Line 558, Address: 0x26cd28, Func Offset: 0x618
	// Line 559, Address: 0x26cd2c, Func Offset: 0x61c
	// Line 560, Address: 0x26cd54, Func Offset: 0x644
	// Line 561, Address: 0x26cd7c, Func Offset: 0x66c
	// Line 562, Address: 0x26cd84, Func Offset: 0x674
	// Line 561, Address: 0x26cd88, Func Offset: 0x678
	// Line 562, Address: 0x26cd8c, Func Offset: 0x67c
	// Line 563, Address: 0x26cdcc, Func Offset: 0x6bc
	// Line 564, Address: 0x26cdd4, Func Offset: 0x6c4
	// Line 566, Address: 0x26ce08, Func Offset: 0x6f8
	// Line 567, Address: 0x26ce14, Func Offset: 0x704
	// Line 568, Address: 0x26ce20, Func Offset: 0x710
	// Func End, Address: 0x26ce5c, Func Offset: 0x74c
}

// 
// Start address: 0x26ce60
void bhDrawScopeNumber(float px, float py, int num)
{
	_anon14 uv[4];
	_anon14 col[4];
	_anon25 p[4];
	_anon30 p2c;
	short uv_tab[8][18];
	// Line 572, Address: 0x26ce60, Func Offset: 0
	// Line 599, Address: 0x26ce64, Func Offset: 0x4
	// Line 572, Address: 0x26ce68, Func Offset: 0x8
	// Line 599, Address: 0x26ce6c, Func Offset: 0xc
	// Line 600, Address: 0x26ce70, Func Offset: 0x10
	// Line 601, Address: 0x26ce78, Func Offset: 0x18
	// Line 602, Address: 0x26ce80, Func Offset: 0x20
	// Line 604, Address: 0x26ce88, Func Offset: 0x28
	// Line 605, Address: 0x26ce90, Func Offset: 0x30
	// Line 606, Address: 0x26ce94, Func Offset: 0x34
	// Line 608, Address: 0x26ce98, Func Offset: 0x38
	// Line 607, Address: 0x26ce9c, Func Offset: 0x3c
	// Line 608, Address: 0x26cea0, Func Offset: 0x40
	// Line 624, Address: 0x26ceb0, Func Offset: 0x50
	// Line 609, Address: 0x26ceb4, Func Offset: 0x54
	// Line 608, Address: 0x26cec0, Func Offset: 0x60
	// Line 609, Address: 0x26cec4, Func Offset: 0x64
	// Line 610, Address: 0x26cec8, Func Offset: 0x68
	// Line 609, Address: 0x26ced4, Func Offset: 0x74
	// Line 610, Address: 0x26ced8, Func Offset: 0x78
	// Line 611, Address: 0x26cedc, Func Offset: 0x7c
	// Line 610, Address: 0x26cee4, Func Offset: 0x84
	// Line 611, Address: 0x26cee8, Func Offset: 0x88
	// Line 610, Address: 0x26ceec, Func Offset: 0x8c
	// Line 611, Address: 0x26cef0, Func Offset: 0x90
	// Line 612, Address: 0x26cef4, Func Offset: 0x94
	// Line 611, Address: 0x26cf00, Func Offset: 0xa0
	// Line 612, Address: 0x26cf04, Func Offset: 0xa4
	// Line 613, Address: 0x26cf08, Func Offset: 0xa8
	// Line 612, Address: 0x26cf10, Func Offset: 0xb0
	// Line 613, Address: 0x26cf14, Func Offset: 0xb4
	// Line 612, Address: 0x26cf18, Func Offset: 0xb8
	// Line 613, Address: 0x26cf1c, Func Offset: 0xbc
	// Line 614, Address: 0x26cf20, Func Offset: 0xc0
	// Line 613, Address: 0x26cf28, Func Offset: 0xc8
	// Line 614, Address: 0x26cf2c, Func Offset: 0xcc
	// Line 613, Address: 0x26cf30, Func Offset: 0xd0
	// Line 614, Address: 0x26cf34, Func Offset: 0xd4
	// Line 615, Address: 0x26cf38, Func Offset: 0xd8
	// Line 614, Address: 0x26cf40, Func Offset: 0xe0
	// Line 615, Address: 0x26cf44, Func Offset: 0xe4
	// Line 624, Address: 0x26cf4c, Func Offset: 0xec
	// Line 618, Address: 0x26cf50, Func Offset: 0xf0
	// Line 616, Address: 0x26cf58, Func Offset: 0xf8
	// Line 618, Address: 0x26cf5c, Func Offset: 0xfc
	// Line 617, Address: 0x26cf60, Func Offset: 0x100
	// Line 624, Address: 0x26cf64, Func Offset: 0x104
	// Line 615, Address: 0x26cf68, Func Offset: 0x108
	// Line 621, Address: 0x26cf6c, Func Offset: 0x10c
	// Line 618, Address: 0x26cf70, Func Offset: 0x110
	// Line 619, Address: 0x26cf74, Func Offset: 0x114
	// Line 620, Address: 0x26cf78, Func Offset: 0x118
	// Line 621, Address: 0x26cf7c, Func Offset: 0x11c
	// Line 622, Address: 0x26cf80, Func Offset: 0x120
	// Line 624, Address: 0x26cf84, Func Offset: 0x124
	// Line 615, Address: 0x26cf8c, Func Offset: 0x12c
	// Line 624, Address: 0x26cf90, Func Offset: 0x130
	// Line 623, Address: 0x26cf94, Func Offset: 0x134
	// Line 624, Address: 0x26cf98, Func Offset: 0x138
	// Line 625, Address: 0x26cfa0, Func Offset: 0x140
	// Func End, Address: 0x26cfac, Func Offset: 0x14c
}

// 
// Start address: 0x26cfb0
void bhDrawThermometer()
{
	float py;
	float px;
	unsigned int argb;
	_anon14 uv[4];
	_anon14 col[4];
	_anon25 p[4];
	_anon30 p2c;
	int ten;
	// Line 632, Address: 0x26cfb0, Func Offset: 0
	// Line 641, Address: 0x26cfdc, Func Offset: 0x2c
	// Line 642, Address: 0x26cfec, Func Offset: 0x3c
	// Line 643, Address: 0x26cff8, Func Offset: 0x48
	// Line 644, Address: 0x26d010, Func Offset: 0x60
	// Line 645, Address: 0x26d028, Func Offset: 0x78
	// Line 646, Address: 0x26d030, Func Offset: 0x80
	// Line 647, Address: 0x26d038, Func Offset: 0x88
	// Line 648, Address: 0x26d040, Func Offset: 0x90
	// Line 651, Address: 0x26d048, Func Offset: 0x98
	// Line 652, Address: 0x26d04c, Func Offset: 0x9c
	// Line 651, Address: 0x26d050, Func Offset: 0xa0
	// Line 652, Address: 0x26d054, Func Offset: 0xa4
	// Line 653, Address: 0x26d058, Func Offset: 0xa8
	// Line 654, Address: 0x26d060, Func Offset: 0xb0
	// Line 656, Address: 0x26d068, Func Offset: 0xb8
	// Line 655, Address: 0x26d06c, Func Offset: 0xbc
	// Line 657, Address: 0x26d070, Func Offset: 0xc0
	// Line 656, Address: 0x26d078, Func Offset: 0xc8
	// Line 658, Address: 0x26d07c, Func Offset: 0xcc
	// Line 657, Address: 0x26d080, Func Offset: 0xd0
	// Line 659, Address: 0x26d084, Func Offset: 0xd4
	// Line 658, Address: 0x26d088, Func Offset: 0xd8
	// Line 659, Address: 0x26d08c, Func Offset: 0xdc
	// Line 660, Address: 0x26d090, Func Offset: 0xe0
	// Line 661, Address: 0x26d098, Func Offset: 0xe8
	// Line 660, Address: 0x26d09c, Func Offset: 0xec
	// Line 662, Address: 0x26d0a0, Func Offset: 0xf0
	// Line 661, Address: 0x26d0a4, Func Offset: 0xf4
	// Line 662, Address: 0x26d0a8, Func Offset: 0xf8
	// Line 663, Address: 0x26d0ac, Func Offset: 0xfc
	// Line 664, Address: 0x26d0b0, Func Offset: 0x100
	// Line 663, Address: 0x26d0b4, Func Offset: 0x104
	// Line 664, Address: 0x26d0b8, Func Offset: 0x108
	// Line 665, Address: 0x26d0c0, Func Offset: 0x110
	// Line 666, Address: 0x26d0cc, Func Offset: 0x11c
	// Line 667, Address: 0x26d0d4, Func Offset: 0x124
	// Line 668, Address: 0x26d0dc, Func Offset: 0x12c
	// Line 671, Address: 0x26d0e8, Func Offset: 0x138
	// Line 669, Address: 0x26d0ec, Func Offset: 0x13c
	// Line 671, Address: 0x26d0f0, Func Offset: 0x140
	// Line 669, Address: 0x26d0f8, Func Offset: 0x148
	// Line 670, Address: 0x26d0fc, Func Offset: 0x14c
	// Line 671, Address: 0x26d100, Func Offset: 0x150
	// Line 670, Address: 0x26d10c, Func Offset: 0x15c
	// Line 671, Address: 0x26d110, Func Offset: 0x160
	// Line 673, Address: 0x26d118, Func Offset: 0x168
	// Line 675, Address: 0x26d138, Func Offset: 0x188
	// Line 676, Address: 0x26d164, Func Offset: 0x1b4
	// Line 677, Address: 0x26d16c, Func Offset: 0x1bc
	// Line 681, Address: 0x26d170, Func Offset: 0x1c0
	// Line 682, Address: 0x26d174, Func Offset: 0x1c4
	// Line 676, Address: 0x26d178, Func Offset: 0x1c8
	// Line 678, Address: 0x26d188, Func Offset: 0x1d8
	// Line 679, Address: 0x26d190, Func Offset: 0x1e0
	// Line 680, Address: 0x26d198, Func Offset: 0x1e8
	// Line 681, Address: 0x26d1a0, Func Offset: 0x1f0
	// Line 683, Address: 0x26d1a4, Func Offset: 0x1f4
	// Line 682, Address: 0x26d1a8, Func Offset: 0x1f8
	// Line 683, Address: 0x26d1ac, Func Offset: 0x1fc
	// Line 684, Address: 0x26d1b0, Func Offset: 0x200
	// Line 685, Address: 0x26d1b4, Func Offset: 0x204
	// Line 686, Address: 0x26d1b8, Func Offset: 0x208
	// Line 687, Address: 0x26d1c0, Func Offset: 0x210
	// Line 688, Address: 0x26d1c4, Func Offset: 0x214
	// Line 689, Address: 0x26d1c8, Func Offset: 0x218
	// Line 690, Address: 0x26d1cc, Func Offset: 0x21c
	// Line 689, Address: 0x26d1d0, Func Offset: 0x220
	// Line 690, Address: 0x26d1d4, Func Offset: 0x224
	// Line 691, Address: 0x26d1dc, Func Offset: 0x22c
	// Line 692, Address: 0x26d1e8, Func Offset: 0x238
	// Line 693, Address: 0x26d1f0, Func Offset: 0x240
	// Line 694, Address: 0x26d1f8, Func Offset: 0x248
	// Line 695, Address: 0x26d204, Func Offset: 0x254
	// Line 697, Address: 0x26d208, Func Offset: 0x258
	// Line 696, Address: 0x26d220, Func Offset: 0x270
	// Line 697, Address: 0x26d224, Func Offset: 0x274
	// Line 699, Address: 0x26d22c, Func Offset: 0x27c
	// Line 701, Address: 0x26d24c, Func Offset: 0x29c
	// Line 702, Address: 0x26d250, Func Offset: 0x2a0
	// Line 701, Address: 0x26d254, Func Offset: 0x2a4
	// Line 702, Address: 0x26d258, Func Offset: 0x2a8
	// Line 703, Address: 0x26d25c, Func Offset: 0x2ac
	// Line 704, Address: 0x26d264, Func Offset: 0x2b4
	// Line 705, Address: 0x26d26c, Func Offset: 0x2bc
	// Line 707, Address: 0x26d278, Func Offset: 0x2c8
	// Line 706, Address: 0x26d27c, Func Offset: 0x2cc
	// Line 708, Address: 0x26d280, Func Offset: 0x2d0
	// Line 707, Address: 0x26d284, Func Offset: 0x2d4
	// Line 709, Address: 0x26d288, Func Offset: 0x2d8
	// Line 708, Address: 0x26d28c, Func Offset: 0x2dc
	// Line 709, Address: 0x26d290, Func Offset: 0x2e0
	// Line 710, Address: 0x26d294, Func Offset: 0x2e4
	// Line 711, Address: 0x26d298, Func Offset: 0x2e8
	// Line 712, Address: 0x26d29c, Func Offset: 0x2ec
	// Line 713, Address: 0x26d2a4, Func Offset: 0x2f4
	// Line 715, Address: 0x26d2a8, Func Offset: 0x2f8
	// Line 716, Address: 0x26d2b0, Func Offset: 0x300
	// Line 717, Address: 0x26d2b8, Func Offset: 0x308
	// Line 718, Address: 0x26d2bc, Func Offset: 0x30c
	// Line 717, Address: 0x26d2c0, Func Offset: 0x310
	// Line 719, Address: 0x26d2c4, Func Offset: 0x314
	// Line 718, Address: 0x26d2c8, Func Offset: 0x318
	// Line 719, Address: 0x26d2cc, Func Offset: 0x31c
	// Line 720, Address: 0x26d2d0, Func Offset: 0x320
	// Line 721, Address: 0x26d2d4, Func Offset: 0x324
	// Line 722, Address: 0x26d2d8, Func Offset: 0x328
	// Line 723, Address: 0x26d2e0, Func Offset: 0x330
	// Line 724, Address: 0x26d2e4, Func Offset: 0x334
	// Line 726, Address: 0x26d2e8, Func Offset: 0x338
	// Line 731, Address: 0x26d300, Func Offset: 0x350
	// Line 726, Address: 0x26d304, Func Offset: 0x354
	// Line 727, Address: 0x26d310, Func Offset: 0x360
	// Line 726, Address: 0x26d314, Func Offset: 0x364
	// Line 728, Address: 0x26d318, Func Offset: 0x368
	// Line 734, Address: 0x26d31c, Func Offset: 0x36c
	// Line 726, Address: 0x26d324, Func Offset: 0x374
	// Line 727, Address: 0x26d328, Func Offset: 0x378
	// Line 726, Address: 0x26d330, Func Offset: 0x380
	// Line 734, Address: 0x26d334, Func Offset: 0x384
	// Line 727, Address: 0x26d340, Func Offset: 0x390
	// Line 734, Address: 0x26d344, Func Offset: 0x394
	// Line 726, Address: 0x26d348, Func Offset: 0x398
	// Line 727, Address: 0x26d34c, Func Offset: 0x39c
	// Line 731, Address: 0x26d350, Func Offset: 0x3a0
	// Line 727, Address: 0x26d354, Func Offset: 0x3a4
	// Line 728, Address: 0x26d358, Func Offset: 0x3a8
	// Line 731, Address: 0x26d35c, Func Offset: 0x3ac
	// Line 728, Address: 0x26d360, Func Offset: 0x3b0
	// Line 734, Address: 0x26d368, Func Offset: 0x3b8
	// Line 728, Address: 0x26d36c, Func Offset: 0x3bc
	// Line 729, Address: 0x26d380, Func Offset: 0x3d0
	// Line 730, Address: 0x26d388, Func Offset: 0x3d8
	// Line 731, Address: 0x26d3a8, Func Offset: 0x3f8
	// Line 732, Address: 0x26d3b0, Func Offset: 0x400
	// Line 734, Address: 0x26d3cc, Func Offset: 0x41c
	// Line 738, Address: 0x26d3d4, Func Offset: 0x424
	// Line 736, Address: 0x26d3dc, Func Offset: 0x42c
	// Line 738, Address: 0x26d3e4, Func Offset: 0x434
	// Line 739, Address: 0x26d400, Func Offset: 0x450
	// Line 740, Address: 0x26d408, Func Offset: 0x458
	// Line 742, Address: 0x26d428, Func Offset: 0x478
	// Line 741, Address: 0x26d430, Func Offset: 0x480
	// Line 742, Address: 0x26d438, Func Offset: 0x488
	// Line 743, Address: 0x26d458, Func Offset: 0x4a8
	// Line 744, Address: 0x26d460, Func Offset: 0x4b0
	// Line 746, Address: 0x26d47c, Func Offset: 0x4cc
	// Line 745, Address: 0x26d484, Func Offset: 0x4d4
	// Line 746, Address: 0x26d48c, Func Offset: 0x4dc
	// Line 747, Address: 0x26d4ac, Func Offset: 0x4fc
	// Line 748, Address: 0x26d4b4, Func Offset: 0x504
	// Line 750, Address: 0x26d4d0, Func Offset: 0x520
	// Line 751, Address: 0x26d4dc, Func Offset: 0x52c
	// Line 752, Address: 0x26d4e8, Func Offset: 0x538
	// Func End, Address: 0x26d51c, Func Offset: 0x56c
}

// 
// Start address: 0x26d520
void bhDrawThermoNumber(float px, float py, int num, unsigned int argb)
{
	_anon14 uv[4];
	_anon14 col[4];
	_anon25 p[4];
	_anon30 p2c;
	short uv_tab[8][10];
	// Line 755, Address: 0x26d520, Func Offset: 0
	// Line 773, Address: 0x26d524, Func Offset: 0x4
	// Line 755, Address: 0x26d528, Func Offset: 0x8
	// Line 773, Address: 0x26d52c, Func Offset: 0xc
	// Line 774, Address: 0x26d530, Func Offset: 0x10
	// Line 775, Address: 0x26d538, Func Offset: 0x18
	// Line 776, Address: 0x26d540, Func Offset: 0x20
	// Line 781, Address: 0x26d544, Func Offset: 0x24
	// Line 777, Address: 0x26d548, Func Offset: 0x28
	// Line 776, Address: 0x26d54c, Func Offset: 0x2c
	// Line 778, Address: 0x26d550, Func Offset: 0x30
	// Line 779, Address: 0x26d554, Func Offset: 0x34
	// Line 780, Address: 0x26d558, Func Offset: 0x38
	// Line 781, Address: 0x26d55c, Func Offset: 0x3c
	// Line 797, Address: 0x26d56c, Func Offset: 0x4c
	// Line 782, Address: 0x26d570, Func Offset: 0x50
	// Line 781, Address: 0x26d57c, Func Offset: 0x5c
	// Line 782, Address: 0x26d580, Func Offset: 0x60
	// Line 783, Address: 0x26d584, Func Offset: 0x64
	// Line 782, Address: 0x26d590, Func Offset: 0x70
	// Line 783, Address: 0x26d594, Func Offset: 0x74
	// Line 784, Address: 0x26d598, Func Offset: 0x78
	// Line 783, Address: 0x26d5a0, Func Offset: 0x80
	// Line 784, Address: 0x26d5a4, Func Offset: 0x84
	// Line 783, Address: 0x26d5a8, Func Offset: 0x88
	// Line 784, Address: 0x26d5ac, Func Offset: 0x8c
	// Line 785, Address: 0x26d5b0, Func Offset: 0x90
	// Line 784, Address: 0x26d5bc, Func Offset: 0x9c
	// Line 785, Address: 0x26d5c0, Func Offset: 0xa0
	// Line 786, Address: 0x26d5c4, Func Offset: 0xa4
	// Line 785, Address: 0x26d5cc, Func Offset: 0xac
	// Line 786, Address: 0x26d5d0, Func Offset: 0xb0
	// Line 785, Address: 0x26d5d4, Func Offset: 0xb4
	// Line 786, Address: 0x26d5d8, Func Offset: 0xb8
	// Line 787, Address: 0x26d5dc, Func Offset: 0xbc
	// Line 786, Address: 0x26d5e4, Func Offset: 0xc4
	// Line 787, Address: 0x26d5e8, Func Offset: 0xc8
	// Line 786, Address: 0x26d5ec, Func Offset: 0xcc
	// Line 787, Address: 0x26d5f0, Func Offset: 0xd0
	// Line 788, Address: 0x26d5f4, Func Offset: 0xd4
	// Line 787, Address: 0x26d600, Func Offset: 0xe0
	// Line 788, Address: 0x26d604, Func Offset: 0xe4
	// Line 794, Address: 0x26d608, Func Offset: 0xe8
	// Line 791, Address: 0x26d60c, Func Offset: 0xec
	// Line 789, Address: 0x26d614, Func Offset: 0xf4
	// Line 797, Address: 0x26d618, Func Offset: 0xf8
	// Line 788, Address: 0x26d61c, Func Offset: 0xfc
	// Line 791, Address: 0x26d620, Func Offset: 0x100
	// Line 790, Address: 0x26d624, Func Offset: 0x104
	// Line 788, Address: 0x26d628, Func Offset: 0x108
	// Line 797, Address: 0x26d62c, Func Offset: 0x10c
	// Line 791, Address: 0x26d630, Func Offset: 0x110
	// Line 792, Address: 0x26d634, Func Offset: 0x114
	// Line 793, Address: 0x26d638, Func Offset: 0x118
	// Line 794, Address: 0x26d63c, Func Offset: 0x11c
	// Line 797, Address: 0x26d640, Func Offset: 0x120
	// Line 794, Address: 0x26d644, Func Offset: 0x124
	// Line 795, Address: 0x26d64c, Func Offset: 0x12c
	// Line 797, Address: 0x26d650, Func Offset: 0x130
	// Line 796, Address: 0x26d654, Func Offset: 0x134
	// Line 797, Address: 0x26d658, Func Offset: 0x138
	// Line 798, Address: 0x26d664, Func Offset: 0x144
	// Func End, Address: 0x26d670, Func Offset: 0x150
}

// 
// Start address: 0x26d670
void bhDrawFullScreenRenderTexture()
{
	_anon4 scr_tex;
	int y1;
	int y;
	_anon5 tvh[32];
	// Line 805, Address: 0x26d670, Func Offset: 0
	// Line 810, Address: 0x26d698, Func Offset: 0x28
	// Line 811, Address: 0x26d6a4, Func Offset: 0x34
	// Line 812, Address: 0x26d6b0, Func Offset: 0x40
	// Line 813, Address: 0x26d6c4, Func Offset: 0x54
	// Line 812, Address: 0x26d6c8, Func Offset: 0x58
	// Line 813, Address: 0x26d6cc, Func Offset: 0x5c
	// Line 814, Address: 0x26d6d0, Func Offset: 0x60
	// Line 812, Address: 0x26d6d8, Func Offset: 0x68
	// Line 813, Address: 0x26d6dc, Func Offset: 0x6c
	// Line 815, Address: 0x26d6e0, Func Offset: 0x70
	// Line 814, Address: 0x26d6e8, Func Offset: 0x78
	// Line 819, Address: 0x26d6ec, Func Offset: 0x7c
	// Line 815, Address: 0x26d6f4, Func Offset: 0x84
	// Line 821, Address: 0x26d6f8, Func Offset: 0x88
	// Line 822, Address: 0x26d704, Func Offset: 0x94
	// Line 824, Address: 0x26d70c, Func Offset: 0x9c
	// Line 825, Address: 0x26d714, Func Offset: 0xa4
	// Line 826, Address: 0x26d71c, Func Offset: 0xac
	// Line 828, Address: 0x26d724, Func Offset: 0xb4
	// Line 829, Address: 0x26d73c, Func Offset: 0xcc
	// Line 830, Address: 0x26d744, Func Offset: 0xd4
	// Line 831, Address: 0x26d74c, Func Offset: 0xdc
	// Line 832, Address: 0x26d754, Func Offset: 0xe4
	// Line 833, Address: 0x26d758, Func Offset: 0xe8
	// Line 839, Address: 0x26d764, Func Offset: 0xf4
	// Line 841, Address: 0x26d76c, Func Offset: 0xfc
	// Line 842, Address: 0x26d774, Func Offset: 0x104
	// Line 845, Address: 0x26d77c, Func Offset: 0x10c
	// Line 849, Address: 0x26d784, Func Offset: 0x114
	// Line 847, Address: 0x26d798, Func Offset: 0x128
	// Line 851, Address: 0x26d79c, Func Offset: 0x12c
	// Line 849, Address: 0x26d7a0, Func Offset: 0x130
	// Line 847, Address: 0x26d7c4, Func Offset: 0x154
	// Line 849, Address: 0x26d7cc, Func Offset: 0x15c
	// Line 850, Address: 0x26d7dc, Func Offset: 0x16c
	// Line 849, Address: 0x26d7ec, Func Offset: 0x17c
	// Line 850, Address: 0x26d7f8, Func Offset: 0x188
	// Line 849, Address: 0x26d804, Func Offset: 0x194
	// Line 851, Address: 0x26d810, Func Offset: 0x1a0
	// Line 850, Address: 0x26d820, Func Offset: 0x1b0
	// Line 851, Address: 0x26d834, Func Offset: 0x1c4
	// Line 850, Address: 0x26d83c, Func Offset: 0x1cc
	// Line 851, Address: 0x26d84c, Func Offset: 0x1dc
	// Line 850, Address: 0x26d850, Func Offset: 0x1e0
	// Line 852, Address: 0x26d854, Func Offset: 0x1e4
	// Line 850, Address: 0x26d858, Func Offset: 0x1e8
	// Line 852, Address: 0x26d860, Func Offset: 0x1f0
	// Line 851, Address: 0x26d870, Func Offset: 0x200
	// Line 850, Address: 0x26d874, Func Offset: 0x204
	// Line 851, Address: 0x26d880, Func Offset: 0x210
	// Line 852, Address: 0x26d890, Func Offset: 0x220
	// Line 851, Address: 0x26d89c, Func Offset: 0x22c
	// Line 853, Address: 0x26d8ac, Func Offset: 0x23c
	// Line 851, Address: 0x26d8b0, Func Offset: 0x240
	// Line 853, Address: 0x26d8b4, Func Offset: 0x244
	// Line 851, Address: 0x26d8c4, Func Offset: 0x254
	// Line 852, Address: 0x26d8cc, Func Offset: 0x25c
	// Line 853, Address: 0x26d8d0, Func Offset: 0x260
	// Line 851, Address: 0x26d8dc, Func Offset: 0x26c
	// Line 854, Address: 0x26d8e8, Func Offset: 0x278
	// Line 852, Address: 0x26d8ec, Func Offset: 0x27c
	// Line 854, Address: 0x26d8f0, Func Offset: 0x280
	// Line 852, Address: 0x26d900, Func Offset: 0x290
	// Line 853, Address: 0x26d90c, Func Offset: 0x29c
	// Line 854, Address: 0x26d910, Func Offset: 0x2a0
	// Line 852, Address: 0x26d91c, Func Offset: 0x2ac
	// Line 855, Address: 0x26d92c, Func Offset: 0x2bc
	// Line 852, Address: 0x26d930, Func Offset: 0x2c0
	// Line 855, Address: 0x26d934, Func Offset: 0x2c4
	// Line 852, Address: 0x26d944, Func Offset: 0x2d4
	// Line 854, Address: 0x26d94c, Func Offset: 0x2dc
	// Line 855, Address: 0x26d950, Func Offset: 0x2e0
	// Line 852, Address: 0x26d958, Func Offset: 0x2e8
	// Line 855, Address: 0x26d964, Func Offset: 0x2f4
	// Line 853, Address: 0x26d968, Func Offset: 0x2f8
	// Line 856, Address: 0x26d96c, Func Offset: 0x2fc
	// Line 853, Address: 0x26d970, Func Offset: 0x300
	// Line 856, Address: 0x26d974, Func Offset: 0x304
	// Line 853, Address: 0x26d984, Func Offset: 0x314
	// Line 855, Address: 0x26d98c, Func Offset: 0x31c
	// Line 856, Address: 0x26d990, Func Offset: 0x320
	// Line 853, Address: 0x26d998, Func Offset: 0x328
	// Line 856, Address: 0x26d9a8, Func Offset: 0x338
	// Line 853, Address: 0x26d9ac, Func Offset: 0x33c
	// Line 857, Address: 0x26d9b0, Func Offset: 0x340
	// Line 853, Address: 0x26d9b4, Func Offset: 0x344
	// Line 857, Address: 0x26d9bc, Func Offset: 0x34c
	// Line 856, Address: 0x26d9cc, Func Offset: 0x35c
	// Line 853, Address: 0x26d9d0, Func Offset: 0x360
	// Line 854, Address: 0x26d9dc, Func Offset: 0x36c
	// Line 857, Address: 0x26d9ec, Func Offset: 0x37c
	// Line 854, Address: 0x26d9f8, Func Offset: 0x388
	// Line 858, Address: 0x26da08, Func Offset: 0x398
	// Line 854, Address: 0x26da0c, Func Offset: 0x39c
	// Line 858, Address: 0x26da10, Func Offset: 0x3a0
	// Line 854, Address: 0x26da20, Func Offset: 0x3b0
	// Line 857, Address: 0x26da28, Func Offset: 0x3b8
	// Line 858, Address: 0x26da2c, Func Offset: 0x3bc
	// Line 854, Address: 0x26da34, Func Offset: 0x3c4
	// Line 858, Address: 0x26da40, Func Offset: 0x3d0
	// Line 855, Address: 0x26da44, Func Offset: 0x3d4
	// Line 859, Address: 0x26da48, Func Offset: 0x3d8
	// Line 855, Address: 0x26da4c, Func Offset: 0x3dc
	// Line 859, Address: 0x26da50, Func Offset: 0x3e0
	// Line 855, Address: 0x26da60, Func Offset: 0x3f0
	// Line 859, Address: 0x26da68, Func Offset: 0x3f8
	// Line 855, Address: 0x26da74, Func Offset: 0x404
	// Line 860, Address: 0x26da84, Func Offset: 0x414
	// Line 855, Address: 0x26da88, Func Offset: 0x418
	// Line 860, Address: 0x26da8c, Func Offset: 0x41c
	// Line 855, Address: 0x26da9c, Func Offset: 0x42c
	// Line 860, Address: 0x26daa4, Func Offset: 0x434
	// Line 855, Address: 0x26dab0, Func Offset: 0x440
	// Line 861, Address: 0x26dabc, Func Offset: 0x44c
	// Line 856, Address: 0x26dac0, Func Offset: 0x450
	// Line 861, Address: 0x26dac4, Func Offset: 0x454
	// Line 856, Address: 0x26dad4, Func Offset: 0x464
	// Line 858, Address: 0x26dae0, Func Offset: 0x470
	// Line 861, Address: 0x26dae4, Func Offset: 0x474
	// Line 856, Address: 0x26daf0, Func Offset: 0x480
	// Line 862, Address: 0x26db00, Func Offset: 0x490
	// Line 856, Address: 0x26db04, Func Offset: 0x494
	// Line 862, Address: 0x26db08, Func Offset: 0x498
	// Line 863, Address: 0x26db14, Func Offset: 0x4a4
	// Line 856, Address: 0x26db18, Func Offset: 0x4a8
	// Line 862, Address: 0x26db20, Func Offset: 0x4b0
	// Line 863, Address: 0x26db24, Func Offset: 0x4b4
	// Line 864, Address: 0x26db30, Func Offset: 0x4c0
	// Line 856, Address: 0x26db34, Func Offset: 0x4c4
	// Line 864, Address: 0x26db40, Func Offset: 0x4d0
	// Line 865, Address: 0x26db4c, Func Offset: 0x4dc
	// Line 857, Address: 0x26db50, Func Offset: 0x4e0
	// Line 865, Address: 0x26db54, Func Offset: 0x4e4
	// Line 866, Address: 0x26db60, Func Offset: 0x4f0
	// Line 857, Address: 0x26db64, Func Offset: 0x4f4
	// Line 866, Address: 0x26db68, Func Offset: 0x4f8
	// Line 857, Address: 0x26db74, Func Offset: 0x504
	// Line 862, Address: 0x26db7c, Func Offset: 0x50c
	// Line 857, Address: 0x26db88, Func Offset: 0x518
	// Line 863, Address: 0x26db98, Func Offset: 0x528
	// Line 857, Address: 0x26db9c, Func Offset: 0x52c
	// Line 863, Address: 0x26dba8, Func Offset: 0x538
	// Line 857, Address: 0x26dbb4, Func Offset: 0x544
	// Line 864, Address: 0x26dbc0, Func Offset: 0x550
	// Line 858, Address: 0x26dbc4, Func Offset: 0x554
	// Line 859, Address: 0x26dbd4, Func Offset: 0x564
	// Line 864, Address: 0x26dbd8, Func Offset: 0x568
	// Line 858, Address: 0x26dbe0, Func Offset: 0x570
	// Line 864, Address: 0x26dbf0, Func Offset: 0x580
	// Line 858, Address: 0x26dbf4, Func Offset: 0x584
	// Line 865, Address: 0x26dbf8, Func Offset: 0x588
	// Line 858, Address: 0x26dbfc, Func Offset: 0x58c
	// Line 865, Address: 0x26dc04, Func Offset: 0x594
	// Line 858, Address: 0x26dc10, Func Offset: 0x5a0
	// Line 866, Address: 0x26dc1c, Func Offset: 0x5ac
	// Line 859, Address: 0x26dc20, Func Offset: 0x5b0
	// Line 866, Address: 0x26dc30, Func Offset: 0x5c0
	// Line 859, Address: 0x26dc3c, Func Offset: 0x5cc
	// Line 867, Address: 0x26dc4c, Func Offset: 0x5dc
	// Line 859, Address: 0x26dc50, Func Offset: 0x5e0
	// Line 867, Address: 0x26dc54, Func Offset: 0x5e4
	// Line 868, Address: 0x26dc60, Func Offset: 0x5f0
	// Line 859, Address: 0x26dc64, Func Offset: 0x5f4
	// Line 867, Address: 0x26dc6c, Func Offset: 0x5fc
	// Line 868, Address: 0x26dc70, Func Offset: 0x600
	// Line 867, Address: 0x26dc7c, Func Offset: 0x60c
	// Line 859, Address: 0x26dc80, Func Offset: 0x610
	// Line 867, Address: 0x26dc8c, Func Offset: 0x61c
	// Line 860, Address: 0x26dc94, Func Offset: 0x624
	// Line 868, Address: 0x26dc98, Func Offset: 0x628
	// Line 860, Address: 0x26dc9c, Func Offset: 0x62c
	// Line 868, Address: 0x26dcac, Func Offset: 0x63c
	// Line 860, Address: 0x26dcb4, Func Offset: 0x644
	// Line 868, Address: 0x26dcc4, Func Offset: 0x654
	// Line 860, Address: 0x26dcc8, Func Offset: 0x658
	// Line 869, Address: 0x26dccc, Func Offset: 0x65c
	// Line 860, Address: 0x26dcd0, Func Offset: 0x660
	// Line 869, Address: 0x26dcd8, Func Offset: 0x668
	// Line 870, Address: 0x26dce4, Func Offset: 0x674
	// Line 869, Address: 0x26dce8, Func Offset: 0x678
	// Line 870, Address: 0x26dcec, Func Offset: 0x67c
	// Line 860, Address: 0x26dcf8, Func Offset: 0x688
	// Line 869, Address: 0x26dd04, Func Offset: 0x694
	// Line 861, Address: 0x26dd08, Func Offset: 0x698
	// Line 869, Address: 0x26dd0c, Func Offset: 0x69c
	// Line 861, Address: 0x26dd14, Func Offset: 0x6a4
	// Line 870, Address: 0x26dd18, Func Offset: 0x6a8
	// Line 861, Address: 0x26dd20, Func Offset: 0x6b0
	// Line 870, Address: 0x26dd24, Func Offset: 0x6b4
	// Line 861, Address: 0x26dd2c, Func Offset: 0x6bc
	// Line 871, Address: 0x26dd30, Func Offset: 0x6c0
	// Line 861, Address: 0x26dd3c, Func Offset: 0x6cc
	// Line 871, Address: 0x26dd40, Func Offset: 0x6d0
	// Line 861, Address: 0x26dd48, Func Offset: 0x6d8
	// Line 871, Address: 0x26dd58, Func Offset: 0x6e8
	// Line 861, Address: 0x26dd5c, Func Offset: 0x6ec
	// Line 871, Address: 0x26dd60, Func Offset: 0x6f0
	// Line 861, Address: 0x26dd68, Func Offset: 0x6f8
	// Line 872, Address: 0x26dd6c, Func Offset: 0x6fc
	// Line 861, Address: 0x26dd70, Func Offset: 0x700
	// Line 872, Address: 0x26dd74, Func Offset: 0x704
	// Line 861, Address: 0x26dd8c, Func Offset: 0x71c
	// Line 872, Address: 0x26dd90, Func Offset: 0x720
	// Line 873, Address: 0x26dd94, Func Offset: 0x724
	// Line 861, Address: 0x26dd98, Func Offset: 0x728
	// Line 873, Address: 0x26dda0, Func Offset: 0x730
	// Line 862, Address: 0x26ddb0, Func Offset: 0x740
	// Line 873, Address: 0x26ddc4, Func Offset: 0x754
	// Line 862, Address: 0x26ddd0, Func Offset: 0x760
	// Line 874, Address: 0x26ddd4, Func Offset: 0x764
	// Line 862, Address: 0x26ddd8, Func Offset: 0x768
	// Line 874, Address: 0x26dde4, Func Offset: 0x774
	// Line 862, Address: 0x26ddf4, Func Offset: 0x784
	// Line 874, Address: 0x26de00, Func Offset: 0x790
	// Line 875, Address: 0x26de0c, Func Offset: 0x79c
	// Line 862, Address: 0x26de18, Func Offset: 0x7a8
	// Line 875, Address: 0x26de24, Func Offset: 0x7b4
	// Line 876, Address: 0x26de28, Func Offset: 0x7b8
	// Line 863, Address: 0x26de2c, Func Offset: 0x7bc
	// Line 878, Address: 0x26de30, Func Offset: 0x7c0
	// Line 863, Address: 0x26de34, Func Offset: 0x7c4
	// Line 875, Address: 0x26de38, Func Offset: 0x7c8
	// Line 876, Address: 0x26de3c, Func Offset: 0x7cc
	// Line 878, Address: 0x26de48, Func Offset: 0x7d8
	// Line 875, Address: 0x26de54, Func Offset: 0x7e4
	// Line 863, Address: 0x26de58, Func Offset: 0x7e8
	// Line 875, Address: 0x26de5c, Func Offset: 0x7ec
	// Line 863, Address: 0x26de64, Func Offset: 0x7f4
	// Line 876, Address: 0x26de6c, Func Offset: 0x7fc
	// Line 877, Address: 0x26de7c, Func Offset: 0x80c
	// Line 863, Address: 0x26de80, Func Offset: 0x810
	// Line 877, Address: 0x26de88, Func Offset: 0x818
	// Line 863, Address: 0x26de90, Func Offset: 0x820
	// Line 877, Address: 0x26de98, Func Offset: 0x828
	// Line 863, Address: 0x26dea0, Func Offset: 0x830
	// Line 877, Address: 0x26deac, Func Offset: 0x83c
	// Line 878, Address: 0x26deb8, Func Offset: 0x848
	// Line 863, Address: 0x26debc, Func Offset: 0x84c
	// Line 880, Address: 0x26dec8, Func Offset: 0x858
	// Line 864, Address: 0x26decc, Func Offset: 0x85c
	// Line 880, Address: 0x26ded0, Func Offset: 0x860
	// Line 878, Address: 0x26dedc, Func Offset: 0x86c
	// Line 864, Address: 0x26dee0, Func Offset: 0x870
	// Line 878, Address: 0x26dee4, Func Offset: 0x874
	// Line 864, Address: 0x26deec, Func Offset: 0x87c
	// Line 879, Address: 0x26def0, Func Offset: 0x880
	// Line 864, Address: 0x26def4, Func Offset: 0x884
	// Line 879, Address: 0x26def8, Func Offset: 0x888
	// Line 880, Address: 0x26df08, Func Offset: 0x898
	// Line 864, Address: 0x26df0c, Func Offset: 0x89c
	// Line 865, Address: 0x26df30, Func Offset: 0x8c0
	// Line 874, Address: 0x26df34, Func Offset: 0x8c4
	// Line 864, Address: 0x26df38, Func Offset: 0x8c8
	// Line 865, Address: 0x26df44, Func Offset: 0x8d4
	// Line 879, Address: 0x26df54, Func Offset: 0x8e4
	// Line 878, Address: 0x26df60, Func Offset: 0x8f0
	// Line 865, Address: 0x26df64, Func Offset: 0x8f4
	// Line 880, Address: 0x26df80, Func Offset: 0x910
	// Line 879, Address: 0x26df88, Func Offset: 0x918
	// Line 880, Address: 0x26df8c, Func Offset: 0x91c
	// Line 865, Address: 0x26df90, Func Offset: 0x920
	// Line 866, Address: 0x26dfa0, Func Offset: 0x930
	// Line 880, Address: 0x26dfb4, Func Offset: 0x944
	// Line 881, Address: 0x26dfb8, Func Offset: 0x948
	// Line 866, Address: 0x26dfbc, Func Offset: 0x94c
	// Line 881, Address: 0x26dfd8, Func Offset: 0x968
	// Line 866, Address: 0x26dfe0, Func Offset: 0x970
	// Line 867, Address: 0x26dff0, Func Offset: 0x980
	// Line 868, Address: 0x26e030, Func Offset: 0x9c0
	// Line 869, Address: 0x26e070, Func Offset: 0xa00
	// Line 870, Address: 0x26e0b0, Func Offset: 0xa40
	// Line 871, Address: 0x26e0ec, Func Offset: 0xa7c
	// Line 872, Address: 0x26e128, Func Offset: 0xab8
	// Line 873, Address: 0x26e164, Func Offset: 0xaf4
	// Line 874, Address: 0x26e1a4, Func Offset: 0xb34
	// Line 875, Address: 0x26e1dc, Func Offset: 0xb6c
	// Line 876, Address: 0x26e21c, Func Offset: 0xbac
	// Line 877, Address: 0x26e25c, Func Offset: 0xbec
	// Line 878, Address: 0x26e29c, Func Offset: 0xc2c
	// Line 879, Address: 0x26e2d4, Func Offset: 0xc64
	// Line 880, Address: 0x26e30c, Func Offset: 0xc9c
	// Line 881, Address: 0x26e340, Func Offset: 0xcd0
	// Line 882, Address: 0x26e348, Func Offset: 0xcd8
	// Line 883, Address: 0x26e364, Func Offset: 0xcf4
	// Line 884, Address: 0x26e36c, Func Offset: 0xcfc
	// Func End, Address: 0x26e39c, Func Offset: 0xd2c
}

// 
// Start address: 0x26e3a0
void bhDrawSmallScreenRenderTexture()
{
	_anon4 scr_tex;
	float dist;
	unsigned int gm_flg;
	_anon33 cambk;
	_anon0* op;
	// Line 961, Address: 0x26e3a0, Func Offset: 0
	// Line 980, Address: 0x26e3c0, Func Offset: 0x20
	// Line 981, Address: 0x26e3d0, Func Offset: 0x30
	// Line 982, Address: 0x26e3f8, Func Offset: 0x58
	// Line 983, Address: 0x26e408, Func Offset: 0x68
	// Line 984, Address: 0x26e410, Func Offset: 0x70
	// Line 986, Address: 0x26e418, Func Offset: 0x78
	// Line 987, Address: 0x26e420, Func Offset: 0x80
	// Line 992, Address: 0x26e428, Func Offset: 0x88
	// Line 993, Address: 0x26e45c, Func Offset: 0xbc
	// Line 996, Address: 0x26e47c, Func Offset: 0xdc
	// Line 998, Address: 0x26e488, Func Offset: 0xe8
	// Line 997, Address: 0x26e48c, Func Offset: 0xec
	// Line 998, Address: 0x26e494, Func Offset: 0xf4
	// Line 999, Address: 0x26e498, Func Offset: 0xf8
	// Line 1000, Address: 0x26e4a0, Func Offset: 0x100
	// Line 1001, Address: 0x26e4b4, Func Offset: 0x114
	// Line 1002, Address: 0x26e4c8, Func Offset: 0x128
	// Line 1003, Address: 0x26e508, Func Offset: 0x168
	// Line 1004, Address: 0x26e510, Func Offset: 0x170
	// Line 1005, Address: 0x26e518, Func Offset: 0x178
	// Line 1006, Address: 0x26e52c, Func Offset: 0x18c
	// Line 1005, Address: 0x26e530, Func Offset: 0x190
	// Line 1006, Address: 0x26e534, Func Offset: 0x194
	// Line 1007, Address: 0x26e538, Func Offset: 0x198
	// Line 1008, Address: 0x26e53c, Func Offset: 0x19c
	// Line 1005, Address: 0x26e540, Func Offset: 0x1a0
	// Line 1006, Address: 0x26e544, Func Offset: 0x1a4
	// Line 1008, Address: 0x26e548, Func Offset: 0x1a8
	// Line 1007, Address: 0x26e54c, Func Offset: 0x1ac
	// Line 1009, Address: 0x26e550, Func Offset: 0x1b0
	// Line 1008, Address: 0x26e554, Func Offset: 0x1b4
	// Line 1010, Address: 0x26e558, Func Offset: 0x1b8
	// Line 1025, Address: 0x26e564, Func Offset: 0x1c4
	// Line 1027, Address: 0x26e57c, Func Offset: 0x1dc
	// Line 1028, Address: 0x26e598, Func Offset: 0x1f8
	// Line 1030, Address: 0x26e5b0, Func Offset: 0x210
	// Line 1032, Address: 0x26e5d8, Func Offset: 0x238
	// Line 1033, Address: 0x26e5f4, Func Offset: 0x254
	// Line 1035, Address: 0x26e60c, Func Offset: 0x26c
	// Line 1036, Address: 0x26e634, Func Offset: 0x294
	// Line 1038, Address: 0x26e63c, Func Offset: 0x29c
	// Line 1039, Address: 0x26e654, Func Offset: 0x2b4
	// Line 1040, Address: 0x26e670, Func Offset: 0x2d0
	// Line 1042, Address: 0x26e694, Func Offset: 0x2f4
	// Line 1043, Address: 0x26e6ac, Func Offset: 0x30c
	// Line 1044, Address: 0x26e6c8, Func Offset: 0x328
	// Line 1048, Address: 0x26e6ec, Func Offset: 0x34c
	// Line 1049, Address: 0x26e6fc, Func Offset: 0x35c
	// Line 1054, Address: 0x26e704, Func Offset: 0x364
	// Line 1055, Address: 0x26e70c, Func Offset: 0x36c
	// Line 1057, Address: 0x26e714, Func Offset: 0x374
	// Line 1058, Address: 0x26e724, Func Offset: 0x384
	// Line 1057, Address: 0x26e728, Func Offset: 0x388
	// Line 1058, Address: 0x26e730, Func Offset: 0x390
	// Line 1068, Address: 0x26e744, Func Offset: 0x3a4
	// Line 1069, Address: 0x26e75c, Func Offset: 0x3bc
	// Line 1070, Address: 0x26e764, Func Offset: 0x3c4
	// Line 1071, Address: 0x26e76c, Func Offset: 0x3cc
	// Line 1072, Address: 0x26e770, Func Offset: 0x3d0
	// Line 1076, Address: 0x26e778, Func Offset: 0x3d8
	// Line 1077, Address: 0x26e780, Func Offset: 0x3e0
	// Line 1078, Address: 0x26e788, Func Offset: 0x3e8
	// Line 1079, Address: 0x26e790, Func Offset: 0x3f0
	// Line 1080, Address: 0x26e794, Func Offset: 0x3f4
	// Line 1081, Address: 0x26e7a0, Func Offset: 0x400
	// Line 1083, Address: 0x26e7d8, Func Offset: 0x438
	// Line 1081, Address: 0x26e7e0, Func Offset: 0x440
	// Line 1083, Address: 0x26e7e8, Func Offset: 0x448
	// Line 1084, Address: 0x26e7f4, Func Offset: 0x454
	// Line 1088, Address: 0x26e808, Func Offset: 0x468
	// Line 1091, Address: 0x26e818, Func Offset: 0x478
	// Line 1093, Address: 0x26e820, Func Offset: 0x480
	// Line 1094, Address: 0x26e82c, Func Offset: 0x48c
	// Line 1096, Address: 0x26e840, Func Offset: 0x4a0
	// Line 1098, Address: 0x26e854, Func Offset: 0x4b4
	// Line 1100, Address: 0x26e85c, Func Offset: 0x4bc
	// Line 1103, Address: 0x26e868, Func Offset: 0x4c8
	// Line 1105, Address: 0x26e870, Func Offset: 0x4d0
	// Func End, Address: 0x26e894, Func Offset: 0x4f4
}

