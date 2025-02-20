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

typedef void(*type_79)(void*);

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
typedef float type_13[32];
typedef _anon0* type_14[512];
typedef _anon1* type_15[200];
typedef short type_16[32];
typedef _anon27 type_17[1];
typedef _anon0* type_18[128];
typedef unsigned int type_19[1];
typedef _anon7 type_20[256];
typedef _anon1* type_21[8];
typedef int* type_22[16];
typedef _anon0* type_23[128];
typedef _anon47 type_24[16];
typedef npobj* type_25[16];
typedef _anon0* type_26[128];
typedef int type_27[4];
typedef _anon1* type_28[16];
typedef unsigned int type_29[4];
typedef float type_30[4];
typedef _anon12 type_31[16];
typedef _anon0* type_32[512];
typedef float type_33[4];
typedef char type_34[256];
typedef float type_35[4];
typedef float type_36[4];
typedef float type_37[4];
typedef float type_38[4];
typedef _anon4* type_39[128];
typedef unsigned char type_40[64];
typedef float type_41[16];
typedef char type_42[8];
typedef void* type_43[2];
typedef _anon24 type_44[31];
typedef _anon1* type_45[256];
typedef int type_46[4];
typedef unsigned char* type_47[256];
typedef unsigned int type_48[2];
typedef short type_49[256];
typedef _anon33 type_50[4];
typedef float type_51[3];
typedef short type_52[256];
typedef int type_53[3];
typedef int type_54[8];
typedef float type_55[3];
typedef BH_PWORK type_56[0];
typedef _anon1* type_57[256];
typedef _anon9 type_58[256];
typedef _anon0 type_59[0];
typedef _anon27 type_60[450];
typedef _anon35 type_61[16];
typedef short type_62[256];
typedef char type_63[3];
typedef int type_64[64];
typedef _anon12 type_65[450];
typedef unsigned int type_66[16];
typedef char type_67[4];
typedef unsigned int type_68[8];
typedef _anon38 type_69[4];
typedef _anon2 type_70[4];
typedef int type_71[450];
typedef unsigned int type_72[8];
typedef unsigned char type_73[450];
typedef float type_74[128];
typedef float type_75[5];
typedef int type_76[5];
typedef char type_77[16];
typedef char type_78[4];
typedef _anon25 type_80[2];
typedef unsigned int type_81[32];
typedef unsigned char type_82[256];
typedef unsigned int type_83[16];
typedef unsigned int type_84[2];
typedef unsigned int type_85[2][4];
typedef _anon21 type_86[64];
typedef unsigned int type_87[16];
typedef _anon21 type_88[64];
typedef unsigned int type_89[32];
typedef _anon21 type_90[64];
typedef unsigned int type_91[16];
typedef unsigned int type_92[3];
typedef BH_PWORK* type_93[16];
typedef unsigned int type_94[8];
typedef unsigned int type_95[1];
typedef unsigned int type_96[384];
typedef unsigned int type_97[2];
typedef int type_98[3];
typedef unsigned char type_99[2];
typedef int* type_100[16];
typedef unsigned int type_101[4];
typedef char type_102[32];
typedef npobj* type_103[16];
typedef char type_104[64];
typedef _anon1* type_105[16];
typedef char type_106[4];
typedef _anon12 type_107[16];
typedef short type_108[4];
typedef unsigned char type_109[4];
typedef _anon36 type_110[16];
typedef unsigned int type_111[8];
typedef unsigned int type_112[32];
typedef unsigned int type_113[4];
typedef _anon6 type_114[32];
typedef _anon0* type_115[512];
typedef _anon0* type_116[128];
typedef _anon0* type_117[512];
typedef unsigned char type_118[64];
typedef _anon0* type_119[512];

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
	_anon1* txp[16];
	_anon12 mdl[16];
	_anon12* mlwP;
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
	_anon45 cspr;
	int pn;
	_anon38* pvp;
	_anon2* tvp;
	_anon38 pv[4];
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
	_anon27* textures;
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
	_anon12 mdl[16];
	_anon12* mlwP;
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
	_anon46 watr;
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

struct _anon4
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon26* md2P;
	unsigned short* atrP;
};

struct _anon5
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon47 keyf[16];
};

struct _anon6
{
	float x;
	float y;
	float z;
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

struct _anon9
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon10
{
	_anon11* cutp;
	_anon15* lgtp;
	_anon16* enep;
	_anon16* objp;
	_anon16* itmp;
	_anon19* effp;
	_anon21* walp;
	_anon21* etcp;
	_anon21* flrp;
	_anon3* posp;
	_anon21* rutp;
	unsigned char* ruttp;
	_anon29* evtp;
	_anon5* evcp;
	unsigned int* mesp;
	_anon15* evlp;
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
	_anon12 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};

struct _anon11
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon14* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon25 cam[2];
	unsigned char exd[256];
};

struct _anon12
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon31* owP;
};

struct _anon13
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
	_anon43* info;
};

struct _anon14
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
	_anon32* light;
};

struct _anon16
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
	int crit;
	int pt[3];
	int timeout;
	int bonus;
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
	int flg;
	int correct;
};

struct _anon21
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

struct _anon22
{
	void* texaddr;
	_anon8 texsurface;
};

struct _anon23
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
	_anon6 ply_pos;
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
	_anon13* p1per;
	_anon13* p2per;
	_anon13* kbper;
	_anon13* msper;
	_anon13 ms_per;
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
	_anon9 txbp[256];
	unsigned char* ef_psp;
	_anon27 ef_tex[450];
	_anon1 ef_tlist;
	_anon41 ef;
	short efid[256];
	_anon12 efm[450];
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
	_anon22 ren_info;
	_anon27 ren_tex[1];
	_anon1 ren_tlist;
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
	_anon42 mr_pl;
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
	_anon21* pl_htp;
	int costume;
	_anon6 hd_pos;
	_anon6 apos;
	_anon21* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon21 mwalp[64];
	_anon21 metcp[64];
	_anon21 mflrp[64];
	int dla_n;
	_anon21* htp;
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
	_anon6 ufo_pos;
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
	_anon6 ghtp[32];
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

struct _anon24
{
	unsigned char color;
	unsigned char mdlno;
	unsigned char tex_id;
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
	_anon6 pnt;
	_anon6 vctr;
	int stat;
	int reserve;
	_anon37 ltcal;
	_anon44 attr;
};

struct _anon33
{
	_anon6 ps;
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
	_anon6 center;
	float r;
};

struct _anon35
{
	float x;
	float y;
};

struct _anon36
{
	_anon6 c1;
	_anon6 c2;
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
	_anon6 lpnt;
	_anon6 lvctr;
	_anon6 lmvctr;
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
	_anon6 off_pos;
	int srd_dir;
	float srd_pos;
	float bld_spd;
	float srt_spd[5];
	int srt_dir[5];
};

struct _anon40
{
	int key;
	float cnt;
};

struct _anon41
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

struct _anon42
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon43
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
	_anon6 c;
	float r;
};

struct _anon46
{
	_anon6 c1;
	_anon6 c2;
	float r;
};

