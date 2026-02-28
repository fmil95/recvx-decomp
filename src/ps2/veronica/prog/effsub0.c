#include "effsub0.h"

/*_anon4* sys;
_anon0 eff[0];
_anon29 cam;

// 
// Start address: 0x21ee20
int setentry(unsigned short id, unsigned short type, _anon0* op)
{
	// Line 124, Address: 0x21ee20, Func Offset: 0
	// Line 137, Address: 0x21ee30, Func Offset: 0x10
	// Line 124, Address: 0x21ee34, Func Offset: 0x14
	// Line 125, Address: 0x21ee40, Func Offset: 0x20
	// Line 126, Address: 0x21ee54, Func Offset: 0x34
	// Line 127, Address: 0x21ee68, Func Offset: 0x48
	// Line 137, Address: 0x21ee70, Func Offset: 0x50
	// Line 127, Address: 0x21ee74, Func Offset: 0x54
	// Line 128, Address: 0x21ee80, Func Offset: 0x60
	// Line 129, Address: 0x21ee94, Func Offset: 0x74
	// Line 130, Address: 0x21eeac, Func Offset: 0x8c
	// Line 131, Address: 0x21eec4, Func Offset: 0xa4
	// Line 132, Address: 0x21eedc, Func Offset: 0xbc
	// Line 133, Address: 0x21eef4, Func Offset: 0xd4
	// Line 134, Address: 0x21ef0c, Func Offset: 0xec
	// Line 135, Address: 0x21ef24, Func Offset: 0x104
	// Line 136, Address: 0x21ef3c, Func Offset: 0x11c
	// Line 137, Address: 0x21ef54, Func Offset: 0x134
	// Func End, Address: 0x21ef70, Func Offset: 0x150
}

// 
// Start address: 0x21ef70
void effinit(_anon0* op)
{
	// Line 148, Address: 0x21ef70, Func Offset: 0
	// Line 149, Address: 0x21ef78, Func Offset: 0x8
	// Line 152, Address: 0x21ef7c, Func Offset: 0xc
	// Line 161, Address: 0x21ef80, Func Offset: 0x10
	// Line 148, Address: 0x21ef84, Func Offset: 0x14
	// Line 149, Address: 0x21ef8c, Func Offset: 0x1c
	// Line 150, Address: 0x21ef90, Func Offset: 0x20
	// Line 151, Address: 0x21ef94, Func Offset: 0x24
	// Line 152, Address: 0x21ef98, Func Offset: 0x28
	// Line 153, Address: 0x21ef9c, Func Offset: 0x2c
	// Line 154, Address: 0x21efa0, Func Offset: 0x30
	// Line 155, Address: 0x21efa4, Func Offset: 0x34
	// Line 156, Address: 0x21efa8, Func Offset: 0x38
	// Line 157, Address: 0x21efac, Func Offset: 0x3c
	// Line 158, Address: 0x21efb0, Func Offset: 0x40
	// Line 159, Address: 0x21efb4, Func Offset: 0x44
	// Line 160, Address: 0x21efb8, Func Offset: 0x48
	// Line 161, Address: 0x21efbc, Func Offset: 0x4c
	// Line 162, Address: 0x21efc0, Func Offset: 0x50
	// Line 163, Address: 0x21efc4, Func Offset: 0x54
	// Line 164, Address: 0x21efc8, Func Offset: 0x58
	// Line 165, Address: 0x21efcc, Func Offset: 0x5c
	// Line 166, Address: 0x21efd4, Func Offset: 0x64
	// Line 167, Address: 0x21efdc, Func Offset: 0x6c
	// Line 168, Address: 0x21effc, Func Offset: 0x8c
	// Line 169, Address: 0x21f000, Func Offset: 0x90
	// Line 170, Address: 0x21f008, Func Offset: 0x98
	// Line 171, Address: 0x21f010, Func Offset: 0xa0
	// Line 172, Address: 0x21f018, Func Offset: 0xa8
	// Line 173, Address: 0x21f01c, Func Offset: 0xac
	// Line 174, Address: 0x21f024, Func Offset: 0xb4
	// Func End, Address: 0x21f02c, Func Offset: 0xbc
}

// 
// Start address: 0x21f030
void effset(_anon0* op, _anon3* uvp, unsigned short num)
{
	unsigned int kcol[4][10];
	// Line 226, Address: 0x21f030, Func Offset: 0
	// Line 229, Address: 0x21f038, Func Offset: 0x8
	// Line 226, Address: 0x21f040, Func Offset: 0x10
	// Line 229, Address: 0x21f04c, Func Offset: 0x1c
	// Line 226, Address: 0x21f058, Func Offset: 0x28
	// Line 230, Address: 0x21f05c, Func Offset: 0x2c
	// Line 226, Address: 0x21f068, Func Offset: 0x38
	// Line 227, Address: 0x21f06c, Func Offset: 0x3c
	// Line 231, Address: 0x21f074, Func Offset: 0x44
	// Line 227, Address: 0x21f080, Func Offset: 0x50
	// Line 232, Address: 0x21f084, Func Offset: 0x54
	// Line 227, Address: 0x21f090, Func Offset: 0x60
	// Line 229, Address: 0x21f098, Func Offset: 0x68
	// Line 230, Address: 0x21f0a0, Func Offset: 0x70
	// Line 231, Address: 0x21f0a8, Func Offset: 0x78
	// Line 232, Address: 0x21f0b0, Func Offset: 0x80
	// Line 234, Address: 0x21f0b8, Func Offset: 0x88
	// Line 235, Address: 0x21f0c0, Func Offset: 0x90
	// Line 236, Address: 0x21f0c8, Func Offset: 0x98
	// Line 237, Address: 0x21f0d8, Func Offset: 0xa8
	// Line 238, Address: 0x21f0e0, Func Offset: 0xb0
	// Line 239, Address: 0x21f0e8, Func Offset: 0xb8
	// Line 240, Address: 0x21f0f8, Func Offset: 0xc8
	// Line 241, Address: 0x21f108, Func Offset: 0xd8
	// Line 242, Address: 0x21f114, Func Offset: 0xe4
	// Func End, Address: 0x21f11c, Func Offset: 0xec
}

// 
// Start address: 0x21f120
void getuv(unsigned char type, _anon0* op)
{
	unsigned char i;
	_anon24 vd;
	_anon24 vs;
	float tab_type[3][4][2];
	// Line 250, Address: 0x21f120, Func Offset: 0
	// Line 251, Address: 0x21f12c, Func Offset: 0xc
	// Line 250, Address: 0x21f130, Func Offset: 0x10
	// Line 251, Address: 0x21f138, Func Offset: 0x18
	// Line 271, Address: 0x21f150, Func Offset: 0x30
	// Line 251, Address: 0x21f154, Func Offset: 0x34
	// Line 271, Address: 0x21f180, Func Offset: 0x60
	// Line 251, Address: 0x21f188, Func Offset: 0x68
	// Line 271, Address: 0x21f18c, Func Offset: 0x6c
	// Line 272, Address: 0x21f194, Func Offset: 0x74
	// Line 275, Address: 0x21f198, Func Offset: 0x78
	// Line 272, Address: 0x21f1a4, Func Offset: 0x84
	// Line 273, Address: 0x21f1a8, Func Offset: 0x88
	// Line 274, Address: 0x21f1b0, Func Offset: 0x90
	// Line 275, Address: 0x21f1b4, Func Offset: 0x94
	// Line 276, Address: 0x21f1bc, Func Offset: 0x9c
	// Line 279, Address: 0x21f1c0, Func Offset: 0xa0
	// Line 278, Address: 0x21f1c4, Func Offset: 0xa4
	// Line 279, Address: 0x21f1c8, Func Offset: 0xa8
	// Line 276, Address: 0x21f1cc, Func Offset: 0xac
	// Line 277, Address: 0x21f1d0, Func Offset: 0xb0
	// Line 278, Address: 0x21f1d8, Func Offset: 0xb8
	// Line 279, Address: 0x21f1e4, Func Offset: 0xc4
	// Line 280, Address: 0x21f1f8, Func Offset: 0xd8
	// Func End, Address: 0x21f210, Func Offset: 0xf0
}

// 
// Start address: 0x21f210
void bhEff150(_anon0* op)
{
	// Line 293, Address: 0x21f210, Func Offset: 0
	// Line 294, Address: 0x21f21c, Func Offset: 0xc
	// Line 296, Address: 0x21f22c, Func Offset: 0x1c
	// Line 297, Address: 0x21f24c, Func Offset: 0x3c
	// Line 298, Address: 0x21f258, Func Offset: 0x48
	// Line 299, Address: 0x21f270, Func Offset: 0x60
	// Line 300, Address: 0x21f274, Func Offset: 0x64
	// Line 303, Address: 0x21f278, Func Offset: 0x68
	// Func End, Address: 0x21f288, Func Offset: 0x78
}

// 
// Start address: 0x21f290
void bhEff151(_anon0* op)
{
	_anon3* uvp;
	_anon3 uvinfo_koisi[11];
	_anon3 uvinfo_mokuhen[11];
	// Line 312, Address: 0x21f290, Func Offset: 0
	// Line 344, Address: 0x21f29c, Func Offset: 0xc
	// Line 346, Address: 0x21f2b0, Func Offset: 0x20
	// Line 347, Address: 0x21f2b4, Func Offset: 0x24
	// Line 349, Address: 0x21f2bc, Func Offset: 0x2c
	// Line 351, Address: 0x21f2c8, Func Offset: 0x38
	// Line 354, Address: 0x21f2d8, Func Offset: 0x48
	// Line 351, Address: 0x21f2dc, Func Offset: 0x4c
	// Line 354, Address: 0x21f2e4, Func Offset: 0x54
	// Line 356, Address: 0x21f2f8, Func Offset: 0x68
	// Line 357, Address: 0x21f304, Func Offset: 0x74
	// Line 358, Address: 0x21f30c, Func Offset: 0x7c
	// Line 360, Address: 0x21f314, Func Offset: 0x84
	// Line 361, Address: 0x21f320, Func Offset: 0x90
	// Line 364, Address: 0x21f32c, Func Offset: 0x9c
	// Line 370, Address: 0x21f334, Func Offset: 0xa4
	// Line 371, Address: 0x21f344, Func Offset: 0xb4
	// Line 372, Address: 0x21f348, Func Offset: 0xb8
	// Line 374, Address: 0x21f360, Func Offset: 0xd0
	// Line 376, Address: 0x21f36c, Func Offset: 0xdc
	// Line 378, Address: 0x21f374, Func Offset: 0xe4
	// Line 379, Address: 0x21f380, Func Offset: 0xf0
	// Line 386, Address: 0x21f38c, Func Offset: 0xfc
	// Line 387, Address: 0x21f3b8, Func Offset: 0x128
	// Line 392, Address: 0x21f3c0, Func Offset: 0x130
	// Line 387, Address: 0x21f3cc, Func Offset: 0x13c
	// Line 391, Address: 0x21f3d4, Func Offset: 0x144
	// Line 392, Address: 0x21f3e4, Func Offset: 0x154
	// Line 394, Address: 0x21f3f8, Func Offset: 0x168
	// Line 397, Address: 0x21f400, Func Offset: 0x170
	// Line 398, Address: 0x21f40c, Func Offset: 0x17c
	// Line 399, Address: 0x21f410, Func Offset: 0x180
	// Line 398, Address: 0x21f414, Func Offset: 0x184
	// Line 399, Address: 0x21f41c, Func Offset: 0x18c
	// Line 400, Address: 0x21f450, Func Offset: 0x1c0
	// Func End, Address: 0x21f460, Func Offset: 0x1d0
}

// 
// Start address: 0x21f460
void bhEff152(_anon0* op)
{
	unsigned short j;
	unsigned short i;
	_anon24 vd;
	_anon24 vs;
	// Line 409, Address: 0x21f460, Func Offset: 0
	// Line 413, Address: 0x21f484, Func Offset: 0x24
	// Line 415, Address: 0x21f494, Func Offset: 0x34
	// Line 417, Address: 0x21f4b4, Func Offset: 0x54
	// Line 418, Address: 0x21f4c0, Func Offset: 0x60
	// Line 419, Address: 0x21f4c8, Func Offset: 0x68
	// Line 420, Address: 0x21f4cc, Func Offset: 0x6c
	// Line 421, Address: 0x21f4d8, Func Offset: 0x78
	// Line 422, Address: 0x21f4ec, Func Offset: 0x8c
	// Line 427, Address: 0x21f4fc, Func Offset: 0x9c
	// Line 424, Address: 0x21f500, Func Offset: 0xa0
	// Line 425, Address: 0x21f504, Func Offset: 0xa4
	// Line 426, Address: 0x21f508, Func Offset: 0xa8
	// Line 427, Address: 0x21f50c, Func Offset: 0xac
	// Line 428, Address: 0x21f518, Func Offset: 0xb8
	// Line 430, Address: 0x21f524, Func Offset: 0xc4
	// Line 429, Address: 0x21f528, Func Offset: 0xc8
	// Line 432, Address: 0x21f52c, Func Offset: 0xcc
	// Line 433, Address: 0x21f538, Func Offset: 0xd8
	// Line 434, Address: 0x21f5dc, Func Offset: 0x17c
	// Line 435, Address: 0x21f680, Func Offset: 0x220
	// Line 441, Address: 0x21f718, Func Offset: 0x2b8
	// Line 442, Address: 0x21f724, Func Offset: 0x2c4
	// Line 435, Address: 0x21f728, Func Offset: 0x2c8
	// Line 454, Address: 0x21f72c, Func Offset: 0x2cc
	// Line 435, Address: 0x21f738, Func Offset: 0x2d8
	// Line 441, Address: 0x21f744, Func Offset: 0x2e4
	// Line 442, Address: 0x21f754, Func Offset: 0x2f4
	// Line 443, Address: 0x21f768, Func Offset: 0x308
	// Line 444, Address: 0x21f77c, Func Offset: 0x31c
	// Line 445, Address: 0x21f794, Func Offset: 0x334
	// Line 446, Address: 0x21f7a8, Func Offset: 0x348
	// Line 447, Address: 0x21f7c0, Func Offset: 0x360
	// Line 448, Address: 0x21f7d8, Func Offset: 0x378
	// Line 449, Address: 0x21f7f0, Func Offset: 0x390
	// Line 450, Address: 0x21f808, Func Offset: 0x3a8
	// Line 451, Address: 0x21f820, Func Offset: 0x3c0
	// Line 452, Address: 0x21f838, Func Offset: 0x3d8
	// Line 453, Address: 0x21f850, Func Offset: 0x3f0
	// Line 454, Address: 0x21f868, Func Offset: 0x408
	// Line 456, Address: 0x21f880, Func Offset: 0x420
	// Line 457, Address: 0x21f8a4, Func Offset: 0x444
	// Line 459, Address: 0x21f8c4, Func Offset: 0x464
	// Line 460, Address: 0x21f8c8, Func Offset: 0x468
	// Line 461, Address: 0x21f8cc, Func Offset: 0x46c
	// Line 462, Address: 0x21f8d0, Func Offset: 0x470
	// Line 466, Address: 0x21f8d4, Func Offset: 0x474
	// Func End, Address: 0x21f8fc, Func Offset: 0x49c
}

// 
// Start address: 0x21f900
void bhEff153(_anon0* op)
{
	_anon3 uvinfo_geki[12];
	// Line 475, Address: 0x21f900, Func Offset: 0
	// Line 494, Address: 0x21f90c, Func Offset: 0xc
	// Line 496, Address: 0x21f938, Func Offset: 0x38
	// Line 497, Address: 0x21f93c, Func Offset: 0x3c
	// Line 499, Address: 0x21f944, Func Offset: 0x44
	// Line 501, Address: 0x21f950, Func Offset: 0x50
	// Line 499, Address: 0x21f954, Func Offset: 0x54
	// Line 502, Address: 0x21f960, Func Offset: 0x60
	// Line 505, Address: 0x21f968, Func Offset: 0x68
	// Line 508, Address: 0x21f970, Func Offset: 0x70
	// Line 513, Address: 0x21f978, Func Offset: 0x78
	// Line 522, Address: 0x21f988, Func Offset: 0x88
	// Line 529, Address: 0x21f9f4, Func Offset: 0xf4
	// Line 530, Address: 0x21fa2c, Func Offset: 0x12c
	// Func End, Address: 0x21fa3c, Func Offset: 0x13c
}

// 
// Start address: 0x21fa40
void bhEff154(_anon0* op)
{
	// Line 539, Address: 0x21fa40, Func Offset: 0
	// Line 540, Address: 0x21fa4c, Func Offset: 0xc
	// Line 542, Address: 0x21fa5c, Func Offset: 0x1c
	// Line 543, Address: 0x21fa7c, Func Offset: 0x3c
	// Line 545, Address: 0x21fa88, Func Offset: 0x48
	// Line 546, Address: 0x21faa0, Func Offset: 0x60
	// Line 548, Address: 0x21fac4, Func Offset: 0x84
	// Line 549, Address: 0x21fb14, Func Offset: 0xd4
	// Line 551, Address: 0x21fb1c, Func Offset: 0xdc
	// Line 552, Address: 0x21fb6c, Func Offset: 0x12c
	// Line 554, Address: 0x21fb74, Func Offset: 0x134
	// Line 556, Address: 0x21fbc8, Func Offset: 0x188
	// Line 559, Address: 0x21fbd8, Func Offset: 0x198
	// Line 557, Address: 0x21fbdc, Func Offset: 0x19c
	// Line 559, Address: 0x21fbe0, Func Offset: 0x1a0
	// Line 561, Address: 0x21fbe4, Func Offset: 0x1a4
	// Line 564, Address: 0x21fbf0, Func Offset: 0x1b0
	// Func End, Address: 0x21fc00, Func Offset: 0x1c0
}

// 
// Start address: 0x21fc00
void bhEff155(_anon0* op)
{
	_anon3* uvp;
	_anon3 uvinfo_hibana_0[8];
	_anon3 uvinfo_hibana_2[8];
	_anon3 uvinfo_hibana_1[8];
	// Line 573, Address: 0x21fc00, Func Offset: 0
	// Line 609, Address: 0x21fc0c, Func Offset: 0xc
	// Line 611, Address: 0x21fc20, Func Offset: 0x20
	// Line 612, Address: 0x21fc24, Func Offset: 0x24
	// Line 615, Address: 0x21fc2c, Func Offset: 0x2c
	// Line 617, Address: 0x21fc50, Func Offset: 0x50
	// Line 618, Address: 0x21fc58, Func Offset: 0x58
	// Line 620, Address: 0x21fc60, Func Offset: 0x60
	// Line 621, Address: 0x21fc68, Func Offset: 0x68
	// Line 623, Address: 0x21fc70, Func Offset: 0x70
	// Line 625, Address: 0x21fc7c, Func Offset: 0x7c
	// Line 631, Address: 0x21fc84, Func Offset: 0x84
	// Line 632, Address: 0x21fc8c, Func Offset: 0x8c
	// Line 631, Address: 0x21fc94, Func Offset: 0x94
	// Line 632, Address: 0x21fc9c, Func Offset: 0x9c
	// Line 666, Address: 0x21fcb0, Func Offset: 0xb0
	// Line 669, Address: 0x21fcb8, Func Offset: 0xb8
	// Line 670, Address: 0x21fcc4, Func Offset: 0xc4
	// Line 671, Address: 0x21fcc8, Func Offset: 0xc8
	// Line 670, Address: 0x21fccc, Func Offset: 0xcc
	// Line 671, Address: 0x21fcd4, Func Offset: 0xd4
	// Line 672, Address: 0x21fd08, Func Offset: 0x108
	// Func End, Address: 0x21fd18, Func Offset: 0x118
}

// 
// Start address: 0x21fd20
void bhEff156(_anon0* op)
{
	// Line 681, Address: 0x21fd20, Func Offset: 0
	// Line 682, Address: 0x21fd2c, Func Offset: 0xc
	// Line 684, Address: 0x21fd3c, Func Offset: 0x1c
	// Line 685, Address: 0x21fd5c, Func Offset: 0x3c
	// Line 686, Address: 0x21fd68, Func Offset: 0x48
	// Line 687, Address: 0x21fd74, Func Offset: 0x54
	// Line 688, Address: 0x21fd78, Func Offset: 0x58
	// Line 691, Address: 0x21fd7c, Func Offset: 0x5c
	// Func End, Address: 0x21fd8c, Func Offset: 0x6c
}

// 
// Start address: 0x21fd90
void bhEff157(_anon0* op)
{
	_anon24 vd;
	_anon24 vs;
	_anon3* uvp;
	_anon3 uvinfo_mos[13];
	// Line 700, Address: 0x21fd90, Func Offset: 0
	// Line 722, Address: 0x21fd9c, Func Offset: 0xc
	// Line 724, Address: 0x21fdb0, Func Offset: 0x20
	// Line 725, Address: 0x21fdb4, Func Offset: 0x24
	// Line 727, Address: 0x21fdbc, Func Offset: 0x2c
	// Line 728, Address: 0x21fdc4, Func Offset: 0x34
	// Line 729, Address: 0x21fdc8, Func Offset: 0x38
	// Line 730, Address: 0x21fdd4, Func Offset: 0x44
	// Line 731, Address: 0x21fde8, Func Offset: 0x58
	// Line 732, Address: 0x21fdf8, Func Offset: 0x68
	// Line 736, Address: 0x21fdfc, Func Offset: 0x6c
	// Line 737, Address: 0x21fe04, Func Offset: 0x74
	// Line 732, Address: 0x21fe08, Func Offset: 0x78
	// Line 733, Address: 0x21fe0c, Func Offset: 0x7c
	// Line 734, Address: 0x21fe14, Func Offset: 0x84
	// Line 736, Address: 0x21fe1c, Func Offset: 0x8c
	// Line 737, Address: 0x21fe20, Func Offset: 0x90
	// Line 743, Address: 0x21fe24, Func Offset: 0x94
	// Line 749, Address: 0x21fe2c, Func Offset: 0x9c
	// Line 743, Address: 0x21fe38, Func Offset: 0xa8
	// Line 744, Address: 0x21fe40, Func Offset: 0xb0
	// Line 745, Address: 0x21fe50, Func Offset: 0xc0
	// Line 748, Address: 0x21fe60, Func Offset: 0xd0
	// Line 749, Address: 0x21fe70, Func Offset: 0xe0
	// Line 751, Address: 0x21fe84, Func Offset: 0xf4
	// Line 755, Address: 0x21fe8c, Func Offset: 0xfc
	// Line 756, Address: 0x21fe98, Func Offset: 0x108
	// Line 757, Address: 0x21fe9c, Func Offset: 0x10c
	// Line 756, Address: 0x21fea0, Func Offset: 0x110
	// Line 757, Address: 0x21fea8, Func Offset: 0x118
	// Line 758, Address: 0x21fedc, Func Offset: 0x14c
	// Func End, Address: 0x21feec, Func Offset: 0x15c
}

// 
// Start address: 0x21fef0
void bhEff158(_anon0* op)
{
	// Line 767, Address: 0x21fef0, Func Offset: 0
	// Line 769, Address: 0x21fefc, Func Offset: 0xc
	// Line 772, Address: 0x21ff0c, Func Offset: 0x1c
	// Line 773, Address: 0x21ff2c, Func Offset: 0x3c
	// Line 774, Address: 0x21ff38, Func Offset: 0x48
	// Line 775, Address: 0x21ff64, Func Offset: 0x74
	// Line 776, Address: 0x21ff68, Func Offset: 0x78
	// Line 779, Address: 0x21ff6c, Func Offset: 0x7c
	// Func End, Address: 0x21ff7c, Func Offset: 0x8c
}

// 
// Start address: 0x21ff80
void bhEff159(_anon0* op)
{
	_anon3* uvp;
	int exp_bank1[26];
	int exp_bank0[24];
	_anon3 uvinfo_exp_0[25];
	_anon3 uvinfo_exp_1[27];
	// Line 788, Address: 0x21ff80, Func Offset: 0
	// Line 867, Address: 0x21ff88, Func Offset: 0x8
	// Line 788, Address: 0x21ff8c, Func Offset: 0xc
	// Line 867, Address: 0x21ff90, Func Offset: 0x10
	// Line 872, Address: 0x21ffac, Func Offset: 0x2c
	// Line 867, Address: 0x21ffb4, Func Offset: 0x34
	// Line 872, Address: 0x21ffcc, Func Offset: 0x4c
	// Line 867, Address: 0x21ffd4, Func Offset: 0x54
	// Line 872, Address: 0x21ffdc, Func Offset: 0x5c
	// Line 881, Address: 0x220004, Func Offset: 0x84
	// Line 883, Address: 0x220018, Func Offset: 0x98
	// Line 884, Address: 0x220020, Func Offset: 0xa0
	// Line 886, Address: 0x220028, Func Offset: 0xa8
	// Line 888, Address: 0x22004c, Func Offset: 0xcc
	// Line 889, Address: 0x220054, Func Offset: 0xd4
	// Line 891, Address: 0x22005c, Func Offset: 0xdc
	// Line 892, Address: 0x220068, Func Offset: 0xe8
	// Line 893, Address: 0x220070, Func Offset: 0xf0
	// Line 894, Address: 0x2200c0, Func Offset: 0x140
	// Line 895, Address: 0x220110, Func Offset: 0x190
	// Line 896, Address: 0x220160, Func Offset: 0x1e0
	// Line 898, Address: 0x220168, Func Offset: 0x1e8
	// Line 899, Address: 0x220174, Func Offset: 0x1f4
	// Line 902, Address: 0x220178, Func Offset: 0x1f8
	// Line 909, Address: 0x220180, Func Offset: 0x200
	// Line 910, Address: 0x220188, Func Offset: 0x208
	// Line 909, Address: 0x220190, Func Offset: 0x210
	// Line 910, Address: 0x220198, Func Offset: 0x218
	// Line 912, Address: 0x2201ac, Func Offset: 0x22c
	// Line 915, Address: 0x2201b4, Func Offset: 0x234
	// Line 917, Address: 0x2201cc, Func Offset: 0x24c
	// Line 918, Address: 0x2201d8, Func Offset: 0x258
	// Line 920, Address: 0x2201e0, Func Offset: 0x260
	// Line 926, Address: 0x2201f0, Func Offset: 0x270
	// Line 930, Address: 0x2201f8, Func Offset: 0x278
	// Line 926, Address: 0x220200, Func Offset: 0x280
	// Line 927, Address: 0x220208, Func Offset: 0x288
	// Line 928, Address: 0x220218, Func Offset: 0x298
	// Line 930, Address: 0x220224, Func Offset: 0x2a4
	// Line 931, Address: 0x22022c, Func Offset: 0x2ac
	// Line 932, Address: 0x220230, Func Offset: 0x2b0
	// Line 931, Address: 0x220234, Func Offset: 0x2b4
	// Line 932, Address: 0x22023c, Func Offset: 0x2bc
	// Line 933, Address: 0x220270, Func Offset: 0x2f0
	// Func End, Address: 0x220280, Func Offset: 0x300
}

// 
// Start address: 0x220280
void bhEff160(_anon0* op)
{
	// Line 942, Address: 0x220280, Func Offset: 0
	// Line 943, Address: 0x22028c, Func Offset: 0xc
	// Line 945, Address: 0x22029c, Func Offset: 0x1c
	// Line 946, Address: 0x2202bc, Func Offset: 0x3c
	// Line 947, Address: 0x2202c8, Func Offset: 0x48
	// Line 948, Address: 0x2202e0, Func Offset: 0x60
	// Line 949, Address: 0x2202e4, Func Offset: 0x64
	// Line 952, Address: 0x2202e8, Func Offset: 0x68
	// Func End, Address: 0x2202f8, Func Offset: 0x78
}

// 
// Start address: 0x220300
void bhEff161(_anon0* op)
{
	_anon3* uvp;
	_anon24 vd;
	_anon24 vs;
	_anon3 uvinfo_sw_0[11];
	_anon3 uvinfo_sw_2[11];
	_anon3 uvinfo_sw_1[16];
	// Line 961, Address: 0x220300, Func Offset: 0
	// Line 1012, Address: 0x22030c, Func Offset: 0xc
	// Line 1014, Address: 0x220320, Func Offset: 0x20
	// Line 1015, Address: 0x220324, Func Offset: 0x24
	// Line 1017, Address: 0x22032c, Func Offset: 0x2c
	// Line 1018, Address: 0x220334, Func Offset: 0x34
	// Line 1019, Address: 0x220338, Func Offset: 0x38
	// Line 1020, Address: 0x220344, Func Offset: 0x44
	// Line 1021, Address: 0x220358, Func Offset: 0x58
	// Line 1022, Address: 0x220368, Func Offset: 0x68
	// Line 1028, Address: 0x22036c, Func Offset: 0x6c
	// Line 1022, Address: 0x220374, Func Offset: 0x74
	// Line 1023, Address: 0x220378, Func Offset: 0x78
	// Line 1024, Address: 0x220380, Func Offset: 0x80
	// Line 1028, Address: 0x220388, Func Offset: 0x88
	// Line 1030, Address: 0x2203b8, Func Offset: 0xb8
	// Line 1032, Address: 0x2203c4, Func Offset: 0xc4
	// Line 1034, Address: 0x2203cc, Func Offset: 0xcc
	// Line 1035, Address: 0x2203d8, Func Offset: 0xd8
	// Line 1036, Address: 0x2203dc, Func Offset: 0xdc
	// Line 1038, Address: 0x2203e4, Func Offset: 0xe4
	// Line 1043, Address: 0x2203f0, Func Offset: 0xf0
	// Line 1046, Address: 0x220434, Func Offset: 0x134
	// Line 1043, Address: 0x220438, Func Offset: 0x138
	// Line 1044, Address: 0x22043c, Func Offset: 0x13c
	// Line 1046, Address: 0x220440, Func Offset: 0x140
	// Line 1052, Address: 0x220444, Func Offset: 0x144
	// Line 1053, Address: 0x22044c, Func Offset: 0x14c
	// Line 1052, Address: 0x220454, Func Offset: 0x154
	// Line 1053, Address: 0x22045c, Func Offset: 0x15c
	// Line 1055, Address: 0x220470, Func Offset: 0x170
	// Line 1058, Address: 0x220478, Func Offset: 0x178
	// Line 1067, Address: 0x220480, Func Offset: 0x180
	// Line 1058, Address: 0x220488, Func Offset: 0x188
	// Line 1059, Address: 0x220490, Func Offset: 0x190
	// Line 1060, Address: 0x2204a0, Func Offset: 0x1a0
	// Line 1062, Address: 0x2204b0, Func Offset: 0x1b0
	// Line 1063, Address: 0x2204cc, Func Offset: 0x1cc
	// Line 1067, Address: 0x2204d4, Func Offset: 0x1d4
	// Line 1068, Address: 0x2204dc, Func Offset: 0x1dc
	// Line 1069, Address: 0x2204e0, Func Offset: 0x1e0
	// Line 1068, Address: 0x2204e4, Func Offset: 0x1e4
	// Line 1069, Address: 0x2204ec, Func Offset: 0x1ec
	// Line 1070, Address: 0x220520, Func Offset: 0x220
	// Func End, Address: 0x220530, Func Offset: 0x230
}

// 
// Start address: 0x220530
void bhEff162(_anon0* op)
{
	// Line 1079, Address: 0x220530, Func Offset: 0
	// Line 1080, Address: 0x22053c, Func Offset: 0xc
	// Line 1082, Address: 0x22054c, Func Offset: 0x1c
	// Line 1083, Address: 0x22056c, Func Offset: 0x3c
	// Line 1084, Address: 0x220578, Func Offset: 0x48
	// Line 1085, Address: 0x220590, Func Offset: 0x60
	// Line 1086, Address: 0x220594, Func Offset: 0x64
	// Line 1089, Address: 0x220598, Func Offset: 0x68
	// Func End, Address: 0x2205a8, Func Offset: 0x78
}

// 
// Start address: 0x2205b0
void bhEff163(_anon0* op)
{
	_anon24 vd;
	_anon24 vs;
	_anon3* uvp;
	_anon3 uvinfo_bub_0[18];
	_anon3 uvinfo_bub_1[14];
	// Line 1098, Address: 0x2205b0, Func Offset: 0
	// Line 1141, Address: 0x2205bc, Func Offset: 0xc
	// Line 1143, Address: 0x2205d0, Func Offset: 0x20
	// Line 1144, Address: 0x2205d4, Func Offset: 0x24
	// Line 1146, Address: 0x2205dc, Func Offset: 0x2c
	// Line 1148, Address: 0x2205f4, Func Offset: 0x44
	// Line 1150, Address: 0x220600, Func Offset: 0x50
	// Line 1151, Address: 0x220608, Func Offset: 0x58
	// Line 1152, Address: 0x220620, Func Offset: 0x70
	// Line 1154, Address: 0x22062c, Func Offset: 0x7c
	// Line 1156, Address: 0x220634, Func Offset: 0x84
	// Line 1157, Address: 0x220640, Func Offset: 0x90
	// Line 1159, Address: 0x220644, Func Offset: 0x94
	// Line 1160, Address: 0x22064c, Func Offset: 0x9c
	// Line 1161, Address: 0x220654, Func Offset: 0xa4
	// Line 1162, Address: 0x22065c, Func Offset: 0xac
	// Line 1163, Address: 0x220670, Func Offset: 0xc0
	// Line 1164, Address: 0x220680, Func Offset: 0xd0
	// Line 1165, Address: 0x220688, Func Offset: 0xd8
	// Line 1166, Address: 0x220690, Func Offset: 0xe0
	// Line 1171, Address: 0x220698, Func Offset: 0xe8
	// Line 1172, Address: 0x2206a4, Func Offset: 0xf4
	// Line 1171, Address: 0x2206a8, Func Offset: 0xf8
	// Line 1172, Address: 0x2206ac, Func Offset: 0xfc
	// Line 1178, Address: 0x2206b0, Func Offset: 0x100
	// Line 1179, Address: 0x2206bc, Func Offset: 0x10c
	// Line 1180, Address: 0x2206cc, Func Offset: 0x11c
	// Line 1181, Address: 0x2206dc, Func Offset: 0x12c
	// Line 1182, Address: 0x2206ec, Func Offset: 0x13c
	// Line 1186, Address: 0x2206fc, Func Offset: 0x14c
	// Line 1187, Address: 0x220704, Func Offset: 0x154
	// Line 1186, Address: 0x22070c, Func Offset: 0x15c
	// Line 1187, Address: 0x220714, Func Offset: 0x164
	// Line 1189, Address: 0x220728, Func Offset: 0x178
	// Line 1190, Address: 0x220730, Func Offset: 0x180
	// Line 1193, Address: 0x22074c, Func Offset: 0x19c
	// Line 1194, Address: 0x220770, Func Offset: 0x1c0
	// Line 1195, Address: 0x220780, Func Offset: 0x1d0
	// Line 1196, Address: 0x220788, Func Offset: 0x1d8
	// Line 1197, Address: 0x220790, Func Offset: 0x1e0
	// Line 1199, Address: 0x220798, Func Offset: 0x1e8
	// Line 1200, Address: 0x2207bc, Func Offset: 0x20c
	// Line 1201, Address: 0x2207c0, Func Offset: 0x210
	// Line 1205, Address: 0x2207c8, Func Offset: 0x218
	// Line 1206, Address: 0x2207e4, Func Offset: 0x234
	// Line 1207, Address: 0x2207e8, Func Offset: 0x238
	// Line 1206, Address: 0x2207ec, Func Offset: 0x23c
	// Line 1207, Address: 0x2207f4, Func Offset: 0x244
	// Line 1208, Address: 0x220828, Func Offset: 0x278
	// Func End, Address: 0x220838, Func Offset: 0x288
}

// 
// Start address: 0x220840
void bhEff164(_anon0* op)
{
	// Line 1217, Address: 0x220840, Func Offset: 0
	// Line 1219, Address: 0x22084c, Func Offset: 0xc
	// Line 1222, Address: 0x22085c, Func Offset: 0x1c
	// Line 1223, Address: 0x220874, Func Offset: 0x34
	// Line 1224, Address: 0x22087c, Func Offset: 0x3c
	// Line 1226, Address: 0x220880, Func Offset: 0x40
	// Line 1227, Address: 0x220898, Func Offset: 0x58
	// Line 1230, Address: 0x2208a0, Func Offset: 0x60
	// Line 1231, Address: 0x2208ac, Func Offset: 0x6c
	// Line 1233, Address: 0x2208bc, Func Offset: 0x7c
	// Line 1234, Address: 0x2208c8, Func Offset: 0x88
	// Line 1235, Address: 0x2208d4, Func Offset: 0x94
	// Line 1239, Address: 0x2208d8, Func Offset: 0x98
	// Func End, Address: 0x2208e8, Func Offset: 0xa8
}

// 
// Start address: 0x2208f0
void bhEff165(_anon0* op)
{
	_anon24 vd;
	_anon24 vs;
	float py;
	// Line 1248, Address: 0x2208f0, Func Offset: 0
	// Line 1253, Address: 0x2208fc, Func Offset: 0xc
	// Line 1256, Address: 0x22090c, Func Offset: 0x1c
	// Line 1257, Address: 0x220924, Func Offset: 0x34
	// Line 1258, Address: 0x22092c, Func Offset: 0x3c
	// Line 1260, Address: 0x220930, Func Offset: 0x40
	// Line 1261, Address: 0x220948, Func Offset: 0x58
	// Line 1263, Address: 0x220954, Func Offset: 0x64
	// Line 1264, Address: 0x22095c, Func Offset: 0x6c
	// Line 1265, Address: 0x220960, Func Offset: 0x70
	// Line 1266, Address: 0x22096c, Func Offset: 0x7c
	// Line 1267, Address: 0x220980, Func Offset: 0x90
	// Line 1268, Address: 0x220990, Func Offset: 0xa0
	// Line 1269, Address: 0x220998, Func Offset: 0xa8
	// Line 1270, Address: 0x2209a0, Func Offset: 0xb0
	// Line 1271, Address: 0x2209a8, Func Offset: 0xb8
	// Line 1273, Address: 0x2209ac, Func Offset: 0xbc
	// Line 1274, Address: 0x2209b4, Func Offset: 0xc4
	// Line 1275, Address: 0x2209bc, Func Offset: 0xcc
	// Line 1276, Address: 0x2209c4, Func Offset: 0xd4
	// Line 1277, Address: 0x2209cc, Func Offset: 0xdc
	// Line 1278, Address: 0x2209d4, Func Offset: 0xe4
	// Line 1281, Address: 0x2209dc, Func Offset: 0xec
	// Line 1282, Address: 0x2209e8, Func Offset: 0xf8
	// Line 1283, Address: 0x2209f4, Func Offset: 0x104
	// Line 1286, Address: 0x220a04, Func Offset: 0x114
	// Line 1291, Address: 0x220a0c, Func Offset: 0x11c
	// Line 1296, Address: 0x220a18, Func Offset: 0x128
	// Line 1286, Address: 0x220a1c, Func Offset: 0x12c
	// Line 1296, Address: 0x220a20, Func Offset: 0x130
	// Line 1286, Address: 0x220a30, Func Offset: 0x140
	// Line 1287, Address: 0x220a34, Func Offset: 0x144
	// Line 1288, Address: 0x220a44, Func Offset: 0x154
	// Line 1290, Address: 0x220a54, Func Offset: 0x164
	// Line 1291, Address: 0x220a64, Func Offset: 0x174
	// Line 1296, Address: 0x220a70, Func Offset: 0x180
	// Line 1297, Address: 0x220a7c, Func Offset: 0x18c
	// Line 1298, Address: 0x220a84, Func Offset: 0x194
	// Line 1299, Address: 0x220a88, Func Offset: 0x198
	// Line 1300, Address: 0x220a94, Func Offset: 0x1a4
	// Line 1301, Address: 0x220aa8, Func Offset: 0x1b8
	// Line 1302, Address: 0x220ab8, Func Offset: 0x1c8
	// Line 1312, Address: 0x220abc, Func Offset: 0x1cc
	// Line 1302, Address: 0x220ac0, Func Offset: 0x1d0
	// Line 1303, Address: 0x220ac4, Func Offset: 0x1d4
	// Line 1304, Address: 0x220acc, Func Offset: 0x1dc
	// Line 1312, Address: 0x220ad0, Func Offset: 0x1e0
	// Line 1313, Address: 0x220ad8, Func Offset: 0x1e8
	// Line 1314, Address: 0x220aec, Func Offset: 0x1fc
	// Line 1315, Address: 0x220b08, Func Offset: 0x218
	// Line 1317, Address: 0x220b20, Func Offset: 0x230
	// Line 1318, Address: 0x220b28, Func Offset: 0x238
	// Line 1319, Address: 0x220b38, Func Offset: 0x248
	// Line 1327, Address: 0x220b3c, Func Offset: 0x24c
	// Line 1328, Address: 0x220b48, Func Offset: 0x258
	// Line 1329, Address: 0x220b54, Func Offset: 0x264
	// Line 1331, Address: 0x220b58, Func Offset: 0x268
	// Line 1332, Address: 0x220b60, Func Offset: 0x270
	// Line 1333, Address: 0x220b68, Func Offset: 0x278
	// Line 1334, Address: 0x220b70, Func Offset: 0x280
	// Line 1335, Address: 0x220b78, Func Offset: 0x288
	// Line 1336, Address: 0x220b80, Func Offset: 0x290
	// Line 1340, Address: 0x220b88, Func Offset: 0x298
	// Func End, Address: 0x220b98, Func Offset: 0x2a8
}

// 
// Start address: 0x220ba0
void bhEff166(_anon0* op)
{
	// Line 1349, Address: 0x220ba0, Func Offset: 0
	// Line 1350, Address: 0x220bac, Func Offset: 0xc
	// Line 1352, Address: 0x220bbc, Func Offset: 0x1c
	// Line 1353, Address: 0x220bdc, Func Offset: 0x3c
	// Line 1355, Address: 0x220be8, Func Offset: 0x48
	// Line 1356, Address: 0x220c00, Func Offset: 0x60
	// Line 1359, Address: 0x220c10, Func Offset: 0x70
	// Line 1357, Address: 0x220c14, Func Offset: 0x74
	// Line 1359, Address: 0x220c18, Func Offset: 0x78
	// Line 1361, Address: 0x220c1c, Func Offset: 0x7c
	// Line 1364, Address: 0x220c28, Func Offset: 0x88
	// Func End, Address: 0x220c38, Func Offset: 0x98
}

// 
// Start address: 0x220c40
void bhEff167(_anon0* op)
{
	_anon3* uvp;
	_anon3 uvinfo_e29[14];
	// Line 1373, Address: 0x220c40, Func Offset: 0
	// Line 1396, Address: 0x220c4c, Func Offset: 0xc
	// Line 1398, Address: 0x220c60, Func Offset: 0x20
	// Line 1399, Address: 0x220c64, Func Offset: 0x24
	// Line 1401, Address: 0x220c6c, Func Offset: 0x2c
	// Line 1402, Address: 0x220c74, Func Offset: 0x34
	// Line 1403, Address: 0x220c8c, Func Offset: 0x4c
	// Line 1407, Address: 0x220c98, Func Offset: 0x58
	// Line 1408, Address: 0x220ca4, Func Offset: 0x64
	// Line 1414, Address: 0x220cac, Func Offset: 0x6c
	// Line 1415, Address: 0x220cb4, Func Offset: 0x74
	// Line 1414, Address: 0x220cbc, Func Offset: 0x7c
	// Line 1415, Address: 0x220cc4, Func Offset: 0x84
	// Line 1417, Address: 0x220cd8, Func Offset: 0x98
	// Line 1420, Address: 0x220ce0, Func Offset: 0xa0
	// Line 1421, Address: 0x220cec, Func Offset: 0xac
	// Line 1422, Address: 0x220cf0, Func Offset: 0xb0
	// Line 1421, Address: 0x220cf4, Func Offset: 0xb4
	// Line 1422, Address: 0x220cfc, Func Offset: 0xbc
	// Line 1423, Address: 0x220d30, Func Offset: 0xf0
	// Func End, Address: 0x220d40, Func Offset: 0x100
}

// 
// Start address: 0x220d40
void bhEff168(_anon0* op)
{
	// Line 1432, Address: 0x220d40, Func Offset: 0
	// Line 1433, Address: 0x220d4c, Func Offset: 0xc
	// Line 1435, Address: 0x220d5c, Func Offset: 0x1c
	// Line 1436, Address: 0x220d7c, Func Offset: 0x3c
	// Line 1437, Address: 0x220d88, Func Offset: 0x48
	// Line 1438, Address: 0x220da0, Func Offset: 0x60
	// Line 1439, Address: 0x220da4, Func Offset: 0x64
	// Line 1442, Address: 0x220da8, Func Offset: 0x68
	// Func End, Address: 0x220db8, Func Offset: 0x78
}

// 
// Start address: 0x220dc0
void bhEff169(_anon0* op)
{
	_anon3* uvp;
	_anon3 uvinfo_e23_0[11];
	_anon3 uvinfo_e23_1[15];
	// Line 1451, Address: 0x220dc0, Func Offset: 0
	// Line 1486, Address: 0x220dcc, Func Offset: 0xc
	// Line 1488, Address: 0x220de0, Func Offset: 0x20
	// Line 1489, Address: 0x220de4, Func Offset: 0x24
	// Line 1491, Address: 0x220dec, Func Offset: 0x2c
	// Line 1492, Address: 0x220df4, Func Offset: 0x34
	// Line 1494, Address: 0x220e0c, Func Offset: 0x4c
	// Line 1496, Address: 0x220e30, Func Offset: 0x70
	// Line 1497, Address: 0x220e3c, Func Offset: 0x7c
	// Line 1498, Address: 0x220e48, Func Offset: 0x88
	// Line 1500, Address: 0x220e50, Func Offset: 0x90
	// Line 1501, Address: 0x220e58, Func Offset: 0x98
	// Line 1500, Address: 0x220e5c, Func Offset: 0x9c
	// Line 1501, Address: 0x220e60, Func Offset: 0xa0
	// Line 1502, Address: 0x220e68, Func Offset: 0xa8
	// Line 1504, Address: 0x220e70, Func Offset: 0xb0
	// Line 1506, Address: 0x220e7c, Func Offset: 0xbc
	// Line 1509, Address: 0x220e8c, Func Offset: 0xcc
	// Line 1515, Address: 0x220e94, Func Offset: 0xd4
	// Line 1516, Address: 0x220e9c, Func Offset: 0xdc
	// Line 1515, Address: 0x220ea4, Func Offset: 0xe4
	// Line 1516, Address: 0x220eac, Func Offset: 0xec
	// Line 1518, Address: 0x220ec0, Func Offset: 0x100
	// Line 1522, Address: 0x220ec8, Func Offset: 0x108
	// Line 1523, Address: 0x220ed4, Func Offset: 0x114
	// Line 1524, Address: 0x220ed8, Func Offset: 0x118
	// Line 1523, Address: 0x220edc, Func Offset: 0x11c
	// Line 1524, Address: 0x220ee4, Func Offset: 0x124
	// Line 1525, Address: 0x220f18, Func Offset: 0x158
	// Func End, Address: 0x220f28, Func Offset: 0x168
}

// 
// Start address: 0x220f30
void bhEff170(_anon0* op)
{
	_anon24 vd;
	_anon24 vs;
	float py;
	// Line 1534, Address: 0x220f30, Func Offset: 0
	// Line 1539, Address: 0x220f3c, Func Offset: 0xc
	// Line 1542, Address: 0x220f4c, Func Offset: 0x1c
	// Line 1543, Address: 0x220f64, Func Offset: 0x34
	// Line 1544, Address: 0x220f6c, Func Offset: 0x3c
	// Line 1546, Address: 0x220f70, Func Offset: 0x40
	// Line 1547, Address: 0x220f88, Func Offset: 0x58
	// Line 1549, Address: 0x220f94, Func Offset: 0x64
	// Line 1550, Address: 0x220f9c, Func Offset: 0x6c
	// Line 1551, Address: 0x220fa0, Func Offset: 0x70
	// Line 1552, Address: 0x220fac, Func Offset: 0x7c
	// Line 1553, Address: 0x220fc0, Func Offset: 0x90
	// Line 1554, Address: 0x220fd0, Func Offset: 0xa0
	// Line 1555, Address: 0x220fd8, Func Offset: 0xa8
	// Line 1556, Address: 0x220fe0, Func Offset: 0xb0
	// Line 1557, Address: 0x220fe8, Func Offset: 0xb8
	// Line 1559, Address: 0x220fec, Func Offset: 0xbc
	// Line 1560, Address: 0x220ff4, Func Offset: 0xc4
	// Line 1561, Address: 0x220ffc, Func Offset: 0xcc
	// Line 1562, Address: 0x221004, Func Offset: 0xd4
	// Line 1563, Address: 0x22100c, Func Offset: 0xdc
	// Line 1564, Address: 0x221014, Func Offset: 0xe4
	// Line 1565, Address: 0x22101c, Func Offset: 0xec
	// Line 1566, Address: 0x221020, Func Offset: 0xf0
	// Line 1567, Address: 0x221024, Func Offset: 0xf4
	// Line 1570, Address: 0x221028, Func Offset: 0xf8
	// Line 1571, Address: 0x221034, Func Offset: 0x104
	// Line 1572, Address: 0x221040, Func Offset: 0x110
	// Line 1575, Address: 0x221050, Func Offset: 0x120
	// Line 1589, Address: 0x221058, Func Offset: 0x128
	// Line 1575, Address: 0x22106c, Func Offset: 0x13c
	// Line 1576, Address: 0x221074, Func Offset: 0x144
	// Line 1577, Address: 0x221084, Func Offset: 0x154
	// Line 1578, Address: 0x221094, Func Offset: 0x164
	// Line 1580, Address: 0x2210a4, Func Offset: 0x174
	// Line 1581, Address: 0x2210b4, Func Offset: 0x184
	// Line 1582, Address: 0x2210c4, Func Offset: 0x194
	// Line 1583, Address: 0x2210d4, Func Offset: 0x1a4
	// Line 1589, Address: 0x2210e4, Func Offset: 0x1b4
	// Line 1590, Address: 0x2210f0, Func Offset: 0x1c0
	// Line 1591, Address: 0x2210f8, Func Offset: 0x1c8
	// Line 1592, Address: 0x2210fc, Func Offset: 0x1cc
	// Line 1593, Address: 0x221108, Func Offset: 0x1d8
	// Line 1594, Address: 0x22111c, Func Offset: 0x1ec
	// Line 1595, Address: 0x22112c, Func Offset: 0x1fc
	// Line 1605, Address: 0x221130, Func Offset: 0x200
	// Line 1595, Address: 0x221134, Func Offset: 0x204
	// Line 1596, Address: 0x221138, Func Offset: 0x208
	// Line 1597, Address: 0x221140, Func Offset: 0x210
	// Line 1605, Address: 0x221144, Func Offset: 0x214
	// Line 1606, Address: 0x22114c, Func Offset: 0x21c
	// Line 1607, Address: 0x221160, Func Offset: 0x230
	// Line 1608, Address: 0x22117c, Func Offset: 0x24c
	// Line 1610, Address: 0x221194, Func Offset: 0x264
	// Line 1611, Address: 0x22119c, Func Offset: 0x26c
	// Line 1612, Address: 0x2211ac, Func Offset: 0x27c
	// Line 1620, Address: 0x2211b0, Func Offset: 0x280
	// Line 1622, Address: 0x2211cc, Func Offset: 0x29c
	// Line 1623, Address: 0x2211d8, Func Offset: 0x2a8
	// Line 1624, Address: 0x2211e4, Func Offset: 0x2b4
	// Line 1626, Address: 0x2211e8, Func Offset: 0x2b8
	// Line 1627, Address: 0x2211f0, Func Offset: 0x2c0
	// Line 1628, Address: 0x2211f8, Func Offset: 0x2c8
	// Line 1629, Address: 0x221200, Func Offset: 0x2d0
	// Line 1630, Address: 0x221208, Func Offset: 0x2d8
	// Line 1631, Address: 0x221210, Func Offset: 0x2e0
	// Line 1641, Address: 0x221218, Func Offset: 0x2e8
	// Func End, Address: 0x221228, Func Offset: 0x2f8
}

// 
// Start address: 0x221230
void bhEff171(_anon0* op)
{
	_anon3* uvp;
	_anon3 uvinfo_sw_0[11];
	// Line 1650, Address: 0x221230, Func Offset: 0
	// Line 1667, Address: 0x22123c, Func Offset: 0xc
	// Line 1669, Address: 0x221250, Func Offset: 0x20
	// Line 1670, Address: 0x221254, Func Offset: 0x24
	// Line 1672, Address: 0x22125c, Func Offset: 0x2c
	// Line 1673, Address: 0x221268, Func Offset: 0x38
	// Line 1675, Address: 0x22126c, Func Offset: 0x3c
	// Line 1673, Address: 0x221270, Func Offset: 0x40
	// Line 1675, Address: 0x221274, Func Offset: 0x44
	// Line 1681, Address: 0x221278, Func Offset: 0x48
	// Line 1682, Address: 0x221280, Func Offset: 0x50
	// Line 1681, Address: 0x221288, Func Offset: 0x58
	// Line 1682, Address: 0x221290, Func Offset: 0x60
	// Line 1683, Address: 0x2212a4, Func Offset: 0x74
	// Line 1684, Address: 0x2212b0, Func Offset: 0x80
	// Line 1685, Address: 0x2212bc, Func Offset: 0x8c
	// Line 1686, Address: 0x2212c0, Func Offset: 0x90
	// Line 1687, Address: 0x2212cc, Func Offset: 0x9c
	// Line 1689, Address: 0x2212d4, Func Offset: 0xa4
	// Line 1693, Address: 0x2212dc, Func Offset: 0xac
	// Line 1694, Address: 0x2212e8, Func Offset: 0xb8
	// Line 1695, Address: 0x2212ec, Func Offset: 0xbc
	// Line 1694, Address: 0x2212f0, Func Offset: 0xc0
	// Line 1695, Address: 0x2212f8, Func Offset: 0xc8
	// Line 1696, Address: 0x22132c, Func Offset: 0xfc
	// Func End, Address: 0x22133c, Func Offset: 0x10c
}

// 
// Start address: 0x221340
void bhEff172(_anon0* op)
{
	// Line 1705, Address: 0x221340, Func Offset: 0
	// Line 1706, Address: 0x22134c, Func Offset: 0xc
	// Line 1708, Address: 0x22135c, Func Offset: 0x1c
	// Line 1709, Address: 0x22137c, Func Offset: 0x3c
	// Line 1710, Address: 0x221388, Func Offset: 0x48
	// Line 1711, Address: 0x2213a0, Func Offset: 0x60
	// Line 1712, Address: 0x2213a4, Func Offset: 0x64
	// Line 1715, Address: 0x2213a8, Func Offset: 0x68
	// Func End, Address: 0x2213b8, Func Offset: 0x78
}

// 
// Start address: 0x2213c0
void bhEff173(_anon0* op)
{
	_anon3* uvp;
	int bltbl[10];
	_anon3 uvinfo_e23_0[2];
	// Line 1724, Address: 0x2213c0, Func Offset: 0
	// Line 1746, Address: 0x2213cc, Func Offset: 0xc
	// Line 1748, Address: 0x2213e0, Func Offset: 0x20
	// Line 1749, Address: 0x2213e4, Func Offset: 0x24
	// Line 1751, Address: 0x2213ec, Func Offset: 0x2c
	// Line 1752, Address: 0x2213f8, Func Offset: 0x38
	// Line 1756, Address: 0x221400, Func Offset: 0x40
	// Line 1757, Address: 0x221418, Func Offset: 0x58
	// Line 1756, Address: 0x22141c, Func Offset: 0x5c
	// Line 1757, Address: 0x221424, Func Offset: 0x64
	// Line 1756, Address: 0x221428, Func Offset: 0x68
	// Line 1757, Address: 0x22143c, Func Offset: 0x7c
	// Line 1758, Address: 0x221440, Func Offset: 0x80
	// Line 1764, Address: 0x221444, Func Offset: 0x84
	// Line 1756, Address: 0x22144c, Func Offset: 0x8c
	// Line 1757, Address: 0x221450, Func Offset: 0x90
	// Line 1758, Address: 0x221474, Func Offset: 0xb4
	// Line 1759, Address: 0x221478, Func Offset: 0xb8
	// Line 1763, Address: 0x22147c, Func Offset: 0xbc
	// Line 1764, Address: 0x22148c, Func Offset: 0xcc
	// Line 1765, Address: 0x2214a0, Func Offset: 0xe0
	// Line 1766, Address: 0x2214a4, Func Offset: 0xe4
	// Line 1769, Address: 0x2214b4, Func Offset: 0xf4
	// Line 1770, Address: 0x2214c0, Func Offset: 0x100
	// Line 1771, Address: 0x2214c4, Func Offset: 0x104
	// Line 1770, Address: 0x2214c8, Func Offset: 0x108
	// Line 1771, Address: 0x2214d0, Func Offset: 0x110
	// Line 1772, Address: 0x221504, Func Offset: 0x144
	// Func End, Address: 0x221514, Func Offset: 0x154
}

// 
// Start address: 0x221520
void bhEff174()
{
	// Line 1783, Address: 0x221520, Func Offset: 0
	// Func End, Address: 0x221528, Func Offset: 0x8
}

// 
// Start address: 0x221530
void bhEff175(_anon0* op)
{
	// Line 1792, Address: 0x221530, Func Offset: 0
	// Line 1793, Address: 0x22153c, Func Offset: 0xc
	// Line 1795, Address: 0x22154c, Func Offset: 0x1c
	// Line 1796, Address: 0x22156c, Func Offset: 0x3c
	// Line 1797, Address: 0x221578, Func Offset: 0x48
	// Line 1798, Address: 0x221588, Func Offset: 0x58
	// Line 1799, Address: 0x22158c, Func Offset: 0x5c
	// Line 1802, Address: 0x221590, Func Offset: 0x60
	// Func End, Address: 0x2215a0, Func Offset: 0x70
}

// 
// Start address: 0x2215a0
void bhEff176(_anon0* op)
{
	_anon3 uvinfo_moon[1];
	// Line 1811, Address: 0x2215a0, Func Offset: 0
	// Line 1819, Address: 0x2215ac, Func Offset: 0xc
	// Line 1821, Address: 0x2215c0, Func Offset: 0x20
	// Line 1822, Address: 0x2215c4, Func Offset: 0x24
	// Line 1824, Address: 0x2215cc, Func Offset: 0x2c
	// Line 1825, Address: 0x2215d8, Func Offset: 0x38
	// Line 1833, Address: 0x2215e0, Func Offset: 0x40
	// Line 1834, Address: 0x2215fc, Func Offset: 0x5c
	// Line 1835, Address: 0x221634, Func Offset: 0x94
	// Func End, Address: 0x221644, Func Offset: 0xa4
}

// 
// Start address: 0x221650
void bhEff177(_anon0* op)
{
	int lNumber;
	// Line 1844, Address: 0x221650, Func Offset: 0
	// Line 1848, Address: 0x22165c, Func Offset: 0xc
	// Line 1850, Address: 0x22166c, Func Offset: 0x1c
	// Line 1851, Address: 0x22168c, Func Offset: 0x3c
	// Line 1852, Address: 0x221698, Func Offset: 0x48
	// Line 1853, Address: 0x2216b0, Func Offset: 0x60
	// Line 1855, Address: 0x2216bc, Func Offset: 0x6c
	// Line 1857, Address: 0x2216e4, Func Offset: 0x94
	// Line 1858, Address: 0x2216e8, Func Offset: 0x98
	// Line 1861, Address: 0x2216ec, Func Offset: 0x9c
	// Func End, Address: 0x2216fc, Func Offset: 0xac
}

// 
// Start address: 0x221700
void bhEff178(_anon0* op)
{
	_anon3* uvp;
	_anon24 vd;
	_anon24 vs;
	_anon3 uvinfo_hiko[7];
	// Line 1870, Address: 0x221700, Func Offset: 0
	// Line 1893, Address: 0x22170c, Func Offset: 0xc
	// Line 1895, Address: 0x221720, Func Offset: 0x20
	// Line 1896, Address: 0x221724, Func Offset: 0x24
	// Line 1898, Address: 0x22172c, Func Offset: 0x2c
	// Line 1899, Address: 0x221734, Func Offset: 0x34
	// Line 1903, Address: 0x221748, Func Offset: 0x48
	// Line 1899, Address: 0x22174c, Func Offset: 0x4c
	// Line 1903, Address: 0x221750, Func Offset: 0x50
	// Line 1901, Address: 0x221754, Func Offset: 0x54
	// Line 1903, Address: 0x221758, Func Offset: 0x58
	// Line 1904, Address: 0x22175c, Func Offset: 0x5c
	// Line 1910, Address: 0x221764, Func Offset: 0x64
	// Line 1911, Address: 0x221770, Func Offset: 0x70
	// Line 1914, Address: 0x221784, Func Offset: 0x84
	// Line 1917, Address: 0x22178c, Func Offset: 0x8c
	// Line 1918, Address: 0x221794, Func Offset: 0x94
	// Line 1919, Address: 0x221798, Func Offset: 0x98
	// Line 1920, Address: 0x2217a4, Func Offset: 0xa4
	// Line 1921, Address: 0x2217b8, Func Offset: 0xb8
	// Line 1922, Address: 0x2217c8, Func Offset: 0xc8
	// Line 1927, Address: 0x2217d0, Func Offset: 0xd0
	// Line 1922, Address: 0x2217dc, Func Offset: 0xdc
	// Line 1923, Address: 0x2217e4, Func Offset: 0xe4
	// Line 1924, Address: 0x2217f4, Func Offset: 0xf4
	// Line 1926, Address: 0x221804, Func Offset: 0x104
	// Line 1927, Address: 0x221814, Func Offset: 0x114
	// Line 1928, Address: 0x221828, Func Offset: 0x128
	// Line 1929, Address: 0x22182c, Func Offset: 0x12c
	// Line 1932, Address: 0x22183c, Func Offset: 0x13c
	// Line 1933, Address: 0x221848, Func Offset: 0x148
	// Line 1934, Address: 0x22184c, Func Offset: 0x14c
	// Line 1933, Address: 0x221850, Func Offset: 0x150
	// Line 1934, Address: 0x221858, Func Offset: 0x158
	// Line 1935, Address: 0x22188c, Func Offset: 0x18c
	// Func End, Address: 0x22189c, Func Offset: 0x19c
}

// 
// Start address: 0x2218a0
void bhEff179(_anon0* op)
{
	// Line 1944, Address: 0x2218a0, Func Offset: 0
	// Line 1945, Address: 0x2218ac, Func Offset: 0xc
	// Line 1947, Address: 0x2218bc, Func Offset: 0x1c
	// Line 1949, Address: 0x2218dc, Func Offset: 0x3c
	// Line 1950, Address: 0x2218e8, Func Offset: 0x48
	// Line 1951, Address: 0x221904, Func Offset: 0x64
	// Line 1952, Address: 0x22191c, Func Offset: 0x7c
	// Line 1954, Address: 0x221920, Func Offset: 0x80
	// Line 1955, Address: 0x221928, Func Offset: 0x88
	// Line 1956, Address: 0x221934, Func Offset: 0x94
	// Line 1957, Address: 0x22194c, Func Offset: 0xac
	// Line 1959, Address: 0x221958, Func Offset: 0xb8
	// Line 1963, Address: 0x221964, Func Offset: 0xc4
	// Func End, Address: 0x221974, Func Offset: 0xd4
}

// 
// Start address: 0x221980
void bhEff180(_anon0* op)
{
	_anon3* uvp;
	_anon3 uvinfo_hiba2_0[11];
	_anon3 uvinfo_hiba2_1[11];
	// Line 1972, Address: 0x221980, Func Offset: 0
	// Line 2004, Address: 0x22198c, Func Offset: 0xc
	// Line 2006, Address: 0x2219a0, Func Offset: 0x20
	// Line 2007, Address: 0x2219a4, Func Offset: 0x24
	// Line 2010, Address: 0x2219ac, Func Offset: 0x2c
	// Line 2012, Address: 0x2219c4, Func Offset: 0x44
	// Line 2015, Address: 0x2219d0, Func Offset: 0x50
	// Line 2017, Address: 0x2219d8, Func Offset: 0x58
	// Line 2020, Address: 0x2219e4, Func Offset: 0x64
	// Line 2028, Address: 0x2219ec, Func Offset: 0x6c
	// Line 2029, Address: 0x2219f4, Func Offset: 0x74
	// Line 2028, Address: 0x2219fc, Func Offset: 0x7c
	// Line 2029, Address: 0x221a04, Func Offset: 0x84
	// Line 2031, Address: 0x221a18, Func Offset: 0x98
	// Line 2034, Address: 0x221a20, Func Offset: 0xa0
	// Line 2035, Address: 0x221a2c, Func Offset: 0xac
	// Line 2036, Address: 0x221a30, Func Offset: 0xb0
	// Line 2035, Address: 0x221a34, Func Offset: 0xb4
	// Line 2036, Address: 0x221a3c, Func Offset: 0xbc
	// Line 2037, Address: 0x221a70, Func Offset: 0xf0
	// Func End, Address: 0x221a80, Func Offset: 0x100
}

// 
// Start address: 0x221a80
void bhEff181(_anon0* op)
{
	unsigned short typ;
	// Line 2046, Address: 0x221a80, Func Offset: 0
	// Line 2048, Address: 0x221a90, Func Offset: 0x10
	// Line 2050, Address: 0x221aa0, Func Offset: 0x20
	// Line 2052, Address: 0x221ac0, Func Offset: 0x40
	// Line 2054, Address: 0x221acc, Func Offset: 0x4c
	// Line 2053, Address: 0x221ad0, Func Offset: 0x50
	// Line 2054, Address: 0x221ad4, Func Offset: 0x54
	// Line 2055, Address: 0x221af4, Func Offset: 0x74
	// Line 2056, Address: 0x221b04, Func Offset: 0x84
	// Line 2058, Address: 0x221b08, Func Offset: 0x88
	// Line 2059, Address: 0x221b10, Func Offset: 0x90
	// Line 2060, Address: 0x221b1c, Func Offset: 0x9c
	// Line 2061, Address: 0x221b2c, Func Offset: 0xac
	// Line 2063, Address: 0x221b40, Func Offset: 0xc0
	// Line 2067, Address: 0x221b4c, Func Offset: 0xcc
	// Func End, Address: 0x221b60, Func Offset: 0xe0
}

// 
// Start address: 0x221b60
void bhEff182(_anon0* op)
{
	_anon3* uvp;
	_anon24 vd;
	_anon24 vs;
	unsigned short kcolor;
	unsigned short ktype;
	_anon3* uvinfo_kemu[10];
	int texid_kemu[10];
	// Line 2076, Address: 0x221b60, Func Offset: 0
	// Line 2320, Address: 0x221b74, Func Offset: 0x14
	// Line 2322, Address: 0x221b7c, Func Offset: 0x1c
	// Line 2321, Address: 0x221b80, Func Offset: 0x20
	// Line 2320, Address: 0x221b8c, Func Offset: 0x2c
	// Line 2321, Address: 0x221b9c, Func Offset: 0x3c
	// Line 2320, Address: 0x221ba4, Func Offset: 0x44
	// Line 2321, Address: 0x221bac, Func Offset: 0x4c
	// Line 2322, Address: 0x221bb8, Func Offset: 0x58
	// Line 2324, Address: 0x221bc8, Func Offset: 0x68
	// Line 2325, Address: 0x221be0, Func Offset: 0x80
	// Line 2326, Address: 0x221be8, Func Offset: 0x88
	// Line 2327, Address: 0x221bf8, Func Offset: 0x98
	// Line 2326, Address: 0x221bfc, Func Offset: 0x9c
	// Line 2327, Address: 0x221c00, Func Offset: 0xa0
	// Line 2332, Address: 0x221c04, Func Offset: 0xa4
	// Line 2333, Address: 0x221c0c, Func Offset: 0xac
	// Line 2334, Address: 0x221c18, Func Offset: 0xb8
	// Line 2335, Address: 0x221c20, Func Offset: 0xc0
	// Line 2336, Address: 0x221c34, Func Offset: 0xd4
	// Line 2337, Address: 0x221c44, Func Offset: 0xe4
	// Line 2343, Address: 0x221c4c, Func Offset: 0xec
	// Line 2337, Address: 0x221c58, Func Offset: 0xf8
	// Line 2338, Address: 0x221c60, Func Offset: 0x100
	// Line 2339, Address: 0x221c70, Func Offset: 0x110
	// Line 2342, Address: 0x221c80, Func Offset: 0x120
	// Line 2343, Address: 0x221c90, Func Offset: 0x130
	// Line 2345, Address: 0x221ca4, Func Offset: 0x144
	// Line 2348, Address: 0x221cac, Func Offset: 0x14c
	// Line 2349, Address: 0x221cb8, Func Offset: 0x158
	// Line 2350, Address: 0x221cbc, Func Offset: 0x15c
	// Line 2349, Address: 0x221cc0, Func Offset: 0x160
	// Line 2350, Address: 0x221cc8, Func Offset: 0x168
	// Line 2351, Address: 0x221cfc, Func Offset: 0x19c
	// Func End, Address: 0x221d14, Func Offset: 0x1b4
}

// 
// Start address: 0x221d20
void bhEff183(_anon0* op)
{
	// Line 2360, Address: 0x221d20, Func Offset: 0
	// Line 2361, Address: 0x221d28, Func Offset: 0x8
	// Line 2363, Address: 0x221d38, Func Offset: 0x18
	// Line 2364, Address: 0x221d58, Func Offset: 0x38
	// Line 2365, Address: 0x221d64, Func Offset: 0x44
	// Line 2370, Address: 0x221d78, Func Offset: 0x58
	// Func End, Address: 0x221d84, Func Offset: 0x64
}

// 
// Start address: 0x221d90
void bhEff184(_anon0* op)
{
	_anon24 vd;
	_anon24 vs;
	_anon3* uvp;
	_anon3 uvinfo_mizu_0[16];
	// Line 2379, Address: 0x221d90, Func Offset: 0
	// Line 2402, Address: 0x221da0, Func Offset: 0x10
	// Line 2404, Address: 0x221db4, Func Offset: 0x24
	// Line 2405, Address: 0x221db8, Func Offset: 0x28
	// Line 2407, Address: 0x221dc0, Func Offset: 0x30
	// Line 2409, Address: 0x221dcc, Func Offset: 0x3c
	// Line 2410, Address: 0x221dd4, Func Offset: 0x44
	// Line 2412, Address: 0x221de0, Func Offset: 0x50
	// Line 2410, Address: 0x221de4, Func Offset: 0x54
	// Line 2412, Address: 0x221df0, Func Offset: 0x60
	// Line 2413, Address: 0x221df8, Func Offset: 0x68
	// Line 2414, Address: 0x221e0c, Func Offset: 0x7c
	// Line 2415, Address: 0x221e1c, Func Offset: 0x8c
	// Line 2419, Address: 0x221e20, Func Offset: 0x90
	// Line 2421, Address: 0x221e28, Func Offset: 0x98
	// Line 2422, Address: 0x221e2c, Func Offset: 0x9c
	// Line 2415, Address: 0x221e30, Func Offset: 0xa0
	// Line 2416, Address: 0x221e34, Func Offset: 0xa4
	// Line 2417, Address: 0x221e3c, Func Offset: 0xac
	// Line 2419, Address: 0x221e44, Func Offset: 0xb4
	// Line 2421, Address: 0x221e48, Func Offset: 0xb8
	// Line 2422, Address: 0x221e4c, Func Offset: 0xbc
	// Line 2428, Address: 0x221e50, Func Offset: 0xc0
	// Line 2429, Address: 0x221e60, Func Offset: 0xd0
	// Line 2430, Address: 0x221ed4, Func Offset: 0x144
	// Line 2431, Address: 0x221f48, Func Offset: 0x1b8
	// Line 2434, Address: 0x221f94, Func Offset: 0x204
	// Line 2431, Address: 0x221f98, Func Offset: 0x208
	// Line 2434, Address: 0x221f9c, Func Offset: 0x20c
	// Line 2431, Address: 0x221fa0, Func Offset: 0x210
	// Line 2433, Address: 0x221fc8, Func Offset: 0x238
	// Line 2434, Address: 0x221fd0, Func Offset: 0x240
	// Line 2433, Address: 0x221fd8, Func Offset: 0x248
	// Line 2434, Address: 0x221fe0, Func Offset: 0x250
	// Line 2436, Address: 0x221fec, Func Offset: 0x25c
	// Line 2437, Address: 0x222044, Func Offset: 0x2b4
	// Line 2438, Address: 0x222074, Func Offset: 0x2e4
	// Line 2437, Address: 0x222078, Func Offset: 0x2e8
	// Line 2438, Address: 0x22207c, Func Offset: 0x2ec
	// Line 2439, Address: 0x222080, Func Offset: 0x2f0
	// Line 2440, Address: 0x222098, Func Offset: 0x308
	// Line 2444, Address: 0x2220a4, Func Offset: 0x314
	// Line 2445, Address: 0x2220ac, Func Offset: 0x31c
	// Line 2444, Address: 0x2220b4, Func Offset: 0x324
	// Line 2445, Address: 0x2220bc, Func Offset: 0x32c
	// Line 2447, Address: 0x2220d0, Func Offset: 0x340
	// Line 2448, Address: 0x2220d8, Func Offset: 0x348
	// Line 2450, Address: 0x2220f4, Func Offset: 0x364
	// Line 2451, Address: 0x222118, Func Offset: 0x388
	// Line 2452, Address: 0x222128, Func Offset: 0x398
	// Line 2453, Address: 0x222130, Func Offset: 0x3a0
	// Line 2454, Address: 0x222138, Func Offset: 0x3a8
	// Line 2456, Address: 0x222140, Func Offset: 0x3b0
	// Line 2457, Address: 0x222164, Func Offset: 0x3d4
	// Line 2458, Address: 0x222168, Func Offset: 0x3d8
	// Line 2463, Address: 0x222170, Func Offset: 0x3e0
	// Line 2464, Address: 0x22218c, Func Offset: 0x3fc
	// Line 2465, Address: 0x222190, Func Offset: 0x400
	// Line 2464, Address: 0x222194, Func Offset: 0x404
	// Line 2465, Address: 0x22219c, Func Offset: 0x40c
	// Line 2466, Address: 0x2221d0, Func Offset: 0x440
	// Func End, Address: 0x2221e4, Func Offset: 0x454
}

// 
// Start address: 0x2221f0
void bhEff185(_anon0* op)
{
	_anon3* uvp;
	_anon3 uvinfo_button5[5];
	_anon3 uvinfo_button4[5];
	_anon3 uvinfo_button3[5];
	_anon3 uvinfo_button2[5];
	_anon3 uvinfo_button1[5];
	_anon3 uvinfo_button0[5];
	// Line 2542, Address: 0x2221f0, Func Offset: 0
	// Line 2544, Address: 0x222204, Func Offset: 0x14
	// Line 2545, Address: 0x222208, Func Offset: 0x18
	// Line 2546, Address: 0x222210, Func Offset: 0x20
	// Line 2547, Address: 0x222214, Func Offset: 0x24
	// Line 2545, Address: 0x222218, Func Offset: 0x28
	// Line 2546, Address: 0x222220, Func Offset: 0x30
	// Line 2547, Address: 0x222224, Func Offset: 0x34
	// Line 2548, Address: 0x222228, Func Offset: 0x38
	// Line 2551, Address: 0x22222c, Func Offset: 0x3c
	// Line 2549, Address: 0x222230, Func Offset: 0x40
	// Line 2551, Address: 0x222234, Func Offset: 0x44
	// Line 2554, Address: 0x222238, Func Offset: 0x48
	// Line 2556, Address: 0x222260, Func Offset: 0x70
	// Line 2557, Address: 0x222268, Func Offset: 0x78
	// Line 2559, Address: 0x222270, Func Offset: 0x80
	// Line 2560, Address: 0x222278, Func Offset: 0x88
	// Line 2562, Address: 0x222280, Func Offset: 0x90
	// Line 2563, Address: 0x222288, Func Offset: 0x98
	// Line 2565, Address: 0x222290, Func Offset: 0xa0
	// Line 2566, Address: 0x222298, Func Offset: 0xa8
	// Line 2568, Address: 0x2222a0, Func Offset: 0xb0
	// Line 2569, Address: 0x2222a8, Func Offset: 0xb8
	// Line 2571, Address: 0x2222b0, Func Offset: 0xc0
	// Line 2572, Address: 0x2222b8, Func Offset: 0xc8
	// Line 2574, Address: 0x2222c0, Func Offset: 0xd0
	// Line 2576, Address: 0x2222c8, Func Offset: 0xd8
	// Line 2577, Address: 0x2222d0, Func Offset: 0xe0
	// Line 2589, Address: 0x2222d4, Func Offset: 0xe4
	// Line 2591, Address: 0x2222d8, Func Offset: 0xe8
	// Line 2577, Address: 0x2222dc, Func Offset: 0xec
	// Line 2576, Address: 0x2222e0, Func Offset: 0xf0
	// Line 2578, Address: 0x2222e4, Func Offset: 0xf4
	// Line 2579, Address: 0x2222e8, Func Offset: 0xf8
	// Line 2576, Address: 0x2222ec, Func Offset: 0xfc
	// Line 2580, Address: 0x2222f0, Func Offset: 0x100
	// Line 2581, Address: 0x2222f4, Func Offset: 0x104
	// Line 2582, Address: 0x2222fc, Func Offset: 0x10c
	// Line 2583, Address: 0x222304, Func Offset: 0x114
	// Line 2584, Address: 0x222314, Func Offset: 0x124
	// Line 2585, Address: 0x22231c, Func Offset: 0x12c
	// Line 2586, Address: 0x222324, Func Offset: 0x134
	// Line 2587, Address: 0x222334, Func Offset: 0x144
	// Line 2588, Address: 0x222344, Func Offset: 0x154
	// Line 2589, Address: 0x222354, Func Offset: 0x164
	// Line 2591, Address: 0x222388, Func Offset: 0x198
	// Line 2592, Address: 0x2223a4, Func Offset: 0x1b4
	// Func End, Address: 0x2223ac, Func Offset: 0x1bc
}

// 
// Start address: 0x2223b0
void bhEff186(_anon0* op)
{
	_anon3* uvp;
	_anon3* uvinfo_button[6];
	// Line 2601, Address: 0x2223b0, Func Offset: 0
	// Line 2656, Address: 0x2223c0, Func Offset: 0x10
	// Line 2658, Address: 0x2223d4, Func Offset: 0x24
	// Line 2659, Address: 0x2223d8, Func Offset: 0x28
	// Line 2661, Address: 0x2223e0, Func Offset: 0x30
	// Line 2662, Address: 0x2223f0, Func Offset: 0x40
	// Line 2664, Address: 0x2223f4, Func Offset: 0x44
	// Line 2665, Address: 0x222400, Func Offset: 0x50
	// Line 2666, Address: 0x222418, Func Offset: 0x68
	// Line 2668, Address: 0x222424, Func Offset: 0x74
	// Line 2666, Address: 0x222428, Func Offset: 0x78
	// Line 2668, Address: 0x222438, Func Offset: 0x88
	// Line 2673, Address: 0x22243c, Func Offset: 0x8c
	// Line 2674, Address: 0x222444, Func Offset: 0x94
	// Line 2673, Address: 0x22244c, Func Offset: 0x9c
	// Line 2674, Address: 0x222454, Func Offset: 0xa4
	// Line 2678, Address: 0x222468, Func Offset: 0xb8
	// Line 2681, Address: 0x222470, Func Offset: 0xc0
	// Line 2682, Address: 0x222480, Func Offset: 0xd0
	// Line 2683, Address: 0x222494, Func Offset: 0xe4
	// Line 2685, Address: 0x2224a0, Func Offset: 0xf0
	// Line 2687, Address: 0x2224b0, Func Offset: 0x100
	// Line 2688, Address: 0x2224b4, Func Offset: 0x104
	// Line 2687, Address: 0x2224b8, Func Offset: 0x108
	// Line 2688, Address: 0x2224c0, Func Offset: 0x110
	// Line 2689, Address: 0x2224f4, Func Offset: 0x144
	// Func End, Address: 0x222508, Func Offset: 0x158
}

// 
// Start address: 0x222510
void bhEff187(_anon0* op)
{
	unsigned char dt_interval1[10];
	unsigned char dt_interval0[10];
	// Line 2698, Address: 0x222510, Func Offset: 0
	// Line 2700, Address: 0x222514, Func Offset: 0x4
	// Line 2698, Address: 0x222518, Func Offset: 0x8
	// Line 2700, Address: 0x222520, Func Offset: 0x10
	// Line 2705, Address: 0x222530, Func Offset: 0x20
	// Line 2700, Address: 0x22253c, Func Offset: 0x2c
	// Line 2705, Address: 0x222544, Func Offset: 0x34
	// Line 2711, Address: 0x222548, Func Offset: 0x38
	// Line 2705, Address: 0x22254c, Func Offset: 0x3c
	// Line 2711, Address: 0x222558, Func Offset: 0x48
	// Line 2713, Address: 0x222564, Func Offset: 0x54
	// Line 2715, Address: 0x222584, Func Offset: 0x74
	// Line 2716, Address: 0x222590, Func Offset: 0x80
	// Line 2718, Address: 0x2225c0, Func Offset: 0xb0
	// Line 2719, Address: 0x2225d0, Func Offset: 0xc0
	// Line 2721, Address: 0x2225d4, Func Offset: 0xc4
	// Line 2723, Address: 0x2225dc, Func Offset: 0xcc
	// Line 2724, Address: 0x2225e8, Func Offset: 0xd8
	// Line 2725, Address: 0x2225f8, Func Offset: 0xe8
	// Line 2727, Address: 0x222644, Func Offset: 0x134
	// Line 2728, Address: 0x22264c, Func Offset: 0x13c
	// Line 2730, Address: 0x222654, Func Offset: 0x144
	// Line 2731, Address: 0x222660, Func Offset: 0x150
	// Line 2732, Address: 0x222670, Func Offset: 0x160
	// Line 2734, Address: 0x2226bc, Func Offset: 0x1ac
	// Line 2735, Address: 0x2226c4, Func Offset: 0x1b4
	// Line 2737, Address: 0x2226cc, Func Offset: 0x1bc
	// Line 2738, Address: 0x2226dc, Func Offset: 0x1cc
	// Line 2739, Address: 0x2226e0, Func Offset: 0x1d0
	// Line 2744, Address: 0x2226e4, Func Offset: 0x1d4
	// Func End, Address: 0x2226f4, Func Offset: 0x1e4
}

// 
// Start address: 0x222700
void bhEff188(_anon0* op)
{
	_anon3* uvp;
	_anon3 uvinfo_houden_0[13];
	_anon3 uvinfo_houden_1[6];
	// Line 2753, Address: 0x222700, Func Offset: 0
	// Line 2782, Address: 0x22270c, Func Offset: 0xc
	// Line 2784, Address: 0x222720, Func Offset: 0x20
	// Line 2785, Address: 0x222724, Func Offset: 0x24
	// Line 2787, Address: 0x22272c, Func Offset: 0x2c
	// Line 2789, Address: 0x222744, Func Offset: 0x44
	// Line 2790, Address: 0x22274c, Func Offset: 0x4c
	// Line 2792, Address: 0x222754, Func Offset: 0x54
	// Line 2795, Address: 0x222760, Func Offset: 0x60
	// Line 2801, Address: 0x222768, Func Offset: 0x68
	// Line 2802, Address: 0x222770, Func Offset: 0x70
	// Line 2801, Address: 0x222778, Func Offset: 0x78
	// Line 2802, Address: 0x222780, Func Offset: 0x80
	// Line 2804, Address: 0x222794, Func Offset: 0x94
	// Line 2807, Address: 0x22279c, Func Offset: 0x9c
	// Line 2808, Address: 0x2227a8, Func Offset: 0xa8
	// Line 2809, Address: 0x2227ac, Func Offset: 0xac
	// Line 2808, Address: 0x2227b0, Func Offset: 0xb0
	// Line 2809, Address: 0x2227b8, Func Offset: 0xb8
	// Line 2810, Address: 0x2227ec, Func Offset: 0xec
	// Func End, Address: 0x2227fc, Func Offset: 0xfc
}

// 
// Start address: 0x222800
void bhEff189(_anon0* op)
{
	tagEFF0UV* pInfo;
	tagEFF0UV Eff189UvInfo[10];
	// Line 2820, Address: 0x222800, Func Offset: 0
	// Line 2830, Address: 0x22280c, Func Offset: 0xc
	// Line 2831, Address: 0x22282c, Func Offset: 0x2c
	// Line 2833, Address: 0x222838, Func Offset: 0x38
	// Line 2834, Address: 0x222844, Func Offset: 0x44
	// Line 2836, Address: 0x22284c, Func Offset: 0x4c
	// Line 2839, Address: 0x222858, Func Offset: 0x58
	// Line 2836, Address: 0x22285c, Func Offset: 0x5c
	// Line 2839, Address: 0x222864, Func Offset: 0x64
	// Line 2842, Address: 0x222880, Func Offset: 0x80
	// Line 2843, Address: 0x222890, Func Offset: 0x90
	// Line 2844, Address: 0x2228b0, Func Offset: 0xb0
	// Line 2845, Address: 0x2228b8, Func Offset: 0xb8
	// Line 2846, Address: 0x2228c0, Func Offset: 0xc0
	// Line 2849, Address: 0x2228c8, Func Offset: 0xc8
	// Line 2859, Address: 0x2228cc, Func Offset: 0xcc
	// Line 2849, Address: 0x2228d0, Func Offset: 0xd0
	// Line 2850, Address: 0x2228d4, Func Offset: 0xd4
	// Line 2851, Address: 0x2228dc, Func Offset: 0xdc
	// Line 2854, Address: 0x2228e4, Func Offset: 0xe4
	// Line 2855, Address: 0x2228ec, Func Offset: 0xec
	// Line 2856, Address: 0x2228f4, Func Offset: 0xf4
	// Line 2859, Address: 0x2228fc, Func Offset: 0xfc
	// Line 2865, Address: 0x22290c, Func Offset: 0x10c
	// Line 2872, Address: 0x222910, Func Offset: 0x110
	// Line 2873, Address: 0x222928, Func Offset: 0x128
	// Line 2874, Address: 0x222930, Func Offset: 0x130
	// Line 2875, Address: 0x222948, Func Offset: 0x148
	// Line 2876, Address: 0x222950, Func Offset: 0x150
	// Line 2879, Address: 0x22295c, Func Offset: 0x15c
	// Line 2881, Address: 0x222964, Func Offset: 0x164
	// Line 2882, Address: 0x22296c, Func Offset: 0x16c
	// Line 2883, Address: 0x222980, Func Offset: 0x180
	// Line 2885, Address: 0x222990, Func Offset: 0x190
	// Line 2887, Address: 0x222998, Func Offset: 0x198
	// Line 2888, Address: 0x22299c, Func Offset: 0x19c
	// Line 2892, Address: 0x2229a4, Func Offset: 0x1a4
	// Line 2893, Address: 0x2229b4, Func Offset: 0x1b4
	// Line 2894, Address: 0x2229c4, Func Offset: 0x1c4
	// Line 2895, Address: 0x2229d4, Func Offset: 0x1d4
	// Line 2898, Address: 0x2229f0, Func Offset: 0x1f0
	// Line 2907, Address: 0x2229f4, Func Offset: 0x1f4
	// Line 2898, Address: 0x2229f8, Func Offset: 0x1f8
	// Line 2899, Address: 0x2229fc, Func Offset: 0x1fc
	// Line 2900, Address: 0x222a04, Func Offset: 0x204
	// Line 2903, Address: 0x222a0c, Func Offset: 0x20c
	// Line 2904, Address: 0x222a14, Func Offset: 0x214
	// Line 2905, Address: 0x222a1c, Func Offset: 0x21c
	// Line 2907, Address: 0x222a24, Func Offset: 0x224
	// Line 2908, Address: 0x222a2c, Func Offset: 0x22c
	// Line 2913, Address: 0x222a34, Func Offset: 0x234
	// Line 2914, Address: 0x222a48, Func Offset: 0x248
	// Line 2915, Address: 0x222a60, Func Offset: 0x260
	// Line 2916, Address: 0x222a68, Func Offset: 0x268
	// Line 2921, Address: 0x222a88, Func Offset: 0x288
	// Line 2922, Address: 0x222a94, Func Offset: 0x294
	// Line 2924, Address: 0x222aa4, Func Offset: 0x2a4
	// Line 2932, Address: 0x222aa8, Func Offset: 0x2a8
	// Line 2933, Address: 0x222ab4, Func Offset: 0x2b4
	// Line 2940, Address: 0x222abc, Func Offset: 0x2bc
	// Line 2932, Address: 0x222ac0, Func Offset: 0x2c0
	// Line 2933, Address: 0x222ac8, Func Offset: 0x2c8
	// Line 2934, Address: 0x222ae4, Func Offset: 0x2e4
	// Line 2935, Address: 0x222b04, Func Offset: 0x304
	// Line 2936, Address: 0x222b20, Func Offset: 0x320
	// Line 2940, Address: 0x222b40, Func Offset: 0x340
	// Line 2942, Address: 0x222b5c, Func Offset: 0x35c
	// Line 2943, Address: 0x222b70, Func Offset: 0x370
	// Line 2945, Address: 0x222b94, Func Offset: 0x394
	// Func End, Address: 0x222ba4, Func Offset: 0x3a4
}

// 
// Start address: 0x222bb0
void bhEff190(_anon0* op)
{
	_anon12* pEffect;
	// Line 2954, Address: 0x222bb0, Func Offset: 0
	// Line 2958, Address: 0x222bbc, Func Offset: 0xc
	// Line 2959, Address: 0x222bdc, Func Offset: 0x2c
	// Line 2961, Address: 0x222be8, Func Offset: 0x38
	// Line 2962, Address: 0x222bf4, Func Offset: 0x44
	// Line 2964, Address: 0x222bfc, Func Offset: 0x4c
	// Line 2967, Address: 0x222c10, Func Offset: 0x60
	// Line 2970, Address: 0x222c24, Func Offset: 0x74
	// Line 2971, Address: 0x222c2c, Func Offset: 0x7c
	// Line 2975, Address: 0x222c34, Func Offset: 0x84
	// Line 2976, Address: 0x222c40, Func Offset: 0x90
	// Line 2978, Address: 0x222c50, Func Offset: 0xa0
	// Line 2979, Address: 0x222c58, Func Offset: 0xa8
	// Line 2980, Address: 0x222c5c, Func Offset: 0xac
	// Line 2992, Address: 0x222c60, Func Offset: 0xb0
	// Line 2978, Address: 0x222c64, Func Offset: 0xb4
	// Line 2979, Address: 0x222c70, Func Offset: 0xc0
	// Line 2980, Address: 0x222c74, Func Offset: 0xc4
	// Line 2981, Address: 0x222c78, Func Offset: 0xc8
	// Line 2982, Address: 0x222c7c, Func Offset: 0xcc
	// Line 2983, Address: 0x222c80, Func Offset: 0xd0
	// Line 2984, Address: 0x222c84, Func Offset: 0xd4
	// Line 2992, Address: 0x222c88, Func Offset: 0xd8
	// Line 2984, Address: 0x222c90, Func Offset: 0xe0
	// Line 2985, Address: 0x222c94, Func Offset: 0xe4
	// Line 2986, Address: 0x222c9c, Func Offset: 0xec
	// Line 2987, Address: 0x222ca4, Func Offset: 0xf4
	// Line 2988, Address: 0x222cac, Func Offset: 0xfc
	// Line 2989, Address: 0x222cb4, Func Offset: 0x104
	// Line 2990, Address: 0x222cbc, Func Offset: 0x10c
	// Line 2991, Address: 0x222cc4, Func Offset: 0x114
	// Line 2992, Address: 0x222cc8, Func Offset: 0x118
	// Line 2993, Address: 0x222cd0, Func Offset: 0x120
	// Line 2995, Address: 0x222cd4, Func Offset: 0x124
	// Func End, Address: 0x222ce4, Func Offset: 0x134
}

// 
// Start address: 0x222cf0
void bhEff191(_anon0* op)
{
	tagEFF0UVWHUC* pInfo;
	tagEFF0UVWHUC Eff191UvInfo[20];
	// Line 3005, Address: 0x222cf0, Func Offset: 0
	// Line 3018, Address: 0x222d00, Func Offset: 0x10
	// Line 3021, Address: 0x222d20, Func Offset: 0x30
	// Line 3022, Address: 0x222d28, Func Offset: 0x38
	// Line 3024, Address: 0x222d2c, Func Offset: 0x3c
	// Line 3021, Address: 0x222d30, Func Offset: 0x40
	// Line 3022, Address: 0x222d38, Func Offset: 0x48
	// Line 3023, Address: 0x222d3c, Func Offset: 0x4c
	// Line 3024, Address: 0x222d40, Func Offset: 0x50
	// Line 3025, Address: 0x222d44, Func Offset: 0x54
	// Line 3026, Address: 0x222d4c, Func Offset: 0x5c
	// Line 3029, Address: 0x222d50, Func Offset: 0x60
	// Line 3030, Address: 0x222d58, Func Offset: 0x68
	// Line 3031, Address: 0x222d74, Func Offset: 0x84
	// Line 3033, Address: 0x222d7c, Func Offset: 0x8c
	// Line 3034, Address: 0x222d84, Func Offset: 0x94
	// Line 3035, Address: 0x222ddc, Func Offset: 0xec
	// Line 3036, Address: 0x222e34, Func Offset: 0x144
	// Line 3038, Address: 0x222e44, Func Offset: 0x154
	// Line 3041, Address: 0x222e4c, Func Offset: 0x15c
	// Line 3047, Address: 0x222e60, Func Offset: 0x170
	// Line 3050, Address: 0x222e64, Func Offset: 0x174
	// Line 3047, Address: 0x222e68, Func Offset: 0x178
	// Line 3048, Address: 0x222e6c, Func Offset: 0x17c
	// Line 3051, Address: 0x222e74, Func Offset: 0x184
	// Line 3054, Address: 0x222e7c, Func Offset: 0x18c
	// Line 3057, Address: 0x222e88, Func Offset: 0x198
	// Line 3060, Address: 0x222e98, Func Offset: 0x1a8
	// Line 3064, Address: 0x222ea0, Func Offset: 0x1b0
	// Line 3069, Address: 0x222ea8, Func Offset: 0x1b8
	// Line 3072, Address: 0x222eb4, Func Offset: 0x1c4
	// Line 3064, Address: 0x222eb8, Func Offset: 0x1c8
	// Line 3072, Address: 0x222ebc, Func Offset: 0x1cc
	// Line 3064, Address: 0x222ec0, Func Offset: 0x1d0
	// Line 3065, Address: 0x222ec4, Func Offset: 0x1d4
	// Line 3072, Address: 0x222ecc, Func Offset: 0x1dc
	// Line 3065, Address: 0x222ed0, Func Offset: 0x1e0
	// Line 3066, Address: 0x222ed8, Func Offset: 0x1e8
	// Line 3069, Address: 0x222ee8, Func Offset: 0x1f8
	// Line 3072, Address: 0x222ef4, Func Offset: 0x204
	// Line 3077, Address: 0x222f00, Func Offset: 0x210
	// Line 3081, Address: 0x222f14, Func Offset: 0x224
	// Line 3082, Address: 0x222f70, Func Offset: 0x280
	// Line 3086, Address: 0x222fcc, Func Offset: 0x2dc
	// Line 3087, Address: 0x223018, Func Offset: 0x328
	// Line 3088, Address: 0x223040, Func Offset: 0x350
	// Line 3093, Address: 0x22307c, Func Offset: 0x38c
	// Line 3088, Address: 0x223080, Func Offset: 0x390
	// Line 3089, Address: 0x22308c, Func Offset: 0x39c
	// Line 3093, Address: 0x2230b4, Func Offset: 0x3c4
	// Line 3095, Address: 0x2230d0, Func Offset: 0x3e0
	// Line 3096, Address: 0x2230e4, Func Offset: 0x3f4
	// Line 3098, Address: 0x223108, Func Offset: 0x418
	// Func End, Address: 0x223118, Func Offset: 0x428
}

// 
// Start address: 0x223120
void bhEff192(_anon0* op)
{
	int lLoop;
	_anon12* pEffect;
	// Line 3107, Address: 0x223120, Func Offset: 0
	// Line 3112, Address: 0x223134, Func Offset: 0x14
	// Line 3113, Address: 0x223154, Func Offset: 0x34
	// Line 3115, Address: 0x223160, Func Offset: 0x40
	// Line 3116, Address: 0x22316c, Func Offset: 0x4c
	// Line 3118, Address: 0x223174, Func Offset: 0x54
	// Line 3121, Address: 0x223180, Func Offset: 0x60
	// Line 3122, Address: 0x223184, Func Offset: 0x64
	// Line 3118, Address: 0x223188, Func Offset: 0x68
	// Line 3121, Address: 0x223190, Func Offset: 0x70
	// Line 3123, Address: 0x223194, Func Offset: 0x74
	// Line 3135, Address: 0x223198, Func Offset: 0x78
	// Line 3121, Address: 0x22319c, Func Offset: 0x7c
	// Line 3122, Address: 0x2231a8, Func Offset: 0x88
	// Line 3123, Address: 0x2231ac, Func Offset: 0x8c
	// Line 3124, Address: 0x2231b0, Func Offset: 0x90
	// Line 3125, Address: 0x2231b4, Func Offset: 0x94
	// Line 3126, Address: 0x2231b8, Func Offset: 0x98
	// Line 3127, Address: 0x2231bc, Func Offset: 0x9c
	// Line 3128, Address: 0x2231c4, Func Offset: 0xa4
	// Line 3129, Address: 0x2231cc, Func Offset: 0xac
	// Line 3130, Address: 0x2231d4, Func Offset: 0xb4
	// Line 3131, Address: 0x2231dc, Func Offset: 0xbc
	// Line 3132, Address: 0x2231e4, Func Offset: 0xc4
	// Line 3133, Address: 0x2231ec, Func Offset: 0xcc
	// Line 3134, Address: 0x2231f4, Func Offset: 0xd4
	// Line 3135, Address: 0x2231f8, Func Offset: 0xd8
	// Line 3137, Address: 0x223200, Func Offset: 0xe0
	// Line 3138, Address: 0x223214, Func Offset: 0xf4
	// Line 3140, Address: 0x223228, Func Offset: 0x108
	// Line 3141, Address: 0x223238, Func Offset: 0x118
	// Func End, Address: 0x223250, Func Offset: 0x130
}

// 
// Start address: 0x223250
void bhEff193(_anon0* op)
{
	tagEFF0UV* pInfo;
	tagEFF0UV Eff193UvInfo[15];
	// Line 3151, Address: 0x223250, Func Offset: 0
	// Line 3161, Address: 0x223264, Func Offset: 0x14
	// Line 3164, Address: 0x223284, Func Offset: 0x34
	// Line 3165, Address: 0x22328c, Func Offset: 0x3c
	// Line 3167, Address: 0x223290, Func Offset: 0x40
	// Line 3164, Address: 0x223294, Func Offset: 0x44
	// Line 3165, Address: 0x22329c, Func Offset: 0x4c
	// Line 3166, Address: 0x2232a0, Func Offset: 0x50
	// Line 3167, Address: 0x2232a4, Func Offset: 0x54
	// Line 3169, Address: 0x2232a8, Func Offset: 0x58
	// Line 3171, Address: 0x2232b0, Func Offset: 0x60
	// Line 3172, Address: 0x2232c4, Func Offset: 0x74
	// Line 3173, Address: 0x2232d0, Func Offset: 0x80
	// Line 3174, Address: 0x2232e4, Func Offset: 0x94
	// Line 3175, Address: 0x2232f0, Func Offset: 0xa0
	// Line 3176, Address: 0x223304, Func Offset: 0xb4
	// Line 3179, Address: 0x223310, Func Offset: 0xc0
	// Line 3180, Address: 0x223318, Func Offset: 0xc8
	// Line 3181, Address: 0x223334, Func Offset: 0xe4
	// Line 3182, Address: 0x223368, Func Offset: 0x118
	// Line 3184, Address: 0x223370, Func Offset: 0x120
	// Line 3185, Address: 0x223378, Func Offset: 0x128
	// Line 3186, Address: 0x223384, Func Offset: 0x134
	// Line 3187, Address: 0x223390, Func Offset: 0x140
	// Line 3188, Address: 0x2233d8, Func Offset: 0x188
	// Line 3189, Address: 0x223420, Func Offset: 0x1d0
	// Line 3191, Address: 0x223430, Func Offset: 0x1e0
	// Line 3194, Address: 0x223438, Func Offset: 0x1e8
	// Line 3200, Address: 0x22344c, Func Offset: 0x1fc
	// Line 3202, Address: 0x223464, Func Offset: 0x214
	// Line 3204, Address: 0x22349c, Func Offset: 0x24c
	// Line 3202, Address: 0x2234a0, Func Offset: 0x250
	// Line 3205, Address: 0x2234a4, Func Offset: 0x254
	// Line 3209, Address: 0x2234ac, Func Offset: 0x25c
	// Line 3210, Address: 0x2234d0, Func Offset: 0x280
	// Line 3211, Address: 0x2234dc, Func Offset: 0x28c
	// Line 3214, Address: 0x223504, Func Offset: 0x2b4
	// Line 3217, Address: 0x223514, Func Offset: 0x2c4
	// Line 3221, Address: 0x22351c, Func Offset: 0x2cc
	// Line 3226, Address: 0x223524, Func Offset: 0x2d4
	// Line 3229, Address: 0x223530, Func Offset: 0x2e0
	// Line 3221, Address: 0x223534, Func Offset: 0x2e4
	// Line 3229, Address: 0x223538, Func Offset: 0x2e8
	// Line 3221, Address: 0x22353c, Func Offset: 0x2ec
	// Line 3222, Address: 0x223540, Func Offset: 0x2f0
	// Line 3229, Address: 0x223548, Func Offset: 0x2f8
	// Line 3222, Address: 0x22354c, Func Offset: 0x2fc
	// Line 3223, Address: 0x223554, Func Offset: 0x304
	// Line 3226, Address: 0x223564, Func Offset: 0x314
	// Line 3229, Address: 0x223570, Func Offset: 0x320
	// Line 3234, Address: 0x22357c, Func Offset: 0x32c
	// Line 3238, Address: 0x223588, Func Offset: 0x338
	// Line 3245, Address: 0x223590, Func Offset: 0x340
	// Line 3234, Address: 0x223594, Func Offset: 0x344
	// Line 3238, Address: 0x22359c, Func Offset: 0x34c
	// Line 3239, Address: 0x2235b8, Func Offset: 0x368
	// Line 3240, Address: 0x2235d8, Func Offset: 0x388
	// Line 3241, Address: 0x2235f4, Func Offset: 0x3a4
	// Line 3245, Address: 0x223614, Func Offset: 0x3c4
	// Line 3247, Address: 0x223630, Func Offset: 0x3e0
	// Line 3248, Address: 0x223644, Func Offset: 0x3f4
	// Line 3250, Address: 0x223668, Func Offset: 0x418
	// Func End, Address: 0x223680, Func Offset: 0x430
}

// 
// Start address: 0x223680
void bhEff194(_anon0* op)
{
	_anon12* pEffect;
	// Line 3259, Address: 0x223680, Func Offset: 0
	// Line 3263, Address: 0x22368c, Func Offset: 0xc
	// Line 3264, Address: 0x2236ac, Func Offset: 0x2c
	// Line 3266, Address: 0x2236b8, Func Offset: 0x38
	// Line 3267, Address: 0x2236c4, Func Offset: 0x44
	// Line 3269, Address: 0x2236cc, Func Offset: 0x4c
	// Line 3273, Address: 0x2236d8, Func Offset: 0x58
	// Line 3274, Address: 0x2236dc, Func Offset: 0x5c
	// Line 3269, Address: 0x2236e0, Func Offset: 0x60
	// Line 3273, Address: 0x2236e8, Func Offset: 0x68
	// Line 3275, Address: 0x2236ec, Func Offset: 0x6c
	// Line 3276, Address: 0x2236f0, Func Offset: 0x70
	// Line 3287, Address: 0x2236f4, Func Offset: 0x74
	// Line 3273, Address: 0x2236f8, Func Offset: 0x78
	// Line 3274, Address: 0x223704, Func Offset: 0x84
	// Line 3275, Address: 0x223708, Func Offset: 0x88
	// Line 3276, Address: 0x22370c, Func Offset: 0x8c
	// Line 3287, Address: 0x223710, Func Offset: 0x90
	// Line 3276, Address: 0x223718, Func Offset: 0x98
	// Line 3277, Address: 0x223730, Func Offset: 0xb0
	// Line 3278, Address: 0x223734, Func Offset: 0xb4
	// Line 3279, Address: 0x223738, Func Offset: 0xb8
	// Line 3280, Address: 0x223740, Func Offset: 0xc0
	// Line 3281, Address: 0x223748, Func Offset: 0xc8
	// Line 3282, Address: 0x223750, Func Offset: 0xd0
	// Line 3283, Address: 0x223758, Func Offset: 0xd8
	// Line 3284, Address: 0x223760, Func Offset: 0xe0
	// Line 3285, Address: 0x223768, Func Offset: 0xe8
	// Line 3286, Address: 0x223770, Func Offset: 0xf0
	// Line 3287, Address: 0x223774, Func Offset: 0xf4
	// Line 3289, Address: 0x22377c, Func Offset: 0xfc
	// Line 3290, Address: 0x223788, Func Offset: 0x108
	// Func End, Address: 0x223798, Func Offset: 0x118
}

// 
// Start address: 0x2237a0
void bhEff195(_anon0* op)
{
	tagEFF0UVWHUC* pInfo;
	tagEFF0UVWHUC* pEff195UvInfoTop[3];
	int lEff195UvInfoMax[3];
	// Line 3302, Address: 0x2237a0, Func Offset: 0
	// Line 3326, Address: 0x2237ac, Func Offset: 0xc
	// Line 3329, Address: 0x2237cc, Func Offset: 0x2c
	// Line 3330, Address: 0x2237d4, Func Offset: 0x34
	// Line 3331, Address: 0x2237d8, Func Offset: 0x38
	// Line 3329, Address: 0x2237dc, Func Offset: 0x3c
	// Line 3330, Address: 0x2237e4, Func Offset: 0x44
	// Line 3331, Address: 0x2237e8, Func Offset: 0x48
	// Line 3332, Address: 0x2237ec, Func Offset: 0x4c
	// Line 3335, Address: 0x2237f4, Func Offset: 0x54
	// Line 3340, Address: 0x223808, Func Offset: 0x68
	// Line 3341, Address: 0x223810, Func Offset: 0x70
	// Line 3343, Address: 0x223818, Func Offset: 0x78
	// Line 3345, Address: 0x223820, Func Offset: 0x80
	// Line 3348, Address: 0x223828, Func Offset: 0x88
	// Line 3353, Address: 0x223834, Func Offset: 0x94
	// Line 3356, Address: 0x223838, Func Offset: 0x98
	// Line 3353, Address: 0x223840, Func Offset: 0xa0
	// Line 3356, Address: 0x223844, Func Offset: 0xa4
	// Line 3357, Address: 0x22385c, Func Offset: 0xbc
	// Line 3360, Address: 0x223880, Func Offset: 0xe0
	// Line 3362, Address: 0x223888, Func Offset: 0xe8
	// Line 3365, Address: 0x2238c8, Func Offset: 0x128
	// Line 3369, Address: 0x2238ec, Func Offset: 0x14c
	// Line 3370, Address: 0x223948, Func Offset: 0x1a8
	// Line 3374, Address: 0x2239a4, Func Offset: 0x204
	// Line 3375, Address: 0x2239f0, Func Offset: 0x250
	// Line 3376, Address: 0x223a18, Func Offset: 0x278
	// Line 3381, Address: 0x223a54, Func Offset: 0x2b4
	// Line 3376, Address: 0x223a58, Func Offset: 0x2b8
	// Line 3377, Address: 0x223a64, Func Offset: 0x2c4
	// Line 3381, Address: 0x223a8c, Func Offset: 0x2ec
	// Line 3383, Address: 0x223aa8, Func Offset: 0x308
	// Line 3384, Address: 0x223abc, Func Offset: 0x31c
	// Line 3386, Address: 0x223ae0, Func Offset: 0x340
	// Func End, Address: 0x223af0, Func Offset: 0x350
}

// 
// Start address: 0x223af0
void bhEff196(_anon0* op)
{
	int lColor;
	int lType;
	tagEFF0UV* pInfo;
	tagEFF0UV* pEff196UvInfoTop[4];
	unsigned int ulEff196UvInfoMax[4];
	// Line 3422, Address: 0x223af0, Func Offset: 0
	// Line 3423, Address: 0x223b10, Func Offset: 0x20
	// Line 3425, Address: 0x223b1c, Func Offset: 0x2c
	// Line 3426, Address: 0x223b28, Func Offset: 0x38
	// Line 3428, Address: 0x223b30, Func Offset: 0x40
	// Line 3432, Address: 0x223b3c, Func Offset: 0x4c
	// Line 3431, Address: 0x223b40, Func Offset: 0x50
	// Line 3428, Address: 0x223b44, Func Offset: 0x54
	// Line 3431, Address: 0x223b4c, Func Offset: 0x5c
	// Line 3432, Address: 0x223b50, Func Offset: 0x60
	// Line 3431, Address: 0x223b54, Func Offset: 0x64
	// Line 3432, Address: 0x223b68, Func Offset: 0x78
	// Line 3433, Address: 0x223b94, Func Offset: 0xa4
	// Line 3436, Address: 0x223bb4, Func Offset: 0xc4
	// Line 3437, Address: 0x223bbc, Func Offset: 0xcc
	// Line 3438, Address: 0x223bc0, Func Offset: 0xd0
	// Line 3436, Address: 0x223bc4, Func Offset: 0xd4
	// Line 3437, Address: 0x223bcc, Func Offset: 0xdc
	// Line 3438, Address: 0x223bd0, Func Offset: 0xe0
	// Line 3439, Address: 0x223bd4, Func Offset: 0xe4
	// Line 3444, Address: 0x223bdc, Func Offset: 0xec
	// Line 3441, Address: 0x223be0, Func Offset: 0xf0
	// Line 3444, Address: 0x223be4, Func Offset: 0xf4
	// Line 3450, Address: 0x223bf4, Func Offset: 0x104
	// Line 3453, Address: 0x223bfc, Func Offset: 0x10c
	// Line 3456, Address: 0x223c00, Func Offset: 0x110
	// Line 3453, Address: 0x223c10, Func Offset: 0x120
	// Line 3456, Address: 0x223c18, Func Offset: 0x128
	// Line 3458, Address: 0x223c2c, Func Offset: 0x13c
	// Line 3469, Address: 0x223c30, Func Offset: 0x140
	// Line 3465, Address: 0x223c3c, Func Offset: 0x14c
	// Line 3469, Address: 0x223c40, Func Offset: 0x150
	// Line 3477, Address: 0x223c4c, Func Offset: 0x15c
	// Line 3470, Address: 0x223c50, Func Offset: 0x160
	// Line 3469, Address: 0x223c58, Func Offset: 0x168
	// Line 3470, Address: 0x223c60, Func Offset: 0x170
	// Line 3471, Address: 0x223c7c, Func Offset: 0x18c
	// Line 3472, Address: 0x223c9c, Func Offset: 0x1ac
	// Line 3473, Address: 0x223cb8, Func Offset: 0x1c8
	// Line 3477, Address: 0x223cd8, Func Offset: 0x1e8
	// Line 3479, Address: 0x223cf4, Func Offset: 0x204
	// Line 3480, Address: 0x223d08, Func Offset: 0x218
	// Line 3482, Address: 0x223d2c, Func Offset: 0x23c
	// Func End, Address: 0x223d34, Func Offset: 0x244
}

// 
// Start address: 0x223d40
void bhEff197()
{
	// Line 3492, Address: 0x223d40, Func Offset: 0
	// Func End, Address: 0x223d48, Func Offset: 0x8
}

// 
// Start address: 0x223d50
void bhEff198(_anon0* op)
{
	// Line 3502, Address: 0x223d50, Func Offset: 0
	// Line 3504, Address: 0x223d70, Func Offset: 0x20
	// Line 3505, Address: 0x223d7c, Func Offset: 0x2c
	// Line 3506, Address: 0x223d84, Func Offset: 0x34
	// Line 3507, Address: 0x223d8c, Func Offset: 0x3c
	// Line 3508, Address: 0x223d90, Func Offset: 0x40
	// Line 3509, Address: 0x223d94, Func Offset: 0x44
	// Line 3510, Address: 0x223d98, Func Offset: 0x48
	// Line 3511, Address: 0x223d9c, Func Offset: 0x4c
	// Line 3512, Address: 0x223da0, Func Offset: 0x50
	// Line 3513, Address: 0x223da8, Func Offset: 0x58
	// Line 3514, Address: 0x223dac, Func Offset: 0x5c
	// Line 3515, Address: 0x223db0, Func Offset: 0x60
	// Line 3516, Address: 0x223db8, Func Offset: 0x68
	// Line 3517, Address: 0x223dbc, Func Offset: 0x6c
	// Line 3518, Address: 0x223dc0, Func Offset: 0x70
	// Line 3519, Address: 0x223dc8, Func Offset: 0x78
	// Line 3520, Address: 0x223dd0, Func Offset: 0x80
	// Line 3522, Address: 0x223dd4, Func Offset: 0x84
	// Line 3525, Address: 0x223e0c, Func Offset: 0xbc
	// Func End, Address: 0x223e14, Func Offset: 0xc4
}

// 
// Start address: 0x223e20
void bhEff199()
{
	_anon24 ptcl[11];
	// Line 3534, Address: 0x223e20, Func Offset: 0
	// Line 3536, Address: 0x223e24, Func Offset: 0x4
	// Line 3534, Address: 0x223e34, Func Offset: 0x14
	// Line 3536, Address: 0x223e38, Func Offset: 0x18
	// Line 3552, Address: 0x223e5c, Func Offset: 0x3c
	// Line 3536, Address: 0x223e60, Func Offset: 0x40
	// Line 3552, Address: 0x223e64, Func Offset: 0x44
	// Line 3554, Address: 0x223e70, Func Offset: 0x50
	// Line 3555, Address: 0x223e7c, Func Offset: 0x5c
	// Line 3556, Address: 0x223e90, Func Offset: 0x70
	// Line 3557, Address: 0x223ea4, Func Offset: 0x84
	// Line 3558, Address: 0x223eb8, Func Offset: 0x98
	// Line 3559, Address: 0x223ecc, Func Offset: 0xac
	// Line 3560, Address: 0x223ee0, Func Offset: 0xc0
	// Line 3561, Address: 0x223ef4, Func Offset: 0xd4
	// Line 3562, Address: 0x223f08, Func Offset: 0xe8
	// Line 3563, Address: 0x223f1c, Func Offset: 0xfc
	// Line 3564, Address: 0x223f30, Func Offset: 0x110
	// Line 3565, Address: 0x223f44, Func Offset: 0x124
	// Line 3566, Address: 0x223f58, Func Offset: 0x138
	// Line 3567, Address: 0x223f60, Func Offset: 0x140
	// Func End, Address: 0x223f6c, Func Offset: 0x14c
}*/

