typedef struct _anon0;
typedef struct tagTIM2_FILEHEADER;


typedef unsigned int type_0[32];
typedef unsigned char type_1[8192];
typedef unsigned int type_2[32];
typedef unsigned int type_3[32];
typedef unsigned char type_4[8192];
typedef char type_5[4];
typedef unsigned int type_6[128];
typedef unsigned int type_7[32];
typedef unsigned int type_8[128];
typedef char type_9[8];
typedef unsigned char type_10[256];
typedef unsigned char type_11[19];
typedef unsigned int type_12[128];
typedef unsigned char type_13[256];
typedef int type_14[128];
typedef unsigned char type_15[8192];
typedef unsigned int type_16[2];
typedef unsigned int type_17[2];
typedef unsigned int type_18[128];
typedef unsigned char type_19[256];
typedef unsigned char type_20[8192];
typedef unsigned char type_21[256];
typedef int type_22[256];

struct _anon0
{
	unsigned int TotalSize;
	unsigned int ClutSize;
	unsigned int ImageSize;
	unsigned short HeaderSize;
	unsigned short ClutColors;
	unsigned char PictFormat;
	unsigned char MipMapTextures;
	unsigned char ClutType;
	unsigned char ImageType;
	unsigned short ImageWidth;
	unsigned short ImageHeight;
	unsigned int GsTex0[2];
	unsigned int GsTex1[2];
	unsigned int GsRegs;
	unsigned int GsTexClut;
};

struct tagTIM2_FILEHEADER
{
	char FileId[4];
	unsigned char FormatVersion;
	unsigned char FormatId;
	unsigned short Pictures;
	char Reserved[8];
};

unsigned char* Ps2_PXLCONV;

void Tim2_Format_Check(void* tim2_ptr);
int BlockConv4to32(unsigned char* p_input, unsigned char* p_output);
int BlockConv8to32(unsigned char* p_input, unsigned char* p_output);
int PageConv4to32(int width, int height, unsigned char* p_input, unsigned char* p_output);
int PageConv8to32(int width, int height, unsigned char* p_input, unsigned char* p_output);
int Conv4to32(int width, int height, unsigned char* p_input, unsigned char* p_output);
int Conv8to32(int width, int height, unsigned char* p_input, unsigned char* p_output);

// 
// Start address: 0x3011a0
void Tim2_Format_Check(void* tim2_ptr)
{
	unsigned char* output;
	unsigned char* pImage;
	_anon0* ph;
	// Line 28, Address: 0x3011a0, Func Offset: 0
	// Line 34, Address: 0x3011b4, Func Offset: 0x14
	// Line 44, Address: 0x3011b8, Func Offset: 0x18
	// Line 51, Address: 0x3011d0, Func Offset: 0x30
	// Line 53, Address: 0x3011d8, Func Offset: 0x38
	// Line 54, Address: 0x3011dc, Func Offset: 0x3c
	// Line 57, Address: 0x3011f4, Func Offset: 0x54
	// Line 59, Address: 0x3011fc, Func Offset: 0x5c
	// Line 60, Address: 0x301208, Func Offset: 0x68
	// Line 63, Address: 0x301210, Func Offset: 0x70
	// Line 65, Address: 0x301220, Func Offset: 0x80
	// Line 66, Address: 0x301234, Func Offset: 0x94
	// Line 68, Address: 0x301248, Func Offset: 0xa8
	// Line 69, Address: 0x30125c, Func Offset: 0xbc
	// Line 70, Address: 0x301264, Func Offset: 0xc4
	// Line 71, Address: 0x301270, Func Offset: 0xd0
	// Line 74, Address: 0x301278, Func Offset: 0xd8
	// Line 84, Address: 0x301288, Func Offset: 0xe8
	// Func End, Address: 0x3012a0, Func Offset: 0x100
}

