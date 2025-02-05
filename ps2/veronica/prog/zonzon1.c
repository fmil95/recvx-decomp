#include "zonzon1.h"

_anon24 BloodType[31];
unsigned int BloodCol[2][4];
_anon0 eff[0];
_anon23* sys;
BH_PWORK* plp;
BH_PWORK ene[0];
_anon10* rom;

// 
// Start address: 0x218d10
void bhEne_SetMinceEffect(BH_PWORK* epw, int type, int num)
{
	float size;
	int dam_ang;
	int i;
	int eno;
	// Line 105, Address: 0x218d10, Func Offset: 0
	// Line 110, Address: 0x218d28, Func Offset: 0x18
	// Line 111, Address: 0x218d38, Func Offset: 0x28
	// Line 110, Address: 0x218d3c, Func Offset: 0x2c
	// Line 111, Address: 0x218d48, Func Offset: 0x38
	// Line 112, Address: 0x218d60, Func Offset: 0x50
	// Line 113, Address: 0x218d74, Func Offset: 0x64
	// Line 114, Address: 0x218d8c, Func Offset: 0x7c
	// Line 115, Address: 0x218da4, Func Offset: 0x94
	// Line 116, Address: 0x218db8, Func Offset: 0xa8
	// Line 117, Address: 0x218dd8, Func Offset: 0xc8
	// Line 116, Address: 0x218de0, Func Offset: 0xd0
	// Line 120, Address: 0x218df0, Func Offset: 0xe0
	// Line 117, Address: 0x218df4, Func Offset: 0xe4
	// Line 116, Address: 0x218dfc, Func Offset: 0xec
	// Line 120, Address: 0x218e08, Func Offset: 0xf8
	// Line 116, Address: 0x218e0c, Func Offset: 0xfc
	// Line 117, Address: 0x218e18, Func Offset: 0x108
	// Line 118, Address: 0x218e1c, Func Offset: 0x10c
	// Line 119, Address: 0x218e30, Func Offset: 0x120
	// Line 120, Address: 0x218e44, Func Offset: 0x134
	// Line 122, Address: 0x218e6c, Func Offset: 0x15c
	// Line 123, Address: 0x218e90, Func Offset: 0x180
	// Line 122, Address: 0x218e94, Func Offset: 0x184
	// Line 123, Address: 0x218e98, Func Offset: 0x188
	// Line 126, Address: 0x218ea0, Func Offset: 0x190
	// Line 131, Address: 0x218ef4, Func Offset: 0x1e4
	// Line 126, Address: 0x218f00, Func Offset: 0x1f0
	// Line 131, Address: 0x218f0c, Func Offset: 0x1fc
	// Line 132, Address: 0x218f24, Func Offset: 0x214
	// Line 133, Address: 0x218f30, Func Offset: 0x220
	// Line 134, Address: 0x218f54, Func Offset: 0x244
	// Line 135, Address: 0x218f5c, Func Offset: 0x24c
	// Line 133, Address: 0x218f64, Func Offset: 0x254
	// Line 134, Address: 0x218f6c, Func Offset: 0x25c
	// Line 135, Address: 0x218f98, Func Offset: 0x288
	// Line 137, Address: 0x218fb0, Func Offset: 0x2a0
	// Line 138, Address: 0x218fc0, Func Offset: 0x2b0
	// Func End, Address: 0x218fdc, Func Offset: 0x2cc
}

// 
// Start address: 0x218fe0
void bhEne_SetMinceEffect2(BH_PWORK* epw, int type, float size, int num)
{
	int dam_ang;
	int i;
	int eno;
	// Line 151, Address: 0x218fe0, Func Offset: 0
	// Line 155, Address: 0x218ff8, Func Offset: 0x18
	// Line 164, Address: 0x219000, Func Offset: 0x20
	// Line 155, Address: 0x219008, Func Offset: 0x28
	// Line 164, Address: 0x21900c, Func Offset: 0x2c
	// Line 155, Address: 0x219010, Func Offset: 0x30
	// Line 156, Address: 0x21901c, Func Offset: 0x3c
	// Line 157, Address: 0x219038, Func Offset: 0x58
	// Line 158, Address: 0x21904c, Func Offset: 0x6c
	// Line 159, Address: 0x219064, Func Offset: 0x84
	// Line 160, Address: 0x21907c, Func Offset: 0x9c
	// Line 161, Address: 0x219094, Func Offset: 0xb4
	// Line 162, Address: 0x2190a8, Func Offset: 0xc8
	// Line 163, Address: 0x2190bc, Func Offset: 0xdc
	// Line 164, Address: 0x2190d0, Func Offset: 0xf0
	// Line 166, Address: 0x2190f8, Func Offset: 0x118
	// Line 167, Address: 0x21911c, Func Offset: 0x13c
	// Line 166, Address: 0x219120, Func Offset: 0x140
	// Line 167, Address: 0x219124, Func Offset: 0x144
	// Line 170, Address: 0x21912c, Func Offset: 0x14c
	// Line 175, Address: 0x219180, Func Offset: 0x1a0
	// Line 170, Address: 0x21918c, Func Offset: 0x1ac
	// Line 175, Address: 0x219198, Func Offset: 0x1b8
	// Line 176, Address: 0x2191b0, Func Offset: 0x1d0
	// Line 177, Address: 0x2191bc, Func Offset: 0x1dc
	// Line 178, Address: 0x2191e0, Func Offset: 0x200
	// Line 179, Address: 0x2191e8, Func Offset: 0x208
	// Line 177, Address: 0x2191f0, Func Offset: 0x210
	// Line 178, Address: 0x2191f8, Func Offset: 0x218
	// Line 179, Address: 0x219224, Func Offset: 0x244
	// Line 180, Address: 0x21923c, Func Offset: 0x25c
	// Line 181, Address: 0x219240, Func Offset: 0x260
	// Line 182, Address: 0x219250, Func Offset: 0x270
	// Func End, Address: 0x21926c, Func Offset: 0x28c
}

