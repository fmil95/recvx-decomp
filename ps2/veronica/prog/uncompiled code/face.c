typedef struct npobj;
typedef struct _anon0;
typedef struct cnkobj;
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
typedef struct BH_PWORK;
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

typedef void(*type_86)(void*);

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
typedef float type_10[3];
typedef _anon0* type_11[512];
typedef _anon1* type_12[1300];
typedef int type_13[3];
typedef char type_14[32];
typedef float type_15[3];
typedef _anon0* type_16[512];
typedef _anon1* type_17[200];
typedef short type_18[32];
typedef _anon20 type_19[1];
typedef _anon0* type_20[128];
typedef unsigned int type_21[1];
typedef _anon6 type_22[256];
typedef _anon1* type_23[8];
typedef int* type_24[16];
typedef _anon0* type_25[128];
typedef npobj* type_26[16];
typedef _anon0* type_27[128];
typedef int type_28[4];
typedef _anon1* type_29[16];
typedef unsigned int type_30[4];
typedef _anon14 type_31[16];
typedef _anon0* type_32[512];
typedef char type_33[4];
typedef char type_34[256];
typedef unsigned short type_35[2];
typedef float type_36[4];
typedef unsigned int type_37[3];
typedef float type_38[4];
typedef float type_39[4];
typedef _anon5* type_40[128];
typedef cnkobj type_41[9];
typedef unsigned char type_42[64];
typedef float type_43[16];
typedef cnkobj* type_44[9];
typedef float type_45[3];
typedef float type_46[3][9];
typedef int type_47[3];
typedef int type_48[3][9];
typedef unsigned int type_49[4];
typedef char type_50[8];
typedef unsigned int type_51[3];
typedef float type_52[16][9];
typedef void* type_53[2];
typedef char type_54[9];
typedef float type_55[3];
typedef _anon1* type_56[256];
typedef int type_57[3];
typedef int type_58[4];
typedef unsigned char* type_59[256];
typedef float type_60[3];
typedef unsigned int type_61[2];
typedef short type_62[256];
typedef float type_63[32];
typedef int type_64[3];
typedef _anon28 type_65[4];
typedef float type_66[3];
typedef short type_67[256];
typedef int type_68[3];
typedef int type_69[8];
typedef float type_70[3];
typedef _anon1* type_71[256];
typedef _anon9 type_72[256];
typedef _anon20 type_73[450];
typedef _anon29 type_74[16];
typedef short type_75[256];
typedef char type_76[3];
typedef int type_77[64];
typedef _anon14 type_78[450];
typedef _anon32 type_79[4];
typedef _anon3 type_80[4];
typedef int type_81[450];
typedef unsigned int type_82[8];
typedef unsigned char type_83[450];
typedef char type_84[16];
typedef char type_85[4];
typedef unsigned int type_87[32];
typedef unsigned int type_88[16];
typedef _anon34 type_89[64];
typedef unsigned int type_90[16];
typedef _anon34 type_91[64];
typedef unsigned int type_92[32];
typedef _anon34 type_93[64];
typedef unsigned int type_94[16];
typedef unsigned int type_95[3];
typedef BH_PWORK* type_96[16];
typedef unsigned int type_97[8];
typedef unsigned int type_98[1];
typedef unsigned int type_99[384];
typedef unsigned int type_100[2];
typedef unsigned char type_101[2];
typedef unsigned int type_102[4];
typedef int* type_103[16];
typedef char type_104[32];
typedef npobj* type_105[16];
typedef char type_106[64];
typedef _anon1* type_107[16];
typedef char type_108[4];
typedef _anon14 type_109[16];
typedef short type_110[4];
typedef unsigned char type_111[4];
typedef _anon30 type_112[16];
typedef unsigned int type_113[32];
typedef _anon12 type_114[32];
typedef _anon0* type_115[512];
typedef _anon0* type_116[128];
typedef _anon0* type_117[512];
typedef unsigned char type_118[64];
typedef _anon0* type_119[512];

