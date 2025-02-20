typedef struct BH_PWORK;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct npobj;
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

typedef void(*type_19)(BH_PWORK*);
typedef void(*type_36)(BH_PWORK*);
typedef void(*type_50)(BH_PWORK*);
typedef void(*type_65)(BH_PWORK*);
typedef void(*type_75)(BH_PWORK*);
typedef void(*type_82)(void*);

typedef _anon20 type_0[32];
typedef _anon0* type_1[512];
typedef _anon0* type_2[128];
typedef _anon0* type_3[128];
typedef _anon0* type_4[128];
typedef _anon0* type_5[512];
typedef _anon0* type_6[512];
typedef unsigned char type_7[64];
typedef float type_8[16];
typedef _anon0* type_9[512];
typedef unsigned int type_10[4];
typedef _anon0* type_11[32];
typedef _anon0* type_12[512];
typedef BH_PWORK type_13[0];
typedef _anon6* type_14[16];
typedef _anon0* type_15[32];
typedef _anon0* type_16[512];
typedef _anon6* type_17[16][16];
typedef _anon6* type_18[16][16][100];
typedef char type_20[8];
typedef void(*type_21)(BH_PWORK*)[1];
typedef _anon0* type_22[32];
typedef _anon0* type_23[512];
typedef _anon6* type_24[1300];
typedef _anon0* type_25[512];
typedef char type_26[32];
typedef _anon6* type_27[200];
typedef short type_28[32];
typedef _anon14 type_29[1];
typedef unsigned int type_30[1];
typedef _anon6* type_31[8];
typedef int* type_32[16];
typedef _anon5 type_33[256];
typedef npobj* type_34[16];
typedef _anon6* type_35[16];
typedef int type_37[4];
typedef void(*type_38)(BH_PWORK*)[1];
typedef _anon10 type_39[16];
typedef unsigned int type_40[4];
typedef char type_41[256];
typedef float type_42[4];
typedef float type_43[4];
typedef _anon8* type_44[128];
typedef float type_45[4];
typedef unsigned char type_46[64];
typedef char type_47[8];
typedef void* type_48[2];
typedef _anon6* type_49[256];
typedef void(*type_51)(BH_PWORK*)[6];
typedef unsigned char* type_52[256];
typedef int type_53[4];
typedef unsigned int type_54[2];
typedef short type_55[256];
typedef float type_56[3];
typedef _anon21 type_57[4];
typedef short type_58[256];
typedef int type_59[3];
typedef int type_60[8];
typedef float type_61[3];
typedef _anon6* type_62[256];
typedef _anon9 type_63[256];
typedef _anon14 type_64[450];
typedef void(*type_66)(BH_PWORK*)[1];
typedef _anon18 type_67[16];
typedef short type_68[256];
typedef int type_69[64];
typedef _anon10 type_70[450];
typedef char type_71[3];
typedef _anon25 type_72[4];
typedef _anon2 type_73[4];
typedef int type_74[450];
typedef void(*type_76)(BH_PWORK*)[1];
typedef unsigned int type_77[8];
typedef unsigned char type_78[450];
typedef char type_79[16];
typedef char type_80[4];
typedef unsigned int type_81[3];
typedef unsigned int type_83[32];
typedef unsigned int type_84[16];
typedef unsigned int type_85[16];
typedef unsigned char type_86[2];
typedef _anon28 type_87[64];
typedef unsigned int type_88[32];
typedef char type_89[32];
typedef _anon28 type_90[64];
typedef unsigned int type_91[16];
typedef char type_92[64];
typedef _anon28 type_93[64];
typedef BH_PWORK* type_94[16];
typedef unsigned int type_95[8];
typedef unsigned int type_96[1];
typedef unsigned int type_97[384];
typedef unsigned int type_98[2];
typedef unsigned int type_99[4];
typedef int* type_100[16];
typedef npobj* type_101[16];
typedef _anon6* type_102[16];
typedef char type_103[4];
typedef _anon10 type_104[16];
typedef short type_105[4];
typedef unsigned char type_106[4];
typedef _anon24 type_107[16];
typedef unsigned int type_108[32];
typedef _anon0* type_109[128];

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
	_anon6* txp[16];
	_anon10 mdl[16];
	_anon10* mlwP;
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
	_anon32 watr;
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
	_anon6* txp[16];
	_anon10 mdl[16];
	_anon10* mlwP;
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

