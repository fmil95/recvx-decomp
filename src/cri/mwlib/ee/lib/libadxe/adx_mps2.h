#ifndef _ADX_MPS2_H_
#define _ADX_MPS2_H_

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