struct npobj
{
	unsigned int evalflags;
	_anon4* model;
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
	_anon14 mdl[16];
	_anon14* mlwP;
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
	_anon32* pvp;
	_anon3* tvp;
	_anon32 pv[4];
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

struct cnkobj
{
	unsigned int evalflags;
	_anon4* model;
	float pos[3];
	int ang[3];
	float scl[3];
	cnkobj* child;
	cnkobj* sibling;
};

struct _anon1
{
	_anon20* textures;
	unsigned int nbTexture;
};

struct _anon2
{
	_anon4* src;
	_anon4* dst;
	_anon8* list;
	_anon10* vlist;
	_anon12** nvpt;
	int lnum;
	cnkobj* obj;
	_anon16* jaw;
	int jnum;
	unsigned int Dummy[3];
	float jmat1[16];
	float jmat2[16];
	_anon27 param;
	cnkobj eye[9];
	cnkobj* eyesrc[9];
	float eyepos[3][9];
	int eyeang[3][9];
	unsigned int Dummy2[3];
	float eyemat[16][9];
	_anon16* tang;
	int tnum;
	_anon4* tangsrc;
	_anon4* tangdst;
	cnkobj tangobj;
	cnkobj* tangorg;
	float tangpos[3];
	int tangang[3];
	cnkobj tooth;
	cnkobj* toothsrc;
	float toothpos[3];
	int toothang[3];
	unsigned int mode;
	_anon27* face;
	int fnum;
	int vtype;
	int vtop;
	int ntop;
	int vofs;
	_anon13* head;
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
	int* vlist;
	short* plist;
	_anon12 center;
	float r;
};

struct _anon5
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon19* md2P;
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
	int id;
	_anon12 vec;
	float scal;
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
	short id;
	char mnum;
	char nvnum;
};

struct _anon11
{
	unsigned char* top;
	unsigned char* ptr;
	short cnt;
	short time;
	unsigned char cur;
	unsigned char next;
	unsigned short flag;
};

struct _anon12
{
	float x;
	float y;
	float z;
};

struct _anon13
{
	char id[4];
	unsigned short version;
	unsigned short flag;
	unsigned short jawId[2];
	unsigned int nAttr;
	unsigned int nList;
	unsigned int nConnect;
	unsigned int nJaw;
	unsigned int nTang;
	unsigned int nFace;
	unsigned int reserve[4];
	char faceId;
	char tangId;
	char toothId;
	char eyeId[9];
};

struct _anon14
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon25* owP;
};

struct _anon15
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

struct _anon16
{
	int id;
	float rate;
};

struct _anon17
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

struct _anon18
{
	void* texaddr;
	_anon7 texsurface;
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
	_anon26* light;
};

struct _anon23
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
	_anon12 ply_pos;
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
	_anon15* p1per;
	_anon15* p2per;
	_anon15* kbper;
	_anon15* msper;
	_anon15 ms_per;
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
	_anon5* emtp[128];
	_anon5* rmthp;
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
	_anon9 txbp[256];
	unsigned char* ef_psp;
	_anon20 ef_tex[450];
	_anon1 ef_tlist;
	_anon33 ef;
	short efid[256];
	_anon14 efm[450];
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
	_anon18 ren_info;
	_anon20 ren_tex[1];
	_anon1 ren_tlist;
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
	_anon35 mr_pl;
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
	_anon29 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon34* pl_htp;
	int costume;
	_anon12 hd_pos;
	_anon12 apos;
	_anon34* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon34 mwalp[64];
	_anon34 metcp[64];
	_anon34 mflrp[64];
	int dla_n;
	_anon34* htp;
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
	_anon17 door;
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
	_anon12 ufo_pos;
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
	_anon30 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon12 ghtp[32];
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

struct _anon24
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon25
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon26
{
	float mtrx[16];
	_anon12 pnt;
	_anon12 vctr;
	int stat;
	int reserve;
	_anon31 ltcal;
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
	_anon14 mdl[16];
	_anon14* mlwP;
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

struct _anon27
{
	float muscle[32];
	float jawang;
	float jawtrans;
	_anon12 eye;
	float tangx;
	float tangy;
	float tangz;
	short frame;
	short flag;
};

struct _anon28
{
	_anon12 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon29
{
	float x;
	float y;
};

struct _anon30
{
	_anon12 c1;
	_anon12 c2;
	float r1;
	float r2;
};

struct _anon31
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
	_anon12 lpnt;
	_anon12 lvctr;
	_anon12 lmvctr;
	_anon24 atten;
	_anon24 amb;
	_anon24 dif;
	_anon24 spc;
	_anon24 mamb;
	_anon24 mdif;
	_anon24 mspc;
};

struct _anon32
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon33
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

struct _anon34
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

struct _anon35
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
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
	_anon24 argb;
};

struct _anon38
{
	_anon12 c;
	float r;
};

