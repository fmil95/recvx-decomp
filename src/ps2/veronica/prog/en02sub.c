#include "../../../ps2/veronica/prog/en02sub.h"
#include "../../../ps2/veronica/prog/en02.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

typedef void (*bhEne02sub_Mode0_proc)(BH_PWORK* epw);
typedef void (*bhEne02sub_MoveMode2_proc)(BH_PWORK* epw);

static P_WORK Open[4] = 
{
    { 0x00000000, 0.0f    },
    { 0x00000006, 900.0f  },
    { 0x0000000A, 1000.0f },
    { 0x000003E7, 1000.0f }
};
static P_WORK Close[3] = 
{
    { 0x00000000, 1000.0f },
    { 0x0000000A, 0.0f    },
    { 0x000003E7, 0.0f    }
};
bhEne02sub_Mode0_proc bhEne02sub_Mode0[2] = 
{
	bhEne02sub_Init,
	bhEne02sub_Move
};
bhEne02sub_MoveMode2_proc bhEne02sub_MoveMode2[5] =
{
	bhEne02sub_MV00,
	bhEne02sub_MV01,
	bhEne02sub_MV02,
	bhEne02sub_MV03,
	bhEne02sub_MV04
};

// 100% matching!
void bhEne02sub(BH_PWORK* epw)
{
    bhEne02sub_Mode0[epw->mode0](epw);
}

