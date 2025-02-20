typedef struct npobj;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct BH_PWORK;
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

typedef void(*type_10)(BH_PWORK*);
typedef void(*type_37)(BH_PWORK*);
typedef void(*type_43)(BH_PWORK*);
typedef void(*type_70)(BH_PWORK*);
typedef void(*type_84)(BH_PWORK*);
typedef void(*type_88)(void*);

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
typedef void(*type_11)(BH_PWORK*)[2];
typedef _anon0* type_12[512];
typedef _anon1* type_13[1300];
typedef char type_14[32];
typedef _anon0* type_15[512];
typedef _anon1* type_16[200];
typedef short type_17[32];
typedef _anon15 type_18[1];
typedef _anon0* type_19[128];
typedef unsigned int type_20[1];
typedef _anon5 type_21[256];
typedef _anon1* type_22[8];
typedef int* type_23[16];
typedef _anon0* type_24[128];
typedef npobj* type_25[16];
typedef float type_26[16][0];
typedef _anon0* type_27[128];
typedef int type_28[4];
typedef _anon1* type_29[16];
typedef unsigned int type_30[4];
typedef _anon8 type_31[16];
typedef _anon0* type_32[512];
typedef char type_33[256];
typedef _anon35 type_34[21];
typedef float type_35[4];
typedef float type_36[4];
typedef void(*type_38)(BH_PWORK*)[1];
typedef float type_39[4];
typedef _anon3* type_40[128];
typedef unsigned char type_41[64];
typedef float type_42[16];
typedef void(*type_44)(BH_PWORK*)[6];
typedef unsigned short type_45[3];
typedef char type_46[8];
typedef float type_47[11];
typedef void* type_48[2];
typedef _anon28 type_49[6];
typedef _anon1* type_50[256];
typedef float type_51[11];
typedef char type_52[6];
typedef char type_53[6][1];
typedef int type_54[4];
typedef unsigned char* type_55[256];
typedef _anon16 type_56[25];
typedef unsigned int type_57[2];
typedef short type_58[256];
typedef _anon21 type_59[4];
typedef float type_60[3];
typedef short type_61[256];
typedef int type_62[3];
typedef int type_63[8];
typedef float type_64[3];
typedef _anon1* type_65[256];
typedef int type_66[4];
typedef _anon7 type_67[256];
typedef _anon15 type_68[450];
typedef _anon23 type_69[16];
typedef void(*type_71)(BH_PWORK*)[12];
typedef short type_72[256];
typedef char type_73[3];
typedef int type_74[4];
typedef int type_75[64];
typedef _anon8 type_76[450];
typedef _anon38 type_77[22];
typedef _anon27 type_78[4];
typedef _anon2 type_79[4];
typedef int type_80[450];
typedef unsigned int type_81[8];
typedef unsigned char type_82[450];
typedef unsigned char type_83[22];
typedef void(*type_85)(BH_PWORK*)[2];
typedef char type_86[16];
typedef char type_87[4];
typedef unsigned int type_89[32];
typedef _anon28 type_90[5];
typedef unsigned int type_91[16];
typedef _anon30 type_92[64];
typedef unsigned int type_93[16];
typedef char type_94[3];
typedef _anon30 type_95[64];
typedef unsigned int type_96[32];
typedef _anon28 type_97[5];
typedef char type_98[3];
typedef _anon30 type_99[64];
typedef unsigned int type_100[16];
typedef unsigned int type_101[3];
typedef BH_PWORK* type_102[16];
typedef unsigned int type_103[8];
typedef unsigned int type_104[1];
typedef unsigned int type_105[384];
typedef unsigned int type_106[2];
typedef int type_107[3];
typedef _anon32 type_108[21];
typedef unsigned char type_109[2];
typedef unsigned int type_110[4];
typedef int* type_111[16];
typedef char type_112[32];
typedef npobj* type_113[16];
typedef char type_114[64];
typedef _anon1* type_115[16];
typedef char type_116[4];
typedef _anon8 type_117[16];
typedef short type_118[4];
typedef unsigned char type_119[4];
typedef _anon25 type_120[16];
typedef unsigned int type_121[32];
typedef _anon24 type_122[32];
typedef BH_PWORK type_123[0];
typedef _anon0* type_124[512];
typedef _anon0 type_125[0];
typedef _anon0* type_126[128];
typedef _anon0* type_127[512];
typedef unsigned char type_128[64];
typedef _anon11 type_129[22];
typedef char type_130[5];
typedef _anon0* type_131[512];

struct npobj
{
	unsigned int evalflags;
	_anon22* model;
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
	_anon36 cspr;
	int pn;
	_anon27* pvp;
	_anon2* tvp;
	_anon27 pv[4];
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
	_anon15* textures;
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
	_anon37 watr;
	_anon16* cpcl;
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

struct _anon3
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon14* md2P;
	unsigned short* atrP;
};

struct _anon4
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
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
	_anon4* owP;
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
	_anon33* info;
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
	int flg;
	_anon24 ofp;
	float rx;
	float ry;
	float rz;
};

struct _anon12
{
	unsigned short key[3];
};

struct _anon13
{
	void* texaddr;
	_anon6 texsurface;
};

struct _anon14
{
	void* p[2];
};

struct _anon15
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon16
{
	short jnt_a;
	short jnt_b;
	int cap_r;
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
	_anon20* light;
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
	_anon24 ply_pos;
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
	_anon15 ef_tex[450];
	_anon1 ef_tlist;
	_anon29 ef;
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
	_anon15 ren_tex[1];
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
	_anon31 mr_pl;
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
	_anon21 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon23 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon30* pl_htp;
	int costume;
	_anon24 hd_pos;
	_anon24 apos;
	_anon30* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon30 mwalp[64];
	_anon30 metcp[64];
	_anon30 mflrp[64];
	int dla_n;
	_anon30* htp;
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
	_anon24 ufo_pos;
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
	_anon25 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon24 ghtp[32];
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
	float a;
	float r;
	float g;
	float b;
};

struct _anon20
{
	float mtrx[16];
	_anon24 pnt;
	_anon24 vctr;
	int stat;
	int reserve;
	_anon26 ltcal;
	_anon34 attr;
};

struct _anon21
{
	_anon24 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon22
{
	int* vlist;
	short* plist;
	_anon24 center;
	float r;
};

struct _anon23
{
	float x;
	float y;
};

struct _anon24
{
	float x;
	float y;
	float z;
};

struct _anon25
{
	_anon24 c1;
	_anon24 c2;
	float r1;
	float r2;
};

struct _anon26
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
	_anon24 lpnt;
	_anon24 lvctr;
	_anon24 lmvctr;
	_anon19 atten;
	_anon19 amb;
	_anon19 dif;
	_anon19 spc;
	_anon19 mamb;
	_anon19 mdif;
	_anon19 mspc;
};

struct _anon27
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon28
{
	int key;
	float cnt;
};

struct _anon29
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

struct _anon30
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

struct _anon31
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon32
{
	char type[3];
	char bloodstain[3];
	char exef;
};

struct _anon33
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

struct _anon34
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
	_anon19 argb;
};

struct _anon35
{
	int crit;
	int pt[3];
	int timeout;
	int bonus;
};

struct _anon36
{
	_anon24 c;
	float r;
};

struct _anon37
{
	_anon24 c1;
	_anon24 c2;
	float r;
};

struct _anon38
{
	int flg;
	int correct;
};

unsigned char flip_tree[22];
char SdwTab[5];
char joint_tree[6][1];
_anon32 DmgReact[21];
_anon35 CombWepTbl[21];
_anon38 CombJointTbl[22];
_anon11 BloodTbl[22];
_anon16 CapColTab[25];
_anon28 ShapeTbl_Acid_F[5];
_anon28 ShapeTbl_Acid_S[6];
_anon28 ShapeTbl_Acid_A[5];
void(*bhEne14_Mode0)(BH_PWORK*)[6];
void(*bhEne14_BrainType)(BH_PWORK*)[2];
void(*bhEne14_MoveMode2)(BH_PWORK*)[12];
void(*bhEne14_NageMode2)(BH_PWORK*)[1];
void(*bhEne14_DamageMode2)(BH_PWORK*)[2];
_anon0 eff[0];
_anon18* sys;
BH_PWORK ene[0];
BH_PWORK* plp;
float lcmat[16][0];

void bhEne14(BH_PWORK* epw);
void bhEne14_Init(BH_PWORK* epw);
void bhEne14_Brain(BH_PWORK* epw);
void bhEne14_BR00();
void bhEne14_BR01();
void bhEne14_Move(BH_PWORK* epw);
void bhEne14_MV00(BH_PWORK* epw);
void bhEne14_MV01(BH_PWORK* epw);
void bhEne14_MV02(BH_PWORK* epw);
void bhEne14_MV03();
void bhEne14_MV04(BH_PWORK* epw);
void bhEne14_MV05();
void bhEne14_MV06();
void bhEne14_MV07();
void bhEne14_MV08();
void bhEne14_MV09();
void bhEne14_MV10();
void bhEne14_MV11(BH_PWORK* epw);
void bhEne14_Nage(BH_PWORK* epw);
void bhEne14_NG00();
void bhEne14_Damage(BH_PWORK* epw);
void bhEne14_DG00(BH_PWORK* epw);
void bhEne14_DG01(BH_PWORK* epw);
void bhEne14_Die();
void bhEne14_InitDamage(BH_PWORK* epw);
void bhEne14_LookPlayaer(BH_PWORK* epw);
void bhEne14_TailInit(BH_PWORK* epw);
void bhEne14_TailSwing(BH_PWORK* epw);
int bhEne14_HitMark(BH_PWORK* epw);
void bhEne14_Acid(BH_PWORK* epw, int se);
void bhEne14_SetMotion(BH_PWORK* epw);
void bhEne14_CheckWall(BH_PWORK* epw);
void bhEne14_PlayerControl(BH_PWORK* epw);
void bhEne14_CallSE(BH_PWORK* epw);

// 
// Start address: 0x1ddad0
void bhEne14(BH_PWORK* epw)
{
	_anon0* op;
	int i;
	// Line 429, Address: 0x1ddad0, Func Offset: 0
	// Line 431, Address: 0x1ddae0, Func Offset: 0x10
	// Line 434, Address: 0x1ddb00, Func Offset: 0x30
	// Line 437, Address: 0x1ddb08, Func Offset: 0x38
	// Line 440, Address: 0x1ddb1c, Func Offset: 0x4c
	// Line 441, Address: 0x1ddb30, Func Offset: 0x60
	// Line 445, Address: 0x1ddb38, Func Offset: 0x68
	// Line 446, Address: 0x1ddb48, Func Offset: 0x78
	// Line 449, Address: 0x1ddb50, Func Offset: 0x80
	// Line 450, Address: 0x1ddb60, Func Offset: 0x90
	// Line 454, Address: 0x1ddb68, Func Offset: 0x98
	// Line 457, Address: 0x1ddb74, Func Offset: 0xa4
	// Line 460, Address: 0x1ddb7c, Func Offset: 0xac
	// Line 463, Address: 0x1ddb94, Func Offset: 0xc4
	// Line 464, Address: 0x1ddba4, Func Offset: 0xd4
	// Line 472, Address: 0x1ddbac, Func Offset: 0xdc
	// Line 473, Address: 0x1ddbb0, Func Offset: 0xe0
	// Line 474, Address: 0x1ddbb8, Func Offset: 0xe8
	// Line 472, Address: 0x1ddbbc, Func Offset: 0xec
	// Line 476, Address: 0x1ddbc0, Func Offset: 0xf0
	// Line 475, Address: 0x1ddbc8, Func Offset: 0xf8
	// Line 476, Address: 0x1ddbec, Func Offset: 0x11c
	// Line 477, Address: 0x1ddc04, Func Offset: 0x134
	// Line 478, Address: 0x1ddc08, Func Offset: 0x138
	// Line 480, Address: 0x1ddc10, Func Offset: 0x140
	// Line 489, Address: 0x1ddc20, Func Offset: 0x150
	// Func End, Address: 0x1ddc30, Func Offset: 0x160
}