// 
// Start address: 0x219270
void bhEne_SetBloodEffect(BH_PWORK* epw, int type)
{
	// Line 195, Address: 0x219274, Func Offset: 0x4
	// Func End, Address: 0x21927c, Func Offset: 0xc
}

// 
// Start address: 0x219280
void bhEne_SetBloodEffect2(BH_PWORK* epw, int type, int jno, _anon6* ofp)
{
	_anon6 vec;
	_anon6 org;
	// Line 209, Address: 0x219280, Func Offset: 0
	// Line 210, Address: 0x21929c, Func Offset: 0x1c
	// Line 214, Address: 0x2192c0, Func Offset: 0x40
	// Line 217, Address: 0x2192cc, Func Offset: 0x4c
	// Line 220, Address: 0x2192d0, Func Offset: 0x50
	// Line 217, Address: 0x2192e0, Func Offset: 0x60
	// Line 218, Address: 0x2192e8, Func Offset: 0x68
	// Line 220, Address: 0x2192ec, Func Offset: 0x6c
	// Line 218, Address: 0x2192f8, Func Offset: 0x78
	// Line 219, Address: 0x219300, Func Offset: 0x80
	// Line 220, Address: 0x219304, Func Offset: 0x84
	// Line 219, Address: 0x219310, Func Offset: 0x90
	// Line 220, Address: 0x219318, Func Offset: 0x98
	// Line 223, Address: 0x219348, Func Offset: 0xc8
	// Line 225, Address: 0x219350, Func Offset: 0xd0
	// Line 239, Address: 0x219358, Func Offset: 0xd8
	// Line 223, Address: 0x21935c, Func Offset: 0xdc
	// Line 239, Address: 0x21936c, Func Offset: 0xec
	// Line 224, Address: 0x219370, Func Offset: 0xf0
	// Line 225, Address: 0x21937c, Func Offset: 0xfc
	// Line 235, Address: 0x219380, Func Offset: 0x100
	// Line 241, Address: 0x219384, Func Offset: 0x104
	// Line 224, Address: 0x219388, Func Offset: 0x108
	// Line 225, Address: 0x219394, Func Offset: 0x114
	// Line 241, Address: 0x21939c, Func Offset: 0x11c
	// Line 225, Address: 0x2193a4, Func Offset: 0x124
	// Line 227, Address: 0x2193b0, Func Offset: 0x130
	// Line 235, Address: 0x2193ec, Func Offset: 0x16c
	// Line 236, Address: 0x219400, Func Offset: 0x180
	// Line 237, Address: 0x219414, Func Offset: 0x194
	// Line 238, Address: 0x219428, Func Offset: 0x1a8
	// Line 239, Address: 0x21943c, Func Offset: 0x1bc
	// Line 241, Address: 0x219464, Func Offset: 0x1e4
	// Line 245, Address: 0x21947c, Func Offset: 0x1fc
	// Func End, Address: 0x219498, Func Offset: 0x218
}

// 
// Start address: 0x2194a0
void bhEne_SetBloodEffect4(_anon6* pos, _anon6* vec, int col, int type1, int type2)
{
	// Line 259, Address: 0x2194a0, Func Offset: 0
	// Line 261, Address: 0x2194b0, Func Offset: 0x10
	// Line 259, Address: 0x2194b4, Func Offset: 0x14
	// Line 261, Address: 0x2194b8, Func Offset: 0x18
	// Line 264, Address: 0x2194fc, Func Offset: 0x5c
	// Line 265, Address: 0x219508, Func Offset: 0x68
	// Line 266, Address: 0x21950c, Func Offset: 0x6c
	// Line 264, Address: 0x219510, Func Offset: 0x70
	// Line 265, Address: 0x21951c, Func Offset: 0x7c
	// Line 271, Address: 0x219524, Func Offset: 0x84
	// Line 275, Address: 0x219528, Func Offset: 0x88
	// Line 265, Address: 0x219534, Func Offset: 0x94
	// Line 266, Address: 0x219540, Func Offset: 0xa0
	// Line 267, Address: 0x219554, Func Offset: 0xb4
	// Line 268, Address: 0x219568, Func Offset: 0xc8
	// Line 269, Address: 0x219580, Func Offset: 0xe0
	// Line 270, Address: 0x219598, Func Offset: 0xf8
	// Line 271, Address: 0x2195b0, Func Offset: 0x110
	// Line 272, Address: 0x2195c4, Func Offset: 0x124
	// Line 273, Address: 0x2195d8, Func Offset: 0x138
	// Line 274, Address: 0x2195ec, Func Offset: 0x14c
	// Line 275, Address: 0x219600, Func Offset: 0x160
	// Line 279, Address: 0x219618, Func Offset: 0x178
	// Func End, Address: 0x219630, Func Offset: 0x190
}

