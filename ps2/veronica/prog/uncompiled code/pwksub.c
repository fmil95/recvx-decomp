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

typedef void(*type_93)(void*);

typedef float type_0[2];
typedef float type_1[16];
typedef float type_2[2][0];
typedef unsigned int type_3[4];
typedef _anon1* type_4[512];
typedef _anon1* type_5[32];
typedef _anon2* type_6[16];
typedef _anon1* type_7[32];
typedef _anon1* type_8[512];
typedef _anon2* type_9[16][16];
typedef _anon2* type_10[16][16][100];
typedef char type_11[8];
typedef char type_12[0];
typedef _anon1* type_13[32];
typedef _anon1* type_14[512];
typedef _anon2* type_15[1300];
typedef char type_16[32];
typedef float type_17[32];
typedef _anon1* type_18[512];
typedef _anon8 type_19[128];
typedef _anon2* type_20[200];
typedef short type_21[32];
typedef _anon27 type_22[1];
typedef _anon1* type_23[128];
typedef unsigned int type_24[1];
typedef _anon23 type_25[3];
typedef _anon7 type_26[256];
typedef _anon2* type_27[8];
typedef int* type_28[16];
typedef _anon1* type_29[128];
typedef _anon46 type_30[16];
typedef npobj* type_31[16];
typedef _anon1* type_32[128];
typedef int type_33[4];
typedef _anon2* type_34[16];
typedef unsigned int type_35[4];
typedef float type_36[4];
typedef _anon15 type_37[16];
typedef _anon1* type_38[512];
typedef float type_39[4];
typedef char type_40[256];
typedef float type_41[4];
typedef float type_42[4];
typedef float type_43[4];
typedef float type_44[4];
typedef _anon5* type_45[128];
typedef float type_46[3];
typedef unsigned char type_47[64];
typedef float type_48[3][20];
typedef float type_49[3];
typedef float type_50[3][20];
typedef float type_51[3];
typedef float type_52[3][20];
typedef BH_PWORK type_53[0];
typedef char type_54[8];
typedef float type_55[3];
typedef float type_56[3][20];
typedef _anon1 type_57[0];
typedef void* type_58[2];
typedef _anon2* type_59[256];
typedef int type_60[4];
typedef unsigned char* type_61[256];
typedef unsigned int type_62[2];
typedef short type_63[256];
typedef _anon33 type_64[4];
typedef _anon43 type_65[0];
typedef float type_66[3];
typedef short type_67[256];
typedef int type_68[3];
typedef int type_69[8];
typedef float type_70[3];
typedef _anon21 type_71[0];
typedef _anon2* type_72[256];
typedef _anon10 type_73[256];
typedef _anon13 type_74[4];
typedef _anon13 type_75[4][0];
typedef _anon27 type_76[450];
typedef _anon35 type_77[16];
typedef short type_78[256];
typedef char type_79[3];
typedef int type_80[64];
typedef _anon15 type_81[450];
typedef unsigned int type_82[16];
typedef char type_83[4];
typedef unsigned int type_84[8];
typedef _anon38 type_85[4];
typedef _anon3 type_86[4];
typedef int type_87[450];
typedef unsigned int type_88[8];
typedef unsigned char type_89[450];
typedef float type_90[128];
typedef char type_91[16];
typedef char type_92[4];
typedef _anon25 type_94[2];
typedef unsigned int type_95[32];
typedef unsigned char type_96[256];
typedef unsigned int type_97[16];
typedef _anon0 type_98[64];
typedef unsigned int type_99[16];
typedef _anon0 type_100[64];
typedef unsigned int type_101[32];
typedef _anon0 type_102[64];
typedef unsigned int type_103[16];
typedef _anon23 type_104[3];
typedef unsigned int type_105[3];
typedef BH_PWORK* type_106[16];
typedef unsigned int type_107[8];
typedef unsigned int type_108[1];
typedef unsigned int type_109[384];
typedef unsigned int type_110[2];
typedef unsigned char type_111[2];
typedef int* type_112[16];
typedef unsigned int type_113[4];
typedef char type_114[32];
typedef npobj* type_115[16];
typedef char type_116[64];
typedef _anon2* type_117[16];
typedef char type_118[4];
typedef _anon15 type_119[16];
typedef short type_120[4];
typedef _anon23 type_121[8];
typedef unsigned char type_122[4];
typedef _anon36 type_123[16];
typedef unsigned int type_124[8];
typedef unsigned int type_125[32];
typedef unsigned int type_126[4];
typedef _anon23 type_127[32];
typedef _anon1* type_128[512];
typedef _anon1* type_129[128];
typedef _anon1* type_130[512];
typedef unsigned char type_131[64];
typedef _anon1* type_132[512];

struct npobj
{
	unsigned int evalflags;
	_anon34* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon0
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

struct _anon1
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
	_anon2* txp[16];
	_anon15 mdl[16];
	_anon15* mlwP;
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
	_anon5* mnwP;
	_anon5* mnwPb;
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
	_anon45 cspr;
	int pn;
	_anon38* pvp;
	_anon3* tvp;
	_anon38 pv[4];
	_anon3 tv[4];
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
	_anon2* txp[16];
	_anon15 mdl[16];
	_anon15* mlwP;
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
	_anon5* mnwP;
	_anon5* mnwPb;
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
	_anon40 watr;
	_anon28* cpcl;
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
	_anon27* textures;
	unsigned int nbTexture;
};

struct _anon3
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon4
{
	float px;
	float py;
	float pz;
	int ay;
};

struct _anon5
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon26* md2P;
	unsigned short* atrP;
};

struct _anon6
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon46 keyf[16];
};

struct _anon7
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon8
{
	int idx;
	float ln;
};

struct _anon9
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

struct _anon10
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon11
{
	_anon14* cutp;
	_anon18* lgtp;
	_anon19* enep;
	_anon19* objp;
	_anon19* itmp;
	_anon22* effp;
	_anon0* walp;
	_anon0* etcp;
	_anon0* flrp;
	_anon4* posp;
	_anon0* rutp;
	unsigned char* ruttp;
	_anon29* evtp;
	_anon6* evcp;
	unsigned int* mesp;
	_anon18* evlp;
	unsigned char* dmp00;
	unsigned char* dmp01;
	unsigned char* dmp02;
	unsigned char* dmp03;
	unsigned char* dmp04;
	unsigned char* dmp05;
	unsigned char* dmp06;
	unsigned char* dmp07;
	unsigned char* dmp08;
	unsigned char* dmp09;
	unsigned char* dmp10;
	unsigned char* dmp11;
	unsigned char* dmp12;
	unsigned char* dmp13;
	unsigned char* dmp14;
	unsigned char* dmp15;
	int cut_n;
	int lgt_n;
	int ene_n;
	int obj_n;
	int itm_n;
	int eff_n;
	int wal_n;
	int etc_n;
	int flr_n;
	int pos_n;
	int rut_n;
	int evc_n;
	int mes_n;
	int evl_n;
	int dmy00;
	int dmy01;
	int dmy02;
	int dmy03;
	int dmy04;
	int dmy05;
	int dmy06;
	int dmy07;
	int dmy08;
	int dmy09;
	int dmy10;
	int dmy11;
	int dmy12;
	int dmy13;
	int dmy14;
	int dmy15;
	int dmy16;
	int dmy17;
	unsigned int flg;
	unsigned int bak_col;
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	float w;
	float h;
	float d;
	float grand[32];
	_anon15 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};

struct _anon12
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
	_anon2* et_lp[16][16][100];
	_anon2* ot_lp[1300];
	_anon2* it_lp[200];
	int eft_n;
	_anon2* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon16* p1per;
	_anon16* p2per;
	_anon16* kbper;
	_anon16* msper;
	_anon16 ms_per;
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
	_anon1* obwp;
	_anon1* itwp;
	_anon5* emtp[128];
	_anon5* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	_anon2* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon2* txblp[256];
	_anon10 txbp[256];
	unsigned char* ef_psp;
	_anon27 ef_tex[450];
	_anon2 ef_tlist;
	_anon13 ef;
	short efid[256];
	_anon15 efm[450];
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
	_anon1* ef_pol[512];
	_anon1* ef_mdf[128];
	_anon1* ef_lin[512];
	_anon1* ef_ntx[512];
	_anon1* ef_trs[512];
	_anon1* ef_pnc[512];
	_anon1* ef_opq[512];
	_anon1* ef_thl[512];
	_anon1* ef_ntx2d[128];
	_anon1* ef_trs2d[128];
	_anon1* ef_pnc2d[128];
	_anon1* ef_fnc[512];
	int ob_nlgn;
	int ob_hlgn;
	int ob_spcn;
	_anon1* ob_nlg[32];
	_anon1* ob_hlg[32];
	_anon1* ob_spc[32];
	unsigned int ren_gid;
	_anon24 ren_info;
	_anon27 ren_tex[1];
	_anon2 ren_tlist;
	_anon7 rpb[256];
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
	_anon41 mr_pl;
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
	_anon33 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon35 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon0* pl_htp;
	int costume;
	_anon23 hd_pos;
	_anon23 apos;
	_anon0* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon0 mwalp[64];
	_anon0 metcp[64];
	_anon0 mflrp[64];
	int dla_n;
	_anon0* htp;
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
	_anon2* sb_tlist;
	int ddmd;
	_anon20 door;
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
	_anon36 gatc[16];
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

struct _anon13
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

struct _anon14
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon17* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon25 cam[2];
	unsigned char exd[256];
};

struct _anon15
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon2* texP;
	_anon31* owP;
};

struct _anon16
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
	_anon42* info;
};

struct _anon17
{
	unsigned int attr;
	char flr_no;
	char reserve0;
	char reserve1;
	char atr_tp;
	float h;
	float dmy;
	float minx;
	float minz;
	float maxx;
	float maxz;
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
	_anon32* light;
};

struct _anon19
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	unsigned char mdlver;
	unsigned char wrk_no;
	char prm1;
	float px;
	float py;
	float pz;
	short ax;
	short az;
	short ay;
	short aspd;
	char hide[4];
};

struct _anon20
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

struct _anon21
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
	_anon23 wp_fps1;
	_anon23 wp_fps2;
	_anon23 wp_cps;
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

struct _anon22
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
	int lkflg;
	int lkno;
	int lkono;
	float lx;
	float ly;
	float lz;
	int param;
};

struct _anon23
{
	float x;
	float y;
	float z;
};

struct _anon24
{
	void* texaddr;
	_anon9 texsurface;
};

struct _anon25
{
	unsigned short flg;
	unsigned char lgtclip;
	char spd;
	float px;
	float py;
	float pz;
	float ln;
	float w;
	float h;
	float d;
	float y0;
	float y1;
	float y2;
	float y3;
	float am_spd;
	int ax;
	int ay;
	int az;
	int lax;
	int lay;
	short laz0;
	short laz1;
	short laz2;
	short laz3;
	char aa_spd;
	char fil_no;
	char fil_rt;
	char reserve;
	int pers;
	unsigned int hidobj[16];
	unsigned int hidlgt[8];
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
};

struct _anon26
{
	void* p[2];
};

struct _anon27
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon28
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon29
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon30
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon31
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon32
{
	float mtrx[16];
	_anon23 pnt;
	_anon23 vctr;
	int stat;
	int reserve;
	_anon37 ltcal;
	_anon44 attr;
};

struct _anon33
{
	_anon23 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon34
{
	int* vlist;
	short* plist;
	_anon23 center;
	float r;
};

struct _anon35
{
	float x;
	float y;
};

struct _anon36
{
	_anon23 c1;
	_anon23 c2;
	float r1;
	float r2;
};

struct _anon37
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
	_anon30 atten;
	_anon30 amb;
	_anon30 dif;
	_anon30 spc;
	_anon30 mamb;
	_anon30 mdif;
	_anon30 mspc;
};

struct _anon38
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon39
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

struct _anon40
{
	_anon23 c1;
	_anon23 c2;
	float r;
};

struct _anon41
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon42
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

struct _anon43
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
};

struct _anon44
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
	_anon30 argb;
};

struct _anon45
{
	_anon23 c;
	float r;
};

struct _anon46
{
	unsigned short flg;
	short frame;
	float px;
	float py;
	float pz;
	short ax;
	short ay;
	short az;
	short pers;
	unsigned int hidobj[8];
	unsigned int hidlgt[4];
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	short lkflg;
	short lkno;
	short lkono;
	short nxt_no;
	float lx;
	float ly;
	float lz;
	float prm_0;
	float prm_1;
	float prm_2;
	float prm_3;
	float prm_4;
	unsigned char* recp;
};

struct _anon47
{
	_anon23 v[8];
};

_anon12* sys;
unsigned char* freemem;
BH_PWORK* plp;
char PlyFlip[0];
float PlyInfo[2][0];
_anon1 eff[0];
_anon11* rom;
BH_PWORK ene[0];
_anon39 cam;
_anon21 WpnTab[0];
_anon13 WpnEffTab[4][0];
_anon43 lgttab[0];

unsigned char* bhGetFreeMemory(int size);
void bhCalcLinkModel(BH_PWORK* pp);
void bhSetFloorNum(BH_PWORK* pp);
int bhCheckFloorNum(float py);
void bhAddSpeed(BH_PWORK* pp, int r);
int bhGetFrameNum(unsigned int fnm_old, unsigned int fnm_new, int fno_now);
int bhCalcLockEneYR(BH_PWORK* pp, int idx);
int bhSearchNearEnemy(BH_PWORK* pp, int* r, float* h, int* id);
int bhSearchNearEnemyB(_anon23* pos, int ay, int ar, float len);
int bhSearchNearEnemy2(BH_PWORK* pp, int* r, float* h, int* id);
int bhSearchNextEnemy(BH_PWORK* pp, int r, float h);
int bhSearchPlayer(BH_PWORK* pp, int r);
int bhCheckL2Wall(_anon41* lp, unsigned int flg, float* len);
int bhCheckC2Wall(_anon40* cap);
int bhCheckC2WallN(_anon40* cap, unsigned int flg);
int bhCheckClipModel(BH_PWORK* pp);
int bhCheckClipPoint(_anon23* pos);
void bhSetWaterSplash(BH_PWORK* pp, int jno, int type, float sx, float sy, float sz);
void bhSetWaterSplash2(BH_PWORK* pp, _anon23* pos, int type, float sx, float sy, float sz);
void bhSetWaterSplash3(_anon23* pos, int ang, int type, float sx, float sy, float sz);
void bhSetWaterSplash4(_anon23* pos, int ang, int type, float sx, float sy, float sz);
void bhSetGunFire(BH_PWORK* pp, int wno, int jno, int hand, int ang);
void bhSetYakkyou(BH_PWORK* pp, int wno, int jno, int hand);
void bhSetMagazine(BH_PWORK* pp, int wno, int jno, int hand, int ang);
void bhSetLighterFire(_anon1* op, int flg);

// 
// Start address: 0x14dfb0
unsigned char* bhGetFreeMemory(int size)
{
	// Line 111, Address: 0x14dfb0, Func Offset: 0
	// Line 121, Address: 0x14dfc0, Func Offset: 0x10
	// Line 123, Address: 0x14dfdc, Func Offset: 0x2c
	// Line 121, Address: 0x14dfe0, Func Offset: 0x30
	// Line 123, Address: 0x14dfec, Func Offset: 0x3c
	// Line 127, Address: 0x14e028, Func Offset: 0x78
	// Line 128, Address: 0x14e038, Func Offset: 0x88
	// Line 129, Address: 0x14e040, Func Offset: 0x90
	// Line 128, Address: 0x14e048, Func Offset: 0x98
	// Line 129, Address: 0x14e064, Func Offset: 0xb4
	// Line 130, Address: 0x14e07c, Func Offset: 0xcc
	// Line 131, Address: 0x14e080, Func Offset: 0xd0
	// Func End, Address: 0x14e094, Func Offset: 0xe4
}

// 
// Start address: 0x14e0a0
void bhCalcLinkModel(BH_PWORK* pp)
{
	int i;
	_anon1* op;
	BH_PWORK* ep;
	// Line 218, Address: 0x14e0a0, Func Offset: 0
	// Line 223, Address: 0x14e0b4, Func Offset: 0x14
	// Line 224, Address: 0x14e0c4, Func Offset: 0x24
	// Line 225, Address: 0x14e0cc, Func Offset: 0x2c
	// Line 231, Address: 0x14e10c, Func Offset: 0x6c
	// Line 233, Address: 0x14e120, Func Offset: 0x80
	// Line 235, Address: 0x14e148, Func Offset: 0xa8
	// Line 236, Address: 0x14e154, Func Offset: 0xb4
	// Line 237, Address: 0x14e15c, Func Offset: 0xbc
	// Line 243, Address: 0x14e19c, Func Offset: 0xfc
	// Line 245, Address: 0x14e1b0, Func Offset: 0x110
	// Line 247, Address: 0x14e1d0, Func Offset: 0x130
	// Line 248, Address: 0x14e1e4, Func Offset: 0x144
	// Line 249, Address: 0x14e1ec, Func Offset: 0x14c
	// Line 254, Address: 0x14e22c, Func Offset: 0x18c
	// Line 256, Address: 0x14e240, Func Offset: 0x1a0
	// Line 258, Address: 0x14e260, Func Offset: 0x1c0
	// Line 259, Address: 0x14e268, Func Offset: 0x1c8
	// Line 260, Address: 0x14e26c, Func Offset: 0x1cc
	// Line 267, Address: 0x14e29c, Func Offset: 0x1fc
	// Line 268, Address: 0x14e2c4, Func Offset: 0x224
	// Line 269, Address: 0x14e2d8, Func Offset: 0x238
	// Line 270, Address: 0x14e2ec, Func Offset: 0x24c
	// Line 271, Address: 0x14e2f0, Func Offset: 0x250
	// Line 272, Address: 0x14e300, Func Offset: 0x260
	// Func End, Address: 0x14e318, Func Offset: 0x278
}

// 
// Start address: 0x14e320
void bhSetFloorNum(BH_PWORK* pp)
{
	int fnow;
	int fno;
	int i;
	// Line 285, Address: 0x14e320, Func Offset: 0
	// Line 283, Address: 0x14e324, Func Offset: 0x4
	// Line 285, Address: 0x14e328, Func Offset: 0x8
	// Line 284, Address: 0x14e32c, Func Offset: 0xc
	// Line 285, Address: 0x14e330, Func Offset: 0x10
	// Line 286, Address: 0x14e334, Func Offset: 0x14
	// Line 288, Address: 0x14e388, Func Offset: 0x68
	// Line 289, Address: 0x14e38c, Func Offset: 0x6c
	// Line 290, Address: 0x14e390, Func Offset: 0x70
	// Line 291, Address: 0x14e3a0, Func Offset: 0x80
	// Line 292, Address: 0x14e3a8, Func Offset: 0x88
	// Line 293, Address: 0x14e3b8, Func Offset: 0x98
	// Func End, Address: 0x14e3c0, Func Offset: 0xa0
}

// 
// Start address: 0x14e3c0
int bhCheckFloorNum(float py)
{
	int fno;
	int i;
	// Line 305, Address: 0x14e3c0, Func Offset: 0
	// Line 304, Address: 0x14e3c8, Func Offset: 0x8
	// Line 305, Address: 0x14e3cc, Func Offset: 0xc
	// Line 306, Address: 0x14e3d0, Func Offset: 0x10
	// Line 308, Address: 0x14e418, Func Offset: 0x58
	// Line 309, Address: 0x14e41c, Func Offset: 0x5c
	// Line 310, Address: 0x14e420, Func Offset: 0x60
	// Line 312, Address: 0x14e430, Func Offset: 0x70
	// Func End, Address: 0x14e438, Func Offset: 0x78
}

// 
// Start address: 0x14e440
void bhAddSpeed(BH_PWORK* pp, int r)
{
	// Line 321, Address: 0x14e440, Func Offset: 0
	// Line 322, Address: 0x14e450, Func Offset: 0x10
	// Line 323, Address: 0x14e460, Func Offset: 0x20
	// Line 324, Address: 0x14e470, Func Offset: 0x30
	// Line 323, Address: 0x14e474, Func Offset: 0x34
	// Line 324, Address: 0x14e47c, Func Offset: 0x3c
	// Line 325, Address: 0x14e498, Func Offset: 0x58
	// Func End, Address: 0x14e4ac, Func Offset: 0x6c
}

// 
// Start address: 0x14e4b0
int bhGetFrameNum(unsigned int fnm_old, unsigned int fnm_new, int fno_now)
{
	int frm;
	float fnew;
	float fold;
	// Line 335, Address: 0x14e4b0, Func Offset: 0
	// Line 338, Address: 0x14e4bc, Func Offset: 0xc
	// Line 339, Address: 0x14e4ec, Func Offset: 0x3c
	// Line 341, Address: 0x14e51c, Func Offset: 0x6c
	// Line 342, Address: 0x14e538, Func Offset: 0x88
	// Line 343, Address: 0x14e548, Func Offset: 0x98
	// Line 344, Address: 0x14e554, Func Offset: 0xa4
	// Line 345, Address: 0x14e560, Func Offset: 0xb0
	// Line 347, Address: 0x14e570, Func Offset: 0xc0
	// Func End, Address: 0x14e580, Func Offset: 0xd0
}

// 
// Start address: 0x14e580
int bhCalcLockEneYR(BH_PWORK* pp, int idx)
{
	float ez;
	float ex;
	float pz;
	float px;
	short aa;
	int yr;
	_anon23 vec;
	BH_PWORK* ewp;
	// Line 353, Address: 0x14e580, Func Offset: 0
	// Line 361, Address: 0x14e58c, Func Offset: 0xc
	// Line 353, Address: 0x14e590, Func Offset: 0x10
	// Line 361, Address: 0x14e594, Func Offset: 0x14
	// Line 353, Address: 0x14e598, Func Offset: 0x18
	// Line 361, Address: 0x14e5a0, Func Offset: 0x20
	// Line 353, Address: 0x14e5a4, Func Offset: 0x24
	// Line 361, Address: 0x14e5a8, Func Offset: 0x28
	// Line 353, Address: 0x14e5ac, Func Offset: 0x2c
	// Line 361, Address: 0x14e5b4, Func Offset: 0x34
	// Line 362, Address: 0x14e5c0, Func Offset: 0x40
	// Line 361, Address: 0x14e5c4, Func Offset: 0x44
	// Line 362, Address: 0x14e5c8, Func Offset: 0x48
	// Line 364, Address: 0x14e5d8, Func Offset: 0x58
	// Line 365, Address: 0x14e5e0, Func Offset: 0x60
	// Line 366, Address: 0x14e5e4, Func Offset: 0x64
	// Line 368, Address: 0x14e5ec, Func Offset: 0x6c
	// Line 369, Address: 0x14e5f8, Func Offset: 0x78
	// Line 379, Address: 0x14e600, Func Offset: 0x80
	// Line 380, Address: 0x14e608, Func Offset: 0x88
	// Line 379, Address: 0x14e610, Func Offset: 0x90
	// Line 382, Address: 0x14e618, Func Offset: 0x98
	// Line 379, Address: 0x14e61c, Func Offset: 0x9c
	// Line 383, Address: 0x14e620, Func Offset: 0xa0
	// Line 384, Address: 0x14e624, Func Offset: 0xa4
	// Line 380, Address: 0x14e628, Func Offset: 0xa8
	// Line 379, Address: 0x14e62c, Func Offset: 0xac
	// Line 380, Address: 0x14e630, Func Offset: 0xb0
	// Line 381, Address: 0x14e634, Func Offset: 0xb4
	// Line 382, Address: 0x14e63c, Func Offset: 0xbc
	// Line 384, Address: 0x14e644, Func Offset: 0xc4
	// Line 385, Address: 0x14e64c, Func Offset: 0xcc
	// Line 386, Address: 0x14e688, Func Offset: 0x108
	// Line 387, Address: 0x14e698, Func Offset: 0x118
	// Line 386, Address: 0x14e69c, Func Offset: 0x11c
	// Line 387, Address: 0x14e6a0, Func Offset: 0x120
	// Line 395, Address: 0x14e6a8, Func Offset: 0x128
	// Line 387, Address: 0x14e6ac, Func Offset: 0x12c
	// Line 398, Address: 0x14e6b0, Func Offset: 0x130
	// Line 395, Address: 0x14e6b4, Func Offset: 0x134
	// Line 387, Address: 0x14e6b8, Func Offset: 0x138
	// Line 396, Address: 0x14e6c8, Func Offset: 0x148
	// Line 398, Address: 0x14e6d0, Func Offset: 0x150
	// Line 399, Address: 0x14e6d8, Func Offset: 0x158
	// Line 401, Address: 0x14e700, Func Offset: 0x180
	// Func End, Address: 0x14e728, Func Offset: 0x1a8
}

