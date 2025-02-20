typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _adx_talk;
typedef struct _adxt_sprm;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _UUID;
typedef struct _sj_vtbl;
typedef struct _anon5;
typedef struct _adx_fs;
typedef struct _anon6;

typedef void(*type_0)(_anon1*, int, _anon2*);
typedef void(*type_1)(_anon1*, int, _anon2*);
typedef int(*type_4)(_anon1*, int);
typedef int(*type_6)(_anon1*, int, int, int*);
typedef void(*type_8)(_anon1*, void(*)(void*, int), void*);
typedef void(*type_9)(void*, int);
typedef void(*type_21)();
typedef void(*type_22)();
typedef void(*type_23)();
typedef void(*type_25)(_anon1*);
typedef _UUID*(*type_27)(_anon1*);
typedef void(*type_28)(_anon1*);
typedef void(*type_30)(_anon1*, int, int, _anon2*);

typedef _anon6 type_2[8];
typedef _anon0 type_3[4];
typedef char type_5[256];
typedef short type_7[128];
typedef char type_10[256];
typedef _anon1* type_11[2];
typedef char* type_12[0];
typedef char type_13[471040];
typedef char type_14[5628];
typedef int type_15[2];
typedef char type_16[256];
typedef unsigned char type_17[8];
typedef unsigned char type_18[880];
typedef short type_19[2];
typedef char type_20[256];
typedef _anon1* type_24[2];
typedef _anon1* type_26[2];
typedef char type_29[256];
typedef _anon5 type_31[16];

struct _anon0
{
	_adx_talk* Handle;
	unsigned char* pAdxTWork;
	int WorkSize;
	unsigned int Flag;
	int FadeFunc;
	int FadeCntMax;
	float Volume;
	float VolSpeed;
	float VolLast;
	float VolSave;
	float LimitMaxVol;
	int PanFunc;
	int PanCntMax;
	float Pan;
	float PanSpeed;
	float PanLast;
};

struct _anon1
{
	_sj_vtbl* vtbl;
};

struct _anon2
{
	char* data;
	int len;
};

struct _adx_talk
{
	char used;
	char stat;
	char pmode;
	char maxnch;
	void* sjd;
	void* stm;
	void* rna;
	_anon1* sjf;
	_anon1* sji;
	_anon1* sjo[2];
	char* ibuf;
	int ibuflen;
	int ibufxlen;
	short* obuf;
	int obufsize;
	int obufdist;
	int svrfreq;
	short maxsct;
	short minsct;
	short outvol;
	short outpan[2];
	int maxdecsmpl;
	int lpcnt;
	int lp_skiplen;
	int trp;
	int wpos;
	int mofst;
	short ercode;
	int edecpos;
	short edeccnt;
	short eshrtcnt;
	char lpflg;
	char autorcvr;
	char fltmode;
	char execflag;
	char pstwait_flag;
	char pstready_flag;
	char pause_flag;
	void* amp;
	_anon1* ampsji[2];
	_anon1* ampsjo[2];
	int time_ofst;
	int lesct;
	int trpnsmpl;
	void* lsc;
	char lnkflg;
	char rsv;
	short rsv2;
	unsigned int tvofst;
	unsigned int svcnt;
};

struct _adxt_sprm
{
	char* fname;
	char* fpc;
	int size;
	int nrtry;
	int speed;
	int dtype;
	int opmode;
};

struct _anon3
{
	unsigned int MaxChannel;
	unsigned int MaxSampleRate;
	int RecoverType;
	int ReloadSector;
};

struct _anon4
{
	char* AfsFileName;
	int PartitionId;
	int MaxInsideFileNum;
	unsigned char* pInfoWork;
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
	void(*GetChunk)(_anon1*, int, int, _anon2*);
	void(*UngetChunk)(_anon1*, int, _anon2*);
	void(*PutChunk)(_anon1*, int, _anon2*);
	int(*GetNumData)(_anon1*, int);
	int(*IsGetChunk)(_anon1*, int, int, int*);
	void(*EntryErrFunc)(_anon1*, void(*)(void*, int), void*);
};

struct _anon5
{
	unsigned char* pInfoPart;
	unsigned int PartAreaSize;
	unsigned int Flag;
};

struct _adx_fs
{
	char used;
	char stat;
	char sjflag;
	char rev;
	void* stm;
	_anon1* sj;
	int fnsct;
	int fsize;
	int skpos;
	int rdstpos;
	int rqsct;
	int rdsct;
	char* buf;
	int bsize;
	int rqrdsct;
	int ofst;
	char fname[256];
	void* dir;
};

struct _anon6
{
	_adx_fs* Handle;
	unsigned char* pAdxFWork;
	unsigned int Flag;
	int Mode;
};

