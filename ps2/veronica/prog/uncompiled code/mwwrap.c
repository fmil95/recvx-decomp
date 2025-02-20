typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _UUID;
typedef struct _sj_vtbl;
typedef enum _mwe_ply_stat;
typedef struct _mwply_if;

typedef void(*type_0)(_anon1*, int, int, _anon0*);
typedef void(*type_1)();
typedef void(*type_2)(_anon1*, int, _anon0*);
typedef void(*type_3)();
typedef void(*type_4)();
typedef void(*type_5)(_anon2*);
typedef void(*type_6)(_anon1*, int, _anon0*);
typedef void(*type_7)(_anon2*);
typedef int(*type_9)(_anon1*, int);
typedef void(*type_10)(_anon2*);
typedef void(*type_11)(_anon2*, char*);
typedef int(*type_12)(_anon1*, int, int, int*);
typedef void(*type_13)(_anon2*);
typedef void(*type_14)(_anon1*, void(*)(void*, int), void*);
typedef _mwe_ply_stat(*type_15)(_anon2*);
typedef void(*type_16)(void*, int);
typedef void(*type_17)(_anon2*, int*, int*);
typedef void(*type_18)(_anon2*, int);
typedef void(*type_19)(_anon2*, int);
typedef int(*type_20)(_anon2*);
typedef void(*type_21)(_anon2*, int, int);
typedef int(*type_22)(_anon2*, int);
typedef void(*type_23)(_anon2*, _anon1*);
typedef void(*type_25)(_anon2*, void*, int);
typedef void(*type_26)();
typedef void(*type_27)();
typedef void(*type_28)();
typedef void(*type_29)(_anon1*);
typedef _UUID*(*type_30)(_anon1*);
typedef void(*type_31)(_anon1*);
typedef void(*type_32)();

typedef int type_8[4];
typedef unsigned char type_24[8];

struct _anon0
{
	char* data;
	int len;
};

struct _anon1
{
	_sj_vtbl* vtbl;
};

struct _anon2
{
	_mwply_if* vtbl;
};

struct _anon3
{
	int mode;
	int frame;
	int count;
	int latency;
	int rsv[4];
};

struct _anon4
{
	int ftype;
	int max_bps;
	int max_width;
	int max_height;
	int nfrm_pool_wk;
	char* work;
	int wksize;
	int dtype;
};

struct _UUID
{
	unsigned int Data1;
	unsigned short Data2;
	unsigned short Data3;
	unsigned char Data4[8];
};

struct _sj_vtbl
{
	void(*QueryInterface)();
	void(*AddRef)();
	void(*Release)();
	void(*Destroy)(_anon1*);
	_UUID*(*GetUuid)(_anon1*);
	void(*Reset)(_anon1*);
	void(*GetChunk)(_anon1*, int, int, _anon0*);
	void(*UngetChunk)(_anon1*, int, _anon0*);
	void(*PutChunk)(_anon1*, int, _anon0*);
	int(*GetNumData)(_anon1*, int);
	int(*IsGetChunk)(_anon1*, int, int, int*);
	void(*EntryErrFunc)(_anon1*, void(*)(void*, int), void*);
};

enum _mwe_ply_stat
{
	MWE_PLY_STAT_STOP,
	MWE_PLY_STAT_PREP,
	MWE_PLY_STAT_PLAYING,
	MWE_PLY_STAT_PLAYEND,
	MWE_PLY_STAT_ERROR
};

struct _mwply_if
{
	void(*QueryInterface)();
	void(*AddRef)();
	void(*Release)();
	void(*VsyncHndl)(_anon2*);
	void(*ExecSvrHndl)(_anon2*);
	void(*Destroy)(_anon2*);
	void(*StartFname)(_anon2*, char*);
	void(*Stop)(_anon2*);
	_mwe_ply_stat(*GetStat)(_anon2*);
	void(*GetTime)(_anon2*, int*, int*);
	void(*Pause)(_anon2*, int);
	void(*SetOutVol)(_anon2*, int);
	int(*GetOutVol)(_anon2*);
	void(*SetOutPan)(_anon2*, int, int);
	int(*GetOutPan)(_anon2*, int);
	void(*StartSj)(_anon2*, _anon1*);
	void(*StartMem)(_anon2*, void*, int);
};

