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

typedef void(*type_8)(BH_PWORK*);
typedef void(*type_44)(BH_PWORK*);
typedef void(*type_69)(BH_PWORK*);
typedef void(*type_73)(BH_PWORK*);
typedef void(*type_78)(void*);
typedef void(*type_90)(BH_PWORK*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef _anon0* type_2[32];
typedef _anon1* type_3[16];
typedef _anon0* type_4[32];
typedef _anon0* type_5[512];
typedef _anon1* type_6[16][16];
typedef _anon1* type_7[16][16][100];
typedef char type_9[8];
typedef void(*type_10)(BH_PWORK*)[8];
typedef _anon0* type_11[32];
typedef char type_12[3];
typedef _anon0* type_13[512];
typedef _anon1* type_14[1300];
typedef char type_15[32];
typedef _anon0* type_16[512];
typedef _anon1* type_17[200];
typedef short type_18[32];
typedef _anon14 type_19[1];
typedef _anon0* type_20[128];
typedef unsigned int type_21[1];
typedef _anon5 type_22[256];
typedef _anon1* type_23[8];
typedef int* type_24[16];
typedef _anon0* type_25[128];
typedef npobj* type_26[16];
typedef _anon0* type_27[128];
typedef int type_28[4];
typedef _anon1* type_29[16];
typedef unsigned int type_30[4];
typedef _anon8 type_31[16];
typedef _anon0* type_32[512];
typedef char type_33[256];
typedef float type_34[4];
typedef float type_35[4];
typedef float type_36[4];
typedef _anon4* type_37[128];
typedef unsigned char type_38[64];
typedef float type_39[16];
typedef char type_40[8];
typedef BH_PWORK type_41[0];
typedef void* type_42[2];
typedef _anon0 type_43[0];
typedef void(*type_45)(BH_PWORK*)[2];
typedef _anon1* type_46[256];
typedef int type_47[4];
typedef unsigned char* type_48[256];
typedef unsigned int type_49[2];
typedef short type_50[256];
typedef _anon20 type_51[4];
typedef float type_52[3];
typedef _anon15 type_53[3];
typedef short type_54[256];
typedef int type_55[3];
typedef int type_56[8];
typedef float type_57[3];
typedef _anon1* type_58[256];
typedef _anon7 type_59[256];
typedef _anon14 type_60[450];
typedef _anon22 type_61[16];
typedef short type_62[256];
typedef char type_63[3];
typedef int type_64[64];
typedef _anon8 type_65[450];
typedef _anon25 type_66[4];
typedef _anon2 type_67[4];
typedef int type_68[450];
typedef void(*type_70)(BH_PWORK*)[1];
typedef unsigned int type_71[8];
typedef unsigned char type_72[450];
typedef void(*type_74)(BH_PWORK*)[2];
typedef int type_75[16];
typedef char type_76[16];
typedef char type_77[4];
typedef unsigned int type_79[32];
typedef unsigned int type_80[16];
typedef _anon27 type_81[64];
typedef unsigned int type_82[16];
typedef _anon27 type_83[64];
typedef unsigned int type_84[32];
typedef _anon27 type_85[64];
typedef unsigned int type_86[16];
typedef unsigned int type_87[3];
typedef BH_PWORK* type_88[16];
typedef unsigned int type_89[8];
typedef void(*type_91)(BH_PWORK*)[6];
typedef unsigned int type_92[1];
typedef unsigned int type_93[384];
typedef unsigned int type_94[2];
typedef unsigned char type_95[2];
typedef unsigned int type_96[4];
typedef int* type_97[16];
typedef char type_98[32];
typedef npobj* type_99[16];
typedef char type_100[64];
typedef _anon1* type_101[16];
typedef char type_102[4];
typedef _anon8 type_103[16];
typedef short type_104[4];
typedef int type_105[3];
typedef unsigned char type_106[4];
typedef _anon23 type_107[16];
typedef unsigned int type_108[32];
typedef _anon3 type_109[32];
typedef _anon0* type_110[512];
typedef _anon0* type_111[128];
typedef int type_112[3];
typedef _anon0* type_113[512];
typedef unsigned char type_114[64];
typedef _anon0* type_115[512];

struct npobj
{
	unsigned int evalflags;
	_anon21* model;
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
	_anon31 cspr;
	int pn;
	_anon25* pvp;
	_anon2* tvp;
	_anon25 pv[4];
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
	_anon32 watr;
	_anon15* cpcl;
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
	_anon14* textures;
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
	float x;
	float y;
	float z;
};

struct _anon4
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon13* md2P;
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
	_anon1* texP;
	_anon18* owP;
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
	_anon29* info;
};

struct _anon10
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
	_anon3 ply_pos;
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
	_anon4* emtp[128];
	_anon4* rmthp;
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
	_anon14 ef_tex[450];
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
	_anon12 ren_info;
	_anon14 ren_tex[1];
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
	_anon28 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon16* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon20 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon22 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon27* pl_htp;
	int costume;
	_anon3 hd_pos;
	_anon3 apos;
	_anon27* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon27 mwalp[64];
	_anon27 metcp[64];
	_anon27 mflrp[64];
	int dla_n;
	_anon27* htp;
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
	_anon3 ufo_pos;
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
	_anon23 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon3 ghtp[32];
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
	void* p[2];
};

struct _anon14
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon15
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon16
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
	_anon19* light;
};

struct _anon17
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon18
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon19
{
	float mtrx[16];
	_anon3 pnt;
	_anon3 vctr;
	int stat;
	int reserve;
	_anon24 ltcal;
	_anon30 attr;
};

struct _anon20
{
	_anon3 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon21
{
	int* vlist;
	short* plist;
	_anon3 center;
	float r;
};

struct _anon22
{
	float x;
	float y;
};

struct _anon23
{
	_anon3 c1;
	_anon3 c2;
	float r1;
	float r2;
};

struct _anon24
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
	_anon3 lpnt;
	_anon3 lvctr;
	_anon3 lmvctr;
	_anon17 atten;
	_anon17 amb;
	_anon17 dif;
	_anon17 spc;
	_anon17 mamb;
	_anon17 mdif;
	_anon17 mspc;
};

struct _anon25
{
	float x;
	float y;
	float z;
	unsigned int col;
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

struct _anon28
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon29
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

struct _anon30
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
	_anon17 argb;
};

struct _anon31
{
	_anon3 c;
	float r;
};

struct _anon32
{
	_anon3 c1;
	_anon3 c2;
	float r;
};

int ENE30_HITPOINT[16];
char SdwTab[3];
_anon15 CapColTab[3];
void(*bhEne30_Mode0)(BH_PWORK*)[6];
void(*bhEne30_BrainType)(BH_PWORK*)[1];
void(*bhEne30_MoveMode2)(BH_PWORK*)[8];
void(*bhEne30_DamageMode2)(BH_PWORK*)[2];
void(*bhEne30_DeadMode2)(BH_PWORK*)[2];
BH_PWORK* plp;
_anon10* sys;
BH_PWORK ene[0];
_anon0 eff[0];

void bhEne30(BH_PWORK* epw);
void bhEne30_Init(BH_PWORK* epw);
void bhEne30_Brain(BH_PWORK* epw);
void bhEne30_BR00(BH_PWORK* epw);
void bhEne30_Move(BH_PWORK* epw);
void bhEne30_MV00();
void bhEne30_MV01(BH_PWORK* epw);
void bhEne30_MV02(BH_PWORK* epw);
void bhEne30_MV03(BH_PWORK* epw);
void bhEne30_MV04(BH_PWORK* epw);
void bhEne30_MV05(BH_PWORK* epw);
void bhEne30_MV06(BH_PWORK* epw);
void bhEne30_MV07(BH_PWORK* epw);
void bhEne30_Nage();
void bhEne30_Damage(BH_PWORK* epw);
void bhEne30_DG00(BH_PWORK* epw);
void bhEne30_DG01(BH_PWORK* epw);
void bhEne30_Die(BH_PWORK* epw);
void bhEne30_DD00(BH_PWORK* epw);
void bhEne30_DD01(BH_PWORK* epw);
void bhEne30_CheckEnemies(BH_PWORK* epw);
void bhEne30_DamageInit(BH_PWORK* epw);
void bhEne30_CollisionLine(BH_PWORK* epw);
void bhEne30_SetFluidEffect(_anon3* pos, _anon3* vec, int type, float size);

