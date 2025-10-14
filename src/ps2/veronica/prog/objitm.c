#include "objitm.h"

/*void(*bhJumpObject)()[101];
void(*bhJumpObject2)()[13];
unsigned int ulDrawGeneralPurposeWater;
_anon1* sys;
_anon4* rom;
unsigned char pl_sleep_cnt;
_anon41 cam;
BH_PWORK* plp;

void bhInitObjItm();
_anon0* bhSetObject(_anon18* otp, int no, unsigned char* lkp);
_anon0* bhSetItem(_anon18* itp, int no, unsigned char* lkp);
void bhControlObjItm();
void bhDrawGeneralPurposeWater();
void bhDrawObjItm();
void bhDrawObject(_anon0* op);
void bhDrawSpObject(_anon0* op);
void bhSetAlphaFadeObject(_anon0* op, int jntno, int jnt_n, int alpha, int count);
void bhControlAlphaFadeObject(_anon0* op);
void bhObjDmy();
void bhObjItmBox(_anon0* op);
void bhObj001(_anon0* op);
void bhObj002(_anon0* op);
void bhObj003(_anon0* op);
void bhObj004(_anon0* op);
void bhObj005(_anon0* op);
void bhObj006(_anon0* op);
void bhObj007(_anon0* op);
void bhObj008(_anon0* op);
void bhObj009(_anon0* op);
void bhObj010(_anon0* op);
void bhObj011(_anon0* op);
void bhObj012(_anon0* op);
void bhObjClpn(_anon0* op);
void bhObjWssg();*/

