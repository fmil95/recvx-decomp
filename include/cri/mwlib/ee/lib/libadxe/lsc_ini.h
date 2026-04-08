#ifndef	_LSC_INI_H_
#define	_LSC_INI_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "lsc.h"

extern LSC_OBJ lsc_obj[LSC_OBJ_MAX];

void lsc_DeleteSvrInt(void);
void lsc_EntrySvrInt(void);
void LSC_Finish(void);
void LSC_Init(void);

#endif