char last_rdx_files[256];
char last_adx_files[256];
char last_file_id;
char adx_status;
int RDX_SIZE;
unsigned int RDX_CHECK_SAM;
int RDX_TOP;
unsigned int READ_RDX_NO;
_adxt_sprm cf_prm;
short AdxVolTbl[128];
int AdxStreamSleepFlag;
int MaxAdxStreamCnt;
_anon0 AdxTInfo[4];
_anon6 AdxFInfo[8];
_anon5 AfsInfo[16];
unsigned char RDX_FILE_PARTISION[880];
int rdx_image_data_max;
char* rdx_files[0];
int ADX_STREAM_BUFF_OFFSET[2];
char ADX_STREAM_BUFFER[471040];
char cf_area[5628];

void InitAdx();
void ExitAdx();
void DeletePartition(unsigned int PartitionId);
int CreatePartitionEx(_anon4* ap);
void DeletePartitionEx(_anon4* ap);
int SearchAdxFSlot();
int OpenAfsInsideFile(unsigned int PartitionId, unsigned int FileId);
int OpenAfsIsoFile(char* FileName);
int GetAfsInsideFileSize(int SlotNo);
void RequestReadAfsInsideFile(int SlotNo, unsigned char* Address);
int CheckReadEndAfsInsideFile(int SlotNo);
void CloseAfsInsideFile(int SlotNo);
void StopAfsInsideFile(int SlotNo);
void RegistAdxStreamEx(int MaxStream, int DummyStream, _anon3* pAdx);
void FreeAdxStream();
void SleepAdxStream();
void WakeupAdxStream(_anon3* pAdx);
void PlayAdxEx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId, int Flag);
void PlayAdx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId);
void StopAdx(unsigned int SlotNo);
void PauseAdx(unsigned int SlotNo);
void ContinueAdx(unsigned int SlotNo);
int GetAdxStatus(unsigned int SlotNo);
void SetVolumeAdx(unsigned int SlotNo, int Volume);
void SetVolumeAdxEx(unsigned int SlotNo, float Volume, float MaxVolume);
void SetVolumeAdx2(unsigned int SlotNo, float Volume);
void SetPanAdx2(unsigned int SlotNo, float Pan);
void SetPanAdx(unsigned int SlotNo, int Channel, int Pan);
int GetAdxPlayTime(unsigned int SlotNo);
void RequestAdxFadeFunction2(int SlotNo, int Func, int Timer, int FirstVolume);
void RequestAdxFadeFunction(int SlotNo, int Func, int Timer);
void RequestAdxFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame);
int ExecAdxFadeManager();

// 
// Start address: 0x291020
void InitAdx()
{
	unsigned int i;
	// Line 150, Address: 0x291020, Func Offset: 0
	// Line 157, Address: 0x291024, Func Offset: 0x4
	// Line 150, Address: 0x291028, Func Offset: 0x8
	// Line 157, Address: 0x29102c, Func Offset: 0xc
	// Line 158, Address: 0x291034, Func Offset: 0x14
	// Line 185, Address: 0x291040, Func Offset: 0x20
	// Line 193, Address: 0x29104c, Func Offset: 0x2c
	// Line 194, Address: 0x291054, Func Offset: 0x34
	// Line 197, Address: 0x29105c, Func Offset: 0x3c
	// Line 213, Address: 0x29106c, Func Offset: 0x4c
	// Line 215, Address: 0x291070, Func Offset: 0x50
	// Line 214, Address: 0x291074, Func Offset: 0x54
	// Line 215, Address: 0x29107c, Func Offset: 0x5c
	// Line 216, Address: 0x291094, Func Offset: 0x74
	// Line 218, Address: 0x291098, Func Offset: 0x78
	// Line 217, Address: 0x29109c, Func Offset: 0x7c
	// Line 218, Address: 0x2910a4, Func Offset: 0x84
	// Line 219, Address: 0x2910bc, Func Offset: 0x9c
	// Line 220, Address: 0x2910c0, Func Offset: 0xa0
	// Line 221, Address: 0x2910c4, Func Offset: 0xa4
	// Line 222, Address: 0x2910c8, Func Offset: 0xa8
	// Line 223, Address: 0x2910cc, Func Offset: 0xac
	// Line 225, Address: 0x2910d0, Func Offset: 0xb0
	// Line 224, Address: 0x2910d4, Func Offset: 0xb4
	// Line 225, Address: 0x2910d8, Func Offset: 0xb8
	// Line 227, Address: 0x2910e4, Func Offset: 0xc4
	// Line 228, Address: 0x2910ec, Func Offset: 0xcc
	// Line 229, Address: 0x2910f4, Func Offset: 0xd4
	// Func End, Address: 0x291100, Func Offset: 0xe0
}

// 
// Start address: 0x291100
void ExitAdx()
{
	// Line 233, Address: 0x291100, Func Offset: 0
	// Func End, Address: 0x291108, Func Offset: 0x8
}

