#include "ps2_sg_sd.h"  
#include "ps2_MovieFunc.h"
#include "ps2_sfd_mw.h"
#include "ps2_snddrv.h"
#include "sdfunc.h"
#include "main.h"

#include <string.h>

short MIDI_HD_CHECK[4];
short SE_HD_CHECK[5];
SDHANDLE* __snd_handle__[40];
SND_WORK __snd_work__[40];
SDMIDI __midi_handle_top;
SDSHOT __shot_handle_top;
SDPSTM __pstm_handle_top;
int __midi_value;
int __shot_value;
int __pstm_value;
SDS_MEMBLK __snd_mem_blk__[20];
unsigned short use_se_info[6];
unsigned short req_se_info[6];
short SE_BANK[5];
short MIDI_BANK[4];
unsigned int ee_trans_hd_address;
unsigned int ee_trans_bd_address;
unsigned int ee_trans_sq_address;
unsigned int ee_trans_hd_size;
unsigned int ee_trans_bd_size;
unsigned int ee_trans_sq_size;
unsigned int iop_trans_hd_address;
unsigned int iop_trans_bd_address;
unsigned int iop_trans_sq_address;
unsigned int iop_trans_offset;
unsigned int trans_bank_num;
unsigned int trans_type;
unsigned int trans_level;
unsigned int ee_trans_cue;
unsigned int iop_packet_flag;
int iop_zero_buff;
int iop_buff;
int iop_read_buff;
static void(*__snd_set_end_func__)(void*);
static void* __snd_end_func_arg__;
static int snd_data_down_load;
int __sg_sd_snd_init__;
char sound_flag;
/* unused below */
/*int AdxTInfoBack[10][4];
unsigned int old_trans_size;
unsigned int ee_trans_type;*/

