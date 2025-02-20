typedef struct npobj;
typedef struct _anon0;
typedef struct BH_PWORK;
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

typedef void(*type_77)(void*);

typedef unsigned int type_0[4];
typedef char type_1[32];
typedef _anon0* type_2[512];
typedef _anon0* type_3[32];
typedef _anon1* type_4[16];
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
typedef _anon0* type_27[128];
typedef int type_28[4];
typedef _anon1* type_29[16];
typedef unsigned int type_30[4];
typedef float type_31[4];
typedef _anon11 type_32[16];
typedef _anon0* type_33[512];
typedef float type_34[4];
typedef char type_35[256];
typedef float type_36[4];
typedef float type_37[4];
typedef float type_38[4];
typedef float type_39[4];
typedef _anon4* type_40[128];
typedef unsigned char type_41[64];
typedef float type_42[16];
typedef BH_PWORK type_43[0];
typedef char type_44[8];
typedef void* type_45[2];
typedef _anon0 type_46[0];
typedef _anon1* type_47[256];
typedef int type_48[4];
typedef unsigned char* type_49[256];
typedef unsigned int type_50[2];
typedef short type_51[256];
typedef _anon30 type_52[4];
typedef float type_53[3];
typedef short type_54[256];
typedef int type_55[3];
typedef int type_56[8];
typedef float type_57[3];
typedef _anon1* type_58[256];
typedef _anon8 type_59[256];
typedef _anon24 type_60[450];
typedef _anon32 type_61[16];
typedef short type_62[256];
typedef char type_63[3];
typedef int type_64[64];
typedef _anon11 type_65[450];
typedef unsigned int type_66[16];
typedef char type_67[4];
typedef unsigned int type_68[8];
typedef _anon36 type_69[4];
typedef _anon2 type_70[4];
typedef int type_71[450];
typedef unsigned int type_72[8];
typedef unsigned char type_73[450];
typedef float type_74[128];
typedef char type_75[16];
typedef char type_76[4];
typedef unsigned int type_78[32];
typedef _anon22 type_79[2];
typedef unsigned char type_80[256];
typedef unsigned int type_81[16];
typedef _anon20 type_82[64];
typedef unsigned int type_83[16];
typedef _anon20 type_84[64];
typedef unsigned int type_85[32];
typedef _anon20 type_86[64];
typedef unsigned int type_87[16];
typedef unsigned int type_88[3];
typedef BH_PWORK* type_89[16];
typedef unsigned int type_90[8];
typedef unsigned int type_91[1];
typedef unsigned int type_92[384];
typedef unsigned int type_93[2];
typedef unsigned char type_94[2];
typedef int* type_95[16];
typedef unsigned int type_96[4];
typedef char type_97[32];
typedef npobj* type_98[16];
typedef char type_99[64];
typedef _anon1* type_100[16];
typedef char type_101[4];
typedef _anon11 type_102[16];
typedef short type_103[4];
typedef unsigned char type_104[4];
typedef _anon34 type_105[16];
typedef unsigned int type_106[8];
typedef unsigned int type_107[32];
typedef unsigned int type_108[4];
typedef _anon33 type_109[32];
typedef _anon0* type_110[512];
typedef _anon0* type_111[128];
typedef _anon0* type_112[512];
typedef unsigned char type_113[64];
typedef _anon0* type_114[512];

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
	_anon11 mdl[16];
	_anon11* mlwP;
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
	_anon11 mdl[16];
	_anon11* mlwP;
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
	_anon10* cutp;
	_anon14* lgtp;
	_anon17* enep;
	_anon17* objp;
	_anon17* itmp;
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
	_anon14* evlp;
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
	_anon11 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};

struct _anon10
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon13* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon22 cam[2];
	unsigned char exd[256];
};

struct _anon11
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon28* owP;
};

struct _anon12
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

struct _anon13
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
	_anon29* light;
};

struct _anon15
{
	float ver;
	unsigned int flg;
	unsigned int dat0;
	unsigned int dat1;
	unsigned int hed00;
	unsigned int hed01;
	unsigned int hed02;
	unsigned int hed03;
	unsigned int hed04;
	unsigned int hed05;
	unsigned int hed06;
	unsigned int hed07;
	unsigned int hed08;
	unsigned int hed09;
	unsigned int hed10;
	unsigned int hed11;
	unsigned int hed12;
	unsigned int hed13;
	unsigned int hed14;
	unsigned int hed15;
	unsigned int hed16;
	unsigned int hed17;
	unsigned int hed18;
	unsigned int hed19;
	char usrname[32];
};

struct _anon16
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
	_anon12* p1per;
	_anon12* p2per;
	_anon12* kbper;
	_anon12* msper;
	_anon12 ms_per;
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
	_anon24 ef_tex[450];
	_anon1 ef_tlist;
	_anon37 ef;
	short efid[256];
	_anon11 efm[450];
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
	_anon14* lgtp;
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
	_anon18 door;
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

struct _anon17
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

struct _anon18
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
	_anon7 texsurface;
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

_anon9* rom;
_anon16* sys;
BH_PWORK ene[0];
BH_PWORK* plp;
_anon0 eff[0];
unsigned char* freemem;

void bhInitRoom();
void bhInitReadRDT();
void bhSetRDT();
void bhSetRoom();
void bhFinishRoom();
void bhSetEneMdl(unsigned char* datp, _anon17* ep, int mdlno, int eno);
void bhSetEneMtn(unsigned char* datp, BH_PWORK* ep, int id);
void bhSetRoomMtn(unsigned char* datp);
void bhSetObjMdl(unsigned char* datp, _anon17* ep, int eno);
void bhSetItmMdl(unsigned char* datp, _anon17* ep, int eno);
void bhSetEffectTable();
void bhSetEffectLink(_anon19* efp, int efid);
void bhSetDoorDemo(unsigned int attr, int stg_no, int rom_no, unsigned int pos_no, unsigned int dor_tp);
void bhStartDoorDemo();
void bhPushGameData();
void bhPopGameData();

// 
// Start address: 0x287bb0
void bhInitRoom()
{
	// Line 111, Address: 0x287bb0, Func Offset: 0
	// Func End, Address: 0x287bc4, Func Offset: 0x14
}

// 
// Start address: 0x287bd0
void bhInitReadRDT()
{
	// Line 118, Address: 0x287bd0, Func Offset: 0
	// Line 120, Address: 0x287bd8, Func Offset: 0x8
	// Line 122, Address: 0x287be8, Func Offset: 0x18
	// Line 127, Address: 0x287bf0, Func Offset: 0x20
	// Line 129, Address: 0x287bf8, Func Offset: 0x28
	// Line 131, Address: 0x287c00, Func Offset: 0x30
	// Line 133, Address: 0x287c08, Func Offset: 0x38
	// Line 134, Address: 0x287c10, Func Offset: 0x40
	// Func End, Address: 0x287c1c, Func Offset: 0x4c
}

// 
// Start address: 0x287c20
void bhSetRDT()
{
	// Line 142, Address: 0x287c20, Func Offset: 0
	// Func End, Address: 0x287c28, Func Offset: 0x8
}

