#ifndef _MAIN_H_
#define _MAIN_H_

typedef struct CAM_WORK 
{
    // total size: 0x4AC
    unsigned int flg;     // offset 0x0, size 0x4
    int camver;           // offset 0x4, size 0x4
    unsigned char mode0;  // offset 0x8, size 0x1
    unsigned char mode1;  // offset 0x9, size 0x1
    unsigned char mode2;  // offset 0xA, size 0x1
    unsigned char mode3;  // offset 0xB, size 0x1
    float px;             // offset 0xC, size 0x4
    float py;             // offset 0x10, size 0x4
    float pz;             // offset 0x14, size 0x4
    float vx;             // offset 0x18, size 0x4
    float vy;             // offset 0x1C, size 0x4
    float vz;             // offset 0x20, size 0x4
    float wpx;            // offset 0x24, size 0x4
    float wpy;            // offset 0x28, size 0x4
    float wpz;            // offset 0x2C, size 0x4
    float plx;            // offset 0x30, size 0x4
    float ply;            // offset 0x34, size 0x4
    float plz;            // offset 0x38, size 0x4
    float pxp;            // offset 0x3C, size 0x4
    float pyp;            // offset 0x40, size 0x4
    float pzp;            // offset 0x44, size 0x4
    float ofx;            // offset 0x48, size 0x4
    float ofy;            // offset 0x4C, size 0x4
    float ofz;            // offset 0x50, size 0x4
    int ax;               // offset 0x54, size 0x4
    int ay;               // offset 0x58, size 0x4
    int az;               // offset 0x5C, size 0x4
    int axp;              // offset 0x60, size 0x4
    int ayp;              // offset 0x64, size 0x4
    int azp;              // offset 0x68, size 0x4
    float ln;             // offset 0x6C, size 0x4
    float pln;            // offset 0x70, size 0x4
    float xr;             // offset 0x74, size 0x4
    float xn;             // offset 0x78, size 0x4
    float yr;             // offset 0x7C, size 0x4
    float yn;             // offset 0x80, size 0x4
    int pers;             // offset 0x84, size 0x4
    int ppers;            // offset 0x88, size 0x4
    int ncut;             // offset 0x8C, size 0x4
    int ocut;             // offset 0x90, size 0x4
    unsigned int ocflg;   // offset 0x94, size 0x4
    unsigned int attr;    // offset 0x98, size 0x4
    float (*mtx)[16];     // offset 0x9C, size 0x4
    float (*mtxb)[16];    // offset 0xA0, size 0x4
    int evc_no;           // offset 0xA4, size 0x4
    int hct;              // offset 0xA8, size 0x4
    int ct0;              // offset 0xAC, size 0x4
    int ct1;              // offset 0xB0, size 0x4
    int keyf_no;          // offset 0xB4, size 0x4
    float frm;            // offset 0xB8, size 0x4
    float spd;            // offset 0xBC, size 0x4
    float pxn;            // offset 0xC0, size 0x4
    float pyn;            // offset 0xC4, size 0x4
    float pzn;            // offset 0xC8, size 0x4
    int axn;              // offset 0xCC, size 0x4
    int ayn;              // offset 0xD0, size 0x4
    int azn;              // offset 0xD4, size 0x4
    int pe_ax;            // offset 0xD8, size 0x4
    int pe_pers;          // offset 0xDC, size 0x4
    unsigned int fog_col; // offset 0xE0, size 0x4
    float fog_nr;         // offset 0xE4, size 0x4
    float fog_fr;         // offset 0xE8, size 0x4
    float ips[20][3];     // offset 0xEC, size 0xF0
    float ian[20][3];     // offset 0x1DC, size 0xF0
    float ipf[20][3];     // offset 0x2CC, size 0xF0
    float icr[20][3];     // offset 0x3BC, size 0xF0
} CAM_WORK;

typedef struct GATC
{
    // total size: 0x20
	NJS_POINT3 c1; // offset 0x0, size 0xC
	NJS_POINT3 c2; // offset 0xC, size 0xC
	float r1;      // offset 0x18, size 0x4
    float r2;      // offset 0x1C, size 0x4
} GATC;

typedef struct HWS_WORK
{
	// total size: 0x24
    int mode;      // offset 0x0, size 0x4
    int frame;     // offset 0x4, size 0x4
    int count;     // offset 0x8, size 0x4
    int vtx_opq_a; // offset 0xC, size 0x4
    int vtx_opq_b; // offset 0x10, size 0x4
    int vtx_trs_a; // offset 0x14, size 0x4
    int vtx_trs_b; // offset 0x18, size 0x4
    int vtx_punch; // offset 0x1C, size 0x4
    int vtx_total; // offset 0x20, size 0x4
} HWS_WORK;

