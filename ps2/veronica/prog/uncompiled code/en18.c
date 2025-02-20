typedef struct npobj;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct BH_PWORK;
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

typedef void(*type_31)(BH_PWORK*);
typedef void(*type_86)(void*);
typedef void(*type_125)(BH_PWORK*);

typedef unsigned int type_0[4];
typedef _anon1* type_1[512];
typedef _anon1* type_2[32];
typedef _anon2* type_3[16];
typedef _anon1* type_4[32];
typedef _anon1* type_5[512];
typedef _anon2* type_6[16][16];
typedef _anon2* type_7[16][16][100];
typedef char type_8[8];
typedef _anon1* type_9[32];
typedef _anon1* type_10[512];
typedef _anon2* type_11[1300];
typedef char type_12[32];
typedef _anon1* type_13[512];
typedef _anon2* type_14[200];
typedef short type_15[32];
typedef _anon15 type_16[1];
typedef _anon1* type_17[128];
typedef unsigned int type_18[1];
typedef _anon6 type_19[256];
typedef _anon2* type_20[8];
typedef int type_21[10];
typedef int* type_22[16];
typedef _anon1* type_23[128];
typedef _anon27 type_24[11];
typedef char type_25[3];
typedef npobj* type_26[16];
typedef _anon3 type_27[5];
typedef _anon1* type_28[128];
typedef int type_29[4];
typedef _anon2* type_30[16];
typedef char type_32[3];
typedef void(*type_33)(BH_PWORK*)[6];
typedef unsigned int type_34[4];
typedef _anon10 type_35[16];
typedef _anon1* type_36[512];
typedef char type_37[256];
typedef float type_38[4];
typedef _anon7 type_39[21];
typedef float type_40[4];
typedef float type_41[4];
typedef _anon5* type_42[128];
typedef unsigned char type_43[64];
typedef float type_44[16];
typedef _anon3 type_45[5];
typedef _anon25 type_46[3];
typedef _anon27 type_47[15];
typedef char type_48[8];
typedef _anon25 type_49[3];
typedef void* type_50[2];
typedef _anon3 type_51[5];
typedef _anon2* type_52[256];
typedef _anon3 type_53[5];
typedef int type_54[4];
typedef unsigned char* type_55[256];
typedef _anon3 type_56[1];
typedef _anon27 type_57[11];
typedef unsigned int type_58[2];
typedef short type_59[256];
typedef _anon22 type_60[4];
typedef float type_61[3];
typedef short type_62[256];
typedef int type_63[3];
typedef int type_64[8];
typedef float type_65[3];
typedef _anon2* type_66[256];
typedef _anon9 type_67[256];
typedef _anon15 type_68[450];
typedef _anon3 type_69[7];
typedef _anon16 type_70[31];
typedef _anon24 type_71[16];
typedef short type_72[256];
typedef char type_73[3];
typedef int type_74[64];
typedef _anon10 type_75[450];
typedef _anon37 type_76[21];
typedef _anon30 type_77[4];
typedef _anon4 type_78[4];
typedef int type_79[450];
typedef unsigned int type_80[8];
typedef unsigned char type_81[450];
typedef _anon3 type_82[7];
typedef _anon27 type_83[5];
typedef char type_84[16];
typedef char type_85[4];
typedef unsigned int type_87[32];
typedef unsigned char type_88[56];
typedef unsigned int type_89[16];
typedef _anon3 type_90[8];
typedef _anon32 type_91[64];
typedef unsigned int type_92[16];
typedef _anon27 type_93[11];
typedef _anon32 type_94[64];
typedef unsigned int type_95[32];
typedef _anon0 type_96[14];
typedef _anon3 type_97[7];
typedef _anon32 type_98[64];
typedef unsigned int type_99[16];
typedef unsigned int type_100[3];
typedef BH_PWORK* type_101[16];
typedef unsigned int type_102[8];
typedef unsigned int type_103[1];
typedef unsigned int type_104[384];
typedef unsigned int type_105[2];
typedef int type_106[3];
typedef unsigned char type_107[2];
typedef unsigned int type_108[4];
typedef int* type_109[16];
typedef char type_110[32];
typedef npobj* type_111[16];
typedef char type_112[64];
typedef _anon25 type_113[3];
typedef _anon2* type_114[16];
typedef char type_115[4];
typedef _anon10 type_116[16];
typedef short type_117[4];
typedef _anon3 type_118[6];
typedef unsigned char type_119[4];
typedef _anon28 type_120[16];
typedef _anon27 type_121[13];
typedef unsigned int type_122[32];
typedef _anon25 type_123[32];
typedef _anon1* type_124[512];
typedef void(*type_126)(BH_PWORK*)[6];
typedef _anon40 type_127[14];
typedef _anon1* type_128[128];
typedef _anon1* type_129[512];
typedef _anon3 type_130[6];
typedef unsigned char type_131[64];
typedef _anon1* type_132[512];
typedef _anon27 type_133[11];