// 
// Start address: 0x1ddc30
void bhEne14_Init(BH_PWORK* epw)
{
	int i;
	BH_PWORK* ep;
	// Line 499, Address: 0x1ddc30, Func Offset: 0
	// Line 501, Address: 0x1ddc3c, Func Offset: 0xc
	// Line 502, Address: 0x1ddc40, Func Offset: 0x10
	// Line 504, Address: 0x1ddc44, Func Offset: 0x14
	// Line 505, Address: 0x1ddc48, Func Offset: 0x18
	// Line 506, Address: 0x1ddc4c, Func Offset: 0x1c
	// Line 501, Address: 0x1ddc50, Func Offset: 0x20
	// Line 502, Address: 0x1ddc58, Func Offset: 0x28
	// Line 508, Address: 0x1ddc5c, Func Offset: 0x2c
	// Line 502, Address: 0x1ddc60, Func Offset: 0x30
	// Line 503, Address: 0x1ddc68, Func Offset: 0x38
	// Line 504, Address: 0x1ddc74, Func Offset: 0x44
	// Line 505, Address: 0x1ddc78, Func Offset: 0x48
	// Line 506, Address: 0x1ddc7c, Func Offset: 0x4c
	// Line 507, Address: 0x1ddc80, Func Offset: 0x50
	// Line 508, Address: 0x1ddc84, Func Offset: 0x54
	// Line 510, Address: 0x1ddc88, Func Offset: 0x58
	// Line 512, Address: 0x1ddc94, Func Offset: 0x64
	// Line 513, Address: 0x1ddc9c, Func Offset: 0x6c
	// Line 514, Address: 0x1ddca0, Func Offset: 0x70
	// Line 515, Address: 0x1ddca4, Func Offset: 0x74
	// Line 518, Address: 0x1ddca8, Func Offset: 0x78
	// Line 519, Address: 0x1ddcac, Func Offset: 0x7c
	// Line 520, Address: 0x1ddcb0, Func Offset: 0x80
	// Line 521, Address: 0x1ddcb8, Func Offset: 0x88
	// Line 522, Address: 0x1ddcbc, Func Offset: 0x8c
	// Line 523, Address: 0x1ddcc0, Func Offset: 0x90
	// Line 525, Address: 0x1ddccc, Func Offset: 0x9c
	// Line 527, Address: 0x1ddcd4, Func Offset: 0xa4
	// Line 528, Address: 0x1ddcdc, Func Offset: 0xac
	// Line 529, Address: 0x1ddce0, Func Offset: 0xb0
	// Line 533, Address: 0x1ddce8, Func Offset: 0xb8
	// Line 530, Address: 0x1ddcec, Func Offset: 0xbc
	// Line 533, Address: 0x1ddcf0, Func Offset: 0xc0
	// Line 534, Address: 0x1ddcf4, Func Offset: 0xc4
	// Line 535, Address: 0x1ddcf8, Func Offset: 0xc8
	// Line 536, Address: 0x1ddd00, Func Offset: 0xd0
	// Line 537, Address: 0x1ddd04, Func Offset: 0xd4
	// Line 538, Address: 0x1ddd08, Func Offset: 0xd8
	// Line 539, Address: 0x1ddd14, Func Offset: 0xe4
	// Line 543, Address: 0x1ddd18, Func Offset: 0xe8
	// Line 544, Address: 0x1ddd20, Func Offset: 0xf0
	// Line 545, Address: 0x1ddd28, Func Offset: 0xf8
	// Line 546, Address: 0x1ddd30, Func Offset: 0x100
	// Line 547, Address: 0x1ddd38, Func Offset: 0x108
	// Line 548, Address: 0x1ddd40, Func Offset: 0x110
	// Line 549, Address: 0x1ddd48, Func Offset: 0x118
	// Line 550, Address: 0x1ddd50, Func Offset: 0x120
	// Line 551, Address: 0x1ddd58, Func Offset: 0x128
	// Line 554, Address: 0x1ddd68, Func Offset: 0x138
	// Line 555, Address: 0x1ddd74, Func Offset: 0x144
	// Line 559, Address: 0x1ddd84, Func Offset: 0x154
	// Line 560, Address: 0x1ddd94, Func Offset: 0x164
	// Line 565, Address: 0x1ddda0, Func Offset: 0x170
	// Line 564, Address: 0x1ddda8, Func Offset: 0x178
	// Line 565, Address: 0x1dddb0, Func Offset: 0x180
	// Line 566, Address: 0x1dddc8, Func Offset: 0x198
	// Line 567, Address: 0x1ddde4, Func Offset: 0x1b4
	// Line 568, Address: 0x1ddde8, Func Offset: 0x1b8
	// Line 571, Address: 0x1dddec, Func Offset: 0x1bc
	// Line 578, Address: 0x1dddf0, Func Offset: 0x1c0
	// Line 571, Address: 0x1dddf4, Func Offset: 0x1c4
	// Line 572, Address: 0x1dddf8, Func Offset: 0x1c8
	// Line 573, Address: 0x1dde00, Func Offset: 0x1d0
	// Line 575, Address: 0x1dde08, Func Offset: 0x1d8
	// Line 578, Address: 0x1dde10, Func Offset: 0x1e0
	// Line 580, Address: 0x1dde18, Func Offset: 0x1e8
	// Line 582, Address: 0x1dde20, Func Offset: 0x1f0
	// Line 583, Address: 0x1dde34, Func Offset: 0x204
	// Line 586, Address: 0x1dde38, Func Offset: 0x208
	// Line 587, Address: 0x1dde48, Func Offset: 0x218
	// Line 588, Address: 0x1dde58, Func Offset: 0x228
	// Line 589, Address: 0x1dde80, Func Offset: 0x250
	// Line 591, Address: 0x1dde8c, Func Offset: 0x25c
	// Line 592, Address: 0x1dde98, Func Offset: 0x268
	// Line 593, Address: 0x1ddea0, Func Offset: 0x270
	// Line 597, Address: 0x1ddeac, Func Offset: 0x27c
	// Line 599, Address: 0x1ddeb8, Func Offset: 0x288
	// Line 601, Address: 0x1ddec0, Func Offset: 0x290
	// Func End, Address: 0x1dded0, Func Offset: 0x2a0
}

// 
// Start address: 0x1dded0
void bhEne14_Brain(BH_PWORK* epw)
{
	// Line 612, Address: 0x1dded0, Func Offset: 0
	// Func End, Address: 0x1ddef0, Func Offset: 0x20
}

// 
// Start address: 0x1ddef0
void bhEne14_BR00()
{
	// Line 624, Address: 0x1ddef0, Func Offset: 0
	// Func End, Address: 0x1ddef8, Func Offset: 0x8
}

// 
// Start address: 0x1ddf00
void bhEne14_BR01()
{
	// Line 635, Address: 0x1ddf00, Func Offset: 0
	// Func End, Address: 0x1ddf08, Func Offset: 0x8
}

// 
// Start address: 0x1ddf10
void bhEne14_Move(BH_PWORK* epw)
{
	// Line 645, Address: 0x1ddf10, Func Offset: 0
	// Line 647, Address: 0x1ddf20, Func Offset: 0x10
	// Line 650, Address: 0x1ddf40, Func Offset: 0x30
	// Line 651, Address: 0x1ddf50, Func Offset: 0x40
	// Line 655, Address: 0x1ddf58, Func Offset: 0x48
	// Line 656, Address: 0x1ddf78, Func Offset: 0x68
	// Line 657, Address: 0x1ddf84, Func Offset: 0x74
	// Line 659, Address: 0x1ddf8c, Func Offset: 0x7c
	// Func End, Address: 0x1ddf9c, Func Offset: 0x8c
}

// 
// Start address: 0x1ddfa0
void bhEne14_MV00(BH_PWORK* epw)
{
	// Line 670, Address: 0x1ddfa0, Func Offset: 0
	// Line 672, Address: 0x1ddfb4, Func Offset: 0x14
	// Line 673, Address: 0x1ddfbc, Func Offset: 0x1c
	// Line 677, Address: 0x1ddfc0, Func Offset: 0x20
	// Line 672, Address: 0x1ddfc4, Func Offset: 0x24
	// Line 673, Address: 0x1ddfcc, Func Offset: 0x2c
	// Line 678, Address: 0x1ddfd0, Func Offset: 0x30
	// Line 673, Address: 0x1ddfd4, Func Offset: 0x34
	// Line 675, Address: 0x1ddfdc, Func Offset: 0x3c
	// Line 676, Address: 0x1ddfe0, Func Offset: 0x40
	// Line 677, Address: 0x1ddfe4, Func Offset: 0x44
	// Line 678, Address: 0x1ddfe8, Func Offset: 0x48
	// Line 679, Address: 0x1ddfec, Func Offset: 0x4c
	// Line 682, Address: 0x1ddff8, Func Offset: 0x58
	// Func End, Address: 0x1de000, Func Offset: 0x60
}

// 
// Start address: 0x1de000
void bhEne14_MV01(BH_PWORK* epw)
{
	// Line 693, Address: 0x1de000, Func Offset: 0
	// Line 695, Address: 0x1de020, Func Offset: 0x20
	// Line 696, Address: 0x1de02c, Func Offset: 0x2c
	// Line 701, Address: 0x1de030, Func Offset: 0x30
	// Line 695, Address: 0x1de034, Func Offset: 0x34
	// Line 696, Address: 0x1de03c, Func Offset: 0x3c
	// Line 702, Address: 0x1de040, Func Offset: 0x40
	// Line 696, Address: 0x1de044, Func Offset: 0x44
	// Line 699, Address: 0x1de048, Func Offset: 0x48
	// Line 700, Address: 0x1de04c, Func Offset: 0x4c
	// Line 701, Address: 0x1de050, Func Offset: 0x50
	// Line 702, Address: 0x1de054, Func Offset: 0x54
	// Line 703, Address: 0x1de058, Func Offset: 0x58
	// Line 704, Address: 0x1de07c, Func Offset: 0x7c
	// Line 706, Address: 0x1de088, Func Offset: 0x88
	// Line 707, Address: 0x1de098, Func Offset: 0x98
	// Line 708, Address: 0x1de09c, Func Offset: 0x9c
	// Line 709, Address: 0x1de0a0, Func Offset: 0xa0
	// Line 713, Address: 0x1de0a4, Func Offset: 0xa4
	// Line 714, Address: 0x1de0b4, Func Offset: 0xb4
	// Line 715, Address: 0x1de0bc, Func Offset: 0xbc
	// Line 714, Address: 0x1de0c0, Func Offset: 0xc0
	// Line 715, Address: 0x1de0c8, Func Offset: 0xc8
	// Line 718, Address: 0x1de0d0, Func Offset: 0xd0
	// Func End, Address: 0x1de0d8, Func Offset: 0xd8
}

