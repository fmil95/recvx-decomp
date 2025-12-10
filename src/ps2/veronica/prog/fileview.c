#include "fileview.h"
#include "message.h"
#include "ps2_texture.h"
#include "sdfunc.h"

/*unsigned int fstbl[24];
unsigned int fsheader[24];
unsigned int wallpaper[24];*/
typedef void (*FileViewMode_proc)();
FileViewMode_proc FileViewMode[5] = { FileSelect, FileViewInit, FileViewMain, FileViewExit, FileGetWait };
FV_WORK fvwork;
PARTS parts_22b[6]; // TODO: need to define data here
SYS_WORK* sys;
S_WORK swork;
/*char ViewCnt;
_anon23 tbuf[0];
unsigned char menuanim[4][0];
_anon35 parts_00b[24];
_anon35 parts_10b[0];
_anon14 sitem;*/
float cen_pos[12][6] = { { 0,       0,       0,      0,      0,       0       }, 
                         { 28.0f,   -80.0f,  28.0f,  40.0f,  0,       120.0f  }, 
                         { -448.0f, 100.0f,  0,      100.0f, 448.0f,  0       }, 
                         { 640.0f,  40.0f,   352.0f, 40.0f,  -288.0f, 0       }, 
                         { 808.0f,  40.0f,   520.0f, 40.0f,  -288.0f, 0       }, 
                         { 644.0f,  120.0f,  436.0f, 120.0f, -208.0f, 0       }, 
                         { 28.0f,   484.0f,  28.0f,  332.0f, 0,       -152.0f }, 
                         { 328.0f,  120.0f,  328.0f, 120.0f, 0,       0       },
                         { -380.0f, 132.0f,  60.0f,  132.0f, 440.0f,  0       }, 
                         { 644.0f,  40.0f,   436.0f, 40.0f,  -204.0f, 0       }, 
                         { 28.0f,   -384.0f, 28.0f,  40.0f,  0,       424.0f  }, 
                         { 660.0f,  120.0f,  452.0f, 120.0f, -208.0f, 0       } }; 
float cen_pos99[12][6] = { { 0,       0,       0,      0,      0,       0       },       
                           { 28.0f,   -80.0f,  28.0f,  40.0f,  0,       120.0f  }, 
                           { -448.0f, 100.0f,  0,      100.0f, 448.0f,  0       },       
                           { 640.0f,  40.0f,   352.0f, 40.0f,  -288.0f, 0       }, 
                           { 808.0f,  40.0f,   520.0f, 40.0f,  -288.0f, 0       },       
                           { 644.0f,  120.0f,  436.0f, 120.0f, -208.0f, 0       }, 
                           { 28.0f,   484.0f,  28.0f,  332.0f, 0,       -152.0f }, 
                           { 328.0f,  120.0f,  328.0f, 120.0f, 0,       0       }, 
                           { -380.0f, 132.0f,  60.0f,  132.0f, 440.0f,  0       },       
                           { 644.0f,  40.0f,   436.0f, 40.0f,  -204.0f, 0       }, 
                           { 28.0f,   -384.0f, 28.0f,  40.0f,  0,       424.0f  },  
                           { 660.0f,  120.0f,  452.0f, 120.0f, -208.0f, 0       } }; 

// 100% matching!
void ControlFileView()
{
    FileViewMode[fvwork.mode_00]();
    
    ReadFstx();
}

// 
// Start address: 0x2ac000
void FileSelect()
{
	//_anon11* fv;
	// Line 171, Address: 0x2ac000, Func Offset: 0
	// Line 175, Address: 0x2ac008, Func Offset: 0x8
	// Line 173, Address: 0x2ac00c, Func Offset: 0xc
	// Line 175, Address: 0x2ac014, Func Offset: 0x14
	// Line 178, Address: 0x2ac040, Func Offset: 0x40
	// Line 180, Address: 0x2ac044, Func Offset: 0x44
	// Line 181, Address: 0x2ac04c, Func Offset: 0x4c
	// Line 184, Address: 0x2ac054, Func Offset: 0x54
	// Line 185, Address: 0x2ac05c, Func Offset: 0x5c
	// Line 187, Address: 0x2ac064, Func Offset: 0x64
	// Line 190, Address: 0x2ac06c, Func Offset: 0x6c
	// Func End, Address: 0x2ac078, Func Offset: 0x78
	scePrintf("FileSelect - UNIMPLEMENTED!\n");
}

// 74.29% matching
void FileFlagInit01()
{
    fvwork.mode_00 = 1;
    fvwork.mode_01 = 0;
    
    parts_22b[2].atr &= ~0x20;
    
    fvwork.afsmode &= 0x780;
    
    parts_22b[3].atr &= ~0x20;
    
    fvwork.page = 0;
   
    njClipZ(-2.0f, -20000.0f); 
}

/*// 
// Start address: 0x2ac0f0
void FileFlagInit()
{
	// Line 219, Address: 0x2ac0f0, Func Offset: 0
	// Line 214, Address: 0x2ac0f8, Func Offset: 0x8
	// Line 215, Address: 0x2ac104, Func Offset: 0x14
	// Line 218, Address: 0x2ac10c, Func Offset: 0x1c
	// Line 219, Address: 0x2ac114, Func Offset: 0x24
	// Line 220, Address: 0x2ac120, Func Offset: 0x30
	// Line 218, Address: 0x2ac128, Func Offset: 0x38
	// Line 220, Address: 0x2ac134, Func Offset: 0x44
	// Line 221, Address: 0x2ac13c, Func Offset: 0x4c
	// Func End, Address: 0x2ac144, Func Offset: 0x54
}*/

// 100% matching!
void GetFile()
{
    FV_WORK* fv;
    S_WORK* st;
    unsigned int id;

    fv = &fvwork;

    st = &swork;

    if ((sys->cb_flg & 0x20000))
    {
        id = sys->sb_id;
    } 
    else
    {
        id = st->itemid;
    }
    
    fv->filenum = FileNumberSwitch(id);
    
    sys->itm[383] |= 1 << fv->filenum;
    
    fv->page = 0;
}

// 
// Start address: 0x2ac1e0
void FileViewInit()
{
	//_anon11* fv;
	//_anon12* st;
	// Line 247, Address: 0x2ac1e0, Func Offset: 0
	// Line 250, Address: 0x2ac1ec, Func Offset: 0xc
	// Line 248, Address: 0x2ac1f0, Func Offset: 0x10
	// Line 250, Address: 0x2ac1f8, Func Offset: 0x18
	// Line 249, Address: 0x2ac1fc, Func Offset: 0x1c
	// Line 250, Address: 0x2ac200, Func Offset: 0x20
	// Line 253, Address: 0x2ac228, Func Offset: 0x48
	// Line 254, Address: 0x2ac25c, Func Offset: 0x7c
	// Line 255, Address: 0x2ac264, Func Offset: 0x84
	// Line 256, Address: 0x2ac274, Func Offset: 0x94
	// Line 257, Address: 0x2ac284, Func Offset: 0xa4
	// Line 256, Address: 0x2ac288, Func Offset: 0xa8
	// Line 257, Address: 0x2ac294, Func Offset: 0xb4
	// Line 261, Address: 0x2ac298, Func Offset: 0xb8
	// Line 262, Address: 0x2ac2bc, Func Offset: 0xdc
	// Line 263, Address: 0x2ac2c4, Func Offset: 0xe4
	// Line 264, Address: 0x2ac2d4, Func Offset: 0xf4
	// Line 269, Address: 0x2ac2dc, Func Offset: 0xfc
	// Line 271, Address: 0x2ac2e4, Func Offset: 0x104
	// Line 274, Address: 0x2ac2f8, Func Offset: 0x118
	// Line 277, Address: 0x2ac300, Func Offset: 0x120
	// Line 278, Address: 0x2ac308, Func Offset: 0x128
	// Line 279, Address: 0x2ac318, Func Offset: 0x138
	// Line 280, Address: 0x2ac324, Func Offset: 0x144
	// Line 281, Address: 0x2ac328, Func Offset: 0x148
	// Line 283, Address: 0x2ac330, Func Offset: 0x150
	// Line 284, Address: 0x2ac334, Func Offset: 0x154
	// Line 282, Address: 0x2ac338, Func Offset: 0x158
	// Line 281, Address: 0x2ac340, Func Offset: 0x160
	// Line 282, Address: 0x2ac34c, Func Offset: 0x16c
	// Line 283, Address: 0x2ac358, Func Offset: 0x178
	// Line 284, Address: 0x2ac36c, Func Offset: 0x18c
	// Line 285, Address: 0x2ac370, Func Offset: 0x190
	// Line 286, Address: 0x2ac374, Func Offset: 0x194
	// Line 288, Address: 0x2ac378, Func Offset: 0x198
	// Line 292, Address: 0x2ac380, Func Offset: 0x1a0
	// Func End, Address: 0x2ac390, Func Offset: 0x1b0
	scePrintf("FileViewInit - UNIMPLEMENTED!\n");
}