// 
// Start address: 0x287c30
void bhSetRoom()
{
	unsigned char* reladr;
	unsigned char* datp;
	unsigned int* romp;
	unsigned int* texhed;
	unsigned int* mdlhed;
	unsigned int nbt;
	int nbTex;
	int k;
	int j;
	int i;
	_anon0* owp;
	BH_PWORK* pwp;
	_anon19* efp;
	_anon17* ep;
	_anon10* cp;
	_anon15* rh;
	// Line 149, Address: 0x287c30, Func Offset: 0
	// Line 170, Address: 0x287c4c, Func Offset: 0x1c
	// Line 172, Address: 0x287c54, Func Offset: 0x24
	// Line 170, Address: 0x287c60, Func Offset: 0x30
	// Line 172, Address: 0x287c6c, Func Offset: 0x3c
	// Line 173, Address: 0x287c80, Func Offset: 0x50
	// Line 174, Address: 0x287c88, Func Offset: 0x58
	// Line 186, Address: 0x287c90, Func Offset: 0x60
	// Line 188, Address: 0x287ca8, Func Offset: 0x78
	// Line 189, Address: 0x287cb4, Func Offset: 0x84
	// Line 194, Address: 0x287cd4, Func Offset: 0xa4
	// Line 196, Address: 0x287cf0, Func Offset: 0xc0
	// Line 197, Address: 0x287cf4, Func Offset: 0xc4
	// Line 199, Address: 0x287cfc, Func Offset: 0xcc
	// Line 204, Address: 0x287d08, Func Offset: 0xd8
	// Line 199, Address: 0x287d0c, Func Offset: 0xdc
	// Line 204, Address: 0x287d20, Func Offset: 0xf0
	// Line 206, Address: 0x287d40, Func Offset: 0x110
	// Line 212, Address: 0x287d44, Func Offset: 0x114
	// Line 214, Address: 0x287d50, Func Offset: 0x120
	// Line 212, Address: 0x287d60, Func Offset: 0x130
	// Line 214, Address: 0x287d6c, Func Offset: 0x13c
	// Line 215, Address: 0x287d78, Func Offset: 0x148
	// Line 220, Address: 0x287d84, Func Offset: 0x154
	// Line 215, Address: 0x287d8c, Func Offset: 0x15c
	// Line 220, Address: 0x287d9c, Func Offset: 0x16c
	// Line 221, Address: 0x287da8, Func Offset: 0x178
	// Line 223, Address: 0x287db8, Func Offset: 0x188
	// Line 224, Address: 0x287dc0, Func Offset: 0x190
	// Line 225, Address: 0x287dc8, Func Offset: 0x198
	// Line 226, Address: 0x287dd0, Func Offset: 0x1a0
	// Line 227, Address: 0x287dd8, Func Offset: 0x1a8
	// Line 226, Address: 0x287de0, Func Offset: 0x1b0
	// Line 227, Address: 0x287dec, Func Offset: 0x1bc
	// Line 228, Address: 0x287df4, Func Offset: 0x1c4
	// Line 229, Address: 0x287e04, Func Offset: 0x1d4
	// Line 230, Address: 0x287e14, Func Offset: 0x1e4
	// Line 231, Address: 0x287e20, Func Offset: 0x1f0
	// Line 232, Address: 0x287e28, Func Offset: 0x1f8
	// Line 233, Address: 0x287e38, Func Offset: 0x208
	// Line 238, Address: 0x287e44, Func Offset: 0x214
	// Line 233, Address: 0x287e50, Func Offset: 0x220
	// Line 238, Address: 0x287e60, Func Offset: 0x230
	// Line 240, Address: 0x287e68, Func Offset: 0x238
	// Line 250, Address: 0x287e88, Func Offset: 0x258
	// Line 251, Address: 0x287e8c, Func Offset: 0x25c
	// Line 252, Address: 0x287e98, Func Offset: 0x268
	// Line 257, Address: 0x287ea4, Func Offset: 0x274
	// Line 252, Address: 0x287eb0, Func Offset: 0x280
	// Line 257, Address: 0x287ec0, Func Offset: 0x290
	// Line 258, Address: 0x287ec8, Func Offset: 0x298
	// Line 260, Address: 0x287ee8, Func Offset: 0x2b8
	// Line 261, Address: 0x287eec, Func Offset: 0x2bc
	// Line 262, Address: 0x287ef4, Func Offset: 0x2c4
	// Line 267, Address: 0x287f00, Func Offset: 0x2d0
	// Line 262, Address: 0x287f0c, Func Offset: 0x2dc
	// Line 267, Address: 0x287f1c, Func Offset: 0x2ec
	// Line 268, Address: 0x287f24, Func Offset: 0x2f4
	// Line 274, Address: 0x287f48, Func Offset: 0x318
	// Line 288, Address: 0x287f68, Func Offset: 0x338
	// Line 290, Address: 0x287f90, Func Offset: 0x360
	// Line 300, Address: 0x287f9c, Func Offset: 0x36c
	// Line 290, Address: 0x287fa4, Func Offset: 0x374
	// Line 300, Address: 0x287fac, Func Offset: 0x37c
	// Line 290, Address: 0x287fb0, Func Offset: 0x380
	// Line 295, Address: 0x287fb8, Func Offset: 0x388
	// Line 293, Address: 0x287fbc, Func Offset: 0x38c
	// Line 291, Address: 0x287fc0, Func Offset: 0x390
	// Line 295, Address: 0x287fc4, Func Offset: 0x394
	// Line 300, Address: 0x287fc8, Func Offset: 0x398
	// Line 301, Address: 0x287fd0, Func Offset: 0x3a0
	// Line 302, Address: 0x287ff0, Func Offset: 0x3c0
	// Line 303, Address: 0x288018, Func Offset: 0x3e8
	// Line 304, Address: 0x288040, Func Offset: 0x410
	// Line 308, Address: 0x288064, Func Offset: 0x434
	// Line 306, Address: 0x288068, Func Offset: 0x438
	// Line 308, Address: 0x28806c, Func Offset: 0x43c
	// Line 309, Address: 0x288070, Func Offset: 0x440
	// Line 310, Address: 0x288078, Func Offset: 0x448
	// Line 311, Address: 0x288084, Func Offset: 0x454
	// Line 313, Address: 0x2880a0, Func Offset: 0x470
	// Line 322, Address: 0x2880ac, Func Offset: 0x47c
	// Line 313, Address: 0x2880b0, Func Offset: 0x480
	// Line 318, Address: 0x2880c0, Func Offset: 0x490
	// Line 313, Address: 0x2880cc, Func Offset: 0x49c
	// Line 318, Address: 0x2880d0, Func Offset: 0x4a0
	// Line 319, Address: 0x2880e4, Func Offset: 0x4b4
	// Line 320, Address: 0x28810c, Func Offset: 0x4dc
	// Line 321, Address: 0x288134, Func Offset: 0x504
	// Line 322, Address: 0x288158, Func Offset: 0x528
	// Line 324, Address: 0x28815c, Func Offset: 0x52c
	// Line 325, Address: 0x288170, Func Offset: 0x540
	// Line 327, Address: 0x288190, Func Offset: 0x560
	// Line 328, Address: 0x2881c0, Func Offset: 0x590
	// Line 329, Address: 0x2881c8, Func Offset: 0x598
	// Line 328, Address: 0x2881d0, Func Offset: 0x5a0
	// Line 329, Address: 0x2881dc, Func Offset: 0x5ac
	// Line 330, Address: 0x2881e4, Func Offset: 0x5b4
	// Line 331, Address: 0x2881f4, Func Offset: 0x5c4
	// Line 333, Address: 0x28821c, Func Offset: 0x5ec
	// Line 334, Address: 0x288220, Func Offset: 0x5f0
	// Line 344, Address: 0x288224, Func Offset: 0x5f4
	// Line 333, Address: 0x288228, Func Offset: 0x5f8
	// Line 334, Address: 0x288230, Func Offset: 0x600
	// Line 335, Address: 0x288254, Func Offset: 0x624
	// Line 340, Address: 0x28825c, Func Offset: 0x62c
	// Line 335, Address: 0x288260, Func Offset: 0x630
	// Line 340, Address: 0x28826c, Func Offset: 0x63c
	// Line 335, Address: 0x288270, Func Offset: 0x640
	// Line 340, Address: 0x288278, Func Offset: 0x648
	// Line 335, Address: 0x288284, Func Offset: 0x654
	// Line 340, Address: 0x288288, Func Offset: 0x658
	// Line 341, Address: 0x28829c, Func Offset: 0x66c
	// Line 342, Address: 0x2882c4, Func Offset: 0x694
	// Line 343, Address: 0x2882ec, Func Offset: 0x6bc
	// Line 345, Address: 0x28830c, Func Offset: 0x6dc
	// Line 346, Address: 0x288314, Func Offset: 0x6e4
	// Line 347, Address: 0x288318, Func Offset: 0x6e8
	// Line 346, Address: 0x28831c, Func Offset: 0x6ec
	// Line 347, Address: 0x288324, Func Offset: 0x6f4
	// Line 350, Address: 0x288348, Func Offset: 0x718
	// Line 352, Address: 0x288368, Func Offset: 0x738
	// Line 353, Address: 0x288398, Func Offset: 0x768
	// Line 354, Address: 0x2883a0, Func Offset: 0x770
	// Line 353, Address: 0x2883a4, Func Offset: 0x774
	// Line 354, Address: 0x2883b0, Func Offset: 0x780
	// Line 355, Address: 0x2883b8, Func Offset: 0x788
	// Line 356, Address: 0x2883c8, Func Offset: 0x798
	// Line 358, Address: 0x2883f0, Func Offset: 0x7c0
	// Line 359, Address: 0x2883f4, Func Offset: 0x7c4
	// Line 369, Address: 0x2883f8, Func Offset: 0x7c8
	// Line 358, Address: 0x2883fc, Func Offset: 0x7cc
	// Line 359, Address: 0x288404, Func Offset: 0x7d4
	// Line 360, Address: 0x288428, Func Offset: 0x7f8
	// Line 365, Address: 0x288430, Func Offset: 0x800
	// Line 360, Address: 0x288434, Func Offset: 0x804
	// Line 365, Address: 0x288440, Func Offset: 0x810
	// Line 360, Address: 0x288444, Func Offset: 0x814
	// Line 365, Address: 0x28844c, Func Offset: 0x81c
	// Line 360, Address: 0x288458, Func Offset: 0x828
	// Line 365, Address: 0x28845c, Func Offset: 0x82c
	// Line 366, Address: 0x288470, Func Offset: 0x840
	// Line 367, Address: 0x288498, Func Offset: 0x868
	// Line 368, Address: 0x2884c0, Func Offset: 0x890
	// Line 370, Address: 0x2884e0, Func Offset: 0x8b0
	// Line 371, Address: 0x2884e8, Func Offset: 0x8b8
	// Line 372, Address: 0x2884ec, Func Offset: 0x8bc
	// Line 371, Address: 0x2884f0, Func Offset: 0x8c0
	// Line 372, Address: 0x2884f8, Func Offset: 0x8c8
	// Line 374, Address: 0x28851c, Func Offset: 0x8ec
	// Line 375, Address: 0x288520, Func Offset: 0x8f0
	// Line 377, Address: 0x288540, Func Offset: 0x910
	// Line 378, Address: 0x288544, Func Offset: 0x914
	// Line 379, Address: 0x288550, Func Offset: 0x920
	// Line 380, Address: 0x288580, Func Offset: 0x950
	// Line 381, Address: 0x2885b8, Func Offset: 0x988
	// Line 382, Address: 0x2885d8, Func Offset: 0x9a8
	// Line 391, Address: 0x2885dc, Func Offset: 0x9ac
	// Line 392, Address: 0x2885e4, Func Offset: 0x9b4
	// Line 393, Address: 0x2885ec, Func Offset: 0x9bc
	// Line 392, Address: 0x2885f4, Func Offset: 0x9c4
	// Line 393, Address: 0x288604, Func Offset: 0x9d4
	// Line 394, Address: 0x28860c, Func Offset: 0x9dc
	// Line 395, Address: 0x288614, Func Offset: 0x9e4
	// Line 396, Address: 0x28861c, Func Offset: 0x9ec
	// Line 395, Address: 0x288624, Func Offset: 0x9f4
	// Line 396, Address: 0x288634, Func Offset: 0xa04
	// Line 398, Address: 0x28863c, Func Offset: 0xa0c
	// Line 399, Address: 0x288644, Func Offset: 0xa14
	// Line 400, Address: 0x288670, Func Offset: 0xa40
	// Line 402, Address: 0x2886a8, Func Offset: 0xa78
	// Line 403, Address: 0x2886b0, Func Offset: 0xa80
	// Line 409, Address: 0x2886cc, Func Offset: 0xa9c
	// Line 403, Address: 0x2886d8, Func Offset: 0xaa8
	// Line 409, Address: 0x2886dc, Func Offset: 0xaac
	// Line 410, Address: 0x2886ec, Func Offset: 0xabc
	// Line 425, Address: 0x2886f4, Func Offset: 0xac4
	// Line 410, Address: 0x2886f8, Func Offset: 0xac8
	// Line 411, Address: 0x288714, Func Offset: 0xae4
	// Line 412, Address: 0x288748, Func Offset: 0xb18
	// Line 413, Address: 0x288774, Func Offset: 0xb44
	// Line 414, Address: 0x288798, Func Offset: 0xb68
	// Line 423, Address: 0x2887b8, Func Offset: 0xb88
	// Line 427, Address: 0x28880c, Func Offset: 0xbdc
	// Line 428, Address: 0x288810, Func Offset: 0xbe0
	// Line 436, Address: 0x288830, Func Offset: 0xc00
	// Line 437, Address: 0x288844, Func Offset: 0xc14
	// Func End, Address: 0x288864, Func Offset: 0xc34
}

