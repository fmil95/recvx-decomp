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
BUTTON_INFO ButtonInfo[5] = 
{
    { 1, 55541},
    { 2, 55541},
    { 3, 55541},
    { 4, 55541},
    {-1, 0    }
}; 
NO_NAME_19 Pad_status;
unsigned int Ps2_sys_cnt;
PAD_WRK Ps2_pad;
unsigned char Pad_rdata2[32];
unsigned char Pad_rdata1[32];
unsigned char ChkCnt;
unsigned char PadCnt;
PDS_PERIPHERALINFO pgp_info;
unsigned int Pad_state[2];
int SoftResetFlag;
PAD_INFO Pad[4];
int CurrentPortId;
/*_anon4 Pad_info;
_anon6 Pad_status2;

void pdInitPeripheral();
void pdExitPeripheral();
_anon1* pdGetPeripheral(unsigned int port);
_anon2* pdGetPeripheralInfo();
void pdSetMode();*/
void Ps2_pad_read();
void Ps2_Read_Key(PDS_PERIPHERAL* per, PAD_WORK* pad_wk);
void Ps2_MakeRepeatKey(unsigned int Id, PAD_WORK* pad_wk);
void Pad_set(PAD_WORK* pbt, unsigned short pad_num);
/*void Pad_init();*/

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

// 99.87% matching
void Ps2_pad_read()
{
	unsigned int info; 
    PAD_WRK* pad; 
    int* temp; // not from the debugging symbols
    
    pad = &Ps2_pad;
    
    Pad_state[0] = scePadGetState(0, 0);
    
    if ((Pad_state[0] == 6) || (Pad_state[0] == 2))
    {
        if ((Pad_status.be_flag & 0x1))
        {
            info = Pad_status.type;
            
            if (info != scePadInfoMode(0, 0, 1, 0))
            {
                Pad_status.be_flag = 0;
                
                Pad_status.routine_0 = 0;
            }
            
            scePadRead(0, 0, Pad_rdata1);
        } 
        else 
        {
            switch (Pad_status.routine_0)
            {
            case 0:
                info = scePadInfoMode(0, 0, 1, 0);
                
                if ((info == 7) || (info == 4))
                {
                    Pad_status.routine_0 = 1;
                    
                    Pad_status.be_flag |= 0x2;
                }
                
                break;
            case 1:
                info = scePadInfoMode(0, 0, 2, 0);
                
                if (info == 2)
                {
                    Pad_status.be_flag |= 0x8;
                }
                
                Pad_status.routine_0 = 2;
                break;
            case 2:
                info = scePadSetMainMode(0, 0, 1, 3);
                
                if (info == 1)
                {
                    Pad_status.routine_0 = 3;
                }
                
                break;
            case 3:
                info = scePadGetReqState(0, 0);
                
                switch (info) 
                {
                case 1:
                    Pad_status.routine_0 = 2;
                    break;
                case 0:
                    Pad_status.routine_0 = 4;
                    
                    Pad_status.be_flag |= 0x10;
                    break;
                }
               
                break;
            case 4:
                info = scePadSetActAlign(0, 0, Pad_status.act_data);
                
                if (info != 0)
                {
                    Pad_status.routine_0 = 5;
                }
                
                break;
            case 5:
                info = scePadGetReqState(0, 0);
                
                switch (info) 
                {
                case 1:
                    Pad_status.routine_0 = 4;
                    break;
                case 0:
                    Pad_status.routine_0 = 6;
                    
                    Pad_status.be_flag |= 0x20;
                    break;
                }
            
                break;
            case 6:
                info = scePadInfoMode(0, 0, 1, 0);
                
                if (info == 7)
                {
                    Pad_status.be_flag |= 0x4;
                }
                
                Pad_status.routine_0 = 7;
                break;
            case 7:
                info = scePadInfoPressMode(0, 0);
                
                if (info != 0)
                {
                    info = scePadEnterPressMode(0, 0);
                    
                    if (info != 0) 
                    {
                        Pad_status.be_flag |= 0x4;
                    
                        Pad_status.routine_0 = 8;
                    }
                }
                
                break;
            case 8:
                info = scePadGetReqState(0, 0);
            
                switch (info) 
                {
                case 1:
                    Pad_status.routine_0 = 7;
                    break;
                case 0:
                    Pad_status.routine_0 = 9;
                    break;
                }
                
                break;
            case 9:
                Pad_status.be_flag |= 0x1;
                
                info = scePadInfoMode(0, 0, 1, 0);
                
                Pad_status.type = info;
                
                Pad_status.routine_0 = 0;
                break;
            }
            
            *(unsigned short*)(Pad_rdata1 + 2) = 65535;
        }
    }
    else if (Pad_state[0] == 0)
    {
        Pad_status.routine_0 = 0;
        
        Pad_status.be_flag = 0;
        
        *(unsigned short*)(Pad_rdata1 + 2) = 65535;
        
        *(int*)(Pad_rdata1 + 4) = 0x80808080;
    }
    else
    {
        *(unsigned short*)(Pad_rdata1 + 2) = 65535;
        
        *(int*)(Pad_rdata1 + 4) = 0x80808080;
    }
    
    if (!(Pad_status.be_flag & 0x4))
    {
        *(int*)(Pad_rdata1 + 4) = 0x80808080;
    }
    
    *(unsigned short*)(Pad_rdata1 + 2) ^= 65535;
    
    temp = (int*)(Pad_rdata1 + 4);
    
    *temp = ~*temp;
    
    Pad_set(&pad->pad1, 1);
    
    Ps2_pad_actuater();
}

