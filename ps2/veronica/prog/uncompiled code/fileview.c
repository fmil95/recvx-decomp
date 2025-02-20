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
typedef struct _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct BH_PWORK;
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

typedef void(*type_73)(void*);
typedef void(*type_75)();

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
typedef _anon0* type_10[512];
typedef _anon1* type_11[1300];
typedef char type_12[32];
typedef _anon0* type_13[512];
typedef _anon1* type_14[200];
typedef short type_15[32];
typedef _anon16 type_16[1];
typedef _anon0* type_17[128];
typedef unsigned int type_18[1];
typedef _anon5 type_19[256];
typedef _anon1* type_20[8];
typedef int* type_21[16];
typedef _anon0* type_22[128];
typedef npobj* type_23[16];
typedef _anon0* type_24[128];
typedef int type_25[4];
typedef _anon1* type_26[16];
typedef unsigned int type_27[4];
typedef _anon8 type_28[16];
typedef _anon0* type_29[512];
typedef char type_30[256];
typedef float type_31[4];
typedef float type_32[4];
typedef float type_33[4];
typedef _anon3* type_34[128];
typedef unsigned char type_35[64];
typedef float type_36[16];
typedef _anon26 type_37[2];
typedef char type_38[8];
typedef void* type_39[2];
typedef unsigned int type_40[24];
typedef _anon1* type_41[256];
typedef int type_42[4];
typedef unsigned char* type_43[256];
typedef unsigned int type_44[2];
typedef short type_45[256];
typedef _anon24 type_46[4];
typedef float type_47[3];
typedef short type_48[256];
typedef int type_49[3];
typedef int type_50[8];
typedef float type_51[3];
typedef _anon1* type_52[256];
typedef _anon7 type_53[256];
typedef int type_54[3];
typedef _anon35 type_55[0];
typedef _anon16 type_56[450];
typedef _anon26 type_57[16];
typedef short type_58[256];
typedef char type_59[3];
typedef int type_60[64];
typedef _anon8 type_61[450];
typedef _anon16 type_62[1];
typedef unsigned int type_63[24];
typedef _anon16 type_64[1];
typedef _anon31 type_65[4];
typedef _anon2 type_66[4];
typedef int type_67[450];
typedef unsigned int type_68[8];
typedef unsigned char type_69[450];
typedef _anon23 type_70[0];
typedef char type_71[16];
typedef char type_72[4];
typedef unsigned int type_74[32];
typedef void(*type_76)()[5];
typedef unsigned int type_77[16];
typedef _anon33 type_78[64];
typedef unsigned int type_79[16];
typedef float type_80[3];
typedef _anon33 type_81[64];
typedef unsigned int type_82[32];
typedef _anon33 type_83[64];
typedef unsigned int type_84[16];
typedef unsigned int type_85[3];
typedef BH_PWORK* type_86[16];
typedef unsigned int type_87[8];
typedef short type_88[16];
typedef unsigned int type_89[1];
typedef unsigned int type_90[384];
typedef unsigned int type_91[2];
typedef short type_92[16];
typedef float type_93[6];
typedef unsigned char type_94[2];
typedef float type_95[6][0];
typedef int* type_96[16];
typedef unsigned int type_97[4];
typedef char type_98[32];
typedef npobj* type_99[16];
typedef unsigned char type_100[4];
typedef unsigned char type_101[4][0];
typedef float type_102[6];
typedef char type_103[64];
typedef float type_104[6][0];
typedef _anon1* type_105[16];
typedef char type_106[4];
typedef _anon8 type_107[16];
typedef _anon16 type_108[5];
typedef short type_109[4];
typedef _anon35 type_110[0];
typedef _anon35 type_111[24];
typedef unsigned char type_112[4];
typedef _anon29 type_113[16];
typedef unsigned int type_114[32];
typedef _anon28 type_115[32];
typedef _anon0* type_116[512];
typedef unsigned int type_117[24];
typedef _anon0* type_118[128];
typedef _anon0* type_119[512];
typedef unsigned char type_120[64];
typedef _anon0* type_121[512];

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
	_anon38 cspr;
	int pn;
	_anon31* pvp;
	_anon2* tvp;
	_anon31 pv[4];
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
	_anon16* textures;
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

struct _anon3
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon15* md2P;
	unsigned short* atrP;
};

struct _anon4
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
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
	_anon21* owP;
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
	_anon36* info;
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
	_anon20 col;
	_anon16 fstx[1];
	_anon1 fstx_list;
	_anon16 fbtx[1];
	_anon1 fbtx_list;
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

struct _anon12
{
	_anon16 subtx[5];
	_anon1 subtx_list;
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
	_anon4 scr;
	_anon26 clip[2];
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

struct _anon13
{
	void* texaddr;
	_anon6 texsurface;
};

struct _anon14
{
	_anon8 mdl;
	_anon27 mw;
	unsigned char* keep;
	unsigned char* keepbackup;
};

struct _anon15
{
	void* p[2];
};

struct _anon16
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon17
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon18
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
	_anon22* light;
};

struct _anon19
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
	_anon28 ply_pos;
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
	_anon16 ef_tex[450];
	_anon1 ef_tlist;
	_anon32 ef;
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
	_anon16 ren_tex[1];
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
	_anon34 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon18* lgtp;
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
	_anon26 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon33* pl_htp;
	int costume;
	_anon28 hd_pos;
	_anon28 apos;
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
	_anon28 ufo_pos;
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
	_anon29 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon28 ghtp[32];
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

struct _anon20
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon21
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon22
{
	float mtrx[16];
	_anon28 pnt;
	_anon28 vctr;
	int stat;
	int reserve;
	_anon30 ltcal;
	_anon37 attr;
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
	_anon39 watr;
	_anon17* cpcl;
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

struct _anon23
{
	unsigned int globalIndex;
	unsigned int bank;
	unsigned int tspparambuffer;
	unsigned int texparambuffer;
	unsigned int texaddr;
	_anon13 texinfo;
	unsigned short count;
	unsigned short dummy;
};

struct _anon24
{
	_anon28 ps;
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
	_anon28 center;
	float r;
};

struct _anon26
{
	float x;
	float y;
};

struct _anon27
{
	_anon28 pos;
	void* tex_p;
	void* mdl_p;
	int ang[3];
	int rdid;
	int ax1;
	int ay1;
	int az1;
	unsigned short flg;
};

struct _anon28
{
	float x;
	float y;
	float z;
};

struct _anon29
{
	_anon28 c1;
	_anon28 c2;
	float r1;
	float r2;
};

struct _anon30
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
	_anon28 lpnt;
	_anon28 lvctr;
	_anon28 lmvctr;
	_anon20 atten;
	_anon20 amb;
	_anon20 dif;
	_anon20 spc;
	_anon20 mamb;
	_anon20 mdif;
	_anon20 mspc;
};

struct _anon31
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon32
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

struct _anon35
{
	float pos[3];
	short ang;
	unsigned char atr;
	char anim;
	unsigned char cen_no;
	unsigned char parts_num;
	float move;
	unsigned char setnum;
	_anon20 col;
	unsigned char color;
};

struct _anon36
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

struct _anon37
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
	_anon20 argb;
};

struct _anon38
{
	_anon28 c;
	float r;
};

struct _anon39
{
	_anon28 c1;
	_anon28 c2;
	float r;
};

unsigned int fstbl[24];
unsigned int fsheader[24];
unsigned int wallpaper[24];
void(*FileViewMode)()[5];
_anon11 fvwork;
_anon35 parts_22b[0];
_anon19* sys;
_anon12 swork;
char ViewCnt;
_anon23 tbuf[0];
unsigned char menuanim[4][0];
_anon35 parts_00b[24];
_anon35 parts_10b[0];
_anon14 sitem;
float cen_pos[6][0];
float cen_pos99[6][0];

void ControlFileView();
void FileSelect();
void FileFlagInit01();
void FileFlagInit();
void GetFile();
void FileViewInit();
void FileViewMain();
void FileViewExit();
void FileExit00();
void FileExit01();
int SearchTag(int dir);
void SelectFile();
void SelectTag();
void FileScreenCancel();
void FileScrollSet();
void FileGetWait();
void PageScroll();
void FileEtcDisplay();
void StatusToFileView();
void ReadFstx();
unsigned int FileNumberSwitch(unsigned int num);
int PlayPageCheck();

// 
// Start address: 0x2abfc0
void ControlFileView()
{
	// Line 161, Address: 0x2abfc0, Func Offset: 0
	// Line 163, Address: 0x2abfc8, Func Offset: 0x8
	// Line 164, Address: 0x2abfec, Func Offset: 0x2c
	// Line 165, Address: 0x2abff4, Func Offset: 0x34
	// Func End, Address: 0x2ac000, Func Offset: 0x40
}

// 
// Start address: 0x2ac000
void FileSelect()
{
	_anon11* fv;
	// Line 171, Address: 0x2ac000, Func Offset: 0
	// Line 175, Address: 0x2ac008, Func Offset: 0x8
	// Line 173, Address: 0x2ac00c, Func Offset: 0xc
	// Line 175, Address: 0x2ac014, Func Offset: 0x14
	// Line 178, Address: 0x2ac040, Func Offset: 0x40
	// Line 180, Address: 0x2ac044, Func Offset: 0x44
	// Line 181, Address: 0x2ac04c, Func Offset: 0x4c
	// Line 184, Address: 0x2ac054, Func Offset: 0x54
	// Line 185, Address: 0x2ac05c, Func Offset: 0x5c
	// Line 187, Address: 0x2ac064, Func Offset: 0x64
	// Line 190, Address: 0x2ac06c, Func Offset: 0x6c
	// Func End, Address: 0x2ac078, Func Offset: 0x78
}

