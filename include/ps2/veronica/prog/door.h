#ifndef _DOOR_H_
#define _DOOR_H_

#include "types.h"

void bhInitDoor();
int bhReadDoorData();
void bhSetDoor();
void bhExitDoor();
/*int AnalyzeDoor(_door_wrk* dwP, int typ_no, int attr);*/
int bhControlDoor();
/*void ControlSoundTiming(_door_wrk* dwP);
void SetSoundTiming(_door_wrk* dwP);
void FadeProc1(_door_wrk* dwP);
void ViewProc1(_door_wrk* dwP);
void ViewProc2(_door_wrk* dwP);
void ViewProc3(_door_wrk* dwP);
void ViewProc4(_door_wrk* dwP);
void ViewProc5(_door_wrk* dwP);
void ViewProc6(_door_wrk* dwP);
void ViewProc7(_door_wrk* dwP);
void DoorProc1(_door_wrk* dwP);
void DoorProc2(_door_wrk* dwP);
void DoorProc3(_door_wrk* dwP);
void DoorProc4(_door_wrk* dwP);
void DoorProc5(_door_wrk* dwP);
void DoorProc6(_door_wrk* dwP);
void DoorProc7(_door_wrk* dwP);
void LightProc1(_door_wrk* dwP);
void LightProc2(_door_wrk* dwP);*/
int CompareSint32(int val_a, int cmp_typ, int val_b);
static int CompareFloat(float val_a, int cmp_typ, float val_b);
/*void VectorMove(_anon12* posP, int yaw, int pitch, float speed);
void LightSubAmb(_anon12* ambP, _anon12* offP);
void LightSubPnt(_door_wrk* dwP, int lgt_no, _anon35* ldP, _anon12* rteP);*/
void ryExcuteFade(float pri, int col, float rate);
/*void PuruProc1(_door_wrk* dwP);
void DokiProcLgt(_door_wrk* dwP);*/

