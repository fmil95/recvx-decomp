#ifndef _PS2_SAVESCREEN_H_
#define _PS2_SAVESCREEN_H_

/*typedef struct _anon0;
typedef struct npobj;
typedef struct tagSAVE_SCREEN;
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
typedef struct tagSAVEFILE;
typedef struct _anon12;
typedef struct _anon13;
typedef struct _anon14;
typedef struct _anon15;
typedef struct BH_PWORK;
typedef struct _anon16;
typedef struct _anon17;
typedef struct _anon18;
typedef struct _anon19;
typedef struct tagICONINFORMATION;
typedef struct _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct tagCONFIGFILE;
typedef struct _anon23;
typedef struct _anon24;
typedef struct _anon25;
typedef struct tagMEMORYCARDSTATE;
typedef struct _anon26;
typedef struct _anon27;
typedef struct _anon28;
typedef struct _anon29;
typedef struct _anon30;
typedef struct _anon31;
typedef struct _anon32;
typedef struct _anon33;

typedef void(*type_105)(void*);

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
typedef char type_10[12];
typedef char type_11[64];
typedef _anon0* type_12[512];
typedef _anon2* type_13[1300];
typedef int type_14[8];
typedef tagMEMORYCARDPORT type_15[2];
typedef _anon0* type_16[512];
typedef _anon2* type_17[200];
typedef _anon0* type_18[128];
typedef unsigned int type_19[1];
typedef char type_20[12];
typedef char type_21[32];
typedef _anon2* type_22[8];
typedef char type_23[12];
typedef int* type_24[16];
typedef _anon0* type_25[128];
typedef short type_26[32];
typedef npobj* type_27[16];
typedef _anon0* type_28[128];
typedef _anon2* type_29[16];
typedef _anon8 type_30[16];
typedef _anon0* type_31[512];
typedef unsigned int type_32[4];
typedef char type_33[12];
typedef _anon0* type_34[32];
typedef _anon3* type_35[128];
typedef char type_36[256];
typedef _anon0* type_37[32];
typedef unsigned char type_38[64];
typedef float type_39[4];
typedef float type_40[16];
typedef float type_41[4];
typedef _anon0* type_42[32];
typedef float type_43[4];
typedef char type_44[12];
typedef char type_45[8];
typedef _anon26 type_46[1];
typedef _anon24 type_47[256];
typedef char type_48[12];
typedef char type_49[13];
typedef int type_50[4];
typedef _anon2* type_51[256];
typedef float type_52[3];
typedef int type_53[4];
typedef unsigned int type_54[32];
typedef unsigned char* type_55[256];
typedef int type_56[3];
typedef unsigned int type_57[16];
typedef float type_58[3];
typedef float type_59[4];
typedef short type_60[256];
typedef unsigned int type_61[16];
typedef unsigned int type_62[32];
typedef unsigned int type_63[16];
typedef unsigned char type_64[4];
typedef int type_65[4];
typedef unsigned int type_66[8];
typedef short type_67[256];
typedef unsigned int type_68[384];
typedef char type_69[12];
typedef int type_70[8];
typedef unsigned int type_71[4];
typedef _anon2* type_72[256];
typedef char type_73[4];
typedef _anon7 type_74[256];
typedef short type_75[4];
typedef tagSELECTFILEINFO type_76[15];
typedef int type_77[4][4];
typedef unsigned char type_78[4];
typedef float type_79[4][3];
typedef _anon26 type_80[450];
typedef char type_81[12];
typedef char type_82[12];
typedef float type_83[4][3];
typedef short type_84[256];
typedef unsigned char type_85[68];
typedef int type_86[64];
typedef _anon8 type_87[450];
typedef unsigned char type_88[64];
typedef char type_89[9];
typedef unsigned char type_90[64];
typedef char type_91[3];
typedef _anon20 type_92[4];
typedef unsigned char type_93[64];
typedef _anon22 type_94[4];
typedef int type_95[450];
typedef unsigned char type_96[512];
typedef char* type_97[18];
typedef unsigned int type_98[8];
typedef unsigned char type_99[450];
typedef _anon16 type_100[4];
typedef char type_101[12];
typedef void* type_102[2];
typedef char type_103[16];
typedef char type_104[4];
typedef unsigned int type_106[32];
typedef _anon30 type_107[16];
typedef unsigned int type_108[16];
typedef char type_109[12];
typedef char type_110[12];
typedef unsigned int type_111[2];
typedef unsigned int type_112[16];
typedef unsigned int type_113[32];
typedef unsigned int type_114[16];
typedef BH_PWORK* type_115[16];
typedef unsigned int type_116[8];
typedef unsigned int type_117[1];
typedef unsigned int type_118[384];
typedef unsigned int type_119[2];
typedef int* type_120[16];
typedef unsigned int type_121[4];
typedef char type_122[12];
typedef npobj* type_123[16];
typedef _anon2* type_124[16];
typedef char type_125[4];
typedef _anon8 type_126[16];
typedef short type_127[4];
typedef unsigned char type_128[4];
typedef char type_129[12];
typedef char type_130[12];
typedef _anon19 type_131[16];
typedef _anon32 type_132[64];
typedef _anon0* type_133[512];
typedef _anon32 type_134[64];
typedef unsigned int type_135[32];
typedef char type_136[11];
typedef _anon0* type_137[128];
typedef _anon32 type_138[64];
typedef _anon31 type_139[32];
typedef unsigned int type_140[3];
typedef _anon0* type_141[512];
typedef unsigned char type_142[64];
typedef _anon0* type_143[512];
typedef char type_144[50];

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

struct tagSAVE_SCREEN
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
	void* vpReadBuffer;
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

struct tagICONINFORMATION
{
	_anon17 icon;
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
};*/

#endif
