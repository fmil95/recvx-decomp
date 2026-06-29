#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/effsub3.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaView.h"
#include "../../../ps2/veronica/prog/pwksub.h"

// 
// Start address: 0x25d590
void bhCheckWall(BH_PWORK* pw)
{
	float inn;
	//_anon20 vec1;
	//_anon20 vec0;
	int r;
	float abz;
	float abx;
	float wpz;
	float wpx;
	float pah;
	float par;
	float ln;
	float zn;
	float xn;
	float pz;
	float px;
	float hd;
	float hh;
	float hw;
	float hpz;
	float hpy;
	float hpx;
	float* psp;
	unsigned int attr;
	int wal_n;
	int hit;
	int j;
	int i;
	//_anon0 ht;
	//_anon0* hp;
	//_anon39 l;
	//_anon20 pd;
	//_anon20* npos;
	// Line 102, Address: 0x25d590, Func Offset: 0
	// Line 120, Address: 0x25d5ec, Func Offset: 0x5c
	// Line 117, Address: 0x25d608, Func Offset: 0x78
	// Line 120, Address: 0x25d60c, Func Offset: 0x7c
	// Line 124, Address: 0x25d624, Func Offset: 0x94
	// Line 120, Address: 0x25d628, Func Offset: 0x98
	// Line 124, Address: 0x25d638, Func Offset: 0xa8
	// Line 123, Address: 0x25d63c, Func Offset: 0xac
	// Line 124, Address: 0x25d640, Func Offset: 0xb0
	// Line 126, Address: 0x25d654, Func Offset: 0xc4
	// Line 125, Address: 0x25d65c, Func Offset: 0xcc
	// Line 126, Address: 0x25d660, Func Offset: 0xd0
	// Line 127, Address: 0x25d680, Func Offset: 0xf0
	// Line 129, Address: 0x25d6a0, Func Offset: 0x110
	// Line 130, Address: 0x25d6ec, Func Offset: 0x15c
	// Line 137, Address: 0x25d6fc, Func Offset: 0x16c
	// Line 131, Address: 0x25d70c, Func Offset: 0x17c
	// Line 137, Address: 0x25d710, Func Offset: 0x180
	// Line 133, Address: 0x25d718, Func Offset: 0x188
	// Line 132, Address: 0x25d71c, Func Offset: 0x18c
	// Line 137, Address: 0x25d720, Func Offset: 0x190
	// Line 141, Address: 0x25d738, Func Offset: 0x1a8
	// Line 139, Address: 0x25d73c, Func Offset: 0x1ac
	// Line 140, Address: 0x25d740, Func Offset: 0x1b0
	// Line 142, Address: 0x25d744, Func Offset: 0x1b4
	// Line 137, Address: 0x25d748, Func Offset: 0x1b8
	// Line 143, Address: 0x25d74c, Func Offset: 0x1bc
	// Line 137, Address: 0x25d754, Func Offset: 0x1c4
	// Line 143, Address: 0x25d760, Func Offset: 0x1d0
	// Line 144, Address: 0x25d778, Func Offset: 0x1e8
	// Line 146, Address: 0x25d7a4, Func Offset: 0x214
	// Line 147, Address: 0x25d7a8, Func Offset: 0x218
	// Line 152, Address: 0x25d828, Func Offset: 0x298
	// Line 158, Address: 0x25d830, Func Offset: 0x2a0
	// Line 152, Address: 0x25d834, Func Offset: 0x2a4
	// Line 153, Address: 0x25d83c, Func Offset: 0x2ac
	// Line 154, Address: 0x25d840, Func Offset: 0x2b0
	// Line 153, Address: 0x25d844, Func Offset: 0x2b4
	// Line 158, Address: 0x25d848, Func Offset: 0x2b8
	// Line 155, Address: 0x25d850, Func Offset: 0x2c0
	// Line 156, Address: 0x25d854, Func Offset: 0x2c4
	// Line 158, Address: 0x25d858, Func Offset: 0x2c8
	// Line 162, Address: 0x25d8cc, Func Offset: 0x33c
	// Line 163, Address: 0x25d8dc, Func Offset: 0x34c
	// Line 165, Address: 0x25d8ec, Func Offset: 0x35c
	// Line 166, Address: 0x25d8f8, Func Offset: 0x368
	// Line 167, Address: 0x25d904, Func Offset: 0x374
	// Line 169, Address: 0x25d924, Func Offset: 0x394
	// Line 170, Address: 0x25d928, Func Offset: 0x398
	// Line 169, Address: 0x25d92c, Func Offset: 0x39c
	// Line 170, Address: 0x25d930, Func Offset: 0x3a0
	// Line 171, Address: 0x25d934, Func Offset: 0x3a4
	// Line 172, Address: 0x25d940, Func Offset: 0x3b0
	// Line 173, Address: 0x25d950, Func Offset: 0x3c0
	// Line 175, Address: 0x25d970, Func Offset: 0x3e0
	// Line 176, Address: 0x25d980, Func Offset: 0x3f0
	// Line 177, Address: 0x25d990, Func Offset: 0x400
	// Line 184, Address: 0x25d9a0, Func Offset: 0x410
	// Line 186, Address: 0x25d9a8, Func Offset: 0x418
	// Line 188, Address: 0x25d9b8, Func Offset: 0x428
	// Line 191, Address: 0x25d9c0, Func Offset: 0x430
	// Line 193, Address: 0x25d9c8, Func Offset: 0x438
	// Line 194, Address: 0x25d9d4, Func Offset: 0x444
	// Line 195, Address: 0x25d9e4, Func Offset: 0x454
	// Line 197, Address: 0x25da04, Func Offset: 0x474
	// Line 198, Address: 0x25da08, Func Offset: 0x478
	// Line 197, Address: 0x25da10, Func Offset: 0x480
	// Line 198, Address: 0x25da14, Func Offset: 0x484
	// Line 199, Address: 0x25da18, Func Offset: 0x488
	// Line 200, Address: 0x25da24, Func Offset: 0x494
	// Line 201, Address: 0x25da34, Func Offset: 0x4a4
	// Line 203, Address: 0x25da54, Func Offset: 0x4c4
	// Line 204, Address: 0x25da64, Func Offset: 0x4d4
	// Line 205, Address: 0x25da74, Func Offset: 0x4e4
	// Line 210, Address: 0x25da84, Func Offset: 0x4f4
	// Line 212, Address: 0x25da88, Func Offset: 0x4f8
	// Line 214, Address: 0x25da90, Func Offset: 0x500
	// Line 216, Address: 0x25daa0, Func Offset: 0x510
	// Line 220, Address: 0x25daa8, Func Offset: 0x518
	// Line 221, Address: 0x25dab0, Func Offset: 0x520
	// Line 223, Address: 0x25dac0, Func Offset: 0x530
	// Line 224, Address: 0x25dad0, Func Offset: 0x540
	// Line 225, Address: 0x25dadc, Func Offset: 0x54c
	// Line 227, Address: 0x25dafc, Func Offset: 0x56c
	// Line 228, Address: 0x25db00, Func Offset: 0x570
	// Line 227, Address: 0x25db04, Func Offset: 0x574
	// Line 228, Address: 0x25db0c, Func Offset: 0x57c
	// Line 229, Address: 0x25db10, Func Offset: 0x580
	// Line 230, Address: 0x25db1c, Func Offset: 0x58c
	// Line 231, Address: 0x25db2c, Func Offset: 0x59c
	// Line 233, Address: 0x25db4c, Func Offset: 0x5bc
	// Line 234, Address: 0x25db5c, Func Offset: 0x5cc
	// Line 235, Address: 0x25db6c, Func Offset: 0x5dc
	// Line 240, Address: 0x25db7c, Func Offset: 0x5ec
	// Line 242, Address: 0x25db80, Func Offset: 0x5f0
	// Line 244, Address: 0x25db88, Func Offset: 0x5f8
	// Line 246, Address: 0x25db98, Func Offset: 0x608
	// Line 249, Address: 0x25dba0, Func Offset: 0x610
	// Line 251, Address: 0x25dba8, Func Offset: 0x618
	// Line 252, Address: 0x25dbb4, Func Offset: 0x624
	// Line 251, Address: 0x25dbb8, Func Offset: 0x628
	// Line 252, Address: 0x25dbbc, Func Offset: 0x62c
	// Line 253, Address: 0x25dbc8, Func Offset: 0x638
	// Line 255, Address: 0x25dbe8, Func Offset: 0x658
	// Line 256, Address: 0x25dbec, Func Offset: 0x65c
	// Line 255, Address: 0x25dbf0, Func Offset: 0x660
	// Line 256, Address: 0x25dbf4, Func Offset: 0x664
	// Line 255, Address: 0x25dbf8, Func Offset: 0x668
	// Line 256, Address: 0x25dbfc, Func Offset: 0x66c
	// Line 257, Address: 0x25dc00, Func Offset: 0x670
	// Line 258, Address: 0x25dc0c, Func Offset: 0x67c
	// Line 259, Address: 0x25dc1c, Func Offset: 0x68c
	// Line 261, Address: 0x25dc3c, Func Offset: 0x6ac
	// Line 262, Address: 0x25dc4c, Func Offset: 0x6bc
	// Line 263, Address: 0x25dc5c, Func Offset: 0x6cc
	// Line 268, Address: 0x25dc6c, Func Offset: 0x6dc
	// Line 270, Address: 0x25dc70, Func Offset: 0x6e0
	// Line 272, Address: 0x25dc78, Func Offset: 0x6e8
	// Line 274, Address: 0x25dc88, Func Offset: 0x6f8
	// Line 280, Address: 0x25dc90, Func Offset: 0x700
	// Line 283, Address: 0x25dc98, Func Offset: 0x708
	// Line 288, Address: 0x25dd34, Func Offset: 0x7a4
	// Line 289, Address: 0x25dd38, Func Offset: 0x7a8
	// Line 290, Address: 0x25dd3c, Func Offset: 0x7ac
	// Line 289, Address: 0x25dd40, Func Offset: 0x7b0
	// Line 290, Address: 0x25dd44, Func Offset: 0x7b4
	// Line 291, Address: 0x25dd48, Func Offset: 0x7b8
	// Line 292, Address: 0x25dd54, Func Offset: 0x7c4
	// Line 296, Address: 0x25dd94, Func Offset: 0x804
	// Line 303, Address: 0x25ddc8, Func Offset: 0x838
	// Line 304, Address: 0x25ddd8, Func Offset: 0x848
	// Line 306, Address: 0x25dddc, Func Offset: 0x84c
	// Line 315, Address: 0x25dde0, Func Offset: 0x850
	// Line 304, Address: 0x25dde4, Func Offset: 0x854
	// Line 305, Address: 0x25ddec, Func Offset: 0x85c
	// Line 306, Address: 0x25ddf0, Func Offset: 0x860
	// Line 312, Address: 0x25ddfc, Func Offset: 0x86c
	// Line 313, Address: 0x25de00, Func Offset: 0x870
	// Line 315, Address: 0x25de04, Func Offset: 0x874
	// Line 316, Address: 0x25de0c, Func Offset: 0x87c
	// Line 317, Address: 0x25de18, Func Offset: 0x888
	// Line 318, Address: 0x25de30, Func Offset: 0x8a0
	// Line 320, Address: 0x25de44, Func Offset: 0x8b4
	// Line 321, Address: 0x25de58, Func Offset: 0x8c8
	// Line 324, Address: 0x25de68, Func Offset: 0x8d8
	// Line 321, Address: 0x25de70, Func Offset: 0x8e0
	// Line 322, Address: 0x25de74, Func Offset: 0x8e4
	// Line 324, Address: 0x25de78, Func Offset: 0x8e8
	// Line 321, Address: 0x25de7c, Func Offset: 0x8ec
	// Line 322, Address: 0x25de84, Func Offset: 0x8f4
	// Line 324, Address: 0x25de8c, Func Offset: 0x8fc
	// Line 322, Address: 0x25de90, Func Offset: 0x900
	// Line 324, Address: 0x25de98, Func Offset: 0x908
	// Line 325, Address: 0x25deb0, Func Offset: 0x920
	// Line 326, Address: 0x25ded8, Func Offset: 0x948
	// Line 325, Address: 0x25dedc, Func Offset: 0x94c
	// Line 326, Address: 0x25dee4, Func Offset: 0x954
	// Line 329, Address: 0x25def0, Func Offset: 0x960
	// Line 332, Address: 0x25df10, Func Offset: 0x980
	// Line 333, Address: 0x25df20, Func Offset: 0x990
	// Line 334, Address: 0x25df30, Func Offset: 0x9a0
	// Line 340, Address: 0x25df3c, Func Offset: 0x9ac
	// Line 343, Address: 0x25df44, Func Offset: 0x9b4
	// Line 349, Address: 0x25dfc0, Func Offset: 0xa30
	// Line 351, Address: 0x25dfdc, Func Offset: 0xa4c
	// Line 352, Address: 0x25dfe4, Func Offset: 0xa54
	// Line 354, Address: 0x25e01c, Func Offset: 0xa8c
	// Line 356, Address: 0x25e020, Func Offset: 0xa90
	// Line 358, Address: 0x25e028, Func Offset: 0xa98
	// Line 360, Address: 0x25e02c, Func Offset: 0xa9c
	// Line 362, Address: 0x25e034, Func Offset: 0xaa4
	// Line 364, Address: 0x25e038, Func Offset: 0xaa8
	// Line 366, Address: 0x25e040, Func Offset: 0xab0
	// Line 367, Address: 0x25e044, Func Offset: 0xab4
	// Line 371, Address: 0x25e048, Func Offset: 0xab8
	// Line 370, Address: 0x25e04c, Func Offset: 0xabc
	// Line 374, Address: 0x25e050, Func Offset: 0xac0
	// Line 371, Address: 0x25e054, Func Offset: 0xac4
	// Line 374, Address: 0x25e058, Func Offset: 0xac8
	// Line 373, Address: 0x25e05c, Func Offset: 0xacc
	// Line 372, Address: 0x25e060, Func Offset: 0xad0
	// Line 374, Address: 0x25e064, Func Offset: 0xad4
	// Line 375, Address: 0x25e070, Func Offset: 0xae0
	// Line 376, Address: 0x25e078, Func Offset: 0xae8
	// Line 377, Address: 0x25e07c, Func Offset: 0xaec
	// Line 380, Address: 0x25e084, Func Offset: 0xaf4
	// Line 383, Address: 0x25e0bc, Func Offset: 0xb2c
	// Line 384, Address: 0x25e0c0, Func Offset: 0xb30
	// Line 386, Address: 0x25e0c4, Func Offset: 0xb34
	// Line 389, Address: 0x25e0c8, Func Offset: 0xb38
	// Line 385, Address: 0x25e0cc, Func Offset: 0xb3c
	// Line 387, Address: 0x25e0d0, Func Offset: 0xb40
	// Line 389, Address: 0x25e0d4, Func Offset: 0xb44
	// Line 386, Address: 0x25e0d8, Func Offset: 0xb48
	// Line 388, Address: 0x25e0dc, Func Offset: 0xb4c
	// Line 387, Address: 0x25e0e0, Func Offset: 0xb50
	// Line 389, Address: 0x25e0e4, Func Offset: 0xb54
	// Line 390, Address: 0x25e100, Func Offset: 0xb70
	// Line 392, Address: 0x25e108, Func Offset: 0xb78
	// Line 393, Address: 0x25e10c, Func Offset: 0xb7c
	// Line 395, Address: 0x25e110, Func Offset: 0xb80
	// Line 397, Address: 0x25e134, Func Offset: 0xba4
	// Line 402, Address: 0x25e13c, Func Offset: 0xbac
	// Line 400, Address: 0x25e140, Func Offset: 0xbb0
	// Line 402, Address: 0x25e144, Func Offset: 0xbb4
	// Line 401, Address: 0x25e148, Func Offset: 0xbb8
	// Line 402, Address: 0x25e14c, Func Offset: 0xbbc
	// Line 403, Address: 0x25e150, Func Offset: 0xbc0
	// Line 405, Address: 0x25e154, Func Offset: 0xbc4
	// Line 404, Address: 0x25e158, Func Offset: 0xbc8
	// Line 406, Address: 0x25e15c, Func Offset: 0xbcc
	// Line 403, Address: 0x25e160, Func Offset: 0xbd0
	// Line 405, Address: 0x25e164, Func Offset: 0xbd4
	// Line 406, Address: 0x25e168, Func Offset: 0xbd8
	// Line 404, Address: 0x25e16c, Func Offset: 0xbdc
	// Line 406, Address: 0x25e170, Func Offset: 0xbe0
	// Line 405, Address: 0x25e178, Func Offset: 0xbe8
	// Line 406, Address: 0x25e17c, Func Offset: 0xbec
	// Line 407, Address: 0x25e18c, Func Offset: 0xbfc
	// Line 409, Address: 0x25e190, Func Offset: 0xc00
	// Line 413, Address: 0x25e194, Func Offset: 0xc04
	// Line 409, Address: 0x25e198, Func Offset: 0xc08
	// Line 413, Address: 0x25e19c, Func Offset: 0xc0c
	// Line 409, Address: 0x25e1a4, Func Offset: 0xc14
	// Line 410, Address: 0x25e1a8, Func Offset: 0xc18
	// Line 411, Address: 0x25e1ac, Func Offset: 0xc1c
	// Line 413, Address: 0x25e1b0, Func Offset: 0xc20
	// Line 415, Address: 0x25e1c8, Func Offset: 0xc38
	// Line 418, Address: 0x25e1d0, Func Offset: 0xc40
	// Line 421, Address: 0x25e1dc, Func Offset: 0xc4c
	// Line 422, Address: 0x25e1e0, Func Offset: 0xc50
	// Line 424, Address: 0x25e1e4, Func Offset: 0xc54
	// Line 418, Address: 0x25e1e8, Func Offset: 0xc58
	// Line 419, Address: 0x25e1ec, Func Offset: 0xc5c
	// Line 420, Address: 0x25e1f0, Func Offset: 0xc60
	// Line 421, Address: 0x25e1f4, Func Offset: 0xc64
	// Line 423, Address: 0x25e1f8, Func Offset: 0xc68
	// Line 424, Address: 0x25e1fc, Func Offset: 0xc6c
	// Line 422, Address: 0x25e200, Func Offset: 0xc70
	// Line 424, Address: 0x25e204, Func Offset: 0xc74
	// Line 425, Address: 0x25e21c, Func Offset: 0xc8c
	// Line 427, Address: 0x25e220, Func Offset: 0xc90
	// Line 431, Address: 0x25e224, Func Offset: 0xc94
	// Line 427, Address: 0x25e230, Func Offset: 0xca0
	// Line 428, Address: 0x25e234, Func Offset: 0xca4
	// Line 429, Address: 0x25e23c, Func Offset: 0xcac
	// Line 431, Address: 0x25e240, Func Offset: 0xcb0
	// Line 433, Address: 0x25e258, Func Offset: 0xcc8
	// Line 436, Address: 0x25e260, Func Offset: 0xcd0
	// Line 438, Address: 0x25e26c, Func Offset: 0xcdc
	// Line 439, Address: 0x25e270, Func Offset: 0xce0
	// Line 442, Address: 0x25e274, Func Offset: 0xce4
	// Line 436, Address: 0x25e278, Func Offset: 0xce8
	// Line 438, Address: 0x25e27c, Func Offset: 0xcec
	// Line 437, Address: 0x25e280, Func Offset: 0xcf0
	// Line 440, Address: 0x25e284, Func Offset: 0xcf4
	// Line 438, Address: 0x25e288, Func Offset: 0xcf8
	// Line 439, Address: 0x25e28c, Func Offset: 0xcfc
	// Line 441, Address: 0x25e290, Func Offset: 0xd00
	// Line 440, Address: 0x25e298, Func Offset: 0xd08
	// Line 442, Address: 0x25e29c, Func Offset: 0xd0c
	// Line 443, Address: 0x25e2b8, Func Offset: 0xd28
	// Line 446, Address: 0x25e2c0, Func Offset: 0xd30
	// Line 445, Address: 0x25e2c4, Func Offset: 0xd34
	// Line 450, Address: 0x25e2cc, Func Offset: 0xd3c
	// Line 446, Address: 0x25e2d0, Func Offset: 0xd40
	// Line 445, Address: 0x25e2d4, Func Offset: 0xd44
	// Line 450, Address: 0x25e2d8, Func Offset: 0xd48
	// Line 447, Address: 0x25e2dc, Func Offset: 0xd4c
	// Line 446, Address: 0x25e2e0, Func Offset: 0xd50
	// Line 447, Address: 0x25e2e4, Func Offset: 0xd54
	// Line 448, Address: 0x25e2e8, Func Offset: 0xd58
	// Line 450, Address: 0x25e2ec, Func Offset: 0xd5c
	// Line 456, Address: 0x25e308, Func Offset: 0xd78
	// Line 458, Address: 0x25e310, Func Offset: 0xd80
	// Line 483, Address: 0x25e3a0, Func Offset: 0xe10
	// Line 485, Address: 0x25e3d8, Func Offset: 0xe48
	// Line 486, Address: 0x25e3dc, Func Offset: 0xe4c
	// Line 487, Address: 0x25e3e0, Func Offset: 0xe50
	// Line 488, Address: 0x25e3e8, Func Offset: 0xe58
	// Line 489, Address: 0x25e3ec, Func Offset: 0xe5c
	// Line 491, Address: 0x25e3f0, Func Offset: 0xe60
	// Line 495, Address: 0x25e3f8, Func Offset: 0xe68
	// Line 493, Address: 0x25e3fc, Func Offset: 0xe6c
	// Line 494, Address: 0x25e400, Func Offset: 0xe70
	// Line 495, Address: 0x25e404, Func Offset: 0xe74
	// Line 496, Address: 0x25e408, Func Offset: 0xe78
	// Line 497, Address: 0x25e40c, Func Offset: 0xe7c
	// Line 498, Address: 0x25e410, Func Offset: 0xe80
	// Line 499, Address: 0x25e414, Func Offset: 0xe84
	// Line 501, Address: 0x25e41c, Func Offset: 0xe8c
	// Line 502, Address: 0x25e420, Func Offset: 0xe90
	// Line 503, Address: 0x25e424, Func Offset: 0xe94
	// Line 504, Address: 0x25e428, Func Offset: 0xe98
	// Line 505, Address: 0x25e42c, Func Offset: 0xe9c
	// Line 507, Address: 0x25e430, Func Offset: 0xea0
	// Line 509, Address: 0x25e438, Func Offset: 0xea8
	// Line 510, Address: 0x25e440, Func Offset: 0xeb0
	// Line 511, Address: 0x25e444, Func Offset: 0xeb4
	// Line 512, Address: 0x25e448, Func Offset: 0xeb8
	// Line 511, Address: 0x25e44c, Func Offset: 0xebc
	// Line 512, Address: 0x25e450, Func Offset: 0xec0
	// Line 513, Address: 0x25e454, Func Offset: 0xec4
	// Line 514, Address: 0x25e458, Func Offset: 0xec8
	// Line 516, Address: 0x25e45c, Func Offset: 0xecc
	// Line 517, Address: 0x25e460, Func Offset: 0xed0
	// Line 518, Address: 0x25e470, Func Offset: 0xee0
	// Line 519, Address: 0x25e474, Func Offset: 0xee4
	// Line 518, Address: 0x25e47c, Func Offset: 0xeec
	// Line 520, Address: 0x25e480, Func Offset: 0xef0
	// Line 522, Address: 0x25e4e0, Func Offset: 0xf50
	// Line 524, Address: 0x25e4e8, Func Offset: 0xf58
	// Line 525, Address: 0x25e4f8, Func Offset: 0xf68
	// Line 526, Address: 0x25e508, Func Offset: 0xf78
	// Line 527, Address: 0x25e530, Func Offset: 0xfa0
	// Line 528, Address: 0x25e538, Func Offset: 0xfa8
	// Line 529, Address: 0x25e53c, Func Offset: 0xfac
	// Line 532, Address: 0x25e544, Func Offset: 0xfb4
	// Line 533, Address: 0x25e54c, Func Offset: 0xfbc
	// Line 535, Address: 0x25e550, Func Offset: 0xfc0
	// Line 533, Address: 0x25e554, Func Offset: 0xfc4
	// Line 534, Address: 0x25e558, Func Offset: 0xfc8
	// Line 535, Address: 0x25e560, Func Offset: 0xfd0
	// Line 541, Address: 0x25e588, Func Offset: 0xff8
	// Line 543, Address: 0x25e590, Func Offset: 0x1000
	// Line 544, Address: 0x25e5ac, Func Offset: 0x101c
	// Line 545, Address: 0x25e5b0, Func Offset: 0x1020
	// Line 551, Address: 0x25e5b8, Func Offset: 0x1028
	// Line 545, Address: 0x25e5bc, Func Offset: 0x102c
	// Line 547, Address: 0x25e5c4, Func Offset: 0x1034
	// Line 546, Address: 0x25e5c8, Func Offset: 0x1038
	// Line 551, Address: 0x25e5cc, Func Offset: 0x103c
	// Line 546, Address: 0x25e5d8, Func Offset: 0x1048
	// Line 548, Address: 0x25e5dc, Func Offset: 0x104c
	// Line 549, Address: 0x25e5e0, Func Offset: 0x1050
	// Line 551, Address: 0x25e5e4, Func Offset: 0x1054
	// Line 560, Address: 0x25e6f8, Func Offset: 0x1168
	// Line 561, Address: 0x25e708, Func Offset: 0x1178
	// Line 563, Address: 0x25e71c, Func Offset: 0x118c
	// Line 565, Address: 0x25e744, Func Offset: 0x11b4
	// Line 568, Address: 0x25e74c, Func Offset: 0x11bc
	// Line 570, Address: 0x25e754, Func Offset: 0x11c4
	// Line 572, Address: 0x25e780, Func Offset: 0x11f0
	// Line 576, Address: 0x25e788, Func Offset: 0x11f8
	// Line 577, Address: 0x25e790, Func Offset: 0x1200
	// Line 579, Address: 0x25e7a4, Func Offset: 0x1214
	// Line 581, Address: 0x25e7d0, Func Offset: 0x1240
	// Line 584, Address: 0x25e7d8, Func Offset: 0x1248
	// Line 586, Address: 0x25e7e0, Func Offset: 0x1250
	// Line 588, Address: 0x25e810, Func Offset: 0x1280
	// Line 589, Address: 0x25e818, Func Offset: 0x1288
	// Line 596, Address: 0x25e81c, Func Offset: 0x128c
	// Line 597, Address: 0x25e838, Func Offset: 0x12a8
	// Line 598, Address: 0x25e84c, Func Offset: 0x12bc
	// Line 599, Address: 0x25e864, Func Offset: 0x12d4
	// Line 601, Address: 0x25e880, Func Offset: 0x12f0
	// Line 605, Address: 0x25e8c4, Func Offset: 0x1334
	// Func End, Address: 0x25e924, Func Offset: 0x1394
	scePrintf("bhCheckWall - UNIMPLEMENTED!\n");
}

