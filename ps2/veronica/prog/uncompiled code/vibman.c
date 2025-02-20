typedef struct _anon0;


typedef unsigned char type_0[3];
typedef char type_1[4];

struct _anon0
{
	unsigned char unit;
	unsigned char flag;
	char power;
	unsigned char freq;
	unsigned char inc;
	unsigned char reserved[3];
};

char PortIdTbl[4];
int EnadleVibrationFlag;
unsigned int VibStopTime;

void InitVibrationUnit();
void ExitVibrationUnit();
void SetUseVibrationUnit(int Flag);
int GetUseVibrationUnit();
int CheckVibrationUnit(unsigned int PortId);
int StartVibration(unsigned int PortId, _anon0* vpp);
int StopVibration(unsigned int PortId);

// 
// Start address: 0x2c84e0
void InitVibrationUnit()
{
	int i;
	// Line 16, Address: 0x2c84e0, Func Offset: 0
	// Line 19, Address: 0x2c84f0, Func Offset: 0x10
	// Line 21, Address: 0x2c8504, Func Offset: 0x24
	// Line 22, Address: 0x2c8508, Func Offset: 0x28
	// Line 23, Address: 0x2c851c, Func Offset: 0x3c
	// Line 24, Address: 0x2c852c, Func Offset: 0x4c
	// Line 25, Address: 0x2c8530, Func Offset: 0x50
	// Line 27, Address: 0x2c8540, Func Offset: 0x60
	// Line 28, Address: 0x2c8548, Func Offset: 0x68
	// Func End, Address: 0x2c855c, Func Offset: 0x7c
}

// 
// Start address: 0x2c8560
void ExitVibrationUnit()
{
	int i;
	// Line 31, Address: 0x2c8560, Func Offset: 0
	// Line 34, Address: 0x2c8578, Func Offset: 0x18
	// Line 35, Address: 0x2c857c, Func Offset: 0x1c
	// Line 36, Address: 0x2c8590, Func Offset: 0x30
	// Line 38, Address: 0x2c8598, Func Offset: 0x38
	// Line 39, Address: 0x2c85a8, Func Offset: 0x48
	// Func End, Address: 0x2c85bc, Func Offset: 0x5c
}

// 
// Start address: 0x2c85c0
void SetUseVibrationUnit(int Flag)
{
	// Line 43, Address: 0x2c85c0, Func Offset: 0
	// Line 44, Address: 0x2c85c4, Func Offset: 0x4
	// Func End, Address: 0x2c85cc, Func Offset: 0xc
}

// 
// Start address: 0x2c85d0
int GetUseVibrationUnit()
{
	// Line 48, Address: 0x2c85d0, Func Offset: 0
	// Line 49, Address: 0x2c85d4, Func Offset: 0x4
	// Func End, Address: 0x2c85dc, Func Offset: 0xc
}

// 
// Start address: 0x2c85e0
int CheckVibrationUnit(unsigned int PortId)
{
	// Line 53, Address: 0x2c85e0, Func Offset: 0
	// Func End, Address: 0x2c85e8, Func Offset: 0x8
}

// 
// Start address: 0x2c85f0
int StartVibration(unsigned int PortId, _anon0* vpp)
{
	// Line 62, Address: 0x2c85f0, Func Offset: 0
	// Line 65, Address: 0x2c8600, Func Offset: 0x10
	// Line 66, Address: 0x2c8614, Func Offset: 0x24
	// Line 69, Address: 0x2c861c, Func Offset: 0x2c
	// Line 70, Address: 0x2c863c, Func Offset: 0x4c
	// Line 73, Address: 0x2c8644, Func Offset: 0x54
	// Line 74, Address: 0x2c8658, Func Offset: 0x68
	// Line 81, Address: 0x2c8660, Func Offset: 0x70
	// Line 82, Address: 0x2c8664, Func Offset: 0x74
	// Line 83, Address: 0x2c8670, Func Offset: 0x80
	// Func End, Address: 0x2c8684, Func Offset: 0x94
}

// 
// Start address: 0x2c8690
int StopVibration(unsigned int PortId)
{
	// Line 86, Address: 0x2c8690, Func Offset: 0
	// Line 87, Address: 0x2c869c, Func Offset: 0xc
	// Line 88, Address: 0x2c86ac, Func Offset: 0x1c
	// Line 91, Address: 0x2c86b4, Func Offset: 0x24
	// Line 92, Address: 0x2c86d4, Func Offset: 0x44
	// Line 96, Address: 0x2c86dc, Func Offset: 0x4c
	// Line 100, Address: 0x2c8704, Func Offset: 0x74
	// Func End, Address: 0x2c8714, Func Offset: 0x84
}