// 
// Start address: 0x14e730
int bhSearchNearEnemy(BH_PWORK* pp, int* r, float* h, int* id)
{
	int yr;
	int ar;
	int idx;
	int i;
	BH_PWORK* epp;
	float epz;
	float epx;
	float ah;
	float nr;
	float ln;
	float er;
	float a;
	_anon40 cap;
	_anon23 vc2;
	_anon23 vc1;
	_anon23 vc0;
	// Line 419, Address: 0x14e730, Func Offset: 0
	// Line 430, Address: 0x14e770, Func Offset: 0x40
	// Line 431, Address: 0x14e774, Func Offset: 0x44
	// Line 432, Address: 0x14e784, Func Offset: 0x54
	// Line 434, Address: 0x14e790, Func Offset: 0x60
	// Line 433, Address: 0x14e794, Func Offset: 0x64
	// Line 435, Address: 0x14e798, Func Offset: 0x68
	// Line 434, Address: 0x14e79c, Func Offset: 0x6c
	// Line 435, Address: 0x14e7a0, Func Offset: 0x70
	// Line 436, Address: 0x14e7a8, Func Offset: 0x78
	// Line 437, Address: 0x14e7b0, Func Offset: 0x80
	// Line 438, Address: 0x14e7bc, Func Offset: 0x8c
	// Line 439, Address: 0x14e7cc, Func Offset: 0x9c
	// Line 440, Address: 0x14e7d8, Func Offset: 0xa8
	// Line 441, Address: 0x14e7e8, Func Offset: 0xb8
	// Line 460, Address: 0x14e7f8, Func Offset: 0xc8
	// Line 463, Address: 0x14e7fc, Func Offset: 0xcc
	// Line 464, Address: 0x14e804, Func Offset: 0xd4
	// Line 461, Address: 0x14e808, Func Offset: 0xd8
	// Line 465, Address: 0x14e80c, Func Offset: 0xdc
	// Line 460, Address: 0x14e810, Func Offset: 0xe0
	// Line 461, Address: 0x14e814, Func Offset: 0xe4
	// Line 464, Address: 0x14e818, Func Offset: 0xe8
	// Line 466, Address: 0x14e81c, Func Offset: 0xec
	// Line 467, Address: 0x14e820, Func Offset: 0xf0
	// Line 461, Address: 0x14e824, Func Offset: 0xf4
	// Line 462, Address: 0x14e82c, Func Offset: 0xfc
	// Line 467, Address: 0x14e834, Func Offset: 0x104
	// Line 468, Address: 0x14e83c, Func Offset: 0x10c
	// Line 474, Address: 0x14e888, Func Offset: 0x158
	// Line 476, Address: 0x14e8ac, Func Offset: 0x17c
	// Line 477, Address: 0x14e8b0, Func Offset: 0x180
	// Line 478, Address: 0x14e8c4, Func Offset: 0x194
	// Line 477, Address: 0x14e8c8, Func Offset: 0x198
	// Line 479, Address: 0x14e8cc, Func Offset: 0x19c
	// Line 483, Address: 0x14e8d0, Func Offset: 0x1a0
	// Line 477, Address: 0x14e8d4, Func Offset: 0x1a4
	// Line 478, Address: 0x14e8dc, Func Offset: 0x1ac
	// Line 479, Address: 0x14e8f0, Func Offset: 0x1c0
	// Line 480, Address: 0x14e904, Func Offset: 0x1d4
	// Line 481, Address: 0x14e914, Func Offset: 0x1e4
	// Line 482, Address: 0x14e924, Func Offset: 0x1f4
	// Line 483, Address: 0x14e930, Func Offset: 0x200
	// Line 485, Address: 0x14e938, Func Offset: 0x208
	// Line 483, Address: 0x14e93c, Func Offset: 0x20c
	// Line 485, Address: 0x14e940, Func Offset: 0x210
	// Line 486, Address: 0x14e948, Func Offset: 0x218
	// Line 487, Address: 0x14e954, Func Offset: 0x224
	// Line 493, Address: 0x14e97c, Func Offset: 0x24c
	// Line 496, Address: 0x14e9a8, Func Offset: 0x278
	// Line 497, Address: 0x14e9ac, Func Offset: 0x27c
	// Line 494, Address: 0x14e9b0, Func Offset: 0x280
	// Line 495, Address: 0x14e9b4, Func Offset: 0x284
	// Line 501, Address: 0x14e9b8, Func Offset: 0x288
	// Line 502, Address: 0x14e9e0, Func Offset: 0x2b0
	// Line 503, Address: 0x14e9ec, Func Offset: 0x2bc
	// Line 505, Address: 0x14e9f0, Func Offset: 0x2c0
	// Line 503, Address: 0x14e9f4, Func Offset: 0x2c4
	// Line 504, Address: 0x14e9f8, Func Offset: 0x2c8
	// Line 505, Address: 0x14ea08, Func Offset: 0x2d8
	// Line 504, Address: 0x14ea0c, Func Offset: 0x2dc
	// Line 505, Address: 0x14ea18, Func Offset: 0x2e8
	// Line 506, Address: 0x14ea2c, Func Offset: 0x2fc
	// Line 508, Address: 0x14ea30, Func Offset: 0x300
	// Line 509, Address: 0x14ea34, Func Offset: 0x304
	// Line 506, Address: 0x14ea38, Func Offset: 0x308
	// Line 507, Address: 0x14ea40, Func Offset: 0x310
	// Line 508, Address: 0x14ea44, Func Offset: 0x314
	// Line 509, Address: 0x14ea4c, Func Offset: 0x31c
	// Line 510, Address: 0x14ea54, Func Offset: 0x324
	// Line 511, Address: 0x14ea7c, Func Offset: 0x34c
	// Line 512, Address: 0x14ea84, Func Offset: 0x354
	// Line 531, Address: 0x14ea8c, Func Offset: 0x35c
	// Line 533, Address: 0x14ea94, Func Offset: 0x364
	// Line 534, Address: 0x14ea98, Func Offset: 0x368
	// Func End, Address: 0x14eadc, Func Offset: 0x3ac
}

// 
// Start address: 0x14eae0
int bhSearchNearEnemyB(_anon23* pos, int ay, int ar, float len)
{
	int i;
	BH_PWORK* epp;
	float ln;
	float er;
	float a;
	_anon40 cap;
	_anon23 vc2;
	_anon23 vc1;
	_anon23 vc0;
	// Line 549, Address: 0x14eae0, Func Offset: 0
	// Line 555, Address: 0x14eb10, Func Offset: 0x30
	// Line 557, Address: 0x14eb1c, Func Offset: 0x3c
	// Line 556, Address: 0x14eb20, Func Offset: 0x40
	// Line 558, Address: 0x14eb24, Func Offset: 0x44
	// Line 557, Address: 0x14eb28, Func Offset: 0x48
	// Line 558, Address: 0x14eb2c, Func Offset: 0x4c
	// Line 559, Address: 0x14eb34, Func Offset: 0x54
	// Line 560, Address: 0x14eb3c, Func Offset: 0x5c
	// Line 561, Address: 0x14eb48, Func Offset: 0x68
	// Line 562, Address: 0x14eb58, Func Offset: 0x78
	// Line 563, Address: 0x14eb64, Func Offset: 0x84
	// Line 564, Address: 0x14eb74, Func Offset: 0x94
	// Line 565, Address: 0x14eb84, Func Offset: 0xa4
	// Line 568, Address: 0x14eb88, Func Offset: 0xa8
	// Line 569, Address: 0x14eb90, Func Offset: 0xb0
	// Line 565, Address: 0x14eb98, Func Offset: 0xb8
	// Line 566, Address: 0x14eb9c, Func Offset: 0xbc
	// Line 571, Address: 0x14eba0, Func Offset: 0xc0
	// Line 566, Address: 0x14eba4, Func Offset: 0xc4
	// Line 567, Address: 0x14eba8, Func Offset: 0xc8
	// Line 571, Address: 0x14ebb0, Func Offset: 0xd0
	// Line 572, Address: 0x14ebb8, Func Offset: 0xd8
	// Line 578, Address: 0x14ec04, Func Offset: 0x124
	// Line 581, Address: 0x14ec28, Func Offset: 0x148
	// Line 583, Address: 0x14ec38, Func Offset: 0x158
	// Line 581, Address: 0x14ec3c, Func Offset: 0x15c
	// Line 587, Address: 0x14ec44, Func Offset: 0x164
	// Line 581, Address: 0x14ec48, Func Offset: 0x168
	// Line 582, Address: 0x14ec50, Func Offset: 0x170
	// Line 583, Address: 0x14ec64, Func Offset: 0x184
	// Line 584, Address: 0x14ec78, Func Offset: 0x198
	// Line 585, Address: 0x14ec88, Func Offset: 0x1a8
	// Line 586, Address: 0x14ec8c, Func Offset: 0x1ac
	// Line 587, Address: 0x14ec98, Func Offset: 0x1b8
	// Line 588, Address: 0x14eca0, Func Offset: 0x1c0
	// Line 589, Address: 0x14ecb0, Func Offset: 0x1d0
	// Line 590, Address: 0x14ecb8, Func Offset: 0x1d8
	// Line 591, Address: 0x14ecc4, Func Offset: 0x1e4
	// Line 593, Address: 0x14ece8, Func Offset: 0x208
	// Line 596, Address: 0x14ecf0, Func Offset: 0x210
	// Line 597, Address: 0x14ed18, Func Offset: 0x238
	// Line 598, Address: 0x14ed1c, Func Offset: 0x23c
	// Func End, Address: 0x14ed44, Func Offset: 0x264
}

// 
// Start address: 0x14ed50
int bhSearchNearEnemy2(BH_PWORK* pp, int* r, float* h, int* id)
{
	int yr;
	int ar;
	int idx;
	int i;
	BH_PWORK* epp;
	float nr;
	float ln;
	float er;
	float a;
	float epz;
	float epy;
	float epx;
	_anon40 cap;
	_anon23 vc2;
	_anon23 vc1;
	_anon23 vc0;
	// Line 616, Address: 0x14ed50, Func Offset: 0
	// Line 632, Address: 0x14ed94, Func Offset: 0x44
	// Line 635, Address: 0x14ed9c, Func Offset: 0x4c
	// Line 632, Address: 0x14edac, Func Offset: 0x5c
	// Line 633, Address: 0x14edb4, Func Offset: 0x64
	// Line 634, Address: 0x14edc0, Func Offset: 0x70
	// Line 635, Address: 0x14edc8, Func Offset: 0x78
	// Line 636, Address: 0x14edcc, Func Offset: 0x7c
	// Line 638, Address: 0x14edd0, Func Offset: 0x80
	// Line 640, Address: 0x14eddc, Func Offset: 0x8c
	// Line 639, Address: 0x14ede0, Func Offset: 0x90
	// Line 641, Address: 0x14ede4, Func Offset: 0x94
	// Line 640, Address: 0x14ede8, Func Offset: 0x98
	// Line 641, Address: 0x14edec, Func Offset: 0x9c
	// Line 642, Address: 0x14edf4, Func Offset: 0xa4
	// Line 643, Address: 0x14edfc, Func Offset: 0xac
	// Line 644, Address: 0x14ee08, Func Offset: 0xb8
	// Line 645, Address: 0x14ee18, Func Offset: 0xc8
	// Line 646, Address: 0x14ee24, Func Offset: 0xd4
	// Line 647, Address: 0x14ee34, Func Offset: 0xe4
	// Line 648, Address: 0x14ee40, Func Offset: 0xf0
	// Line 649, Address: 0x14ee48, Func Offset: 0xf8
	// Line 650, Address: 0x14ee4c, Func Offset: 0xfc
	// Line 647, Address: 0x14ee50, Func Offset: 0x100
	// Line 651, Address: 0x14ee54, Func Offset: 0x104
	// Line 652, Address: 0x14ee5c, Func Offset: 0x10c
	// Line 656, Address: 0x14ee8c, Func Offset: 0x13c
	// Line 659, Address: 0x14eeb0, Func Offset: 0x160
	// Line 661, Address: 0x14eebc, Func Offset: 0x16c
	// Line 662, Address: 0x14eec0, Func Offset: 0x170
	// Line 663, Address: 0x14eec4, Func Offset: 0x174
	// Line 664, Address: 0x14eecc, Func Offset: 0x17c
	// Line 665, Address: 0x14eee8, Func Offset: 0x198
	// Line 666, Address: 0x14eeec, Func Offset: 0x19c
	// Line 667, Address: 0x14eef4, Func Offset: 0x1a4
	// Line 668, Address: 0x14eef8, Func Offset: 0x1a8
	// Line 671, Address: 0x14ef00, Func Offset: 0x1b0
	// Line 668, Address: 0x14ef04, Func Offset: 0x1b4
	// Line 669, Address: 0x14ef14, Func Offset: 0x1c4
	// Line 670, Address: 0x14ef24, Func Offset: 0x1d4
	// Line 671, Address: 0x14ef30, Func Offset: 0x1e0
	// Line 673, Address: 0x14ef38, Func Offset: 0x1e8
	// Line 671, Address: 0x14ef3c, Func Offset: 0x1ec
	// Line 673, Address: 0x14ef40, Func Offset: 0x1f0
	// Line 674, Address: 0x14ef48, Func Offset: 0x1f8
	// Line 676, Address: 0x14ef58, Func Offset: 0x208
	// Line 679, Address: 0x14ef80, Func Offset: 0x230
	// Line 680, Address: 0x14ef84, Func Offset: 0x234
	// Line 681, Address: 0x14ef88, Func Offset: 0x238
	// Line 677, Address: 0x14ef8c, Func Offset: 0x23c
	// Line 678, Address: 0x14ef90, Func Offset: 0x240
	// Line 685, Address: 0x14ef94, Func Offset: 0x244
	// Line 686, Address: 0x14efc0, Func Offset: 0x270
	// Line 690, Address: 0x14efcc, Func Offset: 0x27c
	// Line 691, Address: 0x14efec, Func Offset: 0x29c
	// Line 693, Address: 0x14eff8, Func Offset: 0x2a8
	// Line 694, Address: 0x14f000, Func Offset: 0x2b0
	// Line 691, Address: 0x14f004, Func Offset: 0x2b4
	// Line 692, Address: 0x14f014, Func Offset: 0x2c4
	// Line 693, Address: 0x14f018, Func Offset: 0x2c8
	// Line 694, Address: 0x14f024, Func Offset: 0x2d4
	// Line 695, Address: 0x14f02c, Func Offset: 0x2dc
	// Line 696, Address: 0x14f054, Func Offset: 0x304
	// Line 708, Address: 0x14f058, Func Offset: 0x308
	// Line 710, Address: 0x14f064, Func Offset: 0x314
	// Line 711, Address: 0x14f068, Func Offset: 0x318
	// Func End, Address: 0x14f0ac, Func Offset: 0x35c
}

// 
// Start address: 0x14f0b0
int bhSearchNextEnemy(BH_PWORK* pp, int r, float h)
{
	_anon8 scw[128];
	int yr;
	int idc;
	int id;
	int k;
	int j;
	int i;
	BH_PWORK* epp;
	float ln;
	float er;
	float a;
	_anon40 cap;
	_anon23 vc2;
	_anon23 vc1;
	_anon23 vc0;
	// Line 725, Address: 0x14f0b0, Func Offset: 0
	// Line 736, Address: 0x14f0ec, Func Offset: 0x3c
	// Line 738, Address: 0x14f0f8, Func Offset: 0x48
	// Line 737, Address: 0x14f0fc, Func Offset: 0x4c
	// Line 739, Address: 0x14f100, Func Offset: 0x50
	// Line 738, Address: 0x14f104, Func Offset: 0x54
	// Line 739, Address: 0x14f108, Func Offset: 0x58
	// Line 740, Address: 0x14f110, Func Offset: 0x60
	// Line 741, Address: 0x14f118, Func Offset: 0x68
	// Line 742, Address: 0x14f124, Func Offset: 0x74
	// Line 743, Address: 0x14f134, Func Offset: 0x84
	// Line 744, Address: 0x14f140, Func Offset: 0x90
	// Line 745, Address: 0x14f150, Func Offset: 0xa0
	// Line 764, Address: 0x14f160, Func Offset: 0xb0
	// Line 767, Address: 0x14f164, Func Offset: 0xb4
	// Line 768, Address: 0x14f16c, Func Offset: 0xbc
	// Line 764, Address: 0x14f174, Func Offset: 0xc4
	// Line 765, Address: 0x14f178, Func Offset: 0xc8
	// Line 771, Address: 0x14f17c, Func Offset: 0xcc
	// Line 765, Address: 0x14f180, Func Offset: 0xd0
	// Line 769, Address: 0x14f184, Func Offset: 0xd4
	// Line 765, Address: 0x14f188, Func Offset: 0xd8
	// Line 770, Address: 0x14f18c, Func Offset: 0xdc
	// Line 771, Address: 0x14f190, Func Offset: 0xe0
	// Line 765, Address: 0x14f198, Func Offset: 0xe8
	// Line 766, Address: 0x14f19c, Func Offset: 0xec
	// Line 771, Address: 0x14f1a4, Func Offset: 0xf4
	// Line 772, Address: 0x14f1ac, Func Offset: 0xfc
	// Line 778, Address: 0x14f1f8, Func Offset: 0x148
	// Line 780, Address: 0x14f21c, Func Offset: 0x16c
	// Line 781, Address: 0x14f220, Func Offset: 0x170
	// Line 782, Address: 0x14f230, Func Offset: 0x180
	// Line 781, Address: 0x14f234, Func Offset: 0x184
	// Line 783, Address: 0x14f23c, Func Offset: 0x18c
	// Line 787, Address: 0x14f240, Func Offset: 0x190
	// Line 781, Address: 0x14f244, Func Offset: 0x194
	// Line 782, Address: 0x14f24c, Func Offset: 0x19c
	// Line 783, Address: 0x14f260, Func Offset: 0x1b0
	// Line 784, Address: 0x14f274, Func Offset: 0x1c4
	// Line 785, Address: 0x14f27c, Func Offset: 0x1cc
	// Line 784, Address: 0x14f280, Func Offset: 0x1d0
	// Line 785, Address: 0x14f288, Func Offset: 0x1d8
	// Line 786, Address: 0x14f298, Func Offset: 0x1e8
	// Line 787, Address: 0x14f2a4, Func Offset: 0x1f4
	// Line 789, Address: 0x14f2ac, Func Offset: 0x1fc
	// Line 787, Address: 0x14f2b0, Func Offset: 0x200
	// Line 789, Address: 0x14f2b4, Func Offset: 0x204
	// Line 790, Address: 0x14f2bc, Func Offset: 0x20c
	// Line 791, Address: 0x14f2c8, Func Offset: 0x218
	// Line 798, Address: 0x14f2f0, Func Offset: 0x240
	// Line 799, Address: 0x14f2f8, Func Offset: 0x248
	// Line 800, Address: 0x14f308, Func Offset: 0x258
	// Line 801, Address: 0x14f31c, Func Offset: 0x26c
	// Line 802, Address: 0x14f338, Func Offset: 0x288
	// Line 803, Address: 0x14f340, Func Offset: 0x290
	// Line 802, Address: 0x14f348, Func Offset: 0x298
	// Line 803, Address: 0x14f350, Func Offset: 0x2a0
	// Line 804, Address: 0x14f358, Func Offset: 0x2a8
	// Line 806, Address: 0x14f368, Func Offset: 0x2b8
	// Line 808, Address: 0x14f370, Func Offset: 0x2c0
	// Line 809, Address: 0x14f380, Func Offset: 0x2d0
	// Line 810, Address: 0x14f388, Func Offset: 0x2d8
	// Line 813, Address: 0x14f38c, Func Offset: 0x2dc
	// Line 814, Address: 0x14f394, Func Offset: 0x2e4
	// Line 815, Address: 0x14f398, Func Offset: 0x2e8
	// Line 816, Address: 0x14f39c, Func Offset: 0x2ec
	// Line 815, Address: 0x14f3a0, Func Offset: 0x2f0
	// Line 818, Address: 0x14f3a4, Func Offset: 0x2f4
	// Line 820, Address: 0x14f3ac, Func Offset: 0x2fc
	// Line 823, Address: 0x14f3bc, Func Offset: 0x30c
	// Line 824, Address: 0x14f3e8, Func Offset: 0x338
	// Line 825, Address: 0x14f3f0, Func Offset: 0x340
	// Line 826, Address: 0x14f400, Func Offset: 0x350
	// Line 827, Address: 0x14f434, Func Offset: 0x384
	// Line 831, Address: 0x14f43c, Func Offset: 0x38c
	// Line 833, Address: 0x14f444, Func Offset: 0x394
	// Line 834, Address: 0x14f458, Func Offset: 0x3a8
	// Line 835, Address: 0x14f464, Func Offset: 0x3b4
	// Line 836, Address: 0x14f4b8, Func Offset: 0x408
	// Line 841, Address: 0x14f4d4, Func Offset: 0x424
	// Line 842, Address: 0x14f4dc, Func Offset: 0x42c
	// Line 850, Address: 0x14f4e4, Func Offset: 0x434
	// Line 849, Address: 0x14f504, Func Offset: 0x454
	// Line 851, Address: 0x14f508, Func Offset: 0x458
	// Line 852, Address: 0x14f50c, Func Offset: 0x45c
	// Line 854, Address: 0x14f514, Func Offset: 0x464
	// Line 855, Address: 0x14f518, Func Offset: 0x468
	// Line 851, Address: 0x14f51c, Func Offset: 0x46c
	// Line 852, Address: 0x14f524, Func Offset: 0x474
	// Line 853, Address: 0x14f540, Func Offset: 0x490
	// Line 854, Address: 0x14f544, Func Offset: 0x494
	// Line 855, Address: 0x14f55c, Func Offset: 0x4ac
	// Line 856, Address: 0x14f564, Func Offset: 0x4b4
	// Line 857, Address: 0x14f58c, Func Offset: 0x4dc
	// Line 874, Address: 0x14f598, Func Offset: 0x4e8
	// Line 875, Address: 0x14f5a0, Func Offset: 0x4f0
	// Line 880, Address: 0x14f5a4, Func Offset: 0x4f4
	// Func End, Address: 0x14f5dc, Func Offset: 0x52c
}

// 
// Start address: 0x14f5e0
int bhSearchPlayer(BH_PWORK* pp, int r)
{
	int yr;
	float er;
	float a;
	_anon23 vc2;
	_anon23 vc1;
	_anon23 vc0;
	// Line 891, Address: 0x14f5e0, Func Offset: 0
	// Line 898, Address: 0x14f600, Func Offset: 0x20
	// Line 900, Address: 0x14f60c, Func Offset: 0x2c
	// Line 899, Address: 0x14f610, Func Offset: 0x30
	// Line 901, Address: 0x14f614, Func Offset: 0x34
	// Line 900, Address: 0x14f618, Func Offset: 0x38
	// Line 901, Address: 0x14f61c, Func Offset: 0x3c
	// Line 902, Address: 0x14f624, Func Offset: 0x44
	// Line 903, Address: 0x14f62c, Func Offset: 0x4c
	// Line 904, Address: 0x14f638, Func Offset: 0x58
	// Line 905, Address: 0x14f648, Func Offset: 0x68
	// Line 906, Address: 0x14f654, Func Offset: 0x74
	// Line 907, Address: 0x14f664, Func Offset: 0x84
	// Line 926, Address: 0x14f670, Func Offset: 0x90
	// Line 907, Address: 0x14f678, Func Offset: 0x98
	// Line 926, Address: 0x14f67c, Func Offset: 0x9c
	// Line 929, Address: 0x14f680, Func Offset: 0xa0
	// Line 926, Address: 0x14f684, Func Offset: 0xa4
	// Line 927, Address: 0x14f690, Func Offset: 0xb0
	// Line 928, Address: 0x14f6a0, Func Offset: 0xc0
	// Line 929, Address: 0x14f6ac, Func Offset: 0xcc
	// Line 930, Address: 0x14f6b4, Func Offset: 0xd4
	// Line 931, Address: 0x14f6c0, Func Offset: 0xe0
	// Line 936, Address: 0x14f6d0, Func Offset: 0xf0
	// Line 937, Address: 0x14f6dc, Func Offset: 0xfc
	// Line 936, Address: 0x14f6e0, Func Offset: 0x100
	// Line 937, Address: 0x14f6ec, Func Offset: 0x10c
	// Line 938, Address: 0x14f6fc, Func Offset: 0x11c
	// Line 939, Address: 0x14f724, Func Offset: 0x144
	// Line 940, Address: 0x14f730, Func Offset: 0x150
	// Line 941, Address: 0x14f738, Func Offset: 0x158
	// Line 944, Address: 0x14f73c, Func Offset: 0x15c
	// Func End, Address: 0x14f75c, Func Offset: 0x17c
}

