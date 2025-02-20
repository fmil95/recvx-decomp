typedef struct SDS_PORT_REF;
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
};

char sound_flag;
int __sg_sd_snd_init__;
void(*__snd_set_end_func__)(void*);
void* __snd_end_func_arg__;
int snd_data_down_load;
unsigned int iop_packet_flag;
unsigned int trans_level;
unsigned int trans_type;
unsigned int trans_bank_num;
unsigned int iop_trans_bd_address;
unsigned int iop_trans_hd_address;
int iop_data_buff;
unsigned int ee_trans_bd_size;
unsigned int ee_trans_hd_size;
unsigned int iop_trans_offset;
unsigned int ee_trans_bd_address;
unsigned int ee_trans_hd_address;
int __shot_value;
_SND_STATUS get_iop_snddata;
SDS_PORT_REF* __midi_handle_top;
int __midi_value;
unsigned int iop_trans_sq_address;
unsigned int ee_trans_sq_size;
unsigned int ee_trans_sq_address;
int CurrentFxLevel;
int AddFxLevel;
char FxLevelTimer;
int RoomFxLevel;
int iRingBufNum;
int iop_read_buff;
int iop_zero_buff;
int iop_buff;
unsigned short req_se_info[6];
unsigned short use_se_info[6];
SDS_MEMBLK __snd_mem_blk__[20];
SDS_PORT_REF* __shot_handle_top;
short SE_BANK[5];
unsigned int ee_trans_cue;
short SE_HD_CHECK[5];
short MIDI_BANK[4];
short MIDI_HD_CHECK[4];
int __pstm_value;
SDS_PORT_REF* __pstm_handle_top;
_anon0 __snd_work__[40];
SDS_PORT_REF* __snd_handle__[40];
int AdxTInfoBack[10][4];
unsigned int old_trans_size;
unsigned int ee_trans_type;

SDE_ERR sdBankDownload(SDS_MEMBLK* handle, SDE_DATA_TYPE bank_type, char bank_num);
SDE_ERR sdDrvInit();
SDE_ERR sdGddaSetPan();
SDE_ERR sdLibInit();
SDE_ERR sdMemBlkCreate(SDS_MEMBLK** handle);
SDE_ERR sdMemBlkDestroy(SDS_MEMBLK* handle);
SDE_ERR sdMemBlkSetPrm(SDS_MEMBLK* handle, void* src_blk_ptr, int src_blk_sz, void(*callback_func)(void*), void* callback_first_arg);
SDE_ERR sdMidiClosePort(SDS_PORT_REF** handle);
SDE_ERR sdMidiGetStat(SDS_PORT_REF** handle, SDS_MIDI_STAT* midi_stat);
SDE_ERR sdMidiOpenPort(SDS_PORT_REF*** handle);
SDE_ERR sdMidiPlay(SDS_PORT_REF** handle, char bank_num, char data_num);
SDE_ERR sdMidiSetFxLev();
SDE_ERR sdMidiSetPan(SDS_PORT_REF** handle, char pan, int fade_time);
SDE_ERR sdMidiSetPitch(SDS_PORT_REF** handle, short pitch, int fade_time);
SDE_ERR sdMidiSetSpeed();
SDE_ERR sdMidiSetVol(SDS_PORT_REF** handle, char vol, int fade_time);
SDE_ERR sdMidiStop(SDS_PORT_REF** handle);
SDE_ERR sdShotClosePort(SDS_PORT_REF** handle);
SDE_ERR sdShotGetStat(SDS_PORT_REF** handle, SDS_SHOT_STAT* shot_stat);
SDE_ERR sdShotOpenPort(SDS_PORT_REF*** handle);
SDE_ERR sdShotPlay(SDS_PORT_REF** handle, char bank_num, char data_num, char priority);
SDE_ERR sdShotSetFxLev();
SDE_ERR sdShotSetPan(SDS_PORT_REF** handle, char pan, int fade_time);
unsigned char Panpot_Control(_anon0* set_snd_work);
SDE_ERR sdShotSetPitch(SDS_PORT_REF** handle, short pitch, int fade_time);
short Pitch_Control(_anon0* set_snd_work);
SDE_ERR sdShotSetVol(SDS_PORT_REF** handle, char vol, int fade_time);
unsigned char Volume_Control(_anon0* set_snd_work);
SDE_ERR sdShotStop(SDS_PORT_REF** handle);
SDE_ERR sdSndClearFxPrg();
SDE_ERR sdSndSetFxPrg();
SDE_ERR sdSndSetMasterVol(char vol);
SDE_ERR sdSndSetPanMode(SDE_PAN_MODE pan_mode);
SDE_ERR sdSndStopAll();
int sndr_trans_func();
SDE_ERR sdSysServer();
SDE_ERR sdSysSetSlotMax(int shot_slot_max, int pstm_slot_max);
SDE_ERR sdMemBlkSetTransferMode();
SDE_ERR sdMultiUnitDownload(SDS_MEMBLK* handle);
SDE_ERR sdSysFinish();
unsigned int CpSifDmaTransEEToIOP(unsigned int src, unsigned int dst, unsigned int size, unsigned int mode, unsigned int flag);
void CpEEWait(int val);

// 
// Start address: 0x2dae10
SDE_ERR sdBankDownload(SDS_MEMBLK* handle, SDE_DATA_TYPE bank_type, char bank_num)
{
	int i;
	_anon0* chk_snd_work;
	unsigned int* snd_data;
	// Line 438, Address: 0x2dae10, Func Offset: 0
	// Line 445, Address: 0x2dae30, Func Offset: 0x20
	// Line 453, Address: 0x2dae48, Func Offset: 0x38
	// Line 472, Address: 0x2dae98, Func Offset: 0x88
	// Line 475, Address: 0x2daea4, Func Offset: 0x94
	// Line 472, Address: 0x2daea8, Func Offset: 0x98
	// Line 475, Address: 0x2daeac, Func Offset: 0x9c
	// Line 476, Address: 0x2daeb4, Func Offset: 0xa4
	// Line 477, Address: 0x2daed0, Func Offset: 0xc0
	// Line 478, Address: 0x2daedc, Func Offset: 0xcc
	// Line 480, Address: 0x2daee4, Func Offset: 0xd4
	// Line 481, Address: 0x2daee8, Func Offset: 0xd8
	// Line 484, Address: 0x2daf04, Func Offset: 0xf4
	// Line 494, Address: 0x2daf0c, Func Offset: 0xfc
	// Line 492, Address: 0x2daf14, Func Offset: 0x104
	// Line 495, Address: 0x2daf18, Func Offset: 0x108
	// Line 492, Address: 0x2daf20, Func Offset: 0x110
	// Line 493, Address: 0x2daf28, Func Offset: 0x118
	// Line 494, Address: 0x2daf34, Func Offset: 0x124
	// Line 495, Address: 0x2daf3c, Func Offset: 0x12c
	// Line 496, Address: 0x2daf44, Func Offset: 0x134
	// Line 497, Address: 0x2daf4c, Func Offset: 0x13c
	// Line 505, Address: 0x2daf50, Func Offset: 0x140
	// Line 539, Address: 0x2daf58, Func Offset: 0x148
	// Line 542, Address: 0x2daf64, Func Offset: 0x154
	// Line 539, Address: 0x2daf68, Func Offset: 0x158
	// Line 542, Address: 0x2daf6c, Func Offset: 0x15c
	// Line 543, Address: 0x2daf74, Func Offset: 0x164
	// Line 544, Address: 0x2daf90, Func Offset: 0x180
	// Line 545, Address: 0x2daf9c, Func Offset: 0x18c
	// Line 547, Address: 0x2dafa4, Func Offset: 0x194
	// Line 548, Address: 0x2dafa8, Func Offset: 0x198
	// Line 551, Address: 0x2dafc4, Func Offset: 0x1b4
	// Line 561, Address: 0x2dafcc, Func Offset: 0x1bc
	// Line 567, Address: 0x2dafd0, Func Offset: 0x1c0
	// Line 569, Address: 0x2dafd8, Func Offset: 0x1c8
	// Line 562, Address: 0x2dafe0, Func Offset: 0x1d0
	// Line 563, Address: 0x2daff0, Func Offset: 0x1e0
	// Line 564, Address: 0x2db000, Func Offset: 0x1f0
	// Line 565, Address: 0x2db008, Func Offset: 0x1f8
	// Line 566, Address: 0x2db014, Func Offset: 0x204
	// Line 569, Address: 0x2db020, Func Offset: 0x210
	// Line 570, Address: 0x2db028, Func Offset: 0x218
	// Line 567, Address: 0x2db030, Func Offset: 0x220
	// Line 568, Address: 0x2db038, Func Offset: 0x228
	// Line 571, Address: 0x2db040, Func Offset: 0x230
	// Line 572, Address: 0x2db048, Func Offset: 0x238
	// Line 604, Address: 0x2db04c, Func Offset: 0x23c
	// Line 634, Address: 0x2db054, Func Offset: 0x244
	// Line 635, Address: 0x2db058, Func Offset: 0x248
	// Line 636, Address: 0x2db06c, Func Offset: 0x25c
	// Line 637, Address: 0x2db078, Func Offset: 0x268
	// Line 639, Address: 0x2db084, Func Offset: 0x274
	// Line 637, Address: 0x2db088, Func Offset: 0x278
	// Line 639, Address: 0x2db08c, Func Offset: 0x27c
	// Line 640, Address: 0x2db094, Func Offset: 0x284
	// Line 641, Address: 0x2db0c4, Func Offset: 0x2b4
	// Line 644, Address: 0x2db0cc, Func Offset: 0x2bc
	// Line 646, Address: 0x2db0ec, Func Offset: 0x2dc
	// Line 647, Address: 0x2db0f0, Func Offset: 0x2e0
	// Line 650, Address: 0x2db10c, Func Offset: 0x2fc
	// Line 660, Address: 0x2db114, Func Offset: 0x304
	// Line 665, Address: 0x2db118, Func Offset: 0x308
	// Line 667, Address: 0x2db120, Func Offset: 0x310
	// Line 660, Address: 0x2db128, Func Offset: 0x318
	// Line 661, Address: 0x2db134, Func Offset: 0x324
	// Line 662, Address: 0x2db144, Func Offset: 0x334
	// Line 663, Address: 0x2db14c, Func Offset: 0x33c
	// Line 664, Address: 0x2db158, Func Offset: 0x348
	// Line 667, Address: 0x2db164, Func Offset: 0x354
	// Line 668, Address: 0x2db16c, Func Offset: 0x35c
	// Line 665, Address: 0x2db174, Func Offset: 0x364
	// Line 666, Address: 0x2db17c, Func Offset: 0x36c
	// Line 669, Address: 0x2db184, Func Offset: 0x374
	// Line 670, Address: 0x2db18c, Func Offset: 0x37c
	// Line 724, Address: 0x2db194, Func Offset: 0x384
	// Line 727, Address: 0x2db1a0, Func Offset: 0x390
	// Line 735, Address: 0x2db1ac, Func Offset: 0x39c
	// Line 738, Address: 0x2db1b4, Func Offset: 0x3a4
	// Line 740, Address: 0x2db1bc, Func Offset: 0x3ac
	// Func End, Address: 0x2db1e0, Func Offset: 0x3d0
}