// 
// Start address: 0x288870
void bhFinishRoom()
{
	unsigned char* datp;
	unsigned int* mtnhed;
	int j;
	int i;
	_anon15* rh;
	_anon0* owp;
	BH_PWORK* pwp;
	// Line 443, Address: 0x288870, Func Offset: 0
	// Line 455, Address: 0x288888, Func Offset: 0x18
	// Line 460, Address: 0x288890, Func Offset: 0x20
	// Line 455, Address: 0x288898, Func Offset: 0x28
	// Line 460, Address: 0x2888a8, Func Offset: 0x38
	// Line 463, Address: 0x2888d0, Func Offset: 0x60
	// Line 466, Address: 0x2888d8, Func Offset: 0x68
	// Line 467, Address: 0x2888e0, Func Offset: 0x70
	// Line 463, Address: 0x2888e4, Func Offset: 0x74
	// Line 465, Address: 0x2888f8, Func Offset: 0x88
	// Line 467, Address: 0x28891c, Func Offset: 0xac
	// Line 469, Address: 0x288924, Func Offset: 0xb4
	// Line 470, Address: 0x288930, Func Offset: 0xc0
	// Line 471, Address: 0x288944, Func Offset: 0xd4
	// Line 476, Address: 0x288950, Func Offset: 0xe0
	// Line 471, Address: 0x288958, Func Offset: 0xe8
	// Line 476, Address: 0x288968, Func Offset: 0xf8
	// Line 477, Address: 0x288970, Func Offset: 0x100
	// Line 478, Address: 0x288978, Func Offset: 0x108
	// Line 479, Address: 0x2889a0, Func Offset: 0x130
	// Line 480, Address: 0x2889a4, Func Offset: 0x134
	// Line 481, Address: 0x2889a8, Func Offset: 0x138
	// Line 483, Address: 0x2889b0, Func Offset: 0x140
	// Line 484, Address: 0x2889c4, Func Offset: 0x154
	// Line 486, Address: 0x2889c8, Func Offset: 0x158
	// Line 483, Address: 0x2889cc, Func Offset: 0x15c
	// Line 484, Address: 0x2889d8, Func Offset: 0x168
	// Line 485, Address: 0x2889ec, Func Offset: 0x17c
	// Line 486, Address: 0x288a10, Func Offset: 0x1a0
	// Line 487, Address: 0x288a1c, Func Offset: 0x1ac
	// Line 488, Address: 0x288a20, Func Offset: 0x1b0
	// Line 487, Address: 0x288a24, Func Offset: 0x1b4
	// Line 488, Address: 0x288a28, Func Offset: 0x1b8
	// Line 490, Address: 0x288a48, Func Offset: 0x1d8
	// Line 491, Address: 0x288a4c, Func Offset: 0x1dc
	// Line 492, Address: 0x288a50, Func Offset: 0x1e0
	// Line 498, Address: 0x288a70, Func Offset: 0x200
	// Line 504, Address: 0x288a7c, Func Offset: 0x20c
	// Line 499, Address: 0x288a84, Func Offset: 0x214
	// Line 504, Address: 0x288a88, Func Offset: 0x218
	// Line 505, Address: 0x288a9c, Func Offset: 0x22c
	// Line 508, Address: 0x288aa4, Func Offset: 0x234
	// Line 510, Address: 0x288ab0, Func Offset: 0x240
	// Line 506, Address: 0x288ab4, Func Offset: 0x244
	// Line 508, Address: 0x288ab8, Func Offset: 0x248
	// Line 509, Address: 0x288ac8, Func Offset: 0x258
	// Line 508, Address: 0x288acc, Func Offset: 0x25c
	// Line 509, Address: 0x288ad8, Func Offset: 0x268
	// Line 510, Address: 0x288af4, Func Offset: 0x284
	// Line 511, Address: 0x288b10, Func Offset: 0x2a0
	// Line 518, Address: 0x288b34, Func Offset: 0x2c4
	// Line 519, Address: 0x288b40, Func Offset: 0x2d0
	// Line 524, Address: 0x288b58, Func Offset: 0x2e8
	// Line 519, Address: 0x288b5c, Func Offset: 0x2ec
	// Line 524, Address: 0x288b60, Func Offset: 0x2f0
	// Line 525, Address: 0x288b64, Func Offset: 0x2f4
	// Line 527, Address: 0x288b6c, Func Offset: 0x2fc
	// Line 526, Address: 0x288b74, Func Offset: 0x304
	// Line 527, Address: 0x288b78, Func Offset: 0x308
	// Line 534, Address: 0x288b84, Func Offset: 0x314
	// Line 535, Address: 0x288b90, Func Offset: 0x320
	// Line 540, Address: 0x288ba4, Func Offset: 0x334
	// Line 535, Address: 0x288ba8, Func Offset: 0x338
	// Line 540, Address: 0x288bac, Func Offset: 0x33c
	// Line 541, Address: 0x288bb0, Func Offset: 0x340
	// Line 543, Address: 0x288bb8, Func Offset: 0x348
	// Line 553, Address: 0x288bcc, Func Offset: 0x35c
	// Line 554, Address: 0x288bd4, Func Offset: 0x364
	// Line 555, Address: 0x288bdc, Func Offset: 0x36c
	// Line 556, Address: 0x288be8, Func Offset: 0x378
	// Line 557, Address: 0x288c0c, Func Offset: 0x39c
	// Line 556, Address: 0x288c10, Func Offset: 0x3a0
	// Line 557, Address: 0x288c18, Func Offset: 0x3a8
	// Line 558, Address: 0x288c24, Func Offset: 0x3b4
	// Line 559, Address: 0x288c38, Func Offset: 0x3c8
	// Line 561, Address: 0x288c48, Func Offset: 0x3d8
	// Line 563, Address: 0x288c50, Func Offset: 0x3e0
	// Line 569, Address: 0x288c70, Func Offset: 0x400
	// Line 570, Address: 0x288c78, Func Offset: 0x408
	// Line 569, Address: 0x288c7c, Func Offset: 0x40c
	// Line 570, Address: 0x288c88, Func Offset: 0x418
	// Line 571, Address: 0x288c90, Func Offset: 0x420
	// Line 572, Address: 0x288cb4, Func Offset: 0x444
	// Line 571, Address: 0x288cbc, Func Offset: 0x44c
	// Line 572, Address: 0x288cc8, Func Offset: 0x458
	// Line 578, Address: 0x288ce0, Func Offset: 0x470
	// Line 579, Address: 0x288cf4, Func Offset: 0x484
	// Line 580, Address: 0x288cfc, Func Offset: 0x48c
	// Line 581, Address: 0x288d20, Func Offset: 0x4b0
	// Line 580, Address: 0x288d28, Func Offset: 0x4b8
	// Line 581, Address: 0x288d34, Func Offset: 0x4c4
	// Line 589, Address: 0x288d50, Func Offset: 0x4e0
	// Line 593, Address: 0x288d58, Func Offset: 0x4e8
	// Line 601, Address: 0x288d60, Func Offset: 0x4f0
	// Line 602, Address: 0x288d6c, Func Offset: 0x4fc
	// Line 601, Address: 0x288d70, Func Offset: 0x500
	// Line 602, Address: 0x288d74, Func Offset: 0x504
	// Line 601, Address: 0x288d78, Func Offset: 0x508
	// Line 602, Address: 0x288d80, Func Offset: 0x510
	// Line 604, Address: 0x288d9c, Func Offset: 0x52c
	// Line 606, Address: 0x288da4, Func Offset: 0x534
	// Line 608, Address: 0x288dc0, Func Offset: 0x550
	// Line 616, Address: 0x288dcc, Func Offset: 0x55c
	// Line 609, Address: 0x288dd4, Func Offset: 0x564
	// Line 608, Address: 0x288dd8, Func Offset: 0x568
	// Line 609, Address: 0x288de0, Func Offset: 0x570
	// Line 611, Address: 0x288de4, Func Offset: 0x574
	// Line 609, Address: 0x288de8, Func Offset: 0x578
	// Line 610, Address: 0x288df4, Func Offset: 0x584
	// Line 609, Address: 0x288df8, Func Offset: 0x588
	// Line 610, Address: 0x288dfc, Func Offset: 0x58c
	// Line 611, Address: 0x288e18, Func Offset: 0x5a8
	// Line 610, Address: 0x288e1c, Func Offset: 0x5ac
	// Line 611, Address: 0x288e20, Func Offset: 0x5b0
	// Line 612, Address: 0x288e28, Func Offset: 0x5b8
	// Line 611, Address: 0x288e2c, Func Offset: 0x5bc
	// Line 612, Address: 0x288e34, Func Offset: 0x5c4
	// Line 613, Address: 0x288e74, Func Offset: 0x604
	// Line 614, Address: 0x288eb8, Func Offset: 0x648
	// Line 615, Address: 0x288efc, Func Offset: 0x68c
	// Line 616, Address: 0x288f1c, Func Offset: 0x6ac
	// Line 615, Address: 0x288f20, Func Offset: 0x6b0
	// Line 616, Address: 0x288f24, Func Offset: 0x6b4
	// Line 617, Address: 0x288f44, Func Offset: 0x6d4
	// Line 616, Address: 0x288f48, Func Offset: 0x6d8
	// Line 617, Address: 0x288f4c, Func Offset: 0x6dc
	// Line 618, Address: 0x288f68, Func Offset: 0x6f8
	// Line 617, Address: 0x288f6c, Func Offset: 0x6fc
	// Line 618, Address: 0x288f70, Func Offset: 0x700
	// Line 619, Address: 0x288f80, Func Offset: 0x710
	// Line 618, Address: 0x288f84, Func Offset: 0x714
	// Line 619, Address: 0x288f88, Func Offset: 0x718
	// Line 620, Address: 0x288fa0, Func Offset: 0x730
	// Line 619, Address: 0x288fa4, Func Offset: 0x734
	// Line 620, Address: 0x288fa8, Func Offset: 0x738
	// Line 621, Address: 0x288fc0, Func Offset: 0x750
	// Line 622, Address: 0x288fc8, Func Offset: 0x758
	// Line 623, Address: 0x288fdc, Func Offset: 0x76c
	// Line 627, Address: 0x288fe0, Func Offset: 0x770
	// Line 623, Address: 0x288fe8, Func Offset: 0x778
	// Line 624, Address: 0x289030, Func Offset: 0x7c0
	// Line 625, Address: 0x28908c, Func Offset: 0x81c
	// Line 626, Address: 0x2890e8, Func Offset: 0x878
	// Line 627, Address: 0x289108, Func Offset: 0x898
	// Line 626, Address: 0x28910c, Func Offset: 0x89c
	// Line 627, Address: 0x289110, Func Offset: 0x8a0
	// Line 628, Address: 0x289130, Func Offset: 0x8c0
	// Line 627, Address: 0x289134, Func Offset: 0x8c4
	// Line 628, Address: 0x289138, Func Offset: 0x8c8
	// Line 629, Address: 0x289154, Func Offset: 0x8e4
	// Line 628, Address: 0x289158, Func Offset: 0x8e8
	// Line 629, Address: 0x28915c, Func Offset: 0x8ec
	// Line 630, Address: 0x289184, Func Offset: 0x914
	// Line 629, Address: 0x289188, Func Offset: 0x918
	// Line 630, Address: 0x28918c, Func Offset: 0x91c
	// Line 631, Address: 0x289194, Func Offset: 0x924
	// Line 632, Address: 0x2891c4, Func Offset: 0x954
	// Line 635, Address: 0x2891e4, Func Offset: 0x974
	// Line 636, Address: 0x2891fc, Func Offset: 0x98c
	// Line 637, Address: 0x28920c, Func Offset: 0x99c
	// Line 640, Address: 0x289214, Func Offset: 0x9a4
	// Line 637, Address: 0x289220, Func Offset: 0x9b0
	// Line 638, Address: 0x28922c, Func Offset: 0x9bc
	// Line 639, Address: 0x289240, Func Offset: 0x9d0
	// Line 640, Address: 0x289250, Func Offset: 0x9e0
	// Line 641, Address: 0x289258, Func Offset: 0x9e8
	// Line 642, Address: 0x289264, Func Offset: 0x9f4
	// Line 641, Address: 0x289268, Func Offset: 0x9f8
	// Line 642, Address: 0x28926c, Func Offset: 0x9fc
	// Line 643, Address: 0x289278, Func Offset: 0xa08
	// Line 642, Address: 0x28927c, Func Offset: 0xa0c
	// Line 643, Address: 0x289284, Func Offset: 0xa14
	// Line 644, Address: 0x289288, Func Offset: 0xa18
	// Line 645, Address: 0x289290, Func Offset: 0xa20
	// Line 648, Address: 0x289298, Func Offset: 0xa28
	// Line 650, Address: 0x2892a8, Func Offset: 0xa38
	// Line 652, Address: 0x2892b4, Func Offset: 0xa44
	// Line 650, Address: 0x2892b8, Func Offset: 0xa48
	// Line 652, Address: 0x2892c0, Func Offset: 0xa50
	// Line 653, Address: 0x2892c8, Func Offset: 0xa58
	// Line 652, Address: 0x2892cc, Func Offset: 0xa5c
	// Line 653, Address: 0x2892d0, Func Offset: 0xa60
	// Line 654, Address: 0x2892d8, Func Offset: 0xa68
	// Line 653, Address: 0x2892dc, Func Offset: 0xa6c
	// Line 654, Address: 0x2892e0, Func Offset: 0xa70
	// Line 655, Address: 0x2892e8, Func Offset: 0xa78
	// Line 654, Address: 0x2892ec, Func Offset: 0xa7c
	// Line 655, Address: 0x2892f0, Func Offset: 0xa80
	// Line 664, Address: 0x2892f8, Func Offset: 0xa88
	// Line 655, Address: 0x2892fc, Func Offset: 0xa8c
	// Line 664, Address: 0x289300, Func Offset: 0xa90
	// Line 670, Address: 0x289310, Func Offset: 0xaa0
	// Func End, Address: 0x28932c, Func Offset: 0xabc
}

