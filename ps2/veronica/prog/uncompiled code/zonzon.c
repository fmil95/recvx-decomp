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
typedef struct _anon44;
typedef struct _anon45;
typedef struct _anon46;

typedef void(*type_78)(void*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef _anon0* type_2[32];
typedef _anon2* type_3[16];
typedef _anon0* type_4[32];
typedef _anon0* type_5[512];
typedef _anon2* type_6[16][16];
typedef _anon2* type_7[16][16][100];
typedef char type_8[8];
typedef _anon0* type_9[32];
typedef _anon0* type_10[512];
typedef _anon2* type_11[1300];
typedef char type_12[32];
typedef float type_13[32];
typedef _anon0* type_14[512];
typedef _anon2* type_15[200];
typedef short type_16[32];
typedef _anon29 type_17[1];
typedef _anon0* type_18[128];
typedef unsigned int type_19[1];
typedef _anon9 type_20[256];
typedef _anon2* type_21[8];
typedef int* type_22[16];
typedef _anon0* type_23[128];
typedef _anon46 type_24[16];
typedef npobj* type_25[16];
typedef _anon0* type_26[128];
typedef int type_27[4];
typedef _anon2* type_28[16];
typedef unsigned int type_29[4];
typedef float type_30[4];
typedef _anon16 type_31[16];
typedef _anon0* type_32[512];
typedef float type_33[4];
typedef char type_34[256];
typedef float type_35[4];
typedef float type_36[4];
typedef float type_37[4];
typedef float type_38[4];
typedef _anon7* type_39[128];
typedef unsigned char type_40[64];
typedef float type_41[16];
typedef float type_42[3];
typedef char type_43[8];
typedef void* type_44[2];
typedef _anon2* type_45[256];
typedef int type_46[4];
typedef unsigned char* type_47[256];
typedef _anon0 type_48[0];
typedef unsigned int type_49[2];
typedef short type_50[256];
typedef _anon34 type_51[4];
typedef float type_52[3];
typedef short type_53[256];
typedef int type_54[3];
typedef _anon1 type_55[42];
typedef int type_56[8];
typedef float type_57[3];
typedef _anon2* type_58[256];
typedef _anon12 type_59[256];
typedef _anon29 type_60[450];
typedef _anon36 type_61[16];
typedef short type_62[256];
typedef char type_63[3];
typedef int type_64[64];
typedef _anon16 type_65[450];
typedef unsigned int type_66[16];
typedef char type_67[4];
typedef unsigned int type_68[8];
typedef _anon39 type_69[4];
typedef _anon3 type_70[4];
typedef int type_71[450];
typedef unsigned int type_72[8];
typedef unsigned char type_73[450];
typedef float type_74[128];
typedef char type_75[16];
typedef _anon6 type_76[20];
typedef char type_77[4];
typedef _anon27 type_79[2];
typedef unsigned int type_80[32];
typedef unsigned char type_81[256];
typedef unsigned int type_82[16];
typedef _anon23 type_83[64];
typedef unsigned int type_84[16];
typedef _anon1 type_85[42];
typedef _anon23 type_86[64];
typedef unsigned int type_87[32];
typedef _anon23 type_88[64];
typedef int type_89[4];
typedef unsigned int type_90[16];
typedef unsigned int type_91[3];
typedef BH_PWORK* type_92[16];
typedef unsigned int type_93[8];
typedef unsigned int type_94[1];
typedef unsigned int type_95[384];
typedef unsigned int type_96[2];
typedef unsigned char type_97[2];
typedef unsigned int type_98[4];
typedef int* type_99[16];
typedef char type_100[32];
typedef npobj* type_101[16];
typedef char type_102[64];
typedef _anon2* type_103[16];
typedef char type_104[4];
typedef _anon16 type_105[16];
typedef short type_106[4];
typedef unsigned char type_107[4];
typedef _anon37 type_108[16];
typedef unsigned int type_109[8];
typedef unsigned int type_110[32];
typedef unsigned int type_111[4];
typedef _anon4 type_112[32];
typedef _anon0* type_113[512];
typedef _anon0* type_114[128];
typedef _anon0* type_115[512];
typedef unsigned char type_116[64];
typedef _anon0* type_117[512];

struct npobj
{
	unsigned int evalflags;
	_anon35* model;
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
	_anon2* txp[16];
	_anon16 mdl[16];
	_anon16* mlwP;
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
	_anon44 cspr;
	int pn;
	_anon39* pvp;
	_anon3* tvp;
	_anon39 pv[4];
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
	_anon16 mdl[16];
	_anon16* mlwP;
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
	_anon45 watr;
	_anon30* cpcl;
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
	float wk;
	int indx;
};

struct _anon2
{
	_anon29* textures;
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
	float x;
	float y;
	float z;
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
	_anon4 ofs;
	int angX;
	int angY;
	int type;
	int wcnt;
};

struct _anon7
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon28* md2P;
	unsigned short* atrP;
};

struct _anon8
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon46 keyf[16];
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
	int lnk_obj;
	float x;
	float y;
	float z;
	float xlen;
	float ylen;
	float size;
	float len;
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
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon13
{
	_anon15* cutp;
	_anon19* lgtp;
	_anon21* enep;
	_anon21* objp;
	_anon21* itmp;
	_anon25* effp;
	_anon23* walp;
	_anon23* etcp;
	_anon23* flrp;
	_anon5* posp;
	_anon23* rutp;
	unsigned char* ruttp;
	_anon31* evtp;
	_anon8* evcp;
	unsigned int* mesp;
	_anon19* evlp;
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
	_anon16 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};

struct _anon14
{
	float key[3];
};

struct _anon15
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon18* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon27 cam[2];
	unsigned char exd[256];
};

struct _anon16
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon2* texP;
	_anon20* owP;
};

struct _anon17
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

struct _anon18
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

struct _anon19
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
	_anon33* light;
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

struct _anon22
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
	_anon4 ply_pos;
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
	_anon17* p1per;
	_anon17* p2per;
	_anon17* kbper;
	_anon17* msper;
	_anon17 ms_per;
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
	_anon2* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon2* txblp[256];
	_anon12 txbp[256];
	unsigned char* ef_psp;
	_anon29 ef_tex[450];
	_anon2 ef_tlist;
	_anon40 ef;
	short efid[256];
	_anon16 efm[450];
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
	_anon26 ren_info;
	_anon29 ren_tex[1];
	_anon2 ren_tlist;
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
	_anon41 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon19* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon34 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon36 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon23* pl_htp;
	int costume;
	_anon4 hd_pos;
	_anon4 apos;
	_anon23* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon23 mwalp[64];
	_anon23 metcp[64];
	_anon23 mflrp[64];
	int dla_n;
	_anon23* htp;
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
	_anon24 door;
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
	_anon4 ufo_pos;
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
	_anon4 ghtp[32];
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

struct _anon23
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

struct _anon24
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
	int lkflg;
	int lkno;
	int lkono;
	float lx;
	float ly;
	float lz;
	int param;
};

struct _anon26
{
	void* texaddr;
	_anon11 texsurface;
};

struct _anon27
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

struct _anon28
{
	void* p[2];
};

struct _anon29
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon30
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon31
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon32
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon33
{
	float mtrx[16];
	_anon4 pnt;
	_anon4 vctr;
	int stat;
	int reserve;
	_anon38 ltcal;
	_anon43 attr;
};

struct _anon34
{
	_anon4 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon35
{
	int* vlist;
	short* plist;
	_anon4 center;
	float r;
};

struct _anon36
{
	float x;
	float y;
};

struct _anon37
{
	_anon4 c1;
	_anon4 c2;
	float r1;
	float r2;
};

struct _anon38
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
	_anon4 lpnt;
	_anon4 lvctr;
	_anon4 lmvctr;
	_anon32 atten;
	_anon32 amb;
	_anon32 dif;
	_anon32 spc;
	_anon32 mamb;
	_anon32 mdif;
	_anon32 mspc;
};

struct _anon39
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon40
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
	int lsrc;
	float iamb;
	float idif;
	float ispc;
	float nrang;
	float frang;
	void* func;
	int iang;
	int oang;
	_anon32 argb;
};

struct _anon44
{
	_anon4 c;
	float r;
};