// 
// Start address: 0x213630
void bhEne30(BH_PWORK* epw)
{
	float wy;
	// Line 205, Address: 0x213630, Func Offset: 0
	// Line 207, Address: 0x213644, Func Offset: 0x14
	// Line 210, Address: 0x213664, Func Offset: 0x34
	// Line 211, Address: 0x21367c, Func Offset: 0x4c
	// Line 214, Address: 0x213688, Func Offset: 0x58
	// Line 216, Address: 0x21369c, Func Offset: 0x6c
	// Line 217, Address: 0x2136b0, Func Offset: 0x80
	// Line 218, Address: 0x2136b8, Func Offset: 0x88
	// Line 222, Address: 0x2136c0, Func Offset: 0x90
	// Line 223, Address: 0x2136d4, Func Offset: 0xa4
	// Line 227, Address: 0x2136dc, Func Offset: 0xac
	// Line 230, Address: 0x2136ec, Func Offset: 0xbc
	// Line 232, Address: 0x2136f4, Func Offset: 0xc4
	// Line 233, Address: 0x2136f8, Func Offset: 0xc8
	// Line 234, Address: 0x2136fc, Func Offset: 0xcc
	// Line 233, Address: 0x213700, Func Offset: 0xd0
	// Line 234, Address: 0x213704, Func Offset: 0xd4
	// Line 235, Address: 0x21370c, Func Offset: 0xdc
	// Line 236, Address: 0x213714, Func Offset: 0xe4
	// Line 235, Address: 0x213718, Func Offset: 0xe8
	// Line 236, Address: 0x213720, Func Offset: 0xf0
	// Line 249, Address: 0x213734, Func Offset: 0x104
	// Line 252, Address: 0x213740, Func Offset: 0x110
	// Line 253, Address: 0x213758, Func Offset: 0x128
	// Func End, Address: 0x21376c, Func Offset: 0x13c
}

// 
// Start address: 0x213770
void bhEne30_Init(BH_PWORK* epw)
{
	npobj* pObj;
	int i;
	npobj* obj;
	int i;
	npobj* obj;
	// Line 263, Address: 0x213770, Func Offset: 0
	// Line 265, Address: 0x21377c, Func Offset: 0xc
	// Line 267, Address: 0x213784, Func Offset: 0x14
	// Line 266, Address: 0x21378c, Func Offset: 0x1c
	// Line 265, Address: 0x213790, Func Offset: 0x20
	// Line 266, Address: 0x213798, Func Offset: 0x28
	// Line 268, Address: 0x21379c, Func Offset: 0x2c
	// Line 271, Address: 0x2137a0, Func Offset: 0x30
	// Line 272, Address: 0x2137a4, Func Offset: 0x34
	// Line 266, Address: 0x2137ac, Func Offset: 0x3c
	// Line 267, Address: 0x2137b4, Func Offset: 0x44
	// Line 273, Address: 0x2137b8, Func Offset: 0x48
	// Line 277, Address: 0x2137bc, Func Offset: 0x4c
	// Line 279, Address: 0x2137c0, Func Offset: 0x50
	// Line 267, Address: 0x2137c4, Func Offset: 0x54
	// Line 268, Address: 0x2137cc, Func Offset: 0x5c
	// Line 269, Address: 0x2137d8, Func Offset: 0x68
	// Line 270, Address: 0x2137e4, Func Offset: 0x74
	// Line 271, Address: 0x2137f0, Func Offset: 0x80
	// Line 272, Address: 0x2137f4, Func Offset: 0x84
	// Line 273, Address: 0x2137f8, Func Offset: 0x88
	// Line 274, Address: 0x2137fc, Func Offset: 0x8c
	// Line 277, Address: 0x213800, Func Offset: 0x90
	// Line 278, Address: 0x213804, Func Offset: 0x94
	// Line 279, Address: 0x213808, Func Offset: 0x98
	// Line 282, Address: 0x213810, Func Offset: 0xa0
	// Line 286, Address: 0x213860, Func Offset: 0xf0
	// Line 292, Address: 0x213864, Func Offset: 0xf4
	// Line 282, Address: 0x213868, Func Offset: 0xf8
	// Line 286, Address: 0x21386c, Func Offset: 0xfc
	// Line 287, Address: 0x213870, Func Offset: 0x100
	// Line 288, Address: 0x213874, Func Offset: 0x104
	// Line 289, Address: 0x213878, Func Offset: 0x108
	// Line 292, Address: 0x21387c, Func Offset: 0x10c
	// Line 293, Address: 0x213880, Func Offset: 0x110
	// Line 294, Address: 0x213884, Func Offset: 0x114
	// Line 295, Address: 0x213888, Func Offset: 0x118
	// Line 296, Address: 0x21388c, Func Offset: 0x11c
	// Line 297, Address: 0x213890, Func Offset: 0x120
	// Line 301, Address: 0x213894, Func Offset: 0x124
	// Line 300, Address: 0x213898, Func Offset: 0x128
	// Line 301, Address: 0x21389c, Func Offset: 0x12c
	// Line 302, Address: 0x2138a0, Func Offset: 0x130
	// Line 303, Address: 0x2138a8, Func Offset: 0x138
	// Line 304, Address: 0x2138b0, Func Offset: 0x140
	// Line 305, Address: 0x2138b8, Func Offset: 0x148
	// Line 306, Address: 0x2138c0, Func Offset: 0x150
	// Line 307, Address: 0x2138c8, Func Offset: 0x158
	// Line 310, Address: 0x2138d8, Func Offset: 0x168
	// Line 311, Address: 0x2138e4, Func Offset: 0x174
	// Line 317, Address: 0x2138f4, Func Offset: 0x184
	// Line 318, Address: 0x2138f8, Func Offset: 0x188
	// Line 319, Address: 0x213904, Func Offset: 0x194
	// Line 322, Address: 0x21390c, Func Offset: 0x19c
	// Line 319, Address: 0x213910, Func Offset: 0x1a0
	// Line 320, Address: 0x213918, Func Offset: 0x1a8
	// Line 321, Address: 0x213928, Func Offset: 0x1b8
	// Line 322, Address: 0x213934, Func Offset: 0x1c4
	// Line 321, Address: 0x213938, Func Offset: 0x1c8
	// Line 322, Address: 0x213940, Func Offset: 0x1d0
	// Line 331, Address: 0x213950, Func Offset: 0x1e0
	// Line 332, Address: 0x213954, Func Offset: 0x1e4
	// Line 331, Address: 0x213958, Func Offset: 0x1e8
	// Line 334, Address: 0x213960, Func Offset: 0x1f0
	// Line 333, Address: 0x213964, Func Offset: 0x1f4
	// Line 334, Address: 0x213968, Func Offset: 0x1f8
	// Line 341, Address: 0x21397c, Func Offset: 0x20c
	// Line 342, Address: 0x213980, Func Offset: 0x210
	// Line 343, Address: 0x213990, Func Offset: 0x220
	// Line 344, Address: 0x213994, Func Offset: 0x224
	// Line 347, Address: 0x2139a0, Func Offset: 0x230
	// Line 349, Address: 0x2139b0, Func Offset: 0x240
	// Line 353, Address: 0x2139c0, Func Offset: 0x250
	// Line 354, Address: 0x2139d0, Func Offset: 0x260
	// Line 355, Address: 0x2139fc, Func Offset: 0x28c
	// Line 357, Address: 0x213a08, Func Offset: 0x298
	// Line 360, Address: 0x213a10, Func Offset: 0x2a0
	// Line 357, Address: 0x213a18, Func Offset: 0x2a8
	// Line 363, Address: 0x213a20, Func Offset: 0x2b0
	// Line 368, Address: 0x213a64, Func Offset: 0x2f4
	// Line 363, Address: 0x213a68, Func Offset: 0x2f8
	// Line 366, Address: 0x213a6c, Func Offset: 0x2fc
	// Line 367, Address: 0x213a74, Func Offset: 0x304
	// Line 368, Address: 0x213a7c, Func Offset: 0x30c
	// Line 369, Address: 0x213a88, Func Offset: 0x318
	// Line 371, Address: 0x213a8c, Func Offset: 0x31c
	// Func End, Address: 0x213a9c, Func Offset: 0x32c
}

// 
// Start address: 0x213aa0
void bhEne30_Brain(BH_PWORK* epw)
{
	// Line 382, Address: 0x213aa0, Func Offset: 0
	// Func End, Address: 0x213ac0, Func Offset: 0x20
}

