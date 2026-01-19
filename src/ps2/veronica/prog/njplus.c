#include "njplus.h"
#include "ps2_dummy.h"
#include "ps2_NaMatrix.h"
#include "main.h"

NP_WORK np;

// 100% matching!
void npPlusInit() 
{
    int i;
    int j;
    
    np.buff = njpmemp; 
    np.buff2 = njpmemp + 131072;
    
    np.bp = np.buff; 
    np.bp2 = np.buff2; 
    
    for (i = 0; i < 128; i++) 
    { 
        for (j = 0; j < 2; j++) 
        { 
            np.mxp[i][j] = (NJS_MATRIX*)np.bp; 
            
            np.bp += sizeof(NJS_MATRIX);  
        } 
    } 
} 

/*// 
// Start address: 0x12b710
int npCollisionCheckCC(_anon4* cpa, _anon4* cpb)
{
	float sca;
	float lenb;
	float lena;
	float inn;
	_anon1 vec;
	_anon6 sb;
	_anon6 sa;
	_anon4* capb;
	_anon4* capa;
	_anon21 lnc;
	_anon21 lnb;
	_anon21 lna;
	// Line 91, Address: 0x12b710, Func Offset: 0
	// Line 97, Address: 0x12b748, Func Offset: 0x38
	// Line 98, Address: 0x12b74c, Func Offset: 0x3c
	// Line 99, Address: 0x12b750, Func Offset: 0x40
	// Line 100, Address: 0x12b754, Func Offset: 0x44
	// Line 97, Address: 0x12b758, Func Offset: 0x48
	// Line 98, Address: 0x12b75c, Func Offset: 0x4c
	// Line 104, Address: 0x12b760, Func Offset: 0x50
	// Line 105, Address: 0x12b764, Func Offset: 0x54
	// Line 106, Address: 0x12b768, Func Offset: 0x58
	// Line 98, Address: 0x12b76c, Func Offset: 0x5c
	// Line 99, Address: 0x12b770, Func Offset: 0x60
	// Line 100, Address: 0x12b780, Func Offset: 0x70
	// Line 101, Address: 0x12b790, Func Offset: 0x80
	// Line 102, Address: 0x12b7a0, Func Offset: 0x90
	// Line 109, Address: 0x12b7a8, Func Offset: 0x98
	// Line 102, Address: 0x12b7ac, Func Offset: 0x9c
	// Line 103, Address: 0x12b7b4, Func Offset: 0xa4
	// Line 104, Address: 0x12b7bc, Func Offset: 0xac
	// Line 105, Address: 0x12b7c4, Func Offset: 0xb4
	// Line 106, Address: 0x12b7cc, Func Offset: 0xbc
	// Line 107, Address: 0x12b7dc, Func Offset: 0xcc
	// Line 108, Address: 0x12b7ec, Func Offset: 0xdc
	// Line 109, Address: 0x12b7f8, Func Offset: 0xe8
	// Line 110, Address: 0x12b804, Func Offset: 0xf4
	// Line 111, Address: 0x12b810, Func Offset: 0x100
	// Line 115, Address: 0x12b820, Func Offset: 0x110
	// Line 118, Address: 0x12b824, Func Offset: 0x114
	// Line 115, Address: 0x12b828, Func Offset: 0x118
	// Line 119, Address: 0x12b834, Func Offset: 0x124
	// Line 116, Address: 0x12b838, Func Offset: 0x128
	// Line 120, Address: 0x12b83c, Func Offset: 0x12c
	// Line 113, Address: 0x12b840, Func Offset: 0x130
	// Line 115, Address: 0x12b844, Func Offset: 0x134
	// Line 116, Address: 0x12b84c, Func Offset: 0x13c
	// Line 117, Address: 0x12b85c, Func Offset: 0x14c
	// Line 121, Address: 0x12b868, Func Offset: 0x158
	// Line 122, Address: 0x12b870, Func Offset: 0x160
	// Line 123, Address: 0x12b874, Func Offset: 0x164
	// Line 127, Address: 0x12b878, Func Offset: 0x168
	// Line 128, Address: 0x12b88c, Func Offset: 0x17c
	// Line 131, Address: 0x12b890, Func Offset: 0x180
	// Line 132, Address: 0x12b894, Func Offset: 0x184
	// Line 128, Address: 0x12b89c, Func Offset: 0x18c
	// Line 131, Address: 0x12b8a0, Func Offset: 0x190
	// Line 129, Address: 0x12b8a4, Func Offset: 0x194
	// Line 133, Address: 0x12b8a8, Func Offset: 0x198
	// Line 134, Address: 0x12b8ac, Func Offset: 0x19c
	// Line 131, Address: 0x12b8b0, Func Offset: 0x1a0
	// Line 129, Address: 0x12b8b4, Func Offset: 0x1a4
	// Line 131, Address: 0x12b8b8, Func Offset: 0x1a8
	// Line 132, Address: 0x12b8bc, Func Offset: 0x1ac
	// Line 133, Address: 0x12b8d0, Func Offset: 0x1c0
	// Line 134, Address: 0x12b8e0, Func Offset: 0x1d0
	// Line 135, Address: 0x12b8e8, Func Offset: 0x1d8
	// Line 136, Address: 0x12b8f4, Func Offset: 0x1e4
	// Line 137, Address: 0x12b8fc, Func Offset: 0x1ec
	// Line 138, Address: 0x12b908, Func Offset: 0x1f8
	// Line 139, Address: 0x12b920, Func Offset: 0x210
	// Line 140, Address: 0x12b930, Func Offset: 0x220
	// Line 141, Address: 0x12b938, Func Offset: 0x228
	// Line 142, Address: 0x12b940, Func Offset: 0x230
	// Line 144, Address: 0x12b944, Func Offset: 0x234
	// Line 145, Address: 0x12b94c, Func Offset: 0x23c
	// Line 146, Address: 0x12b954, Func Offset: 0x244
	// Line 147, Address: 0x12b95c, Func Offset: 0x24c
	// Line 150, Address: 0x12b964, Func Offset: 0x254
	// Line 151, Address: 0x12b96c, Func Offset: 0x25c
	// Line 152, Address: 0x12b974, Func Offset: 0x264
	// Line 150, Address: 0x12b978, Func Offset: 0x268
	// Line 153, Address: 0x12b97c, Func Offset: 0x26c
	// Line 150, Address: 0x12b980, Func Offset: 0x270
	// Line 151, Address: 0x12b984, Func Offset: 0x274
	// Line 152, Address: 0x12b994, Func Offset: 0x284
	// Line 153, Address: 0x12b9a4, Func Offset: 0x294
	// Line 154, Address: 0x12b9ac, Func Offset: 0x29c
	// Line 155, Address: 0x12b9b8, Func Offset: 0x2a8
	// Line 156, Address: 0x12b9c0, Func Offset: 0x2b0
	// Line 157, Address: 0x12b9cc, Func Offset: 0x2bc
	// Line 158, Address: 0x12b9e4, Func Offset: 0x2d4
	// Line 159, Address: 0x12b9f4, Func Offset: 0x2e4
	// Line 160, Address: 0x12b9fc, Func Offset: 0x2ec
	// Line 161, Address: 0x12ba04, Func Offset: 0x2f4
	// Line 163, Address: 0x12ba08, Func Offset: 0x2f8
	// Line 164, Address: 0x12ba10, Func Offset: 0x300
	// Line 165, Address: 0x12ba18, Func Offset: 0x308
	// Line 166, Address: 0x12ba20, Func Offset: 0x310
	// Line 177, Address: 0x12ba28, Func Offset: 0x318
	// Line 180, Address: 0x12ba44, Func Offset: 0x334
	// Line 183, Address: 0x12ba48, Func Offset: 0x338
	// Line 180, Address: 0x12ba54, Func Offset: 0x344
	// Line 181, Address: 0x12ba58, Func Offset: 0x348
	// Line 182, Address: 0x12ba60, Func Offset: 0x350
	// Line 183, Address: 0x12ba64, Func Offset: 0x354
	// Line 185, Address: 0x12ba6c, Func Offset: 0x35c
	// Line 186, Address: 0x12ba74, Func Offset: 0x364
	// Line 188, Address: 0x12ba78, Func Offset: 0x368
	// Line 185, Address: 0x12ba7c, Func Offset: 0x36c
	// Line 186, Address: 0x12ba84, Func Offset: 0x374
	// Line 187, Address: 0x12ba94, Func Offset: 0x384
	// Line 188, Address: 0x12baa4, Func Offset: 0x394
	// Line 189, Address: 0x12baac, Func Offset: 0x39c
	// Line 190, Address: 0x12bab8, Func Offset: 0x3a8
	// Line 191, Address: 0x12bac4, Func Offset: 0x3b4
	// Line 192, Address: 0x12badc, Func Offset: 0x3cc
	// Line 193, Address: 0x12baec, Func Offset: 0x3dc
	// Line 194, Address: 0x12baf4, Func Offset: 0x3e4
	// Line 195, Address: 0x12bafc, Func Offset: 0x3ec
	// Line 197, Address: 0x12bb00, Func Offset: 0x3f0
	// Line 198, Address: 0x12bb08, Func Offset: 0x3f8
	// Line 199, Address: 0x12bb10, Func Offset: 0x400
	// Line 200, Address: 0x12bb18, Func Offset: 0x408
	// Line 210, Address: 0x12bb20, Func Offset: 0x410
	// Line 213, Address: 0x12bb3c, Func Offset: 0x42c
	// Line 216, Address: 0x12bb40, Func Offset: 0x430
	// Line 213, Address: 0x12bb4c, Func Offset: 0x43c
	// Line 214, Address: 0x12bb50, Func Offset: 0x440
	// Line 215, Address: 0x12bb58, Func Offset: 0x448
	// Line 216, Address: 0x12bb5c, Func Offset: 0x44c
	// Line 218, Address: 0x12bb64, Func Offset: 0x454
	// Line 219, Address: 0x12bb6c, Func Offset: 0x45c
	// Line 221, Address: 0x12bb70, Func Offset: 0x460
	// Line 218, Address: 0x12bb74, Func Offset: 0x464
	// Line 219, Address: 0x12bb7c, Func Offset: 0x46c
	// Line 220, Address: 0x12bb8c, Func Offset: 0x47c
	// Line 221, Address: 0x12bb9c, Func Offset: 0x48c
	// Line 222, Address: 0x12bba4, Func Offset: 0x494
	// Line 223, Address: 0x12bbb0, Func Offset: 0x4a0
	// Line 224, Address: 0x12bbbc, Func Offset: 0x4ac
	// Line 225, Address: 0x12bbd4, Func Offset: 0x4c4
	// Line 226, Address: 0x12bbe4, Func Offset: 0x4d4
	// Line 227, Address: 0x12bbec, Func Offset: 0x4dc
	// Line 228, Address: 0x12bbf4, Func Offset: 0x4e4
	// Line 230, Address: 0x12bbf8, Func Offset: 0x4e8
	// Line 231, Address: 0x12bc00, Func Offset: 0x4f0
	// Line 232, Address: 0x12bc08, Func Offset: 0x4f8
	// Line 233, Address: 0x12bc10, Func Offset: 0x500
	// Line 243, Address: 0x12bc18, Func Offset: 0x508
	// Line 246, Address: 0x12bc30, Func Offset: 0x520
	// Func End, Address: 0x12bc6c, Func Offset: 0x55c
}

// 
// Start address: 0x12bc70
int npCollisionCheckCCEx(_anon4* cpa, _anon4* cpb, _anon1* pos)
{
	_anon1 scl;
	_anon1 scl;
	_anon1 scl;
	float sca;
	float lenb;
	float lena;
	float inn;
	_anon1 vec;
	_anon6 sb;
	_anon6 sa;
	_anon4* capb;
	_anon4* capa;
	_anon21 lnc;
	_anon21 lnb;
	_anon21 lna;
	// Line 256, Address: 0x12bc70, Func Offset: 0
	// Line 262, Address: 0x12bca8, Func Offset: 0x38
	// Line 263, Address: 0x12bcac, Func Offset: 0x3c
	// Line 264, Address: 0x12bcb0, Func Offset: 0x40
	// Line 265, Address: 0x12bcb4, Func Offset: 0x44
	// Line 262, Address: 0x12bcb8, Func Offset: 0x48
	// Line 263, Address: 0x12bcbc, Func Offset: 0x4c
	// Line 271, Address: 0x12bcc0, Func Offset: 0x50
	// Line 263, Address: 0x12bcd0, Func Offset: 0x60
	// Line 264, Address: 0x12bcd4, Func Offset: 0x64
	// Line 265, Address: 0x12bcdc, Func Offset: 0x6c
	// Line 266, Address: 0x12bcec, Func Offset: 0x7c
	// Line 269, Address: 0x12bcf4, Func Offset: 0x84
	// Line 266, Address: 0x12bcf8, Func Offset: 0x88
	// Line 267, Address: 0x12bd00, Func Offset: 0x90
	// Line 274, Address: 0x12bd08, Func Offset: 0x98
	// Line 267, Address: 0x12bd0c, Func Offset: 0x9c
	// Line 268, Address: 0x12bd14, Func Offset: 0xa4
	// Line 269, Address: 0x12bd1c, Func Offset: 0xac
	// Line 270, Address: 0x12bd24, Func Offset: 0xb4
	// Line 271, Address: 0x12bd30, Func Offset: 0xc0
	// Line 272, Address: 0x12bd38, Func Offset: 0xc8
	// Line 271, Address: 0x12bd3c, Func Offset: 0xcc
	// Line 272, Address: 0x12bd44, Func Offset: 0xd4
	// Line 273, Address: 0x12bd4c, Func Offset: 0xdc
	// Line 272, Address: 0x12bd50, Func Offset: 0xe0
	// Line 273, Address: 0x12bd58, Func Offset: 0xe8
	// Line 274, Address: 0x12bd64, Func Offset: 0xf4
	// Line 275, Address: 0x12bd70, Func Offset: 0x100
	// Line 276, Address: 0x12bd7c, Func Offset: 0x10c
	// Line 280, Address: 0x12bd8c, Func Offset: 0x11c
	// Line 283, Address: 0x12bd90, Func Offset: 0x120
	// Line 280, Address: 0x12bd94, Func Offset: 0x124
	// Line 284, Address: 0x12bda0, Func Offset: 0x130
	// Line 281, Address: 0x12bda4, Func Offset: 0x134
	// Line 285, Address: 0x12bda8, Func Offset: 0x138
	// Line 278, Address: 0x12bdac, Func Offset: 0x13c
	// Line 280, Address: 0x12bdb0, Func Offset: 0x140
	// Line 281, Address: 0x12bdb8, Func Offset: 0x148
	// Line 282, Address: 0x12bdc8, Func Offset: 0x158
	// Line 286, Address: 0x12bdd4, Func Offset: 0x164
	// Line 287, Address: 0x12bddc, Func Offset: 0x16c
	// Line 288, Address: 0x12bde0, Func Offset: 0x170
	// Line 292, Address: 0x12bde4, Func Offset: 0x174
	// Line 293, Address: 0x12bdf8, Func Offset: 0x188
	// Line 297, Address: 0x12be00, Func Offset: 0x190
	// Line 293, Address: 0x12be08, Func Offset: 0x198
	// Line 296, Address: 0x12be0c, Func Offset: 0x19c
	// Line 294, Address: 0x12be14, Func Offset: 0x1a4
	// Line 298, Address: 0x12be18, Func Offset: 0x1a8
	// Line 299, Address: 0x12be1c, Func Offset: 0x1ac
	// Line 296, Address: 0x12be20, Func Offset: 0x1b0
	// Line 294, Address: 0x12be24, Func Offset: 0x1b4
	// Line 296, Address: 0x12be28, Func Offset: 0x1b8
	// Line 297, Address: 0x12be2c, Func Offset: 0x1bc
	// Line 298, Address: 0x12be40, Func Offset: 0x1d0
	// Line 299, Address: 0x12be50, Func Offset: 0x1e0
	// Line 300, Address: 0x12be58, Func Offset: 0x1e8
	// Line 301, Address: 0x12be64, Func Offset: 0x1f4
	// Line 302, Address: 0x12be6c, Func Offset: 0x1fc
	// Line 303, Address: 0x12be78, Func Offset: 0x208
	// Line 304, Address: 0x12be90, Func Offset: 0x220
	// Line 305, Address: 0x12bea0, Func Offset: 0x230
	// Line 306, Address: 0x12bea8, Func Offset: 0x238
	// Line 307, Address: 0x12beb0, Func Offset: 0x240
	// Line 309, Address: 0x12beb4, Func Offset: 0x244
	// Line 310, Address: 0x12bebc, Func Offset: 0x24c
	// Line 311, Address: 0x12bec4, Func Offset: 0x254
	// Line 312, Address: 0x12becc, Func Offset: 0x25c
	// Line 315, Address: 0x12bed4, Func Offset: 0x264
	// Line 316, Address: 0x12bedc, Func Offset: 0x26c
	// Line 317, Address: 0x12bee4, Func Offset: 0x274
	// Line 315, Address: 0x12bee8, Func Offset: 0x278
	// Line 318, Address: 0x12beec, Func Offset: 0x27c
	// Line 315, Address: 0x12bef0, Func Offset: 0x280
	// Line 316, Address: 0x12bef4, Func Offset: 0x284
	// Line 317, Address: 0x12bf08, Func Offset: 0x298
	// Line 318, Address: 0x12bf1c, Func Offset: 0x2ac
	// Line 319, Address: 0x12bf24, Func Offset: 0x2b4
	// Line 320, Address: 0x12bf30, Func Offset: 0x2c0
	// Line 321, Address: 0x12bf38, Func Offset: 0x2c8
	// Line 322, Address: 0x12bf44, Func Offset: 0x2d4
	// Line 323, Address: 0x12bf5c, Func Offset: 0x2ec
	// Line 324, Address: 0x12bf6c, Func Offset: 0x2fc
	// Line 325, Address: 0x12bf74, Func Offset: 0x304
	// Line 326, Address: 0x12bf7c, Func Offset: 0x30c
	// Line 328, Address: 0x12bf80, Func Offset: 0x310
	// Line 329, Address: 0x12bf88, Func Offset: 0x318
	// Line 330, Address: 0x12bf90, Func Offset: 0x320
	// Line 331, Address: 0x12bf98, Func Offset: 0x328
	// Line 353, Address: 0x12bfa0, Func Offset: 0x330
	// Line 355, Address: 0x12bfb4, Func Offset: 0x344
	// Line 356, Address: 0x12bfbc, Func Offset: 0x34c
	// Line 357, Address: 0x12bfc0, Func Offset: 0x350
	// Line 358, Address: 0x12bfc4, Func Offset: 0x354
	// Line 355, Address: 0x12bfc8, Func Offset: 0x358
	// Line 356, Address: 0x12bfd0, Func Offset: 0x360
	// Line 357, Address: 0x12bfe0, Func Offset: 0x370
	// Line 358, Address: 0x12bfec, Func Offset: 0x37c
	// Line 359, Address: 0x12c008, Func Offset: 0x398
	// Line 360, Address: 0x12c010, Func Offset: 0x3a0
	// Line 361, Address: 0x12c028, Func Offset: 0x3b8
	// Line 362, Address: 0x12c040, Func Offset: 0x3d0
	// Line 363, Address: 0x12c054, Func Offset: 0x3e4
	// Line 364, Address: 0x12c05c, Func Offset: 0x3ec
	// Line 365, Address: 0x12c064, Func Offset: 0x3f4
	// Line 366, Address: 0x12c06c, Func Offset: 0x3fc
	// Line 368, Address: 0x12c074, Func Offset: 0x404
	// Line 372, Address: 0x12c07c, Func Offset: 0x40c
	// Line 375, Address: 0x12c080, Func Offset: 0x410
	// Line 372, Address: 0x12c08c, Func Offset: 0x41c
	// Line 373, Address: 0x12c090, Func Offset: 0x420
	// Line 374, Address: 0x12c098, Func Offset: 0x428
	// Line 375, Address: 0x12c09c, Func Offset: 0x42c
	// Line 377, Address: 0x12c0a4, Func Offset: 0x434
	// Line 378, Address: 0x12c0ac, Func Offset: 0x43c
	// Line 380, Address: 0x12c0b0, Func Offset: 0x440
	// Line 377, Address: 0x12c0b4, Func Offset: 0x444
	// Line 378, Address: 0x12c0bc, Func Offset: 0x44c
	// Line 379, Address: 0x12c0d0, Func Offset: 0x460
	// Line 380, Address: 0x12c0e4, Func Offset: 0x474
	// Line 381, Address: 0x12c0ec, Func Offset: 0x47c
	// Line 382, Address: 0x12c0f8, Func Offset: 0x488
	// Line 383, Address: 0x12c104, Func Offset: 0x494
	// Line 384, Address: 0x12c11c, Func Offset: 0x4ac
	// Line 385, Address: 0x12c12c, Func Offset: 0x4bc
	// Line 386, Address: 0x12c134, Func Offset: 0x4c4
	// Line 387, Address: 0x12c13c, Func Offset: 0x4cc
	// Line 389, Address: 0x12c140, Func Offset: 0x4d0
	// Line 390, Address: 0x12c148, Func Offset: 0x4d8
	// Line 391, Address: 0x12c150, Func Offset: 0x4e0
	// Line 392, Address: 0x12c158, Func Offset: 0x4e8
	// Line 408, Address: 0x12c160, Func Offset: 0x4f0
	// Line 410, Address: 0x12c174, Func Offset: 0x504
	// Line 411, Address: 0x12c17c, Func Offset: 0x50c
	// Line 412, Address: 0x12c180, Func Offset: 0x510
	// Line 413, Address: 0x12c184, Func Offset: 0x514
	// Line 410, Address: 0x12c188, Func Offset: 0x518
	// Line 411, Address: 0x12c190, Func Offset: 0x520
	// Line 412, Address: 0x12c1a0, Func Offset: 0x530
	// Line 413, Address: 0x12c1ac, Func Offset: 0x53c
	// Line 414, Address: 0x12c1c8, Func Offset: 0x558
	// Line 415, Address: 0x12c1d0, Func Offset: 0x560
	// Line 416, Address: 0x12c1e8, Func Offset: 0x578
	// Line 417, Address: 0x12c200, Func Offset: 0x590
	// Line 418, Address: 0x12c214, Func Offset: 0x5a4
	// Line 419, Address: 0x12c21c, Func Offset: 0x5ac
	// Line 420, Address: 0x12c224, Func Offset: 0x5b4
	// Line 421, Address: 0x12c22c, Func Offset: 0x5bc
	// Line 423, Address: 0x12c234, Func Offset: 0x5c4
	// Line 427, Address: 0x12c23c, Func Offset: 0x5cc
	// Line 430, Address: 0x12c240, Func Offset: 0x5d0
	// Line 427, Address: 0x12c24c, Func Offset: 0x5dc
	// Line 428, Address: 0x12c250, Func Offset: 0x5e0
	// Line 429, Address: 0x12c258, Func Offset: 0x5e8
	// Line 430, Address: 0x12c25c, Func Offset: 0x5ec
	// Line 432, Address: 0x12c264, Func Offset: 0x5f4
	// Line 433, Address: 0x12c26c, Func Offset: 0x5fc
	// Line 435, Address: 0x12c270, Func Offset: 0x600
	// Line 432, Address: 0x12c274, Func Offset: 0x604
	// Line 433, Address: 0x12c27c, Func Offset: 0x60c
	// Line 434, Address: 0x12c290, Func Offset: 0x620
	// Line 435, Address: 0x12c2a4, Func Offset: 0x634
	// Line 436, Address: 0x12c2ac, Func Offset: 0x63c
	// Line 437, Address: 0x12c2b8, Func Offset: 0x648
	// Line 438, Address: 0x12c2c4, Func Offset: 0x654
	// Line 439, Address: 0x12c2dc, Func Offset: 0x66c
	// Line 440, Address: 0x12c2ec, Func Offset: 0x67c
	// Line 441, Address: 0x12c2f4, Func Offset: 0x684
	// Line 442, Address: 0x12c2fc, Func Offset: 0x68c
	// Line 444, Address: 0x12c300, Func Offset: 0x690
	// Line 445, Address: 0x12c308, Func Offset: 0x698
	// Line 446, Address: 0x12c310, Func Offset: 0x6a0
	// Line 447, Address: 0x12c318, Func Offset: 0x6a8
	// Line 463, Address: 0x12c320, Func Offset: 0x6b0
	// Line 465, Address: 0x12c334, Func Offset: 0x6c4
	// Line 466, Address: 0x12c33c, Func Offset: 0x6cc
	// Line 467, Address: 0x12c340, Func Offset: 0x6d0
	// Line 468, Address: 0x12c344, Func Offset: 0x6d4
	// Line 465, Address: 0x12c348, Func Offset: 0x6d8
	// Line 466, Address: 0x12c350, Func Offset: 0x6e0
	// Line 467, Address: 0x12c360, Func Offset: 0x6f0
	// Line 468, Address: 0x12c36c, Func Offset: 0x6fc
	// Line 469, Address: 0x12c388, Func Offset: 0x718
	// Line 470, Address: 0x12c390, Func Offset: 0x720
	// Line 471, Address: 0x12c3a8, Func Offset: 0x738
	// Line 472, Address: 0x12c3c0, Func Offset: 0x750
	// Line 473, Address: 0x12c3d4, Func Offset: 0x764
	// Line 474, Address: 0x12c3dc, Func Offset: 0x76c
	// Line 475, Address: 0x12c3e4, Func Offset: 0x774
	// Line 476, Address: 0x12c3ec, Func Offset: 0x77c
	// Line 478, Address: 0x12c3f4, Func Offset: 0x784
	// Line 481, Address: 0x12c3fc, Func Offset: 0x78c
	// Line 482, Address: 0x12c400, Func Offset: 0x790
	// Func End, Address: 0x12c43c, Func Offset: 0x7cc
}

// 
// Start address: 0x12c440
int npCollisionCheckSC(_anon6* sa, _anon4* cpb)
{
	float sca;
	float lenb;
	float lr;
	float inn;
	_anon1 vec;
	_anon6 sb;
	_anon21 lnb;
	// Line 493, Address: 0x12c440, Func Offset: 0
	// Line 498, Address: 0x12c470, Func Offset: 0x30
	// Line 499, Address: 0x12c478, Func Offset: 0x38
	// Line 500, Address: 0x12c47c, Func Offset: 0x3c
	// Line 501, Address: 0x12c480, Func Offset: 0x40
	// Line 498, Address: 0x12c484, Func Offset: 0x44
	// Line 499, Address: 0x12c488, Func Offset: 0x48
	// Line 500, Address: 0x12c48c, Func Offset: 0x4c
	// Line 502, Address: 0x12c490, Func Offset: 0x50
	// Line 505, Address: 0x12c498, Func Offset: 0x58
	// Line 500, Address: 0x12c49c, Func Offset: 0x5c
	// Line 501, Address: 0x12c4a0, Func Offset: 0x60
	// Line 502, Address: 0x12c4ac, Func Offset: 0x6c
	// Line 503, Address: 0x12c4bc, Func Offset: 0x7c
	// Line 504, Address: 0x12c4cc, Func Offset: 0x8c
	// Line 505, Address: 0x12c4d4, Func Offset: 0x94
	// Line 504, Address: 0x12c4d8, Func Offset: 0x98
	// Line 505, Address: 0x12c4dc, Func Offset: 0x9c
	// Line 506, Address: 0x12c4e4, Func Offset: 0xa4
	// Line 507, Address: 0x12c4e8, Func Offset: 0xa8
	// Line 509, Address: 0x12c4f8, Func Offset: 0xb8
	// Line 510, Address: 0x12c500, Func Offset: 0xc0
	// Line 511, Address: 0x12c504, Func Offset: 0xc4
	// Line 512, Address: 0x12c508, Func Offset: 0xc8
	// Line 509, Address: 0x12c50c, Func Offset: 0xcc
	// Line 510, Address: 0x12c514, Func Offset: 0xd4
	// Line 511, Address: 0x12c524, Func Offset: 0xe4
	// Line 512, Address: 0x12c530, Func Offset: 0xf0
	// Line 513, Address: 0x12c538, Func Offset: 0xf8
	// Line 514, Address: 0x12c544, Func Offset: 0x104
	// Line 515, Address: 0x12c54c, Func Offset: 0x10c
	// Line 516, Address: 0x12c558, Func Offset: 0x118
	// Line 517, Address: 0x12c570, Func Offset: 0x130
	// Line 518, Address: 0x12c58c, Func Offset: 0x14c
	// Line 519, Address: 0x12c59c, Func Offset: 0x15c
	// Line 520, Address: 0x12c5a4, Func Offset: 0x164
	// Line 521, Address: 0x12c5ac, Func Offset: 0x16c
	// Line 523, Address: 0x12c5b0, Func Offset: 0x170
	// Line 524, Address: 0x12c5b8, Func Offset: 0x178
	// Line 525, Address: 0x12c5d0, Func Offset: 0x190
	// Line 526, Address: 0x12c5d8, Func Offset: 0x198
	// Line 527, Address: 0x12c5e0, Func Offset: 0x1a0
	// Line 538, Address: 0x12c5e8, Func Offset: 0x1a8
	// Line 540, Address: 0x12c600, Func Offset: 0x1c0
	// Func End, Address: 0x12c634, Func Offset: 0x1f4
}*/

