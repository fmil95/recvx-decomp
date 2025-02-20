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
typedef union _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct _anon23;
typedef struct _anon24;
typedef struct _anon25;
typedef struct _anon26;
typedef struct _anon27;
typedef struct BH_PWORK;
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

typedef unsigned char(*type_62)(_anon5*);
typedef void(*type_87)(void*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef _anon0* type_2[32];
typedef _anon3* type_3[16];
typedef _anon0* type_4[32];
typedef _anon0* type_5[512];
typedef _anon3* type_6[16][16];
typedef _anon3* type_7[16][16][100];
typedef char type_8[8];
typedef _anon0* type_9[32];
typedef _anon0* type_10[512];
typedef _anon3* type_11[1300];
typedef char type_12[32];
typedef _anon0* type_13[512];
typedef _anon3* type_14[200];
typedef short type_15[32];
typedef _anon20 type_16[1];
typedef _anon0* type_17[128];
typedef unsigned int type_18[1];
typedef _anon9 type_19[256];
typedef _anon3* type_20[8];
typedef int* type_21[16];
typedef _anon0* type_22[128];
typedef npobj* type_23[16];
typedef _anon0* type_24[128];
typedef int type_25[4];
typedef _anon3* type_26[16];
typedef unsigned int type_27[4];
typedef _anon12 type_28[16];
typedef _anon0* type_29[512];
typedef char type_30[256];
typedef float type_31[4];
typedef float type_32[4];
typedef float type_33[4];
typedef _anon7* type_34[128];
typedef unsigned char type_35[64];
typedef float type_36[16];
typedef int type_37[3];
typedef char type_38[8];
typedef _anon30 type_39[2];
typedef void* type_40[2];
typedef _anon41 type_41[0];
typedef _anon3* type_42[256];
typedef int type_43[4];
typedef unsigned char* type_44[256];
typedef unsigned int type_45[2];
typedef short type_46[256];
typedef unsigned int type_47[168];
typedef _anon28 type_48[4];
typedef float type_49[3];
typedef short type_50[256];
typedef int type_51[3];
typedef int type_52[8];
typedef float type_53[3];
typedef _anon3* type_54[256];
typedef _anon11 type_55[256];
typedef int type_56[3];
typedef _anon6 type_57[0];
typedef _anon20 type_58[450];
typedef short type_59[6];
typedef short type_60[6][0];
typedef unsigned char type_61[3];
typedef unsigned char(*type_63)(_anon5*)[3];
typedef _anon30 type_64[16];
typedef short type_65[256];
typedef unsigned char type_66[8];
typedef char type_67[3];
typedef unsigned char type_68[8][0];
typedef int type_69[64];
typedef _anon12 type_70[450];
typedef _anon20 type_71[1];
typedef unsigned short type_72[0];
typedef _anon20 type_73[1];
typedef _anon36 type_74[4];
typedef _anon4 type_75[4];
typedef int type_76[450];
typedef unsigned short type_77[0];
typedef unsigned int type_78[8];
typedef unsigned char type_79[450];
typedef int type_80[3];
typedef unsigned short type_81[0];
typedef _anon23 type_82[0];
typedef _anon32 type_83[4];
typedef char type_84[16];
typedef _anon32 type_85[0];
typedef char type_86[4];
typedef unsigned int type_88[32];
typedef float type_89[3];
typedef unsigned int type_90[16];
typedef _anon18 type_91[4];
typedef _anon39 type_92[64];
typedef unsigned int type_93[16];
typedef float type_94[3];
typedef _anon39 type_95[64];
typedef unsigned int type_96[32];
typedef _anon39 type_97[64];
typedef unsigned int type_98[16];
typedef unsigned int type_99[3];
typedef BH_PWORK* type_100[16];
typedef unsigned int type_101[8];
typedef short type_102[16];
typedef unsigned int type_103[1];
typedef unsigned int type_104[384];
typedef unsigned int type_105[2];
typedef short type_106[16];
typedef unsigned char type_107[2];
typedef int* type_108[16];
typedef unsigned int type_109[4];
typedef char type_110[32];
typedef npobj* type_111[16];
typedef char type_112[64];
typedef _anon3* type_113[16];
typedef char type_114[4];
typedef _anon12 type_115[16];
typedef short type_116[4];
typedef _anon20 type_117[5];
typedef int type_118[3];
typedef unsigned char type_119[4];
typedef _anon34 type_120[16];
typedef unsigned int type_121[32];
typedef _anon32 type_122[32];
typedef _anon0* type_123[512];
typedef _anon0* type_124[128];
typedef _anon0* type_125[512];
typedef unsigned char type_126[64];
typedef _anon0* type_127[512];

struct npobj
{
	unsigned int evalflags;
	_anon29* model;
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
	_anon36* pvp;
	_anon4* tvp;
	_anon36 pv[4];
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
	float cmat1[16];
	float rotmat[16];
	_anon32 pos_0;
	_anon32 pos_1;
	int ax;
	int ay;
	int az;
	int cax;
	int cay;
	int caz;
	float dis;
	float Dummy[3];
};

struct _anon2
{
	_anon20 subtx[5];
	_anon3 subtx_list;
	unsigned short subscreenmode;
	unsigned int statusflg;
	unsigned short testmode;
	unsigned int itmwrk;
	unsigned int itemid;
	unsigned short cmbitm;
	short open1;
	short open2;
	unsigned short mode;
	short ips1;
	short ipsdisp;
	unsigned int listcsr_0;
	unsigned int listcsr_1;
	unsigned int listcsr_2;
	unsigned int listcsr_3;
	float color00;
	unsigned short colorcount;
	unsigned short colorflg;
	unsigned char maincsr;
	unsigned char subcsr;
	unsigned int* pip;
	unsigned int* bxp;
	unsigned int* gb;
	unsigned char* ssp;
	char wait_;
	char wait;
	char number;
	char flag;
	unsigned char hp;
	unsigned char abc;
	unsigned char dnum;
	char dflg;
	unsigned char keywait;
	unsigned char boxwait;
	short actioncount;
	_anon8 scr;
	_anon30 clip[2];
	unsigned char flgchk;
	unsigned char flgtest;
	unsigned char* sspb;
	unsigned char sprflg;
	char number_;
	char flag_;
	unsigned short mesid;
	unsigned short taskloop;
	unsigned short wn;
	unsigned short wn_num;
	unsigned char* subp;
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
	_anon12 mdl;
	_anon31 mw;
	unsigned char* keep;
	unsigned char* keepbackup;
};

struct _anon6
{
	short ax;
	short ay;
	short az;
	short hide;
};

struct _anon7
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon19* md2P;
	unsigned short* atrP;
};

struct _anon8
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
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

struct _anon11
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon12
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon3* texP;
	_anon26* owP;
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
	_anon42* info;
};

struct _anon14
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

struct _anon15
{
	short u;
	short v;
};

struct _anon16
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct _anon17
{
	void* texaddr;
	_anon10 texsurface;
};

union _anon18
{
	unsigned int color;
	_anon15 tex;
	_anon16 argb;
};

struct _anon19
{
	void* p[2];
};

struct _anon20
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon21
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon22
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
	_anon27* light;
};

struct _anon23
{
	unsigned short max;
	short cmb;
	unsigned short type;
};

struct _anon24
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
	_anon32 ply_pos;
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
	_anon11 txbp[256];
	unsigned char* ef_psp;
	_anon20 ef_tex[450];
	_anon3 ef_tlist;
	_anon37 ef;
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
	_anon17 ren_info;
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
	_anon22* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon28 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon30 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon39* pl_htp;
	int costume;
	_anon32 hd_pos;
	_anon32 apos;
	_anon39* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon39 mwalp[64];
	_anon39 metcp[64];
	_anon39 mflrp[64];
	int dla_n;
	_anon39* htp;
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
	_anon14 door;
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
	_anon32 ufo_pos;
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
	_anon32 ghtp[32];
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