// 
// Start address: 0x213ac0
void bhEne30_BR00(BH_PWORK* epw)
{
	// Line 393, Address: 0x213ac0, Func Offset: 0
	// Line 458, Address: 0x213acc, Func Offset: 0xc
	// Line 461, Address: 0x213b04, Func Offset: 0x44
	// Line 462, Address: 0x213b24, Func Offset: 0x64
	// Line 463, Address: 0x213b34, Func Offset: 0x74
	// Line 467, Address: 0x213bbc, Func Offset: 0xfc
	// Line 466, Address: 0x213bc0, Func Offset: 0x100
	// Line 467, Address: 0x213bc4, Func Offset: 0x104
	// Line 471, Address: 0x213bc8, Func Offset: 0x108
	// Line 473, Address: 0x213c0c, Func Offset: 0x14c
	// Line 477, Address: 0x213c14, Func Offset: 0x154
	// Line 479, Address: 0x213c34, Func Offset: 0x174
	// Line 478, Address: 0x213c38, Func Offset: 0x178
	// Line 479, Address: 0x213c3c, Func Offset: 0x17c
	// Line 483, Address: 0x213c40, Func Offset: 0x180
	// Line 488, Address: 0x213c88, Func Offset: 0x1c8
	// Func End, Address: 0x213c98, Func Offset: 0x1d8
}

// 
// Start address: 0x213ca0
void bhEne30_Move(BH_PWORK* epw)
{
	// Line 498, Address: 0x213ca0, Func Offset: 0
	// Line 500, Address: 0x213cac, Func Offset: 0xc
	// Line 503, Address: 0x213cc0, Func Offset: 0x20
	// Line 506, Address: 0x213ce0, Func Offset: 0x40
	// Line 507, Address: 0x213cf0, Func Offset: 0x50
	// Line 508, Address: 0x213cfc, Func Offset: 0x5c
	// Line 510, Address: 0x213d04, Func Offset: 0x64
	// Func End, Address: 0x213d14, Func Offset: 0x74
}

// 
// Start address: 0x213d20
void bhEne30_MV00()
{
	// Line 521, Address: 0x213d20, Func Offset: 0
	// Func End, Address: 0x213d28, Func Offset: 0x8
}

// 
// Start address: 0x213d30
void bhEne30_MV01(BH_PWORK* epw)
{
	int ang;
	float wdist;
	float dist;
	BH_PWORK* ep;
	int i;
	_anon3 vec;
	_anon27* hp;
	_anon3 pos;
	// Line 531, Address: 0x213d30, Func Offset: 0
	// Line 540, Address: 0x213d50, Func Offset: 0x20
	// Line 542, Address: 0x213d70, Func Offset: 0x40
	// Line 543, Address: 0x213d7c, Func Offset: 0x4c
	// Line 544, Address: 0x213d80, Func Offset: 0x50
	// Line 542, Address: 0x213d84, Func Offset: 0x54
	// Line 543, Address: 0x213d8c, Func Offset: 0x5c
	// Line 547, Address: 0x213d90, Func Offset: 0x60
	// Line 548, Address: 0x213d94, Func Offset: 0x64
	// Line 550, Address: 0x213d98, Func Offset: 0x68
	// Line 543, Address: 0x213d9c, Func Offset: 0x6c
	// Line 544, Address: 0x213da4, Func Offset: 0x74
	// Line 545, Address: 0x213db0, Func Offset: 0x80
	// Line 546, Address: 0x213db4, Func Offset: 0x84
	// Line 547, Address: 0x213db8, Func Offset: 0x88
	// Line 548, Address: 0x213dbc, Func Offset: 0x8c
	// Line 549, Address: 0x213dc0, Func Offset: 0x90
	// Line 550, Address: 0x213dc4, Func Offset: 0x94
	// Line 551, Address: 0x213dc8, Func Offset: 0x98
	// Line 552, Address: 0x213dcc, Func Offset: 0x9c
	// Line 553, Address: 0x213dd4, Func Offset: 0xa4
	// Line 556, Address: 0x213de0, Func Offset: 0xb0
	// Line 557, Address: 0x213de8, Func Offset: 0xb8
	// Line 559, Address: 0x213df0, Func Offset: 0xc0
	// Line 560, Address: 0x213df8, Func Offset: 0xc8
	// Line 561, Address: 0x213e30, Func Offset: 0x100
	// Line 562, Address: 0x213e58, Func Offset: 0x128
	// Line 563, Address: 0x213e68, Func Offset: 0x138
	// Line 564, Address: 0x213e84, Func Offset: 0x154
	// Line 565, Address: 0x213e94, Func Offset: 0x164
	// Line 568, Address: 0x213eac, Func Offset: 0x17c
	// Line 569, Address: 0x213eb8, Func Offset: 0x188
	// Line 570, Address: 0x213ecc, Func Offset: 0x19c
	// Line 574, Address: 0x213ed4, Func Offset: 0x1a4
	// Line 575, Address: 0x213ed8, Func Offset: 0x1a8
	// Line 576, Address: 0x213f00, Func Offset: 0x1d0
	// Line 577, Address: 0x213f1c, Func Offset: 0x1ec
	// Line 578, Address: 0x213f3c, Func Offset: 0x20c
	// Line 580, Address: 0x213f44, Func Offset: 0x214
	// Line 581, Address: 0x213f6c, Func Offset: 0x23c
	// Line 582, Address: 0x213f70, Func Offset: 0x240
	// Line 581, Address: 0x213f74, Func Offset: 0x244
	// Line 582, Address: 0x213f78, Func Offset: 0x248
	// Line 583, Address: 0x213f90, Func Offset: 0x260
	// Line 585, Address: 0x213f98, Func Offset: 0x268
	// Line 586, Address: 0x213fb8, Func Offset: 0x288
	// Line 587, Address: 0x213fc0, Func Offset: 0x290
	// Line 588, Address: 0x213fd8, Func Offset: 0x2a8
	// Line 587, Address: 0x213fe0, Func Offset: 0x2b0
	// Line 588, Address: 0x213fe4, Func Offset: 0x2b4
	// Line 589, Address: 0x213fec, Func Offset: 0x2bc
	// Line 590, Address: 0x213ff4, Func Offset: 0x2c4
	// Line 591, Address: 0x214000, Func Offset: 0x2d0
	// Line 592, Address: 0x214008, Func Offset: 0x2d8
	// Line 593, Address: 0x214010, Func Offset: 0x2e0
	// Line 594, Address: 0x214018, Func Offset: 0x2e8
	// Line 595, Address: 0x214028, Func Offset: 0x2f8
	// Line 597, Address: 0x214038, Func Offset: 0x308
	// Line 598, Address: 0x214054, Func Offset: 0x324
	// Line 599, Address: 0x214058, Func Offset: 0x328
	// Line 598, Address: 0x21405c, Func Offset: 0x32c
	// Line 600, Address: 0x214064, Func Offset: 0x334
	// Line 601, Address: 0x21406c, Func Offset: 0x33c
	// Line 602, Address: 0x214070, Func Offset: 0x340
	// Line 601, Address: 0x214074, Func Offset: 0x344
	// Line 602, Address: 0x21407c, Func Offset: 0x34c
	// Line 605, Address: 0x214080, Func Offset: 0x350
	// Line 606, Address: 0x2140a0, Func Offset: 0x370
	// Line 607, Address: 0x2140a8, Func Offset: 0x378
	// Line 608, Address: 0x2140ac, Func Offset: 0x37c
	// Line 607, Address: 0x2140b4, Func Offset: 0x384
	// Line 608, Address: 0x2140b8, Func Offset: 0x388
	// Line 614, Address: 0x2140d8, Func Offset: 0x3a8
	// Line 615, Address: 0x2140e4, Func Offset: 0x3b4
	// Line 617, Address: 0x21410c, Func Offset: 0x3dc
	// Line 618, Address: 0x214130, Func Offset: 0x400
	// Line 617, Address: 0x214134, Func Offset: 0x404
	// Line 618, Address: 0x214138, Func Offset: 0x408
	// Line 620, Address: 0x214144, Func Offset: 0x414
	// Line 621, Address: 0x214150, Func Offset: 0x420
	// Line 622, Address: 0x214154, Func Offset: 0x424
	// Line 623, Address: 0x21415c, Func Offset: 0x42c
	// Line 625, Address: 0x214164, Func Offset: 0x434
	// Line 626, Address: 0x21416c, Func Offset: 0x43c
	// Line 629, Address: 0x214170, Func Offset: 0x440
	// Func End, Address: 0x214190, Func Offset: 0x460
}