// 
// Start address: 0x1de0e0
void bhEne14_MV02(BH_PWORK* epw)
{
	int fno;
	int ang;
	BH_PWORK* ep;
	// Line 728, Address: 0x1de0e0, Func Offset: 0
	// Line 733, Address: 0x1de0f4, Func Offset: 0x14
	// Line 735, Address: 0x1de114, Func Offset: 0x34
	// Line 736, Address: 0x1de120, Func Offset: 0x40
	// Line 740, Address: 0x1de124, Func Offset: 0x44
	// Line 735, Address: 0x1de128, Func Offset: 0x48
	// Line 736, Address: 0x1de130, Func Offset: 0x50
	// Line 739, Address: 0x1de138, Func Offset: 0x58
	// Line 740, Address: 0x1de13c, Func Offset: 0x5c
	// Line 741, Address: 0x1de16c, Func Offset: 0x8c
	// Line 742, Address: 0x1de178, Func Offset: 0x98
	// Line 743, Address: 0x1de184, Func Offset: 0xa4
	// Line 744, Address: 0x1de190, Func Offset: 0xb0
	// Line 746, Address: 0x1de19c, Func Offset: 0xbc
	// Line 748, Address: 0x1de1a0, Func Offset: 0xc0
	// Line 751, Address: 0x1de1cc, Func Offset: 0xec
	// Line 753, Address: 0x1de1d4, Func Offset: 0xf4
	// Line 754, Address: 0x1de1d8, Func Offset: 0xf8
	// Line 756, Address: 0x1de1e0, Func Offset: 0x100
	// Line 757, Address: 0x1de1e8, Func Offset: 0x108
	// Line 762, Address: 0x1de1f4, Func Offset: 0x114
	// Line 761, Address: 0x1de1f8, Func Offset: 0x118
	// Line 762, Address: 0x1de1fc, Func Offset: 0x11c
	// Line 763, Address: 0x1de200, Func Offset: 0x120
	// Line 764, Address: 0x1de208, Func Offset: 0x128
	// Line 767, Address: 0x1de210, Func Offset: 0x130
	// Line 764, Address: 0x1de214, Func Offset: 0x134
	// Line 767, Address: 0x1de230, Func Offset: 0x150
	// Line 768, Address: 0x1de234, Func Offset: 0x154
	// Line 769, Address: 0x1de23c, Func Offset: 0x15c
	// Line 770, Address: 0x1de244, Func Offset: 0x164
	// Line 771, Address: 0x1de250, Func Offset: 0x170
	// Line 773, Address: 0x1de254, Func Offset: 0x174
	// Line 776, Address: 0x1de260, Func Offset: 0x180
	// Line 777, Address: 0x1de264, Func Offset: 0x184
	// Line 779, Address: 0x1de278, Func Offset: 0x198
	// Line 780, Address: 0x1de288, Func Offset: 0x1a8
	// Line 782, Address: 0x1de290, Func Offset: 0x1b0
	// Line 787, Address: 0x1de2a4, Func Offset: 0x1c4
	// Line 788, Address: 0x1de2bc, Func Offset: 0x1dc
	// Line 792, Address: 0x1de2c8, Func Offset: 0x1e8
	// Line 793, Address: 0x1de2d4, Func Offset: 0x1f4
	// Line 794, Address: 0x1de2dc, Func Offset: 0x1fc
	// Line 793, Address: 0x1de2e0, Func Offset: 0x200
	// Line 794, Address: 0x1de2e8, Func Offset: 0x208
	// Line 797, Address: 0x1de2f0, Func Offset: 0x210
	// Line 798, Address: 0x1de300, Func Offset: 0x220
	// Line 799, Address: 0x1de304, Func Offset: 0x224
	// Line 800, Address: 0x1de308, Func Offset: 0x228
	// Line 802, Address: 0x1de30c, Func Offset: 0x22c
	// Line 806, Address: 0x1de31c, Func Offset: 0x23c
	// Func End, Address: 0x1de330, Func Offset: 0x250
}

// 
// Start address: 0x1de330
void bhEne14_MV03()
{
	// Line 817, Address: 0x1de330, Func Offset: 0
	// Func End, Address: 0x1de338, Func Offset: 0x8
}

// 
// Start address: 0x1de340
void bhEne14_MV04(BH_PWORK* epw)
{
	float dist;
	_anon31 ln;
	_anon24 cp;
	float spd;
	_anon24 v;
	_anon24 vec;
	int ang;
	_anon30* hp;
	float dist;
	// Line 827, Address: 0x1de340, Func Offset: 0
	// Line 830, Address: 0x1de358, Func Offset: 0x18
	// Line 832, Address: 0x1de384, Func Offset: 0x44
	// Line 833, Address: 0x1de38c, Func Offset: 0x4c
	// Line 834, Address: 0x1de390, Func Offset: 0x50
	// Line 832, Address: 0x1de394, Func Offset: 0x54
	// Line 833, Address: 0x1de39c, Func Offset: 0x5c
	// Line 837, Address: 0x1de3a0, Func Offset: 0x60
	// Line 833, Address: 0x1de3a8, Func Offset: 0x68
	// Line 834, Address: 0x1de3b0, Func Offset: 0x70
	// Line 837, Address: 0x1de3b8, Func Offset: 0x78
	// Line 838, Address: 0x1de3c0, Func Offset: 0x80
	// Line 841, Address: 0x1de3c8, Func Offset: 0x88
	// Line 843, Address: 0x1de3d0, Func Offset: 0x90
	// Line 842, Address: 0x1de3d4, Func Offset: 0x94
	// Line 843, Address: 0x1de3d8, Func Offset: 0x98
	// Line 844, Address: 0x1de3dc, Func Offset: 0x9c
	// Line 846, Address: 0x1de3e4, Func Offset: 0xa4
	// Line 849, Address: 0x1de3f0, Func Offset: 0xb0
	// Line 852, Address: 0x1de3f4, Func Offset: 0xb4
	// Line 846, Address: 0x1de3f8, Func Offset: 0xb8
	// Line 849, Address: 0x1de400, Func Offset: 0xc0
	// Line 852, Address: 0x1de404, Func Offset: 0xc4
	// Line 854, Address: 0x1de408, Func Offset: 0xc8
	// Line 862, Address: 0x1de414, Func Offset: 0xd4
	// Line 863, Address: 0x1de42c, Func Offset: 0xec
	// Line 865, Address: 0x1de444, Func Offset: 0x104
	// Line 870, Address: 0x1de460, Func Offset: 0x120
	// Line 865, Address: 0x1de464, Func Offset: 0x124
	// Line 866, Address: 0x1de474, Func Offset: 0x134
	// Line 870, Address: 0x1de490, Func Offset: 0x150
	// Line 871, Address: 0x1de498, Func Offset: 0x158
	// Line 872, Address: 0x1de4a8, Func Offset: 0x168
	// Line 874, Address: 0x1de4b8, Func Offset: 0x178
	// Line 876, Address: 0x1de4fc, Func Offset: 0x1bc
	// Line 877, Address: 0x1de520, Func Offset: 0x1e0
	// Line 878, Address: 0x1de53c, Func Offset: 0x1fc
	// Line 881, Address: 0x1de598, Func Offset: 0x258
	// Line 883, Address: 0x1de5a0, Func Offset: 0x260
	// Line 882, Address: 0x1de5a4, Func Offset: 0x264
	// Line 883, Address: 0x1de5a8, Func Offset: 0x268
	// Line 884, Address: 0x1de5ac, Func Offset: 0x26c
	// Line 886, Address: 0x1de5b4, Func Offset: 0x274
	// Line 887, Address: 0x1de5c0, Func Offset: 0x280
	// Line 888, Address: 0x1de5c8, Func Offset: 0x288
	// Line 891, Address: 0x1de624, Func Offset: 0x2e4
	// Line 893, Address: 0x1de62c, Func Offset: 0x2ec
	// Line 892, Address: 0x1de630, Func Offset: 0x2f0
	// Line 893, Address: 0x1de634, Func Offset: 0x2f4
	// Line 894, Address: 0x1de638, Func Offset: 0x2f8
	// Line 895, Address: 0x1de640, Func Offset: 0x300
	// Line 898, Address: 0x1de64c, Func Offset: 0x30c
	// Line 899, Address: 0x1de66c, Func Offset: 0x32c
	// Line 898, Address: 0x1de670, Func Offset: 0x330
	// Line 899, Address: 0x1de688, Func Offset: 0x348
	// Line 900, Address: 0x1de69c, Func Offset: 0x35c
	// Line 899, Address: 0x1de6a0, Func Offset: 0x360
	// Line 900, Address: 0x1de6a8, Func Offset: 0x368
	// Line 901, Address: 0x1de6c4, Func Offset: 0x384
	// Line 902, Address: 0x1de714, Func Offset: 0x3d4
	// Line 904, Address: 0x1de71c, Func Offset: 0x3dc
	// Line 905, Address: 0x1de73c, Func Offset: 0x3fc
	// Line 904, Address: 0x1de744, Func Offset: 0x404
	// Line 905, Address: 0x1de748, Func Offset: 0x408
	// Line 907, Address: 0x1de76c, Func Offset: 0x42c
	// Line 910, Address: 0x1de7b8, Func Offset: 0x478
	// Line 912, Address: 0x1de7c0, Func Offset: 0x480
	// Line 911, Address: 0x1de7c4, Func Offset: 0x484
	// Line 912, Address: 0x1de7c8, Func Offset: 0x488
	// Line 913, Address: 0x1de7cc, Func Offset: 0x48c
	// Line 915, Address: 0x1de7d4, Func Offset: 0x494
	// Line 917, Address: 0x1de7e0, Func Offset: 0x4a0
	// Line 918, Address: 0x1de800, Func Offset: 0x4c0
	// Line 917, Address: 0x1de804, Func Offset: 0x4c4
	// Line 918, Address: 0x1de81c, Func Offset: 0x4dc
	// Line 919, Address: 0x1de830, Func Offset: 0x4f0
	// Line 918, Address: 0x1de834, Func Offset: 0x4f4
	// Line 919, Address: 0x1de83c, Func Offset: 0x4fc
	// Line 920, Address: 0x1de858, Func Offset: 0x518
	// Line 921, Address: 0x1de8a8, Func Offset: 0x568
	// Line 923, Address: 0x1de8b0, Func Offset: 0x570
	// Line 926, Address: 0x1de8fc, Func Offset: 0x5bc
	// Line 928, Address: 0x1de904, Func Offset: 0x5c4
	// Line 927, Address: 0x1de908, Func Offset: 0x5c8
	// Line 928, Address: 0x1de90c, Func Offset: 0x5cc
	// Line 929, Address: 0x1de910, Func Offset: 0x5d0
	// Line 931, Address: 0x1de914, Func Offset: 0x5d4
	// Line 932, Address: 0x1de934, Func Offset: 0x5f4
	// Line 931, Address: 0x1de938, Func Offset: 0x5f8
	// Line 932, Address: 0x1de950, Func Offset: 0x610
	// Line 933, Address: 0x1de964, Func Offset: 0x624
	// Line 932, Address: 0x1de968, Func Offset: 0x628
	// Line 933, Address: 0x1de970, Func Offset: 0x630
	// Line 934, Address: 0x1de98c, Func Offset: 0x64c
	// Line 945, Address: 0x1de9e0, Func Offset: 0x6a0
	// Line 946, Address: 0x1de9f0, Func Offset: 0x6b0
	// Line 947, Address: 0x1de9f4, Func Offset: 0x6b4
	// Line 948, Address: 0x1dea04, Func Offset: 0x6c4
	// Line 949, Address: 0x1dea08, Func Offset: 0x6c8
	// Line 950, Address: 0x1dea10, Func Offset: 0x6d0
	// Line 953, Address: 0x1dea14, Func Offset: 0x6d4
	// Line 954, Address: 0x1dea1c, Func Offset: 0x6dc
	// Line 961, Address: 0x1dea24, Func Offset: 0x6e4
	// Line 962, Address: 0x1dea34, Func Offset: 0x6f4
	// Line 963, Address: 0x1dea38, Func Offset: 0x6f8
	// Line 961, Address: 0x1dea3c, Func Offset: 0x6fc
	// Line 964, Address: 0x1dea40, Func Offset: 0x700
	// Line 961, Address: 0x1dea44, Func Offset: 0x704
	// Line 962, Address: 0x1dea4c, Func Offset: 0x70c
	// Line 963, Address: 0x1dea60, Func Offset: 0x720
	// Line 964, Address: 0x1dea78, Func Offset: 0x738
	// Line 965, Address: 0x1dea80, Func Offset: 0x740
	// Line 966, Address: 0x1dea9c, Func Offset: 0x75c
	// Line 967, Address: 0x1deaac, Func Offset: 0x76c
	// Line 968, Address: 0x1deabc, Func Offset: 0x77c
	// Line 970, Address: 0x1deacc, Func Offset: 0x78c
	// Line 974, Address: 0x1dead4, Func Offset: 0x794
	// Line 977, Address: 0x1deafc, Func Offset: 0x7bc
	// Line 978, Address: 0x1deb08, Func Offset: 0x7c8
	// Line 980, Address: 0x1deb0c, Func Offset: 0x7cc
	// Line 979, Address: 0x1deb10, Func Offset: 0x7d0
	// Line 980, Address: 0x1deb14, Func Offset: 0x7d4
	// Line 981, Address: 0x1deb18, Func Offset: 0x7d8
	// Line 988, Address: 0x1deb20, Func Offset: 0x7e0
	// Line 989, Address: 0x1deb30, Func Offset: 0x7f0
	// Line 990, Address: 0x1deb3c, Func Offset: 0x7fc
	// Line 991, Address: 0x1deb60, Func Offset: 0x820
	// Line 993, Address: 0x1deb64, Func Offset: 0x824
	// Line 994, Address: 0x1deb6c, Func Offset: 0x82c
	// Line 998, Address: 0x1deb74, Func Offset: 0x834
	// Line 1000, Address: 0x1deb90, Func Offset: 0x850
	// Line 1006, Address: 0x1deba0, Func Offset: 0x860
	// Line 1012, Address: 0x1deba4, Func Offset: 0x864
	// Line 1006, Address: 0x1debb0, Func Offset: 0x870
	// Line 1007, Address: 0x1debb4, Func Offset: 0x874
	// Line 1008, Address: 0x1debc4, Func Offset: 0x884
	// Line 1009, Address: 0x1debd4, Func Offset: 0x894
	// Line 1010, Address: 0x1debe4, Func Offset: 0x8a4
	// Line 1011, Address: 0x1debf4, Func Offset: 0x8b4
	// Line 1012, Address: 0x1dec00, Func Offset: 0x8c0
	// Line 1015, Address: 0x1dec08, Func Offset: 0x8c8
	// Line 1016, Address: 0x1dec24, Func Offset: 0x8e4
	// Line 1017, Address: 0x1dec2c, Func Offset: 0x8ec
	// Line 1018, Address: 0x1dec34, Func Offset: 0x8f4
	// Line 1022, Address: 0x1dec3c, Func Offset: 0x8fc
	// Line 1023, Address: 0x1dec48, Func Offset: 0x908
	// Line 1024, Address: 0x1dec64, Func Offset: 0x924
	// Line 1025, Address: 0x1dec68, Func Offset: 0x928
	// Line 1031, Address: 0x1dec74, Func Offset: 0x934
	// Func End, Address: 0x1dec90, Func Offset: 0x950
}

