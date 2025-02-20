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
typedef struct BH_PWORK;
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

typedef void(*type_78)(void*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef _anon0* type_2[32];
typedef _anon1* type_3[16];
typedef char* type_4[16];
typedef _anon0* type_5[32];
typedef _anon0* type_6[512];
typedef _anon1* type_7[16][16];
typedef _anon1* type_8[16][16][100];
typedef char type_9[8];
typedef _anon0* type_10[32];
typedef _anon0* type_11[512];
typedef _anon1* type_12[1300];
typedef char type_13[32];
typedef float type_14[32];
typedef _anon0* type_15[512];
typedef _anon1* type_16[200];
typedef short type_17[32];
typedef _anon24 type_18[1];
typedef _anon0* type_19[128];
typedef unsigned int type_20[1];
typedef _anon6 type_21[256];
typedef _anon1* type_22[8];
typedef int* type_23[16];
typedef _anon0* type_24[128];
typedef _anon43 type_25[16];
typedef npobj* type_26[16];
typedef float type_27[3];
typedef _anon0* type_28[128];
typedef int type_29[4];
typedef _anon1* type_30[16];
typedef int type_31[3];
typedef unsigned int type_32[4];
typedef float type_33[4];
typedef _anon13 type_34[16];
typedef _anon0* type_35[512];
typedef float type_36[4];
typedef char type_37[256];
typedef float type_38[4];
typedef float type_39[4];
typedef float type_40[4];
typedef float type_41[4];
typedef _anon4* type_42[128];
typedef unsigned char type_43[64];
typedef float type_44[16];
typedef char type_45[8];
typedef void* type_46[2];
typedef _anon1* type_47[256];
typedef int type_48[4];
typedef unsigned char* type_49[256];
typedef char type_50[0];
typedef unsigned int type_51[2];
typedef short type_52[256];
typedef _anon30 type_53[4];
typedef float type_54[3];
typedef short type_55[256];
typedef int type_56[3];
typedef int type_57[8];
typedef float type_58[3];
typedef _anon1* type_59[256];
typedef _anon10 type_60[256];
typedef _anon24 type_61[450];
typedef _anon32 type_62[16];
typedef short type_63[256];
typedef char type_64[3];
typedef int type_65[64];
typedef _anon13 type_66[450];
typedef unsigned int type_67[16];
typedef char type_68[4];
typedef unsigned int type_69[8];
typedef _anon36 type_70[4];
typedef _anon2 type_71[4];
typedef int type_72[450];
typedef unsigned int type_73[8];
typedef unsigned char type_74[450];
typedef float type_75[128];
typedef char type_76[16];
typedef char type_77[4];
typedef _anon22 type_79[2];
typedef unsigned int type_80[32];
typedef unsigned char type_81[256];
typedef unsigned int type_82[16];
typedef _anon20 type_83[64];
typedef unsigned int type_84[16];
typedef _anon20 type_85[64];
typedef unsigned int type_86[32];
typedef _anon20 type_87[64];
typedef unsigned int type_88[16];
typedef unsigned int type_89[3];
typedef BH_PWORK* type_90[16];
typedef unsigned int type_91[8];
typedef unsigned int type_92[1];
typedef unsigned int type_93[384];
typedef unsigned int type_94[2];
typedef unsigned char type_95[2];
typedef int* type_96[16];
typedef unsigned int type_97[4];
typedef char type_98[32];
typedef npobj* type_99[16];
typedef char type_100[64];
typedef _anon1* type_101[16];
typedef char type_102[4];
typedef _anon13 type_103[16];
typedef short type_104[4];
typedef unsigned char type_105[4];
typedef _anon34 type_106[16];
typedef unsigned int type_107[8];
typedef unsigned int type_108[32];
typedef unsigned int type_109[4];
typedef _anon33 type_110[32];
typedef _anon0* type_111[512];
typedef _anon0* type_112[128];
typedef _anon0* type_113[512];
typedef unsigned char type_114[64];
typedef _anon0* type_115[512];

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
	_anon13 mdl[16];
	_anon13* mlwP;
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
	_anon41 cspr;
	int pn;
	_anon36* pvp;
	_anon2* tvp;
	_anon36 pv[4];
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
	_anon24* textures;
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
	float px;
	float py;
	float pz;
	int ay;
};

