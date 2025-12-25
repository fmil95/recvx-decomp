#include "event.h"
#include "MdlPut.h"
#include "Motion.h"
#include "ps2_NaMath.h"
#include "pwksub.h"
#include "main.h"

/*_anon52 evnt_BldTbl;
_anon52 evnt_BldTbl2;
_anon15* sys;
unsigned short* bhScdPtr;
_anon19 swork;*/
BH_SCEWORK* bhCetask;
/*_anon40 bhEtask[16];
unsigned int Event_T_timer;
int bhIfelFlg;
unsigned char* bhEvdPtr;
unsigned short* bhScd2Ptr;
_anon14* rom;
unsigned int* G_Sp;*/
unsigned char* bhScePtr;
/*BH_PWORK* plp;
_anon45 cam;
BH_PWORK ene[0];*/
float GameFar;
float GameNear;
/*unsigned char G_Mess_flag;
_anon26 NextSoundInfo;
unsigned char pl_sleep_cnt;
_anon24 WpnTab[0];
_anon0 eff[0];
unsigned int(*bhScenarioJmpT)()[256];
unsigned int Ps2_ice_flag;
unsigned int Event_T_timer_bak;
unsigned int Event_C_timer;
unsigned int bhCetask_w[308];
unsigned int* G_Ework_ptr;
_anon23 bhEventWork2;
unsigned short* G_Pl_life;
unsigned short* G_Timer;
unsigned char bhEventWork[16];
unsigned int G_Common_flg[16];
unsigned int* G_Sp9;
unsigned int* G_Sp8;
unsigned int* G_Sp7;
unsigned int* G_Sp6;
unsigned int* G_Sp5;
unsigned int* G_Sp4;
unsigned int* G_Sp3;
unsigned int* G_Sp2;
unsigned int* G_Sp1;*/

// 
// Start address: 0x1559c0
void bhInitEvent()
{
	unsigned int v6;
	// Line 244, Address: 0x1559c0, Func Offset: 0
	// Line 246, Address: 0x1559d0, Func Offset: 0x10
	// Line 247, Address: 0x1559d4, Func Offset: 0x14
	// Line 249, Address: 0x1559d8, Func Offset: 0x18
	// Line 248, Address: 0x1559dc, Func Offset: 0x1c
	// Line 249, Address: 0x1559e4, Func Offset: 0x24
	// Line 250, Address: 0x1559f0, Func Offset: 0x30
	// Line 258, Address: 0x1559f8, Func Offset: 0x38
	// Line 260, Address: 0x155a00, Func Offset: 0x40
	// Line 268, Address: 0x155a08, Func Offset: 0x48
	// Line 260, Address: 0x155a10, Func Offset: 0x50
	// Line 270, Address: 0x155a14, Func Offset: 0x54
	// Line 260, Address: 0x155a1c, Func Offset: 0x5c
	// Line 261, Address: 0x155a28, Func Offset: 0x68
	// Line 271, Address: 0x155a2c, Func Offset: 0x6c
	// Line 261, Address: 0x155a34, Func Offset: 0x74
	// Line 262, Address: 0x155a40, Func Offset: 0x80
	// Line 268, Address: 0x155a50, Func Offset: 0x90
	// Line 264, Address: 0x155a58, Func Offset: 0x98
	// Line 266, Address: 0x155a60, Func Offset: 0xa0
	// Line 270, Address: 0x155a68, Func Offset: 0xa8
	// Line 271, Address: 0x155a7c, Func Offset: 0xbc
	// Line 272, Address: 0x155a84, Func Offset: 0xc4
	// Line 273, Address: 0x155a94, Func Offset: 0xd4
	// Line 274, Address: 0x155a9c, Func Offset: 0xdc
	// Line 275, Address: 0x155aa8, Func Offset: 0xe8
	// Line 274, Address: 0x155aac, Func Offset: 0xec
	// Line 275, Address: 0x155ab4, Func Offset: 0xf4
	// Line 276, Address: 0x155abc, Func Offset: 0xfc
	// Func End, Address: 0x155ac8, Func Offset: 0x108
	scePrintf("bhInitEvent - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x155ad0
void bhControlEvent()
{
	// Line 311, Address: 0x155ad0, Func Offset: 0
	// Line 312, Address: 0x155ad8, Func Offset: 0x8
	// Line 313, Address: 0x155ae4, Func Offset: 0x14
	// Line 314, Address: 0x155aec, Func Offset: 0x1c
	// Func End, Address: 0x155af8, Func Offset: 0x28
	scePrintf("bhControlEvent - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x155b00
unsigned int bhEnd()
{
	// Line 320, Address: 0x155b00, Func Offset: 0
	// Line 322, Address: 0x155b08, Func Offset: 0x8
	// Func End, Address: 0x155b10, Func Offset: 0x10
}

// 
// Start address: 0x155b10
unsigned int bhIfelCk()
{
	unsigned int v0;
	// Line 329, Address: 0x155b10, Func Offset: 0
	// Line 337, Address: 0x155b18, Func Offset: 0x8
	// Line 335, Address: 0x155b1c, Func Offset: 0xc
	// Line 329, Address: 0x155b24, Func Offset: 0x14
	// Line 330, Address: 0x155b28, Func Offset: 0x18
	// Line 335, Address: 0x155b34, Func Offset: 0x24
	// Line 333, Address: 0x155b40, Func Offset: 0x30
	// Line 334, Address: 0x155b58, Func Offset: 0x48
	// Line 338, Address: 0x155b68, Func Offset: 0x58
	// Func End, Address: 0x155b70, Func Offset: 0x60
}

// 
// Start address: 0x155b70
unsigned int bhElseCk()
{
	// Line 344, Address: 0x155b70, Func Offset: 0
	// Line 347, Address: 0x155b78, Func Offset: 0x8
	// Line 345, Address: 0x155b7c, Func Offset: 0xc
	// Line 344, Address: 0x155b84, Func Offset: 0x14
	// Line 346, Address: 0x155b88, Func Offset: 0x18
	// Line 345, Address: 0x155b90, Func Offset: 0x20
	// Line 344, Address: 0x155b94, Func Offset: 0x24
	// Line 345, Address: 0x155b9c, Func Offset: 0x2c
	// Line 346, Address: 0x155ba4, Func Offset: 0x34
	// Line 348, Address: 0x155bb0, Func Offset: 0x40
	// Func End, Address: 0x155bb8, Func Offset: 0x48
}

// 
// Start address: 0x155bc0
unsigned int bhEndif()
{
	// Line 353, Address: 0x155bc0, Func Offset: 0
	// Line 356, Address: 0x155bc8, Func Offset: 0x8
	// Line 354, Address: 0x155bcc, Func Offset: 0xc
	// Line 353, Address: 0x155bd4, Func Offset: 0x14
	// Line 355, Address: 0x155bd8, Func Offset: 0x18
	// Line 354, Address: 0x155be0, Func Offset: 0x20
	// Line 353, Address: 0x155be4, Func Offset: 0x24
	// Line 354, Address: 0x155bec, Func Offset: 0x2c
	// Line 355, Address: 0x155bf4, Func Offset: 0x34
	// Line 357, Address: 0x155bfc, Func Offset: 0x3c
	// Func End, Address: 0x155c04, Func Offset: 0x44
}

// 
// Start address: 0x155c10
unsigned int dm0()
{
	// Line 364, Address: 0x155c10, Func Offset: 0
	// Func End, Address: 0x155c18, Func Offset: 0x8
}

// 
// Start address: 0x155c20
unsigned int bhCk()
{
	unsigned char* a0;
	unsigned char v4;
	unsigned int v3;
	unsigned int v2;
	int v1;
	int* v0;
	// Line 379, Address: 0x155c20, Func Offset: 0
	// Line 380, Address: 0x155c28, Func Offset: 0x8
	// Line 381, Address: 0x155c2c, Func Offset: 0xc
	// Line 383, Address: 0x155c38, Func Offset: 0x18
	// Line 385, Address: 0x155c64, Func Offset: 0x44
	// Line 387, Address: 0x155c74, Func Offset: 0x54
	// Line 389, Address: 0x155c84, Func Offset: 0x64
	// Line 391, Address: 0x155c94, Func Offset: 0x74
	// Line 393, Address: 0x155ca4, Func Offset: 0x84
	// Line 395, Address: 0x155cb4, Func Offset: 0x94
	// Line 397, Address: 0x155cc4, Func Offset: 0xa4
	// Line 399, Address: 0x155cd4, Func Offset: 0xb4
	// Line 401, Address: 0x155ce4, Func Offset: 0xc4
	// Line 403, Address: 0x155cf4, Func Offset: 0xd4
	// Line 405, Address: 0x155d04, Func Offset: 0xe4
	// Line 408, Address: 0x155d14, Func Offset: 0xf4
	// Line 413, Address: 0x155d1c, Func Offset: 0xfc
	// Line 412, Address: 0x155d20, Func Offset: 0x100
	// Line 413, Address: 0x155d24, Func Offset: 0x104
	// Line 415, Address: 0x155d44, Func Offset: 0x124
	// Line 416, Address: 0x155d5c, Func Offset: 0x13c
	// Line 417, Address: 0x155d64, Func Offset: 0x144
	// Line 416, Address: 0x155d68, Func Offset: 0x148
	// Line 417, Address: 0x155d70, Func Offset: 0x150
	// Line 421, Address: 0x155d78, Func Offset: 0x158
	// Line 422, Address: 0x155d90, Func Offset: 0x170
	// Line 423, Address: 0x155d98, Func Offset: 0x178
	// Line 422, Address: 0x155d9c, Func Offset: 0x17c
	// Line 423, Address: 0x155da4, Func Offset: 0x184
	// Line 429, Address: 0x155dac, Func Offset: 0x18c
	// Line 431, Address: 0x155db8, Func Offset: 0x198
	// Line 433, Address: 0x155dc8, Func Offset: 0x1a8
	// Line 435, Address: 0x155dd8, Func Offset: 0x1b8
	// Line 442, Address: 0x155de4, Func Offset: 0x1c4
	// Line 444, Address: 0x155df0, Func Offset: 0x1d0
	// Line 443, Address: 0x155df8, Func Offset: 0x1d8
	// Line 444, Address: 0x155e0c, Func Offset: 0x1ec
	// Line 445, Address: 0x155e10, Func Offset: 0x1f0
	// Line 447, Address: 0x155e18, Func Offset: 0x1f8
	// Line 445, Address: 0x155e24, Func Offset: 0x204
	// Line 446, Address: 0x155e28, Func Offset: 0x208
	// Line 447, Address: 0x155e34, Func Offset: 0x214
	// Line 462, Address: 0x155e3c, Func Offset: 0x21c
	// Func End, Address: 0x155e44, Func Offset: 0x224
}

// 
// Start address: 0x155e50
unsigned int bhSet()
{
	unsigned short* a1;
	unsigned int v1;
	int* a0;
	int v0;
	// Line 475, Address: 0x155e50, Func Offset: 0
	// Line 476, Address: 0x155e58, Func Offset: 0x8
	// Line 477, Address: 0x155e64, Func Offset: 0x14
	// Line 479, Address: 0x155e90, Func Offset: 0x40
	// Line 481, Address: 0x155ea0, Func Offset: 0x50
	// Line 483, Address: 0x155eb0, Func Offset: 0x60
	// Line 485, Address: 0x155ec0, Func Offset: 0x70
	// Line 487, Address: 0x155ed0, Func Offset: 0x80
	// Line 489, Address: 0x155ee0, Func Offset: 0x90
	// Line 491, Address: 0x155ef0, Func Offset: 0xa0
	// Line 493, Address: 0x155f00, Func Offset: 0xb0
	// Line 495, Address: 0x155f10, Func Offset: 0xc0
	// Line 497, Address: 0x155f20, Func Offset: 0xd0
	// Line 499, Address: 0x155f30, Func Offset: 0xe0
	// Line 502, Address: 0x155f40, Func Offset: 0xf0
	// Line 504, Address: 0x155f50, Func Offset: 0x100
	// Line 506, Address: 0x155f5c, Func Offset: 0x10c
	// Line 508, Address: 0x155f6c, Func Offset: 0x11c
	// Line 510, Address: 0x155f7c, Func Offset: 0x12c
	// Line 518, Address: 0x155f88, Func Offset: 0x138
	// Line 523, Address: 0x155f8c, Func Offset: 0x13c
	// Line 519, Address: 0x155f90, Func Offset: 0x140
	// Line 523, Address: 0x155fa0, Func Offset: 0x150
	// Line 525, Address: 0x155fcc, Func Offset: 0x17c
	// Line 526, Address: 0x155fd8, Func Offset: 0x188
	// Line 525, Address: 0x155fdc, Func Offset: 0x18c
	// Line 526, Address: 0x155fe0, Func Offset: 0x190
	// Line 528, Address: 0x155fe8, Func Offset: 0x198
	// Line 529, Address: 0x155ff8, Func Offset: 0x1a8
	// Line 528, Address: 0x155ffc, Func Offset: 0x1ac
	// Line 529, Address: 0x156000, Func Offset: 0x1b0
	// Line 531, Address: 0x156008, Func Offset: 0x1b8
	// Line 532, Address: 0x156014, Func Offset: 0x1c4
	// Line 531, Address: 0x156018, Func Offset: 0x1c8
	// Line 532, Address: 0x15601c, Func Offset: 0x1cc
	// Line 534, Address: 0x156024, Func Offset: 0x1d4
	// Line 535, Address: 0x156030, Func Offset: 0x1e0
	// Line 534, Address: 0x156034, Func Offset: 0x1e4
	// Line 535, Address: 0x156038, Func Offset: 0x1e8
	// Line 537, Address: 0x156040, Func Offset: 0x1f0
	// Line 538, Address: 0x156050, Func Offset: 0x200
	// Line 537, Address: 0x156054, Func Offset: 0x204
	// Line 538, Address: 0x156058, Func Offset: 0x208
	// Line 540, Address: 0x156060, Func Offset: 0x210
	// Line 541, Address: 0x15606c, Func Offset: 0x21c
	// Line 540, Address: 0x156070, Func Offset: 0x220
	// Line 543, Address: 0x156078, Func Offset: 0x228
	// Func End, Address: 0x156080, Func Offset: 0x230
}

// 
// Start address: 0x156080
unsigned int bhCmpB()
{
	unsigned int v3;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 554, Address: 0x156080, Func Offset: 0
	// Line 562, Address: 0x156088, Func Offset: 0x8
	// Line 554, Address: 0x15608c, Func Offset: 0xc
	// Line 555, Address: 0x156098, Func Offset: 0x18
	// Line 556, Address: 0x1560a4, Func Offset: 0x24
	// Line 557, Address: 0x1560b0, Func Offset: 0x30
	// Line 558, Address: 0x1560bc, Func Offset: 0x3c
	// Line 559, Address: 0x1560c8, Func Offset: 0x48
	// Line 560, Address: 0x1560d4, Func Offset: 0x54
	// Line 562, Address: 0x1560dc, Func Offset: 0x5c
	// Line 563, Address: 0x156154, Func Offset: 0xd4
	// Line 564, Address: 0x156160, Func Offset: 0xe0
	// Line 565, Address: 0x15616c, Func Offset: 0xec
	// Line 566, Address: 0x156174, Func Offset: 0xf4
	// Line 567, Address: 0x156180, Func Offset: 0x100
	// Line 568, Address: 0x156194, Func Offset: 0x114
	// Line 569, Address: 0x15619c, Func Offset: 0x11c
	// Line 570, Address: 0x1561a8, Func Offset: 0x128
	// Line 571, Address: 0x1561b4, Func Offset: 0x134
	// Line 572, Address: 0x1561c0, Func Offset: 0x140
	// Line 579, Address: 0x1561d8, Func Offset: 0x158
	// Line 580, Address: 0x1561fc, Func Offset: 0x17c
	// Line 581, Address: 0x156208, Func Offset: 0x188
	// Line 582, Address: 0x156210, Func Offset: 0x190
	// Line 583, Address: 0x15621c, Func Offset: 0x19c
	// Line 584, Address: 0x156224, Func Offset: 0x1a4
	// Line 585, Address: 0x156230, Func Offset: 0x1b0
	// Line 592, Address: 0x156238, Func Offset: 0x1b8
	// Func End, Address: 0x156240, Func Offset: 0x1c0
}

// 
// Start address: 0x156240
unsigned int bhCmpW()
{
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 606, Address: 0x156240, Func Offset: 0
	// Line 616, Address: 0x156248, Func Offset: 0x8
	// Line 606, Address: 0x15624c, Func Offset: 0xc
	// Line 607, Address: 0x156258, Func Offset: 0x18
	// Line 608, Address: 0x156264, Func Offset: 0x24
	// Line 609, Address: 0x156270, Func Offset: 0x30
	// Line 610, Address: 0x15627c, Func Offset: 0x3c
	// Line 611, Address: 0x156288, Func Offset: 0x48
	// Line 612, Address: 0x156294, Func Offset: 0x54
	// Line 613, Address: 0x1562a0, Func Offset: 0x60
	// Line 614, Address: 0x1562ac, Func Offset: 0x6c
	// Line 616, Address: 0x1562b4, Func Offset: 0x74
	// Line 617, Address: 0x1562e8, Func Offset: 0xa8
	// Line 618, Address: 0x1562f4, Func Offset: 0xb4
	// Line 619, Address: 0x156308, Func Offset: 0xc8
	// Line 626, Address: 0x156314, Func Offset: 0xd4
	// Line 634, Address: 0x15635c, Func Offset: 0x11c
	// Line 635, Address: 0x156380, Func Offset: 0x140
	// Line 636, Address: 0x15638c, Func Offset: 0x14c
	// Line 637, Address: 0x156394, Func Offset: 0x154
	// Line 638, Address: 0x1563a0, Func Offset: 0x160
	// Line 639, Address: 0x1563a8, Func Offset: 0x168
	// Line 640, Address: 0x1563b4, Func Offset: 0x174
	// Line 647, Address: 0x1563bc, Func Offset: 0x17c
	// Func End, Address: 0x1563c4, Func Offset: 0x184
}

// 
// Start address: 0x1563d0
unsigned int bhSv()
{
	unsigned int v1;
	unsigned int v0;
	// Line 658, Address: 0x1563d0, Func Offset: 0
	// Line 664, Address: 0x1563d8, Func Offset: 0x8
	// Line 658, Address: 0x1563dc, Func Offset: 0xc
	// Line 659, Address: 0x1563e8, Func Offset: 0x18
	// Line 660, Address: 0x1563f4, Func Offset: 0x24
	// Line 661, Address: 0x156400, Func Offset: 0x30
	// Line 662, Address: 0x15640c, Func Offset: 0x3c
	// Line 664, Address: 0x156414, Func Offset: 0x44
	// Line 665, Address: 0x1564a4, Func Offset: 0xd4
	// Line 666, Address: 0x1564b4, Func Offset: 0xe4
	// Line 667, Address: 0x1564c4, Func Offset: 0xf4
	// Line 668, Address: 0x1564d0, Func Offset: 0x100
	// Line 669, Address: 0x1564e0, Func Offset: 0x110
	// Line 671, Address: 0x1564f8, Func Offset: 0x128
	// Line 672, Address: 0x156504, Func Offset: 0x134
	// Line 673, Address: 0x156514, Func Offset: 0x144
	// Line 674, Address: 0x15651c, Func Offset: 0x14c
	// Line 675, Address: 0x15652c, Func Offset: 0x15c
	// Line 676, Address: 0x156544, Func Offset: 0x174
	// Line 677, Address: 0x15655c, Func Offset: 0x18c
	// Line 680, Address: 0x15656c, Func Offset: 0x19c
	// Line 681, Address: 0x156580, Func Offset: 0x1b0
	// Line 682, Address: 0x156588, Func Offset: 0x1b8
	// Line 689, Address: 0x15659c, Func Offset: 0x1cc
	// Line 690, Address: 0x1565a0, Func Offset: 0x1d0
	// Func End, Address: 0x1565a8, Func Offset: 0x1d8
}

// 
// Start address: 0x1565b0
unsigned int bhSvW()
{
	int v1;
	int v0;
	// Line 703, Address: 0x1565b0, Func Offset: 0
	// Line 709, Address: 0x1565b8, Func Offset: 0x8
	// Line 703, Address: 0x1565bc, Func Offset: 0xc
	// Line 704, Address: 0x1565c8, Func Offset: 0x18
	// Line 705, Address: 0x1565d4, Func Offset: 0x24
	// Line 706, Address: 0x1565e0, Func Offset: 0x30
	// Line 707, Address: 0x1565ec, Func Offset: 0x3c
	// Line 709, Address: 0x1565f4, Func Offset: 0x44
	// Line 710, Address: 0x15664c, Func Offset: 0x9c
	// Line 711, Address: 0x15665c, Func Offset: 0xac
	// Line 718, Address: 0x15666c, Func Offset: 0xbc
	// Line 719, Address: 0x156670, Func Offset: 0xc0
	// Line 720, Address: 0x1566a0, Func Offset: 0xf0
	// Line 727, Address: 0x1566a8, Func Offset: 0xf8
	// Line 728, Address: 0x1566ac, Func Offset: 0xfc
	// Line 729, Address: 0x1566dc, Func Offset: 0x12c
	// Line 736, Address: 0x1566e4, Func Offset: 0x134
	// Line 737, Address: 0x1566e8, Func Offset: 0x138
	// Line 738, Address: 0x156718, Func Offset: 0x168
	// Line 745, Address: 0x156720, Func Offset: 0x170
	// Line 746, Address: 0x156724, Func Offset: 0x174
	// Line 747, Address: 0x156754, Func Offset: 0x1a4
	// Line 754, Address: 0x15675c, Func Offset: 0x1ac
	// Line 755, Address: 0x156760, Func Offset: 0x1b0
	// Line 763, Address: 0x156794, Func Offset: 0x1e4
	// Line 764, Address: 0x156798, Func Offset: 0x1e8
	// Func End, Address: 0x1567a0, Func Offset: 0x1f0
}

// 
// Start address: 0x1567a0
unsigned int bhEvtOn()
{
	unsigned int v0;
	// Line 772, Address: 0x1567a0, Func Offset: 0
	// Line 775, Address: 0x1567a8, Func Offset: 0x8
	// Line 776, Address: 0x1567bc, Func Offset: 0x1c
	// Line 777, Address: 0x1567c8, Func Offset: 0x28
	// Line 778, Address: 0x1567d4, Func Offset: 0x34
	// Line 779, Address: 0x1567dc, Func Offset: 0x3c
	// Line 778, Address: 0x1567e0, Func Offset: 0x40
	// Line 780, Address: 0x1567ec, Func Offset: 0x4c
	// Func End, Address: 0x1567f8, Func Offset: 0x58
}

// 
// Start address: 0x156800
unsigned int bhCamSet()
{
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 788, Address: 0x156800, Func Offset: 0
	// Line 792, Address: 0x156808, Func Offset: 0x8
	// Line 801, Address: 0x156814, Func Offset: 0x14
	// Line 794, Address: 0x156818, Func Offset: 0x18
	// Line 792, Address: 0x156820, Func Offset: 0x20
	// Line 794, Address: 0x15682c, Func Offset: 0x2c
	// Line 795, Address: 0x156838, Func Offset: 0x38
	// Line 796, Address: 0x156844, Func Offset: 0x44
	// Line 797, Address: 0x156850, Func Offset: 0x50
	// Line 798, Address: 0x15685c, Func Offset: 0x5c
	// Line 799, Address: 0x156868, Func Offset: 0x68
	// Line 800, Address: 0x156874, Func Offset: 0x74
	// Line 801, Address: 0x15687c, Func Offset: 0x7c
	// Line 803, Address: 0x156894, Func Offset: 0x94
	// Line 804, Address: 0x15689c, Func Offset: 0x9c
	// Line 805, Address: 0x1568a0, Func Offset: 0xa0
	// Line 807, Address: 0x1568a8, Func Offset: 0xa8
	// Line 808, Address: 0x1568c8, Func Offset: 0xc8
	// Line 810, Address: 0x1568e8, Func Offset: 0xe8
	// Line 812, Address: 0x1568f0, Func Offset: 0xf0
	// Line 813, Address: 0x1568f8, Func Offset: 0xf8
	// Line 812, Address: 0x1568fc, Func Offset: 0xfc
	// Line 813, Address: 0x156908, Func Offset: 0x108
	// Line 815, Address: 0x156910, Func Offset: 0x110
	// Line 816, Address: 0x156928, Func Offset: 0x128
	// Line 817, Address: 0x156938, Func Offset: 0x138
	// Line 819, Address: 0x15695c, Func Offset: 0x15c
	// Line 820, Address: 0x156970, Func Offset: 0x170
	// Line 821, Address: 0x156978, Func Offset: 0x178
	// Line 837, Address: 0x156990, Func Offset: 0x190
	// Line 836, Address: 0x156994, Func Offset: 0x194
	// Line 837, Address: 0x156998, Func Offset: 0x198
	// Func End, Address: 0x1569a0, Func Offset: 0x1a0
}

// 
// Start address: 0x1569a0
unsigned int bhCamSet2()
{
	unsigned int v1;
	unsigned int v0;
	// Line 845, Address: 0x1569a0, Func Offset: 0
	// Line 850, Address: 0x1569a8, Func Offset: 0x8
	// Line 859, Address: 0x1569b4, Func Offset: 0x14
	// Line 852, Address: 0x1569b8, Func Offset: 0x18
	// Line 850, Address: 0x1569c0, Func Offset: 0x20
	// Line 852, Address: 0x1569cc, Func Offset: 0x2c
	// Line 853, Address: 0x1569d8, Func Offset: 0x38
	// Line 854, Address: 0x1569e4, Func Offset: 0x44
	// Line 855, Address: 0x1569f0, Func Offset: 0x50
	// Line 856, Address: 0x1569fc, Func Offset: 0x5c
	// Line 858, Address: 0x156a08, Func Offset: 0x68
	// Line 859, Address: 0x156a18, Func Offset: 0x78
	// Line 861, Address: 0x156a30, Func Offset: 0x90
	// Line 862, Address: 0x156a3c, Func Offset: 0x9c
	// Line 861, Address: 0x156a40, Func Offset: 0xa0
	// Line 862, Address: 0x156a48, Func Offset: 0xa8
	// Line 863, Address: 0x156a50, Func Offset: 0xb0
	// Line 862, Address: 0x156a54, Func Offset: 0xb4
	// Line 863, Address: 0x156a5c, Func Offset: 0xbc
	// Line 864, Address: 0x156a6c, Func Offset: 0xcc
	// Line 865, Address: 0x156a84, Func Offset: 0xe4
	// Line 867, Address: 0x156a8c, Func Offset: 0xec
	// Line 868, Address: 0x156a98, Func Offset: 0xf8
	// Line 867, Address: 0x156a9c, Func Offset: 0xfc
	// Line 868, Address: 0x156aa0, Func Offset: 0x100
	// Line 867, Address: 0x156aa4, Func Offset: 0x104
	// Line 868, Address: 0x156aac, Func Offset: 0x10c
	// Line 873, Address: 0x156abc, Func Offset: 0x11c
	// Line 872, Address: 0x156ac0, Func Offset: 0x120
	// Line 873, Address: 0x156ac4, Func Offset: 0x124
	// Func End, Address: 0x156acc, Func Offset: 0x12c
}

// 
// Start address: 0x156ad0
unsigned int bhCamPauseSet()
{
	unsigned int v0;
	// Line 885, Address: 0x156ad0, Func Offset: 0
	// Line 888, Address: 0x156ad8, Func Offset: 0x8
	// Line 885, Address: 0x156adc, Func Offset: 0xc
	// Line 886, Address: 0x156ae8, Func Offset: 0x18
	// Line 887, Address: 0x156af4, Func Offset: 0x24
	// Line 888, Address: 0x156afc, Func Offset: 0x2c
	// Line 889, Address: 0x156b14, Func Offset: 0x44
	// Line 890, Address: 0x156b24, Func Offset: 0x54
	// Line 895, Address: 0x156b2c, Func Offset: 0x5c
	// Line 896, Address: 0x156b30, Func Offset: 0x60
	// Func End, Address: 0x156b38, Func Offset: 0x68
}

// 
// Start address: 0x156b40
unsigned int bhMessageSet()
{
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 921, Address: 0x156b40, Func Offset: 0
	// Line 924, Address: 0x156b48, Func Offset: 0x8
	// Line 925, Address: 0x156b5c, Func Offset: 0x1c
	// Line 926, Address: 0x156b68, Func Offset: 0x28
	// Line 927, Address: 0x156b74, Func Offset: 0x34
	// Line 928, Address: 0x156b80, Func Offset: 0x40
	// Line 929, Address: 0x156b8c, Func Offset: 0x4c
	// Line 930, Address: 0x156b94, Func Offset: 0x54
	// Line 931, Address: 0x156b9c, Func Offset: 0x5c
	// Line 932, Address: 0x156ba4, Func Offset: 0x64
	// Line 934, Address: 0x156bbc, Func Offset: 0x7c
	// Line 935, Address: 0x156bc8, Func Offset: 0x88
	// Line 936, Address: 0x156bd0, Func Offset: 0x90
	// Line 938, Address: 0x156be4, Func Offset: 0xa4
	// Line 939, Address: 0x156bec, Func Offset: 0xac
	// Line 938, Address: 0x156bf0, Func Offset: 0xb0
	// Line 940, Address: 0x156bfc, Func Offset: 0xbc
	// Func End, Address: 0x156c08, Func Offset: 0xc8
}

// 
// Start address: 0x156c10
unsigned int bhBgmOn()
{
	int v1;
	int v0;
	// Line 960, Address: 0x156c10, Func Offset: 0
	// Line 963, Address: 0x156c18, Func Offset: 0x8
	// Line 964, Address: 0x156c2c, Func Offset: 0x1c
	// Line 965, Address: 0x156c38, Func Offset: 0x28
	// Line 966, Address: 0x156c44, Func Offset: 0x34
	// Line 968, Address: 0x156c50, Func Offset: 0x40
	// Line 967, Address: 0x156c5c, Func Offset: 0x4c
	// Line 971, Address: 0x156c64, Func Offset: 0x54
	// Line 967, Address: 0x156c6c, Func Offset: 0x5c
	// Line 971, Address: 0x156c70, Func Offset: 0x60
	// Line 972, Address: 0x156c78, Func Offset: 0x68
	// Line 974, Address: 0x156c80, Func Offset: 0x70
	// Line 973, Address: 0x156c84, Func Offset: 0x74
	// Line 974, Address: 0x156c88, Func Offset: 0x78
	// Func End, Address: 0x156c90, Func Offset: 0x80
}

// 
// Start address: 0x156c90
unsigned int bhBgmOff()
{
	unsigned int v0;
	// Line 982, Address: 0x156c90, Func Offset: 0
	// Line 985, Address: 0x156c98, Func Offset: 0x8
	// Line 986, Address: 0x156cac, Func Offset: 0x1c
	// Line 988, Address: 0x156cb8, Func Offset: 0x28
	// Line 987, Address: 0x156cc4, Func Offset: 0x34
	// Line 989, Address: 0x156ccc, Func Offset: 0x3c
	// Line 991, Address: 0x156cd4, Func Offset: 0x44
	// Line 990, Address: 0x156cd8, Func Offset: 0x48
	// Line 991, Address: 0x156cdc, Func Offset: 0x4c
	// Func End, Address: 0x156ce4, Func Offset: 0x54
}

// 
// Start address: 0x156cf0
unsigned int bhSeOn()
{
	BH_PWORK* e_ep;
	_anon39 pPos;
	unsigned int v4;
	unsigned int v3;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 999, Address: 0x156cf0, Func Offset: 0
	// Line 1005, Address: 0x156cf8, Func Offset: 0x8
	// Line 1017, Address: 0x156d00, Func Offset: 0x10
	// Line 1005, Address: 0x156d04, Func Offset: 0x14
	// Line 1006, Address: 0x156d10, Func Offset: 0x20
	// Line 1007, Address: 0x156d1c, Func Offset: 0x2c
	// Line 1008, Address: 0x156d28, Func Offset: 0x38
	// Line 1009, Address: 0x156d34, Func Offset: 0x44
	// Line 1010, Address: 0x156d40, Func Offset: 0x50
	// Line 1011, Address: 0x156d4c, Func Offset: 0x5c
	// Line 1012, Address: 0x156d58, Func Offset: 0x68
	// Line 1013, Address: 0x156d64, Func Offset: 0x74
	// Line 1014, Address: 0x156d70, Func Offset: 0x80
	// Line 1015, Address: 0x156d7c, Func Offset: 0x8c
	// Line 1017, Address: 0x156d84, Func Offset: 0x94
	// Line 1020, Address: 0x156da8, Func Offset: 0xb8
	// Line 1021, Address: 0x156dc0, Func Offset: 0xd0
	// Line 1022, Address: 0x156dd0, Func Offset: 0xe0
	// Line 1023, Address: 0x156ddc, Func Offset: 0xec
	// Line 1027, Address: 0x156de4, Func Offset: 0xf4
	// Line 1029, Address: 0x156e24, Func Offset: 0x134
	// Line 1030, Address: 0x156e34, Func Offset: 0x144
	// Line 1031, Address: 0x156e44, Func Offset: 0x154
	// Line 1032, Address: 0x156e50, Func Offset: 0x160
	// Line 1035, Address: 0x156e58, Func Offset: 0x168
	// Line 1037, Address: 0x156e84, Func Offset: 0x194
	// Line 1038, Address: 0x156e94, Func Offset: 0x1a4
	// Line 1039, Address: 0x156ea4, Func Offset: 0x1b4
	// Line 1042, Address: 0x156eb4, Func Offset: 0x1c4
	// Line 1045, Address: 0x156ec0, Func Offset: 0x1d0
	// Line 1044, Address: 0x156ec4, Func Offset: 0x1d4
	// Line 1045, Address: 0x156ec8, Func Offset: 0x1d8
	// Func End, Address: 0x156ed0, Func Offset: 0x1e0
}

// 
// Start address: 0x156ed0
unsigned int bhSeOff()
{
	unsigned char v0;
	// Line 1053, Address: 0x156ed0, Func Offset: 0
	// Line 1056, Address: 0x156ed8, Func Offset: 0x8
	// Line 1057, Address: 0x156eec, Func Offset: 0x1c
	// Line 1058, Address: 0x156ef8, Func Offset: 0x28
	// Line 1059, Address: 0x156f00, Func Offset: 0x30
	// Line 1062, Address: 0x156f08, Func Offset: 0x38
	// Line 1061, Address: 0x156f0c, Func Offset: 0x3c
	// Line 1062, Address: 0x156f10, Func Offset: 0x40
	// Func End, Address: 0x156f18, Func Offset: 0x48
}

// 
// Start address: 0x156f20
unsigned int bhBGSeOn()
{
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 1070, Address: 0x156f20, Func Offset: 0
	// Line 1074, Address: 0x156f28, Func Offset: 0x8
	// Line 1075, Address: 0x156f3c, Func Offset: 0x1c
	// Line 1076, Address: 0x156f48, Func Offset: 0x28
	// Line 1077, Address: 0x156f54, Func Offset: 0x34
	// Line 1078, Address: 0x156f60, Func Offset: 0x40
	// Line 1079, Address: 0x156f6c, Func Offset: 0x4c
	// Line 1081, Address: 0x156f78, Func Offset: 0x58
	// Line 1080, Address: 0x156f84, Func Offset: 0x64
	// Line 1082, Address: 0x156f90, Func Offset: 0x70
	// Line 1085, Address: 0x156f9c, Func Offset: 0x7c
	// Line 1084, Address: 0x156fa0, Func Offset: 0x80
	// Line 1085, Address: 0x156fa4, Func Offset: 0x84
	// Func End, Address: 0x156fac, Func Offset: 0x8c
}

// 
// Start address: 0x156fb0
unsigned int bhBGSeOff()
{
	unsigned int v2;
	unsigned char v0;
	// Line 1093, Address: 0x156fb0, Func Offset: 0
	// Line 1097, Address: 0x156fb8, Func Offset: 0x8
	// Line 1098, Address: 0x156fcc, Func Offset: 0x1c
	// Line 1099, Address: 0x156fd8, Func Offset: 0x28
	// Line 1100, Address: 0x156fe4, Func Offset: 0x34
	// Line 1102, Address: 0x156ff0, Func Offset: 0x40
	// Line 1101, Address: 0x156ffc, Func Offset: 0x4c
	// Line 1103, Address: 0x157008, Func Offset: 0x58
	// Line 1106, Address: 0x157014, Func Offset: 0x64
	// Line 1105, Address: 0x157018, Func Offset: 0x68
	// Line 1106, Address: 0x15701c, Func Offset: 0x6c
	// Func End, Address: 0x157024, Func Offset: 0x74
}

// 
// Start address: 0x157030
unsigned int bhUseItemCheck()
{
	unsigned char v0;
	// Line 1117, Address: 0x157030, Func Offset: 0
	// Line 1123, Address: 0x157038, Func Offset: 0x8
	// Line 1117, Address: 0x157040, Func Offset: 0x10
	// Line 1118, Address: 0x15704c, Func Offset: 0x1c
	// Line 1119, Address: 0x157058, Func Offset: 0x28
	// Line 1123, Address: 0x157064, Func Offset: 0x34
	// Line 1126, Address: 0x157094, Func Offset: 0x64
	// Func End, Address: 0x15709c, Func Offset: 0x6c
}

// 
// Start address: 0x1570a0
unsigned int bhArmsItemCheck()
{
	int v0;
	// Line 1137, Address: 0x1570a0, Func Offset: 0
	// Line 1140, Address: 0x1570a8, Func Offset: 0x8
	// Line 1137, Address: 0x1570b0, Func Offset: 0x10
	// Line 1138, Address: 0x1570bc, Func Offset: 0x1c
	// Line 1139, Address: 0x1570c8, Func Offset: 0x28
	// Line 1140, Address: 0x1570d4, Func Offset: 0x34
	// Line 1141, Address: 0x1570dc, Func Offset: 0x3c
	// Func End, Address: 0x1570e4, Func Offset: 0x44
}

// 
// Start address: 0x1570f0
unsigned int bhArmsItemChange()
{
	int v0;
	// Line 1152, Address: 0x1570f0, Func Offset: 0
	// Line 1158, Address: 0x1570f8, Func Offset: 0x8
	// Line 1160, Address: 0x1570fc, Func Offset: 0xc
	// Line 1156, Address: 0x157100, Func Offset: 0x10
	// Line 1152, Address: 0x157108, Func Offset: 0x18
	// Line 1153, Address: 0x157114, Func Offset: 0x24
	// Line 1154, Address: 0x157120, Func Offset: 0x30
	// Line 1156, Address: 0x15712c, Func Offset: 0x3c
	// Line 1157, Address: 0x157130, Func Offset: 0x40
	// Line 1158, Address: 0x15713c, Func Offset: 0x4c
	// Line 1157, Address: 0x157140, Func Offset: 0x50
	// Line 1158, Address: 0x157148, Func Offset: 0x58
	// Line 1161, Address: 0x157158, Func Offset: 0x68
	// Func End, Address: 0x157160, Func Offset: 0x70
}

// 
// Start address: 0x157160
unsigned int bhPlItemLost()
{
	int v0;
	unsigned int cnt;
	// Line 1173, Address: 0x157160, Func Offset: 0
	// Line 1181, Address: 0x157168, Func Offset: 0x8
	// Line 1173, Address: 0x157170, Func Offset: 0x10
	// Line 1174, Address: 0x15717c, Func Offset: 0x1c
	// Line 1175, Address: 0x157188, Func Offset: 0x28
	// Line 1181, Address: 0x157194, Func Offset: 0x34
	// Line 1182, Address: 0x1571b0, Func Offset: 0x50
	// Line 1183, Address: 0x1571c4, Func Offset: 0x64
	// Line 1184, Address: 0x1571d0, Func Offset: 0x70
	// Line 1185, Address: 0x15720c, Func Offset: 0xac
	// Line 1187, Address: 0x157214, Func Offset: 0xb4
	// Line 1188, Address: 0x15721c, Func Offset: 0xbc
	// Line 1191, Address: 0x157228, Func Offset: 0xc8
	// Line 1192, Address: 0x157230, Func Offset: 0xd0
	// Line 1193, Address: 0x157238, Func Offset: 0xd8
	// Line 1192, Address: 0x15723c, Func Offset: 0xdc
	// Line 1194, Address: 0x157240, Func Offset: 0xe0
	// Line 1195, Address: 0x157260, Func Offset: 0x100
	// Line 1197, Address: 0x157268, Func Offset: 0x108
	// Line 1199, Address: 0x15727c, Func Offset: 0x11c
	// Func End, Address: 0x157284, Func Offset: 0x124
}

// 
// Start address: 0x157290
unsigned int bhUseItemClear()
{
	// Line 1208, Address: 0x157290, Func Offset: 0
	// Line 1209, Address: 0x157298, Func Offset: 0x8
	// Line 1210, Address: 0x15729c, Func Offset: 0xc
	// Line 1209, Address: 0x1572a0, Func Offset: 0x10
	// Line 1208, Address: 0x1572a8, Func Offset: 0x18
	// Line 1209, Address: 0x1572b4, Func Offset: 0x24
	// Line 1211, Address: 0x1572bc, Func Offset: 0x2c
	// Func End, Address: 0x1572c4, Func Offset: 0x34
}

// 
// Start address: 0x1572d0
unsigned int bhPlItemCheck()
{
	unsigned char v0;
	unsigned int cnt;
	// Line 1223, Address: 0x1572d0, Func Offset: 0
	// Line 1227, Address: 0x1572d8, Func Offset: 0x8
	// Line 1223, Address: 0x1572e0, Func Offset: 0x10
	// Line 1224, Address: 0x1572ec, Func Offset: 0x1c
	// Line 1225, Address: 0x1572f8, Func Offset: 0x28
	// Line 1227, Address: 0x157304, Func Offset: 0x34
	// Line 1228, Address: 0x157320, Func Offset: 0x50
	// Line 1229, Address: 0x157334, Func Offset: 0x64
	// Line 1230, Address: 0x157354, Func Offset: 0x84
	// Line 1231, Address: 0x15735c, Func Offset: 0x8c
	// Line 1234, Address: 0x15736c, Func Offset: 0x9c
	// Line 1236, Address: 0x15737c, Func Offset: 0xac
	// Line 1237, Address: 0x15738c, Func Offset: 0xbc
	// Line 1238, Address: 0x157390, Func Offset: 0xc0
	// Func End, Address: 0x157398, Func Offset: 0xc8
}

// 
// Start address: 0x1573a0
unsigned int bhMovieStart()
{
	unsigned int v0;
	// Line 1249, Address: 0x1573a0, Func Offset: 0
	// Line 1256, Address: 0x1573a8, Func Offset: 0x8
	// Line 1261, Address: 0x1573ac, Func Offset: 0xc
	// Line 1255, Address: 0x1573b0, Func Offset: 0x10
	// Line 1249, Address: 0x1573b8, Func Offset: 0x18
	// Line 1250, Address: 0x1573c4, Func Offset: 0x24
	// Line 1251, Address: 0x1573d0, Func Offset: 0x30
	// Line 1253, Address: 0x1573dc, Func Offset: 0x3c
	// Line 1255, Address: 0x1573f0, Func Offset: 0x50
	// Line 1256, Address: 0x1573fc, Func Offset: 0x5c
	// Line 1262, Address: 0x15740c, Func Offset: 0x6c
	// Func End, Address: 0x157414, Func Offset: 0x74
}

// 
// Start address: 0x157420
unsigned int bhMovieStop()
{
	// Line 1271, Address: 0x157420, Func Offset: 0
	// Line 1272, Address: 0x157428, Func Offset: 0x8
	// Line 1276, Address: 0x157430, Func Offset: 0x10
	// Line 1272, Address: 0x157434, Func Offset: 0x14
	// Line 1271, Address: 0x15743c, Func Offset: 0x1c
	// Line 1272, Address: 0x157448, Func Offset: 0x28
	// Line 1277, Address: 0x157450, Func Offset: 0x30
	// Func End, Address: 0x157458, Func Offset: 0x38
}

// 
// Start address: 0x157460
unsigned int bhVoiceOn()
{
	BH_PWORK* e_ep;
	_anon39 pPos;
	unsigned int v4;
	unsigned int v3;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 1285, Address: 0x157460, Func Offset: 0
	// Line 1291, Address: 0x15747c, Func Offset: 0x1c
	// Line 1304, Address: 0x157484, Func Offset: 0x24
	// Line 1291, Address: 0x15748c, Func Offset: 0x2c
	// Line 1292, Address: 0x157498, Func Offset: 0x38
	// Line 1304, Address: 0x1574a0, Func Offset: 0x40
	// Line 1292, Address: 0x1574a4, Func Offset: 0x44
	// Line 1293, Address: 0x1574a8, Func Offset: 0x48
	// Line 1294, Address: 0x1574b4, Func Offset: 0x54
	// Line 1295, Address: 0x1574c0, Func Offset: 0x60
	// Line 1296, Address: 0x1574cc, Func Offset: 0x6c
	// Line 1297, Address: 0x1574d8, Func Offset: 0x78
	// Line 1298, Address: 0x1574e4, Func Offset: 0x84
	// Line 1300, Address: 0x1574f0, Func Offset: 0x90
	// Line 1299, Address: 0x1574fc, Func Offset: 0x9c
	// Line 1301, Address: 0x157504, Func Offset: 0xa4
	// Line 1302, Address: 0x157510, Func Offset: 0xb0
	// Line 1304, Address: 0x15751c, Func Offset: 0xbc
	// Line 1305, Address: 0x157528, Func Offset: 0xc8
	// Line 1306, Address: 0x15752c, Func Offset: 0xcc
	// Line 1309, Address: 0x157534, Func Offset: 0xd4
	// Line 1312, Address: 0x15755c, Func Offset: 0xfc
	// Line 1313, Address: 0x157574, Func Offset: 0x114
	// Line 1314, Address: 0x157584, Func Offset: 0x124
	// Line 1315, Address: 0x157590, Func Offset: 0x130
	// Line 1319, Address: 0x157598, Func Offset: 0x138
	// Line 1320, Address: 0x1575d8, Func Offset: 0x178
	// Line 1321, Address: 0x1575e8, Func Offset: 0x188
	// Line 1322, Address: 0x1575f8, Func Offset: 0x198
	// Line 1323, Address: 0x157604, Func Offset: 0x1a4
	// Line 1326, Address: 0x15760c, Func Offset: 0x1ac
	// Line 1327, Address: 0x157638, Func Offset: 0x1d8
	// Line 1328, Address: 0x157648, Func Offset: 0x1e8
	// Line 1329, Address: 0x157658, Func Offset: 0x1f8
	// Line 1332, Address: 0x157668, Func Offset: 0x208
	// Line 1341, Address: 0x157674, Func Offset: 0x214
	// Line 1344, Address: 0x15768c, Func Offset: 0x22c
	// Line 1343, Address: 0x1576a4, Func Offset: 0x244
	// Line 1344, Address: 0x1576a8, Func Offset: 0x248
	// Func End, Address: 0x1576b0, Func Offset: 0x250
}

// 
// Start address: 0x1576b0
unsigned int bhVoiceOff()
{
	unsigned int v0;
	// Line 1352, Address: 0x1576b0, Func Offset: 0
	// Line 1355, Address: 0x1576b8, Func Offset: 0x8
	// Line 1360, Address: 0x1576c0, Func Offset: 0x10
	// Line 1355, Address: 0x1576c8, Func Offset: 0x18
	// Line 1356, Address: 0x1576d4, Func Offset: 0x24
	// Line 1358, Address: 0x1576e0, Func Offset: 0x30
	// Line 1360, Address: 0x1576ec, Func Offset: 0x3c
	// Line 1357, Address: 0x1576f0, Func Offset: 0x40
	// Line 1361, Address: 0x1576f8, Func Offset: 0x48
	// Line 1364, Address: 0x157700, Func Offset: 0x50
	// Line 1363, Address: 0x157704, Func Offset: 0x54
	// Line 1364, Address: 0x157708, Func Offset: 0x58
	// Func End, Address: 0x157710, Func Offset: 0x60
}

// 
// Start address: 0x157710
unsigned int bhAdxCk()
{
	unsigned int ret;
	unsigned int v1;
	// Line 1375, Address: 0x157710, Func Offset: 0
	// Line 1377, Address: 0x157724, Func Offset: 0x14
	// Line 1378, Address: 0x157738, Func Offset: 0x28
	// Line 1379, Address: 0x157744, Func Offset: 0x34
	// Line 1380, Address: 0x157750, Func Offset: 0x40
	// Line 1382, Address: 0x157760, Func Offset: 0x50
	// Func End, Address: 0x157768, Func Offset: 0x58
}

// 
// Start address: 0x157770
unsigned int bhAdxTimeCk()
{
	unsigned int ret;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 1393, Address: 0x157770, Func Offset: 0
	// Line 1396, Address: 0x157780, Func Offset: 0x10
	// Line 1397, Address: 0x157794, Func Offset: 0x24
	// Line 1398, Address: 0x1577a0, Func Offset: 0x30
	// Line 1399, Address: 0x1577ac, Func Offset: 0x3c
	// Line 1400, Address: 0x1577b8, Func Offset: 0x48
	// Line 1401, Address: 0x1577c4, Func Offset: 0x54
	// Line 1402, Address: 0x1577d0, Func Offset: 0x60
	// Line 1404, Address: 0x1577d8, Func Offset: 0x68
	// Line 1406, Address: 0x1577e0, Func Offset: 0x70
	// Line 1408, Address: 0x157808, Func Offset: 0x98
	// Line 1409, Address: 0x157818, Func Offset: 0xa8
	// Line 1410, Address: 0x15781c, Func Offset: 0xac
	// Line 1412, Address: 0x157824, Func Offset: 0xb4
	// Line 1413, Address: 0x157828, Func Offset: 0xb8
	// Line 1414, Address: 0x15782c, Func Offset: 0xbc
	// Line 1416, Address: 0x157834, Func Offset: 0xc4
	// Line 1417, Address: 0x157848, Func Offset: 0xd8
	// Line 1418, Address: 0x15784c, Func Offset: 0xdc
	// Line 1420, Address: 0x157854, Func Offset: 0xe4
	// Line 1421, Address: 0x157858, Func Offset: 0xe8
	// Line 1422, Address: 0x15785c, Func Offset: 0xec
	// Line 1424, Address: 0x157864, Func Offset: 0xf4
	// Line 1425, Address: 0x157868, Func Offset: 0xf8
	// Line 1426, Address: 0x15786c, Func Offset: 0xfc
	// Line 1428, Address: 0x157874, Func Offset: 0x104
	// Line 1429, Address: 0x157884, Func Offset: 0x114
	// Line 1433, Address: 0x157888, Func Offset: 0x118
	// Func End, Address: 0x15789c, Func Offset: 0x12c
}

// 
// Start address: 0x1578a0
unsigned int bhCineSet()
{
	unsigned int v0;
	// Line 1474, Address: 0x1578a0, Func Offset: 0
	// Line 1475, Address: 0x1578b4, Func Offset: 0x14
	// Line 1476, Address: 0x1578c0, Func Offset: 0x20
	// Line 1477, Address: 0x1578cc, Func Offset: 0x2c
	// Line 1479, Address: 0x1578f4, Func Offset: 0x54
	// Line 1480, Address: 0x157904, Func Offset: 0x64
	// Line 1479, Address: 0x157908, Func Offset: 0x68
	// Line 1480, Address: 0x157910, Func Offset: 0x70
	// Line 1481, Address: 0x157918, Func Offset: 0x78
	// Line 1480, Address: 0x15791c, Func Offset: 0x7c
	// Line 1481, Address: 0x157924, Func Offset: 0x84
	// Line 1482, Address: 0x157930, Func Offset: 0x90
	// Line 1484, Address: 0x157938, Func Offset: 0x98
	// Line 1486, Address: 0x157950, Func Offset: 0xb0
	// Line 1487, Address: 0x15795c, Func Offset: 0xbc
	// Line 1489, Address: 0x157970, Func Offset: 0xd0
	// Line 1491, Address: 0x15797c, Func Offset: 0xdc
	// Line 1489, Address: 0x157980, Func Offset: 0xe0
	// Line 1490, Address: 0x157984, Func Offset: 0xe4
	// Line 1489, Address: 0x157988, Func Offset: 0xe8
	// Line 1490, Address: 0x157990, Func Offset: 0xf0
	// Line 1491, Address: 0x157998, Func Offset: 0xf8
	// Line 1490, Address: 0x15799c, Func Offset: 0xfc
	// Line 1491, Address: 0x1579a4, Func Offset: 0x104
	// Line 1492, Address: 0x1579b0, Func Offset: 0x110
	// Line 1494, Address: 0x1579b8, Func Offset: 0x118
	// Line 1495, Address: 0x1579c8, Func Offset: 0x128
	// Line 1494, Address: 0x1579cc, Func Offset: 0x12c
	// Line 1495, Address: 0x1579d4, Func Offset: 0x134
	// Line 1496, Address: 0x1579dc, Func Offset: 0x13c
	// Line 1495, Address: 0x1579e0, Func Offset: 0x140
	// Line 1496, Address: 0x1579e8, Func Offset: 0x148
	// Line 1497, Address: 0x1579f8, Func Offset: 0x158
	// Line 1498, Address: 0x157a08, Func Offset: 0x168
	// Line 1500, Address: 0x157a10, Func Offset: 0x170
	// Line 1501, Address: 0x157a1c, Func Offset: 0x17c
	// Line 1500, Address: 0x157a20, Func Offset: 0x180
	// Line 1501, Address: 0x157a28, Func Offset: 0x188
	// Line 1502, Address: 0x157a30, Func Offset: 0x190
	// Line 1501, Address: 0x157a34, Func Offset: 0x194
	// Line 1502, Address: 0x157a3c, Func Offset: 0x19c
	// Line 1503, Address: 0x157a48, Func Offset: 0x1a8
	// Line 1505, Address: 0x157a50, Func Offset: 0x1b0
	// Line 1506, Address: 0x157a5c, Func Offset: 0x1bc
	// Line 1508, Address: 0x157a60, Func Offset: 0x1c0
	// Line 1505, Address: 0x157a64, Func Offset: 0x1c4
	// Line 1506, Address: 0x157a68, Func Offset: 0x1c8
	// Line 1505, Address: 0x157a6c, Func Offset: 0x1cc
	// Line 1506, Address: 0x157a74, Func Offset: 0x1d4
	// Line 1507, Address: 0x157a7c, Func Offset: 0x1dc
	// Line 1506, Address: 0x157a80, Func Offset: 0x1e0
	// Line 1507, Address: 0x157a88, Func Offset: 0x1e8
	// Line 1508, Address: 0x157a90, Func Offset: 0x1f0
	// Line 1507, Address: 0x157a94, Func Offset: 0x1f4
	// Line 1508, Address: 0x157a9c, Func Offset: 0x1fc
	// Line 1509, Address: 0x157aa4, Func Offset: 0x204
	// Line 1508, Address: 0x157aa8, Func Offset: 0x208
	// Line 1509, Address: 0x157ab0, Func Offset: 0x210
	// Line 1510, Address: 0x157ac0, Func Offset: 0x220
	// Line 1511, Address: 0x157ad0, Func Offset: 0x230
	// Line 1513, Address: 0x157ad8, Func Offset: 0x238
	// Line 1514, Address: 0x157ae8, Func Offset: 0x248
	// Line 1513, Address: 0x157aec, Func Offset: 0x24c
	// Line 1514, Address: 0x157af4, Func Offset: 0x254
	// Line 1515, Address: 0x157afc, Func Offset: 0x25c
	// Line 1514, Address: 0x157b00, Func Offset: 0x260
	// Line 1515, Address: 0x157b08, Func Offset: 0x268
	// Line 1516, Address: 0x157b10, Func Offset: 0x270
	// Line 1515, Address: 0x157b14, Func Offset: 0x274
	// Line 1516, Address: 0x157b1c, Func Offset: 0x27c
	// Line 1517, Address: 0x157b2c, Func Offset: 0x28c
	// Line 1520, Address: 0x157b40, Func Offset: 0x2a0
	// Line 1521, Address: 0x157b44, Func Offset: 0x2a4
	// Func End, Address: 0x157b4c, Func Offset: 0x2ac
}

// 
// Start address: 0x157b50
unsigned int bhWalAtariSet()
{
	_anon6* e_walp;
	unsigned int v1;
	unsigned int v0;
	// Line 1534, Address: 0x157b50, Func Offset: 0
	// Line 1544, Address: 0x157b58, Func Offset: 0x8
	// Line 1534, Address: 0x157b60, Func Offset: 0x10
	// Line 1535, Address: 0x157b6c, Func Offset: 0x1c
	// Line 1536, Address: 0x157b78, Func Offset: 0x28
	// Line 1537, Address: 0x157b84, Func Offset: 0x34
	// Line 1545, Address: 0x157b8c, Func Offset: 0x3c
	// Line 1537, Address: 0x157b98, Func Offset: 0x48
	// Line 1538, Address: 0x157b9c, Func Offset: 0x4c
	// Line 1544, Address: 0x157ba8, Func Offset: 0x58
	// Line 1547, Address: 0x157bac, Func Offset: 0x5c
	// Line 1548, Address: 0x157bb4, Func Offset: 0x64
	// Line 1549, Address: 0x157bbc, Func Offset: 0x6c
	// Line 1550, Address: 0x157bc4, Func Offset: 0x74
	// Line 1554, Address: 0x157bd0, Func Offset: 0x80
	// Func End, Address: 0x157bd8, Func Offset: 0x88
}

// 
// Start address: 0x157be0
unsigned int bhEtcAtariSet()
{
	_anon6* e_etcp;
	unsigned int v1;
	unsigned int v0;
	// Line 1567, Address: 0x157be0, Func Offset: 0
	// Line 1577, Address: 0x157be8, Func Offset: 0x8
	// Line 1567, Address: 0x157bf0, Func Offset: 0x10
	// Line 1568, Address: 0x157bfc, Func Offset: 0x1c
	// Line 1569, Address: 0x157c08, Func Offset: 0x28
	// Line 1570, Address: 0x157c14, Func Offset: 0x34
	// Line 1578, Address: 0x157c1c, Func Offset: 0x3c
	// Line 1570, Address: 0x157c28, Func Offset: 0x48
	// Line 1571, Address: 0x157c2c, Func Offset: 0x4c
	// Line 1577, Address: 0x157c38, Func Offset: 0x58
	// Line 1580, Address: 0x157c3c, Func Offset: 0x5c
	// Line 1581, Address: 0x157c44, Func Offset: 0x64
	// Line 1582, Address: 0x157c4c, Func Offset: 0x6c
	// Line 1583, Address: 0x157c54, Func Offset: 0x74
	// Line 1587, Address: 0x157c60, Func Offset: 0x80
	// Func End, Address: 0x157c68, Func Offset: 0x88
}

// 
// Start address: 0x157c70
unsigned int bhFlrAtariSet()
{
	_anon6* e_flrp;
	unsigned int v1;
	unsigned int v0;
	// Line 1600, Address: 0x157c70, Func Offset: 0
	// Line 1610, Address: 0x157c78, Func Offset: 0x8
	// Line 1600, Address: 0x157c80, Func Offset: 0x10
	// Line 1601, Address: 0x157c8c, Func Offset: 0x1c
	// Line 1602, Address: 0x157c98, Func Offset: 0x28
	// Line 1603, Address: 0x157ca4, Func Offset: 0x34
	// Line 1611, Address: 0x157cac, Func Offset: 0x3c
	// Line 1603, Address: 0x157cb8, Func Offset: 0x48
	// Line 1604, Address: 0x157cbc, Func Offset: 0x4c
	// Line 1610, Address: 0x157cc8, Func Offset: 0x58
	// Line 1613, Address: 0x157ccc, Func Offset: 0x5c
	// Line 1614, Address: 0x157cd4, Func Offset: 0x64
	// Line 1615, Address: 0x157cdc, Func Offset: 0x6c
	// Line 1616, Address: 0x157ce4, Func Offset: 0x74
	// Line 1620, Address: 0x157cf0, Func Offset: 0x80
	// Func End, Address: 0x157cf8, Func Offset: 0x88
}

// 
// Start address: 0x157d00
unsigned int bhSubStatus()
{
	// Line 1629, Address: 0x157d00, Func Offset: 0
	// Line 1638, Address: 0x157d08, Func Offset: 0x8
	// Line 1637, Address: 0x157d0c, Func Offset: 0xc
	// Line 1629, Address: 0x157d14, Func Offset: 0x14
	// Line 1637, Address: 0x157d20, Func Offset: 0x20
	// Line 1639, Address: 0x157d28, Func Offset: 0x28
	// Func End, Address: 0x157d30, Func Offset: 0x30
}

// 
// Start address: 0x157d30
unsigned int bhMotionPauseSet()
{
	unsigned int v0;
	// Line 1650, Address: 0x157d30, Func Offset: 0
	// Line 1658, Address: 0x157d38, Func Offset: 0x8
	// Line 1650, Address: 0x157d3c, Func Offset: 0xc
	// Line 1651, Address: 0x157d48, Func Offset: 0x18
	// Line 1652, Address: 0x157d54, Func Offset: 0x24
	// Line 1658, Address: 0x157d5c, Func Offset: 0x2c
	// Line 1660, Address: 0x157d74, Func Offset: 0x44
	// Line 1661, Address: 0x157d84, Func Offset: 0x54
	// Line 1660, Address: 0x157d88, Func Offset: 0x58
	// Line 1661, Address: 0x157d8c, Func Offset: 0x5c
	// Line 1662, Address: 0x157da0, Func Offset: 0x70
	// Line 1664, Address: 0x157da4, Func Offset: 0x74
	// Line 1666, Address: 0x157dac, Func Offset: 0x7c
	// Line 1667, Address: 0x157db8, Func Offset: 0x88
	// Line 1666, Address: 0x157dbc, Func Offset: 0x8c
	// Line 1667, Address: 0x157dc0, Func Offset: 0x90
	// Line 1668, Address: 0x157dd4, Func Offset: 0xa4
	// Line 1672, Address: 0x157ddc, Func Offset: 0xac
	// Line 1673, Address: 0x157de0, Func Offset: 0xb0
	// Func End, Address: 0x157de8, Func Offset: 0xb8
}

// 
// Start address: 0x157df0
unsigned int bhMotionPauseSetPly()
{
	unsigned int v0;
	// Line 1683, Address: 0x157df0, Func Offset: 0
	// Line 1686, Address: 0x157df8, Func Offset: 0x8
	// Line 1683, Address: 0x157dfc, Func Offset: 0xc
	// Line 1684, Address: 0x157e08, Func Offset: 0x18
	// Line 1685, Address: 0x157e14, Func Offset: 0x24
	// Line 1686, Address: 0x157e1c, Func Offset: 0x2c
	// Line 1687, Address: 0x157e34, Func Offset: 0x44
	// Line 1688, Address: 0x157e50, Func Offset: 0x60
	// Line 1690, Address: 0x157e64, Func Offset: 0x74
	// Line 1691, Address: 0x157e68, Func Offset: 0x78
	// Func End, Address: 0x157e70, Func Offset: 0x80
}

// 
// Start address: 0x157e70
unsigned int bhInitMotionPause()
{
	BH_PWORK* e_ep;
	unsigned int v0;
	// Line 1704, Address: 0x157e70, Func Offset: 0
	// Line 1713, Address: 0x157e78, Func Offset: 0x8
	// Line 1715, Address: 0x157e80, Func Offset: 0x10
	// Line 1713, Address: 0x157e84, Func Offset: 0x14
	// Line 1704, Address: 0x157e8c, Func Offset: 0x1c
	// Line 1716, Address: 0x157e90, Func Offset: 0x20
	// Line 1704, Address: 0x157e94, Func Offset: 0x24
	// Line 1705, Address: 0x157e9c, Func Offset: 0x2c
	// Line 1718, Address: 0x157ea4, Func Offset: 0x34
	// Line 1705, Address: 0x157ea8, Func Offset: 0x38
	// Line 1706, Address: 0x157eac, Func Offset: 0x3c
	// Line 1713, Address: 0x157eb8, Func Offset: 0x48
	// Line 1715, Address: 0x157ee8, Func Offset: 0x78
	// Line 1716, Address: 0x157eec, Func Offset: 0x7c
	// Line 1718, Address: 0x157ef0, Func Offset: 0x80
	// Line 1719, Address: 0x157efc, Func Offset: 0x8c
	// Line 1720, Address: 0x157f04, Func Offset: 0x94
	// Line 1723, Address: 0x157f0c, Func Offset: 0x9c
	// Line 1724, Address: 0x157f10, Func Offset: 0xa0
	// Func End, Address: 0x157f18, Func Offset: 0xa8
}

// 
// Start address: 0x157f20
unsigned int bhInitMotionPauseEx()
{
	BH_PWORK* e_ep;
	unsigned int v1;
	unsigned int v0;
	// Line 1737, Address: 0x157f20, Func Offset: 0
	// Line 1748, Address: 0x157f28, Func Offset: 0x8
	// Line 1750, Address: 0x157f30, Func Offset: 0x10
	// Line 1748, Address: 0x157f34, Func Offset: 0x14
	// Line 1737, Address: 0x157f3c, Func Offset: 0x1c
	// Line 1751, Address: 0x157f40, Func Offset: 0x20
	// Line 1737, Address: 0x157f44, Func Offset: 0x24
	// Line 1738, Address: 0x157f4c, Func Offset: 0x2c
	// Line 1757, Address: 0x157f54, Func Offset: 0x34
	// Line 1738, Address: 0x157f58, Func Offset: 0x38
	// Line 1739, Address: 0x157f5c, Func Offset: 0x3c
	// Line 1740, Address: 0x157f68, Func Offset: 0x48
	// Line 1748, Address: 0x157f70, Func Offset: 0x50
	// Line 1740, Address: 0x157f7c, Func Offset: 0x5c
	// Line 1741, Address: 0x157f80, Func Offset: 0x60
	// Line 1748, Address: 0x157f8c, Func Offset: 0x6c
	// Line 1755, Address: 0x157f90, Func Offset: 0x70
	// Line 1748, Address: 0x157f94, Func Offset: 0x74
	// Line 1750, Address: 0x157fb4, Func Offset: 0x94
	// Line 1751, Address: 0x157fb8, Func Offset: 0x98
	// Line 1752, Address: 0x157fbc, Func Offset: 0x9c
	// Line 1753, Address: 0x157fc0, Func Offset: 0xa0
	// Line 1755, Address: 0x157fc4, Func Offset: 0xa4
	// Line 1757, Address: 0x157fd8, Func Offset: 0xb8
	// Line 1758, Address: 0x157fe4, Func Offset: 0xc4
	// Line 1759, Address: 0x157fec, Func Offset: 0xcc
	// Line 1760, Address: 0x157ff4, Func Offset: 0xd4
	// Line 1761, Address: 0x157ffc, Func Offset: 0xdc
	// Line 1764, Address: 0x158004, Func Offset: 0xe4
	// Line 1765, Address: 0x158008, Func Offset: 0xe8
	// Func End, Address: 0x158010, Func Offset: 0xf0
}

// 
// Start address: 0x158010
unsigned int bhEffectSet()
{
	_anon53 pnt;
	unsigned int v1;
	unsigned int v0;
	// Line 1773, Address: 0x158010, Func Offset: 0
	// Line 1778, Address: 0x158018, Func Offset: 0x8
	// Line 1784, Address: 0x158020, Func Offset: 0x10
	// Line 1778, Address: 0x158024, Func Offset: 0x14
	// Line 1779, Address: 0x158030, Func Offset: 0x20
	// Line 1780, Address: 0x15803c, Func Offset: 0x2c
	// Line 1781, Address: 0x158048, Func Offset: 0x38
	// Line 1782, Address: 0x158054, Func Offset: 0x44
	// Line 1783, Address: 0x158060, Func Offset: 0x50
	// Line 1784, Address: 0x158070, Func Offset: 0x60
	// Line 1786, Address: 0x158088, Func Offset: 0x78
	// Line 1787, Address: 0x158094, Func Offset: 0x84
	// Line 1788, Address: 0x15809c, Func Offset: 0x8c
	// Line 1789, Address: 0x1580b8, Func Offset: 0xa8
	// Line 1791, Address: 0x1580c0, Func Offset: 0xb0
	// Line 1792, Address: 0x1580cc, Func Offset: 0xbc
	// Line 1793, Address: 0x1580d4, Func Offset: 0xc4
	// Line 1798, Address: 0x1580f4, Func Offset: 0xe4
	// Line 1797, Address: 0x1580f8, Func Offset: 0xe8
	// Line 1798, Address: 0x1580fc, Func Offset: 0xec
	// Func End, Address: 0x158104, Func Offset: 0xf4
}

// 
// Start address: 0x158110
unsigned int bhEffectSensyaSet()
{
	_anon53 pnt;
	// Line 1806, Address: 0x158110, Func Offset: 0
	// Line 1811, Address: 0x158118, Func Offset: 0x8
	// Line 1814, Address: 0x158120, Func Offset: 0x10
	// Line 1815, Address: 0x15812c, Func Offset: 0x1c
	// Line 1816, Address: 0x158134, Func Offset: 0x24
	// Line 1811, Address: 0x15813c, Func Offset: 0x2c
	// Line 1815, Address: 0x158140, Func Offset: 0x30
	// Line 1816, Address: 0x158144, Func Offset: 0x34
	// Line 1811, Address: 0x158148, Func Offset: 0x38
	// Line 1812, Address: 0x158150, Func Offset: 0x40
	// Line 1816, Address: 0x158158, Func Offset: 0x48
	// Line 1812, Address: 0x15815c, Func Offset: 0x4c
	// Line 1816, Address: 0x158168, Func Offset: 0x58
	// Line 1819, Address: 0x158180, Func Offset: 0x70
	// Line 1818, Address: 0x158184, Func Offset: 0x74
	// Line 1819, Address: 0x158188, Func Offset: 0x78
	// Func End, Address: 0x158190, Func Offset: 0x80
}

// 
// Start address: 0x158190
unsigned int bhEffectKokuenSet()
{
	int v0;
	// Line 1827, Address: 0x158190, Func Offset: 0
	// Line 1831, Address: 0x158198, Func Offset: 0x8
	// Line 1832, Address: 0x1581a4, Func Offset: 0x14
	// Line 1836, Address: 0x1581a8, Func Offset: 0x18
	// Line 1831, Address: 0x1581ac, Func Offset: 0x1c
	// Line 1832, Address: 0x1581b8, Func Offset: 0x28
	// Line 1833, Address: 0x1581cc, Func Offset: 0x3c
	// Line 1834, Address: 0x1581e0, Func Offset: 0x50
	// Line 1835, Address: 0x1581f4, Func Offset: 0x64
	// Line 1836, Address: 0x158208, Func Offset: 0x78
	// Line 1837, Address: 0x15821c, Func Offset: 0x8c
	// Line 1838, Address: 0x158230, Func Offset: 0xa0
	// Line 1840, Address: 0x158244, Func Offset: 0xb4
	// Line 1843, Address: 0x15824c, Func Offset: 0xbc
	// Line 1840, Address: 0x158254, Func Offset: 0xc4
	// Line 1841, Address: 0x158260, Func Offset: 0xd0
	// Line 1842, Address: 0x15826c, Func Offset: 0xdc
	// Line 1843, Address: 0x158278, Func Offset: 0xe8
	// Line 1844, Address: 0x158284, Func Offset: 0xf4
	// Line 1845, Address: 0x158300, Func Offset: 0x170
	// Line 1846, Address: 0x158308, Func Offset: 0x178
	// Line 1848, Address: 0x158398, Func Offset: 0x208
	// Line 1849, Address: 0x1583a0, Func Offset: 0x210
	// Line 1848, Address: 0x1583a8, Func Offset: 0x218
	// Line 1849, Address: 0x1583b4, Func Offset: 0x224
	// Line 1850, Address: 0x1583c0, Func Offset: 0x230
	// Line 1851, Address: 0x158418, Func Offset: 0x288
	// Line 1852, Address: 0x158420, Func Offset: 0x290
	// Line 1854, Address: 0x15848c, Func Offset: 0x2fc
	// Line 1855, Address: 0x158494, Func Offset: 0x304
	// Line 1854, Address: 0x15849c, Func Offset: 0x30c
	// Line 1855, Address: 0x1584a8, Func Offset: 0x318
	// Line 1856, Address: 0x1584b4, Func Offset: 0x324
	// Line 1857, Address: 0x158530, Func Offset: 0x3a0
	// Line 1858, Address: 0x158538, Func Offset: 0x3a8
	// Line 1860, Address: 0x1585c8, Func Offset: 0x438
	// Line 1863, Address: 0x1585d0, Func Offset: 0x440
	// Line 1862, Address: 0x1585dc, Func Offset: 0x44c
	// Line 1860, Address: 0x1585e4, Func Offset: 0x454
	// Line 1862, Address: 0x1585f0, Func Offset: 0x460
	// Line 1863, Address: 0x1585fc, Func Offset: 0x46c
	// Line 1866, Address: 0x158614, Func Offset: 0x484
	// Line 1865, Address: 0x158618, Func Offset: 0x488
	// Line 1866, Address: 0x15861c, Func Offset: 0x48c
	// Func End, Address: 0x158624, Func Offset: 0x494
}

// 
// Start address: 0x158630
unsigned int bhDieCk()
{
	_anon21* e_enep;
	unsigned char* a0;
	unsigned int v2;
	int* v0;
	// Line 1883, Address: 0x158630, Func Offset: 0
	// Line 1889, Address: 0x158638, Func Offset: 0x8
	// Line 1884, Address: 0x158640, Func Offset: 0x10
	// Line 1889, Address: 0x15864c, Func Offset: 0x1c
	// Line 1886, Address: 0x158650, Func Offset: 0x20
	// Line 1887, Address: 0x158664, Func Offset: 0x34
	// Line 1893, Address: 0x158670, Func Offset: 0x40
	// Line 1899, Address: 0x15869c, Func Offset: 0x6c
	// Line 1904, Address: 0x1586ac, Func Offset: 0x7c
	// Line 1899, Address: 0x1586b4, Func Offset: 0x84
	// Line 1904, Address: 0x1586c8, Func Offset: 0x98
	// Line 1909, Address: 0x1586f4, Func Offset: 0xc4
	// Line 1912, Address: 0x158704, Func Offset: 0xd4
	// Line 1914, Address: 0x158710, Func Offset: 0xe0
	// Line 1915, Address: 0x158714, Func Offset: 0xe4
	// Line 1912, Address: 0x158718, Func Offset: 0xe8
	// Line 1914, Address: 0x158720, Func Offset: 0xf0
	// Line 1915, Address: 0x15872c, Func Offset: 0xfc
	// Line 1918, Address: 0x158734, Func Offset: 0x104
	// Line 1919, Address: 0x15873c, Func Offset: 0x10c
	// Line 1918, Address: 0x158740, Func Offset: 0x110
	// Line 1920, Address: 0x15874c, Func Offset: 0x11c
	// Func End, Address: 0x158754, Func Offset: 0x124
}

// 
// Start address: 0x158760
unsigned int bhItmCk()
{
	_anon6* e_etcp;
	unsigned int v5;
	unsigned int v4;
	unsigned int v2;
	int v1;
	int* v0;
	// Line 1940, Address: 0x158760, Func Offset: 0
	// Line 1948, Address: 0x158768, Func Offset: 0x8
	// Line 1940, Address: 0x158770, Func Offset: 0x10
	// Line 1942, Address: 0x15877c, Func Offset: 0x1c
	// Line 1943, Address: 0x158790, Func Offset: 0x30
	// Line 1944, Address: 0x15879c, Func Offset: 0x3c
	// Line 1945, Address: 0x1587a8, Func Offset: 0x48
	// Line 1946, Address: 0x1587b4, Func Offset: 0x54
	// Line 1947, Address: 0x1587c0, Func Offset: 0x60
	// Line 1948, Address: 0x1587cc, Func Offset: 0x6c
	// Line 1955, Address: 0x1587d8, Func Offset: 0x78
	// Line 1956, Address: 0x1587ec, Func Offset: 0x8c
	// Line 1962, Address: 0x1587f4, Func Offset: 0x94
	// Line 1968, Address: 0x158804, Func Offset: 0xa4
	// Line 1969, Address: 0x158834, Func Offset: 0xd4
	// Line 1970, Address: 0x15883c, Func Offset: 0xdc
	// Line 1969, Address: 0x158848, Func Offset: 0xe8
	// Line 1971, Address: 0x15884c, Func Offset: 0xec
	// Line 1972, Address: 0x158854, Func Offset: 0xf4
	// Line 1976, Address: 0x158860, Func Offset: 0x100
	// Line 1979, Address: 0x15886c, Func Offset: 0x10c
	// Line 1980, Address: 0x158874, Func Offset: 0x114
	// Line 1984, Address: 0x158878, Func Offset: 0x118
	// Line 1976, Address: 0x15887c, Func Offset: 0x11c
	// Line 1979, Address: 0x158880, Func Offset: 0x120
	// Line 1976, Address: 0x158884, Func Offset: 0x124
	// Line 1984, Address: 0x1588a0, Func Offset: 0x140
	// Line 1976, Address: 0x1588a4, Func Offset: 0x144
	// Line 1981, Address: 0x1588b0, Func Offset: 0x150
	// Line 1978, Address: 0x1588b8, Func Offset: 0x158
	// Line 1984, Address: 0x1588bc, Func Offset: 0x15c
	// Line 1986, Address: 0x1588c0, Func Offset: 0x160
	// Line 1976, Address: 0x1588c4, Func Offset: 0x164
	// Line 1978, Address: 0x1588cc, Func Offset: 0x16c
	// Line 1979, Address: 0x1588d4, Func Offset: 0x174
	// Line 1981, Address: 0x1588d8, Func Offset: 0x178
	// Line 1983, Address: 0x1588dc, Func Offset: 0x17c
	// Line 1981, Address: 0x1588e0, Func Offset: 0x180
	// Line 1983, Address: 0x1588e8, Func Offset: 0x188
	// Line 1984, Address: 0x1588f0, Func Offset: 0x190
	// Line 1986, Address: 0x1588f4, Func Offset: 0x194
	// Line 1989, Address: 0x1588fc, Func Offset: 0x19c
	// Line 1994, Address: 0x158904, Func Offset: 0x1a4
	// Line 1996, Address: 0x158934, Func Offset: 0x1d4
	// Line 1995, Address: 0x15893c, Func Offset: 0x1dc
	// Line 1996, Address: 0x158940, Func Offset: 0x1e0
	// Line 1998, Address: 0x158948, Func Offset: 0x1e8
	// Line 2001, Address: 0x15895c, Func Offset: 0x1fc
	// Line 2002, Address: 0x158968, Func Offset: 0x208
	// Line 2001, Address: 0x15896c, Func Offset: 0x20c
	// Line 2003, Address: 0x158978, Func Offset: 0x218
	// Func End, Address: 0x158980, Func Offset: 0x220
}

// 
// Start address: 0x158980
unsigned int bhObjLinkSet()
{
	int v1;
	// Line 2018, Address: 0x158980, Func Offset: 0
	// Line 2030, Address: 0x158988, Func Offset: 0x8
	// Line 2018, Address: 0x158998, Func Offset: 0x18
	// Line 2030, Address: 0x15899c, Func Offset: 0x1c
	// Line 2018, Address: 0x1589a4, Func Offset: 0x24
	// Line 2019, Address: 0x1589ac, Func Offset: 0x2c
	// Line 2020, Address: 0x1589b8, Func Offset: 0x38
	// Line 2030, Address: 0x1589c4, Func Offset: 0x44
	// Line 2032, Address: 0x1589f0, Func Offset: 0x70
	// Line 2030, Address: 0x1589f4, Func Offset: 0x74
	// Line 2032, Address: 0x158a2c, Func Offset: 0xac
	// Line 2034, Address: 0x158a30, Func Offset: 0xb0
	// Line 2032, Address: 0x158a38, Func Offset: 0xb8
	// Line 2034, Address: 0x158a44, Func Offset: 0xc4
	// Line 2033, Address: 0x158a50, Func Offset: 0xd0
	// Line 2034, Address: 0x158a58, Func Offset: 0xd8
	// Line 2033, Address: 0x158a5c, Func Offset: 0xdc
	// Line 2036, Address: 0x158a60, Func Offset: 0xe0
	// Line 2034, Address: 0x158a64, Func Offset: 0xe4
	// Line 2036, Address: 0x158a68, Func Offset: 0xe8
	// Line 2038, Address: 0x158a78, Func Offset: 0xf8
	// Line 2039, Address: 0x158a8c, Func Offset: 0x10c
	// Line 2041, Address: 0x158aac, Func Offset: 0x12c
	// Line 2042, Address: 0x158ab4, Func Offset: 0x134
	// Line 2045, Address: 0x158adc, Func Offset: 0x15c
	// Line 2046, Address: 0x158af0, Func Offset: 0x170
	// Line 2048, Address: 0x158afc, Func Offset: 0x17c
	// Line 2051, Address: 0x158b08, Func Offset: 0x188
	// Line 2052, Address: 0x158b14, Func Offset: 0x194
	// Line 2053, Address: 0x158b84, Func Offset: 0x204
	// Line 2054, Address: 0x158b8c, Func Offset: 0x20c
	// Line 2056, Address: 0x158bf0, Func Offset: 0x270
	// Line 2059, Address: 0x158bf8, Func Offset: 0x278
	// Line 2056, Address: 0x158bfc, Func Offset: 0x27c
	// Line 2059, Address: 0x158c04, Func Offset: 0x284
	// Line 2060, Address: 0x158c0c, Func Offset: 0x28c
	// Line 2061, Address: 0x158c7c, Func Offset: 0x2fc
	// Line 2062, Address: 0x158c84, Func Offset: 0x304
	// Line 2064, Address: 0x158ce8, Func Offset: 0x368
	// Line 2067, Address: 0x158cf0, Func Offset: 0x370
	// Line 2064, Address: 0x158cf4, Func Offset: 0x374
	// Line 2067, Address: 0x158cfc, Func Offset: 0x37c
	// Line 2068, Address: 0x158d04, Func Offset: 0x384
	// Line 2069, Address: 0x158d74, Func Offset: 0x3f4
	// Line 2070, Address: 0x158d7c, Func Offset: 0x3fc
	// Line 2072, Address: 0x158de0, Func Offset: 0x460
	// Line 2074, Address: 0x158de8, Func Offset: 0x468
	// Line 2072, Address: 0x158dec, Func Offset: 0x46c
	// Line 2075, Address: 0x158df4, Func Offset: 0x474
	// Func End, Address: 0x158dfc, Func Offset: 0x47c
}

// 
// Start address: 0x158e00
unsigned int bhSetObjMotion()
{
	unsigned char* a0;
	BH_PWORK* ob_ep;
	// Line 2083, Address: 0x158e00, Func Offset: 0
	// Line 2088, Address: 0x158e0c, Func Offset: 0xc
	// Line 2099, Address: 0x158e14, Func Offset: 0x14
	// Line 2097, Address: 0x158e18, Func Offset: 0x18
	// Line 2089, Address: 0x158e20, Func Offset: 0x20
	// Line 2097, Address: 0x158e24, Func Offset: 0x24
	// Line 2089, Address: 0x158e28, Func Offset: 0x28
	// Line 2091, Address: 0x158e30, Func Offset: 0x30
	// Line 2097, Address: 0x158e44, Func Offset: 0x44
	// Line 2099, Address: 0x158e6c, Func Offset: 0x6c
	// Line 2100, Address: 0x158e88, Func Offset: 0x88
	// Line 2102, Address: 0x158e9c, Func Offset: 0x9c
	// Line 2107, Address: 0x158ea4, Func Offset: 0xa4
	// Line 2106, Address: 0x158eac, Func Offset: 0xac
	// Line 2107, Address: 0x158eb0, Func Offset: 0xb0
	// Func End, Address: 0x158eb8, Func Offset: 0xb8
}

// 
// Start address: 0x158ec0
unsigned int bhSetDispObj()
{
	BH_PWORK* e_workp;
	int v2;
	int v1;
	int v0;
	// Line 2120, Address: 0x158ec0, Func Offset: 0
	// Line 2128, Address: 0x158ec8, Func Offset: 0x8
	// Line 2120, Address: 0x158ecc, Func Offset: 0xc
	// Line 2121, Address: 0x158ed8, Func Offset: 0x18
	// Line 2122, Address: 0x158ee4, Func Offset: 0x24
	// Line 2123, Address: 0x158ef0, Func Offset: 0x30
	// Line 2124, Address: 0x158efc, Func Offset: 0x3c
	// Line 2125, Address: 0x158f08, Func Offset: 0x48
	// Line 2126, Address: 0x158f14, Func Offset: 0x54
	// Line 2128, Address: 0x158f1c, Func Offset: 0x5c
	// Line 2130, Address: 0x158f4c, Func Offset: 0x8c
	// Line 2131, Address: 0x158f50, Func Offset: 0x90
	// Line 2137, Address: 0x158f58, Func Offset: 0x98
	// Line 2138, Address: 0x158f94, Func Offset: 0xd4
	// Line 2143, Address: 0x158f9c, Func Offset: 0xdc
	// Line 2144, Address: 0x158fc4, Func Offset: 0x104
	// Line 2149, Address: 0x158fcc, Func Offset: 0x10c
	// Line 2152, Address: 0x158ff8, Func Offset: 0x138
	// Line 2153, Address: 0x159000, Func Offset: 0x140
	// Line 2154, Address: 0x159008, Func Offset: 0x148
	// Line 2155, Address: 0x159010, Func Offset: 0x150
	// Line 2158, Address: 0x159020, Func Offset: 0x160
	// Func End, Address: 0x159028, Func Offset: 0x168
}

// 
// Start address: 0x159030
unsigned int bhSetDoorCall()
{
	unsigned int v4;
	unsigned int v3;
	unsigned int v2;
	int v1;
	int v0;
	// Line 2166, Address: 0x159030, Func Offset: 0
	// Line 2170, Address: 0x159038, Func Offset: 0x8
	// Line 2171, Address: 0x15904c, Func Offset: 0x1c
	// Line 2172, Address: 0x159058, Func Offset: 0x28
	// Line 2173, Address: 0x159064, Func Offset: 0x34
	// Line 2174, Address: 0x159070, Func Offset: 0x40
	// Line 2175, Address: 0x15907c, Func Offset: 0x4c
	// Line 2176, Address: 0x159088, Func Offset: 0x58
	// Line 2177, Address: 0x159094, Func Offset: 0x64
	// Line 2178, Address: 0x1590a0, Func Offset: 0x70
	// Line 2179, Address: 0x1590ac, Func Offset: 0x7c
	// Line 2180, Address: 0x1590b8, Func Offset: 0x88
	// Line 2182, Address: 0x1590c0, Func Offset: 0x90
	// Line 2185, Address: 0x1590c8, Func Offset: 0x98
	// Line 2184, Address: 0x1590cc, Func Offset: 0x9c
	// Line 2185, Address: 0x1590d0, Func Offset: 0xa0
	// Func End, Address: 0x1590d8, Func Offset: 0xa8
}

// 
// Start address: 0x1590e0
unsigned int bhDieEventCk()
{
	unsigned int die_cnt;
	unsigned int v3;
	unsigned int v2;
	// Line 2197, Address: 0x1590e0, Func Offset: 0
	// Line 2198, Address: 0x1590f4, Func Offset: 0x14
	// Line 2199, Address: 0x159100, Func Offset: 0x20
	// Line 2200, Address: 0x15910c, Func Offset: 0x2c
	// Line 2202, Address: 0x159118, Func Offset: 0x38
	// Line 2207, Address: 0x15912c, Func Offset: 0x4c
	// Line 2208, Address: 0x159160, Func Offset: 0x80
	// Line 2209, Address: 0x159164, Func Offset: 0x84
	// Line 2210, Address: 0x159168, Func Offset: 0x88
	// Line 2211, Address: 0x159178, Func Offset: 0x98
	// Line 2212, Address: 0x15918c, Func Offset: 0xac
	// Line 2213, Address: 0x159198, Func Offset: 0xb8
	// Line 2214, Address: 0x1591a4, Func Offset: 0xc4
	// Line 2215, Address: 0x1591b0, Func Offset: 0xd0
	// Line 2217, Address: 0x1591bc, Func Offset: 0xdc
	// Line 2218, Address: 0x1591e0, Func Offset: 0x100
	// Line 2219, Address: 0x1591ec, Func Offset: 0x10c
	// Line 2220, Address: 0x1591f4, Func Offset: 0x114
	// Line 2221, Address: 0x159200, Func Offset: 0x120
	// Line 2222, Address: 0x159208, Func Offset: 0x128
	// Line 2223, Address: 0x159214, Func Offset: 0x134
	// Line 2225, Address: 0x15921c, Func Offset: 0x13c
	// Func End, Address: 0x159224, Func Offset: 0x144
}

// 
// Start address: 0x159230
unsigned int bhSetDebugLoopEx()
{
	// Line 2247, Address: 0x159230, Func Offset: 0
	// Line 2248, Address: 0x159238, Func Offset: 0x8
	// Line 2255, Address: 0x159240, Func Offset: 0x10
	// Line 2248, Address: 0x159244, Func Offset: 0x14
	// Line 2250, Address: 0x159248, Func Offset: 0x18
	// Line 2248, Address: 0x15924c, Func Offset: 0x1c
	// Line 2250, Address: 0x159254, Func Offset: 0x24
	// Line 2251, Address: 0x159264, Func Offset: 0x34
	// Line 2252, Address: 0x159278, Func Offset: 0x48
	// Line 2254, Address: 0x159284, Func Offset: 0x54
	// Line 2255, Address: 0x15928c, Func Offset: 0x5c
	// Line 2256, Address: 0x159290, Func Offset: 0x60
	// Line 2257, Address: 0x159298, Func Offset: 0x68
	// Line 2259, Address: 0x1592a4, Func Offset: 0x74
	// Line 2257, Address: 0x1592a8, Func Offset: 0x78
	// Line 2259, Address: 0x1592b0, Func Offset: 0x80
	// Line 2260, Address: 0x1592c0, Func Offset: 0x90
	// Line 2261, Address: 0x1592e8, Func Offset: 0xb8
	// Line 2263, Address: 0x1592f4, Func Offset: 0xc4
	// Line 2262, Address: 0x1592f8, Func Offset: 0xc8
	// Line 2263, Address: 0x1592fc, Func Offset: 0xcc
	// Func End, Address: 0x159304, Func Offset: 0xd4
}

// 
// Start address: 0x159310
unsigned int bhInitSetKage()
{
	BH_PWORK* e_ep;
	unsigned int v1;
	unsigned int v0;
	// Line 2272, Address: 0x159310, Func Offset: 0
	// Line 2277, Address: 0x159318, Func Offset: 0x8
	// Line 2288, Address: 0x159320, Func Offset: 0x10
	// Line 2277, Address: 0x159330, Func Offset: 0x20
	// Line 2278, Address: 0x15933c, Func Offset: 0x2c
	// Line 2279, Address: 0x159348, Func Offset: 0x38
	// Line 2280, Address: 0x159354, Func Offset: 0x44
	// Line 2288, Address: 0x15935c, Func Offset: 0x4c
	// Line 2280, Address: 0x159368, Func Offset: 0x58
	// Line 2281, Address: 0x15936c, Func Offset: 0x5c
	// Line 2288, Address: 0x159378, Func Offset: 0x68
	// Line 2290, Address: 0x15939c, Func Offset: 0x8c
	// Line 2291, Address: 0x1593ac, Func Offset: 0x9c
	// Line 2295, Address: 0x1593b4, Func Offset: 0xa4
	// Line 2298, Address: 0x1593f4, Func Offset: 0xe4
	// Line 2299, Address: 0x159414, Func Offset: 0x104
	// Line 2302, Address: 0x15941c, Func Offset: 0x10c
	// Line 2303, Address: 0x15943c, Func Offset: 0x12c
	// Line 2306, Address: 0x159444, Func Offset: 0x134
	// Line 2307, Address: 0x159468, Func Offset: 0x158
	// Line 2310, Address: 0x159470, Func Offset: 0x160
	// Line 2311, Address: 0x159494, Func Offset: 0x184
	// Line 2314, Address: 0x15949c, Func Offset: 0x18c
	// Line 2319, Address: 0x1594c0, Func Offset: 0x1b0
	// Line 2318, Address: 0x1594c4, Func Offset: 0x1b4
	// Line 2319, Address: 0x1594c8, Func Offset: 0x1b8
	// Func End, Address: 0x1594d0, Func Offset: 0x1c0
}

// 
// Start address: 0x1594d0
unsigned int bhObjLinkSetPly()
{
	int v1;
	// Line 2331, Address: 0x1594d0, Func Offset: 0
	// Line 2333, Address: 0x1594d8, Func Offset: 0x8
	// Line 2331, Address: 0x1594e0, Func Offset: 0x10
	// Line 2333, Address: 0x1594e4, Func Offset: 0x14
	// Line 2331, Address: 0x1594ec, Func Offset: 0x1c
	// Line 2333, Address: 0x1594f4, Func Offset: 0x24
	// Line 2339, Address: 0x15950c, Func Offset: 0x3c
	// Line 2333, Address: 0x159510, Func Offset: 0x40
	// Line 2339, Address: 0x15952c, Func Offset: 0x5c
	// Line 2341, Address: 0x159530, Func Offset: 0x60
	// Line 2339, Address: 0x159538, Func Offset: 0x68
	// Line 2341, Address: 0x159544, Func Offset: 0x74
	// Line 2340, Address: 0x159550, Func Offset: 0x80
	// Line 2341, Address: 0x159558, Func Offset: 0x88
	// Line 2340, Address: 0x15955c, Func Offset: 0x8c
	// Line 2343, Address: 0x159560, Func Offset: 0x90
	// Line 2341, Address: 0x159564, Func Offset: 0x94
	// Line 2343, Address: 0x159568, Func Offset: 0x98
	// Line 2345, Address: 0x159578, Func Offset: 0xa8
	// Line 2346, Address: 0x15958c, Func Offset: 0xbc
	// Line 2348, Address: 0x1595ac, Func Offset: 0xdc
	// Line 2349, Address: 0x1595b4, Func Offset: 0xe4
	// Line 2352, Address: 0x1595dc, Func Offset: 0x10c
	// Line 2353, Address: 0x1595f0, Func Offset: 0x120
	// Line 2355, Address: 0x1595fc, Func Offset: 0x12c
	// Line 2358, Address: 0x159608, Func Offset: 0x138
	// Line 2359, Address: 0x159614, Func Offset: 0x144
	// Line 2360, Address: 0x159684, Func Offset: 0x1b4
	// Line 2361, Address: 0x15968c, Func Offset: 0x1bc
	// Line 2363, Address: 0x1596f0, Func Offset: 0x220
	// Line 2366, Address: 0x1596f8, Func Offset: 0x228
	// Line 2363, Address: 0x1596fc, Func Offset: 0x22c
	// Line 2366, Address: 0x159704, Func Offset: 0x234
	// Line 2367, Address: 0x15970c, Func Offset: 0x23c
	// Line 2368, Address: 0x15977c, Func Offset: 0x2ac
	// Line 2369, Address: 0x159784, Func Offset: 0x2b4
	// Line 2371, Address: 0x1597e8, Func Offset: 0x318
	// Line 2374, Address: 0x1597f0, Func Offset: 0x320
	// Line 2371, Address: 0x1597f4, Func Offset: 0x324
	// Line 2374, Address: 0x1597fc, Func Offset: 0x32c
	// Line 2375, Address: 0x159804, Func Offset: 0x334
	// Line 2376, Address: 0x159874, Func Offset: 0x3a4
	// Line 2377, Address: 0x15987c, Func Offset: 0x3ac
	// Line 2379, Address: 0x1598e0, Func Offset: 0x410
	// Line 2381, Address: 0x1598e8, Func Offset: 0x418
	// Line 2379, Address: 0x1598ec, Func Offset: 0x41c
	// Line 2382, Address: 0x1598f4, Func Offset: 0x424
	// Func End, Address: 0x1598fc, Func Offset: 0x42c
}

// 
// Start address: 0x159900
unsigned int bhSetNextRoomBgm()
{
	int v0;
	// Line 2396, Address: 0x159900, Func Offset: 0
	// Line 2425, Address: 0x159908, Func Offset: 0x8
	// Line 2396, Address: 0x15990c, Func Offset: 0xc
	// Line 2408, Address: 0x159918, Func Offset: 0x18
	// Line 2409, Address: 0x15992c, Func Offset: 0x2c
	// Line 2410, Address: 0x159938, Func Offset: 0x38
	// Line 2411, Address: 0x159940, Func Offset: 0x40
	// Line 2412, Address: 0x15994c, Func Offset: 0x4c
	// Line 2413, Address: 0x159958, Func Offset: 0x58
	// Line 2414, Address: 0x159960, Func Offset: 0x60
	// Line 2415, Address: 0x15996c, Func Offset: 0x6c
	// Line 2416, Address: 0x159978, Func Offset: 0x78
	// Line 2417, Address: 0x159980, Func Offset: 0x80
	// Line 2418, Address: 0x15998c, Func Offset: 0x8c
	// Line 2419, Address: 0x159998, Func Offset: 0x98
	// Line 2420, Address: 0x1599a0, Func Offset: 0xa0
	// Line 2422, Address: 0x1599ac, Func Offset: 0xac
	// Line 2423, Address: 0x1599b8, Func Offset: 0xb8
	// Line 2422, Address: 0x1599c4, Func Offset: 0xc4
	// Line 2426, Address: 0x1599d4, Func Offset: 0xd4
	// Func End, Address: 0x1599dc, Func Offset: 0xdc
}

// 
// Start address: 0x1599e0
unsigned int bhSetNextRoomBgSe()
{
	int v1;
	int v0;
	// Line 2440, Address: 0x1599e0, Func Offset: 0
	// Line 2444, Address: 0x1599e8, Func Offset: 0x8
	// Line 2447, Address: 0x1599f0, Func Offset: 0x10
	// Line 2440, Address: 0x1599f8, Func Offset: 0x18
	// Line 2441, Address: 0x159a04, Func Offset: 0x24
	// Line 2450, Address: 0x159a0c, Func Offset: 0x2c
	// Line 2453, Address: 0x159a14, Func Offset: 0x34
	// Line 2441, Address: 0x159a1c, Func Offset: 0x3c
	// Line 2442, Address: 0x159a20, Func Offset: 0x40
	// Line 2443, Address: 0x159a2c, Func Offset: 0x4c
	// Line 2444, Address: 0x159a34, Func Offset: 0x54
	// Line 2447, Address: 0x159a38, Func Offset: 0x58
	// Line 2450, Address: 0x159a3c, Func Offset: 0x5c
	// Line 2443, Address: 0x159a40, Func Offset: 0x60
	// Line 2450, Address: 0x159a44, Func Offset: 0x64
	// Line 2453, Address: 0x159a48, Func Offset: 0x68
	// Line 2444, Address: 0x159a50, Func Offset: 0x70
	// Line 2445, Address: 0x159a54, Func Offset: 0x74
	// Line 2456, Address: 0x159a5c, Func Offset: 0x7c
	// Line 2445, Address: 0x159a68, Func Offset: 0x88
	// Line 2446, Address: 0x159a74, Func Offset: 0x94
	// Line 2448, Address: 0x159a80, Func Offset: 0xa0
	// Line 2447, Address: 0x159a84, Func Offset: 0xa4
	// Line 2448, Address: 0x159a88, Func Offset: 0xa8
	// Line 2449, Address: 0x159a98, Func Offset: 0xb8
	// Line 2451, Address: 0x159aa4, Func Offset: 0xc4
	// Line 2450, Address: 0x159aa8, Func Offset: 0xc8
	// Line 2451, Address: 0x159aac, Func Offset: 0xcc
	// Line 2452, Address: 0x159abc, Func Offset: 0xdc
	// Line 2454, Address: 0x159ac8, Func Offset: 0xe8
	// Line 2453, Address: 0x159acc, Func Offset: 0xec
	// Line 2454, Address: 0x159ad0, Func Offset: 0xf0
	// Line 2456, Address: 0x159ae0, Func Offset: 0x100
	// Line 2457, Address: 0x159aec, Func Offset: 0x10c
	// Line 2456, Address: 0x159af0, Func Offset: 0x110
	// Line 2457, Address: 0x159b00, Func Offset: 0x120
	// Line 2459, Address: 0x159b10, Func Offset: 0x130
	// Line 2460, Address: 0x159b24, Func Offset: 0x144
	// Line 2461, Address: 0x159b34, Func Offset: 0x154
	// Line 2462, Address: 0x159b3c, Func Offset: 0x15c
	// Line 2464, Address: 0x159b4c, Func Offset: 0x16c
	// Line 2466, Address: 0x159b54, Func Offset: 0x174
	// Line 2464, Address: 0x159b58, Func Offset: 0x178
	// Line 2467, Address: 0x159b60, Func Offset: 0x180
	// Func End, Address: 0x159b68, Func Offset: 0x188
}

// 
// Start address: 0x159b70
unsigned int bhFootSeCall()
{
	int v6;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	int flr_no;
	int fsnd;
	// Line 2475, Address: 0x159b70, Func Offset: 0
	// Line 2481, Address: 0x159b90, Func Offset: 0x20
	// Line 2507, Address: 0x159b98, Func Offset: 0x28
	// Line 2481, Address: 0x159ba0, Func Offset: 0x30
	// Line 2482, Address: 0x159bac, Func Offset: 0x3c
	// Line 2483, Address: 0x159bb8, Func Offset: 0x48
	// Line 2484, Address: 0x159bc4, Func Offset: 0x54
	// Line 2485, Address: 0x159bd0, Func Offset: 0x60
	// Line 2486, Address: 0x159bdc, Func Offset: 0x6c
	// Line 2487, Address: 0x159be8, Func Offset: 0x78
	// Line 2488, Address: 0x159bf4, Func Offset: 0x84
	// Line 2489, Address: 0x159c00, Func Offset: 0x90
	// Line 2490, Address: 0x159c0c, Func Offset: 0x9c
	// Line 2491, Address: 0x159c18, Func Offset: 0xa8
	// Line 2507, Address: 0x159c24, Func Offset: 0xb4
	// Line 2509, Address: 0x159c30, Func Offset: 0xc0
	// Line 2517, Address: 0x159c50, Func Offset: 0xe0
	// Line 2521, Address: 0x159cbc, Func Offset: 0x14c
	// Line 2522, Address: 0x159cc0, Func Offset: 0x150
	// Line 2523, Address: 0x159cc8, Func Offset: 0x158
	// Line 2525, Address: 0x159ccc, Func Offset: 0x15c
	// Line 2528, Address: 0x159cf8, Func Offset: 0x188
	// Line 2527, Address: 0x159d14, Func Offset: 0x1a4
	// Line 2528, Address: 0x159d18, Func Offset: 0x1a8
	// Func End, Address: 0x159d20, Func Offset: 0x1b0
}

// 
// Start address: 0x159d20
unsigned int bhEneSetCk()
{
	_anon21* e_enep;
	unsigned char* a0;
	unsigned int v2;
	// Line 2545, Address: 0x159d20, Func Offset: 0
	// Line 2559, Address: 0x159d28, Func Offset: 0x8
	// Line 2546, Address: 0x159d30, Func Offset: 0x10
	// Line 2548, Address: 0x159d3c, Func Offset: 0x1c
	// Line 2559, Address: 0x159d44, Func Offset: 0x24
	// Line 2548, Address: 0x159d48, Func Offset: 0x28
	// Line 2549, Address: 0x159d54, Func Offset: 0x34
	// Line 2559, Address: 0x159d60, Func Offset: 0x40
	// Line 2560, Address: 0x159d8c, Func Offset: 0x6c
	// Line 2566, Address: 0x159d9c, Func Offset: 0x7c
	// Line 2560, Address: 0x159da4, Func Offset: 0x84
	// Line 2566, Address: 0x159da8, Func Offset: 0x88
	// Line 2560, Address: 0x159dac, Func Offset: 0x8c
	// Line 2566, Address: 0x159dbc, Func Offset: 0x9c
	// Line 2568, Address: 0x159de4, Func Offset: 0xc4
	// Line 2569, Address: 0x159dec, Func Offset: 0xcc
	// Line 2568, Address: 0x159df0, Func Offset: 0xd0
	// Line 2570, Address: 0x159df8, Func Offset: 0xd8
	// Func End, Address: 0x159e00, Func Offset: 0xe0
}

// 
// Start address: 0x159e00
unsigned int bhItmSetCk()
{
	_anon6* e_etcp;
	unsigned int v5;
	unsigned int v4;
	unsigned int v3;
	unsigned int v2;
	// Line 2590, Address: 0x159e00, Func Offset: 0
	// Line 2608, Address: 0x159e08, Func Offset: 0x8
	// Line 2590, Address: 0x159e10, Func Offset: 0x10
	// Line 2591, Address: 0x159e1c, Func Offset: 0x1c
	// Line 2608, Address: 0x159e24, Func Offset: 0x24
	// Line 2591, Address: 0x159e28, Func Offset: 0x28
	// Line 2592, Address: 0x159e2c, Func Offset: 0x2c
	// Line 2593, Address: 0x159e38, Func Offset: 0x38
	// Line 2594, Address: 0x159e44, Func Offset: 0x44
	// Line 2595, Address: 0x159e50, Func Offset: 0x50
	// Line 2608, Address: 0x159e58, Func Offset: 0x58
	// Line 2595, Address: 0x159e68, Func Offset: 0x68
	// Line 2596, Address: 0x159e6c, Func Offset: 0x6c
	// Line 2608, Address: 0x159e70, Func Offset: 0x70
	// Line 2596, Address: 0x159e74, Func Offset: 0x74
	// Line 2597, Address: 0x159e7c, Func Offset: 0x7c
	// Line 2598, Address: 0x159e88, Func Offset: 0x88
	// Line 2608, Address: 0x159e94, Func Offset: 0x94
	// Line 2609, Address: 0x159eac, Func Offset: 0xac
	// Line 2610, Address: 0x159eb4, Func Offset: 0xb4
	// Line 2609, Address: 0x159ec0, Func Offset: 0xc0
	// Line 2611, Address: 0x159ec4, Func Offset: 0xc4
	// Line 2612, Address: 0x159ecc, Func Offset: 0xcc
	// Line 2616, Address: 0x159ed8, Func Offset: 0xd8
	// Line 2617, Address: 0x159f10, Func Offset: 0x110
	// Line 2618, Address: 0x159f18, Func Offset: 0x118
	// Line 2619, Address: 0x159f20, Func Offset: 0x120
	// Line 2618, Address: 0x159f2c, Func Offset: 0x12c
	// Line 2619, Address: 0x159f30, Func Offset: 0x130
	// Line 2620, Address: 0x159f34, Func Offset: 0x134
	// Line 2623, Address: 0x159f40, Func Offset: 0x140
	// Func End, Address: 0x159f48, Func Offset: 0x148
}

// 
// Start address: 0x159f50
unsigned int bhInitModelSet()
{
	_anon0* e_ip;
	BH_PWORK* e_ep;
	unsigned int v4;
	unsigned int v3;
	unsigned int v2;
	// Line 2640, Address: 0x159f50, Func Offset: 0
	// Line 2648, Address: 0x159f58, Func Offset: 0x8
	// Line 2640, Address: 0x159f5c, Func Offset: 0xc
	// Line 2641, Address: 0x159f68, Func Offset: 0x18
	// Line 2642, Address: 0x159f74, Func Offset: 0x24
	// Line 2643, Address: 0x159f80, Func Offset: 0x30
	// Line 2644, Address: 0x159f8c, Func Offset: 0x3c
	// Line 2645, Address: 0x159f98, Func Offset: 0x48
	// Line 2646, Address: 0x159fa4, Func Offset: 0x54
	// Line 2648, Address: 0x159fac, Func Offset: 0x5c
	// Line 2650, Address: 0x159fdc, Func Offset: 0x8c
	// Line 2651, Address: 0x159fe4, Func Offset: 0x94
	// Line 2653, Address: 0x159ff0, Func Offset: 0xa0
	// Line 2651, Address: 0x159ff4, Func Offset: 0xa4
	// Line 2653, Address: 0x159ff8, Func Offset: 0xa8
	// Line 2651, Address: 0x159ffc, Func Offset: 0xac
	// Line 2653, Address: 0x15a004, Func Offset: 0xb4
	// Line 2656, Address: 0x15a030, Func Offset: 0xe0
	// Line 2659, Address: 0x15a034, Func Offset: 0xe4
	// Line 2660, Address: 0x15a03c, Func Offset: 0xec
	// Line 2662, Address: 0x15a054, Func Offset: 0x104
	// Line 2670, Address: 0x15a05c, Func Offset: 0x10c
	// Line 2671, Address: 0x15a098, Func Offset: 0x148
	// Line 2672, Address: 0x15a0a0, Func Offset: 0x150
	// Line 2673, Address: 0x15a0b0, Func Offset: 0x160
	// Line 2674, Address: 0x15a0b8, Func Offset: 0x168
	// Line 2675, Address: 0x15a0c0, Func Offset: 0x170
	// Line 2676, Address: 0x15a0cc, Func Offset: 0x17c
	// Line 2675, Address: 0x15a0d0, Func Offset: 0x180
	// Line 2676, Address: 0x15a0d8, Func Offset: 0x188
	// Line 2677, Address: 0x15a0e8, Func Offset: 0x198
	// Line 2680, Address: 0x15a0f4, Func Offset: 0x1a4
	// Line 2686, Address: 0x15a0fc, Func Offset: 0x1ac
	// Line 2687, Address: 0x15a124, Func Offset: 0x1d4
	// Line 2688, Address: 0x15a12c, Func Offset: 0x1dc
	// Line 2689, Address: 0x15a138, Func Offset: 0x1e8
	// Line 2690, Address: 0x15a140, Func Offset: 0x1f0
	// Line 2692, Address: 0x15a150, Func Offset: 0x200
	// Line 2699, Address: 0x15a158, Func Offset: 0x208
	// Line 2700, Address: 0x15a180, Func Offset: 0x230
	// Line 2701, Address: 0x15a188, Func Offset: 0x238
	// Line 2702, Address: 0x15a194, Func Offset: 0x244
	// Line 2703, Address: 0x15a19c, Func Offset: 0x24c
	// Line 2707, Address: 0x15a1b0, Func Offset: 0x260
	// Line 2708, Address: 0x15a1b4, Func Offset: 0x264
	// Func End, Address: 0x15a1bc, Func Offset: 0x26c
}

// 
// Start address: 0x15a1c0
unsigned int bhEtcAtariSet2()
{
	_anon6* e_etcp;
	unsigned int v1;
	// Line 2722, Address: 0x15a1c0, Func Offset: 0
	// Line 2756, Address: 0x15a1c8, Func Offset: 0x8
	// Line 2728, Address: 0x15a1cc, Func Offset: 0xc
	// Line 2722, Address: 0x15a1d4, Func Offset: 0x14
	// Line 2729, Address: 0x15a1e0, Func Offset: 0x20
	// Line 2728, Address: 0x15a1e8, Func Offset: 0x28
	// Line 2729, Address: 0x15a1ec, Func Offset: 0x2c
	// Line 2731, Address: 0x15a1f0, Func Offset: 0x30
	// Line 2729, Address: 0x15a1fc, Func Offset: 0x3c
	// Line 2732, Address: 0x15a204, Func Offset: 0x44
	// Line 2729, Address: 0x15a20c, Func Offset: 0x4c
	// Line 2732, Address: 0x15a214, Func Offset: 0x54
	// Line 2735, Address: 0x15a218, Func Offset: 0x58
	// Line 2733, Address: 0x15a21c, Func Offset: 0x5c
	// Line 2735, Address: 0x15a220, Func Offset: 0x60
	// Line 2736, Address: 0x15a230, Func Offset: 0x70
	// Line 2739, Address: 0x15a23c, Func Offset: 0x7c
	// Line 2737, Address: 0x15a240, Func Offset: 0x80
	// Line 2739, Address: 0x15a244, Func Offset: 0x84
	// Line 2740, Address: 0x15a254, Func Offset: 0x94
	// Line 2743, Address: 0x15a260, Func Offset: 0xa0
	// Line 2741, Address: 0x15a264, Func Offset: 0xa4
	// Line 2743, Address: 0x15a268, Func Offset: 0xa8
	// Line 2744, Address: 0x15a278, Func Offset: 0xb8
	// Line 2747, Address: 0x15a284, Func Offset: 0xc4
	// Line 2745, Address: 0x15a288, Func Offset: 0xc8
	// Line 2747, Address: 0x15a28c, Func Offset: 0xcc
	// Line 2748, Address: 0x15a29c, Func Offset: 0xdc
	// Line 2751, Address: 0x15a2a8, Func Offset: 0xe8
	// Line 2749, Address: 0x15a2ac, Func Offset: 0xec
	// Line 2751, Address: 0x15a2b0, Func Offset: 0xf0
	// Line 2752, Address: 0x15a2c0, Func Offset: 0x100
	// Line 2754, Address: 0x15a2cc, Func Offset: 0x10c
	// Line 2753, Address: 0x15a2d0, Func Offset: 0x110
	// Line 2754, Address: 0x15a2d4, Func Offset: 0x114
	// Line 2757, Address: 0x15a2e0, Func Offset: 0x120
	// Func End, Address: 0x15a2e8, Func Offset: 0x128
}

// 
// Start address: 0x15a2f0
unsigned int bhLightSet()
{
	_anon11* lp;
	int v2;
	int v1;
	int v0;
	// Line 2769, Address: 0x15a2f0, Func Offset: 0
	// Line 2770, Address: 0x15a304, Func Offset: 0x14
	// Line 2771, Address: 0x15a310, Func Offset: 0x20
	// Line 2772, Address: 0x15a31c, Func Offset: 0x2c
	// Line 2773, Address: 0x15a328, Func Offset: 0x38
	// Line 2774, Address: 0x15a334, Func Offset: 0x44
	// Line 2775, Address: 0x15a340, Func Offset: 0x50
	// Line 2786, Address: 0x15a348, Func Offset: 0x58
	// Line 2789, Address: 0x15a38c, Func Offset: 0x9c
	// Line 2790, Address: 0x15a394, Func Offset: 0xa4
	// Line 2791, Address: 0x15a39c, Func Offset: 0xac
	// Line 2792, Address: 0x15a3a4, Func Offset: 0xb4
	// Line 2795, Address: 0x15a3b4, Func Offset: 0xc4
	// Func End, Address: 0x15a3bc, Func Offset: 0xcc
}

// 
// Start address: 0x15a3c0
unsigned int bhWeaponSeCall()
{
	BH_PWORK* e_ep;
	int v8;
	int v7;
	int v6;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 2805, Address: 0x15a3c0, Func Offset: 0
	// Line 2810, Address: 0x15a3e4, Func Offset: 0x24
	// Line 2811, Address: 0x15a3f8, Func Offset: 0x38
	// Line 2812, Address: 0x15a404, Func Offset: 0x44
	// Line 2813, Address: 0x15a410, Func Offset: 0x50
	// Line 2814, Address: 0x15a41c, Func Offset: 0x5c
	// Line 2815, Address: 0x15a428, Func Offset: 0x68
	// Line 2816, Address: 0x15a434, Func Offset: 0x74
	// Line 2817, Address: 0x15a440, Func Offset: 0x80
	// Line 2818, Address: 0x15a44c, Func Offset: 0x8c
	// Line 2819, Address: 0x15a458, Func Offset: 0x98
	// Line 2820, Address: 0x15a464, Func Offset: 0xa4
	// Line 2821, Address: 0x15a470, Func Offset: 0xb0
	// Line 2822, Address: 0x15a47c, Func Offset: 0xbc
	// Line 2828, Address: 0x15a488, Func Offset: 0xc8
	// Line 2823, Address: 0x15a48c, Func Offset: 0xcc
	// Line 2824, Address: 0x15a498, Func Offset: 0xd8
	// Line 2825, Address: 0x15a4a4, Func Offset: 0xe4
	// Line 2826, Address: 0x15a4b0, Func Offset: 0xf0
	// Line 2828, Address: 0x15a4b8, Func Offset: 0xf8
	// Line 2829, Address: 0x15a4c0, Func Offset: 0x100
	// Line 2831, Address: 0x15a4c4, Func Offset: 0x104
	// Line 2833, Address: 0x15a4e4, Func Offset: 0x124
	// Line 2835, Address: 0x15a518, Func Offset: 0x158
	// Line 2836, Address: 0x15a520, Func Offset: 0x160
	// Line 2837, Address: 0x15a558, Func Offset: 0x198
	// Line 2840, Address: 0x15a56c, Func Offset: 0x1ac
	// Line 2841, Address: 0x15a588, Func Offset: 0x1c8
	// Line 2842, Address: 0x15a590, Func Offset: 0x1d0
	// Line 2843, Address: 0x15a5c8, Func Offset: 0x208
	// Line 2846, Address: 0x15a5dc, Func Offset: 0x21c
	// Line 2848, Address: 0x15a5f8, Func Offset: 0x238
	// Line 2856, Address: 0x15a600, Func Offset: 0x240
	// Line 2857, Address: 0x15a63c, Func Offset: 0x27c
	// Line 2858, Address: 0x15a644, Func Offset: 0x284
	// Line 2859, Address: 0x15a67c, Func Offset: 0x2bc
	// Line 2862, Address: 0x15a6a0, Func Offset: 0x2e0
	// Line 2863, Address: 0x15a6b8, Func Offset: 0x2f8
	// Line 2864, Address: 0x15a6c0, Func Offset: 0x300
	// Line 2865, Address: 0x15a6f8, Func Offset: 0x338
	// Line 2868, Address: 0x15a71c, Func Offset: 0x35c
	// Line 2870, Address: 0x15a734, Func Offset: 0x374
	// Line 2872, Address: 0x15a73c, Func Offset: 0x37c
	// Line 2873, Address: 0x15a744, Func Offset: 0x384
	// Line 2874, Address: 0x15a760, Func Offset: 0x3a0
	// Line 2875, Address: 0x15a768, Func Offset: 0x3a8
	// Line 2877, Address: 0x15a784, Func Offset: 0x3c4
	// Line 2883, Address: 0x15a78c, Func Offset: 0x3cc
	// Line 2884, Address: 0x15a7c8, Func Offset: 0x408
	// Line 2885, Address: 0x15a7d0, Func Offset: 0x410
	// Line 2886, Address: 0x15a7e4, Func Offset: 0x424
	// Line 2887, Address: 0x15a7ec, Func Offset: 0x42c
	// Line 2892, Address: 0x15a800, Func Offset: 0x440
	// Line 2891, Address: 0x15a820, Func Offset: 0x460
	// Line 2892, Address: 0x15a824, Func Offset: 0x464
	// Func End, Address: 0x15a82c, Func Offset: 0x46c
}

// 
// Start address: 0x15a830
unsigned int bhYakkyouSet()
{
	BH_PWORK* e_ep;
	int v7;
	int v6;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 2900, Address: 0x15a830, Func Offset: 0
	// Line 2905, Address: 0x15a84c, Func Offset: 0x1c
	// Line 2906, Address: 0x15a860, Func Offset: 0x30
	// Line 2907, Address: 0x15a86c, Func Offset: 0x3c
	// Line 2908, Address: 0x15a878, Func Offset: 0x48
	// Line 2909, Address: 0x15a884, Func Offset: 0x54
	// Line 2910, Address: 0x15a890, Func Offset: 0x60
	// Line 2911, Address: 0x15a89c, Func Offset: 0x6c
	// Line 2912, Address: 0x15a8a8, Func Offset: 0x78
	// Line 2913, Address: 0x15a8b4, Func Offset: 0x84
	// Line 2914, Address: 0x15a8c0, Func Offset: 0x90
	// Line 2915, Address: 0x15a8cc, Func Offset: 0x9c
	// Line 2916, Address: 0x15a8d8, Func Offset: 0xa8
	// Line 2917, Address: 0x15a8e4, Func Offset: 0xb4
	// Line 2921, Address: 0x15a8f0, Func Offset: 0xc0
	// Line 2918, Address: 0x15a8f4, Func Offset: 0xc4
	// Line 2919, Address: 0x15a900, Func Offset: 0xd0
	// Line 2921, Address: 0x15a908, Func Offset: 0xd8
	// Line 2922, Address: 0x15a910, Func Offset: 0xe0
	// Line 2924, Address: 0x15a914, Func Offset: 0xe4
	// Line 2926, Address: 0x15a930, Func Offset: 0x100
	// Line 2928, Address: 0x15a94c, Func Offset: 0x11c
	// Line 2929, Address: 0x15a954, Func Offset: 0x124
	// Line 2930, Address: 0x15a970, Func Offset: 0x140
	// Line 2931, Address: 0x15a978, Func Offset: 0x148
	// Line 2933, Address: 0x15a994, Func Offset: 0x164
	// Line 2939, Address: 0x15a99c, Func Offset: 0x16c
	// Line 2940, Address: 0x15a9d8, Func Offset: 0x1a8
	// Line 2941, Address: 0x15a9e0, Func Offset: 0x1b0
	// Line 2942, Address: 0x15a9f4, Func Offset: 0x1c4
	// Line 2943, Address: 0x15a9fc, Func Offset: 0x1cc
	// Line 2948, Address: 0x15aa10, Func Offset: 0x1e0
	// Line 2947, Address: 0x15aa28, Func Offset: 0x1f8
	// Line 2948, Address: 0x15aa2c, Func Offset: 0x1fc
	// Func End, Address: 0x15aa34, Func Offset: 0x204
}

// 
// Start address: 0x15aa40
unsigned int bhFadeSet()
{
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 2956, Address: 0x15aa40, Func Offset: 0
	// Line 2959, Address: 0x15aa48, Func Offset: 0x8
	// Line 2960, Address: 0x15aa5c, Func Offset: 0x1c
	// Line 2961, Address: 0x15aa68, Func Offset: 0x28
	// Line 2962, Address: 0x15aa74, Func Offset: 0x34
	// Line 2971, Address: 0x15aa7c, Func Offset: 0x3c
	// Line 2962, Address: 0x15aa80, Func Offset: 0x40
	// Line 2963, Address: 0x15aa84, Func Offset: 0x44
	// Line 2971, Address: 0x15aa90, Func Offset: 0x50
	// Line 2964, Address: 0x15aa98, Func Offset: 0x58
	// Line 2965, Address: 0x15aaa4, Func Offset: 0x64
	// Line 2971, Address: 0x15aab0, Func Offset: 0x70
	// Line 2966, Address: 0x15aab8, Func Offset: 0x78
	// Line 2967, Address: 0x15aac4, Func Offset: 0x84
	// Line 2971, Address: 0x15aad0, Func Offset: 0x90
	// Line 2968, Address: 0x15aad4, Func Offset: 0x94
	// Line 2969, Address: 0x15aae0, Func Offset: 0xa0
	// Line 2971, Address: 0x15aae4, Func Offset: 0xa4
	// Line 2969, Address: 0x15aae8, Func Offset: 0xa8
	// Line 2971, Address: 0x15aaec, Func Offset: 0xac
	// Line 2974, Address: 0x15aaf8, Func Offset: 0xb8
	// Line 2973, Address: 0x15aafc, Func Offset: 0xbc
	// Line 2974, Address: 0x15ab00, Func Offset: 0xc0
	// Func End, Address: 0x15ab08, Func Offset: 0xc8
}

// 
// Start address: 0x15ab10
unsigned int bhRoomCaseNo()
{
	int v0;
	// Line 2985, Address: 0x15ab10, Func Offset: 0
	// Line 2991, Address: 0x15ab18, Func Offset: 0x8
	// Line 2989, Address: 0x15ab1c, Func Offset: 0xc
	// Line 2985, Address: 0x15ab24, Func Offset: 0x14
	// Line 2986, Address: 0x15ab30, Func Offset: 0x20
	// Line 2987, Address: 0x15ab3c, Func Offset: 0x2c
	// Line 2992, Address: 0x15ab48, Func Offset: 0x38
	// Func End, Address: 0x15ab50, Func Offset: 0x40
}

// 
// Start address: 0x15ab50
unsigned int bhFrameCheck()
{
	int v5;
	int v4;
	unsigned int v3;
	unsigned int v2;
	int v1;
	int v0;
	// Line 3009, Address: 0x15ab50, Func Offset: 0
	// Line 3010, Address: 0x15ab64, Func Offset: 0x14
	// Line 3011, Address: 0x15ab70, Func Offset: 0x20
	// Line 3012, Address: 0x15ab7c, Func Offset: 0x2c
	// Line 3013, Address: 0x15ab88, Func Offset: 0x38
	// Line 3014, Address: 0x15ab94, Func Offset: 0x44
	// Line 3015, Address: 0x15aba0, Func Offset: 0x50
	// Line 3016, Address: 0x15abac, Func Offset: 0x5c
	// Line 3017, Address: 0x15abb8, Func Offset: 0x68
	// Line 3020, Address: 0x15abc4, Func Offset: 0x74
	// Line 3021, Address: 0x15abcc, Func Offset: 0x7c
	// Line 3024, Address: 0x15abd4, Func Offset: 0x84
	// Line 3026, Address: 0x15abfc, Func Offset: 0xac
	// Line 3027, Address: 0x15ac04, Func Offset: 0xb4
	// Line 3034, Address: 0x15ac0c, Func Offset: 0xbc
	// Line 3035, Address: 0x15ac4c, Func Offset: 0xfc
	// Line 3041, Address: 0x15ac54, Func Offset: 0x104
	// Line 3045, Address: 0x15ac88, Func Offset: 0x138
	// Line 3048, Address: 0x15aca0, Func Offset: 0x150
	// Func End, Address: 0x15aca8, Func Offset: 0x158
}

// 
// Start address: 0x15acb0
unsigned int bhCamInfoSet()
{
	_anon16* cp;
	unsigned int v1;
	unsigned int v0;
	// Line 3061, Address: 0x15acb0, Func Offset: 0
	// Line 3071, Address: 0x15acb8, Func Offset: 0x8
	// Line 3061, Address: 0x15acc0, Func Offset: 0x10
	// Line 3062, Address: 0x15accc, Func Offset: 0x1c
	// Line 3063, Address: 0x15acd8, Func Offset: 0x28
	// Line 3064, Address: 0x15ace4, Func Offset: 0x34
	// Line 3065, Address: 0x15acf0, Func Offset: 0x40
	// Line 3071, Address: 0x15acfc, Func Offset: 0x4c
	// Line 3073, Address: 0x15ad14, Func Offset: 0x64
	// Line 3074, Address: 0x15ad1c, Func Offset: 0x6c
	// Line 3075, Address: 0x15ad24, Func Offset: 0x74
	// Line 3076, Address: 0x15ad2c, Func Offset: 0x7c
	// Line 3080, Address: 0x15ad38, Func Offset: 0x88
	// Func End, Address: 0x15ad40, Func Offset: 0x90
}

// 
// Start address: 0x15ad40
unsigned int bhMaskSet()
{
	int v2;
	int v1;
	// Line 3088, Address: 0x15ad40, Func Offset: 0
	// Line 3097, Address: 0x15ad48, Func Offset: 0x8
	// Line 3112, Address: 0x15ad50, Func Offset: 0x10
	// Line 3097, Address: 0x15ad64, Func Offset: 0x24
	// Line 3099, Address: 0x15ad70, Func Offset: 0x30
	// Line 3100, Address: 0x15ad84, Func Offset: 0x44
	// Line 3101, Address: 0x15ad90, Func Offset: 0x50
	// Line 3102, Address: 0x15ad9c, Func Offset: 0x5c
	// Line 3112, Address: 0x15ada4, Func Offset: 0x64
	// Line 3102, Address: 0x15adb0, Func Offset: 0x70
	// Line 3103, Address: 0x15adb4, Func Offset: 0x74
	// Line 3112, Address: 0x15adc0, Func Offset: 0x80
	// Line 3115, Address: 0x15ade8, Func Offset: 0xa8
	// Line 3114, Address: 0x15adec, Func Offset: 0xac
	// Line 3115, Address: 0x15adf0, Func Offset: 0xb0
	// Func End, Address: 0x15adf8, Func Offset: 0xb8
}

// 
// Start address: 0x15ae00
unsigned int bhLipSet()
{
	BH_PWORK* pp;
	int v2;
	int v1;
	int v0;
	// Line 3123, Address: 0x15ae00, Func Offset: 0
	// Line 3132, Address: 0x15ae08, Func Offset: 0x8
	// Line 3145, Address: 0x15ae10, Func Offset: 0x10
	// Line 3132, Address: 0x15ae20, Func Offset: 0x20
	// Line 3133, Address: 0x15ae2c, Func Offset: 0x2c
	// Line 3134, Address: 0x15ae38, Func Offset: 0x38
	// Line 3135, Address: 0x15ae44, Func Offset: 0x44
	// Line 3136, Address: 0x15ae50, Func Offset: 0x50
	// Line 3137, Address: 0x15ae5c, Func Offset: 0x5c
	// Line 3145, Address: 0x15ae64, Func Offset: 0x64
	// Line 3137, Address: 0x15ae70, Func Offset: 0x70
	// Line 3138, Address: 0x15ae74, Func Offset: 0x74
	// Line 3145, Address: 0x15ae80, Func Offset: 0x80
	// Line 3147, Address: 0x15aea4, Func Offset: 0xa4
	// Line 3149, Address: 0x15aea8, Func Offset: 0xa8
	// Line 3152, Address: 0x15aeb0, Func Offset: 0xb0
	// Line 3151, Address: 0x15aeb4, Func Offset: 0xb4
	// Line 3152, Address: 0x15aeb8, Func Offset: 0xb8
	// Func End, Address: 0x15aec0, Func Offset: 0xc0
}

// 
// Start address: 0x15aec0
unsigned int bhMaskStart()
{
	BH_PWORK* pp;
	unsigned int v2;
	int v1;
	// Line 3169, Address: 0x15aec0, Func Offset: 0
	// Line 3182, Address: 0x15aec8, Func Offset: 0x8
	// Line 3169, Address: 0x15aed8, Func Offset: 0x18
	// Line 3171, Address: 0x15aee4, Func Offset: 0x24
	// Line 3172, Address: 0x15aef8, Func Offset: 0x38
	// Line 3173, Address: 0x15af04, Func Offset: 0x44
	// Line 3174, Address: 0x15af10, Func Offset: 0x50
	// Line 3182, Address: 0x15af18, Func Offset: 0x58
	// Line 3174, Address: 0x15af24, Func Offset: 0x64
	// Line 3175, Address: 0x15af28, Func Offset: 0x68
	// Line 3182, Address: 0x15af34, Func Offset: 0x74
	// Line 3184, Address: 0x15af54, Func Offset: 0x94
	// Line 3185, Address: 0x15af5c, Func Offset: 0x9c
	// Line 3186, Address: 0x15af68, Func Offset: 0xa8
	// Line 3187, Address: 0x15af70, Func Offset: 0xb0
	// Line 3190, Address: 0x15af84, Func Offset: 0xc4
	// Func End, Address: 0x15af8c, Func Offset: 0xcc
}

// 
// Start address: 0x15af90
unsigned int bhLipStart()
{
	BH_PWORK* pp;
	unsigned int v2;
	int v1;
	// Line 3207, Address: 0x15af90, Func Offset: 0
	// Line 3220, Address: 0x15af98, Func Offset: 0x8
	// Line 3207, Address: 0x15afa8, Func Offset: 0x18
	// Line 3209, Address: 0x15afb4, Func Offset: 0x24
	// Line 3210, Address: 0x15afc8, Func Offset: 0x38
	// Line 3211, Address: 0x15afd4, Func Offset: 0x44
	// Line 3212, Address: 0x15afe0, Func Offset: 0x50
	// Line 3220, Address: 0x15afe8, Func Offset: 0x58
	// Line 3212, Address: 0x15aff4, Func Offset: 0x64
	// Line 3213, Address: 0x15aff8, Func Offset: 0x68
	// Line 3220, Address: 0x15b004, Func Offset: 0x74
	// Line 3222, Address: 0x15b024, Func Offset: 0x94
	// Line 3223, Address: 0x15b02c, Func Offset: 0x9c
	// Line 3224, Address: 0x15b038, Func Offset: 0xa8
	// Line 3225, Address: 0x15b040, Func Offset: 0xb0
	// Line 3228, Address: 0x15b054, Func Offset: 0xc4
	// Func End, Address: 0x15b05c, Func Offset: 0xcc
}

// 
// Start address: 0x15b060
unsigned int bhMutekiSetPl()
{
	int v0;
	// Line 3241, Address: 0x15b060, Func Offset: 0
	// Line 3242, Address: 0x15b074, Func Offset: 0x14
	// Line 3243, Address: 0x15b080, Func Offset: 0x20
	// Line 3245, Address: 0x15b088, Func Offset: 0x28
	// Line 3246, Address: 0x15b090, Func Offset: 0x30
	// Line 3247, Address: 0x15b0a4, Func Offset: 0x44
	// Line 3248, Address: 0x15b0ac, Func Offset: 0x4c
	// Line 3251, Address: 0x15b0c0, Func Offset: 0x60
	// Func End, Address: 0x15b0c8, Func Offset: 0x68
}

// 
// Start address: 0x15b0d0
unsigned int bhLookGsetPlStart()
{
	int v1;
	// Line 3264, Address: 0x15b0d0, Func Offset: 0
	// Line 3269, Address: 0x15b0d8, Func Offset: 0x8
	// Line 3268, Address: 0x15b0dc, Func Offset: 0xc
	// Line 3264, Address: 0x15b0e4, Func Offset: 0x14
	// Line 3265, Address: 0x15b0f0, Func Offset: 0x20
	// Line 3266, Address: 0x15b0fc, Func Offset: 0x2c
	// Line 3268, Address: 0x15b108, Func Offset: 0x38
	// Line 3269, Address: 0x15b10c, Func Offset: 0x3c
	// Line 3268, Address: 0x15b110, Func Offset: 0x40
	// Line 3272, Address: 0x15b114, Func Offset: 0x44
	// Line 3268, Address: 0x15b118, Func Offset: 0x48
	// Line 3269, Address: 0x15b120, Func Offset: 0x50
	// Line 3272, Address: 0x15b128, Func Offset: 0x58
	// Line 3273, Address: 0x15b130, Func Offset: 0x60
	// Line 3274, Address: 0x15b194, Func Offset: 0xc4
	// Line 3275, Address: 0x15b19c, Func Offset: 0xcc
	// Line 3277, Address: 0x15b1f4, Func Offset: 0x124
	// Line 3280, Address: 0x15b1fc, Func Offset: 0x12c
	// Line 3277, Address: 0x15b200, Func Offset: 0x130
	// Line 3280, Address: 0x15b208, Func Offset: 0x138
	// Line 3281, Address: 0x15b210, Func Offset: 0x140
	// Line 3282, Address: 0x15b274, Func Offset: 0x1a4
	// Line 3283, Address: 0x15b27c, Func Offset: 0x1ac
	// Line 3285, Address: 0x15b2d4, Func Offset: 0x204
	// Line 3288, Address: 0x15b2dc, Func Offset: 0x20c
	// Line 3285, Address: 0x15b2e0, Func Offset: 0x210
	// Line 3288, Address: 0x15b2e8, Func Offset: 0x218
	// Line 3289, Address: 0x15b2f0, Func Offset: 0x220
	// Line 3290, Address: 0x15b354, Func Offset: 0x284
	// Line 3291, Address: 0x15b35c, Func Offset: 0x28c
	// Line 3293, Address: 0x15b3b4, Func Offset: 0x2e4
	// Line 3294, Address: 0x15b3bc, Func Offset: 0x2ec
	// Line 3293, Address: 0x15b3c0, Func Offset: 0x2f0
	// Line 3295, Address: 0x15b3c8, Func Offset: 0x2f8
	// Func End, Address: 0x15b3d0, Func Offset: 0x300
}

// 
// Start address: 0x15b3d0
unsigned int bhLookGsetPlStop()
{
	// Line 3304, Address: 0x15b3d0, Func Offset: 0
	// Line 3306, Address: 0x15b3d8, Func Offset: 0x8
	// Line 3307, Address: 0x15b3dc, Func Offset: 0xc
	// Line 3306, Address: 0x15b3e0, Func Offset: 0x10
	// Line 3304, Address: 0x15b3e8, Func Offset: 0x18
	// Line 3306, Address: 0x15b3f4, Func Offset: 0x24
	// Line 3308, Address: 0x15b400, Func Offset: 0x30
	// Func End, Address: 0x15b408, Func Offset: 0x38
}

// 
// Start address: 0x15b410
unsigned int bhSoundFadeOut()
{
	// Line 3318, Address: 0x15b410, Func Offset: 0
	// Line 3319, Address: 0x15b418, Func Offset: 0x8
	// Line 3318, Address: 0x15b41c, Func Offset: 0xc
	// Line 3320, Address: 0x15b424, Func Offset: 0x14
	// Func End, Address: 0x15b42c, Func Offset: 0x1c
}

// 
// Start address: 0x15b430
unsigned int bhDefModelSet()
{
	BH_PWORK* epw;
	unsigned int v3;
	unsigned int v2;
	int v1;
	int v0;
	// Line 3335, Address: 0x15b430, Func Offset: 0
	// Line 3345, Address: 0x15b438, Func Offset: 0x8
	// Line 3335, Address: 0x15b43c, Func Offset: 0xc
	// Line 3336, Address: 0x15b448, Func Offset: 0x18
	// Line 3337, Address: 0x15b454, Func Offset: 0x24
	// Line 3338, Address: 0x15b460, Func Offset: 0x30
	// Line 3339, Address: 0x15b46c, Func Offset: 0x3c
	// Line 3340, Address: 0x15b478, Func Offset: 0x48
	// Line 3341, Address: 0x15b484, Func Offset: 0x54
	// Line 3342, Address: 0x15b490, Func Offset: 0x60
	// Line 3343, Address: 0x15b49c, Func Offset: 0x6c
	// Line 3345, Address: 0x15b4a4, Func Offset: 0x74
	// Line 3347, Address: 0x15b4c8, Func Offset: 0x98
	// Line 3348, Address: 0x15b4cc, Func Offset: 0x9c
	// Line 3354, Address: 0x15b4d4, Func Offset: 0xa4
	// Line 3355, Address: 0x15b510, Func Offset: 0xe0
	// Line 3360, Address: 0x15b518, Func Offset: 0xe8
	// Line 3364, Address: 0x15b544, Func Offset: 0x114
	// Line 3365, Address: 0x15b54c, Func Offset: 0x11c
	// Line 3366, Address: 0x15b574, Func Offset: 0x144
	// Line 3367, Address: 0x15b57c, Func Offset: 0x14c
	// Line 3370, Address: 0x15b5ac, Func Offset: 0x17c
	// Func End, Address: 0x15b5b4, Func Offset: 0x184
}

// 
// Start address: 0x15b5c0
unsigned int bhItmAspdSet()
{
	unsigned int v1;
	unsigned int v0;
	// Line 3382, Address: 0x15b5c0, Func Offset: 0
	// Line 3395, Address: 0x15b5c8, Func Offset: 0x8
	// Line 3393, Address: 0x15b5cc, Func Offset: 0xc
	// Line 3382, Address: 0x15b5d4, Func Offset: 0x14
	// Line 3383, Address: 0x15b5e0, Func Offset: 0x20
	// Line 3384, Address: 0x15b5ec, Func Offset: 0x2c
	// Line 3385, Address: 0x15b5f8, Func Offset: 0x38
	// Line 3393, Address: 0x15b600, Func Offset: 0x40
	// Line 3385, Address: 0x15b610, Func Offset: 0x50
	// Line 3393, Address: 0x15b614, Func Offset: 0x54
	// Line 3386, Address: 0x15b618, Func Offset: 0x58
	// Line 3393, Address: 0x15b624, Func Offset: 0x64
	// Line 3396, Address: 0x15b634, Func Offset: 0x74
	// Func End, Address: 0x15b63c, Func Offset: 0x7c
}

// 
// Start address: 0x15b640
unsigned int bhEffDispSet()
{
	_anon0* e_ep;
	unsigned int v1;
	unsigned int v0;
	// Line 3408, Address: 0x15b640, Func Offset: 0
	// Line 3418, Address: 0x15b648, Func Offset: 0x8
	// Line 3408, Address: 0x15b658, Func Offset: 0x18
	// Line 3409, Address: 0x15b664, Func Offset: 0x24
	// Line 3410, Address: 0x15b670, Func Offset: 0x30
	// Line 3418, Address: 0x15b67c, Func Offset: 0x3c
	// Line 3411, Address: 0x15b684, Func Offset: 0x44
	// Line 3412, Address: 0x15b690, Func Offset: 0x50
	// Line 3418, Address: 0x15b69c, Func Offset: 0x5c
	// Line 3419, Address: 0x15b6bc, Func Offset: 0x7c
	// Line 3420, Address: 0x15b6c4, Func Offset: 0x84
	// Line 3421, Address: 0x15b6d0, Func Offset: 0x90
	// Line 3422, Address: 0x15b6d8, Func Offset: 0x98
	// Line 3425, Address: 0x15b6ec, Func Offset: 0xac
	// Func End, Address: 0x15b6f4, Func Offset: 0xb4
}

// 
// Start address: 0x15b700
unsigned int bhEffAmbSet()
{
	unsigned int v3;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 3437, Address: 0x15b700, Func Offset: 0
	// Line 3447, Address: 0x15b708, Func Offset: 0x8
	// Line 3437, Address: 0x15b714, Func Offset: 0x14
	// Line 3438, Address: 0x15b720, Func Offset: 0x20
	// Line 3439, Address: 0x15b72c, Func Offset: 0x2c
	// Line 3440, Address: 0x15b738, Func Offset: 0x38
	// Line 3441, Address: 0x15b744, Func Offset: 0x44
	// Line 3442, Address: 0x15b750, Func Offset: 0x50
	// Line 3443, Address: 0x15b75c, Func Offset: 0x5c
	// Line 3444, Address: 0x15b768, Func Offset: 0x68
	// Line 3445, Address: 0x15b774, Func Offset: 0x74
	// Line 3447, Address: 0x15b77c, Func Offset: 0x7c
	// Line 3448, Address: 0x15b7b8, Func Offset: 0xb8
	// Line 3447, Address: 0x15b7c0, Func Offset: 0xc0
	// Line 3448, Address: 0x15b7c4, Func Offset: 0xc4
	// Line 3447, Address: 0x15b7c8, Func Offset: 0xc8
	// Line 3448, Address: 0x15b7cc, Func Offset: 0xcc
	// Line 3449, Address: 0x15b808, Func Offset: 0x108
	// Line 3448, Address: 0x15b814, Func Offset: 0x114
	// Line 3449, Address: 0x15b818, Func Offset: 0x118
	// Line 3450, Address: 0x15b854, Func Offset: 0x154
	// Line 3449, Address: 0x15b858, Func Offset: 0x158
	// Line 3451, Address: 0x15b85c, Func Offset: 0x15c
	// Func End, Address: 0x15b864, Func Offset: 0x164
}

// 
// Start address: 0x15b870
unsigned int bhObjLinkSetObjEne()
{
	BH_PWORK* e_ep;
	int v1;
	int v0;
	// Line 3466, Address: 0x15b870, Func Offset: 0
	// Line 3477, Address: 0x15b878, Func Offset: 0x8
	// Line 3466, Address: 0x15b888, Func Offset: 0x18
	// Line 3478, Address: 0x15b88c, Func Offset: 0x1c
	// Line 3466, Address: 0x15b894, Func Offset: 0x24
	// Line 3467, Address: 0x15b89c, Func Offset: 0x2c
	// Line 3468, Address: 0x15b8a8, Func Offset: 0x38
	// Line 3478, Address: 0x15b8b4, Func Offset: 0x44
	// Line 3477, Address: 0x15b8bc, Func Offset: 0x4c
	// Line 3478, Address: 0x15b8c0, Func Offset: 0x50
	// Line 3469, Address: 0x15b8c8, Func Offset: 0x58
	// Line 3478, Address: 0x15b8d0, Func Offset: 0x60
	// Line 3469, Address: 0x15b8e0, Func Offset: 0x70
	// Line 3478, Address: 0x15b8e4, Func Offset: 0x74
	// Line 3480, Address: 0x15b8e8, Func Offset: 0x78
	// Line 3477, Address: 0x15b8ec, Func Offset: 0x7c
	// Line 3478, Address: 0x15b918, Func Offset: 0xa8
	// Line 3480, Address: 0x15b91c, Func Offset: 0xac
	// Line 3481, Address: 0x15b92c, Func Offset: 0xbc
	// Line 3484, Address: 0x15b938, Func Offset: 0xc8
	// Line 3482, Address: 0x15b93c, Func Offset: 0xcc
	// Line 3484, Address: 0x15b940, Func Offset: 0xd0
	// Line 3486, Address: 0x15b950, Func Offset: 0xe0
	// Line 3487, Address: 0x15b964, Func Offset: 0xf4
	// Line 3488, Address: 0x15b96c, Func Offset: 0xfc
	// Line 3489, Address: 0x15b974, Func Offset: 0x104
	// Line 3491, Address: 0x15b984, Func Offset: 0x114
	// Line 3492, Address: 0x15b998, Func Offset: 0x128
	// Line 3494, Address: 0x15b9a4, Func Offset: 0x134
	// Line 3497, Address: 0x15b9b0, Func Offset: 0x140
	// Line 3498, Address: 0x15b9bc, Func Offset: 0x14c
	// Line 3499, Address: 0x15ba18, Func Offset: 0x1a8
	// Line 3500, Address: 0x15ba20, Func Offset: 0x1b0
	// Line 3502, Address: 0x15ba70, Func Offset: 0x200
	// Line 3505, Address: 0x15ba78, Func Offset: 0x208
	// Line 3502, Address: 0x15ba7c, Func Offset: 0x20c
	// Line 3505, Address: 0x15ba84, Func Offset: 0x214
	// Line 3506, Address: 0x15ba8c, Func Offset: 0x21c
	// Line 3507, Address: 0x15bae8, Func Offset: 0x278
	// Line 3508, Address: 0x15baf0, Func Offset: 0x280
	// Line 3510, Address: 0x15bb40, Func Offset: 0x2d0
	// Line 3513, Address: 0x15bb48, Func Offset: 0x2d8
	// Line 3510, Address: 0x15bb4c, Func Offset: 0x2dc
	// Line 3513, Address: 0x15bb54, Func Offset: 0x2e4
	// Line 3514, Address: 0x15bb5c, Func Offset: 0x2ec
	// Line 3515, Address: 0x15bbb8, Func Offset: 0x348
	// Line 3516, Address: 0x15bbc0, Func Offset: 0x350
	// Line 3518, Address: 0x15bc10, Func Offset: 0x3a0
	// Line 3520, Address: 0x15bc18, Func Offset: 0x3a8
	// Line 3518, Address: 0x15bc1c, Func Offset: 0x3ac
	// Line 3521, Address: 0x15bc24, Func Offset: 0x3b4
	// Func End, Address: 0x15bc2c, Func Offset: 0x3bc
}

// 
// Start address: 0x15bc30
unsigned int bhObjLinkSetObjItem()
{
	int v1;
	// Line 3536, Address: 0x15bc30, Func Offset: 0
	// Line 3546, Address: 0x15bc38, Func Offset: 0x8
	// Line 3536, Address: 0x15bc40, Func Offset: 0x10
	// Line 3537, Address: 0x15bc4c, Func Offset: 0x1c
	// Line 3538, Address: 0x15bc58, Func Offset: 0x28
	// Line 3546, Address: 0x15bc64, Func Offset: 0x34
	// Line 3548, Address: 0x15bca0, Func Offset: 0x70
	// Line 3546, Address: 0x15bca4, Func Offset: 0x74
	// Line 3548, Address: 0x15bcc0, Func Offset: 0x90
	// Line 3550, Address: 0x15bcc4, Func Offset: 0x94
	// Line 3548, Address: 0x15bccc, Func Offset: 0x9c
	// Line 3550, Address: 0x15bcd8, Func Offset: 0xa8
	// Line 3549, Address: 0x15bce4, Func Offset: 0xb4
	// Line 3550, Address: 0x15bcec, Func Offset: 0xbc
	// Line 3549, Address: 0x15bcf0, Func Offset: 0xc0
	// Line 3552, Address: 0x15bcf4, Func Offset: 0xc4
	// Line 3550, Address: 0x15bcf8, Func Offset: 0xc8
	// Line 3552, Address: 0x15bcfc, Func Offset: 0xcc
	// Line 3554, Address: 0x15bd0c, Func Offset: 0xdc
	// Line 3555, Address: 0x15bd20, Func Offset: 0xf0
	// Line 3556, Address: 0x15bd40, Func Offset: 0x110
	// Line 3557, Address: 0x15bd48, Func Offset: 0x118
	// Line 3559, Address: 0x15bd70, Func Offset: 0x140
	// Line 3560, Address: 0x15bd84, Func Offset: 0x154
	// Line 3562, Address: 0x15bd90, Func Offset: 0x160
	// Line 3565, Address: 0x15bd9c, Func Offset: 0x16c
	// Line 3566, Address: 0x15bda8, Func Offset: 0x178
	// Line 3567, Address: 0x15be18, Func Offset: 0x1e8
	// Line 3568, Address: 0x15be20, Func Offset: 0x1f0
	// Line 3570, Address: 0x15be84, Func Offset: 0x254
	// Line 3573, Address: 0x15be8c, Func Offset: 0x25c
	// Line 3570, Address: 0x15be90, Func Offset: 0x260
	// Line 3573, Address: 0x15be98, Func Offset: 0x268
	// Line 3574, Address: 0x15bea0, Func Offset: 0x270
	// Line 3575, Address: 0x15bf10, Func Offset: 0x2e0
	// Line 3576, Address: 0x15bf18, Func Offset: 0x2e8
	// Line 3578, Address: 0x15bf7c, Func Offset: 0x34c
	// Line 3581, Address: 0x15bf84, Func Offset: 0x354
	// Line 3578, Address: 0x15bf88, Func Offset: 0x358
	// Line 3581, Address: 0x15bf90, Func Offset: 0x360
	// Line 3582, Address: 0x15bf98, Func Offset: 0x368
	// Line 3583, Address: 0x15c008, Func Offset: 0x3d8
	// Line 3584, Address: 0x15c010, Func Offset: 0x3e0
	// Line 3586, Address: 0x15c074, Func Offset: 0x444
	// Line 3588, Address: 0x15c07c, Func Offset: 0x44c
	// Line 3586, Address: 0x15c080, Func Offset: 0x450
	// Line 3589, Address: 0x15c088, Func Offset: 0x458
	// Func End, Address: 0x15c090, Func Offset: 0x460
}

// 
// Start address: 0x15c090
unsigned int bhObjLinkSetEneItem()
{
	int v1;
	// Line 3604, Address: 0x15c090, Func Offset: 0
	// Line 3616, Address: 0x15c098, Func Offset: 0x8
	// Line 3604, Address: 0x15c0a8, Func Offset: 0x18
	// Line 3616, Address: 0x15c0ac, Func Offset: 0x1c
	// Line 3604, Address: 0x15c0b4, Func Offset: 0x24
	// Line 3605, Address: 0x15c0bc, Func Offset: 0x2c
	// Line 3606, Address: 0x15c0c8, Func Offset: 0x38
	// Line 3616, Address: 0x15c0d4, Func Offset: 0x44
	// Line 3618, Address: 0x15c100, Func Offset: 0x70
	// Line 3616, Address: 0x15c104, Func Offset: 0x74
	// Line 3618, Address: 0x15c13c, Func Offset: 0xac
	// Line 3620, Address: 0x15c140, Func Offset: 0xb0
	// Line 3618, Address: 0x15c148, Func Offset: 0xb8
	// Line 3620, Address: 0x15c154, Func Offset: 0xc4
	// Line 3619, Address: 0x15c160, Func Offset: 0xd0
	// Line 3620, Address: 0x15c168, Func Offset: 0xd8
	// Line 3619, Address: 0x15c16c, Func Offset: 0xdc
	// Line 3622, Address: 0x15c170, Func Offset: 0xe0
	// Line 3620, Address: 0x15c174, Func Offset: 0xe4
	// Line 3622, Address: 0x15c178, Func Offset: 0xe8
	// Line 3624, Address: 0x15c188, Func Offset: 0xf8
	// Line 3625, Address: 0x15c19c, Func Offset: 0x10c
	// Line 3626, Address: 0x15c1bc, Func Offset: 0x12c
	// Line 3627, Address: 0x15c1c4, Func Offset: 0x134
	// Line 3629, Address: 0x15c1ec, Func Offset: 0x15c
	// Line 3630, Address: 0x15c200, Func Offset: 0x170
	// Line 3632, Address: 0x15c20c, Func Offset: 0x17c
	// Line 3635, Address: 0x15c218, Func Offset: 0x188
	// Line 3636, Address: 0x15c224, Func Offset: 0x194
	// Line 3637, Address: 0x15c294, Func Offset: 0x204
	// Line 3638, Address: 0x15c29c, Func Offset: 0x20c
	// Line 3640, Address: 0x15c300, Func Offset: 0x270
	// Line 3643, Address: 0x15c308, Func Offset: 0x278
	// Line 3640, Address: 0x15c30c, Func Offset: 0x27c
	// Line 3643, Address: 0x15c314, Func Offset: 0x284
	// Line 3644, Address: 0x15c31c, Func Offset: 0x28c
	// Line 3645, Address: 0x15c38c, Func Offset: 0x2fc
	// Line 3646, Address: 0x15c394, Func Offset: 0x304
	// Line 3648, Address: 0x15c3f8, Func Offset: 0x368
	// Line 3651, Address: 0x15c400, Func Offset: 0x370
	// Line 3648, Address: 0x15c404, Func Offset: 0x374
	// Line 3651, Address: 0x15c40c, Func Offset: 0x37c
	// Line 3652, Address: 0x15c414, Func Offset: 0x384
	// Line 3653, Address: 0x15c484, Func Offset: 0x3f4
	// Line 3654, Address: 0x15c48c, Func Offset: 0x3fc
	// Line 3656, Address: 0x15c4f0, Func Offset: 0x460
	// Line 3658, Address: 0x15c4f8, Func Offset: 0x468
	// Line 3656, Address: 0x15c4fc, Func Offset: 0x46c
	// Line 3659, Address: 0x15c504, Func Offset: 0x474
	// Func End, Address: 0x15c50c, Func Offset: 0x47c
}

// 
// Start address: 0x15c510
unsigned int bhObjLinkSetEneEne()
{
	BH_PWORK* e_ep2;
	int v1;
	int v0;
	// Line 3676, Address: 0x15c510, Func Offset: 0
	// Line 3690, Address: 0x15c518, Func Offset: 0x8
	// Line 3692, Address: 0x15c520, Func Offset: 0x10
	// Line 3690, Address: 0x15c528, Func Offset: 0x18
	// Line 3676, Address: 0x15c530, Func Offset: 0x20
	// Line 3677, Address: 0x15c53c, Func Offset: 0x2c
	// Line 3678, Address: 0x15c548, Func Offset: 0x38
	// Line 3690, Address: 0x15c554, Func Offset: 0x44
	// Line 3679, Address: 0x15c558, Func Offset: 0x48
	// Line 3692, Address: 0x15c560, Func Offset: 0x50
	// Line 3679, Address: 0x15c568, Func Offset: 0x58
	// Line 3692, Address: 0x15c56c, Func Offset: 0x5c
	// Line 3694, Address: 0x15c574, Func Offset: 0x64
	// Line 3692, Address: 0x15c578, Func Offset: 0x68
	// Line 3690, Address: 0x15c57c, Func Offset: 0x6c
	// Line 3692, Address: 0x15c590, Func Offset: 0x80
	// Line 3690, Address: 0x15c5a8, Func Offset: 0x98
	// Line 3692, Address: 0x15c5c0, Func Offset: 0xb0
	// Line 3694, Address: 0x15c5c4, Func Offset: 0xb4
	// Line 3695, Address: 0x15c5d4, Func Offset: 0xc4
	// Line 3698, Address: 0x15c5e0, Func Offset: 0xd0
	// Line 3696, Address: 0x15c5e4, Func Offset: 0xd4
	// Line 3698, Address: 0x15c5e8, Func Offset: 0xd8
	// Line 3700, Address: 0x15c5f8, Func Offset: 0xe8
	// Line 3701, Address: 0x15c60c, Func Offset: 0xfc
	// Line 3702, Address: 0x15c614, Func Offset: 0x104
	// Line 3703, Address: 0x15c61c, Func Offset: 0x10c
	// Line 3705, Address: 0x15c62c, Func Offset: 0x11c
	// Line 3706, Address: 0x15c640, Func Offset: 0x130
	// Line 3708, Address: 0x15c64c, Func Offset: 0x13c
	// Line 3711, Address: 0x15c658, Func Offset: 0x148
	// Line 3712, Address: 0x15c664, Func Offset: 0x154
	// Line 3713, Address: 0x15c6c0, Func Offset: 0x1b0
	// Line 3714, Address: 0x15c6c8, Func Offset: 0x1b8
	// Line 3716, Address: 0x15c718, Func Offset: 0x208
	// Line 3719, Address: 0x15c720, Func Offset: 0x210
	// Line 3716, Address: 0x15c724, Func Offset: 0x214
	// Line 3719, Address: 0x15c72c, Func Offset: 0x21c
	// Line 3720, Address: 0x15c734, Func Offset: 0x224
	// Line 3721, Address: 0x15c790, Func Offset: 0x280
	// Line 3722, Address: 0x15c798, Func Offset: 0x288
	// Line 3724, Address: 0x15c7e8, Func Offset: 0x2d8
	// Line 3727, Address: 0x15c7f0, Func Offset: 0x2e0
	// Line 3724, Address: 0x15c7f4, Func Offset: 0x2e4
	// Line 3727, Address: 0x15c7fc, Func Offset: 0x2ec
	// Line 3728, Address: 0x15c804, Func Offset: 0x2f4
	// Line 3729, Address: 0x15c860, Func Offset: 0x350
	// Line 3730, Address: 0x15c868, Func Offset: 0x358
	// Line 3732, Address: 0x15c8b8, Func Offset: 0x3a8
	// Line 3734, Address: 0x15c8c0, Func Offset: 0x3b0
	// Line 3732, Address: 0x15c8c4, Func Offset: 0x3b4
	// Line 3735, Address: 0x15c8cc, Func Offset: 0x3bc
	// Func End, Address: 0x15c8d4, Func Offset: 0x3c4
}

// 
// Start address: 0x15c8e0
unsigned int bhDelObjSe()
{
	int v0;
	// Line 3743, Address: 0x15c8e0, Func Offset: 0
	// Line 3746, Address: 0x15c8e8, Func Offset: 0x8
	// Line 3747, Address: 0x15c8fc, Func Offset: 0x1c
	// Line 3748, Address: 0x15c908, Func Offset: 0x28
	// Line 3750, Address: 0x15c910, Func Offset: 0x30
	// Line 3752, Address: 0x15c918, Func Offset: 0x38
	// Line 3751, Address: 0x15c91c, Func Offset: 0x3c
	// Line 3752, Address: 0x15c920, Func Offset: 0x40
	// Func End, Address: 0x15c928, Func Offset: 0x48
}

// 
// Start address: 0x15c930
unsigned int bhLightTypeSet()
{
	_anon11* lp;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 3764, Address: 0x15c930, Func Offset: 0
	// Line 3780, Address: 0x15c938, Func Offset: 0x8
	// Line 3776, Address: 0x15c93c, Func Offset: 0xc
	// Line 3764, Address: 0x15c944, Func Offset: 0x14
	// Line 3765, Address: 0x15c950, Func Offset: 0x20
	// Line 3766, Address: 0x15c95c, Func Offset: 0x2c
	// Line 3767, Address: 0x15c968, Func Offset: 0x38
	// Line 3776, Address: 0x15c970, Func Offset: 0x40
	// Line 3767, Address: 0x15c97c, Func Offset: 0x4c
	// Line 3768, Address: 0x15c980, Func Offset: 0x50
	// Line 3769, Address: 0x15c98c, Func Offset: 0x5c
	// Line 3770, Address: 0x15c998, Func Offset: 0x68
	// Line 3776, Address: 0x15c9a4, Func Offset: 0x74
	// Line 3777, Address: 0x15c9ac, Func Offset: 0x7c
	// Line 3781, Address: 0x15c9b0, Func Offset: 0x80
	// Func End, Address: 0x15c9b8, Func Offset: 0x88
}

// 
// Start address: 0x15c9c0
unsigned int bhFogColorSet()
{
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 3792, Address: 0x15c9c0, Func Offset: 0
	// Line 3793, Address: 0x15c9d4, Func Offset: 0x14
	// Line 3794, Address: 0x15c9e0, Func Offset: 0x20
	// Line 3795, Address: 0x15c9ec, Func Offset: 0x2c
	// Line 3796, Address: 0x15c9f8, Func Offset: 0x38
	// Line 3797, Address: 0x15ca04, Func Offset: 0x44
	// Line 3798, Address: 0x15ca10, Func Offset: 0x50
	// Line 3799, Address: 0x15ca1c, Func Offset: 0x5c
	// Line 3800, Address: 0x15ca28, Func Offset: 0x68
	// Line 3801, Address: 0x15ca34, Func Offset: 0x74
	// Line 3802, Address: 0x15ca40, Func Offset: 0x80
	// Line 3804, Address: 0x15ca48, Func Offset: 0x88
	// Line 3805, Address: 0x15ca50, Func Offset: 0x90
	// Line 3806, Address: 0x15ca70, Func Offset: 0xb0
	// Line 3805, Address: 0x15ca74, Func Offset: 0xb4
	// Line 3806, Address: 0x15ca80, Func Offset: 0xc0
	// Line 3807, Address: 0x15ca8c, Func Offset: 0xcc
	// Line 3806, Address: 0x15ca90, Func Offset: 0xd0
	// Line 3807, Address: 0x15ca98, Func Offset: 0xd8
	// Line 3808, Address: 0x15caa4, Func Offset: 0xe4
	// Line 3809, Address: 0x15caac, Func Offset: 0xec
	// Line 3810, Address: 0x15cac0, Func Offset: 0x100
	// Line 3809, Address: 0x15cac4, Func Offset: 0x104
	// Line 3810, Address: 0x15cacc, Func Offset: 0x10c
	// Line 3815, Address: 0x15cadc, Func Offset: 0x11c
	// Func End, Address: 0x15cae4, Func Offset: 0x124
}

// 
// Start address: 0x15caf0
unsigned int bhEffectSandSet()
{
	_anon39 pos;
	BH_PWORK* epw;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 3824, Address: 0x15caf0, Func Offset: 0
	// Line 3832, Address: 0x15caf8, Func Offset: 0x8
	// Line 3845, Address: 0x15cb00, Func Offset: 0x10
	// Line 3832, Address: 0x15cb10, Func Offset: 0x20
	// Line 3833, Address: 0x15cb1c, Func Offset: 0x2c
	// Line 3834, Address: 0x15cb28, Func Offset: 0x38
	// Line 3835, Address: 0x15cb34, Func Offset: 0x44
	// Line 3845, Address: 0x15cb3c, Func Offset: 0x4c
	// Line 3835, Address: 0x15cb48, Func Offset: 0x58
	// Line 3836, Address: 0x15cb4c, Func Offset: 0x5c
	// Line 3837, Address: 0x15cb58, Func Offset: 0x68
	// Line 3838, Address: 0x15cb64, Func Offset: 0x74
	// Line 3845, Address: 0x15cb70, Func Offset: 0x80
	// Line 3847, Address: 0x15cb90, Func Offset: 0xa0
	// Line 3849, Address: 0x15cb98, Func Offset: 0xa8
	// Line 3850, Address: 0x15cba4, Func Offset: 0xb4
	// Line 3851, Address: 0x15cc00, Func Offset: 0x110
	// Line 3852, Address: 0x15cc08, Func Offset: 0x118
	// Line 3854, Address: 0x15cc58, Func Offset: 0x168
	// Line 3857, Address: 0x15cc60, Func Offset: 0x170
	// Line 3854, Address: 0x15cc64, Func Offset: 0x174
	// Line 3857, Address: 0x15cc6c, Func Offset: 0x17c
	// Line 3858, Address: 0x15cc74, Func Offset: 0x184
	// Line 3859, Address: 0x15ccd0, Func Offset: 0x1e0
	// Line 3860, Address: 0x15ccd8, Func Offset: 0x1e8
	// Line 3862, Address: 0x15cd28, Func Offset: 0x238
	// Line 3865, Address: 0x15cd30, Func Offset: 0x240
	// Line 3862, Address: 0x15cd34, Func Offset: 0x244
	// Line 3865, Address: 0x15cd3c, Func Offset: 0x24c
	// Line 3866, Address: 0x15cd44, Func Offset: 0x254
	// Line 3867, Address: 0x15cda0, Func Offset: 0x2b0
	// Line 3868, Address: 0x15cda8, Func Offset: 0x2b8
	// Line 3870, Address: 0x15cdf8, Func Offset: 0x308
	// Line 3871, Address: 0x15ce08, Func Offset: 0x318
	// Line 3876, Address: 0x15ce10, Func Offset: 0x320
	// Line 3878, Address: 0x15cec8, Func Offset: 0x3d8
	// Line 3884, Address: 0x15ced0, Func Offset: 0x3e0
	// Line 3878, Address: 0x15ced4, Func Offset: 0x3e4
	// Line 3884, Address: 0x15cedc, Func Offset: 0x3ec
	// Line 3886, Address: 0x15cf90, Func Offset: 0x4a0
	// Line 3892, Address: 0x15cf98, Func Offset: 0x4a8
	// Line 3886, Address: 0x15cf9c, Func Offset: 0x4ac
	// Line 3892, Address: 0x15cfa4, Func Offset: 0x4b4
	// Line 3894, Address: 0x15d058, Func Offset: 0x568
	// Line 3895, Address: 0x15d06c, Func Offset: 0x57c
	// Line 3897, Address: 0x15d078, Func Offset: 0x588
	// Line 3898, Address: 0x15d07c, Func Offset: 0x58c
	// Line 3901, Address: 0x15d088, Func Offset: 0x598
	// Line 3904, Address: 0x15d090, Func Offset: 0x5a0
	// Line 3901, Address: 0x15d094, Func Offset: 0x5a4
	// Line 3902, Address: 0x15d098, Func Offset: 0x5a8
	// Line 3904, Address: 0x15d0a0, Func Offset: 0x5b0
	// Line 3907, Address: 0x15d0a8, Func Offset: 0x5b8
	// Line 3906, Address: 0x15d0ac, Func Offset: 0x5bc
	// Line 3907, Address: 0x15d0b0, Func Offset: 0x5c0
	// Func End, Address: 0x15d0b8, Func Offset: 0x5c8
}

// 
// Start address: 0x15d0c0
unsigned int bhPlItemBlockCk()
{
	int v1;
	int v0;
	unsigned int wicnt;
	unsigned int icnt;
	unsigned int cnt;
	// Line 3919, Address: 0x15d0c0, Func Offset: 0
	// Line 3925, Address: 0x15d0c8, Func Offset: 0x8
	// Line 3919, Address: 0x15d0d4, Func Offset: 0x14
	// Line 3920, Address: 0x15d0e0, Func Offset: 0x20
	// Line 3921, Address: 0x15d0ec, Func Offset: 0x2c
	// Line 3922, Address: 0x15d0f8, Func Offset: 0x38
	// Line 3923, Address: 0x15d104, Func Offset: 0x44
	// Line 3925, Address: 0x15d110, Func Offset: 0x50
	// Line 3926, Address: 0x15d120, Func Offset: 0x60
	// Line 3927, Address: 0x15d15c, Func Offset: 0x9c
	// Line 3928, Address: 0x15d168, Func Offset: 0xa8
	// Line 3929, Address: 0x15d16c, Func Offset: 0xac
	// Line 3930, Address: 0x15d170, Func Offset: 0xb0
	// Line 3938, Address: 0x15d1b0, Func Offset: 0xf0
	// Line 3940, Address: 0x15d1b4, Func Offset: 0xf4
	// Line 3938, Address: 0x15d1b8, Func Offset: 0xf8
	// Line 3941, Address: 0x15d1bc, Func Offset: 0xfc
	// Line 3942, Address: 0x15d1cc, Func Offset: 0x10c
	// Line 3943, Address: 0x15d1d4, Func Offset: 0x114
	// Line 3944, Address: 0x15d210, Func Offset: 0x150
	// Line 3945, Address: 0x15d21c, Func Offset: 0x15c
	// Line 3947, Address: 0x15d220, Func Offset: 0x160
	// Line 3955, Address: 0x15d260, Func Offset: 0x1a0
	// Line 3957, Address: 0x15d264, Func Offset: 0x1a4
	// Line 3955, Address: 0x15d268, Func Offset: 0x1a8
	// Line 3958, Address: 0x15d26c, Func Offset: 0x1ac
	// Line 3959, Address: 0x15d27c, Func Offset: 0x1bc
	// Line 3963, Address: 0x15d280, Func Offset: 0x1c0
	// Line 3964, Address: 0x15d2a8, Func Offset: 0x1e8
	// Line 3965, Address: 0x15d2b4, Func Offset: 0x1f4
	// Line 3966, Address: 0x15d2bc, Func Offset: 0x1fc
	// Line 3967, Address: 0x15d2c8, Func Offset: 0x208
	// Line 3968, Address: 0x15d2d0, Func Offset: 0x210
	// Line 3969, Address: 0x15d2dc, Func Offset: 0x21c
	// Line 3971, Address: 0x15d2e8, Func Offset: 0x228
	// Line 3972, Address: 0x15d2ec, Func Offset: 0x22c
	// Func End, Address: 0x15d2f4, Func Offset: 0x234
}

// 
// Start address: 0x15d300
unsigned int bhEffBloodSet()
{
	_anon39 ofp;
	BH_PWORK* epw;
	int v2;
	int v1;
	int v0;
	// Line 3981, Address: 0x15d300, Func Offset: 0
	// Line 3987, Address: 0x15d310, Func Offset: 0x10
	// Line 4000, Address: 0x15d318, Func Offset: 0x18
	// Line 3987, Address: 0x15d328, Func Offset: 0x28
	// Line 3988, Address: 0x15d334, Func Offset: 0x34
	// Line 3989, Address: 0x15d340, Func Offset: 0x40
	// Line 3990, Address: 0x15d34c, Func Offset: 0x4c
	// Line 4000, Address: 0x15d354, Func Offset: 0x54
	// Line 3990, Address: 0x15d360, Func Offset: 0x60
	// Line 3991, Address: 0x15d364, Func Offset: 0x64
	// Line 3992, Address: 0x15d370, Func Offset: 0x70
	// Line 3993, Address: 0x15d37c, Func Offset: 0x7c
	// Line 4000, Address: 0x15d388, Func Offset: 0x88
	// Line 4004, Address: 0x15d394, Func Offset: 0x94
	// Line 4000, Address: 0x15d398, Func Offset: 0x98
	// Line 4004, Address: 0x15d3b0, Func Offset: 0xb0
	// Line 4005, Address: 0x15d3b8, Func Offset: 0xb8
	// Line 4006, Address: 0x15d414, Func Offset: 0x114
	// Line 4007, Address: 0x15d41c, Func Offset: 0x11c
	// Line 4009, Address: 0x15d46c, Func Offset: 0x16c
	// Line 4012, Address: 0x15d474, Func Offset: 0x174
	// Line 4009, Address: 0x15d478, Func Offset: 0x178
	// Line 4012, Address: 0x15d480, Func Offset: 0x180
	// Line 4013, Address: 0x15d488, Func Offset: 0x188
	// Line 4014, Address: 0x15d4e4, Func Offset: 0x1e4
	// Line 4015, Address: 0x15d4ec, Func Offset: 0x1ec
	// Line 4017, Address: 0x15d53c, Func Offset: 0x23c
	// Line 4020, Address: 0x15d544, Func Offset: 0x244
	// Line 4017, Address: 0x15d548, Func Offset: 0x248
	// Line 4020, Address: 0x15d550, Func Offset: 0x250
	// Line 4021, Address: 0x15d558, Func Offset: 0x258
	// Line 4022, Address: 0x15d5b4, Func Offset: 0x2b4
	// Line 4023, Address: 0x15d5bc, Func Offset: 0x2bc
	// Line 4025, Address: 0x15d60c, Func Offset: 0x30c
	// Line 4027, Address: 0x15d620, Func Offset: 0x320
	// Line 4028, Address: 0x15d62c, Func Offset: 0x32c
	// Line 4029, Address: 0x15d638, Func Offset: 0x338
	// Line 4030, Address: 0x15d644, Func Offset: 0x344
	// Line 4034, Address: 0x15d650, Func Offset: 0x350
	// Line 4031, Address: 0x15d654, Func Offset: 0x354
	// Line 4032, Address: 0x15d660, Func Offset: 0x360
	// Line 4034, Address: 0x15d668, Func Offset: 0x368
	// Line 4035, Address: 0x15d670, Func Offset: 0x370
	// Line 4039, Address: 0x15d674, Func Offset: 0x374
	// Line 4043, Address: 0x15d6b4, Func Offset: 0x3b4
	// Line 4042, Address: 0x15d6c0, Func Offset: 0x3c0
	// Line 4043, Address: 0x15d6c4, Func Offset: 0x3c4
	// Func End, Address: 0x15d6cc, Func Offset: 0x3cc
}

// 
// Start address: 0x15d6d0
unsigned int bhEffBloodPoolSet()
{
	int ang;
	_anon39 gpos;
	BH_PWORK* epw;
	int v2;
	int v1;
	int v0;
	// Line 4051, Address: 0x15d6d0, Func Offset: 0
	// Line 4058, Address: 0x15d6e8, Func Offset: 0x18
	// Line 4071, Address: 0x15d6f0, Func Offset: 0x20
	// Line 4074, Address: 0x15d6f8, Func Offset: 0x28
	// Line 4071, Address: 0x15d6fc, Func Offset: 0x2c
	// Line 4058, Address: 0x15d704, Func Offset: 0x34
	// Line 4059, Address: 0x15d710, Func Offset: 0x40
	// Line 4060, Address: 0x15d71c, Func Offset: 0x4c
	// Line 4061, Address: 0x15d728, Func Offset: 0x58
	// Line 4071, Address: 0x15d730, Func Offset: 0x60
	// Line 4061, Address: 0x15d73c, Func Offset: 0x6c
	// Line 4062, Address: 0x15d740, Func Offset: 0x70
	// Line 4063, Address: 0x15d74c, Func Offset: 0x7c
	// Line 4064, Address: 0x15d758, Func Offset: 0x88
	// Line 4071, Address: 0x15d764, Func Offset: 0x94
	// Line 4074, Address: 0x15d788, Func Offset: 0xb8
	// Line 4076, Address: 0x15d7ac, Func Offset: 0xdc
	// Line 4077, Address: 0x15d7b8, Func Offset: 0xe8
	// Line 4076, Address: 0x15d7bc, Func Offset: 0xec
	// Line 4077, Address: 0x15d7c0, Func Offset: 0xf0
	// Line 4076, Address: 0x15d7c4, Func Offset: 0xf4
	// Line 4077, Address: 0x15d7d4, Func Offset: 0x104
	// Line 4078, Address: 0x15d7e4, Func Offset: 0x114
	// Line 4079, Address: 0x15d7f4, Func Offset: 0x124
	// Line 4083, Address: 0x15d80c, Func Offset: 0x13c
	// Line 4085, Address: 0x15d82c, Func Offset: 0x15c
	// Line 4087, Address: 0x15d834, Func Offset: 0x164
	// Line 4088, Address: 0x15d840, Func Offset: 0x170
	// Line 4087, Address: 0x15d844, Func Offset: 0x174
	// Line 4088, Address: 0x15d848, Func Offset: 0x178
	// Line 4087, Address: 0x15d84c, Func Offset: 0x17c
	// Line 4088, Address: 0x15d850, Func Offset: 0x180
	// Line 4089, Address: 0x15d860, Func Offset: 0x190
	// Line 4090, Address: 0x15d870, Func Offset: 0x1a0
	// Line 4094, Address: 0x15d888, Func Offset: 0x1b8
	// Line 4095, Address: 0x15d8a8, Func Offset: 0x1d8
	// Line 4097, Address: 0x15d8b0, Func Offset: 0x1e0
	// Line 4098, Address: 0x15d8bc, Func Offset: 0x1ec
	// Line 4097, Address: 0x15d8c0, Func Offset: 0x1f0
	// Line 4098, Address: 0x15d8c4, Func Offset: 0x1f4
	// Line 4097, Address: 0x15d8c8, Func Offset: 0x1f8
	// Line 4098, Address: 0x15d8cc, Func Offset: 0x1fc
	// Line 4099, Address: 0x15d8dc, Func Offset: 0x20c
	// Line 4100, Address: 0x15d8ec, Func Offset: 0x21c
	// Line 4101, Address: 0x15d904, Func Offset: 0x234
	// Line 4106, Address: 0x15d924, Func Offset: 0x254
	// Line 4105, Address: 0x15d938, Func Offset: 0x268
	// Line 4106, Address: 0x15d93c, Func Offset: 0x26c
	// Func End, Address: 0x15d944, Func Offset: 0x274
}

// 
// Start address: 0x15d950
unsigned int bhEffBloodPoolSet2()
{
	int ang;
	_anon39 gpos;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 4115, Address: 0x15d950, Func Offset: 0
	// Line 4122, Address: 0x15d964, Func Offset: 0x14
	// Line 4123, Address: 0x15d978, Func Offset: 0x28
	// Line 4124, Address: 0x15d984, Func Offset: 0x34
	// Line 4127, Address: 0x15d990, Func Offset: 0x40
	// Line 4128, Address: 0x15d99c, Func Offset: 0x4c
	// Line 4129, Address: 0x15d9f8, Func Offset: 0xa8
	// Line 4130, Address: 0x15da00, Func Offset: 0xb0
	// Line 4132, Address: 0x15da50, Func Offset: 0x100
	// Line 4135, Address: 0x15da58, Func Offset: 0x108
	// Line 4132, Address: 0x15da5c, Func Offset: 0x10c
	// Line 4135, Address: 0x15da64, Func Offset: 0x114
	// Line 4136, Address: 0x15da6c, Func Offset: 0x11c
	// Line 4137, Address: 0x15dac8, Func Offset: 0x178
	// Line 4138, Address: 0x15dad0, Func Offset: 0x180
	// Line 4140, Address: 0x15db20, Func Offset: 0x1d0
	// Line 4143, Address: 0x15db28, Func Offset: 0x1d8
	// Line 4140, Address: 0x15db2c, Func Offset: 0x1dc
	// Line 4143, Address: 0x15db34, Func Offset: 0x1e4
	// Line 4144, Address: 0x15db3c, Func Offset: 0x1ec
	// Line 4145, Address: 0x15db98, Func Offset: 0x248
	// Line 4146, Address: 0x15dba0, Func Offset: 0x250
	// Line 4148, Address: 0x15dbf0, Func Offset: 0x2a0
	// Line 4151, Address: 0x15dc04, Func Offset: 0x2b4
	// Line 4152, Address: 0x15dc18, Func Offset: 0x2c8
	// Line 4153, Address: 0x15dc24, Func Offset: 0x2d4
	// Line 4154, Address: 0x15dc30, Func Offset: 0x2e0
	// Line 4159, Address: 0x15dc38, Func Offset: 0x2e8
	// Line 4154, Address: 0x15dc3c, Func Offset: 0x2ec
	// Line 4155, Address: 0x15dc40, Func Offset: 0x2f0
	// Line 4156, Address: 0x15dc4c, Func Offset: 0x2fc
	// Line 4157, Address: 0x15dc58, Func Offset: 0x308
	// Line 4159, Address: 0x15dc60, Func Offset: 0x310
	// Line 4160, Address: 0x15dc68, Func Offset: 0x318
	// Line 4163, Address: 0x15dc6c, Func Offset: 0x31c
	// Line 4165, Address: 0x15dc94, Func Offset: 0x344
	// Line 4167, Address: 0x15dcd0, Func Offset: 0x380
	// Line 4168, Address: 0x15dcdc, Func Offset: 0x38c
	// Line 4167, Address: 0x15dce4, Func Offset: 0x394
	// Line 4168, Address: 0x15dce8, Func Offset: 0x398
	// Line 4170, Address: 0x15dcf4, Func Offset: 0x3a4
	// Line 4168, Address: 0x15dd00, Func Offset: 0x3b0
	// Line 4170, Address: 0x15dd04, Func Offset: 0x3b4
	// Line 4172, Address: 0x15dd18, Func Offset: 0x3c8
	// Line 4174, Address: 0x15dd20, Func Offset: 0x3d0
	// Line 4175, Address: 0x15dd50, Func Offset: 0x400
	// Line 4176, Address: 0x15dd5c, Func Offset: 0x40c
	// Line 4175, Address: 0x15dd64, Func Offset: 0x414
	// Line 4176, Address: 0x15dd68, Func Offset: 0x418
	// Line 4177, Address: 0x15dd74, Func Offset: 0x424
	// Line 4176, Address: 0x15dd80, Func Offset: 0x430
	// Line 4177, Address: 0x15dd84, Func Offset: 0x434
	// Line 4178, Address: 0x15dd98, Func Offset: 0x448
	// Line 4180, Address: 0x15dda0, Func Offset: 0x450
	// Line 4181, Address: 0x15ddd0, Func Offset: 0x480
	// Line 4182, Address: 0x15dddc, Func Offset: 0x48c
	// Line 4181, Address: 0x15dde4, Func Offset: 0x494
	// Line 4182, Address: 0x15dde8, Func Offset: 0x498
	// Line 4183, Address: 0x15ddf4, Func Offset: 0x4a4
	// Line 4182, Address: 0x15de00, Func Offset: 0x4b0
	// Line 4183, Address: 0x15de04, Func Offset: 0x4b4
	// Line 4187, Address: 0x15de18, Func Offset: 0x4c8
	// Line 4186, Address: 0x15de28, Func Offset: 0x4d8
	// Line 4187, Address: 0x15de2c, Func Offset: 0x4dc
	// Func End, Address: 0x15de34, Func Offset: 0x4e4
}

// 
// Start address: 0x15de40
unsigned int bhCyoutenHenkeiSet()
{
	BH_PWORK* epw;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 4202, Address: 0x15de40, Func Offset: 0
	// Line 4212, Address: 0x15de48, Func Offset: 0x8
	// Line 4202, Address: 0x15de4c, Func Offset: 0xc
	// Line 4203, Address: 0x15de58, Func Offset: 0x18
	// Line 4204, Address: 0x15de64, Func Offset: 0x24
	// Line 4205, Address: 0x15de70, Func Offset: 0x30
	// Line 4206, Address: 0x15de7c, Func Offset: 0x3c
	// Line 4207, Address: 0x15de88, Func Offset: 0x48
	// Line 4208, Address: 0x15de94, Func Offset: 0x54
	// Line 4209, Address: 0x15dea0, Func Offset: 0x60
	// Line 4210, Address: 0x15deac, Func Offset: 0x6c
	// Line 4212, Address: 0x15deb4, Func Offset: 0x74
	// Line 4214, Address: 0x15decc, Func Offset: 0x8c
	// Line 4215, Address: 0x15ded0, Func Offset: 0x90
	// Line 4221, Address: 0x15ded8, Func Offset: 0x98
	// Line 4226, Address: 0x15df18, Func Offset: 0xd8
	// Line 4229, Address: 0x15df28, Func Offset: 0xe8
	// Line 4239, Address: 0x15df30, Func Offset: 0xf0
	// Line 4226, Address: 0x15df34, Func Offset: 0xf4
	// Line 4228, Address: 0x15df38, Func Offset: 0xf8
	// Line 4229, Address: 0x15df40, Func Offset: 0x100
	// Line 4240, Address: 0x15df44, Func Offset: 0x104
	// Func End, Address: 0x15df4c, Func Offset: 0x10c
}

// 
// Start address: 0x15df50
unsigned int bhCyoutenHenkeiStart()
{
	// Line 4251, Address: 0x15df50, Func Offset: 0
	// Line 4258, Address: 0x15df58, Func Offset: 0x8
	// Line 4251, Address: 0x15df60, Func Offset: 0x10
	// Line 4253, Address: 0x15df6c, Func Offset: 0x1c
	// Line 4258, Address: 0x15df80, Func Offset: 0x30
	// Line 4259, Address: 0x15df8c, Func Offset: 0x3c
	// Line 4260, Address: 0x15df90, Func Offset: 0x40
	// Line 4259, Address: 0x15df9c, Func Offset: 0x4c
	// Line 4260, Address: 0x15dfa4, Func Offset: 0x54
	// Line 4263, Address: 0x15dfcc, Func Offset: 0x7c
	// Line 4264, Address: 0x15dfd0, Func Offset: 0x80
	// Func End, Address: 0x15dfd8, Func Offset: 0x88
}

// 
// Start address: 0x15dfe0
unsigned int bhFixEventCamPly()
{
	int v0;
	// Line 4275, Address: 0x15dfe0, Func Offset: 0
	// Line 4276, Address: 0x15dff4, Func Offset: 0x14
	// Line 4277, Address: 0x15e000, Func Offset: 0x20
	// Line 4279, Address: 0x15e008, Func Offset: 0x28
	// Line 4280, Address: 0x15e010, Func Offset: 0x30
	// Line 4281, Address: 0x15e024, Func Offset: 0x44
	// Line 4282, Address: 0x15e02c, Func Offset: 0x4c
	// Line 4285, Address: 0x15e048, Func Offset: 0x68
	// Func End, Address: 0x15e050, Func Offset: 0x70
}

// 
// Start address: 0x15e050
unsigned int bhObjLinkSetObjObj()
{
	int v4;
	int v1;
	int v0;
	// Line 4300, Address: 0x15e050, Func Offset: 0
	// Line 4311, Address: 0x15e058, Func Offset: 0x8
	// Line 4300, Address: 0x15e060, Func Offset: 0x10
	// Line 4301, Address: 0x15e06c, Func Offset: 0x1c
	// Line 4302, Address: 0x15e078, Func Offset: 0x28
	// Line 4303, Address: 0x15e084, Func Offset: 0x34
	// Line 4311, Address: 0x15e08c, Func Offset: 0x3c
	// Line 4303, Address: 0x15e09c, Func Offset: 0x4c
	// Line 4311, Address: 0x15e0a0, Func Offset: 0x50
	// Line 4304, Address: 0x15e0a4, Func Offset: 0x54
	// Line 4311, Address: 0x15e0b0, Func Offset: 0x60
	// Line 4314, Address: 0x15e0dc, Func Offset: 0x8c
	// Line 4316, Address: 0x15e104, Func Offset: 0xb4
	// Line 4318, Address: 0x15e118, Func Offset: 0xc8
	// Line 4319, Address: 0x15e12c, Func Offset: 0xdc
	// Line 4320, Address: 0x15e14c, Func Offset: 0xfc
	// Line 4321, Address: 0x15e154, Func Offset: 0x104
	// Line 4323, Address: 0x15e17c, Func Offset: 0x12c
	// Line 4324, Address: 0x15e190, Func Offset: 0x140
	// Line 4326, Address: 0x15e19c, Func Offset: 0x14c
	// Line 4329, Address: 0x15e1a8, Func Offset: 0x158
	// Line 4330, Address: 0x15e1b4, Func Offset: 0x164
	// Line 4331, Address: 0x15e224, Func Offset: 0x1d4
	// Line 4332, Address: 0x15e22c, Func Offset: 0x1dc
	// Line 4334, Address: 0x15e290, Func Offset: 0x240
	// Line 4337, Address: 0x15e298, Func Offset: 0x248
	// Line 4334, Address: 0x15e29c, Func Offset: 0x24c
	// Line 4337, Address: 0x15e2a4, Func Offset: 0x254
	// Line 4338, Address: 0x15e2ac, Func Offset: 0x25c
	// Line 4339, Address: 0x15e31c, Func Offset: 0x2cc
	// Line 4340, Address: 0x15e324, Func Offset: 0x2d4
	// Line 4342, Address: 0x15e388, Func Offset: 0x338
	// Line 4345, Address: 0x15e390, Func Offset: 0x340
	// Line 4342, Address: 0x15e394, Func Offset: 0x344
	// Line 4345, Address: 0x15e39c, Func Offset: 0x34c
	// Line 4346, Address: 0x15e3a4, Func Offset: 0x354
	// Line 4347, Address: 0x15e414, Func Offset: 0x3c4
	// Line 4348, Address: 0x15e41c, Func Offset: 0x3cc
	// Line 4350, Address: 0x15e480, Func Offset: 0x430
	// Line 4352, Address: 0x15e488, Func Offset: 0x438
	// Line 4350, Address: 0x15e48c, Func Offset: 0x43c
	// Line 4353, Address: 0x15e494, Func Offset: 0x444
	// Func End, Address: 0x15e49c, Func Offset: 0x44c
}

// 
// Start address: 0x15e4a0
unsigned int bhCamYureSet()
{
	int v1;
	int v0;
	// Line 4361, Address: 0x15e4a0, Func Offset: 0
	// Line 4364, Address: 0x15e4b0, Func Offset: 0x10
	// Line 4365, Address: 0x15e4c4, Func Offset: 0x24
	// Line 4366, Address: 0x15e4d0, Func Offset: 0x30
	// Line 4367, Address: 0x15e4dc, Func Offset: 0x3c
	// Line 4368, Address: 0x15e4e8, Func Offset: 0x48
	// Line 4370, Address: 0x15e4f0, Func Offset: 0x50
	// Line 4372, Address: 0x15e4f8, Func Offset: 0x58
	// Line 4373, Address: 0x15e53c, Func Offset: 0x9c
	// Line 4374, Address: 0x15e568, Func Offset: 0xc8
	// Line 4375, Address: 0x15e594, Func Offset: 0xf4
	// Line 4376, Address: 0x15e59c, Func Offset: 0xfc
	// Line 4377, Address: 0x15e5a4, Func Offset: 0x104
	// Line 4378, Address: 0x15e5ac, Func Offset: 0x10c
	// Line 4381, Address: 0x15e5b4, Func Offset: 0x114
	// Line 4380, Address: 0x15e5c0, Func Offset: 0x120
	// Line 4381, Address: 0x15e5c4, Func Offset: 0x124
	// Func End, Address: 0x15e5cc, Func Offset: 0x12c
}

// 
// Start address: 0x15e5d0
unsigned int bhInitCamSet()
{
	// Line 4389, Address: 0x15e5d0, Func Offset: 0
	// Line 4390, Address: 0x15e5d8, Func Offset: 0x8
	// Line 4396, Address: 0x15e5e0, Func Offset: 0x10
	// Line 4398, Address: 0x15e5e4, Func Offset: 0x14
	// Line 4392, Address: 0x15e5e8, Func Offset: 0x18
	// Line 4390, Address: 0x15e5f0, Func Offset: 0x20
	// Line 4392, Address: 0x15e5fc, Func Offset: 0x2c
	// Line 4393, Address: 0x15e600, Func Offset: 0x30
	// Line 4392, Address: 0x15e604, Func Offset: 0x34
	// Line 4393, Address: 0x15e608, Func Offset: 0x38
	// Line 4394, Address: 0x15e610, Func Offset: 0x40
	// Line 4393, Address: 0x15e614, Func Offset: 0x44
	// Line 4394, Address: 0x15e618, Func Offset: 0x48
	// Line 4396, Address: 0x15e620, Func Offset: 0x50
	// Line 4394, Address: 0x15e624, Func Offset: 0x54
	// Line 4396, Address: 0x15e628, Func Offset: 0x58
	// Line 4398, Address: 0x15e634, Func Offset: 0x64
	// Line 4399, Address: 0x15e63c, Func Offset: 0x6c
	// Line 4400, Address: 0x15e644, Func Offset: 0x74
	// Line 4402, Address: 0x15e64c, Func Offset: 0x7c
	// Line 4401, Address: 0x15e650, Func Offset: 0x80
	// Line 4402, Address: 0x15e654, Func Offset: 0x84
	// Func End, Address: 0x15e65c, Func Offset: 0x8c
}

// 
// Start address: 0x15e660
unsigned int bhMesDispEndSet()
{
	// Line 4411, Address: 0x15e660, Func Offset: 0
	// Line 4416, Address: 0x15e668, Func Offset: 0x8
	// Line 4417, Address: 0x15e66c, Func Offset: 0xc
	// Line 4412, Address: 0x15e670, Func Offset: 0x10
	// Line 4411, Address: 0x15e678, Func Offset: 0x18
	// Line 4412, Address: 0x15e684, Func Offset: 0x24
	// Line 4413, Address: 0x15e690, Func Offset: 0x30
	// Line 4414, Address: 0x15e6a4, Func Offset: 0x44
	// Line 4415, Address: 0x15e6b8, Func Offset: 0x58
	// Line 4416, Address: 0x15e6cc, Func Offset: 0x6c
	// Line 4418, Address: 0x15e6dc, Func Offset: 0x7c
	// Func End, Address: 0x15e6e4, Func Offset: 0x84
}

// 
// Start address: 0x15e6f0
unsigned int bhPadCheck()
{
	int v1;
	int v0;
	// Line 4434, Address: 0x15e6f0, Func Offset: 0
	// Line 4444, Address: 0x15e6f8, Func Offset: 0x8
	// Line 4434, Address: 0x15e700, Func Offset: 0x10
	// Line 4435, Address: 0x15e70c, Func Offset: 0x1c
	// Line 4436, Address: 0x15e718, Func Offset: 0x28
	// Line 4437, Address: 0x15e724, Func Offset: 0x34
	// Line 4438, Address: 0x15e730, Func Offset: 0x40
	// Line 4444, Address: 0x15e73c, Func Offset: 0x4c
	// Line 4446, Address: 0x15e74c, Func Offset: 0x5c
	// Line 4448, Address: 0x15e774, Func Offset: 0x84
	// Line 4450, Address: 0x15e7a0, Func Offset: 0xb0
	// Line 4454, Address: 0x15e7a8, Func Offset: 0xb8
	// Line 4456, Address: 0x15e7e0, Func Offset: 0xf0
	// Line 4460, Address: 0x15e7e8, Func Offset: 0xf8
	// Line 4462, Address: 0x15e814, Func Offset: 0x124
	// Line 4464, Address: 0x15e81c, Func Offset: 0x12c
	// Line 4466, Address: 0x15e840, Func Offset: 0x150
	// Line 4470, Address: 0x15e848, Func Offset: 0x158
	// Line 4472, Address: 0x15e868, Func Offset: 0x178
	// Line 4476, Address: 0x15e870, Func Offset: 0x180
	// Line 4478, Address: 0x15e89c, Func Offset: 0x1ac
	// Line 4482, Address: 0x15e8a4, Func Offset: 0x1b4
	// Line 4484, Address: 0x15e8c4, Func Offset: 0x1d4
	// Line 4486, Address: 0x15e8cc, Func Offset: 0x1dc
	// Line 4488, Address: 0x15e8ec, Func Offset: 0x1fc
	// Line 4492, Address: 0x15e8f4, Func Offset: 0x204
	// Line 4494, Address: 0x15e930, Func Offset: 0x240
	// Line 4499, Address: 0x15e938, Func Offset: 0x248
	// Line 4500, Address: 0x15e93c, Func Offset: 0x24c
	// Func End, Address: 0x15e944, Func Offset: 0x254
}

// 
// Start address: 0x15e950
unsigned int bhTFrameCheck()
{
	int v0;
	// Line 4511, Address: 0x15e950, Func Offset: 0
	// Line 4516, Address: 0x15e958, Func Offset: 0x8
	// Line 4511, Address: 0x15e960, Func Offset: 0x10
	// Line 4512, Address: 0x15e96c, Func Offset: 0x1c
	// Line 4513, Address: 0x15e978, Func Offset: 0x28
	// Line 4516, Address: 0x15e980, Func Offset: 0x30
	// Line 4519, Address: 0x15e998, Func Offset: 0x48
	// Func End, Address: 0x15e9a0, Func Offset: 0x50
}

// 
// Start address: 0x15e9a0
unsigned int bhEventTimerClr()
{
	// Line 4529, Address: 0x15e9a0, Func Offset: 0
	// Line 4528, Address: 0x15e9a8, Func Offset: 0x8
	// Line 4530, Address: 0x15e9b0, Func Offset: 0x10
	// Line 4528, Address: 0x15e9b4, Func Offset: 0x14
	// Line 4531, Address: 0x15e9bc, Func Offset: 0x1c
	// Func End, Address: 0x15e9c4, Func Offset: 0x24
}

// 
// Start address: 0x15e9d0
unsigned int bhCamCheck()
{
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 4542, Address: 0x15e9d0, Func Offset: 0
	// Line 4551, Address: 0x15e9d8, Func Offset: 0x8
	// Line 4542, Address: 0x15e9e0, Func Offset: 0x10
	// Line 4543, Address: 0x15e9ec, Func Offset: 0x1c
	// Line 4544, Address: 0x15e9f8, Func Offset: 0x28
	// Line 4545, Address: 0x15ea04, Func Offset: 0x34
	// Line 4546, Address: 0x15ea10, Func Offset: 0x40
	// Line 4547, Address: 0x15ea1c, Func Offset: 0x4c
	// Line 4548, Address: 0x15ea28, Func Offset: 0x58
	// Line 4549, Address: 0x15ea34, Func Offset: 0x64
	// Line 4551, Address: 0x15ea48, Func Offset: 0x78
	// Line 4552, Address: 0x15ea60, Func Offset: 0x90
	// Line 4553, Address: 0x15ea70, Func Offset: 0xa0
	// Line 4554, Address: 0x15ea84, Func Offset: 0xb4
	// Line 4555, Address: 0x15ea94, Func Offset: 0xc4
	// Line 4556, Address: 0x15ea9c, Func Offset: 0xcc
	// Line 4557, Address: 0x15eaac, Func Offset: 0xdc
	// Line 4560, Address: 0x15eab4, Func Offset: 0xe4
	// Line 4565, Address: 0x15eac0, Func Offset: 0xf0
	// Line 4566, Address: 0x15eac4, Func Offset: 0xf4
	// Func End, Address: 0x15eacc, Func Offset: 0xfc
}

// 
// Start address: 0x15ead0
unsigned int bhRandamSet()
{
	int v1;
	int v0;
	// Line 4574, Address: 0x15ead0, Func Offset: 0
	// Line 4578, Address: 0x15eadc, Func Offset: 0xc
	// Line 4579, Address: 0x15eaf0, Func Offset: 0x20
	// Line 4580, Address: 0x15eafc, Func Offset: 0x2c
	// Line 4582, Address: 0x15eb04, Func Offset: 0x34
	// Line 4583, Address: 0x15eb40, Func Offset: 0x70
	// Line 4584, Address: 0x15eb54, Func Offset: 0x84
	// Line 4583, Address: 0x15eb58, Func Offset: 0x88
	// Line 4585, Address: 0x15eb5c, Func Offset: 0x8c
	// Func End, Address: 0x15eb6c, Func Offset: 0x9c
}

// 
// Start address: 0x15eb70
unsigned int bhEventSkipSet()
{
	int v0;
	// Line 4596, Address: 0x15eb70, Func Offset: 0
	// Line 4597, Address: 0x15eb84, Func Offset: 0x14
	// Line 4598, Address: 0x15eb90, Func Offset: 0x20
	// Line 4600, Address: 0x15eb98, Func Offset: 0x28
	// Line 4601, Address: 0x15eba0, Func Offset: 0x30
	// Line 4602, Address: 0x15ebb4, Func Offset: 0x44
	// Line 4603, Address: 0x15ebbc, Func Offset: 0x4c
	// Line 4606, Address: 0x15ebd8, Func Offset: 0x68
	// Func End, Address: 0x15ebe0, Func Offset: 0x70
}

// 
// Start address: 0x15ebe0
unsigned int bhDelYakkyou()
{
	// Line 4614, Address: 0x15ebe0, Func Offset: 0
	// Line 4615, Address: 0x15ebe8, Func Offset: 0x8
	// Line 4616, Address: 0x15ebf8, Func Offset: 0x18
	// Line 4618, Address: 0x15ec00, Func Offset: 0x20
	// Line 4617, Address: 0x15ec04, Func Offset: 0x24
	// Line 4618, Address: 0x15ec08, Func Offset: 0x28
	// Func End, Address: 0x15ec10, Func Offset: 0x30
}

// 
// Start address: 0x15ec10
unsigned int bhObjAlphaSet()
{
	_anon0* op;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 4627, Address: 0x15ec10, Func Offset: 0
	// Line 4631, Address: 0x15ec18, Func Offset: 0x8
	// Line 4645, Address: 0x15ec20, Func Offset: 0x10
	// Line 4631, Address: 0x15ec24, Func Offset: 0x14
	// Line 4632, Address: 0x15ec30, Func Offset: 0x20
	// Line 4633, Address: 0x15ec3c, Func Offset: 0x2c
	// Line 4634, Address: 0x15ec48, Func Offset: 0x38
	// Line 4635, Address: 0x15ec54, Func Offset: 0x44
	// Line 4636, Address: 0x15ec60, Func Offset: 0x50
	// Line 4637, Address: 0x15ec6c, Func Offset: 0x5c
	// Line 4638, Address: 0x15ec78, Func Offset: 0x68
	// Line 4639, Address: 0x15ec84, Func Offset: 0x74
	// Line 4640, Address: 0x15ec90, Func Offset: 0x80
	// Line 4641, Address: 0x15ec9c, Func Offset: 0x8c
	// Line 4642, Address: 0x15eca8, Func Offset: 0x98
	// Line 4643, Address: 0x15ecb4, Func Offset: 0xa4
	// Line 4645, Address: 0x15ecbc, Func Offset: 0xac
	// Line 4650, Address: 0x15ecd8, Func Offset: 0xc8
	// Line 4651, Address: 0x15ed00, Func Offset: 0xf0
	// Line 4656, Address: 0x15ed08, Func Offset: 0xf8
	// Line 4659, Address: 0x15ed34, Func Offset: 0x124
	// Line 4661, Address: 0x15ed3c, Func Offset: 0x12c
	// Line 4660, Address: 0x15ed40, Func Offset: 0x130
	// Line 4661, Address: 0x15ed44, Func Offset: 0x134
	// Func End, Address: 0x15ed4c, Func Offset: 0x13c
}

// 
// Start address: 0x15ed50
unsigned int bhCyodanSet()
{
	int wp_hef;
	_anon39 wps;
	_anon39 ps;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 4671, Address: 0x15ed50, Func Offset: 0
	// Line 4678, Address: 0x15ed58, Func Offset: 0x8
	// Line 4679, Address: 0x15ed6c, Func Offset: 0x1c
	// Line 4680, Address: 0x15ed78, Func Offset: 0x28
	// Line 4681, Address: 0x15ed84, Func Offset: 0x34
	// Line 4682, Address: 0x15ed90, Func Offset: 0x40
	// Line 4683, Address: 0x15ed9c, Func Offset: 0x4c
	// Line 4684, Address: 0x15eda8, Func Offset: 0x58
	// Line 4685, Address: 0x15edb4, Func Offset: 0x64
	// Line 4686, Address: 0x15edc0, Func Offset: 0x70
	// Line 4687, Address: 0x15edcc, Func Offset: 0x7c
	// Line 4688, Address: 0x15edd8, Func Offset: 0x88
	// Line 4691, Address: 0x15ede4, Func Offset: 0x94
	// Line 4692, Address: 0x15edf0, Func Offset: 0xa0
	// Line 4693, Address: 0x15ee4c, Func Offset: 0xfc
	// Line 4694, Address: 0x15ee54, Func Offset: 0x104
	// Line 4696, Address: 0x15eea4, Func Offset: 0x154
	// Line 4699, Address: 0x15eeac, Func Offset: 0x15c
	// Line 4696, Address: 0x15eeb0, Func Offset: 0x160
	// Line 4699, Address: 0x15eeb8, Func Offset: 0x168
	// Line 4700, Address: 0x15eec0, Func Offset: 0x170
	// Line 4701, Address: 0x15ef1c, Func Offset: 0x1cc
	// Line 4702, Address: 0x15ef24, Func Offset: 0x1d4
	// Line 4704, Address: 0x15ef74, Func Offset: 0x224
	// Line 4707, Address: 0x15ef7c, Func Offset: 0x22c
	// Line 4704, Address: 0x15ef80, Func Offset: 0x230
	// Line 4707, Address: 0x15ef88, Func Offset: 0x238
	// Line 4708, Address: 0x15ef90, Func Offset: 0x240
	// Line 4709, Address: 0x15efec, Func Offset: 0x29c
	// Line 4710, Address: 0x15eff4, Func Offset: 0x2a4
	// Line 4712, Address: 0x15f044, Func Offset: 0x2f4
	// Line 4717, Address: 0x15f04c, Func Offset: 0x2fc
	// Line 4712, Address: 0x15f054, Func Offset: 0x304
	// Line 4714, Address: 0x15f060, Func Offset: 0x310
	// Line 4715, Address: 0x15f06c, Func Offset: 0x31c
	// Line 4717, Address: 0x15f078, Func Offset: 0x328
	// Line 4719, Address: 0x15f084, Func Offset: 0x334
	// Line 4717, Address: 0x15f088, Func Offset: 0x338
	// Line 4719, Address: 0x15f08c, Func Offset: 0x33c
	// Line 4717, Address: 0x15f090, Func Offset: 0x340
	// Line 4719, Address: 0x15f09c, Func Offset: 0x34c
	// Line 4720, Address: 0x15f0a0, Func Offset: 0x350
	// Line 4723, Address: 0x15f0a8, Func Offset: 0x358
	// Line 4724, Address: 0x15f0b4, Func Offset: 0x364
	// Line 4725, Address: 0x15f110, Func Offset: 0x3c0
	// Line 4726, Address: 0x15f118, Func Offset: 0x3c8
	// Line 4728, Address: 0x15f168, Func Offset: 0x418
	// Line 4731, Address: 0x15f170, Func Offset: 0x420
	// Line 4728, Address: 0x15f174, Func Offset: 0x424
	// Line 4731, Address: 0x15f17c, Func Offset: 0x42c
	// Line 4732, Address: 0x15f184, Func Offset: 0x434
	// Line 4733, Address: 0x15f1e0, Func Offset: 0x490
	// Line 4734, Address: 0x15f1e8, Func Offset: 0x498
	// Line 4736, Address: 0x15f238, Func Offset: 0x4e8
	// Line 4739, Address: 0x15f240, Func Offset: 0x4f0
	// Line 4736, Address: 0x15f244, Func Offset: 0x4f4
	// Line 4739, Address: 0x15f24c, Func Offset: 0x4fc
	// Line 4740, Address: 0x15f254, Func Offset: 0x504
	// Line 4741, Address: 0x15f2b0, Func Offset: 0x560
	// Line 4742, Address: 0x15f2b8, Func Offset: 0x568
	// Line 4746, Address: 0x15f308, Func Offset: 0x5b8
	// Line 4744, Address: 0x15f320, Func Offset: 0x5d0
	// Line 4746, Address: 0x15f328, Func Offset: 0x5d8
	// Line 4744, Address: 0x15f334, Func Offset: 0x5e4
	// Line 4746, Address: 0x15f33c, Func Offset: 0x5ec
	// Line 4748, Address: 0x15f348, Func Offset: 0x5f8
	// Line 4747, Address: 0x15f34c, Func Offset: 0x5fc
	// Line 4748, Address: 0x15f350, Func Offset: 0x600
	// Func End, Address: 0x15f358, Func Offset: 0x608
}

// 
// Start address: 0x15f360
unsigned int bhHEffectSet()
{
	_anon53 pnt;
	int ay;
	int ax;
	int v3;
	int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 4759, Address: 0x15f360, Func Offset: 0
	// Line 4765, Address: 0x15f374, Func Offset: 0x14
	// Line 4766, Address: 0x15f388, Func Offset: 0x28
	// Line 4767, Address: 0x15f394, Func Offset: 0x34
	// Line 4768, Address: 0x15f3a0, Func Offset: 0x40
	// Line 4769, Address: 0x15f3ac, Func Offset: 0x4c
	// Line 4772, Address: 0x15f3b8, Func Offset: 0x58
	// Line 4773, Address: 0x15f3c4, Func Offset: 0x64
	// Line 4774, Address: 0x15f420, Func Offset: 0xc0
	// Line 4775, Address: 0x15f428, Func Offset: 0xc8
	// Line 4777, Address: 0x15f478, Func Offset: 0x118
	// Line 4780, Address: 0x15f480, Func Offset: 0x120
	// Line 4777, Address: 0x15f484, Func Offset: 0x124
	// Line 4780, Address: 0x15f48c, Func Offset: 0x12c
	// Line 4781, Address: 0x15f494, Func Offset: 0x134
	// Line 4782, Address: 0x15f4f0, Func Offset: 0x190
	// Line 4783, Address: 0x15f4f8, Func Offset: 0x198
	// Line 4785, Address: 0x15f548, Func Offset: 0x1e8
	// Line 4788, Address: 0x15f550, Func Offset: 0x1f0
	// Line 4785, Address: 0x15f554, Func Offset: 0x1f4
	// Line 4788, Address: 0x15f55c, Func Offset: 0x1fc
	// Line 4789, Address: 0x15f564, Func Offset: 0x204
	// Line 4790, Address: 0x15f5c0, Func Offset: 0x260
	// Line 4791, Address: 0x15f5c8, Func Offset: 0x268
	// Line 4793, Address: 0x15f618, Func Offset: 0x2b8
	// Line 4795, Address: 0x15f62c, Func Offset: 0x2cc
	// Line 4796, Address: 0x15f638, Func Offset: 0x2d8
	// Line 4797, Address: 0x15f644, Func Offset: 0x2e4
	// Line 4799, Address: 0x15f64c, Func Offset: 0x2ec
	// Line 4800, Address: 0x15f658, Func Offset: 0x2f8
	// Line 4802, Address: 0x15f65c, Func Offset: 0x2fc
	// Line 4804, Address: 0x15f678, Func Offset: 0x318
	// Line 4802, Address: 0x15f680, Func Offset: 0x320
	// Line 4806, Address: 0x15f684, Func Offset: 0x324
	// Line 4804, Address: 0x15f688, Func Offset: 0x328
	// Line 4805, Address: 0x15f694, Func Offset: 0x334
	// Line 4806, Address: 0x15f69c, Func Offset: 0x33c
	// Line 4807, Address: 0x15f6a4, Func Offset: 0x344
	// Line 4809, Address: 0x15f6a8, Func Offset: 0x348
	// Line 4812, Address: 0x15f6c4, Func Offset: 0x364
	// Line 4813, Address: 0x15f6d8, Func Offset: 0x378
	// Line 4814, Address: 0x15f6e4, Func Offset: 0x384
	// Line 4817, Address: 0x15f6f0, Func Offset: 0x390
	// Line 4818, Address: 0x15f6fc, Func Offset: 0x39c
	// Line 4819, Address: 0x15f758, Func Offset: 0x3f8
	// Line 4820, Address: 0x15f760, Func Offset: 0x400
	// Line 4822, Address: 0x15f7b0, Func Offset: 0x450
	// Line 4825, Address: 0x15f7b8, Func Offset: 0x458
	// Line 4822, Address: 0x15f7bc, Func Offset: 0x45c
	// Line 4825, Address: 0x15f7c4, Func Offset: 0x464
	// Line 4826, Address: 0x15f7cc, Func Offset: 0x46c
	// Line 4827, Address: 0x15f828, Func Offset: 0x4c8
	// Line 4828, Address: 0x15f830, Func Offset: 0x4d0
	// Line 4830, Address: 0x15f880, Func Offset: 0x520
	// Line 4833, Address: 0x15f888, Func Offset: 0x528
	// Line 4830, Address: 0x15f88c, Func Offset: 0x52c
	// Line 4833, Address: 0x15f894, Func Offset: 0x534
	// Line 4834, Address: 0x15f89c, Func Offset: 0x53c
	// Line 4835, Address: 0x15f8f8, Func Offset: 0x598
	// Line 4836, Address: 0x15f900, Func Offset: 0x5a0
	// Line 4843, Address: 0x15f950, Func Offset: 0x5f0
	// Line 4838, Address: 0x15f954, Func Offset: 0x5f4
	// Line 4843, Address: 0x15f95c, Func Offset: 0x5fc
	// Line 4838, Address: 0x15f968, Func Offset: 0x608
	// Line 4839, Address: 0x15f974, Func Offset: 0x614
	// Line 4840, Address: 0x15f980, Func Offset: 0x620
	// Line 4843, Address: 0x15f988, Func Offset: 0x628
	// Line 4845, Address: 0x15f990, Func Offset: 0x630
	// Line 4844, Address: 0x15f9a0, Func Offset: 0x640
	// Line 4845, Address: 0x15f9a4, Func Offset: 0x644
	// Func End, Address: 0x15f9ac, Func Offset: 0x64c
}

// 
// Start address: 0x15f9b0
unsigned int bhObjLinkSetObjPly()
{
	int v1;
	// Line 4857, Address: 0x15f9b0, Func Offset: 0
	// Line 4861, Address: 0x15f9b8, Func Offset: 0x8
	// Line 4857, Address: 0x15f9c0, Func Offset: 0x10
	// Line 4861, Address: 0x15f9c4, Func Offset: 0x14
	// Line 4857, Address: 0x15f9cc, Func Offset: 0x1c
	// Line 4861, Address: 0x15f9d4, Func Offset: 0x24
	// Line 4867, Address: 0x15f9ec, Func Offset: 0x3c
	// Line 4861, Address: 0x15f9f0, Func Offset: 0x40
	// Line 4867, Address: 0x15fa0c, Func Offset: 0x5c
	// Line 4869, Address: 0x15fa10, Func Offset: 0x60
	// Line 4867, Address: 0x15fa18, Func Offset: 0x68
	// Line 4868, Address: 0x15fa24, Func Offset: 0x74
	// Line 4871, Address: 0x15fa30, Func Offset: 0x80
	// Line 4869, Address: 0x15fa34, Func Offset: 0x84
	// Line 4871, Address: 0x15fa38, Func Offset: 0x88
	// Line 4873, Address: 0x15fa48, Func Offset: 0x98
	// Line 4874, Address: 0x15fa5c, Func Offset: 0xac
	// Line 4875, Address: 0x15fa6c, Func Offset: 0xbc
	// Line 4876, Address: 0x15fa74, Func Offset: 0xc4
	// Line 4878, Address: 0x15fa8c, Func Offset: 0xdc
	// Line 4879, Address: 0x15faa0, Func Offset: 0xf0
	// Line 4881, Address: 0x15faac, Func Offset: 0xfc
	// Line 4884, Address: 0x15fab8, Func Offset: 0x108
	// Line 4885, Address: 0x15fac4, Func Offset: 0x114
	// Line 4886, Address: 0x15fb24, Func Offset: 0x174
	// Line 4887, Address: 0x15fb2c, Func Offset: 0x17c
	// Line 4889, Address: 0x15fb80, Func Offset: 0x1d0
	// Line 4892, Address: 0x15fb88, Func Offset: 0x1d8
	// Line 4889, Address: 0x15fb8c, Func Offset: 0x1dc
	// Line 4892, Address: 0x15fb94, Func Offset: 0x1e4
	// Line 4893, Address: 0x15fb9c, Func Offset: 0x1ec
	// Line 4894, Address: 0x15fbfc, Func Offset: 0x24c
	// Line 4895, Address: 0x15fc04, Func Offset: 0x254
	// Line 4897, Address: 0x15fc58, Func Offset: 0x2a8
	// Line 4900, Address: 0x15fc60, Func Offset: 0x2b0
	// Line 4897, Address: 0x15fc64, Func Offset: 0x2b4
	// Line 4900, Address: 0x15fc6c, Func Offset: 0x2bc
	// Line 4901, Address: 0x15fc74, Func Offset: 0x2c4
	// Line 4902, Address: 0x15fcd4, Func Offset: 0x324
	// Line 4903, Address: 0x15fcdc, Func Offset: 0x32c
	// Line 4905, Address: 0x15fd30, Func Offset: 0x380
	// Line 4907, Address: 0x15fd38, Func Offset: 0x388
	// Line 4905, Address: 0x15fd3c, Func Offset: 0x38c
	// Line 4908, Address: 0x15fd44, Func Offset: 0x394
	// Func End, Address: 0x15fd4c, Func Offset: 0x39c
}

// 
// Start address: 0x15fd50
unsigned int bhEffPush()
{
	// Line 4916, Address: 0x15fd50, Func Offset: 0
	// Line 4917, Address: 0x15fd58, Func Offset: 0x8
	// Line 4918, Address: 0x15fd68, Func Offset: 0x18
	// Line 4920, Address: 0x15fd70, Func Offset: 0x20
	// Line 4919, Address: 0x15fd74, Func Offset: 0x24
	// Line 4920, Address: 0x15fd78, Func Offset: 0x28
	// Func End, Address: 0x15fd80, Func Offset: 0x30
}

// 
// Start address: 0x15fd80
unsigned int bhEffPop()
{
	// Line 4928, Address: 0x15fd80, Func Offset: 0
	// Line 4929, Address: 0x15fd88, Func Offset: 0x8
	// Line 4930, Address: 0x15fd98, Func Offset: 0x18
	// Line 4932, Address: 0x15fda0, Func Offset: 0x20
	// Line 4931, Address: 0x15fda4, Func Offset: 0x24
	// Line 4932, Address: 0x15fda8, Func Offset: 0x28
	// Func End, Address: 0x15fdb0, Func Offset: 0x30
}

// 
// Start address: 0x15fdb0
unsigned int bhAreaSearchObj()
{
	float w_pz2;
	float w_px2;
	float w_pz1;
	float w_px1;
	BH_PWORK* e_workp;
	int v2;
	int v0;
	// Line 4948, Address: 0x15fdb0, Func Offset: 0
	// Line 4953, Address: 0x15fdb8, Func Offset: 0x8
	// Line 4948, Address: 0x15fdbc, Func Offset: 0xc
	// Line 4949, Address: 0x15fdc8, Func Offset: 0x18
	// Line 4950, Address: 0x15fdd4, Func Offset: 0x24
	// Line 4953, Address: 0x15fde0, Func Offset: 0x30
	// Line 4955, Address: 0x15fe1c, Func Offset: 0x6c
	// Line 4956, Address: 0x15fe20, Func Offset: 0x70
	// Line 4962, Address: 0x15fe28, Func Offset: 0x78
	// Line 4963, Address: 0x15fe64, Func Offset: 0xb4
	// Line 4968, Address: 0x15fe6c, Func Offset: 0xbc
	// Line 4969, Address: 0x15fe94, Func Offset: 0xe4
	// Line 4974, Address: 0x15fe9c, Func Offset: 0xec
	// Line 4978, Address: 0x15fec8, Func Offset: 0x118
	// Line 4979, Address: 0x15fedc, Func Offset: 0x12c
	// Line 4980, Address: 0x15fee8, Func Offset: 0x138
	// Line 4984, Address: 0x15fef4, Func Offset: 0x144
	// Line 4985, Address: 0x15ffac, Func Offset: 0x1fc
	// Line 4988, Address: 0x15ffb4, Func Offset: 0x204
	// Line 4985, Address: 0x15ffb8, Func Offset: 0x208
	// Line 4988, Address: 0x15ffc0, Func Offset: 0x210
	// Line 4989, Address: 0x160074, Func Offset: 0x2c4
	// Line 4991, Address: 0x160088, Func Offset: 0x2d8
	// Line 4992, Address: 0x16009c, Func Offset: 0x2ec
	// Line 4993, Address: 0x1600a8, Func Offset: 0x2f8
	// Line 4997, Address: 0x1600b4, Func Offset: 0x304
	// Line 4998, Address: 0x16016c, Func Offset: 0x3bc
	// Line 5001, Address: 0x160174, Func Offset: 0x3c4
	// Line 4998, Address: 0x160178, Func Offset: 0x3c8
	// Line 5001, Address: 0x160180, Func Offset: 0x3d0
	// Line 5002, Address: 0x160234, Func Offset: 0x484
	// Line 5004, Address: 0x160248, Func Offset: 0x498
	// Line 5007, Address: 0x160290, Func Offset: 0x4e0
	// Line 5009, Address: 0x160298, Func Offset: 0x4e8
	// Line 5010, Address: 0x16029c, Func Offset: 0x4ec
	// Func End, Address: 0x1602a4, Func Offset: 0x4f4
}

// 
// Start address: 0x1602b0
unsigned int bhLightParameterCSet()
{
	int v9;
	int v8;
	int v7;
	int v6;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5022, Address: 0x1602b0, Func Offset: 0
	// Line 5045, Address: 0x1602b8, Func Offset: 0x8
	// Line 5057, Address: 0x1602c0, Func Offset: 0x10
	// Line 5045, Address: 0x1602c4, Func Offset: 0x14
	// Line 5022, Address: 0x1602cc, Func Offset: 0x1c
	// Line 5023, Address: 0x1602d8, Func Offset: 0x28
	// Line 5024, Address: 0x1602e4, Func Offset: 0x34
	// Line 5045, Address: 0x1602ec, Func Offset: 0x3c
	// Line 5024, Address: 0x1602f0, Func Offset: 0x40
	// Line 5025, Address: 0x1602f4, Func Offset: 0x44
	// Line 5045, Address: 0x1602fc, Func Offset: 0x4c
	// Line 5025, Address: 0x160300, Func Offset: 0x50
	// Line 5026, Address: 0x160304, Func Offset: 0x54
	// Line 5045, Address: 0x160308, Func Offset: 0x58
	// Line 5026, Address: 0x16030c, Func Offset: 0x5c
	// Line 5027, Address: 0x160314, Func Offset: 0x64
	// Line 5028, Address: 0x160320, Func Offset: 0x70
	// Line 5029, Address: 0x16032c, Func Offset: 0x7c
	// Line 5046, Address: 0x160338, Func Offset: 0x88
	// Line 5047, Address: 0x16033c, Func Offset: 0x8c
	// Line 5046, Address: 0x160344, Func Offset: 0x94
	// Line 5030, Address: 0x160348, Func Offset: 0x98
	// Line 5031, Address: 0x160354, Func Offset: 0xa4
	// Line 5046, Address: 0x16035c, Func Offset: 0xac
	// Line 5031, Address: 0x160360, Func Offset: 0xb0
	// Line 5032, Address: 0x160364, Func Offset: 0xb4
	// Line 5034, Address: 0x160370, Func Offset: 0xc0
	// Line 5035, Address: 0x16037c, Func Offset: 0xcc
	// Line 5036, Address: 0x160388, Func Offset: 0xd8
	// Line 5047, Address: 0x160390, Func Offset: 0xe0
	// Line 5036, Address: 0x160394, Func Offset: 0xe4
	// Line 5047, Address: 0x160398, Func Offset: 0xe8
	// Line 5037, Address: 0x16039c, Func Offset: 0xec
	// Line 5038, Address: 0x1603a8, Func Offset: 0xf8
	// Line 5039, Address: 0x1603b4, Func Offset: 0x104
	// Line 5040, Address: 0x1603c0, Func Offset: 0x110
	// Line 5048, Address: 0x1603cc, Func Offset: 0x11c
	// Line 5049, Address: 0x1603d0, Func Offset: 0x120
	// Line 5048, Address: 0x1603d8, Func Offset: 0x128
	// Line 5041, Address: 0x1603dc, Func Offset: 0x12c
	// Line 5042, Address: 0x1603e8, Func Offset: 0x138
	// Line 5049, Address: 0x1603f0, Func Offset: 0x140
	// Line 5042, Address: 0x1603f4, Func Offset: 0x144
	// Line 5048, Address: 0x1603f8, Func Offset: 0x148
	// Line 5043, Address: 0x1603fc, Func Offset: 0x14c
	// Line 5045, Address: 0x160408, Func Offset: 0x158
	// Line 5046, Address: 0x16040c, Func Offset: 0x15c
	// Line 5047, Address: 0x160418, Func Offset: 0x168
	// Line 5048, Address: 0x160424, Func Offset: 0x174
	// Line 5049, Address: 0x16042c, Func Offset: 0x17c
	// Line 5048, Address: 0x160430, Func Offset: 0x180
	// Line 5049, Address: 0x160434, Func Offset: 0x184
	// Line 5051, Address: 0x16043c, Func Offset: 0x18c
	// Line 5049, Address: 0x160440, Func Offset: 0x190
	// Line 5051, Address: 0x160444, Func Offset: 0x194
	// Line 5052, Address: 0x160448, Func Offset: 0x198
	// Line 5051, Address: 0x160450, Func Offset: 0x1a0
	// Line 5052, Address: 0x16045c, Func Offset: 0x1ac
	// Line 5051, Address: 0x160460, Func Offset: 0x1b0
	// Line 5052, Address: 0x160464, Func Offset: 0x1b4
	// Line 5053, Address: 0x160470, Func Offset: 0x1c0
	// Line 5052, Address: 0x160474, Func Offset: 0x1c4
	// Line 5053, Address: 0x160478, Func Offset: 0x1c8
	// Line 5054, Address: 0x16047c, Func Offset: 0x1cc
	// Line 5053, Address: 0x160484, Func Offset: 0x1d4
	// Line 5054, Address: 0x160490, Func Offset: 0x1e0
	// Line 5053, Address: 0x160498, Func Offset: 0x1e8
	// Line 5054, Address: 0x16049c, Func Offset: 0x1ec
	// Line 5055, Address: 0x1604a4, Func Offset: 0x1f4
	// Line 5054, Address: 0x1604a8, Func Offset: 0x1f8
	// Line 5055, Address: 0x1604ac, Func Offset: 0x1fc
	// Line 5058, Address: 0x1604c4, Func Offset: 0x214
	// Func End, Address: 0x1604cc, Func Offset: 0x21c
}

// 
// Start address: 0x1604d0
unsigned int bhLightParameterStart()
{
	float frm;
	float ans[3];
	float ips_w[3][4];
	_anon11* lp;
	unsigned int v1;
	unsigned int v0;
	// Line 5066, Address: 0x1604d0, Func Offset: 0
	// Line 5074, Address: 0x1604f0, Func Offset: 0x20
	// Line 5075, Address: 0x160504, Func Offset: 0x34
	// Line 5076, Address: 0x160510, Func Offset: 0x40
	// Line 5077, Address: 0x16051c, Func Offset: 0x4c
	// Line 5078, Address: 0x160528, Func Offset: 0x58
	// Line 5089, Address: 0x160530, Func Offset: 0x60
	// Line 5093, Address: 0x160574, Func Offset: 0xa4
	// Line 5102, Address: 0x16057c, Func Offset: 0xac
	// Line 5094, Address: 0x160580, Func Offset: 0xb0
	// Line 5102, Address: 0x160584, Func Offset: 0xb4
	// Line 5096, Address: 0x160588, Func Offset: 0xb8
	// Line 5093, Address: 0x16058c, Func Offset: 0xbc
	// Line 5097, Address: 0x160590, Func Offset: 0xc0
	// Line 5103, Address: 0x160594, Func Offset: 0xc4
	// Line 5093, Address: 0x16059c, Func Offset: 0xcc
	// Line 5094, Address: 0x1605a0, Func Offset: 0xd0
	// Line 5103, Address: 0x1605a4, Func Offset: 0xd4
	// Line 5094, Address: 0x1605a8, Func Offset: 0xd8
	// Line 5096, Address: 0x1605ac, Func Offset: 0xdc
	// Line 5097, Address: 0x1605b4, Func Offset: 0xe4
	// Line 5099, Address: 0x1605bc, Func Offset: 0xec
	// Line 5100, Address: 0x1605c4, Func Offset: 0xf4
	// Line 5102, Address: 0x1605cc, Func Offset: 0xfc
	// Line 5103, Address: 0x1605e4, Func Offset: 0x114
	// Line 5104, Address: 0x1605ec, Func Offset: 0x11c
	// Line 5105, Address: 0x1605f0, Func Offset: 0x120
	// Line 5114, Address: 0x1605f4, Func Offset: 0x124
	// Line 5108, Address: 0x1605f8, Func Offset: 0x128
	// Line 5114, Address: 0x1605fc, Func Offset: 0x12c
	// Line 5104, Address: 0x160600, Func Offset: 0x130
	// Line 5105, Address: 0x160604, Func Offset: 0x134
	// Line 5114, Address: 0x160608, Func Offset: 0x138
	// Line 5105, Address: 0x160610, Func Offset: 0x140
	// Line 5106, Address: 0x160614, Func Offset: 0x144
	// Line 5108, Address: 0x16061c, Func Offset: 0x14c
	// Line 5109, Address: 0x160628, Func Offset: 0x158
	// Line 5111, Address: 0x160630, Func Offset: 0x160
	// Line 5112, Address: 0x160638, Func Offset: 0x168
	// Line 5114, Address: 0x16063c, Func Offset: 0x16c
	// Line 5115, Address: 0x160644, Func Offset: 0x174
	// Line 5118, Address: 0x160648, Func Offset: 0x178
	// Line 5115, Address: 0x16064c, Func Offset: 0x17c
	// Line 5116, Address: 0x160650, Func Offset: 0x180
	// Line 5119, Address: 0x160658, Func Offset: 0x188
	// Func End, Address: 0x16067c, Func Offset: 0x1ac
}

// 
// Start address: 0x160680
unsigned int bhInitMidiSlotSet()
{
	int v1;
	int v0;
	// Line 5128, Address: 0x160680, Func Offset: 0
	// Line 5131, Address: 0x160688, Func Offset: 0x8
	// Line 5132, Address: 0x16069c, Func Offset: 0x1c
	// Line 5133, Address: 0x1606a8, Func Offset: 0x28
	// Line 5134, Address: 0x1606b4, Func Offset: 0x34
	// Line 5135, Address: 0x1606c0, Func Offset: 0x40
	// Line 5137, Address: 0x1606c8, Func Offset: 0x48
	// Line 5140, Address: 0x1606d0, Func Offset: 0x50
	// Line 5139, Address: 0x1606d4, Func Offset: 0x54
	// Line 5140, Address: 0x1606d8, Func Offset: 0x58
	// Func End, Address: 0x1606e0, Func Offset: 0x60
}

// 
// Start address: 0x1606e0
unsigned int bh3dSoundFlagSet()
{
	int v2;
	int v1;
	int v0;
	// Line 5148, Address: 0x1606e0, Func Offset: 0
	// Line 5151, Address: 0x1606e8, Func Offset: 0x8
	// Line 5152, Address: 0x1606fc, Func Offset: 0x1c
	// Line 5153, Address: 0x160708, Func Offset: 0x28
	// Line 5154, Address: 0x160714, Func Offset: 0x34
	// Line 5155, Address: 0x160720, Func Offset: 0x40
	// Line 5156, Address: 0x16072c, Func Offset: 0x4c
	// Line 5157, Address: 0x160738, Func Offset: 0x58
	// Line 5159, Address: 0x160740, Func Offset: 0x60
	// Line 5162, Address: 0x160748, Func Offset: 0x68
	// Line 5161, Address: 0x16074c, Func Offset: 0x6c
	// Line 5162, Address: 0x160750, Func Offset: 0x70
	// Func End, Address: 0x160758, Func Offset: 0x78
}

// 
// Start address: 0x160760
unsigned int bhSoundVolumeSet()
{
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5171, Address: 0x160760, Func Offset: 0
	// Line 5175, Address: 0x160768, Func Offset: 0x8
	// Line 5176, Address: 0x16077c, Func Offset: 0x1c
	// Line 5177, Address: 0x160788, Func Offset: 0x28
	// Line 5178, Address: 0x160794, Func Offset: 0x34
	// Line 5179, Address: 0x1607a0, Func Offset: 0x40
	// Line 5180, Address: 0x1607ac, Func Offset: 0x4c
	// Line 5182, Address: 0x1607b8, Func Offset: 0x58
	// Line 5183, Address: 0x1607c4, Func Offset: 0x64
	// Line 5181, Address: 0x1607cc, Func Offset: 0x6c
	// Line 5183, Address: 0x1607d0, Func Offset: 0x70
	// Line 5185, Address: 0x1607d4, Func Offset: 0x74
	// Line 5186, Address: 0x1607e0, Func Offset: 0x80
	// Line 5184, Address: 0x1607e8, Func Offset: 0x88
	// Line 5186, Address: 0x1607ec, Func Offset: 0x8c
	// Line 5187, Address: 0x1607f0, Func Offset: 0x90
	// Line 5189, Address: 0x1607f8, Func Offset: 0x98
	// Line 5192, Address: 0x160800, Func Offset: 0xa0
	// Line 5191, Address: 0x160804, Func Offset: 0xa4
	// Line 5192, Address: 0x160808, Func Offset: 0xa8
	// Func End, Address: 0x160810, Func Offset: 0xb0
}

// 
// Start address: 0x160810
unsigned int bhLightParameterSet()
{
	_anon11* lp;
	int v6;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5205, Address: 0x160810, Func Offset: 0
	// Line 5206, Address: 0x160824, Func Offset: 0x14
	// Line 5207, Address: 0x160830, Func Offset: 0x20
	// Line 5208, Address: 0x16083c, Func Offset: 0x2c
	// Line 5209, Address: 0x160848, Func Offset: 0x38
	// Line 5210, Address: 0x160854, Func Offset: 0x44
	// Line 5211, Address: 0x160860, Func Offset: 0x50
	// Line 5212, Address: 0x16086c, Func Offset: 0x5c
	// Line 5213, Address: 0x160878, Func Offset: 0x68
	// Line 5214, Address: 0x160884, Func Offset: 0x74
	// Line 5215, Address: 0x160890, Func Offset: 0x80
	// Line 5216, Address: 0x16089c, Func Offset: 0x8c
	// Line 5217, Address: 0x1608a8, Func Offset: 0x98
	// Line 5218, Address: 0x1608b4, Func Offset: 0xa4
	// Line 5219, Address: 0x1608c0, Func Offset: 0xb0
	// Line 5230, Address: 0x1608c8, Func Offset: 0xb8
	// Line 5233, Address: 0x16090c, Func Offset: 0xfc
	// Line 5234, Address: 0x160910, Func Offset: 0x100
	// Line 5233, Address: 0x160918, Func Offset: 0x108
	// Line 5239, Address: 0x160920, Func Offset: 0x110
	// Line 5233, Address: 0x160924, Func Offset: 0x114
	// Line 5234, Address: 0x160928, Func Offset: 0x118
	// Line 5233, Address: 0x16092c, Func Offset: 0x11c
	// Line 5234, Address: 0x160934, Func Offset: 0x124
	// Line 5235, Address: 0x16093c, Func Offset: 0x12c
	// Line 5236, Address: 0x160940, Func Offset: 0x130
	// Line 5235, Address: 0x160948, Func Offset: 0x138
	// Line 5236, Address: 0x16094c, Func Offset: 0x13c
	// Line 5235, Address: 0x160950, Func Offset: 0x140
	// Line 5236, Address: 0x160954, Func Offset: 0x144
	// Line 5235, Address: 0x160958, Func Offset: 0x148
	// Line 5236, Address: 0x16095c, Func Offset: 0x14c
	// Line 5237, Address: 0x160960, Func Offset: 0x150
	// Line 5240, Address: 0x160978, Func Offset: 0x168
	// Func End, Address: 0x160980, Func Offset: 0x170
}

// 
// Start address: 0x160980
unsigned int bhEneSeOn()
{
	BH_PWORK* epw;
	_anon39 pPos;
	unsigned int v3;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 5248, Address: 0x160980, Func Offset: 0
	// Line 5254, Address: 0x160988, Func Offset: 0x8
	// Line 5269, Address: 0x160990, Func Offset: 0x10
	// Line 5275, Address: 0x160998, Func Offset: 0x18
	// Line 5269, Address: 0x16099c, Func Offset: 0x1c
	// Line 5254, Address: 0x1609a4, Func Offset: 0x24
	// Line 5255, Address: 0x1609b0, Func Offset: 0x30
	// Line 5256, Address: 0x1609bc, Func Offset: 0x3c
	// Line 5257, Address: 0x1609c8, Func Offset: 0x48
	// Line 5258, Address: 0x1609d4, Func Offset: 0x54
	// Line 5259, Address: 0x1609e0, Func Offset: 0x60
	// Line 5269, Address: 0x1609e8, Func Offset: 0x68
	// Line 5259, Address: 0x1609f4, Func Offset: 0x74
	// Line 5260, Address: 0x1609f8, Func Offset: 0x78
	// Line 5261, Address: 0x160a04, Func Offset: 0x84
	// Line 5271, Address: 0x160a0c, Func Offset: 0x8c
	// Line 5261, Address: 0x160a1c, Func Offset: 0x9c
	// Line 5262, Address: 0x160a20, Func Offset: 0xa0
	// Line 5271, Address: 0x160a24, Func Offset: 0xa4
	// Line 5262, Address: 0x160a28, Func Offset: 0xa8
	// Line 5269, Address: 0x160a30, Func Offset: 0xb0
	// Line 5271, Address: 0x160a54, Func Offset: 0xd4
	// Line 5272, Address: 0x160a68, Func Offset: 0xe8
	// Line 5273, Address: 0x160a7c, Func Offset: 0xfc
	// Line 5275, Address: 0x160a8c, Func Offset: 0x10c
	// Line 5278, Address: 0x160a94, Func Offset: 0x114
	// Line 5277, Address: 0x160a98, Func Offset: 0x118
	// Line 5278, Address: 0x160a9c, Func Offset: 0x11c
	// Func End, Address: 0x160aa4, Func Offset: 0x124
}

// 
// Start address: 0x160ab0
unsigned int bhEneSeOff()
{
	unsigned char v0;
	// Line 5286, Address: 0x160ab0, Func Offset: 0
	// Line 5289, Address: 0x160ab8, Func Offset: 0x8
	// Line 5290, Address: 0x160acc, Func Offset: 0x1c
	// Line 5291, Address: 0x160ad8, Func Offset: 0x28
	// Line 5292, Address: 0x160ae0, Func Offset: 0x30
	// Line 5295, Address: 0x160ae8, Func Offset: 0x38
	// Line 5294, Address: 0x160aec, Func Offset: 0x3c
	// Line 5295, Address: 0x160af0, Func Offset: 0x40
	// Func End, Address: 0x160af8, Func Offset: 0x48
}

// 
// Start address: 0x160b00
unsigned int bhWalAtariSet2()
{
	_anon6* e_walp;
	unsigned int v1;
	// Line 5309, Address: 0x160b00, Func Offset: 0
	// Line 5344, Address: 0x160b08, Func Offset: 0x8
	// Line 5316, Address: 0x160b0c, Func Offset: 0xc
	// Line 5309, Address: 0x160b14, Func Offset: 0x14
	// Line 5317, Address: 0x160b20, Func Offset: 0x20
	// Line 5316, Address: 0x160b28, Func Offset: 0x28
	// Line 5317, Address: 0x160b2c, Func Offset: 0x2c
	// Line 5319, Address: 0x160b30, Func Offset: 0x30
	// Line 5317, Address: 0x160b3c, Func Offset: 0x3c
	// Line 5320, Address: 0x160b44, Func Offset: 0x44
	// Line 5317, Address: 0x160b4c, Func Offset: 0x4c
	// Line 5320, Address: 0x160b54, Func Offset: 0x54
	// Line 5323, Address: 0x160b58, Func Offset: 0x58
	// Line 5321, Address: 0x160b5c, Func Offset: 0x5c
	// Line 5323, Address: 0x160b60, Func Offset: 0x60
	// Line 5324, Address: 0x160b70, Func Offset: 0x70
	// Line 5327, Address: 0x160b7c, Func Offset: 0x7c
	// Line 5325, Address: 0x160b80, Func Offset: 0x80
	// Line 5327, Address: 0x160b84, Func Offset: 0x84
	// Line 5328, Address: 0x160b94, Func Offset: 0x94
	// Line 5331, Address: 0x160ba0, Func Offset: 0xa0
	// Line 5329, Address: 0x160ba4, Func Offset: 0xa4
	// Line 5331, Address: 0x160ba8, Func Offset: 0xa8
	// Line 5332, Address: 0x160bb8, Func Offset: 0xb8
	// Line 5335, Address: 0x160bc4, Func Offset: 0xc4
	// Line 5333, Address: 0x160bc8, Func Offset: 0xc8
	// Line 5335, Address: 0x160bcc, Func Offset: 0xcc
	// Line 5336, Address: 0x160bdc, Func Offset: 0xdc
	// Line 5339, Address: 0x160be8, Func Offset: 0xe8
	// Line 5337, Address: 0x160bec, Func Offset: 0xec
	// Line 5339, Address: 0x160bf0, Func Offset: 0xf0
	// Line 5340, Address: 0x160c00, Func Offset: 0x100
	// Line 5342, Address: 0x160c0c, Func Offset: 0x10c
	// Line 5341, Address: 0x160c10, Func Offset: 0x110
	// Line 5342, Address: 0x160c14, Func Offset: 0x114
	// Line 5345, Address: 0x160c20, Func Offset: 0x120
	// Func End, Address: 0x160c28, Func Offset: 0x128
}

// 
// Start address: 0x160c30
unsigned int bhFlrAtariSet2()
{
	_anon6* e_flrp;
	unsigned int v1;
	// Line 5359, Address: 0x160c30, Func Offset: 0
	// Line 5394, Address: 0x160c38, Func Offset: 0x8
	// Line 5366, Address: 0x160c3c, Func Offset: 0xc
	// Line 5359, Address: 0x160c44, Func Offset: 0x14
	// Line 5367, Address: 0x160c50, Func Offset: 0x20
	// Line 5366, Address: 0x160c58, Func Offset: 0x28
	// Line 5367, Address: 0x160c5c, Func Offset: 0x2c
	// Line 5369, Address: 0x160c60, Func Offset: 0x30
	// Line 5367, Address: 0x160c6c, Func Offset: 0x3c
	// Line 5370, Address: 0x160c74, Func Offset: 0x44
	// Line 5367, Address: 0x160c7c, Func Offset: 0x4c
	// Line 5370, Address: 0x160c84, Func Offset: 0x54
	// Line 5373, Address: 0x160c88, Func Offset: 0x58
	// Line 5371, Address: 0x160c8c, Func Offset: 0x5c
	// Line 5373, Address: 0x160c90, Func Offset: 0x60
	// Line 5374, Address: 0x160ca0, Func Offset: 0x70
	// Line 5377, Address: 0x160cac, Func Offset: 0x7c
	// Line 5375, Address: 0x160cb0, Func Offset: 0x80
	// Line 5377, Address: 0x160cb4, Func Offset: 0x84
	// Line 5378, Address: 0x160cc4, Func Offset: 0x94
	// Line 5381, Address: 0x160cd0, Func Offset: 0xa0
	// Line 5379, Address: 0x160cd4, Func Offset: 0xa4
	// Line 5381, Address: 0x160cd8, Func Offset: 0xa8
	// Line 5382, Address: 0x160ce8, Func Offset: 0xb8
	// Line 5385, Address: 0x160cf4, Func Offset: 0xc4
	// Line 5383, Address: 0x160cf8, Func Offset: 0xc8
	// Line 5385, Address: 0x160cfc, Func Offset: 0xcc
	// Line 5386, Address: 0x160d0c, Func Offset: 0xdc
	// Line 5389, Address: 0x160d18, Func Offset: 0xe8
	// Line 5387, Address: 0x160d1c, Func Offset: 0xec
	// Line 5389, Address: 0x160d20, Func Offset: 0xf0
	// Line 5390, Address: 0x160d30, Func Offset: 0x100
	// Line 5392, Address: 0x160d3c, Func Offset: 0x10c
	// Line 5391, Address: 0x160d40, Func Offset: 0x110
	// Line 5392, Address: 0x160d44, Func Offset: 0x114
	// Line 5395, Address: 0x160d50, Func Offset: 0x120
	// Func End, Address: 0x160d58, Func Offset: 0x128
}

// 
// Start address: 0x160d60
unsigned int bhMotionPosSetEnePly()
{
	short ay;
	BH_PWORK* e_workp;
	int v1;
	int v0;
	// Line 5403, Address: 0x160d60, Func Offset: 0
	// Line 5411, Address: 0x160d6c, Func Offset: 0xc
	// Line 5421, Address: 0x160d74, Func Offset: 0x14
	// Line 5411, Address: 0x160d84, Func Offset: 0x24
	// Line 5427, Address: 0x160d88, Func Offset: 0x28
	// Line 5411, Address: 0x160d90, Func Offset: 0x30
	// Line 5412, Address: 0x160d98, Func Offset: 0x38
	// Line 5413, Address: 0x160da4, Func Offset: 0x44
	// Line 5414, Address: 0x160db0, Func Offset: 0x50
	// Line 5421, Address: 0x160db8, Func Offset: 0x58
	// Line 5414, Address: 0x160dc8, Func Offset: 0x68
	// Line 5423, Address: 0x160dcc, Func Offset: 0x6c
	// Line 5421, Address: 0x160dd0, Func Offset: 0x70
	// Line 5423, Address: 0x160dd8, Func Offset: 0x78
	// Line 5431, Address: 0x160de0, Func Offset: 0x80
	// Line 5421, Address: 0x160de4, Func Offset: 0x84
	// Line 5425, Address: 0x160dec, Func Offset: 0x8c
	// Line 5421, Address: 0x160df4, Func Offset: 0x94
	// Line 5425, Address: 0x160e04, Func Offset: 0xa4
	// Line 5427, Address: 0x160e10, Func Offset: 0xb0
	// Line 5428, Address: 0x160e14, Func Offset: 0xb4
	// Line 5427, Address: 0x160e18, Func Offset: 0xb8
	// Line 5428, Address: 0x160e24, Func Offset: 0xc4
	// Line 5431, Address: 0x160e3c, Func Offset: 0xdc
	// Line 5428, Address: 0x160e40, Func Offset: 0xe0
	// Line 5431, Address: 0x160e44, Func Offset: 0xe4
	// Line 5432, Address: 0x160e58, Func Offset: 0xf8
	// Line 5431, Address: 0x160e5c, Func Offset: 0xfc
	// Line 5432, Address: 0x160e60, Func Offset: 0x100
	// Line 5435, Address: 0x160e68, Func Offset: 0x108
	// Line 5432, Address: 0x160e6c, Func Offset: 0x10c
	// Line 5435, Address: 0x160e70, Func Offset: 0x110
	// Line 5437, Address: 0x160e88, Func Offset: 0x128
	// Line 5438, Address: 0x160e98, Func Offset: 0x138
	// Line 5437, Address: 0x160e9c, Func Offset: 0x13c
	// Line 5438, Address: 0x160ea4, Func Offset: 0x144
	// Line 5450, Address: 0x160ebc, Func Offset: 0x15c
	// Line 5438, Address: 0x160ec0, Func Offset: 0x160
	// Line 5442, Address: 0x160ec4, Func Offset: 0x164
	// Line 5450, Address: 0x160ec8, Func Offset: 0x168
	// Line 5442, Address: 0x160ecc, Func Offset: 0x16c
	// Line 5450, Address: 0x160edc, Func Offset: 0x17c
	// Line 5442, Address: 0x160ee0, Func Offset: 0x180
	// Line 5450, Address: 0x160efc, Func Offset: 0x19c
	// Line 5451, Address: 0x160f18, Func Offset: 0x1b8
	// Line 5455, Address: 0x160f24, Func Offset: 0x1c4
	// Line 5451, Address: 0x160f28, Func Offset: 0x1c8
	// Line 5455, Address: 0x160f2c, Func Offset: 0x1cc
	// Line 5458, Address: 0x160f34, Func Offset: 0x1d4
	// Line 5457, Address: 0x160f3c, Func Offset: 0x1dc
	// Line 5458, Address: 0x160f40, Func Offset: 0x1e0
	// Func End, Address: 0x160f48, Func Offset: 0x1e8
}

// 
// Start address: 0x160f50
unsigned int bhKageSwSet()
{
	_anon0* e_ip;
	BH_PWORK* e_ep;
	unsigned int v4;
	unsigned int v3;
	unsigned int v2;
	// Line 5475, Address: 0x160f50, Func Offset: 0
	// Line 5483, Address: 0x160f58, Func Offset: 0x8
	// Line 5475, Address: 0x160f5c, Func Offset: 0xc
	// Line 5476, Address: 0x160f68, Func Offset: 0x18
	// Line 5477, Address: 0x160f74, Func Offset: 0x24
	// Line 5478, Address: 0x160f80, Func Offset: 0x30
	// Line 5479, Address: 0x160f8c, Func Offset: 0x3c
	// Line 5480, Address: 0x160f98, Func Offset: 0x48
	// Line 5481, Address: 0x160fa4, Func Offset: 0x54
	// Line 5483, Address: 0x160fac, Func Offset: 0x5c
	// Line 5485, Address: 0x160fdc, Func Offset: 0x8c
	// Line 5486, Address: 0x160fe4, Func Offset: 0x94
	// Line 5487, Address: 0x160ff4, Func Offset: 0xa4
	// Line 5488, Address: 0x160ffc, Func Offset: 0xac
	// Line 5490, Address: 0x161010, Func Offset: 0xc0
	// Line 5496, Address: 0x161018, Func Offset: 0xc8
	// Line 5497, Address: 0x161054, Func Offset: 0x104
	// Line 5498, Address: 0x16105c, Func Offset: 0x10c
	// Line 5499, Address: 0x161064, Func Offset: 0x114
	// Line 5500, Address: 0x16106c, Func Offset: 0x11c
	// Line 5502, Address: 0x161078, Func Offset: 0x128
	// Line 5507, Address: 0x161080, Func Offset: 0x130
	// Line 5508, Address: 0x1610a8, Func Offset: 0x158
	// Line 5509, Address: 0x1610b0, Func Offset: 0x160
	// Line 5510, Address: 0x1610b8, Func Offset: 0x168
	// Line 5511, Address: 0x1610c0, Func Offset: 0x170
	// Line 5513, Address: 0x1610cc, Func Offset: 0x17c
	// Line 5518, Address: 0x1610d4, Func Offset: 0x184
	// Line 5519, Address: 0x1610fc, Func Offset: 0x1ac
	// Line 5520, Address: 0x161104, Func Offset: 0x1b4
	// Line 5521, Address: 0x16110c, Func Offset: 0x1bc
	// Line 5522, Address: 0x161114, Func Offset: 0x1c4
	// Line 5526, Address: 0x161124, Func Offset: 0x1d4
	// Line 5527, Address: 0x161128, Func Offset: 0x1d8
	// Func End, Address: 0x161130, Func Offset: 0x1e0
}

// 
// Start address: 0x161130
unsigned int bhSoundPanSet()
{
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5536, Address: 0x161130, Func Offset: 0
	// Line 5540, Address: 0x161138, Func Offset: 0x8
	// Line 5541, Address: 0x16114c, Func Offset: 0x1c
	// Line 5542, Address: 0x161158, Func Offset: 0x28
	// Line 5543, Address: 0x161164, Func Offset: 0x34
	// Line 5544, Address: 0x161170, Func Offset: 0x40
	// Line 5545, Address: 0x16117c, Func Offset: 0x4c
	// Line 5547, Address: 0x161188, Func Offset: 0x58
	// Line 5548, Address: 0x161194, Func Offset: 0x64
	// Line 5554, Address: 0x16119c, Func Offset: 0x6c
	// Line 5548, Address: 0x1611a0, Func Offset: 0x70
	// Line 5550, Address: 0x1611a4, Func Offset: 0x74
	// Line 5551, Address: 0x1611b0, Func Offset: 0x80
	// Line 5554, Address: 0x1611b8, Func Offset: 0x88
	// Line 5551, Address: 0x1611bc, Func Offset: 0x8c
	// Line 5552, Address: 0x1611c0, Func Offset: 0x90
	// Line 5554, Address: 0x1611c8, Func Offset: 0x98
	// Line 5557, Address: 0x1611d0, Func Offset: 0xa0
	// Line 5556, Address: 0x1611d4, Func Offset: 0xa4
	// Line 5557, Address: 0x1611d8, Func Offset: 0xa8
	// Func End, Address: 0x1611e0, Func Offset: 0xb0
}

// 
// Start address: 0x1611e0
unsigned int bhInitPonySet()
{
	unsigned int v3;
	unsigned int v2;
	// Line 5573, Address: 0x1611e0, Func Offset: 0
	// Line 5579, Address: 0x1611e8, Func Offset: 0x8
	// Line 5573, Address: 0x1611ec, Func Offset: 0xc
	// Line 5574, Address: 0x1611f8, Func Offset: 0x18
	// Line 5575, Address: 0x161204, Func Offset: 0x24
	// Line 5576, Address: 0x161210, Func Offset: 0x30
	// Line 5577, Address: 0x16121c, Func Offset: 0x3c
	// Line 5579, Address: 0x161224, Func Offset: 0x44
	// Line 5581, Address: 0x16123c, Func Offset: 0x5c
	// Line 5582, Address: 0x16124c, Func Offset: 0x6c
	// Line 5586, Address: 0x161254, Func Offset: 0x74
	// Line 5589, Address: 0x1612a0, Func Offset: 0xc0
	// Line 5590, Address: 0x1612a4, Func Offset: 0xc4
	// Func End, Address: 0x1612ac, Func Offset: 0xcc
}

// 
// Start address: 0x1612b0
unsigned int bhCyoutenHenkeiSetEX()
{
	BH_PWORK* epw;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5605, Address: 0x1612b0, Func Offset: 0
	// Line 5617, Address: 0x1612b8, Func Offset: 0x8
	// Line 5605, Address: 0x1612bc, Func Offset: 0xc
	// Line 5606, Address: 0x1612c8, Func Offset: 0x18
	// Line 5607, Address: 0x1612d4, Func Offset: 0x24
	// Line 5608, Address: 0x1612e0, Func Offset: 0x30
	// Line 5609, Address: 0x1612ec, Func Offset: 0x3c
	// Line 5610, Address: 0x1612f8, Func Offset: 0x48
	// Line 5611, Address: 0x161304, Func Offset: 0x54
	// Line 5612, Address: 0x161310, Func Offset: 0x60
	// Line 5613, Address: 0x16131c, Func Offset: 0x6c
	// Line 5614, Address: 0x161328, Func Offset: 0x78
	// Line 5615, Address: 0x161334, Func Offset: 0x84
	// Line 5617, Address: 0x16133c, Func Offset: 0x8c
	// Line 5619, Address: 0x161354, Func Offset: 0xa4
	// Line 5620, Address: 0x161358, Func Offset: 0xa8
	// Line 5626, Address: 0x161360, Func Offset: 0xb0
	// Line 5631, Address: 0x1613a0, Func Offset: 0xf0
	// Line 5639, Address: 0x1613a8, Func Offset: 0xf8
	// Line 5631, Address: 0x1613ac, Func Offset: 0xfc
	// Line 5634, Address: 0x1613b4, Func Offset: 0x104
	// Line 5639, Address: 0x1613bc, Func Offset: 0x10c
	// Line 5642, Address: 0x1613c0, Func Offset: 0x110
	// Line 5631, Address: 0x1613c4, Func Offset: 0x114
	// Line 5633, Address: 0x1613c8, Func Offset: 0x118
	// Line 5634, Address: 0x1613d0, Func Offset: 0x120
	// Line 5638, Address: 0x1613d8, Func Offset: 0x128
	// Line 5643, Address: 0x1613e4, Func Offset: 0x134
	// Func End, Address: 0x1613ec, Func Offset: 0x13c
}

// 
// Start address: 0x1613f0
unsigned int bhCyoutenHenkeiStartEX()
{
	float frm1;
	float frm0;
	int v0;
	// Line 5656, Address: 0x1613f0, Func Offset: 0
	// Line 5662, Address: 0x1613f8, Func Offset: 0x8
	// Line 5667, Address: 0x161400, Func Offset: 0x10
	// Line 5656, Address: 0x161408, Func Offset: 0x18
	// Line 5658, Address: 0x161414, Func Offset: 0x24
	// Line 5659, Address: 0x161420, Func Offset: 0x30
	// Line 5661, Address: 0x161424, Func Offset: 0x34
	// Line 5659, Address: 0x161428, Func Offset: 0x38
	// Line 5661, Address: 0x16142c, Func Offset: 0x3c
	// Line 5659, Address: 0x161430, Func Offset: 0x40
	// Line 5667, Address: 0x161434, Func Offset: 0x44
	// Line 5668, Address: 0x161440, Func Offset: 0x50
	// Line 5669, Address: 0x161444, Func Offset: 0x54
	// Line 5668, Address: 0x161448, Func Offset: 0x58
	// Line 5669, Address: 0x161450, Func Offset: 0x60
	// Line 5672, Address: 0x16147c, Func Offset: 0x8c
	// Func End, Address: 0x161484, Func Offset: 0x94
}

// 
// Start address: 0x161490
unsigned int bhEasySESet()
{
	BH_PWORK* epw;
	_anon1 gp;
	int v8;
	int v7;
	int v6;
	int v5;
	int v4;
	// Line 5685, Address: 0x161490, Func Offset: 0
	// Line 5695, Address: 0x161498, Func Offset: 0x8
	// Line 5700, Address: 0x1614a0, Func Offset: 0x10
	// Line 5703, Address: 0x1614a4, Func Offset: 0x14
	// Line 5706, Address: 0x1614a8, Func Offset: 0x18
	// Line 5695, Address: 0x1614ac, Func Offset: 0x1c
	// Line 5696, Address: 0x1614b8, Func Offset: 0x28
	// Line 5709, Address: 0x1614c0, Func Offset: 0x30
	// Line 5724, Address: 0x1614c4, Func Offset: 0x34
	// Line 5696, Address: 0x1614c8, Func Offset: 0x38
	// Line 5697, Address: 0x1614cc, Func Offset: 0x3c
	// Line 5698, Address: 0x1614d8, Func Offset: 0x48
	// Line 5696, Address: 0x1614e0, Func Offset: 0x50
	// Line 5698, Address: 0x1614e4, Func Offset: 0x54
	// Line 5699, Address: 0x1614e8, Func Offset: 0x58
	// Line 5700, Address: 0x1614f4, Func Offset: 0x64
	// Line 5698, Address: 0x1614fc, Func Offset: 0x6c
	// Line 5700, Address: 0x161500, Func Offset: 0x70
	// Line 5702, Address: 0x161504, Func Offset: 0x74
	// Line 5700, Address: 0x161508, Func Offset: 0x78
	// Line 5701, Address: 0x16150c, Func Offset: 0x7c
	// Line 5702, Address: 0x161518, Func Offset: 0x88
	// Line 5703, Address: 0x161528, Func Offset: 0x98
	// Line 5705, Address: 0x161534, Func Offset: 0xa4
	// Line 5703, Address: 0x161538, Func Offset: 0xa8
	// Line 5704, Address: 0x16153c, Func Offset: 0xac
	// Line 5705, Address: 0x161548, Func Offset: 0xb8
	// Line 5706, Address: 0x161558, Func Offset: 0xc8
	// Line 5708, Address: 0x161564, Func Offset: 0xd4
	// Line 5706, Address: 0x161568, Func Offset: 0xd8
	// Line 5707, Address: 0x16156c, Func Offset: 0xdc
	// Line 5708, Address: 0x161578, Func Offset: 0xe8
	// Line 5709, Address: 0x161588, Func Offset: 0xf8
	// Line 5711, Address: 0x161594, Func Offset: 0x104
	// Line 5709, Address: 0x161598, Func Offset: 0x108
	// Line 5710, Address: 0x16159c, Func Offset: 0x10c
	// Line 5711, Address: 0x1615a8, Func Offset: 0x118
	// Line 5712, Address: 0x1615b8, Func Offset: 0x128
	// Line 5713, Address: 0x1615c4, Func Offset: 0x134
	// Line 5714, Address: 0x1615d0, Func Offset: 0x140
	// Line 5712, Address: 0x1615d8, Func Offset: 0x148
	// Line 5714, Address: 0x1615dc, Func Offset: 0x14c
	// Line 5715, Address: 0x1615e0, Func Offset: 0x150
	// Line 5717, Address: 0x1615ec, Func Offset: 0x15c
	// Line 5718, Address: 0x1615f8, Func Offset: 0x168
	// Line 5719, Address: 0x161604, Func Offset: 0x174
	// Line 5720, Address: 0x161610, Func Offset: 0x180
	// Line 5721, Address: 0x16161c, Func Offset: 0x18c
	// Line 5722, Address: 0x161628, Func Offset: 0x198
	// Line 5724, Address: 0x161630, Func Offset: 0x1a0
	// Line 5726, Address: 0x161660, Func Offset: 0x1d0
	// Line 5727, Address: 0x161664, Func Offset: 0x1d4
	// Line 5730, Address: 0x16166c, Func Offset: 0x1dc
	// Line 5731, Address: 0x1616a8, Func Offset: 0x218
	// Line 5733, Address: 0x1616b0, Func Offset: 0x220
	// Line 5734, Address: 0x1616d8, Func Offset: 0x248
	// Line 5736, Address: 0x1616e0, Func Offset: 0x250
	// Line 5766, Address: 0x16170c, Func Offset: 0x27c
	// Line 5773, Address: 0x161714, Func Offset: 0x284
	// Line 5766, Address: 0x161724, Func Offset: 0x294
	// Line 5767, Address: 0x161728, Func Offset: 0x298
	// Line 5768, Address: 0x161734, Func Offset: 0x2a4
	// Line 5769, Address: 0x161740, Func Offset: 0x2b0
	// Line 5768, Address: 0x161748, Func Offset: 0x2b8
	// Line 5769, Address: 0x16174c, Func Offset: 0x2bc
	// Line 5773, Address: 0x161750, Func Offset: 0x2c0
	// Line 5780, Address: 0x161764, Func Offset: 0x2d4
	// Line 5779, Address: 0x161768, Func Offset: 0x2d8
	// Line 5780, Address: 0x16176c, Func Offset: 0x2dc
	// Func End, Address: 0x161774, Func Offset: 0x2e4
}

// 
// Start address: 0x161780
unsigned int bhSoundFlagReSet()
{
	// Line 5788, Address: 0x161780, Func Offset: 0
	// Line 5789, Address: 0x161788, Func Offset: 0x8
	// Line 5790, Address: 0x161798, Func Offset: 0x18
	// Line 5792, Address: 0x1617a0, Func Offset: 0x20
	// Line 5791, Address: 0x1617a4, Func Offset: 0x24
	// Line 5792, Address: 0x1617a8, Func Offset: 0x28
	// Func End, Address: 0x1617b0, Func Offset: 0x30
}

// 
// Start address: 0x1617b0
unsigned int bhEffUVSet()
{
	_anon0* e_ep;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5804, Address: 0x1617b0, Func Offset: 0
	// Line 5820, Address: 0x1617b8, Func Offset: 0x8
	// Line 5822, Address: 0x1617c0, Func Offset: 0x10
	// Line 5820, Address: 0x1617c8, Func Offset: 0x18
	// Line 5804, Address: 0x1617d0, Func Offset: 0x20
	// Line 5834, Address: 0x1617d4, Func Offset: 0x24
	// Line 5804, Address: 0x1617d8, Func Offset: 0x28
	// Line 5805, Address: 0x1617e0, Func Offset: 0x30
	// Line 5806, Address: 0x1617ec, Func Offset: 0x3c
	// Line 5820, Address: 0x1617f8, Func Offset: 0x48
	// Line 5807, Address: 0x161800, Func Offset: 0x50
	// Line 5808, Address: 0x16180c, Func Offset: 0x5c
	// Line 5822, Address: 0x161810, Func Offset: 0x60
	// Line 5808, Address: 0x161814, Func Offset: 0x64
	// Line 5822, Address: 0x161818, Func Offset: 0x68
	// Line 5808, Address: 0x16181c, Func Offset: 0x6c
	// Line 5809, Address: 0x161820, Func Offset: 0x70
	// Line 5822, Address: 0x161828, Func Offset: 0x78
	// Line 5809, Address: 0x16182c, Func Offset: 0x7c
	// Line 5810, Address: 0x161830, Func Offset: 0x80
	// Line 5811, Address: 0x16183c, Func Offset: 0x8c
	// Line 5812, Address: 0x161848, Func Offset: 0x98
	// Line 5813, Address: 0x161854, Func Offset: 0xa4
	// Line 5825, Address: 0x16185c, Func Offset: 0xac
	// Line 5823, Address: 0x161860, Func Offset: 0xb0
	// Line 5825, Address: 0x161868, Func Offset: 0xb8
	// Line 5813, Address: 0x16186c, Func Offset: 0xbc
	// Line 5814, Address: 0x161870, Func Offset: 0xc0
	// Line 5825, Address: 0x161874, Func Offset: 0xc4
	// Line 5814, Address: 0x161878, Func Offset: 0xc8
	// Line 5820, Address: 0x161880, Func Offset: 0xd0
	// Line 5822, Address: 0x1618a4, Func Offset: 0xf4
	// Line 5823, Address: 0x1618a8, Func Offset: 0xf8
	// Line 5829, Address: 0x1618ac, Func Offset: 0xfc
	// Line 5823, Address: 0x1618b4, Func Offset: 0x104
	// Line 5829, Address: 0x1618b8, Func Offset: 0x108
	// Line 5823, Address: 0x1618bc, Func Offset: 0x10c
	// Line 5825, Address: 0x1618c0, Func Offset: 0x110
	// Line 5826, Address: 0x1618c4, Func Offset: 0x114
	// Line 5828, Address: 0x1618c8, Func Offset: 0x118
	// Line 5829, Address: 0x1618cc, Func Offset: 0x11c
	// Line 5831, Address: 0x1618d4, Func Offset: 0x124
	// Line 5835, Address: 0x1618d8, Func Offset: 0x128
	// Func End, Address: 0x1618e0, Func Offset: 0x130
}

// 
// Start address: 0x1618e0
unsigned int bhPlayerChangeSet()
{
	int v0;
	// Line 5846, Address: 0x1618e0, Func Offset: 0
	// Line 5853, Address: 0x1618e8, Func Offset: 0x8
	// Line 5850, Address: 0x1618ec, Func Offset: 0xc
	// Line 5846, Address: 0x1618f4, Func Offset: 0x14
	// Line 5847, Address: 0x161900, Func Offset: 0x20
	// Line 5848, Address: 0x16190c, Func Offset: 0x2c
	// Line 5850, Address: 0x161918, Func Offset: 0x38
	// Line 5851, Address: 0x161924, Func Offset: 0x44
	// Line 5854, Address: 0x161934, Func Offset: 0x54
	// Func End, Address: 0x16193c, Func Offset: 0x5c
}

// 
// Start address: 0x161940
unsigned int bhPlayerPoisonCk()
{
	int v0;
	// Line 5865, Address: 0x161940, Func Offset: 0
	// Line 5869, Address: 0x161948, Func Offset: 0x8
	// Line 5865, Address: 0x161954, Func Offset: 0x14
	// Line 5866, Address: 0x161960, Func Offset: 0x20
	// Line 5867, Address: 0x16196c, Func Offset: 0x2c
	// Line 5869, Address: 0x161978, Func Offset: 0x38
	// Line 5870, Address: 0x161988, Func Offset: 0x48
	// Line 5873, Address: 0x161994, Func Offset: 0x54
	// Line 5876, Address: 0x1619a0, Func Offset: 0x60
	// Func End, Address: 0x1619a8, Func Offset: 0x68
}

// 
// Start address: 0x1619b0
unsigned int bhAddObjSe()
{
	_anon39 pPos;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 5884, Address: 0x1619b0, Func Offset: 0
	// Line 5888, Address: 0x1619b8, Func Offset: 0x8
	// Line 5889, Address: 0x1619cc, Func Offset: 0x1c
	// Line 5890, Address: 0x1619d8, Func Offset: 0x28
	// Line 5891, Address: 0x1619e4, Func Offset: 0x34
	// Line 5892, Address: 0x1619f0, Func Offset: 0x40
	// Line 5893, Address: 0x1619fc, Func Offset: 0x4c
	// Line 5894, Address: 0x161a08, Func Offset: 0x58
	// Line 5897, Address: 0x161a14, Func Offset: 0x64
	// Line 5898, Address: 0x161a20, Func Offset: 0x70
	// Line 5899, Address: 0x161a7c, Func Offset: 0xcc
	// Line 5900, Address: 0x161a84, Func Offset: 0xd4
	// Line 5902, Address: 0x161ad4, Func Offset: 0x124
	// Line 5904, Address: 0x161adc, Func Offset: 0x12c
	// Line 5902, Address: 0x161ae0, Func Offset: 0x130
	// Line 5904, Address: 0x161ae8, Func Offset: 0x138
	// Line 5905, Address: 0x161af0, Func Offset: 0x140
	// Line 5906, Address: 0x161b4c, Func Offset: 0x19c
	// Line 5907, Address: 0x161b54, Func Offset: 0x1a4
	// Line 5909, Address: 0x161ba4, Func Offset: 0x1f4
	// Line 5911, Address: 0x161bac, Func Offset: 0x1fc
	// Line 5909, Address: 0x161bb0, Func Offset: 0x200
	// Line 5911, Address: 0x161bb8, Func Offset: 0x208
	// Line 5912, Address: 0x161bc0, Func Offset: 0x210
	// Line 5913, Address: 0x161c1c, Func Offset: 0x26c
	// Line 5914, Address: 0x161c24, Func Offset: 0x274
	// Line 5916, Address: 0x161c74, Func Offset: 0x2c4
	// Line 5920, Address: 0x161c7c, Func Offset: 0x2cc
	// Line 5916, Address: 0x161c80, Func Offset: 0x2d0
	// Line 5917, Address: 0x161c8c, Func Offset: 0x2dc
	// Line 5918, Address: 0x161c98, Func Offset: 0x2e8
	// Line 5920, Address: 0x161ca0, Func Offset: 0x2f0
	// Line 5922, Address: 0x161ca8, Func Offset: 0x2f8
	// Line 5921, Address: 0x161cac, Func Offset: 0x2fc
	// Line 5922, Address: 0x161cb0, Func Offset: 0x300
	// Func End, Address: 0x161cb8, Func Offset: 0x308
}

// 
// Start address: 0x161cc0
unsigned int bhRandTest()
{
	unsigned int v1;
	int v0;
	// Line 5930, Address: 0x161cc0, Func Offset: 0
	// Line 5938, Address: 0x161cc8, Func Offset: 0x8
	// Line 5939, Address: 0x161cdc, Func Offset: 0x1c
	// Line 5940, Address: 0x161ce8, Func Offset: 0x28
	// Line 5941, Address: 0x161cf4, Func Offset: 0x34
	// Line 5943, Address: 0x161d00, Func Offset: 0x40
	// Line 5944, Address: 0x161d0c, Func Offset: 0x4c
	// Line 5942, Address: 0x161d14, Func Offset: 0x54
	// Line 5944, Address: 0x161d18, Func Offset: 0x58
	// Line 5945, Address: 0x161d1c, Func Offset: 0x5c
	// Line 5948, Address: 0x161d28, Func Offset: 0x68
	// Line 5949, Address: 0x161d30, Func Offset: 0x70
	// Line 5950, Address: 0x161d38, Func Offset: 0x78
	// Line 5954, Address: 0x161d50, Func Offset: 0x90
	// Line 5950, Address: 0x161d58, Func Offset: 0x98
	// Line 5954, Address: 0x161d6c, Func Offset: 0xac
	// Line 5955, Address: 0x161d74, Func Offset: 0xb4
	// Line 5956, Address: 0x161d7c, Func Offset: 0xbc
	// Line 5960, Address: 0x161d94, Func Offset: 0xd4
	// Line 5956, Address: 0x161d9c, Func Offset: 0xdc
	// Line 5960, Address: 0x161db0, Func Offset: 0xf0
	// Line 5977, Address: 0x161dbc, Func Offset: 0xfc
	// Line 5976, Address: 0x161dc0, Func Offset: 0x100
	// Line 5977, Address: 0x161dc4, Func Offset: 0x104
	// Func End, Address: 0x161dcc, Func Offset: 0x10c
}

// 
// Start address: 0x161dd0
unsigned int bhEvtComSet()
{
	int v0;
	// Line 5988, Address: 0x161dd0, Func Offset: 0
	// Line 5992, Address: 0x161dd8, Func Offset: 0x8
	// Line 5995, Address: 0x161ddc, Func Offset: 0xc
	// Line 5992, Address: 0x161de0, Func Offset: 0x10
	// Line 5988, Address: 0x161de8, Func Offset: 0x18
	// Line 5989, Address: 0x161df4, Func Offset: 0x24
	// Line 5990, Address: 0x161e00, Func Offset: 0x30
	// Line 5992, Address: 0x161e0c, Func Offset: 0x3c
	// Line 5993, Address: 0x161e10, Func Offset: 0x40
	// Line 5992, Address: 0x161e14, Func Offset: 0x44
	// Line 5993, Address: 0x161e1c, Func Offset: 0x4c
	// Line 5996, Address: 0x161e28, Func Offset: 0x58
	// Func End, Address: 0x161e30, Func Offset: 0x60
}

// 
// Start address: 0x161e30
unsigned int bhZombieUpDieCk()
{
	BH_PWORK* e_ep;
	int v1;
	int v0;
	// Line 6004, Address: 0x161e30, Func Offset: 0
	// Line 6009, Address: 0x161e38, Func Offset: 0x8
	// Line 6020, Address: 0x161e40, Func Offset: 0x10
	// Line 6021, Address: 0x161e48, Func Offset: 0x18
	// Line 6020, Address: 0x161e4c, Func Offset: 0x1c
	// Line 6009, Address: 0x161e54, Func Offset: 0x24
	// Line 6010, Address: 0x161e60, Func Offset: 0x30
	// Line 6011, Address: 0x161e6c, Func Offset: 0x3c
	// Line 6012, Address: 0x161e78, Func Offset: 0x48
	// Line 6020, Address: 0x161e80, Func Offset: 0x50
	// Line 6012, Address: 0x161e8c, Func Offset: 0x5c
	// Line 6013, Address: 0x161e90, Func Offset: 0x60
	// Line 6020, Address: 0x161e9c, Func Offset: 0x6c
	// Line 6021, Address: 0x161ec0, Func Offset: 0x90
	// Line 6022, Address: 0x161ecc, Func Offset: 0x9c
	// Line 6023, Address: 0x161ee0, Func Offset: 0xb0
	// Line 6027, Address: 0x161eec, Func Offset: 0xbc
	// Line 6026, Address: 0x161ef0, Func Offset: 0xc0
	// Line 6027, Address: 0x161ef4, Func Offset: 0xc4
	// Func End, Address: 0x161efc, Func Offset: 0xcc
}

// 
// Start address: 0x161f00
unsigned int bhFacePauseSet()
{
	BH_PWORK* pp;
	int v2;
	int v1;
	// Line 6043, Address: 0x161f00, Func Offset: 0
	// Line 6054, Address: 0x161f08, Func Offset: 0x8
	// Line 6043, Address: 0x161f18, Func Offset: 0x18
	// Line 6044, Address: 0x161f24, Func Offset: 0x24
	// Line 6045, Address: 0x161f30, Func Offset: 0x30
	// Line 6046, Address: 0x161f3c, Func Offset: 0x3c
	// Line 6054, Address: 0x161f44, Func Offset: 0x44
	// Line 6046, Address: 0x161f50, Func Offset: 0x50
	// Line 6047, Address: 0x161f54, Func Offset: 0x54
	// Line 6054, Address: 0x161f60, Func Offset: 0x60
	// Line 6056, Address: 0x161f80, Func Offset: 0x80
	// Line 6057, Address: 0x161f88, Func Offset: 0x88
	// Line 6058, Address: 0x161f94, Func Offset: 0x94
	// Line 6059, Address: 0x161f9c, Func Offset: 0x9c
	// Line 6062, Address: 0x161fb0, Func Offset: 0xb0
	// Func End, Address: 0x161fb8, Func Offset: 0xb8
}

// 
// Start address: 0x161fc0
unsigned int bhFaceReSet()
{
	int v1;
	// Line 6078, Address: 0x161fc0, Func Offset: 0
	// Line 6089, Address: 0x161fc8, Func Offset: 0x8
	// Line 6091, Address: 0x161fd0, Func Offset: 0x10
	// Line 6089, Address: 0x161fd4, Func Offset: 0x14
	// Line 6078, Address: 0x161fdc, Func Offset: 0x1c
	// Line 6079, Address: 0x161fe8, Func Offset: 0x28
	// Line 6080, Address: 0x161ff4, Func Offset: 0x34
	// Line 6089, Address: 0x162000, Func Offset: 0x40
	// Line 6092, Address: 0x16203c, Func Offset: 0x7c
	// Func End, Address: 0x162044, Func Offset: 0x84
}

// 
// Start address: 0x162050
unsigned int bhEffModeSet()
{
	int v1;
	int v0;
	// Line 6104, Address: 0x162050, Func Offset: 0
	// Line 6115, Address: 0x162058, Func Offset: 0x8
	// Line 6117, Address: 0x162060, Func Offset: 0x10
	// Line 6115, Address: 0x162064, Func Offset: 0x14
	// Line 6104, Address: 0x16206c, Func Offset: 0x1c
	// Line 6105, Address: 0x162078, Func Offset: 0x28
	// Line 6106, Address: 0x162084, Func Offset: 0x34
	// Line 6115, Address: 0x162090, Func Offset: 0x40
	// Line 6107, Address: 0x162098, Func Offset: 0x48
	// Line 6108, Address: 0x1620a4, Func Offset: 0x54
	// Line 6115, Address: 0x1620b0, Func Offset: 0x60
	// Line 6118, Address: 0x1620d4, Func Offset: 0x84
	// Func End, Address: 0x1620dc, Func Offset: 0x8c
}

// 
// Start address: 0x1620e0
unsigned int bhEnemyHpUp()
{
	BH_PWORK* e_ep;
	int v1;
	int v0;
	// Line 6131, Address: 0x1620e0, Func Offset: 0
	// Line 6142, Address: 0x1620e8, Func Offset: 0x8
	// Line 6144, Address: 0x1620f0, Func Offset: 0x10
	// Line 6142, Address: 0x1620f4, Func Offset: 0x14
	// Line 6131, Address: 0x1620fc, Func Offset: 0x1c
	// Line 6132, Address: 0x162108, Func Offset: 0x28
	// Line 6144, Address: 0x162110, Func Offset: 0x30
	// Line 6145, Address: 0x162114, Func Offset: 0x34
	// Line 6132, Address: 0x162118, Func Offset: 0x38
	// Line 6133, Address: 0x16211c, Func Offset: 0x3c
	// Line 6134, Address: 0x162128, Func Offset: 0x48
	// Line 6142, Address: 0x162130, Func Offset: 0x50
	// Line 6134, Address: 0x16213c, Func Offset: 0x5c
	// Line 6135, Address: 0x162140, Func Offset: 0x60
	// Line 6142, Address: 0x16214c, Func Offset: 0x6c
	// Line 6144, Address: 0x162170, Func Offset: 0x90
	// Line 6146, Address: 0x162194, Func Offset: 0xb4
	// Func End, Address: 0x16219c, Func Offset: 0xbc
}

// 
// Start address: 0x1621a0
unsigned int bhFaceRep()
{
	BH_PWORK* pp;
	int v1;
	int v0;
	// Line 6162, Address: 0x1621a0, Func Offset: 0
	// Line 6173, Address: 0x1621a8, Func Offset: 0x8
	// Line 6162, Address: 0x1621b8, Func Offset: 0x18
	// Line 6163, Address: 0x1621c4, Func Offset: 0x24
	// Line 6164, Address: 0x1621d0, Func Offset: 0x30
	// Line 6165, Address: 0x1621dc, Func Offset: 0x3c
	// Line 6173, Address: 0x1621e4, Func Offset: 0x44
	// Line 6165, Address: 0x1621f0, Func Offset: 0x50
	// Line 6166, Address: 0x1621f4, Func Offset: 0x54
	// Line 6173, Address: 0x162200, Func Offset: 0x60
	// Line 6175, Address: 0x162220, Func Offset: 0x80
	// Line 6176, Address: 0x162228, Func Offset: 0x88
	// Line 6177, Address: 0x162234, Func Offset: 0x94
	// Line 6178, Address: 0x16223c, Func Offset: 0x9c
	// Line 6181, Address: 0x162250, Func Offset: 0xb0
	// Func End, Address: 0x162258, Func Offset: 0xb8
}

// 
// Start address: 0x162260
unsigned int bhBGSeOff2()
{
	unsigned int v0;
	// Line 6189, Address: 0x162260, Func Offset: 0
	// Line 6193, Address: 0x162268, Func Offset: 0x8
	// Line 6194, Address: 0x16227c, Func Offset: 0x1c
	// Line 6195, Address: 0x162288, Func Offset: 0x28
	// Line 6196, Address: 0x162290, Func Offset: 0x30
	// Line 6198, Address: 0x162298, Func Offset: 0x38
	// Line 6197, Address: 0x16229c, Func Offset: 0x3c
	// Line 6198, Address: 0x1622a0, Func Offset: 0x40
	// Func End, Address: 0x1622a8, Func Offset: 0x48
}

// 
// Start address: 0x1622b0
unsigned int bhBgmOff2()
{
	// Line 6206, Address: 0x1622b0, Func Offset: 0
	// Line 6207, Address: 0x1622b8, Func Offset: 0x8
	// Line 6208, Address: 0x1622c8, Func Offset: 0x18
	// Line 6210, Address: 0x1622d0, Func Offset: 0x20
	// Line 6209, Address: 0x1622d4, Func Offset: 0x24
	// Line 6210, Address: 0x1622d8, Func Offset: 0x28
	// Func End, Address: 0x1622e0, Func Offset: 0x30
}

// 
// Start address: 0x1622e0
unsigned int bhBGSeOn2()
{
	unsigned int v1;
	unsigned int v0;
	// Line 6218, Address: 0x1622e0, Func Offset: 0
	// Line 6222, Address: 0x1622e8, Func Offset: 0x8
	// Line 6223, Address: 0x1622fc, Func Offset: 0x1c
	// Line 6224, Address: 0x162308, Func Offset: 0x28
	// Line 6225, Address: 0x162314, Func Offset: 0x34
	// Line 6226, Address: 0x162320, Func Offset: 0x40
	// Line 6227, Address: 0x162328, Func Offset: 0x48
	// Line 6229, Address: 0x162330, Func Offset: 0x50
	// Line 6228, Address: 0x162334, Func Offset: 0x54
	// Line 6229, Address: 0x162338, Func Offset: 0x58
	// Func End, Address: 0x162340, Func Offset: 0x60
}

// 
// Start address: 0x162340
unsigned int bhBgmOn2()
{
	int v2;
	int v1;
	int v0;
	// Line 6237, Address: 0x162340, Func Offset: 0
	// Line 6240, Address: 0x162348, Func Offset: 0x8
	// Line 6244, Address: 0x162350, Func Offset: 0x10
	// Line 6240, Address: 0x162354, Func Offset: 0x14
	// Line 6241, Address: 0x162360, Func Offset: 0x20
	// Line 6242, Address: 0x16236c, Func Offset: 0x2c
	// Line 6243, Address: 0x162378, Func Offset: 0x38
	// Line 6245, Address: 0x162384, Func Offset: 0x44
	// Line 6249, Address: 0x162390, Func Offset: 0x50
	// Line 6251, Address: 0x162398, Func Offset: 0x58
	// Line 6250, Address: 0x16239c, Func Offset: 0x5c
	// Line 6251, Address: 0x1623a0, Func Offset: 0x60
	// Func End, Address: 0x1623a8, Func Offset: 0x68
}

// 
// Start address: 0x1623b0
unsigned int bhMovieCk()
{
	int ret;
	int v0;
	// Line 6259, Address: 0x1623b0, Func Offset: 0
	// Line 6262, Address: 0x1623b8, Func Offset: 0x8
	// Line 6263, Address: 0x1623cc, Func Offset: 0x1c
	// Line 6264, Address: 0x1623e0, Func Offset: 0x30
	// Line 6266, Address: 0x1623f4, Func Offset: 0x44
	// Line 6267, Address: 0x162404, Func Offset: 0x54
	// Line 6268, Address: 0x16240c, Func Offset: 0x5c
	// Line 6270, Address: 0x162414, Func Offset: 0x64
	// Line 6271, Address: 0x16241c, Func Offset: 0x6c
	// Line 6274, Address: 0x162420, Func Offset: 0x70
	// Func End, Address: 0x16242c, Func Offset: 0x7c
}

// 
// Start address: 0x162430
unsigned int bhSetItmMotion()
{
	unsigned char* a0;
	BH_PWORK* ob_ep;
	// Line 6282, Address: 0x162430, Func Offset: 0
	// Line 6287, Address: 0x16243c, Func Offset: 0xc
	// Line 6298, Address: 0x162444, Func Offset: 0x14
	// Line 6296, Address: 0x162448, Func Offset: 0x18
	// Line 6288, Address: 0x162450, Func Offset: 0x20
	// Line 6296, Address: 0x162454, Func Offset: 0x24
	// Line 6288, Address: 0x162458, Func Offset: 0x28
	// Line 6290, Address: 0x162460, Func Offset: 0x30
	// Line 6296, Address: 0x162474, Func Offset: 0x44
	// Line 6298, Address: 0x16249c, Func Offset: 0x6c
	// Line 6299, Address: 0x1624b8, Func Offset: 0x88
	// Line 6301, Address: 0x1624cc, Func Offset: 0x9c
	// Line 6305, Address: 0x1624d4, Func Offset: 0xa4
	// Line 6304, Address: 0x1624dc, Func Offset: 0xac
	// Line 6305, Address: 0x1624e0, Func Offset: 0xb0
	// Func End, Address: 0x1624e8, Func Offset: 0xb8
}

// 
// Start address: 0x1624f0
unsigned int bhObjAspdSet()
{
	unsigned int v1;
	unsigned int v0;
	// Line 6317, Address: 0x1624f0, Func Offset: 0
	// Line 6330, Address: 0x1624f8, Func Offset: 0x8
	// Line 6328, Address: 0x1624fc, Func Offset: 0xc
	// Line 6317, Address: 0x162504, Func Offset: 0x14
	// Line 6318, Address: 0x162510, Func Offset: 0x20
	// Line 6319, Address: 0x16251c, Func Offset: 0x2c
	// Line 6320, Address: 0x162528, Func Offset: 0x38
	// Line 6328, Address: 0x162530, Func Offset: 0x40
	// Line 6320, Address: 0x162540, Func Offset: 0x50
	// Line 6328, Address: 0x162544, Func Offset: 0x54
	// Line 6321, Address: 0x162548, Func Offset: 0x58
	// Line 6328, Address: 0x162554, Func Offset: 0x64
	// Line 6331, Address: 0x162564, Func Offset: 0x74
	// Func End, Address: 0x16256c, Func Offset: 0x7c
}

// 
// Start address: 0x162570
unsigned int bhPuruPuruFlagSet()
{
	unsigned int v0;
	// Line 6339, Address: 0x162570, Func Offset: 0
	// Line 6342, Address: 0x162578, Func Offset: 0x8
	// Line 6343, Address: 0x16258c, Func Offset: 0x1c
	// Line 6344, Address: 0x162598, Func Offset: 0x28
	// Line 6345, Address: 0x1625a0, Func Offset: 0x30
	// Line 6346, Address: 0x1625a8, Func Offset: 0x38
	// Line 6347, Address: 0x1625b0, Func Offset: 0x40
	// Line 6348, Address: 0x1625b8, Func Offset: 0x48
	// Line 6351, Address: 0x1625c0, Func Offset: 0x50
	// Line 6350, Address: 0x1625c4, Func Offset: 0x54
	// Line 6351, Address: 0x1625c8, Func Offset: 0x58
	// Func End, Address: 0x1625d0, Func Offset: 0x60
}

// 
// Start address: 0x1625d0
unsigned int bhPuruPuruStart()
{
	unsigned int v0;
	// Line 6359, Address: 0x1625d0, Func Offset: 0
	// Line 6362, Address: 0x1625d8, Func Offset: 0x8
	// Line 6373, Address: 0x1625e0, Func Offset: 0x10
	// Line 6362, Address: 0x1625e4, Func Offset: 0x14
	// Line 6363, Address: 0x1625f0, Func Offset: 0x20
	// Line 6364, Address: 0x1625fc, Func Offset: 0x2c
	// Line 6373, Address: 0x162604, Func Offset: 0x34
	// Line 6377, Address: 0x16260c, Func Offset: 0x3c
	// Line 6376, Address: 0x162610, Func Offset: 0x40
	// Line 6377, Address: 0x162614, Func Offset: 0x44
	// Func End, Address: 0x16261c, Func Offset: 0x4c
}

// 
// Start address: 0x162620
unsigned int bhSubMapBusyCk()
{
	unsigned int v0;
	// Line 6388, Address: 0x162620, Func Offset: 0
	// Line 6391, Address: 0x162628, Func Offset: 0x8
	// Line 6388, Address: 0x162634, Func Offset: 0x14
	// Line 6389, Address: 0x162640, Func Offset: 0x20
	// Line 6390, Address: 0x16264c, Func Offset: 0x2c
	// Line 6391, Address: 0x162658, Func Offset: 0x38
	// Line 6392, Address: 0x162674, Func Offset: 0x54
	// Line 6395, Address: 0x162680, Func Offset: 0x60
	// Line 6397, Address: 0x16268c, Func Offset: 0x6c
	// Func End, Address: 0x162694, Func Offset: 0x74
}

// 
// Start address: 0x1626a0
unsigned int bhMapSystemOn()
{
	unsigned int v3;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 6408, Address: 0x1626a0, Func Offset: 0
	// Line 6422, Address: 0x1626a8, Func Offset: 0x8
	// Line 6423, Address: 0x1626ac, Func Offset: 0xc
	// Line 6418, Address: 0x1626b0, Func Offset: 0x10
	// Line 6408, Address: 0x1626b8, Func Offset: 0x18
	// Line 6409, Address: 0x1626c4, Func Offset: 0x24
	// Line 6410, Address: 0x1626d0, Func Offset: 0x30
	// Line 6411, Address: 0x1626dc, Func Offset: 0x3c
	// Line 6412, Address: 0x1626e8, Func Offset: 0x48
	// Line 6413, Address: 0x1626f4, Func Offset: 0x54
	// Line 6414, Address: 0x162700, Func Offset: 0x60
	// Line 6415, Address: 0x16270c, Func Offset: 0x6c
	// Line 6416, Address: 0x162718, Func Offset: 0x78
	// Line 6418, Address: 0x162724, Func Offset: 0x84
	// Line 6419, Address: 0x162730, Func Offset: 0x90
	// Line 6420, Address: 0x162744, Func Offset: 0xa4
	// Line 6421, Address: 0x162758, Func Offset: 0xb8
	// Line 6422, Address: 0x16276c, Func Offset: 0xcc
	// Line 6424, Address: 0x16277c, Func Offset: 0xdc
	// Func End, Address: 0x162784, Func Offset: 0xe4
}

// 
// Start address: 0x162790
unsigned int bhTrapDamageSet()
{
	unsigned int v0;
	// Line 6435, Address: 0x162790, Func Offset: 0
	// Line 6436, Address: 0x1627a4, Func Offset: 0x14
	// Line 6437, Address: 0x1627b0, Func Offset: 0x20
	// Line 6439, Address: 0x1627b8, Func Offset: 0x28
	// Line 6440, Address: 0x1627c0, Func Offset: 0x30
	// Line 6441, Address: 0x1627d0, Func Offset: 0x40
	// Line 6442, Address: 0x1627d8, Func Offset: 0x48
	// Line 6445, Address: 0x1627f0, Func Offset: 0x60
	// Func End, Address: 0x1627f8, Func Offset: 0x68
}

// 
// Start address: 0x162800
unsigned int bhEvtLighterFireSet()
{
	unsigned int v1;
	unsigned int v0;
	// Line 6453, Address: 0x162800, Func Offset: 0
	// Line 6457, Address: 0x162808, Func Offset: 0x8
	// Line 6468, Address: 0x162810, Func Offset: 0x10
	// Line 6457, Address: 0x162818, Func Offset: 0x18
	// Line 6458, Address: 0x162824, Func Offset: 0x24
	// Line 6459, Address: 0x162830, Func Offset: 0x30
	// Line 6460, Address: 0x16283c, Func Offset: 0x3c
	// Line 6468, Address: 0x162844, Func Offset: 0x44
	// Line 6460, Address: 0x162854, Func Offset: 0x54
	// Line 6468, Address: 0x162858, Func Offset: 0x58
	// Line 6461, Address: 0x16285c, Func Offset: 0x5c
	// Line 6468, Address: 0x162868, Func Offset: 0x68
	// Line 6471, Address: 0x16287c, Func Offset: 0x7c
	// Line 6470, Address: 0x162880, Func Offset: 0x80
	// Line 6471, Address: 0x162884, Func Offset: 0x84
	// Func End, Address: 0x16288c, Func Offset: 0x8c
}

// 
// Start address: 0x162890
unsigned int bhObjLinkSetPlyItem()
{
	int v1;
	// Line 6483, Address: 0x162890, Func Offset: 0
	// Line 6485, Address: 0x162898, Func Offset: 0x8
	// Line 6483, Address: 0x1628a0, Func Offset: 0x10
	// Line 6485, Address: 0x1628a4, Func Offset: 0x14
	// Line 6483, Address: 0x1628ac, Func Offset: 0x1c
	// Line 6485, Address: 0x1628b4, Func Offset: 0x24
	// Line 6487, Address: 0x1628cc, Func Offset: 0x3c
	// Line 6485, Address: 0x1628d0, Func Offset: 0x40
	// Line 6487, Address: 0x1628ec, Func Offset: 0x5c
	// Line 6494, Address: 0x1628f0, Func Offset: 0x60
	// Line 6487, Address: 0x1628f8, Func Offset: 0x68
	// Line 6494, Address: 0x162904, Func Offset: 0x74
	// Line 6493, Address: 0x162910, Func Offset: 0x80
	// Line 6494, Address: 0x162918, Func Offset: 0x88
	// Line 6493, Address: 0x16291c, Func Offset: 0x8c
	// Line 6496, Address: 0x162920, Func Offset: 0x90
	// Line 6494, Address: 0x162924, Func Offset: 0x94
	// Line 6496, Address: 0x162928, Func Offset: 0x98
	// Line 6498, Address: 0x162938, Func Offset: 0xa8
	// Line 6499, Address: 0x16294c, Func Offset: 0xbc
	// Line 6500, Address: 0x16296c, Func Offset: 0xdc
	// Line 6501, Address: 0x162974, Func Offset: 0xe4
	// Line 6504, Address: 0x16299c, Func Offset: 0x10c
	// Line 6505, Address: 0x1629b0, Func Offset: 0x120
	// Line 6507, Address: 0x1629bc, Func Offset: 0x12c
	// Line 6510, Address: 0x1629c8, Func Offset: 0x138
	// Line 6511, Address: 0x1629d4, Func Offset: 0x144
	// Line 6512, Address: 0x162a44, Func Offset: 0x1b4
	// Line 6513, Address: 0x162a4c, Func Offset: 0x1bc
	// Line 6515, Address: 0x162ab0, Func Offset: 0x220
	// Line 6518, Address: 0x162ab8, Func Offset: 0x228
	// Line 6515, Address: 0x162abc, Func Offset: 0x22c
	// Line 6518, Address: 0x162ac4, Func Offset: 0x234
	// Line 6519, Address: 0x162acc, Func Offset: 0x23c
	// Line 6520, Address: 0x162b3c, Func Offset: 0x2ac
	// Line 6521, Address: 0x162b44, Func Offset: 0x2b4
	// Line 6523, Address: 0x162ba8, Func Offset: 0x318
	// Line 6526, Address: 0x162bb0, Func Offset: 0x320
	// Line 6523, Address: 0x162bb4, Func Offset: 0x324
	// Line 6526, Address: 0x162bbc, Func Offset: 0x32c
	// Line 6527, Address: 0x162bc4, Func Offset: 0x334
	// Line 6528, Address: 0x162c34, Func Offset: 0x3a4
	// Line 6529, Address: 0x162c3c, Func Offset: 0x3ac
	// Line 6531, Address: 0x162ca0, Func Offset: 0x410
	// Line 6533, Address: 0x162ca8, Func Offset: 0x418
	// Line 6531, Address: 0x162cac, Func Offset: 0x41c
	// Line 6534, Address: 0x162cb4, Func Offset: 0x424
	// Func End, Address: 0x162cbc, Func Offset: 0x42c
}

// 
// Start address: 0x162cc0
unsigned int bhPlayerKaidanMotion()
{
	unsigned int v1;
	unsigned int v0;
	// Line 6542, Address: 0x162cc0, Func Offset: 0
	// Line 6545, Address: 0x162cc8, Func Offset: 0x8
	// Line 6546, Address: 0x162cdc, Func Offset: 0x1c
	// Line 6547, Address: 0x162ce8, Func Offset: 0x28
	// Line 6548, Address: 0x162cf4, Func Offset: 0x34
	// Line 6549, Address: 0x162d00, Func Offset: 0x40
	// Line 6555, Address: 0x162d08, Func Offset: 0x48
	// Line 6558, Address: 0x162d10, Func Offset: 0x50
	// Line 6557, Address: 0x162d14, Func Offset: 0x54
	// Line 6558, Address: 0x162d18, Func Offset: 0x58
	// Func End, Address: 0x162d20, Func Offset: 0x60
}

// 
// Start address: 0x162d20
unsigned int bhEneRenderSet()
{
	BH_PWORK* epw;
	unsigned int v1;
	unsigned int v0;
	// Line 6571, Address: 0x162d20, Func Offset: 0
	// Line 6582, Address: 0x162d28, Func Offset: 0x8
	// Line 6571, Address: 0x162d38, Func Offset: 0x18
	// Line 6572, Address: 0x162d44, Func Offset: 0x24
	// Line 6573, Address: 0x162d50, Func Offset: 0x30
	// Line 6574, Address: 0x162d5c, Func Offset: 0x3c
	// Line 6582, Address: 0x162d64, Func Offset: 0x44
	// Line 6574, Address: 0x162d70, Func Offset: 0x50
	// Line 6575, Address: 0x162d74, Func Offset: 0x54
	// Line 6582, Address: 0x162d80, Func Offset: 0x60
	// Line 6584, Address: 0x162da0, Func Offset: 0x80
	// Line 6585, Address: 0x162da8, Func Offset: 0x88
	// Line 6586, Address: 0x162db0, Func Offset: 0x90
	// Line 6587, Address: 0x162db8, Func Offset: 0x98
	// Line 6591, Address: 0x162dc8, Func Offset: 0xa8
	// Func End, Address: 0x162dd0, Func Offset: 0xb0
}

// 
// Start address: 0x162dd0
unsigned int bhBgmOnEx()
{
	int v2;
	int v1;
	int v0;
	// Line 6599, Address: 0x162dd0, Func Offset: 0
	// Line 6602, Address: 0x162dd8, Func Offset: 0x8
	// Line 6603, Address: 0x162dec, Func Offset: 0x1c
	// Line 6604, Address: 0x162df8, Func Offset: 0x28
	// Line 6605, Address: 0x162e04, Func Offset: 0x34
	// Line 6607, Address: 0x162e10, Func Offset: 0x40
	// Line 6606, Address: 0x162e1c, Func Offset: 0x4c
	// Line 6608, Address: 0x162e24, Func Offset: 0x54
	// Line 6606, Address: 0x162e2c, Func Offset: 0x5c
	// Line 6608, Address: 0x162e30, Func Offset: 0x60
	// Line 6610, Address: 0x162e34, Func Offset: 0x64
	// Line 6611, Address: 0x162e40, Func Offset: 0x70
	// Line 6613, Address: 0x162e48, Func Offset: 0x78
	// Line 6612, Address: 0x162e4c, Func Offset: 0x7c
	// Line 6613, Address: 0x162e50, Func Offset: 0x80
	// Func End, Address: 0x162e58, Func Offset: 0x88
}

// 
// Start address: 0x162e60
unsigned int bhBgmOn2Ex()
{
	int v1;
	int v0;
	// Line 6621, Address: 0x162e60, Func Offset: 0
	// Line 6624, Address: 0x162e68, Func Offset: 0x8
	// Line 6625, Address: 0x162e7c, Func Offset: 0x1c
	// Line 6626, Address: 0x162e88, Func Offset: 0x28
	// Line 6627, Address: 0x162e94, Func Offset: 0x34
	// Line 6629, Address: 0x162ea0, Func Offset: 0x40
	// Line 6630, Address: 0x162eac, Func Offset: 0x4c
	// Line 6632, Address: 0x162eb4, Func Offset: 0x54
	// Line 6631, Address: 0x162eb8, Func Offset: 0x58
	// Line 6632, Address: 0x162ebc, Func Offset: 0x5c
	// Func End, Address: 0x162ec4, Func Offset: 0x64
}

// 
// Start address: 0x162ed0
unsigned int bhFogParameterCSet()
{
	int v7;
	int v6;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 6644, Address: 0x162ed0, Func Offset: 0
	// Line 6673, Address: 0x162ed8, Func Offset: 0x8
	// Line 6663, Address: 0x162edc, Func Offset: 0xc
	// Line 6644, Address: 0x162ee4, Func Offset: 0x14
	// Line 6645, Address: 0x162ef0, Func Offset: 0x20
	// Line 6646, Address: 0x162efc, Func Offset: 0x2c
	// Line 6663, Address: 0x162f04, Func Offset: 0x34
	// Line 6646, Address: 0x162f08, Func Offset: 0x38
	// Line 6647, Address: 0x162f0c, Func Offset: 0x3c
	// Line 6663, Address: 0x162f14, Func Offset: 0x44
	// Line 6647, Address: 0x162f18, Func Offset: 0x48
	// Line 6648, Address: 0x162f1c, Func Offset: 0x4c
	// Line 6664, Address: 0x162f24, Func Offset: 0x54
	// Line 6648, Address: 0x162f28, Func Offset: 0x58
	// Line 6649, Address: 0x162f2c, Func Offset: 0x5c
	// Line 6664, Address: 0x162f34, Func Offset: 0x64
	// Line 6649, Address: 0x162f38, Func Offset: 0x68
	// Line 6650, Address: 0x162f3c, Func Offset: 0x6c
	// Line 6665, Address: 0x162f44, Func Offset: 0x74
	// Line 6650, Address: 0x162f48, Func Offset: 0x78
	// Line 6651, Address: 0x162f4c, Func Offset: 0x7c
	// Line 6665, Address: 0x162f54, Func Offset: 0x84
	// Line 6651, Address: 0x162f58, Func Offset: 0x88
	// Line 6652, Address: 0x162f5c, Func Offset: 0x8c
	// Line 6666, Address: 0x162f64, Func Offset: 0x94
	// Line 6652, Address: 0x162f68, Func Offset: 0x98
	// Line 6654, Address: 0x162f6c, Func Offset: 0x9c
	// Line 6666, Address: 0x162f74, Func Offset: 0xa4
	// Line 6654, Address: 0x162f78, Func Offset: 0xa8
	// Line 6655, Address: 0x162f7c, Func Offset: 0xac
	// Line 6668, Address: 0x162f84, Func Offset: 0xb4
	// Line 6655, Address: 0x162f88, Func Offset: 0xb8
	// Line 6656, Address: 0x162f8c, Func Offset: 0xbc
	// Line 6668, Address: 0x162f94, Func Offset: 0xc4
	// Line 6656, Address: 0x162f98, Func Offset: 0xc8
	// Line 6657, Address: 0x162f9c, Func Offset: 0xcc
	// Line 6669, Address: 0x162fa4, Func Offset: 0xd4
	// Line 6657, Address: 0x162fa8, Func Offset: 0xd8
	// Line 6658, Address: 0x162fac, Func Offset: 0xdc
	// Line 6669, Address: 0x162fb4, Func Offset: 0xe4
	// Line 6658, Address: 0x162fb8, Func Offset: 0xe8
	// Line 6659, Address: 0x162fbc, Func Offset: 0xec
	// Line 6670, Address: 0x162fc4, Func Offset: 0xf4
	// Line 6659, Address: 0x162fc8, Func Offset: 0xf8
	// Line 6660, Address: 0x162fcc, Func Offset: 0xfc
	// Line 6670, Address: 0x162fd4, Func Offset: 0x104
	// Line 6660, Address: 0x162fd8, Func Offset: 0x108
	// Line 6661, Address: 0x162fdc, Func Offset: 0x10c
	// Line 6671, Address: 0x162fe4, Func Offset: 0x114
	// Line 6661, Address: 0x162fe8, Func Offset: 0x118
	// Line 6663, Address: 0x162fec, Func Offset: 0x11c
	// Line 6664, Address: 0x162ff0, Func Offset: 0x120
	// Line 6671, Address: 0x162ff8, Func Offset: 0x128
	// Line 6664, Address: 0x162ffc, Func Offset: 0x12c
	// Line 6665, Address: 0x163000, Func Offset: 0x130
	// Line 6666, Address: 0x16300c, Func Offset: 0x13c
	// Line 6668, Address: 0x163018, Func Offset: 0x148
	// Line 6669, Address: 0x163024, Func Offset: 0x154
	// Line 6670, Address: 0x163030, Func Offset: 0x160
	// Line 6671, Address: 0x16303c, Func Offset: 0x16c
	// Line 6674, Address: 0x163044, Func Offset: 0x174
	// Func End, Address: 0x16304c, Func Offset: 0x17c
}

// 
// Start address: 0x163050
unsigned int bhFogParameterStart()
{
	float frm;
	float ans[3];
	float ips_w[3][4];
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 6682, Address: 0x163050, Func Offset: 0
	// Line 6689, Address: 0x16306c, Func Offset: 0x1c
	// Line 6701, Address: 0x163074, Func Offset: 0x24
	// Line 6693, Address: 0x16307c, Func Offset: 0x2c
	// Line 6702, Address: 0x163080, Func Offset: 0x30
	// Line 6692, Address: 0x163084, Func Offset: 0x34
	// Line 6689, Address: 0x16308c, Func Offset: 0x3c
	// Line 6702, Address: 0x163090, Func Offset: 0x40
	// Line 6689, Address: 0x163098, Func Offset: 0x48
	// Line 6692, Address: 0x1630a0, Func Offset: 0x50
	// Line 6693, Address: 0x1630a8, Func Offset: 0x58
	// Line 6695, Address: 0x1630b0, Func Offset: 0x60
	// Line 6696, Address: 0x1630b8, Func Offset: 0x68
	// Line 6698, Address: 0x1630c0, Func Offset: 0x70
	// Line 6699, Address: 0x1630c8, Func Offset: 0x78
	// Line 6701, Address: 0x1630d0, Func Offset: 0x80
	// Line 6702, Address: 0x1630e8, Func Offset: 0x98
	// Line 6703, Address: 0x1630f0, Func Offset: 0xa0
	// Line 6704, Address: 0x1630f8, Func Offset: 0xa8
	// Line 6705, Address: 0x163104, Func Offset: 0xb4
	// Line 6707, Address: 0x163114, Func Offset: 0xc4
	// Line 6710, Address: 0x16311c, Func Offset: 0xcc
	// Line 6707, Address: 0x16312c, Func Offset: 0xdc
	// Line 6708, Address: 0x163134, Func Offset: 0xe4
	// Line 6710, Address: 0x163138, Func Offset: 0xe8
	// Line 6713, Address: 0x163140, Func Offset: 0xf0
	// Line 6714, Address: 0x163168, Func Offset: 0x118
	// Line 6718, Address: 0x16316c, Func Offset: 0x11c
	// Line 6713, Address: 0x163170, Func Offset: 0x120
	// Line 6714, Address: 0x16317c, Func Offset: 0x12c
	// Line 6715, Address: 0x163188, Func Offset: 0x138
	// Line 6714, Address: 0x16318c, Func Offset: 0x13c
	// Line 6715, Address: 0x163194, Func Offset: 0x144
	// Line 6719, Address: 0x1631a4, Func Offset: 0x154
	// Func End, Address: 0x1631c4, Func Offset: 0x174
}

// 
// Start address: 0x1631d0
unsigned int bhEffUVSet2()
{
	_anon10* tvp;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 6732, Address: 0x1631d0, Func Offset: 0
	// Line 6750, Address: 0x1631d8, Func Offset: 0x8
	// Line 6752, Address: 0x1631e0, Func Offset: 0x10
	// Line 6750, Address: 0x1631e8, Func Offset: 0x18
	// Line 6732, Address: 0x1631f0, Func Offset: 0x20
	// Line 6764, Address: 0x1631f4, Func Offset: 0x24
	// Line 6732, Address: 0x1631f8, Func Offset: 0x28
	// Line 6733, Address: 0x163200, Func Offset: 0x30
	// Line 6734, Address: 0x16320c, Func Offset: 0x3c
	// Line 6750, Address: 0x163218, Func Offset: 0x48
	// Line 6735, Address: 0x163220, Func Offset: 0x50
	// Line 6736, Address: 0x16322c, Func Offset: 0x5c
	// Line 6752, Address: 0x163230, Func Offset: 0x60
	// Line 6736, Address: 0x163234, Func Offset: 0x64
	// Line 6752, Address: 0x163238, Func Offset: 0x68
	// Line 6736, Address: 0x16323c, Func Offset: 0x6c
	// Line 6737, Address: 0x163240, Func Offset: 0x70
	// Line 6752, Address: 0x163248, Func Offset: 0x78
	// Line 6737, Address: 0x16324c, Func Offset: 0x7c
	// Line 6738, Address: 0x163250, Func Offset: 0x80
	// Line 6739, Address: 0x16325c, Func Offset: 0x8c
	// Line 6740, Address: 0x163268, Func Offset: 0x98
	// Line 6741, Address: 0x163274, Func Offset: 0xa4
	// Line 6755, Address: 0x16327c, Func Offset: 0xac
	// Line 6753, Address: 0x163280, Func Offset: 0xb0
	// Line 6755, Address: 0x163288, Func Offset: 0xb8
	// Line 6741, Address: 0x16328c, Func Offset: 0xbc
	// Line 6742, Address: 0x163290, Func Offset: 0xc0
	// Line 6755, Address: 0x163294, Func Offset: 0xc4
	// Line 6742, Address: 0x163298, Func Offset: 0xc8
	// Line 6750, Address: 0x1632a0, Func Offset: 0xd0
	// Line 6752, Address: 0x1632c8, Func Offset: 0xf8
	// Line 6753, Address: 0x1632cc, Func Offset: 0xfc
	// Line 6759, Address: 0x1632d0, Func Offset: 0x100
	// Line 6753, Address: 0x1632d8, Func Offset: 0x108
	// Line 6759, Address: 0x1632dc, Func Offset: 0x10c
	// Line 6753, Address: 0x1632e0, Func Offset: 0x110
	// Line 6755, Address: 0x1632e4, Func Offset: 0x114
	// Line 6756, Address: 0x1632e8, Func Offset: 0x118
	// Line 6758, Address: 0x1632ec, Func Offset: 0x11c
	// Line 6759, Address: 0x1632f0, Func Offset: 0x120
	// Line 6761, Address: 0x1632f8, Func Offset: 0x128
	// Line 6765, Address: 0x1632fc, Func Offset: 0x12c
	// Func End, Address: 0x163304, Func Offset: 0x134
}

// 
// Start address: 0x163310
unsigned int bhBGColorSet()
{
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 6776, Address: 0x163310, Func Offset: 0
	// Line 6793, Address: 0x163318, Func Offset: 0x8
	// Line 6788, Address: 0x16331c, Func Offset: 0xc
	// Line 6776, Address: 0x163324, Func Offset: 0x14
	// Line 6777, Address: 0x163330, Func Offset: 0x20
	// Line 6778, Address: 0x16333c, Func Offset: 0x2c
	// Line 6779, Address: 0x163348, Func Offset: 0x38
	// Line 6789, Address: 0x163350, Func Offset: 0x40
	// Line 6779, Address: 0x163354, Func Offset: 0x44
	// Line 6780, Address: 0x163358, Func Offset: 0x48
	// Line 6789, Address: 0x163364, Func Offset: 0x54
	// Line 6781, Address: 0x16336c, Func Offset: 0x5c
	// Line 6782, Address: 0x163378, Func Offset: 0x68
	// Line 6789, Address: 0x163384, Func Offset: 0x74
	// Line 6783, Address: 0x16338c, Func Offset: 0x7c
	// Line 6784, Address: 0x163398, Func Offset: 0x88
	// Line 6789, Address: 0x1633a4, Func Offset: 0x94
	// Line 6785, Address: 0x1633a8, Func Offset: 0x98
	// Line 6786, Address: 0x1633b4, Func Offset: 0xa4
	// Line 6788, Address: 0x1633c0, Func Offset: 0xb0
	// Line 6789, Address: 0x1633c4, Func Offset: 0xb4
	// Line 6788, Address: 0x1633c8, Func Offset: 0xb8
	// Line 6789, Address: 0x1633d0, Func Offset: 0xc0
	// Line 6790, Address: 0x1633d8, Func Offset: 0xc8
	// Line 6794, Address: 0x1633e8, Func Offset: 0xd8
	// Func End, Address: 0x1633f0, Func Offset: 0xe0
}

// 
// Start address: 0x1633f0
unsigned int bhMovieTimeCk()
{
	unsigned int ret2;
	unsigned int ret;
	unsigned int v2;
	unsigned int v1;
	// Line 6802, Address: 0x1633f0, Func Offset: 0
	// Line 6805, Address: 0x163400, Func Offset: 0x10
	// Line 6807, Address: 0x163414, Func Offset: 0x24
	// Line 6808, Address: 0x163428, Func Offset: 0x38
	// Line 6809, Address: 0x163434, Func Offset: 0x44
	// Line 6810, Address: 0x163440, Func Offset: 0x50
	// Line 6811, Address: 0x16344c, Func Offset: 0x5c
	// Line 6813, Address: 0x163454, Func Offset: 0x64
	// Line 6814, Address: 0x16345c, Func Offset: 0x6c
	// Line 6816, Address: 0x16346c, Func Offset: 0x7c
	// Line 6818, Address: 0x163474, Func Offset: 0x84
	// Line 6820, Address: 0x16349c, Func Offset: 0xac
	// Line 6821, Address: 0x1634ac, Func Offset: 0xbc
	// Line 6822, Address: 0x1634b0, Func Offset: 0xc0
	// Line 6824, Address: 0x1634b8, Func Offset: 0xc8
	// Line 6825, Address: 0x1634bc, Func Offset: 0xcc
	// Line 6826, Address: 0x1634c0, Func Offset: 0xd0
	// Line 6828, Address: 0x1634c8, Func Offset: 0xd8
	// Line 6829, Address: 0x1634dc, Func Offset: 0xec
	// Line 6830, Address: 0x1634e0, Func Offset: 0xf0
	// Line 6832, Address: 0x1634e8, Func Offset: 0xf8
	// Line 6833, Address: 0x1634ec, Func Offset: 0xfc
	// Line 6834, Address: 0x1634f0, Func Offset: 0x100
	// Line 6836, Address: 0x1634f8, Func Offset: 0x108
	// Line 6837, Address: 0x1634fc, Func Offset: 0x10c
	// Line 6838, Address: 0x163500, Func Offset: 0x110
	// Line 6840, Address: 0x163508, Func Offset: 0x118
	// Line 6841, Address: 0x163518, Func Offset: 0x128
	// Line 6845, Address: 0x16351c, Func Offset: 0x12c
	// Func End, Address: 0x163530, Func Offset: 0x140
}

// 
// Start address: 0x163530
unsigned int bhEffTypeSet()
{
	unsigned int v1;
	unsigned int v0;
	// Line 6857, Address: 0x163530, Func Offset: 0
	// Line 6868, Address: 0x163538, Func Offset: 0x8
	// Line 6870, Address: 0x163540, Func Offset: 0x10
	// Line 6868, Address: 0x163544, Func Offset: 0x14
	// Line 6857, Address: 0x16354c, Func Offset: 0x1c
	// Line 6858, Address: 0x163558, Func Offset: 0x28
	// Line 6859, Address: 0x163564, Func Offset: 0x34
	// Line 6868, Address: 0x163570, Func Offset: 0x40
	// Line 6860, Address: 0x163578, Func Offset: 0x48
	// Line 6861, Address: 0x163584, Func Offset: 0x54
	// Line 6868, Address: 0x163590, Func Offset: 0x60
	// Line 6871, Address: 0x1635b4, Func Offset: 0x84
	// Func End, Address: 0x1635bc, Func Offset: 0x8c
}

// 
// Start address: 0x1635c0
unsigned int bhPlayerPoison2Cr()
{
	// Line 6880, Address: 0x1635c0, Func Offset: 0
	// Line 6881, Address: 0x1635c8, Func Offset: 0x8
	// Line 6882, Address: 0x1635d0, Func Offset: 0x10
	// Line 6881, Address: 0x1635d4, Func Offset: 0x14
	// Line 6880, Address: 0x1635dc, Func Offset: 0x1c
	// Line 6881, Address: 0x1635e8, Func Offset: 0x28
	// Line 6883, Address: 0x1635f0, Func Offset: 0x30
	// Func End, Address: 0x1635f8, Func Offset: 0x38
}

// 
// Start address: 0x163600
unsigned int bhPlyHandChange()
{
	_anon34* owk;
	int v1;
	// Line 6896, Address: 0x163600, Func Offset: 0
	// Line 6904, Address: 0x163608, Func Offset: 0x8
	// Line 6905, Address: 0x16360c, Func Offset: 0xc
	// Line 6898, Address: 0x163610, Func Offset: 0x10
	// Line 6896, Address: 0x163618, Func Offset: 0x18
	// Line 6898, Address: 0x16361c, Func Offset: 0x1c
	// Line 6896, Address: 0x163624, Func Offset: 0x24
	// Line 6898, Address: 0x16362c, Func Offset: 0x2c
	// Line 6900, Address: 0x163644, Func Offset: 0x44
	// Line 6898, Address: 0x163648, Func Offset: 0x48
	// Line 6900, Address: 0x163664, Func Offset: 0x64
	// Line 6902, Address: 0x163668, Func Offset: 0x68
	// Line 6900, Address: 0x163670, Func Offset: 0x70
	// Line 6902, Address: 0x163674, Func Offset: 0x74
	// Line 6900, Address: 0x16367c, Func Offset: 0x7c
	// Line 6902, Address: 0x163684, Func Offset: 0x84
	// Line 6904, Address: 0x16369c, Func Offset: 0x9c
	// Line 6902, Address: 0x1636a0, Func Offset: 0xa0
	// Line 6904, Address: 0x1636bc, Func Offset: 0xbc
	// Line 6905, Address: 0x1636d4, Func Offset: 0xd4
	// Line 6907, Address: 0x1636f0, Func Offset: 0xf0
	// Line 6908, Address: 0x163704, Func Offset: 0x104
	// Line 6909, Address: 0x163710, Func Offset: 0x110
	// Line 6913, Address: 0x163718, Func Offset: 0x118
	// Line 6914, Address: 0x163720, Func Offset: 0x120
	// Line 6923, Address: 0x163730, Func Offset: 0x130
	// Line 6914, Address: 0x163734, Func Offset: 0x134
	// Line 6915, Address: 0x163748, Func Offset: 0x148
	// Line 6914, Address: 0x16374c, Func Offset: 0x14c
	// Line 6915, Address: 0x163754, Func Offset: 0x154
	// Line 6916, Address: 0x16376c, Func Offset: 0x16c
	// Line 6915, Address: 0x163770, Func Offset: 0x170
	// Line 6916, Address: 0x163778, Func Offset: 0x178
	// Line 6917, Address: 0x163790, Func Offset: 0x190
	// Line 6916, Address: 0x163794, Func Offset: 0x194
	// Line 6917, Address: 0x16379c, Func Offset: 0x19c
	// Line 6918, Address: 0x1637b4, Func Offset: 0x1b4
	// Line 6917, Address: 0x1637b8, Func Offset: 0x1b8
	// Line 6918, Address: 0x1637c0, Func Offset: 0x1c0
	// Line 6919, Address: 0x1637d4, Func Offset: 0x1d4
	// Line 6918, Address: 0x1637d8, Func Offset: 0x1d8
	// Line 6919, Address: 0x1637e0, Func Offset: 0x1e0
	// Line 6923, Address: 0x1637f4, Func Offset: 0x1f4
	// Line 6919, Address: 0x1637f8, Func Offset: 0x1f8
	// Line 6923, Address: 0x163800, Func Offset: 0x200
	// Line 6924, Address: 0x163814, Func Offset: 0x214
	// Line 6925, Address: 0x16381c, Func Offset: 0x21c
	// Line 6926, Address: 0x163820, Func Offset: 0x220
	// Line 6929, Address: 0x163828, Func Offset: 0x228
	// Line 6926, Address: 0x16382c, Func Offset: 0x22c
	// Line 6927, Address: 0x163830, Func Offset: 0x230
	// Line 6926, Address: 0x163834, Func Offset: 0x234
	// Line 6927, Address: 0x16383c, Func Offset: 0x23c
	// Line 6930, Address: 0x163844, Func Offset: 0x244
	// Line 6929, Address: 0x163848, Func Offset: 0x248
	// Line 6930, Address: 0x163854, Func Offset: 0x254
	// Line 6935, Address: 0x16385c, Func Offset: 0x25c
	// Line 6932, Address: 0x163860, Func Offset: 0x260
	// Line 6935, Address: 0x16386c, Func Offset: 0x26c
	// Line 6937, Address: 0x16387c, Func Offset: 0x27c
	// Line 6938, Address: 0x163884, Func Offset: 0x284
	// Line 6940, Address: 0x163890, Func Offset: 0x290
	// Line 6942, Address: 0x163894, Func Offset: 0x294
	// Line 6938, Address: 0x163898, Func Offset: 0x298
	// Line 6947, Address: 0x1638a4, Func Offset: 0x2a4
	// Line 6938, Address: 0x1638a8, Func Offset: 0x2a8
	// Line 6939, Address: 0x1638b0, Func Offset: 0x2b0
	// Line 6938, Address: 0x1638b4, Func Offset: 0x2b4
	// Line 6939, Address: 0x1638bc, Func Offset: 0x2bc
	// Line 6940, Address: 0x1638d4, Func Offset: 0x2d4
	// Line 6939, Address: 0x1638d8, Func Offset: 0x2d8
	// Line 6940, Address: 0x1638e0, Func Offset: 0x2e0
	// Line 6941, Address: 0x1638f4, Func Offset: 0x2f4
	// Line 6940, Address: 0x1638f8, Func Offset: 0x2f8
	// Line 6941, Address: 0x163900, Func Offset: 0x300
	// Line 6942, Address: 0x163914, Func Offset: 0x314
	// Line 6941, Address: 0x163918, Func Offset: 0x318
	// Line 6942, Address: 0x163920, Func Offset: 0x320
	// Line 6943, Address: 0x163938, Func Offset: 0x338
	// Line 6942, Address: 0x16393c, Func Offset: 0x33c
	// Line 6943, Address: 0x163944, Func Offset: 0x344
	// Line 6947, Address: 0x16395c, Func Offset: 0x35c
	// Line 6943, Address: 0x163960, Func Offset: 0x360
	// Line 6947, Address: 0x163968, Func Offset: 0x368
	// Line 6948, Address: 0x163974, Func Offset: 0x374
	// Line 6949, Address: 0x16397c, Func Offset: 0x37c
	// Line 6950, Address: 0x163988, Func Offset: 0x388
	// Line 6951, Address: 0x163994, Func Offset: 0x394
	// Line 6950, Address: 0x163998, Func Offset: 0x398
	// Line 6951, Address: 0x1639a0, Func Offset: 0x3a0
	// Line 6954, Address: 0x1639a8, Func Offset: 0x3a8
	// Line 6953, Address: 0x1639ac, Func Offset: 0x3ac
	// Line 6954, Address: 0x1639b8, Func Offset: 0x3b8
	// Line 6959, Address: 0x1639c0, Func Offset: 0x3c0
	// Line 6956, Address: 0x1639c4, Func Offset: 0x3c4
	// Line 6959, Address: 0x1639d0, Func Offset: 0x3d0
	// Line 6968, Address: 0x1639e4, Func Offset: 0x3e4
	// Line 6969, Address: 0x1639e8, Func Offset: 0x3e8
	// Func End, Address: 0x1639f0, Func Offset: 0x3f0
}

// 
// Start address: 0x1639f0
unsigned int bhHEffectSet2()
{
	_anon44* eft;
	int v4;
	int v3;
	int v2;
	// Line 6979, Address: 0x1639f0, Func Offset: 0
	// Line 6986, Address: 0x163a04, Func Offset: 0x14
	// Line 6987, Address: 0x163a0c, Func Offset: 0x1c
	// Line 6986, Address: 0x163a14, Func Offset: 0x24
	// Line 6987, Address: 0x163a20, Func Offset: 0x30
	// Line 6988, Address: 0x163a2c, Func Offset: 0x3c
	// Line 6989, Address: 0x163a38, Func Offset: 0x48
	// Line 6990, Address: 0x163a44, Func Offset: 0x54
	// Line 6991, Address: 0x163a50, Func Offset: 0x60
	// Line 6990, Address: 0x163a54, Func Offset: 0x64
	// Line 6991, Address: 0x163a58, Func Offset: 0x68
	// Line 6992, Address: 0x163a68, Func Offset: 0x78
	// Line 6993, Address: 0x163a74, Func Offset: 0x84
	// Line 6996, Address: 0x163a80, Func Offset: 0x90
	// Line 6997, Address: 0x163a8c, Func Offset: 0x9c
	// Line 6998, Address: 0x163ae8, Func Offset: 0xf8
	// Line 6999, Address: 0x163af0, Func Offset: 0x100
	// Line 7001, Address: 0x163b40, Func Offset: 0x150
	// Line 7004, Address: 0x163b48, Func Offset: 0x158
	// Line 7001, Address: 0x163b4c, Func Offset: 0x15c
	// Line 7004, Address: 0x163b54, Func Offset: 0x164
	// Line 7005, Address: 0x163b5c, Func Offset: 0x16c
	// Line 7006, Address: 0x163bb8, Func Offset: 0x1c8
	// Line 7007, Address: 0x163bc0, Func Offset: 0x1d0
	// Line 7009, Address: 0x163c10, Func Offset: 0x220
	// Line 7012, Address: 0x163c18, Func Offset: 0x228
	// Line 7009, Address: 0x163c1c, Func Offset: 0x22c
	// Line 7012, Address: 0x163c24, Func Offset: 0x234
	// Line 7013, Address: 0x163c2c, Func Offset: 0x23c
	// Line 7014, Address: 0x163c88, Func Offset: 0x298
	// Line 7015, Address: 0x163c90, Func Offset: 0x2a0
	// Line 7017, Address: 0x163ce0, Func Offset: 0x2f0
	// Line 7019, Address: 0x163cf4, Func Offset: 0x304
	// Line 7020, Address: 0x163d00, Func Offset: 0x310
	// Line 7021, Address: 0x163d0c, Func Offset: 0x31c
	// Line 7023, Address: 0x163d14, Func Offset: 0x324
	// Line 7024, Address: 0x163d20, Func Offset: 0x330
	// Line 7026, Address: 0x163d24, Func Offset: 0x334
	// Line 7028, Address: 0x163d44, Func Offset: 0x354
	// Line 7030, Address: 0x163d4c, Func Offset: 0x35c
	// Line 7028, Address: 0x163d50, Func Offset: 0x360
	// Line 7029, Address: 0x163d5c, Func Offset: 0x36c
	// Line 7030, Address: 0x163d64, Func Offset: 0x374
	// Line 7031, Address: 0x163d6c, Func Offset: 0x37c
	// Line 7033, Address: 0x163d70, Func Offset: 0x380
	// Line 7035, Address: 0x163d90, Func Offset: 0x3a0
	// Line 7036, Address: 0x163da4, Func Offset: 0x3b4
	// Line 7037, Address: 0x163db0, Func Offset: 0x3c0
	// Line 7040, Address: 0x163dbc, Func Offset: 0x3cc
	// Line 7041, Address: 0x163dc8, Func Offset: 0x3d8
	// Line 7042, Address: 0x163e24, Func Offset: 0x434
	// Line 7043, Address: 0x163e2c, Func Offset: 0x43c
	// Line 7045, Address: 0x163e7c, Func Offset: 0x48c
	// Line 7048, Address: 0x163e84, Func Offset: 0x494
	// Line 7045, Address: 0x163e88, Func Offset: 0x498
	// Line 7048, Address: 0x163e90, Func Offset: 0x4a0
	// Line 7049, Address: 0x163e98, Func Offset: 0x4a8
	// Line 7050, Address: 0x163ef4, Func Offset: 0x504
	// Line 7051, Address: 0x163efc, Func Offset: 0x50c
	// Line 7053, Address: 0x163f4c, Func Offset: 0x55c
	// Line 7056, Address: 0x163f54, Func Offset: 0x564
	// Line 7053, Address: 0x163f58, Func Offset: 0x568
	// Line 7056, Address: 0x163f60, Func Offset: 0x570
	// Line 7057, Address: 0x163f68, Func Offset: 0x578
	// Line 7058, Address: 0x163fc4, Func Offset: 0x5d4
	// Line 7059, Address: 0x163fcc, Func Offset: 0x5dc
	// Line 7061, Address: 0x16401c, Func Offset: 0x62c
	// Line 7065, Address: 0x164024, Func Offset: 0x634
	// Line 7069, Address: 0x164028, Func Offset: 0x638
	// Line 7061, Address: 0x164034, Func Offset: 0x644
	// Line 7062, Address: 0x164040, Func Offset: 0x650
	// Line 7069, Address: 0x164048, Func Offset: 0x658
	// Line 7062, Address: 0x16404c, Func Offset: 0x65c
	// Line 7063, Address: 0x164050, Func Offset: 0x660
	// Line 7062, Address: 0x164054, Func Offset: 0x664
	// Line 7063, Address: 0x164058, Func Offset: 0x668
	// Line 7065, Address: 0x164068, Func Offset: 0x678
	// Line 7066, Address: 0x16406c, Func Offset: 0x67c
	// Line 7069, Address: 0x164070, Func Offset: 0x680
	// Line 7072, Address: 0x164078, Func Offset: 0x688
	// Line 7071, Address: 0x164088, Func Offset: 0x698
	// Line 7072, Address: 0x16408c, Func Offset: 0x69c
	// Func End, Address: 0x164094, Func Offset: 0x6a4
}

// 
// Start address: 0x1640a0
unsigned int bhObjDposCk()
{
	npobj* objP;
	BH_PWORK* e_ep;
	int eay2;
	int eay;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 7080, Address: 0x1640a0, Func Offset: 0
	// Line 7087, Address: 0x1640b4, Func Offset: 0x14
	// Line 7088, Address: 0x1640c8, Func Offset: 0x28
	// Line 7089, Address: 0x1640d4, Func Offset: 0x34
	// Line 7090, Address: 0x1640e0, Func Offset: 0x40
	// Line 7091, Address: 0x1640ec, Func Offset: 0x4c
	// Line 7092, Address: 0x1640f8, Func Offset: 0x58
	// Line 7101, Address: 0x164104, Func Offset: 0x64
	// Line 7102, Address: 0x164110, Func Offset: 0x70
	// Line 7103, Address: 0x16411c, Func Offset: 0x7c
	// Line 7104, Address: 0x164128, Func Offset: 0x88
	// Line 7105, Address: 0x164134, Func Offset: 0x94
	// Line 7108, Address: 0x16413c, Func Offset: 0x9c
	// Line 7109, Address: 0x164144, Func Offset: 0xa4
	// Line 7110, Address: 0x164150, Func Offset: 0xb0
	// Line 7111, Address: 0x164158, Func Offset: 0xb8
	// Line 7114, Address: 0x16415c, Func Offset: 0xbc
	// Line 7115, Address: 0x164178, Func Offset: 0xd8
	// Line 7114, Address: 0x164184, Func Offset: 0xe4
	// Line 7115, Address: 0x164188, Func Offset: 0xe8
	// Line 7117, Address: 0x16419c, Func Offset: 0xfc
	// Line 7118, Address: 0x1641c8, Func Offset: 0x128
	// Line 7119, Address: 0x1641d0, Func Offset: 0x130
	// Line 7120, Address: 0x1641dc, Func Offset: 0x13c
	// Line 7121, Address: 0x1641e8, Func Offset: 0x148
	// Line 7122, Address: 0x1641fc, Func Offset: 0x15c
	// Line 7123, Address: 0x16420c, Func Offset: 0x16c
	// Line 7124, Address: 0x164214, Func Offset: 0x174
	// Line 7126, Address: 0x16421c, Func Offset: 0x17c
	// Line 7128, Address: 0x164228, Func Offset: 0x188
	// Line 7129, Address: 0x164234, Func Offset: 0x194
	// Line 7130, Address: 0x164248, Func Offset: 0x1a8
	// Line 7131, Address: 0x164258, Func Offset: 0x1b8
	// Line 7132, Address: 0x164260, Func Offset: 0x1c0
	// Line 7134, Address: 0x164268, Func Offset: 0x1c8
	// Line 7139, Address: 0x164274, Func Offset: 0x1d4
	// Line 7140, Address: 0x164280, Func Offset: 0x1e0
	// Line 7142, Address: 0x164284, Func Offset: 0x1e4
	// Line 7143, Address: 0x1642a0, Func Offset: 0x200
	// Line 7142, Address: 0x1642ac, Func Offset: 0x20c
	// Line 7143, Address: 0x1642b0, Func Offset: 0x210
	// Line 7142, Address: 0x1642b8, Func Offset: 0x218
	// Line 7143, Address: 0x1642bc, Func Offset: 0x21c
	// Line 7148, Address: 0x1642c8, Func Offset: 0x228
	// Line 7143, Address: 0x1642d0, Func Offset: 0x230
	// Line 7148, Address: 0x1642d4, Func Offset: 0x234
	// Line 7149, Address: 0x1642f4, Func Offset: 0x254
	// Line 7148, Address: 0x1642fc, Func Offset: 0x25c
	// Line 7149, Address: 0x164318, Func Offset: 0x278
	// Line 7151, Address: 0x164328, Func Offset: 0x288
	// Line 7152, Address: 0x164330, Func Offset: 0x290
	// Line 7153, Address: 0x16433c, Func Offset: 0x29c
	// Line 7154, Address: 0x164348, Func Offset: 0x2a8
	// Line 7155, Address: 0x164350, Func Offset: 0x2b0
	// Line 7156, Address: 0x164360, Func Offset: 0x2c0
	// Line 7157, Address: 0x164364, Func Offset: 0x2c4
	// Line 7159, Address: 0x16436c, Func Offset: 0x2cc
	// Line 7161, Address: 0x164378, Func Offset: 0x2d8
	// Line 7162, Address: 0x164384, Func Offset: 0x2e4
	// Line 7163, Address: 0x16438c, Func Offset: 0x2ec
	// Line 7164, Address: 0x16439c, Func Offset: 0x2fc
	// Line 7165, Address: 0x1643a0, Func Offset: 0x300
	// Line 7167, Address: 0x1643a8, Func Offset: 0x308
	// Line 7192, Address: 0x1643b4, Func Offset: 0x314
	// Line 7193, Address: 0x1643b8, Func Offset: 0x318
	// Func End, Address: 0x1643d0, Func Offset: 0x330
}

// 
// Start address: 0x1643d0
unsigned int bhItemGetGet()
{
	int v2;
	int v1;
	int v0;
	// Line 7205, Address: 0x1643d0, Func Offset: 0
	// Line 7216, Address: 0x1643d8, Func Offset: 0x8
	// Line 7215, Address: 0x1643dc, Func Offset: 0xc
	// Line 7205, Address: 0x1643e4, Func Offset: 0x14
	// Line 7206, Address: 0x1643f0, Func Offset: 0x20
	// Line 7207, Address: 0x1643fc, Func Offset: 0x2c
	// Line 7208, Address: 0x164408, Func Offset: 0x38
	// Line 7215, Address: 0x164410, Func Offset: 0x40
	// Line 7208, Address: 0x164418, Func Offset: 0x48
	// Line 7209, Address: 0x16441c, Func Offset: 0x4c
	// Line 7210, Address: 0x164428, Func Offset: 0x58
	// Line 7215, Address: 0x164430, Func Offset: 0x60
	// Line 7210, Address: 0x164434, Func Offset: 0x64
	// Line 7211, Address: 0x164438, Func Offset: 0x68
	// Line 7216, Address: 0x164444, Func Offset: 0x74
	// Line 7217, Address: 0x16444c, Func Offset: 0x7c
	// Line 7219, Address: 0x164464, Func Offset: 0x94
	// Line 7221, Address: 0x164480, Func Offset: 0xb0
	// Line 7222, Address: 0x164488, Func Offset: 0xb8
	// Line 7221, Address: 0x16448c, Func Offset: 0xbc
	// Line 7222, Address: 0x164490, Func Offset: 0xc0
	// Line 7223, Address: 0x164498, Func Offset: 0xc8
	// Line 7225, Address: 0x1644a8, Func Offset: 0xd8
	// Line 7227, Address: 0x1644b0, Func Offset: 0xe0
	// Line 7229, Address: 0x1644bc, Func Offset: 0xec
	// Line 7227, Address: 0x1644c0, Func Offset: 0xf0
	// Line 7228, Address: 0x1644c8, Func Offset: 0xf8
	// Line 7227, Address: 0x1644cc, Func Offset: 0xfc
	// Line 7228, Address: 0x1644d4, Func Offset: 0x104
	// Line 7229, Address: 0x1644dc, Func Offset: 0x10c
	// Line 7230, Address: 0x1644e4, Func Offset: 0x114
	// Line 7234, Address: 0x1644f8, Func Offset: 0x128
	// Line 7235, Address: 0x1644fc, Func Offset: 0x12c
	// Func End, Address: 0x164504, Func Offset: 0x134
}

// 
// Start address: 0x164510
unsigned int bhEtcAtariEnePosSet()
{
	unsigned int cnt2;
	unsigned int cnt;
	float sw2;
	float sw1;
	_anon3* e_posp;
	BH_PWORK* epw;
	_anon6* e_etcp;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 7244, Address: 0x164510, Func Offset: 0
	// Line 7254, Address: 0x16453c, Func Offset: 0x2c
	// Line 7269, Address: 0x164544, Func Offset: 0x34
	// Line 7254, Address: 0x164554, Func Offset: 0x44
	// Line 7255, Address: 0x164560, Func Offset: 0x50
	// Line 7256, Address: 0x16456c, Func Offset: 0x5c
	// Line 7257, Address: 0x164578, Func Offset: 0x68
	// Line 7269, Address: 0x164580, Func Offset: 0x70
	// Line 7257, Address: 0x16458c, Func Offset: 0x7c
	// Line 7258, Address: 0x164590, Func Offset: 0x80
	// Line 7259, Address: 0x16459c, Func Offset: 0x8c
	// Line 7272, Address: 0x1645a4, Func Offset: 0x94
	// Line 7259, Address: 0x1645b0, Func Offset: 0xa0
	// Line 7260, Address: 0x1645b4, Func Offset: 0xa4
	// Line 7261, Address: 0x1645c0, Func Offset: 0xb0
	// Line 7275, Address: 0x1645c8, Func Offset: 0xb8
	// Line 7261, Address: 0x1645cc, Func Offset: 0xbc
	// Line 7262, Address: 0x1645d0, Func Offset: 0xc0
	// Line 7263, Address: 0x1645dc, Func Offset: 0xcc
	// Line 7264, Address: 0x1645e8, Func Offset: 0xd8
	// Line 7265, Address: 0x1645f4, Func Offset: 0xe4
	// Line 7266, Address: 0x164600, Func Offset: 0xf0
	// Line 7269, Address: 0x16460c, Func Offset: 0xfc
	// Line 7271, Address: 0x164610, Func Offset: 0x100
	// Line 7274, Address: 0x164614, Func Offset: 0x104
	// Line 7269, Address: 0x164618, Func Offset: 0x108
	// Line 7277, Address: 0x164620, Func Offset: 0x110
	// Line 7272, Address: 0x16462c, Func Offset: 0x11c
	// Line 7269, Address: 0x164630, Func Offset: 0x120
	// Line 7277, Address: 0x164648, Func Offset: 0x138
	// Line 7275, Address: 0x16464c, Func Offset: 0x13c
	// Line 7277, Address: 0x164650, Func Offset: 0x140
	// Line 7278, Address: 0x164664, Func Offset: 0x154
	// Line 7277, Address: 0x164668, Func Offset: 0x158
	// Line 7278, Address: 0x16466c, Func Offset: 0x15c
	// Line 7279, Address: 0x164674, Func Offset: 0x164
	// Line 7280, Address: 0x16468c, Func Offset: 0x17c
	// Line 7281, Address: 0x16469c, Func Offset: 0x18c
	// Line 7282, Address: 0x1646a0, Func Offset: 0x190
	// Line 7283, Address: 0x1646a4, Func Offset: 0x194
	// Line 7285, Address: 0x1646a8, Func Offset: 0x198
	// Line 7289, Address: 0x1646b8, Func Offset: 0x1a8
	// Line 7286, Address: 0x1646c4, Func Offset: 0x1b4
	// Line 7287, Address: 0x1646cc, Func Offset: 0x1bc
	// Line 7289, Address: 0x1646d0, Func Offset: 0x1c0
	// Line 7295, Address: 0x1646d4, Func Offset: 0x1c4
	// Line 7286, Address: 0x1646d8, Func Offset: 0x1c8
	// Line 7293, Address: 0x1646dc, Func Offset: 0x1cc
	// Line 7287, Address: 0x1646e0, Func Offset: 0x1d0
	// Line 7289, Address: 0x1646e4, Func Offset: 0x1d4
	// Line 7290, Address: 0x1646f0, Func Offset: 0x1e0
	// Line 7291, Address: 0x1646f8, Func Offset: 0x1e8
	// Line 7293, Address: 0x16470c, Func Offset: 0x1fc
	// Line 7296, Address: 0x164718, Func Offset: 0x208
	// Func End, Address: 0x164748, Func Offset: 0x238
}

// 
// Start address: 0x164750
unsigned int bhEtcAtariEvtPosSet()
{
	_anon3* e_posp;
	_anon6* e_etcp;
	BH_PWORK* epw;
	int v3;
	int v1;
	int v0;
	// Line 7313, Address: 0x164750, Func Offset: 0
	// Line 7329, Address: 0x164758, Func Offset: 0x8
	// Line 7339, Address: 0x164760, Func Offset: 0x10
	// Line 7321, Address: 0x164764, Func Offset: 0x14
	// Line 7313, Address: 0x16476c, Func Offset: 0x1c
	// Line 7327, Address: 0x164770, Func Offset: 0x20
	// Line 7313, Address: 0x164778, Func Offset: 0x28
	// Line 7314, Address: 0x164780, Func Offset: 0x30
	// Line 7315, Address: 0x16478c, Func Offset: 0x3c
	// Line 7316, Address: 0x164798, Func Offset: 0x48
	// Line 7327, Address: 0x1647a0, Func Offset: 0x50
	// Line 7316, Address: 0x1647a4, Func Offset: 0x54
	// Line 7317, Address: 0x1647a8, Func Offset: 0x58
	// Line 7318, Address: 0x1647b4, Func Offset: 0x64
	// Line 7322, Address: 0x1647bc, Func Offset: 0x6c
	// Line 7318, Address: 0x1647c8, Func Offset: 0x78
	// Line 7319, Address: 0x1647cc, Func Offset: 0x7c
	// Line 7321, Address: 0x1647d8, Func Offset: 0x88
	// Line 7327, Address: 0x1647dc, Func Offset: 0x8c
	// Line 7333, Address: 0x1647e0, Func Offset: 0x90
	// Line 7322, Address: 0x1647e4, Func Offset: 0x94
	// Line 7326, Address: 0x1647e8, Func Offset: 0x98
	// Line 7329, Address: 0x1647ec, Func Offset: 0x9c
	// Line 7327, Address: 0x1647f0, Func Offset: 0xa0
	// Line 7333, Address: 0x1647f4, Func Offset: 0xa4
	// Line 7327, Address: 0x1647fc, Func Offset: 0xac
	// Line 7329, Address: 0x164800, Func Offset: 0xb0
	// Line 7333, Address: 0x164808, Func Offset: 0xb8
	// Line 7329, Address: 0x164814, Func Offset: 0xc4
	// Line 7330, Address: 0x16481c, Func Offset: 0xcc
	// Line 7331, Address: 0x164824, Func Offset: 0xd4
	// Line 7333, Address: 0x164838, Func Offset: 0xe8
	// Line 7335, Address: 0x16483c, Func Offset: 0xec
	// Line 7333, Address: 0x164840, Func Offset: 0xf0
	// Line 7335, Address: 0x164850, Func Offset: 0x100
	// Line 7336, Address: 0x164854, Func Offset: 0x104
	// Line 7337, Address: 0x16485c, Func Offset: 0x10c
	// Line 7340, Address: 0x164860, Func Offset: 0x110
	// Func End, Address: 0x164868, Func Offset: 0x118
}

// 
// Start address: 0x164870
unsigned int bhRoomSoundCase()
{
	int v0;
	// Line 7348, Address: 0x164870, Func Offset: 0
	// Line 7351, Address: 0x164878, Func Offset: 0x8
	// Line 7352, Address: 0x16488c, Func Offset: 0x1c
	// Line 7353, Address: 0x164898, Func Offset: 0x28
	// Line 7355, Address: 0x1648a0, Func Offset: 0x30
	// Line 7358, Address: 0x1648a8, Func Offset: 0x38
	// Line 7357, Address: 0x1648ac, Func Offset: 0x3c
	// Line 7358, Address: 0x1648b0, Func Offset: 0x40
	// Func End, Address: 0x1648b8, Func Offset: 0x48
}

// 
// Start address: 0x1648c0
unsigned int bhItemPlToSBox()
{
	int v0;
	unsigned int cnt2;
	unsigned int cnt;
	// Line 7371, Address: 0x1648c0, Func Offset: 0
	// Line 7376, Address: 0x1648c8, Func Offset: 0x8
	// Line 7371, Address: 0x1648d0, Func Offset: 0x10
	// Line 7372, Address: 0x1648dc, Func Offset: 0x1c
	// Line 7373, Address: 0x1648e8, Func Offset: 0x28
	// Line 7377, Address: 0x1648f4, Func Offset: 0x34
	// Line 7378, Address: 0x1648fc, Func Offset: 0x3c
	// Line 7377, Address: 0x164904, Func Offset: 0x44
	// Line 7378, Address: 0x16490c, Func Offset: 0x4c
	// Line 7380, Address: 0x164914, Func Offset: 0x54
	// Line 7381, Address: 0x164930, Func Offset: 0x70
	// Line 7383, Address: 0x164938, Func Offset: 0x78
	// Line 7381, Address: 0x164940, Func Offset: 0x80
	// Line 7382, Address: 0x164948, Func Offset: 0x88
	// Line 7381, Address: 0x16494c, Func Offset: 0x8c
	// Line 7382, Address: 0x164954, Func Offset: 0x94
	// Line 7383, Address: 0x164958, Func Offset: 0x98
	// Line 7382, Address: 0x16495c, Func Offset: 0x9c
	// Line 7383, Address: 0x164968, Func Offset: 0xa8
	// Line 7386, Address: 0x164974, Func Offset: 0xb4
	// Func End, Address: 0x16497c, Func Offset: 0xbc
}

// 
// Start address: 0x164980
unsigned int bhItemSBoxToIBox()
{
	unsigned int cnt2;
	unsigned int cnt;
	// Line 7398, Address: 0x164980, Func Offset: 0
	// Line 7401, Address: 0x164988, Func Offset: 0x8
	// Line 7398, Address: 0x164994, Func Offset: 0x14
	// Line 7401, Address: 0x1649a0, Func Offset: 0x20
	// Line 7403, Address: 0x1649a8, Func Offset: 0x28
	// Line 7404, Address: 0x1649c0, Func Offset: 0x40
	// Line 7405, Address: 0x1649d4, Func Offset: 0x54
	// Line 7406, Address: 0x1649d8, Func Offset: 0x58
	// Line 7407, Address: 0x1649e0, Func Offset: 0x60
	// Line 7406, Address: 0x1649e4, Func Offset: 0x64
	// Line 7407, Address: 0x1649f0, Func Offset: 0x70
	// Line 7409, Address: 0x1649f4, Func Offset: 0x74
	// Line 7411, Address: 0x164a10, Func Offset: 0x90
	// Line 7412, Address: 0x164a14, Func Offset: 0x94
	// Func End, Address: 0x164a1c, Func Offset: 0x9c
}

// 
// Start address: 0x164a20
unsigned int bhGrdPosSet()
{
	_anon6* e_walp;
	unsigned int v1;
	// Line 7425, Address: 0x164a20, Func Offset: 0
	// Line 7432, Address: 0x164a28, Func Offset: 0x8
	// Line 7425, Address: 0x164a30, Func Offset: 0x10
	// Line 7432, Address: 0x164a3c, Func Offset: 0x1c
	// Line 7433, Address: 0x164a40, Func Offset: 0x20
	// Line 7435, Address: 0x164a4c, Func Offset: 0x2c
	// Line 7433, Address: 0x164a58, Func Offset: 0x38
	// Line 7436, Address: 0x164a60, Func Offset: 0x40
	// Line 7433, Address: 0x164a68, Func Offset: 0x48
	// Line 7436, Address: 0x164a70, Func Offset: 0x50
	// Line 7437, Address: 0x164a74, Func Offset: 0x54
	// Line 7440, Address: 0x164a80, Func Offset: 0x60
	// Line 7441, Address: 0x164a8c, Func Offset: 0x6c
	// Line 7442, Address: 0x164ae8, Func Offset: 0xc8
	// Line 7443, Address: 0x164af0, Func Offset: 0xd0
	// Line 7445, Address: 0x164b40, Func Offset: 0x120
	// Line 7448, Address: 0x164b48, Func Offset: 0x128
	// Line 7445, Address: 0x164b4c, Func Offset: 0x12c
	// Line 7448, Address: 0x164b54, Func Offset: 0x134
	// Line 7449, Address: 0x164b5c, Func Offset: 0x13c
	// Line 7450, Address: 0x164bb8, Func Offset: 0x198
	// Line 7451, Address: 0x164bc0, Func Offset: 0x1a0
	// Line 7453, Address: 0x164c10, Func Offset: 0x1f0
	// Line 7456, Address: 0x164c18, Func Offset: 0x1f8
	// Line 7453, Address: 0x164c1c, Func Offset: 0x1fc
	// Line 7456, Address: 0x164c24, Func Offset: 0x204
	// Line 7457, Address: 0x164c2c, Func Offset: 0x20c
	// Line 7458, Address: 0x164c88, Func Offset: 0x268
	// Line 7459, Address: 0x164c90, Func Offset: 0x270
	// Line 7461, Address: 0x164ce0, Func Offset: 0x2c0
	// Line 7464, Address: 0x164ce8, Func Offset: 0x2c8
	// Line 7461, Address: 0x164cec, Func Offset: 0x2cc
	// Line 7465, Address: 0x164cf4, Func Offset: 0x2d4
	// Func End, Address: 0x164cfc, Func Offset: 0x2dc
}

// 
// Start address: 0x164d00
unsigned int bhGrdPosMoveCSet()
{
	int v1;
	int v0;
	// Line 7478, Address: 0x164d00, Func Offset: 0
	// Line 7479, Address: 0x164d14, Func Offset: 0x14
	// Line 7480, Address: 0x164d20, Func Offset: 0x20
	// Line 7482, Address: 0x164d2c, Func Offset: 0x2c
	// Line 7483, Address: 0x164d38, Func Offset: 0x38
	// Line 7484, Address: 0x164d98, Func Offset: 0x98
	// Line 7485, Address: 0x164da0, Func Offset: 0xa0
	// Line 7487, Address: 0x164df4, Func Offset: 0xf4
	// Line 7489, Address: 0x164dfc, Func Offset: 0xfc
	// Line 7487, Address: 0x164e00, Func Offset: 0x100
	// Line 7489, Address: 0x164e08, Func Offset: 0x108
	// Line 7490, Address: 0x164e10, Func Offset: 0x110
	// Line 7491, Address: 0x164e70, Func Offset: 0x170
	// Line 7492, Address: 0x164e78, Func Offset: 0x178
	// Line 7494, Address: 0x164ecc, Func Offset: 0x1cc
	// Line 7496, Address: 0x164ed4, Func Offset: 0x1d4
	// Line 7494, Address: 0x164ed8, Func Offset: 0x1d8
	// Line 7496, Address: 0x164ee0, Func Offset: 0x1e0
	// Line 7497, Address: 0x164ee8, Func Offset: 0x1e8
	// Line 7498, Address: 0x164f48, Func Offset: 0x248
	// Line 7499, Address: 0x164f50, Func Offset: 0x250
	// Line 7501, Address: 0x164fa4, Func Offset: 0x2a4
	// Line 7503, Address: 0x164fb8, Func Offset: 0x2b8
	// Line 7504, Address: 0x164fcc, Func Offset: 0x2cc
	// Line 7505, Address: 0x164fd8, Func Offset: 0x2d8
	// Line 7507, Address: 0x164fe4, Func Offset: 0x2e4
	// Line 7508, Address: 0x164ff0, Func Offset: 0x2f0
	// Line 7509, Address: 0x165050, Func Offset: 0x350
	// Line 7510, Address: 0x165058, Func Offset: 0x358
	// Line 7512, Address: 0x1650ac, Func Offset: 0x3ac
	// Line 7514, Address: 0x1650b4, Func Offset: 0x3b4
	// Line 7512, Address: 0x1650b8, Func Offset: 0x3b8
	// Line 7514, Address: 0x1650c0, Func Offset: 0x3c0
	// Line 7515, Address: 0x1650c8, Func Offset: 0x3c8
	// Line 7516, Address: 0x165128, Func Offset: 0x428
	// Line 7517, Address: 0x165130, Func Offset: 0x430
	// Line 7519, Address: 0x165184, Func Offset: 0x484
	// Line 7521, Address: 0x16518c, Func Offset: 0x48c
	// Line 7519, Address: 0x165190, Func Offset: 0x490
	// Line 7521, Address: 0x165198, Func Offset: 0x498
	// Line 7522, Address: 0x1651a0, Func Offset: 0x4a0
	// Line 7523, Address: 0x165200, Func Offset: 0x500
	// Line 7524, Address: 0x165208, Func Offset: 0x508
	// Line 7526, Address: 0x16525c, Func Offset: 0x55c
	// Line 7528, Address: 0x165264, Func Offset: 0x564
	// Line 7526, Address: 0x165268, Func Offset: 0x568
	// Line 7529, Address: 0x165270, Func Offset: 0x570
	// Func End, Address: 0x165278, Func Offset: 0x578
}

// 
// Start address: 0x165280
unsigned int bhGrdPosMoveStart()
{
	float ans[3];
	float ips_w[3][4];
	_anon6* e_walp;
	// Line 7537, Address: 0x165280, Func Offset: 0
	// Line 7546, Address: 0x16528c, Func Offset: 0xc
	// Line 7575, Address: 0x165294, Func Offset: 0x14
	// Line 7553, Address: 0x1652a4, Func Offset: 0x24
	// Line 7546, Address: 0x1652ac, Func Offset: 0x2c
	// Line 7575, Address: 0x1652b0, Func Offset: 0x30
	// Line 7558, Address: 0x1652b4, Func Offset: 0x34
	// Line 7546, Address: 0x1652bc, Func Offset: 0x3c
	// Line 7554, Address: 0x1652c4, Func Offset: 0x44
	// Line 7553, Address: 0x1652cc, Func Offset: 0x4c
	// Line 7555, Address: 0x1652d0, Func Offset: 0x50
	// Line 7554, Address: 0x1652d4, Func Offset: 0x54
	// Line 7555, Address: 0x1652d8, Func Offset: 0x58
	// Line 7558, Address: 0x1652e0, Func Offset: 0x60
	// Line 7554, Address: 0x1652e4, Func Offset: 0x64
	// Line 7558, Address: 0x1652f4, Func Offset: 0x74
	// Line 7559, Address: 0x1652f8, Func Offset: 0x78
	// Line 7560, Address: 0x165300, Func Offset: 0x80
	// Line 7561, Address: 0x165308, Func Offset: 0x88
	// Line 7563, Address: 0x165310, Func Offset: 0x90
	// Line 7564, Address: 0x165318, Func Offset: 0x98
	// Line 7565, Address: 0x165320, Func Offset: 0xa0
	// Line 7566, Address: 0x165328, Func Offset: 0xa8
	// Line 7568, Address: 0x165330, Func Offset: 0xb0
	// Line 7569, Address: 0x165338, Func Offset: 0xb8
	// Line 7570, Address: 0x165340, Func Offset: 0xc0
	// Line 7571, Address: 0x165348, Func Offset: 0xc8
	// Line 7575, Address: 0x165350, Func Offset: 0xd0
	// Line 7577, Address: 0x165370, Func Offset: 0xf0
	// Line 7581, Address: 0x165374, Func Offset: 0xf4
	// Line 7577, Address: 0x165378, Func Offset: 0xf8
	// Line 7578, Address: 0x16537c, Func Offset: 0xfc
	// Line 7579, Address: 0x165384, Func Offset: 0x104
	// Line 7582, Address: 0x16538c, Func Offset: 0x10c
	// Func End, Address: 0x16539c, Func Offset: 0x11c
}

// 
// Start address: 0x1653a0
unsigned int bhEvtKill()
{
	unsigned int v0;
	// Line 7593, Address: 0x1653a0, Func Offset: 0
	// Line 7597, Address: 0x1653a8, Func Offset: 0x8
	// Line 7593, Address: 0x1653b4, Func Offset: 0x14
	// Line 7594, Address: 0x1653c0, Func Offset: 0x20
	// Line 7599, Address: 0x1653c8, Func Offset: 0x28
	// Line 7594, Address: 0x1653cc, Func Offset: 0x2c
	// Line 7595, Address: 0x1653d0, Func Offset: 0x30
	// Line 7597, Address: 0x1653d4, Func Offset: 0x34
	// Line 7595, Address: 0x1653d8, Func Offset: 0x38
	// Line 7597, Address: 0x1653e0, Func Offset: 0x40
	// Line 7600, Address: 0x1653e4, Func Offset: 0x44
	// Func End, Address: 0x1653ec, Func Offset: 0x4c
}

// 
// Start address: 0x1653f0
unsigned int bhReTryPointSet()
{
	// Line 7608, Address: 0x1653f0, Func Offset: 0
	// Line 7609, Address: 0x1653f8, Func Offset: 0x8
	// Line 7610, Address: 0x165408, Func Offset: 0x18
	// Line 7613, Address: 0x165410, Func Offset: 0x20
	// Line 7612, Address: 0x165414, Func Offset: 0x24
	// Line 7613, Address: 0x165418, Func Offset: 0x28
	// Func End, Address: 0x165420, Func Offset: 0x30
}

// 
// Start address: 0x165420
unsigned int bhPlyDposCk()
{
	BH_PWORK* e_ep;
	int eay2;
	int eay;
	int v3;
	int v2;
	int v1;
	// Line 7621, Address: 0x165420, Func Offset: 0
	// Line 7627, Address: 0x16542c, Func Offset: 0xc
	// Line 7629, Address: 0x165440, Func Offset: 0x20
	// Line 7630, Address: 0x165454, Func Offset: 0x34
	// Line 7631, Address: 0x165460, Func Offset: 0x40
	// Line 7640, Address: 0x16546c, Func Offset: 0x4c
	// Line 7632, Address: 0x165470, Func Offset: 0x50
	// Line 7634, Address: 0x16547c, Func Offset: 0x5c
	// Line 7635, Address: 0x165488, Func Offset: 0x68
	// Line 7636, Address: 0x165494, Func Offset: 0x74
	// Line 7638, Address: 0x1654a0, Func Offset: 0x80
	// Line 7640, Address: 0x1654b0, Func Offset: 0x90
	// Line 7641, Address: 0x1654b8, Func Offset: 0x98
	// Line 7642, Address: 0x1654c0, Func Offset: 0xa0
	// Line 7645, Address: 0x1654c4, Func Offset: 0xa4
	// Line 7646, Address: 0x1654e0, Func Offset: 0xc0
	// Line 7645, Address: 0x1654ec, Func Offset: 0xcc
	// Line 7646, Address: 0x1654f0, Func Offset: 0xd0
	// Line 7648, Address: 0x165504, Func Offset: 0xe4
	// Line 7649, Address: 0x16550c, Func Offset: 0xec
	// Line 7650, Address: 0x165514, Func Offset: 0xf4
	// Line 7651, Address: 0x165520, Func Offset: 0x100
	// Line 7652, Address: 0x16552c, Func Offset: 0x10c
	// Line 7653, Address: 0x165540, Func Offset: 0x120
	// Line 7654, Address: 0x165550, Func Offset: 0x130
	// Line 7655, Address: 0x165558, Func Offset: 0x138
	// Line 7657, Address: 0x165560, Func Offset: 0x140
	// Line 7659, Address: 0x16556c, Func Offset: 0x14c
	// Line 7660, Address: 0x165578, Func Offset: 0x158
	// Line 7661, Address: 0x16558c, Func Offset: 0x16c
	// Line 7662, Address: 0x16559c, Func Offset: 0x17c
	// Line 7663, Address: 0x1655a4, Func Offset: 0x184
	// Line 7665, Address: 0x1655ac, Func Offset: 0x18c
	// Line 7668, Address: 0x1655b8, Func Offset: 0x198
	// Line 7669, Address: 0x1655bc, Func Offset: 0x19c
	// Func End, Address: 0x1655cc, Func Offset: 0x1ac
}

// 
// Start address: 0x1655d0
unsigned int bhPlItemLostEx()
{
	int v1;
	int v0;
	unsigned int cnt2;
	unsigned int cnt;
	// Line 7681, Address: 0x1655d0, Func Offset: 0
	// Line 7693, Address: 0x1655d8, Func Offset: 0x8
	// Line 7681, Address: 0x1655e0, Func Offset: 0x10
	// Line 7682, Address: 0x1655ec, Func Offset: 0x1c
	// Line 7683, Address: 0x1655f8, Func Offset: 0x28
	// Line 7684, Address: 0x165604, Func Offset: 0x34
	// Line 7685, Address: 0x165610, Func Offset: 0x40
	// Line 7693, Address: 0x16561c, Func Offset: 0x4c
	// Line 7687, Address: 0x165620, Func Offset: 0x50
	// Line 7693, Address: 0x165624, Func Offset: 0x54
	// Line 7694, Address: 0x16563c, Func Offset: 0x6c
	// Line 7696, Address: 0x165650, Func Offset: 0x80
	// Line 7698, Address: 0x165668, Func Offset: 0x98
	// Line 7696, Address: 0x16566c, Func Offset: 0x9c
	// Line 7698, Address: 0x165670, Func Offset: 0xa0
	// Line 7699, Address: 0x16567c, Func Offset: 0xac
	// Line 7700, Address: 0x1656b8, Func Offset: 0xe8
	// Line 7702, Address: 0x1656c0, Func Offset: 0xf0
	// Line 7703, Address: 0x1656c8, Func Offset: 0xf8
	// Line 7706, Address: 0x1656d4, Func Offset: 0x104
	// Line 7707, Address: 0x1656dc, Func Offset: 0x10c
	// Line 7708, Address: 0x1656e4, Func Offset: 0x114
	// Line 7707, Address: 0x1656e8, Func Offset: 0x118
	// Line 7709, Address: 0x1656ec, Func Offset: 0x11c
	// Line 7710, Address: 0x165710, Func Offset: 0x140
	// Line 7712, Address: 0x165718, Func Offset: 0x148
	// Line 7713, Address: 0x16572c, Func Offset: 0x15c
	// Line 7714, Address: 0x165730, Func Offset: 0x160
	// Func End, Address: 0x165738, Func Offset: 0x168
}

// 
// Start address: 0x165740
unsigned int bhCyodanSetEx()
{
	BH_PWORK* e_ep;
	int wp_hef;
	_anon39 wps;
	_anon39 ps;
	int w7;
	int w6;
	int w5;
	int w3;
	int w2;
	int w1;
	int w0;
	int v5;
	int v4;
	int v3;
	int v2;
	int v1;
	int v0;
	// Line 7725, Address: 0x165740, Func Offset: 0
	// Line 7737, Address: 0x165748, Func Offset: 0x8
	// Line 7738, Address: 0x16575c, Func Offset: 0x1c
	// Line 7739, Address: 0x165768, Func Offset: 0x28
	// Line 7740, Address: 0x165774, Func Offset: 0x34
	// Line 7741, Address: 0x165780, Func Offset: 0x40
	// Line 7742, Address: 0x16578c, Func Offset: 0x4c
	// Line 7743, Address: 0x165798, Func Offset: 0x58
	// Line 7744, Address: 0x1657a4, Func Offset: 0x64
	// Line 7745, Address: 0x1657b0, Func Offset: 0x70
	// Line 7746, Address: 0x1657bc, Func Offset: 0x7c
	// Line 7747, Address: 0x1657c8, Func Offset: 0x88
	// Line 7748, Address: 0x1657d4, Func Offset: 0x94
	// Line 7749, Address: 0x1657e0, Func Offset: 0xa0
	// Line 7750, Address: 0x1657ec, Func Offset: 0xac
	// Line 7751, Address: 0x1657f8, Func Offset: 0xb8
	// Line 7752, Address: 0x165804, Func Offset: 0xc4
	// Line 7753, Address: 0x165810, Func Offset: 0xd0
	// Line 7754, Address: 0x16581c, Func Offset: 0xdc
	// Line 7755, Address: 0x165828, Func Offset: 0xe8
	// Line 7758, Address: 0x165834, Func Offset: 0xf4
	// Line 7759, Address: 0x165840, Func Offset: 0x100
	// Line 7760, Address: 0x16589c, Func Offset: 0x15c
	// Line 7761, Address: 0x1658a4, Func Offset: 0x164
	// Line 7763, Address: 0x1658f4, Func Offset: 0x1b4
	// Line 7766, Address: 0x1658fc, Func Offset: 0x1bc
	// Line 7763, Address: 0x165900, Func Offset: 0x1c0
	// Line 7766, Address: 0x165908, Func Offset: 0x1c8
	// Line 7767, Address: 0x165910, Func Offset: 0x1d0
	// Line 7768, Address: 0x16596c, Func Offset: 0x22c
	// Line 7769, Address: 0x165974, Func Offset: 0x234
	// Line 7771, Address: 0x1659c4, Func Offset: 0x284
	// Line 7774, Address: 0x1659cc, Func Offset: 0x28c
	// Line 7771, Address: 0x1659d0, Func Offset: 0x290
	// Line 7774, Address: 0x1659d8, Func Offset: 0x298
	// Line 7775, Address: 0x1659e0, Func Offset: 0x2a0
	// Line 7776, Address: 0x165a3c, Func Offset: 0x2fc
	// Line 7777, Address: 0x165a44, Func Offset: 0x304
	// Line 7779, Address: 0x165a94, Func Offset: 0x354
	// Line 7784, Address: 0x165a9c, Func Offset: 0x35c
	// Line 7779, Address: 0x165aa4, Func Offset: 0x364
	// Line 7781, Address: 0x165ab0, Func Offset: 0x370
	// Line 7782, Address: 0x165abc, Func Offset: 0x37c
	// Line 7784, Address: 0x165ac8, Func Offset: 0x388
	// Line 7786, Address: 0x165ad0, Func Offset: 0x390
	// Line 7784, Address: 0x165ad8, Func Offset: 0x398
	// Line 7786, Address: 0x165ae8, Func Offset: 0x3a8
	// Line 7787, Address: 0x165aec, Func Offset: 0x3ac
	// Line 7784, Address: 0x165af0, Func Offset: 0x3b0
	// Line 7787, Address: 0x165af4, Func Offset: 0x3b4
	// Line 7790, Address: 0x165af8, Func Offset: 0x3b8
	// Line 7791, Address: 0x165b04, Func Offset: 0x3c4
	// Line 7792, Address: 0x165b60, Func Offset: 0x420
	// Line 7793, Address: 0x165b68, Func Offset: 0x428
	// Line 7795, Address: 0x165bb8, Func Offset: 0x478
	// Line 7798, Address: 0x165bc0, Func Offset: 0x480
	// Line 7795, Address: 0x165bc4, Func Offset: 0x484
	// Line 7798, Address: 0x165bcc, Func Offset: 0x48c
	// Line 7799, Address: 0x165bd4, Func Offset: 0x494
	// Line 7800, Address: 0x165c30, Func Offset: 0x4f0
	// Line 7801, Address: 0x165c38, Func Offset: 0x4f8
	// Line 7803, Address: 0x165c88, Func Offset: 0x548
	// Line 7806, Address: 0x165c90, Func Offset: 0x550
	// Line 7803, Address: 0x165c94, Func Offset: 0x554
	// Line 7806, Address: 0x165c9c, Func Offset: 0x55c
	// Line 7807, Address: 0x165ca4, Func Offset: 0x564
	// Line 7808, Address: 0x165d00, Func Offset: 0x5c0
	// Line 7809, Address: 0x165d08, Func Offset: 0x5c8
	// Line 7811, Address: 0x165d58, Func Offset: 0x618
	// Line 7821, Address: 0x165d60, Func Offset: 0x620
	// Line 7811, Address: 0x165d64, Func Offset: 0x624
	// Line 7814, Address: 0x165d70, Func Offset: 0x630
	// Line 7815, Address: 0x165d7c, Func Offset: 0x63c
	// Line 7816, Address: 0x165d88, Func Offset: 0x648
	// Line 7817, Address: 0x165d94, Func Offset: 0x654
	// Line 7818, Address: 0x165da0, Func Offset: 0x660
	// Line 7819, Address: 0x165dac, Func Offset: 0x66c
	// Line 7821, Address: 0x165db4, Func Offset: 0x674
	// Line 7825, Address: 0x165dd0, Func Offset: 0x690
	// Line 7827, Address: 0x165de0, Func Offset: 0x6a0
	// Line 7825, Address: 0x165de4, Func Offset: 0x6a4
	// Line 7827, Address: 0x165df4, Func Offset: 0x6b4
	// Line 7825, Address: 0x165dfc, Func Offset: 0x6bc
	// Line 7827, Address: 0x165e04, Func Offset: 0x6c4
	// Line 7825, Address: 0x165e08, Func Offset: 0x6c8
	// Line 7827, Address: 0x165e20, Func Offset: 0x6e0
	// Line 7828, Address: 0x165e38, Func Offset: 0x6f8
	// Line 7829, Address: 0x165e54, Func Offset: 0x714
	// Line 7838, Address: 0x165e6c, Func Offset: 0x72c
	// Line 7841, Address: 0x165e74, Func Offset: 0x734
	// Line 7844, Address: 0x165e84, Func Offset: 0x744
	// Line 7841, Address: 0x165e88, Func Offset: 0x748
	// Line 7844, Address: 0x165ea0, Func Offset: 0x760
	// Line 7841, Address: 0x165eac, Func Offset: 0x76c
	// Line 7844, Address: 0x165eb0, Func Offset: 0x770
	// Line 7845, Address: 0x165ec8, Func Offset: 0x788
	// Line 7846, Address: 0x165ee4, Func Offset: 0x7a4
	// Line 7858, Address: 0x165f00, Func Offset: 0x7c0
	// Line 7860, Address: 0x165f44, Func Offset: 0x804
	// Line 7859, Address: 0x165f48, Func Offset: 0x808
	// Line 7860, Address: 0x165f4c, Func Offset: 0x80c
	// Func End, Address: 0x165f54, Func Offset: 0x814
}

// 
// Start address: 0x165f60
unsigned int bhArmsItemSet()
{
	int v0;
	unsigned int wicnt;
	unsigned int icnt;
	unsigned int cnt;
	// Line 7872, Address: 0x165f60, Func Offset: 0
	// Line 7876, Address: 0x165f68, Func Offset: 0x8
	// Line 7872, Address: 0x165f74, Func Offset: 0x14
	// Line 7873, Address: 0x165f80, Func Offset: 0x20
	// Line 7874, Address: 0x165f8c, Func Offset: 0x2c
	// Line 7876, Address: 0x165f98, Func Offset: 0x38
	// Line 7877, Address: 0x165fa8, Func Offset: 0x48
	// Line 7878, Address: 0x165fcc, Func Offset: 0x6c
	// Line 7880, Address: 0x165fe0, Func Offset: 0x80
	// Line 7882, Address: 0x165fec, Func Offset: 0x8c
	// Line 7883, Address: 0x166004, Func Offset: 0xa4
	// Line 7884, Address: 0x16600c, Func Offset: 0xac
	// Line 7885, Address: 0x166030, Func Offset: 0xd0
	// Line 7887, Address: 0x166044, Func Offset: 0xe4
	// Line 7889, Address: 0x166050, Func Offset: 0xf0
	// Line 7890, Address: 0x166064, Func Offset: 0x104
	// Line 7892, Address: 0x166068, Func Offset: 0x108
	// Line 7893, Address: 0x166070, Func Offset: 0x110
	// Line 7895, Address: 0x166080, Func Offset: 0x120
	// Line 7896, Address: 0x166084, Func Offset: 0x124
	// Func End, Address: 0x16608c, Func Offset: 0x12c
}

// 
// Start address: 0x166090
unsigned int bhItemGetGetEx()
{
	int v3;
	int v2;
	int v1;
	int v0;
	unsigned int wicnt;
	unsigned int icnt;
	unsigned int cnt;
	// Line 7908, Address: 0x166090, Func Offset: 0
	// Line 7918, Address: 0x166098, Func Offset: 0x8
	// Line 7908, Address: 0x1660a4, Func Offset: 0x14
	// Line 7909, Address: 0x1660b0, Func Offset: 0x20
	// Line 7910, Address: 0x1660bc, Func Offset: 0x2c
	// Line 7911, Address: 0x1660c8, Func Offset: 0x38
	// Line 7912, Address: 0x1660d4, Func Offset: 0x44
	// Line 7913, Address: 0x1660e0, Func Offset: 0x50
	// Line 7914, Address: 0x1660ec, Func Offset: 0x5c
	// Line 7915, Address: 0x1660f8, Func Offset: 0x68
	// Line 7916, Address: 0x166104, Func Offset: 0x74
	// Line 7918, Address: 0x166110, Func Offset: 0x80
	// Line 7919, Address: 0x166120, Func Offset: 0x90
	// Line 7920, Address: 0x166140, Func Offset: 0xb0
	// Line 7922, Address: 0x16614c, Func Offset: 0xbc
	// Line 7924, Address: 0x166158, Func Offset: 0xc8
	// Line 7925, Address: 0x16616c, Func Offset: 0xdc
	// Line 7926, Address: 0x166174, Func Offset: 0xe4
	// Line 7927, Address: 0x166194, Func Offset: 0x104
	// Line 7929, Address: 0x1661a0, Func Offset: 0x110
	// Line 7931, Address: 0x1661ac, Func Offset: 0x11c
	// Line 7932, Address: 0x1661c4, Func Offset: 0x134
	// Line 7934, Address: 0x1661c8, Func Offset: 0x138
	// Line 7935, Address: 0x1661d0, Func Offset: 0x140
	// Line 7936, Address: 0x1661e0, Func Offset: 0x150
	// Line 7937, Address: 0x1661e8, Func Offset: 0x158
	// Line 7936, Address: 0x1661ec, Func Offset: 0x15c
	// Line 7937, Address: 0x1661f8, Func Offset: 0x168
	// Line 7938, Address: 0x166200, Func Offset: 0x170
	// Line 7940, Address: 0x16621c, Func Offset: 0x18c
	// Line 7941, Address: 0x166224, Func Offset: 0x194
	// Line 7945, Address: 0x166238, Func Offset: 0x1a8
	// Line 7946, Address: 0x16623c, Func Offset: 0x1ac
	// Func End, Address: 0x166244, Func Offset: 0x1b4
}

// 
// Start address: 0x166250
unsigned int bhEffectSandSetMatsumoto()
{
	int v2;
	int v1;
	int v0;
	// Line 7954, Address: 0x166250, Func Offset: 0
	// Line 7957, Address: 0x166258, Func Offset: 0x8
	// Line 7958, Address: 0x16626c, Func Offset: 0x1c
	// Line 7959, Address: 0x166278, Func Offset: 0x28
	// Line 7960, Address: 0x166284, Func Offset: 0x34
	// Line 7961, Address: 0x166290, Func Offset: 0x40
	// Line 7962, Address: 0x16629c, Func Offset: 0x4c
	// Line 7963, Address: 0x1662a8, Func Offset: 0x58
	// Line 7969, Address: 0x1662b0, Func Offset: 0x60
	// Line 7972, Address: 0x1662b8, Func Offset: 0x68
	// Line 7971, Address: 0x1662bc, Func Offset: 0x6c
	// Line 7972, Address: 0x1662c0, Func Offset: 0x70
	// Func End, Address: 0x1662c8, Func Offset: 0x78
}

// 
// Start address: 0x1662d0
unsigned int bhVoiceWait()
{
	BH_PWORK* e_ep;
	_anon39 pPos;
	unsigned int v4;
	unsigned int v3;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	// Line 7981, Address: 0x1662d0, Func Offset: 0
	// Line 7987, Address: 0x1662ec, Func Offset: 0x1c
	// Line 8002, Address: 0x1662f4, Func Offset: 0x24
	// Line 7987, Address: 0x1662fc, Func Offset: 0x2c
	// Line 7988, Address: 0x166308, Func Offset: 0x38
	// Line 8002, Address: 0x166310, Func Offset: 0x40
	// Line 7988, Address: 0x166314, Func Offset: 0x44
	// Line 7989, Address: 0x166318, Func Offset: 0x48
	// Line 7990, Address: 0x166324, Func Offset: 0x54
	// Line 7991, Address: 0x166330, Func Offset: 0x60
	// Line 7992, Address: 0x16633c, Func Offset: 0x6c
	// Line 7993, Address: 0x166348, Func Offset: 0x78
	// Line 7994, Address: 0x166354, Func Offset: 0x84
	// Line 7996, Address: 0x166360, Func Offset: 0x90
	// Line 7995, Address: 0x16636c, Func Offset: 0x9c
	// Line 7997, Address: 0x166374, Func Offset: 0xa4
	// Line 7998, Address: 0x166380, Func Offset: 0xb0
	// Line 8000, Address: 0x16638c, Func Offset: 0xbc
	// Line 8002, Address: 0x1663a0, Func Offset: 0xd0
	// Line 8003, Address: 0x1663ac, Func Offset: 0xdc
	// Line 8004, Address: 0x1663b0, Func Offset: 0xe0
	// Line 8007, Address: 0x1663b8, Func Offset: 0xe8
	// Line 8010, Address: 0x1663e0, Func Offset: 0x110
	// Line 8011, Address: 0x1663f8, Func Offset: 0x128
	// Line 8012, Address: 0x166408, Func Offset: 0x138
	// Line 8013, Address: 0x166414, Func Offset: 0x144
	// Line 8017, Address: 0x16641c, Func Offset: 0x14c
	// Line 8018, Address: 0x16645c, Func Offset: 0x18c
	// Line 8019, Address: 0x16646c, Func Offset: 0x19c
	// Line 8020, Address: 0x16647c, Func Offset: 0x1ac
	// Line 8021, Address: 0x166488, Func Offset: 0x1b8
	// Line 8024, Address: 0x166490, Func Offset: 0x1c0
	// Line 8025, Address: 0x1664bc, Func Offset: 0x1ec
	// Line 8026, Address: 0x1664cc, Func Offset: 0x1fc
	// Line 8027, Address: 0x1664dc, Func Offset: 0x20c
	// Line 8030, Address: 0x1664ec, Func Offset: 0x21c
	// Line 8039, Address: 0x1664f8, Func Offset: 0x228
	// Line 8042, Address: 0x166510, Func Offset: 0x240
	// Line 8041, Address: 0x166528, Func Offset: 0x258
	// Line 8042, Address: 0x16652c, Func Offset: 0x25c
	// Func End, Address: 0x166534, Func Offset: 0x264
}

// 
// Start address: 0x166540
unsigned int bhVoiceStart()
{
	// Line 8050, Address: 0x166540, Func Offset: 0
	// Line 8051, Address: 0x166548, Func Offset: 0x8
	// Line 8052, Address: 0x166558, Func Offset: 0x18
	// Line 8054, Address: 0x166560, Func Offset: 0x20
	// Line 8053, Address: 0x166564, Func Offset: 0x24
	// Line 8054, Address: 0x166568, Func Offset: 0x28
	// Func End, Address: 0x166570, Func Offset: 0x30
}

// 
// Start address: 0x166570
unsigned int bhGameOverSet()
{
	// Line 8063, Address: 0x166570, Func Offset: 0
	// Line 8064, Address: 0x166578, Func Offset: 0x8
	// Line 8066, Address: 0x16657c, Func Offset: 0xc
	// Line 8064, Address: 0x166580, Func Offset: 0x10
	// Line 8063, Address: 0x166588, Func Offset: 0x18
	// Line 8064, Address: 0x166594, Func Offset: 0x24
	// Line 8065, Address: 0x166598, Func Offset: 0x28
	// Line 8064, Address: 0x16659c, Func Offset: 0x2c
	// Line 8065, Address: 0x1665a4, Func Offset: 0x34
	// Line 8067, Address: 0x1665b4, Func Offset: 0x44
	// Func End, Address: 0x1665bc, Func Offset: 0x4c
}

// 
// Start address: 0x1665c0
unsigned int bhPlItemChangeM()
{
	int v1;
	int v0;
	unsigned int cnt;
	// Line 8079, Address: 0x1665c0, Func Offset: 0
	// Line 8085, Address: 0x1665c8, Func Offset: 0x8
	// Line 8079, Address: 0x1665d0, Func Offset: 0x10
	// Line 8080, Address: 0x1665dc, Func Offset: 0x1c
	// Line 8081, Address: 0x1665e8, Func Offset: 0x28
	// Line 8082, Address: 0x1665f4, Func Offset: 0x34
	// Line 8083, Address: 0x166600, Func Offset: 0x40
	// Line 8085, Address: 0x16660c, Func Offset: 0x4c
	// Line 8086, Address: 0x166628, Func Offset: 0x68
	// Line 8087, Address: 0x16663c, Func Offset: 0x7c
	// Line 8088, Address: 0x16664c, Func Offset: 0x8c
	// Line 8090, Address: 0x166658, Func Offset: 0x98
	// Line 8091, Address: 0x16666c, Func Offset: 0xac
	// Line 8092, Address: 0x166670, Func Offset: 0xb0
	// Func End, Address: 0x166678, Func Offset: 0xb8
}

// 
// Start address: 0x166680
unsigned int bhEffBakuDrmSet()
{
	_anon39 pPos;
	int v2;
	// Line 8100, Address: 0x166680, Func Offset: 0
	// Line 8104, Address: 0x166688, Func Offset: 0x8
	// Line 8105, Address: 0x16669c, Func Offset: 0x1c
	// Line 8106, Address: 0x1666a8, Func Offset: 0x28
	// Line 8109, Address: 0x1666b4, Func Offset: 0x34
	// Line 8110, Address: 0x1666c0, Func Offset: 0x40
	// Line 8111, Address: 0x16671c, Func Offset: 0x9c
	// Line 8112, Address: 0x166724, Func Offset: 0xa4
	// Line 8114, Address: 0x166774, Func Offset: 0xf4
	// Line 8116, Address: 0x16677c, Func Offset: 0xfc
	// Line 8114, Address: 0x166780, Func Offset: 0x100
	// Line 8116, Address: 0x166788, Func Offset: 0x108
	// Line 8117, Address: 0x166790, Func Offset: 0x110
	// Line 8118, Address: 0x1667ec, Func Offset: 0x16c
	// Line 8119, Address: 0x1667f4, Func Offset: 0x174
	// Line 8121, Address: 0x166844, Func Offset: 0x1c4
	// Line 8123, Address: 0x16684c, Func Offset: 0x1cc
	// Line 8121, Address: 0x166850, Func Offset: 0x1d0
	// Line 8123, Address: 0x166858, Func Offset: 0x1d8
	// Line 8124, Address: 0x166860, Func Offset: 0x1e0
	// Line 8125, Address: 0x1668bc, Func Offset: 0x23c
	// Line 8126, Address: 0x1668c4, Func Offset: 0x244
	// Line 8128, Address: 0x166914, Func Offset: 0x294
	// Line 8130, Address: 0x16691c, Func Offset: 0x29c
	// Line 8128, Address: 0x166920, Func Offset: 0x2a0
	// Line 8130, Address: 0x166928, Func Offset: 0x2a8
	// Line 8133, Address: 0x166930, Func Offset: 0x2b0
	// Line 8132, Address: 0x166934, Func Offset: 0x2b4
	// Line 8133, Address: 0x166938, Func Offset: 0x2b8
	// Func End, Address: 0x166940, Func Offset: 0x2c0
}

// 
// Start address: 0x166940
unsigned int bhPlItemTamaSet()
{
	int v1;
	int v0;
	unsigned int cnt;
	// Line 8145, Address: 0x166940, Func Offset: 0
	// Line 8151, Address: 0x166948, Func Offset: 0x8
	// Line 8145, Address: 0x166950, Func Offset: 0x10
	// Line 8146, Address: 0x16695c, Func Offset: 0x1c
	// Line 8147, Address: 0x166968, Func Offset: 0x28
	// Line 8148, Address: 0x166974, Func Offset: 0x34
	// Line 8149, Address: 0x166980, Func Offset: 0x40
	// Line 8151, Address: 0x16698c, Func Offset: 0x4c
	// Line 8152, Address: 0x1669a8, Func Offset: 0x68
	// Line 8153, Address: 0x1669bc, Func Offset: 0x7c
	// Line 8154, Address: 0x1669d0, Func Offset: 0x90
	// Line 8156, Address: 0x1669dc, Func Offset: 0x9c
	// Line 8157, Address: 0x1669ec, Func Offset: 0xac
	// Line 8158, Address: 0x1669f0, Func Offset: 0xb0
	// Func End, Address: 0x1669f8, Func Offset: 0xb8
}

// 
// Start address: 0x166a00
unsigned int bhEffClearEvt()
{
	// Line 8166, Address: 0x166a00, Func Offset: 0
	// Line 8167, Address: 0x166a08, Func Offset: 0x8
	// Line 8169, Address: 0x166a18, Func Offset: 0x18
	// Line 8172, Address: 0x166a20, Func Offset: 0x20
	// Line 8171, Address: 0x166a24, Func Offset: 0x24
	// Line 8172, Address: 0x166a28, Func Offset: 0x28
	// Func End, Address: 0x166a30, Func Offset: 0x30
}

// 
// Start address: 0x166a30
unsigned int bhEvtTimerSet()
{
	int v0;
	// Line 8180, Address: 0x166a30, Func Offset: 0
	// Line 8183, Address: 0x166a38, Func Offset: 0x8
	// Line 8184, Address: 0x166a4c, Func Offset: 0x1c
	// Line 8185, Address: 0x166a58, Func Offset: 0x28
	// Line 8187, Address: 0x166a60, Func Offset: 0x30
	// Line 8190, Address: 0x166a68, Func Offset: 0x38
	// Line 8189, Address: 0x166a6c, Func Offset: 0x3c
	// Line 8190, Address: 0x166a70, Func Offset: 0x40
	// Func End, Address: 0x166a78, Func Offset: 0x48
}

// 
// Start address: 0x166a80
unsigned int bhEneLookFlgSet()
{
	BH_PWORK* e_ep;
	unsigned int v3;
	unsigned int v2;
	// Line 8204, Address: 0x166a80, Func Offset: 0
	// Line 8216, Address: 0x166a88, Func Offset: 0x8
	// Line 8204, Address: 0x166a98, Func Offset: 0x18
	// Line 8205, Address: 0x166aa4, Func Offset: 0x24
	// Line 8206, Address: 0x166ab0, Func Offset: 0x30
	// Line 8207, Address: 0x166abc, Func Offset: 0x3c
	// Line 8216, Address: 0x166ac4, Func Offset: 0x44
	// Line 8207, Address: 0x166ad0, Func Offset: 0x50
	// Line 8208, Address: 0x166ad4, Func Offset: 0x54
	// Line 8216, Address: 0x166ae0, Func Offset: 0x60
	// Line 8217, Address: 0x166b00, Func Offset: 0x80
	// Line 8218, Address: 0x166b08, Func Offset: 0x88
	// Line 8219, Address: 0x166b18, Func Offset: 0x98
	// Line 8220, Address: 0x166b20, Func Offset: 0xa0
	// Line 8223, Address: 0x166b2c, Func Offset: 0xac
	// Func End, Address: 0x166b34, Func Offset: 0xb4
}

// 
// Start address: 0x166b40
unsigned int bhReturnTitleEvt()
{
	// Line 8231, Address: 0x166b40, Func Offset: 0
	// Line 8232, Address: 0x166b48, Func Offset: 0x8
	// Line 8235, Address: 0x166b50, Func Offset: 0x10
	// Line 8232, Address: 0x166b5c, Func Offset: 0x1c
	// Line 8235, Address: 0x166b64, Func Offset: 0x24
	// Line 8236, Address: 0x166b6c, Func Offset: 0x2c
	// Line 8237, Address: 0x166b74, Func Offset: 0x34
	// Line 8239, Address: 0x166b80, Func Offset: 0x40
	// Line 8237, Address: 0x166b84, Func Offset: 0x44
	// Line 8240, Address: 0x166b90, Func Offset: 0x50
	// Func End, Address: 0x166b9c, Func Offset: 0x5c
}

// 
// Start address: 0x166ba0
unsigned int bhSyukanModeSet()
{
	unsigned int v0;
	// Line 8251, Address: 0x166ba0, Func Offset: 0
	// Line 8252, Address: 0x166bb4, Func Offset: 0x14
	// Line 8253, Address: 0x166bc0, Func Offset: 0x20
	// Line 8255, Address: 0x166bc8, Func Offset: 0x28
	// Line 8256, Address: 0x166bd0, Func Offset: 0x30
	// Line 8258, Address: 0x166bdc, Func Offset: 0x3c
	// Line 8260, Address: 0x166be0, Func Offset: 0x40
	// Line 8256, Address: 0x166be4, Func Offset: 0x44
	// Line 8257, Address: 0x166be8, Func Offset: 0x48
	// Line 8256, Address: 0x166bec, Func Offset: 0x4c
	// Line 8257, Address: 0x166bf4, Func Offset: 0x54
	// Line 8258, Address: 0x166bf8, Func Offset: 0x58
	// Line 8259, Address: 0x166c00, Func Offset: 0x60
	// Line 8260, Address: 0x166c0c, Func Offset: 0x6c
	// Line 8259, Address: 0x166c10, Func Offset: 0x70
	// Line 8260, Address: 0x166c18, Func Offset: 0x78
	// Line 8261, Address: 0x166c20, Func Offset: 0x80
	// Line 8260, Address: 0x166c24, Func Offset: 0x84
	// Line 8261, Address: 0x166c2c, Func Offset: 0x8c
	// Line 8262, Address: 0x166c34, Func Offset: 0x94
	// Line 8263, Address: 0x166c3c, Func Offset: 0x9c
	// Line 8264, Address: 0x166c50, Func Offset: 0xb0
	// Line 8263, Address: 0x166c54, Func Offset: 0xb4
	// Line 8264, Address: 0x166c5c, Func Offset: 0xbc
	// Line 8267, Address: 0x166c6c, Func Offset: 0xcc
	// Func End, Address: 0x166c74, Func Offset: 0xd4
}

// 
// Start address: 0x166c80
unsigned int bhExGameItemInit()
{
	// Line 8275, Address: 0x166c80, Func Offset: 0
	// Line 8276, Address: 0x166c88, Func Offset: 0x8
	// Line 8277, Address: 0x166c98, Func Offset: 0x18
	// Line 8279, Address: 0x166ca0, Func Offset: 0x20
	// Line 8278, Address: 0x166ca4, Func Offset: 0x24
	// Line 8279, Address: 0x166ca8, Func Offset: 0x28
	// Func End, Address: 0x166cb0, Func Offset: 0x30
}

// 
// Start address: 0x166cb0
unsigned int bhEneLifeSetM()
{
	int v1;
	int v0;
	// Line 8292, Address: 0x166cb0, Func Offset: 0
	// Line 8303, Address: 0x166cb8, Func Offset: 0x8
	// Line 8305, Address: 0x166cc0, Func Offset: 0x10
	// Line 8303, Address: 0x166cc4, Func Offset: 0x14
	// Line 8292, Address: 0x166ccc, Func Offset: 0x1c
	// Line 8293, Address: 0x166cd8, Func Offset: 0x28
	// Line 8294, Address: 0x166ce4, Func Offset: 0x34
	// Line 8295, Address: 0x166cf0, Func Offset: 0x40
	// Line 8303, Address: 0x166cf8, Func Offset: 0x48
	// Line 8295, Address: 0x166d04, Func Offset: 0x54
	// Line 8296, Address: 0x166d08, Func Offset: 0x58
	// Line 8303, Address: 0x166d14, Func Offset: 0x64
	// Line 8306, Address: 0x166d38, Func Offset: 0x88
	// Func End, Address: 0x166d40, Func Offset: 0x90
}

// 
// Start address: 0x166d40
unsigned int bhEffSSizeSet()
{
	_anon0* e_ep;
	int v1;
	int v0;
	// Line 8319, Address: 0x166d40, Func Offset: 0
	// Line 8329, Address: 0x166d48, Func Offset: 0x8
	// Line 8319, Address: 0x166d58, Func Offset: 0x18
	// Line 8320, Address: 0x166d64, Func Offset: 0x24
	// Line 8321, Address: 0x166d70, Func Offset: 0x30
	// Line 8329, Address: 0x166d7c, Func Offset: 0x3c
	// Line 8322, Address: 0x166d80, Func Offset: 0x40
	// Line 8329, Address: 0x166d88, Func Offset: 0x48
	// Line 8322, Address: 0x166d8c, Func Offset: 0x4c
	// Line 8323, Address: 0x166d90, Func Offset: 0x50
	// Line 8329, Address: 0x166d9c, Func Offset: 0x5c
	// Line 8332, Address: 0x166da8, Func Offset: 0x68
	// Line 8329, Address: 0x166dac, Func Offset: 0x6c
	// Line 8332, Address: 0x166dc0, Func Offset: 0x80
	// Line 8333, Address: 0x166dc8, Func Offset: 0x88
	// Line 8334, Address: 0x166e28, Func Offset: 0xe8
	// Line 8335, Address: 0x166e30, Func Offset: 0xf0
	// Line 8337, Address: 0x166e84, Func Offset: 0x144
	// Line 8340, Address: 0x166e8c, Func Offset: 0x14c
	// Line 8337, Address: 0x166e90, Func Offset: 0x150
	// Line 8340, Address: 0x166e98, Func Offset: 0x158
	// Line 8341, Address: 0x166ea0, Func Offset: 0x160
	// Line 8342, Address: 0x166f00, Func Offset: 0x1c0
	// Line 8343, Address: 0x166f08, Func Offset: 0x1c8
	// Line 8345, Address: 0x166f5c, Func Offset: 0x21c
	// Line 8348, Address: 0x166f64, Func Offset: 0x224
	// Line 8345, Address: 0x166f68, Func Offset: 0x228
	// Line 8348, Address: 0x166f70, Func Offset: 0x230
	// Line 8349, Address: 0x166f78, Func Offset: 0x238
	// Line 8350, Address: 0x166fd8, Func Offset: 0x298
	// Line 8351, Address: 0x166fe0, Func Offset: 0x2a0
	// Line 8353, Address: 0x167034, Func Offset: 0x2f4
	// Line 8355, Address: 0x16703c, Func Offset: 0x2fc
	// Line 8353, Address: 0x167040, Func Offset: 0x300
	// Line 8356, Address: 0x167048, Func Offset: 0x308
	// Func End, Address: 0x167050, Func Offset: 0x310
}

// 
// Start address: 0x167050
unsigned int bhEffLinkOffsetSet()
{
	_anon0* e_ep;
	int v1;
	int v0;
	// Line 8369, Address: 0x167050, Func Offset: 0
	// Line 8379, Address: 0x167058, Func Offset: 0x8
	// Line 8369, Address: 0x167068, Func Offset: 0x18
	// Line 8370, Address: 0x167074, Func Offset: 0x24
	// Line 8371, Address: 0x167080, Func Offset: 0x30
	// Line 8379, Address: 0x16708c, Func Offset: 0x3c
	// Line 8372, Address: 0x167090, Func Offset: 0x40
	// Line 8379, Address: 0x167098, Func Offset: 0x48
	// Line 8372, Address: 0x16709c, Func Offset: 0x4c
	// Line 8373, Address: 0x1670a0, Func Offset: 0x50
	// Line 8379, Address: 0x1670ac, Func Offset: 0x5c
	// Line 8382, Address: 0x1670b8, Func Offset: 0x68
	// Line 8379, Address: 0x1670bc, Func Offset: 0x6c
	// Line 8382, Address: 0x1670d0, Func Offset: 0x80
	// Line 8383, Address: 0x1670d8, Func Offset: 0x88
	// Line 8384, Address: 0x167134, Func Offset: 0xe4
	// Line 8385, Address: 0x16713c, Func Offset: 0xec
	// Line 8387, Address: 0x16718c, Func Offset: 0x13c
	// Line 8390, Address: 0x167194, Func Offset: 0x144
	// Line 8387, Address: 0x167198, Func Offset: 0x148
	// Line 8390, Address: 0x1671a0, Func Offset: 0x150
	// Line 8391, Address: 0x1671a8, Func Offset: 0x158
	// Line 8392, Address: 0x167204, Func Offset: 0x1b4
	// Line 8393, Address: 0x16720c, Func Offset: 0x1bc
	// Line 8395, Address: 0x16725c, Func Offset: 0x20c
	// Line 8398, Address: 0x167264, Func Offset: 0x214
	// Line 8395, Address: 0x167268, Func Offset: 0x218
	// Line 8398, Address: 0x167270, Func Offset: 0x220
	// Line 8399, Address: 0x167278, Func Offset: 0x228
	// Line 8400, Address: 0x1672d4, Func Offset: 0x284
	// Line 8401, Address: 0x1672dc, Func Offset: 0x28c
	// Line 8403, Address: 0x16732c, Func Offset: 0x2dc
	// Line 8405, Address: 0x167334, Func Offset: 0x2e4
	// Line 8403, Address: 0x167338, Func Offset: 0x2e8
	// Line 8406, Address: 0x167340, Func Offset: 0x2f0
	// Func End, Address: 0x167348, Func Offset: 0x2f8
}

// 
// Start address: 0x167350
unsigned int bhRankingCall()
{
	// Line 8414, Address: 0x167350, Func Offset: 0
	// Line 8415, Address: 0x167358, Func Offset: 0x8
	// Line 8416, Address: 0x167360, Func Offset: 0x10
	// Line 8415, Address: 0x16736c, Func Offset: 0x1c
	// Line 8416, Address: 0x167378, Func Offset: 0x28
	// Line 8417, Address: 0x167380, Func Offset: 0x30
	// Line 8418, Address: 0x167388, Func Offset: 0x38
	// Line 8419, Address: 0x167398, Func Offset: 0x48
	// Line 8421, Address: 0x1673a0, Func Offset: 0x50
	// Line 8423, Address: 0x1673a8, Func Offset: 0x58
	// Line 8425, Address: 0x1673d8, Func Offset: 0x88
	// Line 8431, Address: 0x1673e8, Func Offset: 0x98
	// Line 8432, Address: 0x1673f0, Func Offset: 0xa0
	// Line 8425, Address: 0x1673f4, Func Offset: 0xa4
	// Line 8426, Address: 0x1673f8, Func Offset: 0xa8
	// Line 8427, Address: 0x167404, Func Offset: 0xb4
	// Line 8428, Address: 0x167410, Func Offset: 0xc0
	// Line 8429, Address: 0x16741c, Func Offset: 0xcc
	// Line 8430, Address: 0x167430, Func Offset: 0xe0
	// Line 8431, Address: 0x167450, Func Offset: 0x100
	// Line 8433, Address: 0x167464, Func Offset: 0x114
	// Func End, Address: 0x167470, Func Offset: 0x120
}

// 
// Start address: 0x167470
unsigned int bhCallSysSe()
{
	int v0;
	// Line 8441, Address: 0x167470, Func Offset: 0
	// Line 8444, Address: 0x167478, Func Offset: 0x8
	// Line 8447, Address: 0x167480, Func Offset: 0x10
	// Line 8444, Address: 0x167484, Func Offset: 0x14
	// Line 8445, Address: 0x167490, Func Offset: 0x20
	// Line 8446, Address: 0x16749c, Func Offset: 0x2c
	// Line 8447, Address: 0x1674a4, Func Offset: 0x34
	// Line 8450, Address: 0x1674ac, Func Offset: 0x3c
	// Line 8449, Address: 0x1674b0, Func Offset: 0x40
	// Line 8450, Address: 0x1674b4, Func Offset: 0x44
	// Func End, Address: 0x1674bc, Func Offset: 0x4c
}

// 
// Start address: 0x1674c0
unsigned int bhSleep()
{
	// Line 8725, Address: 0x1674c0, Func Offset: 0
	// Line 8726, Address: 0x1674cc, Func Offset: 0xc
	// Line 8725, Address: 0x1674d0, Func Offset: 0x10
	// Line 8726, Address: 0x1674d8, Func Offset: 0x18
	// Line 8728, Address: 0x1674e8, Func Offset: 0x28
	// Line 8726, Address: 0x1674ec, Func Offset: 0x2c
	// Line 8728, Address: 0x1674fc, Func Offset: 0x3c
	// Line 8729, Address: 0x167500, Func Offset: 0x40
	// Line 8728, Address: 0x167508, Func Offset: 0x48
	// Line 8729, Address: 0x167514, Func Offset: 0x54
	// Line 8733, Address: 0x167530, Func Offset: 0x70
	// Line 8734, Address: 0x167538, Func Offset: 0x78
	// Line 8733, Address: 0x167540, Func Offset: 0x80
	// Line 8734, Address: 0x16754c, Func Offset: 0x8c
	// Line 8737, Address: 0x167558, Func Offset: 0x98
	// Func End, Address: 0x167560, Func Offset: 0xa0
}

// 
// Start address: 0x167560
unsigned int bhSleeping()
{
	// Line 8742, Address: 0x167560, Func Offset: 0
	// Line 8746, Address: 0x167584, Func Offset: 0x24
	// Line 8747, Address: 0x16758c, Func Offset: 0x2c
	// Line 8746, Address: 0x167594, Func Offset: 0x34
	// Line 8747, Address: 0x1675a0, Func Offset: 0x40
	// Line 8750, Address: 0x1675ac, Func Offset: 0x4c
	// Func End, Address: 0x1675b4, Func Offset: 0x54
}

// 
// Start address: 0x1675c0
unsigned int bhWhile()
{
	// Line 8759, Address: 0x1675c0, Func Offset: 0
	// Line 8767, Address: 0x1675c8, Func Offset: 0x8
	// Line 8759, Address: 0x1675cc, Func Offset: 0xc
	// Line 8762, Address: 0x1675d0, Func Offset: 0x10
	// Line 8759, Address: 0x1675d4, Func Offset: 0x14
	// Line 8762, Address: 0x1675dc, Func Offset: 0x1c
	// Line 8763, Address: 0x1675f0, Func Offset: 0x30
	// Line 8762, Address: 0x1675f4, Func Offset: 0x34
	// Line 8763, Address: 0x167600, Func Offset: 0x40
	// Line 8766, Address: 0x167604, Func Offset: 0x44
	// Line 8763, Address: 0x167608, Func Offset: 0x48
	// Line 8766, Address: 0x16760c, Func Offset: 0x4c
	// Line 8763, Address: 0x167610, Func Offset: 0x50
	// Line 8766, Address: 0x16761c, Func Offset: 0x5c
	// Line 8768, Address: 0x167630, Func Offset: 0x70
	// Func End, Address: 0x167638, Func Offset: 0x78
}

// 
// Start address: 0x167640
unsigned int bhEwhile()
{
	// Line 8772, Address: 0x167640, Func Offset: 0
	// Line 8773, Address: 0x167648, Func Offset: 0x8
	// Line 8776, Address: 0x167650, Func Offset: 0x10
	// Line 8773, Address: 0x167658, Func Offset: 0x18
	// Line 8774, Address: 0x167664, Func Offset: 0x24
	// Line 8776, Address: 0x167684, Func Offset: 0x44
	// Line 8778, Address: 0x1676ac, Func Offset: 0x6c
	// Line 8779, Address: 0x1676c8, Func Offset: 0x88
	// Line 8781, Address: 0x1676d0, Func Offset: 0x90
	// Line 8784, Address: 0x1676d8, Func Offset: 0x98
	// Line 8781, Address: 0x1676dc, Func Offset: 0x9c
	// Line 8782, Address: 0x1676e8, Func Offset: 0xa8
	// Line 8783, Address: 0x1676fc, Func Offset: 0xbc
	// Line 8784, Address: 0x167704, Func Offset: 0xc4
	// Line 8786, Address: 0x16770c, Func Offset: 0xcc
	// Line 8787, Address: 0x167710, Func Offset: 0xd0
	// Func End, Address: 0x16771c, Func Offset: 0xdc
}

// 
// Start address: 0x167720
unsigned int bhEwhile2()
{
	// Line 8791, Address: 0x167720, Func Offset: 0
	// Line 8792, Address: 0x167728, Func Offset: 0x8
	// Line 8795, Address: 0x167730, Func Offset: 0x10
	// Line 8792, Address: 0x167738, Func Offset: 0x18
	// Line 8793, Address: 0x167744, Func Offset: 0x24
	// Line 8795, Address: 0x167764, Func Offset: 0x44
	// Line 8797, Address: 0x16778c, Func Offset: 0x6c
	// Line 8798, Address: 0x1677a8, Func Offset: 0x88
	// Line 8800, Address: 0x1677b0, Func Offset: 0x90
	// Line 8803, Address: 0x1677b8, Func Offset: 0x98
	// Line 8800, Address: 0x1677bc, Func Offset: 0x9c
	// Line 8801, Address: 0x1677c8, Func Offset: 0xa8
	// Line 8802, Address: 0x1677dc, Func Offset: 0xbc
	// Line 8803, Address: 0x1677e4, Func Offset: 0xc4
	// Line 8806, Address: 0x1677ec, Func Offset: 0xcc
	// Line 8807, Address: 0x1677f0, Func Offset: 0xd0
	// Func End, Address: 0x1677fc, Func Offset: 0xdc
}

// 
// Start address: 0x167800
unsigned int bhEvtNext()
{
	// Line 8816, Address: 0x167800, Func Offset: 0
	// Line 8817, Address: 0x167808, Func Offset: 0x8
	// Line 8816, Address: 0x16780c, Func Offset: 0xc
	// Line 8818, Address: 0x167814, Func Offset: 0x14
	// Func End, Address: 0x16781c, Func Offset: 0x1c
}

// 
// Start address: 0x167820
unsigned int bhComNext()
{
	// Line 8827, Address: 0x167820, Func Offset: 0
	// Line 8828, Address: 0x167828, Func Offset: 0x8
	// Line 8827, Address: 0x16782c, Func Offset: 0xc
	// Line 8829, Address: 0x167834, Func Offset: 0x14
	// Func End, Address: 0x16783c, Func Offset: 0x1c
}

// 
// Start address: 0x167840
unsigned int bhEvtEnd()
{
	// Line 8838, Address: 0x167840, Func Offset: 0
	// Line 8841, Address: 0x167848, Func Offset: 0x8
	// Line 8838, Address: 0x16784c, Func Offset: 0xc
	// Line 8839, Address: 0x167850, Func Offset: 0x10
	// Line 8840, Address: 0x167864, Func Offset: 0x24
	// Line 8842, Address: 0x167874, Func Offset: 0x34
	// Func End, Address: 0x16787c, Func Offset: 0x3c
}

// 
// Start address: 0x167880
unsigned int bhFor()
{
	// Line 8851, Address: 0x167880, Func Offset: 0
	// Line 8857, Address: 0x167888, Func Offset: 0x8
	// Line 8851, Address: 0x16788c, Func Offset: 0xc
	// Line 8852, Address: 0x167890, Func Offset: 0x10
	// Line 8851, Address: 0x167894, Func Offset: 0x14
	// Line 8852, Address: 0x16789c, Func Offset: 0x1c
	// Line 8855, Address: 0x1678d4, Func Offset: 0x54
	// Line 8856, Address: 0x1678dc, Func Offset: 0x5c
	// Line 8855, Address: 0x1678e4, Func Offset: 0x64
	// Line 8856, Address: 0x1678f0, Func Offset: 0x70
	// Line 8858, Address: 0x167904, Func Offset: 0x84
	// Func End, Address: 0x16790c, Func Offset: 0x8c
}

// 
// Start address: 0x167910
unsigned int bhNext()
{
	// Line 8867, Address: 0x167910, Func Offset: 0
	// Line 8868, Address: 0x167934, Func Offset: 0x24
	// Line 8870, Address: 0x167940, Func Offset: 0x30
	// Line 8868, Address: 0x167944, Func Offset: 0x34
	// Line 8870, Address: 0x167954, Func Offset: 0x44
	// Line 8871, Address: 0x16796c, Func Offset: 0x5c
	// Line 8873, Address: 0x167974, Func Offset: 0x64
	// Line 8876, Address: 0x16797c, Func Offset: 0x6c
	// Line 8875, Address: 0x167980, Func Offset: 0x70
	// Line 8873, Address: 0x167988, Func Offset: 0x78
	// Line 8874, Address: 0x167994, Func Offset: 0x84
	// Line 8875, Address: 0x1679a8, Func Offset: 0x98
	// Line 8876, Address: 0x1679b0, Func Offset: 0xa0
	// Line 8878, Address: 0x1679b8, Func Offset: 0xa8
	// Line 8879, Address: 0x1679bc, Func Offset: 0xac
	// Func End, Address: 0x1679c4, Func Offset: 0xb4
}

// 
// Start address: 0x1679d0
unsigned int bhPlCtr()
{
	// Line 8887, Address: 0x1679d0, Func Offset: 0
	// Line 8888, Address: 0x1679d8, Func Offset: 0x8
	// Line 8889, Address: 0x1679e8, Func Offset: 0x18
	// Line 8891, Address: 0x1679f8, Func Offset: 0x28
	// Line 8893, Address: 0x167a00, Func Offset: 0x30
	// Line 8892, Address: 0x167a04, Func Offset: 0x34
	// Line 8893, Address: 0x167a08, Func Offset: 0x38
	// Func End, Address: 0x167a10, Func Offset: 0x40
}

// 
// Start address: 0x167a10
int Player_controll()
{
	_anon3* e_posp;
	unsigned int v0;
	unsigned int v0;
	unsigned int v0;
	unsigned int v0;
	unsigned int v1;
	unsigned int v0;
	unsigned int v2;
	unsigned int v1;
	unsigned int v0;
	unsigned short* a0;
	unsigned int v0;
	// Line 8898, Address: 0x167a10, Func Offset: 0
	// Line 8900, Address: 0x167a20, Func Offset: 0x10
	// Line 8906, Address: 0x167b08, Func Offset: 0xf8
	// Line 8909, Address: 0x167b14, Func Offset: 0x104
	// Line 8910, Address: 0x167b28, Func Offset: 0x118
	// Line 8911, Address: 0x167b30, Func Offset: 0x120
	// Line 8910, Address: 0x167b34, Func Offset: 0x124
	// Line 8911, Address: 0x167b38, Func Offset: 0x128
	// Line 8910, Address: 0x167b3c, Func Offset: 0x12c
	// Line 8911, Address: 0x167b48, Func Offset: 0x138
	// Line 8913, Address: 0x167b58, Func Offset: 0x148
	// Line 8914, Address: 0x167b60, Func Offset: 0x150
	// Line 8917, Address: 0x167b78, Func Offset: 0x168
	// Line 8919, Address: 0x167b88, Func Offset: 0x178
	// Line 8926, Address: 0x167b90, Func Offset: 0x180
	// Line 8927, Address: 0x167b9c, Func Offset: 0x18c
	// Line 8932, Address: 0x167ba4, Func Offset: 0x194
	// Line 8928, Address: 0x167bb0, Func Offset: 0x1a0
	// Line 8930, Address: 0x167bbc, Func Offset: 0x1ac
	// Line 8931, Address: 0x167bc8, Func Offset: 0x1b8
	// Line 8932, Address: 0x167bd0, Func Offset: 0x1c0
	// Line 8935, Address: 0x167c14, Func Offset: 0x204
	// Line 8932, Address: 0x167c20, Func Offset: 0x210
	// Line 8933, Address: 0x167c24, Func Offset: 0x214
	// Line 8932, Address: 0x167c28, Func Offset: 0x218
	// Line 8933, Address: 0x167c30, Func Offset: 0x220
	// Line 8934, Address: 0x167c38, Func Offset: 0x228
	// Line 8935, Address: 0x167c40, Func Offset: 0x230
	// Line 8938, Address: 0x167c84, Func Offset: 0x274
	// Line 8935, Address: 0x167c90, Func Offset: 0x280
	// Line 8936, Address: 0x167c94, Func Offset: 0x284
	// Line 8935, Address: 0x167c98, Func Offset: 0x288
	// Line 8936, Address: 0x167ca0, Func Offset: 0x290
	// Line 8937, Address: 0x167ca8, Func Offset: 0x298
	// Line 8938, Address: 0x167cb0, Func Offset: 0x2a0
	// Line 8939, Address: 0x167cf8, Func Offset: 0x2e8
	// Line 8938, Address: 0x167cfc, Func Offset: 0x2ec
	// Line 8939, Address: 0x167d04, Func Offset: 0x2f4
	// Line 8941, Address: 0x167d08, Func Offset: 0x2f8
	// Line 8939, Address: 0x167d0c, Func Offset: 0x2fc
	// Line 8941, Address: 0x167d10, Func Offset: 0x300
	// Line 8940, Address: 0x167d14, Func Offset: 0x304
	// Line 8941, Address: 0x167d20, Func Offset: 0x310
	// Line 8943, Address: 0x167d24, Func Offset: 0x314
	// Line 8941, Address: 0x167d28, Func Offset: 0x318
	// Line 8943, Address: 0x167d30, Func Offset: 0x320
	// Line 8944, Address: 0x167d4c, Func Offset: 0x33c
	// Line 8945, Address: 0x167d50, Func Offset: 0x340
	// Line 8946, Address: 0x167d5c, Func Offset: 0x34c
	// Line 8945, Address: 0x167d60, Func Offset: 0x350
	// Line 8946, Address: 0x167d68, Func Offset: 0x358
	// Line 8949, Address: 0x167d78, Func Offset: 0x368
	// Line 8950, Address: 0x167d98, Func Offset: 0x388
	// Line 8952, Address: 0x167dc8, Func Offset: 0x3b8
	// Line 8953, Address: 0x167dd0, Func Offset: 0x3c0
	// Line 8956, Address: 0x167e00, Func Offset: 0x3f0
	// Line 8957, Address: 0x167e20, Func Offset: 0x410
	// Line 8959, Address: 0x167e50, Func Offset: 0x440
	// Line 8960, Address: 0x167e58, Func Offset: 0x448
	// Line 8963, Address: 0x167e88, Func Offset: 0x478
	// Line 8965, Address: 0x167ec0, Func Offset: 0x4b0
	// Line 8969, Address: 0x167ec8, Func Offset: 0x4b8
	// Line 8970, Address: 0x167ed4, Func Offset: 0x4c4
	// Line 8969, Address: 0x167ed8, Func Offset: 0x4c8
	// Line 8970, Address: 0x167ee0, Func Offset: 0x4d0
	// Line 8971, Address: 0x167eec, Func Offset: 0x4dc
	// Line 8987, Address: 0x167ef4, Func Offset: 0x4e4
	// Line 8978, Address: 0x167efc, Func Offset: 0x4ec
	// Line 8979, Address: 0x167f08, Func Offset: 0x4f8
	// Line 8980, Address: 0x167f14, Func Offset: 0x504
	// Line 8981, Address: 0x167f20, Func Offset: 0x510
	// Line 8982, Address: 0x167f2c, Func Offset: 0x51c
	// Line 8983, Address: 0x167f38, Func Offset: 0x528
	// Line 8984, Address: 0x167f44, Func Offset: 0x534
	// Line 8985, Address: 0x167f50, Func Offset: 0x540
	// Line 8987, Address: 0x167f64, Func Offset: 0x554
	// Line 8991, Address: 0x167f68, Func Offset: 0x558
	// Line 8987, Address: 0x167f6c, Func Offset: 0x55c
	// Line 8991, Address: 0x167f7c, Func Offset: 0x56c
	// Line 8993, Address: 0x167f84, Func Offset: 0x574
	// Line 8991, Address: 0x167f88, Func Offset: 0x578
	// Line 8993, Address: 0x167f90, Func Offset: 0x580
	// Line 8995, Address: 0x167f98, Func Offset: 0x588
	// Line 8993, Address: 0x167f9c, Func Offset: 0x58c
	// Line 8995, Address: 0x167fa4, Func Offset: 0x594
	// Line 8997, Address: 0x167fb0, Func Offset: 0x5a0
	// Line 9001, Address: 0x167fb8, Func Offset: 0x5a8
	// Line 9003, Address: 0x167fc0, Func Offset: 0x5b0
	// Line 9001, Address: 0x167fc4, Func Offset: 0x5b4
	// Line 9003, Address: 0x167fc8, Func Offset: 0x5b8
	// Line 9001, Address: 0x167fcc, Func Offset: 0x5bc
	// Line 9003, Address: 0x167fdc, Func Offset: 0x5cc
	// Line 9005, Address: 0x167fe4, Func Offset: 0x5d4
	// Line 9003, Address: 0x167fe8, Func Offset: 0x5d8
	// Line 9005, Address: 0x167ff8, Func Offset: 0x5e8
	// Line 9006, Address: 0x168004, Func Offset: 0x5f4
	// Line 9019, Address: 0x16800c, Func Offset: 0x5fc
	// Line 9012, Address: 0x168014, Func Offset: 0x604
	// Line 9013, Address: 0x168020, Func Offset: 0x610
	// Line 9015, Address: 0x16802c, Func Offset: 0x61c
	// Line 9016, Address: 0x168038, Func Offset: 0x628
	// Line 9017, Address: 0x168044, Func Offset: 0x634
	// Line 9019, Address: 0x168050, Func Offset: 0x640
	// Line 9020, Address: 0x168060, Func Offset: 0x650
	// Line 9021, Address: 0x168064, Func Offset: 0x654
	// Line 9022, Address: 0x16806c, Func Offset: 0x65c
	// Line 9024, Address: 0x168070, Func Offset: 0x660
	// Line 9027, Address: 0x16807c, Func Offset: 0x66c
	// Line 9024, Address: 0x168080, Func Offset: 0x670
	// Line 9025, Address: 0x168084, Func Offset: 0x674
	// Line 9024, Address: 0x168088, Func Offset: 0x678
	// Line 9025, Address: 0x16808c, Func Offset: 0x67c
	// Line 9026, Address: 0x168094, Func Offset: 0x684
	// Line 9025, Address: 0x168098, Func Offset: 0x688
	// Line 9026, Address: 0x16809c, Func Offset: 0x68c
	// Line 9027, Address: 0x1680a4, Func Offset: 0x694
	// Line 9026, Address: 0x1680a8, Func Offset: 0x698
	// Line 9027, Address: 0x1680ac, Func Offset: 0x69c
	// Line 9030, Address: 0x1680c0, Func Offset: 0x6b0
	// Line 9042, Address: 0x1680c8, Func Offset: 0x6b8
	// Line 9036, Address: 0x1680d0, Func Offset: 0x6c0
	// Line 9037, Address: 0x1680dc, Func Offset: 0x6cc
	// Line 9039, Address: 0x1680e8, Func Offset: 0x6d8
	// Line 9040, Address: 0x1680f4, Func Offset: 0x6e4
	// Line 9042, Address: 0x168108, Func Offset: 0x6f8
	// Line 9043, Address: 0x168118, Func Offset: 0x708
	// Line 9044, Address: 0x16811c, Func Offset: 0x70c
	// Line 9045, Address: 0x168124, Func Offset: 0x714
	// Line 9048, Address: 0x168128, Func Offset: 0x718
	// Line 9049, Address: 0x168130, Func Offset: 0x720
	// Line 9048, Address: 0x168134, Func Offset: 0x724
	// Line 9049, Address: 0x16813c, Func Offset: 0x72c
	// Line 9048, Address: 0x168140, Func Offset: 0x730
	// Line 9049, Address: 0x168144, Func Offset: 0x734
	// Line 9051, Address: 0x16814c, Func Offset: 0x73c
	// Line 9049, Address: 0x168150, Func Offset: 0x740
	// Line 9051, Address: 0x168154, Func Offset: 0x744
	// Line 9052, Address: 0x168158, Func Offset: 0x748
	// Line 9051, Address: 0x168160, Func Offset: 0x750
	// Line 9052, Address: 0x168164, Func Offset: 0x754
	// Line 9053, Address: 0x168170, Func Offset: 0x760
	// Line 9054, Address: 0x168178, Func Offset: 0x768
	// Line 9055, Address: 0x168180, Func Offset: 0x770
	// Line 9058, Address: 0x168194, Func Offset: 0x784
	// Line 9060, Address: 0x16819c, Func Offset: 0x78c
	// Line 9058, Address: 0x1681a4, Func Offset: 0x794
	// Line 9059, Address: 0x1681b0, Func Offset: 0x7a0
	// Line 9060, Address: 0x1681b8, Func Offset: 0x7a8
	// Line 9061, Address: 0x1681c4, Func Offset: 0x7b4
	// Line 9062, Address: 0x1681d0, Func Offset: 0x7c0
	// Line 9063, Address: 0x1681d8, Func Offset: 0x7c8
	// Line 9065, Address: 0x1681f0, Func Offset: 0x7e0
	// Line 9067, Address: 0x168200, Func Offset: 0x7f0
	// Line 9072, Address: 0x168208, Func Offset: 0x7f8
	// Line 9071, Address: 0x168210, Func Offset: 0x800
	// Line 9072, Address: 0x16821c, Func Offset: 0x80c
	// Line 9073, Address: 0x168228, Func Offset: 0x818
	// Line 9072, Address: 0x16822c, Func Offset: 0x81c
	// Line 9073, Address: 0x168230, Func Offset: 0x820
	// Line 9074, Address: 0x168234, Func Offset: 0x824
	// Line 9073, Address: 0x16823c, Func Offset: 0x82c
	// Line 9074, Address: 0x168248, Func Offset: 0x838
	// Line 9075, Address: 0x168254, Func Offset: 0x844
	// Line 9074, Address: 0x168258, Func Offset: 0x848
	// Line 9075, Address: 0x16825c, Func Offset: 0x84c
	// Line 9076, Address: 0x168260, Func Offset: 0x850
	// Line 9075, Address: 0x168268, Func Offset: 0x858
	// Line 9076, Address: 0x168274, Func Offset: 0x864
	// Line 9077, Address: 0x168280, Func Offset: 0x870
	// Line 9076, Address: 0x168284, Func Offset: 0x874
	// Line 9077, Address: 0x168288, Func Offset: 0x878
	// Line 9078, Address: 0x168298, Func Offset: 0x888
	// Line 9079, Address: 0x1682a8, Func Offset: 0x898
	// Line 9084, Address: 0x1682b0, Func Offset: 0x8a0
	// Line 9083, Address: 0x1682b8, Func Offset: 0x8a8
	// Line 9084, Address: 0x1682c4, Func Offset: 0x8b4
	// Line 9085, Address: 0x1682d0, Func Offset: 0x8c0
	// Line 9084, Address: 0x1682d4, Func Offset: 0x8c4
	// Line 9085, Address: 0x1682d8, Func Offset: 0x8c8
	// Line 9086, Address: 0x1682dc, Func Offset: 0x8cc
	// Line 9085, Address: 0x1682e4, Func Offset: 0x8d4
	// Line 9086, Address: 0x1682f0, Func Offset: 0x8e0
	// Line 9087, Address: 0x1682fc, Func Offset: 0x8ec
	// Line 9086, Address: 0x168300, Func Offset: 0x8f0
	// Line 9087, Address: 0x168304, Func Offset: 0x8f4
	// Line 9088, Address: 0x168308, Func Offset: 0x8f8
	// Line 9087, Address: 0x168310, Func Offset: 0x900
	// Line 9088, Address: 0x16831c, Func Offset: 0x90c
	// Line 9089, Address: 0x168328, Func Offset: 0x918
	// Line 9088, Address: 0x16832c, Func Offset: 0x91c
	// Line 9089, Address: 0x168330, Func Offset: 0x920
	// Line 9090, Address: 0x168340, Func Offset: 0x930
	// Line 9091, Address: 0x168350, Func Offset: 0x940
	// Line 9099, Address: 0x168358, Func Offset: 0x948
	// Line 9101, Address: 0x168360, Func Offset: 0x950
	// Line 9099, Address: 0x168364, Func Offset: 0x954
	// Line 9100, Address: 0x168380, Func Offset: 0x970
	// Line 9101, Address: 0x16838c, Func Offset: 0x97c
	// Line 9100, Address: 0x168390, Func Offset: 0x980
	// Line 9101, Address: 0x168394, Func Offset: 0x984
	// Line 9102, Address: 0x16839c, Func Offset: 0x98c
	// Line 9101, Address: 0x1683a0, Func Offset: 0x990
	// Line 9102, Address: 0x1683a4, Func Offset: 0x994
	// Line 9104, Address: 0x1683ac, Func Offset: 0x99c
	// Line 9102, Address: 0x1683b0, Func Offset: 0x9a0
	// Line 9104, Address: 0x1683b4, Func Offset: 0x9a4
	// Line 9106, Address: 0x1683b8, Func Offset: 0x9a8
	// Line 9104, Address: 0x1683c0, Func Offset: 0x9b0
	// Line 9105, Address: 0x1683cc, Func Offset: 0x9bc
	// Line 9106, Address: 0x1683d4, Func Offset: 0x9c4
	// Line 9105, Address: 0x1683d8, Func Offset: 0x9c8
	// Line 9107, Address: 0x1683dc, Func Offset: 0x9cc
	// Line 9106, Address: 0x1683e0, Func Offset: 0x9d0
	// Line 9107, Address: 0x1683e4, Func Offset: 0x9d4
	// Line 9109, Address: 0x1683e8, Func Offset: 0x9d8
	// Line 9107, Address: 0x1683f0, Func Offset: 0x9e0
	// Line 9108, Address: 0x1683fc, Func Offset: 0x9ec
	// Line 9109, Address: 0x168404, Func Offset: 0x9f4
	// Line 9108, Address: 0x168408, Func Offset: 0x9f8
	// Line 9110, Address: 0x16840c, Func Offset: 0x9fc
	// Line 9109, Address: 0x168410, Func Offset: 0xa00
	// Line 9110, Address: 0x168414, Func Offset: 0xa04
	// Line 9112, Address: 0x168418, Func Offset: 0xa08
	// Line 9110, Address: 0x168420, Func Offset: 0xa10
	// Line 9111, Address: 0x16842c, Func Offset: 0xa1c
	// Line 9112, Address: 0x168434, Func Offset: 0xa24
	// Line 9111, Address: 0x168438, Func Offset: 0xa28
	// Line 9113, Address: 0x16843c, Func Offset: 0xa2c
	// Line 9112, Address: 0x168440, Func Offset: 0xa30
	// Line 9113, Address: 0x168444, Func Offset: 0xa34
	// Line 9115, Address: 0x168448, Func Offset: 0xa38
	// Line 9113, Address: 0x168450, Func Offset: 0xa40
	// Line 9114, Address: 0x16845c, Func Offset: 0xa4c
	// Line 9115, Address: 0x168464, Func Offset: 0xa54
	// Line 9114, Address: 0x168468, Func Offset: 0xa58
	// Line 9116, Address: 0x16846c, Func Offset: 0xa5c
	// Line 9115, Address: 0x168470, Func Offset: 0xa60
	// Line 9116, Address: 0x168474, Func Offset: 0xa64
	// Line 9118, Address: 0x168480, Func Offset: 0xa70
	// Line 9125, Address: 0x168488, Func Offset: 0xa78
	// Line 9127, Address: 0x168490, Func Offset: 0xa80
	// Line 9125, Address: 0x168494, Func Offset: 0xa84
	// Line 9126, Address: 0x1684b0, Func Offset: 0xaa0
	// Line 9127, Address: 0x1684bc, Func Offset: 0xaac
	// Line 9126, Address: 0x1684c0, Func Offset: 0xab0
	// Line 9127, Address: 0x1684c4, Func Offset: 0xab4
	// Line 9129, Address: 0x1684cc, Func Offset: 0xabc
	// Line 9127, Address: 0x1684d0, Func Offset: 0xac0
	// Line 9129, Address: 0x1684d4, Func Offset: 0xac4
	// Line 9131, Address: 0x1684d8, Func Offset: 0xac8
	// Line 9129, Address: 0x1684e0, Func Offset: 0xad0
	// Line 9130, Address: 0x1684ec, Func Offset: 0xadc
	// Line 9131, Address: 0x1684f4, Func Offset: 0xae4
	// Line 9130, Address: 0x1684f8, Func Offset: 0xae8
	// Line 9132, Address: 0x1684fc, Func Offset: 0xaec
	// Line 9131, Address: 0x168500, Func Offset: 0xaf0
	// Line 9132, Address: 0x168504, Func Offset: 0xaf4
	// Line 9133, Address: 0x168514, Func Offset: 0xb04
	// Line 9135, Address: 0x168524, Func Offset: 0xb14
	// Line 9142, Address: 0x16852c, Func Offset: 0xb1c
	// Line 9146, Address: 0x168538, Func Offset: 0xb28
	// Line 9142, Address: 0x16853c, Func Offset: 0xb2c
	// Line 9143, Address: 0x168540, Func Offset: 0xb30
	// Line 9142, Address: 0x168544, Func Offset: 0xb34
	// Line 9143, Address: 0x168548, Func Offset: 0xb38
	// Line 9145, Address: 0x168568, Func Offset: 0xb58
	// Line 9146, Address: 0x168574, Func Offset: 0xb64
	// Line 9145, Address: 0x168578, Func Offset: 0xb68
	// Line 9146, Address: 0x16857c, Func Offset: 0xb6c
	// Line 9147, Address: 0x168584, Func Offset: 0xb74
	// Line 9146, Address: 0x168588, Func Offset: 0xb78
	// Line 9147, Address: 0x16858c, Func Offset: 0xb7c
	// Line 9149, Address: 0x168594, Func Offset: 0xb84
	// Line 9147, Address: 0x168598, Func Offset: 0xb88
	// Line 9149, Address: 0x16859c, Func Offset: 0xb8c
	// Line 9151, Address: 0x1685a0, Func Offset: 0xb90
	// Line 9149, Address: 0x1685a8, Func Offset: 0xb98
	// Line 9150, Address: 0x1685b4, Func Offset: 0xba4
	// Line 9151, Address: 0x1685bc, Func Offset: 0xbac
	// Line 9150, Address: 0x1685c0, Func Offset: 0xbb0
	// Line 9152, Address: 0x1685c4, Func Offset: 0xbb4
	// Line 9151, Address: 0x1685c8, Func Offset: 0xbb8
	// Line 9152, Address: 0x1685cc, Func Offset: 0xbbc
	// Line 9154, Address: 0x1685d0, Func Offset: 0xbc0
	// Line 9152, Address: 0x1685d8, Func Offset: 0xbc8
	// Line 9153, Address: 0x1685e4, Func Offset: 0xbd4
	// Line 9154, Address: 0x1685ec, Func Offset: 0xbdc
	// Line 9153, Address: 0x1685f0, Func Offset: 0xbe0
	// Line 9155, Address: 0x1685f4, Func Offset: 0xbe4
	// Line 9154, Address: 0x1685f8, Func Offset: 0xbe8
	// Line 9155, Address: 0x1685fc, Func Offset: 0xbec
	// Line 9157, Address: 0x168600, Func Offset: 0xbf0
	// Line 9155, Address: 0x168608, Func Offset: 0xbf8
	// Line 9156, Address: 0x168614, Func Offset: 0xc04
	// Line 9157, Address: 0x16861c, Func Offset: 0xc0c
	// Line 9156, Address: 0x168620, Func Offset: 0xc10
	// Line 9158, Address: 0x168624, Func Offset: 0xc14
	// Line 9157, Address: 0x168628, Func Offset: 0xc18
	// Line 9158, Address: 0x16862c, Func Offset: 0xc1c
	// Line 9160, Address: 0x168630, Func Offset: 0xc20
	// Line 9158, Address: 0x168638, Func Offset: 0xc28
	// Line 9159, Address: 0x168644, Func Offset: 0xc34
	// Line 9160, Address: 0x16864c, Func Offset: 0xc3c
	// Line 9159, Address: 0x168650, Func Offset: 0xc40
	// Line 9161, Address: 0x168654, Func Offset: 0xc44
	// Line 9160, Address: 0x168658, Func Offset: 0xc48
	// Line 9161, Address: 0x16865c, Func Offset: 0xc4c
	// Line 9163, Address: 0x168668, Func Offset: 0xc58
	// Line 9170, Address: 0x168670, Func Offset: 0xc60
	// Line 9172, Address: 0x168678, Func Offset: 0xc68
	// Line 9170, Address: 0x16867c, Func Offset: 0xc6c
	// Line 9171, Address: 0x168680, Func Offset: 0xc70
	// Line 9170, Address: 0x168684, Func Offset: 0xc74
	// Line 9171, Address: 0x168688, Func Offset: 0xc78
	// Line 9172, Address: 0x168690, Func Offset: 0xc80
	// Line 9171, Address: 0x168694, Func Offset: 0xc84
	// Line 9172, Address: 0x168698, Func Offset: 0xc88
	// Line 9173, Address: 0x1686a0, Func Offset: 0xc90
	// Line 9172, Address: 0x1686a4, Func Offset: 0xc94
	// Line 9173, Address: 0x1686a8, Func Offset: 0xc98
	// Line 9175, Address: 0x1686b0, Func Offset: 0xca0
	// Line 9173, Address: 0x1686b4, Func Offset: 0xca4
	// Line 9175, Address: 0x1686b8, Func Offset: 0xca8
	// Line 9178, Address: 0x1686bc, Func Offset: 0xcac
	// Line 9175, Address: 0x1686c4, Func Offset: 0xcb4
	// Line 9181, Address: 0x1686c8, Func Offset: 0xcb8
	// Line 9175, Address: 0x1686d0, Func Offset: 0xcc0
	// Line 9178, Address: 0x1686d8, Func Offset: 0xcc8
	// Line 9179, Address: 0x1686dc, Func Offset: 0xccc
	// Line 9181, Address: 0x1686e0, Func Offset: 0xcd0
	// Line 9179, Address: 0x1686e4, Func Offset: 0xcd4
	// Line 9182, Address: 0x1686ec, Func Offset: 0xcdc
	// Line 9179, Address: 0x1686f0, Func Offset: 0xce0
	// Line 9181, Address: 0x1686f8, Func Offset: 0xce8
	// Line 9182, Address: 0x168700, Func Offset: 0xcf0
	// Line 9183, Address: 0x16870c, Func Offset: 0xcfc
	// Line 9184, Address: 0x16871c, Func Offset: 0xd0c
	// Line 9183, Address: 0x168720, Func Offset: 0xd10
	// Line 9184, Address: 0x168724, Func Offset: 0xd14
	// Line 9185, Address: 0x168730, Func Offset: 0xd20
	// Line 9184, Address: 0x168734, Func Offset: 0xd24
	// Line 9185, Address: 0x168738, Func Offset: 0xd28
	// Line 9186, Address: 0x168744, Func Offset: 0xd34
	// Line 9185, Address: 0x168748, Func Offset: 0xd38
	// Line 9186, Address: 0x16874c, Func Offset: 0xd3c
	// Line 9187, Address: 0x168758, Func Offset: 0xd48
	// Line 9186, Address: 0x16875c, Func Offset: 0xd4c
	// Line 9187, Address: 0x168760, Func Offset: 0xd50
	// Line 9189, Address: 0x16876c, Func Offset: 0xd5c
	// Line 9193, Address: 0x168774, Func Offset: 0xd64
	// Line 9201, Address: 0x16877c, Func Offset: 0xd6c
	// Line 9202, Address: 0x168784, Func Offset: 0xd74
	// Line 9193, Address: 0x168788, Func Offset: 0xd78
	// Line 9197, Address: 0x16878c, Func Offset: 0xd7c
	// Line 9193, Address: 0x168790, Func Offset: 0xd80
	// Line 9194, Address: 0x168794, Func Offset: 0xd84
	// Line 9202, Address: 0x168798, Func Offset: 0xd88
	// Line 9193, Address: 0x16879c, Func Offset: 0xd8c
	// Line 9194, Address: 0x1687a0, Func Offset: 0xd90
	// Line 9195, Address: 0x1687a8, Func Offset: 0xd98
	// Line 9194, Address: 0x1687ac, Func Offset: 0xd9c
	// Line 9195, Address: 0x1687b8, Func Offset: 0xda8
	// Line 9197, Address: 0x1687d8, Func Offset: 0xdc8
	// Line 9198, Address: 0x1687e4, Func Offset: 0xdd4
	// Line 9197, Address: 0x1687e8, Func Offset: 0xdd8
	// Line 9198, Address: 0x1687ec, Func Offset: 0xddc
	// Line 9199, Address: 0x1687f4, Func Offset: 0xde4
	// Line 9198, Address: 0x1687f8, Func Offset: 0xde8
	// Line 9199, Address: 0x1687fc, Func Offset: 0xdec
	// Line 9200, Address: 0x168804, Func Offset: 0xdf4
	// Line 9199, Address: 0x168808, Func Offset: 0xdf8
	// Line 9200, Address: 0x16880c, Func Offset: 0xdfc
	// Line 9201, Address: 0x168814, Func Offset: 0xe04
	// Line 9200, Address: 0x168818, Func Offset: 0xe08
	// Line 9201, Address: 0x16881c, Func Offset: 0xe0c
	// Line 9202, Address: 0x168824, Func Offset: 0xe14
	// Line 9201, Address: 0x168828, Func Offset: 0xe18
	// Line 9202, Address: 0x168834, Func Offset: 0xe24
	// Line 9211, Address: 0x168848, Func Offset: 0xe38
	// Line 9212, Address: 0x168854, Func Offset: 0xe44
	// Line 9213, Address: 0x16885c, Func Offset: 0xe4c
	// Line 9212, Address: 0x168864, Func Offset: 0xe54
	// Line 9214, Address: 0x168870, Func Offset: 0xe60
	// Line 9220, Address: 0x168878, Func Offset: 0xe68
	// Line 9219, Address: 0x168880, Func Offset: 0xe70
	// Line 9220, Address: 0x16888c, Func Offset: 0xe7c
	// Line 9221, Address: 0x168898, Func Offset: 0xe88
	// Line 9222, Address: 0x1688ec, Func Offset: 0xedc
	// Line 9223, Address: 0x1688f4, Func Offset: 0xee4
	// Line 9225, Address: 0x168954, Func Offset: 0xf44
	// Line 9226, Address: 0x168974, Func Offset: 0xf64
	// Line 9225, Address: 0x168978, Func Offset: 0xf68
	// Line 9226, Address: 0x16897c, Func Offset: 0xf6c
	// Line 9227, Address: 0x168980, Func Offset: 0xf70
	// Line 9226, Address: 0x168988, Func Offset: 0xf78
	// Line 9227, Address: 0x168994, Func Offset: 0xf84
	// Line 9228, Address: 0x1689a0, Func Offset: 0xf90
	// Line 9229, Address: 0x1689f4, Func Offset: 0xfe4
	// Line 9230, Address: 0x1689fc, Func Offset: 0xfec
	// Line 9232, Address: 0x168a5c, Func Offset: 0x104c
	// Line 9235, Address: 0x168a68, Func Offset: 0x1058
	// Line 9232, Address: 0x168a6c, Func Offset: 0x105c
	// Line 9235, Address: 0x168a74, Func Offset: 0x1064
	// Line 9237, Address: 0x168a90, Func Offset: 0x1080
	// Line 9235, Address: 0x168a94, Func Offset: 0x1084
	// Line 9237, Address: 0x168a98, Func Offset: 0x1088
	// Line 9238, Address: 0x168a9c, Func Offset: 0x108c
	// Line 9237, Address: 0x168aa4, Func Offset: 0x1094
	// Line 9238, Address: 0x168ab0, Func Offset: 0x10a0
	// Line 9239, Address: 0x168abc, Func Offset: 0x10ac
	// Line 9240, Address: 0x168b10, Func Offset: 0x1100
	// Line 9241, Address: 0x168b18, Func Offset: 0x1108
	// Line 9243, Address: 0x168b78, Func Offset: 0x1168
	// Line 9244, Address: 0x168b98, Func Offset: 0x1188
	// Line 9243, Address: 0x168b9c, Func Offset: 0x118c
	// Line 9244, Address: 0x168ba0, Func Offset: 0x1190
	// Line 9246, Address: 0x168bac, Func Offset: 0x119c
	// Line 9248, Address: 0x168bb4, Func Offset: 0x11a4
	// Line 9249, Address: 0x168bbc, Func Offset: 0x11ac
	// Line 9250, Address: 0x168bc4, Func Offset: 0x11b4
	// Line 9252, Address: 0x168bcc, Func Offset: 0x11bc
	// Line 9255, Address: 0x168bd8, Func Offset: 0x11c8
	// Func End, Address: 0x168bec, Func Offset: 0x11dc
}

// 
// Start address: 0x168bf0
unsigned int bhObjCtr()
{
	// Line 9263, Address: 0x168bf0, Func Offset: 0
	// Line 9264, Address: 0x168bf8, Func Offset: 0x8
	// Line 9265, Address: 0x168c08, Func Offset: 0x18
	// Line 9267, Address: 0x168c10, Func Offset: 0x20
	// Line 9266, Address: 0x168c14, Func Offset: 0x24
	// Line 9267, Address: 0x168c18, Func Offset: 0x28
	// Func End, Address: 0x168c20, Func Offset: 0x30
}

// 
// Start address: 0x168c20
int Obj_controll()
{
	unsigned char v0;
	// Line 9275, Address: 0x168c20, Func Offset: 0
	// Line 9285, Address: 0x168c4c, Func Offset: 0x2c
	// Line 9281, Address: 0x168c50, Func Offset: 0x30
	// Line 9285, Address: 0x168c54, Func Offset: 0x34
	// Line 9281, Address: 0x168c58, Func Offset: 0x38
	// Line 9282, Address: 0x168c60, Func Offset: 0x40
	// Line 9285, Address: 0x168c68, Func Offset: 0x48
	// Line 9282, Address: 0x168c70, Func Offset: 0x50
	// Line 9283, Address: 0x168c74, Func Offset: 0x54
	// Line 9285, Address: 0x168c78, Func Offset: 0x58
	// Line 9283, Address: 0x168c7c, Func Offset: 0x5c
	// Line 9285, Address: 0x168c84, Func Offset: 0x64
	// Line 9286, Address: 0x168c90, Func Offset: 0x70
	// Line 9285, Address: 0x168c94, Func Offset: 0x74
	// Line 9286, Address: 0x168cac, Func Offset: 0x8c
	// Line 9288, Address: 0x168ccc, Func Offset: 0xac
	// Line 9292, Address: 0x168cd4, Func Offset: 0xb4
	// Line 9293, Address: 0x168cdc, Func Offset: 0xbc
	// Line 9296, Address: 0x168cf0, Func Offset: 0xd0
	// Func End, Address: 0x168cf8, Func Offset: 0xd8
}

// 
// Start address: 0x168d00
unsigned int bhSubCtr()
{
	// Line 9305, Address: 0x168d00, Func Offset: 0
	// Line 9306, Address: 0x168d08, Func Offset: 0x8
	// Line 9307, Address: 0x168d18, Func Offset: 0x18
	// Line 9309, Address: 0x168d20, Func Offset: 0x20
	// Line 9308, Address: 0x168d24, Func Offset: 0x24
	// Line 9309, Address: 0x168d28, Func Offset: 0x28
	// Func End, Address: 0x168d30, Func Offset: 0x30
}

// 
// Start address: 0x168d30
int Sub_controll()
{
	int v0;
	int v0;
	// Line 9311, Address: 0x168d30, Func Offset: 0
	// Line 9313, Address: 0x168d38, Func Offset: 0x8
	// Line 9317, Address: 0x168db4, Func Offset: 0x84
	// Line 9319, Address: 0x168dc8, Func Offset: 0x98
	// Line 9325, Address: 0x168dd4, Func Offset: 0xa4
	// Line 9321, Address: 0x168ddc, Func Offset: 0xac
	// Line 9319, Address: 0x168de0, Func Offset: 0xb0
	// Line 9326, Address: 0x168df4, Func Offset: 0xc4
	// Line 9319, Address: 0x168dfc, Func Offset: 0xcc
	// Line 9321, Address: 0x168e00, Func Offset: 0xd0
	// Line 9322, Address: 0x168e0c, Func Offset: 0xdc
	// Line 9321, Address: 0x168e10, Func Offset: 0xe0
	// Line 9322, Address: 0x168e14, Func Offset: 0xe4
	// Line 9324, Address: 0x168e1c, Func Offset: 0xec
	// Line 9322, Address: 0x168e20, Func Offset: 0xf0
	// Line 9324, Address: 0x168e24, Func Offset: 0xf4
	// Line 9325, Address: 0x168e2c, Func Offset: 0xfc
	// Line 9324, Address: 0x168e30, Func Offset: 0x100
	// Line 9325, Address: 0x168e34, Func Offset: 0x104
	// Line 9326, Address: 0x168e3c, Func Offset: 0x10c
	// Line 9325, Address: 0x168e40, Func Offset: 0x110
	// Line 9326, Address: 0x168e4c, Func Offset: 0x11c
	// Line 9330, Address: 0x168e5c, Func Offset: 0x12c
	// Line 9331, Address: 0x168e64, Func Offset: 0x134
	// Line 9332, Address: 0x168e70, Func Offset: 0x140
	// Line 9337, Address: 0x168e78, Func Offset: 0x148
	// Line 9338, Address: 0x168e84, Func Offset: 0x154
	// Line 9339, Address: 0x168e8c, Func Offset: 0x15c
	// Line 9338, Address: 0x168e94, Func Offset: 0x164
	// Line 9340, Address: 0x168ea0, Func Offset: 0x170
	// Line 9343, Address: 0x168ea8, Func Offset: 0x178
	// Line 9347, Address: 0x168eb0, Func Offset: 0x180
	// Line 9348, Address: 0x168eb8, Func Offset: 0x188
	// Line 9343, Address: 0x168ebc, Func Offset: 0x18c
	// Line 9344, Address: 0x168ec4, Func Offset: 0x194
	// Line 9345, Address: 0x168ec8, Func Offset: 0x198
	// Line 9348, Address: 0x168ecc, Func Offset: 0x19c
	// Line 9343, Address: 0x168ed0, Func Offset: 0x1a0
	// Line 9344, Address: 0x168ed4, Func Offset: 0x1a4
	// Line 9345, Address: 0x168edc, Func Offset: 0x1ac
	// Line 9344, Address: 0x168ee0, Func Offset: 0x1b0
	// Line 9345, Address: 0x168ee4, Func Offset: 0x1b4
	// Line 9346, Address: 0x168eec, Func Offset: 0x1bc
	// Line 9345, Address: 0x168ef0, Func Offset: 0x1c0
	// Line 9346, Address: 0x168ef4, Func Offset: 0x1c4
	// Line 9347, Address: 0x168efc, Func Offset: 0x1cc
	// Line 9346, Address: 0x168f00, Func Offset: 0x1d0
	// Line 9347, Address: 0x168f04, Func Offset: 0x1d4
	// Line 9348, Address: 0x168f0c, Func Offset: 0x1dc
	// Line 9347, Address: 0x168f10, Func Offset: 0x1e0
	// Line 9348, Address: 0x168f1c, Func Offset: 0x1ec
	// Line 9349, Address: 0x168f24, Func Offset: 0x1f4
	// Line 9348, Address: 0x168f28, Func Offset: 0x1f8
	// Line 9349, Address: 0x168f34, Func Offset: 0x204
	// Line 9350, Address: 0x168f3c, Func Offset: 0x20c
	// Line 9351, Address: 0x168f44, Func Offset: 0x214
	// Line 9350, Address: 0x168f4c, Func Offset: 0x21c
	// Line 9352, Address: 0x168f58, Func Offset: 0x228
	// Line 9355, Address: 0x168f60, Func Offset: 0x230
	// Line 9367, Address: 0x168f68, Func Offset: 0x238
	// Line 9368, Address: 0x168f70, Func Offset: 0x240
	// Line 9355, Address: 0x168f78, Func Offset: 0x248
	// Line 9372, Address: 0x168f88, Func Offset: 0x258
	// Line 9355, Address: 0x168f8c, Func Offset: 0x25c
	// Line 9356, Address: 0x168fa4, Func Offset: 0x274
	// Line 9357, Address: 0x168fac, Func Offset: 0x27c
	// Line 9356, Address: 0x168fb4, Func Offset: 0x284
	// Line 9357, Address: 0x168fc0, Func Offset: 0x290
	// Line 9358, Address: 0x168fd0, Func Offset: 0x2a0
	// Line 9357, Address: 0x168fd4, Func Offset: 0x2a4
	// Line 9358, Address: 0x168fd8, Func Offset: 0x2a8
	// Line 9359, Address: 0x168fdc, Func Offset: 0x2ac
	// Line 9358, Address: 0x168fe4, Func Offset: 0x2b4
	// Line 9359, Address: 0x168ff0, Func Offset: 0x2c0
	// Line 9360, Address: 0x169000, Func Offset: 0x2d0
	// Line 9359, Address: 0x169004, Func Offset: 0x2d4
	// Line 9360, Address: 0x169008, Func Offset: 0x2d8
	// Line 9361, Address: 0x16900c, Func Offset: 0x2dc
	// Line 9360, Address: 0x169014, Func Offset: 0x2e4
	// Line 9361, Address: 0x169020, Func Offset: 0x2f0
	// Line 9362, Address: 0x169030, Func Offset: 0x300
	// Line 9361, Address: 0x169034, Func Offset: 0x304
	// Line 9362, Address: 0x169038, Func Offset: 0x308
	// Line 9363, Address: 0x16903c, Func Offset: 0x30c
	// Line 9362, Address: 0x169044, Func Offset: 0x314
	// Line 9363, Address: 0x169050, Func Offset: 0x320
	// Line 9364, Address: 0x169054, Func Offset: 0x324
	// Line 9363, Address: 0x169058, Func Offset: 0x328
	// Line 9364, Address: 0x16905c, Func Offset: 0x32c
	// Line 9365, Address: 0x169070, Func Offset: 0x340
	// Line 9364, Address: 0x169074, Func Offset: 0x344
	// Line 9365, Address: 0x169078, Func Offset: 0x348
	// Line 9366, Address: 0x16907c, Func Offset: 0x34c
	// Line 9365, Address: 0x169084, Func Offset: 0x354
	// Line 9366, Address: 0x169090, Func Offset: 0x360
	// Line 9367, Address: 0x169094, Func Offset: 0x364
	// Line 9366, Address: 0x169098, Func Offset: 0x368
	// Line 9367, Address: 0x16909c, Func Offset: 0x36c
	// Line 9368, Address: 0x1690a4, Func Offset: 0x374
	// Line 9367, Address: 0x1690a8, Func Offset: 0x378
	// Line 9368, Address: 0x1690b4, Func Offset: 0x384
	// Line 9369, Address: 0x1690bc, Func Offset: 0x38c
	// Line 9368, Address: 0x1690c0, Func Offset: 0x390
	// Line 9369, Address: 0x1690cc, Func Offset: 0x39c
	// Line 9370, Address: 0x1690d4, Func Offset: 0x3a4
	// Line 9372, Address: 0x1690e0, Func Offset: 0x3b0
	// Line 9373, Address: 0x1690f8, Func Offset: 0x3c8
	// Line 9374, Address: 0x1690fc, Func Offset: 0x3cc
	// Line 9373, Address: 0x169100, Func Offset: 0x3d0
	// Line 9374, Address: 0x169104, Func Offset: 0x3d4
	// Line 9376, Address: 0x169134, Func Offset: 0x404
	// Line 9377, Address: 0x169140, Func Offset: 0x410
	// Line 9376, Address: 0x169144, Func Offset: 0x414
	// Line 9377, Address: 0x16914c, Func Offset: 0x41c
	// Line 9378, Address: 0x169154, Func Offset: 0x424
	// Line 9377, Address: 0x169158, Func Offset: 0x428
	// Line 9378, Address: 0x169160, Func Offset: 0x430
	// Line 9380, Address: 0x16916c, Func Offset: 0x43c
	// Line 9383, Address: 0x169174, Func Offset: 0x444
	// Line 9398, Address: 0x16917c, Func Offset: 0x44c
	// Line 9399, Address: 0x169184, Func Offset: 0x454
	// Line 9383, Address: 0x16918c, Func Offset: 0x45c
	// Line 9403, Address: 0x16919c, Func Offset: 0x46c
	// Line 9383, Address: 0x1691a0, Func Offset: 0x470
	// Line 9384, Address: 0x1691b8, Func Offset: 0x488
	// Line 9385, Address: 0x1691c0, Func Offset: 0x490
	// Line 9384, Address: 0x1691c8, Func Offset: 0x498
	// Line 9385, Address: 0x1691d4, Func Offset: 0x4a4
	// Line 9386, Address: 0x1691e4, Func Offset: 0x4b4
	// Line 9385, Address: 0x1691e8, Func Offset: 0x4b8
	// Line 9386, Address: 0x1691ec, Func Offset: 0x4bc
	// Line 9387, Address: 0x1691f0, Func Offset: 0x4c0
	// Line 9386, Address: 0x1691f8, Func Offset: 0x4c8
	// Line 9387, Address: 0x169204, Func Offset: 0x4d4
	// Line 9388, Address: 0x169214, Func Offset: 0x4e4
	// Line 9387, Address: 0x169218, Func Offset: 0x4e8
	// Line 9388, Address: 0x16921c, Func Offset: 0x4ec
	// Line 9389, Address: 0x169220, Func Offset: 0x4f0
	// Line 9388, Address: 0x169228, Func Offset: 0x4f8
	// Line 9389, Address: 0x169234, Func Offset: 0x504
	// Line 9390, Address: 0x169244, Func Offset: 0x514
	// Line 9389, Address: 0x169248, Func Offset: 0x518
	// Line 9390, Address: 0x16924c, Func Offset: 0x51c
	// Line 9391, Address: 0x169250, Func Offset: 0x520
	// Line 9390, Address: 0x169258, Func Offset: 0x528
	// Line 9391, Address: 0x169264, Func Offset: 0x534
	// Line 9392, Address: 0x169274, Func Offset: 0x544
	// Line 9391, Address: 0x169278, Func Offset: 0x548
	// Line 9392, Address: 0x16927c, Func Offset: 0x54c
	// Line 9394, Address: 0x169280, Func Offset: 0x550
	// Line 9392, Address: 0x169288, Func Offset: 0x558
	// Line 9394, Address: 0x169294, Func Offset: 0x564
	// Line 9395, Address: 0x1692a4, Func Offset: 0x574
	// Line 9394, Address: 0x1692a8, Func Offset: 0x578
	// Line 9395, Address: 0x1692ac, Func Offset: 0x57c
	// Line 9397, Address: 0x1692b0, Func Offset: 0x580
	// Line 9395, Address: 0x1692b8, Func Offset: 0x588
	// Line 9397, Address: 0x1692c4, Func Offset: 0x594
	// Line 9398, Address: 0x1692c8, Func Offset: 0x598
	// Line 9397, Address: 0x1692cc, Func Offset: 0x59c
	// Line 9398, Address: 0x1692d0, Func Offset: 0x5a0
	// Line 9399, Address: 0x1692d8, Func Offset: 0x5a8
	// Line 9398, Address: 0x1692dc, Func Offset: 0x5ac
	// Line 9399, Address: 0x1692e8, Func Offset: 0x5b8
	// Line 9400, Address: 0x1692f0, Func Offset: 0x5c0
	// Line 9399, Address: 0x1692f4, Func Offset: 0x5c4
	// Line 9400, Address: 0x169300, Func Offset: 0x5d0
	// Line 9401, Address: 0x169308, Func Offset: 0x5d8
	// Line 9403, Address: 0x169314, Func Offset: 0x5e4
	// Line 9404, Address: 0x16932c, Func Offset: 0x5fc
	// Line 9405, Address: 0x169330, Func Offset: 0x600
	// Line 9404, Address: 0x169334, Func Offset: 0x604
	// Line 9405, Address: 0x169338, Func Offset: 0x608
	// Line 9407, Address: 0x169368, Func Offset: 0x638
	// Line 9408, Address: 0x169374, Func Offset: 0x644
	// Line 9407, Address: 0x169378, Func Offset: 0x648
	// Line 9408, Address: 0x169380, Func Offset: 0x650
	// Line 9410, Address: 0x16938c, Func Offset: 0x65c
	// Line 9413, Address: 0x169394, Func Offset: 0x664
	// Line 9412, Address: 0x16939c, Func Offset: 0x66c
	// Line 9413, Address: 0x1693a8, Func Offset: 0x678
	// Line 9414, Address: 0x1693b8, Func Offset: 0x688
	// Line 9413, Address: 0x1693bc, Func Offset: 0x68c
	// Line 9414, Address: 0x1693c0, Func Offset: 0x690
	// Line 9415, Address: 0x1693c4, Func Offset: 0x694
	// Line 9414, Address: 0x1693cc, Func Offset: 0x69c
	// Line 9415, Address: 0x1693d8, Func Offset: 0x6a8
	// Line 9416, Address: 0x1693e8, Func Offset: 0x6b8
	// Line 9415, Address: 0x1693ec, Func Offset: 0x6bc
	// Line 9416, Address: 0x1693f0, Func Offset: 0x6c0
	// Line 9417, Address: 0x1693f4, Func Offset: 0x6c4
	// Line 9416, Address: 0x1693fc, Func Offset: 0x6cc
	// Line 9417, Address: 0x169408, Func Offset: 0x6d8
	// Line 9418, Address: 0x169418, Func Offset: 0x6e8
	// Line 9417, Address: 0x16941c, Func Offset: 0x6ec
	// Line 9418, Address: 0x169420, Func Offset: 0x6f0
	// Line 9419, Address: 0x169424, Func Offset: 0x6f4
	// Line 9418, Address: 0x16942c, Func Offset: 0x6fc
	// Line 9419, Address: 0x169438, Func Offset: 0x708
	// Line 9420, Address: 0x169448, Func Offset: 0x718
	// Line 9419, Address: 0x16944c, Func Offset: 0x71c
	// Line 9420, Address: 0x169450, Func Offset: 0x720
	// Line 9421, Address: 0x169454, Func Offset: 0x724
	// Line 9420, Address: 0x16945c, Func Offset: 0x72c
	// Line 9421, Address: 0x169468, Func Offset: 0x738
	// Line 9422, Address: 0x169478, Func Offset: 0x748
	// Line 9421, Address: 0x16947c, Func Offset: 0x74c
	// Line 9422, Address: 0x169480, Func Offset: 0x750
	// Line 9423, Address: 0x16948c, Func Offset: 0x75c
	// Line 9438, Address: 0x169494, Func Offset: 0x764
	// Line 9429, Address: 0x16949c, Func Offset: 0x76c
	// Line 9430, Address: 0x1694a8, Func Offset: 0x778
	// Line 9437, Address: 0x1694b4, Func Offset: 0x784
	// Line 9438, Address: 0x1694c0, Func Offset: 0x790
	// Line 9440, Address: 0x1694c8, Func Offset: 0x798
	// Line 9446, Address: 0x1694d0, Func Offset: 0x7a0
	// Line 9447, Address: 0x1694dc, Func Offset: 0x7ac
	// Line 9448, Address: 0x1694e8, Func Offset: 0x7b8
	// Line 9451, Address: 0x1694f0, Func Offset: 0x7c0
	// Line 9452, Address: 0x1694f8, Func Offset: 0x7c8
	// Line 9453, Address: 0x169514, Func Offset: 0x7e4
	// Line 9454, Address: 0x16951c, Func Offset: 0x7ec
	// Line 9457, Address: 0x169534, Func Offset: 0x804
	// Line 9460, Address: 0x16953c, Func Offset: 0x80c
	// Line 9463, Address: 0x169548, Func Offset: 0x818
	// Func End, Address: 0x169554, Func Offset: 0x824
}

// 
// Start address: 0x169560
unsigned int bhCommonCtr()
{
	// Line 9472, Address: 0x169560, Func Offset: 0
	// Line 9473, Address: 0x169568, Func Offset: 0x8
	// Line 9474, Address: 0x169578, Func Offset: 0x18
	// Line 9476, Address: 0x169580, Func Offset: 0x20
	// Line 9475, Address: 0x169584, Func Offset: 0x24
	// Line 9476, Address: 0x169588, Func Offset: 0x28
	// Func End, Address: 0x169590, Func Offset: 0x30
}*/

// 100% matching!
int Common_controll()
{
    switch (*bhScePtr)
    {
        case 53:
        {
            int v0; 
            
            bhScePtr++;
            v0 = bhScePtr[0];
            bhScePtr += 2;
            bhCetask->work->mtn_md |= 0x20;
            if (bhCetask->work->id == 0x1) 
            {
                ((BH_PWORK *)bhCetask->work->exp1)->mtn_md |= 0x20;
            }
            if (v0 == 0) 
            {
                bhCetask->work->mtn_md |= 0x8;
                if (bhCetask->work->id == 0x1) 
                {
                    ((BH_PWORK *)bhCetask->work->exp1)->mtn_md |= 0x8;
                }
            } 
            else 
            {
                bhCetask->work->mtn_md &= ~8;
                if (bhCetask->work->id == 0x1) 
                {
                    ((BH_PWORK *)bhCetask->work->exp1)->mtn_md &= ~8;
                }
            }
        }
        break;
        case 51:
        {
            int v0; 
            int v1; 
            int v2; 
            BH_PWORK* epw; 
            NO_NAME_28* e_posp; 
            NO_NAME_26* temp; // not from the debugging symbols
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            v2 = *bhScePtr;
            bhScePtr += 2;
            temp = &rom->enep[v0];
            
            epw = &ene[temp->wrk_no];
            e_posp = rom->posp;
            e_posp += sys->evt_posno[v2];
            bhCetask->ips[0x0][0x0] = epw->mlwP->owP[v1].mtx[0xc];
            bhCetask->ips[0x0][0x1] = epw->mlwP->owP[v1].mtx[0xd];
            bhCetask->ips[0x0][0x2] = epw->mlwP->owP[v1].mtx[0xe];
            bhCetask->ips[0x1][0x0] = epw->mlwP->owP[v1].mtx[0xc];
            bhCetask->ips[0x1][0x1] = epw->mlwP->owP[v1].mtx[0xd];
            bhCetask->ips[0x1][0x2] = epw->mlwP->owP[v1].mtx[0xe];
            bhCetask->ips[0x2][0x0] = e_posp->px - (e_posp->px - epw->mlwP->owP[v1].mtx[0xc]) / 2.0f;
            bhCetask->ips[0x2][0x1] = e_posp->py;
            bhCetask->ips[0x2][0x2] = e_posp->pz - (e_posp->pz - epw->mlwP->owP[v1].mtx[0xe]) / 2.0f;
            bhCetask->ips[0x3][0x0] = epw->mlwP->owP[v1].mtx[0xc];
            bhCetask->ips[0x3][0x1] = epw->mlwP->owP[v1].mtx[0xd] * -1.0f;
            bhCetask->ips[0x3][0x2] = epw->mlwP->owP[v1].mtx[0xe];
        }
        break;
        case 52:
        {
            int v0; 
            NO_NAME_28* e_posp; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            bhScePtr += 2;
            e_posp = rom->posp;
            e_posp += sys->evt_posno[v0];
            bhCetask->ips[0x0][0x0] = bhCetask->work->px;
            bhCetask->ips[0x0][0x1] = bhCetask->work->py;
            bhCetask->ips[0x0][0x2] = bhCetask->work->pz;
            bhCetask->ips[0x1][0x0] = e_posp->px;
            bhCetask->ips[0x1][0x1] = e_posp->py;
            bhCetask->ips[0x1][0x2] = e_posp->pz;
        }
        break;
        case 50:
            bhScePtr++;
            *(unsigned char *)&bhCetask->work->type = *bhScePtr;
            bhScePtr += 2;
        break;
        case 47:
            bhScePtr++;
            bhCalcModel(bhCetask->work);
        break;
        case 43:
        {
            float ips_w[4][3]; 
            float ian_w[4][3]; 
            float ans[3]; 
            float frm; 
            int v0;
            int v1; 
            int v2; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            v2 = *bhScePtr++;
            ips_w[0x0][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x1][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x2][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x3][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x0][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x1][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x2][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x3][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x0][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x1][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x2][0x2] = bhCetask->ips[0x0][0x2];
            ips_w[0x3][0x2] = bhCetask->ips[0x0][0x2];
            ian_w[0x0][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x1][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x2][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x3][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x0][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x1][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x2][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x3][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x0][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x1][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x2][0x2] = bhCetask->ian[0x0][0x2];
            ian_w[0x3][0x2] = bhCetask->ian[0x0][0x2];
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            if (v0 == '\0') 
            {
                njOverhauserSpline(ips_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ips_w[0x1],ans,0,frm);
            }
            
            if (bhCetask->model_cno == 0x0) 
            {
                if ((v1 & 0x1) != 0x0) 
                {
                    bhCetask->work->px = ans[0x0];
                }
                if ((v1 & 0x2) != 0x0) 
                {
                    bhCetask->work->py = ans[0x1];
                }
                if ((v1 & 0x4) != 0x0) 
                {
                    bhCetask->work->pz = ans[0x2];
                }
            }
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                if ((v1 & 0x1) != 0x0) 
                {
                    objP->pos[0x0] = ans[0x0];
                }
                if ((v1 & 0x2) != 0x0) 
                {
                    objP->pos[0x1] = ans[0x1];
                }
                if ((v1 & 0x4) != 0x0) 
                {
                    objP->pos[0x2] = ans[0x2];
                }
            }
            if (v0 == '\0')
            {
                njOverhauserSpline(ian_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ian_w[0x1],ans,0,frm);
            }
                
            if (bhCetask->model_cno == 0x0) 
            {
                if ((v2 & 0x1) != 0x0) 
                {
                    bhCetask->work->ax = ans[0x0] * 182.04445f;
                }
                if ((v2 & 0x2) != 0x0) 
                {
                    bhCetask->work->ay = ans[0x1] * 182.04445f;
                }
                if ((v2 & 0x4) != 0x0) 
                {
                    bhCetask->work->az = ans[0x2] * 182.04445f;
                }
            }
            else
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                if ((v2 & 0x1) != 0x0) 
                {
                    objP->ang[0x0] = ans[0x0] * 182.04445f;
                }
                if ((v2 & 0x2) != 0x0) 
                {
                    objP->ang[0x1] = ans[0x1] * 182.04445f;
                }
                if ((v2 & 0x4) != 0x0) 
                {
                    objP->ang[0x2] = ans[0x2] * 182.04445f;
                }
            }
        }
        break;
        case 44:
        {
            float ips_w[4][3]; 
            float ans[3]; 
            float frm; 
            int v0; 
            int v1; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            bhScePtr++;
            ips_w[0x0][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x1][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x2][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x3][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x0][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x1][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x2][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x3][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x0][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x1][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x2][0x2] = bhCetask->ips[0x0][0x2];
            ips_w[0x3][0x2] = bhCetask->ips[0x0][0x2];
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            if (v0 == '\0') 
            {
                njOverhauserSpline(ips_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ips_w[1],ans,0,frm);
            }
            
            if (bhCetask->model_cno == 0x0) 
            {
                if ((v1 & 0x1) != 0x0) 
                {
                    bhCetask->work->px = ans[0];
                }
                if ((v1 & 0x2) != 0x0)
                {
                    bhCetask->work->py = ans[1];
                }
                if ((v1 & 0x4) != 0x0) 
                {
                    bhCetask->work->pz = ans[2];
                }
            } 
            else
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                if ((v1 & 0x1) != 0x0) 
                {
                    objP->pos[0] = ans[0];
                }
                if ((v1 & 0x2) != 0x0) 
                {
                    objP->pos[1] = ans[1];
                }
                if ((v1 & 0x4) != 0x0) 
                {
                    objP->pos[2] = ans[2];
                }
            }
        }
        break;
        case 45:
        {
            float ian_w[4][3]; 
            float ans[3]; 
            float frm; 
            int v0; 
            int v1; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            bhScePtr++;
            ian_w[0x0][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x1][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x2][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x3][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x0][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x1][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x2][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x3][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x0][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x1][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x2][0x2] = bhCetask->ian[0x0][0x2];
            ian_w[0x3][0x2] = bhCetask->ian[0x0][0x2];
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            if (v0 == '\0') 
            {
                njOverhauserSpline(ian_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ian_w[1],ans,0,frm);
            }
                
            if (bhCetask->model_cno == 0x0) 
            {
                if ((v1 & 0x1) != 0x0) 
                {
                    bhCetask->work->ax = ans[0] * 182.04445f;
                }
                if ((v1 & 0x2) != 0x0) 
                {
                    bhCetask->work->ay = ans[1] * 182.04445f;
                }
                if ((v1 & 0x4) != 0x0) 
                {
                    bhCetask->work->az = ans[2] * 182.04445f;
                }
            } 
            else
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                if ((v1 & 0x1) != 0x0) 
                {
                    objP->ang[0] = ans[0] * 182.04445f;
                }
                if ((v1 & 0x2) != 0x0) 
                {
                    objP->ang[1] = ans[1] * 182.04445f;
                }
                if ((v1 & 0x4) != 0x0)
                {
                    objP->ang[2] = ans[2] * 182.04445f;
                }
            }
        }
        break;
        case 42:
        {
            int v0; 
            int v1; 
            O_WORK* owk; 
            
            owk = bhCetask->work->mdl->owP;
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            owk += v1;
            if (v0 == '\0') 
            {
                owk->flg |= 0x2;
                break;
            }
            else 
            {
                owk->flg &= ~2;
            }
        }
        break;
        case 41:
            bhScePtr++;
            if (*(unsigned short *)bhScePtr == 0x0) 
            {
                bhCetask->work->flg &= ~0x40000;
            }
            else 
            {
                bhCetask->work->flg |= 0x40000;
            }
            bhScePtr += 2;
        break;
        case 46:
            bhScePtr++;
            if (*(unsigned short *)bhScePtr == 0x0) 
            {
                bhCetask->work->flg &= ~0x20;
            }
            else 
            {
                bhCetask->work->flg |= 0x20;
            }
            bhScePtr += 2;
        break;
        case 40:
        {
            int v0; // not from the debugging symbols
            
            bhScePtr++;
            v0 = *(unsigned short *)bhScePtr;
            bhCetask->work->frm_no = v0 << 0x10;
            if (bhCetask->work->id == 0x1) 
            {
                ((BH_PWORK *)bhCetask->work->exp1)->frm_no = v0 << 0x10;
            }
            bhScePtr += 2;
        }
        break;
        case 28:
        {
            float ips_w[4][3]; 
            float ian_w[4][3]; 
            float ans[3]; 
            float frm; 
            int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            ips_w[0x0][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x1][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x2][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x3][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x0][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x1][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x2][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x3][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x0][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x1][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x2][0x2] = bhCetask->ips[0x0][0x2];
            ips_w[0x3][0x2] = bhCetask->ips[0x0][0x2];
            ian_w[0x0][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x1][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x2][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x3][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x0][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x1][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x2][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x3][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x0][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x1][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x2][0x2] = bhCetask->ian[0x0][0x2];
            ian_w[0x3][0x2] = bhCetask->ian[0x0][0x2];
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            if (v0 == '\0') 
            {
                njOverhauserSpline(ips_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ips_w[1],ans,0,frm);
            }
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->work->px = ans[0];
                bhCetask->work->py = ans[1];
                bhCetask->work->pz = ans[2];
            }
            else
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->pos[0] = ans[0];
                objP->pos[1] = ans[1];
                objP->pos[2] = ans[2];
            }
            
            if (v0 == '\0') 
            {
                njOverhauserSpline(ian_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ian_w[1],ans,0,frm);
            }
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->work->ax = ans[0] * 182.04445f;
                bhCetask->work->ay = ans[1] * 182.04445f;
                bhCetask->work->az = ans[2] * 182.04445f;
            } 
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->ang[0] = ans[0] * 182.04445f;
                objP->ang[1] = ans[1] * 182.04445f;
                objP->ang[2] = ans[2] * 182.04445f;
            }
        }
        break;
        case 30:
        {
            float ips_w[4][3]; 
            float ans[3]; 
            float frm; 
            int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            ips_w[0x0][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x1][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x2][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x3][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x0][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x1][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x2][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x3][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x0][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x1][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x2][0x2] = bhCetask->ips[0x0][0x2];
            ips_w[0x3][0x2] = bhCetask->ips[0x0][0x2];
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            if (v0 == '\0') 
            {
                njOverhauserSpline(ips_w[0],ans,0,frm);
            }
            else 
            {
                njLinear(ips_w[1],ans,0,frm);
            }
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->work->px = ans[0];
                bhCetask->work->py = ans[1];
                bhCetask->work->pz = ans[2];
            } 
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->pos[0] = ans[0];
                objP->pos[1] = ans[1];
                objP->pos[2] = ans[2];
            }
        }
        break;
        case 31:
        {
            float ian_w[4][3]; 
            float ans[3]; 
            float frm; 
            int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            ian_w[0x0][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x1][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x2][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x3][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x0][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x1][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x2][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x3][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x0][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x1][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x2][0x2] = bhCetask->ian[0x0][0x2];
            ian_w[0x3][0x2] = bhCetask->ian[0x0][0x2];
            
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            if (v0 == '\0') 
            {
                njOverhauserSpline(ian_w[0],ans,0,frm);
            }
            else
            {
                njLinear(ian_w[1],ans,0,frm);
            }
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->work->ax = ans[0] * 182.04445f;
                bhCetask->work->ay = ans[1] * 182.04445f;
                bhCetask->work->az = ans[2] * 182.04445f;
            } 
            else
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->ang[0] = ans[0] * 182.04445f;
                objP->ang[1] = ans[1] * 182.04445f;
                objP->ang[2] = ans[2] * 182.04445f;
            }
        }
        break;
        case 29:
        {
            float ips_w[4][3]; 
            float ian_w[4][3]; 
            float ans[3]; 
            float frm; 
            
            bhScePtr++;
            bhScePtr++;
            ips_w[0x0][0x0] = bhCetask->ips[0x3][0x0];
            ips_w[0x1][0x0] = bhCetask->ips[0x2][0x0];
            ips_w[0x2][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x3][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x0][0x1] = bhCetask->ips[0x3][0x1];
            ips_w[0x1][0x1] = bhCetask->ips[0x2][0x1];
            ips_w[0x2][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x3][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x0][0x2] = bhCetask->ips[0x3][0x2];
            ips_w[0x1][0x2] = bhCetask->ips[0x2][0x2];
            ips_w[0x2][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x3][0x2] = bhCetask->ips[0x0][0x2];
            ian_w[0x0][0x0] = bhCetask->ian[0x3][0x0];
            ian_w[0x1][0x0] = bhCetask->ian[0x2][0x0];
            ian_w[0x2][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x3][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x0][0x1] = bhCetask->ian[0x3][0x1];
            ian_w[0x1][0x1] = bhCetask->ian[0x2][0x1];
            ian_w[0x2][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x3][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x0][0x2] = bhCetask->ian[0x3][0x2];
            ian_w[0x1][0x2] = bhCetask->ian[0x2][0x2];
            ian_w[0x2][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x3][0x2] = bhCetask->ian[0x0][0x2];
            frm = 1.0f / bhCetask->cnt3 * bhCetask->cnt2;
            njOverhauserSpline(ips_w[0],ans,0,frm);
            
            if (bhCetask->model_cno == 0x0)
            {
                bhCetask->work->px = ans[0];
                bhCetask->work->py = ans[1];
                bhCetask->work->pz = ans[2];
            }
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->pos[0] = ans[0];
                objP->pos[1] = ans[1];
                objP->pos[2] = ans[2];
            }
            
            njOverhauserSpline(ian_w[0],ans,0,frm); 
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->work->ax = ans[0] * 182.04445f;
                bhCetask->work->ay = ans[1] * 182.04445f;
                bhCetask->work->az = ans[2] * 182.04445f;
            } 
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->ang[0] = ans[0] * 182.04445f;
                objP->ang[1] = ans[1] * 182.04445f;
                objP->ang[2] = ans[2] * 182.04445f;
            }
        }
        break;
        case 32:
        {
            float ips_w[4][3]; 
            float ans[3]; 

            bhScePtr++;
            bhScePtr++;
            ips_w[0x0][0x0] = bhCetask->ips[0x3][0x0];
            ips_w[0x1][0x0] = bhCetask->ips[0x2][0x0];
            ips_w[0x2][0x0] = bhCetask->ips[0x1][0x0];
            ips_w[0x3][0x0] = bhCetask->ips[0x0][0x0];
            ips_w[0x0][0x1] = bhCetask->ips[0x3][0x1];
            ips_w[0x1][0x1] = bhCetask->ips[0x2][0x1];
            ips_w[0x2][0x1] = bhCetask->ips[0x1][0x1];
            ips_w[0x3][0x1] = bhCetask->ips[0x0][0x1];
            ips_w[0x0][0x2] = bhCetask->ips[0x3][0x2];
            ips_w[0x1][0x2] = bhCetask->ips[0x2][0x2];
            ips_w[0x2][0x2] = bhCetask->ips[0x1][0x2];
            ips_w[0x3][0x2] = bhCetask->ips[0x0][0x2];
            
            njOverhauserSpline(ips_w[0],ans,0,1.0f / bhCetask->cnt3 * bhCetask->cnt2);
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->work->px = ans[0];
                bhCetask->work->py = ans[1];
                bhCetask->work->pz = ans[2];
            } 
            else 
            {
                NJS_CNK_OBJECT* objP;
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->pos[0] = ans[0];
                objP->pos[1] = ans[1];
                objP->pos[2] = ans[2];
            }
        }
        break;
        case 33:
        {
            float ian_w[4][3]; 
            float ans[3]; 
            
            bhScePtr++;
            bhScePtr++;
            ian_w[0x0][0x0] = bhCetask->ian[0x3][0x0];
            ian_w[0x1][0x0] = bhCetask->ian[0x2][0x0];
            ian_w[0x2][0x0] = bhCetask->ian[0x1][0x0];
            ian_w[0x3][0x0] = bhCetask->ian[0x0][0x0];
            ian_w[0x0][0x1] = bhCetask->ian[0x3][0x1];
            ian_w[0x1][0x1] = bhCetask->ian[0x2][0x1];
            ian_w[0x2][0x1] = bhCetask->ian[0x1][0x1];
            ian_w[0x3][0x1] = bhCetask->ian[0x0][0x1];
            ian_w[0x0][0x2] = bhCetask->ian[0x3][0x2];
            ian_w[0x1][0x2] = bhCetask->ian[0x2][0x2];
            ian_w[0x2][0x2] = bhCetask->ian[0x1][0x2];
            ian_w[0x3][0x2] = bhCetask->ian[0x0][0x2];
            
            njOverhauserSpline(ian_w[0],ans,0,1.0f / bhCetask->cnt3 * bhCetask->cnt2);
            
            if (bhCetask->model_cno == 0x0) 
            { 
                bhCetask->work->ax = ans[0] * 182.04445f;
                bhCetask->work->ay = ans[1] * 182.04445f;
                bhCetask->work->az = ans[2] * 182.04445f;
            } 
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                objP->ang[0] = ans[0] * 182.04445f;
                objP->ang[1] = ans[1] * 182.04445f;
                objP->ang[2] = ans[2] * 182.04445f;
            }
        }
        break;
        case 26:
        {
            int v0; 
            int v1; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            
            if (v1 & 0x1)
            {
                bhCetask->ips[v0][0x0] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            else 
            {
                bhCetask->ips[v0][0x0] = *(unsigned short *)bhScePtr / 100.0f;
            }
            bhScePtr += 2;
            
            if (v1 & 0x2) 
            {
                bhCetask->ips[v0][0x1] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            else 
            {
                bhCetask->ips[v0][0x1] = *(unsigned short *)bhScePtr / 100.0f;
            }
            bhScePtr += 2;
            
            if (v1 & 0x4) 
            {
                bhCetask->ips[v0][0x2] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            else 
            {
                bhCetask->ips[v0][0x2] = *(unsigned short *)bhScePtr / 100.0f;
            }
            bhScePtr += 2;
        }
        break;
        case 27:
        {
            int v0; 
            int v1; 
            int v2; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            
            v2 = *bhScePtr;
            if ((v1 & 0x1) != 0x0) 
            {
                v2 = -v2;
            }
            bhCetask->ian[v0][0x0] = v2;
            bhScePtr++;
            
            v2 = *bhScePtr;
            if ((v1 & 0x2) != 0x0) 
            {
                v2 = -v2;
            }
            bhCetask->ian[v0][0x1] = v2;
            bhScePtr++;
            
            v2 = *bhScePtr;
            if ((v1 & 0x4) != 0x0) 
            {
                v2 = -v2;
            }
            bhCetask->ian[v0][0x2] = v2;
            bhScePtr += 2;
        }
        break;
        case 48:
        {
            int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            bhScePtr += 2;
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->ips[v0][0x0] = bhCetask->work->px;
                bhCetask->ips[v0][0x1] = bhCetask->work->py;
                bhCetask->ips[v0][0x2] = bhCetask->work->pz;
            } 
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                bhCetask->ips[v0][0x0] = objP->pos[0];
                bhCetask->ips[v0][0x1] = objP->pos[1];
                bhCetask->ips[v0][0x2] = objP->pos[2];
            }
        }
        break;
        case 49:
        {
            int v0;
            int v1; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            bhCetask->ian[v0][0x0] = *(short *)&bhCetask->work->ax * 0.005493164f;
            bhCetask->ian[v0][0x1] = *(short *)&bhCetask->work->ay * 0.005493164f;
            bhCetask->ian[v0][0x2] = *(short *)&bhCetask->work->az * 0.005493164f;
            
            if (bhCetask->model_cno == 0x0) 
            {
                bhCetask->ian[v0][0x0] = *(short *)&bhCetask->work->ax * 0.005493164f;
                bhCetask->ian[v0][0x1] = *(short *)&bhCetask->work->ay * 0.005493164f;
                bhCetask->ian[v0][0x2] = *(short *)&bhCetask->work->az * 0.005493164f;
            }
            else 
            {
                NJS_CNK_OBJECT* objP; 
                
                objP = bhCetask->work->mdl->objP;
                objP += bhCetask->model_cno;
                bhCetask->ian[v0][0x0] = *(short *)&objP->ang[0] * 0.005493164f;
                bhCetask->ian[v0][0x1] = *(short *)&objP->ang[1] * 0.005493164f;
                bhCetask->ian[v0][0x2] = *(short *)&objP->ang[2] * 0.005493164f;
            }
            
            if (bhCetask->ian[v0][0x0] < 0.0f) 
            {
                bhCetask->ian[v0][0x0] += 360.0f;
            }
            
            if (v1 == '\0') 
            {
                if (bhCetask->ian[v0][0x1] < 0.0f) 
                {
                    bhCetask->ian[v0][0x1] += 360.0f;
                }
            }
            else 
            {
                if (bhCetask->ian[v0][0x1] > 180.0f) 
                {
                    bhCetask->ian[v0][0x1] -= 360.0f;
                }
            }
            
            if (bhCetask->ian[v0][0x2] < 0.0f) 
            {
                bhCetask->ian[v0][0x2] += 360.0f;
            }
        }
        break;
        case 25:
        {
            unsigned int v0; 
            unsigned int t1; 
            
            bhScePtr++;
            switch(*bhScePtr) 
            {
                case 1:
                case 2:
                    bhCetask->work->mtn_add = 0x10000;
                    break;
                case 0:
                case 3:
                case 8:
                    bhCetask->work->mtn_add = 0x8000;
                    break;
                case 4:
                    bhCetask->work->mtn_add = 0x5555;
                    break;
                case 5:
                case 9:
                    bhCetask->work->mtn_add = 0x4000;
                    break;
                case 6:
                    bhCetask->work->mtn_add = 0x3333;
                    break;
                case 7:
                case 10:
                    bhCetask->work->mtn_add = 0x2aaa;
                    break;
                case 11:
                    bhCetask->work->mtn_add = 0x2000;
                    break;
                case 12:
                    bhCetask->work->mtn_add = 0x1999;
                    break;
                case 13:
                    bhCetask->work->mtn_add = 0x1555;
                    break;
                case 14:
                    bhCetask->work->mtn_add = 0x2492;
                    break;
                case 15:
                    bhCetask->work->mtn_add = 0x2000;
                    break;
                case 16:
                    bhCetask->work->mtn_add = 0x1c71;
                    break;
                case 17:
                    bhCetask->work->mtn_add = 0x1999;
                    break;
                case 18:
                    bhCetask->work->mtn_add = 0x1745;
                    break;
                case 19:
                    bhCetask->work->mtn_add = 0x1555;
                    break;
                case 20:
                    bhCetask->work->mtn_add = 0x1249;
                    break;
                case 21:
                    bhCetask->work->mtn_add = 0x1000;
                    break;
                case 22:
                    bhCetask->work->mtn_add = 0xe38;
                    break;
                case 23:
                    bhCetask->work->mtn_add = 0xccc;
                    break;
                case 24:
                    bhCetask->work->mtn_add = 0xba2;
                    break;
                case 25:
                    bhCetask->work->mtn_add = 0xaaa;
                    break;
            }
            
            bhScePtr++;
            switch (*bhScePtr) 
            {
                case 0:
                    bhCetask->work->mnwP = (MN_WORK*)sys->plmthp;
                    bhCetask->work->mode0 = '\a';
                    bhCetask->work->mode2 = '\b';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    bhCetask->work->mode1 = *bhScePtr++;
                    bhCetask->work->ct0 = *bhScePtr++;
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = v0;
                    bhScePtr++;
                    
                    t1 = *bhScePtr;
                    bhCetask->work->ct2 = t1;
                    
                    if (t1 == 0x6) 
                    {
                        bhCetask->work->hokan_count = 0x0;
                        bhCetask->work->mtn_md |= 0x8;
                    } 
                    else 
                    {
                        bhCetask->work->hokan_count = 0x8;
                        bhCetask->work->mtn_md &= ~8;
                    }
                    bhScePtr++;
                    bhCetask->work->frm_no = 0x0;
                break;
                case 1:
                    bhCetask->work->mnwP = sys->emtp[bhCetask->work->id];
                    bhCetask->work->mode0 = '\x01';
                    bhCetask->work->mode2 = '\0';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    t1 = *bhScePtr;
                    *(unsigned char*)&bhCetask->work->mtn_no = t1;
                    bhCetask->work->mode1 = t1;
                    
                    bhCetask->work->mtn_md = bhCetask->mtn_md;
                    bhCetask->work->hokan_rate = bhCetask->hokan_rate;
                    
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mode0 = 6;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x20;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_no = t1 + 0xc8;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x8;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_add = bhCetask->work->mtn_add;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_rate = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_no = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_mode = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->mnwP = sys->emtp[bhCetask->work->id];
                    }
                    
                    bhScePtr++;
                    if (*bhScePtr == '\0') 
                    {
                        bhCetask->work->mode0 = '\x01';
                    } 
                    else 
                    {
                        bhCetask->work->mode0 = '\x05';
                    }
                    
                    bhScePtr++;
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = v0;
                    
                    bhScePtr++;
                    t1 = *bhScePtr;
                    if (t1 > 8) 
                    {
                        bhCetask->work->ct2 = 0xa;
                    } 
                    else 
                    {
                        bhCetask->work->ct2 = t1;
                    }
                    
                    bhScePtr++;
                    if (t1 == 0x6) 
                    {
                        bhCetask->work->hokan_count = 0x0;
                        bhCetask->work->mtn_md |= 8;
                        if (bhCetask->work->id == 0x1)
                        {
                            ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x0;
                        }
                    } 
                    else if (t1 > 0x8) 
                    {
                        bhCetask->work->hokan_count = t1;
                        if (bhCetask->work->id == 0x1) 
                        {
                            ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = t1;
                        }
                    } 
                    else 
                    {
                        bhCetask->work->hokan_count = 0x8;
                        bhCetask->work->mtn_md &= ~8;
                    }
                    bhCetask->work->frm_no = 0x0;
                break;
            }
                
            switch(v0) 
            {
                case 0x0:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x2:
                    bhSetMotion(bhCetask->work,0,0,0);
                    break;
                case 0x3:
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x4:
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x5:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x6:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x7:
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
            }
        }
        break;
        case 35:
        {
            unsigned int v0; 
            unsigned int t1; 
            
            bhScePtr++;
            switch(*bhScePtr)
            {
                case 1:
                case 2:
                    bhCetask->work->mtn_add = 0x10000;
                    break;
                case 0:
                case 3:
                case 8:
                    bhCetask->work->mtn_add = 0x8000;
                    break;
                case 4:
                    bhCetask->work->mtn_add = 0x5555;
                    break;
                case 5:
                case 9:
                    bhCetask->work->mtn_add = 0x4000;
                    break;
                case 6:
                    bhCetask->work->mtn_add = 0x3333;
                    break;
                case 7:
                case 10:
                    bhCetask->work->mtn_add = 0x2aaa;
                    break;
                case 11:
                    bhCetask->work->mtn_add = 0x2000;
                    break;
                case 12:
                    bhCetask->work->mtn_add = 0x1999;
                    break;
                case 13:
                    bhCetask->work->mtn_add = 0x1555;
                    break;
                case 14:
                    bhCetask->work->mtn_add = 0x2492;
                    break;
                case 15:
                    bhCetask->work->mtn_add = 0x2000;
                    break;
                case 16:
                    bhCetask->work->mtn_add = 0x1c71;
                    break;
                case 17:
                    bhCetask->work->mtn_add = 0x1999;
                    break;
                case 18:
                    bhCetask->work->mtn_add = 0x1745;
                    break;
                case 19:
                    bhCetask->work->mtn_add = 0x1555;
                    break;
                case 20:
                    bhCetask->work->mtn_add = 0x1249;
                    break;
                case 21:
                    bhCetask->work->mtn_add = 0x1000;
                    break;
                case 22:
                    bhCetask->work->mtn_add = 0xe38;
                    break;
                case 23:
                    bhCetask->work->mtn_add = 0xccc;
                    break;
                case 24:
                    bhCetask->work->mtn_add = 0xba2;
                    break;
                case 25:
                    bhCetask->work->mtn_add = 0xaaa;
                    break;
            }
            
            bhScePtr++;
            switch (*bhScePtr) 
            {
                case 0:
                    bhCetask->work->mnwP = (MN_WORK*)sys->plmthp;
                    bhCetask->work->mode0 = '\a';
                    bhCetask->work->mode2 = '\b';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    bhCetask->work->mode1 = *bhScePtr;
                    
                    bhScePtr++;
                    bhCetask->work->ct0 = *bhScePtr;
                    
                    bhScePtr++;
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = v0;
                    bhScePtr++;

                    t1 = *bhScePtr;
                    bhCetask->work->ct2 = t1;
                    
                    if (t1 == 0x6) 
                    {
                        bhCetask->work->hokan_count = 0x0;
                    } 
                    else 
                    {
                        bhCetask->work->hokan_count = 0x8;
                    }
                    bhScePtr++;
                    bhCetask->work->frm_no = 0x0;
                break;
                case 1:
                    bhCetask->work->mnwP = sys->emtp[bhCetask->work->id];
                    bhCetask->work->mode0 = '\x01';
                    bhCetask->work->mode2 = '\0';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    t1 = *bhScePtr;
                    *(unsigned char*)&bhCetask->work->mtn_no = t1;
                    bhCetask->work->mode1 = t1;
                    
                    bhCetask->work->mtn_md = bhCetask->mtn_md;
                    bhCetask->work->hokan_rate = bhCetask->hokan_rate;
                    
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mode0 = 6;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x20;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_no = t1 + 1;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x8;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_add = bhCetask->work->mtn_add;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_rate = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_no = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_mode = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->mnwP = sys->emtp[bhCetask->work->id];
                    }
                    
                    bhScePtr++;
                    if (*bhScePtr == '\0') 
                    {
                        bhCetask->work->mode0 = '\x01';
                        *(unsigned char *)&bhCetask->work->ct2 = 0x1;
                    } 
                    else
                    {
                        bhCetask->work->mode0 = '\x05';
                        *(unsigned char *)&bhCetask->work->ct2 = 0x3;
                    }

                    t1 = *bhScePtr;
                    if (bhCetask->bpx == '\0') 
                    {
                        bhCetask->work->ct0 = t1 << 0x10;
                    }
                    else
                    {
                        bhCetask->work->ct0 = (t1 * -1) << 0x10;
                    }
                    
                    bhScePtr++;
                    v0 = *bhScePtr++;
                    bhCetask->work->frm_no = 0x0;
                    bhScePtr += 2;
                break;
            }
            
            switch(v0) 
            {
                case 0x0:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x2:
                    bhSetMotion(bhCetask->work,0,0,0);
                    break;
                case 0x3:
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x4:
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x5:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x6:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x7:
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
            }
        }
        break;
        case 24:
        {
            unsigned int v0; 
            unsigned int t0; 
            unsigned int t1; 
            
            bhCetask->work->mnwP = sys->rmthp;
            bhScePtr++;
            t0 = false;
            switch(*bhScePtr) 
            {
                case 1:
                case 2:
                    t0 = true;
                    bhCetask->work->mtn_add = 0x10000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x20;
                    }
                    break;
                case 0:
                case 3:
                case 8:
                    bhCetask->work->mtn_add = 0x8000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 4:
                    bhCetask->work->mtn_add = 0x5555;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 5:
                case 9:
                    bhCetask->work->mtn_add = 0x4000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 6:
                    bhCetask->work->mtn_add = 0x3333;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 7:
                case 10:
                    bhCetask->work->mtn_add = 0x2aaa;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 11:
                    bhCetask->work->mtn_add = 0x2000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 12:
                    bhCetask->work->mtn_add = 0x1999;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 13:
                    bhCetask->work->mtn_add = 0x1555;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 14:
                    bhCetask->work->mtn_add = 0x2492;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 15:
                    bhCetask->work->mtn_add = 0x2000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 16:
                    bhCetask->work->mtn_add = 0x1c71;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 17:
                    bhCetask->work->mtn_add = 0x1999;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 18:
                    bhCetask->work->mtn_add = 0x1745;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 19:
                    bhCetask->work->mtn_add = 0x1555;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 20:
                    bhCetask->work->mtn_add = 0x1249;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 21:
                    bhCetask->work->mtn_add = 0x1000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 22:
                    bhCetask->work->mtn_add = 0xe38;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 23:
                    bhCetask->work->mtn_add = 0xccc;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 24:
                    bhCetask->work->mtn_add = 0xba2;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 25:
                    bhCetask->work->mtn_add = 0xaaa;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
            }

            bhScePtr++;

            switch(*bhScePtr) 
            {
                case 0:
                    bhCetask->work->mode0 = '\a';
                    bhCetask->work->mode2 = '\b';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    bhCetask->work->mode1 = *bhScePtr++;
                    bhCetask->work->ct0 = *bhScePtr++;
                    
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = *bhScePtr++;
                    
                    t1 = *bhScePtr;
                    bhCetask->work->ct2 = t1;
                    if (!t0) 
                    {
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    
                    if (t1 == 0x6) 
                    {
                        bhCetask->work->hokan_count = 0x0;
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    else
                    {
                        bhCetask->work->hokan_count = 0x8;
                    }
                    
                    bhScePtr++;
                    bhCetask->work->frm_no = 0x0;
                break;
                case 1:
                    bhCetask->work->mode0 = '\x01';
                    bhCetask->work->mode2 = '\0';
                    bhCetask->work->mode3 = '\0';
                    bhScePtr++;
                    t1 = *bhScePtr;
                    *(unsigned char *)&bhCetask->work->mtn_no = t1;
                    bhCetask->work->mode1 = t1;
                    bhCetask->work->mtn_md = 0x20;
                    if (!t0) 
                    {
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    bhCetask->work->hokan_rate = 0x0;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mode0 = '\x06';
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_no = t1 + 0x1;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x8;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_add = bhCetask->work->mtn_add;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_rate = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_no = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_mode = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->mnwP = sys->rmthp;
                    }
                    
                    bhScePtr++;
                    if (*bhScePtr == '\0') 
                    {
                        bhCetask->work->mode0 = '\x01';
                    }
                    else 
                    {
                        bhCetask->work->mode0 = '\x05';
                    }
                    
                    bhScePtr++;
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = *bhScePtr;
                    bhScePtr++;
                    
                    t1 = *bhScePtr;
                    if (t1 > 0x8)
                    {
                        bhCetask->work->ct2 = 0xa;
                    }
                    else 
                    {
                        bhCetask->work->ct2 = t1;
                    }
                    
                    if (t1 == 0x6)
                    {
                        if (bhCetask->work->id == 0x1) 
                        {
                            ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x0;
                        }
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    else if (0x8 < t1) 
                    {
                        bhCetask->work->hokan_count = t1;
                        if (bhCetask->work->id == 0x1)
                        {
                            ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = t1;
                        }
                    }
                    bhScePtr++;
                    bhCetask->work->frm_no = 0x0;
                break;
                case 2:
                case 3:
                    bhScePtr++;
                    t1 = *bhScePtr;
                    bhCetask->work->mode3 = '\x01';
                    bhCetask->work->mtn_md = 0x20;
                    if (!t0)
                    {
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    bhCetask->work->mtn_no = t1;
                    bhCetask->work->hokan_rate = 0x0;
                    bhCetask->work->frm_no = 0x0;
                    bhCetask->work->frm_mode = 0x0;
                    bhScePtr++;
                    bhScePtr++;
                    v0 = *bhScePtr++;
                    t1 = *bhScePtr;
                    bhCetask->work->hokan_count = 0x8;
                    if (t1 == '\x06') 
                    {
                        bhCetask->work->hokan_count = 0x0;
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    bhScePtr++;
                break;
            }
            
            switch(v0) 
            {
                case 0x0:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x1:
                    break;
                case 0x2:
                    bhSetMotion(bhCetask->work,0,0,0);
                    break;
                case 0x3:
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x4:
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x5:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x6:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x7:
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
            }
        }
        break;
        case 34:
        {
            unsigned int v0; 
            unsigned int t0; 
            unsigned int t1; 
            
            bhCetask->work->mnwP = sys->rmthp;
            t0 = false;
            bhScePtr++;
            switch(*bhScePtr) 
            {
                case 1:
                case 2:
                    t0 = true;
                    bhCetask->work->mtn_add = 0x10000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x20;
                    }
                    break;
                case 0:
                case 3:
                case 8:
                    bhCetask->work->mtn_add = 0x8000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 4:
                    bhCetask->work->mtn_add = 0x5555;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 5:
                case 9:
                    bhCetask->work->mtn_add = 0x4000;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 6:
                    bhCetask->work->mtn_add = 0x3333;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 7:
                case 10:
                    bhCetask->work->mtn_add = 0x2aaa;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 11:
                    bhCetask->work->mtn_add = 0x2000;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 12:
                    bhCetask->work->mtn_add = 0x1999;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 13:
                    bhCetask->work->mtn_add = 0x1555;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 14:
                    bhCetask->work->mtn_add = 0x2492;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 15:
                    bhCetask->work->mtn_add = 0x2000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 16:
                    bhCetask->work->mtn_add = 0x1c71;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 17:
                    bhCetask->work->mtn_add = 0x1999;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 18:
                    bhCetask->work->mtn_add = 0x1745;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 19:
                    bhCetask->work->mtn_add = 0x1555;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 20:
                    bhCetask->work->mtn_add = 0x1249;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 21:
                    bhCetask->work->mtn_add = 0x1000;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 22:
                    bhCetask->work->mtn_add = 0xe38;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 23:
                    bhCetask->work->mtn_add = 0xccc;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 24:
                    bhCetask->work->mtn_add = 0xba2;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
                case 25:
                    bhCetask->work->mtn_add = 0xaaa;
                    if (bhCetask->work->id == 0x1)
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_md = 0x28;
                    }
                    break;
            }

            bhScePtr++;

            switch(*bhScePtr) 
            {
                case 0:
                    bhCetask->work->mode0 = '\a';
                    bhCetask->work->mode2 = '\b';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    bhCetask->work->mode1 = *bhScePtr++;
                    bhCetask->work->ct0 = *bhScePtr++;
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = *bhScePtr++;
                    
                    t1 = *bhScePtr;
                    bhCetask->work->ct2 = t1;
                    if (!t0) 
                    {
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    
                    if (t1 == 0x6) 
                    {
                        bhCetask->work->hokan_count = 0x0;
                        bhCetask->work->mtn_md |= 0x8;
                    } 
                    else
                    {
                        bhCetask->work->hokan_count = 0x8;
                    }
                    
                    bhScePtr++;
                    bhCetask->work->frm_no = *(unsigned short *)bhScePtr << 0x10;
                    bhScePtr += 2;
                break;
                case 1:
                    bhCetask->work->mode0 = '\x01';
                    bhCetask->work->mode2 = '\0';
                    bhCetask->work->mode3 = '\0';
                    
                    bhScePtr++;
                    t1 = *bhScePtr;
                    *(unsigned char *)&bhCetask->work->mtn_no = t1;
                    bhCetask->work->mode1 = t1;
                    bhCetask->work->mtn_md = 0x20;
                    
                    if (!t0) 
                    {
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    
                    bhCetask->work->hokan_rate = 0x0;
                    bhScePtr++;
                    if (*bhScePtr == '\0')
                    {
                        bhCetask->work->mode0 = '\x01';
                    }
                    else 
                    {
                        bhCetask->work->mode0 = '\x05';
                    }
                    
                    bhScePtr++;
                    v0 = *bhScePtr;
                    bhCetask->work->ct1 = *bhScePtr++;
                    t1 = *bhScePtr;
                    if (t1 > 8) 
                    {
                        bhCetask->work->ct2 = 0xa;
                    }
                    else 
                    {
                        bhCetask->work->ct2 = t1;
                    }
                    
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x8;
                    }
                    
                    if (t1 == 0x6) 
                    {
                        if (bhCetask->work->id == 0x1) 
                        {
                            ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = 0x0;
                        }
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    else if (0x8 < t1) 
                    {
                        bhCetask->work->hokan_count = t1;
                        if (bhCetask->work->id == 0x1) 
                        {
                            ((BH_PWORK *)bhCetask->work->exp1)->hokan_count = t1;
                        }
                    }
                    
                    bhScePtr++;
                    bhCetask->work->frm_no = *(unsigned short *)bhScePtr << 0x10;
                    if (bhCetask->work->id == 0x1) 
                    {
                        ((BH_PWORK *)bhCetask->work->exp1)->mode0 = '\x06';
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_no = bhCetask->work->mtn_no + 0x1;
                        ((BH_PWORK *)bhCetask->work->exp1)->mtn_add = bhCetask->work->mtn_add;
                        ((BH_PWORK *)bhCetask->work->exp1)->hokan_rate = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_no = bhCetask->work->frm_no;
                        ((BH_PWORK *)bhCetask->work->exp1)->frm_mode = 0x0;
                        ((BH_PWORK *)bhCetask->work->exp1)->mnwP = sys->rmthp;
                    }
                    bhScePtr += 2;
                break;
                case 2:
                case 3:
                    bhScePtr++;
                    t1 = *bhScePtr;
                    bhCetask->work->mode3 = '\x01';
                    bhCetask->work->mtn_md = 0x20;
                    if (!t0) 
                    {
                        bhCetask->work->mtn_md |= 0x8;
                    }
                    bhCetask->work->mtn_no = t1;
                    bhCetask->work->hokan_rate = 0x0;
                    bhCetask->work->frm_no = 0x0;
                    bhCetask->work->frm_mode = 0x0;
                    bhScePtr++;
                    bhScePtr++;
                    v0 = *bhScePtr++;
                    t1 = *bhScePtr;
                    bhCetask->work->hokan_count = 0x8;
                    if (t1 == '\x06') 
                    {
                        bhCetask->work->hokan_count = 0x0;
                        bhCetask->work->mtn_md |=  0x8;
                    }
                    bhScePtr++;
                    bhCetask->work->frm_no = *(unsigned short *)bhScePtr << 0x10;
                    bhScePtr += 2;
                break;
            }
            
            switch(v0) 
            {
                case 0x0:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x2:
                    bhSetMotion(bhCetask->work,0,0,0);
                    break;
                case 0x3:
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x4:
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x5:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcModel(bhCetask->work);
                    break;
                case 0x6:
                    bhSetMotion(bhCetask->work,0,0,0);
                    bhCalcLinkModel(bhCetask->work);
                    break;
                case 0x7:
                    bhCalcModel(bhCetask->work);
                    bhCalcLinkModel(bhCetask->work);
                    break;
            }
        }
        break;
        case 23:
        {
            unsigned int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            bhScePtr += 2;

            switch(v0) 
            {
                case 0:
                bhCetask->work->flg &= ~0x118;
                break;
                case 1:
                bhCetask->work->flg |= 0x118;
                break;
                case 2:
                bhCetask->work->flg &= ~0x18;
                break;
                case 3:
                bhCetask->work->flg |= 0x18;
                break;
            }
        }
        break;
        case 0x5:
            bhScePtr++;
            bhCetask->addpx = *bhScePtr++ * 0.1f;
            bhCetask->addpy = *bhScePtr++ * 0.1f;
            bhCetask->addpz = *bhScePtr++ * 0.1f;
            bhScePtr++;
        break;
        case 0x6:
        {
            unsigned int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            bhCetask->addax = (int)(v0 * 182.04445f) >> 0x1;
            bhScePtr++;
            v0 = *bhScePtr;
            bhCetask->adday = (int)(*bhScePtr * 182.04445f) >> 0x1;
            bhScePtr++;
            v0 = *bhScePtr;
            bhCetask->addaz = (int)(v0 * 182.04445f) >> 0x1;
            bhScePtr++;
            bhScePtr++;
        }
        break;
        case 0xC:
            bhScePtr++;
            bhCetask->bpx = *bhScePtr++;
            bhCetask->bpy = *bhScePtr++;
            bhCetask->bpz = *bhScePtr++;
            bhScePtr++;
        break;
        case 0xD:
            bhScePtr++;
            bhCetask->bax = *bhScePtr++;
            bhCetask->bay = *bhScePtr++;
            bhCetask->baz = *bhScePtr++;
            bhScePtr++;
        break;
        case 7:
            bhScePtr++;
            if (bhCetask->bpx == '\0') 
            {
                bhCetask->work->px = *(unsigned short *)bhScePtr / 100.0f;
            }
            else 
            {
                bhCetask->work->px = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            bhCetask->work->pxb = bhCetask->work->px;
            bhScePtr += 2;
            if (bhCetask->bpy == '\0') 
            {
                bhCetask->work->py = *(unsigned short *)bhScePtr / 100.0f;
            }
            else 
            {
                bhCetask->work->py = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            bhCetask->work->pyb = bhCetask->work->py;
            bhCetask->work->flr_no = bhCheckFloorNum(bhCetask->work->py);
            bhScePtr += 2;
            if (bhCetask->bpz == '\0') 
            {
                bhCetask->work->pz = *(unsigned short *)bhScePtr / 100.0f;
            }
            else 
            {
                bhCetask->work->pz = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            bhCetask->work->pzb = bhCetask->work->pz;
            bhScePtr += 2;
        break;
        case 11:
        {
            int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            if (bhCetask->bax != '\0') 
            {
                v0 = -v0;
            }
            bhCetask->work->ax = v0 * 182.04445f;
            bhCetask->work->axb = bhCetask->work->ax;
            bhScePtr++;
            v0 = *bhScePtr;
            if (bhCetask->bay != '\0') 
            {
                v0 = -v0;
            }
            bhCetask->work->ay = v0 * 182.04445f;
            bhCetask->work->ayb = bhCetask->work->ay;
            bhScePtr++;
            v0 = *bhScePtr;
            if (bhCetask->baz != '\0') 
            {
                v0 = -v0;
            }
            bhCetask->work->az = v0 * 182.04445f;
            bhCetask->work->azb = bhCetask->work->az;
            bhScePtr += 2;
        }
        break;
        case 8:
        {
            NJS_CNK_OBJECT* objP; 
            
            objP = bhCetask->work->mdl->objP;
            objP += bhCetask->model_cno;
            
            bhScePtr++;
            if (bhCetask->bpx == '\0') 
            {
                objP->pos[0] = *(unsigned short *)bhScePtr / 100.0f;
            }
            else
            {
                objP->pos[0] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            bhScePtr += 2;
            if (bhCetask->bpy == '\0') 
            {
                objP->pos[1] = *(unsigned short *)bhScePtr / 100.0f;
            }
            else 
            {
                objP->pos[1] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            bhScePtr += 2;
            if (bhCetask->bpz == '\0')
            {
                objP->pos[2] = *(unsigned short *)bhScePtr / 100.0f;
            }
            else 
            {
                objP->pos[2] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            bhScePtr += 2;
        }
        break;
        case 9:
        {
            int v1; 
            NJS_CNK_OBJECT* objP; 
            
            objP = bhCetask->work->mdl->objP;
            objP += bhCetask->model_cno;
            bhScePtr++;
            v1 = *bhScePtr;
            if (bhCetask->bax != '\0') 
            {
                v1 = -v1;
            }
            objP->ang[0] = v1 * 182.04445f;
            bhScePtr++;
            v1 = *bhScePtr;
            if (bhCetask->bay != '\0') 
            {
                v1 = -v1;
            }
            objP->ang[1] = v1 * 182.04445f;
            bhScePtr++;
            v1 = *bhScePtr;
            if (bhCetask->baz != '\0')
            {
                v1 = -v1;
            }
            objP->ang[2] = v1 * 182.04445f;
            bhScePtr += 2;
        }
        break;
        case 2:
            if (bhCetask->bpx == '\0')
            {
                bhCetask->work->px += bhCetask->addpx;
            }
            else
            {
                bhCetask->work->px -= bhCetask->addpx;
            }
            if (bhCetask->bpy == '\0')
            {
                bhCetask->work->py += bhCetask->addpy;
            }
            else 
            {
                bhCetask->work->py -= bhCetask->addpy;
            }
            if (bhCetask->bpz == '\0') 
            {
                bhCetask->work->pz += bhCetask->addpz;
            }
            else
            {
                bhCetask->work->pz -= bhCetask->addpz;
            }
            bhScePtr++;
            bhScePtr++;
        break;
        case 3:
            if (bhCetask->bax == '\0')
            {
                bhCetask->work->ax += bhCetask->addax;
            }
            else 
            {
                bhCetask->work->ax -= bhCetask->addax;
            }
            if (bhCetask->bay == '\0') 
            {
                bhCetask->work->ay += bhCetask->adday;
            }
            else 
            {
                bhCetask->work->ay -= bhCetask->adday;
            }
            if (bhCetask->baz == '\0')
            {
                bhCetask->work->az += bhCetask->addaz;
            }
            else
            {
                bhCetask->work->az -= bhCetask->addaz;
            }
            bhScePtr++;
            bhScePtr++;
        break;
        case 4:
            if (bhCetask->bpx == '\0') 
            {
                bhCetask->work->px += bhCetask->addpx;
            }
            else 
            {
                bhCetask->work->px -= bhCetask->addpx;
            }
            if (bhCetask->bpy == '\0') 
            {
                bhCetask->work->py += bhCetask->addpy;
            }
            else 
            {
                bhCetask->work->py -= bhCetask->addpy;
            }
            if (bhCetask->bpz == '\0') 
            {
                bhCetask->work->pz += bhCetask->addpz;
            }
            else 
            {
                bhCetask->work->pz -= bhCetask->addpz;
            }
            if (bhCetask->bax == '\0') 
            {
                bhCetask->work->ax += bhCetask->addax;
            }
            else
            {
                bhCetask->work->ax -= bhCetask->addax;
            }
            if (bhCetask->bay == '\0') 
            {
                bhCetask->work->ay += bhCetask->adday;
            }
            else 
            {
                bhCetask->work->ay -= bhCetask->adday;
            }
            if (bhCetask->baz == '\0') 
            {
                bhCetask->work->az += bhCetask->addaz;
            }
            else 
            {
                bhCetask->work->az -= bhCetask->addaz;
            }
            bhScePtr++;
            bhScePtr++;
        break;
        case 17:
        {
            NJS_CNK_OBJECT* objP; 
            
            objP = bhCetask->work->mdl->objP;
            objP += bhCetask->model_cno;
            
            if (bhCetask->bpx == '\0') 
            {
                objP->pos[0] += bhCetask->addpx;
            }
            else 
            {
                objP->pos[0] -= bhCetask->addpx;
            }
            if (bhCetask->bpy == '\0') 
            {
                objP->pos[1] += bhCetask->addpy;
            }
            else 
            {
                objP->pos[1] -= bhCetask->addpy;
            }
            if (bhCetask->bpz == '\0') 
            {
                objP->pos[2] += bhCetask->addpz;
            }
            else
            {
                objP->pos[2] -= bhCetask->addpz;
            }
            bhScePtr++;
            bhScePtr++;
        }
        break;
        case 18:
        {
            NJS_CNK_OBJECT* objP; 
            
            objP = bhCetask->work->mdl->objP;
            objP += bhCetask->model_cno;
            
            if (bhCetask->bax == '\0')
            {
                objP->ang[0] += bhCetask->addax;
            }
            else
            {
                objP->ang[0] -= bhCetask->addax;
            }
            if (bhCetask->bay == '\0') 
            {
                objP->ang[1] += bhCetask->adday;
            }
            else 
            {
                objP->ang[1] -= bhCetask->adday;
            }
            if (bhCetask->baz == '\0')
            {
                objP->ang[2] += bhCetask->addaz;
            }
            else 
            {
                objP->ang[2] -= bhCetask->addaz;
            }
            bhScePtr++;
            bhScePtr++;
        }
        break;
        case 19:
        {
            NJS_CNK_OBJECT* objP; 
            
            objP = bhCetask->work->mdl->objP;
            objP += bhCetask->model_cno;
            if (bhCetask->bpx == '\0') 
            {
                objP->pos[0] += bhCetask->addpx;
            }
            else 
            {
                objP->pos[0] -= bhCetask->addpx;
            }
            if (bhCetask->bpy == '\0') 
            {
                objP->pos[1] += bhCetask->addpy;
            }
            else
            {
                objP->pos[1] -= bhCetask->addpy;
            }
            if (bhCetask->bpz == '\0') 
            {
                objP->pos[2] += bhCetask->addpz;
            }
            else
            {
                objP->pos[2] -= bhCetask->addpz;
            }
            if (bhCetask->bax == '\0') 
            {
                objP->ang[0] += bhCetask->addax;
            }
            else 
            {
                objP->ang[0] -= bhCetask->addax;
            }
            if (bhCetask->bay == '\0') 
            {
                objP->ang[1] += bhCetask->adday;
            }
            else
            {
                objP->ang[1] -= bhCetask->adday;
            }
            if (bhCetask->baz == '\0') 
            {
                objP->ang[2] += bhCetask->addaz;
            }
            else 
            {
                objP->ang[2] -= bhCetask->addaz;
            }
            bhScePtr++;
            bhScePtr++;
        }
        break;
        case 22:
        {
            NJS_CNK_OBJECT* objP; 
            
            objP = bhCetask->work->mdl->objP;
            objP += bhCetask->model_cno;
            
            bhScePtr++;
            switch(*bhScePtr) 
            {
                case 0:
                    bhScePtr += 2;
                    if (bhCetask->bpx == '\0') 
                    {
                        objP->pos[0] = *(unsigned short *)bhScePtr / 100.0f;
                    } 
                    else 
                    {
                        objP->pos[0] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
                    }
                    bhScePtr += 2;
                break;
                case 1:
                    bhScePtr += 2;
                    if (bhCetask->bpy == '\0') 
                    {
                        objP->pos[1] = *(unsigned short *)bhScePtr / 100.0f;
                    } 
                    else 
                    {
                        objP->pos[1] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
                    }
                    bhScePtr += 2;
                break;
                case 2:
                    bhScePtr += 2;
                    if (bhCetask->bpz == '\0') 
                    {
                        objP->pos[2] = *(unsigned short *)bhScePtr / 100.0f;
                    } 
                    else 
                    {
                        objP->pos[2] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
                    }
                    bhScePtr += 2;
                break;
            }
        }
        break;
        case 10:
            bhScePtr++;
            
            switch(*bhScePtr) 
            {
                case 0:
                    bhScePtr += 2;
                    if (bhCetask->bpx == '\0') 
                    {
                        bhCetask->work->px = *(unsigned short *)bhScePtr / 100.0f;
                    } 
                    else 
                    {
                        bhCetask->work->px = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
                    }
                    bhScePtr += 2;
                break;
                case 1:
                    bhScePtr += 2;
                    if (bhCetask->bpy == '\0') 
                    {
                        bhCetask->work->py = *(unsigned short *)bhScePtr / 100.0f;
                    } 
                    else 
                    {
                        bhCetask->work->py = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
                    }
                    bhScePtr += 2;
                break;
                case 2:
                    bhScePtr += 2;
                    if (bhCetask->bpz == '\0') 
                    {
                        bhCetask->work->pz = *(unsigned short *)bhScePtr / 100.0f;
                    } 
                    else 
                    {
                        bhCetask->work->pz = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
                    }
                    bhScePtr += 2;
                break;
            }
        break;
        case 132:
            bhCetask->work->mode0 = '\x01';
            bhCetask->work->mode2 = '\0';
            bhCetask->work->mode3 = '\0';
            
            bhScePtr++;
            bhCetask->work->mode1 = *bhScePtr++;
            
            if (*bhScePtr == '\0') 
            {
                bhCetask->work->mode0 = '\x01';
            }
            else 
            {
                bhCetask->work->mode0 = '\x05';
            }

            bhScePtr++;
            bhCetask->work->ct1 = *bhScePtr++;
            bhCetask->work->ct2 = *bhScePtr++;
        break;
        case 140:
        {
            unsigned int v0; 
            
            bhCetask->work->mode2 = '\0';
            bhCetask->work->mode3 = '\0';
            
            bhScePtr++;
            bhCetask->work->mode1 = *bhScePtr++;
            
            if (*bhScePtr == '\0') 
            {
                bhCetask->work->mode0 = '\x01';
                *(unsigned char *)&bhCetask->work->ct2 = 0x1;
            }
            else 
            {
                bhCetask->work->mode0 = '\x05';
                *(unsigned char *)&bhCetask->work->ct2 = 0x3;
            }
            
            bhScePtr++;
            v0 = *(unsigned short *)bhScePtr;
            if (bhCetask->bpx == '\0') 
            {
                bhCetask->work->ct0 = v0 << 0x10;
            }
            else
            {
                bhCetask->work->ct0 = (v0 * -1) << 0x10;
            }
            
            bhScePtr += 2;
            v0 = *(unsigned short *)bhScePtr;
            if (bhCetask->bpz == '\0') 
            {
                bhCetask->work->ct0 |= v0;
            }
            else 
            {
                bhCetask->work->ct0 |= v0 * -1;
            }
            bhScePtr += 2;
        }
        break;
        case 141:
            bhCetask->work->mode0 = '\x05';
            bhCetask->work->mode2 = '\0';
            bhCetask->work->mode3 = '\0';
            
            bhScePtr++;
            bhCetask->work->mode1 = *bhScePtr++;
            bhCetask->work->ct0 = *bhScePtr++;
            bhCetask->work->ct1 = *bhScePtr++;
            bhCetask->work->ct2 = *bhScePtr++;
        break;
        case 14:
        {
            unsigned int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            bhCetask->work->ct3 = v0;
            bhScePtr++;
            bhScePtr++;
        }
        break;
        case 21:
        {
            unsigned int v0; 
            
            bhScePtr++;
            v0 = *bhScePtr;
            bhCetask->work->ct1 = v0;
            bhScePtr++;
            bhScePtr++;
        }
        break;
        case 15:
        {
            int v0; 
            
            bhScePtr++;
            v0 = (unsigned int)*bhScePtr;
            if (bhCetask->bax != '\0') 
            {
                v0 = -v0;
            }
            bhCetask->work->ax = v0 * 182.04445f;
            bhCetask->work->axb = bhCetask->work->ax;
            bhCetask->work->mlwP->objP->ang[0x0] = v0 * 182.04445f;
            bhScePtr++;
            v0 = (unsigned int)*bhScePtr;
            if (bhCetask->bay != '\0') 
            {
                v0 = -v0;
            }
            bhCetask->work->ay = v0 * 182.04445f;
            bhCetask->work->ayb = bhCetask->work->ay;
            bhCetask->work->mlwP->objP->ang[0x1] = v0 * 182.04445f;
            bhScePtr++;
            v0 = (unsigned int)*bhScePtr;
            if (bhCetask->baz != '\0') 
            {
                v0 = -v0;
            }
            bhCetask->work->az = v0 * 182.04445f;
            bhCetask->work->azb = bhCetask->work->az;
            bhCetask->work->mlwP->objP->ang[0x2] = v0 * 182.04445f;
            bhScePtr += 2;
        }
        break;
        case 16:
        {
            int v0;
            int v1; 
            unsigned char* a0; 
            
            bhScePtr++;
            a0 = bhScePtr;
            
            v0 = a0[0];
            v1 = a0[3];
            if ((v1 & 0x1) != 0x0)
            {
                v0 = -v0;
            }
            bhCetask->work->mlwP->objP[0x1].ang[0x0] = v0 * 182.04445f;
            bhScePtr++;
            v0 = *bhScePtr;
            if ((v1 & 0x2) != 0x0) 
            {
                v0 = -v0;
            }
            bhCetask->work->mlwP->objP[0x1].ang[0x1] = v0 * 182.04445f;
            bhScePtr++;
            v0 = *bhScePtr;
            if ((v1 & 0x4) != 0x0)
            {
                v0 = -v0;
            }
            bhCetask->work->mlwP->objP[0x1].ang[0x2] = v0 * 182.04445f;
            bhScePtr += 2;
        }
        break;
        case 36:
            bhCetask->work->mlwP->objP->pos[0x0] = 0.0f;
            bhCetask->work->mlwP->objP->pos[0x1] = 0.0f;
            bhCetask->work->mlwP->objP->pos[0x2] = 0.0f; 
            bhScePtr++;
        break;
        case 38:
        {
            int v0; 
            int v1; 
            
            bhScePtr++;
            v0 = *bhScePtr++;
            v1 = *bhScePtr++;
            
            if ((v1 & 0x1) != 0x0)
            {
                bhCetask->work->mlwP->objP[v0].pos[0x0] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            else
            {
                bhCetask->work->mlwP->objP[v0].pos[0x0] = *(unsigned short *)bhScePtr / 100.0f;
            }
            bhScePtr += 2;
            if ((v1 & 0x2) != 0x0)
            {
                bhCetask->work->mlwP->objP[v0].pos[0x1] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            else 
            {
                bhCetask->work->mlwP->objP[v0].pos[0x1] = *(unsigned short *)bhScePtr / 100.0f;
            }
            
            bhScePtr += 2;
            if ((v1 & 0x4) != 0x0) 
            {
                bhCetask->work->mlwP->objP[v0].pos[0x2] = (*(unsigned short *)bhScePtr / 100.0f) * -1.0f;
            }
            else 
            {
                bhCetask->work->mlwP->objP[v0].pos[0x2] = *(unsigned short *)bhScePtr / 100.0f;
            }
            bhScePtr += 2;
        }
        break;
        case 0:
            bhScePtr++;
        break;
    }
}

/*// 
// Start address: 0x170cd0
unsigned int bhLoadWork()
{
	unsigned char* a0;
	unsigned char* a0;
	unsigned char* a0;
	_anon21* e_enep;
	unsigned char* a0;
	// Line 12111, Address: 0x170cd0, Func Offset: 0
	// Line 12112, Address: 0x170cd8, Func Offset: 0x8
	// Line 12111, Address: 0x170cdc, Func Offset: 0xc
	// Line 12112, Address: 0x170ce8, Func Offset: 0x18
	// Line 12114, Address: 0x170d30, Func Offset: 0x60
	// Line 12115, Address: 0x170d38, Func Offset: 0x68
	// Line 12118, Address: 0x170d3c, Func Offset: 0x6c
	// Line 12119, Address: 0x170d40, Func Offset: 0x70
	// Line 12114, Address: 0x170d44, Func Offset: 0x74
	// Line 12115, Address: 0x170d50, Func Offset: 0x80
	// Line 12120, Address: 0x170d58, Func Offset: 0x88
	// Line 12115, Address: 0x170d5c, Func Offset: 0x8c
	// Line 12116, Address: 0x170d60, Func Offset: 0x90
	// Line 12115, Address: 0x170d64, Func Offset: 0x94
	// Line 12116, Address: 0x170d68, Func Offset: 0x98
	// Line 12117, Address: 0x170d70, Func Offset: 0xa0
	// Line 12116, Address: 0x170d74, Func Offset: 0xa4
	// Line 12117, Address: 0x170d78, Func Offset: 0xa8
	// Line 12118, Address: 0x170d80, Func Offset: 0xb0
	// Line 12117, Address: 0x170d84, Func Offset: 0xb4
	// Line 12118, Address: 0x170d88, Func Offset: 0xb8
	// Line 12119, Address: 0x170d90, Func Offset: 0xc0
	// Line 12118, Address: 0x170d94, Func Offset: 0xc4
	// Line 12119, Address: 0x170d98, Func Offset: 0xc8
	// Line 12120, Address: 0x170da0, Func Offset: 0xd0
	// Line 12119, Address: 0x170da4, Func Offset: 0xd4
	// Line 12120, Address: 0x170db0, Func Offset: 0xe0
	// Line 12121, Address: 0x170db8, Func Offset: 0xe8
	// Line 12120, Address: 0x170dbc, Func Offset: 0xec
	// Line 12121, Address: 0x170dc8, Func Offset: 0xf8
	// Line 12131, Address: 0x170dd0, Func Offset: 0x100
	// Line 12132, Address: 0x170ddc, Func Offset: 0x10c
	// Line 12131, Address: 0x170de0, Func Offset: 0x110
	// Line 12132, Address: 0x170dec, Func Offset: 0x11c
	// Line 12133, Address: 0x170df8, Func Offset: 0x128
	// Line 12149, Address: 0x170e00, Func Offset: 0x130
	// Line 12143, Address: 0x170e08, Func Offset: 0x138
	// Line 12151, Address: 0x170e0c, Func Offset: 0x13c
	// Line 12149, Address: 0x170e10, Func Offset: 0x140
	// Line 12143, Address: 0x170e14, Func Offset: 0x144
	// Line 12145, Address: 0x170e1c, Func Offset: 0x14c
	// Line 12151, Address: 0x170e24, Func Offset: 0x154
	// Line 12145, Address: 0x170e30, Func Offset: 0x160
	// Line 12149, Address: 0x170e3c, Func Offset: 0x16c
	// Line 12153, Address: 0x170e44, Func Offset: 0x174
	// Line 12149, Address: 0x170e48, Func Offset: 0x178
	// Line 12151, Address: 0x170e58, Func Offset: 0x188
	// Line 12153, Address: 0x170e5c, Func Offset: 0x18c
	// Line 12151, Address: 0x170e60, Func Offset: 0x190
	// Line 12153, Address: 0x170e7c, Func Offset: 0x1ac
	// Line 12154, Address: 0x170e88, Func Offset: 0x1b8
	// Line 12155, Address: 0x170e94, Func Offset: 0x1c4
	// Line 12154, Address: 0x170e98, Func Offset: 0x1c8
	// Line 12155, Address: 0x170ea0, Func Offset: 0x1d0
	// Line 12156, Address: 0x170ea8, Func Offset: 0x1d8
	// Line 12155, Address: 0x170eac, Func Offset: 0x1dc
	// Line 12156, Address: 0x170eb4, Func Offset: 0x1e4
	// Line 12158, Address: 0x170ec0, Func Offset: 0x1f0
	// Line 12172, Address: 0x170ec8, Func Offset: 0x1f8
	// Line 12165, Address: 0x170ed0, Func Offset: 0x200
	// Line 12172, Address: 0x170ed4, Func Offset: 0x204
	// Line 12165, Address: 0x170ed8, Func Offset: 0x208
	// Line 12167, Address: 0x170ee0, Func Offset: 0x210
	// Line 12172, Address: 0x170ee8, Func Offset: 0x218
	// Line 12167, Address: 0x170ef0, Func Offset: 0x220
	// Line 12172, Address: 0x170efc, Func Offset: 0x22c
	// Line 12174, Address: 0x170f24, Func Offset: 0x254
	// Line 12172, Address: 0x170f28, Func Offset: 0x258
	// Line 12174, Address: 0x170f2c, Func Offset: 0x25c
	// Line 12176, Address: 0x170f38, Func Offset: 0x268
	// Line 12189, Address: 0x170f40, Func Offset: 0x270
	// Line 12183, Address: 0x170f48, Func Offset: 0x278
	// Line 12189, Address: 0x170f4c, Func Offset: 0x27c
	// Line 12183, Address: 0x170f50, Func Offset: 0x280
	// Line 12185, Address: 0x170f58, Func Offset: 0x288
	// Line 12189, Address: 0x170f60, Func Offset: 0x290
	// Line 12185, Address: 0x170f68, Func Offset: 0x298
	// Line 12189, Address: 0x170f74, Func Offset: 0x2a4
	// Line 12190, Address: 0x170fa0, Func Offset: 0x2d0
	// Line 12192, Address: 0x170fa8, Func Offset: 0x2d8
	// Line 12205, Address: 0x170fb0, Func Offset: 0x2e0
	// Line 12199, Address: 0x170fb8, Func Offset: 0x2e8
	// Line 12205, Address: 0x170fbc, Func Offset: 0x2ec
	// Line 12199, Address: 0x170fc4, Func Offset: 0x2f4
	// Line 12201, Address: 0x170fcc, Func Offset: 0x2fc
	// Line 12205, Address: 0x170fd4, Func Offset: 0x304
	// Line 12201, Address: 0x170fe0, Func Offset: 0x310
	// Line 12205, Address: 0x170fec, Func Offset: 0x31c
	// Line 12206, Address: 0x171020, Func Offset: 0x350
	// Line 12212, Address: 0x17102c, Func Offset: 0x35c
	// Line 12213, Address: 0x171030, Func Offset: 0x360
	// Func End, Address: 0x171038, Func Offset: 0x368
}

// 
// Start address: 0x171040
unsigned int bhLoadWorkEx()
{
	unsigned char* a0;
	unsigned char* a0;
	unsigned char* a0;
	_anon21* e_enep;
	unsigned char* a0;
	// Line 12222, Address: 0x171040, Func Offset: 0
	// Line 12223, Address: 0x171048, Func Offset: 0x8
	// Line 12222, Address: 0x17104c, Func Offset: 0xc
	// Line 12223, Address: 0x171058, Func Offset: 0x18
	// Line 12225, Address: 0x1710a0, Func Offset: 0x60
	// Line 12226, Address: 0x1710a8, Func Offset: 0x68
	// Line 12229, Address: 0x1710ac, Func Offset: 0x6c
	// Line 12230, Address: 0x1710b0, Func Offset: 0x70
	// Line 12225, Address: 0x1710b4, Func Offset: 0x74
	// Line 12226, Address: 0x1710bc, Func Offset: 0x7c
	// Line 12231, Address: 0x1710c4, Func Offset: 0x84
	// Line 12226, Address: 0x1710c8, Func Offset: 0x88
	// Line 12227, Address: 0x1710cc, Func Offset: 0x8c
	// Line 12228, Address: 0x1710d8, Func Offset: 0x98
	// Line 12229, Address: 0x1710e4, Func Offset: 0xa4
	// Line 12230, Address: 0x1710f0, Func Offset: 0xb0
	// Line 12231, Address: 0x1710fc, Func Offset: 0xbc
	// Line 12230, Address: 0x171100, Func Offset: 0xc0
	// Line 12231, Address: 0x171108, Func Offset: 0xc8
	// Line 12232, Address: 0x171110, Func Offset: 0xd0
	// Line 12231, Address: 0x171114, Func Offset: 0xd4
	// Line 12232, Address: 0x17111c, Func Offset: 0xdc
	// Line 12233, Address: 0x171124, Func Offset: 0xe4
	// Line 12232, Address: 0x171128, Func Offset: 0xe8
	// Line 12233, Address: 0x171130, Func Offset: 0xf0
	// Line 12234, Address: 0x171134, Func Offset: 0xf4
	// Line 12235, Address: 0x171144, Func Offset: 0x104
	// Line 12251, Address: 0x17114c, Func Offset: 0x10c
	// Line 12245, Address: 0x171154, Func Offset: 0x114
	// Line 12251, Address: 0x171158, Func Offset: 0x118
	// Line 12245, Address: 0x17115c, Func Offset: 0x11c
	// Line 12247, Address: 0x171164, Func Offset: 0x124
	// Line 12253, Address: 0x17116c, Func Offset: 0x12c
	// Line 12247, Address: 0x171174, Func Offset: 0x134
	// Line 12251, Address: 0x171180, Func Offset: 0x140
	// Line 12253, Address: 0x171188, Func Offset: 0x148
	// Line 12251, Address: 0x17118c, Func Offset: 0x14c
	// Line 12253, Address: 0x17119c, Func Offset: 0x15c
	// Line 12255, Address: 0x1711a0, Func Offset: 0x160
	// Line 12253, Address: 0x1711a4, Func Offset: 0x164
	// Line 12255, Address: 0x1711c0, Func Offset: 0x180
	// Line 12257, Address: 0x1711cc, Func Offset: 0x18c
	// Line 12258, Address: 0x1711e0, Func Offset: 0x1a0
	// Line 12259, Address: 0x1711f4, Func Offset: 0x1b4
	// Line 12261, Address: 0x171204, Func Offset: 0x1c4
	// Line 12275, Address: 0x17120c, Func Offset: 0x1cc
	// Line 12268, Address: 0x171214, Func Offset: 0x1d4
	// Line 12275, Address: 0x171218, Func Offset: 0x1d8
	// Line 12268, Address: 0x17121c, Func Offset: 0x1dc
	// Line 12270, Address: 0x171224, Func Offset: 0x1e4
	// Line 12275, Address: 0x171238, Func Offset: 0x1f8
	// Line 12277, Address: 0x171268, Func Offset: 0x228
	// Line 12279, Address: 0x171274, Func Offset: 0x234
	// Line 12292, Address: 0x17127c, Func Offset: 0x23c
	// Line 12286, Address: 0x171284, Func Offset: 0x244
	// Line 12292, Address: 0x171288, Func Offset: 0x248
	// Line 12286, Address: 0x17128c, Func Offset: 0x24c
	// Line 12288, Address: 0x171294, Func Offset: 0x254
	// Line 12292, Address: 0x1712a8, Func Offset: 0x268
	// Line 12293, Address: 0x1712d8, Func Offset: 0x298
	// Line 12295, Address: 0x1712dc, Func Offset: 0x29c
	// Line 12308, Address: 0x1712e4, Func Offset: 0x2a4
	// Line 12302, Address: 0x1712ec, Func Offset: 0x2ac
	// Line 12308, Address: 0x1712f0, Func Offset: 0x2b0
	// Line 12302, Address: 0x1712f4, Func Offset: 0x2b4
	// Line 12304, Address: 0x1712fc, Func Offset: 0x2bc
	// Line 12308, Address: 0x171304, Func Offset: 0x2c4
	// Line 12304, Address: 0x17130c, Func Offset: 0x2cc
	// Line 12308, Address: 0x171318, Func Offset: 0x2d8
	// Line 12309, Address: 0x171350, Func Offset: 0x310
	// Line 12313, Address: 0x171358, Func Offset: 0x318
	// Line 12314, Address: 0x17135c, Func Offset: 0x31c
	// Func End, Address: 0x171364, Func Offset: 0x324
}

// 
// Start address: 0x171370
unsigned int bhLoadWork2()
{
	unsigned int tk_no;
	unsigned char* a0;
	_anon21* e_enep;
	unsigned char* a0;
	// Line 12322, Address: 0x171370, Func Offset: 0
	// Line 12323, Address: 0x171378, Func Offset: 0x8
	// Line 12322, Address: 0x17137c, Func Offset: 0xc
	// Line 12323, Address: 0x171388, Func Offset: 0x18
	// Line 12325, Address: 0x1713b8, Func Offset: 0x48
	// Line 12326, Address: 0x1713c0, Func Offset: 0x50
	// Line 12327, Address: 0x1713c4, Func Offset: 0x54
	// Line 12325, Address: 0x1713c8, Func Offset: 0x58
	// Line 12326, Address: 0x1713d4, Func Offset: 0x64
	// Line 12327, Address: 0x1713e0, Func Offset: 0x70
	// Line 12326, Address: 0x1713e4, Func Offset: 0x74
	// Line 12327, Address: 0x1713e8, Func Offset: 0x78
	// Line 12336, Address: 0x1713f0, Func Offset: 0x80
	// Line 12327, Address: 0x1713f4, Func Offset: 0x84
	// Line 12336, Address: 0x171400, Func Offset: 0x90
	// Line 12337, Address: 0x171408, Func Offset: 0x98
	// Line 12336, Address: 0x17140c, Func Offset: 0x9c
	// Line 12337, Address: 0x171418, Func Offset: 0xa8
	// Line 12338, Address: 0x17141c, Func Offset: 0xac
	// Line 12345, Address: 0x171424, Func Offset: 0xb4
	// Line 12347, Address: 0x171434, Func Offset: 0xc4
	// Line 12345, Address: 0x17143c, Func Offset: 0xcc
	// Line 12347, Address: 0x171440, Func Offset: 0xd0
	// Line 12345, Address: 0x171448, Func Offset: 0xd8
	// Line 12347, Address: 0x171458, Func Offset: 0xe8
	// Line 12349, Address: 0x171474, Func Offset: 0x104
	// Line 12357, Address: 0x17147c, Func Offset: 0x10c
	// Line 12360, Address: 0x171480, Func Offset: 0x110
	// Line 12358, Address: 0x171488, Func Offset: 0x118
	// Line 12360, Address: 0x171490, Func Offset: 0x120
	// Line 12362, Address: 0x1714b8, Func Offset: 0x148
	// Line 12360, Address: 0x1714c4, Func Offset: 0x154
	// Line 12362, Address: 0x1714dc, Func Offset: 0x16c
	// Line 12360, Address: 0x1714e0, Func Offset: 0x170
	// Line 12362, Address: 0x1714e4, Func Offset: 0x174
	// Line 12366, Address: 0x1714ec, Func Offset: 0x17c
	// Line 12367, Address: 0x1714f4, Func Offset: 0x184
	// Line 12366, Address: 0x1714f8, Func Offset: 0x188
	// Line 12368, Address: 0x171500, Func Offset: 0x190
	// Func End, Address: 0x171508, Func Offset: 0x198
}

// 
// Start address: 0x171510
int Event_init(_anon40* a0, unsigned int evt_id)
{
	// Line 12383, Address: 0x171510, Func Offset: 0
	// Line 12384, Address: 0x171518, Func Offset: 0x8
	// Line 12385, Address: 0x17151c, Func Offset: 0xc
	// Line 12387, Address: 0x171524, Func Offset: 0x14
	// Line 12388, Address: 0x171528, Func Offset: 0x18
	// Line 12385, Address: 0x17152c, Func Offset: 0x1c
	// Line 12387, Address: 0x171530, Func Offset: 0x20
	// Line 12385, Address: 0x171534, Func Offset: 0x24
	// Line 12387, Address: 0x171538, Func Offset: 0x28
	// Line 12388, Address: 0x171554, Func Offset: 0x44
	// Line 12390, Address: 0x171558, Func Offset: 0x48
	// Line 12391, Address: 0x17155c, Func Offset: 0x4c
	// Line 12392, Address: 0x171560, Func Offset: 0x50
	// Line 12393, Address: 0x171564, Func Offset: 0x54
	// Line 12394, Address: 0x171568, Func Offset: 0x58
	// Line 12395, Address: 0x17156c, Func Offset: 0x5c
	// Line 12396, Address: 0x171570, Func Offset: 0x60
	// Line 12397, Address: 0x171574, Func Offset: 0x64
	// Line 12398, Address: 0x171578, Func Offset: 0x68
	// Line 12399, Address: 0x17157c, Func Offset: 0x6c
	// Line 12400, Address: 0x171580, Func Offset: 0x70
	// Line 12401, Address: 0x171584, Func Offset: 0x74
	// Line 12402, Address: 0x171588, Func Offset: 0x78
	// Line 12403, Address: 0x17158c, Func Offset: 0x7c
	// Line 12404, Address: 0x171590, Func Offset: 0x80
	// Line 12405, Address: 0x171594, Func Offset: 0x84
	// Line 12406, Address: 0x171598, Func Offset: 0x88
	// Line 12407, Address: 0x17159c, Func Offset: 0x8c
	// Line 12408, Address: 0x1715a0, Func Offset: 0x90
	// Line 12409, Address: 0x1715a4, Func Offset: 0x94
	// Line 12410, Address: 0x1715a8, Func Offset: 0x98
	// Line 12411, Address: 0x1715ac, Func Offset: 0x9c
	// Line 12412, Address: 0x1715b0, Func Offset: 0xa0
	// Line 12419, Address: 0x1715b4, Func Offset: 0xa4
	// Func End, Address: 0x1715bc, Func Offset: 0xac
}

// 
// Start address: 0x1715c0
int Event_exec(unsigned int task_level, unsigned int evt_id)
{
	// Line 12432, Address: 0x1715c0, Func Offset: 0
	// Line 12435, Address: 0x1715d4, Func Offset: 0x14
	// Line 12436, Address: 0x1715e4, Func Offset: 0x24
	// Line 12437, Address: 0x1715e8, Func Offset: 0x28
	// Line 12438, Address: 0x1715fc, Func Offset: 0x3c
	// Line 12451, Address: 0x171600, Func Offset: 0x40
	// Func End, Address: 0x171618, Func Offset: 0x58
}

// 
// Start address: 0x171620
int bhEventScheduler2()
{
	unsigned int t_time_flg;
	unsigned int level;
	// Line 12464, Address: 0x171620, Func Offset: 0
	// Line 12467, Address: 0x171634, Func Offset: 0x14
	// Line 12469, Address: 0x171654, Func Offset: 0x34
	// Line 12471, Address: 0x171658, Func Offset: 0x38
	// Line 12472, Address: 0x17165c, Func Offset: 0x3c
	// Line 12473, Address: 0x171664, Func Offset: 0x44
	// Line 12474, Address: 0x171670, Func Offset: 0x50
	// Line 12475, Address: 0x171678, Func Offset: 0x58
	// Line 12476, Address: 0x17168c, Func Offset: 0x6c
	// Line 12479, Address: 0x171690, Func Offset: 0x70
	// Line 12477, Address: 0x171698, Func Offset: 0x78
	// Line 12479, Address: 0x17169c, Func Offset: 0x7c
	// Line 12481, Address: 0x1716a0, Func Offset: 0x80
	// Line 12482, Address: 0x1716d0, Func Offset: 0xb0
	// Line 12484, Address: 0x1716e0, Func Offset: 0xc0
	// Line 12483, Address: 0x1716e4, Func Offset: 0xc4
	// Line 12484, Address: 0x1716ec, Func Offset: 0xcc
	// Line 12483, Address: 0x1716f4, Func Offset: 0xd4
	// Line 12485, Address: 0x171704, Func Offset: 0xe4
	// Line 12495, Address: 0x17170c, Func Offset: 0xec
	// Line 12497, Address: 0x171720, Func Offset: 0x100
	// Line 12498, Address: 0x171730, Func Offset: 0x110
	// Func End, Address: 0x171748, Func Offset: 0x128
}

// 
// Start address: 0x171750
void bhScenarioCheck(unsigned char* next_ptr)
{
	// Line 12503, Address: 0x171750, Func Offset: 0
	// Line 12506, Address: 0x171758, Func Offset: 0x8
	// Line 12509, Address: 0x17176c, Func Offset: 0x1c
	// Line 12507, Address: 0x171774, Func Offset: 0x24
	// Line 12513, Address: 0x171788, Func Offset: 0x38
	// Line 12514, Address: 0x1717b8, Func Offset: 0x68
	// Line 12516, Address: 0x1717c8, Func Offset: 0x78
	// Line 12515, Address: 0x1717cc, Func Offset: 0x7c
	// Line 12516, Address: 0x1717d4, Func Offset: 0x84
	// Line 12515, Address: 0x1717dc, Func Offset: 0x8c
	// Line 12517, Address: 0x1717ec, Func Offset: 0x9c
	// Line 12519, Address: 0x1717f4, Func Offset: 0xa4
	// Func End, Address: 0x171800, Func Offset: 0xb0
}

// 
// Start address: 0x171800
unsigned int bhFlagCk(unsigned char type, unsigned int cnt, unsigned char flag)
{
	int* v0;
	// Line 12535, Address: 0x171800, Func Offset: 0
	// Line 12536, Address: 0x17182c, Func Offset: 0x2c
	// Line 12537, Address: 0x17183c, Func Offset: 0x3c
	// Line 12538, Address: 0x17184c, Func Offset: 0x4c
	// Line 12539, Address: 0x17185c, Func Offset: 0x5c
	// Line 12540, Address: 0x17186c, Func Offset: 0x6c
	// Line 12541, Address: 0x17187c, Func Offset: 0x7c
	// Line 12542, Address: 0x17188c, Func Offset: 0x8c
	// Line 12543, Address: 0x17189c, Func Offset: 0x9c
	// Line 12544, Address: 0x1718ac, Func Offset: 0xac
	// Line 12545, Address: 0x1718bc, Func Offset: 0xbc
	// Line 12548, Address: 0x1718c8, Func Offset: 0xc8
	// Line 12549, Address: 0x1718ec, Func Offset: 0xec
	// Func End, Address: 0x1718f4, Func Offset: 0xf4
}

// 
// Start address: 0x171900
unsigned int bhFlagSet(unsigned char type, unsigned int cnt, unsigned char flag)
{
	int v1;
	int* v0;
	// Line 12565, Address: 0x171900, Func Offset: 0
	// Line 12566, Address: 0x17192c, Func Offset: 0x2c
	// Line 12567, Address: 0x17193c, Func Offset: 0x3c
	// Line 12568, Address: 0x17194c, Func Offset: 0x4c
	// Line 12569, Address: 0x17195c, Func Offset: 0x5c
	// Line 12570, Address: 0x17196c, Func Offset: 0x6c
	// Line 12571, Address: 0x17197c, Func Offset: 0x7c
	// Line 12572, Address: 0x17198c, Func Offset: 0x8c
	// Line 12573, Address: 0x17199c, Func Offset: 0x9c
	// Line 12574, Address: 0x1719ac, Func Offset: 0xac
	// Line 12575, Address: 0x1719bc, Func Offset: 0xbc
	// Line 12577, Address: 0x1719c8, Func Offset: 0xc8
	// Line 12579, Address: 0x1719d8, Func Offset: 0xd8
	// Line 12581, Address: 0x171a04, Func Offset: 0x104
	// Line 12583, Address: 0x171a1c, Func Offset: 0x11c
	// Line 12585, Address: 0x171a38, Func Offset: 0x138
	// Line 12587, Address: 0x171a50, Func Offset: 0x150
	// Func End, Address: 0x171a58, Func Offset: 0x158
}

// 
// Start address: 0x171a60
void bhChangeViewClip(char stg_no, char rom_no, char rcase, int evc_no)
{
	float far;
	float near;
	int i;
	_anon2* ViewClipTbl;
	_anon2* ViewClipStage[10];
	// Line 12598, Address: 0x171a60, Func Offset: 0
	// Line 12774, Address: 0x171a74, Func Offset: 0x14
	// Line 12775, Address: 0x171a8c, Func Offset: 0x2c
	// Line 12776, Address: 0x171a94, Func Offset: 0x34
	// Line 12777, Address: 0x171aa0, Func Offset: 0x40
	// Line 12778, Address: 0x171aa8, Func Offset: 0x48
	// Line 12779, Address: 0x171ab0, Func Offset: 0x50
	// Line 12782, Address: 0x171ab8, Func Offset: 0x58
	// Line 12781, Address: 0x171af4, Func Offset: 0x94
	// Line 12782, Address: 0x171af8, Func Offset: 0x98
	// Line 12784, Address: 0x171afc, Func Offset: 0x9c
	// Line 12787, Address: 0x171b20, Func Offset: 0xc0
	// Line 12788, Address: 0x171b30, Func Offset: 0xd0
	// Line 12789, Address: 0x171b34, Func Offset: 0xd4
	// Line 12790, Address: 0x171b3c, Func Offset: 0xdc
	// Line 12794, Address: 0x171b48, Func Offset: 0xe8
	// Line 12799, Address: 0x171b50, Func Offset: 0xf0
	// Line 12802, Address: 0x171b58, Func Offset: 0xf8
	// Line 12803, Address: 0x171b70, Func Offset: 0x110
	// Line 12804, Address: 0x171b88, Func Offset: 0x128
	// Line 12807, Address: 0x171b94, Func Offset: 0x134
	// Func End, Address: 0x171bac, Func Offset: 0x14c
}

// 
// Start address: 0x171bb0
void bhChangeViewClipRM()
{
	int i;
	_anon2* ViewClipTbl;
	_anon2* ViewClipStage[10];
	// Line 12810, Address: 0x171bb0, Func Offset: 0
	// Line 12939, Address: 0x171bb8, Func Offset: 0x8
	// Line 12940, Address: 0x171bc4, Func Offset: 0x14
	// Line 12941, Address: 0x171bd4, Func Offset: 0x24
	// Line 12942, Address: 0x171be8, Func Offset: 0x38
	// Line 12943, Address: 0x171bf8, Func Offset: 0x48
	// Line 12942, Address: 0x171bfc, Func Offset: 0x4c
	// Line 12943, Address: 0x171c00, Func Offset: 0x50
	// Line 12942, Address: 0x171c08, Func Offset: 0x58
	// Line 12943, Address: 0x171c1c, Func Offset: 0x6c
	// Line 12945, Address: 0x171c2c, Func Offset: 0x7c
	// Line 12947, Address: 0x171c44, Func Offset: 0x94
	// Line 12948, Address: 0x171c60, Func Offset: 0xb0
	// Line 12949, Address: 0x171c68, Func Offset: 0xb8
	// Line 12950, Address: 0x171c70, Func Offset: 0xc0
	// Line 12954, Address: 0x171c7c, Func Offset: 0xcc
	// Line 12956, Address: 0x171c84, Func Offset: 0xd4
	// Line 12961, Address: 0x171c90, Func Offset: 0xe0
	// Line 12963, Address: 0x171ca4, Func Offset: 0xf4
	// Line 12964, Address: 0x171ccc, Func Offset: 0x11c
	// Line 12967, Address: 0x171cd8, Func Offset: 0x128
	// Func End, Address: 0x171ce4, Func Offset: 0x134
}

// 
// Start address: 0x171cf0
void bhChangeClipVolume(char stg_no, char rom_no, char rcase, int evc_no)
{
	float y;
	float x;
	int i;
	_anon2* ViewClipTbl;
	_anon2* ViewClipStage[10];
	// Line 13030, Address: 0x171cf0, Func Offset: 0
	// Line 13027, Address: 0x171cfc, Func Offset: 0xc
	// Line 13028, Address: 0x171d08, Func Offset: 0x18
	// Line 13030, Address: 0x171d14, Func Offset: 0x24
	// Line 13029, Address: 0x171d30, Func Offset: 0x40
	// Line 13030, Address: 0x171d34, Func Offset: 0x44
	// Line 13032, Address: 0x171d44, Func Offset: 0x54
	// Line 13035, Address: 0x171d68, Func Offset: 0x78
	// Line 13036, Address: 0x171d78, Func Offset: 0x88
	// Line 13040, Address: 0x171d7c, Func Offset: 0x8c
	// Line 13041, Address: 0x171d84, Func Offset: 0x94
	// Line 13045, Address: 0x171d90, Func Offset: 0xa0
	// Line 13046, Address: 0x171d98, Func Offset: 0xa8
	// Func End, Address: 0x171da0, Func Offset: 0xb0
}

// 
// Start address: 0x171da0
void bhChangeClipVolumeRM()
{
	float y;
	float x;
	int i;
	_anon2* ViewClipTbl;
	_anon2* ViewClipStage[10];
	// Line 13140, Address: 0x171da0, Func Offset: 0
	// Line 13138, Address: 0x171da8, Func Offset: 0x8
	// Line 13141, Address: 0x171db0, Func Offset: 0x10
	// Line 13139, Address: 0x171db4, Func Offset: 0x14
	// Line 13140, Address: 0x171dbc, Func Offset: 0x1c
	// Line 13141, Address: 0x171dc4, Func Offset: 0x24
	// Line 13140, Address: 0x171dcc, Func Offset: 0x2c
	// Line 13141, Address: 0x171de4, Func Offset: 0x44
	// Line 13143, Address: 0x171df4, Func Offset: 0x54
	// Line 13145, Address: 0x171e0c, Func Offset: 0x6c
	// Line 13146, Address: 0x171e1c, Func Offset: 0x7c
	// Line 13150, Address: 0x171e20, Func Offset: 0x80
	// Line 13151, Address: 0x171e28, Func Offset: 0x88
	// Line 13155, Address: 0x171e34, Func Offset: 0x94
	// Line 13156, Address: 0x171e3c, Func Offset: 0x9c
	// Func End, Address: 0x171e44, Func Offset: 0xa4
}*/