// 100% matching!
void npDistanceP2C(NJS_POINT3* pos, NJS_CAPSULE* cap, NJS_POINT3* htp) 
{
	NJS_LINE ln;   
    NJS_VECTOR vec;
    float inn;    
    float len;      
    float sca;     

    ln.px = cap->c1.x;
    ln.py = cap->c1.y;
    ln.pz = cap->c1.z;

    ln.vx = cap->c2.x - ln.px;
    ln.vy = cap->c2.y - ln.py;
    ln.vz = cap->c2.z - ln.pz;
    
    njDistanceP2L(pos, &ln, htp);
    
    len = njScalor((NJS_VECTOR*)&ln.vx);
    
    vec.x = htp->x - ln.px;
    vec.y = htp->y - ln.py;
    vec.z = htp->z - ln.pz; 
    
    sca = njScalor(&vec);
    
    njUnitVector(&vec);
    njUnitVector((NJS_VECTOR*)&ln.vx);

    inn = njInnerProduct(&vec, (NJS_VECTOR*)&ln.vx); 
    
    if (inn > 0) 
    {
        if (sca > len) 
        {
            htp->x = cap->c2.x;
            htp->y = cap->c2.y;
            htp->z = cap->c2.z;
        }
    } 
    else 
    {
        htp->x = cap->c1.x;
        htp->y = cap->c1.y;
        htp->z = cap->c1.z;
    }
    
    vec.x = pos->x - htp->x;
    vec.y = pos->y - htp->y;
    vec.z = pos->z - htp->z;
    
    if (cap->r < njScalor(&vec))
    {
        njUnitVector(&vec);
        
        htp->x += vec.x * cap->r;
        htp->y += vec.y * cap->r;
        htp->z += vec.z * cap->r;
    } 
    else 
    {
        htp->x = pos->x;
        htp->y = pos->y;
        htp->z = pos->z;
    }
}

