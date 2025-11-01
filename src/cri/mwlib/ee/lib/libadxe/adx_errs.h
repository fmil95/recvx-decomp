#ifndef _ADX_ERRS_H_
#define _ADX_ERRS_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>

void ADXERR_CallErrFunc1(const Sint8 *msg);
void ADXERR_CallErrFunc2(const Sint8 *msg1, const Sint8 *msg2);
void ADXERR_EntryErrFunc(void (*func)(), void *obj);
void ADXERR_Finish(void);
void ADXERR_Init(void);
void ADXERR_ItoA(Sint32 val, Sint8 *str, Sint32 len);
void ADXERR_ItoA2(Sint32 val, Sint32 val2, Sint8 *str, Sint32 len);

#endif
