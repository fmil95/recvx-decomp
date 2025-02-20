typedef struct npobj;
typedef struct BH_PWORK;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _en29_freework;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _eaw_typ;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef enum _enum_0;
typedef struct _anon9;
typedef enum _enum_1;
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
typedef struct _e19_dmg_typ;
typedef struct _anon29;
typedef struct _anon30;
typedef struct _anon31;
typedef struct _anon32;
typedef struct _anon33;
typedef struct _anon34;
typedef struct _anon35;
typedef struct _anon36;
typedef enum _enum_2;
typedef struct _anon37;
typedef enum _enum_3;
typedef struct _anon38;
typedef struct _anon39;
typedef struct _anon40;
typedef struct _anon41;
typedef struct _anon42;
typedef enum _enum_4;
typedef struct _anon43;

typedef void(*type_16)(BH_PWORK*, void*, int);
typedef void(*type_33)(BH_PWORK*);
typedef void(*type_47)(BH_PWORK*, void*);
typedef void(*type_50)(BH_PWORK*);
typedef void(*type_84)(void*);
typedef void(*type_120)(BH_PWORK*, void*, int);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef char type_2[20];
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
typedef short type_17[32];
typedef _anon18 type_18[1];
typedef _anon0* type_19[128];
typedef _anon1 type_20[4];
typedef unsigned int type_21[1];
typedef _anon8 type_22[256];
typedef _anon2* type_23[8];
typedef int* type_24[16];
typedef _anon0* type_25[128];
typedef npobj* type_26[16];
typedef _anon0* type_27[128];
typedef int type_28[4];
typedef _anon2* type_29[16];
typedef unsigned int type_30[4];
typedef _anon12 type_31[16];
typedef _anon0* type_32[512];
typedef void(*type_34)(BH_PWORK*)[4];
typedef char type_35[256];
typedef float type_36[4];
typedef _anon31 type_37[21];
typedef float type_38[4];
typedef float type_39[4];
typedef _anon6* type_40[128];
typedef unsigned char type_41[64];
typedef float type_42[16];
typedef int type_43[4];
typedef int type_44[4][9];
typedef float type_45[16][0];
typedef char type_46[8];
typedef void* type_48[2];
typedef _anon40 type_49[21];
typedef void(*type_51)(BH_PWORK*)[6];
typedef _anon2* type_52[256];
typedef int type_53[4];
typedef unsigned char* type_54[256];
typedef unsigned int type_55[2];
typedef short type_56[256];
typedef _anon19 type_57[15];
typedef _anon24 type_58[4];
typedef float type_59[3];
typedef short type_60[256];
typedef int type_61[3];
typedef int type_62[8];
typedef float type_63[3];
typedef _anon2* type_64[256];
typedef _anon10 type_65[256];
typedef _anon18 type_66[450];
typedef _anon27 type_67[16];
typedef short type_68[256];
typedef char type_69[3];
typedef int type_70[64];
typedef _anon12 type_71[450];
typedef char type_72[4];
typedef _anon34 type_73[4];
typedef _anon3 type_74[4];
typedef int type_75[450];
typedef unsigned int type_76[8];
typedef unsigned char type_77[450];
typedef _anon14 type_78[2];
typedef _enum_0 type_79[4];
typedef int type_80[4];
typedef _e19_dmg_typ type_81[8];
typedef char type_82[16];
typedef char type_83[4];
typedef unsigned int type_85[32];
typedef unsigned int type_86[16];
typedef _anon43 type_87[21];
typedef _anon4 type_88[64];
typedef unsigned int type_89[16];
typedef _anon4 type_90[64];
typedef unsigned int type_91[32];
typedef _anon4 type_92[64];
typedef unsigned int type_93[16];
typedef _anon7 type_94[40];
typedef unsigned int type_95[3];
typedef BH_PWORK* type_96[16];
typedef unsigned int type_97[8];
typedef _anon28 type_98[6];
typedef unsigned int type_99[1];
typedef unsigned int type_100[384];
typedef unsigned int type_101[2];
typedef int type_102[3];
typedef unsigned char type_103[2];
typedef unsigned int type_104[4];
typedef int* type_105[16];
typedef char type_106[32];
typedef npobj* type_107[16];
typedef char type_108[64];
typedef _anon35 type_109[5];
typedef _anon2* type_110[16];
typedef char type_111[4];
typedef _anon12 type_112[16];
typedef short type_113[4];
typedef _anon30 type_114[20];
typedef unsigned char type_115[4];
typedef _anon32 type_116[16];
typedef unsigned int type_117[32];
typedef _anon26 type_118[32];
typedef _anon0* type_119[512];
typedef _anon0* type_121[128];
typedef _anon0* type_122[512];
typedef unsigned char type_123[64];
typedef _anon0* type_124[512];

struct npobj
{
	unsigned int evalflags;
	_anon25* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
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
	_anon6* mnwP;
	_anon6* mnwPb;
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
	_anon19* cpcl;
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
	_anon6* mnwP;
	_anon6* mnwPb;
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
	_anon34* pvp;
	_anon3* tvp;
	_anon34 pv[4];
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

struct _anon1
{
	_enum_2 bas_obj;
	_enum_2 atr_obj;
	_anon26 atr_siz;
	_enum_2 atk_obj0;
	float atk_rng0;
	_enum_2 atk_obj1;
	float atk_rng1;
};

struct _en29_freework
{
	_e19_dmg_typ* dmg_eneP;
	_e19_dmg_typ DmgWrk[8];
	int status;
	_enum_3 mode0_bak;
	_enum_0 br_mde0;
	_enum_1 br_mde1;
	int br_rnd;
	int br_tim;
	int br_fir;
	_anon26 tgt_pos;
	int dir_dlt;
	_enum_2 bas_obj;
	int bas_ax;
	int bas_ay;
	_enum_2 atk_obj0;
	_enum_2 atk_obj1;
	float atk_rng0;
	float atk_rng1;
	_enum_2 dmg_obj;
	int dmg_lvl;
	int eff_wit;
	_anon0* sdw_owkP;
	_anon4* hit_tabP;
	_enum_2 atr_obj;
	int p_status;
	int p_br_mde0;
	int p_br_mde1;
	_anon26 ply_dmg;
	int dmg_dir;
	_eaw_typ ene_act;
	_anon11 ply_act;
};

struct _anon2
{
	_anon18* textures;
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

struct _eaw_typ
{
	int act_flg;
	void(*prgP)(BH_PWORK*, void*, int);
	int act_frm;
	int act_now;
	int mtn_rte;
	int chg_rte;
	int act_cnt;
	int b_act_flg;
	void(*b_prgP)(BH_PWORK*, void*, int);
	int b_act_frm;
	int b_act_now;
	int b_mtn_rte;
	int b_chg_rte;
	int b_act_cnt;
	int b_mtn_md;
	int dummy;
	_anon7* act_tblP;
	int tbl_num;
};

struct _anon5
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
	_anon26 ply_pos;
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
	_anon6* emtp[128];
	_anon6* rmthp;
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
	_anon10 txbp[256];
	unsigned char* ef_psp;
	_anon18 ef_tex[450];
	_anon2 ef_tlist;
	_anon36 ef;
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
	_anon16 ren_info;
	_anon18 ren_tex[1];
	_anon2 ren_tlist;
	_anon8 rpb[256];
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
	_anon37 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon20* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon24 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon27 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon4* pl_htp;
	int costume;
	_anon26 hd_pos;
	_anon26 apos;
	_anon4* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon4 mwalp[64];
	_anon4 metcp[64];
	_anon4 mflrp[64];
	int dla_n;
	_anon4* htp;
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
	_anon15 door;
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
	_anon26 ufo_pos;
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
	_anon32 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon26 ghtp[32];
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

struct _anon6
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon17* md2P;
	unsigned short* atrP;
};

struct _anon7
{
	int label;
	unsigned char mtn_no;
	unsigned char frm_no;
	unsigned char hkn_lvl;
	unsigned char hkn_cnt;
	float chg_rte;
	int flag;
	void* prgP;
};

struct _anon8
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

enum _enum_0
{
	TC_BR0_NORMAL,
	TC_BR0_ATTACK,
	TC_BR0_DAMAGE,
	TC_BR0_DIE,
	TC_BR0_WAIT
};

struct _anon9
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

enum _enum_1
{
	TC_BR1_FIRST,
	TC_BR1_LOOP0,
	TC_BR1_LOOP1
};

struct _anon10
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon11
{
	int p_status;
	int p_mode;
	int p_act_flg;
	void(*p_prgP)(BH_PWORK*, void*);
	void* p_paramP;
	int p_act_frm;
	int p_chg_frm;
	int p_mtn_rte;
	int p_act_jmp;
	int p_frm_num;
	int p_act_now;
	_anon6* ene_mnwP;
	_anon14* act_tblP;
	int tbl_num;
};

struct _anon12
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon2* texP;
	_anon22* owP;
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
	_anon38* info;
};

struct _anon14
{
	short mtn_no;
	short frm_no;
	unsigned char hkn_lvl;
	unsigned char hkn_cnt;
	unsigned char chg_frm;
	char act_jmp;
	int flag;
	void* prgP;
};

struct _anon15
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

struct _anon16
{
	void* texaddr;
	_anon9 texsurface;
};

struct _anon17
{
	void* p[2];
};

struct _anon18
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon19
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon20
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
	_anon23* light;
};

struct _anon21
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon22
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon23
{
	float mtrx[16];
	_anon26 pnt;
	_anon26 vctr;
	int stat;
	int reserve;
	_anon33 ltcal;
	_anon39 attr;
};

struct _anon24
{
	_anon26 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon25
{
	int* vlist;
	short* plist;
	_anon26 center;
	float r;
};

struct _anon26
{
	float x;
	float y;
	float z;
};

struct _anon27
{
	float x;
	float y;
};

struct _anon28
{
	int obj_no;
	float chk_siz;
};

struct _e19_dmg_typ
{
	_e19_dmg_typ* nextP;
	BH_PWORK* ewP;
	_enum_2 atr_top;
	_enum_2 atr_end;
	float atr_rad;
};

struct _anon29
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

struct _anon30
{
	float off_z;
	float rnd_z;
};

struct _anon31
{
	int eff_nml_p;
	int eff_nml_s;
	int eff_cmb_p;
	int eff_cmb_s;
};

struct _anon32
{
	_anon26 c1;
	_anon26 c2;
	float r1;
	float r2;
};

struct _anon33
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
	_anon26 lpnt;
	_anon26 lvctr;
	_anon26 lmvctr;
	_anon21 atten;
	_anon21 amb;
	_anon21 dif;
	_anon21 spc;
	_anon21 mamb;
	_anon21 mdif;
	_anon21 mspc;
};

