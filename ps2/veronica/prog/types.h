typedef struct NO_NAME_1
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
} NO_NAME_1;

typedef struct NO_NAME_2
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	NJS_CNK_OBJECT* objP;
	NJS_TEXLIST* texP;
	NO_NAME_1* owP;
} NO_NAME_2;

typedef struct NO_NAME_3
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	NJS_MDATA2* md2P;
	unsigned short* atrP;
} NO_NAME_3;

typedef struct NO_NAME_4
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
	NJS_CNK_OBJECT* mbp[16];
	NJS_TEXLIST* txp[16];
	NO_NAME_2 mdl[16];
	NO_NAME_2* mlwP;
	unsigned int mdl_no;
	int lkono;
	unsigned char* lkwkp;
	unsigned char* exp0;
	unsigned char* exp1;
	unsigned char* exp2;
	unsigned char* exp3;
	unsigned char mtxbuf[64];
	float mtx[16];
	NJS_CNK_OBJECT* obj_a;
	NJS_CNK_OBJECT* obj_b;
	float shp_ct;
	char clp_jno[8];
	int lok_jno;
	NO_NAME_3* mnwP;
	NO_NAME_3* mnwPb;
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
	NJS_SPHERE cspr;
	int pn;
	NJS_POLYGON_VTX* pvp;
	NJS_TEXTURE_VTX* tvp;
	NJS_POLYGON_VTX pv[4];
	NJS_TEXTURE_VTX tv[4];
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
} NO_NAME_4;

typedef struct NO_NAME_5
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
} NO_NAME_5;

typedef struct NO_NAME_6
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
} NO_NAME_6;

typedef struct NO_NAME_7
{
	short jnt_a;
	short jnt_b;
	int cap_r;
} NO_NAME_7;

typedef struct BH_PWORK
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
	NJS_CNK_OBJECT* mbp[16];
	NJS_TEXLIST* txp[16];
	NO_NAME_2 mdl[16];
	NO_NAME_2* mlwP;
	unsigned int mdl_no;
	int lkono;
	unsigned char* lkwkp;
	unsigned char* exp0;
	unsigned char* exp1;
	unsigned char* exp2;
	unsigned char* exp3;
	unsigned char mtxbuf[64];
	float mtx[16];
	NJS_CNK_OBJECT* obj_a;
	NJS_CNK_OBJECT* obj_b;
	float shp_ct;
	char clp_jno[8];
	int lok_jno;
	NO_NAME_3* mnwP;
	NO_NAME_3* mnwPb;
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
	NJS_CAPSULE watr;
	NO_NAME_7* cpcl;
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
} BH_PWORK;

typedef struct NO_NAME_8
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
	NJS_LIGHT_PTR* light;
} NO_NAME_8;

typedef struct NO_NAME_9
{
	NJS_POINT3 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
} NO_NAME_9;

typedef struct NO_NAME_10
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
} NO_NAME_10; 

typedef struct DOOR
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
} DOOR;

// similar but not quite like NJS_CAPSULE
typedef struct CONICAL_FRUSTUM
{
	NJS_POINT3 c1;
	NJS_POINT3 c2;
	float r1;
	float r2;
} CONICAL_FRUSTUM;

typedef struct SYS_WORK
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
	NJS_POINT3 ply_pos;
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
	NJS_TEXLIST* et_lp[16][16][100];
	NJS_TEXLIST* ot_lp[1300];
	NJS_TEXLIST* it_lp[200];
	int eft_n;
	NJS_TEXLIST* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	PDS_PERIPHERAL* p1per;
	PDS_PERIPHERAL* p2per;
	PDS_PERIPHERAL* kbper;
	PDS_PERIPHERAL* msper;
	PDS_PERIPHERAL ms_per;
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
	NO_NAME_4* obwp;
	NO_NAME_4* itwp;
	NO_NAME_3* emtp[128];
	NO_NAME_3* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	NJS_TEXLIST* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	NJS_TEXLIST* txblp[256];
	NO_NAME_5 txbp[256];
	unsigned char* ef_psp;
	NJS_TEXNAME ef_tex[450];
	NJS_TEXLIST ef_tlist;
	NO_NAME_6 ef;
	short efid[256];
	NO_NAME_2 efm[450];
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
	NO_NAME_4* ef_pol[512];
	NO_NAME_4* ef_mdf[128];
	NO_NAME_4* ef_lin[512];
	NO_NAME_4* ef_ntx[512];
	NO_NAME_4* ef_trs[512];
	NO_NAME_4* ef_pnc[512];
	NO_NAME_4* ef_opq[512];
	NO_NAME_4* ef_thl[512];
	NO_NAME_4* ef_ntx2d[128];
	NO_NAME_4* ef_trs2d[128];
	NO_NAME_4* ef_pnc2d[128];
	NO_NAME_4* ef_fnc[512];
	int ob_nlgn;
	int ob_hlgn;
	int ob_spcn;
	NO_NAME_4* ob_nlg[32];
	NO_NAME_4* ob_hlg[32];
	NO_NAME_4* ob_spc[32];
	unsigned int ren_gid;
	NJS_TEXINFO ren_info;
	NJS_TEXNAME ren_tex[1];
	NJS_TEXLIST ren_tlist;
	NJS_TEXTUREH_VTX rpb[256];
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
	NJS_PLANE mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	NO_NAME_8* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	NO_NAME_9 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	NJS_POINT2 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	NO_NAME_10* pl_htp;
	int costume;
	NJS_POINT3 hd_pos;
	NJS_POINT3 apos;
	NO_NAME_10* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	NO_NAME_10 mwalp[64];
	NO_NAME_10 metcp[64];
	NO_NAME_10 mflrp[64];
	int dla_n;
	NO_NAME_10* htp;
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
	NJS_TEXLIST* sb_tlist;
	int ddmd;
	DOOR door;
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
	NJS_POINT3 ufo_pos;
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
	CONICAL_FRUSTUM gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	NJS_POINT3 ghtp[32];
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
} SYS_WORK;