// 
// Start address: 0x2ac080
void FileFlagInit01()
{
	// Line 199, Address: 0x2ac080, Func Offset: 0
	// Line 195, Address: 0x2ac088, Func Offset: 0x8
	// Line 196, Address: 0x2ac094, Func Offset: 0x14
	// Line 198, Address: 0x2ac09c, Func Offset: 0x1c
	// Line 203, Address: 0x2ac0a4, Func Offset: 0x24
	// Line 199, Address: 0x2ac0b0, Func Offset: 0x30
	// Line 198, Address: 0x2ac0bc, Func Offset: 0x3c
	// Line 201, Address: 0x2ac0c8, Func Offset: 0x48
	// Line 200, Address: 0x2ac0d0, Func Offset: 0x50
	// Line 203, Address: 0x2ac0d8, Func Offset: 0x58
	// Line 200, Address: 0x2ac0e0, Func Offset: 0x60
	// Line 203, Address: 0x2ac0e8, Func Offset: 0x68
	// Func End, Address: 0x2ac0f0, Func Offset: 0x70
}

// 
// Start address: 0x2ac0f0
void FileFlagInit()
{
	// Line 219, Address: 0x2ac0f0, Func Offset: 0
	// Line 214, Address: 0x2ac0f8, Func Offset: 0x8
	// Line 215, Address: 0x2ac104, Func Offset: 0x14
	// Line 218, Address: 0x2ac10c, Func Offset: 0x1c
	// Line 219, Address: 0x2ac114, Func Offset: 0x24
	// Line 220, Address: 0x2ac120, Func Offset: 0x30
	// Line 218, Address: 0x2ac128, Func Offset: 0x38
	// Line 220, Address: 0x2ac134, Func Offset: 0x44
	// Line 221, Address: 0x2ac13c, Func Offset: 0x4c
	// Func End, Address: 0x2ac144, Func Offset: 0x54
}

// 
// Start address: 0x2ac150
void GetFile()
{
	unsigned int id;
	_anon12* st;
	_anon11* fv;
	// Line 225, Address: 0x2ac150, Func Offset: 0
	// Line 233, Address: 0x2ac15c, Func Offset: 0xc
	// Line 226, Address: 0x2ac164, Func Offset: 0x14
	// Line 227, Address: 0x2ac16c, Func Offset: 0x1c
	// Line 233, Address: 0x2ac174, Func Offset: 0x24
	// Line 238, Address: 0x2ac180, Func Offset: 0x30
	// Line 240, Address: 0x2ac1ac, Func Offset: 0x5c
	// Line 241, Address: 0x2ac1cc, Func Offset: 0x7c
	// Line 243, Address: 0x2ac1d0, Func Offset: 0x80
	// Func End, Address: 0x2ac1e0, Func Offset: 0x90
}

// 
// Start address: 0x2ac1e0
void FileViewInit()
{
	_anon11* fv;
	_anon12* st;
	// Line 247, Address: 0x2ac1e0, Func Offset: 0
	// Line 250, Address: 0x2ac1ec, Func Offset: 0xc
	// Line 248, Address: 0x2ac1f0, Func Offset: 0x10
	// Line 250, Address: 0x2ac1f8, Func Offset: 0x18
	// Line 249, Address: 0x2ac1fc, Func Offset: 0x1c
	// Line 250, Address: 0x2ac200, Func Offset: 0x20
	// Line 253, Address: 0x2ac228, Func Offset: 0x48
	// Line 254, Address: 0x2ac25c, Func Offset: 0x7c
	// Line 255, Address: 0x2ac264, Func Offset: 0x84
	// Line 256, Address: 0x2ac274, Func Offset: 0x94
	// Line 257, Address: 0x2ac284, Func Offset: 0xa4
	// Line 256, Address: 0x2ac288, Func Offset: 0xa8
	// Line 257, Address: 0x2ac294, Func Offset: 0xb4
	// Line 261, Address: 0x2ac298, Func Offset: 0xb8
	// Line 262, Address: 0x2ac2bc, Func Offset: 0xdc
	// Line 263, Address: 0x2ac2c4, Func Offset: 0xe4
	// Line 264, Address: 0x2ac2d4, Func Offset: 0xf4
	// Line 269, Address: 0x2ac2dc, Func Offset: 0xfc
	// Line 271, Address: 0x2ac2e4, Func Offset: 0x104
	// Line 274, Address: 0x2ac2f8, Func Offset: 0x118
	// Line 277, Address: 0x2ac300, Func Offset: 0x120
	// Line 278, Address: 0x2ac308, Func Offset: 0x128
	// Line 279, Address: 0x2ac318, Func Offset: 0x138
	// Line 280, Address: 0x2ac324, Func Offset: 0x144
	// Line 281, Address: 0x2ac328, Func Offset: 0x148
	// Line 283, Address: 0x2ac330, Func Offset: 0x150
	// Line 284, Address: 0x2ac334, Func Offset: 0x154
	// Line 282, Address: 0x2ac338, Func Offset: 0x158
	// Line 281, Address: 0x2ac340, Func Offset: 0x160
	// Line 282, Address: 0x2ac34c, Func Offset: 0x16c
	// Line 283, Address: 0x2ac358, Func Offset: 0x178
	// Line 284, Address: 0x2ac36c, Func Offset: 0x18c
	// Line 285, Address: 0x2ac370, Func Offset: 0x190
	// Line 286, Address: 0x2ac374, Func Offset: 0x194
	// Line 288, Address: 0x2ac378, Func Offset: 0x198
	// Line 292, Address: 0x2ac380, Func Offset: 0x1a0
	// Func End, Address: 0x2ac390, Func Offset: 0x1b0
}

// 
// Start address: 0x2ac390
void FileViewMain()
{
	_anon11* fv;
	// Line 297, Address: 0x2ac390, Func Offset: 0
	// Line 300, Address: 0x2ac398, Func Offset: 0x8
	// Line 299, Address: 0x2ac39c, Func Offset: 0xc
	// Line 300, Address: 0x2ac3a4, Func Offset: 0x14
	// Line 302, Address: 0x2ac3c4, Func Offset: 0x34
	// Line 304, Address: 0x2ac3c8, Func Offset: 0x38
	// Line 305, Address: 0x2ac3d0, Func Offset: 0x40
	// Line 306, Address: 0x2ac3d8, Func Offset: 0x48
	// Line 309, Address: 0x2ac3e0, Func Offset: 0x50
	// Func End, Address: 0x2ac3ec, Func Offset: 0x5c
}

// 
// Start address: 0x2ac3f0
void FileViewExit()
{
	// Line 313, Address: 0x2ac3f0, Func Offset: 0
	// Line 314, Address: 0x2ac3f8, Func Offset: 0x8
	// Line 315, Address: 0x2ac414, Func Offset: 0x24
	// Line 316, Address: 0x2ac41c, Func Offset: 0x2c
	// Line 317, Address: 0x2ac424, Func Offset: 0x34
	// Line 319, Address: 0x2ac42c, Func Offset: 0x3c
	// Func End, Address: 0x2ac438, Func Offset: 0x48
}

// 
// Start address: 0x2ac440
void FileExit00()
{
	// Line 326, Address: 0x2ac440, Func Offset: 0
	// Line 356, Address: 0x2ac454, Func Offset: 0x14
	// Func End, Address: 0x2ac45c, Func Offset: 0x1c
}