// 
// Start address: 0x1dec90
void bhEne14_MV05()
{
	// Line 1042, Address: 0x1dec90, Func Offset: 0
	// Func End, Address: 0x1dec98, Func Offset: 0x8
}

// 
// Start address: 0x1deca0
void bhEne14_MV06()
{
	// Line 1053, Address: 0x1deca0, Func Offset: 0
	// Func End, Address: 0x1deca8, Func Offset: 0x8
}

// 
// Start address: 0x1decb0
void bhEne14_MV07()
{
	// Line 1064, Address: 0x1decb0, Func Offset: 0
	// Func End, Address: 0x1decb8, Func Offset: 0x8
}

// 
// Start address: 0x1decc0
void bhEne14_MV08()
{
	// Line 1075, Address: 0x1decc0, Func Offset: 0
	// Func End, Address: 0x1decc8, Func Offset: 0x8
}

// 
// Start address: 0x1decd0
void bhEne14_MV09()
{
	// Line 1086, Address: 0x1decd0, Func Offset: 0
	// Func End, Address: 0x1decd8, Func Offset: 0x8
}

// 
// Start address: 0x1dece0
void bhEne14_MV10()
{
	// Line 1097, Address: 0x1dece0, Func Offset: 0
	// Func End, Address: 0x1dece8, Func Offset: 0x8
}

// 
// Start address: 0x1decf0
void bhEne14_MV11(BH_PWORK* epw)
{
	float dist;
	_anon31 ln;
	_anon24 cp;
	float spd;
	_anon24 v;
	_anon24 vec;
	int ang;
	_anon30* hp;
	float dist;
	// Line 1107, Address: 0x1decf0, Func Offset: 0
	// Line 1110, Address: 0x1ded08, Func Offset: 0x18
	// Line 1112, Address: 0x1ded34, Func Offset: 0x44
	// Line 1113, Address: 0x1ded3c, Func Offset: 0x4c
	// Line 1114, Address: 0x1ded40, Func Offset: 0x50
	// Line 1112, Address: 0x1ded44, Func Offset: 0x54
	// Line 1113, Address: 0x1ded4c, Func Offset: 0x5c
	// Line 1117, Address: 0x1ded50, Func Offset: 0x60
	// Line 1113, Address: 0x1ded58, Func Offset: 0x68
	// Line 1114, Address: 0x1ded60, Func Offset: 0x70
	// Line 1117, Address: 0x1ded68, Func Offset: 0x78
	// Line 1118, Address: 0x1ded70, Func Offset: 0x80
	// Line 1121, Address: 0x1ded78, Func Offset: 0x88
	// Line 1123, Address: 0x1ded80, Func Offset: 0x90
	// Line 1122, Address: 0x1ded84, Func Offset: 0x94
	// Line 1123, Address: 0x1ded88, Func Offset: 0x98
	// Line 1124, Address: 0x1ded8c, Func Offset: 0x9c
	// Line 1126, Address: 0x1ded94, Func Offset: 0xa4
	// Line 1129, Address: 0x1deda8, Func Offset: 0xb8
	// Line 1130, Address: 0x1dedb4, Func Offset: 0xc4
	// Line 1131, Address: 0x1dedb8, Func Offset: 0xc8
	// Line 1132, Address: 0x1dedc0, Func Offset: 0xd0
	// Line 1136, Address: 0x1dedc4, Func Offset: 0xd4
	// Line 1139, Address: 0x1dedd8, Func Offset: 0xe8
	// Line 1141, Address: 0x1dede0, Func Offset: 0xf0
	// Line 1149, Address: 0x1dedec, Func Offset: 0xfc
	// Line 1150, Address: 0x1dee04, Func Offset: 0x114
	// Line 1152, Address: 0x1dee1c, Func Offset: 0x12c
	// Line 1157, Address: 0x1dee38, Func Offset: 0x148
	// Line 1152, Address: 0x1dee3c, Func Offset: 0x14c
	// Line 1153, Address: 0x1dee4c, Func Offset: 0x15c
	// Line 1157, Address: 0x1dee68, Func Offset: 0x178
	// Line 1158, Address: 0x1dee70, Func Offset: 0x180
	// Line 1159, Address: 0x1dee80, Func Offset: 0x190
	// Line 1162, Address: 0x1dee90, Func Offset: 0x1a0
	// Line 1163, Address: 0x1deeb4, Func Offset: 0x1c4
	// Line 1164, Address: 0x1deed0, Func Offset: 0x1e0
	// Line 1165, Address: 0x1def28, Func Offset: 0x238
	// Line 1166, Address: 0x1def30, Func Offset: 0x240
	// Line 1169, Address: 0x1def8c, Func Offset: 0x29c
	// Line 1170, Address: 0x1defac, Func Offset: 0x2bc
	// Line 1169, Address: 0x1defb0, Func Offset: 0x2c0
	// Line 1170, Address: 0x1defc8, Func Offset: 0x2d8
	// Line 1171, Address: 0x1defdc, Func Offset: 0x2ec
	// Line 1170, Address: 0x1defe0, Func Offset: 0x2f0
	// Line 1171, Address: 0x1defe8, Func Offset: 0x2f8
	// Line 1172, Address: 0x1df004, Func Offset: 0x314
	// Line 1177, Address: 0x1df058, Func Offset: 0x368
	// Line 1179, Address: 0x1df060, Func Offset: 0x370
	// Line 1180, Address: 0x1df068, Func Offset: 0x378
	// Line 1187, Address: 0x1df070, Func Offset: 0x380
	// Line 1188, Address: 0x1df080, Func Offset: 0x390
	// Line 1189, Address: 0x1df084, Func Offset: 0x394
	// Line 1187, Address: 0x1df088, Func Offset: 0x398
	// Line 1190, Address: 0x1df08c, Func Offset: 0x39c
	// Line 1187, Address: 0x1df090, Func Offset: 0x3a0
	// Line 1188, Address: 0x1df098, Func Offset: 0x3a8
	// Line 1189, Address: 0x1df0ac, Func Offset: 0x3bc
	// Line 1190, Address: 0x1df0c4, Func Offset: 0x3d4
	// Line 1191, Address: 0x1df0cc, Func Offset: 0x3dc
	// Line 1192, Address: 0x1df0e8, Func Offset: 0x3f8
	// Line 1193, Address: 0x1df0f8, Func Offset: 0x408
	// Line 1194, Address: 0x1df108, Func Offset: 0x418
	// Line 1196, Address: 0x1df118, Func Offset: 0x428
	// Line 1200, Address: 0x1df120, Func Offset: 0x430
	// Line 1203, Address: 0x1df140, Func Offset: 0x450
	// Line 1200, Address: 0x1df144, Func Offset: 0x454
	// Line 1203, Address: 0x1df14c, Func Offset: 0x45c
	// Line 1204, Address: 0x1df158, Func Offset: 0x468
	// Line 1206, Address: 0x1df160, Func Offset: 0x470
	// Line 1207, Address: 0x1df184, Func Offset: 0x494
	// Line 1210, Address: 0x1df18c, Func Offset: 0x49c
	// Line 1211, Address: 0x1df19c, Func Offset: 0x4ac
	// Line 1212, Address: 0x1df1c4, Func Offset: 0x4d4
	// Line 1214, Address: 0x1df1cc, Func Offset: 0x4dc
	// Line 1215, Address: 0x1df1d4, Func Offset: 0x4e4
	// Line 1220, Address: 0x1df1d8, Func Offset: 0x4e8
	// Line 1226, Address: 0x1df1e8, Func Offset: 0x4f8
	// Line 1232, Address: 0x1df1ec, Func Offset: 0x4fc
	// Line 1226, Address: 0x1df1f8, Func Offset: 0x508
	// Line 1227, Address: 0x1df1fc, Func Offset: 0x50c
	// Line 1228, Address: 0x1df20c, Func Offset: 0x51c
	// Line 1229, Address: 0x1df21c, Func Offset: 0x52c
	// Line 1230, Address: 0x1df22c, Func Offset: 0x53c
	// Line 1231, Address: 0x1df23c, Func Offset: 0x54c
	// Line 1232, Address: 0x1df248, Func Offset: 0x558
	// Line 1234, Address: 0x1df250, Func Offset: 0x560
	// Line 1235, Address: 0x1df26c, Func Offset: 0x57c
	// Line 1239, Address: 0x1df270, Func Offset: 0x580
	// Line 1240, Address: 0x1df27c, Func Offset: 0x58c
	// Line 1241, Address: 0x1df288, Func Offset: 0x598
	// Line 1242, Address: 0x1df2a4, Func Offset: 0x5b4
	// Line 1243, Address: 0x1df2a8, Func Offset: 0x5b8
	// Line 1249, Address: 0x1df2b4, Func Offset: 0x5c4
	// Func End, Address: 0x1df2d0, Func Offset: 0x5e0
}