typedef struct NO_NAME_12
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
} NO_NAME_12;

typedef struct NO_NAME_13
{
	int mode;
	int frame;
	int count;
	int vtx_opq_a;
	int vtx_opq_b;
	int vtx_trs_a;
	int vtx_trs_b;
	int vtx_punch;
	int vtx_total;
} NO_NAME_13;

typedef struct NO_NAME_14
{
	float pos[3];
	int* vlist;
	short* plist;
} NO_NAME_14;

typedef struct NP_WORK
{
	int* sknp;
	int obj_now;
	int obj_cnt;
	unsigned char* buff;
	unsigned char* bp;
	int* vlist[128];
	NJS_POINT3 op[128];
	NJS_CNK_OBJECT* cobj[128];
	int* sktp[128];
	int* vlp[128];
	NJS_MATRIX* mxp[128][10];
	void* wkp;
	unsigned char* buff2;
	unsigned char* bp2;
	NO_NAME_14 mdlstr2[128];
	int* vlp2[128];
	char mes[256];
} NP_WORK;

typedef struct NO_NAME_15
{
	unsigned char ucType;
	unsigned char ucAttr;
	unsigned short usSize;
	unsigned short usIndexOfs;
	unsigned short usIndexMax;
	unsigned char ucPadding[56];
} NO_NAME_15;

typedef struct NO_NAME_15_NOPAD
{
	unsigned char ucType;
	unsigned char ucAttr;
	unsigned short usSize;
	unsigned short usIndexOfs;
	unsigned short usIndexMax;
} NO_NAME_15_NOPAD;

typedef struct NO_NAME_16
{
	float x;
	float y;
	float z;
	float w;
} NO_NAME_16;