// 
// Start address: 0x289330
void bhSetEneMdl(unsigned char* datp, _anon17* ep, int mdlno, int eno)
{
	unsigned char* emdlp;
	int mdlver;
	int dt;
	BH_PWORK* epp;
	// Line 676, Address: 0x289330, Func Offset: 0
	// Line 682, Address: 0x289358, Func Offset: 0x28
	// Line 684, Address: 0x289360, Func Offset: 0x30
	// Line 686, Address: 0x289374, Func Offset: 0x44
	// Line 688, Address: 0x28937c, Func Offset: 0x4c
	// Line 689, Address: 0x289384, Func Offset: 0x54
	// Line 690, Address: 0x28938c, Func Offset: 0x5c
	// Line 691, Address: 0x289394, Func Offset: 0x64
	// Line 693, Address: 0x289398, Func Offset: 0x68
	// Line 696, Address: 0x2893c4, Func Offset: 0x94
	// Line 698, Address: 0x2893cc, Func Offset: 0x9c
	// Line 699, Address: 0x2893dc, Func Offset: 0xac
	// Line 701, Address: 0x2893e4, Func Offset: 0xb4
	// Line 702, Address: 0x2893f4, Func Offset: 0xc4
	// Line 704, Address: 0x289400, Func Offset: 0xd0
	// Line 705, Address: 0x289418, Func Offset: 0xe8
	// Line 707, Address: 0x289424, Func Offset: 0xf4
	// Line 708, Address: 0x289428, Func Offset: 0xf8
	// Line 709, Address: 0x289440, Func Offset: 0x110
	// Line 710, Address: 0x289458, Func Offset: 0x128
	// Line 712, Address: 0x289468, Func Offset: 0x138
	// Line 710, Address: 0x289474, Func Offset: 0x144
	// Line 712, Address: 0x289478, Func Offset: 0x148
	// Line 713, Address: 0x289494, Func Offset: 0x164
	// Line 714, Address: 0x289498, Func Offset: 0x168
	// Line 713, Address: 0x28949c, Func Offset: 0x16c
	// Line 714, Address: 0x2894a4, Func Offset: 0x174
	// Line 715, Address: 0x2894c4, Func Offset: 0x194
	// Line 716, Address: 0x2894cc, Func Offset: 0x19c
	// Line 717, Address: 0x2894d4, Func Offset: 0x1a4
	// Line 716, Address: 0x2894d8, Func Offset: 0x1a8
	// Line 717, Address: 0x2894e0, Func Offset: 0x1b0
	// Line 719, Address: 0x289500, Func Offset: 0x1d0
	// Line 720, Address: 0x289508, Func Offset: 0x1d8
	// Line 721, Address: 0x289514, Func Offset: 0x1e4
	// Line 722, Address: 0x28951c, Func Offset: 0x1ec
	// Line 724, Address: 0x289544, Func Offset: 0x214
	// Line 726, Address: 0x289548, Func Offset: 0x218
	// Line 727, Address: 0x289554, Func Offset: 0x224
	// Line 731, Address: 0x289560, Func Offset: 0x230
	// Line 732, Address: 0x289568, Func Offset: 0x238
	// Line 734, Address: 0x28956c, Func Offset: 0x23c
	// Line 735, Address: 0x289580, Func Offset: 0x250
	// Line 736, Address: 0x289588, Func Offset: 0x258
	// Func End, Address: 0x2895b0, Func Offset: 0x280
}

