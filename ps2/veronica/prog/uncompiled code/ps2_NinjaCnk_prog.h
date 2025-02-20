



tagCHUNK_HEAD* njCnkCsUvh(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCsUvn(tagCHUNK_HEAD* pCnk);

// 
// Start address: 0x2d25a0
tagCHUNK_HEAD* njCnkCsUvh(tagCHUNK_HEAD* pCnk)
{
	unsigned int cflag;
	float zbuff[4];
	unsigned int coflag;
	_anon17* timp;
	unsigned long vu1func_tag;
	unsigned long ulVuflag;
	unsigned long* ulpP;
	int sExit;
	void(*pVu1Func)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
	unsigned short usColorCalc;
	unsigned short usClip;
	unsigned short usNum;
	unsigned short usMax;
	unsigned short usCnt;
	unsigned short usStrip;
	unsigned short usNext;
	tagVU1_STRIP_BUF* pSorg;
	tagVU1_STRIP_BUF* pS;
	tagVU1_STRIP_BUF* pV;
	unsigned short* uspCnk;
	unsigned long ulType2;
	unsigned long ulType;
	unsigned char ucFlag;
	// Line 19, Address: 0x2d25a0, Func Offset: 0
	// Line 21, Address: 0x2d25bc, Func Offset: 0x1c
	// Line 19, Address: 0x2d25c0, Func Offset: 0x20
	// Line 21, Address: 0x2d25c8, Func Offset: 0x28
	// Line 19, Address: 0x2d25d0, Func Offset: 0x30
	// Line 22, Address: 0x2d25d4, Func Offset: 0x34
	// Line 19, Address: 0x2d25d8, Func Offset: 0x38
	// Line 22, Address: 0x2d25dc, Func Offset: 0x3c
	// Line 35, Address: 0x2d25e0, Func Offset: 0x40
	// Line 36, Address: 0x2d25fc, Func Offset: 0x5c
	// Line 40, Address: 0x2d2604, Func Offset: 0x64
	// Line 41, Address: 0x2d2614, Func Offset: 0x74
	// Line 42, Address: 0x2d2620, Func Offset: 0x80
	// Line 41, Address: 0x2d2624, Func Offset: 0x84
	// Line 48, Address: 0x2d262c, Func Offset: 0x8c
	// Line 49, Address: 0x2d263c, Func Offset: 0x9c
	// Line 50, Address: 0x2d2648, Func Offset: 0xa8
	// Line 49, Address: 0x2d264c, Func Offset: 0xac
	// Line 55, Address: 0x2d2654, Func Offset: 0xb4
	// Line 57, Address: 0x2d2664, Func Offset: 0xc4
	// Line 58, Address: 0x2d2670, Func Offset: 0xd0
	// Line 59, Address: 0x2d267c, Func Offset: 0xdc
	// Line 60, Address: 0x2d2680, Func Offset: 0xe0
	// Line 63, Address: 0x2d2688, Func Offset: 0xe8
	// Line 64, Address: 0x2d2698, Func Offset: 0xf8
	// Line 65, Address: 0x2d26a8, Func Offset: 0x108
	// Line 66, Address: 0x2d26b8, Func Offset: 0x118
	// Line 67, Address: 0x2d26c4, Func Offset: 0x124
	// Line 72, Address: 0x2d26e4, Func Offset: 0x144
	// Line 78, Address: 0x2d26f8, Func Offset: 0x158
	// Line 76, Address: 0x2d26fc, Func Offset: 0x15c
	// Line 72, Address: 0x2d2700, Func Offset: 0x160
	// Line 86, Address: 0x2d2710, Func Offset: 0x170
	// Line 72, Address: 0x2d2714, Func Offset: 0x174
	// Line 86, Address: 0x2d2718, Func Offset: 0x178
	// Line 79, Address: 0x2d271c, Func Offset: 0x17c
	// Line 78, Address: 0x2d2720, Func Offset: 0x180
	// Line 86, Address: 0x2d2724, Func Offset: 0x184
	// Line 87, Address: 0x2d272c, Func Offset: 0x18c
	// Line 97, Address: 0x2d2754, Func Offset: 0x1b4
	// Line 99, Address: 0x2d277c, Func Offset: 0x1dc
	// Line 100, Address: 0x2d2780, Func Offset: 0x1e0
	// Line 101, Address: 0x2d2788, Func Offset: 0x1e8
	// Line 104, Address: 0x2d278c, Func Offset: 0x1ec
	// Line 105, Address: 0x2d2798, Func Offset: 0x1f8
	// Line 106, Address: 0x2d27a4, Func Offset: 0x204
	// Line 107, Address: 0x2d27ac, Func Offset: 0x20c
	// Line 108, Address: 0x2d27b4, Func Offset: 0x214
	// Line 112, Address: 0x2d27bc, Func Offset: 0x21c
	// Line 113, Address: 0x2d27c4, Func Offset: 0x224
	// Line 115, Address: 0x2d27cc, Func Offset: 0x22c
	// Line 114, Address: 0x2d27dc, Func Offset: 0x23c
	// Line 115, Address: 0x2d27e0, Func Offset: 0x240
	// Line 116, Address: 0x2d27e8, Func Offset: 0x248
	// Line 117, Address: 0x2d27f8, Func Offset: 0x258
	// Line 120, Address: 0x2d2804, Func Offset: 0x264
	// Line 118, Address: 0x2d2808, Func Offset: 0x268
	// Line 117, Address: 0x2d2810, Func Offset: 0x270
	// Line 118, Address: 0x2d2814, Func Offset: 0x274
	// Line 119, Address: 0x2d2818, Func Offset: 0x278
	// Line 124, Address: 0x2d2820, Func Offset: 0x280
	// Line 118, Address: 0x2d2824, Func Offset: 0x284
	// Line 119, Address: 0x2d2828, Func Offset: 0x288
	// Line 124, Address: 0x2d282c, Func Offset: 0x28c
	// Line 125, Address: 0x2d2830, Func Offset: 0x290
	// Line 119, Address: 0x2d2838, Func Offset: 0x298
	// Line 120, Address: 0x2d283c, Func Offset: 0x29c
	// Line 126, Address: 0x2d2840, Func Offset: 0x2a0
	// Line 127, Address: 0x2d2848, Func Offset: 0x2a8
	// Line 120, Address: 0x2d2850, Func Offset: 0x2b0
	// Line 121, Address: 0x2d2854, Func Offset: 0x2b4
	// Line 131, Address: 0x2d285c, Func Offset: 0x2bc
	// Line 135, Address: 0x2d2864, Func Offset: 0x2c4
	// Line 136, Address: 0x2d286c, Func Offset: 0x2cc
	// Line 121, Address: 0x2d2870, Func Offset: 0x2d0
	// Line 122, Address: 0x2d2874, Func Offset: 0x2d4
	// Line 136, Address: 0x2d287c, Func Offset: 0x2dc
	// Line 137, Address: 0x2d2880, Func Offset: 0x2e0
	// Line 122, Address: 0x2d2888, Func Offset: 0x2e8
	// Line 123, Address: 0x2d288c, Func Offset: 0x2ec
	// Line 138, Address: 0x2d2894, Func Offset: 0x2f4
	// Line 139, Address: 0x2d289c, Func Offset: 0x2fc
	// Line 141, Address: 0x2d28a0, Func Offset: 0x300
	// Line 123, Address: 0x2d28a4, Func Offset: 0x304
	// Line 124, Address: 0x2d28a8, Func Offset: 0x308
	// Line 141, Address: 0x2d28ac, Func Offset: 0x30c
	// Line 124, Address: 0x2d28c0, Func Offset: 0x320
	// Line 125, Address: 0x2d28c4, Func Offset: 0x324
	// Line 144, Address: 0x2d28c8, Func Offset: 0x328
	// Line 128, Address: 0x2d28d0, Func Offset: 0x330
	// Line 139, Address: 0x2d28d4, Func Offset: 0x334
	// Line 125, Address: 0x2d28d8, Func Offset: 0x338
	// Line 126, Address: 0x2d28dc, Func Offset: 0x33c
	// Line 142, Address: 0x2d28e0, Func Offset: 0x340
	// Line 144, Address: 0x2d28e4, Func Offset: 0x344
	// Line 126, Address: 0x2d28ec, Func Offset: 0x34c
	// Line 127, Address: 0x2d28f0, Func Offset: 0x350
	// Line 128, Address: 0x2d28f8, Func Offset: 0x358
	// Line 129, Address: 0x2d2900, Func Offset: 0x360
	// Line 130, Address: 0x2d290c, Func Offset: 0x36c
	// Line 131, Address: 0x2d2910, Func Offset: 0x370
	// Line 132, Address: 0x2d2914, Func Offset: 0x374
	// Line 133, Address: 0x2d2920, Func Offset: 0x380
	// Line 134, Address: 0x2d292c, Func Offset: 0x38c
	// Line 135, Address: 0x2d2930, Func Offset: 0x390
	// Line 136, Address: 0x2d2934, Func Offset: 0x394
	// Line 137, Address: 0x2d293c, Func Offset: 0x39c
	// Line 138, Address: 0x2d2944, Func Offset: 0x3a4
	// Line 139, Address: 0x2d294c, Func Offset: 0x3ac
	// Line 141, Address: 0x2d2954, Func Offset: 0x3b4
	// Line 144, Address: 0x2d2958, Func Offset: 0x3b8
	// Line 145, Address: 0x2d2960, Func Offset: 0x3c0
	// Line 148, Address: 0x2d2974, Func Offset: 0x3d4
	// Line 151, Address: 0x2d297c, Func Offset: 0x3dc
	// Line 152, Address: 0x2d2988, Func Offset: 0x3e8
	// Line 153, Address: 0x2d29a0, Func Offset: 0x400
	// Line 152, Address: 0x2d29a4, Func Offset: 0x404
	// Line 155, Address: 0x2d29a8, Func Offset: 0x408
	// Line 156, Address: 0x2d29ac, Func Offset: 0x40c
	// Line 161, Address: 0x2d29b0, Func Offset: 0x410
	// Line 167, Address: 0x2d29d8, Func Offset: 0x438
	// Line 168, Address: 0x2d29e8, Func Offset: 0x448
	// Line 170, Address: 0x2d29f0, Func Offset: 0x450
	// Line 171, Address: 0x2d29f8, Func Offset: 0x458
	// Line 173, Address: 0x2d29fc, Func Offset: 0x45c
	// Line 175, Address: 0x2d2a00, Func Offset: 0x460
	// Line 178, Address: 0x2d2a0c, Func Offset: 0x46c
	// Line 175, Address: 0x2d2a14, Func Offset: 0x474
	// Line 178, Address: 0x2d2a28, Func Offset: 0x488
	// Line 176, Address: 0x2d2a38, Func Offset: 0x498
	// Line 178, Address: 0x2d2a3c, Func Offset: 0x49c
	// Line 177, Address: 0x2d2a40, Func Offset: 0x4a0
	// Line 178, Address: 0x2d2a44, Func Offset: 0x4a4
	// Line 179, Address: 0x2d2a4c, Func Offset: 0x4ac
	// Line 183, Address: 0x2d2a64, Func Offset: 0x4c4
	// Line 179, Address: 0x2d2a68, Func Offset: 0x4c8
	// Line 180, Address: 0x2d2a7c, Func Offset: 0x4dc
	// Line 183, Address: 0x2d2a84, Func Offset: 0x4e4
	// Line 185, Address: 0x2d2a8c, Func Offset: 0x4ec
	// Line 186, Address: 0x2d2a90, Func Offset: 0x4f0
	// Line 187, Address: 0x2d2a94, Func Offset: 0x4f4
	// Line 188, Address: 0x2d2a98, Func Offset: 0x4f8
	// Line 189, Address: 0x2d2a9c, Func Offset: 0x4fc
	// Line 190, Address: 0x2d2aa0, Func Offset: 0x500
	// Line 191, Address: 0x2d2aa4, Func Offset: 0x504
	// Line 193, Address: 0x2d2aa8, Func Offset: 0x508
	// Line 194, Address: 0x2d2aac, Func Offset: 0x50c
	// Line 195, Address: 0x2d2ab0, Func Offset: 0x510
	// Line 196, Address: 0x2d2ab4, Func Offset: 0x514
	// Line 198, Address: 0x2d2ab8, Func Offset: 0x518
	// Line 199, Address: 0x2d2abc, Func Offset: 0x51c
	// Line 200, Address: 0x2d2ac0, Func Offset: 0x520
	// Line 201, Address: 0x2d2ac4, Func Offset: 0x524
	// Line 202, Address: 0x2d2ac8, Func Offset: 0x528
	// Line 204, Address: 0x2d2ad0, Func Offset: 0x530
	// Line 206, Address: 0x2d2ad4, Func Offset: 0x534
	// Line 207, Address: 0x2d2ad8, Func Offset: 0x538
	// Line 208, Address: 0x2d2adc, Func Offset: 0x53c
	// Line 209, Address: 0x2d2ae0, Func Offset: 0x540
	// Line 210, Address: 0x2d2ae4, Func Offset: 0x544
	// Line 211, Address: 0x2d2ae8, Func Offset: 0x548
	// Line 212, Address: 0x2d2aec, Func Offset: 0x54c
	// Line 214, Address: 0x2d2af0, Func Offset: 0x550
	// Line 217, Address: 0x2d2af8, Func Offset: 0x558
	// Line 218, Address: 0x2d2afc, Func Offset: 0x55c
	// Line 219, Address: 0x2d2b00, Func Offset: 0x560
	// Line 220, Address: 0x2d2b04, Func Offset: 0x564
	// Line 221, Address: 0x2d2b08, Func Offset: 0x568
	// Line 222, Address: 0x2d2b0c, Func Offset: 0x56c
	// Line 223, Address: 0x2d2b10, Func Offset: 0x570
	// Line 224, Address: 0x2d2b14, Func Offset: 0x574
	// Line 227, Address: 0x2d2b18, Func Offset: 0x578
	// Line 231, Address: 0x2d2b20, Func Offset: 0x580
	// Line 233, Address: 0x2d2b30, Func Offset: 0x590
	// Line 239, Address: 0x2d2b38, Func Offset: 0x598
	// Line 242, Address: 0x2d2b6c, Func Offset: 0x5cc
	// Line 249, Address: 0x2d2b70, Func Offset: 0x5d0
	// Line 251, Address: 0x2d2b84, Func Offset: 0x5e4
	// Line 252, Address: 0x2d2b88, Func Offset: 0x5e8
	// Line 253, Address: 0x2d2b8c, Func Offset: 0x5ec
	// Line 257, Address: 0x2d2b90, Func Offset: 0x5f0
	// Line 258, Address: 0x2d2b94, Func Offset: 0x5f4
	// Line 259, Address: 0x2d2b98, Func Offset: 0x5f8
	// Line 260, Address: 0x2d2b9c, Func Offset: 0x5fc
	// Line 261, Address: 0x2d2ba0, Func Offset: 0x600
	// Line 262, Address: 0x2d2ba4, Func Offset: 0x604
	// Line 263, Address: 0x2d2ba8, Func Offset: 0x608
	// Line 264, Address: 0x2d2bac, Func Offset: 0x60c
	// Line 265, Address: 0x2d2bb0, Func Offset: 0x610
	// Line 266, Address: 0x2d2bb4, Func Offset: 0x614
	// Line 267, Address: 0x2d2bb8, Func Offset: 0x618
	// Line 268, Address: 0x2d2bbc, Func Offset: 0x61c
	// Line 270, Address: 0x2d2bc0, Func Offset: 0x620
	// Line 271, Address: 0x2d2bc4, Func Offset: 0x624
	// Line 272, Address: 0x2d2bc8, Func Offset: 0x628
	// Line 273, Address: 0x2d2bcc, Func Offset: 0x62c
	// Line 274, Address: 0x2d2bd0, Func Offset: 0x630
	// Line 276, Address: 0x2d2bd4, Func Offset: 0x634
	// Line 278, Address: 0x2d2bd8, Func Offset: 0x638
	// Line 279, Address: 0x2d2bdc, Func Offset: 0x63c
	// Line 281, Address: 0x2d2be0, Func Offset: 0x640
	// Line 282, Address: 0x2d2be4, Func Offset: 0x644
	// Line 283, Address: 0x2d2be8, Func Offset: 0x648
	// Line 285, Address: 0x2d2bec, Func Offset: 0x64c
	// Line 287, Address: 0x2d2bf0, Func Offset: 0x650
	// Line 288, Address: 0x2d2bf4, Func Offset: 0x654
	// Line 289, Address: 0x2d2bf8, Func Offset: 0x658
	// Line 290, Address: 0x2d2bfc, Func Offset: 0x65c
	// Line 292, Address: 0x2d2c00, Func Offset: 0x660
	// Line 294, Address: 0x2d2c04, Func Offset: 0x664
	// Line 296, Address: 0x2d2c08, Func Offset: 0x668
	// Line 297, Address: 0x2d2c0c, Func Offset: 0x66c
	// Line 298, Address: 0x2d2c10, Func Offset: 0x670
	// Line 299, Address: 0x2d2c14, Func Offset: 0x674
	// Line 300, Address: 0x2d2c18, Func Offset: 0x678
	// Line 301, Address: 0x2d2c1c, Func Offset: 0x67c
	// Line 303, Address: 0x2d2c20, Func Offset: 0x680
	// Line 309, Address: 0x2d2c28, Func Offset: 0x688
	// Line 310, Address: 0x2d2c3c, Func Offset: 0x69c
	// Line 325, Address: 0x2d2c44, Func Offset: 0x6a4
	// Line 314, Address: 0x2d2c50, Func Offset: 0x6b0
	// Line 325, Address: 0x2d2c54, Func Offset: 0x6b4
	// Line 326, Address: 0x2d2c60, Func Offset: 0x6c0
	// Line 327, Address: 0x2d2c74, Func Offset: 0x6d4
	// Line 328, Address: 0x2d2c78, Func Offset: 0x6d8
	// Line 330, Address: 0x2d2c80, Func Offset: 0x6e0
	// Line 336, Address: 0x2d2c88, Func Offset: 0x6e8
	// Line 338, Address: 0x2d2c98, Func Offset: 0x6f8
	// Line 344, Address: 0x2d2ca0, Func Offset: 0x700
	// Line 356, Address: 0x2d2ca8, Func Offset: 0x708
	// Line 354, Address: 0x2d2cac, Func Offset: 0x70c
	// Line 356, Address: 0x2d2cb4, Func Offset: 0x714
	// Line 357, Address: 0x2d2cbc, Func Offset: 0x71c
	// Line 358, Address: 0x2d2cd8, Func Offset: 0x738
	// Line 357, Address: 0x2d2cdc, Func Offset: 0x73c
	// Line 360, Address: 0x2d2ce0, Func Offset: 0x740
	// Line 361, Address: 0x2d2ce4, Func Offset: 0x744
	// Line 367, Address: 0x2d2ce8, Func Offset: 0x748
	// Line 364, Address: 0x2d2cf0, Func Offset: 0x750
	// Line 367, Address: 0x2d2cf4, Func Offset: 0x754
	// Line 368, Address: 0x2d2cfc, Func Offset: 0x75c
	// Line 370, Address: 0x2d2d04, Func Offset: 0x764
	// Line 371, Address: 0x2d2d0c, Func Offset: 0x76c
	// Line 374, Address: 0x2d2d10, Func Offset: 0x770
	// Line 376, Address: 0x2d2d18, Func Offset: 0x778
	// Line 377, Address: 0x2d2d30, Func Offset: 0x790
	// Line 378, Address: 0x2d2d38, Func Offset: 0x798
	// Line 379, Address: 0x2d2d40, Func Offset: 0x7a0
	// Line 380, Address: 0x2d2d48, Func Offset: 0x7a8
	// Line 381, Address: 0x2d2d94, Func Offset: 0x7f4
	// Line 384, Address: 0x2d2dd4, Func Offset: 0x834
	// Line 381, Address: 0x2d2dd8, Func Offset: 0x838
	// Line 384, Address: 0x2d2de0, Func Offset: 0x840
	// Line 387, Address: 0x2d2dec, Func Offset: 0x84c
	// Line 386, Address: 0x2d2df0, Func Offset: 0x850
	// Line 387, Address: 0x2d2df4, Func Offset: 0x854
	// Line 391, Address: 0x2d2e00, Func Offset: 0x860
	// Line 395, Address: 0x2d2e38, Func Offset: 0x898
	// Line 397, Address: 0x2d2e40, Func Offset: 0x8a0
	// Line 400, Address: 0x2d2e48, Func Offset: 0x8a8
	// Line 405, Address: 0x2d2e58, Func Offset: 0x8b8
	// Line 406, Address: 0x2d2e5c, Func Offset: 0x8bc
	// Func End, Address: 0x2d2e8c, Func Offset: 0x8ec
}

// 
// Start address: 0x2d2e90
tagCHUNK_HEAD* njCnkCsUvn(tagCHUNK_HEAD* pCnk)
{
	unsigned int cflag;
	float zbuff[4];
	unsigned int coflag;
	_anon17* timp;
	unsigned long vu1func_tag;
	unsigned long ulVuflag;
	unsigned long* ulpP;
	int sExit;
	void(*pVu1Func)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
	unsigned short usColorCalc;
	unsigned short usClip;
	unsigned short usNum;
	unsigned short usMax;
	unsigned short usCnt;
	unsigned short usStrip;
	unsigned short usNext;
	tagVU1_STRIP_BUF* pSorg;
	tagVU1_STRIP_BUF* pS;
	tagVU1_STRIP_BUF* pV;
	unsigned short* uspCnk;
	unsigned long ulType2;
	unsigned long ulType;
	unsigned char ucFlag;
	// Line 19, Address: 0x2d2e90, Func Offset: 0
	// Line 21, Address: 0x2d2eac, Func Offset: 0x1c
	// Line 19, Address: 0x2d2eb0, Func Offset: 0x20
	// Line 21, Address: 0x2d2eb8, Func Offset: 0x28
	// Line 19, Address: 0x2d2ec0, Func Offset: 0x30
	// Line 22, Address: 0x2d2ec4, Func Offset: 0x34
	// Line 19, Address: 0x2d2ec8, Func Offset: 0x38
	// Line 22, Address: 0x2d2ecc, Func Offset: 0x3c
	// Line 35, Address: 0x2d2ed0, Func Offset: 0x40
	// Line 36, Address: 0x2d2eec, Func Offset: 0x5c
	// Line 40, Address: 0x2d2ef4, Func Offset: 0x64
	// Line 41, Address: 0x2d2f04, Func Offset: 0x74
	// Line 42, Address: 0x2d2f10, Func Offset: 0x80
	// Line 41, Address: 0x2d2f14, Func Offset: 0x84
	// Line 48, Address: 0x2d2f1c, Func Offset: 0x8c
	// Line 49, Address: 0x2d2f2c, Func Offset: 0x9c
	// Line 50, Address: 0x2d2f38, Func Offset: 0xa8
	// Line 49, Address: 0x2d2f3c, Func Offset: 0xac
	// Line 55, Address: 0x2d2f44, Func Offset: 0xb4
	// Line 57, Address: 0x2d2f54, Func Offset: 0xc4
	// Line 58, Address: 0x2d2f60, Func Offset: 0xd0
	// Line 59, Address: 0x2d2f6c, Func Offset: 0xdc
	// Line 60, Address: 0x2d2f70, Func Offset: 0xe0
	// Line 63, Address: 0x2d2f78, Func Offset: 0xe8
	// Line 64, Address: 0x2d2f88, Func Offset: 0xf8
	// Line 65, Address: 0x2d2f98, Func Offset: 0x108
	// Line 66, Address: 0x2d2fa8, Func Offset: 0x118
	// Line 67, Address: 0x2d2fb4, Func Offset: 0x124
	// Line 72, Address: 0x2d2fd4, Func Offset: 0x144
	// Line 78, Address: 0x2d2fe8, Func Offset: 0x158
	// Line 76, Address: 0x2d2fec, Func Offset: 0x15c
	// Line 72, Address: 0x2d2ff0, Func Offset: 0x160
	// Line 86, Address: 0x2d3000, Func Offset: 0x170
	// Line 72, Address: 0x2d3004, Func Offset: 0x174
	// Line 86, Address: 0x2d3008, Func Offset: 0x178
	// Line 79, Address: 0x2d300c, Func Offset: 0x17c
	// Line 78, Address: 0x2d3010, Func Offset: 0x180
	// Line 86, Address: 0x2d3014, Func Offset: 0x184
	// Line 87, Address: 0x2d301c, Func Offset: 0x18c
	// Line 97, Address: 0x2d3044, Func Offset: 0x1b4
	// Line 99, Address: 0x2d306c, Func Offset: 0x1dc
	// Line 100, Address: 0x2d3070, Func Offset: 0x1e0
	// Line 101, Address: 0x2d3078, Func Offset: 0x1e8
	// Line 104, Address: 0x2d307c, Func Offset: 0x1ec
	// Line 105, Address: 0x2d3088, Func Offset: 0x1f8
	// Line 106, Address: 0x2d3094, Func Offset: 0x204
	// Line 107, Address: 0x2d309c, Func Offset: 0x20c
	// Line 108, Address: 0x2d30a4, Func Offset: 0x214
	// Line 112, Address: 0x2d30ac, Func Offset: 0x21c
	// Line 113, Address: 0x2d30b4, Func Offset: 0x224
	// Line 115, Address: 0x2d30bc, Func Offset: 0x22c
	// Line 114, Address: 0x2d30cc, Func Offset: 0x23c
	// Line 115, Address: 0x2d30d0, Func Offset: 0x240
	// Line 116, Address: 0x2d30d8, Func Offset: 0x248
	// Line 117, Address: 0x2d30e8, Func Offset: 0x258
	// Line 120, Address: 0x2d30f4, Func Offset: 0x264
	// Line 118, Address: 0x2d30f8, Func Offset: 0x268
	// Line 117, Address: 0x2d3100, Func Offset: 0x270
	// Line 118, Address: 0x2d3104, Func Offset: 0x274
	// Line 119, Address: 0x2d3108, Func Offset: 0x278
	// Line 124, Address: 0x2d3110, Func Offset: 0x280
	// Line 118, Address: 0x2d3114, Func Offset: 0x284
	// Line 119, Address: 0x2d3118, Func Offset: 0x288
	// Line 124, Address: 0x2d311c, Func Offset: 0x28c
	// Line 125, Address: 0x2d3120, Func Offset: 0x290
	// Line 119, Address: 0x2d3128, Func Offset: 0x298
	// Line 120, Address: 0x2d312c, Func Offset: 0x29c
	// Line 126, Address: 0x2d3130, Func Offset: 0x2a0
	// Line 127, Address: 0x2d3138, Func Offset: 0x2a8
	// Line 120, Address: 0x2d3140, Func Offset: 0x2b0
	// Line 121, Address: 0x2d3144, Func Offset: 0x2b4
	// Line 131, Address: 0x2d314c, Func Offset: 0x2bc
	// Line 135, Address: 0x2d3154, Func Offset: 0x2c4
	// Line 136, Address: 0x2d315c, Func Offset: 0x2cc
	// Line 121, Address: 0x2d3160, Func Offset: 0x2d0
	// Line 122, Address: 0x2d3164, Func Offset: 0x2d4
	// Line 136, Address: 0x2d316c, Func Offset: 0x2dc
	// Line 137, Address: 0x2d3170, Func Offset: 0x2e0
	// Line 122, Address: 0x2d3178, Func Offset: 0x2e8
	// Line 123, Address: 0x2d317c, Func Offset: 0x2ec
	// Line 138, Address: 0x2d3184, Func Offset: 0x2f4
	// Line 139, Address: 0x2d318c, Func Offset: 0x2fc
	// Line 141, Address: 0x2d3190, Func Offset: 0x300
	// Line 123, Address: 0x2d3194, Func Offset: 0x304
	// Line 124, Address: 0x2d3198, Func Offset: 0x308
	// Line 141, Address: 0x2d319c, Func Offset: 0x30c
	// Line 124, Address: 0x2d31b0, Func Offset: 0x320
	// Line 125, Address: 0x2d31b4, Func Offset: 0x324
	// Line 144, Address: 0x2d31b8, Func Offset: 0x328
	// Line 128, Address: 0x2d31c0, Func Offset: 0x330
	// Line 139, Address: 0x2d31c4, Func Offset: 0x334
	// Line 125, Address: 0x2d31c8, Func Offset: 0x338
	// Line 126, Address: 0x2d31cc, Func Offset: 0x33c
	// Line 142, Address: 0x2d31d0, Func Offset: 0x340
	// Line 144, Address: 0x2d31d4, Func Offset: 0x344
	// Line 126, Address: 0x2d31dc, Func Offset: 0x34c
	// Line 127, Address: 0x2d31e0, Func Offset: 0x350
	// Line 128, Address: 0x2d31e8, Func Offset: 0x358
	// Line 129, Address: 0x2d31f0, Func Offset: 0x360
	// Line 130, Address: 0x2d31fc, Func Offset: 0x36c
	// Line 131, Address: 0x2d3200, Func Offset: 0x370
	// Line 132, Address: 0x2d3204, Func Offset: 0x374
	// Line 133, Address: 0x2d3210, Func Offset: 0x380
	// Line 134, Address: 0x2d321c, Func Offset: 0x38c
	// Line 135, Address: 0x2d3220, Func Offset: 0x390
	// Line 136, Address: 0x2d3224, Func Offset: 0x394
	// Line 137, Address: 0x2d322c, Func Offset: 0x39c
	// Line 138, Address: 0x2d3234, Func Offset: 0x3a4
	// Line 139, Address: 0x2d323c, Func Offset: 0x3ac
	// Line 141, Address: 0x2d3244, Func Offset: 0x3b4
	// Line 144, Address: 0x2d3248, Func Offset: 0x3b8
	// Line 145, Address: 0x2d3250, Func Offset: 0x3c0
	// Line 148, Address: 0x2d3264, Func Offset: 0x3d4
	// Line 151, Address: 0x2d326c, Func Offset: 0x3dc
	// Line 152, Address: 0x2d3278, Func Offset: 0x3e8
	// Line 153, Address: 0x2d3290, Func Offset: 0x400
	// Line 152, Address: 0x2d3294, Func Offset: 0x404
	// Line 155, Address: 0x2d3298, Func Offset: 0x408
	// Line 156, Address: 0x2d329c, Func Offset: 0x40c
	// Line 161, Address: 0x2d32a0, Func Offset: 0x410
	// Line 167, Address: 0x2d32c8, Func Offset: 0x438
	// Line 168, Address: 0x2d32d8, Func Offset: 0x448
	// Line 170, Address: 0x2d32e0, Func Offset: 0x450
	// Line 171, Address: 0x2d32e8, Func Offset: 0x458
	// Line 173, Address: 0x2d32ec, Func Offset: 0x45c
	// Line 175, Address: 0x2d32f0, Func Offset: 0x460
	// Line 178, Address: 0x2d32fc, Func Offset: 0x46c
	// Line 175, Address: 0x2d3304, Func Offset: 0x474
	// Line 178, Address: 0x2d3318, Func Offset: 0x488
	// Line 176, Address: 0x2d3328, Func Offset: 0x498
	// Line 178, Address: 0x2d332c, Func Offset: 0x49c
	// Line 177, Address: 0x2d3330, Func Offset: 0x4a0
	// Line 178, Address: 0x2d3334, Func Offset: 0x4a4
	// Line 179, Address: 0x2d333c, Func Offset: 0x4ac
	// Line 183, Address: 0x2d3354, Func Offset: 0x4c4
	// Line 179, Address: 0x2d3358, Func Offset: 0x4c8
	// Line 180, Address: 0x2d336c, Func Offset: 0x4dc
	// Line 183, Address: 0x2d3374, Func Offset: 0x4e4
	// Line 185, Address: 0x2d337c, Func Offset: 0x4ec
	// Line 186, Address: 0x2d3380, Func Offset: 0x4f0
	// Line 187, Address: 0x2d3384, Func Offset: 0x4f4
	// Line 188, Address: 0x2d3388, Func Offset: 0x4f8
	// Line 189, Address: 0x2d338c, Func Offset: 0x4fc
	// Line 190, Address: 0x2d3390, Func Offset: 0x500
	// Line 191, Address: 0x2d3394, Func Offset: 0x504
	// Line 193, Address: 0x2d3398, Func Offset: 0x508
	// Line 194, Address: 0x2d339c, Func Offset: 0x50c
	// Line 195, Address: 0x2d33a0, Func Offset: 0x510
	// Line 196, Address: 0x2d33a4, Func Offset: 0x514
	// Line 198, Address: 0x2d33a8, Func Offset: 0x518
	// Line 199, Address: 0x2d33ac, Func Offset: 0x51c
	// Line 200, Address: 0x2d33b0, Func Offset: 0x520
	// Line 201, Address: 0x2d33b4, Func Offset: 0x524
	// Line 202, Address: 0x2d33b8, Func Offset: 0x528
	// Line 204, Address: 0x2d33c0, Func Offset: 0x530
	// Line 206, Address: 0x2d33c4, Func Offset: 0x534
	// Line 207, Address: 0x2d33c8, Func Offset: 0x538
	// Line 208, Address: 0x2d33cc, Func Offset: 0x53c
	// Line 209, Address: 0x2d33d0, Func Offset: 0x540
	// Line 210, Address: 0x2d33d4, Func Offset: 0x544
	// Line 211, Address: 0x2d33d8, Func Offset: 0x548
	// Line 212, Address: 0x2d33dc, Func Offset: 0x54c
	// Line 214, Address: 0x2d33e0, Func Offset: 0x550
	// Line 217, Address: 0x2d33e8, Func Offset: 0x558
	// Line 218, Address: 0x2d33ec, Func Offset: 0x55c
	// Line 219, Address: 0x2d33f0, Func Offset: 0x560
	// Line 220, Address: 0x2d33f4, Func Offset: 0x564
	// Line 221, Address: 0x2d33f8, Func Offset: 0x568
	// Line 222, Address: 0x2d33fc, Func Offset: 0x56c
	// Line 223, Address: 0x2d3400, Func Offset: 0x570
	// Line 224, Address: 0x2d3404, Func Offset: 0x574
	// Line 227, Address: 0x2d3408, Func Offset: 0x578
	// Line 231, Address: 0x2d3410, Func Offset: 0x580
	// Line 233, Address: 0x2d3420, Func Offset: 0x590
	// Line 239, Address: 0x2d3428, Func Offset: 0x598
	// Line 242, Address: 0x2d345c, Func Offset: 0x5cc
	// Line 249, Address: 0x2d3460, Func Offset: 0x5d0
	// Line 251, Address: 0x2d3474, Func Offset: 0x5e4
	// Line 252, Address: 0x2d3478, Func Offset: 0x5e8
	// Line 253, Address: 0x2d347c, Func Offset: 0x5ec
	// Line 257, Address: 0x2d3480, Func Offset: 0x5f0
	// Line 258, Address: 0x2d3484, Func Offset: 0x5f4
	// Line 259, Address: 0x2d3488, Func Offset: 0x5f8
	// Line 260, Address: 0x2d348c, Func Offset: 0x5fc
	// Line 261, Address: 0x2d3490, Func Offset: 0x600
	// Line 262, Address: 0x2d3494, Func Offset: 0x604
	// Line 263, Address: 0x2d3498, Func Offset: 0x608
	// Line 264, Address: 0x2d349c, Func Offset: 0x60c
	// Line 265, Address: 0x2d34a0, Func Offset: 0x610
	// Line 266, Address: 0x2d34a4, Func Offset: 0x614
	// Line 267, Address: 0x2d34a8, Func Offset: 0x618
	// Line 268, Address: 0x2d34ac, Func Offset: 0x61c
	// Line 270, Address: 0x2d34b0, Func Offset: 0x620
	// Line 271, Address: 0x2d34b4, Func Offset: 0x624
	// Line 272, Address: 0x2d34b8, Func Offset: 0x628
	// Line 273, Address: 0x2d34bc, Func Offset: 0x62c
	// Line 274, Address: 0x2d34c0, Func Offset: 0x630
	// Line 276, Address: 0x2d34c4, Func Offset: 0x634
	// Line 278, Address: 0x2d34c8, Func Offset: 0x638
	// Line 279, Address: 0x2d34cc, Func Offset: 0x63c
	// Line 281, Address: 0x2d34d0, Func Offset: 0x640
	// Line 282, Address: 0x2d34d4, Func Offset: 0x644
	// Line 283, Address: 0x2d34d8, Func Offset: 0x648
	// Line 285, Address: 0x2d34dc, Func Offset: 0x64c
	// Line 287, Address: 0x2d34e0, Func Offset: 0x650
	// Line 288, Address: 0x2d34e4, Func Offset: 0x654
	// Line 289, Address: 0x2d34e8, Func Offset: 0x658
	// Line 290, Address: 0x2d34ec, Func Offset: 0x65c
	// Line 292, Address: 0x2d34f0, Func Offset: 0x660
	// Line 294, Address: 0x2d34f4, Func Offset: 0x664
	// Line 296, Address: 0x2d34f8, Func Offset: 0x668
	// Line 297, Address: 0x2d34fc, Func Offset: 0x66c
	// Line 298, Address: 0x2d3500, Func Offset: 0x670
	// Line 299, Address: 0x2d3504, Func Offset: 0x674
	// Line 300, Address: 0x2d3508, Func Offset: 0x678
	// Line 301, Address: 0x2d350c, Func Offset: 0x67c
	// Line 303, Address: 0x2d3510, Func Offset: 0x680
	// Line 309, Address: 0x2d3518, Func Offset: 0x688
	// Line 310, Address: 0x2d352c, Func Offset: 0x69c
	// Line 325, Address: 0x2d3534, Func Offset: 0x6a4
	// Line 314, Address: 0x2d3540, Func Offset: 0x6b0
	// Line 325, Address: 0x2d3544, Func Offset: 0x6b4
	// Line 326, Address: 0x2d3550, Func Offset: 0x6c0
	// Line 327, Address: 0x2d3564, Func Offset: 0x6d4
	// Line 328, Address: 0x2d3568, Func Offset: 0x6d8
	// Line 330, Address: 0x2d3570, Func Offset: 0x6e0
	// Line 336, Address: 0x2d3578, Func Offset: 0x6e8
	// Line 338, Address: 0x2d3588, Func Offset: 0x6f8
	// Line 344, Address: 0x2d3590, Func Offset: 0x700
	// Line 356, Address: 0x2d3598, Func Offset: 0x708
	// Line 354, Address: 0x2d359c, Func Offset: 0x70c
	// Line 356, Address: 0x2d35a4, Func Offset: 0x714
	// Line 357, Address: 0x2d35ac, Func Offset: 0x71c
	// Line 358, Address: 0x2d35c8, Func Offset: 0x738
	// Line 357, Address: 0x2d35cc, Func Offset: 0x73c
	// Line 360, Address: 0x2d35d0, Func Offset: 0x740
	// Line 361, Address: 0x2d35d4, Func Offset: 0x744
	// Line 367, Address: 0x2d35d8, Func Offset: 0x748
	// Line 364, Address: 0x2d35e0, Func Offset: 0x750
	// Line 367, Address: 0x2d35e4, Func Offset: 0x754
	// Line 368, Address: 0x2d35ec, Func Offset: 0x75c
	// Line 370, Address: 0x2d35f4, Func Offset: 0x764
	// Line 371, Address: 0x2d35fc, Func Offset: 0x76c
	// Line 374, Address: 0x2d3600, Func Offset: 0x770
	// Line 376, Address: 0x2d3608, Func Offset: 0x778
	// Line 377, Address: 0x2d3620, Func Offset: 0x790
	// Line 378, Address: 0x2d3628, Func Offset: 0x798
	// Line 379, Address: 0x2d3630, Func Offset: 0x7a0
	// Line 380, Address: 0x2d3638, Func Offset: 0x7a8
	// Line 381, Address: 0x2d3684, Func Offset: 0x7f4
	// Line 384, Address: 0x2d36c4, Func Offset: 0x834
	// Line 381, Address: 0x2d36c8, Func Offset: 0x838
	// Line 384, Address: 0x2d36d0, Func Offset: 0x840
	// Line 387, Address: 0x2d36dc, Func Offset: 0x84c
	// Line 386, Address: 0x2d36e0, Func Offset: 0x850
	// Line 387, Address: 0x2d36e4, Func Offset: 0x854
	// Line 391, Address: 0x2d36f0, Func Offset: 0x860
	// Line 395, Address: 0x2d3728, Func Offset: 0x898
	// Line 397, Address: 0x2d3730, Func Offset: 0x8a0
	// Line 400, Address: 0x2d3738, Func Offset: 0x8a8
	// Line 405, Address: 0x2d3748, Func Offset: 0x8b8
	// Line 406, Address: 0x2d374c, Func Offset: 0x8bc
	// Func End, Address: 0x2d377c, Func Offset: 0x8ec
}