typedef struct NO_NAME_11 /* @anon20 */ {
    // total size: 0x330
    struct /* @anon35 */ {
        // total size: 0x28
        struct /* @anon26 */ {
            // total size: 0x8
            unsigned int EN1 : 1; // offset 0x0, size 0x4
            unsigned int EN2 : 1; // offset 0x0, size 0x4
            unsigned int CRTMD : 3; // offset 0x0, size 0x4
            unsigned int MMOD : 1; // offset 0x0, size 0x4
            unsigned int AMOD : 1; // offset 0x0, size 0x4
            unsigned int SLBG : 1; // offset 0x0, size 0x4
            unsigned int ALP : 8; // offset 0x0, size 0x4
            unsigned int p0 : 16; // offset 0x0, size 0x4
            unsigned int p1; // offset 0x4, size 0x4
        } pmode; // offset 0x0, size 0x8
        struct /* @anon37 */ {
            // total size: 0x8
            unsigned int INT : 1; // offset 0x0, size 0x4
            unsigned int FFMD : 1; // offset 0x0, size 0x4
            unsigned int DPMS : 2; // offset 0x0, size 0x4
            unsigned int p0 : 28; // offset 0x0, size 0x4
            unsigned int p1; // offset 0x4, size 0x4
        } smode2; // offset 0x8, size 0x8
        struct /* @anon29 */ {
            // total size: 0x8
            unsigned int FBP : 9; // offset 0x0, size 0x4
            unsigned int FBW : 6; // offset 0x0, size 0x4
            unsigned int PSM : 5; // offset 0x0, size 0x4
            unsigned int p0 : 12; // offset 0x0, size 0x4
            unsigned int DBX : 11; // offset 0x4, size 0x4
            unsigned int DBY : 11; // offset 0x4, size 0x4
            unsigned int p1 : 10; // offset 0x4, size 0x4
        } dispfb; // offset 0x10, size 0x8
        struct /* @anon2 */ {
            // total size: 0x8
            unsigned int DX : 12; // offset 0x0, size 0x4
            unsigned int DY : 11; // offset 0x0, size 0x4
            unsigned int MAGH : 4; // offset 0x0, size 0x4
            unsigned int MAGV : 2; // offset 0x0, size 0x4
            unsigned int p0 : 3; // offset 0x0, size 0x4
            unsigned int DW : 12; // offset 0x4, size 0x4
            unsigned int DH : 11; // offset 0x4, size 0x4
            unsigned int p1 : 9; // offset 0x4, size 0x4
        } display; // offset 0x18, size 0x8
        struct /* @anon7 */ {
            // total size: 0x8
            unsigned int R : 8; // offset 0x0, size 0x4
            unsigned int G : 8; // offset 0x0, size 0x4
            unsigned int B : 8; // offset 0x0, size 0x4
            unsigned int p0 : 8; // offset 0x0, size 0x4
            unsigned int p1; // offset 0x4, size 0x4
        } bgcolor; // offset 0x20, size 0x8
    } disp[2]; // offset 0x0, size 0x50
    struct /* @anon23 */ {
        // total size: 0x10
        unsigned long NLOOP : 15; // offset 0x0, size 0x4
        unsigned long EOP : 1; // offset 0x0, size 0x4
        unsigned long pad16 : 16; // offset 0x0, size 0x4
        unsigned long id : 14; // offset 0x0, size 0x4
        unsigned long PRE : 1; // offset 0x0, size 0x4
        unsigned long PRIM : 11; // offset 0x0, size 0x4
        unsigned long FLG : 2; // offset 0x0, size 0x4
        unsigned long NREG : 4; // offset 0x0, size 0x4
        unsigned long REGS0 : 4; // offset 0x8, size 0x4
        unsigned long REGS1 : 4; // offset 0x8, size 0x4
        unsigned long REGS2 : 4; // offset 0x8, size 0x4
        unsigned long REGS3 : 4; // offset 0x8, size 0x4
        unsigned long REGS4 : 4; // offset 0x8, size 0x4
        unsigned long REGS5 : 4; // offset 0x8, size 0x4
        unsigned long REGS6 : 4; // offset 0x8, size 0x4
        unsigned long REGS7 : 4; // offset 0x8, size 0x4
        unsigned long REGS8 : 4; // offset 0x8, size 0x4
        unsigned long REGS9 : 4; // offset 0x8, size 0x4
        unsigned long REGS10 : 4; // offset 0x8, size 0x4
        unsigned long REGS11 : 4; // offset 0x8, size 0x4
        unsigned long REGS12 : 4; // offset 0x8, size 0x4
        unsigned long REGS13 : 4; // offset 0x8, size 0x4
        unsigned long REGS14 : 4; // offset 0x8, size 0x4
        unsigned long REGS15 : 4; // offset 0x8, size 0x4
    } giftag0; // offset 0x50, size 0x10
    struct /* @anon38 */ {
        // total size: 0x80
        struct /* @anon15 */ {
            // total size: 0x8
            unsigned long FBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 7; // offset 0x0, size 0x4
            unsigned long FBW : 6; // offset 0x0, size 0x4
            unsigned long pad22 : 2; // offset 0x0, size 0x4
            unsigned long PSM : 6; // offset 0x0, size 0x4
            unsigned long pad30 : 2; // offset 0x0, size 0x4
            unsigned long FBMSK : 32; // offset 0x0, size 0x4
        } frame1; // offset 0x0, size 0x8
        unsigned long frame1addr; // offset 0x8, size 0x4
        struct /* @anon30 */ {
            // total size: 0x8
            unsigned long ZBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 15; // offset 0x0, size 0x4
            unsigned long PSM : 4; // offset 0x0, size 0x4
            unsigned long pad28 : 4; // offset 0x0, size 0x4
            unsigned long ZMSK : 1; // offset 0x0, size 0x4
            unsigned long pad33 : 31; // offset 0x0, size 0x4
        } zbuf1; // offset 0x10, size 0x8
        signed long zbuf1addr; // offset 0x18, size 0x4
        struct /* @anon22 */ {
            // total size: 0x8
            unsigned long OFX : 16; // offset 0x0, size 0x4
            unsigned long pad16 : 16; // offset 0x0, size 0x4
            unsigned long OFY : 16; // offset 0x0, size 0x4
            unsigned long pad48 : 16; // offset 0x0, size 0x4
        } xyoffset1; // offset 0x20, size 0x8
        signed long xyoffset1addr; // offset 0x28, size 0x4
        struct /* @anon13 */ {
            // total size: 0x8
            unsigned long SCAX0 : 11; // offset 0x0, size 0x4
            unsigned long pad11 : 5; // offset 0x0, size 0x4
            unsigned long SCAX1 : 11; // offset 0x0, size 0x4
            unsigned long pad27 : 5; // offset 0x0, size 0x4
            unsigned long SCAY0 : 11; // offset 0x0, size 0x4
            unsigned long pad43 : 5; // offset 0x0, size 0x4
            unsigned long SCAY1 : 11; // offset 0x0, size 0x4
            unsigned long pad59 : 5; // offset 0x0, size 0x4
        } scissor1; // offset 0x30, size 0x8
        signed long scissor1addr; // offset 0x38, size 0x4
        struct /* @anon5 */ {
            // total size: 0x8
            unsigned long AC : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } prmodecont; // offset 0x40, size 0x8
        signed long prmodecontaddr; // offset 0x48, size 0x4
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned long CLAMP : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } colclamp; // offset 0x50, size 0x8
        signed long colclampaddr; // offset 0x58, size 0x4
        struct /* @anon10 */ {
            // total size: 0x8
            unsigned long DTHE : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } dthe; // offset 0x60, size 0x8
        signed long dtheaddr; // offset 0x68, size 0x4
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } test1; // offset 0x70, size 0x8
        signed long test1addr; // offset 0x78, size 0x4
    } draw01; // offset 0x60, size 0x80
    struct /* @anon8 */ {
        // total size: 0x80
        struct /* @anon15 */ {
            // total size: 0x8
            unsigned long FBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 7; // offset 0x0, size 0x4
            unsigned long FBW : 6; // offset 0x0, size 0x4
            unsigned long pad22 : 2; // offset 0x0, size 0x4
            unsigned long PSM : 6; // offset 0x0, size 0x4
            unsigned long pad30 : 2; // offset 0x0, size 0x4
            unsigned long FBMSK : 32; // offset 0x0, size 0x4
        } frame2; // offset 0x0, size 0x8
        unsigned long frame2addr; // offset 0x8, size 0x4
        struct /* @anon30 */ {
            // total size: 0x8
            unsigned long ZBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 15; // offset 0x0, size 0x4
            unsigned long PSM : 4; // offset 0x0, size 0x4
            unsigned long pad28 : 4; // offset 0x0, size 0x4
            unsigned long ZMSK : 1; // offset 0x0, size 0x4
            unsigned long pad33 : 31; // offset 0x0, size 0x4
        } zbuf2; // offset 0x10, size 0x8
        signed long zbuf2addr; // offset 0x18, size 0x4
        struct /* @anon22 */ {
            // total size: 0x8
            unsigned long OFX : 16; // offset 0x0, size 0x4
            unsigned long pad16 : 16; // offset 0x0, size 0x4
            unsigned long OFY : 16; // offset 0x0, size 0x4
            unsigned long pad48 : 16; // offset 0x0, size 0x4
        } xyoffset2; // offset 0x20, size 0x8
        signed long xyoffset2addr; // offset 0x28, size 0x4
        struct /* @anon13 */ {
            // total size: 0x8
            unsigned long SCAX0 : 11; // offset 0x0, size 0x4
            unsigned long pad11 : 5; // offset 0x0, size 0x4
            unsigned long SCAX1 : 11; // offset 0x0, size 0x4
            unsigned long pad27 : 5; // offset 0x0, size 0x4
            unsigned long SCAY0 : 11; // offset 0x0, size 0x4
            unsigned long pad43 : 5; // offset 0x0, size 0x4
            unsigned long SCAY1 : 11; // offset 0x0, size 0x4
            unsigned long pad59 : 5; // offset 0x0, size 0x4
        } scissor2; // offset 0x30, size 0x8
        signed long scissor2addr; // offset 0x38, size 0x4
        struct /* @anon5 */ {
            // total size: 0x8
            unsigned long AC : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } prmodecont; // offset 0x40, size 0x8
        signed long prmodecontaddr; // offset 0x48, size 0x4
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned long CLAMP : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } colclamp; // offset 0x50, size 0x8
        signed long colclampaddr; // offset 0x58, size 0x4
        struct /* @anon10 */ {
            // total size: 0x8
            unsigned long DTHE : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } dthe; // offset 0x60, size 0x8
        signed long dtheaddr; // offset 0x68, size 0x4
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } test2; // offset 0x70, size 0x8
        signed long test2addr; // offset 0x78, size 0x4
    } draw02; // offset 0xE0, size 0x80
    struct /* @anon14 */ {
        // total size: 0x60
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } testa; // offset 0x0, size 0x8
        signed long testaaddr; // offset 0x8, size 0x4
        struct /* @anon34 */ {
            // total size: 0x8
            unsigned long PRIM : 3; // offset 0x0, size 0x4
            unsigned long IIP : 1; // offset 0x0, size 0x4
            unsigned long TME : 1; // offset 0x0, size 0x4
            unsigned long FGE : 1; // offset 0x0, size 0x4
            unsigned long ABE : 1; // offset 0x0, size 0x4
            unsigned long AA1 : 1; // offset 0x0, size 0x4
            unsigned long FST : 1; // offset 0x0, size 0x4
            unsigned long CTXT : 1; // offset 0x0, size 0x4
            unsigned long FIX : 1; // offset 0x0, size 0x4
            unsigned long pad11 : 53; // offset 0x0, size 0x4
        } prim; // offset 0x10, size 0x8
        signed long primaddr; // offset 0x18, size 0x4
        struct /* @anon9 */ {
            // total size: 0x8
            unsigned int R : 8; // offset 0x0, size 0x4
            unsigned int G : 8; // offset 0x0, size 0x4
            unsigned int B : 8; // offset 0x0, size 0x4
            unsigned int A : 8; // offset 0x0, size 0x4
            float Q; // offset 0x4, size 0x4
        } rgbaq; // offset 0x20, size 0x8
        signed long rgbaqaddr; // offset 0x28, size 0x4
        struct /* @anon25 */ {
            // total size: 0x8
            unsigned long X : 16; // offset 0x0, size 0x4
            unsigned long Y : 16; // offset 0x0, size 0x4
            unsigned long Z : 32; // offset 0x0, size 0x4
        } xyz2a; // offset 0x30, size 0x8
        signed long xyz2aaddr; // offset 0x38, size 0x4
        struct /* @anon25 */ {
            // total size: 0x8
            unsigned long X : 16; // offset 0x0, size 0x4
            unsigned long Y : 16; // offset 0x0, size 0x4
            unsigned long Z : 32; // offset 0x0, size 0x4
        } xyz2b; // offset 0x40, size 0x8
        signed long xyz2baddr; // offset 0x48, size 0x4
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } testb; // offset 0x50, size 0x8
        signed long testbaddr; // offset 0x58, size 0x4
    } clear0; // offset 0x160, size 0x60
    struct /* @anon23 */ {
        // total size: 0x10
        unsigned long NLOOP : 15; // offset 0x0, size 0x4
        unsigned long EOP : 1; // offset 0x0, size 0x4
        unsigned long pad16 : 16; // offset 0x0, size 0x4
        unsigned long id : 14; // offset 0x0, size 0x4
        unsigned long PRE : 1; // offset 0x0, size 0x4
        unsigned long PRIM : 11; // offset 0x0, size 0x4
        unsigned long FLG : 2; // offset 0x0, size 0x4
        unsigned long NREG : 4; // offset 0x0, size 0x4
        unsigned long REGS0 : 4; // offset 0x8, size 0x4
        unsigned long REGS1 : 4; // offset 0x8, size 0x4
        unsigned long REGS2 : 4; // offset 0x8, size 0x4
        unsigned long REGS3 : 4; // offset 0x8, size 0x4
        unsigned long REGS4 : 4; // offset 0x8, size 0x4
        unsigned long REGS5 : 4; // offset 0x8, size 0x4
        unsigned long REGS6 : 4; // offset 0x8, size 0x4
        unsigned long REGS7 : 4; // offset 0x8, size 0x4
        unsigned long REGS8 : 4; // offset 0x8, size 0x4
        unsigned long REGS9 : 4; // offset 0x8, size 0x4
        unsigned long REGS10 : 4; // offset 0x8, size 0x4
        unsigned long REGS11 : 4; // offset 0x8, size 0x4
        unsigned long REGS12 : 4; // offset 0x8, size 0x4
        unsigned long REGS13 : 4; // offset 0x8, size 0x4
        unsigned long REGS14 : 4; // offset 0x8, size 0x4
        unsigned long REGS15 : 4; // offset 0x8, size 0x4
    } giftag1; // offset 0x1C0, size 0x10
    struct /* @anon38 */ {
        // total size: 0x80
        struct /* @anon15 */ {
            // total size: 0x8
            unsigned long FBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 7; // offset 0x0, size 0x4
            unsigned long FBW : 6; // offset 0x0, size 0x4
            unsigned long pad22 : 2; // offset 0x0, size 0x4
            unsigned long PSM : 6; // offset 0x0, size 0x4
            unsigned long pad30 : 2; // offset 0x0, size 0x4
            unsigned long FBMSK : 32; // offset 0x0, size 0x4
        } frame1; // offset 0x0, size 0x8
        unsigned long frame1addr; // offset 0x8, size 0x4
        struct /* @anon30 */ {
            // total size: 0x8
            unsigned long ZBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 15; // offset 0x0, size 0x4
            unsigned long PSM : 4; // offset 0x0, size 0x4
            unsigned long pad28 : 4; // offset 0x0, size 0x4
            unsigned long ZMSK : 1; // offset 0x0, size 0x4
            unsigned long pad33 : 31; // offset 0x0, size 0x4
        } zbuf1; // offset 0x10, size 0x8
        signed long zbuf1addr; // offset 0x18, size 0x4
        struct /* @anon22 */ {
            // total size: 0x8
            unsigned long OFX : 16; // offset 0x0, size 0x4
            unsigned long pad16 : 16; // offset 0x0, size 0x4
            unsigned long OFY : 16; // offset 0x0, size 0x4
            unsigned long pad48 : 16; // offset 0x0, size 0x4
        } xyoffset1; // offset 0x20, size 0x8
        signed long xyoffset1addr; // offset 0x28, size 0x4
        struct /* @anon13 */ {
            // total size: 0x8
            unsigned long SCAX0 : 11; // offset 0x0, size 0x4
            unsigned long pad11 : 5; // offset 0x0, size 0x4
            unsigned long SCAX1 : 11; // offset 0x0, size 0x4
            unsigned long pad27 : 5; // offset 0x0, size 0x4
            unsigned long SCAY0 : 11; // offset 0x0, size 0x4
            unsigned long pad43 : 5; // offset 0x0, size 0x4
            unsigned long SCAY1 : 11; // offset 0x0, size 0x4
            unsigned long pad59 : 5; // offset 0x0, size 0x4
        } scissor1; // offset 0x30, size 0x8
        signed long scissor1addr; // offset 0x38, size 0x4
        struct /* @anon5 */ {
            // total size: 0x8
            unsigned long AC : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } prmodecont; // offset 0x40, size 0x8
        signed long prmodecontaddr; // offset 0x48, size 0x4
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned long CLAMP : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } colclamp; // offset 0x50, size 0x8
        signed long colclampaddr; // offset 0x58, size 0x4
        struct /* @anon10 */ {
            // total size: 0x8
            unsigned long DTHE : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } dthe; // offset 0x60, size 0x8
        signed long dtheaddr; // offset 0x68, size 0x4
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } test1; // offset 0x70, size 0x8
        signed long test1addr; // offset 0x78, size 0x4
    } draw11; // offset 0x1D0, size 0x80
    struct /* @anon8 */ {
        // total size: 0x80
        struct /* @anon15 */ {
            // total size: 0x8
            unsigned long FBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 7; // offset 0x0, size 0x4
            unsigned long FBW : 6; // offset 0x0, size 0x4
            unsigned long pad22 : 2; // offset 0x0, size 0x4
            unsigned long PSM : 6; // offset 0x0, size 0x4
            unsigned long pad30 : 2; // offset 0x0, size 0x4
            unsigned long FBMSK : 32; // offset 0x0, size 0x4
        } frame2; // offset 0x0, size 0x8
        unsigned long frame2addr; // offset 0x8, size 0x4
        struct /* @anon30 */ {
            // total size: 0x8
            unsigned long ZBP : 9; // offset 0x0, size 0x4
            unsigned long pad09 : 15; // offset 0x0, size 0x4
            unsigned long PSM : 4; // offset 0x0, size 0x4
            unsigned long pad28 : 4; // offset 0x0, size 0x4
            unsigned long ZMSK : 1; // offset 0x0, size 0x4
            unsigned long pad33 : 31; // offset 0x0, size 0x4
        } zbuf2; // offset 0x10, size 0x8
        signed long zbuf2addr; // offset 0x18, size 0x4
        struct /* @anon22 */ {
            // total size: 0x8
            unsigned long OFX : 16; // offset 0x0, size 0x4
            unsigned long pad16 : 16; // offset 0x0, size 0x4
            unsigned long OFY : 16; // offset 0x0, size 0x4
            unsigned long pad48 : 16; // offset 0x0, size 0x4
        } xyoffset2; // offset 0x20, size 0x8
        signed long xyoffset2addr; // offset 0x28, size 0x4
        struct /* @anon13 */ {
            // total size: 0x8
            unsigned long SCAX0 : 11; // offset 0x0, size 0x4
            unsigned long pad11 : 5; // offset 0x0, size 0x4
            unsigned long SCAX1 : 11; // offset 0x0, size 0x4
            unsigned long pad27 : 5; // offset 0x0, size 0x4
            unsigned long SCAY0 : 11; // offset 0x0, size 0x4
            unsigned long pad43 : 5; // offset 0x0, size 0x4
            unsigned long SCAY1 : 11; // offset 0x0, size 0x4
            unsigned long pad59 : 5; // offset 0x0, size 0x4
        } scissor2; // offset 0x30, size 0x8
        signed long scissor2addr; // offset 0x38, size 0x4
        struct /* @anon5 */ {
            // total size: 0x8
            unsigned long AC : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } prmodecont; // offset 0x40, size 0x8
        signed long prmodecontaddr; // offset 0x48, size 0x4
        struct /* @anon21 */ {
            // total size: 0x8
            unsigned long CLAMP : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } colclamp; // offset 0x50, size 0x8
        signed long colclampaddr; // offset 0x58, size 0x4
        struct /* @anon10 */ {
            // total size: 0x8
            unsigned long DTHE : 1; // offset 0x0, size 0x4
            unsigned long pad01 : 63; // offset 0x0, size 0x4
        } dthe; // offset 0x60, size 0x8
        signed long dtheaddr; // offset 0x68, size 0x4
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } test2; // offset 0x70, size 0x8
        signed long test2addr; // offset 0x78, size 0x4
    } draw12; // offset 0x250, size 0x80
    struct /* @anon14 */ {
        // total size: 0x60
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } testa; // offset 0x0, size 0x8
        signed long testaaddr; // offset 0x8, size 0x4
        struct /* @anon34 */ {
            // total size: 0x8
            unsigned long PRIM : 3; // offset 0x0, size 0x4
            unsigned long IIP : 1; // offset 0x0, size 0x4
            unsigned long TME : 1; // offset 0x0, size 0x4
            unsigned long FGE : 1; // offset 0x0, size 0x4
            unsigned long ABE : 1; // offset 0x0, size 0x4
            unsigned long AA1 : 1; // offset 0x0, size 0x4
            unsigned long FST : 1; // offset 0x0, size 0x4
            unsigned long CTXT : 1; // offset 0x0, size 0x4
            unsigned long FIX : 1; // offset 0x0, size 0x4
            unsigned long pad11 : 53; // offset 0x0, size 0x4
        } prim; // offset 0x10, size 0x8
        signed long primaddr; // offset 0x18, size 0x4
        struct /* @anon9 */ {
            // total size: 0x8
            unsigned int R : 8; // offset 0x0, size 0x4
            unsigned int G : 8; // offset 0x0, size 0x4
            unsigned int B : 8; // offset 0x0, size 0x4
            unsigned int A : 8; // offset 0x0, size 0x4
            float Q; // offset 0x4, size 0x4
        } rgbaq; // offset 0x20, size 0x8
        signed long rgbaqaddr; // offset 0x28, size 0x4
        struct /* @anon25 */ {
            // total size: 0x8
            unsigned long X : 16; // offset 0x0, size 0x4
            unsigned long Y : 16; // offset 0x0, size 0x4
            unsigned long Z : 32; // offset 0x0, size 0x4
        } xyz2a; // offset 0x30, size 0x8
        signed long xyz2aaddr; // offset 0x38, size 0x4
        struct /* @anon25 */ {
            // total size: 0x8
            unsigned long X : 16; // offset 0x0, size 0x4
            unsigned long Y : 16; // offset 0x0, size 0x4
            unsigned long Z : 32; // offset 0x0, size 0x4
        } xyz2b; // offset 0x40, size 0x8
        signed long xyz2baddr; // offset 0x48, size 0x4
        struct /* @anon18 */ {
            // total size: 0x8
            unsigned long ATE : 1; // offset 0x0, size 0x4
            unsigned long ATST : 3; // offset 0x0, size 0x4
            unsigned long AREF : 8; // offset 0x0, size 0x4
            unsigned long AFAIL : 2; // offset 0x0, size 0x4
            unsigned long DATE : 1; // offset 0x0, size 0x4
            unsigned long DATM : 1; // offset 0x0, size 0x4
            unsigned long ZTE : 1; // offset 0x0, size 0x4
            unsigned long ZTST : 2; // offset 0x0, size 0x4
            unsigned long pad19 : 45; // offset 0x0, size 0x4
        } testb; // offset 0x50, size 0x8
        signed long testbaddr; // offset 0x58, size 0x4
    } clear1; // offset 0x2D0, size 0x60
} NO_NAME_11; // size: 0x330, address: 0x112C7B0