struct _anon25
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon26
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon27
{
	float mtrx[16];
	_anon32 pnt;
	_anon32 vctr;
	int stat;
	int reserve;
	_anon35 ltcal;
	_anon43 attr;
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
	_anon21* cpcl;
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

struct _anon28
{
	_anon32 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon29
{
	int* vlist;
	short* plist;
	_anon32 center;
	float r;
};

struct _anon30
{
	float x;
	float y;
};

struct _anon31
{
	_anon32 pos;
	void* tex_p;
	void* mdl_p;
	int ang[3];
	int rdid;
	int ax1;
	int ay1;
	int az1;
	unsigned short flg;
};

struct _anon32
{
	float x;
	float y;
	float z;
};

struct _anon33
{
	_anon25 col;
	_anon20 fstx[1];
	_anon3 fstx_list;
	_anon20 fbtx[1];
	_anon3 fbtx_list;
	int afsmode;
	int ang00;
	int mode_00;
	int mode_01;
	int mode_02;
	int mode_03;
	unsigned int page;
	int rdsz;
	int tag;
	int move;
	unsigned int part_id;
	int filenum;
	int pagewait00;
	int pagewait01;
	short bufnum;
	short filecsr;
	short roll;
	short j;
	short k;
	short z;
	short koma[16];
	short koma2[16];
	unsigned char scrol;
	unsigned char scrolcnt;
	unsigned char flg;
	unsigned char* fsp;
	unsigned char* fspr;
	unsigned char* fspl;
	unsigned short tex_flg;
};

struct _anon34
{
	_anon32 c1;
	_anon32 c2;
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
	_anon32 lpnt;
	_anon32 lvctr;
	_anon32 lmvctr;
	_anon25 atten;
	_anon25 amb;
	_anon25 dif;
	_anon25 spc;
	_anon25 mamb;
	_anon25 mdif;
	_anon25 mspc;
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
	_anon32* p;
	_anon18* col;
	_anon18* tex;
	unsigned int num;
};

struct _anon39
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
	float pos[3];
	short ang;
	unsigned char atr;
	char anim;
	unsigned char cen_no;
	unsigned char parts_num;
	float move;
	unsigned char setnum;
	_anon25 col;
	unsigned char color;
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
	_anon25 argb;
};

struct _anon44
{
	_anon32 c;
	float r;
};

struct _anon45
{
	_anon32 c1;
	_anon32 c2;
	float r;
};

unsigned char(*actionprg)(_anon5*)[3];
unsigned int* wp_;
unsigned char flg[3];
int ang_00[3];
int ang_01[3];
int ang_02[3];
_anon32 vec_00;
float check[16];
float testf;
_anon32 whd;
unsigned int ItemViewTypeTbl[168];
int ViewType;
_anon33 fvwork;
_anon1 st_cam;
_anon6 dsptbl[0];
_anon2 swork;
_anon24* sys;
_anon5 sitem;
_anon32 hoseipos[0];
unsigned char itemflg[8][0];
unsigned short getmestbl[0];
_anon23 itemdata[0];
unsigned short mestbl[0];
short c_a[6][0];
_anon41 parts_10b[0];
unsigned short idsettbl[0];

void DrawSubItem(_anon2* st, _anon5* si);
void Model_Read_Start();
void Model_Read_Set(_anon2* st);
void CameraInit();
void CameraSet();
void ItemView();
void ItemModelChangeZoomIn();
void ItemModelCheck();
void ItemModelActionSet();
void ItemModelChangeZoomOut();
void ItemModelMessageWait();
unsigned char MdlDirChk(short* dirang, short mdlang);
unsigned char MdlAction00(_anon5* si);
unsigned char MdlAction01(_anon5* si);
unsigned char MdlAction02(_anon5* si);
void MdlEvalflagsSet(unsigned short evalchk);
void MdlHideCheck(npobj* op, unsigned char el, unsigned char chk);
float ModelScaleSet(_anon5* itemmodel, unsigned short flg);
void FlagErase(npobj* op);
void LighterOpen(npobj* op);
void FileSyu(npobj* op);
void MakeTag(unsigned short flg);

// 
// Start address: 0x2a9870
void DrawSubItem(_anon2* st, _anon5* si)
{
	_anon32 pos00;
	_anon6* dw_a;
	_anon33* fv;
	_anon1* sc;
	float testtest[16];
	// Line 173, Address: 0x2a9870, Func Offset: 0
	// Line 184, Address: 0x2a988c, Func Offset: 0x1c
	// Line 187, Address: 0x2a9894, Func Offset: 0x24
	// Line 185, Address: 0x2a9898, Func Offset: 0x28
	// Line 187, Address: 0x2a98a0, Func Offset: 0x30
	// Line 213, Address: 0x2a98b8, Func Offset: 0x48
	// Line 214, Address: 0x2a98c0, Func Offset: 0x50
	// Line 216, Address: 0x2a98d0, Func Offset: 0x60
	// Line 218, Address: 0x2a98d8, Func Offset: 0x68
	// Line 221, Address: 0x2a9910, Func Offset: 0xa0
	// Line 222, Address: 0x2a9918, Func Offset: 0xa8
	// Line 223, Address: 0x2a994c, Func Offset: 0xdc
	// Line 224, Address: 0x2a9980, Func Offset: 0x110
	// Line 225, Address: 0x2a99b4, Func Offset: 0x144
	// Line 227, Address: 0x2a99bc, Func Offset: 0x14c
	// Line 228, Address: 0x2a99c8, Func Offset: 0x158
	// Line 229, Address: 0x2a99d4, Func Offset: 0x164
	// Line 230, Address: 0x2a99e0, Func Offset: 0x170
	// Line 232, Address: 0x2a99e8, Func Offset: 0x178
	// Line 234, Address: 0x2a99f0, Func Offset: 0x180
	// Line 235, Address: 0x2a9a00, Func Offset: 0x190
	// Line 236, Address: 0x2a9a0c, Func Offset: 0x19c
	// Line 237, Address: 0x2a9a18, Func Offset: 0x1a8
	// Line 238, Address: 0x2a9a24, Func Offset: 0x1b4
	// Line 239, Address: 0x2a9a38, Func Offset: 0x1c8
	// Line 240, Address: 0x2a9a44, Func Offset: 0x1d4
	// Line 241, Address: 0x2a9a50, Func Offset: 0x1e0
	// Line 242, Address: 0x2a9a5c, Func Offset: 0x1ec
	// Line 243, Address: 0x2a9a64, Func Offset: 0x1f4
	// Line 244, Address: 0x2a9a70, Func Offset: 0x200
	// Line 245, Address: 0x2a9a7c, Func Offset: 0x20c
	// Line 249, Address: 0x2a9a88, Func Offset: 0x218
	// Line 250, Address: 0x2a9a94, Func Offset: 0x224
	// Line 251, Address: 0x2a9a9c, Func Offset: 0x22c
	// Line 252, Address: 0x2a9aa8, Func Offset: 0x238
	// Line 254, Address: 0x2a9ab0, Func Offset: 0x240
	// Line 255, Address: 0x2a9aec, Func Offset: 0x27c
	// Line 256, Address: 0x2a9b24, Func Offset: 0x2b4
	// Line 258, Address: 0x2a9b60, Func Offset: 0x2f0
	// Line 259, Address: 0x2a9b6c, Func Offset: 0x2fc
	// Line 260, Address: 0x2a9b78, Func Offset: 0x308
	// Line 262, Address: 0x2a9b84, Func Offset: 0x314
	// Line 272, Address: 0x2a9b8c, Func Offset: 0x31c
	// Line 262, Address: 0x2a9b94, Func Offset: 0x324
	// Line 263, Address: 0x2a9bb8, Func Offset: 0x348
	// Line 264, Address: 0x2a9be4, Func Offset: 0x374
	// Line 272, Address: 0x2a9c0c, Func Offset: 0x39c
	// Line 273, Address: 0x2a9c30, Func Offset: 0x3c0
	// Line 274, Address: 0x2a9c58, Func Offset: 0x3e8
	// Line 276, Address: 0x2a9c80, Func Offset: 0x410
	// Line 280, Address: 0x2a9c88, Func Offset: 0x418
	// Line 276, Address: 0x2a9c8c, Func Offset: 0x41c
	// Line 277, Address: 0x2a9cb0, Func Offset: 0x440
	// Line 278, Address: 0x2a9cdc, Func Offset: 0x46c
	// Line 280, Address: 0x2a9d04, Func Offset: 0x494
	// Line 282, Address: 0x2a9d0c, Func Offset: 0x49c
	// Line 283, Address: 0x2a9d20, Func Offset: 0x4b0
	// Line 285, Address: 0x2a9d2c, Func Offset: 0x4bc
	// Line 286, Address: 0x2a9d34, Func Offset: 0x4c4
	// Line 287, Address: 0x2a9d3c, Func Offset: 0x4cc
	// Line 288, Address: 0x2a9d44, Func Offset: 0x4d4
	// Line 300, Address: 0x2a9d4c, Func Offset: 0x4dc
	// Line 301, Address: 0x2a9d54, Func Offset: 0x4e4
	// Line 302, Address: 0x2a9d6c, Func Offset: 0x4fc
	// Line 303, Address: 0x2a9d84, Func Offset: 0x514
	// Line 304, Address: 0x2a9da0, Func Offset: 0x530
	// Line 305, Address: 0x2a9db8, Func Offset: 0x548
	// Line 307, Address: 0x2a9dc0, Func Offset: 0x550
	// Line 309, Address: 0x2a9dc8, Func Offset: 0x558
	// Line 310, Address: 0x2a9dd0, Func Offset: 0x560
	// Line 312, Address: 0x2a9ddc, Func Offset: 0x56c
	// Line 313, Address: 0x2a9de8, Func Offset: 0x578
	// Line 314, Address: 0x2a9df4, Func Offset: 0x584
	// Line 316, Address: 0x2a9e00, Func Offset: 0x590
	// Line 317, Address: 0x2a9e08, Func Offset: 0x598
	// Line 318, Address: 0x2a9e1c, Func Offset: 0x5ac
	// Line 319, Address: 0x2a9e2c, Func Offset: 0x5bc
	// Line 320, Address: 0x2a9e48, Func Offset: 0x5d8
	// Line 321, Address: 0x2a9e50, Func Offset: 0x5e0
	// Line 323, Address: 0x2a9e68, Func Offset: 0x5f8
	// Line 325, Address: 0x2a9e74, Func Offset: 0x604
	// Line 326, Address: 0x2a9e84, Func Offset: 0x614
	// Line 327, Address: 0x2a9e8c, Func Offset: 0x61c
	// Line 328, Address: 0x2a9eac, Func Offset: 0x63c
	// Line 329, Address: 0x2a9eb8, Func Offset: 0x648
	// Line 330, Address: 0x2a9ec0, Func Offset: 0x650
	// Line 331, Address: 0x2a9ed4, Func Offset: 0x664
	// Line 332, Address: 0x2a9ee8, Func Offset: 0x678
	// Line 333, Address: 0x2a9efc, Func Offset: 0x68c
	// Line 334, Address: 0x2a9f14, Func Offset: 0x6a4
	// Line 335, Address: 0x2a9f1c, Func Offset: 0x6ac
	// Line 336, Address: 0x2a9f30, Func Offset: 0x6c0
	// Line 337, Address: 0x2a9f3c, Func Offset: 0x6cc
	// Line 343, Address: 0x2a9f48, Func Offset: 0x6d8
	// Line 345, Address: 0x2a9f58, Func Offset: 0x6e8
	// Line 347, Address: 0x2a9f68, Func Offset: 0x6f8
	// Line 349, Address: 0x2a9f74, Func Offset: 0x704
	// Line 350, Address: 0x2a9f7c, Func Offset: 0x70c
	// Line 351, Address: 0x2a9fa0, Func Offset: 0x730
	// Line 352, Address: 0x2a9fac, Func Offset: 0x73c
	// Line 353, Address: 0x2a9fb4, Func Offset: 0x744
	// Line 354, Address: 0x2a9fcc, Func Offset: 0x75c
	// Line 355, Address: 0x2a9fe4, Func Offset: 0x774
	// Line 356, Address: 0x2a9ffc, Func Offset: 0x78c
	// Line 359, Address: 0x2aa018, Func Offset: 0x7a8
	// Line 360, Address: 0x2aa020, Func Offset: 0x7b0
	// Line 361, Address: 0x2aa034, Func Offset: 0x7c4
	// Line 362, Address: 0x2aa044, Func Offset: 0x7d4
	// Line 369, Address: 0x2aa050, Func Offset: 0x7e0
	// Line 372, Address: 0x2aa064, Func Offset: 0x7f4
	// Line 375, Address: 0x2aa078, Func Offset: 0x808
	// Line 377, Address: 0x2aa084, Func Offset: 0x814
	// Line 378, Address: 0x2aa08c, Func Offset: 0x81c
	// Line 379, Address: 0x2aa0b0, Func Offset: 0x840
	// Line 380, Address: 0x2aa0bc, Func Offset: 0x84c
	// Line 381, Address: 0x2aa0c4, Func Offset: 0x854
	// Line 382, Address: 0x2aa0e0, Func Offset: 0x870
	// Line 383, Address: 0x2aa0fc, Func Offset: 0x88c
	// Line 384, Address: 0x2aa118, Func Offset: 0x8a8
	// Line 387, Address: 0x2aa138, Func Offset: 0x8c8
	// Line 388, Address: 0x2aa140, Func Offset: 0x8d0
	// Line 389, Address: 0x2aa154, Func Offset: 0x8e4
	// Line 390, Address: 0x2aa164, Func Offset: 0x8f4
	// Line 398, Address: 0x2aa170, Func Offset: 0x900
	// Line 401, Address: 0x2aa188, Func Offset: 0x918
	// Line 404, Address: 0x2aa1a0, Func Offset: 0x930
	// Line 406, Address: 0x2aa1ac, Func Offset: 0x93c
	// Line 409, Address: 0x2aa1b4, Func Offset: 0x944
	// Line 423, Address: 0x2aa1d4, Func Offset: 0x964
	// Line 425, Address: 0x2aa1dc, Func Offset: 0x96c
	// Line 428, Address: 0x2aa204, Func Offset: 0x994
	// Line 429, Address: 0x2aa22c, Func Offset: 0x9bc
	// Line 430, Address: 0x2aa234, Func Offset: 0x9c4
	// Line 431, Address: 0x2aa23c, Func Offset: 0x9cc
	// Line 435, Address: 0x2aa244, Func Offset: 0x9d4
	// Line 436, Address: 0x2aa250, Func Offset: 0x9e0
	// Line 437, Address: 0x2aa258, Func Offset: 0x9e8
	// Line 440, Address: 0x2aa260, Func Offset: 0x9f0
	// Func End, Address: 0x2aa280, Func Offset: 0xa10
}

// 
// Start address: 0x2aa280
void Model_Read_Start()
{
	_anon5* si;
	// Line 448, Address: 0x2aa280, Func Offset: 0
	// Line 444, Address: 0x2aa288, Func Offset: 0x8
	// Line 448, Address: 0x2aa28c, Func Offset: 0xc
	// Line 450, Address: 0x2aa298, Func Offset: 0x18
	// Line 453, Address: 0x2aa2a4, Func Offset: 0x24
	// Line 450, Address: 0x2aa2a8, Func Offset: 0x28
	// Line 451, Address: 0x2aa2b4, Func Offset: 0x34
	// Line 452, Address: 0x2aa2cc, Func Offset: 0x4c
	// Line 453, Address: 0x2aa2e0, Func Offset: 0x60
	// Line 454, Address: 0x2aa2f8, Func Offset: 0x78
	// Line 455, Address: 0x2aa304, Func Offset: 0x84
	// Line 458, Address: 0x2aa310, Func Offset: 0x90
	// Line 459, Address: 0x2aa32c, Func Offset: 0xac
	// Line 460, Address: 0x2aa33c, Func Offset: 0xbc
	// Line 461, Address: 0x2aa344, Func Offset: 0xc4
	// Line 462, Address: 0x2aa35c, Func Offset: 0xdc
	// Line 463, Address: 0x2aa374, Func Offset: 0xf4
	// Line 464, Address: 0x2aa394, Func Offset: 0x114
	// Line 467, Address: 0x2aa3a8, Func Offset: 0x128
	// Func End, Address: 0x2aa3b0, Func Offset: 0x130
}

// 
// Start address: 0x2aa3b0
void Model_Read_Set(_anon2* st)
{
	_anon6* dw;
	_anon5* si;
	// Line 471, Address: 0x2aa3b0, Func Offset: 0
	// Line 472, Address: 0x2aa3c4, Func Offset: 0x14
	// Line 478, Address: 0x2aa3cc, Func Offset: 0x1c
	// Line 480, Address: 0x2aa3e0, Func Offset: 0x30
	// Line 481, Address: 0x2aa3ec, Func Offset: 0x3c
	// Line 482, Address: 0x2aa3fc, Func Offset: 0x4c
	// Line 484, Address: 0x2aa40c, Func Offset: 0x5c
	// Line 485, Address: 0x2aa418, Func Offset: 0x68
	// Line 484, Address: 0x2aa41c, Func Offset: 0x6c
	// Line 485, Address: 0x2aa428, Func Offset: 0x78
	// Line 486, Address: 0x2aa438, Func Offset: 0x88
	// Line 487, Address: 0x2aa440, Func Offset: 0x90
	// Line 489, Address: 0x2aa444, Func Offset: 0x94
	// Line 490, Address: 0x2aa454, Func Offset: 0xa4
	// Line 494, Address: 0x2aa458, Func Offset: 0xa8
	// Line 497, Address: 0x2aa460, Func Offset: 0xb0
	// Line 494, Address: 0x2aa464, Func Offset: 0xb4
	// Line 497, Address: 0x2aa46c, Func Offset: 0xbc
	// Line 499, Address: 0x2aa474, Func Offset: 0xc4
	// Line 501, Address: 0x2aa488, Func Offset: 0xd8
	// Line 502, Address: 0x2aa4a8, Func Offset: 0xf8
	// Line 505, Address: 0x2aa4c4, Func Offset: 0x114
	// Line 509, Address: 0x2aa4ec, Func Offset: 0x13c
	// Line 510, Address: 0x2aa520, Func Offset: 0x170
	// Line 509, Address: 0x2aa52c, Func Offset: 0x17c
	// Line 510, Address: 0x2aa530, Func Offset: 0x180
	// Line 511, Address: 0x2aa534, Func Offset: 0x184
	// Line 510, Address: 0x2aa540, Func Offset: 0x190
	// Line 511, Address: 0x2aa544, Func Offset: 0x194
	// Line 514, Address: 0x2aa54c, Func Offset: 0x19c
	// Line 515, Address: 0x2aa550, Func Offset: 0x1a0
	// Line 516, Address: 0x2aa554, Func Offset: 0x1a4
	// Line 520, Address: 0x2aa558, Func Offset: 0x1a8
	// Line 521, Address: 0x2aa568, Func Offset: 0x1b8
	// Line 522, Address: 0x2aa580, Func Offset: 0x1d0
	// Line 523, Address: 0x2aa58c, Func Offset: 0x1dc
	// Line 524, Address: 0x2aa598, Func Offset: 0x1e8
	// Line 525, Address: 0x2aa5a0, Func Offset: 0x1f0
	// Line 523, Address: 0x2aa5a4, Func Offset: 0x1f4
	// Line 524, Address: 0x2aa5b0, Func Offset: 0x200
	// Line 525, Address: 0x2aa5c4, Func Offset: 0x214
	// Line 527, Address: 0x2aa5d4, Func Offset: 0x224
	// Line 528, Address: 0x2aa5dc, Func Offset: 0x22c
	// Line 529, Address: 0x2aa600, Func Offset: 0x250
	// Line 530, Address: 0x2aa60c, Func Offset: 0x25c
	// Line 531, Address: 0x2aa61c, Func Offset: 0x26c
	// Line 532, Address: 0x2aa620, Func Offset: 0x270
	// Line 530, Address: 0x2aa624, Func Offset: 0x274
	// Line 531, Address: 0x2aa630, Func Offset: 0x280
	// Line 533, Address: 0x2aa638, Func Offset: 0x288
	// Line 531, Address: 0x2aa640, Func Offset: 0x290
	// Line 532, Address: 0x2aa64c, Func Offset: 0x29c
	// Line 533, Address: 0x2aa660, Func Offset: 0x2b0
	// Line 536, Address: 0x2aa674, Func Offset: 0x2c4
	// Func End, Address: 0x2aa68c, Func Offset: 0x2dc
}

// 
// Start address: 0x2aa690
void CameraInit()
{
	// Line 540, Address: 0x2aa690, Func Offset: 0
	// Line 542, Address: 0x2aa694, Func Offset: 0x4
	// Line 540, Address: 0x2aa698, Func Offset: 0x8
	// Line 542, Address: 0x2aa69c, Func Offset: 0xc
	// Line 543, Address: 0x2aa6a4, Func Offset: 0x14
	// Line 544, Address: 0x2aa6b0, Func Offset: 0x20
	// Line 545, Address: 0x2aa6bc, Func Offset: 0x2c
	// Line 546, Address: 0x2aa6c4, Func Offset: 0x34
	// Line 547, Address: 0x2aa6cc, Func Offset: 0x3c
	// Line 548, Address: 0x2aa6d8, Func Offset: 0x48
	// Line 549, Address: 0x2aa6e0, Func Offset: 0x50
	// Line 550, Address: 0x2aa6e8, Func Offset: 0x58
	// Line 551, Address: 0x2aa6f0, Func Offset: 0x60
	// Line 552, Address: 0x2aa6f8, Func Offset: 0x68
	// Line 553, Address: 0x2aa700, Func Offset: 0x70
	// Line 554, Address: 0x2aa708, Func Offset: 0x78
	// Line 555, Address: 0x2aa710, Func Offset: 0x80
	// Line 556, Address: 0x2aa718, Func Offset: 0x88
	// Line 557, Address: 0x2aa720, Func Offset: 0x90
	// Func End, Address: 0x2aa72c, Func Offset: 0x9c
}

// 
// Start address: 0x2aa730
void CameraSet()
{
	// Line 560, Address: 0x2aa730, Func Offset: 0
	// Line 563, Address: 0x2aa738, Func Offset: 0x8
	// Line 564, Address: 0x2aa740, Func Offset: 0x10
	// Line 566, Address: 0x2aa748, Func Offset: 0x18
	// Line 567, Address: 0x2aa778, Func Offset: 0x48
	// Line 568, Address: 0x2aa788, Func Offset: 0x58
	// Line 569, Address: 0x2aa798, Func Offset: 0x68
	// Line 570, Address: 0x2aa7a8, Func Offset: 0x78
	// Line 572, Address: 0x2aa7c0, Func Offset: 0x90
	// Line 573, Address: 0x2aa7cc, Func Offset: 0x9c
	// Func End, Address: 0x2aa7d8, Func Offset: 0xa8
}

// 
// Start address: 0x2aa7e0
void ItemView()
{
	_anon2* st;
	// Line 576, Address: 0x2aa7e0, Func Offset: 0
	// Line 585, Address: 0x2aa7e8, Func Offset: 0x8
	// Line 577, Address: 0x2aa7ec, Func Offset: 0xc
	// Line 585, Address: 0x2aa7f4, Func Offset: 0x14
	// Line 586, Address: 0x2aa804, Func Offset: 0x24
	// Line 588, Address: 0x2aa808, Func Offset: 0x28
	// Line 590, Address: 0x2aa834, Func Offset: 0x54
	// Line 591, Address: 0x2aa844, Func Offset: 0x64
	// Line 592, Address: 0x2aa848, Func Offset: 0x68
	// Line 593, Address: 0x2aa850, Func Offset: 0x70
	// Line 595, Address: 0x2aa854, Func Offset: 0x74
	// Line 597, Address: 0x2aa85c, Func Offset: 0x7c
	// Line 598, Address: 0x2aa864, Func Offset: 0x84
	// Line 600, Address: 0x2aa86c, Func Offset: 0x8c
	// Line 601, Address: 0x2aa874, Func Offset: 0x94
	// Line 605, Address: 0x2aa87c, Func Offset: 0x9c
	// Line 606, Address: 0x2aa884, Func Offset: 0xa4
	// Line 608, Address: 0x2aa88c, Func Offset: 0xac
	// Line 609, Address: 0x2aa894, Func Offset: 0xb4
	// Line 611, Address: 0x2aa89c, Func Offset: 0xbc
	// Line 612, Address: 0x2aa8a4, Func Offset: 0xc4
	// Line 614, Address: 0x2aa8ac, Func Offset: 0xcc
	// Line 615, Address: 0x2aa8c4, Func Offset: 0xe4
	// Line 616, Address: 0x2aa8c8, Func Offset: 0xe8
	// Line 617, Address: 0x2aa8d0, Func Offset: 0xf0
	// Line 618, Address: 0x2aa8d8, Func Offset: 0xf8
	// Line 620, Address: 0x2aa8e0, Func Offset: 0x100
	// Line 622, Address: 0x2aa8e8, Func Offset: 0x108
	// Line 623, Address: 0x2aa8f0, Func Offset: 0x110
	// Line 625, Address: 0x2aa8f8, Func Offset: 0x118
	// Line 628, Address: 0x2aa900, Func Offset: 0x120
	// Func End, Address: 0x2aa90c, Func Offset: 0x12c
}

// 
// Start address: 0x2aa910
void ItemModelChangeZoomIn()
{
	_anon1* sc;
	_anon2* st;
	// Line 630, Address: 0x2aa910, Func Offset: 0
	// Line 638, Address: 0x2aa91c, Func Offset: 0xc
	// Line 631, Address: 0x2aa924, Func Offset: 0x14
	// Line 633, Address: 0x2aa92c, Func Offset: 0x1c
	// Line 639, Address: 0x2aa934, Func Offset: 0x24
	// Line 638, Address: 0x2aa93c, Func Offset: 0x2c
	// Line 640, Address: 0x2aa950, Func Offset: 0x40
	// Line 639, Address: 0x2aa958, Func Offset: 0x48
	// Line 638, Address: 0x2aa964, Func Offset: 0x54
	// Line 640, Address: 0x2aa96c, Func Offset: 0x5c
	// Line 642, Address: 0x2aa970, Func Offset: 0x60
	// Line 640, Address: 0x2aa978, Func Offset: 0x68
	// Line 641, Address: 0x2aa980, Func Offset: 0x70
	// Line 642, Address: 0x2aa990, Func Offset: 0x80
	// Line 643, Address: 0x2aa998, Func Offset: 0x88
	// Line 645, Address: 0x2aa99c, Func Offset: 0x8c
	// Line 644, Address: 0x2aa9a0, Func Offset: 0x90
	// Line 645, Address: 0x2aa9a4, Func Offset: 0x94
	// Line 647, Address: 0x2aa9a8, Func Offset: 0x98
	// Line 649, Address: 0x2aa9b8, Func Offset: 0xa8
	// Line 647, Address: 0x2aa9bc, Func Offset: 0xac
	// Line 649, Address: 0x2aa9d8, Func Offset: 0xc8
	// Line 647, Address: 0x2aa9dc, Func Offset: 0xcc
	// Line 649, Address: 0x2aa9e4, Func Offset: 0xd4
	// Line 652, Address: 0x2aa9fc, Func Offset: 0xec
	// Line 654, Address: 0x2aaa14, Func Offset: 0x104
	// Func End, Address: 0x2aaa24, Func Offset: 0x114
}

// 
// Start address: 0x2aaa30
void ItemModelCheck()
{
	unsigned char chkcode;
	unsigned char y;
	unsigned char x;
	unsigned short mesnum;
	short* d_a;
	unsigned int* wp;
	int c01;
	int c00;
	_anon6* dw;
	_anon1* sc;
	_anon5* si;
	_anon2* st;
	short at_ang;
	// Line 656, Address: 0x2aaa30, Func Offset: 0
	// Line 660, Address: 0x2aaa5c, Func Offset: 0x2c
	// Line 657, Address: 0x2aaa64, Func Offset: 0x34
	// Line 658, Address: 0x2aaa6c, Func Offset: 0x3c
	// Line 671, Address: 0x2aaa74, Func Offset: 0x44
	// Line 660, Address: 0x2aaa7c, Func Offset: 0x4c
	// Line 671, Address: 0x2aaa8c, Func Offset: 0x5c
	// Line 659, Address: 0x2aaa90, Func Offset: 0x60
	// Line 660, Address: 0x2aaa94, Func Offset: 0x64
	// Line 659, Address: 0x2aaa98, Func Offset: 0x68
	// Line 668, Address: 0x2aaa9c, Func Offset: 0x6c
	// Line 671, Address: 0x2aaaa0, Func Offset: 0x70
	// Line 672, Address: 0x2aaaac, Func Offset: 0x7c
	// Line 673, Address: 0x2aaac0, Func Offset: 0x90
	// Line 676, Address: 0x2aaad8, Func Offset: 0xa8
	// Line 677, Address: 0x2aaae8, Func Offset: 0xb8
	// Line 679, Address: 0x2aaaf8, Func Offset: 0xc8
	// Line 677, Address: 0x2aab08, Func Offset: 0xd8
	// Line 680, Address: 0x2aab14, Func Offset: 0xe4
	// Line 681, Address: 0x2aab1c, Func Offset: 0xec
	// Line 682, Address: 0x2aab24, Func Offset: 0xf4
	// Line 683, Address: 0x2aab2c, Func Offset: 0xfc
	// Line 684, Address: 0x2aab34, Func Offset: 0x104
	// Line 685, Address: 0x2aab3c, Func Offset: 0x10c
	// Line 686, Address: 0x2aab44, Func Offset: 0x114
	// Line 687, Address: 0x2aab4c, Func Offset: 0x11c
	// Line 688, Address: 0x2aab54, Func Offset: 0x124
	// Line 689, Address: 0x2aab5c, Func Offset: 0x12c
	// Line 690, Address: 0x2aab64, Func Offset: 0x134
	// Line 691, Address: 0x2aab6c, Func Offset: 0x13c
	// Line 692, Address: 0x2aab84, Func Offset: 0x154
	// Line 693, Address: 0x2aab8c, Func Offset: 0x15c
	// Line 694, Address: 0x2aab98, Func Offset: 0x168
	// Line 695, Address: 0x2aaba0, Func Offset: 0x170
	// Line 696, Address: 0x2aaba4, Func Offset: 0x174
	// Line 697, Address: 0x2aabb8, Func Offset: 0x188
	// Line 698, Address: 0x2aabc0, Func Offset: 0x190
	// Line 699, Address: 0x2aabcc, Func Offset: 0x19c
	// Line 700, Address: 0x2aabd4, Func Offset: 0x1a4
	// Line 701, Address: 0x2aabd8, Func Offset: 0x1a8
	// Line 702, Address: 0x2aabe0, Func Offset: 0x1b0
	// Line 705, Address: 0x2aabe4, Func Offset: 0x1b4
	// Line 706, Address: 0x2aac04, Func Offset: 0x1d4
	// Line 707, Address: 0x2aac0c, Func Offset: 0x1dc
	// Line 708, Address: 0x2aac18, Func Offset: 0x1e8
	// Line 709, Address: 0x2aac20, Func Offset: 0x1f0
	// Line 710, Address: 0x2aac24, Func Offset: 0x1f4
	// Line 711, Address: 0x2aac38, Func Offset: 0x208
	// Line 712, Address: 0x2aac40, Func Offset: 0x210
	// Line 713, Address: 0x2aac4c, Func Offset: 0x21c
	// Line 714, Address: 0x2aac54, Func Offset: 0x224
	// Line 715, Address: 0x2aac58, Func Offset: 0x228
	// Line 716, Address: 0x2aac60, Func Offset: 0x230
	// Line 719, Address: 0x2aac64, Func Offset: 0x234
	// Line 720, Address: 0x2aac84, Func Offset: 0x254
	// Line 721, Address: 0x2aac90, Func Offset: 0x260
	// Line 722, Address: 0x2aacb0, Func Offset: 0x280
	// Line 724, Address: 0x2aacc4, Func Offset: 0x294
	// Line 725, Address: 0x2aacd8, Func Offset: 0x2a8
	// Line 726, Address: 0x2aacf8, Func Offset: 0x2c8
	// Line 799, Address: 0x2aad0c, Func Offset: 0x2dc
	// Line 800, Address: 0x2aad14, Func Offset: 0x2e4
	// Line 801, Address: 0x2aad18, Func Offset: 0x2e8
	// Line 802, Address: 0x2aad1c, Func Offset: 0x2ec
	// Line 803, Address: 0x2aad20, Func Offset: 0x2f0
	// Line 804, Address: 0x2aad40, Func Offset: 0x310
	// Line 805, Address: 0x2aad48, Func Offset: 0x318
	// Line 807, Address: 0x2aad50, Func Offset: 0x320
	// Line 804, Address: 0x2aad58, Func Offset: 0x328
	// Line 805, Address: 0x2aad68, Func Offset: 0x338
	// Line 807, Address: 0x2aad7c, Func Offset: 0x34c
	// Line 808, Address: 0x2aad94, Func Offset: 0x364
	// Line 809, Address: 0x2aad98, Func Offset: 0x368
	// Line 810, Address: 0x2aada0, Func Offset: 0x370
	// Line 811, Address: 0x2aada8, Func Offset: 0x378
	// Line 812, Address: 0x2aadc4, Func Offset: 0x394
	// Line 813, Address: 0x2aadd4, Func Offset: 0x3a4
	// Line 815, Address: 0x2aade8, Func Offset: 0x3b8
	// Line 814, Address: 0x2aadec, Func Offset: 0x3bc
	// Line 815, Address: 0x2aadf4, Func Offset: 0x3c4
	// Line 816, Address: 0x2aae08, Func Offset: 0x3d8
	// Line 817, Address: 0x2aae30, Func Offset: 0x400
	// Line 820, Address: 0x2aae38, Func Offset: 0x408
	// Line 824, Address: 0x2aae70, Func Offset: 0x440
	// Line 826, Address: 0x2aae74, Func Offset: 0x444
	// Line 827, Address: 0x2aae84, Func Offset: 0x454
	// Line 829, Address: 0x2aae98, Func Offset: 0x468
	// Line 827, Address: 0x2aae9c, Func Offset: 0x46c
	// Line 829, Address: 0x2aaea0, Func Offset: 0x470
	// Line 830, Address: 0x2aaed4, Func Offset: 0x4a4
	// Line 832, Address: 0x2aaee4, Func Offset: 0x4b4
	// Line 833, Address: 0x2aaef4, Func Offset: 0x4c4
	// Line 834, Address: 0x2aaf00, Func Offset: 0x4d0
	// Line 835, Address: 0x2aaf08, Func Offset: 0x4d8
	// Line 838, Address: 0x2aaf14, Func Offset: 0x4e4
	// Line 839, Address: 0x2aaf1c, Func Offset: 0x4ec
	// Line 840, Address: 0x2aaf38, Func Offset: 0x508
	// Line 841, Address: 0x2aaf44, Func Offset: 0x514
	// Line 845, Address: 0x2aaf64, Func Offset: 0x534
	// Line 846, Address: 0x2aaf78, Func Offset: 0x548
	// Line 847, Address: 0x2aaf7c, Func Offset: 0x54c
	// Line 848, Address: 0x2aaf80, Func Offset: 0x550
	// Line 846, Address: 0x2aaf84, Func Offset: 0x554
	// Line 847, Address: 0x2aaf88, Func Offset: 0x558
	// Line 849, Address: 0x2aaf8c, Func Offset: 0x55c
	// Line 850, Address: 0x2aaf94, Func Offset: 0x564
	// Line 851, Address: 0x2aaf9c, Func Offset: 0x56c
	// Line 852, Address: 0x2aafa4, Func Offset: 0x574
	// Line 853, Address: 0x2aafb4, Func Offset: 0x584
	// Line 857, Address: 0x2aafb8, Func Offset: 0x588
	// Line 859, Address: 0x2aafc0, Func Offset: 0x590
	// Line 860, Address: 0x2aafcc, Func Offset: 0x59c
	// Line 861, Address: 0x2aafd4, Func Offset: 0x5a4
	// Line 862, Address: 0x2aafdc, Func Offset: 0x5ac
	// Line 863, Address: 0x2aaff8, Func Offset: 0x5c8
	// Line 864, Address: 0x2ab000, Func Offset: 0x5d0
	// Line 865, Address: 0x2ab008, Func Offset: 0x5d8
	// Line 869, Address: 0x2ab014, Func Offset: 0x5e4
	// Line 870, Address: 0x2ab028, Func Offset: 0x5f8
	// Line 871, Address: 0x2ab030, Func Offset: 0x600
	// Line 872, Address: 0x2ab034, Func Offset: 0x604
	// Line 873, Address: 0x2ab03c, Func Offset: 0x60c
	// Line 874, Address: 0x2ab040, Func Offset: 0x610
	// Line 875, Address: 0x2ab04c, Func Offset: 0x61c
	// Line 874, Address: 0x2ab050, Func Offset: 0x620
	// Line 875, Address: 0x2ab05c, Func Offset: 0x62c
	// Line 876, Address: 0x2ab068, Func Offset: 0x638
	// Line 877, Address: 0x2ab070, Func Offset: 0x640
	// Line 878, Address: 0x2ab078, Func Offset: 0x648
	// Line 883, Address: 0x2ab0a0, Func Offset: 0x670
	// Line 884, Address: 0x2ab0a8, Func Offset: 0x678
	// Line 885, Address: 0x2ab0ac, Func Offset: 0x67c
	// Line 886, Address: 0x2ab0b0, Func Offset: 0x680
	// Line 888, Address: 0x2ab0b4, Func Offset: 0x684
	// Func End, Address: 0x2ab0e4, Func Offset: 0x6b4
}

// 
// Start address: 0x2ab0f0
void ItemModelActionSet()
{
	_anon6* dw;
	_anon2* st;
	// Line 891, Address: 0x2ab0f0, Func Offset: 0
	// Line 895, Address: 0x2ab0fc, Func Offset: 0xc
	// Line 892, Address: 0x2ab104, Func Offset: 0x14
	// Line 895, Address: 0x2ab10c, Func Offset: 0x1c
	// Line 897, Address: 0x2ab114, Func Offset: 0x24
	// Line 895, Address: 0x2ab120, Func Offset: 0x30
	// Line 899, Address: 0x2ab128, Func Offset: 0x38
	// Line 897, Address: 0x2ab12c, Func Offset: 0x3c
	// Line 899, Address: 0x2ab138, Func Offset: 0x48
	// Line 900, Address: 0x2ab178, Func Offset: 0x88
	// Line 901, Address: 0x2ab180, Func Offset: 0x90
	// Line 903, Address: 0x2ab188, Func Offset: 0x98
	// Func End, Address: 0x2ab198, Func Offset: 0xa8
}

// 
// Start address: 0x2ab1a0
void ItemModelChangeZoomOut()
{
	int chkang;
	_anon6* dw;
	_anon5* si;
	_anon1* sc;
	_anon2* st;
	// Line 906, Address: 0x2ab1a0, Func Offset: 0
	// Line 915, Address: 0x2ab1b8, Func Offset: 0x18
	// Line 907, Address: 0x2ab1c0, Func Offset: 0x20
	// Line 908, Address: 0x2ab1c8, Func Offset: 0x28
	// Line 916, Address: 0x2ab1d0, Func Offset: 0x30
	// Line 909, Address: 0x2ab1d8, Func Offset: 0x38
	// Line 915, Address: 0x2ab1e0, Func Offset: 0x40
	// Line 918, Address: 0x2ab1e4, Func Offset: 0x44
	// Line 915, Address: 0x2ab1ec, Func Offset: 0x4c
	// Line 916, Address: 0x2ab1f4, Func Offset: 0x54
	// Line 918, Address: 0x2ab200, Func Offset: 0x60
	// Line 916, Address: 0x2ab204, Func Offset: 0x64
	// Line 918, Address: 0x2ab208, Func Offset: 0x68
	// Line 919, Address: 0x2ab210, Func Offset: 0x70
	// Line 921, Address: 0x2ab218, Func Offset: 0x78
	// Line 919, Address: 0x2ab220, Func Offset: 0x80
	// Line 916, Address: 0x2ab224, Func Offset: 0x84
	// Line 919, Address: 0x2ab22c, Func Offset: 0x8c
	// Line 921, Address: 0x2ab230, Func Offset: 0x90
	// Line 924, Address: 0x2ab238, Func Offset: 0x98
	// Line 927, Address: 0x2ab240, Func Offset: 0xa0
	// Line 924, Address: 0x2ab248, Func Offset: 0xa8
	// Line 927, Address: 0x2ab258, Func Offset: 0xb8
	// Line 928, Address: 0x2ab264, Func Offset: 0xc4
	// Line 927, Address: 0x2ab26c, Func Offset: 0xcc
	// Line 929, Address: 0x2ab278, Func Offset: 0xd8
	// Line 927, Address: 0x2ab280, Func Offset: 0xe0
	// Line 928, Address: 0x2ab290, Func Offset: 0xf0
	// Line 929, Address: 0x2ab2a4, Func Offset: 0x104
	// Line 932, Address: 0x2ab2b0, Func Offset: 0x110
	// Line 933, Address: 0x2ab2bc, Func Offset: 0x11c
	// Line 934, Address: 0x2ab2c4, Func Offset: 0x124
	// Line 936, Address: 0x2ab2d0, Func Offset: 0x130
	// Line 934, Address: 0x2ab2d8, Func Offset: 0x138
	// Line 936, Address: 0x2ab2e0, Func Offset: 0x140
	// Line 938, Address: 0x2ab300, Func Offset: 0x160
	// Line 939, Address: 0x2ab308, Func Offset: 0x168
	// Line 940, Address: 0x2ab328, Func Offset: 0x188
	// Line 939, Address: 0x2ab338, Func Offset: 0x198
	// Line 943, Address: 0x2ab34c, Func Offset: 0x1ac
	// Line 939, Address: 0x2ab350, Func Offset: 0x1b0
	// Line 940, Address: 0x2ab354, Func Offset: 0x1b4
	// Line 941, Address: 0x2ab358, Func Offset: 0x1b8
	// Line 940, Address: 0x2ab368, Func Offset: 0x1c8
	// Line 942, Address: 0x2ab374, Func Offset: 0x1d4
	// Line 940, Address: 0x2ab378, Func Offset: 0x1d8
	// Line 941, Address: 0x2ab390, Func Offset: 0x1f0
	// Line 943, Address: 0x2ab3b8, Func Offset: 0x218
	// Line 944, Address: 0x2ab3c0, Func Offset: 0x220
	// Line 946, Address: 0x2ab3c8, Func Offset: 0x228
	// Line 947, Address: 0x2ab3cc, Func Offset: 0x22c
	// Line 948, Address: 0x2ab3d0, Func Offset: 0x230
	// Line 949, Address: 0x2ab3d4, Func Offset: 0x234
	// Line 952, Address: 0x2ab3fc, Func Offset: 0x25c
	// Line 953, Address: 0x2ab400, Func Offset: 0x260
	// Line 954, Address: 0x2ab408, Func Offset: 0x268
	// Line 957, Address: 0x2ab410, Func Offset: 0x270
	// Line 958, Address: 0x2ab414, Func Offset: 0x274
	// Line 959, Address: 0x2ab418, Func Offset: 0x278
	// Line 960, Address: 0x2ab41c, Func Offset: 0x27c
	// Line 962, Address: 0x2ab428, Func Offset: 0x288
	// Func End, Address: 0x2ab444, Func Offset: 0x2a4
}

// 
// Start address: 0x2ab450
void ItemModelMessageWait()
{
	_anon6* dw;
	_anon2* st;
	// Line 966, Address: 0x2ab450, Func Offset: 0
	// Line 965, Address: 0x2ab45c, Func Offset: 0xc
	// Line 966, Address: 0x2ab460, Func Offset: 0x10
	// Line 968, Address: 0x2ab464, Func Offset: 0x14
	// Line 966, Address: 0x2ab46c, Func Offset: 0x1c
	// Line 968, Address: 0x2ab474, Func Offset: 0x24
	// Line 969, Address: 0x2ab494, Func Offset: 0x44
	// Line 970, Address: 0x2ab49c, Func Offset: 0x4c
	// Line 969, Address: 0x2ab4a4, Func Offset: 0x54
	// Line 970, Address: 0x2ab4ac, Func Offset: 0x5c
	// Line 971, Address: 0x2ab4b0, Func Offset: 0x60
	// Line 970, Address: 0x2ab4b4, Func Offset: 0x64
	// Line 971, Address: 0x2ab4b8, Func Offset: 0x68
	// Line 970, Address: 0x2ab4bc, Func Offset: 0x6c
	// Line 971, Address: 0x2ab4c4, Func Offset: 0x74
	// Line 973, Address: 0x2ab4f0, Func Offset: 0xa0
	// Line 975, Address: 0x2ab4f4, Func Offset: 0xa4
	// Line 973, Address: 0x2ab4fc, Func Offset: 0xac
	// Line 975, Address: 0x2ab500, Func Offset: 0xb0
	// Line 976, Address: 0x2ab518, Func Offset: 0xc8
	// Line 977, Address: 0x2ab51c, Func Offset: 0xcc
	// Line 978, Address: 0x2ab524, Func Offset: 0xd4
	// Line 979, Address: 0x2ab52c, Func Offset: 0xdc
	// Line 981, Address: 0x2ab530, Func Offset: 0xe0
	// Line 983, Address: 0x2ab538, Func Offset: 0xe8
	// Line 987, Address: 0x2ab540, Func Offset: 0xf0
	// Func End, Address: 0x2ab548, Func Offset: 0xf8
}

// 
// Start address: 0x2ab550
unsigned char MdlDirChk(short* dirang, short mdlang)
{
	// Line 994, Address: 0x2ab550, Func Offset: 0
	// Line 999, Address: 0x2ab55c, Func Offset: 0xc
	// Line 997, Address: 0x2ab560, Func Offset: 0x10
	// Line 999, Address: 0x2ab570, Func Offset: 0x20
	// Line 1005, Address: 0x2ab590, Func Offset: 0x40
	// Func End, Address: 0x2ab598, Func Offset: 0x48
}

// 
// Start address: 0x2ab5a0
unsigned char MdlAction00(_anon5* si)
{
	// Line 1009, Address: 0x2ab5a0, Func Offset: 0
	// Line 1011, Address: 0x2ab5dc, Func Offset: 0x3c
	// Line 1013, Address: 0x2ab5e0, Func Offset: 0x40
	// Line 1015, Address: 0x2ab5e8, Func Offset: 0x48
	// Line 1017, Address: 0x2ab5ec, Func Offset: 0x4c
	// Line 1015, Address: 0x2ab5f0, Func Offset: 0x50
	// Line 1016, Address: 0x2ab608, Func Offset: 0x68
	// Line 1017, Address: 0x2ab61c, Func Offset: 0x7c
	// Line 1018, Address: 0x2ab63c, Func Offset: 0x9c
	// Line 1020, Address: 0x2ab644, Func Offset: 0xa4
	// Line 1021, Address: 0x2ab668, Func Offset: 0xc8
	// Line 1022, Address: 0x2ab67c, Func Offset: 0xdc
	// Line 1026, Address: 0x2ab68c, Func Offset: 0xec
	// Line 1028, Address: 0x2ab694, Func Offset: 0xf4
	// Line 1030, Address: 0x2ab6a0, Func Offset: 0x100
	// Line 1032, Address: 0x2ab6a4, Func Offset: 0x104
	// Func End, Address: 0x2ab6ac, Func Offset: 0x10c
}

// 
// Start address: 0x2ab6b0
unsigned char MdlAction01(_anon5* si)
{
	// Line 1036, Address: 0x2ab6b0, Func Offset: 0
	// Line 1038, Address: 0x2ab6e0, Func Offset: 0x30
	// Line 1040, Address: 0x2ab6e8, Func Offset: 0x38
	// Line 1041, Address: 0x2ab6fc, Func Offset: 0x4c
	// Line 1043, Address: 0x2ab700, Func Offset: 0x50
	// Line 1041, Address: 0x2ab704, Func Offset: 0x54
	// Line 1042, Address: 0x2ab724, Func Offset: 0x74
	// Line 1043, Address: 0x2ab738, Func Offset: 0x88
	// Line 1044, Address: 0x2ab760, Func Offset: 0xb0
	// Line 1046, Address: 0x2ab768, Func Offset: 0xb8
	// Line 1047, Address: 0x2ab77c, Func Offset: 0xcc
	// Line 1049, Address: 0x2ab780, Func Offset: 0xd0
	// Line 1047, Address: 0x2ab784, Func Offset: 0xd4
	// Line 1048, Address: 0x2ab7a0, Func Offset: 0xf0
	// Line 1049, Address: 0x2ab7b4, Func Offset: 0x104
	// Line 1050, Address: 0x2ab7d8, Func Offset: 0x128
	// Line 1052, Address: 0x2ab7e0, Func Offset: 0x130
	// Line 1053, Address: 0x2ab7f4, Func Offset: 0x144
	// Line 1055, Address: 0x2ab7f8, Func Offset: 0x148
	// Line 1053, Address: 0x2ab7fc, Func Offset: 0x14c
	// Line 1054, Address: 0x2ab814, Func Offset: 0x164
	// Line 1055, Address: 0x2ab828, Func Offset: 0x178
	// Line 1056, Address: 0x2ab848, Func Offset: 0x198
	// Line 1058, Address: 0x2ab850, Func Offset: 0x1a0
	// Line 1059, Address: 0x2ab858, Func Offset: 0x1a8
	// Line 1061, Address: 0x2ab85c, Func Offset: 0x1ac
	// Line 1059, Address: 0x2ab860, Func Offset: 0x1b0
	// Line 1060, Address: 0x2ab878, Func Offset: 0x1c8
	// Line 1061, Address: 0x2ab88c, Func Offset: 0x1dc
	// Line 1062, Address: 0x2ab8ac, Func Offset: 0x1fc
	// Line 1065, Address: 0x2ab8b8, Func Offset: 0x208
	// Line 1066, Address: 0x2ab8dc, Func Offset: 0x22c
	// Line 1067, Address: 0x2ab8f0, Func Offset: 0x240
	// Line 1072, Address: 0x2ab900, Func Offset: 0x250
	// Line 1074, Address: 0x2ab908, Func Offset: 0x258
	// Line 1076, Address: 0x2ab914, Func Offset: 0x264
	// Line 1077, Address: 0x2ab918, Func Offset: 0x268
	// Func End, Address: 0x2ab920, Func Offset: 0x270
}

// 
// Start address: 0x2ab920
unsigned char MdlAction02(_anon5* si)
{
	// Line 1081, Address: 0x2ab920, Func Offset: 0
	// Line 1083, Address: 0x2ab950, Func Offset: 0x30
	// Line 1085, Address: 0x2ab958, Func Offset: 0x38
	// Line 1087, Address: 0x2ab95c, Func Offset: 0x3c
	// Line 1085, Address: 0x2ab960, Func Offset: 0x40
	// Line 1086, Address: 0x2ab978, Func Offset: 0x58
	// Line 1087, Address: 0x2ab98c, Func Offset: 0x6c
	// Line 1088, Address: 0x2ab9ac, Func Offset: 0x8c
	// Line 1090, Address: 0x2ab9b8, Func Offset: 0x98
	// Line 1091, Address: 0x2ab9dc, Func Offset: 0xbc
	// Line 1092, Address: 0x2ab9f0, Func Offset: 0xd0
	// Line 1096, Address: 0x2aba00, Func Offset: 0xe0
	// Line 1098, Address: 0x2aba08, Func Offset: 0xe8
	// Line 1100, Address: 0x2aba14, Func Offset: 0xf4
	// Line 1101, Address: 0x2aba18, Func Offset: 0xf8
	// Func End, Address: 0x2aba20, Func Offset: 0x100
}

// 
// Start address: 0x2aba20
void MdlEvalflagsSet(unsigned short evalchk)
{
	// Line 1108, Address: 0x2aba20, Func Offset: 0
	// Func End, Address: 0x2aba48, Func Offset: 0x28
}

// 
// Start address: 0x2aba50
void MdlHideCheck(npobj* op, unsigned char el, unsigned char chk)
{
	// Line 1112, Address: 0x2aba50, Func Offset: 0
	// Line 1113, Address: 0x2aba68, Func Offset: 0x18
	// Line 1114, Address: 0x2aba80, Func Offset: 0x30
	// Line 1116, Address: 0x2aba84, Func Offset: 0x34
	// Line 1117, Address: 0x2aba90, Func Offset: 0x40
	// Line 1114, Address: 0x2aba98, Func Offset: 0x48
	// Line 1119, Address: 0x2aba9c, Func Offset: 0x4c
	// Line 1120, Address: 0x2ababc, Func Offset: 0x6c
	// Line 1121, Address: 0x2abadc, Func Offset: 0x8c
	// Line 1123, Address: 0x2abaec, Func Offset: 0x9c
	// Line 1122, Address: 0x2abaf0, Func Offset: 0xa0
	// Line 1123, Address: 0x2abaf4, Func Offset: 0xa4
	// Line 1124, Address: 0x2abb04, Func Offset: 0xb4
	// Line 1127, Address: 0x2abb1c, Func Offset: 0xcc
	// Func End, Address: 0x2abb34, Func Offset: 0xe4
}

// 
// Start address: 0x2abb40
float ModelScaleSet(_anon5* itemmodel, unsigned short flg)
{
	float scale00;
	// Line 1130, Address: 0x2abb40, Func Offset: 0
	// Line 1133, Address: 0x2abb4c, Func Offset: 0xc
	// Line 1134, Address: 0x2abb54, Func Offset: 0x14
	// Line 1135, Address: 0x2abb5c, Func Offset: 0x1c
	// Line 1136, Address: 0x2abb64, Func Offset: 0x24
	// Line 1138, Address: 0x2abb6c, Func Offset: 0x2c
	// Line 1139, Address: 0x2abb78, Func Offset: 0x38
	// Line 1140, Address: 0x2abb84, Func Offset: 0x44
	// Line 1143, Address: 0x2abb90, Func Offset: 0x50
	// Line 1158, Address: 0x2abba0, Func Offset: 0x60
	// Line 1170, Address: 0x2abbac, Func Offset: 0x6c
	// Line 1178, Address: 0x2abc10, Func Offset: 0xd0
	// Line 1179, Address: 0x2abc2c, Func Offset: 0xec
	// Line 1180, Address: 0x2abc34, Func Offset: 0xf4
	// Line 1185, Address: 0x2abc48, Func Offset: 0x108
	// Func End, Address: 0x2abc58, Func Offset: 0x118
}

// 
// Start address: 0x2abc60
void FlagErase(npobj* op)
{
	// Line 1199, Address: 0x2abc60, Func Offset: 0
	// Line 1200, Address: 0x2abc6c, Func Offset: 0xc
	// Line 1201, Address: 0x2abc74, Func Offset: 0x14
	// Line 1200, Address: 0x2abc7c, Func Offset: 0x1c
	// Line 1201, Address: 0x2abc84, Func Offset: 0x24
	// Line 1202, Address: 0x2abc90, Func Offset: 0x30
	// Line 1203, Address: 0x2abca4, Func Offset: 0x44
	// Line 1204, Address: 0x2abcb8, Func Offset: 0x58
	// Func End, Address: 0x2abcc8, Func Offset: 0x68
}

// 
// Start address: 0x2abcd0
void LighterOpen(npobj* op)
{
	// Line 1239, Address: 0x2abcd0, Func Offset: 0
	// Line 1240, Address: 0x2abcd4, Func Offset: 0x4
	// Func End, Address: 0x2abcdc, Func Offset: 0xc
}

// 
// Start address: 0x2abce0
void FileSyu(npobj* op)
{
	// Line 1243, Address: 0x2abce0, Func Offset: 0
	// Line 1244, Address: 0x2abce8, Func Offset: 0x8
	// Line 1245, Address: 0x2abcec, Func Offset: 0xc
	// Line 1246, Address: 0x2abcf4, Func Offset: 0x14
	// Line 1247, Address: 0x2abd00, Func Offset: 0x20
	// Line 1248, Address: 0x2abd08, Func Offset: 0x28
	// Line 1249, Address: 0x2abd10, Func Offset: 0x30
	// Func End, Address: 0x2abd18, Func Offset: 0x38
}

// 
// Start address: 0x2abd20
void MakeTag(unsigned short flg)
{
	float zpos;
	float ypos;
	int tagcol;
	int i;
	_anon38 p3c;
	_anon18 col[4];
	_anon32 p[4];
	_anon33* fv;
	_anon2* st;
	// Line 1254, Address: 0x2abd20, Func Offset: 0
	// Line 1256, Address: 0x2abd3c, Func Offset: 0x1c
	// Line 1258, Address: 0x2abd44, Func Offset: 0x24
	// Line 1254, Address: 0x2abd4c, Func Offset: 0x2c
	// Line 1275, Address: 0x2abd50, Func Offset: 0x30
	// Line 1254, Address: 0x2abd54, Func Offset: 0x34
	// Line 1277, Address: 0x2abd58, Func Offset: 0x38
	// Line 1275, Address: 0x2abd5c, Func Offset: 0x3c
	// Line 1277, Address: 0x2abd60, Func Offset: 0x40
	// Line 1275, Address: 0x2abd64, Func Offset: 0x44
	// Line 1278, Address: 0x2abd74, Func Offset: 0x54
	// Line 1277, Address: 0x2abd78, Func Offset: 0x58
	// Line 1278, Address: 0x2abd84, Func Offset: 0x64
	// Line 1279, Address: 0x2abd98, Func Offset: 0x78
	// Line 1282, Address: 0x2abdac, Func Offset: 0x8c
	// Line 1284, Address: 0x2abdb0, Func Offset: 0x90
	// Line 1285, Address: 0x2abdd4, Func Offset: 0xb4
	// Line 1286, Address: 0x2abde4, Func Offset: 0xc4
	// Line 1289, Address: 0x2abe04, Func Offset: 0xe4
	// Line 1290, Address: 0x2abe0c, Func Offset: 0xec
	// Line 1292, Address: 0x2abe10, Func Offset: 0xf0
	// Line 1293, Address: 0x2abe18, Func Offset: 0xf8
	// Line 1295, Address: 0x2abe20, Func Offset: 0x100
	// Line 1298, Address: 0x2abe54, Func Offset: 0x134
	// Line 1299, Address: 0x2abe5c, Func Offset: 0x13c
	// Line 1303, Address: 0x2abe60, Func Offset: 0x140
	// Line 1304, Address: 0x2abe68, Func Offset: 0x148
	// Line 1306, Address: 0x2abe70, Func Offset: 0x150
	// Line 1305, Address: 0x2abe74, Func Offset: 0x154
	// Line 1306, Address: 0x2abe78, Func Offset: 0x158
	// Line 1309, Address: 0x2abe7c, Func Offset: 0x15c
	// Line 1308, Address: 0x2abe80, Func Offset: 0x160
	// Line 1310, Address: 0x2abe84, Func Offset: 0x164
	// Line 1309, Address: 0x2abe88, Func Offset: 0x168
	// Line 1310, Address: 0x2abe8c, Func Offset: 0x16c
	// Line 1311, Address: 0x2abe90, Func Offset: 0x170
	// Line 1312, Address: 0x2abe94, Func Offset: 0x174
	// Line 1340, Address: 0x2abea0, Func Offset: 0x180
	// Line 1314, Address: 0x2abea4, Func Offset: 0x184
	// Line 1311, Address: 0x2abea8, Func Offset: 0x188
	// Line 1312, Address: 0x2abeac, Func Offset: 0x18c
	// Line 1314, Address: 0x2abeb0, Func Offset: 0x190
	// Line 1321, Address: 0x2abeb8, Func Offset: 0x198
	// Line 1312, Address: 0x2abebc, Func Offset: 0x19c
	// Line 1313, Address: 0x2abec4, Func Offset: 0x1a4
	// Line 1314, Address: 0x2abecc, Func Offset: 0x1ac
	// Line 1315, Address: 0x2abed8, Func Offset: 0x1b8
	// Line 1316, Address: 0x2abee4, Func Offset: 0x1c4
	// Line 1317, Address: 0x2abeec, Func Offset: 0x1cc
	// Line 1318, Address: 0x2abef8, Func Offset: 0x1d8
	// Line 1319, Address: 0x2abf00, Func Offset: 0x1e0
	// Line 1321, Address: 0x2abf04, Func Offset: 0x1e4
	// Line 1322, Address: 0x2abf08, Func Offset: 0x1e8
	// Line 1323, Address: 0x2abf0c, Func Offset: 0x1ec
	// Line 1324, Address: 0x2abf10, Func Offset: 0x1f0
	// Line 1326, Address: 0x2abf14, Func Offset: 0x1f4
	// Line 1327, Address: 0x2abf18, Func Offset: 0x1f8
	// Line 1328, Address: 0x2abf1c, Func Offset: 0x1fc
	// Line 1329, Address: 0x2abf20, Func Offset: 0x200
	// Line 1331, Address: 0x2abf24, Func Offset: 0x204
	// Line 1332, Address: 0x2abf28, Func Offset: 0x208
	// Line 1333, Address: 0x2abf2c, Func Offset: 0x20c
	// Line 1334, Address: 0x2abf30, Func Offset: 0x210
	// Line 1336, Address: 0x2abf34, Func Offset: 0x214
	// Line 1337, Address: 0x2abf38, Func Offset: 0x218
	// Line 1338, Address: 0x2abf3c, Func Offset: 0x21c
	// Line 1319, Address: 0x2abf40, Func Offset: 0x220
	// Line 1340, Address: 0x2abf44, Func Offset: 0x224
	// Line 1341, Address: 0x2abf4c, Func Offset: 0x22c
	// Line 1342, Address: 0x2abf5c, Func Offset: 0x23c
	// Line 1343, Address: 0x2abf64, Func Offset: 0x244
	// Line 1344, Address: 0x2abf68, Func Offset: 0x248
	// Line 1346, Address: 0x2abf74, Func Offset: 0x254
	// Line 1344, Address: 0x2abf78, Func Offset: 0x258
	// Line 1345, Address: 0x2abf7c, Func Offset: 0x25c
	// Line 1346, Address: 0x2abf88, Func Offset: 0x268
	// Line 1348, Address: 0x2abf94, Func Offset: 0x274
	// Func End, Address: 0x2abfbc, Func Offset: 0x29c
}

