/*typedef struct _anon0;
typedef struct npobj;
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
typedef struct BH_PWORK;
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
typedef struct _anon35;
typedef struct _anon36;
typedef struct _anon37;
typedef struct _anon38;
typedef struct _anon39;
typedef struct _anon40;
typedef struct _anon41;
typedef struct _anon42;
typedef struct _anon43;
typedef struct _anon44;
typedef struct _anon45;
typedef struct _anon46;
typedef struct _anon47;
typedef struct _anon48;
typedef struct _anon49;
typedef struct _anon50;
typedef struct _anon51;
typedef struct _anon52;
typedef struct _anon53;
typedef struct _anon54;
typedef struct _anon55;
typedef struct _anon56;

typedef void(*type_8)();
typedef void(*type_11)();
typedef void(*type_14)();
typedef void(*type_41)(void*);
typedef void(*type_57)();
typedef void(*type_83)();
typedef void(*type_108)();

typedef char type_0[32];
typedef unsigned char type_1[2];
typedef char type_2[8];
typedef short type_3[32];
typedef _anon3 type_4[1];
typedef _anon2 type_5[256];
typedef int type_6[4];
typedef unsigned int type_7[4];
typedef _anon9* type_9[256];
typedef unsigned char* type_10[256];
typedef char type_12[256];
typedef short type_13[256];
typedef float type_15[4];
typedef float type_16[4];
typedef float type_17[4];
typedef short type_18[256];
typedef int type_19[8];
typedef _anon9* type_20[256];
typedef float type_21[16];
typedef _anon54 type_22[256];
typedef char type_23[192];
typedef _anon3 type_24[450];
typedef short type_25[256];
typedef _anon42 type_26[450];
typedef int type_27[64];
typedef int type_28[4];
typedef _anon22 type_29[4];
typedef int type_30[450];
typedef _anon24 type_31[4];
typedef unsigned int type_32[8];
typedef unsigned char type_33[450];
typedef _anon16 type_34[4];
typedef unsigned int type_35[3];
typedef char type_36[16];
typedef unsigned char type_37[2];
typedef char type_38[4];
typedef char type_39[32];
typedef unsigned int type_40[32];
typedef _anon15 type_42[16];
typedef char type_43[64];
typedef unsigned int type_44[16];
typedef unsigned int type_45[16];
typedef char type_46[3];
typedef void* type_47[2];
typedef unsigned int type_48[32];
typedef unsigned int type_49[16];
typedef float type_50[3];
typedef BH_PWORK* type_51[16];
typedef int type_52[3];
typedef unsigned int type_53[8];
typedef float type_54[3];
typedef unsigned int type_55[384];
typedef _anon50 type_56[2];
typedef unsigned int type_58[2];
typedef unsigned int type_59[4];
typedef unsigned int type_60[1];
typedef unsigned int type_61[2];
typedef int* type_62[16];
typedef npobj* type_63[16];
typedef int type_64[4];
typedef char type_65[4];
typedef _anon9* type_66[16];
typedef short type_67[4];
typedef float type_68[4];
typedef _anon42 type_69[16];
typedef unsigned char type_70[4];
typedef unsigned long type_71[2];
typedef unsigned long type_72[2];
typedef _anon41 type_73[64];
typedef _anon39* type_74[512];
typedef _anon41 type_75[64];
typedef _anon39* type_76[128];
typedef _anon41 type_77[64];
typedef _anon39* type_78[512];
typedef _anon39* type_79[512];
typedef unsigned char type_80[64];
typedef unsigned int type_81[4];
typedef _anon39* type_82[512];
typedef _anon9* type_84[16];
typedef _anon39* type_85[512];
typedef _anon9* type_86[16][16];
typedef _anon9* type_87[16][16][100];
typedef _anon39* type_88[512];
typedef _anon9* type_89[1300];
typedef char type_90[8];
typedef _anon39* type_91[512];
typedef _anon9* type_92[200];
typedef _anon43 type_93[16];
typedef _anon39* type_94[128];
typedef unsigned int type_95[1];
typedef unsigned int type_96[32];
typedef _anon9* type_97[8];
typedef _anon39* type_98[128];
typedef int* type_99[16];
typedef _anon18 type_100[32];
typedef _anon39* type_101[128];
typedef npobj* type_102[16];
typedef unsigned char type_103[2];
typedef unsigned long type_104[12];
typedef _anon9* type_105[16];
typedef unsigned long type_106[12][13];
typedef _anon39* type_107[512];
typedef _anon42 type_109[16];
typedef _anon39* type_110[32];
typedef _anon4* type_111[128];
typedef _anon39* type_112[32];
typedef unsigned char type_113[64];
typedef _anon39* type_114[32];

struct _anon0
{
	void* texaddr;
	_anon52 texsurface;
};

struct npobj
{
	unsigned int evalflags;
	_anon31* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon1
{
	unsigned char mode_bk[2];
	unsigned char set_last;
	unsigned char dc_alpha;
	int mode;
};

struct _anon2
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon3
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon4
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon30* md2P;
	unsigned short* atrP;
};

struct _anon5
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon6
{
	struct
	{
		unsigned long AC : 1;
		unsigned long pad01 : 63;
	};
};

struct _anon7
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon8
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
	_anon18 ply_pos;
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
	_anon9* et_lp[16][16][100];
	_anon9* ot_lp[1300];
	_anon9* it_lp[200];
	int eft_n;
	_anon9* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon32* p1per;
	_anon32* p2per;
	_anon32* kbper;
	_anon32* msper;
	_anon32 ms_per;
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
	_anon39* obwp;
	_anon39* itwp;
	_anon4* emtp[128];
	_anon4* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	_anon9* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon9* txblp[256];
	_anon54 txbp[256];
	unsigned char* ef_psp;
	_anon3 ef_tex[450];
	_anon9 ef_tlist;
	_anon25 ef;
	short efid[256];
	_anon42 efm[450];
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
	_anon39* ef_pol[512];
	_anon39* ef_mdf[128];
	_anon39* ef_lin[512];
	_anon39* ef_ntx[512];
	_anon39* ef_trs[512];
	_anon39* ef_pnc[512];
	_anon39* ef_opq[512];
	_anon39* ef_thl[512];
	_anon39* ef_ntx2d[128];
	_anon39* ef_trs2d[128];
	_anon39* ef_pnc2d[128];
	_anon39* ef_fnc[512];
	int ob_nlgn;
	int ob_hlgn;
	int ob_spcn;
	_anon39* ob_nlg[32];
	_anon39* ob_hlg[32];
	_anon39* ob_spc[32];
	unsigned int ren_gid;
	_anon0 ren_info;
	_anon3 ren_tex[1];
	_anon9 ren_tlist;
	_anon2 rpb[256];
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
	_anon27 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon20* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon16 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon15 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon41* pl_htp;
	int costume;
	_anon18 hd_pos;
	_anon18 apos;
	_anon41* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon41 mwalp[64];
	_anon41 metcp[64];
	_anon41 mflrp[64];
	int dla_n;
	_anon41* htp;
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
	_anon9* sb_tlist;
	int ddmd;
	_anon55 door;
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
	_anon18 ufo_pos;
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
	_anon43 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon18 ghtp[32];
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

struct _anon9
{
	_anon3* textures;
	unsigned int nbTexture;
};

struct _anon10
{
	_anon23 frame2;
	unsigned long frame2addr;
	_anon48 zbuf2;
	long zbuf2addr;
	_anon38 xyoffset2;
	long xyoffset2addr;
	_anon19 scissor2;
	long scissor2addr;
	_anon6 prmodecont;
	long prmodecontaddr;
	_anon36 colclamp;
	long colclampaddr;
	_anon13 dthe;
	long dtheaddr;
	_anon28 test2;
	long test2addr;
};

struct _anon11
{
	struct
	{
		unsigned int R : 8;
		unsigned int G : 8;
		unsigned int B : 8;
		unsigned int A : 8;
	};
	float Q;
};

struct _anon12
{
	struct
	{
		unsigned int DX : 12;
		unsigned int DY : 11;
		unsigned int MAGH : 4;
		unsigned int MAGV : 2;
		unsigned int p0 : 3;
	};
	struct
	{
		unsigned int DW : 12;
		unsigned int DH : 11;
		unsigned int p1 : 9;
	};
};

struct _anon13
{
	struct
	{
		unsigned long DTHE : 1;
		unsigned long pad01 : 63;
	};
};

struct _anon14
{
	float mtrx[16];
	_anon18 pnt;
	_anon18 vctr;
	int stat;
	int reserve;
	_anon29 ltcal;
	_anon46 attr;
};

struct _anon15
{
	float x;
	float y;
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
	_anon9* txp[16];
	_anon42 mdl[16];
	_anon42* mlwP;
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
	_anon35 watr;
	_anon7* cpcl;
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

struct _anon16
{
	_anon18 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon17
{
	struct
	{
		unsigned int R : 8;
		unsigned int G : 8;
		unsigned int B : 8;
		unsigned int p0 : 8;
	};
	unsigned int p1;
};

struct _anon18
{
	float x;
	float y;
	float z;
};

struct _anon19
{
	struct
	{
		unsigned long SCAX0 : 11;
		unsigned long pad11 : 5;
		unsigned long SCAX1 : 11;
		unsigned long pad27 : 5;
		unsigned long SCAY0 : 11;
		unsigned long pad43 : 5;
		unsigned long SCAY1 : 11;
		unsigned long pad59 : 5;
	};
};

struct _anon20
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
	_anon14* light;
};

struct _anon21
{
	_anon28 testa;
	long testaaddr;
	_anon49 prim;
	long primaddr;
	_anon11 rgbaq;
	long rgbaqaddr;
	_anon44 xyz2a;
	long xyz2aaddr;
	_anon44 xyz2b;
	long xyz2baddr;
	_anon28 testb;
	long testbaddr;
};

struct _anon22
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon23
{
	struct
	{
		unsigned long FBP : 9;
		unsigned long pad09 : 7;
		unsigned long FBW : 6;
		unsigned long pad22 : 2;
		unsigned long PSM : 6;
		unsigned long pad30 : 2;
		unsigned long FBMSK : 32;
	};
};

struct _anon24
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon25
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

struct _anon26
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

struct _anon27
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon28
{
	struct
	{
		unsigned long ATE : 1;
		unsigned long ATST : 3;
		unsigned long AREF : 8;
		unsigned long AFAIL : 2;
		unsigned long DATE : 1;
		unsigned long DATM : 1;
		unsigned long ZTE : 1;
		unsigned long ZTST : 2;
		unsigned long pad19 : 45;
	};
};

struct _anon29
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
	_anon18 lpnt;
	_anon18 lvctr;
	_anon18 lmvctr;
	_anon5 atten;
	_anon5 amb;
	_anon5 dif;
	_anon5 spc;
	_anon5 mamb;
	_anon5 mdif;
	_anon5 mspc;
};

struct _anon30
{
	void* p[2];
};

struct _anon31
{
	int* vlist;
	short* plist;
	_anon18 center;
	float r;
};

struct _anon32
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
	_anon26* info;
};

struct _anon33
{
	_anon18 c;
	float r;
};

struct _anon34
{
	_anon50 disp[2];
	_anon40 giftag0;
	_anon53 draw01;
	_anon10 draw02;
	_anon21 clear0;
	_anon40 giftag1;
	_anon53 draw11;
	_anon10 draw12;
	_anon21 clear1;
};

struct _anon35
{
	_anon18 c1;
	_anon18 c2;
	float r;
};

struct _anon36
{
	struct
	{
		unsigned long CLAMP : 1;
		unsigned long pad01 : 63;
	};
};

struct _anon37
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon38
{
	struct
	{
		unsigned long OFX : 16;
		unsigned long pad16 : 16;
		unsigned long OFY : 16;
		unsigned long pad48 : 16;
	};
};

struct _anon39
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
	_anon9* txp[16];
	_anon42 mdl[16];
	_anon42* mlwP;
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
	_anon33 cspr;
	int pn;
	_anon22* pvp;
	_anon24* tvp;
	_anon22 pv[4];
	_anon24 tv[4];
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

struct _anon40
{
	struct
	{
		unsigned long NLOOP : 15;
		unsigned long EOP : 1;
		unsigned long pad16 : 16;
		unsigned long id : 14;
		unsigned long PRE : 1;
		unsigned long PRIM : 11;
		unsigned long FLG : 2;
		unsigned long NREG : 4;
	};
	struct
	{
		unsigned long REGS0 : 4;
		unsigned long REGS1 : 4;
		unsigned long REGS2 : 4;
		unsigned long REGS3 : 4;
		unsigned long REGS4 : 4;
		unsigned long REGS5 : 4;
		unsigned long REGS6 : 4;
		unsigned long REGS7 : 4;
		unsigned long REGS8 : 4;
		unsigned long REGS9 : 4;
		unsigned long REGS10 : 4;
		unsigned long REGS11 : 4;
		unsigned long REGS12 : 4;
		unsigned long REGS13 : 4;
		unsigned long REGS14 : 4;
		unsigned long REGS15 : 4;
	};
};

struct _anon41
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

struct _anon42
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon9* texP;
	_anon37* owP;
};

struct _anon43
{
	_anon18 c1;
	_anon18 c2;
	float r1;
	float r2;
};

struct _anon44
{
	struct
	{
		unsigned long X : 16;
		unsigned long Y : 16;
		unsigned long Z : 32;
	};
};

struct _anon45
{
	unsigned long SC_TAG[2];
	unsigned long GIF_TAG[2];
	unsigned long TEX0;
	unsigned long TEX0_TAG;
	unsigned long TEX0_NEXT;
	unsigned long TEX0_NEXT_TAG;
	unsigned long TEX1;
	unsigned long TEX1_TAG;
	unsigned long CLAMP;
	unsigned long CLAMP_TAG;
	unsigned long TEST;
	unsigned long TEST_TAG;
	unsigned long FOGCOL;
	unsigned long FOGCOL_TAG;
	unsigned long ALPHA;
	unsigned long ALPHA_TAG;
	unsigned long FBA;
	unsigned long FBA_TAG;
	unsigned long SCISSOR;
	unsigned long SCISSOR_TAG;
	unsigned char mode_bk[2];
	unsigned char set_last;
	unsigned char dc_alpha;
	unsigned int pad32;
	unsigned long pad64;
};

struct _anon46
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
	_anon5 argb;
};

struct _anon47
{
	struct
	{
		unsigned int EN1 : 1;
		unsigned int EN2 : 1;
		unsigned int CRTMD : 3;
		unsigned int MMOD : 1;
		unsigned int AMOD : 1;
		unsigned int SLBG : 1;
		unsigned int ALP : 8;
		unsigned int p0 : 16;
	};
	unsigned int p1;
};

struct _anon48
{
	struct
	{
		unsigned long ZBP : 9;
		unsigned long pad09 : 15;
		unsigned long PSM : 4;
		unsigned long pad28 : 4;
		unsigned long ZMSK : 1;
		unsigned long pad33 : 31;
	};
};

struct _anon49
{
	struct
	{
		unsigned long PRIM : 3;
		unsigned long IIP : 1;
		unsigned long TME : 1;
		unsigned long FGE : 1;
		unsigned long ABE : 1;
		unsigned long AA1 : 1;
		unsigned long FST : 1;
		unsigned long CTXT : 1;
		unsigned long FIX : 1;
		unsigned long pad11 : 53;
	};
};

struct _anon50
{
	_anon47 pmode;
	_anon56 smode2;
	_anon51 dispfb;
	_anon12 display;
	_anon17 bgcolor;
};

struct _anon51
{
	struct
	{
		unsigned int FBP : 9;
		unsigned int FBW : 6;
		unsigned int PSM : 5;
		unsigned int p0 : 12;
	};
	struct
	{
		unsigned int DBX : 11;
		unsigned int DBY : 11;
		unsigned int p1 : 10;
	};
};

struct _anon52
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

struct _anon53
{
	_anon23 frame1;
	unsigned long frame1addr;
	_anon48 zbuf1;
	long zbuf1addr;
	_anon38 xyoffset1;
	long xyoffset1addr;
	_anon19 scissor1;
	long scissor1addr;
	_anon6 prmodecont;
	long prmodecontaddr;
	_anon36 colclamp;
	long colclampaddr;
	_anon13 dthe;
	long dtheaddr;
	_anon28 test1;
	long test1addr;
};

struct _anon54
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon55
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

struct _anon56
{
	struct
	{
		unsigned int INT : 1;
		unsigned int FFMD : 1;
		unsigned int DPMS : 2;
		unsigned int p0 : 28;
	};
	unsigned int p1;
};*/

