#include "subpl.h"
#include "MdlPut.h"
#include "Motion.h"

typedef void (*Subpl_proc)(BH_PWORK*);
typedef void (*InitSubpl_proc)(BH_PWORK*);
typedef void (*MvSubpl_proc)(BH_PWORK*);
typedef void (*Mv00Subpl_proc)(BH_PWORK*);
typedef void (*Mv01Subpl_proc)(BH_PWORK*);

Subpl_proc Subpl_tbl[7] = 
{
    init_subpl,
    move_subpl,
    NULL,
    NULL,
    NULL,
    em_sce,
    em_sce
};
InitSubpl_proc subpl_init_tbl[120] = { em60_init };
MvSubpl_proc subpl_mv_tbl[1] = { bhEne_Event2 };
Mv00Subpl_proc subpl_mv00_tbl[15] = 
{
    mv00_subpl0,
    mv00_subpl1,
    mv00_subpl2,
    mv00_subpl3,
    mv00_subpl5,
    mv00_subpl6,
    mv00_subpl0_1,
    mv00_subpl0,
    mv00_subpl0,
    mv00_subpl1,
    mv00_subpl0Ex,
    mv00_subpl0,
    mv00_subpl0,
    mv00_subpl0,
    mv00_subpl0
}; 
Mv01Subpl_proc subpl_mv01_tbl[15] = 
{
    mv00_subpl2,
    mv00_subpl3,
    mv00_subpl2,
    mv00_subpl3,
    mv00_subpl5,
    mv00_subpl6,
    mv00_subpl2_0,
    mv00_subpl3_0,
    mv00_subpl0,
    mv00_subpl1,
    mv00_subpl10,
    mv00_subpl0,
    mv00_subpl0,
    mv00_subpl0,
    mv00_subpl0
};

// 100% matching!
void bhSubpl(BH_PWORK* epw)
{
    epw->flg |= 0x8100;
    epw->flg &= ~0x2;
    
    Subpl_tbl[epw->mode0](epw);
    
    bhCalcModel(epw);
}

// 100% matching! 
void init_subpl(BH_PWORK* epw)
{
    epw->mode0 = 1;
    
    subpl_init_tbl[epw->id - 40](epw);
}

