#include "../../../ps2/veronica/prog/en54.h"
#include "../../../ps2/veronica/prog/subpl.h"

typedef void (*bhEne54_Mode0_proc)(BH_PWORK* epw);
typedef void (*bhEne54_MoveType_proc)(BH_PWORK* epw);
typedef void (*bhEne54_MoveMode2_proc)(BH_PWORK* epw);
typedef void (*bhEne54_DamageType_proc)(BH_PWORK* epw);
typedef void (*bhEne54_DamageMode2_proc)(BH_PWORK* epw);

bhEne54_Mode0_proc bhEne54_Mode0[6] = 
{
	bhEne54_Init,
	bhEne54_Move,
	NULL,
	bhEne54_Damage,
	NULL,
	bhEne_Event
};
bhEne54_MoveType_proc bhEne54_MoveType[1] = 
{
	bhEne54_MVType00
};
bhEne54_MoveMode2_proc bhEne54_MoveMode2[1] = 
{
	bhEne54_MV00
};
bhEne54_DamageType_proc bhEne54_DamageType[1] = 
{
	bhEne54_DGType00
};
bhEne54_DamageMode2_proc bhEne54_DamageMode2[1] = 
{
	bhEne54_DG00
};

// 100% matching!
void bhEne54(BH_PWORK* epw)
{
	int i;

	bhEne54_MainLoop(epw);

    if ((epw->flg & 0x4))
    {
        for (i = 0; i < 64; i++)
        {
            epw->dam[i] = 0;
        }

        epw->flg &= ~0x4;
    }

    bhEne54_CalcEnemy(epw);

    bhEne54_CollCheck(epw);
}

// 100% matching!
void bhEne54_MainLoop(BH_PWORK* epw)
{
	bhEne54_Mode0[epw->mode0](epw);

	bhEne54_SetMtn(epw);
}

// 
// Start address: 0x21afa0
int bhEne54_SetMtn(BH_PWORK* epw)
{
	int ret;
	// Line 226, Address: 0x21afa0, Func Offset: 0
	// Line 232, Address: 0x21afb0, Func Offset: 0x10
	// Line 235, Address: 0x21afc0, Func Offset: 0x20
	// Line 236, Address: 0x21afc8, Func Offset: 0x28
	// Line 238, Address: 0x21afdc, Func Offset: 0x3c
	// Line 241, Address: 0x21aff0, Func Offset: 0x50
	// Func End, Address: 0x21b000, Func Offset: 0x60
}

// 
// Start address: 0x21b000
void bhEne54_CollCheck(BH_PWORK* epw)
{
	int i;
	//_anon20 ps;
	//_anon31 at;
	//_anon4* owk;
	BH_PWORK* epp;
	// Line 260, Address: 0x21b000, Func Offset: 0
	// Line 267, Address: 0x21b010, Func Offset: 0x10
	// Line 270, Address: 0x21b040, Func Offset: 0x40
	// Line 273, Address: 0x21b058, Func Offset: 0x58
	// Line 276, Address: 0x21b05c, Func Offset: 0x5c
	// Line 277, Address: 0x21b060, Func Offset: 0x60
	// Line 273, Address: 0x21b068, Func Offset: 0x68
	// Line 274, Address: 0x21b074, Func Offset: 0x74
	// Line 275, Address: 0x21b078, Func Offset: 0x78
	// Line 277, Address: 0x21b07c, Func Offset: 0x7c
	// Line 278, Address: 0x21b088, Func Offset: 0x88
	// Line 279, Address: 0x21b08c, Func Offset: 0x8c
	// Line 281, Address: 0x21b0a4, Func Offset: 0xa4
	// Line 282, Address: 0x21b0ac, Func Offset: 0xac
	// Line 281, Address: 0x21b0b0, Func Offset: 0xb0
	// Line 282, Address: 0x21b0bc, Func Offset: 0xbc
	// Line 283, Address: 0x21b0c0, Func Offset: 0xc0
	// Line 284, Address: 0x21b0c4, Func Offset: 0xc4
	// Line 287, Address: 0x21b0c8, Func Offset: 0xc8
	// Line 289, Address: 0x21b0d0, Func Offset: 0xd0
	// Line 290, Address: 0x21b0e8, Func Offset: 0xe8
	// Func End, Address: 0x21b0fc, Func Offset: 0xfc
}

// 
// Start address: 0x21b100
void bhEne54_CalcEnemy(BH_PWORK* epw)
{
	//_anon4* owk;
	// Line 307, Address: 0x21b100, Func Offset: 0
	// Line 311, Address: 0x21b10c, Func Offset: 0xc
	// Line 314, Address: 0x21b114, Func Offset: 0x14
	// Line 315, Address: 0x21b118, Func Offset: 0x18
	// Line 326, Address: 0x21b11c, Func Offset: 0x1c
	// Line 314, Address: 0x21b120, Func Offset: 0x20
	// Line 315, Address: 0x21b124, Func Offset: 0x24
	// Line 318, Address: 0x21b134, Func Offset: 0x34
	// Line 319, Address: 0x21b13c, Func Offset: 0x3c
	// Line 320, Address: 0x21b144, Func Offset: 0x44
	// Line 321, Address: 0x21b14c, Func Offset: 0x4c
	// Line 322, Address: 0x21b154, Func Offset: 0x54
	// Line 323, Address: 0x21b15c, Func Offset: 0x5c
	// Line 324, Address: 0x21b164, Func Offset: 0x64
	// Line 325, Address: 0x21b16c, Func Offset: 0x6c
	// Line 326, Address: 0x21b174, Func Offset: 0x74
	// Line 327, Address: 0x21b178, Func Offset: 0x78
	// Func End, Address: 0x21b188, Func Offset: 0x88
}