// 
// Start address: 0x291110
void DeletePartition(unsigned int PartitionId)
{
	// Line 310, Address: 0x291110, Func Offset: 0
	// Line 309, Address: 0x291118, Func Offset: 0x8
	// Line 310, Address: 0x29111c, Func Offset: 0xc
	// Line 309, Address: 0x291124, Func Offset: 0x14
	// Line 310, Address: 0x291128, Func Offset: 0x18
	// Line 309, Address: 0x29112c, Func Offset: 0x1c
	// Line 310, Address: 0x291130, Func Offset: 0x20
	// Line 311, Address: 0x291140, Func Offset: 0x30
	// Line 312, Address: 0x291154, Func Offset: 0x44
	// Line 314, Address: 0x291158, Func Offset: 0x48
	// Func End, Address: 0x291168, Func Offset: 0x58
}

// 
// Start address: 0x291170
int CreatePartitionEx(_anon4* ap)
{
	int ret;
	char chg_AfsFile[256];
	// Line 317, Address: 0x291170, Func Offset: 0
	// Line 322, Address: 0x291184, Func Offset: 0x14
	// Line 328, Address: 0x291190, Func Offset: 0x20
	// Line 329, Address: 0x2911a8, Func Offset: 0x38
	// Line 331, Address: 0x2911d0, Func Offset: 0x60
	// Line 333, Address: 0x2911d8, Func Offset: 0x68
	// Line 335, Address: 0x2911ec, Func Offset: 0x7c
	// Line 337, Address: 0x2911f4, Func Offset: 0x84
	// Line 339, Address: 0x2911f8, Func Offset: 0x88
	// Line 341, Address: 0x291200, Func Offset: 0x90
	// Line 343, Address: 0x291208, Func Offset: 0x98
	// Line 345, Address: 0x291210, Func Offset: 0xa0
	// Line 348, Address: 0x29121c, Func Offset: 0xac
	// Line 349, Address: 0x291228, Func Offset: 0xb8
	// Line 350, Address: 0x291238, Func Offset: 0xc8
	// Line 360, Address: 0x291240, Func Offset: 0xd0
	// Line 361, Address: 0x29124c, Func Offset: 0xdc
	// Line 362, Address: 0x291254, Func Offset: 0xe4
	// Line 382, Address: 0x291278, Func Offset: 0x108
	// Line 383, Address: 0x29127c, Func Offset: 0x10c
	// Line 394, Address: 0x291284, Func Offset: 0x114
	// Line 404, Address: 0x29128c, Func Offset: 0x11c
	// Line 407, Address: 0x2912a8, Func Offset: 0x138
	// Line 412, Address: 0x2912b0, Func Offset: 0x140
	// Line 414, Address: 0x2912b8, Func Offset: 0x148
	// Line 416, Address: 0x2912c0, Func Offset: 0x150
	// Line 418, Address: 0x2912c8, Func Offset: 0x158
	// Line 421, Address: 0x2912d4, Func Offset: 0x164
	// Line 422, Address: 0x2912e0, Func Offset: 0x170
	// Line 423, Address: 0x2912f0, Func Offset: 0x180
	// Line 432, Address: 0x2912f8, Func Offset: 0x188
	// Line 433, Address: 0x291304, Func Offset: 0x194
	// Line 459, Address: 0x29130c, Func Offset: 0x19c
	// Line 458, Address: 0x291318, Func Offset: 0x1a8
	// Line 459, Address: 0x29131c, Func Offset: 0x1ac
	// Func End, Address: 0x291324, Func Offset: 0x1b4
}

// 
// Start address: 0x291330
void DeletePartitionEx(_anon4* ap)
{
	// Line 467, Address: 0x291330, Func Offset: 0
	// Line 464, Address: 0x291338, Func Offset: 0x8
	// Line 467, Address: 0x291344, Func Offset: 0x14
	// Line 468, Address: 0x291358, Func Offset: 0x28
	// Line 469, Address: 0x29135c, Func Offset: 0x2c
	// Line 470, Address: 0x291364, Func Offset: 0x34
	// Func End, Address: 0x29136c, Func Offset: 0x3c
}

// 
// Start address: 0x291370
int SearchAdxFSlot()
{
	unsigned int i;
	// Line 476, Address: 0x291378, Func Offset: 0x8
	// Line 477, Address: 0x29137c, Func Offset: 0xc
	// Line 478, Address: 0x291388, Func Offset: 0x18
	// Line 480, Address: 0x291390, Func Offset: 0x20
	// Line 482, Address: 0x2913a0, Func Offset: 0x30
	// Line 483, Address: 0x2913a4, Func Offset: 0x34
	// Func End, Address: 0x2913ac, Func Offset: 0x3c
}