struct _anon1
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
	_anon20 ply_pos;
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
	_anon6* et_lp[16][16][100];
	_anon6* ot_lp[1300];
	_anon6* it_lp[200];
	int eft_n;
	_anon6* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon11* p1per;
	_anon11* p2per;
	_anon11* kbper;
	_anon11* msper;
	_anon11 ms_per;
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
	_anon6* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon6* txblp[256];
	_anon9 txbp[256];
	unsigned char* ef_psp;
	_anon14 ef_tex[450];
	_anon6 ef_tlist;
	_anon27 ef;
	short efid[256];
	_anon10 efm[450];
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
	_anon14 ren_tex[1];
	_anon6 ren_tlist;
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
	_anon26 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon3* lgtp;
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
	_anon18 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon28* pl_htp;
	int costume;
	_anon20 hd_pos;
	_anon20 apos;
	_anon28* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon28 mwalp[64];
	_anon28 metcp[64];
	_anon28 mflrp[64];
	int dla_n;
	_anon28* htp;
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
	_anon6* sb_tlist;
	int ddmd;
	_anon12 door;
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
	_anon20 ufo_pos;
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
	_anon24 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon20 ghtp[32];
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

struct _anon4
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

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
	_anon14* textures;
	unsigned int nbTexture;
};

struct _anon7
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

struct _anon8
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon16* md2P;
	unsigned short* atrP;
};

struct _anon9
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon10
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon6* texP;
	_anon4* owP;
};

struct _anon11
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

struct _anon12
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

struct _anon13
{
	void* texaddr;
	_anon7 texsurface;
};

struct _anon14
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon15
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon16
{
	void* p[2];
};

struct _anon17
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon18
{
	float x;
	float y;
};

struct _anon19
{
	float mtrx[16];
	_anon20 pnt;
	_anon20 vctr;
	int stat;
	int reserve;
	_anon23 ltcal;
	_anon30 attr;
};

struct _anon20
{
	float x;
	float y;
	float z;
};

struct _anon21
{
	_anon20 ps;
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
	_anon20 center;
	float r;
};

struct _anon23
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
	_anon20 lpnt;
	_anon20 lvctr;
	_anon20 lmvctr;
	_anon15 atten;
	_anon15 amb;
	_anon15 dif;
	_anon15 spc;
	_anon15 mamb;
	_anon15 mdif;
	_anon15 mspc;
};

struct _anon24
{
	_anon20 c1;
	_anon20 c2;
	float r1;
	float r2;
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
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon27
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

struct _anon28
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
	_anon15 argb;
};

struct _anon31
{
	_anon20 c;
	float r;
};

struct _anon32
{
	_anon20 c1;
	_anon20 c2;
	float r;
};

void(*bhEne54_Mode0)(BH_PWORK*)[6];
void(*bhEne54_MoveType)(BH_PWORK*)[1];
void(*bhEne54_MoveMode2)(BH_PWORK*)[1];
void(*bhEne54_DamageType)(BH_PWORK*)[1];
void(*bhEne54_DamageMode2)(BH_PWORK*)[1];
_anon1* sys;
BH_PWORK ene[0];

void bhEne54(BH_PWORK* epw);
void bhEne54_MainLoop(BH_PWORK* epw);
int bhEne54_SetMtn(BH_PWORK* epw);
void bhEne54_CollCheck(BH_PWORK* epw);
void bhEne54_CalcEnemy(BH_PWORK* epw);
void bhEne54_Init(BH_PWORK* epw);
void bhEne54_Move(BH_PWORK* epw);
void bhEne54_Damage(BH_PWORK* epw);
void bhEne54_MVType00(BH_PWORK* epw);
void bhEne54_MV00(BH_PWORK* epw);
void bhEne54_DGType00(BH_PWORK* epw);
void bhEne54_DG00(BH_PWORK* epw);

// 
// Start address: 0x21aed0
void bhEne54(BH_PWORK* epw)
{
	int i;
	// Line 154, Address: 0x21aed0, Func Offset: 0
	// Line 158, Address: 0x21aedc, Func Offset: 0xc
	// Line 161, Address: 0x21aee4, Func Offset: 0x14
	// Line 163, Address: 0x21aef4, Func Offset: 0x24
	// Line 164, Address: 0x21af18, Func Offset: 0x48
	// Line 168, Address: 0x21af28, Func Offset: 0x58
	// Line 171, Address: 0x21af34, Func Offset: 0x64
	// Line 173, Address: 0x21af3c, Func Offset: 0x6c
	// Func End, Address: 0x21af4c, Func Offset: 0x7c
}