// 100% matching! 
SDE_ERR	sdBankDownload( SDMEMBLK handle, const SDE_DATA_TYPE bank_type, const Sint8 bank_num)
{
    SND_WORK* chk_snd_work; 
    unsigned int* snd_data; 
    int i;                  
    unsigned int *temp; // not from the debugging symbols

    if (__sg_sd_snd_init__ != 0)
    {
        switch (bank_type) 
        {                          
        case SDE_DATA_TYPE_MIDI_SEQ_BANK:
            chk_snd_work = (SND_WORK*)*__midi_handle_top;
            
            for (i = 0; i < __midi_value; i++, chk_snd_work++)
            {
                if (((get_iop_snddata.midi_info & (1 << i))) && (chk_snd_work->bank_num == bank_num)) 
                {
                    SdrBgmStop(chk_snd_work->port_num);
                }
            }
            
            SdrSendReq(0);
            
            ee_trans_sq_address = handle->m_Member[1];
            ee_trans_sq_size = handle->m_Member[2];
            
            iop_trans_sq_address = iop_data_buff;
            
            trans_bank_num = bank_num;
            trans_type = bank_type;
            
            trans_level = 0;
            break; 
        case SDE_DATA_TYPE_MIDI_PRG_BANK:
            chk_snd_work = (SND_WORK*)*__midi_handle_top;
            
            for (i = 0; i < __midi_value; i++, chk_snd_work++)
            {
                if (((get_iop_snddata.midi_info & (1 << i))) && (chk_snd_work->bank_num == bank_num)) 
                {
                    SdrBgmStop(chk_snd_work->port_num);
                }
            }
            
            SdrSendReq(0);
            
            snd_data = (void*)handle->m_Member[1];
            
            ee_trans_hd_address = (unsigned int)snd_data + ((unsigned int*)snd_data)[0];
            ee_trans_bd_address = (unsigned int)snd_data + ((unsigned int*)snd_data)[2];
            
            iop_trans_offset = 0;
            
            ee_trans_hd_size = ((unsigned int*)snd_data)[1];
            ee_trans_bd_size = ((unsigned int*)snd_data)[3];
            
            trans_bank_num = bank_num;
            trans_type = bank_type;
            
            iop_trans_hd_address = iop_data_buff;
            iop_trans_bd_address = iop_data_buff;
            
            trans_level = 0;
            
            iop_packet_flag = 0;
            break;
        case SDE_DATA_TYPE_SHOT_BANK:
            snd_data = (void*)handle->m_Member[1];
            
            temp = (unsigned int*)((char*)snd_data + ((unsigned int*)snd_data)[0]);
            
            if ((!((unsigned int)temp & 0x3)) && (*temp != 0)) 
            {
                chk_snd_work = (SND_WORK*)*__midi_handle_top;
                
                for (i = 0; i < __shot_value; i++, chk_snd_work++) 
                {
                    if ((((1 << chk_snd_work->channel_num) & get_iop_snddata.se_info[chk_snd_work->port_num])) && (bank_num == chk_snd_work->port_num))
                    {
                        SdrSeCancel((char)chk_snd_work->channel_num | ((chk_snd_work->port_num << 16) | (chk_snd_work->bank_num << 8)));
                    }
                }
                
                SdrSendReq(0);
                
                ee_trans_hd_address = (int)snd_data + ((unsigned int*)snd_data)[0];
                ee_trans_bd_address = (int)snd_data + ((unsigned int*)snd_data)[2];
                
                iop_trans_offset = 0;
                
                ee_trans_hd_size = ((unsigned int*)snd_data)[1];
                ee_trans_bd_size = ((unsigned int*)snd_data)[3];
                
                trans_bank_num = bank_num;
                trans_type = bank_type;
                
                iop_trans_hd_address = iop_data_buff;
                iop_trans_bd_address = iop_data_buff;
                
                trans_level = 0;
                
                iop_packet_flag = 0;
            }
            
            break;
        case SDE_DATA_TYPE_FX_OUT_BANK:
        case SDE_DATA_TYPE_FX_PRG_BANK:
            break;
        }
        
        SdrSendReq(0);
        
        snd_data_down_load = 1;
        
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT;
}

// 100% matching! 
SDE_ERR	sdDrvInit( SDMEMBLK handle)
{
    char trans_0_buff[2175]; 
    char* _0_buf; 

    SdrInit();
    
    sceSdRemoteInit();
    
    SdrGetStateSend(16, 2048);
    
    iop_buff = (int)sceSifAllocIopHeap(12288);
    
    if (iop_buff < 0) 
    {
        printf("Cannot allocate IOP memory\n", iop_buff);
        
        return SDE_ERR_NOTHING;
    }
    else 
    {
        printf("IOP memory 0x%08x(size:%d) is allocated\n", iop_buff, 12288);
        
        iop_zero_buff = (int)sceSifAllocIopHeap(2048);
    }
    
    if (iop_zero_buff < 0)
    {
        printf("Cannot allocate IOP memory\n", iop_zero_buff);
        
        return SDE_ERR_NOTHING;
    }
    else 
    {
        printf("IOP memory 0x%08x(size:%d) is allocated\n", iop_zero_buff, 2048);
        
        _0_buf = (char*)((int)&trans_0_buff[127] & ~0x7F);
        
        memset(_0_buf, 0, 2048);
        
        sendToIOP(iop_zero_buff, (unsigned char*)_0_buf, 2048);
        
        iRingBufNum = 10;
        
        iop_read_buff = (int)sceSifAllocIopHeap(327696);
    }
    
    if (iop_read_buff < 0)
    {
        printf("Cannot allocate IOP memory\n", iop_read_buff);
        
        while (TRUE);
    }
    else 
    {
        printf("IOP memory 0x%08x(size:%d) is allocated\n", iop_read_buff, (iRingBufNum * 32768) + 16);
        
        SdrSetRev(0, 0, 0, 0, 0);
        SdrSetRev(1, 0, 0, 0, 0);
        
        RoomFxLevel = 0;
        
        FxLevelTimer = 0;
        
        CurrentFxLevel = 0;
        AddFxLevel = 0;
        
        SdrSetRev(0, 5, 0, 0, 0);
        SdrSetRev(1, 5, CurrentFxLevel, 0, 0);
        
        return SDE_ERR_NOTHING;
    }
}

// 100% matching!
SDE_ERR	sdGddaSetPan( const Sint8 leftPan, const Sint8 right_pan)
{
    if (__sg_sd_snd_init__ != 0)
    {
        printf("sdGddaSetPan NOT USED!\n");
        
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT;
}

// 100% matching!
SDE_ERR	sdLibInit( Void *wrk_ptr, Sint32 mem_blk_handle_max, Sint32 second_host_cmd_max) 
{
    int i;
    int j;
	
    __sg_sd_snd_init__ = 1;
    
    for (i = 0; i < 20; i++) 
    {
        for (j = 0; j < 16; j++) 
        {
            __snd_mem_blk__[i].m_Member[j] = 0;
        }
    }
    
    for (i = 0; i < 6; i++) 
    {
        use_se_info[i] = 0;
        req_se_info[i] = 0;
    }
    
    return SDE_ERR_NOTHING;
}

// 100% matching!
SDE_ERR	sdMemBlkCreate( SDMEMBLK *handle)
{
    int i;
    
    if (__sg_sd_snd_init__ != 0) 
    {
        for (i = 0; i < 20; i++) 
        {
            if (__snd_mem_blk__[i].m_Member[0] == 0) 
            {
                break;
            }
        } 
        
        if (i == 20) 
        {
            return SDE_ERR_HANDLE_NO_ENOUGH;
        }
        else 
        {
            __snd_mem_blk__[i].m_Member[0] = 1;
        
            handle[0] = &__snd_mem_blk__[i];
            
            return SDE_ERR_NOTHING;
        }
    }
    
    return SDE_ERR_NO_INIT;
}

// 100% matching!
SDE_ERR	sdMemBlkDestroy( SDMEMBLK handle)
{
    int i;

    if (__sg_sd_snd_init__ != 0) 
    {
        if (handle == NULL) 
        {
            return SDE_ERR_HANDLE_NULL;
        }
        
        for (i = 0; i < 16; i++)
        {
            handle->m_Member[i] = 0;
        } 
        
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT;
}

// 100% matching!
SDE_ERR	sdMemBlkSetPrm( SDMEMBLK handle, const Void *src_blk_ptr, const Sint32 src_blk_sz, const SD_MEMBLK_CALLBACK_FUNC callback_func, const Void *callback_first_arg) 
{
    if (__sg_sd_snd_init__ != 0)
    {
        if (handle == NULL) 
        {
            return SDE_ERR_HANDLE_NULL;
        }
        
        handle->m_Member[1] = (unsigned int)src_blk_ptr;
        handle->m_Member[2] = src_blk_sz;
        
        __snd_set_end_func__ = callback_func;
        
        __snd_end_func_arg__ = (void*)callback_first_arg;
        
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT;
}

// 
// Start address: 0x2db5e0
SDE_ERR	sdMidiClosePort( SDMIDI handle)
{
	// Line 1083, Address: 0x2db5e0, Func Offset: 0
	// Line 1087, Address: 0x2db5ec, Func Offset: 0xc
	// Line 1089, Address: 0x2db5fc, Func Offset: 0x1c
	// Line 1090, Address: 0x2db608, Func Offset: 0x28
	// Line 1095, Address: 0x2db614, Func Offset: 0x34
	// Line 1096, Address: 0x2db634, Func Offset: 0x54
	// Line 1099, Address: 0x2db63c, Func Offset: 0x5c
	// Line 1100, Address: 0x2db644, Func Offset: 0x64
	// Line 1101, Address: 0x2db64c, Func Offset: 0x6c
	// Line 1102, Address: 0x2db654, Func Offset: 0x74
	// Line 1103, Address: 0x2db658, Func Offset: 0x78
	// Line 1104, Address: 0x2db65c, Func Offset: 0x7c
	// Line 1105, Address: 0x2db660, Func Offset: 0x80
	// Line 1106, Address: 0x2db664, Func Offset: 0x84
	// Line 1107, Address: 0x2db668, Func Offset: 0x88
	// Line 1108, Address: 0x2db66c, Func Offset: 0x8c
	// Line 1109, Address: 0x2db670, Func Offset: 0x90
	// Line 1111, Address: 0x2db674, Func Offset: 0x94
	// Line 1110, Address: 0x2db678, Func Offset: 0x98
	// Line 1111, Address: 0x2db67c, Func Offset: 0x9c
	// Line 1113, Address: 0x2db680, Func Offset: 0xa0
	// Line 1116, Address: 0x2db688, Func Offset: 0xa8
	// Line 1118, Address: 0x2db690, Func Offset: 0xb0
	// Func End, Address: 0x2db6a0, Func Offset: 0xc0
    scePrintf("sdMidiClosePort - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2db6a0
SDE_ERR	sdMidiGetStat( SDMIDI handle, SDS_MIDI_STAT *midi_stat)
{
	// Line 1148, Address: 0x2db6a0, Func Offset: 0
	// Line 1149, Address: 0x2db6b0, Func Offset: 0x10
	// Line 1150, Address: 0x2db6bc, Func Offset: 0x1c
	// Line 1156, Address: 0x2db6c8, Func Offset: 0x28
	// Line 1157, Address: 0x2db6e8, Func Offset: 0x48
	// Line 1158, Address: 0x2db6f0, Func Offset: 0x50
	// Line 1160, Address: 0x2db6f8, Func Offset: 0x58
	// Line 1162, Address: 0x2db708, Func Offset: 0x68
	// Line 1165, Address: 0x2db710, Func Offset: 0x70
	// Line 1167, Address: 0x2db718, Func Offset: 0x78
	// Func End, Address: 0x2db720, Func Offset: 0x80
    scePrintf("sdMidiGetStat - UNIMPLEMENTED!\n");
}

// 100% matching! 
SDE_ERR	sdMidiOpenPort( SDMIDI *handle)
{
    int i;
    SND_WORK* check_snd_work;
    SND_WORK* temp; // not from the debugging symbols
	
    if (__sg_sd_snd_init__ != 0) 
    {
        check_snd_work = (SND_WORK*)*__midi_handle_top;
        
        for (i = 0; i < __midi_value; i++, check_snd_work++) 
        {
            if (check_snd_work->port_check == 0) 
            {
                break;
            }
        } 
        
        if (i == __midi_value) 
        {
            return SDE_ERR_HANDLE_NO_ENOUGH;
        }
        else 
        {
            check_snd_work->port_check = 1;
            
            check_snd_work->vol = 127;
            
            check_snd_work->pan = 64;
            
            check_snd_work->pitch = 8192;
            
            check_snd_work->port_num = i;
            
            check_snd_work->req = 255;

            if (i == 2) 
            {
                temp = (SND_WORK*)*__midi_handle_top; 
                
                temp[8].port_num = 255;  // TODO: rewrite these two lines, likely wrong cast
                temp[9].port_num = 255;
            }
            
            *handle = &__midi_handle_top[i];
            
            return SDE_ERR_NOTHING;
        }
    }
    
    return SDE_ERR_NO_INIT;
}

// 100% matching!
SDE_ERR	sdMidiPlay( SDMIDI handle, const Sint8 bank_num, const Sint8 data_num, const Sint8 priority)
{
    SND_WORK* temp; // not from the debugging symbols
    unsigned int ch_check;

    if (__sg_sd_snd_init__ != 0)
    {
        temp = (SND_WORK*)*handle;
        
        if (temp == NULL) 
        {
            return SDE_ERR_HANDLE_NULL;  
        }
        
        ch_check = temp->port_num;
        
        if ((get_iop_snddata.midi_info & (1 << ch_check))) 
        {
            SdrBgmStop(ch_check);
        }
        
        if (ch_check == 2)
        {
            ch_check = 8;
        }
        else if (ch_check == 8) 
        {
            ch_check = 9;
        } 
        else if (ch_check == 9) 
        {
            ch_check = 2;
        }
        
        temp->port_num = ch_check;
        temp->channel_num = data_num;
        temp->bank_num = bank_num;
        
        temp->req = 1;
        
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT;  
}

// 100% matching!
SDE_ERR	sdMidiSetFxLev( SDMIDI handle, const Sint8 fx_lev)
{
    if (__sg_sd_snd_init__ != 0) 
    {
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT;
}

/*// 
// Start address: 0x2db910
SDE_ERR sdMidiSetPan(SDS_PORT_REF** handle, char pan, int fade_time)
{
	char set_pan;
	// Line 1402, Address: 0x2db910, Func Offset: 0
	// Line 1407, Address: 0x2db918, Func Offset: 0x8
	// Line 1409, Address: 0x2db928, Func Offset: 0x18
	// Line 1410, Address: 0x2db934, Func Offset: 0x24
	// Line 1415, Address: 0x2db940, Func Offset: 0x30
	// Line 1417, Address: 0x2db954, Func Offset: 0x44
	// Line 1418, Address: 0x2db95c, Func Offset: 0x4c
	// Line 1419, Address: 0x2db968, Func Offset: 0x58
	// Line 1420, Address: 0x2db96c, Func Offset: 0x5c
	// Line 1421, Address: 0x2db974, Func Offset: 0x64
	// Line 1425, Address: 0x2db978, Func Offset: 0x68
	// Line 1426, Address: 0x2db980, Func Offset: 0x70
	// Line 1429, Address: 0x2db988, Func Offset: 0x78
	// Line 1431, Address: 0x2db98c, Func Offset: 0x7c
	// Line 1433, Address: 0x2db990, Func Offset: 0x80
	// Line 1436, Address: 0x2db99c, Func Offset: 0x8c
	// Line 1438, Address: 0x2db9a4, Func Offset: 0x94
	// Func End, Address: 0x2db9b0, Func Offset: 0xa0
}*/

// 
// Start address: 0x2db9b0
SDE_ERR	sdMidiSetPitch( SDMIDI handle, const Sint16 pitch, const Sint32 fade_time)
{
	unsigned short set_pitch;
	// Line 1464, Address: 0x2db9b0, Func Offset: 0
	// Line 1469, Address: 0x2db9b8, Func Offset: 0x8
	// Line 1471, Address: 0x2db9c8, Func Offset: 0x18
	// Line 1472, Address: 0x2db9d4, Func Offset: 0x24
	// Line 1480, Address: 0x2db9e0, Func Offset: 0x30
	// Line 1481, Address: 0x2db9f0, Func Offset: 0x40
	// Line 1482, Address: 0x2dba1c, Func Offset: 0x6c
	// Line 1483, Address: 0x2dba24, Func Offset: 0x74
	// Line 1484, Address: 0x2dba2c, Func Offset: 0x7c
	// Line 1485, Address: 0x2dba58, Func Offset: 0xa8
	// Line 1487, Address: 0x2dba60, Func Offset: 0xb0
	// Line 1494, Address: 0x2dba64, Func Offset: 0xb4
	// Line 1496, Address: 0x2dba74, Func Offset: 0xc4
	// Line 1498, Address: 0x2dba7c, Func Offset: 0xcc
	// Line 1499, Address: 0x2dba88, Func Offset: 0xd8
	// Line 1506, Address: 0x2dba8c, Func Offset: 0xdc
	// Line 1507, Address: 0x2dba94, Func Offset: 0xe4
	// Line 1508, Address: 0x2dbaa0, Func Offset: 0xf0
	// Line 1509, Address: 0x2dbaa4, Func Offset: 0xf4
	// Line 1510, Address: 0x2dbaac, Func Offset: 0xfc
	// Line 1514, Address: 0x2dbab0, Func Offset: 0x100
	// Line 1515, Address: 0x2dbab8, Func Offset: 0x108
	// Line 1518, Address: 0x2dbac0, Func Offset: 0x110
	// Line 1520, Address: 0x2dbac4, Func Offset: 0x114
	// Line 1522, Address: 0x2dbac8, Func Offset: 0x118
	// Line 1525, Address: 0x2dbad4, Func Offset: 0x124
	// Line 1527, Address: 0x2dbadc, Func Offset: 0x12c
	// Func End, Address: 0x2dbae8, Func Offset: 0x138
    scePrintf("sdMidiSetPitch - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2dbaf0
SDE_ERR	sdMidiSetSpeed( SDMIDI handle, const Sint16 speed, const Sint32 fade_time)
{
	// Line 1554, Address: 0x2dbaf0, Func Offset: 0
	// Line 1556, Address: 0x2dbaf8, Func Offset: 0x8
	// Line 1558, Address: 0x2dbb08, Func Offset: 0x18
	// Line 1560, Address: 0x2dbb14, Func Offset: 0x24
	// Line 1563, Address: 0x2dbb1c, Func Offset: 0x2c
	// Line 1565, Address: 0x2dbb24, Func Offset: 0x34
	// Func End, Address: 0x2dbb30, Func Offset: 0x40
    scePrintf("sdMidiSetSpeed - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2dbb30
SDE_ERR sdMidiSetVol(SDS_PORT_REF** handle, char vol, int fade_time)
{
	// Line 1591, Address: 0x2dbb30, Func Offset: 0
	// Line 1596, Address: 0x2dbb38, Func Offset: 0x8
	// Line 1598, Address: 0x2dbb48, Func Offset: 0x18
	// Line 1599, Address: 0x2dbb54, Func Offset: 0x24
	// Line 1604, Address: 0x2dbb60, Func Offset: 0x30
	// Line 1605, Address: 0x2dbb68, Func Offset: 0x38
	// Line 1606, Address: 0x2dbb74, Func Offset: 0x44
	// Line 1607, Address: 0x2dbb78, Func Offset: 0x48
	// Line 1608, Address: 0x2dbb7c, Func Offset: 0x4c
	// Line 1613, Address: 0x2dbb80, Func Offset: 0x50
	// Line 1615, Address: 0x2dbb94, Func Offset: 0x64
	// Line 1623, Address: 0x2dbb9c, Func Offset: 0x6c
	// Line 1624, Address: 0x2dbba8, Func Offset: 0x78
	// Line 1625, Address: 0x2dbbac, Func Offset: 0x7c
	// Line 1628, Address: 0x2dbbb4, Func Offset: 0x84
	// Line 1635, Address: 0x2dbbbc, Func Offset: 0x8c
	// Line 1636, Address: 0x2dbbc4, Func Offset: 0x94
	// Line 1645, Address: 0x2dbbcc, Func Offset: 0x9c
	// Line 1647, Address: 0x2dbbe0, Func Offset: 0xb0
	// Line 1655, Address: 0x2dbbe8, Func Offset: 0xb8
	// Line 1656, Address: 0x2dbbf4, Func Offset: 0xc4
	// Line 1657, Address: 0x2dbbf8, Func Offset: 0xc8
	// Line 1660, Address: 0x2dbc00, Func Offset: 0xd0
	// Line 1666, Address: 0x2dbc08, Func Offset: 0xd8
	// Line 1669, Address: 0x2dbc14, Func Offset: 0xe4
	// Line 1671, Address: 0x2dbc1c, Func Offset: 0xec
	// Func End, Address: 0x2dbc28, Func Offset: 0xf8
}*/

// 100% matching!
SDE_ERR	sdMidiStop( SDMIDI handle)
{
    SND_WORK* temp; // not from the debugging symbols

    if (__sg_sd_snd_init__ != 0) 
    {
        temp = (SND_WORK*)*handle;
        
        if (temp == NULL) 
        {
            return SDE_ERR_HANDLE_NULL;
        }

        if (SdrBgmStop(temp->port_num) == 0) 
        {
            return SDE_ERR_NOTHING;
        }
        
        return SDE_ERR_HOST_CMD_BUF_NO_ENOUGH;
    }
    
    return SDE_ERR_NO_INIT;
}

// 100% matching!
SDE_ERR	sdShotClosePort( SDSHOT handle)
{
    SND_WORK* temp; // not from the debugging symbols

    if (__sg_sd_snd_init__ != 0) 
    {
        temp = (SND_WORK*)*handle;
        
        if (temp == NULL) 
        {
            return SDE_ERR_HANDLE_NULL; 
        }

        if (((1 << temp->channel_num) & get_iop_snddata.se_info[temp->port_num]))
        {
            SdrSeCancel((char)temp->channel_num | (((int)temp->port_num << 16) | (temp->bank_num << 8)));
            
            use_se_info[temp->port_num] &= ~(1 << (temp->channel_num & 0x7));
        }
        
        temp->port_check = 0;
        
        temp->vol = 127;
        temp->pan = 64;
        temp->pitch = 8192;
        
        temp->vol_old = 0;
        temp->pan_old = 0;
        temp->pitch_old = 0;
        
        temp->vol_timer = 0;
        temp->pan_timer = 0;
        temp->pitch_timer = 0;
        
        temp->port_num = 0;
        temp->channel_num = -1;
        temp->bank_num = 0;
        
        temp->req = 255;
        
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT; 
}

// 100% matching! 
SDE_ERR	sdShotGetStat( SDSHOT handle, SDS_SHOT_STAT *shot_stat)
{
    SND_WORK* temp; // not from the debugging symbols

    if (__sg_sd_snd_init__ != 0)
    {
        temp = (SND_WORK*)*handle;
        
        if (temp == NULL) 
        {
            return SDE_ERR_HANDLE_NULL;
        }

        if (((1 << temp->channel_num) & get_iop_snddata.se_info[temp->port_num])) 
        {
            shot_stat->m_Flg |= 0x1;
        } 
        else 
        {
            shot_stat->m_Flg &= ~0x1;
        }
        
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT;
}

// 100% matching! 
SDE_ERR	sdShotOpenPort( SDSHOT *handle)
{
    int i;
    SND_WORK* check_snd_work;
	
    if (__sg_sd_snd_init__ != 0) 
    {
        check_snd_work = (SND_WORK*)*__shot_handle_top;
        
        for (i = 0; i < __shot_value; i++, check_snd_work++) 
        {
            if (check_snd_work->port_check == 0) 
            {
                break;
            }
        } 
        
        if (i == __shot_value) 
        {
            return SDE_ERR_HANDLE_NO_ENOUGH;
        }
        else 
        {
            check_snd_work->port_check = 1;
            
            check_snd_work->vol = 127;
            
            check_snd_work->pan = 64;
            
            check_snd_work->pitch = 8192;
            
            check_snd_work->port_num = 0;
            check_snd_work->channel_num = -1;
            
            check_snd_work->req = 255;
            
            *handle = &__shot_handle_top[i];
            
            return SDE_ERR_NOTHING;
        }
    }
    
    return SDE_ERR_NO_INIT;
}

/*// 
// Start address: 0x2dbf30
SDE_ERR sdShotPlay(SDS_PORT_REF** handle, char bank_num, char data_num, char priority)
{
	int cancel_flag;
	unsigned short* check_se_channel;
	unsigned int ch_check;
	// Line 1918, Address: 0x2dbf30, Func Offset: 0
	// Line 1933, Address: 0x2dbf54, Func Offset: 0x24
	// Line 1935, Address: 0x2dbf70, Func Offset: 0x40
	// Line 1936, Address: 0x2dbf7c, Func Offset: 0x4c
	// Line 1983, Address: 0x2dbf88, Func Offset: 0x58
	// Line 1984, Address: 0x2dbfc0, Func Offset: 0x90
	// Line 1989, Address: 0x2dbfcc, Func Offset: 0x9c
	// Line 1991, Address: 0x2dbfd8, Func Offset: 0xa8
	// Line 1994, Address: 0x2dc000, Func Offset: 0xd0
	// Line 1999, Address: 0x2dc020, Func Offset: 0xf0
	// Line 2004, Address: 0x2dc024, Func Offset: 0xf4
	// Line 2012, Address: 0x2dc030, Func Offset: 0x100
	// Line 2016, Address: 0x2dc054, Func Offset: 0x124
	// Line 2012, Address: 0x2dc058, Func Offset: 0x128
	// Line 2016, Address: 0x2dc060, Func Offset: 0x130
	// Line 2020, Address: 0x2dc064, Func Offset: 0x134
	// Line 2022, Address: 0x2dc074, Func Offset: 0x144
	// Line 2029, Address: 0x2dc080, Func Offset: 0x150
	// Line 2033, Address: 0x2dc084, Func Offset: 0x154
	// Line 2035, Address: 0x2dc09c, Func Offset: 0x16c
	// Line 2036, Address: 0x2dc0a0, Func Offset: 0x170
	// Line 2038, Address: 0x2dc0a8, Func Offset: 0x178
	// Line 2048, Address: 0x2dc0b8, Func Offset: 0x188
	// Line 2052, Address: 0x2dc0c4, Func Offset: 0x194
	// Line 2061, Address: 0x2dc0d0, Func Offset: 0x1a0
	// Line 2058, Address: 0x2dc0d4, Func Offset: 0x1a4
	// Line 2063, Address: 0x2dc0d8, Func Offset: 0x1a8
	// Line 2064, Address: 0x2dc0e4, Func Offset: 0x1b4
	// Line 2070, Address: 0x2dc0f0, Func Offset: 0x1c0
	// Line 2072, Address: 0x2dc0f8, Func Offset: 0x1c8
	// Line 2076, Address: 0x2dc104, Func Offset: 0x1d4
	// Line 2086, Address: 0x2dc108, Func Offset: 0x1d8
	// Line 2076, Address: 0x2dc110, Func Offset: 0x1e0
	// Line 2084, Address: 0x2dc120, Func Offset: 0x1f0
	// Line 2086, Address: 0x2dc124, Func Offset: 0x1f4
	// Line 2088, Address: 0x2dc12c, Func Offset: 0x1fc
	// Line 2086, Address: 0x2dc130, Func Offset: 0x200
	// Line 2088, Address: 0x2dc144, Func Offset: 0x214
	// Line 2094, Address: 0x2dc14c, Func Offset: 0x21c
	// Line 2096, Address: 0x2dc154, Func Offset: 0x224
	// Func End, Address: 0x2dc17c, Func Offset: 0x24c
}*/

// 
// Start address: 0x2dc180
SDE_ERR	sdShotSetFxLev( SDSHOT handle, const Sint8 fx_lev)
{
	// Line 2126, Address: 0x2dc180, Func Offset: 0
	// Line 2131, Address: 0x2dc194, Func Offset: 0x14
	// Func End, Address: 0x2dc19c, Func Offset: 0x1c
    scePrintf("sdShotSetFxLev - UNIMPLEMENTED!\n");
}

// 100% matching!
SDE_ERR	sdShotSetPan( SDSHOT handle, const Sint8 pan, const Sint32 fade_time)
{ 
    SND_WORK* check_snd_work; // not from the debugging symbols
    char set_pan;

    if (__sg_sd_snd_init__ != 0) 
    {
        if (*handle == 0) 
        {
            return SDE_ERR_HANDLE_NULL;
        }

        check_snd_work = (SND_WORK*)*handle;
        
        set_pan = (pan / 2) + 64;
        
        if (fade_time != 0) 
        {
            if (check_snd_work->pan_timer == 0)
            {
                check_snd_work->pan_timer = fade_time;
                
                check_snd_work->pan_old = check_snd_work->pan;
                
                check_snd_work->pan = set_pan;
            }
            
            Panpot_Control(check_snd_work);
        } 
        else 
        {
            check_snd_work->pan_timer = 0;
            
            check_snd_work->pan = set_pan;
        }
        
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT;
}

// 
// Start address: 0x2dc240
unsigned char Panpot_Control(SND_WORK* set_snd_work)
{
	float dpan;
	float shift_pan;
	// Line 2196, Address: 0x2dc240, Func Offset: 0
	// Line 2201, Address: 0x2dc248, Func Offset: 0x8
	// Line 2202, Address: 0x2dc254, Func Offset: 0x14
	// Line 2204, Address: 0x2dc268, Func Offset: 0x28
	// Line 2205, Address: 0x2dc270, Func Offset: 0x30
	// Line 2206, Address: 0x2dc2a4, Func Offset: 0x64
	// Line 2205, Address: 0x2dc2a8, Func Offset: 0x68
	// Line 2206, Address: 0x2dc2b8, Func Offset: 0x78
	// Line 2207, Address: 0x2dc318, Func Offset: 0xd8
	// Line 2206, Address: 0x2dc31c, Func Offset: 0xdc
	// Line 2207, Address: 0x2dc320, Func Offset: 0xe0
	// Line 2208, Address: 0x2dc324, Func Offset: 0xe4
	// Line 2210, Address: 0x2dc32c, Func Offset: 0xec
	// Line 2211, Address: 0x2dc334, Func Offset: 0xf4
	// Line 2212, Address: 0x2dc368, Func Offset: 0x128
	// Line 2211, Address: 0x2dc36c, Func Offset: 0x12c
	// Line 2212, Address: 0x2dc37c, Func Offset: 0x13c
	// Line 2213, Address: 0x2dc3dc, Func Offset: 0x19c
	// Line 2212, Address: 0x2dc3e0, Func Offset: 0x1a0
	// Line 2213, Address: 0x2dc3e4, Func Offset: 0x1a4
	// Line 2215, Address: 0x2dc3ec, Func Offset: 0x1ac
	// Line 2219, Address: 0x2dc3fc, Func Offset: 0x1bc
	// Line 2221, Address: 0x2dc400, Func Offset: 0x1c0
	// Line 2223, Address: 0x2dc408, Func Offset: 0x1c8
	// Func End, Address: 0x2dc414, Func Offset: 0x1d4
	scePrintf("Panpot_Control - UNIMPLEMENTED!\n");
}

// 100% matching!
SDE_ERR	sdShotSetPitch( SDSHOT handle, const Sint16 pitch, const Sint32 fade_time) 
{
    SND_WORK* temp; // not from the debugging symbols
    unsigned short set_pitch;
    
    if (__sg_sd_snd_init__ != 0) 
    {
        temp = (SND_WORK*)*handle;
        
        if (temp == NULL) 
        {
            return SDE_ERR_HANDLE_NULL;
        }
        
        set_pitch = ((pitch << 1) + 8192) + pitch;
        
        if (set_pitch < 512)
        {
            set_pitch = 512;
        } 
        else if (set_pitch > 16383) 
        {
            set_pitch = 16383;
        }
        
        if (fade_time != 0) 
        {
            if (temp->pitch_timer == 0) 
            {
                temp->pitch_timer = fade_time;
                
                temp->pitch_old = temp->pitch;
                temp->pitch = set_pitch;
            }
            
            Pitch_Control(temp);
        } 
        else 
        {
            temp->pitch_timer = 0;
            
            temp->pitch = set_pitch;
        }
        
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT;
}

// 
// Start address: 0x2dc4e0
short Pitch_Control(SND_WORK* set_snd_work)
{
	float dpitch;
	float pitch_bend;
	// Line 2318, Address: 0x2dc4e0, Func Offset: 0
	// Line 2323, Address: 0x2dc4e8, Func Offset: 0x8
	// Line 2324, Address: 0x2dc4f4, Func Offset: 0x14
	// Line 2326, Address: 0x2dc508, Func Offset: 0x28
	// Line 2327, Address: 0x2dc510, Func Offset: 0x30
	// Line 2328, Address: 0x2dc544, Func Offset: 0x64
	// Line 2327, Address: 0x2dc548, Func Offset: 0x68
	// Line 2328, Address: 0x2dc558, Func Offset: 0x78
	// Line 2329, Address: 0x2dc58c, Func Offset: 0xac
	// Line 2328, Address: 0x2dc590, Func Offset: 0xb0
	// Line 2329, Address: 0x2dc59c, Func Offset: 0xbc
	// Line 2330, Address: 0x2dc5a4, Func Offset: 0xc4
	// Line 2332, Address: 0x2dc5ac, Func Offset: 0xcc
	// Line 2333, Address: 0x2dc5b4, Func Offset: 0xd4
	// Line 2334, Address: 0x2dc5e8, Func Offset: 0x108
	// Line 2333, Address: 0x2dc5ec, Func Offset: 0x10c
	// Line 2334, Address: 0x2dc5fc, Func Offset: 0x11c
	// Line 2335, Address: 0x2dc630, Func Offset: 0x150
	// Line 2334, Address: 0x2dc634, Func Offset: 0x154
	// Line 2335, Address: 0x2dc640, Func Offset: 0x160
	// Line 2334, Address: 0x2dc648, Func Offset: 0x168
	// Line 2337, Address: 0x2dc64c, Func Offset: 0x16c
	// Line 2341, Address: 0x2dc65c, Func Offset: 0x17c
	// Line 2343, Address: 0x2dc660, Func Offset: 0x180
	// Line 2345, Address: 0x2dc668, Func Offset: 0x188
	// Func End, Address: 0x2dc674, Func Offset: 0x194
	scePrintf("Pitch_Control - UNIMPLEMENTED!\n");
}

// 100% matching!
SDE_ERR	sdShotSetVol( SDSHOT handle, const Sint8 vol, const Sint32 fade_time)
{
    SND_WORK* temp; // not from the debugging symbols

    if (__sg_sd_snd_init__ != 0) 
    {
        temp = (SND_WORK*)*handle;
        
        if (temp == NULL)
        {
            return SDE_ERR_HANDLE_NULL;
        }
        
        if (fade_time != 0)
        {
            if (temp->vol_timer == 0) 
            {
                temp->vol_timer = fade_time;
                temp->vol_set_time = fade_time;
                
                temp->vol_old = temp->vol;
                temp->vol = vol + 128;
            }
            
            Volume_Control(temp);
        } 
        else 
        {
            temp->vol_timer = 0;
            
            temp->vol = vol + 128;
        }
        
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT;
}

// 
// Start address: 0x2dc720
unsigned char Volume_Control(SND_WORK* set_snd_work)
{
	float dvol;
	float fade_vol;
	// Line 2458, Address: 0x2dc720, Func Offset: 0
	// Line 2463, Address: 0x2dc730, Func Offset: 0x10
	// Line 2464, Address: 0x2dc73c, Func Offset: 0x1c
	// Line 2466, Address: 0x2dc750, Func Offset: 0x30
	// Line 2467, Address: 0x2dc758, Func Offset: 0x38
	// Line 2468, Address: 0x2dc78c, Func Offset: 0x6c
	// Line 2467, Address: 0x2dc790, Func Offset: 0x70
	// Line 2468, Address: 0x2dc7a0, Func Offset: 0x80
	// Line 2469, Address: 0x2dc800, Func Offset: 0xe0
	// Line 2468, Address: 0x2dc804, Func Offset: 0xe4
	// Line 2469, Address: 0x2dc808, Func Offset: 0xe8
	// Line 2470, Address: 0x2dc80c, Func Offset: 0xec
	// Line 2472, Address: 0x2dc814, Func Offset: 0xf4
	// Line 2473, Address: 0x2dc81c, Func Offset: 0xfc
	// Line 2474, Address: 0x2dc850, Func Offset: 0x130
	// Line 2473, Address: 0x2dc854, Func Offset: 0x134
	// Line 2474, Address: 0x2dc864, Func Offset: 0x144
	// Line 2475, Address: 0x2dc8d0, Func Offset: 0x1b0
	// Line 2477, Address: 0x2dc8dc, Func Offset: 0x1bc
	// Line 2481, Address: 0x2dc8ec, Func Offset: 0x1cc
	// Line 2483, Address: 0x2dc8f0, Func Offset: 0x1d0
	// Line 2485, Address: 0x2dc8f8, Func Offset: 0x1d8
	// Func End, Address: 0x2dc90c, Func Offset: 0x1ec
	scePrintf("Volume_Control - UNIMPLEMENTED!\n");
}

// 100% matching!
SDE_ERR	sdShotStop( SDSHOT handle)
{
    SND_WORK* set_snd_work;

    if (__sg_sd_snd_init__ != 0) 
    {
        set_snd_work = (SND_WORK*)*handle;

        if (SdrSeCancel((set_snd_work->channel_num << 0) | ((set_snd_work->port_num << 16) | (set_snd_work->bank_num << 8))) == 0) 
        {
            return SDE_ERR_NOTHING;
        }
        
        return SDE_ERR_HOST_CMD_BUF_NO_ENOUGH;
    }

    return SDE_ERR_NO_INIT;
}

// 100% matching! 
SDE_ERR	sdSndClearFxPrg( Void)
{
    return (__sg_sd_snd_init__ != 0) ? SDE_ERR_NOTHING : SDE_ERR_NO_INIT;
}

// 100% matching! 
SDE_ERR	sdSndSetFxPrg( const Sint8 new_fx_prg_num, const Sint8 new_fx_out_num)
{
    return (__sg_sd_snd_init__ != 0) ? SDE_ERR_NOTHING : SDE_ERR_NO_INIT;
}

// 100% matching! 
SDE_ERR	sdSndSetMasterVol( const Sint8 vol)
{
    if (__sg_sd_snd_init__ != 0) 
    {
        if (vol) 
        {
            if ((vol < 0) || (vol > 15)) 
            {
                return SDE_ERR_PRM_OVER_RANGE;
            }
            else if (SdrMasterVol((vol * 1092) + 3) == -1) 
            {
                return SDE_ERR_HOST_CMD_BUF_NO_ENOUGH;
            }
            else 
            {
                return SDE_ERR_NOTHING;
            }
        }
        
        if (SdrMasterVol(0) == -1) 
        {
            return SDE_ERR_HOST_CMD_BUF_NO_ENOUGH;
        }
        else 
        {
            return SDE_ERR_NOTHING;
        }
    }
    
    return SDE_ERR_NO_INIT;
}

// 100% matching! 
SDE_ERR	sdSndSetPanMode( const SDE_PAN_MODE pan_mode) 
{
    int ret;

    if (__sg_sd_snd_init__ != 0)
    {
        if (pan_mode == 1) 
        {
            ret = SdrSetOutputMode(1);
            
            sceSSyn_SetOutputMode(1);
            
            ADXT_SetOutputMono(0);
            
            sound_flag = 0;
            
            goto label;
        }
        else if (pan_mode == 0) 
        {
            ret = SdrSetOutputMode(0);
            
            sceSSyn_SetOutputMode(0);
            
            ADXT_SetOutputMono(1);
            
            sound_flag = 1;
            
            goto label;
        }
        else 
        {
            return SDE_ERR_PRM_OVER_RANGE;
        }

    label:
        if (ret == 0) 
        {
            return SDE_ERR_NOTHING;
        }
        else 
        {
            return SDE_ERR_HOST_CMD_BUF_NO_ENOUGH;
        }
    }
    
    return SDE_ERR_NO_INIT;
}

// 100% matching! 
SDE_ERR	sdSndStopAll( Void)
{
    if (__sg_sd_snd_init__ != 0) 
    {
        return (SdrSeAllStop() == 0) ? SDE_ERR_NOTHING : SDE_ERR_HOST_CMD_BUF_NO_ENOUGH;
    }
    
    return SDE_ERR_NO_INIT;
}

// 100% matching!
int sndr_trans_func()
{
    int i;                 
    int current_trans_size; 

    switch (trans_type)
    {
    case SDE_DATA_TYPE_MIDI_SEQ_BANK:
        switch (trans_level)
        {
        case 0:
            while ((ee_trans_cue = CpSifDmaTransEEToIOP(ee_trans_sq_address, iop_trans_sq_address, ee_trans_sq_size, 0, 0)) == 0);
           
            trans_level = 1;
            break;
        case 1:
            while (sceSifDmaStat(ee_trans_cue) >= 0)
            {
                CpEEWait(10240);
            }
            
            SdrSQDataSet(trans_bank_num, ee_trans_sq_size);
            
            SdrSendReq(0);
            
            if ((__snd_set_end_func__ != NULL) && ((int)__snd_set_end_func__ != -1))
            {
                (*__snd_set_end_func__)(__snd_end_func_arg__);
            }
            
            snd_data_down_load = 0;
            break;
        }
        
        break;
    case SDE_DATA_TYPE_MIDI_PRG_BANK:
        switch (trans_level)
        {
        case 0:
            MIDI_HD_CHECK[trans_bank_num] = 0;
            
            current_trans_size = ee_trans_hd_size;
            
            for (i = 0; i < ee_trans_hd_size; i++)
            {
                MIDI_HD_CHECK[trans_bank_num] += ((char*)ee_trans_hd_address)[i];
            }
            
            while ((ee_trans_cue = CpSifDmaTransEEToIOP(ee_trans_hd_address, iop_trans_hd_address, ee_trans_hd_size, 0, 0)) == 0);
           
            trans_level = 1;
            break;
        case 1:
            while (sceSifDmaStat(ee_trans_cue) >= 0)
            {
                CpEEWait(10240);
            }
            
            SdrHDDataSet(trans_bank_num, ee_trans_hd_size);
            
            SdrSendReq(0);
            
            trans_level = 2;
            break;
        case 2:
            while (get_iop_snddata.midi_sum[trans_bank_num] == 0)
            {
                CpEEWait(1000);
                
                get_iopsnd_info();
            }
            
            if (get_iop_snddata.midi_sum[trans_bank_num] != MIDI_HD_CHECK[trans_bank_num])
            {
                while ((ee_trans_cue = CpSifDmaTransEEToIOP(ee_trans_hd_address, iop_trans_hd_address, ee_trans_hd_size, 0, 0)) == 0);
                
                trans_level = 1;
                break;
            }

            current_trans_size = ee_trans_bd_size;
            
            if (ee_trans_bd_size > 49152)
            {
                current_trans_size = 49152;
            }
            
            while ((ee_trans_cue = CpSifDmaTransEEToIOP(ee_trans_bd_address, iop_trans_bd_address, current_trans_size, 0, 0)) == 0);
            
            if (ee_trans_bd_size > 49152)
            {
                trans_level = 3;
            }
            else
            {
                trans_level = 4;
            }
            
            break;
        case 3:
            while (sceSifDmaStat(ee_trans_cue) >= 0)
            {
                CpEEWait(10240);
            }
            
            SdrBDDataTrans(MIDI_BANK[trans_bank_num], iop_trans_offset, 49152, iop_packet_flag);
            
            SdrSendReq(0);
            
            iop_packet_flag ^= 1;
            
            ee_trans_bd_size -= 49152;
            
            iop_trans_offset += 49152;
            
            ee_trans_bd_address += 49152;
            
            current_trans_size = ee_trans_bd_size;
            
            if (ee_trans_bd_size > 49152)
            {
                current_trans_size = 49152;
            }
            
            if (iop_packet_flag != 0)
            {
                while ((ee_trans_cue = CpSifDmaTransEEToIOP(ee_trans_bd_address, iop_trans_bd_address + 204800, current_trans_size, 0, 0)) == 0);
            }
            else
            {
                while ((ee_trans_cue = CpSifDmaTransEEToIOP(ee_trans_bd_address, iop_trans_bd_address, current_trans_size, 0, 0)) == 0);
            }
            
            if (ee_trans_bd_size > 49152)
            {
                trans_level = 3;
            }
            else
            {
                trans_level = 4;
            }
            
            break;
        case 4:
            while (sceSifDmaStat(ee_trans_cue) >= 0)
            {
                CpEEWait(10240);
            }
            
            SdrBDDataTrans(MIDI_BANK[trans_bank_num], iop_trans_offset, ee_trans_bd_size, iop_packet_flag);
            
            SdrSendReq(0);
            
            trans_level = 5;
            break;
        case 5:
            SdrBDDataSet(trans_bank_num);
            
            SdrSendReq(0);
            
            if ((__snd_set_end_func__ != NULL) && ((int)__snd_set_end_func__ != -1))
            {
                (*__snd_set_end_func__)(__snd_end_func_arg__);
            }
            
            snd_data_down_load = 0;
            break;
        }
        
        break;
    case SDE_DATA_TYPE_SHOT_BANK:
        switch (trans_level)
        {
        case 0:
        {
            int i;            
                
            SE_HD_CHECK[trans_bank_num] = 0;
            
            current_trans_size = ee_trans_hd_size;
            
            for (i = 0; i < ee_trans_hd_size; i++)
            {
                SE_HD_CHECK[trans_bank_num] += ((char*)ee_trans_hd_address)[i];
            }
            
            while ((ee_trans_cue = CpSifDmaTransEEToIOP(ee_trans_hd_address, iop_trans_hd_address, ee_trans_hd_size, 0, 0)) == 0);
            
            trans_level = 1;
            break;
        }
        case 1:
            while (sceSifDmaStat(ee_trans_cue) >= 0)
            {
                CpEEWait(10240);
            }
            
            SdrHDDataSet2(trans_bank_num, ee_trans_hd_size);
            
            SdrSendReq(0);
            
            trans_level = 2;
            break;
        case 2:
            while (get_iop_snddata.se_sum[trans_bank_num] == 0)
            {
                CpEEWait(1000);
                
                get_iopsnd_info();
            }
            
            if (get_iop_snddata.se_sum[trans_bank_num] != SE_HD_CHECK[trans_bank_num])
            {
                while ((ee_trans_cue = CpSifDmaTransEEToIOP(ee_trans_hd_address, iop_trans_hd_address, ee_trans_hd_size, 0, 0)) == 0);
                
                trans_level = 1;
                break;
            }

            current_trans_size = ee_trans_bd_size;
            
            if (ee_trans_bd_size > 49152)
            {
                current_trans_size = 49152;
            }
                
            while ((ee_trans_cue = CpSifDmaTransEEToIOP(ee_trans_bd_address, iop_trans_bd_address, current_trans_size, 0, 0)) == 0);

            if (ee_trans_bd_size > 49152)
            {
                trans_level = 3;
            }
            else
            {
                trans_level = 4;
            }
                
            break;
        case 3:
            while (sceSifDmaStat(ee_trans_cue) >= 0)
            {
                CpEEWait(10240);
            }
            
            SdrBDDataTrans(SE_BANK[trans_bank_num], iop_trans_offset, 49152, iop_packet_flag);
            
            SdrSendReq(0);
            
            iop_packet_flag ^= 1;
            
            ee_trans_bd_size -= 49152;
            
            iop_trans_offset += 49152;
            
            ee_trans_bd_address += 49152;
            
            current_trans_size = ee_trans_bd_size;
            
            if (ee_trans_bd_size > 49152)
            {
                current_trans_size = 49152;
            }
            
            if (iop_packet_flag != 0)
            {
                while ((ee_trans_cue = CpSifDmaTransEEToIOP(ee_trans_bd_address, iop_trans_bd_address + 204800, current_trans_size, 0, 0)) == 0);
            }
            else
            {
                while ((ee_trans_cue = CpSifDmaTransEEToIOP(ee_trans_bd_address, iop_trans_bd_address, current_trans_size, 0, 0)) == 0);
            }

            if (ee_trans_bd_size > 49152)
            {
                trans_level = 3;
            }
            else
            {
                trans_level = 4;
            }
            
            break;
        case 4:
            while (sceSifDmaStat(ee_trans_cue) >= 0)
            {
                CpEEWait(10240);
            }
            
            SdrBDDataTrans(SE_BANK[trans_bank_num], iop_trans_offset, ee_trans_bd_size, iop_packet_flag);
            
            SdrSendReq(0);
            
            trans_level = 5;
            break;
        case 5:
            SdrBDDataSet2(trans_bank_num);
            
            SdrSendReq(0);
            
            if ((__snd_set_end_func__ != NULL) && ((int)__snd_set_end_func__ != -1))
            {
                (*__snd_set_end_func__)(__snd_end_func_arg__);
            }
            
            snd_data_down_load = 0;
            break;
        }
        
        break;
    }
}

// 100% matching!
SDE_ERR	sdSysServer( Void)
{
    int i;                  
    SND_WORK* chk_snd_work; 
    unsigned char vol;      
    unsigned char pan;      
    short pitch;           
    unsigned int req;      
    
    if (__sg_sd_snd_init__ != 0) 
    {
        if (snd_data_down_load != 0) 
        {
            sndr_trans_func();
        }
        
        get_iopsnd_info();
        
        if (FxLevelTimer != 0)
        {
            FxLevelTimer--;
            
            if (FxLevelTimer == 0) 
            {
                CurrentFxLevel = RoomFxLevel;
            }
            else 
            {
                CurrentFxLevel += AddFxLevel;
            }
            
            SdrSetRev(0, 5, CurrentFxLevel, 0, 0);
            SdrSetRev(1, 5, CurrentFxLevel, 0, 0);
        }
        
        chk_snd_work = (SND_WORK*)*__shot_handle_top;
        
        for (i = 0; i < __shot_value; i++, chk_snd_work++) 
        {
            if (chk_snd_work->req == 1) 
            {
                SdrSeReq(chk_snd_work->channel_num | ((chk_snd_work->port_num << 16) | (chk_snd_work->bank_num << 8)), chk_snd_work->vol, chk_snd_work->pan, chk_snd_work->pitch);
                
                get_iop_snddata.se_info[chk_snd_work->port_num] |= 1 << chk_snd_work->channel_num;
               
                chk_snd_work->req = 254;
            }
            else if (((1 << chk_snd_work->channel_num) & get_iop_snddata.se_info[chk_snd_work->port_num])) 
            {
                if (chk_snd_work->vol_timer != 0) 
                {
                    vol = Volume_Control(chk_snd_work);
                } 
                else 
                {
                    vol = chk_snd_work->vol;
                }
                
                if (chk_snd_work->pan_timer != 0) 
                {
                    pan = Panpot_Control(chk_snd_work);
                }
                else 
                {
                    pan = chk_snd_work->pan;
                }
                
                if (chk_snd_work->pitch_timer != 0)
                {
                    pitch = Pitch_Control(chk_snd_work);
                }
                else 
                {
                    pitch = chk_snd_work->pitch;
                }
                
                req = (chk_snd_work->port_num << 16) | (chk_snd_work->bank_num << 8) | chk_snd_work->channel_num;
                
                if (sound_flag != 0) 
                {
                    pan = 64;
                }
                
                SdrSeChg(req, vol, pan, pitch);
                
                chk_snd_work->req = 255;
            }
            else if (chk_snd_work->req == 254)
            {
                get_iop_snddata.se_info[chk_snd_work->port_num] |= 1 << chk_snd_work->channel_num;
                
                chk_snd_work->req = 255;
            }
        }
        
        chk_snd_work = (SND_WORK*)*__midi_handle_top;
        
        for (i = 0; i < __midi_value; i++, chk_snd_work++) 
        {
            if (chk_snd_work->req == 1) 
            {
                SdrBgmReq(chk_snd_work->port_num, chk_snd_work->bank_num, chk_snd_work->vol, chk_snd_work->channel_num);
                
                get_iop_snddata.midi_info |= 1 << chk_snd_work->port_num;
                
                chk_snd_work->req = 254;
            }
            
            if ((get_iop_snddata.midi_info & (1 << chk_snd_work->port_num))) 
            {
                if (chk_snd_work->vol_timer != 0) 
                {
                    chk_snd_work->vol = Volume_Control(chk_snd_work);
                }
                
                if (chk_snd_work->pan_timer != 0) 
                {
                    chk_snd_work->pan = Panpot_Control(chk_snd_work);
                }
                
                if (chk_snd_work->pitch_timer != 0) 
                {
                    chk_snd_work->pitch = Pitch_Control(chk_snd_work);
                }
                
                SdrBgmChg(chk_snd_work->port_num, chk_snd_work->vol, chk_snd_work->pan, chk_snd_work->pitch);
                
                chk_snd_work->req = 255;
            } 
            else if (chk_snd_work->req == 254) 
            {
                get_iop_snddata.midi_info |= 1 << chk_snd_work->port_num;
                
                chk_snd_work->req = 255;
            }
        }
        
        SdrSetIopData();
        
        SdrSendReq(1);
        
        for (i = 0; i < 6; i++) 
        {
            req_se_info[i] = 0;
        }
        
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT;
}

// 100% matching! 
SDE_ERR	sdSysSetSlotMax(const Sint32 midi_slot_max, const Sint32 shot_slot_max, const Sint32 pstm_slot_max)
{
    int i;

	if (__sg_sd_snd_init__ != 0) 
    {
        __shot_value = shot_slot_max;
        __pstm_value = pstm_slot_max;
        __midi_value = 10;

        if ((pstm_slot_max + (shot_slot_max + 10)) > 40) 
        {
            return SDE_ERR_PRM_OVER_RANGE;
        }

        __midi_handle_top = (SDMIDI)&__snd_handle__[0];
        __shot_handle_top = (SDSHOT)&__snd_handle__[10];
        __pstm_handle_top = (SDPSTM)&__snd_handle__[shot_slot_max + 10];

        for (i = 0; i < __midi_value; i++)
        {
            __midi_handle_top[i] = (SDHANDLE)&__snd_work__[i];
        }

        for (i = 0; i < __shot_value; i++) 
        {
            __shot_handle_top[i] = (SDHANDLE)&__snd_work__[__midi_value + i];
        }

        for (i = 0; i < __pstm_value; i++) 
        {
            __pstm_handle_top[i] = (SDHANDLE)&__snd_work__[__midi_value + __shot_value + i];
        }

        return SDE_ERR_NOTHING;
    }

    return SDE_ERR_NO_INIT;
}

// 100% matching! 
SDE_ERR	sdMemBlkSetTransferMode( SDE_MEMBLK_TRANSFER_MODE transfer_mode)
{
    return (__sg_sd_snd_init__ != 0) ? SDE_ERR_NOTHING : SDE_ERR_NO_INIT;
}

// 88.73% matching
SDE_ERR	sdMultiUnitDownload( SDMEMBLK handle)
{
    char* UnitAddress;
    
    if (__sg_sd_snd_init__ != 0)
    {
        SE_BANK[0] = 0;
        SE_BANK[1] = 4;
        SE_BANK[2] = 5;
        SE_BANK[3] = 6;
        SE_BANK[4] = 7;
        
        MIDI_BANK[1] = 1;
        MIDI_BANK[2] = 2;
        MIDI_BANK[3] = 3;
        
        UnitAddress = (char*)handle->m_Member[1];
        
        sdBankDownload(handle, SDE_DATA_TYPE_SHOT_BANK, 0); 

        /* ERROR: enabling this loop makes PCSX2 stuck, see ps2_snddrv.c for more information
        do 
        {
            sndr_trans_func();
            
            SdrSendReq(0);
        } while (snd_data_down_load != 0); */
        
        handle->m_Member[1] = (int)(UnitAddress + ((int*)UnitAddress)[4]);
        handle->m_Member[2] = ((int*)UnitAddress)[5];
        
        sdBankDownload(handle, SDE_DATA_TYPE_MIDI_SEQ_BANK, 1); 
        
        do
        {
            sndr_trans_func();
            
            SdrSendReq(0);
        } while (snd_data_down_load != 0);
        
        return SDE_ERR_NOTHING;
    }
    
    return SDE_ERR_NO_INIT;
}

// 100% matching! 
SDE_ERR	sdSysFinish( Void)
{
    return (__sg_sd_snd_init__ != 0) ? SDE_ERR_NOTHING : SDE_ERR_NO_INIT;
}

// 98.68% matching
unsigned int CpSifDmaTransEEToIOP(unsigned int src, unsigned int dst, unsigned int size, unsigned int mode, unsigned int flag) 
{
    int cueNo;
    static sceSifDmaData transDmaEEToIOP;

    cueNo = 0;

    if (size > 1048560) 
    {
        return 0;
    }
    
    switch (flag) 
    {
    case 0:
        while (TRUE)
        {
            transDmaEEToIOP.data = src;
            transDmaEEToIOP.addr = dst;
            
            transDmaEEToIOP.size = size;
            
            transDmaEEToIOP.mode = mode;
            
            FlushCache(0);
            
            cueNo = sceSifSetDma(&transDmaEEToIOP, 1);
            
            if (cueNo != 0) 
            {
                break;
            }
            
            CpEEWait(10000);
        }
        
        break;
    case 1:
        while (TRUE) 
        {
            transDmaEEToIOP.data = src;
            transDmaEEToIOP.addr = dst;
            
            transDmaEEToIOP.size = size;
            
            transDmaEEToIOP.mode = mode;
            
            FlushCache(0);
            
            cueNo = isceSifSetDma(&transDmaEEToIOP, 1);
            
            if (cueNo != 0)
            {
                break;
            }
            
            CpEEWait(10000);
        }
        
        break;
    default:
        return 0;
    }

    if (cueNo == 0)
    {
        return 0;
    }

    return cueNo;
}

// 100% matching!
void CpEEWait(int val)
{
    while (val-- > 0) 
    {
        asm("nop");
        asm("nop");
        asm("nop");
        asm("nop");
    }
}