// 100% matching!
void FileViewMain()
{
    FV_WORK* fv;
    
    fv = &fvwork;

    switch (fv->mode_01) 
    {                   
    case 0:
        fv->mode_01 = 1;
    case 1:
        FileScrollSet();
        
        PageScroll();
        
        FileEtcDisplay();
        break;
    }
}

// 100% matching!
void FileViewExit()
{
    if ((sys->cb_flg & 0x20000)) 
    {
        FileExit00();
    }
    else
    {
        FileExit01();
    }
}

/*// 
// Start address: 0x2ac440
void FileExit00()
{
	// Line 326, Address: 0x2ac440, Func Offset: 0
	// Line 356, Address: 0x2ac454, Func Offset: 0x14
	// Func End, Address: 0x2ac45c, Func Offset: 0x1c
}

// 
// Start address: 0x2ac460
void FileExit01()
{
	unsigned int* itm;
	unsigned int* wp;
	int num;
	_anon11* fv;
	_anon12* st;
	// Line 360, Address: 0x2ac460, Func Offset: 0
	// Line 363, Address: 0x2ac46c, Func Offset: 0xc
	// Line 361, Address: 0x2ac474, Func Offset: 0x14
	// Line 362, Address: 0x2ac47c, Func Offset: 0x1c
	// Line 365, Address: 0x2ac480, Func Offset: 0x20
	// Line 363, Address: 0x2ac484, Func Offset: 0x24
	// Line 365, Address: 0x2ac498, Func Offset: 0x38
	// Line 366, Address: 0x2ac4a8, Func Offset: 0x48
	// Line 367, Address: 0x2ac4bc, Func Offset: 0x5c
	// Line 368, Address: 0x2ac4c8, Func Offset: 0x68
	// Line 370, Address: 0x2ac4d0, Func Offset: 0x70
	// Line 369, Address: 0x2ac4d8, Func Offset: 0x78
	// Line 371, Address: 0x2ac4dc, Func Offset: 0x7c
	// Line 368, Address: 0x2ac4e0, Func Offset: 0x80
	// Line 369, Address: 0x2ac4ec, Func Offset: 0x8c
	// Line 372, Address: 0x2ac4f4, Func Offset: 0x94
	// Line 369, Address: 0x2ac4f8, Func Offset: 0x98
	// Line 370, Address: 0x2ac504, Func Offset: 0xa4
	// Line 371, Address: 0x2ac518, Func Offset: 0xb8
	// Line 372, Address: 0x2ac51c, Func Offset: 0xbc
	// Line 373, Address: 0x2ac520, Func Offset: 0xc0
	// Line 376, Address: 0x2ac524, Func Offset: 0xc4
	// Line 377, Address: 0x2ac52c, Func Offset: 0xcc
	// Line 378, Address: 0x2ac538, Func Offset: 0xd8
	// Line 379, Address: 0x2ac540, Func Offset: 0xe0
	// Line 380, Address: 0x2ac548, Func Offset: 0xe8
	// Line 381, Address: 0x2ac54c, Func Offset: 0xec
	// Line 385, Address: 0x2ac550, Func Offset: 0xf0
	// Line 379, Address: 0x2ac554, Func Offset: 0xf4
	// Line 380, Address: 0x2ac560, Func Offset: 0x100
	// Line 389, Address: 0x2ac568, Func Offset: 0x108
	// Line 380, Address: 0x2ac56c, Func Offset: 0x10c
	// Line 381, Address: 0x2ac578, Func Offset: 0x118
	// Line 382, Address: 0x2ac57c, Func Offset: 0x11c
	// Line 385, Address: 0x2ac580, Func Offset: 0x120
	// Line 383, Address: 0x2ac588, Func Offset: 0x128
	// Line 384, Address: 0x2ac59c, Func Offset: 0x13c
	// Line 386, Address: 0x2ac5b0, Func Offset: 0x150
	// Line 387, Address: 0x2ac5b4, Func Offset: 0x154
	// Line 388, Address: 0x2ac5b8, Func Offset: 0x158
	// Line 389, Address: 0x2ac5bc, Func Offset: 0x15c
	// Line 402, Address: 0x2ac5d0, Func Offset: 0x170
	// Line 403, Address: 0x2ac5e8, Func Offset: 0x188
	// Line 404, Address: 0x2ac5fc, Func Offset: 0x19c
	// Line 416, Address: 0x2ac600, Func Offset: 0x1a0
	// Line 418, Address: 0x2ac60c, Func Offset: 0x1ac
	// Line 420, Address: 0x2ac614, Func Offset: 0x1b4
	// Line 424, Address: 0x2ac634, Func Offset: 0x1d4
	// Line 420, Address: 0x2ac638, Func Offset: 0x1d8
	// Line 426, Address: 0x2ac640, Func Offset: 0x1e0
	// Line 429, Address: 0x2ac644, Func Offset: 0x1e4
	// Line 425, Address: 0x2ac648, Func Offset: 0x1e8
	// Line 427, Address: 0x2ac654, Func Offset: 0x1f4
	// Line 428, Address: 0x2ac65c, Func Offset: 0x1fc
	// Line 429, Address: 0x2ac664, Func Offset: 0x204
	// Line 430, Address: 0x2ac668, Func Offset: 0x208
	// Line 431, Address: 0x2ac66c, Func Offset: 0x20c
	// Line 433, Address: 0x2ac670, Func Offset: 0x210
	// Line 431, Address: 0x2ac678, Func Offset: 0x218
	// Line 433, Address: 0x2ac67c, Func Offset: 0x21c
	// Line 434, Address: 0x2ac684, Func Offset: 0x224
	// Line 436, Address: 0x2ac68c, Func Offset: 0x22c
	// Line 438, Address: 0x2ac698, Func Offset: 0x238
	// Line 440, Address: 0x2ac6b4, Func Offset: 0x254
	// Line 447, Address: 0x2ac6bc, Func Offset: 0x25c
	// Line 449, Address: 0x2ac6d0, Func Offset: 0x270
	// Line 452, Address: 0x2ac6d8, Func Offset: 0x278
	// Line 453, Address: 0x2ac6e8, Func Offset: 0x288
	// Line 460, Address: 0x2ac700, Func Offset: 0x2a0
	// Func End, Address: 0x2ac710, Func Offset: 0x2b0
}*/

// 100% matching!
int SearchTag(int dir)
{
    FV_WORK* fv;
    int tagbak;

    fv = &fvwork;

    tagbak = fv->tag;

    while (TRUE) 
    {
        if (!(sys->itm[383] & (1 << (fv->tag + (fv->filecsr * 8))))) 
        {
            fv->tag = (fv->tag + dir) & 0x7;
            
            if (fv->tag == tagbak) 
            {
                return 0;
            } 
        }
        else 
        {
            return 1;
        }
    }
}

