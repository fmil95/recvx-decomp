#ifndef _SDC_H_
#define _SDC_H_

#include "types.h"

typedef struct SDS_INFO
{
	// total size: 0x30
	unsigned int Flag; // offset 0x0, size 0x4
    int FadeFunc;      // offset 0x4, size 0x4
    int FadeCntMax;    // offset 0x8, size 0x4
    float Volume;      // offset 0xC, size 0x4
    float VolSpeed;    // offset 0x10, size 0x4
    float VolLast;     // offset 0x14, size 0x4
    float LimitMaxVol; // offset 0x18, size 0x4
    int PanFunc;       // offset 0x1C, size 0x4
    int PanCntMax;     // offset 0x20, size 0x4
    float Pan;         // offset 0x24, size 0x4
    float PanSpeed;    // offset 0x28, size 0x4
    float PanLast;     // offset 0x2C, size 0x4
} SDS_INFO;

void TransWaitCallBackFunction();
unsigned int CheckTransComplete();
void SetupSoundDriver(void* pSndDrv, unsigned int SndDrvSize);
void ExitSoundDriver();
void SetMultiUnit(void* pMulUni, unsigned int MulUniSize);
void SetSoundData(SDE_DATA_TYPE DataType, int BankNo, void* pSndDat, unsigned int SndDatSize);
void SetSoundModeEx(int Mode, int Flag);
void SetSoundMode(int Mode);
int GetSoundMode();
void SetMasterVolume(char Volume);
void SetGdDaVolume(char Volume);
void InitMidiInfo();
unsigned int RegistMidiSlot(unsigned int SlotNo);
void FreeMidiSlot(unsigned int SlotNo);
unsigned int CheckPlayMidi(unsigned int SlotNo);
void PlayMidi(unsigned int SlotNo, char BankNo, char ListNo, char Priority);
void ExPlayMidi(SND_REQ* pRequestInfo); 
void StopMidi(unsigned int SlotNo);
void SetPanMidi2(unsigned int SlotNo, float Pan, short DelayTime);
void SetPanMidi(unsigned int SlotNo, char Pan, short DelayTime);
void SetVolumeMidiEx(unsigned int SlotNo, float Volume, short DelayTime, int Flag);
void SetVolumeMidi(unsigned int SlotNo, char Volume, short DelayTime);
void SetVolumeMidi2(unsigned int SlotNo, float Volume, short DelayTime);
void SetPitchMidi(unsigned int SlotNo, short Pitch, short DelayTime);
void SetSpeedMidi(unsigned int SlotNo, short Speed, short DelayTime);
void SetFxLevelMidi(unsigned int SlotNo, char FxLevel);
void SetMidiDefaultVolume(char Volume);
void InitSeInfo();
unsigned int RegistSeSlot(unsigned int SlotNo);
void FreeSeSlot(unsigned int SlotNo);
unsigned int CheckPlaySe(unsigned int SlotNo);
void PlaySe(unsigned int SlotNo, char BankNo, char ListNo, char Priority);
void ExPlaySe(SND_REQ* pRequestInfo);
void StopSe(unsigned int SlotNo);
void SetPanSe2(unsigned int SlotNo, float Pan, short DelayTime);
void SetPanSe(unsigned int SlotNo, char Pan, short DelayTime);
void SetVolumeSeEx(unsigned int SlotNo, float Volume, short DelayTime, int Flag);
void SetVolumeSe(unsigned int SlotNo, char Volume, short DelayTime);
void SetVolumeSe2(unsigned int SlotNo, float Volume, short DelayTime);
void SetPitchSe(unsigned int SlotNo, short Pitch, short DelayTime);
void SetFxLevelSe(unsigned int SlotNo, char FxLevel);
void SetSeDefaultVolume(char Volume);
void SetFxProgram(char FxProgramNo, char FxOutputNo);
void StopFxProgram();
void RequestMidiFadeFunction(int SlotNo, int Func, short Timer);
void RequestMidiFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame);
void StopFadeMidi(int SlotNo);
void RequestSeFadeFunction(int SlotNo, int Func, short Timer);
void RequestSeFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame);
void StopFadeSe(int SlotNo);
int CheckFadeEndSe(int SlotNo);
int ExecSoundFadeManager();
void RequestMidiPanFunctionEx(int SlotNo, int StartPan, int LastPan, int Frame);
void RequestSePanFunctionEx(int SlotNo, int StartPan, int LastPan, int Frame);
int ExecSoundPanManager();

extern char SdcGdDaVolume;
extern unsigned int SddFirstFlag;

#endif
