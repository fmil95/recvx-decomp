#ifndef _EFFSUB3_H_
#define _EFFSUB3_H_

#include "types.h"

typedef struct OR_WORK 
{
    // total size: 0x4E0
    unsigned int flg; // offset 0x0, size 0x4
    unsigned short id; // offset 0x4, size 0x2
    signed char free0[10]; // offset 0x6, size 0xA
    float px; // offset 0x10, size 0x4
    float py; // offset 0x14, size 0x4
    float pz; // offset 0x18, size 0x4
    signed int ax; // offset 0x1C, size 0x4
    signed int ay; // offset 0x20, size 0x4
    signed int az; // offset 0x24, size 0x4
    signed char free1[24]; // offset 0x28, size 0x18
    float pxb; // offset 0x40, size 0x4
    float pyb; // offset 0x44, size 0x4
    float pzb; // offset 0x48, size 0x4
    signed int axb; // offset 0x4C, size 0x4
    signed int ayb; // offset 0x50, size 0x4
    signed int azb; // offset 0x54, size 0x4
    signed char free2[12]; // offset 0x58, size 0xC
    float lox; // offset 0x64, size 0x4
    float loy; // offset 0x68, size 0x4
    float loz; // offset 0x6C, size 0x4
    signed char free3[24]; // offset 0x70, size 0x18
    unsigned int stflg; // offset 0x88, size 0x4
    unsigned int Dummy; // offset 0x8C, size 0x4
    signed char free4[1092]; // offset 0x90, size 0x444
    void (* func)(void *); // offset 0x4D4, size 0x4
    signed int idx; // offset 0x4D8, size 0x4
    signed int Dummy2; // offset 0x4DC, size 0x4
} OR_WORK;

