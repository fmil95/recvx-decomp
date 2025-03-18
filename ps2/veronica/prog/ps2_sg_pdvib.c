/*typedef struct _anon0;
typedef struct _anon1;


typedef char type_0[2];
typedef unsigned char type_1[3];
typedef _anon0 type_2[20];
typedef unsigned char type_3[6];

struct _anon0
{
	unsigned char be_flag;
	unsigned char level;
	unsigned char start;
	unsigned char end;
	unsigned short delay;
	unsigned short time;
	unsigned short add;
	short f_level;
	short f_add;
	char data[2];
};

struct _anon1
{
	unsigned char unit;
	unsigned char flag;
	char power;
	unsigned char freq;
	unsigned char inc;
	unsigned char reserved[3];
};*/

unsigned char Pad_vibe_call_num;
unsigned char Ps2_pad_motor[6];
PAD_ACT Pad_act[20];

/*int pdVibMxIsReady();
int pdVibMxSetStopTime();
int pdVibMxStart(_anon1* param);
int pdVibMxStop();
void Ps2_pad_actuater();*/
void Ps2_pad_act_start(PAD_ACT* pPact);
void Ps2_pad_act_stop(PAD_ACT* pPact);
void Ps2_pad_act_all_stop();

// 
// Start address: 0x2daab0
Sint32 pdVibMxIsReady(Uint32 port)
{
	unsigned char i;
	unsigned int pad_info;
	unsigned int pad_stat;
	// Line 38, Address: 0x2daab0, Func Offset: 0
	// Line 44, Address: 0x2daab8, Func Offset: 0x8
	// Line 47, Address: 0x2daac4, Func Offset: 0x14
	// Line 49, Address: 0x2daadc, Func Offset: 0x2c
	// Line 52, Address: 0x2daae4, Func Offset: 0x34
	// Line 54, Address: 0x2daae8, Func Offset: 0x38
	// Line 56, Address: 0x2dab08, Func Offset: 0x58
	// Line 57, Address: 0x2dab0c, Func Offset: 0x5c
	// Line 56, Address: 0x2dab14, Func Offset: 0x64
	// Line 57, Address: 0x2dab18, Func Offset: 0x68
	// Line 60, Address: 0x2dab28, Func Offset: 0x78
	// Line 63, Address: 0x2dab3c, Func Offset: 0x8c
	// Line 64, Address: 0x2dab54, Func Offset: 0xa4
	// Line 72, Address: 0x2dab5c, Func Offset: 0xac
	// Line 73, Address: 0x2dab60, Func Offset: 0xb0
	// Func End, Address: 0x2dab6c, Func Offset: 0xbc
	scePrintf("pdVibMxIsReady - UNIMPLEMENTED!\n");
}

// 100% matching! 
Sint32 pdVibMxSetStopTime(Uint32 port, Uint32 time)
{
    return 0;
}

// 
// Start address: 0x2dab80
Sint32 pdVibMxStart(Uint32 port, const PDS_VIBPARAM* param)
{
	//_anon0* pPact;
	unsigned char cnt;
	// Line 148, Address: 0x2dab80, Func Offset: 0
	// Line 159, Address: 0x2dab88, Func Offset: 0x8
	// Line 161, Address: 0x2dab90, Func Offset: 0x10
	// Line 162, Address: 0x2daba4, Func Offset: 0x24
	// Line 164, Address: 0x2dabac, Func Offset: 0x2c
	// Line 167, Address: 0x2dabb8, Func Offset: 0x38
	// Line 174, Address: 0x2dabc0, Func Offset: 0x40
	// Line 175, Address: 0x2dabd0, Func Offset: 0x50
	// Line 176, Address: 0x2dabd8, Func Offset: 0x58
	// Line 178, Address: 0x2dabe0, Func Offset: 0x60
	// Line 187, Address: 0x2dabf0, Func Offset: 0x70
	// Line 188, Address: 0x2dac00, Func Offset: 0x80
	// Line 189, Address: 0x2dac04, Func Offset: 0x84
	// Line 190, Address: 0x2dac18, Func Offset: 0x98
	// Line 191, Address: 0x2dac1c, Func Offset: 0x9c
	// Line 192, Address: 0x2dac24, Func Offset: 0xa4
	// Line 200, Address: 0x2dac2c, Func Offset: 0xac
	// Func End, Address: 0x2dac34, Func Offset: 0xb4
	scePrintf("pdVibMxStart - UNIMPLEMENTED!\n");
}

// 100% matching! 
Sint32 pdVibMxStop(Uint32 port)
{
    Ps2_pad_act_all_stop();
    
    return 0;
}

// 100% matching! 
void Ps2_pad_actuater()
{
    PAD_ACT* pPact;
    unsigned int cnt;

    pPact = Pad_act;
    
    Ps2_pad_motor[0] = 0;
    Ps2_pad_motor[1] = 0;
    
    for (cnt = 0; cnt < 19; cnt++) 
    {
        if ((pPact->be_flag & 0x3)) 
        {
            if (pPact->delay > 0) 
            {
                pPact->delay--;
            }
            else if (pPact->time > 0) 
            {
                Ps2_pad_act_start(pPact);
                
                pPact->time--;
            } 
            else
            {
                Ps2_pad_act_stop(pPact);
            }
        }
        
        pPact++;
    } 
    
    Pad_vibe_call_num = 0;
    
    scePadSetActDirect(0, 0, Ps2_pad_motor);
}

// 100% matching! 
void Ps2_pad_act_start(PAD_ACT* pPact)
{
    unsigned char temp; // not from the debugging symbols

    if ((pPact->be_flag & 0x2)) 
    {
        if (pPact->f_add != 0) 
        {
            pPact->level = (((short)pPact->start * 16) - (short)pPact->f_add) / 16;
        }
        
        temp = pPact->level;
        
        if (Ps2_pad_motor[1] < temp)
        {
            Ps2_pad_motor[1] = temp;
        }
        
        if (pPact->f_level != 0) 
        {
            pPact->f_add += pPact->f_level;
        }
    }
    
    if (pPact->f_level != 0) 
    {
        pPact->f_add += pPact->f_level;
    }
}

// 100% matching! 
void Ps2_pad_act_stop(PAD_ACT* pPact)
{
    pPact->be_flag = 0;
}

// 100% matching! 
void Ps2_pad_act_all_stop()
{
    PAD_ACT* pPact; 
    int i; 
    
    pPact = Pad_act;
    
    i = 19;
    
    do
    {
        pPact->be_flag = 0;
        
        pPact++; 
    } while (i--);
}