struct _anon47
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

_anon24 BloodType[31];
unsigned int BloodCol[2][4];
_anon0 eff[0];
_anon23* sys;
BH_PWORK* plp;
BH_PWORK ene[0];
_anon10* rom;

void bhEne_SetMinceEffect(BH_PWORK* epw, int type, int num);
void bhEne_SetMinceEffect2(BH_PWORK* epw, int type, float size, int num);
void bhEne_SetBloodEffect(BH_PWORK* epw, int type);
void bhEne_SetBloodEffect2(BH_PWORK* epw, int type, int jno, _anon6* ofp);
void bhEne_SetBloodEffect4(_anon6* pos, _anon6* vec, int col, int type1, int type2);
void bhEne_SetBloodEffect5(BH_PWORK* epw, int type1, int type2);
void bhEne_SetBloodEffectBurst(BH_PWORK* epw, int type, int jno, _anon6* pos, int flg);
void bhEne_SetBloodstain(BH_PWORK* epw, int type, int jno, _anon6* ofp);
void bhEne_SetFireEffect(BH_PWORK* epw, int jno, _anon6* ofp, float size, int len);
void bhEne_BloodPool(BH_PWORK* epw, _anon6* pos, int ang, _anon39* param);
void bhEne_SetAcidEffect(BH_PWORK* epw, int jno, _anon6* ofp, float size);
int bhEne_DirTarget(BH_PWORK* epw, float x, float z, int w);
int bhEne_CheckDirTarget(BH_PWORK* epw, float x, float z, int w);
void bhEne_GetPartsPos(BH_PWORK* epw, char* parts, _anon6* p);
int bhEne_DirCheck(int ay, _anon6* vec);
int bhEne_DGDirCheck(BH_PWORK* epw);
void bhEne_CallPlayerVoice(int no);
void bhEne_CheckEnemiesBall(BH_PWORK* epw);
void bhEne_SetWeponAtr(BH_PWORK* epw, char j1, char j2, float r);
unsigned char bhEne_AttackHitCheck(BH_PWORK* pl, _anon6* pos, float ar);
void bhEne_AddNullTrans(BH_PWORK* epw, _anon6* mtn);
void bhEne_AddNullTransDir(BH_PWORK* epw, int ay, _anon6* mtn);
float bhEne_GetShapeCnt(_anon40* p, int key);
void bhEne_CalcDamage(BH_PWORK* epw, _anon18* CombWepTbl, _anon20* CombJointTbl);
void bhEne_InitDamage(BH_PWORK* epw);
void bhEne_CallSE(BH_PWORK* epw, _anon6* pos, int se);
void bhEne_CallSE_EX(BH_PWORK* epw, _anon6* pos, int se, int fade);
void bhEne_CallEffectSE(_anon6* pos, int se);
void bhEne_SetSEPan(_anon6* pos, int se);
int bhEne_CheckPlayEffectSE(int se);
int bhArcTan2(float y, float x);
_anon21* bhEne_CheckEventAtr(int flr_no, float px, float pz, int id, int min, int max);
void bhEne_EraseArrow(BH_PWORK* epw, int obj_no);

// 
// Start address: 0x218d10
void bhEne_SetMinceEffect(BH_PWORK* epw, int type, int num)
{
	float size;
	int dam_ang;
	int i;
	int eno;
	// Line 105, Address: 0x218d10, Func Offset: 0
	// Line 110, Address: 0x218d28, Func Offset: 0x18
	// Line 111, Address: 0x218d38, Func Offset: 0x28
	// Line 110, Address: 0x218d3c, Func Offset: 0x2c
	// Line 111, Address: 0x218d48, Func Offset: 0x38
	// Line 112, Address: 0x218d60, Func Offset: 0x50
	// Line 113, Address: 0x218d74, Func Offset: 0x64
	// Line 114, Address: 0x218d8c, Func Offset: 0x7c
	// Line 115, Address: 0x218da4, Func Offset: 0x94
	// Line 116, Address: 0x218db8, Func Offset: 0xa8
	// Line 117, Address: 0x218dd8, Func Offset: 0xc8
	// Line 116, Address: 0x218de0, Func Offset: 0xd0
	// Line 120, Address: 0x218df0, Func Offset: 0xe0
	// Line 117, Address: 0x218df4, Func Offset: 0xe4
	// Line 116, Address: 0x218dfc, Func Offset: 0xec
	// Line 120, Address: 0x218e08, Func Offset: 0xf8
	// Line 116, Address: 0x218e0c, Func Offset: 0xfc
	// Line 117, Address: 0x218e18, Func Offset: 0x108
	// Line 118, Address: 0x218e1c, Func Offset: 0x10c
	// Line 119, Address: 0x218e30, Func Offset: 0x120
	// Line 120, Address: 0x218e44, Func Offset: 0x134
	// Line 122, Address: 0x218e6c, Func Offset: 0x15c
	// Line 123, Address: 0x218e90, Func Offset: 0x180
	// Line 122, Address: 0x218e94, Func Offset: 0x184
	// Line 123, Address: 0x218e98, Func Offset: 0x188
	// Line 126, Address: 0x218ea0, Func Offset: 0x190
	// Line 131, Address: 0x218ef4, Func Offset: 0x1e4
	// Line 126, Address: 0x218f00, Func Offset: 0x1f0
	// Line 131, Address: 0x218f0c, Func Offset: 0x1fc
	// Line 132, Address: 0x218f24, Func Offset: 0x214
	// Line 133, Address: 0x218f30, Func Offset: 0x220
	// Line 134, Address: 0x218f54, Func Offset: 0x244
	// Line 135, Address: 0x218f5c, Func Offset: 0x24c
	// Line 133, Address: 0x218f64, Func Offset: 0x254
	// Line 134, Address: 0x218f6c, Func Offset: 0x25c
	// Line 135, Address: 0x218f98, Func Offset: 0x288
	// Line 137, Address: 0x218fb0, Func Offset: 0x2a0
	// Line 138, Address: 0x218fc0, Func Offset: 0x2b0
	// Func End, Address: 0x218fdc, Func Offset: 0x2cc
}

