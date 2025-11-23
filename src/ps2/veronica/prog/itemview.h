#ifndef _ITEMVIEW_H_
#define _ITEMVIEW_H_

/*void DrawSubItem(_anon2* st, _anon5* si);*/
void Model_Read_Start();
/*void Model_Read_Set(_anon2* st);*/
void CameraInit();
void CameraSet();
void ItemView();
void ItemModelChangeZoomIn();
void ItemModelCheck();
void ItemModelActionSet();
void ItemModelChangeZoomOut();
void ItemModelMessageWait();
unsigned char MdlDirChk(short* dirang, short mdlang);
/*unsigned char MdlAction00(_anon5* si);
unsigned char MdlAction01(_anon5* si);
unsigned char MdlAction02(_anon5* si);*/
void MdlEvalflagsSet(unsigned short evalchk);
/*void MdlHideCheck(npobj* op, unsigned char el, unsigned char chk);
float ModelScaleSet(_anon5* itemmodel, unsigned short flg);
void FlagErase(npobj* op);*/
void LighterOpen(NJS_CNK_OBJECT* object);
void FileSyu(NJS_CNK_OBJECT* op);
void MakeTag(unsigned short flg);

/*typedef struct npobj;
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
};*/

#endif