// 
// Start address: 0x2913b0
int OpenAfsInsideFile(unsigned int PartitionId, unsigned int FileId)
{
	unsigned int SlotNo;
	// Line 486, Address: 0x2913b0, Func Offset: 0
	// Line 489, Address: 0x2913c8, Func Offset: 0x18
	// Line 500, Address: 0x2913d0, Func Offset: 0x20
	// Line 502, Address: 0x2913d8, Func Offset: 0x28
	// Line 504, Address: 0x2913f4, Func Offset: 0x44
	// Line 506, Address: 0x2913fc, Func Offset: 0x4c
	// Line 512, Address: 0x291408, Func Offset: 0x58
	// Line 519, Address: 0x291410, Func Offset: 0x60
	// Line 520, Address: 0x291424, Func Offset: 0x74
	// Line 521, Address: 0x291434, Func Offset: 0x84
	// Line 520, Address: 0x291438, Func Offset: 0x88
	// Line 523, Address: 0x29143c, Func Offset: 0x8c
	// Func End, Address: 0x291454, Func Offset: 0xa4
}

// 
// Start address: 0x291460
int OpenAfsIsoFile(char* FileName)
{
	int i;
	char chg_FileName[256];
	unsigned int SlotNo;
	// Line 526, Address: 0x291460, Func Offset: 0
	// Line 530, Address: 0x291478, Func Offset: 0x18
	// Line 539, Address: 0x291484, Func Offset: 0x24
	// Line 547, Address: 0x2914f4, Func Offset: 0x94
	// Line 549, Address: 0x291510, Func Offset: 0xb0
	// Line 550, Address: 0x291530, Func Offset: 0xd0
	// Line 551, Address: 0x291534, Func Offset: 0xd4
	// Line 553, Address: 0x29153c, Func Offset: 0xdc
	// Line 555, Address: 0x291544, Func Offset: 0xe4
	// Line 557, Address: 0x291560, Func Offset: 0x100
	// Line 592, Address: 0x291570, Func Offset: 0x110
	// Line 594, Address: 0x291578, Func Offset: 0x118
	// Line 597, Address: 0x291590, Func Offset: 0x130
	// Line 599, Address: 0x2915b0, Func Offset: 0x150
	// Line 600, Address: 0x2915c0, Func Offset: 0x160
	// Line 601, Address: 0x2915cc, Func Offset: 0x16c
	// Line 602, Address: 0x2915dc, Func Offset: 0x17c
	// Line 606, Address: 0x2915e4, Func Offset: 0x184
	// Line 612, Address: 0x2915f4, Func Offset: 0x194
	// Line 614, Address: 0x2915fc, Func Offset: 0x19c
	// Line 616, Address: 0x291618, Func Offset: 0x1b8
	// Line 619, Address: 0x291620, Func Offset: 0x1c0
	// Line 625, Address: 0x29162c, Func Offset: 0x1cc
	// Line 640, Address: 0x291634, Func Offset: 0x1d4
	// Line 641, Address: 0x291648, Func Offset: 0x1e8
	// Line 642, Address: 0x291658, Func Offset: 0x1f8
	// Line 646, Address: 0x291664, Func Offset: 0x204
	// Line 653, Address: 0x291680, Func Offset: 0x220
	// Line 655, Address: 0x291688, Func Offset: 0x228
	// Line 657, Address: 0x2916a4, Func Offset: 0x244
	// Line 661, Address: 0x2916ac, Func Offset: 0x24c
	// Line 667, Address: 0x2916b8, Func Offset: 0x258
	// Line 674, Address: 0x2916c0, Func Offset: 0x260
	// Line 675, Address: 0x2916d4, Func Offset: 0x274
	// Line 676, Address: 0x2916e4, Func Offset: 0x284
	// Line 675, Address: 0x2916e8, Func Offset: 0x288
	// Line 841, Address: 0x2916ec, Func Offset: 0x28c
	// Func End, Address: 0x291708, Func Offset: 0x2a8
}

// 
// Start address: 0x291710
int GetAfsInsideFileSize(int SlotNo)
{
	// Line 846, Address: 0x291710, Func Offset: 0
	// Line 844, Address: 0x291718, Func Offset: 0x8
	// Line 846, Address: 0x29171c, Func Offset: 0xc
	// Line 844, Address: 0x291724, Func Offset: 0x14
	// Line 846, Address: 0x291728, Func Offset: 0x18
	// Line 850, Address: 0x291754, Func Offset: 0x44
	// Func End, Address: 0x291760, Func Offset: 0x50
}

// 
// Start address: 0x291760
void RequestReadAfsInsideFile(int SlotNo, unsigned char* Address)
{
	// Line 853, Address: 0x291760, Func Offset: 0
	// Line 854, Address: 0x291770, Func Offset: 0x10
	// Line 853, Address: 0x291774, Func Offset: 0x14
	// Line 854, Address: 0x291778, Func Offset: 0x18
	// Line 876, Address: 0x291790, Func Offset: 0x30
	// Line 878, Address: 0x291798, Func Offset: 0x38
	// Line 880, Address: 0x2917a0, Func Offset: 0x40
	// Line 883, Address: 0x2917c4, Func Offset: 0x64
	// Line 890, Address: 0x2917cc, Func Offset: 0x6c
	// Line 906, Address: 0x2917dc, Func Offset: 0x7c
	// Func End, Address: 0x2917f4, Func Offset: 0x94
}