// 
// Start address: 0x2895b0
void bhSetEneMtn(unsigned char* datp, BH_PWORK* ep, int id)
{
	unsigned char* emtnp;
	int mno;
	int sz;
	_anon4* mtnp;
	// Line 742, Address: 0x2895b0, Func Offset: 0
	// Line 747, Address: 0x2895c8, Func Offset: 0x18
	// Line 748, Address: 0x2895f0, Func Offset: 0x40
	// Line 752, Address: 0x2895f4, Func Offset: 0x44
	// Line 747, Address: 0x2895f8, Func Offset: 0x48
	// Line 748, Address: 0x289604, Func Offset: 0x54
	// Line 749, Address: 0x289618, Func Offset: 0x68
	// Line 751, Address: 0x28961c, Func Offset: 0x6c
	// Line 749, Address: 0x289620, Func Offset: 0x70
	// Line 751, Address: 0x289624, Func Offset: 0x74
	// Line 750, Address: 0x289628, Func Offset: 0x78
	// Line 751, Address: 0x28962c, Func Offset: 0x7c
	// Line 752, Address: 0x289648, Func Offset: 0x98
	// Line 753, Address: 0x289654, Func Offset: 0xa4
	// Line 755, Address: 0x289664, Func Offset: 0xb4
	// Line 753, Address: 0x289668, Func Offset: 0xb8
	// Line 757, Address: 0x289674, Func Offset: 0xc4
	// Line 758, Address: 0x28967c, Func Offset: 0xcc
	// Line 759, Address: 0x289684, Func Offset: 0xd4
	// Line 766, Address: 0x289688, Func Offset: 0xd8
	// Line 768, Address: 0x289694, Func Offset: 0xe4
	// Line 769, Address: 0x28969c, Func Offset: 0xec
	// Line 771, Address: 0x2896a0, Func Offset: 0xf0
	// Line 772, Address: 0x2896a4, Func Offset: 0xf4
	// Line 773, Address: 0x2896a8, Func Offset: 0xf8
	// Line 774, Address: 0x2896b8, Func Offset: 0x108
	// Func End, Address: 0x2896d4, Func Offset: 0x124
}