// 
// Start address: 0x219630
void bhEne_SetBloodEffect5(BH_PWORK* epw, int type1, int type2)
{
	_anon6 vec;
	_anon6 ofp;
	// Line 291, Address: 0x219630, Func Offset: 0
	// Line 296, Address: 0x219644, Func Offset: 0x14
	// Line 297, Address: 0x21967c, Func Offset: 0x4c
	// Line 298, Address: 0x2196a8, Func Offset: 0x78
	// Line 300, Address: 0x2196d4, Func Offset: 0xa4
	// Line 301, Address: 0x2196fc, Func Offset: 0xcc
	// Line 302, Address: 0x219704, Func Offset: 0xd4
	// Line 305, Address: 0x219714, Func Offset: 0xe4
	// Line 308, Address: 0x219718, Func Offset: 0xe8
	// Line 305, Address: 0x219728, Func Offset: 0xf8
	// Line 306, Address: 0x219730, Func Offset: 0x100
	// Line 308, Address: 0x219734, Func Offset: 0x104
	// Line 306, Address: 0x219740, Func Offset: 0x110
	// Line 307, Address: 0x219748, Func Offset: 0x118
	// Line 308, Address: 0x21974c, Func Offset: 0x11c
	// Line 307, Address: 0x219754, Func Offset: 0x124
	// Line 308, Address: 0x21975c, Func Offset: 0x12c
	// Line 311, Address: 0x219790, Func Offset: 0x160
	// Line 327, Address: 0x219798, Func Offset: 0x168
	// Line 311, Address: 0x21979c, Func Offset: 0x16c
	// Line 327, Address: 0x2197a0, Func Offset: 0x170
	// Line 311, Address: 0x2197a4, Func Offset: 0x174
	// Line 312, Address: 0x2197b0, Func Offset: 0x180
	// Line 323, Address: 0x2197bc, Func Offset: 0x18c
	// Line 330, Address: 0x2197c0, Func Offset: 0x190
	// Line 312, Address: 0x2197c4, Func Offset: 0x194
	// Line 313, Address: 0x2197d0, Func Offset: 0x1a0
	// Line 330, Address: 0x2197d8, Func Offset: 0x1a8
	// Line 313, Address: 0x2197dc, Func Offset: 0x1ac
	// Line 315, Address: 0x2197e8, Func Offset: 0x1b8
	// Line 323, Address: 0x219824, Func Offset: 0x1f4
	// Line 324, Address: 0x219838, Func Offset: 0x208
	// Line 325, Address: 0x21984c, Func Offset: 0x21c
	// Line 326, Address: 0x219860, Func Offset: 0x230
	// Line 327, Address: 0x219874, Func Offset: 0x244
	// Line 330, Address: 0x21989c, Func Offset: 0x26c
	// Line 334, Address: 0x2198b8, Func Offset: 0x288
	// Func End, Address: 0x2198d0, Func Offset: 0x2a0
}

// 
// Start address: 0x2198d0
void bhEne_SetBloodEffectBurst(BH_PWORK* epw, int type, int jno, _anon6* pos, int flg)
{
	_anon6 ofp;
	_anon0* op;
	int eno;
	// Line 349, Address: 0x2198d0, Func Offset: 0
	// Line 354, Address: 0x2198f0, Func Offset: 0x20
	// Line 357, Address: 0x2198f8, Func Offset: 0x28
	// Line 365, Address: 0x219900, Func Offset: 0x30
	// Line 367, Address: 0x219908, Func Offset: 0x38
	// Line 371, Address: 0x219924, Func Offset: 0x54
	// Line 372, Address: 0x21992c, Func Offset: 0x5c
	// Line 373, Address: 0x219950, Func Offset: 0x80
	// Line 374, Address: 0x219968, Func Offset: 0x98
	// Line 375, Address: 0x219970, Func Offset: 0xa0
	// Line 378, Address: 0x219980, Func Offset: 0xb0
	// Line 394, Address: 0x219988, Func Offset: 0xb8
	// Line 378, Address: 0x21998c, Func Offset: 0xbc
	// Line 394, Address: 0x219990, Func Offset: 0xc0
	// Line 378, Address: 0x219994, Func Offset: 0xc4
	// Line 379, Address: 0x2199a0, Func Offset: 0xd0
	// Line 390, Address: 0x2199ac, Func Offset: 0xdc
	// Line 396, Address: 0x2199b0, Func Offset: 0xe0
	// Line 379, Address: 0x2199b4, Func Offset: 0xe4
	// Line 380, Address: 0x2199c0, Func Offset: 0xf0
	// Line 396, Address: 0x2199c8, Func Offset: 0xf8
	// Line 380, Address: 0x2199d0, Func Offset: 0x100
	// Line 382, Address: 0x2199dc, Func Offset: 0x10c
	// Line 390, Address: 0x219a18, Func Offset: 0x148
	// Line 391, Address: 0x219a2c, Func Offset: 0x15c
	// Line 392, Address: 0x219a40, Func Offset: 0x170
	// Line 393, Address: 0x219a54, Func Offset: 0x184
	// Line 394, Address: 0x219a68, Func Offset: 0x198
	// Line 396, Address: 0x219a90, Func Offset: 0x1c0
	// Line 397, Address: 0x219aa8, Func Offset: 0x1d8
	// Line 398, Address: 0x219ab4, Func Offset: 0x1e4
	// Line 399, Address: 0x219abc, Func Offset: 0x1ec
	// Line 398, Address: 0x219ac0, Func Offset: 0x1f0
	// Line 399, Address: 0x219ad4, Func Offset: 0x204
	// Line 398, Address: 0x219ad8, Func Offset: 0x208
	// Line 399, Address: 0x219adc, Func Offset: 0x20c
	// Line 400, Address: 0x219ae0, Func Offset: 0x210
	// Line 401, Address: 0x219aec, Func Offset: 0x21c
	// Line 403, Address: 0x219af8, Func Offset: 0x228
	// Func End, Address: 0x219b14, Func Offset: 0x244
}