struct _anon39
{
	_anon12 c1;
	_anon12 c2;
	float r;
};

_anon23* sys;

void bhInitMask(BH_PWORK* pp);
void bhControlMask(BH_PWORK* pp);
int bhSetMask(BH_PWORK* pp, int msk_no, int frm_no);
int bhSetLip(BH_PWORK* pp, int mls_no);

// 
// Start address: 0x297fd0
void bhInitMask(BH_PWORK* pp)
{
	int i;
	_anon2* fm;
	// Line 61, Address: 0x297fd0, Func Offset: 0
	// Line 66, Address: 0x297fe0, Func Offset: 0x10
	// Line 68, Address: 0x297ff0, Func Offset: 0x20
	// Line 70, Address: 0x298000, Func Offset: 0x30
	// Line 73, Address: 0x298014, Func Offset: 0x44
	// Line 74, Address: 0x298020, Func Offset: 0x50
	// Line 75, Address: 0x298030, Func Offset: 0x60
	// Line 76, Address: 0x298044, Func Offset: 0x74
	// Line 77, Address: 0x298058, Func Offset: 0x88
	// Line 78, Address: 0x29806c, Func Offset: 0x9c
	// Line 79, Address: 0x298080, Func Offset: 0xb0
	// Line 80, Address: 0x298090, Func Offset: 0xc0
	// Line 84, Address: 0x298098, Func Offset: 0xc8
	// Line 85, Address: 0x2980a0, Func Offset: 0xd0
	// Line 86, Address: 0x2980a4, Func Offset: 0xd4
	// Line 85, Address: 0x2980ac, Func Offset: 0xdc
	// Line 86, Address: 0x2980b4, Func Offset: 0xe4
	// Line 87, Address: 0x2980bc, Func Offset: 0xec
	// Line 88, Address: 0x2980c4, Func Offset: 0xf4
	// Line 90, Address: 0x2980cc, Func Offset: 0xfc
	// Line 89, Address: 0x2980d0, Func Offset: 0x100
	// Line 90, Address: 0x2980d4, Func Offset: 0x104
	// Line 94, Address: 0x2980e4, Func Offset: 0x114
	// Line 95, Address: 0x2980f0, Func Offset: 0x120
	// Line 96, Address: 0x298100, Func Offset: 0x130
	// Line 97, Address: 0x29810c, Func Offset: 0x13c
	// Line 98, Address: 0x298118, Func Offset: 0x148
	// Line 101, Address: 0x298130, Func Offset: 0x160
	// Line 102, Address: 0x298144, Func Offset: 0x174
	// Line 103, Address: 0x298158, Func Offset: 0x188
	// Line 104, Address: 0x29816c, Func Offset: 0x19c
	// Line 105, Address: 0x298180, Func Offset: 0x1b0
	// Line 106, Address: 0x298194, Func Offset: 0x1c4
	// Line 107, Address: 0x2981a8, Func Offset: 0x1d8
	// Line 108, Address: 0x2981bc, Func Offset: 0x1ec
	// Line 109, Address: 0x2981d0, Func Offset: 0x200
	// Line 112, Address: 0x2981e4, Func Offset: 0x214
	// Line 114, Address: 0x2981ec, Func Offset: 0x21c
	// Line 115, Address: 0x2981f4, Func Offset: 0x224
	// Line 118, Address: 0x298204, Func Offset: 0x234
	// Line 122, Address: 0x298208, Func Offset: 0x238
	// Line 118, Address: 0x29820c, Func Offset: 0x23c
	// Line 119, Address: 0x298210, Func Offset: 0x240
	// Line 120, Address: 0x298218, Func Offset: 0x248
	// Line 121, Address: 0x298220, Func Offset: 0x250
	// Line 122, Address: 0x298228, Func Offset: 0x258
	// Line 123, Address: 0x298230, Func Offset: 0x260
	// Line 124, Address: 0x298238, Func Offset: 0x268
	// Line 125, Address: 0x29823c, Func Offset: 0x26c
	// Func End, Address: 0x298250, Func Offset: 0x280
}

