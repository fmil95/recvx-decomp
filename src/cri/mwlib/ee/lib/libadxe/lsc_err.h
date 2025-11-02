#ifndef	_LSC_ERR_H_
#define	_LSC_ERR_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "lsc.h"
#include <stdarg.h>
#include <va-mips.h>

void LSC_CallErrFunc(const char *fmt, ...);
void LSC_EntryErrFunc(LSC_ERRFN errfn, void *obj);

#endif