void (* VsyncFunc)();
void (* EorFunc)();
unsigned int Ps2_vcount;
unsigned int Ps2_dbuff;
sceGsDBuffDc Db;
SYS_WORK* sys;
int vsync_func(int);
PS2_NJ_SAVE Ps2_nj_save_current;
PS2_GS_SAVE Ps2_gs_save;

/*void njSetTextureMemorySize();
void njSetVertexBuffer();
void njInitSystem();
void njInitVertexBuffer();
void njWaitVSync();*/
void null_func();
/*void Ps2InitFunc();
void njSetEORFunction(void(*func)());
void Ps2SwapDBuff();
void vsync_func();
void Ps2SetVSyncCounter();
void njSetVSyncFunction(void(*func)());
void njExitSystem();
void njSetBackColor(unsigned int col1);
void njTextureFilterMode(int mode);
void njPolygonCullingMode();
void njColorBlendingModeSys(int s_mode, int d_mode);
void njColorBlendingMode(int target, int mode);
void njTextureShadingMode();
void njSetCheapShadowMode();
void njUserClipping(int mode, _anon15* np);
void njGetSystemAttr(char attr[192]);
void njSetSystemAttr(char attr[192]);
void njChangeSystem();
void njAdjustDisplay(int xadjust, int yadjust);
void njSetBorderColor();*/