// 
// Start address: 0x298250
void bhControlMask(BH_PWORK* pp)
{
	void* fbak;
	_anon11* lip;
	_anon2* fm;
	// Line 131, Address: 0x298250, Func Offset: 0
	// Line 136, Address: 0x298268, Func Offset: 0x18
	// Line 137, Address: 0x298274, Func Offset: 0x24
	// Line 140, Address: 0x298298, Func Offset: 0x48
	// Line 146, Address: 0x2982a0, Func Offset: 0x50
	// Line 143, Address: 0x2982a4, Func Offset: 0x54
	// Line 146, Address: 0x2982a8, Func Offset: 0x58
	// Line 147, Address: 0x2982b4, Func Offset: 0x64
	// Line 148, Address: 0x2982c0, Func Offset: 0x70
	// Line 150, Address: 0x2982e0, Func Offset: 0x90
	// Line 153, Address: 0x298308, Func Offset: 0xb8
	// Line 154, Address: 0x29831c, Func Offset: 0xcc
	// Line 155, Address: 0x298328, Func Offset: 0xd8
	// Line 156, Address: 0x29832c, Func Offset: 0xdc
	// Line 155, Address: 0x298330, Func Offset: 0xe0
	// Line 156, Address: 0x298334, Func Offset: 0xe4
	// Line 157, Address: 0x298340, Func Offset: 0xf0
	// Line 159, Address: 0x298364, Func Offset: 0x114
	// Line 160, Address: 0x29836c, Func Offset: 0x11c
	// Line 163, Address: 0x298370, Func Offset: 0x120
	// Line 160, Address: 0x298374, Func Offset: 0x124
	// Line 161, Address: 0x298380, Func Offset: 0x130
	// Line 162, Address: 0x29838c, Func Offset: 0x13c
	// Line 163, Address: 0x298394, Func Offset: 0x144
	// Line 164, Address: 0x2983a4, Func Offset: 0x154
	// Line 169, Address: 0x2983c4, Func Offset: 0x174
	// Line 170, Address: 0x2983d8, Func Offset: 0x188
	// Line 171, Address: 0x2983e4, Func Offset: 0x194
	// Line 174, Address: 0x2983e8, Func Offset: 0x198
	// Line 171, Address: 0x2983ec, Func Offset: 0x19c
	// Line 172, Address: 0x2983f0, Func Offset: 0x1a0
	// Line 173, Address: 0x2983f8, Func Offset: 0x1a8
	// Line 177, Address: 0x298400, Func Offset: 0x1b0
	// Line 178, Address: 0x298408, Func Offset: 0x1b8
	// Line 182, Address: 0x29840c, Func Offset: 0x1bc
	// Line 200, Address: 0x298420, Func Offset: 0x1d0
	// Line 203, Address: 0x29842c, Func Offset: 0x1dc
	// Line 210, Address: 0x298434, Func Offset: 0x1e4
	// Line 203, Address: 0x298440, Func Offset: 0x1f0
	// Line 204, Address: 0x298448, Func Offset: 0x1f8
	// Line 210, Address: 0x29844c, Func Offset: 0x1fc
	// Line 204, Address: 0x298450, Func Offset: 0x200
	// Line 207, Address: 0x298454, Func Offset: 0x204
	// Line 205, Address: 0x298458, Func Offset: 0x208
	// Line 207, Address: 0x29845c, Func Offset: 0x20c
	// Line 210, Address: 0x298464, Func Offset: 0x214
	// Line 211, Address: 0x29848c, Func Offset: 0x23c
	// Line 213, Address: 0x2984ac, Func Offset: 0x25c
	// Line 217, Address: 0x2984b0, Func Offset: 0x260
	// Line 219, Address: 0x2984c4, Func Offset: 0x274
	// Line 220, Address: 0x2984d0, Func Offset: 0x280
	// Line 221, Address: 0x2984dc, Func Offset: 0x28c
	// Line 222, Address: 0x2984f8, Func Offset: 0x2a8
	// Line 223, Address: 0x298508, Func Offset: 0x2b8
	// Line 224, Address: 0x298510, Func Offset: 0x2c0
	// Line 225, Address: 0x298528, Func Offset: 0x2d8
	// Line 226, Address: 0x298538, Func Offset: 0x2e8
	// Line 229, Address: 0x298540, Func Offset: 0x2f0
	// Line 230, Address: 0x298548, Func Offset: 0x2f8
	// Line 231, Address: 0x298558, Func Offset: 0x308
	// Line 237, Address: 0x298560, Func Offset: 0x310
	// Line 238, Address: 0x298574, Func Offset: 0x324
	// Line 240, Address: 0x29857c, Func Offset: 0x32c
	// Line 246, Address: 0x298580, Func Offset: 0x330
	// Line 238, Address: 0x298584, Func Offset: 0x334
	// Line 239, Address: 0x29858c, Func Offset: 0x33c
	// Line 240, Address: 0x298594, Func Offset: 0x344
	// Line 241, Address: 0x2985a4, Func Offset: 0x354
	// Line 242, Address: 0x2985b0, Func Offset: 0x360
	// Line 243, Address: 0x2985bc, Func Offset: 0x36c
	// Line 244, Address: 0x2985c8, Func Offset: 0x378
	// Line 245, Address: 0x2985d4, Func Offset: 0x384
	// Line 246, Address: 0x2985d8, Func Offset: 0x388
	// Line 276, Address: 0x2985e8, Func Offset: 0x398
	// Line 279, Address: 0x29862c, Func Offset: 0x3dc
	// Line 281, Address: 0x298634, Func Offset: 0x3e4
	// Line 282, Address: 0x298648, Func Offset: 0x3f8
	// Line 283, Address: 0x29865c, Func Offset: 0x40c
	// Line 284, Address: 0x298674, Func Offset: 0x424
	// Line 285, Address: 0x29868c, Func Offset: 0x43c
	// Line 286, Address: 0x2986a4, Func Offset: 0x454
	// Line 336, Address: 0x2986bc, Func Offset: 0x46c
	// Func End, Address: 0x2986d8, Func Offset: 0x488
}