// 
// Start address: 0x219b20
void bhEne_SetBloodstain(BH_PWORK* epw, int type, int jno, _anon6* ofp)
{
	float d;
	_anon6 pos;
	// Line 416, Address: 0x219b20, Func Offset: 0
	// Line 420, Address: 0x219b3c, Func Offset: 0x1c
	// Line 421, Address: 0x219b44, Func Offset: 0x24
	// Line 422, Address: 0x219b4c, Func Offset: 0x2c
	// Line 423, Address: 0x219b64, Func Offset: 0x44
	// Line 424, Address: 0x219b6c, Func Offset: 0x4c
	// Line 426, Address: 0x219b84, Func Offset: 0x64
	// Line 427, Address: 0x219b8c, Func Offset: 0x6c
	// Line 428, Address: 0x219b94, Func Offset: 0x74
	// Line 429, Address: 0x219bb8, Func Offset: 0x98
	// Line 430, Address: 0x219bc8, Func Offset: 0xa8
	// Line 431, Address: 0x219bd0, Func Offset: 0xb0
	// Line 435, Address: 0x219c04, Func Offset: 0xe4
	// Line 444, Address: 0x219c0c, Func Offset: 0xec
	// Line 435, Address: 0x219c10, Func Offset: 0xf0
	// Line 444, Address: 0x219c14, Func Offset: 0xf4
	// Line 435, Address: 0x219c18, Func Offset: 0xf8
	// Line 436, Address: 0x219c24, Func Offset: 0x104
	// Line 441, Address: 0x219c30, Func Offset: 0x110
	// Line 436, Address: 0x219c34, Func Offset: 0x114
	// Line 437, Address: 0x219c40, Func Offset: 0x120
	// Line 438, Address: 0x219c54, Func Offset: 0x134
	// Line 439, Address: 0x219c6c, Func Offset: 0x14c
	// Line 440, Address: 0x219c84, Func Offset: 0x164
	// Line 441, Address: 0x219c9c, Func Offset: 0x17c
	// Line 442, Address: 0x219cb0, Func Offset: 0x190
	// Line 443, Address: 0x219cc4, Func Offset: 0x1a4
	// Line 444, Address: 0x219cd8, Func Offset: 0x1b8
	// Line 445, Address: 0x219d00, Func Offset: 0x1e0
	// Line 446, Address: 0x219d14, Func Offset: 0x1f4
	// Line 447, Address: 0x219d34, Func Offset: 0x214
	// Line 448, Address: 0x219d50, Func Offset: 0x230
	// Line 447, Address: 0x219d5c, Func Offset: 0x23c
	// Line 448, Address: 0x219d68, Func Offset: 0x248
	// Line 449, Address: 0x219d80, Func Offset: 0x260
	// Line 450, Address: 0x219da4, Func Offset: 0x284
	// Line 451, Address: 0x219dc8, Func Offset: 0x2a8
	// Line 452, Address: 0x219dec, Func Offset: 0x2cc
	// Func End, Address: 0x219e04, Func Offset: 0x2e4
}

// 
// Start address: 0x219e10
void bhEne_SetFireEffect(BH_PWORK* epw, int jno, _anon6* ofp, float size, int len)
{
	int eno;
	_anon6 org;
	// Line 466, Address: 0x219e10, Func Offset: 0
	// Line 467, Address: 0x219e20, Func Offset: 0x10
	// Line 471, Address: 0x219e38, Func Offset: 0x28
	// Line 474, Address: 0x219e44, Func Offset: 0x34
	// Line 492, Address: 0x219e4c, Func Offset: 0x3c
	// Line 474, Address: 0x219e54, Func Offset: 0x44
	// Line 475, Address: 0x219e58, Func Offset: 0x48
	// Line 474, Address: 0x219e5c, Func Offset: 0x4c
	// Line 475, Address: 0x219e68, Func Offset: 0x58
	// Line 488, Address: 0x219e70, Func Offset: 0x60
	// Line 492, Address: 0x219e74, Func Offset: 0x64
	// Line 475, Address: 0x219e78, Func Offset: 0x68
	// Line 476, Address: 0x219e84, Func Offset: 0x74
	// Line 478, Address: 0x219e98, Func Offset: 0x88
	// Line 486, Address: 0x219ed4, Func Offset: 0xc4
	// Line 487, Address: 0x219ee8, Func Offset: 0xd8
	// Line 488, Address: 0x219efc, Func Offset: 0xec
	// Line 489, Address: 0x219f10, Func Offset: 0x100
	// Line 490, Address: 0x219f24, Func Offset: 0x114
	// Line 492, Address: 0x219f38, Func Offset: 0x128
	// Line 497, Address: 0x219f50, Func Offset: 0x140
	// Line 498, Address: 0x219f5c, Func Offset: 0x14c
	// Line 500, Address: 0x219f80, Func Offset: 0x170
	// Func End, Address: 0x219f90, Func Offset: 0x180
}

// 
// Start address: 0x219f90
void bhEne_BloodPool(BH_PWORK* epw, _anon6* pos, int ang, _anon39* param)
{
	// Line 515, Address: 0x219f90, Func Offset: 0
	// Func End, Address: 0x219fb0, Func Offset: 0x20
}

// 
// Start address: 0x219fb0
void bhEne_SetAcidEffect(BH_PWORK* epw, int jno, _anon6* ofp, float size)
{
	_anon6 org;
	// Line 529, Address: 0x219fb0, Func Offset: 0
	// Line 530, Address: 0x219fb8, Func Offset: 0x8
	// Line 529, Address: 0x219fc0, Func Offset: 0x10
	// Line 530, Address: 0x219fc4, Func Offset: 0x14
	// Line 533, Address: 0x219fd4, Func Offset: 0x24
	// Line 536, Address: 0x219fe0, Func Offset: 0x30
	// Line 537, Address: 0x219ff4, Func Offset: 0x44
	// Line 539, Address: 0x219ffc, Func Offset: 0x4c
	// Line 540, Address: 0x21a010, Func Offset: 0x60
	// Line 542, Address: 0x21a018, Func Offset: 0x68
	// Line 544, Address: 0x21a030, Func Offset: 0x80
	// Line 559, Address: 0x21a038, Func Offset: 0x88
	// Line 544, Address: 0x21a03c, Func Offset: 0x8c
	// Line 559, Address: 0x21a040, Func Offset: 0x90
	// Line 544, Address: 0x21a044, Func Offset: 0x94
	// Line 546, Address: 0x21a050, Func Offset: 0xa0
	// Line 554, Address: 0x21a08c, Func Offset: 0xdc
	// Line 555, Address: 0x21a0a0, Func Offset: 0xf0
	// Line 556, Address: 0x21a0b4, Func Offset: 0x104
	// Line 557, Address: 0x21a0c8, Func Offset: 0x118
	// Line 559, Address: 0x21a0dc, Func Offset: 0x12c
	// Line 563, Address: 0x21a0f4, Func Offset: 0x144
	// Func End, Address: 0x21a100, Func Offset: 0x150
}