// 
// Start address: 0x21af50
void bhEne54_MainLoop(BH_PWORK* epw)
{
	// Line 193, Address: 0x21af50, Func Offset: 0
	// Line 197, Address: 0x21af60, Func Offset: 0x10
	// Line 200, Address: 0x21af80, Func Offset: 0x30
	// Line 210, Address: 0x21af88, Func Offset: 0x38
	// Func End, Address: 0x21af98, Func Offset: 0x48
}

// 
// Start address: 0x21afa0
int bhEne54_SetMtn(BH_PWORK* epw)
{
	int ret;
	// Line 226, Address: 0x21afa0, Func Offset: 0
	// Line 232, Address: 0x21afb0, Func Offset: 0x10
	// Line 235, Address: 0x21afc0, Func Offset: 0x20
	// Line 236, Address: 0x21afc8, Func Offset: 0x28
	// Line 238, Address: 0x21afdc, Func Offset: 0x3c
	// Line 241, Address: 0x21aff0, Func Offset: 0x50
	// Func End, Address: 0x21b000, Func Offset: 0x60
}

// 
// Start address: 0x21b000
void bhEne54_CollCheck(BH_PWORK* epw)
{
	int i;
	_anon20 ps;
	_anon31 at;
	_anon4* owk;
	BH_PWORK* epp;
	// Line 260, Address: 0x21b000, Func Offset: 0
	// Line 267, Address: 0x21b010, Func Offset: 0x10
	// Line 270, Address: 0x21b040, Func Offset: 0x40
	// Line 273, Address: 0x21b058, Func Offset: 0x58
	// Line 276, Address: 0x21b05c, Func Offset: 0x5c
	// Line 277, Address: 0x21b060, Func Offset: 0x60
	// Line 273, Address: 0x21b068, Func Offset: 0x68
	// Line 274, Address: 0x21b074, Func Offset: 0x74
	// Line 275, Address: 0x21b078, Func Offset: 0x78
	// Line 277, Address: 0x21b07c, Func Offset: 0x7c
	// Line 278, Address: 0x21b088, Func Offset: 0x88
	// Line 279, Address: 0x21b08c, Func Offset: 0x8c
	// Line 281, Address: 0x21b0a4, Func Offset: 0xa4
	// Line 282, Address: 0x21b0ac, Func Offset: 0xac
	// Line 281, Address: 0x21b0b0, Func Offset: 0xb0
	// Line 282, Address: 0x21b0bc, Func Offset: 0xbc
	// Line 283, Address: 0x21b0c0, Func Offset: 0xc0
	// Line 284, Address: 0x21b0c4, Func Offset: 0xc4
	// Line 287, Address: 0x21b0c8, Func Offset: 0xc8
	// Line 289, Address: 0x21b0d0, Func Offset: 0xd0
	// Line 290, Address: 0x21b0e8, Func Offset: 0xe8
	// Func End, Address: 0x21b0fc, Func Offset: 0xfc
}

// 
// Start address: 0x21b100
void bhEne54_CalcEnemy(BH_PWORK* epw)
{
	_anon4* owk;
	// Line 307, Address: 0x21b100, Func Offset: 0
	// Line 311, Address: 0x21b10c, Func Offset: 0xc
	// Line 314, Address: 0x21b114, Func Offset: 0x14
	// Line 315, Address: 0x21b118, Func Offset: 0x18
	// Line 326, Address: 0x21b11c, Func Offset: 0x1c
	// Line 314, Address: 0x21b120, Func Offset: 0x20
	// Line 315, Address: 0x21b124, Func Offset: 0x24
	// Line 318, Address: 0x21b134, Func Offset: 0x34
	// Line 319, Address: 0x21b13c, Func Offset: 0x3c
	// Line 320, Address: 0x21b144, Func Offset: 0x44
	// Line 321, Address: 0x21b14c, Func Offset: 0x4c
	// Line 322, Address: 0x21b154, Func Offset: 0x54
	// Line 323, Address: 0x21b15c, Func Offset: 0x5c
	// Line 324, Address: 0x21b164, Func Offset: 0x64
	// Line 325, Address: 0x21b16c, Func Offset: 0x6c
	// Line 326, Address: 0x21b174, Func Offset: 0x74
	// Line 327, Address: 0x21b178, Func Offset: 0x78
	// Func End, Address: 0x21b188, Func Offset: 0x88
}

