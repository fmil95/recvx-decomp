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
typedef struct _anon47;
typedef struct _anon48;

typedef void(*type_91)(void*);

typedef float type_0[16];
typedef unsigned int type_1[4];
typedef _anon0* type_2[512];
typedef _anon0* type_3[32];
typedef _anon2* type_4[16];
typedef _anon0* type_5[32];
typedef _anon0* type_6[512];
typedef _anon2* type_7[16][16];
typedef _anon2* type_8[16][16][100];
typedef char type_9[8];
typedef _anon0* type_10[32];
typedef _anon28 type_11[5];
typedef _anon0* type_12[512];
typedef _anon2* type_13[1300];
typedef char type_14[32];
typedef float type_15[32];
typedef _anon0* type_16[512];
typedef _anon2* type_17[200];
typedef short type_18[32];
typedef _anon28 type_19[1];
typedef _anon0* type_20[128];
typedef unsigned int type_21[1];
typedef _anon12 type_22[256];
typedef _anon2* type_23[8];
typedef int* type_24[16];
typedef _anon0* type_25[128];
typedef _anon47 type_26[16];
typedef npobj* type_27[16];
typedef _anon0* type_28[128];
typedef int type_29[4];
typedef _anon2* type_30[16];
typedef unsigned int type_31[4];
typedef float type_32[4];
typedef _anon16 type_33[16];
typedef _anon0* type_34[512];
typedef float type_35[4];
typedef char type_36[256];
typedef float type_37[4];
typedef float type_38[4];
typedef BH_PWORK type_39[0];
typedef float type_40[4];
typedef float type_41[4];
typedef _anon8* type_42[128];
typedef float type_43[3];
typedef unsigned char type_44[64];
typedef float type_45[3][20];
typedef float type_46[3];
typedef float type_47[3][20];
typedef float type_48[3];
typedef float type_49[3][20];
typedef int type_50[3];
typedef char type_51[8];
typedef int type_52[3][21];
typedef float type_53[3];
typedef float type_54[3][20];
typedef void* type_55[2];
typedef _anon2* type_56[256];
typedef int type_57[4];
typedef unsigned char* type_58[256];
typedef short type_59[22];
typedef short type_60[22][31];
typedef unsigned int type_61[2];
typedef short type_62[256];
typedef _anon35 type_63[4];
typedef float type_64[3];
typedef short type_65[256];
typedef int type_66[3];
typedef int type_67[8];
typedef float type_68[3];
typedef _anon2* type_69[256];
typedef _anon14 type_70[256];
typedef _anon37 type_71[2];
typedef _anon22 type_72[0];
typedef _anon28 type_73[450];
typedef _anon37 type_74[16];
typedef short type_75[256];
typedef char type_76[3];
typedef int type_77[64];
typedef _anon16 type_78[450];
typedef unsigned int type_79[16];
typedef char type_80[4];
typedef unsigned int type_81[8];
typedef _anon40 type_82[4];
typedef _anon3 type_83[4];
typedef int type_84[450];
typedef unsigned int type_85[8];
typedef unsigned char type_86[450];
typedef float type_87[128];
typedef unsigned int type_88[8];
typedef char type_89[16];
typedef char type_90[4];
typedef _anon26 type_92[2];
typedef unsigned int type_93[32];
typedef unsigned char type_94[256];
typedef unsigned int type_95[16];
typedef _anon24 type_96[64];
typedef unsigned int type_97[16];
typedef _anon24 type_98[64];
typedef unsigned int type_99[32];
typedef short type_100[22];
typedef short type_101[22][31];
typedef _anon24 type_102[64];
typedef unsigned int type_103[16];
typedef unsigned int type_104[3];
typedef BH_PWORK* type_105[16];
typedef unsigned int type_106[8];
typedef unsigned int type_107[1];
typedef unsigned int type_108[384];
typedef unsigned int type_109[2];
typedef unsigned char type_110[2];
typedef unsigned int type_111[4];
typedef int* type_112[16];
typedef char type_113[32];
typedef npobj* type_114[16];
typedef char type_115[64];
typedef _anon2* type_116[16];
typedef char type_117[4];
typedef _anon16 type_118[16];
typedef short type_119[4];
typedef unsigned char type_120[4];
typedef _anon38 type_121[16];
typedef unsigned int type_122[8];
typedef unsigned int type_123[32];
typedef unsigned int type_124[4];
typedef _anon1 type_125[32];
typedef _anon0* type_126[512];
typedef _anon0* type_127[128];
typedef short type_128[22];
typedef short type_129[22][31];
typedef _anon0* type_130[512];
typedef unsigned char type_131[64];
typedef _anon0* type_132[512];

struct npobj
{
	unsigned int evalflags;
	_anon36* model;
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
	_anon8* mnwP;
	_anon8* mnwPb;
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
	_anon46 cspr;
	int pn;
	_anon40* pvp;
	_anon3* tvp;
	_anon40 pv[4];
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
	_anon8* mnwP;
	_anon8* mnwPb;
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
	_anon34 watr;
	_anon29* cpcl;
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
	float x;
	float y;
	float z;
};

struct _anon2
{
	_anon28* textures;
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
	_anon28 subtx[5];
	_anon2 subtx_list;
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
	_anon9 scr;
	_anon37 clip[2];
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

struct _anon5
{
	float px;
	float py;
	float pz;
	int ay;
};

struct _anon6
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
	_anon1 ply_pos;
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
	_anon8* emtp[128];
	_anon8* rmthp;
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
	_anon14 txbp[256];
	unsigned char* ef_psp;
	_anon28 ef_tex[450];
	_anon2 ef_tlist;
	_anon41 ef;
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
	_anon25 ren_info;
	_anon28 ren_tex[1];
	_anon2 ren_tlist;
	_anon12 rpb[256];
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
	_anon43 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon7* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon35 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon37 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon24* pl_htp;
	int costume;
	_anon1 hd_pos;
	_anon1 apos;
	_anon24* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon24 mwalp[64];
	_anon24 metcp[64];
	_anon24 mflrp[64];
	int dla_n;
	_anon24* htp;
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
	_anon20 door;
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
	_anon1 ufo_pos;
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
	_anon38 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon1 ghtp[32];
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

struct _anon7
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

struct _anon8
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon27* md2P;
	unsigned short* atrP;
};

struct _anon9
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
};

struct _anon10
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon47 keyf[16];
};

struct _anon11
{
	_anon15* cutp;
	_anon7* lgtp;
	_anon19* enep;
	_anon19* objp;
	_anon19* itmp;
	_anon23* effp;
	_anon24* walp;
	_anon24* etcp;
	_anon24* flrp;
	_anon5* posp;
	_anon24* rutp;
	unsigned char* ruttp;
	_anon30* evtp;
	_anon10* evcp;
	unsigned int* mesp;
	_anon7* evlp;
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

struct _anon12
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon13
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

struct _anon14
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
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
	_anon26 cam[2];
	unsigned char exd[256];
};

struct _anon16
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon2* texP;
	_anon32* owP;
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
	_anon44* info;
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

struct _anon20
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

struct _anon21
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
	float gx;
	float gy;
	float gz;
	unsigned int at_flg;
	int wpn_no;
	float r;
	float l;
	float rn;
	float rmax;
	int ax;
	int ay;
};

struct _anon22
{
	unsigned int flg;
	unsigned int atack_ct;
	unsigned int fend_ct;
	unsigned int at_cct;
	short ef_yct;
	short act_ct0;
	short act_ct1;
	short act_ct2;
	float r;
	float l;
	float rn;
	float rmax;
	_anon1 wp_fps1;
	_anon1 wp_fps2;
	_anon1 wp_cps;
	unsigned char ltp;
	unsigned char lr;
	unsigned char lg;
	unsigned char lb;
	unsigned short lnr;
	unsigned short lfr;
	float hrate;
	float ef_scale;
	short snd_wpno;
	short hiteff;
	unsigned short seno0;
	unsigned short seno1;
	char vib_tp;
	char vib_ct;
	char reserve1;
	char reserve2;
};

struct _anon23
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

struct _anon24
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

struct _anon25
{
	void* texaddr;
	_anon13 texsurface;
};

struct _anon26
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

struct _anon27
{
	void* p[2];
};

struct _anon28
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon29
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon30
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon31
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon32
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon33
{
	float mtrx[16];
	_anon1 pnt;
	_anon1 vctr;
	int stat;
	int reserve;
	_anon39 ltcal;
	_anon45 attr;
};

struct _anon34
{
	_anon1 c1;
	_anon1 c2;
	float r;
};

struct _anon35
{
	_anon1 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon36
{
	int* vlist;
	short* plist;
	_anon1 center;
	float r;
};

struct _anon37
{
	float x;
	float y;
};

struct _anon38
{
	_anon1 c1;
	_anon1 c2;
	float r1;
	float r2;
};

struct _anon39
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
	_anon1 lpnt;
	_anon1 lvctr;
	_anon1 lmvctr;
	_anon31 atten;
	_anon31 amb;
	_anon31 dif;
	_anon31 spc;
	_anon31 mamb;
	_anon31 mdif;
	_anon31 mspc;
};

struct _anon40
{
	float x;
	float y;
	float z;
	unsigned int col;
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
	unsigned int flg;
	int camver;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
	float wpx;
	float wpy;
	float wpz;
	float plx;
	float ply;
	float plz;
	float pxp;
	float pyp;
	float pzp;
	float ofx;
	float ofy;
	float ofz;
	int ax;
	int ay;
	int az;
	int axp;
	int ayp;
	int azp;
	float ln;
	float pln;
	float xr;
	float xn;
	float yr;
	float yn;
	int pers;
	int ppers;
	int ncut;
	int ocut;
	unsigned int ocflg;
	unsigned int attr;
	float mtx[16];
	float mtxb[16];
	int evc_no;
	int hct;
	int ct0;
	int ct1;
	int keyf_no;
	float frm;
	float spd;
	float pxn;
	float pyn;
	float pzn;
	int axn;
	int ayn;
	int azn;
	int pe_ax;
	int pe_pers;
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	float ips[3][20];
	float ian[3][20];
	float ipf[3][20];
	float icr[3][20];
};

struct _anon43
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon44
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

struct _anon45
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
	_anon31 argb;
};