// 
// Start address: 0x291800
int CheckReadEndAfsInsideFile(int SlotNo)
{
	// Line 938, Address: 0x291800, Func Offset: 0
	// Line 939, Address: 0x29180c, Func Offset: 0xc
	// Line 938, Address: 0x291810, Func Offset: 0x10
	// Line 939, Address: 0x291814, Func Offset: 0x14
	// Line 940, Address: 0x29184c, Func Offset: 0x4c
	// Line 941, Address: 0x291864, Func Offset: 0x64
	// Line 944, Address: 0x29186c, Func Offset: 0x6c
	// Line 946, Address: 0x291878, Func Offset: 0x78
	// Line 948, Address: 0x29187c, Func Offset: 0x7c
	// Func End, Address: 0x291890, Func Offset: 0x90
}

// 
// Start address: 0x291890
void CloseAfsInsideFile(int SlotNo)
{
	// Line 951, Address: 0x291890, Func Offset: 0
	// Line 952, Address: 0x29189c, Func Offset: 0xc
	// Line 951, Address: 0x2918a0, Func Offset: 0x10
	// Line 952, Address: 0x2918a4, Func Offset: 0x14
	// Line 959, Address: 0x2918bc, Func Offset: 0x2c
	// Line 961, Address: 0x2918c4, Func Offset: 0x34
	// Line 963, Address: 0x2918d8, Func Offset: 0x48
	// Line 965, Address: 0x2918e0, Func Offset: 0x50
	// Line 967, Address: 0x2918e4, Func Offset: 0x54
	// Func End, Address: 0x2918f8, Func Offset: 0x68
}

// 
// Start address: 0x291900
void StopAfsInsideFile(int SlotNo)
{
	// Line 970, Address: 0x291900, Func Offset: 0
	// Line 971, Address: 0x29190c, Func Offset: 0xc
	// Line 970, Address: 0x291918, Func Offset: 0x18
	// Line 971, Address: 0x29191c, Func Offset: 0x1c
	// Line 973, Address: 0x29192c, Func Offset: 0x2c
	// Line 974, Address: 0x291934, Func Offset: 0x34
	// Line 975, Address: 0x291948, Func Offset: 0x48
	// Line 976, Address: 0x291950, Func Offset: 0x50
	// Line 979, Address: 0x291958, Func Offset: 0x58
	// Func End, Address: 0x29196c, Func Offset: 0x6c
}

// 
// Start address: 0x291970
void RegistAdxStreamEx(int MaxStream, int DummyStream, _anon3* pAdx)
{
	_anon0* tp;
	int i;
	// Line 998, Address: 0x291970, Func Offset: 0
	// Line 1002, Address: 0x291998, Func Offset: 0x28
	// Line 1003, Address: 0x2919a0, Func Offset: 0x30
	// Line 1008, Address: 0x2919a4, Func Offset: 0x34
	// Line 1012, Address: 0x2919bc, Func Offset: 0x4c
	// Line 1015, Address: 0x2919d8, Func Offset: 0x68
	// Line 1016, Address: 0x291a1c, Func Offset: 0xac
	// Line 1015, Address: 0x291a24, Func Offset: 0xb4
	// Line 1016, Address: 0x291a54, Func Offset: 0xe4
	// Line 1018, Address: 0x291a5c, Func Offset: 0xec
	// Line 1020, Address: 0x291a64, Func Offset: 0xf4
	// Line 1022, Address: 0x291a74, Func Offset: 0x104
	// Line 1024, Address: 0x291a7c, Func Offset: 0x10c
	// Line 1025, Address: 0x291a8c, Func Offset: 0x11c
	// Line 1026, Address: 0x291a94, Func Offset: 0x124
	// Line 1027, Address: 0x291a98, Func Offset: 0x128
	// Line 1028, Address: 0x291aa4, Func Offset: 0x134
	// Line 1029, Address: 0x291aac, Func Offset: 0x13c
	// Line 1030, Address: 0x291ab0, Func Offset: 0x140
	// Line 1052, Address: 0x291ab4, Func Offset: 0x144
	// Line 1031, Address: 0x291ab8, Func Offset: 0x148
	// Line 1052, Address: 0x291ac4, Func Offset: 0x154
	// Line 1056, Address: 0x291ad0, Func Offset: 0x160
	// Line 1055, Address: 0x291ad8, Func Offset: 0x168
	// Line 1071, Address: 0x291ae0, Func Offset: 0x170
	// Func End, Address: 0x291b04, Func Offset: 0x194
}

