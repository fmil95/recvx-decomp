#include "../../../ps2/veronica/prog/door.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/sdfunc.h"

_door_wrk DoorWrk;

const _proc_wrk FadeProcTbl[2] = 
{ 
	NULL, (void*)FadeProc1 
}; 
const _proc_wrk ViewProcTbl[8] = 
{ 
	NULL, (void*)ViewProc1, (void*)ViewProc2, (void*)ViewProc3, (void*)ViewProc4, (void*)ViewProc5, (void*)ViewProc6, (void*)ViewProc7 
};  
const _proc_wrk DoorProcTbl[8] = 
{ 
	NULL, (void*)DoorProc1, (void*)DoorProc2, (void*)DoorProc3, (void*)DoorProc4, (void*)DoorProc5, (void*)DoorProc6, (void*)DoorProc7 
};  
const _proc_wrk LightProcTbl[3] = 
{ 
	NULL, (void*)LightProc1, (void*)LightProc2 
};
const _proc_wrk PuruProcTbl[2] = 
{ 
	NULL, (void*)PuruProc1 
};
const int PruSndTbl[1] = { 10 };

// 100% matching!
void bhInitDoor()
{
    _door_wrk* dwP; // not from DWARF        
    static const NJS_POINT3 amb_ini = { 0 }; 
    static const NJS_POINT3 vct_ini = { 1.0f, 1.0f, 1.0f }; 

    dwP = &DoorWrk;
    
    npSetMemory((unsigned char*)dwP, sizeof(_door_wrk), 0);
    
    dwP->dmo_bufP = sys->doordp;
    
    AnalyzeDoor(dwP, sys->door.dor_tp, sys->door.flg);
    
    dwP->spd_mde = DMO_SPD_1;
    dwP->spd_mde = DMO_SPD_1;
    
    dwP->lgt_pnt_rte = vct_ini;
    dwP->lgt_amb_off = amb_ini;
}