// 
// Start address: 0x2896e0
void bhSetRoomMtn(unsigned char* datp)
{
	unsigned char* emtnp;
	int mno;
	int sz;
	_anon4* mtnp;
	// Line 780, Address: 0x2896e0, Func Offset: 0
	// Line 785, Address: 0x2896f8, Func Offset: 0x18
	// Line 789, Address: 0x289708, Func Offset: 0x28
	// Line 785, Address: 0x28970c, Func Offset: 0x2c
	// Line 786, Address: 0x28971c, Func Offset: 0x3c
	// Line 785, Address: 0x289720, Func Offset: 0x40
	// Line 786, Address: 0x28972c, Func Offset: 0x4c
	// Line 787, Address: 0x289748, Func Offset: 0x68
	// Line 788, Address: 0x28975c, Func Offset: 0x7c
	// Line 789, Address: 0x289778, Func Offset: 0x98
	// Line 793, Address: 0x289794, Func Offset: 0xb4
	// Line 794, Address: 0x28979c, Func Offset: 0xbc
	// Line 795, Address: 0x2897a4, Func Offset: 0xc4
	// Line 796, Address: 0x2897a8, Func Offset: 0xc8
	// Line 798, Address: 0x2897b4, Func Offset: 0xd4
	// Line 799, Address: 0x2897bc, Func Offset: 0xdc
	// Line 801, Address: 0x2897c0, Func Offset: 0xe0
	// Line 802, Address: 0x2897c4, Func Offset: 0xe4
	// Line 803, Address: 0x2897c8, Func Offset: 0xe8
	// Line 804, Address: 0x2897d8, Func Offset: 0xf8
	// Func End, Address: 0x2897f4, Func Offset: 0x114
}

// 
// Start address: 0x289800
void bhSetObjMdl(unsigned char* datp, _anon17* ep, int eno)
{
	int sz;
	_anon0* epp;
	// Line 810, Address: 0x289800, Func Offset: 0
	// Line 814, Address: 0x289810, Func Offset: 0x10
	// Line 815, Address: 0x28982c, Func Offset: 0x2c
	// Line 817, Address: 0x28983c, Func Offset: 0x3c
	// Line 821, Address: 0x28986c, Func Offset: 0x6c
	// Line 822, Address: 0x289878, Func Offset: 0x78
	// Line 824, Address: 0x289880, Func Offset: 0x80
	// Line 825, Address: 0x289884, Func Offset: 0x84
	// Line 827, Address: 0x289888, Func Offset: 0x88
	// Line 825, Address: 0x28988c, Func Offset: 0x8c
	// Line 826, Address: 0x289890, Func Offset: 0x90
	// Line 827, Address: 0x289898, Func Offset: 0x98
	// Line 828, Address: 0x2898a0, Func Offset: 0xa0
	// Line 830, Address: 0x2898ac, Func Offset: 0xac
	// Line 832, Address: 0x2898b4, Func Offset: 0xb4
	// Func End, Address: 0x2898c8, Func Offset: 0xc8
}

// 
// Start address: 0x2898d0
void bhSetItmMdl(unsigned char* datp, _anon17* ep, int eno)
{
	_anon0* epp;
	// Line 838, Address: 0x2898d0, Func Offset: 0
	// Line 841, Address: 0x2898e0, Func Offset: 0x10
	// Line 842, Address: 0x2898fc, Func Offset: 0x2c
	// Line 843, Address: 0x28990c, Func Offset: 0x3c
	// Line 844, Address: 0x289918, Func Offset: 0x48
	// Line 846, Address: 0x289920, Func Offset: 0x50
	// Func End, Address: 0x289934, Func Offset: 0x64
}

// 
// Start address: 0x289940
void bhSetEffectTable()
{
	int i;
	_anon19* ep;
	// Line 852, Address: 0x289940, Func Offset: 0
	// Line 855, Address: 0x289954, Func Offset: 0x14
	// Line 856, Address: 0x28995c, Func Offset: 0x1c
	// Line 855, Address: 0x289960, Func Offset: 0x20
	// Line 856, Address: 0x289964, Func Offset: 0x24
	// Line 857, Address: 0x28996c, Func Offset: 0x2c
	// Line 858, Address: 0x289988, Func Offset: 0x48
	// Line 857, Address: 0x289990, Func Offset: 0x50
	// Line 858, Address: 0x28999c, Func Offset: 0x5c
	// Line 859, Address: 0x2899a8, Func Offset: 0x68
	// Line 860, Address: 0x2899c8, Func Offset: 0x88
	// Func End, Address: 0x2899e0, Func Offset: 0xa0
}

