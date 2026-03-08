#include "effsub4.h"

/*void(*bhEff_PtclSpriteDraw)(O_WRK*);
O_WRK eff[0];
void(*bhEff_LineDraw)(O_WRK*);
_anon7* sys;
BH_PWORK* plp;
_anon35 cam;
void(*bhEff_3DSpriteDraw)(O_WRK*);
void(*bhEff_ModelDraw)(O_WRK*);*/

// 
// Start address: 0x24c8a0
void bhEff_SetPtcl(BH_PWORK* epw, NJS_POINT3* pos, int tex_id)
{
	int time;
	int i;
	// Line 111, Address: 0x24c8a0, Func Offset: 0
	// Line 114, Address: 0x24c8c4, Func Offset: 0x24
	// Line 115, Address: 0x24c8e4, Func Offset: 0x44
	// Line 117, Address: 0x24c8e8, Func Offset: 0x48
	// Line 118, Address: 0x24c8fc, Func Offset: 0x5c
	// Line 119, Address: 0x24c90c, Func Offset: 0x6c
	// Func End, Address: 0x24c92c, Func Offset: 0x8c
	scePrintf("bhEff_SetPtcl - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24c930
void bhEff_SetPtcl1(BH_PWORK* epw, NJS_POINT3* pos, int tex_id, int wcnt)
{
	int i;
	NJS_POINT3 ps;
	float* size;
	NJS_POINT3* avec;
	NJS_POINT3* vpos;
	int eff_no;
	//_anon41 ps;
	O_WRK* op;
	//_anon6* effect;
	float eff_tbl[2];
	// Line 140, Address: 0x24c930, Func Offset: 0
	// Line 149, Address: 0x24c94c, Func Offset: 0x1c
	// Line 155, Address: 0x24c960, Func Offset: 0x30
	// Line 149, Address: 0x24c964, Func Offset: 0x34
	// Line 150, Address: 0x24c968, Func Offset: 0x38
	// Line 155, Address: 0x24c96c, Func Offset: 0x3c
	// Line 150, Address: 0x24c974, Func Offset: 0x44
	// Line 151, Address: 0x24c978, Func Offset: 0x48
	// Line 152, Address: 0x24c980, Func Offset: 0x50
	// Line 153, Address: 0x24c984, Func Offset: 0x54
	// Line 155, Address: 0x24c988, Func Offset: 0x58
	// Line 161, Address: 0x24c9a0, Func Offset: 0x70
	// Line 163, Address: 0x24c9a8, Func Offset: 0x78
	// Line 165, Address: 0x24c9c4, Func Offset: 0x94
	// Line 163, Address: 0x24c9c8, Func Offset: 0x98
	// Line 181, Address: 0x24c9cc, Func Offset: 0x9c
	// Line 165, Address: 0x24c9d0, Func Offset: 0xa0
	// Line 166, Address: 0x24c9d8, Func Offset: 0xa8
	// Line 168, Address: 0x24c9dc, Func Offset: 0xac
	// Line 167, Address: 0x24c9e4, Func Offset: 0xb4
	// Line 168, Address: 0x24c9e8, Func Offset: 0xb8
	// Line 169, Address: 0x24c9ec, Func Offset: 0xbc
	// Line 180, Address: 0x24c9f0, Func Offset: 0xc0
	// Line 182, Address: 0x24c9f8, Func Offset: 0xc8
	// Line 181, Address: 0x24c9fc, Func Offset: 0xcc
	// Line 185, Address: 0x24ca00, Func Offset: 0xd0
	// Line 182, Address: 0x24ca04, Func Offset: 0xd4
	// Line 188, Address: 0x24ca08, Func Offset: 0xd8
	// Line 189, Address: 0x24ca10, Func Offset: 0xe0
	// Line 191, Address: 0x24ca1c, Func Offset: 0xec
	// Line 193, Address: 0x24ca20, Func Offset: 0xf0
	// Line 194, Address: 0x24ca5c, Func Offset: 0x12c
	// Line 195, Address: 0x24ca60, Func Offset: 0x130
	// Line 198, Address: 0x24ca9c, Func Offset: 0x16c
	// Line 201, Address: 0x24cabc, Func Offset: 0x18c
	// Line 198, Address: 0x24cac4, Func Offset: 0x194
	// Line 201, Address: 0x24cacc, Func Offset: 0x19c
	// Line 198, Address: 0x24cad4, Func Offset: 0x1a4
	// Line 202, Address: 0x24cadc, Func Offset: 0x1ac
	// Line 198, Address: 0x24cae0, Func Offset: 0x1b0
	// Line 202, Address: 0x24cae4, Func Offset: 0x1b4
	// Line 198, Address: 0x24cae8, Func Offset: 0x1b8
	// Line 199, Address: 0x24caf8, Func Offset: 0x1c8
	// Line 201, Address: 0x24cafc, Func Offset: 0x1cc
	// Line 202, Address: 0x24cb00, Func Offset: 0x1d0
	// Line 201, Address: 0x24cb08, Func Offset: 0x1d8
	// Line 202, Address: 0x24cb0c, Func Offset: 0x1dc
	// Line 204, Address: 0x24cb20, Func Offset: 0x1f0
	// Line 210, Address: 0x24cb30, Func Offset: 0x200
	// Line 207, Address: 0x24cb38, Func Offset: 0x208
	// Line 208, Address: 0x24cb3c, Func Offset: 0x20c
	// Line 210, Address: 0x24cb40, Func Offset: 0x210
	// Line 212, Address: 0x24cb48, Func Offset: 0x218
	// Func End, Address: 0x24cb68, Func Offset: 0x238
	scePrintf("bhEff_SetPtcl1 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24cb70
void bhEff_SetPtcl2(NJS_POINT3* pos, float mtx[16])
{
	float spd;
	int ang2;
	int ang;
	NJS_POINT3* vec;
	NJS_POINT3* vtx_p2;
	NJS_POINT3* vtx_p;
	int i;
	int eff_no;
	//_anon9* effect;
	O_WRK* op;
	//_anon41 ps;
	float eff_tbl[2];
	// Line 232, Address: 0x24cb70, Func Offset: 0
	// Line 241, Address: 0x24cb9c, Func Offset: 0x2c
	// Line 247, Address: 0x24cba8, Func Offset: 0x38
	// Line 241, Address: 0x24cbb0, Func Offset: 0x40
	// Line 242, Address: 0x24cbb4, Func Offset: 0x44
	// Line 247, Address: 0x24cbb8, Func Offset: 0x48
	// Line 242, Address: 0x24cbbc, Func Offset: 0x4c
	// Line 243, Address: 0x24cbc0, Func Offset: 0x50
	// Line 244, Address: 0x24cbc8, Func Offset: 0x58
	// Line 245, Address: 0x24cbcc, Func Offset: 0x5c
	// Line 247, Address: 0x24cbd0, Func Offset: 0x60
	// Line 253, Address: 0x24cbe8, Func Offset: 0x78
	// Line 255, Address: 0x24cbf0, Func Offset: 0x80
	// Line 258, Address: 0x24cc10, Func Offset: 0xa0
	// Line 257, Address: 0x24cc18, Func Offset: 0xa8
	// Line 258, Address: 0x24cc1c, Func Offset: 0xac
	// Line 280, Address: 0x24cc20, Func Offset: 0xb0
	// Line 259, Address: 0x24cc24, Func Offset: 0xb4
	// Line 260, Address: 0x24cc28, Func Offset: 0xb8
	// Line 272, Address: 0x24cc2c, Func Offset: 0xbc
	// Line 273, Address: 0x24cc30, Func Offset: 0xc0
	// Line 272, Address: 0x24cc34, Func Offset: 0xc4
	// Line 274, Address: 0x24cc38, Func Offset: 0xc8
	// Line 273, Address: 0x24cc3c, Func Offset: 0xcc
	// Line 278, Address: 0x24cc40, Func Offset: 0xd0
	// Line 274, Address: 0x24cc44, Func Offset: 0xd4
	// Line 280, Address: 0x24cc48, Func Offset: 0xd8
	// Line 281, Address: 0x24cc50, Func Offset: 0xe0
	// Line 282, Address: 0x24cc58, Func Offset: 0xe8
	// Line 284, Address: 0x24cc64, Func Offset: 0xf4
	// Line 286, Address: 0x24cc68, Func Offset: 0xf8
	// Line 287, Address: 0x24cc74, Func Offset: 0x104
	// Line 288, Address: 0x24cc80, Func Offset: 0x110
	// Line 290, Address: 0x24cc88, Func Offset: 0x118
	// Line 291, Address: 0x24cca8, Func Offset: 0x138
	// Line 292, Address: 0x24ccc4, Func Offset: 0x154
	// Line 294, Address: 0x24cce4, Func Offset: 0x174
	// Line 292, Address: 0x24cce8, Func Offset: 0x178
	// Line 294, Address: 0x24cd04, Func Offset: 0x194
	// Line 295, Address: 0x24cd1c, Func Offset: 0x1ac
	// Line 294, Address: 0x24cd20, Func Offset: 0x1b0
	// Line 295, Address: 0x24cd24, Func Offset: 0x1b4
	// Line 296, Address: 0x24cd30, Func Offset: 0x1c0
	// Line 298, Address: 0x24cd4c, Func Offset: 0x1dc
	// Line 296, Address: 0x24cd58, Func Offset: 0x1e8
	// Line 298, Address: 0x24cd5c, Func Offset: 0x1ec
	// Line 303, Address: 0x24cd64, Func Offset: 0x1f4
	// Line 300, Address: 0x24cd6c, Func Offset: 0x1fc
	// Line 301, Address: 0x24cd70, Func Offset: 0x200
	// Line 303, Address: 0x24cd74, Func Offset: 0x204
	// Line 305, Address: 0x24cd7c, Func Offset: 0x20c
	// Func End, Address: 0x24cdac, Func Offset: 0x23c
	scePrintf("bhEff_SetPtcl2 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24cdb0
void bhEff_SetPtcl2V(NJS_POINT3* pos, NJS_POINT3* dv, int wcnt)
{
	float spd;
	int ang2;
	int ang1;
	NJS_POINT3* vec;
	NJS_POINT3* vtx_p2;
	NJS_POINT3* vtx_p;
	int i;
	int eff_no;
	//_anon9* effect;
	O_WRK* op;
	//_anon41 ps;
	float eff_tbl[2];
	// Line 328, Address: 0x24cdb0, Func Offset: 0
	// Line 337, Address: 0x24cddc, Func Offset: 0x2c
	// Line 343, Address: 0x24cdec, Func Offset: 0x3c
	// Line 337, Address: 0x24cdf0, Func Offset: 0x40
	// Line 338, Address: 0x24cdf4, Func Offset: 0x44
	// Line 343, Address: 0x24cdf8, Func Offset: 0x48
	// Line 338, Address: 0x24ce00, Func Offset: 0x50
	// Line 339, Address: 0x24ce04, Func Offset: 0x54
	// Line 340, Address: 0x24ce0c, Func Offset: 0x5c
	// Line 341, Address: 0x24ce10, Func Offset: 0x60
	// Line 343, Address: 0x24ce14, Func Offset: 0x64
	// Line 349, Address: 0x24ce2c, Func Offset: 0x7c
	// Line 351, Address: 0x24ce34, Func Offset: 0x84
	// Line 354, Address: 0x24ce54, Func Offset: 0xa4
	// Line 353, Address: 0x24ce5c, Func Offset: 0xac
	// Line 354, Address: 0x24ce60, Func Offset: 0xb0
	// Line 355, Address: 0x24ce64, Func Offset: 0xb4
	// Line 356, Address: 0x24ce68, Func Offset: 0xb8
	// Line 368, Address: 0x24ce70, Func Offset: 0xc0
	// Line 369, Address: 0x24ce74, Func Offset: 0xc4
	// Line 368, Address: 0x24ce78, Func Offset: 0xc8
	// Line 370, Address: 0x24ce7c, Func Offset: 0xcc
	// Line 369, Address: 0x24ce80, Func Offset: 0xd0
	// Line 374, Address: 0x24ce84, Func Offset: 0xd4
	// Line 370, Address: 0x24ce88, Func Offset: 0xd8
	// Line 376, Address: 0x24ce8c, Func Offset: 0xdc
	// Line 378, Address: 0x24ce90, Func Offset: 0xe0
	// Line 379, Address: 0x24ce9c, Func Offset: 0xec
	// Line 380, Address: 0x24cea8, Func Offset: 0xf8
	// Line 382, Address: 0x24ceb0, Func Offset: 0x100
	// Line 383, Address: 0x24cecc, Func Offset: 0x11c
	// Line 384, Address: 0x24cee8, Func Offset: 0x138
	// Line 386, Address: 0x24cf08, Func Offset: 0x158
	// Line 384, Address: 0x24cf0c, Func Offset: 0x15c
	// Line 386, Address: 0x24cf28, Func Offset: 0x178
	// Line 387, Address: 0x24cf30, Func Offset: 0x180
	// Line 388, Address: 0x24cf38, Func Offset: 0x188
	// Line 389, Address: 0x24cf4c, Func Offset: 0x19c
	// Line 391, Address: 0x24cf5c, Func Offset: 0x1ac
	// Line 398, Address: 0x24cf60, Func Offset: 0x1b0
	// Line 396, Address: 0x24cf68, Func Offset: 0x1b8
	// Line 391, Address: 0x24cf6c, Func Offset: 0x1bc
	// Line 397, Address: 0x24cf70, Func Offset: 0x1c0
	// Line 391, Address: 0x24cf74, Func Offset: 0x1c4
	// Line 392, Address: 0x24cf78, Func Offset: 0x1c8
	// Line 393, Address: 0x24cf84, Func Offset: 0x1d4
	// Line 398, Address: 0x24cf90, Func Offset: 0x1e0
	// Line 400, Address: 0x24cf98, Func Offset: 0x1e8
	// Func End, Address: 0x24cfc8, Func Offset: 0x218
	scePrintf("bhEff_SetPtcl2V - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24cfd0
void bhEff_SetBlood5(NJS_POINT3* pos, NJS_POINT3* vec, float size, int col)
{
	int tmp;
	// Line 513, Address: 0x24cfd0, Func Offset: 0
	// Line 517, Address: 0x24cfdc, Func Offset: 0xc
	// Line 518, Address: 0x24cfec, Func Offset: 0x1c
	// Line 517, Address: 0x24cff0, Func Offset: 0x20
	// Line 518, Address: 0x24cffc, Func Offset: 0x2c
	// Line 530, Address: 0x24d004, Func Offset: 0x34
	// Line 518, Address: 0x24d00c, Func Offset: 0x3c
	// Line 519, Address: 0x24d018, Func Offset: 0x48
	// Line 520, Address: 0x24d02c, Func Offset: 0x5c
	// Line 521, Address: 0x24d040, Func Offset: 0x70
	// Line 522, Address: 0x24d054, Func Offset: 0x84
	// Line 523, Address: 0x24d06c, Func Offset: 0x9c
	// Line 524, Address: 0x24d084, Func Offset: 0xb4
	// Line 525, Address: 0x24d09c, Func Offset: 0xcc
	// Line 526, Address: 0x24d0b0, Func Offset: 0xe0
	// Line 527, Address: 0x24d0c4, Func Offset: 0xf4
	// Line 530, Address: 0x24d0d8, Func Offset: 0x108
	// Line 532, Address: 0x24d100, Func Offset: 0x130
	// Line 533, Address: 0x24d124, Func Offset: 0x154
	// Line 534, Address: 0x24d13c, Func Offset: 0x16c
	// Line 535, Address: 0x24d14c, Func Offset: 0x17c
	// Line 536, Address: 0x24d164, Func Offset: 0x194
	// Line 537, Address: 0x24d178, Func Offset: 0x1a8
	// Line 538, Address: 0x24d190, Func Offset: 0x1c0
	// Line 540, Address: 0x24d1a8, Func Offset: 0x1d8
	// Func End, Address: 0x24d1b8, Func Offset: 0x1e8
	scePrintf("bhEff_SetBlood5 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24d1c0
void bhEff_Sub350(O_WRK* op)
{
	int i;
	int tmp;
	float wk1;
	float wk0;
	NJS_POINT3 p2;
	NJS_POINT3 p1;
	//_anon31 uvinfo[11];
	//_anon4* anim_tbl[2];
	// Line 559, Address: 0x24d1c0, Func Offset: 0
	// Line 596, Address: 0x24d1e4, Func Offset: 0x24
	// Line 599, Address: 0x24d21c, Func Offset: 0x5c
	// Line 600, Address: 0x24d228, Func Offset: 0x68
	// Line 603, Address: 0x24d22c, Func Offset: 0x6c
	// Line 606, Address: 0x24d230, Func Offset: 0x70
	// Line 611, Address: 0x24d234, Func Offset: 0x74
	// Line 616, Address: 0x24d238, Func Offset: 0x78
	// Line 600, Address: 0x24d23c, Func Offset: 0x7c
	// Line 603, Address: 0x24d248, Func Offset: 0x88
	// Line 604, Address: 0x24d24c, Func Offset: 0x8c
	// Line 606, Address: 0x24d250, Func Offset: 0x90
	// Line 607, Address: 0x24d25c, Func Offset: 0x9c
	// Line 608, Address: 0x24d268, Func Offset: 0xa8
	// Line 609, Address: 0x24d26c, Func Offset: 0xac
	// Line 610, Address: 0x24d270, Func Offset: 0xb0
	// Line 611, Address: 0x24d274, Func Offset: 0xb4
	// Line 613, Address: 0x24d278, Func Offset: 0xb8
	// Line 616, Address: 0x24d27c, Func Offset: 0xbc
	// Line 617, Address: 0x24d290, Func Offset: 0xd0
	// Line 619, Address: 0x24d2a8, Func Offset: 0xe8
	// Line 620, Address: 0x24d2c0, Func Offset: 0x100
	// Line 621, Address: 0x24d2d4, Func Offset: 0x114
	// Line 622, Address: 0x24d2d8, Func Offset: 0x118
	// Line 625, Address: 0x24d2e4, Func Offset: 0x124
	// Line 626, Address: 0x24d2f0, Func Offset: 0x130
	// Line 628, Address: 0x24d2fc, Func Offset: 0x13c
	// Line 629, Address: 0x24d304, Func Offset: 0x144
	// Line 637, Address: 0x24d310, Func Offset: 0x150
	// Line 638, Address: 0x24d318, Func Offset: 0x158
	// Line 649, Address: 0x24d324, Func Offset: 0x164
	// Line 646, Address: 0x24d328, Func Offset: 0x168
	// Line 637, Address: 0x24d32c, Func Offset: 0x16c
	// Line 649, Address: 0x24d330, Func Offset: 0x170
	// Line 648, Address: 0x24d334, Func Offset: 0x174
	// Line 637, Address: 0x24d338, Func Offset: 0x178
	// Line 638, Address: 0x24d33c, Func Offset: 0x17c
	// Line 646, Address: 0x24d348, Func Offset: 0x188
	// Line 638, Address: 0x24d34c, Func Offset: 0x18c
	// Line 639, Address: 0x24d360, Func Offset: 0x1a0
	// Line 640, Address: 0x24d370, Func Offset: 0x1b0
	// Line 643, Address: 0x24d37c, Func Offset: 0x1bc
	// Line 644, Address: 0x24d384, Func Offset: 0x1c4
	// Line 645, Address: 0x24d38c, Func Offset: 0x1cc
	// Line 646, Address: 0x24d394, Func Offset: 0x1d4
	// Line 649, Address: 0x24d3a0, Func Offset: 0x1e0
	// Line 652, Address: 0x24d3b4, Func Offset: 0x1f4
	// Line 655, Address: 0x24d3e0, Func Offset: 0x220
	// Line 656, Address: 0x24d3e8, Func Offset: 0x228
	// Line 657, Address: 0x24d3f4, Func Offset: 0x234
	// Line 656, Address: 0x24d3f8, Func Offset: 0x238
	// Line 657, Address: 0x24d3fc, Func Offset: 0x23c
	// Line 658, Address: 0x24d408, Func Offset: 0x248
	// Line 659, Address: 0x24d414, Func Offset: 0x254
	// Line 661, Address: 0x24d420, Func Offset: 0x260
	// Line 659, Address: 0x24d424, Func Offset: 0x264
	// Line 661, Address: 0x24d42c, Func Offset: 0x26c
	// Line 662, Address: 0x24d440, Func Offset: 0x280
	// Line 663, Address: 0x24d444, Func Offset: 0x284
	// Line 665, Address: 0x24d454, Func Offset: 0x294
	// Line 667, Address: 0x24d468, Func Offset: 0x2a8
	// Line 668, Address: 0x24d474, Func Offset: 0x2b4
	// Line 671, Address: 0x24d47c, Func Offset: 0x2bc
	// Line 674, Address: 0x24d488, Func Offset: 0x2c8
	// Line 675, Address: 0x24d48c, Func Offset: 0x2cc
	// Line 680, Address: 0x24d494, Func Offset: 0x2d4
	// Line 682, Address: 0x24d4a4, Func Offset: 0x2e4
	// Line 683, Address: 0x24d4ac, Func Offset: 0x2ec
	// Line 684, Address: 0x24d4b0, Func Offset: 0x2f0
	// Line 685, Address: 0x24d4b4, Func Offset: 0x2f4
	// Line 686, Address: 0x24d4bc, Func Offset: 0x2fc
	// Line 690, Address: 0x24d4c4, Func Offset: 0x304
	// Line 691, Address: 0x24d4c8, Func Offset: 0x308
	// Line 695, Address: 0x24d4d0, Func Offset: 0x310
	// Line 696, Address: 0x24d4d4, Func Offset: 0x314
	// Line 690, Address: 0x24d4d8, Func Offset: 0x318
	// Line 691, Address: 0x24d4dc, Func Offset: 0x31c
	// Line 697, Address: 0x24d4e0, Func Offset: 0x320
	// Line 691, Address: 0x24d4ec, Func Offset: 0x32c
	// Line 697, Address: 0x24d4f0, Func Offset: 0x330
	// Line 691, Address: 0x24d4f4, Func Offset: 0x334
	// Line 692, Address: 0x24d4f8, Func Offset: 0x338
	// Line 694, Address: 0x24d500, Func Offset: 0x340
	// Line 695, Address: 0x24d508, Func Offset: 0x348
	// Line 696, Address: 0x24d514, Func Offset: 0x354
	// Line 697, Address: 0x24d518, Func Offset: 0x358
	// Line 699, Address: 0x24d528, Func Offset: 0x368
	// Line 700, Address: 0x24d52c, Func Offset: 0x36c
	// Line 702, Address: 0x24d534, Func Offset: 0x374
	// Line 699, Address: 0x24d538, Func Offset: 0x378
	// Line 700, Address: 0x24d53c, Func Offset: 0x37c
	// Line 701, Address: 0x24d548, Func Offset: 0x388
	// Line 706, Address: 0x24d550, Func Offset: 0x390
	// Line 710, Address: 0x24d558, Func Offset: 0x398
	// Line 711, Address: 0x24d564, Func Offset: 0x3a4
	// Line 712, Address: 0x24d568, Func Offset: 0x3a8
	// Line 710, Address: 0x24d56c, Func Offset: 0x3ac
	// Line 711, Address: 0x24d578, Func Offset: 0x3b8
	// Line 719, Address: 0x24d580, Func Offset: 0x3c0
	// Line 711, Address: 0x24d584, Func Offset: 0x3c4
	// Line 712, Address: 0x24d590, Func Offset: 0x3d0
	// Line 713, Address: 0x24d5a4, Func Offset: 0x3e4
	// Line 714, Address: 0x24d5b8, Func Offset: 0x3f8
	// Line 715, Address: 0x24d5cc, Func Offset: 0x40c
	// Line 719, Address: 0x24d5e0, Func Offset: 0x420
	// Line 721, Address: 0x24d5ec, Func Offset: 0x42c
	// Line 723, Address: 0x24d5f8, Func Offset: 0x438
	// Line 724, Address: 0x24d60c, Func Offset: 0x44c
	// Line 725, Address: 0x24d620, Func Offset: 0x460
	// Line 727, Address: 0x24d634, Func Offset: 0x474
	// Line 729, Address: 0x24d644, Func Offset: 0x484
	// Line 733, Address: 0x24d64c, Func Offset: 0x48c
	// Line 732, Address: 0x24d654, Func Offset: 0x494
	// Line 733, Address: 0x24d660, Func Offset: 0x4a0
	// Line 735, Address: 0x24d68c, Func Offset: 0x4cc
	// Line 736, Address: 0x24d6b8, Func Offset: 0x4f8
	// Line 737, Address: 0x24d6c0, Func Offset: 0x500
	// Line 739, Address: 0x24d6c8, Func Offset: 0x508
	// Line 740, Address: 0x24d710, Func Offset: 0x550
	// Line 741, Address: 0x24d764, Func Offset: 0x5a4
	// Line 743, Address: 0x24d7b0, Func Offset: 0x5f0
	// Line 744, Address: 0x24d7c0, Func Offset: 0x600
	// Line 747, Address: 0x24d7c8, Func Offset: 0x608
	// Line 752, Address: 0x24d7d4, Func Offset: 0x614
	// Line 747, Address: 0x24d7e0, Func Offset: 0x620
	// Line 748, Address: 0x24d7ec, Func Offset: 0x62c
	// Line 749, Address: 0x24d804, Func Offset: 0x644
	// Line 752, Address: 0x24d81c, Func Offset: 0x65c
	// Line 754, Address: 0x24d840, Func Offset: 0x680
	// Line 755, Address: 0x24d864, Func Offset: 0x6a4
	// Line 754, Address: 0x24d870, Func Offset: 0x6b0
	// Line 755, Address: 0x24d878, Func Offset: 0x6b8
	// Line 756, Address: 0x24d87c, Func Offset: 0x6bc
	// Line 755, Address: 0x24d888, Func Offset: 0x6c8
	// Line 756, Address: 0x24d88c, Func Offset: 0x6cc
	// Line 757, Address: 0x24d890, Func Offset: 0x6d0
	// Line 756, Address: 0x24d89c, Func Offset: 0x6dc
	// Line 758, Address: 0x24d8a0, Func Offset: 0x6e0
	// Line 759, Address: 0x24d8f4, Func Offset: 0x734
	// Line 760, Address: 0x24d954, Func Offset: 0x794
	// Line 764, Address: 0x24d9ac, Func Offset: 0x7ec
	// Line 765, Address: 0x24d9b4, Func Offset: 0x7f4
	// Line 766, Address: 0x24d9b8, Func Offset: 0x7f8
	// Line 767, Address: 0x24d9bc, Func Offset: 0x7fc
	// Line 777, Address: 0x24d9c8, Func Offset: 0x808
	// Line 779, Address: 0x24d9d4, Func Offset: 0x814
	// Line 781, Address: 0x24da00, Func Offset: 0x840
	// Func End, Address: 0x24da24, Func Offset: 0x864
	scePrintf("bhEff_Sub350 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24da30
void bhEff_Sub351(O_WRK* op)
{
	//_anon31 uvinfo[14];
	//_anon4 anim00_tbl[15];
	// Line 797, Address: 0x24da30, Func Offset: 0
	// Line 826, Address: 0x24da38, Func Offset: 0x8
	// Line 829, Address: 0x24da64, Func Offset: 0x34
	// Line 830, Address: 0x24da70, Func Offset: 0x40
	// Line 833, Address: 0x24da74, Func Offset: 0x44
	// Line 834, Address: 0x24da78, Func Offset: 0x48
	// Line 836, Address: 0x24da7c, Func Offset: 0x4c
	// Line 830, Address: 0x24da80, Func Offset: 0x50
	// Line 833, Address: 0x24da8c, Func Offset: 0x5c
	// Line 834, Address: 0x24da90, Func Offset: 0x60
	// Line 836, Address: 0x24da94, Func Offset: 0x64
	// Line 842, Address: 0x24da98, Func Offset: 0x68
	// Line 836, Address: 0x24da9c, Func Offset: 0x6c
	// Line 837, Address: 0x24daa4, Func Offset: 0x74
	// Line 838, Address: 0x24dab0, Func Offset: 0x80
	// Line 839, Address: 0x24dab4, Func Offset: 0x84
	// Line 840, Address: 0x24dab8, Func Offset: 0x88
	// Line 841, Address: 0x24dabc, Func Offset: 0x8c
	// Line 842, Address: 0x24dac0, Func Offset: 0x90
	// Line 844, Address: 0x24dac4, Func Offset: 0x94
	// Line 845, Address: 0x24dac8, Func Offset: 0x98
	// Line 846, Address: 0x24dad0, Func Offset: 0xa0
	// Line 849, Address: 0x24dad8, Func Offset: 0xa8
	// Line 850, Address: 0x24dae4, Func Offset: 0xb4
	// Line 852, Address: 0x24daf0, Func Offset: 0xc0
	// Line 853, Address: 0x24daf4, Func Offset: 0xc4
	// Line 855, Address: 0x24daf8, Func Offset: 0xc8
	// Line 856, Address: 0x24db14, Func Offset: 0xe4
	// Line 864, Address: 0x24db20, Func Offset: 0xf0
	// Line 865, Address: 0x24db30, Func Offset: 0x100
	// Line 866, Address: 0x24db40, Func Offset: 0x110
	// Line 868, Address: 0x24db50, Func Offset: 0x120
	// Line 870, Address: 0x24db64, Func Offset: 0x134
	// Line 871, Address: 0x24db74, Func Offset: 0x144
	// Line 877, Address: 0x24db84, Func Offset: 0x154
	// Line 879, Address: 0x24db90, Func Offset: 0x160
	// Line 881, Address: 0x24dba8, Func Offset: 0x178
	// Func End, Address: 0x24dbb4, Func Offset: 0x184
	scePrintf("bhEff_Sub351 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24dbc0
void bhEff_Sub352(O_WRK* op)
{
	//_anon11* owk;
	NJS_POINT3 p2;
	NJS_POINT3 p1;
	//_anon31 uvinfo[10];
	//_anon4* anim_tbl[1];
	// Line 898, Address: 0x24dbc0, Func Offset: 0
	// Line 926, Address: 0x24dbe0, Func Offset: 0x20
	// Line 929, Address: 0x24dbf8, Func Offset: 0x38
	// Line 932, Address: 0x24dc04, Func Offset: 0x44
	// Line 938, Address: 0x24dc1c, Func Offset: 0x5c
	// Line 942, Address: 0x24dc54, Func Offset: 0x94
	// Line 943, Address: 0x24dc58, Func Offset: 0x98
	// Line 942, Address: 0x24dc5c, Func Offset: 0x9c
	// Line 943, Address: 0x24dc60, Func Offset: 0xa0
	// Line 945, Address: 0x24dc64, Func Offset: 0xa4
	// Line 948, Address: 0x24dc6c, Func Offset: 0xac
	// Line 950, Address: 0x24dc70, Func Offset: 0xb0
	// Line 951, Address: 0x24dc74, Func Offset: 0xb4
	// Line 957, Address: 0x24dc78, Func Offset: 0xb8
	// Line 945, Address: 0x24dc7c, Func Offset: 0xbc
	// Line 946, Address: 0x24dc84, Func Offset: 0xc4
	// Line 947, Address: 0x24dc88, Func Offset: 0xc8
	// Line 948, Address: 0x24dc8c, Func Offset: 0xcc
	// Line 950, Address: 0x24dc90, Func Offset: 0xd0
	// Line 951, Address: 0x24dc94, Func Offset: 0xd4
	// Line 952, Address: 0x24dc98, Func Offset: 0xd8
	// Line 953, Address: 0x24dc9c, Func Offset: 0xdc
	// Line 954, Address: 0x24dca0, Func Offset: 0xe0
	// Line 955, Address: 0x24dca4, Func Offset: 0xe4
	// Line 956, Address: 0x24dca8, Func Offset: 0xe8
	// Line 957, Address: 0x24dcac, Func Offset: 0xec
	// Line 958, Address: 0x24dcb0, Func Offset: 0xf0
	// Line 959, Address: 0x24dcb4, Func Offset: 0xf4
	// Line 960, Address: 0x24dcb8, Func Offset: 0xf8
	// Line 961, Address: 0x24dcbc, Func Offset: 0xfc
	// Line 962, Address: 0x24dcc0, Func Offset: 0x100
	// Line 964, Address: 0x24dcd4, Func Offset: 0x114
	// Line 966, Address: 0x24dce0, Func Offset: 0x120
	// Line 969, Address: 0x24dce8, Func Offset: 0x128
	// Line 970, Address: 0x24dcf4, Func Offset: 0x134
	// Line 971, Address: 0x24dcfc, Func Offset: 0x13c
	// Line 973, Address: 0x24dd0c, Func Offset: 0x14c
	// Line 971, Address: 0x24dd10, Func Offset: 0x150
	// Line 973, Address: 0x24dd14, Func Offset: 0x154
	// Line 971, Address: 0x24dd18, Func Offset: 0x158
	// Line 972, Address: 0x24dd1c, Func Offset: 0x15c
	// Line 973, Address: 0x24dd28, Func Offset: 0x168
	// Line 975, Address: 0x24dd38, Func Offset: 0x178
	// Line 986, Address: 0x24dd3c, Func Offset: 0x17c
	// Line 975, Address: 0x24dd44, Func Offset: 0x184
	// Line 977, Address: 0x24dd50, Func Offset: 0x190
	// Line 978, Address: 0x24dd54, Func Offset: 0x194
	// Line 979, Address: 0x24dd58, Func Offset: 0x198
	// Line 981, Address: 0x24dd5c, Func Offset: 0x19c
	// Line 982, Address: 0x24dd64, Func Offset: 0x1a4
	// Line 983, Address: 0x24dd6c, Func Offset: 0x1ac
	// Line 985, Address: 0x24dd74, Func Offset: 0x1b4
	// Line 986, Address: 0x24dd7c, Func Offset: 0x1bc
	// Line 988, Address: 0x24dd88, Func Offset: 0x1c8
	// Line 994, Address: 0x24dd90, Func Offset: 0x1d0
	// Line 995, Address: 0x24dd94, Func Offset: 0x1d4
	// Line 996, Address: 0x24dd98, Func Offset: 0x1d8
	// Line 999, Address: 0x24dda4, Func Offset: 0x1e4
	// Line 1000, Address: 0x24ddb0, Func Offset: 0x1f0
	// Line 1002, Address: 0x24ddbc, Func Offset: 0x1fc
	// Line 1003, Address: 0x24ddf0, Func Offset: 0x230
	// Line 1004, Address: 0x24ddf8, Func Offset: 0x238
	// Line 1012, Address: 0x24de04, Func Offset: 0x244
	// Line 1013, Address: 0x24de14, Func Offset: 0x254
	// Line 1015, Address: 0x24de28, Func Offset: 0x268
	// Line 1017, Address: 0x24de2c, Func Offset: 0x26c
	// Line 1020, Address: 0x24de34, Func Offset: 0x274
	// Line 1022, Address: 0x24de44, Func Offset: 0x284
	// Line 1024, Address: 0x24de54, Func Offset: 0x294
	// Line 1025, Address: 0x24de5c, Func Offset: 0x29c
	// Line 1028, Address: 0x24de64, Func Offset: 0x2a4
	// Line 1031, Address: 0x24de6c, Func Offset: 0x2ac
	// Line 1032, Address: 0x24de88, Func Offset: 0x2c8
	// Line 1034, Address: 0x24de8c, Func Offset: 0x2cc
	// Line 1036, Address: 0x24de9c, Func Offset: 0x2dc
	// Line 1047, Address: 0x24dea0, Func Offset: 0x2e0
	// Line 1049, Address: 0x24deb8, Func Offset: 0x2f8
	// Line 1054, Address: 0x24ded8, Func Offset: 0x318
	// Line 1056, Address: 0x24dee4, Func Offset: 0x324
	// Line 1064, Address: 0x24df10, Func Offset: 0x350
	// Line 1065, Address: 0x24df1c, Func Offset: 0x35c
	// Line 1066, Address: 0x24df20, Func Offset: 0x360
	// Line 1065, Address: 0x24df24, Func Offset: 0x364
	// Line 1064, Address: 0x24df28, Func Offset: 0x368
	// Line 1065, Address: 0x24df2c, Func Offset: 0x36c
	// Line 1064, Address: 0x24df30, Func Offset: 0x370
	// Line 1070, Address: 0x24df34, Func Offset: 0x374
	// Line 1064, Address: 0x24df38, Func Offset: 0x378
	// Line 1065, Address: 0x24df3c, Func Offset: 0x37c
	// Line 1066, Address: 0x24df44, Func Offset: 0x384
	// Line 1065, Address: 0x24df48, Func Offset: 0x388
	// Line 1066, Address: 0x24df50, Func Offset: 0x390
	// Line 1069, Address: 0x24df64, Func Offset: 0x3a4
	// Line 1070, Address: 0x24df84, Func Offset: 0x3c4
	// Line 1071, Address: 0x24df8c, Func Offset: 0x3cc
	// Line 1072, Address: 0x24df9c, Func Offset: 0x3dc
	// Line 1073, Address: 0x24dfa8, Func Offset: 0x3e8
	// Line 1074, Address: 0x24dfac, Func Offset: 0x3ec
	// Line 1072, Address: 0x24dfb0, Func Offset: 0x3f0
	// Line 1076, Address: 0x24dfb4, Func Offset: 0x3f4
	// Line 1072, Address: 0x24dfb8, Func Offset: 0x3f8
	// Line 1073, Address: 0x24dfc0, Func Offset: 0x400
	// Line 1074, Address: 0x24dfd8, Func Offset: 0x418
	// Line 1076, Address: 0x24dfec, Func Offset: 0x42c
	// Line 1077, Address: 0x24dff4, Func Offset: 0x434
	// Line 1079, Address: 0x24e004, Func Offset: 0x444
	// Line 1083, Address: 0x24e008, Func Offset: 0x448
	// Line 1079, Address: 0x24e00c, Func Offset: 0x44c
	// Line 1080, Address: 0x24e010, Func Offset: 0x450
	// Line 1081, Address: 0x24e018, Func Offset: 0x458
	// Line 1083, Address: 0x24e020, Func Offset: 0x460
	// Line 1085, Address: 0x24e024, Func Offset: 0x464
	// Func End, Address: 0x24e048, Func Offset: 0x488
	scePrintf("bhEff_Sub352 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24e050
void bhEff_Sub353(O_WRK* op)
{
	//_anon31 uvinfo[1];
	// Line 1108, Address: 0x24e050, Func Offset: 0
	// Line 1111, Address: 0x24e094, Func Offset: 0x44
	// Line 1113, Address: 0x24e0a0, Func Offset: 0x50
	// Line 1115, Address: 0x24e0a4, Func Offset: 0x54
	// Line 1116, Address: 0x24e0a8, Func Offset: 0x58
	// Line 1118, Address: 0x24e0ac, Func Offset: 0x5c
	// Line 1113, Address: 0x24e0b0, Func Offset: 0x60
	// Line 1115, Address: 0x24e0bc, Func Offset: 0x6c
	// Line 1116, Address: 0x24e0c0, Func Offset: 0x70
	// Line 1118, Address: 0x24e0c4, Func Offset: 0x74
	// Line 1123, Address: 0x24e0c8, Func Offset: 0x78
	// Line 1118, Address: 0x24e0cc, Func Offset: 0x7c
	// Line 1119, Address: 0x24e0d4, Func Offset: 0x84
	// Line 1120, Address: 0x24e0e0, Func Offset: 0x90
	// Line 1121, Address: 0x24e0e4, Func Offset: 0x94
	// Line 1122, Address: 0x24e0e8, Func Offset: 0x98
	// Line 1123, Address: 0x24e0ec, Func Offset: 0x9c
	// Line 1124, Address: 0x24e0f0, Func Offset: 0xa0
	// Line 1125, Address: 0x24e0f4, Func Offset: 0xa4
	// Line 1127, Address: 0x24e0f8, Func Offset: 0xa8
	// Line 1130, Address: 0x24e104, Func Offset: 0xb4
	// Line 1131, Address: 0x24e110, Func Offset: 0xc0
	// Line 1133, Address: 0x24e11c, Func Offset: 0xcc
	// Line 1134, Address: 0x24e124, Func Offset: 0xd4
	// Line 1135, Address: 0x24e12c, Func Offset: 0xdc
	// Line 1143, Address: 0x24e138, Func Offset: 0xe8
	// Line 1145, Address: 0x24e154, Func Offset: 0x104
	// Line 1146, Address: 0x24e15c, Func Offset: 0x10c
	// Line 1149, Address: 0x24e164, Func Offset: 0x114
	// Line 1151, Address: 0x24e170, Func Offset: 0x120
	// Line 1153, Address: 0x24e180, Func Offset: 0x130
	// Line 1155, Address: 0x24e190, Func Offset: 0x140
	// Line 1156, Address: 0x24e198, Func Offset: 0x148
	// Line 1158, Address: 0x24e1a0, Func Offset: 0x150
	// Line 1162, Address: 0x24e1a8, Func Offset: 0x158
	// Line 1163, Address: 0x24e1c0, Func Offset: 0x170
	// Line 1164, Address: 0x24e1cc, Func Offset: 0x17c
	// Line 1166, Address: 0x24e1dc, Func Offset: 0x18c
	// Line 1168, Address: 0x24e1e4, Func Offset: 0x194
	// Line 1166, Address: 0x24e1ec, Func Offset: 0x19c
	// Line 1167, Address: 0x24e1f4, Func Offset: 0x1a4
	// Line 1168, Address: 0x24e204, Func Offset: 0x1b4
	// Line 1170, Address: 0x24e218, Func Offset: 0x1c8
	// Line 1174, Address: 0x24e21c, Func Offset: 0x1cc
	// Line 1177, Address: 0x24e224, Func Offset: 0x1d4
	// Line 1179, Address: 0x24e22c, Func Offset: 0x1dc
	// Line 1177, Address: 0x24e234, Func Offset: 0x1e4
	// Line 1178, Address: 0x24e23c, Func Offset: 0x1ec
	// Line 1179, Address: 0x24e24c, Func Offset: 0x1fc
	// Line 1181, Address: 0x24e260, Func Offset: 0x210
	// Line 1182, Address: 0x24e264, Func Offset: 0x214
	// Line 1189, Address: 0x24e268, Func Offset: 0x218
	// Line 1191, Address: 0x24e274, Func Offset: 0x224
	// Line 1195, Address: 0x24e298, Func Offset: 0x248
	// Line 1191, Address: 0x24e2a4, Func Offset: 0x254
	// Line 1192, Address: 0x24e2a8, Func Offset: 0x258
	// Line 1193, Address: 0x24e2b0, Func Offset: 0x260
	// Line 1194, Address: 0x24e2b8, Func Offset: 0x268
	// Line 1195, Address: 0x24e2c0, Func Offset: 0x270
	// Line 1196, Address: 0x24e2d0, Func Offset: 0x280
	// Line 1191, Address: 0x24e2e0, Func Offset: 0x290
	// Line 1192, Address: 0x24e2e8, Func Offset: 0x298
	// Line 1193, Address: 0x24e308, Func Offset: 0x2b8
	// Line 1194, Address: 0x24e320, Func Offset: 0x2d0
	// Line 1195, Address: 0x24e338, Func Offset: 0x2e8
	// Line 1196, Address: 0x24e360, Func Offset: 0x310
	// Line 1197, Address: 0x24e388, Func Offset: 0x338
	// Line 1198, Address: 0x24e390, Func Offset: 0x340
	// Line 1199, Address: 0x24e398, Func Offset: 0x348
	// Line 1200, Address: 0x24e3a0, Func Offset: 0x350
	// Line 1202, Address: 0x24e3a8, Func Offset: 0x358
	// Line 1204, Address: 0x24e3b4, Func Offset: 0x364
	// Line 1205, Address: 0x24e3dc, Func Offset: 0x38c
	// Line 1208, Address: 0x24e400, Func Offset: 0x3b0
	// Func End, Address: 0x24e408, Func Offset: 0x3b8
	scePrintf("bhEff_Sub353 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24e410
void bhEff_Sub354(O_WRK* op)
{
	NJS_POINT3 p2;
	NJS_POINT3 p1;
	NJS_POINT3 ofs;
	//_anon11* owk;
	unsigned int argb_tbl[2];
	//_anon31 uvinfo[29];
	//_anon4* anim_tbl[4];
	// Line 1226, Address: 0x24e410, Func Offset: 0
	// Line 1295, Address: 0x24e428, Func Offset: 0x18
	// Line 1226, Address: 0x24e42c, Func Offset: 0x1c
	// Line 1295, Address: 0x24e430, Func Offset: 0x20
	// Line 1226, Address: 0x24e434, Func Offset: 0x24
	// Line 1295, Address: 0x24e438, Func Offset: 0x28
	// Line 1301, Address: 0x24e448, Func Offset: 0x38
	// Line 1305, Address: 0x24e474, Func Offset: 0x64
	// Line 1306, Address: 0x24e47c, Func Offset: 0x6c
	// Line 1308, Address: 0x24e484, Func Offset: 0x74
	// Line 1323, Address: 0x24e48c, Func Offset: 0x7c
	// Line 1315, Address: 0x24e494, Func Offset: 0x84
	// Line 1328, Address: 0x24e498, Func Offset: 0x88
	// Line 1308, Address: 0x24e49c, Func Offset: 0x8c
	// Line 1309, Address: 0x24e4a4, Func Offset: 0x94
	// Line 1328, Address: 0x24e4a8, Func Offset: 0x98
	// Line 1309, Address: 0x24e4ac, Func Offset: 0x9c
	// Line 1310, Address: 0x24e4b4, Func Offset: 0xa4
	// Line 1312, Address: 0x24e4b8, Func Offset: 0xa8
	// Line 1313, Address: 0x24e4c0, Func Offset: 0xb0
	// Line 1315, Address: 0x24e4d0, Func Offset: 0xc0
	// Line 1316, Address: 0x24e4d4, Func Offset: 0xc4
	// Line 1318, Address: 0x24e4d8, Func Offset: 0xc8
	// Line 1319, Address: 0x24e4e0, Func Offset: 0xd0
	// Line 1320, Address: 0x24e4e8, Func Offset: 0xd8
	// Line 1322, Address: 0x24e4f0, Func Offset: 0xe0
	// Line 1323, Address: 0x24e4f8, Func Offset: 0xe8
	// Line 1325, Address: 0x24e504, Func Offset: 0xf4
	// Line 1326, Address: 0x24e50c, Func Offset: 0xfc
	// Line 1328, Address: 0x24e510, Func Offset: 0x100
	// Line 1330, Address: 0x24e514, Func Offset: 0x104
	// Line 1333, Address: 0x24e520, Func Offset: 0x110
	// Line 1334, Address: 0x24e52c, Func Offset: 0x11c
	// Line 1336, Address: 0x24e538, Func Offset: 0x128
	// Line 1337, Address: 0x24e540, Func Offset: 0x130
	// Line 1338, Address: 0x24e548, Func Offset: 0x138
	// Line 1346, Address: 0x24e554, Func Offset: 0x144
	// Line 1350, Address: 0x24e560, Func Offset: 0x150
	// Line 1352, Address: 0x24e570, Func Offset: 0x160
	// Line 1353, Address: 0x24e580, Func Offset: 0x170
	// Line 1361, Address: 0x24e590, Func Offset: 0x180
	// Line 1363, Address: 0x24e59c, Func Offset: 0x18c
	// Line 1365, Address: 0x24e5c8, Func Offset: 0x1b8
	// Line 1376, Address: 0x24e5d4, Func Offset: 0x1c4
	// Line 1377, Address: 0x24e5e0, Func Offset: 0x1d0
	// Line 1378, Address: 0x24e5e4, Func Offset: 0x1d4
	// Line 1377, Address: 0x24e5e8, Func Offset: 0x1d8
	// Line 1376, Address: 0x24e5ec, Func Offset: 0x1dc
	// Line 1377, Address: 0x24e5f0, Func Offset: 0x1e0
	// Line 1376, Address: 0x24e5f4, Func Offset: 0x1e4
	// Line 1382, Address: 0x24e5f8, Func Offset: 0x1e8
	// Line 1376, Address: 0x24e5fc, Func Offset: 0x1ec
	// Line 1377, Address: 0x24e600, Func Offset: 0x1f0
	// Line 1378, Address: 0x24e608, Func Offset: 0x1f8
	// Line 1377, Address: 0x24e60c, Func Offset: 0x1fc
	// Line 1378, Address: 0x24e614, Func Offset: 0x204
	// Line 1381, Address: 0x24e628, Func Offset: 0x218
	// Line 1382, Address: 0x24e648, Func Offset: 0x238
	// Line 1384, Address: 0x24e650, Func Offset: 0x240
	// Line 1385, Address: 0x24e6b8, Func Offset: 0x2a8
	// Line 1386, Address: 0x24e724, Func Offset: 0x314
	// Line 1388, Address: 0x24e728, Func Offset: 0x318
	// Line 1389, Address: 0x24e73c, Func Offset: 0x32c
	// Line 1390, Address: 0x24e748, Func Offset: 0x338
	// Line 1391, Address: 0x24e74c, Func Offset: 0x33c
	// Line 1389, Address: 0x24e750, Func Offset: 0x340
	// Line 1393, Address: 0x24e754, Func Offset: 0x344
	// Line 1389, Address: 0x24e758, Func Offset: 0x348
	// Line 1390, Address: 0x24e760, Func Offset: 0x350
	// Line 1391, Address: 0x24e778, Func Offset: 0x368
	// Line 1393, Address: 0x24e78c, Func Offset: 0x37c
	// Line 1394, Address: 0x24e794, Func Offset: 0x384
	// Line 1396, Address: 0x24e7a4, Func Offset: 0x394
	// Line 1397, Address: 0x24e7ac, Func Offset: 0x39c
	// Line 1398, Address: 0x24e7b4, Func Offset: 0x3a4
	// Line 1401, Address: 0x24e7bc, Func Offset: 0x3ac
	// Func End, Address: 0x24e7e0, Func Offset: 0x3d0
	scePrintf("bhEff_Sub354 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24e7e0
void bhEff_Sub355(O_WRK* op)
{
	// Line 1422, Address: 0x24e7e0, Func Offset: 0
	// Line 1425, Address: 0x24e80c, Func Offset: 0x2c
	// Line 1426, Address: 0x24e814, Func Offset: 0x34
	// Line 1429, Address: 0x24e818, Func Offset: 0x38
	// Line 1430, Address: 0x24e81c, Func Offset: 0x3c
	// Line 1432, Address: 0x24e820, Func Offset: 0x40
	// Line 1426, Address: 0x24e824, Func Offset: 0x44
	// Line 1429, Address: 0x24e830, Func Offset: 0x50
	// Line 1430, Address: 0x24e834, Func Offset: 0x54
	// Line 1432, Address: 0x24e838, Func Offset: 0x58
	// Line 1434, Address: 0x24e83c, Func Offset: 0x5c
	// Line 1442, Address: 0x24e840, Func Offset: 0x60
	// Line 1432, Address: 0x24e844, Func Offset: 0x64
	// Line 1433, Address: 0x24e84c, Func Offset: 0x6c
	// Line 1434, Address: 0x24e850, Func Offset: 0x70
	// Line 1435, Address: 0x24e854, Func Offset: 0x74
	// Line 1436, Address: 0x24e858, Func Offset: 0x78
	// Line 1438, Address: 0x24e85c, Func Offset: 0x7c
	// Line 1439, Address: 0x24e864, Func Offset: 0x84
	// Line 1440, Address: 0x24e86c, Func Offset: 0x8c
	// Line 1441, Address: 0x24e870, Func Offset: 0x90
	// Line 1442, Address: 0x24e874, Func Offset: 0x94
	// Line 1443, Address: 0x24e878, Func Offset: 0x98
	// Line 1444, Address: 0x24e87c, Func Offset: 0x9c
	// Line 1445, Address: 0x24e884, Func Offset: 0xa4
	// Line 1446, Address: 0x24e88c, Func Offset: 0xac
	// Line 1447, Address: 0x24e894, Func Offset: 0xb4
	// Line 1449, Address: 0x24e89c, Func Offset: 0xbc
	// Line 1452, Address: 0x24e8a8, Func Offset: 0xc8
	// Line 1453, Address: 0x24e8b4, Func Offset: 0xd4
	// Line 1455, Address: 0x24e8c0, Func Offset: 0xe0
	// Line 1456, Address: 0x24e8c8, Func Offset: 0xe8
	// Line 1464, Address: 0x24e8d4, Func Offset: 0xf4
	// Line 1466, Address: 0x24e8dc, Func Offset: 0xfc
	// Line 1464, Address: 0x24e8e4, Func Offset: 0x104
	// Line 1465, Address: 0x24e8ec, Func Offset: 0x10c
	// Line 1466, Address: 0x24e8fc, Func Offset: 0x11c
	// Line 1468, Address: 0x24e910, Func Offset: 0x130
	// Line 1475, Address: 0x24e914, Func Offset: 0x134
	// Line 1477, Address: 0x24e92c, Func Offset: 0x14c
	// Line 1482, Address: 0x24e930, Func Offset: 0x150
	// Line 1484, Address: 0x24e93c, Func Offset: 0x15c
	// Line 1486, Address: 0x24e948, Func Offset: 0x168
	// Line 1487, Address: 0x24e970, Func Offset: 0x190
	// Line 1490, Address: 0x24e994, Func Offset: 0x1b4
	// Func End, Address: 0x24e99c, Func Offset: 0x1bc
	scePrintf("bhEff_Sub355 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24e9a0
void bhEff_Sub356(O_WRK* op)
{
	// Line 1508, Address: 0x24e9a0, Func Offset: 0
	// Line 1516, Address: 0x24e9ac, Func Offset: 0xc
	// Line 1527, Address: 0x24e9d8, Func Offset: 0x38
	// Line 1528, Address: 0x24e9e0, Func Offset: 0x40
	// Line 1532, Address: 0x24e9e8, Func Offset: 0x48
	// Line 1533, Address: 0x24e9f8, Func Offset: 0x58
	// Line 1534, Address: 0x24ea00, Func Offset: 0x60
	// Line 1545, Address: 0x24ea08, Func Offset: 0x68
	// Line 1546, Address: 0x24ea0c, Func Offset: 0x6c
	// Line 1550, Address: 0x24ea14, Func Offset: 0x74
	// Line 1551, Address: 0x24ea20, Func Offset: 0x80
	// Line 1552, Address: 0x24ea28, Func Offset: 0x88
	// Line 1553, Address: 0x24ea30, Func Offset: 0x90
	// Line 1556, Address: 0x24ea38, Func Offset: 0x98
	// Line 1559, Address: 0x24ea48, Func Offset: 0xa8
	// Line 1561, Address: 0x24ea54, Func Offset: 0xb4
	// Line 1562, Address: 0x24ea5c, Func Offset: 0xbc
	// Line 1564, Address: 0x24ea64, Func Offset: 0xc4
	// Line 1567, Address: 0x24ea6c, Func Offset: 0xcc
	// Line 1570, Address: 0x24ea7c, Func Offset: 0xdc
	// Line 1573, Address: 0x24ea88, Func Offset: 0xe8
	// Line 1577, Address: 0x24ea8c, Func Offset: 0xec
	// Func End, Address: 0x24ea9c, Func Offset: 0xfc
	scePrintf("bhEff_Sub356 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24eaa0
void bhEff_Sub357()
{
	// Line 1581, Address: 0x24eaa0, Func Offset: 0
	// Func End, Address: 0x24eaa8, Func Offset: 0x8
	scePrintf("bhEff_Sub357 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24eab0
void bhEff_Sub360(O_WRK* op)
{
	//_anon4* anim_tbl[2];
	//_anon31* blood_uvinfo[2];
	// Line 1598, Address: 0x24eab0, Func Offset: 0
	// Line 1637, Address: 0x24eab4, Func Offset: 0x4
	// Line 1598, Address: 0x24eabc, Func Offset: 0xc
	// Line 1637, Address: 0x24eac0, Func Offset: 0x10
	// Line 1642, Address: 0x24eac8, Func Offset: 0x18
	// Line 1637, Address: 0x24ead4, Func Offset: 0x24
	// Line 1642, Address: 0x24ead8, Func Offset: 0x28
	// Line 1651, Address: 0x24eae0, Func Offset: 0x30
	// Line 1654, Address: 0x24eb0c, Func Offset: 0x5c
	// Line 1655, Address: 0x24eb18, Func Offset: 0x68
	// Line 1658, Address: 0x24eb1c, Func Offset: 0x6c
	// Line 1660, Address: 0x24eb20, Func Offset: 0x70
	// Line 1661, Address: 0x24eb24, Func Offset: 0x74
	// Line 1655, Address: 0x24eb28, Func Offset: 0x78
	// Line 1658, Address: 0x24eb34, Func Offset: 0x84
	// Line 1660, Address: 0x24eb38, Func Offset: 0x88
	// Line 1661, Address: 0x24eb3c, Func Offset: 0x8c
	// Line 1666, Address: 0x24eb40, Func Offset: 0x90
	// Line 1661, Address: 0x24eb44, Func Offset: 0x94
	// Line 1662, Address: 0x24eb4c, Func Offset: 0x9c
	// Line 1663, Address: 0x24eb58, Func Offset: 0xa8
	// Line 1664, Address: 0x24eb5c, Func Offset: 0xac
	// Line 1665, Address: 0x24eb60, Func Offset: 0xb0
	// Line 1666, Address: 0x24eb64, Func Offset: 0xb4
	// Line 1667, Address: 0x24eb68, Func Offset: 0xb8
	// Line 1668, Address: 0x24eb6c, Func Offset: 0xbc
	// Line 1669, Address: 0x24eb70, Func Offset: 0xc0
	// Line 1672, Address: 0x24eb7c, Func Offset: 0xcc
	// Line 1673, Address: 0x24eb88, Func Offset: 0xd8
	// Line 1675, Address: 0x24eb94, Func Offset: 0xe4
	// Line 1676, Address: 0x24eb9c, Func Offset: 0xec
	// Line 1688, Address: 0x24eba8, Func Offset: 0xf8
	// Line 1690, Address: 0x24ebb4, Func Offset: 0x104
	// Line 1692, Address: 0x24ebd0, Func Offset: 0x120
	// Func End, Address: 0x24ebdc, Func Offset: 0x12c
	scePrintf("bhEff_Sub360 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24ebe0
void bhEff_Sub361(O_WRK* op)
{
	//_anon4* anim_tbl[2];
	//_anon31* blood_uvinfo[2];
	// Line 1711, Address: 0x24ebe0, Func Offset: 0
	// Line 1750, Address: 0x24ebe4, Func Offset: 0x4
	// Line 1711, Address: 0x24ebec, Func Offset: 0xc
	// Line 1750, Address: 0x24ebf0, Func Offset: 0x10
	// Line 1755, Address: 0x24ebf8, Func Offset: 0x18
	// Line 1750, Address: 0x24ec04, Func Offset: 0x24
	// Line 1755, Address: 0x24ec08, Func Offset: 0x28
	// Line 1764, Address: 0x24ec10, Func Offset: 0x30
	// Line 1767, Address: 0x24ec3c, Func Offset: 0x5c
	// Line 1768, Address: 0x24ec48, Func Offset: 0x68
	// Line 1770, Address: 0x24ec58, Func Offset: 0x78
	// Line 1771, Address: 0x24ec64, Func Offset: 0x84
	// Line 1774, Address: 0x24ec68, Func Offset: 0x88
	// Line 1776, Address: 0x24ec6c, Func Offset: 0x8c
	// Line 1777, Address: 0x24ec70, Func Offset: 0x90
	// Line 1771, Address: 0x24ec74, Func Offset: 0x94
	// Line 1774, Address: 0x24ec80, Func Offset: 0xa0
	// Line 1776, Address: 0x24ec84, Func Offset: 0xa4
	// Line 1777, Address: 0x24ec88, Func Offset: 0xa8
	// Line 1782, Address: 0x24ec8c, Func Offset: 0xac
	// Line 1777, Address: 0x24ec90, Func Offset: 0xb0
	// Line 1778, Address: 0x24ec98, Func Offset: 0xb8
	// Line 1779, Address: 0x24eca4, Func Offset: 0xc4
	// Line 1780, Address: 0x24eca8, Func Offset: 0xc8
	// Line 1781, Address: 0x24ecac, Func Offset: 0xcc
	// Line 1782, Address: 0x24ecb0, Func Offset: 0xd0
	// Line 1784, Address: 0x24ecb4, Func Offset: 0xd4
	// Line 1785, Address: 0x24ecbc, Func Offset: 0xdc
	// Line 1786, Address: 0x24ecc0, Func Offset: 0xe0
	// Line 1787, Address: 0x24ecc8, Func Offset: 0xe8
	// Line 1790, Address: 0x24ecd0, Func Offset: 0xf0
	// Line 1791, Address: 0x24ecdc, Func Offset: 0xfc
	// Line 1793, Address: 0x24ece8, Func Offset: 0x108
	// Line 1794, Address: 0x24ecec, Func Offset: 0x10c
	// Line 1805, Address: 0x24ecf8, Func Offset: 0x118
	// Line 1807, Address: 0x24ed04, Func Offset: 0x124
	// Line 1809, Address: 0x24ed20, Func Offset: 0x140
	// Func End, Address: 0x24ed2c, Func Offset: 0x14c
	scePrintf("bhEff_Sub361 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24ed30
void bhEff_Sub362(O_WRK* op)
{
	NJS_POINT3 n;
	NJS_POINT3 p2;
	NJS_POINT3 p1;
	float eff_sub362_tbl[3][1];
	//_anon4* anim_tbl[5];
	//_anon31 bl00_uvinfo[48];
	// Line 1827, Address: 0x24ed30, Func Offset: 0
	// Line 1927, Address: 0x24ed3c, Func Offset: 0xc
	// Line 1827, Address: 0x24ed40, Func Offset: 0x10
	// Line 1927, Address: 0x24ed48, Func Offset: 0x18
	// Line 1935, Address: 0x24ed58, Func Offset: 0x28
	// Line 1927, Address: 0x24ed64, Func Offset: 0x34
	// Line 1935, Address: 0x24ed68, Func Offset: 0x38
	// Line 1927, Address: 0x24ed6c, Func Offset: 0x3c
	// Line 1935, Address: 0x24ed70, Func Offset: 0x40
	// Line 1948, Address: 0x24ed78, Func Offset: 0x48
	// Line 1935, Address: 0x24ed7c, Func Offset: 0x4c
	// Line 1948, Address: 0x24ed84, Func Offset: 0x54
	// Line 1951, Address: 0x24edb8, Func Offset: 0x88
	// Line 1952, Address: 0x24edc4, Func Offset: 0x94
	// Line 1955, Address: 0x24edc8, Func Offset: 0x98
	// Line 1957, Address: 0x24edcc, Func Offset: 0x9c
	// Line 1952, Address: 0x24edd0, Func Offset: 0xa0
	// Line 1955, Address: 0x24eddc, Func Offset: 0xac
	// Line 1956, Address: 0x24ede0, Func Offset: 0xb0
	// Line 1957, Address: 0x24ede4, Func Offset: 0xb4
	// Line 1958, Address: 0x24edf0, Func Offset: 0xc0
	// Line 1959, Address: 0x24edfc, Func Offset: 0xcc
	// Line 1960, Address: 0x24ee00, Func Offset: 0xd0
	// Line 1962, Address: 0x24ee04, Func Offset: 0xd4
	// Line 1964, Address: 0x24ee20, Func Offset: 0xf0
	// Line 1962, Address: 0x24ee24, Func Offset: 0xf4
	// Line 1963, Address: 0x24ee28, Func Offset: 0xf8
	// Line 1964, Address: 0x24ee2c, Func Offset: 0xfc
	// Line 1965, Address: 0x24ee30, Func Offset: 0x100
	// Line 1968, Address: 0x24ee38, Func Offset: 0x108
	// Line 1969, Address: 0x24ee68, Func Offset: 0x138
	// Line 1972, Address: 0x24ee74, Func Offset: 0x144
	// Line 1973, Address: 0x24ee80, Func Offset: 0x150
	// Line 1976, Address: 0x24ee8c, Func Offset: 0x15c
	// Line 1975, Address: 0x24ee90, Func Offset: 0x160
	// Line 1976, Address: 0x24ee94, Func Offset: 0x164
	// Line 1977, Address: 0x24ee98, Func Offset: 0x168
	// Line 1985, Address: 0x24eea4, Func Offset: 0x174
	// Line 1987, Address: 0x24eeb4, Func Offset: 0x184
	// Line 1988, Address: 0x24eecc, Func Offset: 0x19c
	// Line 1989, Address: 0x24eef4, Func Offset: 0x1c4
	// Line 1990, Address: 0x24ef0c, Func Offset: 0x1dc
	// Line 1993, Address: 0x24ef18, Func Offset: 0x1e8
	// Line 1995, Address: 0x24ef28, Func Offset: 0x1f8
	// Line 1996, Address: 0x24ef30, Func Offset: 0x200
	// Line 2000, Address: 0x24ef38, Func Offset: 0x208
	// Line 2001, Address: 0x24ef3c, Func Offset: 0x20c
	// Line 2005, Address: 0x24ef44, Func Offset: 0x214
	// Line 2006, Address: 0x24ef48, Func Offset: 0x218
	// Line 2000, Address: 0x24ef4c, Func Offset: 0x21c
	// Line 2001, Address: 0x24ef50, Func Offset: 0x220
	// Line 2009, Address: 0x24ef54, Func Offset: 0x224
	// Line 2001, Address: 0x24ef60, Func Offset: 0x230
	// Line 2009, Address: 0x24ef64, Func Offset: 0x234
	// Line 2001, Address: 0x24ef68, Func Offset: 0x238
	// Line 2002, Address: 0x24ef6c, Func Offset: 0x23c
	// Line 2004, Address: 0x24ef74, Func Offset: 0x244
	// Line 2005, Address: 0x24ef7c, Func Offset: 0x24c
	// Line 2006, Address: 0x24ef88, Func Offset: 0x258
	// Line 2009, Address: 0x24ef8c, Func Offset: 0x25c
	// Line 2011, Address: 0x24ef9c, Func Offset: 0x26c
	// Line 2012, Address: 0x24efa0, Func Offset: 0x270
	// Line 2015, Address: 0x24efa8, Func Offset: 0x278
	// Line 2011, Address: 0x24efac, Func Offset: 0x27c
	// Line 2012, Address: 0x24efb0, Func Offset: 0x280
	// Line 2013, Address: 0x24efbc, Func Offset: 0x28c
	// Line 2015, Address: 0x24efc0, Func Offset: 0x290
	// Line 2016, Address: 0x24efc8, Func Offset: 0x298
	// Line 2017, Address: 0x24efd0, Func Offset: 0x2a0
	// Line 2019, Address: 0x24f004, Func Offset: 0x2d4
	// Line 2020, Address: 0x24f008, Func Offset: 0x2d8
	// Line 2021, Address: 0x24f00c, Func Offset: 0x2dc
	// Line 2022, Address: 0x24f010, Func Offset: 0x2e0
	// Line 2023, Address: 0x24f014, Func Offset: 0x2e4
	// Line 2024, Address: 0x24f01c, Func Offset: 0x2ec
	// Line 2028, Address: 0x24f024, Func Offset: 0x2f4
	// Line 2029, Address: 0x24f02c, Func Offset: 0x2fc
	// Line 2030, Address: 0x24f030, Func Offset: 0x300
	// Line 2034, Address: 0x24f034, Func Offset: 0x304
	// Line 2036, Address: 0x24f054, Func Offset: 0x324
	// Line 2038, Address: 0x24f064, Func Offset: 0x334
	// Line 2039, Address: 0x24f084, Func Offset: 0x354
	// Line 2042, Address: 0x24f08c, Func Offset: 0x35c
	// Line 2045, Address: 0x24f0ac, Func Offset: 0x37c
	// Line 2046, Address: 0x24f0b4, Func Offset: 0x384
	// Line 2049, Address: 0x24f0bc, Func Offset: 0x38c
	// Line 2050, Address: 0x24f0c4, Func Offset: 0x394
	// Line 2049, Address: 0x24f0cc, Func Offset: 0x39c
	// Line 2050, Address: 0x24f0d4, Func Offset: 0x3a4
	// Line 2053, Address: 0x24f0e8, Func Offset: 0x3b8
	// Line 2055, Address: 0x24f0f0, Func Offset: 0x3c0
	// Line 2056, Address: 0x24f0fc, Func Offset: 0x3cc
	// Line 2057, Address: 0x24f118, Func Offset: 0x3e8
	// Line 2059, Address: 0x24f124, Func Offset: 0x3f4
	// Line 2061, Address: 0x24f140, Func Offset: 0x410
	// Line 2063, Address: 0x24f150, Func Offset: 0x420
	// Line 2064, Address: 0x24f170, Func Offset: 0x440
	// Line 2067, Address: 0x24f178, Func Offset: 0x448
	// Line 2070, Address: 0x24f198, Func Offset: 0x468
	// Line 2085, Address: 0x24f1a4, Func Offset: 0x474
	// Line 2087, Address: 0x24f1b0, Func Offset: 0x480
	// Line 2089, Address: 0x24f1d4, Func Offset: 0x4a4
	// Func End, Address: 0x24f1ec, Func Offset: 0x4bc
	scePrintf("bhEff_Sub362 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24f1f0
void bhEff_Sub363(O_WRK* op)
{
	//_anon31 eff_uvinfo[12];
	// Line 2106, Address: 0x24f1f0, Func Offset: 0
	// Line 2129, Address: 0x24f1fc, Func Offset: 0xc
	// Line 2132, Address: 0x24f228, Func Offset: 0x38
	// Line 2133, Address: 0x24f234, Func Offset: 0x44
	// Line 2136, Address: 0x24f238, Func Offset: 0x48
	// Line 2137, Address: 0x24f23c, Func Offset: 0x4c
	// Line 2138, Address: 0x24f240, Func Offset: 0x50
	// Line 2133, Address: 0x24f244, Func Offset: 0x54
	// Line 2136, Address: 0x24f250, Func Offset: 0x60
	// Line 2137, Address: 0x24f254, Func Offset: 0x64
	// Line 2138, Address: 0x24f258, Func Offset: 0x68
	// Line 2139, Address: 0x24f264, Func Offset: 0x74
	// Line 2141, Address: 0x24f270, Func Offset: 0x80
	// Line 2142, Address: 0x24f290, Func Offset: 0xa0
	// Line 2144, Address: 0x24f29c, Func Offset: 0xac
	// Line 2146, Address: 0x24f2a0, Func Offset: 0xb0
	// Line 2147, Address: 0x24f2b8, Func Offset: 0xc8
	// Line 2148, Address: 0x24f2dc, Func Offset: 0xec
	// Line 2149, Address: 0x24f2ec, Func Offset: 0xfc
	// Line 2151, Address: 0x24f314, Func Offset: 0x124
	// Line 2153, Address: 0x24f338, Func Offset: 0x148
	// Line 2154, Address: 0x24f340, Func Offset: 0x150
	// Line 2155, Address: 0x24f344, Func Offset: 0x154
	// Line 2156, Address: 0x24f350, Func Offset: 0x160
	// Line 2161, Address: 0x24f35c, Func Offset: 0x16c
	// Line 2164, Address: 0x24f368, Func Offset: 0x178
	// Line 2167, Address: 0x24f374, Func Offset: 0x184
	// Line 2168, Address: 0x24f37c, Func Offset: 0x18c
	// Line 2167, Address: 0x24f384, Func Offset: 0x194
	// Line 2168, Address: 0x24f388, Func Offset: 0x198
	// Line 2171, Address: 0x24f39c, Func Offset: 0x1ac
	// Line 2173, Address: 0x24f3c0, Func Offset: 0x1d0
	// Line 2174, Address: 0x24f3e8, Func Offset: 0x1f8
	// Line 2175, Address: 0x24f3f0, Func Offset: 0x200
	// Line 2178, Address: 0x24f3f8, Func Offset: 0x208
	// Line 2181, Address: 0x24f410, Func Offset: 0x220
	// Line 2182, Address: 0x24f428, Func Offset: 0x238
	// Line 2183, Address: 0x24f440, Func Offset: 0x250
	// Line 2215, Address: 0x24f448, Func Offset: 0x258
	// Line 2218, Address: 0x24f450, Func Offset: 0x260
	// Line 2226, Address: 0x24f458, Func Offset: 0x268
	// Line 2228, Address: 0x24f464, Func Offset: 0x274
	// Line 2229, Address: 0x24f46c, Func Offset: 0x27c
	// Line 2228, Address: 0x24f474, Func Offset: 0x284
	// Line 2229, Address: 0x24f47c, Func Offset: 0x28c
	// Line 2231, Address: 0x24f490, Func Offset: 0x2a0
	// Line 2233, Address: 0x24f494, Func Offset: 0x2a4
	// Line 2234, Address: 0x24f4a0, Func Offset: 0x2b0
	// Line 2237, Address: 0x24f4a8, Func Offset: 0x2b8
	// Line 2240, Address: 0x24f4b0, Func Offset: 0x2c0
	// Line 2241, Address: 0x24f4d0, Func Offset: 0x2e0
	// Func End, Address: 0x24f4e0, Func Offset: 0x2f0
	scePrintf("bhEff_Sub363 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24f4e0
void bhEff_Sub364(O_WRK* op)
{
	// Line 2262, Address: 0x24f4e0, Func Offset: 0
	// Line 2269, Address: 0x24f500, Func Offset: 0x20
	// Line 2270, Address: 0x24f508, Func Offset: 0x28
	// Line 2272, Address: 0x24f510, Func Offset: 0x30
	// Line 2279, Address: 0x24f518, Func Offset: 0x38
	// Line 2272, Address: 0x24f520, Func Offset: 0x40
	// Line 2273, Address: 0x24f528, Func Offset: 0x48
	// Line 2274, Address: 0x24f52c, Func Offset: 0x4c
	// Line 2275, Address: 0x24f530, Func Offset: 0x50
	// Line 2276, Address: 0x24f534, Func Offset: 0x54
	// Line 2277, Address: 0x24f538, Func Offset: 0x58
	// Line 2279, Address: 0x24f53c, Func Offset: 0x5c
	// Line 2280, Address: 0x24f540, Func Offset: 0x60
	// Line 2283, Address: 0x24f54c, Func Offset: 0x6c
	// Line 2285, Address: 0x24f55c, Func Offset: 0x7c
	// Line 2290, Address: 0x24f560, Func Offset: 0x80
	// Line 2292, Address: 0x24f56c, Func Offset: 0x8c
	// Line 2293, Address: 0x24f594, Func Offset: 0xb4
	// Line 2298, Address: 0x24f5b8, Func Offset: 0xd8
	// Func End, Address: 0x24f5c0, Func Offset: 0xe0
	scePrintf("bhEff_Sub364 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24f5c0
void bhEff_Sub365(O_WRK* op)
{
	int i;
	NJS_POINT3* avec;
	NJS_POINT3* vpos;
	//_anon6* effect;
	// Line 2322, Address: 0x24f5c0, Func Offset: 0
	// Line 2328, Address: 0x24f5c4, Func Offset: 0x4
	// Line 2324, Address: 0x24f5cc, Func Offset: 0xc
	// Line 2328, Address: 0x24f5d0, Func Offset: 0x10
	// Line 2331, Address: 0x24f5f4, Func Offset: 0x34
	// Line 2332, Address: 0x24f600, Func Offset: 0x40
	// Line 2333, Address: 0x24f608, Func Offset: 0x48
	// Line 2335, Address: 0x24f60c, Func Offset: 0x4c
	// Line 2336, Address: 0x24f614, Func Offset: 0x54
	// Line 2337, Address: 0x24f618, Func Offset: 0x58
	// Line 2338, Address: 0x24f61c, Func Offset: 0x5c
	// Line 2339, Address: 0x24f620, Func Offset: 0x60
	// Line 2342, Address: 0x24f62c, Func Offset: 0x6c
	// Line 2343, Address: 0x24f638, Func Offset: 0x78
	// Line 2346, Address: 0x24f644, Func Offset: 0x84
	// Line 2345, Address: 0x24f648, Func Offset: 0x88
	// Line 2346, Address: 0x24f64c, Func Offset: 0x8c
	// Line 2347, Address: 0x24f650, Func Offset: 0x90
	// Line 2355, Address: 0x24f65c, Func Offset: 0x9c
	// Line 2357, Address: 0x24f670, Func Offset: 0xb0
	// Line 2362, Address: 0x24f678, Func Offset: 0xb8
	// Line 2357, Address: 0x24f67c, Func Offset: 0xbc
	// Line 2358, Address: 0x24f684, Func Offset: 0xc4
	// Line 2359, Address: 0x24f6a4, Func Offset: 0xe4
	// Line 2361, Address: 0x24f6ac, Func Offset: 0xec
	// Line 2359, Address: 0x24f6b0, Func Offset: 0xf0
	// Line 2360, Address: 0x24f6b8, Func Offset: 0xf8
	// Line 2362, Address: 0x24f6bc, Func Offset: 0xfc
	// Line 2364, Address: 0x24f6d0, Func Offset: 0x110
	// Line 2365, Address: 0x24f6dc, Func Offset: 0x11c
	// Line 2367, Address: 0x24f6ec, Func Offset: 0x12c
	// Line 2368, Address: 0x24f6f4, Func Offset: 0x134
	// Line 2367, Address: 0x24f6fc, Func Offset: 0x13c
	// Line 2368, Address: 0x24f704, Func Offset: 0x144
	// Line 2370, Address: 0x24f718, Func Offset: 0x158
	// Line 2371, Address: 0x24f71c, Func Offset: 0x15c
	// Line 2377, Address: 0x24f720, Func Offset: 0x160
	// Line 2379, Address: 0x24f72c, Func Offset: 0x16c
	// Line 2381, Address: 0x24f738, Func Offset: 0x178
	// Line 2382, Address: 0x24f760, Func Offset: 0x1a0
	// Line 2385, Address: 0x24f784, Func Offset: 0x1c4
	// Func End, Address: 0x24f78c, Func Offset: 0x1cc
	scePrintf("bhEff_Sub365 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24f790
void bhEff_Sub366(O_WRK* op)
{
	int i;
	float* g;
	NJS_POINT3* vec;
	NJS_POINT3* vtx_p2;
	NJS_POINT3* vtx_p;
	//_anon9* effect;
	// Line 2411, Address: 0x24f790, Func Offset: 0
	// Line 2418, Address: 0x24f794, Func Offset: 0x4
	// Line 2413, Address: 0x24f79c, Func Offset: 0xc
	// Line 2414, Address: 0x24f7a0, Func Offset: 0x10
	// Line 2415, Address: 0x24f7a4, Func Offset: 0x14
	// Line 2418, Address: 0x24f7a8, Func Offset: 0x18
	// Line 2421, Address: 0x24f7cc, Func Offset: 0x3c
	// Line 2423, Address: 0x24f7d8, Func Offset: 0x48
	// Line 2424, Address: 0x24f7e0, Func Offset: 0x50
	// Line 2427, Address: 0x24f7e4, Func Offset: 0x54
	// Line 2428, Address: 0x24f7ec, Func Offset: 0x5c
	// Line 2429, Address: 0x24f7f0, Func Offset: 0x60
	// Line 2432, Address: 0x24f7f8, Func Offset: 0x68
	// Line 2433, Address: 0x24f800, Func Offset: 0x70
	// Line 2436, Address: 0x24f808, Func Offset: 0x78
	// Line 2437, Address: 0x24f810, Func Offset: 0x80
	// Line 2439, Address: 0x24f818, Func Offset: 0x88
	// Line 2440, Address: 0x24f820, Func Offset: 0x90
	// Line 2442, Address: 0x24f824, Func Offset: 0x94
	// Line 2443, Address: 0x24f82c, Func Offset: 0x9c
	// Line 2444, Address: 0x24f830, Func Offset: 0xa0
	// Line 2445, Address: 0x24f834, Func Offset: 0xa4
	// Line 2446, Address: 0x24f838, Func Offset: 0xa8
	// Line 2449, Address: 0x24f844, Func Offset: 0xb4
	// Line 2450, Address: 0x24f850, Func Offset: 0xc0
	// Line 2453, Address: 0x24f85c, Func Offset: 0xcc
	// Line 2452, Address: 0x24f860, Func Offset: 0xd0
	// Line 2453, Address: 0x24f864, Func Offset: 0xd4
	// Line 2454, Address: 0x24f868, Func Offset: 0xd8
	// Line 2462, Address: 0x24f874, Func Offset: 0xe4
	// Line 2464, Address: 0x24f878, Func Offset: 0xe8
	// Line 2462, Address: 0x24f88c, Func Offset: 0xfc
	// Line 2463, Address: 0x24f894, Func Offset: 0x104
	// Line 2464, Address: 0x24f898, Func Offset: 0x108
	// Line 2463, Address: 0x24f8a4, Func Offset: 0x114
	// Line 2464, Address: 0x24f8a8, Func Offset: 0x118
	// Line 2466, Address: 0x24f8b0, Func Offset: 0x120
	// Line 2467, Address: 0x24f8bc, Func Offset: 0x12c
	// Line 2468, Address: 0x24f8c4, Func Offset: 0x134
	// Line 2469, Address: 0x24f8cc, Func Offset: 0x13c
	// Line 2471, Address: 0x24f8d4, Func Offset: 0x144
	// Line 2472, Address: 0x24f8e4, Func Offset: 0x154
	// Line 2473, Address: 0x24f8fc, Func Offset: 0x16c
	// Line 2475, Address: 0x24f90c, Func Offset: 0x17c
	// Line 2477, Address: 0x24f920, Func Offset: 0x190
	// Line 2479, Address: 0x24f924, Func Offset: 0x194
	// Line 2480, Address: 0x24f928, Func Offset: 0x198
	// Line 2481, Address: 0x24f934, Func Offset: 0x1a4
	// Line 2482, Address: 0x24f940, Func Offset: 0x1b0
	// Line 2483, Address: 0x24f94c, Func Offset: 0x1bc
	// Line 2485, Address: 0x24f950, Func Offset: 0x1c0
	// Line 2486, Address: 0x24f954, Func Offset: 0x1c4
	// Line 2487, Address: 0x24f958, Func Offset: 0x1c8
	// Line 2488, Address: 0x24f95c, Func Offset: 0x1cc
	// Line 2489, Address: 0x24f960, Func Offset: 0x1d0
	// Line 2490, Address: 0x24f978, Func Offset: 0x1e8
	// Line 2492, Address: 0x24f984, Func Offset: 0x1f4
	// Line 2494, Address: 0x24f994, Func Offset: 0x204
	// Line 2495, Address: 0x24f9a0, Func Offset: 0x210
	// Line 2500, Address: 0x24f9ac, Func Offset: 0x21c
	// Line 2502, Address: 0x24f9bc, Func Offset: 0x22c
	// Line 2503, Address: 0x24f9cc, Func Offset: 0x23c
	// Line 2504, Address: 0x24f9d8, Func Offset: 0x248
	// Line 2506, Address: 0x24f9e8, Func Offset: 0x258
	// Line 2507, Address: 0x24f9ec, Func Offset: 0x25c
	// Line 2513, Address: 0x24f9f0, Func Offset: 0x260
	// Line 2515, Address: 0x24f9fc, Func Offset: 0x26c
	// Line 2517, Address: 0x24fa08, Func Offset: 0x278
	// Line 2518, Address: 0x24fa30, Func Offset: 0x2a0
	// Line 2521, Address: 0x24fa54, Func Offset: 0x2c4
	// Func End, Address: 0x24fa5c, Func Offset: 0x2cc
	scePrintf("bhEff_Sub366 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24fa60
void bhEff_Sub367(O_WRK* op)
{
	int i;
	int* rot_spd;
	int* rot;
	float* r;
	float* g;
	NJS_POINT3* vtx_p;
	//_anon17* effect;
	// Line 2540, Address: 0x24fa60, Func Offset: 0
	// Line 2551, Address: 0x24fa88, Func Offset: 0x28
	// Line 2560, Address: 0x24fa90, Func Offset: 0x30
	// Line 2553, Address: 0x24fa98, Func Offset: 0x38
	// Line 2555, Address: 0x24fa9c, Func Offset: 0x3c
	// Line 2556, Address: 0x24faa0, Func Offset: 0x40
	// Line 2557, Address: 0x24faa4, Func Offset: 0x44
	// Line 2560, Address: 0x24faa8, Func Offset: 0x48
	// Line 2563, Address: 0x24fac0, Func Offset: 0x60
	// Line 2564, Address: 0x24facc, Func Offset: 0x6c
	// Line 2565, Address: 0x24fad4, Func Offset: 0x74
	// Line 2567, Address: 0x24fad8, Func Offset: 0x78
	// Line 2568, Address: 0x24fae0, Func Offset: 0x80
	// Line 2569, Address: 0x24fae4, Func Offset: 0x84
	// Line 2570, Address: 0x24fae8, Func Offset: 0x88
	// Line 2571, Address: 0x24faec, Func Offset: 0x8c
	// Line 2574, Address: 0x24faf8, Func Offset: 0x98
	// Line 2576, Address: 0x24fafc, Func Offset: 0x9c
	// Line 2574, Address: 0x24fb00, Func Offset: 0xa0
	// Line 2575, Address: 0x24fb08, Func Offset: 0xa8
	// Line 2576, Address: 0x24fb10, Func Offset: 0xb0
	// Line 2578, Address: 0x24fb18, Func Offset: 0xb8
	// Line 2580, Address: 0x24fb28, Func Offset: 0xc8
	// Line 2581, Address: 0x24fb44, Func Offset: 0xe4
	// Line 2585, Address: 0x24fb54, Func Offset: 0xf4
	// Line 2586, Address: 0x24fb58, Func Offset: 0xf8
	// Line 2581, Address: 0x24fb5c, Func Offset: 0xfc
	// Line 2587, Address: 0x24fb60, Func Offset: 0x100
	// Line 2589, Address: 0x24fb64, Func Offset: 0x104
	// Line 2581, Address: 0x24fb68, Func Offset: 0x108
	// Line 2582, Address: 0x24fb70, Func Offset: 0x110
	// Line 2588, Address: 0x24fb80, Func Offset: 0x120
	// Line 2582, Address: 0x24fb84, Func Offset: 0x124
	// Line 2584, Address: 0x24fb90, Func Offset: 0x130
	// Line 2589, Address: 0x24fb94, Func Offset: 0x134
	// Line 2591, Address: 0x24fba8, Func Offset: 0x148
	// Line 2593, Address: 0x24fbb8, Func Offset: 0x158
	// Line 2594, Address: 0x24fbbc, Func Offset: 0x15c
	// Line 2599, Address: 0x24fbc0, Func Offset: 0x160
	// Line 2601, Address: 0x24fbcc, Func Offset: 0x16c
	// Line 2602, Address: 0x24fbf4, Func Offset: 0x194
	// Line 2604, Address: 0x24fc18, Func Offset: 0x1b8
	// Func End, Address: 0x24fc44, Func Offset: 0x1e4
	scePrintf("bhEff_Sub367 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24fc50
void bhEff_Sub368(O_WRK* op)
{
	//_anon31 uvinfo[1];
	// Line 2624, Address: 0x24fc50, Func Offset: 0
	// Line 2630, Address: 0x24fc58, Func Offset: 0x8
	// Line 2633, Address: 0x24fc90, Func Offset: 0x40
	// Line 2634, Address: 0x24fc9c, Func Offset: 0x4c
	// Line 2636, Address: 0x24fca0, Func Offset: 0x50
	// Line 2639, Address: 0x24fca4, Func Offset: 0x54
	// Line 2643, Address: 0x24fca8, Func Offset: 0x58
	// Line 2650, Address: 0x24fcac, Func Offset: 0x5c
	// Line 2634, Address: 0x24fcb0, Func Offset: 0x60
	// Line 2636, Address: 0x24fcbc, Func Offset: 0x6c
	// Line 2637, Address: 0x24fcc0, Func Offset: 0x70
	// Line 2638, Address: 0x24fcc4, Func Offset: 0x74
	// Line 2639, Address: 0x24fcc8, Func Offset: 0x78
	// Line 2640, Address: 0x24fccc, Func Offset: 0x7c
	// Line 2641, Address: 0x24fcd0, Func Offset: 0x80
	// Line 2642, Address: 0x24fcd4, Func Offset: 0x84
	// Line 2643, Address: 0x24fcd8, Func Offset: 0x88
	// Line 2644, Address: 0x24fcdc, Func Offset: 0x8c
	// Line 2645, Address: 0x24fce0, Func Offset: 0x90
	// Line 2646, Address: 0x24fce4, Func Offset: 0x94
	// Line 2647, Address: 0x24fce8, Func Offset: 0x98
	// Line 2650, Address: 0x24fcec, Func Offset: 0x9c
	// Line 2651, Address: 0x24fcf0, Func Offset: 0xa0
	// Line 2654, Address: 0x24fcf4, Func Offset: 0xa4
	// Line 2659, Address: 0x24fcfc, Func Offset: 0xac
	// Line 2654, Address: 0x24fd00, Func Offset: 0xb0
	// Line 2655, Address: 0x24fd08, Func Offset: 0xb8
	// Line 2656, Address: 0x24fd14, Func Offset: 0xc4
	// Line 2657, Address: 0x24fd18, Func Offset: 0xc8
	// Line 2658, Address: 0x24fd1c, Func Offset: 0xcc
	// Line 2659, Address: 0x24fd20, Func Offset: 0xd0
	// Line 2661, Address: 0x24fd24, Func Offset: 0xd4
	// Line 2662, Address: 0x24fd28, Func Offset: 0xd8
	// Line 2663, Address: 0x24fd30, Func Offset: 0xe0
	// Line 2666, Address: 0x24fd38, Func Offset: 0xe8
	// Line 2667, Address: 0x24fd44, Func Offset: 0xf4
	// Line 2669, Address: 0x24fd50, Func Offset: 0x100
	// Line 2670, Address: 0x24fd54, Func Offset: 0x104
	// Line 2678, Address: 0x24fd60, Func Offset: 0x110
	// Line 2680, Address: 0x24fd70, Func Offset: 0x120
	// Line 2681, Address: 0x24fd78, Func Offset: 0x128
	// Line 2683, Address: 0x24fd80, Func Offset: 0x130
	// Line 2691, Address: 0x24fd9c, Func Offset: 0x14c
	// Line 2693, Address: 0x24fda8, Func Offset: 0x158
	// Line 2695, Address: 0x24fdb8, Func Offset: 0x168
	// Func End, Address: 0x24fdc4, Func Offset: 0x174
	scePrintf("bhEff_Sub368 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24fdd0
void bhEff_Sub369(O_WRK* op)
{
	//_anon31 uvinfo[15];
	//_anon4* anim_tbl[2];
	// Line 2713, Address: 0x24fdd0, Func Offset: 0
	// Line 2782, Address: 0x24fddc, Func Offset: 0xc
	// Line 2785, Address: 0x24fe08, Func Offset: 0x38
	// Line 2786, Address: 0x24fe14, Func Offset: 0x44
	// Line 2789, Address: 0x24fe18, Func Offset: 0x48
	// Line 2790, Address: 0x24fe1c, Func Offset: 0x4c
	// Line 2792, Address: 0x24fe20, Func Offset: 0x50
	// Line 2786, Address: 0x24fe24, Func Offset: 0x54
	// Line 2789, Address: 0x24fe30, Func Offset: 0x60
	// Line 2790, Address: 0x24fe34, Func Offset: 0x64
	// Line 2792, Address: 0x24fe38, Func Offset: 0x68
	// Line 2798, Address: 0x24fe3c, Func Offset: 0x6c
	// Line 2792, Address: 0x24fe40, Func Offset: 0x70
	// Line 2793, Address: 0x24fe48, Func Offset: 0x78
	// Line 2794, Address: 0x24fe54, Func Offset: 0x84
	// Line 2795, Address: 0x24fe58, Func Offset: 0x88
	// Line 2796, Address: 0x24fe5c, Func Offset: 0x8c
	// Line 2797, Address: 0x24fe60, Func Offset: 0x90
	// Line 2798, Address: 0x24fe64, Func Offset: 0x94
	// Line 2800, Address: 0x24fe68, Func Offset: 0x98
	// Line 2801, Address: 0x24fe70, Func Offset: 0xa0
	// Line 2802, Address: 0x24fe74, Func Offset: 0xa4
	// Line 2803, Address: 0x24fe7c, Func Offset: 0xac
	// Line 2806, Address: 0x24fe84, Func Offset: 0xb4
	// Line 2807, Address: 0x24fe90, Func Offset: 0xc0
	// Line 2809, Address: 0x24fe9c, Func Offset: 0xcc
	// Line 2810, Address: 0x24fea0, Func Offset: 0xd0
	// Line 2818, Address: 0x24feac, Func Offset: 0xdc
	// Line 2819, Address: 0x24febc, Func Offset: 0xec
	// Line 2820, Address: 0x24fedc, Func Offset: 0x10c
	// Line 2821, Address: 0x24fefc, Func Offset: 0x12c
	// Line 2826, Address: 0x24ff0c, Func Offset: 0x13c
	// Line 2828, Address: 0x24ff18, Func Offset: 0x148
	// Line 2830, Address: 0x24ff44, Func Offset: 0x174
	// Func End, Address: 0x24ff54, Func Offset: 0x184
	scePrintf("bhEff_Sub369 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x24ff60
void bhEff_Sub370(O_WRK* op)
{
	int eno;
	NJS_POINT3 v2;
	NJS_POINT3 v1;
	//_anon23* eff_p;
	unsigned int bl_col[4];
	//_anon23 eff370_tbl[11];
	// Line 2870, Address: 0x24ff60, Func Offset: 0
	// Line 2889, Address: 0x24ff6c, Func Offset: 0xc
	// Line 2870, Address: 0x24ff70, Func Offset: 0x10
	// Line 2889, Address: 0x24ff74, Func Offset: 0x14
	// Line 2870, Address: 0x24ff78, Func Offset: 0x18
	// Line 2889, Address: 0x24ff7c, Func Offset: 0x1c
	// Line 2903, Address: 0x24ff8c, Func Offset: 0x2c
	// Line 2896, Address: 0x24ff90, Func Offset: 0x30
	// Line 2905, Address: 0x24ff98, Func Offset: 0x38
	// Line 2903, Address: 0x24ff9c, Func Offset: 0x3c
	// Line 2905, Address: 0x24ffa4, Func Offset: 0x44
	// Line 2903, Address: 0x24ffa8, Func Offset: 0x48
	// Line 2905, Address: 0x24ffac, Func Offset: 0x4c
	// Line 2908, Address: 0x24ffc4, Func Offset: 0x64
	// Line 2909, Address: 0x24ffc8, Func Offset: 0x68
	// Line 2930, Address: 0x24ffcc, Func Offset: 0x6c
	// Line 2931, Address: 0x24ffd0, Func Offset: 0x70
	// Line 2934, Address: 0x24ffdc, Func Offset: 0x7c
	// Line 2936, Address: 0x24ffec, Func Offset: 0x8c
	// Line 2938, Address: 0x24fff8, Func Offset: 0x98
	// Line 2944, Address: 0x24fffc, Func Offset: 0x9c
	// Line 2936, Address: 0x250000, Func Offset: 0xa0
	// Line 2937, Address: 0x25000c, Func Offset: 0xac
	// Line 2938, Address: 0x250024, Func Offset: 0xc4
	// Line 2939, Address: 0x250038, Func Offset: 0xd8
	// Line 2940, Address: 0x25004c, Func Offset: 0xec
	// Line 2941, Address: 0x250064, Func Offset: 0x104
	// Line 2942, Address: 0x25007c, Func Offset: 0x11c
	// Line 2944, Address: 0x250094, Func Offset: 0x134
	// Line 2946, Address: 0x2500b8, Func Offset: 0x158
	// Line 2949, Address: 0x2500c4, Func Offset: 0x164
	// Line 2952, Address: 0x2500d4, Func Offset: 0x174
	// Line 2954, Address: 0x2500fc, Func Offset: 0x19c
	// Line 2957, Address: 0x250104, Func Offset: 0x1a4
	// Line 2960, Address: 0x25012c, Func Offset: 0x1cc
	// Line 2963, Address: 0x250134, Func Offset: 0x1d4
	// Line 2965, Address: 0x250144, Func Offset: 0x1e4
	// Line 2970, Address: 0x250150, Func Offset: 0x1f0
	// Line 2971, Address: 0x250190, Func Offset: 0x230
	// Line 2972, Address: 0x2501b4, Func Offset: 0x254
	// Line 2976, Address: 0x2501bc, Func Offset: 0x25c
	// Line 2979, Address: 0x2501c4, Func Offset: 0x264
	// Line 2976, Address: 0x2501c8, Func Offset: 0x268
	// Line 2977, Address: 0x2501d4, Func Offset: 0x274
	// Line 2978, Address: 0x2501e8, Func Offset: 0x288
	// Line 2979, Address: 0x2501fc, Func Offset: 0x29c
	// Line 2981, Address: 0x25021c, Func Offset: 0x2bc
	// Line 2984, Address: 0x250224, Func Offset: 0x2c4
	// Line 2987, Address: 0x250230, Func Offset: 0x2d0
	// Line 2984, Address: 0x25023c, Func Offset: 0x2dc
	// Line 2985, Address: 0x250248, Func Offset: 0x2e8
	// Line 2986, Address: 0x250260, Func Offset: 0x300
	// Line 2987, Address: 0x250278, Func Offset: 0x318
	// Line 2990, Address: 0x250294, Func Offset: 0x334
	// Line 2992, Address: 0x2502a0, Func Offset: 0x340
	// Line 2994, Address: 0x2502c0, Func Offset: 0x360
	// Line 2995, Address: 0x2502e4, Func Offset: 0x384
	// Line 2994, Address: 0x2502f0, Func Offset: 0x390
	// Line 2995, Address: 0x2502f8, Func Offset: 0x398
	// Line 2996, Address: 0x2502fc, Func Offset: 0x39c
	// Line 2995, Address: 0x250308, Func Offset: 0x3a8
	// Line 2996, Address: 0x25030c, Func Offset: 0x3ac
	// Line 3000, Address: 0x250314, Func Offset: 0x3b4
	// Line 3002, Address: 0x250324, Func Offset: 0x3c4
	// Line 3008, Address: 0x250328, Func Offset: 0x3c8
	// Line 3002, Address: 0x25032c, Func Offset: 0x3cc
	// Line 3003, Address: 0x250330, Func Offset: 0x3d0
	// Line 3004, Address: 0x250338, Func Offset: 0x3d8
	// Line 3008, Address: 0x250340, Func Offset: 0x3e0
	// Line 3009, Address: 0x250368, Func Offset: 0x408
	// Line 3010, Address: 0x250378, Func Offset: 0x418
	// Line 3013, Address: 0x250380, Func Offset: 0x420
	// Line 3014, Address: 0x250388, Func Offset: 0x428
	// Line 3015, Address: 0x250390, Func Offset: 0x430
	// Line 3018, Address: 0x250398, Func Offset: 0x438
	// Line 3019, Address: 0x2503bc, Func Offset: 0x45c
	// Line 3020, Address: 0x2503d0, Func Offset: 0x470
	// Line 3021, Address: 0x2503e4, Func Offset: 0x484
	// Line 3022, Address: 0x2503f4, Func Offset: 0x494
	// Line 3023, Address: 0x250430, Func Offset: 0x4d0
	// Line 3024, Address: 0x25043c, Func Offset: 0x4dc
	// Line 3022, Address: 0x250448, Func Offset: 0x4e8
	// Line 3023, Address: 0x250454, Func Offset: 0x4f4
	// Line 3024, Address: 0x25045c, Func Offset: 0x4fc
	// Line 3027, Address: 0x250464, Func Offset: 0x504
	// Line 3029, Address: 0x25046c, Func Offset: 0x50c
	// Line 3030, Address: 0x250478, Func Offset: 0x518
	// Line 3032, Address: 0x25048c, Func Offset: 0x52c
	// Line 3037, Address: 0x250490, Func Offset: 0x530
	// Func End, Address: 0x2504a8, Func Offset: 0x548
	scePrintf("bhEff_Sub370 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2504b0
void bhEff_Sub371(O_WRK* op)
{
	//_anon31 uvinfo[32];
	//_anon4* anim_tbl[4];
	// Line 3057, Address: 0x2504b0, Func Offset: 0
	// Line 3126, Address: 0x2504b8, Func Offset: 0x8
	// Line 3129, Address: 0x2504e4, Func Offset: 0x34
	// Line 3130, Address: 0x2504f0, Func Offset: 0x40
	// Line 3133, Address: 0x2504f4, Func Offset: 0x44
	// Line 3134, Address: 0x2504f8, Func Offset: 0x48
	// Line 3136, Address: 0x2504fc, Func Offset: 0x4c
	// Line 3130, Address: 0x250500, Func Offset: 0x50
	// Line 3133, Address: 0x25050c, Func Offset: 0x5c
	// Line 3134, Address: 0x250510, Func Offset: 0x60
	// Line 3136, Address: 0x250514, Func Offset: 0x64
	// Line 3142, Address: 0x250518, Func Offset: 0x68
	// Line 3136, Address: 0x25051c, Func Offset: 0x6c
	// Line 3137, Address: 0x250524, Func Offset: 0x74
	// Line 3138, Address: 0x250530, Func Offset: 0x80
	// Line 3139, Address: 0x250534, Func Offset: 0x84
	// Line 3140, Address: 0x250538, Func Offset: 0x88
	// Line 3141, Address: 0x25053c, Func Offset: 0x8c
	// Line 3142, Address: 0x250540, Func Offset: 0x90
	// Line 3144, Address: 0x250544, Func Offset: 0x94
	// Line 3145, Address: 0x25054c, Func Offset: 0x9c
	// Line 3146, Address: 0x250550, Func Offset: 0xa0
	// Line 3147, Address: 0x250558, Func Offset: 0xa8
	// Line 3150, Address: 0x250560, Func Offset: 0xb0
	// Line 3151, Address: 0x25056c, Func Offset: 0xbc
	// Line 3153, Address: 0x250578, Func Offset: 0xc8
	// Line 3154, Address: 0x25057c, Func Offset: 0xcc
	// Line 3155, Address: 0x250580, Func Offset: 0xd0
	// Line 3163, Address: 0x25058c, Func Offset: 0xdc
	// Line 3165, Address: 0x25059c, Func Offset: 0xec
	// Line 3167, Address: 0x2505ac, Func Offset: 0xfc
	// Line 3168, Address: 0x2505c4, Func Offset: 0x114
	// Line 3169, Address: 0x2505ec, Func Offset: 0x13c
	// Line 3170, Address: 0x250600, Func Offset: 0x150
	// Line 3173, Address: 0x250608, Func Offset: 0x158
	// Line 3174, Address: 0x250620, Func Offset: 0x170
	// Line 3175, Address: 0x250648, Func Offset: 0x198
	// Line 3177, Address: 0x250660, Func Offset: 0x1b0
	// Line 3179, Address: 0x25066c, Func Offset: 0x1bc
	// Line 3181, Address: 0x250678, Func Offset: 0x1c8
	// Line 3183, Address: 0x250688, Func Offset: 0x1d8
	// Line 3184, Address: 0x250698, Func Offset: 0x1e8
	// Line 3186, Address: 0x2506a4, Func Offset: 0x1f4
	// Line 3189, Address: 0x2506ac, Func Offset: 0x1fc
	// Line 3191, Address: 0x2506bc, Func Offset: 0x20c
	// Line 3192, Address: 0x2506cc, Func Offset: 0x21c
	// Line 3199, Address: 0x2506dc, Func Offset: 0x22c
	// Line 3201, Address: 0x2506e8, Func Offset: 0x238
	// Line 3203, Address: 0x250710, Func Offset: 0x260
	// Func End, Address: 0x25071c, Func Offset: 0x26c
	scePrintf("bhEff_Sub371 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x250720
void bhEff_Sub372(O_WRK* op)
{
	//_anon31 uvinfo[13];
	//_anon4* anim_tbl[1];
	// Line 3220, Address: 0x250720, Func Offset: 0
	// Line 3394, Address: 0x250728, Func Offset: 0x8
	// Line 3397, Address: 0x250754, Func Offset: 0x34
	// Line 3398, Address: 0x25075c, Func Offset: 0x3c
	// Line 3399, Address: 0x250760, Func Offset: 0x40
	// Line 3402, Address: 0x250764, Func Offset: 0x44
	// Line 3403, Address: 0x250768, Func Offset: 0x48
	// Line 3398, Address: 0x25076c, Func Offset: 0x4c
	// Line 3399, Address: 0x250778, Func Offset: 0x58
	// Line 3402, Address: 0x25077c, Func Offset: 0x5c
	// Line 3403, Address: 0x250780, Func Offset: 0x60
	// Line 3405, Address: 0x250784, Func Offset: 0x64
	// Line 3409, Address: 0x25078c, Func Offset: 0x6c
	// Line 3405, Address: 0x250790, Func Offset: 0x70
	// Line 3406, Address: 0x250798, Func Offset: 0x78
	// Line 3407, Address: 0x25079c, Func Offset: 0x7c
	// Line 3408, Address: 0x2507a0, Func Offset: 0x80
	// Line 3409, Address: 0x2507a4, Func Offset: 0x84
	// Line 3410, Address: 0x2507a8, Func Offset: 0x88
	// Line 3412, Address: 0x2507b0, Func Offset: 0x90
	// Line 3413, Address: 0x2507b4, Func Offset: 0x94
	// Line 3414, Address: 0x2507b8, Func Offset: 0x98
	// Line 3424, Address: 0x2507c0, Func Offset: 0xa0
	// Line 3427, Address: 0x2507c8, Func Offset: 0xa8
	// Line 3428, Address: 0x2507d4, Func Offset: 0xb4
	// Line 3430, Address: 0x2507e0, Func Offset: 0xc0
	// Line 3431, Address: 0x2507e4, Func Offset: 0xc4
	// Line 3432, Address: 0x2507e8, Func Offset: 0xc8
	// Line 3450, Address: 0x2507f4, Func Offset: 0xd4
	// Line 3451, Address: 0x25080c, Func Offset: 0xec
	// Line 3452, Address: 0x250834, Func Offset: 0x114
	// Line 3453, Address: 0x25084c, Func Offset: 0x12c
	// Line 3455, Address: 0x250858, Func Offset: 0x138
	// Line 3457, Address: 0x250868, Func Offset: 0x148
	// Line 3458, Address: 0x250878, Func Offset: 0x158
	// Line 3464, Address: 0x250888, Func Offset: 0x168
	// Line 3466, Address: 0x250894, Func Offset: 0x174
	// Line 3469, Address: 0x2508bc, Func Offset: 0x19c
	// Func End, Address: 0x2508c8, Func Offset: 0x1a8
	scePrintf("bhEff_Sub372 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2508d0
void bhEff_Sub373(O_WRK* op)
{
	//_anon31 uvinfo[13];
	//_anon4* anim_tbl[1];
	// Line 3486, Address: 0x2508d0, Func Offset: 0
	// Line 3516, Address: 0x2508d8, Func Offset: 0x8
	// Line 3519, Address: 0x250904, Func Offset: 0x34
	// Line 3520, Address: 0x25090c, Func Offset: 0x3c
	// Line 3521, Address: 0x250910, Func Offset: 0x40
	// Line 3524, Address: 0x250914, Func Offset: 0x44
	// Line 3525, Address: 0x250918, Func Offset: 0x48
	// Line 3520, Address: 0x25091c, Func Offset: 0x4c
	// Line 3521, Address: 0x250928, Func Offset: 0x58
	// Line 3524, Address: 0x25092c, Func Offset: 0x5c
	// Line 3525, Address: 0x250930, Func Offset: 0x60
	// Line 3527, Address: 0x250934, Func Offset: 0x64
	// Line 3531, Address: 0x25093c, Func Offset: 0x6c
	// Line 3527, Address: 0x250940, Func Offset: 0x70
	// Line 3528, Address: 0x250948, Func Offset: 0x78
	// Line 3529, Address: 0x25094c, Func Offset: 0x7c
	// Line 3530, Address: 0x250950, Func Offset: 0x80
	// Line 3531, Address: 0x250954, Func Offset: 0x84
	// Line 3532, Address: 0x250958, Func Offset: 0x88
	// Line 3534, Address: 0x250960, Func Offset: 0x90
	// Line 3535, Address: 0x250968, Func Offset: 0x98
	// Line 3536, Address: 0x25096c, Func Offset: 0x9c
	// Line 3537, Address: 0x250974, Func Offset: 0xa4
	// Line 3540, Address: 0x25097c, Func Offset: 0xac
	// Line 3541, Address: 0x250988, Func Offset: 0xb8
	// Line 3543, Address: 0x250994, Func Offset: 0xc4
	// Line 3544, Address: 0x250998, Func Offset: 0xc8
	// Line 3545, Address: 0x25099c, Func Offset: 0xcc
	// Line 3553, Address: 0x2509a8, Func Offset: 0xd8
	// Line 3555, Address: 0x2509b8, Func Offset: 0xe8
	// Line 3557, Address: 0x2509c8, Func Offset: 0xf8
	// Line 3558, Address: 0x2509e0, Func Offset: 0x110
	// Line 3559, Address: 0x250a08, Func Offset: 0x138
	// Line 3560, Address: 0x250a1c, Func Offset: 0x14c
	// Line 3563, Address: 0x250a24, Func Offset: 0x154
	// Line 3564, Address: 0x250a3c, Func Offset: 0x16c
	// Line 3565, Address: 0x250a64, Func Offset: 0x194
	// Line 3567, Address: 0x250a7c, Func Offset: 0x1ac
	// Line 3569, Address: 0x250a88, Func Offset: 0x1b8
	// Line 3571, Address: 0x250a98, Func Offset: 0x1c8
	// Line 3572, Address: 0x250aa8, Func Offset: 0x1d8
	// Line 3578, Address: 0x250ab8, Func Offset: 0x1e8
	// Line 3580, Address: 0x250ac4, Func Offset: 0x1f4
	// Line 3582, Address: 0x250aec, Func Offset: 0x21c
	// Func End, Address: 0x250af8, Func Offset: 0x228
	scePrintf("bhEff_Sub373 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x250b00
void bhEff_Sub398(O_WRK* op)
{
	int i;
	NJS_POINT3 ps;
	//_anon4* bani;
	//_anon31* uvp;
	float pos_tbl[2][11];
	//_anon4* blanim_tbl[11];
	//_anon31* blood_uvinfo[11];
	// Line 3600, Address: 0x250b00, Func Offset: 0
	// Line 3737, Address: 0x250b14, Func Offset: 0x14
	// Line 3600, Address: 0x250b1c, Func Offset: 0x1c
	// Line 3737, Address: 0x250b20, Func Offset: 0x20
	// Line 3751, Address: 0x250b34, Func Offset: 0x34
	// Line 3763, Address: 0x250b38, Func Offset: 0x38
	// Line 3737, Address: 0x250b3c, Func Offset: 0x3c
	// Line 3751, Address: 0x250b40, Func Offset: 0x40
	// Line 3737, Address: 0x250b44, Func Offset: 0x44
	// Line 3751, Address: 0x250b4c, Func Offset: 0x4c
	// Line 3737, Address: 0x250b50, Func Offset: 0x50
	// Line 3751, Address: 0x250b54, Func Offset: 0x54
	// Line 3763, Address: 0x250b84, Func Offset: 0x84
	// Line 3766, Address: 0x250ba0, Func Offset: 0xa0
	// Line 3767, Address: 0x250bac, Func Offset: 0xac
	// Line 3769, Address: 0x250bb0, Func Offset: 0xb0
	// Line 3772, Address: 0x250bb4, Func Offset: 0xb4
	// Line 3776, Address: 0x250bb8, Func Offset: 0xb8
	// Line 3783, Address: 0x250bbc, Func Offset: 0xbc
	// Line 3767, Address: 0x250bc0, Func Offset: 0xc0
	// Line 3769, Address: 0x250bcc, Func Offset: 0xcc
	// Line 3770, Address: 0x250bd0, Func Offset: 0xd0
	// Line 3771, Address: 0x250bd4, Func Offset: 0xd4
	// Line 3772, Address: 0x250bd8, Func Offset: 0xd8
	// Line 3773, Address: 0x250bdc, Func Offset: 0xdc
	// Line 3774, Address: 0x250be0, Func Offset: 0xe0
	// Line 3775, Address: 0x250be4, Func Offset: 0xe4
	// Line 3776, Address: 0x250be8, Func Offset: 0xe8
	// Line 3777, Address: 0x250bec, Func Offset: 0xec
	// Line 3778, Address: 0x250bf0, Func Offset: 0xf0
	// Line 3779, Address: 0x250bf4, Func Offset: 0xf4
	// Line 3780, Address: 0x250bf8, Func Offset: 0xf8
	// Line 3783, Address: 0x250bfc, Func Offset: 0xfc
	// Line 3784, Address: 0x250c00, Func Offset: 0x100
	// Line 3786, Address: 0x250c08, Func Offset: 0x108
	// Line 3787, Address: 0x250c10, Func Offset: 0x110
	// Line 3795, Address: 0x250c14, Func Offset: 0x114
	// Line 3786, Address: 0x250c18, Func Offset: 0x118
	// Line 3787, Address: 0x250c20, Func Offset: 0x120
	// Line 3788, Address: 0x250c24, Func Offset: 0x124
	// Line 3789, Address: 0x250c2c, Func Offset: 0x12c
	// Line 3790, Address: 0x250c34, Func Offset: 0x134
	// Line 3791, Address: 0x250c3c, Func Offset: 0x13c
	// Line 3792, Address: 0x250c40, Func Offset: 0x140
	// Line 3793, Address: 0x250c44, Func Offset: 0x144
	// Line 3794, Address: 0x250c48, Func Offset: 0x148
	// Line 3795, Address: 0x250c4c, Func Offset: 0x14c
	// Line 3796, Address: 0x250c50, Func Offset: 0x150
	// Line 3797, Address: 0x250c54, Func Offset: 0x154
	// Line 3798, Address: 0x250c58, Func Offset: 0x158
	// Line 3801, Address: 0x250c64, Func Offset: 0x164
	// Line 3805, Address: 0x250c70, Func Offset: 0x170
	// Line 3807, Address: 0x250c7c, Func Offset: 0x17c
	// Line 3805, Address: 0x250c80, Func Offset: 0x180
	// Line 3806, Address: 0x250c8c, Func Offset: 0x18c
	// Line 3807, Address: 0x250ca0, Func Offset: 0x1a0
	// Line 3808, Address: 0x250cb4, Func Offset: 0x1b4
	// Line 3809, Address: 0x250cf8, Func Offset: 0x1f8
	// Line 3810, Address: 0x250d10, Func Offset: 0x210
	// Line 3816, Address: 0x250d24, Func Offset: 0x224
	// Line 3810, Address: 0x250d2c, Func Offset: 0x22c
	// Line 3816, Address: 0x250d30, Func Offset: 0x230
	// Line 3810, Address: 0x250d34, Func Offset: 0x234
	// Line 3811, Address: 0x250d44, Func Offset: 0x244
	// Line 3812, Address: 0x250d5c, Func Offset: 0x25c
	// Line 3813, Address: 0x250d74, Func Offset: 0x274
	// Line 3814, Address: 0x250d8c, Func Offset: 0x28c
	// Line 3815, Address: 0x250da4, Func Offset: 0x2a4
	// Line 3816, Address: 0x250dbc, Func Offset: 0x2bc
	// Line 3825, Address: 0x250dd4, Func Offset: 0x2d4
	// Line 3831, Address: 0x250de4, Func Offset: 0x2e4
	// Line 3834, Address: 0x250de8, Func Offset: 0x2e8
	// Line 3835, Address: 0x250dec, Func Offset: 0x2ec
	// Line 3837, Address: 0x250df0, Func Offset: 0x2f0
	// Line 3834, Address: 0x250df4, Func Offset: 0x2f4
	// Line 3835, Address: 0x250e00, Func Offset: 0x300
	// Line 3837, Address: 0x250e08, Func Offset: 0x308
	// Line 3840, Address: 0x250e14, Func Offset: 0x314
	// Line 3841, Address: 0x250e1c, Func Offset: 0x31c
	// Line 3840, Address: 0x250e20, Func Offset: 0x320
	// Line 3841, Address: 0x250e28, Func Offset: 0x328
	// Line 3844, Address: 0x250e3c, Func Offset: 0x33c
	// Line 3847, Address: 0x250e44, Func Offset: 0x344
	// Line 3848, Address: 0x250e60, Func Offset: 0x360
	// Line 3850, Address: 0x250e70, Func Offset: 0x370
	// Line 3852, Address: 0x250e7c, Func Offset: 0x37c
	// Line 3853, Address: 0x250ea4, Func Offset: 0x3a4
	// Line 3856, Address: 0x250ec4, Func Offset: 0x3c4
	// Line 3857, Address: 0x250ecc, Func Offset: 0x3cc
	// Line 3859, Address: 0x250ed8, Func Offset: 0x3d8
	// Line 3862, Address: 0x250ee0, Func Offset: 0x3e0
	// Line 3859, Address: 0x250ee4, Func Offset: 0x3e4
	// Line 3860, Address: 0x250eec, Func Offset: 0x3ec
	// Line 3865, Address: 0x250ef0, Func Offset: 0x3f0
	// Line 3860, Address: 0x250ef4, Func Offset: 0x3f4
	// Line 3862, Address: 0x250ef8, Func Offset: 0x3f8
	// Line 3863, Address: 0x250f14, Func Offset: 0x414
	// Line 3865, Address: 0x250f28, Func Offset: 0x428
	// Line 3866, Address: 0x250f30, Func Offset: 0x430
	// Line 3867, Address: 0x250f44, Func Offset: 0x444
	// Line 3868, Address: 0x250f58, Func Offset: 0x458
	// Line 3871, Address: 0x250f68, Func Offset: 0x468
	// Line 3868, Address: 0x250f6c, Func Offset: 0x46c
	// Line 3871, Address: 0x250f78, Func Offset: 0x478
	// Line 3868, Address: 0x250f80, Func Offset: 0x480
	// Line 3869, Address: 0x250f8c, Func Offset: 0x48c
	// Line 3871, Address: 0x250fac, Func Offset: 0x4ac
	// Line 3873, Address: 0x250fb4, Func Offset: 0x4b4
	// Line 3875, Address: 0x250fc0, Func Offset: 0x4c0
	// Line 3873, Address: 0x250fcc, Func Offset: 0x4cc
	// Line 3874, Address: 0x250fd4, Func Offset: 0x4d4
	// Line 3875, Address: 0x250fe0, Func Offset: 0x4e0
	// Line 3876, Address: 0x250ff8, Func Offset: 0x4f8
	// Line 3877, Address: 0x251010, Func Offset: 0x510
	// Line 3878, Address: 0x251018, Func Offset: 0x518
	// Line 3879, Address: 0x251020, Func Offset: 0x520
	// Line 3880, Address: 0x251028, Func Offset: 0x528
	// Line 3883, Address: 0x251030, Func Offset: 0x530
	// Line 3885, Address: 0x25103c, Func Offset: 0x53c
	// Line 3886, Address: 0x251064, Func Offset: 0x564
	// Line 3891, Address: 0x251088, Func Offset: 0x588
	// Line 3893, Address: 0x251098, Func Offset: 0x598
	// Line 3894, Address: 0x2510a4, Func Offset: 0x5a4
	// Line 3896, Address: 0x2510b4, Func Offset: 0x5b4
	// Line 3897, Address: 0x2510b8, Func Offset: 0x5b8
	// Line 3900, Address: 0x2510c4, Func Offset: 0x5c4
	// Func End, Address: 0x2510e0, Func Offset: 0x5e0
	scePrintf("bhEff_Sub398 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2510e0
O_WRK* bhEff_AllocOwork()
{
	int i;
	O_WRK* op;
	// Line 3920, Address: 0x2510e0, Func Offset: 0
	// Line 3921, Address: 0x2510ec, Func Offset: 0xc
	// Line 3924, Address: 0x2510f4, Func Offset: 0x14
	// Line 3926, Address: 0x2510f8, Func Offset: 0x18
	// Line 3928, Address: 0x251108, Func Offset: 0x28
	// Line 3929, Address: 0x251118, Func Offset: 0x38
	// Line 3930, Address: 0x251120, Func Offset: 0x40
	// Line 3932, Address: 0x251128, Func Offset: 0x48
	// Line 3933, Address: 0x251138, Func Offset: 0x58
	// Line 3934, Address: 0x25113c, Func Offset: 0x5c
	// Func End, Address: 0x25114c, Func Offset: 0x6c
	scePrintf("bhEff_AllocOwork - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x251150
void bhEff_PtclSpriteDraw(O_WRK* op)
{
	int i;
	char atr[192];
	float* size;
	NJS_POINT3* vtx_p;
	//_anon2* dtbl;
	// Line 3952, Address: 0x251150, Func Offset: 0
	// Line 3953, Address: 0x251168, Func Offset: 0x18
	// Line 3961, Address: 0x251170, Func Offset: 0x20
	// Line 3962, Address: 0x251178, Func Offset: 0x28
	// Line 3963, Address: 0x251184, Func Offset: 0x34
	// Line 3965, Address: 0x251190, Func Offset: 0x40
	// Line 3966, Address: 0x251198, Func Offset: 0x48
	// Line 3968, Address: 0x2511a8, Func Offset: 0x58
	// Line 3972, Address: 0x2511b0, Func Offset: 0x60
	// Line 3970, Address: 0x2511b8, Func Offset: 0x68
	// Line 3971, Address: 0x2511bc, Func Offset: 0x6c
	// Line 3972, Address: 0x2511c0, Func Offset: 0x70
	// Line 3974, Address: 0x2511c8, Func Offset: 0x78
	// Line 3976, Address: 0x2511d0, Func Offset: 0x80
	// Line 3977, Address: 0x2511e4, Func Offset: 0x94
	// Line 3978, Address: 0x2511e8, Func Offset: 0x98
	// Line 3979, Address: 0x2511ec, Func Offset: 0x9c
	// Line 3980, Address: 0x251200, Func Offset: 0xb0
	// Line 3985, Address: 0x251208, Func Offset: 0xb8
	// Line 3987, Address: 0x251210, Func Offset: 0xc0
	// Func End, Address: 0x25122c, Func Offset: 0xdc
	scePrintf("bhEff_PtclSpriteDraw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x251230
void bhEff_LineDraw(O_WRK* op)
{
	//_anon32 poly[3];
	int i;
	char atr[192];
	NJS_POINT3* vtx_p2;
	NJS_POINT3* vtx_p;
	//_anon2* dtbl;
	// Line 4005, Address: 0x251230, Func Offset: 0
	// Line 4006, Address: 0x25124c, Func Offset: 0x1c
	// Line 4014, Address: 0x251254, Func Offset: 0x24
	// Line 4015, Address: 0x25125c, Func Offset: 0x2c
	// Line 4016, Address: 0x251268, Func Offset: 0x38
	// Line 4019, Address: 0x251274, Func Offset: 0x44
	// Line 4021, Address: 0x25127c, Func Offset: 0x4c
	// Line 4025, Address: 0x25128c, Func Offset: 0x5c
	// Line 4026, Address: 0x251290, Func Offset: 0x60
	// Line 4028, Address: 0x251294, Func Offset: 0x64
	// Line 4032, Address: 0x251298, Func Offset: 0x68
	// Line 4028, Address: 0x25129c, Func Offset: 0x6c
	// Line 4029, Address: 0x2512a0, Func Offset: 0x70
	// Line 4030, Address: 0x2512a8, Func Offset: 0x78
	// Line 4032, Address: 0x2512ac, Func Offset: 0x7c
	// Line 4034, Address: 0x2512b4, Func Offset: 0x84
	// Line 4040, Address: 0x2512b8, Func Offset: 0x88
	// Line 4043, Address: 0x2512c4, Func Offset: 0x94
	// Line 4034, Address: 0x2512c8, Func Offset: 0x98
	// Line 4035, Address: 0x2512cc, Func Offset: 0x9c
	// Line 4041, Address: 0x2512d0, Func Offset: 0xa0
	// Line 4043, Address: 0x2512dc, Func Offset: 0xac
	// Line 4035, Address: 0x2512e0, Func Offset: 0xb0
	// Line 4036, Address: 0x2512e4, Func Offset: 0xb4
	// Line 4043, Address: 0x2512e8, Func Offset: 0xb8
	// Line 4036, Address: 0x2512ec, Func Offset: 0xbc
	// Line 4037, Address: 0x2512f0, Func Offset: 0xc0
	// Line 4038, Address: 0x2512f8, Func Offset: 0xc8
	// Line 4039, Address: 0x251300, Func Offset: 0xd0
	// Line 4040, Address: 0x251308, Func Offset: 0xd8
	// Line 4041, Address: 0x251314, Func Offset: 0xe4
	// Line 4042, Address: 0x251320, Func Offset: 0xf0
	// Line 4043, Address: 0x251328, Func Offset: 0xf8
	// Line 4045, Address: 0x251330, Func Offset: 0x100
	// Line 4046, Address: 0x251334, Func Offset: 0x104
	// Line 4047, Address: 0x251338, Func Offset: 0x108
	// Line 4083, Address: 0x251350, Func Offset: 0x120
	// Line 4084, Address: 0x251358, Func Offset: 0x128
	// Line 4085, Address: 0x251360, Func Offset: 0x130
	// Func End, Address: 0x251380, Func Offset: 0x150
	scePrintf("bhEff_LineDraw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x251380
void bhEff_SetSprite(O_WRK* op, UV_WORK* uvp, int mode)
{
	// Line 4105, Address: 0x251380, Func Offset: 0
	// Line 4107, Address: 0x251390, Func Offset: 0x10
	// Line 4105, Address: 0x251398, Func Offset: 0x18
	// Line 4109, Address: 0x25139c, Func Offset: 0x1c
	// Line 4105, Address: 0x2513a0, Func Offset: 0x20
	// Line 4106, Address: 0x2513a8, Func Offset: 0x28
	// Line 4109, Address: 0x2513b0, Func Offset: 0x30
	// Line 4106, Address: 0x2513b4, Func Offset: 0x34
	// Line 4107, Address: 0x2513c0, Func Offset: 0x40
	// Line 4108, Address: 0x2513cc, Func Offset: 0x4c
	// Line 4109, Address: 0x2513d8, Func Offset: 0x58
	// Line 4110, Address: 0x2513f0, Func Offset: 0x70
	// Line 4111, Address: 0x251408, Func Offset: 0x88
	// Line 4112, Address: 0x251410, Func Offset: 0x90
	// Line 4113, Address: 0x251418, Func Offset: 0x98
	// Line 4114, Address: 0x251420, Func Offset: 0xa0
	// Line 4117, Address: 0x251428, Func Offset: 0xa8
	// Line 4119, Address: 0x251434, Func Offset: 0xb4
	// Line 4121, Address: 0x25143c, Func Offset: 0xbc
	// Line 4122, Address: 0x251464, Func Offset: 0xe4
	// Line 4123, Address: 0x251484, Func Offset: 0x104
	// Line 4126, Address: 0x25148c, Func Offset: 0x10c
	// Line 4127, Address: 0x2514b4, Func Offset: 0x134
	// Line 4130, Address: 0x2514d8, Func Offset: 0x158
	// Func End, Address: 0x2514e0, Func Offset: 0x160
	scePrintf("bhEff_SetSprite - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2514e0
void bhEff_SetSpriteAnime(O_WRK* op, EFF_ANIM* eff_anim, UV_WORK* uvp, int mode)
{
	EFF_ANIM* anim_p;
	// Line 4158, Address: 0x2514e0, Func Offset: 0
	// Line 4162, Address: 0x2514e8, Func Offset: 0x8
	// Line 4165, Address: 0x2514ec, Func Offset: 0xc
	// Line 4162, Address: 0x2514f0, Func Offset: 0x10
	// Line 4165, Address: 0x2514f8, Func Offset: 0x18
	// Line 4168, Address: 0x251504, Func Offset: 0x24
	// Line 4172, Address: 0x25150c, Func Offset: 0x2c
	// Line 4175, Address: 0x251518, Func Offset: 0x38
	// Line 4176, Address: 0x251520, Func Offset: 0x40
	// Line 4179, Address: 0x25152c, Func Offset: 0x4c
	// Line 4180, Address: 0x251538, Func Offset: 0x58
	// Line 4182, Address: 0x251548, Func Offset: 0x68
	// Line 4183, Address: 0x25154c, Func Offset: 0x6c
	// Line 4186, Address: 0x251574, Func Offset: 0x94
	// Line 4188, Address: 0x251584, Func Offset: 0xa4
	// Line 4190, Address: 0x251594, Func Offset: 0xb4
	// Func End, Address: 0x2515a0, Func Offset: 0xc0
	scePrintf("bhEff_SetSpriteAnime - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2515a0
void bhEff_3DSpriteDraw(O_WRK* op)
{
	unsigned int tnm;
	// Line 4209, Address: 0x2515a0, Func Offset: 0
	// Line 4215, Address: 0x2515b0, Func Offset: 0x10
	// Line 4218, Address: 0x2515b8, Func Offset: 0x18
	// Line 4223, Address: 0x25160c, Func Offset: 0x6c
	// Line 4224, Address: 0x251614, Func Offset: 0x74
	// Line 4228, Address: 0x25161c, Func Offset: 0x7c
	// Line 4230, Address: 0x25162c, Func Offset: 0x8c
	// Line 4231, Address: 0x251634, Func Offset: 0x94
	// Line 4234, Address: 0x25163c, Func Offset: 0x9c
	// Line 4238, Address: 0x251648, Func Offset: 0xa8
	// Line 4240, Address: 0x251658, Func Offset: 0xb8
	// Line 4241, Address: 0x251670, Func Offset: 0xd0
	// Line 4242, Address: 0x251698, Func Offset: 0xf8
	// Line 4243, Address: 0x2516a0, Func Offset: 0x100
	// Line 4246, Address: 0x2516a8, Func Offset: 0x108
	// Line 4247, Address: 0x2516b0, Func Offset: 0x110
	// Line 4248, Address: 0x2516bc, Func Offset: 0x11c
	// Line 4252, Address: 0x2516c4, Func Offset: 0x124
	// Line 4254, Address: 0x2516d8, Func Offset: 0x138
	// Line 4258, Address: 0x2516e4, Func Offset: 0x144
	// Line 4260, Address: 0x2516ec, Func Offset: 0x14c
	// Line 4263, Address: 0x25170c, Func Offset: 0x16c
	// Line 4264, Address: 0x251718, Func Offset: 0x178
	// Line 4265, Address: 0x251720, Func Offset: 0x180
	// Line 4266, Address: 0x25172c, Func Offset: 0x18c
	// Line 4267, Address: 0x251734, Func Offset: 0x194
	// Line 4273, Address: 0x25173c, Func Offset: 0x19c
	// Line 4274, Address: 0x251768, Func Offset: 0x1c8
	// Line 4275, Address: 0x25177c, Func Offset: 0x1dc
	// Line 4278, Address: 0x251790, Func Offset: 0x1f0
	// Line 4279, Address: 0x251798, Func Offset: 0x1f8
	// Line 4281, Address: 0x2517a4, Func Offset: 0x204
	// Line 4283, Address: 0x2517b8, Func Offset: 0x218
	// Line 4284, Address: 0x2517c0, Func Offset: 0x220
	// Line 4286, Address: 0x2517cc, Func Offset: 0x22c
	// Line 4289, Address: 0x2517d8, Func Offset: 0x238
	// Line 4290, Address: 0x2517e4, Func Offset: 0x244
	// Line 4291, Address: 0x2517f0, Func Offset: 0x250
	// Line 4294, Address: 0x2517f8, Func Offset: 0x258
	// Line 4296, Address: 0x251808, Func Offset: 0x268
	// Line 4299, Address: 0x251810, Func Offset: 0x270
	// Line 4301, Address: 0x25181c, Func Offset: 0x27c
	// Line 4304, Address: 0x251828, Func Offset: 0x288
	// Line 4305, Address: 0x251830, Func Offset: 0x290
	// Func End, Address: 0x251844, Func Offset: 0x2a4
	scePrintf("bhEff_3DSpriteDraw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x251850
void bhEff_ModelDraw(O_WRK* op)
{
	//_anon14* mlp;
	//_anon20* tnp;
	// Line 4487, Address: 0x251850, Func Offset: 0
	// Line 4494, Address: 0x251854, Func Offset: 0x4
	// Line 4487, Address: 0x25185c, Func Offset: 0xc
	// Line 4494, Address: 0x25186c, Func Offset: 0x1c
	// Line 4495, Address: 0x25187c, Func Offset: 0x2c
	// Line 4496, Address: 0x251898, Func Offset: 0x48
	// Line 4498, Address: 0x2518bc, Func Offset: 0x6c
	// Line 4501, Address: 0x2518c4, Func Offset: 0x74
	// Line 4505, Address: 0x251910, Func Offset: 0xc0
	// Line 4506, Address: 0x251918, Func Offset: 0xc8
	// Line 4510, Address: 0x251920, Func Offset: 0xd0
	// Line 4511, Address: 0x251930, Func Offset: 0xe0
	// Line 4513, Address: 0x251940, Func Offset: 0xf0
	// Line 4519, Address: 0x25194c, Func Offset: 0xfc
	// Line 4521, Address: 0x25195c, Func Offset: 0x10c
	// Line 4522, Address: 0x251964, Func Offset: 0x114
	// Line 4521, Address: 0x25196c, Func Offset: 0x11c
	// Line 4522, Address: 0x251978, Func Offset: 0x128
	// Line 4521, Address: 0x25197c, Func Offset: 0x12c
	// Line 4522, Address: 0x251980, Func Offset: 0x130
	// Line 4523, Address: 0x25198c, Func Offset: 0x13c
	// Line 4522, Address: 0x251990, Func Offset: 0x140
	// Line 4523, Address: 0x251998, Func Offset: 0x148
	// Line 4524, Address: 0x2519ac, Func Offset: 0x15c
	// Line 4525, Address: 0x2519b4, Func Offset: 0x164
	// Line 4528, Address: 0x2519bc, Func Offset: 0x16c
	// Line 4529, Address: 0x2519c4, Func Offset: 0x174
	// Line 4532, Address: 0x2519cc, Func Offset: 0x17c
	// Line 4533, Address: 0x2519d4, Func Offset: 0x184
	// Line 4536, Address: 0x2519f4, Func Offset: 0x1a4
	// Line 4537, Address: 0x251a00, Func Offset: 0x1b0
	// Line 4538, Address: 0x251a08, Func Offset: 0x1b8
	// Line 4539, Address: 0x251a14, Func Offset: 0x1c4
	// Line 4540, Address: 0x251a1c, Func Offset: 0x1cc
	// Line 4546, Address: 0x251a24, Func Offset: 0x1d4
	// Line 4547, Address: 0x251a50, Func Offset: 0x200
	// Line 4548, Address: 0x251a64, Func Offset: 0x214
	// Line 4550, Address: 0x251a78, Func Offset: 0x228
	// Line 4551, Address: 0x251a80, Func Offset: 0x230
	// Line 4555, Address: 0x251a8c, Func Offset: 0x23c
	// Line 4558, Address: 0x251a94, Func Offset: 0x244
	// Line 4560, Address: 0x251aa0, Func Offset: 0x250
	// Line 4563, Address: 0x251acc, Func Offset: 0x27c
	// Line 4565, Address: 0x251af4, Func Offset: 0x2a4
	// Line 4567, Address: 0x251b04, Func Offset: 0x2b4
	// Line 4569, Address: 0x251b18, Func Offset: 0x2c8
	// Line 4570, Address: 0x251b20, Func Offset: 0x2d0
	// Func End, Address: 0x251b38, Func Offset: 0x2e8
	scePrintf("bhEff_ModelDraw - UNIMPLEMENTED!\n");
}
