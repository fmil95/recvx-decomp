typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;


typedef int type_0[4];
typedef float type_1[4];
typedef int type_2[4][32];

struct _anon0
{
	void* texaddr;
	_anon7 texsurface;
};

struct _anon1
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon2
{
	_anon1* textures;
	unsigned int nbTexture;
};

struct _anon3
{
	unsigned int globalIndex;
	unsigned int bank;
	unsigned int tspparambuffer;
	unsigned int texparambuffer;
	unsigned int texaddr;
	_anon0 texinfo;
	unsigned short count;
	unsigned short dummy;
};

struct _anon4
{
	float x;
	float y;
	float z;
};

struct _anon5
{
	_anon4 p;
	float sx;
	float sy;
	int ang;
	_anon2* tlist;
	_anon6* tanim;
};

struct _anon6
{
	short sx;
	short sy;
	short cx;
	short cy;
	short u1;
	short v1;
	short u2;
	short v2;
	short texid;
	short attr;
};

struct _anon7
{
	unsigned int Type;
	unsigned int BitDepth;
	unsigned int PixelFormat;
	unsigned int nWidth;
	unsigned int nHeight;
	unsigned int TextureSize;
	unsigned int fSurfaceFlags;
	unsigned int* pSurface;
	unsigned int* pVirtual;
	unsigned int* pPhysical;
};

float fNaCnkConstantA;
float fNaCnkConstantB;
float fNaCnkConstantG;
float fNaCnkConstantR;

void njDrawSprite2D(_anon5* sp, int n, float pri, unsigned int attr);