// 
// Start address: 0x2899e0
void bhSetEffectLink(_anon19* efp, int efid)
{
	_anon0* op;
	BH_PWORK* pwp;
	// Line 866, Address: 0x2899e0, Func Offset: 0
	// Line 870, Address: 0x2899e8, Func Offset: 0x8
	// Line 872, Address: 0x289a14, Func Offset: 0x34
	// Line 873, Address: 0x289a1c, Func Offset: 0x3c
	// Line 875, Address: 0x289a24, Func Offset: 0x44
	// Line 876, Address: 0x289a28, Func Offset: 0x48
	// Line 877, Address: 0x289a2c, Func Offset: 0x4c
	// Line 879, Address: 0x289a34, Func Offset: 0x54
	// Line 880, Address: 0x289a54, Func Offset: 0x74
	// Line 881, Address: 0x289a74, Func Offset: 0x94
	// Line 883, Address: 0x289a7c, Func Offset: 0x9c
	// Line 884, Address: 0x289a9c, Func Offset: 0xbc
	// Line 885, Address: 0x289ac8, Func Offset: 0xe8
	// Line 887, Address: 0x289ad0, Func Offset: 0xf0
	// Line 888, Address: 0x289af0, Func Offset: 0x110
	// Line 889, Address: 0x289b1c, Func Offset: 0x13c
	// Line 891, Address: 0x289b24, Func Offset: 0x144
	// Line 892, Address: 0x289b44, Func Offset: 0x164
	// Line 895, Address: 0x289b84, Func Offset: 0x1a4
	// Line 896, Address: 0x289b98, Func Offset: 0x1b8
	// Line 895, Address: 0x289b9c, Func Offset: 0x1bc
	// Line 896, Address: 0x289bc0, Func Offset: 0x1e0
	// Line 897, Address: 0x289bc8, Func Offset: 0x1e8
	// Line 898, Address: 0x289bd8, Func Offset: 0x1f8
	// Line 899, Address: 0x289be4, Func Offset: 0x204
	// Line 901, Address: 0x289bec, Func Offset: 0x20c
	// Line 902, Address: 0x289bf8, Func Offset: 0x218
	// Line 903, Address: 0x289bfc, Func Offset: 0x21c
	// Line 904, Address: 0x289c18, Func Offset: 0x238
	// Line 905, Address: 0x289c20, Func Offset: 0x240
	// Line 906, Address: 0x289c28, Func Offset: 0x248
	// Line 907, Address: 0x289c30, Func Offset: 0x250
	// Line 908, Address: 0x289c38, Func Offset: 0x258
	// Line 910, Address: 0x289c44, Func Offset: 0x264
	// Line 912, Address: 0x289c54, Func Offset: 0x274
	// Line 915, Address: 0x289c5c, Func Offset: 0x27c
	// Line 918, Address: 0x289c84, Func Offset: 0x2a4
	// Line 919, Address: 0x289c8c, Func Offset: 0x2ac
	// Line 920, Address: 0x289c9c, Func Offset: 0x2bc
	// Line 922, Address: 0x289ca4, Func Offset: 0x2c4
	// Func End, Address: 0x289cb0, Func Offset: 0x2d0
}

// 
// Start address: 0x289cb0
void bhSetDoorDemo(unsigned int attr, int stg_no, int rom_no, unsigned int pos_no, unsigned int dor_tp)
{
	int etmf;
	// Line 937, Address: 0x289cb0, Func Offset: 0
	// Line 939, Address: 0x289cc0, Func Offset: 0x10
	// Line 938, Address: 0x289cc4, Func Offset: 0x14
	// Line 939, Address: 0x289cc8, Func Offset: 0x18
	// Line 937, Address: 0x289ccc, Func Offset: 0x1c
	// Line 939, Address: 0x289cd4, Func Offset: 0x24
	// Line 940, Address: 0x289cdc, Func Offset: 0x2c
	// Line 941, Address: 0x289cf8, Func Offset: 0x48
	// Line 943, Address: 0x289d00, Func Offset: 0x50
	// Line 941, Address: 0x289d04, Func Offset: 0x54
	// Line 943, Address: 0x289d08, Func Offset: 0x58
	// Line 941, Address: 0x289d0c, Func Offset: 0x5c
	// Line 942, Address: 0x289d10, Func Offset: 0x60
	// Line 941, Address: 0x289d14, Func Offset: 0x64
	// Line 942, Address: 0x289d1c, Func Offset: 0x6c
	// Line 943, Address: 0x289d24, Func Offset: 0x74
	// Line 942, Address: 0x289d28, Func Offset: 0x78
	// Line 943, Address: 0x289d30, Func Offset: 0x80
	// Line 944, Address: 0x289d38, Func Offset: 0x88
	// Line 943, Address: 0x289d3c, Func Offset: 0x8c
	// Line 944, Address: 0x289d44, Func Offset: 0x94
	// Line 945, Address: 0x289d54, Func Offset: 0xa4
	// Line 946, Address: 0x289d68, Func Offset: 0xb8
	// Line 947, Address: 0x289d7c, Func Offset: 0xcc
	// Line 948, Address: 0x289d90, Func Offset: 0xe0
	// Line 949, Address: 0x289da4, Func Offset: 0xf4
	// Line 951, Address: 0x289db8, Func Offset: 0x108
	// Line 952, Address: 0x289de4, Func Offset: 0x134
	// Line 953, Address: 0x289dec, Func Offset: 0x13c
	// Line 952, Address: 0x289df4, Func Offset: 0x144
	// Line 953, Address: 0x289dfc, Func Offset: 0x14c
	// Line 954, Address: 0x289e24, Func Offset: 0x174
	// Line 955, Address: 0x289e44, Func Offset: 0x194
	// Line 956, Address: 0x289e50, Func Offset: 0x1a0
	// Line 955, Address: 0x289e5c, Func Offset: 0x1ac
	// Line 956, Address: 0x289e64, Func Offset: 0x1b4
	// Line 957, Address: 0x289e6c, Func Offset: 0x1bc
	// Line 956, Address: 0x289e70, Func Offset: 0x1c0
	// Line 957, Address: 0x289e78, Func Offset: 0x1c8
	// Line 960, Address: 0x289e88, Func Offset: 0x1d8
	// Func End, Address: 0x289e90, Func Offset: 0x1e0
}

