#ifndef	_LSC_ERR_H_
#define	_LSC_ERR_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "lsc.h"
#include <stdarg.h>

void LSC_CallErrFunc(Sint8 *fmt, ...);
void LSC_EntryErrFunc(LSC_ERRFN errfn, void *obj);

#endif
