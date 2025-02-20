typedef struct _anon0;
typedef struct tagLOAD_SCREEN;
typedef struct npobj;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct tagSELECTFILEWINDOW;
typedef struct tagMEMORYCARDPORT;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct tagSELECTFILEINFO;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;
typedef struct _anon11;
typedef struct tagCONFIGFILE;
typedef struct tagSAVEFILE;
typedef struct tagICONINFORMATION;
typedef struct tagMEMORYCARDSTATE;
typedef struct _anon12;
typedef struct _anon13;
typedef struct _anon14;
typedef struct _anon15;
typedef struct BH_PWORK;
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

typedef void(*type_92)(void*);

typedef unsigned char type_0[2];
typedef unsigned int type_1[4];
typedef _anon0* type_2[512];
typedef char type_3[32];
typedef char type_4[32];
typedef _anon2* type_5[16];
typedef _anon0* type_6[512];
typedef _anon2* type_7[16][16];
typedef _anon2* type_8[16][16][100];
typedef char type_9[8];
typedef char type_10[64];
typedef _anon0* type_11[512];
typedef _anon2* type_12[1300];
typedef int type_13[8];
typedef tagMEMORYCARDPORT type_14[2];
typedef _anon0* type_15[512];
typedef _anon2* type_16[200];
typedef _anon0* type_17[128];
typedef unsigned int type_18[1];
typedef tagSELECTFILEINFO type_19[15];
typedef char type_20[32];
typedef _anon2* type_21[8];
typedef int* type_22[16];
typedef _anon0* type_23[128];
typedef short type_24[32];
typedef npobj* type_25[16];
typedef _anon0* type_26[128];
typedef _anon2* type_27[16];
typedef _anon8 type_28[16];
typedef _anon0* type_29[512];
typedef unsigned int type_30[4];
typedef _anon0* type_31[32];
typedef _anon3* type_32[128];
typedef char type_33[256];
typedef _anon0* type_34[32];
typedef unsigned char type_35[64];
typedef float type_36[4];
typedef float type_37[16];
typedef float type_38[4];
typedef _anon0* type_39[32];
typedef float type_40[4];
typedef char type_41[8];
typedef _anon26 type_42[1];
typedef _anon24 type_43[256];
typedef int type_44[4];
typedef _anon2* type_45[256];
typedef float type_46[3];
typedef int type_47[4];
typedef unsigned int type_48[32];
typedef unsigned char* type_49[256];
typedef int type_50[3];
typedef unsigned int type_51[16];
typedef float type_52[3];
typedef float type_53[4];
typedef short type_54[256];
typedef unsigned int type_55[16];
typedef unsigned int type_56[32];
typedef unsigned int type_57[16];
typedef unsigned char type_58[4];
typedef int type_59[4];
typedef unsigned int type_60[8];
typedef short type_61[256];
typedef unsigned int type_62[384];
typedef int type_63[8];
typedef unsigned int type_64[4];
typedef _anon2* type_65[256];
typedef char type_66[4];
typedef _anon7 type_67[256];
typedef short type_68[4];
typedef int type_69[4][4];
typedef unsigned char type_70[4];
typedef float type_71[4][3];
typedef _anon26 type_72[450];
typedef float type_73[4][3];
typedef short type_74[256];
typedef unsigned char type_75[68];
typedef int type_76[64];
typedef _anon8 type_77[450];
typedef unsigned char type_78[64];
typedef unsigned char type_79[64];
typedef char type_80[3];
typedef _anon20 type_81[4];
typedef unsigned char type_82[64];
typedef _anon22 type_83[4];
typedef int type_84[450];
typedef unsigned char type_85[512];
typedef unsigned int type_86[8];
typedef unsigned char type_87[450];
typedef _anon16 type_88[4];
typedef void* type_89[2];
typedef char type_90[16];
typedef char type_91[4];
typedef unsigned int type_93[32];
typedef _anon30 type_94[16];
typedef unsigned int type_95[16];
typedef unsigned int type_96[2];
typedef unsigned int type_97[16];
typedef unsigned int type_98[32];
typedef unsigned int type_99[16];
typedef BH_PWORK* type_100[16];
typedef unsigned int type_101[8];
typedef unsigned int type_102[1];
typedef unsigned int type_103[384];
typedef unsigned int type_104[2];
typedef int* type_105[16];
typedef unsigned int type_106[4];
typedef npobj* type_107[16];
typedef _anon2* type_108[16];
typedef char type_109[4];
typedef _anon8 type_110[16];
typedef short type_111[4];
typedef unsigned char type_112[4];
typedef _anon19 type_113[16];
typedef _anon32 type_114[64];
typedef _anon0* type_115[512];
typedef _anon32 type_116[64];
typedef unsigned int type_117[32];
typedef _anon0* type_118[128];
typedef _anon32 type_119[64];
typedef _anon31 type_120[32];
typedef unsigned int type_121[3];
typedef _anon0* type_122[512];
typedef unsigned char type_123[64];
typedef _anon0* type_124[512];
typedef char type_125[50];

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
	_anon5 cspr;
	int pn;
	_anon20* pvp;
	_anon22* tvp;
	_anon20 pv[4];
	_anon22 tv[4];
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

struct tagLOAD_SCREEN
{
	unsigned int ulState;
	unsigned int ulSubState;
	unsigned int ulMemCheckCountTimer;
	unsigned int ulFileSize;
	int lCardState;
	short sCursorX;
	short sCursorY;
	short sSelectCur;
	unsigned short usExitFlag;
	unsigned short usSaveEnd;
	unsigned short usLoopCount;
	char cMesFlag;
	char cCgFlag;
	tagCONFIGFILE* pConfigFile;
	tagSAVEFILE* pSaveFile;
	tagICONINFORMATION* pIconInfo;
	tagMEMORYCARDSTATE* pMcState;
	tagSELECTFILEINFO* pSelectFileInfo;
	tagSELECTFILEWINDOW* pSelectFileWindow;
};

struct npobj
{
	unsigned int evalflags;
	_anon14* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon1
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
	_anon31 lpnt;
	_anon31 lvctr;
	_anon31 lmvctr;
	_anon27 atten;
	_anon27 amb;
	_anon27 dif;
	_anon27 spc;
	_anon27 mamb;
	_anon27 mdif;
	_anon27 mspc;
};

struct _anon2
{
	_anon26* textures;
	unsigned int nbTexture;
};

struct _anon3
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon28* md2P;
	unsigned short* atrP;
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

struct _anon4
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

struct _anon5
{
	_anon31 c;
	float r;
};

struct _anon6
{
	_anon31 c1;
	_anon31 c2;
	float r;
};

struct _anon7
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct tagSELECTFILEINFO
{
	int FileNumber;
	int save_ct;
	int gm_mode;
	char ply_id;
	char saveroom;
};

struct _anon8
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon2* texP;
	_anon29* owP;
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

struct _anon11
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
	_anon31 ply_pos;
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
	_anon4* p1per;
	_anon4* p2per;
	_anon4* kbper;
	_anon4* msper;
	_anon4 ms_per;
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
	_anon2* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon2* txblp[256];
	_anon7 txbp[256];
	unsigned char* ef_psp;
	_anon26 ef_tex[450];
	_anon2 ef_tlist;
	_anon25 ef;
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
	_anon23 ren_info;
	_anon26 ren_tex[1];
	_anon2 ren_tlist;
	_anon24 rpb[256];
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
	_anon33 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon21* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon16 lg_ptb[4];
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
	_anon32* pl_htp;
	int costume;
	_anon31 hd_pos;
	_anon31 apos;
	_anon32* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon32 mwalp[64];
	_anon32 metcp[64];
	_anon32 mflrp[64];
	int dla_n;
	_anon32* htp;
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
	_anon31 ufo_pos;
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
	_anon19 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon31 ghtp[32];
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
	_anon31 ply_pos;
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

