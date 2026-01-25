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
SDE_ERR	sdMidiSetFxLev( SDMIDI handle, const Sint8 fx_lev);
SDE_ERR	sdMidiSetPan( SDMIDI handle, const Sint8 pan, const Sint32 fade_time);
SDE_ERR	sdMidiSetPitch( SDMIDI handle, const Sint16 pitch, const Sint32 fade_time);
SDE_ERR	sdMidiSetSpeed( SDMIDI handle, const Sint16 speed, const Sint32 fade_time);
SDE_ERR	sdMidiSetVol( SDMIDI handle, const Sint8 vol, const Sint32 fade_time);
SDE_ERR	sdMidiStop( SDMIDI handle);
SDE_ERR	sdShotClosePort( SDSHOT handle);
SDE_ERR	sdShotGetStat( SDSHOT handle, SDS_SHOT_STAT *shot_stat);
SDE_ERR	sdShotOpenPort( SDSHOT *handle);
SDE_ERR	sdShotPlay( SDSHOT handle, const Sint8 bank_num, const Sint8 data_num, const Sint8 priority);
SDE_ERR	sdShotSetFxLev( SDSHOT handle, const Sint8 fx_lev);
SDE_ERR	sdShotSetPan( SDSHOT handle, const Sint8 pan, const Sint32 fade_time);
static unsigned char Panpot_Control(SND_WORK* set_snd_work);
SDE_ERR	sdShotSetPitch( SDSHOT handle, const Sint16 pitch, const Sint32 fade_time);
static short Pitch_Control(SND_WORK* set_snd_work);
SDE_ERR	sdShotSetVol( SDSHOT handle, const Sint8 vol, const Sint32 fade_time);
static unsigned char Volume_Control(SND_WORK* set_snd_work);
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

#endif