// 
// Start address: 0x3012a0
int BlockConv4to32(unsigned char* p_input, unsigned char* p_output)
{
	unsigned char* pIn;
	unsigned char c_out;
	unsigned int index1;
	unsigned int index0;
	unsigned int i2;
	unsigned int i0;
	unsigned int k;
	unsigned int j;
	unsigned int i;
	int lut[256];
	// Line 132, Address: 0x3012a0, Func Offset: 0
	// Line 178, Address: 0x3012ac, Func Offset: 0xc
	// Line 180, Address: 0x3012b0, Func Offset: 0x10
	// Line 198, Address: 0x3012b4, Func Offset: 0x14
	// Line 196, Address: 0x3012bc, Func Offset: 0x1c
	// Line 198, Address: 0x3012c0, Func Offset: 0x20
	// Line 182, Address: 0x3012c8, Func Offset: 0x28
	// Line 184, Address: 0x3012d4, Func Offset: 0x34
	// Line 186, Address: 0x3012e0, Func Offset: 0x40
	// Line 198, Address: 0x3012e8, Func Offset: 0x48
	// Line 190, Address: 0x3012ec, Func Offset: 0x4c
	// Line 198, Address: 0x3012f0, Func Offset: 0x50
	// Line 207, Address: 0x3012fc, Func Offset: 0x5c
	// Line 198, Address: 0x301300, Func Offset: 0x60
	// Line 194, Address: 0x301308, Func Offset: 0x68
	// Line 196, Address: 0x301310, Func Offset: 0x70
	// Line 198, Address: 0x30131c, Func Offset: 0x7c
	// Line 196, Address: 0x301320, Func Offset: 0x80
	// Line 202, Address: 0x301330, Func Offset: 0x90
	// Line 204, Address: 0x301338, Func Offset: 0x98
	// Line 206, Address: 0x301358, Func Offset: 0xb8
	// Line 204, Address: 0x30135c, Func Offset: 0xbc
	// Line 206, Address: 0x301364, Func Offset: 0xc4
	// Line 207, Address: 0x301368, Func Offset: 0xc8
	// Line 208, Address: 0x301374, Func Offset: 0xd4
	// Line 210, Address: 0x301384, Func Offset: 0xe4
	// Line 213, Address: 0x301394, Func Offset: 0xf4
	// Line 212, Address: 0x30139c, Func Offset: 0xfc
	// Line 213, Address: 0x3013a0, Func Offset: 0x100
	// Func End, Address: 0x3013a8, Func Offset: 0x108
}

// 
// Start address: 0x3013b0
int BlockConv8to32(unsigned char* p_input, unsigned char* p_output)
{
	unsigned char* pIn;
	unsigned int index1;
	unsigned int index0;
	unsigned int i0;
	unsigned int k;
	unsigned int j;
	unsigned int i;
	int lut[128];
	// Line 272, Address: 0x3013b0, Func Offset: 0
	// Line 274, Address: 0x3013b4, Func Offset: 0x4
	// Line 277, Address: 0x3013c0, Func Offset: 0x10
	// Line 279, Address: 0x3013cc, Func Offset: 0x1c
	// Line 280, Address: 0x3013d8, Func Offset: 0x28
	// Line 281, Address: 0x3013e0, Func Offset: 0x30
	// Line 282, Address: 0x3013e4, Func Offset: 0x34
	// Line 283, Address: 0x3013e8, Func Offset: 0x38
	// Line 281, Address: 0x3013ec, Func Offset: 0x3c
	// Line 282, Address: 0x3013f0, Func Offset: 0x40
	// Line 281, Address: 0x3013f8, Func Offset: 0x48
	// Line 282, Address: 0x301400, Func Offset: 0x50
	// Line 283, Address: 0x301404, Func Offset: 0x54
	// Line 284, Address: 0x301410, Func Offset: 0x60
	// Line 286, Address: 0x301420, Func Offset: 0x70
	// Line 289, Address: 0x301430, Func Offset: 0x80
	// Func End, Address: 0x301438, Func Offset: 0x88
}