// 
// Start address: 0x289e90
void bhStartDoorDemo()
{
	int etmf;
	_anon18* ddp;
	// Line 966, Address: 0x289e90, Func Offset: 0
	// Line 967, Address: 0x289e9c, Func Offset: 0xc
	// Line 969, Address: 0x289ea4, Func Offset: 0x14
	// Line 967, Address: 0x289ea8, Func Offset: 0x18
	// Line 969, Address: 0x289eb4, Func Offset: 0x24
	// Line 972, Address: 0x289ed8, Func Offset: 0x48
	// Line 974, Address: 0x289ee8, Func Offset: 0x58
	// Line 976, Address: 0x289ef0, Func Offset: 0x60
	// Line 981, Address: 0x289ef8, Func Offset: 0x68
	// Line 982, Address: 0x289efc, Func Offset: 0x6c
	// Line 984, Address: 0x289f00, Func Offset: 0x70
	// Line 976, Address: 0x289f04, Func Offset: 0x74
	// Line 977, Address: 0x289f14, Func Offset: 0x84
	// Line 978, Address: 0x289f28, Func Offset: 0x98
	// Line 979, Address: 0x289f3c, Func Offset: 0xac
	// Line 980, Address: 0x289f50, Func Offset: 0xc0
	// Line 981, Address: 0x289f64, Func Offset: 0xd4
	// Line 982, Address: 0x289f70, Func Offset: 0xe0
	// Line 981, Address: 0x289f74, Func Offset: 0xe4
	// Line 982, Address: 0x289f7c, Func Offset: 0xec
	// Line 984, Address: 0x289f84, Func Offset: 0xf4
	// Line 982, Address: 0x289f88, Func Offset: 0xf8
	// Line 984, Address: 0x289f90, Func Offset: 0x100
	// Line 986, Address: 0x289f98, Func Offset: 0x108
	// Line 985, Address: 0x289f9c, Func Offset: 0x10c
	// Line 986, Address: 0x289fa0, Func Offset: 0x110
	// Line 984, Address: 0x289fa4, Func Offset: 0x114
	// Line 986, Address: 0x289fac, Func Offset: 0x11c
	// Line 987, Address: 0x289fb4, Func Offset: 0x124
	// Line 988, Address: 0x289fd0, Func Offset: 0x140
	// Line 1007, Address: 0x289fd8, Func Offset: 0x148
	// Line 1009, Address: 0x289fdc, Func Offset: 0x14c
	// Line 988, Address: 0x289fe0, Func Offset: 0x150
	// Line 989, Address: 0x28a000, Func Offset: 0x170
	// Line 990, Address: 0x28a020, Func Offset: 0x190
	// Line 991, Address: 0x28a02c, Func Offset: 0x19c
	// Line 992, Address: 0x28a038, Func Offset: 0x1a8
	// Line 991, Address: 0x28a03c, Func Offset: 0x1ac
	// Line 992, Address: 0x28a040, Func Offset: 0x1b0
	// Line 993, Address: 0x28a048, Func Offset: 0x1b8
	// Line 992, Address: 0x28a04c, Func Offset: 0x1bc
	// Line 993, Address: 0x28a050, Func Offset: 0x1c0
	// Line 1007, Address: 0x28a058, Func Offset: 0x1c8
	// Line 993, Address: 0x28a05c, Func Offset: 0x1cc
	// Line 1007, Address: 0x28a060, Func Offset: 0x1d0
	// Line 1009, Address: 0x28a074, Func Offset: 0x1e4
	// Line 1010, Address: 0x28a084, Func Offset: 0x1f4
	// Line 1012, Address: 0x28a08c, Func Offset: 0x1fc
	// Line 1024, Address: 0x28a09c, Func Offset: 0x20c
	// Line 1025, Address: 0x28a0ac, Func Offset: 0x21c
	// Line 1027, Address: 0x28a0b4, Func Offset: 0x224
	// Line 1028, Address: 0x28a0b8, Func Offset: 0x228
	// Line 1029, Address: 0x28a0bc, Func Offset: 0x22c
	// Line 1025, Address: 0x28a0c0, Func Offset: 0x230
	// Line 1027, Address: 0x28a0cc, Func Offset: 0x23c
	// Line 1028, Address: 0x28a0d8, Func Offset: 0x248
	// Line 1027, Address: 0x28a0dc, Func Offset: 0x24c
	// Line 1028, Address: 0x28a0e4, Func Offset: 0x254
	// Line 1029, Address: 0x28a0e8, Func Offset: 0x258
	// Line 1033, Address: 0x28a0f0, Func Offset: 0x260
	// Func End, Address: 0x28a100, Func Offset: 0x270
}

// 
// Start address: 0x28a100
void bhPushGameData()
{
	// Line 1061, Address: 0x28a100, Func Offset: 0
	// Line 1070, Address: 0x28a10c, Func Offset: 0xc
	// Line 1061, Address: 0x28a110, Func Offset: 0x10
	// Line 1062, Address: 0x28a114, Func Offset: 0x14
	// Line 1070, Address: 0x28a128, Func Offset: 0x28
	// Line 1062, Address: 0x28a12c, Func Offset: 0x2c
	// Line 1070, Address: 0x28a130, Func Offset: 0x30
	// Line 1071, Address: 0x28a140, Func Offset: 0x40
	// Line 1070, Address: 0x28a144, Func Offset: 0x44
	// Line 1071, Address: 0x28a158, Func Offset: 0x58
	// Line 1072, Address: 0x28a168, Func Offset: 0x68
	// Line 1071, Address: 0x28a16c, Func Offset: 0x6c
	// Line 1072, Address: 0x28a170, Func Offset: 0x70
	// Line 1073, Address: 0x28a180, Func Offset: 0x80
	// Line 1072, Address: 0x28a184, Func Offset: 0x84
	// Line 1073, Address: 0x28a188, Func Offset: 0x88
	// Line 1074, Address: 0x28a198, Func Offset: 0x98
	// Line 1073, Address: 0x28a19c, Func Offset: 0x9c
	// Line 1074, Address: 0x28a1a0, Func Offset: 0xa0
	// Line 1075, Address: 0x28a1b0, Func Offset: 0xb0
	// Line 1074, Address: 0x28a1b4, Func Offset: 0xb4
	// Line 1075, Address: 0x28a1b8, Func Offset: 0xb8
	// Line 1076, Address: 0x28a1c8, Func Offset: 0xc8
	// Line 1075, Address: 0x28a1cc, Func Offset: 0xcc
	// Line 1076, Address: 0x28a1d8, Func Offset: 0xd8
	// Line 1079, Address: 0x28a1e8, Func Offset: 0xe8
	// Line 1076, Address: 0x28a1ec, Func Offset: 0xec
	// Line 1079, Address: 0x28a1fc, Func Offset: 0xfc
	// Func End, Address: 0x28a218, Func Offset: 0x118
}

// 
// Start address: 0x28a220
void bhPopGameData()
{
	// Line 1089, Address: 0x28a220, Func Offset: 0
	// Line 1093, Address: 0x28a228, Func Offset: 0x8
	// Line 1094, Address: 0x28a23c, Func Offset: 0x1c
	// Line 1096, Address: 0x28a244, Func Offset: 0x24
	// Line 1098, Address: 0x28a264, Func Offset: 0x44
	// Line 1099, Address: 0x28a28c, Func Offset: 0x6c
	// Line 1101, Address: 0x28a294, Func Offset: 0x74
	// Line 1104, Address: 0x28a29c, Func Offset: 0x7c
	// Line 1099, Address: 0x28a2a4, Func Offset: 0x84
	// Line 1100, Address: 0x28a2a8, Func Offset: 0x88
	// Line 1099, Address: 0x28a2ac, Func Offset: 0x8c
	// Line 1100, Address: 0x28a2b4, Func Offset: 0x94
	// Line 1101, Address: 0x28a2bc, Func Offset: 0x9c
	// Line 1100, Address: 0x28a2c0, Func Offset: 0xa0
	// Line 1101, Address: 0x28a2c8, Func Offset: 0xa8
	// Line 1102, Address: 0x28a2d0, Func Offset: 0xb0
	// Line 1104, Address: 0x28a2dc, Func Offset: 0xbc
	// Line 1105, Address: 0x28a2f0, Func Offset: 0xd0
	// Func End, Address: 0x28a2fc, Func Offset: 0xdc
}