// 
// Start address: 0x291b10
void FreeAdxStream()
{
	int i;
	// Line 1081, Address: 0x291b10, Func Offset: 0
	// Line 1084, Address: 0x291b20, Func Offset: 0x10
	// Line 1085, Address: 0x291b44, Func Offset: 0x34
	// Line 1087, Address: 0x291b54, Func Offset: 0x44
	// Line 1090, Address: 0x291b60, Func Offset: 0x50
	// Line 1092, Address: 0x291b68, Func Offset: 0x58
	// Line 1094, Address: 0x291b70, Func Offset: 0x60
	// Line 1097, Address: 0x291b78, Func Offset: 0x68
	// Line 1099, Address: 0x291b80, Func Offset: 0x70
	// Line 1101, Address: 0x291b88, Func Offset: 0x78
	// Line 1104, Address: 0x291b90, Func Offset: 0x80
	// Line 1105, Address: 0x291b98, Func Offset: 0x88
	// Line 1107, Address: 0x291ba8, Func Offset: 0x98
	// Line 1108, Address: 0x291bb0, Func Offset: 0xa0
	// Func End, Address: 0x291bc4, Func Offset: 0xb4
}

// 
// Start address: 0x291bd0
void SleepAdxStream()
{
	int i;
	// Line 1111, Address: 0x291bd0, Func Offset: 0
	// Line 1114, Address: 0x291be0, Func Offset: 0x10
	// Line 1115, Address: 0x291bf8, Func Offset: 0x28
	// Line 1117, Address: 0x291c00, Func Offset: 0x30
	// Line 1120, Address: 0x291c08, Func Offset: 0x38
	// Line 1123, Address: 0x291c14, Func Offset: 0x44
	// Line 1126, Address: 0x291c1c, Func Offset: 0x4c
	// Line 1128, Address: 0x291c24, Func Offset: 0x54
	// Line 1130, Address: 0x291c2c, Func Offset: 0x5c
	// Line 1133, Address: 0x291c34, Func Offset: 0x64
	// Line 1135, Address: 0x291c3c, Func Offset: 0x6c
	// Line 1137, Address: 0x291c44, Func Offset: 0x74
	// Line 1139, Address: 0x291c50, Func Offset: 0x80
	// Line 1140, Address: 0x291c6c, Func Offset: 0x9c
	// Line 1142, Address: 0x291c78, Func Offset: 0xa8
	// Func End, Address: 0x291c8c, Func Offset: 0xbc
}

// 
// Start address: 0x291c90
void WakeupAdxStream(_anon3* pAdx)
{
	_anon0* tp;
	int i;
	// Line 1145, Address: 0x291c90, Func Offset: 0
	// Line 1149, Address: 0x291ca4, Func Offset: 0x14
	// Line 1150, Address: 0x291cbc, Func Offset: 0x2c
	// Line 1153, Address: 0x291cc4, Func Offset: 0x34
	// Line 1155, Address: 0x291ccc, Func Offset: 0x3c
	// Line 1157, Address: 0x291cdc, Func Offset: 0x4c
	// Line 1159, Address: 0x291ce4, Func Offset: 0x54
	// Line 1160, Address: 0x291cf4, Func Offset: 0x64
	// Line 1161, Address: 0x291cfc, Func Offset: 0x6c
	// Line 1162, Address: 0x291d00, Func Offset: 0x70
	// Line 1163, Address: 0x291d0c, Func Offset: 0x7c
	// Line 1164, Address: 0x291d14, Func Offset: 0x84
	// Line 1165, Address: 0x291d18, Func Offset: 0x88
	// Line 1166, Address: 0x291d1c, Func Offset: 0x8c
	// Line 1167, Address: 0x291d24, Func Offset: 0x94
	// Line 1168, Address: 0x291d44, Func Offset: 0xb4
	// Line 1170, Address: 0x291d4c, Func Offset: 0xbc
	// Func End, Address: 0x291d64, Func Offset: 0xd4
}

// 
// Start address: 0x291d70
void PlayAdxEx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId, int Flag)
{
	// Line 1178, Address: 0x291d70, Func Offset: 0
	// Line 1179, Address: 0x291d90, Func Offset: 0x20
	// Line 1180, Address: 0x291d98, Func Offset: 0x28
	// Line 1185, Address: 0x291da0, Func Offset: 0x30
	// Line 1191, Address: 0x291da8, Func Offset: 0x38
	// Line 1209, Address: 0x291dc4, Func Offset: 0x54
	// Line 1218, Address: 0x291dd4, Func Offset: 0x64
	// Line 1222, Address: 0x291ddc, Func Offset: 0x6c
	// Line 1223, Address: 0x291df0, Func Offset: 0x80
	// Func End, Address: 0x291e0c, Func Offset: 0x9c
}

// 
// Start address: 0x291e10
void PlayAdx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId)
{
	// Line 1227, Address: 0x291e10, Func Offset: 0
	// Func End, Address: 0x291e18, Func Offset: 0x8
}

// 
// Start address: 0x291e20
void StopAdx(unsigned int SlotNo)
{
	// Line 1231, Address: 0x291e20, Func Offset: 0
	// Line 1234, Address: 0x291e2c, Func Offset: 0xc
	// Line 1231, Address: 0x291e30, Func Offset: 0x10
	// Line 1234, Address: 0x291e34, Func Offset: 0x14
	// Line 1240, Address: 0x291e4c, Func Offset: 0x2c
	// Line 1261, Address: 0x291e54, Func Offset: 0x34
	// Line 1272, Address: 0x291e68, Func Offset: 0x48
	// Line 1283, Address: 0x291e70, Func Offset: 0x50
	// Line 1284, Address: 0x291e74, Func Offset: 0x54
	// Func End, Address: 0x291e88, Func Offset: 0x68
}

