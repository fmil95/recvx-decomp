

typedef int type_0[4];
typedef float type_1[8];
typedef float type_2[128];
typedef float type_3[8];

float fNaFogTbl[128];
unsigned int ulNaFogState;
float fNaFogB;
unsigned int ulNaFogB;
float fNaFogG;
unsigned int ulNaFogG;
float fNaFogR;
unsigned int ulNaFogR;
float fNaFogA;
unsigned int ulNaFogA;
float* fpNaFogTblTop;
float fNaFogNear;
float fNaFogFar;
float fNaFogDensity;
float fNaFogDist;

void njFogEnable();
void njFogDisable();
void njSetFogColor(unsigned int ulColor);
void njSetFogTable(float* FogTbl);
void njGenerateFogTable3(float near, float far);
float njCalcFogPowerEx(float INVZ);
float njCalcFogPower(float fVSZ);

// 
// Start address: 0x2d5f60
void njFogEnable()
{
	// Line 82, Address: 0x2d5f60, Func Offset: 0
	// Line 83, Address: 0x2d5f68, Func Offset: 0x8
	// Func End, Address: 0x2d5f70, Func Offset: 0x10
}

// 
// Start address: 0x2d5f70
void njFogDisable()
{
	// Line 96, Address: 0x2d5f70, Func Offset: 0
	// Line 97, Address: 0x2d5f74, Func Offset: 0x4
	// Func End, Address: 0x2d5f7c, Func Offset: 0xc
}

// 
// Start address: 0x2d5f80
void njSetFogColor(unsigned int ulColor)
{
	// Line 114, Address: 0x2d5f80, Func Offset: 0
	// Line 115, Address: 0x2d5f90, Func Offset: 0x10
	// Line 116, Address: 0x2d5fa0, Func Offset: 0x20
	// Line 117, Address: 0x2d5fb0, Func Offset: 0x30
	// Line 118, Address: 0x2d5fbc, Func Offset: 0x3c
	// Line 119, Address: 0x2d5ffc, Func Offset: 0x7c
	// Line 118, Address: 0x2d6000, Func Offset: 0x80
	// Line 119, Address: 0x2d6004, Func Offset: 0x84
	// Line 118, Address: 0x2d6008, Func Offset: 0x88
	// Line 119, Address: 0x2d6010, Func Offset: 0x90
	// Line 120, Address: 0x2d6048, Func Offset: 0xc8
	// Line 119, Address: 0x2d604c, Func Offset: 0xcc
	// Line 120, Address: 0x2d6050, Func Offset: 0xd0
	// Line 119, Address: 0x2d6054, Func Offset: 0xd4
	// Line 120, Address: 0x2d605c, Func Offset: 0xdc
	// Line 121, Address: 0x2d6094, Func Offset: 0x114
	// Line 120, Address: 0x2d6098, Func Offset: 0x118
	// Line 121, Address: 0x2d609c, Func Offset: 0x11c
	// Line 120, Address: 0x2d60a0, Func Offset: 0x120
	// Line 121, Address: 0x2d60a8, Func Offset: 0x128
	// Line 122, Address: 0x2d60f0, Func Offset: 0x170
	// Func End, Address: 0x2d60f8, Func Offset: 0x178
}

// 
// Start address: 0x2d6100
void njSetFogTable(float* FogTbl)
{
	// Line 140, Address: 0x2d6100, Func Offset: 0
	// Line 141, Address: 0x2d6104, Func Offset: 0x4
	// Func End, Address: 0x2d610c, Func Offset: 0xc
}

