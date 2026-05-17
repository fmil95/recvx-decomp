#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "types.h"
#include "macros.h"

typedef struct WPN_TAB
{
	// total size: 0x68
    unsigned int flg;      // offset 0x0, size 0x4
    unsigned int atack_ct; // offset 0x4, size 0x4
    unsigned int fend_ct;  // offset 0x8, size 0x4
    unsigned int at_cct;   // offset 0xC, size 0x4
    short ef_yct;          // offset 0x10, size 0x2
    short act_ct0;         // offset 0x12, size 0x2
    short act_ct1;         // offset 0x14, size 0x2
    short act_ct2;         // offset 0x16, size 0x2
    float r;               // offset 0x18, size 0x4
    float l;               // offset 0x1C, size 0x4
    float rn;              // offset 0x20, size 0x4
    float rmax;            // offset 0x24, size 0x4
	NJS_POINT3 wp_fps1;    // offset 0x28, size 0xC
	NJS_POINT3 wp_fps2;    // offset 0x34, size 0xC
	NJS_POINT3 wp_cps;     // offset 0x40, size 0xC
	unsigned char ltp;     // offset 0x4C, size 0x1
    unsigned char lr;      // offset 0x4D, size 0x1
    unsigned char lg;      // offset 0x4E, size 0x1
    unsigned char lb;      // offset 0x4F, size 0x1
    unsigned short lnr;    // offset 0x50, size 0x2
    unsigned short lfr;    // offset 0x52, size 0x2
    float hrate;           // offset 0x54, size 0x4
    float ef_scale;        // offset 0x58, size 0x4
    short snd_wpno;        // offset 0x5C, size 0x2
    short hiteff;          // offset 0x5E, size 0x2
    unsigned short seno0;  // offset 0x60, size 0x2
    unsigned short seno1;  // offset 0x62, size 0x2
    char vib_tp;           // offset 0x64, size 0x1
    char vib_ct;           // offset 0x65, size 0x1
    char reserve1;         // offset 0x66, size 0x1
    char reserve2;         // offset 0x67, size 0x1
} WPN_TAB;

typedef struct EXP_WORK 
{
    // total size: 0x7C
    int wpntp;    // offset 0x0, size 0x4
    int yrct;     // offset 0x4, size 0x4
    int kdn_fr;   // offset 0x8, size 0x4
    float kdn_py; // offset 0xC, size 0x4
    float rtspd;  // offset 0x10, size 0x4
    int dmlvl;    // offset 0x14, size 0x4
    int dm_ct;    // offset 0x18, size 0x4
    float arn;    // offset 0x1C, size 0x4
    float arp;    // offset 0x20, size 0x4
    float fpx;    // offset 0x24, size 0x4
    float fpy;    // offset 0x28, size 0x4
    float fpz;    // offset 0x2C, size 0x4
    float bpx;    // offset 0x30, size 0x4
    float bpy;    // offset 0x34, size 0x4
    float bpz;    // offset 0x38, size 0x4
    float bpxb;   // offset 0x3C, size 0x4
    float bpyb;   // offset 0x40, size 0x4
    float bpzb;   // offset 0x44, size 0x4
    float spx;    // offset 0x48, size 0x4
    float spy;    // offset 0x4C, size 0x4
    float spz;    // offset 0x50, size 0x4
    float spxn;   // offset 0x54, size 0x4
    float spyn;   // offset 0x58, size 0x4
    float spzn;   // offset 0x5C, size 0x4
    float plx;    // offset 0x60, size 0x4
    float ply;    // offset 0x64, size 0x4
    float plz;    // offset 0x68, size 0x4
    float nlxb;   // offset 0x6C, size 0x4
    float nlyb;   // offset 0x70, size 0x4
    float nlzb;   // offset 0x74, size 0x4
    int scp_ct;   // offset 0x78, size 0x4
} EXP_WORK;

void bhInitPlayer();
void bhSetPlayer();
void bhInitRoomChangePlayer();
void bhResetPlayer();
void bhCheckMothEgg();
void bhCheckSubPack();
void bhStandPlayerMotion();
void bhKaidanPlayerMotion(int flg, int idx);
void bhFixPositionXYZ(BH_PWORK* ewP, char* datP);
int bhCheckPlayerKegaMotion(int wpntp, int dmlvl, int num);
void bhCheckEvtTimer();
void bhControlPlayer();
void bhCPM0_action();
void bhControlPlayerPad();
void bhCPM1_act_bas();
void bhCPM2_act_std();
void bhCPM2_act_srt();
void bhCPM2_act_sta();
void bhCPM2_act_wlk();
void bhCPM2_act_run();
void bhCPM2_act_bak();
void bhCPM2_act_bk2();
void bhCPM2_act_kdu();
void bhCPM2_act_kdd();
void bhCPM2_act_dnu();
void bhCPM2_act_dnd();
void bhCPM2_act_psh();
void bhCPM2_act_cro();
void bhCPM2_act_hsu();
void bhCPM2_act_hsd();
void bhCPM2_act_rpsh();
void bhCPM1_act_atk();
void bhCPM2_act_suw();
void bhCPM2_act_wpn();
void bhCPM2_act_wre();
void bhCPM2_act_atk();
void bhCPM2_act_rld();
void bhCPM2_act_knf();
void bhCPM0_damage();
void bhCPM0_die();
void bhCPM0_nage();
void bhCPM0_enedam();
void bhCPM0_enedie();
void bhCPM0_nothing();
void bhControlPlayerHead();
void bhLookNearEnemy();
void bhSetHeadRotation(short ax, short ay);
void bhCalcHair(O_WRK* op, BH_PWORK* pp);
void* bhGetTransZ(int mtn_no);

extern EF_WORK WpnEffTab[23][4];
extern const WPN_TAB WpnTab[23];
extern const unsigned short PlMtnWpn[5];
extern const unsigned short PlMtnAct[2][3][7];
extern const char PlFootSnd[4][2][7];

#endif