// 
// Start address: 0x14f760
int bhCheckL2Wall(_anon41* lp, unsigned int flg, float* len)
{
	_anon41 cln;
	int hit;
	int wal_n;
	int i;
	float lr;
	float ln;
	float nr;
	float d;
	float h;
	float w;
	float pz;
	float py;
	float px;
	float* psp;
	_anon23 pt;
	_anon23 ps;
	_anon41 pl;
	_anon40 cap2;
	_anon40 cap;
	_anon47 box;
	_anon0* hp;
	// Line 960, Address: 0x14f760, Func Offset: 0
	// Line 974, Address: 0x14f7b4, Func Offset: 0x54
	// Line 980, Address: 0x14f7b8, Func Offset: 0x58
	// Line 977, Address: 0x14f7bc, Func Offset: 0x5c
	// Line 980, Address: 0x14f7c4, Func Offset: 0x64
	// Line 974, Address: 0x14f7c8, Func Offset: 0x68
	// Line 975, Address: 0x14f7cc, Func Offset: 0x6c
	// Line 976, Address: 0x14f7dc, Func Offset: 0x7c
	// Line 977, Address: 0x14f7e4, Func Offset: 0x84
	// Line 978, Address: 0x14f7f4, Func Offset: 0x94
	// Line 979, Address: 0x14f804, Func Offset: 0xa4
	// Line 985, Address: 0x14f810, Func Offset: 0xb0
	// Line 979, Address: 0x14f814, Func Offset: 0xb4
	// Line 985, Address: 0x14f818, Func Offset: 0xb8
	// Line 988, Address: 0x14f820, Func Offset: 0xc0
	// Line 985, Address: 0x14f828, Func Offset: 0xc8
	// Line 987, Address: 0x14f82c, Func Offset: 0xcc
	// Line 988, Address: 0x14f830, Func Offset: 0xd0
	// Line 989, Address: 0x14f850, Func Offset: 0xf0
	// Line 991, Address: 0x14f870, Func Offset: 0x110
	// Line 992, Address: 0x14f8c0, Func Offset: 0x160
	// Line 998, Address: 0x14f8d0, Func Offset: 0x170
	// Line 1000, Address: 0x14f8d4, Func Offset: 0x174
	// Line 995, Address: 0x14f8d8, Func Offset: 0x178
	// Line 996, Address: 0x14f8dc, Func Offset: 0x17c
	// Line 997, Address: 0x14f8e0, Func Offset: 0x180
	// Line 999, Address: 0x14f8e4, Func Offset: 0x184
	// Line 1000, Address: 0x14f8e8, Func Offset: 0x188
	// Line 1001, Address: 0x14f900, Func Offset: 0x1a0
	// Line 1003, Address: 0x14f92c, Func Offset: 0x1cc
	// Line 1004, Address: 0x14f930, Func Offset: 0x1d0
	// Line 1006, Address: 0x14f948, Func Offset: 0x1e8
	// Line 1005, Address: 0x14f94c, Func Offset: 0x1ec
	// Line 1029, Address: 0x14f950, Func Offset: 0x1f0
	// Line 1007, Address: 0x14f954, Func Offset: 0x1f4
	// Line 1006, Address: 0x14f958, Func Offset: 0x1f8
	// Line 1029, Address: 0x14f95c, Func Offset: 0x1fc
	// Line 1007, Address: 0x14f960, Func Offset: 0x200
	// Line 1008, Address: 0x14f964, Func Offset: 0x204
	// Line 1009, Address: 0x14f968, Func Offset: 0x208
	// Line 1011, Address: 0x14f96c, Func Offset: 0x20c
	// Line 1010, Address: 0x14f970, Func Offset: 0x210
	// Line 1011, Address: 0x14f974, Func Offset: 0x214
	// Line 1012, Address: 0x14f978, Func Offset: 0x218
	// Line 1013, Address: 0x14f97c, Func Offset: 0x21c
	// Line 1014, Address: 0x14f980, Func Offset: 0x220
	// Line 1015, Address: 0x14f984, Func Offset: 0x224
	// Line 1016, Address: 0x14f988, Func Offset: 0x228
	// Line 1017, Address: 0x14f98c, Func Offset: 0x22c
	// Line 1018, Address: 0x14f990, Func Offset: 0x230
	// Line 1019, Address: 0x14f994, Func Offset: 0x234
	// Line 1020, Address: 0x14f998, Func Offset: 0x238
	// Line 1021, Address: 0x14f99c, Func Offset: 0x23c
	// Line 1022, Address: 0x14f9a0, Func Offset: 0x240
	// Line 1023, Address: 0x14f9a4, Func Offset: 0x244
	// Line 1024, Address: 0x14f9a8, Func Offset: 0x248
	// Line 1025, Address: 0x14f9ac, Func Offset: 0x24c
	// Line 1026, Address: 0x14f9b0, Func Offset: 0x250
	// Line 1027, Address: 0x14f9b4, Func Offset: 0x254
	// Line 1029, Address: 0x14f9b8, Func Offset: 0x258
	// Line 1032, Address: 0x14f9c8, Func Offset: 0x268
	// Line 1031, Address: 0x14f9d4, Func Offset: 0x274
	// Line 1032, Address: 0x14f9d8, Func Offset: 0x278
	// Line 1033, Address: 0x14f9e0, Func Offset: 0x280
	// Line 1032, Address: 0x14f9e4, Func Offset: 0x284
	// Line 1033, Address: 0x14f9e8, Func Offset: 0x288
	// Line 1035, Address: 0x14f9ec, Func Offset: 0x28c
	// Line 1034, Address: 0x14f9f4, Func Offset: 0x294
	// Line 1036, Address: 0x14f9f8, Func Offset: 0x298
	// Line 1035, Address: 0x14f9fc, Func Offset: 0x29c
	// Line 1037, Address: 0x14fa00, Func Offset: 0x2a0
	// Line 1038, Address: 0x14fa2c, Func Offset: 0x2cc
	// Line 1039, Address: 0x14fa34, Func Offset: 0x2d4
	// Line 1041, Address: 0x14fa38, Func Offset: 0x2d8
	// Line 1038, Address: 0x14fa3c, Func Offset: 0x2dc
	// Line 1039, Address: 0x14fa44, Func Offset: 0x2e4
	// Line 1040, Address: 0x14fa58, Func Offset: 0x2f8
	// Line 1041, Address: 0x14fa6c, Func Offset: 0x30c
	// Line 1042, Address: 0x14fa74, Func Offset: 0x314
	// Line 1043, Address: 0x14fa78, Func Offset: 0x318
	// Line 1045, Address: 0x14fa7c, Func Offset: 0x31c
	// Line 1042, Address: 0x14fa80, Func Offset: 0x320
	// Line 1043, Address: 0x14fa88, Func Offset: 0x328
	// Line 1044, Address: 0x14fa98, Func Offset: 0x338
	// Line 1045, Address: 0x14faac, Func Offset: 0x34c
	// Line 1048, Address: 0x14fb30, Func Offset: 0x3d0
	// Line 1051, Address: 0x14fb3c, Func Offset: 0x3dc
	// Line 1048, Address: 0x14fb40, Func Offset: 0x3e0
	// Line 1049, Address: 0x14fb58, Func Offset: 0x3f8
	// Line 1048, Address: 0x14fb5c, Func Offset: 0x3fc
	// Line 1049, Address: 0x14fb68, Func Offset: 0x408
	// Line 1052, Address: 0x14fb6c, Func Offset: 0x40c
	// Line 1049, Address: 0x14fb70, Func Offset: 0x410
	// Line 1050, Address: 0x14fb7c, Func Offset: 0x41c
	// Line 1054, Address: 0x14fb94, Func Offset: 0x434
	// Line 1057, Address: 0x14fb98, Func Offset: 0x438
	// Line 1056, Address: 0x14fba4, Func Offset: 0x444
	// Line 1057, Address: 0x14fba8, Func Offset: 0x448
	// Line 1060, Address: 0x14fbb0, Func Offset: 0x450
	// Line 1057, Address: 0x14fbb4, Func Offset: 0x454
	// Line 1058, Address: 0x14fbb8, Func Offset: 0x458
	// Line 1059, Address: 0x14fbbc, Func Offset: 0x45c
	// Line 1060, Address: 0x14fbc0, Func Offset: 0x460
	// Line 1062, Address: 0x14fbc4, Func Offset: 0x464
	// Line 1063, Address: 0x14fbf0, Func Offset: 0x490
	// Line 1064, Address: 0x14fbf8, Func Offset: 0x498
	// Line 1066, Address: 0x14fbfc, Func Offset: 0x49c
	// Line 1063, Address: 0x14fc00, Func Offset: 0x4a0
	// Line 1064, Address: 0x14fc08, Func Offset: 0x4a8
	// Line 1065, Address: 0x14fc1c, Func Offset: 0x4bc
	// Line 1066, Address: 0x14fc30, Func Offset: 0x4d0
	// Line 1067, Address: 0x14fc38, Func Offset: 0x4d8
	// Line 1068, Address: 0x14fc3c, Func Offset: 0x4dc
	// Line 1070, Address: 0x14fc40, Func Offset: 0x4e0
	// Line 1067, Address: 0x14fc44, Func Offset: 0x4e4
	// Line 1068, Address: 0x14fc4c, Func Offset: 0x4ec
	// Line 1069, Address: 0x14fc5c, Func Offset: 0x4fc
	// Line 1070, Address: 0x14fc70, Func Offset: 0x510
	// Line 1073, Address: 0x14fcf4, Func Offset: 0x594
	// Line 1076, Address: 0x14fd00, Func Offset: 0x5a0
	// Line 1073, Address: 0x14fd04, Func Offset: 0x5a4
	// Line 1074, Address: 0x14fd1c, Func Offset: 0x5bc
	// Line 1073, Address: 0x14fd20, Func Offset: 0x5c0
	// Line 1074, Address: 0x14fd2c, Func Offset: 0x5cc
	// Line 1077, Address: 0x14fd30, Func Offset: 0x5d0
	// Line 1074, Address: 0x14fd34, Func Offset: 0x5d4
	// Line 1075, Address: 0x14fd40, Func Offset: 0x5e0
	// Line 1081, Address: 0x14fd58, Func Offset: 0x5f8
	// Line 1084, Address: 0x14fd64, Func Offset: 0x604
	// Line 1081, Address: 0x14fd68, Func Offset: 0x608
	// Line 1082, Address: 0x14fd6c, Func Offset: 0x60c
	// Line 1087, Address: 0x14fd70, Func Offset: 0x610
	// Line 1081, Address: 0x14fd74, Func Offset: 0x614
	// Line 1082, Address: 0x14fd78, Func Offset: 0x618
	// Line 1083, Address: 0x14fd7c, Func Offset: 0x61c
	// Line 1084, Address: 0x14fd80, Func Offset: 0x620
	// Line 1085, Address: 0x14fd84, Func Offset: 0x624
	// Line 1087, Address: 0x14fd88, Func Offset: 0x628
	// Line 1088, Address: 0x14fdb0, Func Offset: 0x650
	// Line 1089, Address: 0x14fdb8, Func Offset: 0x658
	// Line 1091, Address: 0x14fdbc, Func Offset: 0x65c
	// Line 1088, Address: 0x14fdc0, Func Offset: 0x660
	// Line 1089, Address: 0x14fdc8, Func Offset: 0x668
	// Line 1090, Address: 0x14fddc, Func Offset: 0x67c
	// Line 1091, Address: 0x14fdf0, Func Offset: 0x690
	// Line 1092, Address: 0x14fdf8, Func Offset: 0x698
	// Line 1093, Address: 0x14fdfc, Func Offset: 0x69c
	// Line 1095, Address: 0x14fe00, Func Offset: 0x6a0
	// Line 1092, Address: 0x14fe04, Func Offset: 0x6a4
	// Line 1093, Address: 0x14fe0c, Func Offset: 0x6ac
	// Line 1094, Address: 0x14fe1c, Func Offset: 0x6bc
	// Line 1095, Address: 0x14fe30, Func Offset: 0x6d0
	// Line 1098, Address: 0x14feb4, Func Offset: 0x754
	// Line 1101, Address: 0x14fec0, Func Offset: 0x760
	// Line 1098, Address: 0x14fec4, Func Offset: 0x764
	// Line 1099, Address: 0x14fedc, Func Offset: 0x77c
	// Line 1098, Address: 0x14fee0, Func Offset: 0x780
	// Line 1099, Address: 0x14feec, Func Offset: 0x78c
	// Line 1102, Address: 0x14fef0, Func Offset: 0x790
	// Line 1099, Address: 0x14fef4, Func Offset: 0x794
	// Line 1100, Address: 0x14ff00, Func Offset: 0x7a0
	// Line 1106, Address: 0x14ff18, Func Offset: 0x7b8
	// Line 1109, Address: 0x14ff24, Func Offset: 0x7c4
	// Line 1106, Address: 0x14ff28, Func Offset: 0x7c8
	// Line 1107, Address: 0x14ff2c, Func Offset: 0x7cc
	// Line 1112, Address: 0x14ff30, Func Offset: 0x7d0
	// Line 1106, Address: 0x14ff34, Func Offset: 0x7d4
	// Line 1107, Address: 0x14ff38, Func Offset: 0x7d8
	// Line 1108, Address: 0x14ff3c, Func Offset: 0x7dc
	// Line 1109, Address: 0x14ff40, Func Offset: 0x7e0
	// Line 1110, Address: 0x14ff44, Func Offset: 0x7e4
	// Line 1112, Address: 0x14ff48, Func Offset: 0x7e8
	// Line 1113, Address: 0x14ff70, Func Offset: 0x810
	// Line 1114, Address: 0x14ff78, Func Offset: 0x818
	// Line 1116, Address: 0x14ff7c, Func Offset: 0x81c
	// Line 1113, Address: 0x14ff80, Func Offset: 0x820
	// Line 1114, Address: 0x14ff88, Func Offset: 0x828
	// Line 1115, Address: 0x14ff9c, Func Offset: 0x83c
	// Line 1116, Address: 0x14ffb0, Func Offset: 0x850
	// Line 1117, Address: 0x14ffb8, Func Offset: 0x858
	// Line 1118, Address: 0x14ffbc, Func Offset: 0x85c
	// Line 1120, Address: 0x14ffc0, Func Offset: 0x860
	// Line 1117, Address: 0x14ffc4, Func Offset: 0x864
	// Line 1118, Address: 0x14ffcc, Func Offset: 0x86c
	// Line 1119, Address: 0x14ffdc, Func Offset: 0x87c
	// Line 1120, Address: 0x14fff0, Func Offset: 0x890
	// Line 1123, Address: 0x150074, Func Offset: 0x914
	// Line 1126, Address: 0x150080, Func Offset: 0x920
	// Line 1123, Address: 0x150084, Func Offset: 0x924
	// Line 1124, Address: 0x15009c, Func Offset: 0x93c
	// Line 1123, Address: 0x1500a0, Func Offset: 0x940
	// Line 1124, Address: 0x1500ac, Func Offset: 0x94c
	// Line 1127, Address: 0x1500b0, Func Offset: 0x950
	// Line 1124, Address: 0x1500b4, Func Offset: 0x954
	// Line 1125, Address: 0x1500c0, Func Offset: 0x960
	// Line 1132, Address: 0x1500d8, Func Offset: 0x978
	// Line 1131, Address: 0x1500dc, Func Offset: 0x97c
	// Line 1132, Address: 0x1500e0, Func Offset: 0x980
	// Line 1133, Address: 0x1500e4, Func Offset: 0x984
	// Line 1137, Address: 0x1500f0, Func Offset: 0x990
	// Line 1133, Address: 0x1500f4, Func Offset: 0x994
	// Line 1136, Address: 0x1500f8, Func Offset: 0x998
	// Line 1137, Address: 0x1500fc, Func Offset: 0x99c
	// Line 1133, Address: 0x150100, Func Offset: 0x9a0
	// Line 1134, Address: 0x150104, Func Offset: 0x9a4
	// Line 1135, Address: 0x150108, Func Offset: 0x9a8
	// Line 1137, Address: 0x15010c, Func Offset: 0x9ac
	// Line 1138, Address: 0x150130, Func Offset: 0x9d0
	// Line 1139, Address: 0x150138, Func Offset: 0x9d8
	// Line 1141, Address: 0x15013c, Func Offset: 0x9dc
	// Line 1138, Address: 0x150140, Func Offset: 0x9e0
	// Line 1139, Address: 0x150148, Func Offset: 0x9e8
	// Line 1140, Address: 0x15015c, Func Offset: 0x9fc
	// Line 1141, Address: 0x150170, Func Offset: 0xa10
	// Line 1142, Address: 0x150178, Func Offset: 0xa18
	// Line 1143, Address: 0x15017c, Func Offset: 0xa1c
	// Line 1145, Address: 0x150180, Func Offset: 0xa20
	// Line 1142, Address: 0x150184, Func Offset: 0xa24
	// Line 1143, Address: 0x15018c, Func Offset: 0xa2c
	// Line 1144, Address: 0x15019c, Func Offset: 0xa3c
	// Line 1145, Address: 0x1501b0, Func Offset: 0xa50
	// Line 1148, Address: 0x150234, Func Offset: 0xad4
	// Line 1151, Address: 0x150240, Func Offset: 0xae0
	// Line 1148, Address: 0x150244, Func Offset: 0xae4
	// Line 1149, Address: 0x15025c, Func Offset: 0xafc
	// Line 1148, Address: 0x150260, Func Offset: 0xb00
	// Line 1149, Address: 0x15026c, Func Offset: 0xb0c
	// Line 1152, Address: 0x150270, Func Offset: 0xb10
	// Line 1149, Address: 0x150274, Func Offset: 0xb14
	// Line 1150, Address: 0x150280, Func Offset: 0xb20
	// Line 1157, Address: 0x150298, Func Offset: 0xb38
	// Line 1156, Address: 0x15029c, Func Offset: 0xb3c
	// Line 1157, Address: 0x1502a0, Func Offset: 0xb40
	// Line 1158, Address: 0x1502a4, Func Offset: 0xb44
	// Line 1162, Address: 0x1502b0, Func Offset: 0xb50
	// Line 1158, Address: 0x1502b4, Func Offset: 0xb54
	// Line 1161, Address: 0x1502b8, Func Offset: 0xb58
	// Line 1162, Address: 0x1502bc, Func Offset: 0xb5c
	// Line 1158, Address: 0x1502c0, Func Offset: 0xb60
	// Line 1159, Address: 0x1502c4, Func Offset: 0xb64
	// Line 1160, Address: 0x1502c8, Func Offset: 0xb68
	// Line 1162, Address: 0x1502cc, Func Offset: 0xb6c
	// Line 1163, Address: 0x1502f0, Func Offset: 0xb90
	// Line 1164, Address: 0x1502f8, Func Offset: 0xb98
	// Line 1165, Address: 0x150300, Func Offset: 0xba0
	// Line 1163, Address: 0x150304, Func Offset: 0xba4
	// Line 1165, Address: 0x150308, Func Offset: 0xba8
	// Line 1166, Address: 0x15030c, Func Offset: 0xbac
	// Line 1163, Address: 0x150310, Func Offset: 0xbb0
	// Line 1164, Address: 0x150314, Func Offset: 0xbb4
	// Line 1165, Address: 0x150324, Func Offset: 0xbc4
	// Line 1166, Address: 0x150330, Func Offset: 0xbd0
	// Line 1167, Address: 0x150338, Func Offset: 0xbd8
	// Line 1168, Address: 0x15033c, Func Offset: 0xbdc
	// Line 1170, Address: 0x150340, Func Offset: 0xbe0
	// Line 1167, Address: 0x150344, Func Offset: 0xbe4
	// Line 1168, Address: 0x15034c, Func Offset: 0xbec
	// Line 1169, Address: 0x150358, Func Offset: 0xbf8
	// Line 1170, Address: 0x150364, Func Offset: 0xc04
	// Line 1173, Address: 0x1503e0, Func Offset: 0xc80
	// Line 1176, Address: 0x1503ec, Func Offset: 0xc8c
	// Line 1173, Address: 0x1503f0, Func Offset: 0xc90
	// Line 1174, Address: 0x150408, Func Offset: 0xca8
	// Line 1173, Address: 0x15040c, Func Offset: 0xcac
	// Line 1174, Address: 0x150418, Func Offset: 0xcb8
	// Line 1177, Address: 0x15041c, Func Offset: 0xcbc
	// Line 1174, Address: 0x150420, Func Offset: 0xcc0
	// Line 1175, Address: 0x15042c, Func Offset: 0xccc
	// Line 1180, Address: 0x150440, Func Offset: 0xce0
	// Line 1183, Address: 0x150448, Func Offset: 0xce8
	// Line 1184, Address: 0x150460, Func Offset: 0xd00
	// Line 1185, Address: 0x150464, Func Offset: 0xd04
	// Line 1186, Address: 0x150468, Func Offset: 0xd08
	// Line 1188, Address: 0x15046c, Func Offset: 0xd0c
	// Line 1187, Address: 0x150470, Func Offset: 0xd10
	// Line 1191, Address: 0x150474, Func Offset: 0xd14
	// Line 1188, Address: 0x150478, Func Offset: 0xd18
	// Line 1189, Address: 0x15047c, Func Offset: 0xd1c
	// Line 1191, Address: 0x150480, Func Offset: 0xd20
	// Line 1194, Address: 0x150494, Func Offset: 0xd34
	// Line 1193, Address: 0x1504a0, Func Offset: 0xd40
	// Line 1194, Address: 0x1504a4, Func Offset: 0xd44
	// Line 1197, Address: 0x1504ac, Func Offset: 0xd4c
	// Line 1194, Address: 0x1504b0, Func Offset: 0xd50
	// Line 1195, Address: 0x1504b4, Func Offset: 0xd54
	// Line 1197, Address: 0x1504bc, Func Offset: 0xd5c
	// Line 1196, Address: 0x1504c0, Func Offset: 0xd60
	// Line 1197, Address: 0x1504c4, Func Offset: 0xd64
	// Line 1198, Address: 0x1504c8, Func Offset: 0xd68
	// Line 1199, Address: 0x1504cc, Func Offset: 0xd6c
	// Line 1198, Address: 0x1504d0, Func Offset: 0xd70
	// Line 1199, Address: 0x1504d4, Func Offset: 0xd74
	// Line 1200, Address: 0x1504e4, Func Offset: 0xd84
	// Line 1201, Address: 0x15050c, Func Offset: 0xdac
	// Line 1202, Address: 0x150514, Func Offset: 0xdb4
	// Line 1203, Address: 0x15051c, Func Offset: 0xdbc
	// Line 1201, Address: 0x150520, Func Offset: 0xdc0
	// Line 1203, Address: 0x150524, Func Offset: 0xdc4
	// Line 1204, Address: 0x150528, Func Offset: 0xdc8
	// Line 1201, Address: 0x15052c, Func Offset: 0xdcc
	// Line 1202, Address: 0x150530, Func Offset: 0xdd0
	// Line 1203, Address: 0x150540, Func Offset: 0xde0
	// Line 1204, Address: 0x15054c, Func Offset: 0xdec
	// Line 1205, Address: 0x150558, Func Offset: 0xdf8
	// Line 1207, Address: 0x15055c, Func Offset: 0xdfc
	// Line 1208, Address: 0x150560, Func Offset: 0xe00
	// Line 1205, Address: 0x150564, Func Offset: 0xe04
	// Line 1206, Address: 0x15056c, Func Offset: 0xe0c
	// Line 1207, Address: 0x150570, Func Offset: 0xe10
	// Line 1208, Address: 0x150578, Func Offset: 0xe18
	// Line 1210, Address: 0x150580, Func Offset: 0xe20
	// Line 1209, Address: 0x150584, Func Offset: 0xe24
	// Line 1210, Address: 0x15058c, Func Offset: 0xe2c
	// Line 1212, Address: 0x1505d0, Func Offset: 0xe70
	// Line 1215, Address: 0x1505dc, Func Offset: 0xe7c
	// Line 1212, Address: 0x1505e0, Func Offset: 0xe80
	// Line 1213, Address: 0x1505f8, Func Offset: 0xe98
	// Line 1212, Address: 0x1505fc, Func Offset: 0xe9c
	// Line 1213, Address: 0x150608, Func Offset: 0xea8
	// Line 1216, Address: 0x15060c, Func Offset: 0xeac
	// Line 1213, Address: 0x150610, Func Offset: 0xeb0
	// Line 1214, Address: 0x15061c, Func Offset: 0xebc
	// Line 1218, Address: 0x150634, Func Offset: 0xed4
	// Line 1221, Address: 0x150638, Func Offset: 0xed8
	// Line 1220, Address: 0x150644, Func Offset: 0xee4
	// Line 1221, Address: 0x150648, Func Offset: 0xee8
	// Line 1224, Address: 0x150650, Func Offset: 0xef0
	// Line 1221, Address: 0x150654, Func Offset: 0xef4
	// Line 1222, Address: 0x150658, Func Offset: 0xef8
	// Line 1224, Address: 0x150660, Func Offset: 0xf00
	// Line 1223, Address: 0x150664, Func Offset: 0xf04
	// Line 1224, Address: 0x150668, Func Offset: 0xf08
	// Line 1225, Address: 0x15066c, Func Offset: 0xf0c
	// Line 1226, Address: 0x150670, Func Offset: 0xf10
	// Line 1227, Address: 0x15069c, Func Offset: 0xf3c
	// Line 1228, Address: 0x1506a4, Func Offset: 0xf44
	// Line 1229, Address: 0x1506ac, Func Offset: 0xf4c
	// Line 1227, Address: 0x1506b0, Func Offset: 0xf50
	// Line 1229, Address: 0x1506b4, Func Offset: 0xf54
	// Line 1230, Address: 0x1506b8, Func Offset: 0xf58
	// Line 1227, Address: 0x1506bc, Func Offset: 0xf5c
	// Line 1228, Address: 0x1506c0, Func Offset: 0xf60
	// Line 1229, Address: 0x1506d0, Func Offset: 0xf70
	// Line 1230, Address: 0x1506dc, Func Offset: 0xf7c
	// Line 1231, Address: 0x1506e8, Func Offset: 0xf88
	// Line 1233, Address: 0x1506ec, Func Offset: 0xf8c
	// Line 1234, Address: 0x1506f0, Func Offset: 0xf90
	// Line 1231, Address: 0x1506f4, Func Offset: 0xf94
	// Line 1232, Address: 0x1506fc, Func Offset: 0xf9c
	// Line 1233, Address: 0x150700, Func Offset: 0xfa0
	// Line 1234, Address: 0x150708, Func Offset: 0xfa8
	// Line 1236, Address: 0x150710, Func Offset: 0xfb0
	// Line 1235, Address: 0x150714, Func Offset: 0xfb4
	// Line 1236, Address: 0x15071c, Func Offset: 0xfbc
	// Line 1238, Address: 0x150760, Func Offset: 0x1000
	// Line 1241, Address: 0x15076c, Func Offset: 0x100c
	// Line 1238, Address: 0x150770, Func Offset: 0x1010
	// Line 1239, Address: 0x150788, Func Offset: 0x1028
	// Line 1238, Address: 0x15078c, Func Offset: 0x102c
	// Line 1239, Address: 0x150798, Func Offset: 0x1038
	// Line 1242, Address: 0x15079c, Func Offset: 0x103c
	// Line 1239, Address: 0x1507a0, Func Offset: 0x1040
	// Line 1240, Address: 0x1507ac, Func Offset: 0x104c
	// Line 1245, Address: 0x1507c4, Func Offset: 0x1064
	// Line 1249, Address: 0x1507c8, Func Offset: 0x1068
	// Line 1250, Address: 0x1507cc, Func Offset: 0x106c
	// Line 1251, Address: 0x1507d0, Func Offset: 0x1070
	// Line 1252, Address: 0x1507d4, Func Offset: 0x1074
	// Line 1253, Address: 0x1507d8, Func Offset: 0x1078
	// Line 1255, Address: 0x1507dc, Func Offset: 0x107c
	// Line 1256, Address: 0x1507f4, Func Offset: 0x1094
	// Line 1257, Address: 0x1507f8, Func Offset: 0x1098
	// Line 1258, Address: 0x1507fc, Func Offset: 0x109c
	// Line 1256, Address: 0x150804, Func Offset: 0x10a4
	// Line 1259, Address: 0x150808, Func Offset: 0x10a8
	// Line 1256, Address: 0x15080c, Func Offset: 0x10ac
	// Line 1257, Address: 0x150810, Func Offset: 0x10b0
	// Line 1258, Address: 0x150814, Func Offset: 0x10b4
	// Line 1259, Address: 0x15081c, Func Offset: 0x10bc
	// Line 1260, Address: 0x150824, Func Offset: 0x10c4
	// Line 1261, Address: 0x150834, Func Offset: 0x10d4
	// Line 1264, Address: 0x150838, Func Offset: 0x10d8
	// Line 1261, Address: 0x15083c, Func Offset: 0x10dc
	// Line 1262, Address: 0x150844, Func Offset: 0x10e4
	// Line 1263, Address: 0x150848, Func Offset: 0x10e8
	// Line 1264, Address: 0x150850, Func Offset: 0x10f0
	// Line 1265, Address: 0x150858, Func Offset: 0x10f8
	// Line 1266, Address: 0x15085c, Func Offset: 0x10fc
	// Line 1271, Address: 0x150860, Func Offset: 0x1100
	// Line 1265, Address: 0x150868, Func Offset: 0x1108
	// Line 1271, Address: 0x15086c, Func Offset: 0x110c
	// Line 1265, Address: 0x150870, Func Offset: 0x1110
	// Line 1266, Address: 0x150878, Func Offset: 0x1118
	// Line 1267, Address: 0x15087c, Func Offset: 0x111c
	// Line 1269, Address: 0x150890, Func Offset: 0x1130
	// Line 1268, Address: 0x150894, Func Offset: 0x1134
	// Line 1269, Address: 0x150898, Func Offset: 0x1138
	// Line 1270, Address: 0x15089c, Func Offset: 0x113c
	// Line 1271, Address: 0x1508a0, Func Offset: 0x1140
	// Line 1272, Address: 0x1508c0, Func Offset: 0x1160
	// Line 1275, Address: 0x1508c4, Func Offset: 0x1164
	// Line 1272, Address: 0x1508c8, Func Offset: 0x1168
	// Line 1273, Address: 0x1508d0, Func Offset: 0x1170
	// Line 1274, Address: 0x1508d4, Func Offset: 0x1174
	// Line 1275, Address: 0x1508dc, Func Offset: 0x117c
	// Line 1276, Address: 0x1508e4, Func Offset: 0x1184
	// Line 1279, Address: 0x1508e8, Func Offset: 0x1188
	// Line 1281, Address: 0x1508ec, Func Offset: 0x118c
	// Line 1276, Address: 0x1508f0, Func Offset: 0x1190
	// Line 1277, Address: 0x1508fc, Func Offset: 0x119c
	// Line 1278, Address: 0x15090c, Func Offset: 0x11ac
	// Line 1279, Address: 0x15091c, Func Offset: 0x11bc
	// Line 1280, Address: 0x15092c, Func Offset: 0x11cc
	// Line 1281, Address: 0x150938, Func Offset: 0x11d8
	// Line 1282, Address: 0x150940, Func Offset: 0x11e0
	// Line 1283, Address: 0x150944, Func Offset: 0x11e4
	// Line 1282, Address: 0x150948, Func Offset: 0x11e8
	// Line 1283, Address: 0x150950, Func Offset: 0x11f0
	// Line 1285, Address: 0x150984, Func Offset: 0x1224
	// Line 1288, Address: 0x150990, Func Offset: 0x1230
	// Line 1285, Address: 0x150994, Func Offset: 0x1234
	// Line 1286, Address: 0x1509ac, Func Offset: 0x124c
	// Line 1285, Address: 0x1509b0, Func Offset: 0x1250
	// Line 1286, Address: 0x1509bc, Func Offset: 0x125c
	// Line 1289, Address: 0x1509c0, Func Offset: 0x1260
	// Line 1286, Address: 0x1509c4, Func Offset: 0x1264
	// Line 1287, Address: 0x1509d0, Func Offset: 0x1270
	// Line 1293, Address: 0x1509e4, Func Offset: 0x1284
	// Line 1296, Address: 0x1509ec, Func Offset: 0x128c
	// Line 1297, Address: 0x150a08, Func Offset: 0x12a8
	// Line 1300, Address: 0x150a40, Func Offset: 0x12e0
	// Line 1299, Address: 0x150a44, Func Offset: 0x12e4
	// Line 1301, Address: 0x150a48, Func Offset: 0x12e8
	// Line 1300, Address: 0x150a4c, Func Offset: 0x12ec
	// Line 1301, Address: 0x150a50, Func Offset: 0x12f0
	// Line 1302, Address: 0x150a54, Func Offset: 0x12f4
	// Line 1303, Address: 0x150a58, Func Offset: 0x12f8
	// Line 1305, Address: 0x150a5c, Func Offset: 0x12fc
	// Line 1304, Address: 0x150a60, Func Offset: 0x1300
	// Line 1305, Address: 0x150a64, Func Offset: 0x1304
	// Line 1306, Address: 0x150a68, Func Offset: 0x1308
	// Line 1307, Address: 0x150a6c, Func Offset: 0x130c
	// Line 1308, Address: 0x150a70, Func Offset: 0x1310
	// Line 1309, Address: 0x150a74, Func Offset: 0x1314
	// Line 1310, Address: 0x150a78, Func Offset: 0x1318
	// Line 1311, Address: 0x150a7c, Func Offset: 0x131c
	// Line 1312, Address: 0x150a80, Func Offset: 0x1320
	// Line 1313, Address: 0x150a84, Func Offset: 0x1324
	// Line 1314, Address: 0x150a88, Func Offset: 0x1328
	// Line 1315, Address: 0x150a8c, Func Offset: 0x132c
	// Line 1316, Address: 0x150a90, Func Offset: 0x1330
	// Line 1317, Address: 0x150a94, Func Offset: 0x1334
	// Line 1318, Address: 0x150a98, Func Offset: 0x1338
	// Line 1319, Address: 0x150a9c, Func Offset: 0x133c
	// Line 1320, Address: 0x150aa0, Func Offset: 0x1340
	// Line 1321, Address: 0x150aa4, Func Offset: 0x1344
	// Line 1323, Address: 0x150aa8, Func Offset: 0x1348
	// Line 1326, Address: 0x150ab0, Func Offset: 0x1350
	// Line 1325, Address: 0x150ab4, Func Offset: 0x1354
	// Line 1326, Address: 0x150ab8, Func Offset: 0x1358
	// Line 1327, Address: 0x150abc, Func Offset: 0x135c
	// Line 1328, Address: 0x150ac0, Func Offset: 0x1360
	// Line 1330, Address: 0x150ac4, Func Offset: 0x1364
	// Line 1329, Address: 0x150ac8, Func Offset: 0x1368
	// Line 1331, Address: 0x150acc, Func Offset: 0x136c
	// Line 1330, Address: 0x150ad0, Func Offset: 0x1370
	// Line 1331, Address: 0x150ad4, Func Offset: 0x1374
	// Line 1332, Address: 0x150ad8, Func Offset: 0x1378
	// Line 1333, Address: 0x150adc, Func Offset: 0x137c
	// Line 1334, Address: 0x150ae0, Func Offset: 0x1380
	// Line 1335, Address: 0x150ae4, Func Offset: 0x1384
	// Line 1336, Address: 0x150ae8, Func Offset: 0x1388
	// Line 1337, Address: 0x150aec, Func Offset: 0x138c
	// Line 1338, Address: 0x150af0, Func Offset: 0x1390
	// Line 1339, Address: 0x150af4, Func Offset: 0x1394
	// Line 1340, Address: 0x150af8, Func Offset: 0x1398
	// Line 1341, Address: 0x150afc, Func Offset: 0x139c
	// Line 1342, Address: 0x150b00, Func Offset: 0x13a0
	// Line 1343, Address: 0x150b04, Func Offset: 0x13a4
	// Line 1344, Address: 0x150b08, Func Offset: 0x13a8
	// Line 1345, Address: 0x150b0c, Func Offset: 0x13ac
	// Line 1346, Address: 0x150b10, Func Offset: 0x13b0
	// Line 1347, Address: 0x150b14, Func Offset: 0x13b4
	// Line 1349, Address: 0x150b18, Func Offset: 0x13b8
	// Line 1351, Address: 0x150b20, Func Offset: 0x13c0
	// Line 1352, Address: 0x150b24, Func Offset: 0x13c4
	// Line 1351, Address: 0x150b28, Func Offset: 0x13c8
	// Line 1353, Address: 0x150b2c, Func Offset: 0x13cc
	// Line 1352, Address: 0x150b30, Func Offset: 0x13d0
	// Line 1353, Address: 0x150b34, Func Offset: 0x13d4
	// Line 1354, Address: 0x150b38, Func Offset: 0x13d8
	// Line 1355, Address: 0x150b3c, Func Offset: 0x13dc
	// Line 1356, Address: 0x150b40, Func Offset: 0x13e0
	// Line 1357, Address: 0x150b44, Func Offset: 0x13e4
	// Line 1358, Address: 0x150b48, Func Offset: 0x13e8
	// Line 1359, Address: 0x150b4c, Func Offset: 0x13ec
	// Line 1360, Address: 0x150b50, Func Offset: 0x13f0
	// Line 1361, Address: 0x150b54, Func Offset: 0x13f4
	// Line 1362, Address: 0x150b58, Func Offset: 0x13f8
	// Line 1363, Address: 0x150b5c, Func Offset: 0x13fc
	// Line 1364, Address: 0x150b60, Func Offset: 0x1400
	// Line 1365, Address: 0x150b64, Func Offset: 0x1404
	// Line 1366, Address: 0x150b68, Func Offset: 0x1408
	// Line 1367, Address: 0x150b6c, Func Offset: 0x140c
	// Line 1368, Address: 0x150b70, Func Offset: 0x1410
	// Line 1369, Address: 0x150b74, Func Offset: 0x1414
	// Line 1370, Address: 0x150b78, Func Offset: 0x1418
	// Line 1371, Address: 0x150b7c, Func Offset: 0x141c
	// Line 1372, Address: 0x150b80, Func Offset: 0x1420
	// Line 1373, Address: 0x150b84, Func Offset: 0x1424
	// Line 1375, Address: 0x150b88, Func Offset: 0x1428
	// Line 1377, Address: 0x150b90, Func Offset: 0x1430
	// Line 1378, Address: 0x150b94, Func Offset: 0x1434
	// Line 1377, Address: 0x150b98, Func Offset: 0x1438
	// Line 1378, Address: 0x150b9c, Func Offset: 0x143c
	// Line 1379, Address: 0x150ba0, Func Offset: 0x1440
	// Line 1380, Address: 0x150ba4, Func Offset: 0x1444
	// Line 1382, Address: 0x150ba8, Func Offset: 0x1448
	// Line 1381, Address: 0x150bac, Func Offset: 0x144c
	// Line 1382, Address: 0x150bb0, Func Offset: 0x1450
	// Line 1383, Address: 0x150bb4, Func Offset: 0x1454
	// Line 1384, Address: 0x150bb8, Func Offset: 0x1458
	// Line 1385, Address: 0x150bbc, Func Offset: 0x145c
	// Line 1386, Address: 0x150bc0, Func Offset: 0x1460
	// Line 1387, Address: 0x150bc4, Func Offset: 0x1464
	// Line 1388, Address: 0x150bc8, Func Offset: 0x1468
	// Line 1389, Address: 0x150bcc, Func Offset: 0x146c
	// Line 1390, Address: 0x150bd0, Func Offset: 0x1470
	// Line 1391, Address: 0x150bd4, Func Offset: 0x1474
	// Line 1392, Address: 0x150bd8, Func Offset: 0x1478
	// Line 1393, Address: 0x150bdc, Func Offset: 0x147c
	// Line 1394, Address: 0x150be0, Func Offset: 0x1480
	// Line 1395, Address: 0x150be4, Func Offset: 0x1484
	// Line 1396, Address: 0x150be8, Func Offset: 0x1488
	// Line 1397, Address: 0x150bec, Func Offset: 0x148c
	// Line 1398, Address: 0x150bf0, Func Offset: 0x1490
	// Line 1399, Address: 0x150bf4, Func Offset: 0x1494
	// Line 1400, Address: 0x150bf8, Func Offset: 0x1498
	// Line 1402, Address: 0x150bfc, Func Offset: 0x149c
	// Line 1403, Address: 0x150c00, Func Offset: 0x14a0
	// Line 1406, Address: 0x150c14, Func Offset: 0x14b4
	// Line 1405, Address: 0x150c28, Func Offset: 0x14c8
	// Line 1406, Address: 0x150c2c, Func Offset: 0x14cc
	// Line 1407, Address: 0x150c30, Func Offset: 0x14d0
	// Line 1409, Address: 0x150c34, Func Offset: 0x14d4
	// Line 1406, Address: 0x150c38, Func Offset: 0x14d8
	// Line 1407, Address: 0x150c3c, Func Offset: 0x14dc
	// Line 1409, Address: 0x150c40, Func Offset: 0x14e0
	// Line 1408, Address: 0x150c44, Func Offset: 0x14e4
	// Line 1410, Address: 0x150c48, Func Offset: 0x14e8
	// Line 1409, Address: 0x150c4c, Func Offset: 0x14ec
	// Line 1411, Address: 0x150c50, Func Offset: 0x14f0
	// Line 1412, Address: 0x150c7c, Func Offset: 0x151c
	// Line 1413, Address: 0x150c84, Func Offset: 0x1524
	// Line 1414, Address: 0x150c88, Func Offset: 0x1528
	// Line 1415, Address: 0x150c8c, Func Offset: 0x152c
	// Line 1412, Address: 0x150c90, Func Offset: 0x1530
	// Line 1413, Address: 0x150c98, Func Offset: 0x1538
	// Line 1414, Address: 0x150ca4, Func Offset: 0x1544
	// Line 1415, Address: 0x150cac, Func Offset: 0x154c
	// Line 1416, Address: 0x150cb4, Func Offset: 0x1554
	// Line 1415, Address: 0x150cbc, Func Offset: 0x155c
	// Line 1416, Address: 0x150cc0, Func Offset: 0x1560
	// Line 1417, Address: 0x150ce4, Func Offset: 0x1584
	// Line 1420, Address: 0x150cf0, Func Offset: 0x1590
	// Line 1417, Address: 0x150cf4, Func Offset: 0x1594
	// Line 1418, Address: 0x150d0c, Func Offset: 0x15ac
	// Line 1417, Address: 0x150d10, Func Offset: 0x15b0
	// Line 1418, Address: 0x150d1c, Func Offset: 0x15bc
	// Line 1421, Address: 0x150d20, Func Offset: 0x15c0
	// Line 1418, Address: 0x150d24, Func Offset: 0x15c4
	// Line 1419, Address: 0x150d30, Func Offset: 0x15d0
	// Line 1426, Address: 0x150d48, Func Offset: 0x15e8
	// Line 1425, Address: 0x150d54, Func Offset: 0x15f4
	// Line 1426, Address: 0x150d58, Func Offset: 0x15f8
	// Line 1429, Address: 0x150d60, Func Offset: 0x1600
	// Line 1426, Address: 0x150d64, Func Offset: 0x1604
	// Line 1427, Address: 0x150d68, Func Offset: 0x1608
	// Line 1428, Address: 0x150d6c, Func Offset: 0x160c
	// Line 1429, Address: 0x150d70, Func Offset: 0x1610
	// Line 1431, Address: 0x150d74, Func Offset: 0x1614
	// Line 1432, Address: 0x150da0, Func Offset: 0x1640
	// Line 1433, Address: 0x150da8, Func Offset: 0x1648
	// Line 1434, Address: 0x150dac, Func Offset: 0x164c
	// Line 1435, Address: 0x150db0, Func Offset: 0x1650
	// Line 1432, Address: 0x150db4, Func Offset: 0x1654
	// Line 1433, Address: 0x150dbc, Func Offset: 0x165c
	// Line 1434, Address: 0x150dc8, Func Offset: 0x1668
	// Line 1435, Address: 0x150dd0, Func Offset: 0x1670
	// Line 1436, Address: 0x150dd8, Func Offset: 0x1678
	// Line 1435, Address: 0x150de0, Func Offset: 0x1680
	// Line 1436, Address: 0x150de4, Func Offset: 0x1684
	// Line 1437, Address: 0x150e08, Func Offset: 0x16a8
	// Line 1440, Address: 0x150e14, Func Offset: 0x16b4
	// Line 1437, Address: 0x150e18, Func Offset: 0x16b8
	// Line 1438, Address: 0x150e30, Func Offset: 0x16d0
	// Line 1437, Address: 0x150e34, Func Offset: 0x16d4
	// Line 1438, Address: 0x150e40, Func Offset: 0x16e0
	// Line 1441, Address: 0x150e44, Func Offset: 0x16e4
	// Line 1438, Address: 0x150e48, Func Offset: 0x16e8
	// Line 1439, Address: 0x150e54, Func Offset: 0x16f4
	// Line 1443, Address: 0x150e6c, Func Offset: 0x170c
	// Line 1447, Address: 0x150e70, Func Offset: 0x1710
	// Line 1446, Address: 0x150e74, Func Offset: 0x1714
	// Line 1447, Address: 0x150e78, Func Offset: 0x1718
	// Line 1445, Address: 0x150e7c, Func Offset: 0x171c
	// Line 1447, Address: 0x150e80, Func Offset: 0x1720
	// Line 1448, Address: 0x150ea4, Func Offset: 0x1744
	// Line 1449, Address: 0x150ec0, Func Offset: 0x1760
	// Line 1450, Address: 0x150ec4, Func Offset: 0x1764
	// Line 1451, Address: 0x150ec8, Func Offset: 0x1768
	// Line 1452, Address: 0x150ecc, Func Offset: 0x176c
	// Line 1451, Address: 0x150ed4, Func Offset: 0x1774
	// Line 1452, Address: 0x150ed8, Func Offset: 0x1778
	// Line 1453, Address: 0x150ef8, Func Offset: 0x1798
	// Line 1454, Address: 0x150f00, Func Offset: 0x17a0
	// Line 1455, Address: 0x150f04, Func Offset: 0x17a4
	// Line 1456, Address: 0x150f08, Func Offset: 0x17a8
	// Line 1453, Address: 0x150f0c, Func Offset: 0x17ac
	// Line 1454, Address: 0x150f14, Func Offset: 0x17b4
	// Line 1455, Address: 0x150f20, Func Offset: 0x17c0
	// Line 1456, Address: 0x150f28, Func Offset: 0x17c8
	// Line 1457, Address: 0x150f30, Func Offset: 0x17d0
	// Line 1456, Address: 0x150f38, Func Offset: 0x17d8
	// Line 1457, Address: 0x150f3c, Func Offset: 0x17dc
	// Line 1458, Address: 0x150f60, Func Offset: 0x1800
	// Line 1461, Address: 0x150f6c, Func Offset: 0x180c
	// Line 1458, Address: 0x150f70, Func Offset: 0x1810
	// Line 1459, Address: 0x150f88, Func Offset: 0x1828
	// Line 1458, Address: 0x150f8c, Func Offset: 0x182c
	// Line 1459, Address: 0x150f98, Func Offset: 0x1838
	// Line 1462, Address: 0x150f9c, Func Offset: 0x183c
	// Line 1459, Address: 0x150fa0, Func Offset: 0x1840
	// Line 1460, Address: 0x150fac, Func Offset: 0x184c
	// Line 1464, Address: 0x150fc4, Func Offset: 0x1864
	// Line 1466, Address: 0x150fc8, Func Offset: 0x1868
	// Line 1467, Address: 0x150ffc, Func Offset: 0x189c
	// Line 1468, Address: 0x151018, Func Offset: 0x18b8
	// Line 1469, Address: 0x151020, Func Offset: 0x18c0
	// Line 1470, Address: 0x151024, Func Offset: 0x18c4
	// Line 1471, Address: 0x15102c, Func Offset: 0x18cc
	// Line 1473, Address: 0x151030, Func Offset: 0x18d0
	// Line 1474, Address: 0x15105c, Func Offset: 0x18fc
	// Line 1475, Address: 0x151064, Func Offset: 0x1904
	// Line 1476, Address: 0x151068, Func Offset: 0x1908
	// Line 1477, Address: 0x15106c, Func Offset: 0x190c
	// Line 1474, Address: 0x151070, Func Offset: 0x1910
	// Line 1475, Address: 0x151078, Func Offset: 0x1918
	// Line 1476, Address: 0x151084, Func Offset: 0x1924
	// Line 1477, Address: 0x15108c, Func Offset: 0x192c
	// Line 1478, Address: 0x151094, Func Offset: 0x1934
	// Line 1477, Address: 0x15109c, Func Offset: 0x193c
	// Line 1478, Address: 0x1510a0, Func Offset: 0x1940
	// Line 1479, Address: 0x1510c4, Func Offset: 0x1964
	// Line 1482, Address: 0x1510d0, Func Offset: 0x1970
	// Line 1479, Address: 0x1510d4, Func Offset: 0x1974
	// Line 1480, Address: 0x1510ec, Func Offset: 0x198c
	// Line 1479, Address: 0x1510f0, Func Offset: 0x1990
	// Line 1480, Address: 0x1510fc, Func Offset: 0x199c
	// Line 1483, Address: 0x151100, Func Offset: 0x19a0
	// Line 1480, Address: 0x151104, Func Offset: 0x19a4
	// Line 1481, Address: 0x151110, Func Offset: 0x19b0
	// Line 1487, Address: 0x151128, Func Offset: 0x19c8
	// Line 1489, Address: 0x15112c, Func Offset: 0x19cc
	// Line 1491, Address: 0x151130, Func Offset: 0x19d0
	// Line 1487, Address: 0x151134, Func Offset: 0x19d4
	// Line 1488, Address: 0x151138, Func Offset: 0x19d8
	// Line 1489, Address: 0x15113c, Func Offset: 0x19dc
	// Line 1490, Address: 0x151140, Func Offset: 0x19e0
	// Line 1491, Address: 0x151144, Func Offset: 0x19e4
	// Line 1494, Address: 0x151178, Func Offset: 0x1a18
	// Line 1496, Address: 0x15117c, Func Offset: 0x1a1c
	// Line 1499, Address: 0x151184, Func Offset: 0x1a24
	// Line 1500, Address: 0x15118c, Func Offset: 0x1a2c
	// Line 1502, Address: 0x151194, Func Offset: 0x1a34
	// Line 1503, Address: 0x151198, Func Offset: 0x1a38
	// Line 1504, Address: 0x1511a4, Func Offset: 0x1a44
	// Line 1506, Address: 0x1511b8, Func Offset: 0x1a58
	// Line 1504, Address: 0x1511bc, Func Offset: 0x1a5c
	// Line 1506, Address: 0x1511c0, Func Offset: 0x1a60
	// Line 1504, Address: 0x1511c8, Func Offset: 0x1a68
	// Line 1505, Address: 0x1511d0, Func Offset: 0x1a70
	// Line 1506, Address: 0x1511e0, Func Offset: 0x1a80
	// Line 1507, Address: 0x151200, Func Offset: 0x1aa0
	// Line 1508, Address: 0x151208, Func Offset: 0x1aa8
	// Line 1509, Address: 0x15120c, Func Offset: 0x1aac
	// Line 1510, Address: 0x151210, Func Offset: 0x1ab0
	// Line 1507, Address: 0x151214, Func Offset: 0x1ab4
	// Line 1508, Address: 0x15121c, Func Offset: 0x1abc
	// Line 1509, Address: 0x151228, Func Offset: 0x1ac8
	// Line 1510, Address: 0x151230, Func Offset: 0x1ad0
	// Line 1511, Address: 0x151238, Func Offset: 0x1ad8
	// Line 1510, Address: 0x151240, Func Offset: 0x1ae0
	// Line 1511, Address: 0x151244, Func Offset: 0x1ae4
	// Line 1512, Address: 0x151268, Func Offset: 0x1b08
	// Line 1515, Address: 0x151274, Func Offset: 0x1b14
	// Line 1512, Address: 0x151278, Func Offset: 0x1b18
	// Line 1513, Address: 0x151290, Func Offset: 0x1b30
	// Line 1512, Address: 0x151294, Func Offset: 0x1b34
	// Line 1513, Address: 0x1512a0, Func Offset: 0x1b40
	// Line 1516, Address: 0x1512a4, Func Offset: 0x1b44
	// Line 1513, Address: 0x1512a8, Func Offset: 0x1b48
	// Line 1514, Address: 0x1512b4, Func Offset: 0x1b54
	// Line 1519, Address: 0x1512c8, Func Offset: 0x1b68
	// Line 1522, Address: 0x1512d0, Func Offset: 0x1b70
	// Line 1521, Address: 0x1512d4, Func Offset: 0x1b74
	// Line 1545, Address: 0x1512d8, Func Offset: 0x1b78
	// Line 1523, Address: 0x1512dc, Func Offset: 0x1b7c
	// Line 1522, Address: 0x1512e0, Func Offset: 0x1b80
	// Line 1545, Address: 0x1512e4, Func Offset: 0x1b84
	// Line 1523, Address: 0x1512e8, Func Offset: 0x1b88
	// Line 1524, Address: 0x1512ec, Func Offset: 0x1b8c
	// Line 1525, Address: 0x1512f0, Func Offset: 0x1b90
	// Line 1527, Address: 0x1512f4, Func Offset: 0x1b94
	// Line 1526, Address: 0x1512f8, Func Offset: 0x1b98
	// Line 1527, Address: 0x1512fc, Func Offset: 0x1b9c
	// Line 1528, Address: 0x151300, Func Offset: 0x1ba0
	// Line 1529, Address: 0x151304, Func Offset: 0x1ba4
	// Line 1530, Address: 0x151308, Func Offset: 0x1ba8
	// Line 1531, Address: 0x15130c, Func Offset: 0x1bac
	// Line 1532, Address: 0x151310, Func Offset: 0x1bb0
	// Line 1533, Address: 0x151314, Func Offset: 0x1bb4
	// Line 1534, Address: 0x151318, Func Offset: 0x1bb8
	// Line 1535, Address: 0x15131c, Func Offset: 0x1bbc
	// Line 1536, Address: 0x151320, Func Offset: 0x1bc0
	// Line 1537, Address: 0x151324, Func Offset: 0x1bc4
	// Line 1538, Address: 0x151328, Func Offset: 0x1bc8
	// Line 1539, Address: 0x15132c, Func Offset: 0x1bcc
	// Line 1540, Address: 0x151330, Func Offset: 0x1bd0
	// Line 1541, Address: 0x151334, Func Offset: 0x1bd4
	// Line 1542, Address: 0x151338, Func Offset: 0x1bd8
	// Line 1543, Address: 0x15133c, Func Offset: 0x1bdc
	// Line 1545, Address: 0x151340, Func Offset: 0x1be0
	// Line 1547, Address: 0x151350, Func Offset: 0x1bf0
	// Line 1549, Address: 0x151388, Func Offset: 0x1c28
	// Line 1550, Address: 0x15138c, Func Offset: 0x1c2c
	// Line 1551, Address: 0x151390, Func Offset: 0x1c30
	// Line 1552, Address: 0x151394, Func Offset: 0x1c34
	// Line 1553, Address: 0x15139c, Func Offset: 0x1c3c
	// Line 1555, Address: 0x1513a0, Func Offset: 0x1c40
	// Line 1556, Address: 0x1513ac, Func Offset: 0x1c4c
	// Line 1558, Address: 0x1513b4, Func Offset: 0x1c54
	// Line 1559, Address: 0x1513b8, Func Offset: 0x1c58
	// Line 1560, Address: 0x1513bc, Func Offset: 0x1c5c
	// Line 1561, Address: 0x1513c0, Func Offset: 0x1c60
	// Line 1562, Address: 0x1513c4, Func Offset: 0x1c64
	// Line 1564, Address: 0x1513c8, Func Offset: 0x1c68
	// Line 1565, Address: 0x1513d4, Func Offset: 0x1c74
	// Line 1567, Address: 0x1513dc, Func Offset: 0x1c7c
	// Line 1568, Address: 0x1513e0, Func Offset: 0x1c80
	// Line 1569, Address: 0x1513e4, Func Offset: 0x1c84
	// Line 1570, Address: 0x1513e8, Func Offset: 0x1c88
	// Line 1571, Address: 0x1513ec, Func Offset: 0x1c8c
	// Line 1572, Address: 0x1513f0, Func Offset: 0x1c90
	// Line 1573, Address: 0x1513f8, Func Offset: 0x1c98
	// Line 1574, Address: 0x151400, Func Offset: 0x1ca0
	// Line 1576, Address: 0x151408, Func Offset: 0x1ca8
	// Line 1577, Address: 0x15140c, Func Offset: 0x1cac
	// Line 1578, Address: 0x151410, Func Offset: 0x1cb0
	// Line 1579, Address: 0x151414, Func Offset: 0x1cb4
	// Line 1580, Address: 0x151418, Func Offset: 0x1cb8
	// Line 1582, Address: 0x15141c, Func Offset: 0x1cbc
	// Line 1585, Address: 0x151428, Func Offset: 0x1cc8
	// Line 1586, Address: 0x151450, Func Offset: 0x1cf0
	// Line 1587, Address: 0x151458, Func Offset: 0x1cf8
	// Line 1588, Address: 0x151460, Func Offset: 0x1d00
	// Line 1586, Address: 0x151464, Func Offset: 0x1d04
	// Line 1588, Address: 0x151468, Func Offset: 0x1d08
	// Line 1589, Address: 0x15146c, Func Offset: 0x1d0c
	// Line 1586, Address: 0x151470, Func Offset: 0x1d10
	// Line 1587, Address: 0x151474, Func Offset: 0x1d14
	// Line 1588, Address: 0x151484, Func Offset: 0x1d24
	// Line 1589, Address: 0x151490, Func Offset: 0x1d30
	// Line 1590, Address: 0x151498, Func Offset: 0x1d38
	// Line 1591, Address: 0x15149c, Func Offset: 0x1d3c
	// Line 1593, Address: 0x1514a0, Func Offset: 0x1d40
	// Line 1590, Address: 0x1514a4, Func Offset: 0x1d44
	// Line 1591, Address: 0x1514ac, Func Offset: 0x1d4c
	// Line 1592, Address: 0x1514b8, Func Offset: 0x1d58
	// Line 1593, Address: 0x1514c4, Func Offset: 0x1d64
	// Line 1596, Address: 0x151540, Func Offset: 0x1de0
	// Line 1599, Address: 0x15154c, Func Offset: 0x1dec
	// Line 1596, Address: 0x151550, Func Offset: 0x1df0
	// Line 1597, Address: 0x151568, Func Offset: 0x1e08
	// Line 1596, Address: 0x15156c, Func Offset: 0x1e0c
	// Line 1597, Address: 0x151578, Func Offset: 0x1e18
	// Line 1600, Address: 0x15157c, Func Offset: 0x1e1c
	// Line 1597, Address: 0x151580, Func Offset: 0x1e20
	// Line 1598, Address: 0x15158c, Func Offset: 0x1e2c
	// Line 1745, Address: 0x1515a0, Func Offset: 0x1e40
	// Line 1748, Address: 0x1515a8, Func Offset: 0x1e48
	// Line 1749, Address: 0x1515b4, Func Offset: 0x1e54
	// Line 1747, Address: 0x1515b8, Func Offset: 0x1e58
	// Line 1771, Address: 0x1515bc, Func Offset: 0x1e5c
	// Line 1748, Address: 0x1515c0, Func Offset: 0x1e60
	// Line 1771, Address: 0x1515c4, Func Offset: 0x1e64
	// Line 1748, Address: 0x1515c8, Func Offset: 0x1e68
	// Line 1749, Address: 0x1515cc, Func Offset: 0x1e6c
	// Line 1750, Address: 0x1515d0, Func Offset: 0x1e70
	// Line 1751, Address: 0x1515d4, Func Offset: 0x1e74
	// Line 1753, Address: 0x1515d8, Func Offset: 0x1e78
	// Line 1752, Address: 0x1515dc, Func Offset: 0x1e7c
	// Line 1753, Address: 0x1515e0, Func Offset: 0x1e80
	// Line 1754, Address: 0x1515e4, Func Offset: 0x1e84
	// Line 1755, Address: 0x1515e8, Func Offset: 0x1e88
	// Line 1756, Address: 0x1515ec, Func Offset: 0x1e8c
	// Line 1757, Address: 0x1515f0, Func Offset: 0x1e90
	// Line 1758, Address: 0x1515f4, Func Offset: 0x1e94
	// Line 1760, Address: 0x1515f8, Func Offset: 0x1e98
	// Line 1759, Address: 0x1515fc, Func Offset: 0x1e9c
	// Line 1760, Address: 0x151600, Func Offset: 0x1ea0
	// Line 1761, Address: 0x151604, Func Offset: 0x1ea4
	// Line 1762, Address: 0x151608, Func Offset: 0x1ea8
	// Line 1763, Address: 0x15160c, Func Offset: 0x1eac
	// Line 1764, Address: 0x151610, Func Offset: 0x1eb0
	// Line 1765, Address: 0x151614, Func Offset: 0x1eb4
	// Line 1766, Address: 0x151618, Func Offset: 0x1eb8
	// Line 1767, Address: 0x15161c, Func Offset: 0x1ebc
	// Line 1768, Address: 0x151620, Func Offset: 0x1ec0
	// Line 1769, Address: 0x151624, Func Offset: 0x1ec4
	// Line 1771, Address: 0x151628, Func Offset: 0x1ec8
	// Line 1774, Address: 0x151638, Func Offset: 0x1ed8
	// Line 1773, Address: 0x151644, Func Offset: 0x1ee4
	// Line 1774, Address: 0x151648, Func Offset: 0x1ee8
	// Line 1775, Address: 0x151650, Func Offset: 0x1ef0
	// Line 1774, Address: 0x151654, Func Offset: 0x1ef4
	// Line 1775, Address: 0x151658, Func Offset: 0x1ef8
	// Line 1777, Address: 0x15165c, Func Offset: 0x1efc
	// Line 1776, Address: 0x151664, Func Offset: 0x1f04
	// Line 1778, Address: 0x151668, Func Offset: 0x1f08
	// Line 1777, Address: 0x15166c, Func Offset: 0x1f0c
	// Line 1779, Address: 0x151670, Func Offset: 0x1f10
	// Line 1780, Address: 0x15169c, Func Offset: 0x1f3c
	// Line 1781, Address: 0x1516a4, Func Offset: 0x1f44
	// Line 1783, Address: 0x1516a8, Func Offset: 0x1f48
	// Line 1780, Address: 0x1516ac, Func Offset: 0x1f4c
	// Line 1781, Address: 0x1516b4, Func Offset: 0x1f54
	// Line 1782, Address: 0x1516c8, Func Offset: 0x1f68
	// Line 1783, Address: 0x1516dc, Func Offset: 0x1f7c
	// Line 1784, Address: 0x1516e4, Func Offset: 0x1f84
	// Line 1785, Address: 0x1516e8, Func Offset: 0x1f88
	// Line 1787, Address: 0x1516ec, Func Offset: 0x1f8c
	// Line 1784, Address: 0x1516f0, Func Offset: 0x1f90
	// Line 1785, Address: 0x1516f8, Func Offset: 0x1f98
	// Line 1786, Address: 0x151708, Func Offset: 0x1fa8
	// Line 1787, Address: 0x15171c, Func Offset: 0x1fbc
	// Line 1790, Address: 0x1517a0, Func Offset: 0x2040
	// Line 1793, Address: 0x1517ac, Func Offset: 0x204c
	// Line 1790, Address: 0x1517b0, Func Offset: 0x2050
	// Line 1791, Address: 0x1517c8, Func Offset: 0x2068
	// Line 1790, Address: 0x1517cc, Func Offset: 0x206c
	// Line 1791, Address: 0x1517d8, Func Offset: 0x2078
	// Line 1794, Address: 0x1517dc, Func Offset: 0x207c
	// Line 1791, Address: 0x1517e0, Func Offset: 0x2080
	// Line 1792, Address: 0x1517ec, Func Offset: 0x208c
	// Line 1796, Address: 0x151804, Func Offset: 0x20a4
	// Line 1799, Address: 0x151808, Func Offset: 0x20a8
	// Line 1798, Address: 0x151814, Func Offset: 0x20b4
	// Line 1799, Address: 0x151818, Func Offset: 0x20b8
	// Line 1802, Address: 0x151820, Func Offset: 0x20c0
	// Line 1799, Address: 0x151824, Func Offset: 0x20c4
	// Line 1800, Address: 0x151828, Func Offset: 0x20c8
	// Line 1801, Address: 0x15182c, Func Offset: 0x20cc
	// Line 1802, Address: 0x151830, Func Offset: 0x20d0
	// Line 1804, Address: 0x151834, Func Offset: 0x20d4
	// Line 1805, Address: 0x151860, Func Offset: 0x2100
	// Line 1806, Address: 0x151868, Func Offset: 0x2108
	// Line 1808, Address: 0x15186c, Func Offset: 0x210c
	// Line 1805, Address: 0x151870, Func Offset: 0x2110
	// Line 1806, Address: 0x151878, Func Offset: 0x2118
	// Line 1807, Address: 0x15188c, Func Offset: 0x212c
	// Line 1808, Address: 0x1518a0, Func Offset: 0x2140
	// Line 1809, Address: 0x1518a8, Func Offset: 0x2148
	// Line 1810, Address: 0x1518ac, Func Offset: 0x214c
	// Line 1812, Address: 0x1518b0, Func Offset: 0x2150
	// Line 1809, Address: 0x1518b4, Func Offset: 0x2154
	// Line 1810, Address: 0x1518bc, Func Offset: 0x215c
	// Line 1811, Address: 0x1518cc, Func Offset: 0x216c
	// Line 1812, Address: 0x1518e0, Func Offset: 0x2180
	// Line 1815, Address: 0x151964, Func Offset: 0x2204
	// Line 1818, Address: 0x151970, Func Offset: 0x2210
	// Line 1815, Address: 0x151974, Func Offset: 0x2214
	// Line 1816, Address: 0x15198c, Func Offset: 0x222c
	// Line 1815, Address: 0x151990, Func Offset: 0x2230
	// Line 1816, Address: 0x15199c, Func Offset: 0x223c
	// Line 1819, Address: 0x1519a0, Func Offset: 0x2240
	// Line 1816, Address: 0x1519a4, Func Offset: 0x2244
	// Line 1817, Address: 0x1519b0, Func Offset: 0x2250
	// Line 1823, Address: 0x1519c8, Func Offset: 0x2268
	// Line 1826, Address: 0x1519d4, Func Offset: 0x2274
	// Line 1823, Address: 0x1519d8, Func Offset: 0x2278
	// Line 1824, Address: 0x1519dc, Func Offset: 0x227c
	// Line 1829, Address: 0x1519e0, Func Offset: 0x2280
	// Line 1823, Address: 0x1519e4, Func Offset: 0x2284
	// Line 1824, Address: 0x1519e8, Func Offset: 0x2288
	// Line 1825, Address: 0x1519ec, Func Offset: 0x228c
	// Line 1826, Address: 0x1519f0, Func Offset: 0x2290
	// Line 1827, Address: 0x1519f4, Func Offset: 0x2294
	// Line 1829, Address: 0x1519f8, Func Offset: 0x2298
	// Line 1830, Address: 0x151a20, Func Offset: 0x22c0
	// Line 1831, Address: 0x151a28, Func Offset: 0x22c8
	// Line 1833, Address: 0x151a2c, Func Offset: 0x22cc
	// Line 1830, Address: 0x151a30, Func Offset: 0x22d0
	// Line 1831, Address: 0x151a38, Func Offset: 0x22d8
	// Line 1832, Address: 0x151a4c, Func Offset: 0x22ec
	// Line 1833, Address: 0x151a60, Func Offset: 0x2300
	// Line 1834, Address: 0x151a68, Func Offset: 0x2308
	// Line 1835, Address: 0x151a6c, Func Offset: 0x230c
	// Line 1837, Address: 0x151a70, Func Offset: 0x2310
	// Line 1834, Address: 0x151a74, Func Offset: 0x2314
	// Line 1835, Address: 0x151a7c, Func Offset: 0x231c
	// Line 1836, Address: 0x151a8c, Func Offset: 0x232c
	// Line 1837, Address: 0x151aa0, Func Offset: 0x2340
	// Line 1840, Address: 0x151b24, Func Offset: 0x23c4
	// Line 1843, Address: 0x151b30, Func Offset: 0x23d0
	// Line 1840, Address: 0x151b34, Func Offset: 0x23d4
	// Line 1841, Address: 0x151b4c, Func Offset: 0x23ec
	// Line 1840, Address: 0x151b50, Func Offset: 0x23f0
	// Line 1841, Address: 0x151b5c, Func Offset: 0x23fc
	// Line 1844, Address: 0x151b60, Func Offset: 0x2400
	// Line 1841, Address: 0x151b64, Func Offset: 0x2404
	// Line 1842, Address: 0x151b70, Func Offset: 0x2410
	// Line 1848, Address: 0x151b88, Func Offset: 0x2428
	// Line 1851, Address: 0x151b94, Func Offset: 0x2434
	// Line 1848, Address: 0x151b98, Func Offset: 0x2438
	// Line 1849, Address: 0x151b9c, Func Offset: 0x243c
	// Line 1854, Address: 0x151ba0, Func Offset: 0x2440
	// Line 1848, Address: 0x151ba4, Func Offset: 0x2444
	// Line 1849, Address: 0x151ba8, Func Offset: 0x2448
	// Line 1850, Address: 0x151bac, Func Offset: 0x244c
	// Line 1851, Address: 0x151bb0, Func Offset: 0x2450
	// Line 1852, Address: 0x151bb4, Func Offset: 0x2454
	// Line 1854, Address: 0x151bb8, Func Offset: 0x2458
	// Line 1855, Address: 0x151be0, Func Offset: 0x2480
	// Line 1856, Address: 0x151be8, Func Offset: 0x2488
	// Line 1858, Address: 0x151bec, Func Offset: 0x248c
	// Line 1855, Address: 0x151bf0, Func Offset: 0x2490
	// Line 1856, Address: 0x151bf8, Func Offset: 0x2498
	// Line 1857, Address: 0x151c0c, Func Offset: 0x24ac
	// Line 1858, Address: 0x151c20, Func Offset: 0x24c0
	// Line 1859, Address: 0x151c28, Func Offset: 0x24c8
	// Line 1860, Address: 0x151c2c, Func Offset: 0x24cc
	// Line 1862, Address: 0x151c30, Func Offset: 0x24d0
	// Line 1859, Address: 0x151c34, Func Offset: 0x24d4
	// Line 1860, Address: 0x151c3c, Func Offset: 0x24dc
	// Line 1861, Address: 0x151c4c, Func Offset: 0x24ec
	// Line 1862, Address: 0x151c60, Func Offset: 0x2500
	// Line 1865, Address: 0x151ce4, Func Offset: 0x2584
	// Line 1868, Address: 0x151cf0, Func Offset: 0x2590
	// Line 1865, Address: 0x151cf4, Func Offset: 0x2594
	// Line 1866, Address: 0x151d0c, Func Offset: 0x25ac
	// Line 1865, Address: 0x151d10, Func Offset: 0x25b0
	// Line 1866, Address: 0x151d1c, Func Offset: 0x25bc
	// Line 1869, Address: 0x151d20, Func Offset: 0x25c0
	// Line 1866, Address: 0x151d24, Func Offset: 0x25c4
	// Line 1867, Address: 0x151d30, Func Offset: 0x25d0
	// Line 1874, Address: 0x151d48, Func Offset: 0x25e8
	// Line 1873, Address: 0x151d4c, Func Offset: 0x25ec
	// Line 1874, Address: 0x151d50, Func Offset: 0x25f0
	// Line 1875, Address: 0x151d54, Func Offset: 0x25f4
	// Line 1879, Address: 0x151d60, Func Offset: 0x2600
	// Line 1875, Address: 0x151d64, Func Offset: 0x2604
	// Line 1878, Address: 0x151d68, Func Offset: 0x2608
	// Line 1879, Address: 0x151d6c, Func Offset: 0x260c
	// Line 1875, Address: 0x151d70, Func Offset: 0x2610
	// Line 1876, Address: 0x151d74, Func Offset: 0x2614
	// Line 1877, Address: 0x151d78, Func Offset: 0x2618
	// Line 1879, Address: 0x151d7c, Func Offset: 0x261c
	// Line 1880, Address: 0x151da0, Func Offset: 0x2640
	// Line 1881, Address: 0x151da8, Func Offset: 0x2648
	// Line 1883, Address: 0x151dac, Func Offset: 0x264c
	// Line 1880, Address: 0x151db0, Func Offset: 0x2650
	// Line 1881, Address: 0x151db8, Func Offset: 0x2658
	// Line 1882, Address: 0x151dcc, Func Offset: 0x266c
	// Line 1883, Address: 0x151de0, Func Offset: 0x2680
	// Line 1884, Address: 0x151de8, Func Offset: 0x2688
	// Line 1885, Address: 0x151dec, Func Offset: 0x268c
	// Line 1887, Address: 0x151df0, Func Offset: 0x2690
	// Line 1884, Address: 0x151df4, Func Offset: 0x2694
	// Line 1885, Address: 0x151dfc, Func Offset: 0x269c
	// Line 1886, Address: 0x151e0c, Func Offset: 0x26ac
	// Line 1887, Address: 0x151e20, Func Offset: 0x26c0
	// Line 1890, Address: 0x151ea4, Func Offset: 0x2744
	// Line 1893, Address: 0x151eb0, Func Offset: 0x2750
	// Line 1890, Address: 0x151eb4, Func Offset: 0x2754
	// Line 1891, Address: 0x151ecc, Func Offset: 0x276c
	// Line 1890, Address: 0x151ed0, Func Offset: 0x2770
	// Line 1891, Address: 0x151edc, Func Offset: 0x277c
	// Line 1894, Address: 0x151ee0, Func Offset: 0x2780
	// Line 1891, Address: 0x151ee4, Func Offset: 0x2784
	// Line 1892, Address: 0x151ef0, Func Offset: 0x2790
	// Line 1899, Address: 0x151f08, Func Offset: 0x27a8
	// Line 1898, Address: 0x151f0c, Func Offset: 0x27ac
	// Line 1899, Address: 0x151f10, Func Offset: 0x27b0
	// Line 1900, Address: 0x151f14, Func Offset: 0x27b4
	// Line 1904, Address: 0x151f20, Func Offset: 0x27c0
	// Line 1900, Address: 0x151f24, Func Offset: 0x27c4
	// Line 1903, Address: 0x151f28, Func Offset: 0x27c8
	// Line 1904, Address: 0x151f2c, Func Offset: 0x27cc
	// Line 1900, Address: 0x151f30, Func Offset: 0x27d0
	// Line 1901, Address: 0x151f34, Func Offset: 0x27d4
	// Line 1902, Address: 0x151f38, Func Offset: 0x27d8
	// Line 1904, Address: 0x151f3c, Func Offset: 0x27dc
	// Line 1905, Address: 0x151f60, Func Offset: 0x2800
	// Line 1906, Address: 0x151f68, Func Offset: 0x2808
	// Line 1907, Address: 0x151f70, Func Offset: 0x2810
	// Line 1905, Address: 0x151f74, Func Offset: 0x2814
	// Line 1907, Address: 0x151f78, Func Offset: 0x2818
	// Line 1908, Address: 0x151f7c, Func Offset: 0x281c
	// Line 1905, Address: 0x151f80, Func Offset: 0x2820
	// Line 1906, Address: 0x151f84, Func Offset: 0x2824
	// Line 1907, Address: 0x151f94, Func Offset: 0x2834
	// Line 1908, Address: 0x151fa0, Func Offset: 0x2840
	// Line 1909, Address: 0x151fa8, Func Offset: 0x2848
	// Line 1910, Address: 0x151fac, Func Offset: 0x284c
	// Line 1912, Address: 0x151fb0, Func Offset: 0x2850
	// Line 1909, Address: 0x151fb4, Func Offset: 0x2854
	// Line 1910, Address: 0x151fbc, Func Offset: 0x285c
	// Line 1911, Address: 0x151fc8, Func Offset: 0x2868
	// Line 1912, Address: 0x151fd4, Func Offset: 0x2874
	// Line 1915, Address: 0x152050, Func Offset: 0x28f0
	// Line 1918, Address: 0x15205c, Func Offset: 0x28fc
	// Line 1915, Address: 0x152060, Func Offset: 0x2900
	// Line 1916, Address: 0x152078, Func Offset: 0x2918
	// Line 1915, Address: 0x15207c, Func Offset: 0x291c
	// Line 1916, Address: 0x152088, Func Offset: 0x2928
	// Line 1919, Address: 0x15208c, Func Offset: 0x292c
	// Line 1916, Address: 0x152090, Func Offset: 0x2930
	// Line 1917, Address: 0x15209c, Func Offset: 0x293c
	// Line 1924, Address: 0x1520b4, Func Offset: 0x2954
	// Line 1919, Address: 0x1520b8, Func Offset: 0x2958
	// Line 1924, Address: 0x1520bc, Func Offset: 0x295c
	// Line 1919, Address: 0x1520c0, Func Offset: 0x2960
	// Line 1924, Address: 0x1520c8, Func Offset: 0x2968
	// Line 1931, Address: 0x1520d8, Func Offset: 0x2978
	// Line 1932, Address: 0x1520dc, Func Offset: 0x297c
	// Line 1933, Address: 0x1520e4, Func Offset: 0x2984
	// Line 1937, Address: 0x1520f4, Func Offset: 0x2994
	// Line 1933, Address: 0x1520f8, Func Offset: 0x2998
	// Line 1934, Address: 0x152108, Func Offset: 0x29a8
	// Line 1935, Address: 0x152128, Func Offset: 0x29c8
	// Line 1936, Address: 0x152148, Func Offset: 0x29e8
	// Line 1937, Address: 0x152158, Func Offset: 0x29f8
	// Line 1939, Address: 0x152160, Func Offset: 0x2a00
	// Line 1940, Address: 0x152164, Func Offset: 0x2a04
	// Func End, Address: 0x1521bc, Func Offset: 0x2a5c
}

