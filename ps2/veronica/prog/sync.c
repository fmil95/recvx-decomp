#include "sync.h"

void(*bhControlEOR)();
void(*bhControlVSync)();
_anon31* sys;
int OpenDriveTrayFlag;
_anon17* rom;
_anon43 cam;
unsigned char BackColorFlag;
int pd_port;
unsigned int palbuf[0];
unsigned char Pause_Flag;
int SoftResetFlag;

// 
// Start address: 0x2ca4c0
void bhInitVSync()
{
	// Line 74, Address: 0x2ca4c0, Func Offset: 0
	// Line 76, Address: 0x2ca4c4, Func Offset: 0x4
	// Line 74, Address: 0x2ca4c8, Func Offset: 0x8
	// Line 76, Address: 0x2ca4cc, Func Offset: 0xc
	// Line 78, Address: 0x2ca4d4, Func Offset: 0x14
	// Line 79, Address: 0x2ca4e0, Func Offset: 0x20
	// Func End, Address: 0x2ca4ec, Func Offset: 0x2c
}

// 
// Start address: 0x2ca4f0
void bhClearVSync()
{
	// Line 85, Address: 0x2ca4f0, Func Offset: 0
	// Line 87, Address: 0x2ca4f8, Func Offset: 0x8
	// Line 89, Address: 0x2ca500, Func Offset: 0x10
	// Line 90, Address: 0x2ca508, Func Offset: 0x18
	// Func End, Address: 0x2ca514, Func Offset: 0x24
}

// 
// Start address: 0x2ca520
void bhControlVSync()
{
	// Line 120, Address: 0x2ca520, Func Offset: 0
	// Line 122, Address: 0x2ca528, Func Offset: 0x8
	// Line 125, Address: 0x2ca530, Func Offset: 0x10
	// Line 126, Address: 0x2ca54c, Func Offset: 0x2c
	// Line 127, Address: 0x2ca570, Func Offset: 0x50
	// Line 128, Address: 0x2ca578, Func Offset: 0x58
	// Line 129, Address: 0x2ca580, Func Offset: 0x60
	// Line 130, Address: 0x2ca594, Func Offset: 0x74
	// Line 152, Address: 0x2ca5b4, Func Offset: 0x94
	// Line 154, Address: 0x2ca5d8, Func Offset: 0xb8
	// Line 155, Address: 0x2ca5fc, Func Offset: 0xdc
	// Line 156, Address: 0x2ca620, Func Offset: 0x100
	// Line 157, Address: 0x2ca624, Func Offset: 0x104
	// Line 158, Address: 0x2ca644, Func Offset: 0x124
	// Line 163, Address: 0x2ca658, Func Offset: 0x138
	// Line 170, Address: 0x2ca670, Func Offset: 0x150
	// Line 171, Address: 0x2ca6a8, Func Offset: 0x188
	// Line 176, Address: 0x2ca6b4, Func Offset: 0x194
	// Line 181, Address: 0x2ca6f8, Func Offset: 0x1d8
	// Line 183, Address: 0x2ca700, Func Offset: 0x1e0
	// Line 185, Address: 0x2ca740, Func Offset: 0x220
	// Line 186, Address: 0x2ca754, Func Offset: 0x234
	// Line 187, Address: 0x2ca768, Func Offset: 0x248
	// Line 189, Address: 0x2ca778, Func Offset: 0x258
	// Line 191, Address: 0x2ca780, Func Offset: 0x260
	// Line 192, Address: 0x2ca794, Func Offset: 0x274
	// Line 193, Address: 0x2ca7a8, Func Offset: 0x288
	// Line 195, Address: 0x2ca7b8, Func Offset: 0x298
	// Line 197, Address: 0x2ca7c0, Func Offset: 0x2a0
	// Line 198, Address: 0x2ca7d4, Func Offset: 0x2b4
	// Line 199, Address: 0x2ca7e8, Func Offset: 0x2c8
	// Line 218, Address: 0x2ca7fc, Func Offset: 0x2dc
	// Func End, Address: 0x2ca808, Func Offset: 0x2e8
}