// 
// Start address: 0x2db1e0
SDE_ERR sdDrvInit()
{
	char* _0_buf;
	char trans_0_buff[2175];
	// Line 768, Address: 0x2db1e0, Func Offset: 0
	// Line 785, Address: 0x2db1e8, Func Offset: 0x8
	// Line 787, Address: 0x2db1f0, Func Offset: 0x10
	// Line 790, Address: 0x2db1f8, Func Offset: 0x18
	// Line 793, Address: 0x2db204, Func Offset: 0x24
	// Line 794, Address: 0x2db214, Func Offset: 0x34
	// Line 796, Address: 0x2db224, Func Offset: 0x44
	// Line 798, Address: 0x2db230, Func Offset: 0x50
	// Line 801, Address: 0x2db238, Func Offset: 0x58
	// Line 804, Address: 0x2db248, Func Offset: 0x68
	// Line 805, Address: 0x2db258, Func Offset: 0x78
	// Line 807, Address: 0x2db268, Func Offset: 0x88
	// Line 809, Address: 0x2db274, Func Offset: 0x94
	// Line 812, Address: 0x2db27c, Func Offset: 0x9c
	// Line 816, Address: 0x2db28c, Func Offset: 0xac
	// Line 817, Address: 0x2db298, Func Offset: 0xb8
	// Line 819, Address: 0x2db2a8, Func Offset: 0xc8
	// Line 825, Address: 0x2db2bc, Func Offset: 0xdc
	// Line 828, Address: 0x2db2c8, Func Offset: 0xe8
	// Line 829, Address: 0x2db2dc, Func Offset: 0xfc
	// Line 831, Address: 0x2db2ec, Func Offset: 0x10c
	// Line 833, Address: 0x2db2f8, Func Offset: 0x118
	// Line 836, Address: 0x2db300, Func Offset: 0x120
	// Line 840, Address: 0x2db31c, Func Offset: 0x13c
	// Line 841, Address: 0x2db334, Func Offset: 0x154
	// Line 844, Address: 0x2db34c, Func Offset: 0x16c
	// Line 845, Address: 0x2db354, Func Offset: 0x174
	// Line 846, Address: 0x2db35c, Func Offset: 0x17c
	// Line 847, Address: 0x2db364, Func Offset: 0x184
	// Line 850, Address: 0x2db368, Func Offset: 0x188
	// Line 851, Address: 0x2db384, Func Offset: 0x1a4
	// Line 857, Address: 0x2db3a0, Func Offset: 0x1c0
	// Line 858, Address: 0x2db3a4, Func Offset: 0x1c4
	// Func End, Address: 0x2db3b4, Func Offset: 0x1d4
}

// 
// Start address: 0x2db3c0
SDE_ERR sdGddaSetPan()
{
	// Line 883, Address: 0x2db3c0, Func Offset: 0
	// Line 885, Address: 0x2db3c8, Func Offset: 0x8
	// Line 886, Address: 0x2db3d8, Func Offset: 0x18
	// Line 887, Address: 0x2db3e4, Func Offset: 0x24
	// Line 890, Address: 0x2db3ec, Func Offset: 0x2c
	// Line 892, Address: 0x2db3f4, Func Offset: 0x34
	// Func End, Address: 0x2db400, Func Offset: 0x40
}

// 
// Start address: 0x2db400
SDE_ERR sdLibInit()
{
	int j;
	int i;
	// Line 920, Address: 0x2db400, Func Offset: 0
	// Line 922, Address: 0x2db414, Func Offset: 0x14
	// Line 923, Address: 0x2db418, Func Offset: 0x18
	// Line 925, Address: 0x2db420, Func Offset: 0x20
	// Line 924, Address: 0x2db424, Func Offset: 0x24
	// Line 925, Address: 0x2db428, Func Offset: 0x28
	// Line 924, Address: 0x2db42c, Func Offset: 0x2c
	// Line 925, Address: 0x2db430, Func Offset: 0x30
	// Line 926, Address: 0x2db43c, Func Offset: 0x3c
	// Line 927, Address: 0x2db45c, Func Offset: 0x5c
	// Line 930, Address: 0x2db460, Func Offset: 0x60
	// Line 928, Address: 0x2db464, Func Offset: 0x64
	// Line 929, Address: 0x2db468, Func Offset: 0x68
	// Line 930, Address: 0x2db46c, Func Offset: 0x6c
	// Line 929, Address: 0x2db470, Func Offset: 0x70
	// Line 930, Address: 0x2db474, Func Offset: 0x74
	// Line 933, Address: 0x2db47c, Func Offset: 0x7c
	// Func End, Address: 0x2db484, Func Offset: 0x84
}

// 
// Start address: 0x2db490
SDE_ERR sdMemBlkCreate(SDS_MEMBLK** handle)
{
	int i;
	// Line 958, Address: 0x2db490, Func Offset: 0
	// Line 959, Address: 0x2db4a8, Func Offset: 0x18
	// Line 962, Address: 0x2db4ac, Func Offset: 0x1c
	// Line 965, Address: 0x2db4b8, Func Offset: 0x28
	// Line 967, Address: 0x2db4c8, Func Offset: 0x38
	// Line 968, Address: 0x2db4d4, Func Offset: 0x44
	// Line 971, Address: 0x2db4e0, Func Offset: 0x50
	// Line 973, Address: 0x2db4f8, Func Offset: 0x68
	// Line 974, Address: 0x2db4fc, Func Offset: 0x6c
	// Line 977, Address: 0x2db504, Func Offset: 0x74
	// Line 979, Address: 0x2db50c, Func Offset: 0x7c
	// Func End, Address: 0x2db514, Func Offset: 0x84
}