// 
// Start address: 0x291e90
void PauseAdx(unsigned int SlotNo)
{
	// Line 1287, Address: 0x291e90, Func Offset: 0
	// Line 1291, Address: 0x291e9c, Func Offset: 0xc
	// Line 1294, Address: 0x291ea4, Func Offset: 0x14
	// Line 1298, Address: 0x291ec0, Func Offset: 0x30
	// Line 1301, Address: 0x291ec8, Func Offset: 0x38
	// Func End, Address: 0x291ed8, Func Offset: 0x48
}

// 
// Start address: 0x291ee0
void ContinueAdx(unsigned int SlotNo)
{
	// Line 1304, Address: 0x291ee0, Func Offset: 0
	// Line 1308, Address: 0x291eec, Func Offset: 0xc
	// Line 1311, Address: 0x291ef4, Func Offset: 0x14
	// Line 1315, Address: 0x291f10, Func Offset: 0x30
	// Line 1318, Address: 0x291f18, Func Offset: 0x38
	// Func End, Address: 0x291f28, Func Offset: 0x48
}

// 
// Start address: 0x291f30
int GetAdxStatus(unsigned int SlotNo)
{
	// Line 1325, Address: 0x291f30, Func Offset: 0
	// Func End, Address: 0x291f48, Func Offset: 0x18
}

// 
// Start address: 0x291f50
void SetVolumeAdx(unsigned int SlotNo, int Volume)
{
	// Line 1334, Address: 0x291f50, Func Offset: 0
	// Func End, Address: 0x291f5c, Func Offset: 0xc
}

// 
// Start address: 0x291f60
void SetVolumeAdxEx(unsigned int SlotNo, float Volume, float MaxVolume)
{
	// Line 1340, Address: 0x291f60, Func Offset: 0
	// Line 1341, Address: 0x291f7c, Func Offset: 0x1c
	// Line 1342, Address: 0x291f84, Func Offset: 0x24
	// Line 1344, Address: 0x291f8c, Func Offset: 0x2c
	// Line 1347, Address: 0x291f90, Func Offset: 0x30
	// Line 1348, Address: 0x291fa0, Func Offset: 0x40
	// Func End, Address: 0x291fa8, Func Offset: 0x48
}

// 
// Start address: 0x291fb0
void SetVolumeAdx2(unsigned int SlotNo, float Volume)
{
	// Line 1356, Address: 0x291fb0, Func Offset: 0
	// Line 1359, Address: 0x291fc0, Func Offset: 0x10
	// Line 1356, Address: 0x291fcc, Func Offset: 0x1c
	// Line 1359, Address: 0x291fd0, Func Offset: 0x20
	// Line 1363, Address: 0x291fe4, Func Offset: 0x34
	// Line 1370, Address: 0x291fec, Func Offset: 0x3c
	// Line 1374, Address: 0x292010, Func Offset: 0x60
	// Line 1380, Address: 0x292018, Func Offset: 0x68
	// Line 1383, Address: 0x292028, Func Offset: 0x78
	// Func End, Address: 0x292040, Func Offset: 0x90
}

// 
// Start address: 0x292040
void SetPanAdx2(unsigned int SlotNo, float Pan)
{
	// Line 1387, Address: 0x292040, Func Offset: 0
	// Line 1401, Address: 0x292050, Func Offset: 0x10
	// Func End, Address: 0x292058, Func Offset: 0x18
}

// 
// Start address: 0x292060
void SetPanAdx(unsigned int SlotNo, int Channel, int Pan)
{
	// Line 1405, Address: 0x292060, Func Offset: 0
	// Func End, Address: 0x29206c, Func Offset: 0xc
}

// 
// Start address: 0x292070
int GetAdxPlayTime(unsigned int SlotNo)
{
	int SamplingRate;
	int SampleCount;
	// Line 1419, Address: 0x292070, Func Offset: 0
	// Line 1423, Address: 0x29207c, Func Offset: 0xc
	// Line 1425, Address: 0x292084, Func Offset: 0x14
	// Line 1427, Address: 0x2920a4, Func Offset: 0x34
	// Line 1430, Address: 0x2920ac, Func Offset: 0x3c
	// Line 1431, Address: 0x2920e4, Func Offset: 0x74
	// Func End, Address: 0x2920f4, Func Offset: 0x84
}