// 
// Start address: 0x214190
void bhEne30_MV02(BH_PWORK* epw)
{
	int i;
	npobj* objB;
	npobj* objA;
	float size;
	_anon3 pos;
	_anon3 v;
	int i;
	// Line 639, Address: 0x214190, Func Offset: 0
	// Line 640, Address: 0x2141b8, Func Offset: 0x28
	// Line 642, Address: 0x2141d8, Func Offset: 0x48
	// Line 645, Address: 0x2141e0, Func Offset: 0x50
	// Line 649, Address: 0x2141e4, Func Offset: 0x54
	// Line 642, Address: 0x2141e8, Func Offset: 0x58
	// Line 645, Address: 0x2141f0, Func Offset: 0x60
	// Line 646, Address: 0x2141f4, Func Offset: 0x64
	// Line 647, Address: 0x2141f8, Func Offset: 0x68
	// Line 649, Address: 0x2141fc, Func Offset: 0x6c
	// Line 650, Address: 0x214200, Func Offset: 0x70
	// Line 662, Address: 0x214204, Func Offset: 0x74
	// Line 650, Address: 0x214208, Func Offset: 0x78
	// Line 651, Address: 0x21420c, Func Offset: 0x7c
	// Line 652, Address: 0x214214, Func Offset: 0x84
	// Line 653, Address: 0x214220, Func Offset: 0x90
	// Line 664, Address: 0x214224, Func Offset: 0x94
	// Line 665, Address: 0x214268, Func Offset: 0xd8
	// Line 666, Address: 0x2142a0, Func Offset: 0x110
	// Line 669, Address: 0x2142e8, Func Offset: 0x158
	// Line 673, Address: 0x214310, Func Offset: 0x180
	// Line 669, Address: 0x214314, Func Offset: 0x184
	// Line 672, Address: 0x214318, Func Offset: 0x188
	// Line 669, Address: 0x21431c, Func Offset: 0x18c
	// Line 673, Address: 0x214320, Func Offset: 0x190
	// Line 669, Address: 0x214324, Func Offset: 0x194
	// Line 674, Address: 0x214334, Func Offset: 0x1a4
	// Line 677, Address: 0x21436c, Func Offset: 0x1dc
	// Line 674, Address: 0x214370, Func Offset: 0x1e0
	// Line 677, Address: 0x214380, Func Offset: 0x1f0
	// Line 678, Address: 0x214388, Func Offset: 0x1f8
	// Line 679, Address: 0x2143d0, Func Offset: 0x240
	// Line 681, Address: 0x2143e0, Func Offset: 0x250
	// Line 682, Address: 0x2143f4, Func Offset: 0x264
	// Line 684, Address: 0x214404, Func Offset: 0x274
	// Line 686, Address: 0x214408, Func Offset: 0x278
	// Line 687, Address: 0x21444c, Func Offset: 0x2bc
	// Line 688, Address: 0x214480, Func Offset: 0x2f0
	// Line 691, Address: 0x2144c4, Func Offset: 0x334
	// Line 694, Address: 0x2144e8, Func Offset: 0x358
	// Line 691, Address: 0x2144ec, Func Offset: 0x35c
	// Line 695, Address: 0x214500, Func Offset: 0x370
	// Line 691, Address: 0x214504, Func Offset: 0x374
	// Line 696, Address: 0x21450c, Func Offset: 0x37c
	// Line 699, Address: 0x214534, Func Offset: 0x3a4
	// Line 696, Address: 0x214538, Func Offset: 0x3a8
	// Line 699, Address: 0x214558, Func Offset: 0x3c8
	// Line 700, Address: 0x214560, Func Offset: 0x3d0
	// Line 701, Address: 0x2145a8, Func Offset: 0x418
	// Line 703, Address: 0x2145b8, Func Offset: 0x428
	// Line 704, Address: 0x2145cc, Func Offset: 0x43c
	// Line 708, Address: 0x2145dc, Func Offset: 0x44c
	// Line 710, Address: 0x2145f0, Func Offset: 0x460
	// Line 712, Address: 0x2145fc, Func Offset: 0x46c
	// Line 713, Address: 0x214608, Func Offset: 0x478
	// Line 712, Address: 0x214614, Func Offset: 0x484
	// Line 713, Address: 0x214618, Func Offset: 0x488
	// Line 714, Address: 0x214628, Func Offset: 0x498
	// Line 715, Address: 0x21462c, Func Offset: 0x49c
	// Line 716, Address: 0x214634, Func Offset: 0x4a4
	// Line 720, Address: 0x21463c, Func Offset: 0x4ac
	// Line 716, Address: 0x214640, Func Offset: 0x4b0
	// Line 719, Address: 0x214648, Func Offset: 0x4b8
	// Line 720, Address: 0x21464c, Func Offset: 0x4bc
	// Line 721, Address: 0x214650, Func Offset: 0x4c0
	// Line 729, Address: 0x214654, Func Offset: 0x4c4
	// Line 730, Address: 0x214658, Func Offset: 0x4c8
	// Line 731, Address: 0x21465c, Func Offset: 0x4cc
	// Line 729, Address: 0x214664, Func Offset: 0x4d4
	// Line 730, Address: 0x214668, Func Offset: 0x4d8
	// Line 732, Address: 0x21466c, Func Offset: 0x4dc
	// Line 733, Address: 0x214678, Func Offset: 0x4e8
	// Line 732, Address: 0x21467c, Func Offset: 0x4ec
	// Line 733, Address: 0x214680, Func Offset: 0x4f0
	// Line 732, Address: 0x214684, Func Offset: 0x4f4
	// Line 733, Address: 0x2146a0, Func Offset: 0x510
	// Line 735, Address: 0x2146ac, Func Offset: 0x51c
	// Line 736, Address: 0x2146b0, Func Offset: 0x520
	// Func End, Address: 0x2146d8, Func Offset: 0x548
}

// 
// Start address: 0x2146e0
void bhEne30_MV03(BH_PWORK* epw)
{
	int i;
	npobj* objB;
	npobj* objA;
	// Line 747, Address: 0x2146e0, Func Offset: 0
	// Line 749, Address: 0x214700, Func Offset: 0x20
	// Line 752, Address: 0x214708, Func Offset: 0x28
	// Line 754, Address: 0x21470c, Func Offset: 0x2c
	// Line 749, Address: 0x214710, Func Offset: 0x30
	// Line 752, Address: 0x214718, Func Offset: 0x38
	// Line 753, Address: 0x21471c, Func Offset: 0x3c
	// Line 754, Address: 0x214720, Func Offset: 0x40
	// Line 755, Address: 0x214724, Func Offset: 0x44
	// Line 757, Address: 0x21472c, Func Offset: 0x4c
	// Line 758, Address: 0x214734, Func Offset: 0x54
	// Line 761, Address: 0x214738, Func Offset: 0x58
	// Line 758, Address: 0x21473c, Func Offset: 0x5c
	// Line 759, Address: 0x214740, Func Offset: 0x60
	// Line 760, Address: 0x214748, Func Offset: 0x68
	// Line 761, Address: 0x214754, Func Offset: 0x74
	// Line 763, Address: 0x214758, Func Offset: 0x78
	// Line 765, Address: 0x214764, Func Offset: 0x84
	// Line 766, Address: 0x214770, Func Offset: 0x90
	// Line 765, Address: 0x214778, Func Offset: 0x98
	// Line 766, Address: 0x21477c, Func Offset: 0x9c
	// Line 768, Address: 0x21478c, Func Offset: 0xac
	// Line 767, Address: 0x214790, Func Offset: 0xb0
	// Line 768, Address: 0x214794, Func Offset: 0xb4
	// Line 769, Address: 0x214798, Func Offset: 0xb8
	// Line 770, Address: 0x21479c, Func Offset: 0xbc
	// Line 769, Address: 0x2147a0, Func Offset: 0xc0
	// Line 770, Address: 0x2147a4, Func Offset: 0xc4
	// Line 771, Address: 0x2147a8, Func Offset: 0xc8
	// Line 769, Address: 0x2147ac, Func Offset: 0xcc
	// Line 770, Address: 0x2147b4, Func Offset: 0xd4
	// Line 774, Address: 0x2147b8, Func Offset: 0xd8
	// Line 770, Address: 0x2147bc, Func Offset: 0xdc
	// Line 771, Address: 0x2147c4, Func Offset: 0xe4
	// Line 774, Address: 0x2147d0, Func Offset: 0xf0
	// Line 775, Address: 0x2147d4, Func Offset: 0xf4
	// Line 776, Address: 0x2147d8, Func Offset: 0xf8
	// Line 784, Address: 0x2147dc, Func Offset: 0xfc
	// Line 785, Address: 0x2147e0, Func Offset: 0x100
	// Line 786, Address: 0x2147e4, Func Offset: 0x104
	// Line 784, Address: 0x2147ec, Func Offset: 0x10c
	// Line 785, Address: 0x2147f0, Func Offset: 0x110
	// Line 787, Address: 0x2147f4, Func Offset: 0x114
	// Line 788, Address: 0x214800, Func Offset: 0x120
	// Line 787, Address: 0x214804, Func Offset: 0x124
	// Line 788, Address: 0x214808, Func Offset: 0x128
	// Line 787, Address: 0x21480c, Func Offset: 0x12c
	// Line 788, Address: 0x214828, Func Offset: 0x148
	// Line 790, Address: 0x214834, Func Offset: 0x154
	// Line 791, Address: 0x214838, Func Offset: 0x158
	// Func End, Address: 0x214840, Func Offset: 0x160
}

