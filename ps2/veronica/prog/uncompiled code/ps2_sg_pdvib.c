typedef struct _anon0;
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
};

unsigned char Pad_vibe_call_num;
unsigned char Ps2_pad_motor[6];
_anon0 Pad_act[20];

int pdVibMxIsReady();
int pdVibMxSetStopTime();
int pdVibMxStart(_anon1* param);
int pdVibMxStop();
void Ps2_pad_actuater();
void Ps2_pad_act_start(_anon0* pPact);
void Ps2_pad_act_stop(_anon0* pPact);
void Ps2_pad_act_all_stop();

// 
// Start address: 0x2daab0
int pdVibMxIsReady()
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
}

// 
// Start address: 0x2dab70
int pdVibMxSetStopTime()
{
	// Line 131, Address: 0x2dab70, Func Offset: 0
	// Func End, Address: 0x2dab78, Func Offset: 0x8
}

// 
// Start address: 0x2dab80
int pdVibMxStart(_anon1* param)
{
	_anon0* pPact;
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
}

// 
// Start address: 0x2dac40
int pdVibMxStop()
{
	// Line 211, Address: 0x2dac40, Func Offset: 0
	// Line 228, Address: 0x2dac48, Func Offset: 0x8
	// Line 231, Address: 0x2dac50, Func Offset: 0x10
	// Line 230, Address: 0x2dac54, Func Offset: 0x14
	// Line 231, Address: 0x2dac58, Func Offset: 0x18
	// Func End, Address: 0x2dac60, Func Offset: 0x20
}

// 
// Start address: 0x2dac60
void Ps2_pad_actuater()
{
	unsigned int cnt;
	_anon0* pPact;
	// Line 240, Address: 0x2dac60, Func Offset: 0
	// Line 245, Address: 0x2dac70, Func Offset: 0x10
	// Line 241, Address: 0x2dac78, Func Offset: 0x18
	// Line 247, Address: 0x2dac7c, Func Offset: 0x1c
	// Line 241, Address: 0x2dac80, Func Offset: 0x20
	// Line 247, Address: 0x2dac84, Func Offset: 0x24
	// Line 242, Address: 0x2dac88, Func Offset: 0x28
	// Line 254, Address: 0x2dac8c, Func Offset: 0x2c
	// Line 255, Address: 0x2dac9c, Func Offset: 0x3c
	// Line 256, Address: 0x2daca8, Func Offset: 0x48
	// Line 257, Address: 0x2dacac, Func Offset: 0x4c
	// Line 259, Address: 0x2dacb4, Func Offset: 0x54
	// Line 261, Address: 0x2dacc0, Func Offset: 0x60
	// Line 262, Address: 0x2dacc8, Func Offset: 0x68
	// Line 263, Address: 0x2dacd0, Func Offset: 0x70
	// Line 265, Address: 0x2dacd8, Func Offset: 0x78
	// Line 268, Address: 0x2dace4, Func Offset: 0x84
	// Line 270, Address: 0x2dace8, Func Offset: 0x88
	// Line 271, Address: 0x2dacec, Func Offset: 0x8c
	// Line 275, Address: 0x2dacf8, Func Offset: 0x98
	// Line 273, Address: 0x2dad00, Func Offset: 0xa0
	// Line 275, Address: 0x2dad04, Func Offset: 0xa4
	// Line 277, Address: 0x2dad14, Func Offset: 0xb4
	// Func End, Address: 0x2dad28, Func Offset: 0xc8
}

// 
// Start address: 0x2dad30
void Ps2_pad_act_start(_anon0* pPact)
{
	// Line 296, Address: 0x2dad30, Func Offset: 0
	// Line 298, Address: 0x2dad40, Func Offset: 0x10
	// Line 299, Address: 0x2dad4c, Func Offset: 0x1c
	// Line 302, Address: 0x2dad70, Func Offset: 0x40
	// Line 304, Address: 0x2dad88, Func Offset: 0x58
	// Line 306, Address: 0x2dad90, Func Offset: 0x60
	// Line 307, Address: 0x2dad9c, Func Offset: 0x6c
	// Line 310, Address: 0x2dada8, Func Offset: 0x78
	// Line 311, Address: 0x2dadb4, Func Offset: 0x84
	// Line 314, Address: 0x2dadc0, Func Offset: 0x90
	// Func End, Address: 0x2dadc8, Func Offset: 0x98
}

// 
// Start address: 0x2dadd0
void Ps2_pad_act_stop(_anon0* pPact)
{
	// Line 328, Address: 0x2dadd0, Func Offset: 0
	// Func End, Address: 0x2dadd8, Func Offset: 0x8
}

// 
// Start address: 0x2dade0
void Ps2_pad_act_all_stop()
{
	int i;
	_anon0* pPact;
	// Line 338, Address: 0x2dade0, Func Offset: 0
	// Line 339, Address: 0x2dade8, Func Offset: 0x8
	// Line 350, Address: 0x2dadec, Func Offset: 0xc
	// Line 352, Address: 0x2dadf0, Func Offset: 0x10
	// Line 351, Address: 0x2dadf4, Func Offset: 0x14
	// Line 352, Address: 0x2dadf8, Func Offset: 0x18
	// Line 358, Address: 0x2dae08, Func Offset: 0x28
	// Func End, Address: 0x2dae10, Func Offset: 0x30
}