// 
// Start address: 0x2db520
SDE_ERR sdMemBlkDestroy(SDS_MEMBLK* handle)
{
	int i;
	// Line 1005, Address: 0x2db520, Func Offset: 0
	// Line 1006, Address: 0x2db530, Func Offset: 0x10
	// Line 1007, Address: 0x2db538, Func Offset: 0x18
	// Line 1009, Address: 0x2db544, Func Offset: 0x24
	// Line 1011, Address: 0x2db548, Func Offset: 0x28
	// Line 1010, Address: 0x2db54c, Func Offset: 0x2c
	// Line 1011, Address: 0x2db550, Func Offset: 0x30
	// Line 1010, Address: 0x2db554, Func Offset: 0x34
	// Line 1011, Address: 0x2db558, Func Offset: 0x38
	// Line 1012, Address: 0x2db564, Func Offset: 0x44
	// Line 1015, Address: 0x2db56c, Func Offset: 0x4c
	// Line 1017, Address: 0x2db574, Func Offset: 0x54
	// Func End, Address: 0x2db57c, Func Offset: 0x5c
}

// 
// Start address: 0x2db580
SDE_ERR sdMemBlkSetPrm(SDS_MEMBLK* handle, void* src_blk_ptr, int src_blk_sz, void(*callback_func)(void*), void* callback_first_arg)
{
	// Line 1046, Address: 0x2db580, Func Offset: 0
	// Line 1048, Address: 0x2db590, Func Offset: 0x10
	// Line 1049, Address: 0x2db598, Func Offset: 0x18
	// Line 1051, Address: 0x2db5a4, Func Offset: 0x24
	// Line 1052, Address: 0x2db5a8, Func Offset: 0x28
	// Line 1054, Address: 0x2db5ac, Func Offset: 0x2c
	// Line 1055, Address: 0x2db5b4, Func Offset: 0x34
	// Line 1056, Address: 0x2db5bc, Func Offset: 0x3c
	// Line 1059, Address: 0x2db5c4, Func Offset: 0x44
	// Line 1061, Address: 0x2db5cc, Func Offset: 0x4c
	// Func End, Address: 0x2db5d4, Func Offset: 0x54
}

// 
// Start address: 0x2db5e0
SDE_ERR sdMidiClosePort(SDS_PORT_REF** handle)
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
}

// 
// Start address: 0x2db6a0
SDE_ERR sdMidiGetStat(SDS_PORT_REF** handle, SDS_MIDI_STAT* midi_stat)
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
}

// 
// Start address: 0x2db720
SDE_ERR sdMidiOpenPort(SDS_PORT_REF*** handle)
{
	_anon0* check_snd_work;
	int i;
	// Line 1194, Address: 0x2db720, Func Offset: 0
	// Line 1196, Address: 0x2db730, Func Offset: 0x10
	// Line 1197, Address: 0x2db738, Func Offset: 0x18
	// Line 1196, Address: 0x2db740, Func Offset: 0x20
	// Line 1197, Address: 0x2db744, Func Offset: 0x24
	// Line 1199, Address: 0x2db74c, Func Offset: 0x2c
	// Line 1202, Address: 0x2db758, Func Offset: 0x38
	// Line 1203, Address: 0x2db770, Func Offset: 0x50
	// Line 1204, Address: 0x2db778, Func Offset: 0x58
	// Line 1207, Address: 0x2db784, Func Offset: 0x64
	// Line 1208, Address: 0x2db78c, Func Offset: 0x6c
	// Line 1209, Address: 0x2db794, Func Offset: 0x74
	// Line 1210, Address: 0x2db79c, Func Offset: 0x7c
	// Line 1213, Address: 0x2db7a4, Func Offset: 0x84
	// Line 1212, Address: 0x2db7a8, Func Offset: 0x88
	// Line 1217, Address: 0x2db7ac, Func Offset: 0x8c
	// Line 1218, Address: 0x2db7b8, Func Offset: 0x98
	// Line 1220, Address: 0x2db7c4, Func Offset: 0xa4
	// Line 1222, Address: 0x2db7c8, Func Offset: 0xa8
	// Line 1226, Address: 0x2db7cc, Func Offset: 0xac
	// Line 1227, Address: 0x2db7d8, Func Offset: 0xb8
	// Line 1226, Address: 0x2db7dc, Func Offset: 0xbc
	// Line 1227, Address: 0x2db7e0, Func Offset: 0xc0
	// Line 1230, Address: 0x2db7e8, Func Offset: 0xc8
	// Line 1232, Address: 0x2db7f0, Func Offset: 0xd0
	// Func End, Address: 0x2db7f8, Func Offset: 0xd8
}

// 
// Start address: 0x2db800
SDE_ERR sdMidiPlay(SDS_PORT_REF** handle, char bank_num, char data_num)
{
	unsigned int ch_check;
	// Line 1259, Address: 0x2db800, Func Offset: 0
	// Line 1265, Address: 0x2db818, Func Offset: 0x18
	// Line 1267, Address: 0x2db82c, Func Offset: 0x2c
	// Line 1268, Address: 0x2db838, Func Offset: 0x38
	// Line 1305, Address: 0x2db844, Func Offset: 0x44
	// Line 1302, Address: 0x2db848, Func Offset: 0x48
	// Line 1305, Address: 0x2db84c, Func Offset: 0x4c
	// Line 1306, Address: 0x2db864, Func Offset: 0x64
	// Line 1309, Address: 0x2db86c, Func Offset: 0x6c
	// Line 1311, Address: 0x2db878, Func Offset: 0x78
	// Line 1312, Address: 0x2db880, Func Offset: 0x80
	// Line 1314, Address: 0x2db88c, Func Offset: 0x8c
	// Line 1315, Address: 0x2db894, Func Offset: 0x94
	// Line 1316, Address: 0x2db8a0, Func Offset: 0xa0
	// Line 1318, Address: 0x2db8a4, Func Offset: 0xa4
	// Line 1320, Address: 0x2db8a8, Func Offset: 0xa8
	// Line 1319, Address: 0x2db8ac, Func Offset: 0xac
	// Line 1320, Address: 0x2db8b0, Func Offset: 0xb0
	// Line 1324, Address: 0x2db8b8, Func Offset: 0xb8
	// Line 1332, Address: 0x2db8c0, Func Offset: 0xc0
	// Line 1338, Address: 0x2db8c8, Func Offset: 0xc8
	// Line 1340, Address: 0x2db8d0, Func Offset: 0xd0
	// Func End, Address: 0x2db8ec, Func Offset: 0xec
}

// 
// Start address: 0x2db8f0
SDE_ERR sdMidiSetFxLev()
{
	// Line 1371, Address: 0x2db8f0, Func Offset: 0
	// Line 1376, Address: 0x2db904, Func Offset: 0x14
	// Func End, Address: 0x2db90c, Func Offset: 0x1c
}

// 
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
}

// 
// Start address: 0x2db9b0
SDE_ERR sdMidiSetPitch(SDS_PORT_REF** handle, short pitch, int fade_time)
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
}

// 
// Start address: 0x2dbaf0
SDE_ERR sdMidiSetSpeed()
{
	// Line 1554, Address: 0x2dbaf0, Func Offset: 0
	// Line 1556, Address: 0x2dbaf8, Func Offset: 0x8
	// Line 1558, Address: 0x2dbb08, Func Offset: 0x18
	// Line 1560, Address: 0x2dbb14, Func Offset: 0x24
	// Line 1563, Address: 0x2dbb1c, Func Offset: 0x2c
	// Line 1565, Address: 0x2dbb24, Func Offset: 0x34
	// Func End, Address: 0x2dbb30, Func Offset: 0x40
}

// 
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
}

// 
// Start address: 0x2dbc30
SDE_ERR sdMidiStop(SDS_PORT_REF** handle)
{
	// Line 1695, Address: 0x2dbc30, Func Offset: 0
	// Line 1699, Address: 0x2dbc38, Func Offset: 0x8
	// Line 1701, Address: 0x2dbc48, Func Offset: 0x18
	// Line 1702, Address: 0x2dbc54, Func Offset: 0x24
	// Line 1708, Address: 0x2dbc60, Func Offset: 0x30
	// Line 1714, Address: 0x2dbc80, Func Offset: 0x50
	// Line 1716, Address: 0x2dbc88, Func Offset: 0x58
	// Func End, Address: 0x2dbc94, Func Offset: 0x64
}