// 
// Start address: 0x1521c0
int bhCheckC2Wall(_anon40* cap)
{
	int wal_n;
	int i;
	float ln;
	float nr;
	float d;
	float h;
	float w;
	float pz;
	float py;
	float px;
	float* psp;
	_anon23 p[3];
	_anon23 pt;
	_anon23 ps;
	_anon41 pl;
	_anon41 lp;
	_anon40 cap2;
	_anon47 box;
	_anon0* hp;
	// Line 1953, Address: 0x1521c0, Func Offset: 0
	// Line 1966, Address: 0x152218, Func Offset: 0x58
	// Line 1967, Address: 0x15221c, Func Offset: 0x5c
	// Line 1968, Address: 0x152220, Func Offset: 0x60
	// Line 1969, Address: 0x152224, Func Offset: 0x64
	// Line 1966, Address: 0x152228, Func Offset: 0x68
	// Line 1967, Address: 0x15222c, Func Offset: 0x6c
	// Line 1968, Address: 0x152238, Func Offset: 0x78
	// Line 1969, Address: 0x152240, Func Offset: 0x80
	// Line 1970, Address: 0x152250, Func Offset: 0x90
	// Line 1971, Address: 0x152260, Func Offset: 0xa0
	// Line 1972, Address: 0x152268, Func Offset: 0xa8
	// Line 1971, Address: 0x15226c, Func Offset: 0xac
	// Line 1972, Address: 0x152270, Func Offset: 0xb0
	// Line 1974, Address: 0x152278, Func Offset: 0xb8
	// Line 1972, Address: 0x152280, Func Offset: 0xc0
	// Line 1974, Address: 0x152284, Func Offset: 0xc4
	// Line 1975, Address: 0x1522a4, Func Offset: 0xe4
	// Line 1977, Address: 0x1522bc, Func Offset: 0xfc
	// Line 1978, Address: 0x152308, Func Offset: 0x148
	// Line 1984, Address: 0x152328, Func Offset: 0x168
	// Line 1986, Address: 0x15232c, Func Offset: 0x16c
	// Line 1981, Address: 0x152330, Func Offset: 0x170
	// Line 1982, Address: 0x152334, Func Offset: 0x174
	// Line 1983, Address: 0x152338, Func Offset: 0x178
	// Line 1985, Address: 0x15233c, Func Offset: 0x17c
	// Line 1986, Address: 0x152340, Func Offset: 0x180
	// Line 1987, Address: 0x152358, Func Offset: 0x198
	// Line 1990, Address: 0x152390, Func Offset: 0x1d0
	// Line 1989, Address: 0x152394, Func Offset: 0x1d4
	// Line 2013, Address: 0x152398, Func Offset: 0x1d8
	// Line 1991, Address: 0x15239c, Func Offset: 0x1dc
	// Line 1990, Address: 0x1523a0, Func Offset: 0x1e0
	// Line 2013, Address: 0x1523a4, Func Offset: 0x1e4
	// Line 1991, Address: 0x1523a8, Func Offset: 0x1e8
	// Line 1992, Address: 0x1523ac, Func Offset: 0x1ec
	// Line 1993, Address: 0x1523b0, Func Offset: 0x1f0
	// Line 1995, Address: 0x1523b4, Func Offset: 0x1f4
	// Line 1994, Address: 0x1523b8, Func Offset: 0x1f8
	// Line 1995, Address: 0x1523bc, Func Offset: 0x1fc
	// Line 1996, Address: 0x1523c0, Func Offset: 0x200
	// Line 1997, Address: 0x1523c4, Func Offset: 0x204
	// Line 1998, Address: 0x1523c8, Func Offset: 0x208
	// Line 1999, Address: 0x1523cc, Func Offset: 0x20c
	// Line 2000, Address: 0x1523d0, Func Offset: 0x210
	// Line 2001, Address: 0x1523d4, Func Offset: 0x214
	// Line 2002, Address: 0x1523d8, Func Offset: 0x218
	// Line 2003, Address: 0x1523dc, Func Offset: 0x21c
	// Line 2004, Address: 0x1523e0, Func Offset: 0x220
	// Line 2005, Address: 0x1523e4, Func Offset: 0x224
	// Line 2006, Address: 0x1523e8, Func Offset: 0x228
	// Line 2007, Address: 0x1523ec, Func Offset: 0x22c
	// Line 2008, Address: 0x1523f0, Func Offset: 0x230
	// Line 2009, Address: 0x1523f4, Func Offset: 0x234
	// Line 2010, Address: 0x1523f8, Func Offset: 0x238
	// Line 2011, Address: 0x1523fc, Func Offset: 0x23c
	// Line 2013, Address: 0x152400, Func Offset: 0x240
	// Line 2016, Address: 0x152418, Func Offset: 0x258
	// Line 2017, Address: 0x15241c, Func Offset: 0x25c
	// Line 2018, Address: 0x152420, Func Offset: 0x260
	// Line 2020, Address: 0x152424, Func Offset: 0x264
	// Line 2019, Address: 0x152428, Func Offset: 0x268
	// Line 2023, Address: 0x15242c, Func Offset: 0x26c
	// Line 2020, Address: 0x152430, Func Offset: 0x270
	// Line 2021, Address: 0x152434, Func Offset: 0x274
	// Line 2023, Address: 0x152438, Func Offset: 0x278
	// Line 2028, Address: 0x152454, Func Offset: 0x294
	// Line 2027, Address: 0x152468, Func Offset: 0x2a8
	// Line 2028, Address: 0x15246c, Func Offset: 0x2ac
	// Line 2029, Address: 0x152470, Func Offset: 0x2b0
	// Line 2031, Address: 0x152474, Func Offset: 0x2b4
	// Line 2028, Address: 0x152478, Func Offset: 0x2b8
	// Line 2029, Address: 0x15247c, Func Offset: 0x2bc
	// Line 2031, Address: 0x152480, Func Offset: 0x2c0
	// Line 2030, Address: 0x152484, Func Offset: 0x2c4
	// Line 2031, Address: 0x152488, Func Offset: 0x2c8
	// Line 2032, Address: 0x15248c, Func Offset: 0x2cc
	// Line 2033, Address: 0x152490, Func Offset: 0x2d0
	// Line 2034, Address: 0x1524bc, Func Offset: 0x2fc
	// Line 2035, Address: 0x1524c4, Func Offset: 0x304
	// Line 2036, Address: 0x1524c8, Func Offset: 0x308
	// Line 2037, Address: 0x1524cc, Func Offset: 0x30c
	// Line 2034, Address: 0x1524d4, Func Offset: 0x314
	// Line 2035, Address: 0x1524dc, Func Offset: 0x31c
	// Line 2036, Address: 0x1524e8, Func Offset: 0x328
	// Line 2037, Address: 0x1524f0, Func Offset: 0x330
	// Line 2038, Address: 0x152510, Func Offset: 0x350
	// Line 2039, Address: 0x152518, Func Offset: 0x358
	// Line 2038, Address: 0x152520, Func Offset: 0x360
	// Line 2039, Address: 0x152524, Func Offset: 0x364
	// Line 2040, Address: 0x152548, Func Offset: 0x388
	// Line 2046, Address: 0x152550, Func Offset: 0x390
	// Line 2045, Address: 0x152554, Func Offset: 0x394
	// Line 2046, Address: 0x152558, Func Offset: 0x398
	// Line 2047, Address: 0x15255c, Func Offset: 0x39c
	// Line 2049, Address: 0x152560, Func Offset: 0x3a0
	// Line 2048, Address: 0x152564, Func Offset: 0x3a4
	// Line 2049, Address: 0x152568, Func Offset: 0x3a8
	// Line 2050, Address: 0x152570, Func Offset: 0x3b0
	// Line 2051, Address: 0x152574, Func Offset: 0x3b4
	// Line 2052, Address: 0x1525a0, Func Offset: 0x3e0
	// Line 2053, Address: 0x1525a8, Func Offset: 0x3e8
	// Line 2054, Address: 0x1525ac, Func Offset: 0x3ec
	// Line 2055, Address: 0x1525b0, Func Offset: 0x3f0
	// Line 2052, Address: 0x1525b8, Func Offset: 0x3f8
	// Line 2053, Address: 0x1525c0, Func Offset: 0x400
	// Line 2054, Address: 0x1525cc, Func Offset: 0x40c
	// Line 2055, Address: 0x1525d4, Func Offset: 0x414
	// Line 2056, Address: 0x1525f4, Func Offset: 0x434
	// Line 2057, Address: 0x1525fc, Func Offset: 0x43c
	// Line 2056, Address: 0x152604, Func Offset: 0x444
	// Line 2057, Address: 0x152608, Func Offset: 0x448
	// Line 2058, Address: 0x15262c, Func Offset: 0x46c
	// Line 2064, Address: 0x152634, Func Offset: 0x474
	// Line 2066, Address: 0x152638, Func Offset: 0x478
	// Line 2063, Address: 0x15263c, Func Offset: 0x47c
	// Line 2064, Address: 0x152640, Func Offset: 0x480
	// Line 2065, Address: 0x152644, Func Offset: 0x484
	// Line 2068, Address: 0x152648, Func Offset: 0x488
	// Line 2065, Address: 0x15264c, Func Offset: 0x48c
	// Line 2066, Address: 0x152650, Func Offset: 0x490
	// Line 2067, Address: 0x152658, Func Offset: 0x498
	// Line 2068, Address: 0x152660, Func Offset: 0x4a0
	// Line 2069, Address: 0x152668, Func Offset: 0x4a8
	// Line 2070, Address: 0x152670, Func Offset: 0x4b0
	// Line 2071, Address: 0x152678, Func Offset: 0x4b8
	// Line 2072, Address: 0x15267c, Func Offset: 0x4bc
	// Line 2071, Address: 0x152680, Func Offset: 0x4c0
	// Line 2072, Address: 0x152684, Func Offset: 0x4c4
	// Line 2073, Address: 0x15268c, Func Offset: 0x4cc
	// Line 2076, Address: 0x152694, Func Offset: 0x4d4
	// Line 2074, Address: 0x152698, Func Offset: 0x4d8
	// Line 2076, Address: 0x1526a0, Func Offset: 0x4e0
	// Line 2074, Address: 0x1526a4, Func Offset: 0x4e4
	// Line 2076, Address: 0x1526a8, Func Offset: 0x4e8
	// Line 2073, Address: 0x1526ac, Func Offset: 0x4ec
	// Line 2075, Address: 0x1526b8, Func Offset: 0x4f8
	// Line 2074, Address: 0x1526bc, Func Offset: 0x4fc
	// Line 2075, Address: 0x1526c0, Func Offset: 0x500
	// Line 2076, Address: 0x1526c4, Func Offset: 0x504
	// Line 2077, Address: 0x1526cc, Func Offset: 0x50c
	// Line 2078, Address: 0x1526d4, Func Offset: 0x514
	// Line 2080, Address: 0x1526d8, Func Offset: 0x518
	// Line 2077, Address: 0x1526e0, Func Offset: 0x520
	// Line 2078, Address: 0x1526e8, Func Offset: 0x528
	// Line 2079, Address: 0x1526fc, Func Offset: 0x53c
	// Line 2080, Address: 0x152710, Func Offset: 0x550
	// Line 2081, Address: 0x152730, Func Offset: 0x570
	// Line 2082, Address: 0x152738, Func Offset: 0x578
	// Line 2081, Address: 0x152740, Func Offset: 0x580
	// Line 2082, Address: 0x152744, Func Offset: 0x584
	// Line 2083, Address: 0x152768, Func Offset: 0x5a8
	// Line 2087, Address: 0x152770, Func Offset: 0x5b0
	// Line 2086, Address: 0x152774, Func Offset: 0x5b4
	// Line 2087, Address: 0x152778, Func Offset: 0x5b8
	// Line 2088, Address: 0x15277c, Func Offset: 0x5bc
	// Line 2089, Address: 0x152784, Func Offset: 0x5c4
	// Line 2090, Address: 0x15278c, Func Offset: 0x5cc
	// Line 2091, Address: 0x152794, Func Offset: 0x5d4
	// Line 2092, Address: 0x15279c, Func Offset: 0x5dc
	// Line 2093, Address: 0x1527a4, Func Offset: 0x5e4
	// Line 2094, Address: 0x1527ac, Func Offset: 0x5ec
	// Line 2095, Address: 0x1527b0, Func Offset: 0x5f0
	// Line 2094, Address: 0x1527b4, Func Offset: 0x5f4
	// Line 2095, Address: 0x1527b8, Func Offset: 0x5f8
	// Line 2096, Address: 0x1527c0, Func Offset: 0x600
	// Line 2099, Address: 0x1527cc, Func Offset: 0x60c
	// Line 2096, Address: 0x1527d0, Func Offset: 0x610
	// Line 2097, Address: 0x1527d4, Func Offset: 0x614
	// Line 2099, Address: 0x1527d8, Func Offset: 0x618
	// Line 2096, Address: 0x1527dc, Func Offset: 0x61c
	// Line 2099, Address: 0x1527e0, Func Offset: 0x620
	// Line 2096, Address: 0x1527e4, Func Offset: 0x624
	// Line 2098, Address: 0x1527e8, Func Offset: 0x628
	// Line 2097, Address: 0x1527ec, Func Offset: 0x62c
	// Line 2098, Address: 0x1527f0, Func Offset: 0x630
	// Line 2099, Address: 0x1527f4, Func Offset: 0x634
	// Line 2100, Address: 0x1527fc, Func Offset: 0x63c
	// Line 2101, Address: 0x152804, Func Offset: 0x644
	// Line 2103, Address: 0x152808, Func Offset: 0x648
	// Line 2100, Address: 0x152810, Func Offset: 0x650
	// Line 2101, Address: 0x152818, Func Offset: 0x658
	// Line 2102, Address: 0x15282c, Func Offset: 0x66c
	// Line 2103, Address: 0x152840, Func Offset: 0x680
	// Line 2104, Address: 0x152860, Func Offset: 0x6a0
	// Line 2105, Address: 0x152868, Func Offset: 0x6a8
	// Line 2104, Address: 0x152870, Func Offset: 0x6b0
	// Line 2105, Address: 0x152874, Func Offset: 0x6b4
	// Line 2106, Address: 0x152898, Func Offset: 0x6d8
	// Line 2112, Address: 0x1528a0, Func Offset: 0x6e0
	// Line 2113, Address: 0x1528ac, Func Offset: 0x6ec
	// Line 2111, Address: 0x1528b0, Func Offset: 0x6f0
	// Line 2135, Address: 0x1528b4, Func Offset: 0x6f4
	// Line 2112, Address: 0x1528b8, Func Offset: 0x6f8
	// Line 2135, Address: 0x1528bc, Func Offset: 0x6fc
	// Line 2112, Address: 0x1528c0, Func Offset: 0x700
	// Line 2113, Address: 0x1528c4, Func Offset: 0x704
	// Line 2114, Address: 0x1528c8, Func Offset: 0x708
	// Line 2115, Address: 0x1528cc, Func Offset: 0x70c
	// Line 2117, Address: 0x1528d0, Func Offset: 0x710
	// Line 2116, Address: 0x1528d4, Func Offset: 0x714
	// Line 2117, Address: 0x1528d8, Func Offset: 0x718
	// Line 2118, Address: 0x1528dc, Func Offset: 0x71c
	// Line 2119, Address: 0x1528e0, Func Offset: 0x720
	// Line 2120, Address: 0x1528e4, Func Offset: 0x724
	// Line 2121, Address: 0x1528e8, Func Offset: 0x728
	// Line 2122, Address: 0x1528ec, Func Offset: 0x72c
	// Line 2124, Address: 0x1528f0, Func Offset: 0x730
	// Line 2123, Address: 0x1528f4, Func Offset: 0x734
	// Line 2124, Address: 0x1528f8, Func Offset: 0x738
	// Line 2125, Address: 0x1528fc, Func Offset: 0x73c
	// Line 2126, Address: 0x152900, Func Offset: 0x740
	// Line 2127, Address: 0x152904, Func Offset: 0x744
	// Line 2128, Address: 0x152908, Func Offset: 0x748
	// Line 2129, Address: 0x15290c, Func Offset: 0x74c
	// Line 2130, Address: 0x152910, Func Offset: 0x750
	// Line 2131, Address: 0x152914, Func Offset: 0x754
	// Line 2132, Address: 0x152918, Func Offset: 0x758
	// Line 2133, Address: 0x15291c, Func Offset: 0x75c
	// Line 2135, Address: 0x152920, Func Offset: 0x760
	// Line 2138, Address: 0x152938, Func Offset: 0x778
	// Line 2139, Address: 0x152950, Func Offset: 0x790
	// Line 2140, Address: 0x152954, Func Offset: 0x794
	// Func End, Address: 0x1529b0, Func Offset: 0x7f0
}