/*typedef struct npobj;
typedef struct NJS_POINT3;
typedef struct O_WRK;
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
typedef struct OR_WORK;
typedef struct _anon25;
typedef struct BH_PWORK;
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
typedef struct _eff30b_vtx_buf_typ;
typedef struct _rap_tex_typ;
typedef struct _anon36;
typedef struct _anon37;
typedef struct _anon38;
typedef struct _anon39;
typedef struct _anon40;
typedef struct _anon41;
typedef union _anon42;
typedef struct _anon43;
typedef struct _anon44;
typedef struct _anon45;
typedef struct _anon46;
typedef struct _anon47;
typedef struct _anon48;
typedef struct _anon49;
typedef struct _anon50;
typedef struct _anon51;
typedef struct _anon52;
typedef struct _anon53;
typedef struct _anon54;
typedef struct _anon55;
typedef struct _anon56;
typedef struct _anon57;
typedef struct _anon58;
typedef struct _anon59;
typedef struct _anon60;
typedef struct _rap_dsp_typ;
typedef struct _anon61;
typedef struct _anon62;
typedef struct _anon63;
typedef struct _anon64;
typedef struct _anon65;
typedef struct _anon66;
typedef struct _anon67;
typedef struct _anon68;
typedef struct _anon69;
typedef struct _anon70;
typedef struct _anon71;
typedef struct _anon72;
typedef struct _anon73;
typedef struct _anon74;
typedef struct _anon75;
typedef struct _anon76;
typedef struct _anon77;
typedef struct _anon78;
typedef struct _anon79;
typedef struct _anon80;
typedef struct _anon81;
typedef struct _anon82;

typedef void(*type_88)(OR_WORK*);
typedef void(*type_99)(O_WRK*);
typedef void(*type_144)(void*);
typedef void(*type_147)(void*);
typedef void(*type_150)(void*);
typedef void(*type_160)(OR_WORK*);
typedef void(*type_177)(OR_WORK*);
typedef void(*type_186)(OR_WORK*);
typedef void(*type_187)(OR_WORK*);
typedef void(*type_200)(OR_WORK*);

typedef float type_0[16];
typedef float* type_1[6];
typedef unsigned int type_2[4];
typedef O_WRK* type_3[512];
typedef float type_4[96];
typedef float type_5[18];
typedef O_WRK* type_6[32];
typedef _anon2 type_7[2];
typedef _anon5* type_8[16];
typedef O_WRK* type_9[32];
typedef O_WRK* type_10[512];
typedef _anon5* type_11[16][16];
typedef _anon5* type_12[16][16][100];
typedef char type_13[8];
typedef O_WRK* type_14[32];
typedef NJS_POINT3 type_15[2];
typedef O_WRK* type_16[512];
typedef _anon5* type_17[1300];
typedef _anon42 type_18[2];
typedef char type_19[32];
typedef float type_20[32];
typedef _anon12 type_21[2];
typedef O_WRK* type_22[512];
typedef _anon5* type_23[200];
typedef float type_24[6];
typedef short type_25[32];
typedef _anon45 type_26[1];
typedef O_WRK* type_27[128];
typedef unsigned int type_28[1];
typedef _anon2 type_29[2];
typedef _anon17 type_30[256];
typedef _anon5* type_31[8];
typedef int* type_32[16];
typedef O_WRK* type_33[128];
typedef _anon81 type_34[16];
typedef npobj* type_35[16];
typedef O_WRK* type_36[128];
typedef int type_37[4];
typedef _anon5* type_38[16];
typedef _anon2 type_39[2];
typedef _anon47 type_40[4];
typedef unsigned int type_41[4];
typedef float type_42[4];
typedef NJS_POINT3 type_43[96];
typedef _anon27 type_44[16];
typedef O_WRK* type_45[512];
typedef _anon9* type_46[10];
typedef float type_47[4];
typedef _anon12 type_48[4];
typedef char type_49[256];
typedef float type_50[4];
typedef float type_51[4];
typedef float type_52[4];
typedef float type_53[4];
typedef _anon13* type_54[128];
typedef _anon9 type_55[8];
typedef _anon2 type_56[2];
typedef float type_57[3];
typedef unsigned char type_58[64];
typedef float type_59[3][20];
typedef O_WRK type_60[0];
typedef float type_61[3];
typedef float type_62[3][20];
typedef _anon71 type_63[6];
typedef _anon2 type_64[2];
typedef _anon25 type_65[28];
typedef float type_66[3];
typedef float type_67[3][20];
typedef char type_68[8];
typedef int type_69[16];
typedef float type_70[3];
typedef float type_71[3][20];
typedef int type_72[16];
typedef int type_73[16];
typedef void* type_74[2];
typedef _anon57 type_75[8];
typedef NJS_POINT3 type_76[16];
typedef NJS_POINT3 type_77[2];
typedef NJS_POINT3 type_78[2][16];
typedef _anon2 type_79[1];
typedef unsigned int type_80[2];
typedef unsigned int type_81[2][16];
typedef _anon5* type_82[256];
typedef _anon2 type_83[1];
typedef int type_84[4];
typedef unsigned char* type_85[256];
typedef unsigned int type_86[2];
typedef short type_87[256];
typedef int type_89[4];
typedef _anon2 type_90[2];
typedef float type_91[5];
typedef _anon55 type_92[4];
typedef float type_93[3];
typedef short type_94[256];
typedef int type_95[5];
typedef int type_96[3];
typedef int type_97[8];
typedef float type_98[3];
typedef _anon6 type_100[4];
typedef void(*type_101)(O_WRK*)[4];
typedef _anon5* type_102[256];
typedef _anon23 type_103[256];
typedef _anon67 type_104[7];
typedef _anon2 type_105[2];
typedef _anon45 type_106[450];
typedef float type_107[5];
typedef char type_108[10];
typedef int type_109[5];
typedef _anon59 type_110[16];
typedef _anon2 type_111[2];
typedef _anon6 type_112[16];
typedef short type_113[256];
typedef char type_114[3];
typedef int type_115[64];
typedef NJS_POINT3 type_116[16];
typedef _anon27 type_117[450];
typedef unsigned int type_118[16];
typedef unsigned char type_119[2];
typedef unsigned char type_120[2][4];
typedef char type_121[24];
typedef int type_122[16];
typedef char type_123[4];
typedef unsigned int type_124[8];
typedef _anon66 type_125[4];
typedef _anon6 type_126[4];
typedef float type_127[3];
typedef _anon7 type_128[20];
typedef int type_129[450];
typedef _anon2 type_130[2];
typedef int type_131[3];
typedef unsigned int type_132[8];
typedef char type_133[12];
typedef unsigned char type_134[450];
typedef float type_135[128];
typedef _anon9 type_136[12];
typedef _anon2 type_137[1];
typedef _anon9 type_138[9];
typedef char type_139[24];
typedef _anon2 type_140[2];
typedef char type_141[1092];
typedef char type_142[64];
typedef char type_143[16];
typedef _anon6 type_145[4];
typedef char type_146[4];
typedef _anon43 type_148[2];
typedef unsigned int type_149[32];
typedef char type_151[6];
typedef char type_152[8];
typedef _anon34 type_153[19];
typedef unsigned char type_154[256];
typedef unsigned int type_155[16];
typedef _anon36 type_156[64];
typedef unsigned int type_157[16];
typedef _anon40 type_158[8];
typedef _anon2 type_159[1];
typedef _anon36 type_161[64];
typedef unsigned int type_162[32];
typedef _anon36 type_163[64];
typedef unsigned int type_164[16];
typedef unsigned int type_165[3];
typedef _anon2 type_166[1];
typedef BH_PWORK* type_167[16];
typedef int type_168[1024];
typedef unsigned int type_169[8];
typedef unsigned int type_170[1];
typedef unsigned int type_171[384];
typedef unsigned int type_172[2];
typedef unsigned char type_173[2];
typedef int* type_174[16];
typedef unsigned int type_175[4];
typedef _anon41 type_176[6];
typedef char type_178[32];
typedef npobj* type_179[16];
typedef char type_180[64];
typedef _anon5* type_181[16];
typedef char type_182[4];
typedef _anon2 type_183[1];
typedef _anon27 type_184[16];
typedef short type_185[4];
typedef unsigned char type_188[4];
typedef _anon63 type_189[16];
typedef _anon2 type_190[2];
typedef char type_191[192];
typedef _rap_tex_typ type_192[6];
typedef unsigned int type_193[8];
typedef unsigned int type_194[32];
typedef float type_195[16][0];
typedef unsigned int type_196[4];
typedef int type_197[18];
typedef int type_198[6];
typedef NJS_POINT3 type_199[32];
typedef int type_201[18];
typedef O_WRK* type_202[512];
typedef int type_203[6];
typedef NJS_POINT3 type_204[18];
typedef O_WRK* type_205[128];
typedef NJS_POINT3* type_206[6];
typedef NJS_POINT3 type_207[18];
typedef _anon2 type_208[1];
typedef NJS_POINT3 type_209[6];
typedef O_WRK* type_210[512];
typedef NJS_POINT3 type_211[18];
typedef unsigned char type_212[64];
typedef NJS_POINT3 type_213[16];
typedef _anon6 type_214[4];
typedef _anon2 type_215[2];
typedef O_WRK* type_216[512];

struct npobj
{
	unsigned int evalflags;
	_anon58* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct NJS_POINT3
{
	float x;
	float y;
	float z;
};

struct O_WRK
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
	_anon5* txp[16];
	_anon27 mdl[16];
	_anon27* mlwP;
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
	_anon13* mnwP;
	_anon13* mnwPb;
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
	_anon79 cspr;
	int pn;
	_anon66* pvp;
	_anon6* tvp;
	_anon66 pv[4];
	_anon6 tv[4];
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
	unsigned short mov_no;
	unsigned char col_lv;
	unsigned char drw_typ;
};

struct _anon3
{
	unsigned int flg;
	NJS_POINT3 vtx_pos[96];
};

struct _anon4
{
	_anon12 prm_a;
	_anon16 prm_b;
	int mode;
	int drw_num;
	int TimBuf[16];
	int ColAdd[16];
	int ColSub[16];
	NJS_POINT3 VtxDir[16];
	NJS_POINT3 VtxBuf[2][16];
	unsigned int VtxCol[2][16];
	_anon62 lne_p3c;
	float wnd_spd;
	float wnd_acl;
};

struct _anon5
{
	_anon45* textures;
	unsigned int nbTexture;
};

struct _anon6
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon7
{
	float vtx_speed;
	float vtx_accel;
	float ang_rand;
	float pos_rand;
	float spd_rand;
	float vtx_scale;
	int stg_erase;
	char stg_timer[6];
	NJS_POINT3 vtx_gravity;
};

struct _anon8
{
	_anon82 prm_a;
	int mode;
	int ang_x;
	int ang_y;
	NJS_POINT3 off_pos;
	NJS_POINT3 dst_pos;
};

struct _anon9
{
	float u;
	float v;
	float xs;
	float ys;
};

struct _anon10
{
	float px;
	float py;
	float pz;
	int ay;
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
	_anon5* et_lp[16][16][100];
	_anon5* ot_lp[1300];
	_anon5* it_lp[200];
	int eft_n;
	_anon5* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon28* p1per;
	_anon28* p2per;
	_anon28* kbper;
	_anon28* msper;
	_anon28 ms_per;
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
	O_WRK* obwp;
	O_WRK* itwp;
	_anon13* emtp[128];
	_anon13* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	_anon5* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon5* txblp[256];
	_anon23 txbp[256];
	unsigned char* ef_psp;
	_anon45 ef_tex[450];
	_anon5 ef_tlist;
	_anon69 ef;
	short efid[256];
	_anon27 efm[450];
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
	O_WRK* ef_pol[512];
	O_WRK* ef_mdf[128];
	O_WRK* ef_lin[512];
	O_WRK* ef_ntx[512];
	O_WRK* ef_trs[512];
	O_WRK* ef_pnc[512];
	O_WRK* ef_opq[512];
	O_WRK* ef_thl[512];
	O_WRK* ef_ntx2d[128];
	O_WRK* ef_trs2d[128];
	O_WRK* ef_pnc2d[128];
	O_WRK* ef_fnc[512];
	int ob_nlgn;
	int ob_hlgn;
	int ob_spcn;
	O_WRK* ob_nlg[32];
	O_WRK* ob_hlg[32];
	O_WRK* ob_spc[32];
	unsigned int ren_gid;
	_anon39 ren_info;
	_anon45 ren_tex[1];
	_anon5 ren_tlist;
	_anon17 rpb[256];
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
	_anon73 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon30* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon55 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon59 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon36* pl_htp;
	int costume;
	NJS_POINT3 hd_pos;
	NJS_POINT3 apos;
	_anon36* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon36 mwalp[64];
	_anon36 metcp[64];
	_anon36 mflrp[64];
	int dla_n;
	_anon36* htp;
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
	_anon5* sb_tlist;
	int ddmd;
	_anon32 door;
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
	_anon63 gatc[16];
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
};

struct _anon12
{
	int vtx_num;
	float speed;
	float accel;
	float scale;
	int time;
	float ang_rand;
	float spd_rand;
	int tim_rand;
	float gravity;
};

struct _anon13
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon44* md2P;
	unsigned short* atrP;
};

struct _anon14
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon81 keyf[16];
};

struct _anon15
{
	_anon26* cutp;
	_anon30* lgtp;
	_anon31* enep;
	_anon31* objp;
	_anon31* itmp;
	_anon35* effp;
	_anon36* walp;
	_anon36* etcp;
	_anon36* flrp;
	_anon10* posp;
	_anon36* rutp;
	unsigned char* ruttp;
	_anon48* evtp;
	_anon14* evcp;
	unsigned int* mesp;
	_anon30* evlp;
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
	_anon27 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};

struct _anon16
{
	NJS_POINT3 vtx_pos;
	NJS_POINT3 vtx_dir;
	unsigned int col_src;
	unsigned int col_dst;
	float gnd_hgh;
};

struct _anon17
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon18
{
	unsigned int flg;
	int stg_stt;
	int stg_num;
	int vtx_num;
	float pos_rand;
	float spd_rand;
	float vtx_speed;
	float vtx_accel;
	int stg_erase;
	float scale;
	unsigned int src_col;
	unsigned int dst_col;
	int col_add;
	int col_sub;
	NJS_POINT3* vtx_bufP;
	NJS_POINT3 vtx_gravity;
	NJS_POINT3 pos_bak;
	char atr_bak[192];
	int stg_col[6];
	int stg_tim[6];
	NJS_POINT3* stg_buf[6];
	NJS_POINT3 stg_grv[6];
	NJS_POINT3 vtx_dir[16];
	float* stg_spd[6];
	float vtx_spd[96];
	_anon62 lne_p3c;
	NJS_POINT3 lne_pnt[2];
	_anon42 lne_col[2];
	float stg_scl[6];
	float scl_add_1st;
	float scl_add_2nd;
};

struct _anon19
{
	_anon41 prm_a;
	_anon38 prm_b;
	int mode;
	int type;
	int time;
	_anon5* texP;
	int tex_id;
	float eff_scale;
	_eff30b_vtx_buf_typ* vtx_bufP;
};

struct _anon20
{
	_anon9* uv_tabP;
	int anm_no;
	int color;
	int col_add;
	int col_sub;
};

struct _anon21
{
	float vtx_scl;
	NJS_POINT3 vtx_pos;
	_anon6 VtxBuf[4];
};

struct _anon22
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

struct _anon23
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct OR_WORK
{
	unsigned int flg;
	unsigned short id;
	char free0[10];
	float px;
	float py;
	float pz;
	int ax;
	int ay;
	int az;
	char free1[24];
	float pxb;
	float pyb;
	float pzb;
	int axb;
	int ayb;
	int azb;
	char free2[12];
	float lox;
	float loy;
	float loz;
	char free3[24];
	unsigned int stflg;
	unsigned int Dummy;
	char free4[1092];
	void(*func)(void*);
	int idx;
	int Dummy2;
};

struct _anon25
{
	short time;
	short scl_time;
	float spd;
	float grv;
	int col;
	float scl;
	NJS_POINT3 dir;
	NJS_POINT3 pos;
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
	_anon5* txp[16];
	_anon27 mdl[16];
	_anon27* mlwP;
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
	_anon13* mnwP;
	_anon13* mnwPb;
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
	_anon80 watr;
	_anon46* cpcl;
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

struct _anon26
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon29* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon43 cam[2];
	unsigned char exd[256];
};

struct _anon27
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon5* texP;
	_anon53* owP;
};

struct _anon28
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
	_anon76* info;
};

struct _anon29
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

struct _anon30
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
	_anon54* light;
};

struct _anon31
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

struct _anon32
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

struct _anon33
{
	short u;
	short v;
};

struct _anon34
{
	int set_num;
	_anon2* pdP;
};

struct _anon35
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

struct _eff30b_vtx_buf_typ
{
	unsigned int flg;
	_eff30b_vtx_buf_typ* nextP;
	_anon25 VtxBuf[28];
};

struct _rap_tex_typ
{
	_rap_tex_typ* nextP;
	int mode;
	_anon21 dsp_wrk;
	_rap_dsp_typ mov_wrk;
	_anon20 anm_wrk;
};

struct _anon36
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

struct _anon37
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct _anon38
{
	float vtx_mtxP[16];
	NJS_POINT3 vtx_pos;
	NJS_POINT3 vtx_dir;
};

struct _anon39
{
	void* texaddr;
	_anon22 texsurface;
};

struct _anon40
{
	int anm_no;
	unsigned int color;
	float speed;
	int time;
};

struct _anon41
{
	float vtx_sp_min;
	float vtx_sp_max;
	float vtx_accel;
	float ang_rand;
	float vtx_scale;
	int vtx_erase;
	unsigned int col_src;
	unsigned int col_dst;
	float vtx_gravity;
	int vtx_num;
	int eff_erase;
	float eff_rate;
};

union _anon42
{
	unsigned int color;
	_anon33 tex;
	_anon37 argb;
};

struct _anon43
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

struct _anon44
{
	void* p[2];
};

struct _anon45
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon46
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon47
{
	unsigned int color;
	float speed;
	float accel;
	int time;
	float offset;
	float src_scl;
	float dst_scl;
};

struct _anon48
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon49
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon50
{
	float vtx_mtxP[16];
	NJS_POINT3 vtx_pos;
	NJS_POINT3 vtx_dir;
};

struct _anon51
{
	_anon75 eff_prm;
	int mode0;
	int entry;
	int vtx_top;
	int vtx_num;
	float spl_frm;
	float tex_frm;
	int VtxAlp[18];
	int VtxCol[18];
	NJS_POINT3 VtxDir[18];
	NJS_POINT3 VtxBufS[18];
	NJS_POINT3 VtxBufD[18];
	_anon6 poly[4];
	float wnd_acl;
	float WndSpd[18];
};

struct _anon52
{
	NJS_POINT3 off_pos;
	int srd_dir;
	float srd_pos;
	float bld_spd;
	float srt_spd[5];
	int srt_dir[5];
};

struct _anon53
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon54
{
	float mtrx[16];
	NJS_POINT3 pnt;
	NJS_POINT3 vctr;
	int stat;
	int reserve;
	_anon64 ltcal;
	_anon78 attr;
};

struct _anon55
{
	NJS_POINT3 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon56
{
	_anon71 prm_a;
	_anon50 prm_b;
	int mode;
	int type;
	_rap_tex_typ* busyP;
	_rap_tex_typ* freeP;
	_rap_tex_typ RapTex[6];
	_anon5* texP;
	int tex_id;
};

struct _anon57
{
	int tex_id;
	int wait;
	int time0;
	int time1;
	float offset;
	float src_scl;
	float dst_scl;
};

struct _anon58
{
	int* vlist;
	short* plist;
	NJS_POINT3 center;
	float r;
};

struct _anon59
{
	float x;
	float y;
};

struct _anon60
{
	unsigned int flg;
	int eff_dir;
	int srd_dir;
	float srd_pos;
	float bld_spd;
	float srt_spd[5];
	int srt_vtx[5];
	_anon6 tv_buf[16];
	NJS_POINT3 tv_spd[16];
};

struct _rap_dsp_typ
{
	NJS_POINT3 vtx_vel;
};

struct _anon61
{
	_anon65 prm;
	int mode;
	int erase;
	float mtxP[16];
	char mtx_buf[64];
};

struct _anon62
{
	NJS_POINT3* p;
	_anon42* col;
	_anon42* tex;
	unsigned int num;
};

struct _anon63
{
	NJS_POINT3 c1;
	NJS_POINT3 c2;
	float r1;
	float r2;
};

struct _anon64
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
	NJS_POINT3 lpnt;
	NJS_POINT3 lvctr;
	NJS_POINT3 lmvctr;
	_anon49 atten;
	_anon49 amb;
	_anon49 dif;
	_anon49 spc;
	_anon49 mamb;
	_anon49 mdif;
	_anon49 mspc;
};

struct _anon65
{
	float mtxP[16];
	_anon5* texP;
	_anon68* mdlP;
	float pos[3];
	int ang[3];
};

struct _anon66
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon67
{
	unsigned int color;
	float vtx_range;
	float ang_rand;
};

struct _anon68
{
	NJS_POINT3* points;
	NJS_POINT3* normals;
	int nbPoint;
	_anon77* meshsets;
	_anon72* mats;
	unsigned short nbMeshset;
	unsigned short nbMat;
	NJS_POINT3 center;
	float r;
};

struct _anon69
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

struct _anon70
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

struct _anon71
{
	float speed;
	float accel;
	float scale;
	float scl_accel;
	char SetTim[8];
	float ang_rand;
	float spd_rand;
	unsigned int col_src;
	unsigned int col_dst;
	float gravity;
	int pal_bank;
};

struct _anon72
{
	_anon42 diffuse;
	_anon42 specular;
	float exponent;
	unsigned int attr_texId;
	unsigned int attrflags;
};

struct _anon73
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon74
{
	void(*fnc_prcP)(void*);
	void(*fnc_drwP)(OR_WORK*);
	int free[1024];
};

struct _anon75
{
	float mtxP[16];
	NJS_POINT3 src;
	NJS_POINT3 dst;
	float frm_inc;
	int col;
	int tim;
	_anon5* texP;
	int tex_id;
};

struct _anon76
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

struct _anon77
{
	unsigned short type_matId;
	unsigned short nbMesh;
	short* meshes;
	unsigned int* attrs;
	NJS_POINT3* normals;
	_anon42* vertcolor;
	_anon42* vertuv;
};

struct _anon78
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
	_anon49 argb;
};

struct _anon79
{
	NJS_POINT3 c;
	float r;
};

struct _anon80
{
	NJS_POINT3 c1;
	NJS_POINT3 c2;
	float r;
};

struct _anon81
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

struct _anon82
{
	int type;
	int ang_fst;
	int add_ax;
	float x_rang;
	float x_rate;
	int add_ay;
	float y_rang;
	float y_rate;
};*/

