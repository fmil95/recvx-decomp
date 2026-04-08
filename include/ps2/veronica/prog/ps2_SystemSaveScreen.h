#ifndef _PS2_SYSTEMSAVESCREEN_H_
#define _PS2_SYSTEMSAVESCREEN_H_

#include "types.h"

typedef struct SYSSAVE_SCREEN 
{
    // total size: 0x3C
    unsigned int ulState;                // offset 0x0, size 0x4
    unsigned int ulSubState;             // offset 0x4, size 0x4
    unsigned int ulMemCheckCountTimer;   // offset 0x8, size 0x4
    unsigned int ulFileSize;             // offset 0xC, size 0x4
    int lCardState;                      // offset 0x10, size 0x4
    short sSelectCur;                    // offset 0x14, size 0x2
    unsigned short usExitFlag;           // offset 0x16, size 0x2
    unsigned short usMesMode;            // offset 0x18, size 0x2
    unsigned short usSaveMode;           // offset 0x1A, size 0x2
    unsigned short usLoopCount;          // offset 0x1C, size 0x2
    char cMesFlag;                       // offset 0x1E, size 0x1
    CONFIGFILE* pConfigFile;             // offset 0x20, size 0x4
    SAVEFILE* pSaveFile;                 // offset 0x24, size 0x4
    ICONINFORMATION* pIconInfo;          // offset 0x28, size 0x4
    MEMORYCARDSTATE* pMcState;           // offset 0x2C, size 0x4
    SELECTFILEINFO* pSelectFileInfo;     // offset 0x30, size 0x4
    SELECTFILEWINDOW* pSelectFileWindow; // offset 0x34, size 0x4
    void* vpReadBuffer;                  // offset 0x38, size 0x4
} SYSSAVE_SCREEN;

SYSSAVE_SCREEN* CreateSysSaveScreen(SYSSAVE_SCREEN* pSysSave, void* vpWorkPtrSys, unsigned short usSaveMesMode, unsigned short usSaveWriteMode);
int ExecuteSysSaveScreen(SYSSAVE_SCREEN* pSysSave);