// 
// Start address: 0x2dbca0
SDE_ERR sdShotClosePort(SDS_PORT_REF** handle)
{
	// Line 1738, Address: 0x2dbca0, Func Offset: 0
	// Line 1743, Address: 0x2dbcac, Func Offset: 0xc
	// Line 1745, Address: 0x2dbcbc, Func Offset: 0x1c
	// Line 1746, Address: 0x2dbcc8, Func Offset: 0x28
	// Line 1752, Address: 0x2dbcd4, Func Offset: 0x34
	// Line 1755, Address: 0x2dbd04, Func Offset: 0x64
	// Line 1763, Address: 0x2dbd24, Func Offset: 0x84
	// Line 1770, Address: 0x2dbd58, Func Offset: 0xb8
	// Line 1769, Address: 0x2dbd5c, Func Offset: 0xbc
	// Line 1770, Address: 0x2dbd60, Func Offset: 0xc0
	// Line 1771, Address: 0x2dbd64, Func Offset: 0xc4
	// Line 1772, Address: 0x2dbd6c, Func Offset: 0xcc
	// Line 1773, Address: 0x2dbd74, Func Offset: 0xd4
	// Line 1774, Address: 0x2dbd78, Func Offset: 0xd8
	// Line 1775, Address: 0x2dbd7c, Func Offset: 0xdc
	// Line 1776, Address: 0x2dbd80, Func Offset: 0xe0
	// Line 1777, Address: 0x2dbd84, Func Offset: 0xe4
	// Line 1778, Address: 0x2dbd88, Func Offset: 0xe8
	// Line 1780, Address: 0x2dbd8c, Func Offset: 0xec
	// Line 1779, Address: 0x2dbd90, Func Offset: 0xf0
	// Line 1780, Address: 0x2dbd94, Func Offset: 0xf4
	// Line 1782, Address: 0x2dbd98, Func Offset: 0xf8
	// Line 1781, Address: 0x2dbd9c, Func Offset: 0xfc
	// Line 1782, Address: 0x2dbda0, Func Offset: 0x100
	// Line 1783, Address: 0x2dbda4, Func Offset: 0x104
	// Line 1786, Address: 0x2dbdac, Func Offset: 0x10c
	// Line 1788, Address: 0x2dbdb4, Func Offset: 0x114
	// Func End, Address: 0x2dbdc4, Func Offset: 0x124
}

// 
// Start address: 0x2dbdd0
SDE_ERR sdShotGetStat(SDS_PORT_REF** handle, SDS_SHOT_STAT* shot_stat)
{
	// Line 1817, Address: 0x2dbdd0, Func Offset: 0
	// Line 1818, Address: 0x2dbde0, Func Offset: 0x10
	// Line 1819, Address: 0x2dbdec, Func Offset: 0x1c
	// Line 1825, Address: 0x2dbdf8, Func Offset: 0x28
	// Line 1826, Address: 0x2dbe28, Func Offset: 0x58
	// Line 1827, Address: 0x2dbe30, Func Offset: 0x60
	// Line 1829, Address: 0x2dbe38, Func Offset: 0x68
	// Line 1832, Address: 0x2dbe48, Func Offset: 0x78
	// Line 1835, Address: 0x2dbe50, Func Offset: 0x80
	// Line 1837, Address: 0x2dbe58, Func Offset: 0x88
	// Func End, Address: 0x2dbe60, Func Offset: 0x90
}

// 
// Start address: 0x2dbe60
SDE_ERR sdShotOpenPort(SDS_PORT_REF*** handle)
{
	_anon0* check_snd_work;
	int i;
	// Line 1864, Address: 0x2dbe60, Func Offset: 0
	// Line 1866, Address: 0x2dbe70, Func Offset: 0x10
	// Line 1867, Address: 0x2dbe78, Func Offset: 0x18
	// Line 1866, Address: 0x2dbe80, Func Offset: 0x20
	// Line 1867, Address: 0x2dbe84, Func Offset: 0x24
	// Line 1869, Address: 0x2dbe8c, Func Offset: 0x2c
	// Line 1872, Address: 0x2dbe98, Func Offset: 0x38
	// Line 1873, Address: 0x2dbeb0, Func Offset: 0x50
	// Line 1874, Address: 0x2dbeb8, Func Offset: 0x58
	// Line 1877, Address: 0x2dbec4, Func Offset: 0x64
	// Line 1878, Address: 0x2dbecc, Func Offset: 0x6c
	// Line 1879, Address: 0x2dbed4, Func Offset: 0x74
	// Line 1880, Address: 0x2dbedc, Func Offset: 0x7c
	// Line 1882, Address: 0x2dbee4, Func Offset: 0x84
	// Line 1881, Address: 0x2dbee8, Func Offset: 0x88
	// Line 1882, Address: 0x2dbeec, Func Offset: 0x8c
	// Line 1883, Address: 0x2dbef0, Func Offset: 0x90
	// Line 1885, Address: 0x2dbef8, Func Offset: 0x98
	// Line 1886, Address: 0x2dbf04, Func Offset: 0xa4
	// Line 1885, Address: 0x2dbf08, Func Offset: 0xa8
	// Line 1886, Address: 0x2dbf0c, Func Offset: 0xac
	// Line 1889, Address: 0x2dbf14, Func Offset: 0xb4
	// Line 1891, Address: 0x2dbf1c, Func Offset: 0xbc
	// Func End, Address: 0x2dbf24, Func Offset: 0xc4
}

// 
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
}

// 
// Start address: 0x2dc180
SDE_ERR sdShotSetFxLev()
{
	// Line 2126, Address: 0x2dc180, Func Offset: 0
	// Line 2131, Address: 0x2dc194, Func Offset: 0x14
	// Func End, Address: 0x2dc19c, Func Offset: 0x1c
}

// 
// Start address: 0x2dc1a0
SDE_ERR sdShotSetPan(SDS_PORT_REF** handle, char pan, int fade_time)
{
	char set_pan;
	// Line 2156, Address: 0x2dc1a0, Func Offset: 0
	// Line 2161, Address: 0x2dc1a8, Func Offset: 0x8
	// Line 2163, Address: 0x2dc1b8, Func Offset: 0x18
	// Line 2164, Address: 0x2dc1c4, Func Offset: 0x24
	// Line 2169, Address: 0x2dc1d0, Func Offset: 0x30
	// Line 2171, Address: 0x2dc1e4, Func Offset: 0x44
	// Line 2172, Address: 0x2dc1ec, Func Offset: 0x4c
	// Line 2173, Address: 0x2dc1f8, Func Offset: 0x58
	// Line 2174, Address: 0x2dc1fc, Func Offset: 0x5c
	// Line 2175, Address: 0x2dc204, Func Offset: 0x64
	// Line 2179, Address: 0x2dc208, Func Offset: 0x68
	// Line 2180, Address: 0x2dc210, Func Offset: 0x70
	// Line 2183, Address: 0x2dc218, Func Offset: 0x78
	// Line 2185, Address: 0x2dc21c, Func Offset: 0x7c
	// Line 2187, Address: 0x2dc220, Func Offset: 0x80
	// Line 2190, Address: 0x2dc22c, Func Offset: 0x8c
	// Line 2192, Address: 0x2dc234, Func Offset: 0x94
	// Func End, Address: 0x2dc240, Func Offset: 0xa0
}

// 
// Start address: 0x2dc240
unsigned char Panpot_Control(_anon0* set_snd_work)
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
}

// 
// Start address: 0x2dc420
SDE_ERR sdShotSetPitch(SDS_PORT_REF** handle, short pitch, int fade_time)
{
	unsigned short set_pitch;
	// Line 2248, Address: 0x2dc420, Func Offset: 0
	// Line 2253, Address: 0x2dc428, Func Offset: 0x8
	// Line 2255, Address: 0x2dc438, Func Offset: 0x18
	// Line 2256, Address: 0x2dc444, Func Offset: 0x24
	// Line 2265, Address: 0x2dc450, Func Offset: 0x30
	// Line 2281, Address: 0x2dc460, Func Offset: 0x40
	// Line 2283, Address: 0x2dc46c, Func Offset: 0x4c
	// Line 2285, Address: 0x2dc474, Func Offset: 0x54
	// Line 2286, Address: 0x2dc480, Func Offset: 0x60
	// Line 2293, Address: 0x2dc484, Func Offset: 0x64
	// Line 2294, Address: 0x2dc48c, Func Offset: 0x6c
	// Line 2295, Address: 0x2dc498, Func Offset: 0x78
	// Line 2296, Address: 0x2dc49c, Func Offset: 0x7c
	// Line 2297, Address: 0x2dc4a4, Func Offset: 0x84
	// Line 2301, Address: 0x2dc4a8, Func Offset: 0x88
	// Line 2302, Address: 0x2dc4b0, Func Offset: 0x90
	// Line 2305, Address: 0x2dc4b8, Func Offset: 0x98
	// Line 2307, Address: 0x2dc4bc, Func Offset: 0x9c
	// Line 2309, Address: 0x2dc4c0, Func Offset: 0xa0
	// Line 2312, Address: 0x2dc4cc, Func Offset: 0xac
	// Line 2314, Address: 0x2dc4d4, Func Offset: 0xb4
	// Func End, Address: 0x2dc4e0, Func Offset: 0xc0
}

// 
// Start address: 0x2dc4e0
short Pitch_Control(_anon0* set_snd_work)
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
}