// 100% matching!
void	njSetTextureMemorySize(Uint32 size )
{

}

// 100% matching!
void	njSetVertexBuffer(Uint32 *buffer,Sint32 size)
{

}

void Ps2Init(); // TODO: remove this declaration
// 100% matching!
void	njInitSystem( Int, Int, Int )
{
    Ps2Init();
}

// 100% matching!
void	njInitVertexBuffer( Sint32 op, Sint32 om, Sint32 tp, Sint32 tm ,Sint32 pt)
{

}

// 100% matching!
void njWaitVSync(void) 
{

}

// 100% matching! 
void null_func()
{

}

// 100% matching! 
void Ps2InitFunc()
{ 
    EorFunc = null_func; 
    VsyncFunc = null_func; 
} 

// 100% matching! 
void 	njSetEORFunction( void (*func)(void) )
{
    if (func == NULL) 
    { 
        EorFunc = null_func; 
    } 
    else 
    {
        EorFunc = func; 
    }
} 

#pragma optimization_level 0

// TODO: remove these function declarations
void Ps2DrawOTag();
void Ps2ClearOT();
void PS2_swap();
// 100% matching!
void Ps2SwapDBuff() 
{ 
    SyncPath(); 
    
    Ps2DrawOTag(); 
    Ps2ClearOT(); 
    
    SyncPath(); 

    EorFunc(); 
    
    while (Ps2_vcount < 2) 
    { 
        asm("nop");
        asm("nop");
    } 
    
    PS2_swap(); 
    
    sceGsSwapDBuffDc(&Db, Ps2_dbuff);
    
    Ps2_dbuff = (Ps2_dbuff + 1) & 0x1;
    
    Ps2_vcount = 0; 

    printf("TICK = %d\n", *(volatile unsigned int*)SR_CU0); 
    
    *(volatile unsigned int*)SR_CU0 = 0; 
    
    VsyncFunc(); 
} 