struct _anon4
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon23* md2P;
	unsigned short* atrP;
};

struct _anon5
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon43 keyf[16];
};

struct _anon6
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon7
{
	float pos[3];
	int ang[3];
};

struct _anon8
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
	_anon12* cutp;
	_anon16* lgtp;
	_anon8* enep;
	_anon8* objp;
	_anon8* itmp;
	_anon19* effp;
	_anon20* walp;
	_anon20* etcp;
	_anon20* flrp;
	_anon3* posp;
	_anon20* rutp;
	unsigned char* ruttp;
	_anon26* evtp;
	_anon5* evcp;
	unsigned int* mesp;
	_anon16* evlp;
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
	_anon13 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
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
	_anon13 mdl[16];
	_anon13* mlwP;
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
	_anon42 watr;
	_anon25* cpcl;
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

struct _anon12
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon15* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon22 cam[2];
	unsigned char exd[256];
};

struct _anon13
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon28* owP;
};

struct _anon14
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
	_anon39* info;
};

struct _anon15
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
	_anon29* light;
};

struct _anon17
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
	_anon33 ply_pos;
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
	_anon14* p1per;
	_anon14* p2per;
	_anon14* kbper;
	_anon14* msper;
	_anon14 ms_per;
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
	_anon10 txbp[256];
	unsigned char* ef_psp;
	_anon24 ef_tex[450];
	_anon1 ef_tlist;
	_anon37 ef;
	short efid[256];
	_anon13 efm[450];
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
	_anon21 ren_info;
	_anon24 ren_tex[1];
	_anon1 ren_tlist;
	_anon6 rpb[256];
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
	_anon38 mr_pl;
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
	_anon30 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon32 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon20* pl_htp;
	int costume;
	_anon33 hd_pos;
	_anon33 apos;
	_anon20* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon20 mwalp[64];
	_anon20 metcp[64];
	_anon20 mflrp[64];
	int dla_n;
	_anon20* htp;
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
	_anon17 door;
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
	_anon33 ufo_pos;
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
	_anon34 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon33 ghtp[32];
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

struct _anon20
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

struct _anon21
{
	void* texaddr;
	_anon9 texsurface;
};

struct _anon22
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

struct _anon23
{
	void* p[2];
};

struct _anon24
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon25
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon26
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon27
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon28
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon29
{
	float mtrx[16];
	_anon33 pnt;
	_anon33 vctr;
	int stat;
	int reserve;
	_anon35 ltcal;
	_anon40 attr;
};

struct _anon30
{
	_anon33 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon31
{
	int* vlist;
	short* plist;
	_anon33 center;
	float r;
};

struct _anon32
{
	float x;
	float y;
};

struct _anon33
{
	float x;
	float y;
	float z;
};

struct _anon34
{
	_anon33 c1;
	_anon33 c2;
	float r1;
	float r2;
};

struct _anon35
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
	_anon33 lpnt;
	_anon33 lvctr;
	_anon33 lmvctr;
	_anon27 atten;
	_anon27 amb;
	_anon27 dif;
	_anon27 spc;
	_anon27 mamb;
	_anon27 mdif;
	_anon27 mspc;
};

struct _anon36
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon37
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

struct _anon38
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon39
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

struct _anon40
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
	_anon27 argb;
};

struct _anon41
{
	_anon33 c;
	float r;
};

struct _anon42
{
	_anon33 c1;
	_anon33 c2;
	float r;
};

struct _anon43
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

char* mshp_tab[16];
_anon18* sys;
BH_PWORK* plp;
_anon11* rom;
char BIO_CURRENT[0];

void bhReadPlayerData();
void bhReadWeaponData();
unsigned char* bhKeepObjWork(_anon13* mp, unsigned char* sp);