struct _anon34
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon35
{
	_enum_2 atr_top;
	_enum_2 atr_end;
	float atr_rad;
	int or_flg2;
};

struct _anon36
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

enum _enum_2
{
	TC_OBJ_NULL,
	TC_OBJ_BODY00,
	TC_OBJ_BODY01,
	TC_OBJ_BODY02,
	TC_OBJ_BODY03,
	TC_OBJ_BODY04,
	TC_OBJ_BODY05,
	TC_OBJ_BODY06,
	TC_OBJ_BODY07,
	TC_OBJ_BODY08,
	TC_OBJ_BODY09,
	TC_OBJ_BODY10,
	TC_OBJ_BODY11,
	TC_OBJ_BODY12,
	TC_OBJ_BODY13,
	TC_OBJ_BODY14,
	TC_OBJ_BODY15,
	TC_OBJ_BODY16,
	TC_OBJ_BODY17,
	TC_OBJ_BODY18,
	TC_OBJ_NUM
};

struct _anon37
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

enum _enum_3
{
	TC_PRG_INIT,
	TC_PRG_MOVE,
	TC_PRG_DAMAGE,
	TC_PRG_DIE,
	TC_PRG_UNKKOWN,
	TC_PRG_EVENT
};

struct _anon38
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

struct _anon39
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
	_anon21 argb;
};

struct _anon40
{
	int crit;
	int pt[3];
	int timeout;
	int bonus;
};

struct _anon41
{
	_anon26 c;
	float r;
};

struct _anon42
{
	_anon26 c1;
	_anon26 c2;
	float r;
};

enum _enum_4
{
	TC_ACT_000,
	TC_ACT_001,
	TC_ACT_002,
	TC_ACT_003,
	TC_ACT_004,
	TC_ACT_005,
	TC_ACT_006,
	TC_ACT_007,
	TC_ACT_008,
	TC_ACT_009,
	TC_ACT_010,
	TC_ACT_011,
	TC_ACT_012,
	TC_ACT_013,
	TC_ACT_014,
	TC_ACT_015,
	TC_ACT_016,
	TC_ACT_017,
	TC_ACT_018,
	TC_ACT_019,
	TC_ACT_020,
	TC_ACT_021,
	TC_ACT_022,
	TC_ACT_023,
	TC_ACT_INIT = 0x1e,
	TC_ACT_ALL = 0xffffffff
};

struct _anon43
{
	int flg;
	int correct;
};

void(*bhEne29_Mode0)(BH_PWORK*)[6];
void(*bhEne29_BrainType)(BH_PWORK*)[4];
_enum_0 InitBrnMde[4];
char En29FlpTbl[20];
_anon19 Ene29CapColTbl[15];
_anon7 En29ActTbl[40];
_anon14 En29PlyActTbl[2];
_anon40 En29CombWepTbl[21];
_anon43 En29CombJointTbl[21];
_anon1 TypPrm[4];
_anon29 En29DmgDat;
_anon35 E29DmgSet[5];
_anon5* sys;
BH_PWORK* plp;
_anon30 E29OffTbl[20];
int E29EffTbl[4][9];
float lcmat[16][0];

void bhEne29(BH_PWORK* ewP);
void bhEne29_Init(BH_PWORK* ewP);
void bhEne29_Move(BH_PWORK* ewP);
void bhEne29_Die();
void bhEne29_Damage();
void bhEne29_Event(BH_PWORK* ewP);
void bhEne29_Br00(BH_PWORK* ewP);
void bhEne29_Br01(BH_PWORK* ewP);
void bhEne29_Mv00();
void bhEne29_Mv01(BH_PWORK* ewP, _en29_freework* fwP, int count);
void bhEne29_Mv02(BH_PWORK* ewP, _en29_freework* fwP, int count);
void bhEne29_Mv03(BH_PWORK* ewP, _en29_freework* fwP, int count);
void bhEne29_Mv04(BH_PWORK* ewP, _en29_freework* fwP);
void bhEne29_Mv20(BH_PWORK* ewP, _en29_freework* fwP);
void bhEne29_ActionInit(_eaw_typ* eawP, _anon7* act_tblP, int tbl_num);
_anon7* bhEne29_ActionSearch(_eaw_typ* eawP, int act_nw, int act_no);
int bhEne29_ActionChange(BH_PWORK* ewP, _eaw_typ* eawP, int act_dst);
int bhEne29_ActionMain(BH_PWORK* ewP, _eaw_typ* eawP);
void bhEne29_TargetAnalyze(BH_PWORK* ewP, _en29_freework* fwP);
void bhEne29_CalcEnemy(BH_PWORK* ewP, _en29_freework* fwP);
void bhEne29_DmgCheck(BH_PWORK* ewP, _en29_freework* fwP);
int bhEne29_AttackHitCheck(BH_PWORK* ewP, _en29_freework* fwP);
int bhEne29_PlySetDamage(BH_PWORK* plP, _en29_freework* fwP, int dmg_mde);
void bhEne29_PlyMoveMain(BH_PWORK* plP, _en29_freework* fwP);
void bhEne29_PlyActionInit(BH_PWORK* ewP, _anon11* pawP, _anon14* act_tblP, int tbl_num);
void bhEne29_PlyActionMain(BH_PWORK* plP, _anon11* pawP);
int bhEne29_PlyActionChange(BH_PWORK* plP, _anon11* pawP, int act_no);
void bhEne29_PlyDmg117(BH_PWORK* plP, _en29_freework* fwP);
void bhEne29_PlyDmg118(BH_PWORK* plP, _en29_freework* fwP);
void bhEne29_PlyDmgRtn(BH_PWORK* plP, _en29_freework* fwP);
void bhEne29_SetDmgEffect(BH_PWORK* ewP, int eff_typ);
void SetDmgEne(_en29_freework* fwP, _anon35* dsP, int set_num);
void CalcDmgEne(BH_PWORK* ewP, _en29_freework* fwP);
void CheckDmgEne(BH_PWORK* ewP, _en29_freework* fwP);

// 
// Start address: 0x210a00
void bhEne29(BH_PWORK* ewP)
{
	// Line 335, Address: 0x210a00, Func Offset: 0
	// Line 338, Address: 0x210a0c, Func Offset: 0xc
	// Line 340, Address: 0x210a1c, Func Offset: 0x1c
	// Line 357, Address: 0x210a3c, Func Offset: 0x3c
	// Line 361, Address: 0x210a48, Func Offset: 0x48
	// Line 365, Address: 0x210a54, Func Offset: 0x54
	// Func End, Address: 0x210a64, Func Offset: 0x64
}

// 
// Start address: 0x210a70
void bhEne29_Init(BH_PWORK* ewP)
{
	_anon0* oP;
	_anon26* szP;
	_anon4* htP;
	_anon1* etP;
	_anon4* htP;
	_en29_freework* fwP;
	// Line 375, Address: 0x210a70, Func Offset: 0
	// Line 379, Address: 0x210a80, Func Offset: 0x10
	// Line 383, Address: 0x210aa4, Func Offset: 0x34
	// Line 386, Address: 0x210ab4, Func Offset: 0x44
	// Line 395, Address: 0x210abc, Func Offset: 0x4c
	// Line 388, Address: 0x210ac4, Func Offset: 0x54
	// Line 386, Address: 0x210ac8, Func Offset: 0x58
	// Line 390, Address: 0x210ad4, Func Offset: 0x64
	// Line 395, Address: 0x210ad8, Func Offset: 0x68
	// Line 386, Address: 0x210adc, Func Offset: 0x6c
	// Line 387, Address: 0x210b10, Func Offset: 0xa0
	// Line 388, Address: 0x210b1c, Func Offset: 0xac
	// Line 389, Address: 0x210b20, Func Offset: 0xb0
	// Line 390, Address: 0x210b24, Func Offset: 0xb4
	// Line 391, Address: 0x210b28, Func Offset: 0xb8
	// Line 392, Address: 0x210b38, Func Offset: 0xc8
	// Line 395, Address: 0x210b3c, Func Offset: 0xcc
	// Line 398, Address: 0x210b48, Func Offset: 0xd8
	// Line 401, Address: 0x210b4c, Func Offset: 0xdc
	// Line 410, Address: 0x210b50, Func Offset: 0xe0
	// Line 411, Address: 0x210b54, Func Offset: 0xe4
	// Line 414, Address: 0x210b58, Func Offset: 0xe8
	// Line 401, Address: 0x210b5c, Func Offset: 0xec
	// Line 402, Address: 0x210b60, Func Offset: 0xf0
	// Line 403, Address: 0x210b64, Func Offset: 0xf4
	// Line 404, Address: 0x210b68, Func Offset: 0xf8
	// Line 410, Address: 0x210b6c, Func Offset: 0xfc
	// Line 411, Address: 0x210b70, Func Offset: 0x100
	// Line 412, Address: 0x210b74, Func Offset: 0x104
	// Line 413, Address: 0x210b78, Func Offset: 0x108
	// Line 414, Address: 0x210b7c, Func Offset: 0x10c
	// Line 416, Address: 0x210b80, Func Offset: 0x110
	// Line 415, Address: 0x210b84, Func Offset: 0x114
	// Line 416, Address: 0x210b88, Func Offset: 0x118
	// Line 417, Address: 0x210b8c, Func Offset: 0x11c
	// Line 420, Address: 0x210b98, Func Offset: 0x128
	// Line 421, Address: 0x210b9c, Func Offset: 0x12c
	// Line 422, Address: 0x210ba0, Func Offset: 0x130
	// Line 423, Address: 0x210ba4, Func Offset: 0x134
	// Line 426, Address: 0x210ba8, Func Offset: 0x138
	// Line 424, Address: 0x210bac, Func Offset: 0x13c
	// Line 426, Address: 0x210bb0, Func Offset: 0x140
	// Line 425, Address: 0x210bb4, Func Offset: 0x144
	// Line 426, Address: 0x210bb8, Func Offset: 0x148
	// Line 429, Address: 0x210bbc, Func Offset: 0x14c
	// Line 430, Address: 0x210bc0, Func Offset: 0x150
	// Line 435, Address: 0x210bc4, Func Offset: 0x154
	// Line 436, Address: 0x210bc8, Func Offset: 0x158
	// Line 429, Address: 0x210bcc, Func Offset: 0x15c
	// Line 430, Address: 0x210bd4, Func Offset: 0x164
	// Line 437, Address: 0x210bd8, Func Offset: 0x168
	// Line 438, Address: 0x210bdc, Func Offset: 0x16c
	// Line 439, Address: 0x210be0, Func Offset: 0x170
	// Line 430, Address: 0x210be4, Func Offset: 0x174
	// Line 431, Address: 0x210bec, Func Offset: 0x17c
	// Line 446, Address: 0x210bf0, Func Offset: 0x180
	// Line 440, Address: 0x210bf4, Func Offset: 0x184
	// Line 446, Address: 0x210bf8, Func Offset: 0x188
	// Line 431, Address: 0x210bfc, Func Offset: 0x18c
	// Line 435, Address: 0x210c04, Func Offset: 0x194
	// Line 436, Address: 0x210c08, Func Offset: 0x198
	// Line 437, Address: 0x210c0c, Func Offset: 0x19c
	// Line 438, Address: 0x210c10, Func Offset: 0x1a0
	// Line 439, Address: 0x210c14, Func Offset: 0x1a4
	// Line 440, Address: 0x210c20, Func Offset: 0x1b0
	// Line 443, Address: 0x210c24, Func Offset: 0x1b4
	// Line 446, Address: 0x210c2c, Func Offset: 0x1bc
	// Line 448, Address: 0x210c40, Func Offset: 0x1d0
	// Line 449, Address: 0x210c48, Func Offset: 0x1d8
	// Line 450, Address: 0x210c50, Func Offset: 0x1e0
	// Line 451, Address: 0x210c58, Func Offset: 0x1e8
	// Line 452, Address: 0x210c60, Func Offset: 0x1f0
	// Line 453, Address: 0x210c68, Func Offset: 0x1f8
	// Line 458, Address: 0x210c70, Func Offset: 0x200
	// Line 461, Address: 0x210c74, Func Offset: 0x204
	// Line 462, Address: 0x210c80, Func Offset: 0x210
	// Line 463, Address: 0x210c88, Func Offset: 0x218
	// Line 464, Address: 0x210c90, Func Offset: 0x220
	// Line 465, Address: 0x210c98, Func Offset: 0x228
	// Line 470, Address: 0x210cb0, Func Offset: 0x240
	// Line 473, Address: 0x210cc0, Func Offset: 0x250
	// Line 474, Address: 0x210cc8, Func Offset: 0x258
	// Line 475, Address: 0x210ce4, Func Offset: 0x274
	// Line 474, Address: 0x210ce8, Func Offset: 0x278
	// Line 475, Address: 0x210cec, Func Offset: 0x27c
	// Line 476, Address: 0x210cf0, Func Offset: 0x280
	// Line 477, Address: 0x210cf4, Func Offset: 0x284
	// Line 481, Address: 0x210cfc, Func Offset: 0x28c
	// Line 482, Address: 0x210d10, Func Offset: 0x2a0
	// Line 499, Address: 0x210d28, Func Offset: 0x2b8
	// Line 500, Address: 0x210d40, Func Offset: 0x2d0
	// Func End, Address: 0x210d54, Func Offset: 0x2e4
}