// 
// Start address: 0x218fe0
void bhEne_SetMinceEffect2(BH_PWORK* epw, int type, float size, int num)
{
	int dam_ang;
	int i;
	int eno;
	// Line 151, Address: 0x218fe0, Func Offset: 0
	// Line 155, Address: 0x218ff8, Func Offset: 0x18
	// Line 164, Address: 0x219000, Func Offset: 0x20
	// Line 155, Address: 0x219008, Func Offset: 0x28
	// Line 164, Address: 0x21900c, Func Offset: 0x2c
	// Line 155, Address: 0x219010, Func Offset: 0x30
	// Line 156, Address: 0x21901c, Func Offset: 0x3c
	// Line 157, Address: 0x219038, Func Offset: 0x58
	// Line 158, Address: 0x21904c, Func Offset: 0x6c
	// Line 159, Address: 0x219064, Func Offset: 0x84
	// Line 160, Address: 0x21907c, Func Offset: 0x9c
	// Line 161, Address: 0x219094, Func Offset: 0xb4
	// Line 162, Address: 0x2190a8, Func Offset: 0xc8
	// Line 163, Address: 0x2190bc, Func Offset: 0xdc
	// Line 164, Address: 0x2190d0, Func Offset: 0xf0
	// Line 166, Address: 0x2190f8, Func Offset: 0x118
	// Line 167, Address: 0x21911c, Func Offset: 0x13c
	// Line 166, Address: 0x219120, Func Offset: 0x140
	// Line 167, Address: 0x219124, Func Offset: 0x144
	// Line 170, Address: 0x21912c, Func Offset: 0x14c
	// Line 175, Address: 0x219180, Func Offset: 0x1a0
	// Line 170, Address: 0x21918c, Func Offset: 0x1ac
	// Line 175, Address: 0x219198, Func Offset: 0x1b8
	// Line 176, Address: 0x2191b0, Func Offset: 0x1d0
	// Line 177, Address: 0x2191bc, Func Offset: 0x1dc
	// Line 178, Address: 0x2191e0, Func Offset: 0x200
	// Line 179, Address: 0x2191e8, Func Offset: 0x208
	// Line 177, Address: 0x2191f0, Func Offset: 0x210
	// Line 178, Address: 0x2191f8, Func Offset: 0x218
	// Line 179, Address: 0x219224, Func Offset: 0x244
	// Line 180, Address: 0x21923c, Func Offset: 0x25c
	// Line 181, Address: 0x219240, Func Offset: 0x260
	// Line 182, Address: 0x219250, Func Offset: 0x270
	// Func End, Address: 0x21926c, Func Offset: 0x28c
}

// 
// Start address: 0x219270
void bhEne_SetBloodEffect(BH_PWORK* epw, int type)
{
	// Line 195, Address: 0x219274, Func Offset: 0x4
	// Func End, Address: 0x21927c, Func Offset: 0xc
}

// 
// Start address: 0x219280
void bhEne_SetBloodEffect2(BH_PWORK* epw, int type, int jno, _anon6* ofp)
{
	_anon6 vec;
	_anon6 org;
	// Line 209, Address: 0x219280, Func Offset: 0
	// Line 210, Address: 0x21929c, Func Offset: 0x1c
	// Line 214, Address: 0x2192c0, Func Offset: 0x40
	// Line 217, Address: 0x2192cc, Func Offset: 0x4c
	// Line 220, Address: 0x2192d0, Func Offset: 0x50
	// Line 217, Address: 0x2192e0, Func Offset: 0x60
	// Line 218, Address: 0x2192e8, Func Offset: 0x68
	// Line 220, Address: 0x2192ec, Func Offset: 0x6c
	// Line 218, Address: 0x2192f8, Func Offset: 0x78
	// Line 219, Address: 0x219300, Func Offset: 0x80
	// Line 220, Address: 0x219304, Func Offset: 0x84
	// Line 219, Address: 0x219310, Func Offset: 0x90
	// Line 220, Address: 0x219318, Func Offset: 0x98
	// Line 223, Address: 0x219348, Func Offset: 0xc8
	// Line 225, Address: 0x219350, Func Offset: 0xd0
	// Line 239, Address: 0x219358, Func Offset: 0xd8
	// Line 223, Address: 0x21935c, Func Offset: 0xdc
	// Line 239, Address: 0x21936c, Func Offset: 0xec
	// Line 224, Address: 0x219370, Func Offset: 0xf0
	// Line 225, Address: 0x21937c, Func Offset: 0xfc
	// Line 235, Address: 0x219380, Func Offset: 0x100
	// Line 241, Address: 0x219384, Func Offset: 0x104
	// Line 224, Address: 0x219388, Func Offset: 0x108
	// Line 225, Address: 0x219394, Func Offset: 0x114
	// Line 241, Address: 0x21939c, Func Offset: 0x11c
	// Line 225, Address: 0x2193a4, Func Offset: 0x124
	// Line 227, Address: 0x2193b0, Func Offset: 0x130
	// Line 235, Address: 0x2193ec, Func Offset: 0x16c
	// Line 236, Address: 0x219400, Func Offset: 0x180
	// Line 237, Address: 0x219414, Func Offset: 0x194
	// Line 238, Address: 0x219428, Func Offset: 0x1a8
	// Line 239, Address: 0x21943c, Func Offset: 0x1bc
	// Line 241, Address: 0x219464, Func Offset: 0x1e4
	// Line 245, Address: 0x21947c, Func Offset: 0x1fc
	// Func End, Address: 0x219498, Func Offset: 0x218
}

// 
// Start address: 0x2194a0
void bhEne_SetBloodEffect4(_anon6* pos, _anon6* vec, int col, int type1, int type2)
{
	// Line 259, Address: 0x2194a0, Func Offset: 0
	// Line 261, Address: 0x2194b0, Func Offset: 0x10
	// Line 259, Address: 0x2194b4, Func Offset: 0x14
	// Line 261, Address: 0x2194b8, Func Offset: 0x18
	// Line 264, Address: 0x2194fc, Func Offset: 0x5c
	// Line 265, Address: 0x219508, Func Offset: 0x68
	// Line 266, Address: 0x21950c, Func Offset: 0x6c
	// Line 264, Address: 0x219510, Func Offset: 0x70
	// Line 265, Address: 0x21951c, Func Offset: 0x7c
	// Line 271, Address: 0x219524, Func Offset: 0x84
	// Line 275, Address: 0x219528, Func Offset: 0x88
	// Line 265, Address: 0x219534, Func Offset: 0x94
	// Line 266, Address: 0x219540, Func Offset: 0xa0
	// Line 267, Address: 0x219554, Func Offset: 0xb4
	// Line 268, Address: 0x219568, Func Offset: 0xc8
	// Line 269, Address: 0x219580, Func Offset: 0xe0
	// Line 270, Address: 0x219598, Func Offset: 0xf8
	// Line 271, Address: 0x2195b0, Func Offset: 0x110
	// Line 272, Address: 0x2195c4, Func Offset: 0x124
	// Line 273, Address: 0x2195d8, Func Offset: 0x138
	// Line 274, Address: 0x2195ec, Func Offset: 0x14c
	// Line 275, Address: 0x219600, Func Offset: 0x160
	// Line 279, Address: 0x219618, Func Offset: 0x178
	// Func End, Address: 0x219630, Func Offset: 0x190
}