// 
// Start address: 0x2dc680
SDE_ERR sdShotSetVol(SDS_PORT_REF** handle, char vol, int fade_time)
{
	// Line 2370, Address: 0x2dc680, Func Offset: 0
	// Line 2374, Address: 0x2dc688, Func Offset: 0x8
	// Line 2376, Address: 0x2dc698, Func Offset: 0x18
	// Line 2377, Address: 0x2dc6a4, Func Offset: 0x24
	// Line 2383, Address: 0x2dc6b0, Func Offset: 0x30
	// Line 2384, Address: 0x2dc6b8, Func Offset: 0x38
	// Line 2385, Address: 0x2dc6c4, Func Offset: 0x44
	// Line 2386, Address: 0x2dc6c8, Func Offset: 0x48
	// Line 2387, Address: 0x2dc6cc, Func Offset: 0x4c
	// Line 2411, Address: 0x2dc6d0, Func Offset: 0x50
	// Line 2387, Address: 0x2dc6d4, Func Offset: 0x54
	// Line 2411, Address: 0x2dc6d8, Func Offset: 0x58
	// Line 2416, Address: 0x2dc6dc, Func Offset: 0x5c
	// Line 2417, Address: 0x2dc6e4, Func Offset: 0x64
	// Line 2445, Address: 0x2dc6ec, Func Offset: 0x6c
	// Line 2420, Address: 0x2dc6f0, Func Offset: 0x70
	// Line 2445, Address: 0x2dc6f4, Func Offset: 0x74
	// Line 2449, Address: 0x2dc6f8, Func Offset: 0x78
	// Line 2452, Address: 0x2dc704, Func Offset: 0x84
	// Line 2454, Address: 0x2dc70c, Func Offset: 0x8c
	// Func End, Address: 0x2dc718, Func Offset: 0x98
}

// 
// Start address: 0x2dc720
unsigned char Volume_Control(_anon0* set_snd_work)
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
}

// 
// Start address: 0x2dc910
SDE_ERR sdShotStop(SDS_PORT_REF** handle)
{
	_anon0* set_snd_work;
	// Line 2507, Address: 0x2dc910, Func Offset: 0
	// Line 2512, Address: 0x2dc918, Func Offset: 0x8
	// Line 2513, Address: 0x2dc928, Func Offset: 0x18
	// Line 2517, Address: 0x2dc92c, Func Offset: 0x1c
	// Line 2523, Address: 0x2dc964, Func Offset: 0x54
	// Line 2525, Address: 0x2dc96c, Func Offset: 0x5c
	// Func End, Address: 0x2dc978, Func Offset: 0x68
}

// 
// Start address: 0x2dc980
SDE_ERR sdSndClearFxPrg()
{
	// Line 2552, Address: 0x2dc980, Func Offset: 0
	// Line 2557, Address: 0x2dc994, Func Offset: 0x14
	// Func End, Address: 0x2dc99c, Func Offset: 0x1c
}

// 
// Start address: 0x2dc9a0
SDE_ERR sdSndSetFxPrg()
{
	// Line 2585, Address: 0x2dc9a0, Func Offset: 0
	// Line 2590, Address: 0x2dc9b4, Func Offset: 0x14
	// Func End, Address: 0x2dc9bc, Func Offset: 0x1c
}

// 
// Start address: 0x2dc9c0
SDE_ERR sdSndSetMasterVol(char vol)
{
	// Line 2614, Address: 0x2dc9c0, Func Offset: 0
	// Line 2616, Address: 0x2dc9c8, Func Offset: 0x8
	// Line 2618, Address: 0x2dc9d8, Func Offset: 0x18
	// Line 2619, Address: 0x2dc9e0, Func Offset: 0x20
	// Line 2620, Address: 0x2dc9fc, Func Offset: 0x3c
	// Line 2624, Address: 0x2dca08, Func Offset: 0x48
	// Line 2633, Address: 0x2dca4c, Func Offset: 0x8c
	// Line 2641, Address: 0x2dca7c, Func Offset: 0xbc
	// Line 2643, Address: 0x2dca84, Func Offset: 0xc4
	// Func End, Address: 0x2dca90, Func Offset: 0xd0
}

// 
// Start address: 0x2dca90
SDE_ERR sdSndSetPanMode(SDE_PAN_MODE pan_mode)
{
	int ret;
	// Line 2668, Address: 0x2dca90, Func Offset: 0
	// Line 2671, Address: 0x2dca9c, Func Offset: 0xc
	// Line 2674, Address: 0x2dcaac, Func Offset: 0x1c
	// Line 2675, Address: 0x2dcab8, Func Offset: 0x28
	// Line 2676, Address: 0x2dcac0, Func Offset: 0x30
	// Line 2680, Address: 0x2dcacc, Func Offset: 0x3c
	// Line 2683, Address: 0x2dcad4, Func Offset: 0x44
	// Line 2685, Address: 0x2dcad8, Func Offset: 0x48
	// Line 2687, Address: 0x2dcae0, Func Offset: 0x50
	// Line 2688, Address: 0x2dcae8, Func Offset: 0x58
	// Line 2689, Address: 0x2dcaf4, Func Offset: 0x64
	// Line 2693, Address: 0x2dcafc, Func Offset: 0x6c
	// Line 2696, Address: 0x2dcb04, Func Offset: 0x74
	// Line 2698, Address: 0x2dcb0c, Func Offset: 0x7c
	// Line 2700, Address: 0x2dcb14, Func Offset: 0x84
	// Line 2702, Address: 0x2dcb20, Func Offset: 0x90
	// Line 2703, Address: 0x2dcb28, Func Offset: 0x98
	// Line 2706, Address: 0x2dcb30, Func Offset: 0xa0
	// Line 2710, Address: 0x2dcb3c, Func Offset: 0xac
	// Line 2712, Address: 0x2dcb44, Func Offset: 0xb4
	// Func End, Address: 0x2dcb54, Func Offset: 0xc4
}

// 
// Start address: 0x2dcb60
SDE_ERR sdSndStopAll()
{
	// Line 2734, Address: 0x2dcb60, Func Offset: 0
	// Line 2736, Address: 0x2dcb68, Func Offset: 0x8
	// Line 2738, Address: 0x2dcb78, Func Offset: 0x18
	// Line 2745, Address: 0x2dcb98, Func Offset: 0x38
	// Line 2747, Address: 0x2dcba0, Func Offset: 0x40
	// Func End, Address: 0x2dcbac, Func Offset: 0x4c
}