// 
// Start address: 0x2aecf0
int bhReadDoorData()
{
	int* pacP;
	int next;
	int status;
	//_door_wrk* dwP;
	int code;
	// Line 223, Address: 0x2aecf0, Func Offset: 0
	// Line 229, Address: 0x2aed04, Func Offset: 0x14
	// Line 226, Address: 0x2aed08, Func Offset: 0x18
	// Line 229, Address: 0x2aed10, Func Offset: 0x20
	// Line 273, Address: 0x2aed3c, Func Offset: 0x4c
	// Line 274, Address: 0x2aed4c, Func Offset: 0x5c
	// Line 289, Address: 0x2aed68, Func Offset: 0x78
	// Line 291, Address: 0x2aed70, Func Offset: 0x80
	// Line 299, Address: 0x2aed7c, Func Offset: 0x8c
	// Line 300, Address: 0x2aed84, Func Offset: 0x94
	// Line 302, Address: 0x2aed98, Func Offset: 0xa8
	// Line 306, Address: 0x2aeda0, Func Offset: 0xb0
	// Line 313, Address: 0x2aeda8, Func Offset: 0xb8
	// Line 315, Address: 0x2aedbc, Func Offset: 0xcc
	// Line 319, Address: 0x2aedc0, Func Offset: 0xd0
	// Line 316, Address: 0x2aedc4, Func Offset: 0xd4
	// Line 317, Address: 0x2aedc8, Func Offset: 0xd8
	// Line 319, Address: 0x2aedcc, Func Offset: 0xdc
	// Line 320, Address: 0x2aedd4, Func Offset: 0xe4
	// Line 322, Address: 0x2aede0, Func Offset: 0xf0
	// Line 323, Address: 0x2aede8, Func Offset: 0xf8
	// Line 324, Address: 0x2aedec, Func Offset: 0xfc
	// Line 326, Address: 0x2aedf8, Func Offset: 0x108
	// Line 328, Address: 0x2aedfc, Func Offset: 0x10c
	// Line 326, Address: 0x2aee00, Func Offset: 0x110
	// Line 329, Address: 0x2aee04, Func Offset: 0x114
	// Line 330, Address: 0x2aee08, Func Offset: 0x118
	// Line 334, Address: 0x2aee10, Func Offset: 0x120
	// Line 340, Address: 0x2aee18, Func Offset: 0x128
	// Line 342, Address: 0x2aee20, Func Offset: 0x130
	// Line 343, Address: 0x2aee30, Func Offset: 0x140
	// Line 344, Address: 0x2aee38, Func Offset: 0x148
	// Line 346, Address: 0x2aee3c, Func Offset: 0x14c
	// Line 348, Address: 0x2aee48, Func Offset: 0x158
	// Line 350, Address: 0x2aee54, Func Offset: 0x164
	// Line 352, Address: 0x2aee60, Func Offset: 0x170
	// Line 354, Address: 0x2aee6c, Func Offset: 0x17c
	// Line 356, Address: 0x2aee74, Func Offset: 0x184
	// Line 358, Address: 0x2aee80, Func Offset: 0x190
	// Line 362, Address: 0x2aee88, Func Offset: 0x198
	// Line 363, Address: 0x2aeea0, Func Offset: 0x1b0
	// Line 373, Address: 0x2aeea4, Func Offset: 0x1b4
	// Func End, Address: 0x2aeebc, Func Offset: 0x1cc
	scePrintf("bhReadDoorData - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2aeec0
void bhSetDoor()
{
	//_anon3* ptP;
	//_anon36* phP;
	//_anon3* ptP;
	//_anon36* phP;
	//_door_wrk* dwP;
	int i;
	float far;
	float near;
	//_anon43 DkiPru;
	//_anon33 dmo_clip[2];
	// Line 392, Address: 0x2aeec0, Func Offset: 0
	// Line 402, Address: 0x2aeecc, Func Offset: 0xc
	// Line 406, Address: 0x2aeed4, Func Offset: 0x14
	// Line 407, Address: 0x2aeedc, Func Offset: 0x1c
	// Line 409, Address: 0x2aeee0, Func Offset: 0x20
	// Line 410, Address: 0x2aeef8, Func Offset: 0x38
	// Line 412, Address: 0x2aef0c, Func Offset: 0x4c
	// Line 414, Address: 0x2aef14, Func Offset: 0x54
	// Line 413, Address: 0x2aef18, Func Offset: 0x58
	// Line 414, Address: 0x2aef28, Func Offset: 0x68
	// Line 415, Address: 0x2aef30, Func Offset: 0x70
	// Line 418, Address: 0x2aef5c, Func Offset: 0x9c
	// Line 419, Address: 0x2aef78, Func Offset: 0xb8
	// Line 420, Address: 0x2aef84, Func Offset: 0xc4
	// Line 422, Address: 0x2aef90, Func Offset: 0xd0
	// Line 429, Address: 0x2aefa8, Func Offset: 0xe8
	// Line 434, Address: 0x2aefb0, Func Offset: 0xf0
	// Line 435, Address: 0x2aefcc, Func Offset: 0x10c
	// Line 438, Address: 0x2aefdc, Func Offset: 0x11c
	// Line 439, Address: 0x2aefe4, Func Offset: 0x124
	// Line 442, Address: 0x2aefec, Func Offset: 0x12c
	// Line 445, Address: 0x2af004, Func Offset: 0x144
	// Line 446, Address: 0x2af010, Func Offset: 0x150
	// Line 451, Address: 0x2af01c, Func Offset: 0x15c
	// Line 454, Address: 0x2af020, Func Offset: 0x160
	// Line 455, Address: 0x2af034, Func Offset: 0x174
	// Line 458, Address: 0x2af044, Func Offset: 0x184
	// Line 461, Address: 0x2af050, Func Offset: 0x190
	// Line 458, Address: 0x2af058, Func Offset: 0x198
	// Line 459, Address: 0x2af068, Func Offset: 0x1a8
	// Line 464, Address: 0x2af06c, Func Offset: 0x1ac
	// Line 467, Address: 0x2af074, Func Offset: 0x1b4
	// Line 459, Address: 0x2af07c, Func Offset: 0x1bc
	// Line 461, Address: 0x2af084, Func Offset: 0x1c4
	// Line 470, Address: 0x2af088, Func Offset: 0x1c8
	// Line 461, Address: 0x2af090, Func Offset: 0x1d0
	// Line 462, Address: 0x2af0a0, Func Offset: 0x1e0
	// Line 464, Address: 0x2af0ac, Func Offset: 0x1ec
	// Line 465, Address: 0x2af0c0, Func Offset: 0x200
	// Line 467, Address: 0x2af0cc, Func Offset: 0x20c
	// Line 468, Address: 0x2af0e0, Func Offset: 0x220
	// Line 470, Address: 0x2af0ec, Func Offset: 0x22c
	// Line 471, Address: 0x2af100, Func Offset: 0x240
	// Line 476, Address: 0x2af10c, Func Offset: 0x24c
	// Line 477, Address: 0x2af128, Func Offset: 0x268
	// Line 478, Address: 0x2af144, Func Offset: 0x284
	// Line 479, Address: 0x2af160, Func Offset: 0x2a0
	// Line 481, Address: 0x2af17c, Func Offset: 0x2bc
	// Line 484, Address: 0x2af19c, Func Offset: 0x2dc
	// Line 485, Address: 0x2af1ac, Func Offset: 0x2ec
	// Line 487, Address: 0x2af1b8, Func Offset: 0x2f8
	// Line 488, Address: 0x2af1d8, Func Offset: 0x318
	// Line 492, Address: 0x2af1e8, Func Offset: 0x328
	// Line 493, Address: 0x2af208, Func Offset: 0x348
	// Line 497, Address: 0x2af228, Func Offset: 0x368
	// Line 498, Address: 0x2af22c, Func Offset: 0x36c
	// Line 501, Address: 0x2af234, Func Offset: 0x374
	// Line 497, Address: 0x2af238, Func Offset: 0x378
	// Line 498, Address: 0x2af240, Func Offset: 0x380
	// Line 501, Address: 0x2af248, Func Offset: 0x388
	// Line 504, Address: 0x2af250, Func Offset: 0x390
	// Line 507, Address: 0x2af264, Func Offset: 0x3a4
	// Line 509, Address: 0x2af270, Func Offset: 0x3b0
	// Line 510, Address: 0x2af278, Func Offset: 0x3b8
	// Line 509, Address: 0x2af280, Func Offset: 0x3c0
	// Line 510, Address: 0x2af284, Func Offset: 0x3c4
	// Line 513, Address: 0x2af288, Func Offset: 0x3c8
	// Func End, Address: 0x2af298, Func Offset: 0x3d8
	scePrintf("bhSetDoor - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhExitDoor()
{
	_door_wrk* dwP;

	dwP = &DoorWrk;

	njClipZ(-2.0f, -20000.0f);

    njSetAspect(BHD_ASPECT_X, BHD_ASPECT_Y);

    if (dwP->dor_mdl.texP != NULL) 
	{
        njReleaseTexture(dwP->dor_mdl.texP);
		
        bhGarbageTexture(NULL, 0);

        Ps2ClearOT();

        if (sys->fade_an > 0) 
		{
            bhDrawScreenFade();
        }
    }
}

// 100% matching!
int AnalyzeDoor(_door_wrk* dwP, int typ_no, int attr)
{
	dwP->dmo_typ = typ_no;
	dwP->dmo_atr = attr;

	dwP->cse_no = (attr & 0x180) >> 7;

	return 1;
}

// 
// Start address: 0x2af370
int bhControlDoor()
{
	int lop;
	//_door_wrk* dwP;
	// Line 573, Address: 0x2af370, Func Offset: 0
	// Line 575, Address: 0x2af380, Func Offset: 0x10
	// Line 574, Address: 0x2af388, Func Offset: 0x18
	// Line 582, Address: 0x2af390, Func Offset: 0x20
	// Line 588, Address: 0x2af3a4, Func Offset: 0x34
	// Line 589, Address: 0x2af3b4, Func Offset: 0x44
	// Line 590, Address: 0x2af3d0, Func Offset: 0x60
	// Line 591, Address: 0x2af3f8, Func Offset: 0x88
	// Line 592, Address: 0x2af420, Func Offset: 0xb0
	// Line 593, Address: 0x2af448, Func Offset: 0xd8
	// Line 594, Address: 0x2af470, Func Offset: 0x100
	// Line 595, Address: 0x2af498, Func Offset: 0x128
	// Line 596, Address: 0x2af4a4, Func Offset: 0x134
	// Line 597, Address: 0x2af4a8, Func Offset: 0x138
	// Line 609, Address: 0x2af4b4, Func Offset: 0x144
	// Line 610, Address: 0x2af4c8, Func Offset: 0x158
	// Line 611, Address: 0x2af4d4, Func Offset: 0x164
	// Line 612, Address: 0x2af4dc, Func Offset: 0x16c
	// Line 613, Address: 0x2af4ec, Func Offset: 0x17c
	// Line 614, Address: 0x2af4f8, Func Offset: 0x188
	// Line 615, Address: 0x2af500, Func Offset: 0x190
	// Line 616, Address: 0x2af510, Func Offset: 0x1a0
	// Line 617, Address: 0x2af51c, Func Offset: 0x1ac
	// Line 618, Address: 0x2af524, Func Offset: 0x1b4
	// Line 619, Address: 0x2af534, Func Offset: 0x1c4
	// Line 623, Address: 0x2af540, Func Offset: 0x1d0
	// Line 665, Address: 0x2af554, Func Offset: 0x1e4
	// Line 667, Address: 0x2af564, Func Offset: 0x1f4
	// Line 670, Address: 0x2af56c, Func Offset: 0x1fc
	// Line 671, Address: 0x2af574, Func Offset: 0x204
	// Line 674, Address: 0x2af580, Func Offset: 0x210
	// Line 675, Address: 0x2af590, Func Offset: 0x220
	// Line 676, Address: 0x2af5a0, Func Offset: 0x230
	// Line 677, Address: 0x2af5b0, Func Offset: 0x240
	// Line 680, Address: 0x2af5d0, Func Offset: 0x260
	// Line 683, Address: 0x2af5d8, Func Offset: 0x268
	// Line 686, Address: 0x2af5f4, Func Offset: 0x284
	// Line 689, Address: 0x2af608, Func Offset: 0x298
	// Line 691, Address: 0x2af614, Func Offset: 0x2a4
	// Line 700, Address: 0x2af624, Func Offset: 0x2b4
	// Line 701, Address: 0x2af63c, Func Offset: 0x2cc
	// Line 704, Address: 0x2af644, Func Offset: 0x2d4
	// Line 705, Address: 0x2af64c, Func Offset: 0x2dc
	// Line 707, Address: 0x2af654, Func Offset: 0x2e4
	// Line 713, Address: 0x2af660, Func Offset: 0x2f0
	// Line 715, Address: 0x2af66c, Func Offset: 0x2fc
	// Line 725, Address: 0x2af67c, Func Offset: 0x30c
	// Line 726, Address: 0x2af68c, Func Offset: 0x31c
	// Line 727, Address: 0x2af698, Func Offset: 0x328
	// Line 728, Address: 0x2af6a0, Func Offset: 0x330
	// Line 729, Address: 0x2af6b0, Func Offset: 0x340
	// Line 730, Address: 0x2af6bc, Func Offset: 0x34c
	// Line 731, Address: 0x2af6c4, Func Offset: 0x354
	// Line 732, Address: 0x2af6d4, Func Offset: 0x364
	// Line 733, Address: 0x2af6e0, Func Offset: 0x370
	// Line 734, Address: 0x2af6e8, Func Offset: 0x378
	// Line 735, Address: 0x2af6f8, Func Offset: 0x388
	// Line 739, Address: 0x2af704, Func Offset: 0x394
	// Line 741, Address: 0x2af718, Func Offset: 0x3a8
	// Line 742, Address: 0x2af730, Func Offset: 0x3c0
	// Line 744, Address: 0x2af734, Func Offset: 0x3c4
	// Func End, Address: 0x2af748, Func Offset: 0x3d8
	scePrintf("bhControlDoor - UNIMPLEMENTED!\n");
}

// 100% matching!
static void ControlSoundTiming(_door_wrk* dwP) 
{
    int cmd_no;
    int sts;
    int* bsP; // not from DWARF
    
    sts = dwP->status;
    
    bsP = dwP->BgmSet;
    
    for (cmd_no = 0; *bsP != -1; bsP++, cmd_no++) 
    {
        if ((sts & *bsP)) 
        {
            SendSoundCommand(cmd_no);
            
            *bsP = 0;
        }
    }
}

// 100% matching!
static void SetSoundTiming(_door_wrk* dwP)
{
	int i;
	int* sfP, *bsP;
	static const int SetFlag[11] = { 0, 0, 0, 0, 0, 0x1000000, 0x2000000, 0x4000000, 0x10, 0x20, -1 };

    bsP = dwP->BgmSet;
    sfP = SetFlag;

	for (i = 11; i > 0; i--) 
	{
    	*bsP++ = *sfP++;
	}
}

// 
// Start address: 0x2af800
void FadeProc1(_door_wrk* dwP)
{
	//_anon11* fpP;
	// Line 822, Address: 0x2af800, Func Offset: 0
	// Line 825, Address: 0x2af810, Func Offset: 0x10
	// Line 823, Address: 0x2af814, Func Offset: 0x14
	// Line 825, Address: 0x2af818, Func Offset: 0x18
	// Line 828, Address: 0x2af840, Func Offset: 0x40
	// Line 829, Address: 0x2af848, Func Offset: 0x48
	// Line 832, Address: 0x2af854, Func Offset: 0x54
	// Line 838, Address: 0x2af864, Func Offset: 0x64
	// Line 840, Address: 0x2af86c, Func Offset: 0x6c
	// Line 841, Address: 0x2af874, Func Offset: 0x74
	// Line 842, Address: 0x2af880, Func Offset: 0x80
	// Line 843, Address: 0x2af88c, Func Offset: 0x8c
	// Line 848, Address: 0x2af898, Func Offset: 0x98
	// Line 849, Address: 0x2af8a8, Func Offset: 0xa8
	// Line 850, Address: 0x2af8bc, Func Offset: 0xbc
	// Line 851, Address: 0x2af8cc, Func Offset: 0xcc
	// Line 852, Address: 0x2af8d4, Func Offset: 0xd4
	// Line 854, Address: 0x2af8dc, Func Offset: 0xdc
	// Line 857, Address: 0x2af8e4, Func Offset: 0xe4
	// Line 863, Address: 0x2af8f4, Func Offset: 0xf4
	// Line 865, Address: 0x2af8fc, Func Offset: 0xfc
	// Line 866, Address: 0x2af904, Func Offset: 0x104
	// Line 867, Address: 0x2af910, Func Offset: 0x110
	// Line 872, Address: 0x2af91c, Func Offset: 0x11c
	// Line 873, Address: 0x2af92c, Func Offset: 0x12c
	// Line 874, Address: 0x2af940, Func Offset: 0x140
	// Line 875, Address: 0x2af948, Func Offset: 0x148
	// Line 874, Address: 0x2af94c, Func Offset: 0x14c
	// Line 875, Address: 0x2af954, Func Offset: 0x154
	// Line 876, Address: 0x2af960, Func Offset: 0x160
	// Line 877, Address: 0x2af96c, Func Offset: 0x16c
	// Line 878, Address: 0x2af974, Func Offset: 0x174
	// Line 880, Address: 0x2af97c, Func Offset: 0x17c
	// Line 883, Address: 0x2af984, Func Offset: 0x184
	// Line 885, Address: 0x2af994, Func Offset: 0x194
	// Line 886, Address: 0x2af9a0, Func Offset: 0x1a0
	// Line 893, Address: 0x2af9ac, Func Offset: 0x1ac
	// Func End, Address: 0x2af9c0, Func Offset: 0x1c0
	scePrintf("FadeProc1 - UNIMPLEMENTED!\n");
}

// 100% matching!
static void ViewProc1(_door_wrk* dwP)
{
    int flp;            
    VIEWPROC_WORK* vpP; 

    dwP->status = dwP->status;
    
    vpP = dwP->vpP;
    
    if ((dwP->status & 0x8000)) 
    {
        flp = -1;
    } 
    else 
    {
        flp = 1;
    }
    
    switch (dwP->vew_mode) 
    {              
    case 0:
        if ((dwP->status & 0x4000)) 
        {
            dwP->vew_pos = vpP->pos_pull;
            dwP->vew_reg = vpP->wait_pull;
        } 
        else 
        {
            dwP->vew_pos = vpP->pos_push;
            dwP->vew_reg = vpP->wait_push;
        }
        
        dwP->vew_ang[0] = vpP->ang[0];
        dwP->vew_ang[1] = vpP->ang[1];
        dwP->vew_ang[2] = vpP->ang[2];
        
        if ((dwP->status & 0x1000)) 
        {
            dwP->vew_yaw = 0;
        } 
        else 
        {
            dwP->vew_yaw = vpP->vew0_yaw * flp;
        }
        
        dwP->vew_pitch = vpP->vew0_pitch;
        dwP->vew_speed = vpP->vew0_speed;
        
        dwP->vew_mode++;
    case 1:
        if (dwP->vew_reg-- <= 0) 
        {
            dwP->status |= 0x8000000;
            
            dwP->vew_mode++;
        } 
        else 
        {
            break;
        }
    case 2:
        if (CompareFloat(dwP->vew_pos.z, vpP->vew0_cmp, vpP->vew0_goal_pz) != 0) 
        {
            VectorMove(&dwP->vew_pos, dwP->vew_yaw, dwP->vew_pitch, dwP->vew_speed);
            
            dwP->vew_speed += vpP->vew0_accel;
            
            if (CompareSint32(dwP->vew_yaw, vpP->vew0_cmp_dy * flp, vpP->vew0_goal_dy * flp) != 0) 
            {
                dwP->vew_yaw += vpP->vew0_speed_dy * flp;
                break;
            }
        } 
        else 
        {
            dwP->vew_mode++;
        }
    case 3:
        break;
    }
}

// 100% matching!
static void ViewProc2(_door_wrk* dwP) 
{
    VIEWPROC2_WORK* vpP, *prmP;   
    NJS_VECTOR vct;     
    float y; // not from DWARF
    
    vpP = prmP = dwP->vpP;
    
    if ((dwP->status & 0x4000)) 
    {
        vpP = (VIEWPROC2_WORK*)&prmP->pos_high;
    }
    
    switch (dwP->vew_mode) 
    {                         
    case 0:
        dwP->vew_reg = prmP->wait;
        
        dwP->vew_pos = vpP->pos_low;
        dwP->vew_yaw = vpP->yaw_low;
        dwP->vew_pitch = vpP->pitch_low;
        dwP->vew_speed = vpP->speed_low;
        dwP->vew_ang[2] = vpP->roll_low;
        
        dwP->vew_mode++;
    case 1:
        if (dwP->vew_reg-- <= 0) 
        {
            dwP->status |= 0x10000;
            dwP->status |= 0x200000;
            dwP->status |= 0x8000000;
            
            dwP->vew_mode++;
        } 
        else 
        {
            break;
        }
    case 2:
        VectorMove(&dwP->vew_pos, dwP->vew_yaw, dwP->vew_pitch, dwP->vew_speed);
        
        dwP->vew_speed += vpP->accel_low;
        break;
    }
    
    vct = vpP->tgt_low;
    
    njSubVector(&vct, &dwP->vew_pos);
    
    y = vct.y; 
    
    dwP->vew_ang[0] = (int)(10430.381f * atan2f(y, njSqrt((vct.x * vct.x) + (vct.z * vct.z))));
    dwP->vew_ang[1] = (int)(10430.381f * atan2f(-vct.x, -vct.z));
}

/*// 
// Start address: 0x2afd50
void ViewProc3(_door_wrk* dwP)
{
	_anon7* prmP;
	_anon7* vpP;
	// Line 1029, Address: 0x2afd50, Func Offset: 0
	// Line 1033, Address: 0x2afd64, Func Offset: 0x14
	// Line 1031, Address: 0x2afd68, Func Offset: 0x18
	// Line 1033, Address: 0x2afd70, Func Offset: 0x20
	// Line 1035, Address: 0x2afd80, Func Offset: 0x30
	// Line 1039, Address: 0x2afdac, Func Offset: 0x5c
	// Line 1040, Address: 0x2afdb4, Func Offset: 0x64
	// Line 1042, Address: 0x2afdbc, Func Offset: 0x6c
	// Line 1043, Address: 0x2afdd4, Func Offset: 0x84
	// Line 1044, Address: 0x2afddc, Func Offset: 0x8c
	// Line 1045, Address: 0x2afde4, Func Offset: 0x94
	// Line 1046, Address: 0x2afdec, Func Offset: 0x9c
	// Line 1047, Address: 0x2afdf4, Func Offset: 0xa4
	// Line 1048, Address: 0x2afdfc, Func Offset: 0xac
	// Line 1052, Address: 0x2afe08, Func Offset: 0xb8
	// Line 1054, Address: 0x2afe18, Func Offset: 0xc8
	// Line 1058, Address: 0x2afe1c, Func Offset: 0xcc
	// Line 1054, Address: 0x2afe20, Func Offset: 0xd0
	// Line 1055, Address: 0x2afe24, Func Offset: 0xd4
	// Line 1056, Address: 0x2afe2c, Func Offset: 0xdc
	// Line 1057, Address: 0x2afe34, Func Offset: 0xe4
	// Line 1058, Address: 0x2afe4c, Func Offset: 0xfc
	// Line 1059, Address: 0x2afe58, Func Offset: 0x108
	// Line 1064, Address: 0x2afe64, Func Offset: 0x114
	// Line 1065, Address: 0x2afe74, Func Offset: 0x124
	// Line 1066, Address: 0x2afe88, Func Offset: 0x138
	// Line 1070, Address: 0x2afe90, Func Offset: 0x140
	// Line 1066, Address: 0x2afea0, Func Offset: 0x150
	// Line 1067, Address: 0x2afea8, Func Offset: 0x158
	// Line 1068, Address: 0x2afeb8, Func Offset: 0x168
	// Line 1070, Address: 0x2afec8, Func Offset: 0x178
	// Line 1071, Address: 0x2aff08, Func Offset: 0x1b8
	// Line 1078, Address: 0x2aff0c, Func Offset: 0x1bc
	// Line 1071, Address: 0x2aff10, Func Offset: 0x1c0
	// Line 1072, Address: 0x2aff14, Func Offset: 0x1c4
	// Line 1073, Address: 0x2aff1c, Func Offset: 0x1cc
	// Line 1074, Address: 0x2aff24, Func Offset: 0x1d4
	// Line 1075, Address: 0x2aff2c, Func Offset: 0x1dc
	// Line 1078, Address: 0x2aff44, Func Offset: 0x1f4
	// Line 1085, Address: 0x2aff50, Func Offset: 0x200
	// Line 1086, Address: 0x2aff5c, Func Offset: 0x20c
	// Line 1087, Address: 0x2aff8c, Func Offset: 0x23c
	// Line 1088, Address: 0x2affbc, Func Offset: 0x26c
	// Line 1089, Address: 0x2affe8, Func Offset: 0x298
	// Line 1091, Address: 0x2afff8, Func Offset: 0x2a8
	// Func End, Address: 0x2b0010, Func Offset: 0x2c0
}*/

// 100% matching!
static void ViewProc4(_door_wrk* dwP) 
{
    VIEWPROC4_WORK* vpP, *prmP;
    
    vpP = prmP = dwP->vpP;
    
    if ((dwP->status & 0x4000))
    {
        vpP = (VIEWPROC4_WORK*)&prmP->pos_high;
    }
    
    switch (dwP->vew_mode) 
    {                            
    case 0:
        dwP->vew_reg = prmP->wait;
        
        dwP->vew_pos = vpP->pos_low;
        
        dwP->vew_ang[0] = vpP->ang_low[0];
        dwP->vew_ang[1] = vpP->ang_low[1];
        dwP->vew_ang[2] = vpP->ang_low[2];
        
        dwP->vew_mode++;
    case 1:
        if (dwP->vew_reg-- <= 0) 
        {
            dwP->vew_mode = 0;
            
            dwP->vew_prcP = ViewProcTbl[prmP->chg_vew].procP;
            dwP->vpP = &prmP[1];
        }
        
        break;
    }
}

// 100% matching!
static void ViewProc5(_door_wrk* dwP) 
{
    VIEWPROC5_WORK* vpP, *prmP;
    
    vpP = prmP = dwP->vpP;
    
    if ((dwP->status & 0x4000)) 
    {
        vpP = (VIEWPROC5_WORK*)&prmP->pos_high;
    }
    
    switch (dwP->vew_mode) 
    {                          
    case 0:
        dwP->vew_reg = prmP->wait0;
        
        dwP->vew_mode++;
    case 1:
        if (dwP->vew_reg > 0)
        {
            if (--dwP->vew_reg == 0) 
            {
                dwP->status |= 0x100;
                
                dwP->fde_rate = prmP->fde_rte0;
            }
        } 
        else 
        {
            dwP->fde_rate += prmP->fde_spd0;
            
            if (CompareFloat(dwP->fde_rate, prmP->fde_cmp0, prmP->fde_gol0) != 0) 
            {
                dwP->fde_rate = prmP->fde_rte1;
                
                dwP->vew_reg = prmP->wait1;
                
                dwP->vew_mode++;
                
                dwP->vew_pos = vpP->pos_low;
                
                dwP->vew_ang[0] = vpP->ang_low[0];
                dwP->vew_ang[1] = vpP->ang_low[1];
                dwP->vew_ang[2] = vpP->ang_low[2];
                
                if ((dwP->dmo_atr & 0x2)) 
                {
                    dwP->vew_pos.x *= -1.0f;
                }
            }
        }
        
        break;
    case 2:
        if (dwP->vew_reg > 0) 
        {
            dwP->vew_reg--;
            break;
        }
        
        dwP->fde_rate += prmP->fde_spd1;
        
        if (CompareFloat(dwP->fde_rate, prmP->fde_cmp1, prmP->fde_gol1) != 0)
        {
            dwP->status &= ~0x100;
            
            dwP->vew_mode = 0;
            
            dwP->vew_prcP = ViewProcTbl[prmP->chg_vew].procP;
            dwP->vpP = &prmP[1];
        }
        
        break;
    }
}

/*// 
// Start address: 0x2b02a0
void ViewProc6(_door_wrk* dwP)
{
	float adj_ang;
	float adj_pos;
	_anon50* prmP;
	_anon50* vpP;
	// Line 1212, Address: 0x2b02a0, Func Offset: 0
	// Line 1217, Address: 0x2b02b8, Func Offset: 0x18
	// Line 1215, Address: 0x2b02bc, Func Offset: 0x1c
	// Line 1217, Address: 0x2b02c4, Func Offset: 0x24
	// Line 1219, Address: 0x2b02d4, Func Offset: 0x34
	// Line 1223, Address: 0x2b02f4, Func Offset: 0x54
	// Line 1227, Address: 0x2b02f8, Func Offset: 0x58
	// Line 1223, Address: 0x2b030c, Func Offset: 0x6c
	// Line 1224, Address: 0x2b0310, Func Offset: 0x70
	// Line 1226, Address: 0x2b0318, Func Offset: 0x78
	// Line 1227, Address: 0x2b0320, Func Offset: 0x80
	// Line 1228, Address: 0x2b0344, Func Offset: 0xa4
	// Line 1230, Address: 0x2b0368, Func Offset: 0xc8
	// Line 1234, Address: 0x2b0374, Func Offset: 0xd4
	// Line 1235, Address: 0x2b0380, Func Offset: 0xe0
	// Line 1237, Address: 0x2b0390, Func Offset: 0xf0
	// Line 1238, Address: 0x2b03a0, Func Offset: 0x100
	// Line 1240, Address: 0x2b03c8, Func Offset: 0x128
	// Line 1242, Address: 0x2b03e8, Func Offset: 0x148
	// Line 1243, Address: 0x2b0408, Func Offset: 0x168
	// Line 1244, Address: 0x2b0424, Func Offset: 0x184
	// Line 1245, Address: 0x2b042c, Func Offset: 0x18c
	// Line 1247, Address: 0x2b0434, Func Offset: 0x194
	// Line 1248, Address: 0x2b0440, Func Offset: 0x1a0
	// Line 1250, Address: 0x2b0450, Func Offset: 0x1b0
	// Line 1252, Address: 0x2b048c, Func Offset: 0x1ec
	// Line 1253, Address: 0x2b049c, Func Offset: 0x1fc
	// Line 1255, Address: 0x2b04e0, Func Offset: 0x240
	// Line 1257, Address: 0x2b051c, Func Offset: 0x27c
	// Line 1258, Address: 0x2b0554, Func Offset: 0x2b4
	// Line 1259, Address: 0x2b055c, Func Offset: 0x2bc
	// Line 1261, Address: 0x2b0564, Func Offset: 0x2c4
	// Line 1263, Address: 0x2b0574, Func Offset: 0x2d4
	// Line 1264, Address: 0x2b0578, Func Offset: 0x2d8
	// Line 1265, Address: 0x2b0584, Func Offset: 0x2e4
	// Line 1264, Address: 0x2b0588, Func Offset: 0x2e8
	// Line 1265, Address: 0x2b0598, Func Offset: 0x2f8
	// Line 1270, Address: 0x2b059c, Func Offset: 0x2fc
	// Func End, Address: 0x2b05b8, Func Offset: 0x318
}

// 
// Start address: 0x2b05c0
void ViewProc7(_door_wrk* dwP)
{
	_anon21* vpP;
	int flp;
	// Line 1281, Address: 0x2b05c0, Func Offset: 0
	// Line 1285, Address: 0x2b05c8, Func Offset: 0x8
	// Line 1287, Address: 0x2b05cc, Func Offset: 0xc
	// Line 1283, Address: 0x2b05d0, Func Offset: 0x10
	// Line 1285, Address: 0x2b05d4, Func Offset: 0x14
	// Line 1287, Address: 0x2b05e0, Func Offset: 0x20
	// Line 1288, Address: 0x2b05e8, Func Offset: 0x28
	// Line 1290, Address: 0x2b05f4, Func Offset: 0x34
	// Line 1291, Address: 0x2b05f8, Func Offset: 0x38
	// Line 1293, Address: 0x2b0600, Func Offset: 0x40
	// Line 1296, Address: 0x2b0608, Func Offset: 0x48
	// Line 1297, Address: 0x2b0620, Func Offset: 0x60
	// Line 1299, Address: 0x2b062c, Func Offset: 0x6c
	// Line 1300, Address: 0x2b0634, Func Offset: 0x74
	// Line 1301, Address: 0x2b063c, Func Offset: 0x7c
	// Line 1302, Address: 0x2b0644, Func Offset: 0x84
	// Line 1303, Address: 0x2b064c, Func Offset: 0x8c
	// Line 1305, Address: 0x2b0654, Func Offset: 0x94
	// Func End, Address: 0x2b0660, Func Offset: 0xa0
}

// 
// Start address: 0x2b0660
void DoorProc1(_door_wrk* dwP)
{
	_anon51* dpP;
	npobj* objP;
	npobj* obP;
	npobj* oaP;
	int flp_n;
	int flp_d;
	// Line 1322, Address: 0x2b0660, Func Offset: 0
	// Line 1327, Address: 0x2b0680, Func Offset: 0x20
	// Line 1328, Address: 0x2b0684, Func Offset: 0x24
	// Line 1331, Address: 0x2b068c, Func Offset: 0x2c
	// Line 1332, Address: 0x2b06a8, Func Offset: 0x48
	// Line 1334, Address: 0x2b06b0, Func Offset: 0x50
	// Line 1336, Address: 0x2b06c4, Func Offset: 0x64
	// Line 1337, Address: 0x2b06d8, Func Offset: 0x78
	// Line 1340, Address: 0x2b06e0, Func Offset: 0x80
	// Line 1343, Address: 0x2b070c, Func Offset: 0xac
	// Line 1344, Address: 0x2b0714, Func Offset: 0xb4
	// Line 1348, Address: 0x2b0720, Func Offset: 0xc0
	// Line 1351, Address: 0x2b0730, Func Offset: 0xd0
	// Line 1358, Address: 0x2b0734, Func Offset: 0xd4
	// Line 1351, Address: 0x2b0738, Func Offset: 0xd8
	// Line 1352, Address: 0x2b0740, Func Offset: 0xe0
	// Line 1353, Address: 0x2b074c, Func Offset: 0xec
	// Line 1354, Address: 0x2b0754, Func Offset: 0xf4
	// Line 1356, Address: 0x2b075c, Func Offset: 0xfc
	// Line 1358, Address: 0x2b0764, Func Offset: 0x104
	// Line 1359, Address: 0x2b0770, Func Offset: 0x110
	// Line 1364, Address: 0x2b077c, Func Offset: 0x11c
	// Line 1365, Address: 0x2b079c, Func Offset: 0x13c
	// Line 1366, Address: 0x2b07ac, Func Offset: 0x14c
	// Line 1369, Address: 0x2b07c0, Func Offset: 0x160
	// Line 1370, Address: 0x2b07dc, Func Offset: 0x17c
	// Line 1372, Address: 0x2b07e4, Func Offset: 0x184
	// Line 1376, Address: 0x2b07f0, Func Offset: 0x190
	// Line 1380, Address: 0x2b0800, Func Offset: 0x1a0
	// Line 1382, Address: 0x2b080c, Func Offset: 0x1ac
	// Line 1383, Address: 0x2b0818, Func Offset: 0x1b8
	// Line 1384, Address: 0x2b0820, Func Offset: 0x1c0
	// Line 1389, Address: 0x2b082c, Func Offset: 0x1cc
	// Line 1390, Address: 0x2b084c, Func Offset: 0x1ec
	// Line 1391, Address: 0x2b085c, Func Offset: 0x1fc
	// Line 1395, Address: 0x2b0870, Func Offset: 0x210
	// Line 1397, Address: 0x2b0890, Func Offset: 0x230
	// Line 1399, Address: 0x2b08b0, Func Offset: 0x250
	// Line 1400, Address: 0x2b08bc, Func Offset: 0x25c
	// Line 1402, Address: 0x2b08c4, Func Offset: 0x264
	// Line 1406, Address: 0x2b08d0, Func Offset: 0x270
	// Line 1409, Address: 0x2b08e0, Func Offset: 0x280
	// Line 1410, Address: 0x2b08ec, Func Offset: 0x28c
	// Line 1415, Address: 0x2b08f8, Func Offset: 0x298
	// Line 1416, Address: 0x2b0918, Func Offset: 0x2b8
	// Line 1417, Address: 0x2b0928, Func Offset: 0x2c8
	// Line 1418, Address: 0x2b0938, Func Offset: 0x2d8
	// Line 1419, Address: 0x2b0940, Func Offset: 0x2e0
	// Line 1420, Address: 0x2b0954, Func Offset: 0x2f4
	// Line 1423, Address: 0x2b0964, Func Offset: 0x304
	// Line 1424, Address: 0x2b0980, Func Offset: 0x320
	// Line 1425, Address: 0x2b0990, Func Offset: 0x330
	// Line 1435, Address: 0x2b099c, Func Offset: 0x33c
	// Line 1436, Address: 0x2b09ac, Func Offset: 0x34c
	// Line 1437, Address: 0x2b09b8, Func Offset: 0x358
	// Line 1440, Address: 0x2b09c4, Func Offset: 0x364
	// Func End, Address: 0x2b09e8, Func Offset: 0x388
}

// 
// Start address: 0x2b09f0
void DoorProc2(_door_wrk* dwP)
{
	float pos_x;
	int ang_z;
	int pole;
	npobj* objP;
	npobj* basP;
	int j;
	int i;
	npobj* basP;
	_anon0* dpP;
	// Line 1450, Address: 0x2b09f0, Func Offset: 0
	// Line 1455, Address: 0x2b0a04, Func Offset: 0x14
	// Line 1457, Address: 0x2b0a08, Func Offset: 0x18
	// Line 1454, Address: 0x2b0a0c, Func Offset: 0x1c
	// Line 1457, Address: 0x2b0a10, Func Offset: 0x20
	// Line 1460, Address: 0x2b0a48, Func Offset: 0x58
	// Line 1462, Address: 0x2b0a50, Func Offset: 0x60
	// Line 1463, Address: 0x2b0a58, Func Offset: 0x68
	// Line 1464, Address: 0x2b0a60, Func Offset: 0x70
	// Line 1466, Address: 0x2b0a64, Func Offset: 0x74
	// Line 1468, Address: 0x2b0a70, Func Offset: 0x80
	// Line 1476, Address: 0x2b0a74, Func Offset: 0x84
	// Line 1466, Address: 0x2b0a78, Func Offset: 0x88
	// Line 1468, Address: 0x2b0a80, Func Offset: 0x90
	// Line 1469, Address: 0x2b0a8c, Func Offset: 0x9c
	// Line 1473, Address: 0x2b0a98, Func Offset: 0xa8
	// Line 1477, Address: 0x2b0aa4, Func Offset: 0xb4
	// Line 1478, Address: 0x2b0ac4, Func Offset: 0xd4
	// Line 1481, Address: 0x2b0ad4, Func Offset: 0xe4
	// Line 1482, Address: 0x2b0ad8, Func Offset: 0xe8
	// Line 1484, Address: 0x2b0ae8, Func Offset: 0xf8
	// Line 1487, Address: 0x2b0aec, Func Offset: 0xfc
	// Line 1488, Address: 0x2b0af0, Func Offset: 0x100
	// Line 1484, Address: 0x2b0af4, Func Offset: 0x104
	// Line 1487, Address: 0x2b0af8, Func Offset: 0x108
	// Line 1488, Address: 0x2b0b04, Func Offset: 0x114
	// Line 1489, Address: 0x2b0b10, Func Offset: 0x120
	// Line 1494, Address: 0x2b0b1c, Func Offset: 0x12c
	// Line 1495, Address: 0x2b0b34, Func Offset: 0x144
	// Line 1496, Address: 0x2b0b44, Func Offset: 0x154
	// Line 1497, Address: 0x2b0b48, Func Offset: 0x158
	// Line 1498, Address: 0x2b0b50, Func Offset: 0x160
	// Line 1499, Address: 0x2b0b58, Func Offset: 0x168
	// Line 1512, Address: 0x2b0b68, Func Offset: 0x178
	// Line 1514, Address: 0x2b0b6c, Func Offset: 0x17c
	// Line 1517, Address: 0x2b0b80, Func Offset: 0x190
	// Line 1518, Address: 0x2b0bb0, Func Offset: 0x1c0
	// Line 1526, Address: 0x2b0bbc, Func Offset: 0x1cc
	// Line 1521, Address: 0x2b0bc0, Func Offset: 0x1d0
	// Line 1518, Address: 0x2b0bc4, Func Offset: 0x1d4
	// Line 1526, Address: 0x2b0bcc, Func Offset: 0x1dc
	// Line 1520, Address: 0x2b0bd0, Func Offset: 0x1e0
	// Line 1521, Address: 0x2b0bd8, Func Offset: 0x1e8
	// Line 1522, Address: 0x2b0be0, Func Offset: 0x1f0
	// Line 1523, Address: 0x2b0be8, Func Offset: 0x1f8
	// Line 1524, Address: 0x2b0bf0, Func Offset: 0x200
	// Line 1525, Address: 0x2b0bf8, Func Offset: 0x208
	// Line 1526, Address: 0x2b0c00, Func Offset: 0x210
	// Line 1530, Address: 0x2b0c08, Func Offset: 0x218
	// Func End, Address: 0x2b0c20, Func Offset: 0x230
}

// 
// Start address: 0x2b0c20
void DoorProc3(_door_wrk* dwP)
{
	_anon10* dpP;
	npobj* objP;
	npobj* obP;
	npobj* oaP;
	int flp_n;
	int flp_d;
	// Line 1541, Address: 0x2b0c20, Func Offset: 0
	// Line 1549, Address: 0x2b0c3c, Func Offset: 0x1c
	// Line 1545, Address: 0x2b0c40, Func Offset: 0x20
	// Line 1546, Address: 0x2b0c44, Func Offset: 0x24
	// Line 1549, Address: 0x2b0c48, Func Offset: 0x28
	// Line 1550, Address: 0x2b0c64, Func Offset: 0x44
	// Line 1552, Address: 0x2b0c70, Func Offset: 0x50
	// Line 1555, Address: 0x2b0c9c, Func Offset: 0x7c
	// Line 1556, Address: 0x2b0ca4, Func Offset: 0x84
	// Line 1558, Address: 0x2b0cac, Func Offset: 0x8c
	// Line 1562, Address: 0x2b0cb8, Func Offset: 0x98
	// Line 1565, Address: 0x2b0cc8, Func Offset: 0xa8
	// Line 1570, Address: 0x2b0ccc, Func Offset: 0xac
	// Line 1565, Address: 0x2b0cd0, Func Offset: 0xb0
	// Line 1566, Address: 0x2b0cd8, Func Offset: 0xb8
	// Line 1567, Address: 0x2b0ce4, Func Offset: 0xc4
	// Line 1568, Address: 0x2b0cec, Func Offset: 0xcc
	// Line 1570, Address: 0x2b0cf4, Func Offset: 0xd4
	// Line 1571, Address: 0x2b0d00, Func Offset: 0xe0
	// Line 1576, Address: 0x2b0d0c, Func Offset: 0xec
	// Line 1577, Address: 0x2b0d2c, Func Offset: 0x10c
	// Line 1578, Address: 0x2b0d3c, Func Offset: 0x11c
	// Line 1581, Address: 0x2b0d50, Func Offset: 0x130
	// Line 1582, Address: 0x2b0d6c, Func Offset: 0x14c
	// Line 1584, Address: 0x2b0d74, Func Offset: 0x154
	// Line 1585, Address: 0x2b0d7c, Func Offset: 0x15c
	// Line 1590, Address: 0x2b0d88, Func Offset: 0x168
	// Line 1592, Address: 0x2b0d98, Func Offset: 0x178
	// Line 1593, Address: 0x2b0da4, Func Offset: 0x184
	// Line 1594, Address: 0x2b0dac, Func Offset: 0x18c
	// Line 1595, Address: 0x2b0db4, Func Offset: 0x194
	// Line 1601, Address: 0x2b0dc0, Func Offset: 0x1a0
	// Line 1602, Address: 0x2b0dd0, Func Offset: 0x1b0
	// Line 1603, Address: 0x2b0dd8, Func Offset: 0x1b8
	// Line 1602, Address: 0x2b0ddc, Func Offset: 0x1bc
	// Line 1603, Address: 0x2b0de4, Func Offset: 0x1c4
	// Line 1606, Address: 0x2b0df0, Func Offset: 0x1d0
	// Line 1607, Address: 0x2b0e08, Func Offset: 0x1e8
	// Line 1608, Address: 0x2b0e1c, Func Offset: 0x1fc
	// Line 1610, Address: 0x2b0e24, Func Offset: 0x204
	// Line 1608, Address: 0x2b0e28, Func Offset: 0x208
	// Line 1610, Address: 0x2b0e30, Func Offset: 0x210
	// Line 1611, Address: 0x2b0e3c, Func Offset: 0x21c
	// Line 1613, Address: 0x2b0e50, Func Offset: 0x230
	// Line 1614, Address: 0x2b0e58, Func Offset: 0x238
	// Line 1615, Address: 0x2b0e68, Func Offset: 0x248
	// Line 1625, Address: 0x2b0e74, Func Offset: 0x254
	// Line 1626, Address: 0x2b0e84, Func Offset: 0x264
	// Line 1627, Address: 0x2b0e90, Func Offset: 0x270
	// Line 1628, Address: 0x2b0e98, Func Offset: 0x278
	// Line 1629, Address: 0x2b0ea4, Func Offset: 0x284
	// Line 1630, Address: 0x2b0eac, Func Offset: 0x28c
	// Line 1633, Address: 0x2b0eb8, Func Offset: 0x298
	// Func End, Address: 0x2b0ed8, Func Offset: 0x2b8
}

// 
// Start address: 0x2b0ee0
void DoorProc4(_door_wrk* dwP)
{
	_anon6* prmP;
	_anon6* dpP;
	npobj* objP;
	// Line 1647, Address: 0x2b0ee0, Func Offset: 0
	// Line 1653, Address: 0x2b0ef4, Func Offset: 0x14
	// Line 1651, Address: 0x2b0ef8, Func Offset: 0x18
	// Line 1648, Address: 0x2b0efc, Func Offset: 0x1c
	// Line 1653, Address: 0x2b0f04, Func Offset: 0x24
	// Line 1655, Address: 0x2b0f14, Func Offset: 0x34
	// Line 1658, Address: 0x2b0f4c, Func Offset: 0x6c
	// Line 1666, Address: 0x2b0f50, Func Offset: 0x70
	// Line 1658, Address: 0x2b0f54, Func Offset: 0x74
	// Line 1659, Address: 0x2b0f58, Func Offset: 0x78
	// Line 1660, Address: 0x2b0f60, Func Offset: 0x80
	// Line 1661, Address: 0x2b0f68, Func Offset: 0x88
	// Line 1662, Address: 0x2b0f70, Func Offset: 0x90
	// Line 1664, Address: 0x2b0f78, Func Offset: 0x98
	// Line 1666, Address: 0x2b0f80, Func Offset: 0xa0
	// Line 1674, Address: 0x2b0f8c, Func Offset: 0xac
	// Line 1676, Address: 0x2b0f98, Func Offset: 0xb8
	// Line 1680, Address: 0x2b0fa4, Func Offset: 0xc4
	// Line 1681, Address: 0x2b0fb4, Func Offset: 0xd4
	// Line 1682, Address: 0x2b0fc4, Func Offset: 0xe4
	// Line 1684, Address: 0x2b0fe8, Func Offset: 0x108
	// Line 1686, Address: 0x2b1004, Func Offset: 0x124
	// Line 1687, Address: 0x2b100c, Func Offset: 0x12c
	// Line 1688, Address: 0x2b1014, Func Offset: 0x134
	// Line 1690, Address: 0x2b101c, Func Offset: 0x13c
	// Line 1693, Address: 0x2b1024, Func Offset: 0x144
	// Line 1694, Address: 0x2b1034, Func Offset: 0x154
	// Line 1698, Address: 0x2b1040, Func Offset: 0x160
	// Line 1699, Address: 0x2b1058, Func Offset: 0x178
	// Line 1700, Address: 0x2b106c, Func Offset: 0x18c
	// Line 1705, Address: 0x2b107c, Func Offset: 0x19c
	// Func End, Address: 0x2b1094, Func Offset: 0x1b4
}

// 
// Start address: 0x2b10a0
void DoorProc5(_door_wrk* dwP)
{
	_anon30* dpP;
	npobj* objP;
	// Line 1716, Address: 0x2b10a0, Func Offset: 0
	// Line 1723, Address: 0x2b10b4, Func Offset: 0x14
	// Line 1717, Address: 0x2b10b8, Func Offset: 0x18
	// Line 1720, Address: 0x2b10bc, Func Offset: 0x1c
	// Line 1723, Address: 0x2b10c0, Func Offset: 0x20
	// Line 1726, Address: 0x2b10e8, Func Offset: 0x48
	// Line 1727, Address: 0x2b10f0, Func Offset: 0x50
	// Line 1728, Address: 0x2b10f8, Func Offset: 0x58
	// Line 1732, Address: 0x2b1104, Func Offset: 0x64
	// Line 1735, Address: 0x2b1114, Func Offset: 0x74
	// Line 1737, Address: 0x2b1118, Func Offset: 0x78
	// Line 1742, Address: 0x2b111c, Func Offset: 0x7c
	// Line 1737, Address: 0x2b1120, Func Offset: 0x80
	// Line 1738, Address: 0x2b1124, Func Offset: 0x84
	// Line 1739, Address: 0x2b112c, Func Offset: 0x8c
	// Line 1742, Address: 0x2b1138, Func Offset: 0x98
	// Line 1747, Address: 0x2b1144, Func Offset: 0xa4
	// Line 1748, Address: 0x2b115c, Func Offset: 0xbc
	// Line 1749, Address: 0x2b116c, Func Offset: 0xcc
	// Line 1752, Address: 0x2b117c, Func Offset: 0xdc
	// Line 1754, Address: 0x2b119c, Func Offset: 0xfc
	// Line 1755, Address: 0x2b11a8, Func Offset: 0x108
	// Line 1757, Address: 0x2b11b0, Func Offset: 0x110
	// Line 1761, Address: 0x2b11bc, Func Offset: 0x11c
	// Line 1764, Address: 0x2b11cc, Func Offset: 0x12c
	// Line 1768, Address: 0x2b11d0, Func Offset: 0x130
	// Line 1764, Address: 0x2b11d4, Func Offset: 0x134
	// Line 1765, Address: 0x2b11d8, Func Offset: 0x138
	// Line 1768, Address: 0x2b11e4, Func Offset: 0x144
	// Line 1773, Address: 0x2b11f0, Func Offset: 0x150
	// Line 1774, Address: 0x2b1208, Func Offset: 0x168
	// Line 1775, Address: 0x2b1218, Func Offset: 0x178
	// Line 1776, Address: 0x2b1224, Func Offset: 0x184
	// Line 1777, Address: 0x2b122c, Func Offset: 0x18c
	// Line 1778, Address: 0x2b123c, Func Offset: 0x19c
	// Line 1781, Address: 0x2b124c, Func Offset: 0x1ac
	// Line 1782, Address: 0x2b1264, Func Offset: 0x1c4
	// Line 1786, Address: 0x2b126c, Func Offset: 0x1cc
	// Line 1782, Address: 0x2b1270, Func Offset: 0x1d0
	// Line 1783, Address: 0x2b1278, Func Offset: 0x1d8
	// Line 1786, Address: 0x2b1284, Func Offset: 0x1e4
	// Line 1796, Address: 0x2b1290, Func Offset: 0x1f0
	// Func End, Address: 0x2b12a8, Func Offset: 0x208
}

// 
// Start address: 0x2b12b0
void DoorProc6(_door_wrk* dwP)
{
	npobj* objP;
	// Line 1812, Address: 0x2b12b0, Func Offset: 0
	// Line 1816, Address: 0x2b12d0, Func Offset: 0x20
	// Line 1817, Address: 0x2b12f0, Func Offset: 0x40
	// Line 1819, Address: 0x2b12fc, Func Offset: 0x4c
	// Line 1826, Address: 0x2b1308, Func Offset: 0x58
	// Func End, Address: 0x2b1310, Func Offset: 0x60
}

// 
// Start address: 0x2b1310
void DoorProc7(_door_wrk* dwP)
{
	_anon51* dpP;
	npobj* objP;
	npobj* obP;
	npobj* oaP;
	int nob;
	int flp_n;
	int flp_d;
	// Line 1839, Address: 0x2b1310, Func Offset: 0
	// Line 1844, Address: 0x2b1338, Func Offset: 0x28
	// Line 1845, Address: 0x2b133c, Func Offset: 0x2c
	// Line 1849, Address: 0x2b1344, Func Offset: 0x34
	// Line 1851, Address: 0x2b1358, Func Offset: 0x48
	// Line 1852, Address: 0x2b136c, Func Offset: 0x5c
	// Line 1854, Address: 0x2b1374, Func Offset: 0x64
	// Line 1855, Address: 0x2b138c, Func Offset: 0x7c
	// Line 1857, Address: 0x2b1394, Func Offset: 0x84
	// Line 1860, Address: 0x2b13c0, Func Offset: 0xb0
	// Line 1861, Address: 0x2b13c8, Func Offset: 0xb8
	// Line 1865, Address: 0x2b13d4, Func Offset: 0xc4
	// Line 1868, Address: 0x2b13e4, Func Offset: 0xd4
	// Line 1869, Address: 0x2b1408, Func Offset: 0xf8
	// Line 1875, Address: 0x2b140c, Func Offset: 0xfc
	// Line 1869, Address: 0x2b1410, Func Offset: 0x100
	// Line 1870, Address: 0x2b1418, Func Offset: 0x108
	// Line 1871, Address: 0x2b1420, Func Offset: 0x110
	// Line 1873, Address: 0x2b1428, Func Offset: 0x118
	// Line 1875, Address: 0x2b1430, Func Offset: 0x120
	// Line 1876, Address: 0x2b143c, Func Offset: 0x12c
	// Line 1881, Address: 0x2b1448, Func Offset: 0x138
	// Line 1882, Address: 0x2b1484, Func Offset: 0x174
	// Line 1883, Address: 0x2b1494, Func Offset: 0x184
	// Line 1886, Address: 0x2b14a8, Func Offset: 0x198
	// Line 1887, Address: 0x2b14c4, Func Offset: 0x1b4
	// Line 1889, Address: 0x2b14cc, Func Offset: 0x1bc
	// Line 1893, Address: 0x2b14d8, Func Offset: 0x1c8
	// Line 1897, Address: 0x2b14e8, Func Offset: 0x1d8
	// Line 1899, Address: 0x2b14f4, Func Offset: 0x1e4
	// Line 1900, Address: 0x2b1500, Func Offset: 0x1f0
	// Line 1901, Address: 0x2b1508, Func Offset: 0x1f8
	// Line 1906, Address: 0x2b1514, Func Offset: 0x204
	// Line 1907, Address: 0x2b1534, Func Offset: 0x224
	// Line 1908, Address: 0x2b1544, Func Offset: 0x234
	// Line 1912, Address: 0x2b1558, Func Offset: 0x248
	// Line 1914, Address: 0x2b1578, Func Offset: 0x268
	// Line 1916, Address: 0x2b1598, Func Offset: 0x288
	// Line 1917, Address: 0x2b15a4, Func Offset: 0x294
	// Line 1919, Address: 0x2b15ac, Func Offset: 0x29c
	// Line 1923, Address: 0x2b15b8, Func Offset: 0x2a8
	// Line 1926, Address: 0x2b15c8, Func Offset: 0x2b8
	// Line 1927, Address: 0x2b15d4, Func Offset: 0x2c4
	// Line 1932, Address: 0x2b15e0, Func Offset: 0x2d0
	// Line 1933, Address: 0x2b1600, Func Offset: 0x2f0
	// Line 1934, Address: 0x2b1610, Func Offset: 0x300
	// Line 1935, Address: 0x2b1620, Func Offset: 0x310
	// Line 1936, Address: 0x2b1628, Func Offset: 0x318
	// Line 1937, Address: 0x2b163c, Func Offset: 0x32c
	// Line 1940, Address: 0x2b164c, Func Offset: 0x33c
	// Line 1941, Address: 0x2b1668, Func Offset: 0x358
	// Line 1942, Address: 0x2b1678, Func Offset: 0x368
	// Line 1951, Address: 0x2b1684, Func Offset: 0x374
	// Line 1952, Address: 0x2b1694, Func Offset: 0x384
	// Line 1953, Address: 0x2b1698, Func Offset: 0x388
	// Line 1952, Address: 0x2b16a8, Func Offset: 0x398
	// Line 1953, Address: 0x2b16b0, Func Offset: 0x3a0
	// Line 1956, Address: 0x2b16c8, Func Offset: 0x3b8
	// Func End, Address: 0x2b16f4, Func Offset: 0x3e4
}*/

// 100% matching!
static void LightProc1(_door_wrk* dwP) 
{
    LIGHTPROC_WORK* lpP; 
    int lgt_no;        
    
    lpP = dwP->lpP;
    
    switch (dwP->lgt_mode) 
    {                            
    case 0:
        LightSubAmb(dwP, (NJS_POINT3*)&lpP->amb_r, &dwP->lgt_amb_off);
        
        dwP->lgt_mode++;
    case 1:
        for (lgt_no = 0; lgt_no < lpP->lgt_num; lgt_no++) 
        {
            LightSubPnt(dwP, lgt_no, &lpP->lgt_dat[lgt_no], &dwP->lgt_pnt_rte);
        }
        
        break;
    }
}

// 100% matching!
static void LightProc2(_door_wrk* dwP)
{
	LIGHTPROC_WORK* lpP; 
    int lgt_no;        
    
    lpP = dwP->lpP;

	if ((dwP->status & 0x4000)) 
	{
		lpP++;	
	}
    
    switch (dwP->lgt_mode) 
    {                            
    case 0:
        LightSubAmb(dwP, (NJS_POINT3*)&lpP->amb_r, &dwP->lgt_amb_off);
        
        dwP->lgt_mode++;
    case 1:
        for (lgt_no = 0; lgt_no < lpP->lgt_num; lgt_no++) 
        {
            LightSubPnt(dwP, lgt_no, &lpP->lgt_dat[lgt_no], &dwP->lgt_pnt_rte);
        }
        
        break;
    }
}

// 100% matching!
static int CompareSint32(int val_a, int cmp_typ, int val_b)
{
    int ret; // not from the debugging symbols

    // the statement below is just to get rid of the warning
    if (0) 
    {
        ret = 0;
    }
    
    switch (cmp_typ) 
    {                                
    case -1:
        return (val_a >= val_b) ? 1 : 0;
    case 0:
        return (val_a == val_b) ? 1 : 0;
    case 1:
        return (val_a <= val_b) ? 1 : 0;
    case -2:
    case 2:
        return (val_a != val_b) ? 1 : 0;
    }
    
    return ret;
}

/* 97.56% matching - with this same code, this function matches 100% on Dreamcast but for some reason not here. However, compiling 
   this function with a different version of MWCC (2.3 as opposed to 2.3.3) does match, which might indicate that the project is
   using the wrong compiler? */ 
static int CompareFloat(float val_a, int cmp_typ, float val_b)
{
    switch (cmp_typ) 
    {                                
    case -1:
        if (val_a >= val_b) 
        {
            return 1;
        } 
        else 
        {
            return 0;
        }
        
        break;
    case 0:
        if (val_a == val_b) 
        {
            return 1;
        }
        else 
        {
            return 0;
        }
        
        break;
    case 1:
        if (val_a <= val_b)
        {
            return 1;
        } 
        else 
        {
            return 0;
        }
        
        break;
    case -2:
    case 2:
        if (val_a != val_b)
        {
            return 1;
        } 
        else 
        {
            return 0;
        }
        
        break;
    }
}

// 100% matching! 
static void VectorMove(NJS_POINT3* posP, int yaw, int pitch, float speed)
{
    njUnitMatrix(lcmat);
    
	*(NJS_POINT3*)&lcmat[0][12] = *posP;
    
    njRotateY(lcmat, yaw);
    njRotateX(lcmat, pitch);
    
    njTranslate(lcmat, 0, 0, -speed);
    
	*posP = *(NJS_POINT3*)&lcmat[0][12];
}

// 100% matching!
static void LightSubAmb(_door_wrk* dwP, NJS_POINT3* ambP, NJS_POINT3* offP) // first parameter is not present on DWARF
{
    NJS_POINT3 amb;

    amb = *ambP;
    
    if (offP != NULL) 
    {
        njAddVector(&amb, offP);
        
        if (amb.x > 0.4f) 
        {
            amb.x = 0.4f;
        }
        
        if (amb.y > 0.4f) 
        {
            amb.y = 0.4f; 
        }
        
        if (amb.z > 0.4f) 
        {
            amb.z = 0.4f;
        }
    }
    
    njCnkSetEasyMultiAmbient(amb.x, amb.y, amb.z);
}

// 100% matching!
static void LightSubPnt(_door_wrk* dwP, int lgt_no, LGT_WRK* ldP, NJS_POINT3* rteP)
{
    NJS_VECTOR vct;

    vct = ldP->pos;
    
    if (ldP->lgt_mod != 0) 
    {
        njAddVector(&vct, &dwP->vew_pos);
    }
    
    njCnkSetEasyMultiLightPoint(lgt_no + 2, vct.x, vct.y, vct.z);
    njCnkSetEasyMultiLightColor(lgt_no + 2, ldP->col_r * rteP->x, ldP->col_g * rteP->y, ldP->col_b * rteP->z);
    njCnkSetEasyMultiLightRange(lgt_no + 2, ldP->n_rang, ldP->f_rang);
    njCnkSetEasyMultiLightSwitch(lgt_no + 2, 1);
}

/*// 
// Start address: 0x2b1c20
void ryExcuteFade(float pri, int col, float rate)
{
	unsigned int tmp;
	int pal;
	_anon47 p2c;
	_anon24 col_buf[4];
	// Line 2148, Address: 0x2b1c20, Func Offset: 0
	// Line 2161, Address: 0x2b1c34, Func Offset: 0x14
	// Line 2148, Address: 0x2b1c3c, Func Offset: 0x1c
	// Line 2161, Address: 0x2b1c40, Func Offset: 0x20
	// Line 2162, Address: 0x2b1c54, Func Offset: 0x34
	// Line 2165, Address: 0x2b1c64, Func Offset: 0x44
	// Line 2162, Address: 0x2b1c68, Func Offset: 0x48
	// Line 2165, Address: 0x2b1c6c, Func Offset: 0x4c
	// Line 2167, Address: 0x2b1c74, Func Offset: 0x54
	// Line 2166, Address: 0x2b1c78, Func Offset: 0x58
	// Line 2167, Address: 0x2b1c7c, Func Offset: 0x5c
	// Line 2168, Address: 0x2b1c88, Func Offset: 0x68
	// Line 2171, Address: 0x2b1c98, Func Offset: 0x78
	// Line 2173, Address: 0x2b1ca4, Func Offset: 0x84
	// Line 2174, Address: 0x2b1cb0, Func Offset: 0x90
	// Line 2176, Address: 0x2b1cbc, Func Offset: 0x9c
	// Line 2177, Address: 0x2b1cdc, Func Offset: 0xbc
	// Line 2179, Address: 0x2b1cf8, Func Offset: 0xd8
	// Func End, Address: 0x2b1d14, Func Offset: 0xf4
}*/

// 100% matching!
static void PuruProc1(_door_wrk* dwP) 
{
    PURUPROC_WORK* ppP; 
    
    ppP = dwP->ppP;
    
    switch (dwP->pru_mode) 
    {                           
    case 0:
        dwP->pru_reg = ppP->wait_time;
        dwP->pru_tim = ppP->loop_time;
        
        dwP->pru_mode++;
    case 1:
        if (dwP->pru_reg == 0) 
        {
            dwP->pru_mode++;
        }
        else 
        {
            dwP->pru_reg--;
            break;
        }
    case 2:
        if (dwP->pru_tim != 0)
        {
            dwP->pru_tim--;
            
            if (dwP->pru_reg == 0) 
            {
                dwP->pru_reg = ppP->pru_wait;
                
                CallSystemSe(0, PruSndTbl[ppP->snd_no]);
                
                StartVibrationEx(2, ppP->pru_no);
            } 
            else 
            {
                dwP->pru_reg--;
            }
            
            if (dwP->pru_reg == ppP->pru_wait) 
            {
                StartVibrationEx(2, ppP->pru_no);
            }
        }
        
        break;
    }
}

// 100% matching!
static void DokiProcLgt(_door_wrk* dwP) 
{
    NJS_POINT3* rteP, *offP; 
    int ang;        
    
    switch (dwP->dki_mode) 
    {                         
    case 0:
        dwP->dki_mode++;
    case 1:
        ang = dwP->time * 1024;
        
        rteP = &dwP->lgt_pnt_rte;
        offP = &dwP->lgt_amb_off; 
        
        if ((ang & 0x8000)) 
        {
            ang = ~ang + 1;
        }
        
        offP->x = 0.5f;
        offP->y = 0.5f;
        offP->z = 0.5f;
        
        rteP->x = 0.5 + njSin(ang); // very likely a mistake
        rteP->y = 0.5f;
        rteP->z = 0.5f;
        break;
    }
}