// 97.77% matching
int bhCheckWallEx(BH_PWORK* pw, NJS_POINT3* npos, NJS_POINT3* opos, float par, float pah)
{
    NJS_POINT3 pd;     
    NJS_LINE l;      
    ATR_WORK* hp;     
    ATR_WORK ht;       
    int i, j;             
    int hit;        
    int wal_n;       
    int pcflg;        
    unsigned int attr;
    float* psp;       
    float hpx, hpy, hpz;        
    float hw, hh, hd;        
    float px, pz;        
    float xn, zn;         
    float ln;         
    float wpx, wpz;       
    float abx, abz;        
    float pxx, pzz;        
    int r;            
    int ayp;         
    NJS_VECTOR vec0, vec1;  
    float inn;        

    if ((pw->stflg & 0x20000)) 
    {
        bhSetDansaLimitAtari(pw);
    }
    
    hit = 0;
    
    wal_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < wal_n; i++) 
    {
        if (i < rom->wal_n) 
        {
            hp = &rom->walp[i];
        }
        else
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        if ((hp->flg & 0x1))
        {
            attr = hp->attr;
            
            hpx = hp->px;
            hpy = hp->py;
            hpz = hp->pz;
            
            hw = hp->w;
            hh = hp->h; 
            hd = hp->d;
            
            if (!hh) 
            {
                hh = rom->h;
            }
            
            switch (hp->type) 
            {                  
            case 0:                                     
            case 1:                                     
                if (((!(hp->type & 0x1)) || (!(pw->flg & 0x400))) && ((!(attr & 0x1)) || (hp->flr_no == pw->flr_no)) && ((!(attr & 0x2)) || (!(pw->flg & 0x4000))) && ((!(attr & 0x4)) || (!(pw->stflg & 0x40000000)))) 
                {
                    wpx = hpx + (0.5f * hw);
                    wpz = hpz + (0.5f * hd);
                    
                    px = hpx - par;
                    pz = hpz - par;
                    
                    xn = hw + (2.0f * par);
                    zn = hd + (2.0f * par);
                    
                    if ((((npos->x - px) >= 0) && ((npos->x - px) < xn)) && (((npos->z - pz) >= 0) && ((npos->z - pz) < zn)) && (((npos->y + pah) >= hpy) && (npos->y <= (hpy + hh))))
                    {
                        hit++;
                        
                        if (((attr & 0x10000)) && (pw == plp))
                        {
                            ayp = (pw->ay + 8192) & ~0x3FFF;
                            
                            pcflg = 0;
                            
                            switch (ayp & 0xC000) 
                            { 
                            case 0: 
                                if ((attr & 0x40000)) 
                                {
                                    pcflg = 1;
                                }
                                
                                break;
                            case 0x4000: 
                                if ((attr & 0x200000)) 
                                {
                                    pcflg = 1;
                                }
                                
                                break;
                            case 0x8000: 
                                if ((attr & 0x100000)) 
                                {
                                    pcflg = 1;
                                }
                                
                                break;
                            case 0xC000: 
                                if ((attr & 0x80000)) 
                                {
                                    pcflg = 1;
                                }
                                
                                break;
                            }
                            
                            if (pcflg != 0) 
                            {
                                pw->psh_ct = 0;
                            } 
                            else 
                            {
                                njSinCos(ayp, &pxx, &pzz);
                                
                                pxx = npos->x - (5.0f * pxx);
                                pzz = npos->z - (5.0f * pzz);
                                
                                if (((hpx <= pxx) && ((hpx + hw) >= pxx)) && ((hpz <= pzz) && ((hpz + hd) >= pzz))) 
                                {
                                    pw->psh_ct++;
                                } 
                                else 
                                {
                                    pw->psh_ct = 0;
                                }
                            }
                        }
                        
                        if ((!(attr & 0x20000)) && ((pw->stflg & 0x80))) 
                        {
                            hp->attr |= 0x20000;
                            
                            pw->psh_idx = i;
                        }
                        
                        if (opos->x < wpx) 
                        {
                            if (opos->z < wpz) 
                            {
                                abx = fabsf(npos->x - px);
                                abz = fabsf(npos->z - pz);
                                
                                if ((abx < par) && (abz < par)) 
                                {
                                    px = hpx - npos->x;
                                    pz = hpz - npos->z;
                                    
                                    ln = njSqrt((px * px) + (pz * pz));
                                    
                                    if (ln <= par) 
                                    {
                                        r = 10430.381f * atan2f(px, pz);
                                        
                                        njSinCos(r, &npos->x, &npos->z);
                                        
                                        npos->x = hpx - (npos->x * par);
                                        npos->z = hpz - (npos->z * par);
                                    }
                                    
                                    pw->psh_ct = 0;
                                }
                                else
                                {
                                    abx = fabsf(opos->x - px);
                                    abz = fabsf(opos->z - pz);
                                    
                                    if (abx > abz)
                                    {
                                        npos->z = pz;
                                    }
                                    else
                                    {
                                        npos->x = px;
                                    }
                                }
                            } 
                            else
                            {
                                abx = fabsf(npos->x - px);
                                abz = fabsf(npos->z - (pz + zn));
                                
                                if ((abx < par) && (abz < par))
                                {
                                    px = hpx        - npos->x;
                                    pz = (hpz + hd) - npos->z; 
                                    
                                    ln = njSqrt((px * px) + (pz * pz));
                                    
                                    if (ln <= par)
                                    {
                                        r = 10430.381f * atan2f(px, pz);
                                        
                                        njSinCos(r, &npos->x, &npos->z);
                                        
                                        npos->x = hpx        - (npos->x * par);
                                        npos->z = (hpz + hd) - (npos->z * par);
                                    }
                                    
                                    pw->psh_ct = 0;
                                } 
                                else 
                                {
                                    abx = fabsf(opos->x - px);
                                    abz = fabsf(opos->z - (pz + zn));
                                    
                                    if (abx > abz) 
                                    {
                                        npos->z = pz + zn;
                                    } 
                                    else
                                    {
                                        npos->x = px;
                                    }
                                }
                            }
                        } 
                        else if (opos->z < wpz)
                        {
                            abx = fabsf(npos->x - (px + xn));
                            abz = fabsf(npos->z - pz);
                            
                            if ((abx < par) && (abz < par)) 
                            {
                                px = (hpx + hw) - npos->x;
                                pz = hpz        - npos->z;
                                
                                ln = njSqrt((px * px) + (pz * pz));
                                
                                if (ln <= par) 
                                {
                                    r = 10430.381f * atan2f(px, pz);
                                    
                                    njSinCos(r, &npos->x, &npos->z);
                                    
                                    npos->x = (hpx + hw) - (npos->x * par);
                                    npos->z = hpz        - (npos->z * par);
                                }
                                
                                pw->psh_ct = 0;
                            } 
                            else 
                            {
                                abx = fabsf(opos->x - (px + xn));
                                abz = fabsf(opos->z - pz);
                                
                                if (abx > abz) 
                                {
                                    npos->z = pz;
                                }
                                else
                                {
                                    npos->x = px + xn;
                                }
                            }
                        } 
                        else 
                        {
                            abx = fabsf(npos->x - (px + xn));
                            abz = fabsf(npos->z - (pz + zn));
                            
                            if ((abx < par) && (abz < par)) 
                            {
                                px = (hpx + hw) - npos->x;
                                pz = (hpz + hd) - npos->z;
                                
                                ln = njSqrt((px * px) + (pz * pz));
                                
                                if (ln <= par)
                                {
                                    r = 10430.381f * atan2f(px, pz);
                                    
                                    njSinCos(r, &npos->x, &npos->z);
                                    
                                    npos->x = (hpx + hw) - (npos->x * par);
                                    npos->z = (hpz + hd) - (npos->z * par);
                                }
                                
                                pw->psh_ct = 0;
                            }
                            else
                            {
                                abx = fabsf(opos->x - (px + xn));
                                abz = fabsf(opos->z - (pz + zn));
                                
                                if (abx > abz)
                                {
                                    npos->z = pz + zn; 
                                } 
                                else
                                {
                                    npos->x = px + xn;
                                }
                            }
                        }
                    }
                }
                
                break;
            case 2:                                     
            case 3:                                     
                if (((!(hp->type & 0x1)) || (!(pw->flg & 0x400))) && ((!(attr & 0x1)) || (hp->flr_no == pw->flr_no)) && ((!(attr & 0x2)) || (!(pw->flg & 0x4000))) && ((!(attr & 0x4)) || (!(pw->stflg & 0x40000000))) && ((!(attr & 0x40)) || (!(pw->stflg & 0x4000))))
                {
                    px = hpx - npos->x;
                    pz = hpz - npos->z;
                    
                    ln = njSqrt((px * px) + (pz * pz));
                    
                    hw = par + hw; 
                    
                    if ((ln < hw) && (((npos->y + pah) >= hpy) && (npos->y <= (hpy + hh))))
                    {
                        hit++;
                        
                        if (((attr & 0x40)) && ((pw->stflg & 0x40000000)) && (!(plp->flg & 0x6)))
                        {
                            njSinCos(pw->ay, &vec0.x, &vec0.z);
                            
                            vec0.x = -vec0.x;
                            vec0.y = 0;
                            vec0.z = -vec0.z;
                            
                            vec1.x = px;
                            vec1.y = 0;
                            vec1.z = pz;
                            
                            njUnitVector(&vec1);
                            
                            inn = njInnerProduct(&vec0, &vec1);
                            
                            if (inn > 0) 
                            {
                                *(int*)&plp->mode0 = 2;
                            } 
                            else 
                            {
                                *(int*)&plp->mode0 = 0x102;
                            }
                            
                            plp->flg    |= 0x10004;
                            sys->st_flg |= 0x4;
                            
                            j = bhSetEffect(29, (POINT*)&plp->px, &hp->flg, 0);
                            
                            if (j != -1)
                            {
                                eff[j].flg &= ~0x80;
                                hp->attr   &= ~0x40;
                            }
                        }
                        
                        r = 10430.381f * atan2f(px, pz);
                        
                        njSinCos(r, &npos->x, &npos->z);
                        
                        npos->x = hpx - (npos->x * hw);
                        npos->z = hpz - (npos->z * hw);
                    }
                }
                
                break;
            case 4:                             
            case 5:                             
                if (((!(hp->type & 0x1)) || (!(pw->flg & 0x400))) && ((!(attr & 0x1)) || (hp->flr_no == pw->flr_no)) && ((!(attr & 0x2)) || (!(pw->flg & 0x4000))) && ((!(attr & 0x4)) || (!(pw->stflg & 0x40000000))))
                {
                    if (bhCheckInnerTriangle(hp, npos, par, pah) != 0) 
                    {
                        hit++;
                        
                        l.vy = 0;
                        l.py = 0;
                        
                        switch (hp->id) 
                        { 
                        case 0:     
                            px = hpx + par;
                            pz = hpz + par;
                            break;
                        case 1:     
                            px = hpx + par;
                            pz = hpz - par;
                            break;
                        case 2:     
                            px = hpx - par;
                            pz = hpz + par;
                            break;
                        case 3:     
                            px = hpx - par;
                            pz = hpz - par;
                            break;
                        }
                        
                        l.px = px;
                        l.pz = pz + hd;
                        
                        l.vx = hw;
                        l.vz = -hd;
                        
                        njDistanceP2L(npos, &l, &pd);
                        
                        npos->x = pd.x; 
                        npos->z = pd.z;
                    } 
                    else 
                    {
                        switch (hp->id)
                        { 
                        case 0:     
                            ht.px = hpx;
                            ht.py = hpy;
                            ht.pz = hpz;
                            
                            ht.w = 0;
                            ht.h = hh;
                            ht.d = hd;
                            
                            if (bhCheckBox(&ht, npos, par, pah, 12) != 0)
                            {
                                hit++;
                            }
                            
                            ht.w = hw;
                            ht.h = hh;
                            ht.d = 0;
                            
                            if (bhCheckBox(&ht, npos, par, pah, 10) != 0) 
                            {
                                hit++;
                            } 
                            
                            break;
                        case 1:     
                            ht.px = hpx;
                            ht.py = hpy;
                            ht.pz = hpz + hd;
                            
                            ht.w = 0;
                            ht.h = hh;
                            ht.d = -hd;
                            
                            if (bhCheckBox(&ht, npos, par, pah, 12) != 0) 
                            {
                                hit++;
                            }
                            
                            r = 0;
                            
                            ht.pz = hpz - r;
                            
                            ht.w = hw;
                            ht.h = hh;
                            ht.d = 0;
                            
                            if (bhCheckBox(&ht, npos, par, pah, 5) != 0)
                            {
                                hit++;
                            }
                            
                            break;
                        case 2:     
                            r = 0;
                            
                            ht.px = hpx - r;
                            ht.py = hpy;
                            ht.pz = hpz;
                            
                            ht.w = 0;
                            ht.h = hh;
                            ht.d = hd;
                            
                            if (bhCheckBox(&ht, npos, par, pah, 3) != 0) 
                            {
                                hit++;
                            }
                            
                            ht.px = hpx + hw;
                            
                            ht.w = -hw;
                            ht.h = hh;
                            ht.d = 0;
                            
                            if (bhCheckBox(&ht, npos, par, pah, 10) != 0) 
                            {
                                hit++;
                            }
                            
                            break;
                        case 3:     
                            r = 0;
                            
                            ht.px = hpx - r;
                            ht.py = hpy;
                            ht.pz = hpz + hd;
                            
                            ht.w = 0;
                            ht.h = hh;
                            ht.d = -hd;
                            
                            if (bhCheckBox(&ht, npos, par, pah, 3) != 0) 
                            {
                                hit++;
                            }
                            
                            r = 0;
                            
                            ht.px = hpx + hw;
                            ht.pz = hpz - r; 
                            
                            ht.w = -hw;
                            ht.h = hh;
                            ht.d = 0;
                            
                            if (bhCheckBox(&ht, npos, par, pah, 5) != 0) 
                            {
                                hit++;
                            }
                            
                            break;
                        }
                    }
                }
                
                break;
            case 7:                                     
                if ((!(attr & 0x1)) || (hp->flr_no == pw->flr_no)) 
                {
                    wpx = hpx + (0.5f * hw);
                    wpz = hpz + (0.5f * hd);
                    
                    px = hpx - par;
                    pz = hpz - par;
                    
                    xn = hw + (2.0f * par);
                    zn = hd + (2.0f * par);
                    
                    if (((((npos->x - px) >= 0) && ((npos->x - px) < xn)) && (((npos->z - pz) >= 0) && ((npos->z - pz) < zn)) && ((npos->y < (hpy + hh)) && ((npos->y + pah) > (hpy + hh))) && ((pw->flg & 0x100))) || ((((npos->x - px) >= 0) && ((npos->x - px) < xn)) && (((npos->z - pz) >= 0) && ((npos->z - pz) < zn)) && (((npos->y + pah) >= (hpy + hh)) && (npos->y < hpy)) && (!(pw->flg & 0x100))))
                    {
                        hit++;
                        
                        if (opos->x < wpx)
                        {
                            if (opos->z < wpz) 
                            {
                                if (fabsf(npos->x - px) > fabsf(npos->z - pz)) 
                                {
                                    npos->z = pz;
                                }
                                else 
                                {
                                    npos->x = px;
                                }
                            }
                            else
                            {
                                if (fabsf(npos->x - px) > fabsf(npos->z - (pz + zn)))
                                {
                                    npos->z = pz + zn;
                                } 
                                else 
                                {
                                    npos->x = px;
                                }
                            }
                        }
                        else 
                        {
                            if (opos->z < wpz) 
                            {
                                if (fabsf(npos->x - (px + xn)) > fabsf(npos->z - pz))
                                {
                                    npos->z = pz;
                                } 
                                else
                                {
                                    npos->x = px + xn;
                                }
                            }
                            else
                            {
                                if (fabsf(npos->x - (px + xn)) > fabsf(npos->z - (pz + zn))) 
                                {
                                    npos->z = pz + zn; 
                                }
                                else 
                                {
                                    npos->x = px + xn; 
                                }
                            }
                        } 
                    }
                } 
                
                break;
            }
        }
    }
    
    if (hit != 0)
    {
        pw->stflg |= 0x1;
    }
    
    if ((hit == 0) && ((pw->flg & 0x100)))
    {
        npos->y = rom->grand[pw->flr_no + 2]; 
    }
    
    if ((pw->stflg & 0x20000)) 
    {
        sys->mwal_n -= sys->dla_n;
    }
    
    return (hit != 0) ? 1 : 0;
}