// 
// Start address: 0x2986e0
int bhSetMask(BH_PWORK* pp, int msk_no, int frm_no)
{
	int i;
	unsigned int sz;
	unsigned char* datp;
	_anon2* fm;
	// Line 347, Address: 0x2986e0, Func Offset: 0
	// Line 351, Address: 0x2986e4, Func Offset: 0x4
	// Line 352, Address: 0x2986e8, Func Offset: 0x8
	// Line 351, Address: 0x2986ec, Func Offset: 0xc
	// Line 352, Address: 0x2986f0, Func Offset: 0x10
	// Line 353, Address: 0x298700, Func Offset: 0x20
	// Line 354, Address: 0x29871c, Func Offset: 0x3c
	// Line 355, Address: 0x298720, Func Offset: 0x40
	// Line 357, Address: 0x29872c, Func Offset: 0x4c
	// Line 356, Address: 0x298730, Func Offset: 0x50
	// Line 357, Address: 0x298734, Func Offset: 0x54
	// Line 359, Address: 0x298744, Func Offset: 0x64
	// Line 358, Address: 0x298748, Func Offset: 0x68
	// Line 361, Address: 0x29874c, Func Offset: 0x6c
	// Line 359, Address: 0x298754, Func Offset: 0x74
	// Line 361, Address: 0x298758, Func Offset: 0x78
	// Line 362, Address: 0x298760, Func Offset: 0x80
	// Line 364, Address: 0x298764, Func Offset: 0x84
	// Line 362, Address: 0x298768, Func Offset: 0x88
	// Line 363, Address: 0x29876c, Func Offset: 0x8c
	// Line 365, Address: 0x29877c, Func Offset: 0x9c
	// Func End, Address: 0x298784, Func Offset: 0xa4
}

// 
// Start address: 0x298790
int bhSetLip(BH_PWORK* pp, int mls_no)
{
	int i;
	unsigned int sz;
	unsigned char* datp;
	_anon11* lip;
	// Line 406, Address: 0x298790, Func Offset: 0
	// Line 407, Address: 0x2987a4, Func Offset: 0x14
	// Line 408, Address: 0x2987bc, Func Offset: 0x2c
	// Line 409, Address: 0x2987c0, Func Offset: 0x30
	// Line 411, Address: 0x2987cc, Func Offset: 0x3c
	// Line 410, Address: 0x2987d0, Func Offset: 0x40
	// Line 411, Address: 0x2987d4, Func Offset: 0x44
	// Line 413, Address: 0x2987e4, Func Offset: 0x54
	// Line 412, Address: 0x2987e8, Func Offset: 0x58
	// Line 415, Address: 0x2987ec, Func Offset: 0x5c
	// Line 413, Address: 0x2987f4, Func Offset: 0x64
	// Line 415, Address: 0x2987f8, Func Offset: 0x68
	// Line 416, Address: 0x298800, Func Offset: 0x70
	// Line 417, Address: 0x298804, Func Offset: 0x74
	// Line 416, Address: 0x298808, Func Offset: 0x78
	// Line 418, Address: 0x29880c, Func Offset: 0x7c
	// Func End, Address: 0x298814, Func Offset: 0x84
}