// 
// Start address: 0x214840
void bhEne30_MV04(BH_PWORK* epw)
{
	int mtn[3];
	// Line 801, Address: 0x214840, Func Offset: 0
	// Line 802, Address: 0x214844, Func Offset: 0x4
	// Line 801, Address: 0x214848, Func Offset: 0x8
	// Line 802, Address: 0x214850, Func Offset: 0x10
	// Line 807, Address: 0x214868, Func Offset: 0x28
	// Line 809, Address: 0x21487c, Func Offset: 0x3c
	// Line 812, Address: 0x214888, Func Offset: 0x48
	// Line 814, Address: 0x2148d0, Func Offset: 0x90
	// Line 812, Address: 0x2148d4, Func Offset: 0x94
	// Line 813, Address: 0x2148d8, Func Offset: 0x98
	// Line 815, Address: 0x2148dc, Func Offset: 0x9c
	// Line 814, Address: 0x2148e0, Func Offset: 0xa0
	// Line 815, Address: 0x2148e4, Func Offset: 0xa4
	// Line 816, Address: 0x2148e8, Func Offset: 0xa8
	// Line 818, Address: 0x2148f4, Func Offset: 0xb4
	// Func End, Address: 0x214904, Func Offset: 0xc4
}

// 
// Start address: 0x214910
void bhEne30_MV05(BH_PWORK* epw)
{
	_anon18* owk;
	int i;
	_anon3 pos;
	int mtn[3];
	// Line 828, Address: 0x214910, Func Offset: 0
	// Line 829, Address: 0x21491c, Func Offset: 0xc
	// Line 828, Address: 0x214920, Func Offset: 0x10
	// Line 829, Address: 0x214928, Func Offset: 0x18
	// Line 838, Address: 0x214944, Func Offset: 0x34
	// Line 840, Address: 0x214964, Func Offset: 0x54
	// Line 843, Address: 0x214968, Func Offset: 0x58
	// Line 840, Address: 0x214970, Func Offset: 0x60
	// Line 843, Address: 0x21497c, Func Offset: 0x6c
	// Line 844, Address: 0x214994, Func Offset: 0x84
	// Line 845, Address: 0x2149d0, Func Offset: 0xc0
	// Line 846, Address: 0x2149f4, Func Offset: 0xe4
	// Line 847, Address: 0x214a30, Func Offset: 0x120
	// Line 848, Address: 0x214a38, Func Offset: 0x128
	// Line 850, Address: 0x214a3c, Func Offset: 0x12c
	// Line 852, Address: 0x214a40, Func Offset: 0x130
	// Line 853, Address: 0x214a44, Func Offset: 0x134
	// Line 855, Address: 0x214a48, Func Offset: 0x138
	// Line 850, Address: 0x214a4c, Func Offset: 0x13c
	// Line 859, Address: 0x214a58, Func Offset: 0x148
	// Line 850, Address: 0x214a60, Func Offset: 0x150
	// Line 851, Address: 0x214a64, Func Offset: 0x154
	// Line 852, Address: 0x214a68, Func Offset: 0x158
	// Line 853, Address: 0x214a6c, Func Offset: 0x15c
	// Line 854, Address: 0x214a70, Func Offset: 0x160
	// Line 859, Address: 0x214a74, Func Offset: 0x164
	// Line 854, Address: 0x214a7c, Func Offset: 0x16c
	// Line 855, Address: 0x214a9c, Func Offset: 0x18c
	// Line 856, Address: 0x214aa0, Func Offset: 0x190
	// Line 859, Address: 0x214aa8, Func Offset: 0x198
	// Line 860, Address: 0x214ab0, Func Offset: 0x1a0
	// Line 862, Address: 0x214ab8, Func Offset: 0x1a8
	// Line 864, Address: 0x214ac8, Func Offset: 0x1b8
	// Line 865, Address: 0x214ad0, Func Offset: 0x1c0
	// Line 871, Address: 0x214ad4, Func Offset: 0x1c4
	// Line 875, Address: 0x214b08, Func Offset: 0x1f8
	// Line 876, Address: 0x214b10, Func Offset: 0x200
	// Line 880, Address: 0x214b14, Func Offset: 0x204
	// Line 876, Address: 0x214b28, Func Offset: 0x218
	// Line 877, Address: 0x214b30, Func Offset: 0x220
	// Line 878, Address: 0x214b38, Func Offset: 0x228
	// Line 879, Address: 0x214b40, Func Offset: 0x230
	// Line 880, Address: 0x214b44, Func Offset: 0x234
	// Line 882, Address: 0x214b54, Func Offset: 0x244
	// Line 885, Address: 0x214b68, Func Offset: 0x258
	// Line 886, Address: 0x214b7c, Func Offset: 0x26c
	// Line 885, Address: 0x214b80, Func Offset: 0x270
	// Line 886, Address: 0x214b88, Func Offset: 0x278
	// Line 887, Address: 0x214b90, Func Offset: 0x280
	// Line 886, Address: 0x214b94, Func Offset: 0x284
	// Line 887, Address: 0x214b9c, Func Offset: 0x28c
	// Line 888, Address: 0x214ba4, Func Offset: 0x294
	// Line 887, Address: 0x214ba8, Func Offset: 0x298
	// Line 888, Address: 0x214bb0, Func Offset: 0x2a0
	// Line 890, Address: 0x214bc8, Func Offset: 0x2b8
	// Line 893, Address: 0x214bdc, Func Offset: 0x2cc
	// Line 894, Address: 0x214bec, Func Offset: 0x2dc
	// Line 895, Address: 0x214bf8, Func Offset: 0x2e8
	// Line 896, Address: 0x214c04, Func Offset: 0x2f4
	// Line 897, Address: 0x214c30, Func Offset: 0x320
	// Line 898, Address: 0x214c38, Func Offset: 0x328
	// Line 899, Address: 0x214c40, Func Offset: 0x330
	// Line 909, Address: 0x214c50, Func Offset: 0x340
	// Line 911, Address: 0x214c58, Func Offset: 0x348
	// Line 913, Address: 0x214c68, Func Offset: 0x358
	// Func End, Address: 0x214c80, Func Offset: 0x370
}