// 100% matching!
void npDrawPlane(NJS_POINT3* ps0, NJS_POINT3* ps1, NJS_POINT3* ps2, NJS_POINT3* ps3, unsigned int argb)
{
    NJS_POINT3COL p3c;
    NJS_POINT3 p3[4];
    NJS_COLOR col[4];

    if (argb == 0) 
    {
        argb = 0x80808080; 
    }
    
    p3c.p = p3;
    
    p3c.col = col;
    
    p3c.tex = NULL;
    
    p3c.num = 1;
    
    ((int*)&p3c.col->color)[0] = argb;
    ((int*)&p3c.col->color)[1] = argb;
    ((int*)&p3c.col->color)[2] = argb; 
    ((int*)&p3c.col->color)[3] = argb;
    
    p3[0].x = ps0->x;
    p3[0].y = ps0->y;
    p3[0].z = ps0->z;
    
    p3[1].x = ps1->x;
    p3[1].y = ps1->y;
    p3[1].z = ps1->z;
    
    p3[2].x = ps2->x;
    p3[2].y = ps2->y;
    p3[2].z = ps2->z;
    
    p3[3].x = ps3->x;
    p3[3].y = ps3->y;
    p3[3].z = ps3->z;
    
    njDrawPolygon3D(&p3c, 4, 96);
}

