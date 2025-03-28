/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;


typedef unsigned char type_0[8];
typedef char type_1[32];
typedef char type_2[64];
typedef <unknown fundamental type (0xa510)> type_3[16];
typedef unsigned char type_4[32];
typedef unsigned char type_5[32];
typedef unsigned int type_6[2];
typedef _anon5 type_7[5];
typedef unsigned char type_8[2];
typedef char type_9[16];
typedef char type_10[16];
typedef <unknown fundamental type (0xa510)> type_11[16];
typedef _anon3 type_12[0];
typedef unsigned int type_13[3];
typedef unsigned short type_14[2];
typedef unsigned char type_15[2];

struct _anon0
{
	unsigned short on;
	unsigned short old;
	unsigned short push;
	unsigned short release;
	short send;
	unsigned short ad_flag;
	unsigned char buff[2];
	unsigned short onon;
	unsigned short repeat;
	char time1[16];
	char time2[16];
	unsigned char rh;
	unsigned char rv;
	unsigned char lh;
	unsigned char lv;
	unsigned char au;
	unsigned char ad;
	unsigned char al;
	unsigned char ar;
	unsigned char abu;
	unsigned char abd;
	unsigned char abl;
	unsigned char abr;
	unsigned char al1;
	unsigned char al2;
	unsigned char ar1;
	unsigned char ar2;
};

struct _anon1
{
	unsigned int id;
	unsigned int support;
	unsigned int on;
	unsigned int off;
	unsigned int press;
	unsigned int release;
	unsigned short r;
	unsigned short l;
	short x1;
	short y1;
	short x2;
	short y2;
	char* name;
	void* extend;
	unsigned int old;
	_anon2* info;
};

struct _anon2
{
	unsigned int type;
	unsigned int reserved[3];
	unsigned char is_root;
	unsigned char area_code;
	unsigned char connector_dir[2];
	char product_name[32];
	char license[64];
	unsigned short stdby_pow;
	unsigned short max_pow;
};

struct _anon3
{
	int PerType;
	int OldPerType;
	int PerTypeEx;
	unsigned int Flag;
	int SoftReset;
	unsigned int on;
	unsigned int press;
	unsigned int Rept;
	unsigned int on2;
	unsigned int on2old;
	unsigned int press2;
	unsigned short l;
	unsigned short r;
	short x1;
	short y1;
	short x2;
	short y2;
	short Calibrate;
};

struct _anon4
{
	_anon0 pad1;
	_anon0 pad2;
};

struct _anon5
{
	int Type;
	unsigned int Button;
};

struct _anon6
{
	unsigned short routine_0;
	unsigned short type;
	unsigned short act_lv[2];
	unsigned short be_flag;
	unsigned char act_data[8];
};*/

unsigned int Old_sys_cnt;
static u_long128 Padd1[scePadDmaBufferMax];
static u_long128 Padd2[scePadDmaBufferMax];
/*_anon5 ButtonInfo[5];*/
NO_NAME_19 Pad_status;
unsigned int Ps2_sys_cnt;
PAD_WRK Ps2_pad;
unsigned char Pad_rdata2[32];
unsigned char Pad_rdata1[32];
unsigned char ChkCnt;
unsigned char PadCnt;
PDS_PERIPHERALINFO pgp_info;
/*unsigned int Pad_state[2];
int SoftResetFlag;*/
PAD_INFO Pad[4];
/*int CurrentPortId;
_anon4 Pad_info;
_anon6 Pad_status2;

void pdInitPeripheral();
void pdExitPeripheral();
_anon1* pdGetPeripheral(unsigned int port);
_anon2* pdGetPeripheralInfo();
void pdSetMode();*/
void Ps2_pad_read();
void Ps2_Read_Key(PDS_PERIPHERAL* per, PAD_WORK* pad_wk);
/*void Ps2_MakeRepeatKey(unsigned int Id, _anon0* pad_wk);
void Pad_set(_anon0* pbt, unsigned short pad_num);
void Pad_init();*/

// 100% matching!
void pdInitPeripheral(Sint32 logic, void* recvbuf, void* sendbuf)
{
    Pad_status.routine_0 = 0;
    
    Pad_status.be_flag = 0;
    
    Pad_status.type = 0;
    
    Pad_status.act_data[0] = 0;
    Pad_status.act_data[1] = 1;
    Pad_status.act_data[2] = 255;
    Pad_status.act_data[3] = 255;
    Pad_status.act_data[4] = 255;
    Pad_status.act_data[5] = 255;
}