// 
// Start address: 0x1529b0
int bhCheckC2WallN(_anon40* cap, unsigned int flg)
{
	int wal_n;
	int i;
	float ln;
	float nr;
	float d;
	float h;
	float w;
	float pz;
	float py;
	float px;
	float* psp;
	_anon23 p[3];
	_anon23 pt;
	_anon23 ps;
	_anon41 pl;
	_anon41 lp;
	_anon40 cap2;
	_anon47 box;
	_anon0* hp;
	// Line 2153, Address: 0x1529b0, Func Offset: 0
	// Line 2162, Address: 0x152a08, Func Offset: 0x58
	// Line 2163, Address: 0x152a0c, Func Offset: 0x5c
	// Line 2164, Address: 0x152a10, Func Offset: 0x60
	// Line 2165, Address: 0x152a14, Func Offset: 0x64
	// Line 2162, Address: 0x152a18, Func Offset: 0x68
	// Line 2163, Address: 0x152a1c, Func Offset: 0x6c
	// Line 2164, Address: 0x152a2c, Func Offset: 0x7c
	// Line 2165, Address: 0x152a34, Func Offset: 0x84
	// Line 2166, Address: 0x152a44, Func Offset: 0x94
	// Line 2167, Address: 0x152a54, Func Offset: 0xa4
	// Line 2168, Address: 0x152a5c, Func Offset: 0xac
	// Line 2167, Address: 0x152a60, Func Offset: 0xb0
	// Line 2168, Address: 0x152a64, Func Offset: 0xb4
	// Line 2170, Address: 0x152a6c, Func Offset: 0xbc
	// Line 2168, Address: 0x152a74, Func Offset: 0xc4
	// Line 2170, Address: 0x152a78, Func Offset: 0xc8
	// Line 2171, Address: 0x152a98, Func Offset: 0xe8
	// Line 2173, Address: 0x152ac0, Func Offset: 0x110
	// Line 2174, Address: 0x152b0c, Func Offset: 0x15c
	// Line 2176, Address: 0x152b3c, Func Offset: 0x18c
	// Line 2182, Address: 0x152b40, Func Offset: 0x190
	// Line 2184, Address: 0x152b44, Func Offset: 0x194
	// Line 2179, Address: 0x152b48, Func Offset: 0x198
	// Line 2180, Address: 0x152b4c, Func Offset: 0x19c
	// Line 2181, Address: 0x152b50, Func Offset: 0x1a0
	// Line 2183, Address: 0x152b54, Func Offset: 0x1a4
	// Line 2184, Address: 0x152b58, Func Offset: 0x1a8
	// Line 2185, Address: 0x152b70, Func Offset: 0x1c0
	// Line 2187, Address: 0x152b9c, Func Offset: 0x1ec
	// Line 2188, Address: 0x152ba0, Func Offset: 0x1f0
	// Line 2190, Address: 0x152bb8, Func Offset: 0x208
	// Line 2189, Address: 0x152bbc, Func Offset: 0x20c
	// Line 2213, Address: 0x152bc0, Func Offset: 0x210
	// Line 2191, Address: 0x152bc4, Func Offset: 0x214
	// Line 2190, Address: 0x152bc8, Func Offset: 0x218
	// Line 2213, Address: 0x152bcc, Func Offset: 0x21c
	// Line 2191, Address: 0x152bd0, Func Offset: 0x220
	// Line 2192, Address: 0x152bd4, Func Offset: 0x224
	// Line 2193, Address: 0x152bd8, Func Offset: 0x228
	// Line 2195, Address: 0x152bdc, Func Offset: 0x22c
	// Line 2194, Address: 0x152be0, Func Offset: 0x230
	// Line 2195, Address: 0x152be4, Func Offset: 0x234
	// Line 2196, Address: 0x152be8, Func Offset: 0x238
	// Line 2197, Address: 0x152bec, Func Offset: 0x23c
	// Line 2198, Address: 0x152bf0, Func Offset: 0x240
	// Line 2199, Address: 0x152bf4, Func Offset: 0x244
	// Line 2200, Address: 0x152bf8, Func Offset: 0x248
	// Line 2201, Address: 0x152bfc, Func Offset: 0x24c
	// Line 2202, Address: 0x152c00, Func Offset: 0x250
	// Line 2203, Address: 0x152c04, Func Offset: 0x254
	// Line 2204, Address: 0x152c08, Func Offset: 0x258
	// Line 2205, Address: 0x152c0c, Func Offset: 0x25c
	// Line 2206, Address: 0x152c10, Func Offset: 0x260
	// Line 2207, Address: 0x152c14, Func Offset: 0x264
	// Line 2208, Address: 0x152c18, Func Offset: 0x268
	// Line 2209, Address: 0x152c1c, Func Offset: 0x26c
	// Line 2210, Address: 0x152c20, Func Offset: 0x270
	// Line 2211, Address: 0x152c24, Func Offset: 0x274
	// Line 2213, Address: 0x152c28, Func Offset: 0x278
	// Line 2217, Address: 0x152c40, Func Offset: 0x290
	// Line 2218, Address: 0x152c58, Func Offset: 0x2a8
	// Line 2219, Address: 0x152c5c, Func Offset: 0x2ac
	// Line 2220, Address: 0x152c60, Func Offset: 0x2b0
	// Line 2222, Address: 0x152c64, Func Offset: 0x2b4
	// Line 2221, Address: 0x152c68, Func Offset: 0x2b8
	// Line 2225, Address: 0x152c6c, Func Offset: 0x2bc
	// Line 2222, Address: 0x152c70, Func Offset: 0x2c0
	// Line 2223, Address: 0x152c74, Func Offset: 0x2c4
	// Line 2225, Address: 0x152c78, Func Offset: 0x2c8
	// Line 2229, Address: 0x152c94, Func Offset: 0x2e4
	// Line 2232, Address: 0x152ca8, Func Offset: 0x2f8
	// Line 2231, Address: 0x152cbc, Func Offset: 0x30c
	// Line 2232, Address: 0x152cc0, Func Offset: 0x310
	// Line 2235, Address: 0x152cc4, Func Offset: 0x314
	// Line 2237, Address: 0x152cc8, Func Offset: 0x318
	// Line 2232, Address: 0x152ccc, Func Offset: 0x31c
	// Line 2233, Address: 0x152cd0, Func Offset: 0x320
	// Line 2235, Address: 0x152cd8, Func Offset: 0x328
	// Line 2234, Address: 0x152cdc, Func Offset: 0x32c
	// Line 2235, Address: 0x152ce0, Func Offset: 0x330
	// Line 2236, Address: 0x152ce4, Func Offset: 0x334
	// Line 2237, Address: 0x152ce8, Func Offset: 0x338
	// Line 2238, Address: 0x152d10, Func Offset: 0x360
	// Line 2239, Address: 0x152d18, Func Offset: 0x368
	// Line 2240, Address: 0x152d1c, Func Offset: 0x36c
	// Line 2241, Address: 0x152d20, Func Offset: 0x370
	// Line 2238, Address: 0x152d28, Func Offset: 0x378
	// Line 2239, Address: 0x152d30, Func Offset: 0x380
	// Line 2240, Address: 0x152d3c, Func Offset: 0x38c
	// Line 2241, Address: 0x152d44, Func Offset: 0x394
	// Line 2242, Address: 0x152d64, Func Offset: 0x3b4
	// Line 2243, Address: 0x152d6c, Func Offset: 0x3bc
	// Line 2242, Address: 0x152d74, Func Offset: 0x3c4
	// Line 2243, Address: 0x152d78, Func Offset: 0x3c8
	// Line 2244, Address: 0x152d9c, Func Offset: 0x3ec
	// Line 2250, Address: 0x152da4, Func Offset: 0x3f4
	// Line 2249, Address: 0x152da8, Func Offset: 0x3f8
	// Line 2250, Address: 0x152dac, Func Offset: 0x3fc
	// Line 2251, Address: 0x152db0, Func Offset: 0x400
	// Line 2253, Address: 0x152db8, Func Offset: 0x408
	// Line 2252, Address: 0x152dbc, Func Offset: 0x40c
	// Line 2253, Address: 0x152dc0, Func Offset: 0x410
	// Line 2254, Address: 0x152dc8, Func Offset: 0x418
	// Line 2255, Address: 0x152dcc, Func Offset: 0x41c
	// Line 2256, Address: 0x152df8, Func Offset: 0x448
	// Line 2257, Address: 0x152e00, Func Offset: 0x450
	// Line 2258, Address: 0x152e04, Func Offset: 0x454
	// Line 2259, Address: 0x152e08, Func Offset: 0x458
	// Line 2256, Address: 0x152e10, Func Offset: 0x460
	// Line 2257, Address: 0x152e18, Func Offset: 0x468
	// Line 2258, Address: 0x152e24, Func Offset: 0x474
	// Line 2259, Address: 0x152e2c, Func Offset: 0x47c
	// Line 2260, Address: 0x152e4c, Func Offset: 0x49c
	// Line 2261, Address: 0x152e54, Func Offset: 0x4a4
	// Line 2260, Address: 0x152e5c, Func Offset: 0x4ac
	// Line 2261, Address: 0x152e60, Func Offset: 0x4b0
	// Line 2262, Address: 0x152e84, Func Offset: 0x4d4
	// Line 2268, Address: 0x152e8c, Func Offset: 0x4dc
	// Line 2270, Address: 0x152e90, Func Offset: 0x4e0
	// Line 2267, Address: 0x152e94, Func Offset: 0x4e4
	// Line 2268, Address: 0x152e98, Func Offset: 0x4e8
	// Line 2269, Address: 0x152e9c, Func Offset: 0x4ec
	// Line 2272, Address: 0x152ea0, Func Offset: 0x4f0
	// Line 2269, Address: 0x152ea4, Func Offset: 0x4f4
	// Line 2270, Address: 0x152ea8, Func Offset: 0x4f8
	// Line 2271, Address: 0x152eb0, Func Offset: 0x500
	// Line 2272, Address: 0x152eb8, Func Offset: 0x508
	// Line 2273, Address: 0x152ec0, Func Offset: 0x510
	// Line 2274, Address: 0x152ec8, Func Offset: 0x518
	// Line 2275, Address: 0x152ed0, Func Offset: 0x520
	// Line 2276, Address: 0x152ed4, Func Offset: 0x524
	// Line 2275, Address: 0x152ed8, Func Offset: 0x528
	// Line 2276, Address: 0x152edc, Func Offset: 0x52c
	// Line 2277, Address: 0x152ee4, Func Offset: 0x534
	// Line 2280, Address: 0x152eec, Func Offset: 0x53c
	// Line 2278, Address: 0x152ef0, Func Offset: 0x540
	// Line 2280, Address: 0x152ef8, Func Offset: 0x548
	// Line 2278, Address: 0x152efc, Func Offset: 0x54c
	// Line 2280, Address: 0x152f00, Func Offset: 0x550
	// Line 2277, Address: 0x152f04, Func Offset: 0x554
	// Line 2279, Address: 0x152f10, Func Offset: 0x560
	// Line 2278, Address: 0x152f14, Func Offset: 0x564
	// Line 2279, Address: 0x152f18, Func Offset: 0x568
	// Line 2280, Address: 0x152f20, Func Offset: 0x570
	// Line 2281, Address: 0x152f28, Func Offset: 0x578
	// Line 2282, Address: 0x152f30, Func Offset: 0x580
	// Line 2284, Address: 0x152f34, Func Offset: 0x584
	// Line 2281, Address: 0x152f3c, Func Offset: 0x58c
	// Line 2282, Address: 0x152f44, Func Offset: 0x594
	// Line 2283, Address: 0x152f58, Func Offset: 0x5a8
	// Line 2284, Address: 0x152f6c, Func Offset: 0x5bc
	// Line 2285, Address: 0x152f8c, Func Offset: 0x5dc
	// Line 2286, Address: 0x152f94, Func Offset: 0x5e4
	// Line 2285, Address: 0x152f9c, Func Offset: 0x5ec
	// Line 2286, Address: 0x152fa0, Func Offset: 0x5f0
	// Line 2287, Address: 0x152fc4, Func Offset: 0x614
	// Line 2291, Address: 0x152fcc, Func Offset: 0x61c
	// Line 2290, Address: 0x152fd0, Func Offset: 0x620
	// Line 2291, Address: 0x152fd4, Func Offset: 0x624
	// Line 2292, Address: 0x152fd8, Func Offset: 0x628
	// Line 2293, Address: 0x152fe0, Func Offset: 0x630
	// Line 2294, Address: 0x152fe8, Func Offset: 0x638
	// Line 2295, Address: 0x152ff0, Func Offset: 0x640
	// Line 2296, Address: 0x152ff8, Func Offset: 0x648
	// Line 2297, Address: 0x153000, Func Offset: 0x650
	// Line 2298, Address: 0x153008, Func Offset: 0x658
	// Line 2299, Address: 0x15300c, Func Offset: 0x65c
	// Line 2298, Address: 0x153010, Func Offset: 0x660
	// Line 2299, Address: 0x153014, Func Offset: 0x664
	// Line 2300, Address: 0x15301c, Func Offset: 0x66c
	// Line 2303, Address: 0x153028, Func Offset: 0x678
	// Line 2300, Address: 0x15302c, Func Offset: 0x67c
	// Line 2301, Address: 0x153030, Func Offset: 0x680
	// Line 2303, Address: 0x153034, Func Offset: 0x684
	// Line 2300, Address: 0x153038, Func Offset: 0x688
	// Line 2303, Address: 0x15303c, Func Offset: 0x68c
	// Line 2300, Address: 0x153040, Func Offset: 0x690
	// Line 2302, Address: 0x153044, Func Offset: 0x694
	// Line 2301, Address: 0x153048, Func Offset: 0x698
	// Line 2302, Address: 0x15304c, Func Offset: 0x69c
	// Line 2303, Address: 0x153054, Func Offset: 0x6a4
	// Line 2304, Address: 0x15305c, Func Offset: 0x6ac
	// Line 2305, Address: 0x153064, Func Offset: 0x6b4
	// Line 2307, Address: 0x153068, Func Offset: 0x6b8
	// Line 2304, Address: 0x153070, Func Offset: 0x6c0
	// Line 2305, Address: 0x153078, Func Offset: 0x6c8
	// Line 2306, Address: 0x15308c, Func Offset: 0x6dc
	// Line 2307, Address: 0x1530a0, Func Offset: 0x6f0
	// Line 2308, Address: 0x1530c0, Func Offset: 0x710
	// Line 2309, Address: 0x1530c8, Func Offset: 0x718
	// Line 2308, Address: 0x1530d0, Func Offset: 0x720
	// Line 2309, Address: 0x1530d4, Func Offset: 0x724
	// Line 2310, Address: 0x1530f8, Func Offset: 0x748
	// Line 2316, Address: 0x153100, Func Offset: 0x750
	// Line 2317, Address: 0x15310c, Func Offset: 0x75c
	// Line 2315, Address: 0x153110, Func Offset: 0x760
	// Line 2339, Address: 0x153114, Func Offset: 0x764
	// Line 2316, Address: 0x153118, Func Offset: 0x768
	// Line 2339, Address: 0x15311c, Func Offset: 0x76c
	// Line 2316, Address: 0x153120, Func Offset: 0x770
	// Line 2317, Address: 0x153124, Func Offset: 0x774
	// Line 2318, Address: 0x153128, Func Offset: 0x778
	// Line 2319, Address: 0x15312c, Func Offset: 0x77c
	// Line 2321, Address: 0x153130, Func Offset: 0x780
	// Line 2320, Address: 0x153134, Func Offset: 0x784
	// Line 2321, Address: 0x153138, Func Offset: 0x788
	// Line 2322, Address: 0x15313c, Func Offset: 0x78c
	// Line 2323, Address: 0x153140, Func Offset: 0x790
	// Line 2324, Address: 0x153144, Func Offset: 0x794
	// Line 2325, Address: 0x153148, Func Offset: 0x798
	// Line 2326, Address: 0x15314c, Func Offset: 0x79c
	// Line 2328, Address: 0x153150, Func Offset: 0x7a0
	// Line 2327, Address: 0x153154, Func Offset: 0x7a4
	// Line 2328, Address: 0x153158, Func Offset: 0x7a8
	// Line 2329, Address: 0x15315c, Func Offset: 0x7ac
	// Line 2330, Address: 0x153160, Func Offset: 0x7b0
	// Line 2331, Address: 0x153164, Func Offset: 0x7b4
	// Line 2332, Address: 0x153168, Func Offset: 0x7b8
	// Line 2333, Address: 0x15316c, Func Offset: 0x7bc
	// Line 2334, Address: 0x153170, Func Offset: 0x7c0
	// Line 2335, Address: 0x153174, Func Offset: 0x7c4
	// Line 2336, Address: 0x153178, Func Offset: 0x7c8
	// Line 2337, Address: 0x15317c, Func Offset: 0x7cc
	// Line 2339, Address: 0x153180, Func Offset: 0x7d0
	// Line 2342, Address: 0x153198, Func Offset: 0x7e8
	// Line 2343, Address: 0x1531b0, Func Offset: 0x800
	// Line 2344, Address: 0x1531b4, Func Offset: 0x804
	// Func End, Address: 0x153210, Func Offset: 0x860
}

