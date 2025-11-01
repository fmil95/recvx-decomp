#ifndef _ADX_INIS_H_
#define _ADX_INIS_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxt.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>

#define	ADXT_MAX_OBJ		(8) // TODO: this should be in override_adxt.h

extern Sint32 adxt_init_cnt;
extern ADX_TALK adxt_obj[ADXT_MAX_OBJ];
extern Uint32 adxt_vsync_cnt;

void adxini_rnaerr_cbfn(void *obj, const Char8 *msg);
void ADXT_ConfigVsyncSvr(Sint32 vsync_svr_flag);
void ADXT_Finish(void);
void ADXT_Init(void);
void ADXT_ResetLibrary(void);
void ADXT_VsyncProc(void);

#endif