// 100% matching!
void bhCheckWall2Box(BH_PWORK* pw) 
{
    NJS_POINT3 pd; 
    NJS_LINE l;    
    ATR_WORK* hp; 
    ATR_WORK ht;  
    int i, j;        
    int hit;      
    int wal_n;     
    float px, pz;      
    float xn, zn;     
    float ln;     
    float wpx, wpz;   
    float h;       
    float abx, abz;   
    float pxx, pzz;     
    int r;     
  
    hit = 0;
    
    wal_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < wal_n; i++) 
    {
        if (i < rom->wal_n) 
        {
            hp = &rom->walp[i];
        } 
        else 
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        if ((hp->flg & 0x1)) 
        {
            if (hp->h) 
            {
                h = hp->h;
            } 
            else 
            {
                h = rom->h;
            }
            
            switch (hp->type) 
            {                  
            case 0:                             
            case 1:                             
                if (((!(hp->type & 0x1)) || (!(pw->flg & 0x400))) && ((!(hp->attr & 0x1)) || (hp->flr_no == pw->flr_no)) && (!((hp->attr & 0x2)) || (!(pw->flg & 0x4000))) && (!((hp->attr & 0x4)) || (!(pw->stflg & 0x40000000))) && ((!(hp->attr & 0x10000)) || (!(pw->flg & 0x2000)) || (hp->prm3 != (unsigned char)pw->idx_ct))) 
                {
                    wpx = hp->px + (0.5f * hp->w);
                    wpz = hp->pz + (0.5f * hp->d);
                    
                    px = hp->px - pw->aw; 
                    pz = hp->pz - pw->ad;
                    
                    xn = hp->w + (2.0f * pw->aw);
                    zn = hp->d + (2.0f * pw->ad);
                    
                    if ((((pw->px - px) >= 0) && ((pw->px - px) < xn)) && (((pw->pz - pz) >= 0) && ((pw->pz - pz) < zn)) && (((pw->py + pw->ah) >= hp->py) && (pw->py <= (hp->py + h)))) 
                    {
                        hit++;
                        
                        if (((hp->attr & 0x10000)) && (pw == plp)) 
                        {
                            njSinCos((pw->ay + 8192) & ~0x3FFF, &pxx, &pzz);
                            
                            pxx = pw->px - (4.0f * pxx);
                            pzz = pw->pz - (4.0f * pzz); 
                            
                            if (((hp->px <= pxx) && ((hp->px + hp->w) >= pxx)) && ((hp->pz <= pzz) && ((hp->pz + hp->d) >= pzz)))
                            {
                                pw->psh_ct++;
                            } 
                            else 
                            {
                                pw->psh_ct = 0;
                            }
                        }
                        
                        if ((!(hp->attr & 0x20000)) && ((pw->stflg & 0x80)))
                        {
                            hp->attr |= 0x20000;
                            
                            pw->psh_idx = i;
                        }
                        
                        if (pw->px < wpx) 
                        {
                            if (pw->pz < wpz) 
                            {
                                abx = fabsf(pw->px - px);
                                abz = fabsf(pw->pz - pz);
                                
                                if (abx > abz)
                                {
                                    pw->pz = pz;
                                }
                                else 
                                {
                                    pw->px = px; 
                                }
                            }
                            else 
                            {
                                abx = fabsf(pw->px - px);
                                abz = fabsf(pw->pz - (pz + zn));
                                
                                if (abx > abz)
                                {
                                    pw->pz = pz + zn;
                                } 
                                else
                                {
                                    pw->px = px;
                                }
                            }
                        } 
                        else 
                        {
                            if (pw->pz < wpz)
                            { 
                                abx = fabsf(pw->px - (px + xn));
                                abz = fabsf(pw->pz - pz);
                                
                                if (abx > abz)
                                {
                                    pw->pz = pz;
                                } 
                                else 
                                {
                                    pw->px = px + xn;
                                }
                            } 
                            else 
                            {
                                abx = fabsf(pw->px - (px + xn));
                                abz = fabsf(pw->pz - (pz + zn));
                                
                                if (abx > abz) 
                                {
                                    pw->pz = pz + zn;
                                } 
                                else 
                                {
                                    pw->px = px + xn;
                                }
                            }
                        }
                    }
                }
                
                break;
            case 2:                             
            case 3:                             
                if (((!(hp->type & 0x1)) || (!(pw->flg & 0x400))) && ((!(hp->attr & 0x1)) || (hp->flr_no == pw->flr_no)) && (!((hp->attr & 0x2)) || (!(pw->flg & 0x4000))) && (!((hp->attr & 0x4)) || (!(pw->stflg & 0x40000000))) && (!((hp->attr & 0x40)) || (!(pw->flg & 0x2000))))
                {
                    px = (hp->px - pw->aw) - hp->w;
                    pz = (hp->pz - pw->ad) - hp->w;
                    
                    xn = (2.0f * hp->w) + (2.0f * pw->aw);
                    zn = (2.0f * hp->w) + (2.0f * pw->ad);
                    
                    if ((((pw->px - px) >= 0) && ((pw->px - px) < xn)) && (((pw->pz - pz) >= 0) && ((pw->pz - pz) < zn)) && (((pw->py + pw->ah) >= hp->py) && (pw->py <= (hp->py + h)))) 
                    {
                        if (hp->px < pw->px)
                        {
                            if (hp->pz < pw->pz) 
                            {
                                abx = fabsf(pw->px - (pw->aw + (hp->px + hp->w)));
                                abz = fabsf(pw->pz - (pw->ad + (hp->pz + hp->w)));
                                
                                if (abx < abz) 
                                {  
                                    if (fabsf(hp->pz - pw->pz) < pw->ad) 
                                    {
                                        hit++;
                                        
                                        pw->px = pw->aw + (hp->px + hp->w);
                                    }
                                } 
                                else if (fabsf(hp->px - pw->px) < pw->aw) 
                                {
                                    hit++;
                                    
                                    pw->pz = pw->ad + (hp->pz + hp->w);
                                }
                            } 
                            else 
                            {
                                abx = fabsf(pw->px - (pw->aw + (hp->px + hp->w)));
                                abz = fabsf(pw->pz - pz);
                                
                                if (abx < abz) 
                                {
                                    if (fabsf(hp->pz - pw->pz) < pw->ad)
                                    {
                                        hit++;
                                        
                                        pw->px = pw->aw + (hp->px + hp->w);
                                    }
                                } 
                                else if (fabsf(hp->px - pw->px) < pw->aw) 
                                {
                                    hit++;
                                    
                                    pw->pz = pz;
                                }
                            }
                        } 
                        else if (hp->pz < pw->pz) 
                        {
                            abx = fabsf(pw->px - px);
                            abz = fabsf(pw->pz - (pw->ad + (hp->pz + hp->w)));
                            
                            if (abx < abz) 
                            {
                                if (fabsf(hp->pz - pw->pz) < pw->ad)
                                {
                                    hit++;
                                    
                                    pw->px = px;
                                }
                            } 
                            else if (fabsf(hp->px - pw->px) < pw->aw) 
                            {
                                hit++;
                                
                                pw->pz = pw->ad + (hp->pz + hp->w);
                            }
                        } 
                        else 
                        {
                            abx = fabsf(pw->px - px);
                            abz = fabsf(pw->pz - pz);
                            
                            if (abx < abz) 
                            {
                                if (fabsf(hp->pz - pw->pz) < pw->ad) 
                                {
                                    hit++;
                                    
                                    pw->px = px;
                                }
                            } 
                            else if (fabsf(hp->px - pw->px) < pw->aw) 
                            {
                                hit++;
                                
                                pw->pz = pz;
                            }
                        }
                        
                        px = hp->px - (pw->px - pw->aw); 
                        pz = hp->pz - (pw->pz - pw->ad);
                        
                        ln = njSqrt((px * px) + (pz * pz));
                        
                        if (ln < hp->w)
                        {
                            hit++;
                            
                            r = 10430.381f * atan2f(px, pz);
                            
                            njSinCos(r, &pw->px, &pw->pz);
                            
                            pw->px = pw->aw + (hp->px - (pw->px * hp->w));
                            pw->pz = pw->ad + (hp->pz - (pw->pz * hp->w));
                        } 
                        else 
                        {
                            px = hp->px - (pw->px + pw->aw); 
                            pz = hp->pz - (pw->pz - pw->ad);
                            
                            ln = njSqrt((px * px) + (pz * pz));
                            
                            if (ln < hp->w) 
                            {
                                hit++;
                                
                                r = 10430.381f * atan2f(px, pz);
                                
                                njSinCos(r, &pw->px, &pw->pz);
                                
                                pw->px = (hp->px - (pw->px * hp->w)) - pw->aw;
                                pw->pz = pw->ad + (hp->pz - (pw->pz * hp->w));
                            } 
                            else 
                            {
                                px = hp->px - (pw->px - pw->aw); 
                                pz = hp->pz - (pw->pz + pw->ad);
                                
                                ln = njSqrt((px * px) + (pz * pz));
                                
                                if (ln < hp->w)
                                {
                                    hit++;
                                    
                                    r = 10430.381f * atan2f(px, pz);
                                    
                                    njSinCos(r, &pw->px, &pw->pz);
                                    
                                    pw->px = pw->aw + (hp->px - (pw->px * hp->w));
                                    pw->pz = (hp->pz - (pw->pz * hp->w)) - pw->ad;
                                } 
                                else 
                                {
                                    px = hp->px - (pw->px + pw->aw); 
                                    pz = hp->pz - (pw->pz + pw->ad);
                                    
                                    ln = njSqrt((px * px) + (pz * pz));
                                    
                                    if (ln < hp->w) 
                                    {
                                        hit++;

                                        r = 10430.381f * atan2f(px, pz);
                                        
                                        njSinCos(r, &pw->px, &pw->pz);
                                        
                                        pw->px = (hp->px - (pw->px * hp->w)) - pw->aw;
                                        pw->pz = (hp->pz - (pw->pz * hp->w)) - pw->ad;
                                    }
                                }
                            }
                        }
                    }
                }
                
                break;
            case 4:                             
            case 5:                             
                if (((!(hp->type & 0x1)) || (!(pw->flg & 0x400))) && ((!(hp->attr & 0x1)) || (hp->flr_no == pw->flr_no)) && (!((hp->attr & 0x2)) || (!(pw->flg & 0x4000))) && ((!(hp->attr & 0x4)) || (!(pw->stflg & 0x40000000))))
                {
                    if (bhCheckInnerTriangle2(hp, (NJS_POINT3*)&pw->px, pw->aw, pw->ad, pw->ah) != 0) 
                    {
                        l.vy = 0;
                        l.py = 0;
                        
                        hit++;
                        
                        switch (hp->id) 
                        { 
                        case 0:     
                            px = hp->px + pw->aw;
                            pz = hp->pz + pw->ad;
                            break;
                        case 1:     
                            px = hp->px + pw->aw;
                            pz = hp->pz - pw->ad;
                            break;
                        case 2:     
                            px = hp->px - pw->aw;
                            pz = hp->pz + pw->ad;
                            break;
                        case 3:     
                            px = hp->px - pw->aw;
                            pz = hp->pz - pw->ad;
                            break;
                        }
                        
                        l.px = px;
                        l.pz = pz + hp->d;
                        
                        l.vx =  hp->w;
                        l.vz = -hp->d;
                        
                        njDistanceP2L((NJS_POINT3*)&pw->px, &l, &pd);
                        
                        pw->px = pd.x;
                        pw->pz = pd.z; 
                    } 
                    else 
                    {
                        switch (hp->id)
                        { 
                        case 0:     
                            ht.px = hp->px;
                            ht.py = hp->py;
                            ht.pz = hp->pz;
                            
                            ht.w = 0;
                            ht.h = hp->h;
                            ht.d = hp->d;
                            
                            if (bhCheckBox2Box(&ht, (NJS_POINT3*)&pw->px, pw->aw, pw->ad, pw->ah) != 0)
                            {
                                hit++;
                            }
                            
                            ht.w = hp->w;
                            ht.h = hp->h;
                            ht.d = 0;
                            
                            if (bhCheckBox2Box(&ht, (NJS_POINT3*)&pw->px, pw->aw, pw->ad, pw->ah) != 0) 
                            {
                                hit++;
                            }
                            
                            break;
                        case 1:     
                            ht.px = hp->px;
                            ht.py = hp->py;
                            ht.pz = hp->pz + hp->d;
                            
                            ht.w =  0;
                            ht.h =  hp->h;
                            ht.d = -hp->d;
                            
                            if (bhCheckBox2Box(&ht, (NJS_POINT3*)&pw->px, pw->aw, pw->ad, pw->ah) != 0) 
                            {
                                hit++;
                            }
                            
                            r = 0;
                            
                            ht.pz = hp->pz - r;
                            
                            ht.w = hp->w;
                            ht.h = hp->h;
                            ht.d = 0;
                            
                            if (bhCheckBox2Box(&ht, (NJS_POINT3*)&pw->px, pw->aw, pw->ad, pw->ah) != 0) 
                            {
                                hit++;
                            }
                            
                            break;
                        case 2:     
                            r = 0;
                            
                            ht.px = hp->px - r;
                            ht.py = hp->py;
                            ht.pz = hp->pz;
                            
                            ht.w = 0;
                            ht.h = hp->h;
                            ht.d = hp->d;
                            
                            if (bhCheckBox2Box(&ht, (NJS_POINT3*)&pw->px, pw->aw, pw->ad, pw->ah) != 0) 
                            {
                                hit++;
                            }
                            
                            ht.px = hp->px + hp->w;
                            
                            ht.w = -hp->w;
                            ht.h =  hp->h;
                            ht.d =  0;
                            
                            if (bhCheckBox2Box(&ht, (NJS_POINT3*)&pw->px, pw->aw, pw->ad, pw->ah) != 0) 
                            {
                                hit++;
                            }
                            
                            break;
                        case 3:     
                            r = 0;
                            
                            ht.px = hp->px - r;
                            ht.py = hp->py;  
                            ht.pz = hp->pz + hp->d;
                            
                            ht.w =  0;
                            ht.h =  hp->h;
                            ht.d = -hp->d;
                            
                            if (bhCheckBox2Box(&ht, (NJS_POINT3*)&pw->px, pw->aw, pw->ad, pw->ah) != 0) 
                            {
                                hit++;
                            }
                            
                            ht.px = hp->px + hp->w;
                            ht.pz = hp->pz - r;

                            ht.w = -hp->w;  
                            ht.h =  hp->h;
                            ht.d =  0;
                            
                            if (bhCheckBox2Box(&ht, (NJS_POINT3*)&pw->px, pw->aw, pw->ad, pw->ah) != 0) 
                            {
                                hit++;
                            }
                            
                            break;
                        }
                    }
                }
                
                break;
            case 6:                             
                if ((((pw->px - hp->px) >= 0) && ((pw->px - hp->px) < hp->w)) && (((pw->pz - hp->pz) >= 0) && ((pw->pz - hp->pz) < hp->d)) && (((pw->py + pw->ah) >= hp->py) && (pw->py <= (hp->py + h))) && ((pw->flg & 0x100)))
                {
                    hit++;
                    
                    switch (hp->id) 
                    { 
                    case 0:         
                        l.px = hp->px;
                        l.py = hp->py;
                        l.pz = pw->pz;
                        
                        l.vx = hp->w;
                        l.vy = hp->h;
                        l.vz = 0;
                        break;
                    case 1:         
                        l.px = pw->px;
                        l.py = hp->py;
                        l.pz = hp->pz + hp->d;
                        
                        l.vx =  0;
                        l.vy =  hp->h;
                        l.vz = -hp->d;
                        break;
                    case 2:         
                        l.px = pw->px;
                        l.py = hp->py;
                        l.pz = hp->pz;
                        
                        l.vx = 0;
                        l.vy = hp->h;
                        l.vz = hp->d;
                        break;
                    case 3:         
                        l.px = hp->px + hp->w;
                        l.py = hp->py;
                        l.pz = pw->pz;
                        
                        l.vx = -hp->w;
                        l.vy =  hp->h;
                        l.vz =  0;
                        break;
                    }
                    
                    njDistanceP2L((NJS_POINT3*)&pw->px, &l, &pd);
                    
                    pw->py = pd.y;
                    
                    for (j = 0; j < 31; j++) 
                    { 
                        if (((rom->grand[j]) && (pw->py >= rom->grand[j])) || ((j == 2) && (pw->py >= rom->grand[j]))) 
                        {
                            pw->flr_no = j - 2; 
                        } 
                    }
                    
                    if (pw->flr_no != hp->flr_no) 
                    {
                        if (pw->py < rom->grand[pw->flr_no + 2]) 
                        {
                            pw->px = pd.x;
                            pw->pz = pd.z;
                        }
                        else 
                        {
                            pw->py = rom->grand[pw->flr_no + 2];
                        }
                    }
                    else 
                    {
                        pw->px = pd.x;
                        pw->pz = pd.z;
                        
                        if (pw->py < rom->grand[pw->flr_no + 2]) 
                        {
                            pw->py = rom->grand[pw->flr_no + 2];
                        }
                    }
                }
                
                break;
            case 7:                             
                if ((!(hp->attr & 0x1)) || (hp->flr_no == pw->flr_no)) 
                {
                    wpx = hp->px + (0.5f * hp->w);
                    wpz = hp->pz + (0.5f * hp->d);
                    
                    px = hp->px - pw->aw; 
                    pz = hp->pz - pw->ad;  
                    
                    xn = hp->w + (2.0f * pw->aw);
                    zn = hp->d + (2.0f * pw->ad);   
                    
                    if (((((pw->px - px) >= 0) && ((pw->px - px) < xn)) && (((pw->pz - pz) >= 0) && ((pw->pz - pz) < zn)) && ((pw->py < (hp->py + hp->h)) && ((pw->py + pw->ah) > (hp->py + hp->h))) && ((pw->flg & 0x100))) || ((((pw->px - px) >= 0) && ((pw->px - px) < xn)) && (((pw->pz - pz) >= 0) && ((pw->pz - pz) < zn)) && ((((pw->py + pw->ah) >= (hp->py + hp->h)) && (pw->py < hp->py)) && (!(pw->flg & 0x100))))) 
                    {
                        hit++;
                        
                        if (pw->px < wpx) 
                        {
                            if (pw->pz < wpz) 
                            {
                                if (fabsf(pw->px - px) > fabsf(pw->pz - pz))
                                {
                                    pw->pz = pz;
                                } 
                                else 
                                {
                                    pw->px = px;
                                }
                            } 
                            else 
                            {
                                if (fabsf(pw->px - px) > fabsf(pw->pz - (pz + zn)))
                                {
                                    pw->pz = pz + zn;
                                } 
                                else 
                                {
                                    pw->px = px;
                                }
                            }
                        }
                        else 
                        {
                            if (pw->pz < wpz) 
                            {
                                if (fabsf(pw->px - (px + xn)) > fabsf(pw->pz - pz)) 
                                {
                                    pw->pz = pz;
                                } 
                                else 
                                {
                                    pw->px = px + xn;
                                }
                            } 
                            else 
                            {
                                if (fabsf(pw->px - (px + xn)) > fabsf(pw->pz - (pz + zn))) 
                                {
                                    pw->pz = pz + zn;
                                } 
                                else 
                                {
                                    pw->px = px + xn;
                                }
                            }
                        }
                    }
                }
                
                break;
            }
        }
    }
    
    if (hit != 0) 
    {
        pw->stflg |= 0x1;
    }
    
    if ((hit == 0) && ((pw->flg & 0x100))) 
    {
        pw->py = rom->grand[pw->flr_no + 2]; 
    }
    
    if (hit == 0)
    {
        pw->psh_ct = 0;
    }
}