// 
// Start address: 0x2dcbb0
int sndr_trans_func()
{
	int i;
	int i;
	int current_trans_size;
	// Line 2879, Address: 0x2dcbb0, Func Offset: 0
	// Line 2881, Address: 0x2dcbbc, Func Offset: 0xc
	// Line 2883, Address: 0x2dcbf8, Func Offset: 0x48
	// Line 2887, Address: 0x2dcc1c, Func Offset: 0x6c
	// Line 2888, Address: 0x2dcc4c, Func Offset: 0x9c
	// Line 2889, Address: 0x2dcc54, Func Offset: 0xa4
	// Line 2892, Address: 0x2dcc5c, Func Offset: 0xac
	// Line 2893, Address: 0x2dcc64, Func Offset: 0xb4
	// Line 2894, Address: 0x2dcc7c, Func Offset: 0xcc
	// Line 2895, Address: 0x2dcc90, Func Offset: 0xe0
	// Line 2896, Address: 0x2dcc98, Func Offset: 0xe8
	// Line 2897, Address: 0x2dcca8, Func Offset: 0xf8
	// Line 2898, Address: 0x2dccb4, Func Offset: 0x104
	// Line 2901, Address: 0x2dccc0, Func Offset: 0x110
	// Line 2904, Address: 0x2dccc4, Func Offset: 0x114
	// Line 2906, Address: 0x2dcccc, Func Offset: 0x11c
	// Line 2911, Address: 0x2dccfc, Func Offset: 0x14c
	// Line 2913, Address: 0x2dcd18, Func Offset: 0x168
	// Line 2914, Address: 0x2dcd30, Func Offset: 0x180
	// Line 2915, Address: 0x2dcd38, Func Offset: 0x188
	// Line 2914, Address: 0x2dcd3c, Func Offset: 0x18c
	// Line 2915, Address: 0x2dcd48, Func Offset: 0x198
	// Line 2919, Address: 0x2dcd54, Func Offset: 0x1a4
	// Line 2921, Address: 0x2dcd58, Func Offset: 0x1a8
	// Line 2922, Address: 0x2dcd88, Func Offset: 0x1d8
	// Line 2923, Address: 0x2dcd90, Func Offset: 0x1e0
	// Line 2926, Address: 0x2dcd98, Func Offset: 0x1e8
	// Line 2927, Address: 0x2dcda0, Func Offset: 0x1f0
	// Line 2928, Address: 0x2dcdb4, Func Offset: 0x204
	// Line 2929, Address: 0x2dcdc8, Func Offset: 0x218
	// Line 2930, Address: 0x2dcdd0, Func Offset: 0x220
	// Line 2931, Address: 0x2dcdd8, Func Offset: 0x228
	// Line 2935, Address: 0x2dcde0, Func Offset: 0x230
	// Line 2936, Address: 0x2dcde8, Func Offset: 0x238
	// Line 2937, Address: 0x2dcdf0, Func Offset: 0x240
	// Line 2939, Address: 0x2dce14, Func Offset: 0x264
	// Line 2943, Address: 0x2dce44, Func Offset: 0x294
	// Line 2944, Address: 0x2dce74, Func Offset: 0x2c4
	// Line 2945, Address: 0x2dce7c, Func Offset: 0x2cc
	// Line 2948, Address: 0x2dce84, Func Offset: 0x2d4
	// Line 2949, Address: 0x2dce9c, Func Offset: 0x2ec
	// Line 2957, Address: 0x2dcea0, Func Offset: 0x2f0
	// Line 2961, Address: 0x2dcecc, Func Offset: 0x31c
	// Line 2962, Address: 0x2dcee4, Func Offset: 0x334
	// Line 2963, Address: 0x2dceec, Func Offset: 0x33c
	// Line 2965, Address: 0x2dcef4, Func Offset: 0x344
	// Line 2967, Address: 0x2dcefc, Func Offset: 0x34c
	// Line 2970, Address: 0x2dcf04, Func Offset: 0x354
	// Line 2971, Address: 0x2dcf0c, Func Offset: 0x35c
	// Line 2973, Address: 0x2dcf24, Func Offset: 0x374
	// Line 2974, Address: 0x2dcf58, Func Offset: 0x3a8
	// Line 2976, Address: 0x2dcf60, Func Offset: 0x3b0
	// Line 2978, Address: 0x2dcf68, Func Offset: 0x3b8
	// Line 2976, Address: 0x2dcf70, Func Offset: 0x3c0
	// Line 2979, Address: 0x2dcf74, Func Offset: 0x3c4
	// Line 2978, Address: 0x2dcf7c, Func Offset: 0x3cc
	// Line 2980, Address: 0x2dcf84, Func Offset: 0x3d4
	// Line 2979, Address: 0x2dcf8c, Func Offset: 0x3dc
	// Line 2976, Address: 0x2dcf94, Func Offset: 0x3e4
	// Line 2978, Address: 0x2dcf9c, Func Offset: 0x3ec
	// Line 2982, Address: 0x2dcfa4, Func Offset: 0x3f4
	// Line 2980, Address: 0x2dcfac, Func Offset: 0x3fc
	// Line 2979, Address: 0x2dcfb4, Func Offset: 0x404
	// Line 2980, Address: 0x2dcfbc, Func Offset: 0x40c
	// Line 2982, Address: 0x2dcfc4, Func Offset: 0x414
	// Line 2983, Address: 0x2dcfd4, Func Offset: 0x424
	// Line 2989, Address: 0x2dcfd8, Func Offset: 0x428
	// Line 2992, Address: 0x2dcfe8, Func Offset: 0x438
	// Line 2993, Address: 0x2dd020, Func Offset: 0x470
	// Line 2997, Address: 0x2dd028, Func Offset: 0x478
	// Line 2998, Address: 0x2dd054, Func Offset: 0x4a4
	// Line 3001, Address: 0x2dd058, Func Offset: 0x4a8
	// Line 3002, Address: 0x2dd070, Func Offset: 0x4c0
	// Line 3003, Address: 0x2dd078, Func Offset: 0x4c8
	// Line 3005, Address: 0x2dd080, Func Offset: 0x4d0
	// Line 3007, Address: 0x2dd088, Func Offset: 0x4d8
	// Line 3010, Address: 0x2dd090, Func Offset: 0x4e0
	// Line 3011, Address: 0x2dd098, Func Offset: 0x4e8
	// Line 3012, Address: 0x2dd0ac, Func Offset: 0x4fc
	// Line 3013, Address: 0x2dd0e4, Func Offset: 0x534
	// Line 3014, Address: 0x2dd0ec, Func Offset: 0x53c
	// Line 3015, Address: 0x2dd0f4, Func Offset: 0x544
	// Line 3017, Address: 0x2dd0fc, Func Offset: 0x54c
	// Line 3018, Address: 0x2dd108, Func Offset: 0x558
	// Line 3019, Address: 0x2dd110, Func Offset: 0x560
	// Line 3020, Address: 0x2dd120, Func Offset: 0x570
	// Line 3021, Address: 0x2dd12c, Func Offset: 0x57c
	// Line 3024, Address: 0x2dd138, Func Offset: 0x588
	// Line 3027, Address: 0x2dd13c, Func Offset: 0x58c
	// Line 3029, Address: 0x2dd144, Func Offset: 0x594
	// Line 3034, Address: 0x2dd174, Func Offset: 0x5c4
	// Line 3036, Address: 0x2dd190, Func Offset: 0x5e0
	// Line 3037, Address: 0x2dd1a8, Func Offset: 0x5f8
	// Line 3038, Address: 0x2dd1b0, Func Offset: 0x600
	// Line 3037, Address: 0x2dd1b4, Func Offset: 0x604
	// Line 3038, Address: 0x2dd1c0, Func Offset: 0x610
	// Line 3041, Address: 0x2dd1cc, Func Offset: 0x61c
	// Line 3043, Address: 0x2dd1d0, Func Offset: 0x620
	// Line 3044, Address: 0x2dd200, Func Offset: 0x650
	// Line 3045, Address: 0x2dd208, Func Offset: 0x658
	// Line 3048, Address: 0x2dd210, Func Offset: 0x660
	// Line 3049, Address: 0x2dd218, Func Offset: 0x668
	// Line 3050, Address: 0x2dd22c, Func Offset: 0x67c
	// Line 3051, Address: 0x2dd240, Func Offset: 0x690
	// Line 3052, Address: 0x2dd248, Func Offset: 0x698
	// Line 3053, Address: 0x2dd250, Func Offset: 0x6a0
	// Line 3057, Address: 0x2dd258, Func Offset: 0x6a8
	// Line 3058, Address: 0x2dd260, Func Offset: 0x6b0
	// Line 3059, Address: 0x2dd268, Func Offset: 0x6b8
	// Line 3061, Address: 0x2dd28c, Func Offset: 0x6dc
	// Line 3065, Address: 0x2dd2bc, Func Offset: 0x70c
	// Line 3066, Address: 0x2dd2ec, Func Offset: 0x73c
	// Line 3067, Address: 0x2dd2f4, Func Offset: 0x744
	// Line 3070, Address: 0x2dd2fc, Func Offset: 0x74c
	// Line 3071, Address: 0x2dd314, Func Offset: 0x764
	// Line 3079, Address: 0x2dd318, Func Offset: 0x768
	// Line 3083, Address: 0x2dd344, Func Offset: 0x794
	// Line 3084, Address: 0x2dd35c, Func Offset: 0x7ac
	// Line 3085, Address: 0x2dd364, Func Offset: 0x7b4
	// Line 3087, Address: 0x2dd36c, Func Offset: 0x7bc
	// Line 3089, Address: 0x2dd374, Func Offset: 0x7c4
	// Line 3092, Address: 0x2dd37c, Func Offset: 0x7cc
	// Line 3093, Address: 0x2dd384, Func Offset: 0x7d4
	// Line 3095, Address: 0x2dd39c, Func Offset: 0x7ec
	// Line 3096, Address: 0x2dd3d0, Func Offset: 0x820
	// Line 3098, Address: 0x2dd3d8, Func Offset: 0x828
	// Line 3100, Address: 0x2dd3e0, Func Offset: 0x830
	// Line 3098, Address: 0x2dd3e8, Func Offset: 0x838
	// Line 3101, Address: 0x2dd3ec, Func Offset: 0x83c
	// Line 3100, Address: 0x2dd3f4, Func Offset: 0x844
	// Line 3102, Address: 0x2dd3fc, Func Offset: 0x84c
	// Line 3101, Address: 0x2dd404, Func Offset: 0x854
	// Line 3098, Address: 0x2dd40c, Func Offset: 0x85c
	// Line 3100, Address: 0x2dd414, Func Offset: 0x864
	// Line 3104, Address: 0x2dd41c, Func Offset: 0x86c
	// Line 3102, Address: 0x2dd424, Func Offset: 0x874
	// Line 3101, Address: 0x2dd42c, Func Offset: 0x87c
	// Line 3102, Address: 0x2dd434, Func Offset: 0x884
	// Line 3104, Address: 0x2dd43c, Func Offset: 0x88c
	// Line 3105, Address: 0x2dd44c, Func Offset: 0x89c
	// Line 3111, Address: 0x2dd450, Func Offset: 0x8a0
	// Line 3114, Address: 0x2dd460, Func Offset: 0x8b0
	// Line 3115, Address: 0x2dd498, Func Offset: 0x8e8
	// Line 3119, Address: 0x2dd4a0, Func Offset: 0x8f0
	// Line 3120, Address: 0x2dd4cc, Func Offset: 0x91c
	// Line 3123, Address: 0x2dd4d0, Func Offset: 0x920
	// Line 3124, Address: 0x2dd4e8, Func Offset: 0x938
	// Line 3125, Address: 0x2dd4f0, Func Offset: 0x940
	// Line 3127, Address: 0x2dd4f8, Func Offset: 0x948
	// Line 3129, Address: 0x2dd500, Func Offset: 0x950
	// Line 3132, Address: 0x2dd508, Func Offset: 0x958
	// Line 3133, Address: 0x2dd510, Func Offset: 0x960
	// Line 3135, Address: 0x2dd524, Func Offset: 0x974
	// Line 3136, Address: 0x2dd55c, Func Offset: 0x9ac
	// Line 3137, Address: 0x2dd564, Func Offset: 0x9b4
	// Line 3138, Address: 0x2dd56c, Func Offset: 0x9bc
	// Line 3140, Address: 0x2dd574, Func Offset: 0x9c4
	// Line 3141, Address: 0x2dd580, Func Offset: 0x9d0
	// Line 3142, Address: 0x2dd588, Func Offset: 0x9d8
	// Line 3143, Address: 0x2dd598, Func Offset: 0x9e8
	// Line 3144, Address: 0x2dd5a4, Func Offset: 0x9f4
	// Line 3147, Address: 0x2dd5b0, Func Offset: 0xa00
	// Line 3152, Address: 0x2dd5b8, Func Offset: 0xa08
	// Func End, Address: 0x2dd5c8, Func Offset: 0xa18
}