// 99.57% matching
void npCalcMorphing(NJS_CNK_OBJECT* obj_a, NJS_CNK_OBJECT* obj_b, float no, int obj_n)
{
    int i;
    int nb; 
    unsigned int ulSize; 
    
    njPushMatrix(NULL);
    
    np.mxp[128][2] = np.mxp[128][1];
    
    for (i = 0; i < obj_n; i++) 
    {
        if ((obj_a[i].model != NULL) && (!(obj_a[i].evalflags & 0x8))) 
        {
            obj_a[i].pos[0] = (no * (0.001f * (obj_b[i].pos[0] - obj_a[i].pos[0]))) + obj_a[i].pos[0];
            obj_a[i].pos[1] = (no * (0.001f * (obj_b[i].pos[1] - obj_a[i].pos[1]))) + obj_a[i].pos[1];
            obj_a[i].pos[2] = (no * (0.001f * (obj_b[i].pos[2] - obj_a[i].pos[2]))) + obj_a[i].pos[2];

            nb = ((unsigned short*)obj_a[i].model->vlist)[3];

            np.vlp2[i] = (int*)np.mxp[128][2]; 
            
            ulSize = (nb * 32) + 76;
            
            ulSize += 64 - (ulSize & 0x3F);
            
            np.mxp[128][2] = (NJS_MATRIX*)((int)np.mxp[128][2] + ulSize);
            
            npTransform(&obj_a[i], &obj_b[i], no, i);
        }
    } 
    
    njPopMatrix(1);
}

// 99.95% matching
void npTransform(NJS_CNK_OBJECT* srcobj, NJS_CNK_OBJECT* dstobj, register float no, int ono)
{
    int s_nb;
    register NJS_POINT4* dp; 
    register NJS_POINT4* fp; 
    register NJS_POINT4* sp; 
    HDR_PS* pSrc;
    HDR_PS* pDst; 

    pSrc = (HDR_PS*)srcobj->model->vlist; 
    fp = (NJS_POINT4*)dstobj->model->vlist; 

    s_nb = pSrc->usIndexMax; 

    if (s_nb != ((HDR_PS*)fp)->usIndexMax)
    {
        return; 
    }

    sp = (NJS_POINT4*)(pSrc + 1); 
    dp = (NJS_POINT4*)((HDR_PS*)fp + 1); 
    fp = (NJS_POINT4*)np.vlp2[ono]; 

    fp = (NJS_POINT4*)((int)fp | 0x30000000); 

    ((HDR_PS*)fp)->ucType = pSrc->ucType; 
    ((HDR_PS*)fp)->ucAttr = pSrc->ucAttr; 
    
    ((HDR_PS*)fp)->usSize = pSrc->usSize; 
    
    ((HDR_PS*)fp)->usIndexOfs = pSrc->usIndexOfs; 
    ((HDR_PS*)fp)->usIndexMax = s_nb; 

    no *= 0.001f; 
    
    fp = (NJS_POINT4*)((HDR_PS*)fp + 1);
    
    for ( ; s_nb != 0; s_nb--) 
    { 
        if ((sp->x != dp->x) || (sp->y != dp->y) || (sp->z != dp->z)) 
        { 
            asm volatile 
            {
            .set noreorder
                
                mfc1      t0, no 
                
                lqc2      vf4, 0x0(sp)
                lqc2      vf5, 0x0(dp) 
                lqc2      vf6, 0x10(sp) 
                lqc2      vf7, 0x10(dp) 
                
                qmtc2     t0, vf12 
                
                vsub.xyz  vf5xyz, vf5xyz, vf4xyz 
                vsub.xyz  vf7xyz, vf7xyz, vf6xyz 
                
                vmulx.xyz vf5xyz, vf5xyz, vf12x 
                vmulx.xyz vf7xyz, vf7xyz, vf12x 
                
                vadd.xyz  vf5xyz, vf5xyz, vf4xyz 
                vadd.xyz  vf7xyz, vf7xyz, vf6xyz 
                
                sqc2      vf5, 0x0(fp) 
                sqc2      vf7, 0x10(fp) 

            .set reorder
            }
                
            fp += 2; 
            sp += 2; 
            dp += 2;
        } 
        else 
        { 
            asm volatile
            {
                .set noreorder
                
                lqc2 vf4, 0x0(sp) 
                lqc2 vf6, 0x10(sp)
                    
                sqc2 vf4, 0x0(fp)
                sqc2 vf6, 0x10(fp)

                .set reorder
            }
            
            fp += 2; 
            sp += 2;
            dp += 2;
        } 
    } 

    ((HDR_PS*)fp)->ucType = 0xFF; 

    srcobj->model->vlist = np.vlp2[ono]; 
} 

// 100% matching!
void npPushMdlstr(NJS_CNK_OBJECT* objp, int obj_n)
{
    int i; 
    
    for (i = 0; i < obj_n; i++, objp++) 
    {
        if (objp->model != NULL) 
        {
            np.vlist[i] = objp->model->vlist;
        } 
    } 
}

// 100% matching!
void npPopMdlstr(NJS_CNK_OBJECT* objp, int obj_n)
{
    int i; 
    
    for (i = 0; i < obj_n; i++, objp++) 
    {
        if (objp->model != NULL) 
        {
            objp->model->vlist = np.vlist[i];
        } 
    } 
}

// 100% matching!
void npPushMdlstr2(NJS_CNK_OBJECT* objp, int obj_n)
{
    int i; 
    
    for (i = 0; i < obj_n; i++, objp++) 
    {
        if ((objp->model != NULL) && (!(objp->evalflags & 0x8))) 
        {
            np.mdlstr2[i].pos[0] = objp->pos[0];
            np.mdlstr2[i].pos[1] = objp->pos[1];
            np.mdlstr2[i].pos[2] = objp->pos[2];
            
            np.mdlstr2[i].vlist = objp->model->vlist;
            np.mdlstr2[i].plist = objp->model->plist;
        } 
    } 
}

// 100% matching!
void npPopMdlstr2(NJS_CNK_OBJECT* objp, int obj_n)
{
    int i; 
    
    for (i = 0; i < obj_n; i++, objp++) 
    {
        if ((objp->model != NULL) && (!(objp->evalflags & 0x8))) 
        {
            objp->pos[0] = np.mdlstr2[i].pos[0];
            objp->pos[1] = np.mdlstr2[i].pos[1];
            objp->pos[2] = np.mdlstr2[i].pos[2];
            
            objp->model->vlist = np.mdlstr2[i].vlist;
            objp->model->plist = np.mdlstr2[i].plist;
        } 
    } 
}

// 100% matching!
void npCnkFlatOff(NJS_CNK_OBJECT* objp)
{
    int offset;
    short* plP;
    short head; 

    if (objp->model != NULL) 
    {
        plP = objp->model->plist;
        
        while (TRUE)
        {
            head = (unsigned char)*plP++; 
            
            if ((head >= 64) && (head < 67)) 
            { 
                plP[-1] &= ~0x2000; 
                
                offset = *plP++;
                plP += offset; 
            } 
            else if (head == 8) 
            { 
                plP++;
            }
            else if ((head >= 17) && (head < 24)) 
            { 
                offset = *plP++; 
                plP += offset; 
            } 
            else if ((head >= 56) && (head < 59))
            {
                offset = *plP++; 
                plP += offset; 
            } 
            else if (head == 255)
            {  
                break;
            }
        }
    }
    
    if (objp->child != NULL) 
    {
        npCnkFlatOff(objp->child);
    }
    
    if (objp->sibling != NULL) 
    {
        npCnkFlatOff(objp->sibling);
    }
}

// 100% matching!
void npClrTranslate() 
{
    njGetMatrix(lcmat);
   
    lcmat[0][14] = lcmat[0][13] = lcmat[0][12] = 0;
    
    njSetMatrix(NULL, lcmat); 
}

// 100% matching!
void npSetMemory(unsigned char* memp, unsigned int size, char dat)
{
    while (size-- != 0) 
    {
        *memp++ = dat;
    }
}