typedef struct NO_NAME_17
{
	unsigned int num;
	NJS_TEXMEMLIST tmem[256];
	void* addr[256];
} NO_NAME_17;

typedef struct NO_NAME_18
{
	unsigned int Flag;
	GDFS_HANDLE* GdFs;
} NO_NAME_18;

typedef struct _HM _HM; 
struct _HM
{
	unsigned int Use_size;
	unsigned int Total_size;
	unsigned int dummy;
	_HM* pNext_work;
	unsigned int dummy64[12];
};

typedef struct NO_NAME_19
{
	unsigned short routine_0;
	unsigned short type;
	unsigned short act_lv[2];
	unsigned short be_flag;
	unsigned char act_data[8];
} NO_NAME_19;

typedef struct PLANE
{
	unsigned int xyzflag;
	unsigned int clipmask;
} PLANE;

typedef struct SCISSOR_PLANE
{
	PLANE plane[5];
	unsigned int planeNum;
} SCISSOR_PLANE;

typedef struct NODE
{
	sceVu0FVECTOR vertex;
	sceVu0FVECTOR color;
	sceVu0FVECTOR texUV;
	sceVu0FVECTOR clipV;
} NODE;

typedef struct SCISSOR_NODE
{
	NODE node[12];
	unsigned int nodeNum;
	float pad[3]; 
} SCISSOR_NODE;