// 
// Start address: 0x2dd5d0
SDE_ERR sdSysServer()
{
	unsigned int req;
	short pitch;
	unsigned char pan;
	unsigned char vol;
	_anon0* chk_snd_work;
	int i;
	// Line 3651, Address: 0x2dd5d0, Func Offset: 0
	// Line 3665, Address: 0x2dd5e8, Func Offset: 0x18
	// Line 3667, Address: 0x2dd5f8, Func Offset: 0x28
	// Line 3682, Address: 0x2dd608, Func Offset: 0x38
	// Line 3704, Address: 0x2dd610, Func Offset: 0x40
	// Line 3729, Address: 0x2dd618, Func Offset: 0x48
	// Line 3730, Address: 0x2dd628, Func Offset: 0x58
	// Line 3731, Address: 0x2dd634, Func Offset: 0x64
	// Line 3732, Address: 0x2dd644, Func Offset: 0x74
	// Line 3733, Address: 0x2dd650, Func Offset: 0x80
	// Line 3735, Address: 0x2dd658, Func Offset: 0x88
	// Line 3737, Address: 0x2dd674, Func Offset: 0xa4
	// Line 3738, Address: 0x2dd690, Func Offset: 0xc0
	// Line 3741, Address: 0x2dd6ac, Func Offset: 0xdc
	// Line 3742, Address: 0x2dd6b8, Func Offset: 0xe8
	// Line 3746, Address: 0x2dd6c0, Func Offset: 0xf0
	// Line 3751, Address: 0x2dd6d0, Func Offset: 0x100
	// Line 3752, Address: 0x2dd6fc, Func Offset: 0x12c
	// Line 3753, Address: 0x2dd720, Func Offset: 0x150
	// Line 3752, Address: 0x2dd724, Func Offset: 0x154
	// Line 3754, Address: 0x2dd72c, Func Offset: 0x15c
	// Line 3755, Address: 0x2dd734, Func Offset: 0x164
	// Line 3761, Address: 0x2dd760, Func Offset: 0x190
	// Line 3769, Address: 0x2dd788, Func Offset: 0x1b8
	// Line 3777, Address: 0x2dd7b0, Func Offset: 0x1e0
	// Line 3782, Address: 0x2dd7d4, Func Offset: 0x204
	// Line 3777, Address: 0x2dd7dc, Func Offset: 0x20c
	// Line 3788, Address: 0x2dd7e0, Func Offset: 0x210
	// Line 3782, Address: 0x2dd7e4, Func Offset: 0x214
	// Line 3788, Address: 0x2dd7e8, Func Offset: 0x218
	// Line 3782, Address: 0x2dd7ec, Func Offset: 0x21c
	// Line 3777, Address: 0x2dd7f8, Func Offset: 0x228
	// Line 3788, Address: 0x2dd7fc, Func Offset: 0x22c
	// Line 3789, Address: 0x2dd804, Func Offset: 0x234
	// Line 3793, Address: 0x2dd808, Func Offset: 0x238
	// Line 3795, Address: 0x2dd81c, Func Offset: 0x24c
	// Line 3796, Address: 0x2dd820, Func Offset: 0x250
	// Line 3798, Address: 0x2dd828, Func Offset: 0x258
	// Line 3799, Address: 0x2dd834, Func Offset: 0x264
	// Line 3800, Address: 0x2dd848, Func Offset: 0x278
	// Line 3803, Address: 0x2dd850, Func Offset: 0x280
	// Line 3808, Address: 0x2dd86c, Func Offset: 0x29c
	// Line 3809, Address: 0x2dd878, Func Offset: 0x2a8
	// Line 3813, Address: 0x2dd880, Func Offset: 0x2b0
	// Line 3814, Address: 0x2dd890, Func Offset: 0x2c0
	// Line 3818, Address: 0x2dd8a4, Func Offset: 0x2d4
	// Line 3820, Address: 0x2dd8b4, Func Offset: 0x2e4
	// Line 3818, Address: 0x2dd8b8, Func Offset: 0x2e8
	// Line 3820, Address: 0x2dd8c8, Func Offset: 0x2f8
	// Line 3821, Address: 0x2dd8cc, Func Offset: 0x2fc
	// Line 3826, Address: 0x2dd8d0, Func Offset: 0x300
	// Line 3829, Address: 0x2dd8f0, Func Offset: 0x320
	// Line 3830, Address: 0x2dd8fc, Func Offset: 0x32c
	// Line 3831, Address: 0x2dd904, Func Offset: 0x334
	// Line 3834, Address: 0x2dd908, Func Offset: 0x338
	// Line 3835, Address: 0x2dd914, Func Offset: 0x344
	// Line 3836, Address: 0x2dd91c, Func Offset: 0x34c
	// Line 3839, Address: 0x2dd920, Func Offset: 0x350
	// Line 3840, Address: 0x2dd92c, Func Offset: 0x35c
	// Line 3841, Address: 0x2dd934, Func Offset: 0x364
	// Line 3843, Address: 0x2dd938, Func Offset: 0x368
	// Line 3844, Address: 0x2dd94c, Func Offset: 0x37c
	// Line 3845, Address: 0x2dd950, Func Offset: 0x380
	// Line 3846, Address: 0x2dd958, Func Offset: 0x388
	// Line 3850, Address: 0x2dd968, Func Offset: 0x398
	// Line 3852, Address: 0x2dd96c, Func Offset: 0x39c
	// Line 3850, Address: 0x2dd970, Func Offset: 0x3a0
	// Line 3852, Address: 0x2dd980, Func Offset: 0x3b0
	// Line 3853, Address: 0x2dd984, Func Offset: 0x3b4
	// Line 3854, Address: 0x2dd988, Func Offset: 0x3b8
	// Line 3856, Address: 0x2dd9a4, Func Offset: 0x3d4
	// Line 3857, Address: 0x2dd9ac, Func Offset: 0x3dc
	// Line 3863, Address: 0x2dd9bc, Func Offset: 0x3ec
	// Line 3865, Address: 0x2dd9c0, Func Offset: 0x3f0
	// Line 3864, Address: 0x2dd9c4, Func Offset: 0x3f4
	// Line 3865, Address: 0x2dd9c8, Func Offset: 0x3f8
	// Line 3864, Address: 0x2dd9cc, Func Offset: 0x3fc
	// Line 3865, Address: 0x2dd9d0, Func Offset: 0x400
	// Line 4005, Address: 0x2dd9dc, Func Offset: 0x40c
	// Line 4008, Address: 0x2dd9e4, Func Offset: 0x414
	// Line 4011, Address: 0x2dd9ec, Func Offset: 0x41c
	// Func End, Address: 0x2dda08, Func Offset: 0x438
}