// 
// Start address: 0x214c80
void bhEne30_MV06(BH_PWORK* epw)
{
	float size;
	float spd;
	_anon3 pos;
	_anon3 v;
	int i;
	// Line 923, Address: 0x214c80, Func Offset: 0
	// Line 924, Address: 0x214ca8, Func Offset: 0x28
	// Line 926, Address: 0x214cc8, Func Offset: 0x48
	// Line 927, Address: 0x214cd4, Func Offset: 0x54
	// Line 928, Address: 0x214cd8, Func Offset: 0x58
	// Line 926, Address: 0x214cdc, Func Offset: 0x5c
	// Line 927, Address: 0x214ce4, Func Offset: 0x64
	// Line 932, Address: 0x214ce8, Func Offset: 0x68
	// Line 927, Address: 0x214cec, Func Offset: 0x6c
	// Line 928, Address: 0x214cf4, Func Offset: 0x74
	// Line 929, Address: 0x214d00, Func Offset: 0x80
	// Line 930, Address: 0x214d04, Func Offset: 0x84
	// Line 931, Address: 0x214d08, Func Offset: 0x88
	// Line 932, Address: 0x214d0c, Func Offset: 0x8c
	// Line 933, Address: 0x214d10, Func Offset: 0x90
	// Line 935, Address: 0x214d14, Func Offset: 0x94
	// Line 938, Address: 0x214d18, Func Offset: 0x98
	// Line 939, Address: 0x214d24, Func Offset: 0xa4
	// Line 941, Address: 0x214d30, Func Offset: 0xb0
	// Line 944, Address: 0x214d3c, Func Offset: 0xbc
	// Line 947, Address: 0x214d48, Func Offset: 0xc8
	// Line 954, Address: 0x214d58, Func Offset: 0xd8
	// Line 955, Address: 0x214d64, Func Offset: 0xe4
	// Line 954, Address: 0x214d68, Func Offset: 0xe8
	// Line 955, Address: 0x214d6c, Func Offset: 0xec
	// Line 956, Address: 0x214d70, Func Offset: 0xf0
	// Line 958, Address: 0x214d84, Func Offset: 0x104
	// Line 960, Address: 0x214d88, Func Offset: 0x108
	// Line 961, Address: 0x214dcc, Func Offset: 0x14c
	// Line 962, Address: 0x214e04, Func Offset: 0x184
	// Line 965, Address: 0x214e4c, Func Offset: 0x1cc
	// Line 968, Address: 0x214e8c, Func Offset: 0x20c
	// Line 969, Address: 0x214ebc, Func Offset: 0x23c
	// Line 968, Address: 0x214ec0, Func Offset: 0x240
	// Line 969, Address: 0x214ec8, Func Offset: 0x248
	// Line 970, Address: 0x214ed0, Func Offset: 0x250
	// Line 971, Address: 0x214ed8, Func Offset: 0x258
	// Line 974, Address: 0x214f00, Func Offset: 0x280
	// Line 971, Address: 0x214f04, Func Offset: 0x284
	// Line 974, Address: 0x214f24, Func Offset: 0x2a4
	// Line 975, Address: 0x214f2c, Func Offset: 0x2ac
	// Line 976, Address: 0x214f80, Func Offset: 0x300
	// Line 978, Address: 0x214f90, Func Offset: 0x310
	// Line 979, Address: 0x214fa4, Func Offset: 0x324
	// Line 981, Address: 0x214fb4, Func Offset: 0x334
	// Line 983, Address: 0x214fb8, Func Offset: 0x338
	// Line 984, Address: 0x214ffc, Func Offset: 0x37c
	// Line 985, Address: 0x215030, Func Offset: 0x3b0
	// Line 988, Address: 0x215074, Func Offset: 0x3f4
	// Line 991, Address: 0x2150b4, Func Offset: 0x434
	// Line 992, Address: 0x2150e4, Func Offset: 0x464
	// Line 991, Address: 0x2150e8, Func Offset: 0x468
	// Line 992, Address: 0x2150f0, Func Offset: 0x470
	// Line 993, Address: 0x2150f8, Func Offset: 0x478
	// Line 994, Address: 0x215100, Func Offset: 0x480
	// Line 997, Address: 0x215128, Func Offset: 0x4a8
	// Line 994, Address: 0x21512c, Func Offset: 0x4ac
	// Line 997, Address: 0x21514c, Func Offset: 0x4cc
	// Line 998, Address: 0x215154, Func Offset: 0x4d4
	// Line 999, Address: 0x2151a8, Func Offset: 0x528
	// Line 1001, Address: 0x2151b8, Func Offset: 0x538
	// Line 1002, Address: 0x2151cc, Func Offset: 0x54c
	// Line 1003, Address: 0x2151dc, Func Offset: 0x55c
	// Line 1005, Address: 0x2151e0, Func Offset: 0x560
	// Line 1007, Address: 0x2151f8, Func Offset: 0x578
	// Line 1008, Address: 0x215200, Func Offset: 0x580
	// Line 1009, Address: 0x215204, Func Offset: 0x584
	// Line 1011, Address: 0x215208, Func Offset: 0x588
	// Line 1014, Address: 0x215214, Func Offset: 0x594
	// Line 1017, Address: 0x21521c, Func Offset: 0x59c
	// Func End, Address: 0x215244, Func Offset: 0x5c4
}

// 
// Start address: 0x215250
void bhEne30_MV07(BH_PWORK* epw)
{
	float dist;
	// Line 1027, Address: 0x215250, Func Offset: 0
	// Line 1030, Address: 0x215264, Func Offset: 0x14
	// Line 1032, Address: 0x215284, Func Offset: 0x34
	// Line 1033, Address: 0x215290, Func Offset: 0x40
	// Line 1034, Address: 0x215294, Func Offset: 0x44
	// Line 1032, Address: 0x215298, Func Offset: 0x48
	// Line 1033, Address: 0x2152a0, Func Offset: 0x50
	// Line 1035, Address: 0x2152a4, Func Offset: 0x54
	// Line 1040, Address: 0x2152a8, Func Offset: 0x58
	// Line 1042, Address: 0x2152ac, Func Offset: 0x5c
	// Line 1033, Address: 0x2152b0, Func Offset: 0x60
	// Line 1034, Address: 0x2152b8, Func Offset: 0x68
	// Line 1035, Address: 0x2152c4, Func Offset: 0x74
	// Line 1036, Address: 0x2152d0, Func Offset: 0x80
	// Line 1037, Address: 0x2152d4, Func Offset: 0x84
	// Line 1038, Address: 0x2152d8, Func Offset: 0x88
	// Line 1039, Address: 0x2152dc, Func Offset: 0x8c
	// Line 1040, Address: 0x2152e0, Func Offset: 0x90
	// Line 1042, Address: 0x2152e4, Func Offset: 0x94
	// Line 1043, Address: 0x21530c, Func Offset: 0xbc
	// Line 1044, Address: 0x215338, Func Offset: 0xe8
	// Line 1045, Address: 0x21534c, Func Offset: 0xfc
	// Line 1044, Address: 0x215350, Func Offset: 0x100
	// Line 1045, Address: 0x215360, Func Offset: 0x110
	// Line 1047, Address: 0x215364, Func Offset: 0x114
	// Line 1049, Address: 0x215370, Func Offset: 0x120
	// Line 1051, Address: 0x215384, Func Offset: 0x134
	// Line 1054, Address: 0x21538c, Func Offset: 0x13c
	// Line 1057, Address: 0x215398, Func Offset: 0x148
	// Line 1051, Address: 0x21539c, Func Offset: 0x14c
	// Line 1052, Address: 0x2153a4, Func Offset: 0x154
	// Line 1053, Address: 0x2153b4, Func Offset: 0x164
	// Line 1054, Address: 0x2153c4, Func Offset: 0x174
	// Line 1057, Address: 0x2153cc, Func Offset: 0x17c
	// Line 1058, Address: 0x2153dc, Func Offset: 0x18c
	// Line 1059, Address: 0x2153f8, Func Offset: 0x1a8
	// Line 1060, Address: 0x215400, Func Offset: 0x1b0
	// Line 1064, Address: 0x215410, Func Offset: 0x1c0
	// Line 1065, Address: 0x215428, Func Offset: 0x1d8
	// Line 1067, Address: 0x215440, Func Offset: 0x1f0
	// Line 1068, Address: 0x215454, Func Offset: 0x204
	// Line 1067, Address: 0x215458, Func Offset: 0x208
	// Line 1068, Address: 0x215460, Func Offset: 0x210
	// Line 1069, Address: 0x215468, Func Offset: 0x218
	// Line 1068, Address: 0x21546c, Func Offset: 0x21c
	// Line 1069, Address: 0x215474, Func Offset: 0x224
	// Line 1070, Address: 0x21547c, Func Offset: 0x22c
	// Line 1069, Address: 0x215480, Func Offset: 0x230
	// Line 1070, Address: 0x215488, Func Offset: 0x238
	// Line 1072, Address: 0x2154a0, Func Offset: 0x250
	// Line 1077, Address: 0x2154ac, Func Offset: 0x25c
	// Line 1072, Address: 0x2154b4, Func Offset: 0x264
	// Line 1073, Address: 0x2154b8, Func Offset: 0x268
	// Line 1077, Address: 0x2154c0, Func Offset: 0x270
	// Line 1073, Address: 0x2154cc, Func Offset: 0x27c
	// Line 1074, Address: 0x2154d0, Func Offset: 0x280
	// Line 1075, Address: 0x2154dc, Func Offset: 0x28c
	// Line 1077, Address: 0x2154e4, Func Offset: 0x294
	// Line 1078, Address: 0x2154ec, Func Offset: 0x29c
	// Line 1080, Address: 0x2154fc, Func Offset: 0x2ac
	// Line 1078, Address: 0x215500, Func Offset: 0x2b0
	// Line 1079, Address: 0x215508, Func Offset: 0x2b8
	// Line 1083, Address: 0x215514, Func Offset: 0x2c4
	// Line 1085, Address: 0x21551c, Func Offset: 0x2cc
	// Line 1086, Address: 0x215524, Func Offset: 0x2d4
	// Line 1087, Address: 0x215528, Func Offset: 0x2d8
	// Line 1089, Address: 0x21552c, Func Offset: 0x2dc
	// Line 1090, Address: 0x215530, Func Offset: 0x2e0
	// Line 1093, Address: 0x215534, Func Offset: 0x2e4
	// Line 1089, Address: 0x215538, Func Offset: 0x2e8
	// Line 1090, Address: 0x215540, Func Offset: 0x2f0
	// Line 1091, Address: 0x215544, Func Offset: 0x2f4
	// Line 1093, Address: 0x215548, Func Offset: 0x2f8
	// Line 1097, Address: 0x21554c, Func Offset: 0x2fc
	// Line 1099, Address: 0x21555c, Func Offset: 0x30c
	// Line 1102, Address: 0x215560, Func Offset: 0x310
	// Func End, Address: 0x215574, Func Offset: 0x324
}

