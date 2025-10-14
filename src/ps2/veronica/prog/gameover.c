#include "gameover.h"

void bhControlGameOver();
void bhSelectContinue();
void bhInitGameOver();
void bhMainGameOver();
void bhExitGameOver();
/*void bhDrawGameOver();*/

typedef void (*mode0_proc)();
mode0_proc bhCtrGov_mode0[4] = { bhSelectContinue, bhInitGameOver, bhMainGameOver, bhExitGameOver };
/*float gov_yn[16];
_anon23 gov_etb[7];
unsigned short cnt_mes[17];*/
SYS_WORK* sys;
/*float cmat[16];
BH_PWORK* plp;
_anon34 cam;
unsigned short PlMtnAct[7][3][2];*/

// 100% matching!
void bhControlGameOver()
{
    bhCtrGov_mode0[sys->gov_md0]();
}

// 
// Start address: 0x2b9aa0
void bhSelectContinue()
{
	//_anon0* gv;
	// Line 188, Address: 0x2b9aa0, Func Offset: 0
	// Line 191, Address: 0x2b9aa4, Func Offset: 0x4
	// Line 188, Address: 0x2b9aa8, Func Offset: 0x8
	// Line 191, Address: 0x2b9aac, Func Offset: 0xc
	// Line 196, Address: 0x2b9abc, Func Offset: 0x1c
	// Line 191, Address: 0x2b9ac0, Func Offset: 0x20
	// Line 192, Address: 0x2b9acc, Func Offset: 0x2c
	// Line 193, Address: 0x2b9ae0, Func Offset: 0x40
	// Line 194, Address: 0x2b9ae4, Func Offset: 0x44
	// Line 195, Address: 0x2b9ae8, Func Offset: 0x48
	// Line 196, Address: 0x2b9aec, Func Offset: 0x4c
	// Line 197, Address: 0x2b9b00, Func Offset: 0x60
	// Line 198, Address: 0x2b9b14, Func Offset: 0x74
	// Func End, Address: 0x2b9b20, Func Offset: 0x80
	scePrintf("bhSelectContinue - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2b9b20
void bhInitGameOver()
{
	int rn;
	int ct;
	int y;
	int x;
	int j;
	int i;
	float ar;
	float scl;
	//_anon0* gv;
	// Line 204, Address: 0x2b9b20, Func Offset: 0
	// Line 208, Address: 0x2b9b54, Func Offset: 0x34
	// Line 209, Address: 0x2b9b5c, Func Offset: 0x3c
	// Line 212, Address: 0x2b9b60, Func Offset: 0x40
	// Line 215, Address: 0x2b9b64, Func Offset: 0x44
	// Line 208, Address: 0x2b9b68, Func Offset: 0x48
	// Line 209, Address: 0x2b9b6c, Func Offset: 0x4c
	// Line 208, Address: 0x2b9b70, Func Offset: 0x50
	// Line 209, Address: 0x2b9b78, Func Offset: 0x58
	// Line 211, Address: 0x2b9b80, Func Offset: 0x60
	// Line 209, Address: 0x2b9b84, Func Offset: 0x64
	// Line 211, Address: 0x2b9b8c, Func Offset: 0x6c
	// Line 212, Address: 0x2b9b9c, Func Offset: 0x7c
	// Line 213, Address: 0x2b9bb0, Func Offset: 0x90
	// Line 215, Address: 0x2b9bc4, Func Offset: 0xa4
	// Line 216, Address: 0x2b9bd4, Func Offset: 0xb4
	// Line 217, Address: 0x2b9be8, Func Offset: 0xc8
	// Line 218, Address: 0x2b9bfc, Func Offset: 0xdc
	// Line 220, Address: 0x2b9c04, Func Offset: 0xe4
	// Line 218, Address: 0x2b9c08, Func Offset: 0xe8
	// Line 219, Address: 0x2b9c14, Func Offset: 0xf4
	// Line 220, Address: 0x2b9c28, Func Offset: 0x108
	// Line 222, Address: 0x2b9c4c, Func Offset: 0x12c
	// Line 224, Address: 0x2b9c60, Func Offset: 0x140
	// Line 230, Address: 0x2b9c68, Func Offset: 0x148
	// Line 232, Address: 0x2b9c70, Func Offset: 0x150
	// Line 228, Address: 0x2b9c74, Func Offset: 0x154
	// Line 224, Address: 0x2b9c78, Func Offset: 0x158
	// Line 231, Address: 0x2b9c80, Func Offset: 0x160
	// Line 224, Address: 0x2b9c88, Func Offset: 0x168
	// Line 232, Address: 0x2b9c8c, Func Offset: 0x16c
	// Line 229, Address: 0x2b9c94, Func Offset: 0x174
	// Line 232, Address: 0x2b9c98, Func Offset: 0x178
	// Line 225, Address: 0x2b9c9c, Func Offset: 0x17c
	// Line 226, Address: 0x2b9ca4, Func Offset: 0x184
	// Line 227, Address: 0x2b9cac, Func Offset: 0x18c
	// Line 228, Address: 0x2b9cb4, Func Offset: 0x194
	// Line 229, Address: 0x2b9cb8, Func Offset: 0x198
	// Line 230, Address: 0x2b9cbc, Func Offset: 0x19c
	// Line 231, Address: 0x2b9cc0, Func Offset: 0x1a0
	// Line 233, Address: 0x2b9cc4, Func Offset: 0x1a4
	// Line 232, Address: 0x2b9ccc, Func Offset: 0x1ac
	// Line 233, Address: 0x2b9cd0, Func Offset: 0x1b0
	// Line 234, Address: 0x2b9cf0, Func Offset: 0x1d0
	// Line 235, Address: 0x2b9d00, Func Offset: 0x1e0
	// Line 237, Address: 0x2b9d20, Func Offset: 0x200
	// Line 244, Address: 0x2b9d40, Func Offset: 0x220
	// Line 237, Address: 0x2b9d44, Func Offset: 0x224
	// Line 238, Address: 0x2b9d4c, Func Offset: 0x22c
	// Line 239, Address: 0x2b9d50, Func Offset: 0x230
	// Line 240, Address: 0x2b9d54, Func Offset: 0x234
	// Line 241, Address: 0x2b9d6c, Func Offset: 0x24c
	// Line 242, Address: 0x2b9d70, Func Offset: 0x250
	// Line 244, Address: 0x2b9d74, Func Offset: 0x254
	// Line 245, Address: 0x2b9d7c, Func Offset: 0x25c
	// Line 246, Address: 0x2b9d8c, Func Offset: 0x26c
	// Line 250, Address: 0x2b9d9c, Func Offset: 0x27c
	// Line 252, Address: 0x2b9da4, Func Offset: 0x284
	// Line 251, Address: 0x2b9da8, Func Offset: 0x288
	// Line 274, Address: 0x2b9db0, Func Offset: 0x290
	// Line 249, Address: 0x2b9db4, Func Offset: 0x294
	// Line 247, Address: 0x2b9db8, Func Offset: 0x298
	// Line 274, Address: 0x2b9dbc, Func Offset: 0x29c
	// Line 252, Address: 0x2b9dd4, Func Offset: 0x2b4
	// Line 274, Address: 0x2b9ddc, Func Offset: 0x2bc
	// Line 254, Address: 0x2b9de8, Func Offset: 0x2c8
	// Line 274, Address: 0x2b9df0, Func Offset: 0x2d0
	// Line 253, Address: 0x2b9df4, Func Offset: 0x2d4
	// Line 255, Address: 0x2b9df8, Func Offset: 0x2d8
	// Line 254, Address: 0x2b9dfc, Func Offset: 0x2dc
	// Line 274, Address: 0x2b9e20, Func Offset: 0x300
	// Line 255, Address: 0x2b9e2c, Func Offset: 0x30c
	// Line 256, Address: 0x2b9e30, Func Offset: 0x310
	// Line 274, Address: 0x2b9e38, Func Offset: 0x318
	// Line 256, Address: 0x2b9e3c, Func Offset: 0x31c
	// Line 274, Address: 0x2b9e58, Func Offset: 0x338
	// Line 256, Address: 0x2b9e60, Func Offset: 0x340
	// Line 274, Address: 0x2b9e64, Func Offset: 0x344
	// Line 257, Address: 0x2b9e80, Func Offset: 0x360
	// Line 256, Address: 0x2b9e84, Func Offset: 0x364
	// Line 274, Address: 0x2b9e88, Func Offset: 0x368
	// Line 257, Address: 0x2b9e94, Func Offset: 0x374
	// Line 274, Address: 0x2b9e98, Func Offset: 0x378
	// Line 260, Address: 0x2b9ec8, Func Offset: 0x3a8
	// Line 274, Address: 0x2b9ed0, Func Offset: 0x3b0
	// Line 260, Address: 0x2b9ed4, Func Offset: 0x3b4
	// Line 274, Address: 0x2b9ef0, Func Offset: 0x3d0
	// Line 260, Address: 0x2b9ef8, Func Offset: 0x3d8
	// Line 274, Address: 0x2b9efc, Func Offset: 0x3dc
	// Line 260, Address: 0x2b9f14, Func Offset: 0x3f4
	// Line 274, Address: 0x2b9f18, Func Offset: 0x3f8
	// Line 261, Address: 0x2b9f1c, Func Offset: 0x3fc
	// Line 260, Address: 0x2b9f20, Func Offset: 0x400
	// Line 274, Address: 0x2b9f24, Func Offset: 0x404
	// Line 261, Address: 0x2b9f30, Func Offset: 0x410
	// Line 274, Address: 0x2b9f34, Func Offset: 0x414
	// Line 264, Address: 0x2b9f68, Func Offset: 0x448
	// Line 274, Address: 0x2b9f70, Func Offset: 0x450
	// Line 264, Address: 0x2b9f74, Func Offset: 0x454
	// Line 274, Address: 0x2b9f90, Func Offset: 0x470
	// Line 264, Address: 0x2b9f98, Func Offset: 0x478
	// Line 274, Address: 0x2b9f9c, Func Offset: 0x47c
	// Line 265, Address: 0x2b9fb8, Func Offset: 0x498
	// Line 264, Address: 0x2b9fbc, Func Offset: 0x49c
	// Line 274, Address: 0x2b9fc0, Func Offset: 0x4a0
	// Line 265, Address: 0x2b9fcc, Func Offset: 0x4ac
	// Line 274, Address: 0x2b9fd0, Func Offset: 0x4b0
	// Line 268, Address: 0x2b9ff8, Func Offset: 0x4d8
	// Line 274, Address: 0x2ba000, Func Offset: 0x4e0
	// Line 268, Address: 0x2ba004, Func Offset: 0x4e4
	// Line 274, Address: 0x2ba020, Func Offset: 0x500
	// Line 268, Address: 0x2ba028, Func Offset: 0x508
	// Line 274, Address: 0x2ba02c, Func Offset: 0x50c
	// Line 268, Address: 0x2ba044, Func Offset: 0x524
	// Line 274, Address: 0x2ba048, Func Offset: 0x528
	// Line 269, Address: 0x2ba04c, Func Offset: 0x52c
	// Line 268, Address: 0x2ba050, Func Offset: 0x530
	// Line 274, Address: 0x2ba054, Func Offset: 0x534
	// Line 269, Address: 0x2ba060, Func Offset: 0x540
	// Line 274, Address: 0x2ba064, Func Offset: 0x544
	// Line 275, Address: 0x2ba0b8, Func Offset: 0x598
	// Func End, Address: 0x2ba0f0, Func Offset: 0x5d0
	scePrintf("bhInitGameOver - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ba0f0
void bhMainGameOver()
{
	unsigned int argb;
	int rn;
	int ct;
	int y;
	int x;
	int j;
	int i;
	float ar;
	float scn;
	float scl;
	//_anon26 cpos;
	//_anon0* gv;
	// Line 282, Address: 0x2ba0f0, Func Offset: 0
	// Line 283, Address: 0x2ba12c, Func Offset: 0x3c
	// Line 288, Address: 0x2ba134, Func Offset: 0x44
	// Line 283, Address: 0x2ba138, Func Offset: 0x48
	// Line 288, Address: 0x2ba144, Func Offset: 0x54
	// Line 290, Address: 0x2ba184, Func Offset: 0x94
	// Line 291, Address: 0x2ba19c, Func Offset: 0xac
	// Line 294, Address: 0x2ba1c0, Func Offset: 0xd0
	// Line 296, Address: 0x2ba1c8, Func Offset: 0xd8
	// Line 299, Address: 0x2ba1e4, Func Offset: 0xf4
	// Line 300, Address: 0x2ba210, Func Offset: 0x120
	// Line 301, Address: 0x2ba220, Func Offset: 0x130
	// Line 302, Address: 0x2ba228, Func Offset: 0x138
	// Line 301, Address: 0x2ba230, Func Offset: 0x140
	// Line 302, Address: 0x2ba238, Func Offset: 0x148
	// Line 304, Address: 0x2ba248, Func Offset: 0x158
	// Line 305, Address: 0x2ba258, Func Offset: 0x168
	// Line 304, Address: 0x2ba260, Func Offset: 0x170
	// Line 305, Address: 0x2ba264, Func Offset: 0x174
	// Line 304, Address: 0x2ba268, Func Offset: 0x178
	// Line 305, Address: 0x2ba270, Func Offset: 0x180
	// Line 307, Address: 0x2ba280, Func Offset: 0x190
	// Line 308, Address: 0x2ba298, Func Offset: 0x1a8
	// Line 309, Address: 0x2ba2a8, Func Offset: 0x1b8
	// Line 310, Address: 0x2ba2b8, Func Offset: 0x1c8
	// Line 311, Address: 0x2ba2c8, Func Offset: 0x1d8
	// Line 312, Address: 0x2ba2d8, Func Offset: 0x1e8
	// Line 316, Address: 0x2ba2e0, Func Offset: 0x1f0
	// Line 317, Address: 0x2ba2e8, Func Offset: 0x1f8
	// Line 312, Address: 0x2ba2ec, Func Offset: 0x1fc
	// Line 313, Address: 0x2ba2f0, Func Offset: 0x200
	// Line 314, Address: 0x2ba2fc, Func Offset: 0x20c
	// Line 313, Address: 0x2ba300, Func Offset: 0x210
	// Line 314, Address: 0x2ba308, Func Offset: 0x218
	// Line 315, Address: 0x2ba310, Func Offset: 0x220
	// Line 316, Address: 0x2ba31c, Func Offset: 0x22c
	// Line 315, Address: 0x2ba320, Func Offset: 0x230
	// Line 316, Address: 0x2ba328, Func Offset: 0x238
	// Line 317, Address: 0x2ba330, Func Offset: 0x240
	// Line 316, Address: 0x2ba334, Func Offset: 0x244
	// Line 317, Address: 0x2ba33c, Func Offset: 0x24c
	// Line 318, Address: 0x2ba348, Func Offset: 0x258
	// Line 319, Address: 0x2ba350, Func Offset: 0x260
	// Line 325, Address: 0x2ba360, Func Offset: 0x270
	// Line 319, Address: 0x2ba368, Func Offset: 0x278
	// Line 320, Address: 0x2ba36c, Func Offset: 0x27c
	// Line 323, Address: 0x2ba370, Func Offset: 0x280
	// Line 328, Address: 0x2ba374, Func Offset: 0x284
	// Line 330, Address: 0x2ba378, Func Offset: 0x288
	// Line 319, Address: 0x2ba37c, Func Offset: 0x28c
	// Line 320, Address: 0x2ba384, Func Offset: 0x294
	// Line 334, Address: 0x2ba388, Func Offset: 0x298
	// Line 337, Address: 0x2ba38c, Func Offset: 0x29c
	// Line 338, Address: 0x2ba390, Func Offset: 0x2a0
	// Line 320, Address: 0x2ba394, Func Offset: 0x2a4
	// Line 321, Address: 0x2ba398, Func Offset: 0x2a8
	// Line 346, Address: 0x2ba3a0, Func Offset: 0x2b0
	// Line 344, Address: 0x2ba3a4, Func Offset: 0x2b4
	// Line 345, Address: 0x2ba3a8, Func Offset: 0x2b8
	// Line 346, Address: 0x2ba3ac, Func Offset: 0x2bc
	// Line 321, Address: 0x2ba3b0, Func Offset: 0x2c0
	// Line 322, Address: 0x2ba3b4, Func Offset: 0x2c4
	// Line 323, Address: 0x2ba3c0, Func Offset: 0x2d0
	// Line 324, Address: 0x2ba3cc, Func Offset: 0x2dc
	// Line 325, Address: 0x2ba3d8, Func Offset: 0x2e8
	// Line 324, Address: 0x2ba3dc, Func Offset: 0x2ec
	// Line 325, Address: 0x2ba3e0, Func Offset: 0x2f0
	// Line 326, Address: 0x2ba3e8, Func Offset: 0x2f8
	// Line 325, Address: 0x2ba3ec, Func Offset: 0x2fc
	// Line 326, Address: 0x2ba424, Func Offset: 0x334
	// Line 327, Address: 0x2ba42c, Func Offset: 0x33c
	// Line 328, Address: 0x2ba438, Func Offset: 0x348
	// Line 329, Address: 0x2ba444, Func Offset: 0x354
	// Line 330, Address: 0x2ba450, Func Offset: 0x360
	// Line 329, Address: 0x2ba454, Func Offset: 0x364
	// Line 330, Address: 0x2ba45c, Func Offset: 0x36c
	// Line 331, Address: 0x2ba464, Func Offset: 0x374
	// Line 330, Address: 0x2ba468, Func Offset: 0x378
	// Line 331, Address: 0x2ba478, Func Offset: 0x388
	// Line 332, Address: 0x2ba480, Func Offset: 0x390
	// Line 331, Address: 0x2ba484, Func Offset: 0x394
	// Line 332, Address: 0x2ba494, Func Offset: 0x3a4
	// Line 333, Address: 0x2ba49c, Func Offset: 0x3ac
	// Line 332, Address: 0x2ba4a0, Func Offset: 0x3b0
	// Line 333, Address: 0x2ba4b0, Func Offset: 0x3c0
	// Line 334, Address: 0x2ba4b8, Func Offset: 0x3c8
	// Line 333, Address: 0x2ba4bc, Func Offset: 0x3cc
	// Line 334, Address: 0x2ba4cc, Func Offset: 0x3dc
	// Line 335, Address: 0x2ba4e0, Func Offset: 0x3f0
	// Line 334, Address: 0x2ba4e4, Func Offset: 0x3f4
	// Line 335, Address: 0x2ba4ec, Func Offset: 0x3fc
	// Line 336, Address: 0x2ba500, Func Offset: 0x410
	// Line 335, Address: 0x2ba504, Func Offset: 0x414
	// Line 336, Address: 0x2ba50c, Func Offset: 0x41c
	// Line 337, Address: 0x2ba514, Func Offset: 0x424
	// Line 336, Address: 0x2ba518, Func Offset: 0x428
	// Line 337, Address: 0x2ba520, Func Offset: 0x430
	// Line 338, Address: 0x2ba524, Func Offset: 0x434
	// Line 339, Address: 0x2ba52c, Func Offset: 0x43c
	// Line 340, Address: 0x2ba534, Func Offset: 0x444
	// Line 341, Address: 0x2ba544, Func Offset: 0x454
	// Line 342, Address: 0x2ba554, Func Offset: 0x464
	// Line 343, Address: 0x2ba564, Func Offset: 0x474
	// Line 344, Address: 0x2ba574, Func Offset: 0x484
	// Line 345, Address: 0x2ba584, Func Offset: 0x494
	// Line 346, Address: 0x2ba594, Func Offset: 0x4a4
	// Line 347, Address: 0x2ba5a0, Func Offset: 0x4b0
	// Line 346, Address: 0x2ba5a4, Func Offset: 0x4b4
	// Line 347, Address: 0x2ba5ac, Func Offset: 0x4bc
	// Line 348, Address: 0x2ba5b8, Func Offset: 0x4c8
	// Line 350, Address: 0x2ba5c0, Func Offset: 0x4d0
	// Line 351, Address: 0x2ba5c8, Func Offset: 0x4d8
	// Line 350, Address: 0x2ba5d4, Func Offset: 0x4e4
	// Line 351, Address: 0x2ba5e0, Func Offset: 0x4f0
	// Line 354, Address: 0x2ba5e8, Func Offset: 0x4f8
	// Line 356, Address: 0x2ba5f8, Func Offset: 0x508
	// Line 357, Address: 0x2ba608, Func Offset: 0x518
	// Line 360, Address: 0x2ba610, Func Offset: 0x520
	// Line 357, Address: 0x2ba618, Func Offset: 0x528
	// Line 358, Address: 0x2ba61c, Func Offset: 0x52c
	// Line 359, Address: 0x2ba628, Func Offset: 0x538
	// Line 358, Address: 0x2ba62c, Func Offset: 0x53c
	// Line 359, Address: 0x2ba634, Func Offset: 0x544
	// Line 360, Address: 0x2ba63c, Func Offset: 0x54c
	// Line 362, Address: 0x2ba64c, Func Offset: 0x55c
	// Line 368, Address: 0x2ba654, Func Offset: 0x564
	// Line 369, Address: 0x2ba658, Func Offset: 0x568
	// Line 370, Address: 0x2ba65c, Func Offset: 0x56c
	// Line 371, Address: 0x2ba660, Func Offset: 0x570
	// Line 370, Address: 0x2ba664, Func Offset: 0x574
	// Line 393, Address: 0x2ba668, Func Offset: 0x578
	// Line 367, Address: 0x2ba66c, Func Offset: 0x57c
	// Line 365, Address: 0x2ba670, Func Offset: 0x580
	// Line 393, Address: 0x2ba674, Func Offset: 0x584
	// Line 371, Address: 0x2ba68c, Func Offset: 0x59c
	// Line 393, Address: 0x2ba694, Func Offset: 0x5a4
	// Line 373, Address: 0x2ba6a0, Func Offset: 0x5b0
	// Line 393, Address: 0x2ba6a8, Func Offset: 0x5b8
	// Line 372, Address: 0x2ba6ac, Func Offset: 0x5bc
	// Line 374, Address: 0x2ba6b0, Func Offset: 0x5c0
	// Line 373, Address: 0x2ba6b4, Func Offset: 0x5c4
	// Line 393, Address: 0x2ba6d8, Func Offset: 0x5e8
	// Line 375, Address: 0x2ba6e8, Func Offset: 0x5f8
	// Line 393, Address: 0x2ba6f0, Func Offset: 0x600
	// Line 375, Address: 0x2ba6f4, Func Offset: 0x604
	// Line 393, Address: 0x2ba714, Func Offset: 0x624
	// Line 375, Address: 0x2ba71c, Func Offset: 0x62c
	// Line 393, Address: 0x2ba720, Func Offset: 0x630
	// Line 375, Address: 0x2ba72c, Func Offset: 0x63c
	// Line 393, Address: 0x2ba730, Func Offset: 0x640
	// Line 375, Address: 0x2ba734, Func Offset: 0x644
	// Line 393, Address: 0x2ba738, Func Offset: 0x648
	// Line 376, Address: 0x2ba73c, Func Offset: 0x64c
	// Line 375, Address: 0x2ba740, Func Offset: 0x650
	// Line 393, Address: 0x2ba744, Func Offset: 0x654
	// Line 376, Address: 0x2ba750, Func Offset: 0x660
	// Line 393, Address: 0x2ba754, Func Offset: 0x664
	// Line 378, Address: 0x2ba77c, Func Offset: 0x68c
	// Line 379, Address: 0x2ba780, Func Offset: 0x690
	// Line 393, Address: 0x2ba788, Func Offset: 0x698
	// Line 379, Address: 0x2ba78c, Func Offset: 0x69c
	// Line 393, Address: 0x2ba7ac, Func Offset: 0x6bc
	// Line 379, Address: 0x2ba7b4, Func Offset: 0x6c4
	// Line 393, Address: 0x2ba7b8, Func Offset: 0x6c8
	// Line 379, Address: 0x2ba7c4, Func Offset: 0x6d4
	// Line 393, Address: 0x2ba7cc, Func Offset: 0x6dc
	// Line 379, Address: 0x2ba7d0, Func Offset: 0x6e0
	// Line 393, Address: 0x2ba7d4, Func Offset: 0x6e4
	// Line 380, Address: 0x2ba7d8, Func Offset: 0x6e8
	// Line 379, Address: 0x2ba7dc, Func Offset: 0x6ec
	// Line 393, Address: 0x2ba7e0, Func Offset: 0x6f0
	// Line 380, Address: 0x2ba7ec, Func Offset: 0x6fc
	// Line 393, Address: 0x2ba7f0, Func Offset: 0x700
	// Line 382, Address: 0x2ba81c, Func Offset: 0x72c
	// Line 383, Address: 0x2ba820, Func Offset: 0x730
	// Line 393, Address: 0x2ba828, Func Offset: 0x738
	// Line 383, Address: 0x2ba82c, Func Offset: 0x73c
	// Line 393, Address: 0x2ba84c, Func Offset: 0x75c
	// Line 383, Address: 0x2ba854, Func Offset: 0x764
	// Line 393, Address: 0x2ba858, Func Offset: 0x768
	// Line 383, Address: 0x2ba864, Func Offset: 0x774
	// Line 393, Address: 0x2ba868, Func Offset: 0x778
	// Line 383, Address: 0x2ba86c, Func Offset: 0x77c
	// Line 393, Address: 0x2ba870, Func Offset: 0x780
	// Line 384, Address: 0x2ba874, Func Offset: 0x784
	// Line 383, Address: 0x2ba878, Func Offset: 0x788
	// Line 393, Address: 0x2ba87c, Func Offset: 0x78c
	// Line 384, Address: 0x2ba888, Func Offset: 0x798
	// Line 393, Address: 0x2ba88c, Func Offset: 0x79c
	// Line 386, Address: 0x2ba8ac, Func Offset: 0x7bc
	// Line 387, Address: 0x2ba8b0, Func Offset: 0x7c0
	// Line 393, Address: 0x2ba8b8, Func Offset: 0x7c8
	// Line 387, Address: 0x2ba8bc, Func Offset: 0x7cc
	// Line 393, Address: 0x2ba8dc, Func Offset: 0x7ec
	// Line 387, Address: 0x2ba8e4, Func Offset: 0x7f4
	// Line 393, Address: 0x2ba8e8, Func Offset: 0x7f8
	// Line 387, Address: 0x2ba8f4, Func Offset: 0x804
	// Line 393, Address: 0x2ba8fc, Func Offset: 0x80c
	// Line 387, Address: 0x2ba900, Func Offset: 0x810
	// Line 393, Address: 0x2ba904, Func Offset: 0x814
	// Line 388, Address: 0x2ba908, Func Offset: 0x818
	// Line 387, Address: 0x2ba90c, Func Offset: 0x81c
	// Line 393, Address: 0x2ba910, Func Offset: 0x820
	// Line 388, Address: 0x2ba91c, Func Offset: 0x82c
	// Line 393, Address: 0x2ba920, Func Offset: 0x830
	// Line 394, Address: 0x2ba968, Func Offset: 0x878
	// Line 400, Address: 0x2ba970, Func Offset: 0x880
	// Line 395, Address: 0x2ba980, Func Offset: 0x890
	// Line 397, Address: 0x2ba988, Func Offset: 0x898
	// Line 401, Address: 0x2ba9a0, Func Offset: 0x8b0
	// Line 400, Address: 0x2ba9a8, Func Offset: 0x8b8
	// Line 397, Address: 0x2ba9ac, Func Offset: 0x8bc
	// Line 398, Address: 0x2ba9b4, Func Offset: 0x8c4
	// Line 399, Address: 0x2ba9c4, Func Offset: 0x8d4
	// Line 400, Address: 0x2ba9d4, Func Offset: 0x8e4
	// Line 401, Address: 0x2ba9f8, Func Offset: 0x908
	// Line 402, Address: 0x2baa00, Func Offset: 0x910
	// Line 404, Address: 0x2baa10, Func Offset: 0x920
	// Line 405, Address: 0x2baa30, Func Offset: 0x940
	// Line 406, Address: 0x2baa50, Func Offset: 0x960
	// Line 411, Address: 0x2baa58, Func Offset: 0x968
	// Line 412, Address: 0x2baa80, Func Offset: 0x990
	// Line 414, Address: 0x2baa8c, Func Offset: 0x99c
	// Line 412, Address: 0x2baa90, Func Offset: 0x9a0
	// Line 413, Address: 0x2baaa8, Func Offset: 0x9b8
	// Line 412, Address: 0x2baab0, Func Offset: 0x9c0
	// Line 413, Address: 0x2baab8, Func Offset: 0x9c8
	// Line 414, Address: 0x2baacc, Func Offset: 0x9dc
	// Line 416, Address: 0x2baaec, Func Offset: 0x9fc
	// Line 417, Address: 0x2bab1c, Func Offset: 0xa2c
	// Line 418, Address: 0x2bab28, Func Offset: 0xa38
	// Line 419, Address: 0x2bab38, Func Offset: 0xa48
	// Line 421, Address: 0x2bab40, Func Offset: 0xa50
	// Line 422, Address: 0x2bab48, Func Offset: 0xa58
	// Line 425, Address: 0x2bab50, Func Offset: 0xa60
	// Line 427, Address: 0x2bab58, Func Offset: 0xa68
	// Line 435, Address: 0x2bab68, Func Offset: 0xa78
	// Line 438, Address: 0x2baba8, Func Offset: 0xab8
	// Line 439, Address: 0x2babb8, Func Offset: 0xac8
	// Line 440, Address: 0x2babc0, Func Offset: 0xad0
	// Line 441, Address: 0x2babd0, Func Offset: 0xae0
	// Line 443, Address: 0x2babd8, Func Offset: 0xae8
	// Line 444, Address: 0x2babf4, Func Offset: 0xb04
	// Line 443, Address: 0x2babf8, Func Offset: 0xb08
	// Line 444, Address: 0x2bac04, Func Offset: 0xb14
	// Line 449, Address: 0x2bac10, Func Offset: 0xb20
	// Line 450, Address: 0x2bac28, Func Offset: 0xb38
	// Line 452, Address: 0x2bac30, Func Offset: 0xb40
	// Line 453, Address: 0x2bac38, Func Offset: 0xb48
	// Line 454, Address: 0x2bac50, Func Offset: 0xb60
	// Line 455, Address: 0x2bac7c, Func Offset: 0xb8c
	// Line 456, Address: 0x2bac80, Func Offset: 0xb90
	// Line 455, Address: 0x2bac84, Func Offset: 0xb94
	// Line 456, Address: 0x2bac88, Func Offset: 0xb98
	// Line 458, Address: 0x2bac90, Func Offset: 0xba0
	// Line 459, Address: 0x2bacbc, Func Offset: 0xbcc
	// Line 460, Address: 0x2bacc0, Func Offset: 0xbd0
	// Line 459, Address: 0x2bacc4, Func Offset: 0xbd4
	// Line 460, Address: 0x2bacc8, Func Offset: 0xbd8
	// Line 462, Address: 0x2bacd0, Func Offset: 0xbe0
	// Line 463, Address: 0x2bacf0, Func Offset: 0xc00
	// Line 468, Address: 0x2bacfc, Func Offset: 0xc0c
	// Line 469, Address: 0x2bad0c, Func Offset: 0xc1c
	// Line 470, Address: 0x2bad1c, Func Offset: 0xc2c
	// Line 474, Address: 0x2bad28, Func Offset: 0xc38
	// Line 470, Address: 0x2bad2c, Func Offset: 0xc3c
	// Line 474, Address: 0x2bad34, Func Offset: 0xc44
	// Line 475, Address: 0x2bad3c, Func Offset: 0xc4c
	// Line 476, Address: 0x2bad44, Func Offset: 0xc54
	// Line 477, Address: 0x2bad50, Func Offset: 0xc60
	// Line 478, Address: 0x2bad68, Func Offset: 0xc78
	// Line 480, Address: 0x2bad78, Func Offset: 0xc88
	// Line 482, Address: 0x2bad88, Func Offset: 0xc98
	// Line 486, Address: 0x2bad94, Func Offset: 0xca4
	// Line 488, Address: 0x2bad9c, Func Offset: 0xcac
	// Line 489, Address: 0x2badac, Func Offset: 0xcbc
	// Line 491, Address: 0x2badb4, Func Offset: 0xcc4
	// Line 492, Address: 0x2badbc, Func Offset: 0xccc
	// Line 499, Address: 0x2badc4, Func Offset: 0xcd4
	// Line 500, Address: 0x2badc8, Func Offset: 0xcd8
	// Line 499, Address: 0x2badd0, Func Offset: 0xce0
	// Line 500, Address: 0x2badd8, Func Offset: 0xce8
	// Line 501, Address: 0x2bade8, Func Offset: 0xcf8
	// Line 502, Address: 0x2bae18, Func Offset: 0xd28
	// Line 503, Address: 0x2bae24, Func Offset: 0xd34
	// Line 504, Address: 0x2bae3c, Func Offset: 0xd4c
	// Line 505, Address: 0x2bae64, Func Offset: 0xd74
	// Line 506, Address: 0x2bae70, Func Offset: 0xd80
	// Line 507, Address: 0x2bae8c, Func Offset: 0xd9c
	// Line 508, Address: 0x2bae90, Func Offset: 0xda0
	// Line 507, Address: 0x2bae94, Func Offset: 0xda4
	// Line 508, Address: 0x2bae9c, Func Offset: 0xdac
	// Line 509, Address: 0x2baea8, Func Offset: 0xdb8
	// Line 510, Address: 0x2baeb4, Func Offset: 0xdc4
	// Line 511, Address: 0x2baeb8, Func Offset: 0xdc8
	// Line 509, Address: 0x2baebc, Func Offset: 0xdcc
	// Line 510, Address: 0x2baec0, Func Offset: 0xdd0
	// Line 512, Address: 0x2baec8, Func Offset: 0xdd8
	// Line 510, Address: 0x2baecc, Func Offset: 0xddc
	// Line 511, Address: 0x2baed0, Func Offset: 0xde0
	// Line 512, Address: 0x2baedc, Func Offset: 0xdec
	// Line 513, Address: 0x2baee8, Func Offset: 0xdf8
	// Line 514, Address: 0x2baef4, Func Offset: 0xe04
	// Line 515, Address: 0x2baf04, Func Offset: 0xe14
	// Line 518, Address: 0x2baf14, Func Offset: 0xe24
	// Line 519, Address: 0x2baf38, Func Offset: 0xe48
	// Line 520, Address: 0x2baf58, Func Offset: 0xe68
	// Line 521, Address: 0x2baf64, Func Offset: 0xe74
	// Line 522, Address: 0x2baf6c, Func Offset: 0xe7c
	// Line 521, Address: 0x2baf70, Func Offset: 0xe80
	// Line 522, Address: 0x2baf7c, Func Offset: 0xe8c
	// Line 523, Address: 0x2baf90, Func Offset: 0xea0
	// Line 524, Address: 0x2baf9c, Func Offset: 0xeac
	// Line 525, Address: 0x2bafa8, Func Offset: 0xeb8
	// Line 524, Address: 0x2bafac, Func Offset: 0xebc
	// Line 525, Address: 0x2bafb4, Func Offset: 0xec4
	// Line 530, Address: 0x2bafbc, Func Offset: 0xecc
	// Line 531, Address: 0x2bafc8, Func Offset: 0xed8
	// Line 532, Address: 0x2bafd8, Func Offset: 0xee8
	// Line 536, Address: 0x2bafe0, Func Offset: 0xef0
	// Func End, Address: 0x2bb020, Func Offset: 0xf30
	scePrintf("bhMainGameOver - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2bb020
void bhExitGameOver()
{
	// Line 542, Address: 0x2bb020, Func Offset: 0
	// Line 587, Address: 0x2bb028, Func Offset: 0x8
	// Line 588, Address: 0x2bb040, Func Offset: 0x20
	// Line 589, Address: 0x2bb048, Func Offset: 0x28
	// Line 591, Address: 0x2bb050, Func Offset: 0x30
	// Line 592, Address: 0x2bb058, Func Offset: 0x38
	// Line 595, Address: 0x2bb060, Func Offset: 0x40
	// Func End, Address: 0x2bb06c, Func Offset: 0x4c
	scePrintf("bhExitGameOver - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2bb070
void bhDrawGameOver()
{
	int y;
	int x;
	_anon15 uv[32];
	_anon15 cl[32];
	_anon27 pt[32];
	_anon32 p3c;
	_anon0* gv;
	// Line 602, Address: 0x2bb070, Func Offset: 0
	// Line 603, Address: 0x2bb084, Func Offset: 0x14
	// Line 609, Address: 0x2bb098, Func Offset: 0x28
	// Line 610, Address: 0x2bb0a0, Func Offset: 0x30
	// Line 611, Address: 0x2bb0ac, Func Offset: 0x3c
	// Line 612, Address: 0x2bb0b8, Func Offset: 0x48
	// Line 613, Address: 0x2bb0d0, Func Offset: 0x60
	// Line 614, Address: 0x2bb0d8, Func Offset: 0x68
	// Line 615, Address: 0x2bb0e0, Func Offset: 0x70
	// Line 616, Address: 0x2bb0e8, Func Offset: 0x78
	// Line 617, Address: 0x2bb0f0, Func Offset: 0x80
	// Line 618, Address: 0x2bb0f8, Func Offset: 0x88
	// Line 619, Address: 0x2bb100, Func Offset: 0x90
	// Line 621, Address: 0x2bb120, Func Offset: 0xb0
	// Line 624, Address: 0x2bb134, Func Offset: 0xc4
	// Line 628, Address: 0x2bb13c, Func Offset: 0xcc
	// Line 621, Address: 0x2bb144, Func Offset: 0xd4
	// Line 622, Address: 0x2bb148, Func Offset: 0xd8
	// Line 628, Address: 0x2bb14c, Func Offset: 0xdc
	// Line 631, Address: 0x2bb154, Func Offset: 0xe4
	// Line 622, Address: 0x2bb15c, Func Offset: 0xec
	// Line 623, Address: 0x2bb160, Func Offset: 0xf0
	// Line 634, Address: 0x2bb164, Func Offset: 0xf4
	// Line 633, Address: 0x2bb16c, Func Offset: 0xfc
	// Line 623, Address: 0x2bb170, Func Offset: 0x100
	// Line 624, Address: 0x2bb174, Func Offset: 0x104
	// Line 633, Address: 0x2bb178, Func Offset: 0x108
	// Line 624, Address: 0x2bb17c, Func Offset: 0x10c
	// Line 625, Address: 0x2bb180, Func Offset: 0x110
	// Line 626, Address: 0x2bb188, Func Offset: 0x118
	// Line 628, Address: 0x2bb190, Func Offset: 0x120
	// Line 629, Address: 0x2bb198, Func Offset: 0x128
	// Line 630, Address: 0x2bb1a0, Func Offset: 0x130
	// Line 631, Address: 0x2bb1a8, Func Offset: 0x138
	// Line 633, Address: 0x2bb1ac, Func Offset: 0x13c
	// Line 631, Address: 0x2bb1b0, Func Offset: 0x140
	// Line 632, Address: 0x2bb1b4, Func Offset: 0x144
	// Line 633, Address: 0x2bb1bc, Func Offset: 0x14c
	// Line 634, Address: 0x2bb1c8, Func Offset: 0x158
	// Line 635, Address: 0x2bb1d0, Func Offset: 0x160
	// Line 639, Address: 0x2bb1e4, Func Offset: 0x174
	// Line 640, Address: 0x2bb1f4, Func Offset: 0x184
	// Func End, Address: 0x2bb20c, Func Offset: 0x19c
}*/
