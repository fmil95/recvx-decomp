#include "../../../ps2/veronica/prog/en55.h"

/*void(*bhEne55_Mode0)(BH_PWORK*)[6];
void(*bhEne55_MoveType)(BH_PWORK*)[1];
void(*bhEne55_MoveMode2)(BH_PWORK*)[1];
void(*bhEne55_DamageType)(BH_PWORK*)[1];*/
typedef void (*bhEne55_DamageMode2_proc)(BH_PWORK* epw);
bhEne55_DamageMode2_proc bhEne55_DamageMode2[1] = 
{
	bhEne55_DG00
};

// 
// Start address: 0x21b410
void bhEne55(BH_PWORK* epw)
{
	int i;
	// Line 154, Address: 0x21b410, Func Offset: 0
	// Line 158, Address: 0x21b41c, Func Offset: 0xc
	// Line 161, Address: 0x21b424, Func Offset: 0x14
	// Line 163, Address: 0x21b434, Func Offset: 0x24
	// Line 164, Address: 0x21b458, Func Offset: 0x48
	// Line 168, Address: 0x21b468, Func Offset: 0x58
	// Line 171, Address: 0x21b474, Func Offset: 0x64
	// Line 173, Address: 0x21b47c, Func Offset: 0x6c
	// Func End, Address: 0x21b48c, Func Offset: 0x7c
	scePrintf("bhEne55 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x21b490
void bhEne55_MainLoop(BH_PWORK* epw)
{
	// Line 193, Address: 0x21b490, Func Offset: 0
	// Line 197, Address: 0x21b4a0, Func Offset: 0x10
	// Line 200, Address: 0x21b4c0, Func Offset: 0x30
	// Line 210, Address: 0x21b4c8, Func Offset: 0x38
	// Func End, Address: 0x21b4d8, Func Offset: 0x48
}

// 
// Start address: 0x21b4e0
int bhEne55_SetMtn(BH_PWORK* epw)
{
	int ret;
	// Line 226, Address: 0x21b4e0, Func Offset: 0
	// Line 232, Address: 0x21b4f0, Func Offset: 0x10
	// Line 235, Address: 0x21b500, Func Offset: 0x20
	// Line 236, Address: 0x21b508, Func Offset: 0x28
	// Line 238, Address: 0x21b51c, Func Offset: 0x3c
	// Line 241, Address: 0x21b530, Func Offset: 0x50
	// Func End, Address: 0x21b540, Func Offset: 0x60
}

// 
// Start address: 0x21b540
void bhEne55_CollCheck(BH_PWORK* epw)
{
	int i;
	//_anon20 ps;
	//_anon31 at;
	//_anon4* owk;
	BH_PWORK* epp;
	// Line 260, Address: 0x21b540, Func Offset: 0
	// Line 267, Address: 0x21b550, Func Offset: 0x10
	// Line 270, Address: 0x21b580, Func Offset: 0x40
	// Line 273, Address: 0x21b598, Func Offset: 0x58
	// Line 276, Address: 0x21b59c, Func Offset: 0x5c
	// Line 277, Address: 0x21b5a0, Func Offset: 0x60
	// Line 273, Address: 0x21b5a8, Func Offset: 0x68
	// Line 274, Address: 0x21b5b4, Func Offset: 0x74
	// Line 275, Address: 0x21b5b8, Func Offset: 0x78
	// Line 277, Address: 0x21b5bc, Func Offset: 0x7c
	// Line 278, Address: 0x21b5c8, Func Offset: 0x88
	// Line 279, Address: 0x21b5cc, Func Offset: 0x8c
	// Line 281, Address: 0x21b5e4, Func Offset: 0xa4
	// Line 282, Address: 0x21b5ec, Func Offset: 0xac
	// Line 281, Address: 0x21b5f0, Func Offset: 0xb0
	// Line 282, Address: 0x21b5fc, Func Offset: 0xbc
	// Line 283, Address: 0x21b600, Func Offset: 0xc0
	// Line 284, Address: 0x21b604, Func Offset: 0xc4
	// Line 287, Address: 0x21b608, Func Offset: 0xc8
	// Line 289, Address: 0x21b610, Func Offset: 0xd0
	// Line 290, Address: 0x21b628, Func Offset: 0xe8
	// Func End, Address: 0x21b63c, Func Offset: 0xfc
}

// 
// Start address: 0x21b640
void bhEne55_CalcEnemy(BH_PWORK* epw)
{
	//_anon4* owk;
	// Line 307, Address: 0x21b640, Func Offset: 0
	// Line 311, Address: 0x21b64c, Func Offset: 0xc
	// Line 314, Address: 0x21b654, Func Offset: 0x14
	// Line 315, Address: 0x21b658, Func Offset: 0x18
	// Line 326, Address: 0x21b65c, Func Offset: 0x1c
	// Line 314, Address: 0x21b660, Func Offset: 0x20
	// Line 315, Address: 0x21b664, Func Offset: 0x24
	// Line 318, Address: 0x21b674, Func Offset: 0x34
	// Line 319, Address: 0x21b67c, Func Offset: 0x3c
	// Line 320, Address: 0x21b684, Func Offset: 0x44
	// Line 321, Address: 0x21b68c, Func Offset: 0x4c
	// Line 322, Address: 0x21b694, Func Offset: 0x54
	// Line 323, Address: 0x21b69c, Func Offset: 0x5c
	// Line 324, Address: 0x21b6a4, Func Offset: 0x64
	// Line 325, Address: 0x21b6ac, Func Offset: 0x6c
	// Line 326, Address: 0x21b6b4, Func Offset: 0x74
	// Line 327, Address: 0x21b6b8, Func Offset: 0x78
	// Func End, Address: 0x21b6c8, Func Offset: 0x88
}

// 
// Start address: 0x21b6d0
void bhEne55_Init(BH_PWORK* epw)
{
	int i;
	// Line 347, Address: 0x21b6d0, Func Offset: 0
	// Line 348, Address: 0x21b6d8, Func Offset: 0x8
	// Line 349, Address: 0x21b6e0, Func Offset: 0x10
	// Line 350, Address: 0x21b6e4, Func Offset: 0x14
	// Line 351, Address: 0x21b6e8, Func Offset: 0x18
	// Line 352, Address: 0x21b6ec, Func Offset: 0x1c
	// Line 353, Address: 0x21b6f0, Func Offset: 0x20
	// Line 354, Address: 0x21b6f8, Func Offset: 0x28
	// Line 355, Address: 0x21b6fc, Func Offset: 0x2c
	// Line 358, Address: 0x21b720, Func Offset: 0x50
	// Line 359, Address: 0x21b724, Func Offset: 0x54
	// Line 360, Address: 0x21b728, Func Offset: 0x58
	// Line 361, Address: 0x21b72c, Func Offset: 0x5c
	// Line 362, Address: 0x21b730, Func Offset: 0x60
	// Line 363, Address: 0x21b734, Func Offset: 0x64
	// Line 364, Address: 0x21b738, Func Offset: 0x68
	// Line 368, Address: 0x21b73c, Func Offset: 0x6c
	// Line 369, Address: 0x21b740, Func Offset: 0x70
	// Line 372, Address: 0x21b744, Func Offset: 0x74
	// Line 375, Address: 0x21b748, Func Offset: 0x78
	// Line 368, Address: 0x21b74c, Func Offset: 0x7c
	// Line 369, Address: 0x21b754, Func Offset: 0x84
	// Line 372, Address: 0x21b760, Func Offset: 0x90
	// Line 373, Address: 0x21b764, Func Offset: 0x94
	// Line 375, Address: 0x21b770, Func Offset: 0xa0
	// Line 376, Address: 0x21b774, Func Offset: 0xa4
	// Line 377, Address: 0x21b778, Func Offset: 0xa8
	// Line 379, Address: 0x21b77c, Func Offset: 0xac
	// Func End, Address: 0x21b784, Func Offset: 0xb4
}

// 
// Start address: 0x21b790
void bhEne55_Move(BH_PWORK* epw)
{
	// Line 399, Address: 0x21b790, Func Offset: 0
	// Func End, Address: 0x21b7b0, Func Offset: 0x20
}

// 
// Start address: 0x21b7b0
void bhEne55_Damage(BH_PWORK* epw)
{
	// Line 418, Address: 0x21b7b0, Func Offset: 0
	// Func End, Address: 0x21b7d0, Func Offset: 0x20
}

// 
// Start address: 0x21b7d0
void bhEne55_MVType00(BH_PWORK* epw)
{
	// Line 438, Address: 0x21b7d0, Func Offset: 0
	// Func End, Address: 0x21b7f0, Func Offset: 0x20
}

// 
// Start address: 0x21b7f0
void bhEne55_MV00(BH_PWORK* epw)
{
	// Line 459, Address: 0x21b7f0, Func Offset: 0
	// Line 460, Address: 0x21b7fc, Func Offset: 0xc
	// Line 463, Address: 0x21b81c, Func Offset: 0x2c
	// Line 464, Address: 0x21b82c, Func Offset: 0x3c
	// Line 465, Address: 0x21b830, Func Offset: 0x40
	// Line 470, Address: 0x21b83c, Func Offset: 0x4c
	// Func End, Address: 0x21b84c, Func Offset: 0x5c
}

// 100% matching!
void bhEne55_DGType00(BH_PWORK* epw)
{
	bhEne55_DamageMode2[epw->mode2](epw);
}

// 
// Start address: 0x21b870
void bhEne55_DG00(BH_PWORK* epw)
{
	// Line 510, Address: 0x21b870, Func Offset: 0
	// Line 511, Address: 0x21b87c, Func Offset: 0xc
	// Line 514, Address: 0x21b8a8, Func Offset: 0x38
	// Line 516, Address: 0x21b8c8, Func Offset: 0x58
	// Line 517, Address: 0x21b8d4, Func Offset: 0x64
	// Line 520, Address: 0x21b8dc, Func Offset: 0x6c
	// Line 522, Address: 0x21b8ec, Func Offset: 0x7c
	// Line 525, Address: 0x21b8f8, Func Offset: 0x88
	// Line 527, Address: 0x21b928, Func Offset: 0xb8
	// Line 528, Address: 0x21b92c, Func Offset: 0xbc
	// Line 535, Address: 0x21b938, Func Offset: 0xc8
	// Func End, Address: 0x21b948, Func Offset: 0xd8
}