// 
// Start address: 0x215580
void bhEne30_Nage()
{
	// Line 1113, Address: 0x215580, Func Offset: 0
	// Func End, Address: 0x215588, Func Offset: 0x8
}

// 
// Start address: 0x215590
void bhEne30_Damage(BH_PWORK* epw)
{
	// Line 1124, Address: 0x215590, Func Offset: 0
	// Func End, Address: 0x2155b0, Func Offset: 0x20
}

// 
// Start address: 0x2155b0
void bhEne30_DG00(BH_PWORK* epw)
{
	// Line 1136, Address: 0x2155b0, Func Offset: 0
	// Line 1138, Address: 0x2155d0, Func Offset: 0x20
	// Line 1140, Address: 0x2155d8, Func Offset: 0x28
	// Line 1139, Address: 0x2155dc, Func Offset: 0x2c
	// Line 1140, Address: 0x2155e0, Func Offset: 0x30
	// Line 1141, Address: 0x2155e4, Func Offset: 0x34
	// Line 1142, Address: 0x2155ec, Func Offset: 0x3c
	// Line 1143, Address: 0x2155f4, Func Offset: 0x44
	// Line 1144, Address: 0x2155fc, Func Offset: 0x4c
	// Line 1145, Address: 0x215604, Func Offset: 0x54
	// Line 1147, Address: 0x21560c, Func Offset: 0x5c
	// Line 1148, Address: 0x21561c, Func Offset: 0x6c
	// Line 1149, Address: 0x215624, Func Offset: 0x74
	// Line 1151, Address: 0x215628, Func Offset: 0x78
	// Line 1150, Address: 0x21562c, Func Offset: 0x7c
	// Line 1151, Address: 0x215630, Func Offset: 0x80
	// Line 1152, Address: 0x215634, Func Offset: 0x84
	// Line 1155, Address: 0x215638, Func Offset: 0x88
	// Func End, Address: 0x215640, Func Offset: 0x90
}

// 
// Start address: 0x215640
void bhEne30_DG01(BH_PWORK* epw)
{
	// Line 1166, Address: 0x215640, Func Offset: 0
	// Line 1168, Address: 0x215660, Func Offset: 0x20
	// Line 1170, Address: 0x215668, Func Offset: 0x28
	// Line 1169, Address: 0x21566c, Func Offset: 0x2c
	// Line 1170, Address: 0x215670, Func Offset: 0x30
	// Line 1171, Address: 0x215674, Func Offset: 0x34
	// Line 1172, Address: 0x21567c, Func Offset: 0x3c
	// Line 1173, Address: 0x215684, Func Offset: 0x44
	// Line 1174, Address: 0x21568c, Func Offset: 0x4c
	// Line 1176, Address: 0x215694, Func Offset: 0x54
	// Line 1177, Address: 0x2156a0, Func Offset: 0x60
	// Line 1178, Address: 0x2156a8, Func Offset: 0x68
	// Line 1179, Address: 0x2156ac, Func Offset: 0x6c
	// Line 1180, Address: 0x2156b0, Func Offset: 0x70
	// Line 1181, Address: 0x2156b4, Func Offset: 0x74
	// Line 1184, Address: 0x2156b8, Func Offset: 0x78
	// Func End, Address: 0x2156c0, Func Offset: 0x80
}

// 
// Start address: 0x2156c0
void bhEne30_Die(BH_PWORK* epw)
{
	// Line 1195, Address: 0x2156c0, Func Offset: 0
	// Func End, Address: 0x2156e0, Func Offset: 0x20
}

// 
// Start address: 0x2156e0
void bhEne30_DD00(BH_PWORK* epw)
{
	_anon18* owk;
	int i;
	npobj* objB;
	npobj* objA;
	// Line 1206, Address: 0x2156e0, Func Offset: 0
	// Line 1209, Address: 0x2156ec, Func Offset: 0xc
	// Line 1211, Address: 0x215724, Func Offset: 0x44
	// Line 1213, Address: 0x215728, Func Offset: 0x48
	// Line 1212, Address: 0x215730, Func Offset: 0x50
	// Line 1218, Address: 0x215734, Func Offset: 0x54
	// Line 1211, Address: 0x215738, Func Offset: 0x58
	// Line 1212, Address: 0x215740, Func Offset: 0x60
	// Line 1220, Address: 0x215744, Func Offset: 0x64
	// Line 1221, Address: 0x215748, Func Offset: 0x68
	// Line 1231, Address: 0x21574c, Func Offset: 0x6c
	// Line 1212, Address: 0x215750, Func Offset: 0x70
	// Line 1213, Address: 0x215758, Func Offset: 0x78
	// Line 1231, Address: 0x21575c, Func Offset: 0x7c
	// Line 1213, Address: 0x215764, Func Offset: 0x84
	// Line 1216, Address: 0x21576c, Func Offset: 0x8c
	// Line 1218, Address: 0x215778, Func Offset: 0x98
	// Line 1219, Address: 0x21577c, Func Offset: 0x9c
	// Line 1220, Address: 0x215780, Func Offset: 0xa0
	// Line 1221, Address: 0x215784, Func Offset: 0xa4
	// Line 1222, Address: 0x215788, Func Offset: 0xa8
	// Line 1226, Address: 0x2157ac, Func Offset: 0xcc
	// Line 1228, Address: 0x2157c0, Func Offset: 0xe0
	// Line 1231, Address: 0x2157d0, Func Offset: 0xf0
	// Line 1233, Address: 0x2157d8, Func Offset: 0xf8
	// Line 1235, Address: 0x2157e4, Func Offset: 0x104
	// Line 1236, Address: 0x2157f4, Func Offset: 0x114
	// Line 1240, Address: 0x2157f8, Func Offset: 0x118
	// Line 1241, Address: 0x215804, Func Offset: 0x124
	// Line 1240, Address: 0x215810, Func Offset: 0x130
	// Line 1241, Address: 0x215814, Func Offset: 0x134
	// Line 1242, Address: 0x215824, Func Offset: 0x144
	// Line 1243, Address: 0x215828, Func Offset: 0x148
	// Line 1251, Address: 0x215834, Func Offset: 0x154
	// Line 1252, Address: 0x215838, Func Offset: 0x158
	// Line 1253, Address: 0x21583c, Func Offset: 0x15c
	// Line 1251, Address: 0x215844, Func Offset: 0x164
	// Line 1252, Address: 0x215848, Func Offset: 0x168
	// Line 1254, Address: 0x21584c, Func Offset: 0x16c
	// Line 1255, Address: 0x215858, Func Offset: 0x178
	// Line 1254, Address: 0x21585c, Func Offset: 0x17c
	// Line 1255, Address: 0x215860, Func Offset: 0x180
	// Line 1254, Address: 0x215864, Func Offset: 0x184
	// Line 1255, Address: 0x215880, Func Offset: 0x1a0
	// Line 1259, Address: 0x21588c, Func Offset: 0x1ac
	// Line 1261, Address: 0x21589c, Func Offset: 0x1bc
	// Line 1266, Address: 0x2158a0, Func Offset: 0x1c0
	// Line 1261, Address: 0x2158a4, Func Offset: 0x1c4
	// Line 1262, Address: 0x2158a8, Func Offset: 0x1c8
	// Line 1263, Address: 0x2158b0, Func Offset: 0x1d0
	// Line 1264, Address: 0x2158b8, Func Offset: 0x1d8
	// Line 1266, Address: 0x2158c0, Func Offset: 0x1e0
	// Line 1267, Address: 0x2158d0, Func Offset: 0x1f0
	// Line 1269, Address: 0x2158e8, Func Offset: 0x208
	// Line 1271, Address: 0x215928, Func Offset: 0x248
	// Line 1274, Address: 0x215930, Func Offset: 0x250
	// Line 1275, Address: 0x215934, Func Offset: 0x254
	// Line 1274, Address: 0x215940, Func Offset: 0x260
	// Line 1275, Address: 0x215944, Func Offset: 0x264
	// Line 1276, Address: 0x21594c, Func Offset: 0x26c
	// Line 1277, Address: 0x215954, Func Offset: 0x274
	// Line 1279, Address: 0x215960, Func Offset: 0x280
	// Line 1281, Address: 0x215970, Func Offset: 0x290
	// Line 1284, Address: 0x215974, Func Offset: 0x294
	// Func End, Address: 0x215984, Func Offset: 0x2a4
}

