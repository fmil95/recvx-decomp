typedef struct _anon0;


typedef float type[16384];

struct _anon0
{
	int keys;
	int* iparam;
	float* fparam;
};

float SinTable[16384];

void _Make_SinTable();
float njSin(int lAngle);
float njCos(int lAngle);
void njSinCos(int lAngle, float* sin, float* cos);
float njFraction(float fN);
float njSqrt(float x);
float njInvertSqrt(float x);
void njLinear(float* fpIdata, float* fpOdata, float fFrame);
void njOverhauserSpline(float* fpIdata, float* fpOdata, _anon0* pAttr, float fT);
void njBezierSpline(float* fpIdata, float* fpOdata, _anon0* pAttr, float fFrame);
unsigned int njFactorial(unsigned int ulN);

// 
// Start address: 0x2d7c50
void _Make_SinTable()
{
	int i;
	// Line 51, Address: 0x2d7c50, Func Offset: 0
	// Line 54, Address: 0x2d7c68, Func Offset: 0x18
	// Line 55, Address: 0x2d7c6c, Func Offset: 0x1c
	// Line 56, Address: 0x2d7c88, Func Offset: 0x38
	// Line 55, Address: 0x2d7c8c, Func Offset: 0x3c
	// Line 56, Address: 0x2d7c90, Func Offset: 0x40
	// Line 58, Address: 0x2d7c9c, Func Offset: 0x4c
	// Func End, Address: 0x2d7cb0, Func Offset: 0x60
}

// 
// Start address: 0x2d7cb0
float njSin(int lAngle)
{
	float ret;
	// Line 79, Address: 0x2d7cb0, Func Offset: 0
	// Line 113, Address: 0x2d7cb4, Func Offset: 0x4
	// Line 79, Address: 0x2d7cc0, Func Offset: 0x10
	// Line 115, Address: 0x2d7cc4, Func Offset: 0x14
	// Line 116, Address: 0x2d7cc8, Func Offset: 0x18
	// Line 117, Address: 0x2d7ccc, Func Offset: 0x1c
	// Line 118, Address: 0x2d7cd0, Func Offset: 0x20
	// Line 120, Address: 0x2d7cd8, Func Offset: 0x28
	// Line 121, Address: 0x2d7cdc, Func Offset: 0x2c
	// Line 122, Address: 0x2d7ce8, Func Offset: 0x38
	// Line 123, Address: 0x2d7cec, Func Offset: 0x3c
	// Line 124, Address: 0x2d7cf0, Func Offset: 0x40
	// Line 125, Address: 0x2d7cf4, Func Offset: 0x44
	// Line 126, Address: 0x2d7cf8, Func Offset: 0x48
	// Line 127, Address: 0x2d7cfc, Func Offset: 0x4c
	// Line 128, Address: 0x2d7d00, Func Offset: 0x50
	// Line 131, Address: 0x2d7d08, Func Offset: 0x58
	// Line 132, Address: 0x2d7d14, Func Offset: 0x64
	// Line 133, Address: 0x2d7d18, Func Offset: 0x68
	// Line 134, Address: 0x2d7d1c, Func Offset: 0x6c
	// Line 135, Address: 0x2d7d20, Func Offset: 0x70
	// Line 136, Address: 0x2d7d24, Func Offset: 0x74
	// Line 137, Address: 0x2d7d28, Func Offset: 0x78
	// Line 138, Address: 0x2d7d2c, Func Offset: 0x7c
	// Line 140, Address: 0x2d7d30, Func Offset: 0x80
	// Line 150, Address: 0x2d7d34, Func Offset: 0x84
	// Func End, Address: 0x2d7d3c, Func Offset: 0x8c
}