// 
// Start address: 0x219630
void bhEne_SetBloodEffect5(BH_PWORK* epw, int type1, int type2)
{
	_anon6 vec;
	_anon6 ofp;
	// Line 291, Address: 0x219630, Func Offset: 0
	// Line 296, Address: 0x219644, Func Offset: 0x14
	// Line 297, Address: 0x21967c, Func Offset: 0x4c
	// Line 298, Address: 0x2196a8, Func Offset: 0x78
	// Line 300, Address: 0x2196d4, Func Offset: 0xa4
	// Line 301, Address: 0x2196fc, Func Offset: 0xcc
	// Line 302, Address: 0x219704, Func Offset: 0xd4
	// Line 305, Address: 0x219714, Func Offset: 0xe4
	// Line 308, Address: 0x219718, Func Offset: 0xe8
	// Line 305, Address: 0x219728, Func Offset: 0xf8
	// Line 306, Address: 0x219730, Func Offset: 0x100
	// Line 308, Address: 0x219734, Func Offset: 0x104
	// Line 306, Address: 0x219740, Func Offset: 0x110
	// Line 307, Address: 0x219748, Func Offset: 0x118
	// Line 308, Address: 0x21974c, Func Offset: 0x11c
	// Line 307, Address: 0x219754, Func Offset: 0x124
	// Line 308, Address: 0x21975c, Func Offset: 0x12c
	// Line 311, Address: 0x219790, Func Offset: 0x160
	// Line 327, Address: 0x219798, Func Offset: 0x168
	// Line 311, Address: 0x21979c, Func Offset: 0x16c
	// Line 327, Address: 0x2197a0, Func Offset: 0x170
	// Line 311, Address: 0x2197a4, Func Offset: 0x174
	// Line 312, Address: 0x2197b0, Func Offset: 0x180
	// Line 323, Address: 0x2197bc, Func Offset: 0x18c
	// Line 330, Address: 0x2197c0, Func Offset: 0x190
	// Line 312, Address: 0x2197c4, Func Offset: 0x194
	// Line 313, Address: 0x2197d0, Func Offset: 0x1a0
	// Line 330, Address: 0x2197d8, Func Offset: 0x1a8
	// Line 313, Address: 0x2197dc, Func Offset: 0x1ac
	// Line 315, Address: 0x2197e8, Func Offset: 0x1b8
	// Line 323, Address: 0x219824, Func Offset: 0x1f4
	// Line 324, Address: 0x219838, Func Offset: 0x208
	// Line 325, Address: 0x21984c, Func Offset: 0x21c
	// Line 326, Address: 0x219860, Func Offset: 0x230
	// Line 327, Address: 0x219874, Func Offset: 0x244
	// Line 330, Address: 0x21989c, Func Offset: 0x26c
	// Line 334, Address: 0x2198b8, Func Offset: 0x288
	// Func End, Address: 0x2198d0, Func Offset: 0x2a0
}

// 
// Start address: 0x2198d0
void bhEne_SetBloodEffectBurst(BH_PWORK* epw, int type, int jno, _anon6* pos, int flg)
{
	_anon6 ofp;
	_anon0* op;
	int eno;
	// Line 349, Address: 0x2198d0, Func Offset: 0
	// Line 354, Address: 0x2198f0, Func Offset: 0x20
	// Line 357, Address: 0x2198f8, Func Offset: 0x28
	// Line 365, Address: 0x219900, Func Offset: 0x30
	// Line 367, Address: 0x219908, Func Offset: 0x38
	// Line 371, Address: 0x219924, Func Offset: 0x54
	// Line 372, Address: 0x21992c, Func Offset: 0x5c
	// Line 373, Address: 0x219950, Func Offset: 0x80
	// Line 374, Address: 0x219968, Func Offset: 0x98
	// Line 375, Address: 0x219970, Func Offset: 0xa0
	// Line 378, Address: 0x219980, Func Offset: 0xb0
	// Line 394, Address: 0x219988, Func Offset: 0xb8
	// Line 378, Address: 0x21998c, Func Offset: 0xbc
	// Line 394, Address: 0x219990, Func Offset: 0xc0
	// Line 378, Address: 0x219994, Func Offset: 0xc4
	// Line 379, Address: 0x2199a0, Func Offset: 0xd0
	// Line 390, Address: 0x2199ac, Func Offset: 0xdc
	// Line 396, Address: 0x2199b0, Func Offset: 0xe0
	// Line 379, Address: 0x2199b4, Func Offset: 0xe4
	// Line 380, Address: 0x2199c0, Func Offset: 0xf0
	// Line 396, Address: 0x2199c8, Func Offset: 0xf8
	// Line 380, Address: 0x2199d0, Func Offset: 0x100
	// Line 382, Address: 0x2199dc, Func Offset: 0x10c
	// Line 390, Address: 0x219a18, Func Offset: 0x148
	// Line 391, Address: 0x219a2c, Func Offset: 0x15c
	// Line 392, Address: 0x219a40, Func Offset: 0x170
	// Line 393, Address: 0x219a54, Func Offset: 0x184
	// Line 394, Address: 0x219a68, Func Offset: 0x198
	// Line 396, Address: 0x219a90, Func Offset: 0x1c0
	// Line 397, Address: 0x219aa8, Func Offset: 0x1d8
	// Line 398, Address: 0x219ab4, Func Offset: 0x1e4
	// Line 399, Address: 0x219abc, Func Offset: 0x1ec
	// Line 398, Address: 0x219ac0, Func Offset: 0x1f0
	// Line 399, Address: 0x219ad4, Func Offset: 0x204
	// Line 398, Address: 0x219ad8, Func Offset: 0x208
	// Line 399, Address: 0x219adc, Func Offset: 0x20c
	// Line 400, Address: 0x219ae0, Func Offset: 0x210
	// Line 401, Address: 0x219aec, Func Offset: 0x21c
	// Line 403, Address: 0x219af8, Func Offset: 0x228
	// Func End, Address: 0x219b14, Func Offset: 0x244
}

// 
// Start address: 0x219b20
void bhEne_SetBloodstain(BH_PWORK* epw, int type, int jno, _anon6* ofp)
{
	float d;
	_anon6 pos;
	// Line 416, Address: 0x219b20, Func Offset: 0
	// Line 420, Address: 0x219b3c, Func Offset: 0x1c
	// Line 421, Address: 0x219b44, Func Offset: 0x24
	// Line 422, Address: 0x219b4c, Func Offset: 0x2c
	// Line 423, Address: 0x219b64, Func Offset: 0x44
	// Line 424, Address: 0x219b6c, Func Offset: 0x4c
	// Line 426, Address: 0x219b84, Func Offset: 0x64
	// Line 427, Address: 0x219b8c, Func Offset: 0x6c
	// Line 428, Address: 0x219b94, Func Offset: 0x74
	// Line 429, Address: 0x219bb8, Func Offset: 0x98
	// Line 430, Address: 0x219bc8, Func Offset: 0xa8
	// Line 431, Address: 0x219bd0, Func Offset: 0xb0
	// Line 435, Address: 0x219c04, Func Offset: 0xe4
	// Line 444, Address: 0x219c0c, Func Offset: 0xec
	// Line 435, Address: 0x219c10, Func Offset: 0xf0
	// Line 444, Address: 0x219c14, Func Offset: 0xf4
	// Line 435, Address: 0x219c18, Func Offset: 0xf8
	// Line 436, Address: 0x219c24, Func Offset: 0x104
	// Line 441, Address: 0x219c30, Func Offset: 0x110
	// Line 436, Address: 0x219c34, Func Offset: 0x114
	// Line 437, Address: 0x219c40, Func Offset: 0x120
	// Line 438, Address: 0x219c54, Func Offset: 0x134
	// Line 439, Address: 0x219c6c, Func Offset: 0x14c
	// Line 440, Address: 0x219c84, Func Offset: 0x164
	// Line 441, Address: 0x219c9c, Func Offset: 0x17c
	// Line 442, Address: 0x219cb0, Func Offset: 0x190
	// Line 443, Address: 0x219cc4, Func Offset: 0x1a4
	// Line 444, Address: 0x219cd8, Func Offset: 0x1b8
	// Line 445, Address: 0x219d00, Func Offset: 0x1e0
	// Line 446, Address: 0x219d14, Func Offset: 0x1f4
	// Line 447, Address: 0x219d34, Func Offset: 0x214
	// Line 448, Address: 0x219d50, Func Offset: 0x230
	// Line 447, Address: 0x219d5c, Func Offset: 0x23c
	// Line 448, Address: 0x219d68, Func Offset: 0x248
	// Line 449, Address: 0x219d80, Func Offset: 0x260
	// Line 450, Address: 0x219da4, Func Offset: 0x284
	// Line 451, Address: 0x219dc8, Func Offset: 0x2a8
	// Line 452, Address: 0x219dec, Func Offset: 0x2cc
	// Func End, Address: 0x219e04, Func Offset: 0x2e4
}

