typedef struct _anon0;
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
};

unsigned int SddFirstFlag;
unsigned int ExecFxFlag;
int SdcSoundMode;
void(*TransCallBackFunc)(void*);
unsigned int TransCompleteFlag;
SDS_MEMBLK* SdMemBlk;
void(*TransWaitCallBackFunction)();
char SdcMasterVolume;
char SdcGdDaVolume;
_anon0 MidiInfo[8];
SDS_PORT_REF** MidiHandle[8];
char SdcSeDefaultVolume;
char SdcMidiDefaultVolume;
_anon0 SeInfo[20];
SDS_PORT_REF** SeHandle[20];

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
void ExPlayMidi(_anon1* pRequestInfo);
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
void ExPlaySe(_anon1* pRequestInfo);
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

// 
// Start address: 0x28ecd0
void TransWaitCallBackFunction()
{
	// Line 28, Address: 0x28ecd0, Func Offset: 0
	// Line 29, Address: 0x28ecd8, Func Offset: 0x8
	// Line 30, Address: 0x28ece4, Func Offset: 0x14
	// Line 31, Address: 0x28ecec, Func Offset: 0x1c
	// Func End, Address: 0x28ecf8, Func Offset: 0x28
}

// 
// Start address: 0x28ed00
unsigned int CheckTransComplete()
{
	// Line 35, Address: 0x28ed00, Func Offset: 0
	// Line 36, Address: 0x28ed04, Func Offset: 0x4
	// Func End, Address: 0x28ed0c, Func Offset: 0xc
}

// 
// Start address: 0x28ed10
void SetupSoundDriver(void* pSndDrv, unsigned int SndDrvSize)
{
	// Line 39, Address: 0x28ed10, Func Offset: 0
	// Line 40, Address: 0x28ed28, Func Offset: 0x18
	// Line 41, Address: 0x28ed38, Func Offset: 0x28
	// Line 44, Address: 0x28ed44, Func Offset: 0x34
	// Line 43, Address: 0x28ed4c, Func Offset: 0x3c
	// Line 44, Address: 0x28ed50, Func Offset: 0x40
	// Line 43, Address: 0x28ed58, Func Offset: 0x48
	// Line 44, Address: 0x28ed60, Func Offset: 0x50
	// Line 45, Address: 0x28ed70, Func Offset: 0x60
	// Line 47, Address: 0x28ed7c, Func Offset: 0x6c
	// Line 49, Address: 0x28ed88, Func Offset: 0x78
	// Line 50, Address: 0x28ed90, Func Offset: 0x80
	// Line 53, Address: 0x28ed9c, Func Offset: 0x8c
	// Line 55, Address: 0x28edb0, Func Offset: 0xa0
	// Func End, Address: 0x28edc4, Func Offset: 0xb4
}

// 
// Start address: 0x28edd0
void ExitSoundDriver()
{
	// Line 58, Address: 0x28edd0, Func Offset: 0
	// Line 59, Address: 0x28edd8, Func Offset: 0x8
	// Line 60, Address: 0x28ede0, Func Offset: 0x10
	// Line 61, Address: 0x28ede8, Func Offset: 0x18
	// Line 62, Address: 0x28edf0, Func Offset: 0x20
	// Func End, Address: 0x28edfc, Func Offset: 0x2c
}

// 
// Start address: 0x28ee00
void SetMultiUnit(void* pMulUni, unsigned int MulUniSize)
{
	// Line 65, Address: 0x28ee00, Func Offset: 0
	// Line 66, Address: 0x28ee10, Func Offset: 0x10
	// Line 65, Address: 0x28ee14, Func Offset: 0x14
	// Line 66, Address: 0x28ee18, Func Offset: 0x18
	// Line 70, Address: 0x28ee24, Func Offset: 0x24
	// Line 68, Address: 0x28ee2c, Func Offset: 0x2c
	// Line 70, Address: 0x28ee30, Func Offset: 0x30
	// Line 68, Address: 0x28ee38, Func Offset: 0x38
	// Line 70, Address: 0x28ee3c, Func Offset: 0x3c
	// Line 68, Address: 0x28ee40, Func Offset: 0x40
	// Line 70, Address: 0x28ee44, Func Offset: 0x44
	// Line 72, Address: 0x28ee4c, Func Offset: 0x4c
	// Line 77, Address: 0x28ee58, Func Offset: 0x58
	// Line 78, Address: 0x28ee64, Func Offset: 0x64
	// Func End, Address: 0x28ee78, Func Offset: 0x78
}

// 
// Start address: 0x28ee80
void SetSoundData(SDE_DATA_TYPE DataType, int BankNo, void* pSndDat, unsigned int SndDatSize)
{
	// Line 81, Address: 0x28ee80, Func Offset: 0
	// Line 82, Address: 0x28ee9c, Func Offset: 0x1c
	// Line 86, Address: 0x28eeb4, Func Offset: 0x34
	// Line 84, Address: 0x28eebc, Func Offset: 0x3c
	// Line 86, Address: 0x28eec0, Func Offset: 0x40
	// Line 84, Address: 0x28eec8, Func Offset: 0x48
	// Line 86, Address: 0x28eed0, Func Offset: 0x50
	// Line 87, Address: 0x28eee0, Func Offset: 0x60
	// Line 94, Address: 0x28eef8, Func Offset: 0x78
	// Func End, Address: 0x28ef14, Func Offset: 0x94
}