// 
// Start address: 0x21a100
int bhEne_DirTarget(BH_PWORK* epw, float x, float z, int w)
{
	int ang;
	// Line 576, Address: 0x21a100, Func Offset: 0
	// Line 582, Address: 0x21a110, Func Offset: 0x10
	// Line 583, Address: 0x21a12c, Func Offset: 0x2c
	// Line 585, Address: 0x21a13c, Func Offset: 0x3c
	// Line 586, Address: 0x21a150, Func Offset: 0x50
	// Line 589, Address: 0x21a168, Func Offset: 0x68
	// Line 590, Address: 0x21a16c, Func Offset: 0x6c
	// Func End, Address: 0x21a180, Func Offset: 0x80
}

// 
// Start address: 0x21a180
int bhEne_CheckDirTarget(BH_PWORK* epw, float x, float z, int w)
{
	int ang;
	// Line 603, Address: 0x21a180, Func Offset: 0
	// Line 609, Address: 0x21a190, Func Offset: 0x10
	// Line 610, Address: 0x21a1bc, Func Offset: 0x3c
	// Line 611, Address: 0x21a1e4, Func Offset: 0x64
	// Line 612, Address: 0x21a1e8, Func Offset: 0x68
	// Func End, Address: 0x21a1fc, Func Offset: 0x7c
}

// 
// Start address: 0x21a200
void bhEne_GetPartsPos(BH_PWORK* epw, char* parts, _anon6* p)
{
	npobj* objP;
	_anon12* mlwP;
	// Line 624, Address: 0x21a200, Func Offset: 0
	// Line 625, Address: 0x21a218, Func Offset: 0x18
	// Line 627, Address: 0x21a224, Func Offset: 0x24
	// Line 629, Address: 0x21a22c, Func Offset: 0x2c
	// Line 630, Address: 0x21a234, Func Offset: 0x34
	// Line 631, Address: 0x21a23c, Func Offset: 0x3c
	// Line 633, Address: 0x21a248, Func Offset: 0x48
	// Line 634, Address: 0x21a250, Func Offset: 0x50
	// Line 636, Address: 0x21a270, Func Offset: 0x70
	// Line 637, Address: 0x21a278, Func Offset: 0x78
	// Line 638, Address: 0x21a284, Func Offset: 0x84
	// Line 639, Address: 0x21a298, Func Offset: 0x98
	// Line 641, Address: 0x21a2a4, Func Offset: 0xa4
	// Line 642, Address: 0x21a2ac, Func Offset: 0xac
	// Func End, Address: 0x21a2c8, Func Offset: 0xc8
}

// 
// Start address: 0x21a2d0
int bhEne_DirCheck(int ay, _anon6* vec)
{
	_anon6 v;
	// Line 653, Address: 0x21a2d0, Func Offset: 0
	// Line 656, Address: 0x21a2e8, Func Offset: 0x18
	// Line 657, Address: 0x21a2f0, Func Offset: 0x20
	// Line 658, Address: 0x21a2fc, Func Offset: 0x2c
	// Line 661, Address: 0x21a30c, Func Offset: 0x3c
	// Line 665, Address: 0x21a32c, Func Offset: 0x5c
	// Func End, Address: 0x21a340, Func Offset: 0x70
}

// 
// Start address: 0x21a340
int bhEne_DGDirCheck(BH_PWORK* epw)
{
	// Line 676, Address: 0x21a340, Func Offset: 0
	// Func End, Address: 0x21a34c, Func Offset: 0xc
}

// 
// Start address: 0x21a350
void bhEne_CallPlayerVoice(int no)
{
	// Line 688, Address: 0x21a350, Func Offset: 0
	// Func End, Address: 0x21a358, Func Offset: 0x8
}