// 100% matching!
ATR_WORK* bhCheckWallType(NJS_POINT3* pos, unsigned int flg, float ar, float ah)
{
    ATR_WORK* hp; 
    int i;      
    int wal_n;   
    float px, pz;   
    float xn, zn;    
    float ln;  
    float h;    

    wal_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < wal_n; i++) 
    {
        if (i < rom->wal_n) 
        {
            hp = &rom->walp[i];
        } 
        else 
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        if ((hp->flg & 0x1)) 
        {
            if (hp->h)
            {
                h = hp->h;
            } 
            else 
            {
                h = rom->h;
            }
            
            switch (hp->type) 
            {
            case 0:
            case 1:
                if ((!(hp->type & 0x1)) || (!(flg & 0x400))) 
                {
                    pz = hp->pz - ar;
                    
                    xn = hp->w + (2.0f * ar);
                    zn = hp->d + (2.0f * ar);
                    
                    px = pos->x - (hp->px - ar);
                    
                    if (((px >= 0) && (px < xn)) && (((pos->z - pz) >= 0) && ((pos->z - pz) < zn)) && (((pos->y + ah) >= hp->py) && (pos->y <= (hp->py + h)))) 
                    {
                        return hp;
                    }
                }
                
                break;
            case 2:
            case 3:
                if ((!(hp->type & 0x1)) || (!(flg & 0x400))) 
                {
                    px = pos->x - hp->px;
                    pz = pos->z - hp->pz;
                    
                    ln = njSqrt((px * px) + (pz * pz));
                    
                    if ((ln < (ar + hp->w)) && (((pos->y + ah) >= hp->py) && (pos->y <= (hp->py + h)))) 
                    {
                        return hp;
                    }
                }
                
                break;
            case 4:
            case 5:
                if (((!(hp->type & 0x1)) || (!(flg & 0x400))) && (bhCheckInnerTriangle(hp, pos, ar, ah) != 0)) 
                {
                    return hp;
                }
                
                break;
            case 6:
                if ((((pos->x - hp->px) >= 0) && ((pos->x - hp->px) < hp->w)) && (((pos->z - hp->pz) >= 0) && ((pos->z - hp->pz) < hp->d)) && (((pos->y + ah) >= hp->py) && (pos->y <= (hp->py + h))))  
                {
                    return hp;
                }
                
                break;
            case 7:
                pz = hp->pz - ar;
                
                xn = hp->w + (2.0f * ar);
                zn = hp->d + (2.0f * ar);
                
                px = hp->px - ar; 
                
                if ((((((pos->x - px) >= 0) && ((pos->x - px) < xn)) && (((pos->z - pz) >= 0) && ((pos->z - pz) < zn)) && ((pos->y < (hp->py + hp->h)) && ((pos->y + ah) > (hp->py + hp->h)))) && ((flg & 0x100))) || (((((pos->x - px) >= 0) && ((pos->x - px) < xn)) && (((pos->z - pz) >= 0) && ((pos->z - pz) < zn)) && (((pos->y + ah) >= (hp->py + hp->h)) && (pos->y < hp->py))) && (!(flg & 0x100)))) 
                {
                    return hp;
                }
                
                break;
            }
        } 
    } 
    
    return NULL;
}

// 100% matching!
ATR_WORK* bhCheckWallType2(NJS_POINT3* pos, unsigned int flg, float aw, float ad, float ah, int idx_ct)
{
    NJS_SPHERE sph; 
    NJS_BOX box;    
    ATR_WORK* hp; 
    int i;       
    int wal_n;    
    float px, pz;    
    float xn, zn;      
    float h;       

    wal_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < wal_n; i++) 
    {
        if (i < rom->wal_n) 
        {
            hp = &rom->walp[i];
        } 
        else 
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        if (((hp->flg & 0x1)) && ((!(hp->attr & 0x40)) || (!(flg & 0x2000))))
        {
            if (hp->h)
            {
                h = hp->h;
            } 
            else 
            {
                h = rom->h;
            }
            
            switch (hp->type) 
            {
            case 0:
            case 1:
                if (((!(hp->type & 0x1)) || (!(flg & 0x400))) && ((!(hp->attr & 0x10000)) || (!(flg & 0x2000)) || (hp->prm3 != (unsigned char)idx_ct))) 
                {
                    pz = hp->pz - ad;
                    
                    xn = hp->w + (2.0f * aw);
                    zn = hp->d + (2.0f * ad);
                    
                    px = pos->x - (hp->px - aw);
                    
                    if (((px >= 0) && (px < xn)) && (((pos->z - pz) >= 0) && ((pos->z - pz) < zn)) && (((pos->y + ah) >= hp->py) && (pos->y <= (hp->py + h)))) 
                    {
                        return hp;
                    } 
                }
                
                break;
            case 2:
            case 3:
                if ((!(hp->type & 0x1)) || (!(flg & 0x400))) 
                {
                    px = (hp->px - aw) - hp->w;
                    pz = (hp->pz - ad) - hp->w;
                    
                    xn = (2.0f * hp->w) + (2.0f * aw);
                    zn = (2.0f * hp->w) + (2.0f * ad);
                    
                    if ((((pos->x - px) >= 0) && ((pos->x - px) < xn)) && (((pos->z - pz) >= 0) && ((pos->z - pz) < zn)) && (((pos->y + ah) >= hp->py) && (pos->y <= (hp->py + h))))  
                    {
                        sph.c.x = hp->px; 
                        sph.c.y = hp->py;
                        sph.c.z = hp->pz;
                        sph.r   = hp->w;
                        
                        box.v[0].y = box.v[1].y = box.v[2].y = box.v[3].y = 0.1f;
                        box.v[4].y = box.v[5].y = box.v[6].y = box.v[7].y = 0;
                        
                        box.v[0].x = box.v[4].x = pos->x - aw; 
                        box.v[0].z = box.v[4].z = pos->z + ad;
                        
                        box.v[1].x = box.v[5].x = pos->x - aw;
                        box.v[1].z = box.v[5].z = pos->z - ad;
                        
                        box.v[2].x = box.v[6].x = pos->x + aw;
                        box.v[2].z = box.v[6].z = pos->z - ad;
                        
                        box.v[3].x = box.v[7].x = pos->x + aw;
                        box.v[3].z = box.v[7].z = pos->z + ad;
                            
                        if (njCollisionCheckBS(&box, &sph) != 0) 
                        {
                            return hp;
                        }
                    }
                }
                
                break;
            case 4:
            case 5:
                if (((!(hp->type & 0x1)) || (!(flg & 0x400))) && (bhCheckInnerTriangle2(hp, pos, aw, ad, ah) != 0)) 
                {
                    return hp;
                }
                
                break;
            case 6:
                if ((((pos->x - hp->px) >= 0) && ((pos->x - hp->px) < hp->w)) && (((pos->z - hp->pz) >= 0) && ((pos->z - hp->pz) < hp->d)) && (((pos->y + ah) >= hp->py) && (pos->y <= (hp->py + h))))  
                {
                    return hp;
                }
                
                break;
            case 7:
                pz = hp->pz - ad;
                
                xn = hp->w + (2.0f * aw);
                zn = hp->d + (2.0f * ad);
                
                px = hp->px - aw; 
                
                if ((((((pos->x - px) >= 0) && ((pos->x - px) < xn)) && (((pos->z - pz) >= 0) && ((pos->z - pz) < zn)) && ((pos->y < (hp->py + hp->h)) && ((pos->y + ah) > (hp->py + hp->h)))) && ((flg & 0x100))) || (((((pos->x - px) >= 0) && ((pos->x - px) < xn)) && (((pos->z - pz) >= 0) && ((pos->z - pz) < zn)) && (((pos->y + ah) >= (hp->py + hp->h)) && (pos->y < hp->py))) && (!(flg & 0x100)))) 
                {
                    return hp;
                }
                
                break; 
            }
        } 
    } 
    
    return NULL;
}

// 99.95% matching
ATR_WORK* bhCheckWallRefAngle(NJS_POINT3* pos, unsigned int flg, float ar, float ah, int* ay)
{
    NJS_POINT3 pd; 
    NJS_LINE l;    
    ATR_WORK* hp; 
    ATR_WORK ht;  
    int i;         
    int wal_n;    
    float px, py, pz;    
    float xn, zn;    
    float ln, ln2;     
    float wpx, wpz;    
    float h;     
    float abx, aby, abz;    
    int r;         

    wal_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < wal_n; i++) 
    {
        if (i < rom->wal_n) 
        {
            hp = &rom->walp[i];
        }
        else
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        if ((hp->flg & 0x1))
        {
            if (hp->h)
            {
                h = hp->h;
            }
            else
            {
                h = rom->h;
            }
            
            switch (hp->type)
            {                      
            case 0:                                 
            case 1:                                 
                if (((!(hp->type & 0x1)) || (!(flg & 0x400))) && ((!(hp->attr & 0x20)) || (!(flg & 0x200))))  
                {
                    wpx = hp->px + (0.5f * hp->w);
                    wpz = hp->pz + (0.5f * hp->d);
                    
                    px = hp->px - ar;
                    pz = hp->pz - ar;
                    
                    xn = hp->w + (2.0f * ar);
                    zn = hp->d + (2.0f * ar);
                    
                    if ((((pos->x - px) >= 0) && ((pos->x - px) < xn)) && (((pos->z - pz) >= 0) && ((pos->z - pz) < zn)) && (((pos->y + ah) >= hp->py) && (pos->y <= (hp->py + h))))
                    {
                        aby = fabsf(pos->y - (hp->py + h));
                        
                        if (pos->x < wpx) 
                        {
                            if (pos->z < wpz)
                            {
                                abx = fabsf(pos->x - px);
                                abz = fabsf(pos->z - pz);
                                
                                if (abx > abz) 
                                {
                                    if (aby < abz)
                                    {
                                        pos->y = hp->py + h;
                                    }
                                    else 
                                    {
                                        pos->z = pz;
                                        
                                        *ay = 32768 - *ay;
                                    }
                                } 
                                else if (aby < abx)
                                {
                                    pos->y = hp->py + h;
                                } 
                                else
                                {
                                    pos->x = px;
                                    
                                    *ay = -*ay;
                                }
                            } 
                            else
                            {
                                abx = fabsf(pos->x - px);
                                abz = fabsf(pos->z - (pz + zn));
                                
                                if (abx > abz) 
                                {
                                    if (aby < abz) 
                                    {
                                        pos->y = hp->py + h;
                                    } 
                                    else 
                                    {
                                        pos->z = pz + zn;
                                        
                                        *ay = 32768 - *ay;
                                    }
                                } 
                                else if (aby < abx) 
                                {
                                    pos->y = hp->py + h;
                                } 
                                else
                                {
                                    pos->x = px;
                                    
                                    *ay = -*ay;
                                }
                            }
                        } 
                        else 
                        {
                            if (pos->z < wpz) 
                            {
                                abx = fabsf(pos->x - (px + xn));
                                abz = fabsf(pos->z - pz);
                                
                                if (abx > abz) 
                                {
                                    if (aby < abz) 
                                    {
                                        pos->y = hp->py + h;
                                    }
                                    else
                                    {
                                        pos->z = pz;
                                        
                                        *ay = 32768 - *ay;
                                    }
                                }
                                else if (aby < abx)
                                {
                                    pos->y = hp->py + h;
                                } 
                                else 
                                {
                                    pos->x = px + xn;
                                    
                                    *ay = -*ay;
                                }
                            } 
                            else 
                            {
                                abx = fabsf(pos->x - (px + xn));
                                abz = fabsf(pos->z - (pz + zn));
                                
                                if (abx > abz) 
                                {
                                    if (aby < abz) 
                                    {
                                        pos->y = hp->py + h;
                                    }
                                    else
                                    {
                                        pos->z = pz + zn;
                                        
                                        *ay = 32768 - *ay;
                                    }
                                }
                                else if (aby < abx)
                                {
                                    pos->y = hp->py + h;
                                } 
                                else 
                                {
                                    pos->x = px + xn;
                                    
                                    *ay = -*ay;
                                }
                            }
                        }
                        
                        return hp;
                    }
                }
                
                break;
            case 2:                                 
            case 3:                                 
                if (((!(hp->type & 0x1)) || (!(flg & 0x400))) && ((!(hp->attr & 0x20)) || (!(flg & 0x200)))) 
                {
                    px = hp->px - pos->x;
                    pz = hp->pz - pos->z;
                    
                    ln = njSqrt((px * px) + (pz * pz));
                    
                    if ((ln < (ar + hp->w)) && (((pos->y + ah) >= hp->py) && (pos->y <= (hp->py + h))))
                    {
                        r = 10430.381f * atan2f(px, pz); 
                        
                        ln2 = ar + hp->w;
                        
                        aby = fabsf(pos->y - (hp->py + h));
                        abx = fabsf(ln2    - ln); 
                        
                        if (abx < aby) 
                        {
                            njSinCos(r, &pos->x, &pos->z);
                            
                            pos->x = hp->px - (pos->x * ln2);
                            pos->z = hp->pz - (pos->z * ln2);
                            
                            *ay = r + ((r + 32768) - *ay);
                        }
                        else 
                        {
                            pos->y = hp->py + h;
                        }
                        
                        return hp;
                    }
                }
                
                break;
            case 4:                                 
            case 5:                                 
                if (((!(hp->type & 0x1)) || (!(flg & 0x400))) && ((!(hp->attr & 0x20)) || (!(flg & 0x200)))) 
                {
                    if (bhCheckInnerTriangle(hp, pos, ar, ah) != 0) 
                    {
                        l.vy = 0;
                        l.py = 0; 
                        
                        switch (hp->id) 
                        {          
                        case 0:                     
                            px = hp->px + ar;
                            pz = hp->pz + ar;
                            break;
                        case 1:                     
                            px = hp->px + ar;
                            pz = hp->pz - ar;
                            break;
                        case 2:                     
                            px = hp->px - ar;
                            pz = hp->pz + ar;
                            break;
                        case 3:                     
                            px = hp->px - ar;
                            pz = hp->pz - ar;
                            break;
                        }
                        
                        l.px = px;
                        l.pz = pz + hp->d;
                        
                        l.vx =  hp->w;
                        l.vz = -hp->d;
                        
                        njDistanceP2L(pos, &l, &pd);
                        
                        px = pd.x - pos->x; 
                        pz = pd.z - pos->z;
                        
                        ln2 = njSqrt((px * px) + (pz * pz));
                        
                        aby = fabsf(pos->y - (hp->py + h));
                        
                        if (aby >= ln2) 
                        {
                            pos->x = pd.x;
                            pos->z = pd.z;
                            
                            r = 10430.381f * atan2f(hp->w, hp->d);
                            
                            *ay = r + ((r + 32768) - *ay);
                        } 
                        else 
                        {
                            pos->y = hp->py + h;
                        }
                        
                        return hp;
                    }
                    
                    switch (hp->id) 
                    {            
                    case 0:                         
                        ht.px = hp->px;
                        ht.py = hp->py;
                        ht.pz = hp->pz;
                        
                        ht.w = 0;
                        ht.h = hp->h;
                        ht.d = hp->d;
                        
                        if (bhCheckBox(&ht, pos, ar, ah, 12) != 0) 
                        {
                            *ay = -*ay;
                            
                            return hp;
                        }
                        
                        ht.w = hp->w;
                        ht.h = hp->h;
                        ht.d = 0;
                        
                        if (bhCheckBox(&ht, pos, ar, ah, 10) != 0)
                        {
                            *ay = -*ay;
                            
                            return hp;
                        }
                        
                        break;
                    case 1:                         
                        ht.px = hp->px;
                        ht.py = hp->py;
                        ht.pz = hp->pz + hp->d;
                        
                        ht.w =  0;
                        ht.h =  hp->h;
                        ht.d = -hp->d;
                        
                        if (bhCheckBox(&ht, pos, ar, ah, 12) != 0) 
                        {
                            *ay = -*ay;
                            
                            return hp;
                        }
                        
                        r = 0;
                        
                        ht.pz = hp->pz - r;
                        
                        ht.w = hp->w;
                        ht.h = hp->h;
                        ht.d = 0;
                        
                        if (bhCheckBox(&ht, pos, ar, ah, 5) != 0) 
                        {
                            *ay = -*ay;
                            
                            return hp;
                        }
                        
                        break;
                    case 2:          
                        r = 0;
                        
                        ht.px = hp->px - r;
                        ht.py = hp->py;
                        ht.pz = hp->pz;
                        
                        ht.w = 0;
                        ht.h = hp->h;
                        ht.d = hp->d;
                        
                        if (bhCheckBox(&ht, pos, ar, ah, 3) != 0)
                        {
                            *ay = -*ay;
                            
                            return hp;
                        }
                        
                        ht.px = hp->px + hp->w;
                        
                        ht.w = -hp->w;
                        ht.h =  hp->h;
                        ht.d =  0;
                        
                        if (bhCheckBox(&ht, pos, ar, ah, 10) != 0)
                        {
                            *ay = -*ay;
                            
                            return hp;
                        }
                        
                        break;
                    case 3:                   
                        r = 0;
                        
                        ht.px = hp->px - r;
                        ht.py = hp->py;
                        ht.pz = hp->pz + hp->d;
                        
                        ht.w =  0;
                        ht.h =  hp->h;
                        ht.d = -hp->d;
                        
                        if (bhCheckBox(&ht, pos, ar, ah, 3) != 0)
                        {
                            *ay = -*ay;
                            
                            return hp;
                        }
                        
                        ht.px = hp->px + hp->w;
                        ht.pz = hp->pz - r;
                        
                        ht.w = -hp->w;
                        ht.h =  hp->h;
                        ht.d =  0;
                        
                        if (bhCheckBox(&ht, pos, ar, ah, 5) != 0)
                        {
                            *ay = -*ay;
                            
                            return hp;
                        }
                        
                        break;
                    }
                }
                
                break;
            case 6:                                 
                if ((((pos->x - hp->px) >= 0) && ((pos->x - hp->px) < hp->w)) && (((pos->z - hp->pz) >= 0) && ((pos->z - hp->pz) < hp->d)) && (((pos->y + ah) >= hp->py) && (pos->y <= (hp->py + h))))
                {
                    // this switch is identical to the one found on bhSetWallRefAngle, however here registers won't match
                    switch (hp->id) 
                    { 
                    case 0:         
                        py = hp->py + ((hp->h / hp->w) * (pos->x - hp->px));
                        break;
                    case 1:         
                        py = hp->h + (hp->py + ((hp->h / hp->d) * (hp->pz - pos->z)));
                        break;
                    case 2:         
                        py = hp->py + ((hp->h / hp->d) * (pos->z - hp->pz));
                        break;
                    case 3:         
                        py = hp->h + (hp->py + ((hp->h / hp->w) * (hp->px - pos->x)));
                        break;
                    }
                    
                    if (pos->y < py) 
                    {
                        aby = fabsf(pos->y - py);
                        
                        wpx = hp->px + (0.5f * hp->w);
                        wpz = hp->pz + (0.5f * hp->d);
                        
                        px = hp->px - ar;
                        pz = hp->pz - ar;
                        
                        xn = hp->w + (2.0f * ar);
                        zn = hp->d + (2.0f * ar);
                        
                        if (pos->x < wpx) 
                        {
                            if (pos->z < wpz) 
                            {
                                abx = fabsf(pos->x - px);
                                abz = fabsf(pos->z - pz);
                                
                                if (abx > abz) 
                                {
                                    if (aby < abz) 
                                    {
                                        pos->y = py;
                                    } 
                                    else 
                                    {
                                        pos->z = pz;
                                        
                                        *ay = 32768 - *ay;
                                    }
                                } 
                                else if (aby < abx) 
                                {
                                    pos->y = py;
                                } 
                                else 
                                {
                                    pos->x = px;
                                    
                                    *ay = -*ay;
                                }
                            } 
                            else 
                            {
                                abx = fabsf(pos->x - px);
                                abz = fabsf(pos->z - (pz + zn));
                                
                                if (abx > abz)
                                {
                                    if (aby < abz)
                                    {
                                        pos->y = py;
                                    } 
                                    else 
                                    {
                                        pos->z = pz + zn;
                                        
                                        *ay = 32768 - *ay;
                                    }
                                } 
                                else if (aby < abx) 
                                {
                                    pos->y = py;
                                } 
                                else 
                                {
                                    pos->x = px;
                                    
                                    *ay = -*ay;
                                }
                            }
                        }
                        else if (pos->z < wpz) 
                        {
                            abx = fabsf(pos->x - (px + xn));
                            abz = fabsf(pos->z - pz);
                            
                            if (abx > abz) 
                            {
                                if (aby < abz) 
                                {
                                    pos->y = py;
                                } 
                                else 
                                {
                                    pos->z = pz;
                                    
                                    *ay = 32768 - *ay;
                                }
                            } 
                            else if (aby < abx) 
                            {
                                pos->y = py;
                            } 
                            else 
                            {
                                pos->x = px + xn;
                                
                                *ay = -*ay;
                            }
                        } 
                        else 
                        {
                            abx = fabsf(pos->x - (px + xn));
                            abz = fabsf(pos->z - (pz + zn));
                            
                            if (abx > abz) 
                            {
                                if (aby < abz) 
                                {
                                    pos->y = py;
                                }
                                else 
                                {
                                    pos->z = pz + zn;
                                    
                                    *ay = 32768 - *ay;
                                }
                            } 
                            else if (aby < abx) 
                            {
                                pos->y = py;
                            } 
                            else 
                            {
                                pos->x = px + xn;
                                
                                *ay = -*ay;
                            }
                        }
                        
                        return hp;
                    }
                    
                    break;
                }
                
                break;
            case 7:                                 
                if ((!(hp->attr & 0x20)) || (!(flg & 0x200))) 
                {
                    wpx = hp->px + (0.5f * hp->w);
                    wpz = hp->pz + (0.5f * hp->d);
                    
                    px = hp->px - ar;
                    pz = hp->pz - ar;
                    
                    xn = hp->w + (2.0f * ar);
                    zn = hp->d + (2.0f * ar);
                    
                    if (((((pos->x - px) >= 0) && ((pos->x - px) < xn)) && (((pos->z - pz) >= 0) && ((pos->z - pz) < zn)) && ((pos->y < (hp->py + hp->h)) && ((pos->y + ah) > (hp->py + hp->h))) && ((flg & 0x100))) || ((((pos->x - px) >= 0) && ((pos->x - px) < xn)) && (((pos->z - pz) >= 0) && ((pos->z - pz) < zn)) && (((pos->y + ah) >= (hp->py + hp->h)) && (pos->y < hp->py)) && (!(flg & 0x100)))) 
                    {
                        aby = fabsf(pos->y - hp->py);
                        
                        if (pos->x < wpx)
                        {
                            if (pos->z < wpz) 
                            {
                                abx = fabsf(pos->x - px);
                                abz = fabsf(pos->z - pz);
                                
                                if (abx > abz) 
                                {
                                    if (aby < abz) 
                                    {
                                        pos->y = hp->py;
                                    } 
                                    else 
                                    {
                                        pos->z = pz;
                                        
                                        *ay = 32768 - *ay;
                                    }
                                } 
                                else if (aby < abx) 
                                {
                                    pos->y = hp->py;
                                } 
                                else 
                                {
                                    pos->x = px;
                                    
                                    *ay = -*ay;
                                }
                            }
                            else 
                            {
                                abx = fabsf(pos->x - px);
                                abz = fabsf(pos->z - (pz + zn));
                                
                                if (abx > abz)
                                {
                                    if (aby < abz) 
                                    {
                                        pos->y = hp->py;
                                    } 
                                    else 
                                    {
                                        pos->z = pz + zn;
                                        
                                        *ay = 32768 - *ay;
                                    }
                                } 
                                else if (aby < abx) 
                                {
                                    pos->y = hp->py;
                                } 
                                else
                                {
                                    pos->x = px;
                                    
                                    *ay = -*ay;
                                }
                            }
                        } 
                        else
                        {
                            if (pos->z < wpz) 
                            {
                                abx = fabsf(pos->x - (px + xn));
                                abz = fabsf(pos->z - pz);
                                
                                if (abx > abz)
                                {
                                    if (aby < abz)
                                    {
                                        pos->y = hp->py;
                                    }
                                    else 
                                    {
                                        pos->z = pz;
                                        
                                        *ay = 32768 - *ay;
                                    }
                                } 
                                else if (aby < abx) 
                                {
                                    pos->y = hp->py;
                                }
                                else 
                                {
                                    pos->x = px + xn;
                                    
                                    *ay = -*ay;
                                }
                            } 
                            else 
                            {
                                abx = fabsf(pos->x - (px + xn));
                                abz = fabsf(pos->z - (pz + zn));
                                
                                if (abx > abz) 
                                {
                                    if (aby < abz) 
                                    {
                                        pos->y = hp->py;
                                    }
                                    else 
                                    {
                                        pos->z = pz + zn;
                                        
                                        *ay = 32768 - *ay;
                                    }
                                } 
                                else if (aby < abx) 
                                {
                                    pos->y = hp->py;
                                }
                                else 
                                {
                                    pos->x = px + xn;
                                    
                                    *ay = -*ay;
                                }
                            }
                        }
                        
                        return hp;
                    }
                }
            }
        } 
    } 
    
    return NULL;
}

