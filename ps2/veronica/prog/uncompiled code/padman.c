typedef struct _anon0;
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
};

unsigned int KeyWaitFirst;
unsigned int KeyWaitNext;
_anon4 ButtonInfo[5];
int SoftResetFlag;
int CurrentPortId;
_anon1 Pad[4];
int MaxContorolPlayer;
_anon2 RepeatInfo[6][4];

void InitReadKeyEx(int MaxPlayer);
void SetRepeatKeyTimer(unsigned int FirstTimer, unsigned int NextTimer);
int CheckSoftResetKeyFlag(int ControllerId);
void ClearSoftResetKeyFlag(int ControllerId);

// 
// Start address: 0x297e00
void InitReadKeyEx(int MaxPlayer)
{
	unsigned int j;
	unsigned int i;
	// Line 60, Address: 0x297e10, Func Offset: 0x10
	// Line 73, Address: 0x297e14, Func Offset: 0x14
	// Line 74, Address: 0x297e18, Func Offset: 0x18
	// Line 62, Address: 0x297e1c, Func Offset: 0x1c
	// Line 63, Address: 0x297e20, Func Offset: 0x20
	// Line 64, Address: 0x297e24, Func Offset: 0x24
	// Line 65, Address: 0x297e28, Func Offset: 0x28
	// Line 66, Address: 0x297e2c, Func Offset: 0x2c
	// Line 61, Address: 0x297e30, Func Offset: 0x30
	// Line 62, Address: 0x297e38, Func Offset: 0x38
	// Line 63, Address: 0x297e3c, Func Offset: 0x3c
	// Line 64, Address: 0x297e40, Func Offset: 0x40
	// Line 65, Address: 0x297e44, Func Offset: 0x44
	// Line 66, Address: 0x297e48, Func Offset: 0x48
	// Line 67, Address: 0x297e4c, Func Offset: 0x4c
	// Line 68, Address: 0x297e58, Func Offset: 0x58
	// Line 70, Address: 0x297e5c, Func Offset: 0x5c
	// Line 69, Address: 0x297e60, Func Offset: 0x60
	// Line 70, Address: 0x297e68, Func Offset: 0x68
	// Line 71, Address: 0x297e74, Func Offset: 0x74
	// Line 72, Address: 0x297e78, Func Offset: 0x78
	// Line 73, Address: 0x297e7c, Func Offset: 0x7c
	// Line 74, Address: 0x297e80, Func Offset: 0x80
	// Line 76, Address: 0x297e84, Func Offset: 0x84
	// Line 75, Address: 0x297e88, Func Offset: 0x88
	// Line 76, Address: 0x297e90, Func Offset: 0x90
	// Line 78, Address: 0x297e9c, Func Offset: 0x9c
	// Line 80, Address: 0x297ea4, Func Offset: 0xa4
	// Line 82, Address: 0x297eb8, Func Offset: 0xb8
	// Line 81, Address: 0x297ebc, Func Offset: 0xbc
	// Line 82, Address: 0x297ec4, Func Offset: 0xc4
	// Line 84, Address: 0x297ed8, Func Offset: 0xd8
	// Line 85, Address: 0x297ee0, Func Offset: 0xe0
	// Line 86, Address: 0x297ee4, Func Offset: 0xe4
	// Func End, Address: 0x297eec, Func Offset: 0xec
}

// 
// Start address: 0x297ef0
void SetRepeatKeyTimer(unsigned int FirstTimer, unsigned int NextTimer)
{
	// Line 126, Address: 0x297ef0, Func Offset: 0
	// Line 127, Address: 0x297ef8, Func Offset: 0x8
	// Line 128, Address: 0x297efc, Func Offset: 0xc
	// Func End, Address: 0x297f04, Func Offset: 0x14
}

// 
// Start address: 0x297f10
int CheckSoftResetKeyFlag(int ControllerId)
{
	// Line 133, Address: 0x297f10, Func Offset: 0
	// Line 137, Address: 0x297f60, Func Offset: 0x50
	// Func End, Address: 0x297f68, Func Offset: 0x58
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
}