// 
// Start address: 0x21a360
void bhEne_CheckEnemiesBall(BH_PWORK* epw)
{
	int i;
	float r;
	float ez1;
	float ey1;
	float ex1;
	float ez0;
	float ey0;
	float ex0;
	float ln;
	float pz;
	float py;
	float px;
	BH_PWORK* epp;
	// Line 699, Address: 0x21a360, Func Offset: 0
	// Line 704, Address: 0x21a38c, Func Offset: 0x2c
	// Line 706, Address: 0x21a39c, Func Offset: 0x3c
	// Line 707, Address: 0x21a3a4, Func Offset: 0x44
	// Line 708, Address: 0x21a3ac, Func Offset: 0x4c
	// Line 710, Address: 0x21a3b4, Func Offset: 0x54
	// Line 706, Address: 0x21a3b8, Func Offset: 0x58
	// Line 710, Address: 0x21a3bc, Func Offset: 0x5c
	// Line 711, Address: 0x21a3c0, Func Offset: 0x60
	// Line 707, Address: 0x21a3c4, Func Offset: 0x64
	// Line 711, Address: 0x21a3c8, Func Offset: 0x68
	// Line 712, Address: 0x21a3d0, Func Offset: 0x70
	// Line 713, Address: 0x21a3f4, Func Offset: 0x94
	// Line 714, Address: 0x21a410, Func Offset: 0xb0
	// Line 716, Address: 0x21a418, Func Offset: 0xb8
	// Line 715, Address: 0x21a420, Func Offset: 0xc0
	// Line 714, Address: 0x21a428, Func Offset: 0xc8
	// Line 716, Address: 0x21a42c, Func Offset: 0xcc
	// Line 717, Address: 0x21a430, Func Offset: 0xd0
	// Line 720, Address: 0x21a434, Func Offset: 0xd4
	// Line 715, Address: 0x21a438, Func Offset: 0xd8
	// Line 718, Address: 0x21a43c, Func Offset: 0xdc
	// Line 720, Address: 0x21a440, Func Offset: 0xe0
	// Line 719, Address: 0x21a448, Func Offset: 0xe8
	// Line 720, Address: 0x21a44c, Func Offset: 0xec
	// Line 721, Address: 0x21a454, Func Offset: 0xf4
	// Line 726, Address: 0x21a470, Func Offset: 0x110
	// Line 727, Address: 0x21a478, Func Offset: 0x118
	// Line 736, Address: 0x21a480, Func Offset: 0x120
	// Line 726, Address: 0x21a484, Func Offset: 0x124
	// Line 727, Address: 0x21a48c, Func Offset: 0x12c
	// Line 728, Address: 0x21a498, Func Offset: 0x138
	// Line 727, Address: 0x21a49c, Func Offset: 0x13c
	// Line 728, Address: 0x21a4a0, Func Offset: 0x140
	// Line 729, Address: 0x21a4b0, Func Offset: 0x150
	// Line 728, Address: 0x21a4b4, Func Offset: 0x154
	// Line 729, Address: 0x21a4b8, Func Offset: 0x158
	// Line 736, Address: 0x21a4cc, Func Offset: 0x16c
	// Line 737, Address: 0x21a4d8, Func Offset: 0x178
	// Line 738, Address: 0x21a4e0, Func Offset: 0x180
	// Line 739, Address: 0x21a4e8, Func Offset: 0x188
	// Line 743, Address: 0x21a4f4, Func Offset: 0x194
	// Line 744, Address: 0x21a520, Func Offset: 0x1c0
	// Func End, Address: 0x21a550, Func Offset: 0x1f0
}

// 
// Start address: 0x21a550
void bhEne_SetWeponAtr(BH_PWORK* epw, char j1, char j2, float r)
{
	_anon31* owk;
	// Line 760, Address: 0x21a550, Func Offset: 0
	// Line 765, Address: 0x21a554, Func Offset: 0x4
	// Line 760, Address: 0x21a558, Func Offset: 0x8
	// Line 765, Address: 0x21a568, Func Offset: 0x18
	// Line 760, Address: 0x21a56c, Func Offset: 0x1c
	// Line 765, Address: 0x21a574, Func Offset: 0x24
	// Line 760, Address: 0x21a580, Func Offset: 0x30
	// Line 761, Address: 0x21a584, Func Offset: 0x34
	// Line 762, Address: 0x21a58c, Func Offset: 0x3c
	// Line 763, Address: 0x21a594, Func Offset: 0x44
	// Line 765, Address: 0x21a59c, Func Offset: 0x4c
	// Line 766, Address: 0x21a5a8, Func Offset: 0x58
	// Line 767, Address: 0x21a5b0, Func Offset: 0x60
	// Line 768, Address: 0x21a5b8, Func Offset: 0x68
	// Line 771, Address: 0x21a5c0, Func Offset: 0x70
	// Func End, Address: 0x21a5c8, Func Offset: 0x78
}

// 
// Start address: 0x21a5d0
unsigned char bhEne_AttackHitCheck(BH_PWORK* pl, _anon6* pos, float ar)
{
	_anon45 sphere;
	int kno;
	int i;
	float knr;
	float ll;
	_anon6 vec;
	// Line 783, Address: 0x21a5d0, Func Offset: 0
	// Line 789, Address: 0x21a5f8, Func Offset: 0x28
	// Line 795, Address: 0x21a604, Func Offset: 0x34
	// Line 794, Address: 0x21a60c, Func Offset: 0x3c
	// Line 789, Address: 0x21a610, Func Offset: 0x40
	// Line 790, Address: 0x21a614, Func Offset: 0x44
	// Line 791, Address: 0x21a61c, Func Offset: 0x4c
	// Line 795, Address: 0x21a624, Func Offset: 0x54
	// Line 796, Address: 0x21a638, Func Offset: 0x68
	// Line 797, Address: 0x21a63c, Func Offset: 0x6c
	// Line 798, Address: 0x21a648, Func Offset: 0x78
	// Line 799, Address: 0x21a650, Func Offset: 0x80
	// Line 800, Address: 0x21a654, Func Offset: 0x84
	// Line 798, Address: 0x21a658, Func Offset: 0x88
	// Line 801, Address: 0x21a660, Func Offset: 0x90
	// Line 798, Address: 0x21a664, Func Offset: 0x94
	// Line 799, Address: 0x21a66c, Func Offset: 0x9c
	// Line 800, Address: 0x21a688, Func Offset: 0xb8
	// Line 801, Address: 0x21a6a0, Func Offset: 0xd0
	// Line 802, Address: 0x21a6a8, Func Offset: 0xd8
	// Line 804, Address: 0x21a6b8, Func Offset: 0xe8
	// Line 805, Address: 0x21a6bc, Func Offset: 0xec
	// Line 803, Address: 0x21a6c0, Func Offset: 0xf0
	// Line 805, Address: 0x21a6c4, Func Offset: 0xf4
	// Line 806, Address: 0x21a6cc, Func Offset: 0xfc
	// Line 807, Address: 0x21a6d8, Func Offset: 0x108
	// Line 808, Address: 0x21a6e4, Func Offset: 0x114
	// Line 807, Address: 0x21a6e8, Func Offset: 0x118
	// Line 809, Address: 0x21a6ec, Func Offset: 0x11c
	// Line 810, Address: 0x21a704, Func Offset: 0x134
	// Line 812, Address: 0x21a708, Func Offset: 0x138
	// Line 813, Address: 0x21a710, Func Offset: 0x140
	// Line 814, Address: 0x21a714, Func Offset: 0x144
	// Line 818, Address: 0x21a718, Func Offset: 0x148
	// Line 814, Address: 0x21a71c, Func Offset: 0x14c
	// Line 815, Address: 0x21a720, Func Offset: 0x150
	// Line 816, Address: 0x21a728, Func Offset: 0x158
	// Line 818, Address: 0x21a72c, Func Offset: 0x15c
	// Line 821, Address: 0x21a734, Func Offset: 0x164
	// Line 822, Address: 0x21a738, Func Offset: 0x168
	// Func End, Address: 0x21a764, Func Offset: 0x194
}