// 
// Start address: 0x219e10
void bhEne_SetFireEffect(BH_PWORK* epw, int jno, _anon6* ofp, float size, int len)
{
	int eno;
	_anon6 org;
	// Line 466, Address: 0x219e10, Func Offset: 0
	// Line 467, Address: 0x219e20, Func Offset: 0x10
	// Line 471, Address: 0x219e38, Func Offset: 0x28
	// Line 474, Address: 0x219e44, Func Offset: 0x34
	// Line 492, Address: 0x219e4c, Func Offset: 0x3c
	// Line 474, Address: 0x219e54, Func Offset: 0x44
	// Line 475, Address: 0x219e58, Func Offset: 0x48
	// Line 474, Address: 0x219e5c, Func Offset: 0x4c
	// Line 475, Address: 0x219e68, Func Offset: 0x58
	// Line 488, Address: 0x219e70, Func Offset: 0x60
	// Line 492, Address: 0x219e74, Func Offset: 0x64
	// Line 475, Address: 0x219e78, Func Offset: 0x68
	// Line 476, Address: 0x219e84, Func Offset: 0x74
	// Line 478, Address: 0x219e98, Func Offset: 0x88
	// Line 486, Address: 0x219ed4, Func Offset: 0xc4
	// Line 487, Address: 0x219ee8, Func Offset: 0xd8
	// Line 488, Address: 0x219efc, Func Offset: 0xec
	// Line 489, Address: 0x219f10, Func Offset: 0x100
	// Line 490, Address: 0x219f24, Func Offset: 0x114
	// Line 492, Address: 0x219f38, Func Offset: 0x128
	// Line 497, Address: 0x219f50, Func Offset: 0x140
	// Line 498, Address: 0x219f5c, Func Offset: 0x14c
	// Line 500, Address: 0x219f80, Func Offset: 0x170
	// Func End, Address: 0x219f90, Func Offset: 0x180
}

// 
// Start address: 0x219f90
void bhEne_BloodPool(BH_PWORK* epw, _anon6* pos, int ang, _anon39* param)
{
	// Line 515, Address: 0x219f90, Func Offset: 0
	// Func End, Address: 0x219fb0, Func Offset: 0x20
}

// 
// Start address: 0x219fb0
void bhEne_SetAcidEffect(BH_PWORK* epw, int jno, _anon6* ofp, float size)
{
	_anon6 org;
	// Line 529, Address: 0x219fb0, Func Offset: 0
	// Line 530, Address: 0x219fb8, Func Offset: 0x8
	// Line 529, Address: 0x219fc0, Func Offset: 0x10
	// Line 530, Address: 0x219fc4, Func Offset: 0x14
	// Line 533, Address: 0x219fd4, Func Offset: 0x24
	// Line 536, Address: 0x219fe0, Func Offset: 0x30
	// Line 537, Address: 0x219ff4, Func Offset: 0x44
	// Line 539, Address: 0x219ffc, Func Offset: 0x4c
	// Line 540, Address: 0x21a010, Func Offset: 0x60
	// Line 542, Address: 0x21a018, Func Offset: 0x68
	// Line 544, Address: 0x21a030, Func Offset: 0x80
	// Line 559, Address: 0x21a038, Func Offset: 0x88
	// Line 544, Address: 0x21a03c, Func Offset: 0x8c
	// Line 559, Address: 0x21a040, Func Offset: 0x90
	// Line 544, Address: 0x21a044, Func Offset: 0x94
	// Line 546, Address: 0x21a050, Func Offset: 0xa0
	// Line 554, Address: 0x21a08c, Func Offset: 0xdc
	// Line 555, Address: 0x21a0a0, Func Offset: 0xf0
	// Line 556, Address: 0x21a0b4, Func Offset: 0x104
	// Line 557, Address: 0x21a0c8, Func Offset: 0x118
	// Line 559, Address: 0x21a0dc, Func Offset: 0x12c
	// Line 563, Address: 0x21a0f4, Func Offset: 0x144
	// Func End, Address: 0x21a100, Func Offset: 0x150
}

// 
// Start address: 0x21a100
int bhEne_DirTarget(BH_PWORK* epw, float x, float z, int w)
{
	int ang;
	// Line 576, Address: 0x21a100, Func Offset: 0
	// Line 582, Address: 0x21a110, Func Offset: 0x10
	// Line 583, Address: 0x21a12c, Func Offset: 0x2c
	// Line 585, Address: 0x21a13c, Func Offset: 0x3c
	// Line 586, Address: 0x21a150, Func Offset: 0x50
	// Line 589, Address: 0x21a168, Func Offset: 0x68
	// Line 590, Address: 0x21a16c, Func Offset: 0x6c
	// Func End, Address: 0x21a180, Func Offset: 0x80
}

// 
// Start address: 0x21a180
int bhEne_CheckDirTarget(BH_PWORK* epw, float x, float z, int w)
{
	int ang;
	// Line 603, Address: 0x21a180, Func Offset: 0
	// Line 609, Address: 0x21a190, Func Offset: 0x10
	// Line 610, Address: 0x21a1bc, Func Offset: 0x3c
	// Line 611, Address: 0x21a1e4, Func Offset: 0x64
	// Line 612, Address: 0x21a1e8, Func Offset: 0x68
	// Func End, Address: 0x21a1fc, Func Offset: 0x7c
}

