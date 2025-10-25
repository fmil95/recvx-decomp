#ifndef _ADX_INIS_H_
#define _ADX_INIS_H_

void adxini_rnaerr_cbfn(void *obj, const Char8 *msg);
void ADXT_ConfigVsyncSvr(Sint32 vsync_svr_flag);
void ADXT_Finish(void);
void ADXT_Init(void);
void ADXT_ResetLibrary(void);
void ADXT_VsyncProc(void);

#endif