/*// 
// Start address: 0x2ac780
void SelectFile()
{
	unsigned int tagbak;
	short i;
	_anon14* si;
	_anon12* st;
	_anon11* fv;
	// Line 481, Address: 0x2ac780, Func Offset: 0
	// Line 482, Address: 0x2ac78c, Func Offset: 0xc
	// Line 481, Address: 0x2ac790, Func Offset: 0x10
	// Line 482, Address: 0x2ac794, Func Offset: 0x14
	// Line 481, Address: 0x2ac798, Func Offset: 0x18
	// Line 488, Address: 0x2ac79c, Func Offset: 0x1c
	// Line 484, Address: 0x2ac7a0, Func Offset: 0x20
	// Line 488, Address: 0x2ac7a4, Func Offset: 0x24
	// Line 484, Address: 0x2ac7a8, Func Offset: 0x28
	// Line 485, Address: 0x2ac7ac, Func Offset: 0x2c
	// Line 488, Address: 0x2ac7b4, Func Offset: 0x34
	// Line 489, Address: 0x2ac7bc, Func Offset: 0x3c
	// Line 490, Address: 0x2ac7e8, Func Offset: 0x68
	// Line 491, Address: 0x2ac7f8, Func Offset: 0x78
	// Line 492, Address: 0x2ac800, Func Offset: 0x80
	// Line 493, Address: 0x2ac808, Func Offset: 0x88
	// Line 494, Address: 0x2ac810, Func Offset: 0x90
	// Line 495, Address: 0x2ac818, Func Offset: 0x98
	// Line 498, Address: 0x2ac820, Func Offset: 0xa0
	// Line 502, Address: 0x2ac850, Func Offset: 0xd0
	// Line 503, Address: 0x2ac864, Func Offset: 0xe4
	// Line 504, Address: 0x2ac870, Func Offset: 0xf0
	// Line 506, Address: 0x2ac894, Func Offset: 0x114
	// Line 507, Address: 0x2ac8a0, Func Offset: 0x120
	// Line 508, Address: 0x2ac8a8, Func Offset: 0x128
	// Line 509, Address: 0x2ac8b0, Func Offset: 0x130
	// Line 510, Address: 0x2ac8b4, Func Offset: 0x134
	// Line 511, Address: 0x2ac8b8, Func Offset: 0x138
	// Line 510, Address: 0x2ac8bc, Func Offset: 0x13c
	// Line 511, Address: 0x2ac8c4, Func Offset: 0x144
	// Line 512, Address: 0x2ac8c8, Func Offset: 0x148
	// Line 513, Address: 0x2ac8dc, Func Offset: 0x15c
	// Line 515, Address: 0x2ac8ec, Func Offset: 0x16c
	// Line 514, Address: 0x2ac8f0, Func Offset: 0x170
	// Line 515, Address: 0x2ac8f4, Func Offset: 0x174
	// Line 514, Address: 0x2ac8f8, Func Offset: 0x178
	// Line 515, Address: 0x2ac8fc, Func Offset: 0x17c
	// Line 516, Address: 0x2ac914, Func Offset: 0x194
	// Line 517, Address: 0x2ac918, Func Offset: 0x198
	// Line 516, Address: 0x2ac91c, Func Offset: 0x19c
	// Line 517, Address: 0x2ac920, Func Offset: 0x1a0
	// Line 518, Address: 0x2ac928, Func Offset: 0x1a8
	// Line 519, Address: 0x2ac948, Func Offset: 0x1c8
	// Line 520, Address: 0x2ac954, Func Offset: 0x1d4
	// Line 521, Address: 0x2ac95c, Func Offset: 0x1dc
	// Line 523, Address: 0x2ac964, Func Offset: 0x1e4
	// Line 524, Address: 0x2ac968, Func Offset: 0x1e8
	// Line 525, Address: 0x2ac96c, Func Offset: 0x1ec
	// Line 524, Address: 0x2ac970, Func Offset: 0x1f0
	// Line 525, Address: 0x2ac978, Func Offset: 0x1f8
	// Line 526, Address: 0x2ac97c, Func Offset: 0x1fc
	// Line 527, Address: 0x2ac990, Func Offset: 0x210
	// Line 529, Address: 0x2ac9a0, Func Offset: 0x220
	// Line 528, Address: 0x2ac9a4, Func Offset: 0x224
	// Line 529, Address: 0x2ac9a8, Func Offset: 0x228
	// Line 528, Address: 0x2ac9ac, Func Offset: 0x22c
	// Line 529, Address: 0x2ac9b0, Func Offset: 0x230
	// Line 530, Address: 0x2ac9cc, Func Offset: 0x24c
	// Line 531, Address: 0x2ac9d0, Func Offset: 0x250
	// Line 530, Address: 0x2ac9d4, Func Offset: 0x254
	// Line 531, Address: 0x2ac9d8, Func Offset: 0x258
	// Line 534, Address: 0x2ac9e0, Func Offset: 0x260
	// Line 535, Address: 0x2ac9e8, Func Offset: 0x268
	// Line 537, Address: 0x2ac9f4, Func Offset: 0x274
	// Line 541, Address: 0x2aca10, Func Offset: 0x290
	// Line 542, Address: 0x2aca24, Func Offset: 0x2a4
	// Line 543, Address: 0x2aca28, Func Offset: 0x2a8
	// Line 542, Address: 0x2aca2c, Func Offset: 0x2ac
	// Line 543, Address: 0x2aca30, Func Offset: 0x2b0
	// Line 544, Address: 0x2aca38, Func Offset: 0x2b8
	// Line 546, Address: 0x2aca48, Func Offset: 0x2c8
	// Line 545, Address: 0x2aca4c, Func Offset: 0x2cc
	// Line 546, Address: 0x2aca50, Func Offset: 0x2d0
	// Line 545, Address: 0x2aca54, Func Offset: 0x2d4
	// Line 546, Address: 0x2aca58, Func Offset: 0x2d8
	// Line 547, Address: 0x2aca74, Func Offset: 0x2f4
	// Line 548, Address: 0x2aca88, Func Offset: 0x308
	// Line 549, Address: 0x2aca90, Func Offset: 0x310
	// Line 551, Address: 0x2acaa8, Func Offset: 0x328
	// Line 553, Address: 0x2acabc, Func Offset: 0x33c
	// Line 554, Address: 0x2acac4, Func Offset: 0x344
	// Line 555, Address: 0x2acacc, Func Offset: 0x34c
	// Line 556, Address: 0x2acad0, Func Offset: 0x350
	// Line 558, Address: 0x2acad4, Func Offset: 0x354
	// Line 559, Address: 0x2acae0, Func Offset: 0x360
	// Line 560, Address: 0x2acae4, Func Offset: 0x364
	// Line 561, Address: 0x2acaf0, Func Offset: 0x370
	// Line 560, Address: 0x2acaf8, Func Offset: 0x378
	// Line 561, Address: 0x2acb00, Func Offset: 0x380
	// Line 567, Address: 0x2acb08, Func Offset: 0x388
	// Line 569, Address: 0x2acb38, Func Offset: 0x3b8
	// Line 570, Address: 0x2acb50, Func Offset: 0x3d0
	// Line 571, Address: 0x2acb6c, Func Offset: 0x3ec
	// Line 572, Address: 0x2acb94, Func Offset: 0x414
	// Line 573, Address: 0x2acbc0, Func Offset: 0x440
	// Line 574, Address: 0x2acbc8, Func Offset: 0x448
	// Line 576, Address: 0x2acbd0, Func Offset: 0x450
	// Line 589, Address: 0x2acbdc, Func Offset: 0x45c
	// Line 576, Address: 0x2acbe0, Func Offset: 0x460
	// Line 579, Address: 0x2acbf8, Func Offset: 0x478
	// Line 582, Address: 0x2acc1c, Func Offset: 0x49c
	// Line 586, Address: 0x2acc44, Func Offset: 0x4c4
	// Line 587, Address: 0x2acc48, Func Offset: 0x4c8
	// Line 589, Address: 0x2acc4c, Func Offset: 0x4cc
	// Line 591, Address: 0x2acc54, Func Offset: 0x4d4
	// Line 590, Address: 0x2acc58, Func Offset: 0x4d8
	// Line 591, Address: 0x2acc5c, Func Offset: 0x4dc
	// Line 590, Address: 0x2acc60, Func Offset: 0x4e0
	// Line 591, Address: 0x2acc64, Func Offset: 0x4e4
	// Line 593, Address: 0x2acc7c, Func Offset: 0x4fc
	// Line 595, Address: 0x2acc84, Func Offset: 0x504
	// Line 596, Address: 0x2acc9c, Func Offset: 0x51c
	// Line 598, Address: 0x2accc4, Func Offset: 0x544
	// Line 599, Address: 0x2acce4, Func Offset: 0x564
	// Line 600, Address: 0x2acd0c, Func Offset: 0x58c
	// Line 602, Address: 0x2acd14, Func Offset: 0x594
	// Line 603, Address: 0x2acd30, Func Offset: 0x5b0
	// Line 604, Address: 0x2acd54, Func Offset: 0x5d4
	// Line 606, Address: 0x2acd5c, Func Offset: 0x5dc
	// Line 607, Address: 0x2acd78, Func Offset: 0x5f8
	// Line 610, Address: 0x2acda4, Func Offset: 0x624
	// Line 611, Address: 0x2acdac, Func Offset: 0x62c
	// Line 613, Address: 0x2acdb4, Func Offset: 0x634
	// Line 612, Address: 0x2acdb8, Func Offset: 0x638
	// Line 613, Address: 0x2acdbc, Func Offset: 0x63c
	// Line 615, Address: 0x2acdc8, Func Offset: 0x648
	// Line 614, Address: 0x2acdcc, Func Offset: 0x64c
	// Line 615, Address: 0x2acdd0, Func Offset: 0x650
	// Line 614, Address: 0x2acdd4, Func Offset: 0x654
	// Line 615, Address: 0x2acdd8, Func Offset: 0x658
	// Line 616, Address: 0x2acdf4, Func Offset: 0x674
	// Line 617, Address: 0x2acdfc, Func Offset: 0x67c
	// Line 619, Address: 0x2ace0c, Func Offset: 0x68c
	// Line 621, Address: 0x2ace14, Func Offset: 0x694
	// Line 622, Address: 0x2ace2c, Func Offset: 0x6ac
	// Line 623, Address: 0x2ace40, Func Offset: 0x6c0
	// Line 624, Address: 0x2ace48, Func Offset: 0x6c8
	// Line 625, Address: 0x2ace50, Func Offset: 0x6d0
	// Line 627, Address: 0x2ace54, Func Offset: 0x6d4
	// Line 629, Address: 0x2ace64, Func Offset: 0x6e4
	// Line 628, Address: 0x2ace68, Func Offset: 0x6e8
	// Line 629, Address: 0x2ace6c, Func Offset: 0x6ec
	// Line 628, Address: 0x2ace70, Func Offset: 0x6f0
	// Line 629, Address: 0x2ace74, Func Offset: 0x6f4
	// Line 632, Address: 0x2ace8c, Func Offset: 0x70c
	// Line 630, Address: 0x2ace90, Func Offset: 0x710
	// Line 632, Address: 0x2ace94, Func Offset: 0x714
	// Line 635, Address: 0x2ace98, Func Offset: 0x718
	// Line 636, Address: 0x2acec8, Func Offset: 0x748
	// Line 637, Address: 0x2aced0, Func Offset: 0x750
	// Line 638, Address: 0x2acee8, Func Offset: 0x768
	// Line 642, Address: 0x2acef4, Func Offset: 0x774
	// Line 644, Address: 0x2acef8, Func Offset: 0x778
	// Func End, Address: 0x2acf10, Func Offset: 0x790
}

// 
// Start address: 0x2acf10
void SelectTag()
{
	int title;
	int tagbak;
	short i;
	_anon26 mpos;
	_anon14* si;
	_anon11* fv;
	_anon12* st;
	// Line 648, Address: 0x2acf10, Func Offset: 0
	// Line 650, Address: 0x2acf20, Func Offset: 0x10
	// Line 657, Address: 0x2acf28, Func Offset: 0x18
	// Line 651, Address: 0x2acf2c, Func Offset: 0x1c
	// Line 657, Address: 0x2acf34, Func Offset: 0x24
	// Line 652, Address: 0x2acf38, Func Offset: 0x28
	// Line 657, Address: 0x2acf3c, Func Offset: 0x2c
	// Line 659, Address: 0x2acf58, Func Offset: 0x48
	// Line 663, Address: 0x2acf90, Func Offset: 0x80
	// Line 664, Address: 0x2acf9c, Func Offset: 0x8c
	// Line 667, Address: 0x2acfa4, Func Offset: 0x94
	// Line 669, Address: 0x2acfa8, Func Offset: 0x98
	// Line 666, Address: 0x2acfac, Func Offset: 0x9c
	// Line 667, Address: 0x2acfb8, Func Offset: 0xa8
	// Line 668, Address: 0x2acfc8, Func Offset: 0xb8
	// Line 669, Address: 0x2acfd4, Func Offset: 0xc4
	// Line 670, Address: 0x2acffc, Func Offset: 0xec
	// Line 671, Address: 0x2ad008, Func Offset: 0xf8
	// Line 674, Address: 0x2ad010, Func Offset: 0x100
	// Line 675, Address: 0x2ad01c, Func Offset: 0x10c
	// Line 680, Address: 0x2ad024, Func Offset: 0x114
	// Line 677, Address: 0x2ad028, Func Offset: 0x118
	// Line 678, Address: 0x2ad034, Func Offset: 0x124
	// Line 679, Address: 0x2ad048, Func Offset: 0x138
	// Line 680, Address: 0x2ad054, Func Offset: 0x144
	// Line 681, Address: 0x2ad07c, Func Offset: 0x16c
	// Line 686, Address: 0x2ad088, Func Offset: 0x178
	// Line 689, Address: 0x2ad0a8, Func Offset: 0x198
	// Line 694, Address: 0x2ad0b0, Func Offset: 0x1a0
	// Line 691, Address: 0x2ad0b8, Func Offset: 0x1a8
	// Line 692, Address: 0x2ad0bc, Func Offset: 0x1ac
	// Line 689, Address: 0x2ad0c0, Func Offset: 0x1b0
	// Line 690, Address: 0x2ad0cc, Func Offset: 0x1bc
	// Line 694, Address: 0x2ad0d0, Func Offset: 0x1c0
	// Line 691, Address: 0x2ad0dc, Func Offset: 0x1cc
	// Line 690, Address: 0x2ad0e0, Func Offset: 0x1d0
	// Line 694, Address: 0x2ad0e4, Func Offset: 0x1d4
	// Line 698, Address: 0x2ad0ec, Func Offset: 0x1dc
	// Line 700, Address: 0x2ad0f4, Func Offset: 0x1e4
	// Line 704, Address: 0x2ad118, Func Offset: 0x208
	// Line 705, Address: 0x2ad140, Func Offset: 0x230
	// Line 706, Address: 0x2ad14c, Func Offset: 0x23c
	// Line 707, Address: 0x2ad154, Func Offset: 0x244
	// Line 708, Address: 0x2ad15c, Func Offset: 0x24c
	// Line 711, Address: 0x2ad164, Func Offset: 0x254
	// Line 709, Address: 0x2ad168, Func Offset: 0x258
	// Line 708, Address: 0x2ad170, Func Offset: 0x260
	// Line 709, Address: 0x2ad17c, Func Offset: 0x26c
	// Line 710, Address: 0x2ad188, Func Offset: 0x278
	// Line 711, Address: 0x2ad18c, Func Offset: 0x27c
	// Line 712, Address: 0x2ad190, Func Offset: 0x280
	// Line 715, Address: 0x2ad1a4, Func Offset: 0x294
	// Line 716, Address: 0x2ad1b8, Func Offset: 0x2a8
	// Line 717, Address: 0x2ad1c4, Func Offset: 0x2b4
	// Line 719, Address: 0x2ad1d4, Func Offset: 0x2c4
	// Line 718, Address: 0x2ad1d8, Func Offset: 0x2c8
	// Line 719, Address: 0x2ad1dc, Func Offset: 0x2cc
	// Line 718, Address: 0x2ad1e0, Func Offset: 0x2d0
	// Line 719, Address: 0x2ad1e4, Func Offset: 0x2d4
	// Line 720, Address: 0x2ad1fc, Func Offset: 0x2ec
	// Line 723, Address: 0x2ad200, Func Offset: 0x2f0
	// Line 724, Address: 0x2ad208, Func Offset: 0x2f8
	// Line 725, Address: 0x2ad218, Func Offset: 0x308
	// Line 726, Address: 0x2ad230, Func Offset: 0x320
	// Line 727, Address: 0x2ad244, Func Offset: 0x334
	// Line 728, Address: 0x2ad24c, Func Offset: 0x33c
	// Line 730, Address: 0x2ad254, Func Offset: 0x344
	// Line 729, Address: 0x2ad258, Func Offset: 0x348
	// Line 730, Address: 0x2ad25c, Func Offset: 0x34c
	// Line 732, Address: 0x2ad268, Func Offset: 0x358
	// Line 731, Address: 0x2ad26c, Func Offset: 0x35c
	// Line 732, Address: 0x2ad270, Func Offset: 0x360
	// Line 731, Address: 0x2ad274, Func Offset: 0x364
	// Line 732, Address: 0x2ad278, Func Offset: 0x368
	// Line 733, Address: 0x2ad294, Func Offset: 0x384
	// Line 734, Address: 0x2ad29c, Func Offset: 0x38c
	// Line 736, Address: 0x2ad2b0, Func Offset: 0x3a0
	// Line 737, Address: 0x2ad2c4, Func Offset: 0x3b4
	// Line 738, Address: 0x2ad2dc, Func Offset: 0x3cc
	// Line 740, Address: 0x2ad300, Func Offset: 0x3f0
	// Line 741, Address: 0x2ad320, Func Offset: 0x410
	// Line 742, Address: 0x2ad348, Func Offset: 0x438
	// Line 744, Address: 0x2ad350, Func Offset: 0x440
	// Line 745, Address: 0x2ad36c, Func Offset: 0x45c
	// Line 746, Address: 0x2ad390, Func Offset: 0x480
	// Line 748, Address: 0x2ad398, Func Offset: 0x488
	// Line 749, Address: 0x2ad3b4, Func Offset: 0x4a4
	// Line 752, Address: 0x2ad3e0, Func Offset: 0x4d0
	// Line 753, Address: 0x2ad3e8, Func Offset: 0x4d8
	// Line 754, Address: 0x2ad3f0, Func Offset: 0x4e0
	// Line 755, Address: 0x2ad3f4, Func Offset: 0x4e4
	// Line 757, Address: 0x2ad400, Func Offset: 0x4f0
	// Line 756, Address: 0x2ad404, Func Offset: 0x4f4
	// Line 757, Address: 0x2ad408, Func Offset: 0x4f8
	// Line 756, Address: 0x2ad40c, Func Offset: 0x4fc
	// Line 757, Address: 0x2ad410, Func Offset: 0x500
	// Line 758, Address: 0x2ad42c, Func Offset: 0x51c
	// Line 759, Address: 0x2ad434, Func Offset: 0x524
	// Line 763, Address: 0x2ad438, Func Offset: 0x528
	// Func End, Address: 0x2ad44c, Func Offset: 0x53c
}*/