// 100% matching!
void bhSetWallRefAngle(ATR_WORK* hp, NJS_POINT3* pos, float ar, float ah, int* ay) 
{
    NJS_POINT3 pd;
    NJS_LINE l;
    ATR_WORK ht;
    float px, py, pz;
    float xn, zn;
    float ln, ln2;
    float wpx, wpz;
    float h;
    float abx, aby, abz;
    int r;
    float zero; // not from DWARF
	
    if (!hp->h) 
    { 
        h = rom->h; 
    } 
    else 
    { 
        h = hp->h;
    }
    
    switch (hp->type) 
    {
    case 0:
    case 1:
        wpx = hp->px + (0.5f * hp->w);
        wpz = hp->pz + (0.5f * hp->d);
        
        px = hp->px - ar;
        pz = hp->pz - ar;
        
        xn = hp->w + (2.0f * ar);
        zn = hp->d + (2.0f * ar);
        
        aby = fabsf(pos->y - (hp->py + h));
        
        if (pos->x < wpx) 
        {
            if (pos->z < wpz) 
            {
                abx = fabsf(pos->x - px);
                abz = fabsf(pos->z - pz);
                
                if (abx > abz) 
                {
                    if (aby < abz) 
                    { 
                        pos->y = hp->py + h; 
                    }
                    else 
                    {
                        pos->z = pz;
                        
                        *ay = 32768 - *ay;
                    }
                }
                else if (aby < abx) 
                { 
                    pos->y = hp->py + h; 
                }
                else 
                {
                    pos->x = px;
                    
                    *ay = -*ay;
                }
            } 
            else 
            {
                abx = fabsf(pos->x - px);
                abz = fabsf(pos->z - (pz + zn));
                
                if (abx > abz) 
                {
                    if (aby < abz) 
                    { 
                        pos->y = hp->py + h; 
                    }
                    else 
                    {
                        pos->z = pz + zn;
                        
                        *ay = 32768 - *ay;
                    }
                }
                else if (aby < abx) 
                { 
                    pos->y = hp->py + h; 
                } 
                else
                {
                    pos->x = px;
                    
                    *ay = -*ay;
                }
            }
        }
        else if (pos->z < wpz) 
        {
            abx = fabsf(pos->x - (px + xn));
            abz = fabsf(pos->z - pz);
            
            if (abx > abz) 
            {
                if (aby < abz) 
                {
                    pos->y = hp->py + h; 
                } 
                else 
                {
                    pos->z = pz;
                    
                    *ay = 32768 - *ay;
                }
            } 
            else if (aby < abx) 
            { 
                pos->y = hp->py + h; 
            } 
            else
            {
                pos->x = px + xn;
                
                *ay = -*ay;
            }
        } 
        else 
        {
            abx = fabsf(pos->x - (px + xn));
            abz = fabsf(pos->z - (pz + zn));
            
            if (abx > abz) 
            {
                if (aby < abz)
                { 
                    pos->y = hp->py + h; 
                } 
                else 
                {
                    pos->z = pz + zn;
                    
                    *ay = 32768 - *ay;
                }
            }
            else if (aby < abx) 
            { 
                pos->y = hp->py + h; 
            } 
            else 
            {
                pos->x = px + xn;
                
                *ay = -*ay;
            }
        }
        
        break;
    case 2:
    case 3:
        px = hp->px - pos->x;
        pz = hp->pz - pos->z;
        
        ln = njSqrt((px * px) + (pz * pz));
        
        r = (65536.0f / PI_2) * atan2f(px, pz);
        
        ln2 = ar + hp->w;
        
        py = fabsf(pos->y - (hp->py + h));
        
        if (fabsf(ln2 - ln) < py) 
        {
            njSinCos(r, &pos->x, &pos->z);
            
            pos->x = hp->px - (pos->x * ln2);
            pos->z = hp->pz - (pos->z * ln2);
            
            *ay = r + ((r + (32767 + 1)) - *ay);
        } 
        else 
        {
            pos->y = hp->py + h;
        }
        
        break;
    case 4:
    case 5:
        if (bhCheckInnerTriangle(hp, pos, ar, ah) != 0) 
        {
            l.py = l.vy = 0;
            
            switch (hp->id) 
            {
            case 0:
                px = hp->px + ar;
                pz = hp->pz + ar;
                break;
            case 1:
                px = hp->px + ar;
                pz = hp->pz - ar;
                break;
            case 2:
                px = hp->px - ar;
                pz = hp->pz + ar;
                break;
            case 3:
                px = hp->px - ar;
                pz = hp->pz - ar;
                break;
            }
            
            l.px = px;
            l.pz = pz + hp->d;
            
            l.vx = hp->w;
            l.vz = -hp->d;
            
            njDistanceP2L(pos, &l, &pd);
            
            px = pd.x - pos->x;
            pz = pd.z - pos->z;
            
            abx = njSqrt((px * px) + (pz * pz));
            aby = fabsf(pos->y - (hp->py + h));
            
            if (aby >= abx) 
            {
                pos->x = pd.x;
                pos->z = pd.z;
                
                r = (65536.0f / PI_2) * atan2f(hp->w, hp->d);
                
                *ay = r + ((r + (32767 + 1)) - *ay);
            } 
            else 
            {
                pos->y = hp->py + h;
            }
        } 
        else 
        {
            zero = 0;
            
            switch (hp->id) 
            {
            case 0:
                ht.px = hp->px;
                ht.py = hp->py;
                ht.pz = hp->pz;
                
                ht.w = 0;
                ht.h = hp->h;
                
                ht.d = hp->d;
                
                if (bhCheckBox(&ht, pos, ar, ah, 12) != 0) 
                {
                    *ay = -*ay;
                    break;
                }

                ht.w = hp->w;
                ht.h = hp->h;
                
                ht.d = 0;
                
                if (bhCheckBox(&ht, pos, ar, ah, 10) != 0) 
                {
                    *ay = -*ay;
                }
                
                break;
            case 1:
                ht.px = hp->px;
                ht.py = hp->py;
                ht.pz = hp->pz + hp->d;
                
                ht.w = 0;
                ht.h = hp->h;
                
                ht.d = -hp->d;
                
                if (bhCheckBox(&ht, pos, ar, ah, 12) != 0) 
                {
                    *ay = -*ay;
                    break;
                }
                
                ht.pz = hp->pz - zero;
                
                ht.w = hp->w;
                ht.h = hp->h;
                
                ht.d = 0;
                
                if (bhCheckBox(&ht, pos, ar, ah, 5) != 0) 
                {
                    *ay = -*ay;
                }
                
                break;
            case 2:
                ht.px = hp->px - zero;
                ht.py = hp->py;
                ht.pz = hp->pz;
                
                ht.w = 0;
                ht.h = hp->h;
                
                ht.d = hp->d;
                
                if (bhCheckBox(&ht, pos, ar, ah, 3) != 0) 
                {
                    *ay = -*ay;
                    break;
                }
                
                ht.px = hp->px + hp->w;
                
                ht.w = -hp->w;
                ht.h = hp->h;
                
                ht.d = 0;
                
                if (bhCheckBox(&ht, pos, ar, ah, 10) != 0) 
                {
                    *ay = -*ay;
                }
                
                break;
            case 3:
                ht.px = hp->px - zero;
                ht.py = hp->py;
                ht.pz = hp->pz + hp->d;
                
                ht.w = 0;
                ht.h = hp->h;
                
                ht.d = -hp->d;
                
                if (bhCheckBox(&ht, pos, ar, ah, 3) != 0) 
                {
                    *ay = -*ay;
                    break;
                }
                
                ht.px = hp->px + hp->w;
                ht.pz = hp->pz - zero;
                
                ht.w = -hp->w;
                ht.h = hp->h;
                
                ht.d = 0;
                
                if (bhCheckBox(&ht, pos, ar, ah, 5) != 0) 
                {
                    *ay = -*ay;
                }
            }
        }
        
        break;
    case 6:
        switch (hp->id) 
        {
        case 0:
            py = hp->py + ((hp->h / hp->w) * (pos->x - hp->px));
            break;
        case 1:
            py = hp->h + (hp->py + ((hp->h / hp->d) * (hp->pz - pos->z)));
            break;
        case 2:
            py = hp->py + ((hp->h / hp->d) * (pos->z - hp->pz));
            break;
        case 3:
            py = hp->h + (hp->py + ((hp->h / hp->w) * (hp->px - pos->x)));
            break;
        }
        
        if (pos->y < py) 
        {
            aby = fabsf(pos->y - py);
            
            wpx = hp->px + (0.5f * hp->w);
            wpz = hp->pz + (0.5f * hp->d);
            
            px = hp->px - ar;
            pz = hp->pz - ar;
            
            xn = hp->w + (2.0f * ar);
            zn = hp->d + (2.0f * ar);
            
            if (pos->x < wpx) 
            {
                if (pos->z < wpz) 
                {
                    abx = fabsf(pos->x - px);
                    abz = fabsf(pos->z - pz);
                    
                    if (abx > abz) 
                    {
                        if (aby < abz) 
                        { 
                            pos->y = py; 
                        } 
                        else 
                        {
                            pos->z = pz;
                            
                            *ay = 32768 - *ay;
                        }
                    }
                    else if (aby < abx) 
                    { 
                        pos->y = py; 
                    } 
                    else 
                    {
                        pos->x = px;
                        
                        *ay = -*ay;
                    }
                } 
                else 
                {
                    abx = fabsf(pos->x - px);
                    abz = fabsf(pos->z - (pz + zn));
                    
                    if (abx > abz) 
                    {
                        if (aby < abz) 
                        { 
                            pos->y = py; 
                        } 
                        else 
                        {
                            pos->z = pz + zn;
                            
                            *ay = 32768 - *ay;
                        }
                    }
                    else if (aby < abx) 
                    { 
                        pos->y = py; 
                    } 
                    else 
                    {
                        pos->x = px;
                        
                        *ay = -*ay;
                    }
                }
            }
            else if (pos->z < wpz) 
            {
                abx = fabsf(pos->x - (px + xn));
                abz = fabsf(pos->z - pz);
                
                if (abx > abz) 
                {
                    if (aby < abz) 
                    { 
                        pos->y = py; 
                    } 
                    else 
                    {
                        pos->z = pz;
                        
                        *ay = 32768 - *ay;
                    }
                }
                else if (aby < abx) 
                { 
                    pos->y = py;
                }
                else 
                {
                    pos->x = px + xn;
                    
                    *ay = -*ay;
                }
            } 
            else 
            {
                abx = fabsf(pos->x - (px + xn));
                abz = fabsf(pos->z - (pz + zn));
                
                if (abx > abz)
                {
                    if (aby < abz)
                    { 
                        pos->y = py; 
                    } 
                    else 
                    {
                        pos->z = pz + zn;
                        
                        *ay = 32768 - *ay;
                    }
                }
                else if (aby < abx) 
                { 
                    pos->y = py; 
                }
                else 
                {
                    pos->x = px + xn;
                    
                    *ay = -*ay;
                }
            }
        }
        
        break;
    case 7:
        wpx = hp->px + (0.5f * hp->w);
        wpz = hp->pz + (0.5f * hp->d);
        
        px = hp->px - ar;
        pz = hp->pz - ar;
        
        xn = hp->w + (2.0f * ar);
        zn = hp->d + (2.0f * ar);
        
        aby = fabsf(pos->y - hp->py);
        
        if (pos->x < wpx) 
        {
            if (pos->z < wpz) 
            {
                abx = fabsf(pos->x - px);
                abz = fabsf(pos->z - pz);
                
                if (abx > abz) 
                {
                    if (aby < abz) 
                    {
                        pos->y = hp->py;
                    } 
                    else 
                    {
                        pos->z = pz;
                        
                        *ay = 32768 - *ay;
                    }
                }
                else if (aby < abx) 
                {
                    pos->y = hp->py;
                }
                else 
                {
                    pos->x = px;
                    
                    *ay = -*ay;
                }
            } 
            else 
            {
                abx = fabsf(pos->x - px);
                abz = fabsf(pos->z - (pz + zn));
                
                if (abx > abz) 
                {
                    if (aby < abz) 
                    {
                        pos->y = hp->py;
                    } 
                    else 
                    {
                        pos->z = pz + zn;
                        
                        *ay = 32768 - *ay;
                    }
                }
                else if (aby < abx) 
                {
                    pos->y = hp->py;
                } 
                else 
                {
                    pos->x = px;
                    
                    *ay = -*ay;
                }
            }
        }
        else if (pos->z < wpz) 
        {
            abx = fabsf(pos->x - (px + xn));
            abz = fabsf(pos->z - pz);
            
            if (abx > abz) 
            {
                if (aby < abz) 
                {
                    pos->y = hp->py;
                } 
                else 
                {
                    pos->z = pz;
                    
                    *ay = 32768 - *ay;
                }
            }
            else if (aby < abx) 
            { 
                pos->y = hp->py; 
            }
            else 
            {
                pos->x = px + xn;
                
                *ay = -*ay;
            }
        } 
        else 
        {
            abx = fabsf(pos->x - (px + xn));
            abz = fabsf(pos->z - (pz + zn));
            
            if (abx > abz) 
            {
                if (aby < abz) 
                {
                    pos->y = hp->py;
                } 
                else 
                {
                    pos->z = pz + zn;
                    
                    *ay = 32768 - *ay;
                }
            }
            else if (aby < abx) 
            {
                pos->y = hp->py;
            } 
            else 
            {
                pos->x = px + xn;
                
                *ay = -*ay;
            }
        }
        
        break;
    }
}