// 
// Start address: 0x1df2d0
void bhEne14_Nage(BH_PWORK* epw)
{
	// Line 1260, Address: 0x1df2d0, Func Offset: 0
	// Func End, Address: 0x1df2f0, Func Offset: 0x20
}

// 
// Start address: 0x1df2f0
void bhEne14_NG00()
{
	// Line 1272, Address: 0x1df2f0, Func Offset: 0
	// Func End, Address: 0x1df2f8, Func Offset: 0x8
}

// 
// Start address: 0x1df300
void bhEne14_Damage(BH_PWORK* epw)
{
	// Line 1283, Address: 0x1df300, Func Offset: 0
	// Func End, Address: 0x1df320, Func Offset: 0x20
}

// 
// Start address: 0x1df320
void bhEne14_DG00(BH_PWORK* epw)
{
	// Line 1295, Address: 0x1df320, Func Offset: 0
	// Line 1297, Address: 0x1df340, Func Offset: 0x20
	// Line 1298, Address: 0x1df34c, Func Offset: 0x2c
	// Line 1301, Address: 0x1df350, Func Offset: 0x30
	// Line 1297, Address: 0x1df354, Func Offset: 0x34
	// Line 1298, Address: 0x1df35c, Func Offset: 0x3c
	// Line 1304, Address: 0x1df360, Func Offset: 0x40
	// Line 1306, Address: 0x1df364, Func Offset: 0x44
	// Line 1298, Address: 0x1df368, Func Offset: 0x48
	// Line 1301, Address: 0x1df36c, Func Offset: 0x4c
	// Line 1302, Address: 0x1df370, Func Offset: 0x50
	// Line 1303, Address: 0x1df374, Func Offset: 0x54
	// Line 1304, Address: 0x1df378, Func Offset: 0x58
	// Line 1305, Address: 0x1df37c, Func Offset: 0x5c
	// Line 1306, Address: 0x1df3a0, Func Offset: 0x80
	// Line 1307, Address: 0x1df3ac, Func Offset: 0x8c
	// Line 1309, Address: 0x1df3b8, Func Offset: 0x98
	// Line 1310, Address: 0x1df3c8, Func Offset: 0xa8
	// Line 1311, Address: 0x1df3d0, Func Offset: 0xb0
	// Line 1312, Address: 0x1df3d4, Func Offset: 0xb4
	// Line 1313, Address: 0x1df3d8, Func Offset: 0xb8
	// Line 1315, Address: 0x1df3dc, Func Offset: 0xbc
	// Line 1317, Address: 0x1df3e4, Func Offset: 0xc4
	// Line 1318, Address: 0x1df3e8, Func Offset: 0xc8
	// Line 1315, Address: 0x1df3ec, Func Offset: 0xcc
	// Line 1317, Address: 0x1df3f4, Func Offset: 0xd4
	// Line 1318, Address: 0x1df400, Func Offset: 0xe0
	// Line 1321, Address: 0x1df408, Func Offset: 0xe8
	// Func End, Address: 0x1df410, Func Offset: 0xf0
}

// 
// Start address: 0x1df410
void bhEne14_DG01(BH_PWORK* epw)
{
	// Line 1332, Address: 0x1df410, Func Offset: 0
	// Line 1334, Address: 0x1df430, Func Offset: 0x20
	// Line 1335, Address: 0x1df43c, Func Offset: 0x2c
	// Line 1338, Address: 0x1df440, Func Offset: 0x30
	// Line 1334, Address: 0x1df444, Func Offset: 0x34
	// Line 1335, Address: 0x1df44c, Func Offset: 0x3c
	// Line 1341, Address: 0x1df450, Func Offset: 0x40
	// Line 1343, Address: 0x1df454, Func Offset: 0x44
	// Line 1335, Address: 0x1df458, Func Offset: 0x48
	// Line 1338, Address: 0x1df45c, Func Offset: 0x4c
	// Line 1339, Address: 0x1df460, Func Offset: 0x50
	// Line 1340, Address: 0x1df464, Func Offset: 0x54
	// Line 1341, Address: 0x1df468, Func Offset: 0x58
	// Line 1342, Address: 0x1df46c, Func Offset: 0x5c
	// Line 1343, Address: 0x1df490, Func Offset: 0x80
	// Line 1344, Address: 0x1df49c, Func Offset: 0x8c
	// Line 1346, Address: 0x1df4a8, Func Offset: 0x98
	// Line 1347, Address: 0x1df4b8, Func Offset: 0xa8
	// Line 1348, Address: 0x1df4c0, Func Offset: 0xb0
	// Line 1349, Address: 0x1df4c4, Func Offset: 0xb4
	// Line 1350, Address: 0x1df4c8, Func Offset: 0xb8
	// Line 1352, Address: 0x1df4cc, Func Offset: 0xbc
	// Line 1354, Address: 0x1df4d4, Func Offset: 0xc4
	// Line 1355, Address: 0x1df4d8, Func Offset: 0xc8
	// Line 1352, Address: 0x1df4dc, Func Offset: 0xcc
	// Line 1354, Address: 0x1df4e4, Func Offset: 0xd4
	// Line 1355, Address: 0x1df4f0, Func Offset: 0xe0
	// Line 1358, Address: 0x1df4f8, Func Offset: 0xe8
	// Func End, Address: 0x1df500, Func Offset: 0xf0
}

// 
// Start address: 0x1df500
void bhEne14_Die()
{
	// Line 1369, Address: 0x1df500, Func Offset: 0
	// Func End, Address: 0x1df508, Func Offset: 0x8
}

// 
// Start address: 0x1df510
void bhEne14_InitDamage(BH_PWORK* epw)
{
	// Line 1380, Address: 0x1df510, Func Offset: 0
	// Func End, Address: 0x1df518, Func Offset: 0x8
}

// 
// Start address: 0x1df520
void bhEne14_LookPlayaer(BH_PWORK* epw)
{
	npobj* objP;
	_anon12* mkaP;
	int ang;
	float out;
	_anon24 ov;
	_anon24 vec;
	_anon24 view;
	int rz2;
	int rz1;
	int rz;
	int ry;
	int rx;
	float* mat2;
	float* mat;
	// Line 1391, Address: 0x1df520, Func Offset: 0
	// Line 1392, Address: 0x1df544, Func Offset: 0x24
	// Line 1391, Address: 0x1df548, Func Offset: 0x28
	// Line 1392, Address: 0x1df54c, Func Offset: 0x2c
	// Line 1401, Address: 0x1df550, Func Offset: 0x30
	// Line 1393, Address: 0x1df55c, Func Offset: 0x3c
	// Line 1401, Address: 0x1df560, Func Offset: 0x40
	// Line 1402, Address: 0x1df568, Func Offset: 0x48
	// Line 1403, Address: 0x1df574, Func Offset: 0x54
	// Line 1402, Address: 0x1df578, Func Offset: 0x58
	// Line 1403, Address: 0x1df580, Func Offset: 0x60
	// Line 1404, Address: 0x1df590, Func Offset: 0x70
	// Line 1406, Address: 0x1df598, Func Offset: 0x78
	// Line 1408, Address: 0x1df59c, Func Offset: 0x7c
	// Line 1406, Address: 0x1df5a0, Func Offset: 0x80
	// Line 1408, Address: 0x1df5b0, Func Offset: 0x90
	// Line 1411, Address: 0x1df5c0, Func Offset: 0xa0
	// Line 1415, Address: 0x1df5c4, Func Offset: 0xa4
	// Line 1411, Address: 0x1df5c8, Func Offset: 0xa8
	// Line 1412, Address: 0x1df5cc, Func Offset: 0xac
	// Line 1411, Address: 0x1df5d0, Func Offset: 0xb0
	// Line 1415, Address: 0x1df5e4, Func Offset: 0xc4
	// Line 1411, Address: 0x1df5e8, Func Offset: 0xc8
	// Line 1412, Address: 0x1df5ec, Func Offset: 0xcc
	// Line 1415, Address: 0x1df5fc, Func Offset: 0xdc
	// Line 1416, Address: 0x1df604, Func Offset: 0xe4
	// Line 1417, Address: 0x1df610, Func Offset: 0xf0
	// Line 1418, Address: 0x1df630, Func Offset: 0x110
	// Line 1419, Address: 0x1df638, Func Offset: 0x118
	// Line 1420, Address: 0x1df644, Func Offset: 0x124
	// Line 1422, Address: 0x1df65c, Func Offset: 0x13c
	// Line 1424, Address: 0x1df664, Func Offset: 0x144
	// Line 1425, Address: 0x1df670, Func Offset: 0x150
	// Line 1426, Address: 0x1df674, Func Offset: 0x154
	// Line 1424, Address: 0x1df678, Func Offset: 0x158
	// Line 1427, Address: 0x1df680, Func Offset: 0x160
	// Line 1424, Address: 0x1df684, Func Offset: 0x164
	// Line 1425, Address: 0x1df698, Func Offset: 0x178
	// Line 1426, Address: 0x1df6b8, Func Offset: 0x198
	// Line 1427, Address: 0x1df6d4, Func Offset: 0x1b4
	// Line 1430, Address: 0x1df6dc, Func Offset: 0x1bc
	// Line 1431, Address: 0x1df6f0, Func Offset: 0x1d0
	// Line 1432, Address: 0x1df6f8, Func Offset: 0x1d8
	// Line 1435, Address: 0x1df708, Func Offset: 0x1e8
	// Line 1436, Address: 0x1df724, Func Offset: 0x204
	// Line 1435, Address: 0x1df72c, Func Offset: 0x20c
	// Line 1436, Address: 0x1df730, Func Offset: 0x210
	// Line 1437, Address: 0x1df740, Func Offset: 0x220
	// Line 1438, Address: 0x1df750, Func Offset: 0x230
	// Line 1439, Address: 0x1df760, Func Offset: 0x240
	// Line 1440, Address: 0x1df770, Func Offset: 0x250
	// Line 1441, Address: 0x1df780, Func Offset: 0x260
	// Line 1442, Address: 0x1df784, Func Offset: 0x264
	// Line 1443, Address: 0x1df788, Func Offset: 0x268
	// Line 1444, Address: 0x1df790, Func Offset: 0x270
	// Line 1445, Address: 0x1df798, Func Offset: 0x278
	// Line 1446, Address: 0x1df7ac, Func Offset: 0x28c
	// Line 1449, Address: 0x1df7bc, Func Offset: 0x29c
	// Line 1450, Address: 0x1df7c0, Func Offset: 0x2a0
	// Line 1451, Address: 0x1df7c4, Func Offset: 0x2a4
	// Line 1452, Address: 0x1df7c8, Func Offset: 0x2a8
	// Line 1453, Address: 0x1df7dc, Func Offset: 0x2bc
	// Line 1454, Address: 0x1df7e8, Func Offset: 0x2c8
	// Line 1456, Address: 0x1df808, Func Offset: 0x2e8
	// Line 1457, Address: 0x1df814, Func Offset: 0x2f4
	// Line 1460, Address: 0x1df828, Func Offset: 0x308
	// Line 1461, Address: 0x1df844, Func Offset: 0x324
	// Line 1464, Address: 0x1df854, Func Offset: 0x334
	// Line 1466, Address: 0x1df864, Func Offset: 0x344
	// Line 1468, Address: 0x1df87c, Func Offset: 0x35c
	// Line 1469, Address: 0x1df890, Func Offset: 0x370
	// Line 1470, Address: 0x1df898, Func Offset: 0x378
	// Line 1471, Address: 0x1df8a8, Func Offset: 0x388
	// Line 1474, Address: 0x1df8b4, Func Offset: 0x394
	// Line 1475, Address: 0x1df8d0, Func Offset: 0x3b0
	// Line 1478, Address: 0x1df8f0, Func Offset: 0x3d0
	// Line 1479, Address: 0x1df904, Func Offset: 0x3e4
	// Line 1480, Address: 0x1df910, Func Offset: 0x3f0
	// Line 1482, Address: 0x1df944, Func Offset: 0x424
	// Line 1483, Address: 0x1df94c, Func Offset: 0x42c
	// Line 1484, Address: 0x1df95c, Func Offset: 0x43c
	// Line 1485, Address: 0x1df96c, Func Offset: 0x44c
	// Line 1488, Address: 0x1df978, Func Offset: 0x458
	// Line 1489, Address: 0x1df998, Func Offset: 0x478
	// Line 1488, Address: 0x1df99c, Func Offset: 0x47c
	// Line 1489, Address: 0x1df9a0, Func Offset: 0x480
	// Line 1491, Address: 0x1df9a8, Func Offset: 0x488
	// Line 1495, Address: 0x1df9b8, Func Offset: 0x498
	// Line 1496, Address: 0x1df9c4, Func Offset: 0x4a4
	// Line 1495, Address: 0x1df9cc, Func Offset: 0x4ac
	// Line 1496, Address: 0x1df9d0, Func Offset: 0x4b0
	// Line 1497, Address: 0x1df9d8, Func Offset: 0x4b8
	// Line 1501, Address: 0x1df9fc, Func Offset: 0x4dc
	// Line 1509, Address: 0x1dfa00, Func Offset: 0x4e0
	// Line 1501, Address: 0x1dfa04, Func Offset: 0x4e4
	// Line 1504, Address: 0x1dfa08, Func Offset: 0x4e8
	// Line 1505, Address: 0x1dfa0c, Func Offset: 0x4ec
	// Line 1506, Address: 0x1dfa10, Func Offset: 0x4f0
	// Line 1509, Address: 0x1dfa14, Func Offset: 0x4f4
	// Line 1510, Address: 0x1dfa24, Func Offset: 0x504
	// Line 1511, Address: 0x1dfa38, Func Offset: 0x518
	// Line 1513, Address: 0x1dfa48, Func Offset: 0x528
	// Func End, Address: 0x1dfa74, Func Offset: 0x554
}

