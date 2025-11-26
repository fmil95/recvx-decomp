#include "ps2_SaveScreen.h"

/*char cIconSys[9];
char cBioCvIco[11];
char cSysData[13];
char cSaveData00[12];
char cSaveData01[12];
char cSaveData02[12];
char cSaveData03[12];
char cSaveData04[12];
char cSaveData05[12];
char cSaveData06[12];
char cSaveData07[12];
char cSaveData08[12];
char cSaveData09[12];
char cSaveData10[12];
char cSaveData11[12];
char cSaveData12[12];
char cSaveData13[12];
char cSaveData14[12];
char* cpNameList[18];
tagSELECTFILEWINDOW SelectFileWindow;
tagSELECTFILEINFO SelectFileInfo[15];
tagICONINFORMATION IconInfo;
tagMEMORYCARDSTATE McState;
tagSAVEFILE SaveFile;
tagCONFIGFILE ConfigFile;
_anon11* sys;*/

// 
// Start address: 0x26e8a0
SAVE_SCREEN* CreateSaveScreen(SAVE_SCREEN* pSave, void* vpWorkPtrSys)
{
	// Line 110, Address: 0x26e8a0, Func Offset: 0
	// Line 111, Address: 0x26e8b0, Func Offset: 0x10
	// Line 112, Address: 0x26e8b4, Func Offset: 0x14
	// Line 113, Address: 0x26e8b8, Func Offset: 0x18
	// Line 114, Address: 0x26e8bc, Func Offset: 0x1c
	// Line 115, Address: 0x26e8c0, Func Offset: 0x20
	// Line 116, Address: 0x26e8c4, Func Offset: 0x24
	// Line 117, Address: 0x26e8c8, Func Offset: 0x28
	// Line 118, Address: 0x26e8cc, Func Offset: 0x2c
	// Line 119, Address: 0x26e8d0, Func Offset: 0x30
	// Line 120, Address: 0x26e8d4, Func Offset: 0x34
	// Line 121, Address: 0x26e8d8, Func Offset: 0x38
	// Line 122, Address: 0x26e8dc, Func Offset: 0x3c
	// Line 123, Address: 0x26e8e0, Func Offset: 0x40
	// Line 124, Address: 0x26e8e8, Func Offset: 0x48
	// Line 125, Address: 0x26e8fc, Func Offset: 0x5c
	// Line 126, Address: 0x26e90c, Func Offset: 0x6c
	// Line 127, Address: 0x26e91c, Func Offset: 0x7c
	// Line 128, Address: 0x26e938, Func Offset: 0x98
	// Line 129, Address: 0x26e948, Func Offset: 0xa8
	// Line 130, Address: 0x26e960, Func Offset: 0xc0
	// Line 133, Address: 0x26e964, Func Offset: 0xc4
	// Line 135, Address: 0x26e96c, Func Offset: 0xcc
	// Line 136, Address: 0x26e970, Func Offset: 0xd0
	// Func End, Address: 0x26e984, Func Offset: 0xe4
	scePrintf("CreateSaveScreen - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x26e990
void DispMessageSelect(char cSelectMes)
{
	// Line 256, Address: 0x26e990, Func Offset: 0
	// Line 151, Address: 0x26e99c, Func Offset: 0xc
	// Line 256, Address: 0x26e9a0, Func Offset: 0x10
	// Line 151, Address: 0x26e9a4, Func Offset: 0x14
	// Line 256, Address: 0x26e9a8, Func Offset: 0x18
	// Line 151, Address: 0x26e9ac, Func Offset: 0x1c
	// Line 256, Address: 0x26e9b0, Func Offset: 0x20
	// Line 258, Address: 0x26e9bc, Func Offset: 0x2c
	// Line 262, Address: 0x26e9ec, Func Offset: 0x5c
	// Line 263, Address: 0x26e9f4, Func Offset: 0x64
	// Line 267, Address: 0x26e9fc, Func Offset: 0x6c
	// Line 269, Address: 0x26ea2c, Func Offset: 0x9c
	// Line 270, Address: 0x26ea34, Func Offset: 0xa4
	// Line 273, Address: 0x26ea3c, Func Offset: 0xac
	// Line 274, Address: 0x26ea6c, Func Offset: 0xdc
	// Line 277, Address: 0x26ea74, Func Offset: 0xe4
	// Line 278, Address: 0x26eaa4, Func Offset: 0x114
	// Line 281, Address: 0x26eaac, Func Offset: 0x11c
	// Line 282, Address: 0x26eadc, Func Offset: 0x14c
	// Line 283, Address: 0x26eb0c, Func Offset: 0x17c
	// Line 286, Address: 0x26eb14, Func Offset: 0x184
	// Line 287, Address: 0x26eb44, Func Offset: 0x1b4
	// Line 290, Address: 0x26eb4c, Func Offset: 0x1bc
	// Line 291, Address: 0x26eb7c, Func Offset: 0x1ec
	// Line 294, Address: 0x26eb84, Func Offset: 0x1f4
	// Line 295, Address: 0x26ebb8, Func Offset: 0x228
	// Line 296, Address: 0x26ebe8, Func Offset: 0x258
	// Line 299, Address: 0x26ebf0, Func Offset: 0x260
	// Line 300, Address: 0x26ec20, Func Offset: 0x290
	// Line 303, Address: 0x26ec28, Func Offset: 0x298
	// Line 304, Address: 0x26ec5c, Func Offset: 0x2cc
	// Line 305, Address: 0x26ec8c, Func Offset: 0x2fc
	// Line 308, Address: 0x26ec94, Func Offset: 0x304
	// Line 309, Address: 0x26ecc8, Func Offset: 0x338
	// Line 310, Address: 0x26ecf8, Func Offset: 0x368
	// Line 313, Address: 0x26ed00, Func Offset: 0x370
	// Line 314, Address: 0x26ed34, Func Offset: 0x3a4
	// Line 317, Address: 0x26ed3c, Func Offset: 0x3ac
	// Line 318, Address: 0x26ed70, Func Offset: 0x3e0
	// Line 321, Address: 0x26ed78, Func Offset: 0x3e8
	// Line 322, Address: 0x26eda8, Func Offset: 0x418
	// Line 325, Address: 0x26edb0, Func Offset: 0x420
	// Line 326, Address: 0x26ede0, Func Offset: 0x450
	// Line 327, Address: 0x26ee10, Func Offset: 0x480
	// Line 330, Address: 0x26ee18, Func Offset: 0x488
	// Line 331, Address: 0x26ee48, Func Offset: 0x4b8
	// Line 334, Address: 0x26ee50, Func Offset: 0x4c0
	// Line 335, Address: 0x26ee80, Func Offset: 0x4f0
	// Line 336, Address: 0x26eeb0, Func Offset: 0x520
	// Line 339, Address: 0x26eeb8, Func Offset: 0x528
	// Line 340, Address: 0x26eee8, Func Offset: 0x558
	// Line 343, Address: 0x26eef0, Func Offset: 0x560
	// Line 344, Address: 0x26ef20, Func Offset: 0x590
	// Line 347, Address: 0x26ef28, Func Offset: 0x598
	// Line 354, Address: 0x26ef58, Func Offset: 0x5c8
	// Line 356, Address: 0x26ef70, Func Offset: 0x5e0
	// Func End, Address: 0x26ef80, Func Offset: 0x5f0
}

// 
// Start address: 0x26ef80
void DispTexture(tagSAVE_SCREEN* pSave)
{
	int DispSavePortCard;
	// Line 371, Address: 0x26ef80, Func Offset: 0
	// Line 413, Address: 0x26ef8c, Func Offset: 0xc
	// Line 416, Address: 0x26efb8, Func Offset: 0x38
	// Line 417, Address: 0x26efc0, Func Offset: 0x40
	// Line 420, Address: 0x26efc8, Func Offset: 0x48
	// Line 421, Address: 0x26efe8, Func Offset: 0x68
	// Line 424, Address: 0x26eff0, Func Offset: 0x70
	// Line 425, Address: 0x26f010, Func Offset: 0x90
	// Line 428, Address: 0x26f018, Func Offset: 0x98
	// Line 429, Address: 0x26f020, Func Offset: 0xa0
	// Line 431, Address: 0x26f03c, Func Offset: 0xbc
	// Line 432, Address: 0x26f05c, Func Offset: 0xdc
	// Line 435, Address: 0x26f064, Func Offset: 0xe4
	// Line 436, Address: 0x26f06c, Func Offset: 0xec
	// Line 437, Address: 0x26f088, Func Offset: 0x108
	// Line 440, Address: 0x26f090, Func Offset: 0x110
	// Line 441, Address: 0x26f0ac, Func Offset: 0x12c
	// Line 444, Address: 0x26f0b4, Func Offset: 0x134
	// Line 451, Address: 0x26f0d0, Func Offset: 0x150
	// Func End, Address: 0x26f0e0, Func Offset: 0x160
}*/

// 
// Start address: 0x26f0e0
int ExecuteSaveScreen(SAVE_SCREEN* pSave)
{
	// Line 498, Address: 0x26f0e0, Func Offset: 0
	// Line 500, Address: 0x26f0f0, Func Offset: 0x10
	// Line 503, Address: 0x26f0f8, Func Offset: 0x18
	// Line 505, Address: 0x26f100, Func Offset: 0x20
	// Line 508, Address: 0x26f240, Func Offset: 0x160
	// Line 509, Address: 0x26f24c, Func Offset: 0x16c
	// Line 511, Address: 0x26f254, Func Offset: 0x174
	// Line 512, Address: 0x26f260, Func Offset: 0x180
	// Line 514, Address: 0x26f268, Func Offset: 0x188
	// Line 515, Address: 0x26f274, Func Offset: 0x194
	// Line 517, Address: 0x26f27c, Func Offset: 0x19c
	// Line 518, Address: 0x26f288, Func Offset: 0x1a8
	// Line 520, Address: 0x26f290, Func Offset: 0x1b0
	// Line 521, Address: 0x26f29c, Func Offset: 0x1bc
	// Line 523, Address: 0x26f2a4, Func Offset: 0x1c4
	// Line 524, Address: 0x26f2b0, Func Offset: 0x1d0
	// Line 526, Address: 0x26f2b8, Func Offset: 0x1d8
	// Line 527, Address: 0x26f2c4, Func Offset: 0x1e4
	// Line 529, Address: 0x26f2cc, Func Offset: 0x1ec
	// Line 530, Address: 0x26f2d8, Func Offset: 0x1f8
	// Line 532, Address: 0x26f2e0, Func Offset: 0x200
	// Line 533, Address: 0x26f2ec, Func Offset: 0x20c
	// Line 535, Address: 0x26f2f4, Func Offset: 0x214
	// Line 536, Address: 0x26f300, Func Offset: 0x220
	// Line 538, Address: 0x26f308, Func Offset: 0x228
	// Line 539, Address: 0x26f314, Func Offset: 0x234
	// Line 541, Address: 0x26f31c, Func Offset: 0x23c
	// Line 542, Address: 0x26f328, Func Offset: 0x248
	// Line 544, Address: 0x26f330, Func Offset: 0x250
	// Line 545, Address: 0x26f33c, Func Offset: 0x25c
	// Line 547, Address: 0x26f344, Func Offset: 0x264
	// Line 548, Address: 0x26f350, Func Offset: 0x270
	// Line 550, Address: 0x26f358, Func Offset: 0x278
	// Line 551, Address: 0x26f364, Func Offset: 0x284
	// Line 553, Address: 0x26f36c, Func Offset: 0x28c
	// Line 554, Address: 0x26f378, Func Offset: 0x298
	// Line 556, Address: 0x26f380, Func Offset: 0x2a0
	// Line 557, Address: 0x26f38c, Func Offset: 0x2ac
	// Line 559, Address: 0x26f394, Func Offset: 0x2b4
	// Line 560, Address: 0x26f3a0, Func Offset: 0x2c0
	// Line 562, Address: 0x26f3a8, Func Offset: 0x2c8
	// Line 563, Address: 0x26f3b4, Func Offset: 0x2d4
	// Line 565, Address: 0x26f3bc, Func Offset: 0x2dc
	// Line 566, Address: 0x26f3c8, Func Offset: 0x2e8
	// Line 568, Address: 0x26f3d0, Func Offset: 0x2f0
	// Line 569, Address: 0x26f3dc, Func Offset: 0x2fc
	// Line 571, Address: 0x26f3e4, Func Offset: 0x304
	// Line 572, Address: 0x26f3f0, Func Offset: 0x310
	// Line 574, Address: 0x26f3f8, Func Offset: 0x318
	// Line 575, Address: 0x26f404, Func Offset: 0x324
	// Line 577, Address: 0x26f40c, Func Offset: 0x32c
	// Line 578, Address: 0x26f418, Func Offset: 0x338
	// Line 580, Address: 0x26f420, Func Offset: 0x340
	// Line 581, Address: 0x26f42c, Func Offset: 0x34c
	// Line 583, Address: 0x26f434, Func Offset: 0x354
	// Line 587, Address: 0x26f440, Func Offset: 0x360
	// Line 589, Address: 0x26f44c, Func Offset: 0x36c
	// Line 592, Address: 0x26f454, Func Offset: 0x374
	// Line 591, Address: 0x26f45c, Func Offset: 0x37c
	// Line 592, Address: 0x26f460, Func Offset: 0x380
	// Func End, Address: 0x26f468, Func Offset: 0x388
	scePrintf("ExecuteSaveScreen - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x26f470
void SetStateSaveScreenAwarenessCard(tagSAVE_SCREEN* pSave)
{
	// Line 609, Address: 0x26f470, Func Offset: 0
	// Line 611, Address: 0x26f474, Func Offset: 0x4
	// Line 613, Address: 0x26f478, Func Offset: 0x8
	// Line 615, Address: 0x26f47c, Func Offset: 0xc
	// Func End, Address: 0x26f488, Func Offset: 0x18
}

// 
// Start address: 0x26f490
void ExecuteStateSaveScreenAwarenessCard(tagSAVE_SCREEN* pSave)
{
	int lPort1State;
	int lPort0State;
	// Line 631, Address: 0x26f490, Func Offset: 0
	// Line 634, Address: 0x26f4a0, Func Offset: 0x10
	// Line 637, Address: 0x26f4dc, Func Offset: 0x4c
	// Line 638, Address: 0x26f4e8, Func Offset: 0x58
	// Line 640, Address: 0x26f4f8, Func Offset: 0x68
	// Line 643, Address: 0x26f50c, Func Offset: 0x7c
	// Line 644, Address: 0x26f518, Func Offset: 0x88
	// Line 646, Address: 0x26f520, Func Offset: 0x90
	// Line 650, Address: 0x26f544, Func Offset: 0xb4
	// Line 651, Address: 0x26f550, Func Offset: 0xc0
	// Line 656, Address: 0x26f558, Func Offset: 0xc8
	// Line 658, Address: 0x26f564, Func Offset: 0xd4
	// Line 661, Address: 0x26f56c, Func Offset: 0xdc
	// Line 662, Address: 0x26f574, Func Offset: 0xe4
	// Line 665, Address: 0x26f57c, Func Offset: 0xec
	// Line 666, Address: 0x26f584, Func Offset: 0xf4
	// Line 669, Address: 0x26f58c, Func Offset: 0xfc
	// Line 674, Address: 0x26f594, Func Offset: 0x104
	// Func End, Address: 0x26f5a8, Func Offset: 0x118
}

// 
// Start address: 0x26f5b0
void SetStateSaveScreenErrLostCard(tagSAVE_SCREEN* pSave)
{
	// Line 691, Address: 0x26f5b0, Func Offset: 0
	// Line 693, Address: 0x26f5b8, Func Offset: 0x8
	// Line 696, Address: 0x26f5bc, Func Offset: 0xc
	// Func End, Address: 0x26f5c4, Func Offset: 0x14
}

// 
// Start address: 0x26f5d0
void ExecuteStateSaveScreenErrLostCard(tagSAVE_SCREEN* pSave)
{
	int lPort1State;
	int lPort0State;
	// Line 711, Address: 0x26f5d0, Func Offset: 0
	// Line 715, Address: 0x26f5e0, Func Offset: 0x10
	// Line 718, Address: 0x26f600, Func Offset: 0x30
	// Line 720, Address: 0x26f608, Func Offset: 0x38
	// Line 721, Address: 0x26f614, Func Offset: 0x44
	// Line 725, Address: 0x26f61c, Func Offset: 0x4c
	// Line 728, Address: 0x26f64c, Func Offset: 0x7c
	// Line 729, Address: 0x26f658, Func Offset: 0x88
	// Line 731, Address: 0x26f668, Func Offset: 0x98
	// Line 734, Address: 0x26f67c, Func Offset: 0xac
	// Line 735, Address: 0x26f688, Func Offset: 0xb8
	// Line 737, Address: 0x26f690, Func Offset: 0xc0
	// Line 741, Address: 0x26f6b4, Func Offset: 0xe4
	// Line 743, Address: 0x26f6c0, Func Offset: 0xf0
	// Line 746, Address: 0x26f6c8, Func Offset: 0xf8
	// Line 747, Address: 0x26f6d0, Func Offset: 0x100
	// Line 750, Address: 0x26f6d8, Func Offset: 0x108
	// Line 754, Address: 0x26f6e0, Func Offset: 0x110
	// Func End, Address: 0x26f6f4, Func Offset: 0x124
}

// 
// Start address: 0x26f700
void SetStateSaveScreenErrUnPS2MemCard(tagSAVE_SCREEN* pSave)
{
	// Line 771, Address: 0x26f700, Func Offset: 0
	// Line 773, Address: 0x26f708, Func Offset: 0x8
	// Line 776, Address: 0x26f70c, Func Offset: 0xc
	// Func End, Address: 0x26f714, Func Offset: 0x14
}

// 
// Start address: 0x26f720
void ExecuteStateSaveScreenErrUnPS2MemCard(tagSAVE_SCREEN* pSave)
{
	int lPort1State;
	int lPort0State;
	// Line 791, Address: 0x26f720, Func Offset: 0
	// Line 795, Address: 0x26f730, Func Offset: 0x10
	// Line 798, Address: 0x26f750, Func Offset: 0x30
	// Line 800, Address: 0x26f758, Func Offset: 0x38
	// Line 801, Address: 0x26f764, Func Offset: 0x44
	// Line 805, Address: 0x26f76c, Func Offset: 0x4c
	// Line 808, Address: 0x26f79c, Func Offset: 0x7c
	// Line 809, Address: 0x26f7a8, Func Offset: 0x88
	// Line 811, Address: 0x26f7b8, Func Offset: 0x98
	// Line 814, Address: 0x26f7cc, Func Offset: 0xac
	// Line 815, Address: 0x26f7d8, Func Offset: 0xb8
	// Line 816, Address: 0x26f7e0, Func Offset: 0xc0
	// Line 819, Address: 0x26f7f0, Func Offset: 0xd0
	// Line 821, Address: 0x26f7f8, Func Offset: 0xd8
	// Line 824, Address: 0x26f800, Func Offset: 0xe0
	// Line 825, Address: 0x26f808, Func Offset: 0xe8
	// Line 828, Address: 0x26f810, Func Offset: 0xf0
	// Line 832, Address: 0x26f818, Func Offset: 0xf8
	// Func End, Address: 0x26f82c, Func Offset: 0x10c
}

// 
// Start address: 0x26f830
void SetStateSaveScreenSelectCard(tagSAVE_SCREEN* pSave)
{
	// Line 847, Address: 0x26f830, Func Offset: 0
	// Line 849, Address: 0x26f83c, Func Offset: 0xc
	// Line 851, Address: 0x26f844, Func Offset: 0x14
	// Line 853, Address: 0x26f848, Func Offset: 0x18
	// Line 855, Address: 0x26f84c, Func Offset: 0x1c
	// Line 857, Address: 0x26f854, Func Offset: 0x24
	// Line 859, Address: 0x26f858, Func Offset: 0x28
	// Line 861, Address: 0x26f860, Func Offset: 0x30
	// Line 862, Address: 0x26f86c, Func Offset: 0x3c
	// Func End, Address: 0x26f87c, Func Offset: 0x4c
}

// 
// Start address: 0x26f880
void ExecuteStateSaveScreenSelectCard(tagSAVE_SCREEN* pSave)
{
	// Line 877, Address: 0x26f880, Func Offset: 0
	// Line 879, Address: 0x26f88c, Func Offset: 0xc
	// Line 881, Address: 0x26f8b0, Func Offset: 0x30
	// Line 883, Address: 0x26f8b4, Func Offset: 0x34
	// Line 881, Address: 0x26f8bc, Func Offset: 0x3c
	// Line 883, Address: 0x26f8c0, Func Offset: 0x40
	// Line 884, Address: 0x26f8c8, Func Offset: 0x48
	// Line 885, Address: 0x26f8d0, Func Offset: 0x50
	// Line 887, Address: 0x26f8dc, Func Offset: 0x5c
	// Line 889, Address: 0x26f8e0, Func Offset: 0x60
	// Line 887, Address: 0x26f8e8, Func Offset: 0x68
	// Line 889, Address: 0x26f8ec, Func Offset: 0x6c
	// Line 892, Address: 0x26f8f4, Func Offset: 0x74
	// Line 895, Address: 0x26f900, Func Offset: 0x80
	// Line 898, Address: 0x26f90c, Func Offset: 0x8c
	// Line 902, Address: 0x26f93c, Func Offset: 0xbc
	// Line 904, Address: 0x26f95c, Func Offset: 0xdc
	// Line 906, Address: 0x26f960, Func Offset: 0xe0
	// Line 904, Address: 0x26f964, Func Offset: 0xe4
	// Line 906, Address: 0x26f968, Func Offset: 0xe8
	// Line 907, Address: 0x26f970, Func Offset: 0xf0
	// Line 909, Address: 0x26f978, Func Offset: 0xf8
	// Line 911, Address: 0x26f984, Func Offset: 0x104
	// Line 913, Address: 0x26f988, Func Offset: 0x108
	// Line 911, Address: 0x26f98c, Func Offset: 0x10c
	// Line 913, Address: 0x26f990, Func Offset: 0x110
	// Line 915, Address: 0x26f998, Func Offset: 0x118
	// Line 916, Address: 0x26f9a4, Func Offset: 0x124
	// Line 921, Address: 0x26f9ac, Func Offset: 0x12c
	// Line 924, Address: 0x26f9cc, Func Offset: 0x14c
	// Line 927, Address: 0x26f9dc, Func Offset: 0x15c
	// Line 928, Address: 0x26f9e4, Func Offset: 0x164
	// Line 933, Address: 0x26f9ec, Func Offset: 0x16c
	// Line 936, Address: 0x26f9f8, Func Offset: 0x178
	// Line 937, Address: 0x26fa04, Func Offset: 0x184
	// Line 939, Address: 0x26fa0c, Func Offset: 0x18c
	// Line 942, Address: 0x26fa18, Func Offset: 0x198
	// Line 944, Address: 0x26fa20, Func Offset: 0x1a0
	// Line 945, Address: 0x26fa2c, Func Offset: 0x1ac
	// Line 949, Address: 0x26fa34, Func Offset: 0x1b4
	// Line 952, Address: 0x26fa50, Func Offset: 0x1d0
	// Line 965, Address: 0x26fa58, Func Offset: 0x1d8
	// Func End, Address: 0x26fa68, Func Offset: 0x1e8
}

// 
// Start address: 0x26fa70
void SetStateSaveScreenExit(tagSAVE_SCREEN* pSave)
{
	// Line 982, Address: 0x26fa70, Func Offset: 0
	// Line 984, Address: 0x26fa78, Func Offset: 0x8
	// Line 986, Address: 0x26fa80, Func Offset: 0x10
	// Line 988, Address: 0x26fa84, Func Offset: 0x14
	// Line 990, Address: 0x26fa8c, Func Offset: 0x1c
	// Func End, Address: 0x26fa98, Func Offset: 0x28
}

// 
// Start address: 0x26faa0
void ExecuteStateSaveScreenExit(tagSAVE_SCREEN* pSave)
{
	// Line 1006, Address: 0x26faa0, Func Offset: 0
	// Line 1010, Address: 0x26faac, Func Offset: 0xc
	// Line 1012, Address: 0x26facc, Func Offset: 0x2c
	// Line 1014, Address: 0x26fadc, Func Offset: 0x3c
	// Line 1016, Address: 0x26fae0, Func Offset: 0x40
	// Line 1019, Address: 0x26fae8, Func Offset: 0x48
	// Line 1021, Address: 0x26faf4, Func Offset: 0x54
	// Func End, Address: 0x26fb04, Func Offset: 0x64
}

// 
// Start address: 0x26fb10
void SetSaveScreenSpecialSave(tagSAVE_SCREEN* pSave)
{
	// Line 1038, Address: 0x26fb10, Func Offset: 0
	// Line 1040, Address: 0x26fb18, Func Offset: 0x8
	// Line 1042, Address: 0x26fb20, Func Offset: 0x10
	// Line 1044, Address: 0x26fb28, Func Offset: 0x18
	// Line 1045, Address: 0x26fb2c, Func Offset: 0x1c
	// Func End, Address: 0x26fb34, Func Offset: 0x24
}

// 
// Start address: 0x26fb40
void ExecuteStateSaveScreenSpecialSave(tagSAVE_SCREEN* pSave)
{
	// Line 1060, Address: 0x26fb40, Func Offset: 0
	// Line 1064, Address: 0x26fb48, Func Offset: 0x8
	// Line 1066, Address: 0x26fb68, Func Offset: 0x28
	// Line 1069, Address: 0x26fb6c, Func Offset: 0x2c
	// Line 1066, Address: 0x26fb70, Func Offset: 0x30
	// Line 1067, Address: 0x26fb78, Func Offset: 0x38
	// Line 1069, Address: 0x26fb84, Func Offset: 0x44
	// Line 1070, Address: 0x26fb8c, Func Offset: 0x4c
	// Line 1071, Address: 0x26fb94, Func Offset: 0x54
	// Line 1073, Address: 0x26fba0, Func Offset: 0x60
	// Line 1076, Address: 0x26fba4, Func Offset: 0x64
	// Line 1073, Address: 0x26fba8, Func Offset: 0x68
	// Line 1074, Address: 0x26fbb0, Func Offset: 0x70
	// Line 1076, Address: 0x26fbbc, Func Offset: 0x7c
	// Line 1077, Address: 0x26fbc4, Func Offset: 0x84
	// Line 1079, Address: 0x26fbcc, Func Offset: 0x8c
	// Line 1082, Address: 0x26fbd8, Func Offset: 0x98
	// Line 1085, Address: 0x26fbe8, Func Offset: 0xa8
	// Line 1086, Address: 0x26fbf0, Func Offset: 0xb0
	// Line 1090, Address: 0x26fbf8, Func Offset: 0xb8
	// Line 1093, Address: 0x26fbfc, Func Offset: 0xbc
	// Line 1094, Address: 0x26fc08, Func Offset: 0xc8
	// Line 1096, Address: 0x26fc10, Func Offset: 0xd0
	// Line 1099, Address: 0x26fc1c, Func Offset: 0xdc
	// Line 1101, Address: 0x26fc24, Func Offset: 0xe4
	// Line 1102, Address: 0x26fc30, Func Offset: 0xf0
	// Line 1106, Address: 0x26fc38, Func Offset: 0xf8
	// Line 1109, Address: 0x26fc54, Func Offset: 0x114
	// Line 1112, Address: 0x26fc5c, Func Offset: 0x11c
	// Func End, Address: 0x26fc68, Func Offset: 0x128
}

// 
// Start address: 0x26fc70
void SetStateSaveScreenLostDirCheck(tagSAVE_SCREEN* pSave)
{
	// Line 1127, Address: 0x26fc70, Func Offset: 0
	// Line 1129, Address: 0x26fc7c, Func Offset: 0xc
	// Line 1131, Address: 0x26fc84, Func Offset: 0x14
	// Line 1133, Address: 0x26fc8c, Func Offset: 0x1c
	// Line 1135, Address: 0x26fc94, Func Offset: 0x24
	// Line 1139, Address: 0x26fc98, Func Offset: 0x28
	// Line 1137, Address: 0x26fc9c, Func Offset: 0x2c
	// Line 1139, Address: 0x26fca4, Func Offset: 0x34
	// Line 1141, Address: 0x26fca8, Func Offset: 0x38
	// Line 1143, Address: 0x26fcb4, Func Offset: 0x44
	// Line 1145, Address: 0x26fcc0, Func Offset: 0x50
	// Line 1147, Address: 0x26fccc, Func Offset: 0x5c
	// Func End, Address: 0x26fcdc, Func Offset: 0x6c
}

// 
// Start address: 0x26fce0
void ExecuteStateSaveScreenLostDirCheck(tagSAVE_SCREEN* pSave)
{
	int lResult;
	// Line 1162, Address: 0x26fce0, Func Offset: 0
	// Line 1165, Address: 0x26fcec, Func Offset: 0xc
	// Line 1169, Address: 0x26fd18, Func Offset: 0x38
	// Line 1171, Address: 0x26fd20, Func Offset: 0x40
	// Line 1174, Address: 0x26fd2c, Func Offset: 0x4c
	// Line 1177, Address: 0x26fd3c, Func Offset: 0x5c
	// Line 1178, Address: 0x26fd44, Func Offset: 0x64
	// Line 1182, Address: 0x26fd4c, Func Offset: 0x6c
	// Line 1186, Address: 0x26fd58, Func Offset: 0x78
	// Line 1188, Address: 0x26fd60, Func Offset: 0x80
	// Line 1191, Address: 0x26fd6c, Func Offset: 0x8c
	// Line 1193, Address: 0x26fd78, Func Offset: 0x98
	// Line 1195, Address: 0x26fd80, Func Offset: 0xa0
	// Line 1197, Address: 0x26fd84, Func Offset: 0xa4
	// Line 1200, Address: 0x26fd8c, Func Offset: 0xac
	// Line 1201, Address: 0x26fd94, Func Offset: 0xb4
	// Line 1204, Address: 0x26fda0, Func Offset: 0xc0
	// Line 1205, Address: 0x26fda4, Func Offset: 0xc4
	// Line 1206, Address: 0x26fdac, Func Offset: 0xcc
	// Line 1209, Address: 0x26fdb8, Func Offset: 0xd8
	// Line 1211, Address: 0x26fdc4, Func Offset: 0xe4
	// Line 1213, Address: 0x26fdc8, Func Offset: 0xe8
	// Line 1217, Address: 0x26fdd0, Func Offset: 0xf0
	// Line 1218, Address: 0x26fde4, Func Offset: 0x104
	// Line 1220, Address: 0x26fdec, Func Offset: 0x10c
	// Line 1222, Address: 0x26fdf4, Func Offset: 0x114
	// Line 1224, Address: 0x26fe00, Func Offset: 0x120
	// Line 1225, Address: 0x26fe08, Func Offset: 0x128
	// Line 1226, Address: 0x26fe10, Func Offset: 0x130
	// Line 1229, Address: 0x26fe1c, Func Offset: 0x13c
	// Line 1231, Address: 0x26fe20, Func Offset: 0x140
	// Line 1235, Address: 0x26fe28, Func Offset: 0x148
	// Line 1237, Address: 0x26fe4c, Func Offset: 0x16c
	// Line 1239, Address: 0x26fe50, Func Offset: 0x170
	// Line 1242, Address: 0x26fe58, Func Offset: 0x178
	// Line 1243, Address: 0x26fe68, Func Offset: 0x188
	// Line 1245, Address: 0x26fe74, Func Offset: 0x194
	// Line 1246, Address: 0x26fe84, Func Offset: 0x1a4
	// Line 1249, Address: 0x26fea0, Func Offset: 0x1c0
	// Line 1250, Address: 0x26fea8, Func Offset: 0x1c8
	// Line 1253, Address: 0x26feb0, Func Offset: 0x1d0
	// Line 1255, Address: 0x26feb4, Func Offset: 0x1d4
	// Line 1256, Address: 0x26febc, Func Offset: 0x1dc
	// Line 1259, Address: 0x26fec8, Func Offset: 0x1e8
	// Line 1261, Address: 0x26fed0, Func Offset: 0x1f0
	// Line 1263, Address: 0x26fedc, Func Offset: 0x1fc
	// Line 1265, Address: 0x26fee4, Func Offset: 0x204
	// Line 1268, Address: 0x26feec, Func Offset: 0x20c
	// Line 1271, Address: 0x26fefc, Func Offset: 0x21c
	// Line 1273, Address: 0x26ff04, Func Offset: 0x224
	// Line 1276, Address: 0x26ff0c, Func Offset: 0x22c
	// Line 1279, Address: 0x26ff1c, Func Offset: 0x23c
	// Line 1284, Address: 0x26ff24, Func Offset: 0x244
	// Line 1287, Address: 0x26ff40, Func Offset: 0x260
	// Line 1289, Address: 0x26ff48, Func Offset: 0x268
	// Func End, Address: 0x26ff58, Func Offset: 0x278
}

// 
// Start address: 0x26ff60
void SetStateSaveScreenFreeCapacity(tagSAVE_SCREEN* pSave)
{
	// Line 1306, Address: 0x26ff60, Func Offset: 0
	// Line 1308, Address: 0x26ff68, Func Offset: 0x8
	// Line 1310, Address: 0x26ff70, Func Offset: 0x10
	// Line 1311, Address: 0x26ff74, Func Offset: 0x14
	// Func End, Address: 0x26ff7c, Func Offset: 0x1c
}

// 
// Start address: 0x26ff80
void ExecuteStateSaveScreenFreeCapacity(tagSAVE_SCREEN* pSave)
{
	int lResult;
	// Line 1326, Address: 0x26ff80, Func Offset: 0
	// Line 1329, Address: 0x26ff94, Func Offset: 0x14
	// Line 1331, Address: 0x26ff9c, Func Offset: 0x1c
	// Line 1334, Address: 0x26ffb0, Func Offset: 0x30
	// Line 1337, Address: 0x26ffbc, Func Offset: 0x3c
	// Line 1340, Address: 0x26ffc4, Func Offset: 0x44
	// Line 1347, Address: 0x26ffd0, Func Offset: 0x50
	// Line 1349, Address: 0x26ffd8, Func Offset: 0x58
	// Line 1354, Address: 0x26ffe0, Func Offset: 0x60
	// Line 1356, Address: 0x26ffec, Func Offset: 0x6c
	// Func End, Address: 0x270000, Func Offset: 0x80
}

// 
// Start address: 0x270000
void SetStateSaveScreenErrFreeCapacity(tagSAVE_SCREEN* pSave)
{
	// Line 1373, Address: 0x270000, Func Offset: 0
	// Line 1375, Address: 0x270008, Func Offset: 0x8
	// Line 1377, Address: 0x270010, Func Offset: 0x10
	// Line 1378, Address: 0x270014, Func Offset: 0x14
	// Func End, Address: 0x27001c, Func Offset: 0x1c
}

// 
// Start address: 0x270020
void ExecuteStateSaveScreenErrFreeCapacity(tagSAVE_SCREEN* pSave)
{
	// Line 1393, Address: 0x270020, Func Offset: 0
	// Line 1395, Address: 0x270028, Func Offset: 0x8
	// Line 1398, Address: 0x270048, Func Offset: 0x28
	// Line 1400, Address: 0x270050, Func Offset: 0x30
	// Line 1401, Address: 0x27005c, Func Offset: 0x3c
	// Line 1405, Address: 0x270064, Func Offset: 0x44
	// Line 1408, Address: 0x270080, Func Offset: 0x60
	// Line 1411, Address: 0x270088, Func Offset: 0x68
	// Func End, Address: 0x270094, Func Offset: 0x74
}

// 
// Start address: 0x2700a0
void SetStateSaveScreenCreateSaveFileCheck(tagSAVE_SCREEN* pSave)
{
	// Line 1428, Address: 0x2700a0, Func Offset: 0
	// Line 1430, Address: 0x2700a8, Func Offset: 0x8
	// Line 1432, Address: 0x2700b0, Func Offset: 0x10
	// Line 1435, Address: 0x2700b8, Func Offset: 0x18
	// Func End, Address: 0x2700c0, Func Offset: 0x20
}

// 
// Start address: 0x2700c0
void ExecuteStateSaveScreenCreateSaveFileCheck(tagSAVE_SCREEN* pSave)
{
	// Line 1450, Address: 0x2700c0, Func Offset: 0
	// Line 1454, Address: 0x2700c8, Func Offset: 0x8
	// Line 1456, Address: 0x2700e8, Func Offset: 0x28
	// Line 1459, Address: 0x2700ec, Func Offset: 0x2c
	// Line 1456, Address: 0x2700f0, Func Offset: 0x30
	// Line 1457, Address: 0x2700f8, Func Offset: 0x38
	// Line 1459, Address: 0x270104, Func Offset: 0x44
	// Line 1460, Address: 0x27010c, Func Offset: 0x4c
	// Line 1462, Address: 0x270114, Func Offset: 0x54
	// Line 1464, Address: 0x270120, Func Offset: 0x60
	// Line 1467, Address: 0x270124, Func Offset: 0x64
	// Line 1464, Address: 0x270128, Func Offset: 0x68
	// Line 1465, Address: 0x270130, Func Offset: 0x70
	// Line 1467, Address: 0x27013c, Func Offset: 0x7c
	// Line 1468, Address: 0x270144, Func Offset: 0x84
	// Line 1470, Address: 0x27014c, Func Offset: 0x8c
	// Line 1472, Address: 0x270158, Func Offset: 0x98
	// Line 1475, Address: 0x270168, Func Offset: 0xa8
	// Line 1476, Address: 0x270170, Func Offset: 0xb0
	// Line 1480, Address: 0x270178, Func Offset: 0xb8
	// Line 1483, Address: 0x270180, Func Offset: 0xc0
	// Line 1484, Address: 0x27018c, Func Offset: 0xcc
	// Line 1486, Address: 0x270194, Func Offset: 0xd4
	// Line 1488, Address: 0x2701a0, Func Offset: 0xe0
	// Line 1490, Address: 0x2701a8, Func Offset: 0xe8
	// Line 1491, Address: 0x2701b4, Func Offset: 0xf4
	// Line 1495, Address: 0x2701bc, Func Offset: 0xfc
	// Line 1498, Address: 0x2701d8, Func Offset: 0x118
	// Line 1501, Address: 0x2701e0, Func Offset: 0x120
	// Func End, Address: 0x2701ec, Func Offset: 0x12c
}

// 
// Start address: 0x2701f0
void SetStateSaveScreenCreateSaveFile(tagSAVE_SCREEN* pSave)
{
	// Line 1518, Address: 0x2701f0, Func Offset: 0
	// Line 1520, Address: 0x2701f8, Func Offset: 0x8
	// Line 1524, Address: 0x2701fc, Func Offset: 0xc
	// Line 1522, Address: 0x270200, Func Offset: 0x10
	// Line 1524, Address: 0x270204, Func Offset: 0x14
	// Line 1526, Address: 0x270208, Func Offset: 0x18
	// Line 1528, Address: 0x270210, Func Offset: 0x20
	// Line 1530, Address: 0x270218, Func Offset: 0x28
	// Func End, Address: 0x270224, Func Offset: 0x34
}

// 
// Start address: 0x270230
void ExecuteStateSaveScreenCreateSaveFile(tagSAVE_SCREEN* pSave)
{
	int lResult;
	// Line 1546, Address: 0x270230, Func Offset: 0
	// Line 1549, Address: 0x27023c, Func Offset: 0xc
	// Line 1552, Address: 0x270268, Func Offset: 0x38
	// Line 1554, Address: 0x270270, Func Offset: 0x40
	// Line 1557, Address: 0x27027c, Func Offset: 0x4c
	// Line 1559, Address: 0x270288, Func Offset: 0x58
	// Line 1561, Address: 0x270290, Func Offset: 0x60
	// Line 1562, Address: 0x270294, Func Offset: 0x64
	// Line 1563, Address: 0x27029c, Func Offset: 0x6c
	// Line 1566, Address: 0x2702a8, Func Offset: 0x78
	// Line 1571, Address: 0x2702cc, Func Offset: 0x9c
	// Line 1574, Address: 0x2702d4, Func Offset: 0xa4
	// Line 1575, Address: 0x2702dc, Func Offset: 0xac
	// Line 1577, Address: 0x2702e8, Func Offset: 0xb8
	// Line 1578, Address: 0x2702ec, Func Offset: 0xbc
	// Line 1579, Address: 0x2702f4, Func Offset: 0xc4
	// Line 1582, Address: 0x270300, Func Offset: 0xd0
	// Line 1584, Address: 0x27030c, Func Offset: 0xdc
	// Line 1586, Address: 0x270314, Func Offset: 0xe4
	// Line 1588, Address: 0x270318, Func Offset: 0xe8
	// Line 1592, Address: 0x270320, Func Offset: 0xf0
	// Line 1593, Address: 0x270338, Func Offset: 0x108
	// Line 1596, Address: 0x270344, Func Offset: 0x114
	// Line 1598, Address: 0x270350, Func Offset: 0x120
	// Line 1600, Address: 0x270358, Func Offset: 0x128
	// Line 1601, Address: 0x27035c, Func Offset: 0x12c
	// Line 1605, Address: 0x270364, Func Offset: 0x134
	// Line 1607, Address: 0x270388, Func Offset: 0x158
	// Line 1610, Address: 0x27038c, Func Offset: 0x15c
	// Line 1613, Address: 0x270394, Func Offset: 0x164
	// Line 1614, Address: 0x27039c, Func Offset: 0x16c
	// Line 1617, Address: 0x2703a8, Func Offset: 0x178
	// Line 1619, Address: 0x2703b4, Func Offset: 0x184
	// Line 1621, Address: 0x2703bc, Func Offset: 0x18c
	// Line 1622, Address: 0x2703c0, Func Offset: 0x190
	// Line 1623, Address: 0x2703c8, Func Offset: 0x198
	// Line 1626, Address: 0x2703d4, Func Offset: 0x1a4
	// Line 1628, Address: 0x2703ec, Func Offset: 0x1bc
	// Line 1631, Address: 0x2703f0, Func Offset: 0x1c0
	// Line 1634, Address: 0x2703f8, Func Offset: 0x1c8
	// Line 1635, Address: 0x270400, Func Offset: 0x1d0
	// Line 1637, Address: 0x27040c, Func Offset: 0x1dc
	// Line 1638, Address: 0x270410, Func Offset: 0x1e0
	// Line 1639, Address: 0x270418, Func Offset: 0x1e8
	// Line 1642, Address: 0x270424, Func Offset: 0x1f4
	// Line 1644, Address: 0x270430, Func Offset: 0x200
	// Line 1646, Address: 0x270438, Func Offset: 0x208
	// Line 1648, Address: 0x27043c, Func Offset: 0x20c
	// Line 1652, Address: 0x270444, Func Offset: 0x214
	// Line 1654, Address: 0x270468, Func Offset: 0x238
	// Line 1656, Address: 0x27046c, Func Offset: 0x23c
	// Line 1659, Address: 0x270474, Func Offset: 0x244
	// Line 1660, Address: 0x27047c, Func Offset: 0x24c
	// Line 1662, Address: 0x270488, Func Offset: 0x258
	// Line 1665, Address: 0x2704a4, Func Offset: 0x274
	// Line 1669, Address: 0x2704ac, Func Offset: 0x27c
	// Line 1667, Address: 0x2704b0, Func Offset: 0x280
	// Line 1669, Address: 0x2704b4, Func Offset: 0x284
	// Line 1671, Address: 0x2704b8, Func Offset: 0x288
	// Line 1672, Address: 0x2704c4, Func Offset: 0x294
	// Line 1675, Address: 0x2704cc, Func Offset: 0x29c
	// Line 1677, Address: 0x2704d0, Func Offset: 0x2a0
	// Line 1678, Address: 0x2704d8, Func Offset: 0x2a8
	// Line 1681, Address: 0x2704e4, Func Offset: 0x2b4
	// Line 1683, Address: 0x2704f0, Func Offset: 0x2c0
	// Line 1685, Address: 0x2704f8, Func Offset: 0x2c8
	// Line 1687, Address: 0x2704fc, Func Offset: 0x2cc
	// Line 1690, Address: 0x270504, Func Offset: 0x2d4
	// Line 1692, Address: 0x270514, Func Offset: 0x2e4
	// Line 1695, Address: 0x270524, Func Offset: 0x2f4
	// Line 1698, Address: 0x27052c, Func Offset: 0x2fc
	// Line 1701, Address: 0x270534, Func Offset: 0x304
	// Line 1704, Address: 0x270544, Func Offset: 0x314
	// Line 1709, Address: 0x27054c, Func Offset: 0x31c
	// Func End, Address: 0x27055c, Func Offset: 0x32c
}

// 
// Start address: 0x270560
void SetStateSaveScreenErrCreateSaveFile(tagSAVE_SCREEN* pSave)
{
	// Line 1726, Address: 0x270560, Func Offset: 0
	// Line 1728, Address: 0x270568, Func Offset: 0x8
	// Line 1730, Address: 0x270570, Func Offset: 0x10
	// Line 1732, Address: 0x270578, Func Offset: 0x18
	// Line 1735, Address: 0x27057c, Func Offset: 0x1c
	// Func End, Address: 0x270584, Func Offset: 0x24
}

// 
// Start address: 0x270590
void ExecuteStateSaveScreenErrCreateSaveFile(tagSAVE_SCREEN* pSave)
{
	// Line 1750, Address: 0x270590, Func Offset: 0
	// Line 1754, Address: 0x270598, Func Offset: 0x8
	// Line 1757, Address: 0x2705b8, Func Offset: 0x28
	// Line 1759, Address: 0x2705c0, Func Offset: 0x30
	// Line 1760, Address: 0x2705cc, Func Offset: 0x3c
	// Line 1764, Address: 0x2705d4, Func Offset: 0x44
	// Line 1767, Address: 0x2705f0, Func Offset: 0x60
	// Line 1770, Address: 0x2705f8, Func Offset: 0x68
	// Func End, Address: 0x270604, Func Offset: 0x74
}

// 
// Start address: 0x270610
void SetStateSaveScreenSelectFile(tagSAVE_SCREEN* pSave)
{
	// Line 1785, Address: 0x270610, Func Offset: 0
	// Line 1787, Address: 0x27061c, Func Offset: 0xc
	// Line 1789, Address: 0x270624, Func Offset: 0x14
	// Line 1791, Address: 0x27062c, Func Offset: 0x1c
	// Line 1793, Address: 0x270634, Func Offset: 0x24
	// Line 1795, Address: 0x27063c, Func Offset: 0x2c
	// Line 1797, Address: 0x270640, Func Offset: 0x30
	// Line 1799, Address: 0x27064c, Func Offset: 0x3c
	// Line 1800, Address: 0x270658, Func Offset: 0x48
	// Func End, Address: 0x270668, Func Offset: 0x58
}

// 
// Start address: 0x270670
void ExecuteStateSaveScreenSelectFile(tagSAVE_SCREEN* pSave)
{
	unsigned int KeyWait01;
	unsigned int KeyWait00;
	// Line 1815, Address: 0x270670, Func Offset: 0
	// Line 1820, Address: 0x27067c, Func Offset: 0xc
	// Line 1822, Address: 0x27069c, Func Offset: 0x2c
	// Line 1824, Address: 0x2706b8, Func Offset: 0x48
	// Line 1826, Address: 0x2706cc, Func Offset: 0x5c
	// Line 1827, Address: 0x2706dc, Func Offset: 0x6c
	// Line 1830, Address: 0x2706e4, Func Offset: 0x74
	// Line 1832, Address: 0x2706ec, Func Offset: 0x7c
	// Line 1835, Address: 0x2706f4, Func Offset: 0x84
	// Line 1836, Address: 0x2706fc, Func Offset: 0x8c
	// Line 1838, Address: 0x270704, Func Offset: 0x94
	// Line 1840, Address: 0x27072c, Func Offset: 0xbc
	// Line 1841, Address: 0x270734, Func Offset: 0xc4
	// Line 1843, Address: 0x270744, Func Offset: 0xd4
	// Line 1845, Address: 0x270750, Func Offset: 0xe0
	// Line 1847, Address: 0x27075c, Func Offset: 0xec
	// Line 1848, Address: 0x270768, Func Offset: 0xf8
	// Line 1850, Address: 0x270774, Func Offset: 0x104
	// Line 1852, Address: 0x27077c, Func Offset: 0x10c
	// Line 1853, Address: 0x270788, Func Offset: 0x118
	// Line 1854, Address: 0x270790, Func Offset: 0x120
	// Line 1857, Address: 0x2707a0, Func Offset: 0x130
	// Line 1859, Address: 0x2707ac, Func Offset: 0x13c
	// Line 1860, Address: 0x2707b8, Func Offset: 0x148
	// Line 1861, Address: 0x2707c0, Func Offset: 0x150
	// Line 1863, Address: 0x2707cc, Func Offset: 0x15c
	// Line 1865, Address: 0x2707d8, Func Offset: 0x168
	// Line 1867, Address: 0x2707e4, Func Offset: 0x174
	// Line 1869, Address: 0x2707f0, Func Offset: 0x180
	// Line 1871, Address: 0x270800, Func Offset: 0x190
	// Line 1873, Address: 0x270804, Func Offset: 0x194
	// Line 1874, Address: 0x270810, Func Offset: 0x1a0
	// Line 1875, Address: 0x270818, Func Offset: 0x1a8
	// Line 1879, Address: 0x27082c, Func Offset: 0x1bc
	// Line 1881, Address: 0x270838, Func Offset: 0x1c8
	// Line 1884, Address: 0x270844, Func Offset: 0x1d4
	// Line 1887, Address: 0x27084c, Func Offset: 0x1dc
	// Line 1890, Address: 0x270858, Func Offset: 0x1e8
	// Line 1892, Address: 0x270860, Func Offset: 0x1f0
	// Line 1893, Address: 0x27086c, Func Offset: 0x1fc
	// Line 1894, Address: 0x270874, Func Offset: 0x204
	// Line 1897, Address: 0x270880, Func Offset: 0x210
	// Line 1899, Address: 0x270888, Func Offset: 0x218
	// Line 1905, Address: 0x270894, Func Offset: 0x224
	// Line 1908, Address: 0x2708b0, Func Offset: 0x240
	// Line 1912, Address: 0x2708b8, Func Offset: 0x248
	// Line 1914, Address: 0x2708cc, Func Offset: 0x25c
	// Line 1917, Address: 0x2708d0, Func Offset: 0x260
	// Line 1919, Address: 0x2708f4, Func Offset: 0x284
	// Line 1920, Address: 0x27090c, Func Offset: 0x29c
	// Line 1922, Address: 0x270924, Func Offset: 0x2b4
	// Func End, Address: 0x270934, Func Offset: 0x2c4
}

// 
// Start address: 0x270940
void SetStateSaveScreenSaveCursor(tagSAVE_SCREEN* pSave)
{
	// Line 1937, Address: 0x270940, Func Offset: 0
	// Line 1939, Address: 0x27094c, Func Offset: 0xc
	// Line 1941, Address: 0x27095c, Func Offset: 0x1c
	// Line 1943, Address: 0x270964, Func Offset: 0x24
	// Line 1945, Address: 0x27096c, Func Offset: 0x2c
	// Line 1947, Address: 0x270974, Func Offset: 0x34
	// Line 1948, Address: 0x270978, Func Offset: 0x38
	// Func End, Address: 0x270988, Func Offset: 0x48
}

// 
// Start address: 0x270990
void ExecuteStateSaveScreenSaveCursor(tagSAVE_SCREEN* pSave)
{
	// Line 1963, Address: 0x270990, Func Offset: 0
	// Line 1965, Address: 0x2709a0, Func Offset: 0x10
	// Line 1968, Address: 0x2709bc, Func Offset: 0x2c
	// Line 1969, Address: 0x2709c4, Func Offset: 0x34
	// Line 1974, Address: 0x2709cc, Func Offset: 0x3c
	// Line 1976, Address: 0x2709d8, Func Offset: 0x48
	// Func End, Address: 0x2709e8, Func Offset: 0x58
}

// 
// Start address: 0x2709f0
void SetStateSaveScreenSaveCursorOld(tagSAVE_SCREEN* pSave)
{
	// Line 1993, Address: 0x2709f0, Func Offset: 0
	// Line 1995, Address: 0x2709f8, Func Offset: 0x8
	// Line 1997, Address: 0x270a00, Func Offset: 0x10
	// Line 1999, Address: 0x270a08, Func Offset: 0x18
	// Line 2000, Address: 0x270a0c, Func Offset: 0x1c
	// Func End, Address: 0x270a14, Func Offset: 0x24
}

// 
// Start address: 0x270a20
void ExecuteStateSaveScreenSaveCursorOld(tagSAVE_SCREEN* pSave)
{
	// Line 2015, Address: 0x270a20, Func Offset: 0
	// Line 2019, Address: 0x270a28, Func Offset: 0x8
	// Line 2021, Address: 0x270a48, Func Offset: 0x28
	// Line 2024, Address: 0x270a4c, Func Offset: 0x2c
	// Line 2021, Address: 0x270a50, Func Offset: 0x30
	// Line 2022, Address: 0x270a58, Func Offset: 0x38
	// Line 2024, Address: 0x270a64, Func Offset: 0x44
	// Line 2025, Address: 0x270a6c, Func Offset: 0x4c
	// Line 2027, Address: 0x270a74, Func Offset: 0x54
	// Line 2029, Address: 0x270a80, Func Offset: 0x60
	// Line 2032, Address: 0x270a84, Func Offset: 0x64
	// Line 2029, Address: 0x270a88, Func Offset: 0x68
	// Line 2030, Address: 0x270a90, Func Offset: 0x70
	// Line 2032, Address: 0x270a9c, Func Offset: 0x7c
	// Line 2033, Address: 0x270aa4, Func Offset: 0x84
	// Line 2035, Address: 0x270aac, Func Offset: 0x8c
	// Line 2037, Address: 0x270ab8, Func Offset: 0x98
	// Line 2040, Address: 0x270ac8, Func Offset: 0xa8
	// Line 2041, Address: 0x270ad0, Func Offset: 0xb0
	// Line 2045, Address: 0x270ad8, Func Offset: 0xb8
	// Line 2048, Address: 0x270ae0, Func Offset: 0xc0
	// Line 2049, Address: 0x270aec, Func Offset: 0xcc
	// Line 2051, Address: 0x270af4, Func Offset: 0xd4
	// Line 2054, Address: 0x270b00, Func Offset: 0xe0
	// Line 2056, Address: 0x270b08, Func Offset: 0xe8
	// Line 2057, Address: 0x270b14, Func Offset: 0xf4
	// Line 2061, Address: 0x270b1c, Func Offset: 0xfc
	// Line 2064, Address: 0x270b38, Func Offset: 0x118
	// Line 2067, Address: 0x270b40, Func Offset: 0x120
	// Func End, Address: 0x270b4c, Func Offset: 0x12c
}

// 
// Start address: 0x270b50
void SetStateSaveScreenSaveCursorNew(tagSAVE_SCREEN* pSave)
{
	// Line 2084, Address: 0x270b50, Func Offset: 0
	// Line 2086, Address: 0x270b58, Func Offset: 0x8
	// Line 2088, Address: 0x270b60, Func Offset: 0x10
	// Line 2091, Address: 0x270b68, Func Offset: 0x18
	// Func End, Address: 0x270b70, Func Offset: 0x20
}

// 
// Start address: 0x270b70
void ExecuteStateSaveScreenSaveCursorNew(tagSAVE_SCREEN* pSave)
{
	// Line 2106, Address: 0x270b70, Func Offset: 0
	// Line 2110, Address: 0x270b78, Func Offset: 0x8
	// Line 2112, Address: 0x270b98, Func Offset: 0x28
	// Line 2114, Address: 0x270b9c, Func Offset: 0x2c
	// Line 2112, Address: 0x270ba0, Func Offset: 0x30
	// Line 2113, Address: 0x270ba8, Func Offset: 0x38
	// Line 2114, Address: 0x270bb4, Func Offset: 0x44
	// Line 2115, Address: 0x270bbc, Func Offset: 0x4c
	// Line 2117, Address: 0x270bc4, Func Offset: 0x54
	// Line 2119, Address: 0x270bd0, Func Offset: 0x60
	// Line 2122, Address: 0x270bd4, Func Offset: 0x64
	// Line 2119, Address: 0x270bd8, Func Offset: 0x68
	// Line 2120, Address: 0x270be0, Func Offset: 0x70
	// Line 2122, Address: 0x270bec, Func Offset: 0x7c
	// Line 2123, Address: 0x270bf4, Func Offset: 0x84
	// Line 2125, Address: 0x270bfc, Func Offset: 0x8c
	// Line 2127, Address: 0x270c08, Func Offset: 0x98
	// Line 2130, Address: 0x270c18, Func Offset: 0xa8
	// Line 2131, Address: 0x270c20, Func Offset: 0xb0
	// Line 2135, Address: 0x270c28, Func Offset: 0xb8
	// Line 2138, Address: 0x270c30, Func Offset: 0xc0
	// Line 2139, Address: 0x270c3c, Func Offset: 0xcc
	// Line 2141, Address: 0x270c44, Func Offset: 0xd4
	// Line 2144, Address: 0x270c50, Func Offset: 0xe0
	// Line 2146, Address: 0x270c58, Func Offset: 0xe8
	// Line 2147, Address: 0x270c64, Func Offset: 0xf4
	// Line 2151, Address: 0x270c6c, Func Offset: 0xfc
	// Line 2154, Address: 0x270c88, Func Offset: 0x118
	// Line 2157, Address: 0x270c90, Func Offset: 0x120
	// Func End, Address: 0x270c9c, Func Offset: 0x12c
}

// 
// Start address: 0x270ca0
void SetStateSaveScreenSave(tagSAVE_SCREEN* pSave)
{
	// Line 2174, Address: 0x270ca0, Func Offset: 0
	// Line 2178, Address: 0x270ca8, Func Offset: 0x8
	// Line 2176, Address: 0x270cac, Func Offset: 0xc
	// Line 2178, Address: 0x270cb0, Func Offset: 0x10
	// Line 2180, Address: 0x270cb4, Func Offset: 0x14
	// Line 2182, Address: 0x270cbc, Func Offset: 0x1c
	// Func End, Address: 0x270cc8, Func Offset: 0x28
}

// 
// Start address: 0x270cd0
void ExecuteStateSaveScreenSave(tagSAVE_SCREEN* pSave)
{
	int lFileNumber;
	int lSaveResult;
	// Line 2198, Address: 0x270cd0, Func Offset: 0
	// Line 2201, Address: 0x270cdc, Func Offset: 0xc
	// Line 2206, Address: 0x270d14, Func Offset: 0x44
	// Line 2208, Address: 0x270d1c, Func Offset: 0x4c
	// Line 2212, Address: 0x270d40, Func Offset: 0x70
	// Line 2217, Address: 0x270d48, Func Offset: 0x78
	// Line 2219, Address: 0x270d50, Func Offset: 0x80
	// Line 2222, Address: 0x270d5c, Func Offset: 0x8c
	// Line 2223, Address: 0x270d60, Func Offset: 0x90
	// Line 2225, Address: 0x270d68, Func Offset: 0x98
	// Line 2228, Address: 0x270d74, Func Offset: 0xa4
	// Line 2230, Address: 0x270d80, Func Offset: 0xb0
	// Line 2232, Address: 0x270d88, Func Offset: 0xb8
	// Line 2234, Address: 0x270d8c, Func Offset: 0xbc
	// Line 2238, Address: 0x270d94, Func Offset: 0xc4
	// Line 2240, Address: 0x270d9c, Func Offset: 0xcc
	// Line 2242, Address: 0x270dac, Func Offset: 0xdc
	// Line 2243, Address: 0x270db4, Func Offset: 0xe4
	// Line 2246, Address: 0x270dbc, Func Offset: 0xec
	// Line 2249, Address: 0x270dcc, Func Offset: 0xfc
	// Line 2253, Address: 0x270dd4, Func Offset: 0x104
	// Func End, Address: 0x270de4, Func Offset: 0x114
}

// 
// Start address: 0x270df0
void SetStateSaveScreenSuccessCardWrite(tagSAVE_SCREEN* pSave)
{
	// Line 2270, Address: 0x270df0, Func Offset: 0
	// Line 2272, Address: 0x270df8, Func Offset: 0x8
	// Line 2274, Address: 0x270dfc, Func Offset: 0xc
	// Line 2272, Address: 0x270e00, Func Offset: 0x10
	// Line 2274, Address: 0x270e04, Func Offset: 0x14
	// Line 2276, Address: 0x270e08, Func Offset: 0x18
	// Func End, Address: 0x270e10, Func Offset: 0x20
}

// 
// Start address: 0x270e10
void ExecuteStateSaveScreenSuccessCardWrite(tagSAVE_SCREEN* pSave)
{
	// Line 2292, Address: 0x270e10, Func Offset: 0
	// Line 2294, Address: 0x270e20, Func Offset: 0x10
	// Line 2296, Address: 0x270e30, Func Offset: 0x20
	// Line 2299, Address: 0x270e3c, Func Offset: 0x2c
	// Line 2301, Address: 0x270e44, Func Offset: 0x34
	// Line 2307, Address: 0x270e4c, Func Offset: 0x3c
	// Func End, Address: 0x270e5c, Func Offset: 0x4c
}

// 
// Start address: 0x270e60
void SetStateSaveScreenSuccessCardWriteMessage(tagSAVE_SCREEN* pSave)
{
	// Line 2322, Address: 0x270e60, Func Offset: 0
	// Line 2324, Address: 0x270e6c, Func Offset: 0xc
	// Line 2326, Address: 0x270e74, Func Offset: 0x14
	// Line 2328, Address: 0x270e7c, Func Offset: 0x1c
	// Line 2330, Address: 0x270e84, Func Offset: 0x24
	// Line 2332, Address: 0x270e90, Func Offset: 0x30
	// Line 2334, Address: 0x270e9c, Func Offset: 0x3c
	// Line 2335, Address: 0x270ea8, Func Offset: 0x48
	// Func End, Address: 0x270eb8, Func Offset: 0x58
}

// 
// Start address: 0x270ec0
void ExecuteStateSaveScreenSuccessCardWriteMessage(tagSAVE_SCREEN* pSave)
{
	// Line 2350, Address: 0x270ec0, Func Offset: 0
	// Line 2352, Address: 0x270ec8, Func Offset: 0x8
	// Line 2355, Address: 0x270ed4, Func Offset: 0x14
	// Line 2356, Address: 0x270ed8, Func Offset: 0x18
	// Line 2360, Address: 0x270ee0, Func Offset: 0x20
	// Line 2362, Address: 0x270ee8, Func Offset: 0x28
	// Func End, Address: 0x270ef4, Func Offset: 0x34
}

// 
// Start address: 0x270f00
void SetStateSaveScreenErrCardWrite(tagSAVE_SCREEN* pSave)
{
	// Line 2379, Address: 0x270f00, Func Offset: 0
	// Line 2381, Address: 0x270f08, Func Offset: 0x8
	// Line 2383, Address: 0x270f10, Func Offset: 0x10
	// Line 2384, Address: 0x270f14, Func Offset: 0x14
	// Func End, Address: 0x270f1c, Func Offset: 0x1c
}

// 
// Start address: 0x270f20
void ExecuteStateSaveScreenErrCardWrite(tagSAVE_SCREEN* pSave)
{
	// Line 2399, Address: 0x270f20, Func Offset: 0
	// Line 2400, Address: 0x270f28, Func Offset: 0x8
	// Line 2403, Address: 0x270f48, Func Offset: 0x28
	// Line 2405, Address: 0x270f50, Func Offset: 0x30
	// Line 2406, Address: 0x270f5c, Func Offset: 0x3c
	// Line 2410, Address: 0x270f64, Func Offset: 0x44
	// Line 2413, Address: 0x270f80, Func Offset: 0x60
	// Line 2416, Address: 0x270f88, Func Offset: 0x68
	// Func End, Address: 0x270f94, Func Offset: 0x74
}

// 
// Start address: 0x270fa0
void SetStateSaveScreenFormat(tagSAVE_SCREEN* pSave)
{
	// Line 2433, Address: 0x270fa0, Func Offset: 0
	// Line 2435, Address: 0x270fa8, Func Offset: 0x8
	// Line 2437, Address: 0x270fb0, Func Offset: 0x10
	// Line 2439, Address: 0x270fb8, Func Offset: 0x18
	// Line 2441, Address: 0x270fc0, Func Offset: 0x20
	// Func End, Address: 0x270fcc, Func Offset: 0x2c
}

// 
// Start address: 0x270fd0
void ExecuteStateSaveScreenFormat(tagSAVE_SCREEN* pSave)
{
	// Line 2457, Address: 0x270fd0, Func Offset: 0
	// Line 2460, Address: 0x270fd8, Func Offset: 0x8
	// Line 2462, Address: 0x270ff8, Func Offset: 0x28
	// Line 2465, Address: 0x270ffc, Func Offset: 0x2c
	// Line 2462, Address: 0x271000, Func Offset: 0x30
	// Line 2463, Address: 0x271008, Func Offset: 0x38
	// Line 2465, Address: 0x271014, Func Offset: 0x44
	// Line 2466, Address: 0x27101c, Func Offset: 0x4c
	// Line 2467, Address: 0x271024, Func Offset: 0x54
	// Line 2469, Address: 0x271030, Func Offset: 0x60
	// Line 2472, Address: 0x271034, Func Offset: 0x64
	// Line 2469, Address: 0x271038, Func Offset: 0x68
	// Line 2470, Address: 0x271040, Func Offset: 0x70
	// Line 2472, Address: 0x27104c, Func Offset: 0x7c
	// Line 2473, Address: 0x271054, Func Offset: 0x84
	// Line 2475, Address: 0x27105c, Func Offset: 0x8c
	// Line 2477, Address: 0x271068, Func Offset: 0x98
	// Line 2480, Address: 0x271078, Func Offset: 0xa8
	// Line 2481, Address: 0x271080, Func Offset: 0xb0
	// Line 2486, Address: 0x271088, Func Offset: 0xb8
	// Line 2489, Address: 0x271090, Func Offset: 0xc0
	// Line 2490, Address: 0x27109c, Func Offset: 0xcc
	// Line 2492, Address: 0x2710a4, Func Offset: 0xd4
	// Line 2495, Address: 0x2710b0, Func Offset: 0xe0
	// Line 2497, Address: 0x2710b8, Func Offset: 0xe8
	// Line 2498, Address: 0x2710c4, Func Offset: 0xf4
	// Line 2502, Address: 0x2710cc, Func Offset: 0xfc
	// Line 2505, Address: 0x2710e8, Func Offset: 0x118
	// Line 2508, Address: 0x2710f0, Func Offset: 0x120
	// Func End, Address: 0x2710fc, Func Offset: 0x12c
}

// 
// Start address: 0x271100
void SetStateSaveScreenStartFormat(tagSAVE_SCREEN* pSave)
{
	// Line 2525, Address: 0x271100, Func Offset: 0
	// Line 2529, Address: 0x271108, Func Offset: 0x8
	// Line 2527, Address: 0x27110c, Func Offset: 0xc
	// Line 2529, Address: 0x271110, Func Offset: 0x10
	// Line 2531, Address: 0x271114, Func Offset: 0x14
	// Line 2533, Address: 0x27111c, Func Offset: 0x1c
	// Func End, Address: 0x271128, Func Offset: 0x28
}

// 
// Start address: 0x271130
void ExecuteStateSaveScreenStartFormat(tagSAVE_SCREEN* pSave)
{
	int lFormatResult;
	// Line 2550, Address: 0x271130, Func Offset: 0
	// Line 2553, Address: 0x27113c, Func Offset: 0xc
	// Line 2557, Address: 0x271174, Func Offset: 0x44
	// Line 2561, Address: 0x271188, Func Offset: 0x58
	// Line 2564, Address: 0x271190, Func Offset: 0x60
	// Line 2566, Address: 0x271198, Func Offset: 0x68
	// Line 2569, Address: 0x2711a4, Func Offset: 0x74
	// Line 2571, Address: 0x2711b0, Func Offset: 0x80
	// Line 2572, Address: 0x2711b4, Func Offset: 0x84
	// Line 2574, Address: 0x2711bc, Func Offset: 0x8c
	// Line 2577, Address: 0x2711c8, Func Offset: 0x98
	// Line 2579, Address: 0x2711d4, Func Offset: 0xa4
	// Line 2581, Address: 0x2711dc, Func Offset: 0xac
	// Line 2583, Address: 0x2711e0, Func Offset: 0xb0
	// Line 2587, Address: 0x2711e8, Func Offset: 0xb8
	// Line 2590, Address: 0x2711f8, Func Offset: 0xc8
	// Line 2592, Address: 0x271200, Func Offset: 0xd0
	// Line 2595, Address: 0x271208, Func Offset: 0xd8
	// Line 2598, Address: 0x271218, Func Offset: 0xe8
	// Line 2602, Address: 0x271220, Func Offset: 0xf0
	// Func End, Address: 0x271230, Func Offset: 0x100
}

// 
// Start address: 0x271230
void SetStateSaveScreenExitFormat(tagSAVE_SCREEN* pSave)
{
	// Line 2619, Address: 0x271230, Func Offset: 0
	// Line 2621, Address: 0x271238, Func Offset: 0x8
	// Line 2623, Address: 0x271240, Func Offset: 0x10
	// Line 2625, Address: 0x271248, Func Offset: 0x18
	// Line 2626, Address: 0x27124c, Func Offset: 0x1c
	// Func End, Address: 0x271254, Func Offset: 0x24
}

// 
// Start address: 0x271260
void ExecuteStateSaveScreenExitFormat(tagSAVE_SCREEN* pSave)
{
	// Line 2641, Address: 0x271260, Func Offset: 0
	// Line 2643, Address: 0x271268, Func Offset: 0x8
	// Line 2645, Address: 0x271288, Func Offset: 0x28
	// Line 2648, Address: 0x27128c, Func Offset: 0x2c
	// Line 2645, Address: 0x271290, Func Offset: 0x30
	// Line 2646, Address: 0x271298, Func Offset: 0x38
	// Line 2648, Address: 0x2712a4, Func Offset: 0x44
	// Line 2649, Address: 0x2712ac, Func Offset: 0x4c
	// Line 2650, Address: 0x2712b4, Func Offset: 0x54
	// Line 2652, Address: 0x2712c0, Func Offset: 0x60
	// Line 2655, Address: 0x2712c4, Func Offset: 0x64
	// Line 2652, Address: 0x2712c8, Func Offset: 0x68
	// Line 2653, Address: 0x2712d0, Func Offset: 0x70
	// Line 2655, Address: 0x2712dc, Func Offset: 0x7c
	// Line 2656, Address: 0x2712e4, Func Offset: 0x84
	// Line 2657, Address: 0x2712ec, Func Offset: 0x8c
	// Line 2659, Address: 0x2712f8, Func Offset: 0x98
	// Line 2662, Address: 0x271308, Func Offset: 0xa8
	// Line 2663, Address: 0x271310, Func Offset: 0xb0
	// Line 2667, Address: 0x271318, Func Offset: 0xb8
	// Line 2670, Address: 0x271320, Func Offset: 0xc0
	// Line 2671, Address: 0x27132c, Func Offset: 0xcc
	// Line 2672, Address: 0x271334, Func Offset: 0xd4
	// Line 2675, Address: 0x271340, Func Offset: 0xe0
	// Line 2677, Address: 0x271348, Func Offset: 0xe8
	// Line 2678, Address: 0x271354, Func Offset: 0xf4
	// Line 2682, Address: 0x27135c, Func Offset: 0xfc
	// Line 2685, Address: 0x271378, Func Offset: 0x118
	// Line 2688, Address: 0x271380, Func Offset: 0x120
	// Func End, Address: 0x27138c, Func Offset: 0x12c
}

// 
// Start address: 0x271390
void SetStateSaveScreenSuccessFormat(tagSAVE_SCREEN* pSave)
{
	// Line 2705, Address: 0x271390, Func Offset: 0
	// Line 2707, Address: 0x271398, Func Offset: 0x8
	// Line 2709, Address: 0x2713a0, Func Offset: 0x10
	// Line 2711, Address: 0x2713a8, Func Offset: 0x18
	// Line 2712, Address: 0x2713ac, Func Offset: 0x1c
	// Func End, Address: 0x2713b4, Func Offset: 0x24
}

// 
// Start address: 0x2713c0
void ExecuteStateSaveScreenSuccessFormat(tagSAVE_SCREEN* pSave)
{
	// Line 2727, Address: 0x2713c0, Func Offset: 0
	// Line 2729, Address: 0x2713c8, Func Offset: 0x8
	// Line 2732, Address: 0x2713d8, Func Offset: 0x18
	// Line 2734, Address: 0x2713e0, Func Offset: 0x20
	// Func End, Address: 0x2713ec, Func Offset: 0x2c
}

// 
// Start address: 0x2713f0
void SetStateSaveScreenErrFormat(tagSAVE_SCREEN* pSave)
{
	// Line 2751, Address: 0x2713f0, Func Offset: 0
	// Line 2753, Address: 0x2713f8, Func Offset: 0x8
	// Line 2755, Address: 0x271400, Func Offset: 0x10
	// Line 2758, Address: 0x271408, Func Offset: 0x18
	// Func End, Address: 0x271410, Func Offset: 0x20
}

// 
// Start address: 0x271410
void ExecuteStateSaveScreenErrFormat(tagSAVE_SCREEN* pSave)
{
	// Line 2773, Address: 0x271410, Func Offset: 0
	// Line 2774, Address: 0x271418, Func Offset: 0x8
	// Line 2777, Address: 0x271434, Func Offset: 0x24
	// Line 2779, Address: 0x27143c, Func Offset: 0x2c
	// Line 2780, Address: 0x271448, Func Offset: 0x38
	// Line 2784, Address: 0x271450, Func Offset: 0x40
	// Line 2787, Address: 0x27146c, Func Offset: 0x5c
	// Line 2790, Address: 0x271474, Func Offset: 0x64
	// Func End, Address: 0x271480, Func Offset: 0x70
}

// 
// Start address: 0x271480
void SetStateSaveScreenErrDer(tagSAVE_SCREEN* pSave)
{
	// Line 2807, Address: 0x271480, Func Offset: 0
	// Line 2809, Address: 0x271488, Func Offset: 0x8
	// Line 2811, Address: 0x271490, Func Offset: 0x10
	// Line 2812, Address: 0x271494, Func Offset: 0x14
	// Func End, Address: 0x27149c, Func Offset: 0x1c
}

// 
// Start address: 0x2714a0
void ExecuteStateSaveScreenErrDer(tagSAVE_SCREEN* pSave)
{
	// Line 2827, Address: 0x2714a0, Func Offset: 0
	// Line 2828, Address: 0x2714a8, Func Offset: 0x8
	// Line 2831, Address: 0x2714c8, Func Offset: 0x28
	// Line 2833, Address: 0x2714d0, Func Offset: 0x30
	// Line 2834, Address: 0x2714dc, Func Offset: 0x3c
	// Line 2838, Address: 0x2714e4, Func Offset: 0x44
	// Line 2841, Address: 0x271500, Func Offset: 0x60
	// Line 2844, Address: 0x271508, Func Offset: 0x68
	// Func End, Address: 0x271514, Func Offset: 0x74
}

// 
// Start address: 0x271520
void SetDispSelectMessage()
{
	// Line 2870, Address: 0x271520, Func Offset: 0
	// Line 2858, Address: 0x27152c, Func Offset: 0xc
	// Line 2870, Address: 0x271530, Func Offset: 0x10
	// Line 2858, Address: 0x271538, Func Offset: 0x18
	// Line 2870, Address: 0x27153c, Func Offset: 0x1c
	// Line 2872, Address: 0x271544, Func Offset: 0x24
	// Line 2874, Address: 0x271574, Func Offset: 0x54
	// Line 2875, Address: 0x2715a4, Func Offset: 0x84
	// Line 2877, Address: 0x2715d4, Func Offset: 0xb4
	// Line 2878, Address: 0x271604, Func Offset: 0xe4
	// Line 2880, Address: 0x271638, Func Offset: 0x118
	// Line 2882, Address: 0x27166c, Func Offset: 0x14c
	// Line 2884, Address: 0x271684, Func Offset: 0x164
	// Func End, Address: 0x271690, Func Offset: 0x170
}

// 
// Start address: 0x271690
void CheckDispMemoryCard(tagSAVE_SCREEN* pSave)
{
	int lPort1CurX;
	int lPort0CurX;
	int lPort1Card;
	int lPort0Card;
	// Line 2899, Address: 0x271690, Func Offset: 0
	// Line 2904, Address: 0x2716a8, Func Offset: 0x18
	// Line 2905, Address: 0x2716b4, Func Offset: 0x24
	// Line 2908, Address: 0x2716c4, Func Offset: 0x34
	// Line 2912, Address: 0x2716d8, Func Offset: 0x48
	// Line 2911, Address: 0x2716dc, Func Offset: 0x4c
	// Line 2914, Address: 0x2716e0, Func Offset: 0x50
	// Line 2912, Address: 0x2716e4, Func Offset: 0x54
	// Line 2915, Address: 0x2716e8, Func Offset: 0x58
	// Line 2917, Address: 0x2716f0, Func Offset: 0x60
	// Line 2923, Address: 0x271704, Func Offset: 0x74
	// Line 2921, Address: 0x271708, Func Offset: 0x78
	// Line 2924, Address: 0x27170c, Func Offset: 0x7c
	// Line 2920, Address: 0x271710, Func Offset: 0x80
	// Line 2925, Address: 0x271714, Func Offset: 0x84
	// Line 2927, Address: 0x27171c, Func Offset: 0x8c
	// Line 2932, Address: 0x271730, Func Offset: 0xa0
	// Line 2933, Address: 0x271734, Func Offset: 0xa4
	// Line 2929, Address: 0x271738, Func Offset: 0xa8
	// Line 2931, Address: 0x27173c, Func Offset: 0xac
	// Line 2935, Address: 0x271740, Func Offset: 0xb0
	// Line 2944, Address: 0x271748, Func Offset: 0xb8
	// Line 2943, Address: 0x27174c, Func Offset: 0xbc
	// Line 2939, Address: 0x271750, Func Offset: 0xc0
	// Line 2940, Address: 0x271754, Func Offset: 0xc4
	// Line 2941, Address: 0x271758, Func Offset: 0xc8
	// Line 2942, Address: 0x27175c, Func Offset: 0xcc
	// Line 2944, Address: 0x271760, Func Offset: 0xd0
	// Line 2947, Address: 0x271764, Func Offset: 0xd4
	// Line 2949, Address: 0x271774, Func Offset: 0xe4
	// Line 2950, Address: 0x271778, Func Offset: 0xe8
	// Line 2951, Address: 0x27177c, Func Offset: 0xec
	// Line 2952, Address: 0x271780, Func Offset: 0xf0
	// Line 2956, Address: 0x271784, Func Offset: 0xf4
	// Line 2957, Address: 0x27179c, Func Offset: 0x10c
	// Line 2959, Address: 0x2717b8, Func Offset: 0x128
	// Line 2960, Address: 0x271810, Func Offset: 0x180
	// Func End, Address: 0x271828, Func Offset: 0x198
}*/

