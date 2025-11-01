#ifndef	_LSC_SVR_H_
#define	_LSC_SVR_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include <cri_lsc.h>

void lsc_ExecHndl(LSC lsc);
void lsc_StatEnd(LSC lsc);
void lsc_StatRead(LSC lsc);
void lsc_StatWait(LSC lsc);

#endif