typedef struct SCISSOR
{
	SCISSOR_NODE triangle;
	SCISSOR_NODE narray[2];
	SCISSOR_NODE* in;
	SCISSOR_NODE* out;
	unsigned int rotflag;
	unsigned int flipflag;
} SCISSOR;

typedef struct VU1_STRIP_BUF
{
	float fU;
	float fV;
	float fPad0;
	float fPad1;
	float fIr;
	float fIg;
	float fIb;
	float fA;
	float fVx;
	float fVy;
	float fVz;
	float fFog;
	float fSx;
	float fSy;
	float fIz;
	float fNz;
} VU1_STRIP_BUF;

typedef struct PAD_WORK
{
	// total size: 0x42
    unsigned short on; // offset 0x0, size 0x2
    unsigned short old; // offset 0x2, size 0x2
    unsigned short push; // offset 0x4, size 0x2
    unsigned short release; // offset 0x6, size 0x2
    short send; // offset 0x8, size 0x2
    unsigned short ad_flag; // offset 0xA, size 0x2
    unsigned char buff[2]; // offset 0xC, size 0x2
    unsigned short onon; // offset 0xE, size 0x2
    unsigned short repeat; // offset 0x10, size 0x2
    char time1[16]; // offset 0x12, size 0x10
    char time2[16]; // offset 0x22, size 0x10
    unsigned char rh; // offset 0x32, size 0x1
    unsigned char rv; // offset 0x33, size 0x1
    unsigned char lh; // offset 0x34, size 0x1
    unsigned char lv; // offset 0x35, size 0x1
    unsigned char au; // offset 0x36, size 0x1
    unsigned char ad; // offset 0x37, size 0x1
    unsigned char al; // offset 0x38, size 0x1
    unsigned char ar; // offset 0x39, size 0x1
    unsigned char abu; // offset 0x3A, size 0x1
    unsigned char abd; // offset 0x3B, size 0x1
    unsigned char abl; // offset 0x3C, size 0x1
    unsigned char abr; // offset 0x3D, size 0x1
    unsigned char al1; // offset 0x3E, size 0x1
    unsigned char al2; // offset 0x3F, size 0x1
    unsigned char ar1; // offset 0x40, size 0x1
    unsigned char ar2; // offset 0x41, size 0x1
} PAD_WORK;