// 
// Start address: 0x301440
int PageConv4to32(int width, int height, unsigned char* p_input, unsigned char* p_output)
{
	int n_height;
	int n_width;
	int k;
	int j;
	int i;
	int index0;
	unsigned char* po1;
	unsigned char* po0;
	unsigned char* pi1;
	unsigned char* pi0;
	unsigned char output_block[256];
	unsigned char input_block[256];
	unsigned int in_block_nb;
	unsigned int index32_v[128];
	unsigned int index32_h[128];
	unsigned int block_table4[32];
	unsigned int block_table32[32];
	// Line 292, Address: 0x301440, Func Offset: 0
	// Line 321, Address: 0x30146c, Func Offset: 0x2c
	// Line 292, Address: 0x301470, Func Offset: 0x30
	// Line 321, Address: 0x301474, Func Offset: 0x34
	// Line 292, Address: 0x301480, Func Offset: 0x40
	// Line 321, Address: 0x301484, Func Offset: 0x44
	// Line 332, Address: 0x3014dc, Func Offset: 0x9c
	// Line 333, Address: 0x3014e0, Func Offset: 0xa0
	// Line 334, Address: 0x3014e4, Func Offset: 0xa4
	// Line 336, Address: 0x3014f0, Func Offset: 0xb0
	// Line 337, Address: 0x3014f4, Func Offset: 0xb4
	// Line 338, Address: 0x3014f8, Func Offset: 0xb8
	// Line 336, Address: 0x3014fc, Func Offset: 0xbc
	// Line 339, Address: 0x301508, Func Offset: 0xc8
	// Line 337, Address: 0x30150c, Func Offset: 0xcc
	// Line 339, Address: 0x301510, Func Offset: 0xd0
	// Line 340, Address: 0x30151c, Func Offset: 0xdc
	// Line 347, Address: 0x30152c, Func Offset: 0xec
	// Line 362, Address: 0x301534, Func Offset: 0xf4
	// Line 346, Address: 0x301538, Func Offset: 0xf8
	// Line 362, Address: 0x30153c, Func Offset: 0xfc
	// Line 364, Address: 0x301550, Func Offset: 0x110
	// Line 373, Address: 0x301570, Func Offset: 0x130
	// Line 366, Address: 0x301584, Func Offset: 0x144
	// Line 370, Address: 0x301588, Func Offset: 0x148
	// Line 375, Address: 0x30158c, Func Offset: 0x14c
	// Line 376, Address: 0x301590, Func Offset: 0x150
	// Line 383, Address: 0x3015a0, Func Offset: 0x160
	// Line 380, Address: 0x3015a8, Func Offset: 0x168
	// Line 383, Address: 0x3015ac, Func Offset: 0x16c
	// Line 385, Address: 0x3015b4, Func Offset: 0x174
	// Line 388, Address: 0x3015c0, Func Offset: 0x180
	// Line 387, Address: 0x3015cc, Func Offset: 0x18c
	// Line 389, Address: 0x3015d0, Func Offset: 0x190
	// Line 388, Address: 0x3015d4, Func Offset: 0x194
	// Line 390, Address: 0x3015e8, Func Offset: 0x1a8
	// Line 397, Address: 0x3015f8, Func Offset: 0x1b8
	// Line 394, Address: 0x301600, Func Offset: 0x1c0
	// Line 397, Address: 0x301604, Func Offset: 0x1c4
	// Line 399, Address: 0x30160c, Func Offset: 0x1cc
	// Line 397, Address: 0x301610, Func Offset: 0x1d0
	// Line 399, Address: 0x301614, Func Offset: 0x1d4
	// Line 400, Address: 0x301638, Func Offset: 0x1f8
	// Line 408, Address: 0x301658, Func Offset: 0x218
	// Line 407, Address: 0x301680, Func Offset: 0x240
	// Line 408, Address: 0x301684, Func Offset: 0x244
	// Func End, Address: 0x30168c, Func Offset: 0x24c
}

