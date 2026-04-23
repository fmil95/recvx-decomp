#ifndef _DOOR_H_
#define _DOOR_H_

#include "types.h"

typedef struct _proc_wrk 
{
    // total size: 0x4
    void (*procP)(void*); // offset 0x0, size 0x4
} _proc_wrk;

typedef struct FADEPROC_WORK 
{
    // total size: 0x34
    int wait0;           // offset 0x0, size 0x4
    unsigned int color0; // offset 0x4, size 0x4
    float rate0;         // offset 0x8, size 0x4
    float speed0;        // offset 0xC, size 0x4
    float goal0;         // offset 0x10, size 0x4
    int cmp0;            // offset 0x14, size 0x4
    int wait1;           // offset 0x18, size 0x4
    unsigned int color1; // offset 0x1C, size 0x4
    float rate1;         // offset 0x20, size 0x4
    float speed1;        // offset 0x24, size 0x4
    float goal1;         // offset 0x28, size 0x4
    int cmp1;            // offset 0x2C, size 0x4
    int wait2;           // offset 0x30, size 0x4
} FADEPROC_WORK;

typedef struct VIEWPROC1_WORK 
{
    // total size: 0x50
    int wait_push;       // offset 0x0, size 0x4
    NJS_POINT3 pos_push; // offset 0x4, size 0xC
    int wait_pull;       // offset 0x10, size 0x4
    NJS_POINT3 pos_pull; // offset 0x14, size 0xC
    int ang[3];          // offset 0x20, size 0xC
    int vew0_yaw;        // offset 0x2C, size 0x4
    int vew0_pitch;      // offset 0x30, size 0x4
    float vew0_speed;    // offset 0x34, size 0x4
    float vew0_accel;    // offset 0x38, size 0x4
    float vew0_goal_pz;  // offset 0x3C, size 0x4
    int vew0_cmp;        // offset 0x40, size 0x4
    int vew0_goal_dy;    // offset 0x44, size 0x4
    int vew0_speed_dy;   // offset 0x48, size 0x4
    int vew0_cmp_dy;     // offset 0x4C, size 0x4
} VIEWPROC1_WORK;

typedef struct VIEWPROC2_WORK
{
    // total size: 0x5C
    NJS_POINT3 pos_low;  // offset 0x0, size 0xC
    NJS_POINT3 tgt_low;  // offset 0xC, size 0xC
    int roll_low;        // offset 0x18, size 0x4
    int yaw_low;         // offset 0x1C, size 0x4
    int pitch_low;       // offset 0x20, size 0x4
    float speed_low;     // offset 0x24, size 0x4
    float accel_low;     // offset 0x28, size 0x4
    NJS_POINT3 pos_high; // offset 0x2C, size 0xC
    NJS_POINT3 tgt_high; // offset 0x38, size 0xC
    int roll_high;       // offset 0x44, size 0x4
    int yaw_high;        // offset 0x48, size 0x4
    int pitxh_high;      // offset 0x4C, size 0x4
    float speed_high;    // offset 0x50, size 0x4
    float accel_high;    // offset 0x54, size 0x4
    int wait;            // offset 0x58, size 0x4
} VIEWPROC2_WORK;

typedef struct VIEWPROC3_WORK 
{
    // total size: 0x94
    NJS_POINT3 pos_low;  // offset 0x0, size 0xC
    int ang_low[3];      // offset 0xC, size 0xC
    int dst_ang_low[3];  // offset 0x18, size 0xC
    float ang_rte_low;   // offset 0x24, size 0x4
    int yaw_low;         // offset 0x28, size 0x4
    int pitch_low;       // offset 0x2C, size 0x4
    float speed_low;     // offset 0x30, size 0x4
    float accel_low;     // offset 0x34, size 0x4
    int speed_dx_low;    // offset 0x38, size 0x4
    int accel_dx_low;    // offset 0x3C, size 0x4
    int loop_wait_low;   // offset 0x40, size 0x4
    NJS_POINT3 pos_high; // offset 0x44, size 0xC
    int ang_high[3];     // offset 0x50, size 0xC
    int dst_ang_high[3]; // offset 0x5C, size 0xC
    float ang_rte_high;  // offset 0x68, size 0x4
    int yaw_high;        // offset 0x6C, size 0x4
    int pitch_high;      // offset 0x70, size 0x4
    float speed_high;    // offset 0x74, size 0x4
    float accel_high;    // offset 0x78, size 0x4
    int speed_dx_high;   // offset 0x7C, size 0x4
    int accel_dx_high;   // offset 0x80, size 0x4
    int loop_wait_high;  // offset 0x84, size 0x4
    int pos_wait;        // offset 0x88, size 0x4
    int ang_wait;        // offset 0x8C, size 0x4
    int slope_ax;        // offset 0x90, size 0x4
} VIEWPROC3_WORK;