// 
// Start address: 0x283080
void bhInitObjItm()
{
	// Line 59, Address: 0x283080, Func Offset: 0
	// Line 60, Address: 0x283088, Func Offset: 0x8
	// Line 61, Address: 0x2830a8, Func Offset: 0x28
	// Line 62, Address: 0x2830c8, Func Offset: 0x48
	// Func End, Address: 0x2830d4, Func Offset: 0x54
	scePrintf("bhInitObjItm - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2830e0
_anon0* bhSetObject(_anon18* otp, int no, unsigned char* lkp)
{
	_anon0* opp;
	// Line 73, Address: 0x2830e0, Func Offset: 0
	// Line 75, Address: 0x2830fc, Func Offset: 0x1c
	// Line 76, Address: 0x28312c, Func Offset: 0x4c
	// Line 75, Address: 0x283134, Func Offset: 0x54
	// Line 76, Address: 0x283138, Func Offset: 0x58
	// Line 77, Address: 0x283140, Func Offset: 0x60
	// Line 78, Address: 0x283144, Func Offset: 0x64
	// Line 77, Address: 0x283148, Func Offset: 0x68
	// Line 78, Address: 0x28314c, Func Offset: 0x6c
	// Line 79, Address: 0x283168, Func Offset: 0x88
	// Line 80, Address: 0x283188, Func Offset: 0xa8
	// Line 93, Address: 0x28318c, Func Offset: 0xac
	// Line 103, Address: 0x283190, Func Offset: 0xb0
	// Line 109, Address: 0x283194, Func Offset: 0xb4
	// Line 80, Address: 0x283198, Func Offset: 0xb8
	// Line 81, Address: 0x28319c, Func Offset: 0xbc
	// Line 111, Address: 0x2831a0, Func Offset: 0xc0
	// Line 81, Address: 0x2831a4, Func Offset: 0xc4
	// Line 82, Address: 0x2831a8, Func Offset: 0xc8
	// Line 83, Address: 0x2831b4, Func Offset: 0xd4
	// Line 84, Address: 0x2831bc, Func Offset: 0xdc
	// Line 85, Address: 0x2831c4, Func Offset: 0xe4
	// Line 86, Address: 0x2831cc, Func Offset: 0xec
	// Line 87, Address: 0x2831d4, Func Offset: 0xf4
	// Line 88, Address: 0x2831dc, Func Offset: 0xfc
	// Line 89, Address: 0x2831e4, Func Offset: 0x104
	// Line 90, Address: 0x2831ec, Func Offset: 0x10c
	// Line 91, Address: 0x2831f4, Func Offset: 0x114
	// Line 92, Address: 0x2831fc, Func Offset: 0x11c
	// Line 93, Address: 0x283204, Func Offset: 0x124
	// Line 94, Address: 0x28320c, Func Offset: 0x12c
	// Line 95, Address: 0x283214, Func Offset: 0x134
	// Line 96, Address: 0x28321c, Func Offset: 0x13c
	// Line 97, Address: 0x283224, Func Offset: 0x144
	// Line 98, Address: 0x28322c, Func Offset: 0x14c
	// Line 99, Address: 0x283234, Func Offset: 0x154
	// Line 100, Address: 0x28323c, Func Offset: 0x15c
	// Line 103, Address: 0x283240, Func Offset: 0x160
	// Line 108, Address: 0x283244, Func Offset: 0x164
	// Line 109, Address: 0x283248, Func Offset: 0x168
	// Line 110, Address: 0x28324c, Func Offset: 0x16c
	// Line 112, Address: 0x283250, Func Offset: 0x170
	// Func End, Address: 0x28326c, Func Offset: 0x18c
}

// 
// Start address: 0x283270
_anon0* bhSetItem(_anon18* itp, int no, unsigned char* lkp)
{
	_anon0* opp;
	// Line 123, Address: 0x283270, Func Offset: 0
	// Line 125, Address: 0x28328c, Func Offset: 0x1c
	// Line 126, Address: 0x2832bc, Func Offset: 0x4c
	// Line 125, Address: 0x2832c4, Func Offset: 0x54
	// Line 126, Address: 0x2832c8, Func Offset: 0x58
	// Line 127, Address: 0x2832d0, Func Offset: 0x60
	// Line 128, Address: 0x2832d4, Func Offset: 0x64
	// Line 127, Address: 0x2832d8, Func Offset: 0x68
	// Line 128, Address: 0x2832dc, Func Offset: 0x6c
	// Line 129, Address: 0x2832f8, Func Offset: 0x88
	// Line 130, Address: 0x283318, Func Offset: 0xa8
	// Line 143, Address: 0x28331c, Func Offset: 0xac
	// Line 153, Address: 0x283320, Func Offset: 0xb0
	// Line 159, Address: 0x283324, Func Offset: 0xb4
	// Line 130, Address: 0x283328, Func Offset: 0xb8
	// Line 131, Address: 0x28332c, Func Offset: 0xbc
	// Line 161, Address: 0x283330, Func Offset: 0xc0
	// Line 131, Address: 0x283334, Func Offset: 0xc4
	// Line 132, Address: 0x283338, Func Offset: 0xc8
	// Line 133, Address: 0x283344, Func Offset: 0xd4
	// Line 134, Address: 0x28334c, Func Offset: 0xdc
	// Line 135, Address: 0x283354, Func Offset: 0xe4
	// Line 136, Address: 0x28335c, Func Offset: 0xec
	// Line 137, Address: 0x283364, Func Offset: 0xf4
	// Line 138, Address: 0x28336c, Func Offset: 0xfc
	// Line 139, Address: 0x283374, Func Offset: 0x104
	// Line 140, Address: 0x28337c, Func Offset: 0x10c
	// Line 141, Address: 0x283384, Func Offset: 0x114
	// Line 142, Address: 0x28338c, Func Offset: 0x11c
	// Line 143, Address: 0x283394, Func Offset: 0x124
	// Line 144, Address: 0x28339c, Func Offset: 0x12c
	// Line 145, Address: 0x2833a4, Func Offset: 0x134
	// Line 146, Address: 0x2833ac, Func Offset: 0x13c
	// Line 147, Address: 0x2833b4, Func Offset: 0x144
	// Line 148, Address: 0x2833bc, Func Offset: 0x14c
	// Line 149, Address: 0x2833c4, Func Offset: 0x154
	// Line 150, Address: 0x2833cc, Func Offset: 0x15c
	// Line 153, Address: 0x2833d0, Func Offset: 0x160
	// Line 158, Address: 0x2833d4, Func Offset: 0x164
	// Line 159, Address: 0x2833d8, Func Offset: 0x168
	// Line 160, Address: 0x2833dc, Func Offset: 0x16c
	// Line 162, Address: 0x2833e0, Func Offset: 0x170
	// Func End, Address: 0x2833fc, Func Offset: 0x18c
}*/

// 
// Start address: 0x283400
void bhControlObjItm()
{
	int obj_n;
	int i;
	BH_PWORK* pp;
	//_anon0* op;
	// Line 168, Address: 0x283400, Func Offset: 0
	// Line 174, Address: 0x283418, Func Offset: 0x18
	// Line 176, Address: 0x283430, Func Offset: 0x30
	// Line 177, Address: 0x28343c, Func Offset: 0x3c
	// Line 181, Address: 0x283444, Func Offset: 0x44
	// Line 177, Address: 0x283448, Func Offset: 0x48
	// Line 178, Address: 0x283454, Func Offset: 0x54
	// Line 179, Address: 0x283468, Func Offset: 0x68
	// Line 181, Address: 0x283478, Func Offset: 0x78
	// Line 182, Address: 0x2834a0, Func Offset: 0xa0
	// Line 183, Address: 0x2834ac, Func Offset: 0xac
	// Line 184, Address: 0x2834c0, Func Offset: 0xc0
	// Line 186, Address: 0x2834d0, Func Offset: 0xd0
	// Line 187, Address: 0x2834f8, Func Offset: 0xf8
	// Line 188, Address: 0x28350c, Func Offset: 0x10c
	// Line 192, Address: 0x283510, Func Offset: 0x110
	// Line 194, Address: 0x283538, Func Offset: 0x138
	// Line 196, Address: 0x283548, Func Offset: 0x148
	// Line 197, Address: 0x283550, Func Offset: 0x150
	// Line 198, Address: 0x283558, Func Offset: 0x158
	// Line 200, Address: 0x283560, Func Offset: 0x160
	// Line 201, Address: 0x283568, Func Offset: 0x168
	// Line 202, Address: 0x283570, Func Offset: 0x170
	// Line 205, Address: 0x283578, Func Offset: 0x178
	// Line 206, Address: 0x283588, Func Offset: 0x188
	// Line 211, Address: 0x28358c, Func Offset: 0x18c
	// Line 218, Address: 0x2835b8, Func Offset: 0x1b8
	// Line 219, Address: 0x2835d8, Func Offset: 0x1d8
	// Line 220, Address: 0x2835e4, Func Offset: 0x1e4
	// Line 221, Address: 0x2835ec, Func Offset: 0x1ec
	// Line 225, Address: 0x283608, Func Offset: 0x208
	// Line 226, Address: 0x28361c, Func Offset: 0x21c
	// Line 227, Address: 0x283624, Func Offset: 0x224
	// Line 244, Address: 0x283628, Func Offset: 0x228
	// Line 245, Address: 0x283638, Func Offset: 0x238
	// Line 247, Address: 0x28365c, Func Offset: 0x25c
	// Line 250, Address: 0x283680, Func Offset: 0x280
	// Line 251, Address: 0x2836a0, Func Offset: 0x2a0
	// Line 252, Address: 0x2836b0, Func Offset: 0x2b0
	// Line 254, Address: 0x2836f0, Func Offset: 0x2f0
	// Line 255, Address: 0x28371c, Func Offset: 0x31c
	// Line 256, Address: 0x283724, Func Offset: 0x324
	// Line 257, Address: 0x28373c, Func Offset: 0x33c
	// Line 258, Address: 0x283758, Func Offset: 0x358
	// Line 260, Address: 0x28378c, Func Offset: 0x38c
	// Line 263, Address: 0x2837bc, Func Offset: 0x3bc
	// Line 265, Address: 0x2837c0, Func Offset: 0x3c0
	// Line 269, Address: 0x2837d4, Func Offset: 0x3d4
	// Line 270, Address: 0x2837dc, Func Offset: 0x3dc
	// Line 272, Address: 0x2837e0, Func Offset: 0x3e0
	// Line 274, Address: 0x283800, Func Offset: 0x400
	// Line 276, Address: 0x28380c, Func Offset: 0x40c
	// Line 277, Address: 0x283820, Func Offset: 0x420
	// Line 279, Address: 0x28383c, Func Offset: 0x43c
	// Line 280, Address: 0x283848, Func Offset: 0x448
	// Line 281, Address: 0x283850, Func Offset: 0x450
	// Line 282, Address: 0x283864, Func Offset: 0x464
	// Line 284, Address: 0x283874, Func Offset: 0x474
	// Line 285, Address: 0x28387c, Func Offset: 0x47c
	// Line 286, Address: 0x283884, Func Offset: 0x484
	// Line 288, Address: 0x28388c, Func Offset: 0x48c
	// Line 289, Address: 0x283894, Func Offset: 0x494
	// Line 290, Address: 0x28389c, Func Offset: 0x49c
	// Line 292, Address: 0x2838a4, Func Offset: 0x4a4
	// Line 294, Address: 0x2838b0, Func Offset: 0x4b0
	// Line 296, Address: 0x2838d4, Func Offset: 0x4d4
	// Line 297, Address: 0x2838e0, Func Offset: 0x4e0
	// Line 298, Address: 0x2838f4, Func Offset: 0x4f4
	// Line 299, Address: 0x283900, Func Offset: 0x500
	// Line 300, Address: 0x283904, Func Offset: 0x504
	// Line 301, Address: 0x283908, Func Offset: 0x508
	// Line 303, Address: 0x283910, Func Offset: 0x510
	// Line 305, Address: 0x283918, Func Offset: 0x518
	// Line 306, Address: 0x283924, Func Offset: 0x524
	// Line 307, Address: 0x283934, Func Offset: 0x534
	// Line 308, Address: 0x283940, Func Offset: 0x540
	// Line 309, Address: 0x283950, Func Offset: 0x550
	// Line 311, Address: 0x283958, Func Offset: 0x558
	// Line 313, Address: 0x283960, Func Offset: 0x560
	// Line 314, Address: 0x283970, Func Offset: 0x570
	// Line 316, Address: 0x283974, Func Offset: 0x574
	// Line 321, Address: 0x2839b8, Func Offset: 0x5b8
	// Line 323, Address: 0x2839d8, Func Offset: 0x5d8
	// Line 325, Address: 0x2839e4, Func Offset: 0x5e4
	// Line 326, Address: 0x283a08, Func Offset: 0x608
	// Func End, Address: 0x283a24, Func Offset: 0x624
	scePrintf("bhControlObjItm - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x283a30
void bhDrawGeneralPurposeWater()
{
	int i;
	// Line 333, Address: 0x283a30, Func Offset: 0
	// Line 338, Address: 0x283a40, Func Offset: 0x10
	// Line 362, Address: 0x283a58, Func Offset: 0x28
	// Line 364, Address: 0x283a64, Func Offset: 0x34
	// Line 373, Address: 0x283b30, Func Offset: 0x100
	// Line 375, Address: 0x283b3c, Func Offset: 0x10c
	// Line 377, Address: 0x283b50, Func Offset: 0x120
	// Line 379, Address: 0x283b5c, Func Offset: 0x12c
	// Line 381, Address: 0x283b80, Func Offset: 0x150
	// Func End, Address: 0x283b94, Func Offset: 0x164
	scePrintf("bhDrawGeneralPurposeWater - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x283ba0
void bhDrawObjItm()
{
	float its;
	//_anon32 vec;
	int i;
	//_anon0* op;
	// Line 389, Address: 0x283ba0, Func Offset: 0
	// Line 399, Address: 0x283bbc, Func Offset: 0x1c
	// Line 401, Address: 0x283bd4, Func Offset: 0x34
	// Line 402, Address: 0x283bec, Func Offset: 0x4c
	// Line 405, Address: 0x283c10, Func Offset: 0x70
	// Line 408, Address: 0x283c34, Func Offset: 0x94
	// Line 410, Address: 0x283c80, Func Offset: 0xe0
	// Line 411, Address: 0x283c98, Func Offset: 0xf8
	// Line 414, Address: 0x283cbc, Func Offset: 0x11c
	// Line 417, Address: 0x283ce0, Func Offset: 0x140
	// Line 418, Address: 0x283cec, Func Offset: 0x14c
	// Line 419, Address: 0x283d04, Func Offset: 0x164
	// Line 422, Address: 0x283d28, Func Offset: 0x188
	// Line 424, Address: 0x283d34, Func Offset: 0x194
	// Line 434, Address: 0x283dfc, Func Offset: 0x25c
	// Line 435, Address: 0x283e00, Func Offset: 0x260
	// Line 436, Address: 0x283e14, Func Offset: 0x274
	// Line 435, Address: 0x283e18, Func Offset: 0x278
	// Line 436, Address: 0x283e1c, Func Offset: 0x27c
	// Line 444, Address: 0x283e40, Func Offset: 0x2a0
	// Line 448, Address: 0x283e60, Func Offset: 0x2c0
	// Line 451, Address: 0x283e84, Func Offset: 0x2e4
	// Line 455, Address: 0x283ea8, Func Offset: 0x308
	// Line 459, Address: 0x283eb0, Func Offset: 0x310
	// Line 460, Address: 0x283ec8, Func Offset: 0x328
	// Line 461, Address: 0x283ed4, Func Offset: 0x334
	// Line 462, Address: 0x283edc, Func Offset: 0x33c
	// Line 463, Address: 0x283ef0, Func Offset: 0x350
	// Line 470, Address: 0x283f10, Func Offset: 0x370
	// Line 475, Address: 0x283f4c, Func Offset: 0x3ac
	// Line 481, Address: 0x283f84, Func Offset: 0x3e4
	// Line 492, Address: 0x283f88, Func Offset: 0x3e8
	// Line 493, Address: 0x283fac, Func Offset: 0x40c
	// Line 495, Address: 0x283fb8, Func Offset: 0x418
	// Line 498, Address: 0x283fc8, Func Offset: 0x428
	// Line 499, Address: 0x283fd8, Func Offset: 0x438
	// Line 498, Address: 0x283fe0, Func Offset: 0x440
	// Line 499, Address: 0x283fe4, Func Offset: 0x444
	// Line 500, Address: 0x283ff4, Func Offset: 0x454
	// Line 502, Address: 0x284004, Func Offset: 0x464
	// Line 503, Address: 0x28401c, Func Offset: 0x47c
	// Line 504, Address: 0x284030, Func Offset: 0x490
	// Line 505, Address: 0x28403c, Func Offset: 0x49c
	// Line 507, Address: 0x284044, Func Offset: 0x4a4
	// Line 508, Address: 0x284054, Func Offset: 0x4b4
	// Line 509, Address: 0x284068, Func Offset: 0x4c8
	// Line 510, Address: 0x284074, Func Offset: 0x4d4
	// Line 511, Address: 0x28407c, Func Offset: 0x4dc
	// Line 512, Address: 0x284084, Func Offset: 0x4e4
	// Line 513, Address: 0x284094, Func Offset: 0x4f4
	// Line 515, Address: 0x2840b0, Func Offset: 0x510
	// Line 516, Address: 0x2840c4, Func Offset: 0x524
	// Line 518, Address: 0x2840d0, Func Offset: 0x530
	// Line 519, Address: 0x2840e4, Func Offset: 0x544
	// Line 520, Address: 0x2840f0, Func Offset: 0x550
	// Line 522, Address: 0x2840f8, Func Offset: 0x558
	// Line 523, Address: 0x284124, Func Offset: 0x584
	// Line 524, Address: 0x284154, Func Offset: 0x5b4
	// Line 525, Address: 0x284160, Func Offset: 0x5c0
	// Line 527, Address: 0x284168, Func Offset: 0x5c8
	// Line 528, Address: 0x28419c, Func Offset: 0x5fc
	// Line 529, Address: 0x2841cc, Func Offset: 0x62c
	// Line 530, Address: 0x2841d8, Func Offset: 0x638
	// Line 533, Address: 0x2841e0, Func Offset: 0x640
	// Line 534, Address: 0x2841f8, Func Offset: 0x658
	// Line 535, Address: 0x284220, Func Offset: 0x680
	// Line 537, Address: 0x284228, Func Offset: 0x688
	// Line 542, Address: 0x284248, Func Offset: 0x6a8
	// Func End, Address: 0x284268, Func Offset: 0x6c8
	scePrintf("bhDrawObjItm - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x284270
void bhDrawObject(_anon0* op)
{
	// Line 548, Address: 0x284270, Func Offset: 0
	// Line 551, Address: 0x28427c, Func Offset: 0xc
	// Line 553, Address: 0x28428c, Func Offset: 0x1c
	// Line 554, Address: 0x2842b4, Func Offset: 0x44
	// Line 555, Address: 0x2842c8, Func Offset: 0x58
	// Line 560, Address: 0x2842ec, Func Offset: 0x7c
	// Line 563, Address: 0x284338, Func Offset: 0xc8
	// Line 571, Address: 0x284340, Func Offset: 0xd0
	// Line 575, Address: 0x28436c, Func Offset: 0xfc
	// Line 583, Address: 0x2843a0, Func Offset: 0x130
	// Line 584, Address: 0x2843b0, Func Offset: 0x140
	// Line 587, Address: 0x2843b8, Func Offset: 0x148
	// Line 598, Address: 0x2843e8, Func Offset: 0x178
	// Line 603, Address: 0x2843f4, Func Offset: 0x184
	// Line 604, Address: 0x2843fc, Func Offset: 0x18c
	// Line 605, Address: 0x284428, Func Offset: 0x1b8
	// Func End, Address: 0x284438, Func Offset: 0x1c8
}

// 
// Start address: 0x284440
void bhDrawSpObject(_anon0* op)
{
	_anon32 vec;
	_anon3* lp;
	// Line 611, Address: 0x284440, Func Offset: 0
	// Line 620, Address: 0x284454, Func Offset: 0x14
	// Line 624, Address: 0x284494, Func Offset: 0x54
	// Line 632, Address: 0x2844cc, Func Offset: 0x8c
	// Line 637, Address: 0x2844e4, Func Offset: 0xa4
	// Line 638, Address: 0x2844f0, Func Offset: 0xb0
	// Line 637, Address: 0x2844f4, Func Offset: 0xb4
	// Line 638, Address: 0x284504, Func Offset: 0xc4
	// Line 639, Address: 0x28450c, Func Offset: 0xcc
	// Line 640, Address: 0x28451c, Func Offset: 0xdc
	// Line 641, Address: 0x28452c, Func Offset: 0xec
	// Line 642, Address: 0x284540, Func Offset: 0x100
	// Line 643, Address: 0x28454c, Func Offset: 0x10c
	// Line 644, Address: 0x284554, Func Offset: 0x114
	// Line 645, Address: 0x28455c, Func Offset: 0x11c
	// Line 646, Address: 0x284570, Func Offset: 0x130
	// Line 647, Address: 0x284580, Func Offset: 0x140
	// Line 648, Address: 0x28459c, Func Offset: 0x15c
	// Line 651, Address: 0x2845ac, Func Offset: 0x16c
	// Line 654, Address: 0x2845b8, Func Offset: 0x178
	// Func End, Address: 0x2845cc, Func Offset: 0x18c
}

// 
// Start address: 0x2845d0
void bhSetAlphaFadeObject(_anon0* op, int jntno, int jnt_n, int alpha, int count)
{
	float* fwk;
	int* iwk;
	// Line 694, Address: 0x2845d0, Func Offset: 0
	// Line 695, Address: 0x2845d4, Func Offset: 0x4
	// Line 689, Address: 0x2845d8, Func Offset: 0x8
	// Line 694, Address: 0x2845e0, Func Offset: 0x10
	// Line 689, Address: 0x2845e4, Func Offset: 0x14
	// Line 692, Address: 0x2845ec, Func Offset: 0x1c
	// Line 693, Address: 0x2845f0, Func Offset: 0x20
	// Line 695, Address: 0x2845f4, Func Offset: 0x24
	// Line 694, Address: 0x2845f8, Func Offset: 0x28
	// Line 696, Address: 0x2845fc, Func Offset: 0x2c
	// Func End, Address: 0x284604, Func Offset: 0x34
}

// 
// Start address: 0x284610
void bhControlAlphaFadeObject(_anon0* op)
{
	float count;
	float alpha;
	float na;
	int jnt_n;
	int i;
	float* fwk;
	int* iwk;
	npobj* objp;
	// Line 702, Address: 0x284610, Func Offset: 0
	// Line 715, Address: 0x284634, Func Offset: 0x24
	// Line 712, Address: 0x28463c, Func Offset: 0x2c
	// Line 713, Address: 0x284644, Func Offset: 0x34
	// Line 714, Address: 0x284648, Func Offset: 0x38
	// Line 715, Address: 0x28464c, Func Offset: 0x3c
	// Line 710, Address: 0x284664, Func Offset: 0x54
	// Line 715, Address: 0x284668, Func Offset: 0x58
	// Line 716, Address: 0x28466c, Func Offset: 0x5c
	// Line 717, Address: 0x284678, Func Offset: 0x68
	// Line 719, Address: 0x284694, Func Offset: 0x84
	// Line 720, Address: 0x2846cc, Func Offset: 0xbc
	// Line 721, Address: 0x2846dc, Func Offset: 0xcc
	// Line 722, Address: 0x2846f8, Func Offset: 0xe8
	// Line 723, Address: 0x284718, Func Offset: 0x108
	// Line 727, Address: 0x284730, Func Offset: 0x120
	// Line 728, Address: 0x284740, Func Offset: 0x130
	// Line 729, Address: 0x284748, Func Offset: 0x138
	// Line 728, Address: 0x284750, Func Offset: 0x140
	// Line 729, Address: 0x284754, Func Offset: 0x144
	// Line 730, Address: 0x284778, Func Offset: 0x168
	// Line 731, Address: 0x28477c, Func Offset: 0x16c
	// Func End, Address: 0x2847a4, Func Offset: 0x194
}

// 
// Start address: 0x2847b0
void bhObjDmy()
{
	// Line 746, Address: 0x2847b0, Func Offset: 0
	// Func End, Address: 0x2847b8, Func Offset: 0x8
}

// 
// Start address: 0x2847c0
void bhObjItmBox(_anon0* op)
{
	// Line 753, Address: 0x2847c0, Func Offset: 0
	// Line 754, Address: 0x2847d0, Func Offset: 0x10
	// Line 756, Address: 0x284808, Func Offset: 0x48
	// Line 758, Address: 0x28480c, Func Offset: 0x4c
	// Line 757, Address: 0x284810, Func Offset: 0x50
	// Line 758, Address: 0x284814, Func Offset: 0x54
	// Line 760, Address: 0x284820, Func Offset: 0x60
	// Line 761, Address: 0x28482c, Func Offset: 0x6c
	// Line 762, Address: 0x284844, Func Offset: 0x84
	// Line 763, Address: 0x284878, Func Offset: 0xb8
	// Line 765, Address: 0x284880, Func Offset: 0xc0
	// Line 767, Address: 0x284898, Func Offset: 0xd8
	// Line 769, Address: 0x2848a0, Func Offset: 0xe0
	// Line 770, Address: 0x2848bc, Func Offset: 0xfc
	// Line 771, Address: 0x2848c0, Func Offset: 0x100
	// Line 774, Address: 0x2848c4, Func Offset: 0x104
	// Func End, Address: 0x2848d4, Func Offset: 0x114
}

// 
// Start address: 0x2848e0
void bhObj001(_anon0* op)
{
	int pcflg;
	_anon22* hp;
	_anon32 pos;
	// Line 781, Address: 0x2848e0, Func Offset: 0
	// Line 786, Address: 0x2848f8, Func Offset: 0x18
	// Line 788, Address: 0x284918, Func Offset: 0x38
	// Line 790, Address: 0x28492c, Func Offset: 0x4c
	// Line 792, Address: 0x284934, Func Offset: 0x54
	// Line 793, Address: 0x284940, Func Offset: 0x60
	// Line 795, Address: 0x28494c, Func Offset: 0x6c
	// Line 798, Address: 0x284978, Func Offset: 0x98
	// Line 799, Address: 0x28497c, Func Offset: 0x9c
	// Line 798, Address: 0x284980, Func Offset: 0xa0
	// Line 799, Address: 0x284984, Func Offset: 0xa4
	// Line 801, Address: 0x28498c, Func Offset: 0xac
	// Line 800, Address: 0x284990, Func Offset: 0xb0
	// Line 802, Address: 0x284994, Func Offset: 0xb4
	// Line 804, Address: 0x28499c, Func Offset: 0xbc
	// Line 805, Address: 0x2849a4, Func Offset: 0xc4
	// Line 806, Address: 0x2849b0, Func Offset: 0xd0
	// Line 808, Address: 0x2849b8, Func Offset: 0xd8
	// Line 810, Address: 0x2849c0, Func Offset: 0xe0
	// Line 811, Address: 0x2849c4, Func Offset: 0xe4
	// Line 810, Address: 0x2849c8, Func Offset: 0xe8
	// Line 811, Address: 0x2849cc, Func Offset: 0xec
	// Line 812, Address: 0x2849d4, Func Offset: 0xf4
	// Line 814, Address: 0x2849d8, Func Offset: 0xf8
	// Line 816, Address: 0x2849e0, Func Offset: 0x100
	// Line 817, Address: 0x2849e8, Func Offset: 0x108
	// Line 818, Address: 0x2849f0, Func Offset: 0x110
	// Line 820, Address: 0x2849f8, Func Offset: 0x118
	// Line 822, Address: 0x284a00, Func Offset: 0x120
	// Line 823, Address: 0x284a08, Func Offset: 0x128
	// Line 824, Address: 0x284a10, Func Offset: 0x130
	// Line 826, Address: 0x284a18, Func Offset: 0x138
	// Line 828, Address: 0x284a20, Func Offset: 0x140
	// Line 829, Address: 0x284a28, Func Offset: 0x148
	// Line 830, Address: 0x284a30, Func Offset: 0x150
	// Line 832, Address: 0x284a38, Func Offset: 0x158
	// Line 834, Address: 0x284a40, Func Offset: 0x160
	// Line 835, Address: 0x284a48, Func Offset: 0x168
	// Line 836, Address: 0x284a50, Func Offset: 0x170
	// Line 837, Address: 0x284a58, Func Offset: 0x178
	// Line 841, Address: 0x284a5c, Func Offset: 0x17c
	// Line 846, Address: 0x284a64, Func Offset: 0x184
	// Line 850, Address: 0x284a6c, Func Offset: 0x18c
	// Line 843, Address: 0x284a74, Func Offset: 0x194
	// Line 841, Address: 0x284a78, Func Offset: 0x198
	// Line 842, Address: 0x284a98, Func Offset: 0x1b8
	// Line 843, Address: 0x284ac0, Func Offset: 0x1e0
	// Line 844, Address: 0x284ac4, Func Offset: 0x1e4
	// Line 845, Address: 0x284ac8, Func Offset: 0x1e8
	// Line 848, Address: 0x284acc, Func Offset: 0x1ec
	// Line 845, Address: 0x284ad0, Func Offset: 0x1f0
	// Line 846, Address: 0x284ad4, Func Offset: 0x1f4
	// Line 847, Address: 0x284ad8, Func Offset: 0x1f8
	// Line 848, Address: 0x284ae8, Func Offset: 0x208
	// Line 854, Address: 0x284afc, Func Offset: 0x21c
	// Line 848, Address: 0x284b00, Func Offset: 0x220
	// Line 849, Address: 0x284b04, Func Offset: 0x224
	// Line 850, Address: 0x284b14, Func Offset: 0x234
	// Line 851, Address: 0x284b20, Func Offset: 0x240
	// Line 852, Address: 0x284b28, Func Offset: 0x248
	// Line 853, Address: 0x284b34, Func Offset: 0x254
	// Line 854, Address: 0x284b40, Func Offset: 0x260
	// Line 855, Address: 0x284b54, Func Offset: 0x274
	// Line 857, Address: 0x284b60, Func Offset: 0x280
	// Line 861, Address: 0x284b68, Func Offset: 0x288
	// Line 860, Address: 0x284b70, Func Offset: 0x290
	// Line 857, Address: 0x284b74, Func Offset: 0x294
	// Line 858, Address: 0x284b94, Func Offset: 0x2b4
	// Line 859, Address: 0x284bbc, Func Offset: 0x2dc
	// Line 860, Address: 0x284bc0, Func Offset: 0x2e0
	// Line 861, Address: 0x284bc4, Func Offset: 0x2e4
	// Line 863, Address: 0x284bd4, Func Offset: 0x2f4
	// Line 864, Address: 0x284bdc, Func Offset: 0x2fc
	// Line 867, Address: 0x284be4, Func Offset: 0x304
	// Line 865, Address: 0x284bec, Func Offset: 0x30c
	// Line 891, Address: 0x284bf0, Func Offset: 0x310
	// Line 868, Address: 0x284bf4, Func Offset: 0x314
	// Line 864, Address: 0x284bf8, Func Offset: 0x318
	// Line 875, Address: 0x284bfc, Func Offset: 0x31c
	// Line 876, Address: 0x284c00, Func Offset: 0x320
	// Line 864, Address: 0x284c04, Func Offset: 0x324
	// Line 891, Address: 0x284c08, Func Offset: 0x328
	// Line 865, Address: 0x284c0c, Func Offset: 0x32c
	// Line 871, Address: 0x284c20, Func Offset: 0x340
	// Line 865, Address: 0x284c24, Func Offset: 0x344
	// Line 866, Address: 0x284c28, Func Offset: 0x348
	// Line 867, Address: 0x284c38, Func Offset: 0x358
	// Line 868, Address: 0x284c44, Func Offset: 0x364
	// Line 869, Address: 0x284c48, Func Offset: 0x368
	// Line 870, Address: 0x284c54, Func Offset: 0x374
	// Line 871, Address: 0x284c60, Func Offset: 0x380
	// Line 873, Address: 0x284c74, Func Offset: 0x394
	// Line 874, Address: 0x284c9c, Func Offset: 0x3bc
	// Line 875, Address: 0x284cc4, Func Offset: 0x3e4
	// Line 876, Address: 0x284cc8, Func Offset: 0x3e8
	// Line 877, Address: 0x284ccc, Func Offset: 0x3ec
	// Line 880, Address: 0x284cd0, Func Offset: 0x3f0
	// Line 877, Address: 0x284cd4, Func Offset: 0x3f4
	// Line 878, Address: 0x284cd8, Func Offset: 0x3f8
	// Line 879, Address: 0x284cdc, Func Offset: 0x3fc
	// Line 880, Address: 0x284cec, Func Offset: 0x40c
	// Line 887, Address: 0x284d00, Func Offset: 0x420
	// Line 880, Address: 0x284d04, Func Offset: 0x424
	// Line 881, Address: 0x284d08, Func Offset: 0x428
	// Line 882, Address: 0x284d18, Func Offset: 0x438
	// Line 883, Address: 0x284d24, Func Offset: 0x444
	// Line 884, Address: 0x284d28, Func Offset: 0x448
	// Line 885, Address: 0x284d34, Func Offset: 0x454
	// Line 887, Address: 0x284d44, Func Offset: 0x464
	// Line 888, Address: 0x284d68, Func Offset: 0x488
	// Line 889, Address: 0x284d90, Func Offset: 0x4b0
	// Line 890, Address: 0x284d94, Func Offset: 0x4b4
	// Line 891, Address: 0x284d98, Func Offset: 0x4b8
	// Line 892, Address: 0x284da8, Func Offset: 0x4c8
	// Line 893, Address: 0x284dac, Func Offset: 0x4cc
	// Line 896, Address: 0x284db4, Func Offset: 0x4d4
	// Line 894, Address: 0x284dbc, Func Offset: 0x4dc
	// Line 906, Address: 0x284dc0, Func Offset: 0x4e0
	// Line 899, Address: 0x284dc4, Func Offset: 0x4e4
	// Line 893, Address: 0x284dc8, Func Offset: 0x4e8
	// Line 904, Address: 0x284dcc, Func Offset: 0x4ec
	// Line 893, Address: 0x284dd0, Func Offset: 0x4f0
	// Line 906, Address: 0x284dd4, Func Offset: 0x4f4
	// Line 894, Address: 0x284dd8, Func Offset: 0x4f8
	// Line 902, Address: 0x284dec, Func Offset: 0x50c
	// Line 894, Address: 0x284df0, Func Offset: 0x510
	// Line 895, Address: 0x284df4, Func Offset: 0x514
	// Line 896, Address: 0x284e04, Func Offset: 0x524
	// Line 897, Address: 0x284e10, Func Offset: 0x530
	// Line 898, Address: 0x284e14, Func Offset: 0x534
	// Line 899, Address: 0x284e20, Func Offset: 0x540
	// Line 900, Address: 0x284e24, Func Offset: 0x544
	// Line 902, Address: 0x284e30, Func Offset: 0x550
	// Line 903, Address: 0x284e54, Func Offset: 0x574
	// Line 904, Address: 0x284e7c, Func Offset: 0x59c
	// Line 905, Address: 0x284e80, Func Offset: 0x5a0
	// Line 906, Address: 0x284e84, Func Offset: 0x5a4
	// Line 907, Address: 0x284e94, Func Offset: 0x5b4
	// Line 908, Address: 0x284e98, Func Offset: 0x5b8
	// Line 909, Address: 0x284ea8, Func Offset: 0x5c8
	// Line 911, Address: 0x284eac, Func Offset: 0x5cc
	// Line 908, Address: 0x284eb4, Func Offset: 0x5d4
	// Line 911, Address: 0x284eb8, Func Offset: 0x5d8
	// Line 908, Address: 0x284ebc, Func Offset: 0x5dc
	// Line 911, Address: 0x284ec4, Func Offset: 0x5e4
	// Line 909, Address: 0x284ec8, Func Offset: 0x5e8
	// Line 910, Address: 0x284ee0, Func Offset: 0x600
	// Line 911, Address: 0x284ef4, Func Offset: 0x614
	// Line 912, Address: 0x284f04, Func Offset: 0x624
	// Line 913, Address: 0x284f08, Func Offset: 0x628
	// Line 914, Address: 0x284f18, Func Offset: 0x638
	// Line 915, Address: 0x284f20, Func Offset: 0x640
	// Line 917, Address: 0x284f2c, Func Offset: 0x64c
	// Line 921, Address: 0x284f34, Func Offset: 0x654
	// Line 925, Address: 0x284f3c, Func Offset: 0x65c
	// Line 919, Address: 0x284f40, Func Offset: 0x660
	// Line 925, Address: 0x284f44, Func Offset: 0x664
	// Line 919, Address: 0x284f48, Func Offset: 0x668
	// Line 925, Address: 0x284f50, Func Offset: 0x670
	// Line 924, Address: 0x284f54, Func Offset: 0x674
	// Line 925, Address: 0x284f58, Func Offset: 0x678
	// Line 919, Address: 0x284f5c, Func Offset: 0x67c
	// Line 926, Address: 0x284f78, Func Offset: 0x698
	// Line 921, Address: 0x284f80, Func Offset: 0x6a0
	// Line 926, Address: 0x284f84, Func Offset: 0x6a4
	// Line 921, Address: 0x284f8c, Func Offset: 0x6ac
	// Line 923, Address: 0x284f94, Func Offset: 0x6b4
	// Line 924, Address: 0x284f9c, Func Offset: 0x6bc
	// Line 925, Address: 0x284fa4, Func Offset: 0x6c4
	// Line 926, Address: 0x284fb8, Func Offset: 0x6d8
	// Line 927, Address: 0x284fd8, Func Offset: 0x6f8
	// Line 929, Address: 0x284fe8, Func Offset: 0x708
	// Line 931, Address: 0x284fec, Func Offset: 0x70c
	// Line 932, Address: 0x284ff8, Func Offset: 0x718
	// Line 929, Address: 0x284ffc, Func Offset: 0x71c
	// Line 930, Address: 0x285000, Func Offset: 0x720
	// Line 932, Address: 0x285004, Func Offset: 0x724
	// Line 930, Address: 0x285010, Func Offset: 0x730
	// Line 931, Address: 0x285014, Func Offset: 0x734
	// Line 932, Address: 0x285028, Func Offset: 0x748
	// Line 933, Address: 0x285048, Func Offset: 0x768
	// Line 935, Address: 0x285058, Func Offset: 0x778
	// Line 938, Address: 0x28506c, Func Offset: 0x78c
	// Line 935, Address: 0x285070, Func Offset: 0x790
	// Line 938, Address: 0x285074, Func Offset: 0x794
	// Line 935, Address: 0x28507c, Func Offset: 0x79c
	// Line 936, Address: 0x285084, Func Offset: 0x7a4
	// Line 938, Address: 0x285088, Func Offset: 0x7a8
	// Line 936, Address: 0x28508c, Func Offset: 0x7ac
	// Line 937, Address: 0x285090, Func Offset: 0x7b0
	// Line 938, Address: 0x285098, Func Offset: 0x7b8
	// Line 939, Address: 0x2850b8, Func Offset: 0x7d8
	// Line 941, Address: 0x2850c8, Func Offset: 0x7e8
	// Line 944, Address: 0x2850dc, Func Offset: 0x7fc
	// Line 941, Address: 0x2850e0, Func Offset: 0x800
	// Line 944, Address: 0x2850e4, Func Offset: 0x804
	// Line 941, Address: 0x2850ec, Func Offset: 0x80c
	// Line 942, Address: 0x2850f4, Func Offset: 0x814
	// Line 944, Address: 0x2850f8, Func Offset: 0x818
	// Line 942, Address: 0x2850fc, Func Offset: 0x81c
	// Line 943, Address: 0x285100, Func Offset: 0x820
	// Line 944, Address: 0x285108, Func Offset: 0x828
	// Line 945, Address: 0x285128, Func Offset: 0x848
	// Line 948, Address: 0x285138, Func Offset: 0x858
	// Line 949, Address: 0x28514c, Func Offset: 0x86c
	// Line 950, Address: 0x285174, Func Offset: 0x894
	// Line 951, Address: 0x28517c, Func Offset: 0x89c
	// Line 952, Address: 0x28518c, Func Offset: 0x8ac
	// Line 953, Address: 0x285194, Func Offset: 0x8b4
	// Line 955, Address: 0x2851c0, Func Offset: 0x8e0
	// Line 956, Address: 0x2851d4, Func Offset: 0x8f4
	// Line 958, Address: 0x2851dc, Func Offset: 0x8fc
	// Line 959, Address: 0x2851f0, Func Offset: 0x910
	// Line 962, Address: 0x2851f8, Func Offset: 0x918
	// Line 963, Address: 0x28520c, Func Offset: 0x92c
	// Line 965, Address: 0x285214, Func Offset: 0x934
	// Line 966, Address: 0x285228, Func Offset: 0x948
	// Line 969, Address: 0x285230, Func Offset: 0x950
	// Line 970, Address: 0x285244, Func Offset: 0x964
	// Line 972, Address: 0x28524c, Func Offset: 0x96c
	// Line 975, Address: 0x285264, Func Offset: 0x984
	// Line 977, Address: 0x28528c, Func Offset: 0x9ac
	// Line 978, Address: 0x2852a4, Func Offset: 0x9c4
	// Line 977, Address: 0x2852a8, Func Offset: 0x9c8
	// Line 978, Address: 0x2852b4, Func Offset: 0x9d4
	// Line 979, Address: 0x2852cc, Func Offset: 0x9ec
	// Line 978, Address: 0x2852d0, Func Offset: 0x9f0
	// Line 979, Address: 0x2852dc, Func Offset: 0x9fc
	// Line 981, Address: 0x2852e4, Func Offset: 0xa04
	// Line 983, Address: 0x285328, Func Offset: 0xa48
	// Line 984, Address: 0x28533c, Func Offset: 0xa5c
	// Line 986, Address: 0x285344, Func Offset: 0xa64
	// Line 987, Address: 0x285358, Func Offset: 0xa78
	// Line 989, Address: 0x285360, Func Offset: 0xa80
	// Line 990, Address: 0x285374, Func Offset: 0xa94
	// Line 992, Address: 0x28537c, Func Offset: 0xa9c
	// Line 995, Address: 0x285394, Func Offset: 0xab4
	// Line 996, Address: 0x28539c, Func Offset: 0xabc
	// Line 998, Address: 0x2853a0, Func Offset: 0xac0
	// Line 999, Address: 0x2853a8, Func Offset: 0xac8
	// Line 1003, Address: 0x2853bc, Func Offset: 0xadc
	// Line 1004, Address: 0x2853cc, Func Offset: 0xaec
	// Line 1005, Address: 0x2853dc, Func Offset: 0xafc
	// Line 1006, Address: 0x2853e8, Func Offset: 0xb08
	// Line 1016, Address: 0x2853f0, Func Offset: 0xb10
	// Line 1006, Address: 0x2853f4, Func Offset: 0xb14
	// Line 1016, Address: 0x2853f8, Func Offset: 0xb18
	// Line 1007, Address: 0x2853fc, Func Offset: 0xb1c
	// Line 1006, Address: 0x285404, Func Offset: 0xb24
	// Line 1007, Address: 0x285414, Func Offset: 0xb34
	// Line 1006, Address: 0x285418, Func Offset: 0xb38
	// Line 1007, Address: 0x285424, Func Offset: 0xb44
	// Line 1008, Address: 0x285428, Func Offset: 0xb48
	// Line 1009, Address: 0x285430, Func Offset: 0xb50
	// Line 1008, Address: 0x285434, Func Offset: 0xb54
	// Line 1009, Address: 0x28543c, Func Offset: 0xb5c
	// Line 1010, Address: 0x285444, Func Offset: 0xb64
	// Line 1009, Address: 0x28544c, Func Offset: 0xb6c
	// Line 1010, Address: 0x28545c, Func Offset: 0xb7c
	// Line 1009, Address: 0x285460, Func Offset: 0xb80
	// Line 1010, Address: 0x28546c, Func Offset: 0xb8c
	// Line 1011, Address: 0x285470, Func Offset: 0xb90
	// Line 1012, Address: 0x285478, Func Offset: 0xb98
	// Line 1011, Address: 0x28547c, Func Offset: 0xb9c
	// Line 1012, Address: 0x285484, Func Offset: 0xba4
	// Line 1013, Address: 0x28548c, Func Offset: 0xbac
	// Line 1012, Address: 0x285494, Func Offset: 0xbb4
	// Line 1013, Address: 0x2854a4, Func Offset: 0xbc4
	// Line 1012, Address: 0x2854a8, Func Offset: 0xbc8
	// Line 1013, Address: 0x2854b4, Func Offset: 0xbd4
	// Line 1014, Address: 0x2854b8, Func Offset: 0xbd8
	// Line 1015, Address: 0x2854c0, Func Offset: 0xbe0
	// Line 1014, Address: 0x2854c4, Func Offset: 0xbe4
	// Line 1015, Address: 0x2854cc, Func Offset: 0xbec
	// Line 1016, Address: 0x2854d4, Func Offset: 0xbf4
	// Line 1015, Address: 0x2854dc, Func Offset: 0xbfc
	// Line 1016, Address: 0x2854e4, Func Offset: 0xc04
	// Line 1015, Address: 0x2854e8, Func Offset: 0xc08
	// Line 1016, Address: 0x2854f4, Func Offset: 0xc14
	// Line 1015, Address: 0x2854f8, Func Offset: 0xc18
	// Line 1016, Address: 0x285500, Func Offset: 0xc20
	// Line 1017, Address: 0x285504, Func Offset: 0xc24
	// Line 1021, Address: 0x285518, Func Offset: 0xc38
	// Func End, Address: 0x285534, Func Offset: 0xc54
}

// 
// Start address: 0x285540
void bhObj002(_anon0* op)
{
	// Line 1028, Address: 0x285540, Func Offset: 0
	// Line 1029, Address: 0x28554c, Func Offset: 0xc
	// Line 1030, Address: 0x285588, Func Offset: 0x48
	// Func End, Address: 0x285598, Func Offset: 0x58
}

// 
// Start address: 0x2855a0
void bhObj003(_anon0* op)
{
	// Line 1037, Address: 0x2855a0, Func Offset: 0
	// Line 1038, Address: 0x2855b0, Func Offset: 0x10
	// Line 1039, Address: 0x2855d0, Func Offset: 0x30
	// Line 1040, Address: 0x2855dc, Func Offset: 0x3c
	// Func End, Address: 0x2855ec, Func Offset: 0x4c
}

// 
// Start address: 0x2855f0
void bhObj004(_anon0* op)
{
	// Line 1047, Address: 0x2855f0, Func Offset: 0
	// Line 1048, Address: 0x285600, Func Offset: 0x10
	// Line 1050, Address: 0x285620, Func Offset: 0x30
	// Line 1051, Address: 0x285624, Func Offset: 0x34
	// Line 1052, Address: 0x285628, Func Offset: 0x38
	// Line 1053, Address: 0x28562c, Func Offset: 0x3c
	// Line 1054, Address: 0x285640, Func Offset: 0x50
	// Line 1055, Address: 0x285644, Func Offset: 0x54
	// Line 1057, Address: 0x28564c, Func Offset: 0x5c
	// Line 1060, Address: 0x285670, Func Offset: 0x80
	// Func End, Address: 0x285680, Func Offset: 0x90
}

// 
// Start address: 0x285680
void bhObj005(_anon0* op)
{
	_anon36* pOrg;
	_anon36* pCnk;
	float* wty;
	int wt_zp;
	int zp;
	int xp;
	int nb;
	int j;
	int i;
	_anon7* pp;
	_anon7* ps;
	_anon5* cmd;
	// Line 1072, Address: 0x285680, Func Offset: 0
	// Line 1089, Address: 0x2856a0, Func Offset: 0x20
	// Line 1091, Address: 0x2856c0, Func Offset: 0x40
	// Line 1092, Address: 0x2856d8, Func Offset: 0x58
	// Line 1093, Address: 0x2856f8, Func Offset: 0x78
	// Line 1094, Address: 0x2856fc, Func Offset: 0x7c
	// Line 1097, Address: 0x285704, Func Offset: 0x84
	// Line 1106, Address: 0x285708, Func Offset: 0x88
	// Line 1108, Address: 0x285710, Func Offset: 0x90
	// Line 1097, Address: 0x285714, Func Offset: 0x94
	// Line 1098, Address: 0x28571c, Func Offset: 0x9c
	// Line 1101, Address: 0x285720, Func Offset: 0xa0
	// Line 1102, Address: 0x285724, Func Offset: 0xa4
	// Line 1103, Address: 0x285728, Func Offset: 0xa8
	// Line 1106, Address: 0x28572c, Func Offset: 0xac
	// Line 1107, Address: 0x285734, Func Offset: 0xb4
	// Line 1108, Address: 0x285738, Func Offset: 0xb8
	// Line 1109, Address: 0x285740, Func Offset: 0xc0
	// Line 1110, Address: 0x285760, Func Offset: 0xe0
	// Line 1111, Address: 0x285764, Func Offset: 0xe4
	// Line 1113, Address: 0x285770, Func Offset: 0xf0
	// Line 1114, Address: 0x285790, Func Offset: 0x110
	// Line 1115, Address: 0x285794, Func Offset: 0x114
	// Line 1117, Address: 0x2857a0, Func Offset: 0x120
	// Line 1118, Address: 0x2857a4, Func Offset: 0x124
	// Line 1119, Address: 0x2857a8, Func Offset: 0x128
	// Line 1156, Address: 0x2857bc, Func Offset: 0x13c
	// Line 1157, Address: 0x2857cc, Func Offset: 0x14c
	// Line 1156, Address: 0x2857d4, Func Offset: 0x154
	// Line 1157, Address: 0x2857d8, Func Offset: 0x158
	// Line 1158, Address: 0x2857e0, Func Offset: 0x160
	// Line 1157, Address: 0x2857e8, Func Offset: 0x168
	// Line 1168, Address: 0x2857ec, Func Offset: 0x16c
	// Line 1158, Address: 0x2857f0, Func Offset: 0x170
	// Line 1168, Address: 0x2857f4, Func Offset: 0x174
	// Line 1158, Address: 0x2857f8, Func Offset: 0x178
	// Line 1159, Address: 0x285804, Func Offset: 0x184
	// Line 1168, Address: 0x285810, Func Offset: 0x190
	// Line 1159, Address: 0x285814, Func Offset: 0x194
	// Line 1160, Address: 0x285820, Func Offset: 0x1a0
	// Line 1161, Address: 0x285838, Func Offset: 0x1b8
	// Line 1162, Address: 0x28584c, Func Offset: 0x1cc
	// Line 1163, Address: 0x285860, Func Offset: 0x1e0
	// Line 1164, Address: 0x285874, Func Offset: 0x1f4
	// Line 1165, Address: 0x285888, Func Offset: 0x208
	// Line 1166, Address: 0x28589c, Func Offset: 0x21c
	// Line 1168, Address: 0x2858ac, Func Offset: 0x22c
	// Line 1169, Address: 0x2858b8, Func Offset: 0x238
	// Line 1172, Address: 0x2858c0, Func Offset: 0x240
	// Line 1169, Address: 0x2858c4, Func Offset: 0x244
	// Line 1172, Address: 0x2858c8, Func Offset: 0x248
	// Line 1169, Address: 0x2858d0, Func Offset: 0x250
	// Line 1171, Address: 0x2858dc, Func Offset: 0x25c
	// Line 1172, Address: 0x2858e0, Func Offset: 0x260
	// Line 1174, Address: 0x2858ec, Func Offset: 0x26c
	// Line 1173, Address: 0x2858f4, Func Offset: 0x274
	// Line 1174, Address: 0x2858fc, Func Offset: 0x27c
	// Line 1175, Address: 0x285908, Func Offset: 0x288
	// Line 1179, Address: 0x28590c, Func Offset: 0x28c
	// Line 1180, Address: 0x285918, Func Offset: 0x298
	// Line 1181, Address: 0x28592c, Func Offset: 0x2ac
	// Line 1182, Address: 0x285934, Func Offset: 0x2b4
	// Line 1183, Address: 0x285940, Func Offset: 0x2c0
	// Line 1187, Address: 0x285948, Func Offset: 0x2c8
	// Line 1183, Address: 0x28594c, Func Offset: 0x2cc
	// Line 1184, Address: 0x285968, Func Offset: 0x2e8
	// Line 1185, Address: 0x28596c, Func Offset: 0x2ec
	// Line 1186, Address: 0x285970, Func Offset: 0x2f0
	// Line 1187, Address: 0x285974, Func Offset: 0x2f4
	// Line 1189, Address: 0x285988, Func Offset: 0x308
	// Line 1190, Address: 0x285990, Func Offset: 0x310
	// Line 1189, Address: 0x285994, Func Offset: 0x314
	// Line 1191, Address: 0x2859a0, Func Offset: 0x320
	// Line 1195, Address: 0x2859a8, Func Offset: 0x328
	// Line 1197, Address: 0x2859d4, Func Offset: 0x354
	// Line 1198, Address: 0x2859ec, Func Offset: 0x36c
	// Line 1200, Address: 0x2859f4, Func Offset: 0x374
	// Line 1201, Address: 0x285a0c, Func Offset: 0x38c
	// Line 1203, Address: 0x285a14, Func Offset: 0x394
	// Line 1204, Address: 0x285a2c, Func Offset: 0x3ac
	// Line 1206, Address: 0x285a34, Func Offset: 0x3b4
	// Line 1207, Address: 0x285a4c, Func Offset: 0x3cc
	// Line 1209, Address: 0x285a54, Func Offset: 0x3d4
	// Line 1210, Address: 0x285a6c, Func Offset: 0x3ec
	// Line 1212, Address: 0x285a74, Func Offset: 0x3f4
	// Line 1213, Address: 0x285a8c, Func Offset: 0x40c
	// Line 1215, Address: 0x285a94, Func Offset: 0x414
	// Line 1216, Address: 0x285aac, Func Offset: 0x42c
	// Line 1218, Address: 0x285ab4, Func Offset: 0x434
	// Line 1219, Address: 0x285acc, Func Offset: 0x44c
	// Line 1221, Address: 0x285ad4, Func Offset: 0x454
	// Line 1222, Address: 0x285aec, Func Offset: 0x46c
	// Line 1224, Address: 0x285af4, Func Offset: 0x474
	// Line 1225, Address: 0x285b0c, Func Offset: 0x48c
	// Line 1227, Address: 0x285b14, Func Offset: 0x494
	// Line 1228, Address: 0x285b2c, Func Offset: 0x4ac
	// Line 1230, Address: 0x285b34, Func Offset: 0x4b4
	// Line 1231, Address: 0x285b4c, Func Offset: 0x4cc
	// Line 1233, Address: 0x285b54, Func Offset: 0x4d4
	// Line 1234, Address: 0x285b6c, Func Offset: 0x4ec
	// Line 1236, Address: 0x285b74, Func Offset: 0x4f4
	// Line 1237, Address: 0x285b8c, Func Offset: 0x50c
	// Line 1239, Address: 0x285b94, Func Offset: 0x514
	// Line 1240, Address: 0x285bac, Func Offset: 0x52c
	// Line 1242, Address: 0x285bb4, Func Offset: 0x534
	// Line 1245, Address: 0x285bcc, Func Offset: 0x54c
	// Line 1284, Address: 0x285bd0, Func Offset: 0x550
	// Line 1245, Address: 0x285bd4, Func Offset: 0x554
	// Line 1284, Address: 0x285be0, Func Offset: 0x560
	// Line 1286, Address: 0x285be4, Func Offset: 0x564
	// Line 1287, Address: 0x285be8, Func Offset: 0x568
	// Line 1675, Address: 0x285bec, Func Offset: 0x56c
	// Line 1284, Address: 0x285bf0, Func Offset: 0x570
	// Line 1292, Address: 0x285bfc, Func Offset: 0x57c
	// Line 1293, Address: 0x285c00, Func Offset: 0x580
	// Line 1285, Address: 0x285c04, Func Offset: 0x584
	// Line 1284, Address: 0x285c10, Func Offset: 0x590
	// Line 1677, Address: 0x285c14, Func Offset: 0x594
	// Line 1679, Address: 0x285c1c, Func Offset: 0x59c
	// Line 1680, Address: 0x285c28, Func Offset: 0x5a8
	// Line 1682, Address: 0x285c30, Func Offset: 0x5b0
	// Line 1683, Address: 0x285c34, Func Offset: 0x5b4
	// Line 1684, Address: 0x285c38, Func Offset: 0x5b8
	// Line 1685, Address: 0x285c3c, Func Offset: 0x5bc
	// Line 1686, Address: 0x285c40, Func Offset: 0x5c0
	// Line 1687, Address: 0x285c44, Func Offset: 0x5c4
	// Line 1688, Address: 0x285c48, Func Offset: 0x5c8
	// Line 1689, Address: 0x285c4c, Func Offset: 0x5cc
	// Line 1691, Address: 0x285c50, Func Offset: 0x5d0
	// Line 1692, Address: 0x285c54, Func Offset: 0x5d4
	// Line 1693, Address: 0x285c58, Func Offset: 0x5d8
	// Line 1694, Address: 0x285c5c, Func Offset: 0x5dc
	// Line 1695, Address: 0x285c60, Func Offset: 0x5e0
	// Line 1696, Address: 0x285c64, Func Offset: 0x5e4
	// Line 1697, Address: 0x285c68, Func Offset: 0x5e8
	// Line 1699, Address: 0x285c6c, Func Offset: 0x5ec
	// Line 1700, Address: 0x285c70, Func Offset: 0x5f0
	// Line 1701, Address: 0x285c74, Func Offset: 0x5f4
	// Line 1702, Address: 0x285c78, Func Offset: 0x5f8
	// Line 1703, Address: 0x285c7c, Func Offset: 0x5fc
	// Line 1704, Address: 0x285c80, Func Offset: 0x600
	// Line 1705, Address: 0x285c84, Func Offset: 0x604
	// Line 1706, Address: 0x285c88, Func Offset: 0x608
	// Line 1707, Address: 0x285c8c, Func Offset: 0x60c
	// Line 1709, Address: 0x285c94, Func Offset: 0x614
	// Line 1710, Address: 0x285c98, Func Offset: 0x618
	// Line 1711, Address: 0x285c9c, Func Offset: 0x61c
	// Line 1712, Address: 0x285ca0, Func Offset: 0x620
	// Line 1713, Address: 0x285ca4, Func Offset: 0x624
	// Line 1714, Address: 0x285ca8, Func Offset: 0x628
	// Line 1715, Address: 0x285cac, Func Offset: 0x62c
	// Line 1716, Address: 0x285cb0, Func Offset: 0x630
	// Line 1717, Address: 0x285cb4, Func Offset: 0x634
	// Line 1718, Address: 0x285cb8, Func Offset: 0x638
	// Line 1719, Address: 0x285cbc, Func Offset: 0x63c
	// Line 1720, Address: 0x285cc0, Func Offset: 0x640
	// Line 1721, Address: 0x285cc4, Func Offset: 0x644
	// Line 1722, Address: 0x285cc8, Func Offset: 0x648
	// Line 1723, Address: 0x285ccc, Func Offset: 0x64c
	// Line 1811, Address: 0x285cd4, Func Offset: 0x654
	// Line 1812, Address: 0x285d00, Func Offset: 0x680
	// Line 1813, Address: 0x285d04, Func Offset: 0x684
	// Line 1814, Address: 0x285d08, Func Offset: 0x688
	// Line 1815, Address: 0x285d0c, Func Offset: 0x68c
	// Line 1816, Address: 0x285d10, Func Offset: 0x690
	// Line 1817, Address: 0x285d14, Func Offset: 0x694
	// Line 1819, Address: 0x285d1c, Func Offset: 0x69c
	// Line 1820, Address: 0x285d20, Func Offset: 0x6a0
	// Line 1821, Address: 0x285d24, Func Offset: 0x6a4
	// Line 1822, Address: 0x285d28, Func Offset: 0x6a8
	// Line 1823, Address: 0x285d2c, Func Offset: 0x6ac
	// Line 1824, Address: 0x285d30, Func Offset: 0x6b0
	// Line 1825, Address: 0x285d34, Func Offset: 0x6b4
	// Line 1826, Address: 0x285d38, Func Offset: 0x6b8
	// Line 1827, Address: 0x285d3c, Func Offset: 0x6bc
	// Line 1828, Address: 0x285d40, Func Offset: 0x6c0
	// Line 1829, Address: 0x285d44, Func Offset: 0x6c4
	// Line 1830, Address: 0x285d48, Func Offset: 0x6c8
	// Line 1831, Address: 0x285d4c, Func Offset: 0x6cc
	// Line 1832, Address: 0x285d50, Func Offset: 0x6d0
	// Line 1833, Address: 0x285d54, Func Offset: 0x6d4
	// Line 1834, Address: 0x285d58, Func Offset: 0x6d8
	// Line 1836, Address: 0x285d5c, Func Offset: 0x6dc
	// Line 1837, Address: 0x285d64, Func Offset: 0x6e4
	// Line 1838, Address: 0x285d68, Func Offset: 0x6e8
	// Line 1840, Address: 0x285d6c, Func Offset: 0x6ec
	// Line 1841, Address: 0x285d74, Func Offset: 0x6f4
	// Line 1842, Address: 0x285d78, Func Offset: 0x6f8
	// Line 1843, Address: 0x285d7c, Func Offset: 0x6fc
	// Line 1844, Address: 0x285d80, Func Offset: 0x700
	// Line 1846, Address: 0x285d84, Func Offset: 0x704
	// Line 1858, Address: 0x285d8c, Func Offset: 0x70c
	// Func End, Address: 0x285db0, Func Offset: 0x730
}

// 
// Start address: 0x285db0
void bhObj006(_anon0* op)
{
	_anon3* lp;
	float len;
	_anon39 line;
	_anon32 ps0;
	_anon32 ps;
	npobj* obp;
	// Line 2074, Address: 0x285db0, Func Offset: 0
	// Line 2082, Address: 0x285ddc, Func Offset: 0x2c
	// Line 2086, Address: 0x285de0, Func Offset: 0x30
	// Line 2087, Address: 0x285de4, Func Offset: 0x34
	// Line 2082, Address: 0x285dec, Func Offset: 0x3c
	// Line 2083, Address: 0x285df0, Func Offset: 0x40
	// Line 2087, Address: 0x285df4, Func Offset: 0x44
	// Line 2083, Address: 0x285df8, Func Offset: 0x48
	// Line 2084, Address: 0x285dfc, Func Offset: 0x4c
	// Line 2085, Address: 0x285e04, Func Offset: 0x54
	// Line 2086, Address: 0x285e08, Func Offset: 0x58
	// Line 2087, Address: 0x285e0c, Func Offset: 0x5c
	// Line 2088, Address: 0x285e10, Func Offset: 0x60
	// Line 2089, Address: 0x285e18, Func Offset: 0x68
	// Line 2091, Address: 0x285e2c, Func Offset: 0x7c
	// Line 2092, Address: 0x285e34, Func Offset: 0x84
	// Line 2095, Address: 0x285e48, Func Offset: 0x98
	// Line 2096, Address: 0x285e5c, Func Offset: 0xac
	// Line 2106, Address: 0x285e70, Func Offset: 0xc0
	// Line 2109, Address: 0x285e78, Func Offset: 0xc8
	// Line 2107, Address: 0x285e7c, Func Offset: 0xcc
	// Line 2106, Address: 0x285e84, Func Offset: 0xd4
	// Line 2108, Address: 0x285e88, Func Offset: 0xd8
	// Line 2106, Address: 0x285e90, Func Offset: 0xe0
	// Line 2107, Address: 0x285e94, Func Offset: 0xe4
	// Line 2109, Address: 0x285e9c, Func Offset: 0xec
	// Line 2107, Address: 0x285ea8, Func Offset: 0xf8
	// Line 2109, Address: 0x285eac, Func Offset: 0xfc
	// Line 2107, Address: 0x285eb0, Func Offset: 0x100
	// Line 2108, Address: 0x285eb4, Func Offset: 0x104
	// Line 2109, Address: 0x285ec0, Func Offset: 0x110
	// Line 2113, Address: 0x285ec8, Func Offset: 0x118
	// Line 2114, Address: 0x285ed0, Func Offset: 0x120
	// Line 2115, Address: 0x285ed8, Func Offset: 0x128
	// Line 2116, Address: 0x285eec, Func Offset: 0x13c
	// Line 2118, Address: 0x285f00, Func Offset: 0x150
	// Line 2119, Address: 0x285f08, Func Offset: 0x158
	// Line 2122, Address: 0x285f1c, Func Offset: 0x16c
	// Line 2123, Address: 0x285f30, Func Offset: 0x180
	// Line 2124, Address: 0x285f38, Func Offset: 0x188
	// Line 2125, Address: 0x285f40, Func Offset: 0x190
	// Line 2126, Address: 0x285f50, Func Offset: 0x1a0
	// Line 2128, Address: 0x285f8c, Func Offset: 0x1dc
	// Line 2129, Address: 0x285f98, Func Offset: 0x1e8
	// Line 2130, Address: 0x285fa8, Func Offset: 0x1f8
	// Line 2129, Address: 0x285fac, Func Offset: 0x1fc
	// Line 2130, Address: 0x285fb0, Func Offset: 0x200
	// Line 2134, Address: 0x285fb8, Func Offset: 0x208
	// Line 2129, Address: 0x285fc0, Func Offset: 0x210
	// Line 2130, Address: 0x285fc4, Func Offset: 0x214
	// Line 2134, Address: 0x285fc8, Func Offset: 0x218
	// Line 2130, Address: 0x285fcc, Func Offset: 0x21c
	// Line 2131, Address: 0x285fd0, Func Offset: 0x220
	// Line 2129, Address: 0x285fd4, Func Offset: 0x224
	// Line 2131, Address: 0x285fd8, Func Offset: 0x228
	// Line 2132, Address: 0x285fe0, Func Offset: 0x230
	// Line 2133, Address: 0x285fec, Func Offset: 0x23c
	// Line 2134, Address: 0x285ff0, Func Offset: 0x240
	// Line 2135, Address: 0x286000, Func Offset: 0x250
	// Line 2136, Address: 0x28600c, Func Offset: 0x25c
	// Line 2135, Address: 0x286014, Func Offset: 0x264
	// Line 2136, Address: 0x28601c, Func Offset: 0x26c
	// Line 2137, Address: 0x286030, Func Offset: 0x280
	// Line 2138, Address: 0x286044, Func Offset: 0x294
	// Line 2139, Address: 0x286064, Func Offset: 0x2b4
	// Line 2140, Address: 0x286078, Func Offset: 0x2c8
	// Line 2141, Address: 0x286080, Func Offset: 0x2d0
	// Line 2142, Address: 0x286088, Func Offset: 0x2d8
	// Line 2143, Address: 0x286090, Func Offset: 0x2e0
	// Line 2145, Address: 0x286098, Func Offset: 0x2e8
	// Line 2146, Address: 0x2860a0, Func Offset: 0x2f0
	// Line 2148, Address: 0x2860b4, Func Offset: 0x304
	// Line 2149, Address: 0x2860bc, Func Offset: 0x30c
	// Line 2152, Address: 0x2860d0, Func Offset: 0x320
	// Line 2153, Address: 0x2860e4, Func Offset: 0x334
	// Line 2154, Address: 0x2860f4, Func Offset: 0x344
	// Line 2155, Address: 0x286104, Func Offset: 0x354
	// Line 2156, Address: 0x286114, Func Offset: 0x364
	// Line 2158, Address: 0x286124, Func Offset: 0x374
	// Func End, Address: 0x286154, Func Offset: 0x3a4
}

// 
// Start address: 0x286160
void bhObj007(_anon0* op)
{
	float inn;
	float len2;
	float len1;
	float len0;
	_anon32 ps2;
	_anon32 ps1;
	_anon32 ps0;
	_anon39 lin;
	// Line 2165, Address: 0x286160, Func Offset: 0
	// Line 2169, Address: 0x286194, Func Offset: 0x34
	// Line 2170, Address: 0x2861b4, Func Offset: 0x54
	// Line 2172, Address: 0x2861f8, Func Offset: 0x98
	// Line 2174, Address: 0x2861fc, Func Offset: 0x9c
	// Line 2176, Address: 0x286204, Func Offset: 0xa4
	// Line 2177, Address: 0x28620c, Func Offset: 0xac
	// Line 2178, Address: 0x286210, Func Offset: 0xb0
	// Line 2179, Address: 0x286218, Func Offset: 0xb8
	// Line 2180, Address: 0x286234, Func Offset: 0xd4
	// Line 2181, Address: 0x286238, Func Offset: 0xd8
	// Line 2182, Address: 0x286254, Func Offset: 0xf4
	// Line 2183, Address: 0x28626c, Func Offset: 0x10c
	// Line 2185, Address: 0x28627c, Func Offset: 0x11c
	// Line 2186, Address: 0x286280, Func Offset: 0x120
	// Line 2183, Address: 0x286284, Func Offset: 0x124
	// Line 2184, Address: 0x28628c, Func Offset: 0x12c
	// Line 2185, Address: 0x28629c, Func Offset: 0x13c
	// Line 2186, Address: 0x2862a0, Func Offset: 0x140
	// Line 2187, Address: 0x2862ac, Func Offset: 0x14c
	// Line 2188, Address: 0x2862b4, Func Offset: 0x154
	// Line 2189, Address: 0x2862c0, Func Offset: 0x160
	// Line 2191, Address: 0x2862dc, Func Offset: 0x17c
	// Line 2190, Address: 0x2862e4, Func Offset: 0x184
	// Line 2191, Address: 0x2862e8, Func Offset: 0x188
	// Line 2192, Address: 0x2862f4, Func Offset: 0x194
	// Line 2199, Address: 0x286308, Func Offset: 0x1a8
	// Line 2200, Address: 0x286314, Func Offset: 0x1b4
	// Line 2201, Address: 0x286318, Func Offset: 0x1b8
	// Line 2199, Address: 0x28631c, Func Offset: 0x1bc
	// Line 2202, Address: 0x286320, Func Offset: 0x1c0
	// Line 2199, Address: 0x286324, Func Offset: 0x1c4
	// Line 2200, Address: 0x28632c, Func Offset: 0x1cc
	// Line 2201, Address: 0x286330, Func Offset: 0x1d0
	// Line 2202, Address: 0x28633c, Func Offset: 0x1dc
	// Line 2203, Address: 0x286344, Func Offset: 0x1e4
	// Line 2204, Address: 0x286350, Func Offset: 0x1f0
	// Line 2205, Address: 0x28635c, Func Offset: 0x1fc
	// Line 2204, Address: 0x286364, Func Offset: 0x204
	// Line 2205, Address: 0x286368, Func Offset: 0x208
	// Line 2208, Address: 0x28636c, Func Offset: 0x20c
	// Line 2205, Address: 0x286370, Func Offset: 0x210
	// Line 2206, Address: 0x28637c, Func Offset: 0x21c
	// Line 2207, Address: 0x286380, Func Offset: 0x220
	// Line 2208, Address: 0x28638c, Func Offset: 0x22c
	// Line 2209, Address: 0x286394, Func Offset: 0x234
	// Line 2210, Address: 0x2863a0, Func Offset: 0x240
	// Line 2211, Address: 0x2863e8, Func Offset: 0x288
	// Line 2212, Address: 0x28640c, Func Offset: 0x2ac
	// Line 2213, Address: 0x286438, Func Offset: 0x2d8
	// Line 2214, Address: 0x286450, Func Offset: 0x2f0
	// Line 2215, Address: 0x286454, Func Offset: 0x2f4
	// Line 2216, Address: 0x286468, Func Offset: 0x308
	// Line 2221, Address: 0x286478, Func Offset: 0x318
	// Line 2226, Address: 0x2864f0, Func Offset: 0x390
	// Line 2230, Address: 0x286510, Func Offset: 0x3b0
	// Line 2231, Address: 0x28651c, Func Offset: 0x3bc
	// Line 2233, Address: 0x28652c, Func Offset: 0x3cc
	// Line 2234, Address: 0x286540, Func Offset: 0x3e0
	// Line 2235, Address: 0x286544, Func Offset: 0x3e4
	// Line 2236, Address: 0x286554, Func Offset: 0x3f4
	// Line 2237, Address: 0x28657c, Func Offset: 0x41c
	// Line 2239, Address: 0x286588, Func Offset: 0x428
	// Line 2237, Address: 0x28658c, Func Offset: 0x42c
	// Line 2240, Address: 0x286594, Func Offset: 0x434
	// Line 2241, Address: 0x28659c, Func Offset: 0x43c
	// Line 2243, Address: 0x2865a8, Func Offset: 0x448
	// Line 2241, Address: 0x2865ac, Func Offset: 0x44c
	// Line 2243, Address: 0x2865b4, Func Offset: 0x454
	// Line 2245, Address: 0x2865b8, Func Offset: 0x458
	// Line 2246, Address: 0x2865c0, Func Offset: 0x460
	// Line 2245, Address: 0x2865c4, Func Offset: 0x464
	// Line 2246, Address: 0x2865c8, Func Offset: 0x468
	// Line 2245, Address: 0x2865cc, Func Offset: 0x46c
	// Line 2246, Address: 0x2865d4, Func Offset: 0x474
	// Line 2247, Address: 0x2865dc, Func Offset: 0x47c
	// Line 2251, Address: 0x2865e8, Func Offset: 0x488
	// Line 2255, Address: 0x2865f0, Func Offset: 0x490
	// Line 2257, Address: 0x2865f8, Func Offset: 0x498
	// Line 2258, Address: 0x286610, Func Offset: 0x4b0
	// Line 2259, Address: 0x286630, Func Offset: 0x4d0
	// Line 2261, Address: 0x286638, Func Offset: 0x4d8
	// Line 2263, Address: 0x286640, Func Offset: 0x4e0
	// Line 2264, Address: 0x286674, Func Offset: 0x514
	// Line 2263, Address: 0x286678, Func Offset: 0x518
	// Line 2264, Address: 0x286680, Func Offset: 0x520
	// Line 2265, Address: 0x286690, Func Offset: 0x530
	// Line 2266, Address: 0x2866b4, Func Offset: 0x554
	// Line 2267, Address: 0x2866d0, Func Offset: 0x570
	// Line 2266, Address: 0x2866d4, Func Offset: 0x574
	// Line 2267, Address: 0x2866e0, Func Offset: 0x580
	// Line 2268, Address: 0x286714, Func Offset: 0x5b4
	// Line 2269, Address: 0x28674c, Func Offset: 0x5ec
	// Line 2271, Address: 0x286768, Func Offset: 0x608
	// Line 2272, Address: 0x28676c, Func Offset: 0x60c
	// Line 2273, Address: 0x286778, Func Offset: 0x618
	// Line 2275, Address: 0x28677c, Func Offset: 0x61c
	// Line 2272, Address: 0x286780, Func Offset: 0x620
	// Line 2273, Address: 0x286784, Func Offset: 0x624
	// Line 2275, Address: 0x286788, Func Offset: 0x628
	// Line 2276, Address: 0x286798, Func Offset: 0x638
	// Line 2279, Address: 0x2867a0, Func Offset: 0x640
	// Line 2280, Address: 0x2867b0, Func Offset: 0x650
	// Line 2282, Address: 0x2867b8, Func Offset: 0x658
	// Line 2287, Address: 0x2867c0, Func Offset: 0x660
	// Line 2288, Address: 0x2867d8, Func Offset: 0x678
	// Line 2289, Address: 0x2867f8, Func Offset: 0x698
	// Line 2291, Address: 0x286800, Func Offset: 0x6a0
	// Line 2293, Address: 0x286808, Func Offset: 0x6a8
	// Line 2294, Address: 0x28683c, Func Offset: 0x6dc
	// Line 2293, Address: 0x286840, Func Offset: 0x6e0
	// Line 2294, Address: 0x286848, Func Offset: 0x6e8
	// Line 2295, Address: 0x286858, Func Offset: 0x6f8
	// Line 2296, Address: 0x28687c, Func Offset: 0x71c
	// Line 2297, Address: 0x286898, Func Offset: 0x738
	// Line 2296, Address: 0x28689c, Func Offset: 0x73c
	// Line 2297, Address: 0x2868a8, Func Offset: 0x748
	// Line 2298, Address: 0x2868dc, Func Offset: 0x77c
	// Line 2299, Address: 0x286914, Func Offset: 0x7b4
	// Line 2301, Address: 0x286930, Func Offset: 0x7d0
	// Line 2302, Address: 0x286934, Func Offset: 0x7d4
	// Line 2303, Address: 0x286940, Func Offset: 0x7e0
	// Line 2305, Address: 0x286944, Func Offset: 0x7e4
	// Line 2302, Address: 0x286948, Func Offset: 0x7e8
	// Line 2303, Address: 0x28694c, Func Offset: 0x7ec
	// Line 2305, Address: 0x286950, Func Offset: 0x7f0
	// Line 2306, Address: 0x286960, Func Offset: 0x800
	// Line 2309, Address: 0x286968, Func Offset: 0x808
	// Line 2310, Address: 0x286978, Func Offset: 0x818
	// Line 2311, Address: 0x286980, Func Offset: 0x820
	// Line 2319, Address: 0x286984, Func Offset: 0x824
	// Func End, Address: 0x2869bc, Func Offset: 0x85c
}

// 
// Start address: 0x2869c0
void bhObj008(_anon0* op)
{
	_anon22* hp;
	// Line 2328, Address: 0x2869c0, Func Offset: 0
	// Line 2329, Address: 0x2869cc, Func Offset: 0xc
	// Line 2330, Address: 0x2869e0, Func Offset: 0x20
	// Line 2331, Address: 0x2869e4, Func Offset: 0x24
	// Line 2333, Address: 0x2869ec, Func Offset: 0x2c
	// Line 2334, Address: 0x2869f4, Func Offset: 0x34
	// Line 2343, Address: 0x2869f8, Func Offset: 0x38
	// Line 2337, Address: 0x286a00, Func Offset: 0x40
	// Line 2339, Address: 0x286a04, Func Offset: 0x44
	// Line 2334, Address: 0x286a08, Func Offset: 0x48
	// Line 2335, Address: 0x286a0c, Func Offset: 0x4c
	// Line 2345, Address: 0x286a10, Func Offset: 0x50
	// Line 2346, Address: 0x286a18, Func Offset: 0x58
	// Line 2347, Address: 0x286a1c, Func Offset: 0x5c
	// Line 2348, Address: 0x286a20, Func Offset: 0x60
	// Line 2335, Address: 0x286a24, Func Offset: 0x64
	// Line 2336, Address: 0x286a28, Func Offset: 0x68
	// Line 2353, Address: 0x286a2c, Func Offset: 0x6c
	// Line 2336, Address: 0x286a30, Func Offset: 0x70
	// Line 2337, Address: 0x286a34, Func Offset: 0x74
	// Line 2338, Address: 0x286a58, Func Offset: 0x98
	// Line 2339, Address: 0x286a80, Func Offset: 0xc0
	// Line 2340, Address: 0x286a84, Func Offset: 0xc4
	// Line 2341, Address: 0x286a88, Func Offset: 0xc8
	// Line 2344, Address: 0x286a8c, Func Offset: 0xcc
	// Line 2341, Address: 0x286a90, Func Offset: 0xd0
	// Line 2342, Address: 0x286a94, Func Offset: 0xd4
	// Line 2343, Address: 0x286a98, Func Offset: 0xd8
	// Line 2344, Address: 0x286aa4, Func Offset: 0xe4
	// Line 2345, Address: 0x286abc, Func Offset: 0xfc
	// Line 2346, Address: 0x286ac8, Func Offset: 0x108
	// Line 2347, Address: 0x286acc, Func Offset: 0x10c
	// Line 2348, Address: 0x286ad0, Func Offset: 0x110
	// Line 2349, Address: 0x286ad4, Func Offset: 0x114
	// Line 2354, Address: 0x286ae4, Func Offset: 0x124
	// Line 2356, Address: 0x286aec, Func Offset: 0x12c
	// Line 2355, Address: 0x286af4, Func Offset: 0x134
	// Line 2358, Address: 0x286af8, Func Offset: 0x138
	// Line 2356, Address: 0x286b00, Func Offset: 0x140
	// Line 2355, Address: 0x286b04, Func Offset: 0x144
	// Line 2356, Address: 0x286b14, Func Offset: 0x154
	// Line 2355, Address: 0x286b18, Func Offset: 0x158
	// Line 2356, Address: 0x286b20, Func Offset: 0x160
	// Line 2355, Address: 0x286b24, Func Offset: 0x164
	// Line 2356, Address: 0x286b30, Func Offset: 0x170
	// Line 2357, Address: 0x286b38, Func Offset: 0x178
	// Line 2358, Address: 0x286b48, Func Offset: 0x188
	// Line 2360, Address: 0x286b5c, Func Offset: 0x19c
	// Func End, Address: 0x286b64, Func Offset: 0x1a4
}

// 
// Start address: 0x286b70
void bhObj009(_anon0* op)
{
	float ln;
	_anon32 vec;
	_anon9* ptp;
	// Line 2371, Address: 0x286b70, Func Offset: 0
	// Line 2375, Address: 0x286b88, Func Offset: 0x18
	// Line 2377, Address: 0x286ba8, Func Offset: 0x38
	// Line 2379, Address: 0x286bc0, Func Offset: 0x50
	// Line 2380, Address: 0x286bc8, Func Offset: 0x58
	// Line 2385, Address: 0x286bcc, Func Offset: 0x5c
	// Line 2379, Address: 0x286bd0, Func Offset: 0x60
	// Line 2380, Address: 0x286bd4, Func Offset: 0x64
	// Line 2381, Address: 0x286bd8, Func Offset: 0x68
	// Line 2382, Address: 0x286be0, Func Offset: 0x70
	// Line 2383, Address: 0x286bf8, Func Offset: 0x88
	// Line 2384, Address: 0x286c14, Func Offset: 0xa4
	// Line 2385, Address: 0x286c18, Func Offset: 0xa8
	// Line 2386, Address: 0x286c34, Func Offset: 0xc4
	// Line 2387, Address: 0x286c48, Func Offset: 0xd8
	// Line 2388, Address: 0x286c54, Func Offset: 0xe4
	// Line 2389, Address: 0x286c70, Func Offset: 0x100
	// Line 2390, Address: 0x286c84, Func Offset: 0x114
	// Line 2391, Address: 0x286c8c, Func Offset: 0x11c
	// Line 2392, Address: 0x286c94, Func Offset: 0x124
	// Line 2393, Address: 0x286c9c, Func Offset: 0x12c
	// Line 2394, Address: 0x286cac, Func Offset: 0x13c
	// Line 2395, Address: 0x286cb8, Func Offset: 0x148
	// Line 2396, Address: 0x286cbc, Func Offset: 0x14c
	// Line 2397, Address: 0x286cd4, Func Offset: 0x164
	// Line 2398, Address: 0x286cec, Func Offset: 0x17c
	// Line 2400, Address: 0x286cf8, Func Offset: 0x188
	// Line 2401, Address: 0x286d08, Func Offset: 0x198
	// Line 2402, Address: 0x286d10, Func Offset: 0x1a0
	// Line 2408, Address: 0x286d14, Func Offset: 0x1a4
	// Line 2402, Address: 0x286d1c, Func Offset: 0x1ac
	// Line 2403, Address: 0x286d2c, Func Offset: 0x1bc
	// Line 2404, Address: 0x286d40, Func Offset: 0x1d0
	// Line 2405, Address: 0x286d48, Func Offset: 0x1d8
	// Line 2406, Address: 0x286d50, Func Offset: 0x1e0
	// Line 2408, Address: 0x286d6c, Func Offset: 0x1fc
	// Line 2409, Address: 0x286d80, Func Offset: 0x210
	// Line 2411, Address: 0x286d94, Func Offset: 0x224
	// Line 2410, Address: 0x286d98, Func Offset: 0x228
	// Line 2412, Address: 0x286d9c, Func Offset: 0x22c
	// Line 2414, Address: 0x286da4, Func Offset: 0x234
	// Line 2415, Address: 0x286dac, Func Offset: 0x23c
	// Line 2419, Address: 0x286dcc, Func Offset: 0x25c
	// Line 2420, Address: 0x286e0c, Func Offset: 0x29c
	// Line 2421, Address: 0x286e50, Func Offset: 0x2e0
	// Line 2422, Address: 0x286e6c, Func Offset: 0x2fc
	// Line 2423, Address: 0x286e80, Func Offset: 0x310
	// Line 2425, Address: 0x286ea4, Func Offset: 0x334
	// Line 2426, Address: 0x286ee0, Func Offset: 0x370
	// Line 2427, Address: 0x286ee8, Func Offset: 0x378
	// Line 2429, Address: 0x286ef8, Func Offset: 0x388
	// Line 2430, Address: 0x286f34, Func Offset: 0x3c4
	// Line 2435, Address: 0x286f48, Func Offset: 0x3d8
	// Line 2437, Address: 0x286f50, Func Offset: 0x3e0
	// Line 2439, Address: 0x286f70, Func Offset: 0x400
	// Line 2441, Address: 0x286f78, Func Offset: 0x408
	// Line 2439, Address: 0x286f7c, Func Offset: 0x40c
	// Line 2440, Address: 0x286f80, Func Offset: 0x410
	// Line 2441, Address: 0x286f90, Func Offset: 0x420
	// Line 2442, Address: 0x286fa0, Func Offset: 0x430
	// Line 2451, Address: 0x286fbc, Func Offset: 0x44c
	// Line 2442, Address: 0x286fc0, Func Offset: 0x450
	// Line 2453, Address: 0x286fc4, Func Offset: 0x454
	// Line 2443, Address: 0x286fc8, Func Offset: 0x458
	// Line 2444, Address: 0x286fcc, Func Offset: 0x45c
	// Line 2445, Address: 0x286fe0, Func Offset: 0x470
	// Line 2446, Address: 0x286ff4, Func Offset: 0x484
	// Line 2447, Address: 0x286ffc, Func Offset: 0x48c
	// Line 2448, Address: 0x287004, Func Offset: 0x494
	// Line 2449, Address: 0x287008, Func Offset: 0x498
	// Line 2450, Address: 0x287014, Func Offset: 0x4a4
	// Line 2451, Address: 0x28701c, Func Offset: 0x4ac
	// Line 2452, Address: 0x287020, Func Offset: 0x4b0
	// Line 2453, Address: 0x287028, Func Offset: 0x4b8
	// Line 2455, Address: 0x28702c, Func Offset: 0x4bc
	// Line 2457, Address: 0x287034, Func Offset: 0x4c4
	// Line 2458, Address: 0x287040, Func Offset: 0x4d0
	// Line 2459, Address: 0x287050, Func Offset: 0x4e0
	// Line 2460, Address: 0x287070, Func Offset: 0x500
	// Line 2465, Address: 0x287074, Func Offset: 0x504
	// Func End, Address: 0x287090, Func Offset: 0x520
}

// 
// Start address: 0x287090
void bhObj010(_anon0* op)
{
	// Line 2472, Address: 0x287090, Func Offset: 0
	// Line 2473, Address: 0x28709c, Func Offset: 0xc
	// Line 2474, Address: 0x2870bc, Func Offset: 0x2c
	// Line 2475, Address: 0x2870d4, Func Offset: 0x44
	// Line 2476, Address: 0x2870e4, Func Offset: 0x54
	// Line 2477, Address: 0x2870f0, Func Offset: 0x60
	// Line 2480, Address: 0x287108, Func Offset: 0x78
	// Func End, Address: 0x287118, Func Offset: 0x88
}

// 
// Start address: 0x287120
void bhObj011(_anon0* op)
{
	// Line 2488, Address: 0x287120, Func Offset: 0
	// Line 2489, Address: 0x287128, Func Offset: 0x8
	// Func End, Address: 0x287130, Func Offset: 0x10
}

// 
// Start address: 0x287130
void bhObj012(_anon0* op)
{
	_anon22* hp;
	// Line 2498, Address: 0x287130, Func Offset: 0
	// Line 2499, Address: 0x28713c, Func Offset: 0xc
	// Line 2507, Address: 0x287150, Func Offset: 0x20
	// Line 2508, Address: 0x287154, Func Offset: 0x24
	// Line 2510, Address: 0x28715c, Func Offset: 0x2c
	// Line 2511, Address: 0x287164, Func Offset: 0x34
	// Line 2513, Address: 0x28716c, Func Offset: 0x3c
	// Line 2514, Address: 0x287170, Func Offset: 0x40
	// Line 2516, Address: 0x287174, Func Offset: 0x44
	// Line 2511, Address: 0x287178, Func Offset: 0x48
	// Line 2520, Address: 0x287184, Func Offset: 0x54
	// Line 2521, Address: 0x287188, Func Offset: 0x58
	// Line 2527, Address: 0x28718c, Func Offset: 0x5c
	// Line 2511, Address: 0x287190, Func Offset: 0x60
	// Line 2512, Address: 0x2871a4, Func Offset: 0x74
	// Line 2513, Address: 0x2871cc, Func Offset: 0x9c
	// Line 2514, Address: 0x2871d0, Func Offset: 0xa0
	// Line 2515, Address: 0x2871d4, Func Offset: 0xa4
	// Line 2518, Address: 0x2871d8, Func Offset: 0xa8
	// Line 2515, Address: 0x2871dc, Func Offset: 0xac
	// Line 2516, Address: 0x2871e0, Func Offset: 0xb0
	// Line 2517, Address: 0x2871e4, Func Offset: 0xb4
	// Line 2518, Address: 0x2871ec, Func Offset: 0xbc
	// Line 2526, Address: 0x287200, Func Offset: 0xd0
	// Line 2518, Address: 0x287204, Func Offset: 0xd4
	// Line 2519, Address: 0x287208, Func Offset: 0xd8
	// Line 2520, Address: 0x287210, Func Offset: 0xe0
	// Line 2521, Address: 0x287214, Func Offset: 0xe4
	// Line 2522, Address: 0x287218, Func Offset: 0xe8
	// Line 2523, Address: 0x28721c, Func Offset: 0xec
	// Line 2526, Address: 0x287228, Func Offset: 0xf8
	// Line 2528, Address: 0x28723c, Func Offset: 0x10c
	// Line 2530, Address: 0x287244, Func Offset: 0x114
	// Line 2529, Address: 0x287248, Func Offset: 0x118
	// Line 2530, Address: 0x287254, Func Offset: 0x124
	// Line 2529, Address: 0x287258, Func Offset: 0x128
	// Line 2530, Address: 0x287268, Func Offset: 0x138
	// Line 2529, Address: 0x28726c, Func Offset: 0x13c
	// Line 2530, Address: 0x287278, Func Offset: 0x148
	// Line 2531, Address: 0x28727c, Func Offset: 0x14c
	// Line 2532, Address: 0x28728c, Func Offset: 0x15c
	// Line 2534, Address: 0x28729c, Func Offset: 0x16c
	// Func End, Address: 0x2872a4, Func Offset: 0x174
}

// 
// Start address: 0x2872b0
void bhObjClpn(_anon0* op)
{
	float ln;
	float pz;
	float py;
	_anon32 ps5;
	_anon32 ps4;
	_anon32 ps3;
	_anon32 ps2;
	_anon32 ps1;
	_anon32* psp;
	_anon32* g3p;
	_anon32* p3p;
	short ry;
	short rx;
	short ay;
	short ax;
	int i;
	_anon35* hair;
	BH_PWORK* pp;
	// Line 2547, Address: 0x2872b0, Func Offset: 0
	// Line 2556, Address: 0x2872e8, Func Offset: 0x38
	// Line 2557, Address: 0x2872f8, Func Offset: 0x48
	// Line 2559, Address: 0x287324, Func Offset: 0x74
	// Line 2560, Address: 0x28732c, Func Offset: 0x7c
	// Line 2561, Address: 0x287340, Func Offset: 0x90
	// Line 2562, Address: 0x287348, Func Offset: 0x98
	// Line 2563, Address: 0x28735c, Func Offset: 0xac
	// Line 2564, Address: 0x287378, Func Offset: 0xc8
	// Line 2565, Address: 0x28738c, Func Offset: 0xdc
	// Line 2566, Address: 0x287394, Func Offset: 0xe4
	// Line 2567, Address: 0x2873a0, Func Offset: 0xf0
	// Line 2570, Address: 0x2873b4, Func Offset: 0x104
	// Line 2571, Address: 0x2873b8, Func Offset: 0x108
	// Line 2572, Address: 0x2873bc, Func Offset: 0x10c
	// Line 2573, Address: 0x2873c0, Func Offset: 0x110
	// Line 2574, Address: 0x2873c4, Func Offset: 0x114
	// Line 2575, Address: 0x2873c8, Func Offset: 0x118
	// Line 2576, Address: 0x2873cc, Func Offset: 0x11c
	// Line 2577, Address: 0x2873d8, Func Offset: 0x128
	// Line 2578, Address: 0x2873dc, Func Offset: 0x12c
	// Line 2579, Address: 0x2873e0, Func Offset: 0x130
	// Line 2581, Address: 0x2873e4, Func Offset: 0x134
	// Line 2580, Address: 0x2873e8, Func Offset: 0x138
	// Line 2581, Address: 0x2873ec, Func Offset: 0x13c
	// Line 2582, Address: 0x2873f8, Func Offset: 0x148
	// Line 2583, Address: 0x287404, Func Offset: 0x154
	// Line 2585, Address: 0x287410, Func Offset: 0x160
	// Line 2584, Address: 0x287414, Func Offset: 0x164
	// Line 2586, Address: 0x287418, Func Offset: 0x168
	// Line 2589, Address: 0x287420, Func Offset: 0x170
	// Line 2588, Address: 0x287424, Func Offset: 0x174
	// Line 2590, Address: 0x287428, Func Offset: 0x178
	// Line 2588, Address: 0x28742c, Func Offset: 0x17c
	// Line 2590, Address: 0x287430, Func Offset: 0x180
	// Line 2591, Address: 0x28743c, Func Offset: 0x18c
	// Line 2593, Address: 0x287448, Func Offset: 0x198
	// Line 2594, Address: 0x287458, Func Offset: 0x1a8
	// Line 2595, Address: 0x287468, Func Offset: 0x1b8
	// Line 2596, Address: 0x28746c, Func Offset: 0x1bc
	// Line 2597, Address: 0x287470, Func Offset: 0x1c0
	// Line 2598, Address: 0x28747c, Func Offset: 0x1cc
	// Line 2599, Address: 0x287480, Func Offset: 0x1d0
	// Line 2600, Address: 0x287484, Func Offset: 0x1d4
	// Line 2602, Address: 0x287488, Func Offset: 0x1d8
	// Line 2601, Address: 0x28748c, Func Offset: 0x1dc
	// Line 2602, Address: 0x287490, Func Offset: 0x1e0
	// Line 2603, Address: 0x287498, Func Offset: 0x1e8
	// Line 2604, Address: 0x2874a4, Func Offset: 0x1f4
	// Line 2605, Address: 0x2874b0, Func Offset: 0x200
	// Line 2607, Address: 0x2874b4, Func Offset: 0x204
	// Line 2610, Address: 0x2874c0, Func Offset: 0x210
	// Line 2608, Address: 0x2874c4, Func Offset: 0x214
	// Line 2630, Address: 0x2874cc, Func Offset: 0x21c
	// Line 2631, Address: 0x2874d0, Func Offset: 0x220
	// Line 2634, Address: 0x2874d4, Func Offset: 0x224
	// Line 2610, Address: 0x2874d8, Func Offset: 0x228
	// Line 2611, Address: 0x2874f4, Func Offset: 0x244
	// Line 2610, Address: 0x2874f8, Func Offset: 0x248
	// Line 2611, Address: 0x2874fc, Func Offset: 0x24c
	// Line 2620, Address: 0x287500, Func Offset: 0x250
	// Line 2611, Address: 0x287508, Func Offset: 0x258
	// Line 2608, Address: 0x28750c, Func Offset: 0x25c
	// Line 2620, Address: 0x287510, Func Offset: 0x260
	// Line 2608, Address: 0x287514, Func Offset: 0x264
	// Line 2620, Address: 0x287518, Func Offset: 0x268
	// Line 2608, Address: 0x28751c, Func Offset: 0x26c
	// Line 2620, Address: 0x287524, Func Offset: 0x274
	// Line 2611, Address: 0x287528, Func Offset: 0x278
	// Line 2620, Address: 0x28752c, Func Offset: 0x27c
	// Line 2621, Address: 0x287548, Func Offset: 0x298
	// Line 2622, Address: 0x28755c, Func Offset: 0x2ac
	// Line 2623, Address: 0x287570, Func Offset: 0x2c0
	// Line 2626, Address: 0x287574, Func Offset: 0x2c4
	// Line 2623, Address: 0x287578, Func Offset: 0x2c8
	// Line 2624, Address: 0x287580, Func Offset: 0x2d0
	// Line 2625, Address: 0x287584, Func Offset: 0x2d4
	// Line 2626, Address: 0x287588, Func Offset: 0x2d8
	// Line 2627, Address: 0x28758c, Func Offset: 0x2dc
	// Line 2628, Address: 0x287594, Func Offset: 0x2e4
	// Line 2632, Address: 0x28759c, Func Offset: 0x2ec
	// Line 2633, Address: 0x2875a4, Func Offset: 0x2f4
	// Line 2637, Address: 0x2875a8, Func Offset: 0x2f8
	// Line 2639, Address: 0x2875b4, Func Offset: 0x304
	// Line 2637, Address: 0x2875b8, Func Offset: 0x308
	// Line 2639, Address: 0x2875cc, Func Offset: 0x31c
	// Line 2640, Address: 0x2875d4, Func Offset: 0x324
	// Line 2641, Address: 0x2875e4, Func Offset: 0x334
	// Line 2642, Address: 0x2875f4, Func Offset: 0x344
	// Line 2644, Address: 0x287604, Func Offset: 0x354
	// Line 2643, Address: 0x28760c, Func Offset: 0x35c
	// Line 2644, Address: 0x287610, Func Offset: 0x360
	// Line 2646, Address: 0x287618, Func Offset: 0x368
	// Line 2648, Address: 0x287620, Func Offset: 0x370
	// Line 2651, Address: 0x287624, Func Offset: 0x374
	// Line 2652, Address: 0x287630, Func Offset: 0x380
	// Line 2648, Address: 0x287634, Func Offset: 0x384
	// Line 2650, Address: 0x28763c, Func Offset: 0x38c
	// Line 2652, Address: 0x287644, Func Offset: 0x394
	// Line 2650, Address: 0x287648, Func Offset: 0x398
	// Line 2651, Address: 0x28764c, Func Offset: 0x39c
	// Line 2650, Address: 0x287650, Func Offset: 0x3a0
	// Line 2652, Address: 0x287654, Func Offset: 0x3a4
	// Line 2653, Address: 0x287668, Func Offset: 0x3b8
	// Line 2654, Address: 0x287690, Func Offset: 0x3e0
	// Line 2656, Address: 0x2876a4, Func Offset: 0x3f4
	// Line 2660, Address: 0x2876b0, Func Offset: 0x400
	// Line 2659, Address: 0x2876b4, Func Offset: 0x404
	// Line 2660, Address: 0x2876b8, Func Offset: 0x408
	// Line 2661, Address: 0x2876bc, Func Offset: 0x40c
	// Line 2660, Address: 0x2876c0, Func Offset: 0x410
	// Line 2661, Address: 0x2876c4, Func Offset: 0x414
	// Line 2662, Address: 0x2876c8, Func Offset: 0x418
	// Line 2663, Address: 0x2876e0, Func Offset: 0x430
	// Line 2664, Address: 0x2876e8, Func Offset: 0x438
	// Line 2663, Address: 0x2876ec, Func Offset: 0x43c
	// Line 2664, Address: 0x2876f4, Func Offset: 0x444
	// Line 2665, Address: 0x287708, Func Offset: 0x458
	// Line 2666, Address: 0x28771c, Func Offset: 0x46c
	// Line 2667, Address: 0x287730, Func Offset: 0x480
	// Line 2668, Address: 0x28774c, Func Offset: 0x49c
	// Line 2669, Address: 0x287750, Func Offset: 0x4a0
	// Line 2670, Address: 0x28775c, Func Offset: 0x4ac
	// Line 2671, Address: 0x287764, Func Offset: 0x4b4
	// Line 2670, Address: 0x287768, Func Offset: 0x4b8
	// Line 2671, Address: 0x287770, Func Offset: 0x4c0
	// Line 2673, Address: 0x287780, Func Offset: 0x4d0
	// Line 2677, Address: 0x287794, Func Offset: 0x4e4
	// Line 2673, Address: 0x287798, Func Offset: 0x4e8
	// Line 2678, Address: 0x28779c, Func Offset: 0x4ec
	// Line 2679, Address: 0x2877a0, Func Offset: 0x4f0
	// Line 2673, Address: 0x2877a4, Func Offset: 0x4f4
	// Line 2674, Address: 0x2877b0, Func Offset: 0x500
	// Line 2675, Address: 0x2877c8, Func Offset: 0x518
	// Line 2676, Address: 0x2877e0, Func Offset: 0x530
	// Line 2677, Address: 0x2877ec, Func Offset: 0x53c
	// Line 2678, Address: 0x2877f8, Func Offset: 0x548
	// Line 2679, Address: 0x287800, Func Offset: 0x550
	// Line 2680, Address: 0x287824, Func Offset: 0x574
	// Line 2681, Address: 0x28782c, Func Offset: 0x57c
	// Line 2682, Address: 0x287844, Func Offset: 0x594
	// Line 2683, Address: 0x287850, Func Offset: 0x5a0
	// Line 2684, Address: 0x28785c, Func Offset: 0x5ac
	// Line 2685, Address: 0x287868, Func Offset: 0x5b8
	// Line 2686, Address: 0x287874, Func Offset: 0x5c4
	// Line 2690, Address: 0x287880, Func Offset: 0x5d0
	// Line 2689, Address: 0x287884, Func Offset: 0x5d4
	// Line 2690, Address: 0x287888, Func Offset: 0x5d8
	// Line 2691, Address: 0x287890, Func Offset: 0x5e0
	// Line 2692, Address: 0x28789c, Func Offset: 0x5ec
	// Line 2693, Address: 0x2878b4, Func Offset: 0x604
	// Line 2698, Address: 0x2878c4, Func Offset: 0x614
	// Line 2699, Address: 0x2878d4, Func Offset: 0x624
	// Line 2700, Address: 0x2878e8, Func Offset: 0x638
	// Line 2701, Address: 0x2878fc, Func Offset: 0x64c
	// Line 2702, Address: 0x287910, Func Offset: 0x660
	// Line 2703, Address: 0x287930, Func Offset: 0x680
	// Line 2704, Address: 0x287934, Func Offset: 0x684
	// Line 2705, Address: 0x287940, Func Offset: 0x690
	// Line 2706, Address: 0x287954, Func Offset: 0x6a4
	// Line 2705, Address: 0x287958, Func Offset: 0x6a8
	// Line 2706, Address: 0x287964, Func Offset: 0x6b4
	// Line 2708, Address: 0x287978, Func Offset: 0x6c8
	// Line 2711, Address: 0x28797c, Func Offset: 0x6cc
	// Line 2708, Address: 0x287980, Func Offset: 0x6d0
	// Line 2709, Address: 0x287988, Func Offset: 0x6d8
	// Line 2710, Address: 0x287994, Func Offset: 0x6e4
	// Line 2711, Address: 0x28799c, Func Offset: 0x6ec
	// Line 2712, Address: 0x2879c0, Func Offset: 0x710
	// Line 2713, Address: 0x2879c8, Func Offset: 0x718
	// Line 2714, Address: 0x2879e0, Func Offset: 0x730
	// Line 2715, Address: 0x2879ec, Func Offset: 0x73c
	// Line 2716, Address: 0x2879f8, Func Offset: 0x748
	// Line 2717, Address: 0x287a04, Func Offset: 0x754
	// Line 2718, Address: 0x287a10, Func Offset: 0x760
	// Line 2719, Address: 0x287a1c, Func Offset: 0x76c
	// Line 2721, Address: 0x287a20, Func Offset: 0x770
	// Line 2722, Address: 0x287a2c, Func Offset: 0x77c
	// Line 2723, Address: 0x287a3c, Func Offset: 0x78c
	// Line 2724, Address: 0x287a4c, Func Offset: 0x79c
	// Line 2726, Address: 0x287a5c, Func Offset: 0x7ac
	// Line 2727, Address: 0x287a94, Func Offset: 0x7e4
	// Line 2726, Address: 0x287a98, Func Offset: 0x7e8
	// Line 2728, Address: 0x287a9c, Func Offset: 0x7ec
	// Line 2727, Address: 0x287aa0, Func Offset: 0x7f0
	// Line 2731, Address: 0x287aa8, Func Offset: 0x7f8
	// Line 2728, Address: 0x287abc, Func Offset: 0x80c
	// Line 2731, Address: 0x287ac8, Func Offset: 0x818
	// Line 2732, Address: 0x287ae0, Func Offset: 0x830
	// Line 2731, Address: 0x287ae4, Func Offset: 0x834
	// Line 2733, Address: 0x287aec, Func Offset: 0x83c
	// Line 2740, Address: 0x287af0, Func Offset: 0x840
	// Line 2732, Address: 0x287af4, Func Offset: 0x844
	// Line 2740, Address: 0x287afc, Func Offset: 0x84c
	// Line 2733, Address: 0x287b00, Func Offset: 0x850
	// Line 2740, Address: 0x287b04, Func Offset: 0x854
	// Line 2741, Address: 0x287b0c, Func Offset: 0x85c
	// Line 2733, Address: 0x287b10, Func Offset: 0x860
	// Line 2735, Address: 0x287b18, Func Offset: 0x868
	// Line 2736, Address: 0x287b1c, Func Offset: 0x86c
	// Line 2741, Address: 0x287b20, Func Offset: 0x870
	// Line 2737, Address: 0x287b24, Func Offset: 0x874
	// Line 2741, Address: 0x287b28, Func Offset: 0x878
	// Line 2740, Address: 0x287b30, Func Offset: 0x880
	// Line 2738, Address: 0x287b34, Func Offset: 0x884
	// Line 2739, Address: 0x287b38, Func Offset: 0x888
	// Line 2740, Address: 0x287b3c, Func Offset: 0x88c
	// Line 2741, Address: 0x287b40, Func Offset: 0x890
	// Line 2740, Address: 0x287b44, Func Offset: 0x894
	// Line 2741, Address: 0x287b48, Func Offset: 0x898
	// Line 2742, Address: 0x287b50, Func Offset: 0x8a0
	// Line 2747, Address: 0x287b60, Func Offset: 0x8b0
	// Func End, Address: 0x287b9c, Func Offset: 0x8ec
}

// 
// Start address: 0x287ba0
void bhObjWssg()
{
	// Line 2761, Address: 0x287ba0, Func Offset: 0
	// Func End, Address: 0x287ba8, Func Offset: 0x8
}*/