// 
// Start address: 0x210d60
void bhEne29_Move(BH_PWORK* ewP)
{
	_en29_freework* fwP;
	_en29_freework* fwP;
	// Line 510, Address: 0x210d60, Func Offset: 0
	// Line 511, Address: 0x210d70, Func Offset: 0x10
	// Line 521, Address: 0x210d78, Func Offset: 0x18
	// Line 519, Address: 0x210d80, Func Offset: 0x20
	// Line 521, Address: 0x210d90, Func Offset: 0x30
	// Line 527, Address: 0x210da0, Func Offset: 0x40
	// Line 528, Address: 0x210db0, Func Offset: 0x50
	// Line 534, Address: 0x210db8, Func Offset: 0x58
	// Line 535, Address: 0x210dbc, Func Offset: 0x5c
	// Line 538, Address: 0x210dc0, Func Offset: 0x60
	// Line 539, Address: 0x210df0, Func Offset: 0x90
	// Line 545, Address: 0x210e20, Func Offset: 0xc0
	// Line 548, Address: 0x210e2c, Func Offset: 0xcc
	// Line 551, Address: 0x210e4c, Func Offset: 0xec
	// Line 554, Address: 0x210e68, Func Offset: 0x108
	// Line 557, Address: 0x210e74, Func Offset: 0x114
	// Line 560, Address: 0x210e94, Func Offset: 0x134
	// Line 562, Address: 0x210ea4, Func Offset: 0x144
	// Func End, Address: 0x210eb8, Func Offset: 0x158
}

// 
// Start address: 0x210ec0
void bhEne29_Die()
{
	// Line 571, Address: 0x210ec0, Func Offset: 0
	// Func End, Address: 0x210ec8, Func Offset: 0x8
}

// 
// Start address: 0x210ed0
void bhEne29_Damage()
{
	// Line 578, Address: 0x210ed0, Func Offset: 0
	// Func End, Address: 0x210ed8, Func Offset: 0x8
}

// 
// Start address: 0x210ee0
void bhEne29_Event(BH_PWORK* ewP)
{
	_en29_freework* fwP;
	// Line 586, Address: 0x210ee0, Func Offset: 0
	// Line 589, Address: 0x210eec, Func Offset: 0xc
	// Line 593, Address: 0x210ef0, Func Offset: 0x10
	// Line 591, Address: 0x210ef8, Func Offset: 0x18
	// Line 593, Address: 0x210f08, Func Offset: 0x28
	// Line 596, Address: 0x210f14, Func Offset: 0x34
	// Line 597, Address: 0x210f1c, Func Offset: 0x3c
	// Line 598, Address: 0x210f30, Func Offset: 0x50
	// Line 599, Address: 0x210f3c, Func Offset: 0x5c
	// Func End, Address: 0x210f4c, Func Offset: 0x6c
}

// 
// Start address: 0x210f50
void bhEne29_Br00(BH_PWORK* ewP)
{
	int lop;
	int rte;
	_enum_4 act;
	_enum_1* br1P;
	_enum_0* br0P;
	int sts;
	int typ;
	int* stsP;
	_eaw_typ* eawP;
	_en29_freework* fwP;
	// Line 612, Address: 0x210f50, Func Offset: 0
	// Line 624, Address: 0x210f6c, Func Offset: 0x1c
	// Line 613, Address: 0x210f74, Func Offset: 0x24
	// Line 620, Address: 0x210f78, Func Offset: 0x28
	// Line 624, Address: 0x210f84, Func Offset: 0x34
	// Line 614, Address: 0x210f90, Func Offset: 0x40
	// Line 620, Address: 0x210f94, Func Offset: 0x44
	// Line 616, Address: 0x210f98, Func Offset: 0x48
	// Line 624, Address: 0x210f9c, Func Offset: 0x4c
	// Line 625, Address: 0x210fa8, Func Offset: 0x58
	// Line 628, Address: 0x210fac, Func Offset: 0x5c
	// Line 625, Address: 0x210fb0, Func Offset: 0x60
	// Line 628, Address: 0x210fb4, Func Offset: 0x64
	// Line 632, Address: 0x210fbc, Func Offset: 0x6c
	// Line 636, Address: 0x210fc4, Func Offset: 0x74
	// Line 633, Address: 0x210fc8, Func Offset: 0x78
	// Line 634, Address: 0x210fcc, Func Offset: 0x7c
	// Line 635, Address: 0x210fd4, Func Offset: 0x84
	// Line 637, Address: 0x210fd8, Func Offset: 0x88
	// Line 641, Address: 0x210fe0, Func Offset: 0x90
	// Line 651, Address: 0x210fec, Func Offset: 0x9c
	// Line 652, Address: 0x210ffc, Func Offset: 0xac
	// Line 653, Address: 0x211008, Func Offset: 0xb8
	// Line 654, Address: 0x21101c, Func Offset: 0xcc
	// Line 656, Address: 0x211020, Func Offset: 0xd0
	// Line 657, Address: 0x211028, Func Offset: 0xd8
	// Line 658, Address: 0x211034, Func Offset: 0xe4
	// Line 659, Address: 0x211038, Func Offset: 0xe8
	// Line 668, Address: 0x21103c, Func Offset: 0xec
	// Line 670, Address: 0x211040, Func Offset: 0xf0
	// Line 673, Address: 0x211078, Func Offset: 0x128
	// Line 674, Address: 0x211084, Func Offset: 0x134
	// Line 676, Address: 0x21108c, Func Offset: 0x13c
	// Line 677, Address: 0x211094, Func Offset: 0x144
	// Line 678, Address: 0x2110b4, Func Offset: 0x164
	// Line 679, Address: 0x2110b8, Func Offset: 0x168
	// Line 681, Address: 0x2110bc, Func Offset: 0x16c
	// Line 682, Address: 0x2110c4, Func Offset: 0x174
	// Line 684, Address: 0x2110c8, Func Offset: 0x178
	// Line 686, Address: 0x2110dc, Func Offset: 0x18c
	// Line 689, Address: 0x2110e4, Func Offset: 0x194
	// Line 693, Address: 0x211108, Func Offset: 0x1b8
	// Line 694, Address: 0x21110c, Func Offset: 0x1bc
	// Line 697, Address: 0x211114, Func Offset: 0x1c4
	// Line 699, Address: 0x21111c, Func Offset: 0x1cc
	// Line 701, Address: 0x211120, Func Offset: 0x1d0
	// Line 704, Address: 0x211128, Func Offset: 0x1d8
	// Line 706, Address: 0x211138, Func Offset: 0x1e8
	// Line 711, Address: 0x21113c, Func Offset: 0x1ec
	// Line 714, Address: 0x211144, Func Offset: 0x1f4
	// Line 717, Address: 0x21116c, Func Offset: 0x21c
	// Line 719, Address: 0x211178, Func Offset: 0x228
	// Line 720, Address: 0x21117c, Func Offset: 0x22c
	// Line 721, Address: 0x211184, Func Offset: 0x234
	// Line 722, Address: 0x2111a0, Func Offset: 0x250
	// Line 724, Address: 0x2111a4, Func Offset: 0x254
	// Line 730, Address: 0x2111ac, Func Offset: 0x25c
	// Line 732, Address: 0x2111bc, Func Offset: 0x26c
	// Line 738, Address: 0x2111c4, Func Offset: 0x274
	// Line 744, Address: 0x2111d0, Func Offset: 0x280
	// Line 747, Address: 0x2111d8, Func Offset: 0x288
	// Line 750, Address: 0x211204, Func Offset: 0x2b4
	// Line 752, Address: 0x211208, Func Offset: 0x2b8
	// Line 755, Address: 0x211210, Func Offset: 0x2c0
	// Line 756, Address: 0x211220, Func Offset: 0x2d0
	// Line 757, Address: 0x21122c, Func Offset: 0x2dc
	// Line 758, Address: 0x211230, Func Offset: 0x2e0
	// Line 767, Address: 0x211234, Func Offset: 0x2e4
	// Line 768, Address: 0x211238, Func Offset: 0x2e8
	// Line 771, Address: 0x211244, Func Offset: 0x2f4
	// Line 772, Address: 0x211250, Func Offset: 0x300
	// Line 773, Address: 0x211264, Func Offset: 0x314
	// Line 775, Address: 0x211268, Func Offset: 0x318
	// Line 780, Address: 0x211274, Func Offset: 0x324
	// Func End, Address: 0x211294, Func Offset: 0x344
}