// 
// Start address: 0x2c9ca0
void bhReadPlayerData()
{
	unsigned char* plmtnp;
	unsigned char* mempb;
	unsigned char* plmdlp;
	unsigned char* datp;
	unsigned int dt1;
	unsigned int dt0;
	int plmdlsz;
	int i;
	_anon4* mtnp;
	_anon13* mdlp;
	// Line 81, Address: 0x2c9ca0, Func Offset: 0
	// Line 89, Address: 0x2c9cc4, Func Offset: 0x24
	// Line 98, Address: 0x2c9cd8, Func Offset: 0x38
	// Line 96, Address: 0x2c9cdc, Func Offset: 0x3c
	// Line 98, Address: 0x2c9ce0, Func Offset: 0x40
	// Line 89, Address: 0x2c9ce4, Func Offset: 0x44
	// Line 98, Address: 0x2c9ce8, Func Offset: 0x48
	// Line 97, Address: 0x2c9cec, Func Offset: 0x4c
	// Line 98, Address: 0x2c9cf0, Func Offset: 0x50
	// Line 101, Address: 0x2c9cfc, Func Offset: 0x5c
	// Line 102, Address: 0x2c9d04, Func Offset: 0x64
	// Line 101, Address: 0x2c9d0c, Func Offset: 0x6c
	// Line 102, Address: 0x2c9d18, Func Offset: 0x78
	// Line 103, Address: 0x2c9d20, Func Offset: 0x80
	// Line 105, Address: 0x2c9d2c, Func Offset: 0x8c
	// Line 106, Address: 0x2c9d34, Func Offset: 0x94
	// Line 107, Address: 0x2c9d3c, Func Offset: 0x9c
	// Line 108, Address: 0x2c9d40, Func Offset: 0xa0
	// Line 109, Address: 0x2c9d54, Func Offset: 0xb4
	// Line 110, Address: 0x2c9d6c, Func Offset: 0xcc
	// Line 111, Address: 0x2c9d74, Func Offset: 0xd4
	// Line 112, Address: 0x2c9d80, Func Offset: 0xe0
	// Line 113, Address: 0x2c9da0, Func Offset: 0x100
	// Line 115, Address: 0x2c9da8, Func Offset: 0x108
	// Line 116, Address: 0x2c9db8, Func Offset: 0x118
	// Line 115, Address: 0x2c9dbc, Func Offset: 0x11c
	// Line 116, Address: 0x2c9dc8, Func Offset: 0x128
	// Line 119, Address: 0x2c9dd4, Func Offset: 0x134
	// Line 118, Address: 0x2c9dd8, Func Offset: 0x138
	// Line 116, Address: 0x2c9ddc, Func Offset: 0x13c
	// Line 119, Address: 0x2c9de8, Func Offset: 0x148
	// Line 122, Address: 0x2c9df8, Func Offset: 0x158
	// Line 123, Address: 0x2c9e00, Func Offset: 0x160
	// Line 125, Address: 0x2c9e04, Func Offset: 0x164
	// Line 131, Address: 0x2c9e18, Func Offset: 0x178
	// Line 127, Address: 0x2c9e20, Func Offset: 0x180
	// Line 129, Address: 0x2c9e24, Func Offset: 0x184
	// Line 131, Address: 0x2c9e28, Func Offset: 0x188
	// Line 130, Address: 0x2c9e34, Func Offset: 0x194
	// Line 131, Address: 0x2c9e38, Func Offset: 0x198
	// Line 132, Address: 0x2c9e44, Func Offset: 0x1a4
	// Line 134, Address: 0x2c9e58, Func Offset: 0x1b8
	// Line 135, Address: 0x2c9e60, Func Offset: 0x1c0
	// Line 134, Address: 0x2c9e68, Func Offset: 0x1c8
	// Line 135, Address: 0x2c9e74, Func Offset: 0x1d4
	// Line 136, Address: 0x2c9e84, Func Offset: 0x1e4
	// Line 137, Address: 0x2c9e90, Func Offset: 0x1f0
	// Line 136, Address: 0x2c9e94, Func Offset: 0x1f4
	// Line 137, Address: 0x2c9e98, Func Offset: 0x1f8
	// Line 138, Address: 0x2c9e9c, Func Offset: 0x1fc
	// Line 139, Address: 0x2c9ea4, Func Offset: 0x204
	// Line 140, Address: 0x2c9eac, Func Offset: 0x20c
	// Line 141, Address: 0x2c9eb0, Func Offset: 0x210
	// Line 144, Address: 0x2c9ebc, Func Offset: 0x21c
	// Line 146, Address: 0x2c9ec4, Func Offset: 0x224
	// Line 145, Address: 0x2c9ec8, Func Offset: 0x228
	// Line 147, Address: 0x2c9ecc, Func Offset: 0x22c
	// Line 148, Address: 0x2c9ed0, Func Offset: 0x230
	// Line 149, Address: 0x2c9ed4, Func Offset: 0x234
	// Line 155, Address: 0x2c9ee8, Func Offset: 0x248
	// Line 151, Address: 0x2c9ef0, Func Offset: 0x250
	// Line 153, Address: 0x2c9ef4, Func Offset: 0x254
	// Line 155, Address: 0x2c9ef8, Func Offset: 0x258
	// Line 154, Address: 0x2c9f04, Func Offset: 0x264
	// Line 155, Address: 0x2c9f08, Func Offset: 0x268
	// Line 157, Address: 0x2c9f14, Func Offset: 0x274
	// Line 160, Address: 0x2c9f18, Func Offset: 0x278
	// Line 161, Address: 0x2c9f24, Func Offset: 0x284
	// Line 162, Address: 0x2c9f34, Func Offset: 0x294
	// Line 163, Address: 0x2c9f38, Func Offset: 0x298
	// Line 165, Address: 0x2c9f48, Func Offset: 0x2a8
	// Line 166, Address: 0x2c9f54, Func Offset: 0x2b4
	// Line 165, Address: 0x2c9f58, Func Offset: 0x2b8
	// Line 167, Address: 0x2c9f5c, Func Offset: 0x2bc
	// Line 168, Address: 0x2c9f64, Func Offset: 0x2c4
	// Line 171, Address: 0x2c9f68, Func Offset: 0x2c8
	// Line 172, Address: 0x2c9f6c, Func Offset: 0x2cc
	// Line 171, Address: 0x2c9f74, Func Offset: 0x2d4
	// Line 172, Address: 0x2c9f7c, Func Offset: 0x2dc
	// Line 175, Address: 0x2c9f90, Func Offset: 0x2f0
	// Line 176, Address: 0x2c9f98, Func Offset: 0x2f8
	// Line 178, Address: 0x2c9fac, Func Offset: 0x30c
	// Line 180, Address: 0x2c9fc8, Func Offset: 0x328
	// Line 181, Address: 0x2c9fd4, Func Offset: 0x334
	// Line 180, Address: 0x2c9fdc, Func Offset: 0x33c
	// Line 181, Address: 0x2c9ffc, Func Offset: 0x35c
	// Line 182, Address: 0x2ca004, Func Offset: 0x364
	// Line 184, Address: 0x2ca028, Func Offset: 0x388
	// Line 182, Address: 0x2ca02c, Func Offset: 0x38c
	// Line 184, Address: 0x2ca038, Func Offset: 0x398
	// Line 186, Address: 0x2ca050, Func Offset: 0x3b0
	// Line 188, Address: 0x2ca078, Func Offset: 0x3d8
	// Line 186, Address: 0x2ca07c, Func Offset: 0x3dc
	// Line 188, Address: 0x2ca088, Func Offset: 0x3e8
	// Line 189, Address: 0x2ca098, Func Offset: 0x3f8
	// Func End, Address: 0x2ca0c0, Func Offset: 0x420
}