// 
// Start address: 0x1dfa80
void bhEne14_TailInit(BH_PWORK* epw)
{
	_anon4* p;
	int i;
	// Line 1527, Address: 0x1dfa80, Func Offset: 0
	// Line 1528, Address: 0x1dfa84, Func Offset: 0x4
	// Line 1527, Address: 0x1dfa90, Func Offset: 0x10
	// Line 1539, Address: 0x1dfa98, Func Offset: 0x18
	// Line 1530, Address: 0x1dfa9c, Func Offset: 0x1c
	// Line 1540, Address: 0x1dfaa0, Func Offset: 0x20
	// Line 1530, Address: 0x1dfaa4, Func Offset: 0x24
	// Line 1540, Address: 0x1dfaa8, Func Offset: 0x28
	// Line 1530, Address: 0x1dfaac, Func Offset: 0x2c
	// Line 1531, Address: 0x1dfab4, Func Offset: 0x34
	// Line 1532, Address: 0x1dfac4, Func Offset: 0x44
	// Line 1535, Address: 0x1dfad4, Func Offset: 0x54
	// Line 1540, Address: 0x1dfad8, Func Offset: 0x58
	// Line 1535, Address: 0x1dfadc, Func Offset: 0x5c
	// Line 1536, Address: 0x1dfae4, Func Offset: 0x64
	// Line 1537, Address: 0x1dfaf0, Func Offset: 0x70
	// Line 1539, Address: 0x1dfafc, Func Offset: 0x7c
	// Line 1540, Address: 0x1dfb0c, Func Offset: 0x8c
	// Line 1541, Address: 0x1dfb14, Func Offset: 0x94
	// Func End, Address: 0x1dfb1c, Func Offset: 0x9c
}

// 
// Start address: 0x1dfb20
void bhEne14_TailSwing(BH_PWORK* epw)
{
	npobj* objp;
	_anon4* owp;
	int i;
	_anon24 v;
	float g[11];
	float n[11];
	// Line 1569, Address: 0x1dfb20, Func Offset: 0
	// Line 1604, Address: 0x1dfb3c, Func Offset: 0x1c
	// Line 1606, Address: 0x1dfb44, Func Offset: 0x24
	// Line 1607, Address: 0x1dfb4c, Func Offset: 0x2c
	// Line 1610, Address: 0x1dfb50, Func Offset: 0x30
	// Line 1607, Address: 0x1dfb58, Func Offset: 0x38
	// Line 1608, Address: 0x1dfb64, Func Offset: 0x44
	// Line 1609, Address: 0x1dfb74, Func Offset: 0x54
	// Line 1610, Address: 0x1dfb84, Func Offset: 0x64
	// Line 1612, Address: 0x1dfb8c, Func Offset: 0x6c
	// Line 1613, Address: 0x1dfba4, Func Offset: 0x84
	// Line 1612, Address: 0x1dfbac, Func Offset: 0x8c
	// Line 1615, Address: 0x1dfbb0, Func Offset: 0x90
	// Line 1623, Address: 0x1dfbb4, Func Offset: 0x94
	// Line 1615, Address: 0x1dfbb8, Func Offset: 0x98
	// Line 1623, Address: 0x1dfbbc, Func Offset: 0x9c
	// Line 1615, Address: 0x1dfbc0, Func Offset: 0xa0
	// Line 1616, Address: 0x1dfbd8, Func Offset: 0xb8
	// Line 1617, Address: 0x1dfbf8, Func Offset: 0xd8
	// Line 1622, Address: 0x1dfc0c, Func Offset: 0xec
	// Line 1617, Address: 0x1dfc10, Func Offset: 0xf0
	// Line 1620, Address: 0x1dfc1c, Func Offset: 0xfc
	// Line 1621, Address: 0x1dfc40, Func Offset: 0x120
	// Line 1622, Address: 0x1dfc64, Func Offset: 0x144
	// Line 1623, Address: 0x1dfc80, Func Offset: 0x160
	// Line 1622, Address: 0x1dfc84, Func Offset: 0x164
	// Line 1623, Address: 0x1dfc90, Func Offset: 0x170
	// Line 1626, Address: 0x1dfc98, Func Offset: 0x178
	// Line 1631, Address: 0x1dfca0, Func Offset: 0x180
	// Line 1626, Address: 0x1dfca8, Func Offset: 0x188
	// Line 1627, Address: 0x1dfcb4, Func Offset: 0x194
	// Line 1628, Address: 0x1dfcc8, Func Offset: 0x1a8
	// Line 1632, Address: 0x1dfcdc, Func Offset: 0x1bc
	// Line 1633, Address: 0x1dfce0, Func Offset: 0x1c0
	// Line 1634, Address: 0x1dfce4, Func Offset: 0x1c4
	// Line 1635, Address: 0x1dfce8, Func Offset: 0x1c8
	// Line 1632, Address: 0x1dfcec, Func Offset: 0x1cc
	// Line 1633, Address: 0x1dfd00, Func Offset: 0x1e0
	// Line 1634, Address: 0x1dfd18, Func Offset: 0x1f8
	// Line 1635, Address: 0x1dfd2c, Func Offset: 0x20c
	// Line 1636, Address: 0x1dfd34, Func Offset: 0x214
	// Line 1639, Address: 0x1dfd44, Func Offset: 0x224
	// Line 1636, Address: 0x1dfd48, Func Offset: 0x228
	// Line 1639, Address: 0x1dfd54, Func Offset: 0x234
	// Line 1636, Address: 0x1dfd58, Func Offset: 0x238
	// Line 1637, Address: 0x1dfd60, Func Offset: 0x240
	// Line 1638, Address: 0x1dfd7c, Func Offset: 0x25c
	// Line 1639, Address: 0x1dfd98, Func Offset: 0x278
	// Line 1642, Address: 0x1dfda0, Func Offset: 0x280
	// Line 1643, Address: 0x1dfda8, Func Offset: 0x288
	// Line 1646, Address: 0x1dfdac, Func Offset: 0x28c
	// Line 1643, Address: 0x1dfdb4, Func Offset: 0x294
	// Line 1644, Address: 0x1dfdc8, Func Offset: 0x2a8
	// Line 1645, Address: 0x1dfde0, Func Offset: 0x2c0
	// Line 1646, Address: 0x1dfdf8, Func Offset: 0x2d8
	// Line 1649, Address: 0x1dfe00, Func Offset: 0x2e0
	// Line 1651, Address: 0x1dfe04, Func Offset: 0x2e4
	// Line 1649, Address: 0x1dfe08, Func Offset: 0x2e8
	// Line 1650, Address: 0x1dfe0c, Func Offset: 0x2ec
	// Line 1649, Address: 0x1dfe10, Func Offset: 0x2f0
	// Line 1651, Address: 0x1dfe14, Func Offset: 0x2f4
	// Line 1652, Address: 0x1dfe20, Func Offset: 0x300
	// Line 1653, Address: 0x1dfe24, Func Offset: 0x304
	// Line 1654, Address: 0x1dfe2c, Func Offset: 0x30c
	// Line 1655, Address: 0x1dfe34, Func Offset: 0x314
	// Line 1656, Address: 0x1dfe5c, Func Offset: 0x33c
	// Line 1659, Address: 0x1dfe64, Func Offset: 0x344
	// Line 1660, Address: 0x1dfe7c, Func Offset: 0x35c
	// Line 1661, Address: 0x1dfe80, Func Offset: 0x360
	// Line 1664, Address: 0x1dfe98, Func Offset: 0x378
	// Line 1665, Address: 0x1dfeb0, Func Offset: 0x390
	// Line 1666, Address: 0x1dfec8, Func Offset: 0x3a8
	// Line 1667, Address: 0x1dfee0, Func Offset: 0x3c0
	// Line 1669, Address: 0x1dfef8, Func Offset: 0x3d8
	// Line 1670, Address: 0x1dff04, Func Offset: 0x3e4
	// Line 1671, Address: 0x1dff10, Func Offset: 0x3f0
	// Line 1692, Address: 0x1dff20, Func Offset: 0x400
	// Func End, Address: 0x1dff40, Func Offset: 0x420
}