// 
// Start address: 0x28ef20
void SetSoundModeEx(int Mode, int Flag)
{
	// Line 97, Address: 0x28ef20, Func Offset: 0
	// Line 98, Address: 0x28ef34, Func Offset: 0x14
	// Line 100, Address: 0x28ef3c, Func Offset: 0x1c
	// Line 104, Address: 0x28ef44, Func Offset: 0x24
	// Line 105, Address: 0x28ef50, Func Offset: 0x30
	// Line 107, Address: 0x28ef58, Func Offset: 0x38
	// Line 111, Address: 0x28ef60, Func Offset: 0x40
	// Line 113, Address: 0x28ef6c, Func Offset: 0x4c
	// Line 115, Address: 0x28ef70, Func Offset: 0x50
	// Line 116, Address: 0x28ef78, Func Offset: 0x58
	// Line 118, Address: 0x28ef80, Func Offset: 0x60
	// Func End, Address: 0x28ef94, Func Offset: 0x74
}

// 
// Start address: 0x28efa0
void SetSoundMode(int Mode)
{
	// Line 122, Address: 0x28efa0, Func Offset: 0
	// Func End, Address: 0x28efa8, Func Offset: 0x8
}

// 
// Start address: 0x28efb0
int GetSoundMode()
{
	int Mode;
	// Line 126, Address: 0x28efb0, Func Offset: 0
	// Line 129, Address: 0x28efb8, Func Offset: 0x8
	// Line 130, Address: 0x28efcc, Func Offset: 0x1c
	// Line 131, Address: 0x28efd4, Func Offset: 0x24
	// Line 135, Address: 0x28efe0, Func Offset: 0x30
	// Line 134, Address: 0x28efe4, Func Offset: 0x34
	// Line 135, Address: 0x28efec, Func Offset: 0x3c
	// Func End, Address: 0x28eff4, Func Offset: 0x44
}

// 
// Start address: 0x28f000
void SetMasterVolume(char Volume)
{
	// Line 138, Address: 0x28f000, Func Offset: 0
	// Line 139, Address: 0x28f00c, Func Offset: 0xc
	// Line 140, Address: 0x28f014, Func Offset: 0x14
	// Line 141, Address: 0x28f01c, Func Offset: 0x1c
	// Func End, Address: 0x28f02c, Func Offset: 0x2c
}

// 
// Start address: 0x28f030
void SetGdDaVolume(char Volume)
{
	// Line 150, Address: 0x28f030, Func Offset: 0
	// Line 151, Address: 0x28f034, Func Offset: 0x4
	// Func End, Address: 0x28f03c, Func Offset: 0xc
}

// 
// Start address: 0x28f040
void InitMidiInfo()
{
	unsigned int i;
	// Line 154, Address: 0x28f040, Func Offset: 0
	// Line 157, Address: 0x28f058, Func Offset: 0x18
	// Line 158, Address: 0x28f05c, Func Offset: 0x1c
	// Line 160, Address: 0x28f06c, Func Offset: 0x2c
	// Line 161, Address: 0x28f074, Func Offset: 0x34
	// Line 163, Address: 0x28f080, Func Offset: 0x40
	// Line 164, Address: 0x28f084, Func Offset: 0x44
	// Line 165, Address: 0x28f088, Func Offset: 0x48
	// Line 167, Address: 0x28f08c, Func Offset: 0x4c
	// Line 166, Address: 0x28f090, Func Offset: 0x50
	// Line 167, Address: 0x28f094, Func Offset: 0x54
	// Line 168, Address: 0x28f0a0, Func Offset: 0x60
	// Func End, Address: 0x28f0b4, Func Offset: 0x74
}

// 
// Start address: 0x28f0c0
unsigned int RegistMidiSlot(unsigned int SlotNo)
{
	// Line 172, Address: 0x28f0c0, Func Offset: 0
	// Line 171, Address: 0x28f0c8, Func Offset: 0x8
	// Line 172, Address: 0x28f0cc, Func Offset: 0xc
	// Line 171, Address: 0x28f0d4, Func Offset: 0x14
	// Line 172, Address: 0x28f0d8, Func Offset: 0x18
	// Line 171, Address: 0x28f0dc, Func Offset: 0x1c
	// Line 172, Address: 0x28f0e0, Func Offset: 0x20
	// Line 173, Address: 0x28f0f0, Func Offset: 0x30
	// Line 178, Address: 0x28f0f8, Func Offset: 0x38
	// Line 179, Address: 0x28f10c, Func Offset: 0x4c
	// Line 183, Address: 0x28f114, Func Offset: 0x54
	// Line 184, Address: 0x28f118, Func Offset: 0x58
	// Func End, Address: 0x28f128, Func Offset: 0x68
}

// 
// Start address: 0x28f130
void FreeMidiSlot(unsigned int SlotNo)
{
	// Line 188, Address: 0x28f130, Func Offset: 0
	// Line 187, Address: 0x28f138, Func Offset: 0x8
	// Line 188, Address: 0x28f13c, Func Offset: 0xc
	// Line 187, Address: 0x28f144, Func Offset: 0x14
	// Line 188, Address: 0x28f148, Func Offset: 0x18
	// Line 187, Address: 0x28f14c, Func Offset: 0x1c
	// Line 188, Address: 0x28f150, Func Offset: 0x20
	// Line 192, Address: 0x28f160, Func Offset: 0x30
	// Line 195, Address: 0x28f178, Func Offset: 0x48
	// Line 196, Address: 0x28f17c, Func Offset: 0x4c
	// Func End, Address: 0x28f18c, Func Offset: 0x5c
}

// 
// Start address: 0x28f190
unsigned int CheckPlayMidi(unsigned int SlotNo)
{
	SDS_MIDI_STAT Status;
	// Line 207, Address: 0x28f190, Func Offset: 0
	// Line 204, Address: 0x28f198, Func Offset: 0x8
	// Line 207, Address: 0x28f19c, Func Offset: 0xc
	// Line 204, Address: 0x28f1a4, Func Offset: 0x14
	// Line 207, Address: 0x28f1a8, Func Offset: 0x18
	// Line 208, Address: 0x28f1b4, Func Offset: 0x24
	// Line 209, Address: 0x28f1b8, Func Offset: 0x28
	// Line 208, Address: 0x28f1bc, Func Offset: 0x2c
	// Line 209, Address: 0x28f1c0, Func Offset: 0x30
	// Func End, Address: 0x28f1c8, Func Offset: 0x38
}