// 
// Start address: 0x2ac460
void FileExit01()
{
	unsigned int* itm;
	unsigned int* wp;
	int num;
	_anon11* fv;
	_anon12* st;
	// Line 360, Address: 0x2ac460, Func Offset: 0
	// Line 363, Address: 0x2ac46c, Func Offset: 0xc
	// Line 361, Address: 0x2ac474, Func Offset: 0x14
	// Line 362, Address: 0x2ac47c, Func Offset: 0x1c
	// Line 365, Address: 0x2ac480, Func Offset: 0x20
	// Line 363, Address: 0x2ac484, Func Offset: 0x24
	// Line 365, Address: 0x2ac498, Func Offset: 0x38
	// Line 366, Address: 0x2ac4a8, Func Offset: 0x48
	// Line 367, Address: 0x2ac4bc, Func Offset: 0x5c
	// Line 368, Address: 0x2ac4c8, Func Offset: 0x68
	// Line 370, Address: 0x2ac4d0, Func Offset: 0x70
	// Line 369, Address: 0x2ac4d8, Func Offset: 0x78
	// Line 371, Address: 0x2ac4dc, Func Offset: 0x7c
	// Line 368, Address: 0x2ac4e0, Func Offset: 0x80
	// Line 369, Address: 0x2ac4ec, Func Offset: 0x8c
	// Line 372, Address: 0x2ac4f4, Func Offset: 0x94
	// Line 369, Address: 0x2ac4f8, Func Offset: 0x98
	// Line 370, Address: 0x2ac504, Func Offset: 0xa4
	// Line 371, Address: 0x2ac518, Func Offset: 0xb8
	// Line 372, Address: 0x2ac51c, Func Offset: 0xbc
	// Line 373, Address: 0x2ac520, Func Offset: 0xc0
	// Line 376, Address: 0x2ac524, Func Offset: 0xc4
	// Line 377, Address: 0x2ac52c, Func Offset: 0xcc
	// Line 378, Address: 0x2ac538, Func Offset: 0xd8
	// Line 379, Address: 0x2ac540, Func Offset: 0xe0
	// Line 380, Address: 0x2ac548, Func Offset: 0xe8
	// Line 381, Address: 0x2ac54c, Func Offset: 0xec
	// Line 385, Address: 0x2ac550, Func Offset: 0xf0
	// Line 379, Address: 0x2ac554, Func Offset: 0xf4
	// Line 380, Address: 0x2ac560, Func Offset: 0x100
	// Line 389, Address: 0x2ac568, Func Offset: 0x108
	// Line 380, Address: 0x2ac56c, Func Offset: 0x10c
	// Line 381, Address: 0x2ac578, Func Offset: 0x118
	// Line 382, Address: 0x2ac57c, Func Offset: 0x11c
	// Line 385, Address: 0x2ac580, Func Offset: 0x120
	// Line 383, Address: 0x2ac588, Func Offset: 0x128
	// Line 384, Address: 0x2ac59c, Func Offset: 0x13c
	// Line 386, Address: 0x2ac5b0, Func Offset: 0x150
	// Line 387, Address: 0x2ac5b4, Func Offset: 0x154
	// Line 388, Address: 0x2ac5b8, Func Offset: 0x158
	// Line 389, Address: 0x2ac5bc, Func Offset: 0x15c
	// Line 402, Address: 0x2ac5d0, Func Offset: 0x170
	// Line 403, Address: 0x2ac5e8, Func Offset: 0x188
	// Line 404, Address: 0x2ac5fc, Func Offset: 0x19c
	// Line 416, Address: 0x2ac600, Func Offset: 0x1a0
	// Line 418, Address: 0x2ac60c, Func Offset: 0x1ac
	// Line 420, Address: 0x2ac614, Func Offset: 0x1b4
	// Line 424, Address: 0x2ac634, Func Offset: 0x1d4
	// Line 420, Address: 0x2ac638, Func Offset: 0x1d8
	// Line 426, Address: 0x2ac640, Func Offset: 0x1e0
	// Line 429, Address: 0x2ac644, Func Offset: 0x1e4
	// Line 425, Address: 0x2ac648, Func Offset: 0x1e8
	// Line 427, Address: 0x2ac654, Func Offset: 0x1f4
	// Line 428, Address: 0x2ac65c, Func Offset: 0x1fc
	// Line 429, Address: 0x2ac664, Func Offset: 0x204
	// Line 430, Address: 0x2ac668, Func Offset: 0x208
	// Line 431, Address: 0x2ac66c, Func Offset: 0x20c
	// Line 433, Address: 0x2ac670, Func Offset: 0x210
	// Line 431, Address: 0x2ac678, Func Offset: 0x218
	// Line 433, Address: 0x2ac67c, Func Offset: 0x21c
	// Line 434, Address: 0x2ac684, Func Offset: 0x224
	// Line 436, Address: 0x2ac68c, Func Offset: 0x22c
	// Line 438, Address: 0x2ac698, Func Offset: 0x238
	// Line 440, Address: 0x2ac6b4, Func Offset: 0x254
	// Line 447, Address: 0x2ac6bc, Func Offset: 0x25c
	// Line 449, Address: 0x2ac6d0, Func Offset: 0x270
	// Line 452, Address: 0x2ac6d8, Func Offset: 0x278
	// Line 453, Address: 0x2ac6e8, Func Offset: 0x288
	// Line 460, Address: 0x2ac700, Func Offset: 0x2a0
	// Func End, Address: 0x2ac710, Func Offset: 0x2b0
}

// 
// Start address: 0x2ac710
int SearchTag(int dir)
{
	int tagbak;
	_anon11* fv;
	// Line 469, Address: 0x2ac710, Func Offset: 0
	// Line 468, Address: 0x2ac718, Func Offset: 0x8
	// Line 471, Address: 0x2ac720, Func Offset: 0x10
	// Line 472, Address: 0x2ac750, Func Offset: 0x40
	// Line 473, Address: 0x2ac75c, Func Offset: 0x4c
	// Line 476, Address: 0x2ac76c, Func Offset: 0x5c
	// Func End, Address: 0x2ac774, Func Offset: 0x64
}

// 
// Start address: 0x2ac780
void SelectFile()
{
	unsigned int tagbak;
	short i;
	_anon14* si;
	_anon12* st;
	_anon11* fv;
	// Line 481, Address: 0x2ac780, Func Offset: 0
	// Line 482, Address: 0x2ac78c, Func Offset: 0xc
	// Line 481, Address: 0x2ac790, Func Offset: 0x10
	// Line 482, Address: 0x2ac794, Func Offset: 0x14
	// Line 481, Address: 0x2ac798, Func Offset: 0x18
	// Line 488, Address: 0x2ac79c, Func Offset: 0x1c
	// Line 484, Address: 0x2ac7a0, Func Offset: 0x20
	// Line 488, Address: 0x2ac7a4, Func Offset: 0x24
	// Line 484, Address: 0x2ac7a8, Func Offset: 0x28
	// Line 485, Address: 0x2ac7ac, Func Offset: 0x2c
	// Line 488, Address: 0x2ac7b4, Func Offset: 0x34
	// Line 489, Address: 0x2ac7bc, Func Offset: 0x3c
	// Line 490, Address: 0x2ac7e8, Func Offset: 0x68
	// Line 491, Address: 0x2ac7f8, Func Offset: 0x78
	// Line 492, Address: 0x2ac800, Func Offset: 0x80
	// Line 493, Address: 0x2ac808, Func Offset: 0x88
	// Line 494, Address: 0x2ac810, Func Offset: 0x90
	// Line 495, Address: 0x2ac818, Func Offset: 0x98
	// Line 498, Address: 0x2ac820, Func Offset: 0xa0
	// Line 502, Address: 0x2ac850, Func Offset: 0xd0
	// Line 503, Address: 0x2ac864, Func Offset: 0xe4
	// Line 504, Address: 0x2ac870, Func Offset: 0xf0
	// Line 506, Address: 0x2ac894, Func Offset: 0x114
	// Line 507, Address: 0x2ac8a0, Func Offset: 0x120
	// Line 508, Address: 0x2ac8a8, Func Offset: 0x128
	// Line 509, Address: 0x2ac8b0, Func Offset: 0x130
	// Line 510, Address: 0x2ac8b4, Func Offset: 0x134
	// Line 511, Address: 0x2ac8b8, Func Offset: 0x138
	// Line 510, Address: 0x2ac8bc, Func Offset: 0x13c
	// Line 511, Address: 0x2ac8c4, Func Offset: 0x144
	// Line 512, Address: 0x2ac8c8, Func Offset: 0x148
	// Line 513, Address: 0x2ac8dc, Func Offset: 0x15c
	// Line 515, Address: 0x2ac8ec, Func Offset: 0x16c
	// Line 514, Address: 0x2ac8f0, Func Offset: 0x170
	// Line 515, Address: 0x2ac8f4, Func Offset: 0x174
	// Line 514, Address: 0x2ac8f8, Func Offset: 0x178
	// Line 515, Address: 0x2ac8fc, Func Offset: 0x17c
	// Line 516, Address: 0x2ac914, Func Offset: 0x194
	// Line 517, Address: 0x2ac918, Func Offset: 0x198
	// Line 516, Address: 0x2ac91c, Func Offset: 0x19c
	// Line 517, Address: 0x2ac920, Func Offset: 0x1a0
	// Line 518, Address: 0x2ac928, Func Offset: 0x1a8
	// Line 519, Address: 0x2ac948, Func Offset: 0x1c8
	// Line 520, Address: 0x2ac954, Func Offset: 0x1d4
	// Line 521, Address: 0x2ac95c, Func Offset: 0x1dc
	// Line 523, Address: 0x2ac964, Func Offset: 0x1e4
	// Line 524, Address: 0x2ac968, Func Offset: 0x1e8
	// Line 525, Address: 0x2ac96c, Func Offset: 0x1ec
	// Line 524, Address: 0x2ac970, Func Offset: 0x1f0
	// Line 525, Address: 0x2ac978, Func Offset: 0x1f8
	// Line 526, Address: 0x2ac97c, Func Offset: 0x1fc
	// Line 527, Address: 0x2ac990, Func Offset: 0x210
	// Line 529, Address: 0x2ac9a0, Func Offset: 0x220
	// Line 528, Address: 0x2ac9a4, Func Offset: 0x224
	// Line 529, Address: 0x2ac9a8, Func Offset: 0x228
	// Line 528, Address: 0x2ac9ac, Func Offset: 0x22c
	// Line 529, Address: 0x2ac9b0, Func Offset: 0x230
	// Line 530, Address: 0x2ac9cc, Func Offset: 0x24c
	// Line 531, Address: 0x2ac9d0, Func Offset: 0x250
	// Line 530, Address: 0x2ac9d4, Func Offset: 0x254
	// Line 531, Address: 0x2ac9d8, Func Offset: 0x258
	// Line 534, Address: 0x2ac9e0, Func Offset: 0x260
	// Line 535, Address: 0x2ac9e8, Func Offset: 0x268
	// Line 537, Address: 0x2ac9f4, Func Offset: 0x274
	// Line 541, Address: 0x2aca10, Func Offset: 0x290
	// Line 542, Address: 0x2aca24, Func Offset: 0x2a4
	// Line 543, Address: 0x2aca28, Func Offset: 0x2a8
	// Line 542, Address: 0x2aca2c, Func Offset: 0x2ac
	// Line 543, Address: 0x2aca30, Func Offset: 0x2b0
	// Line 544, Address: 0x2aca38, Func Offset: 0x2b8
	// Line 546, Address: 0x2aca48, Func Offset: 0x2c8
	// Line 545, Address: 0x2aca4c, Func Offset: 0x2cc
	// Line 546, Address: 0x2aca50, Func Offset: 0x2d0
	// Line 545, Address: 0x2aca54, Func Offset: 0x2d4
	// Line 546, Address: 0x2aca58, Func Offset: 0x2d8
	// Line 547, Address: 0x2aca74, Func Offset: 0x2f4
	// Line 548, Address: 0x2aca88, Func Offset: 0x308
	// Line 549, Address: 0x2aca90, Func Offset: 0x310
	// Line 551, Address: 0x2acaa8, Func Offset: 0x328
	// Line 553, Address: 0x2acabc, Func Offset: 0x33c
	// Line 554, Address: 0x2acac4, Func Offset: 0x344
	// Line 555, Address: 0x2acacc, Func Offset: 0x34c
	// Line 556, Address: 0x2acad0, Func Offset: 0x350
	// Line 558, Address: 0x2acad4, Func Offset: 0x354
	// Line 559, Address: 0x2acae0, Func Offset: 0x360
	// Line 560, Address: 0x2acae4, Func Offset: 0x364
	// Line 561, Address: 0x2acaf0, Func Offset: 0x370
	// Line 560, Address: 0x2acaf8, Func Offset: 0x378
	// Line 561, Address: 0x2acb00, Func Offset: 0x380
	// Line 567, Address: 0x2acb08, Func Offset: 0x388
	// Line 569, Address: 0x2acb38, Func Offset: 0x3b8
	// Line 570, Address: 0x2acb50, Func Offset: 0x3d0
	// Line 571, Address: 0x2acb6c, Func Offset: 0x3ec
	// Line 572, Address: 0x2acb94, Func Offset: 0x414
	// Line 573, Address: 0x2acbc0, Func Offset: 0x440
	// Line 574, Address: 0x2acbc8, Func Offset: 0x448
	// Line 576, Address: 0x2acbd0, Func Offset: 0x450
	// Line 589, Address: 0x2acbdc, Func Offset: 0x45c
	// Line 576, Address: 0x2acbe0, Func Offset: 0x460
	// Line 579, Address: 0x2acbf8, Func Offset: 0x478
	// Line 582, Address: 0x2acc1c, Func Offset: 0x49c
	// Line 586, Address: 0x2acc44, Func Offset: 0x4c4
	// Line 587, Address: 0x2acc48, Func Offset: 0x4c8
	// Line 589, Address: 0x2acc4c, Func Offset: 0x4cc
	// Line 591, Address: 0x2acc54, Func Offset: 0x4d4
	// Line 590, Address: 0x2acc58, Func Offset: 0x4d8
	// Line 591, Address: 0x2acc5c, Func Offset: 0x4dc
	// Line 590, Address: 0x2acc60, Func Offset: 0x4e0
	// Line 591, Address: 0x2acc64, Func Offset: 0x4e4
	// Line 593, Address: 0x2acc7c, Func Offset: 0x4fc
	// Line 595, Address: 0x2acc84, Func Offset: 0x504
	// Line 596, Address: 0x2acc9c, Func Offset: 0x51c
	// Line 598, Address: 0x2accc4, Func Offset: 0x544
	// Line 599, Address: 0x2acce4, Func Offset: 0x564
	// Line 600, Address: 0x2acd0c, Func Offset: 0x58c
	// Line 602, Address: 0x2acd14, Func Offset: 0x594
	// Line 603, Address: 0x2acd30, Func Offset: 0x5b0
	// Line 604, Address: 0x2acd54, Func Offset: 0x5d4
	// Line 606, Address: 0x2acd5c, Func Offset: 0x5dc
	// Line 607, Address: 0x2acd78, Func Offset: 0x5f8
	// Line 610, Address: 0x2acda4, Func Offset: 0x624
	// Line 611, Address: 0x2acdac, Func Offset: 0x62c
	// Line 613, Address: 0x2acdb4, Func Offset: 0x634
	// Line 612, Address: 0x2acdb8, Func Offset: 0x638
	// Line 613, Address: 0x2acdbc, Func Offset: 0x63c
	// Line 615, Address: 0x2acdc8, Func Offset: 0x648
	// Line 614, Address: 0x2acdcc, Func Offset: 0x64c
	// Line 615, Address: 0x2acdd0, Func Offset: 0x650
	// Line 614, Address: 0x2acdd4, Func Offset: 0x654
	// Line 615, Address: 0x2acdd8, Func Offset: 0x658
	// Line 616, Address: 0x2acdf4, Func Offset: 0x674
	// Line 617, Address: 0x2acdfc, Func Offset: 0x67c
	// Line 619, Address: 0x2ace0c, Func Offset: 0x68c
	// Line 621, Address: 0x2ace14, Func Offset: 0x694
	// Line 622, Address: 0x2ace2c, Func Offset: 0x6ac
	// Line 623, Address: 0x2ace40, Func Offset: 0x6c0
	// Line 624, Address: 0x2ace48, Func Offset: 0x6c8
	// Line 625, Address: 0x2ace50, Func Offset: 0x6d0
	// Line 627, Address: 0x2ace54, Func Offset: 0x6d4
	// Line 629, Address: 0x2ace64, Func Offset: 0x6e4
	// Line 628, Address: 0x2ace68, Func Offset: 0x6e8
	// Line 629, Address: 0x2ace6c, Func Offset: 0x6ec
	// Line 628, Address: 0x2ace70, Func Offset: 0x6f0
	// Line 629, Address: 0x2ace74, Func Offset: 0x6f4
	// Line 632, Address: 0x2ace8c, Func Offset: 0x70c
	// Line 630, Address: 0x2ace90, Func Offset: 0x710
	// Line 632, Address: 0x2ace94, Func Offset: 0x714
	// Line 635, Address: 0x2ace98, Func Offset: 0x718
	// Line 636, Address: 0x2acec8, Func Offset: 0x748
	// Line 637, Address: 0x2aced0, Func Offset: 0x750
	// Line 638, Address: 0x2acee8, Func Offset: 0x768
	// Line 642, Address: 0x2acef4, Func Offset: 0x774
	// Line 644, Address: 0x2acef8, Func Offset: 0x778
	// Func End, Address: 0x2acf10, Func Offset: 0x790
}