// 
// Start address: 0x153210
int bhCheckClipModel(BH_PWORK* pp)
{
	int jno;
	int i;
	_anon23 p3;
	_anon35 p2;
	_anon15* mlwP;
	// Line 2439, Address: 0x153210, Func Offset: 0
	// Line 2440, Address: 0x153228, Func Offset: 0x18
	// Line 2444, Address: 0x15322c, Func Offset: 0x1c
	// Line 2445, Address: 0x15323c, Func Offset: 0x2c
	// Line 2446, Address: 0x153240, Func Offset: 0x30
	// Line 2447, Address: 0x153254, Func Offset: 0x44
	// Line 2449, Address: 0x15327c, Func Offset: 0x6c
	// Line 2451, Address: 0x153298, Func Offset: 0x88
	// Line 2453, Address: 0x153324, Func Offset: 0x114
	// Line 2454, Address: 0x15332c, Func Offset: 0x11c
	// Line 2455, Address: 0x153340, Func Offset: 0x130
	// Line 2456, Address: 0x153344, Func Offset: 0x134
	// Func End, Address: 0x153360, Func Offset: 0x150
}

// 
// Start address: 0x153360
int bhCheckClipPoint(_anon23* pos)
{
	_anon23 p3;
	_anon35 p2;
	// Line 2466, Address: 0x153360, Func Offset: 0
	// Line 2469, Address: 0x153370, Func Offset: 0x10
	// Line 2470, Address: 0x153384, Func Offset: 0x24
	// Line 2471, Address: 0x153398, Func Offset: 0x38
	// Line 2473, Address: 0x153424, Func Offset: 0xc4
	// Line 2474, Address: 0x15342c, Func Offset: 0xcc
	// Line 2475, Address: 0x153430, Func Offset: 0xd0
	// Func End, Address: 0x153440, Func Offset: 0xe0
}