// 100% matching!
void pdExitPeripheral(void)
{ 
    int ret1;
    int ret2;

    ret1 = scePadPortClose(0, 0);
    
    if (ret1 != 1) 
    {
        return; 
    }

    ret2 = scePadPortClose(1, 0);
    
    if (ret2 != 1)
    {
        return;
    }
} 

// 97.66% matching
const PDS_PERIPHERAL* pdGetPeripheral(Uint32 port)
{
    static PDS_PERIPHERALINFO pp_info;
    static PDS_PERIPHERAL pp;
    PAD_WORK *pad_wk; 
    unsigned char *pad_data; 
    int temp; // not from the debugging symbols

    pad_wk = &Ps2_pad.pad1;
    
    pad_data = Pad_rdata1;
    
    if (port == 1) 
    {
        pad_data = Pad_rdata2;
        
        pad_wk = &Ps2_pad.pad2;
    }
    
    if (Ps2_sys_cnt != Old_sys_cnt) 
    {
        Ps2_pad_read();
        
        temp = 55541;
        
        pp.id = pad_data[1] / 16;
        
        pp.support = temp;
        
        pp.on = pad_wk->on;
        pp.off = ~pad_wk->on;
        
        pp.press = pad_wk->push;
        pp.release = pad_wk->release;
        
        pp.l = pad_data[16];
        pp.r = pad_data[17];
        
        pp.x1 = pad_data[6] - 128;
        pp.y1 = pad_data[7] - 128;
        
        pp_info.type = 1;
          
        pp.x2 = 0;
        pp.y2 = 0;
        
        pp.name = NULL;
        
        pp.old = 0;
        
        pp.info = &pp_info;

        Old_sys_cnt = Ps2_sys_cnt;
        
        pp_info.connector_dir[0] = 0;
        pp_info.connector_dir[1] = 0;
        
        Ps2_Read_Key(&pp, pad_wk);
        
        return &pp;
    }
    
    return &pp;
}

// 100% matching! 
const PDS_PERIPHERALINFO* pdGetPeripheralInfo(Uint32 port)
{
    pgp_info.type = 1;
    
    if (scePadGetState(0, 0) != 6) 
    {
        if (ChkCnt >= 3)
        {
            pgp_info.type = 0;
        } 
        else
        {
            ChkCnt++;
        }
        
        PadCnt = 3;
    } 
    else if (PadCnt != 0) 
    {
        PadCnt--;
        
        pgp_info.type = 0;
    }
    else if (scePadInfoMode(0, 0, 1, 0) != 7) 
    {
        pgp_info.type = 0;
    }
    else if (scePadInfoPressMode(0, 0) != 0) 
    {
        ChkCnt = 0;
    } 
    else 
    {
        pgp_info.type = 0;
    }
    
    return &pgp_info;
}

// 100% matching!
void pdSetMode(Sint32 mode)
{

}

