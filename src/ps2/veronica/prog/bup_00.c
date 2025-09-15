#include "bup_00.h"

/*char vmssyscmttbl[16];
int old_data_flg;
unsigned int InitFlag;
char bootcommenttbl[32][32];
_anon20* bip;
char StrBuf[128];
char ErrBuf[128];
char TwBuf[128];
char name_99[16];
unsigned char sys_icon_palette[32];
unsigned char sys_icon_data[512];
unsigned char cla_icon_palette[32];
unsigned char cla_icon_data[1536];
unsigned char chs_icon_palette[32];
unsigned char chs_icon_data[1536];
int space_pos[8][18];
unsigned short mesdeftbl[10];
void(*TypewriterMode)()[3];
_anon31* sys;
unsigned char* img1p;
_anon44 hdr00;
_anon20* binfo_;
unsigned char* img2p;
unsigned char* img3p;
unsigned char* img4p;
unsigned int palbuf[0];
_anon11* rom;
tagLOAD_SCREEN* pLoad;
tagLOAD_SCREEN Load;
BH_PWORK* plp;
tagSAVE_SCREEN* pSave;
unsigned char* vwbmemp;
tagSAVE_SCREEN Save;
int ErrorCode;
_anon44 hdr01;
_anon54 Info;
char bootcommentbuf[32][15];

void ControlTypewriter();
void TypewriterKeepMemory();
void CountDisplay(int disppoint, _anon5* pos, unsigned int col);
unsigned int RoomNameSwitch(unsigned int name);
void TypeWriterTextureInit();
void TypewriterInit();
void TypewriterMain();
void TypewriterExit();*/

// 
// Start address: 0x2c8b20
void ControlTypewriter()
{
	// Line 1113, Address: 0x2c8b20, Func Offset: 0
	// Func End, Address: 0x2c8b48, Func Offset: 0x28
	scePrintf("ControlTypewriter - UNIMPLEMENTED!\n");
}

// 100% matching! 
void TypewriterKeepMemory()
{
    sys->typ_exp = bhGetFreeMemory(800, 32);
}