// 99.79% matching
float bhGetGroundPosition(NJS_POINT3* pos) 
{
    NJS_POINT3 pd; 
    ATR_WORK* hp;  
    int i;        
    int wal_n;     
    float px, pz;     
    float ln;    
    float h;     
    float yy;     
    float yn, nr;     

    sys->htp = NULL;
    
    yn = -1000.0f;
    nr = 10000.0f;
    
    wal_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < wal_n; i++)
    {
        if (i < rom->wal_n) 
        {
            hp = &rom->walp[i];
        } 
        else
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        if ((hp->flg & 0x1)) 
        {
            if (hp->h) 
            {
                h = hp->h;
            } 
            else 
            {
                h = rom->h;
            }
            
            switch (hp->type) 
            {                 
            case 0:                             
                yy = pos->y - (hp->py + h);
                
                if ((((pos->x - hp->px) >= 0) && ((pos->x - hp->px) < hp->w)) && (((pos->z - hp->pz) >= 0) && ((pos->z - hp->pz) < hp->d)) && ((yy >= 0) && (yy < nr)))  
                {
                    nr = yy;
                    yn = hp->py + h;
                    
                    sys->htp = hp;
                }
                
                break;
            case 2:                             
                yy = pos->y - (hp->py + h);
                
                px = hp->px - pos->x;
                pz = hp->pz - pos->z;
                
                if ((njSqrt((px * px) + (pz * pz)) < hp->w) && ((yy >= 0) && (yy < nr)))
                {
                    nr = yy;
                    yn = hp->py + h;
                    
                    sys->htp = hp;
                }
                
                break;
            case 4:                             
                yy = pos->y - (hp->py + h);
                
                pd.x = pos->x;
                pd.y = hp->py; 
                pd.z = pos->z;
                
                if ((bhCheckInnerTriangle3(hp, &pd) != 0) && ((yy >= 0) && (yy < nr))) 
                {
                    nr = yy;
                    yn = hp->py + h;
                    
                    sys->htp = hp;
                }
                
                break;
            case 6:                             
                yy = pos->y - hp->py;
                
                if ((((pos->x - hp->px) >= 0) && ((pos->x - hp->px) < hp->w)) && (((pos->z - hp->pz) >= 0) && ((pos->z - hp->pz) < hp->d)) && (yy >= 0)) 
                {
                    switch (hp->id)  
                    { 
                    case 0:         
                        ln = hp->py + ((hp->h / hp->w) * (pos->x - hp->px));
                        break;
                    case 1:         
                        ln = hp->h + (hp->py + ((hp->h / hp->d) * (hp->pz - pos->z)));
                        break;
                    case 2:         
                        ln = hp->py + ((hp->h / hp->d) * (pos->z - hp->pz));
                        break;
                    case 3:         
                        ln = hp->h + (hp->py + ((hp->h / hp->w) * (hp->px - pos->x)));
                        break;
                    }
                    
                    if ((pos->y - ln) < nr) 
                    {
                        nr = pos->y - ln;
                        yn = ln;
                        
                        sys->htp = hp;
                    }
                }
                
                break;
            case 7:                             
                yy = pos->y - hp->py;
                
                if ((yy <= 0) && (yy >= -0.0001f))
                {
                    yy = 0;
                }
                
                if ((((pos->x - hp->px) >= 0) && ((pos->x - hp->px) < hp->w)) && (((pos->z - hp->pz) >= 0) && ((pos->z - hp->pz) < hp->d)) && ((yy >= 0) && (yy < nr))) 
                {
                    nr = yy;
                    yn = hp->py;
                
                    sys->htp = hp;
                }
                
                break;
            }
        }
    }
    
    return yn;
}

// 100% matching!
int bhCheckInnerTriangle(ATR_WORK* hp, NJS_POINT3* pos, float ar, float ah) 
{
    NJS_POINT2 ps, pa, pb, pc, pd;     
    float px, pz;        
    float h, w, d;    // w and d are not from DWARF
    float minx, maxx; // not from DWARF
	float minz, maxz; // not from DWARF
    float abx, abz;   // not from DWARF
  
    if (hp->h) 
    {
        h = hp->h;
    } 
    else 
    {
        h = rom->h;
    }
    
    if ((hp->py > (pos->y + ah)) || ((hp->py + h) < pos->y)) 
    {
        return 0;
    } 
    
    w = hp->w;
    
    if (w > 0) 
    {
        minx = hp->px;
        maxx = ar + (minx + w);
    } 
    else 
    {
        maxx = hp->px;
        minx = (maxx + w) - ar;
    }
    
    d = hp->d;
    
    if (d > 0) 
    { 
        minz = hp->pz;
        maxz = ar + (minz + d);
    } 
    else 
    {
        maxz = hp->pz;
        minz = (maxz + d) - ar;
    }
    
    if (((minx > pos->x) || (maxx <= pos->x)) || ((minz > pos->z) || (maxz <= pos->z)))
    {
    	return 0;
	}
    
    if (!ar) 
    {
        abx = fabsf(d / (w / (pos->x - hp->px)));
        abz = fabsf((hp->pz + hp->d) - pos->z);
        
        if (abz <= abx) 
        {
            return 0;
        }
    }
    else 
    {
        px = hp->px;
        pz = hp->pz;
        
        ps.x = pos->x;
        ps.y = pos->z;
        
        switch (hp->id) 
        {                     
        case 0:
            pa.x = px + hp->w;
            pa.y = pz;
            
            pb.x = pa.x + ar;
            pb.y = pa.y + ar;
            
            pc.x = px;
            pc.y = pz + hp->d;
            
            pd.x = pc.x + ar;
            pd.y = pc.y + ar;
            
            if (bhCheckInnerP4(&ps, &pa, &pb, &pc, &pd) != 0) 
            {
                return 1;
            }
            
            px += ar;
            pz += ar;
            
            if ((px > pos->x) || (pz > pos->z)) 
            {
                return 0;
            }
            
            break;
        case 1:
            pa.x = px + ar;
            pa.y = (pz + hp->d) - ar;
            
            pb.x = pa.x - ar;
            pb.y = pa.y + ar;
            
            pc.x = ar + (px + hp->w);
            pc.y = pz - ar;
            
            pd.x = pc.x - ar;
            pd.y = pc.y + ar;
            
            if (bhCheckInnerP4(&ps, &pa, &pb, &pc, &pd) != 0) 
            {
                return 1;
            }
            
            px += ar;
            pz -= ar;
            
            if ((px > pos->x) || (pz <= pos->z)) 
            {
                return 0;
            }
            
            break;
        case 2:
            pa.x = px + hp->w;
            pa.y = pz;
            
            pb.x = pa.x - ar;
            pb.y = pa.y + ar;
            
            pc.x = px;
            pc.y = pz + hp->d;
            
            pd.x = pc.x - ar;
            pd.y = pc.y + ar;
            
            if (bhCheckInnerP4(&ps, &pa, &pb, &pc, &pd) != 0) 
            {
                return 1;
            }
            
            px -= ar;
            pz += ar;
            
            if ((px <= pos->x) || (pz > pos->z)) 
            {
                return 0;
            }
            
            break;
        case 3:
            pa.x = px - ar;
            pa.y = (pz + hp->d) - ar;
            
            pb.x = pa.x + ar;
            pb.y = pa.y + ar;
            
            pc.x = (px + hp->w) - ar;
            pc.y = pz - ar;
            
            pd.x = pc.x + ar;
            pd.y = pc.y + ar;
            
            if (bhCheckInnerP4(&ps, &pa, &pb, &pc, &pd) != 0) 
            {
                return 1;
            }
            
            px -= ar;
            pz -= ar;
            
            if ((px <= pos->x) || (pz <= pos->z)) 
            {
                return 0;
            }
            
            break;
        }
        
        abx = fabsf(d / (w / (pos->x - px)));
        abz = fabsf((pz + d) - pos->z);
        
        if (abz <= abx) 
        {
            return 0; 
        }
    }
    
    return 1;
}

// 100% matching!
int bhCheckInnerTriangle2(ATR_WORK* hp, NJS_POINT3* pos, float aw, float ad, float ah)
{
    NJS_POINT2 ps, pa, pb, pc, pd;     
    float px, pz;        
    float h, w, d;    // w and d are not from DWARF
    float minx, maxx; // not from DWARF
	float minz, maxz; // not from DWARF
    float abx, abz;   // not from DWARF
  
    if (hp->h) 
    {
        h = hp->h;
    } 
    else 
    {
        h = rom->h;
    }
    
    if ((hp->py > (pos->y + ah)) || ((hp->py + h) < pos->y)) 
    {
        return 0;
    } 
    
    w = hp->w;
    
    if (w > 0) 
    {
        minx = hp->px;
        maxx = aw + (minx + w);
    } 
    else 
    {
        maxx = hp->px;
        minx = (maxx + w) - aw;
    }
    
    d = hp->d;
    
    if (d > 0) 
    { 
        minz = hp->pz;
        maxz = ad + (minz + d);
    } 
    else 
    {
        maxz = hp->pz;
        minz = (maxz + d) - ad;
    }
    
    if (((minx > pos->x) || (maxx <= pos->x)) || ((minz > pos->z) || (maxz <= pos->z)))
    {
    	return 0;
	}
    
    if ((!aw) && (!ad)) 
    {
        abx = fabsf(d / (w / (pos->x - hp->px)));
        abz = fabsf((hp->pz + hp->d) - pos->z);
        
        if (abz <= abx) 
        {
            return 0;
        }
    }
    else 
    {
        px = hp->px;
        pz = hp->pz;
        
        ps.x = pos->x;
        ps.y = pos->z;
        
        switch (hp->id) 
        {                     
        case 0:
            pa.x = px + hp->w;
            pa.y = pz;
            
            pb.x = pa.x + aw;
            pb.y = pa.y + ad;
            
            pc.x = px;
            pc.y = pz + hp->d;
            
            pd.x = pc.x + aw;
            pd.y = pc.y + ad;
            
            if (bhCheckInnerP4(&ps, &pa, &pb, &pc, &pd) != 0) 
            {
                return 1;
            }
            
            px += aw;
            pz += ad;
            
            if ((px > pos->x) || (pz > pos->z)) 
            {
                return 0;
            }
            
            break;
        case 1:
            pa.x = px + aw;
            pa.y = (pz + hp->d) - ad;
            
            pb.x = pa.x - aw;
            pb.y = pa.y + ad;
            
            pc.x = aw + (px + hp->w);
            pc.y = pz - ad;
            
            pd.x = pc.x - aw;
            pd.y = pc.y + ad;
            
            if (bhCheckInnerP4(&ps, &pa, &pb, &pc, &pd) != 0) 
            {
                return 1;
            }
            
            px += aw;
            pz -= ad;
            
            if ((px > pos->x) || (pz <= pos->z)) 
            {
                return 0;
            }
            
            break;
        case 2:
            pa.x = px + hp->w;
            pa.y = pz;
            
            pb.x = pa.x - aw;
            pb.y = pa.y + ad;
            
            pc.x = px;
            pc.y = pz + hp->d;
            
            pd.x = pc.x - aw;
            pd.y = pc.y + ad;
            
            if (bhCheckInnerP4(&ps, &pa, &pb, &pc, &pd) != 0) 
            {
                return 1;
            }
            
            px -= aw;
            pz += ad;
            
            if ((px <= pos->x) || (pz > pos->z)) 
            {
                return 0;
            }
            
            break;
        case 3:
            pa.x = px - aw;
            pa.y = (pz + hp->d) - ad;
            
            pb.x = pa.x + aw;
            pb.y = pa.y + ad;
            
            pc.x = (px + hp->w) - aw;
            pc.y = pz - ad;
            
            pd.x = pc.x + aw;
            pd.y = pc.y + ad;
            
            if (bhCheckInnerP4(&ps, &pa, &pb, &pc, &pd) != 0) 
            {
                return 1;
            }
            
            px -= aw;
            pz -= ad;
            
            if ((px <= pos->x) || (pz <= pos->z)) 
            {
                return 0;
            }
            
            break;
        }
    
        abx = fabsf(d / (w / (pos->x - px)));
        abz = fabsf((pz + d) - pos->z);
        
        if (abz <= abx) 
        {
            return 0; 
        }
    }
    
    return 1;
}

// 100% matching!
int bhCheckInnerTriangle3(ATR_WORK* hp, NJS_POINT3* pos)
{
	float h;
	float min_x, max_x; // not from DWARF
	float min_z, max_z; // not from DWARF
	float abx; // not from DWARF
	float abz; // not from DWARF

	h = hp->h ? hp->h : rom->h;

	if (hp->py > pos->y || (hp->py + h) < pos->y) {
    	return 0;
	}

	if (hp->w > 0.0f) {
		max_x = hp->px + hp->w;
		min_x = hp->px;
	}
	else {
		min_x = hp->px + hp->w;
    	max_x = hp->px;
	}

	if (hp->d > 0.0f) {
		min_z = hp->pz;
		max_z = hp->pz + hp->d;
	}
	else {
		max_z = hp->pz;
		min_z = hp->pz + hp->d;
	}

	if (min_x > pos->x || max_x <= pos->x || min_z > pos->z || max_z <= pos->z) {
    	return 0;
	}

	abx = fabsf(hp->d / (hp->w / (pos->x - hp->px)));
	abz = fabsf((hp->pz + hp->d) - pos->z);
	if (abz <= abx) {
    	return 0;
	}

	return 1;
}

// 100% matching!
int bhCheckBox(ATR_WORK* hp, NJS_POINT3* pos, float ar, float ah, unsigned int aflg)
{
    float px, pz;  
    float xn, zn;  
    float ln;  
    float wpx, wpz; 
    float h;  
    float abx, abz; 
    int r;    
    
    if (hp->h) 
    {
        h = hp->h;
    } 
    else
    {
        h = rom->h;
    }
    
    wpx = hp->px + (0.5f * hp->w);
    wpz = hp->pz + (0.5f * hp->d);
    
    px = hp->px - ar;
    pz = hp->pz - ar;
    
    xn = hp->w + (2.0f * ar);
    zn = hp->d + (2.0f * ar); 
    
    if ((((pos->x - px) >= 0) && ((pos->x - px) < xn)) && (((pos->z - pz) >= 0) && ((pos->z - pz) < zn)) && (((pos->y + ah) >= hp->py) && (pos->y <= (hp->py + h))))  
    {
        if (pos->x < wpx)
        {
            if (pos->z < wpz) 
            {
                abx = fabsf(pos->x - px);
                abz = fabsf(pos->z - pz);
                
                if (((abx < ar) && (abz < ar)) && (!(aflg & 0x1))) 
                {
                    px = hp->px - pos->x;
                    pz = hp->pz - pos->z;
                    
                    ln = njSqrt((px * px) + (pz * pz));
                    
                    if (ln <= ar) 
                    {
                        r = 10430.381f * atan2f(px, pz);
                        
                        njSinCos(r, &pos->x, &pos->z);
                        
                        pos->x = hp->px - (pos->x * ar); 
                        pos->z = hp->pz - (pos->z * ar);
                        
                        return 1;
                    }
                    
                    return 0;
                }
                
                if (abx > abz) 
                {
                    pos->z = pz;
                } 
                else
                {
                    pos->x = px;
                }
                
                return 1;
            }
            
            abx = fabsf(pos->x - px);
            abz = fabsf(pos->z - (pz + zn));
            
            if (((abx < ar) && (abz < ar)) && (!(aflg & 0x2))) 
            {
                px = hp->px - pos->x;
                pz = (hp->pz + hp->d) - pos->z;
                
                ln = njSqrt((px * px) + (pz * pz));
                
                if (ln <= ar) 
                {
                    r = 10430.381f * atan2f(px, pz);
                    
                    njSinCos(r, &pos->x, &pos->z);
                    
                    pos->x = hp->px - (pos->x * ar);
                    pos->z = (hp->pz + hp->d) - (pos->z * ar);
                    
                    return 1;
                }
                
                return 0;
            }
            
            if (abx > abz) 
            {
                pos->z = pz + zn;
            } 
            else 
            {
                pos->x = px;
            }
            
            return 1;
        }
        
        if (pos->z < wpz)
        {
            abx = fabsf(pos->x - (px + xn));
            abz = fabsf(pos->z - pz);
            
            if (((abx < ar) && (abz < ar)) && (!(aflg & 0x4))) 
            {
                px = (hp->px + hp->w) - pos->x;
                pz = hp->pz - pos->z;
                
                ln = njSqrt((px * px) + (pz * pz));
                
                if (ln <= ar)
                {
                    r = 10430.381f * atan2f(px, pz);
                    
                    njSinCos(r, &pos->x, &pos->z);
                    
                    pos->x = (hp->px + hp->w) - (pos->x * ar);
                    pos->z = hp->pz - (pos->z * ar);
                    
                    return 1;
                }
                
                return 0;
            }
            
            if (abx > abz) 
            {
                pos->z = pz;
            }
            else
            {
                pos->x = px + xn;
            }
            
            return 1;
        }
        
        abx = fabsf(pos->x - (px + xn));
        abz = fabsf(pos->z - (pz + zn));
        
        if (((abx < ar) && (abz < ar)) && (!(aflg & 0x8))) 
        {
            px = (hp->px + hp->w) - pos->x;
            pz = (hp->pz + hp->d) - pos->z; 
            
            ln = njSqrt((px * px) + (pz * pz));
            
            if (ln <= ar) 
            {
                r = 10430.381f * atan2f(px, pz);
                
                njSinCos(r, &pos->x, &pos->z);
                
                pos->x = (hp->px + hp->w) - (pos->x * ar); 
                pos->z = (hp->pz + hp->d) - (pos->z * ar); 
                
                return 1; 
            }
            
            return 0;
        }
        
        if (abx > abz) 
        {
            pos->z = pz + zn;
        } 
        else
        {
            pos->x = px + xn;
        }
        
        return 1;
    }
    
    return 0;
}

// 100% matching!
int bhCheckBox2Box(ATR_WORK* hp, NJS_POINT3* pos, float aw, float ad, float ah)
{
    float px, pz;  
    float xn, zn;  
    float wpx, wpz; 
    float h;   
    float abx, abz; 

    if (hp->h)
    {
        h = hp->h;
    } 
    else 
    {
        h = rom->h;
    }
    
    wpx = hp->px + (0.5f * hp->w);
    wpz = hp->pz + (0.5f * hp->d);
    
    px = hp->px - aw;
    pz = hp->pz - ad;
    
    xn = hp->w + (2.0f * aw);
    zn = hp->d + (2.0f * ad);
    
    if ((((pos->x - px) >= 0) && ((pos->x - px) < xn)) && (((pos->z - pz) >= 0) && ((pos->z - pz) < zn)) && (((pos->y + ah) >= hp->py) && (pos->y <= (hp->py + h))))
    {
        if (pos->x < wpx) 
        {
            if (pos->z < wpz)
            {
                abx = fabsf(pos->x - px);
                abz = fabsf(pos->z - pz);
                
                if (abx > abz)
                {
                    pos->z = pz;
                } 
                else 
                {
                    pos->x = px;
                }
                
                return 1;
            }
            
            abx = fabsf(pos->x - px);
            abz = fabsf(pos->z - (pz + zn));
            
            if (abx > abz)
            {
                pos->z = pz + zn;
            }
            else
            {
                pos->x = px;
            }
            
            return 1;
        }
        
        if (pos->z < wpz) 
        {
            abx = fabsf(pos->x - (px + xn));
            abz = fabsf(pos->z - pz);
            
            if (abx > abz)
            {
                pos->z = pz;
            } 
            else
            {
                pos->x = px + xn;
            }
            
            return 1;
        }
        
        abx = fabsf(pos->x - (px + xn));
        abz = fabsf(pos->z - (pz + zn));
        
        if (abx > abz) 
        {
            pos->z = pz + zn;
        } 
        else 
        {
            pos->x = px + xn;
        }
        
        return 1;
    } 
    
    return 0;
}

