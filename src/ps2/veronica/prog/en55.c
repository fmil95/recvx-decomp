#include "../../../ps2/veronica/prog/en55.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon.h"

typedef void (*bhEne55_Mode0_proc)(BH_PWORK* epw);
typedef void (*bhEne55_MoveType_proc)(BH_PWORK* epw);
typedef void (*bhEne55_MoveMode2_proc)(BH_PWORK* epw);
typedef void (*bhEne55_DamageType_proc)(BH_PWORK* epw);
typedef void (*bhEne55_DamageMode2_proc)(BH_PWORK* epw);

bhEne55_Mode0_proc bhEne55_Mode0[6] = 
{
	bhEne55_Init,
	bhEne55_Move,
	NULL,
	bhEne55_Damage,
	NULL,
	bhEne_Event
};
bhEne55_MoveType_proc bhEne55_MoveType[1] = 
{
	bhEne55_MVType00
};
bhEne55_MoveMode2_proc bhEne55_MoveMode2[1] = 
{
	bhEne55_MV00
};
bhEne55_DamageType_proc bhEne55_DamageType[1] = 
{
	bhEne55_DGType00
};
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

// 100% matching!
void bhEne55_MainLoop(BH_PWORK* epw)
{
	bhEne55_Mode0[epw->mode0](epw);

	bhEne55_SetMtn(epw);
}

// 100% matching!
int bhEne55_SetMtn(BH_PWORK* epw)
{
	int ret;

	ret = bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);

    if (ret != 0)
    {
        epw->flg |= 0x2000000;
    }
    else
    {
        epw->flg &= ~0x2000000;
    }

    return ret;
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

// 100% matching!
void bhEne55_Move(BH_PWORK* epw)
{
	bhEne55_MoveType[epw->type](epw);
}

// 100% matching!
void bhEne55_Damage(BH_PWORK* epw)
{
	bhEne55_DamageType[epw->type](epw);
}

// 100% matching!
void bhEne55_MVType00(BH_PWORK* epw)
{
	bhEne55_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne55_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)                               
    {
    case 0:
        bhEne_ChgMtn(epw, 0, 0, 0);

        epw->mtn_add = 0;

        epw->mode3++;
    case 1:
        break;
    }
}

// 100% matching!
void bhEne55_DGType00(BH_PWORK* epw)
{
	bhEne55_DamageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne55_DG00(BH_PWORK* epw)
{
    switch (epw->mode3)                        
    {
    case 0:
        if (epw->pz < 20.0f)
        {
            bhEne_ChgMtn(epw, 1, 0, 0);
        }
        else
        {
            bhEne_ChgMtn(epw, 0, 0, 0);
        }

        epw->mode3++;
    case 1:
        if ((epw->frm_no / 65536) == (epw->mnwP[epw->mtn_no].frm_num - 1))
        {
            epw->mtn_add = 0;

            epw->mode3++;
        }
    case 2:
        break;
    }
}
