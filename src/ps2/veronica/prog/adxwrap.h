#ifndef _ADXWRAP_H_
#define _ADXWRAP_H_

#include "types.h"

typedef struct ADX_WORK
{
	// total size: 0x10
	unsigned int MaxChannel;    // offset 0x0, size 0x4
    unsigned int MaxSampleRate; // offset 0x4, size 0x4
    int RecoverType;            // offset 0x8, size 0x4
    int ReloadSector;           // offset 0xC, size 0x4
} ADX_WORK;

typedef struct AFS_PATINFO
{
    // total size: 0x10
    char* AfsFileName;        // offset 0x0, size 0x4
    int PartitionId;          // offset 0x4, size 0x4
    int MaxInsideFileNum;     // offset 0x8, size 0x4
    unsigned char* pInfoWork; // offset 0xC, size 0x4
} AFS_PATINFO;

typedef struct AFS_INFO
{
	// total size: 0xC
    unsigned char* pInfoPart;  // offset 0x0, size 0x4
    unsigned int PartAreaSize; // offset 0x4, size 0x4
    unsigned int Flag;         // offset 0x8, size 0x4
} AFS_INFO;

typedef struct ADXF_INFO
{
	// total size: 0x10
    ADX_FS* Handle;           // offset 0x0, size 0x4
    unsigned char* pAdxFWork; // offset 0x4, size 0x4
    unsigned int Flag;        // offset 0x8, size 0x4
    int Mode;                 // offset 0xC, size 0x4
} ADXF_INFO;

typedef struct ADXT_INFO
{
	// total size: 0x40
    ADX_TALK* Handle;         // offset 0x0, size 0x4
    unsigned char* pAdxTWork; // offset 0x4, size 0x4
    int WorkSize;             // offset 0x8, size 0x4
    unsigned int Flag;        // offset 0xC, size 0x4
    int FadeFunc;             // offset 0x10, size 0x4
    int FadeCntMax;           // offset 0x14, size 0x4
    float Volume;             // offset 0x18, size 0x4
    float VolSpeed;           // offset 0x1C, size 0x4
    float VolLast;            // offset 0x20, size 0x4
    float VolSave;            // offset 0x24, size 0x4
    float LimitMaxVol;        // offset 0x28, size 0x4
    int PanFunc;              // offset 0x2C, size 0x4
    int PanCntMax;            // offset 0x30, size 0x4
    float Pan;                // offset 0x34, size 0x4
    float PanSpeed;           // offset 0x38, size 0x4
    float PanLast;            // offset 0x3C, size 0x4
} ADXT_INFO;

void InitAdx();
void ExitAdx();
void DeletePartition(unsigned int PartitionId);
int CreatePartitionEx(AFS_PATINFO* ap);
void DeletePartitionEx(AFS_PATINFO* ap);
int SearchAdxFSlot();
int OpenAfsInsideFile(unsigned int PartitionId, unsigned int FileId);
int OpenAfsIsoFile(char* FileName);
int GetAfsInsideFileSize(int SlotNo);
void RequestReadAfsInsideFile(int SlotNo, unsigned char* Address);
int CheckReadEndAfsInsideFile(int SlotNo);
void CloseAfsInsideFile(int SlotNo);
void StopAfsInsideFile(int SlotNo);
void RegistAdxStreamEx(int MaxStream, int DummyStream, ADX_WORK* pAdx);
void FreeAdxStream();
void SleepAdxStream();
void WakeupAdxStream(ADX_WORK* pAdx);
void PlayAdxEx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId, int Flag);
void PlayAdx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId);
void StopAdx(unsigned int SlotNo);
void PauseAdx(unsigned int SlotNo);
void ContinueAdx(unsigned int SlotNo);
int GetAdxStatus(unsigned int SlotNo);
void SetVolumeAdx(unsigned int SlotNo, int Volume);
void SetVolumeAdxEx(unsigned int SlotNo, float Volume, float MaxVolume);
void SetVolumeAdx2(unsigned int SlotNo, float Volume);
void SetPanAdx2(unsigned int SlotNo, int Channel, float Pan); // second parameter is not present on the debugging symbols
void SetPanAdx(unsigned int SlotNo, int Channel, int Pan);
int GetAdxPlayTime(unsigned int SlotNo);
void RequestAdxFadeFunction2(int SlotNo, int Func, int Timer, int FirstVolume);
void RequestAdxFadeFunction(int SlotNo, int Func, int Timer);
void RequestAdxFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame);
int ExecAdxFadeManager();

extern char ADX_STREAM_BUFFER[471040] __attribute__((aligned(64)));

#endif