// 
// Start address: 0x301690
int PageConv8to32(int width, int height, unsigned char* p_input, unsigned char* p_output)
{
	int n_height;
	int n_width;
	int k;
	int j;
	int i;
	int index0;
	unsigned char* po1;
	unsigned char* po0;
	unsigned char* pi1;
	unsigned char* pi0;
	unsigned char output_block[256];
	unsigned char input_block[256];
	unsigned int in_block_nb;
	unsigned int index32_v[128];
	unsigned int index32_h[128];
	unsigned int block_table8[32];
	unsigned int block_table32[32];
	// Line 411, Address: 0x301690, Func Offset: 0
	// Line 441, Address: 0x3016cc, Func Offset: 0x3c
	// Line 442, Address: 0x3016d0, Func Offset: 0x40
	// Line 443, Address: 0x3016d4, Func Offset: 0x44
	// Line 445, Address: 0x3016e0, Func Offset: 0x50
	// Line 446, Address: 0x3016e4, Func Offset: 0x54
	// Line 447, Address: 0x3016e8, Func Offset: 0x58
	// Line 445, Address: 0x3016ec, Func Offset: 0x5c
	// Line 448, Address: 0x3016f8, Func Offset: 0x68
	// Line 446, Address: 0x3016fc, Func Offset: 0x6c
	// Line 448, Address: 0x301700, Func Offset: 0x70
	// Line 449, Address: 0x30170c, Func Offset: 0x7c
	// Line 452, Address: 0x30171c, Func Offset: 0x8c
	// Line 462, Address: 0x301724, Func Offset: 0x94
	// Line 451, Address: 0x301728, Func Offset: 0x98
	// Line 462, Address: 0x30172c, Func Offset: 0x9c
	// Line 464, Address: 0x301740, Func Offset: 0xb0
	// Line 469, Address: 0x301760, Func Offset: 0xd0
	// Line 466, Address: 0x301774, Func Offset: 0xe4
	// Line 467, Address: 0x301778, Func Offset: 0xe8
	// Line 471, Address: 0x30177c, Func Offset: 0xec
	// Line 472, Address: 0x301780, Func Offset: 0xf0
	// Line 475, Address: 0x301790, Func Offset: 0x100
	// Line 473, Address: 0x301798, Func Offset: 0x108
	// Line 475, Address: 0x30179c, Func Offset: 0x10c
	// Line 477, Address: 0x3017a4, Func Offset: 0x114
	// Line 481, Address: 0x3017b0, Func Offset: 0x120
	// Line 479, Address: 0x3017bc, Func Offset: 0x12c
	// Line 482, Address: 0x3017c0, Func Offset: 0x130
	// Line 481, Address: 0x3017c4, Func Offset: 0x134
	// Line 484, Address: 0x3017d8, Func Offset: 0x148
	// Line 488, Address: 0x3017e8, Func Offset: 0x158
	// Line 486, Address: 0x3017f0, Func Offset: 0x160
	// Line 488, Address: 0x3017f4, Func Offset: 0x164
	// Line 490, Address: 0x3017fc, Func Offset: 0x16c
	// Line 488, Address: 0x301800, Func Offset: 0x170
	// Line 490, Address: 0x301804, Func Offset: 0x174
	// Line 491, Address: 0x301828, Func Offset: 0x198
	// Line 499, Address: 0x301848, Func Offset: 0x1b8
	// Line 498, Address: 0x301870, Func Offset: 0x1e0
	// Line 499, Address: 0x301874, Func Offset: 0x1e4
	// Func End, Address: 0x30187c, Func Offset: 0x1ec
}