// 
// Start address: 0x1dff40
int bhEne14_HitMark(BH_PWORK* epw)
{
	_anon11* blp;
	_anon24 ofp;
	int i;
	int range;
	// Line 1702, Address: 0x1dff40, Func Offset: 0
	// Line 1708, Address: 0x1dff4c, Func Offset: 0xc
	// Line 1702, Address: 0x1dff50, Func Offset: 0x10
	// Line 1708, Address: 0x1dff54, Func Offset: 0x14
	// Line 1702, Address: 0x1dff58, Func Offset: 0x18
	// Line 1708, Address: 0x1dff64, Func Offset: 0x24
	// Line 1702, Address: 0x1dff70, Func Offset: 0x30
	// Line 1708, Address: 0x1dff74, Func Offset: 0x34
	// Line 1711, Address: 0x1dff7c, Func Offset: 0x3c
	// Line 1712, Address: 0x1dff84, Func Offset: 0x44
	// Line 1711, Address: 0x1dff88, Func Offset: 0x48
	// Line 1712, Address: 0x1dff9c, Func Offset: 0x5c
	// Line 1713, Address: 0x1dffa0, Func Offset: 0x60
	// Line 1714, Address: 0x1dffb0, Func Offset: 0x70
	// Line 1715, Address: 0x1dffc0, Func Offset: 0x80
	// Line 1716, Address: 0x1dffe8, Func Offset: 0xa8
	// Line 1717, Address: 0x1dffec, Func Offset: 0xac
	// Line 1716, Address: 0x1dfff0, Func Offset: 0xb0
	// Line 1717, Address: 0x1dfff4, Func Offset: 0xb4
	// Line 1718, Address: 0x1dfffc, Func Offset: 0xbc
	// Line 1719, Address: 0x1e0024, Func Offset: 0xe4
	// Line 1720, Address: 0x1e0064, Func Offset: 0x124
	// Line 1721, Address: 0x1e00a4, Func Offset: 0x164
	// Line 1723, Address: 0x1e00e4, Func Offset: 0x1a4
	// Line 1733, Address: 0x1e0114, Func Offset: 0x1d4
	// Line 1734, Address: 0x1e0144, Func Offset: 0x204
	// Line 1736, Address: 0x1e014c, Func Offset: 0x20c
	// Line 1748, Address: 0x1e017c, Func Offset: 0x23c
	// Line 1749, Address: 0x1e01b0, Func Offset: 0x270
	// Line 1750, Address: 0x1e01b4, Func Offset: 0x274
	// Line 1751, Address: 0x1e01b8, Func Offset: 0x278
	// Line 1752, Address: 0x1e01bc, Func Offset: 0x27c
	// Line 1750, Address: 0x1e01c0, Func Offset: 0x280
	// Line 1751, Address: 0x1e01c4, Func Offset: 0x284
	// Line 1752, Address: 0x1e01cc, Func Offset: 0x28c
	// Line 1753, Address: 0x1e01d4, Func Offset: 0x294
	// Line 1754, Address: 0x1e0214, Func Offset: 0x2d4
	// Line 1755, Address: 0x1e0254, Func Offset: 0x314
	// Line 1756, Address: 0x1e0290, Func Offset: 0x350
	// Line 1757, Address: 0x1e0318, Func Offset: 0x3d8
	// Line 1760, Address: 0x1e0328, Func Offset: 0x3e8
	// Line 1761, Address: 0x1e0350, Func Offset: 0x410
	// Line 1762, Address: 0x1e0354, Func Offset: 0x414
	// Line 1763, Address: 0x1e0358, Func Offset: 0x418
	// Line 1761, Address: 0x1e035c, Func Offset: 0x41c
	// Line 1762, Address: 0x1e0360, Func Offset: 0x420
	// Line 1763, Address: 0x1e0368, Func Offset: 0x428
	// Line 1764, Address: 0x1e0370, Func Offset: 0x430
	// Line 1765, Address: 0x1e03b0, Func Offset: 0x470
	// Line 1766, Address: 0x1e03f0, Func Offset: 0x4b0
	// Line 1767, Address: 0x1e040c, Func Offset: 0x4cc
	// Line 1766, Address: 0x1e0410, Func Offset: 0x4d0
	// Line 1767, Address: 0x1e0434, Func Offset: 0x4f4
	// Line 1771, Address: 0x1e0440, Func Offset: 0x500
	// Line 1772, Address: 0x1e0450, Func Offset: 0x510
	// Line 1774, Address: 0x1e0460, Func Offset: 0x520
	// Line 1776, Address: 0x1e0478, Func Offset: 0x538
	// Line 1777, Address: 0x1e0488, Func Offset: 0x548
	// Line 1778, Address: 0x1e0498, Func Offset: 0x558
	// Line 1780, Address: 0x1e049c, Func Offset: 0x55c
	// Line 1778, Address: 0x1e04a0, Func Offset: 0x560
	// Line 1780, Address: 0x1e04a8, Func Offset: 0x568
	// Line 1783, Address: 0x1e04b0, Func Offset: 0x570
	// Line 1785, Address: 0x1e04b8, Func Offset: 0x578
	// Line 1786, Address: 0x1e04c4, Func Offset: 0x584
	// Line 1790, Address: 0x1e04d0, Func Offset: 0x590
	// Line 1791, Address: 0x1e04d4, Func Offset: 0x594
	// Func End, Address: 0x1e04f8, Func Offset: 0x5b8
}

// 
// Start address: 0x1e0500
void bhEne14_Acid(BH_PWORK* epw, int se)
{
	float t;
	float dt;
	_anon4* owk;
	int rapid;
	int i;
	int eno;
	// Line 1802, Address: 0x1e0500, Func Offset: 0
	// Line 1822, Address: 0x1e0504, Func Offset: 0x4
	// Line 1802, Address: 0x1e0508, Func Offset: 0x8
	// Line 1810, Address: 0x1e0540, Func Offset: 0x40
	// Line 1811, Address: 0x1e054c, Func Offset: 0x4c
	// Line 1812, Address: 0x1e0550, Func Offset: 0x50
	// Line 1813, Address: 0x1e0554, Func Offset: 0x54
	// Line 1822, Address: 0x1e0558, Func Offset: 0x58
	// Line 1827, Address: 0x1e0560, Func Offset: 0x60
	// Line 1822, Address: 0x1e0570, Func Offset: 0x70
	// Line 1827, Address: 0x1e0574, Func Offset: 0x74
	// Line 1828, Address: 0x1e05b0, Func Offset: 0xb0
	// Line 1829, Address: 0x1e05b8, Func Offset: 0xb8
	// Line 1831, Address: 0x1e05d8, Func Offset: 0xd8
	// Line 1836, Address: 0x1e05e0, Func Offset: 0xe0
	// Line 1837, Address: 0x1e05e4, Func Offset: 0xe4
	// Line 1836, Address: 0x1e05e8, Func Offset: 0xe8
	// Line 1831, Address: 0x1e05f0, Func Offset: 0xf0
	// Line 1832, Address: 0x1e05f4, Func Offset: 0xf4
	// Line 1836, Address: 0x1e05f8, Func Offset: 0xf8
	// Line 1831, Address: 0x1e0600, Func Offset: 0x100
	// Line 1836, Address: 0x1e0604, Func Offset: 0x104
	// Line 1837, Address: 0x1e0608, Func Offset: 0x108
	// Line 1832, Address: 0x1e0610, Func Offset: 0x110
	// Line 1831, Address: 0x1e0614, Func Offset: 0x114
	// Line 1837, Address: 0x1e0618, Func Offset: 0x118
	// Line 1838, Address: 0x1e0624, Func Offset: 0x124
	// Line 1839, Address: 0x1e0638, Func Offset: 0x138
	// Line 1840, Address: 0x1e064c, Func Offset: 0x14c
	// Line 1832, Address: 0x1e0654, Func Offset: 0x154
	// Line 1840, Address: 0x1e0658, Func Offset: 0x158
	// Line 1842, Address: 0x1e0664, Func Offset: 0x164
	// Line 1832, Address: 0x1e0668, Func Offset: 0x168
	// Line 1842, Address: 0x1e0670, Func Offset: 0x170
	// Line 1843, Address: 0x1e0678, Func Offset: 0x178
	// Line 1845, Address: 0x1e068c, Func Offset: 0x18c
	// Line 1846, Address: 0x1e0694, Func Offset: 0x194
	// Line 1850, Address: 0x1e06ac, Func Offset: 0x1ac
	// Line 1851, Address: 0x1e06b8, Func Offset: 0x1b8
	// Line 1852, Address: 0x1e06d4, Func Offset: 0x1d4
	// Line 1851, Address: 0x1e06dc, Func Offset: 0x1dc
	// Line 1855, Address: 0x1e06e0, Func Offset: 0x1e0
	// Line 1851, Address: 0x1e06e4, Func Offset: 0x1e4
	// Line 1852, Address: 0x1e06f4, Func Offset: 0x1f4
	// Line 1855, Address: 0x1e06fc, Func Offset: 0x1fc
	// Line 1851, Address: 0x1e0704, Func Offset: 0x204
	// Line 1852, Address: 0x1e0714, Func Offset: 0x214
	// Line 1853, Address: 0x1e0718, Func Offset: 0x218
	// Line 1854, Address: 0x1e072c, Func Offset: 0x22c
	// Line 1855, Address: 0x1e0740, Func Offset: 0x240
	// Line 1856, Address: 0x1e0758, Func Offset: 0x258
	// Line 1857, Address: 0x1e0764, Func Offset: 0x264
	// Line 1860, Address: 0x1e0788, Func Offset: 0x288
	// Line 1861, Address: 0x1e078c, Func Offset: 0x28c
	// Line 1862, Address: 0x1e0790, Func Offset: 0x290
	// Line 1857, Address: 0x1e0794, Func Offset: 0x294
	// Line 1858, Address: 0x1e079c, Func Offset: 0x29c
	// Line 1865, Address: 0x1e07a0, Func Offset: 0x2a0
	// Line 1858, Address: 0x1e07a4, Func Offset: 0x2a4
	// Line 1859, Address: 0x1e07a8, Func Offset: 0x2a8
	// Line 1860, Address: 0x1e07ac, Func Offset: 0x2ac
	// Line 1861, Address: 0x1e07b0, Func Offset: 0x2b0
	// Line 1865, Address: 0x1e07b4, Func Offset: 0x2b4
	// Line 1866, Address: 0x1e07bc, Func Offset: 0x2bc
	// Line 1867, Address: 0x1e0810, Func Offset: 0x310
	// Line 1868, Address: 0x1e085c, Func Offset: 0x35c
	// Line 1870, Address: 0x1e086c, Func Offset: 0x36c
	// Line 1871, Address: 0x1e087c, Func Offset: 0x37c
	// Line 1870, Address: 0x1e0880, Func Offset: 0x380
	// Line 1871, Address: 0x1e088c, Func Offset: 0x38c
	// Line 1870, Address: 0x1e0890, Func Offset: 0x390
	// Line 1871, Address: 0x1e0894, Func Offset: 0x394
	// Line 1872, Address: 0x1e08a0, Func Offset: 0x3a0
	// Line 1873, Address: 0x1e08b4, Func Offset: 0x3b4
	// Line 1876, Address: 0x1e08c8, Func Offset: 0x3c8
	// Line 1877, Address: 0x1e08cc, Func Offset: 0x3cc
	// Line 1878, Address: 0x1e08d0, Func Offset: 0x3d0
	// Line 1879, Address: 0x1e08e0, Func Offset: 0x3e0
	// Func End, Address: 0x1e0920, Func Offset: 0x420
}