int MwMode;
int MwPlayFlag;
_anon2* MwPly;
_anon4 MwsCprmSfd;
int MwMemoryMode;
int MwPlayMode;

void InitMwSystem(unsigned int Mode, void* pPrm);
void ReinitMwSystem(_anon3* pPrm);
void ExitMwSystem();
void SetMwSoundMode();
void GetMwPlayTime(int* ncount, int* tscale);
int GetMwPlayTimeEx();
void CreateSfdHandle(void* mp, void* pp, char* fname);
void CreateWaveHandle();
void CreateTmHandle();
void PlayMwOpenMain(char* FileName, int Mode, void* mp, void* pp, int PauseFlag);
void PlayMw2(char* FileName, int Mode, void* mp, void* pp, int PauseFlag);
void StopMw();
_mwe_ply_stat GetMwStatus();
int PlayMwMain2(void(*Func)());
int PlayMwMain();
void PauseMw();
void RestartMw();
void SetMwVolume(int Volume);
int GetSfdFadeRate();
void SetSfdDislpaySize(float PosX, float PosY, float SizeX, float SizeY);

// 
// Start address: 0x290960
void InitMwSystem(unsigned int Mode, void* pPrm)
{
	// Line 29, Address: 0x290960, Func Offset: 0
	// Line 30, Address: 0x29096c, Func Offset: 0xc
	// Line 32, Address: 0x29098c, Func Offset: 0x2c
	// Line 33, Address: 0x290998, Func Offset: 0x38
	// Line 40, Address: 0x2909a0, Func Offset: 0x40
	// Line 52, Address: 0x2909ac, Func Offset: 0x4c
	// Line 50, Address: 0x2909b4, Func Offset: 0x54
	// Line 53, Address: 0x2909bc, Func Offset: 0x5c
	// Func End, Address: 0x2909cc, Func Offset: 0x6c
}

// 
// Start address: 0x2909d0
void ReinitMwSystem(_anon3* pPrm)
{
	// Line 56, Address: 0x2909d0, Func Offset: 0
	// Line 57, Address: 0x2909dc, Func Offset: 0xc
	// Line 60, Address: 0x290a00, Func Offset: 0x30
	// Line 63, Address: 0x290a14, Func Offset: 0x44
	// Func End, Address: 0x290a20, Func Offset: 0x50
}

// 
// Start address: 0x290a20
void ExitMwSystem()
{
	// Line 66, Address: 0x290a20, Func Offset: 0
	// Line 69, Address: 0x290a28, Func Offset: 0x8
	// Line 71, Address: 0x290a4c, Func Offset: 0x2c
	// Line 72, Address: 0x290a54, Func Offset: 0x34
	// Line 79, Address: 0x290a5c, Func Offset: 0x3c
	// Line 89, Address: 0x290a64, Func Offset: 0x44
	// Line 90, Address: 0x290a70, Func Offset: 0x50
	// Func End, Address: 0x290a7c, Func Offset: 0x5c
}

// 
// Start address: 0x290a80
void SetMwSoundMode()
{
	// Line 103, Address: 0x290a80, Func Offset: 0
	// Func End, Address: 0x290a88, Func Offset: 0x8
}

// 
// Start address: 0x290a90
void GetMwPlayTime(int* ncount, int* tscale)
{
	// Line 107, Address: 0x290a94, Func Offset: 0x4
	// Func End, Address: 0x290ab0, Func Offset: 0x20
}

// 
// Start address: 0x290ab0
int GetMwPlayTimeEx()
{
	int SamplingRate;
	int SampleCount;
	// Line 111, Address: 0x290ab0, Func Offset: 0
	// Line 114, Address: 0x290ab4, Func Offset: 0x4
	// Line 111, Address: 0x290ab8, Func Offset: 0x8
	// Line 114, Address: 0x290abc, Func Offset: 0xc
	// Line 116, Address: 0x290ac8, Func Offset: 0x18
	// Line 117, Address: 0x290b00, Func Offset: 0x50
	// Func End, Address: 0x290b10, Func Offset: 0x60
}

