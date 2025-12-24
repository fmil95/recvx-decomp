#ifndef _SDC_H_
#define _SDC_H_

#include "types.h"

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

extern unsigned int SddFirstFlag;
extern char SdcGdDaVolume;

/*typedef struct _anon0;
typedef struct SDS_MEMBLK;
typedef struct SDS_PORT_REF;
typedef struct _anon1;
typedef enum SDE_DATA_TYPE;
typedef struct SDS_MIDI_STAT;
typedef struct SDS_SHOT_STAT;

typedef void(*type_1)();
typedef void(*type_6)(void*);

typedef unsigned int type_0[16];
typedef _anon0 type_2[8];
typedef SDS_PORT_REF** type_3[8];
typedef _anon0 type_4[20];
typedef SDS_PORT_REF** type_5[20];

struct _anon0
{
	unsigned int Flag;
	int FadeFunc;
	int FadeCntMax;
	float Volume;
	float VolSpeed;
	float VolLast;
	float LimitMaxVol;
	int PanFunc;
	int PanCntMax;
	float Pan;
	float PanSpeed;
	float PanLast;
};

struct SDS_MEMBLK
{
	unsigned int m_Member[16];
};

struct SDS_PORT_REF
{
	void* m_Ref;
};

struct _anon1
{
	unsigned int SlotNo;
	short PanDelayTime;
	short VolumeDelayTime;
	short Pitch;
	short PitchDelayTime;
	short Speed;
	short SpeedDelayTime;
	char BankNo;
	char ListNo;
	char Priority;
	char Pan;
	char Volume;
	char FxInput;
	char FxLevel;
};

enum SDE_DATA_TYPE
{
	SDE_DATA_TYPE_SND_DRV = 0x56524453,
	SDE_DATA_TYPE_MULTI_UNIT = 0x544c4d53,
	SDE_DATA_TYPE_MIDI_DRM_BANK = 0x42444d53,
	SDE_DATA_TYPE_MIDI_SEQ_BANK = 0x42534d53,
	SDE_DATA_TYPE_MIDI_PRG_BANK = 0x42504d53,
	SDE_DATA_TYPE_SHOT_BANK = 0x42534f53,
	SDE_DATA_TYPE_PSTM_RING_BUF = 0x52535053,
	SDE_DATA_TYPE_FX_OUT_BANK = 0x424f4653,
	SDE_DATA_TYPE_FX_PRG_BANK = 0x42504653,
	SDE_DATA_TYPE_FX_PRG_WRK = 0x57504653
};

struct SDS_MIDI_STAT
{
	short rsv;
	char m_Vol;
	char m_Pan;
	char m_FxLev;
	char m_DrctLev;
	short m_Pitch;
	short m_Speed;
	unsigned int m_TotalBeatTime;
	int m_CurAdr;
	unsigned int m_Err;
	unsigned int m_Flg;
};

struct SDS_SHOT_STAT
{
	short rsv;
	char m_Vol;
	char m_Pan;
	char m_FxLev;
	char m_DrctLev;
	short m_Pitch;
	short rsv2;
	unsigned int m_TotalSmpFrame;
	int m_CurAdr;
	unsigned int m_Err;
	unsigned int m_Flg;
};*/

#endif