// 
// Start address: 0x265e10
int bhCheckInnerP4(NJS_POINT2* pos, NJS_POINT2* p0, NJS_POINT2* p1, NJS_POINT2* p2, NJS_POINT2* p3)
{
	float y3;
	float y2;
	float y1;
	float y0;
	float x1;
	float x0;
	float nn;
	float swp;
	float max;
	float min;
	// Line 3509, Address: 0x265e10, Func Offset: 0
	// Line 3510, Address: 0x265e48, Func Offset: 0x38
	// Line 3512, Address: 0x265e50, Func Offset: 0x40
	// Line 3513, Address: 0x265e54, Func Offset: 0x44
	// Line 3511, Address: 0x265e58, Func Offset: 0x48
	// Line 3510, Address: 0x265e64, Func Offset: 0x54
	// Line 3512, Address: 0x265e68, Func Offset: 0x58
	// Line 3513, Address: 0x265e6c, Func Offset: 0x5c
	// Line 3514, Address: 0x265e70, Func Offset: 0x60
	// Line 3516, Address: 0x265e74, Func Offset: 0x64
	// Line 3517, Address: 0x265e84, Func Offset: 0x74
	// Line 3518, Address: 0x265ea0, Func Offset: 0x90
	// Line 3519, Address: 0x265ecc, Func Offset: 0xbc
	// Line 3520, Address: 0x265ed4, Func Offset: 0xc4
	// Line 3521, Address: 0x265ef0, Func Offset: 0xe0
	// Line 3523, Address: 0x265f14, Func Offset: 0x104
	// Line 3524, Address: 0x265f24, Func Offset: 0x114
	// Line 3525, Address: 0x265f2c, Func Offset: 0x11c
	// Line 3524, Address: 0x265f30, Func Offset: 0x120
	// Line 3525, Address: 0x265f34, Func Offset: 0x124
	// Line 3526, Address: 0x265f38, Func Offset: 0x128
	// Line 3527, Address: 0x265f48, Func Offset: 0x138
	// Line 3528, Address: 0x265f4c, Func Offset: 0x13c
	// Line 3529, Address: 0x265f50, Func Offset: 0x140
	// Line 3531, Address: 0x265f54, Func Offset: 0x144
	// Line 3533, Address: 0x265f84, Func Offset: 0x174
	// Line 3534, Address: 0x265f94, Func Offset: 0x184
	// Line 3535, Address: 0x265fac, Func Offset: 0x19c
	// Line 3537, Address: 0x265fd4, Func Offset: 0x1c4
	// Line 3538, Address: 0x265fd8, Func Offset: 0x1c8
	// Line 3537, Address: 0x265fdc, Func Offset: 0x1cc
	// Line 3538, Address: 0x265fe0, Func Offset: 0x1d0
	// Line 3537, Address: 0x265fe4, Func Offset: 0x1d4
	// Line 3538, Address: 0x265fe8, Func Offset: 0x1d8
	// Line 3539, Address: 0x265fec, Func Offset: 0x1dc
	// Line 3540, Address: 0x265ffc, Func Offset: 0x1ec
	// Line 3541, Address: 0x266000, Func Offset: 0x1f0
	// Line 3542, Address: 0x266004, Func Offset: 0x1f4
	// Line 3544, Address: 0x266008, Func Offset: 0x1f8
	// Line 3546, Address: 0x266038, Func Offset: 0x228
	// Line 3548, Address: 0x266060, Func Offset: 0x250
	// Line 3549, Address: 0x266064, Func Offset: 0x254
	// Line 3548, Address: 0x266068, Func Offset: 0x258
	// Line 3549, Address: 0x26606c, Func Offset: 0x25c
	// Line 3548, Address: 0x266070, Func Offset: 0x260
	// Line 3549, Address: 0x266074, Func Offset: 0x264
	// Line 3550, Address: 0x266078, Func Offset: 0x268
	// Line 3551, Address: 0x266088, Func Offset: 0x278
	// Line 3552, Address: 0x26608c, Func Offset: 0x27c
	// Line 3553, Address: 0x266090, Func Offset: 0x280
	// Line 3555, Address: 0x266094, Func Offset: 0x284
	// Line 3558, Address: 0x2660c4, Func Offset: 0x2b4
	// Line 3559, Address: 0x2660dc, Func Offset: 0x2cc
	// Line 3561, Address: 0x266104, Func Offset: 0x2f4
	// Line 3563, Address: 0x266138, Func Offset: 0x328
	// Line 3564, Address: 0x26613c, Func Offset: 0x32c
	// Line 3563, Address: 0x266140, Func Offset: 0x330
	// Line 3564, Address: 0x266148, Func Offset: 0x338
	// Line 3563, Address: 0x26614c, Func Offset: 0x33c
	// Line 3564, Address: 0x266150, Func Offset: 0x340
	// Line 3565, Address: 0x266154, Func Offset: 0x344
	// Line 3566, Address: 0x266164, Func Offset: 0x354
	// Line 3567, Address: 0x266168, Func Offset: 0x358
	// Line 3568, Address: 0x26616c, Func Offset: 0x35c
	// Line 3570, Address: 0x266170, Func Offset: 0x360
	// Line 3572, Address: 0x2661a0, Func Offset: 0x390
	// Line 3574, Address: 0x2661c8, Func Offset: 0x3b8
	// Line 3576, Address: 0x2661fc, Func Offset: 0x3ec
	// Line 3577, Address: 0x266200, Func Offset: 0x3f0
	// Line 3576, Address: 0x266208, Func Offset: 0x3f8
	// Line 3577, Address: 0x26620c, Func Offset: 0x3fc
	// Line 3576, Address: 0x266210, Func Offset: 0x400
	// Line 3577, Address: 0x266214, Func Offset: 0x404
	// Line 3578, Address: 0x266218, Func Offset: 0x408
	// Line 3579, Address: 0x266228, Func Offset: 0x418
	// Line 3580, Address: 0x26622c, Func Offset: 0x41c
	// Line 3581, Address: 0x266230, Func Offset: 0x420
	// Line 3583, Address: 0x266234, Func Offset: 0x424
	// Line 3587, Address: 0x266264, Func Offset: 0x454
	// Line 3588, Address: 0x266268, Func Offset: 0x458
	// Func End, Address: 0x266270, Func Offset: 0x460
	scePrintf("bhCheckInnerP4 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhCheckExmAtari(BH_PWORK* pp)
{
    NJS_POINT3 ps; 
    ATR_WORK* exp; 
    ATR_WORK* ckp; 
    O_WRK* op;   
    float px, pz;      
    float pxx, pzz;    
    float pxn[5], pzn[5];  
    int i;      
    int etc_n;   
    int danf;    
    int ang;     
    
    njSinCos(pp->ay, &px, &pz);
    
    danf = 0;
    
    pxn[0] = ((EXP_WORK*)plp->exp0)->fpx - (px * (1.5f + (3.0f - ((EXP_WORK*)plp->exp0)->arn)));
    pzn[0] = ((EXP_WORK*)plp->exp0)->fpz - (pz * (1.5f + (3.0f - ((EXP_WORK*)plp->exp0)->arn)));
    
    pxn[1] = plp->px - (0.75f * px);
    pzn[1] = plp->pz - (0.75f * pz);
    
    pxn[2] = plp->px - (4.5f * px);
    pzn[2] = plp->pz - (4.5f * pz); 
    
    pxn[3] = ((EXP_WORK*)plp->exp0)->fpx - (px * (3.0f + (3.0f - ((EXP_WORK*)plp->exp0)->arn)));
    pzn[3] = ((EXP_WORK*)plp->exp0)->fpz - (pz * (3.0f + (3.0f - ((EXP_WORK*)plp->exp0)->arn)));
    
    pxn[4] = plp->px - (2.0f * px);
    pzn[4] = plp->pz - (2.0f * pz);
    
    sys->cb_flg &= ~0x100;
    
    etc_n = rom->etc_n + sys->metc_n;
    
    for (i = 0; i < etc_n; i++)
    {
        if (i < rom->etc_n) 
        {
            exp = &rom->etcp[i];
        } 
        else
        {
            exp = &sys->metcp[i - rom->etc_n];
        }
        
        if ((exp->flg & 0x1)) 
        {
            px = pxn[exp->type];
            pz = pzn[exp->type];
            
            if (((exp->px <= px) && ((exp->px + exp->w) >= px)) && ((exp->pz <= pz) && ((exp->pz + exp->d) >= pz)) && (exp->flr_no == pp->flr_no)) 
            {
                sys->cb_flg |= 0x100;
                
                sys->etc_idx = i;
                
                switch (exp->type) 
                {       
                case 0:                                 
                    ang = pp->ay + 8192;
                    
                    if ((((ang & 0xC000) == 0x8000) && ((exp->attr & 0x400))) || (((ang & 0xC000) == 0x4000) && ((exp->attr & 0x800))) || ((!(ang & 0xC000)) && ((exp->attr & 0x1000))) || (((ang & 0xC000) == 0xC000) && ((exp->attr & 0x2000)))) 
                    {
                        sys->cb_flg &= ~0x100;
                        break;
                    }
                    
                    if ((!(sys->gm_flg & 0x1)) && (!(sys->gm_flg & 0x8))) 
                    {
                        pp->stflg |= 0x80000000;
                        
                        sys->cb_flg |= 0x1;
                        sys->st_flg |= 0x4;
                        
                        sys->ddmd = 0;
                        
                        sys->door.flg = (unsigned short)exp->attr; 
                        
                        sys->door.stg_no = exp->prm0;
                        sys->door.rom_no = exp->prm1;
                        sys->door.pos_no = exp->prm2;
                    
                        sys->door.dor_tp = exp->prm3;
                    } 
                    
                    return;
                case 1:                                 
                    if ((!(pp->stflg & 0x10)) && (!(exp->attr & 0x400000))) 
                    {
                        bhSetUseKaidanFlag(pp, exp, i);
                        
                        pp->stflg |= 0x80010010;
                        
                        pp->flg |=  0x10400;
                        pp->flg &= ~0x110;
                        
                        sys->st_flg |= 0x4;
                        
                        sys->pl_htp = exp;
                        
                        if (exp->prm0 == 0) 
                        {
                            pp->mode0 = 1;
                            pp->mode1 = 0;
                            
                            if ((exp->attr & 0x1))
                            {
                                pp->mode2 = 20;
                            }
                            else 
                            {
                                pp->mode2 = 14;
                            }
                            
                            pp->mode3 = 0;
                        } 
                        else
                        {
                            pp->mode0 = 1;
                            pp->mode1 = 0;
                            
                            if ((exp->attr & 0x1))
                            {
                                pp->mode2 = 21;
                            }
                            else
                            {
                                pp->mode2 = 15;
                            }
                            
                            pp->mode3 = 0;
                            
                            pp->flr_no = bhCheckFloorNum(pp->py - (2.0f * exp->prm2));
                        }
                    }
                    
                    return;
                case 2:                                 
                    if ((!(pp->stflg & 0x20)) && (exp->prm0 == 0)) 
                    {
                        pp->ayp = (pp->ay + 8192) & ~0x3FFF;
                        
                        njSinCos(pp->ayp, &pxx, &pzz);
                        
                        pxx = plp->px - (6.0f * pxx);
                        pzz = plp->pz - (6.0f * pzz);
                        
                        if ((((1.0f + exp->px) <= pxx) && (((exp->px + exp->w) - 1.0f) >= pxx)) && (((1.0f + exp->pz) <= pzz) && (((exp->pz + exp->d) - 1.0f) >= pzz)))
                        {
                            njSinCos(pp->ayp, &ps.x, &ps.z), 
                                
                            ps.x = plp->px - (ps.x * (2.0f + pp->ar));
                            ps.y = 9.1f + plp->py;
                            ps.z = plp->pz - (ps.z * (2.0f + pp->ar)); 
                            
                            ckp = bhCheckWallType(&ps, pp->flg, pp->ar, pp->ah); 
                            
                            if ((ckp == NULL) || ((ckp->attr & 0x4))) 
                            {
                                pp->stflg |= 0x80010020;
                                
                                pp->flg |=  0x10400;
                                pp->flg &= ~0x110;
                                
                                sys->st_flg |= 0x4;
                                
                                sys->pl_htp = exp;
                                
                                pp->mode0 = 1;
                                pp->mode1 = 0;
                                pp->mode2 = 16;
                                pp->mode3 = 0;
                                return;
                            }
                        }
                    }
                    else
                    {
                        if ((!(pp->stflg & 0x20)) && (exp->prm0 != 0)) 
                        {
                            danf = 1;
                        }
                        
                        break;
                    }
                    
                    return;
                case 3:                                 
                    ang = pp->ay + 8192;
                    
                    if ((((ang & 0xC000) == 0x8000) && ((exp->attr & 0x400))) || (((ang & 0xC000) == 0x4000) && ((exp->attr & 0x800))) || ((!(ang & 0xC000)) && ((exp->attr & 0x1000))) || (((ang & 0xC000) == 0xC000) && ((exp->attr & 0x2000)))) 
                    {
                        sys->cb_flg &= ~0x100;
                        break;
                    }
                    
                    if (!(sys->st_flg & 0x80))
                    {
                        if ((exp->attr & 0x9))
                        {
                            sys->fixcno = exp->prm0;
                            sys->fixkno = exp->prm2;
                            
                            sys->exm_attr = exp->attr;
                            
                            sys->pad_onb  = sys->pad_on;
                            sys->pad_psb  = sys->pad_ps;
                            sys->pad_oldb = sys->pad_old;
                            
                            sys->pad_ps = 0;
                            
                            sys->gm_flg |= 0x1000;
                            
                            if ((exp->attr & 0x8)) 
                            {
                                sys->gm_flg |=  0x10000;
                            }
                            else 
                            {
                                sys->gm_flg &= ~0x10000;
                            }
                            
                            sys->st_flg |= 0x80;
                            
                            sys->cb_flg |= 0x8;
                            
                            sys->st_flg |= 0x4;
                            
                            if ((cam.flg & 0x20)) 
                            {
                                sys->ef_flg |= 0x10;
                            }
                        }
                        
                        if ((exp->attr & 0x8000)) 
                        {
                            bhSetMessage(0, exp->prm1);
                            
                            if (!(exp->attr & 0x9)) 
                            {
                                sys->pad_onb  = sys->pad_on;
                                sys->pad_psb  = sys->pad_ps;
                                sys->pad_oldb = sys->pad_old;
                                
                                sys->pad_ps = 0;
                            }
                            
                            sys->cb_flg |= 0x20;
                            
                            sys->st_flg |= 0x2000;
                            sys->st_flg |= 0x4;
                            
                        }
                    }
                    
                    return;
                case 4:                                 
                    ang = pp->ay + 8192;
                    
                    if ((((ang & 0xC000) == 0x8000) && ((exp->attr & 0x400))) || (((ang & 0xC000) == 0x4000) && ((exp->attr & 0x800))) || ((!(ang & 0xC000)) && ((exp->attr & 0x1000))) || (((ang & 0xC000) == 0xC000) && ((exp->attr & 0x2000)))) 
                    {
                        sys->cb_flg &= ~0x100;
                        break;
                    }
                    
                    if (!(exp->attr & 0x2)) 
                    {
                        if ((exp->attr & 0x10))
                        {
                            sys->cb_flg |= 0x20000;
                        }
                        
                        op = &sys->itwp[exp->prm0];
                        
                        if ((op->flg & 0x1)) 
                        {
                            sys->sb_id = op->id;
                            
                            if ((exp->attr & 0x1))
                            {
                                pp->flg |= 0x10000;
                                
                                pp->stflg   |= 0x10000;
                                sys->st_flg |= 0x4;
                                
                                pp->mode0 = 1;
                                pp->mode1 = 0;
                                pp->mode2 = 19;
                                pp->mode3 = 0;
                            } 
                            else
                            {
                                sys->st_flg &= ~0x4;
                                
                                sys->cb_flg |= 0x10;
                            }
                            
                            return;
                        }
                    }
                    else if ((exp->attr & 0xC))
                    {
                        if ((exp->attr & 0x4)) 
                        {
                            sys->cb_flg |= 0x80000;
                        } 
                        else 
                        {
                            sys->cb_flg |= 0x100000;
                        }
                    }
                    
                    if (exp->prm0 == 0xFF)
                    {
                        sys->cb_flg |= 0x40000;
                    } 
                    else
                    {
                        op = &sys->obwp[exp->prm0];
                        
                        if ((op->flg & 0x1)) 
                        {
                            op->type = 100;
                            
                            *(int*)&op->mode0 = 0; 
                            
                            pp->flg |= 0x10000;
                            
                            pp->stflg   |= 0x18000;
                            sys->st_flg |= 0x4;
                            
                            pp->mode0 = 1;
                            pp->mode1 = 0;
                            pp->mode2 = 0;
                            pp->mode3 = 0;
                        } 
                    }
                    
                    return;
                }
            }
        } 
    } 
    
    if (((!(pp->stflg & 0x20)) && ((pp->stflg & 0x20000))) && (danf == 0)) 
    {
        pp->ayp = (pp->ay + 8192) & ~0x3FFF;
        
        njSinCos(pp->ayp, &ps.x, &ps.z);
        
        ps.x = plp->px - (ps.x * (3.0f + pp->ar));
        ps.y = plp->py - 8.9f;
        ps.z = plp->pz - (ps.z * (3.0f + pp->ar)); 
        
        ckp = bhCheckWallType(&ps, pp->flg, pp->ar, pp->ah);
        
        if ((ckp == NULL) || ((ckp->attr & 0x4))) 
        {
            pp->stflg |= 0x80010020;
            
            pp->flg |=  0x10400;
            pp->flg &= ~0x110;
            
            sys->st_flg |= 0x4;
            
            pp->mode0 = 1;
            pp->mode1 = 0;
            pp->mode2 = 17;
            pp->mode3 = 0;
        }
    }
}

// 100% matching!
void bhSetUseKaidanFlag(BH_PWORK* pp, ATR_WORK* exp, int idx)
{
    ATR_WORK* exp2;
    
    pp->kdnp   = &exp->flg;
    pp->kdnidx = idx;
    
    exp->attr |= 0x400000;
    
    if (exp->prm3 == 0xFF) 
    {
        if (idx < rom->etc_n)
        {
            exp2 = &rom->etcp[idx];
        } 
        else 
        {
            exp2 = &sys->metcp[idx - rom->etc_n];
        }
        
        if (exp->prm0 == 0) 
        {
            exp2++;
        } 
        else 
        {
            exp2--;
        }
        
        exp2->attr |= 0x400000;
    }
    else 
    {
        exp2 = &rom->etcp[exp->prm3];
        
        exp2->attr |= 0x400000;
    }
}

// 100% matching!
void bhClrUseKaidanFlag(BH_PWORK* pp) 
{
    ATR_WORK* exp, *exp2;
    int idx;
	
    exp = (ATR_WORK*)pp->kdnp;
    
    if (exp != NULL) 
    {
        idx = pp->kdnidx;
        
        exp->attr &= ~0x400000;
        
        if (exp->prm3 == 0xFF) 
        {
            if (idx < rom->etc_n) 
            {
                exp2 = &rom->etcp[idx];
            } 
            else 
            {
                exp2 = &sys->metcp[idx - rom->etc_n];
            }
            
            if (exp->prm0 == 0)
            {
                exp2++;
            } 
            else 
            {
                exp2--;
            }
            
            exp2->attr &= ~0x400000;
        }
        else
        {
            exp = &rom->etcp[exp->prm3];
            
            exp->attr &= ~0x400000;
        }
    }
}

// 99.21% matching
void bhSetDansaLimitAtari(BH_PWORK* pp) 
{
    // modified order of local variables in regards to DWARF
    ATR_WORK* hp;  
    ATR_WORK* exp; 
    ATR_WORK* pop; 
    float px1;      
    float pz2;      
    float px3;      
    float tmp; // not from DWARF 
    float arh;      
    float px0;      
    float pz0;      
    int i;          
    int etc_n;      
    float pz1; // not from DWARF       

    sys->dla_n = 0;
    
    px0 = pp->px;
    pz0 = pp->pz;
    
    arh = pp->ar;
    
    pz1 = pz0 - arh;
    px1 = px0 + arh;
    pz2 = pz0 + arh;
    px3 = px0 - arh;
    
    tmp = 0.5f * arh;
    
    pop = NULL;
    
    etc_n = rom->etc_n + sys->metc_n;
    
    for (i = 0; i < etc_n; i++) 
    {
        if (i < rom->etc_n) 
        {
            exp = &rom->etcp[i];
        } 
        else 
        {
            exp = &sys->metcp[i - rom->etc_n];
        }
        
        if (((exp->flg & 0x1)) && (exp->type == 2) && (exp->prm0 != 0) && (exp->flr_no == pp->flr_no) && ((exp->px <= px0) && ((exp->px + exp->w) >= px0)) && ((exp->pz <= pz0) && ((exp->pz + exp->d) >= pz0))) 
        {
            pop = exp;
            break; 
        } 
    }
    
    if (pop == NULL) 
    {
        pop = pp->dan_ap;
    } 
    else 
    {
        pp->dan_ap = pop;
    }
    
    if (pop == NULL) 
    {
        pp->stflg &= ~0x20000;
        return;
    }
    
    if (bhCheckDansaAtari(pp->flr_no, px0, pz1) == NULL) 
    {
        sys->dla_n++;
        
        hp = &sys->mwalp[sys->mwal_n++];
        
        hp->flg  = 1;
        hp->type = 1;
        
        hp->flr_no = pp->flr_no;
        
        hp->attr = 0x800000;
        
        hp->px = pop->px - (2.0f * arh);
        hp->py = pop->py;
        hp->pz = pop->pz - ((2.0f * arh) + tmp);
        
        hp->w = pop->w + (4.0f * arh);
        hp->h = 1.0f;
        hp->d = 2.0f * arh;
        
        hp->prm0 = hp->prm1 = hp->prm2 = hp->prm3 = 0;
    }
    
    if (bhCheckDansaAtari(pp->flr_no, px1, pz0) == NULL)
    {
        sys->dla_n++;
        
        hp = &sys->mwalp[sys->mwal_n++];
        
        hp->flg  = 1;
        hp->type = 1;
        
        hp->flr_no = pp->flr_no;
        
        hp->attr = 0x800000;
        
        hp->px = tmp + (pop->px + pop->w);
        hp->py = pop->py;
        hp->pz = pop->pz - (2.0f * arh);
        
        hp->w = 2.0f * arh;
        hp->h = 1.0f;
        hp->d = pop->d + (4.0f * arh);
        
        hp->prm0 = hp->prm1 = hp->prm2 = hp->prm3 = 0;
    }
    
    if (bhCheckDansaAtari(pp->flr_no, px0, pz2) == NULL)
    {
        sys->dla_n++;
        
        hp = &sys->mwalp[sys->mwal_n++];
        
        hp->flg  = 1;
        hp->type = 1;
        
        hp->flr_no = pp->flr_no;
        
        hp->attr = 0x800000;
        
        hp->px = pop->px - (2.0f * arh);
        hp->py = pop->py;
        hp->pz = tmp + (pop->pz + pop->d);
        
        hp->w = pop->w + (4.0f * arh);
        hp->h = 1.0f;
        hp->d = 2.0f * arh;
        
        hp->prm0 = hp->prm1 = hp->prm2 = hp->prm3 = 0;
    }
    
    if (bhCheckDansaAtari(pp->flr_no, px3, pz0) == NULL) 
    {
        sys->dla_n++;
        
        hp = &sys->mwalp[sys->mwal_n++];
        
        hp->flg  = 1;
        hp->type = 1;
        
        hp->flr_no = pp->flr_no;
        
        hp->attr = 0x800000;
        
        hp->px = pop->px - ((2.0f * arh) + tmp);
        hp->py = pop->py;
        hp->pz = pop->pz - (2.0f * arh);
        
        hp->w = 2.0f * arh;
        hp->h = 1.0f;
        hp->d = pop->d + (4.0f * arh);
        
        hp->prm0 = hp->prm1 = hp->prm2 = hp->prm3 = 0;
    }
}

// 100% matching! 
ATR_WORK* bhCheckDansaAtari(int flr_no, float px, float pz)
{
    ATR_WORK* exp; 
    int i;        
    int etc_n;     
    
    etc_n = rom->etc_n + sys->metc_n;
    
    for (i = 0; i < etc_n; i++) 
    {
        if (i < rom->etc_n) 
        {
            exp = rom->etcp + i;
        } 
        else 
        {
            exp = &sys->metcp[i - rom->etc_n];
        }
        
        if (((exp->flg & 0x1)) && (exp->type == 2) && (exp->prm0 != 0) && (((exp->px <= px) && ((exp->px + exp->w) >= px)) && ((exp->pz <= pz) && ((exp->pz + exp->d) >= pz))) && (exp->flr_no == flr_no)) 
        {
            return exp;
        }
    }
    
    return NULL;
}

// 100% matching!
void bhCheckFloorP(BH_PWORK* pp) 
{
    ATR_WORK* fp; 
    float px, py, pz;    
    float spx, spz;    
    float* dp;   
    int i;        
    int flr_n;   
    int ang;     
  
    px = pp->px;
    py = pp->py;
    pz = pp->pz;
    
    njSinCos(pp->ay, &spx, &spz);
    
    dp = (float*)plp->exp0;
    spx = dp[9] - (spx * (3.0f + (3.0f - dp[7])));
    
    dp = (float*)plp->exp0;
    spz = dp[11] - (spz * (3.0f + (3.0f - dp[7])));
    
    pp->stflg &= ~0x100000;
    pp->flg2  &= ~0x8;
    
    sys->cb_flg &= ~0x8000200;
    
    flr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < flr_n; i++)
    {
        if (i < rom->flr_n) 
        {
            fp = &rom->flrp[i];
        } 
        else 
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if ((fp->flg & 0x1)) 
        {
            if ((fp->type == 0) && ((fp->attr & 0x1))) 
            {
                if ((((fp->px <= spx) && ((fp->px + fp->w) >= spx)) && ((fp->pz <= spz) && ((fp->pz + fp->d) >= spz)) && (fp->flr_no == pp->flr_no)) && ((!(plp->flg & 0x4)) && (!(plp->flg & 0x2)))) 
                {
                    ang = (pp->ay + 8192) & 0xC000; 
                    
                    if ((((ang == 32768) == 0) || (!(fp->attr & 0x400))) && ((ang != 16384) || (!(fp->attr & 0x800))) && ((ang != 0) || (!(fp->attr & 0x1000))) && ((ang != 49152) || (!(fp->attr & 0x2000)))) 
                    {
                        sys->cb_flg |= 0x200;
                        
                        sys->flr_idx = i; 
                    }
                }
            } 
            else 
            {
                if (((fp->px <= px) && ((fp->px + fp->w) >= px)) && ((fp->py <= py) && ((fp->py + fp->h) >= py)) && ((fp->pz <= pz) && ((fp->pz + fp->d) >= pz))) 
                {
                    switch ((unsigned short)fp->type) 
                    { 
                    case 0:         
                        if ((!(plp->flg & 0x4)) && (!(plp->flg & 0x2)))
                        {
                            ang = (pp->ay + 8192) & 0xC000; 
                            
                            if (((ang != 32768) || (!(fp->attr & 0x400))) && ((ang != 16384) || (!(fp->attr & 0x800))) && ((ang != 0) || (!(fp->attr & 0x1000))) && ((ang != 49152) || (!(fp->attr & 0x2000))))
                            {
                                sys->cb_flg |= 0x200;
                                
                                sys->flr_idx = i; 
                            }
                        } 
                        
                        break;
                    case 1:             
                        if ((!(fp->attr & 0x1)) || ((pp->stflg & 0x10)))
                        {
                            pp->flr_snd = fp->prm0;
                        } 
                        
                        break;
                    case 3:        
                        switch (fp->prm0) 
                        { 
                        case 1:         
                            pp->stflg |= 0x100000;
                            break;
                        case 3:         
                            pp->flg2 |= 0x8;
                            
                            pp->footeff = 2;
                            break;
                        case 4:         
                            sys->flr_idx = i;
                            
                            if ((pp->flg & 0x10000000)) 
                            {
                                sys->cb_flg |= 0x8000000;
                            }
                            
                            break;
                        }
                        
                        break;
                    }
                }
            }
        }
    }
    
    pp->stflg &= ~0x20000;
    
    if (bhCheckDansaAtari(pp->flr_no, px, pz) != NULL) 
    {
        pp->stflg |= 0x20000;
        return;
    }
    
    if (bhCheckDansaAtari(pp->flr_no, px, pz - pp->ar) != NULL) 
    {
        pp->stflg |= 0x20000;
        return;
    }
    
    if (bhCheckDansaAtari(pp->flr_no, px + pp->ar, pz) != NULL) 
    {
        pp->stflg |= 0x20000;
        return;
    }
    
    if (bhCheckDansaAtari(pp->flr_no, px, pz + pp->ar) != NULL) 
    {
        pp->stflg |= 0x20000;
        return;
    }
    
    if (bhCheckDansaAtari(pp->flr_no, px - pp->ar, pz) != NULL) 
    {
        pp->stflg |= 0x20000;
        return;
    }
}

// 100% matching!
void bhCheckDansa(BH_PWORK* pp) 
{
    ATR_WORK* exp; 
    float px, pz;     
    float* dp;  
    int i;       
    int etc_n;     
 
    px = pp->px;
    pz = pp->pz;
    
    pp->stflg &= ~0x20000;
    
    etc_n = rom->etc_n + sys->metc_n;
    
    for (i = 0; i < etc_n; i++) 
    {
        if (i < rom->etc_n) 
        {
            exp = rom->etcp + i;
        }
        else
        {
            exp = &sys->metcp[i - rom->etc_n];
        }
        
        if (((exp->flg & 0x1)) && (((exp->px <= px) && ((exp->px + exp->w) >= px)) && ((exp->pz <= pz) && ((exp->pz + exp->d) >= pz))) && (exp->flr_no == pp->flr_no))
        {
            switch (exp->type) 
            {
            case 2:
                if ((!(pp->stflg & 0x30)) && (exp->prm0 != 0)) 
                { 
                    pp->stflg |= 0x20000;  
                }
                
                break;
            }
        }
    } 
}

// 100% matching! 
int bhCheckFloorSound(BH_PWORK* pp, int flr_no, float px, float pz)
{
    ATR_WORK* fp; 
    int i;        
    int flr_n;    
    int sno;     
    
    sno = 0;
    
    flr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < flr_n; i++) 
    {
        if (i < rom->flr_n) 
        {
            fp = &rom->flrp[i];
        } 
        else 
        {
            fp = &sys->mflrp[i - rom->flr_n]; 
        }
        
        if ((((fp->flg & 0x1)) && (fp->type == 1)) && ((fp->px <= px) && ((fp->px + fp->w) >= px)) && (((fp->pz <= pz) && ((fp->pz + fp->d) >= pz)) && (fp->flr_no == flr_no))) 
        {
            if (((fp->attr & 0x1)) && ((pp->stflg & 0x10))) 
            {
                return fp->prm0;
            }
            
            if (!(fp->attr & 0x1)) 
            {
                sno = fp->prm0;
            }
        }
    }
    
    return sno;
}