// 
// Start address: 0x2d6110
void njGenerateFogTable3(float near, float far)
{
	int exp[4];
	int count;
	int tmp;
	int i;
	float fr1;
	float fr0;
	// Line 151, Address: 0x2d6110, Func Offset: 0
	// Line 158, Address: 0x2d6118, Func Offset: 0x8
	// Line 151, Address: 0x2d611c, Func Offset: 0xc
	// Line 158, Address: 0x2d6124, Func Offset: 0x14
	// Line 151, Address: 0x2d6128, Func Offset: 0x18
	// Line 158, Address: 0x2d612c, Func Offset: 0x1c
	// Line 160, Address: 0x2d6144, Func Offset: 0x34
	// Line 161, Address: 0x2d614c, Func Offset: 0x3c
	// Line 162, Address: 0x2d6154, Func Offset: 0x44
	// Line 164, Address: 0x2d6160, Func Offset: 0x50
	// Line 165, Address: 0x2d6164, Func Offset: 0x54
	// Line 167, Address: 0x2d6174, Func Offset: 0x64
	// Line 169, Address: 0x2d6184, Func Offset: 0x74
	// Line 173, Address: 0x2d618c, Func Offset: 0x7c
	// Line 179, Address: 0x2d61d4, Func Offset: 0xc4
	// Line 181, Address: 0x2d61fc, Func Offset: 0xec
	// Line 182, Address: 0x2d6204, Func Offset: 0xf4
	// Line 186, Address: 0x2d620c, Func Offset: 0xfc
	// Line 185, Address: 0x2d621c, Func Offset: 0x10c
	// Line 189, Address: 0x2d622c, Func Offset: 0x11c
	// Line 190, Address: 0x2d6230, Func Offset: 0x120
	// Line 202, Address: 0x2d6234, Func Offset: 0x124
	// Line 195, Address: 0x2d6240, Func Offset: 0x130
	// Line 202, Address: 0x2d6244, Func Offset: 0x134
	// Line 204, Address: 0x2d6294, Func Offset: 0x184
	// Line 205, Address: 0x2d62a4, Func Offset: 0x194
	// Line 207, Address: 0x2d62a8, Func Offset: 0x198
	// Line 208, Address: 0x2d62ac, Func Offset: 0x19c
	// Line 227, Address: 0x2d62b8, Func Offset: 0x1a8
	// Line 228, Address: 0x2d62c8, Func Offset: 0x1b8
	// Line 229, Address: 0x2d62d4, Func Offset: 0x1c4
	// Line 230, Address: 0x2d62e8, Func Offset: 0x1d8
	// Line 229, Address: 0x2d62f0, Func Offset: 0x1e0
	// Line 233, Address: 0x2d62f8, Func Offset: 0x1e8
	// Line 234, Address: 0x2d6304, Func Offset: 0x1f4
	// Line 235, Address: 0x2d6308, Func Offset: 0x1f8
	// Line 233, Address: 0x2d630c, Func Offset: 0x1fc
	// Line 235, Address: 0x2d631c, Func Offset: 0x20c
	// Line 236, Address: 0x2d6324, Func Offset: 0x214
	// Line 237, Address: 0x2d6338, Func Offset: 0x228
	// Line 239, Address: 0x2d6344, Func Offset: 0x234
	// Line 242, Address: 0x2d6360, Func Offset: 0x250
	// Line 241, Address: 0x2d6364, Func Offset: 0x254
	// Line 243, Address: 0x2d6368, Func Offset: 0x258
	// Line 241, Address: 0x2d636c, Func Offset: 0x25c
	// Line 243, Address: 0x2d6370, Func Offset: 0x260
	// Line 245, Address: 0x2d637c, Func Offset: 0x26c
	// Line 251, Address: 0x2d6388, Func Offset: 0x278
	// Line 252, Address: 0x2d638c, Func Offset: 0x27c
	// Line 253, Address: 0x2d6398, Func Offset: 0x288
	// Line 252, Address: 0x2d63a0, Func Offset: 0x290
	// Line 253, Address: 0x2d63ac, Func Offset: 0x29c
	// Line 256, Address: 0x2d63b4, Func Offset: 0x2a4
	// Func End, Address: 0x2d63cc, Func Offset: 0x2bc
}