typedef struct VIEWPROC4_WORK 
{
    // total size: 0x38
    NJS_POINT3 pos_low;  // offset 0x0, size 0xC
    int ang_low[3];      // offset 0xC, size 0xC
    NJS_POINT3 pos_high; // offset 0x18, size 0xC
    int ang_high[3];     // offset 0x24, size 0xC
    int wait;            // offset 0x30, size 0x4
    int chg_vew;         // offset 0x34, size 0x4
} VIEWPROC4_WORK;

typedef struct VIEWPROC5_WORK 
{
    // total size: 0x5C
    NJS_POINT3 pos_low;  // offset 0x0, size 0xC
    int ang_low[3];      // offset 0xC, size 0xC
    NJS_POINT3 pos_high; // offset 0x18, size 0xC
    int ang_high[3];     // offset 0x24, size 0xC
    int wait0;           // offset 0x30, size 0x4
    float fde_rte0;      // offset 0x34, size 0x4
    float fde_spd0;      // offset 0x38, size 0x4
    float fde_gol0;      // offset 0x3C, size 0x4
    int fde_cmp0;        // offset 0x40, size 0x4
    int wait1;           // offset 0x44, size 0x4
    float fde_rte1;      // offset 0x48, size 0x4
    float fde_spd1;      // offset 0x4C, size 0x4
    float fde_gol1;      // offset 0x50, size 0x4
    int fde_cmp1;        // offset 0x54, size 0x4
    int chg_vew;         // offset 0x58, size 0x4
} VIEWPROC5_WORK;

typedef struct VIEWPROC6_WORK 
{
    // total size: 0x58
    NJS_POINT3 dst_pos_low;  // offset 0x0, size 0xC
    int dst_ang_low[3];      // offset 0xC, size 0xC
    NJS_POINT3 dst_pos_high; // offset 0x18, size 0xC
    int dst_ang_high[3];     // offset 0x24, size 0xC
    int wait_pos;            // offset 0x30, size 0x4
    int wait_ang;            // offset 0x34, size 0x4
    NJS_POINT3 pos_rte;      // offset 0x38, size 0xC
    NJS_POINT3 ang_rte;      // offset 0x44, size 0xC
    int total_time;          // offset 0x50, size 0x4
    int chg_vew;             // offset 0x54, size 0x4
} VIEWPROC6_WORK;

typedef struct VIEWPROC7_WORK
{
    // total size: 0x50
    int wait_push;       // offset 0x0, size 0x4
    NJS_POINT3 pos_push; // offset 0x4, size 0xC
    int wait_pull;       // offset 0x10, size 0x4
    NJS_POINT3 pos_pull; // offset 0x14, size 0xC
    int ang[3];          // offset 0x20, size 0xC
    int vew0_yaw;        // offset 0x2C, size 0x4
    int vew0_pitch;      // offset 0x30, size 0x4
    float vew0_speed;    // offset 0x34, size 0x4
    float vew0_accel;    // offset 0x38, size 0x4
    float vew0_goal_pz;  // offset 0x3C, size 0x4
    int vew0_cmp;        // offset 0x40, size 0x4
    int vew0_goal_dy;    // offset 0x44, size 0x4
    int vew0_speed_dy;   // offset 0x48, size 0x4
    int vew0_cmp_dy;     // offset 0x4C, size 0x4
} VIEWPROC7_WORK;

typedef struct DOORPROC1_WORK 
{
    // total size: 0x50
    int nob_first;       // offset 0x0, size 0x4
    int nob_speed;       // offset 0x4, size 0x4
    int nob_accel;       // offset 0x8, size 0x4
    int nob_goal;        // offset 0xC, size 0x4
    int nob_cmp;         // offset 0x10, size 0x4
    int dor0_wait;       // offset 0x14, size 0x4
    int dor0_first;      // offset 0x18, size 0x4
    int dor0_speed;      // offset 0x1C, size 0x4
    int dor0_accel;      // offset 0x20, size 0x4
    int dor0_goal_speed; // offset 0x24, size 0x4
    int dor0_cmp;        // offset 0x28, size 0x4
    int dor1_wait;       // offset 0x2C, size 0x4
    int dor1_speed;      // offset 0x30, size 0x4
    int dor1_accel;      // offset 0x34, size 0x4
    int dor1_goal_angle; // offset 0x38, size 0x4
    int dor1_cmp;        // offset 0x3C, size 0x4
    int dor1_decel;      // offset 0x40, size 0x4
    int wait;            // offset 0x44, size 0x4
    int snd_wait;        // offset 0x48, size 0x4
    int snd_wait1;       // offset 0x4C, size 0x4
} DOORPROC1_WORK;