// 
// Start address: 0x2112a0
void bhEne29_Br01(BH_PWORK* ewP)
{
	int lop;
	int rte;
	_enum_4 act;
	_enum_1* br1P;
	_enum_0* br0P;
	int sts;
	int typ;
	int* stsP;
	_eaw_typ* eawP;
	_en29_freework* fwP;
	// Line 790, Address: 0x2112a0, Func Offset: 0
	// Line 791, Address: 0x2112bc, Func Offset: 0x1c
	// Line 798, Address: 0x2112c0, Func Offset: 0x20
	// Line 792, Address: 0x2112cc, Func Offset: 0x2c
	// Line 798, Address: 0x2112d0, Func Offset: 0x30
	// Line 802, Address: 0x2112e4, Func Offset: 0x44
	// Line 806, Address: 0x2112ec, Func Offset: 0x4c
	// Line 802, Address: 0x2112f4, Func Offset: 0x54
	// Line 803, Address: 0x21130c, Func Offset: 0x6c
	// Line 806, Address: 0x211314, Func Offset: 0x74
	// Line 810, Address: 0x21131c, Func Offset: 0x7c
	// Line 814, Address: 0x211324, Func Offset: 0x84
	// Line 815, Address: 0x211328, Func Offset: 0x88
	// Line 811, Address: 0x211334, Func Offset: 0x94
	// Line 812, Address: 0x211338, Func Offset: 0x98
	// Line 813, Address: 0x21133c, Func Offset: 0x9c
	// Line 815, Address: 0x211340, Func Offset: 0xa0
	// Line 818, Address: 0x21134c, Func Offset: 0xac
	// Line 828, Address: 0x211358, Func Offset: 0xb8
	// Line 829, Address: 0x211368, Func Offset: 0xc8
	// Line 830, Address: 0x211374, Func Offset: 0xd4
	// Line 831, Address: 0x211388, Func Offset: 0xe8
	// Line 833, Address: 0x211390, Func Offset: 0xf0
	// Line 834, Address: 0x211398, Func Offset: 0xf8
	// Line 835, Address: 0x2113a4, Func Offset: 0x104
	// Line 836, Address: 0x2113a8, Func Offset: 0x108
	// Line 845, Address: 0x2113ac, Func Offset: 0x10c
	// Line 847, Address: 0x2113b0, Func Offset: 0x110
	// Line 850, Address: 0x2113f4, Func Offset: 0x154
	// Line 851, Address: 0x211400, Func Offset: 0x160
	// Line 853, Address: 0x211408, Func Offset: 0x168
	// Line 854, Address: 0x211410, Func Offset: 0x170
	// Line 855, Address: 0x211430, Func Offset: 0x190
	// Line 856, Address: 0x211434, Func Offset: 0x194
	// Line 858, Address: 0x211438, Func Offset: 0x198
	// Line 859, Address: 0x211440, Func Offset: 0x1a0
	// Line 861, Address: 0x211448, Func Offset: 0x1a8
	// Line 863, Address: 0x211460, Func Offset: 0x1c0
	// Line 866, Address: 0x211468, Func Offset: 0x1c8
	// Line 869, Address: 0x21148c, Func Offset: 0x1ec
	// Line 871, Address: 0x211490, Func Offset: 0x1f0
	// Line 874, Address: 0x211498, Func Offset: 0x1f8
	// Line 876, Address: 0x2114a0, Func Offset: 0x200
	// Line 875, Address: 0x2114a4, Func Offset: 0x204
	// Line 878, Address: 0x2114a8, Func Offset: 0x208
	// Line 881, Address: 0x2114b0, Func Offset: 0x210
	// Line 883, Address: 0x2114c0, Func Offset: 0x220
	// Line 882, Address: 0x2114c4, Func Offset: 0x224
	// Line 887, Address: 0x2114c8, Func Offset: 0x228
	// Line 890, Address: 0x2114d0, Func Offset: 0x230
	// Line 893, Address: 0x2114f8, Func Offset: 0x258
	// Line 894, Address: 0x211504, Func Offset: 0x264
	// Line 896, Address: 0x211508, Func Offset: 0x268
	// Line 897, Address: 0x211510, Func Offset: 0x270
	// Line 898, Address: 0x211530, Func Offset: 0x290
	// Line 900, Address: 0x211534, Func Offset: 0x294
	// Line 906, Address: 0x21153c, Func Offset: 0x29c
	// Line 908, Address: 0x21154c, Func Offset: 0x2ac
	// Line 914, Address: 0x211554, Func Offset: 0x2b4
	// Line 920, Address: 0x211560, Func Offset: 0x2c0
	// Line 923, Address: 0x211568, Func Offset: 0x2c8
	// Line 926, Address: 0x211594, Func Offset: 0x2f4
	// Line 928, Address: 0x211598, Func Offset: 0x2f8
	// Line 931, Address: 0x2115a0, Func Offset: 0x300
	// Line 932, Address: 0x2115b0, Func Offset: 0x310
	// Line 933, Address: 0x2115bc, Func Offset: 0x31c
	// Line 942, Address: 0x2115c0, Func Offset: 0x320
	// Line 945, Address: 0x2115c8, Func Offset: 0x328
	// Line 948, Address: 0x2115f4, Func Offset: 0x354
	// Line 950, Address: 0x2115f8, Func Offset: 0x358
	// Line 954, Address: 0x211600, Func Offset: 0x360
	// Line 955, Address: 0x211618, Func Offset: 0x378
	// Line 956, Address: 0x21161c, Func Offset: 0x37c
	// Line 957, Address: 0x211628, Func Offset: 0x388
	// Line 958, Address: 0x211630, Func Offset: 0x390
	// Line 959, Address: 0x211638, Func Offset: 0x398
	// Line 962, Address: 0x211640, Func Offset: 0x3a0
	// Line 966, Address: 0x211654, Func Offset: 0x3b4
	// Line 968, Address: 0x211658, Func Offset: 0x3b8
	// Line 971, Address: 0x211664, Func Offset: 0x3c4
	// Line 972, Address: 0x211670, Func Offset: 0x3d0
	// Line 973, Address: 0x211684, Func Offset: 0x3e4
	// Line 974, Address: 0x211688, Func Offset: 0x3e8
	// Line 978, Address: 0x211694, Func Offset: 0x3f4
	// Func End, Address: 0x2116b4, Func Offset: 0x414
}

// 
// Start address: 0x2116c0
void bhEne29_Mv00()
{
	// Line 989, Address: 0x2116c0, Func Offset: 0
	// Func End, Address: 0x2116c8, Func Offset: 0x8
}

// 
// Start address: 0x2116d0
void bhEne29_Mv01(BH_PWORK* ewP, _en29_freework* fwP, int count)
{
	// Line 1001, Address: 0x2116d0, Func Offset: 0
	// Line 1002, Address: 0x2116e4, Func Offset: 0x14
	// Line 1003, Address: 0x2116ec, Func Offset: 0x1c
	// Line 1006, Address: 0x21172c, Func Offset: 0x5c
	// Line 1007, Address: 0x211744, Func Offset: 0x74
	// Line 1008, Address: 0x211758, Func Offset: 0x88
	// Line 1011, Address: 0x211764, Func Offset: 0x94
	// Func End, Address: 0x211778, Func Offset: 0xa8
}

// 
// Start address: 0x211780
void bhEne29_Mv02(BH_PWORK* ewP, _en29_freework* fwP, int count)
{
	// Line 1023, Address: 0x211780, Func Offset: 0
	// Line 1024, Address: 0x211784, Func Offset: 0x4
	// Line 1025, Address: 0x21178c, Func Offset: 0xc
	// Line 1027, Address: 0x2117cc, Func Offset: 0x4c
	// Func End, Address: 0x2117d8, Func Offset: 0x58
}

// 
// Start address: 0x2117e0
void bhEne29_Mv03(BH_PWORK* ewP, _en29_freework* fwP, int count)
{
	// Line 1039, Address: 0x2117e0, Func Offset: 0
	// Line 1040, Address: 0x2117f4, Func Offset: 0x14
	// Line 1041, Address: 0x2117fc, Func Offset: 0x1c
	// Line 1044, Address: 0x21183c, Func Offset: 0x5c
	// Line 1045, Address: 0x211854, Func Offset: 0x74
	// Line 1046, Address: 0x211868, Func Offset: 0x88
	// Line 1048, Address: 0x211874, Func Offset: 0x94
	// Func End, Address: 0x211888, Func Offset: 0xa8
}

// 
// Start address: 0x211890
void bhEne29_Mv04(BH_PWORK* ewP, _en29_freework* fwP)
{
	// Line 1060, Address: 0x211890, Func Offset: 0
	// Line 1063, Address: 0x2118a0, Func Offset: 0x10
	// Line 1064, Address: 0x2118b8, Func Offset: 0x28
	// Line 1065, Address: 0x2118e0, Func Offset: 0x50
	// Line 1070, Address: 0x211920, Func Offset: 0x90
	// Func End, Address: 0x211934, Func Offset: 0xa4
}