// 100% matching! 
void em60_init(BH_PWORK* epw)
{
    epw->hokan_rate = 0;
    epw->hokan_count = 0;
    
    epw->mtn_add = 32768;
    
    epw->frm_no = 0;
    
    epw->mtn_no = 0;
    epw->mtn_md = 0x20;
    epw->mtn_tp = NULL;
    
    epw->frm_mode = 0;
    
    epw->mode3 = 3;

    if (epw->id == 199) 
    {
        epw->mlwP->objP += 8;
        epw->mlwP->owP += 8;
        
        epw->mlwP->obj_num -= 8;
        
        bhSetMotion(epw, (int)epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        
        epw->mlwP->obj_num += 8;
        
        epw->mlwP->owP -= 8;
        epw->mlwP->objP -= 8;
    }

    bhSetMotion(epw, (int)epw->mtn_add, epw->mtn_md, epw->mtn_tp);
}

// 100% matching!
void move_subpl(BH_PWORK* epw)
{
    subpl_mv_tbl[epw->mode2](epw);
}

// 100% matching!
void em_sce(BH_PWORK* epw)
{
    subpl_mv01_tbl[epw->ct2](epw);
}

// 100% matching!
void bhEne_Event(BH_PWORK* epw)
{
    subpl_mv01_tbl[epw->ct2](epw);
}

// 100% matching!
void bhEne_Event2(BH_PWORK* epw)
{
    subpl_mv00_tbl[epw->ct2](epw);
}

// 100% matching!
void mv00_subpl0(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {                              
    case 0:
        epw->mode3 = 1;
        
        epw->mtn_no = epw->mode1;
        
        epw->hokan_count = 8;
        epw->hokan_rate = 0;
        
        epw->mtn_md &= ~0x100;
        
        epw->frm_mode = 0;
    case 1:
        bhSetMotion(epw, (int)epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        break;
    }
}

// 
// Start address: 0x174130
void mv00_subpl0Ex(BH_PWORK* epw)
{
	// Line 313, Address: 0x174130, Func Offset: 0
	// Line 314, Address: 0x174138, Func Offset: 0x8
	// Line 316, Address: 0x174158, Func Offset: 0x28
	// Line 317, Address: 0x17415c, Func Offset: 0x2c
	// Line 325, Address: 0x174160, Func Offset: 0x30
	// Line 317, Address: 0x174164, Func Offset: 0x34
	// Line 321, Address: 0x174168, Func Offset: 0x38
	// Line 325, Address: 0x17416c, Func Offset: 0x3c
	// Line 328, Address: 0x174178, Func Offset: 0x48
	// Line 346, Address: 0x17417c, Func Offset: 0x4c
	// Line 348, Address: 0x17418c, Func Offset: 0x5c
	// Func End, Address: 0x174198, Func Offset: 0x68
	scePrintf("mv00_subpl0Ex - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1741a0
void mv00_subpl1(BH_PWORK* epw)
{
	// Line 353, Address: 0x1741a0, Func Offset: 0
	// Line 357, Address: 0x1741b0, Func Offset: 0x10
	// Line 359, Address: 0x1741d0, Func Offset: 0x30
	// Line 360, Address: 0x1741d4, Func Offset: 0x34
	// Line 361, Address: 0x1741d8, Func Offset: 0x38
	// Line 360, Address: 0x1741dc, Func Offset: 0x3c
	// Line 361, Address: 0x1741e0, Func Offset: 0x40
	// Line 364, Address: 0x1741e4, Func Offset: 0x44
	// Line 368, Address: 0x1741e8, Func Offset: 0x48
	// Line 370, Address: 0x1741ec, Func Offset: 0x4c
	// Line 377, Address: 0x1741f0, Func Offset: 0x50
	// Line 379, Address: 0x17423c, Func Offset: 0x9c
	// Line 377, Address: 0x174248, Func Offset: 0xa8
	// Line 379, Address: 0x174250, Func Offset: 0xb0
	// Line 381, Address: 0x174260, Func Offset: 0xc0
	// Line 382, Address: 0x174274, Func Offset: 0xd4
	// Line 384, Address: 0x174280, Func Offset: 0xe0
	// Func End, Address: 0x174290, Func Offset: 0xf0
	scePrintf("mv00_subpl1 - UNIMPLEMENTED!\n");
}

// 100% matching! 
void mv00_subpl2(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {
    case 0:
        epw->mode3 = 1;
        
        epw->mtn_no = epw->mode1;
        
        epw->hokan_count = 8;
        
        epw->frm_mode = 0;
        
        epw->spd = 0;
        break;
    }
}

// 100% matching! 
void mv00_subpl2_0(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {
    case 0:
        epw->mode3 = 1;
        
        epw->mtn_no = epw->mode1;
        
        epw->hokan_count = 0;
        
        epw->frm_mode = 0;
        
        epw->spd = 0;
        break;
    }
}

// 
// Start address: 0x174310
void mv00_subpl3(BH_PWORK* epw)
{
	// Line 431, Address: 0x174310, Func Offset: 0
	// Line 435, Address: 0x174320, Func Offset: 0x10
	// Line 437, Address: 0x174340, Func Offset: 0x30
	// Line 438, Address: 0x174344, Func Offset: 0x34
	// Line 439, Address: 0x174348, Func Offset: 0x38
	// Line 438, Address: 0x17434c, Func Offset: 0x3c
	// Line 439, Address: 0x174350, Func Offset: 0x40
	// Line 446, Address: 0x174354, Func Offset: 0x44
	// Line 454, Address: 0x174358, Func Offset: 0x48
	// Line 456, Address: 0x1743a4, Func Offset: 0x94
	// Line 458, Address: 0x1743b0, Func Offset: 0xa0
	// Line 454, Address: 0x1743b8, Func Offset: 0xa8
	// Line 456, Address: 0x1743c0, Func Offset: 0xb0
	// Line 458, Address: 0x1743cc, Func Offset: 0xbc
	// Line 460, Address: 0x1743d4, Func Offset: 0xc4
	// Func End, Address: 0x1743e4, Func Offset: 0xd4
	scePrintf("mv00_subpl3 - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x1743f0
void mv00_subpl3_0(BH_PWORK* epw)
{
	// Line 466, Address: 0x1743f0, Func Offset: 0
	// Line 470, Address: 0x174400, Func Offset: 0x10
	// Line 472, Address: 0x174420, Func Offset: 0x30
	// Line 473, Address: 0x174424, Func Offset: 0x34
	// Line 474, Address: 0x17442c, Func Offset: 0x3c
	// Line 481, Address: 0x174430, Func Offset: 0x40
	// Line 489, Address: 0x174434, Func Offset: 0x44
	// Line 491, Address: 0x174480, Func Offset: 0x90
	// Line 493, Address: 0x17448c, Func Offset: 0x9c
	// Line 489, Address: 0x174494, Func Offset: 0xa4
	// Line 491, Address: 0x17449c, Func Offset: 0xac
	// Line 493, Address: 0x1744a8, Func Offset: 0xb8
	// Line 495, Address: 0x1744b0, Func Offset: 0xc0
	// Func End, Address: 0x1744c0, Func Offset: 0xd0
}*/

// 
// Start address: 0x1744c0
void mv00_subpl5(BH_PWORK* epw)
{
	// Line 501, Address: 0x1744c0, Func Offset: 0
	// Line 502, Address: 0x1744c8, Func Offset: 0x8
	// Line 504, Address: 0x1744e8, Func Offset: 0x28
	// Line 505, Address: 0x1744ec, Func Offset: 0x2c
	// Line 507, Address: 0x1744f0, Func Offset: 0x30
	// Line 505, Address: 0x1744f4, Func Offset: 0x34
	// Line 506, Address: 0x1744f8, Func Offset: 0x38
	// Line 507, Address: 0x1744fc, Func Offset: 0x3c
	// Line 513, Address: 0x174500, Func Offset: 0x40
	// Line 515, Address: 0x174504, Func Offset: 0x44
	// Line 518, Address: 0x174508, Func Offset: 0x48
	// Line 520, Address: 0x174518, Func Offset: 0x58
	// Func End, Address: 0x174524, Func Offset: 0x64
	scePrintf("mv00_subpl5 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x174530
void mv00_subpl6(BH_PWORK* epw)
{
	// Line 525, Address: 0x174530, Func Offset: 0
	// Line 526, Address: 0x174538, Func Offset: 0x8
	// Line 528, Address: 0x174558, Func Offset: 0x28
	// Line 529, Address: 0x17455c, Func Offset: 0x2c
	// Line 530, Address: 0x174560, Func Offset: 0x30
	// Line 532, Address: 0x174564, Func Offset: 0x34
	// Line 529, Address: 0x174568, Func Offset: 0x38
	// Line 530, Address: 0x17456c, Func Offset: 0x3c
	// Line 532, Address: 0x174570, Func Offset: 0x40
	// Line 538, Address: 0x174574, Func Offset: 0x44
	// Line 539, Address: 0x174580, Func Offset: 0x50
	// Line 541, Address: 0x174584, Func Offset: 0x54
	// Line 544, Address: 0x174588, Func Offset: 0x58
	// Line 546, Address: 0x174598, Func Offset: 0x68
	// Func End, Address: 0x1745a4, Func Offset: 0x74
	scePrintf("mv00_subpl6 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1745b0
void mv00_subpl0_1(BH_PWORK* epw)
{
	// Line 551, Address: 0x1745b0, Func Offset: 0
	// Line 552, Address: 0x1745b8, Func Offset: 0x8
	// Line 554, Address: 0x1745d8, Func Offset: 0x28
	// Line 555, Address: 0x1745dc, Func Offset: 0x2c
	// Line 556, Address: 0x1745e4, Func Offset: 0x34
	// Line 557, Address: 0x1745e8, Func Offset: 0x38
	// Line 559, Address: 0x1745ec, Func Offset: 0x3c
	// Line 561, Address: 0x1745fc, Func Offset: 0x4c
	// Func End, Address: 0x174608, Func Offset: 0x58
	scePrintf("mv00_subpl0_1 - UNIMPLEMENTED!\n");
}

// 100% matching! 
int bhSub_DirTarget(BH_PWORK* epw, float x, float z, int ay)
{
    int ang;
    
    ang = atan2f(epw->px - x, epw->pz - z) * 10430.381f;
    
    ang = (short)(ang - epw->ay);
    
    if (ay < abs(ang)) 
    {  
        ang = (ang > 0) ? ay : -ay;
    }
    
    return ang;
}

// 100% matching! 
void mv00_subpl10(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {
    case 0:
        epw->mode3 = 1;
        
        epw->mtn_no = epw->mode1;
        
        epw->frm_mode = 0;
        
        epw->spd = 0;
        break;
    }
}
