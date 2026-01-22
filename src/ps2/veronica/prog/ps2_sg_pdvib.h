#ifndef _PS2_SG_PDVIB_H_
#define _PS2_SG_PDVIB_H_

#include "types.h"

typedef struct PAD_ACT
{
	// total size: 0x10
    unsigned char be_flag; // offset 0x0, size 0x1
    unsigned char level;   // offset 0x1, size 0x1
    unsigned char start;   // offset 0x2, size 0x1
    unsigned char end;     // offset 0x3, size 0x1
    unsigned short delay;  // offset 0x4, size 0x2
    unsigned short time;   // offset 0x6, size 0x2
    unsigned short add;    // offset 0x8, size 0x2
    short f_level;         // offset 0xA, size 0x2
    short f_add;           // offset 0xC, size 0x2
    char data[2];          // offset 0xE, size 0x2
} PAD_ACT;

Sint32 pdVibMxIsReady(Uint32 port);
Sint32 pdVibMxSetStopTime(Uint32 port, Uint32 time);
Sint32 pdVibMxStart(Uint32 port, const PDS_VIBPARAM* param);
Sint32 pdVibMxStop(Uint32 port);
void Ps2_pad_actuater();
static void Ps2_pad_act_start(PAD_ACT* pPact);
static void Ps2_pad_act_stop(PAD_ACT* pPact);
static void Ps2_pad_act_all_stop();

extern PAD_ACT Pad_act[20];

#endif