// 
// Start address: 0x28f1d0
void PlayMidi(unsigned int SlotNo, char BankNo, char ListNo, char Priority)
{
	// Line 213, Address: 0x28f1d0, Func Offset: 0
	// Line 212, Address: 0x28f1e4, Func Offset: 0x14
	// Line 213, Address: 0x28f1e8, Func Offset: 0x18
	// Line 212, Address: 0x28f1ec, Func Offset: 0x1c
	// Line 213, Address: 0x28f1f0, Func Offset: 0x20
	// Line 214, Address: 0x28f1fc, Func Offset: 0x2c
	// Line 215, Address: 0x28f210, Func Offset: 0x40
	// Line 218, Address: 0x28f228, Func Offset: 0x58
	// Func End, Address: 0x28f234, Func Offset: 0x64
}

// 
// Start address: 0x28f240
void ExPlayMidi(_anon1* pRequestInfo)
{
	// Line 221, Address: 0x28f240, Func Offset: 0
	// Line 222, Address: 0x28f250, Func Offset: 0x10
	// Line 223, Address: 0x28f278, Func Offset: 0x38
	// Line 225, Address: 0x28f29c, Func Offset: 0x5c
	// Line 226, Address: 0x28f2a8, Func Offset: 0x68
	// Line 228, Address: 0x28f2b0, Func Offset: 0x70
	// Line 233, Address: 0x28f2bc, Func Offset: 0x7c
	// Line 235, Address: 0x28f2e0, Func Offset: 0xa0
	// Line 236, Address: 0x28f2f4, Func Offset: 0xb4
	// Line 238, Address: 0x28f2fc, Func Offset: 0xbc
	// Line 243, Address: 0x28f308, Func Offset: 0xc8
	// Line 245, Address: 0x28f32c, Func Offset: 0xec
	// Line 246, Address: 0x28f33c, Func Offset: 0xfc
	// Line 248, Address: 0x28f344, Func Offset: 0x104
	// Line 253, Address: 0x28f350, Func Offset: 0x110
	// Line 255, Address: 0x28f374, Func Offset: 0x134
	// Line 256, Address: 0x28f384, Func Offset: 0x144
	// Line 258, Address: 0x28f38c, Func Offset: 0x14c
	// Line 263, Address: 0x28f398, Func Offset: 0x158
	// Line 264, Address: 0x28f3a8, Func Offset: 0x168
	// Line 267, Address: 0x28f3c8, Func Offset: 0x188
	// Line 269, Address: 0x28f3dc, Func Offset: 0x19c
	// Func End, Address: 0x28f3ec, Func Offset: 0x1ac
}

// 
// Start address: 0x28f3f0
void StopMidi(unsigned int SlotNo)
{
	// Line 273, Address: 0x28f3f0, Func Offset: 0
	// Line 272, Address: 0x28f404, Func Offset: 0x14
	// Line 273, Address: 0x28f408, Func Offset: 0x18
	// Line 272, Address: 0x28f40c, Func Offset: 0x1c
	// Line 273, Address: 0x28f410, Func Offset: 0x20
	// Line 274, Address: 0x28f41c, Func Offset: 0x2c
	// Line 276, Address: 0x28f434, Func Offset: 0x44
	// Func End, Address: 0x28f440, Func Offset: 0x50
}

// 
// Start address: 0x28f440
void SetPanMidi2(unsigned int SlotNo, float Pan, short DelayTime)
{
	// Line 311, Address: 0x28f440, Func Offset: 0
	// Line 312, Address: 0x28f450, Func Offset: 0x10
	// Line 311, Address: 0x28f454, Func Offset: 0x14
	// Line 312, Address: 0x28f458, Func Offset: 0x18
	// Line 311, Address: 0x28f468, Func Offset: 0x28
	// Line 312, Address: 0x28f46c, Func Offset: 0x2c
	// Line 313, Address: 0x28f484, Func Offset: 0x44
	// Line 314, Address: 0x28f4b8, Func Offset: 0x78
	// Line 315, Address: 0x28f4e8, Func Offset: 0xa8
	// Line 318, Address: 0x28f4f8, Func Offset: 0xb8
	// Func End, Address: 0x28f514, Func Offset: 0xd4
}

// 
// Start address: 0x28f520
void SetPanMidi(unsigned int SlotNo, char Pan, short DelayTime)
{
	// Line 322, Address: 0x28f520, Func Offset: 0
	// Func End, Address: 0x28f534, Func Offset: 0x14
}

// 
// Start address: 0x28f540
void SetVolumeMidiEx(unsigned int SlotNo, float Volume, short DelayTime, int Flag)
{
	// Line 326, Address: 0x28f540, Func Offset: 0
	// Line 327, Address: 0x28f550, Func Offset: 0x10
	// Line 326, Address: 0x28f554, Func Offset: 0x14
	// Line 327, Address: 0x28f558, Func Offset: 0x18
	// Line 326, Address: 0x28f568, Func Offset: 0x28
	// Line 327, Address: 0x28f56c, Func Offset: 0x2c
	// Line 328, Address: 0x28f584, Func Offset: 0x44
	// Line 330, Address: 0x28f5bc, Func Offset: 0x7c
	// Line 331, Address: 0x28f5e8, Func Offset: 0xa8
	// Line 332, Address: 0x28f5f4, Func Offset: 0xb4
	// Line 334, Address: 0x28f5fc, Func Offset: 0xbc
	// Line 335, Address: 0x28f604, Func Offset: 0xc4
	// Line 336, Address: 0x28f624, Func Offset: 0xe4
	// Line 339, Address: 0x28f64c, Func Offset: 0x10c
	// Line 341, Address: 0x28f65c, Func Offset: 0x11c
	// Line 345, Address: 0x28f690, Func Offset: 0x150
	// Func End, Address: 0x28f6ac, Func Offset: 0x16c
}

