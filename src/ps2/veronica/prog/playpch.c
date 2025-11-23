#include "playpch.h"
#include "pwksub.h"

/*BH_PWORK* plp;
_anon10* sys;
_anon1 WpnTab[0];
float lcmat[16][0];
BH_PWORK ene[0];
unsigned short PlMtnWpn[0];
_anon5 WpnEffTab[4][0];*/

// 100% matching! 
void PlyPchInit(BH_PWORK* ewP)
{
    ewP->exp2 = bhGetFreeMemory(1712, 32);
}

/*// 
// Start address: 0x14a5e0
void PlyPchMain(BH_PWORK* ewP)
{
	int* dstP;
	int* atP;
	int dir;
	npobj* objP;
	_anon11* mlwP;
	_anon3* ppP;
	char RouteArmLn_0[5];
	char RouteArmRn_0[5];
	// Line 101, Address: 0x14a5e0, Func Offset: 0
	// Line 111, Address: 0x14a5f4, Func Offset: 0x14
	// Line 108, Address: 0x14a600, Func Offset: 0x20
	// Line 111, Address: 0x14a608, Func Offset: 0x28
	// Line 112, Address: 0x14a638, Func Offset: 0x58
	// Line 115, Address: 0x14a654, Func Offset: 0x74
	// Line 116, Address: 0x14a664, Func Offset: 0x84
	// Line 118, Address: 0x14a674, Func Offset: 0x94
	// Line 126, Address: 0x14a678, Func Offset: 0x98
	// Line 120, Address: 0x14a680, Func Offset: 0xa0
	// Line 121, Address: 0x14a698, Func Offset: 0xb8
	// Line 123, Address: 0x14a6b0, Func Offset: 0xd0
	// Line 126, Address: 0x14a6bc, Func Offset: 0xdc
	// Line 127, Address: 0x14a6d0, Func Offset: 0xf0
	// Line 128, Address: 0x14a6e0, Func Offset: 0x100
	// Line 129, Address: 0x14a6f0, Func Offset: 0x110
	// Line 130, Address: 0x14a708, Func Offset: 0x128
	// Line 133, Address: 0x14a710, Func Offset: 0x130
	// Line 134, Address: 0x14a718, Func Offset: 0x138
	// Line 133, Address: 0x14a71c, Func Offset: 0x13c
	// Line 135, Address: 0x14a724, Func Offset: 0x144
	// Line 136, Address: 0x14a72c, Func Offset: 0x14c
	// Line 137, Address: 0x14a738, Func Offset: 0x158
	// Line 138, Address: 0x14a748, Func Offset: 0x168
	// Line 140, Address: 0x14a750, Func Offset: 0x170
	// Line 141, Address: 0x14a754, Func Offset: 0x174
	// Line 143, Address: 0x14a758, Func Offset: 0x178
	// Line 140, Address: 0x14a760, Func Offset: 0x180
	// Line 141, Address: 0x14a768, Func Offset: 0x188
	// Line 143, Address: 0x14a76c, Func Offset: 0x18c
	// Line 148, Address: 0x14a780, Func Offset: 0x1a0
	// Line 152, Address: 0x14a784, Func Offset: 0x1a4
	// Line 148, Address: 0x14a790, Func Offset: 0x1b0
	// Line 149, Address: 0x14a79c, Func Offset: 0x1bc
	// Line 152, Address: 0x14a7a8, Func Offset: 0x1c8
	// Line 153, Address: 0x14a7b0, Func Offset: 0x1d0
	// Line 155, Address: 0x14a7c0, Func Offset: 0x1e0
	// Line 156, Address: 0x14a7d0, Func Offset: 0x1f0
	// Line 159, Address: 0x14a7e0, Func Offset: 0x200
	// Line 163, Address: 0x14a7ec, Func Offset: 0x20c
	// Line 166, Address: 0x14a81c, Func Offset: 0x23c
	// Line 168, Address: 0x14a850, Func Offset: 0x270
	// Line 172, Address: 0x14a85c, Func Offset: 0x27c
	// Line 173, Address: 0x14a874, Func Offset: 0x294
	// Line 179, Address: 0x14a88c, Func Offset: 0x2ac
	// Line 180, Address: 0x14a8b8, Func Offset: 0x2d8
	// Line 181, Address: 0x14a8e4, Func Offset: 0x304
	// Line 183, Address: 0x14a908, Func Offset: 0x328
	// Line 185, Address: 0x14a914, Func Offset: 0x334
	// Line 192, Address: 0x14a920, Func Offset: 0x340
	// Line 190, Address: 0x14a924, Func Offset: 0x344
	// Line 192, Address: 0x14a928, Func Offset: 0x348
	// Line 193, Address: 0x14a92c, Func Offset: 0x34c
	// Line 185, Address: 0x14a930, Func Offset: 0x350
	// Line 193, Address: 0x14a938, Func Offset: 0x358
	// Line 192, Address: 0x14a93c, Func Offset: 0x35c
	// Line 185, Address: 0x14a940, Func Offset: 0x360
	// Line 192, Address: 0x14a94c, Func Offset: 0x36c
	// Line 193, Address: 0x14a950, Func Offset: 0x370
	// Line 194, Address: 0x14a958, Func Offset: 0x378
	// Line 198, Address: 0x14a960, Func Offset: 0x380
	// Line 199, Address: 0x14a964, Func Offset: 0x384
	// Line 194, Address: 0x14a96c, Func Offset: 0x38c
	// Line 195, Address: 0x14a984, Func Offset: 0x3a4
	// Line 196, Address: 0x14a9a0, Func Offset: 0x3c0
	// Line 198, Address: 0x14a9a8, Func Offset: 0x3c8
	// Line 199, Address: 0x14a9b4, Func Offset: 0x3d4
	// Line 200, Address: 0x14a9bc, Func Offset: 0x3dc
	// Line 201, Address: 0x14a9dc, Func Offset: 0x3fc
	// Line 202, Address: 0x14a9f8, Func Offset: 0x418
	// Line 206, Address: 0x14a9fc, Func Offset: 0x41c
	// Line 207, Address: 0x14aa04, Func Offset: 0x424
	// Line 208, Address: 0x14aa0c, Func Offset: 0x42c
	// Line 207, Address: 0x14aa10, Func Offset: 0x430
	// Line 208, Address: 0x14aa20, Func Offset: 0x440
	// Line 209, Address: 0x14aa28, Func Offset: 0x448
	// Line 208, Address: 0x14aa2c, Func Offset: 0x44c
	// Line 209, Address: 0x14aa3c, Func Offset: 0x45c
	// Line 210, Address: 0x14aa44, Func Offset: 0x464
	// Line 209, Address: 0x14aa48, Func Offset: 0x468
	// Line 210, Address: 0x14aa58, Func Offset: 0x478
	// Line 212, Address: 0x14aa70, Func Offset: 0x490
	// Line 213, Address: 0x14aa80, Func Offset: 0x4a0
	// Line 218, Address: 0x14aa84, Func Offset: 0x4a4
	// Func End, Address: 0x14aa9c, Func Offset: 0x4bc
}

// 
// Start address: 0x14aaa0
void MixSetToJointRot(npobj* basP, char* rutP, npobj* objP, int yaw)
{
	npobj* tmpP;
	float mtx1P[16];
	float mtx0P[16];
	// Line 231, Address: 0x14aaa0, Func Offset: 0
	// Line 232, Address: 0x14aac0, Func Offset: 0x20
	// Line 233, Address: 0x14aac8, Func Offset: 0x28
	// Line 235, Address: 0x14aad4, Func Offset: 0x34
	// Line 237, Address: 0x14aaec, Func Offset: 0x4c
	// Line 239, Address: 0x14aaf4, Func Offset: 0x54
	// Line 241, Address: 0x14aaf8, Func Offset: 0x58
	// Line 239, Address: 0x14aafc, Func Offset: 0x5c
	// Line 241, Address: 0x14ab14, Func Offset: 0x74
	// Line 242, Address: 0x14ab28, Func Offset: 0x88
	// Line 244, Address: 0x14ab38, Func Offset: 0x98
	// Line 246, Address: 0x14ab44, Func Offset: 0xa4
	// Line 248, Address: 0x14ab58, Func Offset: 0xb8
	// Line 249, Address: 0x14ab60, Func Offset: 0xc0
	// Line 250, Address: 0x14ab6c, Func Offset: 0xcc
	// Line 252, Address: 0x14ab78, Func Offset: 0xd8
	// Line 253, Address: 0x14ab7c, Func Offset: 0xdc
	// Line 252, Address: 0x14ab84, Func Offset: 0xe4
	// Line 253, Address: 0x14ab98, Func Offset: 0xf8
	// Line 254, Address: 0x14abb8, Func Offset: 0x118
	// Line 255, Address: 0x14abdc, Func Offset: 0x13c
	// Line 257, Address: 0x14ac00, Func Offset: 0x160
	// Func End, Address: 0x14ac24, Func Offset: 0x184
}

// 
// Start address: 0x14ac30
void GetOneObjectMotion(BH_PWORK* ewP, int obj_no, int* ang)
{
	_anon15* mkaP;
	char* rutP;
	int flp;
	char NormalTbl[64];
	// Line 286, Address: 0x14ac30, Func Offset: 0
	// Line 287, Address: 0x14ac40, Func Offset: 0x10
	// Line 289, Address: 0x14ac44, Func Offset: 0x14
	// Line 290, Address: 0x14ac4c, Func Offset: 0x1c
	// Line 291, Address: 0x14ac54, Func Offset: 0x24
	// Line 295, Address: 0x14ac58, Func Offset: 0x28
	// Line 293, Address: 0x14ac5c, Func Offset: 0x2c
	// Line 295, Address: 0x14ac60, Func Offset: 0x30
	// Line 297, Address: 0x14ac88, Func Offset: 0x58
	// Line 298, Address: 0x14ac90, Func Offset: 0x60
	// Line 299, Address: 0x14aca8, Func Offset: 0x78
	// Line 300, Address: 0x14acb0, Func Offset: 0x80
	// Line 301, Address: 0x14acbc, Func Offset: 0x8c
	// Line 302, Address: 0x14acc4, Func Offset: 0x94
	// Line 303, Address: 0x14accc, Func Offset: 0x9c
	// Line 306, Address: 0x14acd8, Func Offset: 0xa8
	// Func End, Address: 0x14ace0, Func Offset: 0xb0
}

// 
// Start address: 0x14ace0
void SetOneObjectMotion(BH_PWORK* ewP, npobj* objP, int* ang)
{
	int* srcP;
	float rate;
	short dlt;
	int sum1;
	int* srcP;
	int tmpS[3];
	int tmpD[3];
	// Line 319, Address: 0x14ace0, Func Offset: 0
	// Line 321, Address: 0x14acf8, Func Offset: 0x18
	// Line 331, Address: 0x14ad0c, Func Offset: 0x2c
	// Line 332, Address: 0x14ad44, Func Offset: 0x64
	// Line 334, Address: 0x14ad58, Func Offset: 0x78
	// Line 335, Address: 0x14ad6c, Func Offset: 0x8c
	// Line 337, Address: 0x14ad80, Func Offset: 0xa0
	// Line 340, Address: 0x14ada8, Func Offset: 0xc8
	// Line 341, Address: 0x14ade0, Func Offset: 0x100
	// Line 343, Address: 0x14adf8, Func Offset: 0x118
	// Line 346, Address: 0x14ae00, Func Offset: 0x120
	// Line 344, Address: 0x14ae04, Func Offset: 0x124
	// Line 346, Address: 0x14ae08, Func Offset: 0x128
	// Line 347, Address: 0x14ae0c, Func Offset: 0x12c
	// Line 346, Address: 0x14ae10, Func Offset: 0x130
	// Line 347, Address: 0x14ae1c, Func Offset: 0x13c
	// Line 348, Address: 0x14ae28, Func Offset: 0x148
	// Line 367, Address: 0x14ae3c, Func Offset: 0x15c
	// Line 368, Address: 0x14ae4c, Func Offset: 0x16c
	// Line 370, Address: 0x14ae5c, Func Offset: 0x17c
	// Line 374, Address: 0x14ae60, Func Offset: 0x180
	// Line 370, Address: 0x14ae68, Func Offset: 0x188
	// Line 374, Address: 0x14ae7c, Func Offset: 0x19c
	// Line 370, Address: 0x14ae80, Func Offset: 0x1a0
	// Line 374, Address: 0x14ae84, Func Offset: 0x1a4
	// Line 370, Address: 0x14ae88, Func Offset: 0x1a8
	// Line 374, Address: 0x14ae8c, Func Offset: 0x1ac
	// Line 375, Address: 0x14aeb4, Func Offset: 0x1d4
	// Line 374, Address: 0x14aebc, Func Offset: 0x1dc
	// Line 375, Address: 0x14aec8, Func Offset: 0x1e8
	// Line 376, Address: 0x14aef8, Func Offset: 0x218
	// Line 375, Address: 0x14af00, Func Offset: 0x220
	// Line 376, Address: 0x14af0c, Func Offset: 0x22c
	// Line 378, Address: 0x14af3c, Func Offset: 0x25c
	// Line 376, Address: 0x14af48, Func Offset: 0x268
	// Line 378, Address: 0x14af50, Func Offset: 0x270
	// Line 382, Address: 0x14af58, Func Offset: 0x278
	// Line 386, Address: 0x14af60, Func Offset: 0x280
	// Line 387, Address: 0x14af68, Func Offset: 0x288
	// Line 388, Address: 0x14af70, Func Offset: 0x290
	// Line 391, Address: 0x14af78, Func Offset: 0x298
	// Func End, Address: 0x14af94, Func Offset: 0x2b4
}

// 
// Start address: 0x14afa0
_search* bhSearchEnemy(BH_PWORK* pwP, int rng, float hgt)
{
	_anon36 cap;
	int i;
	float dst;
	float p_cs;
	BH_PWORK* ewP;
	_anon27 vct1;
	_anon27 vct0;
	_search* prvP;
	_search* scnP;
	_search* lstP;
	_search* hedP;
	// Line 403, Address: 0x14afa0, Func Offset: 0
	// Line 410, Address: 0x14afd0, Func Offset: 0x30
	// Line 412, Address: 0x14afdc, Func Offset: 0x3c
	// Line 413, Address: 0x14afe0, Func Offset: 0x40
	// Line 410, Address: 0x14afe4, Func Offset: 0x44
	// Line 411, Address: 0x14afe8, Func Offset: 0x48
	// Line 414, Address: 0x14afec, Func Offset: 0x4c
	// Line 416, Address: 0x14aff0, Func Offset: 0x50
	// Line 421, Address: 0x14aff8, Func Offset: 0x58
	// Line 416, Address: 0x14b000, Func Offset: 0x60
	// Line 421, Address: 0x14b004, Func Offset: 0x64
	// Line 429, Address: 0x14b014, Func Offset: 0x74
	// Line 422, Address: 0x14b020, Func Offset: 0x80
	// Line 429, Address: 0x14b024, Func Offset: 0x84
	// Line 430, Address: 0x14b02c, Func Offset: 0x8c
	// Line 433, Address: 0x14b078, Func Offset: 0xd8
	// Line 435, Address: 0x14b0a0, Func Offset: 0x100
	// Line 437, Address: 0x14b0b0, Func Offset: 0x110
	// Line 438, Address: 0x14b0b4, Func Offset: 0x114
	// Line 435, Address: 0x14b0b8, Func Offset: 0x118
	// Line 438, Address: 0x14b0bc, Func Offset: 0x11c
	// Line 435, Address: 0x14b0c0, Func Offset: 0x120
	// Line 436, Address: 0x14b0c8, Func Offset: 0x128
	// Line 437, Address: 0x14b0dc, Func Offset: 0x13c
	// Line 438, Address: 0x14b0ec, Func Offset: 0x14c
	// Line 439, Address: 0x14b0f4, Func Offset: 0x154
	// Line 442, Address: 0x14b0fc, Func Offset: 0x15c
	// Line 439, Address: 0x14b100, Func Offset: 0x160
	// Line 442, Address: 0x14b104, Func Offset: 0x164
	// Line 445, Address: 0x14b120, Func Offset: 0x180
	// Line 446, Address: 0x14b124, Func Offset: 0x184
	// Line 449, Address: 0x14b128, Func Offset: 0x188
	// Line 445, Address: 0x14b130, Func Offset: 0x190
	// Line 446, Address: 0x14b138, Func Offset: 0x198
	// Line 447, Address: 0x14b144, Func Offset: 0x1a4
	// Line 448, Address: 0x14b150, Func Offset: 0x1b0
	// Line 449, Address: 0x14b158, Func Offset: 0x1b8
	// Line 450, Address: 0x14b160, Func Offset: 0x1c0
	// Line 453, Address: 0x14b16c, Func Offset: 0x1cc
	// Line 455, Address: 0x14b184, Func Offset: 0x1e4
	// Line 456, Address: 0x14b1b0, Func Offset: 0x210
	// Line 457, Address: 0x14b1b4, Func Offset: 0x214
	// Line 458, Address: 0x14b1b8, Func Offset: 0x218
	// Line 462, Address: 0x14b1bc, Func Offset: 0x21c
	// Line 463, Address: 0x14b1c0, Func Offset: 0x220
	// Line 465, Address: 0x14b1c8, Func Offset: 0x228
	// Line 466, Address: 0x14b1dc, Func Offset: 0x23c
	// Line 467, Address: 0x14b1e0, Func Offset: 0x240
	// Line 470, Address: 0x14b1e4, Func Offset: 0x244
	// Line 471, Address: 0x14b1f0, Func Offset: 0x250
	// Line 472, Address: 0x14b1f8, Func Offset: 0x258
	// Line 476, Address: 0x14b200, Func Offset: 0x260
	// Line 478, Address: 0x14b228, Func Offset: 0x288
	// Line 479, Address: 0x14b22c, Func Offset: 0x28c
	// Func End, Address: 0x14b260, Func Offset: 0x2c0
}

// 
// Start address: 0x14b260
int SetLockOnDirection(int range, int count, int mode, int special)
{
	_search* tgtP;
	_search* lstP;
	_search* topP;
	_anon3* ppP;
	// Line 495, Address: 0x14b260, Func Offset: 0
	// Line 496, Address: 0x14b274, Func Offset: 0x14
	// Line 501, Address: 0x14b280, Func Offset: 0x20
	// Line 502, Address: 0x14b290, Func Offset: 0x30
	// Line 504, Address: 0x14b294, Func Offset: 0x34
	// Line 506, Address: 0x14b2c8, Func Offset: 0x68
	// Line 509, Address: 0x14b2d0, Func Offset: 0x70
	// Line 538, Address: 0x14b2d8, Func Offset: 0x78
	// Line 535, Address: 0x14b2dc, Func Offset: 0x7c
	// Line 538, Address: 0x14b2e0, Func Offset: 0x80
	// Line 539, Address: 0x14b2e4, Func Offset: 0x84
	// Line 541, Address: 0x14b2e8, Func Offset: 0x88
	// Line 543, Address: 0x14b2fc, Func Offset: 0x9c
	// Line 546, Address: 0x14b30c, Func Offset: 0xac
	// Line 550, Address: 0x14b31c, Func Offset: 0xbc
	// Line 555, Address: 0x14b324, Func Offset: 0xc4
	// Line 557, Address: 0x14b338, Func Offset: 0xd8
	// Line 559, Address: 0x14b350, Func Offset: 0xf0
	// Line 560, Address: 0x14b358, Func Offset: 0xf8
	// Line 561, Address: 0x14b35c, Func Offset: 0xfc
	// Line 562, Address: 0x14b36c, Func Offset: 0x10c
	// Line 563, Address: 0x14b37c, Func Offset: 0x11c
	// Line 565, Address: 0x14b384, Func Offset: 0x124
	// Line 568, Address: 0x14b398, Func Offset: 0x138
	// Line 569, Address: 0x14b3a0, Func Offset: 0x140
	// Line 570, Address: 0x14b3b4, Func Offset: 0x154
	// Line 571, Address: 0x14b3c8, Func Offset: 0x168
	// Line 572, Address: 0x14b3d0, Func Offset: 0x170
	// Line 573, Address: 0x14b3e4, Func Offset: 0x184
	// Line 575, Address: 0x14b3fc, Func Offset: 0x19c
	// Line 578, Address: 0x14b404, Func Offset: 0x1a4
	// Line 580, Address: 0x14b40c, Func Offset: 0x1ac
	// Line 582, Address: 0x14b418, Func Offset: 0x1b8
	// Line 583, Address: 0x14b420, Func Offset: 0x1c0
	// Line 586, Address: 0x14b428, Func Offset: 0x1c8
	// Line 589, Address: 0x14b430, Func Offset: 0x1d0
	// Line 593, Address: 0x14b448, Func Offset: 0x1e8
	// Line 597, Address: 0x14b45c, Func Offset: 0x1fc
	// Func End, Address: 0x14b474, Func Offset: 0x214
}

// 
// Start address: 0x14b480
void bhCPM2_act_suw_pch()
{
	_search* lstP;
	// Line 611, Address: 0x14b480, Func Offset: 0
	// Line 613, Address: 0x14b48c, Func Offset: 0xc
	// Line 619, Address: 0x14b4b4, Func Offset: 0x34
	// Line 621, Address: 0x14b4c8, Func Offset: 0x48
	// Line 622, Address: 0x14b4d0, Func Offset: 0x50
	// Line 623, Address: 0x14b4dc, Func Offset: 0x5c
	// Line 622, Address: 0x14b4e0, Func Offset: 0x60
	// Line 623, Address: 0x14b4e4, Func Offset: 0x64
	// Line 622, Address: 0x14b4e8, Func Offset: 0x68
	// Line 623, Address: 0x14b4f0, Func Offset: 0x70
	// Line 629, Address: 0x14b4fc, Func Offset: 0x7c
	// Line 634, Address: 0x14b50c, Func Offset: 0x8c
	// Line 636, Address: 0x14b510, Func Offset: 0x90
	// Line 629, Address: 0x14b514, Func Offset: 0x94
	// Line 634, Address: 0x14b518, Func Offset: 0x98
	// Line 637, Address: 0x14b51c, Func Offset: 0x9c
	// Line 638, Address: 0x14b520, Func Offset: 0xa0
	// Line 639, Address: 0x14b524, Func Offset: 0xa4
	// Line 629, Address: 0x14b528, Func Offset: 0xa8
	// Line 634, Address: 0x14b530, Func Offset: 0xb0
	// Line 635, Address: 0x14b538, Func Offset: 0xb8
	// Line 634, Address: 0x14b53c, Func Offset: 0xbc
	// Line 635, Address: 0x14b544, Func Offset: 0xc4
	// Line 636, Address: 0x14b554, Func Offset: 0xd4
	// Line 637, Address: 0x14b560, Func Offset: 0xe0
	// Line 638, Address: 0x14b56c, Func Offset: 0xec
	// Line 639, Address: 0x14b578, Func Offset: 0xf8
	// Line 640, Address: 0x14b584, Func Offset: 0x104
	// Line 639, Address: 0x14b588, Func Offset: 0x108
	// Line 640, Address: 0x14b58c, Func Offset: 0x10c
	// Line 642, Address: 0x14b590, Func Offset: 0x110
	// Line 643, Address: 0x14b5b8, Func Offset: 0x138
	// Line 648, Address: 0x14b5cc, Func Offset: 0x14c
	// Line 649, Address: 0x14b5e0, Func Offset: 0x160
	// Line 650, Address: 0x14b5e8, Func Offset: 0x168
	// Line 649, Address: 0x14b5f4, Func Offset: 0x174
	// Line 650, Address: 0x14b5fc, Func Offset: 0x17c
	// Line 651, Address: 0x14b630, Func Offset: 0x1b0
	// Line 652, Address: 0x14b640, Func Offset: 0x1c0
	// Line 653, Address: 0x14b648, Func Offset: 0x1c8
	// Line 656, Address: 0x14b658, Func Offset: 0x1d8
	// Line 657, Address: 0x14b698, Func Offset: 0x218
	// Line 659, Address: 0x14b6a8, Func Offset: 0x228
	// Line 660, Address: 0x14b6e8, Func Offset: 0x268
	// Line 661, Address: 0x14b6ec, Func Offset: 0x26c
	// Line 663, Address: 0x14b6f8, Func Offset: 0x278
	// Line 664, Address: 0x14b6fc, Func Offset: 0x27c
	// Line 661, Address: 0x14b700, Func Offset: 0x280
	// Line 662, Address: 0x14b704, Func Offset: 0x284
	// Line 663, Address: 0x14b710, Func Offset: 0x290
	// Line 664, Address: 0x14b71c, Func Offset: 0x29c
	// Line 666, Address: 0x14b728, Func Offset: 0x2a8
	// Line 667, Address: 0x14b734, Func Offset: 0x2b4
	// Line 668, Address: 0x14b73c, Func Offset: 0x2bc
	// Line 670, Address: 0x14b744, Func Offset: 0x2c4
	// Line 671, Address: 0x14b778, Func Offset: 0x2f8
	// Line 672, Address: 0x14b7a8, Func Offset: 0x328
	// Line 673, Address: 0x14b7b0, Func Offset: 0x330
	// Line 674, Address: 0x14b7b8, Func Offset: 0x338
	// Line 675, Address: 0x14b7bc, Func Offset: 0x33c
	// Line 677, Address: 0x14b7c0, Func Offset: 0x340
	// Line 673, Address: 0x14b7c4, Func Offset: 0x344
	// Line 674, Address: 0x14b7c8, Func Offset: 0x348
	// Line 675, Address: 0x14b7d4, Func Offset: 0x354
	// Line 676, Address: 0x14b7e0, Func Offset: 0x360
	// Line 677, Address: 0x14b7ec, Func Offset: 0x36c
	// Line 678, Address: 0x14b7f4, Func Offset: 0x374
	// Line 680, Address: 0x14b7fc, Func Offset: 0x37c
	// Line 681, Address: 0x14b818, Func Offset: 0x398
	// Line 682, Address: 0x14b820, Func Offset: 0x3a0
	// Line 683, Address: 0x14b828, Func Offset: 0x3a8
	// Line 686, Address: 0x14b82c, Func Offset: 0x3ac
	// Line 682, Address: 0x14b830, Func Offset: 0x3b0
	// Line 683, Address: 0x14b834, Func Offset: 0x3b4
	// Line 684, Address: 0x14b840, Func Offset: 0x3c0
	// Line 685, Address: 0x14b84c, Func Offset: 0x3cc
	// Line 686, Address: 0x14b858, Func Offset: 0x3d8
	// Line 687, Address: 0x14b860, Func Offset: 0x3e0
	// Line 692, Address: 0x14b868, Func Offset: 0x3e8
	// Line 693, Address: 0x14b8c8, Func Offset: 0x448
	// Line 694, Address: 0x14b928, Func Offset: 0x4a8
	// Func End, Address: 0x14b938, Func Offset: 0x4b8
}

// 
// Start address: 0x14b940
void bhCPM2_act_wsc_pch()
{
	// Line 778, Address: 0x14b940, Func Offset: 0
	// Func End, Address: 0x14b948, Func Offset: 0x8
}

// 
// Start address: 0x14b950
void bhCPM2_act_atk_pch()
{
	_search* lstP;
	_anon14* gaP;
	_anon14* gaP;
	_anon5* wet;
	_anon1* wt;
	_anon3* ppP;
	// Line 785, Address: 0x14b950, Func Offset: 0
	// Line 786, Address: 0x14b968, Func Offset: 0x18
	// Line 787, Address: 0x14b970, Func Offset: 0x20
	// Line 788, Address: 0x14b978, Func Offset: 0x28
	// Line 786, Address: 0x14b980, Func Offset: 0x30
	// Line 787, Address: 0x14b984, Func Offset: 0x34
	// Line 788, Address: 0x14b9a0, Func Offset: 0x50
	// Line 792, Address: 0x14b9a8, Func Offset: 0x58
	// Line 788, Address: 0x14b9ac, Func Offset: 0x5c
	// Line 792, Address: 0x14b9b4, Func Offset: 0x64
	// Line 797, Address: 0x14b9e8, Func Offset: 0x98
	// Line 799, Address: 0x14ba10, Func Offset: 0xc0
	// Line 800, Address: 0x14ba18, Func Offset: 0xc8
	// Line 799, Address: 0x14ba1c, Func Offset: 0xcc
	// Line 800, Address: 0x14ba24, Func Offset: 0xd4
	// Line 801, Address: 0x14ba50, Func Offset: 0x100
	// Line 802, Address: 0x14ba8c, Func Offset: 0x13c
	// Line 803, Address: 0x14ba9c, Func Offset: 0x14c
	// Line 804, Address: 0x14bab0, Func Offset: 0x160
	// Line 806, Address: 0x14bac0, Func Offset: 0x170
	// Line 808, Address: 0x14badc, Func Offset: 0x18c
	// Line 815, Address: 0x14bae0, Func Offset: 0x190
	// Line 806, Address: 0x14bae4, Func Offset: 0x194
	// Line 808, Address: 0x14bae8, Func Offset: 0x198
	// Line 809, Address: 0x14baf4, Func Offset: 0x1a4
	// Line 810, Address: 0x14bb00, Func Offset: 0x1b0
	// Line 815, Address: 0x14bb14, Func Offset: 0x1c4
	// Line 818, Address: 0x14bb18, Func Offset: 0x1c8
	// Line 819, Address: 0x14bb28, Func Offset: 0x1d8
	// Line 820, Address: 0x14bb44, Func Offset: 0x1f4
	// Line 819, Address: 0x14bb48, Func Offset: 0x1f8
	// Line 820, Address: 0x14bb50, Func Offset: 0x200
	// Line 828, Address: 0x14bb64, Func Offset: 0x214
	// Line 830, Address: 0x14bb88, Func Offset: 0x238
	// Line 833, Address: 0x14bb90, Func Offset: 0x240
	// Line 834, Address: 0x14bb9c, Func Offset: 0x24c
	// Line 835, Address: 0x14bbac, Func Offset: 0x25c
	// Line 841, Address: 0x14bbd0, Func Offset: 0x280
	// Line 842, Address: 0x14bc00, Func Offset: 0x2b0
	// Line 845, Address: 0x14bc18, Func Offset: 0x2c8
	// Line 847, Address: 0x14bc40, Func Offset: 0x2f0
	// Line 850, Address: 0x14bc5c, Func Offset: 0x30c
	// Line 855, Address: 0x14bce0, Func Offset: 0x390
	// Line 856, Address: 0x14bcf0, Func Offset: 0x3a0
	// Line 857, Address: 0x14bcf8, Func Offset: 0x3a8
	// Line 858, Address: 0x14bd00, Func Offset: 0x3b0
	// Line 860, Address: 0x14bd08, Func Offset: 0x3b8
	// Line 861, Address: 0x14bd38, Func Offset: 0x3e8
	// Line 862, Address: 0x14bd44, Func Offset: 0x3f4
	// Line 863, Address: 0x14bd50, Func Offset: 0x400
	// Line 867, Address: 0x14bd58, Func Offset: 0x408
	// Line 871, Address: 0x14bd68, Func Offset: 0x418
	// Line 872, Address: 0x14bdd8, Func Offset: 0x488
	// Line 873, Address: 0x14bdfc, Func Offset: 0x4ac
	// Line 874, Address: 0x14be20, Func Offset: 0x4d0
	// Line 876, Address: 0x14be40, Func Offset: 0x4f0
	// Line 877, Address: 0x14be48, Func Offset: 0x4f8
	// Line 880, Address: 0x14be50, Func Offset: 0x500
	// Line 881, Address: 0x14be64, Func Offset: 0x514
	// Line 883, Address: 0x14be70, Func Offset: 0x520
	// Line 884, Address: 0x14be90, Func Offset: 0x540
	// Line 889, Address: 0x14bea8, Func Offset: 0x558
	// Line 890, Address: 0x14beb8, Func Offset: 0x568
	// Line 889, Address: 0x14bebc, Func Offset: 0x56c
	// Line 890, Address: 0x14bed4, Func Offset: 0x584
	// Line 891, Address: 0x14bf30, Func Offset: 0x5e0
	// Line 893, Address: 0x14bf8c, Func Offset: 0x63c
	// Line 898, Address: 0x14bf94, Func Offset: 0x644
	// Line 899, Address: 0x14bfc0, Func Offset: 0x670
	// Line 900, Address: 0x14bfc8, Func Offset: 0x678
	// Line 901, Address: 0x14bfd4, Func Offset: 0x684
	// Line 902, Address: 0x14bfe4, Func Offset: 0x694
	// Line 903, Address: 0x14bfec, Func Offset: 0x69c
	// Line 906, Address: 0x14bff8, Func Offset: 0x6a8
	// Line 908, Address: 0x14c044, Func Offset: 0x6f4
	// Line 909, Address: 0x14c04c, Func Offset: 0x6fc
	// Line 908, Address: 0x14c054, Func Offset: 0x704
	// Line 909, Address: 0x14c05c, Func Offset: 0x70c
	// Line 911, Address: 0x14c088, Func Offset: 0x738
	// Line 913, Address: 0x14c094, Func Offset: 0x744
	// Line 915, Address: 0x14c0b8, Func Offset: 0x768
	// Line 916, Address: 0x14c0c0, Func Offset: 0x770
	// Line 917, Address: 0x14c0d4, Func Offset: 0x784
	// Line 919, Address: 0x14c0e4, Func Offset: 0x794
	// Line 920, Address: 0x14c100, Func Offset: 0x7b0
	// Line 923, Address: 0x14c104, Func Offset: 0x7b4
	// Line 919, Address: 0x14c108, Func Offset: 0x7b8
	// Line 920, Address: 0x14c10c, Func Offset: 0x7bc
	// Line 921, Address: 0x14c118, Func Offset: 0x7c8
	// Line 922, Address: 0x14c124, Func Offset: 0x7d4
	// Line 923, Address: 0x14c13c, Func Offset: 0x7ec
	// Line 928, Address: 0x14c148, Func Offset: 0x7f8
	// Line 929, Address: 0x14c16c, Func Offset: 0x81c
	// Line 931, Address: 0x14c174, Func Offset: 0x824
	// Line 932, Address: 0x14c184, Func Offset: 0x834
	// Line 933, Address: 0x14c1a0, Func Offset: 0x850
	// Line 932, Address: 0x14c1a4, Func Offset: 0x854
	// Line 933, Address: 0x14c1ac, Func Offset: 0x85c
	// Line 941, Address: 0x14c1c0, Func Offset: 0x870
	// Line 943, Address: 0x14c1e4, Func Offset: 0x894
	// Line 945, Address: 0x14c1f4, Func Offset: 0x8a4
	// Line 946, Address: 0x14c200, Func Offset: 0x8b0
	// Line 947, Address: 0x14c204, Func Offset: 0x8b4
	// Line 945, Address: 0x14c208, Func Offset: 0x8b8
	// Line 946, Address: 0x14c20c, Func Offset: 0x8bc
	// Line 945, Address: 0x14c210, Func Offset: 0x8c0
	// Line 946, Address: 0x14c218, Func Offset: 0x8c8
	// Line 947, Address: 0x14c220, Func Offset: 0x8d0
	// Line 949, Address: 0x14c234, Func Offset: 0x8e4
	// Line 950, Address: 0x14c244, Func Offset: 0x8f4
	// Line 951, Address: 0x14c280, Func Offset: 0x930
	// Line 952, Address: 0x14c28c, Func Offset: 0x93c
	// Line 953, Address: 0x14c298, Func Offset: 0x948
	// Line 955, Address: 0x14c29c, Func Offset: 0x94c
	// Line 961, Address: 0x14c2a4, Func Offset: 0x954
	// Line 962, Address: 0x14c2b0, Func Offset: 0x960
	// Line 963, Address: 0x14c2c0, Func Offset: 0x970
	// Line 966, Address: 0x14c2e4, Func Offset: 0x994
	// Line 970, Address: 0x14c2f4, Func Offset: 0x9a4
	// Line 972, Address: 0x14c318, Func Offset: 0x9c8
	// Line 975, Address: 0x14c334, Func Offset: 0x9e4
	// Line 979, Address: 0x14c388, Func Offset: 0xa38
	// Line 980, Address: 0x14c398, Func Offset: 0xa48
	// Line 981, Address: 0x14c3a4, Func Offset: 0xa54
	// Line 982, Address: 0x14c3cc, Func Offset: 0xa7c
	// Line 983, Address: 0x14c3d8, Func Offset: 0xa88
	// Line 982, Address: 0x14c3dc, Func Offset: 0xa8c
	// Line 983, Address: 0x14c3e0, Func Offset: 0xa90
	// Line 982, Address: 0x14c3e4, Func Offset: 0xa94
	// Line 983, Address: 0x14c3ec, Func Offset: 0xa9c
	// Line 985, Address: 0x14c420, Func Offset: 0xad0
	// Line 987, Address: 0x14c428, Func Offset: 0xad8
	// Line 989, Address: 0x14c44c, Func Offset: 0xafc
	// Line 990, Address: 0x14c454, Func Offset: 0xb04
	// Line 991, Address: 0x14c460, Func Offset: 0xb10
	// Line 995, Address: 0x14c464, Func Offset: 0xb14
	// Line 998, Address: 0x14c46c, Func Offset: 0xb1c
	// Line 1000, Address: 0x14c488, Func Offset: 0xb38
	// Line 1002, Address: 0x14c4a4, Func Offset: 0xb54
	// Line 1003, Address: 0x14c4dc, Func Offset: 0xb8c
	// Line 1004, Address: 0x14c4e4, Func Offset: 0xb94
	// Line 1003, Address: 0x14c4e8, Func Offset: 0xb98
	// Line 1004, Address: 0x14c4ec, Func Offset: 0xb9c
	// Line 1003, Address: 0x14c4f0, Func Offset: 0xba0
	// Line 1004, Address: 0x14c4f8, Func Offset: 0xba8
	// Line 1005, Address: 0x14c50c, Func Offset: 0xbbc
	// Line 1007, Address: 0x14c540, Func Offset: 0xbf0
	// Line 1008, Address: 0x14c548, Func Offset: 0xbf8
	// Line 1009, Address: 0x14c55c, Func Offset: 0xc0c
	// Line 1011, Address: 0x14c568, Func Offset: 0xc18
	// Line 1013, Address: 0x14c58c, Func Offset: 0xc3c
	// Line 1015, Address: 0x14c594, Func Offset: 0xc44
	// Line 1016, Address: 0x14c59c, Func Offset: 0xc4c
	// Line 1017, Address: 0x14c5a4, Func Offset: 0xc54
	// Line 1016, Address: 0x14c5a8, Func Offset: 0xc58
	// Line 1017, Address: 0x14c5b4, Func Offset: 0xc64
	// Line 1018, Address: 0x14c5bc, Func Offset: 0xc6c
	// Line 1020, Address: 0x14c5c4, Func Offset: 0xc74
	// Line 1021, Address: 0x14c5cc, Func Offset: 0xc7c
	// Line 1022, Address: 0x14c5d4, Func Offset: 0xc84
	// Line 1021, Address: 0x14c5d8, Func Offset: 0xc88
	// Line 1022, Address: 0x14c5e4, Func Offset: 0xc94
	// Line 1025, Address: 0x14c5f0, Func Offset: 0xca0
	// Line 1026, Address: 0x14c5fc, Func Offset: 0xcac
	// Line 1027, Address: 0x14c608, Func Offset: 0xcb8
	// Line 1028, Address: 0x14c610, Func Offset: 0xcc0
	// Line 1033, Address: 0x14c618, Func Offset: 0xcc8
	// Line 1034, Address: 0x14c620, Func Offset: 0xcd0
	// Line 1035, Address: 0x14c62c, Func Offset: 0xcdc
	// Line 1034, Address: 0x14c630, Func Offset: 0xce0
	// Line 1035, Address: 0x14c634, Func Offset: 0xce4
	// Line 1037, Address: 0x14c668, Func Offset: 0xd18
	// Line 1038, Address: 0x14c670, Func Offset: 0xd20
	// Line 1039, Address: 0x14c684, Func Offset: 0xd34
	// Line 1041, Address: 0x14c690, Func Offset: 0xd40
	// Line 1043, Address: 0x14c6b4, Func Offset: 0xd64
	// Line 1045, Address: 0x14c6bc, Func Offset: 0xd6c
	// Line 1046, Address: 0x14c6c4, Func Offset: 0xd74
	// Line 1047, Address: 0x14c6cc, Func Offset: 0xd7c
	// Line 1046, Address: 0x14c6d0, Func Offset: 0xd80
	// Line 1047, Address: 0x14c6dc, Func Offset: 0xd8c
	// Line 1048, Address: 0x14c6e4, Func Offset: 0xd94
	// Line 1050, Address: 0x14c6ec, Func Offset: 0xd9c
	// Line 1051, Address: 0x14c6f4, Func Offset: 0xda4
	// Line 1052, Address: 0x14c6fc, Func Offset: 0xdac
	// Line 1051, Address: 0x14c700, Func Offset: 0xdb0
	// Line 1052, Address: 0x14c70c, Func Offset: 0xdbc
	// Line 1055, Address: 0x14c718, Func Offset: 0xdc8
	// Line 1056, Address: 0x14c720, Func Offset: 0xdd0
	// Line 1059, Address: 0x14c728, Func Offset: 0xdd8
	// Line 1060, Address: 0x14c75c, Func Offset: 0xe0c
	// Line 1062, Address: 0x14c79c, Func Offset: 0xe4c
	// Line 1063, Address: 0x14c7a0, Func Offset: 0xe50
	// Line 1066, Address: 0x14c7ac, Func Offset: 0xe5c
	// Line 1067, Address: 0x14c7b4, Func Offset: 0xe64
	// Line 1066, Address: 0x14c7b8, Func Offset: 0xe68
	// Line 1067, Address: 0x14c7c0, Func Offset: 0xe70
	// Line 1066, Address: 0x14c7c4, Func Offset: 0xe74
	// Line 1067, Address: 0x14c7dc, Func Offset: 0xe8c
	// Line 1069, Address: 0x14c818, Func Offset: 0xec8
	// Line 1070, Address: 0x14c834, Func Offset: 0xee4
	// Line 1071, Address: 0x14c83c, Func Offset: 0xeec
	// Line 1073, Address: 0x14c840, Func Offset: 0xef0
	// Line 1070, Address: 0x14c844, Func Offset: 0xef4
	// Line 1071, Address: 0x14c84c, Func Offset: 0xefc
	// Line 1072, Address: 0x14c854, Func Offset: 0xf04
	// Line 1071, Address: 0x14c858, Func Offset: 0xf08
	// Line 1072, Address: 0x14c860, Func Offset: 0xf10
	// Line 1073, Address: 0x14c870, Func Offset: 0xf20
	// Line 1074, Address: 0x14c87c, Func Offset: 0xf2c
	// Line 1075, Address: 0x14c888, Func Offset: 0xf38
	// Line 1076, Address: 0x14c894, Func Offset: 0xf44
	// Line 1075, Address: 0x14c898, Func Offset: 0xf48
	// Line 1076, Address: 0x14c89c, Func Offset: 0xf4c
	// Line 1078, Address: 0x14c8a4, Func Offset: 0xf54
	// Line 1080, Address: 0x14c8cc, Func Offset: 0xf7c
	// Line 1082, Address: 0x14c8ec, Func Offset: 0xf9c
	// Line 1084, Address: 0x14c8f4, Func Offset: 0xfa4
	// Line 1085, Address: 0x14c910, Func Offset: 0xfc0
	// Line 1086, Address: 0x14c918, Func Offset: 0xfc8
	// Line 1088, Address: 0x14c91c, Func Offset: 0xfcc
	// Line 1085, Address: 0x14c920, Func Offset: 0xfd0
	// Line 1086, Address: 0x14c928, Func Offset: 0xfd8
	// Line 1091, Address: 0x14c92c, Func Offset: 0xfdc
	// Line 1092, Address: 0x14c930, Func Offset: 0xfe0
	// Line 1086, Address: 0x14c934, Func Offset: 0xfe4
	// Line 1087, Address: 0x14c938, Func Offset: 0xfe8
	// Line 1086, Address: 0x14c93c, Func Offset: 0xfec
	// Line 1087, Address: 0x14c944, Func Offset: 0xff4
	// Line 1088, Address: 0x14c958, Func Offset: 0x1008
	// Line 1089, Address: 0x14c964, Func Offset: 0x1014
	// Line 1090, Address: 0x14c970, Func Offset: 0x1020
	// Line 1091, Address: 0x14c97c, Func Offset: 0x102c
	// Line 1090, Address: 0x14c980, Func Offset: 0x1030
	// Line 1091, Address: 0x14c984, Func Offset: 0x1034
	// Line 1092, Address: 0x14c98c, Func Offset: 0x103c
	// Line 1094, Address: 0x14c9a8, Func Offset: 0x1058
	// Line 1096, Address: 0x14c9b0, Func Offset: 0x1060
	// Line 1097, Address: 0x14c9cc, Func Offset: 0x107c
	// Line 1098, Address: 0x14c9d4, Func Offset: 0x1084
	// Line 1100, Address: 0x14c9d8, Func Offset: 0x1088
	// Line 1097, Address: 0x14c9dc, Func Offset: 0x108c
	// Line 1098, Address: 0x14c9e4, Func Offset: 0x1094
	// Line 1103, Address: 0x14c9e8, Func Offset: 0x1098
	// Line 1104, Address: 0x14c9ec, Func Offset: 0x109c
	// Line 1098, Address: 0x14c9f0, Func Offset: 0x10a0
	// Line 1099, Address: 0x14c9f4, Func Offset: 0x10a4
	// Line 1098, Address: 0x14c9f8, Func Offset: 0x10a8
	// Line 1099, Address: 0x14ca00, Func Offset: 0x10b0
	// Line 1100, Address: 0x14ca14, Func Offset: 0x10c4
	// Line 1101, Address: 0x14ca20, Func Offset: 0x10d0
	// Line 1102, Address: 0x14ca2c, Func Offset: 0x10dc
	// Line 1103, Address: 0x14ca38, Func Offset: 0x10e8
	// Line 1102, Address: 0x14ca3c, Func Offset: 0x10ec
	// Line 1103, Address: 0x14ca40, Func Offset: 0x10f0
	// Line 1104, Address: 0x14ca48, Func Offset: 0x10f8
	// Line 1109, Address: 0x14ca68, Func Offset: 0x1118
	// Line 1110, Address: 0x14cac8, Func Offset: 0x1178
	// Line 1113, Address: 0x14cb28, Func Offset: 0x11d8
	// Line 1116, Address: 0x14cb48, Func Offset: 0x11f8
	// Line 1117, Address: 0x14cb64, Func Offset: 0x1214
	// Line 1118, Address: 0x14cb70, Func Offset: 0x1220
	// Line 1117, Address: 0x14cb74, Func Offset: 0x1224
	// Line 1118, Address: 0x14cb78, Func Offset: 0x1228
	// Line 1117, Address: 0x14cb7c, Func Offset: 0x122c
	// Line 1118, Address: 0x14cb84, Func Offset: 0x1234
	// Line 1123, Address: 0x14cb90, Func Offset: 0x1240
	// Line 1124, Address: 0x14cb9c, Func Offset: 0x124c
	// Line 1125, Address: 0x14cbbc, Func Offset: 0x126c
	// Line 1126, Address: 0x14cbe0, Func Offset: 0x1290
	// Line 1127, Address: 0x14cc04, Func Offset: 0x12b4
	// Line 1128, Address: 0x14cc08, Func Offset: 0x12b8
	// Line 1129, Address: 0x14cc10, Func Offset: 0x12c0
	// Line 1133, Address: 0x14cc20, Func Offset: 0x12d0
	// Line 1134, Address: 0x14cc3c, Func Offset: 0x12ec
	// Line 1138, Address: 0x14cc50, Func Offset: 0x1300
	// Func End, Address: 0x14cc6c, Func Offset: 0x131c
}

// 
// Start address: 0x14cc70
_anon14* CheckGunHit(_anon1* wtP, int obj_no, int yaw)
{
	_anon27 ps;
	_anon14 gap;
	// Line 1143, Address: 0x14cc70, Func Offset: 0
	// Line 1147, Address: 0x14cc84, Func Offset: 0x14
	// Line 1159, Address: 0x14cc8c, Func Offset: 0x1c
	// Line 1160, Address: 0x14cc94, Func Offset: 0x24
	// Line 1147, Address: 0x14cc9c, Func Offset: 0x2c
	// Line 1160, Address: 0x14cca4, Func Offset: 0x34
	// Line 1158, Address: 0x14ccb0, Func Offset: 0x40
	// Line 1147, Address: 0x14ccb4, Func Offset: 0x44
	// Line 1148, Address: 0x14ccb8, Func Offset: 0x48
	// Line 1159, Address: 0x14ccc0, Func Offset: 0x50
	// Line 1160, Address: 0x14ccc4, Func Offset: 0x54
	// Line 1148, Address: 0x14ccc8, Func Offset: 0x58
	// Line 1149, Address: 0x14cccc, Func Offset: 0x5c
	// Line 1150, Address: 0x14ccd8, Func Offset: 0x68
	// Line 1151, Address: 0x14cce4, Func Offset: 0x74
	// Line 1152, Address: 0x14ccf0, Func Offset: 0x80
	// Line 1153, Address: 0x14ccfc, Func Offset: 0x8c
	// Line 1154, Address: 0x14cd08, Func Offset: 0x98
	// Line 1155, Address: 0x14cd10, Func Offset: 0xa0
	// Line 1160, Address: 0x14cd14, Func Offset: 0xa4
	// Line 1156, Address: 0x14cd18, Func Offset: 0xa8
	// Line 1158, Address: 0x14cd24, Func Offset: 0xb4
	// Line 1159, Address: 0x14cd28, Func Offset: 0xb8
	// Line 1158, Address: 0x14cd30, Func Offset: 0xc0
	// Line 1159, Address: 0x14cd34, Func Offset: 0xc4
	// Line 1160, Address: 0x14cd58, Func Offset: 0xe8
	// Line 1161, Address: 0x14cd6c, Func Offset: 0xfc
	// Line 1162, Address: 0x14cd88, Func Offset: 0x118
	// Line 1161, Address: 0x14cd90, Func Offset: 0x120
	// Line 1162, Address: 0x14cd9c, Func Offset: 0x12c
	// Line 1164, Address: 0x14cda4, Func Offset: 0x134
	// Line 1162, Address: 0x14cda8, Func Offset: 0x138
	// Line 1164, Address: 0x14cdb4, Func Offset: 0x144
	// Line 1165, Address: 0x14cdbc, Func Offset: 0x14c
	// Line 1166, Address: 0x14cdd8, Func Offset: 0x168
	// Line 1167, Address: 0x14cddc, Func Offset: 0x16c
	// Line 1168, Address: 0x14cde4, Func Offset: 0x174
	// Line 1166, Address: 0x14cde8, Func Offset: 0x178
	// Line 1168, Address: 0x14cdec, Func Offset: 0x17c
	// Line 1167, Address: 0x14cdf4, Func Offset: 0x184
	// Line 1168, Address: 0x14cdf8, Func Offset: 0x188
	// Line 1169, Address: 0x14ce04, Func Offset: 0x194
	// Line 1172, Address: 0x14ce10, Func Offset: 0x1a0
	// Line 1171, Address: 0x14ce20, Func Offset: 0x1b0
	// Line 1172, Address: 0x14ce28, Func Offset: 0x1b8
	// Func End, Address: 0x14ce30, Func Offset: 0x1c0
}

// 
// Start address: 0x14ce30
void bhCPM2_SearchPch()
{
	_anon3* ppP;
	_search* lstP;
	// Line 1187, Address: 0x14ce30, Func Offset: 0
	// Line 1191, Address: 0x14ce38, Func Offset: 0x8
	// Line 1194, Address: 0x14ce98, Func Offset: 0x68
	// Line 1195, Address: 0x14cea0, Func Offset: 0x70
	// Line 1196, Address: 0x14ceac, Func Offset: 0x7c
	// Line 1195, Address: 0x14ceb0, Func Offset: 0x80
	// Line 1196, Address: 0x14ceb4, Func Offset: 0x84
	// Line 1195, Address: 0x14ceb8, Func Offset: 0x88
	// Line 1196, Address: 0x14cec0, Func Offset: 0x90
	// Line 1199, Address: 0x14cec8, Func Offset: 0x98
	// Line 1196, Address: 0x14cecc, Func Offset: 0x9c
	// Line 1199, Address: 0x14ced0, Func Offset: 0xa0
	// Line 1201, Address: 0x14ced8, Func Offset: 0xa8
	// Line 1202, Address: 0x14cef0, Func Offset: 0xc0
	// Line 1206, Address: 0x14cef8, Func Offset: 0xc8
	// Line 1207, Address: 0x14cf08, Func Offset: 0xd8
	// Line 1208, Address: 0x14cf24, Func Offset: 0xf4
	// Line 1209, Address: 0x14cf2c, Func Offset: 0xfc
	// Line 1210, Address: 0x14cf38, Func Offset: 0x108
	// Line 1209, Address: 0x14cf3c, Func Offset: 0x10c
	// Line 1210, Address: 0x14cf40, Func Offset: 0x110
	// Line 1216, Address: 0x14cf4c, Func Offset: 0x11c
	// Func End, Address: 0x14cf58, Func Offset: 0x128
}

// 
// Start address: 0x14cf60
void bhArmIkMdk(BH_PWORK* ewP, int bas_no, _anon27* effP, int rot)
{
	npobj* obj1P;
	npobj* obj0P;
	_anon27* vtP;
	_anon27* vb1P;
	_anon27* vyP;
	_anon27* vhP;
	float l01;
	float lb0;
	float lb1;
	int Ta;
	_anon27 vu;
	// Line 1235, Address: 0x14cf60, Func Offset: 0
	// Line 1241, Address: 0x14cf8c, Func Offset: 0x2c
	// Line 1235, Address: 0x14cf90, Func Offset: 0x30
	// Line 1241, Address: 0x14cf94, Func Offset: 0x34
	// Line 1235, Address: 0x14cf98, Func Offset: 0x38
	// Line 1242, Address: 0x14cfa0, Func Offset: 0x40
	// Line 1235, Address: 0x14cfa4, Func Offset: 0x44
	// Line 1242, Address: 0x14cfa8, Func Offset: 0x48
	// Line 1235, Address: 0x14cfac, Func Offset: 0x4c
	// Line 1250, Address: 0x14cfb0, Func Offset: 0x50
	// Line 1245, Address: 0x14cfb4, Func Offset: 0x54
	// Line 1243, Address: 0x14cfc4, Func Offset: 0x64
	// Line 1250, Address: 0x14cfcc, Func Offset: 0x6c
	// Line 1245, Address: 0x14cfd0, Func Offset: 0x70
	// Line 1244, Address: 0x14cfd4, Func Offset: 0x74
	// Line 1245, Address: 0x14cfdc, Func Offset: 0x7c
	// Line 1250, Address: 0x14cff8, Func Offset: 0x98
	// Line 1245, Address: 0x14d00c, Func Offset: 0xac
	// Line 1250, Address: 0x14d010, Func Offset: 0xb0
	// Line 1252, Address: 0x14d018, Func Offset: 0xb8
	// Line 1253, Address: 0x14d020, Func Offset: 0xc0
	// Line 1254, Address: 0x14d02c, Func Offset: 0xcc
	// Line 1256, Address: 0x14d03c, Func Offset: 0xdc
	// Line 1257, Address: 0x14d048, Func Offset: 0xe8
	// Line 1258, Address: 0x14d054, Func Offset: 0xf4
	// Line 1261, Address: 0x14d05c, Func Offset: 0xfc
	// Line 1260, Address: 0x14d060, Func Offset: 0x100
	// Line 1263, Address: 0x14d064, Func Offset: 0x104
	// Line 1264, Address: 0x14d078, Func Offset: 0x118
	// Line 1266, Address: 0x14d080, Func Offset: 0x120
	// Line 1267, Address: 0x14d090, Func Offset: 0x130
	// Line 1269, Address: 0x14d098, Func Offset: 0x138
	// Line 1271, Address: 0x14d0a8, Func Offset: 0x148
	// Line 1273, Address: 0x14d0f4, Func Offset: 0x194
	// Line 1274, Address: 0x14d104, Func Offset: 0x1a4
	// Line 1282, Address: 0x14d108, Func Offset: 0x1a8
	// Line 1274, Address: 0x14d118, Func Offset: 0x1b8
	// Line 1275, Address: 0x14d120, Func Offset: 0x1c0
	// Line 1276, Address: 0x14d124, Func Offset: 0x1c4
	// Line 1282, Address: 0x14d12c, Func Offset: 0x1cc
	// Line 1283, Address: 0x14d134, Func Offset: 0x1d4
	// Line 1285, Address: 0x14d13c, Func Offset: 0x1dc
	// Line 1286, Address: 0x14d14c, Func Offset: 0x1ec
	// Line 1288, Address: 0x14d154, Func Offset: 0x1f4
	// Line 1289, Address: 0x14d178, Func Offset: 0x218
	// Line 1290, Address: 0x14d19c, Func Offset: 0x23c
	// Line 1291, Address: 0x14d1bc, Func Offset: 0x25c
	// Line 1290, Address: 0x14d1c0, Func Offset: 0x260
	// Line 1291, Address: 0x14d1c4, Func Offset: 0x264
	// Line 1293, Address: 0x14d204, Func Offset: 0x2a4
	// Line 1295, Address: 0x14d20c, Func Offset: 0x2ac
	// Func End, Address: 0x14d250, Func Offset: 0x2f0
}*/