// 100% matching!
void FileScreenCancel()
{
    FV_WORK* fv;
    unsigned short i;
    unsigned short j;

    fv = &fvwork;
    
    if ((fv->afsmode & 0x80)) 
    {
        njReleaseTexture(&fv->fstx_list);
        
        bhGarbageTexture(tbuf, 256);
    }
    
    fvwork.afsmode &= ~0xB80;
    
    if (!(sys->cb_flg & 0x20000)) 
    {
        fvwork.afsmode |= 0x20;
    }

    for (i = 0; i < 12; i++) 
    {
        for (j = 0; j < 6; j++) 
        {
            cen_pos[i][j] = cen_pos99[i][j];
        }
    }

    parts_22b[0].atr &= ~0x20;
    
    fvwork.flg &= ~0x1;
    
    swork.statusflg &= ~0x800;
    
    parts_22b[1].atr &= ~0x20;
    parts_22b[2].atr &= ~0x20;
    parts_22b[3].atr &= ~0x20;
    parts_22b[4].atr &= ~0x20;
    
    parts_22b[4].color |= 0x8;
    
    fv->mode_00 = 3;
    fv->mode_01 = 0;

    if ((sys->cb_flg & 0x20000)) 
    {
        fv->mode_02 = 0;
    }
    else 
    {
        fv->mode_02 = 7;
    }
}