// 
// Start address: 0x2acf10
void SelectTag()
{
	int title;
	int tagbak;
	short i;
	_anon26 mpos;
	_anon14* si;
	_anon11* fv;
	_anon12* st;
	// Line 648, Address: 0x2acf10, Func Offset: 0
	// Line 650, Address: 0x2acf20, Func Offset: 0x10
	// Line 657, Address: 0x2acf28, Func Offset: 0x18
	// Line 651, Address: 0x2acf2c, Func Offset: 0x1c
	// Line 657, Address: 0x2acf34, Func Offset: 0x24
	// Line 652, Address: 0x2acf38, Func Offset: 0x28
	// Line 657, Address: 0x2acf3c, Func Offset: 0x2c
	// Line 659, Address: 0x2acf58, Func Offset: 0x48
	// Line 663, Address: 0x2acf90, Func Offset: 0x80
	// Line 664, Address: 0x2acf9c, Func Offset: 0x8c
	// Line 667, Address: 0x2acfa4, Func Offset: 0x94
	// Line 669, Address: 0x2acfa8, Func Offset: 0x98
	// Line 666, Address: 0x2acfac, Func Offset: 0x9c
	// Line 667, Address: 0x2acfb8, Func Offset: 0xa8
	// Line 668, Address: 0x2acfc8, Func Offset: 0xb8
	// Line 669, Address: 0x2acfd4, Func Offset: 0xc4
	// Line 670, Address: 0x2acffc, Func Offset: 0xec
	// Line 671, Address: 0x2ad008, Func Offset: 0xf8
	// Line 674, Address: 0x2ad010, Func Offset: 0x100
	// Line 675, Address: 0x2ad01c, Func Offset: 0x10c
	// Line 680, Address: 0x2ad024, Func Offset: 0x114
	// Line 677, Address: 0x2ad028, Func Offset: 0x118
	// Line 678, Address: 0x2ad034, Func Offset: 0x124
	// Line 679, Address: 0x2ad048, Func Offset: 0x138
	// Line 680, Address: 0x2ad054, Func Offset: 0x144
	// Line 681, Address: 0x2ad07c, Func Offset: 0x16c
	// Line 686, Address: 0x2ad088, Func Offset: 0x178
	// Line 689, Address: 0x2ad0a8, Func Offset: 0x198
	// Line 694, Address: 0x2ad0b0, Func Offset: 0x1a0
	// Line 691, Address: 0x2ad0b8, Func Offset: 0x1a8
	// Line 692, Address: 0x2ad0bc, Func Offset: 0x1ac
	// Line 689, Address: 0x2ad0c0, Func Offset: 0x1b0
	// Line 690, Address: 0x2ad0cc, Func Offset: 0x1bc
	// Line 694, Address: 0x2ad0d0, Func Offset: 0x1c0
	// Line 691, Address: 0x2ad0dc, Func Offset: 0x1cc
	// Line 690, Address: 0x2ad0e0, Func Offset: 0x1d0
	// Line 694, Address: 0x2ad0e4, Func Offset: 0x1d4
	// Line 698, Address: 0x2ad0ec, Func Offset: 0x1dc
	// Line 700, Address: 0x2ad0f4, Func Offset: 0x1e4
	// Line 704, Address: 0x2ad118, Func Offset: 0x208
	// Line 705, Address: 0x2ad140, Func Offset: 0x230
	// Line 706, Address: 0x2ad14c, Func Offset: 0x23c
	// Line 707, Address: 0x2ad154, Func Offset: 0x244
	// Line 708, Address: 0x2ad15c, Func Offset: 0x24c
	// Line 711, Address: 0x2ad164, Func Offset: 0x254
	// Line 709, Address: 0x2ad168, Func Offset: 0x258
	// Line 708, Address: 0x2ad170, Func Offset: 0x260
	// Line 709, Address: 0x2ad17c, Func Offset: 0x26c
	// Line 710, Address: 0x2ad188, Func Offset: 0x278
	// Line 711, Address: 0x2ad18c, Func Offset: 0x27c
	// Line 712, Address: 0x2ad190, Func Offset: 0x280
	// Line 715, Address: 0x2ad1a4, Func Offset: 0x294
	// Line 716, Address: 0x2ad1b8, Func Offset: 0x2a8
	// Line 717, Address: 0x2ad1c4, Func Offset: 0x2b4
	// Line 719, Address: 0x2ad1d4, Func Offset: 0x2c4
	// Line 718, Address: 0x2ad1d8, Func Offset: 0x2c8
	// Line 719, Address: 0x2ad1dc, Func Offset: 0x2cc
	// Line 718, Address: 0x2ad1e0, Func Offset: 0x2d0
	// Line 719, Address: 0x2ad1e4, Func Offset: 0x2d4
	// Line 720, Address: 0x2ad1fc, Func Offset: 0x2ec
	// Line 723, Address: 0x2ad200, Func Offset: 0x2f0
	// Line 724, Address: 0x2ad208, Func Offset: 0x2f8
	// Line 725, Address: 0x2ad218, Func Offset: 0x308
	// Line 726, Address: 0x2ad230, Func Offset: 0x320
	// Line 727, Address: 0x2ad244, Func Offset: 0x334
	// Line 728, Address: 0x2ad24c, Func Offset: 0x33c
	// Line 730, Address: 0x2ad254, Func Offset: 0x344
	// Line 729, Address: 0x2ad258, Func Offset: 0x348
	// Line 730, Address: 0x2ad25c, Func Offset: 0x34c
	// Line 732, Address: 0x2ad268, Func Offset: 0x358
	// Line 731, Address: 0x2ad26c, Func Offset: 0x35c
	// Line 732, Address: 0x2ad270, Func Offset: 0x360
	// Line 731, Address: 0x2ad274, Func Offset: 0x364
	// Line 732, Address: 0x2ad278, Func Offset: 0x368
	// Line 733, Address: 0x2ad294, Func Offset: 0x384
	// Line 734, Address: 0x2ad29c, Func Offset: 0x38c
	// Line 736, Address: 0x2ad2b0, Func Offset: 0x3a0
	// Line 737, Address: 0x2ad2c4, Func Offset: 0x3b4
	// Line 738, Address: 0x2ad2dc, Func Offset: 0x3cc
	// Line 740, Address: 0x2ad300, Func Offset: 0x3f0
	// Line 741, Address: 0x2ad320, Func Offset: 0x410
	// Line 742, Address: 0x2ad348, Func Offset: 0x438
	// Line 744, Address: 0x2ad350, Func Offset: 0x440
	// Line 745, Address: 0x2ad36c, Func Offset: 0x45c
	// Line 746, Address: 0x2ad390, Func Offset: 0x480
	// Line 748, Address: 0x2ad398, Func Offset: 0x488
	// Line 749, Address: 0x2ad3b4, Func Offset: 0x4a4
	// Line 752, Address: 0x2ad3e0, Func Offset: 0x4d0
	// Line 753, Address: 0x2ad3e8, Func Offset: 0x4d8
	// Line 754, Address: 0x2ad3f0, Func Offset: 0x4e0
	// Line 755, Address: 0x2ad3f4, Func Offset: 0x4e4
	// Line 757, Address: 0x2ad400, Func Offset: 0x4f0
	// Line 756, Address: 0x2ad404, Func Offset: 0x4f4
	// Line 757, Address: 0x2ad408, Func Offset: 0x4f8
	// Line 756, Address: 0x2ad40c, Func Offset: 0x4fc
	// Line 757, Address: 0x2ad410, Func Offset: 0x500
	// Line 758, Address: 0x2ad42c, Func Offset: 0x51c
	// Line 759, Address: 0x2ad434, Func Offset: 0x524
	// Line 763, Address: 0x2ad438, Func Offset: 0x528
	// Func End, Address: 0x2ad44c, Func Offset: 0x53c
}