// 100% matching! 
int vsync_func(int) 
{
    Ps2_vcount++; 
    
    if ((((sys->tk_flg & 0x80)) && ((sys->gm_flg & 0x80000000))) && (sys->time < 216000000)) 
    {
        sys->time++;
    }
    
    ExitHandler(); 
} 

#pragma optimization_level reset

// 100% matching! 
void Ps2SetVSyncCounter()
{
    DisableIntc(2);
    
    AddIntcHandler(2, vsync_func, 0);
    
    EnableIntc(2);
}

// 100% matching! 
void	njSetVSyncFunction( void (*func)(void) )
{
    Ps2_vcount = 0; 
    
    if (func == NULL)
    { 
        VsyncFunc = null_func; 
    }
    else 
    {
        VsyncFunc = func; 
    }
} 

// 100% matching!
void	njExitSystem( void )
{

}

// 100% matching!
void	njSetBackColor( Uint32 col1, Uint32 col2, Uint32 col3 ) 
{
    unsigned long tmp; 

    tmp = SCE_GS_SET_RGBAQ((col1 >> 16) & 0xFF, (col1 >> 8) & 0xFF, col1 & 0xFF, (col1 >> 24) & 0xFF, 0); 
    
    *(unsigned long*)UNCACHED(&Db.clear0.rgbaq) = tmp; 
    *(unsigned long*)UNCACHED(&Db.clear1.rgbaq) = tmp; 
} 