// 
// Start address: 0x2ca810
void bhControlEOR()
{
	// Line 224, Address: 0x2ca810, Func Offset: 0
	// Line 232, Address: 0x2ca818, Func Offset: 0x8
	// Line 234, Address: 0x2ca83c, Func Offset: 0x2c
	// Line 235, Address: 0x2ca858, Func Offset: 0x48
	// Line 236, Address: 0x2ca860, Func Offset: 0x50
	// Line 235, Address: 0x2ca868, Func Offset: 0x58
	// Line 236, Address: 0x2ca870, Func Offset: 0x60
	// Line 239, Address: 0x2ca87c, Func Offset: 0x6c
	// Line 240, Address: 0x2ca884, Func Offset: 0x74
	// Line 302, Address: 0x2ca8a0, Func Offset: 0x90
	// Line 315, Address: 0x2ca900, Func Offset: 0xf0
	// Line 317, Address: 0x2ca908, Func Offset: 0xf8
	// Line 318, Address: 0x2ca918, Func Offset: 0x108
	// Line 319, Address: 0x2ca930, Func Offset: 0x120
	// Line 320, Address: 0x2ca934, Func Offset: 0x124
	// Line 321, Address: 0x2ca93c, Func Offset: 0x12c
	// Line 323, Address: 0x2ca948, Func Offset: 0x138
	// Line 321, Address: 0x2ca950, Func Offset: 0x140
	// Line 323, Address: 0x2ca958, Func Offset: 0x148
	// Line 324, Address: 0x2ca95c, Func Offset: 0x14c
	// Line 325, Address: 0x2ca974, Func Offset: 0x164
	// Line 327, Address: 0x2ca984, Func Offset: 0x174
	// Line 331, Address: 0x2ca98c, Func Offset: 0x17c
	// Line 333, Address: 0x2ca9a8, Func Offset: 0x198
	// Line 334, Address: 0x2ca9b0, Func Offset: 0x1a0
	// Line 355, Address: 0x2ca9b8, Func Offset: 0x1a8
	// Line 356, Address: 0x2ca9c4, Func Offset: 0x1b4
	// Line 358, Address: 0x2ca9cc, Func Offset: 0x1bc
	// Line 359, Address: 0x2ca9e4, Func Offset: 0x1d4
	// Line 360, Address: 0x2ca9e8, Func Offset: 0x1d8
	// Line 361, Address: 0x2ca9f0, Func Offset: 0x1e0
	// Line 363, Address: 0x2ca9f8, Func Offset: 0x1e8
	// Line 361, Address: 0x2caa00, Func Offset: 0x1f0
	// Line 363, Address: 0x2caa08, Func Offset: 0x1f8
	// Line 364, Address: 0x2caa30, Func Offset: 0x220
	// Line 369, Address: 0x2caa44, Func Offset: 0x234
	// Line 370, Address: 0x2caa64, Func Offset: 0x254
	// Line 371, Address: 0x2caa74, Func Offset: 0x264
	// Line 372, Address: 0x2caa7c, Func Offset: 0x26c
	// Line 374, Address: 0x2caa8c, Func Offset: 0x27c
	// Line 375, Address: 0x2caa94, Func Offset: 0x284
	// Line 377, Address: 0x2caaa4, Func Offset: 0x294
	// Line 378, Address: 0x2caabc, Func Offset: 0x2ac
	// Line 379, Address: 0x2caac0, Func Offset: 0x2b0
	// Line 382, Address: 0x2caac8, Func Offset: 0x2b8
	// Line 384, Address: 0x2cab08, Func Offset: 0x2f8
	// Line 385, Address: 0x2cab30, Func Offset: 0x320
	// Line 390, Address: 0x2cab44, Func Offset: 0x334
	// Line 391, Address: 0x2cab64, Func Offset: 0x354
	// Line 392, Address: 0x2cab74, Func Offset: 0x364
	// Line 393, Address: 0x2cab7c, Func Offset: 0x36c
	// Line 394, Address: 0x2cab8c, Func Offset: 0x37c
	// Line 396, Address: 0x2cab94, Func Offset: 0x384
	// Line 397, Address: 0x2cab9c, Func Offset: 0x38c
	// Line 400, Address: 0x2cabb0, Func Offset: 0x3a0
	// Line 402, Address: 0x2cabb8, Func Offset: 0x3a8
	// Line 403, Address: 0x2cabd4, Func Offset: 0x3c4
	// Line 404, Address: 0x2cabec, Func Offset: 0x3dc
	// Line 408, Address: 0x2cabf4, Func Offset: 0x3e4
	// Line 404, Address: 0x2cabf8, Func Offset: 0x3e8
	// Line 408, Address: 0x2cac00, Func Offset: 0x3f0
	// Line 410, Address: 0x2cac58, Func Offset: 0x448
	// Line 411, Address: 0x2cac84, Func Offset: 0x474
	// Line 415, Address: 0x2cac98, Func Offset: 0x488
	// Line 416, Address: 0x2cacb8, Func Offset: 0x4a8
	// Line 417, Address: 0x2cacc8, Func Offset: 0x4b8
	// Line 418, Address: 0x2cacd0, Func Offset: 0x4c0
	// Line 419, Address: 0x2cace0, Func Offset: 0x4d0
	// Line 421, Address: 0x2cace8, Func Offset: 0x4d8
	// Line 422, Address: 0x2cacf0, Func Offset: 0x4e0
	// Line 428, Address: 0x2cad08, Func Offset: 0x4f8
	// Func End, Address: 0x2cad14, Func Offset: 0x504
}

// 
// Start address: 0x2cad20
void bhCheckPadPort()
{
	_anon26* info;
	// Line 437, Address: 0x2cad20, Func Offset: 0
	// Line 441, Address: 0x2cad28, Func Offset: 0x8
	// Line 443, Address: 0x2cad30, Func Offset: 0x10
	// Line 501, Address: 0x2cad40, Func Offset: 0x20
	// Line 511, Address: 0x2cad44, Func Offset: 0x24
	// Line 515, Address: 0x2cad4c, Func Offset: 0x2c
	// Line 513, Address: 0x2cad54, Func Offset: 0x34
	// Line 515, Address: 0x2cad60, Func Offset: 0x40
	// Line 543, Address: 0x2cadf0, Func Offset: 0xd0
	// Line 562, Address: 0x2cadfc, Func Offset: 0xdc
	// Func End, Address: 0x2cae08, Func Offset: 0xe8
}

// 
// Start address: 0x2cae10
void bhCheckSoftReset()
{
	// Line 568, Address: 0x2cae10, Func Offset: 0
	// Line 570, Address: 0x2cae18, Func Offset: 0x8
	// Line 579, Address: 0x2cae5c, Func Offset: 0x4c
	// Line 581, Address: 0x2cae70, Func Offset: 0x60
	// Line 584, Address: 0x2cae78, Func Offset: 0x68
	// Func End, Address: 0x2cae84, Func Offset: 0x74
}

