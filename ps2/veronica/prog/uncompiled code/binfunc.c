typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef union _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct npobj;
typedef struct _anon9;
typedef struct _anon10;
typedef struct _anon11;
typedef struct _anon12;
typedef struct _anon13;
typedef struct _anon14;


typedef void* type_0[2];
typedef unsigned int type_1[2];
typedef float type_2[3];
typedef int type_3[3];
typedef float type_4[3];
typedef float type_5[16];

struct _anon0
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon3* md2P;
	unsigned short* atrP;
};

struct _anon1
{
	void* mdata;
	unsigned int nbFrame;
	unsigned short type;
	unsigned short inp_fn;
};

struct _anon2
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon3
{
	void* p[2];
};

struct _anon4
{
	short u;
	short v;
};

struct _anon5
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

union _anon6
{
	unsigned int color;
	_anon4 tex;
	_anon5 argb;
};

struct _anon7
{
	_anon2* textures;
	unsigned int nbTexture;
};

struct _anon8
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct npobj
{
	unsigned int evalflags;
	_anon9* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon9
{
	int* vlist;
	short* plist;
	_anon11 center;
	float r;
};

struct _anon10
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon7* texP;
	_anon8* owP;
};

struct _anon11
{
	float x;
	float y;
	float z;
};

struct _anon12
{
	_anon11* points;
	_anon11* normals;
	int nbPoint;
	_anon13* meshsets;
	_anon14* mats;
	unsigned short nbMeshset;
	unsigned short nbMat;
	_anon11 center;
	float r;
};

struct _anon13
{
	unsigned short type_matId;
	unsigned short nbMesh;
	short* meshes;
	unsigned int* attrs;
	_anon11* normals;
	_anon6* vertcolor;
	_anon6* vertuv;
};

struct _anon14
{
	_anon6 diffuse;
	_anon6 specular;
	float exponent;
	unsigned int attr_texId;
	unsigned int attrflags;
};


int bhMlbBinRealize(void* bin_datP, _anon10* mlwP);
int bhBscBinRealize(_anon12* mdlP, unsigned int dat_off);
int bhCnkBinRealize(_anon9* mdlP, unsigned int dat_off);
int bhMnbBinRealize(void* bin_datP, _anon0* mnwP);

// 
// Start address: 0x2c8720
int bhMlbBinRealize(void* bin_datP, _anon10* mlwP)
{
	_anon2* namP;
	unsigned int tex_num;
	npobj* objP;
	unsigned int status;
	unsigned int obj_off;
	unsigned int tex_off;
	unsigned int obj_num;
	// Line 52, Address: 0x2c8720, Func Offset: 0
	// Line 56, Address: 0x2c8740, Func Offset: 0x20
	// Line 57, Address: 0x2c8744, Func Offset: 0x24
	// Line 58, Address: 0x2c8748, Func Offset: 0x28
	// Line 59, Address: 0x2c874c, Func Offset: 0x2c
	// Line 74, Address: 0x2c8754, Func Offset: 0x34
	// Line 63, Address: 0x2c875c, Func Offset: 0x3c
	// Line 64, Address: 0x2c8760, Func Offset: 0x40
	// Line 65, Address: 0x2c8764, Func Offset: 0x44
	// Line 66, Address: 0x2c8768, Func Offset: 0x48
	// Line 67, Address: 0x2c876c, Func Offset: 0x4c
	// Line 68, Address: 0x2c8770, Func Offset: 0x50
	// Line 70, Address: 0x2c8774, Func Offset: 0x54
	// Line 74, Address: 0x2c8778, Func Offset: 0x58
	// Line 78, Address: 0x2c8780, Func Offset: 0x60
	// Line 76, Address: 0x2c8784, Func Offset: 0x64
	// Line 79, Address: 0x2c8788, Func Offset: 0x68
	// Line 83, Address: 0x2c878c, Func Offset: 0x6c
	// Line 85, Address: 0x2c8798, Func Offset: 0x78
	// Line 86, Address: 0x2c87a8, Func Offset: 0x88
	// Line 88, Address: 0x2c87b4, Func Offset: 0x94
	// Line 90, Address: 0x2c87b8, Func Offset: 0x98
	// Line 91, Address: 0x2c87c8, Func Offset: 0xa8
	// Line 93, Address: 0x2c87d4, Func Offset: 0xb4
	// Line 96, Address: 0x2c87d8, Func Offset: 0xb8
	// Line 97, Address: 0x2c87e8, Func Offset: 0xc8
	// Line 99, Address: 0x2c87ec, Func Offset: 0xcc
	// Line 100, Address: 0x2c87f4, Func Offset: 0xd4
	// Line 102, Address: 0x2c8808, Func Offset: 0xe8
	// Line 103, Address: 0x2c8814, Func Offset: 0xf4
	// Line 104, Address: 0x2c881c, Func Offset: 0xfc
	// Line 106, Address: 0x2c8820, Func Offset: 0x100
	// Line 108, Address: 0x2c882c, Func Offset: 0x10c
	// Line 111, Address: 0x2c8830, Func Offset: 0x110
	// Line 115, Address: 0x2c883c, Func Offset: 0x11c
	// Line 116, Address: 0x2c8844, Func Offset: 0x124
	// Line 119, Address: 0x2c8854, Func Offset: 0x134
	// Line 120, Address: 0x2c8858, Func Offset: 0x138
	// Line 121, Address: 0x2c885c, Func Offset: 0x13c
	// Line 122, Address: 0x2c8864, Func Offset: 0x144
	// Line 123, Address: 0x2c8868, Func Offset: 0x148
	// Line 122, Address: 0x2c886c, Func Offset: 0x14c
	// Line 123, Address: 0x2c8874, Func Offset: 0x154
	// Line 128, Address: 0x2c8880, Func Offset: 0x160
	// Line 127, Address: 0x2c889c, Func Offset: 0x17c
	// Line 128, Address: 0x2c88a0, Func Offset: 0x180
	// Func End, Address: 0x2c88a8, Func Offset: 0x188
}