// 
// Start address: 0x153440
void bhSetWaterSplash(BH_PWORK* pp, int jno, int type, float sx, float sy, float sz)
{
	_anon23 ps;
	_anon0* hp;
	_anon31* owp;
	// Line 2486, Address: 0x153440, Func Offset: 0
	// Line 2487, Address: 0x153468, Func Offset: 0x28
	// Line 2490, Address: 0x15346c, Func Offset: 0x2c
	// Line 2491, Address: 0x15347c, Func Offset: 0x3c
	// Line 2487, Address: 0x153480, Func Offset: 0x40
	// Line 2490, Address: 0x153494, Func Offset: 0x54
	// Line 2492, Address: 0x1534a0, Func Offset: 0x60
	// Line 2490, Address: 0x1534a4, Func Offset: 0x64
	// Line 2491, Address: 0x1534a8, Func Offset: 0x68
	// Line 2492, Address: 0x1534b0, Func Offset: 0x70
	// Line 2493, Address: 0x1534b4, Func Offset: 0x74
	// Line 2494, Address: 0x1534c0, Func Offset: 0x80
	// Line 2495, Address: 0x1534cc, Func Offset: 0x8c
	// Line 2496, Address: 0x1534d4, Func Offset: 0x94
	// Line 2497, Address: 0x1534e0, Func Offset: 0xa0
	// Line 2508, Address: 0x1534e4, Func Offset: 0xa4
	// Line 2496, Address: 0x1534e8, Func Offset: 0xa8
	// Line 2497, Address: 0x1534f4, Func Offset: 0xb4
	// Line 2508, Address: 0x1534fc, Func Offset: 0xbc
	// Line 2497, Address: 0x153504, Func Offset: 0xc4
	// Line 2498, Address: 0x153510, Func Offset: 0xd0
	// Line 2499, Address: 0x153524, Func Offset: 0xe4
	// Line 2500, Address: 0x153538, Func Offset: 0xf8
	// Line 2501, Address: 0x15354c, Func Offset: 0x10c
	// Line 2502, Address: 0x153560, Func Offset: 0x120
	// Line 2503, Address: 0x153574, Func Offset: 0x134
	// Line 2504, Address: 0x153588, Func Offset: 0x148
	// Line 2505, Address: 0x1535a0, Func Offset: 0x160
	// Line 2506, Address: 0x1535c0, Func Offset: 0x180
	// Line 2507, Address: 0x1535d8, Func Offset: 0x198
	// Line 2508, Address: 0x1535f4, Func Offset: 0x1b4
	// Line 2509, Address: 0x15360c, Func Offset: 0x1cc
	// Line 2510, Address: 0x153618, Func Offset: 0x1d8
	// Line 2509, Address: 0x153624, Func Offset: 0x1e4
	// Line 2510, Address: 0x153634, Func Offset: 0x1f4
	// Line 2511, Address: 0x15364c, Func Offset: 0x20c
	// Line 2512, Address: 0x153658, Func Offset: 0x218
	// Line 2511, Address: 0x153660, Func Offset: 0x220
	// Line 2512, Address: 0x153674, Func Offset: 0x234
	// Line 2514, Address: 0x153690, Func Offset: 0x250
	// Func End, Address: 0x1536bc, Func Offset: 0x27c
}

// 
// Start address: 0x1536c0
void bhSetWaterSplash2(BH_PWORK* pp, _anon23* pos, int type, float sx, float sy, float sz)
{
	_anon23 ps;
	_anon0* hp;
	// Line 2525, Address: 0x1536c0, Func Offset: 0
	// Line 2528, Address: 0x1536e4, Func Offset: 0x24
	// Line 2529, Address: 0x1536e8, Func Offset: 0x28
	// Line 2528, Address: 0x1536fc, Func Offset: 0x3c
	// Line 2529, Address: 0x153700, Func Offset: 0x40
	// Line 2530, Address: 0x153710, Func Offset: 0x50
	// Line 2531, Address: 0x153714, Func Offset: 0x54
	// Line 2532, Address: 0x153720, Func Offset: 0x60
	// Line 2533, Address: 0x15372c, Func Offset: 0x6c
	// Line 2534, Address: 0x153734, Func Offset: 0x74
	// Line 2535, Address: 0x153740, Func Offset: 0x80
	// Line 2546, Address: 0x153744, Func Offset: 0x84
	// Line 2534, Address: 0x153748, Func Offset: 0x88
	// Line 2535, Address: 0x153754, Func Offset: 0x94
	// Line 2546, Address: 0x15375c, Func Offset: 0x9c
	// Line 2535, Address: 0x153764, Func Offset: 0xa4
	// Line 2536, Address: 0x153770, Func Offset: 0xb0
	// Line 2537, Address: 0x153784, Func Offset: 0xc4
	// Line 2538, Address: 0x153798, Func Offset: 0xd8
	// Line 2539, Address: 0x1537ac, Func Offset: 0xec
	// Line 2540, Address: 0x1537c0, Func Offset: 0x100
	// Line 2541, Address: 0x1537d4, Func Offset: 0x114
	// Line 2542, Address: 0x1537e8, Func Offset: 0x128
	// Line 2543, Address: 0x153800, Func Offset: 0x140
	// Line 2544, Address: 0x153820, Func Offset: 0x160
	// Line 2545, Address: 0x153838, Func Offset: 0x178
	// Line 2546, Address: 0x153854, Func Offset: 0x194
	// Line 2547, Address: 0x15386c, Func Offset: 0x1ac
	// Line 2548, Address: 0x153878, Func Offset: 0x1b8
	// Line 2547, Address: 0x153884, Func Offset: 0x1c4
	// Line 2548, Address: 0x153894, Func Offset: 0x1d4
	// Line 2549, Address: 0x1538ac, Func Offset: 0x1ec
	// Line 2550, Address: 0x1538b8, Func Offset: 0x1f8
	// Line 2549, Address: 0x1538c0, Func Offset: 0x200
	// Line 2550, Address: 0x1538d4, Func Offset: 0x214
	// Line 2552, Address: 0x1538f0, Func Offset: 0x230
	// Func End, Address: 0x153918, Func Offset: 0x258
}

// 
// Start address: 0x153920
void bhSetWaterSplash3(_anon23* pos, int ang, int type, float sx, float sy, float sz)
{
	// Line 2563, Address: 0x153920, Func Offset: 0
	// Line 2564, Address: 0x15392c, Func Offset: 0xc
	// Line 2565, Address: 0x15393c, Func Offset: 0x1c
	// Line 2564, Address: 0x153940, Func Offset: 0x20
	// Line 2565, Address: 0x15394c, Func Offset: 0x2c
	// Line 2575, Address: 0x153954, Func Offset: 0x34
	// Line 2576, Address: 0x153958, Func Offset: 0x38
	// Line 2565, Address: 0x153960, Func Offset: 0x40
	// Line 2566, Address: 0x15396c, Func Offset: 0x4c
	// Line 2567, Address: 0x153980, Func Offset: 0x60
	// Line 2568, Address: 0x153994, Func Offset: 0x74
	// Line 2576, Address: 0x15399c, Func Offset: 0x7c
	// Line 2568, Address: 0x1539a0, Func Offset: 0x80
	// Line 2569, Address: 0x1539ac, Func Offset: 0x8c
	// Line 2570, Address: 0x1539c0, Func Offset: 0xa0
	// Line 2571, Address: 0x1539d4, Func Offset: 0xb4
	// Line 2572, Address: 0x1539e8, Func Offset: 0xc8
	// Line 2573, Address: 0x153a00, Func Offset: 0xe0
	// Line 2574, Address: 0x153a18, Func Offset: 0xf8
	// Line 2575, Address: 0x153a30, Func Offset: 0x110
	// Line 2576, Address: 0x153a44, Func Offset: 0x124
	// Line 2577, Address: 0x153a5c, Func Offset: 0x13c
	// Line 2578, Address: 0x153a68, Func Offset: 0x148
	// Line 2577, Address: 0x153a70, Func Offset: 0x150
	// Line 2578, Address: 0x153a7c, Func Offset: 0x15c
	// Line 2579, Address: 0x153a98, Func Offset: 0x178
	// Func End, Address: 0x153aa8, Func Offset: 0x188
}

// 
// Start address: 0x153ab0
void bhSetWaterSplash4(_anon23* pos, int ang, int type, float sx, float sy, float sz)
{
	// Line 2590, Address: 0x153ab0, Func Offset: 0
	// Line 2591, Address: 0x153abc, Func Offset: 0xc
	// Line 2594, Address: 0x153ac8, Func Offset: 0x18
	// Line 2591, Address: 0x153acc, Func Offset: 0x1c
	// Line 2592, Address: 0x153adc, Func Offset: 0x2c
	// Line 2602, Address: 0x153ae8, Func Offset: 0x38
	// Line 2603, Address: 0x153aec, Func Offset: 0x3c
	// Line 2592, Address: 0x153af0, Func Offset: 0x40
	// Line 2593, Address: 0x153afc, Func Offset: 0x4c
	// Line 2603, Address: 0x153b04, Func Offset: 0x54
	// Line 2593, Address: 0x153b0c, Func Offset: 0x5c
	// Line 2594, Address: 0x153b18, Func Offset: 0x68
	// Line 2595, Address: 0x153b2c, Func Offset: 0x7c
	// Line 2596, Address: 0x153b40, Func Offset: 0x90
	// Line 2597, Address: 0x153b54, Func Offset: 0xa4
	// Line 2598, Address: 0x153b68, Func Offset: 0xb8
	// Line 2599, Address: 0x153b7c, Func Offset: 0xcc
	// Line 2600, Address: 0x153b94, Func Offset: 0xe4
	// Line 2601, Address: 0x153bac, Func Offset: 0xfc
	// Line 2602, Address: 0x153bc4, Func Offset: 0x114
	// Line 2603, Address: 0x153bd8, Func Offset: 0x128
	// Line 2604, Address: 0x153bf0, Func Offset: 0x140
	// Line 2605, Address: 0x153bfc, Func Offset: 0x14c
	// Line 2604, Address: 0x153c04, Func Offset: 0x154
	// Line 2605, Address: 0x153c10, Func Offset: 0x160
	// Line 2606, Address: 0x153c2c, Func Offset: 0x17c
	// Func End, Address: 0x153c3c, Func Offset: 0x18c
}

// 
// Start address: 0x153c40
void bhSetGunFire(BH_PWORK* pp, int wno, int jno, int hand, int ang)
{
	float len;
	int walhit;
	_anon0* wlp;
	_anon23 wps;
	_anon41 gline;
	_anon1* op;
	_anon18* lp;
	int i;
	_anon23 ps2;
	_anon23 ps;
	_anon23 ops;
	_anon13* eft;
	// Line 2618, Address: 0x153c40, Func Offset: 0
	// Line 2624, Address: 0x153c60, Func Offset: 0x20
	// Line 2618, Address: 0x153c6c, Func Offset: 0x2c
	// Line 2624, Address: 0x153c70, Func Offset: 0x30
	// Line 2618, Address: 0x153c88, Func Offset: 0x48
	// Line 2624, Address: 0x153c8c, Func Offset: 0x4c
	// Line 2618, Address: 0x153c90, Func Offset: 0x50
	// Line 2624, Address: 0x153ca4, Func Offset: 0x64
	// Line 2626, Address: 0x153cb4, Func Offset: 0x74
	// Line 2627, Address: 0x153cbc, Func Offset: 0x7c
	// Line 2629, Address: 0x153cc0, Func Offset: 0x80
	// Line 2626, Address: 0x153cc4, Func Offset: 0x84
	// Line 2627, Address: 0x153cc8, Func Offset: 0x88
	// Line 2628, Address: 0x153ccc, Func Offset: 0x8c
	// Line 2629, Address: 0x153cd0, Func Offset: 0x90
	// Line 2630, Address: 0x153ce0, Func Offset: 0xa0
	// Line 2631, Address: 0x153ce8, Func Offset: 0xa8
	// Line 2633, Address: 0x153cec, Func Offset: 0xac
	// Line 2634, Address: 0x153cf4, Func Offset: 0xb4
	// Line 2635, Address: 0x153cfc, Func Offset: 0xbc
	// Line 2636, Address: 0x153d04, Func Offset: 0xc4
	// Line 2639, Address: 0x153d08, Func Offset: 0xc8
	// Line 2638, Address: 0x153d0c, Func Offset: 0xcc
	// Line 2639, Address: 0x153d10, Func Offset: 0xd0
	// Line 2640, Address: 0x153d14, Func Offset: 0xd4
	// Line 2641, Address: 0x153d24, Func Offset: 0xe4
	// Line 2640, Address: 0x153d30, Func Offset: 0xf0
	// Line 2641, Address: 0x153d34, Func Offset: 0xf4
	// Line 2642, Address: 0x153d78, Func Offset: 0x138
	// Line 2641, Address: 0x153d84, Func Offset: 0x144
	// Line 2642, Address: 0x153d88, Func Offset: 0x148
	// Line 2643, Address: 0x153dcc, Func Offset: 0x18c
	// Line 2642, Address: 0x153dd8, Func Offset: 0x198
	// Line 2643, Address: 0x153ddc, Func Offset: 0x19c
	// Line 2644, Address: 0x153e20, Func Offset: 0x1e0
	// Line 2643, Address: 0x153e2c, Func Offset: 0x1ec
	// Line 2644, Address: 0x153e30, Func Offset: 0x1f0
	// Line 2645, Address: 0x153e64, Func Offset: 0x224
	// Line 2644, Address: 0x153e70, Func Offset: 0x230
	// Line 2645, Address: 0x153e74, Func Offset: 0x234
	// Line 2646, Address: 0x153ea8, Func Offset: 0x268
	// Line 2647, Address: 0x153ec8, Func Offset: 0x288
	// Line 2648, Address: 0x153ee0, Func Offset: 0x2a0
	// Line 2649, Address: 0x153ef0, Func Offset: 0x2b0
	// Line 2648, Address: 0x153efc, Func Offset: 0x2bc
	// Line 2649, Address: 0x153f00, Func Offset: 0x2c0
	// Line 2650, Address: 0x153f08, Func Offset: 0x2c8
	// Line 2653, Address: 0x153f0c, Func Offset: 0x2cc
	// Line 2662, Address: 0x153f38, Func Offset: 0x2f8
	// Line 2670, Address: 0x153f40, Func Offset: 0x300
	// Line 2671, Address: 0x153f64, Func Offset: 0x324
	// Line 2672, Address: 0x153f6c, Func Offset: 0x32c
	// Line 2673, Address: 0x153f90, Func Offset: 0x350
	// Line 2674, Address: 0x153f98, Func Offset: 0x358
	// Line 2675, Address: 0x153fa4, Func Offset: 0x364
	// Line 2676, Address: 0x153fb0, Func Offset: 0x370
	// Line 2677, Address: 0x153fbc, Func Offset: 0x37c
	// Line 2678, Address: 0x153fc4, Func Offset: 0x384
	// Line 2679, Address: 0x153fcc, Func Offset: 0x38c
	// Line 2680, Address: 0x153fdc, Func Offset: 0x39c
	// Line 2679, Address: 0x153fe4, Func Offset: 0x3a4
	// Line 2680, Address: 0x153fe8, Func Offset: 0x3a8
	// Line 2679, Address: 0x153fec, Func Offset: 0x3ac
	// Line 2680, Address: 0x153ff0, Func Offset: 0x3b0
	// Line 2681, Address: 0x153ff4, Func Offset: 0x3b4
	// Line 2680, Address: 0x154000, Func Offset: 0x3c0
	// Line 2681, Address: 0x154004, Func Offset: 0x3c4
	// Line 2685, Address: 0x15400c, Func Offset: 0x3cc
	// Line 2686, Address: 0x154034, Func Offset: 0x3f4
	// Line 2689, Address: 0x15406c, Func Offset: 0x42c
	// Line 2691, Address: 0x154074, Func Offset: 0x434
	// Line 2692, Address: 0x1540a4, Func Offset: 0x464
	// Line 2693, Address: 0x1540ac, Func Offset: 0x46c
	// Line 2694, Address: 0x1540b0, Func Offset: 0x470
	// Line 2695, Address: 0x1540b8, Func Offset: 0x478
	// Line 2698, Address: 0x1540c0, Func Offset: 0x480
	// Line 2700, Address: 0x1540c8, Func Offset: 0x488
	// Line 2701, Address: 0x1540f8, Func Offset: 0x4b8
	// Line 2702, Address: 0x154100, Func Offset: 0x4c0
	// Line 2703, Address: 0x154104, Func Offset: 0x4c4
	// Line 2704, Address: 0x15410c, Func Offset: 0x4cc
	// Line 2707, Address: 0x154114, Func Offset: 0x4d4
	// Line 2716, Address: 0x15411c, Func Offset: 0x4dc
	// Line 2717, Address: 0x154124, Func Offset: 0x4e4
	// Line 2720, Address: 0x154128, Func Offset: 0x4e8
	// Line 2721, Address: 0x154138, Func Offset: 0x4f8
	// Line 2722, Address: 0x15413c, Func Offset: 0x4fc
	// Line 2721, Address: 0x15414c, Func Offset: 0x50c
	// Line 2722, Address: 0x154150, Func Offset: 0x510
	// Line 2724, Address: 0x154164, Func Offset: 0x524
	// Line 2725, Address: 0x154180, Func Offset: 0x540
	// Line 2724, Address: 0x154184, Func Offset: 0x544
	// Line 2725, Address: 0x154188, Func Offset: 0x548
	// Line 2736, Address: 0x15419c, Func Offset: 0x55c
	// Line 2737, Address: 0x1541b0, Func Offset: 0x570
	// Line 2738, Address: 0x1541d0, Func Offset: 0x590
	// Line 2740, Address: 0x15422c, Func Offset: 0x5ec
	// Line 2741, Address: 0x15423c, Func Offset: 0x5fc
	// Line 2742, Address: 0x154244, Func Offset: 0x604
	// Line 2743, Address: 0x154248, Func Offset: 0x608
	// Line 2744, Address: 0x15424c, Func Offset: 0x60c
	// Line 2746, Address: 0x154268, Func Offset: 0x628
	// Line 2748, Address: 0x154288, Func Offset: 0x648
	// Line 2750, Address: 0x154290, Func Offset: 0x650
	// Line 2751, Address: 0x15429c, Func Offset: 0x65c
	// Line 2757, Address: 0x1542a4, Func Offset: 0x664
	// Line 2758, Address: 0x1542b0, Func Offset: 0x670
	// Line 2760, Address: 0x1542b8, Func Offset: 0x678
	// Line 2761, Address: 0x1542c0, Func Offset: 0x680
	// Line 2762, Address: 0x1542d4, Func Offset: 0x694
	// Line 2763, Address: 0x1542dc, Func Offset: 0x69c
	// Line 2768, Address: 0x1542f0, Func Offset: 0x6b0
	// Line 2769, Address: 0x1542f8, Func Offset: 0x6b8
	// Line 2770, Address: 0x154308, Func Offset: 0x6c8
	// Line 2771, Address: 0x154310, Func Offset: 0x6d0
	// Line 2775, Address: 0x154324, Func Offset: 0x6e4
	// Line 2776, Address: 0x15433c, Func Offset: 0x6fc
	// Line 2777, Address: 0x154344, Func Offset: 0x704
	// Line 2778, Address: 0x154368, Func Offset: 0x728
	// Line 2779, Address: 0x154370, Func Offset: 0x730
	// Line 2780, Address: 0x15437c, Func Offset: 0x73c
	// Line 2781, Address: 0x154388, Func Offset: 0x748
	// Line 2782, Address: 0x154394, Func Offset: 0x754
	// Line 2783, Address: 0x15439c, Func Offset: 0x75c
	// Line 2784, Address: 0x1543a4, Func Offset: 0x764
	// Line 2785, Address: 0x1543b4, Func Offset: 0x774
	// Line 2784, Address: 0x1543bc, Func Offset: 0x77c
	// Line 2785, Address: 0x1543c0, Func Offset: 0x780
	// Line 2784, Address: 0x1543c4, Func Offset: 0x784
	// Line 2785, Address: 0x1543c8, Func Offset: 0x788
	// Line 2786, Address: 0x1543cc, Func Offset: 0x78c
	// Line 2785, Address: 0x1543d8, Func Offset: 0x798
	// Line 2786, Address: 0x1543dc, Func Offset: 0x79c
	// Line 2790, Address: 0x1543e4, Func Offset: 0x7a4
	// Line 2789, Address: 0x1543f4, Func Offset: 0x7b4
	// Line 2790, Address: 0x1543f8, Func Offset: 0x7b8
	// Line 2791, Address: 0x154410, Func Offset: 0x7d0
	// Line 2792, Address: 0x154420, Func Offset: 0x7e0
	// Line 2794, Address: 0x154424, Func Offset: 0x7e4
	// Line 2795, Address: 0x15442c, Func Offset: 0x7ec
	// Line 2797, Address: 0x154454, Func Offset: 0x814
	// Line 2798, Address: 0x15447c, Func Offset: 0x83c
	// Line 2799, Address: 0x154498, Func Offset: 0x858
	// Line 2800, Address: 0x15449c, Func Offset: 0x85c
	// Line 2801, Address: 0x1544b4, Func Offset: 0x874
	// Line 2803, Address: 0x1544bc, Func Offset: 0x87c
	// Line 2807, Address: 0x1544d4, Func Offset: 0x894
	// Line 2815, Address: 0x154500, Func Offset: 0x8c0
	// Line 2816, Address: 0x154508, Func Offset: 0x8c8
	// Line 2817, Address: 0x15452c, Func Offset: 0x8ec
	// Line 2818, Address: 0x154534, Func Offset: 0x8f4
	// Line 2819, Address: 0x154544, Func Offset: 0x904
	// Line 2818, Address: 0x15454c, Func Offset: 0x90c
	// Line 2819, Address: 0x154550, Func Offset: 0x910
	// Line 2818, Address: 0x154554, Func Offset: 0x914
	// Line 2819, Address: 0x154558, Func Offset: 0x918
	// Line 2820, Address: 0x15455c, Func Offset: 0x91c
	// Line 2819, Address: 0x154568, Func Offset: 0x928
	// Line 2820, Address: 0x15456c, Func Offset: 0x92c
	// Line 2823, Address: 0x154574, Func Offset: 0x934
	// Line 2824, Address: 0x154580, Func Offset: 0x940
	// Line 2826, Address: 0x154584, Func Offset: 0x944
	// Line 2823, Address: 0x154588, Func Offset: 0x948
	// Line 2824, Address: 0x154594, Func Offset: 0x954
	// Line 2836, Address: 0x15459c, Func Offset: 0x95c
	// Line 2824, Address: 0x1545a8, Func Offset: 0x968
	// Line 2825, Address: 0x1545b4, Func Offset: 0x974
	// Line 2826, Address: 0x1545c8, Func Offset: 0x988
	// Line 2827, Address: 0x1545dc, Func Offset: 0x99c
	// Line 2828, Address: 0x1545f0, Func Offset: 0x9b0
	// Line 2829, Address: 0x154604, Func Offset: 0x9c4
	// Line 2830, Address: 0x154618, Func Offset: 0x9d8
	// Line 2831, Address: 0x15462c, Func Offset: 0x9ec
	// Line 2832, Address: 0x154640, Func Offset: 0xa00
	// Line 2833, Address: 0x154654, Func Offset: 0xa14
	// Line 2834, Address: 0x15466c, Func Offset: 0xa2c
	// Line 2835, Address: 0x154684, Func Offset: 0xa44
	// Line 2836, Address: 0x15469c, Func Offset: 0xa5c
	// Line 2837, Address: 0x1546b4, Func Offset: 0xa74
	// Line 2841, Address: 0x1546bc, Func Offset: 0xa7c
	// Line 2842, Address: 0x1546c4, Func Offset: 0xa84
	// Line 2843, Address: 0x1546c8, Func Offset: 0xa88
	// Line 2848, Address: 0x1546cc, Func Offset: 0xa8c
	// Line 2841, Address: 0x1546d0, Func Offset: 0xa90
	// Line 2842, Address: 0x1546dc, Func Offset: 0xa9c
	// Line 2843, Address: 0x1546e0, Func Offset: 0xaa0
	// Line 2844, Address: 0x1546e4, Func Offset: 0xaa4
	// Line 2845, Address: 0x1546e8, Func Offset: 0xaa8
	// Line 2846, Address: 0x1546ec, Func Offset: 0xaac
	// Line 2848, Address: 0x1546f0, Func Offset: 0xab0
	// Line 2849, Address: 0x1546f4, Func Offset: 0xab4
	// Line 2846, Address: 0x154700, Func Offset: 0xac0
	// Line 2847, Address: 0x154704, Func Offset: 0xac4
	// Line 2848, Address: 0x154708, Func Offset: 0xac8
	// Line 2849, Address: 0x15470c, Func Offset: 0xacc
	// Line 2850, Address: 0x154710, Func Offset: 0xad0
	// Line 2849, Address: 0x15471c, Func Offset: 0xadc
	// Line 2850, Address: 0x154720, Func Offset: 0xae0
	// Line 2851, Address: 0x154724, Func Offset: 0xae4
	// Line 2850, Address: 0x15472c, Func Offset: 0xaec
	// Line 2851, Address: 0x154730, Func Offset: 0xaf0
	// Line 2850, Address: 0x154734, Func Offset: 0xaf4
	// Line 2852, Address: 0x154738, Func Offset: 0xaf8
	// Line 2851, Address: 0x154740, Func Offset: 0xb00
	// Line 2852, Address: 0x154748, Func Offset: 0xb08
	// Line 2851, Address: 0x154750, Func Offset: 0xb10
	// Line 2852, Address: 0x154754, Func Offset: 0xb14
	// Line 2854, Address: 0x15476c, Func Offset: 0xb2c
	// Line 2855, Address: 0x154774, Func Offset: 0xb34
	// Line 2856, Address: 0x154778, Func Offset: 0xb38
	// Line 2857, Address: 0x15477c, Func Offset: 0xb3c
	// Line 2859, Address: 0x154790, Func Offset: 0xb50
	// Line 2860, Address: 0x154798, Func Offset: 0xb58
	// Line 2861, Address: 0x15479c, Func Offset: 0xb5c
	// Line 2862, Address: 0x1547a0, Func Offset: 0xb60
	// Line 2863, Address: 0x1547a8, Func Offset: 0xb68
	// Line 2866, Address: 0x1547b0, Func Offset: 0xb70
	// Line 2861, Address: 0x1547b4, Func Offset: 0xb74
	// Line 2862, Address: 0x1547b8, Func Offset: 0xb78
	// Line 2863, Address: 0x1547bc, Func Offset: 0xb7c
	// Line 2866, Address: 0x1547c0, Func Offset: 0xb80
	// Line 2863, Address: 0x1547c4, Func Offset: 0xb84
	// Line 2864, Address: 0x1547cc, Func Offset: 0xb8c
	// Line 2865, Address: 0x1547d4, Func Offset: 0xb94
	// Line 2866, Address: 0x1547dc, Func Offset: 0xb9c
	// Line 2868, Address: 0x1547f0, Func Offset: 0xbb0
	// Line 2869, Address: 0x1547f8, Func Offset: 0xbb8
	// Line 2870, Address: 0x1547fc, Func Offset: 0xbbc
	// Line 2871, Address: 0x154800, Func Offset: 0xbc0
	// Line 2873, Address: 0x154814, Func Offset: 0xbd4
	// Line 2874, Address: 0x15481c, Func Offset: 0xbdc
	// Line 2875, Address: 0x154824, Func Offset: 0xbe4
	// Line 2876, Address: 0x154828, Func Offset: 0xbe8
	// Line 2877, Address: 0x154830, Func Offset: 0xbf0
	// Line 2880, Address: 0x154838, Func Offset: 0xbf8
	// Line 2875, Address: 0x15483c, Func Offset: 0xbfc
	// Line 2876, Address: 0x154840, Func Offset: 0xc00
	// Line 2877, Address: 0x154844, Func Offset: 0xc04
	// Line 2880, Address: 0x154848, Func Offset: 0xc08
	// Line 2877, Address: 0x15484c, Func Offset: 0xc0c
	// Line 2878, Address: 0x154854, Func Offset: 0xc14
	// Line 2879, Address: 0x15485c, Func Offset: 0xc1c
	// Line 2880, Address: 0x154864, Func Offset: 0xc24
	// Line 2882, Address: 0x154878, Func Offset: 0xc38
	// Line 2883, Address: 0x154880, Func Offset: 0xc40
	// Line 2884, Address: 0x154884, Func Offset: 0xc44
	// Line 2885, Address: 0x154888, Func Offset: 0xc48
	// Line 2887, Address: 0x1548a4, Func Offset: 0xc64
	// Line 2890, Address: 0x1548ac, Func Offset: 0xc6c
	// Line 2893, Address: 0x1548b0, Func Offset: 0xc70
	// Line 2887, Address: 0x1548b8, Func Offset: 0xc78
	// Line 2893, Address: 0x1548bc, Func Offset: 0xc7c
	// Line 2887, Address: 0x1548c4, Func Offset: 0xc84
	// Line 2888, Address: 0x1548d4, Func Offset: 0xc94
	// Line 2889, Address: 0x1548f0, Func Offset: 0xcb0
	// Line 2890, Address: 0x15490c, Func Offset: 0xccc
	// Line 2891, Address: 0x154910, Func Offset: 0xcd0
	// Line 2893, Address: 0x154914, Func Offset: 0xcd4
	// Line 2894, Address: 0x15491c, Func Offset: 0xcdc
	// Line 2897, Address: 0x15492c, Func Offset: 0xcec
	// Line 2894, Address: 0x154930, Func Offset: 0xcf0
	// Line 2897, Address: 0x154934, Func Offset: 0xcf4
	// Line 2894, Address: 0x154938, Func Offset: 0xcf8
	// Line 2895, Address: 0x15493c, Func Offset: 0xcfc
	// Line 2896, Address: 0x154944, Func Offset: 0xd04
	// Line 2897, Address: 0x15494c, Func Offset: 0xd0c
	// Line 2899, Address: 0x154960, Func Offset: 0xd20
	// Line 2901, Address: 0x154974, Func Offset: 0xd34
	// Line 2902, Address: 0x15497c, Func Offset: 0xd3c
	// Line 2904, Address: 0x154984, Func Offset: 0xd44
	// Line 2903, Address: 0x154988, Func Offset: 0xd48
	// Line 2904, Address: 0x15498c, Func Offset: 0xd4c
	// Line 2905, Address: 0x154994, Func Offset: 0xd54
	// Line 2906, Address: 0x1549a8, Func Offset: 0xd68
	// Line 2907, Address: 0x1549b0, Func Offset: 0xd70
	// Line 2908, Address: 0x1549b8, Func Offset: 0xd78
	// Line 2909, Address: 0x1549bc, Func Offset: 0xd7c
	// Line 2910, Address: 0x1549c4, Func Offset: 0xd84
	// Line 2912, Address: 0x1549d0, Func Offset: 0xd90
	// Line 2911, Address: 0x1549d4, Func Offset: 0xd94
	// Line 2912, Address: 0x1549d8, Func Offset: 0xd98
	// Line 2914, Address: 0x1549e0, Func Offset: 0xda0
	// Line 2915, Address: 0x1549ec, Func Offset: 0xdac
	// Line 2917, Address: 0x1549f0, Func Offset: 0xdb0
	// Line 2916, Address: 0x1549f4, Func Offset: 0xdb4
	// Line 2917, Address: 0x1549f8, Func Offset: 0xdb8
	// Line 2919, Address: 0x154a08, Func Offset: 0xdc8
	// Line 2920, Address: 0x154a10, Func Offset: 0xdd0
	// Line 2922, Address: 0x154a18, Func Offset: 0xdd8
	// Line 2921, Address: 0x154a1c, Func Offset: 0xddc
	// Line 2922, Address: 0x154a20, Func Offset: 0xde0
	// Line 2923, Address: 0x154a24, Func Offset: 0xde4
	// Line 2925, Address: 0x154a28, Func Offset: 0xde8
	// Line 2924, Address: 0x154a2c, Func Offset: 0xdec
	// Line 2925, Address: 0x154a30, Func Offset: 0xdf0
	// Line 2926, Address: 0x154a38, Func Offset: 0xdf8
	// Line 2927, Address: 0x154a40, Func Offset: 0xe00
	// Line 2928, Address: 0x154a44, Func Offset: 0xe04
	// Line 2929, Address: 0x154a48, Func Offset: 0xe08
	// Line 2931, Address: 0x154a50, Func Offset: 0xe10
	// Line 2930, Address: 0x154a54, Func Offset: 0xe14
	// Line 2931, Address: 0x154a58, Func Offset: 0xe18
	// Line 2932, Address: 0x154a60, Func Offset: 0xe20
	// Line 2933, Address: 0x154a78, Func Offset: 0xe38
	// Line 2934, Address: 0x154a7c, Func Offset: 0xe3c
	// Line 2935, Address: 0x154a8c, Func Offset: 0xe4c
	// Line 2936, Address: 0x154aa0, Func Offset: 0xe60
	// Line 2937, Address: 0x154aac, Func Offset: 0xe6c
	// Line 2938, Address: 0x154abc, Func Offset: 0xe7c
	// Line 2947, Address: 0x154ac4, Func Offset: 0xe84
	// Line 2950, Address: 0x154b00, Func Offset: 0xec0
	// Line 2951, Address: 0x154b0c, Func Offset: 0xecc
	// Line 2955, Address: 0x154b10, Func Offset: 0xed0
	// Line 2950, Address: 0x154b14, Func Offset: 0xed4
	// Line 2951, Address: 0x154b20, Func Offset: 0xee0
	// Line 2960, Address: 0x154b28, Func Offset: 0xee8
	// Line 2963, Address: 0x154b2c, Func Offset: 0xeec
	// Line 2951, Address: 0x154b30, Func Offset: 0xef0
	// Line 2952, Address: 0x154b3c, Func Offset: 0xefc
	// Line 2953, Address: 0x154b50, Func Offset: 0xf10
	// Line 2954, Address: 0x154b64, Func Offset: 0xf24
	// Line 2955, Address: 0x154b78, Func Offset: 0xf38
	// Line 2956, Address: 0x154b8c, Func Offset: 0xf4c
	// Line 2957, Address: 0x154ba0, Func Offset: 0xf60
	// Line 2958, Address: 0x154bb4, Func Offset: 0xf74
	// Line 2959, Address: 0x154bc8, Func Offset: 0xf88
	// Line 2960, Address: 0x154bdc, Func Offset: 0xf9c
	// Line 2961, Address: 0x154be0, Func Offset: 0xfa0
	// Line 2962, Address: 0x154be4, Func Offset: 0xfa4
	// Line 2963, Address: 0x154be8, Func Offset: 0xfa8
	// Line 2964, Address: 0x154bfc, Func Offset: 0xfbc
	// Line 2965, Address: 0x154c0c, Func Offset: 0xfcc
	// Line 2986, Address: 0x154c30, Func Offset: 0xff0
	// Line 2997, Address: 0x154c38, Func Offset: 0xff8
	// Line 2998, Address: 0x154c54, Func Offset: 0x1014
	// Line 2997, Address: 0x154c60, Func Offset: 0x1020
	// Line 2998, Address: 0x154c68, Func Offset: 0x1028
	// Line 2997, Address: 0x154c6c, Func Offset: 0x102c
	// Line 2998, Address: 0x154c70, Func Offset: 0x1030
	// Line 2999, Address: 0x154c84, Func Offset: 0x1044
	// Line 3000, Address: 0x154c8c, Func Offset: 0x104c
	// Line 3002, Address: 0x154c94, Func Offset: 0x1054
	// Line 3003, Address: 0x154cac, Func Offset: 0x106c
	// Line 3004, Address: 0x154cb8, Func Offset: 0x1078
	// Line 3005, Address: 0x154cc4, Func Offset: 0x1084
	// Line 3006, Address: 0x154cd8, Func Offset: 0x1098
	// Line 3007, Address: 0x154cf0, Func Offset: 0x10b0
	// Line 3009, Address: 0x154cfc, Func Offset: 0x10bc
	// Line 3007, Address: 0x154d00, Func Offset: 0x10c0
	// Line 3008, Address: 0x154d18, Func Offset: 0x10d8
	// Line 3007, Address: 0x154d20, Func Offset: 0x10e0
	// Line 3008, Address: 0x154d2c, Func Offset: 0x10ec
	// Line 3010, Address: 0x154d30, Func Offset: 0x10f0
	// Line 3011, Address: 0x154d38, Func Offset: 0x10f8
	// Line 3013, Address: 0x154d3c, Func Offset: 0x10fc
	// Line 3014, Address: 0x154d44, Func Offset: 0x1104
	// Line 3015, Address: 0x154d54, Func Offset: 0x1114
	// Line 3016, Address: 0x154d58, Func Offset: 0x1118
	// Line 3017, Address: 0x154d5c, Func Offset: 0x111c
	// Line 3020, Address: 0x154d60, Func Offset: 0x1120
	// Line 3015, Address: 0x154d68, Func Offset: 0x1128
	// Line 3016, Address: 0x154d70, Func Offset: 0x1130
	// Line 3017, Address: 0x154d78, Func Offset: 0x1138
	// Line 3020, Address: 0x154d7c, Func Offset: 0x113c
	// Line 3017, Address: 0x154d80, Func Offset: 0x1140
	// Line 3020, Address: 0x154d84, Func Offset: 0x1144
	// Line 3021, Address: 0x154da8, Func Offset: 0x1168
	// Line 3022, Address: 0x154dbc, Func Offset: 0x117c
	// Line 3032, Address: 0x154dc4, Func Offset: 0x1184
	// Line 3022, Address: 0x154dcc, Func Offset: 0x118c
	// Line 3032, Address: 0x154ddc, Func Offset: 0x119c
	// Line 3023, Address: 0x154de0, Func Offset: 0x11a0
	// Line 3031, Address: 0x154de8, Func Offset: 0x11a8
	// Line 3035, Address: 0x154dec, Func Offset: 0x11ac
	// Line 3023, Address: 0x154df8, Func Offset: 0x11b8
	// Line 3024, Address: 0x154e04, Func Offset: 0x11c4
	// Line 3025, Address: 0x154e18, Func Offset: 0x11d8
	// Line 3026, Address: 0x154e2c, Func Offset: 0x11ec
	// Line 3027, Address: 0x154e40, Func Offset: 0x1200
	// Line 3028, Address: 0x154e58, Func Offset: 0x1218
	// Line 3029, Address: 0x154e70, Func Offset: 0x1230
	// Line 3030, Address: 0x154e88, Func Offset: 0x1248
	// Line 3031, Address: 0x154e9c, Func Offset: 0x125c
	// Line 3032, Address: 0x154eb0, Func Offset: 0x1270
	// Line 3033, Address: 0x154ec8, Func Offset: 0x1288
	// Line 3034, Address: 0x154ee0, Func Offset: 0x12a0
	// Line 3035, Address: 0x154ef8, Func Offset: 0x12b8
	// Line 3036, Address: 0x154f10, Func Offset: 0x12d0
	// Line 3039, Address: 0x154f24, Func Offset: 0x12e4
	// Line 3036, Address: 0x154f30, Func Offset: 0x12f0
	// Line 3037, Address: 0x154f40, Func Offset: 0x1300
	// Line 3038, Address: 0x154f5c, Func Offset: 0x131c
	// Line 3039, Address: 0x154f78, Func Offset: 0x1338
	// Line 3040, Address: 0x154f90, Func Offset: 0x1350
	// Line 3044, Address: 0x154f9c, Func Offset: 0x135c
	// Line 3040, Address: 0x154fa4, Func Offset: 0x1364
	// Line 3041, Address: 0x154fb0, Func Offset: 0x1370
	// Line 3044, Address: 0x154fbc, Func Offset: 0x137c
	// Line 3041, Address: 0x154fc0, Func Offset: 0x1380
	// Line 3042, Address: 0x154fcc, Func Offset: 0x138c
	// Line 3043, Address: 0x154fe4, Func Offset: 0x13a4
	// Line 3044, Address: 0x154ffc, Func Offset: 0x13bc
	// Line 3045, Address: 0x155014, Func Offset: 0x13d4
	// Line 3048, Address: 0x155028, Func Offset: 0x13e8
	// Line 3045, Address: 0x155030, Func Offset: 0x13f0
	// Line 3048, Address: 0x155034, Func Offset: 0x13f4
	// Line 3045, Address: 0x155038, Func Offset: 0x13f8
	// Line 3046, Address: 0x155044, Func Offset: 0x1404
	// Line 3047, Address: 0x155060, Func Offset: 0x1420
	// Line 3048, Address: 0x15507c, Func Offset: 0x143c
	// Line 3055, Address: 0x155094, Func Offset: 0x1454
	// Func End, Address: 0x1550c4, Func Offset: 0x1484
}

