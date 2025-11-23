#include "dread.h"

/*char* mshp_tab[16];
_anon18* sys;
BH_PWORK* plp;
_anon11* rom;
char BIO_CURRENT[0];*/

// 
// Start address: 0x2c9ca0
void bhReadPlayerData()
{
	unsigned char* plmtnp;
	unsigned char* mempb;
	unsigned char* plmdlp;
	unsigned char* datp;
	unsigned int dt1;
	unsigned int dt0;
	int plmdlsz;
	int i;
	//_anon4* mtnp;
	//_anon13* mdlp;
	// Line 81, Address: 0x2c9ca0, Func Offset: 0
	// Line 89, Address: 0x2c9cc4, Func Offset: 0x24
	// Line 98, Address: 0x2c9cd8, Func Offset: 0x38
	// Line 96, Address: 0x2c9cdc, Func Offset: 0x3c
	// Line 98, Address: 0x2c9ce0, Func Offset: 0x40
	// Line 89, Address: 0x2c9ce4, Func Offset: 0x44
	// Line 98, Address: 0x2c9ce8, Func Offset: 0x48
	// Line 97, Address: 0x2c9cec, Func Offset: 0x4c
	// Line 98, Address: 0x2c9cf0, Func Offset: 0x50
	// Line 101, Address: 0x2c9cfc, Func Offset: 0x5c
	// Line 102, Address: 0x2c9d04, Func Offset: 0x64
	// Line 101, Address: 0x2c9d0c, Func Offset: 0x6c
	// Line 102, Address: 0x2c9d18, Func Offset: 0x78
	// Line 103, Address: 0x2c9d20, Func Offset: 0x80
	// Line 105, Address: 0x2c9d2c, Func Offset: 0x8c
	// Line 106, Address: 0x2c9d34, Func Offset: 0x94
	// Line 107, Address: 0x2c9d3c, Func Offset: 0x9c
	// Line 108, Address: 0x2c9d40, Func Offset: 0xa0
	// Line 109, Address: 0x2c9d54, Func Offset: 0xb4
	// Line 110, Address: 0x2c9d6c, Func Offset: 0xcc
	// Line 111, Address: 0x2c9d74, Func Offset: 0xd4
	// Line 112, Address: 0x2c9d80, Func Offset: 0xe0
	// Line 113, Address: 0x2c9da0, Func Offset: 0x100
	// Line 115, Address: 0x2c9da8, Func Offset: 0x108
	// Line 116, Address: 0x2c9db8, Func Offset: 0x118
	// Line 115, Address: 0x2c9dbc, Func Offset: 0x11c
	// Line 116, Address: 0x2c9dc8, Func Offset: 0x128
	// Line 119, Address: 0x2c9dd4, Func Offset: 0x134
	// Line 118, Address: 0x2c9dd8, Func Offset: 0x138
	// Line 116, Address: 0x2c9ddc, Func Offset: 0x13c
	// Line 119, Address: 0x2c9de8, Func Offset: 0x148
	// Line 122, Address: 0x2c9df8, Func Offset: 0x158
	// Line 123, Address: 0x2c9e00, Func Offset: 0x160
	// Line 125, Address: 0x2c9e04, Func Offset: 0x164
	// Line 131, Address: 0x2c9e18, Func Offset: 0x178
	// Line 127, Address: 0x2c9e20, Func Offset: 0x180
	// Line 129, Address: 0x2c9e24, Func Offset: 0x184
	// Line 131, Address: 0x2c9e28, Func Offset: 0x188
	// Line 130, Address: 0x2c9e34, Func Offset: 0x194
	// Line 131, Address: 0x2c9e38, Func Offset: 0x198
	// Line 132, Address: 0x2c9e44, Func Offset: 0x1a4
	// Line 134, Address: 0x2c9e58, Func Offset: 0x1b8
	// Line 135, Address: 0x2c9e60, Func Offset: 0x1c0
	// Line 134, Address: 0x2c9e68, Func Offset: 0x1c8
	// Line 135, Address: 0x2c9e74, Func Offset: 0x1d4
	// Line 136, Address: 0x2c9e84, Func Offset: 0x1e4
	// Line 137, Address: 0x2c9e90, Func Offset: 0x1f0
	// Line 136, Address: 0x2c9e94, Func Offset: 0x1f4
	// Line 137, Address: 0x2c9e98, Func Offset: 0x1f8
	// Line 138, Address: 0x2c9e9c, Func Offset: 0x1fc
	// Line 139, Address: 0x2c9ea4, Func Offset: 0x204
	// Line 140, Address: 0x2c9eac, Func Offset: 0x20c
	// Line 141, Address: 0x2c9eb0, Func Offset: 0x210
	// Line 144, Address: 0x2c9ebc, Func Offset: 0x21c
	// Line 146, Address: 0x2c9ec4, Func Offset: 0x224
	// Line 145, Address: 0x2c9ec8, Func Offset: 0x228
	// Line 147, Address: 0x2c9ecc, Func Offset: 0x22c
	// Line 148, Address: 0x2c9ed0, Func Offset: 0x230
	// Line 149, Address: 0x2c9ed4, Func Offset: 0x234
	// Line 155, Address: 0x2c9ee8, Func Offset: 0x248
	// Line 151, Address: 0x2c9ef0, Func Offset: 0x250
	// Line 153, Address: 0x2c9ef4, Func Offset: 0x254
	// Line 155, Address: 0x2c9ef8, Func Offset: 0x258
	// Line 154, Address: 0x2c9f04, Func Offset: 0x264
	// Line 155, Address: 0x2c9f08, Func Offset: 0x268
	// Line 157, Address: 0x2c9f14, Func Offset: 0x274
	// Line 160, Address: 0x2c9f18, Func Offset: 0x278
	// Line 161, Address: 0x2c9f24, Func Offset: 0x284
	// Line 162, Address: 0x2c9f34, Func Offset: 0x294
	// Line 163, Address: 0x2c9f38, Func Offset: 0x298
	// Line 165, Address: 0x2c9f48, Func Offset: 0x2a8
	// Line 166, Address: 0x2c9f54, Func Offset: 0x2b4
	// Line 165, Address: 0x2c9f58, Func Offset: 0x2b8
	// Line 167, Address: 0x2c9f5c, Func Offset: 0x2bc
	// Line 168, Address: 0x2c9f64, Func Offset: 0x2c4
	// Line 171, Address: 0x2c9f68, Func Offset: 0x2c8
	// Line 172, Address: 0x2c9f6c, Func Offset: 0x2cc
	// Line 171, Address: 0x2c9f74, Func Offset: 0x2d4
	// Line 172, Address: 0x2c9f7c, Func Offset: 0x2dc
	// Line 175, Address: 0x2c9f90, Func Offset: 0x2f0
	// Line 176, Address: 0x2c9f98, Func Offset: 0x2f8
	// Line 178, Address: 0x2c9fac, Func Offset: 0x30c
	// Line 180, Address: 0x2c9fc8, Func Offset: 0x328
	// Line 181, Address: 0x2c9fd4, Func Offset: 0x334
	// Line 180, Address: 0x2c9fdc, Func Offset: 0x33c
	// Line 181, Address: 0x2c9ffc, Func Offset: 0x35c
	// Line 182, Address: 0x2ca004, Func Offset: 0x364
	// Line 184, Address: 0x2ca028, Func Offset: 0x388
	// Line 182, Address: 0x2ca02c, Func Offset: 0x38c
	// Line 184, Address: 0x2ca038, Func Offset: 0x398
	// Line 186, Address: 0x2ca050, Func Offset: 0x3b0
	// Line 188, Address: 0x2ca078, Func Offset: 0x3d8
	// Line 186, Address: 0x2ca07c, Func Offset: 0x3dc
	// Line 188, Address: 0x2ca088, Func Offset: 0x3e8
	// Line 189, Address: 0x2ca098, Func Offset: 0x3f8
	// Func End, Address: 0x2ca0c0, Func Offset: 0x420
	scePrintf("bhReadPlayerData - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2ca0c0
void bhReadWeaponData()
{
	unsigned char* plmtnp;
	int mtsz;
	//_anon4* mtnp;
	unsigned char* mp;
	unsigned char* dp;
	int wpn_no;
	int msz;
	int sz;
	//_anon0* op;
	// Line 195, Address: 0x2ca0c0, Func Offset: 0
	// Line 200, Address: 0x2ca0e0, Func Offset: 0x20
	// Line 201, Address: 0x2ca0e8, Func Offset: 0x28
	// Line 200, Address: 0x2ca0f0, Func Offset: 0x30
	// Line 201, Address: 0x2ca0f4, Func Offset: 0x34
	// Line 208, Address: 0x2ca0fc, Func Offset: 0x3c
	// Line 201, Address: 0x2ca100, Func Offset: 0x40
	// Line 208, Address: 0x2ca104, Func Offset: 0x44
	// Line 207, Address: 0x2ca108, Func Offset: 0x48
	// Line 204, Address: 0x2ca110, Func Offset: 0x50
	// Line 207, Address: 0x2ca114, Func Offset: 0x54
	// Line 208, Address: 0x2ca118, Func Offset: 0x58
	// Line 209, Address: 0x2ca120, Func Offset: 0x60
	// Line 210, Address: 0x2ca130, Func Offset: 0x70
	// Line 212, Address: 0x2ca138, Func Offset: 0x78
	// Line 216, Address: 0x2ca144, Func Offset: 0x84
	// Line 217, Address: 0x2ca14c, Func Offset: 0x8c
	// Line 218, Address: 0x2ca154, Func Offset: 0x94
	// Line 217, Address: 0x2ca15c, Func Offset: 0x9c
	// Line 218, Address: 0x2ca168, Func Offset: 0xa8
	// Line 219, Address: 0x2ca170, Func Offset: 0xb0
	// Line 220, Address: 0x2ca180, Func Offset: 0xc0
	// Line 221, Address: 0x2ca188, Func Offset: 0xc8
	// Line 223, Address: 0x2ca194, Func Offset: 0xd4
	// Line 225, Address: 0x2ca198, Func Offset: 0xd8
	// Line 226, Address: 0x2ca19c, Func Offset: 0xdc
	// Line 232, Address: 0x2ca1ac, Func Offset: 0xec
	// Line 235, Address: 0x2ca1b8, Func Offset: 0xf8
	// Line 232, Address: 0x2ca1bc, Func Offset: 0xfc
	// Line 236, Address: 0x2ca1c0, Func Offset: 0x100
	// Line 237, Address: 0x2ca1c8, Func Offset: 0x108
	// Line 239, Address: 0x2ca1cc, Func Offset: 0x10c
	// Line 240, Address: 0x2ca1d4, Func Offset: 0x114
	// Line 241, Address: 0x2ca1e4, Func Offset: 0x124
	// Line 242, Address: 0x2ca1e8, Func Offset: 0x128
	// Line 241, Address: 0x2ca1ec, Func Offset: 0x12c
	// Line 242, Address: 0x2ca1f4, Func Offset: 0x134
	// Line 246, Address: 0x2ca204, Func Offset: 0x144
	// Line 247, Address: 0x2ca21c, Func Offset: 0x15c
	// Line 248, Address: 0x2ca23c, Func Offset: 0x17c
	// Line 256, Address: 0x2ca240, Func Offset: 0x180
	// Line 250, Address: 0x2ca248, Func Offset: 0x188
	// Line 253, Address: 0x2ca24c, Func Offset: 0x18c
	// Line 256, Address: 0x2ca250, Func Offset: 0x190
	// Line 257, Address: 0x2ca25c, Func Offset: 0x19c
	// Line 255, Address: 0x2ca260, Func Offset: 0x1a0
	// Line 257, Address: 0x2ca264, Func Offset: 0x1a4
	// Line 258, Address: 0x2ca270, Func Offset: 0x1b0
	// Line 259, Address: 0x2ca280, Func Offset: 0x1c0
	// Line 261, Address: 0x2ca288, Func Offset: 0x1c8
	// Line 265, Address: 0x2ca294, Func Offset: 0x1d4
	// Line 266, Address: 0x2ca29c, Func Offset: 0x1dc
	// Line 267, Address: 0x2ca2a4, Func Offset: 0x1e4
	// Line 266, Address: 0x2ca2ac, Func Offset: 0x1ec
	// Line 267, Address: 0x2ca2b8, Func Offset: 0x1f8
	// Line 268, Address: 0x2ca2c0, Func Offset: 0x200
	// Line 269, Address: 0x2ca2d0, Func Offset: 0x210
	// Line 270, Address: 0x2ca2d8, Func Offset: 0x218
	// Line 272, Address: 0x2ca2e4, Func Offset: 0x224
	// Line 274, Address: 0x2ca2e8, Func Offset: 0x228
	// Line 275, Address: 0x2ca2ec, Func Offset: 0x22c
	// Line 281, Address: 0x2ca2fc, Func Offset: 0x23c
	// Line 284, Address: 0x2ca308, Func Offset: 0x248
	// Line 281, Address: 0x2ca30c, Func Offset: 0x24c
	// Line 285, Address: 0x2ca310, Func Offset: 0x250
	// Line 286, Address: 0x2ca318, Func Offset: 0x258
	// Line 288, Address: 0x2ca31c, Func Offset: 0x25c
	// Line 289, Address: 0x2ca324, Func Offset: 0x264
	// Line 290, Address: 0x2ca334, Func Offset: 0x274
	// Line 291, Address: 0x2ca338, Func Offset: 0x278
	// Line 290, Address: 0x2ca33c, Func Offset: 0x27c
	// Line 291, Address: 0x2ca344, Func Offset: 0x284
	// Line 295, Address: 0x2ca354, Func Offset: 0x294
	// Line 296, Address: 0x2ca36c, Func Offset: 0x2ac
	// Line 297, Address: 0x2ca38c, Func Offset: 0x2cc
	// Line 299, Address: 0x2ca390, Func Offset: 0x2d0
	// Line 301, Address: 0x2ca394, Func Offset: 0x2d4
	// Line 303, Address: 0x2ca398, Func Offset: 0x2d8
	// Line 307, Address: 0x2ca3a0, Func Offset: 0x2e0
	// Line 308, Address: 0x2ca3a8, Func Offset: 0x2e8
	// Line 307, Address: 0x2ca3b0, Func Offset: 0x2f0
	// Line 308, Address: 0x2ca3bc, Func Offset: 0x2fc
	// Line 309, Address: 0x2ca3c4, Func Offset: 0x304
	// Line 310, Address: 0x2ca3d8, Func Offset: 0x318
	// Line 311, Address: 0x2ca3e4, Func Offset: 0x324
	// Line 312, Address: 0x2ca3ec, Func Offset: 0x32c
	// Line 313, Address: 0x2ca3f4, Func Offset: 0x334
	// Line 314, Address: 0x2ca3f8, Func Offset: 0x338
	// Line 316, Address: 0x2ca404, Func Offset: 0x344
	// Line 317, Address: 0x2ca40c, Func Offset: 0x34c
	// Line 319, Address: 0x2ca410, Func Offset: 0x350
	// Line 320, Address: 0x2ca414, Func Offset: 0x354
	// Line 324, Address: 0x2ca428, Func Offset: 0x368
	// Func End, Address: 0x2ca44c, Func Offset: 0x38c
	scePrintf("bhReadWeaponData - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2ca450
unsigned char* bhKeepObjWork(_anon13* mp, unsigned char* sp)
{
	// Line 648, Address: 0x2ca450, Func Offset: 0
	// Line 651, Address: 0x2ca464, Func Offset: 0x14
	// Line 656, Address: 0x2ca470, Func Offset: 0x20
	// Line 657, Address: 0x2ca474, Func Offset: 0x24
	// Line 658, Address: 0x2ca494, Func Offset: 0x44
	// Line 660, Address: 0x2ca498, Func Offset: 0x48
	// Line 658, Address: 0x2ca49c, Func Offset: 0x4c
	// Line 660, Address: 0x2ca4a4, Func Offset: 0x54
	// Line 658, Address: 0x2ca4a8, Func Offset: 0x58
	// Line 659, Address: 0x2ca4b0, Func Offset: 0x60
	// Line 660, Address: 0x2ca4b4, Func Offset: 0x64
	// Func End, Address: 0x2ca4c0, Func Offset: 0x70
}*/