// 
// Start address: 0x2c88b0
int bhBscBinRealize(_anon12* mdlP, unsigned int dat_off)
{
	unsigned int i;
	_anon13* mshP;
	// Line 144, Address: 0x2c88b0, Func Offset: 0
	// Line 146, Address: 0x2c88c4, Func Offset: 0x14
	// Line 148, Address: 0x2c88d0, Func Offset: 0x20
	// Line 149, Address: 0x2c88e0, Func Offset: 0x30
	// Line 150, Address: 0x2c88e8, Func Offset: 0x38
	// Line 151, Address: 0x2c88f8, Func Offset: 0x48
	// Line 152, Address: 0x2c8900, Func Offset: 0x50
	// Line 153, Address: 0x2c8910, Func Offset: 0x60
	// Line 154, Address: 0x2c8918, Func Offset: 0x68
	// Line 155, Address: 0x2c8928, Func Offset: 0x78
	// Line 157, Address: 0x2c8930, Func Offset: 0x80
	// Line 158, Address: 0x2c893c, Func Offset: 0x8c
	// Line 159, Address: 0x2c8948, Func Offset: 0x98
	// Line 161, Address: 0x2c8950, Func Offset: 0xa0
	// Line 162, Address: 0x2c895c, Func Offset: 0xac
	// Line 164, Address: 0x2c8968, Func Offset: 0xb8
	// Line 166, Address: 0x2c8970, Func Offset: 0xc0
	// Line 167, Address: 0x2c897c, Func Offset: 0xcc
	// Line 169, Address: 0x2c8988, Func Offset: 0xd8
	// Line 171, Address: 0x2c8990, Func Offset: 0xe0
	// Line 172, Address: 0x2c899c, Func Offset: 0xec
	// Line 174, Address: 0x2c89a8, Func Offset: 0xf8
	// Line 176, Address: 0x2c89b0, Func Offset: 0x100
	// Line 177, Address: 0x2c89bc, Func Offset: 0x10c
	// Line 179, Address: 0x2c89c8, Func Offset: 0x118
	// Line 180, Address: 0x2c89d0, Func Offset: 0x120
	// Line 184, Address: 0x2c89e8, Func Offset: 0x138
	// Line 186, Address: 0x2c89ec, Func Offset: 0x13c
	// Func End, Address: 0x2c89f4, Func Offset: 0x144
}

// 
// Start address: 0x2c8a00
int bhCnkBinRealize(_anon9* mdlP, unsigned int dat_off)
{
	// Line 199, Address: 0x2c8a00, Func Offset: 0
	// Line 200, Address: 0x2c8a1c, Func Offset: 0x1c
	// Line 202, Address: 0x2c8a24, Func Offset: 0x24
	// Line 205, Address: 0x2c8a34, Func Offset: 0x34
	// Line 213, Address: 0x2c8a3c, Func Offset: 0x3c
	// Line 214, Address: 0x2c8a4c, Func Offset: 0x4c
	// Line 217, Address: 0x2c8a54, Func Offset: 0x54
	// Line 219, Address: 0x2c8a58, Func Offset: 0x58
	// Func End, Address: 0x2c8a60, Func Offset: 0x60
}

// 
// Start address: 0x2c8a60
int bhMnbBinRealize(void* bin_datP, _anon0* mnwP)
{
	int i;
	void* dat_topP;
	_anon3* md2P;
	_anon1* mtnP;
	// Line 237, Address: 0x2c8a60, Func Offset: 0
	// Line 238, Address: 0x2c8a64, Func Offset: 0x4
	// Line 248, Address: 0x2c8a68, Func Offset: 0x8
	// Line 237, Address: 0x2c8a6c, Func Offset: 0xc
	// Line 238, Address: 0x2c8a70, Func Offset: 0x10
	// Line 239, Address: 0x2c8a74, Func Offset: 0x14
	// Line 241, Address: 0x2c8a80, Func Offset: 0x20
	// Line 242, Address: 0x2c8a88, Func Offset: 0x28
	// Line 243, Address: 0x2c8a90, Func Offset: 0x30
	// Line 244, Address: 0x2c8a98, Func Offset: 0x38
	// Line 245, Address: 0x2c8a9c, Func Offset: 0x3c
	// Line 246, Address: 0x2c8aa0, Func Offset: 0x40
	// Line 248, Address: 0x2c8aa4, Func Offset: 0x44
	// Line 249, Address: 0x2c8ab0, Func Offset: 0x50
	// Line 251, Address: 0x2c8ab8, Func Offset: 0x58
	// Line 252, Address: 0x2c8ac4, Func Offset: 0x64
	// Line 253, Address: 0x2c8ad8, Func Offset: 0x78
	// Line 254, Address: 0x2c8ae0, Func Offset: 0x80
	// Line 255, Address: 0x2c8af4, Func Offset: 0x94
	// Line 256, Address: 0x2c8b00, Func Offset: 0xa0
	// Line 260, Address: 0x2c8b18, Func Offset: 0xb8
	// Func End, Address: 0x2c8b20, Func Offset: 0xc0
}

