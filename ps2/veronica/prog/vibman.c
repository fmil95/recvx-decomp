/*typedef struct _anon0;


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
};*/

char PortIdTbl[4] = {
    0x02, 0x08, 0x0E, 0x14
};
int EnadleVibrationFlag;
unsigned int VibStopTime;

/*void InitVibrationUnit();
void ExitVibrationUnit();
void SetUseVibrationUnit(int Flag);
int GetUseVibrationUnit();*/
int CheckVibrationUnit(unsigned int PortId);
/*int StartVibration(unsigned int PortId, _anon0* vpp);
int StopVibration(unsigned int PortId);*/

// 100% matching! 
void InitVibrationUnit()
{ 
    int i;

    VibStopTime = 20;

    for (i = 0; i < 4; i++) 
    { 
        if (CheckVibrationUnit(PortIdTbl[i]) == 1) 
        { 
            pdVibMxSetStopTime(PortIdTbl[i], VibStopTime); 
        } 
    } 

    EnadleVibrationFlag = 0; 
} 

/*// 
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
}*/

// 100% matching! 
int GetUseVibrationUnit()
{
    return EnadleVibrationFlag; 
} 

// 100% matching!
int CheckVibrationUnit(unsigned int PortId)
{
    return pdVibMxIsReady(PortId); 
}

/*// 
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
}*/