typedef struct DOORPROC2_WORK 
{
    // total size: 0x1C
    int wait;     // offset 0x0, size 0x4
    int snd_wait; // offset 0x4, size 0x4
    int yaw;      // offset 0x8, size 0x4
    int pitch;    // offset 0xC, size 0x4
    float speed;  // offset 0x10, size 0x4
    float decel;  // offset 0x14, size 0x4
    float goal;   // offset 0x18, size 0x4
} DOORPROC2_WORK;

typedef struct DOORPROC3_WORK 
{
    // total size: 0x40
    int nob_wait;     // offset 0x0, size 0x4
    int nob_first;    // offset 0x4, size 0x4
    int nob_speed;    // offset 0x8, size 0x4
    int nob_accel;    // offset 0xC, size 0x4
    int nob_goal;     // offset 0x10, size 0x4
    int nob_cmp;      // offset 0x14, size 0x4
    int dor0_wait;    // offset 0x18, size 0x4
    int dor0_yaw;     // offset 0x1C, size 0x4
    int dor0_pitch;   // offset 0x20, size 0x4
    float dor0_speed; // offset 0x24, size 0x4
    float dor0_accel; // offset 0x28, size 0x4
    int dor0_cmp;     // offset 0x2C, size 0x4
    float dor0_goal;  // offset 0x30, size 0x4
    int wait;         // offset 0x34, size 0x4
    int snd_wait;     // offset 0x38, size 0x4
    int type;         // offset 0x3C, size 0x4
} DOORPROC3_WORK;

typedef struct DOORPROC4_WORK
{
    // total size: 0x30
    float pos_y_low;  // offset 0x0, size 0x4
    int yaw_low;      // offset 0x4, size 0x4
    int pitch_low;    // offset 0x8, size 0x4
    float pos_y_high; // offset 0xC, size 0x4
    int yaw_high;     // offset 0x10, size 0x4
    int pitch_high;   // offset 0x14, size 0x4
    int wait;         // offset 0x18, size 0x4
    int snd_wait;     // offset 0x1C, size 0x4
    float speed;      // offset 0x20, size 0x4
    float accel;      // offset 0x24, size 0x4
    float goal;       // offset 0x28, size 0x4
    int cmp;          // offset 0x2C, size 0x4
} DOORPROC4_WORK;

typedef struct DOORPROC5_WORK 
{
    // total size: 0x34
    int dor0_wait;       // offset 0x0, size 0x4
    int dor0_first;      // offset 0x4, size 0x4
    int dor0_speed;      // offset 0x8, size 0x4
    int dor0_accel;      // offset 0xC, size 0x4
    int dor0_goal_speed; // offset 0x10, size 0x4
    int dor0_cmp;        // offset 0x14, size 0x4
    int dor1_wait;       // offset 0x18, size 0x4
    int dor1_speed;      // offset 0x1C, size 0x4
    int dor1_accel;      // offset 0x20, size 0x4
    int dor1_goal_angle; // offset 0x24, size 0x4
    int dor1_cmp;        // offset 0x28, size 0x4
    int dor1_decel;      // offset 0x2C, size 0x4
    int snd_wait;        // offset 0x30, size 0x4
} DOORPROC5_WORK;

typedef struct DOORPROC7_WORK 
{
    // total size: 0x50
    int nob_first;       // offset 0x0, size 0x4
    int nob_speed;       // offset 0x4, size 0x4
    int nob_accel;       // offset 0x8, size 0x4
    int nob_goal;        // offset 0xC, size 0x4
    int nob_cmp;         // offset 0x10, size 0x4
    int dor0_wait;       // offset 0x14, size 0x4
    int dor0_first;      // offset 0x18, size 0x4
    int dor0_speed;      // offset 0x1C, size 0x4
    int dor0_accel;      // offset 0x20, size 0x4
    int dor0_goal_speed; // offset 0x24, size 0x4
    int dor0_cmp;        // offset 0x28, size 0x4
    int dor1_wait;       // offset 0x2C, size 0x4
    int dor1_speed;      // offset 0x30, size 0x4
    int dor1_accel;      // offset 0x34, size 0x4
    int dor1_goal_angle; // offset 0x38, size 0x4
    int dor1_cmp;        // offset 0x3C, size 0x4
    int dor1_decel;      // offset 0x40, size 0x4
    int wait;            // offset 0x44, size 0x4
    int snd_wait;        // offset 0x48, size 0x4
    int snd_wait1;       // offset 0x4C, size 0x4
} DOORPROC7_WORK;

