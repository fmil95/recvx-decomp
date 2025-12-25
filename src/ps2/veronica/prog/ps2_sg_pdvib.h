#ifndef _PS2_SG_PDVIB_H_
#define _PS2_SG_PDVIB_H_

#include "types.h"

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