// 
// Start address: 0x28f6b0
void SetVolumeMidi(unsigned int SlotNo, char Volume, short DelayTime)
{
	// Line 349, Address: 0x28f6b0, Func Offset: 0
	// Func End, Address: 0x28f6c8, Func Offset: 0x18
}

// 
// Start address: 0x28f6d0
void SetVolumeMidi2(unsigned int SlotNo, float Volume, short DelayTime)
{
	// Line 354, Address: 0x28f6d0, Func Offset: 0
	// Func End, Address: 0x28f6d8, Func Offset: 0x8
}

// 
// Start address: 0x28f6e0
void SetPitchMidi(unsigned int SlotNo, short Pitch, short DelayTime)
{
	// Line 359, Address: 0x28f6e0, Func Offset: 0
	// Line 358, Address: 0x28f6f4, Func Offset: 0x14
	// Line 359, Address: 0x28f6f8, Func Offset: 0x18
	// Line 358, Address: 0x28f6fc, Func Offset: 0x1c
	// Line 359, Address: 0x28f700, Func Offset: 0x20
	// Line 360, Address: 0x28f70c, Func Offset: 0x2c
	// Line 362, Address: 0x28f72c, Func Offset: 0x4c
	// Func End, Address: 0x28f738, Func Offset: 0x58
}

// 
// Start address: 0x28f740
void SetSpeedMidi(unsigned int SlotNo, short Speed, short DelayTime)
{
	// Line 366, Address: 0x28f740, Func Offset: 0
	// Line 365, Address: 0x28f754, Func Offset: 0x14
	// Line 366, Address: 0x28f758, Func Offset: 0x18
	// Line 365, Address: 0x28f75c, Func Offset: 0x1c
	// Line 366, Address: 0x28f760, Func Offset: 0x20
	// Line 367, Address: 0x28f76c, Func Offset: 0x2c
	// Line 369, Address: 0x28f78c, Func Offset: 0x4c
	// Func End, Address: 0x28f798, Func Offset: 0x58
}

// 
// Start address: 0x28f7a0
void SetFxLevelMidi(unsigned int SlotNo, char FxLevel)
{
	// Line 373, Address: 0x28f7a0, Func Offset: 0
	// Line 372, Address: 0x28f7b4, Func Offset: 0x14
	// Line 373, Address: 0x28f7b8, Func Offset: 0x18
	// Line 372, Address: 0x28f7bc, Func Offset: 0x1c
	// Line 373, Address: 0x28f7c0, Func Offset: 0x20
	// Line 374, Address: 0x28f7cc, Func Offset: 0x2c
	// Line 376, Address: 0x28f7e4, Func Offset: 0x44
	// Func End, Address: 0x28f7f0, Func Offset: 0x50
}

// 
// Start address: 0x28f7f0
void SetMidiDefaultVolume(char Volume)
{
	// Line 380, Address: 0x28f7f0, Func Offset: 0
	// Line 381, Address: 0x28f7f4, Func Offset: 0x4
	// Func End, Address: 0x28f7fc, Func Offset: 0xc
}

// 
// Start address: 0x28f800
void InitSeInfo()
{
	unsigned int i;
	// Line 384, Address: 0x28f800, Func Offset: 0
	// Line 387, Address: 0x28f818, Func Offset: 0x18
	// Line 388, Address: 0x28f81c, Func Offset: 0x1c
	// Line 390, Address: 0x28f82c, Func Offset: 0x2c
	// Line 391, Address: 0x28f834, Func Offset: 0x34
	// Line 393, Address: 0x28f840, Func Offset: 0x40
	// Line 394, Address: 0x28f844, Func Offset: 0x44
	// Line 395, Address: 0x28f848, Func Offset: 0x48
	// Line 397, Address: 0x28f84c, Func Offset: 0x4c
	// Line 396, Address: 0x28f850, Func Offset: 0x50
	// Line 397, Address: 0x28f854, Func Offset: 0x54
	// Line 398, Address: 0x28f860, Func Offset: 0x60
	// Func End, Address: 0x28f874, Func Offset: 0x74
}

// 
// Start address: 0x28f880
unsigned int RegistSeSlot(unsigned int SlotNo)
{
	// Line 402, Address: 0x28f880, Func Offset: 0
	// Line 401, Address: 0x28f888, Func Offset: 0x8
	// Line 402, Address: 0x28f88c, Func Offset: 0xc
	// Line 401, Address: 0x28f894, Func Offset: 0x14
	// Line 402, Address: 0x28f898, Func Offset: 0x18
	// Line 401, Address: 0x28f89c, Func Offset: 0x1c
	// Line 402, Address: 0x28f8a0, Func Offset: 0x20
	// Line 403, Address: 0x28f8b0, Func Offset: 0x30
	// Line 407, Address: 0x28f8b8, Func Offset: 0x38
	// Line 408, Address: 0x28f8cc, Func Offset: 0x4c
	// Line 412, Address: 0x28f8d4, Func Offset: 0x54
	// Line 413, Address: 0x28f8d8, Func Offset: 0x58
	// Func End, Address: 0x28f8e8, Func Offset: 0x68
}