// 
// Start address: 0x2ad450
void FileScreenCancel()
{
	unsigned short j;
	unsigned short i;
	_anon11* fv;
	// Line 768, Address: 0x2ad450, Func Offset: 0
	// Line 770, Address: 0x2ad45c, Func Offset: 0xc
	// Line 773, Address: 0x2ad464, Func Offset: 0x14
	// Line 774, Address: 0x2ad478, Func Offset: 0x28
	// Line 780, Address: 0x2ad480, Func Offset: 0x30
	// Line 783, Address: 0x2ad490, Func Offset: 0x40
	// Line 784, Address: 0x2ad49c, Func Offset: 0x4c
	// Line 783, Address: 0x2ad4a8, Func Offset: 0x58
	// Line 784, Address: 0x2ad4b4, Func Offset: 0x64
	// Line 786, Address: 0x2ad4e8, Func Offset: 0x98
	// Line 787, Address: 0x2ad4f0, Func Offset: 0xa0
	// Line 788, Address: 0x2ad500, Func Offset: 0xb0
	// Line 789, Address: 0x2ad504, Func Offset: 0xb4
	// Line 788, Address: 0x2ad50c, Func Offset: 0xbc
	// Line 789, Address: 0x2ad518, Func Offset: 0xc8
	// Line 790, Address: 0x2ad528, Func Offset: 0xd8
	// Line 789, Address: 0x2ad52c, Func Offset: 0xdc
	// Line 790, Address: 0x2ad534, Func Offset: 0xe4
	// Line 791, Address: 0x2ad548, Func Offset: 0xf8
	// Line 799, Address: 0x2ad550, Func Offset: 0x100
	// Line 800, Address: 0x2ad554, Func Offset: 0x104
	// Line 797, Address: 0x2ad558, Func Offset: 0x108
	// Line 791, Address: 0x2ad560, Func Offset: 0x110
	// Line 799, Address: 0x2ad564, Func Offset: 0x114
	// Line 791, Address: 0x2ad56c, Func Offset: 0x11c
	// Line 799, Address: 0x2ad574, Func Offset: 0x124
	// Line 797, Address: 0x2ad580, Func Offset: 0x130
	// Line 792, Address: 0x2ad58c, Func Offset: 0x13c
	// Line 802, Address: 0x2ad594, Func Offset: 0x144
	// Line 792, Address: 0x2ad598, Func Offset: 0x148
	// Line 793, Address: 0x2ad5a4, Func Offset: 0x154
	// Line 794, Address: 0x2ad5b8, Func Offset: 0x168
	// Line 795, Address: 0x2ad5cc, Func Offset: 0x17c
	// Line 796, Address: 0x2ad5e0, Func Offset: 0x190
	// Line 800, Address: 0x2ad5f4, Func Offset: 0x1a4
	// Line 801, Address: 0x2ad5f8, Func Offset: 0x1a8
	// Line 802, Address: 0x2ad5fc, Func Offset: 0x1ac
	// Line 804, Address: 0x2ad614, Func Offset: 0x1c4
	// Line 805, Address: 0x2ad61c, Func Offset: 0x1cc
	// Line 807, Address: 0x2ad624, Func Offset: 0x1d4
	// Func End, Address: 0x2ad634, Func Offset: 0x1e4
}