// 
// Start address: 0x1550d0
void bhSetYakkyou(BH_PWORK* pp, int wno, int jno, int hand)
{
	_anon23 jps;
	_anon23 wps;
	_anon23 ops;
	_anon13* eft;
	short hl;
	short hr;
	// Line 3067, Address: 0x1550d0, Func Offset: 0
	// Line 3071, Address: 0x1550f4, Func Offset: 0x24
	// Line 3067, Address: 0x1550fc, Func Offset: 0x2c
	// Line 3071, Address: 0x155108, Func Offset: 0x38
	// Line 3073, Address: 0x155110, Func Offset: 0x40
	// Line 3075, Address: 0x155118, Func Offset: 0x48
	// Line 3076, Address: 0x15512c, Func Offset: 0x5c
	// Line 3079, Address: 0x155148, Func Offset: 0x78
	// Line 3080, Address: 0x15515c, Func Offset: 0x8c
	// Line 3084, Address: 0x155170, Func Offset: 0xa0
	// Line 3085, Address: 0x155188, Func Offset: 0xb8
	// Line 3086, Address: 0x155194, Func Offset: 0xc4
	// Line 3084, Address: 0x15519c, Func Offset: 0xcc
	// Line 3086, Address: 0x1551a0, Func Offset: 0xd0
	// Line 3088, Address: 0x1551ac, Func Offset: 0xdc
	// Line 3089, Address: 0x1551b4, Func Offset: 0xe4
	// Line 3090, Address: 0x1551e4, Func Offset: 0x114
	// Line 3089, Address: 0x1551ec, Func Offset: 0x11c
	// Line 3090, Address: 0x1551f0, Func Offset: 0x120
	// Line 3089, Address: 0x1551f4, Func Offset: 0x124
	// Line 3090, Address: 0x1551fc, Func Offset: 0x12c
	// Line 3091, Address: 0x155214, Func Offset: 0x144
	// Line 3092, Address: 0x15521c, Func Offset: 0x14c
	// Line 3093, Address: 0x155228, Func Offset: 0x158
	// Line 3094, Address: 0x155234, Func Offset: 0x164
	// Line 3095, Address: 0x155240, Func Offset: 0x170
	// Line 3096, Address: 0x15524c, Func Offset: 0x17c
	// Line 3097, Address: 0x155258, Func Offset: 0x188
	// Line 3098, Address: 0x155264, Func Offset: 0x194
	// Line 3099, Address: 0x15526c, Func Offset: 0x19c
	// Line 3100, Address: 0x155274, Func Offset: 0x1a4
	// Line 3101, Address: 0x155298, Func Offset: 0x1c8
	// Line 3100, Address: 0x1552a0, Func Offset: 0x1d0
	// Line 3101, Address: 0x1552a4, Func Offset: 0x1d4
	// Line 3100, Address: 0x1552a8, Func Offset: 0x1d8
	// Line 3101, Address: 0x1552ac, Func Offset: 0x1dc
	// Line 3102, Address: 0x1552b0, Func Offset: 0x1e0
	// Line 3101, Address: 0x1552bc, Func Offset: 0x1ec
	// Line 3102, Address: 0x1552c0, Func Offset: 0x1f0
	// Line 3103, Address: 0x1552c4, Func Offset: 0x1f4
	// Line 3102, Address: 0x1552d0, Func Offset: 0x200
	// Line 3103, Address: 0x1552d4, Func Offset: 0x204
	// Line 3104, Address: 0x1552d8, Func Offset: 0x208
	// Line 3103, Address: 0x1552e0, Func Offset: 0x210
	// Line 3104, Address: 0x1552e4, Func Offset: 0x214
	// Line 3103, Address: 0x1552e8, Func Offset: 0x218
	// Line 3104, Address: 0x1552ec, Func Offset: 0x21c
	// Line 3105, Address: 0x1552f0, Func Offset: 0x220
	// Line 3104, Address: 0x1552fc, Func Offset: 0x22c
	// Line 3105, Address: 0x155300, Func Offset: 0x230
	// Line 3109, Address: 0x155308, Func Offset: 0x238
	// Line 3112, Address: 0x155330, Func Offset: 0x260
	// Line 3113, Address: 0x155338, Func Offset: 0x268
	// Line 3112, Address: 0x15533c, Func Offset: 0x26c
	// Line 3113, Address: 0x15534c, Func Offset: 0x27c
	// Line 3114, Address: 0x155364, Func Offset: 0x294
	// Line 3118, Address: 0x155384, Func Offset: 0x2b4
	// Line 3114, Address: 0x155388, Func Offset: 0x2b8
	// Line 3118, Address: 0x15538c, Func Offset: 0x2bc
	// Line 3120, Address: 0x1553a4, Func Offset: 0x2d4
	// Line 3123, Address: 0x1553c8, Func Offset: 0x2f8
	// Line 3124, Address: 0x1553e0, Func Offset: 0x310
	// Line 3125, Address: 0x1553e8, Func Offset: 0x318
	// Line 3126, Address: 0x155420, Func Offset: 0x350
	// Line 3127, Address: 0x155428, Func Offset: 0x358
	// Line 3128, Address: 0x15544c, Func Offset: 0x37c
	// Line 3127, Address: 0x155454, Func Offset: 0x384
	// Line 3128, Address: 0x155458, Func Offset: 0x388
	// Line 3127, Address: 0x15545c, Func Offset: 0x38c
	// Line 3128, Address: 0x155460, Func Offset: 0x390
	// Line 3129, Address: 0x155464, Func Offset: 0x394
	// Line 3128, Address: 0x155470, Func Offset: 0x3a0
	// Line 3129, Address: 0x155474, Func Offset: 0x3a4
	// Line 3132, Address: 0x15547c, Func Offset: 0x3ac
	// Line 3131, Address: 0x155484, Func Offset: 0x3b4
	// Line 3133, Address: 0x155488, Func Offset: 0x3b8
	// Line 3132, Address: 0x155490, Func Offset: 0x3c0
	// Line 3133, Address: 0x155498, Func Offset: 0x3c8
	// Line 3134, Address: 0x1554ac, Func Offset: 0x3dc
	// Line 3135, Address: 0x1554bc, Func Offset: 0x3ec
	// Line 3136, Address: 0x1554d0, Func Offset: 0x400
	// Line 3137, Address: 0x1554d8, Func Offset: 0x408
	// Line 3139, Address: 0x1554ec, Func Offset: 0x41c
	// Line 3141, Address: 0x155500, Func Offset: 0x430
	// Line 3145, Address: 0x155508, Func Offset: 0x438
	// Line 3141, Address: 0x155510, Func Offset: 0x440
	// Line 3149, Address: 0x155514, Func Offset: 0x444
	// Line 3144, Address: 0x155518, Func Offset: 0x448
	// Line 3141, Address: 0x15551c, Func Offset: 0x44c
	// Line 3142, Address: 0x155528, Func Offset: 0x458
	// Line 3149, Address: 0x155534, Func Offset: 0x464
	// Line 3146, Address: 0x155538, Func Offset: 0x468
	// Line 3154, Address: 0x15553c, Func Offset: 0x46c
	// Line 3142, Address: 0x155540, Func Offset: 0x470
	// Line 3143, Address: 0x15554c, Func Offset: 0x47c
	// Line 3154, Address: 0x155558, Func Offset: 0x488
	// Line 3143, Address: 0x155560, Func Offset: 0x490
	// Line 3144, Address: 0x15556c, Func Offset: 0x49c
	// Line 3145, Address: 0x155580, Func Offset: 0x4b0
	// Line 3146, Address: 0x155594, Func Offset: 0x4c4
	// Line 3147, Address: 0x1555a8, Func Offset: 0x4d8
	// Line 3148, Address: 0x1555bc, Func Offset: 0x4ec
	// Line 3149, Address: 0x1555d0, Func Offset: 0x500
	// Line 3150, Address: 0x1555e4, Func Offset: 0x514
	// Line 3151, Address: 0x1555f8, Func Offset: 0x528
	// Line 3152, Address: 0x15560c, Func Offset: 0x53c
	// Line 3153, Address: 0x155620, Func Offset: 0x550
	// Line 3154, Address: 0x155634, Func Offset: 0x564
	// Line 3158, Address: 0x15564c, Func Offset: 0x57c
	// Func End, Address: 0x155678, Func Offset: 0x5a8
}

// 
// Start address: 0x155680
void bhSetMagazine(BH_PWORK* pp, int wno, int jno, int hand, int ang)
{
	_anon23 ops;
	_anon13* eft;
	// Line 3170, Address: 0x155680, Func Offset: 0
	// Line 3173, Address: 0x155688, Func Offset: 0x8
	// Line 3178, Address: 0x155694, Func Offset: 0x14
	// Line 3175, Address: 0x155698, Func Offset: 0x18
	// Line 3173, Address: 0x1556a0, Func Offset: 0x20
	// Line 3174, Address: 0x1556ac, Func Offset: 0x2c
	// Line 3175, Address: 0x1556b4, Func Offset: 0x34
	// Line 3176, Address: 0x1556bc, Func Offset: 0x3c
	// Line 3177, Address: 0x1556c0, Func Offset: 0x40
	// Line 3180, Address: 0x1556c8, Func Offset: 0x48
	// Line 3183, Address: 0x1556cc, Func Offset: 0x4c
	// Line 3177, Address: 0x1556d0, Func Offset: 0x50
	// Line 3178, Address: 0x1556e0, Func Offset: 0x60
	// Line 3179, Address: 0x1556e4, Func Offset: 0x64
	// Line 3180, Address: 0x1556e8, Func Offset: 0x68
	// Line 3181, Address: 0x1556ec, Func Offset: 0x6c
	// Line 3183, Address: 0x1556f0, Func Offset: 0x70
	// Line 3185, Address: 0x15570c, Func Offset: 0x8c
	// Line 3186, Address: 0x155714, Func Offset: 0x94
	// Line 3187, Address: 0x155720, Func Offset: 0xa0
	// Line 3189, Address: 0x155724, Func Offset: 0xa4
	// Line 3191, Address: 0x15572c, Func Offset: 0xac
	// Line 3192, Address: 0x155734, Func Offset: 0xb4
	// Line 3193, Address: 0x155740, Func Offset: 0xc0
	// Line 3194, Address: 0x155744, Func Offset: 0xc4
	// Line 3195, Address: 0x155748, Func Offset: 0xc8
	// Line 3197, Address: 0x155750, Func Offset: 0xd0
	// Line 3198, Address: 0x155754, Func Offset: 0xd4
	// Line 3199, Address: 0x15575c, Func Offset: 0xdc
	// Line 3200, Address: 0x155764, Func Offset: 0xe4
	// Line 3202, Address: 0x155768, Func Offset: 0xe8
	// Line 3203, Address: 0x155770, Func Offset: 0xf0
	// Line 3204, Address: 0x155778, Func Offset: 0xf8
	// Line 3205, Address: 0x15577c, Func Offset: 0xfc
	// Line 3212, Address: 0x155780, Func Offset: 0x100
	// Line 3214, Address: 0x155794, Func Offset: 0x114
	// Line 3216, Address: 0x1557b8, Func Offset: 0x138
	// Func End, Address: 0x1557c4, Func Offset: 0x144
}

// 
// Start address: 0x1557d0
void bhSetLighterFire(_anon1* op, int flg)
{
	// Line 3226, Address: 0x1557d0, Func Offset: 0
	// Line 3228, Address: 0x1557dc, Func Offset: 0xc
	// Line 3229, Address: 0x1557e4, Func Offset: 0x14
	// Line 3230, Address: 0x1557ec, Func Offset: 0x1c
	// Line 3229, Address: 0x1557f4, Func Offset: 0x24
	// Line 3240, Address: 0x1557f8, Func Offset: 0x28
	// Line 3229, Address: 0x1557fc, Func Offset: 0x2c
	// Line 3230, Address: 0x155808, Func Offset: 0x38
	// Line 3240, Address: 0x155810, Func Offset: 0x40
	// Line 3231, Address: 0x155814, Func Offset: 0x44
	// Line 3235, Address: 0x155818, Func Offset: 0x48
	// Line 3230, Address: 0x15581c, Func Offset: 0x4c
	// Line 3231, Address: 0x155828, Func Offset: 0x58
	// Line 3240, Address: 0x155830, Func Offset: 0x60
	// Line 3231, Address: 0x155838, Func Offset: 0x68
	// Line 3232, Address: 0x155844, Func Offset: 0x74
	// Line 3233, Address: 0x15585c, Func Offset: 0x8c
	// Line 3234, Address: 0x155874, Func Offset: 0xa4
	// Line 3235, Address: 0x15588c, Func Offset: 0xbc
	// Line 3236, Address: 0x1558a0, Func Offset: 0xd0
	// Line 3237, Address: 0x1558b4, Func Offset: 0xe4
	// Line 3238, Address: 0x1558c8, Func Offset: 0xf8
	// Line 3239, Address: 0x1558dc, Func Offset: 0x10c
	// Line 3240, Address: 0x1558f0, Func Offset: 0x120
	// Line 3244, Address: 0x155908, Func Offset: 0x138
	// Line 3245, Address: 0x155914, Func Offset: 0x144
	// Line 3247, Address: 0x155918, Func Offset: 0x148
	// Line 3245, Address: 0x15591c, Func Offset: 0x14c
	// Line 3247, Address: 0x155920, Func Offset: 0x150
	// Line 3245, Address: 0x155928, Func Offset: 0x158
	// Line 3246, Address: 0x15592c, Func Offset: 0x15c
	// Line 3247, Address: 0x155930, Func Offset: 0x160
	// Line 3249, Address: 0x155938, Func Offset: 0x168
	// Line 3250, Address: 0x155940, Func Offset: 0x170
	// Line 3249, Address: 0x155944, Func Offset: 0x174
	// Line 3250, Address: 0x155948, Func Offset: 0x178
	// Line 3249, Address: 0x15594c, Func Offset: 0x17c
	// Line 3250, Address: 0x155958, Func Offset: 0x188
	// Line 3251, Address: 0x155964, Func Offset: 0x194
	// Line 3254, Address: 0x15596c, Func Offset: 0x19c
	// Line 3255, Address: 0x155974, Func Offset: 0x1a4
	// Line 3254, Address: 0x155978, Func Offset: 0x1a8
	// Line 3255, Address: 0x15597c, Func Offset: 0x1ac
	// Line 3254, Address: 0x155980, Func Offset: 0x1b0
	// Line 3255, Address: 0x155984, Func Offset: 0x1b4
	// Line 3254, Address: 0x155988, Func Offset: 0x1b8
	// Line 3255, Address: 0x155994, Func Offset: 0x1c4
	// Line 3257, Address: 0x1559a4, Func Offset: 0x1d4
	// Func End, Address: 0x1559b4, Func Offset: 0x1e4
}