struct npobj
{
	unsigned int evalflags;
	_anon23* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon0
{
	int flg;
	_anon3* effoff;
	int num;
};

struct _anon1
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
	_anon5* mnwP;
	_anon5* mnwPb;
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
	_anon30* pvp;
	_anon4* tvp;
	_anon30 pv[4];
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

struct _anon2
{
	_anon15* textures;
	unsigned int nbTexture;
};

struct _anon3
{
	_anon25 ofp;
	float rx;
	float ry;
	float rz;
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
	_anon5* mnwP;
	_anon5* mnwPb;
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

struct _anon5
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon14* md2P;
	unsigned short* atrP;
};

struct _anon6
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon7
{
	char type[3];
	char bloodstain[3];
	char exef;
};

struct _anon8
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
	_anon2* texP;
	_anon20* owP;
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
	_anon35* info;
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
	_anon8 texsurface;
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
	_anon21* light;
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
	_anon1* obwp;
	_anon1* itwp;
	_anon5* emtp[128];
	_anon5* rmthp;
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
	_anon9 txbp[256];
	unsigned char* ef_psp;
	_anon15 ef_tex[450];
	_anon2 ef_tlist;
	_anon31 ef;
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
	_anon1* ef_pol[512];
	_anon1* ef_mdf[128];
	_anon1* ef_lin[512];
	_anon1* ef_ntx[512];
	_anon1* ef_trs[512];
	_anon1* ef_pnc[512];
	_anon1* ef_opq[512];
	_anon1* ef_thl[512];
	_anon1* ef_ntx2d[128];
	_anon1* ef_trs2d[128];
	_anon1* ef_pnc2d[128];
	_anon1* ef_fnc[512];
	int ob_nlgn;
	int ob_hlgn;
	int ob_spcn;
	_anon1* ob_nlg[32];
	_anon1* ob_hlg[32];
	_anon1* ob_spc[32];
	unsigned int ren_gid;
	_anon13 ren_info;
	_anon15 ren_tex[1];
	_anon2 ren_tlist;
	_anon6 rpb[256];
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
	_anon17* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon22 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon24 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon32* pl_htp;
	int costume;
	_anon25 hd_pos;
	_anon25 apos;
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
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon21
{
	float mtrx[16];
	_anon25 pnt;
	_anon25 vctr;
	int stat;
	int reserve;
	_anon29 ltcal;
	_anon36 attr;
};

struct _anon22
{
	_anon25 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon23
{
	int* vlist;
	short* plist;
	_anon25 center;
	float r;
};

struct _anon24
{
	float x;
	float y;
};

struct _anon25
{
	float x;
	float y;
	float z;
};

struct _anon26
{
	float x;
	float y;
	float z;
	float w;
};

struct _anon27
{
	int key;
	float cnt;
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
	unsigned char ucType;
	unsigned char ucAttr;
	unsigned short usSize;
	unsigned short usIndexOfs;
	unsigned short usIndexMax;
	unsigned char ucPadding[56];
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

struct _anon36
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

struct _anon37
{
	int crit;
	int pt[3];
	int timeout;
	int bonus;
};

struct _anon38
{
	_anon25 c;
	float r;
};

struct _anon39
{
	_anon25 c1;
	_anon25 c2;
	float r;
};

struct _anon40
{
	int flg;
	int correct;
};

_anon7 DmgReact[21];
_anon37 CombWepTbl[21];
_anon40 CombJointTbl[14];
_anon3 ENE18_EO_00[1];
_anon3 ENE18_EO_04[7];
_anon3 ENE18_EO_05[5];
_anon3 ENE18_EO_06[7];
_anon3 ENE18_EO_07[6];
_anon3 ENE18_EO_08[5];
_anon3 ENE18_EO_09[7];
_anon3 ENE18_EO_10[6];
_anon3 ENE18_EO_11[5];
_anon3 ENE18_EO_12[8];
_anon3 ENE18_EO_13[5];
_anon0 BloodTbl[14];
_anon16 CapColTab[31];
_anon27 HeartBeat[13];
_anon27 SpawnAttacker[15];
_anon27 Broken[5];
_anon27 Tentacle[11];
_anon27 Tentacle2[11];
_anon27 Tentacle3[11];
_anon27 Tentacle4[11];
void(*bhEne18_Mode0)(BH_PWORK*)[6];
void(*bhEne18_MoveMode2)(BH_PWORK*)[6];
_anon18* sys;

void bhEne18(BH_PWORK* epw);
void bhEne18_Init(BH_PWORK* epw);
void bhEne18_Move(BH_PWORK* epw);
void bhEne18_MV00(BH_PWORK* epw);
void bhEne18_MV01(BH_PWORK* epw);
void bhEne18_MV02(BH_PWORK* epw);
void bhEne18_MV03();
void bhEne18_MV04(BH_PWORK* epw);
void bhEne18_MV05(BH_PWORK* epw);
void bhEne18_Nage();
void bhEne18_Damage();
void bhEne18_Die(BH_PWORK* epw);
int bhEne18_HitMark(BH_PWORK* epw);

// 
// Start address: 0x1eec00
void bhEne18(BH_PWORK* epw)
{
	// Line 476, Address: 0x1eec00, Func Offset: 0
	// Line 478, Address: 0x1eec10, Func Offset: 0x10
	// Line 481, Address: 0x1eec30, Func Offset: 0x30
	// Line 482, Address: 0x1eec48, Func Offset: 0x48
	// Line 483, Address: 0x1eec54, Func Offset: 0x54
	// Line 487, Address: 0x1eec60, Func Offset: 0x60
	// Line 488, Address: 0x1eec6c, Func Offset: 0x6c
	// Func End, Address: 0x1eec7c, Func Offset: 0x7c
}

// 
// Start address: 0x1eec80
void bhEne18_Init(BH_PWORK* epw)
{
	int InitAction[10];
	_anon25 vec;
	BH_PWORK* ep;
	// Line 498, Address: 0x1eec80, Func Offset: 0
	// Line 501, Address: 0x1eec94, Func Offset: 0x14
	// Line 498, Address: 0x1eec9c, Func Offset: 0x1c
	// Line 501, Address: 0x1eeca0, Func Offset: 0x20
	// Line 515, Address: 0x1eecc0, Func Offset: 0x40
	// Line 516, Address: 0x1eecc4, Func Offset: 0x44
	// Line 518, Address: 0x1eece4, Func Offset: 0x64
	// Line 522, Address: 0x1eecec, Func Offset: 0x6c
	// Line 523, Address: 0x1eecf0, Func Offset: 0x70
	// Line 525, Address: 0x1eecf4, Func Offset: 0x74
	// Line 526, Address: 0x1eecf8, Func Offset: 0x78
	// Line 527, Address: 0x1eecfc, Func Offset: 0x7c
	// Line 522, Address: 0x1eed00, Func Offset: 0x80
	// Line 523, Address: 0x1eed08, Func Offset: 0x88
	// Line 530, Address: 0x1eed0c, Func Offset: 0x8c
	// Line 536, Address: 0x1eed10, Func Offset: 0x90
	// Line 523, Address: 0x1eed14, Func Offset: 0x94
	// Line 524, Address: 0x1eed1c, Func Offset: 0x9c
	// Line 525, Address: 0x1eed28, Func Offset: 0xa8
	// Line 526, Address: 0x1eed2c, Func Offset: 0xac
	// Line 527, Address: 0x1eed30, Func Offset: 0xb0
	// Line 530, Address: 0x1eed34, Func Offset: 0xb4
	// Line 531, Address: 0x1eed38, Func Offset: 0xb8
	// Line 532, Address: 0x1eed3c, Func Offset: 0xbc
	// Line 533, Address: 0x1eed50, Func Offset: 0xd0
	// Line 536, Address: 0x1eed54, Func Offset: 0xd4
	// Line 537, Address: 0x1eed58, Func Offset: 0xd8
	// Line 538, Address: 0x1eed5c, Func Offset: 0xdc
	// Line 539, Address: 0x1eed60, Func Offset: 0xe0
	// Line 540, Address: 0x1eed64, Func Offset: 0xe4
	// Line 544, Address: 0x1eed68, Func Offset: 0xe8
	// Line 547, Address: 0x1eedbc, Func Offset: 0x13c
	// Line 548, Address: 0x1eedc8, Func Offset: 0x148
	// Line 549, Address: 0x1eedd8, Func Offset: 0x158
	// Line 554, Address: 0x1eede0, Func Offset: 0x160
	// Line 557, Address: 0x1eede4, Func Offset: 0x164
	// Line 549, Address: 0x1eede8, Func Offset: 0x168
	// Line 550, Address: 0x1eedf0, Func Offset: 0x170
	// Line 551, Address: 0x1eee00, Func Offset: 0x180
	// Line 554, Address: 0x1eee10, Func Offset: 0x190
	// Line 555, Address: 0x1eee44, Func Offset: 0x1c4
	// Line 556, Address: 0x1eee68, Func Offset: 0x1e8
	// Line 557, Address: 0x1eee74, Func Offset: 0x1f4
	// Line 558, Address: 0x1eee80, Func Offset: 0x200
	// Line 559, Address: 0x1eee8c, Func Offset: 0x20c
	// Line 560, Address: 0x1eee98, Func Offset: 0x218
	// Line 561, Address: 0x1eeea4, Func Offset: 0x224
	// Line 564, Address: 0x1eeeb0, Func Offset: 0x230
	// Line 565, Address: 0x1eeec0, Func Offset: 0x240
	// Line 566, Address: 0x1eeecc, Func Offset: 0x24c
	// Line 569, Address: 0x1eeed8, Func Offset: 0x258
	// Line 572, Address: 0x1eef08, Func Offset: 0x288
	// Line 573, Address: 0x1eef0c, Func Offset: 0x28c
	// Line 578, Address: 0x1eef14, Func Offset: 0x294
	// Line 576, Address: 0x1eef18, Func Offset: 0x298
	// Line 572, Address: 0x1eef20, Func Offset: 0x2a0
	// Line 573, Address: 0x1eef24, Func Offset: 0x2a4
	// Line 581, Address: 0x1eef28, Func Offset: 0x2a8
	// Line 573, Address: 0x1eef30, Func Offset: 0x2b0
	// Line 574, Address: 0x1eef38, Func Offset: 0x2b8
	// Line 575, Address: 0x1eef40, Func Offset: 0x2c0
	// Line 576, Address: 0x1eef48, Func Offset: 0x2c8
	// Line 577, Address: 0x1eef54, Func Offset: 0x2d4
	// Line 578, Address: 0x1eef5c, Func Offset: 0x2dc
	// Line 582, Address: 0x1eef60, Func Offset: 0x2e0
	// Line 585, Address: 0x1eef68, Func Offset: 0x2e8
	// Line 586, Address: 0x1eef70, Func Offset: 0x2f0
	// Line 587, Address: 0x1eef7c, Func Offset: 0x2fc
	// Line 589, Address: 0x1eef88, Func Offset: 0x308
	// Line 590, Address: 0x1eef90, Func Offset: 0x310
	// Line 591, Address: 0x1eef9c, Func Offset: 0x31c
	// Line 593, Address: 0x1eefac, Func Offset: 0x32c
	// Line 597, Address: 0x1eefb4, Func Offset: 0x334
	// Line 598, Address: 0x1eefb8, Func Offset: 0x338
	// Line 599, Address: 0x1eefbc, Func Offset: 0x33c
	// Line 601, Address: 0x1eefc0, Func Offset: 0x340
	// Line 593, Address: 0x1eefc4, Func Offset: 0x344
	// Line 594, Address: 0x1eefcc, Func Offset: 0x34c
	// Line 595, Address: 0x1eefdc, Func Offset: 0x35c
	// Line 597, Address: 0x1eefec, Func Offset: 0x36c
	// Line 598, Address: 0x1eeff0, Func Offset: 0x370
	// Line 601, Address: 0x1eeff4, Func Offset: 0x374
	// Line 602, Address: 0x1eeffc, Func Offset: 0x37c
	// Line 603, Address: 0x1ef008, Func Offset: 0x388
	// Line 605, Address: 0x1ef018, Func Offset: 0x398
	// Line 609, Address: 0x1ef020, Func Offset: 0x3a0
	// Line 605, Address: 0x1ef024, Func Offset: 0x3a4
	// Line 606, Address: 0x1ef02c, Func Offset: 0x3ac
	// Line 607, Address: 0x1ef03c, Func Offset: 0x3bc
	// Line 609, Address: 0x1ef04c, Func Offset: 0x3cc
	// Line 611, Address: 0x1ef050, Func Offset: 0x3d0
	// Line 612, Address: 0x1ef058, Func Offset: 0x3d8
	// Line 615, Address: 0x1ef060, Func Offset: 0x3e0
	// Line 616, Address: 0x1ef068, Func Offset: 0x3e8
	// Line 617, Address: 0x1ef070, Func Offset: 0x3f0
	// Line 616, Address: 0x1ef074, Func Offset: 0x3f4
	// Line 619, Address: 0x1ef078, Func Offset: 0x3f8
	// Line 620, Address: 0x1ef084, Func Offset: 0x404
	// Line 621, Address: 0x1ef090, Func Offset: 0x410
	// Line 623, Address: 0x1ef0a0, Func Offset: 0x420
	// Line 627, Address: 0x1ef0a8, Func Offset: 0x428
	// Line 628, Address: 0x1ef0ac, Func Offset: 0x42c
	// Line 629, Address: 0x1ef0b0, Func Offset: 0x430
	// Line 631, Address: 0x1ef0b4, Func Offset: 0x434
	// Line 623, Address: 0x1ef0b8, Func Offset: 0x438
	// Line 624, Address: 0x1ef0c0, Func Offset: 0x440
	// Line 625, Address: 0x1ef0d0, Func Offset: 0x450
	// Line 627, Address: 0x1ef0e0, Func Offset: 0x460
	// Line 628, Address: 0x1ef0e4, Func Offset: 0x464
	// Line 631, Address: 0x1ef0e8, Func Offset: 0x468
	// Line 632, Address: 0x1ef0f0, Func Offset: 0x470
	// Line 633, Address: 0x1ef0fc, Func Offset: 0x47c
	// Line 635, Address: 0x1ef10c, Func Offset: 0x48c
	// Line 639, Address: 0x1ef114, Func Offset: 0x494
	// Line 635, Address: 0x1ef118, Func Offset: 0x498
	// Line 636, Address: 0x1ef120, Func Offset: 0x4a0
	// Line 637, Address: 0x1ef130, Func Offset: 0x4b0
	// Line 639, Address: 0x1ef140, Func Offset: 0x4c0
	// Line 641, Address: 0x1ef144, Func Offset: 0x4c4
	// Line 642, Address: 0x1ef14c, Func Offset: 0x4cc
	// Line 646, Address: 0x1ef154, Func Offset: 0x4d4
	// Line 645, Address: 0x1ef158, Func Offset: 0x4d8
	// Line 646, Address: 0x1ef15c, Func Offset: 0x4dc
	// Line 647, Address: 0x1ef164, Func Offset: 0x4e4
	// Line 649, Address: 0x1ef170, Func Offset: 0x4f0
	// Line 650, Address: 0x1ef178, Func Offset: 0x4f8
	// Line 651, Address: 0x1ef184, Func Offset: 0x504
	// Line 653, Address: 0x1ef194, Func Offset: 0x514
	// Line 659, Address: 0x1ef19c, Func Offset: 0x51c
	// Line 661, Address: 0x1ef1a0, Func Offset: 0x520
	// Line 653, Address: 0x1ef1a4, Func Offset: 0x524
	// Line 654, Address: 0x1ef1ac, Func Offset: 0x52c
	// Line 655, Address: 0x1ef1bc, Func Offset: 0x53c
	// Line 657, Address: 0x1ef1cc, Func Offset: 0x54c
	// Line 658, Address: 0x1ef1d0, Func Offset: 0x550
	// Line 661, Address: 0x1ef1d4, Func Offset: 0x554
	// Line 662, Address: 0x1ef1dc, Func Offset: 0x55c
	// Line 663, Address: 0x1ef1e8, Func Offset: 0x568
	// Line 665, Address: 0x1ef1f8, Func Offset: 0x578
	// Line 669, Address: 0x1ef200, Func Offset: 0x580
	// Line 665, Address: 0x1ef204, Func Offset: 0x584
	// Line 666, Address: 0x1ef20c, Func Offset: 0x58c
	// Line 667, Address: 0x1ef21c, Func Offset: 0x59c
	// Line 669, Address: 0x1ef22c, Func Offset: 0x5ac
	// Line 671, Address: 0x1ef230, Func Offset: 0x5b0
	// Line 672, Address: 0x1ef238, Func Offset: 0x5b8
	// Line 675, Address: 0x1ef240, Func Offset: 0x5c0
	// Line 676, Address: 0x1ef248, Func Offset: 0x5c8
	// Line 677, Address: 0x1ef254, Func Offset: 0x5d4
	// Line 679, Address: 0x1ef260, Func Offset: 0x5e0
	// Line 680, Address: 0x1ef268, Func Offset: 0x5e8
	// Line 681, Address: 0x1ef274, Func Offset: 0x5f4
	// Line 683, Address: 0x1ef284, Func Offset: 0x604
	// Line 687, Address: 0x1ef28c, Func Offset: 0x60c
	// Line 689, Address: 0x1ef290, Func Offset: 0x610
	// Line 691, Address: 0x1ef294, Func Offset: 0x614
	// Line 683, Address: 0x1ef298, Func Offset: 0x618
	// Line 684, Address: 0x1ef2a0, Func Offset: 0x620
	// Line 685, Address: 0x1ef2b0, Func Offset: 0x630
	// Line 687, Address: 0x1ef2c0, Func Offset: 0x640
	// Line 688, Address: 0x1ef2c4, Func Offset: 0x644
	// Line 691, Address: 0x1ef2c8, Func Offset: 0x648
	// Line 692, Address: 0x1ef2d0, Func Offset: 0x650
	// Line 693, Address: 0x1ef2dc, Func Offset: 0x65c
	// Line 695, Address: 0x1ef2ec, Func Offset: 0x66c
	// Line 699, Address: 0x1ef2f4, Func Offset: 0x674
	// Line 695, Address: 0x1ef2f8, Func Offset: 0x678
	// Line 696, Address: 0x1ef300, Func Offset: 0x680
	// Line 697, Address: 0x1ef310, Func Offset: 0x690
	// Line 699, Address: 0x1ef320, Func Offset: 0x6a0
	// Line 701, Address: 0x1ef324, Func Offset: 0x6a4
	// Line 702, Address: 0x1ef32c, Func Offset: 0x6ac
	// Line 705, Address: 0x1ef334, Func Offset: 0x6b4
	// Line 706, Address: 0x1ef33c, Func Offset: 0x6bc
	// Line 707, Address: 0x1ef348, Func Offset: 0x6c8
	// Line 709, Address: 0x1ef354, Func Offset: 0x6d4
	// Line 710, Address: 0x1ef35c, Func Offset: 0x6dc
	// Line 711, Address: 0x1ef368, Func Offset: 0x6e8
	// Line 713, Address: 0x1ef378, Func Offset: 0x6f8
	// Line 717, Address: 0x1ef380, Func Offset: 0x700
	// Line 719, Address: 0x1ef384, Func Offset: 0x704
	// Line 721, Address: 0x1ef388, Func Offset: 0x708
	// Line 713, Address: 0x1ef38c, Func Offset: 0x70c
	// Line 714, Address: 0x1ef394, Func Offset: 0x714
	// Line 715, Address: 0x1ef3a4, Func Offset: 0x724
	// Line 717, Address: 0x1ef3b4, Func Offset: 0x734
	// Line 718, Address: 0x1ef3b8, Func Offset: 0x738
	// Line 721, Address: 0x1ef3bc, Func Offset: 0x73c
	// Line 722, Address: 0x1ef3c4, Func Offset: 0x744
	// Line 723, Address: 0x1ef3d0, Func Offset: 0x750
	// Line 725, Address: 0x1ef3e0, Func Offset: 0x760
	// Line 729, Address: 0x1ef3e8, Func Offset: 0x768
	// Line 725, Address: 0x1ef3ec, Func Offset: 0x76c
	// Line 726, Address: 0x1ef3f4, Func Offset: 0x774
	// Line 727, Address: 0x1ef404, Func Offset: 0x784
	// Line 729, Address: 0x1ef414, Func Offset: 0x794
	// Line 731, Address: 0x1ef418, Func Offset: 0x798
	// Line 735, Address: 0x1ef424, Func Offset: 0x7a4
	// Func End, Address: 0x1ef440, Func Offset: 0x7c0
}

// 
// Start address: 0x1ef440
void bhEne18_Move(BH_PWORK* epw)
{
	// Line 758, Address: 0x1ef440, Func Offset: 0
	// Func End, Address: 0x1ef460, Func Offset: 0x20
}

// 
// Start address: 0x1ef460
void bhEne18_MV00(BH_PWORK* epw)
{
	// Line 770, Address: 0x1ef460, Func Offset: 0
	// Line 772, Address: 0x1ef474, Func Offset: 0x14
	// Line 774, Address: 0x1ef47c, Func Offset: 0x1c
	// Line 772, Address: 0x1ef480, Func Offset: 0x20
	// Line 773, Address: 0x1ef488, Func Offset: 0x28
	// Line 774, Address: 0x1ef48c, Func Offset: 0x2c
	// Line 775, Address: 0x1ef498, Func Offset: 0x38
	// Line 778, Address: 0x1ef4a4, Func Offset: 0x44
	// Func End, Address: 0x1ef4ac, Func Offset: 0x4c
}

// 
// Start address: 0x1ef4b0
void bhEne18_MV01(BH_PWORK* epw)
{
	// Line 788, Address: 0x1ef4b0, Func Offset: 0
	// Line 789, Address: 0x1ef4c0, Func Offset: 0x10
	// Line 791, Address: 0x1ef4e0, Func Offset: 0x30
	// Line 792, Address: 0x1ef4ec, Func Offset: 0x3c
	// Line 793, Address: 0x1ef4f0, Func Offset: 0x40
	// Line 795, Address: 0x1ef4fc, Func Offset: 0x4c
	// Line 796, Address: 0x1ef50c, Func Offset: 0x5c
	// Line 797, Address: 0x1ef528, Func Offset: 0x78
	// Line 798, Address: 0x1ef534, Func Offset: 0x84
	// Line 799, Address: 0x1ef53c, Func Offset: 0x8c
	// Line 800, Address: 0x1ef544, Func Offset: 0x94
	// Line 801, Address: 0x1ef550, Func Offset: 0xa0
	// Line 802, Address: 0x1ef55c, Func Offset: 0xac
	// Line 805, Address: 0x1ef568, Func Offset: 0xb8
	// Line 806, Address: 0x1ef574, Func Offset: 0xc4
	// Line 809, Address: 0x1ef588, Func Offset: 0xd8
	// Func End, Address: 0x1ef598, Func Offset: 0xe8
}

// 
// Start address: 0x1ef5a0
void bhEne18_MV02(BH_PWORK* epw)
{
	BH_PWORK* ep;
	_anon25 pos[3];
	// Line 819, Address: 0x1ef5a0, Func Offset: 0
	// Line 820, Address: 0x1ef5ac, Func Offset: 0xc
	// Line 819, Address: 0x1ef5b4, Func Offset: 0x14
	// Line 820, Address: 0x1ef5b8, Func Offset: 0x18
	// Line 827, Address: 0x1ef5d8, Func Offset: 0x38
	// Line 829, Address: 0x1ef5f8, Func Offset: 0x58
	// Line 830, Address: 0x1ef604, Func Offset: 0x64
	// Line 831, Address: 0x1ef608, Func Offset: 0x68
	// Line 835, Address: 0x1ef614, Func Offset: 0x74
	// Line 834, Address: 0x1ef618, Func Offset: 0x78
	// Line 835, Address: 0x1ef61c, Func Offset: 0x7c
	// Line 836, Address: 0x1ef620, Func Offset: 0x80
	// Line 835, Address: 0x1ef624, Func Offset: 0x84
	// Line 836, Address: 0x1ef628, Func Offset: 0x88
	// Line 837, Address: 0x1ef630, Func Offset: 0x90
	// Line 838, Address: 0x1ef63c, Func Offset: 0x9c
	// Line 839, Address: 0x1ef668, Func Offset: 0xc8
	// Line 841, Address: 0x1ef67c, Func Offset: 0xdc
	// Line 843, Address: 0x1ef688, Func Offset: 0xe8
	// Line 844, Address: 0x1ef698, Func Offset: 0xf8
	// Line 845, Address: 0x1ef6b4, Func Offset: 0x114
	// Line 848, Address: 0x1ef6b8, Func Offset: 0x118
	// Line 845, Address: 0x1ef6c0, Func Offset: 0x120
	// Line 846, Address: 0x1ef6c8, Func Offset: 0x128
	// Line 848, Address: 0x1ef6d4, Func Offset: 0x134
	// Line 849, Address: 0x1ef6f0, Func Offset: 0x150
	// Line 850, Address: 0x1ef714, Func Offset: 0x174
	// Line 854, Address: 0x1ef718, Func Offset: 0x178
	// Line 850, Address: 0x1ef71c, Func Offset: 0x17c
	// Line 851, Address: 0x1ef724, Func Offset: 0x184
	// Line 852, Address: 0x1ef730, Func Offset: 0x190
	// Line 854, Address: 0x1ef73c, Func Offset: 0x19c
	// Line 855, Address: 0x1ef744, Func Offset: 0x1a4
	// Line 858, Address: 0x1ef74c, Func Offset: 0x1ac
	// Line 856, Address: 0x1ef758, Func Offset: 0x1b8
	// Line 860, Address: 0x1ef75c, Func Offset: 0x1bc
	// Line 856, Address: 0x1ef764, Func Offset: 0x1c4
	// Line 857, Address: 0x1ef76c, Func Offset: 0x1cc
	// Line 858, Address: 0x1ef778, Func Offset: 0x1d8
	// Line 860, Address: 0x1ef784, Func Offset: 0x1e4
	// Line 863, Address: 0x1ef79c, Func Offset: 0x1fc
	// Line 866, Address: 0x1ef7a0, Func Offset: 0x200
	// Line 863, Address: 0x1ef7a4, Func Offset: 0x204
	// Line 866, Address: 0x1ef7ac, Func Offset: 0x20c
	// Line 867, Address: 0x1ef7b8, Func Offset: 0x218
	// Line 870, Address: 0x1ef7c4, Func Offset: 0x224
	// Line 871, Address: 0x1ef7d4, Func Offset: 0x234
	// Line 872, Address: 0x1ef7e4, Func Offset: 0x244
	// Line 875, Address: 0x1ef7e8, Func Offset: 0x248
	// Line 876, Address: 0x1ef7ec, Func Offset: 0x24c
	// Line 879, Address: 0x1ef7f0, Func Offset: 0x250
	// Line 883, Address: 0x1ef7fc, Func Offset: 0x25c
	// Func End, Address: 0x1ef810, Func Offset: 0x270
}

// 
// Start address: 0x1ef810
void bhEne18_MV03()
{
	// Line 924, Address: 0x1ef810, Func Offset: 0
	// Func End, Address: 0x1ef818, Func Offset: 0x8
}

// 
// Start address: 0x1ef820
void bhEne18_MV04(BH_PWORK* epw)
{
	BH_PWORK* ep;
	_anon25 pos[3];
	// Line 934, Address: 0x1ef820, Func Offset: 0
	// Line 935, Address: 0x1ef82c, Func Offset: 0xc
	// Line 934, Address: 0x1ef834, Func Offset: 0x14
	// Line 935, Address: 0x1ef838, Func Offset: 0x18
	// Line 942, Address: 0x1ef858, Func Offset: 0x38
	// Line 944, Address: 0x1ef878, Func Offset: 0x58
	// Line 945, Address: 0x1ef884, Func Offset: 0x64
	// Line 946, Address: 0x1ef888, Func Offset: 0x68
	// Line 947, Address: 0x1ef894, Func Offset: 0x74
	// Line 951, Address: 0x1ef8a0, Func Offset: 0x80
	// Line 950, Address: 0x1ef8a4, Func Offset: 0x84
	// Line 951, Address: 0x1ef8a8, Func Offset: 0x88
	// Line 952, Address: 0x1ef8ac, Func Offset: 0x8c
	// Line 951, Address: 0x1ef8b0, Func Offset: 0x90
	// Line 952, Address: 0x1ef8b4, Func Offset: 0x94
	// Line 953, Address: 0x1ef8bc, Func Offset: 0x9c
	// Line 954, Address: 0x1ef8c8, Func Offset: 0xa8
	// Line 955, Address: 0x1ef8f4, Func Offset: 0xd4
	// Line 957, Address: 0x1ef908, Func Offset: 0xe8
	// Line 959, Address: 0x1ef914, Func Offset: 0xf4
	// Line 961, Address: 0x1ef924, Func Offset: 0x104
	// Line 962, Address: 0x1ef934, Func Offset: 0x114
	// Line 964, Address: 0x1ef93c, Func Offset: 0x11c
	// Line 966, Address: 0x1ef950, Func Offset: 0x130
	// Line 967, Address: 0x1ef970, Func Offset: 0x150
	// Line 970, Address: 0x1ef974, Func Offset: 0x154
	// Line 967, Address: 0x1ef97c, Func Offset: 0x15c
	// Line 968, Address: 0x1ef984, Func Offset: 0x164
	// Line 970, Address: 0x1ef990, Func Offset: 0x170
	// Line 971, Address: 0x1ef9ac, Func Offset: 0x18c
	// Line 972, Address: 0x1ef9d0, Func Offset: 0x1b0
	// Line 976, Address: 0x1ef9d4, Func Offset: 0x1b4
	// Line 972, Address: 0x1ef9d8, Func Offset: 0x1b8
	// Line 973, Address: 0x1ef9e0, Func Offset: 0x1c0
	// Line 974, Address: 0x1ef9ec, Func Offset: 0x1cc
	// Line 976, Address: 0x1ef9f8, Func Offset: 0x1d8
	// Line 977, Address: 0x1efa00, Func Offset: 0x1e0
	// Line 980, Address: 0x1efa08, Func Offset: 0x1e8
	// Line 978, Address: 0x1efa14, Func Offset: 0x1f4
	// Line 982, Address: 0x1efa18, Func Offset: 0x1f8
	// Line 978, Address: 0x1efa20, Func Offset: 0x200
	// Line 979, Address: 0x1efa28, Func Offset: 0x208
	// Line 980, Address: 0x1efa34, Func Offset: 0x214
	// Line 982, Address: 0x1efa40, Func Offset: 0x220
	// Line 985, Address: 0x1efa58, Func Offset: 0x238
	// Line 988, Address: 0x1efa5c, Func Offset: 0x23c
	// Line 985, Address: 0x1efa60, Func Offset: 0x240
	// Line 988, Address: 0x1efa68, Func Offset: 0x248
	// Line 989, Address: 0x1efa74, Func Offset: 0x254
	// Line 993, Address: 0x1efa80, Func Offset: 0x260
	// Line 994, Address: 0x1efa90, Func Offset: 0x270
	// Line 995, Address: 0x1efaa0, Func Offset: 0x280
	// Line 998, Address: 0x1efaa4, Func Offset: 0x284
	// Line 999, Address: 0x1efaa8, Func Offset: 0x288
	// Line 1002, Address: 0x1efaac, Func Offset: 0x28c
	// Line 1006, Address: 0x1efab8, Func Offset: 0x298
	// Func End, Address: 0x1efacc, Func Offset: 0x2ac
}

// 
// Start address: 0x1efad0
void bhEne18_MV05(BH_PWORK* epw)
{
	BH_PWORK* ep;
	_anon25 pos[3];
	// Line 1016, Address: 0x1efad0, Func Offset: 0
	// Line 1017, Address: 0x1efadc, Func Offset: 0xc
	// Line 1016, Address: 0x1efae4, Func Offset: 0x14
	// Line 1017, Address: 0x1efae8, Func Offset: 0x18
	// Line 1024, Address: 0x1efb08, Func Offset: 0x38
	// Line 1026, Address: 0x1efb28, Func Offset: 0x58
	// Line 1027, Address: 0x1efb34, Func Offset: 0x64
	// Line 1028, Address: 0x1efb38, Func Offset: 0x68
	// Line 1029, Address: 0x1efb44, Func Offset: 0x74
	// Line 1033, Address: 0x1efb50, Func Offset: 0x80
	// Line 1032, Address: 0x1efb54, Func Offset: 0x84
	// Line 1033, Address: 0x1efb58, Func Offset: 0x88
	// Line 1034, Address: 0x1efb5c, Func Offset: 0x8c
	// Line 1033, Address: 0x1efb60, Func Offset: 0x90
	// Line 1034, Address: 0x1efb64, Func Offset: 0x94
	// Line 1035, Address: 0x1efb6c, Func Offset: 0x9c
	// Line 1036, Address: 0x1efb78, Func Offset: 0xa8
	// Line 1037, Address: 0x1efba4, Func Offset: 0xd4
	// Line 1039, Address: 0x1efbb8, Func Offset: 0xe8
	// Line 1041, Address: 0x1efbc4, Func Offset: 0xf4
	// Line 1043, Address: 0x1efbd4, Func Offset: 0x104
	// Line 1044, Address: 0x1efbe4, Func Offset: 0x114
	// Line 1046, Address: 0x1efbec, Func Offset: 0x11c
	// Line 1048, Address: 0x1efc00, Func Offset: 0x130
	// Line 1049, Address: 0x1efc20, Func Offset: 0x150
	// Line 1052, Address: 0x1efc24, Func Offset: 0x154
	// Line 1049, Address: 0x1efc2c, Func Offset: 0x15c
	// Line 1050, Address: 0x1efc34, Func Offset: 0x164
	// Line 1052, Address: 0x1efc40, Func Offset: 0x170
	// Line 1053, Address: 0x1efc5c, Func Offset: 0x18c
	// Line 1054, Address: 0x1efc80, Func Offset: 0x1b0
	// Line 1058, Address: 0x1efc84, Func Offset: 0x1b4
	// Line 1054, Address: 0x1efc88, Func Offset: 0x1b8
	// Line 1055, Address: 0x1efc90, Func Offset: 0x1c0
	// Line 1056, Address: 0x1efc9c, Func Offset: 0x1cc
	// Line 1058, Address: 0x1efca8, Func Offset: 0x1d8
	// Line 1059, Address: 0x1efcb0, Func Offset: 0x1e0
	// Line 1062, Address: 0x1efcb8, Func Offset: 0x1e8
	// Line 1060, Address: 0x1efcc4, Func Offset: 0x1f4
	// Line 1064, Address: 0x1efcc8, Func Offset: 0x1f8
	// Line 1060, Address: 0x1efcd0, Func Offset: 0x200
	// Line 1061, Address: 0x1efcd8, Func Offset: 0x208
	// Line 1062, Address: 0x1efce4, Func Offset: 0x214
	// Line 1064, Address: 0x1efcf0, Func Offset: 0x220
	// Line 1067, Address: 0x1efd08, Func Offset: 0x238
	// Line 1070, Address: 0x1efd0c, Func Offset: 0x23c
	// Line 1067, Address: 0x1efd10, Func Offset: 0x240
	// Line 1070, Address: 0x1efd18, Func Offset: 0x248
	// Line 1071, Address: 0x1efd24, Func Offset: 0x254
	// Line 1075, Address: 0x1efd30, Func Offset: 0x260
	// Line 1076, Address: 0x1efd40, Func Offset: 0x270
	// Line 1077, Address: 0x1efd50, Func Offset: 0x280
	// Line 1080, Address: 0x1efd54, Func Offset: 0x284
	// Line 1081, Address: 0x1efd58, Func Offset: 0x288
	// Line 1084, Address: 0x1efd5c, Func Offset: 0x28c
	// Line 1088, Address: 0x1efd68, Func Offset: 0x298
	// Func End, Address: 0x1efd7c, Func Offset: 0x2ac
}

// 
// Start address: 0x1efd80
void bhEne18_Nage()
{
	// Line 1099, Address: 0x1efd80, Func Offset: 0
	// Func End, Address: 0x1efd88, Func Offset: 0x8
}

// 
// Start address: 0x1efd90
void bhEne18_Damage()
{
	// Line 1110, Address: 0x1efd90, Func Offset: 0
	// Func End, Address: 0x1efd98, Func Offset: 0x8
}

// 
// Start address: 0x1efda0
void bhEne18_Die(BH_PWORK* epw)
{
	// Line 1121, Address: 0x1efda0, Func Offset: 0
	// Line 1125, Address: 0x1efda4, Func Offset: 0x4
	// Line 1121, Address: 0x1efda8, Func Offset: 0x8
	// Line 1123, Address: 0x1efdb0, Func Offset: 0x10
	// Line 1124, Address: 0x1efdc0, Func Offset: 0x20
	// Line 1125, Address: 0x1efdc4, Func Offset: 0x24
	// Line 1126, Address: 0x1efdd0, Func Offset: 0x30
	// Line 1127, Address: 0x1efde4, Func Offset: 0x44
	// Func End, Address: 0x1efdec, Func Offset: 0x4c
}

// 
// Start address: 0x1efdf0
int bhEne18_HitMark(BH_PWORK* epw)
{
	_anon3* eop;
	_anon0* blp;
	_anon25 ofp;
	int i;
	int range;
	// Line 1137, Address: 0x1efdf0, Func Offset: 0
	// Line 1144, Address: 0x1efe00, Func Offset: 0x10
	// Line 1137, Address: 0x1efe04, Func Offset: 0x14
	// Line 1144, Address: 0x1efe08, Func Offset: 0x18
	// Line 1137, Address: 0x1efe0c, Func Offset: 0x1c
	// Line 1144, Address: 0x1efe18, Func Offset: 0x28
	// Line 1137, Address: 0x1efe24, Func Offset: 0x34
	// Line 1144, Address: 0x1efe28, Func Offset: 0x38
	// Line 1147, Address: 0x1efe30, Func Offset: 0x40
	// Line 1148, Address: 0x1efe38, Func Offset: 0x48
	// Line 1147, Address: 0x1efe3c, Func Offset: 0x4c
	// Line 1148, Address: 0x1efe50, Func Offset: 0x60
	// Line 1149, Address: 0x1efe54, Func Offset: 0x64
	// Line 1150, Address: 0x1efe64, Func Offset: 0x74
	// Line 1151, Address: 0x1efe74, Func Offset: 0x84
	// Line 1152, Address: 0x1efe9c, Func Offset: 0xac
	// Line 1154, Address: 0x1efee8, Func Offset: 0xf8
	// Line 1155, Address: 0x1efeec, Func Offset: 0xfc
	// Line 1152, Address: 0x1efef0, Func Offset: 0x100
	// Line 1153, Address: 0x1efef4, Func Offset: 0x104
	// Line 1154, Address: 0x1efefc, Func Offset: 0x10c
	// Line 1155, Address: 0x1eff04, Func Offset: 0x114
	// Line 1156, Address: 0x1eff0c, Func Offset: 0x11c
	// Line 1157, Address: 0x1eff4c, Func Offset: 0x15c
	// Line 1158, Address: 0x1eff8c, Func Offset: 0x19c
	// Line 1160, Address: 0x1effcc, Func Offset: 0x1dc
	// Line 1170, Address: 0x1efffc, Func Offset: 0x20c
	// Line 1171, Address: 0x1f002c, Func Offset: 0x23c
	// Line 1173, Address: 0x1f0034, Func Offset: 0x244
	// Line 1178, Address: 0x1f0064, Func Offset: 0x274
	// Line 1179, Address: 0x1f008c, Func Offset: 0x29c
	// Line 1183, Address: 0x1f00a0, Func Offset: 0x2b0
	// Line 1184, Address: 0x1f00e4, Func Offset: 0x2f4
	// Line 1185, Address: 0x1f00e8, Func Offset: 0x2f8
	// Line 1187, Address: 0x1f0134, Func Offset: 0x344
	// Line 1188, Address: 0x1f0138, Func Offset: 0x348
	// Line 1185, Address: 0x1f013c, Func Offset: 0x34c
	// Line 1186, Address: 0x1f0140, Func Offset: 0x350
	// Line 1187, Address: 0x1f0148, Func Offset: 0x358
	// Line 1188, Address: 0x1f0150, Func Offset: 0x360
	// Line 1189, Address: 0x1f0158, Func Offset: 0x368
	// Line 1190, Address: 0x1f0198, Func Offset: 0x3a8
	// Line 1191, Address: 0x1f01d8, Func Offset: 0x3e8
	// Line 1192, Address: 0x1f0214, Func Offset: 0x424
	// Line 1193, Address: 0x1f029c, Func Offset: 0x4ac
	// Line 1194, Address: 0x1f02ac, Func Offset: 0x4bc
	// Line 1196, Address: 0x1f02b0, Func Offset: 0x4c0
	// Line 1197, Address: 0x1f02e4, Func Offset: 0x4f4
	// Line 1199, Address: 0x1f0330, Func Offset: 0x540
	// Line 1197, Address: 0x1f0334, Func Offset: 0x544
	// Line 1198, Address: 0x1f0338, Func Offset: 0x548
	// Line 1200, Address: 0x1f033c, Func Offset: 0x54c
	// Line 1198, Address: 0x1f0340, Func Offset: 0x550
	// Line 1199, Address: 0x1f0344, Func Offset: 0x554
	// Line 1200, Address: 0x1f034c, Func Offset: 0x55c
	// Line 1201, Address: 0x1f0354, Func Offset: 0x564
	// Line 1202, Address: 0x1f0394, Func Offset: 0x5a4
	// Line 1203, Address: 0x1f03d4, Func Offset: 0x5e4
	// Line 1204, Address: 0x1f03f0, Func Offset: 0x600
	// Line 1203, Address: 0x1f03f4, Func Offset: 0x604
	// Line 1204, Address: 0x1f0418, Func Offset: 0x628
	// Line 1207, Address: 0x1f0424, Func Offset: 0x634
	// Line 1208, Address: 0x1f0428, Func Offset: 0x638
	// Func End, Address: 0x1f0450, Func Offset: 0x660
}

