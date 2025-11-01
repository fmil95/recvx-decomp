#ifndef _ADX_MPS2_H_
#define _ADX_MPS2_H_

#include <adx_ps2.h>
#include <PREFIX_PS2.h>
#include <eekernel.h>

// TODO: move these two defines and the typedef below elsewhere
#define bss_align(val) \
    __attribute__ ((aligned(val))) __attribute__ ((section (".bss"))) 
#define DEF_STACK_SIZE    2048

typedef struct ThreadParam ThreadParam; 

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