struct tagICONINFORMATION
{
	_anon17 icon;
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

struct _anon12
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

struct _anon13
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon14
{
	int* vlist;
	short* plist;
	_anon31 center;
	float r;
};

struct _anon15
{
	float mtrx[16];
	_anon31 pnt;
	_anon31 vctr;
	int stat;
	int reserve;
	_anon1 ltcal;
	_anon12 attr;
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
	_anon6 watr;
	_anon13* cpcl;
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

struct _anon16
{
	_anon31 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon17
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

struct _anon18
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

struct _anon19
{
	_anon31 c1;
	_anon31 c2;
	float r1;
	float r2;
};

struct _anon20
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon21
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
	_anon15* light;
};

struct _anon22
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon23
{
	void* texaddr;
	_anon18 texsurface;
};

struct _anon24
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
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
};

struct _anon26
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
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
	void* p[2];
};

struct _anon29
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon30
{
	float x;
	float y;
};

struct _anon31
{
	float x;
	float y;
	float z;
};

struct _anon32
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

struct _anon33
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
_anon11* sys;

tagLOAD_SCREEN* CreateLoadScreen(tagLOAD_SCREEN* pLoad);
void DispLoadMessageSelect(char cSelectMes);
void DispLoadTexture(tagLOAD_SCREEN* pLoad);
int ExecuteLoadScreen(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenAwarenessCard(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenAwarenessCard(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenErrLostCard(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrLostCard(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenErrUnPS2MemCard(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrUnPS2MemCard(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenSelectCard(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenSelectCard(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenTitleExit(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenTitleExit(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenErrUnFormat(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrUnFormat(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenErrLostDirCheck(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrLostDirCheck(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenDirCheck(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenDirCheck(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenDirFileBroken(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenDirFileBroken(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenSelectFile(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenSelectFile(tagLOAD_SCREEN* pLoad);
void LoadScreenCheckSave(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenNoSave(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenNoSave(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenLoadCursor(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenLoadCursor(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenLoad(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenLoad(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenFileBroken(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenFileBroken(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenErrCardRead(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenErrCardRead(tagLOAD_SCREEN* pLoad);
void SetStateLoadScreenLoadExit(tagLOAD_SCREEN* pLoad);
void ExecuteStateLoadScreenLoadExit(tagLOAD_SCREEN* pLoad);
void SetDispLoadSelectMessage();
void CheckDispLoadMemoryCard(tagLOAD_SCREEN* pLoad);

// 
// Start address: 0x275340
tagLOAD_SCREEN* CreateLoadScreen(tagLOAD_SCREEN* pLoad)
{
	// Line 62, Address: 0x275340, Func Offset: 0
	// Line 63, Address: 0x27534c, Func Offset: 0xc
	// Line 64, Address: 0x275350, Func Offset: 0x10
	// Line 65, Address: 0x275354, Func Offset: 0x14
	// Line 66, Address: 0x275358, Func Offset: 0x18
	// Line 67, Address: 0x27535c, Func Offset: 0x1c
	// Line 68, Address: 0x275360, Func Offset: 0x20
	// Line 69, Address: 0x275364, Func Offset: 0x24
	// Line 70, Address: 0x275368, Func Offset: 0x28
	// Line 71, Address: 0x27536c, Func Offset: 0x2c
	// Line 72, Address: 0x275370, Func Offset: 0x30
	// Line 73, Address: 0x275374, Func Offset: 0x34
	// Line 74, Address: 0x275378, Func Offset: 0x38
	// Line 75, Address: 0x27537c, Func Offset: 0x3c
	// Line 76, Address: 0x275384, Func Offset: 0x44
	// Line 77, Address: 0x275394, Func Offset: 0x54
	// Line 78, Address: 0x2753a4, Func Offset: 0x64
	// Line 79, Address: 0x2753b4, Func Offset: 0x74
	// Line 80, Address: 0x2753d0, Func Offset: 0x90
	// Line 81, Address: 0x2753e0, Func Offset: 0xa0
	// Line 84, Address: 0x2753f8, Func Offset: 0xb8
	// Line 86, Address: 0x275400, Func Offset: 0xc0
	// Line 87, Address: 0x275404, Func Offset: 0xc4
	// Func End, Address: 0x275414, Func Offset: 0xd4
}

// 
// Start address: 0x275420
void DispLoadMessageSelect(char cSelectMes)
{
	// Line 168, Address: 0x275420, Func Offset: 0
	// Line 102, Address: 0x27542c, Func Offset: 0xc
	// Line 168, Address: 0x275430, Func Offset: 0x10
	// Line 102, Address: 0x275434, Func Offset: 0x14
	// Line 168, Address: 0x275438, Func Offset: 0x18
	// Line 102, Address: 0x27543c, Func Offset: 0x1c
	// Line 168, Address: 0x275440, Func Offset: 0x20
	// Line 170, Address: 0x27544c, Func Offset: 0x2c
	// Line 174, Address: 0x27547c, Func Offset: 0x5c
	// Line 175, Address: 0x275484, Func Offset: 0x64
	// Line 179, Address: 0x27548c, Func Offset: 0x6c
	// Line 181, Address: 0x2754b8, Func Offset: 0x98
	// Line 182, Address: 0x2754c0, Func Offset: 0xa0
	// Line 185, Address: 0x2754c8, Func Offset: 0xa8
	// Line 186, Address: 0x2754f4, Func Offset: 0xd4
	// Line 189, Address: 0x2754fc, Func Offset: 0xdc
	// Line 190, Address: 0x275528, Func Offset: 0x108
	// Line 196, Address: 0x275530, Func Offset: 0x110
	// Line 197, Address: 0x275560, Func Offset: 0x140
	// Line 200, Address: 0x275568, Func Offset: 0x148
	// Line 201, Address: 0x275598, Func Offset: 0x178
	// Line 202, Address: 0x2755c4, Func Offset: 0x1a4
	// Line 205, Address: 0x2755cc, Func Offset: 0x1ac
	// Line 206, Address: 0x2755fc, Func Offset: 0x1dc
	// Line 209, Address: 0x275604, Func Offset: 0x1e4
	// Line 210, Address: 0x275630, Func Offset: 0x210
	// Line 213, Address: 0x275638, Func Offset: 0x218
	// Line 214, Address: 0x275664, Func Offset: 0x244
	// Line 217, Address: 0x27566c, Func Offset: 0x24c
	// Line 224, Address: 0x275698, Func Offset: 0x278
	// Line 226, Address: 0x2756b0, Func Offset: 0x290
	// Func End, Address: 0x2756c0, Func Offset: 0x2a0
}

// 
// Start address: 0x2756c0
void DispLoadTexture(tagLOAD_SCREEN* pLoad)
{
	int DispLoadPortCard;
	// Line 241, Address: 0x2756c0, Func Offset: 0
	// Line 244, Address: 0x2756cc, Func Offset: 0xc
	// Line 248, Address: 0x2756f8, Func Offset: 0x38
	// Line 249, Address: 0x275700, Func Offset: 0x40
	// Line 251, Address: 0x275708, Func Offset: 0x48
	// Line 252, Address: 0x275710, Func Offset: 0x50
	// Line 253, Address: 0x27572c, Func Offset: 0x6c
	// Line 255, Address: 0x275734, Func Offset: 0x74
	// Line 256, Address: 0x27573c, Func Offset: 0x7c
	// Line 260, Address: 0x275758, Func Offset: 0x98
	// Line 267, Address: 0x275774, Func Offset: 0xb4
	// Func End, Address: 0x275784, Func Offset: 0xc4
}

// 
// Start address: 0x275790
int ExecuteLoadScreen(tagLOAD_SCREEN* pLoad)
{
	// Line 282, Address: 0x275790, Func Offset: 0
	// Line 284, Address: 0x2757a0, Func Offset: 0x10
	// Line 286, Address: 0x2757a8, Func Offset: 0x18
	// Line 288, Address: 0x2757b0, Func Offset: 0x20
	// Line 291, Address: 0x275878, Func Offset: 0xe8
	// Line 292, Address: 0x275884, Func Offset: 0xf4
	// Line 294, Address: 0x27588c, Func Offset: 0xfc
	// Line 295, Address: 0x275898, Func Offset: 0x108
	// Line 297, Address: 0x2758a0, Func Offset: 0x110
	// Line 298, Address: 0x2758ac, Func Offset: 0x11c
	// Line 300, Address: 0x2758b4, Func Offset: 0x124
	// Line 301, Address: 0x2758c0, Func Offset: 0x130
	// Line 303, Address: 0x2758c8, Func Offset: 0x138
	// Line 304, Address: 0x2758d4, Func Offset: 0x144
	// Line 306, Address: 0x2758dc, Func Offset: 0x14c
	// Line 307, Address: 0x2758e8, Func Offset: 0x158
	// Line 309, Address: 0x2758f0, Func Offset: 0x160
	// Line 310, Address: 0x2758fc, Func Offset: 0x16c
	// Line 312, Address: 0x275904, Func Offset: 0x174
	// Line 313, Address: 0x275910, Func Offset: 0x180
	// Line 315, Address: 0x275918, Func Offset: 0x188
	// Line 316, Address: 0x275924, Func Offset: 0x194
	// Line 318, Address: 0x27592c, Func Offset: 0x19c
	// Line 319, Address: 0x275938, Func Offset: 0x1a8
	// Line 321, Address: 0x275940, Func Offset: 0x1b0
	// Line 322, Address: 0x27594c, Func Offset: 0x1bc
	// Line 324, Address: 0x275954, Func Offset: 0x1c4
	// Line 325, Address: 0x275960, Func Offset: 0x1d0
	// Line 327, Address: 0x275968, Func Offset: 0x1d8
	// Line 328, Address: 0x275974, Func Offset: 0x1e4
	// Line 330, Address: 0x27597c, Func Offset: 0x1ec
	// Line 331, Address: 0x275988, Func Offset: 0x1f8
	// Line 333, Address: 0x275990, Func Offset: 0x200
	// Line 334, Address: 0x27599c, Func Offset: 0x20c
	// Line 336, Address: 0x2759a4, Func Offset: 0x214
	// Line 341, Address: 0x2759b0, Func Offset: 0x220
	// Line 343, Address: 0x2759bc, Func Offset: 0x22c
	// Line 346, Address: 0x2759c4, Func Offset: 0x234
	// Line 345, Address: 0x2759cc, Func Offset: 0x23c
	// Line 346, Address: 0x2759d0, Func Offset: 0x240
	// Func End, Address: 0x2759d8, Func Offset: 0x248
}

// 
// Start address: 0x2759e0
void SetStateLoadScreenAwarenessCard(tagLOAD_SCREEN* pLoad)
{
	// Line 364, Address: 0x2759e0, Func Offset: 0
	// Line 366, Address: 0x2759e4, Func Offset: 0x4
	// Line 368, Address: 0x2759e8, Func Offset: 0x8
	// Line 370, Address: 0x2759ec, Func Offset: 0xc
	// Func End, Address: 0x2759f8, Func Offset: 0x18
}

// 
// Start address: 0x275a00
void ExecuteStateLoadScreenAwarenessCard(tagLOAD_SCREEN* pLoad)
{
	int lPort1State;
	int lPort0State;
	// Line 386, Address: 0x275a00, Func Offset: 0
	// Line 389, Address: 0x275a10, Func Offset: 0x10
	// Line 393, Address: 0x275a4c, Func Offset: 0x4c
	// Line 395, Address: 0x275a58, Func Offset: 0x58
	// Line 397, Address: 0x275a68, Func Offset: 0x68
	// Line 400, Address: 0x275a7c, Func Offset: 0x7c
	// Line 401, Address: 0x275a88, Func Offset: 0x88
	// Line 403, Address: 0x275a90, Func Offset: 0x90
	// Line 407, Address: 0x275ab4, Func Offset: 0xb4
	// Line 408, Address: 0x275ac0, Func Offset: 0xc0
	// Line 413, Address: 0x275ac8, Func Offset: 0xc8
	// Line 415, Address: 0x275ad4, Func Offset: 0xd4
	// Line 418, Address: 0x275adc, Func Offset: 0xdc
	// Line 419, Address: 0x275ae4, Func Offset: 0xe4
	// Line 422, Address: 0x275aec, Func Offset: 0xec
	// Line 423, Address: 0x275af4, Func Offset: 0xf4
	// Line 426, Address: 0x275afc, Func Offset: 0xfc
	// Line 429, Address: 0x275b04, Func Offset: 0x104
	// Func End, Address: 0x275b18, Func Offset: 0x118
}

// 
// Start address: 0x275b20
void SetStateLoadScreenErrLostCard(tagLOAD_SCREEN* pLoad)
{
	// Line 446, Address: 0x275b20, Func Offset: 0
	// Line 448, Address: 0x275b28, Func Offset: 0x8
	// Line 451, Address: 0x275b2c, Func Offset: 0xc
	// Func End, Address: 0x275b34, Func Offset: 0x14
}

// 
// Start address: 0x275b40
void ExecuteStateLoadScreenErrLostCard(tagLOAD_SCREEN* pLoad)
{
	int lPort1State;
	int lPort0State;
	// Line 466, Address: 0x275b40, Func Offset: 0
	// Line 470, Address: 0x275b50, Func Offset: 0x10
	// Line 473, Address: 0x275b70, Func Offset: 0x30
	// Line 475, Address: 0x275b78, Func Offset: 0x38
	// Line 476, Address: 0x275b84, Func Offset: 0x44
	// Line 480, Address: 0x275b8c, Func Offset: 0x4c
	// Line 484, Address: 0x275bbc, Func Offset: 0x7c
	// Line 486, Address: 0x275bc8, Func Offset: 0x88
	// Line 488, Address: 0x275bd8, Func Offset: 0x98
	// Line 491, Address: 0x275bec, Func Offset: 0xac
	// Line 492, Address: 0x275bf8, Func Offset: 0xb8
	// Line 494, Address: 0x275c00, Func Offset: 0xc0
	// Line 498, Address: 0x275c24, Func Offset: 0xe4
	// Line 500, Address: 0x275c30, Func Offset: 0xf0
	// Line 503, Address: 0x275c38, Func Offset: 0xf8
	// Line 504, Address: 0x275c40, Func Offset: 0x100
	// Line 507, Address: 0x275c48, Func Offset: 0x108
	// Line 511, Address: 0x275c50, Func Offset: 0x110
	// Func End, Address: 0x275c64, Func Offset: 0x124
}

// 
// Start address: 0x275c70
void SetStateLoadScreenErrUnPS2MemCard(tagLOAD_SCREEN* pLoad)
{
	// Line 528, Address: 0x275c70, Func Offset: 0
	// Line 530, Address: 0x275c78, Func Offset: 0x8
	// Line 533, Address: 0x275c7c, Func Offset: 0xc
	// Func End, Address: 0x275c84, Func Offset: 0x14
}

// 
// Start address: 0x275c90
void ExecuteStateLoadScreenErrUnPS2MemCard(tagLOAD_SCREEN* pLoad)
{
	int lPort1State;
	int lPort0State;
	// Line 548, Address: 0x275c90, Func Offset: 0
	// Line 552, Address: 0x275ca0, Func Offset: 0x10
	// Line 555, Address: 0x275cc0, Func Offset: 0x30
	// Line 557, Address: 0x275cc8, Func Offset: 0x38
	// Line 558, Address: 0x275cd4, Func Offset: 0x44
	// Line 562, Address: 0x275cdc, Func Offset: 0x4c
	// Line 566, Address: 0x275d0c, Func Offset: 0x7c
	// Line 568, Address: 0x275d18, Func Offset: 0x88
	// Line 570, Address: 0x275d28, Func Offset: 0x98
	// Line 573, Address: 0x275d3c, Func Offset: 0xac
	// Line 574, Address: 0x275d48, Func Offset: 0xb8
	// Line 575, Address: 0x275d50, Func Offset: 0xc0
	// Line 578, Address: 0x275d60, Func Offset: 0xd0
	// Line 580, Address: 0x275d68, Func Offset: 0xd8
	// Line 583, Address: 0x275d70, Func Offset: 0xe0
	// Line 584, Address: 0x275d78, Func Offset: 0xe8
	// Line 587, Address: 0x275d80, Func Offset: 0xf0
	// Line 591, Address: 0x275d88, Func Offset: 0xf8
	// Func End, Address: 0x275d9c, Func Offset: 0x10c
}

// 
// Start address: 0x275da0
void SetStateLoadScreenSelectCard(tagLOAD_SCREEN* pLoad)
{
	// Line 606, Address: 0x275da0, Func Offset: 0
	// Line 608, Address: 0x275dac, Func Offset: 0xc
	// Line 610, Address: 0x275db4, Func Offset: 0x14
	// Line 612, Address: 0x275db8, Func Offset: 0x18
	// Line 614, Address: 0x275dbc, Func Offset: 0x1c
	// Line 616, Address: 0x275dc4, Func Offset: 0x24
	// Line 618, Address: 0x275dc8, Func Offset: 0x28
	// Line 620, Address: 0x275dd4, Func Offset: 0x34
	// Line 621, Address: 0x275ddc, Func Offset: 0x3c
	// Func End, Address: 0x275dec, Func Offset: 0x4c
}

// 
// Start address: 0x275df0
void ExecuteStateLoadScreenSelectCard(tagLOAD_SCREEN* pLoad)
{
	// Line 636, Address: 0x275df0, Func Offset: 0
	// Line 639, Address: 0x275dfc, Func Offset: 0xc
	// Line 642, Address: 0x275e20, Func Offset: 0x30
	// Line 644, Address: 0x275e24, Func Offset: 0x34
	// Line 642, Address: 0x275e2c, Func Offset: 0x3c
	// Line 644, Address: 0x275e30, Func Offset: 0x40
	// Line 645, Address: 0x275e38, Func Offset: 0x48
	// Line 646, Address: 0x275e40, Func Offset: 0x50
	// Line 649, Address: 0x275e4c, Func Offset: 0x5c
	// Line 651, Address: 0x275e50, Func Offset: 0x60
	// Line 649, Address: 0x275e58, Func Offset: 0x68
	// Line 651, Address: 0x275e5c, Func Offset: 0x6c
	// Line 654, Address: 0x275e64, Func Offset: 0x74
	// Line 657, Address: 0x275e70, Func Offset: 0x80
	// Line 660, Address: 0x275e7c, Func Offset: 0x8c
	// Line 664, Address: 0x275eac, Func Offset: 0xbc
	// Line 667, Address: 0x275ecc, Func Offset: 0xdc
	// Line 669, Address: 0x275ed0, Func Offset: 0xe0
	// Line 667, Address: 0x275ed4, Func Offset: 0xe4
	// Line 669, Address: 0x275ed8, Func Offset: 0xe8
	// Line 670, Address: 0x275ee0, Func Offset: 0xf0
	// Line 672, Address: 0x275ee8, Func Offset: 0xf8
	// Line 675, Address: 0x275ef4, Func Offset: 0x104
	// Line 677, Address: 0x275ef8, Func Offset: 0x108
	// Line 675, Address: 0x275efc, Func Offset: 0x10c
	// Line 677, Address: 0x275f00, Func Offset: 0x110
	// Line 680, Address: 0x275f08, Func Offset: 0x118
	// Line 682, Address: 0x275f14, Func Offset: 0x124
	// Line 687, Address: 0x275f1c, Func Offset: 0x12c
	// Line 690, Address: 0x275f3c, Func Offset: 0x14c
	// Line 693, Address: 0x275f4c, Func Offset: 0x15c
	// Line 694, Address: 0x275f54, Func Offset: 0x164
	// Line 698, Address: 0x275f5c, Func Offset: 0x16c
	// Line 701, Address: 0x275f68, Func Offset: 0x178
	// Line 702, Address: 0x275f74, Func Offset: 0x184
	// Line 704, Address: 0x275f7c, Func Offset: 0x18c
	// Line 707, Address: 0x275f88, Func Offset: 0x198
	// Line 709, Address: 0x275f90, Func Offset: 0x1a0
	// Line 710, Address: 0x275f9c, Func Offset: 0x1ac
	// Line 714, Address: 0x275fa4, Func Offset: 0x1b4
	// Line 717, Address: 0x275fc0, Func Offset: 0x1d0
	// Line 730, Address: 0x275fc8, Func Offset: 0x1d8
	// Func End, Address: 0x275fd8, Func Offset: 0x1e8
}

// 
// Start address: 0x275fe0
void SetStateLoadScreenTitleExit(tagLOAD_SCREEN* pLoad)
{
	// Line 747, Address: 0x275fe0, Func Offset: 0
	// Line 749, Address: 0x275fe8, Func Offset: 0x8
	// Line 751, Address: 0x275ff0, Func Offset: 0x10
	// Line 753, Address: 0x275ff4, Func Offset: 0x14
	// Line 754, Address: 0x275ff8, Func Offset: 0x18
	// Func End, Address: 0x276000, Func Offset: 0x20
}

// 
// Start address: 0x276000
void ExecuteStateLoadScreenTitleExit(tagLOAD_SCREEN* pLoad)
{
	// Line 773, Address: 0x276000, Func Offset: 0
	// Line 775, Address: 0x276010, Func Offset: 0x10
	// Line 777, Address: 0x276018, Func Offset: 0x18
	// Func End, Address: 0x276020, Func Offset: 0x20
}

// 
// Start address: 0x276020
void SetStateLoadScreenErrUnFormat(tagLOAD_SCREEN* pLoad)
{
	// Line 794, Address: 0x276020, Func Offset: 0
	// Line 796, Address: 0x276028, Func Offset: 0x8
	// Line 798, Address: 0x276030, Func Offset: 0x10
	// Line 800, Address: 0x276038, Func Offset: 0x18
	// Func End, Address: 0x276044, Func Offset: 0x24
}

// 
// Start address: 0x276050
void ExecuteStateLoadScreenErrUnFormat(tagLOAD_SCREEN* pLoad)
{
	// Line 815, Address: 0x276050, Func Offset: 0
	// Line 817, Address: 0x276058, Func Offset: 0x8
	// Line 820, Address: 0x276078, Func Offset: 0x28
	// Line 822, Address: 0x276080, Func Offset: 0x30
	// Line 823, Address: 0x27608c, Func Offset: 0x3c
	// Line 827, Address: 0x276094, Func Offset: 0x44
	// Line 830, Address: 0x2760b0, Func Offset: 0x60
	// Line 833, Address: 0x2760b8, Func Offset: 0x68
	// Func End, Address: 0x2760c4, Func Offset: 0x74
}

// 
// Start address: 0x2760d0
void SetStateLoadScreenErrLostDirCheck(tagLOAD_SCREEN* pLoad)
{
	// Line 850, Address: 0x2760d0, Func Offset: 0
	// Line 852, Address: 0x2760d8, Func Offset: 0x8
	// Line 854, Address: 0x2760e0, Func Offset: 0x10
	// Line 855, Address: 0x2760e4, Func Offset: 0x14
	// Func End, Address: 0x2760ec, Func Offset: 0x1c
}

// 
// Start address: 0x2760f0
void ExecuteStateLoadScreenErrLostDirCheck(tagLOAD_SCREEN* pLoad)
{
	// Line 870, Address: 0x2760f0, Func Offset: 0
	// Line 872, Address: 0x2760f8, Func Offset: 0x8
	// Line 875, Address: 0x276118, Func Offset: 0x28
	// Line 877, Address: 0x276120, Func Offset: 0x30
	// Line 878, Address: 0x27612c, Func Offset: 0x3c
	// Line 882, Address: 0x276134, Func Offset: 0x44
	// Line 885, Address: 0x276150, Func Offset: 0x60
	// Line 888, Address: 0x276158, Func Offset: 0x68
	// Func End, Address: 0x276164, Func Offset: 0x74
}

// 
// Start address: 0x276170
void SetStateLoadScreenDirCheck(tagLOAD_SCREEN* pLoad)
{
	// Line 903, Address: 0x276170, Func Offset: 0
	// Line 905, Address: 0x27617c, Func Offset: 0xc
	// Line 907, Address: 0x276184, Func Offset: 0x14
	// Line 909, Address: 0x27618c, Func Offset: 0x1c
	// Line 911, Address: 0x276194, Func Offset: 0x24
	// Line 915, Address: 0x276198, Func Offset: 0x28
	// Line 913, Address: 0x27619c, Func Offset: 0x2c
	// Line 915, Address: 0x2761a4, Func Offset: 0x34
	// Line 917, Address: 0x2761a8, Func Offset: 0x38
	// Line 919, Address: 0x2761b4, Func Offset: 0x44
	// Line 921, Address: 0x2761c0, Func Offset: 0x50
	// Line 922, Address: 0x2761cc, Func Offset: 0x5c
	// Func End, Address: 0x2761dc, Func Offset: 0x6c
}

// 
// Start address: 0x2761e0
void ExecuteStateLoadScreenDirCheck(tagLOAD_SCREEN* pLoad)
{
	int lResult;
	// Line 937, Address: 0x2761e0, Func Offset: 0
	// Line 940, Address: 0x2761ec, Func Offset: 0xc
	// Line 944, Address: 0x276218, Func Offset: 0x38
	// Line 946, Address: 0x276220, Func Offset: 0x40
	// Line 948, Address: 0x27622c, Func Offset: 0x4c
	// Line 951, Address: 0x27623c, Func Offset: 0x5c
	// Line 953, Address: 0x276244, Func Offset: 0x64
	// Line 956, Address: 0x27624c, Func Offset: 0x6c
	// Line 960, Address: 0x276254, Func Offset: 0x74
	// Line 962, Address: 0x27625c, Func Offset: 0x7c
	// Line 965, Address: 0x276264, Func Offset: 0x84
	// Line 967, Address: 0x276270, Func Offset: 0x90
	// Line 969, Address: 0x276278, Func Offset: 0x98
	// Line 971, Address: 0x27627c, Func Offset: 0x9c
	// Line 975, Address: 0x276284, Func Offset: 0xa4
	// Line 976, Address: 0x27628c, Func Offset: 0xac
	// Line 979, Address: 0x276298, Func Offset: 0xb8
	// Line 980, Address: 0x27629c, Func Offset: 0xbc
	// Line 981, Address: 0x2762a4, Func Offset: 0xc4
	// Line 984, Address: 0x2762ac, Func Offset: 0xcc
	// Line 986, Address: 0x2762b8, Func Offset: 0xd8
	// Line 988, Address: 0x2762bc, Func Offset: 0xdc
	// Line 992, Address: 0x2762c4, Func Offset: 0xe4
	// Line 993, Address: 0x2762d8, Func Offset: 0xf8
	// Line 995, Address: 0x2762e0, Func Offset: 0x100
	// Line 997, Address: 0x2762e8, Func Offset: 0x108
	// Line 999, Address: 0x2762f4, Func Offset: 0x114
	// Line 1000, Address: 0x2762fc, Func Offset: 0x11c
	// Line 1001, Address: 0x276304, Func Offset: 0x124
	// Line 1006, Address: 0x27630c, Func Offset: 0x12c
	// Line 1010, Address: 0x276314, Func Offset: 0x134
	// Line 1015, Address: 0x276338, Func Offset: 0x158
	// Line 1018, Address: 0x276340, Func Offset: 0x160
	// Line 1019, Address: 0x276350, Func Offset: 0x170
	// Line 1022, Address: 0x27635c, Func Offset: 0x17c
	// Line 1023, Address: 0x27636c, Func Offset: 0x18c
	// Line 1026, Address: 0x276388, Func Offset: 0x1a8
	// Line 1027, Address: 0x276390, Func Offset: 0x1b0
	// Line 1033, Address: 0x276398, Func Offset: 0x1b8
	// Line 1034, Address: 0x2763a0, Func Offset: 0x1c0
	// Line 1037, Address: 0x2763a8, Func Offset: 0x1c8
	// Line 1039, Address: 0x2763b0, Func Offset: 0x1d0
	// Line 1041, Address: 0x2763bc, Func Offset: 0x1dc
	// Line 1043, Address: 0x2763c4, Func Offset: 0x1e4
	// Line 1046, Address: 0x2763cc, Func Offset: 0x1ec
	// Line 1049, Address: 0x2763dc, Func Offset: 0x1fc
	// Line 1051, Address: 0x2763e4, Func Offset: 0x204
	// Line 1054, Address: 0x2763ec, Func Offset: 0x20c
	// Line 1057, Address: 0x2763fc, Func Offset: 0x21c
	// Line 1062, Address: 0x276404, Func Offset: 0x224
	// Line 1065, Address: 0x27641c, Func Offset: 0x23c
	// Line 1067, Address: 0x276424, Func Offset: 0x244
	// Func End, Address: 0x276434, Func Offset: 0x254
}

// 
// Start address: 0x276440
void SetStateLoadScreenDirFileBroken(tagLOAD_SCREEN* pLoad)
{
	// Line 1084, Address: 0x276440, Func Offset: 0
	// Line 1086, Address: 0x276448, Func Offset: 0x8
	// Line 1088, Address: 0x276450, Func Offset: 0x10
	// Line 1089, Address: 0x276454, Func Offset: 0x14
	// Func End, Address: 0x27645c, Func Offset: 0x1c
}

// 
// Start address: 0x276460
void ExecuteStateLoadScreenDirFileBroken(tagLOAD_SCREEN* pLoad)
{
	// Line 1104, Address: 0x276460, Func Offset: 0
	// Line 1105, Address: 0x276468, Func Offset: 0x8
	// Line 1108, Address: 0x276488, Func Offset: 0x28
	// Line 1110, Address: 0x276490, Func Offset: 0x30
	// Line 1111, Address: 0x27649c, Func Offset: 0x3c
	// Line 1115, Address: 0x2764a4, Func Offset: 0x44
	// Line 1118, Address: 0x2764c0, Func Offset: 0x60
	// Line 1121, Address: 0x2764c8, Func Offset: 0x68
	// Func End, Address: 0x2764d4, Func Offset: 0x74
}

// 
// Start address: 0x2764e0
void SetStateLoadScreenSelectFile(tagLOAD_SCREEN* pLoad)
{
	// Line 1136, Address: 0x2764e0, Func Offset: 0
	// Line 1138, Address: 0x2764ec, Func Offset: 0xc
	// Line 1140, Address: 0x2764f4, Func Offset: 0x14
	// Line 1142, Address: 0x2764fc, Func Offset: 0x1c
	// Line 1144, Address: 0x276508, Func Offset: 0x28
	// Line 1146, Address: 0x27650c, Func Offset: 0x2c
	// Line 1148, Address: 0x276518, Func Offset: 0x38
	// Line 1150, Address: 0x27651c, Func Offset: 0x3c
	// Line 1151, Address: 0x276528, Func Offset: 0x48
	// Func End, Address: 0x276538, Func Offset: 0x58
}

// 
// Start address: 0x276540
void ExecuteStateLoadScreenSelectFile(tagLOAD_SCREEN* pLoad)
{
	unsigned int KeyWait01;
	unsigned int KeyWait00;
	// Line 1166, Address: 0x276540, Func Offset: 0
	// Line 1171, Address: 0x27654c, Func Offset: 0xc
	// Line 1173, Address: 0x27656c, Func Offset: 0x2c
	// Line 1175, Address: 0x276588, Func Offset: 0x48
	// Line 1177, Address: 0x27659c, Func Offset: 0x5c
	// Line 1178, Address: 0x2765ac, Func Offset: 0x6c
	// Line 1181, Address: 0x2765b4, Func Offset: 0x74
	// Line 1183, Address: 0x2765bc, Func Offset: 0x7c
	// Line 1186, Address: 0x2765c4, Func Offset: 0x84
	// Line 1187, Address: 0x2765cc, Func Offset: 0x8c
	// Line 1189, Address: 0x2765d4, Func Offset: 0x94
	// Line 1191, Address: 0x2765fc, Func Offset: 0xbc
	// Line 1192, Address: 0x276604, Func Offset: 0xc4
	// Line 1194, Address: 0x276614, Func Offset: 0xd4
	// Line 1196, Address: 0x276620, Func Offset: 0xe0
	// Line 1198, Address: 0x27662c, Func Offset: 0xec
	// Line 1199, Address: 0x276638, Func Offset: 0xf8
	// Line 1201, Address: 0x276644, Func Offset: 0x104
	// Line 1203, Address: 0x27664c, Func Offset: 0x10c
	// Line 1204, Address: 0x276658, Func Offset: 0x118
	// Line 1205, Address: 0x276660, Func Offset: 0x120
	// Line 1209, Address: 0x276670, Func Offset: 0x130
	// Line 1211, Address: 0x27667c, Func Offset: 0x13c
	// Line 1212, Address: 0x276688, Func Offset: 0x148
	// Line 1213, Address: 0x276690, Func Offset: 0x150
	// Line 1215, Address: 0x27669c, Func Offset: 0x15c
	// Line 1217, Address: 0x2766a8, Func Offset: 0x168
	// Line 1219, Address: 0x2766b4, Func Offset: 0x174
	// Line 1221, Address: 0x2766c0, Func Offset: 0x180
	// Line 1223, Address: 0x2766d0, Func Offset: 0x190
	// Line 1225, Address: 0x2766d4, Func Offset: 0x194
	// Line 1226, Address: 0x2766e0, Func Offset: 0x1a0
	// Line 1227, Address: 0x2766e8, Func Offset: 0x1a8
	// Line 1230, Address: 0x2766fc, Func Offset: 0x1bc
	// Line 1232, Address: 0x276708, Func Offset: 0x1c8
	// Line 1235, Address: 0x276714, Func Offset: 0x1d4
	// Line 1238, Address: 0x27671c, Func Offset: 0x1dc
	// Line 1241, Address: 0x276728, Func Offset: 0x1e8
	// Line 1242, Address: 0x276730, Func Offset: 0x1f0
	// Line 1243, Address: 0x276738, Func Offset: 0x1f8
	// Line 1246, Address: 0x276744, Func Offset: 0x204
	// Line 1248, Address: 0x27674c, Func Offset: 0x20c
	// Line 1254, Address: 0x276758, Func Offset: 0x218
	// Line 1257, Address: 0x276774, Func Offset: 0x234
	// Line 1261, Address: 0x27677c, Func Offset: 0x23c
	// Line 1263, Address: 0x276790, Func Offset: 0x250
	// Line 1266, Address: 0x276794, Func Offset: 0x254
	// Line 1268, Address: 0x2767b8, Func Offset: 0x278
	// Line 1269, Address: 0x2767d0, Func Offset: 0x290
	// Line 1271, Address: 0x2767e8, Func Offset: 0x2a8
	// Func End, Address: 0x2767f8, Func Offset: 0x2b8
}

// 
// Start address: 0x276800
void LoadScreenCheckSave(tagLOAD_SCREEN* pLoad)
{
	// Line 1286, Address: 0x276800, Func Offset: 0
	// Line 1288, Address: 0x27680c, Func Offset: 0xc
	// Line 1291, Address: 0x27681c, Func Offset: 0x1c
	// Line 1294, Address: 0x276830, Func Offset: 0x30
	// Line 1296, Address: 0x276838, Func Offset: 0x38
	// Line 1297, Address: 0x276844, Func Offset: 0x44
	// Line 1302, Address: 0x27684c, Func Offset: 0x4c
	// Line 1304, Address: 0x276858, Func Offset: 0x58
	// Line 1306, Address: 0x276864, Func Offset: 0x64
	// Func End, Address: 0x276874, Func Offset: 0x74
}

// 
// Start address: 0x276880
void SetStateLoadScreenNoSave(tagLOAD_SCREEN* pLoad)
{
	// Line 1323, Address: 0x276880, Func Offset: 0
	// Line 1325, Address: 0x276888, Func Offset: 0x8
	// Line 1327, Address: 0x276890, Func Offset: 0x10
	// Line 1328, Address: 0x276894, Func Offset: 0x14
	// Func End, Address: 0x27689c, Func Offset: 0x1c
}

// 
// Start address: 0x2768a0
void ExecuteStateLoadScreenNoSave(tagLOAD_SCREEN* pLoad)
{
	// Line 1343, Address: 0x2768a0, Func Offset: 0
	// Line 1345, Address: 0x2768a8, Func Offset: 0x8
	// Line 1348, Address: 0x2768c8, Func Offset: 0x28
	// Line 1350, Address: 0x2768d0, Func Offset: 0x30
	// Line 1351, Address: 0x2768dc, Func Offset: 0x3c
	// Line 1355, Address: 0x2768e4, Func Offset: 0x44
	// Line 1358, Address: 0x276900, Func Offset: 0x60
	// Line 1361, Address: 0x276908, Func Offset: 0x68
	// Func End, Address: 0x276914, Func Offset: 0x74
}

// 
// Start address: 0x276920
void SetStateLoadScreenLoadCursor(tagLOAD_SCREEN* pLoad)
{
	// Line 1378, Address: 0x276920, Func Offset: 0
	// Line 1380, Address: 0x276928, Func Offset: 0x8
	// Line 1382, Address: 0x276930, Func Offset: 0x10
	// Line 1385, Address: 0x276938, Func Offset: 0x18
	// Func End, Address: 0x276940, Func Offset: 0x20
}

// 
// Start address: 0x276940
void ExecuteStateLoadScreenLoadCursor(tagLOAD_SCREEN* pLoad)
{
	// Line 1400, Address: 0x276940, Func Offset: 0
	// Line 1404, Address: 0x276948, Func Offset: 0x8
	// Line 1407, Address: 0x276968, Func Offset: 0x28
	// Line 1411, Address: 0x27696c, Func Offset: 0x2c
	// Line 1407, Address: 0x276970, Func Offset: 0x30
	// Line 1409, Address: 0x276978, Func Offset: 0x38
	// Line 1411, Address: 0x276984, Func Offset: 0x44
	// Line 1412, Address: 0x27698c, Func Offset: 0x4c
	// Line 1414, Address: 0x276994, Func Offset: 0x54
	// Line 1417, Address: 0x2769a0, Func Offset: 0x60
	// Line 1421, Address: 0x2769a4, Func Offset: 0x64
	// Line 1417, Address: 0x2769a8, Func Offset: 0x68
	// Line 1419, Address: 0x2769b0, Func Offset: 0x70
	// Line 1421, Address: 0x2769bc, Func Offset: 0x7c
	// Line 1422, Address: 0x2769c4, Func Offset: 0x84
	// Line 1424, Address: 0x2769cc, Func Offset: 0x8c
	// Line 1426, Address: 0x2769d8, Func Offset: 0x98
	// Line 1429, Address: 0x2769e8, Func Offset: 0xa8
	// Line 1431, Address: 0x2769f0, Func Offset: 0xb0
	// Line 1432, Address: 0x2769fc, Func Offset: 0xbc
	// Line 1436, Address: 0x276a04, Func Offset: 0xc4
	// Line 1438, Address: 0x276a0c, Func Offset: 0xcc
	// Line 1440, Address: 0x276a18, Func Offset: 0xd8
	// Line 1442, Address: 0x276a20, Func Offset: 0xe0
	// Line 1445, Address: 0x276a2c, Func Offset: 0xec
	// Line 1447, Address: 0x276a34, Func Offset: 0xf4
	// Line 1448, Address: 0x276a40, Func Offset: 0x100
	// Line 1452, Address: 0x276a48, Func Offset: 0x108
	// Line 1455, Address: 0x276a64, Func Offset: 0x124
	// Line 1458, Address: 0x276a6c, Func Offset: 0x12c
	// Func End, Address: 0x276a78, Func Offset: 0x138
}

// 
// Start address: 0x276a80
void SetStateLoadScreenLoad(tagLOAD_SCREEN* pLoad)
{
	// Line 1475, Address: 0x276a80, Func Offset: 0
	// Line 1479, Address: 0x276a88, Func Offset: 0x8
	// Line 1477, Address: 0x276a8c, Func Offset: 0xc
	// Line 1481, Address: 0x276a90, Func Offset: 0x10
	// Line 1479, Address: 0x276a94, Func Offset: 0x14
	// Line 1481, Address: 0x276a98, Func Offset: 0x18
	// Line 1483, Address: 0x276a9c, Func Offset: 0x1c
	// Func End, Address: 0x276aa4, Func Offset: 0x24
}

// 
// Start address: 0x276ab0
void ExecuteStateLoadScreenLoad(tagLOAD_SCREEN* pLoad)
{
	int lFileNumber;
	int lResult;
	// Line 1499, Address: 0x276ab0, Func Offset: 0
	// Line 1502, Address: 0x276abc, Func Offset: 0xc
	// Line 1507, Address: 0x276af4, Func Offset: 0x44
	// Line 1509, Address: 0x276afc, Func Offset: 0x4c
	// Line 1514, Address: 0x276b20, Func Offset: 0x70
	// Line 1517, Address: 0x276b28, Func Offset: 0x78
	// Line 1519, Address: 0x276b34, Func Offset: 0x84
	// Line 1522, Address: 0x276b40, Func Offset: 0x90
	// Line 1523, Address: 0x276b48, Func Offset: 0x98
	// Line 1525, Address: 0x276b50, Func Offset: 0xa0
	// Line 1528, Address: 0x276b5c, Func Offset: 0xac
	// Line 1530, Address: 0x276b68, Func Offset: 0xb8
	// Line 1532, Address: 0x276b70, Func Offset: 0xc0
	// Line 1533, Address: 0x276b74, Func Offset: 0xc4
	// Line 1535, Address: 0x276b7c, Func Offset: 0xcc
	// Line 1538, Address: 0x276b88, Func Offset: 0xd8
	// Line 1540, Address: 0x276b94, Func Offset: 0xe4
	// Line 1542, Address: 0x276b9c, Func Offset: 0xec
	// Line 1544, Address: 0x276ba0, Func Offset: 0xf0
	// Line 1547, Address: 0x276ba8, Func Offset: 0xf8
	// Line 1550, Address: 0x276bb8, Func Offset: 0x108
	// Line 1552, Address: 0x276bc0, Func Offset: 0x110
	// Line 1555, Address: 0x276bc8, Func Offset: 0x118
	// Line 1558, Address: 0x276bd8, Func Offset: 0x128
	// Line 1562, Address: 0x276be0, Func Offset: 0x130
	// Func End, Address: 0x276bf0, Func Offset: 0x140
}

// 
// Start address: 0x276bf0
void SetStateLoadScreenFileBroken(tagLOAD_SCREEN* pLoad)
{
	// Line 1579, Address: 0x276bf0, Func Offset: 0
	// Line 1581, Address: 0x276bf8, Func Offset: 0x8
	// Line 1583, Address: 0x276c00, Func Offset: 0x10
	// Line 1584, Address: 0x276c04, Func Offset: 0x14
	// Func End, Address: 0x276c0c, Func Offset: 0x1c
}

// 
// Start address: 0x276c10
void ExecuteStateLoadScreenFileBroken(tagLOAD_SCREEN* pLoad)
{
	// Line 1599, Address: 0x276c10, Func Offset: 0
	// Line 1600, Address: 0x276c18, Func Offset: 0x8
	// Line 1603, Address: 0x276c38, Func Offset: 0x28
	// Line 1605, Address: 0x276c40, Func Offset: 0x30
	// Line 1606, Address: 0x276c4c, Func Offset: 0x3c
	// Line 1610, Address: 0x276c54, Func Offset: 0x44
	// Line 1613, Address: 0x276c70, Func Offset: 0x60
	// Line 1616, Address: 0x276c78, Func Offset: 0x68
	// Func End, Address: 0x276c84, Func Offset: 0x74
}

// 
// Start address: 0x276c90
void SetStateLoadScreenErrCardRead(tagLOAD_SCREEN* pLoad)
{
	// Line 1633, Address: 0x276c90, Func Offset: 0
	// Line 1635, Address: 0x276c98, Func Offset: 0x8
	// Line 1637, Address: 0x276ca0, Func Offset: 0x10
	// Line 1638, Address: 0x276ca4, Func Offset: 0x14
	// Func End, Address: 0x276cac, Func Offset: 0x1c
}

// 
// Start address: 0x276cb0
void ExecuteStateLoadScreenErrCardRead(tagLOAD_SCREEN* pLoad)
{
	// Line 1653, Address: 0x276cb0, Func Offset: 0
	// Line 1654, Address: 0x276cb8, Func Offset: 0x8
	// Line 1657, Address: 0x276cd8, Func Offset: 0x28
	// Line 1659, Address: 0x276ce0, Func Offset: 0x30
	// Line 1660, Address: 0x276cec, Func Offset: 0x3c
	// Line 1664, Address: 0x276cf4, Func Offset: 0x44
	// Line 1667, Address: 0x276d10, Func Offset: 0x60
	// Line 1670, Address: 0x276d18, Func Offset: 0x68
	// Func End, Address: 0x276d24, Func Offset: 0x74
}

// 
// Start address: 0x276d30
void SetStateLoadScreenLoadExit(tagLOAD_SCREEN* pLoad)
{
	// Line 1687, Address: 0x276d30, Func Offset: 0
	// Line 1689, Address: 0x276d38, Func Offset: 0x8
	// Line 1691, Address: 0x276d40, Func Offset: 0x10
	// Line 1693, Address: 0x276d44, Func Offset: 0x14
	// Line 1695, Address: 0x276d4c, Func Offset: 0x1c
	// Func End, Address: 0x276d58, Func Offset: 0x28
}

// 
// Start address: 0x276d60
void ExecuteStateLoadScreenLoadExit(tagLOAD_SCREEN* pLoad)
{
	// Line 1711, Address: 0x276d60, Func Offset: 0
	// Line 1715, Address: 0x276d6c, Func Offset: 0xc
	// Line 1718, Address: 0x276d80, Func Offset: 0x20
	// Line 1720, Address: 0x276d8c, Func Offset: 0x2c
	// Line 1722, Address: 0x276d94, Func Offset: 0x34
	// Line 1720, Address: 0x276d98, Func Offset: 0x38
	// Line 1722, Address: 0x276da4, Func Offset: 0x44
	// Line 1724, Address: 0x276da8, Func Offset: 0x48
	// Func End, Address: 0x276db8, Func Offset: 0x58
}

// 
// Start address: 0x276dc0
void SetDispLoadSelectMessage()
{
	// Line 1749, Address: 0x276dc0, Func Offset: 0
	// Line 1738, Address: 0x276dcc, Func Offset: 0xc
	// Line 1749, Address: 0x276dd0, Func Offset: 0x10
	// Line 1738, Address: 0x276dd8, Func Offset: 0x18
	// Line 1749, Address: 0x276ddc, Func Offset: 0x1c
	// Line 1751, Address: 0x276de4, Func Offset: 0x24
	// Line 1753, Address: 0x276e10, Func Offset: 0x50
	// Line 1754, Address: 0x276e3c, Func Offset: 0x7c
	// Line 1756, Address: 0x276e68, Func Offset: 0xa8
	// Line 1757, Address: 0x276e94, Func Offset: 0xd4
	// Line 1759, Address: 0x276ec4, Func Offset: 0x104
	// Line 1760, Address: 0x276ef4, Func Offset: 0x134
	// Line 1762, Address: 0x276f0c, Func Offset: 0x14c
	// Func End, Address: 0x276f18, Func Offset: 0x158
}

// 
// Start address: 0x276f20
void CheckDispLoadMemoryCard(tagLOAD_SCREEN* pLoad)
{
	int lPort1CurX;
	int lPort0CurX;
	int lPort1Card;
	int lPort0Card;
	// Line 1777, Address: 0x276f20, Func Offset: 0
	// Line 1782, Address: 0x276f38, Func Offset: 0x18
	// Line 1784, Address: 0x276f44, Func Offset: 0x24
	// Line 1787, Address: 0x276f54, Func Offset: 0x34
	// Line 1791, Address: 0x276f68, Func Offset: 0x48
	// Line 1790, Address: 0x276f6c, Func Offset: 0x4c
	// Line 1793, Address: 0x276f70, Func Offset: 0x50
	// Line 1791, Address: 0x276f74, Func Offset: 0x54
	// Line 1794, Address: 0x276f78, Func Offset: 0x58
	// Line 1796, Address: 0x276f80, Func Offset: 0x60
	// Line 1802, Address: 0x276f94, Func Offset: 0x74
	// Line 1800, Address: 0x276f98, Func Offset: 0x78
	// Line 1803, Address: 0x276f9c, Func Offset: 0x7c
	// Line 1799, Address: 0x276fa0, Func Offset: 0x80
	// Line 1804, Address: 0x276fa4, Func Offset: 0x84
	// Line 1806, Address: 0x276fac, Func Offset: 0x8c
	// Line 1811, Address: 0x276fc0, Func Offset: 0xa0
	// Line 1812, Address: 0x276fc4, Func Offset: 0xa4
	// Line 1808, Address: 0x276fc8, Func Offset: 0xa8
	// Line 1810, Address: 0x276fcc, Func Offset: 0xac
	// Line 1814, Address: 0x276fd0, Func Offset: 0xb0
	// Line 1823, Address: 0x276fd8, Func Offset: 0xb8
	// Line 1822, Address: 0x276fdc, Func Offset: 0xbc
	// Line 1818, Address: 0x276fe0, Func Offset: 0xc0
	// Line 1819, Address: 0x276fe4, Func Offset: 0xc4
	// Line 1820, Address: 0x276fe8, Func Offset: 0xc8
	// Line 1821, Address: 0x276fec, Func Offset: 0xcc
	// Line 1823, Address: 0x276ff0, Func Offset: 0xd0
	// Line 1826, Address: 0x276ff4, Func Offset: 0xd4
	// Line 1828, Address: 0x277004, Func Offset: 0xe4
	// Line 1829, Address: 0x277008, Func Offset: 0xe8
	// Line 1830, Address: 0x27700c, Func Offset: 0xec
	// Line 1831, Address: 0x277010, Func Offset: 0xf0
	// Line 1835, Address: 0x277014, Func Offset: 0xf4
	// Line 1836, Address: 0x27702c, Func Offset: 0x10c
	// Line 1838, Address: 0x277048, Func Offset: 0x128
	// Line 1839, Address: 0x2770a0, Func Offset: 0x180
	// Func End, Address: 0x2770b8, Func Offset: 0x198
}