// 
// Start address: 0x292100
void RequestAdxFadeFunction2(int SlotNo, int Func, int Timer, int FirstVolume)
{
	_anon0* tp;
	float Cnt;
	// Line 1465, Address: 0x292100, Func Offset: 0
	// Line 1467, Address: 0x292110, Func Offset: 0x10
	// Line 1470, Address: 0x292178, Func Offset: 0x78
	// Line 1471, Address: 0x292184, Func Offset: 0x84
	// Line 1472, Address: 0x292190, Func Offset: 0x90
	// Line 1477, Address: 0x292198, Func Offset: 0x98
	// Line 1478, Address: 0x2921a4, Func Offset: 0xa4
	// Line 1481, Address: 0x2921b4, Func Offset: 0xb4
	// Line 1483, Address: 0x2921d4, Func Offset: 0xd4
	// Line 1484, Address: 0x2921d8, Func Offset: 0xd8
	// Line 1486, Address: 0x2921e0, Func Offset: 0xe0
	// Line 1490, Address: 0x2921e8, Func Offset: 0xe8
	// Line 1493, Address: 0x2921f0, Func Offset: 0xf0
	// Line 1494, Address: 0x2921fc, Func Offset: 0xfc
	// Line 1495, Address: 0x292214, Func Offset: 0x114
	// Line 1497, Address: 0x29221c, Func Offset: 0x11c
	// Line 1501, Address: 0x292220, Func Offset: 0x120
	// Line 1503, Address: 0x292228, Func Offset: 0x128
	// Func End, Address: 0x292230, Func Offset: 0x130
}

// 
// Start address: 0x292230
void RequestAdxFadeFunction(int SlotNo, int Func, int Timer)
{
	// Line 1507, Address: 0x292230, Func Offset: 0
	// Func End, Address: 0x292238, Func Offset: 0x8
}

// 
// Start address: 0x292240
void RequestAdxFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame)
{
	_anon0* tp;
	// Line 1511, Address: 0x292240, Func Offset: 0
	// Line 1514, Address: 0x292250, Func Offset: 0x10
	// Line 1511, Address: 0x29225c, Func Offset: 0x1c
	// Line 1514, Address: 0x292260, Func Offset: 0x20
	// Line 1516, Address: 0x292268, Func Offset: 0x28
	// Line 1517, Address: 0x292274, Func Offset: 0x34
	// Line 1519, Address: 0x292280, Func Offset: 0x40
	// Line 1520, Address: 0x292284, Func Offset: 0x44
	// Line 1519, Address: 0x29228c, Func Offset: 0x4c
	// Line 1520, Address: 0x292290, Func Offset: 0x50
	// Line 1519, Address: 0x292294, Func Offset: 0x54
	// Line 1520, Address: 0x292298, Func Offset: 0x58
	// Line 1522, Address: 0x29229c, Func Offset: 0x5c
	// Line 1523, Address: 0x2922a4, Func Offset: 0x64
	// Line 1526, Address: 0x2922c4, Func Offset: 0x84
	// Line 1527, Address: 0x2922cc, Func Offset: 0x8c
	// Func End, Address: 0x2922e4, Func Offset: 0xa4
}

// 
// Start address: 0x2922f0
int ExecAdxFadeManager()
{
	_anon0* tp;
	int ReturnCode;
	int i;
	// Line 1583, Address: 0x2922f0, Func Offset: 0
	// Line 1585, Address: 0x29230c, Func Offset: 0x1c
	// Line 1588, Address: 0x292310, Func Offset: 0x20
	// Line 1590, Address: 0x292314, Func Offset: 0x24
	// Line 1591, Address: 0x292320, Func Offset: 0x30
	// Line 1592, Address: 0x292330, Func Offset: 0x40
	// Line 1593, Address: 0x29233c, Func Offset: 0x4c
	// Line 1594, Address: 0x292348, Func Offset: 0x58
	// Line 1595, Address: 0x29234c, Func Offset: 0x5c
	// Line 1596, Address: 0x292360, Func Offset: 0x70
	// Line 1599, Address: 0x292368, Func Offset: 0x78
	// Line 1600, Address: 0x292370, Func Offset: 0x80
	// Line 1601, Address: 0x292374, Func Offset: 0x84
	// Line 1602, Address: 0x292378, Func Offset: 0x88
	// Line 1603, Address: 0x292384, Func Offset: 0x94
	// Line 1604, Address: 0x292388, Func Offset: 0x98
	// Line 1605, Address: 0x292394, Func Offset: 0xa4
	// Line 1606, Address: 0x2923a4, Func Offset: 0xb4
	// Line 1607, Address: 0x2923b0, Func Offset: 0xc0
	// Line 1608, Address: 0x2923bc, Func Offset: 0xcc
	// Line 1610, Address: 0x2923c4, Func Offset: 0xd4
	// Line 1611, Address: 0x2923cc, Func Offset: 0xdc
	// Line 1613, Address: 0x2923d0, Func Offset: 0xe0
	// Line 1615, Address: 0x2923e0, Func Offset: 0xf0
	// Line 1617, Address: 0x2923f0, Func Offset: 0x100
	// Line 1618, Address: 0x2923f4, Func Offset: 0x104
	// Func End, Address: 0x29240c, Func Offset: 0x11c
}

