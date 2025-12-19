#ifndef _PS2_SFD_MW_H_
#define _PS2_SFD_MW_H_

#include "types.h"

Sint32 mwPlyCalcWorkSofdec(Sint32 ftype, Sint32 max_bps, Sint32 max_sx, Sint32 max_sy, Sint32 nfb);
MWPLY ps2mwPlyCreateSofdec(MWS_PLY_CPRM_SFD* cprm, char* fname);
void mwPlyExecServer(void);
void mwPlyFinishSofdec(void);
Sint32 mwPlyGetBright(MWPLY mwply);
void mwPlyInitSofdec(MWS_PLY_INIT_SFD *iprm);
void mwPlyPreInitSofdec(void);
void mwPlySetDispMode(Sint32 mode, Sint32 frame, Sint32 count, Sint32 latency);
void mwPlySetDispPos(MWPLY mwply, float lx, float ly);
void mwPlySetFastHalfpel(MWPLY mwply, Sint32 sw);
void mwPlyStartFrame(void);
void mwPlySetDispSize(MWPLY mwply, float sx, float sy);
void ps2mwPlyVsyncHndl(MWPLY ply);
void ps2mwPlyExecSvrHndl(MWPLY ply);
void ps2mwPlyDestroy(MWPLY ply);
void ps2mwPlyStartFname(MWPLY ply, Sint8 *fname);
void ps2mwPlyStop(MWPLY ply);
MWE_PLY_STAT ps2mwPlyGetStat(MWPLY ply);
void ps2mwPlyGetTime(MWPLY ply, Sint32 *ncount, Sint32 *tscale);
void ps2mwPlyPause(MWPLY ply, Sint32 sw);
void ps2mwPlySetOutVol(MWPLY ply, Sint32 vol);
Sint32 ps2mwPlyGetOutVol(MWPLY ply);
void ps2mwErrorStop();
void Setps2FuncTbl(MWPLY mwply);

extern StrFile infile;
extern MDSIZE_WORK mdSize;

#endif