// 
// Start address: 0x28f8f0
void FreeSeSlot(unsigned int SlotNo)
{
	// Line 417, Address: 0x28f8f0, Func Offset: 0
	// Line 416, Address: 0x28f8f8, Func Offset: 0x8
	// Line 417, Address: 0x28f8fc, Func Offset: 0xc
	// Line 416, Address: 0x28f904, Func Offset: 0x14
	// Line 417, Address: 0x28f908, Func Offset: 0x18
	// Line 416, Address: 0x28f90c, Func Offset: 0x1c
	// Line 417, Address: 0x28f910, Func Offset: 0x20
	// Line 421, Address: 0x28f920, Func Offset: 0x30
	// Line 424, Address: 0x28f938, Func Offset: 0x48
	// Line 425, Address: 0x28f93c, Func Offset: 0x4c
	// Func End, Address: 0x28f94c, Func Offset: 0x5c
}

// 
// Start address: 0x28f950
unsigned int CheckPlaySe(unsigned int SlotNo)
{
	SDS_SHOT_STAT Status;
	// Line 436, Address: 0x28f950, Func Offset: 0
	// Line 433, Address: 0x28f958, Func Offset: 0x8
	// Line 436, Address: 0x28f95c, Func Offset: 0xc
	// Line 433, Address: 0x28f964, Func Offset: 0x14
	// Line 436, Address: 0x28f968, Func Offset: 0x18
	// Line 437, Address: 0x28f974, Func Offset: 0x24
	// Line 438, Address: 0x28f978, Func Offset: 0x28
	// Line 437, Address: 0x28f97c, Func Offset: 0x2c
	// Line 438, Address: 0x28f980, Func Offset: 0x30
	// Func End, Address: 0x28f988, Func Offset: 0x38
}

// 
// Start address: 0x28f990
void PlaySe(unsigned int SlotNo, char BankNo, char ListNo, char Priority)
{
	// Line 444, Address: 0x28f990, Func Offset: 0
	// Line 441, Address: 0x28f9a4, Func Offset: 0x14
	// Line 444, Address: 0x28f9a8, Func Offset: 0x18
	// Line 441, Address: 0x28f9ac, Func Offset: 0x1c
	// Line 444, Address: 0x28f9b0, Func Offset: 0x20
	// Line 445, Address: 0x28f9bc, Func Offset: 0x2c
	// Line 446, Address: 0x28f9d0, Func Offset: 0x40
	// Line 449, Address: 0x28f9e8, Func Offset: 0x58
	// Func End, Address: 0x28f9f4, Func Offset: 0x64
}

// 
// Start address: 0x28fa00
void ExPlaySe(_anon1* pRequestInfo)
{
	// Line 452, Address: 0x28fa00, Func Offset: 0
	// Line 453, Address: 0x28fa10, Func Offset: 0x10
	// Line 454, Address: 0x28fa38, Func Offset: 0x38
	// Line 456, Address: 0x28fa5c, Func Offset: 0x5c
	// Line 457, Address: 0x28fa68, Func Offset: 0x68
	// Line 459, Address: 0x28fa70, Func Offset: 0x70
	// Line 464, Address: 0x28fa7c, Func Offset: 0x7c
	// Line 466, Address: 0x28faa0, Func Offset: 0xa0
	// Line 467, Address: 0x28fab4, Func Offset: 0xb4
	// Line 469, Address: 0x28fabc, Func Offset: 0xbc
	// Line 474, Address: 0x28fac8, Func Offset: 0xc8
	// Line 476, Address: 0x28faec, Func Offset: 0xec
	// Line 477, Address: 0x28fafc, Func Offset: 0xfc
	// Line 479, Address: 0x28fb04, Func Offset: 0x104
	// Line 496, Address: 0x28fb10, Func Offset: 0x110
	// Line 498, Address: 0x28fb34, Func Offset: 0x134
	// Line 499, Address: 0x28fb54, Func Offset: 0x154
	// Line 501, Address: 0x28fb5c, Func Offset: 0x15c
	// Line 507, Address: 0x28fb7c, Func Offset: 0x17c
	// Line 509, Address: 0x28fb90, Func Offset: 0x190
	// Func End, Address: 0x28fba0, Func Offset: 0x1a0
}

// 
// Start address: 0x28fba0
void StopSe(unsigned int SlotNo)
{
	// Line 513, Address: 0x28fba0, Func Offset: 0
	// Line 512, Address: 0x28fbb4, Func Offset: 0x14
	// Line 513, Address: 0x28fbb8, Func Offset: 0x18
	// Line 512, Address: 0x28fbbc, Func Offset: 0x1c
	// Line 513, Address: 0x28fbc0, Func Offset: 0x20
	// Line 514, Address: 0x28fbcc, Func Offset: 0x2c
	// Line 516, Address: 0x28fbe4, Func Offset: 0x44
	// Func End, Address: 0x28fbf0, Func Offset: 0x50
}

// 
// Start address: 0x28fbf0
void SetPanSe2(unsigned int SlotNo, float Pan, short DelayTime)
{
	// Line 556, Address: 0x28fbf0, Func Offset: 0
	// Line 557, Address: 0x28fc00, Func Offset: 0x10
	// Line 556, Address: 0x28fc04, Func Offset: 0x14
	// Line 557, Address: 0x28fc08, Func Offset: 0x18
	// Line 556, Address: 0x28fc18, Func Offset: 0x28
	// Line 557, Address: 0x28fc1c, Func Offset: 0x2c
	// Line 558, Address: 0x28fc34, Func Offset: 0x44
	// Line 559, Address: 0x28fc60, Func Offset: 0x70
	// Line 561, Address: 0x28fc70, Func Offset: 0x80
	// Func End, Address: 0x28fc8c, Func Offset: 0x9c
}

// 
// Start address: 0x28fc90
void SetPanSe(unsigned int SlotNo, char Pan, short DelayTime)
{
	// Line 565, Address: 0x28fc90, Func Offset: 0
	// Func End, Address: 0x28fca4, Func Offset: 0x14
}