// 
// Start address: 0x2ad640
void FileScrollSet()
{
	int page_end;
	//_anon11* fv;
	//_anon12* st;
	// Line 811, Address: 0x2ad640, Func Offset: 0
	// Line 815, Address: 0x2ad650, Func Offset: 0x10
	// Line 812, Address: 0x2ad654, Func Offset: 0x14
	// Line 815, Address: 0x2ad65c, Func Offset: 0x1c
	// Line 813, Address: 0x2ad660, Func Offset: 0x20
	// Line 815, Address: 0x2ad668, Func Offset: 0x28
	// Line 818, Address: 0x2ad67c, Func Offset: 0x3c
	// Line 819, Address: 0x2ad698, Func Offset: 0x58
	// Line 820, Address: 0x2ad69c, Func Offset: 0x5c
	// Line 819, Address: 0x2ad6a4, Func Offset: 0x64
	// Line 820, Address: 0x2ad6ac, Func Offset: 0x6c
	// Line 825, Address: 0x2ad6cc, Func Offset: 0x8c
	// Line 826, Address: 0x2ad6ec, Func Offset: 0xac
	// Line 827, Address: 0x2ad70c, Func Offset: 0xcc
	// Line 828, Address: 0x2ad718, Func Offset: 0xd8
	// Line 829, Address: 0x2ad738, Func Offset: 0xf8
	// Line 830, Address: 0x2ad750, Func Offset: 0x110
	// Line 832, Address: 0x2ad77c, Func Offset: 0x13c
	// Line 833, Address: 0x2ad780, Func Offset: 0x140
	// Line 832, Address: 0x2ad784, Func Offset: 0x144
	// Line 833, Address: 0x2ad788, Func Offset: 0x148
	// Line 834, Address: 0x2ad78c, Func Offset: 0x14c
	// Line 835, Address: 0x2ad798, Func Offset: 0x158
	// Line 836, Address: 0x2ad7a8, Func Offset: 0x168
	// Line 837, Address: 0x2ad7b0, Func Offset: 0x170
	// Line 839, Address: 0x2ad7b4, Func Offset: 0x174
	// Line 840, Address: 0x2ad7c0, Func Offset: 0x180
	// Line 843, Address: 0x2ad7d0, Func Offset: 0x190
	// Line 845, Address: 0x2ad7d8, Func Offset: 0x198
	// Line 843, Address: 0x2ad7dc, Func Offset: 0x19c
	// Line 844, Address: 0x2ad7e8, Func Offset: 0x1a8
	// Line 845, Address: 0x2ad7fc, Func Offset: 0x1bc
	// Line 846, Address: 0x2ad804, Func Offset: 0x1c4
	// Line 847, Address: 0x2ad80c, Func Offset: 0x1cc
	// Line 848, Address: 0x2ad814, Func Offset: 0x1d4
	// Line 850, Address: 0x2ad818, Func Offset: 0x1d8
	// Line 851, Address: 0x2ad82c, Func Offset: 0x1ec
	// Line 852, Address: 0x2ad838, Func Offset: 0x1f8
	// Line 853, Address: 0x2ad84c, Func Offset: 0x20c
	// Line 854, Address: 0x2ad854, Func Offset: 0x214
	// Line 855, Address: 0x2ad858, Func Offset: 0x218
	// Line 853, Address: 0x2ad85c, Func Offset: 0x21c
	// Line 854, Address: 0x2ad868, Func Offset: 0x228
	// Line 855, Address: 0x2ad86c, Func Offset: 0x22c
	// Line 856, Address: 0x2ad870, Func Offset: 0x230
	// Line 857, Address: 0x2ad87c, Func Offset: 0x23c
	// Line 858, Address: 0x2ad88c, Func Offset: 0x24c
	// Line 859, Address: 0x2ad894, Func Offset: 0x254
	// Line 861, Address: 0x2ad89c, Func Offset: 0x25c
	// Line 862, Address: 0x2ad8a8, Func Offset: 0x268
	// Line 864, Address: 0x2ad8b0, Func Offset: 0x270
	// Line 865, Address: 0x2ad8b8, Func Offset: 0x278
	// Line 868, Address: 0x2ad8c0, Func Offset: 0x280
	// Line 867, Address: 0x2ad8c4, Func Offset: 0x284
	// Line 868, Address: 0x2ad8c8, Func Offset: 0x288
	// Line 865, Address: 0x2ad8cc, Func Offset: 0x28c
	// Line 866, Address: 0x2ad8d8, Func Offset: 0x298
	// Line 867, Address: 0x2ad8ec, Func Offset: 0x2ac
	// Line 868, Address: 0x2ad8f4, Func Offset: 0x2b4
	// Line 869, Address: 0x2ad8fc, Func Offset: 0x2bc
	// Line 870, Address: 0x2ad904, Func Offset: 0x2c4
	// Line 874, Address: 0x2ad908, Func Offset: 0x2c8
	// Line 875, Address: 0x2ad910, Func Offset: 0x2d0
	// Line 877, Address: 0x2ad930, Func Offset: 0x2f0
	// Line 878, Address: 0x2ad954, Func Offset: 0x314
	// Line 880, Address: 0x2ad95c, Func Offset: 0x31c
	// Line 881, Address: 0x2ad96c, Func Offset: 0x32c
	// Line 882, Address: 0x2ad974, Func Offset: 0x334
	// Line 883, Address: 0x2ad980, Func Offset: 0x340
	// Line 885, Address: 0x2ad988, Func Offset: 0x348
	// Line 886, Address: 0x2ad99c, Func Offset: 0x35c
	// Line 887, Address: 0x2ad9c0, Func Offset: 0x380
	// Line 889, Address: 0x2ad9c8, Func Offset: 0x388
	// Line 890, Address: 0x2ad9d8, Func Offset: 0x398
	// Line 891, Address: 0x2ad9e0, Func Offset: 0x3a0
	// Line 892, Address: 0x2ad9e8, Func Offset: 0x3a8
	// Line 896, Address: 0x2ad9f4, Func Offset: 0x3b4
	// Line 897, Address: 0x2ad9fc, Func Offset: 0x3bc
	// Line 902, Address: 0x2ada04, Func Offset: 0x3c4
	// Func End, Address: 0x2ada18, Func Offset: 0x3d8
	scePrintf("FileScrollSet - UNIMPLEMENTED!\n");
}