// 
// Start address: 0x301880
int Conv4to32(int width, int height, unsigned char* p_input, unsigned char* p_output)
{
	unsigned char output_page[8192];
	unsigned char input_page[8192];
	int n_output_height;
	int n_input_height;
	int n_output_width_byte;
	int n_input_width_byte;
	unsigned char* po1;
	unsigned char* po0;
	unsigned char* pi1;
	unsigned char* pi0;
	int n_page_w;
	int n_page_h;
	int k;
	int j;
	int i;
	// Line 518, Address: 0x301880, Func Offset: 0
	// Line 525, Address: 0x3018ac, Func Offset: 0x2c
	// Line 518, Address: 0x3018b0, Func Offset: 0x30
	// Line 525, Address: 0x3018b4, Func Offset: 0x34
	// Line 518, Address: 0x3018c0, Func Offset: 0x40
	// Line 525, Address: 0x3018c4, Func Offset: 0x44
	// Line 527, Address: 0x3018e4, Func Offset: 0x64
	// Line 531, Address: 0x301914, Func Offset: 0x94
	// Line 532, Address: 0x301918, Func Offset: 0x98
	// Line 533, Address: 0x301928, Func Offset: 0xa8
	// Line 535, Address: 0x301938, Func Offset: 0xb8
	// Line 537, Address: 0x301944, Func Offset: 0xc4
	// Line 539, Address: 0x30194c, Func Offset: 0xcc
	// Line 540, Address: 0x301950, Func Offset: 0xd0
	// Line 541, Address: 0x301960, Func Offset: 0xe0
	// Line 549, Address: 0x301970, Func Offset: 0xf0
	// Line 550, Address: 0x301974, Func Offset: 0xf4
	// Line 551, Address: 0x301984, Func Offset: 0x104
	// Line 553, Address: 0x301998, Func Offset: 0x118
	// Line 555, Address: 0x3019a4, Func Offset: 0x124
	// Line 559, Address: 0x3019ac, Func Offset: 0x12c
	// Line 560, Address: 0x3019bc, Func Offset: 0x13c
	// Line 565, Address: 0x3019cc, Func Offset: 0x14c
	// Line 566, Address: 0x3019dc, Func Offset: 0x15c
	// Line 568, Address: 0x3019e0, Func Offset: 0x160
	// Line 569, Address: 0x3019e8, Func Offset: 0x168
	// Line 570, Address: 0x3019ec, Func Offset: 0x16c
	// Line 573, Address: 0x3019f0, Func Offset: 0x170
	// Line 574, Address: 0x301a00, Func Offset: 0x180
	// Line 576, Address: 0x301a04, Func Offset: 0x184
	// Line 577, Address: 0x301a0c, Func Offset: 0x18c
	// Line 578, Address: 0x301a10, Func Offset: 0x190
	// Line 582, Address: 0x301a14, Func Offset: 0x194
	// Line 583, Address: 0x301a58, Func Offset: 0x1d8
	// Line 584, Address: 0x301a90, Func Offset: 0x210
	// Line 586, Address: 0x301a98, Func Offset: 0x218
	// Line 588, Address: 0x301a9c, Func Offset: 0x21c
	// Line 589, Address: 0x301ab0, Func Offset: 0x230
	// Line 592, Address: 0x301ac0, Func Offset: 0x240
	// Line 590, Address: 0x301ac4, Func Offset: 0x244
	// Line 592, Address: 0x301ac8, Func Offset: 0x248
	// Line 594, Address: 0x301ad8, Func Offset: 0x258
	// Line 596, Address: 0x301aec, Func Offset: 0x26c
	// Line 598, Address: 0x301af4, Func Offset: 0x274
	// Line 599, Address: 0x301af8, Func Offset: 0x278
	// Line 600, Address: 0x301b08, Func Offset: 0x288
	// Line 603, Address: 0x301b18, Func Offset: 0x298
	// Line 601, Address: 0x301b1c, Func Offset: 0x29c
	// Line 603, Address: 0x301b20, Func Offset: 0x2a0
	// Line 604, Address: 0x301b48, Func Offset: 0x2c8
	// Line 605, Address: 0x301b84, Func Offset: 0x304
	// Line 604, Address: 0x301b88, Func Offset: 0x308
	// Line 605, Address: 0x301b8c, Func Offset: 0x30c
	// Line 609, Address: 0x301ba8, Func Offset: 0x328
	// Line 610, Address: 0x301bac, Func Offset: 0x32c
	// Func End, Address: 0x301bdc, Func Offset: 0x35c
}