// 
// Start address: 0x2ca0c0
void bhReadWeaponData()
{
	unsigned char* plmtnp;
	int mtsz;
	_anon4* mtnp;
	unsigned char* mp;
	unsigned char* dp;
	int wpn_no;
	int msz;
	int sz;
	_anon0* op;
	// Line 195, Address: 0x2ca0c0, Func Offset: 0
	// Line 200, Address: 0x2ca0e0, Func Offset: 0x20
	// Line 201, Address: 0x2ca0e8, Func Offset: 0x28
	// Line 200, Address: 0x2ca0f0, Func Offset: 0x30
	// Line 201, Address: 0x2ca0f4, Func Offset: 0x34
	// Line 208, Address: 0x2ca0fc, Func Offset: 0x3c
	// Line 201, Address: 0x2ca100, Func Offset: 0x40
	// Line 208, Address: 0x2ca104, Func Offset: 0x44
	// Line 207, Address: 0x2ca108, Func Offset: 0x48
	// Line 204, Address: 0x2ca110, Func Offset: 0x50
	// Line 207, Address: 0x2ca114, Func Offset: 0x54
	// Line 208, Address: 0x2ca118, Func Offset: 0x58
	// Line 209, Address: 0x2ca120, Func Offset: 0x60
	// Line 210, Address: 0x2ca130, Func Offset: 0x70
	// Line 212, Address: 0x2ca138, Func Offset: 0x78
	// Line 216, Address: 0x2ca144, Func Offset: 0x84
	// Line 217, Address: 0x2ca14c, Func Offset: 0x8c
	// Line 218, Address: 0x2ca154, Func Offset: 0x94
	// Line 217, Address: 0x2ca15c, Func Offset: 0x9c
	// Line 218, Address: 0x2ca168, Func Offset: 0xa8
	// Line 219, Address: 0x2ca170, Func Offset: 0xb0
	// Line 220, Address: 0x2ca180, Func Offset: 0xc0
	// Line 221, Address: 0x2ca188, Func Offset: 0xc8
	// Line 223, Address: 0x2ca194, Func Offset: 0xd4
	// Line 225, Address: 0x2ca198, Func Offset: 0xd8
	// Line 226, Address: 0x2ca19c, Func Offset: 0xdc
	// Line 232, Address: 0x2ca1ac, Func Offset: 0xec
	// Line 235, Address: 0x2ca1b8, Func Offset: 0xf8
	// Line 232, Address: 0x2ca1bc, Func Offset: 0xfc
	// Line 236, Address: 0x2ca1c0, Func Offset: 0x100
	// Line 237, Address: 0x2ca1c8, Func Offset: 0x108
	// Line 239, Address: 0x2ca1cc, Func Offset: 0x10c
	// Line 240, Address: 0x2ca1d4, Func Offset: 0x114
	// Line 241, Address: 0x2ca1e4, Func Offset: 0x124
	// Line 242, Address: 0x2ca1e8, Func Offset: 0x128
	// Line 241, Address: 0x2ca1ec, Func Offset: 0x12c
	// Line 242, Address: 0x2ca1f4, Func Offset: 0x134
	// Line 246, Address: 0x2ca204, Func Offset: 0x144
	// Line 247, Address: 0x2ca21c, Func Offset: 0x15c
	// Line 248, Address: 0x2ca23c, Func Offset: 0x17c
	// Line 256, Address: 0x2ca240, Func Offset: 0x180
	// Line 250, Address: 0x2ca248, Func Offset: 0x188
	// Line 253, Address: 0x2ca24c, Func Offset: 0x18c
	// Line 256, Address: 0x2ca250, Func Offset: 0x190
	// Line 257, Address: 0x2ca25c, Func Offset: 0x19c
	// Line 255, Address: 0x2ca260, Func Offset: 0x1a0
	// Line 257, Address: 0x2ca264, Func Offset: 0x1a4
	// Line 258, Address: 0x2ca270, Func Offset: 0x1b0
	// Line 259, Address: 0x2ca280, Func Offset: 0x1c0
	// Line 261, Address: 0x2ca288, Func Offset: 0x1c8
	// Line 265, Address: 0x2ca294, Func Offset: 0x1d4
	// Line 266, Address: 0x2ca29c, Func Offset: 0x1dc
	// Line 267, Address: 0x2ca2a4, Func Offset: 0x1e4
	// Line 266, Address: 0x2ca2ac, Func Offset: 0x1ec
	// Line 267, Address: 0x2ca2b8, Func Offset: 0x1f8
	// Line 268, Address: 0x2ca2c0, Func Offset: 0x200
	// Line 269, Address: 0x2ca2d0, Func Offset: 0x210
	// Line 270, Address: 0x2ca2d8, Func Offset: 0x218
	// Line 272, Address: 0x2ca2e4, Func Offset: 0x224
	// Line 274, Address: 0x2ca2e8, Func Offset: 0x228
	// Line 275, Address: 0x2ca2ec, Func Offset: 0x22c
	// Line 281, Address: 0x2ca2fc, Func Offset: 0x23c
	// Line 284, Address: 0x2ca308, Func Offset: 0x248
	// Line 281, Address: 0x2ca30c, Func Offset: 0x24c
	// Line 285, Address: 0x2ca310, Func Offset: 0x250
	// Line 286, Address: 0x2ca318, Func Offset: 0x258
	// Line 288, Address: 0x2ca31c, Func Offset: 0x25c
	// Line 289, Address: 0x2ca324, Func Offset: 0x264
	// Line 290, Address: 0x2ca334, Func Offset: 0x274
	// Line 291, Address: 0x2ca338, Func Offset: 0x278
	// Line 290, Address: 0x2ca33c, Func Offset: 0x27c
	// Line 291, Address: 0x2ca344, Func Offset: 0x284
	// Line 295, Address: 0x2ca354, Func Offset: 0x294
	// Line 296, Address: 0x2ca36c, Func Offset: 0x2ac
	// Line 297, Address: 0x2ca38c, Func Offset: 0x2cc
	// Line 299, Address: 0x2ca390, Func Offset: 0x2d0
	// Line 301, Address: 0x2ca394, Func Offset: 0x2d4
	// Line 303, Address: 0x2ca398, Func Offset: 0x2d8
	// Line 307, Address: 0x2ca3a0, Func Offset: 0x2e0
	// Line 308, Address: 0x2ca3a8, Func Offset: 0x2e8
	// Line 307, Address: 0x2ca3b0, Func Offset: 0x2f0
	// Line 308, Address: 0x2ca3bc, Func Offset: 0x2fc
	// Line 309, Address: 0x2ca3c4, Func Offset: 0x304
	// Line 310, Address: 0x2ca3d8, Func Offset: 0x318
	// Line 311, Address: 0x2ca3e4, Func Offset: 0x324
	// Line 312, Address: 0x2ca3ec, Func Offset: 0x32c
	// Line 313, Address: 0x2ca3f4, Func Offset: 0x334
	// Line 314, Address: 0x2ca3f8, Func Offset: 0x338
	// Line 316, Address: 0x2ca404, Func Offset: 0x344
	// Line 317, Address: 0x2ca40c, Func Offset: 0x34c
	// Line 319, Address: 0x2ca410, Func Offset: 0x350
	// Line 320, Address: 0x2ca414, Func Offset: 0x354
	// Line 324, Address: 0x2ca428, Func Offset: 0x368
	// Func End, Address: 0x2ca44c, Func Offset: 0x38c
}

// 
// Start address: 0x2ca450
unsigned char* bhKeepObjWork(_anon13* mp, unsigned char* sp)
{
	// Line 648, Address: 0x2ca450, Func Offset: 0
	// Line 651, Address: 0x2ca464, Func Offset: 0x14
	// Line 656, Address: 0x2ca470, Func Offset: 0x20
	// Line 657, Address: 0x2ca474, Func Offset: 0x24
	// Line 658, Address: 0x2ca494, Func Offset: 0x44
	// Line 660, Address: 0x2ca498, Func Offset: 0x48
	// Line 658, Address: 0x2ca49c, Func Offset: 0x4c
	// Line 660, Address: 0x2ca4a4, Func Offset: 0x54
	// Line 658, Address: 0x2ca4a8, Func Offset: 0x58
	// Line 659, Address: 0x2ca4b0, Func Offset: 0x60
	// Line 660, Address: 0x2ca4b4, Func Offset: 0x64
	// Func End, Address: 0x2ca4c0, Func Offset: 0x70
}

