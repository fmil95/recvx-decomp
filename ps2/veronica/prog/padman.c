/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;


typedef char type_0[32];
typedef char type_1[64];
typedef int type_2[4];
typedef _anon4 type_3[5];
typedef _anon1 type_4[4];
typedef _anon2 type_5[6];
typedef _anon2 type_6[6][4];
typedef unsigned int type_7[3];
typedef unsigned char type_8[2];

struct _anon0
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
	_anon3* info;
};

struct _anon1
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

struct _anon2
{
	unsigned int WaitFlag;
	unsigned int WaitCnt;
	unsigned int Key;
};

struct _anon3
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

struct _anon4
{
	int Type;
	unsigned int Button;
};*/

unsigned int KeyWaitFirst;
unsigned int KeyWaitNext;
/*_anon4 ButtonInfo[5];*/
int SoftResetFlag;
int CurrentPortId;
PAD_INFO Pad[4];
int MaxContorolPlayer;
REPEAT_INFO RepeatInfo[4][6];

void InitReadKeyEx(int MaxPlayer);
void SetRepeatKeyTimer(unsigned int FirstTimer, unsigned int NextTimer);
int CheckSoftResetKeyFlag(int ControllerId);
void ClearSoftResetKeyFlag(int ControllerId);

// 100% matching! 
void InitReadKeyEx(int MaxPlayer) 
{
    unsigned int i; 
    unsigned int j; 

    for (i = 0; i < 4; i++) 
    { 
        RepeatInfo[i][0].Key = 0x8000; 
        RepeatInfo[i][1].Key = 0x2000; 
        RepeatInfo[i][2].Key = 0x1000; 
        RepeatInfo[i][3].Key = 0x4000; 
        RepeatInfo[i][4].Key = 0x4; 
        RepeatInfo[i][5].Key = 0x8; 
        
        for (j = 0; j < 6; j++)
        { 
            RepeatInfo[i][j].WaitFlag = 0; 
            RepeatInfo[i][j].WaitCnt = 0; 
        } 
        
        Pad[i].on2 = 0; 
        Pad[i].press2 = 0; 
        
        Pad[i].Calibrate = 64; 
        
        Pad[i].Flag = 1; 
        
        Pad[i].SoftReset = 0; 
    }   

    MaxContorolPlayer = MaxPlayer; 

    for (i = 0; i < MaxPlayer; i++) 
    { 
        Pad[i].Flag = 0; 
    } 
    
    CurrentPortId = 0; 
    
    SoftResetFlag = 0; 
} 

// 100% matching! 
void SetRepeatKeyTimer(unsigned int FirstTimer, unsigned int NextTimer)
{
    KeyWaitFirst = FirstTimer; 
    KeyWaitNext = NextTimer; 
} 

// 100% matching! 
int CheckSoftResetKeyFlag(int ControllerId)
{
    if (ControllerId < 0) 
    {
        return Pad[CurrentPortId].SoftReset; 
    }
    else 
    {
        return Pad[ControllerId].SoftReset;
    }
}

// 
// Start address: 0x297f70
void ClearSoftResetKeyFlag(int ControllerId)
{
	int i;
	// Line 143, Address: 0x297f70, Func Offset: 0
	// Line 144, Address: 0x297f80, Func Offset: 0x10
	// Line 146, Address: 0x297f84, Func Offset: 0x14
	// Line 145, Address: 0x297f88, Func Offset: 0x18
	// Line 146, Address: 0x297f8c, Func Offset: 0x1c
	// Line 145, Address: 0x297f90, Func Offset: 0x20
	// Line 146, Address: 0x297f94, Func Offset: 0x24
	// Line 147, Address: 0x297fa0, Func Offset: 0x30
	// Line 148, Address: 0x297fa8, Func Offset: 0x38
	// Line 151, Address: 0x297fc4, Func Offset: 0x54
	// Line 152, Address: 0x297fc8, Func Offset: 0x58
	// Func End, Address: 0x297fd0, Func Offset: 0x60
	scePrintf("ClearSoftResetKeyFlag - UNIMPLEMENTED!\n");
}