// 
// Start address: 0x21b190
void bhEne54_Init(BH_PWORK* epw)
{
	int i;
	// Line 347, Address: 0x21b190, Func Offset: 0
	// Line 348, Address: 0x21b198, Func Offset: 0x8
	// Line 349, Address: 0x21b1a0, Func Offset: 0x10
	// Line 350, Address: 0x21b1a4, Func Offset: 0x14
	// Line 351, Address: 0x21b1a8, Func Offset: 0x18
	// Line 352, Address: 0x21b1ac, Func Offset: 0x1c
	// Line 353, Address: 0x21b1b0, Func Offset: 0x20
	// Line 354, Address: 0x21b1b8, Func Offset: 0x28
	// Line 355, Address: 0x21b1bc, Func Offset: 0x2c
	// Line 358, Address: 0x21b1e0, Func Offset: 0x50
	// Line 359, Address: 0x21b1e4, Func Offset: 0x54
	// Line 360, Address: 0x21b1e8, Func Offset: 0x58
	// Line 361, Address: 0x21b1ec, Func Offset: 0x5c
	// Line 362, Address: 0x21b1f0, Func Offset: 0x60
	// Line 363, Address: 0x21b1f4, Func Offset: 0x64
	// Line 364, Address: 0x21b1f8, Func Offset: 0x68
	// Line 368, Address: 0x21b1fc, Func Offset: 0x6c
	// Line 369, Address: 0x21b200, Func Offset: 0x70
	// Line 372, Address: 0x21b204, Func Offset: 0x74
	// Line 375, Address: 0x21b208, Func Offset: 0x78
	// Line 368, Address: 0x21b20c, Func Offset: 0x7c
	// Line 369, Address: 0x21b214, Func Offset: 0x84
	// Line 372, Address: 0x21b220, Func Offset: 0x90
	// Line 373, Address: 0x21b224, Func Offset: 0x94
	// Line 375, Address: 0x21b230, Func Offset: 0xa0
	// Line 376, Address: 0x21b234, Func Offset: 0xa4
	// Line 377, Address: 0x21b238, Func Offset: 0xa8
	// Line 379, Address: 0x21b23c, Func Offset: 0xac
	// Func End, Address: 0x21b244, Func Offset: 0xb4
}

// 
// Start address: 0x21b250
void bhEne54_Move(BH_PWORK* epw)
{
	// Line 399, Address: 0x21b250, Func Offset: 0
	// Func End, Address: 0x21b270, Func Offset: 0x20
}

// 
// Start address: 0x21b270
void bhEne54_Damage(BH_PWORK* epw)
{
	// Line 418, Address: 0x21b270, Func Offset: 0
	// Func End, Address: 0x21b290, Func Offset: 0x20
}

// 
// Start address: 0x21b290
void bhEne54_MVType00(BH_PWORK* epw)
{
	// Line 438, Address: 0x21b290, Func Offset: 0
	// Func End, Address: 0x21b2b0, Func Offset: 0x20
}

// 
// Start address: 0x21b2b0
void bhEne54_MV00(BH_PWORK* epw)
{
	// Line 459, Address: 0x21b2b0, Func Offset: 0
	// Line 460, Address: 0x21b2bc, Func Offset: 0xc
	// Line 463, Address: 0x21b2dc, Func Offset: 0x2c
	// Line 464, Address: 0x21b2ec, Func Offset: 0x3c
	// Line 465, Address: 0x21b2f0, Func Offset: 0x40
	// Line 470, Address: 0x21b2fc, Func Offset: 0x4c
	// Func End, Address: 0x21b30c, Func Offset: 0x5c
}

// 
// Start address: 0x21b310
void bhEne54_DGType00(BH_PWORK* epw)
{
	// Line 489, Address: 0x21b310, Func Offset: 0
	// Func End, Address: 0x21b330, Func Offset: 0x20
}

// 
// Start address: 0x21b330
void bhEne54_DG00(BH_PWORK* epw)
{
	// Line 510, Address: 0x21b330, Func Offset: 0
	// Line 511, Address: 0x21b33c, Func Offset: 0xc
	// Line 514, Address: 0x21b368, Func Offset: 0x38
	// Line 516, Address: 0x21b388, Func Offset: 0x58
	// Line 517, Address: 0x21b394, Func Offset: 0x64
	// Line 520, Address: 0x21b39c, Func Offset: 0x6c
	// Line 522, Address: 0x21b3ac, Func Offset: 0x7c
	// Line 525, Address: 0x21b3b8, Func Offset: 0x88
	// Line 527, Address: 0x21b3e8, Func Offset: 0xb8
	// Line 528, Address: 0x21b3ec, Func Offset: 0xbc
	// Line 535, Address: 0x21b3f8, Func Offset: 0xc8
	// Func End, Address: 0x21b408, Func Offset: 0xd8
}