// 100% matching! 
void	njTextureFilterMode( Int mode )
{
    Ps2_nj_save_current.mode = mode;
}

// 100% matching!
void    njPolygonCullingMode( Int mode )
{

}

// 99.91% matching 
void njColorBlendingModeSys(int s_mode, int d_mode) // this function is not on this KATANA release
{ 
    static unsigned long alpha_tbl[13][12]; // TODO: define this
    unsigned long alpha_value;
    
    Ps2_gs_save.mode_bk[0] = s_mode; 
    Ps2_gs_save.mode_bk[1] = d_mode; 
    
    Ps2_gs_save.set_last = Ps2_nj_save_current.set_last;
    
    Ps2_gs_save.dc_alpha = 0; 
    
    if (Ps2_gs_save.mode_bk[Ps2_gs_save.set_last] < 2) 
    { 
        if (Ps2_gs_save.mode_bk[Ps2_gs_save.set_last] == 0)
        { 
            alpha_value = 1; 
        }
        else
        { 
            alpha_value = 68; 
        }
    } 
    else if ((Ps2_gs_save.mode_bk[0] < 2) || (Ps2_gs_save.mode_bk[1] < 2)) 
    { 
        return;
    }
    else 
    {
        alpha_value = alpha_tbl[Ps2_gs_save.mode_bk[0]][Ps2_gs_save.mode_bk[1]]; 
    }
    
    if (alpha_value == ULONG_MAX) 
    { 
        printf("CALL ISHIKAWA ! ALPHA ERROR !!!!!!! MODE %d %d", Ps2_gs_save.mode_bk[0], Ps2_gs_save.mode_bk[1]); 
        
        while (TRUE); 
    }
    
    D2_SyncTag(); 
    
    ((u_long*)WORKBASE)[0] = DMAend | 0x4; 
    ((u_long*)WORKBASE)[1] = 0; 

    ((u_long*)WORKBASE)[2] = SCE_GIF_SET_TAG(3, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1); 
    ((u_long*)WORKBASE)[3] = SCE_GIF_PACKED_AD; 
    
    ((u_long*)WORKBASE)[4] = Ps2_gs_save.ALPHA = alpha_value; 
    ((u_long*)WORKBASE)[5] = SCE_GS_ALPHA_1; 
    
    ((u_long*)WORKBASE)[6] = 0; 
    ((u_long*)WORKBASE)[7] = SCE_GS_PABE; 
    
    ((u_long*)WORKBASE)[8] = Ps2_gs_save.FBA = 0; 
    ((u_long*)WORKBASE)[9] = SCE_GS_FBA_1; 
    
    loadImage((void*)0xF0000000); 
    
    SyncPath(); 
} 

