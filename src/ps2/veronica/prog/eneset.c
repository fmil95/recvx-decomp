#include "eneset.h"
#include "njplus.h"
#include "main.h"

/*void(*bhJumpEnemy)()[100];
_anon23 En00CapColTab[5];
BH_PWORK ene[0];
_anon24* sys;
BH_PWORK* plp;
_anon9* rom;*/

// 100% matching! 
void bhInitEnemy()
{
    npSetMemory((unsigned char*)ene, 180224, 0);
}

// 
// Start address: 0x174720
BH_PWORK* bhSetEnemy(EGG_WORK* etp, int param) // second parameter is not present on the debugging symbols
{
	int i;
	BH_PWORK* epp;
	// Line 323, Address: 0x174720, Func Offset: 0
	// Line 326, Address: 0x174734, Func Offset: 0x14
	// Line 327, Address: 0x174740, Func Offset: 0x20
	// Line 328, Address: 0x174744, Func Offset: 0x24
	// Line 329, Address: 0x174754, Func Offset: 0x34
	// Line 330, Address: 0x174764, Func Offset: 0x44
	// Line 331, Address: 0x17476c, Func Offset: 0x4c
	// Line 332, Address: 0x174774, Func Offset: 0x54
	// Line 334, Address: 0x174784, Func Offset: 0x64
	// Line 337, Address: 0x174788, Func Offset: 0x68
	// Line 334, Address: 0x17478c, Func Offset: 0x6c
	// Line 337, Address: 0x174794, Func Offset: 0x74
	// Line 347, Address: 0x17485c, Func Offset: 0x13c
	// Line 346, Address: 0x174860, Func Offset: 0x140
	// Line 347, Address: 0x174864, Func Offset: 0x144
	// Line 348, Address: 0x174868, Func Offset: 0x148
	// Line 349, Address: 0x174870, Func Offset: 0x150
	// Line 350, Address: 0x174878, Func Offset: 0x158
	// Line 351, Address: 0x174880, Func Offset: 0x160
	// Line 352, Address: 0x174888, Func Offset: 0x168
	// Line 353, Address: 0x174890, Func Offset: 0x170
	// Line 354, Address: 0x174894, Func Offset: 0x174
	// Line 364, Address: 0x17489c, Func Offset: 0x17c
	// Line 363, Address: 0x1748a0, Func Offset: 0x180
	// Line 364, Address: 0x1748a4, Func Offset: 0x184
	// Line 365, Address: 0x1748a8, Func Offset: 0x188
	// Line 366, Address: 0x1748b0, Func Offset: 0x190
	// Line 367, Address: 0x1748b8, Func Offset: 0x198
	// Line 368, Address: 0x1748c0, Func Offset: 0x1a0
	// Line 369, Address: 0x1748c8, Func Offset: 0x1a8
	// Line 370, Address: 0x1748d0, Func Offset: 0x1b0
	// Line 373, Address: 0x1748d8, Func Offset: 0x1b8
	// Line 381, Address: 0x1748e4, Func Offset: 0x1c4
	// Line 383, Address: 0x1748f4, Func Offset: 0x1d4
	// Line 385, Address: 0x174900, Func Offset: 0x1e0
	// Line 403, Address: 0x174904, Func Offset: 0x1e4
	// Line 412, Address: 0x174908, Func Offset: 0x1e8
	// Line 421, Address: 0x17490c, Func Offset: 0x1ec
	// Line 425, Address: 0x174910, Func Offset: 0x1f0
	// Line 385, Address: 0x174914, Func Offset: 0x1f4
	// Line 387, Address: 0x174918, Func Offset: 0x1f8
	// Line 426, Address: 0x17491c, Func Offset: 0x1fc
	// Line 427, Address: 0x174920, Func Offset: 0x200
	// Line 387, Address: 0x174924, Func Offset: 0x204
	// Line 388, Address: 0x174928, Func Offset: 0x208
	// Line 389, Address: 0x174930, Func Offset: 0x210
	// Line 390, Address: 0x174938, Func Offset: 0x218
	// Line 391, Address: 0x174940, Func Offset: 0x220
	// Line 392, Address: 0x174948, Func Offset: 0x228
	// Line 393, Address: 0x17494c, Func Offset: 0x22c
	// Line 394, Address: 0x174954, Func Offset: 0x234
	// Line 395, Address: 0x174958, Func Offset: 0x238
	// Line 396, Address: 0x174964, Func Offset: 0x244
	// Line 397, Address: 0x174968, Func Offset: 0x248
	// Line 398, Address: 0x174978, Func Offset: 0x258
	// Line 399, Address: 0x17497c, Func Offset: 0x25c
	// Line 400, Address: 0x174980, Func Offset: 0x260
	// Line 401, Address: 0x174984, Func Offset: 0x264
	// Line 402, Address: 0x174988, Func Offset: 0x268
	// Line 403, Address: 0x17498c, Func Offset: 0x26c
	// Line 404, Address: 0x174994, Func Offset: 0x274
	// Line 405, Address: 0x17499c, Func Offset: 0x27c
	// Line 407, Address: 0x1749a4, Func Offset: 0x284
	// Line 408, Address: 0x1749a8, Func Offset: 0x288
	// Line 409, Address: 0x1749ac, Func Offset: 0x28c
	// Line 412, Address: 0x1749b0, Func Offset: 0x290
	// Line 418, Address: 0x1749b4, Func Offset: 0x294
	// Line 419, Address: 0x1749c0, Func Offset: 0x2a0
	// Line 420, Address: 0x1749cc, Func Offset: 0x2ac
	// Line 421, Address: 0x1749d0, Func Offset: 0x2b0
	// Line 422, Address: 0x1749d4, Func Offset: 0x2b4
	// Line 423, Address: 0x1749d8, Func Offset: 0x2b8
	// Line 424, Address: 0x1749dc, Func Offset: 0x2bc
	// Line 425, Address: 0x1749e0, Func Offset: 0x2c0
	// Line 427, Address: 0x1749e4, Func Offset: 0x2c4
	// Line 428, Address: 0x1749ec, Func Offset: 0x2cc
	// Line 429, Address: 0x1749f4, Func Offset: 0x2d4
	// Line 431, Address: 0x1749fc, Func Offset: 0x2dc
	// Line 432, Address: 0x174a0c, Func Offset: 0x2ec
	// Line 433, Address: 0x174a14, Func Offset: 0x2f4
	// Line 434, Address: 0x174a18, Func Offset: 0x2f8
	// Func End, Address: 0x174a30, Func Offset: 0x310
	scePrintf("bhSetEnemy - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhCheckEneWorkNum()
{
    BH_PWORK* epp;
    int i;

    sys->ewk_n = 0;
    
    epp = ene;

    for (i = 0; i < 128; i++, epp++)
    {
        if ((epp->flg & 0x1))
        {
            sys->ewk_n = i + 1;
        }
    }
}

// 
// Start address: 0x174a90
void bhControlEnemy()
{
	unsigned int i;
	BH_PWORK* ep;
	// Line 539, Address: 0x174a90, Func Offset: 0
	// Line 543, Address: 0x174aa0, Func Offset: 0x10
	// Line 565, Address: 0x174ab8, Func Offset: 0x28
	// Line 566, Address: 0x174ad0, Func Offset: 0x40
	// Line 576, Address: 0x174ad8, Func Offset: 0x48
	// Line 566, Address: 0x174ae0, Func Offset: 0x50
	// Line 577, Address: 0x174ae4, Func Offset: 0x54
	// Line 578, Address: 0x174aec, Func Offset: 0x5c
	// Line 579, Address: 0x174af8, Func Offset: 0x68
	// Line 581, Address: 0x174b34, Func Offset: 0xa4
	// Line 582, Address: 0x174b38, Func Offset: 0xa8
	// Line 584, Address: 0x174b44, Func Offset: 0xb4
	// Line 585, Address: 0x174b4c, Func Offset: 0xbc
	// Line 586, Address: 0x174b54, Func Offset: 0xc4
	// Line 588, Address: 0x174b5c, Func Offset: 0xcc
	// Line 589, Address: 0x174b64, Func Offset: 0xd4
	// Line 590, Address: 0x174b6c, Func Offset: 0xdc
	// Line 592, Address: 0x174b74, Func Offset: 0xe4
	// Line 614, Address: 0x174b90, Func Offset: 0x100
	// Line 616, Address: 0x174bb0, Func Offset: 0x120
	// Line 618, Address: 0x174bb8, Func Offset: 0x128
	// Line 620, Address: 0x174c04, Func Offset: 0x174
	// Line 621, Address: 0x174c30, Func Offset: 0x1a0
	// Func End, Address: 0x174c44, Func Offset: 0x1b4
	scePrintf("bhControlEnemy - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x174c50
void bhEne00(BH_PWORK* ep)
{
	_anon43 pnt;
	int i;
	_anon32 pos;
	_anon17* hp;
	// Line 628, Address: 0x174c50, Func Offset: 0
	// Line 632, Address: 0x174c60, Func Offset: 0x10
	// Line 634, Address: 0x174c8c, Func Offset: 0x3c
	// Line 653, Address: 0x174c90, Func Offset: 0x40
	// Line 640, Address: 0x174c94, Func Offset: 0x44
	// Line 643, Address: 0x174c98, Func Offset: 0x48
	// Line 634, Address: 0x174c9c, Func Offset: 0x4c
	// Line 640, Address: 0x174ca4, Func Offset: 0x54
	// Line 645, Address: 0x174ca8, Func Offset: 0x58
	// Line 646, Address: 0x174cac, Func Offset: 0x5c
	// Line 653, Address: 0x174cb0, Func Offset: 0x60
	// Line 654, Address: 0x174cb4, Func Offset: 0x64
	// Line 640, Address: 0x174cb8, Func Offset: 0x68
	// Line 642, Address: 0x174cc0, Func Offset: 0x70
	// Line 643, Address: 0x174ccc, Func Offset: 0x7c
	// Line 644, Address: 0x174cd8, Func Offset: 0x88
	// Line 645, Address: 0x174ce4, Func Offset: 0x94
	// Line 646, Address: 0x174ce8, Func Offset: 0x98
	// Line 647, Address: 0x174cec, Func Offset: 0x9c
	// Line 648, Address: 0x174cf0, Func Offset: 0xa0
	// Line 649, Address: 0x174cf4, Func Offset: 0xa4
	// Line 650, Address: 0x174cf8, Func Offset: 0xa8
	// Line 651, Address: 0x174cfc, Func Offset: 0xac
	// Line 652, Address: 0x174d00, Func Offset: 0xb0
	// Line 653, Address: 0x174d04, Func Offset: 0xb4
	// Line 654, Address: 0x174d08, Func Offset: 0xb8
	// Line 656, Address: 0x174d18, Func Offset: 0xc8
	// Line 657, Address: 0x174d1c, Func Offset: 0xcc
	// Line 659, Address: 0x174d24, Func Offset: 0xd4
	// Line 660, Address: 0x174d28, Func Offset: 0xd8
	// Line 663, Address: 0x174d2c, Func Offset: 0xdc
	// Line 657, Address: 0x174d30, Func Offset: 0xe0
	// Line 667, Address: 0x174d3c, Func Offset: 0xec
	// Line 680, Address: 0x174d40, Func Offset: 0xf0
	// Line 657, Address: 0x174d48, Func Offset: 0xf8
	// Line 658, Address: 0x174d5c, Func Offset: 0x10c
	// Line 680, Address: 0x174d68, Func Offset: 0x118
	// Line 658, Address: 0x174d70, Func Offset: 0x120
	// Line 659, Address: 0x174d8c, Func Offset: 0x13c
	// Line 660, Address: 0x174d90, Func Offset: 0x140
	// Line 661, Address: 0x174d94, Func Offset: 0x144
	// Line 665, Address: 0x174d98, Func Offset: 0x148
	// Line 661, Address: 0x174d9c, Func Offset: 0x14c
	// Line 663, Address: 0x174da0, Func Offset: 0x150
	// Line 664, Address: 0x174da4, Func Offset: 0x154
	// Line 665, Address: 0x174dac, Func Offset: 0x15c
	// Line 673, Address: 0x174dc0, Func Offset: 0x170
	// Line 665, Address: 0x174dc4, Func Offset: 0x174
	// Line 666, Address: 0x174dc8, Func Offset: 0x178
	// Line 667, Address: 0x174dd0, Func Offset: 0x180
	// Line 668, Address: 0x174dd4, Func Offset: 0x184
	// Line 669, Address: 0x174dd8, Func Offset: 0x188
	// Line 670, Address: 0x174ddc, Func Offset: 0x18c
	// Line 673, Address: 0x174de8, Func Offset: 0x198
	// Line 674, Address: 0x174dfc, Func Offset: 0x1ac
	// Line 675, Address: 0x174e00, Func Offset: 0x1b0
	// Line 676, Address: 0x174e04, Func Offset: 0x1b4
	// Line 677, Address: 0x174e08, Func Offset: 0x1b8
	// Line 678, Address: 0x174e0c, Func Offset: 0x1bc
	// Line 680, Address: 0x174e10, Func Offset: 0x1c0
	// Line 681, Address: 0x174e18, Func Offset: 0x1c8
	// Line 682, Address: 0x174e20, Func Offset: 0x1d0
	// Line 683, Address: 0x174e2c, Func Offset: 0x1dc
	// Line 685, Address: 0x174e30, Func Offset: 0x1e0
	// Line 682, Address: 0x174e34, Func Offset: 0x1e4
	// Line 683, Address: 0x174e50, Func Offset: 0x200
	// Line 685, Address: 0x174e54, Func Offset: 0x204
	// Line 687, Address: 0x174e58, Func Offset: 0x208
	// Line 688, Address: 0x174e5c, Func Offset: 0x20c
	// Line 690, Address: 0x174e64, Func Offset: 0x214
	// Line 691, Address: 0x174e70, Func Offset: 0x220
	// Line 690, Address: 0x174e74, Func Offset: 0x224
	// Line 691, Address: 0x174e8c, Func Offset: 0x23c
	// Line 693, Address: 0x174e98, Func Offset: 0x248
	// Line 698, Address: 0x174ea4, Func Offset: 0x254
	// Line 699, Address: 0x174ea8, Func Offset: 0x258
	// Line 701, Address: 0x174eb0, Func Offset: 0x260
	// Line 698, Address: 0x174eb4, Func Offset: 0x264
	// Line 699, Address: 0x174eb8, Func Offset: 0x268
	// Line 700, Address: 0x174ec4, Func Offset: 0x274
	// Line 701, Address: 0x174ec8, Func Offset: 0x278
	// Line 702, Address: 0x174ed0, Func Offset: 0x280
	// Line 704, Address: 0x174ed4, Func Offset: 0x284
	// Line 709, Address: 0x174ed8, Func Offset: 0x288
	// Line 702, Address: 0x174edc, Func Offset: 0x28c
	// Line 703, Address: 0x174ee4, Func Offset: 0x294
	// Line 704, Address: 0x174ef0, Func Offset: 0x2a0
	// Line 708, Address: 0x174efc, Func Offset: 0x2ac
	// Line 709, Address: 0x174f08, Func Offset: 0x2b8
	// Line 713, Address: 0x174f0c, Func Offset: 0x2bc
	// Line 714, Address: 0x174f14, Func Offset: 0x2c4
	// Line 715, Address: 0x174f1c, Func Offset: 0x2cc
	// Line 721, Address: 0x174f24, Func Offset: 0x2d4
	// Line 722, Address: 0x174f34, Func Offset: 0x2e4
	// Line 723, Address: 0x174f5c, Func Offset: 0x30c
	// Line 726, Address: 0x174f6c, Func Offset: 0x31c
	// Line 727, Address: 0x174f84, Func Offset: 0x334
	// Line 728, Address: 0x174f9c, Func Offset: 0x34c
	// Line 730, Address: 0x174fb4, Func Offset: 0x364
	// Line 732, Address: 0x174fc0, Func Offset: 0x370
	// Line 736, Address: 0x174fc4, Func Offset: 0x374
	// Line 732, Address: 0x174fcc, Func Offset: 0x37c
	// Line 733, Address: 0x174fd8, Func Offset: 0x388
	// Line 734, Address: 0x174fe8, Func Offset: 0x398
	// Line 735, Address: 0x174ff8, Func Offset: 0x3a8
	// Line 736, Address: 0x175000, Func Offset: 0x3b0
	// Line 737, Address: 0x17500c, Func Offset: 0x3bc
	// Line 738, Address: 0x175014, Func Offset: 0x3c4
	// Line 739, Address: 0x17501c, Func Offset: 0x3cc
	// Func End, Address: 0x175030, Func Offset: 0x3e0
}

// 
// Start address: 0x175030
void bhEne56(BH_PWORK* ep)
{
	_anon32 pos;
	_anon0* op;
	// Line 746, Address: 0x175030, Func Offset: 0
	// Line 749, Address: 0x175040, Func Offset: 0x10
	// Line 750, Address: 0x175044, Func Offset: 0x14
	// Line 749, Address: 0x175048, Func Offset: 0x18
	// Line 750, Address: 0x175050, Func Offset: 0x20
	// Line 752, Address: 0x175078, Func Offset: 0x48
	// Line 753, Address: 0x17507c, Func Offset: 0x4c
	// Line 757, Address: 0x175080, Func Offset: 0x50
	// Line 761, Address: 0x175084, Func Offset: 0x54
	// Line 762, Address: 0x175088, Func Offset: 0x58
	// Line 752, Address: 0x17508c, Func Offset: 0x5c
	// Line 753, Address: 0x175094, Func Offset: 0x64
	// Line 754, Address: 0x1750a8, Func Offset: 0x78
	// Line 755, Address: 0x1750ac, Func Offset: 0x7c
	// Line 756, Address: 0x1750b0, Func Offset: 0x80
	// Line 757, Address: 0x1750b4, Func Offset: 0x84
	// Line 758, Address: 0x1750b8, Func Offset: 0x88
	// Line 759, Address: 0x1750bc, Func Offset: 0x8c
	// Line 760, Address: 0x1750c0, Func Offset: 0x90
	// Line 761, Address: 0x1750c4, Func Offset: 0x94
	// Line 762, Address: 0x1750d8, Func Offset: 0xa8
	// Line 763, Address: 0x1750f0, Func Offset: 0xc0
	// Line 765, Address: 0x1750f8, Func Offset: 0xc8
	// Line 763, Address: 0x1750fc, Func Offset: 0xcc
	// Line 765, Address: 0x175100, Func Offset: 0xd0
	// Line 764, Address: 0x175104, Func Offset: 0xd4
	// Line 763, Address: 0x175108, Func Offset: 0xd8
	// Line 764, Address: 0x175118, Func Offset: 0xe8
	// Line 765, Address: 0x175130, Func Offset: 0x100
	// Line 766, Address: 0x175144, Func Offset: 0x114
	// Line 767, Address: 0x17514c, Func Offset: 0x11c
	// Line 768, Address: 0x175158, Func Offset: 0x128
	// Line 769, Address: 0x17515c, Func Offset: 0x12c
	// Line 767, Address: 0x175160, Func Offset: 0x130
	// Line 768, Address: 0x175170, Func Offset: 0x140
	// Line 769, Address: 0x175188, Func Offset: 0x158
	// Line 772, Address: 0x1751a0, Func Offset: 0x170
	// Line 773, Address: 0x1751b0, Func Offset: 0x180
	// Line 774, Address: 0x1751d8, Func Offset: 0x1a8
	// Line 776, Address: 0x1751e4, Func Offset: 0x1b4
	// Line 777, Address: 0x175200, Func Offset: 0x1d0
	// Line 781, Address: 0x175208, Func Offset: 0x1d8
	// Line 784, Address: 0x17520c, Func Offset: 0x1dc
	// Line 777, Address: 0x175210, Func Offset: 0x1e0
	// Line 778, Address: 0x175240, Func Offset: 0x210
	// Line 779, Address: 0x17524c, Func Offset: 0x21c
	// Line 780, Address: 0x175250, Func Offset: 0x220
	// Line 781, Address: 0x175254, Func Offset: 0x224
	// Line 782, Address: 0x175258, Func Offset: 0x228
	// Line 783, Address: 0x17525c, Func Offset: 0x22c
	// Line 785, Address: 0x175260, Func Offset: 0x230
	// Line 787, Address: 0x175268, Func Offset: 0x238
	// Line 790, Address: 0x175270, Func Offset: 0x240
	// Line 793, Address: 0x175278, Func Offset: 0x248
	// Line 790, Address: 0x17527c, Func Offset: 0x24c
	// Line 791, Address: 0x17528c, Func Offset: 0x25c
	// Line 792, Address: 0x1752a4, Func Offset: 0x274
	// Line 793, Address: 0x1752bc, Func Offset: 0x28c
	// Line 794, Address: 0x1752cc, Func Offset: 0x29c
	// Line 795, Address: 0x1752d4, Func Offset: 0x2a4
	// Line 797, Address: 0x175310, Func Offset: 0x2e0
	// Line 798, Address: 0x175324, Func Offset: 0x2f4
	// Line 799, Address: 0x175328, Func Offset: 0x2f8
	// Line 801, Address: 0x175330, Func Offset: 0x300
	// Line 803, Address: 0x175334, Func Offset: 0x304
	// Line 805, Address: 0x17533c, Func Offset: 0x30c
	// Line 807, Address: 0x17535c, Func Offset: 0x32c
	// Line 809, Address: 0x175364, Func Offset: 0x334
	// Line 810, Address: 0x175368, Func Offset: 0x338
	// Line 809, Address: 0x175374, Func Offset: 0x344
	// Line 811, Address: 0x17537c, Func Offset: 0x34c
	// Line 812, Address: 0x175388, Func Offset: 0x358
	// Line 809, Address: 0x17538c, Func Offset: 0x35c
	// Line 812, Address: 0x175398, Func Offset: 0x368
	// Line 809, Address: 0x1753a8, Func Offset: 0x378
	// Line 810, Address: 0x1753b4, Func Offset: 0x384
	// Line 811, Address: 0x1753c0, Func Offset: 0x390
	// Line 812, Address: 0x1753c8, Func Offset: 0x398
	// Line 813, Address: 0x1753d8, Func Offset: 0x3a8
	// Line 814, Address: 0x1753ec, Func Offset: 0x3bc
	// Line 816, Address: 0x1753f4, Func Offset: 0x3c4
	// Line 817, Address: 0x1753f8, Func Offset: 0x3c8
	// Line 816, Address: 0x175404, Func Offset: 0x3d4
	// Line 818, Address: 0x17540c, Func Offset: 0x3dc
	// Line 819, Address: 0x175414, Func Offset: 0x3e4
	// Line 816, Address: 0x175420, Func Offset: 0x3f0
	// Line 819, Address: 0x17542c, Func Offset: 0x3fc
	// Line 816, Address: 0x175434, Func Offset: 0x404
	// Line 817, Address: 0x175440, Func Offset: 0x410
	// Line 818, Address: 0x17544c, Func Offset: 0x41c
	// Line 819, Address: 0x175454, Func Offset: 0x424
	// Line 820, Address: 0x175464, Func Offset: 0x434
	// Line 821, Address: 0x175478, Func Offset: 0x448
	// Line 823, Address: 0x175480, Func Offset: 0x450
	// Line 824, Address: 0x175484, Func Offset: 0x454
	// Line 823, Address: 0x175490, Func Offset: 0x460
	// Line 825, Address: 0x175498, Func Offset: 0x468
	// Line 826, Address: 0x1754a0, Func Offset: 0x470
	// Line 823, Address: 0x1754ac, Func Offset: 0x47c
	// Line 826, Address: 0x1754b8, Func Offset: 0x488
	// Line 823, Address: 0x1754c0, Func Offset: 0x490
	// Line 824, Address: 0x1754cc, Func Offset: 0x49c
	// Line 825, Address: 0x1754d8, Func Offset: 0x4a8
	// Line 826, Address: 0x1754e0, Func Offset: 0x4b0
	// Line 827, Address: 0x1754f0, Func Offset: 0x4c0
	// Line 828, Address: 0x175504, Func Offset: 0x4d4
	// Line 830, Address: 0x17550c, Func Offset: 0x4dc
	// Line 831, Address: 0x175510, Func Offset: 0x4e0
	// Line 830, Address: 0x17551c, Func Offset: 0x4ec
	// Line 832, Address: 0x175524, Func Offset: 0x4f4
	// Line 833, Address: 0x17552c, Func Offset: 0x4fc
	// Line 830, Address: 0x175538, Func Offset: 0x508
	// Line 833, Address: 0x175544, Func Offset: 0x514
	// Line 830, Address: 0x17554c, Func Offset: 0x51c
	// Line 831, Address: 0x175558, Func Offset: 0x528
	// Line 832, Address: 0x175564, Func Offset: 0x534
	// Line 833, Address: 0x17556c, Func Offset: 0x53c
	// Line 834, Address: 0x17557c, Func Offset: 0x54c
	// Line 835, Address: 0x175590, Func Offset: 0x560
	// Line 841, Address: 0x175598, Func Offset: 0x568
	// Line 842, Address: 0x1755b8, Func Offset: 0x588
	// Line 843, Address: 0x1755bc, Func Offset: 0x58c
	// Line 844, Address: 0x1755d8, Func Offset: 0x5a8
	// Line 845, Address: 0x175634, Func Offset: 0x604
	// Line 848, Address: 0x175638, Func Offset: 0x608
	// Line 850, Address: 0x175640, Func Offset: 0x610
	// Line 851, Address: 0x175658, Func Offset: 0x628
	// Line 850, Address: 0x175660, Func Offset: 0x630
	// Line 851, Address: 0x175668, Func Offset: 0x638
	// Line 850, Address: 0x17566c, Func Offset: 0x63c
	// Line 851, Address: 0x175678, Func Offset: 0x648
	// Line 852, Address: 0x175680, Func Offset: 0x650
	// Line 853, Address: 0x175690, Func Offset: 0x660
	// Line 854, Address: 0x175698, Func Offset: 0x668
	// Line 855, Address: 0x17569c, Func Offset: 0x66c
	// Line 856, Address: 0x1756a0, Func Offset: 0x670
	// Line 857, Address: 0x1756b0, Func Offset: 0x680
	// Line 858, Address: 0x1756c0, Func Offset: 0x690
	// Line 860, Address: 0x1756c4, Func Offset: 0x694
	// Line 861, Address: 0x175704, Func Offset: 0x6d4
	// Line 867, Address: 0x17570c, Func Offset: 0x6dc
	// Line 861, Address: 0x175714, Func Offset: 0x6e4
	// Line 862, Address: 0x17571c, Func Offset: 0x6ec
	// Line 863, Address: 0x17572c, Func Offset: 0x6fc
	// Line 864, Address: 0x17573c, Func Offset: 0x70c
	// Line 865, Address: 0x17574c, Func Offset: 0x71c
	// Line 866, Address: 0x175750, Func Offset: 0x720
	// Line 867, Address: 0x175754, Func Offset: 0x724
	// Line 870, Address: 0x175760, Func Offset: 0x730
	// Line 872, Address: 0x175768, Func Offset: 0x738
	// Line 873, Address: 0x175774, Func Offset: 0x744
	// Line 872, Address: 0x175778, Func Offset: 0x748
	// Line 873, Address: 0x17579c, Func Offset: 0x76c
	// Line 875, Address: 0x1757c4, Func Offset: 0x794
	// Line 876, Address: 0x1757cc, Func Offset: 0x79c
	// Line 875, Address: 0x1757d8, Func Offset: 0x7a8
	// Line 876, Address: 0x1757e0, Func Offset: 0x7b0
	// Line 877, Address: 0x17580c, Func Offset: 0x7dc
	// Line 878, Address: 0x175828, Func Offset: 0x7f8
	// Line 879, Address: 0x175830, Func Offset: 0x800
	// Line 880, Address: 0x175838, Func Offset: 0x808
	// Line 882, Address: 0x175848, Func Offset: 0x818
	// Line 884, Address: 0x175850, Func Offset: 0x820
	// Line 885, Address: 0x175868, Func Offset: 0x838
	// Line 886, Address: 0x175870, Func Offset: 0x840
	// Line 884, Address: 0x175878, Func Offset: 0x848
	// Line 885, Address: 0x17588c, Func Offset: 0x85c
	// Line 886, Address: 0x175894, Func Offset: 0x864
	// Line 885, Address: 0x17589c, Func Offset: 0x86c
	// Line 886, Address: 0x1758a0, Func Offset: 0x870
	// Line 887, Address: 0x1758b0, Func Offset: 0x880
	// Line 888, Address: 0x1758b8, Func Offset: 0x888
	// Line 897, Address: 0x1758bc, Func Offset: 0x88c
	// Line 899, Address: 0x1758c4, Func Offset: 0x894
	// Line 900, Address: 0x1758cc, Func Offset: 0x89c
	// Line 901, Address: 0x1758dc, Func Offset: 0x8ac
	// Line 932, Address: 0x1758e4, Func Offset: 0x8b4
	// Func End, Address: 0x1758f8, Func Offset: 0x8c8
}*/

// 
// Start address: 0x175900
void bhDrawEnemy()
{
	unsigned int argb;
	int i;
	BH_PWORK* ep;
	// Line 938, Address: 0x175900, Func Offset: 0
	// Line 955, Address: 0x175910, Func Offset: 0x10
	// Line 956, Address: 0x175918, Func Offset: 0x18
	// Line 957, Address: 0x175920, Func Offset: 0x20
	// Line 1008, Address: 0x175940, Func Offset: 0x40
	// Line 1011, Address: 0x17599c, Func Offset: 0x9c
	// Line 1022, Address: 0x1759a0, Func Offset: 0xa0
	// Line 1024, Address: 0x1759b8, Func Offset: 0xb8
	// Line 1025, Address: 0x1759c8, Func Offset: 0xc8
	// Line 1028, Address: 0x1759d8, Func Offset: 0xd8
	// Line 1034, Address: 0x1759f8, Func Offset: 0xf8
	// Line 1035, Address: 0x175a10, Func Offset: 0x110
	// Line 1036, Address: 0x175a18, Func Offset: 0x118
	// Line 1038, Address: 0x175a20, Func Offset: 0x120
	// Line 1039, Address: 0x175a38, Func Offset: 0x138
	// Line 1042, Address: 0x175a44, Func Offset: 0x144
	// Line 1044, Address: 0x175a4c, Func Offset: 0x14c
	// Line 1045, Address: 0x175aa0, Func Offset: 0x1a0
	// Line 1046, Address: 0x175aa8, Func Offset: 0x1a8
	// Line 1048, Address: 0x175abc, Func Offset: 0x1bc
	// Line 1049, Address: 0x175ac0, Func Offset: 0x1c0
	// Line 1051, Address: 0x175ad0, Func Offset: 0x1d0
	// Line 1052, Address: 0x175ae0, Func Offset: 0x1e0
	// Line 1056, Address: 0x175af8, Func Offset: 0x1f8
	// Line 1057, Address: 0x175b00, Func Offset: 0x200
	// Line 1058, Address: 0x175b0c, Func Offset: 0x20c
	// Line 1059, Address: 0x175b1c, Func Offset: 0x21c
	// Line 1061, Address: 0x175b24, Func Offset: 0x224
	// Line 1065, Address: 0x175b30, Func Offset: 0x230
	// Line 1066, Address: 0x175b58, Func Offset: 0x258
	// Func End, Address: 0x175b6c, Func Offset: 0x26c
	scePrintf("bhDrawEnemy - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x175b70
void bhDrawEneObject()
{
	int i;
	BH_PWORK* ep;
	// Line 1072, Address: 0x175b70, Func Offset: 0
	// Line 1089, Address: 0x175b84, Func Offset: 0x14
	// Line 1090, Address: 0x175b90, Func Offset: 0x20
	// Line 1091, Address: 0x175ba0, Func Offset: 0x30
	// Line 1092, Address: 0x175bb0, Func Offset: 0x40
	// Line 1103, Address: 0x175bc4, Func Offset: 0x54
	// Line 1105, Address: 0x175be0, Func Offset: 0x70
	// Line 1106, Address: 0x175bf0, Func Offset: 0x80
	// Line 1108, Address: 0x175c00, Func Offset: 0x90
	// Line 1113, Address: 0x175c20, Func Offset: 0xb0
	// Line 1115, Address: 0x175c2c, Func Offset: 0xbc
	// Line 1116, Address: 0x175c38, Func Offset: 0xc8
	// Line 1120, Address: 0x175c50, Func Offset: 0xe0
	// Line 1121, Address: 0x175c58, Func Offset: 0xe8
	// Line 1122, Address: 0x175c64, Func Offset: 0xf4
	// Line 1123, Address: 0x175c74, Func Offset: 0x104
	// Line 1124, Address: 0x175c7c, Func Offset: 0x10c
	// Line 1128, Address: 0x175c8c, Func Offset: 0x11c
	// Line 1129, Address: 0x175cb0, Func Offset: 0x140
	// Func End, Address: 0x175cc8, Func Offset: 0x158
	scePrintf("bhDrawEneObject - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x175cd0
void* bhEne_CallocWork(int size)
{
	unsigned char* addr;
	unsigned char* ret_addr;
	// Line 1205, Address: 0x175cd0, Func Offset: 0
	// Line 1207, Address: 0x175d10, Func Offset: 0x40
	// Line 1210, Address: 0x175d18, Func Offset: 0x48
	// Line 1211, Address: 0x175d28, Func Offset: 0x58
	// Line 1215, Address: 0x175d30, Func Offset: 0x60
	// Line 1211, Address: 0x175d34, Func Offset: 0x64
	// Line 1212, Address: 0x175d44, Func Offset: 0x74
	// Line 1215, Address: 0x175d4c, Func Offset: 0x7c
	// Line 1217, Address: 0x175d58, Func Offset: 0x88
	// Line 1218, Address: 0x175d5c, Func Offset: 0x8c
	// Line 1217, Address: 0x175d60, Func Offset: 0x90
	// Line 1218, Address: 0x175d64, Func Offset: 0x94
	// Line 1220, Address: 0x175d78, Func Offset: 0xa8
	// Func End, Address: 0x175d80, Func Offset: 0xb0
}

// 
// Start address: 0x175d80
void bhEne_SetCallFunc(void(*func)(BH_PWORK*), unsigned int no)
{
	// Line 1231, Address: 0x175d80, Func Offset: 0
	// Line 1232, Address: 0x175d90, Func Offset: 0x10
	// Func End, Address: 0x175d98, Func Offset: 0x18
}*/

