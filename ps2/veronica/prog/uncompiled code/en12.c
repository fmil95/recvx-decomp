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

typedef void(*type_21)(BH_PWORK*);
typedef void(*type_33)(BH_PWORK*);
typedef void(*type_80)(BH_PWORK*);
typedef void(*type_84)(BH_PWORK*);
typedef void(*type_89)(BH_PWORK*);
typedef void(*type_91)(void*);
typedef void(*type_116)(BH_PWORK*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef float type_2[16][0];
typedef _anon0* type_3[32];
typedef _anon2* type_4[16];
typedef _anon0* type_5[32];
typedef _anon0* type_6[512];
typedef _anon2* type_7[16][16];
typedef _anon2* type_8[16][16][100];
typedef char type_9[8];
typedef _anon0* type_10[32];
typedef _anon0* type_11[512];
typedef _anon2* type_12[1300];
typedef char type_13[32];
typedef _anon0* type_14[512];
typedef _anon2* type_15[200];
typedef _anon25 type_16[57];
typedef short type_17[32];
typedef _anon15 type_18[1];
typedef _anon0* type_19[128];
typedef unsigned int type_20[1];
typedef _anon5 type_22[256];
typedef _anon2* type_23[8];
typedef void(*type_24)(BH_PWORK*)[8];
typedef int* type_25[16];
typedef _anon0* type_26[128];
typedef char type_27[8];
typedef npobj* type_28[16];
typedef char type_29[8][3];
typedef _anon0* type_30[128];
typedef int type_31[4];
typedef _anon2* type_32[16];
typedef unsigned int type_34[4];
typedef void(*type_35)(BH_PWORK*)[1];
typedef _anon8 type_36[16];
typedef _anon0* type_37[512];
typedef _anon24 type_38[17];
typedef char type_39[256];
typedef float type_40[4];
typedef float type_41[4];
typedef float type_42[4];
typedef _anon4* type_43[128];
typedef unsigned char type_44[64];
typedef float type_45[16];
typedef unsigned short type_46[3];
typedef char type_47[8];
typedef void* type_48[2];
typedef _anon39 type_49[33];
typedef _anon16 type_50[25];
typedef _anon2* type_51[256];
typedef int type_52[4];
typedef unsigned char* type_53[256];
typedef unsigned char type_54[22];
typedef unsigned int type_55[2];
typedef short type_56[256];
typedef _anon21 type_57[4];
typedef float type_58[3];
typedef short type_59[256];
typedef int type_60[3];
typedef int type_61[8];
typedef float type_62[3];
typedef _anon2* type_63[256];
typedef _anon25 type_64[150];
typedef _anon7 type_65[256];
typedef _anon15 type_66[450];
typedef char type_67[3];
typedef _anon23 type_68[16];
typedef char type_69[3];
typedef short type_70[256];
typedef _anon26 type_71[6];
typedef char type_72[3];
typedef int type_73[64];
typedef _anon8 type_74[450];
typedef int type_75[4];
typedef _anon27 type_76[21];
typedef _anon30 type_77[4];
typedef _anon3 type_78[4];
typedef int type_79[450];
typedef void(*type_81)(BH_PWORK*)[1];
typedef unsigned int type_82[8];
typedef unsigned char type_83[450];
typedef void(*type_85)(BH_PWORK*)[2];
typedef char type_86[16];
typedef _anon25 type_87[30];
typedef char type_88[4];
typedef void(*type_90)(BH_PWORK*)[1];
typedef unsigned int type_92[32];
typedef unsigned int type_93[16];
typedef _anon13 type_94[64];
typedef unsigned int type_95[16];
typedef _anon13 type_96[64];
typedef char type_97[8];
typedef unsigned int type_98[32];
typedef _anon33 type_99[22];
typedef _anon13 type_100[64];
typedef unsigned int type_101[16];
typedef unsigned int type_102[3];
typedef _anon25 type_103[2];
typedef BH_PWORK* type_104[16];
typedef _anon24 type_105[49];
typedef unsigned int type_106[8];
typedef unsigned int type_107[1];
typedef unsigned int type_108[384];
typedef unsigned int type_109[2];
typedef int type_110[3];
typedef unsigned char type_111[2];
typedef unsigned int type_112[4];
typedef int* type_113[16];
typedef char type_114[32];
typedef npobj* type_115[16];
typedef char type_117[64];
typedef void(*type_118)(BH_PWORK*)[6];
typedef int type_119[16];
typedef _anon2* type_120[16];
typedef int type_121[16][2];
typedef char type_122[4];
typedef _anon8 type_123[16];
typedef short type_124[4];
typedef unsigned char type_125[4];
typedef _anon28 type_126[16];
typedef unsigned int type_127[32];
typedef _anon25 type_128[32];
typedef int type_129[4];
typedef _anon0* type_130[512];
typedef _anon36 type_131[21];
typedef _anon0* type_132[128];
typedef _anon0* type_133[512];
typedef unsigned char type_134[64];
typedef _anon0 type_135[0];
typedef _anon0* type_136[512];

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
	_anon2* txp[16];
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
	_anon37 cspr;
	int pn;
	_anon30* pvp;
	_anon3* tvp;
	_anon30 pv[4];
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
	_anon38 watr;
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

struct _anon1
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon2
{
	_anon15* textures;
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
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon14* md2P;
	unsigned short* atrP;
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
	_anon2* texP;
	_anon1* owP;
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
	_anon34* info;
};

struct _anon10
{
	unsigned short key[3];
};

struct _anon11
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

struct _anon12
{
	void* texaddr;
	_anon6 texsurface;
};

struct _anon13
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
	_anon25 ply_pos;
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
	_anon4* emtp[128];
	_anon4* rmthp;
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
	_anon7 txbp[256];
	unsigned char* ef_psp;
	_anon15 ef_tex[450];
	_anon2 ef_tlist;
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
	_anon12 ren_info;
	_anon15 ren_tex[1];
	_anon2 ren_tlist;
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
	_anon32 mr_pl;
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
	_anon13* pl_htp;
	int costume;
	_anon25 hd_pos;
	_anon25 apos;
	_anon13* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon13 mwalp[64];
	_anon13 metcp[64];
	_anon13 mflrp[64];
	int dla_n;
	_anon13* htp;
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
	_anon11 door;
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
	_anon25 ufo_pos;
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
	_anon28 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon25 ghtp[32];
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
	_anon25 pnt;
	_anon25 vctr;
	int stat;
	int reserve;
	_anon29 ltcal;
	_anon35 attr;
};

struct _anon21
{
	_anon25 ps;
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
	_anon25 center;
	float r;
};

struct _anon23
{
	float x;
	float y;
};

struct _anon24
{
	int jno;
	_anon25 ofp;
	float size;
	int life;
	int delay;
};

struct _anon25
{
	float x;
	float y;
	float z;
};

struct _anon26
{
	int key;
	float cnt;
};

struct _anon27
{
	char type[3];
	char bloodstain[3];
	char exef;
};

struct _anon28
{
	_anon25 c1;
	_anon25 c2;
	float r1;
	float r2;
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
	_anon25 lpnt;
	_anon25 lvctr;
	_anon25 lmvctr;
	_anon19 atten;
	_anon19 amb;
	_anon19 dif;
	_anon19 spc;
	_anon19 mamb;
	_anon19 mdif;
	_anon19 mspc;
};