typedef struct ROM_WORK
{
    // total size: 0x3EC
	CUT_WORK* cutp;       // offset 0x0, size 0x4
	LGT_WORK* lgtp;       // offset 0x4, size 0x4
	ETTY_WORK* enep;      // offset 0x8, size 0x4
	ETTY_WORK* objp;      // offset 0xC, size 0x4
	ETTY_WORK* itmp;      // offset 0x10, size 0x4
	EF_WRK* effp;         // offset 0x14, size 0x4
	ATR_WORK* walp;       // offset 0x18, size 0x4
	ATR_WORK* etcp;       // offset 0x1C, size 0x4
	ATR_WORK* flrp;       // offset 0x20, size 0x4
	POS* posp;            // offset 0x24, size 0x4
	ATR_WORK* rutp;       // offset 0x28, size 0x4
	unsigned char* ruttp; // offset 0x2C, size 0x4
	EVT_WORK* evtp;       // offset 0x30, size 0x4
	EVC_WORK* evcp;       // offset 0x34, size 0x4
	unsigned int* mesp;   // offset 0x38, size 0x4
	LGT_WORK* evlp;       // offset 0x3C, size 0x4
	unsigned char* dmp00; // offset 0x40, size 0x4
    unsigned char* dmp01; // offset 0x44, size 0x4
    unsigned char* dmp02; // offset 0x48, size 0x4
    unsigned char* dmp03; // offset 0x4C, size 0x4
    unsigned char* dmp04; // offset 0x50, size 0x4
    unsigned char* dmp05; // offset 0x54, size 0x4
    unsigned char* dmp06; // offset 0x58, size 0x4
    unsigned char* dmp07; // offset 0x5C, size 0x4
    unsigned char* dmp08; // offset 0x60, size 0x4
    unsigned char* dmp09; // offset 0x64, size 0x4
    unsigned char* dmp10; // offset 0x68, size 0x4
    unsigned char* dmp11; // offset 0x6C, size 0x4
    unsigned char* dmp12; // offset 0x70, size 0x4
    unsigned char* dmp13; // offset 0x74, size 0x4
    unsigned char* dmp14; // offset 0x78, size 0x4
    unsigned char* dmp15; // offset 0x7C, size 0x4
    int cut_n;            // offset 0x80, size 0x4
    int lgt_n;            // offset 0x84, size 0x4
    int ene_n;            // offset 0x88, size 0x4
    int obj_n;            // offset 0x8C, size 0x4
    int itm_n;            // offset 0x90, size 0x4
    int eff_n;            // offset 0x94, size 0x4
    int wal_n;            // offset 0x98, size 0x4
    int etc_n;            // offset 0x9C, size 0x4
    int flr_n;            // offset 0xA0, size 0x4
    int pos_n;            // offset 0xA4, size 0x4
    int rut_n;            // offset 0xA8, size 0x4
    int evc_n;            // offset 0xAC, size 0x4
    int mes_n;            // offset 0xB0, size 0x4
    int evl_n;            // offset 0xB4, size 0x4
    int dmy00;            // offset 0xB8, size 0x4
    int dmy01;            // offset 0xBC, size 0x4
    int dmy02;            // offset 0xC0, size 0x4
    int dmy03;            // offset 0xC4, size 0x4
    int dmy04;            // offset 0xC8, size 0x4
    int dmy05;            // offset 0xCC, size 0x4
    int dmy06;            // offset 0xD0, size 0x4
    int dmy07;            // offset 0xD4, size 0x4
    int dmy08;            // offset 0xD8, size 0x4
    int dmy09;            // offset 0xDC, size 0x4
    int dmy10;            // offset 0xE0, size 0x4
    int dmy11;            // offset 0xE4, size 0x4
    int dmy12;            // offset 0xE8, size 0x4
    int dmy13;            // offset 0xEC, size 0x4
    int dmy14;            // offset 0xF0, size 0x4
    int dmy15;            // offset 0xF4, size 0x4
    int dmy16;            // offset 0xF8, size 0x4
    int dmy17;            // offset 0xFC, size 0x4
    unsigned int flg;     // offset 0x100, size 0x4
    unsigned int bak_col; // offset 0x104, size 0x4
    unsigned int fog_col; // offset 0x108, size 0x4
    float fog_nr;         // offset 0x10C, size 0x4
    float fog_fr;         // offset 0x110, size 0x4
    float w;              // offset 0x114, size 0x4
    float h;              // offset 0x118, size 0x4
    float d;              // offset 0x11C, size 0x4
    float grand[32];      // offset 0x120, size 0x80
	ML_WORK mdl;          // offset 0x1A0, size 0x18
	float fog[128];       // offset 0x1B8, size 0x200
    char amb_rom;         // offset 0x3B8, size 0x1
    char amb_chr;         // offset 0x3B9, size 0x1
    char amb_obj;         // offset 0x3BA, size 0x1
    char amb_itm;         // offset 0x3BB, size 0x1
    float amb_r[4];       // offset 0x3BC, size 0x10
    float amb_g[4];       // offset 0x3CC, size 0x10
    float amb_b[4];       // offset 0x3DC, size 0x10
} ROM_WORK;