// 
// Start address: 0x28fcb0
void SetVolumeSeEx(unsigned int SlotNo, float Volume, short DelayTime, int Flag)
{
	// Line 569, Address: 0x28fcb0, Func Offset: 0
	// Line 570, Address: 0x28fcc0, Func Offset: 0x10
	// Line 569, Address: 0x28fcc4, Func Offset: 0x14
	// Line 570, Address: 0x28fcc8, Func Offset: 0x18
	// Line 569, Address: 0x28fcd8, Func Offset: 0x28
	// Line 570, Address: 0x28fcdc, Func Offset: 0x2c
	// Line 571, Address: 0x28fcf4, Func Offset: 0x44
	// Line 573, Address: 0x28fd2c, Func Offset: 0x7c
	// Line 574, Address: 0x28fd58, Func Offset: 0xa8
	// Line 575, Address: 0x28fd64, Func Offset: 0xb4
	// Line 577, Address: 0x28fd6c, Func Offset: 0xbc
	// Line 578, Address: 0x28fd74, Func Offset: 0xc4
	// Line 579, Address: 0x28fd94, Func Offset: 0xe4
	// Line 582, Address: 0x28fdbc, Func Offset: 0x10c
	// Line 584, Address: 0x28fdcc, Func Offset: 0x11c
	// Line 588, Address: 0x28fe00, Func Offset: 0x150
	// Func End, Address: 0x28fe1c, Func Offset: 0x16c
}

// 
// Start address: 0x28fe20
void SetVolumeSe(unsigned int SlotNo, char Volume, short DelayTime)
{
	// Line 592, Address: 0x28fe20, Func Offset: 0
	// Func End, Address: 0x28fe38, Func Offset: 0x18
}

// 
// Start address: 0x28fe40
void SetVolumeSe2(unsigned int SlotNo, float Volume, short DelayTime)
{
	// Line 597, Address: 0x28fe40, Func Offset: 0
	// Func End, Address: 0x28fe48, Func Offset: 0x8
}

// 
// Start address: 0x28fe50
void SetPitchSe(unsigned int SlotNo, short Pitch, short DelayTime)
{
	// Line 602, Address: 0x28fe50, Func Offset: 0
	// Line 601, Address: 0x28fe64, Func Offset: 0x14
	// Line 602, Address: 0x28fe68, Func Offset: 0x18
	// Line 601, Address: 0x28fe6c, Func Offset: 0x1c
	// Line 602, Address: 0x28fe70, Func Offset: 0x20
	// Line 603, Address: 0x28fe7c, Func Offset: 0x2c
	// Line 605, Address: 0x28fe9c, Func Offset: 0x4c
	// Func End, Address: 0x28fea8, Func Offset: 0x58
}

// 
// Start address: 0x28feb0
void SetFxLevelSe(unsigned int SlotNo, char FxLevel)
{
	// Line 618, Address: 0x28feb0, Func Offset: 0
	// Line 617, Address: 0x28fec4, Func Offset: 0x14
	// Line 618, Address: 0x28fec8, Func Offset: 0x18
	// Line 617, Address: 0x28fecc, Func Offset: 0x1c
	// Line 618, Address: 0x28fed0, Func Offset: 0x20
	// Line 619, Address: 0x28fedc, Func Offset: 0x2c
	// Line 621, Address: 0x28fef4, Func Offset: 0x44
	// Func End, Address: 0x28ff00, Func Offset: 0x50
}

// 
// Start address: 0x28ff00
void SetSeDefaultVolume(char Volume)
{
	// Line 625, Address: 0x28ff00, Func Offset: 0
	// Line 626, Address: 0x28ff04, Func Offset: 0x4
	// Func End, Address: 0x28ff0c, Func Offset: 0xc
}

// 
// Start address: 0x28ff10
void SetFxProgram(char FxProgramNo, char FxOutputNo)
{
	// Line 629, Address: 0x28ff10, Func Offset: 0
	// Line 630, Address: 0x28ff18, Func Offset: 0x8
	// Line 631, Address: 0x28ff20, Func Offset: 0x10
	// Line 632, Address: 0x28ff2c, Func Offset: 0x1c
	// Func End, Address: 0x28ff38, Func Offset: 0x28
}

// 
// Start address: 0x28ff40
void StopFxProgram()
{
	// Line 640, Address: 0x28ff40, Func Offset: 0
	// Line 641, Address: 0x28ff48, Func Offset: 0x8
	// Line 642, Address: 0x28ff58, Func Offset: 0x18
	// Line 644, Address: 0x28ff60, Func Offset: 0x20
	// Line 645, Address: 0x28ff68, Func Offset: 0x28
	// Func End, Address: 0x28ff74, Func Offset: 0x34
}

// 
// Start address: 0x28ff80
void RequestMidiFadeFunction(int SlotNo, int Func, short Timer)
{
	_anon0* mp;
	// Line 652, Address: 0x28ff80, Func Offset: 0
	// Line 653, Address: 0x28ff98, Func Offset: 0x18
	// Line 655, Address: 0x28ffb8, Func Offset: 0x38
	// Line 656, Address: 0x28ffc0, Func Offset: 0x40
	// Line 657, Address: 0x28ffc4, Func Offset: 0x44
	// Line 659, Address: 0x28ffcc, Func Offset: 0x4c
	// Line 663, Address: 0x28ffd4, Func Offset: 0x54
	// Line 666, Address: 0x290044, Func Offset: 0xc4
	// Line 667, Address: 0x290050, Func Offset: 0xd0
	// Line 668, Address: 0x29005c, Func Offset: 0xdc
	// Line 674, Address: 0x290064, Func Offset: 0xe4
	// Line 677, Address: 0x290084, Func Offset: 0x104
	// Func End, Address: 0x29008c, Func Offset: 0x10c
}