struct _anon30
{
	float x;
	float y;
	float z;
	unsigned int col;
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
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon33
{
	int flg;
	_anon25 ofp;
	float rx;
	float ry;
	float rz;
};

struct _anon34
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

struct _anon35
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

struct _anon36
{
	int crit;
	int pt[3];
	int timeout;
	int bonus;
};

struct _anon37
{
	_anon25 c;
	float r;
};

struct _anon38
{
	_anon25 c1;
	_anon25 c2;
	float r;
};

struct _anon39
{
	int flg;
	int correct;
};

_anon25 vm1_012[30];
_anon25 vm1_013[57];
_anon25 vm1_014[150];
unsigned char flip_tree[22];
char SdwTab[8];
char joint_tree[8][3];
_anon27 DmgReact[21];
_anon36 CombWepTbl[21];
_anon39 CombJointTbl[33];
_anon33 BloodTbl[22];
_anon16 CapColTab[25];
_anon24 pc_eff_tab[49];
_anon24 alex_eff_tab[17];
_anon26 ShapeTbl_Acid[6];
void(*bhEne12_Mode0)(BH_PWORK*)[6];
void(*bhEne12_BrainType)(BH_PWORK*)[2];
void(*bhEne12_MoveMode2)(BH_PWORK*)[8];
void(*bhEne12_NageMode2)(BH_PWORK*)[1];
void(*bhEne12_DamageMode2)(BH_PWORK*)[1];
void(*bhEne12_DieMode2)(BH_PWORK*)[1];
_anon18* sys;
_anon0 eff[0];
BH_PWORK* plp;
float lcmat[16][0];

void bhEne12(BH_PWORK* epw);
void bhEne12_Init(BH_PWORK* epw);
void bhEne12_Brain(BH_PWORK* epw);
void bhEne12_BR00(BH_PWORK* epw);
void bhEne12_Move(BH_PWORK* epw);
void bhEne12_MV00(BH_PWORK* epw);
void bhEne12_MV01(BH_PWORK* epw);
void bhEne12_MV02(BH_PWORK* epw);
void bhEne12_MV03(BH_PWORK* epw);
void bhEne12_MV04(BH_PWORK* epw);
void bhEne12_MV05();
void bhEne12_MV06(BH_PWORK* epw);
void bhEne12_MV07(BH_PWORK* epw);
void bhEne12_Nage(BH_PWORK* epw);
void bhEne12_NG00(BH_PWORK* epw);
void bhEne12_Damage(BH_PWORK* epw);
void bhEne12_DG00(BH_PWORK* epw);
void bhEne12_Die(BH_PWORK* epw);
void bhEne12_DD00(BH_PWORK* epw);
void bhEne12_InitDamage(BH_PWORK* epw);
void bhEne12_LookPlayaer(BH_PWORK* epw);
void bhEne12_HitMark(BH_PWORK* epw);
void bhEne12_FixedLegPos(BH_PWORK* epw);
void bhEne12_PlayerControl(BH_PWORK* epw);
void bhEne12_FlameLiquid(BH_PWORK* epw, _anon25* pos, int time);
void bhEne12_Acid(BH_PWORK* epw);
void bhEne12_CheckWall(BH_PWORK* epw);
void bhEne12_Blood(BH_PWORK* epw, int num);
int bhEne12_AvoidWall(BH_PWORK* epw);
void bhEne12_CallSE(BH_PWORK* epw);
void bhEne12_CallFootSE(BH_PWORK* epw, int flg);
void bhEne12_SetFireBintaEffect(BH_PWORK* epw, int act);

// 
// Start address: 0x1d5690
void bhEne12(BH_PWORK* epw)
{
	// Line 507, Address: 0x1d5690, Func Offset: 0
	// Line 509, Address: 0x1d569c, Func Offset: 0xc
	// Line 510, Address: 0x1d56ac, Func Offset: 0x1c
	// Line 512, Address: 0x1d56b4, Func Offset: 0x24
	// Line 510, Address: 0x1d56b8, Func Offset: 0x28
	// Line 511, Address: 0x1d56c0, Func Offset: 0x30
	// Line 512, Address: 0x1d56cc, Func Offset: 0x3c
	// Line 516, Address: 0x1d56d8, Func Offset: 0x48
	// Line 517, Address: 0x1d56e8, Func Offset: 0x58
	// Line 518, Address: 0x1d56f8, Func Offset: 0x68
	// Line 519, Address: 0x1d5704, Func Offset: 0x74
	// Line 520, Address: 0x1d570c, Func Offset: 0x7c
	// Line 522, Address: 0x1d5714, Func Offset: 0x84
	// Line 521, Address: 0x1d5718, Func Offset: 0x88
	// Line 522, Address: 0x1d571c, Func Offset: 0x8c
	// Line 523, Address: 0x1d5720, Func Offset: 0x90
	// Line 526, Address: 0x1d5724, Func Offset: 0x94
	// Line 531, Address: 0x1d5728, Func Offset: 0x98
	// Line 534, Address: 0x1d5748, Func Offset: 0xb8
	// Line 537, Address: 0x1d5750, Func Offset: 0xc0
	// Line 540, Address: 0x1d5764, Func Offset: 0xd4
	// Line 543, Address: 0x1d576c, Func Offset: 0xdc
	// Line 545, Address: 0x1d5784, Func Offset: 0xf4
	// Line 546, Address: 0x1d578c, Func Offset: 0xfc
	// Line 547, Address: 0x1d579c, Func Offset: 0x10c
	// Line 550, Address: 0x1d57a4, Func Offset: 0x114
	// Line 553, Address: 0x1d57b0, Func Offset: 0x120
	// Line 556, Address: 0x1d57bc, Func Offset: 0x12c
	// Line 559, Address: 0x1d57c4, Func Offset: 0x134
	// Line 560, Address: 0x1d57cc, Func Offset: 0x13c
	// Func End, Address: 0x1d57dc, Func Offset: 0x14c
}

// 
// Start address: 0x1d57e0
void bhEne12_Init(BH_PWORK* epw)
{
	int eno;
	// Line 570, Address: 0x1d57e0, Func Offset: 0
	// Line 572, Address: 0x1d57ec, Func Offset: 0xc
	// Line 573, Address: 0x1d57f0, Func Offset: 0x10
	// Line 574, Address: 0x1d57f4, Func Offset: 0x14
	// Line 575, Address: 0x1d57f8, Func Offset: 0x18
	// Line 576, Address: 0x1d57fc, Func Offset: 0x1c
	// Line 572, Address: 0x1d5800, Func Offset: 0x20
	// Line 573, Address: 0x1d5808, Func Offset: 0x28
	// Line 577, Address: 0x1d580c, Func Offset: 0x2c
	// Line 580, Address: 0x1d5810, Func Offset: 0x30
	// Line 587, Address: 0x1d5814, Func Offset: 0x34
	// Line 573, Address: 0x1d5818, Func Offset: 0x38
	// Line 574, Address: 0x1d5820, Func Offset: 0x40
	// Line 575, Address: 0x1d5824, Func Offset: 0x44
	// Line 576, Address: 0x1d5828, Func Offset: 0x48
	// Line 577, Address: 0x1d582c, Func Offset: 0x4c
	// Line 580, Address: 0x1d5830, Func Offset: 0x50
	// Line 581, Address: 0x1d5834, Func Offset: 0x54
	// Line 582, Address: 0x1d5838, Func Offset: 0x58
	// Line 583, Address: 0x1d583c, Func Offset: 0x5c
	// Line 586, Address: 0x1d5840, Func Offset: 0x60
	// Line 587, Address: 0x1d5844, Func Offset: 0x64
	// Line 588, Address: 0x1d5848, Func Offset: 0x68
	// Line 589, Address: 0x1d584c, Func Offset: 0x6c
	// Line 590, Address: 0x1d5850, Func Offset: 0x70
	// Line 591, Address: 0x1d5858, Func Offset: 0x78
	// Line 595, Address: 0x1d5864, Func Offset: 0x84
	// Line 592, Address: 0x1d5868, Func Offset: 0x88
	// Line 595, Address: 0x1d586c, Func Offset: 0x8c
	// Line 597, Address: 0x1d5870, Func Offset: 0x90
	// Line 596, Address: 0x1d5874, Func Offset: 0x94
	// Line 597, Address: 0x1d5878, Func Offset: 0x98
	// Line 598, Address: 0x1d587c, Func Offset: 0x9c
	// Line 599, Address: 0x1d5884, Func Offset: 0xa4
	// Line 600, Address: 0x1d588c, Func Offset: 0xac
	// Line 601, Address: 0x1d5890, Func Offset: 0xb0
	// Line 602, Address: 0x1d5898, Func Offset: 0xb8
	// Line 603, Address: 0x1d58a0, Func Offset: 0xc0
	// Line 605, Address: 0x1d58b0, Func Offset: 0xd0
	// Line 609, Address: 0x1d58bc, Func Offset: 0xdc
	// Line 612, Address: 0x1d58cc, Func Offset: 0xec
	// Line 613, Address: 0x1d58d8, Func Offset: 0xf8
	// Line 614, Address: 0x1d58dc, Func Offset: 0xfc
	// Line 612, Address: 0x1d58e0, Func Offset: 0x100
	// Line 613, Address: 0x1d58ec, Func Offset: 0x10c
	// Line 614, Address: 0x1d58f4, Func Offset: 0x114
	// Line 613, Address: 0x1d58fc, Func Offset: 0x11c
	// Line 614, Address: 0x1d5908, Func Offset: 0x128
	// Line 616, Address: 0x1d5920, Func Offset: 0x140
	// Line 620, Address: 0x1d5948, Func Offset: 0x168
	// Line 621, Address: 0x1d5950, Func Offset: 0x170
	// Line 624, Address: 0x1d5954, Func Offset: 0x174
	// Line 620, Address: 0x1d5958, Func Offset: 0x178
	// Line 621, Address: 0x1d595c, Func Offset: 0x17c
	// Line 622, Address: 0x1d5964, Func Offset: 0x184
	// Line 623, Address: 0x1d596c, Func Offset: 0x18c
	// Line 624, Address: 0x1d5974, Func Offset: 0x194
	// Line 627, Address: 0x1d597c, Func Offset: 0x19c
	// Line 628, Address: 0x1d598c, Func Offset: 0x1ac
	// Line 629, Address: 0x1d59b4, Func Offset: 0x1d4
	// Line 631, Address: 0x1d59c0, Func Offset: 0x1e0
	// Line 637, Address: 0x1d59c8, Func Offset: 0x1e8
	// Line 634, Address: 0x1d59cc, Func Offset: 0x1ec
	// Line 631, Address: 0x1d59d0, Func Offset: 0x1f0
	// Line 637, Address: 0x1d59d8, Func Offset: 0x1f8
	// Line 634, Address: 0x1d59dc, Func Offset: 0x1fc
	// Line 637, Address: 0x1d59e0, Func Offset: 0x200
	// Line 640, Address: 0x1d59e4, Func Offset: 0x204
	// Line 641, Address: 0x1d59f0, Func Offset: 0x210
	// Line 644, Address: 0x1d59f4, Func Offset: 0x214
	// Line 640, Address: 0x1d59f8, Func Offset: 0x218
	// Line 641, Address: 0x1d5a00, Func Offset: 0x220
	// Line 644, Address: 0x1d5a04, Func Offset: 0x224
	// Line 641, Address: 0x1d5a08, Func Offset: 0x228
	// Line 644, Address: 0x1d5a0c, Func Offset: 0x22c
	// Line 645, Address: 0x1d5a1c, Func Offset: 0x23c
	// Func End, Address: 0x1d5a2c, Func Offset: 0x24c
}

// 
// Start address: 0x1d5a30
void bhEne12_Brain(BH_PWORK* epw)
{
	// Line 656, Address: 0x1d5a30, Func Offset: 0
	// Func End, Address: 0x1d5a50, Func Offset: 0x20
}

// 
// Start address: 0x1d5a50
void bhEne12_BR00(BH_PWORK* epw)
{
	_anon25 pos;
	int act_no;
	int i;
	int inter[4];
	int act[16][2];
	int mode[4];
	float dist;
	// Line 667, Address: 0x1d5a50, Func Offset: 0
	// Line 669, Address: 0x1d5a5c, Func Offset: 0xc
	// Line 667, Address: 0x1d5a64, Func Offset: 0x14
	// Line 669, Address: 0x1d5a68, Func Offset: 0x18
	// Line 675, Address: 0x1d5a74, Func Offset: 0x24
	// Line 669, Address: 0x1d5a7c, Func Offset: 0x2c
	// Line 675, Address: 0x1d5a80, Func Offset: 0x30
	// Line 680, Address: 0x1d5aa8, Func Offset: 0x58
	// Line 684, Address: 0x1d5ab8, Func Offset: 0x68
	// Line 680, Address: 0x1d5ac0, Func Offset: 0x70
	// Line 684, Address: 0x1d5ac4, Func Offset: 0x74
	// Line 687, Address: 0x1d5ad4, Func Offset: 0x84
	// Line 688, Address: 0x1d5adc, Func Offset: 0x8c
	// Line 689, Address: 0x1d5b00, Func Offset: 0xb0
	// Line 691, Address: 0x1d5b10, Func Offset: 0xc0
	// Line 692, Address: 0x1d5b2c, Func Offset: 0xdc
	// Line 696, Address: 0x1d5b3c, Func Offset: 0xec
	// Line 697, Address: 0x1d5b88, Func Offset: 0x138
	// Line 698, Address: 0x1d5b90, Func Offset: 0x140
	// Line 699, Address: 0x1d5b94, Func Offset: 0x144
	// Line 700, Address: 0x1d5b98, Func Offset: 0x148
	// Line 703, Address: 0x1d5b9c, Func Offset: 0x14c
	// Line 704, Address: 0x1d5bb0, Func Offset: 0x160
	// Line 703, Address: 0x1d5bb4, Func Offset: 0x164
	// Line 704, Address: 0x1d5bbc, Func Offset: 0x16c
	// Line 706, Address: 0x1d5bc8, Func Offset: 0x178
	// Line 711, Address: 0x1d5bd0, Func Offset: 0x180
	// Line 714, Address: 0x1d5bf0, Func Offset: 0x1a0
	// Line 718, Address: 0x1d5c00, Func Offset: 0x1b0
	// Line 719, Address: 0x1d5c14, Func Offset: 0x1c4
	// Line 721, Address: 0x1d5c1c, Func Offset: 0x1cc
	// Line 720, Address: 0x1d5c20, Func Offset: 0x1d0
	// Line 721, Address: 0x1d5c24, Func Offset: 0x1d4
	// Line 723, Address: 0x1d5c28, Func Offset: 0x1d8
	// Line 727, Address: 0x1d5c30, Func Offset: 0x1e0
	// Line 728, Address: 0x1d5c50, Func Offset: 0x200
	// Line 730, Address: 0x1d5c68, Func Offset: 0x218
	// Line 728, Address: 0x1d5c74, Func Offset: 0x224
	// Line 730, Address: 0x1d5c78, Func Offset: 0x228
	// Line 728, Address: 0x1d5c7c, Func Offset: 0x22c
	// Line 729, Address: 0x1d5c80, Func Offset: 0x230
	// Line 730, Address: 0x1d5c84, Func Offset: 0x234
	// Line 734, Address: 0x1d5c9c, Func Offset: 0x24c
	// Line 736, Address: 0x1d5cac, Func Offset: 0x25c
	// Line 741, Address: 0x1d5cec, Func Offset: 0x29c
	// Line 745, Address: 0x1d5da8, Func Offset: 0x358
	// Line 746, Address: 0x1d5dc4, Func Offset: 0x374
	// Line 749, Address: 0x1d5de0, Func Offset: 0x390
	// Line 750, Address: 0x1d5df4, Func Offset: 0x3a4
	// Line 751, Address: 0x1d5dfc, Func Offset: 0x3ac
	// Line 752, Address: 0x1d5e04, Func Offset: 0x3b4
	// Line 753, Address: 0x1d5e20, Func Offset: 0x3d0
	// Line 754, Address: 0x1d5e24, Func Offset: 0x3d4
	// Line 756, Address: 0x1d5e2c, Func Offset: 0x3dc
	// Line 759, Address: 0x1d5e34, Func Offset: 0x3e4
	// Line 763, Address: 0x1d5e40, Func Offset: 0x3f0
	// Func End, Address: 0x1d5e54, Func Offset: 0x404
}

// 
// Start address: 0x1d5e60
void bhEne12_Move(BH_PWORK* epw)
{
	// Line 773, Address: 0x1d5e60, Func Offset: 0
	// Line 775, Address: 0x1d5e70, Func Offset: 0x10
	// Line 778, Address: 0x1d5e90, Func Offset: 0x30
	// Line 779, Address: 0x1d5ea0, Func Offset: 0x40
	// Line 780, Address: 0x1d5ea8, Func Offset: 0x48
	// Line 784, Address: 0x1d5eb0, Func Offset: 0x50
	// Line 786, Address: 0x1d5ec4, Func Offset: 0x64
	// Func End, Address: 0x1d5ed4, Func Offset: 0x74
}

// 
// Start address: 0x1d5ee0
void bhEne12_MV00(BH_PWORK* epw)
{
	float dist;
	// Line 796, Address: 0x1d5ee0, Func Offset: 0
	// Line 799, Address: 0x1d5ef0, Func Offset: 0x10
	// Line 801, Address: 0x1d5f10, Func Offset: 0x30
	// Line 802, Address: 0x1d5f18, Func Offset: 0x38
	// Line 805, Address: 0x1d5f20, Func Offset: 0x40
	// Line 807, Address: 0x1d5f24, Func Offset: 0x44
	// Line 801, Address: 0x1d5f28, Func Offset: 0x48
	// Line 802, Address: 0x1d5f30, Func Offset: 0x50
	// Line 803, Address: 0x1d5f3c, Func Offset: 0x5c
	// Line 804, Address: 0x1d5f40, Func Offset: 0x60
	// Line 805, Address: 0x1d5f44, Func Offset: 0x64
	// Line 806, Address: 0x1d5f48, Func Offset: 0x68
	// Line 807, Address: 0x1d5f54, Func Offset: 0x74
	// Line 809, Address: 0x1d5f58, Func Offset: 0x78
	// Line 810, Address: 0x1d5f64, Func Offset: 0x84
	// Line 811, Address: 0x1d5f68, Func Offset: 0x88
	// Line 812, Address: 0x1d5f70, Func Offset: 0x90
	// Line 814, Address: 0x1d5f78, Func Offset: 0x98
	// Line 815, Address: 0x1d5fa4, Func Offset: 0xc4
	// Line 816, Address: 0x1d5fe4, Func Offset: 0x104
	// Line 817, Address: 0x1d5fec, Func Offset: 0x10c
	// Line 818, Address: 0x1d5ff0, Func Offset: 0x110
	// Line 819, Address: 0x1d5ff4, Func Offset: 0x114
	// Line 824, Address: 0x1d5ff8, Func Offset: 0x118
	// Func End, Address: 0x1d6008, Func Offset: 0x128
}

// 
// Start address: 0x1d6010
void bhEne12_MV01(BH_PWORK* epw)
{
	float dist;
	// Line 834, Address: 0x1d6010, Func Offset: 0
	// Line 837, Address: 0x1d6020, Func Offset: 0x10
	// Line 839, Address: 0x1d6040, Func Offset: 0x30
	// Line 840, Address: 0x1d6048, Func Offset: 0x38
	// Line 842, Address: 0x1d604c, Func Offset: 0x3c
	// Line 839, Address: 0x1d6050, Func Offset: 0x40
	// Line 840, Address: 0x1d6058, Func Offset: 0x48
	// Line 842, Address: 0x1d6064, Func Offset: 0x54
	// Line 844, Address: 0x1d6070, Func Offset: 0x60
	// Line 845, Address: 0x1d607c, Func Offset: 0x6c
	// Line 846, Address: 0x1d6080, Func Offset: 0x70
	// Line 848, Address: 0x1d6084, Func Offset: 0x74
	// Line 849, Address: 0x1d608c, Func Offset: 0x7c
	// Line 851, Address: 0x1d6098, Func Offset: 0x88
	// Line 853, Address: 0x1d60a0, Func Offset: 0x90
	// Line 851, Address: 0x1d60a4, Func Offset: 0x94
	// Line 852, Address: 0x1d60a8, Func Offset: 0x98
	// Line 851, Address: 0x1d60ac, Func Offset: 0x9c
	// Line 852, Address: 0x1d60b0, Func Offset: 0xa0
	// Line 853, Address: 0x1d60b8, Func Offset: 0xa8
	// Line 855, Address: 0x1d60c8, Func Offset: 0xb8
	// Line 858, Address: 0x1d60e0, Func Offset: 0xd0
	// Line 861, Address: 0x1d610c, Func Offset: 0xfc
	// Line 858, Address: 0x1d6118, Func Offset: 0x108
	// Line 861, Address: 0x1d611c, Func Offset: 0x10c
	// Line 862, Address: 0x1d6134, Func Offset: 0x124
	// Line 863, Address: 0x1d6148, Func Offset: 0x138
	// Line 864, Address: 0x1d6174, Func Offset: 0x164
	// Line 865, Address: 0x1d6188, Func Offset: 0x178
	// Line 866, Address: 0x1d6190, Func Offset: 0x180
	// Line 868, Address: 0x1d61a8, Func Offset: 0x198
	// Line 871, Address: 0x1d61b0, Func Offset: 0x1a0
	// Line 868, Address: 0x1d61c0, Func Offset: 0x1b0
	// Line 871, Address: 0x1d61c4, Func Offset: 0x1b4
	// Line 872, Address: 0x1d61f0, Func Offset: 0x1e0
	// Line 873, Address: 0x1d61f8, Func Offset: 0x1e8
	// Line 874, Address: 0x1d61fc, Func Offset: 0x1ec
	// Line 875, Address: 0x1d6200, Func Offset: 0x1f0
	// Line 879, Address: 0x1d6204, Func Offset: 0x1f4
	// Func End, Address: 0x1d6218, Func Offset: 0x208
}

// 
// Start address: 0x1d6220
void bhEne12_MV02(BH_PWORK* epw)
{
	// Line 889, Address: 0x1d6220, Func Offset: 0
	// Line 890, Address: 0x1d6230, Func Offset: 0x10
	// Line 892, Address: 0x1d6250, Func Offset: 0x30
	// Line 893, Address: 0x1d625c, Func Offset: 0x3c
	// Line 895, Address: 0x1d6260, Func Offset: 0x40
	// Line 892, Address: 0x1d6264, Func Offset: 0x44
	// Line 893, Address: 0x1d626c, Func Offset: 0x4c
	// Line 897, Address: 0x1d6270, Func Offset: 0x50
	// Line 901, Address: 0x1d6274, Func Offset: 0x54
	// Line 904, Address: 0x1d6278, Func Offset: 0x58
	// Line 893, Address: 0x1d627c, Func Offset: 0x5c
	// Line 895, Address: 0x1d6284, Func Offset: 0x64
	// Line 896, Address: 0x1d6288, Func Offset: 0x68
	// Line 897, Address: 0x1d628c, Func Offset: 0x6c
	// Line 898, Address: 0x1d6290, Func Offset: 0x70
	// Line 901, Address: 0x1d62b4, Func Offset: 0x94
	// Line 904, Address: 0x1d62c0, Func Offset: 0xa0
	// Line 905, Address: 0x1d62c4, Func Offset: 0xa4
	// Line 906, Address: 0x1d62cc, Func Offset: 0xac
	// Line 907, Address: 0x1d62d4, Func Offset: 0xb4
	// Line 908, Address: 0x1d62e0, Func Offset: 0xc0
	// Line 909, Address: 0x1d62e8, Func Offset: 0xc8
	// Line 912, Address: 0x1d62f0, Func Offset: 0xd0
	// Line 914, Address: 0x1d6308, Func Offset: 0xe8
	// Line 915, Address: 0x1d6314, Func Offset: 0xf4
	// Line 916, Address: 0x1d631c, Func Offset: 0xfc
	// Line 917, Address: 0x1d6320, Func Offset: 0x100
	// Line 918, Address: 0x1d6324, Func Offset: 0x104
	// Line 919, Address: 0x1d6328, Func Offset: 0x108
	// Line 923, Address: 0x1d6338, Func Offset: 0x118
	// Line 924, Address: 0x1d6360, Func Offset: 0x140
	// Line 927, Address: 0x1d6368, Func Offset: 0x148
	// Line 928, Address: 0x1d637c, Func Offset: 0x15c
	// Line 931, Address: 0x1d6390, Func Offset: 0x170
	// Line 933, Address: 0x1d6398, Func Offset: 0x178
	// Line 931, Address: 0x1d639c, Func Offset: 0x17c
	// Line 932, Address: 0x1d63a0, Func Offset: 0x180
	// Line 931, Address: 0x1d63a4, Func Offset: 0x184
	// Line 932, Address: 0x1d63a8, Func Offset: 0x188
	// Line 933, Address: 0x1d63b0, Func Offset: 0x190
	// Line 935, Address: 0x1d63c0, Func Offset: 0x1a0
	// Line 939, Address: 0x1d63d8, Func Offset: 0x1b8
	// Line 940, Address: 0x1d63fc, Func Offset: 0x1dc
	// Line 941, Address: 0x1d6410, Func Offset: 0x1f0
	// Line 942, Address: 0x1d643c, Func Offset: 0x21c
	// Line 943, Address: 0x1d6450, Func Offset: 0x230
	// Line 944, Address: 0x1d6458, Func Offset: 0x238
	// Line 946, Address: 0x1d6470, Func Offset: 0x250
	// Line 948, Address: 0x1d6480, Func Offset: 0x260
	// Func End, Address: 0x1d6490, Func Offset: 0x270
}

// 
// Start address: 0x1d6490
void bhEne12_MV03(BH_PWORK* epw)
{
	_anon25 v;
	int i;
	// Line 958, Address: 0x1d6490, Func Offset: 0
	// Line 969, Address: 0x1d64a4, Func Offset: 0x14
	// Line 971, Address: 0x1d64c4, Func Offset: 0x34
	// Line 972, Address: 0x1d64cc, Func Offset: 0x3c
	// Line 975, Address: 0x1d64d0, Func Offset: 0x40
	// Line 977, Address: 0x1d64d4, Func Offset: 0x44
	// Line 971, Address: 0x1d64d8, Func Offset: 0x48
	// Line 972, Address: 0x1d64e0, Func Offset: 0x50
	// Line 979, Address: 0x1d64e4, Func Offset: 0x54
	// Line 972, Address: 0x1d64e8, Func Offset: 0x58
	// Line 975, Address: 0x1d64f0, Func Offset: 0x60
	// Line 977, Address: 0x1d64fc, Func Offset: 0x6c
	// Line 978, Address: 0x1d6500, Func Offset: 0x70
	// Line 979, Address: 0x1d6504, Func Offset: 0x74
	// Line 980, Address: 0x1d6508, Func Offset: 0x78
	// Line 981, Address: 0x1d652c, Func Offset: 0x9c
	// Line 982, Address: 0x1d6530, Func Offset: 0xa0
	// Line 983, Address: 0x1d6538, Func Offset: 0xa8
	// Line 986, Address: 0x1d6540, Func Offset: 0xb0
	// Line 987, Address: 0x1d6568, Func Offset: 0xd8
	// Line 988, Address: 0x1d656c, Func Offset: 0xdc
	// Line 989, Address: 0x1d6574, Func Offset: 0xe4
	// Line 990, Address: 0x1d6580, Func Offset: 0xf0
	// Line 991, Address: 0x1d65a0, Func Offset: 0x110
	// Line 990, Address: 0x1d65a4, Func Offset: 0x114
	// Line 992, Address: 0x1d65c8, Func Offset: 0x138
	// Line 993, Address: 0x1d65ec, Func Offset: 0x15c
	// Line 992, Address: 0x1d65f0, Func Offset: 0x160
	// Line 993, Address: 0x1d65fc, Func Offset: 0x16c
	// Line 992, Address: 0x1d6604, Func Offset: 0x174
	// Line 993, Address: 0x1d6628, Func Offset: 0x198
	// Line 994, Address: 0x1d6630, Func Offset: 0x1a0
	// Line 995, Address: 0x1d663c, Func Offset: 0x1ac
	// Line 996, Address: 0x1d667c, Func Offset: 0x1ec
	// Line 997, Address: 0x1d6680, Func Offset: 0x1f0
	// Line 996, Address: 0x1d6688, Func Offset: 0x1f8
	// Line 997, Address: 0x1d668c, Func Offset: 0x1fc
	// Line 998, Address: 0x1d6694, Func Offset: 0x204
	// Line 1000, Address: 0x1d6698, Func Offset: 0x208
	// Line 1001, Address: 0x1d66ac, Func Offset: 0x21c
	// Line 1004, Address: 0x1d66c0, Func Offset: 0x230
	// Line 1005, Address: 0x1d66cc, Func Offset: 0x23c
	// Line 1006, Address: 0x1d66d4, Func Offset: 0x244
	// Line 1007, Address: 0x1d66d8, Func Offset: 0x248
	// Line 1008, Address: 0x1d66dc, Func Offset: 0x24c
	// Line 1011, Address: 0x1d66e0, Func Offset: 0x250
	// Line 1013, Address: 0x1d66e8, Func Offset: 0x258
	// Line 1011, Address: 0x1d66ec, Func Offset: 0x25c
	// Line 1012, Address: 0x1d66f0, Func Offset: 0x260
	// Line 1011, Address: 0x1d66f4, Func Offset: 0x264
	// Line 1012, Address: 0x1d66f8, Func Offset: 0x268
	// Line 1013, Address: 0x1d6700, Func Offset: 0x270
	// Line 1015, Address: 0x1d6710, Func Offset: 0x280
	// Line 1019, Address: 0x1d6728, Func Offset: 0x298
	// Line 1020, Address: 0x1d674c, Func Offset: 0x2bc
	// Line 1021, Address: 0x1d6760, Func Offset: 0x2d0
	// Line 1022, Address: 0x1d678c, Func Offset: 0x2fc
	// Line 1023, Address: 0x1d67a0, Func Offset: 0x310
	// Line 1024, Address: 0x1d67a8, Func Offset: 0x318
	// Line 1026, Address: 0x1d67c0, Func Offset: 0x330
	// Line 1029, Address: 0x1d67c8, Func Offset: 0x338
	// Line 1026, Address: 0x1d67cc, Func Offset: 0x33c
	// Line 1029, Address: 0x1d67d4, Func Offset: 0x344
	// Line 1030, Address: 0x1d67ec, Func Offset: 0x35c
	// Line 1031, Address: 0x1d6804, Func Offset: 0x374
	// Line 1033, Address: 0x1d6838, Func Offset: 0x3a8
	// Func End, Address: 0x1d684c, Func Offset: 0x3bc
}

// 
// Start address: 0x1d6850
void bhEne12_MV04(BH_PWORK* epw)
{
	_anon25 v;
	int num;
	int i;
	float dist;
	// Line 1043, Address: 0x1d6850, Func Offset: 0
	// Line 1049, Address: 0x1d6870, Func Offset: 0x20
	// Line 1051, Address: 0x1d689c, Func Offset: 0x4c
	// Line 1052, Address: 0x1d68a4, Func Offset: 0x54
	// Line 1055, Address: 0x1d68a8, Func Offset: 0x58
	// Line 1057, Address: 0x1d68ac, Func Offset: 0x5c
	// Line 1051, Address: 0x1d68b0, Func Offset: 0x60
	// Line 1052, Address: 0x1d68b8, Func Offset: 0x68
	// Line 1059, Address: 0x1d68bc, Func Offset: 0x6c
	// Line 1066, Address: 0x1d68c0, Func Offset: 0x70
	// Line 1052, Address: 0x1d68c4, Func Offset: 0x74
	// Line 1055, Address: 0x1d68cc, Func Offset: 0x7c
	// Line 1057, Address: 0x1d68d8, Func Offset: 0x88
	// Line 1058, Address: 0x1d68dc, Func Offset: 0x8c
	// Line 1059, Address: 0x1d68e0, Func Offset: 0x90
	// Line 1060, Address: 0x1d68e4, Func Offset: 0x94
	// Line 1062, Address: 0x1d68e8, Func Offset: 0x98
	// Line 1063, Address: 0x1d68f0, Func Offset: 0xa0
	// Line 1064, Address: 0x1d68f8, Func Offset: 0xa8
	// Line 1066, Address: 0x1d6900, Func Offset: 0xb0
	// Line 1070, Address: 0x1d6934, Func Offset: 0xe4
	// Line 1071, Address: 0x1d6954, Func Offset: 0x104
	// Line 1072, Address: 0x1d6978, Func Offset: 0x128
	// Line 1076, Address: 0x1d6980, Func Offset: 0x130
	// Line 1077, Address: 0x1d69a0, Func Offset: 0x150
	// Line 1078, Address: 0x1d69c4, Func Offset: 0x174
	// Line 1083, Address: 0x1d69cc, Func Offset: 0x17c
	// Line 1084, Address: 0x1d69ec, Func Offset: 0x19c
	// Line 1085, Address: 0x1d6a10, Func Offset: 0x1c0
	// Line 1087, Address: 0x1d6a18, Func Offset: 0x1c8
	// Line 1091, Address: 0x1d6a20, Func Offset: 0x1d0
	// Line 1092, Address: 0x1d6a3c, Func Offset: 0x1ec
	// Line 1093, Address: 0x1d6a5c, Func Offset: 0x20c
	// Line 1095, Address: 0x1d6a80, Func Offset: 0x230
	// Line 1097, Address: 0x1d6a8c, Func Offset: 0x23c
	// Line 1098, Address: 0x1d6a94, Func Offset: 0x244
	// Line 1097, Address: 0x1d6a98, Func Offset: 0x248
	// Line 1098, Address: 0x1d6ab4, Func Offset: 0x264
	// Line 1099, Address: 0x1d6ab8, Func Offset: 0x268
	// Line 1100, Address: 0x1d6ac0, Func Offset: 0x270
	// Line 1103, Address: 0x1d6ac8, Func Offset: 0x278
	// Line 1104, Address: 0x1d6af0, Func Offset: 0x2a0
	// Line 1105, Address: 0x1d6b28, Func Offset: 0x2d8
	// Line 1106, Address: 0x1d6b34, Func Offset: 0x2e4
	// Line 1107, Address: 0x1d6b3c, Func Offset: 0x2ec
	// Line 1108, Address: 0x1d6be8, Func Offset: 0x398
	// Line 1109, Address: 0x1d6bec, Func Offset: 0x39c
	// Line 1110, Address: 0x1d6bf0, Func Offset: 0x3a0
	// Line 1111, Address: 0x1d6c0c, Func Offset: 0x3bc
	// Line 1110, Address: 0x1d6c18, Func Offset: 0x3c8
	// Line 1111, Address: 0x1d6c38, Func Offset: 0x3e8
	// Line 1112, Address: 0x1d6c40, Func Offset: 0x3f0
	// Line 1113, Address: 0x1d6c4c, Func Offset: 0x3fc
	// Line 1114, Address: 0x1d6ca4, Func Offset: 0x454
	// Line 1115, Address: 0x1d6ca8, Func Offset: 0x458
	// Line 1114, Address: 0x1d6cb0, Func Offset: 0x460
	// Line 1115, Address: 0x1d6cb4, Func Offset: 0x464
	// Line 1116, Address: 0x1d6cbc, Func Offset: 0x46c
	// Line 1118, Address: 0x1d6cc0, Func Offset: 0x470
	// Line 1119, Address: 0x1d6cd4, Func Offset: 0x484
	// Line 1122, Address: 0x1d6ce8, Func Offset: 0x498
	// Line 1123, Address: 0x1d6cf4, Func Offset: 0x4a4
	// Line 1124, Address: 0x1d6cfc, Func Offset: 0x4ac
	// Line 1125, Address: 0x1d6d00, Func Offset: 0x4b0
	// Line 1126, Address: 0x1d6d04, Func Offset: 0x4b4
	// Line 1129, Address: 0x1d6d08, Func Offset: 0x4b8
	// Line 1131, Address: 0x1d6d10, Func Offset: 0x4c0
	// Line 1129, Address: 0x1d6d14, Func Offset: 0x4c4
	// Line 1130, Address: 0x1d6d18, Func Offset: 0x4c8
	// Line 1129, Address: 0x1d6d1c, Func Offset: 0x4cc
	// Line 1130, Address: 0x1d6d20, Func Offset: 0x4d0
	// Line 1131, Address: 0x1d6d28, Func Offset: 0x4d8
	// Line 1133, Address: 0x1d6d38, Func Offset: 0x4e8
	// Line 1137, Address: 0x1d6d50, Func Offset: 0x500
	// Line 1138, Address: 0x1d6d74, Func Offset: 0x524
	// Line 1139, Address: 0x1d6d88, Func Offset: 0x538
	// Line 1140, Address: 0x1d6db4, Func Offset: 0x564
	// Line 1141, Address: 0x1d6dc8, Func Offset: 0x578
	// Line 1142, Address: 0x1d6dd0, Func Offset: 0x580
	// Line 1144, Address: 0x1d6de8, Func Offset: 0x598
	// Line 1147, Address: 0x1d6df0, Func Offset: 0x5a0
	// Line 1144, Address: 0x1d6df4, Func Offset: 0x5a4
	// Line 1147, Address: 0x1d6dfc, Func Offset: 0x5ac
	// Line 1148, Address: 0x1d6e14, Func Offset: 0x5c4
	// Line 1149, Address: 0x1d6e2c, Func Offset: 0x5dc
	// Line 1151, Address: 0x1d6e60, Func Offset: 0x610
	// Func End, Address: 0x1d6e84, Func Offset: 0x634
}

// 
// Start address: 0x1d6e90
void bhEne12_MV05()
{
	// Line 1163, Address: 0x1d6e90, Func Offset: 0
	// Func End, Address: 0x1d6e98, Func Offset: 0x8
}

// 
// Start address: 0x1d6ea0
void bhEne12_MV06(BH_PWORK* epw)
{
	// Line 1174, Address: 0x1d6ea0, Func Offset: 0
	// Line 1176, Address: 0x1d6eb4, Func Offset: 0x14
	// Line 1177, Address: 0x1d6ebc, Func Offset: 0x1c
	// Line 1179, Address: 0x1d6ec4, Func Offset: 0x24
	// Line 1176, Address: 0x1d6ec8, Func Offset: 0x28
	// Line 1177, Address: 0x1d6ed0, Func Offset: 0x30
	// Line 1178, Address: 0x1d6edc, Func Offset: 0x3c
	// Line 1179, Address: 0x1d6ee0, Func Offset: 0x40
	// Line 1180, Address: 0x1d6ee4, Func Offset: 0x44
	// Line 1181, Address: 0x1d6ee8, Func Offset: 0x48
	// Line 1183, Address: 0x1d6ef4, Func Offset: 0x54
	// Func End, Address: 0x1d6efc, Func Offset: 0x5c
}

// 
// Start address: 0x1d6f00
void bhEne12_MV07(BH_PWORK* epw)
{
	_anon10* mkaP;
	// Line 1193, Address: 0x1d6f00, Func Offset: 0
	// Line 1194, Address: 0x1d6f0c, Func Offset: 0xc
	// Line 1196, Address: 0x1d6f20, Func Offset: 0x20
	// Line 1197, Address: 0x1d6f30, Func Offset: 0x30
	// Line 1198, Address: 0x1d6f3c, Func Offset: 0x3c
	// Line 1197, Address: 0x1d6f40, Func Offset: 0x40
	// Line 1198, Address: 0x1d6f44, Func Offset: 0x44
	// Line 1200, Address: 0x1d6f50, Func Offset: 0x50
	// Line 1213, Address: 0x1d6f54, Func Offset: 0x54
	// Line 1211, Address: 0x1d6f5c, Func Offset: 0x5c
	// Line 1212, Address: 0x1d6f60, Func Offset: 0x60
	// Line 1217, Address: 0x1d6f64, Func Offset: 0x64
	// Line 1200, Address: 0x1d6f68, Func Offset: 0x68
	// Line 1205, Address: 0x1d6f70, Func Offset: 0x70
	// Line 1206, Address: 0x1d6f78, Func Offset: 0x78
	// Line 1218, Address: 0x1d6f7c, Func Offset: 0x7c
	// Line 1222, Address: 0x1d6f80, Func Offset: 0x80
	// Line 1205, Address: 0x1d6f84, Func Offset: 0x84
	// Line 1206, Address: 0x1d6f98, Func Offset: 0x98
	// Line 1205, Address: 0x1d6fa4, Func Offset: 0xa4
	// Line 1206, Address: 0x1d6fa8, Func Offset: 0xa8
	// Line 1207, Address: 0x1d6fb0, Func Offset: 0xb0
	// Line 1211, Address: 0x1d6fb8, Func Offset: 0xb8
	// Line 1212, Address: 0x1d6fc4, Func Offset: 0xc4
	// Line 1213, Address: 0x1d6fd0, Func Offset: 0xd0
	// Line 1214, Address: 0x1d6fdc, Func Offset: 0xdc
	// Line 1215, Address: 0x1d6fe4, Func Offset: 0xe4
	// Line 1216, Address: 0x1d6fe8, Func Offset: 0xe8
	// Line 1217, Address: 0x1d6fec, Func Offset: 0xec
	// Line 1218, Address: 0x1d6ff0, Func Offset: 0xf0
	// Line 1219, Address: 0x1d6ff4, Func Offset: 0xf4
	// Line 1222, Address: 0x1d7000, Func Offset: 0x100
	// Line 1224, Address: 0x1d7010, Func Offset: 0x110
	// Func End, Address: 0x1d7020, Func Offset: 0x120
}

// 
// Start address: 0x1d7020
void bhEne12_Nage(BH_PWORK* epw)
{
	// Line 1236, Address: 0x1d7020, Func Offset: 0
	// Func End, Address: 0x1d7040, Func Offset: 0x20
}

// 
// Start address: 0x1d7040
void bhEne12_NG00(BH_PWORK* epw)
{
	_anon24* efp;
	_anon25 wp;
	_anon25 pos[2];
	// Line 1247, Address: 0x1d7040, Func Offset: 0
	// Line 1248, Address: 0x1d7048, Func Offset: 0x8
	// Line 1247, Address: 0x1d704c, Func Offset: 0xc
	// Line 1248, Address: 0x1d7054, Func Offset: 0x14
	// Line 1254, Address: 0x1d7070, Func Offset: 0x30
	// Line 1257, Address: 0x1d7090, Func Offset: 0x50
	// Line 1259, Address: 0x1d709c, Func Offset: 0x5c
	// Line 1258, Address: 0x1d70a4, Func Offset: 0x64
	// Line 1257, Address: 0x1d70a8, Func Offset: 0x68
	// Line 1258, Address: 0x1d70b0, Func Offset: 0x70
	// Line 1260, Address: 0x1d70b4, Func Offset: 0x74
	// Line 1262, Address: 0x1d70b8, Func Offset: 0x78
	// Line 1264, Address: 0x1d70bc, Func Offset: 0x7c
	// Line 1258, Address: 0x1d70c0, Func Offset: 0x80
	// Line 1259, Address: 0x1d70c8, Func Offset: 0x88
	// Line 1268, Address: 0x1d70cc, Func Offset: 0x8c
	// Line 1259, Address: 0x1d70d4, Func Offset: 0x94
	// Line 1260, Address: 0x1d70dc, Func Offset: 0x9c
	// Line 1262, Address: 0x1d70e8, Func Offset: 0xa8
	// Line 1263, Address: 0x1d70ec, Func Offset: 0xac
	// Line 1264, Address: 0x1d70f0, Func Offset: 0xb0
	// Line 1265, Address: 0x1d70f4, Func Offset: 0xb4
	// Line 1268, Address: 0x1d7118, Func Offset: 0xd8
	// Line 1269, Address: 0x1d7120, Func Offset: 0xe0
	// Line 1270, Address: 0x1d712c, Func Offset: 0xec
	// Line 1271, Address: 0x1d7158, Func Offset: 0x118
	// Line 1272, Address: 0x1d7160, Func Offset: 0x120
	// Line 1273, Address: 0x1d7168, Func Offset: 0x128
	// Line 1277, Address: 0x1d7178, Func Offset: 0x138
	// Line 1278, Address: 0x1d719c, Func Offset: 0x15c
	// Line 1277, Address: 0x1d71a0, Func Offset: 0x160
	// Line 1278, Address: 0x1d71a4, Func Offset: 0x164
	// Line 1279, Address: 0x1d71a8, Func Offset: 0x168
	// Line 1282, Address: 0x1d71ac, Func Offset: 0x16c
	// Line 1283, Address: 0x1d71bc, Func Offset: 0x17c
	// Line 1282, Address: 0x1d71c0, Func Offset: 0x180
	// Line 1283, Address: 0x1d71cc, Func Offset: 0x18c
	// Line 1285, Address: 0x1d71dc, Func Offset: 0x19c
	// Line 1287, Address: 0x1d71e8, Func Offset: 0x1a8
	// Line 1289, Address: 0x1d71f8, Func Offset: 0x1b8
	// Line 1290, Address: 0x1d720c, Func Offset: 0x1cc
	// Line 1293, Address: 0x1d7210, Func Offset: 0x1d0
	// Line 1290, Address: 0x1d7214, Func Offset: 0x1d4
	// Line 1291, Address: 0x1d7218, Func Offset: 0x1d8
	// Line 1293, Address: 0x1d7220, Func Offset: 0x1e0
	// Line 1294, Address: 0x1d722c, Func Offset: 0x1ec
	// Line 1295, Address: 0x1d7230, Func Offset: 0x1f0
	// Line 1296, Address: 0x1d7234, Func Offset: 0x1f4
	// Line 1298, Address: 0x1d723c, Func Offset: 0x1fc
	// Line 1302, Address: 0x1d7244, Func Offset: 0x204
	// Line 1304, Address: 0x1d7258, Func Offset: 0x218
	// Line 1305, Address: 0x1d7260, Func Offset: 0x220
	// Line 1306, Address: 0x1d7274, Func Offset: 0x234
	// Line 1307, Address: 0x1d72a0, Func Offset: 0x260
	// Line 1309, Address: 0x1d72b4, Func Offset: 0x274
	// Line 1311, Address: 0x1d72c0, Func Offset: 0x280
	// Line 1312, Address: 0x1d72f0, Func Offset: 0x2b0
	// Line 1313, Address: 0x1d7310, Func Offset: 0x2d0
	// Line 1314, Address: 0x1d7330, Func Offset: 0x2f0
	// Line 1315, Address: 0x1d7338, Func Offset: 0x2f8
	// Line 1316, Address: 0x1d7340, Func Offset: 0x300
	// Line 1317, Address: 0x1d7348, Func Offset: 0x308
	// Line 1322, Address: 0x1d7350, Func Offset: 0x310
	// Line 1323, Address: 0x1d7360, Func Offset: 0x320
	// Line 1327, Address: 0x1d7374, Func Offset: 0x334
	// Line 1328, Address: 0x1d7384, Func Offset: 0x344
	// Line 1329, Address: 0x1d73a4, Func Offset: 0x364
	// Line 1330, Address: 0x1d73d0, Func Offset: 0x390
	// Line 1358, Address: 0x1d73fc, Func Offset: 0x3bc
	// Line 1361, Address: 0x1d7414, Func Offset: 0x3d4
	// Line 1362, Address: 0x1d7420, Func Offset: 0x3e0
	// Line 1363, Address: 0x1d7430, Func Offset: 0x3f0
	// Line 1365, Address: 0x1d7448, Func Offset: 0x408
	// Line 1366, Address: 0x1d745c, Func Offset: 0x41c
	// Line 1369, Address: 0x1d7468, Func Offset: 0x428
	// Func End, Address: 0x1d747c, Func Offset: 0x43c
}

// 
// Start address: 0x1d7480
void bhEne12_Damage(BH_PWORK* epw)
{
	// Line 1379, Address: 0x1d7480, Func Offset: 0
	// Line 1381, Address: 0x1d748c, Func Offset: 0xc
	// Line 1382, Address: 0x1d749c, Func Offset: 0x1c
	// Line 1384, Address: 0x1d74a8, Func Offset: 0x28
	// Line 1387, Address: 0x1d74bc, Func Offset: 0x3c
	// Line 1388, Address: 0x1d74dc, Func Offset: 0x5c
	// Line 1391, Address: 0x1d74ec, Func Offset: 0x6c
	// Line 1394, Address: 0x1d74f4, Func Offset: 0x74
	// Line 1391, Address: 0x1d74f8, Func Offset: 0x78
	// Line 1394, Address: 0x1d7500, Func Offset: 0x80
	// Line 1398, Address: 0x1d751c, Func Offset: 0x9c
	// Line 1402, Address: 0x1d7528, Func Offset: 0xa8
	// Line 1403, Address: 0x1d7548, Func Offset: 0xc8
	// Func End, Address: 0x1d7558, Func Offset: 0xd8
}

// 
// Start address: 0x1d7560
void bhEne12_DG00(BH_PWORK* epw)
{
	// Line 1413, Address: 0x1d7560, Func Offset: 0
	// Line 1414, Address: 0x1d756c, Func Offset: 0xc
	// Line 1416, Address: 0x1d758c, Func Offset: 0x2c
	// Line 1417, Address: 0x1d7598, Func Offset: 0x38
	// Line 1416, Address: 0x1d75a0, Func Offset: 0x40
	// Line 1417, Address: 0x1d75a8, Func Offset: 0x48
	// Line 1420, Address: 0x1d75b0, Func Offset: 0x50
	// Line 1421, Address: 0x1d75c0, Func Offset: 0x60
	// Line 1422, Address: 0x1d75c8, Func Offset: 0x68
	// Line 1423, Address: 0x1d75d4, Func Offset: 0x74
	// Line 1422, Address: 0x1d75d8, Func Offset: 0x78
	// Line 1423, Address: 0x1d75e0, Func Offset: 0x80
	// Line 1424, Address: 0x1d75e8, Func Offset: 0x88
	// Line 1425, Address: 0x1d75f0, Func Offset: 0x90
	// Line 1430, Address: 0x1d762c, Func Offset: 0xcc
	// Line 1431, Address: 0x1d7654, Func Offset: 0xf4
	// Line 1432, Address: 0x1d765c, Func Offset: 0xfc
	// Line 1433, Address: 0x1d7664, Func Offset: 0x104
	// Line 1436, Address: 0x1d7674, Func Offset: 0x114
	// Line 1439, Address: 0x1d767c, Func Offset: 0x11c
	// Line 1440, Address: 0x1d7680, Func Offset: 0x120
	// Line 1441, Address: 0x1d7688, Func Offset: 0x128
	// Line 1442, Address: 0x1d7690, Func Offset: 0x130
	// Line 1443, Address: 0x1d7698, Func Offset: 0x138
	// Line 1444, Address: 0x1d76bc, Func Offset: 0x15c
	// Line 1448, Address: 0x1d76c8, Func Offset: 0x168
	// Line 1449, Address: 0x1d76d8, Func Offset: 0x178
	// Line 1451, Address: 0x1d76e8, Func Offset: 0x188
	// Line 1452, Address: 0x1d76f8, Func Offset: 0x198
	// Line 1454, Address: 0x1d7750, Func Offset: 0x1f0
	// Line 1456, Address: 0x1d7754, Func Offset: 0x1f4
	// Line 1455, Address: 0x1d7758, Func Offset: 0x1f8
	// Line 1456, Address: 0x1d775c, Func Offset: 0x1fc
	// Line 1458, Address: 0x1d7760, Func Offset: 0x200
	// Line 1457, Address: 0x1d7764, Func Offset: 0x204
	// Line 1458, Address: 0x1d7768, Func Offset: 0x208
	// Line 1460, Address: 0x1d776c, Func Offset: 0x20c
	// Line 1462, Address: 0x1d7774, Func Offset: 0x214
	// Line 1464, Address: 0x1d7778, Func Offset: 0x218
	// Line 1463, Address: 0x1d777c, Func Offset: 0x21c
	// Line 1464, Address: 0x1d7780, Func Offset: 0x220
	// Line 1466, Address: 0x1d7784, Func Offset: 0x224
	// Line 1465, Address: 0x1d7788, Func Offset: 0x228
	// Line 1466, Address: 0x1d778c, Func Offset: 0x22c
	// Line 1468, Address: 0x1d7790, Func Offset: 0x230
	// Line 1470, Address: 0x1d7798, Func Offset: 0x238
	// Line 1472, Address: 0x1d779c, Func Offset: 0x23c
	// Line 1471, Address: 0x1d77a0, Func Offset: 0x240
	// Line 1472, Address: 0x1d77a4, Func Offset: 0x244
	// Line 1474, Address: 0x1d77a8, Func Offset: 0x248
	// Line 1473, Address: 0x1d77ac, Func Offset: 0x24c
	// Line 1474, Address: 0x1d77b0, Func Offset: 0x250
	// Line 1475, Address: 0x1d77b4, Func Offset: 0x254
	// Line 1479, Address: 0x1d77b8, Func Offset: 0x258
	// Line 1480, Address: 0x1d77c0, Func Offset: 0x260
	// Line 1482, Address: 0x1d77c8, Func Offset: 0x268
	// Line 1490, Address: 0x1d77cc, Func Offset: 0x26c
	// Line 1480, Address: 0x1d77d0, Func Offset: 0x270
	// Line 1482, Address: 0x1d77d8, Func Offset: 0x278
	// Line 1485, Address: 0x1d77e4, Func Offset: 0x284
	// Line 1486, Address: 0x1d77ec, Func Offset: 0x28c
	// Line 1487, Address: 0x1d77f4, Func Offset: 0x294
	// Line 1488, Address: 0x1d77fc, Func Offset: 0x29c
	// Line 1490, Address: 0x1d7804, Func Offset: 0x2a4
	// Line 1493, Address: 0x1d7810, Func Offset: 0x2b0
	// Func End, Address: 0x1d7820, Func Offset: 0x2c0
}

// 
// Start address: 0x1d7820
void bhEne12_Die(BH_PWORK* epw)
{
	// Line 1504, Address: 0x1d7820, Func Offset: 0
	// Func End, Address: 0x1d7840, Func Offset: 0x20
}

// 
// Start address: 0x1d7840
void bhEne12_DD00(BH_PWORK* epw)
{
	// Line 1515, Address: 0x1d7840, Func Offset: 0
	// Line 1516, Address: 0x1d7850, Func Offset: 0x10
	// Line 1518, Address: 0x1d7870, Func Offset: 0x30
	// Line 1519, Address: 0x1d787c, Func Offset: 0x3c
	// Line 1520, Address: 0x1d7884, Func Offset: 0x44
	// Line 1518, Address: 0x1d7888, Func Offset: 0x48
	// Line 1520, Address: 0x1d7890, Func Offset: 0x50
	// Line 1519, Address: 0x1d7894, Func Offset: 0x54
	// Line 1521, Address: 0x1d7898, Func Offset: 0x58
	// Line 1523, Address: 0x1d789c, Func Offset: 0x5c
	// Line 1525, Address: 0x1d78a0, Func Offset: 0x60
	// Line 1519, Address: 0x1d78a4, Func Offset: 0x64
	// Line 1520, Address: 0x1d78ac, Func Offset: 0x6c
	// Line 1526, Address: 0x1d78b0, Func Offset: 0x70
	// Line 1520, Address: 0x1d78b4, Func Offset: 0x74
	// Line 1521, Address: 0x1d78bc, Func Offset: 0x7c
	// Line 1523, Address: 0x1d78c8, Func Offset: 0x88
	// Line 1524, Address: 0x1d78cc, Func Offset: 0x8c
	// Line 1525, Address: 0x1d78d0, Func Offset: 0x90
	// Line 1526, Address: 0x1d78d4, Func Offset: 0x94
	// Line 1527, Address: 0x1d78d8, Func Offset: 0x98
	// Line 1528, Address: 0x1d78fc, Func Offset: 0xbc
	// Line 1530, Address: 0x1d7908, Func Offset: 0xc8
	// Line 1531, Address: 0x1d7918, Func Offset: 0xd8
	// Line 1532, Address: 0x1d7928, Func Offset: 0xe8
	// Line 1533, Address: 0x1d792c, Func Offset: 0xec
	// Line 1534, Address: 0x1d7938, Func Offset: 0xf8
	// Line 1538, Address: 0x1d7944, Func Offset: 0x104
	// Func End, Address: 0x1d7954, Func Offset: 0x114
}

// 
// Start address: 0x1d7960
void bhEne12_InitDamage(BH_PWORK* epw)
{
	// Line 1548, Address: 0x1d7960, Func Offset: 0
	// Line 1549, Address: 0x1d796c, Func Offset: 0xc
	// Line 1551, Address: 0x1d7970, Func Offset: 0x10
	// Line 1549, Address: 0x1d7974, Func Offset: 0x14
	// Line 1551, Address: 0x1d7978, Func Offset: 0x18
	// Line 1549, Address: 0x1d797c, Func Offset: 0x1c
	// Line 1551, Address: 0x1d7984, Func Offset: 0x24
	// Line 1554, Address: 0x1d7994, Func Offset: 0x34
	// Line 1555, Address: 0x1d79b4, Func Offset: 0x54
	// Line 1558, Address: 0x1d79c4, Func Offset: 0x64
	// Line 1561, Address: 0x1d79cc, Func Offset: 0x6c
	// Line 1558, Address: 0x1d79d0, Func Offset: 0x70
	// Line 1561, Address: 0x1d79d8, Func Offset: 0x78
	// Line 1566, Address: 0x1d79f4, Func Offset: 0x94
	// Line 1568, Address: 0x1d7a00, Func Offset: 0xa0
	// Line 1569, Address: 0x1d7a0c, Func Offset: 0xac
	// Line 1570, Address: 0x1d7a14, Func Offset: 0xb4
	// Line 1571, Address: 0x1d7a18, Func Offset: 0xb8
	// Line 1573, Address: 0x1d7a1c, Func Offset: 0xbc
	// Line 1574, Address: 0x1d7a24, Func Offset: 0xc4
	// Line 1575, Address: 0x1d7a38, Func Offset: 0xd8
	// Line 1576, Address: 0x1d7a58, Func Offset: 0xf8
	// Line 1577, Address: 0x1d7a60, Func Offset: 0x100
	// Line 1578, Address: 0x1d7a64, Func Offset: 0x104
	// Line 1579, Address: 0x1d7a68, Func Offset: 0x108
	// Line 1583, Address: 0x1d7a6c, Func Offset: 0x10c
	// Func End, Address: 0x1d7a7c, Func Offset: 0x11c
}

// 
// Start address: 0x1d7a80
void bhEne12_LookPlayaer(BH_PWORK* epw)
{
	npobj* objP;
	_anon10* mkaP;
	int ang;
	float out;
	_anon25 ov;
	_anon25 vec;
	_anon25 view;
	int rz2;
	int rz1;
	int rz;
	int ry;
	int rx;
	float* mat2;
	float* mat;
	// Line 1593, Address: 0x1d7a80, Func Offset: 0
	// Line 1594, Address: 0x1d7aa4, Func Offset: 0x24
	// Line 1593, Address: 0x1d7aa8, Func Offset: 0x28
	// Line 1594, Address: 0x1d7aac, Func Offset: 0x2c
	// Line 1603, Address: 0x1d7ab0, Func Offset: 0x30
	// Line 1595, Address: 0x1d7abc, Func Offset: 0x3c
	// Line 1603, Address: 0x1d7ac0, Func Offset: 0x40
	// Line 1604, Address: 0x1d7ac8, Func Offset: 0x48
	// Line 1605, Address: 0x1d7ad8, Func Offset: 0x58
	// Line 1608, Address: 0x1d7ae0, Func Offset: 0x60
	// Line 1610, Address: 0x1d7af4, Func Offset: 0x74
	// Line 1613, Address: 0x1d7b04, Func Offset: 0x84
	// Line 1617, Address: 0x1d7b08, Func Offset: 0x88
	// Line 1614, Address: 0x1d7b0c, Func Offset: 0x8c
	// Line 1613, Address: 0x1d7b10, Func Offset: 0x90
	// Line 1617, Address: 0x1d7b24, Func Offset: 0xa4
	// Line 1613, Address: 0x1d7b28, Func Offset: 0xa8
	// Line 1614, Address: 0x1d7b2c, Func Offset: 0xac
	// Line 1617, Address: 0x1d7b3c, Func Offset: 0xbc
	// Line 1618, Address: 0x1d7b44, Func Offset: 0xc4
	// Line 1619, Address: 0x1d7b50, Func Offset: 0xd0
	// Line 1620, Address: 0x1d7b70, Func Offset: 0xf0
	// Line 1621, Address: 0x1d7b78, Func Offset: 0xf8
	// Line 1622, Address: 0x1d7b84, Func Offset: 0x104
	// Line 1624, Address: 0x1d7b9c, Func Offset: 0x11c
	// Line 1629, Address: 0x1d7ba4, Func Offset: 0x124
	// Line 1630, Address: 0x1d7bac, Func Offset: 0x12c
	// Line 1631, Address: 0x1d7bb0, Func Offset: 0x130
	// Line 1629, Address: 0x1d7bb4, Func Offset: 0x134
	// Line 1632, Address: 0x1d7bbc, Func Offset: 0x13c
	// Line 1629, Address: 0x1d7bc0, Func Offset: 0x140
	// Line 1630, Address: 0x1d7bd4, Func Offset: 0x154
	// Line 1631, Address: 0x1d7bf4, Func Offset: 0x174
	// Line 1632, Address: 0x1d7c10, Func Offset: 0x190
	// Line 1635, Address: 0x1d7c18, Func Offset: 0x198
	// Line 1636, Address: 0x1d7c2c, Func Offset: 0x1ac
	// Line 1637, Address: 0x1d7c34, Func Offset: 0x1b4
	// Line 1640, Address: 0x1d7c44, Func Offset: 0x1c4
	// Line 1641, Address: 0x1d7c60, Func Offset: 0x1e0
	// Line 1640, Address: 0x1d7c68, Func Offset: 0x1e8
	// Line 1641, Address: 0x1d7c6c, Func Offset: 0x1ec
	// Line 1642, Address: 0x1d7c7c, Func Offset: 0x1fc
	// Line 1643, Address: 0x1d7c8c, Func Offset: 0x20c
	// Line 1644, Address: 0x1d7c9c, Func Offset: 0x21c
	// Line 1645, Address: 0x1d7ca8, Func Offset: 0x228
	// Line 1646, Address: 0x1d7cb8, Func Offset: 0x238
	// Line 1647, Address: 0x1d7cbc, Func Offset: 0x23c
	// Line 1648, Address: 0x1d7cc0, Func Offset: 0x240
	// Line 1649, Address: 0x1d7cc8, Func Offset: 0x248
	// Line 1650, Address: 0x1d7cd0, Func Offset: 0x250
	// Line 1651, Address: 0x1d7ce4, Func Offset: 0x264
	// Line 1654, Address: 0x1d7cf4, Func Offset: 0x274
	// Line 1655, Address: 0x1d7cf8, Func Offset: 0x278
	// Line 1656, Address: 0x1d7cfc, Func Offset: 0x27c
	// Line 1657, Address: 0x1d7d00, Func Offset: 0x280
	// Line 1658, Address: 0x1d7d14, Func Offset: 0x294
	// Line 1659, Address: 0x1d7d20, Func Offset: 0x2a0
	// Line 1661, Address: 0x1d7d40, Func Offset: 0x2c0
	// Line 1662, Address: 0x1d7d4c, Func Offset: 0x2cc
	// Line 1665, Address: 0x1d7d60, Func Offset: 0x2e0
	// Line 1666, Address: 0x1d7d7c, Func Offset: 0x2fc
	// Line 1669, Address: 0x1d7d8c, Func Offset: 0x30c
	// Line 1673, Address: 0x1d7d98, Func Offset: 0x318
	// Line 1675, Address: 0x1d7db0, Func Offset: 0x330
	// Line 1676, Address: 0x1d7dc4, Func Offset: 0x344
	// Line 1677, Address: 0x1d7dcc, Func Offset: 0x34c
	// Line 1678, Address: 0x1d7ddc, Func Offset: 0x35c
	// Line 1681, Address: 0x1d7de8, Func Offset: 0x368
	// Line 1682, Address: 0x1d7e04, Func Offset: 0x384
	// Line 1685, Address: 0x1d7e24, Func Offset: 0x3a4
	// Line 1686, Address: 0x1d7e38, Func Offset: 0x3b8
	// Line 1687, Address: 0x1d7e44, Func Offset: 0x3c4
	// Line 1689, Address: 0x1d7e78, Func Offset: 0x3f8
	// Line 1690, Address: 0x1d7e80, Func Offset: 0x400
	// Line 1691, Address: 0x1d7e90, Func Offset: 0x410
	// Line 1692, Address: 0x1d7ea0, Func Offset: 0x420
	// Line 1695, Address: 0x1d7eac, Func Offset: 0x42c
	// Line 1696, Address: 0x1d7ecc, Func Offset: 0x44c
	// Line 1695, Address: 0x1d7ed0, Func Offset: 0x450
	// Line 1696, Address: 0x1d7ed4, Func Offset: 0x454
	// Line 1699, Address: 0x1d7edc, Func Offset: 0x45c
	// Line 1700, Address: 0x1d7ee8, Func Offset: 0x468
	// Line 1699, Address: 0x1d7ef0, Func Offset: 0x470
	// Line 1700, Address: 0x1d7ef4, Func Offset: 0x474
	// Line 1701, Address: 0x1d7efc, Func Offset: 0x47c
	// Line 1705, Address: 0x1d7f20, Func Offset: 0x4a0
	// Line 1713, Address: 0x1d7f24, Func Offset: 0x4a4
	// Line 1705, Address: 0x1d7f28, Func Offset: 0x4a8
	// Line 1708, Address: 0x1d7f2c, Func Offset: 0x4ac
	// Line 1709, Address: 0x1d7f30, Func Offset: 0x4b0
	// Line 1710, Address: 0x1d7f34, Func Offset: 0x4b4
	// Line 1713, Address: 0x1d7f38, Func Offset: 0x4b8
	// Line 1714, Address: 0x1d7f48, Func Offset: 0x4c8
	// Line 1715, Address: 0x1d7f5c, Func Offset: 0x4dc
	// Line 1718, Address: 0x1d7f6c, Func Offset: 0x4ec
	// Line 1719, Address: 0x1d7f80, Func Offset: 0x500
	// Line 1721, Address: 0x1d7fa0, Func Offset: 0x520
	// Func End, Address: 0x1d7fcc, Func Offset: 0x54c
}

// 
// Start address: 0x1d7fd0
void bhEne12_HitMark(BH_PWORK* epw)
{
	_anon33* blp;
	_anon25 ofp;
	int i;
	int range;
	// Line 1731, Address: 0x1d7fd0, Func Offset: 0
	// Line 1737, Address: 0x1d7ff0, Func Offset: 0x20
	// Line 1738, Address: 0x1d7ff4, Func Offset: 0x24
	// Line 1737, Address: 0x1d7ffc, Func Offset: 0x2c
	// Line 1732, Address: 0x1d8004, Func Offset: 0x34
	// Line 1737, Address: 0x1d8008, Func Offset: 0x38
	// Line 1738, Address: 0x1d8018, Func Offset: 0x48
	// Line 1739, Address: 0x1d801c, Func Offset: 0x4c
	// Line 1740, Address: 0x1d802c, Func Offset: 0x5c
	// Line 1741, Address: 0x1d803c, Func Offset: 0x6c
	// Line 1742, Address: 0x1d8064, Func Offset: 0x94
	// Line 1743, Address: 0x1d8068, Func Offset: 0x98
	// Line 1742, Address: 0x1d806c, Func Offset: 0x9c
	// Line 1743, Address: 0x1d8070, Func Offset: 0xa0
	// Line 1744, Address: 0x1d8078, Func Offset: 0xa8
	// Line 1745, Address: 0x1d80a0, Func Offset: 0xd0
	// Line 1746, Address: 0x1d80e0, Func Offset: 0x110
	// Line 1747, Address: 0x1d8120, Func Offset: 0x150
	// Line 1749, Address: 0x1d8160, Func Offset: 0x190
	// Line 1759, Address: 0x1d8190, Func Offset: 0x1c0
	// Line 1760, Address: 0x1d81c0, Func Offset: 0x1f0
	// Line 1762, Address: 0x1d81c8, Func Offset: 0x1f8
	// Line 1767, Address: 0x1d81f8, Func Offset: 0x228
	// Line 1768, Address: 0x1d8208, Func Offset: 0x238
	// Line 1769, Address: 0x1d8230, Func Offset: 0x260
	// Line 1774, Address: 0x1d8240, Func Offset: 0x270
	// Line 1775, Address: 0x1d8274, Func Offset: 0x2a4
	// Line 1776, Address: 0x1d8278, Func Offset: 0x2a8
	// Line 1777, Address: 0x1d827c, Func Offset: 0x2ac
	// Line 1778, Address: 0x1d8280, Func Offset: 0x2b0
	// Line 1776, Address: 0x1d8284, Func Offset: 0x2b4
	// Line 1777, Address: 0x1d8288, Func Offset: 0x2b8
	// Line 1778, Address: 0x1d8290, Func Offset: 0x2c0
	// Line 1779, Address: 0x1d8298, Func Offset: 0x2c8
	// Line 1780, Address: 0x1d82d8, Func Offset: 0x308
	// Line 1781, Address: 0x1d8318, Func Offset: 0x348
	// Line 1782, Address: 0x1d8354, Func Offset: 0x384
	// Line 1783, Address: 0x1d83dc, Func Offset: 0x40c
	// Line 1784, Address: 0x1d83ec, Func Offset: 0x41c
	// Line 1786, Address: 0x1d83f0, Func Offset: 0x420
	// Line 1787, Address: 0x1d8418, Func Offset: 0x448
	// Line 1788, Address: 0x1d841c, Func Offset: 0x44c
	// Line 1789, Address: 0x1d8420, Func Offset: 0x450
	// Line 1787, Address: 0x1d8424, Func Offset: 0x454
	// Line 1788, Address: 0x1d8428, Func Offset: 0x458
	// Line 1789, Address: 0x1d8430, Func Offset: 0x460
	// Line 1790, Address: 0x1d8438, Func Offset: 0x468
	// Line 1791, Address: 0x1d8478, Func Offset: 0x4a8
	// Line 1792, Address: 0x1d84b8, Func Offset: 0x4e8
	// Line 1793, Address: 0x1d84d4, Func Offset: 0x504
	// Line 1792, Address: 0x1d84d8, Func Offset: 0x508
	// Line 1793, Address: 0x1d84fc, Func Offset: 0x52c
	// Line 1797, Address: 0x1d8508, Func Offset: 0x538
	// Func End, Address: 0x1d852c, Func Offset: 0x55c
}

// 
// Start address: 0x1d8530
void bhEne12_FixedLegPos(BH_PWORK* epw)
{
	_anon25 ret;
	int fno;
	// Line 1818, Address: 0x1d8530, Func Offset: 0
	// Line 1822, Address: 0x1d8540, Func Offset: 0x10
	// Line 1823, Address: 0x1d8554, Func Offset: 0x24
	// Line 1825, Address: 0x1d8564, Func Offset: 0x34
	// Line 1826, Address: 0x1d8568, Func Offset: 0x38
	// Line 1831, Address: 0x1d85b0, Func Offset: 0x80
	// Line 1832, Address: 0x1d85c0, Func Offset: 0x90
	// Line 1833, Address: 0x1d85f8, Func Offset: 0xc8
	// Line 1834, Address: 0x1d8600, Func Offset: 0xd0
	// Line 1836, Address: 0x1d8638, Func Offset: 0x108
	// Line 1838, Address: 0x1d8640, Func Offset: 0x110
	// Line 1839, Address: 0x1d8650, Func Offset: 0x120
	// Line 1840, Address: 0x1d8674, Func Offset: 0x144
	// Line 1841, Address: 0x1d867c, Func Offset: 0x14c
	// Line 1846, Address: 0x1d86a4, Func Offset: 0x174
	// Line 1847, Address: 0x1d86b4, Func Offset: 0x184
	// Line 1848, Address: 0x1d86c4, Func Offset: 0x194
	// Line 1849, Address: 0x1d86d4, Func Offset: 0x1a4
	// Line 1851, Address: 0x1d86e4, Func Offset: 0x1b4
	// Func End, Address: 0x1d86f4, Func Offset: 0x1c4
}

// 
// Start address: 0x1d8700
void bhEne12_PlayerControl(BH_PWORK* epw)
{
	// Line 1861, Address: 0x1d8700, Func Offset: 0
	// Line 1864, Address: 0x1d8714, Func Offset: 0x14
	// Line 1865, Address: 0x1d872c, Func Offset: 0x2c
	// Line 1868, Address: 0x1d874c, Func Offset: 0x4c
	// Line 1870, Address: 0x1d8778, Func Offset: 0x78
	// Line 1871, Address: 0x1d8784, Func Offset: 0x84
	// Line 1870, Address: 0x1d8788, Func Offset: 0x88
	// Line 1871, Address: 0x1d8790, Func Offset: 0x90
	// Line 1874, Address: 0x1d8798, Func Offset: 0x98
	// Line 1871, Address: 0x1d879c, Func Offset: 0x9c
	// Line 1874, Address: 0x1d87a4, Func Offset: 0xa4
	// Line 1875, Address: 0x1d87b4, Func Offset: 0xb4
	// Line 1876, Address: 0x1d87b8, Func Offset: 0xb8
	// Line 1877, Address: 0x1d87c0, Func Offset: 0xc0
	// Line 1879, Address: 0x1d87c8, Func Offset: 0xc8
	// Line 1880, Address: 0x1d87d0, Func Offset: 0xd0
	// Line 1881, Address: 0x1d87d4, Func Offset: 0xd4
	// Line 1882, Address: 0x1d87d8, Func Offset: 0xd8
	// Line 1886, Address: 0x1d87dc, Func Offset: 0xdc
	// Line 1879, Address: 0x1d87e0, Func Offset: 0xe0
	// Line 1880, Address: 0x1d87e4, Func Offset: 0xe4
	// Line 1881, Address: 0x1d87f0, Func Offset: 0xf0
	// Line 1882, Address: 0x1d87fc, Func Offset: 0xfc
	// Line 1883, Address: 0x1d8808, Func Offset: 0x108
	// Line 1886, Address: 0x1d8818, Func Offset: 0x118
	// Line 1888, Address: 0x1d8820, Func Offset: 0x120
	// Line 1889, Address: 0x1d882c, Func Offset: 0x12c
	// Line 1891, Address: 0x1d8834, Func Offset: 0x134
	// Line 1892, Address: 0x1d8840, Func Offset: 0x140
	// Line 1893, Address: 0x1d8844, Func Offset: 0x144
	// Line 1892, Address: 0x1d8848, Func Offset: 0x148
	// Line 1893, Address: 0x1d884c, Func Offset: 0x14c
	// Line 1894, Address: 0x1d885c, Func Offset: 0x15c
	// Line 1895, Address: 0x1d8860, Func Offset: 0x160
	// Line 1896, Address: 0x1d8868, Func Offset: 0x168
	// Line 1898, Address: 0x1d8870, Func Offset: 0x170
	// Line 1899, Address: 0x1d8878, Func Offset: 0x178
	// Line 1900, Address: 0x1d887c, Func Offset: 0x17c
	// Line 1901, Address: 0x1d8880, Func Offset: 0x180
	// Line 1898, Address: 0x1d8884, Func Offset: 0x184
	// Line 1899, Address: 0x1d8888, Func Offset: 0x188
	// Line 1900, Address: 0x1d8894, Func Offset: 0x194
	// Line 1901, Address: 0x1d88a0, Func Offset: 0x1a0
	// Line 1902, Address: 0x1d88ac, Func Offset: 0x1ac
	// Line 1904, Address: 0x1d88bc, Func Offset: 0x1bc
	// Line 1906, Address: 0x1d88c4, Func Offset: 0x1c4
	// Line 1908, Address: 0x1d88d0, Func Offset: 0x1d0
	// Line 1909, Address: 0x1d88d4, Func Offset: 0x1d4
	// Line 1913, Address: 0x1d88e0, Func Offset: 0x1e0
	// Line 1910, Address: 0x1d88e4, Func Offset: 0x1e4
	// Line 1908, Address: 0x1d88e8, Func Offset: 0x1e8
	// Line 1909, Address: 0x1d88ec, Func Offset: 0x1ec
	// Line 1914, Address: 0x1d88f0, Func Offset: 0x1f0
	// Line 1909, Address: 0x1d88f4, Func Offset: 0x1f4
	// Line 1910, Address: 0x1d88f8, Func Offset: 0x1f8
	// Line 1909, Address: 0x1d88fc, Func Offset: 0x1fc
	// Line 1910, Address: 0x1d8904, Func Offset: 0x204
	// Line 1911, Address: 0x1d890c, Func Offset: 0x20c
	// Line 1910, Address: 0x1d8910, Func Offset: 0x210
	// Line 1911, Address: 0x1d8918, Func Offset: 0x218
	// Line 1912, Address: 0x1d8920, Func Offset: 0x220
	// Line 1911, Address: 0x1d8924, Func Offset: 0x224
	// Line 1912, Address: 0x1d892c, Func Offset: 0x22c
	// Line 1913, Address: 0x1d8934, Func Offset: 0x234
	// Line 1914, Address: 0x1d8940, Func Offset: 0x240
	// Line 1913, Address: 0x1d8944, Func Offset: 0x244
	// Line 1914, Address: 0x1d894c, Func Offset: 0x24c
	// Line 1919, Address: 0x1d8950, Func Offset: 0x250
	// Line 1920, Address: 0x1d8964, Func Offset: 0x264
	// Line 1923, Address: 0x1d8984, Func Offset: 0x284
	// Line 1925, Address: 0x1d89b0, Func Offset: 0x2b0
	// Line 1926, Address: 0x1d89bc, Func Offset: 0x2bc
	// Line 1925, Address: 0x1d89c8, Func Offset: 0x2c8
	// Line 1926, Address: 0x1d89d0, Func Offset: 0x2d0
	// Line 1927, Address: 0x1d89d4, Func Offset: 0x2d4
	// Line 1935, Address: 0x1d89dc, Func Offset: 0x2dc
	// Line 1926, Address: 0x1d89e0, Func Offset: 0x2e0
	// Line 1927, Address: 0x1d89e4, Func Offset: 0x2e4
	// Line 1926, Address: 0x1d89e8, Func Offset: 0x2e8
	// Line 1927, Address: 0x1d89f0, Func Offset: 0x2f0
	// Line 1928, Address: 0x1d89f8, Func Offset: 0x2f8
	// Line 1927, Address: 0x1d89fc, Func Offset: 0x2fc
	// Line 1928, Address: 0x1d8a04, Func Offset: 0x304
	// Line 1931, Address: 0x1d8a0c, Func Offset: 0x30c
	// Line 1928, Address: 0x1d8a10, Func Offset: 0x310
	// Line 1931, Address: 0x1d8a18, Func Offset: 0x318
	// Line 1935, Address: 0x1d8a20, Func Offset: 0x320
	// Line 1931, Address: 0x1d8a24, Func Offset: 0x324
	// Line 1935, Address: 0x1d8a30, Func Offset: 0x330
	// Line 1937, Address: 0x1d8a38, Func Offset: 0x338
	// Line 1935, Address: 0x1d8a3c, Func Offset: 0x33c
	// Line 1937, Address: 0x1d8a48, Func Offset: 0x348
	// Line 1939, Address: 0x1d8a58, Func Offset: 0x358
	// Line 1941, Address: 0x1d8a5c, Func Offset: 0x35c
	// Line 1942, Address: 0x1d8a88, Func Offset: 0x388
	// Line 1944, Address: 0x1d8a90, Func Offset: 0x390
	// Line 1946, Address: 0x1d8a98, Func Offset: 0x398
	// Line 1948, Address: 0x1d8ac8, Func Offset: 0x3c8
	// Line 1953, Address: 0x1d8ad4, Func Offset: 0x3d4
	// Line 1954, Address: 0x1d8ad8, Func Offset: 0x3d8
	// Line 1948, Address: 0x1d8adc, Func Offset: 0x3dc
	// Line 1950, Address: 0x1d8ae0, Func Offset: 0x3e0
	// Line 1951, Address: 0x1d8aec, Func Offset: 0x3ec
	// Line 1950, Address: 0x1d8af0, Func Offset: 0x3f0
	// Line 1951, Address: 0x1d8af4, Func Offset: 0x3f4
	// Line 1952, Address: 0x1d8afc, Func Offset: 0x3fc
	// Line 1951, Address: 0x1d8b00, Func Offset: 0x400
	// Line 1952, Address: 0x1d8b08, Func Offset: 0x408
	// Line 1953, Address: 0x1d8b10, Func Offset: 0x410
	// Line 1954, Address: 0x1d8b1c, Func Offset: 0x41c
	// Line 1955, Address: 0x1d8b28, Func Offset: 0x428
	// Line 1957, Address: 0x1d8b34, Func Offset: 0x434
	// Line 1959, Address: 0x1d8b48, Func Offset: 0x448
	// Line 1961, Address: 0x1d8b60, Func Offset: 0x460
	// Line 1962, Address: 0x1d8b70, Func Offset: 0x470
	// Line 1964, Address: 0x1d8b80, Func Offset: 0x480
	// Line 1962, Address: 0x1d8b84, Func Offset: 0x484
	// Line 1964, Address: 0x1d8ba0, Func Offset: 0x4a0
	// Line 1967, Address: 0x1d8bb0, Func Offset: 0x4b0
	// Line 1968, Address: 0x1d8bc4, Func Offset: 0x4c4
	// Line 1969, Address: 0x1d8bf0, Func Offset: 0x4f0
	// Line 1968, Address: 0x1d8bf4, Func Offset: 0x4f4
	// Line 1969, Address: 0x1d8bfc, Func Offset: 0x4fc
	// Line 1971, Address: 0x1d8c08, Func Offset: 0x508
	// Line 1974, Address: 0x1d8c10, Func Offset: 0x510
	// Line 1975, Address: 0x1d8c1c, Func Offset: 0x51c
	// Line 1976, Address: 0x1d8c48, Func Offset: 0x548
	// Line 1975, Address: 0x1d8c4c, Func Offset: 0x54c
	// Line 1976, Address: 0x1d8c54, Func Offset: 0x554
	// Line 1979, Address: 0x1d8c64, Func Offset: 0x564
	// Line 1981, Address: 0x1d8c7c, Func Offset: 0x57c
	// Line 1984, Address: 0x1d8c88, Func Offset: 0x588
	// Line 1985, Address: 0x1d8c9c, Func Offset: 0x59c
	// Line 1986, Address: 0x1d8d00, Func Offset: 0x600
	// Line 1987, Address: 0x1d8d0c, Func Offset: 0x60c
	// Line 1992, Address: 0x1d8d20, Func Offset: 0x620
	// Line 1993, Address: 0x1d8d30, Func Offset: 0x630
	// Line 1995, Address: 0x1d8d34, Func Offset: 0x634
	// Line 1992, Address: 0x1d8d38, Func Offset: 0x638
	// Line 1993, Address: 0x1d8d40, Func Offset: 0x640
	// Line 1992, Address: 0x1d8d44, Func Offset: 0x644
	// Line 1993, Address: 0x1d8d48, Func Offset: 0x648
	// Line 1994, Address: 0x1d8d4c, Func Offset: 0x64c
	// Line 1995, Address: 0x1d8d54, Func Offset: 0x654
	// Line 1996, Address: 0x1d8d5c, Func Offset: 0x65c
	// Line 1995, Address: 0x1d8d60, Func Offset: 0x660
	// Line 1996, Address: 0x1d8d68, Func Offset: 0x668
	// Line 1997, Address: 0x1d8d70, Func Offset: 0x670
	// Line 1998, Address: 0x1d8d7c, Func Offset: 0x67c
	// Line 1997, Address: 0x1d8d80, Func Offset: 0x680
	// Line 1998, Address: 0x1d8d88, Func Offset: 0x688
	// Line 2002, Address: 0x1d8d98, Func Offset: 0x698
	// Func End, Address: 0x1d8db0, Func Offset: 0x6b0
}

// 
// Start address: 0x1d8db0
void bhEne12_FlameLiquid(BH_PWORK* epw, _anon25* pos, int time)
{
	float scale;
	_anon25 n;
	_anon13* hp;
	int eno;
	_anon25 p2;
	_anon25 p1;
	_anon1* p;
	// Line 2012, Address: 0x1d8db0, Func Offset: 0
	// Line 2021, Address: 0x1d8dd0, Func Offset: 0x20
	// Line 2026, Address: 0x1d8ddc, Func Offset: 0x2c
	// Line 2027, Address: 0x1d8de0, Func Offset: 0x30
	// Line 2021, Address: 0x1d8de4, Func Offset: 0x34
	// Line 2028, Address: 0x1d8de8, Func Offset: 0x38
	// Line 2022, Address: 0x1d8df4, Func Offset: 0x44
	// Line 2023, Address: 0x1d8dfc, Func Offset: 0x4c
	// Line 2024, Address: 0x1d8e04, Func Offset: 0x54
	// Line 2025, Address: 0x1d8e0c, Func Offset: 0x5c
	// Line 2026, Address: 0x1d8e14, Func Offset: 0x64
	// Line 2027, Address: 0x1d8e1c, Func Offset: 0x6c
	// Line 2028, Address: 0x1d8e20, Func Offset: 0x70
	// Line 2029, Address: 0x1d8e2c, Func Offset: 0x7c
	// Line 2057, Address: 0x1d8e34, Func Offset: 0x84
	// Line 2058, Address: 0x1d8e3c, Func Offset: 0x8c
	// Line 2059, Address: 0x1d8e44, Func Offset: 0x94
	// Line 2060, Address: 0x1d8e58, Func Offset: 0xa8
	// Line 2059, Address: 0x1d8e5c, Func Offset: 0xac
	// Line 2061, Address: 0x1d8e60, Func Offset: 0xb0
	// Line 2063, Address: 0x1d8e64, Func Offset: 0xb4
	// Line 2059, Address: 0x1d8e6c, Func Offset: 0xbc
	// Line 2064, Address: 0x1d8e70, Func Offset: 0xc0
	// Line 2059, Address: 0x1d8e74, Func Offset: 0xc4
	// Line 2060, Address: 0x1d8e78, Func Offset: 0xc8
	// Line 2061, Address: 0x1d8e8c, Func Offset: 0xdc
	// Line 2063, Address: 0x1d8ea0, Func Offset: 0xf0
	// Line 2064, Address: 0x1d8eb0, Func Offset: 0x100
	// Line 2065, Address: 0x1d8ec4, Func Offset: 0x114
	// Line 2066, Address: 0x1d8ed8, Func Offset: 0x128
	// Line 2067, Address: 0x1d8ef0, Func Offset: 0x140
	// Line 2068, Address: 0x1d8f08, Func Offset: 0x158
	// Line 2069, Address: 0x1d8f1c, Func Offset: 0x16c
	// Line 2070, Address: 0x1d8f44, Func Offset: 0x194
	// Line 2069, Address: 0x1d8f48, Func Offset: 0x198
	// Line 2070, Address: 0x1d8f58, Func Offset: 0x1a8
	// Line 2071, Address: 0x1d8f5c, Func Offset: 0x1ac
	// Line 2075, Address: 0x1d8f60, Func Offset: 0x1b0
	// Line 2070, Address: 0x1d8f6c, Func Offset: 0x1bc
	// Line 2069, Address: 0x1d8f74, Func Offset: 0x1c4
	// Line 2070, Address: 0x1d8f84, Func Offset: 0x1d4
	// Line 2071, Address: 0x1d8f88, Func Offset: 0x1d8
	// Line 2072, Address: 0x1d8f9c, Func Offset: 0x1ec
	// Line 2075, Address: 0x1d8fb0, Func Offset: 0x200
	// Line 2076, Address: 0x1d8fc8, Func Offset: 0x218
	// Line 2077, Address: 0x1d8fd4, Func Offset: 0x224
	// Line 2078, Address: 0x1d8ffc, Func Offset: 0x24c
	// Line 2079, Address: 0x1d9010, Func Offset: 0x260
	// Line 2080, Address: 0x1d9024, Func Offset: 0x274
	// Line 2083, Address: 0x1d9038, Func Offset: 0x288
	// Line 2084, Address: 0x1d9064, Func Offset: 0x2b4
	// Line 2087, Address: 0x1d9080, Func Offset: 0x2d0
	// Line 2089, Address: 0x1d9090, Func Offset: 0x2e0
	// Func End, Address: 0x1d90b4, Func Offset: 0x304
}

// 
// Start address: 0x1d90c0
void bhEne12_Acid(BH_PWORK* epw)
{
	float size;
	float spd;
	_anon1* owk;
	int i;
	int eno;
	// Line 2099, Address: 0x1d90c0, Func Offset: 0
	// Line 2107, Address: 0x1d90f4, Func Offset: 0x34
	// Line 2108, Address: 0x1d9100, Func Offset: 0x40
	// Line 2109, Address: 0x1d9104, Func Offset: 0x44
	// Line 2110, Address: 0x1d9108, Func Offset: 0x48
	// Line 2113, Address: 0x1d910c, Func Offset: 0x4c
	// Line 2115, Address: 0x1d911c, Func Offset: 0x5c
	// Line 2117, Address: 0x1d9130, Func Offset: 0x70
	// Line 2115, Address: 0x1d913c, Func Offset: 0x7c
	// Line 2118, Address: 0x1d9140, Func Offset: 0x80
	// Line 2119, Address: 0x1d9144, Func Offset: 0x84
	// Line 2117, Address: 0x1d9148, Func Offset: 0x88
	// Line 2118, Address: 0x1d9154, Func Offset: 0x94
	// Line 2124, Address: 0x1d915c, Func Offset: 0x9c
	// Line 2118, Address: 0x1d9160, Func Offset: 0xa0
	// Line 2119, Address: 0x1d916c, Func Offset: 0xac
	// Line 2120, Address: 0x1d9180, Func Offset: 0xc0
	// Line 2121, Address: 0x1d9194, Func Offset: 0xd4
	// Line 2122, Address: 0x1d91a8, Func Offset: 0xe8
	// Line 2125, Address: 0x1d91bc, Func Offset: 0xfc
	// Line 2126, Address: 0x1d91d4, Func Offset: 0x114
	// Line 2125, Address: 0x1d91dc, Func Offset: 0x11c
	// Line 2130, Address: 0x1d91e0, Func Offset: 0x120
	// Line 2125, Address: 0x1d91e8, Func Offset: 0x128
	// Line 2126, Address: 0x1d91f8, Func Offset: 0x138
	// Line 2130, Address: 0x1d9200, Func Offset: 0x140
	// Line 2125, Address: 0x1d9204, Func Offset: 0x144
	// Line 2126, Address: 0x1d9208, Func Offset: 0x148
	// Line 2127, Address: 0x1d920c, Func Offset: 0x14c
	// Line 2128, Address: 0x1d9220, Func Offset: 0x160
	// Line 2130, Address: 0x1d9234, Func Offset: 0x174
	// Line 2131, Address: 0x1d924c, Func Offset: 0x18c
	// Line 2132, Address: 0x1d9258, Func Offset: 0x198
	// Line 2136, Address: 0x1d927c, Func Offset: 0x1bc
	// Line 2135, Address: 0x1d9284, Func Offset: 0x1c4
	// Line 2136, Address: 0x1d9288, Func Offset: 0x1c8
	// Line 2132, Address: 0x1d928c, Func Offset: 0x1cc
	// Line 2133, Address: 0x1d9294, Func Offset: 0x1d4
	// Line 2138, Address: 0x1d9298, Func Offset: 0x1d8
	// Line 2137, Address: 0x1d92a0, Func Offset: 0x1e0
	// Line 2141, Address: 0x1d92a4, Func Offset: 0x1e4
	// Line 2133, Address: 0x1d92a8, Func Offset: 0x1e8
	// Line 2134, Address: 0x1d92ac, Func Offset: 0x1ec
	// Line 2135, Address: 0x1d92b0, Func Offset: 0x1f0
	// Line 2136, Address: 0x1d92b4, Func Offset: 0x1f4
	// Line 2137, Address: 0x1d92b8, Func Offset: 0x1f8
	// Line 2141, Address: 0x1d92bc, Func Offset: 0x1fc
	// Line 2142, Address: 0x1d92c4, Func Offset: 0x204
	// Line 2143, Address: 0x1d9310, Func Offset: 0x250
	// Line 2145, Address: 0x1d9320, Func Offset: 0x260
	// Line 2146, Address: 0x1d9330, Func Offset: 0x270
	// Line 2145, Address: 0x1d9334, Func Offset: 0x274
	// Line 2146, Address: 0x1d9340, Func Offset: 0x280
	// Line 2145, Address: 0x1d9344, Func Offset: 0x284
	// Line 2146, Address: 0x1d9348, Func Offset: 0x288
	// Line 2147, Address: 0x1d9354, Func Offset: 0x294
	// Line 2148, Address: 0x1d9368, Func Offset: 0x2a8
	// Line 2149, Address: 0x1d937c, Func Offset: 0x2bc
	// Line 2150, Address: 0x1d9380, Func Offset: 0x2c0
	// Line 2151, Address: 0x1d9390, Func Offset: 0x2d0
	// Func End, Address: 0x1d93c8, Func Offset: 0x308
}

// 
// Start address: 0x1d93d0
void bhEne12_CheckWall(BH_PWORK* epw)
{
	_anon1* owk;
	// Line 2161, Address: 0x1d93d0, Func Offset: 0
	// Line 2165, Address: 0x1d93e8, Func Offset: 0x18
	// Line 2166, Address: 0x1d93ec, Func Offset: 0x1c
	// Line 2168, Address: 0x1d93f0, Func Offset: 0x20
	// Line 2167, Address: 0x1d93f4, Func Offset: 0x24
	// Line 2165, Address: 0x1d93fc, Func Offset: 0x2c
	// Line 2166, Address: 0x1d9400, Func Offset: 0x30
	// Line 2168, Address: 0x1d9404, Func Offset: 0x34
	// Line 2167, Address: 0x1d9408, Func Offset: 0x38
	// Line 2166, Address: 0x1d940c, Func Offset: 0x3c
	// Line 2168, Address: 0x1d9410, Func Offset: 0x40
	// Line 2171, Address: 0x1d9414, Func Offset: 0x44
	// Line 2172, Address: 0x1d941c, Func Offset: 0x4c
	// Line 2167, Address: 0x1d9420, Func Offset: 0x50
	// Line 2172, Address: 0x1d9424, Func Offset: 0x54
	// Line 2173, Address: 0x1d942c, Func Offset: 0x5c
	// Line 2174, Address: 0x1d9434, Func Offset: 0x64
	// Line 2175, Address: 0x1d943c, Func Offset: 0x6c
	// Line 2180, Address: 0x1d9440, Func Offset: 0x70
	// Line 2175, Address: 0x1d9444, Func Offset: 0x74
	// Line 2176, Address: 0x1d944c, Func Offset: 0x7c
	// Line 2177, Address: 0x1d9458, Func Offset: 0x88
	// Line 2180, Address: 0x1d9460, Func Offset: 0x90
	// Line 2181, Address: 0x1d9468, Func Offset: 0x98
	// Func End, Address: 0x1d9484, Func Offset: 0xb4
}

// 
// Start address: 0x1d9490
void bhEne12_Blood(BH_PWORK* epw, int num)
{
	int i;
	float dist;
	int ang;
	int base_ang;
	float scale;
	int eno;
	// Line 2191, Address: 0x1d9490, Func Offset: 0
	// Line 2198, Address: 0x1d94b0, Func Offset: 0x20
	// Line 2199, Address: 0x1d94c0, Func Offset: 0x30
	// Line 2198, Address: 0x1d94c4, Func Offset: 0x34
	// Line 2199, Address: 0x1d94d0, Func Offset: 0x40
	// Line 2200, Address: 0x1d94e8, Func Offset: 0x58
	// Line 2201, Address: 0x1d94fc, Func Offset: 0x6c
	// Line 2203, Address: 0x1d9520, Func Offset: 0x90
	// Line 2201, Address: 0x1d9524, Func Offset: 0x94
	// Line 2203, Address: 0x1d9528, Func Offset: 0x98
	// Line 2204, Address: 0x1d9530, Func Offset: 0xa0
	// Line 2205, Address: 0x1d9568, Func Offset: 0xd8
	// Line 2206, Address: 0x1d95c4, Func Offset: 0x134
	// Line 2207, Address: 0x1d95dc, Func Offset: 0x14c
	// Line 2208, Address: 0x1d95e4, Func Offset: 0x154
	// Line 2206, Address: 0x1d95e8, Func Offset: 0x158
	// Line 2207, Address: 0x1d95f8, Func Offset: 0x168
	// Line 2208, Address: 0x1d9614, Func Offset: 0x184
	// Line 2209, Address: 0x1d9638, Func Offset: 0x1a8
	// Line 2210, Address: 0x1d9660, Func Offset: 0x1d0
	// Line 2209, Address: 0x1d9664, Func Offset: 0x1d4
	// Line 2210, Address: 0x1d9674, Func Offset: 0x1e4
	// Line 2211, Address: 0x1d9678, Func Offset: 0x1e8
	// Line 2215, Address: 0x1d967c, Func Offset: 0x1ec
	// Line 2210, Address: 0x1d9688, Func Offset: 0x1f8
	// Line 2209, Address: 0x1d9690, Func Offset: 0x200
	// Line 2210, Address: 0x1d96a0, Func Offset: 0x210
	// Line 2211, Address: 0x1d96a4, Func Offset: 0x214
	// Line 2212, Address: 0x1d96b8, Func Offset: 0x228
	// Line 2215, Address: 0x1d96cc, Func Offset: 0x23c
	// Line 2216, Address: 0x1d96e4, Func Offset: 0x254
	// Line 2217, Address: 0x1d96f0, Func Offset: 0x260
	// Line 2218, Address: 0x1d9714, Func Offset: 0x284
	// Line 2219, Address: 0x1d971c, Func Offset: 0x28c
	// Line 2220, Address: 0x1d9720, Func Offset: 0x290
	// Line 2221, Address: 0x1d9724, Func Offset: 0x294
	// Line 2220, Address: 0x1d9728, Func Offset: 0x298
	// Line 2221, Address: 0x1d9730, Func Offset: 0x2a0
	// Line 2222, Address: 0x1d9734, Func Offset: 0x2a4
	// Line 2223, Address: 0x1d9738, Func Offset: 0x2a8
	// Line 2224, Address: 0x1d9748, Func Offset: 0x2b8
	// Func End, Address: 0x1d976c, Func Offset: 0x2dc
}

// 
// Start address: 0x1d9770
int bhEne12_AvoidWall(BH_PWORK* epw)
{
	int i;
	_anon25 p2;
	_anon25 p1;
	// Line 2234, Address: 0x1d9770, Func Offset: 0
	// Line 2238, Address: 0x1d9788, Func Offset: 0x18
	// Line 2240, Address: 0x1d978c, Func Offset: 0x1c
	// Line 2242, Address: 0x1d9790, Func Offset: 0x20
	// Line 2244, Address: 0x1d9798, Func Offset: 0x28
	// Line 2238, Address: 0x1d979c, Func Offset: 0x2c
	// Line 2239, Address: 0x1d97a0, Func Offset: 0x30
	// Line 2246, Address: 0x1d97a4, Func Offset: 0x34
	// Line 2239, Address: 0x1d97a8, Func Offset: 0x38
	// Line 2240, Address: 0x1d97ac, Func Offset: 0x3c
	// Line 2242, Address: 0x1d97b4, Func Offset: 0x44
	// Line 2246, Address: 0x1d97b8, Func Offset: 0x48
	// Line 2242, Address: 0x1d97bc, Func Offset: 0x4c
	// Line 2243, Address: 0x1d97c4, Func Offset: 0x54
	// Line 2244, Address: 0x1d97cc, Func Offset: 0x5c
	// Line 2246, Address: 0x1d97d0, Func Offset: 0x60
	// Line 2248, Address: 0x1d97e8, Func Offset: 0x78
	// Line 2250, Address: 0x1d97f8, Func Offset: 0x88
	// Line 2248, Address: 0x1d97fc, Func Offset: 0x8c
	// Line 2249, Address: 0x1d9808, Func Offset: 0x98
	// Line 2251, Address: 0x1d981c, Func Offset: 0xac
	// Line 2253, Address: 0x1d9824, Func Offset: 0xb4
	// Line 2251, Address: 0x1d9830, Func Offset: 0xc0
	// Line 2252, Address: 0x1d9838, Func Offset: 0xc8
	// Line 2253, Address: 0x1d9848, Func Offset: 0xd8
	// Line 2254, Address: 0x1d9864, Func Offset: 0xf4
	// Line 2255, Address: 0x1d9874, Func Offset: 0x104
	// Func End, Address: 0x1d9890, Func Offset: 0x120
}

// 
// Start address: 0x1d9890
void bhEne12_CallSE(BH_PWORK* epw)
{
	// Line 2265, Address: 0x1d9890, Func Offset: 0
	// Line 2266, Address: 0x1d989c, Func Offset: 0xc
	// Line 2268, Address: 0x1d98ac, Func Offset: 0x1c
	// Line 2270, Address: 0x1d9918, Func Offset: 0x88
	// Line 2271, Address: 0x1d9928, Func Offset: 0x98
	// Line 2273, Address: 0x1d9930, Func Offset: 0xa0
	// Line 2274, Address: 0x1d9940, Func Offset: 0xb0
	// Line 2276, Address: 0x1d994c, Func Offset: 0xbc
	// Line 2279, Address: 0x1d9954, Func Offset: 0xc4
	// Line 2280, Address: 0x1d9964, Func Offset: 0xd4
	// Line 2282, Address: 0x1d9970, Func Offset: 0xe0
	// Line 2283, Address: 0x1d9980, Func Offset: 0xf0
	// Line 2285, Address: 0x1d998c, Func Offset: 0xfc
	// Line 2287, Address: 0x1d999c, Func Offset: 0x10c
	// Line 2288, Address: 0x1d99b0, Func Offset: 0x120
	// Line 2290, Address: 0x1d99c0, Func Offset: 0x130
	// Line 2292, Address: 0x1d99c8, Func Offset: 0x138
	// Line 2293, Address: 0x1d99d8, Func Offset: 0x148
	// Line 2295, Address: 0x1d99e0, Func Offset: 0x150
	// Line 2296, Address: 0x1d99f0, Func Offset: 0x160
	// Line 2298, Address: 0x1d9a04, Func Offset: 0x174
	// Line 2300, Address: 0x1d9a0c, Func Offset: 0x17c
	// Line 2301, Address: 0x1d9a1c, Func Offset: 0x18c
	// Line 2303, Address: 0x1d9a24, Func Offset: 0x194
	// Line 2304, Address: 0x1d9a34, Func Offset: 0x1a4
	// Line 2306, Address: 0x1d9a48, Func Offset: 0x1b8
	// Line 2308, Address: 0x1d9a50, Func Offset: 0x1c0
	// Line 2309, Address: 0x1d9a5c, Func Offset: 0x1cc
	// Line 2311, Address: 0x1d9a6c, Func Offset: 0x1dc
	// Line 2312, Address: 0x1d9a7c, Func Offset: 0x1ec
	// Line 2314, Address: 0x1d9a88, Func Offset: 0x1f8
	// Line 2316, Address: 0x1d9a90, Func Offset: 0x200
	// Line 2317, Address: 0x1d9a9c, Func Offset: 0x20c
	// Line 2319, Address: 0x1d9aac, Func Offset: 0x21c
	// Line 2320, Address: 0x1d9abc, Func Offset: 0x22c
	// Line 2322, Address: 0x1d9ac8, Func Offset: 0x238
	// Line 2323, Address: 0x1d9ad8, Func Offset: 0x248
	// Line 2325, Address: 0x1d9ae4, Func Offset: 0x254
	// Line 2327, Address: 0x1d9aec, Func Offset: 0x25c
	// Line 2328, Address: 0x1d9af8, Func Offset: 0x268
	// Line 2330, Address: 0x1d9b08, Func Offset: 0x278
	// Line 2331, Address: 0x1d9b18, Func Offset: 0x288
	// Line 2333, Address: 0x1d9b28, Func Offset: 0x298
	// Line 2334, Address: 0x1d9b38, Func Offset: 0x2a8
	// Line 2338, Address: 0x1d9b48, Func Offset: 0x2b8
	// Func End, Address: 0x1d9b58, Func Offset: 0x2c8
}

// 
// Start address: 0x1d9b60
void bhEne12_CallFootSE(BH_PWORK* epw, int flg)
{
	_anon25 pos;
	_anon13* hp;
	// Line 2349, Address: 0x1d9b60, Func Offset: 0
	// Line 2354, Address: 0x1d9b6c, Func Offset: 0xc
	// Line 2355, Address: 0x1d9b7c, Func Offset: 0x1c
	// Line 2358, Address: 0x1d9b84, Func Offset: 0x24
	// Line 2360, Address: 0x1d9b8c, Func Offset: 0x2c
	// Line 2361, Address: 0x1d9ba0, Func Offset: 0x40
	// Line 2363, Address: 0x1d9ba8, Func Offset: 0x48
	// Line 2366, Address: 0x1d9bbc, Func Offset: 0x5c
	// Line 2367, Address: 0x1d9bcc, Func Offset: 0x6c
	// Line 2369, Address: 0x1d9be4, Func Offset: 0x84
	// Line 2370, Address: 0x1d9bf8, Func Offset: 0x98
	// Line 2372, Address: 0x1d9c00, Func Offset: 0xa0
	// Line 2374, Address: 0x1d9c14, Func Offset: 0xb4
	// Func End, Address: 0x1d9c24, Func Offset: 0xc4
}

// 
// Start address: 0x1d9c30
void bhEne12_SetFireBintaEffect(BH_PWORK* epw, int act)
{
	float scale;
	_anon25 vec2;
	_anon25 vec;
	_anon25 ofp;
	_anon1* owk;
	int eno;
	int i;
	_anon24* efp;
	// Line 2385, Address: 0x1d9c30, Func Offset: 0
	// Line 2393, Address: 0x1d9c44, Func Offset: 0x14
	// Line 2385, Address: 0x1d9c48, Func Offset: 0x18
	// Line 2393, Address: 0x1d9c4c, Func Offset: 0x1c
	// Line 2395, Address: 0x1d9c7c, Func Offset: 0x4c
	// Line 2404, Address: 0x1d9c84, Func Offset: 0x54
	// Line 2395, Address: 0x1d9c88, Func Offset: 0x58
	// Line 2404, Address: 0x1d9c8c, Func Offset: 0x5c
	// Line 2395, Address: 0x1d9c90, Func Offset: 0x60
	// Line 2396, Address: 0x1d9c9c, Func Offset: 0x6c
	// Line 2404, Address: 0x1d9ca4, Func Offset: 0x74
	// Line 2396, Address: 0x1d9cac, Func Offset: 0x7c
	// Line 2397, Address: 0x1d9cb8, Func Offset: 0x88
	// Line 2398, Address: 0x1d9ccc, Func Offset: 0x9c
	// Line 2399, Address: 0x1d9ce0, Func Offset: 0xb0
	// Line 2400, Address: 0x1d9cf4, Func Offset: 0xc4
	// Line 2401, Address: 0x1d9d08, Func Offset: 0xd8
	// Line 2402, Address: 0x1d9d1c, Func Offset: 0xec
	// Line 2404, Address: 0x1d9d2c, Func Offset: 0xfc
	// Line 2405, Address: 0x1d9d34, Func Offset: 0x104
	// Line 2407, Address: 0x1d9d40, Func Offset: 0x110
	// Line 2405, Address: 0x1d9d48, Func Offset: 0x118
	// Line 2406, Address: 0x1d9d54, Func Offset: 0x124
	// Line 2407, Address: 0x1d9d6c, Func Offset: 0x13c
	// Line 2408, Address: 0x1d9d88, Func Offset: 0x158
	// Line 2409, Address: 0x1d9d94, Func Offset: 0x164
	// Line 2410, Address: 0x1d9dc0, Func Offset: 0x190
	// Line 2411, Address: 0x1d9dd4, Func Offset: 0x1a4
	// Line 2413, Address: 0x1d9dec, Func Offset: 0x1bc
	// Line 2414, Address: 0x1d9e04, Func Offset: 0x1d4
	// Line 2416, Address: 0x1d9e0c, Func Offset: 0x1dc
	// Line 2417, Address: 0x1d9e24, Func Offset: 0x1f4
	// Line 2418, Address: 0x1d9e38, Func Offset: 0x208
	// Line 2420, Address: 0x1d9e54, Func Offset: 0x224
	// Line 2423, Address: 0x1d9e5c, Func Offset: 0x22c
	// Line 2424, Address: 0x1d9e74, Func Offset: 0x244
	// Line 2426, Address: 0x1d9e7c, Func Offset: 0x24c
	// Line 2427, Address: 0x1d9e88, Func Offset: 0x258
	// Line 2435, Address: 0x1d9e8c, Func Offset: 0x25c
	// Line 2426, Address: 0x1d9e90, Func Offset: 0x260
	// Line 2427, Address: 0x1d9e9c, Func Offset: 0x26c
	// Line 2437, Address: 0x1d9ea4, Func Offset: 0x274
	// Line 2427, Address: 0x1d9ea8, Func Offset: 0x278
	// Line 2428, Address: 0x1d9eb4, Func Offset: 0x284
	// Line 2429, Address: 0x1d9ec8, Func Offset: 0x298
	// Line 2430, Address: 0x1d9edc, Func Offset: 0x2ac
	// Line 2433, Address: 0x1d9ef0, Func Offset: 0x2c0
	// Line 2437, Address: 0x1d9ef4, Func Offset: 0x2c4
	// Line 2433, Address: 0x1d9efc, Func Offset: 0x2cc
	// Line 2437, Address: 0x1d9f00, Func Offset: 0x2d0
	// Line 2433, Address: 0x1d9f0c, Func Offset: 0x2dc
	// Line 2434, Address: 0x1d9f10, Func Offset: 0x2e0
	// Line 2435, Address: 0x1d9f14, Func Offset: 0x2e4
	// Line 2437, Address: 0x1d9f18, Func Offset: 0x2e8
	// Line 2439, Address: 0x1d9f24, Func Offset: 0x2f4
	// Line 2440, Address: 0x1d9f38, Func Offset: 0x308
	// Line 2439, Address: 0x1d9f3c, Func Offset: 0x30c
	// Line 2441, Address: 0x1d9f4c, Func Offset: 0x31c
	// Line 2442, Address: 0x1d9f50, Func Offset: 0x320
	// Line 2439, Address: 0x1d9f54, Func Offset: 0x324
	// Line 2440, Address: 0x1d9f58, Func Offset: 0x328
	// Line 2439, Address: 0x1d9f60, Func Offset: 0x330
	// Line 2440, Address: 0x1d9f6c, Func Offset: 0x33c
	// Line 2441, Address: 0x1d9f78, Func Offset: 0x348
	// Line 2440, Address: 0x1d9f80, Func Offset: 0x350
	// Line 2441, Address: 0x1d9f90, Func Offset: 0x360
	// Line 2442, Address: 0x1d9fa8, Func Offset: 0x378
	// Line 2444, Address: 0x1d9fb0, Func Offset: 0x380
	// Line 2445, Address: 0x1d9fd8, Func Offset: 0x3a8
	// Line 2444, Address: 0x1d9fdc, Func Offset: 0x3ac
	// Line 2445, Address: 0x1d9fe0, Func Offset: 0x3b0
	// Line 2444, Address: 0x1d9fe4, Func Offset: 0x3b4
	// Line 2447, Address: 0x1d9fe8, Func Offset: 0x3b8
	// Line 2445, Address: 0x1d9ff4, Func Offset: 0x3c4
	// Line 2444, Address: 0x1d9ffc, Func Offset: 0x3cc
	// Line 2445, Address: 0x1da014, Func Offset: 0x3e4
	// Line 2446, Address: 0x1da018, Func Offset: 0x3e8
	// Line 2447, Address: 0x1da02c, Func Offset: 0x3fc
	// Line 2448, Address: 0x1da044, Func Offset: 0x414
	// Line 2449, Address: 0x1da050, Func Offset: 0x420
	// Line 2450, Address: 0x1da088, Func Offset: 0x458
	// Line 2451, Address: 0x1da09c, Func Offset: 0x46c
	// Line 2450, Address: 0x1da0a8, Func Offset: 0x478
	// Line 2451, Address: 0x1da0ac, Func Offset: 0x47c
	// Line 2454, Address: 0x1da0b8, Func Offset: 0x488
	// Line 2455, Address: 0x1da0d4, Func Offset: 0x4a4
	// Line 2456, Address: 0x1da0f4, Func Offset: 0x4c4
	// Line 2458, Address: 0x1da0fc, Func Offset: 0x4cc
	// Line 2455, Address: 0x1da100, Func Offset: 0x4d0
	// Line 2458, Address: 0x1da110, Func Offset: 0x4e0
	// Line 2456, Address: 0x1da114, Func Offset: 0x4e4
	// Line 2458, Address: 0x1da11c, Func Offset: 0x4ec
	// Line 2455, Address: 0x1da120, Func Offset: 0x4f0
	// Line 2456, Address: 0x1da128, Func Offset: 0x4f8
	// Line 2457, Address: 0x1da12c, Func Offset: 0x4fc
	// Line 2458, Address: 0x1da140, Func Offset: 0x510
	// Line 2459, Address: 0x1da158, Func Offset: 0x528
	// Line 2460, Address: 0x1da164, Func Offset: 0x534
	// Line 2461, Address: 0x1da19c, Func Offset: 0x56c
	// Line 2462, Address: 0x1da1b0, Func Offset: 0x580
	// Line 2461, Address: 0x1da1bc, Func Offset: 0x58c
	// Line 2462, Address: 0x1da1c0, Func Offset: 0x590
	// Line 2465, Address: 0x1da1cc, Func Offset: 0x59c
	// Line 2466, Address: 0x1da1e8, Func Offset: 0x5b8
	// Line 2467, Address: 0x1da208, Func Offset: 0x5d8
	// Line 2466, Address: 0x1da210, Func Offset: 0x5e0
	// Line 2469, Address: 0x1da224, Func Offset: 0x5f4
	// Line 2467, Address: 0x1da228, Func Offset: 0x5f8
	// Line 2469, Address: 0x1da230, Func Offset: 0x600
	// Line 2466, Address: 0x1da238, Func Offset: 0x608
	// Line 2467, Address: 0x1da248, Func Offset: 0x618
	// Line 2468, Address: 0x1da24c, Func Offset: 0x61c
	// Line 2469, Address: 0x1da260, Func Offset: 0x630
	// Line 2470, Address: 0x1da278, Func Offset: 0x648
	// Line 2471, Address: 0x1da284, Func Offset: 0x654
	// Line 2472, Address: 0x1da2bc, Func Offset: 0x68c
	// Line 2473, Address: 0x1da2d0, Func Offset: 0x6a0
	// Line 2472, Address: 0x1da2dc, Func Offset: 0x6ac
	// Line 2473, Address: 0x1da2e0, Func Offset: 0x6b0
	// Line 2475, Address: 0x1da2e8, Func Offset: 0x6b8
	// Line 2477, Address: 0x1da2f0, Func Offset: 0x6c0
	// Line 2479, Address: 0x1da2f4, Func Offset: 0x6c4
	// Line 2481, Address: 0x1da2f8, Func Offset: 0x6c8
	// Line 2477, Address: 0x1da2fc, Func Offset: 0x6cc
	// Line 2478, Address: 0x1da300, Func Offset: 0x6d0
	// Line 2479, Address: 0x1da304, Func Offset: 0x6d4
	// Line 2480, Address: 0x1da308, Func Offset: 0x6d8
	// Line 2481, Address: 0x1da30c, Func Offset: 0x6dc
	// Line 2477, Address: 0x1da310, Func Offset: 0x6e0
	// Line 2481, Address: 0x1da314, Func Offset: 0x6e4
	// Line 2483, Address: 0x1da320, Func Offset: 0x6f0
	// Func End, Address: 0x1da33c, Func Offset: 0x70c
}