// 
// Start address: 0x215990
void bhEne30_DD01(BH_PWORK* epw)
{
	// Line 1294, Address: 0x215990, Func Offset: 0
	// Line 1295, Address: 0x21599c, Func Offset: 0xc
	// Line 1297, Address: 0x2159bc, Func Offset: 0x2c
	// Line 1299, Address: 0x2159c0, Func Offset: 0x30
	// Line 1298, Address: 0x2159c8, Func Offset: 0x38
	// Line 1302, Address: 0x2159cc, Func Offset: 0x3c
	// Line 1297, Address: 0x2159d0, Func Offset: 0x40
	// Line 1298, Address: 0x2159d8, Func Offset: 0x48
	// Line 1302, Address: 0x2159dc, Func Offset: 0x4c
	// Line 1298, Address: 0x2159e4, Func Offset: 0x54
	// Line 1299, Address: 0x2159ec, Func Offset: 0x5c
	// Line 1302, Address: 0x2159f4, Func Offset: 0x64
	// Line 1305, Address: 0x2159fc, Func Offset: 0x6c
	// Line 1308, Address: 0x215a00, Func Offset: 0x70
	// Line 1305, Address: 0x215a04, Func Offset: 0x74
	// Line 1307, Address: 0x215a0c, Func Offset: 0x7c
	// Line 1308, Address: 0x215a18, Func Offset: 0x88
	// Line 1309, Address: 0x215a1c, Func Offset: 0x8c
	// Line 1311, Address: 0x215a28, Func Offset: 0x98
	// Line 1313, Address: 0x215a38, Func Offset: 0xa8
	// Line 1316, Address: 0x215a3c, Func Offset: 0xac
	// Func End, Address: 0x215a4c, Func Offset: 0xbc
}

// 
// Start address: 0x215a50
void bhEne30_CheckEnemies(BH_PWORK* epw)
{
	BH_PWORK* ep;
	float len;
	float dz;
	float dx;
	int i;
	// Line 1326, Address: 0x215a50, Func Offset: 0
	// Line 1331, Address: 0x215a64, Func Offset: 0x14
	// Line 1326, Address: 0x215a68, Func Offset: 0x18
	// Line 1331, Address: 0x215a6c, Func Offset: 0x1c
	// Line 1326, Address: 0x215a70, Func Offset: 0x20
	// Line 1332, Address: 0x215a78, Func Offset: 0x28
	// Line 1333, Address: 0x215a80, Func Offset: 0x30
	// Line 1335, Address: 0x215abc, Func Offset: 0x6c
	// Line 1336, Address: 0x215ac4, Func Offset: 0x74
	// Line 1335, Address: 0x215acc, Func Offset: 0x7c
	// Line 1336, Address: 0x215ad0, Func Offset: 0x80
	// Line 1337, Address: 0x215ad4, Func Offset: 0x84
	// Line 1338, Address: 0x215ae0, Func Offset: 0x90
	// Line 1339, Address: 0x215af8, Func Offset: 0xa8
	// Line 1340, Address: 0x215b14, Func Offset: 0xc4
	// Line 1341, Address: 0x215b28, Func Offset: 0xd8
	// Line 1344, Address: 0x215b48, Func Offset: 0xf8
	// Line 1345, Address: 0x215b70, Func Offset: 0x120
	// Func End, Address: 0x215b90, Func Offset: 0x140
}

// 
// Start address: 0x215b90
void bhEne30_DamageInit(BH_PWORK* epw)
{
	_anon3 ofp;
	int dam;
	int i;
	// Line 1355, Address: 0x215b90, Func Offset: 0
	// Line 1359, Address: 0x215ba0, Func Offset: 0x10
	// Line 1360, Address: 0x215ba4, Func Offset: 0x14
	// Line 1361, Address: 0x215bb0, Func Offset: 0x20
	// Line 1362, Address: 0x215bbc, Func Offset: 0x2c
	// Line 1363, Address: 0x215bc0, Func Offset: 0x30
	// Line 1364, Address: 0x215bc4, Func Offset: 0x34
	// Line 1363, Address: 0x215bc8, Func Offset: 0x38
	// Line 1365, Address: 0x215bcc, Func Offset: 0x3c
	// Line 1367, Address: 0x215be4, Func Offset: 0x54
	// Line 1368, Address: 0x215bec, Func Offset: 0x5c
	// Line 1371, Address: 0x215bf0, Func Offset: 0x60
	// Line 1368, Address: 0x215bfc, Func Offset: 0x6c
	// Line 1371, Address: 0x215c04, Func Offset: 0x74
	// Line 1373, Address: 0x215c10, Func Offset: 0x80
	// Line 1378, Address: 0x215c30, Func Offset: 0xa0
	// Line 1379, Address: 0x215c34, Func Offset: 0xa4
	// Line 1380, Address: 0x215c3c, Func Offset: 0xac
	// Line 1381, Address: 0x215c40, Func Offset: 0xb0
	// Line 1382, Address: 0x215c48, Func Offset: 0xb8
	// Line 1383, Address: 0x215c4c, Func Offset: 0xbc
	// Line 1382, Address: 0x215c58, Func Offset: 0xc8
	// Line 1383, Address: 0x215c5c, Func Offset: 0xcc
	// Line 1387, Address: 0x215c64, Func Offset: 0xd4
	// Line 1388, Address: 0x215c6c, Func Offset: 0xdc
	// Line 1392, Address: 0x215c70, Func Offset: 0xe0
	// Line 1393, Address: 0x215c84, Func Offset: 0xf4
	// Line 1395, Address: 0x215c94, Func Offset: 0x104
	// Line 1397, Address: 0x215ca8, Func Offset: 0x118
	// Line 1398, Address: 0x215cb0, Func Offset: 0x120
	// Line 1400, Address: 0x215cb4, Func Offset: 0x124
	// Line 1402, Address: 0x215cbc, Func Offset: 0x12c
	// Line 1406, Address: 0x215ccc, Func Offset: 0x13c
	// Line 1408, Address: 0x215cd4, Func Offset: 0x144
	// Line 1409, Address: 0x215cdc, Func Offset: 0x14c
	// Line 1411, Address: 0x215ce4, Func Offset: 0x154
	// Line 1412, Address: 0x215cec, Func Offset: 0x15c
	// Line 1413, Address: 0x215cf0, Func Offset: 0x160
	// Line 1416, Address: 0x215cf4, Func Offset: 0x164
	// Func End, Address: 0x215d04, Func Offset: 0x174
}

// 
// Start address: 0x215d10
void bhEne30_CollisionLine(BH_PWORK* epw)
{
	_anon27* hp;
	_anon3 n;
	// Line 1426, Address: 0x215d10, Func Offset: 0
	// Line 1430, Address: 0x215d20, Func Offset: 0x10
	// Line 1431, Address: 0x215d2c, Func Offset: 0x1c
	// Line 1432, Address: 0x215d48, Func Offset: 0x38
	// Line 1433, Address: 0x215d50, Func Offset: 0x40
	// Line 1434, Address: 0x215d58, Func Offset: 0x48
	// Line 1435, Address: 0x215d7c, Func Offset: 0x6c
	// Line 1458, Address: 0x215d90, Func Offset: 0x80
	// Func End, Address: 0x215da0, Func Offset: 0x90
}

// 
// Start address: 0x215da0
void bhEne30_SetFluidEffect(_anon3* pos, _anon3* vec, int type, float size)
{
	int eno;
	// Line 1470, Address: 0x215da0, Func Offset: 0
	// Line 1473, Address: 0x215dac, Func Offset: 0xc
	// Line 1474, Address: 0x215dbc, Func Offset: 0x1c
	// Line 1473, Address: 0x215dc0, Func Offset: 0x20
	// Line 1474, Address: 0x215dcc, Func Offset: 0x2c
	// Line 1484, Address: 0x215dd4, Func Offset: 0x34
	// Line 1474, Address: 0x215ddc, Func Offset: 0x3c
	// Line 1475, Address: 0x215de8, Func Offset: 0x48
	// Line 1476, Address: 0x215dfc, Func Offset: 0x5c
	// Line 1484, Address: 0x215e08, Func Offset: 0x68
	// Line 1476, Address: 0x215e0c, Func Offset: 0x6c
	// Line 1477, Address: 0x215e18, Func Offset: 0x78
	// Line 1478, Address: 0x215e30, Func Offset: 0x90
	// Line 1479, Address: 0x215e48, Func Offset: 0xa8
	// Line 1480, Address: 0x215e5c, Func Offset: 0xbc
	// Line 1481, Address: 0x215e70, Func Offset: 0xd0
	// Line 1484, Address: 0x215e84, Func Offset: 0xe4
	// Line 1485, Address: 0x215e9c, Func Offset: 0xfc
	// Line 1486, Address: 0x215ea8, Func Offset: 0x108
	// Line 1487, Address: 0x215ed0, Func Offset: 0x130
	// Line 1488, Address: 0x215ee4, Func Offset: 0x144
	// Line 1490, Address: 0x215ef8, Func Offset: 0x158
	// Func End, Address: 0x215f08, Func Offset: 0x168
}