// 
// Start address: 0x2d7d40
float njCos(int lAngle)
{
	float ret;
	// Line 172, Address: 0x2d7d40, Func Offset: 0
	// Line 208, Address: 0x2d7d44, Func Offset: 0x4
	// Line 172, Address: 0x2d7d50, Func Offset: 0x10
	// Line 210, Address: 0x2d7d54, Func Offset: 0x14
	// Line 211, Address: 0x2d7d58, Func Offset: 0x18
	// Line 212, Address: 0x2d7d5c, Func Offset: 0x1c
	// Line 213, Address: 0x2d7d60, Func Offset: 0x20
	// Line 215, Address: 0x2d7d68, Func Offset: 0x28
	// Line 216, Address: 0x2d7d74, Func Offset: 0x34
	// Line 217, Address: 0x2d7d78, Func Offset: 0x38
	// Line 218, Address: 0x2d7d7c, Func Offset: 0x3c
	// Line 219, Address: 0x2d7d80, Func Offset: 0x40
	// Line 220, Address: 0x2d7d84, Func Offset: 0x44
	// Line 221, Address: 0x2d7d88, Func Offset: 0x48
	// Line 222, Address: 0x2d7d8c, Func Offset: 0x4c
	// Line 225, Address: 0x2d7d94, Func Offset: 0x54
	// Line 226, Address: 0x2d7d98, Func Offset: 0x58
	// Line 227, Address: 0x2d7da4, Func Offset: 0x64
	// Line 228, Address: 0x2d7da8, Func Offset: 0x68
	// Line 229, Address: 0x2d7dac, Func Offset: 0x6c
	// Line 230, Address: 0x2d7db0, Func Offset: 0x70
	// Line 231, Address: 0x2d7db4, Func Offset: 0x74
	// Line 232, Address: 0x2d7db8, Func Offset: 0x78
	// Line 233, Address: 0x2d7dbc, Func Offset: 0x7c
	// Line 235, Address: 0x2d7dc0, Func Offset: 0x80
	// Line 245, Address: 0x2d7dc4, Func Offset: 0x84
	// Func End, Address: 0x2d7dcc, Func Offset: 0x8c
}

// 
// Start address: 0x2d7dd0
void njSinCos(int lAngle, float* sin, float* cos)
{
	// Line 254, Address: 0x2d7dd0, Func Offset: 0
	// Line 289, Address: 0x2d7dd8, Func Offset: 0x8
	// Line 291, Address: 0x2d7de4, Func Offset: 0x14
	// Line 292, Address: 0x2d7de8, Func Offset: 0x18
	// Line 293, Address: 0x2d7dec, Func Offset: 0x1c
	// Line 294, Address: 0x2d7df0, Func Offset: 0x20
	// Line 296, Address: 0x2d7df8, Func Offset: 0x28
	// Line 297, Address: 0x2d7dfc, Func Offset: 0x2c
	// Line 298, Address: 0x2d7e08, Func Offset: 0x38
	// Line 299, Address: 0x2d7e14, Func Offset: 0x44
	// Line 300, Address: 0x2d7e18, Func Offset: 0x48
	// Line 301, Address: 0x2d7e1c, Func Offset: 0x4c
	// Line 302, Address: 0x2d7e20, Func Offset: 0x50
	// Line 303, Address: 0x2d7e24, Func Offset: 0x54
	// Line 304, Address: 0x2d7e28, Func Offset: 0x58
	// Line 305, Address: 0x2d7e2c, Func Offset: 0x5c
	// Line 306, Address: 0x2d7e30, Func Offset: 0x60
	// Line 307, Address: 0x2d7e34, Func Offset: 0x64
	// Line 308, Address: 0x2d7e38, Func Offset: 0x68
	// Line 309, Address: 0x2d7e3c, Func Offset: 0x6c
	// Line 310, Address: 0x2d7e40, Func Offset: 0x70
	// Line 311, Address: 0x2d7e44, Func Offset: 0x74
	// Line 314, Address: 0x2d7e4c, Func Offset: 0x7c
	// Line 315, Address: 0x2d7e50, Func Offset: 0x80
	// Line 316, Address: 0x2d7e5c, Func Offset: 0x8c
	// Line 317, Address: 0x2d7e68, Func Offset: 0x98
	// Line 318, Address: 0x2d7e6c, Func Offset: 0x9c
	// Line 319, Address: 0x2d7e70, Func Offset: 0xa0
	// Line 320, Address: 0x2d7e74, Func Offset: 0xa4
	// Line 321, Address: 0x2d7e78, Func Offset: 0xa8
	// Line 322, Address: 0x2d7e7c, Func Offset: 0xac
	// Line 323, Address: 0x2d7e80, Func Offset: 0xb0
	// Line 324, Address: 0x2d7e84, Func Offset: 0xb4
	// Line 325, Address: 0x2d7e88, Func Offset: 0xb8
	// Line 326, Address: 0x2d7e8c, Func Offset: 0xbc
	// Line 327, Address: 0x2d7e90, Func Offset: 0xc0
	// Line 328, Address: 0x2d7e94, Func Offset: 0xc4
	// Line 329, Address: 0x2d7e98, Func Offset: 0xc8
	// Line 331, Address: 0x2d7e9c, Func Offset: 0xcc
	// Line 332, Address: 0x2d7ea0, Func Offset: 0xd0
	// Line 333, Address: 0x2d7ea4, Func Offset: 0xd4
	// Line 334, Address: 0x2d7ea8, Func Offset: 0xd8
	// Line 338, Address: 0x2d7eac, Func Offset: 0xdc
	// Func End, Address: 0x2d7eb4, Func Offset: 0xe4
}