// 
// Start address: 0x2ad640
void FileScrollSet()
{
	int page_end;
	_anon11* fv;
	_anon12* st;
	// Line 811, Address: 0x2ad640, Func Offset: 0
	// Line 815, Address: 0x2ad650, Func Offset: 0x10
	// Line 812, Address: 0x2ad654, Func Offset: 0x14
	// Line 815, Address: 0x2ad65c, Func Offset: 0x1c
	// Line 813, Address: 0x2ad660, Func Offset: 0x20
	// Line 815, Address: 0x2ad668, Func Offset: 0x28
	// Line 818, Address: 0x2ad67c, Func Offset: 0x3c
	// Line 819, Address: 0x2ad698, Func Offset: 0x58
	// Line 820, Address: 0x2ad69c, Func Offset: 0x5c
	// Line 819, Address: 0x2ad6a4, Func Offset: 0x64
	// Line 820, Address: 0x2ad6ac, Func Offset: 0x6c
	// Line 825, Address: 0x2ad6cc, Func Offset: 0x8c
	// Line 826, Address: 0x2ad6ec, Func Offset: 0xac
	// Line 827, Address: 0x2ad70c, Func Offset: 0xcc
	// Line 828, Address: 0x2ad718, Func Offset: 0xd8
	// Line 829, Address: 0x2ad738, Func Offset: 0xf8
	// Line 830, Address: 0x2ad750, Func Offset: 0x110
	// Line 832, Address: 0x2ad77c, Func Offset: 0x13c
	// Line 833, Address: 0x2ad780, Func Offset: 0x140
	// Line 832, Address: 0x2ad784, Func Offset: 0x144
	// Line 833, Address: 0x2ad788, Func Offset: 0x148
	// Line 834, Address: 0x2ad78c, Func Offset: 0x14c
	// Line 835, Address: 0x2ad798, Func Offset: 0x158
	// Line 836, Address: 0x2ad7a8, Func Offset: 0x168
	// Line 837, Address: 0x2ad7b0, Func Offset: 0x170
	// Line 839, Address: 0x2ad7b4, Func Offset: 0x174
	// Line 840, Address: 0x2ad7c0, Func Offset: 0x180
	// Line 843, Address: 0x2ad7d0, Func Offset: 0x190
	// Line 845, Address: 0x2ad7d8, Func Offset: 0x198
	// Line 843, Address: 0x2ad7dc, Func Offset: 0x19c
	// Line 844, Address: 0x2ad7e8, Func Offset: 0x1a8
	// Line 845, Address: 0x2ad7fc, Func Offset: 0x1bc
	// Line 846, Address: 0x2ad804, Func Offset: 0x1c4
	// Line 847, Address: 0x2ad80c, Func Offset: 0x1cc
	// Line 848, Address: 0x2ad814, Func Offset: 0x1d4
	// Line 850, Address: 0x2ad818, Func Offset: 0x1d8
	// Line 851, Address: 0x2ad82c, Func Offset: 0x1ec
	// Line 852, Address: 0x2ad838, Func Offset: 0x1f8
	// Line 853, Address: 0x2ad84c, Func Offset: 0x20c
	// Line 854, Address: 0x2ad854, Func Offset: 0x214
	// Line 855, Address: 0x2ad858, Func Offset: 0x218
	// Line 853, Address: 0x2ad85c, Func Offset: 0x21c
	// Line 854, Address: 0x2ad868, Func Offset: 0x228
	// Line 855, Address: 0x2ad86c, Func Offset: 0x22c
	// Line 856, Address: 0x2ad870, Func Offset: 0x230
	// Line 857, Address: 0x2ad87c, Func Offset: 0x23c
	// Line 858, Address: 0x2ad88c, Func Offset: 0x24c
	// Line 859, Address: 0x2ad894, Func Offset: 0x254
	// Line 861, Address: 0x2ad89c, Func Offset: 0x25c
	// Line 862, Address: 0x2ad8a8, Func Offset: 0x268
	// Line 864, Address: 0x2ad8b0, Func Offset: 0x270
	// Line 865, Address: 0x2ad8b8, Func Offset: 0x278
	// Line 868, Address: 0x2ad8c0, Func Offset: 0x280
	// Line 867, Address: 0x2ad8c4, Func Offset: 0x284
	// Line 868, Address: 0x2ad8c8, Func Offset: 0x288
	// Line 865, Address: 0x2ad8cc, Func Offset: 0x28c
	// Line 866, Address: 0x2ad8d8, Func Offset: 0x298
	// Line 867, Address: 0x2ad8ec, Func Offset: 0x2ac
	// Line 868, Address: 0x2ad8f4, Func Offset: 0x2b4
	// Line 869, Address: 0x2ad8fc, Func Offset: 0x2bc
	// Line 870, Address: 0x2ad904, Func Offset: 0x2c4
	// Line 874, Address: 0x2ad908, Func Offset: 0x2c8
	// Line 875, Address: 0x2ad910, Func Offset: 0x2d0
	// Line 877, Address: 0x2ad930, Func Offset: 0x2f0
	// Line 878, Address: 0x2ad954, Func Offset: 0x314
	// Line 880, Address: 0x2ad95c, Func Offset: 0x31c
	// Line 881, Address: 0x2ad96c, Func Offset: 0x32c
	// Line 882, Address: 0x2ad974, Func Offset: 0x334
	// Line 883, Address: 0x2ad980, Func Offset: 0x340
	// Line 885, Address: 0x2ad988, Func Offset: 0x348
	// Line 886, Address: 0x2ad99c, Func Offset: 0x35c
	// Line 887, Address: 0x2ad9c0, Func Offset: 0x380
	// Line 889, Address: 0x2ad9c8, Func Offset: 0x388
	// Line 890, Address: 0x2ad9d8, Func Offset: 0x398
	// Line 891, Address: 0x2ad9e0, Func Offset: 0x3a0
	// Line 892, Address: 0x2ad9e8, Func Offset: 0x3a8
	// Line 896, Address: 0x2ad9f4, Func Offset: 0x3b4
	// Line 897, Address: 0x2ad9fc, Func Offset: 0x3bc
	// Line 902, Address: 0x2ada04, Func Offset: 0x3c4
	// Func End, Address: 0x2ada18, Func Offset: 0x3d8
}

// 
// Start address: 0x2ada20
void FileGetWait()
{
	_anon11* fv;
	// Line 906, Address: 0x2ada20, Func Offset: 0
	// Line 908, Address: 0x2ada2c, Func Offset: 0xc
	// Line 909, Address: 0x2ada34, Func Offset: 0x14
	// Line 911, Address: 0x2ada58, Func Offset: 0x38
	// Line 912, Address: 0x2ada64, Func Offset: 0x44
	// Line 911, Address: 0x2ada68, Func Offset: 0x48
	// Line 912, Address: 0x2ada74, Func Offset: 0x54
	// Line 913, Address: 0x2ada7c, Func Offset: 0x5c
	// Line 914, Address: 0x2ada84, Func Offset: 0x64
	// Line 915, Address: 0x2ada98, Func Offset: 0x78
	// Line 916, Address: 0x2adaac, Func Offset: 0x8c
	// Line 917, Address: 0x2adac0, Func Offset: 0xa0
	// Line 918, Address: 0x2adad4, Func Offset: 0xb4
	// Line 920, Address: 0x2adae8, Func Offset: 0xc8
	// Line 921, Address: 0x2adb0c, Func Offset: 0xec
	// Line 924, Address: 0x2adb3c, Func Offset: 0x11c
	// Line 925, Address: 0x2adb44, Func Offset: 0x124
	// Line 924, Address: 0x2adb4c, Func Offset: 0x12c
	// Line 925, Address: 0x2adb50, Func Offset: 0x130
	// Line 926, Address: 0x2adb58, Func Offset: 0x138
	// Line 928, Address: 0x2adb6c, Func Offset: 0x14c
	// Line 933, Address: 0x2adb74, Func Offset: 0x154
	// Func End, Address: 0x2adb84, Func Offset: 0x164
}

// 
// Start address: 0x2adb90
void PageScroll()
{
	int page_end;
	_anon11* fv;
	// Line 938, Address: 0x2adb90, Func Offset: 0
	// Line 943, Address: 0x2adb9c, Func Offset: 0xc
	// Line 940, Address: 0x2adba4, Func Offset: 0x14
	// Line 943, Address: 0x2adbac, Func Offset: 0x1c
	// Line 946, Address: 0x2adbbc, Func Offset: 0x2c
	// Line 947, Address: 0x2adbd0, Func Offset: 0x40
	// Line 948, Address: 0x2adbec, Func Offset: 0x5c
	// Line 949, Address: 0x2adbf8, Func Offset: 0x68
	// Line 950, Address: 0x2adc04, Func Offset: 0x74
	// Line 951, Address: 0x2adc20, Func Offset: 0x90
	// Line 952, Address: 0x2adc3c, Func Offset: 0xac
	// Line 954, Address: 0x2adc44, Func Offset: 0xb4
	// Line 955, Address: 0x2adc4c, Func Offset: 0xbc
	// Line 956, Address: 0x2adc68, Func Offset: 0xd8
	// Line 957, Address: 0x2adc84, Func Offset: 0xf4
	// Line 959, Address: 0x2adc90, Func Offset: 0x100
	// Line 960, Address: 0x2adcc4, Func Offset: 0x134
	// Line 961, Address: 0x2adcd0, Func Offset: 0x140
	// Line 962, Address: 0x2adcdc, Func Offset: 0x14c
	// Line 964, Address: 0x2add08, Func Offset: 0x178
	// Line 967, Address: 0x2add10, Func Offset: 0x180
	// Line 966, Address: 0x2add14, Func Offset: 0x184
	// Line 967, Address: 0x2add18, Func Offset: 0x188
	// Line 964, Address: 0x2add1c, Func Offset: 0x18c
	// Line 965, Address: 0x2add28, Func Offset: 0x198
	// Line 966, Address: 0x2add3c, Func Offset: 0x1ac
	// Line 967, Address: 0x2add44, Func Offset: 0x1b4
	// Line 968, Address: 0x2add4c, Func Offset: 0x1bc
	// Line 969, Address: 0x2add54, Func Offset: 0x1c4
	// Line 971, Address: 0x2add5c, Func Offset: 0x1cc
	// Line 972, Address: 0x2add64, Func Offset: 0x1d4
	// Line 973, Address: 0x2add68, Func Offset: 0x1d8
	// Line 974, Address: 0x2add6c, Func Offset: 0x1dc
	// Line 971, Address: 0x2add70, Func Offset: 0x1e0
	// Line 972, Address: 0x2add7c, Func Offset: 0x1ec
	// Line 973, Address: 0x2add80, Func Offset: 0x1f0
	// Line 974, Address: 0x2add84, Func Offset: 0x1f4
	// Line 975, Address: 0x2add88, Func Offset: 0x1f8
	// Line 982, Address: 0x2add98, Func Offset: 0x208
	// Line 983, Address: 0x2addd0, Func Offset: 0x240
	// Line 984, Address: 0x2adde8, Func Offset: 0x258
	// Line 985, Address: 0x2addf4, Func Offset: 0x264
	// Line 986, Address: 0x2addf8, Func Offset: 0x268
	// Line 985, Address: 0x2addfc, Func Offset: 0x26c
	// Line 984, Address: 0x2ade04, Func Offset: 0x274
	// Line 985, Address: 0x2ade10, Func Offset: 0x280
	// Line 986, Address: 0x2ade1c, Func Offset: 0x28c
	// Line 988, Address: 0x2ade20, Func Offset: 0x290
	// Line 989, Address: 0x2ade2c, Func Offset: 0x29c
	// Line 991, Address: 0x2ade38, Func Offset: 0x2a8
	// Line 990, Address: 0x2ade3c, Func Offset: 0x2ac
	// Line 993, Address: 0x2ade40, Func Offset: 0x2b0
	// Line 994, Address: 0x2ade60, Func Offset: 0x2d0
	// Line 995, Address: 0x2ade6c, Func Offset: 0x2dc
	// Line 996, Address: 0x2ade78, Func Offset: 0x2e8
	// Line 997, Address: 0x2ade94, Func Offset: 0x304
	// Line 998, Address: 0x2adeb0, Func Offset: 0x320
	// Line 1000, Address: 0x2adeb8, Func Offset: 0x328
	// Line 1001, Address: 0x2adec0, Func Offset: 0x330
	// Line 1002, Address: 0x2adedc, Func Offset: 0x34c
	// Line 1003, Address: 0x2adef8, Func Offset: 0x368
	// Line 1005, Address: 0x2adf04, Func Offset: 0x374
	// Line 1006, Address: 0x2adf38, Func Offset: 0x3a8
	// Line 1007, Address: 0x2adf44, Func Offset: 0x3b4
	// Line 1008, Address: 0x2adf50, Func Offset: 0x3c0
	// Line 1009, Address: 0x2adf58, Func Offset: 0x3c8
	// Line 1010, Address: 0x2adf5c, Func Offset: 0x3cc
	// Line 1011, Address: 0x2adf60, Func Offset: 0x3d0
	// Line 1008, Address: 0x2adf64, Func Offset: 0x3d4
	// Line 1009, Address: 0x2adf70, Func Offset: 0x3e0
	// Line 1010, Address: 0x2adf74, Func Offset: 0x3e4
	// Line 1011, Address: 0x2adf78, Func Offset: 0x3e8
	// Line 1012, Address: 0x2adf7c, Func Offset: 0x3ec
	// Line 1019, Address: 0x2adf8c, Func Offset: 0x3fc
	// Line 1020, Address: 0x2adfc4, Func Offset: 0x434
	// Line 1021, Address: 0x2adfd0, Func Offset: 0x440
	// Line 1023, Address: 0x2adfdc, Func Offset: 0x44c
	// Line 1022, Address: 0x2adfe0, Func Offset: 0x450
	// Line 1026, Address: 0x2adfe4, Func Offset: 0x454
	// Line 1027, Address: 0x2adfec, Func Offset: 0x45c
	// Line 1028, Address: 0x2ae000, Func Offset: 0x470
	// Line 1029, Address: 0x2ae00c, Func Offset: 0x47c
	// Line 1044, Address: 0x2ae018, Func Offset: 0x488
	// Line 1029, Address: 0x2ae01c, Func Offset: 0x48c
	// Line 1045, Address: 0x2ae028, Func Offset: 0x498
	// Line 1046, Address: 0x2ae030, Func Offset: 0x4a0
	// Line 1061, Address: 0x2ae038, Func Offset: 0x4a8
	// Line 1064, Address: 0x2ae064, Func Offset: 0x4d4
	// Func End, Address: 0x2ae074, Func Offset: 0x4e4
}

