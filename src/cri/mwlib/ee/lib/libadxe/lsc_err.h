#ifndef	_LSC_ERR_H_
#define	_LSC_ERR_H_

#include <cri_lsc.h>

void LSC_CallErrFunc(const char *fmt, ...);
void LSC_EntryErrFunc(LSC_ERRFN errfn, void *obj);

#endif
