#ifndef	_LSC_H_
#define	_LSC_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include <cri_lsc.h>

LSC lsc_Alloc(void);
void LSC_CallStatFunc(void);
LSC LSC_Create(SJ sj);
void LSC_Destroy(LSC lsc);
void LSC_EntryChgStatFunc(LSC_STATFN statfn, void *obj1, void *obj2);
Sint32 LSC_EntryFileRange(LSC lsc, Sint8 *fname, void *dir, Sint32 ofst, Sint32 nsct);
Sint32 LSC_EntryFname(LSC lsc, Sint8 *fname);
void LSC_ExecServer(void);
Sint32 LSC_GetFlowLimit(LSC lsc);
Sint32 LSC_GetNumStm(LSC lsc);
Sint32 LSC_GetStat(LSC lsc);
Sint8* LSC_GetStmFname(LSC lsc, Sint32 sid);
Sint32 LSC_GetStmId(LSC lsc, Sint32 no);
Sint32 LSC_GetStmRdSct(LSC lsc, Sint32 sid);
Sint32 LSC_GetStmStat(LSC lsc, Sint32 sid);
void LSC_Pause(LSC lsc, Sint32 sw);
void LSC_SetFlowLimit(LSC lsc, Sint32 min);
void LSC_SetLpFlg(LSC lsc, Sint32 flg);
void LSC_Start(LSC lsc);
void LSC_Stop(LSC lsc);

#endif
