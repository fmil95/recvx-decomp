#ifndef _SDC_H_
#define _SDC_H_

#include "types.h"

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