// 100% matching!
void bhEne02sub_Init(BH_PWORK* epw) 
{
    epw->mdflg |= 0x4;
    epw->mdflg |= 0x1;
    
    epw->flg2 |= 0x1;
    
    if (epw->type == 0) 
    {
        epw->car = 10.0f;
        epw->cah = 20.0f;
    }
    
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne02sub_Move(BH_PWORK* epw)
{
    bhEne02sub_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne02sub_MV00()
{

}

// 100% matching!
void bhEne02sub_MV01(BH_PWORK* epw)
{
	BH_PWORK* ep;

    switch (epw->mode3)
    { 
    case 0:
        epw->flg |= 0x48;
        
        epw->mdflg |= 0x2;
        epw->mdflg &= ~0x1;
        
        epw->ct0 = 0;
        
        ep = (BH_PWORK*)epw->lkwkp;
        
        epw->px = ep->px;
        epw->py = ep->py;
        epw->pz = ep->pz;
        
        epw->ay = (ep->ay + 32767) + 1;
        
        epw->car = 0.1f;
        
        epw->mode3++;
    case 1:
        epw->shp_ct = bhEne_GetShapeCnt(Open, epw->ct0);
        
        if (epw->ct0 > 30) 
        {
            epw->mode2 = 0;
        }
        
        epw->car += (10.0f - epw->car) / 16.0f;
        
        epw->ct0++;
        break;
    }
}

// 100% matching!
void bhEne02sub_MV02(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {
    case 0:
        epw->mdflg |= 0x2;
        epw->mdflg &= ~0x1;
        
        epw->ct0 = 0;
        
        epw->car = 10.0f;
        
        epw->mode3++;
    case 1:
        epw->shp_ct = bhEne_GetShapeCnt(Close, epw->ct0);
        
        if (epw->ct0 > 10) 
        {
            epw->mdflg |= 0x1;
            epw->flg &= ~0x48;
            
            epw->mode2 = 0;
        }
        
        epw->car += -epw->car / 16.0f;
        
        epw->ct0++;
    }
}

/*// 
// Start address: 0x1965d0
void bhEne02sub_MV03(BH_PWORK* epw)
{
	_anon8 pos;
	BH_PWORK* ep;
	// Line 288, Address: 0x1965d0, Func Offset: 0
	// Line 289, Address: 0x1965e0, Func Offset: 0x10
	// Line 292, Address: 0x1965e8, Func Offset: 0x18
	// Line 295, Address: 0x196620, Func Offset: 0x50
	// Line 310, Address: 0x196628, Func Offset: 0x58
	// Line 295, Address: 0x19662c, Func Offset: 0x5c
	// Line 312, Address: 0x196634, Func Offset: 0x64
	// Line 313, Address: 0x196674, Func Offset: 0xa4
	// Line 316, Address: 0x196680, Func Offset: 0xb0
	// Line 317, Address: 0x196698, Func Offset: 0xc8
	// Line 319, Address: 0x1966a0, Func Offset: 0xd0
	// Line 320, Address: 0x1966b8, Func Offset: 0xe8
	// Line 321, Address: 0x1966d0, Func Offset: 0x100
	// Line 323, Address: 0x1966e0, Func Offset: 0x110
	// Line 321, Address: 0x1966e4, Func Offset: 0x114
	// Line 322, Address: 0x1966e8, Func Offset: 0x118
	// Line 321, Address: 0x1966ec, Func Offset: 0x11c
	// Line 322, Address: 0x1966f4, Func Offset: 0x124
	// Line 323, Address: 0x1966fc, Func Offset: 0x12c
	// Line 322, Address: 0x196700, Func Offset: 0x130
	// Line 323, Address: 0x196708, Func Offset: 0x138
	// Line 324, Address: 0x196710, Func Offset: 0x140
	// Line 325, Address: 0x19671c, Func Offset: 0x14c
	// Line 326, Address: 0x196728, Func Offset: 0x158
	// Line 329, Address: 0x196734, Func Offset: 0x164
	// Line 330, Address: 0x196740, Func Offset: 0x170
	// Line 329, Address: 0x196744, Func Offset: 0x174
	// Line 330, Address: 0x19674c, Func Offset: 0x17c
	// Line 331, Address: 0x196760, Func Offset: 0x190
	// Line 336, Address: 0x196764, Func Offset: 0x194
	// Line 338, Address: 0x196780, Func Offset: 0x1b0
	// Line 340, Address: 0x19678c, Func Offset: 0x1bc
	// Line 341, Address: 0x1967a0, Func Offset: 0x1d0
	// Line 344, Address: 0x1967a4, Func Offset: 0x1d4
	// Line 347, Address: 0x1967a8, Func Offset: 0x1d8
	// Line 344, Address: 0x1967b4, Func Offset: 0x1e4
	// Line 345, Address: 0x1967b8, Func Offset: 0x1e8
	// Line 346, Address: 0x1967c0, Func Offset: 0x1f0
	// Line 347, Address: 0x1967c4, Func Offset: 0x1f4
	// Line 349, Address: 0x1967cc, Func Offset: 0x1fc
	// Line 351, Address: 0x1967d4, Func Offset: 0x204
	// Line 353, Address: 0x1967dc, Func Offset: 0x20c
	// Line 356, Address: 0x1967e4, Func Offset: 0x214
	// Line 357, Address: 0x196800, Func Offset: 0x230
	// Line 358, Address: 0x196810, Func Offset: 0x240
	// Line 360, Address: 0x19681c, Func Offset: 0x24c
	// Line 368, Address: 0x196820, Func Offset: 0x250
	// Func End, Address: 0x196834, Func Offset: 0x264
}*/

// 100% matching!
void bhEne02sub_MV04(BH_PWORK* epw)
{
	BH_PWORK* ep;

    ep = (BH_PWORK*)epw->lkwkp;
    
    switch (epw->mode3)
    {                         
    case 0:
        epw->flg |= 0x48;
        epw->mdflg &= ~0x1;
        
        epw->ct0 = 0;
        
        epw->px = ep->px + (20.0f * njSin(ep->ay));
        epw->pz = ep->pz + (20.0f * njCos(ep->ay));
        
        epw->ax = 0;
        epw->ay = ep->ay;
        
        epw->yn = ep->py - 5.0f;
        
        epw->spd = 1.0f;
        
        epw->mode3++;
    case 1:
        epw->ax += 2184;
        
        bhAddSpeed(epw, 0);
        
        epw->py = epw->yn + (2.0f * njSin((epw->ct0 * 2184) - 16384));
        
        bhEne02_SetSandEffect(ep, (NJS_POINT3*)&epw->px, 8);
        
        if (epw->ct0++ > 30)
        {
            epw->mdflg |= 0x1;
            epw->flg &= ~0x40;
            
            epw->mode2 = 0;
        }
        
        break;
    }
}