// 
// Start address: 0x301be0
int Conv8to32(int width, int height, unsigned char* p_input, unsigned char* p_output)
{
	unsigned char output_page[8192];
	unsigned char input_page[8192];
	unsigned char* po1;
	unsigned char* po0;
	unsigned char* pi1;
	unsigned char* pi0;
	int n_output_height;
	int n_input_height;
	int n_output_width_byte;
	int n_input_width_byte;
	int n_page_w;
	int n_page_h;
	int k;
	int j;
	int i;
	// Line 634, Address: 0x301be0, Func Offset: 0
	// Line 640, Address: 0x301c0c, Func Offset: 0x2c
	// Line 634, Address: 0x301c10, Func Offset: 0x30
	// Line 640, Address: 0x301c14, Func Offset: 0x34
	// Line 634, Address: 0x301c20, Func Offset: 0x40
	// Line 640, Address: 0x301c24, Func Offset: 0x44
	// Line 642, Address: 0x301c44, Func Offset: 0x64
	// Line 646, Address: 0x301c74, Func Offset: 0x94
	// Line 647, Address: 0x301c78, Func Offset: 0x98
	// Line 648, Address: 0x301c88, Func Offset: 0xa8
	// Line 650, Address: 0x301c98, Func Offset: 0xb8
	// Line 652, Address: 0x301ca4, Func Offset: 0xc4
	// Line 655, Address: 0x301cac, Func Offset: 0xcc
	// Line 656, Address: 0x301cb0, Func Offset: 0xd0
	// Line 657, Address: 0x301cc0, Func Offset: 0xe0
	// Line 659, Address: 0x301cd0, Func Offset: 0xf0
	// Line 661, Address: 0x301cdc, Func Offset: 0xfc
	// Line 672, Address: 0x301ce4, Func Offset: 0x104
	// Line 675, Address: 0x301cf4, Func Offset: 0x114
	// Line 683, Address: 0x301d04, Func Offset: 0x124
	// Line 684, Address: 0x301d14, Func Offset: 0x134
	// Line 686, Address: 0x301d18, Func Offset: 0x138
	// Line 687, Address: 0x301d20, Func Offset: 0x140
	// Line 688, Address: 0x301d24, Func Offset: 0x144
	// Line 691, Address: 0x301d28, Func Offset: 0x148
	// Line 692, Address: 0x301d38, Func Offset: 0x158
	// Line 694, Address: 0x301d3c, Func Offset: 0x15c
	// Line 695, Address: 0x301d44, Func Offset: 0x164
	// Line 696, Address: 0x301d48, Func Offset: 0x168
	// Line 699, Address: 0x301d4c, Func Offset: 0x16c
	// Line 700, Address: 0x301d90, Func Offset: 0x1b0
	// Line 701, Address: 0x301dc8, Func Offset: 0x1e8
	// Line 703, Address: 0x301dd0, Func Offset: 0x1f0
	// Line 705, Address: 0x301dd4, Func Offset: 0x1f4
	// Line 706, Address: 0x301de8, Func Offset: 0x208
	// Line 709, Address: 0x301df8, Func Offset: 0x218
	// Line 707, Address: 0x301dfc, Func Offset: 0x21c
	// Line 709, Address: 0x301e00, Func Offset: 0x220
	// Line 711, Address: 0x301e10, Func Offset: 0x230
	// Line 713, Address: 0x301e24, Func Offset: 0x244
	// Line 715, Address: 0x301e2c, Func Offset: 0x24c
	// Line 716, Address: 0x301e30, Func Offset: 0x250
	// Line 717, Address: 0x301e40, Func Offset: 0x260
	// Line 720, Address: 0x301e50, Func Offset: 0x270
	// Line 718, Address: 0x301e54, Func Offset: 0x274
	// Line 720, Address: 0x301e58, Func Offset: 0x278
	// Line 721, Address: 0x301e80, Func Offset: 0x2a0
	// Line 722, Address: 0x301ebc, Func Offset: 0x2dc
	// Line 721, Address: 0x301ec0, Func Offset: 0x2e0
	// Line 722, Address: 0x301ec4, Func Offset: 0x2e4
	// Line 724, Address: 0x301ee0, Func Offset: 0x300
	// Line 725, Address: 0x301ee4, Func Offset: 0x304
	// Func End, Address: 0x301f14, Func Offset: 0x334
}