typedef struct PAD
{
	// total size: 0x3C
    int PerType; // offset 0x0, size 0x4
    int OldPerType; // offset 0x4, size 0x4
    int PerTypeEx; // offset 0x8, size 0x4
    unsigned int Flag; // offset 0xC, size 0x4
    int SoftReset; // offset 0x10, size 0x4
    unsigned int on; // offset 0x14, size 0x4
    unsigned int press; // offset 0x18, size 0x4
    unsigned int Rept; // offset 0x1C, size 0x4
    unsigned int on2; // offset 0x20, size 0x4
    unsigned int on2old; // offset 0x24, size 0x4
    unsigned int press2; // offset 0x28, size 0x4
    unsigned short l; // offset 0x2C, size 0x2
    unsigned short r; // offset 0x2E, size 0x2
    short x1; // offset 0x30, size 0x2
    short y1; // offset 0x32, size 0x2
    short x2; // offset 0x34, size 0x2
    short y2; // offset 0x36, size 0x2
    short Calibrate; // offset 0x38, size 0x2
} PAD;

typedef struct DVDISO_DATA
{
	char* file_name;
	//char* link_file; original field from the debugging symbols, the below version matches better
    char** link_file;
} DVDISO_DATA;

typedef struct PS2_NJ_SAVE
{
	unsigned char mode_bk[2]; // offset 0x0, size 0x2
    unsigned char set_last; // offset 0x2, size 0x1
    unsigned char dc_alpha; // offset 0x3, size 0x1
    int mode; // offset 0x4, size 0x4
} PS2_NJ_SAVE;