typedef struct LIGHTPROC_WORK
{
    // total size: 0x7C
    float amb_r;        // offset 0x0, size 0x4
    float amb_g;        // offset 0x4, size 0x4
    float amb_b;        // offset 0x8, size 0x4
    int lgt_num;        // offset 0xC, size 0x4
    LGT_WRK lgt_dat[3]; // offset 0x10, size 0x6C
} LIGHTPROC_WORK;

typedef struct PURUPROC_WORK 
{
    // total size: 0x14
    int wait_time; // offset 0x0, size 0x4
    int loop_time; // offset 0x4, size 0x4
    int snd_no;    // offset 0x8, size 0x4
    int pru_no;    // offset 0xC, size 0x4
    int pru_wait;  // offset 0x10, size 0x4
} PURUPROC_WORK;

typedef enum SPD_MDE
{
	DMO_SPD_1 = 0,
	DMO_SPD_2 = 1,
	DMO_SPD_3 = 2
} SPD_MDE;

typedef struct HRT_WORK
{
	// total size: 0xC
	int mode; // offset 0x0, size 0x4
	int time; // offset 0x4, size 0x4
	int wait; // offset 0x8, size 0x4
} HRT_WORK;

typedef struct _door_wrk 
{
    // total size: 0x1F4
    int dmo_atr;             // offset 0x0, size 0x4
    char dmo_typ;            // offset 0x4, size 0x1
    char cse_no;             // offset 0x5, size 0x1
    char dummy[2];           // offset 0x6, size 0x2
    int status;              // offset 0x8, size 0x4
    int dmo_mode;            // offset 0xC, size 0x4
    int time;                // offset 0x10, size 0x4
    int prti_no;             // offset 0x14, size 0x4
    int slot_no;             // offset 0x18, size 0x4
    void* dmo_bufP;          // offset 0x1C, size 0x4
    void* dmo_prmP;          // offset 0x20, size 0x4
    void* tex_pacP;          // offset 0x24, size 0x4
    SPD_MDE spd_mde;         // offset 0x28, size 0x4
    void (*fde_prcP)(void*); // offset 0x2C, size 0x4
    int fde_mode;            // offset 0x30, size 0x4
    int fde_reg;             // offset 0x34, size 0x4
    void* fpP;               // offset 0x38, size 0x4
    float fde_rate;          // offset 0x3C, size 0x4
    int fde_col;             // offset 0x40, size 0x4
    void (*vew_prcP)(void*); // offset 0x44, size 0x4
    int vew_mode;            // offset 0x48, size 0x4
    int vew_reg;             // offset 0x4C, size 0x4
    int vew_tmp;             // offset 0x50, size 0x4
    void* vpP;               // offset 0x54, size 0x4
	NJS_POINT3 vew_pos;      // offset 0x58, size 0xC
    NJS_POINT3 vew_bak;      // offset 0x64, size 0xC
    int vew_ang[3];          // offset 0x70, size 0xC
    int vew_ang_speed;       // offset 0x7C, size 0x4
    int vew_yaw;             // offset 0x80, size 0x4
    int vew_pitch;           // offset 0x84, size 0x4
    float vew_speed;         // offset 0x88, size 0x4
    float vew_adj_pos;       // offset 0x8C, size 0x4
    float vew_adj_ang;       // offset 0x90, size 0x4
    float vew_adj_pos_add;   // offset 0x94, size 0x4
    float vew_adj_ang_add;   // offset 0x98, size 0x4
    void (*dor_prcP)(void*); // offset 0x9C, size 0x4
    int dor_mode;            // offset 0xA0, size 0x4
    int dor_reg;             // offset 0xA4, size 0x4
    float dor_flt;           // offset 0xA8, size 0x4
    int dor_snd;             // offset 0xAC, size 0x4
    int dor_snd_exd;         // offset 0xB0, size 0x4
    void* dpP;               // offset 0xB4, size 0x4
    ML_WORK dor_mdl;         // offset 0xB8, size 0x18
    NJS_CNK_OBJECT* objP;    // offset 0xD0, size 0x4
    NJS_POINT3 dor_bak;      // offset 0xD4, size 0xC
    int dor_yaw;             // offset 0xE0, size 0x4
    int dor_pitch;           // offset 0xE4, size 0x4
    float dor_speed;         // offset 0xE8, size 0x4
    int dor_ang_speed;       // offset 0xEC, size 0x4
    void (*lgt_prcP)(void*); // offset 0xF0, size 0x4
    int lgt_mode;            // offset 0xF4, size 0x4
    int lgt_reg;             // offset 0xF8, size 0x4
    int lgt_atr[3];          // offset 0xFC, size 0xC
    void *lpP;               // offset 0x108, size 0x4
    NJS_POINT3 lgt_amb_off;  // offset 0x10C, size 0xC
    NJS_POINT3 lgt_pnt_rte;  // offset 0x118, size 0xC
    LGT_WRK lgt_buf[3];      // offset 0x124, size 0x6C
    void (*pru_prcP)(void*); // offset 0x190, size 0x4
    int pru_mode;            // offset 0x194, size 0x4
    int pru_reg;             // offset 0x198, size 0x4
    int pru_tim;             // offset 0x19C, size 0x4
    void* ppP;               // offset 0x1A0, size 0x4
    int dki_mode;            // offset 0x1A4, size 0x4
    int BgmSet[16];          // offset 0x1A8, size 0x40
    HRT_WORK hrt_prm;        // offset 0x1E8, size 0xC
} _door_wrk;