// 
// Start address: 0x211940
void bhEne29_Mv20(BH_PWORK* ewP, _en29_freework* fwP)
{
	// Line 1082, Address: 0x211940, Func Offset: 0
	// Line 1083, Address: 0x21194c, Func Offset: 0xc
	// Line 1084, Address: 0x211960, Func Offset: 0x20
	// Line 1085, Address: 0x211974, Func Offset: 0x34
	// Line 1087, Address: 0x211980, Func Offset: 0x40
	// Func End, Address: 0x211990, Func Offset: 0x50
}

// 
// Start address: 0x211990
void bhEne29_ActionInit(_eaw_typ* eawP, _anon7* act_tblP, int tbl_num)
{
	// Line 1100, Address: 0x211990, Func Offset: 0
	// Line 1102, Address: 0x211994, Func Offset: 0x4
	// Line 1101, Address: 0x211998, Func Offset: 0x8
	// Line 1103, Address: 0x21199c, Func Offset: 0xc
	// Func End, Address: 0x2119a4, Func Offset: 0x14
}

// 
// Start address: 0x2119b0
_anon7* bhEne29_ActionSearch(_eaw_typ* eawP, int act_nw, int act_no)
{
	int val;
	int middle;
	int low;
	int high;
	int key;
	_anon7* eaP;
	// Line 1118, Address: 0x2119b0, Func Offset: 0
	// Line 1117, Address: 0x2119c0, Func Offset: 0x10
	// Line 1119, Address: 0x2119c4, Func Offset: 0x14
	// Line 1122, Address: 0x2119c8, Func Offset: 0x18
	// Line 1124, Address: 0x2119d4, Func Offset: 0x24
	// Line 1125, Address: 0x2119dc, Func Offset: 0x2c
	// Line 1127, Address: 0x2119f0, Func Offset: 0x40
	// Line 1128, Address: 0x2119f8, Func Offset: 0x48
	// Line 1130, Address: 0x211a08, Func Offset: 0x58
	// Line 1135, Address: 0x211a14, Func Offset: 0x64
	// Line 1138, Address: 0x211a20, Func Offset: 0x70
	// Line 1139, Address: 0x211a24, Func Offset: 0x74
	// Func End, Address: 0x211a2c, Func Offset: 0x7c
}

// 
// Start address: 0x211a30
int bhEne29_ActionChange(BH_PWORK* ewP, _eaw_typ* eawP, int act_dst)
{
	_anon7* eaP;
	// Line 1151, Address: 0x211a30, Func Offset: 0
	// Line 1156, Address: 0x211a4c, Func Offset: 0x1c
	// Line 1157, Address: 0x211a68, Func Offset: 0x38
	// Line 1158, Address: 0x211a74, Func Offset: 0x44
	// Line 1163, Address: 0x211a88, Func Offset: 0x58
	// Line 1165, Address: 0x211a90, Func Offset: 0x60
	// Line 1168, Address: 0x211aa0, Func Offset: 0x70
	// Line 1171, Address: 0x211aa8, Func Offset: 0x78
	// Line 1174, Address: 0x211aac, Func Offset: 0x7c
	// Line 1175, Address: 0x211ab4, Func Offset: 0x84
	// Line 1176, Address: 0x211ab8, Func Offset: 0x88
	// Line 1179, Address: 0x211ac0, Func Offset: 0x90
	// Line 1180, Address: 0x211ac8, Func Offset: 0x98
	// Line 1181, Address: 0x211ad4, Func Offset: 0xa4
	// Line 1182, Address: 0x211b08, Func Offset: 0xd8
	// Line 1184, Address: 0x211b0c, Func Offset: 0xdc
	// Line 1182, Address: 0x211b10, Func Offset: 0xe0
	// Line 1184, Address: 0x211b14, Func Offset: 0xe4
	// Line 1186, Address: 0x211b2c, Func Offset: 0xfc
	// Line 1187, Address: 0x211b48, Func Offset: 0x118
	// Line 1189, Address: 0x211b50, Func Offset: 0x120
	// Line 1192, Address: 0x211b54, Func Offset: 0x124
	// Line 1189, Address: 0x211b5c, Func Offset: 0x12c
	// Line 1192, Address: 0x211b60, Func Offset: 0x130
	// Line 1197, Address: 0x211b70, Func Offset: 0x140
	// Line 1200, Address: 0x211b7c, Func Offset: 0x14c
	// Line 1204, Address: 0x211b80, Func Offset: 0x150
	// Func End, Address: 0x211b9c, Func Offset: 0x16c
}

// 
// Start address: 0x211ba0
int bhEne29_ActionMain(BH_PWORK* ewP, _eaw_typ* eawP)
{
	short* s16P;
	// Line 1215, Address: 0x211ba0, Func Offset: 0
	// Line 1217, Address: 0x211bb4, Func Offset: 0x14
	// Line 1223, Address: 0x211bdc, Func Offset: 0x3c
	// Line 1221, Address: 0x211be8, Func Offset: 0x48
	// Line 1223, Address: 0x211bec, Func Offset: 0x4c
	// Line 1224, Address: 0x211c08, Func Offset: 0x68
	// Line 1228, Address: 0x211c14, Func Offset: 0x74
	// Line 1230, Address: 0x211c48, Func Offset: 0xa8
	// Line 1228, Address: 0x211c4c, Func Offset: 0xac
	// Line 1231, Address: 0x211c50, Func Offset: 0xb0
	// Func End, Address: 0x211c68, Func Offset: 0xc8
}

// 
// Start address: 0x211c70
void bhEne29_TargetAnalyze(BH_PWORK* ewP, _en29_freework* fwP)
{
	float dst;
	_anon26 dlt;
	int dlt;
	int ad;
	_anon26 dlt;
	_anon26* vP;
	int* stsP;
	// Line 1242, Address: 0x211c70, Func Offset: 0
	// Line 1246, Address: 0x211c88, Func Offset: 0x18
	// Line 1243, Address: 0x211c90, Func Offset: 0x20
	// Line 1246, Address: 0x211c94, Func Offset: 0x24
	// Line 1247, Address: 0x211ca0, Func Offset: 0x30
	// Line 1253, Address: 0x211cd0, Func Offset: 0x60
	// Line 1254, Address: 0x211cec, Func Offset: 0x7c
	// Line 1255, Address: 0x211d10, Func Offset: 0xa0
	// Line 1262, Address: 0x211d34, Func Offset: 0xc4
	// Line 1263, Address: 0x211d40, Func Offset: 0xd0
	// Line 1262, Address: 0x211d44, Func Offset: 0xd4
	// Line 1263, Address: 0x211d6c, Func Offset: 0xfc
	// Line 1266, Address: 0x211d74, Func Offset: 0x104
	// Line 1268, Address: 0x211d98, Func Offset: 0x128
	// Line 1266, Address: 0x211da0, Func Offset: 0x130
	// Line 1268, Address: 0x211da4, Func Offset: 0x134
	// Line 1266, Address: 0x211dac, Func Offset: 0x13c
	// Line 1269, Address: 0x211db4, Func Offset: 0x144
	// Line 1270, Address: 0x211dcc, Func Offset: 0x15c
	// Line 1278, Address: 0x211dd8, Func Offset: 0x168
	// Line 1280, Address: 0x211df0, Func Offset: 0x180
	// Line 1281, Address: 0x211dfc, Func Offset: 0x18c
	// Line 1282, Address: 0x211e04, Func Offset: 0x194
	// Line 1284, Address: 0x211e0c, Func Offset: 0x19c
	// Line 1292, Address: 0x211e10, Func Offset: 0x1a0
	// Line 1294, Address: 0x211e18, Func Offset: 0x1a8
	// Line 1295, Address: 0x211e1c, Func Offset: 0x1ac
	// Line 1292, Address: 0x211e20, Func Offset: 0x1b0
	// Line 1294, Address: 0x211e28, Func Offset: 0x1b8
	// Line 1295, Address: 0x211e58, Func Offset: 0x1e8
	// Line 1296, Address: 0x211e60, Func Offset: 0x1f0
	// Line 1297, Address: 0x211e6c, Func Offset: 0x1fc
	// Line 1296, Address: 0x211e70, Func Offset: 0x200
	// Line 1297, Address: 0x211e78, Func Offset: 0x208
	// Line 1299, Address: 0x211e9c, Func Offset: 0x22c
	// Line 1300, Address: 0x211ea8, Func Offset: 0x238
	// Line 1299, Address: 0x211eac, Func Offset: 0x23c
	// Line 1300, Address: 0x211ed4, Func Offset: 0x264
	// Line 1302, Address: 0x211edc, Func Offset: 0x26c
	// Line 1301, Address: 0x211ee0, Func Offset: 0x270
	// Line 1302, Address: 0x211ee8, Func Offset: 0x278
	// Line 1301, Address: 0x211eec, Func Offset: 0x27c
	// Line 1302, Address: 0x211ef4, Func Offset: 0x284
	// Line 1307, Address: 0x211f10, Func Offset: 0x2a0
	// Func End, Address: 0x211f2c, Func Offset: 0x2bc
}

// 
// Start address: 0x211f30
void bhEne29_CalcEnemy(BH_PWORK* ewP, _en29_freework* fwP)
{
	_anon4* htP;
	// Line 1318, Address: 0x211f30, Func Offset: 0
	// Line 1322, Address: 0x211f44, Func Offset: 0x14
	// Line 1325, Address: 0x211f4c, Func Offset: 0x1c
	// Line 1331, Address: 0x211f58, Func Offset: 0x28
	// Line 1329, Address: 0x211f60, Func Offset: 0x30
	// Line 1331, Address: 0x211f64, Func Offset: 0x34
	// Line 1332, Address: 0x211f80, Func Offset: 0x50
	// Line 1338, Address: 0x211fa4, Func Offset: 0x74
	// Func End, Address: 0x211fb8, Func Offset: 0x88
}