// 
// Start address: 0x2ae080
void FileEtcDisplay()
{
	int page_end;
	_anon11* fv;
	unsigned short flg;
	unsigned short count;
	// Line 1069, Address: 0x2ae080, Func Offset: 0
	// Line 1076, Address: 0x2ae08c, Func Offset: 0xc
	// Line 1071, Address: 0x2ae094, Func Offset: 0x14
	// Line 1076, Address: 0x2ae09c, Func Offset: 0x1c
	// Line 1077, Address: 0x2ae0bc, Func Offset: 0x3c
	// Line 1079, Address: 0x2ae0d0, Func Offset: 0x50
	// Line 1080, Address: 0x2ae0e8, Func Offset: 0x68
	// Line 1081, Address: 0x2ae100, Func Offset: 0x80
	// Line 1083, Address: 0x2ae128, Func Offset: 0xa8
	// Line 1084, Address: 0x2ae154, Func Offset: 0xd4
	// Line 1085, Address: 0x2ae168, Func Offset: 0xe8
	// Line 1086, Address: 0x2ae178, Func Offset: 0xf8
	// Line 1087, Address: 0x2ae180, Func Offset: 0x100
	// Line 1088, Address: 0x2ae194, Func Offset: 0x114
	// Line 1090, Address: 0x2ae1a4, Func Offset: 0x124
	// Line 1091, Address: 0x2ae1ac, Func Offset: 0x12c
	// Line 1092, Address: 0x2ae1cc, Func Offset: 0x14c
	// Line 1093, Address: 0x2ae1d4, Func Offset: 0x154
	// Line 1092, Address: 0x2ae1dc, Func Offset: 0x15c
	// Line 1093, Address: 0x2ae1e8, Func Offset: 0x168
	// Line 1095, Address: 0x2ae20c, Func Offset: 0x18c
	// Line 1096, Address: 0x2ae228, Func Offset: 0x1a8
	// Line 1097, Address: 0x2ae230, Func Offset: 0x1b0
	// Line 1099, Address: 0x2ae240, Func Offset: 0x1c0
	// Line 1100, Address: 0x2ae248, Func Offset: 0x1c8
	// Line 1101, Address: 0x2ae25c, Func Offset: 0x1dc
	// Line 1105, Address: 0x2ae270, Func Offset: 0x1f0
	// Line 1106, Address: 0x2ae284, Func Offset: 0x204
	// Line 1107, Address: 0x2ae298, Func Offset: 0x218
	// Line 1108, Address: 0x2ae2a0, Func Offset: 0x220
	// Line 1110, Address: 0x2ae2b8, Func Offset: 0x238
	// Line 1111, Address: 0x2ae2cc, Func Offset: 0x24c
	// Line 1112, Address: 0x2ae2dc, Func Offset: 0x25c
	// Line 1113, Address: 0x2ae2fc, Func Offset: 0x27c
	// Line 1114, Address: 0x2ae30c, Func Offset: 0x28c
	// Line 1115, Address: 0x2ae314, Func Offset: 0x294
	// Line 1116, Address: 0x2ae334, Func Offset: 0x2b4
	// Line 1120, Address: 0x2ae348, Func Offset: 0x2c8
	// Func End, Address: 0x2ae358, Func Offset: 0x2d8
}

// 
// Start address: 0x2ae360
void StatusToFileView()
{
	unsigned short num1;
	_anon11* fv;
	// Line 1130, Address: 0x2ae360, Func Offset: 0
	// Line 1127, Address: 0x2ae368, Func Offset: 0x8
	// Line 1130, Address: 0x2ae370, Func Offset: 0x10
	// Line 1132, Address: 0x2ae378, Func Offset: 0x18
	// Line 1130, Address: 0x2ae384, Func Offset: 0x24
	// Line 1133, Address: 0x2ae390, Func Offset: 0x30
	// Line 1134, Address: 0x2ae39c, Func Offset: 0x3c
	// Line 1135, Address: 0x2ae3a8, Func Offset: 0x48
	// Line 1136, Address: 0x2ae3b4, Func Offset: 0x54
	// Line 1137, Address: 0x2ae3c0, Func Offset: 0x60
	// Line 1138, Address: 0x2ae3cc, Func Offset: 0x6c
	// Line 1139, Address: 0x2ae3d8, Func Offset: 0x78
	// Line 1140, Address: 0x2ae3e0, Func Offset: 0x80
	// Line 1141, Address: 0x2ae3ec, Func Offset: 0x8c
	// Line 1143, Address: 0x2ae400, Func Offset: 0xa0
	// Line 1144, Address: 0x2ae414, Func Offset: 0xb4
	// Line 1145, Address: 0x2ae41c, Func Offset: 0xbc
	// Line 1146, Address: 0x2ae42c, Func Offset: 0xcc
	// Line 1147, Address: 0x2ae438, Func Offset: 0xd8
	// Line 1148, Address: 0x2ae440, Func Offset: 0xe0
	// Line 1149, Address: 0x2ae44c, Func Offset: 0xec
	// Line 1150, Address: 0x2ae450, Func Offset: 0xf0
	// Line 1148, Address: 0x2ae454, Func Offset: 0xf4
	// Line 1150, Address: 0x2ae458, Func Offset: 0xf8
	// Line 1152, Address: 0x2ae470, Func Offset: 0x110
	// Line 1154, Address: 0x2ae478, Func Offset: 0x118
	// Line 1152, Address: 0x2ae47c, Func Offset: 0x11c
	// Line 1153, Address: 0x2ae488, Func Offset: 0x128
	// Line 1156, Address: 0x2ae49c, Func Offset: 0x13c
	// Func End, Address: 0x2ae4a4, Func Offset: 0x144
}