static O_WRK* AllocOwork();
O_WRK* AllocOworkOne();
void bhClrEff_RY();
int bhSetBloodPoolLnk(BH_PWORK* ewP, NJS_POINT3* posP, int ay, BP_WORK* tabP, int pal_bnk);
void bhEff300(O_WRK* oP);
void bhEff301(O_WRK* oP);
O_WRK* bhSetEffParticle(BH_PWORK* ewP, int lnk_no, NJS_POINT3* offP, NJS_POINT3* dirP, unsigned int color, int typ_no);
O_WRK* bhSetEffParticleMk2(BH_PWORK* ewP, int lnk_no, NJS_POINT3* offP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no);
void bhEff302(O_WRK* oP);
void bhEff_PtclSpriteDrawB(O_WRK* oP);
void bhEff_PtclLineDraw(O_WRK* oP);
void bhEff303(O_WRK* oP);
int bhCheckCamWall2D(NJS_POINT3* srcP, NJS_POINT3* vctP, NJS_POINT3* rtnP, float rng_x, float rng_y);
O_WRK* rySetShadow(BH_PWORK* ewP, int obj0, int obj1, int obj2, float off_a, float off_b);
void bhEff304(O_WRK* oP);
void bhEff305(O_WRK* oP);
void bhEff306(O_WRK* oP);
OR_WORK* bhSetRapEff(int eff_no, void* datP, int lng_siz);
void bhEff307(OR_WORK* orP);
void bhEff307Drw(OR_WORK* orP);
void bhSetEffGunSpark(NJS_POINT3* posP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no);
void bhSetEffSpark(NJS_POINT3* posP, NJS_POINT3* dirP, unsigned int src_col, unsigned int dst_col, int typ_no);
void bhEff308(OR_WORK* orP);
void bhEff308Drw(OR_WORK* orP);
int ryLinerColor(int src_col, int dst_col, float rate);
OR_WORK* rySetEffBlood(float mtxP[16], NJS_POINT3* posP, NJS_POINT3* dirP, int typ_no);
void bhEff309(OR_WORK* orP);
void bhEff309Drw(OR_WORK* orP);
/*void ryRapTexDrw(_anon5* texP, int tex_id, _rap_tex_typ* rtP);
int ryRapTexAnm(_anon20* anmP, _anon21* dspP, int bol);
void ryRapDspSet(NJS_POINT3* posP, _anon21* dspP, float scl);
void ryRapAnmColSet(_anon20* anmP, int src_col, int dst_col, int col_cnt);*/
void bhEff30a(OR_WORK* orP);
void bhEff349(OR_WORK* orP);
OR_WORK* rySetEffBlood2(float mtxP[16], NJS_POINT3* posP, NJS_POINT3* dirP, int typ_no);
void bhEff30b(OR_WORK* orP);
void bhEff30bDrw(OR_WORK* orP);
void bhEff30c(OR_WORK* orP);
void bhEff30cDrw(OR_WORK* orP);

#endif