struct _anon46
{
	_anon1 c;
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

struct _anon48
{
	float px;
	float py;
	float pz;
	float ox;
	float oy;
	float oz;
};

short EneDamNear[22][31];
short EneDamMid[22][31];
short EneDamFar[22][31];
int WpnAngTab[3][21];
unsigned int HitWalEff[8];
BH_PWORK* plp;
_anon6* sys;
_anon4 swork;
_anon22 WpnTab[0];
BH_PWORK ene[0];
_anon42 cam;
_anon11* rom;

void bhSetWeapon(_anon0* op, int wpn_no, int flg);
void bhObjWpn(_anon0* op);
void bhActionWeapon(_anon0* op);
short bhCheckBullet();
int bhCountBullet();
int bhCheckGunAtari(_anon21* gap);
void bhCheckKnifeAtari(_anon21* gap);
int bhCheckFlyAtari(_anon21* gap, int eidx);
void bhSetBowDamage();
void bhCheckBombAtari(_anon1* pos, float ar, int dmax, int dmin);
int bhCheckCapCol2Capsule(BH_PWORK* pp, _anon34* cap, _anon1* hps);
void bhSetGunSplash(_anon21* gap, _anon1* pos, int wattr);
void bhSetExplosion(_anon1* pos);
void bhSetExplosionEffect(_anon1* pos);
void bhSetExplosionEffectEx(_anon1* pos, float scl);

// 
// Start address: 0x28a300
void bhSetWeapon(_anon0* op, int wpn_no, int flg)
{
	// Line 137, Address: 0x28a300, Func Offset: 0
	// Line 138, Address: 0x28a31c, Func Offset: 0x1c
	// Line 139, Address: 0x28a32c, Func Offset: 0x2c
	// Line 140, Address: 0x28a334, Func Offset: 0x34
	// Line 141, Address: 0x28a33c, Func Offset: 0x3c
	// Line 142, Address: 0x28a344, Func Offset: 0x44
	// Line 145, Address: 0x28a34c, Func Offset: 0x4c
	// Line 142, Address: 0x28a350, Func Offset: 0x50
	// Line 150, Address: 0x28a358, Func Offset: 0x58
	// Line 151, Address: 0x28a374, Func Offset: 0x74
	// Line 152, Address: 0x28a388, Func Offset: 0x88
	// Line 153, Address: 0x28a39c, Func Offset: 0x9c
	// Line 154, Address: 0x28a3a4, Func Offset: 0xa4
	// Line 155, Address: 0x28a3b0, Func Offset: 0xb0
	// Line 156, Address: 0x28a3d4, Func Offset: 0xd4
	// Line 157, Address: 0x28a3e0, Func Offset: 0xe0
	// Line 158, Address: 0x28a3f8, Func Offset: 0xf8
	// Line 159, Address: 0x28a400, Func Offset: 0x100
	// Line 158, Address: 0x28a408, Func Offset: 0x108
	// Line 159, Address: 0x28a410, Func Offset: 0x110
	// Line 160, Address: 0x28a418, Func Offset: 0x118
	// Line 159, Address: 0x28a41c, Func Offset: 0x11c
	// Line 160, Address: 0x28a42c, Func Offset: 0x12c
	// Line 161, Address: 0x28a434, Func Offset: 0x134
	// Line 160, Address: 0x28a438, Func Offset: 0x138
	// Line 161, Address: 0x28a448, Func Offset: 0x148
	// Line 162, Address: 0x28a45c, Func Offset: 0x15c
	// Line 163, Address: 0x28a464, Func Offset: 0x164
	// Line 164, Address: 0x28a470, Func Offset: 0x170
	// Line 163, Address: 0x28a478, Func Offset: 0x178
	// Line 164, Address: 0x28a480, Func Offset: 0x180
	// Line 165, Address: 0x28a490, Func Offset: 0x190
	// Line 166, Address: 0x28a494, Func Offset: 0x194
	// Line 165, Address: 0x28a498, Func Offset: 0x198
	// Line 166, Address: 0x28a4ac, Func Offset: 0x1ac
	// Line 167, Address: 0x28a4b4, Func Offset: 0x1b4
	// Line 166, Address: 0x28a4b8, Func Offset: 0x1b8
	// Line 167, Address: 0x28a4c8, Func Offset: 0x1c8
	// Line 170, Address: 0x28a4e0, Func Offset: 0x1e0
	// Line 171, Address: 0x28a4f0, Func Offset: 0x1f0
	// Line 170, Address: 0x28a4f4, Func Offset: 0x1f4
	// Line 171, Address: 0x28a504, Func Offset: 0x204
	// Line 172, Address: 0x28a50c, Func Offset: 0x20c
	// Line 171, Address: 0x28a510, Func Offset: 0x210
	// Line 172, Address: 0x28a520, Func Offset: 0x220
	// Line 173, Address: 0x28a538, Func Offset: 0x238
	// Func End, Address: 0x28a550, Func Offset: 0x250
}

// 
// Start address: 0x28a550
void bhObjWpn(_anon0* op)
{
	// Line 182, Address: 0x28a550, Func Offset: 0
	// Line 183, Address: 0x28a560, Func Offset: 0x10
	// Line 184, Address: 0x28a584, Func Offset: 0x34
	// Line 185, Address: 0x28a590, Func Offset: 0x40
	// Line 184, Address: 0x28a598, Func Offset: 0x48
	// Line 185, Address: 0x28a5b0, Func Offset: 0x60
	// Line 186, Address: 0x28a5b4, Func Offset: 0x64
	// Line 185, Address: 0x28a5bc, Func Offset: 0x6c
	// Line 186, Address: 0x28a5d4, Func Offset: 0x84
	// Line 187, Address: 0x28a5ec, Func Offset: 0x9c
	// Line 188, Address: 0x28a5f4, Func Offset: 0xa4
	// Line 189, Address: 0x28a5f8, Func Offset: 0xa8
	// Line 190, Address: 0x28a5fc, Func Offset: 0xac
	// Line 193, Address: 0x28a600, Func Offset: 0xb0
	// Func End, Address: 0x28a608, Func Offset: 0xb8
}

// 
// Start address: 0x28a610
void bhActionWeapon(_anon0* op)
{
	float nn;
	int rr;
	int ang;
	npobj* obp;
	_anon1 pos;
	// Line 199, Address: 0x28a610, Func Offset: 0
	// Line 204, Address: 0x28a620, Func Offset: 0x10
	// Line 205, Address: 0x28a624, Func Offset: 0x14
	// Line 204, Address: 0x28a630, Func Offset: 0x20
	// Line 205, Address: 0x28a634, Func Offset: 0x24
	// Line 207, Address: 0x28a664, Func Offset: 0x54
	// Line 209, Address: 0x28a690, Func Offset: 0x80
	// Line 210, Address: 0x28a69c, Func Offset: 0x8c
	// Line 211, Address: 0x28a6a4, Func Offset: 0x94
	// Line 213, Address: 0x28a6ac, Func Offset: 0x9c
	// Line 214, Address: 0x28a6b4, Func Offset: 0xa4
	// Line 215, Address: 0x28a6bc, Func Offset: 0xac
	// Line 217, Address: 0x28a6c4, Func Offset: 0xb4
	// Line 218, Address: 0x28a6d4, Func Offset: 0xc4
	// Line 217, Address: 0x28a6dc, Func Offset: 0xcc
	// Line 218, Address: 0x28a6e0, Func Offset: 0xd0
	// Line 219, Address: 0x28a6f0, Func Offset: 0xe0
	// Line 220, Address: 0x28a6f4, Func Offset: 0xe4
	// Line 225, Address: 0x28a708, Func Offset: 0xf8
	// Line 227, Address: 0x28a710, Func Offset: 0x100
	// Line 229, Address: 0x28a734, Func Offset: 0x124
	// Line 230, Address: 0x28a738, Func Offset: 0x128
	// Line 232, Address: 0x28a74c, Func Offset: 0x13c
	// Line 234, Address: 0x28a754, Func Offset: 0x144
	// Line 235, Address: 0x28a768, Func Offset: 0x158
	// Line 241, Address: 0x28a794, Func Offset: 0x184
	// Line 242, Address: 0x28a7ec, Func Offset: 0x1dc
	// Line 243, Address: 0x28a7f4, Func Offset: 0x1e4
	// Line 248, Address: 0x28a7fc, Func Offset: 0x1ec
	// Line 249, Address: 0x28a854, Func Offset: 0x244
	// Line 250, Address: 0x28a85c, Func Offset: 0x24c
	// Line 252, Address: 0x28a864, Func Offset: 0x254
	// Line 253, Address: 0x28a868, Func Offset: 0x258
	// Line 257, Address: 0x28a87c, Func Offset: 0x26c
	// Line 258, Address: 0x28a884, Func Offset: 0x274
	// Line 263, Address: 0x28a8b0, Func Offset: 0x2a0
	// Line 264, Address: 0x28a908, Func Offset: 0x2f8
	// Line 265, Address: 0x28a910, Func Offset: 0x300
	// Line 269, Address: 0x28a918, Func Offset: 0x308
	// Line 270, Address: 0x28a970, Func Offset: 0x360
	// Line 271, Address: 0x28a978, Func Offset: 0x368
	// Line 273, Address: 0x28a980, Func Offset: 0x370
	// Line 274, Address: 0x28a984, Func Offset: 0x374
	// Line 279, Address: 0x28a998, Func Offset: 0x388
	// Line 281, Address: 0x28a9a0, Func Offset: 0x390
	// Line 283, Address: 0x28a9c4, Func Offset: 0x3b4
	// Line 284, Address: 0x28a9c8, Func Offset: 0x3b8
	// Line 286, Address: 0x28a9dc, Func Offset: 0x3cc
	// Line 288, Address: 0x28a9e4, Func Offset: 0x3d4
	// Line 291, Address: 0x28aa00, Func Offset: 0x3f0
	// Line 292, Address: 0x28aa08, Func Offset: 0x3f8
	// Line 291, Address: 0x28aa0c, Func Offset: 0x3fc
	// Line 292, Address: 0x28aa1c, Func Offset: 0x40c
	// Line 293, Address: 0x28aa28, Func Offset: 0x418
	// Line 294, Address: 0x28aa3c, Func Offset: 0x42c
	// Line 295, Address: 0x28aa44, Func Offset: 0x434
	// Line 296, Address: 0x28aa54, Func Offset: 0x444
	// Line 300, Address: 0x28aa58, Func Offset: 0x448
	// Line 301, Address: 0x28aa5c, Func Offset: 0x44c
	// Line 302, Address: 0x28aa6c, Func Offset: 0x45c
	// Line 303, Address: 0x28aa78, Func Offset: 0x468
	// Line 304, Address: 0x28aa80, Func Offset: 0x470
	// Line 305, Address: 0x28aa88, Func Offset: 0x478
	// Line 306, Address: 0x28aa8c, Func Offset: 0x47c
	// Line 307, Address: 0x28aa94, Func Offset: 0x484
	// Line 308, Address: 0x28aabc, Func Offset: 0x4ac
	// Line 309, Address: 0x28aac4, Func Offset: 0x4b4
	// Line 313, Address: 0x28aacc, Func Offset: 0x4bc
	// Line 308, Address: 0x28aad4, Func Offset: 0x4c4
	// Line 313, Address: 0x28aad8, Func Offset: 0x4c8
	// Line 308, Address: 0x28aadc, Func Offset: 0x4cc
	// Line 309, Address: 0x28aae8, Func Offset: 0x4d8
	// Line 315, Address: 0x28aaf0, Func Offset: 0x4e0
	// Line 310, Address: 0x28aafc, Func Offset: 0x4ec
	// Line 315, Address: 0x28ab00, Func Offset: 0x4f0
	// Line 309, Address: 0x28ab04, Func Offset: 0x4f4
	// Line 310, Address: 0x28ab10, Func Offset: 0x500
	// Line 311, Address: 0x28ab18, Func Offset: 0x508
	// Line 312, Address: 0x28ab1c, Func Offset: 0x50c
	// Line 317, Address: 0x28ab20, Func Offset: 0x510
	// Line 310, Address: 0x28ab24, Func Offset: 0x514
	// Line 311, Address: 0x28ab30, Func Offset: 0x520
	// Line 317, Address: 0x28ab38, Func Offset: 0x528
	// Line 311, Address: 0x28ab40, Func Offset: 0x530
	// Line 312, Address: 0x28ab4c, Func Offset: 0x53c
	// Line 313, Address: 0x28ab60, Func Offset: 0x550
	// Line 314, Address: 0x28ab74, Func Offset: 0x564
	// Line 315, Address: 0x28ab88, Func Offset: 0x578
	// Line 316, Address: 0x28ab9c, Func Offset: 0x58c
	// Line 317, Address: 0x28abc4, Func Offset: 0x5b4
	// Line 320, Address: 0x28abdc, Func Offset: 0x5cc
	// Line 322, Address: 0x28abe4, Func Offset: 0x5d4
	// Line 323, Address: 0x28abf8, Func Offset: 0x5e8
	// Line 324, Address: 0x28ac04, Func Offset: 0x5f4
	// Line 325, Address: 0x28ac08, Func Offset: 0x5f8
	// Line 326, Address: 0x28ac1c, Func Offset: 0x60c
	// Line 332, Address: 0x28ac20, Func Offset: 0x610
	// Func End, Address: 0x28ac34, Func Offset: 0x624
}

// 
// Start address: 0x28ac40
short bhCheckBullet()
{
	short bn;
	short iw;
	// Line 343, Address: 0x28ac40, Func Offset: 0
	// Line 344, Address: 0x28ac4c, Func Offset: 0xc
	// Line 349, Address: 0x28ac58, Func Offset: 0x18
	// Line 350, Address: 0x28ac88, Func Offset: 0x48
	// Line 353, Address: 0x28ac94, Func Offset: 0x54
	// Func End, Address: 0x28ac9c, Func Offset: 0x5c
}

// 
// Start address: 0x28aca0
int bhCountBullet()
{
	short bn;
	short iw;
	// Line 365, Address: 0x28aca0, Func Offset: 0
	// Line 366, Address: 0x28acac, Func Offset: 0xc
	// Line 367, Address: 0x28acb8, Func Offset: 0x18
	// Line 368, Address: 0x28ace8, Func Offset: 0x48
	// Line 371, Address: 0x28acf4, Func Offset: 0x54
	// Line 373, Address: 0x28ad0c, Func Offset: 0x6c
	// Line 375, Address: 0x28ad38, Func Offset: 0x98
	// Line 374, Address: 0x28ad3c, Func Offset: 0x9c
	// Line 375, Address: 0x28ad44, Func Offset: 0xa4
	// Line 374, Address: 0x28ad50, Func Offset: 0xb0
	// Line 376, Address: 0x28ad54, Func Offset: 0xb4
	// Line 374, Address: 0x28ad58, Func Offset: 0xb8
	// Line 375, Address: 0x28ad60, Func Offset: 0xc0
	// Line 374, Address: 0x28ad64, Func Offset: 0xc4
	// Line 375, Address: 0x28ad6c, Func Offset: 0xcc
	// Line 377, Address: 0x28ad80, Func Offset: 0xe0
	// Func End, Address: 0x28ad88, Func Offset: 0xe8
}

// 
// Start address: 0x28ad90
int bhCheckGunAtari(_anon21* gap)
{
	_anon43 wtln;
	_anon1 vec1;
	_anon1 vec0;
	unsigned int wp_flg;
	int wno;
	int watflg;
	int jno;
	int wp_hef;
	int walhit;
	int kno;
	int id;
	int j;
	int i;
	_anon24* wlp;
	BH_PWORK* pp;
	float len;
	float knr;
	float ll;
	float nr;
	float a;
	float rmax;
	float rn;
	_anon43 gline;
	_anon1 gvec;
	_anon1 wps;
	_anon1 sca;
	_anon1 ps;
	_anon1 ap;
	_anon34 wal;
	_anon34 gatr;
	int igct;
	// Line 403, Address: 0x28ad90, Func Offset: 0
	// Line 415, Address: 0x28add8, Func Offset: 0x48
	// Line 414, Address: 0x28addc, Func Offset: 0x4c
	// Line 415, Address: 0x28ade0, Func Offset: 0x50
	// Line 416, Address: 0x28adec, Func Offset: 0x5c
	// Line 418, Address: 0x28adf0, Func Offset: 0x60
	// Line 421, Address: 0x28ae14, Func Offset: 0x84
	// Line 419, Address: 0x28ae18, Func Offset: 0x88
	// Line 421, Address: 0x28ae28, Func Offset: 0x98
	// Line 422, Address: 0x28ae3c, Func Offset: 0xac
	// Line 423, Address: 0x28ae40, Func Offset: 0xb0
	// Line 422, Address: 0x28ae4c, Func Offset: 0xbc
	// Line 423, Address: 0x28ae50, Func Offset: 0xc0
	// Line 424, Address: 0x28ae5c, Func Offset: 0xcc
	// Line 427, Address: 0x28ae64, Func Offset: 0xd4
	// Line 428, Address: 0x28ae68, Func Offset: 0xd8
	// Line 436, Address: 0x28ae6c, Func Offset: 0xdc
	// Line 427, Address: 0x28ae70, Func Offset: 0xe0
	// Line 428, Address: 0x28ae74, Func Offset: 0xe4
	// Line 429, Address: 0x28ae7c, Func Offset: 0xec
	// Line 430, Address: 0x28ae88, Func Offset: 0xf8
	// Line 431, Address: 0x28ae94, Func Offset: 0x104
	// Line 432, Address: 0x28aea0, Func Offset: 0x110
	// Line 433, Address: 0x28aeac, Func Offset: 0x11c
	// Line 435, Address: 0x28aeb0, Func Offset: 0x120
	// Line 433, Address: 0x28aeb4, Func Offset: 0x124
	// Line 434, Address: 0x28aeb8, Func Offset: 0x128
	// Line 435, Address: 0x28aec0, Func Offset: 0x130
	// Line 436, Address: 0x28aec4, Func Offset: 0x134
	// Line 438, Address: 0x28aecc, Func Offset: 0x13c
	// Line 439, Address: 0x28aee4, Func Offset: 0x154
	// Line 443, Address: 0x28aeec, Func Offset: 0x15c
	// Line 439, Address: 0x28aef0, Func Offset: 0x160
	// Line 440, Address: 0x28aef8, Func Offset: 0x168
	// Line 441, Address: 0x28af08, Func Offset: 0x178
	// Line 442, Address: 0x28af18, Func Offset: 0x188
	// Line 444, Address: 0x28af1c, Func Offset: 0x18c
	// Line 446, Address: 0x28af24, Func Offset: 0x194
	// Line 448, Address: 0x28af3c, Func Offset: 0x1ac
	// Line 447, Address: 0x28af44, Func Offset: 0x1b4
	// Line 450, Address: 0x28af50, Func Offset: 0x1c0
	// Line 448, Address: 0x28af54, Func Offset: 0x1c4
	// Line 447, Address: 0x28af58, Func Offset: 0x1c8
	// Line 448, Address: 0x28af5c, Func Offset: 0x1cc
	// Line 447, Address: 0x28af68, Func Offset: 0x1d8
	// Line 448, Address: 0x28af6c, Func Offset: 0x1dc
	// Line 449, Address: 0x28af78, Func Offset: 0x1e8
	// Line 448, Address: 0x28af80, Func Offset: 0x1f0
	// Line 449, Address: 0x28af8c, Func Offset: 0x1fc
	// Line 450, Address: 0x28af94, Func Offset: 0x204
	// Line 453, Address: 0x28afa8, Func Offset: 0x218
	// Line 456, Address: 0x28afac, Func Offset: 0x21c
	// Line 453, Address: 0x28afb0, Func Offset: 0x220
	// Line 454, Address: 0x28afb8, Func Offset: 0x228
	// Line 455, Address: 0x28afc4, Func Offset: 0x234
	// Line 456, Address: 0x28afc8, Func Offset: 0x238
	// Line 459, Address: 0x28afd0, Func Offset: 0x240
	// Line 460, Address: 0x28b010, Func Offset: 0x280
	// Line 462, Address: 0x28b024, Func Offset: 0x294
	// Line 463, Address: 0x28b028, Func Offset: 0x298
	// Line 464, Address: 0x28b030, Func Offset: 0x2a0
	// Line 468, Address: 0x28b038, Func Offset: 0x2a8
	// Line 464, Address: 0x28b03c, Func Offset: 0x2ac
	// Line 465, Address: 0x28b044, Func Offset: 0x2b4
	// Line 466, Address: 0x28b054, Func Offset: 0x2c4
	// Line 467, Address: 0x28b064, Func Offset: 0x2d4
	// Line 474, Address: 0x28b06c, Func Offset: 0x2dc
	// Line 473, Address: 0x28b070, Func Offset: 0x2e0
	// Line 474, Address: 0x28b074, Func Offset: 0x2e4
	// Line 476, Address: 0x28b08c, Func Offset: 0x2fc
	// Line 477, Address: 0x28b09c, Func Offset: 0x30c
	// Line 481, Address: 0x28b0b0, Func Offset: 0x320
	// Line 482, Address: 0x28b0b4, Func Offset: 0x324
	// Line 483, Address: 0x28b0b8, Func Offset: 0x328
	// Line 484, Address: 0x28b0bc, Func Offset: 0x32c
	// Line 481, Address: 0x28b0c0, Func Offset: 0x330
	// Line 482, Address: 0x28b0c4, Func Offset: 0x334
	// Line 483, Address: 0x28b0cc, Func Offset: 0x33c
	// Line 484, Address: 0x28b0d0, Func Offset: 0x340
	// Line 485, Address: 0x28b0d8, Func Offset: 0x348
	// Line 542, Address: 0x28b0e8, Func Offset: 0x358
	// Line 541, Address: 0x28b0ec, Func Offset: 0x35c
	// Line 542, Address: 0x28b0f0, Func Offset: 0x360
	// Line 485, Address: 0x28b0f4, Func Offset: 0x364
	// Line 543, Address: 0x28b0f8, Func Offset: 0x368
	// Line 485, Address: 0x28b104, Func Offset: 0x374
	// Line 486, Address: 0x28b108, Func Offset: 0x378
	// Line 544, Address: 0x28b128, Func Offset: 0x398
	// Line 486, Address: 0x28b130, Func Offset: 0x3a0
	// Line 487, Address: 0x28b134, Func Offset: 0x3a4
	// Line 544, Address: 0x28b138, Func Offset: 0x3a8
	// Line 487, Address: 0x28b140, Func Offset: 0x3b0
	// Line 544, Address: 0x28b14c, Func Offset: 0x3bc
	// Line 487, Address: 0x28b150, Func Offset: 0x3c0
	// Line 488, Address: 0x28b154, Func Offset: 0x3c4
	// Line 491, Address: 0x28b158, Func Offset: 0x3c8
	// Line 544, Address: 0x28b15c, Func Offset: 0x3cc
	// Line 488, Address: 0x28b160, Func Offset: 0x3d0
	// Line 489, Address: 0x28b164, Func Offset: 0x3d4
	// Line 544, Address: 0x28b168, Func Offset: 0x3d8
	// Line 489, Address: 0x28b178, Func Offset: 0x3e8
	// Line 490, Address: 0x28b17c, Func Offset: 0x3ec
	// Line 544, Address: 0x28b180, Func Offset: 0x3f0
	// Line 490, Address: 0x28b184, Func Offset: 0x3f4
	// Line 491, Address: 0x28b188, Func Offset: 0x3f8
	// Line 544, Address: 0x28b18c, Func Offset: 0x3fc
	// Line 494, Address: 0x28b190, Func Offset: 0x400
	// Line 491, Address: 0x28b194, Func Offset: 0x404
	// Line 492, Address: 0x28b19c, Func Offset: 0x40c
	// Line 493, Address: 0x28b1ac, Func Offset: 0x41c
	// Line 494, Address: 0x28b1bc, Func Offset: 0x42c
	// Line 544, Address: 0x28b1c0, Func Offset: 0x430
	// Line 545, Address: 0x28b1c8, Func Offset: 0x438
	// Line 552, Address: 0x28b204, Func Offset: 0x474
	// Line 557, Address: 0x28b234, Func Offset: 0x4a4
	// Line 560, Address: 0x28b244, Func Offset: 0x4b4
	// Line 557, Address: 0x28b24c, Func Offset: 0x4bc
	// Line 560, Address: 0x28b250, Func Offset: 0x4c0
	// Line 557, Address: 0x28b254, Func Offset: 0x4c4
	// Line 558, Address: 0x28b25c, Func Offset: 0x4cc
	// Line 559, Address: 0x28b270, Func Offset: 0x4e0
	// Line 560, Address: 0x28b280, Func Offset: 0x4f0
	// Line 561, Address: 0x28b288, Func Offset: 0x4f8
	// Line 562, Address: 0x28b290, Func Offset: 0x500
	// Line 563, Address: 0x28b294, Func Offset: 0x504
	// Line 564, Address: 0x28b298, Func Offset: 0x508
	// Line 561, Address: 0x28b29c, Func Offset: 0x50c
	// Line 562, Address: 0x28b2a4, Func Offset: 0x514
	// Line 563, Address: 0x28b2b4, Func Offset: 0x524
	// Line 564, Address: 0x28b2c0, Func Offset: 0x530
	// Line 565, Address: 0x28b2c8, Func Offset: 0x538
	// Line 566, Address: 0x28b2cc, Func Offset: 0x53c
	// Line 567, Address: 0x28b2e0, Func Offset: 0x550
	// Line 569, Address: 0x28b2f0, Func Offset: 0x560
	// Line 571, Address: 0x28b2fc, Func Offset: 0x56c
	// Line 574, Address: 0x28b300, Func Offset: 0x570
	// Line 576, Address: 0x28b308, Func Offset: 0x578
	// Line 577, Address: 0x28b30c, Func Offset: 0x57c
	// Line 571, Address: 0x28b310, Func Offset: 0x580
	// Line 572, Address: 0x28b314, Func Offset: 0x584
	// Line 573, Address: 0x28b318, Func Offset: 0x588
	// Line 574, Address: 0x28b320, Func Offset: 0x590
	// Line 575, Address: 0x28b338, Func Offset: 0x5a8
	// Line 576, Address: 0x28b33c, Func Offset: 0x5ac
	// Line 577, Address: 0x28b358, Func Offset: 0x5c8
	// Line 578, Address: 0x28b360, Func Offset: 0x5d0
	// Line 579, Address: 0x28b368, Func Offset: 0x5d8
	// Line 580, Address: 0x28b38c, Func Offset: 0x5fc
	// Line 581, Address: 0x28b390, Func Offset: 0x600
	// Line 583, Address: 0x28b39c, Func Offset: 0x60c
	// Line 586, Address: 0x28b3b4, Func Offset: 0x624
	// Line 588, Address: 0x28b3c4, Func Offset: 0x634
	// Line 589, Address: 0x28b3fc, Func Offset: 0x66c
	// Line 591, Address: 0x28b404, Func Offset: 0x674
	// Line 592, Address: 0x28b41c, Func Offset: 0x68c
	// Line 594, Address: 0x28b420, Func Offset: 0x690
	// Line 600, Address: 0x28b424, Func Offset: 0x694
	// Line 601, Address: 0x28b42c, Func Offset: 0x69c
	// Line 594, Address: 0x28b434, Func Offset: 0x6a4
	// Line 595, Address: 0x28b438, Func Offset: 0x6a8
	// Line 596, Address: 0x28b440, Func Offset: 0x6b0
	// Line 597, Address: 0x28b448, Func Offset: 0x6b8
	// Line 598, Address: 0x28b450, Func Offset: 0x6c0
	// Line 599, Address: 0x28b458, Func Offset: 0x6c8
	// Line 601, Address: 0x28b460, Func Offset: 0x6d0
	// Line 604, Address: 0x28b470, Func Offset: 0x6e0
	// Line 607, Address: 0x28b478, Func Offset: 0x6e8
	// Line 604, Address: 0x28b47c, Func Offset: 0x6ec
	// Line 605, Address: 0x28b484, Func Offset: 0x6f4
	// Line 606, Address: 0x28b494, Func Offset: 0x704
	// Line 607, Address: 0x28b4a0, Func Offset: 0x710
	// Line 608, Address: 0x28b4a8, Func Offset: 0x718
	// Line 609, Address: 0x28b4c8, Func Offset: 0x738
	// Line 611, Address: 0x28b4f0, Func Offset: 0x760
	// Line 612, Address: 0x28b4f4, Func Offset: 0x764
	// Line 613, Address: 0x28b4f8, Func Offset: 0x768
	// Line 614, Address: 0x28b4fc, Func Offset: 0x76c
	// Line 610, Address: 0x28b500, Func Offset: 0x770
	// Line 615, Address: 0x28b504, Func Offset: 0x774
	// Line 611, Address: 0x28b508, Func Offset: 0x778
	// Line 616, Address: 0x28b50c, Func Offset: 0x77c
	// Line 618, Address: 0x28b510, Func Offset: 0x780
	// Line 629, Address: 0x28b51c, Func Offset: 0x78c
	// Line 631, Address: 0x28b528, Func Offset: 0x798
	// Line 632, Address: 0x28b52c, Func Offset: 0x79c
	// Line 633, Address: 0x28b530, Func Offset: 0x7a0
	// Line 635, Address: 0x28b534, Func Offset: 0x7a4
	// Line 636, Address: 0x28b53c, Func Offset: 0x7ac
	// Line 637, Address: 0x28b544, Func Offset: 0x7b4
	// Line 639, Address: 0x28b54c, Func Offset: 0x7bc
	// Line 640, Address: 0x28b554, Func Offset: 0x7c4
	// Line 642, Address: 0x28b55c, Func Offset: 0x7cc
	// Line 644, Address: 0x28b564, Func Offset: 0x7d4
	// Line 646, Address: 0x28b570, Func Offset: 0x7e0
	// Line 647, Address: 0x28b574, Func Offset: 0x7e4
	// Line 648, Address: 0x28b584, Func Offset: 0x7f4
	// Line 651, Address: 0x28b588, Func Offset: 0x7f8
	// Line 648, Address: 0x28b58c, Func Offset: 0x7fc
	// Line 649, Address: 0x28b59c, Func Offset: 0x80c
	// Line 650, Address: 0x28b5b4, Func Offset: 0x824
	// Line 651, Address: 0x28b5c8, Func Offset: 0x838
	// Line 652, Address: 0x28b5d0, Func Offset: 0x840
	// Line 654, Address: 0x28b5f8, Func Offset: 0x868
	// Line 653, Address: 0x28b5fc, Func Offset: 0x86c
	// Line 654, Address: 0x28b600, Func Offset: 0x870
	// Line 656, Address: 0x28b604, Func Offset: 0x874
	// Line 657, Address: 0x28b61c, Func Offset: 0x88c
	// Line 658, Address: 0x28b624, Func Offset: 0x894
	// Line 659, Address: 0x28b62c, Func Offset: 0x89c
	// Line 663, Address: 0x28b630, Func Offset: 0x8a0
	// Line 665, Address: 0x28b64c, Func Offset: 0x8bc
	// Line 667, Address: 0x28b684, Func Offset: 0x8f4
	// Line 668, Address: 0x28b68c, Func Offset: 0x8fc
	// Line 669, Address: 0x28b694, Func Offset: 0x904
	// Line 671, Address: 0x28b6b0, Func Offset: 0x920
	// Line 673, Address: 0x28b6e8, Func Offset: 0x958
	// Line 674, Address: 0x28b6f0, Func Offset: 0x960
	// Line 676, Address: 0x28b6f8, Func Offset: 0x968
	// Line 678, Address: 0x28b730, Func Offset: 0x9a0
	// Line 688, Address: 0x28b73c, Func Offset: 0x9ac
	// Line 690, Address: 0x28b774, Func Offset: 0x9e4
	// Line 700, Address: 0x28b790, Func Offset: 0xa00
	// Line 702, Address: 0x28b7b4, Func Offset: 0xa24
	// Line 704, Address: 0x28b7c0, Func Offset: 0xa30
	// Line 705, Address: 0x28b7c4, Func Offset: 0xa34
	// Line 706, Address: 0x28b7c8, Func Offset: 0xa38
	// Line 708, Address: 0x28b7cc, Func Offset: 0xa3c
	// Line 709, Address: 0x28b7d4, Func Offset: 0xa44
	// Line 710, Address: 0x28b7dc, Func Offset: 0xa4c
	// Line 712, Address: 0x28b7e4, Func Offset: 0xa54
	// Line 713, Address: 0x28b7ec, Func Offset: 0xa5c
	// Line 715, Address: 0x28b7f4, Func Offset: 0xa64
	// Line 717, Address: 0x28b7fc, Func Offset: 0xa6c
	// Line 719, Address: 0x28b808, Func Offset: 0xa78
	// Line 720, Address: 0x28b80c, Func Offset: 0xa7c
	// Line 721, Address: 0x28b81c, Func Offset: 0xa8c
	// Line 724, Address: 0x28b820, Func Offset: 0xa90
	// Line 721, Address: 0x28b824, Func Offset: 0xa94
	// Line 722, Address: 0x28b834, Func Offset: 0xaa4
	// Line 723, Address: 0x28b84c, Func Offset: 0xabc
	// Line 724, Address: 0x28b860, Func Offset: 0xad0
	// Line 725, Address: 0x28b868, Func Offset: 0xad8
	// Line 727, Address: 0x28b890, Func Offset: 0xb00
	// Line 726, Address: 0x28b894, Func Offset: 0xb04
	// Line 727, Address: 0x28b898, Func Offset: 0xb08
	// Line 729, Address: 0x28b89c, Func Offset: 0xb0c
	// Line 730, Address: 0x28b8b4, Func Offset: 0xb24
	// Line 731, Address: 0x28b8bc, Func Offset: 0xb2c
	// Line 736, Address: 0x28b8c4, Func Offset: 0xb34
	// Line 738, Address: 0x28b8e0, Func Offset: 0xb50
	// Line 739, Address: 0x28b924, Func Offset: 0xb94
	// Line 740, Address: 0x28b92c, Func Offset: 0xb9c
	// Line 741, Address: 0x28b934, Func Offset: 0xba4
	// Line 743, Address: 0x28b950, Func Offset: 0xbc0
	// Line 744, Address: 0x28b994, Func Offset: 0xc04
	// Line 745, Address: 0x28b99c, Func Offset: 0xc0c
	// Line 747, Address: 0x28b9a4, Func Offset: 0xc14
	// Line 748, Address: 0x28b9e8, Func Offset: 0xc58
	// Line 752, Address: 0x28b9f4, Func Offset: 0xc64
	// Line 753, Address: 0x28ba00, Func Offset: 0xc70
	// Line 756, Address: 0x28ba14, Func Offset: 0xc84
	// Line 753, Address: 0x28ba18, Func Offset: 0xc88
	// Line 754, Address: 0x28ba2c, Func Offset: 0xc9c
	// Line 755, Address: 0x28ba48, Func Offset: 0xcb8
	// Line 756, Address: 0x28ba64, Func Offset: 0xcd4
	// Line 757, Address: 0x28ba78, Func Offset: 0xce8
	// Line 758, Address: 0x28ba80, Func Offset: 0xcf0
	// Line 759, Address: 0x28ba90, Func Offset: 0xd00
	// Line 761, Address: 0x28baa0, Func Offset: 0xd10
	// Line 760, Address: 0x28baa4, Func Offset: 0xd14
	// Line 761, Address: 0x28baa8, Func Offset: 0xd18
	// Line 763, Address: 0x28baac, Func Offset: 0xd1c
	// Line 765, Address: 0x28bad8, Func Offset: 0xd48
	// Line 771, Address: 0x28bb14, Func Offset: 0xd84
	// Line 775, Address: 0x28bb60, Func Offset: 0xdd0
	// Line 778, Address: 0x28bb64, Func Offset: 0xdd4
	// Line 776, Address: 0x28bb68, Func Offset: 0xdd8
	// Line 779, Address: 0x28bb6c, Func Offset: 0xddc
	// Line 780, Address: 0x28bb70, Func Offset: 0xde0
	// Line 781, Address: 0x28bb74, Func Offset: 0xde4
	// Line 778, Address: 0x28bb78, Func Offset: 0xde8
	// Line 775, Address: 0x28bb7c, Func Offset: 0xdec
	// Line 781, Address: 0x28bb80, Func Offset: 0xdf0
	// Line 776, Address: 0x28bb84, Func Offset: 0xdf4
	// Line 779, Address: 0x28bb88, Func Offset: 0xdf8
	// Line 777, Address: 0x28bb8c, Func Offset: 0xdfc
	// Line 776, Address: 0x28bb90, Func Offset: 0xe00
	// Line 777, Address: 0x28bb94, Func Offset: 0xe04
	// Line 778, Address: 0x28bb9c, Func Offset: 0xe0c
	// Line 780, Address: 0x28bba0, Func Offset: 0xe10
	// Line 779, Address: 0x28bba4, Func Offset: 0xe14
	// Line 781, Address: 0x28bba8, Func Offset: 0xe18
	// Line 783, Address: 0x28bbb8, Func Offset: 0xe28
	// Line 784, Address: 0x28bbd0, Func Offset: 0xe40
	// Line 785, Address: 0x28bbd4, Func Offset: 0xe44
	// Line 786, Address: 0x28bbe0, Func Offset: 0xe50
	// Line 787, Address: 0x28bbec, Func Offset: 0xe5c
	// Line 789, Address: 0x28bbf0, Func Offset: 0xe60
	// Line 786, Address: 0x28bbf4, Func Offset: 0xe64
	// Line 787, Address: 0x28bc00, Func Offset: 0xe70
	// Line 790, Address: 0x28bc08, Func Offset: 0xe78
	// Line 791, Address: 0x28bc10, Func Offset: 0xe80
	// Line 787, Address: 0x28bc14, Func Offset: 0xe84
	// Line 788, Address: 0x28bc20, Func Offset: 0xe90
	// Line 789, Address: 0x28bc34, Func Offset: 0xea4
	// Line 790, Address: 0x28bc48, Func Offset: 0xeb8
	// Line 791, Address: 0x28bc5c, Func Offset: 0xecc
	// Line 793, Address: 0x28bc68, Func Offset: 0xed8
	// Line 796, Address: 0x28bc70, Func Offset: 0xee0
	// Line 793, Address: 0x28bc74, Func Offset: 0xee4
	// Line 794, Address: 0x28bc7c, Func Offset: 0xeec
	// Line 795, Address: 0x28bc8c, Func Offset: 0xefc
	// Line 796, Address: 0x28bc98, Func Offset: 0xf08
	// Line 797, Address: 0x28bca0, Func Offset: 0xf10
	// Line 798, Address: 0x28bcac, Func Offset: 0xf1c
	// Line 799, Address: 0x28bcf8, Func Offset: 0xf68
	// Line 800, Address: 0x28bd18, Func Offset: 0xf88
	// Line 799, Address: 0x28bd20, Func Offset: 0xf90
	// Line 800, Address: 0x28bd28, Func Offset: 0xf98
	// Line 799, Address: 0x28bd2c, Func Offset: 0xf9c
	// Line 800, Address: 0x28bd48, Func Offset: 0xfb8
	// Line 801, Address: 0x28bd64, Func Offset: 0xfd4
	// Line 802, Address: 0x28bd84, Func Offset: 0xff4
	// Line 803, Address: 0x28bd8c, Func Offset: 0xffc
	// Line 802, Address: 0x28bd94, Func Offset: 0x1004
	// Line 803, Address: 0x28bda0, Func Offset: 0x1010
	// Line 804, Address: 0x28bdb0, Func Offset: 0x1020
	// Line 805, Address: 0x28bde8, Func Offset: 0x1058
	// Line 804, Address: 0x28bdec, Func Offset: 0x105c
	// Line 806, Address: 0x28bdf4, Func Offset: 0x1064
	// Line 804, Address: 0x28be00, Func Offset: 0x1070
	// Line 805, Address: 0x28be0c, Func Offset: 0x107c
	// Line 804, Address: 0x28be10, Func Offset: 0x1080
	// Line 805, Address: 0x28be20, Func Offset: 0x1090
	// Line 806, Address: 0x28be34, Func Offset: 0x10a4
	// Line 807, Address: 0x28be4c, Func Offset: 0x10bc
	// Line 809, Address: 0x28be54, Func Offset: 0x10c4
	// Line 810, Address: 0x28be9c, Func Offset: 0x110c
	// Line 813, Address: 0x28bec0, Func Offset: 0x1130
	// Line 810, Address: 0x28bec8, Func Offset: 0x1138
	// Line 813, Address: 0x28bedc, Func Offset: 0x114c
	// Line 810, Address: 0x28bee0, Func Offset: 0x1150
	// Line 813, Address: 0x28bef4, Func Offset: 0x1164
	// Line 811, Address: 0x28bef8, Func Offset: 0x1168
	// Line 812, Address: 0x28bf10, Func Offset: 0x1180
	// Line 813, Address: 0x28bf24, Func Offset: 0x1194
	// Line 815, Address: 0x28bf54, Func Offset: 0x11c4
	// Line 816, Address: 0x28bf6c, Func Offset: 0x11dc
	// Line 818, Address: 0x28bfa4, Func Offset: 0x1214
	// Line 816, Address: 0x28bfb0, Func Offset: 0x1220
	// Line 817, Address: 0x28bfd4, Func Offset: 0x1244
	// Line 818, Address: 0x28bfe8, Func Offset: 0x1258
	// Line 819, Address: 0x28c000, Func Offset: 0x1270
	// Line 821, Address: 0x28c034, Func Offset: 0x12a4
	// Line 823, Address: 0x28c03c, Func Offset: 0x12ac
	// Line 824, Address: 0x28c054, Func Offset: 0x12c4
	// Line 825, Address: 0x28c078, Func Offset: 0x12e8
	// Line 824, Address: 0x28c07c, Func Offset: 0x12ec
	// Line 825, Address: 0x28c098, Func Offset: 0x1308
	// Line 826, Address: 0x28c09c, Func Offset: 0x130c
	// Line 824, Address: 0x28c0a8, Func Offset: 0x1318
	// Line 825, Address: 0x28c0bc, Func Offset: 0x132c
	// Line 826, Address: 0x28c0d0, Func Offset: 0x1340
	// Line 827, Address: 0x28c0e8, Func Offset: 0x1358
	// Line 831, Address: 0x28c11c, Func Offset: 0x138c
	// Line 833, Address: 0x28c12c, Func Offset: 0x139c
	// Line 835, Address: 0x28c130, Func Offset: 0x13a0
	// Line 840, Address: 0x28c18c, Func Offset: 0x13fc
	// Line 841, Address: 0x28c194, Func Offset: 0x1404
	// Line 840, Address: 0x28c198, Func Offset: 0x1408
	// Line 841, Address: 0x28c1a4, Func Offset: 0x1414
	// Line 842, Address: 0x28c1d4, Func Offset: 0x1444
	// Line 846, Address: 0x28c1f8, Func Offset: 0x1468
	// Line 847, Address: 0x28c208, Func Offset: 0x1478
	// Line 851, Address: 0x28c210, Func Offset: 0x1480
	// Line 847, Address: 0x28c220, Func Offset: 0x1490
	// Line 851, Address: 0x28c228, Func Offset: 0x1498
	// Line 848, Address: 0x28c230, Func Offset: 0x14a0
	// Line 851, Address: 0x28c238, Func Offset: 0x14a8
	// Line 848, Address: 0x28c240, Func Offset: 0x14b0
	// Line 849, Address: 0x28c244, Func Offset: 0x14b4
	// Line 848, Address: 0x28c248, Func Offset: 0x14b8
	// Line 849, Address: 0x28c24c, Func Offset: 0x14bc
	// Line 851, Address: 0x28c254, Func Offset: 0x14c4
	// Line 853, Address: 0x28c25c, Func Offset: 0x14cc
	// Line 860, Address: 0x28c270, Func Offset: 0x14e0
	// Line 862, Address: 0x28c28c, Func Offset: 0x14fc
	// Func End, Address: 0x28c2d8, Func Offset: 0x1548
}

// 
// Start address: 0x28c2e0
void bhCheckKnifeAtari(_anon21* gap)
{
	BH_PWORK* pp;
	int kno;
	int j;
	int i;
	float len;
	float ll;
	float knr;
	_anon1 wps;
	_anon1 ps;
	_anon1 sca;
	_anon34 cap;
	_anon43 gline;
	// Line 870, Address: 0x28c2e0, Func Offset: 0
	// Line 885, Address: 0x28c304, Func Offset: 0x24
	// Line 914, Address: 0x28c308, Func Offset: 0x28
	// Line 885, Address: 0x28c310, Func Offset: 0x30
	// Line 886, Address: 0x28c314, Func Offset: 0x34
	// Line 887, Address: 0x28c31c, Func Offset: 0x3c
	// Line 888, Address: 0x28c324, Func Offset: 0x44
	// Line 889, Address: 0x28c32c, Func Offset: 0x4c
	// Line 890, Address: 0x28c334, Func Offset: 0x54
	// Line 891, Address: 0x28c33c, Func Offset: 0x5c
	// Line 907, Address: 0x28c344, Func Offset: 0x64
	// Line 908, Address: 0x28c34c, Func Offset: 0x6c
	// Line 909, Address: 0x28c354, Func Offset: 0x74
	// Line 910, Address: 0x28c35c, Func Offset: 0x7c
	// Line 911, Address: 0x28c364, Func Offset: 0x84
	// Line 912, Address: 0x28c36c, Func Offset: 0x8c
	// Line 914, Address: 0x28c374, Func Offset: 0x94
	// Line 915, Address: 0x28c384, Func Offset: 0xa4
	// Line 934, Address: 0x28c398, Func Offset: 0xb8
	// Line 935, Address: 0x28c3a4, Func Offset: 0xc4
	// Line 939, Address: 0x28c3a8, Func Offset: 0xc8
	// Line 934, Address: 0x28c3ac, Func Offset: 0xcc
	// Line 935, Address: 0x28c3b8, Func Offset: 0xd8
	// Line 936, Address: 0x28c3cc, Func Offset: 0xec
	// Line 937, Address: 0x28c3e0, Func Offset: 0x100
	// Line 938, Address: 0x28c3f4, Func Offset: 0x114
	// Line 939, Address: 0x28c408, Func Offset: 0x128
	// Line 940, Address: 0x28c41c, Func Offset: 0x13c
	// Line 941, Address: 0x28c430, Func Offset: 0x150
	// Line 942, Address: 0x28c440, Func Offset: 0x160
	// Line 943, Address: 0x28c488, Func Offset: 0x1a8
	// Line 946, Address: 0x28c4ac, Func Offset: 0x1cc
	// Line 943, Address: 0x28c4b0, Func Offset: 0x1d0
	// Line 946, Address: 0x28c4c4, Func Offset: 0x1e4
	// Line 943, Address: 0x28c4cc, Func Offset: 0x1ec
	// Line 944, Address: 0x28c4e0, Func Offset: 0x200
	// Line 945, Address: 0x28c4f8, Func Offset: 0x218
	// Line 946, Address: 0x28c514, Func Offset: 0x234
	// Line 947, Address: 0x28c52c, Func Offset: 0x24c
	// Line 948, Address: 0x28c534, Func Offset: 0x254
	// Line 951, Address: 0x28c53c, Func Offset: 0x25c
	// Line 947, Address: 0x28c544, Func Offset: 0x264
	// Line 948, Address: 0x28c550, Func Offset: 0x270
	// Line 951, Address: 0x28c558, Func Offset: 0x278
	// Line 948, Address: 0x28c55c, Func Offset: 0x27c
	// Line 949, Address: 0x28c568, Func Offset: 0x288
	// Line 950, Address: 0x28c57c, Func Offset: 0x29c
	// Line 951, Address: 0x28c590, Func Offset: 0x2b0
	// Line 956, Address: 0x28c5a8, Func Offset: 0x2c8
	// Line 957, Address: 0x28c5c0, Func Offset: 0x2e0
	// Line 961, Address: 0x28c5e4, Func Offset: 0x304
	// Line 957, Address: 0x28c5ec, Func Offset: 0x30c
	// Line 961, Address: 0x28c5f8, Func Offset: 0x318
	// Line 962, Address: 0x28c608, Func Offset: 0x328
	// Line 963, Address: 0x28c610, Func Offset: 0x330
	// Line 964, Address: 0x28c614, Func Offset: 0x334
	// Line 965, Address: 0x28c618, Func Offset: 0x338
	// Line 962, Address: 0x28c61c, Func Offset: 0x33c
	// Line 963, Address: 0x28c624, Func Offset: 0x344
	// Line 964, Address: 0x28c630, Func Offset: 0x350
	// Line 965, Address: 0x28c638, Func Offset: 0x358
	// Line 967, Address: 0x28c640, Func Offset: 0x360
	// Line 970, Address: 0x28c688, Func Offset: 0x3a8
	// Line 972, Address: 0x28c698, Func Offset: 0x3b8
	// Line 974, Address: 0x28c6a4, Func Offset: 0x3c4
	// Line 972, Address: 0x28c6a8, Func Offset: 0x3c8
	// Line 973, Address: 0x28c6ac, Func Offset: 0x3cc
	// Line 974, Address: 0x28c6b8, Func Offset: 0x3d8
	// Line 975, Address: 0x28c6c4, Func Offset: 0x3e4
	// Line 976, Address: 0x28c6cc, Func Offset: 0x3ec
	// Line 980, Address: 0x28c6d4, Func Offset: 0x3f4
	// Line 981, Address: 0x28c6dc, Func Offset: 0x3fc
	// Line 982, Address: 0x28c6e4, Func Offset: 0x404
	// Line 989, Address: 0x28c720, Func Offset: 0x440
	// Line 994, Address: 0x28c74c, Func Offset: 0x46c
	// Line 1005, Address: 0x28c760, Func Offset: 0x480
	// Line 1007, Address: 0x28c780, Func Offset: 0x4a0
	// Line 1023, Address: 0x28c784, Func Offset: 0x4a4
	// Line 1024, Address: 0x28c788, Func Offset: 0x4a8
	// Line 1007, Address: 0x28c790, Func Offset: 0x4b0
	// Line 1009, Address: 0x28c798, Func Offset: 0x4b8
	// Line 1022, Address: 0x28c79c, Func Offset: 0x4bc
	// Line 1009, Address: 0x28c7a0, Func Offset: 0x4c0
	// Line 1010, Address: 0x28c7a4, Func Offset: 0x4c4
	// Line 1011, Address: 0x28c7ac, Func Offset: 0x4cc
	// Line 1013, Address: 0x28c7b4, Func Offset: 0x4d4
	// Line 1014, Address: 0x28c7bc, Func Offset: 0x4dc
	// Line 1015, Address: 0x28c7c4, Func Offset: 0x4e4
	// Line 1017, Address: 0x28c7cc, Func Offset: 0x4ec
	// Line 1018, Address: 0x28c7d4, Func Offset: 0x4f4
	// Line 1020, Address: 0x28c7dc, Func Offset: 0x4fc
	// Line 1024, Address: 0x28c7e0, Func Offset: 0x500
	// Line 1025, Address: 0x28c7e8, Func Offset: 0x508
	// Line 1028, Address: 0x28c7f8, Func Offset: 0x518
	// Line 1025, Address: 0x28c7fc, Func Offset: 0x51c
	// Line 1026, Address: 0x28c804, Func Offset: 0x524
	// Line 1027, Address: 0x28c820, Func Offset: 0x540
	// Line 1028, Address: 0x28c838, Func Offset: 0x558
	// Line 1029, Address: 0x28c840, Func Offset: 0x560
	// Line 1031, Address: 0x28c868, Func Offset: 0x588
	// Line 1030, Address: 0x28c86c, Func Offset: 0x58c
	// Line 1031, Address: 0x28c870, Func Offset: 0x590
	// Line 1033, Address: 0x28c874, Func Offset: 0x594
	// Line 1035, Address: 0x28c88c, Func Offset: 0x5ac
	// Line 1037, Address: 0x28c890, Func Offset: 0x5b0
	// Line 1038, Address: 0x28c8d8, Func Offset: 0x5f8
	// Line 1041, Address: 0x28c8e4, Func Offset: 0x604
	// Line 1045, Address: 0x28c910, Func Offset: 0x630
	// Func End, Address: 0x28c938, Func Offset: 0x658
}

// 
// Start address: 0x28c940
int bhCheckFlyAtari(_anon21* gap, int eidx)
{
	BH_PWORK* pp;
	int kno;
	int id;
	int j;
	int i;
	float nr;
	float ll;
	float knr;
	_anon1 ps;
	_anon1 sca;
	_anon46 spr;
	_anon34 wal;
	// Line 1057, Address: 0x28c940, Func Offset: 0
	// Line 1068, Address: 0x28c96c, Func Offset: 0x2c
	// Line 1088, Address: 0x28c970, Func Offset: 0x30
	// Line 1087, Address: 0x28c974, Func Offset: 0x34
	// Line 1088, Address: 0x28c978, Func Offset: 0x38
	// Line 1068, Address: 0x28c97c, Func Offset: 0x3c
	// Line 1069, Address: 0x28c980, Func Offset: 0x40
	// Line 1089, Address: 0x28c98c, Func Offset: 0x4c
	// Line 1069, Address: 0x28c990, Func Offset: 0x50
	// Line 1070, Address: 0x28c994, Func Offset: 0x54
	// Line 1071, Address: 0x28c99c, Func Offset: 0x5c
	// Line 1089, Address: 0x28c9a0, Func Offset: 0x60
	// Line 1090, Address: 0x28c9a8, Func Offset: 0x68
	// Line 1096, Address: 0x28c9ec, Func Offset: 0xac
	// Line 1098, Address: 0x28ca0c, Func Offset: 0xcc
	// Line 1099, Address: 0x28ca10, Func Offset: 0xd0
	// Line 1101, Address: 0x28ca24, Func Offset: 0xe4
	// Line 1102, Address: 0x28ca34, Func Offset: 0xf4
	// Line 1103, Address: 0x28ca38, Func Offset: 0xf8
	// Line 1104, Address: 0x28ca3c, Func Offset: 0xfc
	// Line 1108, Address: 0x28ca40, Func Offset: 0x100
	// Line 1109, Address: 0x28ca48, Func Offset: 0x108
	// Line 1102, Address: 0x28ca4c, Func Offset: 0x10c
	// Line 1103, Address: 0x28ca50, Func Offset: 0x110
	// Line 1104, Address: 0x28ca54, Func Offset: 0x114
	// Line 1105, Address: 0x28ca58, Func Offset: 0x118
	// Line 1109, Address: 0x28ca5c, Func Offset: 0x11c
	// Line 1105, Address: 0x28ca60, Func Offset: 0x120
	// Line 1106, Address: 0x28ca64, Func Offset: 0x124
	// Line 1107, Address: 0x28ca6c, Func Offset: 0x12c
	// Line 1109, Address: 0x28ca74, Func Offset: 0x134
	// Line 1122, Address: 0x28ca84, Func Offset: 0x144
	// Line 1138, Address: 0x28ca88, Func Offset: 0x148
	// Line 1139, Address: 0x28ca8c, Func Offset: 0x14c
	// Line 1122, Address: 0x28ca94, Func Offset: 0x154
	// Line 1124, Address: 0x28ca9c, Func Offset: 0x15c
	// Line 1111, Address: 0x28caa0, Func Offset: 0x160
	// Line 1137, Address: 0x28caa4, Func Offset: 0x164
	// Line 1124, Address: 0x28caa8, Func Offset: 0x168
	// Line 1125, Address: 0x28caac, Func Offset: 0x16c
	// Line 1126, Address: 0x28cab4, Func Offset: 0x174
	// Line 1128, Address: 0x28cabc, Func Offset: 0x17c
	// Line 1129, Address: 0x28cac4, Func Offset: 0x184
	// Line 1130, Address: 0x28cacc, Func Offset: 0x18c
	// Line 1132, Address: 0x28cad4, Func Offset: 0x194
	// Line 1133, Address: 0x28cadc, Func Offset: 0x19c
	// Line 1135, Address: 0x28cae4, Func Offset: 0x1a4
	// Line 1139, Address: 0x28cae8, Func Offset: 0x1a8
	// Line 1140, Address: 0x28caf0, Func Offset: 0x1b0
	// Line 1143, Address: 0x28caf8, Func Offset: 0x1b8
	// Line 1140, Address: 0x28cafc, Func Offset: 0x1bc
	// Line 1141, Address: 0x28cb0c, Func Offset: 0x1cc
	// Line 1142, Address: 0x28cb28, Func Offset: 0x1e8
	// Line 1143, Address: 0x28cb40, Func Offset: 0x200
	// Line 1144, Address: 0x28cb48, Func Offset: 0x208
	// Line 1146, Address: 0x28cb70, Func Offset: 0x230
	// Line 1145, Address: 0x28cb74, Func Offset: 0x234
	// Line 1146, Address: 0x28cb78, Func Offset: 0x238
	// Line 1148, Address: 0x28cb7c, Func Offset: 0x23c
	// Line 1150, Address: 0x28cb94, Func Offset: 0x254
	// Line 1152, Address: 0x28cb98, Func Offset: 0x258
	// Line 1153, Address: 0x28cba8, Func Offset: 0x268
	// Line 1154, Address: 0x28cbf0, Func Offset: 0x2b0
	// Line 1155, Address: 0x28cbf8, Func Offset: 0x2b8
	// Line 1157, Address: 0x28cc00, Func Offset: 0x2c0
	// Line 1160, Address: 0x28cc08, Func Offset: 0x2c8
	// Line 1157, Address: 0x28cc0c, Func Offset: 0x2cc
	// Line 1158, Address: 0x28cc14, Func Offset: 0x2d4
	// Line 1159, Address: 0x28cc24, Func Offset: 0x2e4
	// Line 1160, Address: 0x28cc30, Func Offset: 0x2f0
	// Line 1161, Address: 0x28cc38, Func Offset: 0x2f8
	// Line 1163, Address: 0x28cc54, Func Offset: 0x314
	// Line 1164, Address: 0x28cc9c, Func Offset: 0x35c
	// Line 1165, Address: 0x28cca4, Func Offset: 0x364
	// Line 1167, Address: 0x28ccac, Func Offset: 0x36c
	// Line 1168, Address: 0x28ccf4, Func Offset: 0x3b4
	// Line 1173, Address: 0x28cd00, Func Offset: 0x3c0
	// Line 1177, Address: 0x28cd28, Func Offset: 0x3e8
	// Line 1178, Address: 0x28cd2c, Func Offset: 0x3ec
	// Func End, Address: 0x28cd5c, Func Offset: 0x41c
}

// 
// Start address: 0x28cd60
void bhSetBowDamage()
{
	BH_PWORK* pp;
	int kno;
	int j;
	int i;
	float ll;
	float knr;
	_anon1 sca;
	// Line 1188, Address: 0x28cd60, Func Offset: 0
	// Line 1196, Address: 0x28cd84, Func Offset: 0x24
	// Line 1188, Address: 0x28cd88, Func Offset: 0x28
	// Line 1196, Address: 0x28cd8c, Func Offset: 0x2c
	// Line 1188, Address: 0x28cd90, Func Offset: 0x30
	// Line 1197, Address: 0x28cd94, Func Offset: 0x34
	// Line 1198, Address: 0x28cd9c, Func Offset: 0x3c
	// Line 1203, Address: 0x28cdd8, Func Offset: 0x78
	// Line 1206, Address: 0x28cdf8, Func Offset: 0x98
	// Line 1207, Address: 0x28ce28, Func Offset: 0xc8
	// Line 1211, Address: 0x28ce34, Func Offset: 0xd4
	// Line 1207, Address: 0x28ce38, Func Offset: 0xd8
	// Line 1208, Address: 0x28ce3c, Func Offset: 0xdc
	// Line 1207, Address: 0x28ce44, Func Offset: 0xe4
	// Line 1209, Address: 0x28ce48, Func Offset: 0xe8
	// Line 1211, Address: 0x28ce4c, Func Offset: 0xec
	// Line 1218, Address: 0x28ce50, Func Offset: 0xf0
	// Line 1209, Address: 0x28ce54, Func Offset: 0xf4
	// Line 1208, Address: 0x28ce58, Func Offset: 0xf8
	// Line 1224, Address: 0x28ce5c, Func Offset: 0xfc
	// Line 1228, Address: 0x28ce60, Func Offset: 0x100
	// Line 1207, Address: 0x28ce64, Func Offset: 0x104
	// Line 1211, Address: 0x28ce68, Func Offset: 0x108
	// Line 1226, Address: 0x28ce70, Func Offset: 0x110
	// Line 1209, Address: 0x28ce74, Func Offset: 0x114
	// Line 1213, Address: 0x28ce78, Func Offset: 0x118
	// Line 1208, Address: 0x28ce7c, Func Offset: 0x11c
	// Line 1209, Address: 0x28ce80, Func Offset: 0x120
	// Line 1214, Address: 0x28ce84, Func Offset: 0x124
	// Line 1215, Address: 0x28ce88, Func Offset: 0x128
	// Line 1217, Address: 0x28ce8c, Func Offset: 0x12c
	// Line 1218, Address: 0x28ce90, Func Offset: 0x130
	// Line 1219, Address: 0x28ce94, Func Offset: 0x134
	// Line 1221, Address: 0x28ce98, Func Offset: 0x138
	// Line 1222, Address: 0x28ce9c, Func Offset: 0x13c
	// Line 1227, Address: 0x28cea0, Func Offset: 0x140
	// Line 1228, Address: 0x28cea4, Func Offset: 0x144
	// Line 1229, Address: 0x28ceac, Func Offset: 0x14c
	// Line 1232, Address: 0x28ceb0, Func Offset: 0x150
	// Line 1229, Address: 0x28ceb4, Func Offset: 0x154
	// Line 1230, Address: 0x28cec4, Func Offset: 0x164
	// Line 1231, Address: 0x28cedc, Func Offset: 0x17c
	// Line 1232, Address: 0x28cef0, Func Offset: 0x190
	// Line 1233, Address: 0x28cef8, Func Offset: 0x198
	// Line 1235, Address: 0x28cf20, Func Offset: 0x1c0
	// Line 1234, Address: 0x28cf24, Func Offset: 0x1c4
	// Line 1235, Address: 0x28cf28, Func Offset: 0x1c8
	// Line 1237, Address: 0x28cf2c, Func Offset: 0x1cc
	// Line 1239, Address: 0x28cf44, Func Offset: 0x1e4
	// Line 1240, Address: 0x28cf48, Func Offset: 0x1e8
	// Line 1241, Address: 0x28cf78, Func Offset: 0x218
	// Line 1244, Address: 0x28cf84, Func Offset: 0x224
	// Line 1245, Address: 0x28cfb0, Func Offset: 0x250
	// Func End, Address: 0x28cfe0, Func Offset: 0x280
}

// 
// Start address: 0x28cfe0
void bhCheckBombAtari(_anon1* pos, float ar, int dmax, int dmin)
{
	float inn;
	_anon1 vec1;
	_anon1 vec0;
	BH_PWORK* pp;
	int kno;
	int j;
	int i;
	float nr;
	float ll;
	float knr;
	_anon1 ps;
	_anon1 sca;
	_anon46 spr;
	_anon34 wal;
	// Line 1257, Address: 0x28cfe0, Func Offset: 0
	// Line 1268, Address: 0x28d010, Func Offset: 0x30
	// Line 1271, Address: 0x28d014, Func Offset: 0x34
	// Line 1288, Address: 0x28d020, Func Offset: 0x40
	// Line 1268, Address: 0x28d028, Func Offset: 0x48
	// Line 1269, Address: 0x28d02c, Func Offset: 0x4c
	// Line 1270, Address: 0x28d034, Func Offset: 0x54
	// Line 1271, Address: 0x28d03c, Func Offset: 0x5c
	// Line 1288, Address: 0x28d040, Func Offset: 0x60
	// Line 1292, Address: 0x28d074, Func Offset: 0x94
	// Line 1293, Address: 0x28d080, Func Offset: 0xa0
	// Line 1292, Address: 0x28d084, Func Offset: 0xa4
	// Line 1293, Address: 0x28d088, Func Offset: 0xa8
	// Line 1295, Address: 0x28d09c, Func Offset: 0xbc
	// Line 1296, Address: 0x28d0b4, Func Offset: 0xd4
	// Line 1302, Address: 0x28d0b8, Func Offset: 0xd8
	// Line 1297, Address: 0x28d0bc, Func Offset: 0xdc
	// Line 1298, Address: 0x28d0c0, Func Offset: 0xe0
	// Line 1296, Address: 0x28d0c4, Func Offset: 0xe4
	// Line 1297, Address: 0x28d0c8, Func Offset: 0xe8
	// Line 1302, Address: 0x28d0cc, Func Offset: 0xec
	// Line 1303, Address: 0x28d0d0, Func Offset: 0xf0
	// Line 1297, Address: 0x28d0d8, Func Offset: 0xf8
	// Line 1298, Address: 0x28d0dc, Func Offset: 0xfc
	// Line 1299, Address: 0x28d0e4, Func Offset: 0x104
	// Line 1300, Address: 0x28d0ec, Func Offset: 0x10c
	// Line 1301, Address: 0x28d0f4, Func Offset: 0x114
	// Line 1303, Address: 0x28d0fc, Func Offset: 0x11c
	// Line 1315, Address: 0x28d10c, Func Offset: 0x12c
	// Line 1316, Address: 0x28d118, Func Offset: 0x138
	// Line 1315, Address: 0x28d11c, Func Offset: 0x13c
	// Line 1316, Address: 0x28d120, Func Offset: 0x140
	// Line 1317, Address: 0x28d128, Func Offset: 0x148
	// Line 1316, Address: 0x28d12c, Func Offset: 0x14c
	// Line 1317, Address: 0x28d130, Func Offset: 0x150
	// Line 1319, Address: 0x28d138, Func Offset: 0x158
	// Line 1317, Address: 0x28d13c, Func Offset: 0x15c
	// Line 1319, Address: 0x28d140, Func Offset: 0x160
	// Line 1320, Address: 0x28d150, Func Offset: 0x170
	// Line 1319, Address: 0x28d154, Func Offset: 0x174
	// Line 1320, Address: 0x28d158, Func Offset: 0x178
	// Line 1321, Address: 0x28d164, Func Offset: 0x184
	// Line 1320, Address: 0x28d168, Func Offset: 0x188
	// Line 1321, Address: 0x28d170, Func Offset: 0x190
	// Line 1323, Address: 0x28d17c, Func Offset: 0x19c
	// Line 1321, Address: 0x28d180, Func Offset: 0x1a0
	// Line 1323, Address: 0x28d188, Func Offset: 0x1a8
	// Line 1324, Address: 0x28d190, Func Offset: 0x1b0
	// Line 1329, Address: 0x28d1cc, Func Offset: 0x1ec
	// Line 1331, Address: 0x28d1dc, Func Offset: 0x1fc
	// Line 1329, Address: 0x28d1e4, Func Offset: 0x204
	// Line 1330, Address: 0x28d1ec, Func Offset: 0x20c
	// Line 1331, Address: 0x28d1f0, Func Offset: 0x210
	// Line 1332, Address: 0x28d1f8, Func Offset: 0x218
	// Line 1331, Address: 0x28d200, Func Offset: 0x220
	// Line 1335, Address: 0x28d208, Func Offset: 0x228
	// Line 1332, Address: 0x28d20c, Func Offset: 0x22c
	// Line 1333, Address: 0x28d218, Func Offset: 0x238
	// Line 1334, Address: 0x28d21c, Func Offset: 0x23c
	// Line 1335, Address: 0x28d224, Func Offset: 0x244
	// Line 1336, Address: 0x28d22c, Func Offset: 0x24c
	// Line 1337, Address: 0x28d238, Func Offset: 0x258
	// Line 1338, Address: 0x28d250, Func Offset: 0x270
	// Line 1340, Address: 0x28d268, Func Offset: 0x288
	// Line 1341, Address: 0x28d27c, Func Offset: 0x29c
	// Line 1349, Address: 0x28d28c, Func Offset: 0x2ac
	// Line 1341, Address: 0x28d290, Func Offset: 0x2b0
	// Line 1342, Address: 0x28d294, Func Offset: 0x2b4
	// Line 1341, Address: 0x28d298, Func Offset: 0x2b8
	// Line 1342, Address: 0x28d2a0, Func Offset: 0x2c0
	// Line 1343, Address: 0x28d2a8, Func Offset: 0x2c8
	// Line 1342, Address: 0x28d2ac, Func Offset: 0x2cc
	// Line 1343, Address: 0x28d2b4, Func Offset: 0x2d4
	// Line 1346, Address: 0x28d2bc, Func Offset: 0x2dc
	// Line 1343, Address: 0x28d2c0, Func Offset: 0x2e0
	// Line 1346, Address: 0x28d2c8, Func Offset: 0x2e8
	// Line 1347, Address: 0x28d2dc, Func Offset: 0x2fc
	// Line 1348, Address: 0x28d2ec, Func Offset: 0x30c
	// Line 1349, Address: 0x28d2f8, Func Offset: 0x318
	// Line 1350, Address: 0x28d300, Func Offset: 0x320
	// Line 1352, Address: 0x28d324, Func Offset: 0x344
	// Line 1353, Address: 0x28d334, Func Offset: 0x354
	// Line 1355, Address: 0x28d33c, Func Offset: 0x35c
	// Line 1363, Address: 0x28d350, Func Offset: 0x370
	// Line 1361, Address: 0x28d360, Func Offset: 0x380
	// Line 1364, Address: 0x28d368, Func Offset: 0x388
	// Line 1365, Address: 0x28d370, Func Offset: 0x390
	// Line 1370, Address: 0x28d3ac, Func Offset: 0x3cc
	// Line 1372, Address: 0x28d3cc, Func Offset: 0x3ec
	// Line 1373, Address: 0x28d3d0, Func Offset: 0x3f0
	// Line 1375, Address: 0x28d3e4, Func Offset: 0x404
	// Line 1385, Address: 0x28d3f4, Func Offset: 0x414
	// Line 1391, Address: 0x28d3f8, Func Offset: 0x418
	// Line 1386, Address: 0x28d3fc, Func Offset: 0x41c
	// Line 1387, Address: 0x28d400, Func Offset: 0x420
	// Line 1385, Address: 0x28d404, Func Offset: 0x424
	// Line 1386, Address: 0x28d408, Func Offset: 0x428
	// Line 1391, Address: 0x28d40c, Func Offset: 0x42c
	// Line 1392, Address: 0x28d410, Func Offset: 0x430
	// Line 1386, Address: 0x28d418, Func Offset: 0x438
	// Line 1387, Address: 0x28d41c, Func Offset: 0x43c
	// Line 1388, Address: 0x28d424, Func Offset: 0x444
	// Line 1389, Address: 0x28d42c, Func Offset: 0x44c
	// Line 1390, Address: 0x28d434, Func Offset: 0x454
	// Line 1392, Address: 0x28d43c, Func Offset: 0x45c
	// Line 1405, Address: 0x28d44c, Func Offset: 0x46c
	// Line 1406, Address: 0x28d458, Func Offset: 0x478
	// Line 1408, Address: 0x28d464, Func Offset: 0x484
	// Line 1409, Address: 0x28d46c, Func Offset: 0x48c
	// Line 1410, Address: 0x28d474, Func Offset: 0x494
	// Line 1412, Address: 0x28d47c, Func Offset: 0x49c
	// Line 1413, Address: 0x28d48c, Func Offset: 0x4ac
	// Line 1414, Address: 0x28d49c, Func Offset: 0x4bc
	// Line 1416, Address: 0x28d4ac, Func Offset: 0x4cc
	// Line 1417, Address: 0x28d4b0, Func Offset: 0x4d0
	// Line 1419, Address: 0x28d4dc, Func Offset: 0x4fc
	// Line 1422, Address: 0x28d4e0, Func Offset: 0x500
	// Line 1423, Address: 0x28d4e4, Func Offset: 0x504
	// Line 1419, Address: 0x28d4ec, Func Offset: 0x50c
	// Line 1423, Address: 0x28d4f0, Func Offset: 0x510
	// Line 1424, Address: 0x28d4f8, Func Offset: 0x518
	// Line 1427, Address: 0x28d500, Func Offset: 0x520
	// Line 1424, Address: 0x28d504, Func Offset: 0x524
	// Line 1425, Address: 0x28d514, Func Offset: 0x534
	// Line 1426, Address: 0x28d530, Func Offset: 0x550
	// Line 1427, Address: 0x28d548, Func Offset: 0x568
	// Line 1428, Address: 0x28d550, Func Offset: 0x570
	// Line 1430, Address: 0x28d578, Func Offset: 0x598
	// Line 1429, Address: 0x28d57c, Func Offset: 0x59c
	// Line 1430, Address: 0x28d580, Func Offset: 0x5a0
	// Line 1432, Address: 0x28d584, Func Offset: 0x5a4
	// Line 1434, Address: 0x28d59c, Func Offset: 0x5bc
	// Line 1437, Address: 0x28d5a0, Func Offset: 0x5c0
	// Line 1440, Address: 0x28d5a8, Func Offset: 0x5c8
	// Line 1437, Address: 0x28d5ac, Func Offset: 0x5cc
	// Line 1438, Address: 0x28d5b4, Func Offset: 0x5d4
	// Line 1439, Address: 0x28d5c4, Func Offset: 0x5e4
	// Line 1440, Address: 0x28d5d0, Func Offset: 0x5f0
	// Line 1441, Address: 0x28d5d8, Func Offset: 0x5f8
	// Line 1443, Address: 0x28d5e8, Func Offset: 0x608
	// Line 1444, Address: 0x28d5fc, Func Offset: 0x61c
	// Line 1445, Address: 0x28d604, Func Offset: 0x624
	// Line 1447, Address: 0x28d60c, Func Offset: 0x62c
	// Line 1448, Address: 0x28d620, Func Offset: 0x640
	// Line 1452, Address: 0x28d62c, Func Offset: 0x64c
	// Line 1456, Address: 0x28d658, Func Offset: 0x678
	// Func End, Address: 0x28d68c, Func Offset: 0x6ac
}

// 
// Start address: 0x28d690
int bhCheckCapCol2Capsule(BH_PWORK* pp, _anon34* cap, _anon1* hps)
{
	float nr;
	float len;
	int ct;
	int cpcl_no;
	int cap_r;
	int jnt_b;
	int jnt_a;
	int jno;
	_anon1 htp;
	_anon1 sca;
	_anon1 ofp;
	_anon43 gline;
	_anon46 sp;
	_anon34 cp;
	_anon29* cpcl;
	// Line 1469, Address: 0x28d690, Func Offset: 0
	// Line 1477, Address: 0x28d6c0, Func Offset: 0x30
	// Line 1480, Address: 0x28d6dc, Func Offset: 0x4c
	// Line 1479, Address: 0x28d6e0, Func Offset: 0x50
	// Line 1478, Address: 0x28d6ec, Func Offset: 0x5c
	// Line 1480, Address: 0x28d6f0, Func Offset: 0x60
	// Line 1481, Address: 0x28d6f4, Func Offset: 0x64
	// Line 1486, Address: 0x28d6fc, Func Offset: 0x6c
	// Line 1487, Address: 0x28d700, Func Offset: 0x70
	// Line 1481, Address: 0x28d704, Func Offset: 0x74
	// Line 1482, Address: 0x28d708, Func Offset: 0x78
	// Line 1483, Address: 0x28d714, Func Offset: 0x84
	// Line 1484, Address: 0x28d71c, Func Offset: 0x8c
	// Line 1483, Address: 0x28d720, Func Offset: 0x90
	// Line 1484, Address: 0x28d728, Func Offset: 0x98
	// Line 1485, Address: 0x28d730, Func Offset: 0xa0
	// Line 1484, Address: 0x28d734, Func Offset: 0xa4
	// Line 1485, Address: 0x28d73c, Func Offset: 0xac
	// Line 1491, Address: 0x28d74c, Func Offset: 0xbc
	// Line 1490, Address: 0x28d750, Func Offset: 0xc0
	// Line 1492, Address: 0x28d754, Func Offset: 0xc4
	// Line 1493, Address: 0x28d75c, Func Offset: 0xcc
	// Line 1494, Address: 0x28d764, Func Offset: 0xd4
	// Line 1495, Address: 0x28d768, Func Offset: 0xd8
	// Line 1498, Address: 0x28d778, Func Offset: 0xe8
	// Line 1495, Address: 0x28d77c, Func Offset: 0xec
	// Line 1498, Address: 0x28d780, Func Offset: 0xf0
	// Line 1495, Address: 0x28d784, Func Offset: 0xf4
	// Line 1498, Address: 0x28d788, Func Offset: 0xf8
	// Line 1495, Address: 0x28d794, Func Offset: 0x104
	// Line 1496, Address: 0x28d79c, Func Offset: 0x10c
	// Line 1497, Address: 0x28d7b4, Func Offset: 0x124
	// Line 1498, Address: 0x28d7c4, Func Offset: 0x134
	// Line 1499, Address: 0x28d7d8, Func Offset: 0x148
	// Line 1501, Address: 0x28d7e8, Func Offset: 0x158
	// Line 1499, Address: 0x28d7f0, Func Offset: 0x160
	// Line 1501, Address: 0x28d7fc, Func Offset: 0x16c
	// Line 1502, Address: 0x28d80c, Func Offset: 0x17c
	// Line 1503, Address: 0x28d81c, Func Offset: 0x18c
	// Line 1504, Address: 0x28d824, Func Offset: 0x194
	// Line 1505, Address: 0x28d828, Func Offset: 0x198
	// Line 1506, Address: 0x28d82c, Func Offset: 0x19c
	// Line 1503, Address: 0x28d830, Func Offset: 0x1a0
	// Line 1504, Address: 0x28d838, Func Offset: 0x1a8
	// Line 1505, Address: 0x28d848, Func Offset: 0x1b8
	// Line 1504, Address: 0x28d84c, Func Offset: 0x1bc
	// Line 1505, Address: 0x28d850, Func Offset: 0x1c0
	// Line 1506, Address: 0x28d85c, Func Offset: 0x1cc
	// Line 1507, Address: 0x28d864, Func Offset: 0x1d4
	// Line 1509, Address: 0x28d874, Func Offset: 0x1e4
	// Line 1511, Address: 0x28d878, Func Offset: 0x1e8
	// Line 1512, Address: 0x28d87c, Func Offset: 0x1ec
	// Line 1508, Address: 0x28d880, Func Offset: 0x1f0
	// Line 1510, Address: 0x28d884, Func Offset: 0x1f4
	// Line 1511, Address: 0x28d888, Func Offset: 0x1f8
	// Line 1512, Address: 0x28d88c, Func Offset: 0x1fc
	// Line 1513, Address: 0x28d894, Func Offset: 0x204
	// Line 1516, Address: 0x28d898, Func Offset: 0x208
	// Line 1517, Address: 0x28d8a0, Func Offset: 0x210
	// Line 1523, Address: 0x28d8ac, Func Offset: 0x21c
	// Line 1517, Address: 0x28d8b0, Func Offset: 0x220
	// Line 1523, Address: 0x28d8b4, Func Offset: 0x224
	// Line 1517, Address: 0x28d8b8, Func Offset: 0x228
	// Line 1525, Address: 0x28d8bc, Func Offset: 0x22c
	// Line 1517, Address: 0x28d8c0, Func Offset: 0x230
	// Line 1520, Address: 0x28d8c8, Func Offset: 0x238
	// Line 1523, Address: 0x28d8d0, Func Offset: 0x240
	// Line 1517, Address: 0x28d8d8, Func Offset: 0x248
	// Line 1518, Address: 0x28d8dc, Func Offset: 0x24c
	// Line 1523, Address: 0x28d8e0, Func Offset: 0x250
	// Line 1520, Address: 0x28d8e4, Func Offset: 0x254
	// Line 1523, Address: 0x28d8e8, Func Offset: 0x258
	// Line 1525, Address: 0x28d8ec, Func Offset: 0x25c
	// Line 1518, Address: 0x28d8f0, Func Offset: 0x260
	// Line 1525, Address: 0x28d8f4, Func Offset: 0x264
	// Line 1518, Address: 0x28d8f8, Func Offset: 0x268
	// Line 1519, Address: 0x28d904, Func Offset: 0x274
	// Line 1520, Address: 0x28d918, Func Offset: 0x288
	// Line 1521, Address: 0x28d92c, Func Offset: 0x29c
	// Line 1522, Address: 0x28d940, Func Offset: 0x2b0
	// Line 1525, Address: 0x28d954, Func Offset: 0x2c4
	// Line 1549, Address: 0x28d964, Func Offset: 0x2d4
	// Line 1550, Address: 0x28d96c, Func Offset: 0x2dc
	// Line 1551, Address: 0x28d970, Func Offset: 0x2e0
	// Line 1552, Address: 0x28d974, Func Offset: 0x2e4
	// Line 1549, Address: 0x28d978, Func Offset: 0x2e8
	// Line 1550, Address: 0x28d980, Func Offset: 0x2f0
	// Line 1551, Address: 0x28d990, Func Offset: 0x300
	// Line 1550, Address: 0x28d994, Func Offset: 0x304
	// Line 1551, Address: 0x28d998, Func Offset: 0x308
	// Line 1552, Address: 0x28d9a4, Func Offset: 0x314
	// Line 1553, Address: 0x28d9ac, Func Offset: 0x31c
	// Line 1555, Address: 0x28d9bc, Func Offset: 0x32c
	// Line 1557, Address: 0x28d9c0, Func Offset: 0x330
	// Line 1558, Address: 0x28d9c4, Func Offset: 0x334
	// Line 1554, Address: 0x28d9c8, Func Offset: 0x338
	// Line 1556, Address: 0x28d9cc, Func Offset: 0x33c
	// Line 1557, Address: 0x28d9d0, Func Offset: 0x340
	// Line 1558, Address: 0x28d9d4, Func Offset: 0x344
	// Line 1559, Address: 0x28d9dc, Func Offset: 0x34c
	// Line 1562, Address: 0x28d9e4, Func Offset: 0x354
	// Line 1564, Address: 0x28d9e8, Func Offset: 0x358
	// Line 1566, Address: 0x28d9ec, Func Offset: 0x35c
	// Line 1567, Address: 0x28d9f4, Func Offset: 0x364
	// Line 1568, Address: 0x28da00, Func Offset: 0x370
	// Line 1569, Address: 0x28da04, Func Offset: 0x374
	// Line 1572, Address: 0x28da08, Func Offset: 0x378
	// Func End, Address: 0x28da3c, Func Offset: 0x3ac
}

// 
// Start address: 0x28da40
void bhSetGunSplash(_anon21* gap, _anon1* pos, int wattr)
{
	_anon1 vec;
	// Line 1634, Address: 0x28da40, Func Offset: 0
	// Line 1636, Address: 0x28da58, Func Offset: 0x18
	// Line 1638, Address: 0x28da60, Func Offset: 0x20
	// Line 1636, Address: 0x28da6c, Func Offset: 0x2c
	// Line 1637, Address: 0x28da74, Func Offset: 0x34
	// Line 1638, Address: 0x28da80, Func Offset: 0x40
	// Line 1639, Address: 0x28da88, Func Offset: 0x48
	// Line 1640, Address: 0x28da94, Func Offset: 0x54
	// Line 1641, Address: 0x28daa0, Func Offset: 0x60
	// Line 1640, Address: 0x28daa4, Func Offset: 0x64
	// Line 1641, Address: 0x28dab0, Func Offset: 0x70
	// Line 1642, Address: 0x28dac4, Func Offset: 0x84
	// Line 1643, Address: 0x28dad8, Func Offset: 0x98
	// Line 1644, Address: 0x28daec, Func Offset: 0xac
	// Line 1645, Address: 0x28db04, Func Offset: 0xc4
	// Line 1646, Address: 0x28db1c, Func Offset: 0xdc
	// Line 1647, Address: 0x28db34, Func Offset: 0xf4
	// Line 1648, Address: 0x28db48, Func Offset: 0x108
	// Line 1651, Address: 0x28db70, Func Offset: 0x130
	// Line 1653, Address: 0x28db78, Func Offset: 0x138
	// Line 1651, Address: 0x28db88, Func Offset: 0x148
	// Line 1652, Address: 0x28db98, Func Offset: 0x158
	// Line 1654, Address: 0x28dba0, Func Offset: 0x160
	// Line 1655, Address: 0x28dba8, Func Offset: 0x168
	// Line 1652, Address: 0x28dbb0, Func Offset: 0x170
	// Line 1653, Address: 0x28dbbc, Func Offset: 0x17c
	// Line 1657, Address: 0x28dbc8, Func Offset: 0x188
	// Line 1653, Address: 0x28dbd0, Func Offset: 0x190
	// Line 1657, Address: 0x28dbf4, Func Offset: 0x1b4
	// Line 1653, Address: 0x28dbf8, Func Offset: 0x1b8
	// Line 1654, Address: 0x28dc00, Func Offset: 0x1c0
	// Line 1655, Address: 0x28dc38, Func Offset: 0x1f8
	// Line 1656, Address: 0x28dc70, Func Offset: 0x230
	// Line 1657, Address: 0x28dc90, Func Offset: 0x250
	// Line 1658, Address: 0x28dca8, Func Offset: 0x268
	// Line 1661, Address: 0x28dcb0, Func Offset: 0x270
	// Line 1662, Address: 0x28dcb8, Func Offset: 0x278
	// Line 1663, Address: 0x28dcc0, Func Offset: 0x280
	// Line 1661, Address: 0x28dcc8, Func Offset: 0x288
	// Line 1664, Address: 0x28dcd8, Func Offset: 0x298
	// Line 1662, Address: 0x28dcdc, Func Offset: 0x29c
	// Line 1664, Address: 0x28dce0, Func Offset: 0x2a0
	// Line 1662, Address: 0x28dce4, Func Offset: 0x2a4
	// Line 1666, Address: 0x28dcec, Func Offset: 0x2ac
	// Line 1662, Address: 0x28dcf0, Func Offset: 0x2b0
	// Line 1666, Address: 0x28dd14, Func Offset: 0x2d4
	// Line 1662, Address: 0x28dd1c, Func Offset: 0x2dc
	// Line 1663, Address: 0x28dd20, Func Offset: 0x2e0
	// Line 1664, Address: 0x28dd54, Func Offset: 0x314
	// Line 1665, Address: 0x28dd88, Func Offset: 0x348
	// Line 1666, Address: 0x28dda4, Func Offset: 0x364
	// Line 1667, Address: 0x28ddbc, Func Offset: 0x37c
	// Line 1668, Address: 0x28ddc8, Func Offset: 0x388
	// Line 1667, Address: 0x28ddd0, Func Offset: 0x390
	// Line 1668, Address: 0x28dde0, Func Offset: 0x3a0
	// Line 1669, Address: 0x28ddfc, Func Offset: 0x3bc
	// Line 1672, Address: 0x28de04, Func Offset: 0x3c4
	// Line 1673, Address: 0x28de0c, Func Offset: 0x3cc
	// Line 1675, Address: 0x28de14, Func Offset: 0x3d4
	// Line 1672, Address: 0x28de1c, Func Offset: 0x3dc
	// Line 1673, Address: 0x28de2c, Func Offset: 0x3ec
	// Line 1678, Address: 0x28de34, Func Offset: 0x3f4
	// Line 1679, Address: 0x28de3c, Func Offset: 0x3fc
	// Line 1673, Address: 0x28de44, Func Offset: 0x404
	// Line 1674, Address: 0x28de50, Func Offset: 0x410
	// Line 1680, Address: 0x28de58, Func Offset: 0x418
	// Line 1674, Address: 0x28de5c, Func Offset: 0x41c
	// Line 1680, Address: 0x28de60, Func Offset: 0x420
	// Line 1674, Address: 0x28de64, Func Offset: 0x424
	// Line 1675, Address: 0x28de70, Func Offset: 0x430
	// Line 1682, Address: 0x28de7c, Func Offset: 0x43c
	// Line 1675, Address: 0x28de88, Func Offset: 0x448
	// Line 1676, Address: 0x28dea8, Func Offset: 0x468
	// Line 1677, Address: 0x28decc, Func Offset: 0x48c
	// Line 1678, Address: 0x28def8, Func Offset: 0x4b8
	// Line 1679, Address: 0x28df2c, Func Offset: 0x4ec
	// Line 1680, Address: 0x28df60, Func Offset: 0x520
	// Line 1681, Address: 0x28df94, Func Offset: 0x554
	// Line 1682, Address: 0x28dfa8, Func Offset: 0x568
	// Line 1706, Address: 0x28dfc0, Func Offset: 0x580
	// Func End, Address: 0x28dfdc, Func Offset: 0x59c
}

// 
// Start address: 0x28dfe0
void bhSetExplosion(_anon1* pos)
{
	int i;
	_anon1 vc1;
	_anon1 vc0;
	_anon7* lp;
	_anon48 pnt;
	// Line 1715, Address: 0x28dfe0, Func Offset: 0
	// Line 1724, Address: 0x28dff0, Func Offset: 0x10
	// Line 1726, Address: 0x28dffc, Func Offset: 0x1c
	// Line 1727, Address: 0x28e004, Func Offset: 0x24
	// Line 1728, Address: 0x28e008, Func Offset: 0x28
	// Line 1729, Address: 0x28e00c, Func Offset: 0x2c
	// Line 1726, Address: 0x28e010, Func Offset: 0x30
	// Line 1734, Address: 0x28e014, Func Offset: 0x34
	// Line 1735, Address: 0x28e018, Func Offset: 0x38
	// Line 1736, Address: 0x28e01c, Func Offset: 0x3c
	// Line 1727, Address: 0x28e020, Func Offset: 0x40
	// Line 1728, Address: 0x28e024, Func Offset: 0x44
	// Line 1729, Address: 0x28e028, Func Offset: 0x48
	// Line 1730, Address: 0x28e02c, Func Offset: 0x4c
	// Line 1731, Address: 0x28e030, Func Offset: 0x50
	// Line 1732, Address: 0x28e034, Func Offset: 0x54
	// Line 1733, Address: 0x28e038, Func Offset: 0x58
	// Line 1734, Address: 0x28e03c, Func Offset: 0x5c
	// Line 1735, Address: 0x28e040, Func Offset: 0x60
	// Line 1737, Address: 0x28e044, Func Offset: 0x64
	// Line 1736, Address: 0x28e048, Func Offset: 0x68
	// Line 1737, Address: 0x28e04c, Func Offset: 0x6c
	// Line 1738, Address: 0x28e050, Func Offset: 0x70
	// Line 1739, Address: 0x28e058, Func Offset: 0x78
	// Line 1740, Address: 0x28e060, Func Offset: 0x80
	// Line 1755, Address: 0x28e064, Func Offset: 0x84
	// Line 1740, Address: 0x28e070, Func Offset: 0x90
	// Line 1741, Address: 0x28e074, Func Offset: 0x94
	// Line 1755, Address: 0x28e078, Func Offset: 0x98
	// Line 1741, Address: 0x28e07c, Func Offset: 0x9c
	// Line 1742, Address: 0x28e080, Func Offset: 0xa0
	// Line 1743, Address: 0x28e088, Func Offset: 0xa8
	// Line 1744, Address: 0x28e08c, Func Offset: 0xac
	// Line 1745, Address: 0x28e090, Func Offset: 0xb0
	// Line 1746, Address: 0x28e094, Func Offset: 0xb4
	// Line 1747, Address: 0x28e098, Func Offset: 0xb8
	// Line 1749, Address: 0x28e09c, Func Offset: 0xbc
	// Line 1750, Address: 0x28e0a4, Func Offset: 0xc4
	// Line 1751, Address: 0x28e0ac, Func Offset: 0xcc
	// Line 1752, Address: 0x28e0b4, Func Offset: 0xd4
	// Line 1753, Address: 0x28e0b8, Func Offset: 0xd8
	// Line 1755, Address: 0x28e0bc, Func Offset: 0xdc
	// Line 1757, Address: 0x28e0c4, Func Offset: 0xe4
	// Line 1765, Address: 0x28e0cc, Func Offset: 0xec
	// Line 1757, Address: 0x28e0d0, Func Offset: 0xf0
	// Line 1765, Address: 0x28e0d4, Func Offset: 0xf4
	// Line 1758, Address: 0x28e0d8, Func Offset: 0xf8
	// Line 1757, Address: 0x28e0dc, Func Offset: 0xfc
	// Line 1758, Address: 0x28e0e8, Func Offset: 0x108
	// Line 1762, Address: 0x28e0f0, Func Offset: 0x110
	// Line 1770, Address: 0x28e0f4, Func Offset: 0x114
	// Line 1758, Address: 0x28e100, Func Offset: 0x120
	// Line 1759, Address: 0x28e10c, Func Offset: 0x12c
	// Line 1760, Address: 0x28e120, Func Offset: 0x140
	// Line 1761, Address: 0x28e134, Func Offset: 0x154
	// Line 1762, Address: 0x28e148, Func Offset: 0x168
	// Line 1763, Address: 0x28e15c, Func Offset: 0x17c
	// Line 1764, Address: 0x28e170, Func Offset: 0x190
	// Line 1765, Address: 0x28e184, Func Offset: 0x1a4
	// Line 1766, Address: 0x28e1ac, Func Offset: 0x1cc
	// Line 1767, Address: 0x28e1d4, Func Offset: 0x1f4
	// Line 1768, Address: 0x28e1fc, Func Offset: 0x21c
	// Line 1769, Address: 0x28e210, Func Offset: 0x230
	// Line 1770, Address: 0x28e224, Func Offset: 0x244
	// Line 1772, Address: 0x28e23c, Func Offset: 0x25c
	// Line 1773, Address: 0x28e240, Func Offset: 0x260
	// Line 1774, Address: 0x28e248, Func Offset: 0x268
	// Line 1775, Address: 0x28e250, Func Offset: 0x270
	// Line 1776, Address: 0x28e25c, Func Offset: 0x27c
	// Line 1779, Address: 0x28e260, Func Offset: 0x280
	// Line 1775, Address: 0x28e264, Func Offset: 0x284
	// Line 1776, Address: 0x28e270, Func Offset: 0x290
	// Line 1777, Address: 0x28e284, Func Offset: 0x2a4
	// Line 1778, Address: 0x28e298, Func Offset: 0x2b8
	// Line 1779, Address: 0x28e2ac, Func Offset: 0x2cc
	// Line 1780, Address: 0x28e2bc, Func Offset: 0x2dc
	// Line 1781, Address: 0x28e300, Func Offset: 0x320
	// Line 1782, Address: 0x28e320, Func Offset: 0x340
	// Line 1783, Address: 0x28e330, Func Offset: 0x350
	// Line 1784, Address: 0x28e384, Func Offset: 0x3a4
	// Line 1785, Address: 0x28e3d0, Func Offset: 0x3f0
	// Line 1784, Address: 0x28e3d4, Func Offset: 0x3f4
	// Line 1785, Address: 0x28e3dc, Func Offset: 0x3fc
	// Line 1786, Address: 0x28e3e4, Func Offset: 0x404
	// Line 1787, Address: 0x28e410, Func Offset: 0x430
	// Line 1788, Address: 0x28e420, Func Offset: 0x440
	// Line 1789, Address: 0x28e444, Func Offset: 0x464
	// Line 1790, Address: 0x28e454, Func Offset: 0x474
	// Func End, Address: 0x28e464, Func Offset: 0x484
}

// 
// Start address: 0x28e470
void bhSetExplosionEffect(_anon1* pos)
{
	int i;
	_anon1 vc1;
	_anon1 vc0;
	// Line 1799, Address: 0x28e470, Func Offset: 0
	// Line 1803, Address: 0x28e47c, Func Offset: 0xc
	// Line 1811, Address: 0x28e484, Func Offset: 0x14
	// Line 1803, Address: 0x28e488, Func Offset: 0x18
	// Line 1811, Address: 0x28e48c, Func Offset: 0x1c
	// Line 1804, Address: 0x28e490, Func Offset: 0x20
	// Line 1803, Address: 0x28e494, Func Offset: 0x24
	// Line 1804, Address: 0x28e4a0, Func Offset: 0x30
	// Line 1808, Address: 0x28e4a8, Func Offset: 0x38
	// Line 1816, Address: 0x28e4ac, Func Offset: 0x3c
	// Line 1804, Address: 0x28e4b8, Func Offset: 0x48
	// Line 1805, Address: 0x28e4c4, Func Offset: 0x54
	// Line 1806, Address: 0x28e4d8, Func Offset: 0x68
	// Line 1807, Address: 0x28e4ec, Func Offset: 0x7c
	// Line 1808, Address: 0x28e500, Func Offset: 0x90
	// Line 1809, Address: 0x28e514, Func Offset: 0xa4
	// Line 1810, Address: 0x28e528, Func Offset: 0xb8
	// Line 1811, Address: 0x28e53c, Func Offset: 0xcc
	// Line 1812, Address: 0x28e564, Func Offset: 0xf4
	// Line 1813, Address: 0x28e58c, Func Offset: 0x11c
	// Line 1814, Address: 0x28e5b4, Func Offset: 0x144
	// Line 1815, Address: 0x28e5c8, Func Offset: 0x158
	// Line 1816, Address: 0x28e5dc, Func Offset: 0x16c
	// Line 1818, Address: 0x28e5f4, Func Offset: 0x184
	// Line 1819, Address: 0x28e5f8, Func Offset: 0x188
	// Line 1820, Address: 0x28e600, Func Offset: 0x190
	// Line 1821, Address: 0x28e608, Func Offset: 0x198
	// Line 1822, Address: 0x28e614, Func Offset: 0x1a4
	// Line 1825, Address: 0x28e618, Func Offset: 0x1a8
	// Line 1821, Address: 0x28e61c, Func Offset: 0x1ac
	// Line 1822, Address: 0x28e628, Func Offset: 0x1b8
	// Line 1823, Address: 0x28e63c, Func Offset: 0x1cc
	// Line 1824, Address: 0x28e650, Func Offset: 0x1e0
	// Line 1825, Address: 0x28e664, Func Offset: 0x1f4
	// Line 1826, Address: 0x28e674, Func Offset: 0x204
	// Line 1827, Address: 0x28e6b8, Func Offset: 0x248
	// Line 1828, Address: 0x28e6d8, Func Offset: 0x268
	// Line 1829, Address: 0x28e6e8, Func Offset: 0x278
	// Line 1830, Address: 0x28e73c, Func Offset: 0x2cc
	// Line 1831, Address: 0x28e788, Func Offset: 0x318
	// Line 1830, Address: 0x28e78c, Func Offset: 0x31c
	// Line 1831, Address: 0x28e794, Func Offset: 0x324
	// Line 1832, Address: 0x28e79c, Func Offset: 0x32c
	// Line 1833, Address: 0x28e7c8, Func Offset: 0x358
	// Line 1834, Address: 0x28e7d8, Func Offset: 0x368
	// Line 1835, Address: 0x28e7fc, Func Offset: 0x38c
	// Line 1836, Address: 0x28e80c, Func Offset: 0x39c
	// Func End, Address: 0x28e81c, Func Offset: 0x3ac
}

// 
// Start address: 0x28e820
void bhSetExplosionEffectEx(_anon1* pos, float scl)
{
	// Line 1849, Address: 0x28e820, Func Offset: 0
	// Line 1857, Address: 0x28e828, Func Offset: 0x8
	// Line 1849, Address: 0x28e82c, Func Offset: 0xc
	// Line 1857, Address: 0x28e830, Func Offset: 0x10
	// Line 1850, Address: 0x28e834, Func Offset: 0x14
	// Line 1849, Address: 0x28e838, Func Offset: 0x18
	// Line 1850, Address: 0x28e844, Func Offset: 0x24
	// Line 1851, Address: 0x28e84c, Func Offset: 0x2c
	// Line 1862, Address: 0x28e850, Func Offset: 0x30
	// Line 1850, Address: 0x28e85c, Func Offset: 0x3c
	// Line 1851, Address: 0x28e868, Func Offset: 0x48
	// Line 1852, Address: 0x28e87c, Func Offset: 0x5c
	// Line 1853, Address: 0x28e890, Func Offset: 0x70
	// Line 1854, Address: 0x28e8a4, Func Offset: 0x84
	// Line 1855, Address: 0x28e8b8, Func Offset: 0x98
	// Line 1856, Address: 0x28e8cc, Func Offset: 0xac
	// Line 1857, Address: 0x28e8e0, Func Offset: 0xc0
	// Line 1858, Address: 0x28e908, Func Offset: 0xe8
	// Line 1859, Address: 0x28e930, Func Offset: 0x110
	// Line 1860, Address: 0x28e958, Func Offset: 0x138
	// Line 1861, Address: 0x28e96c, Func Offset: 0x14c
	// Line 1862, Address: 0x28e980, Func Offset: 0x160
	// Func End, Address: 0x28e998, Func Offset: 0x178
}

