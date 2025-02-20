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
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct _anon23;
typedef struct _anon24;
typedef struct BH_PWORK;
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

typedef void(*type_83)(void*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef _anon0* type_2[32];
typedef _anon3* type_3[16];
typedef _anon0* type_4[512];
typedef _anon3* type_5[16][16];
typedef _anon3* type_6[16][16][100];
typedef char type_7[8];
typedef _anon0* type_8[32];
typedef _anon0* type_9[512];
typedef _anon3* type_10[1300];
typedef unsigned int type_11[64];
typedef _anon0* type_12[32];
typedef float type_13[32];
typedef _anon0* type_14[512];
typedef _anon3* type_15[200];
typedef char type_16[32];
typedef _anon0* type_17[128];
typedef unsigned int type_18[1];
typedef short type_19[32];
typedef _anon20 type_20[1];
typedef _anon3* type_21[8];
typedef int* type_22[16];
typedef _anon0* type_23[128];
typedef _anon44 type_24[16];
typedef npobj* type_25[16];
typedef _anon0* type_26[128];
typedef _anon9 type_27[256];
typedef _anon3* type_28[16];
typedef BH_PWORK type_29[0];
typedef float type_30[4];
typedef _anon14 type_31[16];
typedef _anon0* type_32[512];
typedef _anon23 type_33[256];
typedef float type_34[4];
typedef int type_35[4];
typedef void* type_36[256];
typedef unsigned int type_37[4];
typedef unsigned int type_38[0];
typedef float type_39[4];
typedef char type_40[256];
typedef _anon23 type_41[0];
typedef _anon7* type_42[128];
typedef float type_43[4];
typedef float type_44[4];
typedef unsigned char type_45[64];
typedef float type_46[4];
typedef float type_47[16];
typedef char type_48[8];
typedef char type_49[128];
typedef void* type_50[2];
typedef _anon3* type_51[256];
typedef unsigned char* type_52[256];
typedef short type_53[256];
typedef char type_54[0];
typedef unsigned int type_55[2];
typedef int type_56[4];
typedef short type_57[256];
typedef int type_58[8];
typedef _anon32 type_59[4];
typedef float type_60[3];
typedef _anon3* type_61[256];
typedef _anon12 type_62[2];
typedef int type_63[3];
typedef float type_64[3];
typedef _anon10 type_65[256];
typedef _anon20 type_66[450];
typedef short type_67[256];
typedef _anon33 type_68[16];
typedef int type_69[64];
typedef _anon14 type_70[450];
typedef unsigned int type_71[16];
typedef char type_72[4];
typedef unsigned int type_73[8];
typedef char type_74[3];
typedef _anon38 type_75[4];
typedef _anon4 type_76[4];
typedef int type_77[450];
typedef unsigned int type_78[8];
typedef unsigned char type_79[450];
typedef float type_80[128];
typedef char type_81[16];
typedef char type_82[4];
typedef _anon25 type_84[2];
typedef unsigned int type_85[32];
typedef unsigned char type_86[256];
typedef unsigned int type_87[16];
typedef unsigned int type_88[16];
typedef unsigned int type_89[32];
typedef _anon22 type_90[64];
typedef unsigned int type_91[16];
typedef _anon22 type_92[64];
typedef BH_PWORK* type_93[16];
typedef unsigned int type_94[8];
typedef unsigned int type_95[3];
typedef _anon22 type_96[64];
typedef unsigned int type_97[1];
typedef unsigned int type_98[384];
typedef unsigned int type_99[2];
typedef int* type_100[16];
typedef unsigned int type_101[4];
typedef npobj* type_102[16];
typedef unsigned char type_103[2];
typedef _anon3* type_104[16];
typedef char type_105[32];
typedef char type_106[4];
typedef _anon14 type_107[16];
typedef char type_108[64];
typedef short type_109[4];
typedef unsigned char type_110[4];
typedef unsigned int type_111[8];
typedef _anon37 type_112[16];
typedef unsigned int type_113[4];
typedef unsigned int type_114[32];
typedef _anon0* type_115[512];
typedef _anon35 type_116[32];
typedef _anon0* type_117[128];
typedef _anon0* type_118[512];
typedef unsigned char type_119[64];
typedef _anon0* type_120[512];

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
	_anon3* txp[16];
	_anon14 mdl[16];
	_anon14* mlwP;
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
	_anon7* mnwP;
	_anon7* mnwPb;
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
	_anon42 cspr;
	int pn;
	_anon38* pvp;
	_anon4* tvp;
	_anon38 pv[4];
	_anon4 tv[4];
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

struct _anon2
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
	_anon35 ply_pos;
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
	_anon3* et_lp[16][16][100];
	_anon3* ot_lp[1300];
	_anon3* it_lp[200];
	int eft_n;
	_anon3* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon15* p1per;
	_anon15* p2per;
	_anon15* kbper;
	_anon15* msper;
	_anon15 ms_per;
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
	_anon7* emtp[128];
	_anon7* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	_anon3* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon3* txblp[256];
	_anon10 txbp[256];
	unsigned char* ef_psp;
	_anon20 ef_tex[450];
	_anon3 ef_tlist;
	_anon39 ef;
	short efid[256];
	_anon14 efm[450];
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
	_anon24 ren_info;
	_anon20 ren_tex[1];
	_anon3 ren_tlist;
	_anon9 rpb[256];
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
	_anon40 mr_pl;
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
	_anon32 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon33 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon22* pl_htp;
	int costume;
	_anon35 hd_pos;
	_anon35 apos;
	_anon22* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon22 mwalp[64];
	_anon22 metcp[64];
	_anon22 mflrp[64];
	int dla_n;
	_anon22* htp;
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
	_anon3* sb_tlist;
	int ddmd;
	_anon19 door;
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
	_anon35 ufo_pos;
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
	_anon37 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon35 ghtp[32];
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

struct _anon3
{
	_anon20* textures;
	unsigned int nbTexture;
};

struct _anon4
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon5
{
	float px;
	float py;
	float pz;
	int ay;
};

struct _anon6
{
	_anon13* cutp;
	_anon17* lgtp;
	_anon18* enep;
	_anon18* objp;
	_anon18* itmp;
	_anon21* effp;
	_anon22* walp;
	_anon22* etcp;
	_anon22* flrp;
	_anon5* posp;
	_anon22* rutp;
	unsigned char* ruttp;
	_anon28* evtp;
	_anon8* evcp;
	unsigned int* mesp;
	_anon17* evlp;
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
	_anon14 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};

struct _anon7
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon26* md2P;
	unsigned short* atrP;
};