// 
// Start address: 0x2c8b80
void CountDisplay(int disppoint, NJS_POINT2* pos, unsigned int col, int param) // fourth parameter is not present on the debugging symbols      
{
	//_anon26 uv[4];
	//_anon26 col_[4];
	//_anon5 p[4];
	//_anon43 p2c;
	// Line 2757, Address: 0x2c8b80, Func Offset: 0
	// Line 2764, Address: 0x2c8b94, Func Offset: 0x14
	// Line 2765, Address: 0x2c8bb8, Func Offset: 0x38
	// Line 2767, Address: 0x2c8bc0, Func Offset: 0x40
	// Line 2768, Address: 0x2c8bc8, Func Offset: 0x48
	// Line 2769, Address: 0x2c8bd0, Func Offset: 0x50
	// Line 2770, Address: 0x2c8bd8, Func Offset: 0x58
	// Line 2771, Address: 0x2c8be0, Func Offset: 0x60
	// Line 2773, Address: 0x2c8be4, Func Offset: 0x64
	// Line 2790, Address: 0x2c8bec, Func Offset: 0x6c
	// Line 2789, Address: 0x2c8bf0, Func Offset: 0x70
	// Line 2771, Address: 0x2c8bf4, Func Offset: 0x74
	// Line 2772, Address: 0x2c8bf8, Func Offset: 0x78
	// Line 2789, Address: 0x2c8bfc, Func Offset: 0x7c
	// Line 2800, Address: 0x2c8c04, Func Offset: 0x84
	// Line 2772, Address: 0x2c8c10, Func Offset: 0x90
	// Line 2773, Address: 0x2c8c14, Func Offset: 0x94
	// Line 2800, Address: 0x2c8c18, Func Offset: 0x98
	// Line 2773, Address: 0x2c8c24, Func Offset: 0xa4
	// Line 2774, Address: 0x2c8c2c, Func Offset: 0xac
	// Line 2775, Address: 0x2c8c34, Func Offset: 0xb4
	// Line 2776, Address: 0x2c8c40, Func Offset: 0xc0
	// Line 2777, Address: 0x2c8c4c, Func Offset: 0xcc
	// Line 2778, Address: 0x2c8c54, Func Offset: 0xd4
	// Line 2780, Address: 0x2c8c5c, Func Offset: 0xdc
	// Line 2781, Address: 0x2c8c60, Func Offset: 0xe0
	// Line 2782, Address: 0x2c8c64, Func Offset: 0xe4
	// Line 2789, Address: 0x2c8c68, Func Offset: 0xe8
	// Line 2778, Address: 0x2c8c6c, Func Offset: 0xec
	// Line 2783, Address: 0x2c8c70, Func Offset: 0xf0
	// Line 2790, Address: 0x2c8c74, Func Offset: 0xf4
	// Line 2792, Address: 0x2c8c78, Func Offset: 0xf8
	// Line 2793, Address: 0x2c8c84, Func Offset: 0x104
	// Line 2794, Address: 0x2c8c8c, Func Offset: 0x10c
	// Line 2795, Address: 0x2c8c98, Func Offset: 0x118
	// Line 2796, Address: 0x2c8ca4, Func Offset: 0x124
	// Line 2797, Address: 0x2c8cac, Func Offset: 0x12c
	// Line 2800, Address: 0x2c8cb4, Func Offset: 0x134
	// Line 2803, Address: 0x2c8cbc, Func Offset: 0x13c
	// Func End, Address: 0x2c8cd4, Func Offset: 0x154
	scePrintf("CountDisplay - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2c8ce0
unsigned int RoomNameSwitch(unsigned int name)
{
	unsigned int roomnum;
	// Line 2810, Address: 0x2c8ce0, Func Offset: 0
	// Line 2813, Address: 0x2c8dc8, Func Offset: 0xe8
	// Line 2819, Address: 0x2c8dd0, Func Offset: 0xf0
	// Line 2822, Address: 0x2c8dd8, Func Offset: 0xf8
	// Line 2828, Address: 0x2c8de0, Func Offset: 0x100
	// Line 2831, Address: 0x2c8de8, Func Offset: 0x108
	// Line 2834, Address: 0x2c8df0, Func Offset: 0x110
	// Line 2837, Address: 0x2c8df8, Func Offset: 0x118
	// Line 2840, Address: 0x2c8e00, Func Offset: 0x120
	// Line 2843, Address: 0x2c8e08, Func Offset: 0x128
	// Line 2846, Address: 0x2c8e10, Func Offset: 0x130
	// Line 2849, Address: 0x2c8e18, Func Offset: 0x138
	// Line 2852, Address: 0x2c8e20, Func Offset: 0x140
	// Line 2855, Address: 0x2c8e28, Func Offset: 0x148
	// Line 2858, Address: 0x2c8e30, Func Offset: 0x150
	// Line 2861, Address: 0x2c8e38, Func Offset: 0x158
	// Line 2864, Address: 0x2c8e40, Func Offset: 0x160
	// Line 2873, Address: 0x2c8e48, Func Offset: 0x168
	// Func End, Address: 0x2c8e50, Func Offset: 0x170
	scePrintf("RoomNameSwitch - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2c8e50
void TypeWriterTextureInit()
{
	unsigned int dt;
	unsigned char* datp;
	int sz;
	_anon2* tw;
	// Line 3232, Address: 0x2c8e50, Func Offset: 0
	// Line 3233, Address: 0x2c8e60, Func Offset: 0x10
	// Line 3237, Address: 0x2c8e6c, Func Offset: 0x1c
	// Line 3239, Address: 0x2c8e98, Func Offset: 0x48
	// Line 3240, Address: 0x2c8eb0, Func Offset: 0x60
	// Line 3241, Address: 0x2c8ec8, Func Offset: 0x78
	// Line 3243, Address: 0x2c8ecc, Func Offset: 0x7c
	// Line 3241, Address: 0x2c8ed4, Func Offset: 0x84
	// Line 3243, Address: 0x2c8edc, Func Offset: 0x8c
	// Line 3244, Address: 0x2c8ee8, Func Offset: 0x98
	// Line 3249, Address: 0x2c8ef0, Func Offset: 0xa0
	// Line 3252, Address: 0x2c8ef8, Func Offset: 0xa8
	// Line 3249, Address: 0x2c8f00, Func Offset: 0xb0
	// Line 3252, Address: 0x2c8f14, Func Offset: 0xc4
	// Line 3249, Address: 0x2c8f18, Func Offset: 0xc8
	// Line 3252, Address: 0x2c8f24, Func Offset: 0xd4
	// Line 3253, Address: 0x2c8f38, Func Offset: 0xe8
	// Line 3255, Address: 0x2c8f40, Func Offset: 0xf0
	// Line 3253, Address: 0x2c8f4c, Func Offset: 0xfc
	// Line 3254, Address: 0x2c8f64, Func Offset: 0x114
	// Line 3255, Address: 0x2c8f84, Func Offset: 0x134
	// Line 3256, Address: 0x2c8f94, Func Offset: 0x144
	// Line 3255, Address: 0x2c8f98, Func Offset: 0x148
	// Line 3268, Address: 0x2c8fa4, Func Offset: 0x154
	// Line 3269, Address: 0x2c8fac, Func Offset: 0x15c
	// Line 3271, Address: 0x2c8fb0, Func Offset: 0x160
	// Line 3273, Address: 0x2c8fb8, Func Offset: 0x168
	// Line 3274, Address: 0x2c8fc8, Func Offset: 0x178
	// Line 3282, Address: 0x2c8fd0, Func Offset: 0x180
	// Line 3274, Address: 0x2c8fd4, Func Offset: 0x184
	// Line 3281, Address: 0x2c8fe4, Func Offset: 0x194
	// Line 3275, Address: 0x2c8fe8, Func Offset: 0x198
	// Line 3276, Address: 0x2c8fec, Func Offset: 0x19c
	// Line 3277, Address: 0x2c8ff0, Func Offset: 0x1a0
	// Line 3278, Address: 0x2c8ff4, Func Offset: 0x1a4
	// Line 3281, Address: 0x2c8ff8, Func Offset: 0x1a8
	// Line 3283, Address: 0x2c900c, Func Offset: 0x1bc
	// Line 3285, Address: 0x2c9014, Func Offset: 0x1c4
	// Line 3286, Address: 0x2c9024, Func Offset: 0x1d4
	// Line 3287, Address: 0x2c9038, Func Offset: 0x1e8
	// Line 3292, Address: 0x2c9040, Func Offset: 0x1f0
	// Line 3295, Address: 0x2c905c, Func Offset: 0x20c
	// Line 3292, Address: 0x2c9060, Func Offset: 0x210
	// Line 3295, Address: 0x2c906c, Func Offset: 0x21c
	// Line 3296, Address: 0x2c9088, Func Offset: 0x238
	// Line 3298, Address: 0x2c908c, Func Offset: 0x23c
	// Line 3300, Address: 0x2c9094, Func Offset: 0x244
	// Line 3301, Address: 0x2c90a4, Func Offset: 0x254
	// Line 3302, Address: 0x2c90bc, Func Offset: 0x26c
	// Line 3303, Address: 0x2c90c0, Func Offset: 0x270
	// Line 3305, Address: 0x2c90c8, Func Offset: 0x278
	// Line 3306, Address: 0x2c90d8, Func Offset: 0x288
	// Line 3311, Address: 0x2c90ec, Func Offset: 0x29c
	// Line 3314, Address: 0x2c9108, Func Offset: 0x2b8
	// Line 3311, Address: 0x2c910c, Func Offset: 0x2bc
	// Line 3314, Address: 0x2c9118, Func Offset: 0x2c8
	// Line 3315, Address: 0x2c9154, Func Offset: 0x304
	// Line 3316, Address: 0x2c9158, Func Offset: 0x308
	// Line 3317, Address: 0x2c9160, Func Offset: 0x310
	// Line 3319, Address: 0x2c9164, Func Offset: 0x314
	// Line 3321, Address: 0x2c916c, Func Offset: 0x31c
	// Line 3322, Address: 0x2c917c, Func Offset: 0x32c
	// Line 3323, Address: 0x2c9190, Func Offset: 0x340
	// Line 3328, Address: 0x2c9198, Func Offset: 0x348
	// Line 3331, Address: 0x2c91b4, Func Offset: 0x364
	// Line 3328, Address: 0x2c91b8, Func Offset: 0x368
	// Line 3331, Address: 0x2c91c4, Func Offset: 0x374
	// Line 3332, Address: 0x2c91e0, Func Offset: 0x390
	// Line 3333, Address: 0x2c91e8, Func Offset: 0x398
	// Line 3332, Address: 0x2c91ec, Func Offset: 0x39c
	// Line 3335, Address: 0x2c9204, Func Offset: 0x3b4
	// Line 3337, Address: 0x2c920c, Func Offset: 0x3bc
	// Line 3338, Address: 0x2c922c, Func Offset: 0x3dc
	// Line 3339, Address: 0x2c9230, Func Offset: 0x3e0
	// Line 3338, Address: 0x2c923c, Func Offset: 0x3ec
	// Line 3339, Address: 0x2c9240, Func Offset: 0x3f0
	// Line 3342, Address: 0x2c9248, Func Offset: 0x3f8
	// Line 3346, Address: 0x2c9270, Func Offset: 0x420
	// Line 3347, Address: 0x2c9280, Func Offset: 0x430
	// Line 3349, Address: 0x2c9294, Func Offset: 0x444
	// Line 3351, Address: 0x2c929c, Func Offset: 0x44c
	// Line 3355, Address: 0x2c92a8, Func Offset: 0x458
	// Line 3356, Address: 0x2c92c0, Func Offset: 0x470
	// Line 3357, Address: 0x2c92c4, Func Offset: 0x474
	// Line 3359, Address: 0x2c92cc, Func Offset: 0x47c
	// Line 3361, Address: 0x2c92d4, Func Offset: 0x484
	// Line 3360, Address: 0x2c92d8, Func Offset: 0x488
	// Line 3361, Address: 0x2c92dc, Func Offset: 0x48c
	// Line 3362, Address: 0x2c92e0, Func Offset: 0x490
	// Line 3366, Address: 0x2c9300, Func Offset: 0x4b0
	// Line 3367, Address: 0x2c9304, Func Offset: 0x4b4
	// Line 3369, Address: 0x2c930c, Func Offset: 0x4bc
	// Line 3370, Address: 0x2c9314, Func Offset: 0x4c4
	// Line 3371, Address: 0x2c9324, Func Offset: 0x4d4
	// Line 3372, Address: 0x2c9330, Func Offset: 0x4e0
	// Line 3375, Address: 0x2c9348, Func Offset: 0x4f8
	// Func End, Address: 0x2c935c, Func Offset: 0x50c
}

// 
// Start address: 0x2c9360
void TypewriterInit()
{
	// Line 3393, Address: 0x2c9360, Func Offset: 0
	// Line 3396, Address: 0x2c9368, Func Offset: 0x8
	// Line 3397, Address: 0x2c9378, Func Offset: 0x18
	// Line 3398, Address: 0x2c9380, Func Offset: 0x20
	// Line 3400, Address: 0x2c9398, Func Offset: 0x38
	// Line 3403, Address: 0x2c939c, Func Offset: 0x3c
	// Line 3405, Address: 0x2c93ac, Func Offset: 0x4c
	// Line 3408, Address: 0x2c93c4, Func Offset: 0x64
	// Line 3409, Address: 0x2c93e0, Func Offset: 0x80
	// Line 3418, Address: 0x2c93ec, Func Offset: 0x8c
	// Line 3409, Address: 0x2c93f0, Func Offset: 0x90
	// Line 3410, Address: 0x2c93f4, Func Offset: 0x94
	// Line 3411, Address: 0x2c9408, Func Offset: 0xa8
	// Line 3410, Address: 0x2c940c, Func Offset: 0xac
	// Line 3411, Address: 0x2c9410, Func Offset: 0xb0
	// Line 3412, Address: 0x2c9420, Func Offset: 0xc0
	// Line 3411, Address: 0x2c9424, Func Offset: 0xc4
	// Line 3412, Address: 0x2c9434, Func Offset: 0xd4
	// Line 3413, Address: 0x2c9444, Func Offset: 0xe4
	// Line 3412, Address: 0x2c9448, Func Offset: 0xe8
	// Line 3413, Address: 0x2c944c, Func Offset: 0xec
	// Line 3414, Address: 0x2c945c, Func Offset: 0xfc
	// Line 3413, Address: 0x2c9460, Func Offset: 0x100
	// Line 3414, Address: 0x2c9464, Func Offset: 0x104
	// Line 3415, Address: 0x2c9474, Func Offset: 0x114
	// Line 3414, Address: 0x2c9478, Func Offset: 0x118
	// Line 3415, Address: 0x2c947c, Func Offset: 0x11c
	// Line 3416, Address: 0x2c948c, Func Offset: 0x12c
	// Line 3415, Address: 0x2c9490, Func Offset: 0x130
	// Line 3416, Address: 0x2c9494, Func Offset: 0x134
	// Line 3417, Address: 0x2c94a4, Func Offset: 0x144
	// Line 3416, Address: 0x2c94a8, Func Offset: 0x148
	// Line 3417, Address: 0x2c94b4, Func Offset: 0x154
	// Line 3418, Address: 0x2c94c4, Func Offset: 0x164
	// Line 3417, Address: 0x2c94c8, Func Offset: 0x168
	// Line 3419, Address: 0x2c94d8, Func Offset: 0x178
	// Line 3423, Address: 0x2c94e0, Func Offset: 0x180
	// Line 3424, Address: 0x2c94f8, Func Offset: 0x198
	// Line 3452, Address: 0x2c9504, Func Offset: 0x1a4
	// Func End, Address: 0x2c9510, Func Offset: 0x1b0
}

// 
// Start address: 0x2c9510
void TypewriterMain()
{
	// Line 3456, Address: 0x2c9510, Func Offset: 0
	// Line 3460, Address: 0x2c9518, Func Offset: 0x8
	// Line 3462, Address: 0x2c9530, Func Offset: 0x20
	// Line 3464, Address: 0x2c953c, Func Offset: 0x2c
	// Line 3466, Address: 0x2c9554, Func Offset: 0x44
	// Line 3467, Address: 0x2c9564, Func Offset: 0x54
	// Line 3468, Address: 0x2c9570, Func Offset: 0x60
	// Line 3469, Address: 0x2c957c, Func Offset: 0x6c
	// Line 3468, Address: 0x2c9580, Func Offset: 0x70
	// Line 3471, Address: 0x2c9588, Func Offset: 0x78
	// Line 3474, Address: 0x2c9590, Func Offset: 0x80
	// Line 3476, Address: 0x2c959c, Func Offset: 0x8c
	// Line 3478, Address: 0x2c95b4, Func Offset: 0xa4
	// Line 3479, Address: 0x2c95c4, Func Offset: 0xb4
	// Line 3480, Address: 0x2c95d0, Func Offset: 0xc0
	// Line 3991, Address: 0x2c95d8, Func Offset: 0xc8
	// Func End, Address: 0x2c95e4, Func Offset: 0xd4
}

// 
// Start address: 0x2c95f0
void TypewriterExit()
{
	_anon2* tw;
	// Line 3996, Address: 0x2c95f0, Func Offset: 0
	// Line 3997, Address: 0x2c95fc, Func Offset: 0xc
	// Line 4000, Address: 0x2c9604, Func Offset: 0x14
	// Line 4001, Address: 0x2c9614, Func Offset: 0x24
	// Line 4002, Address: 0x2c961c, Func Offset: 0x2c
	// Line 4003, Address: 0x2c9628, Func Offset: 0x38
	// Line 4002, Address: 0x2c962c, Func Offset: 0x3c
	// Line 4003, Address: 0x2c9630, Func Offset: 0x40
	// Line 4002, Address: 0x2c9634, Func Offset: 0x44
	// Line 4003, Address: 0x2c963c, Func Offset: 0x4c
	// Line 4005, Address: 0x2c9658, Func Offset: 0x68
	// Line 4006, Address: 0x2c9660, Func Offset: 0x70
	// Line 4008, Address: 0x2c9668, Func Offset: 0x78
	// Line 4010, Address: 0x2c9674, Func Offset: 0x84
	// Line 4013, Address: 0x2c967c, Func Offset: 0x8c
	// Line 4014, Address: 0x2c9684, Func Offset: 0x94
	// Line 4010, Address: 0x2c968c, Func Offset: 0x9c
	// Line 4011, Address: 0x2c9690, Func Offset: 0xa0
	// Line 4012, Address: 0x2c969c, Func Offset: 0xac
	// Line 4013, Address: 0x2c96a8, Func Offset: 0xb8
	// Line 4014, Address: 0x2c96b4, Func Offset: 0xc4
	// Line 4013, Address: 0x2c96b8, Func Offset: 0xc8
	// Line 4014, Address: 0x2c96c0, Func Offset: 0xd0
	// Line 4015, Address: 0x2c96c8, Func Offset: 0xd8
	// Line 4014, Address: 0x2c96cc, Func Offset: 0xdc
	// Line 4015, Address: 0x2c96d4, Func Offset: 0xe4
	// Line 4017, Address: 0x2c96f0, Func Offset: 0x100
	// Line 4018, Address: 0x2c96f8, Func Offset: 0x108
	// Line 4021, Address: 0x2c9724, Func Offset: 0x134
	// Line 4022, Address: 0x2c9728, Func Offset: 0x138
	// Line 4023, Address: 0x2c9738, Func Offset: 0x148
	// Line 4024, Address: 0x2c9740, Func Offset: 0x150
	// Line 4022, Address: 0x2c9744, Func Offset: 0x154
	// Line 4023, Address: 0x2c9748, Func Offset: 0x158
	// Line 4022, Address: 0x2c974c, Func Offset: 0x15c
	// Line 4023, Address: 0x2c9754, Func Offset: 0x164
	// Line 4024, Address: 0x2c9760, Func Offset: 0x170
	// Line 4026, Address: 0x2c9768, Func Offset: 0x178
	// Line 4028, Address: 0x2c9774, Func Offset: 0x184
	// Line 4029, Address: 0x2c9794, Func Offset: 0x1a4
	// Line 4031, Address: 0x2c97c4, Func Offset: 0x1d4
	// Line 4032, Address: 0x2c97c8, Func Offset: 0x1d8
	// Line 4034, Address: 0x2c97d0, Func Offset: 0x1e0
	// Line 4035, Address: 0x2c97d4, Func Offset: 0x1e4
	// Line 4037, Address: 0x2c97dc, Func Offset: 0x1ec
	// Line 4040, Address: 0x2c97e0, Func Offset: 0x1f0
	// Line 4043, Address: 0x2c97e8, Func Offset: 0x1f8
	// Line 4045, Address: 0x2c9804, Func Offset: 0x214
	// Line 4046, Address: 0x2c9810, Func Offset: 0x220
	// Line 4047, Address: 0x2c9828, Func Offset: 0x238
	// Line 4054, Address: 0x2c9830, Func Offset: 0x240
	// Line 4055, Address: 0x2c9838, Func Offset: 0x248
	// Line 4051, Address: 0x2c9840, Func Offset: 0x250
	// Line 4047, Address: 0x2c9844, Func Offset: 0x254
	// Line 4049, Address: 0x2c9848, Func Offset: 0x258
	// Line 4057, Address: 0x2c984c, Func Offset: 0x25c
	// Line 4047, Address: 0x2c9850, Func Offset: 0x260
	// Line 4049, Address: 0x2c9858, Func Offset: 0x268
	// Line 4051, Address: 0x2c9874, Func Offset: 0x284
	// Line 4052, Address: 0x2c9880, Func Offset: 0x290
	// Line 4053, Address: 0x2c9894, Func Offset: 0x2a4
	// Line 4054, Address: 0x2c98a0, Func Offset: 0x2b0
	// Line 4053, Address: 0x2c98a4, Func Offset: 0x2b4
	// Line 4054, Address: 0x2c98ac, Func Offset: 0x2bc
	// Line 4055, Address: 0x2c98b4, Func Offset: 0x2c4
	// Line 4054, Address: 0x2c98b8, Func Offset: 0x2c8
	// Line 4055, Address: 0x2c98c0, Func Offset: 0x2d0
	// Line 4056, Address: 0x2c98c8, Func Offset: 0x2d8
	// Line 4055, Address: 0x2c98cc, Func Offset: 0x2dc
	// Line 4056, Address: 0x2c98d4, Func Offset: 0x2e4
	// Line 4057, Address: 0x2c98dc, Func Offset: 0x2ec
	// Line 4056, Address: 0x2c98e0, Func Offset: 0x2f0
	// Line 4057, Address: 0x2c98e8, Func Offset: 0x2f8
	// Line 4058, Address: 0x2c98f0, Func Offset: 0x300
	// Line 4057, Address: 0x2c98f4, Func Offset: 0x304
	// Line 4058, Address: 0x2c98fc, Func Offset: 0x30c
	// Line 4059, Address: 0x2c9904, Func Offset: 0x314
	// Line 4060, Address: 0x2c9910, Func Offset: 0x320
	// Line 4061, Address: 0x2c9918, Func Offset: 0x328
	// Line 4062, Address: 0x2c9920, Func Offset: 0x330
	// Line 4063, Address: 0x2c9938, Func Offset: 0x348
	// Line 4064, Address: 0x2c9944, Func Offset: 0x354
	// Line 4063, Address: 0x2c9948, Func Offset: 0x358
	// Line 4064, Address: 0x2c9950, Func Offset: 0x360
	// Line 4065, Address: 0x2c996c, Func Offset: 0x37c
	// Line 4068, Address: 0x2c9974, Func Offset: 0x384
	// Line 4069, Address: 0x2c997c, Func Offset: 0x38c
	// Line 4070, Address: 0x2c9990, Func Offset: 0x3a0
	// Line 4073, Address: 0x2c999c, Func Offset: 0x3ac
	// Line 4074, Address: 0x2c99a4, Func Offset: 0x3b4
	// Line 4070, Address: 0x2c99a8, Func Offset: 0x3b8
	// Line 4071, Address: 0x2c99ac, Func Offset: 0x3bc
	// Line 4074, Address: 0x2c99b4, Func Offset: 0x3c4
	// Line 4076, Address: 0x2c99b8, Func Offset: 0x3c8
	// Line 4071, Address: 0x2c99bc, Func Offset: 0x3cc
	// Line 4072, Address: 0x2c99c8, Func Offset: 0x3d8
	// Line 4073, Address: 0x2c99d4, Func Offset: 0x3e4
	// Line 4072, Address: 0x2c99d8, Func Offset: 0x3e8
	// Line 4073, Address: 0x2c99e0, Func Offset: 0x3f0
	// Line 4074, Address: 0x2c99e8, Func Offset: 0x3f8
	// Line 4073, Address: 0x2c99ec, Func Offset: 0x3fc
	// Line 4074, Address: 0x2c99f4, Func Offset: 0x404
	// Line 4075, Address: 0x2c99fc, Func Offset: 0x40c
	// Line 4074, Address: 0x2c9a00, Func Offset: 0x410
	// Line 4075, Address: 0x2c9a08, Func Offset: 0x418
	// Line 4076, Address: 0x2c9a10, Func Offset: 0x420
	// Line 4075, Address: 0x2c9a14, Func Offset: 0x424
	// Line 4076, Address: 0x2c9a1c, Func Offset: 0x42c
	// Line 4104, Address: 0x2c9a24, Func Offset: 0x434
	// Line 4076, Address: 0x2c9a28, Func Offset: 0x438
	// Line 4104, Address: 0x2c9a30, Func Offset: 0x440
	// Line 4105, Address: 0x2c9a38, Func Offset: 0x448
	// Line 4109, Address: 0x2c9a44, Func Offset: 0x454
	// Func End, Address: 0x2c9a54, Func Offset: 0x464
}*/

