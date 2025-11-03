#ifndef _PS2_SG_SD_H_
#define _PS2_SG_SD_H_

#include "types.h"

/*typedef struct SDS_PORT_REF;
typedef struct _anon0;
typedef struct SDS_MEMBLK;
typedef struct SDS_MIDI_STAT;
typedef struct _anon1;
typedef enum SDE_DATA_TYPE;
typedef struct SDS_SHOT_STAT;
typedef enum SDE_PAN_MODE;
typedef struct _SND_STATUS;
typedef enum SDE_ERR;

typedef void(*type_3)(void*);

typedef short type_0[4];
typedef short type_1[5];
typedef unsigned short type_2[9];
typedef SDS_PORT_REF* type_4[40];
typedef _anon0 type_5[40];
typedef unsigned int type_6[16];
typedef char type_7[2175];
typedef int type_8[10];
typedef int type_9[10][4];
typedef SDS_MEMBLK type_10[20];
typedef short type_11[4];
typedef unsigned short type_12[6];
typedef short type_13[5];
typedef unsigned short type_14[6];
typedef short type_15[5];
typedef short type_16[4];
typedef unsigned short type_17[6];
typedef short type_18[8];

struct SDS_PORT_REF
{
	void* m_Ref;
};

struct _anon0
{
	unsigned char port_check;
	unsigned char vol;
	unsigned char vol_old;
	unsigned char pan;
	short pitch_old;
	short pitch;
	unsigned int vol_timer;
	unsigned int vol_set_time;
	unsigned int pan_timer;
	unsigned int pan_set_time;
	unsigned int pitch_timer;
	unsigned int pitch_set_time;
	unsigned int port_num;
	unsigned int bank_num;
	char channel_num;
	unsigned char pan_old;
	char priority;
	unsigned char req;
};

struct SDS_MEMBLK
{
	unsigned int m_Member[16];
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

struct _anon1
{
	unsigned int data;
	unsigned int addr;
	unsigned int size;
	unsigned int mode;
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

enum SDE_PAN_MODE
{
	SDE_PAN_MODE_MONO,
	SDE_PAN_MODE_STEREO,
	SDE_PAN_MODE_DISABLE = 0,
	SDE_PAN_MODE_ENABLE
};

struct _SND_STATUS
{
	unsigned short se_info[6];
	unsigned short midi_info;
	short port_info[8];
	short midi_sum[4];
	short se_sum[5];
	unsigned short dummy[9];
};

enum SDE_ERR
{
	SDE_ERR_NOTHING,
	SDE_ERR_GD_FS_LIB_ERR = 0x1000001,
	SDE_ERR_PRM_OVER_RANGE = 0x3000001,
	SDE_ERR_PRM_ILLEGAL_VALUE,
	SDE_ERR_MODULE_SLOT_NO_ENOUGH = 0x5000001,
	SDE_ERR_MEMBLK_ALREADY_TRANSFER = 0x6000001,
	SDE_ERR_MEMBLK_QUEUE_NO_ENOUGH = 0x6000101,
	SDE_ERR_HANDLE_NO_ENOUGH = 0x7000101,
	SDE_ERR_HANDLE_ILLEGAL_VALUE,
	SDE_ERR_HANDLE_NULL,
	SDE_ERR_PTR_ILLEGAL_VALUE = 0x7000202,
	SDE_ERR_PTR_NULL,
	SDE_ERR_BANK_ILLEGAL_TYPE = 0x9000001,
	SDE_ERR_BANK_ILLEGAL_VER,
	SDE_ERR_BANK_NOTHING,
	SDE_ERR_BANK_ILLEGAL_NUM,
	SDE_ERR_BANK_NO_MAPPING = 0x9000110,
	SDE_ERR_DATA_ILLEGAL_TYPE = 0x9000101,
	SDE_ERR_DATA_ILLEGAL_VER,
	SDE_ERR_DATA_NOTHING,
	SDE_ERR_DATA_ILLEGAL_NUM,
	SDE_ERR_HOST_CMD_BUF_NO_ENOUGH = 0xa000001,
	SDE_ERR_SND_DRV_PROBLEM = 0xb000001,
	SDE_ERR_SND_DRV_ILLEGAL_VER,
	SDE_ERR_SND_DRV_BUSY,
	SDE_ERR_NO_INIT = 0xd000001,
	SDE_ERR_ALREADY_INIT,
	SDE_ERR_HARD_WARE = 0xf000001,
	SDE_ERR_MAIN_MEM_ADR_ERR = 0xf010001,
	SDE_ERR_SND_MEM_ADR_ERR = 0xf010101,
	SDE_ERR_UNKNOW_NUM = 0x7fffffff
};*/

#endif