// 
// Start address: 0x2d7ec0
float njFraction(float fN)
{
	// Line 356, Address: 0x2d7ec0, Func Offset: 0
	// Line 357, Address: 0x2d7ecc, Func Offset: 0xc
	// Line 358, Address: 0x2d7ed8, Func Offset: 0x18
	// Func End, Address: 0x2d7ee8, Func Offset: 0x28
}

// 
// Start address: 0x2d7ef0
float njSqrt(float x)
{
	float ret;
	// Line 438, Address: 0x2d7ef0, Func Offset: 0
	// Line 439, Address: 0x2d7ef8, Func Offset: 0x8
	// Line 440, Address: 0x2d7efc, Func Offset: 0xc
	// Line 441, Address: 0x2d7f00, Func Offset: 0x10
	// Line 442, Address: 0x2d7f04, Func Offset: 0x14
	// Line 443, Address: 0x2d7f08, Func Offset: 0x18
	// Line 444, Address: 0x2d7f0c, Func Offset: 0x1c
	// Line 448, Address: 0x2d7f10, Func Offset: 0x20
	// Func End, Address: 0x2d7f18, Func Offset: 0x28
}

// 
// Start address: 0x2d7f20
float njInvertSqrt(float x)
{
	float ret;
	// Line 466, Address: 0x2d7f20, Func Offset: 0
	// Line 467, Address: 0x2d7f28, Func Offset: 0x8
	// Line 468, Address: 0x2d7f2c, Func Offset: 0xc
	// Line 469, Address: 0x2d7f30, Func Offset: 0x10
	// Line 470, Address: 0x2d7f34, Func Offset: 0x14
	// Line 471, Address: 0x2d7f38, Func Offset: 0x18
	// Line 472, Address: 0x2d7f3c, Func Offset: 0x1c
	// Line 476, Address: 0x2d7f40, Func Offset: 0x20
	// Func End, Address: 0x2d7f48, Func Offset: 0x28
}

