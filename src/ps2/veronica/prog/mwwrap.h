#ifndef _MWWRAP_H_
#define _MWWRAP_H_

void InitMwSystem(unsigned int Mode, void* pPrm);
void ReinitMwSystem(MWS_PLY_INIT_SFD* pPrm);
void ExitMwSystem();
void SetMwSoundMode();
void GetMwPlayTime(int* ncount, int* tscale);
int GetMwPlayTimeEx();
void CreateSfdHandle(void* mp, void* pp, char* fname);
void CreateWaveHandle(void* unused);
void CreateTmHandle();
void PlayMwOpenMain(char* FileName, int Mode, void* mp, void* pp, int PauseFlag);
void PlayMw2(char* FileName, int Mode, void* mp, void* pp, int PauseFlag);
void StopMw();
MWE_PLY_STAT GetMwStatus();
int PlayMwMain2(void(*Func)());
int PlayMwMain();
void PauseMw();
void RestartMw();
void SetMwVolume(int Volume);
int GetSfdFadeRate();
void SetSfdDislpaySize(float PosX, float PosY, float SizeX, float SizeY);

#endif