// 100% matching!
void npSetMemoryL(unsigned int* memp, unsigned int size, int dat) 
{ 
    while (size-- != 0) 
    {
        *memp++ = dat;
    }
}

// 100% matching!
void npCopyMemory(unsigned char* dst, unsigned char* src, unsigned int size)
{
    while (size-- != 0)
    {
        *dst++ = *src++;
    }
}

// 100% matching!
void npGetWHDSizeSub(NJS_CNK_OBJECT* objp, NJS_POINT3* whd)
{
	NJS_POINT3* ps3;   
	NJS_POINT3 pd3;    
	NJS_POINT4* ps4;  
    NJS_POINT4 pd4;    
	int i;           
    HDR_CV* pHdrCv; 
    HDR_PS* pHdrPs;

    njPushMatrix(NULL);
    
    njTranslate(NULL, objp->pos[0], objp->pos[1], objp->pos[2]);
    
    njRotateXYZ(NULL, objp->ang[0], objp->ang[1], objp->ang[2]);
    
    if ((objp->model != NULL) && (!(objp->evalflags & 0x8))) 
    { 
        pHdrPs = (HDR_PS*)objp->model->vlist;
        
        if (pHdrPs->ucType == 51)
        {
            ps4 = (NJS_POINT4*)((unsigned int)pHdrPs + 64);
            
            for (i = pHdrPs->usIndexMax; i-- != 0; )
            {
                njCalcPoint4(NULL, ps4, &pd4);
                
                if (fabsf(pd4.x) >= whd->x)
                {
                    whd->x = fabsf(pd4.x); 
                }
                
                if (fabsf(pd4.y) >= whd->y) 
                {
                    whd->y = fabsf(pd4.y);
                }
                
                if (fabsf(pd4.z) >= whd->z) 
                {
                    whd->z = fabsf(pd4.z);
                }
                
                ps4 = (NJS_POINT4*)((unsigned int)ps4 + 32);
            }
        } 
        else 
        {
            ps3 = (NJS_POINT3*)((unsigned int)pHdrPs + 8);
            
            for (i = pHdrPs->usIndexMax; i-- != 0; ) 
            {
                njCalcPoint(NULL, ps3, &pd3);
                
                if (fabsf(pd3.x) >= whd->x) 
                {
                    whd->x = fabsf(pd3.x);
                }
                
                if (fabsf(pd3.y) >= whd->y) 
                {
                    whd->y = fabsf(pd3.y);
                }
                
                if (fabsf(pd3.z) >= whd->z)
                {
                    whd->z = fabsf(pd3.z);
                }
                
                ps3 = (NJS_POINT3*)((unsigned int)ps3 + 24);
            }
        }
    }
    
    if (objp->child != NULL) 
    {
        npGetWHDSizeSub(objp->child, whd);
    }
    
    njPopMatrix(1);
    
    if (objp->sibling != NULL) 
    {
        npGetWHDSizeSub(objp->sibling, whd);
    }
}

// 100% matching!
void npGetWHDSize(NJS_CNK_OBJECT* objp, NJS_POINT3* whd) 
{
    whd->x = whd->y = whd->z = 0;
    
    njUnitMatrix(NULL);
    
    npGetWHDSizeSub(objp, whd);
}

// 100% matching!
void npSkinConvPreparation(NJS_CNK_OBJECT* objp)
{
    NJS_POINT3 ps = { 0 }; 
    int flg;      
    int mno;       
    int nb;       
    
    njPushMatrix(NULL);
    
    if (!(objp->evalflags & 0x20000000)) 
    {
        flg = *np.sknp++;
        
        if (flg != 0) 
        {
            if ((flg & 0x2)) 
            {
                mno = *np.sknp++;
                
                nb = *np.sknp++;

                np.cobj[mno] = objp;
                
                np.sktp[mno] = np.sknp;
                
                np.sknp += nb;
            } 
            else 
            {
                mno = *np.sknp++;
            }
        }
        
        njTranslate(NULL, objp->pos[0], objp->pos[1], objp->pos[2]);
        
        if ((flg & 0x2))
        {
            njCalcPoint(NULL, &ps, &np.op[mno]);
        }
    }
    
    if (objp->child != NULL)
    {
        npSkinConvPreparation(objp->child);
    }
    
    njPopMatrix(1);
    
    if (objp->sibling != NULL) 
    {
        npSkinConvPreparation(objp->sibling);
    }
}

// 100% matching!
void npSkinConvSub(NJS_CNK_OBJECT* objp)
{
    NJS_POINT4 ps = { 0, 0, 0, 0 }; 
    NJS_POINT4 pd;         
    NJS_POINT4* p0;        
    int* skp;              
    int nb;                
    int i;                 
    int dt;                
    int flg;               
    int mno;               
    HDR_PS* pHdr;      
    unsigned short max; // not from the debugging symbols
    float x, y, z; // not from the debugging symbols

    flg = *np.sknp++;
    
    if (flg != 0) 
    {
        if ((flg & 0x2)) 
        {
            objp->evalflags |= 0x80000000;
            
            mno = *np.sknp++;
            
            nb = *np.sknp++;
            
            np.sknp = &np.sknp[nb];
        } 
        else 
        {
            mno = *np.sknp++;
        }
        
        skp = np.sktp[mno];
    }
    
    njTranslate(NULL, objp->pos[0], objp->pos[1], objp->pos[2]);
    
    ps.z = 0;
    ps.y = 0;
    ps.x = 0;
    ps.w = 1.0f;
    
    njCalcPoint4(NULL, &ps, &pd);
    
    if ((flg & 0x1))
    {
        pHdr = (HDR_PS*)np.cobj[mno]->model->vlist;
        
        max = pHdr->usIndexMax;
        
        p0 = (NJS_POINT4*)&pHdr[1];
        
        i = 0;
        
        if (0 < max)
        {
            do 
            {
                if (np.obj_now == (*skp++ >> 24)) 
                {
                    x = p0->x + np.op[mno].x;
                    y = p0->y + np.op[mno].y;
                    z = p0->z + np.op[mno].z;
    
                    p0->x = x - pd.x;
                    p0->y = y - pd.y;
                    p0->z = z - pd.z;
                }
                
                p0 += 2;
                
                i++;
            } while (i < max);
        }
    }
}

// 100% matching!
void npSkinConvMain(NJS_CNK_OBJECT* objp)
{
    njPushMatrix(NULL);
    
    if (!(objp->evalflags & 0x20000000)) 
    {
        npSkinConvSub(objp);
        
        np.obj_now++;
    }
    
    if (objp->child != NULL) 
    {
        npSkinConvMain(objp->child);
    }
    
    njPopMatrix(1);
    
    if (objp->sibling != NULL) 
    {
        npSkinConvMain(objp->sibling);
    }
}

// 100% matching!
void npSkinConvert(NJS_CNK_OBJECT* objp, int* sknp)
{
    np.sknp = sknp;
    
    njUnitMatrix(NULL);
    
    npSkinConvPreparation(objp);
    
    np.sknp = sknp;
    
    np.obj_now = 0;
    
    njUnitMatrix(NULL);
    
    npSkinConvMain(objp);
}

// 
// Start address: 0x12d740
void npRetSkinConvMain(NJS_CNK_OBJECT* objp)
{
	//_anon3* pHdr;
	int mno;
	int flg;
	int dt;
	int i;
	int nb;
	int* skp;
	//_anon0* p0;
	//_anon0 pd;
	//_anon0 ps;
	// Line 2701, Address: 0x12d740, Func Offset: 0
	// Line 2703, Address: 0x12d750, Func Offset: 0x10
	// Line 2701, Address: 0x12d754, Func Offset: 0x14
	// Line 2703, Address: 0x12d758, Func Offset: 0x18
	// Line 2701, Address: 0x12d75c, Func Offset: 0x1c
	// Line 2703, Address: 0x12d760, Func Offset: 0x20
	// Line 2712, Address: 0x12d76c, Func Offset: 0x2c
	// Line 2713, Address: 0x12d778, Func Offset: 0x38
	// Line 2715, Address: 0x12d78c, Func Offset: 0x4c
	// Line 2716, Address: 0x12d7a0, Func Offset: 0x60
	// Line 2717, Address: 0x12d7a8, Func Offset: 0x68
	// Line 2718, Address: 0x12d7b4, Func Offset: 0x74
	// Line 2719, Address: 0x12d7cc, Func Offset: 0x8c
	// Line 2720, Address: 0x12d7e4, Func Offset: 0xa4
	// Line 2721, Address: 0x12d7f8, Func Offset: 0xb8
	// Line 2722, Address: 0x12d800, Func Offset: 0xc0
	// Line 2724, Address: 0x12d818, Func Offset: 0xd8
	// Line 2726, Address: 0x12d830, Func Offset: 0xf0
	// Line 2727, Address: 0x12d844, Func Offset: 0x104
	// Line 2728, Address: 0x12d850, Func Offset: 0x110
	// Line 2729, Address: 0x12d854, Func Offset: 0x114
	// Line 2728, Address: 0x12d85c, Func Offset: 0x11c
	// Line 2729, Address: 0x12d860, Func Offset: 0x120
	// Line 2730, Address: 0x12d868, Func Offset: 0x128
	// Line 2732, Address: 0x12d874, Func Offset: 0x134
	// Line 2736, Address: 0x12d888, Func Offset: 0x148
	// Line 2732, Address: 0x12d88c, Func Offset: 0x14c
	// Line 2734, Address: 0x12d894, Func Offset: 0x154
	// Line 2736, Address: 0x12d898, Func Offset: 0x158
	// Line 2737, Address: 0x12d8bc, Func Offset: 0x17c
	// Line 2739, Address: 0x12d8c0, Func Offset: 0x180
	// Line 2740, Address: 0x12d8d4, Func Offset: 0x194
	// Line 2741, Address: 0x12d8ec, Func Offset: 0x1ac
	// Line 2742, Address: 0x12d904, Func Offset: 0x1c4
	// Line 2743, Address: 0x12d91c, Func Offset: 0x1dc
	// Line 2746, Address: 0x12d920, Func Offset: 0x1e0
	// Line 2749, Address: 0x12d930, Func Offset: 0x1f0
	// Line 2751, Address: 0x12d944, Func Offset: 0x204
	// Line 2752, Address: 0x12d958, Func Offset: 0x218
	// Line 2753, Address: 0x12d964, Func Offset: 0x224
	// Line 2754, Address: 0x12d978, Func Offset: 0x238
	// Func End, Address: 0x12d994, Func Offset: 0x254
    scePrintf("npRetSkinConvMain - UNIMPLEMENTED!\n");
}