// 100% matching! 
void    njColorBlendingMode( Int target, Int mode ) 
{
    Ps2_nj_save_current.mode_bk[target] = mode; 
    
    Ps2_nj_save_current.set_last = target; 
    
    Ps2_nj_save_current.dc_alpha = 0; 
    
    njColorBlendingModeSys(Ps2_nj_save_current.mode_bk[0], Ps2_nj_save_current.mode_bk[1]); 
}

// 100% matching!
void    njTextureShadingMode( Int mode )
{

}

/*// 
// Start address: 0x2e18b0
void njSetCheapShadowMode()
{
	// Line 565, Address: 0x2e18b0, Func Offset: 0
	// Func End, Address: 0x2e18b8, Func Offset: 0x8
}*/

// 99.95% matching 
void	njUserClipping(Int mode ,NJS_POINT2 *p)
{ 
    unsigned long* np; // changed the original var name from the debugging symbols 
    sceVu0FVECTOR posf;
    sceVu0IVECTOR posi;

    np = (unsigned long*)WORKBASE;
    
    D2_SyncTag(); 
    
    *np++ = DMAend | 0x2; 
    *np++ = 0; 
    
    *np++ = SCE_GIF_SET_TAG(1, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1); 
    *np++ = SCE_GIF_PACKED_AD; 

    if (mode == 2)
    { 
        posf[0] = p[0].x * 32.0f; 
        posf[1] = p[0].y * 32.0f; 
        
        posf[2] = p[1].x * 32.0f; 
        posf[3] = p[1].y * 32.0f; 
        
        sceVu0FTOI0Vector(posi, posf); 
        
        *np++ = Ps2_gs_save.SCISSOR = SCE_GS_SET_SCISSOR(posi[0], posi[2] + 32, posi[1], posi[3] + 32); 
    } 
    else if (mode == 0) 
    { 
        *np++ = Ps2_gs_save.SCISSOR = SCE_GS_SET_SCISSOR(0, DISP_WIDTH, 0, DISP_HEIGHT); 
    } 
    else
    { 
        printf("njUserClipping ERROR!\n"); 
        
        exit(0); 
    }
    
    *np++ = SCE_GS_SCISSOR_1; 
    
    loadImage((void*)0xF0000000); 
    
    D2_SyncTag(); 
}