struct _anon8
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon44 keyf[16];
};

struct _anon9
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
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

struct _anon12
{
	unsigned int num;
	_anon23 tmem[256];
	void* addr[256];
};

struct _anon13
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon16* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon25 cam[2];
	unsigned char exd[256];
};

struct _anon14
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon3* texP;
	_anon31* owP;
};

struct _anon15
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
	_anon1* info;
};

struct _anon16
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
	_anon30* light;
};

struct _anon18
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

struct _anon19
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

struct _anon20
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon21
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

struct _anon22
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

struct _anon23
{
	unsigned int globalIndex;
	unsigned int bank;
	unsigned int tspparambuffer;
	unsigned int texparambuffer;
	unsigned int texaddr;
	_anon24 texinfo;
	unsigned short count;
	unsigned short dummy;
};

struct _anon24
{
	void* texaddr;
	_anon11 texsurface;
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
	_anon3* txp[16];
	_anon14 mdl[16];
	_anon14* mlwP;
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
	_anon7* mnwP;
	_anon7* mnwPb;
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
	_anon43 watr;
	_anon27* cpcl;
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
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon28
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon29
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon30
{
	float mtrx[16];
	_anon35 pnt;
	_anon35 vctr;
	int stat;
	int reserve;
	_anon36 ltcal;
	_anon41 attr;
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
	_anon35 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon33
{
	float x;
	float y;
};

struct _anon34
{
	int* vlist;
	short* plist;
	_anon35 center;
	float r;
};

struct _anon35
{
	float x;
	float y;
	float z;
};

struct _anon36
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
	_anon35 lpnt;
	_anon35 lvctr;
	_anon35 lmvctr;
	_anon29 atten;
	_anon29 amb;
	_anon29 dif;
	_anon29 spc;
	_anon29 mamb;
	_anon29 mdif;
	_anon29 mspc;
};

struct _anon37
{
	_anon35 c1;
	_anon35 c2;
	float r1;
	float r2;
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

struct _anon40
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon41
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
	_anon29 argb;
};

struct _anon42
{
	_anon35 c;
	float r;
};

struct _anon43
{
	_anon35 c1;
	_anon35 c2;
	float r;
};

struct _anon44
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

char fname[128];
_anon24 info;
_anon3 tlist;
_anon2* sys;
char BIO_CURRENT[0];
unsigned int palbuf[0];
_anon23 tbuf[0];
_anon6* rom;
BH_PWORK ene[0];
_anon12 Ps2_tex_save[2];
_anon23* Ps2_tex_info;

void ClutCopy(void* data, void* org_data);
void ClutCopy256(void* data, void* org_data);
int isVQ(unsigned char type);
int bhSetMemPvpTexture(_anon3* tlp, unsigned char* datp, int offset);
void bhReleaseMainTexture();
void Init_PS2_SAVE_TEX();
char* bhCopyTexmem2Mainmem(_anon3* tlp, char* adr);
char* bhCopyTexmem2MainmemSub(_anon3* tlp, char* adr);
void bhCopyMainmem2Texmem(_anon3* tlp);
void bhPushAllTexture();
void bhPopAllTexture();
void bhGarbageTexture(_anon23* addr, unsigned int n);

// 
// Start address: 0x2e5f50
void ClutCopy(void* data, void* org_data)
{
	unsigned int i;
	// Line 136, Address: 0x2e5f50, Func Offset: 0
	// Line 137, Address: 0x2e5f5c, Func Offset: 0xc
	// Line 138, Address: 0x2e5f60, Func Offset: 0x10
	// Line 137, Address: 0x2e5f68, Func Offset: 0x18
	// Line 138, Address: 0x2e5f70, Func Offset: 0x20
	// Line 139, Address: 0x2e5f80, Func Offset: 0x30
	// Line 140, Address: 0x2e5f84, Func Offset: 0x34
	// Line 141, Address: 0x2e5f88, Func Offset: 0x38
	// Line 140, Address: 0x2e5f90, Func Offset: 0x40
	// Line 141, Address: 0x2e5f98, Func Offset: 0x48
	// Line 142, Address: 0x2e5fa0, Func Offset: 0x50
	// Func End, Address: 0x2e5fa8, Func Offset: 0x58
}

// 
// Start address: 0x2e5fb0
void ClutCopy256(void* data, void* org_data)
{
	unsigned int loop;
	unsigned int i;
	unsigned int* op;
	unsigned int* dp;
	// Line 153, Address: 0x2e5fb0, Func Offset: 0
	// Line 154, Address: 0x2e5fb4, Func Offset: 0x4
	// Line 155, Address: 0x2e5fc0, Func Offset: 0x10
	// Line 156, Address: 0x2e5fc4, Func Offset: 0x14
	// Line 155, Address: 0x2e5fcc, Func Offset: 0x1c
	// Line 156, Address: 0x2e5fd4, Func Offset: 0x24
	// Line 157, Address: 0x2e5fdc, Func Offset: 0x2c
	// Line 158, Address: 0x2e5fe8, Func Offset: 0x38
	// Line 159, Address: 0x2e5fec, Func Offset: 0x3c
	// Line 158, Address: 0x2e5ff4, Func Offset: 0x44
	// Line 159, Address: 0x2e5ffc, Func Offset: 0x4c
	// Line 160, Address: 0x2e6004, Func Offset: 0x54
	// Line 161, Address: 0x2e6010, Func Offset: 0x60
	// Line 162, Address: 0x2e6014, Func Offset: 0x64
	// Line 161, Address: 0x2e601c, Func Offset: 0x6c
	// Line 162, Address: 0x2e6024, Func Offset: 0x74
	// Line 163, Address: 0x2e602c, Func Offset: 0x7c
	// Line 164, Address: 0x2e6038, Func Offset: 0x88
	// Line 165, Address: 0x2e603c, Func Offset: 0x8c
	// Line 164, Address: 0x2e6044, Func Offset: 0x94
	// Line 165, Address: 0x2e604c, Func Offset: 0x9c
	// Line 168, Address: 0x2e6054, Func Offset: 0xa4
	// Line 166, Address: 0x2e6058, Func Offset: 0xa8
	// Line 168, Address: 0x2e605c, Func Offset: 0xac
	// Line 169, Address: 0x2e6068, Func Offset: 0xb8
	// Func End, Address: 0x2e6070, Func Offset: 0xc0
}

// 
// Start address: 0x2e6070
int isVQ(unsigned char type)
{
	// Line 205, Address: 0x2e6070, Func Offset: 0
	// Line 206, Address: 0x2e6098, Func Offset: 0x28
	// Func End, Address: 0x2e60a0, Func Offset: 0x30
}

// 
// Start address: 0x2e60a0
int bhSetMemPvpTexture(_anon3* tlp, unsigned char* datp, int offset)
{
	unsigned char* palp;
	unsigned char* dp;
	unsigned char* ap;
	unsigned short et_ct;
	unsigned short et_of;
	unsigned short bk_id;
	unsigned short h;
	unsigned short w;
	unsigned int attr;
	unsigned int gidx;
	unsigned int code;
	int lop;
	int palno;
	int nbTex;
	int end;
	int sz;
	_anon20* tnp;
	unsigned int* clutp;
	unsigned int TEXflag;
	unsigned int VQflag;
	unsigned int palnum;
	unsigned int pal[64];
	// Line 209, Address: 0x2e60a0, Func Offset: 0
	// Line 210, Address: 0x2e60cc, Func Offset: 0x2c
	// Line 220, Address: 0x2e60d0, Func Offset: 0x30
	// Line 222, Address: 0x2e60d4, Func Offset: 0x34
	// Line 220, Address: 0x2e60d8, Func Offset: 0x38
	// Line 222, Address: 0x2e60dc, Func Offset: 0x3c
	// Line 221, Address: 0x2e60ec, Func Offset: 0x4c
	// Line 218, Address: 0x2e60f0, Func Offset: 0x50
	// Line 224, Address: 0x2e60f4, Func Offset: 0x54
	// Line 226, Address: 0x2e60fc, Func Offset: 0x5c
	// Line 230, Address: 0x2e6100, Func Offset: 0x60
	// Line 227, Address: 0x2e6108, Func Offset: 0x68
	// Line 228, Address: 0x2e6114, Func Offset: 0x74
	// Line 229, Address: 0x2e6118, Func Offset: 0x78
	// Line 230, Address: 0x2e6120, Func Offset: 0x80
	// Line 233, Address: 0x2e614c, Func Offset: 0xac
	// Line 235, Address: 0x2e6154, Func Offset: 0xb4
	// Line 236, Address: 0x2e615c, Func Offset: 0xbc
	// Line 239, Address: 0x2e6160, Func Offset: 0xc0
	// Line 236, Address: 0x2e6168, Func Offset: 0xc8
	// Line 239, Address: 0x2e616c, Func Offset: 0xcc
	// Line 243, Address: 0x2e6178, Func Offset: 0xd8
	// Line 245, Address: 0x2e617c, Func Offset: 0xdc
	// Line 243, Address: 0x2e6180, Func Offset: 0xe0
	// Line 245, Address: 0x2e6188, Func Offset: 0xe8
	// Line 248, Address: 0x2e619c, Func Offset: 0xfc
	// Line 250, Address: 0x2e61a4, Func Offset: 0x104
	// Line 254, Address: 0x2e61c0, Func Offset: 0x120
	// Line 257, Address: 0x2e61c8, Func Offset: 0x128
	// Line 259, Address: 0x2e61d0, Func Offset: 0x130
	// Line 261, Address: 0x2e61d8, Func Offset: 0x138
	// Line 262, Address: 0x2e61e0, Func Offset: 0x140
	// Line 264, Address: 0x2e61e4, Func Offset: 0x144
	// Line 262, Address: 0x2e61e8, Func Offset: 0x148
	// Line 264, Address: 0x2e61ec, Func Offset: 0x14c
	// Line 267, Address: 0x2e620c, Func Offset: 0x16c
	// Line 266, Address: 0x2e6210, Func Offset: 0x170
	// Line 268, Address: 0x2e6214, Func Offset: 0x174
	// Line 271, Address: 0x2e621c, Func Offset: 0x17c
	// Line 270, Address: 0x2e6220, Func Offset: 0x180
	// Line 272, Address: 0x2e6224, Func Offset: 0x184
	// Line 275, Address: 0x2e622c, Func Offset: 0x18c
	// Line 277, Address: 0x2e6238, Func Offset: 0x198
	// Line 278, Address: 0x2e623c, Func Offset: 0x19c
	// Line 280, Address: 0x2e6240, Func Offset: 0x1a0
	// Line 281, Address: 0x2e6254, Func Offset: 0x1b4
	// Line 283, Address: 0x2e626c, Func Offset: 0x1cc
	// Line 284, Address: 0x2e6274, Func Offset: 0x1d4
	// Line 285, Address: 0x2e6280, Func Offset: 0x1e0
	// Line 286, Address: 0x2e628c, Func Offset: 0x1ec
	// Line 287, Address: 0x2e6290, Func Offset: 0x1f0
	// Line 286, Address: 0x2e6294, Func Offset: 0x1f4
	// Line 288, Address: 0x2e6298, Func Offset: 0x1f8
	// Line 292, Address: 0x2e62a0, Func Offset: 0x200
	// Line 295, Address: 0x2e62c4, Func Offset: 0x224
	// Line 294, Address: 0x2e62c8, Func Offset: 0x228
	// Line 296, Address: 0x2e62cc, Func Offset: 0x22c
	// Line 299, Address: 0x2e62d4, Func Offset: 0x234
	// Line 298, Address: 0x2e62d8, Func Offset: 0x238
	// Line 300, Address: 0x2e62dc, Func Offset: 0x23c
	// Line 303, Address: 0x2e62e4, Func Offset: 0x244
	// Line 306, Address: 0x2e62f0, Func Offset: 0x250
	// Line 305, Address: 0x2e62f4, Func Offset: 0x254
	// Line 312, Address: 0x2e62f8, Func Offset: 0x258
	// Line 306, Address: 0x2e6300, Func Offset: 0x260
	// Line 308, Address: 0x2e6304, Func Offset: 0x264
	// Line 312, Address: 0x2e6308, Func Offset: 0x268
	// Line 308, Address: 0x2e630c, Func Offset: 0x26c
	// Line 310, Address: 0x2e6328, Func Offset: 0x288
	// Line 312, Address: 0x2e6350, Func Offset: 0x2b0
	// Line 313, Address: 0x2e6358, Func Offset: 0x2b8
	// Line 317, Address: 0x2e635c, Func Offset: 0x2bc
	// Line 313, Address: 0x2e6360, Func Offset: 0x2c0
	// Line 314, Address: 0x2e6364, Func Offset: 0x2c4
	// Line 315, Address: 0x2e6368, Func Offset: 0x2c8
	// Line 316, Address: 0x2e636c, Func Offset: 0x2cc
	// Line 317, Address: 0x2e6370, Func Offset: 0x2d0
	// Line 319, Address: 0x2e6378, Func Offset: 0x2d8
	// Line 320, Address: 0x2e638c, Func Offset: 0x2ec
	// Line 319, Address: 0x2e6394, Func Offset: 0x2f4
	// Line 321, Address: 0x2e6398, Func Offset: 0x2f8
	// Line 320, Address: 0x2e639c, Func Offset: 0x2fc
	// Line 321, Address: 0x2e63a4, Func Offset: 0x304
	// Line 322, Address: 0x2e63cc, Func Offset: 0x32c
	// Line 325, Address: 0x2e63d0, Func Offset: 0x330
	// Line 324, Address: 0x2e63d4, Func Offset: 0x334
	// Line 325, Address: 0x2e63dc, Func Offset: 0x33c
	// Line 333, Address: 0x2e63e4, Func Offset: 0x344
	// Line 334, Address: 0x2e63f4, Func Offset: 0x354
	// Line 335, Address: 0x2e6408, Func Offset: 0x368
	// Line 339, Address: 0x2e6410, Func Offset: 0x370
	// Line 340, Address: 0x2e6420, Func Offset: 0x380
	// Line 341, Address: 0x2e6428, Func Offset: 0x388
	// Line 342, Address: 0x2e642c, Func Offset: 0x38c
	// Line 343, Address: 0x2e6434, Func Offset: 0x394
	// Line 344, Address: 0x2e6440, Func Offset: 0x3a0
	// Line 353, Address: 0x2e6448, Func Offset: 0x3a8
	// Line 354, Address: 0x2e645c, Func Offset: 0x3bc
	// Line 357, Address: 0x2e6468, Func Offset: 0x3c8
	// Line 358, Address: 0x2e6470, Func Offset: 0x3d0
	// Line 359, Address: 0x2e648c, Func Offset: 0x3ec
	// Line 362, Address: 0x2e64a4, Func Offset: 0x404
	// Line 363, Address: 0x2e64ac, Func Offset: 0x40c
	// Line 364, Address: 0x2e64c8, Func Offset: 0x428
	// Line 369, Address: 0x2e64e0, Func Offset: 0x440
	// Line 370, Address: 0x2e64e8, Func Offset: 0x448
	// Line 371, Address: 0x2e64f4, Func Offset: 0x454
	// Line 372, Address: 0x2e6500, Func Offset: 0x460
	// Line 373, Address: 0x2e6504, Func Offset: 0x464
	// Line 372, Address: 0x2e6508, Func Offset: 0x468
	// Line 373, Address: 0x2e6510, Func Offset: 0x470
	// Line 374, Address: 0x2e6518, Func Offset: 0x478
	// Line 376, Address: 0x2e6530, Func Offset: 0x490
	// Line 378, Address: 0x2e6538, Func Offset: 0x498
	// Line 380, Address: 0x2e653c, Func Offset: 0x49c
	// Line 381, Address: 0x2e6540, Func Offset: 0x4a0
	// Line 382, Address: 0x2e654c, Func Offset: 0x4ac
	// Line 383, Address: 0x2e6550, Func Offset: 0x4b0
	// Func End, Address: 0x2e6580, Func Offset: 0x4e0
}

// 
// Start address: 0x2e6580
void bhReleaseMainTexture()
{
	int j;
	int i;
	_anon0* op;
	BH_PWORK* pp;
	// Line 392, Address: 0x2e6580, Func Offset: 0
	// Line 397, Address: 0x2e659c, Func Offset: 0x1c
	// Line 399, Address: 0x2e65b8, Func Offset: 0x38
	// Line 400, Address: 0x2e65c4, Func Offset: 0x44
	// Line 401, Address: 0x2e65f0, Func Offset: 0x70
	// Line 402, Address: 0x2e6600, Func Offset: 0x80
	// Line 403, Address: 0x2e660c, Func Offset: 0x8c
	// Line 404, Address: 0x2e6628, Func Offset: 0xa8
	// Line 405, Address: 0x2e6634, Func Offset: 0xb4
	// Line 407, Address: 0x2e664c, Func Offset: 0xcc
	// Line 409, Address: 0x2e6668, Func Offset: 0xe8
	// Line 410, Address: 0x2e6670, Func Offset: 0xf0
	// Line 409, Address: 0x2e6674, Func Offset: 0xf4
	// Line 410, Address: 0x2e6680, Func Offset: 0x100
	// Line 411, Address: 0x2e6688, Func Offset: 0x108
	// Line 412, Address: 0x2e6698, Func Offset: 0x118
	// Line 413, Address: 0x2e66b4, Func Offset: 0x134
	// Line 414, Address: 0x2e66bc, Func Offset: 0x13c
	// Line 415, Address: 0x2e66c0, Func Offset: 0x140
	// Line 417, Address: 0x2e66e0, Func Offset: 0x160
	// Line 418, Address: 0x2e66f4, Func Offset: 0x174
	// Line 419, Address: 0x2e66fc, Func Offset: 0x17c
	// Line 420, Address: 0x2e670c, Func Offset: 0x18c
	// Line 421, Address: 0x2e6728, Func Offset: 0x1a8
	// Line 423, Address: 0x2e6730, Func Offset: 0x1b0
	// Line 425, Address: 0x2e6750, Func Offset: 0x1d0
	// Line 426, Address: 0x2e676c, Func Offset: 0x1ec
	// Line 427, Address: 0x2e67a0, Func Offset: 0x220
	// Line 428, Address: 0x2e67c0, Func Offset: 0x240
	// Line 429, Address: 0x2e67d8, Func Offset: 0x258
	// Line 430, Address: 0x2e67f8, Func Offset: 0x278
	// Line 432, Address: 0x2e6818, Func Offset: 0x298
	// Line 433, Address: 0x2e6834, Func Offset: 0x2b4
	// Line 434, Address: 0x2e6844, Func Offset: 0x2c4
	// Line 437, Address: 0x2e6858, Func Offset: 0x2d8
	// Line 438, Address: 0x2e6868, Func Offset: 0x2e8
	// Func End, Address: 0x2e6888, Func Offset: 0x308
}

// 
// Start address: 0x2e6890
void Init_PS2_SAVE_TEX()
{
	unsigned int i;
	// Line 446, Address: 0x2e6898, Func Offset: 0x8
	// Line 448, Address: 0x2e689c, Func Offset: 0xc
	// Line 447, Address: 0x2e68a0, Func Offset: 0x10
	// Line 448, Address: 0x2e68a8, Func Offset: 0x18
	// Line 449, Address: 0x2e68b8, Func Offset: 0x28
	// Func End, Address: 0x2e68c0, Func Offset: 0x30
}

// 
// Start address: 0x2e68c0
char* bhCopyTexmem2Mainmem(_anon3* tlp, char* adr)
{
	// Line 464, Address: 0x2e68c0, Func Offset: 0
	// Line 465, Address: 0x2e68d0, Func Offset: 0x10
	// Line 466, Address: 0x2e68dc, Func Offset: 0x1c
	// Line 467, Address: 0x2e68e4, Func Offset: 0x24
	// Line 468, Address: 0x2e68e8, Func Offset: 0x28
	// Func End, Address: 0x2e68fc, Func Offset: 0x3c
}

// 
// Start address: 0x2e6900
char* bhCopyTexmem2MainmemSub(_anon3* tlp, char* adr)
{
	_anon23* tmp;
	unsigned int num;
	unsigned int i;
	// Line 474, Address: 0x2e6900, Func Offset: 0
	// Line 483, Address: 0x2e6924, Func Offset: 0x24
	// Line 489, Address: 0x2e6930, Func Offset: 0x30
	// Line 490, Address: 0x2e6948, Func Offset: 0x48
	// Line 492, Address: 0x2e6954, Func Offset: 0x54
	// Line 493, Address: 0x2e6958, Func Offset: 0x58
	// Line 492, Address: 0x2e6960, Func Offset: 0x60
	// Line 493, Address: 0x2e6968, Func Offset: 0x68
	// Line 499, Address: 0x2e698c, Func Offset: 0x8c
	// Line 500, Address: 0x2e6994, Func Offset: 0x94
	// Line 503, Address: 0x2e69a4, Func Offset: 0xa4
	// Line 502, Address: 0x2e69a8, Func Offset: 0xa8
	// Line 503, Address: 0x2e69b8, Func Offset: 0xb8
	// Line 502, Address: 0x2e69bc, Func Offset: 0xbc
	// Line 503, Address: 0x2e69c8, Func Offset: 0xc8
	// Line 504, Address: 0x2e69e0, Func Offset: 0xe0
	// Line 505, Address: 0x2e69e4, Func Offset: 0xe4
	// Func End, Address: 0x2e6a08, Func Offset: 0x108
}

// 
// Start address: 0x2e6a10
void bhCopyMainmem2Texmem(_anon3* tlp)
{
	_anon23* tmp;
	int no;
	_anon23* addr;
	unsigned int num;
	unsigned int i;
	// Line 515, Address: 0x2e6a10, Func Offset: 0
	// Line 526, Address: 0x2e6a38, Func Offset: 0x28
	// Line 527, Address: 0x2e6a40, Func Offset: 0x30
	// Line 528, Address: 0x2e6a64, Func Offset: 0x54
	// Line 537, Address: 0x2e6a6c, Func Offset: 0x5c
	// Line 538, Address: 0x2e6a84, Func Offset: 0x74
	// Line 540, Address: 0x2e6aa0, Func Offset: 0x90
	// Line 542, Address: 0x2e6ab0, Func Offset: 0xa0
	// Line 543, Address: 0x2e6ab8, Func Offset: 0xa8
	// Line 544, Address: 0x2e6ac0, Func Offset: 0xb0
	// Line 545, Address: 0x2e6ad0, Func Offset: 0xc0
	// Line 546, Address: 0x2e6ae8, Func Offset: 0xd8
	// Line 547, Address: 0x2e6af0, Func Offset: 0xe0
	// Line 549, Address: 0x2e6af8, Func Offset: 0xe8
	// Line 550, Address: 0x2e6b2c, Func Offset: 0x11c
	// Line 551, Address: 0x2e6b34, Func Offset: 0x124
	// Line 553, Address: 0x2e6b38, Func Offset: 0x128
	// Line 554, Address: 0x2e6b48, Func Offset: 0x138
	// Line 558, Address: 0x2e6b50, Func Offset: 0x140
	// Line 554, Address: 0x2e6b54, Func Offset: 0x144
	// Line 558, Address: 0x2e6b60, Func Offset: 0x150
	// Line 559, Address: 0x2e6b78, Func Offset: 0x168
	// Line 560, Address: 0x2e6b80, Func Offset: 0x170
	// Func End, Address: 0x2e6bac, Func Offset: 0x19c
}

// 
// Start address: 0x2e6bb0
void bhPushAllTexture()
{
	// Line 627, Address: 0x2e6bb0, Func Offset: 0
	// Func End, Address: 0x2e6bb8, Func Offset: 0x8
}

// 
// Start address: 0x2e6bc0
void bhPopAllTexture()
{
	// Line 686, Address: 0x2e6bc0, Func Offset: 0
	// Func End, Address: 0x2e6bc8, Func Offset: 0x8
}

// 
// Start address: 0x2e6bd0
void bhGarbageTexture(_anon23* addr, unsigned int n)
{
	// Line 717, Address: 0x2e6bd0, Func Offset: 0
	// Func End, Address: 0x2e6bd8, Func Offset: 0x8
}