typedef struct DMO_CLIP 
{
    // total size: 0x14
    short dmo_typ; // offset 0x0, size 0x2
    int prti_no;   // offset 0x4, size 0x4
    short vew_no;  // offset 0x8, size 0x2
    float near;    // offset 0xC, size 0x4
    float far;     // offset 0x10, size 0x4
} DMO_CLIP; 

typedef struct PT_WORK 
{
    // total size: 0x14
    short fde_no;  // offset 0x0, size 0x2
    short fde_off; // offset 0x2, size 0x2
    short vew_no;  // offset 0x4, size 0x2
    short vew_off; // offset 0x6, size 0x2
    short dor_no;  // offset 0x8, size 0x2
    short dor_off; // offset 0xA, size 0x2
    short lgt_no;  // offset 0xC, size 0x2
    short lgt_off; // offset 0xE, size 0x2
    short pru_no;  // offset 0x10, size 0x2
    short pru_off; // offset 0x12, size 0x2 
} PT_WORK;

typedef struct PH_WORK 
{
    // total size: 0x4
    char nam[3];  // offset 0x0, size 0x3
    char prm_num; // offset 0x3, size 0x1
} PH_WORK;

void bhInitDoor();
int bhReadDoorData();
void bhSetDoor();
void bhExitDoor();
int AnalyzeDoor(_door_wrk* dwP, int typ_no, int attr);
int bhControlDoor();
static void ControlSoundTiming(_door_wrk* dwP);
static void SetSoundTiming(_door_wrk* dwP);
static void FadeProc1(_door_wrk* dwP);
static void ViewProc1(_door_wrk* dwP);
static void ViewProc2(_door_wrk* dwP);
static void ViewProc3(_door_wrk* dwP);
static void ViewProc4(_door_wrk* dwP);
static void ViewProc5(_door_wrk* dwP);
static void ViewProc6(_door_wrk* dwP);
static void ViewProc7(_door_wrk* dwP);
static void DoorProc1(_door_wrk* dwP);
static void DoorProc2(_door_wrk* dwP);
static void DoorProc3(_door_wrk* dwP);
static void DoorProc4(_door_wrk* dwP);
static void DoorProc5(_door_wrk* dwP);
static void DoorProc6(_door_wrk* dwP);
static void DoorProc7(_door_wrk* dwP);
static void LightProc1(_door_wrk* dwP);
static void LightProc2(_door_wrk* dwP);
static int CompareSint32(int val_a, int cmp_typ, int val_b);
static int CompareFloat(float val_a, int cmp_typ, float val_b);
static void VectorMove(NJS_POINT3* posP, int yaw, int pitch, float speed);
static void LightSubAmb(_door_wrk* dwP, NJS_POINT3* ambP, NJS_POINT3* offP);
static void LightSubPnt(_door_wrk* dwP, int lgt_no, LGT_WRK* ldP, NJS_POINT3* rteP);
static void ryExcuteFade(float pri, int col, float rate);
static void PuruProc1(_door_wrk* dwP);
static void DokiProcLgt(_door_wrk* dwP);

#endif