// 
// Start address: 0x21a770
void bhEne_AddNullTrans(BH_PWORK* epw, _anon6* mtn)
{
	_anon6 v;
	// Line 833, Address: 0x21a770, Func Offset: 0
	// Line 836, Address: 0x21a788, Func Offset: 0x18
	// Line 837, Address: 0x21a790, Func Offset: 0x20
	// Line 838, Address: 0x21a79c, Func Offset: 0x2c
	// Line 840, Address: 0x21a7c0, Func Offset: 0x50
	// Line 841, Address: 0x21a7d0, Func Offset: 0x60
	// Line 842, Address: 0x21a7e0, Func Offset: 0x70
	// Func End, Address: 0x21a7f4, Func Offset: 0x84
}

// 
// Start address: 0x21a800
void bhEne_AddNullTransDir(BH_PWORK* epw, int ay, _anon6* mtn)
{
	_anon6 v;
	// Line 853, Address: 0x21a800, Func Offset: 0
	// Line 856, Address: 0x21a820, Func Offset: 0x20
	// Line 857, Address: 0x21a828, Func Offset: 0x28
	// Line 858, Address: 0x21a834, Func Offset: 0x34
	// Line 860, Address: 0x21a858, Func Offset: 0x58
	// Line 861, Address: 0x21a868, Func Offset: 0x68
	// Line 862, Address: 0x21a878, Func Offset: 0x78
	// Func End, Address: 0x21a890, Func Offset: 0x90
}

// 
// Start address: 0x21a890
float bhEne_GetShapeCnt(_anon40* p, int key)
{
	_anon40* pp;
	// Line 878, Address: 0x21a890, Func Offset: 0
	// Line 880, Address: 0x21a8a0, Func Offset: 0x10
	// Line 882, Address: 0x21a8a8, Func Offset: 0x18
	// Line 885, Address: 0x21a8b8, Func Offset: 0x28
	// Line 886, Address: 0x21a8f4, Func Offset: 0x64
	// Func End, Address: 0x21a8fc, Func Offset: 0x6c
}

// 
// Start address: 0x21a900
void bhEne_CalcDamage(BH_PWORK* epw, _anon18* CombWepTbl, _anon20* CombJointTbl)
{
	_anon18* cwp;
	_anon20* cjp;
	unsigned int i;
	int dam;
	// Line 898, Address: 0x21a900, Func Offset: 0
	// Line 902, Address: 0x21a90c, Func Offset: 0xc
	// Line 905, Address: 0x21a910, Func Offset: 0x10
	// Line 908, Address: 0x21a91c, Func Offset: 0x1c
	// Line 902, Address: 0x21a920, Func Offset: 0x20
	// Line 905, Address: 0x21a924, Func Offset: 0x24
	// Line 902, Address: 0x21a92c, Func Offset: 0x2c
	// Line 908, Address: 0x21a930, Func Offset: 0x30
	// Line 902, Address: 0x21a934, Func Offset: 0x34
	// Line 908, Address: 0x21a938, Func Offset: 0x38
	// Line 902, Address: 0x21a93c, Func Offset: 0x3c
	// Line 908, Address: 0x21a944, Func Offset: 0x44
	// Line 910, Address: 0x21a94c, Func Offset: 0x4c
	// Line 912, Address: 0x21a954, Func Offset: 0x54
	// Line 914, Address: 0x21a960, Func Offset: 0x60
	// Line 915, Address: 0x21a970, Func Offset: 0x70
	// Line 916, Address: 0x21a98c, Func Offset: 0x8c
	// Line 917, Address: 0x21a990, Func Offset: 0x90
	// Line 919, Address: 0x21a998, Func Offset: 0x98
	// Line 920, Address: 0x21a9a0, Func Offset: 0xa0
	// Line 921, Address: 0x21a9a4, Func Offset: 0xa4
	// Line 922, Address: 0x21a9ac, Func Offset: 0xac
	// Line 924, Address: 0x21a9b0, Func Offset: 0xb0
	// Line 925, Address: 0x21a9d0, Func Offset: 0xd0
	// Line 926, Address: 0x21a9f0, Func Offset: 0xf0
	// Line 930, Address: 0x21aa10, Func Offset: 0x110
	// Line 931, Address: 0x21aa2c, Func Offset: 0x12c
	// Line 932, Address: 0x21aa38, Func Offset: 0x138
	// Line 933, Address: 0x21aa48, Func Offset: 0x148
	// Line 934, Address: 0x21aa4c, Func Offset: 0x14c
	// Line 936, Address: 0x21aa50, Func Offset: 0x150
	// Line 937, Address: 0x21aa7c, Func Offset: 0x17c
	// Line 939, Address: 0x21aa84, Func Offset: 0x184
	// Line 940, Address: 0x21aaac, Func Offset: 0x1ac
	// Line 943, Address: 0x21aab0, Func Offset: 0x1b0
	// Line 957, Address: 0x21aabc, Func Offset: 0x1bc
	// Line 943, Address: 0x21aac0, Func Offset: 0x1c0
	// Line 957, Address: 0x21aac4, Func Offset: 0x1c4
	// Line 960, Address: 0x21aae4, Func Offset: 0x1e4
	// Line 961, Address: 0x21aaf4, Func Offset: 0x1f4
	// Line 962, Address: 0x21aafc, Func Offset: 0x1fc
	// Line 963, Address: 0x21ab04, Func Offset: 0x204
	// Line 965, Address: 0x21ab10, Func Offset: 0x210
	// Func End, Address: 0x21ab20, Func Offset: 0x220
}