typedef struct SYS_WORK
{
	// total size: 0x2ACF0
    unsigned int ssd_ver;            // offset 0x0, size 0x4
    unsigned int ssd_flg;            // offset 0x4, size 0x4
    unsigned int ssd_reserve;        // offset 0x8, size 0x4
    char keytype;                    // offset 0xC, size 0x1
    char adjust_x;                   // offset 0xD, size 0x1
    char adjust_y;                   // offset 0xE, size 0x1
    char vibration;                  // offset 0xF, size 0x1
    int best_tm[8];                  // offset 0x10, size 0x20
    unsigned int sys_partid;         // offset 0x30, size 0x4
    unsigned int itm_partid;         // offset 0x34, size 0x4
    unsigned int fil_partid;         // offset 0x38, size 0x4
    unsigned int dor_partid;         // offset 0x3C, size 0x4
    unsigned int ss_flg;             // offset 0x40, size 0x4
    int pdm_no;                      // offset 0x44, size 0x4
    unsigned int typ_flg;            // offset 0x48, size 0x4
    unsigned short typ_md0;          // offset 0x4C, size 0x2
    unsigned short typ_md1;          // offset 0x4E, size 0x2
    void* typ_exp;                   // offset 0x50, size 0x4
    unsigned int tk_flg;             // offset 0x54, size 0x4
    unsigned int ts_flg;             // offset 0x58, size 0x4
    unsigned int gm_flg;             // offset 0x5C, size 0x4
    unsigned int st_flg;             // offset 0x60, size 0x4
    unsigned int cb_flg;             // offset 0x64, size 0x4
    unsigned int rm_flg;             // offset 0x68, size 0x4
    unsigned int pt_flg;             // offset 0x6C, size 0x4
    unsigned int sp_flg;             // offset 0x70, size 0x4
    unsigned int ef_flg;             // offset 0x74, size 0x4
    unsigned int error;              // offset 0x78, size 0x4
    unsigned int version;            // offset 0x7C, size 0x4
    int save_ct;                     // offset 0x80, size 0x4
    char ply_id;                     // offset 0x84, size 0x1
    char stg_no;                     // offset 0x85, size 0x1
    char rom_no;                     // offset 0x86, size 0x1
    char rcase;                      // offset 0x87, size 0x1
    char pos_no;                     // offset 0x88, size 0x1
    char cut_no;                     // offset 0x89, size 0x1
    char flr_no;                     // offset 0x8A, size 0x1
    char reserve0;                   // offset 0x8B, size 0x1
    int gm_mode;                     // offset 0x8C, size 0x4
    unsigned int ev_flg[32];         // offset 0x90, size 0x80
    unsigned int it_flg[16];         // offset 0x110, size 0x40
    unsigned int ic_flg[16];         // offset 0x150, size 0x40
    unsigned int ed_flg[32];         // offset 0x190, size 0x80
    unsigned int ky_flg[16];         // offset 0x210, size 0x40
    unsigned int mp_flg[8];          // offset 0x250, size 0x20
    unsigned int itm[384];           // offset 0x270, size 0x600
    unsigned int ply_stflg[4];       // offset 0x870, size 0x10
	NJS_POINT3 ply_pos;              // offset 0x880, size 0xC
	int ply_ang;                     // offset 0x88C, size 0x4
    char ply_wno[4];                 // offset 0x890, size 0x4
    short ply_hp[4];                 // offset 0x894, size 0x8
    unsigned char evt_posno[4];      // offset 0x89C, size 0x4
    int time;                        // offset 0x8A0, size 0x4
    int stv_tm;                      // offset 0x8A4, size 0x4
    short spray_ct;                  // offset 0x8A8, size 0x2
    short retry_ct;                  // offset 0x8AA, size 0x2
    short clear_ct;                  // offset 0x8AC, size 0x2
    short reserve1;                  // offset 0x8AE, size 0x2
    unsigned int save_end;           // offset 0x8B0, size 0x4
    char stg_nob;                    // offset 0x8B4, size 0x1
    char rom_nob;                    // offset 0x8B5, size 0x1
    char pos_nob;                    // offset 0x8B6, size 0x1
    char rcase_b;                    // offset 0x8B7, size 0x1
    unsigned int en_flg[4];          // offset 0x8B8, size 0x10
	NJS_TEXLIST* et_lp[100][16][16]; // offset 0x8C8, size 0x19000
	NJS_TEXLIST* ot_lp[1300];        // offset 0x198C8, size 0x1450
	NJS_TEXLIST* it_lp[200];         // offset 0x1AD18, size 0x320
	int eft_n;                       // offset 0x1B038, size 0x4
	NJS_TEXLIST* eft_lp[8];          // offset 0x1B03C, size 0x20
	int loop_ct;                     // offset 0x1B05C, size 0x4
    int loop_now;                    // offset 0x1B060, size 0x4
    int cng_pid;                     // offset 0x1B064, size 0x4
	const PDS_PERIPHERAL* p1per;     // offset 0x1B068, size 0x4
	PDS_PERIPHERAL* p2per;           // offset 0x1B06C, size 0x4
	PDS_PERIPHERAL* kbper;           // offset 0x1B070, size 0x4
	PDS_PERIPHERAL* msper;           // offset 0x1B074, size 0x4
	PDS_PERIPHERAL ms_per;           // offset 0x1B078, size 0x34
	int pad_port;                    // offset 0x1B0AC, size 0x4
    unsigned int pad_on;             // offset 0x1B0B0, size 0x4
    unsigned int pad_oncpy;          // offset 0x1B0B4, size 0x4
    unsigned int pad_ps;             // offset 0x1B0B8, size 0x4
    unsigned int pad_rs;             // offset 0x1B0BC, size 0x4
    unsigned int pad_old;            // offset 0x1B0C0, size 0x4
    unsigned int pad_onb;            // offset 0x1B0C4, size 0x4
    unsigned int pad_psb;            // offset 0x1B0C8, size 0x4
    unsigned int pad_oldb;           // offset 0x1B0CC, size 0x4
    short pad_ax;                    // offset 0x1B0D0, size 0x2
    short pad_ay;                    // offset 0x1B0D2, size 0x2
    short pad_dx;                    // offset 0x1B0D4, size 0x2
    short pad_dy;                    // offset 0x1B0D6, size 0x2
    unsigned short pad_ar;           // offset 0x1B0D8, size 0x2
    unsigned short pad_al;           // offset 0x1B0DA, size 0x2
    int fixcno;                      // offset 0x1B0DC, size 0x4
    int fixkno;                      // offset 0x1B0E0, size 0x4
    unsigned int exm_attr;           // offset 0x1B0E4, size 0x4
    short evc_no;                    // offset 0x1B0E8, size 0x2
    short evc_kn;                    // offset 0x1B0EA, size 0x2
    short evc_ono;                   // offset 0x1B0EC, size 0x2
    short evc_okn;                   // offset 0x1B0EE, size 0x2
    int evc_sc;                      // offset 0x1B0F0, size 0x4
    unsigned char mn_mode0;          // offset 0x1B0F4, size 0x1
    unsigned char mn_mode1;          // offset 0x1B0F5, size 0x1
    unsigned char mn_mode2;          // offset 0x1B0F6, size 0x1
    unsigned char mn_mode3;          // offset 0x1B0F7, size 0x1
    unsigned char mn_md0;            // offset 0x1B0F8, size 0x1
    unsigned char mn_md1;            // offset 0x1B0F9, size 0x1
    unsigned char mn_md2;            // offset 0x1B0FA, size 0x1
    unsigned char mn_md3;            // offset 0x1B0FB, size 0x1
    int mn_setct;                    // offset 0x1B0FC, size 0x4
    unsigned int mn_stack[8];        // offset 0x1B100, size 0x20
    unsigned int sdm_flg;            // offset 0x1B120, size 0x4
    unsigned int sdm_mode;           // offset 0x1B124, size 0x4
    unsigned char* ltc_bp;           // offset 0x1B128, size 0x4
    unsigned int ltc_tsbak;          // offset 0x1B12C, size 0x4
    int ewk_n;                       // offset 0x1B130, size 0x4
    unsigned int enow;               // offset 0x1B134, size 0x4
    unsigned int onow;               // offset 0x1B138, size 0x4
    unsigned int efnow;              // offset 0x1B13C, size 0x4
    int vsyc_ct;                     // offset 0x1B140, size 0x4
    int vsyc_flg;                    // offset 0x1B144, size 0x4
    int fog_ct;                      // offset 0x1B148, size 0x4
    int bcl_ct;                      // offset 0x1B14C, size 0x4
    int gfrm_ct;                     // offset 0x1B150, size 0x4
    int gframe;                      // offset 0x1B154, size 0x4
    int eor_ct;                      // offset 0x1B158, size 0x4
    unsigned int pfm_cts;            // offset 0x1B15C, size 0x4
    int evt_tmd;                     // offset 0x1B160, size 0x4
    int evt_tim;                     // offset 0x1B164, size 0x4
    int evt_tdg;                     // offset 0x1B168, size 0x4
    int evt_fcd;                     // offset 0x1B16C, size 0x4
    unsigned int evt_fcdct;          // offset 0x1B170, size 0x4
    unsigned int fsize;              // offset 0x1B174, size 0x4
    unsigned int rdtsz;              // offset 0x1B178, size 0x4
    unsigned char* memp;             // offset 0x1B17C, size 0x4
    unsigned char* mempb;            // offset 0x1B180, size 0x4
    unsigned char* endp;             // offset 0x1B184, size 0x4
    unsigned char* rdtp;             // offset 0x1B188, size 0x4
    unsigned char* plmdlp;           // offset 0x1B18C, size 0x4
    unsigned char* lmmdlp;           // offset 0x1B190, size 0x4
    unsigned char* wrmdlp;           // offset 0x1B194, size 0x4
    unsigned char* wlmdlp;           // offset 0x1B198, size 0x4
    unsigned char* plmthp;           // offset 0x1B19C, size 0x4
    unsigned char* plbmtp;           // offset 0x1B1A0, size 0x4
    unsigned char* plwmtp;           // offset 0x1B1A4, size 0x4
    unsigned char* plzmtp;           // offset 0x1B1A8, size 0x4
    unsigned char* plemtp;           // offset 0x1B1AC, size 0x4
    unsigned char* plexwp;           // offset 0x1B1B0, size 0x4
    unsigned char* plhdwp;           // offset 0x1B1B4, size 0x4
    unsigned char* pletcp;           // offset 0x1B1B8, size 0x4
    unsigned char* subtxp;           // offset 0x1B1BC, size 0x4
    unsigned char* doordp;           // offset 0x1B1C0, size 0x4
    unsigned char* sbs_sp;           // offset 0x1B1C4, size 0x4
	O_WRK* obwp;                     // offset 0x1B1C8, size 0x4
	O_WRK* itwp;                     // offset 0x1B1CC, size 0x4
	MN_WORK* emtp[128];              // offset 0x1B1D0, size 0x200
	MN_WORK* rmthp;                  // offset 0x1B3D0, size 0x4
	unsigned char* mspp;             // offset 0x1B3D4, size 0x4
    unsigned char* lspp;             // offset 0x1B3D8, size 0x4
    unsigned int* mes_ip;            // offset 0x1B3DC, size 0x4
    unsigned int* mes_sp;            // offset 0x1B3E0, size 0x4
    void* mes_tp;                    // offset 0x1B3E4, size 0x4
    short txr_n;                     // offset 0x1B3E8, size 0x2
    short txr_ct;                    // offset 0x1B3EA, size 0x2
	NJS_TEXLIST* txlp[256];          // offset 0x1B3EC, size 0x400
	unsigned char* txdp[256];        // offset 0x1B7EC, size 0x400
    short txloff[256];               // offset 0x1BBEC, size 0x200
    short txb_ct;                    // offset 0x1BDEC, size 0x2
    short txb_n;                     // offset 0x1BDEE, size 0x2
    short txb[256];                  // offset 0x1BDF0, size 0x200
	NJS_TEXLIST* txblp[256];         // offset 0x1BFF0, size 0x400
	TXB_WORK txbp[256];              // offset 0x1C3F0, size 0x1400
	unsigned char* ef_psp;           // offset 0x1D7F0, size 0x4
	NJS_TEXNAME ef_tex[450];         // offset 0x1D7F4, size 0x1518
	NJS_TEXLIST ef_tlist;            // offset 0x1ED0C, size 0x8
	EF_WORK ef;                      // offset 0x1ED14, size 0x28
	short efid[256];                 // offset 0x1ED3C, size 0x200
	ML_WORK efm[450];                // offset 0x1EF3C, size 0x2A30
	int ef_ct;                       // offset 0x2196C, size 0x4
    int ef_ctb;                      // offset 0x21970, size 0x4
    int ef_extn;                     // offset 0x21974, size 0x4
    int ef_tn[450];                  // offset 0x21978, size 0x708
    unsigned char ef_pbkb[450];      // offset 0x22080, size 0x1C2
    int ef_pbnk;                     // offset 0x22244, size 0x4
    int ef_slow;                     // offset 0x22248, size 0x4
    int ef_ctrn;                     // offset 0x2224C, size 0x4
    int yk_ct;                       // offset 0x22250, size 0x4
    int mg_ct;                       // offset 0x22254, size 0x4
    int bl_ct;                       // offset 0x22258, size 0x4
    int windr;                       // offset 0x2225C, size 0x4
    float winds;                     // offset 0x22260, size 0x4
    int windrb;                      // offset 0x22264, size 0x4
    float windsb;                    // offset 0x22268, size 0x4
    unsigned int thunder;            // offset 0x2226C, size 0x4
    float gas_py;                    // offset 0x22270, size 0x4
    int en_objn;                     // offset 0x22274, size 0x4
    BH_PWORK* en_obj[16];            // offset 0x22278, size 0x40
    int ef_poln;                     // offset 0x222B8, size 0x4
    int ef_mdfn;                     // offset 0x222BC, size 0x4
    int ef_linn;                     // offset 0x222C0, size 0x4
    int ef_ntxn;                     // offset 0x222C4, size 0x4
    int ef_trsn;                     // offset 0x222C8, size 0x4
    int ef_pncn;                     // offset 0x222CC, size 0x4
    int ef_opqn;                     // offset 0x222D0, size 0x4
    int ef_thln;                     // offset 0x222D4, size 0x4
    int ef_ntx2dn;                   // offset 0x222D8, size 0x4
    int ef_trs2dn;                   // offset 0x222DC, size 0x4
    int ef_pnc2dn;                   // offset 0x222E0, size 0x4
    int ef_fncn;                     // offset 0x222E4, size 0x4
	O_WRK* ef_pol[512];              // offset 0x222E8, size 0x800
	O_WRK* ef_mdf[128];              // offset 0x22AE8, size 0x200
	O_WRK* ef_lin[512];              // offset 0x22CE8, size 0x800
	O_WRK* ef_ntx[512];              // offset 0x234E8, size 0x800
	O_WRK* ef_trs[512];              // offset 0x23CE8, size 0x800
	O_WRK* ef_pnc[512];              // offset 0x244E8, size 0x800
	O_WRK* ef_opq[512];              // offset 0x24CE8, size 0x800
	O_WRK* ef_thl[512];              // offset 0x254E8, size 0x800
	O_WRK* ef_ntx2d[128];            // offset 0x25CE8, size 0x200
	O_WRK* ef_trs2d[128];            // offset 0x25EE8, size 0x200
	O_WRK* ef_pnc2d[128];            // offset 0x260E8, size 0x200
	O_WRK* ef_fnc[512];              // offset 0x262E8, size 0x800
	int ob_nlgn;                     // offset 0x26AE8, size 0x4
    int ob_hlgn;                     // offset 0x26AEC, size 0x4
    int ob_spcn;                     // offset 0x26AF0, size 0x4
	O_WRK* ob_nlg[32];               // offset 0x26AF4, size 0x80
	O_WRK* ob_hlg[32];               // offset 0x26B74, size 0x80
	O_WRK* ob_spc[32];               // offset 0x26BF4, size 0x80
	unsigned int ren_gid;            // offset 0x26C74, size 0x4
	NJS_TEXINFO ren_info;            // offset 0x26C78, size 0x2C
	NJS_TEXNAME ren_tex[1];          // offset 0x26CA4, size 0xC
	NJS_TEXLIST ren_tlist;           // offset 0x26CB0, size 0x8
	NJS_TEXTUREH_VTX rpb[256];       // offset 0x26CB8, size 0x1C00
	int ren_n;                       // offset 0x288B8, size 0x4
    int ren_idx[4];                  // offset 0x288BC, size 0x10
    int wt_nbpt;                     // offset 0x288CC, size 0x4
    float wt_px;                     // offset 0x288D0, size 0x4
    float wt_pz;                     // offset 0x288D4, size 0x4
    int wt_xp;                       // offset 0x288D8, size 0x4
    int wt_zp;                       // offset 0x288DC, size 0x4
    int wt_minx;                     // offset 0x288E0, size 0x4
    int wt_minz;                     // offset 0x288E4, size 0x4
    int wt_maxx;                     // offset 0x288E8, size 0x4
    int wt_maxz;                     // offset 0x288EC, size 0x4
    unsigned char* wt_wvp;           // offset 0x288F0, size 0x4
	NJS_PLANE mr_pl;                 // offset 0x288F4, size 0x18
	unsigned char* zan_memp;         // offset 0x2890C, size 0x4
    unsigned char* zanp;             // offset 0x28910, size 0x4
	LGT_WORK* lgtp;                  // offset 0x28914, size 0x4
	float lg_vx;                     // offset 0x28918, size 0x4
    float lg_vy;                     // offset 0x2891C, size 0x4
    float lg_vz;                     // offset 0x28920, size 0x4
    float lg_r;                      // offset 0x28924, size 0x4
    float lg_g;                      // offset 0x28928, size 0x4
    float lg_b;                      // offset 0x2892C, size 0x4
    int lg_pnt;                      // offset 0x28930, size 0x4
	LPTB lg_ptb[4];                  // offset 0x28934, size 0x80
	int mes_idx;                     // offset 0x289B4, size 0x4
    unsigned int* mes_dp;            // offset 0x289B8, size 0x4
    int mes_ct;                      // offset 0x289BC, size 0x4
    int mes_tim;                     // offset 0x289C0, size 0x4
    int mes_fls;                     // offset 0x289C4, size 0x4
    int mes_sel;                     // offset 0x289C8, size 0x4
    int mes_seln;                    // offset 0x289CC, size 0x4
	NJS_POINT2 mes_sps[16];          // offset 0x289D0, size 0x80
	int rt_sp;                       // offset 0x28A50, size 0x4
    unsigned char* rt_wp;            // offset 0x28A54, size 0x4
    unsigned char* rt_dp;            // offset 0x28A58, size 0x4
    unsigned char* rt_nw;            // offset 0x28A5C, size 0x4
    unsigned char* rt_nx;            // offset 0x28A60, size 0x4
    float* rt_ln;                    // offset 0x28A64, size 0x4
    BH_PWORK* plp;                   // offset 0x28A68, size 0x4
	ATR_WORK* pl_htp;                // offset 0x28A6C, size 0x4
	int costume;                     // offset 0x28A70, size 0x4
	NJS_POINT3 hd_pos;               // offset 0x28A74, size 0xC
	NJS_POINT3 apos;                 // offset 0x28A80, size 0xC
	ATR_WORK* ahtp;                  // offset 0x28A8C, size 0x4
	int mwal_n;                      // offset 0x28A90, size 0x4
    int metc_n;                      // offset 0x28A94, size 0x4
    int mflr_n;                      // offset 0x28A98, size 0x4
	ATR_WORK mwalp[64];              // offset 0x28A9C, size 0x900
	ATR_WORK metcp[64];              // offset 0x2939C, size 0x900
	ATR_WORK mflrp[64];              // offset 0x29C9C, size 0x900
	int dla_n;                       // offset 0x2A59C, size 0x4
	ATR_WORK* htp;                   // offset 0x2A5A0, size 0x4
	int psh_snd;                     // offset 0x2A5A4, size 0x4
    int fog_cngct;                   // offset 0x2A5A8, size 0x4
    unsigned int fog_col;            // offset 0x2A5AC, size 0x4
    float fog_nr;                    // offset 0x2A5B0, size 0x4
    float fog_fr;                    // offset 0x2A5B4, size 0x4
    float fade_ct;                   // offset 0x2A5B8, size 0x4
    float fade_hkn;                  // offset 0x2A5BC, size 0x4
    float fade_ao;                   // offset 0x2A5C0, size 0x4
    float fade_an;                   // offset 0x2A5C4, size 0x4
    float fade_ap;                   // offset 0x2A5C8, size 0x4
    float fade_ro;                   // offset 0x2A5CC, size 0x4
    float fade_rn;                   // offset 0x2A5D0, size 0x4
    float fade_rp;                   // offset 0x2A5D4, size 0x4
    float fade_go;                   // offset 0x2A5D8, size 0x4
    float fade_gn;                   // offset 0x2A5DC, size 0x4
    float fade_gp;                   // offset 0x2A5E0, size 0x4
    float fade_bo;                   // offset 0x2A5E4, size 0x4
    float fade_bn;                   // offset 0x2A5E8, size 0x4
    float fade_bp;                   // offset 0x2A5EC, size 0x4
    unsigned int fade_pbk;           // offset 0x2A5F0, size 0x4
    unsigned short ssv_md0;          // offset 0x2A5F4, size 0x2
    unsigned short ssv_md1;          // offset 0x2A5F6, size 0x2
    int ssv_tim;                     // offset 0x2A5F8, size 0x4
    float ssv_ct;                    // offset 0x2A5FC, size 0x4
    float ssv_hkn;                   // offset 0x2A600, size 0x4
    float ssv_ao;                    // offset 0x2A604, size 0x4
    float ssv_an;                    // offset 0x2A608, size 0x4
    float ssv_ap;                    // offset 0x2A60C, size 0x4
    short fil_no;                    // offset 0x2A610, size 0x2
    short fil_rt;                    // offset 0x2A612, size 0x2
    float rvf_sc;                    // offset 0x2A614, size 0x4
    float rvf_sn;                    // offset 0x2A618, size 0x4
    unsigned int rvfc[4];            // offset 0x2A61C, size 0x10
    float cine_an;                   // offset 0x2A62C, size 0x4
    float cine_ap;                   // offset 0x2A630, size 0x4
    unsigned int sco_flg;            // offset 0x2A634, size 0x4
    float amb_r[4];                  // offset 0x2A638, size 0x10
    float amb_g[4];                  // offset 0x2A648, size 0x10
    float amb_b[4];                  // offset 0x2A658, size 0x10
    int sb_id;                       // offset 0x2A668, size 0x4
    int sb_cmd;                      // offset 0x2A66C, size 0x4
    int sb_rdid;                     // offset 0x2A670, size 0x4
    int sb_rdsz;                     // offset 0x2A674, size 0x4
    void* sb_rdp;                    // offset 0x2A678, size 0x4
    void* sb_mlb;                    // offset 0x2A67C, size 0x4
    void* sb_ppp;                    // offset 0x2A680, size 0x4
	NJS_TEXLIST* sb_tlist;           // offset 0x2A684, size 0x4
	int ddmd;                        // offset 0x2A688, size 0x4
	DOOR_WORK door;                  // offset 0x2A68C, size 0x1C
	int mpmd;                        // offset 0x2A6A8, size 0x4
    int mp_prm[4];                   // offset 0x2A6AC, size 0x10
    unsigned short gov_md0;          // offset 0x2A6BC, size 0x2
    unsigned short gov_md1;          // offset 0x2A6BE, size 0x2
    int gov_ct;                      // offset 0x2A6C0, size 0x4
    void* gov_exp;                   // offset 0x2A6C4, size 0x4
    unsigned int com_flg;            // offset 0x2A6C8, size 0x4
    unsigned short com_md0;          // offset 0x2A6CC, size 0x2
    unsigned short com_md1;          // offset 0x2A6CE, size 0x2
    unsigned int com_num;            // offset 0x2A6D0, size 0x4
    void* com_exp;                   // offset 0x2A6D4, size 0x4
    short ond_tnm;                   // offset 0x2A6D8, size 0x2
    short ond_ud;                    // offset 0x2A6DA, size 0x2
    char ond_cx;                     // offset 0x2A6DC, size 0x1
    char ond_n[3];                   // offset 0x2A6DD, size 0x3
    unsigned char ufo_md;            // offset 0x2A6E0, size 0x1
    unsigned char ufo_flg;           // offset 0x2A6E1, size 0x1
    short ufo_oidx;                  // offset 0x2A6E2, size 0x2
	NJS_POINT3 ufo_pos;              // offset 0x2A6E4, size 0xC
	unsigned int opt_flg;            // offset 0x2A6F0, size 0x4
    unsigned short opt_md0;          // offset 0x2A6F4, size 0x2
    unsigned short opt_md1;          // offset 0x2A6F6, size 0x2
    void* opt_exp;                   // offset 0x2A6F8, size 0x4
    unsigned int etc_idx;            // offset 0x2A6FC, size 0x4
    unsigned int flr_idx;            // offset 0x2A700, size 0x4
    int mvi_no;                      // offset 0x2A704, size 0x4
    int mvi_tp;                      // offset 0x2A708, size 0x4
    unsigned short mvi_md;           // offset 0x2A70C, size 0x2
    unsigned short mvi_flg;          // offset 0x2A70E, size 0x2
    unsigned int mvi_tsb;            // offset 0x2A710, size 0x4
    unsigned int mvi_spb;            // offset 0x2A714, size 0x4
    unsigned char* mvi_memp;         // offset 0x2A718, size 0x4
    unsigned int dcg_tkbak;          // offset 0x2A71C, size 0x4
    unsigned int dcg_tsbak;          // offset 0x2A720, size 0x4
    unsigned int pau_spbak;          // offset 0x2A724, size 0x4
    unsigned int pau_pad_on;         // offset 0x2A728, size 0x4
    unsigned int pau_pad_ps;         // offset 0x2A72C, size 0x4
    unsigned int pau_pad_old;        // offset 0x2A730, size 0x4
    unsigned char* pdm_dp;           // offset 0x2A734, size 0x4
    unsigned char* pdm_pd;           // offset 0x2A738, size 0x4
    int pdm_keytpb;                  // offset 0x2A73C, size 0x4
    int gat_ct;                      // offset 0x2A740, size 0x4
	GATC gatc[16];                   // offset 0x2A744, size 0x200
	int ght_ct;                      // offset 0x2A944, size 0x4
    unsigned int ghtc[32];           // offset 0x2A948, size 0x80
	NJS_POINT3 ghtp[32];             // offset 0x2A9C8, size 0x180
	unsigned short db_md0;           // offset 0x2AB48, size 0x2
    unsigned short db_md1;           // offset 0x2AB4A, size 0x2
    char db_stgno;                   // offset 0x2AB4C, size 0x1
    char db_romno;                   // offset 0x2AB4D, size 0x1
    char db_rcase;                   // offset 0x2AB4E, size 0x1
    char db_muteki;                  // offset 0x2AB4F, size 0x1
    short db_px;                     // offset 0x2AB50, size 0x2
    short db_py;                     // offset 0x2AB52, size 0x2
    int db_mes;                      // offset 0x2AB54, size 0x4
    int calc_v;                      // offset 0x2AB58, size 0x4
    unsigned int brkfg;              // offset 0x2AB5C, size 0x4
    char brkfg_typ[32];              // offset 0x2AB60, size 0x20
    short brkfg_bit[32];             // offset 0x2AB80, size 0x40
    unsigned int brkfg_tkb;          // offset 0x2ABC0, size 0x4
    unsigned int brkfg_tsb;          // offset 0x2ABC4, size 0x4
    int brkfg_ct;                    // offset 0x2ABC8, size 0x4
    unsigned int bmt_size;           // offset 0x2ABCC, size 0x4
    unsigned int lmt_size;           // offset 0x2ABD0, size 0x4
    unsigned int emt_size;           // offset 0x2ABD4, size 0x4
    unsigned int wmt_size;           // offset 0x2ABD8, size 0x4
    char mes[256];                   // offset 0x2ABDC, size 0x100
    float sfx;                       // offset 0x2ACDC, size 0x4
    float sfy;                       // offset 0x2ACE0, size 0x4
    float sfxn;                      // offset 0x2ACE4, size 0x4
    float sfyn;                      // offset 0x2ACE8, size 0x4
    float sfct;                      // offset 0x2ACEC, size 0x4
} SYS_WORK;

extern CAM_WORK cam;
extern ROM_WORK* rom;
extern unsigned char* njpmemp;
extern NJS_MATRIX* cmat;
extern SYS_WORK* sys;
extern O_WRK eff[512];
extern BH_PWORK* plp;
extern HWS_WORK* hws;
extern int pd_port;
extern unsigned char* freemem;
extern unsigned char* vwbmemp;
extern NJS_TEXMEMLIST tbuf[256];
extern unsigned char* vebmemp;
extern unsigned char* keepmem;
extern BH_PWORK ply;
extern float BHD_ASPECT_X;
extern float BHD_ASPECT_Y;
extern BH_PWORK ene[128];

void njUserInit(void);
Sint32 njUserMain(void);
void njUserExit(void);

#endif