// 
// Start address: 0x211fc0
void bhEne29_DmgCheck(BH_PWORK* ewP, _en29_freework* fwP)
{
	_anon31* ddP;
	int dmg_obj;
	_anon31 DmgDat[21];
	// Line 1349, Address: 0x211fc0, Func Offset: 0
	// Line 1377, Address: 0x211fd8, Func Offset: 0x18
	// Line 1379, Address: 0x211fe0, Func Offset: 0x20
	// Line 1383, Address: 0x211ff0, Func Offset: 0x30
	// Line 1386, Address: 0x211ffc, Func Offset: 0x3c
	// Line 1393, Address: 0x212014, Func Offset: 0x54
	// Line 1387, Address: 0x21201c, Func Offset: 0x5c
	// Line 1393, Address: 0x212020, Func Offset: 0x60
	// Line 1411, Address: 0x212028, Func Offset: 0x68
	// Line 1413, Address: 0x21202c, Func Offset: 0x6c
	// Line 1415, Address: 0x212038, Func Offset: 0x78
	// Line 1419, Address: 0x212044, Func Offset: 0x84
	// Line 1415, Address: 0x212048, Func Offset: 0x88
	// Line 1419, Address: 0x21204c, Func Offset: 0x8c
	// Line 1420, Address: 0x212058, Func Offset: 0x98
	// Line 1421, Address: 0x212064, Func Offset: 0xa4
	// Line 1423, Address: 0x212070, Func Offset: 0xb0
	// Line 1424, Address: 0x21207c, Func Offset: 0xbc
	// Line 1429, Address: 0x212084, Func Offset: 0xc4
	// Line 1430, Address: 0x2120a0, Func Offset: 0xe0
	// Line 1433, Address: 0x2120ac, Func Offset: 0xec
	// Line 1438, Address: 0x2120b8, Func Offset: 0xf8
	// Line 1439, Address: 0x2120c8, Func Offset: 0x108
	// Line 1440, Address: 0x2120d0, Func Offset: 0x110
	// Line 1441, Address: 0x2120d4, Func Offset: 0x114
	// Line 1442, Address: 0x2120dc, Func Offset: 0x11c
	// Line 1443, Address: 0x2120e8, Func Offset: 0x128
	// Line 1444, Address: 0x2120f0, Func Offset: 0x130
	// Line 1448, Address: 0x2120f8, Func Offset: 0x138
	// Line 1449, Address: 0x212114, Func Offset: 0x154
	// Line 1451, Address: 0x212118, Func Offset: 0x158
	// Line 1452, Address: 0x212120, Func Offset: 0x160
	// Line 1455, Address: 0x212124, Func Offset: 0x164
	// Line 1456, Address: 0x212130, Func Offset: 0x170
	// Line 1458, Address: 0x212138, Func Offset: 0x178
	// Line 1463, Address: 0x212154, Func Offset: 0x194
	// Line 1466, Address: 0x212168, Func Offset: 0x1a8
	// Line 1467, Address: 0x21217c, Func Offset: 0x1bc
	// Func End, Address: 0x212194, Func Offset: 0x1d4
}

// 
// Start address: 0x2121a0
int bhEne29_AttackHitCheck(BH_PWORK* ewP, _en29_freework* fwP)
{
	int ang;
	int i;
	_anon41 spr;
	_anon28 E29Cll[6];
	// Line 1478, Address: 0x2121a0, Func Offset: 0
	// Line 1489, Address: 0x2121c8, Func Offset: 0x28
	// Line 1494, Address: 0x2121cc, Func Offset: 0x2c
	// Line 1502, Address: 0x2121dc, Func Offset: 0x3c
	// Line 1494, Address: 0x2121e0, Func Offset: 0x40
	// Line 1502, Address: 0x21220c, Func Offset: 0x6c
	// Line 1495, Address: 0x212210, Func Offset: 0x70
	// Line 1502, Address: 0x21221c, Func Offset: 0x7c
	// Line 1507, Address: 0x212244, Func Offset: 0xa4
	// Line 1508, Address: 0x21225c, Func Offset: 0xbc
	// Line 1510, Address: 0x212260, Func Offset: 0xc0
	// Line 1512, Address: 0x212274, Func Offset: 0xd4
	// Line 1510, Address: 0x212278, Func Offset: 0xd8
	// Line 1512, Address: 0x212280, Func Offset: 0xe0
	// Line 1515, Address: 0x212294, Func Offset: 0xf4
	// Line 1512, Address: 0x212298, Func Offset: 0xf8
	// Line 1515, Address: 0x2122a0, Func Offset: 0x100
	// Line 1518, Address: 0x2122a8, Func Offset: 0x108
	// Line 1520, Address: 0x2122b8, Func Offset: 0x118
	// Line 1522, Address: 0x2122bc, Func Offset: 0x11c
	// Func End, Address: 0x2122d8, Func Offset: 0x138
}

// 
// Start address: 0x2122e0
int bhEne29_PlySetDamage(BH_PWORK* plP, _en29_freework* fwP, int dmg_mde)
{
	int dir_mde;
	int PlyDmgTbl[4];
	// Line 1533, Address: 0x2122e0, Func Offset: 0
	// Line 1543, Address: 0x2122f0, Func Offset: 0x10
	// Line 1533, Address: 0x2122f4, Func Offset: 0x14
	// Line 1543, Address: 0x2122fc, Func Offset: 0x1c
	// Line 1545, Address: 0x212308, Func Offset: 0x28
	// Line 1549, Address: 0x212318, Func Offset: 0x38
	// Line 1551, Address: 0x212338, Func Offset: 0x58
	// Line 1552, Address: 0x21234c, Func Offset: 0x6c
	// Line 1553, Address: 0x212358, Func Offset: 0x78
	// Line 1554, Address: 0x212360, Func Offset: 0x80
	// Line 1557, Address: 0x212370, Func Offset: 0x90
	// Line 1558, Address: 0x21237c, Func Offset: 0x9c
	// Line 1564, Address: 0x212384, Func Offset: 0xa4
	// Line 1565, Address: 0x212390, Func Offset: 0xb0
	// Line 1566, Address: 0x212398, Func Offset: 0xb8
	// Line 1564, Address: 0x21239c, Func Offset: 0xbc
	// Line 1565, Address: 0x2123a4, Func Offset: 0xc4
	// Line 1572, Address: 0x2123a8, Func Offset: 0xc8
	// Line 1565, Address: 0x2123ac, Func Offset: 0xcc
	// Line 1566, Address: 0x2123b4, Func Offset: 0xd4
	// Line 1567, Address: 0x2123b8, Func Offset: 0xd8
	// Line 1568, Address: 0x2123bc, Func Offset: 0xdc
	// Line 1569, Address: 0x2123c0, Func Offset: 0xe0
	// Line 1572, Address: 0x2123c4, Func Offset: 0xe4
	// Line 1574, Address: 0x2123c8, Func Offset: 0xe8
	// Line 1577, Address: 0x2123cc, Func Offset: 0xec
	// Line 1578, Address: 0x2123d4, Func Offset: 0xf4
	// Line 1581, Address: 0x2123dc, Func Offset: 0xfc
	// Line 1582, Address: 0x2123e8, Func Offset: 0x108
	// Line 1583, Address: 0x2123f0, Func Offset: 0x110
	// Line 1581, Address: 0x2123f4, Func Offset: 0x114
	// Line 1582, Address: 0x2123fc, Func Offset: 0x11c
	// Line 1592, Address: 0x212400, Func Offset: 0x120
	// Line 1582, Address: 0x212404, Func Offset: 0x124
	// Line 1583, Address: 0x21240c, Func Offset: 0x12c
	// Line 1584, Address: 0x212410, Func Offset: 0x130
	// Line 1585, Address: 0x212414, Func Offset: 0x134
	// Line 1586, Address: 0x212418, Func Offset: 0x138
	// Line 1589, Address: 0x21241c, Func Offset: 0x13c
	// Line 1592, Address: 0x212420, Func Offset: 0x140
	// Line 1595, Address: 0x212424, Func Offset: 0x144
	// Line 1598, Address: 0x212428, Func Offset: 0x148
	// Line 1603, Address: 0x212430, Func Offset: 0x150
	// Line 1604, Address: 0x212434, Func Offset: 0x154
	// Func End, Address: 0x21244c, Func Offset: 0x16c
}

// 
// Start address: 0x212450
void bhEne29_PlyMoveMain(BH_PWORK* plP, _en29_freework* fwP)
{
	int lop;
	int act;
	int* br1P;
	int* br0P;
	int* stsP;
	// Line 1615, Address: 0x212450, Func Offset: 0
	// Line 1618, Address: 0x212474, Func Offset: 0x24
	// Line 1616, Address: 0x21247c, Func Offset: 0x2c
	// Line 1618, Address: 0x212480, Func Offset: 0x30
	// Line 1620, Address: 0x21248c, Func Offset: 0x3c
	// Line 1621, Address: 0x212490, Func Offset: 0x40
	// Line 1622, Address: 0x212494, Func Offset: 0x44
	// Line 1623, Address: 0x212498, Func Offset: 0x48
	// Line 1626, Address: 0x21249c, Func Offset: 0x4c
	// Line 1628, Address: 0x2124c8, Func Offset: 0x78
	// Line 1637, Address: 0x2124d4, Func Offset: 0x84
	// Line 1646, Address: 0x2124e0, Func Offset: 0x90
	// Line 1651, Address: 0x2124e8, Func Offset: 0x98
	// Line 1646, Address: 0x2124f8, Func Offset: 0xa8
	// Line 1647, Address: 0x212500, Func Offset: 0xb0
	// Line 1651, Address: 0x212510, Func Offset: 0xc0
	// Line 1652, Address: 0x21251c, Func Offset: 0xcc
	// Line 1653, Address: 0x212528, Func Offset: 0xd8
	// Line 1656, Address: 0x212568, Func Offset: 0x118
	// Line 1658, Address: 0x212574, Func Offset: 0x124
	// Line 1659, Address: 0x212590, Func Offset: 0x140
	// Line 1661, Address: 0x21259c, Func Offset: 0x14c
	// Func End, Address: 0x2125c4, Func Offset: 0x174
}

// 
// Start address: 0x2125d0
void bhEne29_PlyActionInit(BH_PWORK* ewP, _anon11* pawP, _anon14* act_tblP, int tbl_num)
{
	// Line 1676, Address: 0x2125d0, Func Offset: 0
	// Line 1678, Address: 0x2125d4, Func Offset: 0x4
	// Line 1677, Address: 0x2125d8, Func Offset: 0x8
	// Line 1678, Address: 0x2125dc, Func Offset: 0xc
	// Line 1679, Address: 0x2125e0, Func Offset: 0x10
	// Line 1680, Address: 0x2125e8, Func Offset: 0x18
	// Line 1681, Address: 0x2125ec, Func Offset: 0x1c
	// Func End, Address: 0x2125f4, Func Offset: 0x24
}