// 
// Start address: 0x2e0bb0
void njDrawSprite2D(_anon5* sp, int n, float pri, unsigned int attr)
{
	_anon3* tmp;
	int val;
	int shift_num;
	int v_val;
	int h_val;
	_anon6* ap;
	short swap;
	float yy;
	float xx;
	float si;
	float co;
	unsigned long prim;
	float colf[4];
	int col[4];
	int bp[4];
	int buff[4][32];
	// Line 55, Address: 0x2e0bb0, Func Offset: 0
	// Line 69, Address: 0x2e0bf8, Func Offset: 0x48
	// Line 68, Address: 0x2e0c0c, Func Offset: 0x5c
	// Line 69, Address: 0x2e0c10, Func Offset: 0x60
	// Line 72, Address: 0x2e0c14, Func Offset: 0x64
	// Line 73, Address: 0x2e0c30, Func Offset: 0x80
	// Line 77, Address: 0x2e0c34, Func Offset: 0x84
	// Line 78, Address: 0x2e0c54, Func Offset: 0xa4
	// Line 80, Address: 0x2e0c5c, Func Offset: 0xac
	// Line 89, Address: 0x2e0c64, Func Offset: 0xb4
	// Line 91, Address: 0x2e0c70, Func Offset: 0xc0
	// Line 92, Address: 0x2e0c78, Func Offset: 0xc8
	// Line 94, Address: 0x2e0c7c, Func Offset: 0xcc
	// Line 96, Address: 0x2e0c88, Func Offset: 0xd8
	// Line 97, Address: 0x2e0c90, Func Offset: 0xe0
	// Line 100, Address: 0x2e0c94, Func Offset: 0xe4
	// Line 104, Address: 0x2e0ca0, Func Offset: 0xf0
	// Line 106, Address: 0x2e0cc4, Func Offset: 0x114
	// Line 104, Address: 0x2e0cc8, Func Offset: 0x118
	// Line 106, Address: 0x2e0ccc, Func Offset: 0x11c
	// Line 110, Address: 0x2e0cd4, Func Offset: 0x124
	// Line 112, Address: 0x2e0cf8, Func Offset: 0x148
	// Line 110, Address: 0x2e0cfc, Func Offset: 0x14c
	// Line 112, Address: 0x2e0d00, Func Offset: 0x150
	// Line 116, Address: 0x2e0d08, Func Offset: 0x158
	// Line 118, Address: 0x2e0d2c, Func Offset: 0x17c
	// Line 116, Address: 0x2e0d30, Func Offset: 0x180
	// Line 118, Address: 0x2e0d34, Func Offset: 0x184
	// Line 122, Address: 0x2e0d3c, Func Offset: 0x18c
	// Line 125, Address: 0x2e0d64, Func Offset: 0x1b4
	// Line 127, Address: 0x2e0d6c, Func Offset: 0x1bc
	// Line 128, Address: 0x2e0d70, Func Offset: 0x1c0
	// Line 127, Address: 0x2e0d74, Func Offset: 0x1c4
	// Line 129, Address: 0x2e0d78, Func Offset: 0x1c8
	// Line 130, Address: 0x2e0d7c, Func Offset: 0x1cc
	// Line 131, Address: 0x2e0d80, Func Offset: 0x1d0
	// Line 130, Address: 0x2e0d84, Func Offset: 0x1d4
	// Line 132, Address: 0x2e0d88, Func Offset: 0x1d8
	// Line 134, Address: 0x2e0d8c, Func Offset: 0x1dc
	// Line 135, Address: 0x2e0d90, Func Offset: 0x1e0
	// Line 134, Address: 0x2e0d94, Func Offset: 0x1e4
	// Line 136, Address: 0x2e0d98, Func Offset: 0x1e8
	// Line 137, Address: 0x2e0d9c, Func Offset: 0x1ec
	// Line 138, Address: 0x2e0da0, Func Offset: 0x1f0
	// Line 137, Address: 0x2e0da4, Func Offset: 0x1f4
	// Line 128, Address: 0x2e0da8, Func Offset: 0x1f8
	// Line 131, Address: 0x2e0dac, Func Offset: 0x1fc
	// Line 135, Address: 0x2e0db0, Func Offset: 0x200
	// Line 138, Address: 0x2e0db4, Func Offset: 0x204
	// Line 139, Address: 0x2e0db8, Func Offset: 0x208
	// Line 141, Address: 0x2e0dbc, Func Offset: 0x20c
	// Line 143, Address: 0x2e0dc4, Func Offset: 0x214
	// Line 144, Address: 0x2e0dc8, Func Offset: 0x218
	// Line 143, Address: 0x2e0dcc, Func Offset: 0x21c
	// Line 145, Address: 0x2e0dd0, Func Offset: 0x220
	// Line 146, Address: 0x2e0dd4, Func Offset: 0x224
	// Line 147, Address: 0x2e0dd8, Func Offset: 0x228
	// Line 146, Address: 0x2e0ddc, Func Offset: 0x22c
	// Line 148, Address: 0x2e0de0, Func Offset: 0x230
	// Line 150, Address: 0x2e0de4, Func Offset: 0x234
	// Line 151, Address: 0x2e0de8, Func Offset: 0x238
	// Line 150, Address: 0x2e0dec, Func Offset: 0x23c
	// Line 152, Address: 0x2e0df0, Func Offset: 0x240
	// Line 153, Address: 0x2e0df4, Func Offset: 0x244
	// Line 154, Address: 0x2e0df8, Func Offset: 0x248
	// Line 153, Address: 0x2e0dfc, Func Offset: 0x24c
	// Line 144, Address: 0x2e0e00, Func Offset: 0x250
	// Line 147, Address: 0x2e0e04, Func Offset: 0x254
	// Line 151, Address: 0x2e0e08, Func Offset: 0x258
	// Line 154, Address: 0x2e0e0c, Func Offset: 0x25c
	// Line 155, Address: 0x2e0e10, Func Offset: 0x260
	// Line 159, Address: 0x2e0e14, Func Offset: 0x264
	// Line 161, Address: 0x2e0e5c, Func Offset: 0x2ac
	// Line 162, Address: 0x2e0e68, Func Offset: 0x2b8
	// Line 164, Address: 0x2e0e78, Func Offset: 0x2c8
	// Line 163, Address: 0x2e0e7c, Func Offset: 0x2cc
	// Line 164, Address: 0x2e0e80, Func Offset: 0x2d0
	// Line 165, Address: 0x2e0e88, Func Offset: 0x2d8
	// Line 168, Address: 0x2e0e94, Func Offset: 0x2e4
	// Line 165, Address: 0x2e0e98, Func Offset: 0x2e8
	// Line 167, Address: 0x2e0e9c, Func Offset: 0x2ec
	// Line 168, Address: 0x2e0ea0, Func Offset: 0x2f0
	// Line 171, Address: 0x2e0ea4, Func Offset: 0x2f4
	// Line 166, Address: 0x2e0eac, Func Offset: 0x2fc
	// Line 167, Address: 0x2e0eb0, Func Offset: 0x300
	// Line 168, Address: 0x2e0eb4, Func Offset: 0x304
	// Line 167, Address: 0x2e0eb8, Func Offset: 0x308
	// Line 168, Address: 0x2e0ebc, Func Offset: 0x30c
	// Line 170, Address: 0x2e0ec0, Func Offset: 0x310
	// Line 169, Address: 0x2e0ec4, Func Offset: 0x314
	// Line 170, Address: 0x2e0ec8, Func Offset: 0x318
	// Line 171, Address: 0x2e0ecc, Func Offset: 0x31c
	// Line 170, Address: 0x2e0ed0, Func Offset: 0x320
	// Line 171, Address: 0x2e0ed4, Func Offset: 0x324
	// Line 173, Address: 0x2e0ed8, Func Offset: 0x328
	// Line 175, Address: 0x2e0ee0, Func Offset: 0x330
	// Line 176, Address: 0x2e0eec, Func Offset: 0x33c
	// Line 178, Address: 0x2e0ef8, Func Offset: 0x348
	// Line 177, Address: 0x2e0efc, Func Offset: 0x34c
	// Line 178, Address: 0x2e0f00, Func Offset: 0x350
	// Line 179, Address: 0x2e0f08, Func Offset: 0x358
	// Line 181, Address: 0x2e0f14, Func Offset: 0x364
	// Line 182, Address: 0x2e0f18, Func Offset: 0x368
	// Line 180, Address: 0x2e0f1c, Func Offset: 0x36c
	// Line 181, Address: 0x2e0f20, Func Offset: 0x370
	// Line 185, Address: 0x2e0f24, Func Offset: 0x374
	// Line 181, Address: 0x2e0f28, Func Offset: 0x378
	// Line 182, Address: 0x2e0f2c, Func Offset: 0x37c
	// Line 184, Address: 0x2e0f34, Func Offset: 0x384
	// Line 183, Address: 0x2e0f38, Func Offset: 0x388
	// Line 184, Address: 0x2e0f3c, Func Offset: 0x38c
	// Line 185, Address: 0x2e0f44, Func Offset: 0x394
	// Line 187, Address: 0x2e0f4c, Func Offset: 0x39c
	// Line 189, Address: 0x2e0f54, Func Offset: 0x3a4
	// Line 190, Address: 0x2e0f60, Func Offset: 0x3b0
	// Line 192, Address: 0x2e0f6c, Func Offset: 0x3bc
	// Line 191, Address: 0x2e0f70, Func Offset: 0x3c0
	// Line 192, Address: 0x2e0f74, Func Offset: 0x3c4
	// Line 193, Address: 0x2e0f7c, Func Offset: 0x3cc
	// Line 195, Address: 0x2e0f88, Func Offset: 0x3d8
	// Line 196, Address: 0x2e0f8c, Func Offset: 0x3dc
	// Line 194, Address: 0x2e0f90, Func Offset: 0x3e0
	// Line 195, Address: 0x2e0f94, Func Offset: 0x3e4
	// Line 199, Address: 0x2e0f98, Func Offset: 0x3e8
	// Line 195, Address: 0x2e0f9c, Func Offset: 0x3ec
	// Line 196, Address: 0x2e0fa0, Func Offset: 0x3f0
	// Line 198, Address: 0x2e0fa8, Func Offset: 0x3f8
	// Line 197, Address: 0x2e0fac, Func Offset: 0x3fc
	// Line 198, Address: 0x2e0fb0, Func Offset: 0x400
	// Line 199, Address: 0x2e0fb8, Func Offset: 0x408
	// Line 201, Address: 0x2e0fc0, Func Offset: 0x410
	// Line 203, Address: 0x2e0fc8, Func Offset: 0x418
	// Line 204, Address: 0x2e0fd4, Func Offset: 0x424
	// Line 206, Address: 0x2e0fe0, Func Offset: 0x430
	// Line 205, Address: 0x2e0fe4, Func Offset: 0x434
	// Line 206, Address: 0x2e0fe8, Func Offset: 0x438
	// Line 207, Address: 0x2e0ff0, Func Offset: 0x440
	// Line 209, Address: 0x2e0ffc, Func Offset: 0x44c
	// Line 210, Address: 0x2e1000, Func Offset: 0x450
	// Line 208, Address: 0x2e1004, Func Offset: 0x454
	// Line 209, Address: 0x2e1008, Func Offset: 0x458
	// Line 213, Address: 0x2e100c, Func Offset: 0x45c
	// Line 209, Address: 0x2e1010, Func Offset: 0x460
	// Line 210, Address: 0x2e1014, Func Offset: 0x464
	// Line 212, Address: 0x2e101c, Func Offset: 0x46c
	// Line 211, Address: 0x2e1020, Func Offset: 0x470
	// Line 212, Address: 0x2e1024, Func Offset: 0x474
	// Line 213, Address: 0x2e102c, Func Offset: 0x47c
	// Line 214, Address: 0x2e1034, Func Offset: 0x484
	// Line 253, Address: 0x2e1038, Func Offset: 0x488
	// Line 254, Address: 0x2e1040, Func Offset: 0x490
	// Line 255, Address: 0x2e1044, Func Offset: 0x494
	// Line 256, Address: 0x2e1048, Func Offset: 0x498
	// Line 258, Address: 0x2e104c, Func Offset: 0x49c
	// Line 264, Address: 0x2e1058, Func Offset: 0x4a8
	// Line 269, Address: 0x2e1068, Func Offset: 0x4b8
	// Line 264, Address: 0x2e1070, Func Offset: 0x4c0
	// Line 265, Address: 0x2e1074, Func Offset: 0x4c4
	// Line 264, Address: 0x2e107c, Func Offset: 0x4cc
	// Line 266, Address: 0x2e1080, Func Offset: 0x4d0
	// Line 265, Address: 0x2e1088, Func Offset: 0x4d8
	// Line 268, Address: 0x2e108c, Func Offset: 0x4dc
	// Line 266, Address: 0x2e1094, Func Offset: 0x4e4
	// Line 265, Address: 0x2e1098, Func Offset: 0x4e8
	// Line 268, Address: 0x2e109c, Func Offset: 0x4ec
	// Line 266, Address: 0x2e10a0, Func Offset: 0x4f0
	// Line 269, Address: 0x2e10a4, Func Offset: 0x4f4
	// Line 270, Address: 0x2e10ac, Func Offset: 0x4fc
	// Line 271, Address: 0x2e10b8, Func Offset: 0x508
	// Line 272, Address: 0x2e10c0, Func Offset: 0x510
	// Line 273, Address: 0x2e10c8, Func Offset: 0x518
	// Line 274, Address: 0x2e10cc, Func Offset: 0x51c
	// Line 275, Address: 0x2e10d4, Func Offset: 0x524
	// Line 276, Address: 0x2e10dc, Func Offset: 0x52c
	// Line 277, Address: 0x2e10e0, Func Offset: 0x530
	// Line 278, Address: 0x2e10e4, Func Offset: 0x534
	// Line 279, Address: 0x2e10e8, Func Offset: 0x538
	// Line 280, Address: 0x2e10ec, Func Offset: 0x53c
	// Line 281, Address: 0x2e10f0, Func Offset: 0x540
	// Line 282, Address: 0x2e10f4, Func Offset: 0x544
	// Line 283, Address: 0x2e10f8, Func Offset: 0x548
	// Line 284, Address: 0x2e10fc, Func Offset: 0x54c
	// Line 285, Address: 0x2e1100, Func Offset: 0x550
	// Line 286, Address: 0x2e1104, Func Offset: 0x554
	// Line 287, Address: 0x2e1108, Func Offset: 0x558
	// Line 288, Address: 0x2e110c, Func Offset: 0x55c
	// Line 289, Address: 0x2e1110, Func Offset: 0x560
	// Line 290, Address: 0x2e1114, Func Offset: 0x564
	// Line 294, Address: 0x2e1118, Func Offset: 0x568
	// Line 295, Address: 0x2e1120, Func Offset: 0x570
	// Line 296, Address: 0x2e1124, Func Offset: 0x574
	// Line 297, Address: 0x2e1128, Func Offset: 0x578
	// Line 296, Address: 0x2e112c, Func Offset: 0x57c
	// Line 294, Address: 0x2e1130, Func Offset: 0x580
	// Line 295, Address: 0x2e1140, Func Offset: 0x590
	// Line 297, Address: 0x2e1144, Func Offset: 0x594
	// Line 296, Address: 0x2e1148, Func Offset: 0x598
	// Line 305, Address: 0x2e114c, Func Offset: 0x59c
	// Line 294, Address: 0x2e1150, Func Offset: 0x5a0
	// Line 296, Address: 0x2e1154, Func Offset: 0x5a4
	// Line 295, Address: 0x2e1158, Func Offset: 0x5a8
	// Line 296, Address: 0x2e1160, Func Offset: 0x5b0
	// Line 297, Address: 0x2e1168, Func Offset: 0x5b8
	// Line 295, Address: 0x2e1170, Func Offset: 0x5c0
	// Line 297, Address: 0x2e1174, Func Offset: 0x5c4
	// Line 295, Address: 0x2e1178, Func Offset: 0x5c8
	// Line 297, Address: 0x2e117c, Func Offset: 0x5cc
	// Line 294, Address: 0x2e1180, Func Offset: 0x5d0
	// Line 295, Address: 0x2e1184, Func Offset: 0x5d4
	// Line 296, Address: 0x2e1188, Func Offset: 0x5d8
	// Line 305, Address: 0x2e118c, Func Offset: 0x5dc
	// Line 306, Address: 0x2e1194, Func Offset: 0x5e4
	// Line 307, Address: 0x2e11b4, Func Offset: 0x604
	// Line 306, Address: 0x2e11bc, Func Offset: 0x60c
	// Line 307, Address: 0x2e11c0, Func Offset: 0x610
	// Line 308, Address: 0x2e11d8, Func Offset: 0x628
	// Line 309, Address: 0x2e11e0, Func Offset: 0x630
	// Line 310, Address: 0x2e11e4, Func Offset: 0x634
	// Line 309, Address: 0x2e11e8, Func Offset: 0x638
	// Line 312, Address: 0x2e11f4, Func Offset: 0x644
	// Line 313, Address: 0x2e11fc, Func Offset: 0x64c
	// Line 314, Address: 0x2e1200, Func Offset: 0x650
	// Line 313, Address: 0x2e1204, Func Offset: 0x654
	// Line 317, Address: 0x2e1210, Func Offset: 0x660
	// Line 318, Address: 0x2e1218, Func Offset: 0x668
	// Line 319, Address: 0x2e1220, Func Offset: 0x670
	// Line 321, Address: 0x2e1224, Func Offset: 0x674
	// Line 322, Address: 0x2e122c, Func Offset: 0x67c
	// Line 323, Address: 0x2e1234, Func Offset: 0x684
	// Line 325, Address: 0x2e1238, Func Offset: 0x688
	// Line 343, Address: 0x2e1244, Func Offset: 0x694
	// Line 326, Address: 0x2e1248, Func Offset: 0x698
	// Line 325, Address: 0x2e1254, Func Offset: 0x6a4
	// Line 341, Address: 0x2e1258, Func Offset: 0x6a8
	// Line 325, Address: 0x2e1260, Func Offset: 0x6b0
	// Line 326, Address: 0x2e1268, Func Offset: 0x6b8
	// Line 327, Address: 0x2e1278, Func Offset: 0x6c8
	// Line 328, Address: 0x2e127c, Func Offset: 0x6cc
	// Line 329, Address: 0x2e1280, Func Offset: 0x6d0
	// Line 330, Address: 0x2e1290, Func Offset: 0x6e0
	// Line 331, Address: 0x2e12a0, Func Offset: 0x6f0
	// Line 332, Address: 0x2e12a4, Func Offset: 0x6f4
	// Line 333, Address: 0x2e12a8, Func Offset: 0x6f8
	// Line 334, Address: 0x2e12b8, Func Offset: 0x708
	// Line 335, Address: 0x2e12c8, Func Offset: 0x718
	// Line 336, Address: 0x2e12cc, Func Offset: 0x71c
	// Line 337, Address: 0x2e12d0, Func Offset: 0x720
	// Line 338, Address: 0x2e12e0, Func Offset: 0x730
	// Line 339, Address: 0x2e12f0, Func Offset: 0x740
	// Line 343, Address: 0x2e12f4, Func Offset: 0x744
	// Line 344, Address: 0x2e12fc, Func Offset: 0x74c
	// Line 347, Address: 0x2e1310, Func Offset: 0x760
	// Line 348, Address: 0x2e1324, Func Offset: 0x774
	// Line 350, Address: 0x2e1334, Func Offset: 0x784
	// Func End, Address: 0x2e1380, Func Offset: 0x7d0
}