// 
// Start address: 0x2dda10
SDE_ERR sdSysSetSlotMax(int shot_slot_max, int pstm_slot_max)
{
	int i;
	// Line 4043, Address: 0x2dda10, Func Offset: 0
	// Line 4052, Address: 0x2dda20, Func Offset: 0x10
	// Line 4053, Address: 0x2dda28, Func Offset: 0x18
	// Line 4056, Address: 0x2dda2c, Func Offset: 0x1c
	// Line 4053, Address: 0x2dda30, Func Offset: 0x20
	// Line 4051, Address: 0x2dda34, Func Offset: 0x24
	// Line 4056, Address: 0x2dda3c, Func Offset: 0x2c
	// Line 4051, Address: 0x2dda40, Func Offset: 0x30
	// Line 4056, Address: 0x2dda44, Func Offset: 0x34
	// Line 4057, Address: 0x2dda50, Func Offset: 0x40
	// Line 4061, Address: 0x2dda5c, Func Offset: 0x4c
	// Line 4062, Address: 0x2dda6c, Func Offset: 0x5c
	// Line 4063, Address: 0x2dda7c, Func Offset: 0x6c
	// Line 4065, Address: 0x2dda9c, Func Offset: 0x8c
	// Line 4066, Address: 0x2ddaa8, Func Offset: 0x98
	// Line 4067, Address: 0x2ddab0, Func Offset: 0xa0
	// Line 4066, Address: 0x2ddab4, Func Offset: 0xa4
	// Line 4067, Address: 0x2ddac4, Func Offset: 0xb4
	// Line 4068, Address: 0x2ddadc, Func Offset: 0xcc
	// Line 4069, Address: 0x2ddaf0, Func Offset: 0xe0
	// Line 4070, Address: 0x2ddb24, Func Offset: 0x114
	// Line 4069, Address: 0x2ddb28, Func Offset: 0x118
	// Line 4070, Address: 0x2ddb2c, Func Offset: 0x11c
	// Line 4071, Address: 0x2ddb44, Func Offset: 0x134
	// Line 4072, Address: 0x2ddb58, Func Offset: 0x148
	// Line 4073, Address: 0x2ddb98, Func Offset: 0x188
	// Line 4072, Address: 0x2ddb9c, Func Offset: 0x18c
	// Line 4073, Address: 0x2ddba0, Func Offset: 0x190
	// Line 4074, Address: 0x2ddbb4, Func Offset: 0x1a4
	// Line 4078, Address: 0x2ddbbc, Func Offset: 0x1ac
	// Line 4080, Address: 0x2ddbc4, Func Offset: 0x1b4
	// Func End, Address: 0x2ddbcc, Func Offset: 0x1bc
}

// 
// Start address: 0x2ddbd0
SDE_ERR sdMemBlkSetTransferMode()
{
	// Line 4105, Address: 0x2ddbd0, Func Offset: 0
	// Line 4110, Address: 0x2ddbe4, Func Offset: 0x14
	// Func End, Address: 0x2ddbec, Func Offset: 0x1c
}

// 
// Start address: 0x2ddbf0
SDE_ERR sdMultiUnitDownload(SDS_MEMBLK* handle)
{
	char* UnitAddress;
	// Line 4136, Address: 0x2ddbf0, Func Offset: 0
	// Line 4139, Address: 0x2ddc00, Func Offset: 0x10
	// Line 4140, Address: 0x2ddc10, Func Offset: 0x20
	// Line 4141, Address: 0x2ddc18, Func Offset: 0x28
	// Line 4142, Address: 0x2ddc24, Func Offset: 0x34
	// Line 4143, Address: 0x2ddc30, Func Offset: 0x40
	// Line 4144, Address: 0x2ddc3c, Func Offset: 0x4c
	// Line 4146, Address: 0x2ddc48, Func Offset: 0x58
	// Line 4147, Address: 0x2ddc54, Func Offset: 0x64
	// Line 4148, Address: 0x2ddc60, Func Offset: 0x70
	// Line 4153, Address: 0x2ddc6c, Func Offset: 0x7c
	// Line 4150, Address: 0x2ddc70, Func Offset: 0x80
	// Line 4153, Address: 0x2ddc74, Func Offset: 0x84
	// Line 4158, Address: 0x2ddc80, Func Offset: 0x90
	// Line 4159, Address: 0x2ddc88, Func Offset: 0x98
	// Line 4160, Address: 0x2ddc90, Func Offset: 0xa0
	// Line 4167, Address: 0x2ddca0, Func Offset: 0xb0
	// Line 4171, Address: 0x2ddca4, Func Offset: 0xb4
	// Line 4167, Address: 0x2ddcb4, Func Offset: 0xc4
	// Line 4168, Address: 0x2ddcbc, Func Offset: 0xcc
	// Line 4171, Address: 0x2ddcc0, Func Offset: 0xd0
	// Line 4176, Address: 0x2ddcc8, Func Offset: 0xd8
	// Line 4177, Address: 0x2ddcd0, Func Offset: 0xe0
	// Line 4178, Address: 0x2ddcd8, Func Offset: 0xe8
	// Line 4185, Address: 0x2ddce8, Func Offset: 0xf8
	// Line 4188, Address: 0x2ddcf0, Func Offset: 0x100
	// Line 4190, Address: 0x2ddcf8, Func Offset: 0x108
	// Func End, Address: 0x2ddd0c, Func Offset: 0x11c
}

// 
// Start address: 0x2ddd10
SDE_ERR sdSysFinish()
{
	// Line 4215, Address: 0x2ddd10, Func Offset: 0
	// Line 4220, Address: 0x2ddd24, Func Offset: 0x14
	// Func End, Address: 0x2ddd2c, Func Offset: 0x1c
}

// 
// Start address: 0x2ddd30
unsigned int CpSifDmaTransEEToIOP(unsigned int src, unsigned int dst, unsigned int size, unsigned int mode, unsigned int flag)
{
	int cueNo;
	_anon1 transDmaEEToIOP;
	// Line 4655, Address: 0x2ddd30, Func Offset: 0
	// Line 4659, Address: 0x2ddd44, Func Offset: 0x14
	// Line 4655, Address: 0x2ddd48, Func Offset: 0x18
	// Line 4659, Address: 0x2ddd50, Func Offset: 0x20
	// Line 4667, Address: 0x2ddd68, Func Offset: 0x38
	// Line 4670, Address: 0x2ddd70, Func Offset: 0x40
	// Line 4673, Address: 0x2ddd8c, Func Offset: 0x5c
	// Line 4674, Address: 0x2ddd94, Func Offset: 0x64
	// Line 4675, Address: 0x2ddd9c, Func Offset: 0x6c
	// Line 4676, Address: 0x2ddda4, Func Offset: 0x74
	// Line 4677, Address: 0x2ddda8, Func Offset: 0x78
	// Line 4678, Address: 0x2dddb4, Func Offset: 0x84
	// Line 4679, Address: 0x2dddc4, Func Offset: 0x94
	// Line 4680, Address: 0x2dddcc, Func Offset: 0x9c
	// Line 4681, Address: 0x2dddd4, Func Offset: 0xa4
	// Line 4689, Address: 0x2ddddc, Func Offset: 0xac
	// Line 4690, Address: 0x2ddde4, Func Offset: 0xb4
	// Line 4691, Address: 0x2dddec, Func Offset: 0xbc
	// Line 4692, Address: 0x2dddf4, Func Offset: 0xc4
	// Line 4693, Address: 0x2dddf8, Func Offset: 0xc8
	// Line 4694, Address: 0x2dde04, Func Offset: 0xd4
	// Line 4695, Address: 0x2dde14, Func Offset: 0xe4
	// Line 4696, Address: 0x2dde1c, Func Offset: 0xec
	// Line 4697, Address: 0x2dde24, Func Offset: 0xf4
	// Line 4710, Address: 0x2dde2c, Func Offset: 0xfc
	// Line 4714, Address: 0x2dde38, Func Offset: 0x108
	// Line 4721, Address: 0x2dde40, Func Offset: 0x110
	// Line 4732, Address: 0x2dde44, Func Offset: 0x114
	// Func End, Address: 0x2dde60, Func Offset: 0x130
}

// 
// Start address: 0x2dde60
void CpEEWait(int val)
{
	// Line 4739, Address: 0x2dde60, Func Offset: 0
	// Line 4740, Address: 0x2dde68, Func Offset: 0x8
	// Line 4741, Address: 0x2dde6c, Func Offset: 0xc
	// Line 4742, Address: 0x2dde70, Func Offset: 0x10
	// Line 4743, Address: 0x2dde74, Func Offset: 0x14
	// Line 4744, Address: 0x2dde78, Func Offset: 0x18
	// Line 4745, Address: 0x2dde84, Func Offset: 0x24
	// Func End, Address: 0x2dde8c, Func Offset: 0x2c
}

