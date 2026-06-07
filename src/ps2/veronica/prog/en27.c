#include "../../../ps2/veronica/prog/en27.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"

void (*bhEne27_Mode0[6])(BH_PWORK*);     // DATA
void (*bhEne27_BrainType[1])(BH_PWORK*); // DATA
void (*bhEne27_MoveMode2[3])(BH_PWORK*); // DATA

// 100% matching!
void bhEne27(BH_PWORK* epw)
{
    bhEne27_Mode0[epw->mode0](epw);
    
    if (epw->mode2 > 1) 
    {
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        
        bhEne27_CallSE(epw); 
    }
}

/*// 
// Start address: 0x20fb50
void bhEne27_Init(BH_PWORK* epw)
{
	_anon19* mkfP;
	int flr_n;
	int i;
	_anon7* fp;
	// Line 150, Address: 0x20fb50, Func Offset: 0
	// Line 152, Address: 0x20fb5c, Func Offset: 0xc
	// Line 161, Address: 0x20fb64, Func Offset: 0x14
	// Line 163, Address: 0x20fb68, Func Offset: 0x18
	// Line 152, Address: 0x20fb70, Func Offset: 0x20
	// Line 154, Address: 0x20fb80, Func Offset: 0x30
	// Line 155, Address: 0x20fb90, Func Offset: 0x40
	// Line 158, Address: 0x20fb94, Func Offset: 0x44
	// Line 161, Address: 0x20fba4, Func Offset: 0x54
	// Line 162, Address: 0x20fbb0, Func Offset: 0x60
	// Line 163, Address: 0x20fbbc, Func Offset: 0x6c
	// Line 165, Address: 0x20fbc4, Func Offset: 0x74
	// Line 167, Address: 0x20fc0c, Func Offset: 0xbc
	// Line 168, Address: 0x20fc4c, Func Offset: 0xfc
	// Line 169, Address: 0x20fc54, Func Offset: 0x104
	// Line 173, Address: 0x20fc58, Func Offset: 0x108
	// Line 174, Address: 0x20fc5c, Func Offset: 0x10c
	// Line 175, Address: 0x20fc60, Func Offset: 0x110
	// Line 173, Address: 0x20fc64, Func Offset: 0x114
	// Line 174, Address: 0x20fc6c, Func Offset: 0x11c
	// Line 175, Address: 0x20fc74, Func Offset: 0x124
	// Line 178, Address: 0x20fc78, Func Offset: 0x128
	// Line 182, Address: 0x20fc84, Func Offset: 0x134
	// Line 183, Address: 0x20fca8, Func Offset: 0x158
	// Line 186, Address: 0x20fcb8, Func Offset: 0x168
	// Line 185, Address: 0x20fcc0, Func Offset: 0x170
	// Line 186, Address: 0x20fd0c, Func Offset: 0x1bc
	// Line 189, Address: 0x20fd34, Func Offset: 0x1e4
	// Line 191, Address: 0x20fd38, Func Offset: 0x1e8
	// Line 195, Address: 0x20fd48, Func Offset: 0x1f8
	// Line 196, Address: 0x20fd50, Func Offset: 0x200
	// Line 197, Address: 0x20fd54, Func Offset: 0x204
	// Line 198, Address: 0x20fd58, Func Offset: 0x208
	// Line 201, Address: 0x20fd5c, Func Offset: 0x20c
	// Line 202, Address: 0x20fd64, Func Offset: 0x214
	// Line 203, Address: 0x20fd68, Func Offset: 0x218
	// Line 218, Address: 0x20fd6c, Func Offset: 0x21c
	// Line 220, Address: 0x20fd78, Func Offset: 0x228
	// Line 203, Address: 0x20fd7c, Func Offset: 0x22c
	// Line 204, Address: 0x20fd84, Func Offset: 0x234
	// Line 205, Address: 0x20fd88, Func Offset: 0x238
	// Line 206, Address: 0x20fd8c, Func Offset: 0x23c
	// Line 212, Address: 0x20fd90, Func Offset: 0x240
	// Line 225, Address: 0x20fd98, Func Offset: 0x248
	// Line 226, Address: 0x20fd9c, Func Offset: 0x24c
	// Line 212, Address: 0x20fda0, Func Offset: 0x250
	// Line 213, Address: 0x20fdb8, Func Offset: 0x268
	// Line 214, Address: 0x20fdc0, Func Offset: 0x270
	// Line 215, Address: 0x20fdc8, Func Offset: 0x278
	// Line 218, Address: 0x20fdcc, Func Offset: 0x27c
	// Line 215, Address: 0x20fdd0, Func Offset: 0x280
	// Line 218, Address: 0x20fdd4, Func Offset: 0x284
	// Line 220, Address: 0x20fdd8, Func Offset: 0x288
	// Line 224, Address: 0x20fddc, Func Offset: 0x28c
	// Line 225, Address: 0x20fde0, Func Offset: 0x290
	// Line 226, Address: 0x20fde4, Func Offset: 0x294
	// Line 227, Address: 0x20fdf0, Func Offset: 0x2a0
	// Func End, Address: 0x20fe00, Func Offset: 0x2b0
}*/

