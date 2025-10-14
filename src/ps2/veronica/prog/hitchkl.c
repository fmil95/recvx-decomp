#include "hitchkl.h"

/*_anon37 PLANE;
_anon0* sys;
_anon12* rom;

_anon6* bhCollisionCheckLine(_anon2* p1, _anon2* p2);
_anon6* bhCollisionCheckLine2(_anon2* p1, _anon2* p2, unsigned int flg, char flr_no);
_anon6* bhCollisionCheckLine3(_anon2* p1, _anon2* p2, unsigned int flg, char flr_no);
int bhCollisionCheckLineMain(_anon6* hp, _anon2* vec, _anon2* p1, _anon2* p2);
int bhCollisionCheckL2PL(_anon2* p1, _anon2* p2, _anon2* area, int num);
int bhInOutCheck(_anon2* p, _anon2* area, _anon2* normal, int num);
int bhCollisionCheckL2MDL(_anon2* p1, _anon2* p2, _anon31* mdl, float mtx[16]);
int bhCollisionCheckL2XZPL(_anon2* p1, _anon2* p2, _anon2* pos, float w, float d, int flg);
int bhCollisionCheckL2XYPL(_anon2* p1, _anon2* p2, _anon2* pos, float w, float h, int flg);
int bhCollisionCheckL2YZPL(_anon2* p1, _anon2* p2, _anon2* pos, float h, float d, int flg);
void bhGetHitCollisionNormal(_anon2* n);

// 
// Start address: 0x269370
_anon6* bhCollisionCheckLine(_anon2* p1, _anon2* p2)
{
	_anon2 vec;
	int wal_n;
	int i;
	_anon6* ret;
	_anon6* hp;
	// Line 82, Address: 0x269370, Func Offset: 0
	// Line 88, Address: 0x269394, Func Offset: 0x24
	// Line 92, Address: 0x26939c, Func Offset: 0x2c
	// Line 83, Address: 0x2693ac, Func Offset: 0x3c
	// Line 88, Address: 0x2693b0, Func Offset: 0x40
	// Line 92, Address: 0x2693b4, Func Offset: 0x44
	// Line 88, Address: 0x2693bc, Func Offset: 0x4c
	// Line 89, Address: 0x2693c0, Func Offset: 0x50
	// Line 92, Address: 0x2693c8, Func Offset: 0x58
	// Line 89, Address: 0x2693d0, Func Offset: 0x60
	// Line 90, Address: 0x2693d8, Func Offset: 0x68
	// Line 92, Address: 0x2693e8, Func Offset: 0x78
	// Line 93, Address: 0x2693f4, Func Offset: 0x84
	// Line 95, Address: 0x269404, Func Offset: 0x94
	// Line 97, Address: 0x269450, Func Offset: 0xe0
	// Line 98, Address: 0x269460, Func Offset: 0xf0
	// Line 99, Address: 0x26947c, Func Offset: 0x10c
	// Line 101, Address: 0x269480, Func Offset: 0x110
	// Line 103, Address: 0x269490, Func Offset: 0x120
	// Line 104, Address: 0x269494, Func Offset: 0x124
	// Func End, Address: 0x2694bc, Func Offset: 0x14c
}

// 
// Start address: 0x2694c0
_anon6* bhCollisionCheckLine2(_anon2* p1, _anon2* p2, unsigned int flg, char flr_no)
{
	_anon2 vec;
	int wal_n;
	int i;
	_anon6* ret;
	_anon6* hp;
	// Line 118, Address: 0x2694c0, Func Offset: 0
	// Line 124, Address: 0x2694ec, Func Offset: 0x2c
	// Line 128, Address: 0x2694f4, Func Offset: 0x34
	// Line 119, Address: 0x269504, Func Offset: 0x44
	// Line 124, Address: 0x269508, Func Offset: 0x48
	// Line 128, Address: 0x26950c, Func Offset: 0x4c
	// Line 124, Address: 0x269514, Func Offset: 0x54
	// Line 125, Address: 0x269518, Func Offset: 0x58
	// Line 128, Address: 0x269520, Func Offset: 0x60
	// Line 125, Address: 0x269528, Func Offset: 0x68
	// Line 126, Address: 0x269530, Func Offset: 0x70
	// Line 128, Address: 0x269540, Func Offset: 0x80
	// Line 129, Address: 0x26954c, Func Offset: 0x8c
	// Line 131, Address: 0x26956c, Func Offset: 0xac
	// Line 133, Address: 0x2695b8, Func Offset: 0xf8
	// Line 135, Address: 0x2695c8, Func Offset: 0x108
	// Line 136, Address: 0x2695d8, Func Offset: 0x118
	// Line 141, Address: 0x269624, Func Offset: 0x164
	// Line 142, Address: 0x269628, Func Offset: 0x168
	// Line 143, Address: 0x269644, Func Offset: 0x184
	// Line 145, Address: 0x269648, Func Offset: 0x188
	// Line 147, Address: 0x269658, Func Offset: 0x198
	// Line 148, Address: 0x26965c, Func Offset: 0x19c
	// Func End, Address: 0x26968c, Func Offset: 0x1cc
}

// 
// Start address: 0x269690
_anon6* bhCollisionCheckLine3(_anon2* p1, _anon2* p2, unsigned int flg, char flr_no)
{
	_anon2 vec;
	int wal_n;
	int i;
	_anon6* ret;
	_anon6* hp;
	// Line 163, Address: 0x269690, Func Offset: 0
	// Line 169, Address: 0x2696bc, Func Offset: 0x2c
	// Line 173, Address: 0x2696c4, Func Offset: 0x34
	// Line 164, Address: 0x2696d4, Func Offset: 0x44
	// Line 169, Address: 0x2696d8, Func Offset: 0x48
	// Line 173, Address: 0x2696dc, Func Offset: 0x4c
	// Line 169, Address: 0x2696e4, Func Offset: 0x54
	// Line 170, Address: 0x2696e8, Func Offset: 0x58
	// Line 173, Address: 0x2696f0, Func Offset: 0x60
	// Line 170, Address: 0x2696f8, Func Offset: 0x68
	// Line 171, Address: 0x269700, Func Offset: 0x70
	// Line 173, Address: 0x269710, Func Offset: 0x80
	// Line 174, Address: 0x26971c, Func Offset: 0x8c
	// Line 176, Address: 0x26973c, Func Offset: 0xac
	// Line 178, Address: 0x269788, Func Offset: 0xf8
	// Line 180, Address: 0x269798, Func Offset: 0x108
	// Line 181, Address: 0x2697a8, Func Offset: 0x118
	// Line 187, Address: 0x269804, Func Offset: 0x174
	// Line 188, Address: 0x269808, Func Offset: 0x178
	// Line 189, Address: 0x269824, Func Offset: 0x194
	// Line 191, Address: 0x269828, Func Offset: 0x198
	// Line 193, Address: 0x269838, Func Offset: 0x1a8
	// Line 194, Address: 0x26983c, Func Offset: 0x1ac
	// Func End, Address: 0x26986c, Func Offset: 0x1dc
}

// 
// Start address: 0x269870
int bhCollisionCheckLineMain(_anon6* hp, _anon2* vec, _anon2* p1, _anon2* p2)
{
	_anon2 pos;
	_anon2 area[8];
	int j;
	int ret;
	// Line 205, Address: 0x269870, Func Offset: 0
	// Line 211, Address: 0x269874, Func Offset: 0x4
	// Line 205, Address: 0x269878, Func Offset: 0x8
	// Line 211, Address: 0x2698a8, Func Offset: 0x38
	// Line 212, Address: 0x2698e4, Func Offset: 0x74
	// Line 215, Address: 0x269910, Func Offset: 0xa0
	// Line 216, Address: 0x26993c, Func Offset: 0xcc
	// Line 217, Address: 0x269968, Func Offset: 0xf8
	// Line 218, Address: 0x269994, Func Offset: 0x124
	// Line 221, Address: 0x2699c0, Func Offset: 0x150
	// Line 222, Address: 0x269a0c, Func Offset: 0x19c
	// Line 223, Address: 0x269a10, Func Offset: 0x1a0
	// Line 225, Address: 0x269a14, Func Offset: 0x1a4
	// Line 223, Address: 0x269a20, Func Offset: 0x1b0
	// Line 224, Address: 0x269a28, Func Offset: 0x1b8
	// Line 225, Address: 0x269a30, Func Offset: 0x1c0
	// Line 228, Address: 0x269a48, Func Offset: 0x1d8
	// Line 226, Address: 0x269a4c, Func Offset: 0x1dc
	// Line 228, Address: 0x269a50, Func Offset: 0x1e0
	// Line 234, Address: 0x269a58, Func Offset: 0x1e8
	// Line 235, Address: 0x269aa0, Func Offset: 0x230
	// Line 238, Address: 0x269aa4, Func Offset: 0x234
	// Line 235, Address: 0x269ab4, Func Offset: 0x244
	// Line 236, Address: 0x269ab8, Func Offset: 0x248
	// Line 237, Address: 0x269ac0, Func Offset: 0x250
	// Line 238, Address: 0x269ac8, Func Offset: 0x258
	// Line 241, Address: 0x269adc, Func Offset: 0x26c
	// Line 239, Address: 0x269ae0, Func Offset: 0x270
	// Line 241, Address: 0x269ae4, Func Offset: 0x274
	// Line 247, Address: 0x269ae8, Func Offset: 0x278
	// Line 248, Address: 0x269b30, Func Offset: 0x2c0
	// Line 249, Address: 0x269b34, Func Offset: 0x2c4
	// Line 251, Address: 0x269b38, Func Offset: 0x2c8
	// Line 249, Address: 0x269b48, Func Offset: 0x2d8
	// Line 250, Address: 0x269b4c, Func Offset: 0x2dc
	// Line 251, Address: 0x269b54, Func Offset: 0x2e4
	// Line 254, Address: 0x269b68, Func Offset: 0x2f8
	// Line 252, Address: 0x269b6c, Func Offset: 0x2fc
	// Line 254, Address: 0x269b70, Func Offset: 0x300
	// Line 260, Address: 0x269b74, Func Offset: 0x304
	// Line 261, Address: 0x269bc4, Func Offset: 0x354
	// Line 264, Address: 0x269bc8, Func Offset: 0x358
	// Line 261, Address: 0x269bd8, Func Offset: 0x368
	// Line 262, Address: 0x269bdc, Func Offset: 0x36c
	// Line 263, Address: 0x269be4, Func Offset: 0x374
	// Line 264, Address: 0x269bf4, Func Offset: 0x384
	// Line 267, Address: 0x269c08, Func Offset: 0x398
	// Line 265, Address: 0x269c10, Func Offset: 0x3a0
	// Line 267, Address: 0x269c14, Func Offset: 0x3a4
	// Line 273, Address: 0x269c1c, Func Offset: 0x3ac
	// Line 274, Address: 0x269c6c, Func Offset: 0x3fc
	// Line 275, Address: 0x269c70, Func Offset: 0x400
	// Line 277, Address: 0x269c74, Func Offset: 0x404
	// Line 275, Address: 0x269c84, Func Offset: 0x414
	// Line 276, Address: 0x269c88, Func Offset: 0x418
	// Line 277, Address: 0x269c90, Func Offset: 0x420
	// Line 280, Address: 0x269ca4, Func Offset: 0x434
	// Line 278, Address: 0x269cac, Func Offset: 0x43c
	// Line 280, Address: 0x269cb0, Func Offset: 0x440
	// Line 286, Address: 0x269cb8, Func Offset: 0x448
	// Line 287, Address: 0x269d00, Func Offset: 0x490
	// Line 290, Address: 0x269d04, Func Offset: 0x494
	// Line 287, Address: 0x269d10, Func Offset: 0x4a0
	// Line 288, Address: 0x269d14, Func Offset: 0x4a4
	// Line 289, Address: 0x269d1c, Func Offset: 0x4ac
	// Line 290, Address: 0x269d24, Func Offset: 0x4b4
	// Line 293, Address: 0x269d3c, Func Offset: 0x4cc
	// Line 291, Address: 0x269d40, Func Offset: 0x4d0
	// Line 297, Address: 0x269d44, Func Offset: 0x4d4
	// Line 299, Address: 0x269d4c, Func Offset: 0x4dc
	// Line 300, Address: 0x269d78, Func Offset: 0x508
	// Line 301, Address: 0x269da4, Func Offset: 0x534
	// Line 302, Address: 0x269dd0, Func Offset: 0x560
	// Line 305, Address: 0x269dfc, Func Offset: 0x58c
	// Line 306, Address: 0x269e48, Func Offset: 0x5d8
	// Line 307, Address: 0x269e4c, Func Offset: 0x5dc
	// Line 309, Address: 0x269e54, Func Offset: 0x5e4
	// Line 307, Address: 0x269e60, Func Offset: 0x5f0
	// Line 308, Address: 0x269e68, Func Offset: 0x5f8
	// Line 309, Address: 0x269e70, Func Offset: 0x600
	// Line 312, Address: 0x269e88, Func Offset: 0x618
	// Line 310, Address: 0x269e90, Func Offset: 0x620
	// Line 312, Address: 0x269e94, Func Offset: 0x624
	// Line 318, Address: 0x269e9c, Func Offset: 0x62c
	// Line 319, Address: 0x269ee4, Func Offset: 0x674
	// Line 322, Address: 0x269ee8, Func Offset: 0x678
	// Line 319, Address: 0x269ef4, Func Offset: 0x684
	// Line 320, Address: 0x269ef8, Func Offset: 0x688
	// Line 321, Address: 0x269f00, Func Offset: 0x690
	// Line 322, Address: 0x269f08, Func Offset: 0x698
	// Line 325, Address: 0x269f20, Func Offset: 0x6b0
	// Line 323, Address: 0x269f24, Func Offset: 0x6b4
	// Line 325, Address: 0x269f28, Func Offset: 0x6b8
	// Line 331, Address: 0x269f2c, Func Offset: 0x6bc
	// Line 332, Address: 0x269f88, Func Offset: 0x718
	// Line 335, Address: 0x269f8c, Func Offset: 0x71c
	// Line 332, Address: 0x269f98, Func Offset: 0x728
	// Line 333, Address: 0x269f9c, Func Offset: 0x72c
	// Line 335, Address: 0x269fa4, Func Offset: 0x734
	// Line 333, Address: 0x269fa8, Func Offset: 0x738
	// Line 334, Address: 0x269fb0, Func Offset: 0x740
	// Line 335, Address: 0x269fb8, Func Offset: 0x748
	// Line 338, Address: 0x269fd0, Func Offset: 0x760
	// Line 336, Address: 0x269fd4, Func Offset: 0x764
	// Line 338, Address: 0x269fd8, Func Offset: 0x768
	// Line 344, Address: 0x269fdc, Func Offset: 0x76c
	// Line 345, Address: 0x26a038, Func Offset: 0x7c8
	// Line 346, Address: 0x26a03c, Func Offset: 0x7cc
	// Line 348, Address: 0x26a044, Func Offset: 0x7d4
	// Line 346, Address: 0x26a050, Func Offset: 0x7e0
	// Line 348, Address: 0x26a054, Func Offset: 0x7e4
	// Line 346, Address: 0x26a058, Func Offset: 0x7e8
	// Line 347, Address: 0x26a05c, Func Offset: 0x7ec
	// Line 348, Address: 0x26a064, Func Offset: 0x7f4
	// Line 351, Address: 0x26a07c, Func Offset: 0x80c
	// Line 349, Address: 0x26a080, Func Offset: 0x810
	// Line 351, Address: 0x26a084, Func Offset: 0x814
	// Line 357, Address: 0x26a088, Func Offset: 0x818
	// Line 358, Address: 0x26a0ec, Func Offset: 0x87c
	// Line 361, Address: 0x26a0f0, Func Offset: 0x880
	// Line 358, Address: 0x26a100, Func Offset: 0x890
	// Line 359, Address: 0x26a104, Func Offset: 0x894
	// Line 360, Address: 0x26a114, Func Offset: 0x8a4
	// Line 361, Address: 0x26a124, Func Offset: 0x8b4
	// Line 364, Address: 0x26a13c, Func Offset: 0x8cc
	// Line 362, Address: 0x26a144, Func Offset: 0x8d4
	// Line 364, Address: 0x26a148, Func Offset: 0x8d8
	// Line 370, Address: 0x26a150, Func Offset: 0x8e0
	// Line 371, Address: 0x26a1b4, Func Offset: 0x944
	// Line 372, Address: 0x26a1b8, Func Offset: 0x948
	// Line 374, Address: 0x26a1c0, Func Offset: 0x950
	// Line 372, Address: 0x26a1d0, Func Offset: 0x960
	// Line 373, Address: 0x26a1d8, Func Offset: 0x968
	// Line 374, Address: 0x26a1e0, Func Offset: 0x970
	// Line 377, Address: 0x26a1f8, Func Offset: 0x988
	// Line 375, Address: 0x26a200, Func Offset: 0x990
	// Line 377, Address: 0x26a204, Func Offset: 0x994
	// Line 381, Address: 0x26a208, Func Offset: 0x998
	// Line 384, Address: 0x26a210, Func Offset: 0x9a0
	// Line 385, Address: 0x26a244, Func Offset: 0x9d4
	// Line 386, Address: 0x26a274, Func Offset: 0xa04
	// Line 387, Address: 0x26a29c, Func Offset: 0xa2c
	// Line 390, Address: 0x26a2c4, Func Offset: 0xa54
	// Line 391, Address: 0x26a2c8, Func Offset: 0xa58
	// Line 392, Address: 0x26a2d0, Func Offset: 0xa60
	// Line 395, Address: 0x26a2d4, Func Offset: 0xa64
	// Line 391, Address: 0x26a2d8, Func Offset: 0xa68
	// Line 392, Address: 0x26a2dc, Func Offset: 0xa6c
	// Line 393, Address: 0x26a2e0, Func Offset: 0xa70
	// Line 398, Address: 0x26a2e4, Func Offset: 0xa74
	// Line 392, Address: 0x26a2ec, Func Offset: 0xa7c
	// Line 393, Address: 0x26a2f0, Func Offset: 0xa80
	// Line 394, Address: 0x26a300, Func Offset: 0xa90
	// Line 395, Address: 0x26a30c, Func Offset: 0xa9c
	// Line 396, Address: 0x26a314, Func Offset: 0xaa4
	// Line 397, Address: 0x26a320, Func Offset: 0xab0
	// Line 399, Address: 0x26a328, Func Offset: 0xab8
	// Line 404, Address: 0x26a330, Func Offset: 0xac0
	// Line 399, Address: 0x26a338, Func Offset: 0xac8
	// Line 404, Address: 0x26a33c, Func Offset: 0xacc
	// Line 400, Address: 0x26a348, Func Offset: 0xad8
	// Line 404, Address: 0x26a34c, Func Offset: 0xadc
	// Line 400, Address: 0x26a358, Func Offset: 0xae8
	// Line 401, Address: 0x26a35c, Func Offset: 0xaec
	// Line 404, Address: 0x26a360, Func Offset: 0xaf0
	// Line 401, Address: 0x26a364, Func Offset: 0xaf4
	// Line 402, Address: 0x26a368, Func Offset: 0xaf8
	// Line 404, Address: 0x26a36c, Func Offset: 0xafc
	// Line 405, Address: 0x26a388, Func Offset: 0xb18
	// Line 404, Address: 0x26a38c, Func Offset: 0xb1c
	// Line 405, Address: 0x26a398, Func Offset: 0xb28
	// Line 407, Address: 0x26a3b0, Func Offset: 0xb40
	// Line 405, Address: 0x26a3b8, Func Offset: 0xb48
	// Line 407, Address: 0x26a3bc, Func Offset: 0xb4c
	// Line 405, Address: 0x26a3c4, Func Offset: 0xb54
	// Line 407, Address: 0x26a3cc, Func Offset: 0xb5c
	// Line 408, Address: 0x26a3e0, Func Offset: 0xb70
	// Line 411, Address: 0x26a3f0, Func Offset: 0xb80
	// Line 412, Address: 0x26a40c, Func Offset: 0xb9c
	// Line 413, Address: 0x26a418, Func Offset: 0xba8
	// Line 415, Address: 0x26a454, Func Offset: 0xbe4
	// Line 413, Address: 0x26a458, Func Offset: 0xbe8
	// Line 414, Address: 0x26a464, Func Offset: 0xbf4
	// Line 415, Address: 0x26a46c, Func Offset: 0xbfc
	// Line 417, Address: 0x26a484, Func Offset: 0xc14
	// Line 415, Address: 0x26a48c, Func Offset: 0xc1c
	// Line 417, Address: 0x26a490, Func Offset: 0xc20
	// Line 415, Address: 0x26a498, Func Offset: 0xc28
	// Line 417, Address: 0x26a49c, Func Offset: 0xc2c
	// Line 420, Address: 0x26a4ac, Func Offset: 0xc3c
	// Line 418, Address: 0x26a4b4, Func Offset: 0xc44
	// Line 420, Address: 0x26a4b8, Func Offset: 0xc48
	// Line 422, Address: 0x26a4bc, Func Offset: 0xc4c
	// Line 423, Address: 0x26a4c0, Func Offset: 0xc50
	// Line 420, Address: 0x26a4c8, Func Offset: 0xc58
	// Line 423, Address: 0x26a4cc, Func Offset: 0xc5c
	// Line 425, Address: 0x26a4d4, Func Offset: 0xc64
	// Line 428, Address: 0x26a4dc, Func Offset: 0xc6c
	// Line 429, Address: 0x26a4f4, Func Offset: 0xc84
	// Line 430, Address: 0x26a520, Func Offset: 0xcb0
	// Line 431, Address: 0x26a54c, Func Offset: 0xcdc
	// Line 432, Address: 0x26a554, Func Offset: 0xce4
	// Line 433, Address: 0x26a588, Func Offset: 0xd18
	// Line 435, Address: 0x26a5ac, Func Offset: 0xd3c
	// Line 436, Address: 0x26a5c0, Func Offset: 0xd50
	// Line 437, Address: 0x26a5ec, Func Offset: 0xd7c
	// Line 438, Address: 0x26a618, Func Offset: 0xda8
	// Line 439, Address: 0x26a620, Func Offset: 0xdb0
	// Line 440, Address: 0x26a654, Func Offset: 0xde4
	// Line 443, Address: 0x26a678, Func Offset: 0xe08
	// Line 445, Address: 0x26a68c, Func Offset: 0xe1c
	// Line 446, Address: 0x26a6a8, Func Offset: 0xe38
	// Line 447, Address: 0x26a6ac, Func Offset: 0xe3c
	// Line 455, Address: 0x26a6b0, Func Offset: 0xe40
	// Line 446, Address: 0x26a6b8, Func Offset: 0xe48
	// Line 447, Address: 0x26a6bc, Func Offset: 0xe4c
	// Line 455, Address: 0x26a6c0, Func Offset: 0xe50
	// Line 447, Address: 0x26a6c8, Func Offset: 0xe58
	// Line 448, Address: 0x26a6d0, Func Offset: 0xe60
	// Line 449, Address: 0x26a6d8, Func Offset: 0xe68
	// Line 450, Address: 0x26a6e0, Func Offset: 0xe70
	// Line 451, Address: 0x26a6ec, Func Offset: 0xe7c
	// Line 452, Address: 0x26a6fc, Func Offset: 0xe8c
	// Line 453, Address: 0x26a70c, Func Offset: 0xe9c
	// Line 454, Address: 0x26a718, Func Offset: 0xea8
	// Line 455, Address: 0x26a71c, Func Offset: 0xeac
	// Line 458, Address: 0x26a72c, Func Offset: 0xebc
	// Line 456, Address: 0x26a730, Func Offset: 0xec0
	// Line 458, Address: 0x26a734, Func Offset: 0xec4
	// Line 464, Address: 0x26a738, Func Offset: 0xec8
	// Line 465, Address: 0x26a73c, Func Offset: 0xecc
	// Line 466, Address: 0x26a740, Func Offset: 0xed0
	// Line 472, Address: 0x26a744, Func Offset: 0xed4
	// Line 464, Address: 0x26a748, Func Offset: 0xed8
	// Line 465, Address: 0x26a74c, Func Offset: 0xedc
	// Line 473, Address: 0x26a750, Func Offset: 0xee0
	// Line 474, Address: 0x26a754, Func Offset: 0xee4
	// Line 475, Address: 0x26a758, Func Offset: 0xee8
	// Line 465, Address: 0x26a75c, Func Offset: 0xeec
	// Line 466, Address: 0x26a760, Func Offset: 0xef0
	// Line 467, Address: 0x26a764, Func Offset: 0xef4
	// Line 476, Address: 0x26a768, Func Offset: 0xef8
	// Line 466, Address: 0x26a770, Func Offset: 0xf00
	// Line 467, Address: 0x26a774, Func Offset: 0xf04
	// Line 476, Address: 0x26a778, Func Offset: 0xf08
	// Line 467, Address: 0x26a780, Func Offset: 0xf10
	// Line 468, Address: 0x26a784, Func Offset: 0xf14
	// Line 469, Address: 0x26a790, Func Offset: 0xf20
	// Line 470, Address: 0x26a7a4, Func Offset: 0xf34
	// Line 471, Address: 0x26a7b0, Func Offset: 0xf40
	// Line 472, Address: 0x26a7c0, Func Offset: 0xf50
	// Line 473, Address: 0x26a7d0, Func Offset: 0xf60
	// Line 474, Address: 0x26a7d8, Func Offset: 0xf68
	// Line 475, Address: 0x26a7e4, Func Offset: 0xf74
	// Line 476, Address: 0x26a7e8, Func Offset: 0xf78
	// Line 479, Address: 0x26a7f8, Func Offset: 0xf88
	// Line 477, Address: 0x26a7fc, Func Offset: 0xf8c
	// Line 479, Address: 0x26a800, Func Offset: 0xf90
	// Line 484, Address: 0x26a804, Func Offset: 0xf94
	// Line 485, Address: 0x26a808, Func Offset: 0xf98
	// Line 496, Address: 0x26a80c, Func Offset: 0xf9c
	// Line 484, Address: 0x26a814, Func Offset: 0xfa4
	// Line 485, Address: 0x26a818, Func Offset: 0xfa8
	// Line 496, Address: 0x26a81c, Func Offset: 0xfac
	// Line 485, Address: 0x26a824, Func Offset: 0xfb4
	// Line 486, Address: 0x26a828, Func Offset: 0xfb8
	// Line 487, Address: 0x26a82c, Func Offset: 0xfbc
	// Line 486, Address: 0x26a830, Func Offset: 0xfc0
	// Line 487, Address: 0x26a834, Func Offset: 0xfc4
	// Line 488, Address: 0x26a83c, Func Offset: 0xfcc
	// Line 489, Address: 0x26a84c, Func Offset: 0xfdc
	// Line 490, Address: 0x26a858, Func Offset: 0xfe8
	// Line 491, Address: 0x26a86c, Func Offset: 0xffc
	// Line 492, Address: 0x26a87c, Func Offset: 0x100c
	// Line 493, Address: 0x26a884, Func Offset: 0x1014
	// Line 494, Address: 0x26a894, Func Offset: 0x1024
	// Line 495, Address: 0x26a89c, Func Offset: 0x102c
	// Line 496, Address: 0x26a8a0, Func Offset: 0x1030
	// Line 499, Address: 0x26a8b0, Func Offset: 0x1040
	// Line 497, Address: 0x26a8b4, Func Offset: 0x1044
	// Line 499, Address: 0x26a8b8, Func Offset: 0x1048
	// Line 504, Address: 0x26a8bc, Func Offset: 0x104c
	// Line 505, Address: 0x26a8c4, Func Offset: 0x1054
	// Line 516, Address: 0x26a8c8, Func Offset: 0x1058
	// Line 504, Address: 0x26a8d0, Func Offset: 0x1060
	// Line 516, Address: 0x26a8d4, Func Offset: 0x1064
	// Line 504, Address: 0x26a8dc, Func Offset: 0x106c
	// Line 505, Address: 0x26a8e0, Func Offset: 0x1070
	// Line 506, Address: 0x26a8e8, Func Offset: 0x1078
	// Line 507, Address: 0x26a8ec, Func Offset: 0x107c
	// Line 506, Address: 0x26a8f0, Func Offset: 0x1080
	// Line 507, Address: 0x26a8f4, Func Offset: 0x1084
	// Line 508, Address: 0x26a904, Func Offset: 0x1094
	// Line 509, Address: 0x26a914, Func Offset: 0x10a4
	// Line 510, Address: 0x26a920, Func Offset: 0x10b0
	// Line 511, Address: 0x26a92c, Func Offset: 0x10bc
	// Line 512, Address: 0x26a93c, Func Offset: 0x10cc
	// Line 513, Address: 0x26a94c, Func Offset: 0x10dc
	// Line 514, Address: 0x26a954, Func Offset: 0x10e4
	// Line 515, Address: 0x26a95c, Func Offset: 0x10ec
	// Line 516, Address: 0x26a968, Func Offset: 0x10f8
	// Line 517, Address: 0x26a978, Func Offset: 0x1108
	// Line 519, Address: 0x26a980, Func Offset: 0x1110
	// Line 520, Address: 0x26a99c, Func Offset: 0x112c
	// Line 521, Address: 0x26a9a0, Func Offset: 0x1130
	// Line 529, Address: 0x26a9a4, Func Offset: 0x1134
	// Line 520, Address: 0x26a9ac, Func Offset: 0x113c
	// Line 521, Address: 0x26a9b0, Func Offset: 0x1140
	// Line 529, Address: 0x26a9b4, Func Offset: 0x1144
	// Line 521, Address: 0x26a9b8, Func Offset: 0x1148
	// Line 522, Address: 0x26a9c0, Func Offset: 0x1150
	// Line 523, Address: 0x26a9c8, Func Offset: 0x1158
	// Line 524, Address: 0x26a9d0, Func Offset: 0x1160
	// Line 525, Address: 0x26a9dc, Func Offset: 0x116c
	// Line 526, Address: 0x26a9ec, Func Offset: 0x117c
	// Line 527, Address: 0x26a9fc, Func Offset: 0x118c
	// Line 528, Address: 0x26aa08, Func Offset: 0x1198
	// Line 529, Address: 0x26aa0c, Func Offset: 0x119c
	// Line 532, Address: 0x26aa1c, Func Offset: 0x11ac
	// Line 530, Address: 0x26aa20, Func Offset: 0x11b0
	// Line 532, Address: 0x26aa24, Func Offset: 0x11b4
	// Line 538, Address: 0x26aa28, Func Offset: 0x11b8
	// Line 539, Address: 0x26aa2c, Func Offset: 0x11bc
	// Line 540, Address: 0x26aa30, Func Offset: 0x11c0
	// Line 546, Address: 0x26aa34, Func Offset: 0x11c4
	// Line 538, Address: 0x26aa38, Func Offset: 0x11c8
	// Line 539, Address: 0x26aa3c, Func Offset: 0x11cc
	// Line 547, Address: 0x26aa40, Func Offset: 0x11d0
	// Line 548, Address: 0x26aa44, Func Offset: 0x11d4
	// Line 549, Address: 0x26aa48, Func Offset: 0x11d8
	// Line 539, Address: 0x26aa4c, Func Offset: 0x11dc
	// Line 540, Address: 0x26aa50, Func Offset: 0x11e0
	// Line 541, Address: 0x26aa54, Func Offset: 0x11e4
	// Line 550, Address: 0x26aa58, Func Offset: 0x11e8
	// Line 540, Address: 0x26aa60, Func Offset: 0x11f0
	// Line 541, Address: 0x26aa64, Func Offset: 0x11f4
	// Line 550, Address: 0x26aa68, Func Offset: 0x11f8
	// Line 541, Address: 0x26aa70, Func Offset: 0x1200
	// Line 542, Address: 0x26aa74, Func Offset: 0x1204
	// Line 543, Address: 0x26aa80, Func Offset: 0x1210
	// Line 544, Address: 0x26aa94, Func Offset: 0x1224
	// Line 545, Address: 0x26aaa0, Func Offset: 0x1230
	// Line 546, Address: 0x26aab0, Func Offset: 0x1240
	// Line 547, Address: 0x26aac0, Func Offset: 0x1250
	// Line 548, Address: 0x26aac8, Func Offset: 0x1258
	// Line 549, Address: 0x26aad4, Func Offset: 0x1264
	// Line 550, Address: 0x26aad8, Func Offset: 0x1268
	// Line 553, Address: 0x26aae8, Func Offset: 0x1278
	// Line 551, Address: 0x26aaec, Func Offset: 0x127c
	// Line 553, Address: 0x26aaf0, Func Offset: 0x1280
	// Line 558, Address: 0x26aaf4, Func Offset: 0x1284
	// Line 559, Address: 0x26aaf8, Func Offset: 0x1288
	// Line 570, Address: 0x26aafc, Func Offset: 0x128c
	// Line 558, Address: 0x26ab04, Func Offset: 0x1294
	// Line 559, Address: 0x26ab08, Func Offset: 0x1298
	// Line 570, Address: 0x26ab0c, Func Offset: 0x129c
	// Line 559, Address: 0x26ab14, Func Offset: 0x12a4
	// Line 560, Address: 0x26ab18, Func Offset: 0x12a8
	// Line 561, Address: 0x26ab1c, Func Offset: 0x12ac
	// Line 560, Address: 0x26ab20, Func Offset: 0x12b0
	// Line 561, Address: 0x26ab24, Func Offset: 0x12b4
	// Line 562, Address: 0x26ab2c, Func Offset: 0x12bc
	// Line 563, Address: 0x26ab3c, Func Offset: 0x12cc
	// Line 564, Address: 0x26ab48, Func Offset: 0x12d8
	// Line 565, Address: 0x26ab5c, Func Offset: 0x12ec
	// Line 566, Address: 0x26ab6c, Func Offset: 0x12fc
	// Line 567, Address: 0x26ab74, Func Offset: 0x1304
	// Line 568, Address: 0x26ab84, Func Offset: 0x1314
	// Line 569, Address: 0x26ab8c, Func Offset: 0x131c
	// Line 570, Address: 0x26ab90, Func Offset: 0x1320
	// Line 573, Address: 0x26aba0, Func Offset: 0x1330
	// Line 571, Address: 0x26aba4, Func Offset: 0x1334
	// Line 573, Address: 0x26aba8, Func Offset: 0x1338
	// Line 578, Address: 0x26abac, Func Offset: 0x133c
	// Line 579, Address: 0x26abb4, Func Offset: 0x1344
	// Line 590, Address: 0x26abb8, Func Offset: 0x1348
	// Line 578, Address: 0x26abc0, Func Offset: 0x1350
	// Line 590, Address: 0x26abc4, Func Offset: 0x1354
	// Line 578, Address: 0x26abcc, Func Offset: 0x135c
	// Line 579, Address: 0x26abd0, Func Offset: 0x1360
	// Line 580, Address: 0x26abd8, Func Offset: 0x1368
	// Line 581, Address: 0x26abdc, Func Offset: 0x136c
	// Line 580, Address: 0x26abe0, Func Offset: 0x1370
	// Line 581, Address: 0x26abe4, Func Offset: 0x1374
	// Line 582, Address: 0x26abf4, Func Offset: 0x1384
	// Line 583, Address: 0x26ac04, Func Offset: 0x1394
	// Line 584, Address: 0x26ac10, Func Offset: 0x13a0
	// Line 585, Address: 0x26ac1c, Func Offset: 0x13ac
	// Line 586, Address: 0x26ac2c, Func Offset: 0x13bc
	// Line 587, Address: 0x26ac3c, Func Offset: 0x13cc
	// Line 588, Address: 0x26ac44, Func Offset: 0x13d4
	// Line 589, Address: 0x26ac4c, Func Offset: 0x13dc
	// Line 590, Address: 0x26ac58, Func Offset: 0x13e8
	// Line 592, Address: 0x26ac68, Func Offset: 0x13f8
	// Line 595, Address: 0x26ac70, Func Offset: 0x1400
	// Line 596, Address: 0x26ac9c, Func Offset: 0x142c
	// Line 597, Address: 0x26acc8, Func Offset: 0x1458
	// Line 598, Address: 0x26acf4, Func Offset: 0x1484
	// Line 600, Address: 0x26ad20, Func Offset: 0x14b0
	// Line 601, Address: 0x26ad24, Func Offset: 0x14b4
	// Line 604, Address: 0x26ad2c, Func Offset: 0x14bc
	// Line 607, Address: 0x26ad30, Func Offset: 0x14c0
	// Line 601, Address: 0x26ad34, Func Offset: 0x14c4
	// Line 602, Address: 0x26ad38, Func Offset: 0x14c8
	// Line 610, Address: 0x26ad3c, Func Offset: 0x14cc
	// Line 613, Address: 0x26ad40, Func Offset: 0x14d0
	// Line 602, Address: 0x26ad44, Func Offset: 0x14d4
	// Line 603, Address: 0x26ad48, Func Offset: 0x14d8
	// Line 604, Address: 0x26ad50, Func Offset: 0x14e0
	// Line 605, Address: 0x26ad58, Func Offset: 0x14e8
	// Line 606, Address: 0x26ad68, Func Offset: 0x14f8
	// Line 607, Address: 0x26ad78, Func Offset: 0x1508
	// Line 608, Address: 0x26ad80, Func Offset: 0x1510
	// Line 609, Address: 0x26ad90, Func Offset: 0x1520
	// Line 610, Address: 0x26ada0, Func Offset: 0x1530
	// Line 611, Address: 0x26ada8, Func Offset: 0x1538
	// Line 613, Address: 0x26adb0, Func Offset: 0x1540
	// Line 614, Address: 0x26ade4, Func Offset: 0x1574
	// Line 615, Address: 0x26adf8, Func Offset: 0x1588
	// Line 616, Address: 0x26ae0c, Func Offset: 0x159c
	// Line 617, Address: 0x26ae20, Func Offset: 0x15b0
	// Line 619, Address: 0x26ae30, Func Offset: 0x15c0
	// Line 624, Address: 0x26ae50, Func Offset: 0x15e0
	// Line 625, Address: 0x26ae54, Func Offset: 0x15e4
	// Func End, Address: 0x26ae8c, Func Offset: 0x161c
}

// 
// Start address: 0x26ae90
int bhCollisionCheckL2PL(_anon2* p1, _anon2* p2, _anon2* area, int num)
{
	float wlen;
	float len;
	int ret;
	_anon2 dv;
	_anon2 cp;
	_anon37 ln;
	_anon37 pl;
	// Line 638, Address: 0x26ae90, Func Offset: 0
	// Line 646, Address: 0x26aec0, Func Offset: 0x30
	// Line 647, Address: 0x26aec4, Func Offset: 0x34
	// Line 648, Address: 0x26aec8, Func Offset: 0x38
	// Line 649, Address: 0x26aecc, Func Offset: 0x3c
	// Line 646, Address: 0x26aed0, Func Offset: 0x40
	// Line 647, Address: 0x26aed4, Func Offset: 0x44
	// Line 643, Address: 0x26aee8, Func Offset: 0x58
	// Line 647, Address: 0x26aeec, Func Offset: 0x5c
	// Line 648, Address: 0x26aef0, Func Offset: 0x60
	// Line 649, Address: 0x26aef8, Func Offset: 0x68
	// Line 650, Address: 0x26af08, Func Offset: 0x78
	// Line 651, Address: 0x26af18, Func Offset: 0x88
	// Line 652, Address: 0x26af20, Func Offset: 0x90
	// Line 651, Address: 0x26af24, Func Offset: 0x94
	// Line 652, Address: 0x26af28, Func Offset: 0x98
	// Line 654, Address: 0x26af30, Func Offset: 0xa0
	// Line 652, Address: 0x26af34, Func Offset: 0xa4
	// Line 654, Address: 0x26af38, Func Offset: 0xa8
	// Line 655, Address: 0x26af44, Func Offset: 0xb4
	// Line 660, Address: 0x26af48, Func Offset: 0xb8
	// Line 655, Address: 0x26af50, Func Offset: 0xc0
	// Line 656, Address: 0x26af54, Func Offset: 0xc4
	// Line 657, Address: 0x26af5c, Func Offset: 0xcc
	// Line 660, Address: 0x26af60, Func Offset: 0xd0
	// Line 662, Address: 0x26af80, Func Offset: 0xf0
	// Line 664, Address: 0x26afa8, Func Offset: 0x118
	// Line 667, Address: 0x26afb0, Func Offset: 0x120
	// Line 665, Address: 0x26afb4, Func Offset: 0x124
	// Line 664, Address: 0x26afbc, Func Offset: 0x12c
	// Line 666, Address: 0x26afc0, Func Offset: 0x130
	// Line 667, Address: 0x26afc4, Func Offset: 0x134
	// Line 664, Address: 0x26afc8, Func Offset: 0x138
	// Line 665, Address: 0x26afcc, Func Offset: 0x13c
	// Line 666, Address: 0x26afdc, Func Offset: 0x14c
	// Line 667, Address: 0x26afe8, Func Offset: 0x158
	// Line 669, Address: 0x26b008, Func Offset: 0x178
	// Line 670, Address: 0x26b014, Func Offset: 0x184
	// Line 672, Address: 0x26b024, Func Offset: 0x194
	// Line 674, Address: 0x26b040, Func Offset: 0x1b0
	// Line 679, Address: 0x26b044, Func Offset: 0x1b4
	// Line 674, Address: 0x26b050, Func Offset: 0x1c0
	// Line 675, Address: 0x26b054, Func Offset: 0x1c4
	// Line 681, Address: 0x26b058, Func Offset: 0x1c8
	// Line 675, Address: 0x26b05c, Func Offset: 0x1cc
	// Line 676, Address: 0x26b060, Func Offset: 0x1d0
	// Line 679, Address: 0x26b068, Func Offset: 0x1d8
	// Line 688, Address: 0x26b078, Func Offset: 0x1e8
	// Line 689, Address: 0x26b07c, Func Offset: 0x1ec
	// Func End, Address: 0x26b0b0, Func Offset: 0x220
}

// 
// Start address: 0x26b0b0
int bhInOutCheck(_anon2* p, _anon2* area, _anon2* normal, int num)
{
	float v2z;
	float v2y;
	float v2x;
	float v1z;
	float v1y;
	float v1x;
	_anon2 n;
	_anon2* p2;
	_anon2* p1;
	int i;
	// Line 702, Address: 0x26b0b0, Func Offset: 0
	// Line 707, Address: 0x26b0c8, Func Offset: 0x18
	// Line 710, Address: 0x26b0e0, Func Offset: 0x30
	// Line 711, Address: 0x26b0e8, Func Offset: 0x38
	// Line 712, Address: 0x26b0f0, Func Offset: 0x40
	// Line 713, Address: 0x26b0f8, Func Offset: 0x48
	// Line 714, Address: 0x26b0fc, Func Offset: 0x4c
	// Line 715, Address: 0x26b104, Func Offset: 0x54
	// Line 719, Address: 0x26b110, Func Offset: 0x60
	// Line 718, Address: 0x26b114, Func Offset: 0x64
	// Line 719, Address: 0x26b118, Func Offset: 0x68
	// Line 733, Address: 0x26b130, Func Offset: 0x80
	// Line 721, Address: 0x26b134, Func Offset: 0x84
	// Line 720, Address: 0x26b138, Func Offset: 0x88
	// Line 721, Address: 0x26b13c, Func Offset: 0x8c
	// Line 724, Address: 0x26b148, Func Offset: 0x98
	// Line 727, Address: 0x26b150, Func Offset: 0xa0
	// Line 726, Address: 0x26b154, Func Offset: 0xa4
	// Line 725, Address: 0x26b15c, Func Offset: 0xac
	// Line 724, Address: 0x26b164, Func Offset: 0xb4
	// Line 728, Address: 0x26b168, Func Offset: 0xb8
	// Line 727, Address: 0x26b16c, Func Offset: 0xbc
	// Line 729, Address: 0x26b170, Func Offset: 0xc0
	// Line 726, Address: 0x26b174, Func Offset: 0xc4
	// Line 725, Address: 0x26b178, Func Offset: 0xc8
	// Line 729, Address: 0x26b17c, Func Offset: 0xcc
	// Line 728, Address: 0x26b180, Func Offset: 0xd0
	// Line 733, Address: 0x26b184, Func Offset: 0xd4
	// Line 735, Address: 0x26b1c0, Func Offset: 0x110
	// Line 737, Address: 0x26b1c8, Func Offset: 0x118
	// Line 739, Address: 0x26b1d8, Func Offset: 0x128
	// Line 740, Address: 0x26b1dc, Func Offset: 0x12c
	// Func End, Address: 0x26b1f4, Func Offset: 0x144
}

// 
// Start address: 0x26b200
int bhCollisionCheckL2MDL(_anon2* p1, _anon2* p2, _anon31* mdl, float mtx[16])
{
	_anon37 ln;
	_anon2 center;
	_anon2 area[4];
	_anon2* pd;
	short pnum;
	int j;
	int i;
	int ret;
	int* pVtx;
	short* pPol;
	// Line 849, Address: 0x26b200, Func Offset: 0
	// Line 857, Address: 0x26b234, Func Offset: 0x34
	// Line 858, Address: 0x26b248, Func Offset: 0x48
	// Line 864, Address: 0x26b24c, Func Offset: 0x4c
	// Line 858, Address: 0x26b258, Func Offset: 0x58
	// Line 859, Address: 0x26b25c, Func Offset: 0x5c
	// Line 860, Address: 0x26b264, Func Offset: 0x64
	// Line 861, Address: 0x26b26c, Func Offset: 0x6c
	// Line 862, Address: 0x26b27c, Func Offset: 0x7c
	// Line 863, Address: 0x26b28c, Func Offset: 0x8c
	// Line 864, Address: 0x26b298, Func Offset: 0x98
	// Line 866, Address: 0x26b2bc, Func Offset: 0xbc
	// Line 876, Address: 0x26b2c0, Func Offset: 0xc0
	// Line 867, Address: 0x26b2c8, Func Offset: 0xc8
	// Line 876, Address: 0x26b2cc, Func Offset: 0xcc
	// Line 877, Address: 0x26b2d0, Func Offset: 0xd0
	// Line 876, Address: 0x26b2d8, Func Offset: 0xd8
	// Line 872, Address: 0x26b2e4, Func Offset: 0xe4
	// Line 877, Address: 0x26b2e8, Func Offset: 0xe8
	// Line 876, Address: 0x26b2ec, Func Offset: 0xec
	// Line 872, Address: 0x26b2f0, Func Offset: 0xf0
	// Line 876, Address: 0x26b2f4, Func Offset: 0xf4
	// Line 873, Address: 0x26b2f8, Func Offset: 0xf8
	// Line 877, Address: 0x26b2fc, Func Offset: 0xfc
	// Line 880, Address: 0x26b310, Func Offset: 0x110
	// Line 882, Address: 0x26b318, Func Offset: 0x118
	// Line 883, Address: 0x26b320, Func Offset: 0x120
	// Line 885, Address: 0x26b360, Func Offset: 0x160
	// Line 886, Address: 0x26b37c, Func Offset: 0x17c
	// Line 911, Address: 0x26b380, Func Offset: 0x180
	// Line 913, Address: 0x26b394, Func Offset: 0x194
	// Line 914, Address: 0x26b398, Func Offset: 0x198
	// Func End, Address: 0x26b3c0, Func Offset: 0x1c0
}

// 
// Start address: 0x26b3c0
int bhCollisionCheckL2XZPL(_anon2* p1, _anon2* p2, _anon2* pos, float w, float d, int flg)
{
	int ret;
	_anon2 cp;
	_anon37 ln;
	_anon37 pl;
	// Line 931, Address: 0x26b3c0, Func Offset: 0
	// Line 937, Address: 0x26b3dc, Func Offset: 0x1c
	// Line 935, Address: 0x26b3f0, Func Offset: 0x30
	// Line 937, Address: 0x26b3f4, Func Offset: 0x34
	// Line 938, Address: 0x26b3f8, Func Offset: 0x38
	// Line 939, Address: 0x26b400, Func Offset: 0x40
	// Line 940, Address: 0x26b408, Func Offset: 0x48
	// Line 941, Address: 0x26b418, Func Offset: 0x58
	// Line 942, Address: 0x26b428, Func Offset: 0x68
	// Line 944, Address: 0x26b434, Func Offset: 0x74
	// Line 945, Address: 0x26b438, Func Offset: 0x78
	// Line 946, Address: 0x26b45c, Func Offset: 0x9c
	// Line 947, Address: 0x26b460, Func Offset: 0xa0
	// Line 952, Address: 0x26b464, Func Offset: 0xa4
	// Line 947, Address: 0x26b470, Func Offset: 0xb0
	// Line 948, Address: 0x26b474, Func Offset: 0xb4
	// Line 949, Address: 0x26b47c, Func Offset: 0xbc
	// Line 952, Address: 0x26b480, Func Offset: 0xc0
	// Line 954, Address: 0x26b4a0, Func Offset: 0xe0
	// Line 956, Address: 0x26b4fc, Func Offset: 0x13c
	// Line 957, Address: 0x26b500, Func Offset: 0x140
	// Line 961, Address: 0x26b504, Func Offset: 0x144
	// Line 957, Address: 0x26b510, Func Offset: 0x150
	// Line 958, Address: 0x26b514, Func Offset: 0x154
	// Line 963, Address: 0x26b518, Func Offset: 0x158
	// Line 958, Address: 0x26b51c, Func Offset: 0x15c
	// Line 961, Address: 0x26b520, Func Offset: 0x160
	// Line 967, Address: 0x26b530, Func Offset: 0x170
	// Line 968, Address: 0x26b534, Func Offset: 0x174
	// Func End, Address: 0x26b554, Func Offset: 0x194
}

// 
// Start address: 0x26b560
int bhCollisionCheckL2XYPL(_anon2* p1, _anon2* p2, _anon2* pos, float w, float h, int flg)
{
	int ret;
	_anon2 cp;
	_anon37 ln;
	_anon37 pl;
	// Line 983, Address: 0x26b560, Func Offset: 0
	// Line 989, Address: 0x26b57c, Func Offset: 0x1c
	// Line 987, Address: 0x26b590, Func Offset: 0x30
	// Line 989, Address: 0x26b594, Func Offset: 0x34
	// Line 990, Address: 0x26b598, Func Offset: 0x38
	// Line 991, Address: 0x26b5a0, Func Offset: 0x40
	// Line 992, Address: 0x26b5a8, Func Offset: 0x48
	// Line 993, Address: 0x26b5b8, Func Offset: 0x58
	// Line 994, Address: 0x26b5c8, Func Offset: 0x68
	// Line 996, Address: 0x26b5d4, Func Offset: 0x74
	// Line 997, Address: 0x26b5d8, Func Offset: 0x78
	// Line 998, Address: 0x26b5dc, Func Offset: 0x7c
	// Line 999, Address: 0x26b600, Func Offset: 0xa0
	// Line 1004, Address: 0x26b604, Func Offset: 0xa4
	// Line 999, Address: 0x26b610, Func Offset: 0xb0
	// Line 1000, Address: 0x26b614, Func Offset: 0xb4
	// Line 1001, Address: 0x26b61c, Func Offset: 0xbc
	// Line 1004, Address: 0x26b620, Func Offset: 0xc0
	// Line 1006, Address: 0x26b640, Func Offset: 0xe0
	// Line 1008, Address: 0x26b69c, Func Offset: 0x13c
	// Line 1009, Address: 0x26b6a0, Func Offset: 0x140
	// Line 1013, Address: 0x26b6a4, Func Offset: 0x144
	// Line 1015, Address: 0x26b6a8, Func Offset: 0x148
	// Line 1009, Address: 0x26b6ac, Func Offset: 0x14c
	// Line 1010, Address: 0x26b6b0, Func Offset: 0x150
	// Line 1013, Address: 0x26b6b4, Func Offset: 0x154
	// Line 1010, Address: 0x26b6bc, Func Offset: 0x15c
	// Line 1013, Address: 0x26b6c0, Func Offset: 0x160
	// Line 1019, Address: 0x26b6d0, Func Offset: 0x170
	// Line 1020, Address: 0x26b6d4, Func Offset: 0x174
	// Func End, Address: 0x26b6f4, Func Offset: 0x194
}

// 
// Start address: 0x26b700
int bhCollisionCheckL2YZPL(_anon2* p1, _anon2* p2, _anon2* pos, float h, float d, int flg)
{
	int ret;
	_anon2 cp;
	_anon37 ln;
	_anon37 pl;
	// Line 1035, Address: 0x26b700, Func Offset: 0
	// Line 1041, Address: 0x26b71c, Func Offset: 0x1c
	// Line 1039, Address: 0x26b730, Func Offset: 0x30
	// Line 1041, Address: 0x26b734, Func Offset: 0x34
	// Line 1042, Address: 0x26b738, Func Offset: 0x38
	// Line 1043, Address: 0x26b740, Func Offset: 0x40
	// Line 1044, Address: 0x26b748, Func Offset: 0x48
	// Line 1045, Address: 0x26b758, Func Offset: 0x58
	// Line 1046, Address: 0x26b768, Func Offset: 0x68
	// Line 1048, Address: 0x26b774, Func Offset: 0x74
	// Line 1049, Address: 0x26b798, Func Offset: 0x98
	// Line 1050, Address: 0x26b79c, Func Offset: 0x9c
	// Line 1051, Address: 0x26b7a0, Func Offset: 0xa0
	// Line 1056, Address: 0x26b7a4, Func Offset: 0xa4
	// Line 1051, Address: 0x26b7b0, Func Offset: 0xb0
	// Line 1052, Address: 0x26b7b4, Func Offset: 0xb4
	// Line 1053, Address: 0x26b7bc, Func Offset: 0xbc
	// Line 1056, Address: 0x26b7c0, Func Offset: 0xc0
	// Line 1058, Address: 0x26b7e0, Func Offset: 0xe0
	// Line 1060, Address: 0x26b840, Func Offset: 0x140
	// Line 1065, Address: 0x26b844, Func Offset: 0x144
	// Line 1060, Address: 0x26b850, Func Offset: 0x150
	// Line 1061, Address: 0x26b854, Func Offset: 0x154
	// Line 1067, Address: 0x26b858, Func Offset: 0x158
	// Line 1061, Address: 0x26b85c, Func Offset: 0x15c
	// Line 1062, Address: 0x26b860, Func Offset: 0x160
	// Line 1065, Address: 0x26b868, Func Offset: 0x168
	// Line 1071, Address: 0x26b878, Func Offset: 0x178
	// Line 1072, Address: 0x26b87c, Func Offset: 0x17c
	// Func End, Address: 0x26b89c, Func Offset: 0x19c
}

// 
// Start address: 0x26b8a0
void bhGetHitCollisionNormal(_anon2* n)
{
	// Line 1083, Address: 0x26b8a0, Func Offset: 0
	// Line 1084, Address: 0x26b8ac, Func Offset: 0xc
	// Line 1085, Address: 0x26b8b8, Func Offset: 0x18
	// Line 1086, Address: 0x26b8c0, Func Offset: 0x20
	// Func End, Address: 0x26b8c8, Func Offset: 0x28
}*/