/*typedef struct _anon0;
typedef struct npobj;
typedef struct tagSYSSAVE_SCREEN;
typedef struct _anon1;
typedef struct _anon2;
typedef struct tagICONINFORMATION;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;
typedef struct tagCONFIGFILE;
typedef struct _anon11;
typedef struct _anon12;
typedef struct _anon13;
typedef struct _anon14;
typedef struct _anon15;
typedef struct _anon16;
typedef struct BH_PWORK;
typedef struct _anon17;
typedef struct tagMEMORYCARDSTATE;
typedef struct _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct tagSELECTFILEINFO;
typedef struct _anon23;
typedef struct _anon24;
typedef struct _anon25;
typedef struct _anon26;
typedef struct _anon27;
typedef struct _anon28;
typedef struct _anon29;
typedef struct tagSELECTFILEWINDOW;
typedef struct tagMEMORYCARDPORT;
typedef struct _anon30;
typedef struct _anon31;
typedef struct tagSAVEFILE;
typedef struct _anon32;
typedef struct _anon33;
typedef struct _anon34;

typedef void(*type_88)(void*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef char type_2[4];
typedef unsigned char type_3[2];
typedef _anon1* type_4[16];
typedef short type_5[4];
typedef _anon0* type_6[512];
typedef _anon1* type_7[16][16];
typedef _anon1* type_8[16][16][100];
typedef char type_9[8];
typedef char type_10[32];
typedef unsigned char type_11[4];
typedef _anon0* type_12[512];
typedef char type_13[64];
typedef _anon1* type_14[1300];
typedef _anon0* type_15[512];
typedef _anon1* type_16[200];
typedef _anon0* type_17[128];
typedef unsigned int type_18[1];
typedef _anon1* type_19[8];
typedef int* type_20[16];
typedef _anon0* type_21[128];
typedef char type_22[32];
typedef npobj* type_23[16];
typedef short type_24[32];
typedef _anon0* type_25[128];
typedef _anon1* type_26[16];
typedef _anon8 type_27[16];
typedef _anon0* type_28[512];
typedef unsigned int type_29[4];
typedef _anon0* type_30[32];
typedef _anon3* type_31[128];
typedef char type_32[256];
typedef _anon0* type_33[32];
typedef unsigned char type_34[64];
typedef float type_35[4];
typedef float type_36[16];
typedef float type_37[4];
typedef _anon0* type_38[32];
typedef tagSELECTFILEINFO type_39[15];
typedef float type_40[4];
typedef char type_41[8];
typedef _anon27 type_42[1];
typedef _anon25 type_43[256];
typedef int type_44[4];
typedef _anon1* type_45[256];
typedef int type_46[4];
typedef float type_47[3];
typedef unsigned char* type_48[256];
typedef int type_49[3];
typedef float type_50[3];
typedef float type_51[4];
typedef short type_52[256];
typedef unsigned char type_53[4];
typedef int type_54[4];
typedef short type_55[256];
typedef int type_56[8];
typedef unsigned int type_57[3];
typedef _anon1* type_58[256];
typedef _anon6 type_59[256];
typedef unsigned char type_60[10956];
typedef int type_61[4][4];
typedef float type_62[4][3];
typedef _anon27 type_63[450];
typedef float type_64[4][3];
typedef short type_65[256];
typedef unsigned char type_66[68];
typedef _anon14 type_67[0];
typedef int type_68[64];
typedef _anon8 type_69[450];
typedef unsigned char type_70[64];
typedef unsigned char type_71[64];
typedef char type_72[50];
typedef _anon21 type_73[4];
typedef unsigned char type_74[64];
typedef char type_75[3];
typedef char type_76[32];
typedef _anon23 type_77[4];
typedef int type_78[450];
typedef unsigned char type_79[512];
typedef unsigned int type_80[8];
typedef unsigned char type_81[450];
typedef _anon17 type_82[4];
typedef int type_83[8];
typedef tagMEMORYCARDPORT type_84[2];
typedef void* type_85[2];
typedef char type_86[16];
typedef char type_87[4];
typedef unsigned int type_89[32];
typedef _anon31 type_90[16];
typedef unsigned int type_91[16];
typedef unsigned int type_92[2];
typedef unsigned int type_93[16];
typedef unsigned int type_94[32];
typedef unsigned int type_95[16];
typedef BH_PWORK* type_96[16];
typedef unsigned int type_97[8];
typedef unsigned int type_98[1];
typedef unsigned int type_99[384];
typedef unsigned int type_100[2];
typedef int* type_101[16];
typedef unsigned int type_102[4];
typedef npobj* type_103[16];
typedef _anon1* type_104[16];
typedef char type_105[4];
typedef _anon8 type_106[16];
typedef short type_107[4];
typedef unsigned char type_108[4];
typedef _anon20 type_109[16];
typedef _anon33 type_110[64];
typedef unsigned int type_111[32];
typedef _anon0* type_112[512];
typedef unsigned int type_113[16];
typedef _anon33 type_114[64];
typedef unsigned int type_115[16];
typedef unsigned int type_116[32];
typedef _anon0* type_117[128];
typedef unsigned int type_118[32];
typedef _anon33 type_119[64];
typedef unsigned int type_120[3];
typedef _anon32 type_121[32];
typedef unsigned int type_122[16];
typedef _anon0* type_123[512];
typedef unsigned int type_124[8];
typedef unsigned int type_125[3];
typedef unsigned char type_126[64];
typedef unsigned int type_127[384];
typedef _anon0* type_128[512];
typedef unsigned int type_129[4];

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
	_anon4 cspr;
	int pn;
	_anon21* pvp;
	_anon23* tvp;
	_anon21 pv[4];
	_anon23 tv[4];
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

struct npobj
{
	unsigned int evalflags;
	_anon15* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct tagSYSSAVE_SCREEN
{
	unsigned int ulState;
	unsigned int ulSubState;
	unsigned int ulMemCheckCountTimer;
	unsigned int ulFileSize;
	int lCardState;
	short sSelectCur;
	unsigned short usExitFlag;
	unsigned short usMesMode;
	unsigned short usSaveMode;
	unsigned short usLoopCount;
	char cMesFlag;
	tagCONFIGFILE* pConfigFile;
	tagSAVEFILE* pSaveFile;
	tagICONINFORMATION* pIconInfo;
	tagMEMORYCARDSTATE* pMcState;
	tagSELECTFILEINFO* pSelectFileInfo;
	tagSELECTFILEWINDOW* pSelectFileWindow;
	void* vpReadBuffer;
};

struct _anon1
{
	_anon27* textures;
	unsigned int nbTexture;
};

struct _anon2
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
	_anon28 atten;
	_anon28 amb;
	_anon28 dif;
	_anon28 spc;
	_anon28 mamb;
	_anon28 mdif;
	_anon28 mspc;
};

struct tagICONINFORMATION
{
	_anon18 icon;
};

struct _anon3
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon29* md2P;
	unsigned short* atrP;
};

struct _anon4
{
	_anon32 c;
	float r;
};

struct _anon5
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
	_anon10* info;
};

struct _anon6
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon7
{
	_anon32 c1;
	_anon32 c2;
	float r;
};

struct _anon8
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon30* owP;
};

struct _anon9
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

struct _anon10
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

struct tagCONFIGFILE
{
	unsigned int ssd_ver;
	unsigned int ssd_flg;
	unsigned int ssd_reserve;
	char keytype;
	char adjust_x;
	char adjust_y;
	char vibration;
	int best_tm[8];
	unsigned int Check_Sam;
};

struct _anon11
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
	_anon28 argb;
};

struct _anon12
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon13
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
	_anon1* et_lp[16][16][100];
	_anon1* ot_lp[1300];
	_anon1* it_lp[200];
	int eft_n;
	_anon1* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon5* p1per;
	_anon5* p2per;
	_anon5* kbper;
	_anon5* msper;
	_anon5 ms_per;
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
	_anon6 txbp[256];
	unsigned char* ef_psp;
	_anon27 ef_tex[450];
	_anon1 ef_tlist;
	_anon26 ef;
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
	_anon24 ren_info;
	_anon27 ren_tex[1];
	_anon1 ren_tlist;
	_anon25 rpb[256];
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
	_anon34 mr_pl;
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
	_anon17 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon31 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon33* pl_htp;
	int costume;
	_anon32 hd_pos;
	_anon32 apos;
	_anon33* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon33 mwalp[64];
	_anon33 metcp[64];
	_anon33 mflrp[64];
	int dla_n;
	_anon33* htp;
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
	_anon9 door;
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
	_anon20 gatc[16];
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

struct _anon14
{
	int PerType;
	int OldPerType;
	int PerTypeEx;
	unsigned int Flag;
	int SoftReset;
	unsigned int on;
	unsigned int press;
	unsigned int Rept;
	unsigned int on2;
	unsigned int on2old;
	unsigned int press2;
	unsigned short l;
	unsigned short r;
	short x1;
	short y1;
	short x2;
	short y2;
	short Calibrate;
};

struct _anon15
{
	int* vlist;
	short* plist;
	_anon32 center;
	float r;
};

struct _anon16
{
	float mtrx[16];
	_anon32 pnt;
	_anon32 vctr;
	int stat;
	int reserve;
	_anon2 ltcal;
	_anon11 attr;
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
	_anon7 watr;
	_anon12* cpcl;
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

struct _anon17
{
	_anon32 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct tagMEMORYCARDSTATE
{
	unsigned int ulState;
	unsigned int ulError;
	unsigned int ulMcSubState;
	unsigned int ulFileSize;
	int lCurrentPort;
	int lOpenFileNumber;
	int lSelectFileNumber;
	int lOpenMode;
	unsigned short usMcSysState;
	void* vpAddr;
	char cCurrentDir[50];
	char cOpenFileName[32];
	char cRetryCount;
	char cMcCheckFlag;
	char cCheckMcFlag;
	tagMEMORYCARDPORT Port[2];
};

struct _anon18
{
	unsigned char Head[4];
	unsigned short Reserv1;
	unsigned short OffsLF;
	unsigned int Reserv2;
	unsigned int TransRate;
	int BgColor[4][4];
	float LightDir[4][3];
	float LightColor[4][3];
	float Ambient[4];
	unsigned char TitleName[68];
	unsigned char FnameView[64];
	unsigned char FnameCopy[64];
	unsigned char FnameDel[64];
	unsigned char Reserve3[512];
};

struct _anon19
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

struct _anon20
{
	_anon32 c1;
	_anon32 c2;
	float r1;
	float r2;
};

struct _anon21
{
	float x;
	float y;
	float z;
	unsigned int col;
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
	_anon16* light;
};

struct tagSELECTFILEINFO
{
	int FileNumber;
	int save_ct;
	int gm_mode;
	char ply_id;
	char saveroom;
};

struct _anon23
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon24
{
	void* texaddr;
	_anon19 texsurface;
};

struct _anon25
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon26
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

struct _anon27
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon28
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon29
{
	void* p[2];
};

struct tagSELECTFILEWINDOW
{
	unsigned int ulFileState;
	tagSELECTFILEINFO* pRecordTop;
	int lRecordMax;
	short slDispTopNumber;
	short slDispRecordNumber;
	short sMesCur;
	short sCursol;
	short sWaitMesTimer;
	float slLineNumber;
	int slDispWriteMesMax;
	int slDispWriteMes;
	unsigned int ulfoundationColor;
};

struct tagMEMORYCARDPORT
{
	int lCrntType;
	int lPrevType;
	int lFreeSize;
	int lFormatType;
};

struct _anon30
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon31
{
	float x;
	float y;
};

struct tagSAVEFILE
{
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
	unsigned int CheckSam;
};

struct _anon32
{
	float x;
	float y;
	float z;
};

struct _anon33
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

struct _anon34
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

tagSELECTFILEWINDOW SelectFileWindow;
tagSELECTFILEINFO SelectFileInfo[15];
char* cpNameList;
tagICONINFORMATION IconInfo;
tagMEMORYCARDSTATE McState;
tagSAVEFILE SaveFile;
tagCONFIGFILE ConfigFile;
unsigned char SaveLoadMessage[10956];
_anon14 Pad[0];
_anon13* sys;*/

#endif
