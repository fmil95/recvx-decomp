#ifndef _PS2_SG_SD_H_
#define _PS2_SG_SD_H_

#include "types.h"

typedef struct SND_WORK
{
	// total size: 0x2C
    unsigned char port_check;    // offset 0x0, size 0x1
    unsigned char vol;           // offset 0x1, size 0x1
    unsigned char vol_old;       // offset 0x2, size 0x1
    unsigned char pan;           // offset 0x3, size 0x1
    short pitch_old;             // offset 0x4, size 0x2
    short pitch;                 // offset 0x6, size 0x2
    unsigned int vol_timer;      // offset 0x8, size 0x4
    unsigned int vol_set_time;   // offset 0xC, size 0x4
    unsigned int pan_timer;      // offset 0x10, size 0x4
    unsigned int pan_set_time;   // offset 0x14, size 0x4
    unsigned int pitch_timer;    // offset 0x18, size 0x4
    unsigned int pitch_set_time; // offset 0x1C, size 0x4
    unsigned int port_num;       // offset 0x20, size 0x4
    unsigned int bank_num;       // offset 0x24, size 0x4
    char channel_num;            // offset 0x28, size 0x1
    unsigned char pan_old;       // offset 0x29, size 0x1
    char priority;               // offset 0x2A, size 0x1
    unsigned char req;           // offset 0x2B, size 0x1
} SND_WORK;

SDE_ERR	sdBankDownload( SDMEMBLK handle, const SDE_DATA_TYPE bank_type, const Sint8 bank_num);
SDE_ERR	sdDrvInit( SDMEMBLK handle);
SDE_ERR	sdGddaSetPan( const Sint8 leftPan, const Sint8 right_pan);
SDE_ERR	sdLibInit( Void *wrk_ptr, Sint32 mem_blk_handle_max, Sint32 second_host_cmd_max);
SDE_ERR	sdMemBlkCreate( SDMEMBLK *handle);
SDE_ERR	sdMemBlkDestroy( SDMEMBLK handle);
SDE_ERR	sdMemBlkSetPrm( SDMEMBLK handle, const Void *src_blk_ptr, const Sint32 src_blk_sz, const SD_MEMBLK_CALLBACK_FUNC callback_func, const Void *callback_first_arg);
SDE_ERR	sdMidiClosePort( SDMIDI handle);
SDE_ERR	sdMidiGetStat( SDMIDI handle, SDS_MIDI_STAT *midi_stat);
SDE_ERR	sdMidiOpenPort( SDMIDI *handle);
SDE_ERR	sdMidiPlay( SDMIDI handle, const Sint8 bank_num, const Sint8 data_num, const Sint8 priority);
/*SDE_ERR sdMidiSetFxLev();
SDE_ERR sdMidiSetPan(SDS_PORT_REF** handle, char pan, int fade_time);
SDE_ERR sdMidiSetPitch(SDS_PORT_REF** handle, short pitch, int fade_time);
SDE_ERR sdMidiSetSpeed();
SDE_ERR sdMidiSetVol(SDS_PORT_REF** handle, char vol, int fade_time);*/
SDE_ERR	sdMidiStop( SDMIDI handle);
SDE_ERR	sdShotClosePort( SDSHOT handle);
SDE_ERR	sdShotGetStat( SDSHOT handle, SDS_SHOT_STAT *shot_stat);
SDE_ERR	sdShotOpenPort( SDSHOT *handle);
/*SDE_ERR sdShotPlay(SDS_PORT_REF** handle, char bank_num, char data_num, char priority);
SDE_ERR sdShotSetFxLev();
SDE_ERR sdShotSetPan(SDS_PORT_REF** handle, char pan, int fade_time);*/
unsigned char Panpot_Control(SND_WORK* set_snd_work);
/*SDE_ERR sdShotSetPitch(SDS_PORT_REF** handle, short pitch, int fade_time);*/
short Pitch_Control(SND_WORK* set_snd_work);
/*SDE_ERR sdShotSetVol(SDS_PORT_REF** handle, char vol, int fade_time);*/
unsigned char Volume_Control(SND_WORK* set_snd_work);
SDE_ERR	sdShotStop( SDSHOT handle);
SDE_ERR	sdSndClearFxPrg( Void);
SDE_ERR	sdSndSetFxPrg( const Sint8 new_fx_prg_num, const Sint8 new_fx_out_num);
SDE_ERR	sdSndSetMasterVol( const Sint8 vol);
SDE_ERR	sdSndSetPanMode( const SDE_PAN_MODE pan_mode);
SDE_ERR	sdSndStopAll( Void);
int sndr_trans_func();
SDE_ERR	sdSysServer( Void);
SDE_ERR	sdSysSetSlotMax(const Sint32 midi_slot_max, const Sint32 shot_slot_max, const Sint32 pstm_slot_max);
SDE_ERR	sdMemBlkSetTransferMode( SDE_MEMBLK_TRANSFER_MODE transfer_mode);
SDE_ERR	sdMultiUnitDownload( SDMEMBLK handle);
SDE_ERR	sdSysFinish( Void);
unsigned int CpSifDmaTransEEToIOP(unsigned int src, unsigned int dst, unsigned int size, unsigned int mode, unsigned int flag);
void CpEEWait(int val);

extern int iop_zero_buff;
extern int iop_buff;
extern int iop_read_buff;
extern char sound_flag;

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