// 
// Start address: 0x21a200
void bhEne_GetPartsPos(BH_PWORK* epw, char* parts, _anon6* p)
{
	npobj* objP;
	_anon12* mlwP;
	// Line 624, Address: 0x21a200, Func Offset: 0
	// Line 625, Address: 0x21a218, Func Offset: 0x18
	// Line 627, Address: 0x21a224, Func Offset: 0x24
	// Line 629, Address: 0x21a22c, Func Offset: 0x2c
	// Line 630, Address: 0x21a234, Func Offset: 0x34
	// Line 631, Address: 0x21a23c, Func Offset: 0x3c
	// Line 633, Address: 0x21a248, Func Offset: 0x48
	// Line 634, Address: 0x21a250, Func Offset: 0x50
	// Line 636, Address: 0x21a270, Func Offset: 0x70
	// Line 637, Address: 0x21a278, Func Offset: 0x78
	// Line 638, Address: 0x21a284, Func Offset: 0x84
	// Line 639, Address: 0x21a298, Func Offset: 0x98
	// Line 641, Address: 0x21a2a4, Func Offset: 0xa4
	// Line 642, Address: 0x21a2ac, Func Offset: 0xac
	// Func End, Address: 0x21a2c8, Func Offset: 0xc8
}

// 
// Start address: 0x21a2d0
int bhEne_DirCheck(int ay, _anon6* vec)
{
	_anon6 v;
	// Line 653, Address: 0x21a2d0, Func Offset: 0
	// Line 656, Address: 0x21a2e8, Func Offset: 0x18
	// Line 657, Address: 0x21a2f0, Func Offset: 0x20
	// Line 658, Address: 0x21a2fc, Func Offset: 0x2c
	// Line 661, Address: 0x21a30c, Func Offset: 0x3c
	// Line 665, Address: 0x21a32c, Func Offset: 0x5c
	// Func End, Address: 0x21a340, Func Offset: 0x70
}

// 
// Start address: 0x21a340
int bhEne_DGDirCheck(BH_PWORK* epw)
{
	// Line 676, Address: 0x21a340, Func Offset: 0
	// Func End, Address: 0x21a34c, Func Offset: 0xc
}

// 
// Start address: 0x21a350
void bhEne_CallPlayerVoice(int no)
{
	// Line 688, Address: 0x21a350, Func Offset: 0
	// Func End, Address: 0x21a358, Func Offset: 0x8
}

// 
// Start address: 0x21a360
void bhEne_CheckEnemiesBall(BH_PWORK* epw)
{
	int i;
	float r;
	float ez1;
	float ey1;
	float ex1;
	float ez0;
	float ey0;
	float ex0;
	float ln;
	float pz;
	float py;
	float px;
	BH_PWORK* epp;
	// Line 699, Address: 0x21a360, Func Offset: 0
	// Line 704, Address: 0x21a38c, Func Offset: 0x2c
	// Line 706, Address: 0x21a39c, Func Offset: 0x3c
	// Line 707, Address: 0x21a3a4, Func Offset: 0x44
	// Line 708, Address: 0x21a3ac, Func Offset: 0x4c
	// Line 710, Address: 0x21a3b4, Func Offset: 0x54
	// Line 706, Address: 0x21a3b8, Func Offset: 0x58
	// Line 710, Address: 0x21a3bc, Func Offset: 0x5c
	// Line 711, Address: 0x21a3c0, Func Offset: 0x60
	// Line 707, Address: 0x21a3c4, Func Offset: 0x64
	// Line 711, Address: 0x21a3c8, Func Offset: 0x68
	// Line 712, Address: 0x21a3d0, Func Offset: 0x70
	// Line 713, Address: 0x21a3f4, Func Offset: 0x94
	// Line 714, Address: 0x21a410, Func Offset: 0xb0
	// Line 716, Address: 0x21a418, Func Offset: 0xb8
	// Line 715, Address: 0x21a420, Func Offset: 0xc0
	// Line 714, Address: 0x21a428, Func Offset: 0xc8
	// Line 716, Address: 0x21a42c, Func Offset: 0xcc
	// Line 717, Address: 0x21a430, Func Offset: 0xd0
	// Line 720, Address: 0x21a434, Func Offset: 0xd4
	// Line 715, Address: 0x21a438, Func Offset: 0xd8
	// Line 718, Address: 0x21a43c, Func Offset: 0xdc
	// Line 720, Address: 0x21a440, Func Offset: 0xe0
	// Line 719, Address: 0x21a448, Func Offset: 0xe8
	// Line 720, Address: 0x21a44c, Func Offset: 0xec
	// Line 721, Address: 0x21a454, Func Offset: 0xf4
	// Line 726, Address: 0x21a470, Func Offset: 0x110
	// Line 727, Address: 0x21a478, Func Offset: 0x118
	// Line 736, Address: 0x21a480, Func Offset: 0x120
	// Line 726, Address: 0x21a484, Func Offset: 0x124
	// Line 727, Address: 0x21a48c, Func Offset: 0x12c
	// Line 728, Address: 0x21a498, Func Offset: 0x138
	// Line 727, Address: 0x21a49c, Func Offset: 0x13c
	// Line 728, Address: 0x21a4a0, Func Offset: 0x140
	// Line 729, Address: 0x21a4b0, Func Offset: 0x150
	// Line 728, Address: 0x21a4b4, Func Offset: 0x154
	// Line 729, Address: 0x21a4b8, Func Offset: 0x158
	// Line 736, Address: 0x21a4cc, Func Offset: 0x16c
	// Line 737, Address: 0x21a4d8, Func Offset: 0x178
	// Line 738, Address: 0x21a4e0, Func Offset: 0x180
	// Line 739, Address: 0x21a4e8, Func Offset: 0x188
	// Line 743, Address: 0x21a4f4, Func Offset: 0x194
	// Line 744, Address: 0x21a520, Func Offset: 0x1c0
	// Func End, Address: 0x21a550, Func Offset: 0x1f0
}

// 
// Start address: 0x21a550
void bhEne_SetWeponAtr(BH_PWORK* epw, char j1, char j2, float r)
{
	_anon31* owk;
	// Line 760, Address: 0x21a550, Func Offset: 0
	// Line 765, Address: 0x21a554, Func Offset: 0x4
	// Line 760, Address: 0x21a558, Func Offset: 0x8
	// Line 765, Address: 0x21a568, Func Offset: 0x18
	// Line 760, Address: 0x21a56c, Func Offset: 0x1c
	// Line 765, Address: 0x21a574, Func Offset: 0x24
	// Line 760, Address: 0x21a580, Func Offset: 0x30
	// Line 761, Address: 0x21a584, Func Offset: 0x34
	// Line 762, Address: 0x21a58c, Func Offset: 0x3c
	// Line 763, Address: 0x21a594, Func Offset: 0x44
	// Line 765, Address: 0x21a59c, Func Offset: 0x4c
	// Line 766, Address: 0x21a5a8, Func Offset: 0x58
	// Line 767, Address: 0x21a5b0, Func Offset: 0x60
	// Line 768, Address: 0x21a5b8, Func Offset: 0x68
	// Line 771, Address: 0x21a5c0, Func Offset: 0x70
	// Func End, Address: 0x21a5c8, Func Offset: 0x78
}