// 
// Start address: 0x290b10
void CreateSfdHandle(void* mp, void* pp, char* fname)
{
	// Line 123, Address: 0x290b10, Func Offset: 0
	// Line 124, Address: 0x290b30, Func Offset: 0x20
	// Line 125, Address: 0x290b44, Func Offset: 0x34
	// Line 126, Address: 0x290b4c, Func Offset: 0x3c
	// Line 127, Address: 0x290b58, Func Offset: 0x48
	// Line 128, Address: 0x290b60, Func Offset: 0x50
	// Line 129, Address: 0x290b70, Func Offset: 0x60
	// Line 130, Address: 0x290b7c, Func Offset: 0x6c
	// Line 131, Address: 0x290b88, Func Offset: 0x78
	// Line 132, Address: 0x290b94, Func Offset: 0x84
	// Line 137, Address: 0x290bc4, Func Offset: 0xb4
	// Line 138, Address: 0x290bcc, Func Offset: 0xbc
	// Line 139, Address: 0x290bd8, Func Offset: 0xc8
	// Line 140, Address: 0x290be4, Func Offset: 0xd4
	// Line 141, Address: 0x290bf0, Func Offset: 0xe0
	// Line 142, Address: 0x290bfc, Func Offset: 0xec
	// Line 143, Address: 0x290c08, Func Offset: 0xf8
	// Line 144, Address: 0x290c14, Func Offset: 0x104
	// Line 147, Address: 0x290c20, Func Offset: 0x110
	// Line 148, Address: 0x290c28, Func Offset: 0x118
	// Line 149, Address: 0x290c38, Func Offset: 0x128
	// Line 150, Address: 0x290c40, Func Offset: 0x130
	// Line 151, Address: 0x290c48, Func Offset: 0x138
	// Line 155, Address: 0x290c54, Func Offset: 0x144
	// Line 157, Address: 0x290c6c, Func Offset: 0x15c
	// Line 158, Address: 0x290c7c, Func Offset: 0x16c
	// Func End, Address: 0x290c94, Func Offset: 0x184
}

// 
// Start address: 0x290ca0
void CreateWaveHandle()
{
	// Line 172, Address: 0x290ca0, Func Offset: 0
	// Func End, Address: 0x290ca8, Func Offset: 0x8
}

// 
// Start address: 0x290cb0
void CreateTmHandle()
{
	// Line 179, Address: 0x290cb0, Func Offset: 0
	// Func End, Address: 0x290cb8, Func Offset: 0x8
}

// 
// Start address: 0x290cc0
void PlayMwOpenMain(char* FileName, int Mode, void* mp, void* pp, int PauseFlag)
{
	// Line 182, Address: 0x290cc0, Func Offset: 0
	// Line 183, Address: 0x290cd4, Func Offset: 0x14
	// Line 184, Address: 0x290cec, Func Offset: 0x2c
	// Line 185, Address: 0x290cf4, Func Offset: 0x34
	// Line 189, Address: 0x290d24, Func Offset: 0x64
	// Line 191, Address: 0x290d34, Func Offset: 0x74
	// Line 192, Address: 0x290d38, Func Offset: 0x78
	// Line 194, Address: 0x290d40, Func Offset: 0x80
	// Line 195, Address: 0x290d4c, Func Offset: 0x8c
	// Line 196, Address: 0x290d54, Func Offset: 0x94
	// Line 198, Address: 0x290d5c, Func Offset: 0x9c
	// Line 202, Address: 0x290d84, Func Offset: 0xc4
	// Line 204, Address: 0x290d94, Func Offset: 0xd4
	// Line 206, Address: 0x290d9c, Func Offset: 0xdc
	// Line 207, Address: 0x290da8, Func Offset: 0xe8
	// Line 209, Address: 0x290db0, Func Offset: 0xf0
	// Line 212, Address: 0x290db8, Func Offset: 0xf8
	// Line 215, Address: 0x290dc0, Func Offset: 0x100
	// Line 216, Address: 0x290dd0, Func Offset: 0x110
	// Line 217, Address: 0x290dd8, Func Offset: 0x118
	// Line 219, Address: 0x290de0, Func Offset: 0x120
	// Line 220, Address: 0x290df8, Func Offset: 0x138
	// Line 222, Address: 0x290e04, Func Offset: 0x144
	// Func End, Address: 0x290e1c, Func Offset: 0x15c
}