// 
// Start address: 0x2ae4b0
void ReadFstx()
{
	unsigned int num;
	int sz;
	_anon11* fv;
	_anon12* st;
	// Line 1160, Address: 0x2ae4b0, Func Offset: 0
	// Line 1167, Address: 0x2ae4c0, Func Offset: 0x10
	// Line 1161, Address: 0x2ae4c8, Func Offset: 0x18
	// Line 1162, Address: 0x2ae4d0, Func Offset: 0x20
	// Line 1167, Address: 0x2ae4d8, Func Offset: 0x28
	// Line 1169, Address: 0x2ae4e0, Func Offset: 0x30
	// Line 1167, Address: 0x2ae4e4, Func Offset: 0x34
	// Line 1169, Address: 0x2ae4e8, Func Offset: 0x38
	// Line 1170, Address: 0x2ae508, Func Offset: 0x58
	// Line 1172, Address: 0x2ae51c, Func Offset: 0x6c
	// Line 1176, Address: 0x2ae548, Func Offset: 0x98
	// Line 1178, Address: 0x2ae554, Func Offset: 0xa4
	// Line 1176, Address: 0x2ae558, Func Offset: 0xa8
	// Line 1178, Address: 0x2ae564, Func Offset: 0xb4
	// Line 1179, Address: 0x2ae56c, Func Offset: 0xbc
	// Line 1181, Address: 0x2ae570, Func Offset: 0xc0
	// Line 1182, Address: 0x2ae584, Func Offset: 0xd4
	// Line 1183, Address: 0x2ae594, Func Offset: 0xe4
	// Line 1186, Address: 0x2ae5a8, Func Offset: 0xf8
	// Line 1188, Address: 0x2ae5b8, Func Offset: 0x108
	// Line 1190, Address: 0x2ae5bc, Func Offset: 0x10c
	// Line 1193, Address: 0x2ae5c4, Func Offset: 0x114
	// Line 1195, Address: 0x2ae5d4, Func Offset: 0x124
	// Line 1197, Address: 0x2ae5e0, Func Offset: 0x130
	// Line 1195, Address: 0x2ae5e4, Func Offset: 0x134
	// Line 1197, Address: 0x2ae5f0, Func Offset: 0x140
	// Line 1198, Address: 0x2ae5f4, Func Offset: 0x144
	// Line 1199, Address: 0x2ae608, Func Offset: 0x158
	// Line 1200, Address: 0x2ae618, Func Offset: 0x168
	// Line 1203, Address: 0x2ae620, Func Offset: 0x170
	// Line 1221, Address: 0x2ae634, Func Offset: 0x184
	// Line 1223, Address: 0x2ae638, Func Offset: 0x188
	// Line 1252, Address: 0x2ae640, Func Offset: 0x190
	// Line 1254, Address: 0x2ae650, Func Offset: 0x1a0
	// Line 1255, Address: 0x2ae658, Func Offset: 0x1a8
	// Line 1256, Address: 0x2ae66c, Func Offset: 0x1bc
	// Line 1257, Address: 0x2ae674, Func Offset: 0x1c4
	// Line 1258, Address: 0x2ae67c, Func Offset: 0x1cc
	// Line 1259, Address: 0x2ae688, Func Offset: 0x1d8
	// Line 1260, Address: 0x2ae690, Func Offset: 0x1e0
	// Line 1259, Address: 0x2ae694, Func Offset: 0x1e4
	// Line 1260, Address: 0x2ae698, Func Offset: 0x1e8
	// Line 1265, Address: 0x2ae6a0, Func Offset: 0x1f0
	// Line 1294, Address: 0x2ae6a8, Func Offset: 0x1f8
	// Line 1307, Address: 0x2ae6b0, Func Offset: 0x200
	// Line 1310, Address: 0x2ae6b8, Func Offset: 0x208
	// Line 1311, Address: 0x2ae6cc, Func Offset: 0x21c
	// Line 1312, Address: 0x2ae6e0, Func Offset: 0x230
	// Line 1313, Address: 0x2ae6f0, Func Offset: 0x240
	// Line 1315, Address: 0x2ae704, Func Offset: 0x254
	// Line 1316, Address: 0x2ae71c, Func Offset: 0x26c
	// Line 1317, Address: 0x2ae720, Func Offset: 0x270
	// Line 1319, Address: 0x2ae728, Func Offset: 0x278
	// Line 1321, Address: 0x2ae738, Func Offset: 0x288
	// Line 1320, Address: 0x2ae73c, Func Offset: 0x28c
	// Line 1321, Address: 0x2ae740, Func Offset: 0x290
	// Line 1322, Address: 0x2ae744, Func Offset: 0x294
	// Line 1326, Address: 0x2ae754, Func Offset: 0x2a4
	// Line 1327, Address: 0x2ae760, Func Offset: 0x2b0
	// Line 1329, Address: 0x2ae768, Func Offset: 0x2b8
	// Line 1331, Address: 0x2ae770, Func Offset: 0x2c0
	// Line 1334, Address: 0x2ae774, Func Offset: 0x2c4
	// Line 1327, Address: 0x2ae778, Func Offset: 0x2c8
	// Line 1328, Address: 0x2ae784, Func Offset: 0x2d4
	// Line 1329, Address: 0x2ae798, Func Offset: 0x2e8
	// Line 1330, Address: 0x2ae7ac, Func Offset: 0x2fc
	// Line 1331, Address: 0x2ae7b0, Func Offset: 0x300
	// Line 1332, Address: 0x2ae7b8, Func Offset: 0x308
	// Line 1331, Address: 0x2ae7c0, Func Offset: 0x310
	// Line 1332, Address: 0x2ae7cc, Func Offset: 0x31c
	// Line 1334, Address: 0x2ae7dc, Func Offset: 0x32c
	// Line 1335, Address: 0x2ae7e8, Func Offset: 0x338
	// Line 1336, Address: 0x2ae7f0, Func Offset: 0x340
	// Line 1337, Address: 0x2ae7f8, Func Offset: 0x348
	// Line 1343, Address: 0x2ae800, Func Offset: 0x350
	// Func End, Address: 0x2ae814, Func Offset: 0x364
}

// 
// Start address: 0x2ae820
unsigned int FileNumberSwitch(unsigned int num)
{
	unsigned int filenum;
	// Line 1351, Address: 0x2ae820, Func Offset: 0
	// Line 1353, Address: 0x2ae970, Func Offset: 0x150
	// Line 1354, Address: 0x2ae97c, Func Offset: 0x15c
	// Line 1356, Address: 0x2ae984, Func Offset: 0x164
	// Line 1357, Address: 0x2ae990, Func Offset: 0x170
	// Line 1359, Address: 0x2ae998, Func Offset: 0x178
	// Line 1360, Address: 0x2ae9a4, Func Offset: 0x184
	// Line 1362, Address: 0x2ae9ac, Func Offset: 0x18c
	// Line 1363, Address: 0x2ae9bc, Func Offset: 0x19c
	// Line 1364, Address: 0x2ae9c8, Func Offset: 0x1a8
	// Line 1366, Address: 0x2ae9d0, Func Offset: 0x1b0
	// Line 1367, Address: 0x2ae9dc, Func Offset: 0x1bc
	// Line 1369, Address: 0x2ae9e4, Func Offset: 0x1c4
	// Line 1370, Address: 0x2ae9f0, Func Offset: 0x1d0
	// Line 1373, Address: 0x2ae9f8, Func Offset: 0x1d8
	// Line 1374, Address: 0x2aea04, Func Offset: 0x1e4
	// Line 1376, Address: 0x2aea0c, Func Offset: 0x1ec
	// Line 1377, Address: 0x2aea1c, Func Offset: 0x1fc
	// Line 1378, Address: 0x2aea28, Func Offset: 0x208
	// Line 1381, Address: 0x2aea30, Func Offset: 0x210
	// Line 1382, Address: 0x2aea3c, Func Offset: 0x21c
	// Line 1384, Address: 0x2aea44, Func Offset: 0x224
	// Line 1385, Address: 0x2aea50, Func Offset: 0x230
	// Line 1387, Address: 0x2aea58, Func Offset: 0x238
	// Line 1388, Address: 0x2aea64, Func Offset: 0x244
	// Line 1390, Address: 0x2aea6c, Func Offset: 0x24c
	// Line 1391, Address: 0x2aea7c, Func Offset: 0x25c
	// Line 1392, Address: 0x2aea88, Func Offset: 0x268
	// Line 1394, Address: 0x2aea90, Func Offset: 0x270
	// Line 1395, Address: 0x2aea9c, Func Offset: 0x27c
	// Line 1397, Address: 0x2aeaa4, Func Offset: 0x284
	// Line 1398, Address: 0x2aeab0, Func Offset: 0x290
	// Line 1400, Address: 0x2aeab8, Func Offset: 0x298
	// Line 1401, Address: 0x2aeac4, Func Offset: 0x2a4
	// Line 1403, Address: 0x2aeacc, Func Offset: 0x2ac
	// Line 1404, Address: 0x2aead8, Func Offset: 0x2b8
	// Line 1407, Address: 0x2aeae0, Func Offset: 0x2c0
	// Line 1408, Address: 0x2aeaec, Func Offset: 0x2cc
	// Line 1410, Address: 0x2aeaf4, Func Offset: 0x2d4
	// Line 1411, Address: 0x2aeb00, Func Offset: 0x2e0
	// Line 1413, Address: 0x2aeb08, Func Offset: 0x2e8
	// Line 1414, Address: 0x2aeb14, Func Offset: 0x2f4
	// Line 1416, Address: 0x2aeb1c, Func Offset: 0x2fc
	// Line 1417, Address: 0x2aeb28, Func Offset: 0x308
	// Line 1419, Address: 0x2aeb30, Func Offset: 0x310
	// Line 1420, Address: 0x2aeb34, Func Offset: 0x314
	// Line 1419, Address: 0x2aeb38, Func Offset: 0x318
	// Line 1426, Address: 0x2aeb40, Func Offset: 0x320
	// Line 1428, Address: 0x2aeb50, Func Offset: 0x330
	// Func End, Address: 0x2aeb58, Func Offset: 0x338
}

// 
// Start address: 0x2aeb60
int PlayPageCheck()
{
	int page_end00;
	// Line 1442, Address: 0x2aeb60, Func Offset: 0
	// Line 1460, Address: 0x2aeb68, Func Offset: 0x8
	// Line 1462, Address: 0x2aeb84, Func Offset: 0x24
	// Line 1464, Address: 0x2aeba8, Func Offset: 0x48
	// Line 1466, Address: 0x2aebcc, Func Offset: 0x6c
	// Line 1468, Address: 0x2aebf0, Func Offset: 0x90
	// Line 1470, Address: 0x2aec14, Func Offset: 0xb4
	// Line 1471, Address: 0x2aec1c, Func Offset: 0xbc
	// Line 1475, Address: 0x2aec20, Func Offset: 0xc0
	// Func End, Address: 0x2aec2c, Func Offset: 0xcc
}