// 100% matching!
void Ps2_Read_Key(PDS_PERIPHERAL* per, PAD_WORK* pad_wk)
{
    unsigned int i; 
    unsigned int j; 
    PAD_INFO* pp;   
    
    pp = Pad;
    
    for (i = 0; i < 4; i++) 
    {
        pp[i].OldPerType = pp[i].PerType;
        
        if (per->info->type == 0) 
        {
            pp[i].PerType = 0;
        } 
        else if ((per->info->type & 0x40)) 
        {
            pp[i].PerType = 6;
        } 
        else if ((per->info->type & 0x80))
        {
            pp[i].PerType = 5;
        } 
        else
        {
            pp[i].PerType = -1;
            
            if ((per->info->type & 0x1)) 
            { 
                for (j = 0; ButtonInfo[j].Button != 0; j++)
                {
                    if (ButtonInfo[j].Button == (ButtonInfo[j].Button & per->support)) 
                    {
                        pp[i].PerType = ButtonInfo[j].Type;
                        break;
                    }
                } 
            }
        }
        
        if (pp[i].PerType == 1) 
        {
            pp[i].PerTypeEx = 1;
            
            pp[i].on = per->on;
            
            pp[i].press = per->press;
            
            pp[i].l = per->l;
            pp[i].r = per->r;
            
            pp[i].x1 = per->x1;
            pp[i].y1 = per->y1;
            
            pp[i].x2 = per->x2;
            pp[i].y2 = per->y2;
            
            if (pp[i].Calibrate >= 0) 
            {
                pp[i].on2old = pp[i].on2;
                
                pp[i].on2 = 0;
                
                if (pp[i].x1 < (-64 - pp[i].Calibrate)) 
                {
                    pp[i].on2 |= 0x2000;
                }
                
                if (pp[i].x1 > (pp[i].Calibrate + 64)) 
                {
                    pp[i].on2 |= 0x8000;
                }
                
                if (pp[i].y1 < (-64 - pp[i].Calibrate)) 
                {
                    pp[i].on2 |= 0x4000;
                }
                
                if (pp[i].y1 < (pp[i].Calibrate + 64)) 
                {
                    pp[i].on2 |= 0x1000;
                }
                
                pp[i].press2 = ~pp[i].on2old & pp[i].on2;
                
                pp[i].on |= pp[i].on2;
                
                if (((pp[i].on & 0x1000)) && ((pp[i].on & 0x4000))) 
                {
                    pp[i].on &= ~0x4000;
                }
                
                if (((pp[i].on & 0x8000)) && ((pp[i].on & 0x2000))) 
                {
                    pp[i].on &= ~0x2000;
                }
                
                pp[i].press |= pp[i].press2;
                
                if (((pp[i].press & 0x1000)) && ((pp[i].press & 0x4000))) 
                {
                    pp[i].press &= ~0x4000;
                }
                
                if (((pp[i].press & 0x8000)) && ((pp[i].press & 0x2000))) 
                {
                    pp[i].press &= ~0x2000;
                }
            }
        }
        else
        {
            pp[i].PerTypeEx = 0;
            
            pp[i].on = 0;
            
            pp[i].press = 0;
            
            pp[i].l = 0;
            pp[i].r = 0;
            
            pp[i].x1 = 0;
            pp[i].y1 = 0;
            
            pp[i].x2 = 0;
            pp[i].y2 = 0;
        }
        
        Ps2_MakeRepeatKey(i, pad_wk);
    } 
    
    if (Pad[CurrentPortId].SoftReset != 0)
    {
        SoftResetFlag = 1;
    }
}

// 100% matching!
void Ps2_MakeRepeatKey(unsigned int Id, PAD_WORK* pad_wk)
{
    Pad[Id].Rept = pad_wk->onon;
}

// 
// Start address: 0x2da7a0
void Pad_set(PAD_WORK* pbt, unsigned short pad_num)
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
	scePrintf("Pad_set - UNIMPLEMENTED!\n");
}

// 100% matching! 
void Pad_init()
{
    while (scePadInit(0) == 0);
    
    scePadPortOpen(0, 0, Padd1);
    scePadPortOpen(1, 0, Padd2);
}