// 
// Start address: 0x21a5d0
unsigned char bhEne_AttackHitCheck(BH_PWORK* pl, _anon6* pos, float ar)
{
	_anon45 sphere;
	int kno;
	int i;
	float knr;
	float ll;
	_anon6 vec;
	// Line 783, Address: 0x21a5d0, Func Offset: 0
	// Line 789, Address: 0x21a5f8, Func Offset: 0x28
	// Line 795, Address: 0x21a604, Func Offset: 0x34
	// Line 794, Address: 0x21a60c, Func Offset: 0x3c
	// Line 789, Address: 0x21a610, Func Offset: 0x40
	// Line 790, Address: 0x21a614, Func Offset: 0x44
	// Line 791, Address: 0x21a61c, Func Offset: 0x4c
	// Line 795, Address: 0x21a624, Func Offset: 0x54
	// Line 796, Address: 0x21a638, Func Offset: 0x68
	// Line 797, Address: 0x21a63c, Func Offset: 0x6c
	// Line 798, Address: 0x21a648, Func Offset: 0x78
	// Line 799, Address: 0x21a650, Func Offset: 0x80
	// Line 800, Address: 0x21a654, Func Offset: 0x84
	// Line 798, Address: 0x21a658, Func Offset: 0x88
	// Line 801, Address: 0x21a660, Func Offset: 0x90
	// Line 798, Address: 0x21a664, Func Offset: 0x94
	// Line 799, Address: 0x21a66c, Func Offset: 0x9c
	// Line 800, Address: 0x21a688, Func Offset: 0xb8
	// Line 801, Address: 0x21a6a0, Func Offset: 0xd0
	// Line 802, Address: 0x21a6a8, Func Offset: 0xd8
	// Line 804, Address: 0x21a6b8, Func Offset: 0xe8
	// Line 805, Address: 0x21a6bc, Func Offset: 0xec
	// Line 803, Address: 0x21a6c0, Func Offset: 0xf0
	// Line 805, Address: 0x21a6c4, Func Offset: 0xf4
	// Line 806, Address: 0x21a6cc, Func Offset: 0xfc
	// Line 807, Address: 0x21a6d8, Func Offset: 0x108
	// Line 808, Address: 0x21a6e4, Func Offset: 0x114
	// Line 807, Address: 0x21a6e8, Func Offset: 0x118
	// Line 809, Address: 0x21a6ec, Func Offset: 0x11c
	// Line 810, Address: 0x21a704, Func Offset: 0x134
	// Line 812, Address: 0x21a708, Func Offset: 0x138
	// Line 813, Address: 0x21a710, Func Offset: 0x140
	// Line 814, Address: 0x21a714, Func Offset: 0x144
	// Line 818, Address: 0x21a718, Func Offset: 0x148
	// Line 814, Address: 0x21a71c, Func Offset: 0x14c
	// Line 815, Address: 0x21a720, Func Offset: 0x150
	// Line 816, Address: 0x21a728, Func Offset: 0x158
	// Line 818, Address: 0x21a72c, Func Offset: 0x15c
	// Line 821, Address: 0x21a734, Func Offset: 0x164
	// Line 822, Address: 0x21a738, Func Offset: 0x168
	// Func End, Address: 0x21a764, Func Offset: 0x194
}

// 
// Start address: 0x21a770
void bhEne_AddNullTrans(BH_PWORK* epw, _anon6* mtn)
{
	_anon6 v;
	// Line 833, Address: 0x21a770, Func Offset: 0
	// Line 836, Address: 0x21a788, Func Offset: 0x18
	// Line 837, Address: 0x21a790, Func Offset: 0x20
	// Line 838, Address: 0x21a79c, Func Offset: 0x2c
	// Line 840, Address: 0x21a7c0, Func Offset: 0x50
	// Line 841, Address: 0x21a7d0, Func Offset: 0x60
	// Line 842, Address: 0x21a7e0, Func Offset: 0x70
	// Func End, Address: 0x21a7f4, Func Offset: 0x84
}

// 
// Start address: 0x21a800
void bhEne_AddNullTransDir(BH_PWORK* epw, int ay, _anon6* mtn)
{
	_anon6 v;
	// Line 853, Address: 0x21a800, Func Offset: 0
	// Line 856, Address: 0x21a820, Func Offset: 0x20
	// Line 857, Address: 0x21a828, Func Offset: 0x28
	// Line 858, Address: 0x21a834, Func Offset: 0x34
	// Line 860, Address: 0x21a858, Func Offset: 0x58
	// Line 861, Address: 0x21a868, Func Offset: 0x68
	// Line 862, Address: 0x21a878, Func Offset: 0x78
	// Func End, Address: 0x21a890, Func Offset: 0x90
}

// 
// Start address: 0x21a890
float bhEne_GetShapeCnt(_anon40* p, int key)
{
	_anon40* pp;
	// Line 878, Address: 0x21a890, Func Offset: 0
	// Line 880, Address: 0x21a8a0, Func Offset: 0x10
	// Line 882, Address: 0x21a8a8, Func Offset: 0x18
	// Line 885, Address: 0x21a8b8, Func Offset: 0x28
	// Line 886, Address: 0x21a8f4, Func Offset: 0x64
	// Func End, Address: 0x21a8fc, Func Offset: 0x6c
}

// 
// Start address: 0x21a900
void bhEne_CalcDamage(BH_PWORK* epw, _anon18* CombWepTbl, _anon20* CombJointTbl)
{
	_anon18* cwp;
	_anon20* cjp;
	unsigned int i;
	int dam;
	// Line 898, Address: 0x21a900, Func Offset: 0
	// Line 902, Address: 0x21a90c, Func Offset: 0xc
	// Line 905, Address: 0x21a910, Func Offset: 0x10
	// Line 908, Address: 0x21a91c, Func Offset: 0x1c
	// Line 902, Address: 0x21a920, Func Offset: 0x20
	// Line 905, Address: 0x21a924, Func Offset: 0x24
	// Line 902, Address: 0x21a92c, Func Offset: 0x2c
	// Line 908, Address: 0x21a930, Func Offset: 0x30
	// Line 902, Address: 0x21a934, Func Offset: 0x34
	// Line 908, Address: 0x21a938, Func Offset: 0x38
	// Line 902, Address: 0x21a93c, Func Offset: 0x3c
	// Line 908, Address: 0x21a944, Func Offset: 0x44
	// Line 910, Address: 0x21a94c, Func Offset: 0x4c
	// Line 912, Address: 0x21a954, Func Offset: 0x54
	// Line 914, Address: 0x21a960, Func Offset: 0x60
	// Line 915, Address: 0x21a970, Func Offset: 0x70
	// Line 916, Address: 0x21a98c, Func Offset: 0x8c
	// Line 917, Address: 0x21a990, Func Offset: 0x90
	// Line 919, Address: 0x21a998, Func Offset: 0x98
	// Line 920, Address: 0x21a9a0, Func Offset: 0xa0
	// Line 921, Address: 0x21a9a4, Func Offset: 0xa4
	// Line 922, Address: 0x21a9ac, Func Offset: 0xac
	// Line 924, Address: 0x21a9b0, Func Offset: 0xb0
	// Line 925, Address: 0x21a9d0, Func Offset: 0xd0
	// Line 926, Address: 0x21a9f0, Func Offset: 0xf0
	// Line 930, Address: 0x21aa10, Func Offset: 0x110
	// Line 931, Address: 0x21aa2c, Func Offset: 0x12c
	// Line 932, Address: 0x21aa38, Func Offset: 0x138
	// Line 933, Address: 0x21aa48, Func Offset: 0x148
	// Line 934, Address: 0x21aa4c, Func Offset: 0x14c
	// Line 936, Address: 0x21aa50, Func Offset: 0x150
	// Line 937, Address: 0x21aa7c, Func Offset: 0x17c
	// Line 939, Address: 0x21aa84, Func Offset: 0x184
	// Line 940, Address: 0x21aaac, Func Offset: 0x1ac
	// Line 943, Address: 0x21aab0, Func Offset: 0x1b0
	// Line 957, Address: 0x21aabc, Func Offset: 0x1bc
	// Line 943, Address: 0x21aac0, Func Offset: 0x1c0
	// Line 957, Address: 0x21aac4, Func Offset: 0x1c4
	// Line 960, Address: 0x21aae4, Func Offset: 0x1e4
	// Line 961, Address: 0x21aaf4, Func Offset: 0x1f4
	// Line 962, Address: 0x21aafc, Func Offset: 0x1fc
	// Line 963, Address: 0x21ab04, Func Offset: 0x204
	// Line 965, Address: 0x21ab10, Func Offset: 0x210
	// Func End, Address: 0x21ab20, Func Offset: 0x220
}