// 
// Start address: 0x21b190
void bhEne54_Init(BH_PWORK* epw)
{
	int i;
	// Line 347, Address: 0x21b190, Func Offset: 0
	// Line 348, Address: 0x21b198, Func Offset: 0x8
	// Line 349, Address: 0x21b1a0, Func Offset: 0x10
	// Line 350, Address: 0x21b1a4, Func Offset: 0x14
	// Line 351, Address: 0x21b1a8, Func Offset: 0x18
	// Line 352, Address: 0x21b1ac, Func Offset: 0x1c
	// Line 353, Address: 0x21b1b0, Func Offset: 0x20
	// Line 354, Address: 0x21b1b8, Func Offset: 0x28
	// Line 355, Address: 0x21b1bc, Func Offset: 0x2c
	// Line 358, Address: 0x21b1e0, Func Offset: 0x50
	// Line 359, Address: 0x21b1e4, Func Offset: 0x54
	// Line 360, Address: 0x21b1e8, Func Offset: 0x58
	// Line 361, Address: 0x21b1ec, Func Offset: 0x5c
	// Line 362, Address: 0x21b1f0, Func Offset: 0x60
	// Line 363, Address: 0x21b1f4, Func Offset: 0x64
	// Line 364, Address: 0x21b1f8, Func Offset: 0x68
	// Line 368, Address: 0x21b1fc, Func Offset: 0x6c
	// Line 369, Address: 0x21b200, Func Offset: 0x70
	// Line 372, Address: 0x21b204, Func Offset: 0x74
	// Line 375, Address: 0x21b208, Func Offset: 0x78
	// Line 368, Address: 0x21b20c, Func Offset: 0x7c
	// Line 369, Address: 0x21b214, Func Offset: 0x84
	// Line 372, Address: 0x21b220, Func Offset: 0x90
	// Line 373, Address: 0x21b224, Func Offset: 0x94
	// Line 375, Address: 0x21b230, Func Offset: 0xa0
	// Line 376, Address: 0x21b234, Func Offset: 0xa4
	// Line 377, Address: 0x21b238, Func Offset: 0xa8
	// Line 379, Address: 0x21b23c, Func Offset: 0xac
	// Func End, Address: 0x21b244, Func Offset: 0xb4
}

// 
// Start address: 0x21b250
void bhEne54_Move(BH_PWORK* epw)
{
	// Line 399, Address: 0x21b250, Func Offset: 0
	// Func End, Address: 0x21b270, Func Offset: 0x20
}

// 
// Start address: 0x21b270
void bhEne54_Damage(BH_PWORK* epw)
{
	// Line 418, Address: 0x21b270, Func Offset: 0
	// Func End, Address: 0x21b290, Func Offset: 0x20
}

// 
// Start address: 0x21b290
void bhEne54_MVType00(BH_PWORK* epw)
{
	// Line 438, Address: 0x21b290, Func Offset: 0
	// Func End, Address: 0x21b2b0, Func Offset: 0x20
}

// 
// Start address: 0x21b2b0
void bhEne54_MV00(BH_PWORK* epw)
{
	// Line 459, Address: 0x21b2b0, Func Offset: 0
	// Line 460, Address: 0x21b2bc, Func Offset: 0xc
	// Line 463, Address: 0x21b2dc, Func Offset: 0x2c
	// Line 464, Address: 0x21b2ec, Func Offset: 0x3c
	// Line 465, Address: 0x21b2f0, Func Offset: 0x40
	// Line 470, Address: 0x21b2fc, Func Offset: 0x4c
	// Func End, Address: 0x21b30c, Func Offset: 0x5c
}

// 
// Start address: 0x21b310
void bhEne54_DGType00(BH_PWORK* epw)
{
	// Line 489, Address: 0x21b310, Func Offset: 0
	// Func End, Address: 0x21b330, Func Offset: 0x20
}

// 
// Start address: 0x21b330
void bhEne54_DG00(BH_PWORK* epw)
{
	// Line 510, Address: 0x21b330, Func Offset: 0
	// Line 511, Address: 0x21b33c, Func Offset: 0xc
	// Line 514, Address: 0x21b368, Func Offset: 0x38
	// Line 516, Address: 0x21b388, Func Offset: 0x58
	// Line 517, Address: 0x21b394, Func Offset: 0x64
	// Line 520, Address: 0x21b39c, Func Offset: 0x6c
	// Line 522, Address: 0x21b3ac, Func Offset: 0x7c
	// Line 525, Address: 0x21b3b8, Func Offset: 0x88
	// Line 527, Address: 0x21b3e8, Func Offset: 0xb8
	// Line 528, Address: 0x21b3ec, Func Offset: 0xbc
	// Line 535, Address: 0x21b3f8, Func Offset: 0xc8
	// Func End, Address: 0x21b408, Func Offset: 0xd8
}