// 100% matching!
void bhEne27_Brain(BH_PWORK* epw)
{
	bhEne27_BrainType[0](epw);
}

// 100% matching!
void bhEne27_BR00(BH_PWORK* epw)
{
    ATR_WORK* hp;
    
    if ((!(plp->flg & 0x4)) && (!(plp->stflg & 0x30))) 
    {
        hp = bhCheckFloorEnemy(plp->flr_no, plp->px, plp->pz);
        
        if ((hp != NULL) && ((hp->prm0 == 27) && (hp->prm2 == 0))) 
        {
            if ((hp->prm1 == 0) || (hp->prm1 == (epw->type + 1))) 
            {
                epw->mode2 = 1;
                epw->mode3 = 0;
                
                hp->prm2 = 1;
                return;
            }
        } 
        
        if (epw->ct2 > 0)
        {
            epw->ct2--;
            
            if (epw->ct2 == 0) 
            {
                epw->mode2 = 1;
                epw->mode3 = 0;
            }
        }
    }
}

// 100% matching!
void bhEne27_Move(BH_PWORK* epw)
{
    if (epw->mode1 == 1) 
    {
        bhEne27_Brain(epw);
    }
    
    bhEne27_MoveMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne27_MV00()
{

}

// 100% matching!
void bhEne27_MV01(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {
    case 0:
        epw->mlwP = &plp->mdl[7];
            
        epw->mdl_no = 8;
            
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
            
        bhEne27_IncubateEffect(epw);
            
        epw->lox = 0;
        epw->loy = 0;
        epw->loz = 0;
            
        epw->ax = 0;
        epw->ay = 0;
        epw->az = 0;
            
        plp->flg  |= 0x10004;
        plp->flg2 |= 0x1;
            
        plp->stflg |= 0x10000;
            
        plp->mode0 = 4;
        plp->mode2 = 0;
        plp->mode3 = 0;
            
        plp->mtn_no = 90;
        plp->frm_no = 0;
            
        plp->mtn_add = 0;
            
        plp->hokan_count = 10;
        plp->hokan_rate  = 45875;
        break;
    }
}

/*// 
// Start address: 0x210090
void bhEne27_MV02(BH_PWORK* epw)
{
	_anon33 vec;
	_anon33 p2;
	_anon33 p1;
	_anon28* owk;
	_anon33 vec;
	// Line 365, Address: 0x210090, Func Offset: 0
	// Line 366, Address: 0x2100a4, Func Offset: 0x14
	// Line 368, Address: 0x2100dc, Func Offset: 0x4c
	// Line 371, Address: 0x2100ec, Func Offset: 0x5c
	// Line 372, Address: 0x2100f8, Func Offset: 0x68
	// Line 373, Address: 0x2100fc, Func Offset: 0x6c
	// Line 374, Address: 0x21011c, Func Offset: 0x8c
	// Line 376, Address: 0x210120, Func Offset: 0x90
	// Line 378, Address: 0x21012c, Func Offset: 0x9c
	// Line 379, Address: 0x210140, Func Offset: 0xb0
	// Line 380, Address: 0x210150, Func Offset: 0xc0
	// Line 382, Address: 0x210160, Func Offset: 0xd0
	// Line 383, Address: 0x210168, Func Offset: 0xd8
	// Line 384, Address: 0x21016c, Func Offset: 0xdc
	// Line 385, Address: 0x210170, Func Offset: 0xe0
	// Line 387, Address: 0x210174, Func Offset: 0xe4
	// Line 389, Address: 0x210180, Func Offset: 0xf0
	// Line 390, Address: 0x210184, Func Offset: 0xf4
	// Line 387, Address: 0x210188, Func Offset: 0xf8
	// Line 388, Address: 0x21018c, Func Offset: 0xfc
	// Line 391, Address: 0x210194, Func Offset: 0x104
	// Line 393, Address: 0x210198, Func Offset: 0x108
	// Line 388, Address: 0x21019c, Func Offset: 0x10c
	// Line 389, Address: 0x2101a0, Func Offset: 0x110
	// Line 390, Address: 0x2101ac, Func Offset: 0x11c
	// Line 391, Address: 0x2101b8, Func Offset: 0x128
	// Line 394, Address: 0x2101c4, Func Offset: 0x134
	// Line 396, Address: 0x2101cc, Func Offset: 0x13c
	// Line 397, Address: 0x2101d4, Func Offset: 0x144
	// Line 398, Address: 0x2101d8, Func Offset: 0x148
	// Line 399, Address: 0x2101e0, Func Offset: 0x150
	// Line 401, Address: 0x2101e4, Func Offset: 0x154
	// Line 398, Address: 0x2101ec, Func Offset: 0x15c
	// Line 403, Address: 0x210200, Func Offset: 0x170
	// Line 404, Address: 0x210204, Func Offset: 0x174
	// Line 398, Address: 0x210208, Func Offset: 0x178
	// Line 399, Address: 0x210210, Func Offset: 0x180
	// Line 401, Address: 0x210214, Func Offset: 0x184
	// Line 405, Address: 0x210218, Func Offset: 0x188
	// Line 401, Address: 0x21021c, Func Offset: 0x18c
	// Line 402, Address: 0x210220, Func Offset: 0x190
	// Line 403, Address: 0x21022c, Func Offset: 0x19c
	// Line 404, Address: 0x210238, Func Offset: 0x1a8
	// Line 405, Address: 0x210244, Func Offset: 0x1b4
	// Line 409, Address: 0x210250, Func Offset: 0x1c0
	// Line 412, Address: 0x210264, Func Offset: 0x1d4
	// Line 414, Address: 0x210270, Func Offset: 0x1e0
	// Line 415, Address: 0x210274, Func Offset: 0x1e4
	// Line 412, Address: 0x210278, Func Offset: 0x1e8
	// Line 413, Address: 0x21027c, Func Offset: 0x1ec
	// Line 416, Address: 0x210284, Func Offset: 0x1f4
	// Line 413, Address: 0x210288, Func Offset: 0x1f8
	// Line 414, Address: 0x21028c, Func Offset: 0x1fc
	// Line 415, Address: 0x210298, Func Offset: 0x208
	// Line 416, Address: 0x2102a4, Func Offset: 0x214
	// Line 418, Address: 0x2102ac, Func Offset: 0x21c
	// Line 421, Address: 0x2102b4, Func Offset: 0x224
	// Line 423, Address: 0x2102c4, Func Offset: 0x234
	// Line 426, Address: 0x2102d4, Func Offset: 0x244
	// Line 423, Address: 0x2102d8, Func Offset: 0x248
	// Line 426, Address: 0x2102e0, Func Offset: 0x250
	// Line 427, Address: 0x2102e8, Func Offset: 0x258
	// Line 426, Address: 0x2102ec, Func Offset: 0x25c
	// Line 427, Address: 0x2102f4, Func Offset: 0x264
	// Line 429, Address: 0x21030c, Func Offset: 0x27c
	// Line 430, Address: 0x210310, Func Offset: 0x280
	// Line 433, Address: 0x210314, Func Offset: 0x284
	// Line 435, Address: 0x210320, Func Offset: 0x290
	// Line 436, Address: 0x210324, Func Offset: 0x294
	// Line 433, Address: 0x210328, Func Offset: 0x298
	// Line 434, Address: 0x21032c, Func Offset: 0x29c
	// Line 437, Address: 0x210334, Func Offset: 0x2a4
	// Line 434, Address: 0x210338, Func Offset: 0x2a8
	// Line 435, Address: 0x21033c, Func Offset: 0x2ac
	// Line 436, Address: 0x210348, Func Offset: 0x2b8
	// Line 437, Address: 0x210354, Func Offset: 0x2c4
	// Line 439, Address: 0x210360, Func Offset: 0x2d0
	// Line 440, Address: 0x210368, Func Offset: 0x2d8
	// Line 442, Address: 0x210370, Func Offset: 0x2e0
	// Line 444, Address: 0x210398, Func Offset: 0x308
	// Line 445, Address: 0x2103b0, Func Offset: 0x320
	// Line 444, Address: 0x2103b4, Func Offset: 0x324
	// Line 445, Address: 0x2103b8, Func Offset: 0x328
	// Line 446, Address: 0x2103c4, Func Offset: 0x334
	// Line 447, Address: 0x2103dc, Func Offset: 0x34c
	// Line 446, Address: 0x2103e8, Func Offset: 0x358
	// Line 447, Address: 0x2103ec, Func Offset: 0x35c
	// Line 449, Address: 0x210404, Func Offset: 0x374
	// Line 452, Address: 0x210410, Func Offset: 0x380
	// Line 455, Address: 0x210418, Func Offset: 0x388
	// Line 456, Address: 0x21042c, Func Offset: 0x39c
	// Line 457, Address: 0x210440, Func Offset: 0x3b0
	// Line 460, Address: 0x210450, Func Offset: 0x3c0
	// Line 461, Address: 0x210460, Func Offset: 0x3d0
	// Line 464, Address: 0x210464, Func Offset: 0x3d4
	// Line 460, Address: 0x210468, Func Offset: 0x3d8
	// Line 461, Address: 0x21046c, Func Offset: 0x3dc
	// Line 465, Address: 0x210470, Func Offset: 0x3e0
	// Line 460, Address: 0x210474, Func Offset: 0x3e4
	// Line 461, Address: 0x21047c, Func Offset: 0x3ec
	// Line 462, Address: 0x210484, Func Offset: 0x3f4
	// Line 461, Address: 0x210488, Func Offset: 0x3f8
	// Line 462, Address: 0x210490, Func Offset: 0x400
	// Line 463, Address: 0x210498, Func Offset: 0x408
	// Line 462, Address: 0x21049c, Func Offset: 0x40c
	// Line 463, Address: 0x2104a4, Func Offset: 0x414
	// Line 464, Address: 0x2104ac, Func Offset: 0x41c
	// Line 465, Address: 0x2104b8, Func Offset: 0x428
	// Line 464, Address: 0x2104bc, Func Offset: 0x42c
	// Line 465, Address: 0x2104c4, Func Offset: 0x434
	// Line 467, Address: 0x2104cc, Func Offset: 0x43c
	// Line 468, Address: 0x2104f4, Func Offset: 0x464
	// Line 469, Address: 0x210520, Func Offset: 0x490
	// Line 472, Address: 0x21054c, Func Offset: 0x4bc
	// Line 474, Address: 0x21055c, Func Offset: 0x4cc
	// Line 480, Address: 0x210564, Func Offset: 0x4d4
	// Line 482, Address: 0x210574, Func Offset: 0x4e4
	// Line 483, Address: 0x210578, Func Offset: 0x4e8
	// Line 482, Address: 0x21057c, Func Offset: 0x4ec
	// Line 483, Address: 0x210584, Func Offset: 0x4f4
	// Line 485, Address: 0x210590, Func Offset: 0x500
	// Line 486, Address: 0x210598, Func Offset: 0x508
	// Line 491, Address: 0x21059c, Func Offset: 0x50c
	// Line 485, Address: 0x2105a0, Func Offset: 0x510
	// Line 486, Address: 0x2105a8, Func Offset: 0x518
	// Line 493, Address: 0x2105ac, Func Offset: 0x51c
	// Line 486, Address: 0x2105b0, Func Offset: 0x520
	// Line 487, Address: 0x2105b4, Func Offset: 0x524
	// Line 486, Address: 0x2105b8, Func Offset: 0x528
	// Line 487, Address: 0x2105bc, Func Offset: 0x52c
	// Line 488, Address: 0x2105c4, Func Offset: 0x534
	// Line 487, Address: 0x2105c8, Func Offset: 0x538
	// Line 488, Address: 0x2105cc, Func Offset: 0x53c
	// Line 489, Address: 0x2105d4, Func Offset: 0x544
	// Line 488, Address: 0x2105d8, Func Offset: 0x548
	// Line 489, Address: 0x2105dc, Func Offset: 0x54c
	// Line 491, Address: 0x2105e8, Func Offset: 0x558
	// Line 492, Address: 0x2105ec, Func Offset: 0x55c
	// Line 493, Address: 0x2105f0, Func Offset: 0x560
	// Line 496, Address: 0x2105f4, Func Offset: 0x564
	// Line 497, Address: 0x210604, Func Offset: 0x574
	// Line 498, Address: 0x21061c, Func Offset: 0x58c
	// Line 499, Address: 0x210628, Func Offset: 0x598
	// Line 500, Address: 0x210634, Func Offset: 0x5a4
	// Line 501, Address: 0x210644, Func Offset: 0x5b4
	// Line 503, Address: 0x210648, Func Offset: 0x5b8
	// Line 508, Address: 0x210658, Func Offset: 0x5c8
	// Line 510, Address: 0x21065c, Func Offset: 0x5cc
	// Line 511, Address: 0x210660, Func Offset: 0x5d0
	// Line 513, Address: 0x210664, Func Offset: 0x5d4
	// Line 508, Address: 0x210668, Func Offset: 0x5d8
	// Line 517, Address: 0x21066c, Func Offset: 0x5dc
	// Line 509, Address: 0x210678, Func Offset: 0x5e8
	// Line 517, Address: 0x21067c, Func Offset: 0x5ec
	// Line 509, Address: 0x210680, Func Offset: 0x5f0
	// Line 510, Address: 0x210684, Func Offset: 0x5f4
	// Line 511, Address: 0x21068c, Func Offset: 0x5fc
	// Line 512, Address: 0x210694, Func Offset: 0x604
	// Line 513, Address: 0x2106a4, Func Offset: 0x614
	// Line 514, Address: 0x2106b4, Func Offset: 0x624
	// Line 517, Address: 0x2106c0, Func Offset: 0x630
	// Line 518, Address: 0x2106d0, Func Offset: 0x640
	// Line 519, Address: 0x2106d8, Func Offset: 0x648
	// Line 520, Address: 0x2106e0, Func Offset: 0x650
	// Line 521, Address: 0x2106ec, Func Offset: 0x65c
	// Line 520, Address: 0x2106f4, Func Offset: 0x664
	// Line 521, Address: 0x2106f8, Func Offset: 0x668
	// Line 524, Address: 0x21070c, Func Offset: 0x67c
	// Line 528, Address: 0x210710, Func Offset: 0x680
	// Line 524, Address: 0x21071c, Func Offset: 0x68c
	// Line 525, Address: 0x210724, Func Offset: 0x694
	// Line 528, Address: 0x21072c, Func Offset: 0x69c
	// Line 531, Address: 0x210734, Func Offset: 0x6a4
	// Line 534, Address: 0x210748, Func Offset: 0x6b8
	// Line 535, Address: 0x210750, Func Offset: 0x6c0
	// Line 536, Address: 0x210760, Func Offset: 0x6d0
	// Line 537, Address: 0x210770, Func Offset: 0x6e0
	// Line 541, Address: 0x210780, Func Offset: 0x6f0
	// Line 542, Address: 0x210790, Func Offset: 0x700
	// Line 545, Address: 0x210794, Func Offset: 0x704
	// Func End, Address: 0x2107a8, Func Offset: 0x718
}*/

// 100% matching!
void bhEne27_Nage()
{
	
}

// 100% matching!
void bhEne27_Damage()
{

}

// 100% matching!
void bhEne27_Die()
{

}

// 
// Start address: 0x2107e0
void bhEne27_IncubateEffect(BH_PWORK* epw)
{
	// Line 589, Address: 0x2107e0, Func Offset: 0
	// Line 590, Address: 0x2107ec, Func Offset: 0xc
	// Line 596, Address: 0x2107f0, Func Offset: 0x10
	// Line 589, Address: 0x2107f4, Func Offset: 0x14
	// Line 590, Address: 0x210800, Func Offset: 0x20
	// Line 601, Address: 0x210808, Func Offset: 0x28
	// Line 590, Address: 0x21080c, Func Offset: 0x2c
	// Line 591, Address: 0x210818, Func Offset: 0x38
	// Line 592, Address: 0x21082c, Func Offset: 0x4c
	// Line 593, Address: 0x210840, Func Offset: 0x60
	// Line 594, Address: 0x210854, Func Offset: 0x74
	// Line 595, Address: 0x210868, Func Offset: 0x88
	// Line 596, Address: 0x21087c, Func Offset: 0x9c
	// Line 597, Address: 0x210890, Func Offset: 0xb0
	// Line 598, Address: 0x2108a4, Func Offset: 0xc4
	// Line 599, Address: 0x2108b8, Func Offset: 0xd8
	// Line 601, Address: 0x2108cc, Func Offset: 0xec
	// Func End, Address: 0x2108ec, Func Offset: 0x10c
	scePrintf("bhEne27_IncubateEffect - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2108f0
void bhEne27_CallSE(BH_PWORK* epw)
{
	//_anon33 pos;
	int fno;
	char NullTree[2];
	// Line 615, Address: 0x2108f0, Func Offset: 0
	// Line 616, Address: 0x2108fc, Func Offset: 0xc
	// Line 615, Address: 0x210904, Func Offset: 0x14
	// Line 616, Address: 0x210908, Func Offset: 0x18
	// Line 621, Address: 0x210910, Func Offset: 0x20
	// Line 622, Address: 0x210920, Func Offset: 0x30
	// Line 624, Address: 0x210924, Func Offset: 0x34
	// Line 628, Address: 0x210960, Func Offset: 0x70
	// Line 629, Address: 0x210968, Func Offset: 0x78
	// Line 631, Address: 0x21097c, Func Offset: 0x8c
	// Line 632, Address: 0x21099c, Func Offset: 0xac
	// Line 634, Address: 0x2109b0, Func Offset: 0xc0
	// Line 636, Address: 0x2109b8, Func Offset: 0xc8
	// Line 637, Address: 0x2109d8, Func Offset: 0xe8
	// Line 641, Address: 0x2109ec, Func Offset: 0xfc
	// Func End, Address: 0x210a00, Func Offset: 0x110
	scePrintf("bhEne27_CallSE - UNIMPLEMENTED!\n");
}