// 
// Start address: 0x21ab20
void bhEne_InitDamage(BH_PWORK* epw)
{
	int i;
	// Line 979, Address: 0x21ab20, Func Offset: 0
	// Line 980, Address: 0x21ab2c, Func Offset: 0xc
	// Line 981, Address: 0x21ab38, Func Offset: 0x18
	// Line 982, Address: 0x21ab40, Func Offset: 0x20
	// Line 983, Address: 0x21ab5c, Func Offset: 0x3c
	// Line 986, Address: 0x21ab60, Func Offset: 0x40
	// Line 987, Address: 0x21ab6c, Func Offset: 0x4c
	// Line 991, Address: 0x21ab74, Func Offset: 0x54
	// Line 992, Address: 0x21ab7c, Func Offset: 0x5c
	// Line 991, Address: 0x21ab80, Func Offset: 0x60
	// Line 992, Address: 0x21ab88, Func Offset: 0x68
	// Line 993, Address: 0x21ab90, Func Offset: 0x70
	// Func End, Address: 0x21ab98, Func Offset: 0x78
}

// 
// Start address: 0x21aba0
void bhEne_CallSE(BH_PWORK* epw, _anon6* pos, int se)
{
	// Line 1005, Address: 0x21aba0, Func Offset: 0
	// Line 1006, Address: 0x21aba8, Func Offset: 0x8
	// Line 1007, Address: 0x21abbc, Func Offset: 0x1c
	// Line 1009, Address: 0x21abd4, Func Offset: 0x34
	// Func End, Address: 0x21abe0, Func Offset: 0x40
}

// 
// Start address: 0x21abe0
void bhEne_CallSE_EX(BH_PWORK* epw, _anon6* pos, int se, int fade)
{
	// Line 1021, Address: 0x21abe0, Func Offset: 0
	// Line 1022, Address: 0x21abe8, Func Offset: 0x8
	// Line 1023, Address: 0x21abfc, Func Offset: 0x1c
	// Line 1025, Address: 0x21ac14, Func Offset: 0x34
	// Func End, Address: 0x21ac20, Func Offset: 0x40
}

// 
// Start address: 0x21ac20
void bhEne_CallEffectSE(_anon6* pos, int se)
{
	// Line 1037, Address: 0x21ac24, Func Offset: 0x4
	// Func End, Address: 0x21ac30, Func Offset: 0x10
}

// 
// Start address: 0x21ac30
void bhEne_SetSEPan(_anon6* pos, int se)
{
	// Line 1051, Address: 0x21ac30, Func Offset: 0
	// Func End, Address: 0x21ac50, Func Offset: 0x20
}

// 
// Start address: 0x21ac50
int bhEne_CheckPlayEffectSE(int se)
{
	// Line 1063, Address: 0x21ac54, Func Offset: 0x4
	// Func End, Address: 0x21ac5c, Func Offset: 0xc
}

// 
// Start address: 0x21ac60
int bhArcTan2(float y, float x)
{
	int ang;
	float len;
	// Line 1075, Address: 0x21ac60, Func Offset: 0
	// Line 1079, Address: 0x21ac74, Func Offset: 0x14
	// Line 1080, Address: 0x21ac84, Func Offset: 0x24
	// Line 1082, Address: 0x21aca4, Func Offset: 0x44
	// Line 1084, Address: 0x21acd4, Func Offset: 0x74
	// Line 1085, Address: 0x21acec, Func Offset: 0x8c
	// Line 1094, Address: 0x21acfc, Func Offset: 0x9c
	// Func End, Address: 0x21ad10, Func Offset: 0xb0
}

// 
// Start address: 0x21ad10
_anon21* bhEne_CheckEventAtr(int flr_no, float px, float pz, int id, int min, int max)
{
	int flr_n;
	int i;
	_anon21* fp;
	// Line 1113, Address: 0x21ad10, Func Offset: 0
	// Line 1114, Address: 0x21ad34, Func Offset: 0x24
	// Line 1117, Address: 0x21ad44, Func Offset: 0x34
	// Line 1116, Address: 0x21ad48, Func Offset: 0x38
	// Line 1117, Address: 0x21ad84, Func Offset: 0x74
	// Line 1122, Address: 0x21adc8, Func Offset: 0xb8
	// Line 1125, Address: 0x21ae2c, Func Offset: 0x11c
	// Line 1128, Address: 0x21ae34, Func Offset: 0x124
	// Line 1129, Address: 0x21ae48, Func Offset: 0x138
	// Line 1130, Address: 0x21ae4c, Func Offset: 0x13c
	// Func End, Address: 0x21ae54, Func Offset: 0x144
}

// 
// Start address: 0x21ae60
void bhEne_EraseArrow(BH_PWORK* epw, int obj_no)
{
	_anon0* op;
	int i;
	// Line 1145, Address: 0x21ae60, Func Offset: 0
	// Line 1146, Address: 0x21ae68, Func Offset: 0x8
	// Line 1148, Address: 0x21ae6c, Func Offset: 0xc
	// Line 1147, Address: 0x21ae70, Func Offset: 0x10
	// Line 1148, Address: 0x21ae8c, Func Offset: 0x2c
	// Line 1151, Address: 0x21aeb0, Func Offset: 0x50
	// Line 1153, Address: 0x21aeb4, Func Offset: 0x54
	// Line 1154, Address: 0x21aeb8, Func Offset: 0x58
	// Line 1155, Address: 0x21aec8, Func Offset: 0x68
	// Func End, Address: 0x21aed0, Func Offset: 0x70
}