// 100% matching! 
void FileGetWait()
{
    FV_WORK* fv;

    fv = &fvwork;

    switch (fv->mode_01)
    {                             
    case 0:
        sys->sb_id = fv->filenum + 159;
        
        bhSetMessage(1, 152);
        
        fv->mode_01 = 1;

        parts_22b[0].atr &= ~0x20;
        parts_22b[1].atr &= ~0x20;
        parts_22b[2].atr &= ~0x20;
        parts_22b[3].atr &= ~0x20;
        parts_22b[4].atr &= ~0x20;
    case 1:
        if (((sys->st_flg & 0x4000)) && ((sys->st_flg & 0x1000)) && (((sys->pad_ps & 0x800)) || ((sys->pad_ps & 0x1000)) || ((sys->st_flg & 0x8000)))) 
        {
            sys->st_flg &= ~0x200;
           
            CallSystemSe(0, 3);
            
            sys->sb_id = 0;
            
            fv->mode_01 = 0;
            
            FileScreenCancel();
        }
        
        break;
    }
}

// 
// Start address: 0x2adb90
void PageScroll()
{
	int page_end;
	//_anon11* fv;
	// Line 938, Address: 0x2adb90, Func Offset: 0
	// Line 943, Address: 0x2adb9c, Func Offset: 0xc
	// Line 940, Address: 0x2adba4, Func Offset: 0x14
	// Line 943, Address: 0x2adbac, Func Offset: 0x1c
	// Line 946, Address: 0x2adbbc, Func Offset: 0x2c
	// Line 947, Address: 0x2adbd0, Func Offset: 0x40
	// Line 948, Address: 0x2adbec, Func Offset: 0x5c
	// Line 949, Address: 0x2adbf8, Func Offset: 0x68
	// Line 950, Address: 0x2adc04, Func Offset: 0x74
	// Line 951, Address: 0x2adc20, Func Offset: 0x90
	// Line 952, Address: 0x2adc3c, Func Offset: 0xac
	// Line 954, Address: 0x2adc44, Func Offset: 0xb4
	// Line 955, Address: 0x2adc4c, Func Offset: 0xbc
	// Line 956, Address: 0x2adc68, Func Offset: 0xd8
	// Line 957, Address: 0x2adc84, Func Offset: 0xf4
	// Line 959, Address: 0x2adc90, Func Offset: 0x100
	// Line 960, Address: 0x2adcc4, Func Offset: 0x134
	// Line 961, Address: 0x2adcd0, Func Offset: 0x140
	// Line 962, Address: 0x2adcdc, Func Offset: 0x14c
	// Line 964, Address: 0x2add08, Func Offset: 0x178
	// Line 967, Address: 0x2add10, Func Offset: 0x180
	// Line 966, Address: 0x2add14, Func Offset: 0x184
	// Line 967, Address: 0x2add18, Func Offset: 0x188
	// Line 964, Address: 0x2add1c, Func Offset: 0x18c
	// Line 965, Address: 0x2add28, Func Offset: 0x198
	// Line 966, Address: 0x2add3c, Func Offset: 0x1ac
	// Line 967, Address: 0x2add44, Func Offset: 0x1b4
	// Line 968, Address: 0x2add4c, Func Offset: 0x1bc
	// Line 969, Address: 0x2add54, Func Offset: 0x1c4
	// Line 971, Address: 0x2add5c, Func Offset: 0x1cc
	// Line 972, Address: 0x2add64, Func Offset: 0x1d4
	// Line 973, Address: 0x2add68, Func Offset: 0x1d8
	// Line 974, Address: 0x2add6c, Func Offset: 0x1dc
	// Line 971, Address: 0x2add70, Func Offset: 0x1e0
	// Line 972, Address: 0x2add7c, Func Offset: 0x1ec
	// Line 973, Address: 0x2add80, Func Offset: 0x1f0
	// Line 974, Address: 0x2add84, Func Offset: 0x1f4
	// Line 975, Address: 0x2add88, Func Offset: 0x1f8
	// Line 982, Address: 0x2add98, Func Offset: 0x208
	// Line 983, Address: 0x2addd0, Func Offset: 0x240
	// Line 984, Address: 0x2adde8, Func Offset: 0x258
	// Line 985, Address: 0x2addf4, Func Offset: 0x264
	// Line 986, Address: 0x2addf8, Func Offset: 0x268
	// Line 985, Address: 0x2addfc, Func Offset: 0x26c
	// Line 984, Address: 0x2ade04, Func Offset: 0x274
	// Line 985, Address: 0x2ade10, Func Offset: 0x280
	// Line 986, Address: 0x2ade1c, Func Offset: 0x28c
	// Line 988, Address: 0x2ade20, Func Offset: 0x290
	// Line 989, Address: 0x2ade2c, Func Offset: 0x29c
	// Line 991, Address: 0x2ade38, Func Offset: 0x2a8
	// Line 990, Address: 0x2ade3c, Func Offset: 0x2ac
	// Line 993, Address: 0x2ade40, Func Offset: 0x2b0
	// Line 994, Address: 0x2ade60, Func Offset: 0x2d0
	// Line 995, Address: 0x2ade6c, Func Offset: 0x2dc
	// Line 996, Address: 0x2ade78, Func Offset: 0x2e8
	// Line 997, Address: 0x2ade94, Func Offset: 0x304
	// Line 998, Address: 0x2adeb0, Func Offset: 0x320
	// Line 1000, Address: 0x2adeb8, Func Offset: 0x328
	// Line 1001, Address: 0x2adec0, Func Offset: 0x330
	// Line 1002, Address: 0x2adedc, Func Offset: 0x34c
	// Line 1003, Address: 0x2adef8, Func Offset: 0x368
	// Line 1005, Address: 0x2adf04, Func Offset: 0x374
	// Line 1006, Address: 0x2adf38, Func Offset: 0x3a8
	// Line 1007, Address: 0x2adf44, Func Offset: 0x3b4
	// Line 1008, Address: 0x2adf50, Func Offset: 0x3c0
	// Line 1009, Address: 0x2adf58, Func Offset: 0x3c8
	// Line 1010, Address: 0x2adf5c, Func Offset: 0x3cc
	// Line 1011, Address: 0x2adf60, Func Offset: 0x3d0
	// Line 1008, Address: 0x2adf64, Func Offset: 0x3d4
	// Line 1009, Address: 0x2adf70, Func Offset: 0x3e0
	// Line 1010, Address: 0x2adf74, Func Offset: 0x3e4
	// Line 1011, Address: 0x2adf78, Func Offset: 0x3e8
	// Line 1012, Address: 0x2adf7c, Func Offset: 0x3ec
	// Line 1019, Address: 0x2adf8c, Func Offset: 0x3fc
	// Line 1020, Address: 0x2adfc4, Func Offset: 0x434
	// Line 1021, Address: 0x2adfd0, Func Offset: 0x440
	// Line 1023, Address: 0x2adfdc, Func Offset: 0x44c
	// Line 1022, Address: 0x2adfe0, Func Offset: 0x450
	// Line 1026, Address: 0x2adfe4, Func Offset: 0x454
	// Line 1027, Address: 0x2adfec, Func Offset: 0x45c
	// Line 1028, Address: 0x2ae000, Func Offset: 0x470
	// Line 1029, Address: 0x2ae00c, Func Offset: 0x47c
	// Line 1044, Address: 0x2ae018, Func Offset: 0x488
	// Line 1029, Address: 0x2ae01c, Func Offset: 0x48c
	// Line 1045, Address: 0x2ae028, Func Offset: 0x498
	// Line 1046, Address: 0x2ae030, Func Offset: 0x4a0
	// Line 1061, Address: 0x2ae038, Func Offset: 0x4a8
	// Line 1064, Address: 0x2ae064, Func Offset: 0x4d4
	// Func End, Address: 0x2ae074, Func Offset: 0x4e4
	scePrintf("PageScroll - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ae080
void FileEtcDisplay()
{
	int page_end;
	//_anon11* fv;
	unsigned short flg;
	unsigned short count;
	// Line 1069, Address: 0x2ae080, Func Offset: 0
	// Line 1076, Address: 0x2ae08c, Func Offset: 0xc
	// Line 1071, Address: 0x2ae094, Func Offset: 0x14
	// Line 1076, Address: 0x2ae09c, Func Offset: 0x1c
	// Line 1077, Address: 0x2ae0bc, Func Offset: 0x3c
	// Line 1079, Address: 0x2ae0d0, Func Offset: 0x50
	// Line 1080, Address: 0x2ae0e8, Func Offset: 0x68
	// Line 1081, Address: 0x2ae100, Func Offset: 0x80
	// Line 1083, Address: 0x2ae128, Func Offset: 0xa8
	// Line 1084, Address: 0x2ae154, Func Offset: 0xd4
	// Line 1085, Address: 0x2ae168, Func Offset: 0xe8
	// Line 1086, Address: 0x2ae178, Func Offset: 0xf8
	// Line 1087, Address: 0x2ae180, Func Offset: 0x100
	// Line 1088, Address: 0x2ae194, Func Offset: 0x114
	// Line 1090, Address: 0x2ae1a4, Func Offset: 0x124
	// Line 1091, Address: 0x2ae1ac, Func Offset: 0x12c
	// Line 1092, Address: 0x2ae1cc, Func Offset: 0x14c
	// Line 1093, Address: 0x2ae1d4, Func Offset: 0x154
	// Line 1092, Address: 0x2ae1dc, Func Offset: 0x15c
	// Line 1093, Address: 0x2ae1e8, Func Offset: 0x168
	// Line 1095, Address: 0x2ae20c, Func Offset: 0x18c
	// Line 1096, Address: 0x2ae228, Func Offset: 0x1a8
	// Line 1097, Address: 0x2ae230, Func Offset: 0x1b0
	// Line 1099, Address: 0x2ae240, Func Offset: 0x1c0
	// Line 1100, Address: 0x2ae248, Func Offset: 0x1c8
	// Line 1101, Address: 0x2ae25c, Func Offset: 0x1dc
	// Line 1105, Address: 0x2ae270, Func Offset: 0x1f0
	// Line 1106, Address: 0x2ae284, Func Offset: 0x204
	// Line 1107, Address: 0x2ae298, Func Offset: 0x218
	// Line 1108, Address: 0x2ae2a0, Func Offset: 0x220
	// Line 1110, Address: 0x2ae2b8, Func Offset: 0x238
	// Line 1111, Address: 0x2ae2cc, Func Offset: 0x24c
	// Line 1112, Address: 0x2ae2dc, Func Offset: 0x25c
	// Line 1113, Address: 0x2ae2fc, Func Offset: 0x27c
	// Line 1114, Address: 0x2ae30c, Func Offset: 0x28c
	// Line 1115, Address: 0x2ae314, Func Offset: 0x294
	// Line 1116, Address: 0x2ae334, Func Offset: 0x2b4
	// Line 1120, Address: 0x2ae348, Func Offset: 0x2c8
	// Func End, Address: 0x2ae358, Func Offset: 0x2d8
	scePrintf("FileEtcDisplay - UNIMPLEMENTED!\n");
}

// 100% matching!
void StatusToFileView()
{
    FV_WORK* fv;
    unsigned short num1;

    fv = &fvwork;
    
    swork.statusflg |= 0x9002040;
    
    cen_pos[1][3] = -80.0f;
    cen_pos[2][2] = -448.0f;
    cen_pos[3][2] = 640.0f;
    cen_pos[4][2] = 808.0f;
    cen_pos[5][2] = 644.0f;
    cen_pos[6][3] = 484.0f;
    
    cen_pos[8][2] = -380.0f;
    cen_pos[9][2] = 644.0f;
    cen_pos[10][3] = -384.0f;
    cen_pos[11][2] = 660.0f;

    for (num1 = 1; num1 < 12; num1++) 
    {
        if (num1 != 3)
        {
            cen_pos[num1][4] = cen_pos[num1][2] - cen_pos[num1][0];
            cen_pos[num1][5] = cen_pos[num1][3] - cen_pos[num1][1];
        }
        else 
        {
            cen_pos[num1][4] = cen_pos[num1][2] - 352.0f;
        }
    }

    parts_22b[2].atr &= ~0x20;
    parts_22b[3].atr &= ~0x20;
    
    fv->mode_02 = 1;
}

// 
// Start address: 0x2ae4b0
void ReadFstx()
{
	unsigned int num;
	int sz;
	//_anon11* fv;
	//_anon12* st;
	// Line 1160, Address: 0x2ae4b0, Func Offset: 0
	// Line 1167, Address: 0x2ae4c0, Func Offset: 0x10
	// Line 1161, Address: 0x2ae4c8, Func Offset: 0x18
	// Line 1162, Address: 0x2ae4d0, Func Offset: 0x20
	// Line 1167, Address: 0x2ae4d8, Func Offset: 0x28
	// Line 1169, Address: 0x2ae4e0, Func Offset: 0x30
	// Line 1167, Address: 0x2ae4e4, Func Offset: 0x34
	// Line 1169, Address: 0x2ae4e8, Func Offset: 0x38
	// Line 1170, Address: 0x2ae508, Func Offset: 0x58
	// Line 1172, Address: 0x2ae51c, Func Offset: 0x6c
	// Line 1176, Address: 0x2ae548, Func Offset: 0x98
	// Line 1178, Address: 0x2ae554, Func Offset: 0xa4
	// Line 1176, Address: 0x2ae558, Func Offset: 0xa8
	// Line 1178, Address: 0x2ae564, Func Offset: 0xb4
	// Line 1179, Address: 0x2ae56c, Func Offset: 0xbc
	// Line 1181, Address: 0x2ae570, Func Offset: 0xc0
	// Line 1182, Address: 0x2ae584, Func Offset: 0xd4
	// Line 1183, Address: 0x2ae594, Func Offset: 0xe4
	// Line 1186, Address: 0x2ae5a8, Func Offset: 0xf8
	// Line 1188, Address: 0x2ae5b8, Func Offset: 0x108
	// Line 1190, Address: 0x2ae5bc, Func Offset: 0x10c
	// Line 1193, Address: 0x2ae5c4, Func Offset: 0x114
	// Line 1195, Address: 0x2ae5d4, Func Offset: 0x124
	// Line 1197, Address: 0x2ae5e0, Func Offset: 0x130
	// Line 1195, Address: 0x2ae5e4, Func Offset: 0x134
	// Line 1197, Address: 0x2ae5f0, Func Offset: 0x140
	// Line 1198, Address: 0x2ae5f4, Func Offset: 0x144
	// Line 1199, Address: 0x2ae608, Func Offset: 0x158
	// Line 1200, Address: 0x2ae618, Func Offset: 0x168
	// Line 1203, Address: 0x2ae620, Func Offset: 0x170
	// Line 1221, Address: 0x2ae634, Func Offset: 0x184
	// Line 1223, Address: 0x2ae638, Func Offset: 0x188
	// Line 1252, Address: 0x2ae640, Func Offset: 0x190
	// Line 1254, Address: 0x2ae650, Func Offset: 0x1a0
	// Line 1255, Address: 0x2ae658, Func Offset: 0x1a8
	// Line 1256, Address: 0x2ae66c, Func Offset: 0x1bc
	// Line 1257, Address: 0x2ae674, Func Offset: 0x1c4
	// Line 1258, Address: 0x2ae67c, Func Offset: 0x1cc
	// Line 1259, Address: 0x2ae688, Func Offset: 0x1d8
	// Line 1260, Address: 0x2ae690, Func Offset: 0x1e0
	// Line 1259, Address: 0x2ae694, Func Offset: 0x1e4
	// Line 1260, Address: 0x2ae698, Func Offset: 0x1e8
	// Line 1265, Address: 0x2ae6a0, Func Offset: 0x1f0
	// Line 1294, Address: 0x2ae6a8, Func Offset: 0x1f8
	// Line 1307, Address: 0x2ae6b0, Func Offset: 0x200
	// Line 1310, Address: 0x2ae6b8, Func Offset: 0x208
	// Line 1311, Address: 0x2ae6cc, Func Offset: 0x21c
	// Line 1312, Address: 0x2ae6e0, Func Offset: 0x230
	// Line 1313, Address: 0x2ae6f0, Func Offset: 0x240
	// Line 1315, Address: 0x2ae704, Func Offset: 0x254
	// Line 1316, Address: 0x2ae71c, Func Offset: 0x26c
	// Line 1317, Address: 0x2ae720, Func Offset: 0x270
	// Line 1319, Address: 0x2ae728, Func Offset: 0x278
	// Line 1321, Address: 0x2ae738, Func Offset: 0x288
	// Line 1320, Address: 0x2ae73c, Func Offset: 0x28c
	// Line 1321, Address: 0x2ae740, Func Offset: 0x290
	// Line 1322, Address: 0x2ae744, Func Offset: 0x294
	// Line 1326, Address: 0x2ae754, Func Offset: 0x2a4
	// Line 1327, Address: 0x2ae760, Func Offset: 0x2b0
	// Line 1329, Address: 0x2ae768, Func Offset: 0x2b8
	// Line 1331, Address: 0x2ae770, Func Offset: 0x2c0
	// Line 1334, Address: 0x2ae774, Func Offset: 0x2c4
	// Line 1327, Address: 0x2ae778, Func Offset: 0x2c8
	// Line 1328, Address: 0x2ae784, Func Offset: 0x2d4
	// Line 1329, Address: 0x2ae798, Func Offset: 0x2e8
	// Line 1330, Address: 0x2ae7ac, Func Offset: 0x2fc
	// Line 1331, Address: 0x2ae7b0, Func Offset: 0x300
	// Line 1332, Address: 0x2ae7b8, Func Offset: 0x308
	// Line 1331, Address: 0x2ae7c0, Func Offset: 0x310
	// Line 1332, Address: 0x2ae7cc, Func Offset: 0x31c
	// Line 1334, Address: 0x2ae7dc, Func Offset: 0x32c
	// Line 1335, Address: 0x2ae7e8, Func Offset: 0x338
	// Line 1336, Address: 0x2ae7f0, Func Offset: 0x340
	// Line 1337, Address: 0x2ae7f8, Func Offset: 0x348
	// Line 1343, Address: 0x2ae800, Func Offset: 0x350
	// Func End, Address: 0x2ae814, Func Offset: 0x364
	scePrintf("ReadFstx - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ae820
unsigned int FileNumberSwitch(unsigned int num)
{
	unsigned int filenum;
	// Line 1351, Address: 0x2ae820, Func Offset: 0
	// Line 1353, Address: 0x2ae970, Func Offset: 0x150
	// Line 1354, Address: 0x2ae97c, Func Offset: 0x15c
	// Line 1356, Address: 0x2ae984, Func Offset: 0x164
	// Line 1357, Address: 0x2ae990, Func Offset: 0x170
	// Line 1359, Address: 0x2ae998, Func Offset: 0x178
	// Line 1360, Address: 0x2ae9a4, Func Offset: 0x184
	// Line 1362, Address: 0x2ae9ac, Func Offset: 0x18c
	// Line 1363, Address: 0x2ae9bc, Func Offset: 0x19c
	// Line 1364, Address: 0x2ae9c8, Func Offset: 0x1a8
	// Line 1366, Address: 0x2ae9d0, Func Offset: 0x1b0
	// Line 1367, Address: 0x2ae9dc, Func Offset: 0x1bc
	// Line 1369, Address: 0x2ae9e4, Func Offset: 0x1c4
	// Line 1370, Address: 0x2ae9f0, Func Offset: 0x1d0
	// Line 1373, Address: 0x2ae9f8, Func Offset: 0x1d8
	// Line 1374, Address: 0x2aea04, Func Offset: 0x1e4
	// Line 1376, Address: 0x2aea0c, Func Offset: 0x1ec
	// Line 1377, Address: 0x2aea1c, Func Offset: 0x1fc
	// Line 1378, Address: 0x2aea28, Func Offset: 0x208
	// Line 1381, Address: 0x2aea30, Func Offset: 0x210
	// Line 1382, Address: 0x2aea3c, Func Offset: 0x21c
	// Line 1384, Address: 0x2aea44, Func Offset: 0x224
	// Line 1385, Address: 0x2aea50, Func Offset: 0x230
	// Line 1387, Address: 0x2aea58, Func Offset: 0x238
	// Line 1388, Address: 0x2aea64, Func Offset: 0x244
	// Line 1390, Address: 0x2aea6c, Func Offset: 0x24c
	// Line 1391, Address: 0x2aea7c, Func Offset: 0x25c
	// Line 1392, Address: 0x2aea88, Func Offset: 0x268
	// Line 1394, Address: 0x2aea90, Func Offset: 0x270
	// Line 1395, Address: 0x2aea9c, Func Offset: 0x27c
	// Line 1397, Address: 0x2aeaa4, Func Offset: 0x284
	// Line 1398, Address: 0x2aeab0, Func Offset: 0x290
	// Line 1400, Address: 0x2aeab8, Func Offset: 0x298
	// Line 1401, Address: 0x2aeac4, Func Offset: 0x2a4
	// Line 1403, Address: 0x2aeacc, Func Offset: 0x2ac
	// Line 1404, Address: 0x2aead8, Func Offset: 0x2b8
	// Line 1407, Address: 0x2aeae0, Func Offset: 0x2c0
	// Line 1408, Address: 0x2aeaec, Func Offset: 0x2cc
	// Line 1410, Address: 0x2aeaf4, Func Offset: 0x2d4
	// Line 1411, Address: 0x2aeb00, Func Offset: 0x2e0
	// Line 1413, Address: 0x2aeb08, Func Offset: 0x2e8
	// Line 1414, Address: 0x2aeb14, Func Offset: 0x2f4
	// Line 1416, Address: 0x2aeb1c, Func Offset: 0x2fc
	// Line 1417, Address: 0x2aeb28, Func Offset: 0x308
	// Line 1419, Address: 0x2aeb30, Func Offset: 0x310
	// Line 1420, Address: 0x2aeb34, Func Offset: 0x314
	// Line 1419, Address: 0x2aeb38, Func Offset: 0x318
	// Line 1426, Address: 0x2aeb40, Func Offset: 0x320
	// Line 1428, Address: 0x2aeb50, Func Offset: 0x330
	// Func End, Address: 0x2aeb58, Func Offset: 0x338
	scePrintf("FileNumberSwitch - UNIMPLEMENTED!\n");
}

// 100% matching!
int PlayPageCheck()
{
    int page_end00;

    if (bhCkFlg(sys->ev_flg, 0x199) != 0) 
    {
        page_end00 = 0;
    }
    else if (bhCkFlg(sys->ev_flg, 0x2B) != 0)
    {
        page_end00 = 1;
    }
    else if (bhCkFlg(sys->ev_flg, 0x129) != 0) 
    {
        page_end00 = 2;
    }
    else if (bhCkFlg(sys->ev_flg, 0xE0) != 0) 
    {
        page_end00 = 4;
    }
    else if (bhCkFlg(sys->ev_flg, 0x96) != 0)
    {
        page_end00 = 6;
    } 
    else 
    {
        page_end00 = 7;
    }
    
    return page_end00;
}