// 100% matching!
ATR_WORK* bhCheckFloorEnemy(int flr_no, float px, float pz)
{
    ATR_WORK* fp;
    int i;
    int flr_n;
	
    flr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < flr_n; i++) 
    {
        if (i < rom->flr_n)
        {
            fp = rom->flrp + i;
        } 
        else 
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if ((((fp->flg & 0x1)) && (fp->type == 2)) && (((fp->px <= px) && ((fp->px + fp->w) >= px)) && ((fp->pz <= pz) && ((fp->pz + fp->d) >= pz))) && (fp->flr_no == flr_no)) 
        {
            return fp;
        }
    }
    
    return NULL;
}

// 100% matching!
ATR_WORK* bhCheckFloorEffect(int flr_no, float px, float pz)
{
    ATR_WORK* fp;
    int i;
    int flr_n;
	
    flr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < flr_n; i++) 
    {
        if (i < rom->flr_n)
        {
            fp = rom->flrp + i;
        } 
        else 
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if ((((fp->flg & 0x1)) && (fp->type == 3)) && (((fp->px <= px) && ((fp->px + fp->w) >= px)) && ((fp->pz <= pz) && ((fp->pz + fp->d) >= pz))) && (fp->flr_no == flr_no)) 
        {
            return fp;
        }
    }
    
    return NULL;
}

// 100% matching!
ATR_WORK* bhCheckWater(NJS_POINT3* pos) 
{
    ATR_WORK* fp; 
    int i;        
    int flr_n;   

    flr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < flr_n; i++) 
    {
        if (i < rom->flr_n)
        {
            fp = rom->flrp + i;
        }
        else 
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if ((((fp->flg & 0x1)) && (fp->type == 3)) && (fp->prm0 == 1) && (((fp->px <= pos->x) && ((fp->px + fp->w) >= pos->x)) && ((fp->pz <= pos->z) && ((fp->pz + fp->d) >= pos->z)) && ((fp->py <= pos->y) && ((fp->py + fp->h) >= pos->y)))) 
        {
            return fp;
        }
    }
    
    return NULL;
}

// 100% matching!
ATR_WORK* bhCheckL2Water(NJS_LINE* lp, NJS_POINT3* pos)
{
    ATR_WORK* fp;  
    NJS_LINE pl;  
    NJS_POINT3 ps, pt; 
    NJS_POINT3 ll; 
    float px, pz;     
    float sca;   
    int i;         
    int flr_n;     

    sca = njScalor((NJS_VECTOR*)&lp->vx);
    
    flr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < flr_n; i++) 
    {
        if (i < rom->flr_n) 
        {
            fp = &rom->flrp[i];
        } 
        else 
        {
            fp = &sys->mflrp[i - rom->flr_n];
        }
        
        if ((((fp->flg & 0x1)) && (fp->type == 3)) && (fp->prm0 == 1)) 
        {
            pl.px = fp->px;
            pl.py = fp->py + fp->h;
            pl.pz = fp->pz;
            
            pl.vx = 0;
            pl.vy = 1.0f;
            pl.vz = 0;
            
            if (!njDistanceL2PL(lp, &pl, &pt)) 
            {
                ps.x = pt.x - lp->px;
                ps.y = pt.y - lp->py;
                ps.z = pt.z - lp->pz;
                
                if ((njInnerProduct((NJS_VECTOR*)&lp->vx, &ps) > 0))
                {
                    px = pt.x - fp->px;
                    pz = pt.z - fp->pz;
                    
                    ll.x = lp->px - pt.x;
                    ll.y = lp->py - pt.y;
                    ll.z = lp->pz - pt.z;
                    
                    if ((((px >= 0) && (px <= fp->w)) && ((pz >= 0) && (pz <= fp->d))) && (njScalor(&ll) <= sca)) 
                    {
                        pos->x = pt.x;
                        pos->y = pt.y;
                        pos->z = pt.z;
                        
                        return fp;
                    }
                }
            }
        }
    }
    
    return NULL;
}

// 100% matching! 
void bhResetAtariAttr()
{
    ATR_WORK* hp; 
    int i;        
    int atr_n;    

    atr_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < atr_n; i++)
    {
        if (i < rom->wal_n)
        {
            hp = &rom->walp[i];
        }
        else
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        hp->attr &= 0x1FFFF;
        
        if ((hp->flg & 0x2)) 
        {
            hp->flg &= 0xFE;
        }
        
        if (((hp->flg & 0x1)) && ((hp->type <= 1) || (hp->type == 7))) 
        {
            hp->w = 0.1f * ceilf(10.0f * hp->w);
            hp->d = 0.1f * ceilf(10.0f * hp->d);
        }
    }
    
    atr_n = rom->etc_n + sys->metc_n;
    
    for (i = 0; i < atr_n; i++) 
    {
        if (i < rom->etc_n)
        {
            hp = &rom->etcp[i];
        } 
        else 
        {
            hp = &sys->metcp[i - rom->etc_n];
        }
        
        *(int*)&hp->attr = (unsigned short)hp->attr; // ???
        
        if ((hp->flg & 0x2))
        {
            hp->flg &= 0xFE;
        }
        
        hp->w = 0.1f * ceilf(10.0f * hp->w);
        hp->d = 0.1f * ceilf(10.0f * hp->d);
    }
    
    atr_n = rom->flr_n + sys->mflr_n;
    
    for (i = 0; i < atr_n; i++) 
    {
        if (i < rom->flr_n) 
        {
            hp = &rom->flrp[i]; 
        } 
        else 
        {
            hp = &sys->mflrp[i - rom->flr_n];
        }
        
        *(int*)&hp->attr = (unsigned short)hp->attr; // ???
        
        if ((hp->flg & 0x2)) 
        {
            hp->flg &= 0xFE;
        }
        
        hp->w = 0.1f * ceilf(10.0f * hp->w);
        hp->d = 0.1f * ceilf(10.0f * hp->d);
    } 
}

// 100% matching!
void bhCheckPlayer(BH_PWORK* pp)
{
    NJS_VECTOR vec;
    float px, pz;     
    float ey;    
    float ln;       
    float ppx, ppy, ppz;     
    int r;        
    float car; // not from DWARF

    if ((!(pp->flg & 0x8)) || ((pp->stflg & 0x40000000)) || ((pp->flg2 & 0x1)) || (!(pp->flg & 0x40))) 
    {
        return;
    }
    
    if (!(plp->flg & 0x8)) 
    {
        ppx = ((EXP_WORK*)plp->exp0)->nlxb + plp->aox; 
        ppy = ((EXP_WORK*)plp->exp0)->nlyb + plp->aoy;
        ppz = ((EXP_WORK*)plp->exp0)->nlzb + plp->aoz;
    }
    else 
    {
        ppx = plp->px + plp->aox;
        ppy = plp->py + plp->aoy;
        ppz = plp->pz + plp->aoz;
    }

    ey = pp->py + pp->aoy;
    
    px = ppx - (pp->px + pp->aox); 
    pz = ppz - (pp->pz + pp->aoz);
    
    ln = njSqrt((px * px) + (pz * pz)); 
    
    car = plp->car + pp->car;
    
    if ((ln < car) && ((ppy <= (ey + pp->cah)) && ((ppy + plp->cah) >= ey))) 
    {
        if (((plp->flg2 & 0x1)) || ((pp->flg2 & 0x40))) 
        {
            r = 10430.381f * atan2f(px, pz);
            
            car = plp->car + pp->car;
            
            njSinCos(r, &pp->px, &pp->pz);
            
            pp->px = (ppx - (pp->px * car)) - pp->aox;
            pp->pz = (ppz - (pp->pz * car)) - pp->aoz;
        } 
        else 
        {
            car = 0.5f * (car - ln);
            
            vec.x = px;
            vec.y = 0;
            vec.z = pz;
            
            njUnitVector(&vec);
            
            vec.x *= car;
            vec.z *= car;
            
            plp->px += vec.x;
            plp->pz += vec.z;
            
            pp->px -= vec.x;
            pp->pz -= vec.z;
        }
        
        pp->stflg  |= 0x4;
        plp->stflg |= 0x2;
    }
}

// 100% matching!
void bhCheckEnemies(BH_PWORK* pp)
{
    float px;         
    float pz;        
    float ln;          
    float ex0;        
    float ey0;    
    float ez0;        
    float ex1;     
    float ey1;         
    float ez1;        
    int r;            
    int i;           
    int hct;            
    NJS_POINT3 ps[128];
    BH_PWORK* enep; // not from DWARF
    float car;      // not from DWARF

    if (!(pp->flg2 & 0x1)) 
    {
        ex0 = pp->px + pp->aox;
        ey0 = pp->py + pp->aoy;
        ez0 = pp->pz + pp->aoz;
        
        hct = 0;
        
        for (i = 0; i < sys->ewk_n; i++) 
        {
            enep = &ene[i];
            
            if (((((enep->flg & 0x1)) && ((enep->flg & 0x8))) && (!(enep->stflg & 0x1000000))) && ((((unsigned int)pp & ~0x80000000)) != (((unsigned int)enep & ~0x80000000))) && ((((((unsigned int)pp & ~0x80000000)) != (((unsigned int)plp & ~0x80000000))) || ((enep->flg & 0x40))) && ((!(enep->flg & 0x80)) || (!(((O_WRK*)enep->lkwkp)->stflg & 0x1000000))))) 
            {
                ex1 = enep->px + enep->aox;
                ey1 = enep->py + enep->aoy;
                ez1 = enep->pz + enep->aoz;
                
                px = ex0 - ex1;
                pz = ez0 - ez1;
                
                ln = njSqrt((px * px) + (pz * pz));
                
                car = pp->car + enep->car;
                
                if ((ln < car) && ((ey1 <= (ey0 + pp->cah)) && ((ey1 + enep->cah) >= ey0)))
                {
                    r = 10430.381f * atan2f(ex1 - ex0, ez1 - ez0);
                    
                    car = pp->car + enep->car;
                    
                    njSinCos(r, &ps[hct].x, &ps[hct].z);
                    
                    ps[hct].x = (ex1 - (car * ps[hct].x)) - pp->aox; 
                    ps[hct].z = (ez1 - (car * ps[hct].z)) - pp->aoz;
                    
                    hct++;
                    
                    if (pp == plp) 
                    { 
                        enep->stflg |= 0x4;
                    } 
                    else 
                    {
                        enep->stflg |= 0x2;
                    }
                } 
            }
        }
        
        if (hct != 0) 
        {
            if (hct > 1) 
            {
                px = pz = 0;
                
                for (i = 0; i < hct; i++) 
                {
                    px += ps[i].x;
                    pz += ps[i].z;
                } 
                
                pp->px = px / hct;
                pp->pz = pz / hct;
            } 
            else 
            {
                pp->px = ps->x;
                pp->pz = ps->z;
            }
        }
    }
}

// 100% matching!
int bhCheckWallAttrB89(ATR_WORK* hp)
{
    int i;
    unsigned char* cnop;
    
    if ((!(hp->attr & 0x100)) || ((sys->st_flg & 0x1))) 
    {
        return 1;
    }
    
    if (!(hp->attr & 0x200))
    {
        return 0;
    }
    
    cnop = &hp->prm1;
    
    for (i = 0; i < 3; i++, cnop++) 
    {
        if (*cnop == (unsigned char)cam.ncut) 
        {
            return 0;
        }
    }
    
    return 1;
}