// 
// Start address: 0x2d63d0
float njCalcFogPowerEx(float INVZ)
{
	unsigned int tmp;
	float vb;
	float v0;
	float ftmp2;
	int itmp0;
	float ret;
	float inv[8];
	// Line 280, Address: 0x2d63d0, Func Offset: 0
	// Line 272, Address: 0x2d63d8, Func Offset: 0x8
	// Line 280, Address: 0x2d63e0, Func Offset: 0x10
	// Line 281, Address: 0x2d63e8, Func Offset: 0x18
	// Line 285, Address: 0x2d6400, Func Offset: 0x30
	// Line 289, Address: 0x2d6408, Func Offset: 0x38
	// Line 285, Address: 0x2d6414, Func Offset: 0x44
	// Line 289, Address: 0x2d6418, Func Offset: 0x48
	// Line 290, Address: 0x2d6430, Func Offset: 0x60
	// Line 293, Address: 0x2d6450, Func Offset: 0x80
	// Line 294, Address: 0x2d6458, Func Offset: 0x88
	// Line 301, Address: 0x2d646c, Func Offset: 0x9c
	// Line 294, Address: 0x2d6470, Func Offset: 0xa0
	// Line 301, Address: 0x2d6474, Func Offset: 0xa4
	// Line 309, Address: 0x2d6484, Func Offset: 0xb4
	// Line 311, Address: 0x2d6488, Func Offset: 0xb8
	// Line 313, Address: 0x2d6490, Func Offset: 0xc0
	// Line 315, Address: 0x2d64b0, Func Offset: 0xe0
	// Line 320, Address: 0x2d64cc, Func Offset: 0xfc
	// Line 315, Address: 0x2d64d0, Func Offset: 0x100
	// Line 320, Address: 0x2d64d4, Func Offset: 0x104
	// Line 315, Address: 0x2d64dc, Func Offset: 0x10c
	// Line 320, Address: 0x2d64e0, Func Offset: 0x110
	// Line 390, Address: 0x2d650c, Func Offset: 0x13c
	// Func End, Address: 0x2d6514, Func Offset: 0x144
}

// 
// Start address: 0x2d6520
float njCalcFogPower(float fVSZ)
{
	unsigned int tmp;
	float vb;
	float v0;
	float ftmp2;
	int itmp0;
	float ret;
	float inv[8];
	// Line 413, Address: 0x2d6520, Func Offset: 0
	// Line 404, Address: 0x2d6528, Func Offset: 0x8
	// Line 413, Address: 0x2d6530, Func Offset: 0x10
	// Line 419, Address: 0x2d6538, Func Offset: 0x18
	// Line 422, Address: 0x2d656c, Func Offset: 0x4c
	// Line 423, Address: 0x2d6590, Func Offset: 0x70
	// Line 427, Address: 0x2d65b4, Func Offset: 0x94
	// Line 428, Address: 0x2d65bc, Func Offset: 0x9c
	// Line 441, Address: 0x2d65d4, Func Offset: 0xb4
	// Line 442, Address: 0x2d65e4, Func Offset: 0xc4
	// Line 444, Address: 0x2d65f4, Func Offset: 0xd4
	// Line 450, Address: 0x2d6608, Func Offset: 0xe8
	// Line 452, Address: 0x2d6618, Func Offset: 0xf8
	// Line 454, Address: 0x2d6620, Func Offset: 0x100
	// Line 456, Address: 0x2d6640, Func Offset: 0x120
	// Line 461, Address: 0x2d665c, Func Offset: 0x13c
	// Line 456, Address: 0x2d6660, Func Offset: 0x140
	// Line 461, Address: 0x2d6664, Func Offset: 0x144
	// Line 456, Address: 0x2d666c, Func Offset: 0x14c
	// Line 461, Address: 0x2d6670, Func Offset: 0x150
	// Line 572, Address: 0x2d669c, Func Offset: 0x17c
	// Func End, Address: 0x2d66a4, Func Offset: 0x184
}