// 
// Start address: 0x2d7f50
void njLinear(float* fpIdata, float* fpOdata, float fFrame)
{
	// Line 526, Address: 0x2d7f50, Func Offset: 0
	// Line 527, Address: 0x2d7f54, Func Offset: 0x4
	// Line 528, Address: 0x2d7f58, Func Offset: 0x8
	// Line 529, Address: 0x2d7f5c, Func Offset: 0xc
	// Line 530, Address: 0x2d7f60, Func Offset: 0x10
	// Line 531, Address: 0x2d7f64, Func Offset: 0x14
	// Line 532, Address: 0x2d7f68, Func Offset: 0x18
	// Line 533, Address: 0x2d7f6c, Func Offset: 0x1c
	// Line 534, Address: 0x2d7f70, Func Offset: 0x20
	// Line 535, Address: 0x2d7f74, Func Offset: 0x24
	// Line 536, Address: 0x2d7f78, Func Offset: 0x28
	// Line 537, Address: 0x2d7f7c, Func Offset: 0x2c
	// Line 538, Address: 0x2d7f80, Func Offset: 0x30
	// Line 539, Address: 0x2d7f84, Func Offset: 0x34
	// Line 540, Address: 0x2d7f88, Func Offset: 0x38
	// Line 541, Address: 0x2d7f8c, Func Offset: 0x3c
	// Line 542, Address: 0x2d7f90, Func Offset: 0x40
	// Line 543, Address: 0x2d7f94, Func Offset: 0x44
	// Line 544, Address: 0x2d7f98, Func Offset: 0x48
	// Line 545, Address: 0x2d7f9c, Func Offset: 0x4c
	// Line 549, Address: 0x2d7fa0, Func Offset: 0x50
	// Func End, Address: 0x2d7fa8, Func Offset: 0x58
}

// 
// Start address: 0x2d7fb0
void njOverhauserSpline(float* fpIdata, float* fpOdata, _anon0* pAttr, float fT)
{
	float ftmp;
	// Line 594, Address: 0x2d7fb0, Func Offset: 0
	// Line 599, Address: 0x2d7fb8, Func Offset: 0x8
	// Line 600, Address: 0x2d7fbc, Func Offset: 0xc
	// Line 601, Address: 0x2d7fc0, Func Offset: 0x10
	// Line 602, Address: 0x2d7fc4, Func Offset: 0x14
	// Line 606, Address: 0x2d7fc8, Func Offset: 0x18
	// Line 607, Address: 0x2d7fcc, Func Offset: 0x1c
	// Line 609, Address: 0x2d7fd0, Func Offset: 0x20
	// Line 610, Address: 0x2d7fd4, Func Offset: 0x24
	// Line 611, Address: 0x2d7fd8, Func Offset: 0x28
	// Line 613, Address: 0x2d7fdc, Func Offset: 0x2c
	// Line 614, Address: 0x2d7fe0, Func Offset: 0x30
	// Line 615, Address: 0x2d7fe4, Func Offset: 0x34
	// Line 616, Address: 0x2d7fe8, Func Offset: 0x38
	// Line 618, Address: 0x2d7fec, Func Offset: 0x3c
	// Line 619, Address: 0x2d7ff0, Func Offset: 0x40
	// Line 620, Address: 0x2d7ff4, Func Offset: 0x44
	// Line 621, Address: 0x2d7ff8, Func Offset: 0x48
	// Line 622, Address: 0x2d7ffc, Func Offset: 0x4c
	// Line 624, Address: 0x2d8000, Func Offset: 0x50
	// Line 625, Address: 0x2d8004, Func Offset: 0x54
	// Line 626, Address: 0x2d800c, Func Offset: 0x5c
	// Line 627, Address: 0x2d8010, Func Offset: 0x60
	// Line 628, Address: 0x2d8014, Func Offset: 0x64
	// Line 629, Address: 0x2d8018, Func Offset: 0x68
	// Line 630, Address: 0x2d801c, Func Offset: 0x6c
	// Line 631, Address: 0x2d8020, Func Offset: 0x70
	// Line 632, Address: 0x2d8024, Func Offset: 0x74
	// Line 633, Address: 0x2d8028, Func Offset: 0x78
	// Line 634, Address: 0x2d802c, Func Offset: 0x7c
	// Line 635, Address: 0x2d8030, Func Offset: 0x80
	// Line 636, Address: 0x2d8034, Func Offset: 0x84
	// Line 637, Address: 0x2d8038, Func Offset: 0x88
	// Line 638, Address: 0x2d803c, Func Offset: 0x8c
	// Line 639, Address: 0x2d8040, Func Offset: 0x90
	// Line 640, Address: 0x2d8044, Func Offset: 0x94
	// Line 641, Address: 0x2d8048, Func Offset: 0x98
	// Line 642, Address: 0x2d804c, Func Offset: 0x9c
	// Line 643, Address: 0x2d8050, Func Offset: 0xa0
	// Line 644, Address: 0x2d8054, Func Offset: 0xa4
	// Line 645, Address: 0x2d8058, Func Offset: 0xa8
	// Line 646, Address: 0x2d805c, Func Offset: 0xac
	// Line 650, Address: 0x2d8060, Func Offset: 0xb0
	// Line 651, Address: 0x2d8064, Func Offset: 0xb4
	// Line 652, Address: 0x2d8068, Func Offset: 0xb8
	// Line 653, Address: 0x2d806c, Func Offset: 0xbc
	// Line 655, Address: 0x2d8070, Func Offset: 0xc0
	// Line 656, Address: 0x2d8074, Func Offset: 0xc4
	// Line 657, Address: 0x2d8078, Func Offset: 0xc8
	// Line 658, Address: 0x2d807c, Func Offset: 0xcc
	// Line 659, Address: 0x2d8080, Func Offset: 0xd0
	// Line 660, Address: 0x2d8084, Func Offset: 0xd4
	// Line 661, Address: 0x2d8088, Func Offset: 0xd8
	// Line 662, Address: 0x2d808c, Func Offset: 0xdc
	// Line 667, Address: 0x2d8090, Func Offset: 0xe0
	// Func End, Address: 0x2d8098, Func Offset: 0xe8
}