// 
// Start address: 0x290e20
void PlayMw2(char* FileName, int Mode, void* mp, void* pp, int PauseFlag)
{
	// Line 231, Address: 0x290e20, Func Offset: 0
	// Func End, Address: 0x290e28, Func Offset: 0x8
}

// 
// Start address: 0x290e30
void StopMw()
{
	// Line 235, Address: 0x290e30, Func Offset: 0
	// Line 236, Address: 0x290e38, Func Offset: 0x8
	// Line 237, Address: 0x290e48, Func Offset: 0x18
	// Line 238, Address: 0x290e60, Func Offset: 0x30
	// Line 239, Address: 0x290e78, Func Offset: 0x48
	// Line 240, Address: 0x290e88, Func Offset: 0x58
	// Line 242, Address: 0x290ea0, Func Offset: 0x70
	// Line 251, Address: 0x290eac, Func Offset: 0x7c
	// Line 253, Address: 0x290eb4, Func Offset: 0x84
	// Func End, Address: 0x290ec0, Func Offset: 0x90
}

// 
// Start address: 0x290ec0
_mwe_ply_stat GetMwStatus()
{
	// Line 257, Address: 0x290ec0, Func Offset: 0
	// Func End, Address: 0x290ed8, Func Offset: 0x18
}

// 
// Start address: 0x290ee0
int PlayMwMain2(void(*Func)())
{
	_mwe_ply_stat MweStat;
	// Line 261, Address: 0x290ee0, Func Offset: 0
	// Line 264, Address: 0x290eec, Func Offset: 0xc
	// Line 265, Address: 0x290efc, Func Offset: 0x1c
	// Line 266, Address: 0x290f04, Func Offset: 0x24
	// Line 267, Address: 0x290f10, Func Offset: 0x30
	// Line 268, Address: 0x290f18, Func Offset: 0x38
	// Line 270, Address: 0x290f20, Func Offset: 0x40
	// Line 271, Address: 0x290f28, Func Offset: 0x48
	// Line 274, Address: 0x290f30, Func Offset: 0x50
	// Line 277, Address: 0x290f38, Func Offset: 0x58
	// Line 278, Address: 0x290f3c, Func Offset: 0x5c
	// Func End, Address: 0x290f4c, Func Offset: 0x6c
}

// 
// Start address: 0x290f50
int PlayMwMain()
{
	// Line 282, Address: 0x290f50, Func Offset: 0
	// Func End, Address: 0x290f58, Func Offset: 0x8
}

// 
// Start address: 0x290f60
void PauseMw()
{
	// Line 288, Address: 0x290f60, Func Offset: 0
	// Func End, Address: 0x290f7c, Func Offset: 0x1c
}

// 
// Start address: 0x290f80
void RestartMw()
{
	// Line 306, Address: 0x290f80, Func Offset: 0
	// Func End, Address: 0x290f9c, Func Offset: 0x1c
}

// 
// Start address: 0x290fa0
void SetMwVolume(int Volume)
{
	// Line 322, Address: 0x290fa4, Func Offset: 0x4
	// Func End, Address: 0x290fbc, Func Offset: 0x1c
}

// 
// Start address: 0x290fc0
int GetSfdFadeRate()
{
	// Line 327, Address: 0x290fc0, Func Offset: 0
	// Func End, Address: 0x290fcc, Func Offset: 0xc
}

// 
// Start address: 0x290fd0
void SetSfdDislpaySize(float PosX, float PosY, float SizeX, float SizeY)
{
	// Line 338, Address: 0x290fd0, Func Offset: 0
	// Line 339, Address: 0x290fe0, Func Offset: 0x10
	// Line 340, Address: 0x290ff4, Func Offset: 0x24
	// Line 341, Address: 0x291008, Func Offset: 0x38
	// Func End, Address: 0x29101c, Func Offset: 0x4c
}