// 
// Start address: 0x2d9f80
void Ps2_pad_read()
{
	//_anon4* pad;
	unsigned int info;
	// Line 220, Address: 0x2d9f80, Func Offset: 0
	// Line 222, Address: 0x2d9f90, Func Offset: 0x10
	// Line 223, Address: 0x2d9f98, Func Offset: 0x18
	// Line 225, Address: 0x2d9fac, Func Offset: 0x2c
	// Line 226, Address: 0x2d9fcc, Func Offset: 0x4c
	// Line 227, Address: 0x2d9fe0, Func Offset: 0x60
	// Line 228, Address: 0x2da004, Func Offset: 0x84
	// Line 229, Address: 0x2da00c, Func Offset: 0x8c
	// Line 231, Address: 0x2da014, Func Offset: 0x94
	// Line 232, Address: 0x2da028, Func Offset: 0xa8
	// Line 233, Address: 0x2da030, Func Offset: 0xb0
	// Line 235, Address: 0x2da060, Func Offset: 0xe0
	// Line 256, Address: 0x2da074, Func Offset: 0xf4
	// Line 257, Address: 0x2da08c, Func Offset: 0x10c
	// Line 258, Address: 0x2da098, Func Offset: 0x118
	// Line 265, Address: 0x2da0a8, Func Offset: 0x128
	// Line 268, Address: 0x2da0b0, Func Offset: 0x130
	// Line 270, Address: 0x2da0c4, Func Offset: 0x144
	// Line 271, Address: 0x2da0d0, Func Offset: 0x150
	// Line 274, Address: 0x2da0e4, Func Offset: 0x164
	// Line 275, Address: 0x2da0ec, Func Offset: 0x16c
	// Line 278, Address: 0x2da0f4, Func Offset: 0x174
	// Line 279, Address: 0x2da114, Func Offset: 0x194
	// Line 281, Address: 0x2da11c, Func Offset: 0x19c
	// Line 284, Address: 0x2da124, Func Offset: 0x1a4
	// Line 286, Address: 0x2da14c, Func Offset: 0x1cc
	// Line 287, Address: 0x2da154, Func Offset: 0x1d4
	// Line 290, Address: 0x2da15c, Func Offset: 0x1dc
	// Line 291, Address: 0x2da168, Func Offset: 0x1e8
	// Line 297, Address: 0x2da178, Func Offset: 0x1f8
	// Line 300, Address: 0x2da180, Func Offset: 0x200
	// Line 301, Address: 0x2da19c, Func Offset: 0x21c
	// Line 303, Address: 0x2da1a4, Func Offset: 0x224
	// Line 306, Address: 0x2da1ac, Func Offset: 0x22c
	// Line 308, Address: 0x2da1d4, Func Offset: 0x254
	// Line 309, Address: 0x2da1dc, Func Offset: 0x25c
	// Line 312, Address: 0x2da1e4, Func Offset: 0x264
	// Line 313, Address: 0x2da1f0, Func Offset: 0x270
	// Line 319, Address: 0x2da200, Func Offset: 0x280
	// Line 322, Address: 0x2da208, Func Offset: 0x288
	// Line 323, Address: 0x2da228, Func Offset: 0x2a8
	// Line 325, Address: 0x2da23c, Func Offset: 0x2bc
	// Line 326, Address: 0x2da244, Func Offset: 0x2c4
	// Line 329, Address: 0x2da24c, Func Offset: 0x2cc
	// Line 330, Address: 0x2da260, Func Offset: 0x2e0
	// Line 331, Address: 0x2da274, Func Offset: 0x2f4
	// Line 332, Address: 0x2da27c, Func Offset: 0x2fc
	// Line 331, Address: 0x2da280, Func Offset: 0x300
	// Line 332, Address: 0x2da28c, Func Offset: 0x30c
	// Line 340, Address: 0x2da290, Func Offset: 0x310
	// Line 343, Address: 0x2da298, Func Offset: 0x318
	// Line 345, Address: 0x2da2c0, Func Offset: 0x340
	// Line 346, Address: 0x2da2c8, Func Offset: 0x348
	// Line 349, Address: 0x2da2d0, Func Offset: 0x350
	// Line 355, Address: 0x2da2d8, Func Offset: 0x358
	// Line 358, Address: 0x2da2e0, Func Offset: 0x360
	// Line 359, Address: 0x2da2e8, Func Offset: 0x368
	// Line 358, Address: 0x2da2ec, Func Offset: 0x36c
	// Line 359, Address: 0x2da2f0, Func Offset: 0x370
	// Line 361, Address: 0x2da308, Func Offset: 0x388
	// Line 364, Address: 0x2da310, Func Offset: 0x390
	// Line 366, Address: 0x2da31c, Func Offset: 0x39c
	// Line 368, Address: 0x2da324, Func Offset: 0x3a4
	// Line 369, Address: 0x2da32c, Func Offset: 0x3ac
	// Line 371, Address: 0x2da334, Func Offset: 0x3b4
	// Line 370, Address: 0x2da338, Func Offset: 0x3b8
	// Line 371, Address: 0x2da33c, Func Offset: 0x3bc
	// Line 370, Address: 0x2da340, Func Offset: 0x3c0
	// Line 371, Address: 0x2da344, Func Offset: 0x3c4
	// Line 372, Address: 0x2da34c, Func Offset: 0x3cc
	// Line 373, Address: 0x2da35c, Func Offset: 0x3dc
	// Line 376, Address: 0x2da364, Func Offset: 0x3e4
	// Line 377, Address: 0x2da374, Func Offset: 0x3f4
	// Line 380, Address: 0x2da388, Func Offset: 0x408
	// Line 381, Address: 0x2da39c, Func Offset: 0x41c
	// Line 384, Address: 0x2da3b0, Func Offset: 0x430
	// Line 385, Address: 0x2da3bc, Func Offset: 0x43c
	// Line 387, Address: 0x2da3c4, Func Offset: 0x444
	// Line 384, Address: 0x2da3c8, Func Offset: 0x448
	// Line 385, Address: 0x2da3d0, Func Offset: 0x450
	// Line 387, Address: 0x2da3d4, Func Offset: 0x454
	// Line 385, Address: 0x2da3d8, Func Offset: 0x458
	// Line 387, Address: 0x2da3dc, Func Offset: 0x45c
	// Line 516, Address: 0x2da3e4, Func Offset: 0x464
	// Line 518, Address: 0x2da3ec, Func Offset: 0x46c
	// Func End, Address: 0x2da400, Func Offset: 0x480
	scePrintf("Ps2_pad_read - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2da400
void Ps2_Read_Key(PDS_PERIPHERAL* per, PAD_WORK* pad_wk)
{
	//_anon3* pp;
	unsigned int j;
	unsigned int i;
	// Line 527, Address: 0x2da400, Func Offset: 0
	// Line 532, Address: 0x2da414, Func Offset: 0x14
	// Line 527, Address: 0x2da418, Func Offset: 0x18
	// Line 532, Address: 0x2da41c, Func Offset: 0x1c
	// Line 533, Address: 0x2da42c, Func Offset: 0x2c
	// Line 535, Address: 0x2da434, Func Offset: 0x34
	// Line 537, Address: 0x2da444, Func Offset: 0x44
	// Line 538, Address: 0x2da44c, Func Offset: 0x4c
	// Line 539, Address: 0x2da458, Func Offset: 0x58
	// Line 540, Address: 0x2da45c, Func Offset: 0x5c
	// Line 541, Address: 0x2da464, Func Offset: 0x64
	// Line 542, Address: 0x2da470, Func Offset: 0x70
	// Line 543, Address: 0x2da474, Func Offset: 0x74
	// Line 544, Address: 0x2da47c, Func Offset: 0x7c
	// Line 545, Address: 0x2da484, Func Offset: 0x84
	// Line 546, Address: 0x2da4a0, Func Offset: 0xa0
	// Line 547, Address: 0x2da4a8, Func Offset: 0xa8
	// Line 548, Address: 0x2da4b8, Func Offset: 0xb8
	// Line 549, Address: 0x2da4cc, Func Offset: 0xcc
	// Line 551, Address: 0x2da4d8, Func Offset: 0xd8
	// Line 555, Address: 0x2da4ec, Func Offset: 0xec
	// Line 560, Address: 0x2da4f0, Func Offset: 0xf0
	// Line 562, Address: 0x2da500, Func Offset: 0x100
	// Line 563, Address: 0x2da504, Func Offset: 0x104
	// Line 564, Address: 0x2da50c, Func Offset: 0x10c
	// Line 565, Address: 0x2da514, Func Offset: 0x114
	// Line 566, Address: 0x2da51c, Func Offset: 0x11c
	// Line 567, Address: 0x2da524, Func Offset: 0x124
	// Line 568, Address: 0x2da52c, Func Offset: 0x12c
	// Line 569, Address: 0x2da534, Func Offset: 0x134
	// Line 570, Address: 0x2da53c, Func Offset: 0x13c
	// Line 589, Address: 0x2da544, Func Offset: 0x144
	// Line 590, Address: 0x2da550, Func Offset: 0x150
	// Line 612, Address: 0x2da554, Func Offset: 0x154
	// Line 590, Address: 0x2da558, Func Offset: 0x158
	// Line 591, Address: 0x2da55c, Func Offset: 0x15c
	// Line 612, Address: 0x2da560, Func Offset: 0x160
	// Line 613, Address: 0x2da578, Func Offset: 0x178
	// Line 614, Address: 0x2da584, Func Offset: 0x184
	// Line 616, Address: 0x2da588, Func Offset: 0x188
	// Line 617, Address: 0x2da5a0, Func Offset: 0x1a0
	// Line 618, Address: 0x2da5ac, Func Offset: 0x1ac
	// Line 620, Address: 0x2da5b0, Func Offset: 0x1b0
	// Line 621, Address: 0x2da5cc, Func Offset: 0x1cc
	// Line 624, Address: 0x2da5d8, Func Offset: 0x1d8
	// Line 625, Address: 0x2da5f0, Func Offset: 0x1f0
	// Line 626, Address: 0x2da5fc, Func Offset: 0x1fc
	// Line 631, Address: 0x2da600, Func Offset: 0x200
	// Line 632, Address: 0x2da614, Func Offset: 0x214
	// Line 633, Address: 0x2da624, Func Offset: 0x224
	// Line 634, Address: 0x2da640, Func Offset: 0x240
	// Line 635, Address: 0x2da64c, Func Offset: 0x24c
	// Line 636, Address: 0x2da650, Func Offset: 0x250
	// Line 637, Address: 0x2da66c, Func Offset: 0x26c
	// Line 639, Address: 0x2da678, Func Offset: 0x278
	// Line 640, Address: 0x2da688, Func Offset: 0x288
	// Line 641, Address: 0x2da6a4, Func Offset: 0x2a4
	// Line 643, Address: 0x2da6b0, Func Offset: 0x2b0
	// Line 644, Address: 0x2da6cc, Func Offset: 0x2cc
	// Line 660, Address: 0x2da6d4, Func Offset: 0x2d4
	// Line 661, Address: 0x2da6dc, Func Offset: 0x2dc
	// Line 662, Address: 0x2da6e0, Func Offset: 0x2e0
	// Line 663, Address: 0x2da6e4, Func Offset: 0x2e4
	// Line 664, Address: 0x2da6e8, Func Offset: 0x2e8
	// Line 665, Address: 0x2da6ec, Func Offset: 0x2ec
	// Line 666, Address: 0x2da6f0, Func Offset: 0x2f0
	// Line 667, Address: 0x2da6f4, Func Offset: 0x2f4
	// Line 668, Address: 0x2da6f8, Func Offset: 0x2f8
	// Line 669, Address: 0x2da6fc, Func Offset: 0x2fc
	// Line 675, Address: 0x2da700, Func Offset: 0x300
	// Line 678, Address: 0x2da70c, Func Offset: 0x30c
	// Line 681, Address: 0x2da71c, Func Offset: 0x31c
	// Line 682, Address: 0x2da748, Func Offset: 0x348
	// Line 696, Address: 0x2da754, Func Offset: 0x354
	// Func End, Address: 0x2da770, Func Offset: 0x370
	scePrintf("Ps2_Read_Key - UNIMPLEMENTED!\n");
}

// 100% matching!
void Ps2_MakeRepeatKey(unsigned int Id, PAD_WORK* pad_wk)
{
    Pad[Id].Rept = pad_wk->onon;
}

/*// 
// Start address: 0x2da7a0
void Pad_set(_anon0* pbt, unsigned short pad_num)
{
	unsigned char* pad_data;
	short i;
	// Line 875, Address: 0x2da7a0, Func Offset: 0
	// Line 712, Address: 0x2da7a4, Func Offset: 0x4
	// Line 875, Address: 0x2da7a8, Func Offset: 0x8
	// Line 876, Address: 0x2da7b4, Func Offset: 0x14
	// Line 879, Address: 0x2da7bc, Func Offset: 0x1c
	// Line 880, Address: 0x2da7c4, Func Offset: 0x24
	// Line 883, Address: 0x2da7d8, Func Offset: 0x38
	// Line 884, Address: 0x2da7e8, Func Offset: 0x48
	// Line 885, Address: 0x2da7f4, Func Offset: 0x54
	// Line 886, Address: 0x2da804, Func Offset: 0x64
	// Line 887, Address: 0x2da810, Func Offset: 0x70
	// Line 888, Address: 0x2da820, Func Offset: 0x80
	// Line 889, Address: 0x2da82c, Func Offset: 0x8c
	// Line 890, Address: 0x2da83c, Func Offset: 0x9c
	// Line 893, Address: 0x2da848, Func Offset: 0xa8
	// Line 913, Address: 0x2da850, Func Offset: 0xb0
	// Line 893, Address: 0x2da85c, Func Offset: 0xbc
	// Line 894, Address: 0x2da868, Func Offset: 0xc8
	// Line 895, Address: 0x2da87c, Func Offset: 0xdc
	// Line 896, Address: 0x2da884, Func Offset: 0xe4
	// Line 897, Address: 0x2da88c, Func Offset: 0xec
	// Line 898, Address: 0x2da894, Func Offset: 0xf4
	// Line 900, Address: 0x2da89c, Func Offset: 0xfc
	// Line 901, Address: 0x2da8a4, Func Offset: 0x104
	// Line 902, Address: 0x2da8ac, Func Offset: 0x10c
	// Line 903, Address: 0x2da8b4, Func Offset: 0x114
	// Line 904, Address: 0x2da8bc, Func Offset: 0x11c
	// Line 905, Address: 0x2da8c4, Func Offset: 0x124
	// Line 906, Address: 0x2da8cc, Func Offset: 0x12c
	// Line 907, Address: 0x2da8d4, Func Offset: 0x134
	// Line 908, Address: 0x2da8dc, Func Offset: 0x13c
	// Line 909, Address: 0x2da8e4, Func Offset: 0x144
	// Line 910, Address: 0x2da8ec, Func Offset: 0x14c
	// Line 911, Address: 0x2da8f4, Func Offset: 0x154
	// Line 926, Address: 0x2da8fc, Func Offset: 0x15c
	// Line 916, Address: 0x2da900, Func Offset: 0x160
	// Line 919, Address: 0x2da904, Func Offset: 0x164
	// Line 932, Address: 0x2da908, Func Offset: 0x168
	// Line 934, Address: 0x2da90c, Func Offset: 0x16c
	// Line 915, Address: 0x2da910, Func Offset: 0x170
	// Line 916, Address: 0x2da934, Func Offset: 0x194
	// Line 917, Address: 0x2da938, Func Offset: 0x198
	// Line 916, Address: 0x2da93c, Func Offset: 0x19c
	// Line 917, Address: 0x2da940, Func Offset: 0x1a0
	// Line 919, Address: 0x2da950, Func Offset: 0x1b0
	// Line 920, Address: 0x2da954, Func Offset: 0x1b4
	// Line 921, Address: 0x2da95c, Func Offset: 0x1bc
	// Line 922, Address: 0x2da970, Func Offset: 0x1d0
	// Line 923, Address: 0x2da980, Func Offset: 0x1e0
	// Line 924, Address: 0x2da984, Func Offset: 0x1e4
	// Line 923, Address: 0x2da98c, Func Offset: 0x1ec
	// Line 924, Address: 0x2da994, Func Offset: 0x1f4
	// Line 925, Address: 0x2da99c, Func Offset: 0x1fc
	// Line 926, Address: 0x2da9a4, Func Offset: 0x204
	// Line 927, Address: 0x2da9a8, Func Offset: 0x208
	// Line 930, Address: 0x2da9b8, Func Offset: 0x218
	// Line 931, Address: 0x2da9c4, Func Offset: 0x224
	// Line 932, Address: 0x2da9c8, Func Offset: 0x228
	// Line 931, Address: 0x2da9d0, Func Offset: 0x230
	// Line 932, Address: 0x2da9d8, Func Offset: 0x238
	// Line 933, Address: 0x2da9e0, Func Offset: 0x240
	// Line 934, Address: 0x2da9e8, Func Offset: 0x248
	// Line 935, Address: 0x2da9ec, Func Offset: 0x24c
	// Line 937, Address: 0x2da9f8, Func Offset: 0x258
	// Line 938, Address: 0x2daa00, Func Offset: 0x260
	// Line 939, Address: 0x2daa10, Func Offset: 0x270
	// Line 938, Address: 0x2daa14, Func Offset: 0x274
	// Line 939, Address: 0x2daa1c, Func Offset: 0x27c
	// Line 941, Address: 0x2daa20, Func Offset: 0x280
	// Line 942, Address: 0x2daa2c, Func Offset: 0x28c
	// Line 944, Address: 0x2daa30, Func Offset: 0x290
	// Line 946, Address: 0x2daa44, Func Offset: 0x2a4
	// Func End, Address: 0x2daa4c, Func Offset: 0x2ac
}*/

// 100% matching! 
void Pad_init()
{
    while (scePadInit(0) == 0);
    
    scePadPortOpen(0, 0, Padd1);
    scePadPortOpen(1, 0, Padd2);
}
