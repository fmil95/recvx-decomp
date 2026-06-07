#include "../../../ps2/veronica/prog/en27.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"

void (*bhEne27_Mode0[6])(BH_PWORK*) = 
{
	bhEne27_Init,
	bhEne27_Move,
	bhEne27_Nage,
	bhEne27_Damage,
	bhEne27_Die,
	bhEne_Event
};     
void (*bhEne27_BrainType[1])(BH_PWORK*) = 
{
	bhEne27_BR00
}; 
void (*bhEne27_MoveMode2[3])(BH_PWORK*) = 
{
	bhEne27_MV00,
	bhEne27_MV01,
	bhEne27_MV02
}; 

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

// 99.94% matching
void bhEne27_Init(BH_PWORK* epw)
{
    ATR_WORK* fp;   
    int i;               
    int flr_n;         
    NJS_MKEY_F_MOD* mkfP; 
    
    epw->mnwP = (MN_WORK*)sys->plmthp;
    epw->mlwP = &plp->mdl[6];
    
    epw->mdl_no = 0;
    
    epw->skp[8] = plp->skp[7];
    
    epw->flg &= ~0x6;
    
    epw->mdflg |=  0x4;
    epw->mdflg &= ~0x1;
    
    if ((-rand() / -2.1474836E9f) < 0.3f) 
    {
        epw->ct2 = (unsigned int)(30.0f + (120.0f * (-rand() / -2.1474836E9f)));
    }
    else
    {
        epw->ct2 = 0;
    }
    
    epw->flg |= 0x80;
    
    epw->lkwkp = (unsigned char*)plp;
    epw->lkono = 3;
    
    if (epw->mode2 == 0) 
    {
        flr_n = rom->flr_n + sys->mflr_n;
        
        for (i = 0; i < flr_n; i++)
        {
            if (i < rom->flr_n)
            {
                fp = &rom->flrp[i];
            } 
            else
            {
                fp = &sys->mflrp[i - rom->flr_n];
            }
            
            if ((((fp->flg & 0x1)) && (fp->type == 2)) && (fp->prm0 == 27)) 
            {
                fp->prm2 = 0;
            }
        } 
    }
    
    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 0;
    epw->mode3 = 0;
    
    epw->hokan_rate = 65536;
    epw->hokan_count = 0;
    
    epw->mtn_no = epw->type + 93;
    epw->mtn_md = 0;
    epw->mtn_add = 65536;
    
    epw->frm_no = 0;
    
    mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
    
    epw->lox = mkfP->key[0];
    epw->loy = mkfP->key[1];
    epw->loz = mkfP->key[2];
    
    epw->loz -= 0.3f;
    
    epw->ax = 5461;
    
    epw->clp_jno[0] =  0;
    epw->clp_jno[1] = -1;
    
    epw->mdflg &= ~0x20;
}

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

// 
// Start address: 0x210090
void bhEne27_MV02(BH_PWORK* epw)
{
	//_anon33 vec;
	//_anon33 p2;
	//_anon33 p1;
	//_anon28* owk;
	//_anon33 vec;
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
	scePrintf("bhEne27_MV02 - UNIMPLEMENTED!\n");
}

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

// 100% matching!
void bhEne27_IncubateEffect(BH_PWORK* epw)
{
    sys->ef.id = 5;
    
    sys->ef.flg  = 1;
    sys->ef.type = 0;
    
    sys->ef.mdlver = 0;
    
    sys->ef.px = 0.0f;
    sys->ef.py = 0.0f;
    sys->ef.pz = 0.0f;
    
    sys->ef.sx = 1.0f;
    sys->ef.sy = 1.0f;
    sys->ef.sz = 1.0f;
    
    sys->ef.ay = 0;
    
    bhSetEffectTb(&sys->ef, (NJS_POINT3*)&epw->lox, epw->lkwkp, epw->lkono); 
}

// 100% matching!
void bhEne27_CallSE(BH_PWORK* epw)
{
    char NullTree[2] = { 0, 0xFF };  
    int fno;                    
    NJS_POINT3 pos;        
    
    bhEne_GetPartsPos(epw, NullTree, &pos);
    
    fno = epw->frm_no / 65536;
    
    switch (epw->mtn_no) 
    {                        
    case 93:
    case 94:
    case 95:
        if (fno == 0) 
        {
            bhEne_CallSE(epw, &pos, 74564);
        }
        
        if ((fno % 12) == 11) 
        {
            bhEne_CallSE(epw, &pos, 74565);
        }
        
        break;
    case 96:
        if ((fno % 10) == 9) 
        {
            bhEne_CallSE(epw, &pos, 74566);
        }
        
        break;
    }
}