struct _anon45
{
	_anon4 c1;
	_anon4 c2;
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

_anon22* sys;
_anon13* rom;
BH_PWORK* plp;
_anon0 eff[0];

void ikou(BH_PWORK* epw, _anon4* pos, int add_dir);
int ikou3(BH_PWORK* epw, _anon4* pos, int add_dir);
int NitenDir_ck(float hontai_x, float hontai_z, float target_x, float target_z);
int bhCdirCheck(int my_ang, int trg_ang);
int bhEne_LeverCheck();
int bhDGCdirCheck(_anon4* dv, int rot);
int bhDGCdirCheck2(_anon4* dv, _anon20* owk);
int bhDGCdirCheck3(_anon4* dv, int rot);
int bhEne_AngleCheck(_anon4* vec, int rot, int chk_ang);
void bhEne_GetTranslateMtn(BH_PWORK* epw, int frm, int mode);
void bhEne_GetTranslateMtn2(BH_PWORK* epw, int frm, int mode);
void bhEne_CalcPartsPos(BH_PWORK* epw, float mtx[16], _anon4* pos, char* tree, int parts_num, int clr_flg);
_anon23* bhKaidanAtrCheck(BH_PWORK* epw, float len, int* idx);
_anon23* bhEne_EnemyAtariCheck(_anon4* pos, int flr_no, unsigned char id, unsigned char type);
int bhEne_PosCheck(float px, float pz, float x, float z, float w, float h);
void bhEne_SetBlood(BH_PWORK* epw, unsigned char type, _anon10* bt);
void bhEne_SetBlood2(BH_PWORK* epw, unsigned char type, _anon4* ofp, short ry);
void bhEne_SetBlood3(BH_PWORK* epw, int lnk_obj, _anon4* ofs, _anon4* dv, int n, int tex_id, int type, int wcnt);
void bhEne_SetBlood4(BH_PWORK* epw, int lnk_obj, _anon4* ofs, int tex_id, int type);
void bhEne_SetNikuhenEffect(BH_PWORK* epw, int type, _anon4* pos, _anon4* v, int tex_id);
void bhEne_SetNikuhenEffect2(BH_PWORK* epw, int type, _anon4* pos, int n, int tex_id);
int bhEne_SetDFireEffect(BH_PWORK* epw, int no, _anon10* ltbl, int type);
void bhEne_SetDFireEffect2(BH_PWORK* epw, int no, _anon10* ltbl, int type);
int bhEne_SetSanEffect(BH_PWORK* epw, int no, _anon10* ltbl);
int bhEne_SetSanEffect2(BH_PWORK* epw, int no, _anon10* ltbl);
void bhEne_QuickSort(_anon1* a, int first, int last);
int bhEne_ChgMtn(BH_PWORK* epw, unsigned int no, int frm, int rate);
int bhEne_CollisionCheckWall(BH_PWORK* pw, _anon4* ps, _anon4* pd, float ar, float ah);
_anon23* bhEne_CollisionCheckWall2(BH_PWORK* pw, _anon4* ps, _anon4* ops, _anon4* pd, float ar, float ah);
_anon23* bhEne_CheckDirWall(BH_PWORK* epw, int ang, float step);
_anon23* bhEne_CheckDirWall2(BH_PWORK* epw, int ang, float step);
_anon23* bhEne_CheckDirWall3(BH_PWORK* epw, _anon4* pos, int ang, float step);
int bhEne_CheckSideWall(BH_PWORK* epw, float step, int both);
int bhEne_CheckSideWall2(BH_PWORK* epw, float step, int both);
int bhEne_CheckSideWall3(BH_PWORK* epw, _anon4* pos, float step, int both);
void bhEne_SetVibration(int no);
void bhEne_PlayerSePlay(BH_PWORK* epw, int no);
void bhEne_HitCheckParts(BH_PWORK* pp, _anon4* pos);

// 
// Start address: 0x215f10
void ikou(BH_PWORK* epw, _anon4* pos, int add_dir)
{
	int rot;
	int ang;
	// Line 119, Address: 0x215f10, Func Offset: 0
	// Line 122, Address: 0x215f20, Func Offset: 0x10
	// Line 125, Address: 0x215f34, Func Offset: 0x24
	// Line 128, Address: 0x215f48, Func Offset: 0x38
	// Line 131, Address: 0x215f58, Func Offset: 0x48
	// Line 130, Address: 0x215f60, Func Offset: 0x50
	// Line 131, Address: 0x215f64, Func Offset: 0x54
	// Line 134, Address: 0x215f68, Func Offset: 0x58
	// Line 136, Address: 0x215f6c, Func Offset: 0x5c
	// Line 134, Address: 0x215f70, Func Offset: 0x60
	// Line 136, Address: 0x215f7c, Func Offset: 0x6c
	// Line 139, Address: 0x215f88, Func Offset: 0x78
	// Line 144, Address: 0x215f90, Func Offset: 0x80
	// Line 142, Address: 0x215f94, Func Offset: 0x84
	// Line 144, Address: 0x215f98, Func Offset: 0x88
	// Line 146, Address: 0x215fa4, Func Offset: 0x94
	// Line 149, Address: 0x215fb0, Func Offset: 0xa0
	// Func End, Address: 0x215fc4, Func Offset: 0xb4
}

// 
// Start address: 0x215fd0
int ikou3(BH_PWORK* epw, _anon4* pos, int add_dir)
{
	int rot;
	// Line 168, Address: 0x215fd0, Func Offset: 0
	// Line 171, Address: 0x215fe0, Func Offset: 0x10
	// Line 174, Address: 0x215ffc, Func Offset: 0x2c
	// Line 176, Address: 0x216010, Func Offset: 0x40
	// Line 178, Address: 0x216014, Func Offset: 0x44
	// Line 176, Address: 0x216018, Func Offset: 0x48
	// Line 178, Address: 0x216024, Func Offset: 0x54
	// Line 179, Address: 0x216030, Func Offset: 0x60
	// Line 181, Address: 0x216038, Func Offset: 0x68
	// Line 184, Address: 0x216058, Func Offset: 0x88
	// Func End, Address: 0x21606c, Func Offset: 0x9c
}

// 
// Start address: 0x216070
int NitenDir_ck(float hontai_x, float hontai_z, float target_x, float target_z)
{
	// Line 207, Address: 0x216070, Func Offset: 0
	// Line 206, Address: 0x216074, Func Offset: 0x4
	// Line 207, Address: 0x21607c, Func Offset: 0xc
	// Line 208, Address: 0x216098, Func Offset: 0x28
	// Func End, Address: 0x2160a4, Func Offset: 0x34
}

// 
// Start address: 0x2160b0
int bhCdirCheck(int my_ang, int trg_ang)
{
	// Line 232, Address: 0x2160b0, Func Offset: 0
	// Line 236, Address: 0x2160c8, Func Offset: 0x18
	// Func End, Address: 0x2160d0, Func Offset: 0x20
}

// 
// Start address: 0x2160d0
int bhEne_LeverCheck()
{
	int dec_cnt;
	// Line 255, Address: 0x2160d0, Func Offset: 0
	// Line 257, Address: 0x2160f0, Func Offset: 0x20
	// Line 260, Address: 0x2160f4, Func Offset: 0x24
	// Line 262, Address: 0x216100, Func Offset: 0x30
	// Line 273, Address: 0x216104, Func Offset: 0x34
	// Func End, Address: 0x21610c, Func Offset: 0x3c
}

// 
// Start address: 0x216110
int bhDGCdirCheck(_anon4* dv, int rot)
{
	_anon4 v1;
	_anon4 v0;
	// Line 293, Address: 0x216110, Func Offset: 0
	// Line 305, Address: 0x216128, Func Offset: 0x18
	// Line 306, Address: 0x216134, Func Offset: 0x24
	// Line 307, Address: 0x216148, Func Offset: 0x38
	// Line 309, Address: 0x21614c, Func Offset: 0x3c
	// Line 312, Address: 0x216150, Func Offset: 0x40
	// Line 309, Address: 0x216154, Func Offset: 0x44
	// Line 310, Address: 0x216158, Func Offset: 0x48
	// Line 311, Address: 0x216160, Func Offset: 0x50
	// Line 312, Address: 0x216164, Func Offset: 0x54
	// Line 316, Address: 0x21616c, Func Offset: 0x5c
	// Line 322, Address: 0x21619c, Func Offset: 0x8c
	// Func End, Address: 0x2161b0, Func Offset: 0xa0
}

// 
// Start address: 0x2161b0
int bhDGCdirCheck2(_anon4* dv, _anon20* owk)
{
	_anon4 v1;
	_anon4 v0;
	// Line 340, Address: 0x2161b0, Func Offset: 0
	// Line 354, Address: 0x2161c8, Func Offset: 0x18
	// Line 352, Address: 0x2161cc, Func Offset: 0x1c
	// Line 351, Address: 0x2161d0, Func Offset: 0x20
	// Line 353, Address: 0x2161d4, Func Offset: 0x24
	// Line 352, Address: 0x2161d8, Func Offset: 0x28
	// Line 353, Address: 0x2161dc, Func Offset: 0x2c
	// Line 354, Address: 0x2161e0, Func Offset: 0x30
	// Line 356, Address: 0x2161f0, Func Offset: 0x40
	// Line 359, Address: 0x2161f4, Func Offset: 0x44
	// Line 356, Address: 0x2161f8, Func Offset: 0x48
	// Line 357, Address: 0x2161fc, Func Offset: 0x4c
	// Line 358, Address: 0x216204, Func Offset: 0x54
	// Line 359, Address: 0x216208, Func Offset: 0x58
	// Line 363, Address: 0x216210, Func Offset: 0x60
	// Line 369, Address: 0x216240, Func Offset: 0x90
	// Func End, Address: 0x216258, Func Offset: 0xa8
}

// 
// Start address: 0x216260
int bhDGCdirCheck3(_anon4* dv, int rot)
{
	int ang;
	// Line 388, Address: 0x216260, Func Offset: 0
	// Line 394, Address: 0x21626c, Func Offset: 0xc
	// Line 395, Address: 0x216290, Func Offset: 0x30
	// Line 397, Address: 0x216298, Func Offset: 0x38
	// Line 399, Address: 0x2162b4, Func Offset: 0x54
	// Line 401, Address: 0x2162c0, Func Offset: 0x60
	// Line 403, Address: 0x2162d4, Func Offset: 0x74
	// Line 405, Address: 0x2162dc, Func Offset: 0x7c
	// Line 407, Address: 0x2162f8, Func Offset: 0x98
	// Line 409, Address: 0x216300, Func Offset: 0xa0
	// Line 411, Address: 0x216320, Func Offset: 0xc0
	// Line 413, Address: 0x216328, Func Offset: 0xc8
	// Line 414, Address: 0x21632c, Func Offset: 0xcc
	// Func End, Address: 0x21633c, Func Offset: 0xdc
}

// 
// Start address: 0x216340
int bhEne_AngleCheck(_anon4* vec, int rot, int chk_ang)
{
	float n2;
	float n1;
	_anon4 v3;
	_anon4 v2;
	_anon4 v1;
	// Line 435, Address: 0x216340, Func Offset: 0
	// Line 440, Address: 0x216358, Func Offset: 0x18
	// Line 441, Address: 0x216360, Func Offset: 0x20
	// Line 442, Address: 0x216364, Func Offset: 0x24
	// Line 448, Address: 0x216374, Func Offset: 0x34
	// Line 449, Address: 0x21637c, Func Offset: 0x3c
	// Line 450, Address: 0x216388, Func Offset: 0x48
	// Line 452, Address: 0x216398, Func Offset: 0x58
	// Line 453, Address: 0x2163a0, Func Offset: 0x60
	// Line 454, Address: 0x2163b0, Func Offset: 0x70
	// Line 456, Address: 0x2163c0, Func Offset: 0x80
	// Line 458, Address: 0x2163c8, Func Offset: 0x88
	// Line 459, Address: 0x2163d4, Func Offset: 0x94
	// Line 458, Address: 0x2163d8, Func Offset: 0x98
	// Line 459, Address: 0x2163dc, Func Offset: 0x9c
	// Line 461, Address: 0x2163e4, Func Offset: 0xa4
	// Line 463, Address: 0x216400, Func Offset: 0xc0
	// Func End, Address: 0x21641c, Func Offset: 0xdc
}

// 
// Start address: 0x216420
void bhEne_GetTranslateMtn(BH_PWORK* epw, int frm, int mode)
{
	_anon4 key;
	_anon14* mkfP;
	// Line 483, Address: 0x216420, Func Offset: 0
	// Line 486, Address: 0x21642c, Func Offset: 0xc
	// Line 490, Address: 0x216434, Func Offset: 0x14
	// Line 486, Address: 0x21643c, Func Offset: 0x1c
	// Line 490, Address: 0x216460, Func Offset: 0x40
	// Line 492, Address: 0x216478, Func Offset: 0x58
	// Line 494, Address: 0x216480, Func Offset: 0x60
	// Line 495, Address: 0x216488, Func Offset: 0x68
	// Line 496, Address: 0x216490, Func Offset: 0x70
	// Line 497, Address: 0x216494, Func Offset: 0x74
	// Line 500, Address: 0x21649c, Func Offset: 0x7c
	// Line 501, Address: 0x2164ac, Func Offset: 0x8c
	// Line 502, Address: 0x2164bc, Func Offset: 0x9c
	// Line 504, Address: 0x2164cc, Func Offset: 0xac
	// Line 506, Address: 0x2164d8, Func Offset: 0xb8
	// Line 507, Address: 0x2164e4, Func Offset: 0xc4
	// Line 508, Address: 0x2164f8, Func Offset: 0xd8
	// Line 509, Address: 0x21650c, Func Offset: 0xec
	// Line 512, Address: 0x21651c, Func Offset: 0xfc
	// Line 514, Address: 0x21655c, Func Offset: 0x13c
	// Func End, Address: 0x21656c, Func Offset: 0x14c
}

// 
// Start address: 0x216570
void bhEne_GetTranslateMtn2(BH_PWORK* epw, int frm, int mode)
{
	_anon4 key;
	_anon14* mkfP;
	// Line 533, Address: 0x216570, Func Offset: 0
	// Line 536, Address: 0x21657c, Func Offset: 0xc
	// Line 540, Address: 0x216584, Func Offset: 0x14
	// Line 536, Address: 0x21658c, Func Offset: 0x1c
	// Line 540, Address: 0x2165b0, Func Offset: 0x40
	// Line 545, Address: 0x2165c8, Func Offset: 0x58
	// Line 547, Address: 0x2165d0, Func Offset: 0x60
	// Line 548, Address: 0x2165d8, Func Offset: 0x68
	// Line 549, Address: 0x2165e0, Func Offset: 0x70
	// Line 550, Address: 0x2165e4, Func Offset: 0x74
	// Line 553, Address: 0x2165ec, Func Offset: 0x7c
	// Line 554, Address: 0x2165fc, Func Offset: 0x8c
	// Line 555, Address: 0x21660c, Func Offset: 0x9c
	// Line 557, Address: 0x21661c, Func Offset: 0xac
	// Line 558, Address: 0x216628, Func Offset: 0xb8
	// Line 559, Address: 0x216638, Func Offset: 0xc8
	// Func End, Address: 0x216648, Func Offset: 0xd8
}

// 
// Start address: 0x216650
void bhEne_CalcPartsPos(BH_PWORK* epw, float mtx[16], _anon4* pos, char* tree, int parts_num, int clr_flg)
{
	int i;
	npobj* obj;
	// Line 585, Address: 0x216650, Func Offset: 0
	// Line 589, Address: 0x216684, Func Offset: 0x34
	// Line 591, Address: 0x21668c, Func Offset: 0x3c
	// Line 592, Address: 0x216694, Func Offset: 0x44
	// Line 593, Address: 0x2166a8, Func Offset: 0x58
	// Line 596, Address: 0x2166bc, Func Offset: 0x6c
	// Line 598, Address: 0x2166c8, Func Offset: 0x78
	// Line 599, Address: 0x2166ec, Func Offset: 0x9c
	// Line 600, Address: 0x216700, Func Offset: 0xb0
	// Line 602, Address: 0x216714, Func Offset: 0xc4
	// Line 603, Address: 0x216728, Func Offset: 0xd8
	// Line 604, Address: 0x216734, Func Offset: 0xe4
	// Func End, Address: 0x21675c, Func Offset: 0x10c
}

// 
// Start address: 0x216760
_anon23* bhKaidanAtrCheck(BH_PWORK* epw, float len, int* idx)
{
	int etc_n;
	int i;
	float pz2;
	float pz;
	float px2;
	float px;
	_anon23* exp;
	// Line 623, Address: 0x216760, Func Offset: 0
	// Line 628, Address: 0x21677c, Func Offset: 0x1c
	// Line 629, Address: 0x216790, Func Offset: 0x30
	// Line 628, Address: 0x216794, Func Offset: 0x34
	// Line 629, Address: 0x216798, Func Offset: 0x38
	// Line 642, Address: 0x2167a0, Func Offset: 0x40
	// Line 629, Address: 0x2167a8, Func Offset: 0x48
	// Line 643, Address: 0x2167b0, Func Offset: 0x50
	// Line 642, Address: 0x2167b4, Func Offset: 0x54
	// Line 643, Address: 0x2167d0, Func Offset: 0x70
	// Line 660, Address: 0x2167e0, Func Offset: 0x80
	// Line 664, Address: 0x2167e4, Func Offset: 0x84
	// Line 660, Address: 0x2167e8, Func Offset: 0x88
	// Line 650, Address: 0x2167ec, Func Offset: 0x8c
	// Line 653, Address: 0x2167f0, Func Offset: 0x90
	// Line 646, Address: 0x2167f4, Func Offset: 0x94
	// Line 648, Address: 0x216830, Func Offset: 0xd0
	// Line 650, Address: 0x216840, Func Offset: 0xe0
	// Line 653, Address: 0x216854, Func Offset: 0xf4
	// Line 660, Address: 0x2168cc, Func Offset: 0x16c
	// Line 664, Address: 0x2168d0, Func Offset: 0x170
	// Line 661, Address: 0x2168d4, Func Offset: 0x174
	// Line 662, Address: 0x2168d8, Func Offset: 0x178
	// Line 664, Address: 0x2168dc, Func Offset: 0x17c
	// Line 666, Address: 0x2168f0, Func Offset: 0x190
	// Line 669, Address: 0x216914, Func Offset: 0x1b4
	// Line 674, Address: 0x21691c, Func Offset: 0x1bc
	// Line 677, Address: 0x21693c, Func Offset: 0x1dc
	// Line 684, Address: 0x216944, Func Offset: 0x1e4
	// Line 685, Address: 0x216958, Func Offset: 0x1f8
	// Line 686, Address: 0x21695c, Func Offset: 0x1fc
	// Func End, Address: 0x216978, Func Offset: 0x218
}

// 
// Start address: 0x216980
_anon23* bhEne_EnemyAtariCheck(_anon4* pos, int flr_no, unsigned char id, unsigned char type)
{
	int flr_n;
	int i;
	_anon23* fp;
	// Line 708, Address: 0x216980, Func Offset: 0
	// Line 712, Address: 0x2169a8, Func Offset: 0x28
	// Line 713, Address: 0x2169d4, Func Offset: 0x54
	// Line 716, Address: 0x2169ec, Func Offset: 0x6c
	// Line 717, Address: 0x216a38, Func Offset: 0xb8
	// Line 719, Address: 0x216a58, Func Offset: 0xd8
	// Line 724, Address: 0x216aa0, Func Offset: 0x120
	// Line 727, Address: 0x216aa8, Func Offset: 0x128
	// Line 728, Address: 0x216ab8, Func Offset: 0x138
	// Line 729, Address: 0x216abc, Func Offset: 0x13c
	// Func End, Address: 0x216ae8, Func Offset: 0x168
}

// 
// Start address: 0x216af0
int bhEne_PosCheck(float px, float pz, float x, float z, float w, float h)
{
	// Line 751, Address: 0x216af0, Func Offset: 0
	// Line 754, Address: 0x216b38, Func Offset: 0x48
	// Line 756, Address: 0x216b40, Func Offset: 0x50
	// Line 757, Address: 0x216b44, Func Offset: 0x54
	// Func End, Address: 0x216b4c, Func Offset: 0x5c
}

// 
// Start address: 0x216b50
void bhEne_SetBlood(BH_PWORK* epw, unsigned char type, _anon10* bt)
{
	int fhit;
	_anon4 ps;
	_anon4 ofp;
	_anon20* owk;
	// Line 779, Address: 0x216b50, Func Offset: 0
	// Line 784, Address: 0x216b6c, Func Offset: 0x1c
	// Line 782, Address: 0x216b7c, Func Offset: 0x2c
	// Line 784, Address: 0x216b80, Func Offset: 0x30
	// Line 787, Address: 0x216b94, Func Offset: 0x44
	// Line 792, Address: 0x216bb8, Func Offset: 0x68
	// Line 796, Address: 0x216bc0, Func Offset: 0x70
	// Line 792, Address: 0x216bc4, Func Offset: 0x74
	// Line 793, Address: 0x216bcc, Func Offset: 0x7c
	// Line 794, Address: 0x216bdc, Func Offset: 0x8c
	// Line 796, Address: 0x216be4, Func Offset: 0x94
	// Line 794, Address: 0x216be8, Func Offset: 0x98
	// Line 796, Address: 0x216bec, Func Offset: 0x9c
	// Line 797, Address: 0x216bf4, Func Offset: 0xa4
	// Line 798, Address: 0x216bfc, Func Offset: 0xac
	// Line 799, Address: 0x216c0c, Func Offset: 0xbc
	// Line 802, Address: 0x216c14, Func Offset: 0xc4
	// Line 804, Address: 0x216c28, Func Offset: 0xd8
	// Line 807, Address: 0x216c2c, Func Offset: 0xdc
	// Line 809, Address: 0x216c38, Func Offset: 0xe8
	// Line 810, Address: 0x216c78, Func Offset: 0x128
	// Line 815, Address: 0x216cb4, Func Offset: 0x164
	// Line 816, Address: 0x216cbc, Func Offset: 0x16c
	// Line 818, Address: 0x216ccc, Func Offset: 0x17c
	// Line 819, Address: 0x216cd4, Func Offset: 0x184
	// Line 821, Address: 0x216cdc, Func Offset: 0x18c
	// Line 822, Address: 0x216cf8, Func Offset: 0x1a8
	// Func End, Address: 0x216d18, Func Offset: 0x1c8
}

// 
// Start address: 0x216d20
void bhEne_SetBlood2(BH_PWORK* epw, unsigned char type, _anon4* ofp, short ry)
{
	_anon4 ps;
	_anon4 ps;
	_anon4 ps;
	_anon0* op;
	unsigned int bl_color;
	// Line 848, Address: 0x216d20, Func Offset: 0
	// Line 853, Address: 0x216d3c, Func Offset: 0x1c
	// Line 857, Address: 0x216d4c, Func Offset: 0x2c
	// Line 853, Address: 0x216d54, Func Offset: 0x34
	// Line 854, Address: 0x216d60, Func Offset: 0x40
	// Line 863, Address: 0x216d68, Func Offset: 0x48
	// Line 854, Address: 0x216d6c, Func Offset: 0x4c
	// Line 855, Address: 0x216d78, Func Offset: 0x58
	// Line 856, Address: 0x216d8c, Func Offset: 0x6c
	// Line 857, Address: 0x216da0, Func Offset: 0x80
	// Line 858, Address: 0x216db4, Func Offset: 0x94
	// Line 859, Address: 0x216dc8, Func Offset: 0xa8
	// Line 860, Address: 0x216ddc, Func Offset: 0xbc
	// Line 863, Address: 0x216df0, Func Offset: 0xd0
	// Line 865, Address: 0x216dfc, Func Offset: 0xdc
	// Line 866, Address: 0x216e08, Func Offset: 0xe8
	// Line 865, Address: 0x216e0c, Func Offset: 0xec
	// Line 867, Address: 0x216e14, Func Offset: 0xf4
	// Line 870, Address: 0x216e1c, Func Offset: 0xfc
	// Line 871, Address: 0x216e24, Func Offset: 0x104
	// Line 870, Address: 0x216e28, Func Offset: 0x108
	// Line 874, Address: 0x216e34, Func Offset: 0x114
	// Line 882, Address: 0x216e60, Func Offset: 0x140
	// Line 883, Address: 0x216e68, Func Offset: 0x148
	// Line 882, Address: 0x216e6c, Func Offset: 0x14c
	// Line 885, Address: 0x216e70, Func Offset: 0x150
	// Line 882, Address: 0x216e74, Func Offset: 0x154
	// Line 883, Address: 0x216e80, Func Offset: 0x160
	// Line 885, Address: 0x216e90, Func Offset: 0x170
	// Line 887, Address: 0x216e98, Func Offset: 0x178
	// Line 888, Address: 0x216eb0, Func Offset: 0x190
	// Line 889, Address: 0x216ec4, Func Offset: 0x1a4
	// Line 893, Address: 0x216ed8, Func Offset: 0x1b8
	// Line 897, Address: 0x216efc, Func Offset: 0x1dc
	// Line 903, Address: 0x216f04, Func Offset: 0x1e4
	// Line 904, Address: 0x216f10, Func Offset: 0x1f0
	// Line 906, Address: 0x216f14, Func Offset: 0x1f4
	// Line 903, Address: 0x216f18, Func Offset: 0x1f8
	// Line 904, Address: 0x216f24, Func Offset: 0x204
	// Line 911, Address: 0x216f2c, Func Offset: 0x20c
	// Line 904, Address: 0x216f34, Func Offset: 0x214
	// Line 905, Address: 0x216f40, Func Offset: 0x220
	// Line 906, Address: 0x216f54, Func Offset: 0x234
	// Line 907, Address: 0x216f68, Func Offset: 0x248
	// Line 908, Address: 0x216f7c, Func Offset: 0x25c
	// Line 911, Address: 0x216f90, Func Offset: 0x270
	// Line 913, Address: 0x216fac, Func Offset: 0x28c
	// Line 917, Address: 0x216fb0, Func Offset: 0x290
	// Line 913, Address: 0x216fc0, Func Offset: 0x2a0
	// Line 914, Address: 0x216fc8, Func Offset: 0x2a8
	// Line 915, Address: 0x216fd4, Func Offset: 0x2b4
	// Line 916, Address: 0x216fe0, Func Offset: 0x2c0
	// Line 917, Address: 0x216fe4, Func Offset: 0x2c4
	// Line 919, Address: 0x216ff0, Func Offset: 0x2d0
	// Line 922, Address: 0x216ff8, Func Offset: 0x2d8
	// Line 923, Address: 0x21700c, Func Offset: 0x2ec
	// Line 924, Address: 0x21701c, Func Offset: 0x2fc
	// Line 925, Address: 0x21702c, Func Offset: 0x30c
	// Line 926, Address: 0x217048, Func Offset: 0x328
	// Line 929, Address: 0x217050, Func Offset: 0x330
	// Line 930, Address: 0x21705c, Func Offset: 0x33c
	// Line 931, Address: 0x217060, Func Offset: 0x340
	// Line 929, Address: 0x217064, Func Offset: 0x344
	// Line 930, Address: 0x217070, Func Offset: 0x350
	// Line 936, Address: 0x217078, Func Offset: 0x358
	// Line 930, Address: 0x217080, Func Offset: 0x360
	// Line 931, Address: 0x21708c, Func Offset: 0x36c
	// Line 932, Address: 0x2170a0, Func Offset: 0x380
	// Line 933, Address: 0x2170b4, Func Offset: 0x394
	// Line 936, Address: 0x2170c8, Func Offset: 0x3a8
	// Line 959, Address: 0x2170e4, Func Offset: 0x3c4
	// Line 962, Address: 0x2170ec, Func Offset: 0x3cc
	// Line 965, Address: 0x2170f8, Func Offset: 0x3d8
	// Line 966, Address: 0x2170fc, Func Offset: 0x3dc
	// Line 962, Address: 0x217100, Func Offset: 0x3e0
	// Line 963, Address: 0x21710c, Func Offset: 0x3ec
	// Line 968, Address: 0x217114, Func Offset: 0x3f4
	// Line 963, Address: 0x21711c, Func Offset: 0x3fc
	// Line 964, Address: 0x217128, Func Offset: 0x408
	// Line 965, Address: 0x21713c, Func Offset: 0x41c
	// Line 966, Address: 0x217150, Func Offset: 0x430
	// Line 968, Address: 0x217164, Func Offset: 0x444
	// Line 973, Address: 0x217180, Func Offset: 0x460
	// Line 974, Address: 0x217194, Func Offset: 0x474
	// Line 975, Address: 0x2171a4, Func Offset: 0x484
	// Line 976, Address: 0x2171b4, Func Offset: 0x494
	// Line 977, Address: 0x2171b8, Func Offset: 0x498
	// Line 978, Address: 0x2171d4, Func Offset: 0x4b4
	// Line 982, Address: 0x2171dc, Func Offset: 0x4bc
	// Line 983, Address: 0x2171e8, Func Offset: 0x4c8
	// Line 985, Address: 0x2171ec, Func Offset: 0x4cc
	// Line 982, Address: 0x2171f0, Func Offset: 0x4d0
	// Line 983, Address: 0x2171fc, Func Offset: 0x4dc
	// Line 988, Address: 0x217204, Func Offset: 0x4e4
	// Line 983, Address: 0x21720c, Func Offset: 0x4ec
	// Line 984, Address: 0x217218, Func Offset: 0x4f8
	// Line 985, Address: 0x21722c, Func Offset: 0x50c
	// Line 986, Address: 0x217240, Func Offset: 0x520
	// Line 987, Address: 0x217254, Func Offset: 0x534
	// Line 988, Address: 0x217268, Func Offset: 0x548
	// Line 991, Address: 0x217284, Func Offset: 0x564
	// Line 995, Address: 0x217288, Func Offset: 0x568
	// Line 991, Address: 0x217294, Func Offset: 0x574
	// Line 992, Address: 0x21729c, Func Offset: 0x57c
	// Line 995, Address: 0x2172a0, Func Offset: 0x580
	// Line 992, Address: 0x2172a4, Func Offset: 0x584
	// Line 993, Address: 0x2172ac, Func Offset: 0x58c
	// Line 994, Address: 0x2172b8, Func Offset: 0x598
	// Line 995, Address: 0x2172bc, Func Offset: 0x59c
	// Line 997, Address: 0x2172c8, Func Offset: 0x5a8
	// Line 1002, Address: 0x2172d0, Func Offset: 0x5b0
	// Line 1006, Address: 0x2172d4, Func Offset: 0x5b4
	// Line 1002, Address: 0x2172e0, Func Offset: 0x5c0
	// Line 1003, Address: 0x2172e8, Func Offset: 0x5c8
	// Line 1006, Address: 0x2172ec, Func Offset: 0x5cc
	// Line 1003, Address: 0x2172f0, Func Offset: 0x5d0
	// Line 1004, Address: 0x2172f8, Func Offset: 0x5d8
	// Line 1005, Address: 0x217304, Func Offset: 0x5e4
	// Line 1006, Address: 0x217308, Func Offset: 0x5e8
	// Line 1008, Address: 0x217314, Func Offset: 0x5f4
	// Line 1027, Address: 0x21731c, Func Offset: 0x5fc
	// Line 1028, Address: 0x217320, Func Offset: 0x600
	// Line 1029, Address: 0x217338, Func Offset: 0x618
	// Line 1044, Address: 0x217340, Func Offset: 0x620
	// Line 1046, Address: 0x217354, Func Offset: 0x634
	// Line 1050, Address: 0x217364, Func Offset: 0x644
	// Line 1051, Address: 0x217374, Func Offset: 0x654
	// Line 1053, Address: 0x217378, Func Offset: 0x658
	// Line 1055, Address: 0x217394, Func Offset: 0x674
	// Line 1058, Address: 0x21739c, Func Offset: 0x67c
	// Func End, Address: 0x2173b8, Func Offset: 0x698
}

// 
// Start address: 0x2173c0
void bhEne_SetBlood3(BH_PWORK* epw, int lnk_obj, _anon4* ofs, _anon4* dv, int n, int tex_id, int type, int wcnt)
{
	int eno;
	// Line 1086, Address: 0x2173c0, Func Offset: 0
	// Line 1089, Address: 0x2173dc, Func Offset: 0x1c
	// Line 1090, Address: 0x217400, Func Offset: 0x40
	// Line 1092, Address: 0x21740c, Func Offset: 0x4c
	// Line 1096, Address: 0x217410, Func Offset: 0x50
	// Line 1090, Address: 0x217414, Func Offset: 0x54
	// Line 1091, Address: 0x217420, Func Offset: 0x60
	// Line 1092, Address: 0x21743c, Func Offset: 0x7c
	// Line 1093, Address: 0x217450, Func Offset: 0x90
	// Line 1094, Address: 0x217464, Func Offset: 0xa4
	// Line 1096, Address: 0x217474, Func Offset: 0xb4
	// Line 1098, Address: 0x21747c, Func Offset: 0xbc
	// Line 1101, Address: 0x217484, Func Offset: 0xc4
	// Line 1098, Address: 0x217490, Func Offset: 0xd0
	// Line 1099, Address: 0x21749c, Func Offset: 0xdc
	// Line 1100, Address: 0x2174b0, Func Offset: 0xf0
	// Line 1101, Address: 0x2174c4, Func Offset: 0x104
	// Line 1102, Address: 0x2174dc, Func Offset: 0x11c
	// Line 1105, Address: 0x2174e4, Func Offset: 0x124
	// Line 1108, Address: 0x2174f0, Func Offset: 0x130
	// Line 1105, Address: 0x2174f8, Func Offset: 0x138
	// Line 1106, Address: 0x217504, Func Offset: 0x144
	// Line 1107, Address: 0x21751c, Func Offset: 0x15c
	// Line 1108, Address: 0x217534, Func Offset: 0x174
	// Line 1111, Address: 0x217550, Func Offset: 0x190
	// Line 1113, Address: 0x21755c, Func Offset: 0x19c
	// Line 1114, Address: 0x21757c, Func Offset: 0x1bc
	// Line 1113, Address: 0x217584, Func Offset: 0x1c4
	// Line 1114, Address: 0x217588, Func Offset: 0x1c8
	// Line 1113, Address: 0x21758c, Func Offset: 0x1cc
	// Line 1114, Address: 0x217594, Func Offset: 0x1d4
	// Line 1115, Address: 0x217598, Func Offset: 0x1d8
	// Line 1114, Address: 0x2175a4, Func Offset: 0x1e4
	// Line 1116, Address: 0x2175a8, Func Offset: 0x1e8
	// Line 1114, Address: 0x2175b0, Func Offset: 0x1f0
	// Line 1115, Address: 0x2175b4, Func Offset: 0x1f4
	// Line 1116, Address: 0x2175b8, Func Offset: 0x1f8
	// Line 1117, Address: 0x2175c0, Func Offset: 0x200
	// Line 1116, Address: 0x2175cc, Func Offset: 0x20c
	// Line 1117, Address: 0x2175d0, Func Offset: 0x210
	// Line 1118, Address: 0x2175d4, Func Offset: 0x214
	// Line 1117, Address: 0x2175e0, Func Offset: 0x220
	// Line 1118, Address: 0x2175e4, Func Offset: 0x224
	// Line 1119, Address: 0x2175e8, Func Offset: 0x228
	// Line 1118, Address: 0x2175f4, Func Offset: 0x234
	// Line 1119, Address: 0x2175f8, Func Offset: 0x238
	// Line 1120, Address: 0x2175fc, Func Offset: 0x23c
	// Line 1122, Address: 0x21760c, Func Offset: 0x24c
	// Func End, Address: 0x21762c, Func Offset: 0x26c
}

// 
// Start address: 0x217630
void bhEne_SetBlood4(BH_PWORK* epw, int lnk_obj, _anon4* ofs, int tex_id, int type)
{
	int i;
	int ang;
	int angY;
	_anon4 v;
	_anon4 ps;
	_anon6* tbl;
	int blood_n[4];
	_anon6 bld_tbl[20];
	// Line 1146, Address: 0x217630, Func Offset: 0
	// Line 1186, Address: 0x21765c, Func Offset: 0x2c
	// Line 1187, Address: 0x217664, Func Offset: 0x34
	// Line 1146, Address: 0x21766c, Func Offset: 0x3c
	// Line 1187, Address: 0x217680, Func Offset: 0x50
	// Line 1192, Address: 0x217688, Func Offset: 0x58
	// Line 1194, Address: 0x2176b0, Func Offset: 0x80
	// Line 1198, Address: 0x2176b4, Func Offset: 0x84
	// Line 1199, Address: 0x2176c0, Func Offset: 0x90
	// Line 1202, Address: 0x2176c4, Func Offset: 0x94
	// Line 1196, Address: 0x2176c8, Func Offset: 0x98
	// Line 1199, Address: 0x2176cc, Func Offset: 0x9c
	// Line 1200, Address: 0x2176d4, Func Offset: 0xa4
	// Line 1201, Address: 0x2176e0, Func Offset: 0xb0
	// Line 1202, Address: 0x2176e8, Func Offset: 0xb8
	// Line 1203, Address: 0x2176f0, Func Offset: 0xc0
	// Line 1204, Address: 0x217714, Func Offset: 0xe4
	// Line 1205, Address: 0x21771c, Func Offset: 0xec
	// Line 1207, Address: 0x217728, Func Offset: 0xf8
	// Line 1210, Address: 0x217738, Func Offset: 0x108
	// Line 1212, Address: 0x217740, Func Offset: 0x110
	// Line 1214, Address: 0x217750, Func Offset: 0x120
	// Line 1216, Address: 0x217754, Func Offset: 0x124
	// Line 1214, Address: 0x217758, Func Offset: 0x128
	// Line 1216, Address: 0x21775c, Func Offset: 0x12c
	// Line 1217, Address: 0x21777c, Func Offset: 0x14c
	// Line 1218, Address: 0x217788, Func Offset: 0x158
	// Line 1223, Address: 0x2177a0, Func Offset: 0x170
	// Line 1218, Address: 0x2177a8, Func Offset: 0x178
	// Line 1220, Address: 0x2177b0, Func Offset: 0x180
	// Line 1223, Address: 0x2177b8, Func Offset: 0x188
	// Line 1220, Address: 0x2177c0, Func Offset: 0x190
	// Line 1221, Address: 0x2177c8, Func Offset: 0x198
	// Line 1222, Address: 0x2177d8, Func Offset: 0x1a8
	// Line 1223, Address: 0x2177e8, Func Offset: 0x1b8
	// Line 1225, Address: 0x2177fc, Func Offset: 0x1cc
	// Line 1226, Address: 0x217810, Func Offset: 0x1e0
	// Func End, Address: 0x217844, Func Offset: 0x214
}

// 
// Start address: 0x217850
void bhEne_SetNikuhenEffect(BH_PWORK* epw, int type, _anon4* pos, _anon4* v, int tex_id)
{
	int eno;
	// Line 1311, Address: 0x217850, Func Offset: 0
	// Line 1314, Address: 0x217864, Func Offset: 0x14
	// Line 1315, Address: 0x217874, Func Offset: 0x24
	// Line 1314, Address: 0x217878, Func Offset: 0x28
	// Line 1315, Address: 0x217884, Func Offset: 0x34
	// Line 1316, Address: 0x2178a0, Func Offset: 0x50
	// Line 1317, Address: 0x2178b4, Func Offset: 0x64
	// Line 1318, Address: 0x2178cc, Func Offset: 0x7c
	// Line 1319, Address: 0x2178e4, Func Offset: 0x94
	// Line 1320, Address: 0x2178f8, Func Offset: 0xa8
	// Line 1323, Address: 0x21791c, Func Offset: 0xcc
	// Line 1320, Address: 0x217924, Func Offset: 0xd4
	// Line 1323, Address: 0x21793c, Func Offset: 0xec
	// Line 1320, Address: 0x217940, Func Offset: 0xf0
	// Line 1321, Address: 0x217948, Func Offset: 0xf8
	// Line 1322, Address: 0x217968, Func Offset: 0x118
	// Line 1323, Address: 0x21797c, Func Offset: 0x12c
	// Line 1324, Address: 0x217994, Func Offset: 0x144
	// Line 1326, Address: 0x2179a0, Func Offset: 0x150
	// Line 1327, Address: 0x2179c4, Func Offset: 0x174
	// Line 1326, Address: 0x2179d0, Func Offset: 0x180
	// Line 1327, Address: 0x2179d8, Func Offset: 0x188
	// Line 1328, Address: 0x2179dc, Func Offset: 0x18c
	// Line 1327, Address: 0x2179e8, Func Offset: 0x198
	// Line 1329, Address: 0x2179ec, Func Offset: 0x19c
	// Line 1327, Address: 0x2179f4, Func Offset: 0x1a4
	// Line 1328, Address: 0x2179f8, Func Offset: 0x1a8
	// Line 1329, Address: 0x2179fc, Func Offset: 0x1ac
	// Line 1330, Address: 0x217a04, Func Offset: 0x1b4
	// Line 1329, Address: 0x217a0c, Func Offset: 0x1bc
	// Line 1330, Address: 0x217a10, Func Offset: 0x1c0
	// Line 1331, Address: 0x217a18, Func Offset: 0x1c8
	// Line 1330, Address: 0x217a20, Func Offset: 0x1d0
	// Line 1331, Address: 0x217a24, Func Offset: 0x1d4
	// Line 1333, Address: 0x217a30, Func Offset: 0x1e0
	// Func End, Address: 0x217a48, Func Offset: 0x1f8
}

// 
// Start address: 0x217a50
void bhEne_SetNikuhenEffect2(BH_PWORK* epw, int type, _anon4* pos, int n, int tex_id)
{
	int i;
	int angZ;
	int angY;
	_anon4 v2;
	_anon4 v;
	// Line 1358, Address: 0x217a50, Func Offset: 0
	// Line 1363, Address: 0x217a78, Func Offset: 0x28
	// Line 1365, Address: 0x217a94, Func Offset: 0x44
	// Line 1367, Address: 0x217a9c, Func Offset: 0x4c
	// Line 1368, Address: 0x217ab8, Func Offset: 0x68
	// Line 1374, Address: 0x217ac8, Func Offset: 0x78
	// Line 1368, Address: 0x217ad4, Func Offset: 0x84
	// Line 1374, Address: 0x217ad8, Func Offset: 0x88
	// Line 1375, Address: 0x217ae0, Func Offset: 0x90
	// Line 1378, Address: 0x217ae4, Func Offset: 0x94
	// Line 1375, Address: 0x217ae8, Func Offset: 0x98
	// Line 1376, Address: 0x217af0, Func Offset: 0xa0
	// Line 1377, Address: 0x217afc, Func Offset: 0xac
	// Line 1378, Address: 0x217b04, Func Offset: 0xb4
	// Line 1379, Address: 0x217b0c, Func Offset: 0xbc
	// Line 1380, Address: 0x217b1c, Func Offset: 0xcc
	// Line 1381, Address: 0x217b34, Func Offset: 0xe4
	// Line 1382, Address: 0x217b48, Func Offset: 0xf8
	// Func End, Address: 0x217b70, Func Offset: 0x120
}

// 
// Start address: 0x217b70
int bhEne_SetDFireEffect(BH_PWORK* epw, int no, _anon10* ltbl, int type)
{
	int i;
	int fmax;
	int obj_num;
	_anon4 pos;
	_anon4 vec;
	_anon20* owk;
	_anon1* wp;
	_anon1 work[42];
	// Line 1404, Address: 0x217b70, Func Offset: 0
	// Line 1412, Address: 0x217b98, Func Offset: 0x28
	// Line 1413, Address: 0x217bac, Func Offset: 0x3c
	// Line 1416, Address: 0x217bc0, Func Offset: 0x50
	// Line 1417, Address: 0x217bc4, Func Offset: 0x54
	// Line 1422, Address: 0x217bc8, Func Offset: 0x58
	// Line 1419, Address: 0x217bcc, Func Offset: 0x5c
	// Line 1420, Address: 0x217bd0, Func Offset: 0x60
	// Line 1422, Address: 0x217bd4, Func Offset: 0x64
	// Line 1421, Address: 0x217bd8, Func Offset: 0x68
	// Line 1422, Address: 0x217bdc, Func Offset: 0x6c
	// Line 1425, Address: 0x217be4, Func Offset: 0x74
	// Line 1427, Address: 0x217c08, Func Offset: 0x98
	// Line 1428, Address: 0x217c0c, Func Offset: 0x9c
	// Line 1429, Address: 0x217c10, Func Offset: 0xa0
	// Line 1427, Address: 0x217c14, Func Offset: 0xa4
	// Line 1429, Address: 0x217c18, Func Offset: 0xa8
	// Line 1432, Address: 0x217c20, Func Offset: 0xb0
	// Line 1434, Address: 0x217c30, Func Offset: 0xc0
	// Line 1435, Address: 0x217c38, Func Offset: 0xc8
	// Line 1436, Address: 0x217c3c, Func Offset: 0xcc
	// Line 1437, Address: 0x217c40, Func Offset: 0xd0
	// Line 1434, Address: 0x217c44, Func Offset: 0xd4
	// Line 1435, Address: 0x217c4c, Func Offset: 0xdc
	// Line 1436, Address: 0x217c58, Func Offset: 0xe8
	// Line 1437, Address: 0x217c60, Func Offset: 0xf0
	// Line 1438, Address: 0x217c68, Func Offset: 0xf8
	// Line 1441, Address: 0x217c70, Func Offset: 0x100
	// Line 1442, Address: 0x217c7c, Func Offset: 0x10c
	// Line 1445, Address: 0x217c80, Func Offset: 0x110
	// Line 1443, Address: 0x217c84, Func Offset: 0x114
	// Line 1445, Address: 0x217c88, Func Offset: 0x118
	// Line 1448, Address: 0x217c98, Func Offset: 0x128
	// Line 1450, Address: 0x217ca8, Func Offset: 0x138
	// Line 1452, Address: 0x217cb4, Func Offset: 0x144
	// Line 1453, Address: 0x217cb8, Func Offset: 0x148
	// Line 1461, Address: 0x217cbc, Func Offset: 0x14c
	// Line 1464, Address: 0x217cd0, Func Offset: 0x160
	// Line 1466, Address: 0x217ce0, Func Offset: 0x170
	// Line 1467, Address: 0x217cf4, Func Offset: 0x184
	// Line 1469, Address: 0x217d08, Func Offset: 0x198
	// Line 1470, Address: 0x217d0c, Func Offset: 0x19c
	// Func End, Address: 0x217d38, Func Offset: 0x1c8
}

// 
// Start address: 0x217d40
void bhEne_SetDFireEffect2(BH_PWORK* epw, int no, _anon10* ltbl, int type)
{
	_anon41 line;
	int time;
	int eno;
	_anon4 gpos;
	_anon4 ofp;
	// Line 1491, Address: 0x217d40, Func Offset: 0
	// Line 1499, Address: 0x217d5c, Func Offset: 0x1c
	// Line 1503, Address: 0x217d7c, Func Offset: 0x3c
	// Line 1508, Address: 0x217d80, Func Offset: 0x40
	// Line 1517, Address: 0x217d84, Func Offset: 0x44
	// Line 1503, Address: 0x217d8c, Func Offset: 0x4c
	// Line 1504, Address: 0x217d90, Func Offset: 0x50
	// Line 1505, Address: 0x217d98, Func Offset: 0x58
	// Line 1507, Address: 0x217da0, Func Offset: 0x60
	// Line 1508, Address: 0x217da4, Func Offset: 0x64
	// Line 1517, Address: 0x217da8, Func Offset: 0x68
	// Line 1518, Address: 0x217db0, Func Offset: 0x70
	// Line 1519, Address: 0x217dbc, Func Offset: 0x7c
	// Line 1522, Address: 0x217dc4, Func Offset: 0x84
	// Line 1540, Address: 0x217dcc, Func Offset: 0x8c
	// Line 1526, Address: 0x217dd4, Func Offset: 0x94
	// Line 1528, Address: 0x217de0, Func Offset: 0xa0
	// Line 1526, Address: 0x217de4, Func Offset: 0xa4
	// Line 1527, Address: 0x217df0, Func Offset: 0xb0
	// Line 1528, Address: 0x217e04, Func Offset: 0xc4
	// Line 1530, Address: 0x217e18, Func Offset: 0xd8
	// Line 1531, Address: 0x217e2c, Func Offset: 0xec
	// Line 1532, Address: 0x217e40, Func Offset: 0x100
	// Line 1538, Address: 0x217e54, Func Offset: 0x114
	// Line 1542, Address: 0x217e64, Func Offset: 0x124
	// Line 1543, Address: 0x217e80, Func Offset: 0x140
	// Line 1544, Address: 0x217edc, Func Offset: 0x19c
	// Line 1547, Address: 0x217ef0, Func Offset: 0x1b0
	// Line 1548, Address: 0x217f30, Func Offset: 0x1f0
	// Line 1554, Address: 0x217f4c, Func Offset: 0x20c
	// Line 1548, Address: 0x217f50, Func Offset: 0x210
	// Line 1554, Address: 0x217f74, Func Offset: 0x234
	// Line 1556, Address: 0x217f9c, Func Offset: 0x25c
	// Line 1557, Address: 0x217fa4, Func Offset: 0x264
	// Line 1560, Address: 0x217fac, Func Offset: 0x26c
	// Line 1564, Address: 0x217fb4, Func Offset: 0x274
	// Line 1565, Address: 0x217fc0, Func Offset: 0x280
	// Line 1564, Address: 0x217fc4, Func Offset: 0x284
	// Line 1565, Address: 0x217fc8, Func Offset: 0x288
	// Line 1564, Address: 0x217fcc, Func Offset: 0x28c
	// Line 1565, Address: 0x217fd8, Func Offset: 0x298
	// Line 1566, Address: 0x217ff4, Func Offset: 0x2b4
	// Line 1568, Address: 0x218000, Func Offset: 0x2c0
	// Line 1569, Address: 0x218028, Func Offset: 0x2e8
	// Line 1570, Address: 0x218038, Func Offset: 0x2f8
	// Line 1573, Address: 0x21804c, Func Offset: 0x30c
	// Line 1574, Address: 0x218058, Func Offset: 0x318
	// Line 1573, Address: 0x218060, Func Offset: 0x320
	// Line 1574, Address: 0x21806c, Func Offset: 0x32c
	// Line 1575, Address: 0x218088, Func Offset: 0x348
	// Line 1577, Address: 0x218094, Func Offset: 0x354
	// Line 1578, Address: 0x2180bc, Func Offset: 0x37c
	// Line 1579, Address: 0x2180cc, Func Offset: 0x38c
	// Line 1581, Address: 0x2180e0, Func Offset: 0x3a0
	// Func End, Address: 0x218100, Func Offset: 0x3c0
}

// 
// Start address: 0x218100
int bhEne_SetSanEffect(BH_PWORK* epw, int no, _anon10* ltbl)
{
	int i;
	int obj_num;
	_anon4 pos;
	_anon4 vec;
	_anon20* owk;
	_anon1* wp;
	_anon1 work[42];
	// Line 1601, Address: 0x218100, Func Offset: 0
	// Line 1610, Address: 0x218124, Func Offset: 0x24
	// Line 1611, Address: 0x218134, Func Offset: 0x34
	// Line 1614, Address: 0x218148, Func Offset: 0x48
	// Line 1615, Address: 0x21814c, Func Offset: 0x4c
	// Line 1620, Address: 0x218150, Func Offset: 0x50
	// Line 1617, Address: 0x218154, Func Offset: 0x54
	// Line 1618, Address: 0x218158, Func Offset: 0x58
	// Line 1620, Address: 0x21815c, Func Offset: 0x5c
	// Line 1619, Address: 0x218160, Func Offset: 0x60
	// Line 1620, Address: 0x218164, Func Offset: 0x64
	// Line 1623, Address: 0x21816c, Func Offset: 0x6c
	// Line 1625, Address: 0x218190, Func Offset: 0x90
	// Line 1626, Address: 0x218194, Func Offset: 0x94
	// Line 1627, Address: 0x218198, Func Offset: 0x98
	// Line 1625, Address: 0x21819c, Func Offset: 0x9c
	// Line 1627, Address: 0x2181a0, Func Offset: 0xa0
	// Line 1630, Address: 0x2181a8, Func Offset: 0xa8
	// Line 1632, Address: 0x2181b8, Func Offset: 0xb8
	// Line 1633, Address: 0x2181c0, Func Offset: 0xc0
	// Line 1634, Address: 0x2181c4, Func Offset: 0xc4
	// Line 1635, Address: 0x2181c8, Func Offset: 0xc8
	// Line 1632, Address: 0x2181cc, Func Offset: 0xcc
	// Line 1633, Address: 0x2181d4, Func Offset: 0xd4
	// Line 1634, Address: 0x2181e0, Func Offset: 0xe0
	// Line 1635, Address: 0x2181e8, Func Offset: 0xe8
	// Line 1636, Address: 0x2181f0, Func Offset: 0xf0
	// Line 1639, Address: 0x2181f8, Func Offset: 0xf8
	// Line 1640, Address: 0x218204, Func Offset: 0x104
	// Line 1643, Address: 0x218208, Func Offset: 0x108
	// Line 1641, Address: 0x21820c, Func Offset: 0x10c
	// Line 1643, Address: 0x218210, Func Offset: 0x110
	// Line 1646, Address: 0x218220, Func Offset: 0x120
	// Line 1649, Address: 0x218230, Func Offset: 0x130
	// Line 1652, Address: 0x218240, Func Offset: 0x140
	// Line 1654, Address: 0x218248, Func Offset: 0x148
	// Line 1655, Address: 0x218258, Func Offset: 0x158
	// Line 1657, Address: 0x218268, Func Offset: 0x168
	// Line 1658, Address: 0x21826c, Func Offset: 0x16c
	// Func End, Address: 0x218294, Func Offset: 0x194
}

// 
// Start address: 0x2182a0
int bhEne_SetSanEffect2(BH_PWORK* epw, int no, _anon10* ltbl)
{
	_anon4 ofp;
	_anon20* owk;
	// Line 1677, Address: 0x2182a0, Func Offset: 0
	// Line 1683, Address: 0x2182b8, Func Offset: 0x18
	// Line 1684, Address: 0x2182c8, Func Offset: 0x28
	// Line 1683, Address: 0x2182cc, Func Offset: 0x2c
	// Line 1684, Address: 0x2182d8, Func Offset: 0x38
	// Line 1686, Address: 0x2182f4, Func Offset: 0x54
	// Line 1687, Address: 0x218308, Func Offset: 0x68
	// Line 1688, Address: 0x21831c, Func Offset: 0x7c
	// Line 1694, Address: 0x218330, Func Offset: 0x90
	// Line 1695, Address: 0x218340, Func Offset: 0xa0
	// Line 1697, Address: 0x21836c, Func Offset: 0xcc
	// Line 1695, Address: 0x218378, Func Offset: 0xd8
	// Line 1698, Address: 0x21837c, Func Offset: 0xdc
	// Line 1695, Address: 0x218380, Func Offset: 0xe0
	// Line 1698, Address: 0x218384, Func Offset: 0xe4
	// Line 1695, Address: 0x218388, Func Offset: 0xe8
	// Line 1697, Address: 0x21838c, Func Offset: 0xec
	// Line 1700, Address: 0x218394, Func Offset: 0xf4
	// Line 1701, Address: 0x2183f0, Func Offset: 0x150
	// Line 1704, Address: 0x218404, Func Offset: 0x164
	// Line 1705, Address: 0x218444, Func Offset: 0x1a4
	// Line 1711, Address: 0x218460, Func Offset: 0x1c0
	// Line 1710, Address: 0x218464, Func Offset: 0x1c4
	// Line 1711, Address: 0x218468, Func Offset: 0x1c8
	// Line 1705, Address: 0x21846c, Func Offset: 0x1cc
	// Line 1711, Address: 0x218490, Func Offset: 0x1f0
	// Line 1713, Address: 0x2184a0, Func Offset: 0x200
	// Line 1714, Address: 0x2184a8, Func Offset: 0x208
	// Line 1717, Address: 0x2184b0, Func Offset: 0x210
	// Line 1719, Address: 0x2184b8, Func Offset: 0x218
	// Line 1720, Address: 0x2184dc, Func Offset: 0x23c
	// Func End, Address: 0x2184f8, Func Offset: 0x258
}

// 
// Start address: 0x218500
void bhEne_QuickSort(_anon1* a, int first, int last)
{
	float t;
	float x;
	int indx;
	int j;
	int i;
	// Line 1739, Address: 0x218500, Func Offset: 0
	// Line 1744, Address: 0x218518, Func Offset: 0x18
	// Line 1746, Address: 0x218524, Func Offset: 0x24
	// Line 1747, Address: 0x218538, Func Offset: 0x38
	// Line 1748, Address: 0x21853c, Func Offset: 0x3c
	// Line 1752, Address: 0x218544, Func Offset: 0x44
	// Line 1753, Address: 0x218570, Func Offset: 0x70
	// Line 1754, Address: 0x218594, Func Offset: 0x94
	// Line 1755, Address: 0x2185a0, Func Offset: 0xa0
	// Line 1758, Address: 0x2185a8, Func Offset: 0xa8
	// Line 1755, Address: 0x2185b0, Func Offset: 0xb0
	// Line 1756, Address: 0x2185b4, Func Offset: 0xb4
	// Line 1758, Address: 0x2185b8, Func Offset: 0xb8
	// Line 1763, Address: 0x2185bc, Func Offset: 0xbc
	// Line 1764, Address: 0x2185c0, Func Offset: 0xc0
	// Line 1758, Address: 0x2185c4, Func Offset: 0xc4
	// Line 1759, Address: 0x2185c8, Func Offset: 0xc8
	// Line 1761, Address: 0x2185d0, Func Offset: 0xd0
	// Line 1765, Address: 0x2185d4, Func Offset: 0xd4
	// Line 1767, Address: 0x2185dc, Func Offset: 0xdc
	// Line 1768, Address: 0x2185f4, Func Offset: 0xf4
	// Line 1769, Address: 0x218610, Func Offset: 0x110
	// Func End, Address: 0x218628, Func Offset: 0x128
}

// 
// Start address: 0x218630
int bhEne_ChgMtn(BH_PWORK* epw, unsigned int no, int frm, int rate)
{
	// Line 1791, Address: 0x218630, Func Offset: 0
	// Line 1792, Address: 0x218638, Func Offset: 0x8
	// Line 1794, Address: 0x218644, Func Offset: 0x14
	// Line 1795, Address: 0x218648, Func Offset: 0x18
	// Line 1796, Address: 0x21864c, Func Offset: 0x1c
	// Line 1802, Address: 0x218650, Func Offset: 0x20
	// Line 1798, Address: 0x218654, Func Offset: 0x24
	// Line 1802, Address: 0x218658, Func Offset: 0x28
	// Line 1805, Address: 0x21865c, Func Offset: 0x2c
	// Line 1807, Address: 0x218668, Func Offset: 0x38
	// Line 1809, Address: 0x218670, Func Offset: 0x40
	// Line 1805, Address: 0x218674, Func Offset: 0x44
	// Line 1807, Address: 0x21867c, Func Offset: 0x4c
	// Line 1809, Address: 0x218684, Func Offset: 0x54
	// Line 1811, Address: 0x21868c, Func Offset: 0x5c
	// Line 1812, Address: 0x218690, Func Offset: 0x60
	// Func End, Address: 0x218698, Func Offset: 0x68
}

// 
// Start address: 0x2186a0
int bhEne_CollisionCheckWall(BH_PWORK* pw, _anon4* ps, _anon4* pd, float ar, float ah)
{
	unsigned int flg;
	float h;
	float r;
	float z;
	float y;
	float x;
	// Line 1835, Address: 0x2186a0, Func Offset: 0
	// Line 1844, Address: 0x2186cc, Func Offset: 0x2c
	// Line 1845, Address: 0x2186d0, Func Offset: 0x30
	// Line 1846, Address: 0x2186d4, Func Offset: 0x34
	// Line 1847, Address: 0x2186d8, Func Offset: 0x38
	// Line 1848, Address: 0x2186dc, Func Offset: 0x3c
	// Line 1850, Address: 0x2186e0, Func Offset: 0x40
	// Line 1857, Address: 0x2186e4, Func Offset: 0x44
	// Line 1850, Address: 0x2186f4, Func Offset: 0x54
	// Line 1851, Address: 0x2186f8, Func Offset: 0x58
	// Line 1852, Address: 0x218700, Func Offset: 0x60
	// Line 1853, Address: 0x218708, Func Offset: 0x68
	// Line 1854, Address: 0x21870c, Func Offset: 0x6c
	// Line 1856, Address: 0x218710, Func Offset: 0x70
	// Line 1857, Address: 0x218714, Func Offset: 0x74
	// Line 1858, Address: 0x218718, Func Offset: 0x78
	// Line 1859, Address: 0x218720, Func Offset: 0x80
	// Line 1860, Address: 0x218728, Func Offset: 0x88
	// Line 1862, Address: 0x21872c, Func Offset: 0x8c
	// Line 1873, Address: 0x218734, Func Offset: 0x94
	// Line 1862, Address: 0x21873c, Func Offset: 0x9c
	// Line 1863, Address: 0x218744, Func Offset: 0xa4
	// Line 1864, Address: 0x218754, Func Offset: 0xb4
	// Line 1866, Address: 0x218764, Func Offset: 0xc4
	// Line 1867, Address: 0x218768, Func Offset: 0xc8
	// Line 1868, Address: 0x21876c, Func Offset: 0xcc
	// Line 1869, Address: 0x218770, Func Offset: 0xd0
	// Line 1870, Address: 0x218774, Func Offset: 0xd4
	// Line 1873, Address: 0x218778, Func Offset: 0xd8
	// Line 1874, Address: 0x2187a0, Func Offset: 0x100
	// Line 1880, Address: 0x2187ac, Func Offset: 0x10c
	// Line 1881, Address: 0x2187b0, Func Offset: 0x110
	// Func End, Address: 0x2187e0, Func Offset: 0x140
}

// 
// Start address: 0x2187e0
_anon23* bhEne_CollisionCheckWall2(BH_PWORK* pw, _anon4* ps, _anon4* ops, _anon4* pd, float ar, float ah)
{
	unsigned int flg;
	_anon4 pos;
	_anon23* hp;
	// Line 1904, Address: 0x2187e0, Func Offset: 0
	// Line 1915, Address: 0x218810, Func Offset: 0x30
	// Line 1916, Address: 0x218814, Func Offset: 0x34
	// Line 1917, Address: 0x21881c, Func Offset: 0x3c
	// Line 1920, Address: 0x218824, Func Offset: 0x44
	// Line 1915, Address: 0x218828, Func Offset: 0x48
	// Line 1916, Address: 0x21882c, Func Offset: 0x4c
	// Line 1905, Address: 0x218840, Func Offset: 0x60
	// Line 1916, Address: 0x218844, Func Offset: 0x64
	// Line 1917, Address: 0x218848, Func Offset: 0x68
	// Line 1919, Address: 0x218850, Func Offset: 0x70
	// Line 1920, Address: 0x218854, Func Offset: 0x74
	// Line 1923, Address: 0x218858, Func Offset: 0x78
	// Line 1924, Address: 0x218860, Func Offset: 0x80
	// Line 1926, Address: 0x218880, Func Offset: 0xa0
	// Line 1928, Address: 0x218898, Func Offset: 0xb8
	// Line 1930, Address: 0x21889c, Func Offset: 0xbc
	// Line 1934, Address: 0x2188a4, Func Offset: 0xc4
	// Line 1930, Address: 0x2188a8, Func Offset: 0xc8
	// Line 1931, Address: 0x2188b0, Func Offset: 0xd0
	// Line 1932, Address: 0x2188c0, Func Offset: 0xe0
	// Line 1935, Address: 0x2188d0, Func Offset: 0xf0
	// Func End, Address: 0x218904, Func Offset: 0x124
}

// 
// Start address: 0x218910
_anon23* bhEne_CheckDirWall(BH_PWORK* epw, int ang, float step)
{
	_anon23* hp;
	// Line 2021, Address: 0x218914, Func Offset: 0x4
	// Func End, Address: 0x21891c, Func Offset: 0xc
}

// 
// Start address: 0x218920
_anon23* bhEne_CheckDirWall2(BH_PWORK* epw, int ang, float step)
{
	_anon23* hp;
	_anon4 ps;
	// Line 2042, Address: 0x218920, Func Offset: 0
	// Line 2046, Address: 0x218928, Func Offset: 0x8
	// Line 2050, Address: 0x218934, Func Offset: 0x14
	// Line 2046, Address: 0x218938, Func Offset: 0x18
	// Line 2047, Address: 0x218940, Func Offset: 0x20
	// Line 2048, Address: 0x218950, Func Offset: 0x30
	// Line 2050, Address: 0x218954, Func Offset: 0x34
	// Line 2053, Address: 0x21895c, Func Offset: 0x3c
	// Func End, Address: 0x218968, Func Offset: 0x48
}

// 
// Start address: 0x218970
_anon23* bhEne_CheckDirWall3(BH_PWORK* epw, _anon4* pos, int ang, float step)
{
	_anon23* hp;
	_anon4 ps;
	// Line 2074, Address: 0x218970, Func Offset: 0
	// Line 2078, Address: 0x218988, Func Offset: 0x18
	// Line 2079, Address: 0x2189a0, Func Offset: 0x30
	// Line 2080, Address: 0x2189ac, Func Offset: 0x3c
	// Line 2079, Address: 0x2189b0, Func Offset: 0x40
	// Line 2080, Address: 0x2189b8, Func Offset: 0x48
	// Line 2081, Address: 0x2189d0, Func Offset: 0x60
	// Line 2083, Address: 0x2189d8, Func Offset: 0x68
	// Line 2094, Address: 0x2189ec, Func Offset: 0x7c
	// Func End, Address: 0x218a08, Func Offset: 0x98
}

// 
// Start address: 0x218a10
int bhEne_CheckSideWall(BH_PWORK* epw, float step, int both)
{
	// Line 2115, Address: 0x218a14, Func Offset: 0x4
	// Func End, Address: 0x218a1c, Func Offset: 0xc
}

// 
// Start address: 0x218a20
int bhEne_CheckSideWall2(BH_PWORK* epw, float step, int both)
{
	_anon4 pos;
	// Line 2136, Address: 0x218a20, Func Offset: 0
	// Line 2139, Address: 0x218a28, Func Offset: 0x8
	// Line 2142, Address: 0x218a34, Func Offset: 0x14
	// Line 2139, Address: 0x218a38, Func Offset: 0x18
	// Line 2140, Address: 0x218a40, Func Offset: 0x20
	// Line 2141, Address: 0x218a50, Func Offset: 0x30
	// Line 2142, Address: 0x218a54, Func Offset: 0x34
	// Line 2143, Address: 0x218a5c, Func Offset: 0x3c
	// Func End, Address: 0x218a68, Func Offset: 0x48
}

// 
// Start address: 0x218a70
int bhEne_CheckSideWall3(BH_PWORK* epw, _anon4* pos, float step, int both)
{
	int lhit;
	int rhit;
	// Line 2165, Address: 0x218a70, Func Offset: 0
	// Line 2170, Address: 0x218a94, Func Offset: 0x24
	// Line 2168, Address: 0x218aa4, Func Offset: 0x34
	// Line 2170, Address: 0x218aa8, Func Offset: 0x38
	// Line 2172, Address: 0x218ab8, Func Offset: 0x48
	// Line 2174, Address: 0x218abc, Func Offset: 0x4c
	// Line 2176, Address: 0x218ad8, Func Offset: 0x68
	// Line 2179, Address: 0x218adc, Func Offset: 0x6c
	// Line 2180, Address: 0x218aec, Func Offset: 0x7c
	// Line 2182, Address: 0x218af4, Func Offset: 0x84
	// Line 2183, Address: 0x218af8, Func Offset: 0x88
	// Func End, Address: 0x218b1c, Func Offset: 0xac
}

// 
// Start address: 0x218b20
void bhEne_SetVibration(int no)
{
	// Line 2201, Address: 0x218b20, Func Offset: 0
	// Line 2202, Address: 0x218b24, Func Offset: 0x4
	// Line 2205, Address: 0x218b4c, Func Offset: 0x2c
	// Line 2206, Address: 0x218b58, Func Offset: 0x38
	// Line 2209, Address: 0x218b60, Func Offset: 0x40
	// Line 2210, Address: 0x218b6c, Func Offset: 0x4c
	// Line 2213, Address: 0x218b74, Func Offset: 0x54
	// Line 2216, Address: 0x218b80, Func Offset: 0x60
	// Func End, Address: 0x218b8c, Func Offset: 0x6c
}

// 
// Start address: 0x218b90
void bhEne_PlayerSePlay(BH_PWORK* epw, int no)
{
	// Line 2235, Address: 0x218b90, Func Offset: 0
	// Line 2236, Address: 0x218b98, Func Offset: 0x8
	// Line 2238, Address: 0x218bac, Func Offset: 0x1c
	// Line 2239, Address: 0x218bb4, Func Offset: 0x24
	// Func End, Address: 0x218bc0, Func Offset: 0x30
}

// 
// Start address: 0x218bc0
void bhEne_HitCheckParts(BH_PWORK* pp, _anon4* pos)
{
	int i;
	float slen;
	float len;
	_anon4 vec;
	_anon20* owk;
	// Line 2260, Address: 0x218bc0, Func Offset: 0
	// Line 2266, Address: 0x218be8, Func Offset: 0x28
	// Line 2268, Address: 0x218bec, Func Offset: 0x2c
	// Line 2272, Address: 0x218bf4, Func Offset: 0x34
	// Line 2266, Address: 0x218bfc, Func Offset: 0x3c
	// Line 2272, Address: 0x218c00, Func Offset: 0x40
	// Line 2274, Address: 0x218c08, Func Offset: 0x48
	// Line 2275, Address: 0x218c10, Func Offset: 0x50
	// Line 2276, Address: 0x218c14, Func Offset: 0x54
	// Line 2277, Address: 0x218c18, Func Offset: 0x58
	// Line 2274, Address: 0x218c1c, Func Offset: 0x5c
	// Line 2275, Address: 0x218c24, Func Offset: 0x64
	// Line 2276, Address: 0x218c34, Func Offset: 0x74
	// Line 2277, Address: 0x218c40, Func Offset: 0x80
	// Line 2279, Address: 0x218c48, Func Offset: 0x88
	// Line 2284, Address: 0x218c78, Func Offset: 0xb8
	// Line 2285, Address: 0x218c7c, Func Offset: 0xbc
	// Line 2286, Address: 0x218c80, Func Offset: 0xc0
	// Line 2287, Address: 0x218c8c, Func Offset: 0xcc
	// Line 2288, Address: 0x218c98, Func Offset: 0xd8
	// Line 2289, Address: 0x218ca4, Func Offset: 0xe4
	// Line 2290, Address: 0x218ca8, Func Offset: 0xe8
	// Line 2291, Address: 0x218cac, Func Offset: 0xec
	// Line 2292, Address: 0x218cc8, Func Offset: 0x108
	// Line 2293, Address: 0x218cd0, Func Offset: 0x110
	// Line 2294, Address: 0x218cd8, Func Offset: 0x118
	// Line 2295, Address: 0x218ce0, Func Offset: 0x120
	// Func End, Address: 0x218d08, Func Offset: 0x148
}