// 100% matching!
void npRetSkinConvert(NJS_CNK_OBJECT* objp, int* sknp) 
{
    np.sknp = sknp;
    
    njUnitMatrix(NULL);
    
    npSkinConvPreparation(objp);
    
    np.sknp = sknp;
    
    np.obj_now = 0;
    
    njUnitMatrix(NULL);
    
    npRetSkinConvMain(objp);
}

// 100% matching!
unsigned int npGetMatColor(NJS_CNK_OBJECT* objp, int obj_n)
{
	int i;
    unsigned int* pnt;

    for (i = 0; i < obj_n; i++, objp++) 
    {
        if ((objp->model != NULL) && (!(objp->evalflags & 0x8))) 
        {
            pnt = (unsigned int*)objp->model->plist;
        
            return *++pnt;
        }
    }
    
    return 0;
}

/*// 
// Start address: 0x12da70
void npSetAllMatColor(npobj* objp, int obj_n, unsigned int argb)
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
	unsigned char* mat;
	short* plp;
	short head;
	int offset;
	int i;
	// Line 2877, Address: 0x12da70, Func Offset: 0
	// Line 2878, Address: 0x12da80, Func Offset: 0x10
	// Line 2871, Address: 0x12da90, Func Offset: 0x20
	// Line 2879, Address: 0x12da94, Func Offset: 0x24
	// Line 2871, Address: 0x12da9c, Func Offset: 0x2c
	// Line 2879, Address: 0x12daa0, Func Offset: 0x30
	// Line 2881, Address: 0x12daa4, Func Offset: 0x34
	// Line 2871, Address: 0x12daa8, Func Offset: 0x38
	// Line 2880, Address: 0x12daac, Func Offset: 0x3c
	// Line 2881, Address: 0x12dab0, Func Offset: 0x40
	// Line 2895, Address: 0x12dab8, Func Offset: 0x48
	// Line 2890, Address: 0x12dac8, Func Offset: 0x58
	// Line 2923, Address: 0x12dacc, Func Offset: 0x5c
	// Line 2882, Address: 0x12dad0, Func Offset: 0x60
	// Line 2883, Address: 0x12daec, Func Offset: 0x7c
	// Line 2884, Address: 0x12daf4, Func Offset: 0x84
	// Line 2885, Address: 0x12daf8, Func Offset: 0x88
	// Line 2886, Address: 0x12db04, Func Offset: 0x94
	// Line 2887, Address: 0x12db1c, Func Offset: 0xac
	// Line 2888, Address: 0x12db24, Func Offset: 0xb4
	// Line 2889, Address: 0x12db28, Func Offset: 0xb8
	// Line 2890, Address: 0x12db30, Func Offset: 0xc0
	// Line 2892, Address: 0x12db40, Func Offset: 0xd0
	// Line 2895, Address: 0x12db58, Func Offset: 0xe8
	// Line 2898, Address: 0x12db80, Func Offset: 0x110
	// Line 2899, Address: 0x12db84, Func Offset: 0x114
	// Line 2900, Address: 0x12db88, Func Offset: 0x118
	// Line 2901, Address: 0x12db8c, Func Offset: 0x11c
	// Line 2902, Address: 0x12db98, Func Offset: 0x128
	// Line 2905, Address: 0x12dba0, Func Offset: 0x130
	// Line 2906, Address: 0x12dba4, Func Offset: 0x134
	// Line 2907, Address: 0x12dba8, Func Offset: 0x138
	// Line 2908, Address: 0x12dbac, Func Offset: 0x13c
	// Line 2909, Address: 0x12dbc0, Func Offset: 0x150
	// Line 2910, Address: 0x12dbc4, Func Offset: 0x154
	// Line 2911, Address: 0x12dbc8, Func Offset: 0x158
	// Line 2912, Address: 0x12dbcc, Func Offset: 0x15c
	// Line 2914, Address: 0x12dbdc, Func Offset: 0x16c
	// Line 2915, Address: 0x12dbe0, Func Offset: 0x170
	// Line 2916, Address: 0x12dbe8, Func Offset: 0x178
	// Line 2917, Address: 0x12dbec, Func Offset: 0x17c
	// Line 2918, Address: 0x12dbf4, Func Offset: 0x184
	// Line 2920, Address: 0x12dc0c, Func Offset: 0x19c
	// Line 2921, Address: 0x12dc14, Func Offset: 0x1a4
	// Line 2922, Address: 0x12dc18, Func Offset: 0x1a8
	// Line 2923, Address: 0x12dc20, Func Offset: 0x1b0
	// Line 2926, Address: 0x12dc28, Func Offset: 0x1b8
	// Line 2927, Address: 0x12dc38, Func Offset: 0x1c8
	// Func End, Address: 0x12dc48, Func Offset: 0x1d8
}*/

// 100% matching!
void npChangeMatAlphaColor(NJS_CNK_OBJECT* objp, int obj_n, unsigned char alpha)
{
	int i;
    unsigned char* pnt;
    
    for (i = 0; i < obj_n; i++, objp++)
    {
        if ((objp->model != NULL) && (!(objp->evalflags & 0x8))) 
        {
            pnt = (unsigned char*)objp->model->plist;

            pnt += 7;
            
            *pnt = alpha;

            pnt += 4;
            
            *pnt = alpha;
        }
    } 
}

/*// 
// Start address: 0x12dca0
void npSetAllMatAlphaColor(npobj* objp, int obj_n, unsigned char alpha)
{
	unsigned char* mat;
	short* plp;
	short head;
	int offset;
	int i;
	// Line 2965, Address: 0x12dca0, Func Offset: 0
	// Line 2979, Address: 0x12dcac, Func Offset: 0xc
	// Line 2974, Address: 0x12dcbc, Func Offset: 0x1c
	// Line 2998, Address: 0x12dcc0, Func Offset: 0x20
	// Line 2966, Address: 0x12dcc4, Func Offset: 0x24
	// Line 2967, Address: 0x12dce0, Func Offset: 0x40
	// Line 2969, Address: 0x12dce8, Func Offset: 0x48
	// Line 2970, Address: 0x12dcf4, Func Offset: 0x54
	// Line 2971, Address: 0x12dd0c, Func Offset: 0x6c
	// Line 2972, Address: 0x12dd14, Func Offset: 0x74
	// Line 2973, Address: 0x12dd18, Func Offset: 0x78
	// Line 2974, Address: 0x12dd20, Func Offset: 0x80
	// Line 2976, Address: 0x12dd30, Func Offset: 0x90
	// Line 2979, Address: 0x12dd48, Func Offset: 0xa8
	// Line 2983, Address: 0x12dd70, Func Offset: 0xd0
	// Line 2986, Address: 0x12dd78, Func Offset: 0xd8
	// Line 2987, Address: 0x12dd7c, Func Offset: 0xdc
	// Line 2990, Address: 0x12dd80, Func Offset: 0xe0
	// Line 2991, Address: 0x12dd88, Func Offset: 0xe8
	// Line 2992, Address: 0x12dd8c, Func Offset: 0xec
	// Line 2993, Address: 0x12dd94, Func Offset: 0xf4
	// Line 2995, Address: 0x12ddac, Func Offset: 0x10c
	// Line 2996, Address: 0x12ddb4, Func Offset: 0x114
	// Line 2997, Address: 0x12ddb8, Func Offset: 0x118
	// Line 2998, Address: 0x12ddc0, Func Offset: 0x120
	// Line 3001, Address: 0x12ddc8, Func Offset: 0x128
	// Line 3002, Address: 0x12ddd8, Func Offset: 0x138
	// Func End, Address: 0x12dde0, Func Offset: 0x140
}*/

// 100% matching!
void npSetOffsetUV(NJS_CNK_MODEL* mdlp, short offu, short offv)
{
	int offset; 
    int srp_num; 
    int usr_num;
    short head; 
    short* plp;  

    plp = mdlp->plist; 
    
    while (TRUE) 
    {
        head = (unsigned char)*plp++; 
        
        if ((head >= 64) && (head < 67)) 
        {
            offset = *plp++; 
            
            usr_num = (*plp >> 14) & 0x3; 
            srp_num = *plp++ & ~0xC000; 
            
            if (head == 64) 
            { 
                plp += offset; 
            } 
            else 
            {
                asm volatile 
                ("
                .set noreorder
                
                l_0012DE68: 
                    lh   t2, 0(%0) 
                    
                    bgez t2, l_0012DE78
                    add  %0, %0, 2
                    
                    neg  t2, t2
                    
                l_0012DE78:
                    lh   t0, 2(%0)
                    lh   t1, 4(%0)
                    
                    add  t0, t0, %1
                    add  t1, t1, %2
                    
                    sh   t0, 2(%0)
                    sh   t1, 4(%0)
                    
                    add  t2, t2, -1

                    bgtz t2, l_0012DE78
                    add  %0, %0, 6
                    
                    add  %0, %0, %3
                    add  %4, %4, -1
                    
                    bgtz %4, l_0012DE68
                    add  %0, %0, %3
                    
                    add  %0, %0, zero
                    
                .set reorder
                " : "=r"(plp) : "r"(offu), "r"(offv), "r"(usr_num), "r"(srp_num) : "t0", "t1", "t2"
                );
            }
        }
        else if (head == 8) 
        { 
            plp++; 
        } 
        else if ((head >= 17) && (head < 24)) 
        { 
            offset = *plp++; 
            plp += offset;
        } 
        else if ((head >= 56) && (head < 59)) 
        { 
            offset = *plp++; 
            plp += offset; 
        }
        else if (head == 255)
        { 
            break;
        }
    }
}