// 
// Start address: 0x21ab20
void bhEne_InitDamage(BH_PWORK* epw)
{
	int i;
	// Line 979, Address: 0x21ab20, Func Offset: 0
	// Line 980, Address: 0x21ab2c, Func Offset: 0xc
	// Line 981, Address: 0x21ab38, Func Offset: 0x18
	// Line 982, Address: 0x21ab40, Func Offset: 0x20
	// Line 983, Address: 0x21ab5c, Func Offset: 0x3c
	// Line 986, Address: 0x21ab60, Func Offset: 0x40
	// Line 987, Address: 0x21ab6c, Func Offset: 0x4c
	// Line 991, Address: 0x21ab74, Func Offset: 0x54
	// Line 992, Address: 0x21ab7c, Func Offset: 0x5c
	// Line 991, Address: 0x21ab80, Func Offset: 0x60
	// Line 992, Address: 0x21ab88, Func Offset: 0x68
	// Line 993, Address: 0x21ab90, Func Offset: 0x70
	// Func End, Address: 0x21ab98, Func Offset: 0x78
}

// 
// Start address: 0x21aba0
void bhEne_CallSE(BH_PWORK* epw, _anon6* pos, int se)
{
	// Line 1005, Address: 0x21aba0, Func Offset: 0
	// Line 1006, Address: 0x21aba8, Func Offset: 0x8
	// Line 1007, Address: 0x21abbc, Func Offset: 0x1c
	// Line 1009, Address: 0x21abd4, Func Offset: 0x34
	// Func End, Address: 0x21abe0, Func Offset: 0x40
}

// 
// Start address: 0x21abe0
void bhEne_CallSE_EX(BH_PWORK* epw, _anon6* pos, int se, int fade)
{
	// Line 1021, Address: 0x21abe0, Func Offset: 0
	// Line 1022, Address: 0x21abe8, Func Offset: 0x8
	// Line 1023, Address: 0x21abfc, Func Offset: 0x1c
	// Line 1025, Address: 0x21ac14, Func Offset: 0x34
	// Func End, Address: 0x21ac20, Func Offset: 0x40
}

// 
// Start address: 0x21ac20
void bhEne_CallEffectSE(_anon6* pos, int se)
{
	// Line 1037, Address: 0x21ac24, Func Offset: 0x4
	// Func End, Address: 0x21ac30, Func Offset: 0x10
}

// 
// Start address: 0x21ac30
void bhEne_SetSEPan(_anon6* pos, int se)
{
	// Line 1051, Address: 0x21ac30, Func Offset: 0
	// Func End, Address: 0x21ac50, Func Offset: 0x20
}

// 
// Start address: 0x21ac50
int bhEne_CheckPlayEffectSE(int se)
{
	// Line 1063, Address: 0x21ac54, Func Offset: 0x4
	// Func End, Address: 0x21ac5c, Func Offset: 0xc
}

// 
// Start address: 0x21ac60
int bhArcTan2(float y, float x)
{
	int ang;
	float len;
	// Line 1075, Address: 0x21ac60, Func Offset: 0
	// Line 1079, Address: 0x21ac74, Func Offset: 0x14
	// Line 1080, Address: 0x21ac84, Func Offset: 0x24
	// Line 1082, Address: 0x21aca4, Func Offset: 0x44
	// Line 1084, Address: 0x21acd4, Func Offset: 0x74
	// Line 1085, Address: 0x21acec, Func Offset: 0x8c
	// Line 1094, Address: 0x21acfc, Func Offset: 0x9c
	// Func End, Address: 0x21ad10, Func Offset: 0xb0
}

// 
// Start address: 0x21ad10
_anon21* bhEne_CheckEventAtr(int flr_no, float px, float pz, int id, int min, int max)
{
	int flr_n;
	int i;
	_anon21* fp;
	// Line 1113, Address: 0x21ad10, Func Offset: 0
	// Line 1114, Address: 0x21ad34, Func Offset: 0x24
	// Line 1117, Address: 0x21ad44, Func Offset: 0x34
	// Line 1116, Address: 0x21ad48, Func Offset: 0x38
	// Line 1117, Address: 0x21ad84, Func Offset: 0x74
	// Line 1122, Address: 0x21adc8, Func Offset: 0xb8
	// Line 1125, Address: 0x21ae2c, Func Offset: 0x11c
	// Line 1128, Address: 0x21ae34, Func Offset: 0x124
	// Line 1129, Address: 0x21ae48, Func Offset: 0x138
	// Line 1130, Address: 0x21ae4c, Func Offset: 0x13c
	// Func End, Address: 0x21ae54, Func Offset: 0x144
}

// 
// Start address: 0x21ae60
void bhEne_EraseArrow(BH_PWORK* epw, int obj_no)
{
	_anon0* op;
	int i;
	// Line 1145, Address: 0x21ae60, Func Offset: 0
	// Line 1146, Address: 0x21ae68, Func Offset: 0x8
	// Line 1148, Address: 0x21ae6c, Func Offset: 0xc
	// Line 1147, Address: 0x21ae70, Func Offset: 0x10
	// Line 1148, Address: 0x21ae8c, Func Offset: 0x2c
	// Line 1151, Address: 0x21aeb0, Func Offset: 0x50
	// Line 1153, Address: 0x21aeb4, Func Offset: 0x54
	// Line 1154, Address: 0x21aeb8, Func Offset: 0x58
	// Line 1155, Address: 0x21aec8, Func Offset: 0x68
	// Func End, Address: 0x21aed0, Func Offset: 0x70
}