typedef struct PS2_GS_SAVE
{
	unsigned long SC_TAG[2]; // offset 0x0, size 0x8
    unsigned long GIF_TAG[2]; // offset 0x10, size 0x8
    unsigned long TEX0; // offset 0x20, size 0x4
    unsigned long TEX0_TAG; // offset 0x28, size 0x4
    unsigned long TEX0_NEXT; // offset 0x30, size 0x4
    unsigned long TEX0_NEXT_TAG; // offset 0x38, size 0x4
    unsigned long TEX1; // offset 0x40, size 0x4
    unsigned long TEX1_TAG; // offset 0x48, size 0x4
    unsigned long CLAMP; // offset 0x50, size 0x4
    unsigned long CLAMP_TAG; // offset 0x58, size 0x4
    unsigned long TEST; // offset 0x60, size 0x4
    unsigned long TEST_TAG; // offset 0x68, size 0x4
    unsigned long FOGCOL; // offset 0x70, size 0x4
    unsigned long FOGCOL_TAG; // offset 0x78, size 0x4
    unsigned long ALPHA; // offset 0x80, size 0x4
    unsigned long ALPHA_TAG; // offset 0x88, size 0x4
    unsigned long FBA; // offset 0x90, size 0x4
    unsigned long FBA_TAG; // offset 0x98, size 0x4
    unsigned long SCISSOR; // offset 0xA0, size 0x4
    unsigned long SCISSOR_TAG; // offset 0xA8, size 0x4
    unsigned char mode_bk[2]; // offset 0xB0, size 0x2
    unsigned char set_last; // offset 0xB2, size 0x1
    unsigned char dc_alpha; // offset 0xB3, size 0x1
    unsigned int pad32; // offset 0xB4, size 0x4
    unsigned long pad64; // offset 0xB8, size 0x4
} PS2_GS_SAVE;

#define SCR_WIDTH 640
#define SCR_HEIGHT 224

#define GS_X_COORD(x) ((2048 - (SCR_WIDTH / 2) + x) * 16)
#define GS_Y_COORD(y) ((2048 - (SCR_HEIGHT / 2) + y) * 16)

#define WORKBASE (0x70000000)

#define DMAend  (7<<28)

#define    SCE_GS_FALSE         (0)
#define    SCE_GS_TRUE          (1)

#define SCE_GS_ALPHA_NEVER      (0)

#define    SCE_GS_AFAIL_KEEP    (0)
#define    SCE_GS_AFAIL_FB_ONLY (1)

#define SCE_GS_DEPTH_ALWAYS     (1)
#define SCE_GS_DEPTH_GEQUAL     (2)
#define SCE_GS_ALPHA_GEQUAL     (5)
#define SCE_GS_ALPHA_GREATER    (6)

#define SCE_GS_ALPHA_CS         (0)
#define SCE_GS_ALPHA_CD         (1)

#define SCE_GS_ALPHA_FIX        (2)

typedef struct PS2_OT_LIST
{
    int pad; // TODO: this is actually an empty struct 
} PS2_OT_LIST;

