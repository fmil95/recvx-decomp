#ifndef _ADX_MPS2_H_
#define _ADX_MPS2_H_

#include <adx_ps2.h>
#include <eekernel.h>
#include "macros.h"

#define DEF_STACK_SIZE    2048 // borrowed from PS2 devkit sample code 

typedef struct ThreadParam ThreadParam; // this struct lacks a typedef where it gets defined in the SDK

void adxps2_adx_thrd_func(void);
void ADXPS2_ExecServer(void);
void ADXPS2_Lock(void);
void ADXPS2_RestoreVsyncCallback(void);
void adxps2_safe_thrd_func(void);
void ADXPS2_SetupThrd(ADXPS2_TPRM *tprm);
void ADXPS2_SetupUsvr(void);
void ADXPS2_Shutdown(void);
void ADXPS2_ShutdownThrd(void);
void ADXPS2_Unlock(void);
int ADXPS2_VsyncCallback(int arg);

#endif