/*// 
// Start address: 0x2e1a40
void njGetSystemAttr(char attr[192])
{
	// Line 645, Address: 0x2e1a40, Func Offset: 0
	// Line 647, Address: 0x2e1a54, Func Offset: 0x14
	// Func End, Address: 0x2e1a5c, Func Offset: 0x1c
}

// 
// Start address: 0x2e1a60
void njSetSystemAttr(char attr[192])
{
	// Line 653, Address: 0x2e1a60, Func Offset: 0
	// Line 655, Address: 0x2e1a74, Func Offset: 0x14
	// Func End, Address: 0x2e1a7c, Func Offset: 0x1c
}*/

// 100% matching! 
void    njChangeSystem( Int mode, Int frame, Int count )
{
    printf("ChangeSystem\n");
}

// 100% matching!
void	njAdjustDisplay(Sint32 xadjust,Sint32 yadjust )
{ 
    if (xadjust < -100) 
    {
        xadjust = -100;
    }
    
    if (xadjust > 640) 
    {
        xadjust = 640; 
    }
    
    if (yadjust < -15) 
    {
        yadjust = -15; 
    }
    
    if (yadjust > 240) 
    {
        yadjust = 240; 
    }
    
    Db.disp[0].display.DX = (xadjust * 3) + 636; 
    Db.disp[0].display.DY = (yadjust * 2) + 32; 
    
    Db.disp[1].display.DX = (xadjust * 3) + 636; 
    Db.disp[1].display.DY = (yadjust * 2) + 32; 
    
    FlushCache(0);
}

// 100% matching!
void	njSetBorderColor(Uint32 color )
{

}