// 100% matching!
void npSetOffsetUV2(NJS_CNK_MODEL* mdlp, short offu, short offv)
{
    int srp_num; 
    int usr_num;
    short head; 
    short* plp;  

    plp = mdlp->plist; 
    
    while (TRUE) 
    {
        head = (unsigned char)*plp++; 
        
        if (head == 66)
        { 
            usr_num = (*++plp >> 14) & 0x3; 
            srp_num = *plp++ & ~0xC000;
           
            asm volatile 
            ("
            .set noreorder
            
            l_0012DFA8: 
                lh   t2, 0(%0) 
                
                bgez t2, l_0012DFB8
                add  %0, %0, 2
                
                neg  t2, t2
                
            l_0012DFB8:
                lh   t0, 2(%0)
                lh   t1, 4(%0)
                
                add  t0, t0, %1
                add  t1, t1, %2
                
                sh   t0, 2(%0)
                sh   t1, 4(%0)
                
                add  t2, t2, -1

                bgtz t2, l_0012DFB8
                add  %0, %0, 6
                
                add  %0, %0, %3
                add  %4, %4, -1
                
                bgtz %4, l_0012DFA8
                add  %0, %0, %3
                
            .set reorder
            " : "=r"(plp) : "r"(offu), "r"(offv), "r"(usr_num), "r"(srp_num) : "t0", "t1", "t2"
            );

            break;
        }
        else if (head != 255)
        { 
            *plp++;  
        }
        else 
        {
            break;
        }
    }
}

// 100% matching!
int npCopyVlist(int* dstp, int* srcp)
{
    HDR_PS* pPs;
    int nb;
	
    pPs = (HDR_PS*)srcp;

    if (pPs->ucType == 41)
    {
        nb = ((*(int*)&pPs->usIndexOfs >> 16) * 24) + 12;
        
        njMemCopy4(dstp, srcp, nb / 4);
    } 
    else 
    {
        nb = (pPs->usIndexMax * 32) + 72;
        
        njMemCopy4(dstp, srcp, nb / 4);
    }
    
    return nb;
}

// 100% matching!
void npCutSkin() 
{
    
}

// 100% matching!
void npInitCalcSkin(void* pwp, int obj_n, int* sknp)
{ 
	NJS_MATRIX mat;        
	O_WORK* owp;     
	NJS_CNK_OBJECT* op;    
	int i;                
	int flg;               
	int nb;               
	int mno;              
    unsigned int ulSize;    
	unsigned char matb[64]; 

    owp = ((BH_PWORK*)pwp)->mlwP->owP; 
    
    np.bp = np.buff + (obj_n * 128); 
    
    njUnitMatrix(NULL);
    
    np.sknp = sknp; 
    
    op = ((BH_PWORK*)pwp)->mlwP->objP; 
    
    for (i = 0; i < obj_n; i++, op++, owp++)
    { 
        flg = *np.sknp++;
        
        if (flg != 0) 
        { 
            if ((flg & 0x2)) 
            { 
                mno = *np.sknp++;
                
                nb = *np.sknp++; 
                
                np.sknp += nb; 
                
                np.vlp[mno] = (int*)np.bp;
                
                ulSize = (nb * 32) + 32;
                
                ulSize += 64 - (ulSize & 0x3F); 
                
                np.bp += ulSize; 
            } 
            else 
            { 
                np.sknp++; 
            }
            
            asm volatile 
            ("
            .set noreorder
            
                ldl      t0, 7(%1) 
                ldr      t0, 0(%1)
                
                lw       t1, 8(%1)
                
                pcpyld   t0, t1, t0
            
                qmtc2    t0, vf8
            
                lqc2     vf7, 48(%0)
                lqc2     vf4, 0(%0)
                lqc2     vf5, 16(%0)
                lqc2     vf6, 32(%0)
                
                vsub.xyz vf7xyz, vf7xyz, vf8xyz
                
                sqc2     vf4, 0(%2)
                sqc2     vf5, 16(%2)
                sqc2     vf6, 32(%2)
                sqc2     vf7, 48(%2)
                sqc2     vf4, 64(%2)
                sqc2     vf5, 80(%2)
                sqc2     vf6, 96(%2)
                sqc2     vf7, 112(%2) 
            
            .set reorder
            " : : "r"(&owp->mtx), "r"(&((BH_PWORK*)pwp)->px), "r"(np.mxp[i][0]), "r"(owp) 
            );
                
            njRotXYZ(np.mxp[i][0], -op->ang[0], -op->ang[1], -op->ang[2]); 
        }
    } 
} 

// 99.93% matching
void npCalcSkin(void* pwp, int obj_n, int* sknp)
{ 
    NJS_POINT4* p0;
    NJS_CNK_OBJECT* op;
    float lv;
    float* p1;
    int i;
    int j;
    int flg;
    int rg0;
    int nb;
    HDR_PS* pHdr0;
    HDR_PS* pHdr1;
    static float level[10] = { 0.1000000015f, 0.200000003f, 0.3000000119f, 0.400000006f, 0.5f, 0.6000000238f, 0.6999999881f, 0.8000000119f, 0.8999999762f, 1.0f };

    if (sknp != NULL)
    { 
        njPushMatrixEx(); 

        npInitCalcSkin(pwp, obj_n, sknp); 
        
        np.sknp = sknp; 
        
        op = (NJS_CNK_OBJECT*)((O_WRK*)pwp)->mlwP->objP; 
        
        for (i = 0; i < obj_n; i++, op++) 
        { 
            flg = *np.sknp++; 
            
            if (flg != 0) 
            { 
                if ((flg & 0x2)) 
                { 
                    pHdr0 = (HDR_PS*)op->model->vlist;
                    
                    rg0 = *np.sknp++; 
                    
                    op->model->vlist = np.vlp[rg0]; 
                    
                    pHdr1 = (HDR_PS*)np.vlp[rg0]; 
                    
                    nb = *np.sknp++;
    
                    pHdr1 = (HDR_PS*)((int)pHdr1 | 0x30000000); 
    
                    pHdr1->ucType = pHdr0->ucType;
                    pHdr1->ucAttr = pHdr0->ucAttr; 
                    
                    pHdr1->usSize = pHdr0->usSize;
                    
                    pHdr1->usIndexOfs = pHdr0->usIndexOfs; 
                    pHdr1->usIndexMax = pHdr0->usIndexMax; 
                    
                    p0 = (NJS_POINT4*)(pHdr0 + 1); 
                    p1 = (float*)(pHdr1 + 1); 
    
                    for (j = 0; j < nb; j++) 
                    { 
                        rg0 = *np.sknp++; 
                        
                        lv = level[(rg0 >> 16) & 0xFF]; 
                        
                        rg0 >>= 24;
                        
                        if (lv != 1.0f) 
                        { 
                            asm volatile 
                            ("
                            .set noreorder
                            
                                mfc1        t0, %0 
                                
                                qmtc2       t0, vf13
                                
                                lqc2        vf4, 0(%1)
                                lqc2        vf5, 0(%3)
                                lqc2        vf6, 0x10(%3)
                                lqc2        vf7, 0x20(%3)
                                lqc2        vf8, 0x30(%3)
                                
                                vmulax.xyz  ACC, vf5, vf4x
                                
                                vmadday.xyz ACC, vf6, vf4y
                                vmaddaz.xyz ACC, vf7, vf4z
                                
                                vmaddw.xyz  vf9, vf8, vf0w
                                
                                lqc2        vf5, 0(%4)
                                lqc2        vf6, 0x10(%4)
                                lqc2        vf7, 0x20(%4)
                                lqc2        vf8, 0x30(%4)
                                
                                vmulax.xyz  ACC, vf5, vf4x
                                
                                vmadday.xyz ACC, vf6, vf4y
                                vmaddaz.xyz ACC, vf7, vf4z
                                
                                vmaddw.xyz  vf10, vf8, vf0w
                                
                                vsub.xyz    vf5, vf10, vf9
                                
                                vmulx.xyz   vf6, vf5, vf13x
                                
                                vadd.xyz    vf7, vf6, vf9
                                
                                sqc2        vf7, 0(%2) 
                                
                            .set reorder
                            " : : "f"(lv), "r"(p0), "r"(p1), "r"(np.mxp[rg0][0]), "r"(np.mxp[rg0][1]) : "t0" 
                            );
                            
                            p1 += 4; 
                            p0++; 
                            
                            asm volatile 
                            ("
                            .set noreorder
                                             
                                mfc1        t0, %0 
                                
                                qmtc2       t0, vf13
                                
                                lqc2        vf4, 0(%1)
                                lqc2        vf5, 0(%3)
                                lqc2        vf6, 0x10(%3)
                                lqc2        vf7, 0x20(%3)
                                lqc2        vf8, 0(%4)
                                lqc2        vf9, 0x10(%4)
                                lqc2        vf10, 0x20(%4)
                                
                                vmulax.xyz  ACC, vf5, vf4x
                                
                                vmadday.xyz ACC, vf6, vf4y
                                
                                vmaddz.xyz  vf11, vf7, vf4z
                                
                                vmulax.xyz  ACC, vf8, vf4x
                                
                                vmadday.xyz ACC, vf9, vf4y
                                
                                vmaddz.xyz  vf12, vf10, vf4z
                                
                                vsub.xyz    vf5, vf12, vf11
                                
                                vmulx.xyz   vf6, vf5, vf13x
                                
                                vadd.xyz    vf7, vf6, vf11
                                
                                sqc2        vf7, 0(%2) 
                                
                            .set reorder
                            " : : "f"(lv), "r"(p0),  "r"(p1), "r"(np.mxp[rg0][0]), "r"(np.mxp[rg0][1]) : "t0" 
                            );
                            
                            p1 += 4; 
                            p0++;
                        } 
                        else 
                        { 
                            asm volatile 
                            ("
                            .set noreorder
                                              
                                lqc2        vf4, 0(%0) 
                                lqc2        vf11, 0x10(%0)
                                lqc2        vf5, 0(%2)
                                lqc2        vf6, 0x10(%2)
                                lqc2        vf7, 0x20(%2)
                                lqc2        vf8, 0x30(%2)
                                
                                vmulax.xyz  ACC, vf5xyz, vf4x
                                
                                vmadday.xyz ACC, vf6xyz, vf4y
                                vmaddaz.xyz ACC, vf7xyz, vf4z
                                
                                vmaddw.xyz  vf9, vf8xyz, vf0w
                                
                                vmulax.xyz  ACC, vf5xyz, vf11x
                                
                                vmadday.xyz ACC, vf6xyz, vf11y
                                
                                vmaddz.xyz  vf10xyz, vf7xyz, vf11z
                                
                                sqc2        vf9, 0(%1)
                                sqc2        vf10, 0x10(%1) 
                                
                            .set reorder
                            " : : "r"(p0), "r"(p1), "r"(np.mxp[rg0][1]), "r"(op)
                            ); 
                            
                            p0 += 2; 
                            p1 += 8; 
                        }
                    } 
                    
                    *(int*)p1 = 255; 
                } 
                else 
                { 
                    np.sknp++;
                } 
            }
        } 
    
        njPopMatrixEx(); 
    }
} 