// 
// Start address: 0x212600
void bhEne29_PlyActionMain(BH_PWORK* plP, _anon11* pawP)
{
	// Line 1692, Address: 0x212600, Func Offset: 0
	// Line 1694, Address: 0x212610, Func Offset: 0x10
	// Line 1695, Address: 0x212628, Func Offset: 0x28
	// Line 1696, Address: 0x212634, Func Offset: 0x34
	// Line 1700, Address: 0x21263c, Func Offset: 0x3c
	// Line 1703, Address: 0x21265c, Func Offset: 0x5c
	// Line 1706, Address: 0x212674, Func Offset: 0x74
	// Line 1709, Address: 0x212680, Func Offset: 0x80
	// Line 1710, Address: 0x2126a0, Func Offset: 0xa0
	// Func End, Address: 0x2126b4, Func Offset: 0xb4
}

// 
// Start address: 0x2126c0
int bhEne29_PlyActionChange(BH_PWORK* plP, _anon11* pawP, int act_no)
{
	_anon14* paP;
	// Line 1721, Address: 0x2126c0, Func Offset: 0
	// Line 1724, Address: 0x2126d4, Func Offset: 0x14
	// Line 1722, Address: 0x2126d8, Func Offset: 0x18
	// Line 1724, Address: 0x2126e8, Func Offset: 0x28
	// Line 1727, Address: 0x212700, Func Offset: 0x40
	// Line 1729, Address: 0x212704, Func Offset: 0x44
	// Line 1727, Address: 0x212708, Func Offset: 0x48
	// Line 1728, Address: 0x21270c, Func Offset: 0x4c
	// Line 1731, Address: 0x212710, Func Offset: 0x50
	// Line 1733, Address: 0x212718, Func Offset: 0x58
	// Line 1734, Address: 0x212720, Func Offset: 0x60
	// Line 1735, Address: 0x212728, Func Offset: 0x68
	// Line 1736, Address: 0x212734, Func Offset: 0x74
	// Line 1737, Address: 0x21273c, Func Offset: 0x7c
	// Line 1738, Address: 0x212770, Func Offset: 0xb0
	// Line 1739, Address: 0x212778, Func Offset: 0xb8
	// Line 1745, Address: 0x21277c, Func Offset: 0xbc
	// Line 1739, Address: 0x212780, Func Offset: 0xc0
	// Line 1742, Address: 0x212784, Func Offset: 0xc4
	// Line 1743, Address: 0x2127a4, Func Offset: 0xe4
	// Line 1744, Address: 0x2127ac, Func Offset: 0xec
	// Line 1745, Address: 0x2127b4, Func Offset: 0xf4
	// Line 1746, Address: 0x2127cc, Func Offset: 0x10c
	// Line 1747, Address: 0x2127e4, Func Offset: 0x124
	// Line 1750, Address: 0x2127f0, Func Offset: 0x130
	// Line 1753, Address: 0x2127f8, Func Offset: 0x138
	// Line 1754, Address: 0x2127fc, Func Offset: 0x13c
	// Func End, Address: 0x212814, Func Offset: 0x154
}

// 
// Start address: 0x212820
void bhEne29_PlyDmg117(BH_PWORK* plP, _en29_freework* fwP)
{
	int dlt;
	// Line 1778, Address: 0x212820, Func Offset: 0
	// Line 1780, Address: 0x212834, Func Offset: 0x14
	// Line 1782, Address: 0x21283c, Func Offset: 0x1c
	// Line 1786, Address: 0x212848, Func Offset: 0x28
	// Line 1780, Address: 0x212850, Func Offset: 0x30
	// Line 1781, Address: 0x212858, Func Offset: 0x38
	// Line 1782, Address: 0x212868, Func Offset: 0x48
	// Line 1783, Address: 0x212874, Func Offset: 0x54
	// Line 1786, Address: 0x212880, Func Offset: 0x60
	// Line 1787, Address: 0x212890, Func Offset: 0x70
	// Line 1789, Address: 0x21289c, Func Offset: 0x7c
	// Line 1791, Address: 0x2128c4, Func Offset: 0xa4
	// Line 1794, Address: 0x2128dc, Func Offset: 0xbc
	// Line 1795, Address: 0x2128fc, Func Offset: 0xdc
	// Func End, Address: 0x212914, Func Offset: 0xf4
}

// 
// Start address: 0x212920
void bhEne29_PlyDmg118(BH_PWORK* plP, _en29_freework* fwP)
{
	// Line 1807, Address: 0x212920, Func Offset: 0
	// Func End, Address: 0x212928, Func Offset: 0x8
}

// 
// Start address: 0x212930
void bhEne29_PlyDmgRtn(BH_PWORK* plP, _en29_freework* fwP)
{
	// Line 1821, Address: 0x212930, Func Offset: 0
	// Line 1823, Address: 0x212934, Func Offset: 0x4
	// Line 1824, Address: 0x21293c, Func Offset: 0xc
	// Line 1826, Address: 0x212940, Func Offset: 0x10
	// Line 1821, Address: 0x212944, Func Offset: 0x14
	// Line 1823, Address: 0x212948, Func Offset: 0x18
	// Line 1832, Address: 0x21294c, Func Offset: 0x1c
	// Line 1823, Address: 0x212950, Func Offset: 0x20
	// Line 1824, Address: 0x212958, Func Offset: 0x28
	// Line 1826, Address: 0x212964, Func Offset: 0x34
	// Line 1827, Address: 0x212968, Func Offset: 0x38
	// Line 1828, Address: 0x21296c, Func Offset: 0x3c
	// Line 1829, Address: 0x212970, Func Offset: 0x40
	// Line 1832, Address: 0x212974, Func Offset: 0x44
	// Line 1833, Address: 0x21297c, Func Offset: 0x4c
	// Func End, Address: 0x212984, Func Offset: 0x54
}

