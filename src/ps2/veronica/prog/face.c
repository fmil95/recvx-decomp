#include "face.h"

/*_anon23* sys;

void bhInitMask(BH_PWORK* pp);
void bhControlMask(BH_PWORK* pp);
int bhSetMask(BH_PWORK* pp, int msk_no, int frm_no);
int bhSetLip(BH_PWORK* pp, int mls_no);

// 
// Start address: 0x297fd0
void bhInitMask(BH_PWORK* pp)
{
	int i;
	_anon2* fm;
	// Line 61, Address: 0x297fd0, Func Offset: 0
	// Line 66, Address: 0x297fe0, Func Offset: 0x10
	// Line 68, Address: 0x297ff0, Func Offset: 0x20
	// Line 70, Address: 0x298000, Func Offset: 0x30
	// Line 73, Address: 0x298014, Func Offset: 0x44
	// Line 74, Address: 0x298020, Func Offset: 0x50
	// Line 75, Address: 0x298030, Func Offset: 0x60
	// Line 76, Address: 0x298044, Func Offset: 0x74
	// Line 77, Address: 0x298058, Func Offset: 0x88
	// Line 78, Address: 0x29806c, Func Offset: 0x9c
	// Line 79, Address: 0x298080, Func Offset: 0xb0
	// Line 80, Address: 0x298090, Func Offset: 0xc0
	// Line 84, Address: 0x298098, Func Offset: 0xc8
	// Line 85, Address: 0x2980a0, Func Offset: 0xd0
	// Line 86, Address: 0x2980a4, Func Offset: 0xd4
	// Line 85, Address: 0x2980ac, Func Offset: 0xdc
	// Line 86, Address: 0x2980b4, Func Offset: 0xe4
	// Line 87, Address: 0x2980bc, Func Offset: 0xec
	// Line 88, Address: 0x2980c4, Func Offset: 0xf4
	// Line 90, Address: 0x2980cc, Func Offset: 0xfc
	// Line 89, Address: 0x2980d0, Func Offset: 0x100
	// Line 90, Address: 0x2980d4, Func Offset: 0x104
	// Line 94, Address: 0x2980e4, Func Offset: 0x114
	// Line 95, Address: 0x2980f0, Func Offset: 0x120
	// Line 96, Address: 0x298100, Func Offset: 0x130
	// Line 97, Address: 0x29810c, Func Offset: 0x13c
	// Line 98, Address: 0x298118, Func Offset: 0x148
	// Line 101, Address: 0x298130, Func Offset: 0x160
	// Line 102, Address: 0x298144, Func Offset: 0x174
	// Line 103, Address: 0x298158, Func Offset: 0x188
	// Line 104, Address: 0x29816c, Func Offset: 0x19c
	// Line 105, Address: 0x298180, Func Offset: 0x1b0
	// Line 106, Address: 0x298194, Func Offset: 0x1c4
	// Line 107, Address: 0x2981a8, Func Offset: 0x1d8
	// Line 108, Address: 0x2981bc, Func Offset: 0x1ec
	// Line 109, Address: 0x2981d0, Func Offset: 0x200
	// Line 112, Address: 0x2981e4, Func Offset: 0x214
	// Line 114, Address: 0x2981ec, Func Offset: 0x21c
	// Line 115, Address: 0x2981f4, Func Offset: 0x224
	// Line 118, Address: 0x298204, Func Offset: 0x234
	// Line 122, Address: 0x298208, Func Offset: 0x238
	// Line 118, Address: 0x29820c, Func Offset: 0x23c
	// Line 119, Address: 0x298210, Func Offset: 0x240
	// Line 120, Address: 0x298218, Func Offset: 0x248
	// Line 121, Address: 0x298220, Func Offset: 0x250
	// Line 122, Address: 0x298228, Func Offset: 0x258
	// Line 123, Address: 0x298230, Func Offset: 0x260
	// Line 124, Address: 0x298238, Func Offset: 0x268
	// Line 125, Address: 0x29823c, Func Offset: 0x26c
	// Func End, Address: 0x298250, Func Offset: 0x280
}

// 
// Start address: 0x298250
void bhControlMask(BH_PWORK* pp)
{
	void* fbak;
	_anon11* lip;
	_anon2* fm;
	// Line 131, Address: 0x298250, Func Offset: 0
	// Line 136, Address: 0x298268, Func Offset: 0x18
	// Line 137, Address: 0x298274, Func Offset: 0x24
	// Line 140, Address: 0x298298, Func Offset: 0x48
	// Line 146, Address: 0x2982a0, Func Offset: 0x50
	// Line 143, Address: 0x2982a4, Func Offset: 0x54
	// Line 146, Address: 0x2982a8, Func Offset: 0x58
	// Line 147, Address: 0x2982b4, Func Offset: 0x64
	// Line 148, Address: 0x2982c0, Func Offset: 0x70
	// Line 150, Address: 0x2982e0, Func Offset: 0x90
	// Line 153, Address: 0x298308, Func Offset: 0xb8
	// Line 154, Address: 0x29831c, Func Offset: 0xcc
	// Line 155, Address: 0x298328, Func Offset: 0xd8
	// Line 156, Address: 0x29832c, Func Offset: 0xdc
	// Line 155, Address: 0x298330, Func Offset: 0xe0
	// Line 156, Address: 0x298334, Func Offset: 0xe4
	// Line 157, Address: 0x298340, Func Offset: 0xf0
	// Line 159, Address: 0x298364, Func Offset: 0x114
	// Line 160, Address: 0x29836c, Func Offset: 0x11c
	// Line 163, Address: 0x298370, Func Offset: 0x120
	// Line 160, Address: 0x298374, Func Offset: 0x124
	// Line 161, Address: 0x298380, Func Offset: 0x130
	// Line 162, Address: 0x29838c, Func Offset: 0x13c
	// Line 163, Address: 0x298394, Func Offset: 0x144
	// Line 164, Address: 0x2983a4, Func Offset: 0x154
	// Line 169, Address: 0x2983c4, Func Offset: 0x174
	// Line 170, Address: 0x2983d8, Func Offset: 0x188
	// Line 171, Address: 0x2983e4, Func Offset: 0x194
	// Line 174, Address: 0x2983e8, Func Offset: 0x198
	// Line 171, Address: 0x2983ec, Func Offset: 0x19c
	// Line 172, Address: 0x2983f0, Func Offset: 0x1a0
	// Line 173, Address: 0x2983f8, Func Offset: 0x1a8
	// Line 177, Address: 0x298400, Func Offset: 0x1b0
	// Line 178, Address: 0x298408, Func Offset: 0x1b8
	// Line 182, Address: 0x29840c, Func Offset: 0x1bc
	// Line 200, Address: 0x298420, Func Offset: 0x1d0
	// Line 203, Address: 0x29842c, Func Offset: 0x1dc
	// Line 210, Address: 0x298434, Func Offset: 0x1e4
	// Line 203, Address: 0x298440, Func Offset: 0x1f0
	// Line 204, Address: 0x298448, Func Offset: 0x1f8
	// Line 210, Address: 0x29844c, Func Offset: 0x1fc
	// Line 204, Address: 0x298450, Func Offset: 0x200
	// Line 207, Address: 0x298454, Func Offset: 0x204
	// Line 205, Address: 0x298458, Func Offset: 0x208
	// Line 207, Address: 0x29845c, Func Offset: 0x20c
	// Line 210, Address: 0x298464, Func Offset: 0x214
	// Line 211, Address: 0x29848c, Func Offset: 0x23c
	// Line 213, Address: 0x2984ac, Func Offset: 0x25c
	// Line 217, Address: 0x2984b0, Func Offset: 0x260
	// Line 219, Address: 0x2984c4, Func Offset: 0x274
	// Line 220, Address: 0x2984d0, Func Offset: 0x280
	// Line 221, Address: 0x2984dc, Func Offset: 0x28c
	// Line 222, Address: 0x2984f8, Func Offset: 0x2a8
	// Line 223, Address: 0x298508, Func Offset: 0x2b8
	// Line 224, Address: 0x298510, Func Offset: 0x2c0
	// Line 225, Address: 0x298528, Func Offset: 0x2d8
	// Line 226, Address: 0x298538, Func Offset: 0x2e8
	// Line 229, Address: 0x298540, Func Offset: 0x2f0
	// Line 230, Address: 0x298548, Func Offset: 0x2f8
	// Line 231, Address: 0x298558, Func Offset: 0x308
	// Line 237, Address: 0x298560, Func Offset: 0x310
	// Line 238, Address: 0x298574, Func Offset: 0x324
	// Line 240, Address: 0x29857c, Func Offset: 0x32c
	// Line 246, Address: 0x298580, Func Offset: 0x330
	// Line 238, Address: 0x298584, Func Offset: 0x334
	// Line 239, Address: 0x29858c, Func Offset: 0x33c
	// Line 240, Address: 0x298594, Func Offset: 0x344
	// Line 241, Address: 0x2985a4, Func Offset: 0x354
	// Line 242, Address: 0x2985b0, Func Offset: 0x360
	// Line 243, Address: 0x2985bc, Func Offset: 0x36c
	// Line 244, Address: 0x2985c8, Func Offset: 0x378
	// Line 245, Address: 0x2985d4, Func Offset: 0x384
	// Line 246, Address: 0x2985d8, Func Offset: 0x388
	// Line 276, Address: 0x2985e8, Func Offset: 0x398
	// Line 279, Address: 0x29862c, Func Offset: 0x3dc
	// Line 281, Address: 0x298634, Func Offset: 0x3e4
	// Line 282, Address: 0x298648, Func Offset: 0x3f8
	// Line 283, Address: 0x29865c, Func Offset: 0x40c
	// Line 284, Address: 0x298674, Func Offset: 0x424
	// Line 285, Address: 0x29868c, Func Offset: 0x43c
	// Line 286, Address: 0x2986a4, Func Offset: 0x454
	// Line 336, Address: 0x2986bc, Func Offset: 0x46c
	// Func End, Address: 0x2986d8, Func Offset: 0x488
}

// 
// Start address: 0x2986e0
int bhSetMask(BH_PWORK* pp, int msk_no, int frm_no)
{
	int i;
	unsigned int sz;
	unsigned char* datp;
	_anon2* fm;
	// Line 347, Address: 0x2986e0, Func Offset: 0
	// Line 351, Address: 0x2986e4, Func Offset: 0x4
	// Line 352, Address: 0x2986e8, Func Offset: 0x8
	// Line 351, Address: 0x2986ec, Func Offset: 0xc
	// Line 352, Address: 0x2986f0, Func Offset: 0x10
	// Line 353, Address: 0x298700, Func Offset: 0x20
	// Line 354, Address: 0x29871c, Func Offset: 0x3c
	// Line 355, Address: 0x298720, Func Offset: 0x40
	// Line 357, Address: 0x29872c, Func Offset: 0x4c
	// Line 356, Address: 0x298730, Func Offset: 0x50
	// Line 357, Address: 0x298734, Func Offset: 0x54
	// Line 359, Address: 0x298744, Func Offset: 0x64
	// Line 358, Address: 0x298748, Func Offset: 0x68
	// Line 361, Address: 0x29874c, Func Offset: 0x6c
	// Line 359, Address: 0x298754, Func Offset: 0x74
	// Line 361, Address: 0x298758, Func Offset: 0x78
	// Line 362, Address: 0x298760, Func Offset: 0x80
	// Line 364, Address: 0x298764, Func Offset: 0x84
	// Line 362, Address: 0x298768, Func Offset: 0x88
	// Line 363, Address: 0x29876c, Func Offset: 0x8c
	// Line 365, Address: 0x29877c, Func Offset: 0x9c
	// Func End, Address: 0x298784, Func Offset: 0xa4
}

// 
// Start address: 0x298790
int bhSetLip(BH_PWORK* pp, int mls_no)
{
	int i;
	unsigned int sz;
	unsigned char* datp;
	_anon11* lip;
	// Line 406, Address: 0x298790, Func Offset: 0
	// Line 407, Address: 0x2987a4, Func Offset: 0x14
	// Line 408, Address: 0x2987bc, Func Offset: 0x2c
	// Line 409, Address: 0x2987c0, Func Offset: 0x30
	// Line 411, Address: 0x2987cc, Func Offset: 0x3c
	// Line 410, Address: 0x2987d0, Func Offset: 0x40
	// Line 411, Address: 0x2987d4, Func Offset: 0x44
	// Line 413, Address: 0x2987e4, Func Offset: 0x54
	// Line 412, Address: 0x2987e8, Func Offset: 0x58
	// Line 415, Address: 0x2987ec, Func Offset: 0x5c
	// Line 413, Address: 0x2987f4, Func Offset: 0x64
	// Line 415, Address: 0x2987f8, Func Offset: 0x68
	// Line 416, Address: 0x298800, Func Offset: 0x70
	// Line 417, Address: 0x298804, Func Offset: 0x74
	// Line 416, Address: 0x298808, Func Offset: 0x78
	// Line 418, Address: 0x29880c, Func Offset: 0x7c
	// Func End, Address: 0x298814, Func Offset: 0x84
}*/