// 100% matching!
void npInitCalcSkinFM(void* pwp, int obj_n, int* sknp)
{ 
	NJS_MATRIX mat;        
	O_WORK* owp;     
	NJS_CNK_OBJECT* op;    
	int i;                
	int flg;               
	int nb;               
	int mno;              
    unsigned int ulSize;    
	unsigned char matb[64]; 

    owp = ((BH_PWORK*)pwp)->mlwP->owP; 
    
    np.bp = np.buff + (obj_n * 128); 
    
    njUnitMatrix(NULL);
    
    np.sknp = sknp; 
    
    op = ((BH_PWORK*)pwp)->mlwP->objP; 
    
    for (i = 0; i < obj_n; i++, op++, owp++)
    { 
        if ((i < 11) || (i > 14))
        {
            flg = *np.sknp++;
        
            if (flg != 0) 
            { 
                if ((flg & 0x2)) 
                { 
                    mno = *np.sknp++;
                    
                    nb = *np.sknp++; 
                    
                    np.sknp += nb; 
                    
                    np.vlp[mno] = (int*)np.bp;
                    
                    ulSize = (nb * 32) + 96;
                    
                    ulSize += 64 - (ulSize & 0x3F); 
                    
                    np.bp += ulSize; 
                } 
                else 
                { 
                    np.sknp++; 
                }
                
                asm volatile 
                ("
                .set noreorder
                
                    ldl      t0, 7(%1) 
                    ldr      t0, 0(%1)
                    
                    lw       t1, 8(%1)
                    
                    pcpyld   t0, t1, t0
                
                    qmtc2    t0, vf8
                
                    lqc2     vf7, 48(%0)
                    lqc2     vf4, 0(%0)
                    lqc2     vf5, 16(%0)
                    lqc2     vf6, 32(%0)
                    
                    vsub.xyz vf7xyz, vf7xyz, vf8xyz
                    
                    sqc2     vf4, 0(%2)
                    sqc2     vf5, 16(%2)
                    sqc2     vf6, 32(%2)
                    sqc2     vf7, 48(%2)
                    sqc2     vf4, 64(%2)
                    sqc2     vf5, 80(%2)
                    sqc2     vf6, 96(%2)
                    sqc2     vf7, 112(%2) 
                
                .set reorder
                " : : "r"(&owp->mtx), "r"(&((BH_PWORK*)pwp)->px), "r"(np.mxp[i][0]), "r"(owp) 
                );
                    
                njRotXYZ(np.mxp[i][0], -op->ang[0], -op->ang[1], -op->ang[2]); 
            }
        }
    } 
} 

// 99.93% matching
void npCalcSkinFM(void* pwp, int obj_n, int* sknp)
{ 
    NJS_POINT4* p0;
    NJS_CNK_OBJECT* op;
    float lv;
    float* p1;
    int i;
    int j;
    int flg;
    int rg0;
    int nb;
    HDR_PS* pHdr0;
    HDR_PS* pHdr1;
    static float level[10] = { 0.1000000015f, 0.200000003f, 0.3000000119f, 0.400000006f, 0.5f, 0.6000000238f, 0.6999999881f, 0.8000000119f, 0.8999999762f, 1.0f };

    if (sknp != NULL)
    { 
        njPushMatrixEx(); 

        npInitCalcSkinFM(pwp, obj_n, sknp); 
        
        np.sknp = sknp; 
        
        op = (NJS_CNK_OBJECT*)((O_WRK*)pwp)->mlwP->objP; 
        
        for (i = 0; i < obj_n; i++, op++) 
        { 
            if ((i < 11) || (i > 14))
            {
                flg = *np.sknp++; 
                
                if (flg != 0) 
                { 
                    if ((flg & 0x2)) 
                    { 
                        pHdr0 = (HDR_PS*)op->model->vlist;
                        
                        rg0 = *np.sknp++; 
                        
                        op->model->vlist = np.vlp[rg0]; 
                        
                        pHdr1 = (HDR_PS*)np.vlp[rg0]; 
                        
                        nb = *np.sknp++;
        
                        pHdr1 = (HDR_PS*)((int)pHdr1 | 0x30000000); 
        
                        pHdr1->ucType = pHdr0->ucType;
                        pHdr1->ucAttr = pHdr0->ucAttr; 
                        
                        pHdr1->usSize = pHdr0->usSize;
                        
                        pHdr1->usIndexOfs = pHdr0->usIndexOfs; 
                        pHdr1->usIndexMax = pHdr0->usIndexMax; 
                        
                        p0 = (NJS_POINT4*)(pHdr0 + 1); 
                        p1 = (float*)(pHdr1 + 1); 
        
                        for (j = 0; j < nb; j++) 
                        { 
                            rg0 = *np.sknp++; 
                            
                            lv = level[(rg0 >> 16) & 0xFF]; 
                            
                            rg0 >>= 24;

                            if (rg0 > 10)
                            {
                                rg0 += 4;
                            }
                            
                            if (lv != 1.0f) 
                            { 
                                asm volatile 
                                ("
                                .set noreorder
                                
                                    mfc1        t0, %0 
                                    
                                    qmtc2       t0, vf13
                                    
                                    lqc2        vf4, 0(%1)
                                    lqc2        vf5, 0(%3)
                                    lqc2        vf6, 0x10(%3)
                                    lqc2        vf7, 0x20(%3)
                                    lqc2        vf8, 0x30(%3)
                                    
                                    vmulax.xyz  ACC, vf5, vf4x
                                    
                                    vmadday.xyz ACC, vf6, vf4y
                                    vmaddaz.xyz ACC, vf7, vf4z
                                    
                                    vmaddw.xyz  vf9, vf8, vf0w
                                    
                                    lqc2        vf5, 0(%4)
                                    lqc2        vf6, 0x10(%4)
                                    lqc2        vf7, 0x20(%4)
                                    lqc2        vf8, 0x30(%4)
                                    
                                    vmulax.xyz  ACC, vf5, vf4x
                                    
                                    vmadday.xyz ACC, vf6, vf4y
                                    vmaddaz.xyz ACC, vf7, vf4z
                                    
                                    vmaddw.xyz  vf10, vf8, vf0w
                                    
                                    vsub.xyz    vf5, vf10, vf9
                                    
                                    vmulx.xyz   vf6, vf5, vf13x
                                    
                                    vadd.xyz    vf7, vf6, vf9
                                    
                                    sqc2        vf7, 0(%2) 
                                    
                                .set reorder
                                " : : "f"(lv), "r"(p0), "r"(p1), "r"(np.mxp[rg0][0]), "r"(np.mxp[rg0][1]) : "t0" 
                                );
                                
                                p1 += 4; 
                                p0++; 
                                
                                asm volatile 
                                ("
                                .set noreorder
                                                 
                                    mfc1        t0, %0 
                                    
                                    qmtc2       t0, vf13
                                    
                                    lqc2        vf4, 0(%1)
                                    lqc2        vf5, 0(%3)
                                    lqc2        vf6, 0x10(%3)
                                    lqc2        vf7, 0x20(%3)
                                    lqc2        vf8, 0(%4)
                                    lqc2        vf9, 0x10(%4)
                                    lqc2        vf10, 0x20(%4)
                                    
                                    vmulax.xyz  ACC, vf5, vf4x
                                    
                                    vmadday.xyz ACC, vf6, vf4y
                                    
                                    vmaddz.xyz  vf11, vf7, vf4z
                                    
                                    vmulax.xyz  ACC, vf8, vf4x
                                    
                                    vmadday.xyz ACC, vf9, vf4y
                                    
                                    vmaddz.xyz  vf12, vf10, vf4z
                                    
                                    vsub.xyz    vf5, vf12, vf11
                                    
                                    vmulx.xyz   vf6, vf5, vf13x
                                    
                                    vadd.xyz    vf7, vf6, vf11
                                    
                                    sqc2        vf7, 0(%2) 
                                    
                                .set reorder
                                " : : "f"(lv), "r"(p0),  "r"(p1), "r"(np.mxp[rg0][0]), "r"(np.mxp[rg0][1]) : "t0" 
                                );
                                
                                p1 += 4; 
                                p0++;
                            } 
                            else 
                            { 
                                asm volatile 
                                ("
                                .set noreorder
                                                  
                                    lqc2        vf4, 0(%0) 
                                    lqc2        vf11, 0x10(%0)
                                    lqc2        vf5, 0(%2)
                                    lqc2        vf6, 0x10(%2)
                                    lqc2        vf7, 0x20(%2)
                                    lqc2        vf8, 0x30(%2)
                                    
                                    vmulax.xyz  ACC, vf5xyz, vf4x
                                    
                                    vmadday.xyz ACC, vf6xyz, vf4y
                                    vmaddaz.xyz ACC, vf7xyz, vf4z
                                    
                                    vmaddw.xyz  vf9, vf8xyz, vf0w
                                    
                                    vmulax.xyz  ACC, vf5xyz, vf11x
                                    
                                    vmadday.xyz ACC, vf6xyz, vf11y
                                    
                                    vmaddz.xyz  vf10xyz, vf7xyz, vf11z
                                    
                                    sqc2        vf9, 0(%1)
                                    sqc2        vf10, 0x10(%1) 
                                    
                                .set reorder
                                " : : "r"(p0), "r"(p1), "r"(np.mxp[rg0][1]), "r"(op)
                                ); 
                                
                                p0 += 2; 
                                p1 += 8; 
                            }
                        } 
                        
                        *(int*)p1 = 255; 
                    } 
                    else 
                    { 
                        np.sknp++;
                    } 
                }
            }
        } 
    
        njPopMatrixEx(); 
    }
} 