/*typedef struct _anon0;
typedef struct _door_wrk;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct npobj;
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
typedef enum _enum;
typedef struct _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct _anon23;
typedef union _anon24;
typedef struct _anon25;
typedef struct _anon26;
typedef struct _anon27;
typedef struct _anon28;
typedef struct _anon29;
typedef struct BH_PWORK;
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
typedef struct _anon49;
typedef struct _anon50;
typedef struct _anon51;
typedef struct _anon52;
typedef struct _anon53;
typedef struct _anon54;
typedef struct _anon55;
typedef struct _anon56;
typedef struct _anon57;

typedef void(*type_7)(void*);
typedef void(*type_22)(void*);
typedef void(*type_40)(void*);
typedef void(*type_61)(void*);
typedef void(*type_71)(void*);
typedef void(*type_78)(void*);
typedef void(*type_91)(void*);

typedef char type_0[8];
typedef _anon1* type_1[512];
typedef _anon2* type_2[1300];
typedef _anon1* type_3[512];
typedef _anon2* type_4[200];
typedef _anon45 type_5[16];
typedef _anon1* type_6[128];
typedef unsigned int type_8[1];
typedef unsigned int type_9[32];
typedef _anon2* type_10[8];
typedef _anon1* type_11[128];
typedef int* type_12[16];
typedef _anon12 type_13[32];
typedef _anon1* type_14[128];
typedef npobj* type_15[16];
typedef int type_16[3];
typedef _anon2* type_17[16];
typedef _anon1* type_18[512];
typedef _anon14 type_19[16];
typedef int type_20[3];
typedef int type_21[1];
typedef _anon1* type_23[32];
typedef _anon5* type_24[128];
typedef _anon1* type_25[32];
typedef int type_26[11];
typedef unsigned char type_27[64];
typedef _anon1* type_28[32];
typedef float type_29[16];
typedef int type_30[3];
typedef int type_31[3];
typedef char type_32[32];
typedef int type_33[3];
typedef char type_34[8];
typedef short type_35[32];
typedef _anon27 type_36[1];
typedef _anon8 type_37[256];
typedef _anon41 type_38[2];
typedef int type_39[4];
typedef unsigned int type_41[4];
typedef _anon2* type_42[256];
typedef void* type_43[2];
typedef _anon41 type_44[8];
typedef _anon24 type_45[4];
typedef unsigned char* type_46[256];
typedef _anon41 type_47[2];
typedef char type_48[256];
typedef short type_49[256];
typedef float type_50[4];
typedef float type_51[4];
typedef float type_52[4];
typedef short type_53[256];
typedef unsigned int type_54[2];
typedef int type_55[8];
typedef int type_56[3];
typedef char type_57[3];
typedef _anon2* type_58[256];
typedef int type_59[3];
typedef _anon9 type_60[256];
typedef float type_62[3];
typedef int type_63[3];
typedef float type_64[3];
typedef _anon27 type_65[450];
typedef int type_66[3];
typedef int type_67[3];
typedef _anon33 type_68[2];
typedef int type_69[3];
typedef short type_70[256];
typedef _anon14 type_72[450];
typedef int type_73[64];
typedef int type_74[4];
typedef _anon35 type_75[3];
typedef _anon42 type_76[4];
typedef int type_77[450];
typedef _anon4 type_79[4];
typedef unsigned int type_80[8];
typedef unsigned char type_81[450];
typedef _anon31 type_82[4];
typedef _anon35 type_83[3];
typedef int type_84[16];
typedef int type_85[3];
typedef char type_86[16];
typedef int type_87[3];
typedef char type_88[4];
typedef unsigned int type_89[32];
typedef _anon35 type_90[3];
typedef _anon38 type_92[16];
typedef unsigned int type_93[16];
typedef unsigned int type_94[16];
typedef char type_95[3];
typedef unsigned int type_96[32];
typedef unsigned int type_97[16];
typedef _anon35 type_98[3];
typedef BH_PWORK* type_99[16];
typedef unsigned int type_100[8];
typedef float type_101[16][0];
typedef unsigned int type_102[384];
typedef unsigned int type_103[1];
typedef int type_104[3];
typedef unsigned int type_105[3];
typedef _anon41 type_106[8];
typedef unsigned int type_107[4];
typedef unsigned int type_108[2];
typedef int* type_109[16];
typedef npobj* type_110[16];
typedef unsigned char type_111[2];
typedef char type_112[4];
typedef _anon2* type_113[16];
typedef short type_114[4];
typedef char type_115[32];
typedef _anon14 type_116[16];
typedef unsigned char type_117[4];
typedef char type_118[64];
typedef _anon41 type_119[3];
typedef _anon55 type_120[64];
typedef _anon1* type_121[512];
typedef _anon55 type_122[64];
typedef _anon1* type_123[128];
typedef _anon55 type_124[64];
typedef char type_125[2];
typedef _anon1* type_126[512];
typedef unsigned char type_127[64];
typedef _anon1* type_128[512];
typedef unsigned int type_129[4];
typedef _anon1* type_130[512];
typedef _anon2* type_131[16];
typedef _anon1* type_132[512];
typedef _anon2* type_133[16][16];
typedef _anon2* type_134[16][16][100];

struct _anon0
{
	int wait;
	int snd_wait;
	int yaw;
	int pitch;
	float speed;
	float decel;
	float goal;
};

struct _door_wrk
{
	int dmo_atr;
	char dmo_typ;
	char cse_no;
	char dummy[2];
	int status;
	int dmo_mode;
	int time;
	int prti_no;
	int slot_no;
	void* dmo_bufP;
	void* dmo_prmP;
	void* tex_pacP;
	_enum spd_mde;
	void(*fde_prcP)(void*);
	int fde_mode;
	int fde_reg;
	void* fpP;
	float fde_rate;
	int fde_col;
	void(*vew_prcP)(void*);
	int vew_mode;
	int vew_reg;
	int vew_tmp;
	void* vpP;
	_anon12 vew_pos;
	_anon12 vew_bak;
	int vew_ang[3];
	int vew_ang_speed;
	int vew_yaw;
	int vew_pitch;
	float vew_speed;
	float vew_adj_pos;
	float vew_adj_ang;
	float vew_adj_pos_add;
	float vew_adj_ang_add;
	void(*dor_prcP)(void*);
	int dor_mode;
	int dor_reg;
	float dor_flt;
	int dor_snd;
	int dor_snd_exd;
	void* dpP;
	_anon14 dor_mdl;
	npobj* objP;
	_anon12 dor_bak;
	int dor_yaw;
	int dor_pitch;
	float dor_speed;
	int dor_ang_speed;
	void(*lgt_prcP)(void*);
	int lgt_mode;
	int lgt_reg;
	int lgt_atr[3];
	void* lpP;
	_anon12 lgt_amb_off;
	_anon12 lgt_pnt_rte;
	_anon35 lgt_buf[3];
	void(*pru_prcP)(void*);
	int pru_mode;
	int pru_reg;
	int pru_tim;
	void* ppP;
	int dki_mode;
	int BgmSet[16];
	_anon39 hrt_prm;
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
	_anon56 cspr;
	int pn;
	_anon42* pvp;
	_anon4* tvp;
	_anon42 pv[4];
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
	_anon27* textures;
	unsigned int nbTexture;
};

struct _anon3
{
	short fde_no;
	short fde_off;
	short vew_no;
	short vew_off;
	short dor_no;
	short dor_off;
	short lgt_no;
	short lgt_off;
	short pru_no;
	short pru_off;
};

struct npobj
{
	unsigned int evalflags;
	_anon37* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
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

struct _anon5
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon26* md2P;
	unsigned short* atrP;
};

struct _anon6
{
	float pos_y_low;
	int yaw_low;
	int pitch_low;
	float pos_y_high;
	int yaw_high;
	int pitch_high;
	int wait;
	int snd_wait;
	float speed;
	float accel;
	float goal;
	int cmp;
};

struct _anon7
{
	_anon12 pos_low;
	int ang_low[3];
	int dst_ang_low[3];
	float ang_rte_low;
	int yaw_low;
	int pitch_low;
	float speed_low;
	float accel_low;
	int speed_dx_low;
	int accel_dx_low;
	int loop_wait_low;
	_anon12 pos_high;
	int ang_high[3];
	int dst_ang_high[3];
	float ang_rte_high;
	int yaw_high;
	int pitch_high;
	float speed_high;
	float accel_high;
	int speed_dx_high;
	int accel_dx_high;
	int loop_wait_high;
	int pos_wait;
	int ang_wait;
	int slope_ax;
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
	int nob_wait;
	int nob_first;
	int nob_speed;
	int nob_accel;
	int nob_goal;
	int nob_cmp;
	int dor0_wait;
	int dor0_yaw;
	int dor0_pitch;
	float dor0_speed;
	float dor0_accel;
	int dor0_cmp;
	float dor0_goal;
	int wait;
	int snd_wait;
	int type;
};

struct _anon11
{
	int wait0;
	unsigned int color0;
	float rate0;
	float speed0;
	float goal0;
	int cmp0;
	int wait1;
	unsigned int color1;
	float rate1;
	float speed1;
	float goal1;
	int cmp1;
	int wait2;
};

struct _anon12
{
	float x;
	float y;
	float z;
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
	_anon53* info;
};

struct _anon14
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon2* texP;
	_anon32* owP;
};

struct _anon15
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

struct _anon16
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

struct _anon17
{
	_anon12 pos_low;
	int ang_low[3];
	_anon12 pos_high;
	int ang_high[3];
	int wait0;
	float fde_rte0;
	float fde_spd0;
	float fde_gol0;
	int fde_cmp0;
	int wait1;
	float fde_rte1;
	float fde_spd1;
	float fde_gol1;
	int fde_cmp1;
	int chg_vew;
};

enum _enum
{
	DMO_SPD_1,
	DMO_SPD_2,
	DMO_SPD_3
};

struct _anon18
{
	short u;
	short v;
};

struct _anon19
{
	_anon12 pos_low;
	_anon12 tgt_low;
	int roll_low;
	int yaw_low;
	int pitch_low;
	float speed_low;
	float accel_low;
	_anon12 pos_high;
	_anon12 tgt_high;
	int roll_high;
	int yaw_high;
	int pitxh_high;
	float speed_high;
	float accel_high;
	int wait;
};

struct _anon20
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct _anon21
{
	int wait_push;
	_anon12 pos_push;
	int wait_pull;
	_anon12 pos_pull;
	int ang[3];
	int vew0_yaw;
	int vew0_pitch;
	float vew0_speed;
	float vew0_accel;
	float vew0_goal_pz;
	int vew0_cmp;
	int vew0_goal_dy;
	int vew0_speed_dy;
	int vew0_cmp_dy;
};

struct _anon22
{
	void* texaddr;
	_anon15 texsurface;
};

struct _anon23
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

union _anon24
{
	unsigned int color;
	_anon18 tex;
	_anon20 argb;
};

struct _anon25
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
	_anon27 ef_tex[450];
	_anon2 ef_tlist;
	_anon48 ef;
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
	_anon22 ren_info;
	_anon27 ren_tex[1];
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
	_anon52 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon40* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon31 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon38 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon55* pl_htp;
	int costume;
	_anon12 hd_pos;
	_anon12 apos;
	_anon55* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon55 mwalp[64];
	_anon55 metcp[64];
	_anon55 mflrp[64];
	int dla_n;
	_anon55* htp;
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
	_anon16 door;
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
	_anon45 gatc[16];
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

struct _anon26
{
	void* p[2];
};

struct _anon27
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon28
{
	float mtrx[16];
	_anon12 pnt;
	_anon12 vctr;
	int stat;
	int reserve;
	_anon44 ltcal;
	_anon54 attr;
};

struct _anon29
{
	float a;
	float r;
	float g;
	float b;
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
	_anon57 watr;
	_anon23* cpcl;
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

struct _anon30
{
	int dor0_wait;
	int dor0_first;
	int dor0_speed;
	int dor0_accel;
	int dor0_goal_speed;
	int dor0_cmp;
	int dor1_wait;
	int dor1_speed;
	int dor1_accel;
	int dor1_goal_angle;
	int dor1_cmp;
	int dor1_decel;
	int snd_wait;
};

struct _anon31
{
	_anon12 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
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
	short dmo_typ;
	int prti_no;
	short vew_no;
	float near;
	float far;
};

struct _anon34
{
	_anon12 pos_low;
	int ang_low[3];
	_anon12 pos_high;
	int ang_high[3];
	int wait;
	int chg_vew;
};

struct _anon35
{
	unsigned int lgt_mod;
	float col_r;
	float col_g;
	float col_b;
	_anon12 pos;
	float n_rang;
	float f_rang;
};

struct _anon36
{
	char nam[3];
	char prm_num;
};

struct _anon37
{
	int* vlist;
	short* plist;
	_anon12 center;
	float r;
};

struct _anon38
{
	float x;
	float y;
};

struct _anon39
{
	int mode;
	int time;
	int wait;
};

struct _anon40
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
	_anon28* light;
};

struct _anon41
{
	void(*procP)(void*);
};

struct _anon42
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon43
{
	int wait_time;
	int loop_time;
	int snd_no;
	int pru_no;
	int pru_wait;
};

struct _anon44
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
	_anon29 atten;
	_anon29 amb;
	_anon29 dif;
	_anon29 spc;
	_anon29 mamb;
	_anon29 mdif;
	_anon29 mspc;
};

struct _anon45
{
	_anon12 c1;
	_anon12 c2;
	float r1;
	float r2;
};

struct _anon46
{
	float amb_r;
	float amb_g;
	float amb_b;
	int lgt_num;
	_anon35 lgt_dat[3];
};

struct _anon47
{
	_anon38* p;
	_anon24* col;
	_anon24* tex;
	unsigned int num;
};

struct _anon48
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

struct _anon49
{
	float amb_r_low;
	float amb_g_low;
	float amb_b_low;
	int lgt_num_low;
	_anon35 lgt_dat_low[3];
	float amb_r_high;
	float amb_g_high;
	float amb_b_high;
	int lgt_num_high;
	_anon35 lgt_dat_high[3];
};

struct _anon50
{
	_anon12 dst_pos_low;
	int dst_ang_low[3];
	_anon12 dst_pos_high;
	int dst_ang_high[3];
	int wait_pos;
	int wait_ang;
	_anon12 pos_rte;
	_anon12 ang_rte;
	int total_time;
	int chg_vew;
};

struct _anon51
{
	int nob_first;
	int nob_speed;
	int nob_accel;
	int nob_goal;
	int nob_cmp;
	int dor0_wait;
	int dor0_first;
	int dor0_speed;
	int dor0_accel;
	int dor0_goal_speed;
	int dor0_cmp;
	int dor1_wait;
	int dor1_speed;
	int dor1_accel;
	int dor1_goal_angle;
	int dor1_cmp;
	int dor1_decel;
	int wait;
	int snd_wait;
	int snd_wait1;
};

struct _anon52
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon53
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

struct _anon54
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
	_anon29 argb;
};

struct _anon55
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

struct _anon56
{
	_anon12 c;
	float r;
};

struct _anon57
{
	_anon12 c1;
	_anon12 c2;
	float r;
};*/

#endif