// 
// Start address: 0x2d80a0
void njBezierSpline(float* fpIdata, float* fpOdata, _anon0* pAttr, float fFrame)
{
	float fResult;
	float fFactMax;
	unsigned int ulMax;
	unsigned int ulCnt;
	// Line 692, Address: 0x2d80a0, Func Offset: 0
	// Line 728, Address: 0x2d80d0, Func Offset: 0x30
	// Line 729, Address: 0x2d80d4, Func Offset: 0x34
	// Line 730, Address: 0x2d80d8, Func Offset: 0x38
	// Line 733, Address: 0x2d80dc, Func Offset: 0x3c
	// Line 734, Address: 0x2d80f4, Func Offset: 0x54
	// Line 736, Address: 0x2d812c, Func Offset: 0x8c
	// Line 739, Address: 0x2d8148, Func Offset: 0xa8
	// Line 741, Address: 0x2d821c, Func Offset: 0x17c
	// Line 744, Address: 0x2d8220, Func Offset: 0x180
	// Line 741, Address: 0x2d8228, Func Offset: 0x188
	// Line 742, Address: 0x2d8238, Func Offset: 0x198
	// Line 743, Address: 0x2d824c, Func Offset: 0x1ac
	// Line 744, Address: 0x2d8260, Func Offset: 0x1c0
	// Line 746, Address: 0x2d8268, Func Offset: 0x1c8
	// Func End, Address: 0x2d829c, Func Offset: 0x1fc
}

// 
// Start address: 0x2d82a0
unsigned int njFactorial(unsigned int ulN)
{
	unsigned int ulResult;
	// Line 804, Address: 0x2d82a0, Func Offset: 0
	// Line 806, Address: 0x2d82a8, Func Offset: 0x8
	// Line 807, Address: 0x2d82ac, Func Offset: 0xc
	// Line 827, Address: 0x2d82c8, Func Offset: 0x28
	// Func End, Address: 0x2d82d0, Func Offset: 0x30
}