// 
// Start address: 0x290090
void RequestMidiFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame)
{
	_anon0* mp;
	// Line 680, Address: 0x290090, Func Offset: 0
	// Line 683, Address: 0x2900a0, Func Offset: 0x10
	// Line 680, Address: 0x2900bc, Func Offset: 0x2c
	// Line 685, Address: 0x2900c0, Func Offset: 0x30
	// Line 686, Address: 0x2900cc, Func Offset: 0x3c
	// Line 688, Address: 0x2900d8, Func Offset: 0x48
	// Line 689, Address: 0x2900dc, Func Offset: 0x4c
	// Line 688, Address: 0x2900e4, Func Offset: 0x54
	// Line 689, Address: 0x2900e8, Func Offset: 0x58
	// Line 688, Address: 0x2900ec, Func Offset: 0x5c
	// Line 689, Address: 0x2900f0, Func Offset: 0x60
	// Line 691, Address: 0x2900f4, Func Offset: 0x64
	// Line 692, Address: 0x2900fc, Func Offset: 0x6c
	// Line 695, Address: 0x29011c, Func Offset: 0x8c
	// Line 696, Address: 0x290148, Func Offset: 0xb8
	// Func End, Address: 0x290160, Func Offset: 0xd0
}

// 
// Start address: 0x290160
void StopFadeMidi(int SlotNo)
{
	// Line 700, Address: 0x290160, Func Offset: 0
	// Line 701, Address: 0x290178, Func Offset: 0x18
	// Func End, Address: 0x290180, Func Offset: 0x20
}

// 
// Start address: 0x290180
void RequestSeFadeFunction(int SlotNo, int Func, short Timer)
{
	_anon0* sp;
	// Line 708, Address: 0x290180, Func Offset: 0
	// Line 709, Address: 0x290198, Func Offset: 0x18
	// Line 711, Address: 0x2901b8, Func Offset: 0x38
	// Line 712, Address: 0x2901c0, Func Offset: 0x40
	// Line 713, Address: 0x2901c4, Func Offset: 0x44
	// Line 715, Address: 0x2901cc, Func Offset: 0x4c
	// Line 719, Address: 0x2901d4, Func Offset: 0x54
	// Line 722, Address: 0x290244, Func Offset: 0xc4
	// Line 723, Address: 0x290250, Func Offset: 0xd0
	// Line 724, Address: 0x29025c, Func Offset: 0xdc
	// Line 729, Address: 0x290264, Func Offset: 0xe4
	// Line 732, Address: 0x290284, Func Offset: 0x104
	// Func End, Address: 0x29028c, Func Offset: 0x10c
}

// 
// Start address: 0x290290
void RequestSeFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame)
{
	_anon0* sp;
	// Line 735, Address: 0x290290, Func Offset: 0
	// Line 738, Address: 0x2902a0, Func Offset: 0x10
	// Line 735, Address: 0x2902bc, Func Offset: 0x2c
	// Line 740, Address: 0x2902c0, Func Offset: 0x30
	// Line 741, Address: 0x2902cc, Func Offset: 0x3c
	// Line 743, Address: 0x2902d8, Func Offset: 0x48
	// Line 744, Address: 0x2902dc, Func Offset: 0x4c
	// Line 743, Address: 0x2902e4, Func Offset: 0x54
	// Line 744, Address: 0x2902e8, Func Offset: 0x58
	// Line 743, Address: 0x2902ec, Func Offset: 0x5c
	// Line 744, Address: 0x2902f0, Func Offset: 0x60
	// Line 746, Address: 0x2902f4, Func Offset: 0x64
	// Line 747, Address: 0x2902fc, Func Offset: 0x6c
	// Line 750, Address: 0x29031c, Func Offset: 0x8c
	// Line 751, Address: 0x290348, Func Offset: 0xb8
	// Func End, Address: 0x290360, Func Offset: 0xd0
}

// 
// Start address: 0x290360
void StopFadeSe(int SlotNo)
{
	// Line 755, Address: 0x290360, Func Offset: 0
	// Line 756, Address: 0x290378, Func Offset: 0x18
	// Func End, Address: 0x290380, Func Offset: 0x20
}

// 
// Start address: 0x290380
int CheckFadeEndSe(int SlotNo)
{
	// Line 760, Address: 0x290380, Func Offset: 0
	// Line 761, Address: 0x2903a4, Func Offset: 0x24
	// Func End, Address: 0x2903ac, Func Offset: 0x2c
}

// 
// Start address: 0x2903b0
int ExecSoundFadeManager()
{
	_anon0* sp;
	_anon0* mp;
	int ReturnCode;
	int i;
	// Line 764, Address: 0x2903b0, Func Offset: 0
	// Line 766, Address: 0x2903cc, Func Offset: 0x1c
	// Line 770, Address: 0x2903d0, Func Offset: 0x20
	// Line 772, Address: 0x2903d4, Func Offset: 0x24
	// Line 775, Address: 0x290400, Func Offset: 0x50
	// Line 776, Address: 0x290410, Func Offset: 0x60
	// Line 777, Address: 0x29041c, Func Offset: 0x6c
	// Line 778, Address: 0x290428, Func Offset: 0x78
	// Line 779, Address: 0x29042c, Func Offset: 0x7c
	// Line 780, Address: 0x290440, Func Offset: 0x90
	// Line 783, Address: 0x290448, Func Offset: 0x98
	// Line 784, Address: 0x290450, Func Offset: 0xa0
	// Line 785, Address: 0x290454, Func Offset: 0xa4
	// Line 786, Address: 0x290458, Func Offset: 0xa8
	// Line 789, Address: 0x29046c, Func Offset: 0xbc
	// Line 790, Address: 0x290470, Func Offset: 0xc0
	// Line 791, Address: 0x290488, Func Offset: 0xd8
	// Line 793, Address: 0x29048c, Func Offset: 0xdc
	// Line 796, Address: 0x2904b8, Func Offset: 0x108
	// Line 797, Address: 0x2904c8, Func Offset: 0x118
	// Line 798, Address: 0x2904d4, Func Offset: 0x124
	// Line 799, Address: 0x2904e0, Func Offset: 0x130
	// Line 800, Address: 0x2904e4, Func Offset: 0x134
	// Line 801, Address: 0x2904f8, Func Offset: 0x148
	// Line 804, Address: 0x290500, Func Offset: 0x150
	// Line 805, Address: 0x290508, Func Offset: 0x158
	// Line 806, Address: 0x29050c, Func Offset: 0x15c
	// Line 807, Address: 0x290510, Func Offset: 0x160
	// Line 810, Address: 0x290524, Func Offset: 0x174
	// Line 811, Address: 0x290528, Func Offset: 0x178
	// Line 813, Address: 0x290538, Func Offset: 0x188
	// Line 814, Address: 0x29053c, Func Offset: 0x18c
	// Func End, Address: 0x290554, Func Offset: 0x1a4
}