// 
// Start address: 0x212990
void bhEne29_SetDmgEffect(BH_PWORK* ewP, int eff_typ)
{
	float scl;
	int djnt_no;
	_anon26 off;
	int i;
	float mtxP[16];
	_anon26 off;
	int djnt_no;
	_anon26 dir;
	int i;
	_anon26 vct;
	_anon26 dir;
	_anon26 dir;
	int* effP;
	// Line 1890, Address: 0x212990, Func Offset: 0
	// Line 1891, Address: 0x2129a4, Func Offset: 0x14
	// Line 1890, Address: 0x2129a8, Func Offset: 0x18
	// Line 1891, Address: 0x2129b8, Func Offset: 0x28
	// Line 1890, Address: 0x2129c4, Func Offset: 0x34
	// Line 1893, Address: 0x2129c8, Func Offset: 0x38
	// Line 1901, Address: 0x212a0c, Func Offset: 0x7c
	// Line 1905, Address: 0x212a10, Func Offset: 0x80
	// Line 1901, Address: 0x212a18, Func Offset: 0x88
	// Line 1905, Address: 0x212a38, Func Offset: 0xa8
	// Line 1907, Address: 0x212a60, Func Offset: 0xd0
	// Line 1915, Address: 0x212a68, Func Offset: 0xd8
	// Line 1919, Address: 0x212a6c, Func Offset: 0xdc
	// Line 1915, Address: 0x212a74, Func Offset: 0xe4
	// Line 1919, Address: 0x212a94, Func Offset: 0x104
	// Line 1921, Address: 0x212abc, Func Offset: 0x12c
	// Line 1928, Address: 0x212ac4, Func Offset: 0x134
	// Line 1929, Address: 0x212adc, Func Offset: 0x14c
	// Line 1931, Address: 0x212ae4, Func Offset: 0x154
	// Line 1932, Address: 0x212afc, Func Offset: 0x16c
	// Line 1933, Address: 0x212b14, Func Offset: 0x184
	// Line 1934, Address: 0x212b44, Func Offset: 0x1b4
	// Line 1935, Address: 0x212b74, Func Offset: 0x1e4
	// Line 1947, Address: 0x212b78, Func Offset: 0x1e8
	// Line 1934, Address: 0x212b7c, Func Offset: 0x1ec
	// Line 1935, Address: 0x212b88, Func Offset: 0x1f8
	// Line 1936, Address: 0x212bc4, Func Offset: 0x234
	// Line 1937, Address: 0x212bdc, Func Offset: 0x24c
	// Line 1938, Address: 0x212bf0, Func Offset: 0x260
	// Line 1946, Address: 0x212c38, Func Offset: 0x2a8
	// Line 1944, Address: 0x212c3c, Func Offset: 0x2ac
	// Line 1946, Address: 0x212c40, Func Offset: 0x2b0
	// Line 1947, Address: 0x212c5c, Func Offset: 0x2cc
	// Line 1950, Address: 0x212c64, Func Offset: 0x2d4
	// Line 1953, Address: 0x212c70, Func Offset: 0x2e0
	// Line 1954, Address: 0x212c7c, Func Offset: 0x2ec
	// Line 1955, Address: 0x212cbc, Func Offset: 0x32c
	// Line 1956, Address: 0x212cfc, Func Offset: 0x36c
	// Line 1957, Address: 0x212d14, Func Offset: 0x384
	// Line 1956, Address: 0x212d1c, Func Offset: 0x38c
	// Line 1957, Address: 0x212d20, Func Offset: 0x390
	// Line 1956, Address: 0x212d24, Func Offset: 0x394
	// Line 1957, Address: 0x212d34, Func Offset: 0x3a4
	// Line 1956, Address: 0x212d48, Func Offset: 0x3b8
	// Line 1957, Address: 0x212d4c, Func Offset: 0x3bc
	// Line 1958, Address: 0x212d54, Func Offset: 0x3c4
	// Line 1960, Address: 0x212d58, Func Offset: 0x3c8
	// Line 1961, Address: 0x212d98, Func Offset: 0x408
	// Line 1962, Address: 0x212ddc, Func Offset: 0x44c
	// Line 1963, Address: 0x212dfc, Func Offset: 0x46c
	// Line 1962, Address: 0x212e04, Func Offset: 0x474
	// Line 1963, Address: 0x212e14, Func Offset: 0x484
	// Line 1962, Address: 0x212e1c, Func Offset: 0x48c
	// Line 1963, Address: 0x212e24, Func Offset: 0x494
	// Line 1965, Address: 0x212e38, Func Offset: 0x4a8
	// Line 1966, Address: 0x212e78, Func Offset: 0x4e8
	// Line 1967, Address: 0x212eb8, Func Offset: 0x528
	// Line 1968, Address: 0x212ed8, Func Offset: 0x548
	// Line 1967, Address: 0x212ee0, Func Offset: 0x550
	// Line 1968, Address: 0x212ef0, Func Offset: 0x560
	// Line 1967, Address: 0x212ef8, Func Offset: 0x568
	// Line 1968, Address: 0x212f0c, Func Offset: 0x57c
	// Line 1970, Address: 0x212f20, Func Offset: 0x590
	// Line 1971, Address: 0x212f2c, Func Offset: 0x59c
	// Line 1972, Address: 0x212f6c, Func Offset: 0x5dc
	// Line 1973, Address: 0x212fac, Func Offset: 0x61c
	// Line 1974, Address: 0x212fc8, Func Offset: 0x638
	// Line 1973, Address: 0x212fd4, Func Offset: 0x644
	// Line 1974, Address: 0x212fe4, Func Offset: 0x654
	// Line 1973, Address: 0x212fe8, Func Offset: 0x658
	// Line 1974, Address: 0x212ff0, Func Offset: 0x660
	// Line 1975, Address: 0x213004, Func Offset: 0x674
	// Line 1976, Address: 0x213008, Func Offset: 0x678
	// Line 1979, Address: 0x213014, Func Offset: 0x684
	// Line 1987, Address: 0x21301c, Func Offset: 0x68c
	// Line 1992, Address: 0x213024, Func Offset: 0x694
	// Line 1987, Address: 0x213030, Func Offset: 0x6a0
	// Line 1992, Address: 0x213040, Func Offset: 0x6b0
	// Line 1987, Address: 0x213044, Func Offset: 0x6b4
	// Line 1988, Address: 0x213048, Func Offset: 0x6b8
	// Line 1989, Address: 0x21304c, Func Offset: 0x6bc
	// Line 1990, Address: 0x213050, Func Offset: 0x6c0
	// Line 1992, Address: 0x213054, Func Offset: 0x6c4
	// Line 1988, Address: 0x213058, Func Offset: 0x6c8
	// Line 1989, Address: 0x21305c, Func Offset: 0x6cc
	// Line 1992, Address: 0x213060, Func Offset: 0x6d0
	// Line 1993, Address: 0x213064, Func Offset: 0x6d4
	// Line 1990, Address: 0x213070, Func Offset: 0x6e0
	// Line 1993, Address: 0x213074, Func Offset: 0x6e4
	// Line 1994, Address: 0x21307c, Func Offset: 0x6ec
	// Line 1995, Address: 0x2130a0, Func Offset: 0x710
	// Line 1994, Address: 0x2130a8, Func Offset: 0x718
	// Line 1995, Address: 0x2130b0, Func Offset: 0x720
	// Line 1997, Address: 0x2130d4, Func Offset: 0x744
	// Line 1998, Address: 0x2130d8, Func Offset: 0x748
	// Line 1995, Address: 0x2130dc, Func Offset: 0x74c
	// Line 1996, Address: 0x2130e8, Func Offset: 0x758
	// Line 1997, Address: 0x213100, Func Offset: 0x770
	// Line 1998, Address: 0x21313c, Func Offset: 0x7ac
	// Line 1999, Address: 0x213150, Func Offset: 0x7c0
	// Line 2002, Address: 0x21317c, Func Offset: 0x7ec
	// Line 2004, Address: 0x2131b8, Func Offset: 0x828
	// Line 2010, Address: 0x2131c0, Func Offset: 0x830
	// Line 2012, Address: 0x2131cc, Func Offset: 0x83c
	// Line 2009, Address: 0x2131d0, Func Offset: 0x840
	// Line 2012, Address: 0x2131d4, Func Offset: 0x844
	// Line 2010, Address: 0x2131dc, Func Offset: 0x84c
	// Line 2012, Address: 0x2131e0, Func Offset: 0x850
	// Line 2010, Address: 0x2131f0, Func Offset: 0x860
	// Line 2012, Address: 0x2131f4, Func Offset: 0x864
	// Line 2013, Address: 0x213200, Func Offset: 0x870
	// Line 2014, Address: 0x21320c, Func Offset: 0x87c
	// Line 2016, Address: 0x213220, Func Offset: 0x890
	// Line 2024, Address: 0x21322c, Func Offset: 0x89c
	// Line 2016, Address: 0x213234, Func Offset: 0x8a4
	// Line 2017, Address: 0x213240, Func Offset: 0x8b0
	// Line 2024, Address: 0x21324c, Func Offset: 0x8bc
	// Line 2017, Address: 0x213250, Func Offset: 0x8c0
	// Line 2018, Address: 0x21325c, Func Offset: 0x8cc
	// Line 2019, Address: 0x213284, Func Offset: 0x8f4
	// Line 2020, Address: 0x213298, Func Offset: 0x908
	// Line 2021, Address: 0x2132d4, Func Offset: 0x944
	// Line 2022, Address: 0x2132ec, Func Offset: 0x95c
	// Line 2024, Address: 0x213328, Func Offset: 0x998
	// Line 2029, Address: 0x213340, Func Offset: 0x9b0
	// Func End, Address: 0x213368, Func Offset: 0x9d8
}

// 
// Start address: 0x213370
void SetDmgEne(_en29_freework* fwP, _anon35* dsP, int set_num)
{
	BH_PWORK* ewP;
	_e19_dmg_typ* edP;
	_e19_dmg_typ* hedP;
	// Line 2039, Address: 0x213370, Func Offset: 0
	// Line 2044, Address: 0x213384, Func Offset: 0x14
	// Line 2039, Address: 0x213388, Func Offset: 0x18
	// Line 2047, Address: 0x21338c, Func Offset: 0x1c
	// Line 2051, Address: 0x2133a0, Func Offset: 0x30
	// Line 2054, Address: 0x2133a8, Func Offset: 0x38
	// Line 2056, Address: 0x2133b8, Func Offset: 0x48
	// Line 2064, Address: 0x2133c0, Func Offset: 0x50
	// Line 2056, Address: 0x2133c4, Func Offset: 0x54
	// Line 2057, Address: 0x2133cc, Func Offset: 0x5c
	// Line 2058, Address: 0x2133d4, Func Offset: 0x64
	// Line 2059, Address: 0x2133dc, Func Offset: 0x6c
	// Line 2061, Address: 0x2133e4, Func Offset: 0x74
	// Line 2062, Address: 0x2133e8, Func Offset: 0x78
	// Line 2064, Address: 0x2133ec, Func Offset: 0x7c
	// Line 2062, Address: 0x2133f0, Func Offset: 0x80
	// Line 2063, Address: 0x2133f4, Func Offset: 0x84
	// Line 2064, Address: 0x2133f8, Func Offset: 0x88
	// Line 2065, Address: 0x213400, Func Offset: 0x90
	// Func End, Address: 0x21341c, Func Offset: 0xac
}

// 
// Start address: 0x213420
void CalcDmgEne(BH_PWORK* ewP, _en29_freework* fwP)
{
	BH_PWORK* enP;
	_e19_dmg_typ* edP;
	_e19_dmg_typ* hedP;
	_anon22* owP;
	// Line 2080, Address: 0x213420, Func Offset: 0
	// Line 2079, Address: 0x213424, Func Offset: 0x4
	// Line 2081, Address: 0x213428, Func Offset: 0x8
	// Line 2084, Address: 0x213434, Func Offset: 0x14
	// Line 2085, Address: 0x213438, Func Offset: 0x18
	// Line 2086, Address: 0x213440, Func Offset: 0x20
	// Line 2087, Address: 0x21346c, Func Offset: 0x4c
	// Line 2089, Address: 0x213498, Func Offset: 0x78
	// Line 2090, Address: 0x2134a0, Func Offset: 0x80
	// Line 2091, Address: 0x2134a8, Func Offset: 0x88
	// Line 2092, Address: 0x2134b8, Func Offset: 0x98
	// Func End, Address: 0x2134c0, Func Offset: 0xa0
}

// 
// Start address: 0x2134c0
void CheckDmgEne(BH_PWORK* ewP, _en29_freework* fwP)
{
	int num;
	int* dstP;
	int* srcP;
	float d;
	BH_PWORK* enP;
	_e19_dmg_typ* edP;
	_e19_dmg_typ* hedP;
	BH_PWORK* dmgP;
	// Line 2102, Address: 0x2134c0, Func Offset: 0
	// Line 2114, Address: 0x2134dc, Func Offset: 0x1c
	// Line 2115, Address: 0x2134e4, Func Offset: 0x24
	// Line 2116, Address: 0x2134f0, Func Offset: 0x30
	// Line 2117, Address: 0x2134f4, Func Offset: 0x34
	// Line 2118, Address: 0x213504, Func Offset: 0x44
	// Line 2120, Address: 0x213510, Func Offset: 0x50
	// Line 2121, Address: 0x213524, Func Offset: 0x64
	// Line 2123, Address: 0x213544, Func Offset: 0x84
	// Line 2126, Address: 0x213548, Func Offset: 0x88
	// Line 2129, Address: 0x213558, Func Offset: 0x98
	// Line 2133, Address: 0x213570, Func Offset: 0xb0
	// Line 2134, Address: 0x213578, Func Offset: 0xb8
	// Line 2135, Address: 0x21357c, Func Offset: 0xbc
	// Line 2134, Address: 0x213588, Func Offset: 0xc8
	// Line 2135, Address: 0x21358c, Func Offset: 0xcc
	// Line 2136, Address: 0x2135a8, Func Offset: 0xe8
	// Line 2137, Address: 0x2135b0, Func Offset: 0xf0
	// Line 2138, Address: 0x2135b8, Func Offset: 0xf8
	// Line 2139, Address: 0x2135c0, Func Offset: 0x100
	// Line 2140, Address: 0x2135c8, Func Offset: 0x108
	// Line 2141, Address: 0x2135d0, Func Offset: 0x110
	// Line 2142, Address: 0x2135d8, Func Offset: 0x118
	// Line 2143, Address: 0x2135e0, Func Offset: 0x120
	// Line 2144, Address: 0x2135e8, Func Offset: 0x128
	// Line 2145, Address: 0x2135f0, Func Offset: 0x130
	// Line 2147, Address: 0x213604, Func Offset: 0x144
	// Func End, Address: 0x213624, Func Offset: 0x164
}