typedef struct PS2_OT
{
	NJS_TEXMEMLIST* tp;
	unsigned char mode_bk[2];
	unsigned char set_last;
	unsigned char dc_alpha;
	PS2_OT_LIST* op;
	void* p;
	unsigned long ALPHA;
	unsigned long TEX0;
	unsigned long TEX0_NEXT;
	unsigned int bank;
	unsigned int pad;
} PS2_OT;

typedef struct MOV_INFO
{
	unsigned char * mmp; // offset 0x0, size 0x4
    float Vol; // offset 0x4, size 0x4
    float VolSpeed; // offset 0x8, size 0x4
    float Fade; // offset 0xC, size 0x4
    float FadeSpeed; // offset 0x10, size 0x4
    short FrameCnt; // offset 0x14, size 0x2
    char ExecMovieSystemFlag; // offset 0x16, size 0x1
    char MovieCancelFlag; // offset 0x17, size 0x1
    char MovieFadeFlag; // offset 0x18, size 0x1
    char MovieFadeMode; // offset 0x19, size 0x1
    char MovieSystemLastError; // offset 0x1A, size 0x1
} MOV_INFO;

typedef struct PS2_TP_TAG
{
	unsigned long GIF_TAG[2]; // offset 0x0, size 0x8
    unsigned long TEX0; // offset 0x10, size 0x4
    unsigned long TEX0_TAG; // offset 0x18, size 0x4
    unsigned long TEX0_NEXT; // offset 0x20, size 0x4
    unsigned long TEX0_NEXT_TAG; // offset 0x28, size 0x4
    unsigned long CLAMP; // offset 0x30, size 0x4
    unsigned long CLAMP_TAG; // offset 0x38, size 0x4
} PS2_TP_TAG;

typedef struct PS2_TP_CACHE
{
	void * tp; // offset 0x0, size 0x4
    unsigned int bank; // offset 0x4, size 0x4
    unsigned int tex_addr; // offset 0x8, size 0x4
    unsigned int clt_addr; // offset 0xC, size 0x4
} PS2_TP_CACHE;

#define DMAref              (3<<28)

#define SCE_GS_CLAMP            (1)

// TODO: include sg_sybt.h and remove the below struct
struct tag_SYS_BT_SYSTEMID{                   /*                    */
    Sint32 nNo ;                              /*                    */
    Sint32 nAll ;                             /*                    */
    Sint8  szProduct[16];                     /*                    */
} ;                                           /*                    */
typedef struct tag_SYS_BT_SYSTEMID SYS_BT_SYSTEMID ;

/******** �������J�[�h���\���� *******************************************/
/******** Memory card information structure ********************************/
typedef struct {
	Uint16 Ready;               /* �������J�[�h���}�E���g����Ă��邩      */
	                            /* Is memory card mounted ?                */
	Uint16 IsFormat;            /* �t�H�[�}�b�g����Ă��邩�ǂ���          */
	                            /* Is memory card formatted ?              */
	Uint32 LastError;           /* �Ō�ɔ��������G���[�R�[�h              */
	                            /* Error code which occured last.          */
	Uint32 ProgressCount;       /* �����o�߃J�E���g                        */
	                            /* Operation progress count.               */
	Uint32 ProgressMax;         /* �����o�߃J�E���g�ő�                    */
	                            /* Operattion progress count maximum.      */
	Uint32 Operation;           /* �������̃I�y���[�V�����R�[�h            */
	                            /* Operation code in handling now.         */
	BUS_DISKINFO DiskInfo;      /* �h���C�u���                            */
	                            /* Drive information.                      */
	Uint32 Connect;             /* �������[�J�[�h���ڑ�����Ă��邩        */
	                            /* Is memory card connected ?              */
	void* Work;                 /* ���[�N�A�h���X                          */
	                            /* Work address.                           */
	Uint32 WorkSize;            /* ���[�N�T�C�Y                            */
	                            /* Work size (bytes).                      */
	Uint32 Capacity;            /* �������J�[�h�̗e�ʃt���O(BUD_CAPACITY)  */
	                            /* Capacity flag of memory card.           */
    Sint32 MemMode;             // manually added
} BACKUPINFO;

/*===============================================================*/
/* �Ή����郁�����[�J�[�h�̍ő�e��                              */
/* Mamimum volume to use.                                        */
/*===============================================================*/

#define MAX_CAPS BUD_CAPACITY_1MB

/*===============================================================*/
/* �Ή����郁�����[�J�[�h�̃h���C�u��                            */
/* Number of memory card to use.                                 */
/*===============================================================*/

#define MAX_DRIVES 8
#define USE_DRIVES BUD_USE_DRIVE_ALL

typedef struct BUF_QUEUE 
{
    char* from;               
    unsigned char* to;        
} BUF_QUEUE;

typedef struct EXPAND_STATUS 
{
    char active;              
    char mode;                
} EXPAND_STATUS;

typedef union EXPAND_CTRL 
{
    EXPAND_STATUS sb;      
    short check;              
} EXPAND_CTRL;

typedef union EXPAND_FLAG
{
    struct 
    {
        EXPAND_CTRL uw; 
        char in;              
        char out;             
    } sl;
    int abort;               
} EXPAND_FLAG;

typedef struct EXPAND_CTRL_BUF
{
    EXPAND_FLAG flag;        
    int code;                    
    int counter;                 
    int repeat;                  
    unsigned char* offset;       
    char* source;               
    unsigned char* destination;  
    BUF_QUEUE que[2];         
} EXPAND_CTRL_BUF;

typedef struct ADX_WORK
{
	unsigned int MaxChannel; // offset 0x0, size 0x4
    unsigned int MaxSampleRate; // offset 0x4, size 0x4
    int RecoverType; // offset 0x8, size 0x4
    int ReloadSector; // offset 0xC, size 0x4
} ADX_WORK;

typedef struct SND_CMD
{
	int MaxCommand; // offset 0x0, size 0x4
    unsigned char ComTbl[2]; // offset 0x4, size 0x2
} SND_CMD;