// 
// Start address: 0x290560
void RequestMidiPanFunctionEx(int SlotNo, int StartPan, int LastPan, int Frame)
{
	_anon0* mp;
	// Line 817, Address: 0x290560, Func Offset: 0
	// Line 820, Address: 0x290570, Func Offset: 0x10
	// Line 817, Address: 0x29058c, Func Offset: 0x2c
	// Line 822, Address: 0x290590, Func Offset: 0x30
	// Line 823, Address: 0x29059c, Func Offset: 0x3c
	// Line 825, Address: 0x2905a8, Func Offset: 0x48
	// Line 826, Address: 0x2905ac, Func Offset: 0x4c
	// Line 825, Address: 0x2905b4, Func Offset: 0x54
	// Line 826, Address: 0x2905b8, Func Offset: 0x58
	// Line 825, Address: 0x2905bc, Func Offset: 0x5c
	// Line 826, Address: 0x2905c0, Func Offset: 0x60
	// Line 828, Address: 0x2905c4, Func Offset: 0x64
	// Line 829, Address: 0x2905cc, Func Offset: 0x6c
	// Line 832, Address: 0x290600, Func Offset: 0xa0
	// Line 833, Address: 0x290608, Func Offset: 0xa8
	// Func End, Address: 0x290620, Func Offset: 0xc0
}

// 
// Start address: 0x290620
void RequestSePanFunctionEx(int SlotNo, int StartPan, int LastPan, int Frame)
{
	_anon0* sp;
	// Line 836, Address: 0x290620, Func Offset: 0
	// Line 839, Address: 0x290630, Func Offset: 0x10
	// Line 836, Address: 0x29064c, Func Offset: 0x2c
	// Line 841, Address: 0x290650, Func Offset: 0x30
	// Line 842, Address: 0x29065c, Func Offset: 0x3c
	// Line 844, Address: 0x290668, Func Offset: 0x48
	// Line 845, Address: 0x29066c, Func Offset: 0x4c
	// Line 844, Address: 0x290674, Func Offset: 0x54
	// Line 845, Address: 0x290678, Func Offset: 0x58
	// Line 844, Address: 0x29067c, Func Offset: 0x5c
	// Line 845, Address: 0x290680, Func Offset: 0x60
	// Line 847, Address: 0x290684, Func Offset: 0x64
	// Line 848, Address: 0x29068c, Func Offset: 0x6c
	// Line 851, Address: 0x2906c0, Func Offset: 0xa0
	// Line 852, Address: 0x2906c8, Func Offset: 0xa8
	// Func End, Address: 0x2906e0, Func Offset: 0xc0
}

// 
// Start address: 0x2906e0
int ExecSoundPanManager()
{
	_anon0* sp;
	int ReturnCode;
	int i;
	// Line 855, Address: 0x2906e0, Func Offset: 0
	// Line 857, Address: 0x2906fc, Func Offset: 0x1c
	// Line 860, Address: 0x290700, Func Offset: 0x20
	// Line 862, Address: 0x290704, Func Offset: 0x24
	// Line 863, Address: 0x290710, Func Offset: 0x30
	// Line 864, Address: 0x290720, Func Offset: 0x40
	// Line 865, Address: 0x29072c, Func Offset: 0x4c
	// Line 866, Address: 0x290738, Func Offset: 0x58
	// Line 868, Address: 0x290740, Func Offset: 0x60
	// Line 869, Address: 0x290748, Func Offset: 0x68
	// Line 870, Address: 0x29074c, Func Offset: 0x6c
	// Line 871, Address: 0x290750, Func Offset: 0x70
	// Line 873, Address: 0x290760, Func Offset: 0x80
	// Line 874, Address: 0x290778, Func Offset: 0x98
	// Line 876, Address: 0x29077c, Func Offset: 0x9c
	// Line 877, Address: 0x290788, Func Offset: 0xa8
	// Line 878, Address: 0x290798, Func Offset: 0xb8
	// Line 879, Address: 0x2907a4, Func Offset: 0xc4
	// Line 880, Address: 0x2907b0, Func Offset: 0xd0
	// Line 882, Address: 0x2907b8, Func Offset: 0xd8
	// Line 883, Address: 0x2907c0, Func Offset: 0xe0
	// Line 884, Address: 0x2907c4, Func Offset: 0xe4
	// Line 885, Address: 0x2907c8, Func Offset: 0xe8
	// Line 887, Address: 0x2907d8, Func Offset: 0xf8
	// Line 889, Address: 0x2907e8, Func Offset: 0x108
	// Line 890, Address: 0x2907ec, Func Offset: 0x10c
	// Func End, Address: 0x290804, Func Offset: 0x124
}