// 
// Start address: 0x1e0920
void bhEne14_SetMotion(BH_PWORK* epw)
{
	int obj_list_f[4];
	int obj_list[4];
	int i;
	npobj* objP;
	_anon12* mkaP;
	// Line 1893, Address: 0x1e0920, Func Offset: 0
	// Line 1889, Address: 0x1e092c, Func Offset: 0xc
	// Line 1893, Address: 0x1e0930, Func Offset: 0x10
	// Line 1899, Address: 0x1e0934, Func Offset: 0x14
	// Line 1893, Address: 0x1e0940, Func Offset: 0x20
	// Line 1899, Address: 0x1e0944, Func Offset: 0x24
	// Line 1908, Address: 0x1e094c, Func Offset: 0x2c
	// Line 1909, Address: 0x1e095c, Func Offset: 0x3c
	// Line 1911, Address: 0x1e0960, Func Offset: 0x40
	// Line 1910, Address: 0x1e0964, Func Offset: 0x44
	// Line 1912, Address: 0x1e0968, Func Offset: 0x48
	// Line 1913, Address: 0x1e096c, Func Offset: 0x4c
	// Line 1912, Address: 0x1e0970, Func Offset: 0x50
	// Line 1911, Address: 0x1e0978, Func Offset: 0x58
	// Line 1910, Address: 0x1e0980, Func Offset: 0x60
	// Line 1911, Address: 0x1e0984, Func Offset: 0x64
	// Line 1918, Address: 0x1e0990, Func Offset: 0x70
	// Line 1911, Address: 0x1e0994, Func Offset: 0x74
	// Line 1912, Address: 0x1e0998, Func Offset: 0x78
	// Line 1913, Address: 0x1e099c, Func Offset: 0x7c
	// Line 1912, Address: 0x1e09a0, Func Offset: 0x80
	// Line 1917, Address: 0x1e09b4, Func Offset: 0x94
	// Line 1913, Address: 0x1e09bc, Func Offset: 0x9c
	// Line 1912, Address: 0x1e09c8, Func Offset: 0xa8
	// Line 1913, Address: 0x1e09d0, Func Offset: 0xb0
	// Line 1915, Address: 0x1e09d4, Func Offset: 0xb4
	// Line 1918, Address: 0x1e09d8, Func Offset: 0xb8
	// Line 1915, Address: 0x1e09dc, Func Offset: 0xbc
	// Line 1916, Address: 0x1e09e0, Func Offset: 0xc0
	// Line 1917, Address: 0x1e09ec, Func Offset: 0xcc
	// Line 1918, Address: 0x1e09f4, Func Offset: 0xd4
	// Line 1919, Address: 0x1e09fc, Func Offset: 0xdc
	// Line 1920, Address: 0x1e0a04, Func Offset: 0xe4
	// Line 1922, Address: 0x1e0a08, Func Offset: 0xe8
	// Line 1921, Address: 0x1e0a0c, Func Offset: 0xec
	// Line 1924, Address: 0x1e0a10, Func Offset: 0xf0
	// Line 1923, Address: 0x1e0a14, Func Offset: 0xf4
	// Line 1929, Address: 0x1e0a1c, Func Offset: 0xfc
	// Line 1922, Address: 0x1e0a20, Func Offset: 0x100
	// Line 1921, Address: 0x1e0a28, Func Offset: 0x108
	// Line 1922, Address: 0x1e0a2c, Func Offset: 0x10c
	// Line 1923, Address: 0x1e0a38, Func Offset: 0x118
	// Line 1922, Address: 0x1e0a3c, Func Offset: 0x11c
	// Line 1924, Address: 0x1e0a40, Func Offset: 0x120
	// Line 1923, Address: 0x1e0a44, Func Offset: 0x124
	// Line 1928, Address: 0x1e0a58, Func Offset: 0x138
	// Line 1924, Address: 0x1e0a5c, Func Offset: 0x13c
	// Line 1923, Address: 0x1e0a68, Func Offset: 0x148
	// Line 1924, Address: 0x1e0a70, Func Offset: 0x150
	// Line 1926, Address: 0x1e0a74, Func Offset: 0x154
	// Line 1929, Address: 0x1e0a78, Func Offset: 0x158
	// Line 1926, Address: 0x1e0a7c, Func Offset: 0x15c
	// Line 1927, Address: 0x1e0a80, Func Offset: 0x160
	// Line 1928, Address: 0x1e0a88, Func Offset: 0x168
	// Line 1929, Address: 0x1e0a8c, Func Offset: 0x16c
	// Line 1930, Address: 0x1e0a94, Func Offset: 0x174
	// Line 1931, Address: 0x1e0a98, Func Offset: 0x178
	// Func End, Address: 0x1e0aa4, Func Offset: 0x184
}

// 
// Start address: 0x1e0ab0
void bhEne14_CheckWall(BH_PWORK* epw)
{
	// Line 1941, Address: 0x1e0ab0, Func Offset: 0
	// Line 1946, Address: 0x1e0abc, Func Offset: 0xc
	// Line 1948, Address: 0x1e0ac4, Func Offset: 0x14
	// Line 1953, Address: 0x1e0ad0, Func Offset: 0x20
	// Line 1948, Address: 0x1e0ad4, Func Offset: 0x24
	// Line 1953, Address: 0x1e0ad8, Func Offset: 0x28
	// Line 1954, Address: 0x1e0ae0, Func Offset: 0x30
	// Line 1961, Address: 0x1e0aec, Func Offset: 0x3c
	// Line 1954, Address: 0x1e0af0, Func Offset: 0x40
	// Line 1956, Address: 0x1e0af8, Func Offset: 0x48
	// Line 1961, Address: 0x1e0afc, Func Offset: 0x4c
	// Line 1962, Address: 0x1e0b04, Func Offset: 0x54
	// Line 1965, Address: 0x1e0b1c, Func Offset: 0x6c
	// Func End, Address: 0x1e0b2c, Func Offset: 0x7c
}

// 
// Start address: 0x1e0b30
void bhEne14_PlayerControl(BH_PWORK* epw)
{
	// Line 1975, Address: 0x1e0b30, Func Offset: 0
	// Line 1979, Address: 0x1e0b38, Func Offset: 0x8
	// Line 1981, Address: 0x1e0b60, Func Offset: 0x30
	// Line 1984, Address: 0x1e0b80, Func Offset: 0x50
	// Line 1986, Address: 0x1e0bac, Func Offset: 0x7c
	// Line 1987, Address: 0x1e0bb8, Func Offset: 0x88
	// Line 1986, Address: 0x1e0bc0, Func Offset: 0x90
	// Line 1987, Address: 0x1e0bc8, Func Offset: 0x98
	// Line 1988, Address: 0x1e0bd0, Func Offset: 0xa0
	// Line 1987, Address: 0x1e0bd4, Func Offset: 0xa4
	// Line 1988, Address: 0x1e0bdc, Func Offset: 0xac
	// Line 1991, Address: 0x1e0be4, Func Offset: 0xb4
	// Line 1988, Address: 0x1e0be8, Func Offset: 0xb8
	// Line 1991, Address: 0x1e0bf0, Func Offset: 0xc0
	// Line 1992, Address: 0x1e0c00, Func Offset: 0xd0
	// Line 1993, Address: 0x1e0c04, Func Offset: 0xd4
	// Line 1994, Address: 0x1e0c0c, Func Offset: 0xdc
	// Line 1996, Address: 0x1e0c14, Func Offset: 0xe4
	// Line 1997, Address: 0x1e0c1c, Func Offset: 0xec
	// Line 1998, Address: 0x1e0c20, Func Offset: 0xf0
	// Line 1999, Address: 0x1e0c24, Func Offset: 0xf4
	// Line 2003, Address: 0x1e0c28, Func Offset: 0xf8
	// Line 1996, Address: 0x1e0c2c, Func Offset: 0xfc
	// Line 1997, Address: 0x1e0c30, Func Offset: 0x100
	// Line 1998, Address: 0x1e0c3c, Func Offset: 0x10c
	// Line 1999, Address: 0x1e0c48, Func Offset: 0x118
	// Line 2000, Address: 0x1e0c54, Func Offset: 0x124
	// Line 2003, Address: 0x1e0c64, Func Offset: 0x134
	// Line 2005, Address: 0x1e0c6c, Func Offset: 0x13c
	// Line 2006, Address: 0x1e0c78, Func Offset: 0x148
	// Line 2008, Address: 0x1e0c80, Func Offset: 0x150
	// Line 2009, Address: 0x1e0c8c, Func Offset: 0x15c
	// Line 2010, Address: 0x1e0c90, Func Offset: 0x160
	// Line 2009, Address: 0x1e0c94, Func Offset: 0x164
	// Line 2010, Address: 0x1e0c98, Func Offset: 0x168
	// Line 2011, Address: 0x1e0ca8, Func Offset: 0x178
	// Line 2012, Address: 0x1e0cac, Func Offset: 0x17c
	// Line 2013, Address: 0x1e0cb4, Func Offset: 0x184
	// Line 2015, Address: 0x1e0cbc, Func Offset: 0x18c
	// Line 2016, Address: 0x1e0cc4, Func Offset: 0x194
	// Line 2017, Address: 0x1e0cc8, Func Offset: 0x198
	// Line 2018, Address: 0x1e0ccc, Func Offset: 0x19c
	// Line 2015, Address: 0x1e0cd0, Func Offset: 0x1a0
	// Line 2016, Address: 0x1e0cd4, Func Offset: 0x1a4
	// Line 2017, Address: 0x1e0ce0, Func Offset: 0x1b0
	// Line 2018, Address: 0x1e0cec, Func Offset: 0x1bc
	// Line 2019, Address: 0x1e0cf8, Func Offset: 0x1c8
	// Line 2021, Address: 0x1e0d08, Func Offset: 0x1d8
	// Line 2023, Address: 0x1e0d10, Func Offset: 0x1e0
	// Line 2025, Address: 0x1e0d1c, Func Offset: 0x1ec
	// Line 2026, Address: 0x1e0d20, Func Offset: 0x1f0
	// Line 2027, Address: 0x1e0d2c, Func Offset: 0x1fc
	// Line 2025, Address: 0x1e0d30, Func Offset: 0x200
	// Line 2026, Address: 0x1e0d34, Func Offset: 0x204
	// Line 2030, Address: 0x1e0d38, Func Offset: 0x208
	// Line 2031, Address: 0x1e0d3c, Func Offset: 0x20c
	// Line 2026, Address: 0x1e0d40, Func Offset: 0x210
	// Line 2027, Address: 0x1e0d44, Func Offset: 0x214
	// Line 2026, Address: 0x1e0d48, Func Offset: 0x218
	// Line 2027, Address: 0x1e0d50, Func Offset: 0x220
	// Line 2028, Address: 0x1e0d58, Func Offset: 0x228
	// Line 2027, Address: 0x1e0d5c, Func Offset: 0x22c
	// Line 2028, Address: 0x1e0d64, Func Offset: 0x234
	// Line 2029, Address: 0x1e0d6c, Func Offset: 0x23c
	// Line 2028, Address: 0x1e0d70, Func Offset: 0x240
	// Line 2029, Address: 0x1e0d78, Func Offset: 0x248
	// Line 2030, Address: 0x1e0d80, Func Offset: 0x250
	// Line 2031, Address: 0x1e0d8c, Func Offset: 0x25c
	// Line 2030, Address: 0x1e0d90, Func Offset: 0x260
	// Line 2031, Address: 0x1e0d98, Func Offset: 0x268
	// Line 2037, Address: 0x1e0da0, Func Offset: 0x270
	// Func End, Address: 0x1e0dac, Func Offset: 0x27c
}

// 
// Start address: 0x1e0db0
void bhEne14_CallSE(BH_PWORK* epw)
{
	// Line 2047, Address: 0x1e0db0, Func Offset: 0
	// Line 2048, Address: 0x1e0db8, Func Offset: 0x8
	// Line 2050, Address: 0x1e0dc8, Func Offset: 0x18
	// Line 2052, Address: 0x1e0e10, Func Offset: 0x60
	// Line 2053, Address: 0x1e0e1c, Func Offset: 0x6c
	// Line 2055, Address: 0x1e0e2c, Func Offset: 0x7c
	// Line 2058, Address: 0x1e0e34, Func Offset: 0x84
	// Line 2059, Address: 0x1e0e44, Func Offset: 0x94
	// Line 2061, Address: 0x1e0e54, Func Offset: 0xa4
	// Line 2063, Address: 0x1e0e5c, Func Offset: 0xac
	// Line 2064, Address: 0x1e0e68, Func Offset: 0xb8
	// Line 2066, Address: 0x1e0e74, Func Offset: 0xc4
	// Line 2073, Address: 0x1e0e7c, Func Offset: 0xcc
	// Line 2074, Address: 0x1e0e88, Func Offset: 0xd8
	// Line 2078, Address: 0x1e0e98, Func Offset: 0xe8
	// Func End, Address: 0x1e0ea4, Func Offset: 0xf4
}

