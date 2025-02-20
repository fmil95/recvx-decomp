typedef struct tagVU1_STRIP_BUF;
typedef struct tagVU1_PRIM_BUF;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct tagVU1_COLOR;

typedef void(*type_0)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
typedef void(*type_2)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
typedef void(*type_12)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
typedef void(*type_14)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
typedef void(*type_17)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
typedef void(*type_18)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);

typedef float type_1[4][2];
typedef void(*type_3)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*)[11];
typedef float type_4[16];
typedef _anon4 type_5[12];
typedef float type_6[3];
typedef _anon0 type_7[2];
typedef unsigned char type_8[16384];
typedef float type_9[4][1];
typedef float type_10[4];
typedef _anon6 type_11[5];
typedef float type_13[4];
typedef float type_15[4][4];
typedef tagVU1_PRIM_BUF type_16[16];

struct tagVU1_STRIP_BUF
{
	float fU;
	float fV;
	float fPad0;
	float fPad1;
	float fIr;
	float fIg;
	float fIb;
	float fA;
	float fVx;
	float fVy;
	float fVz;
	float fFog;
	float fSx;
	float fSy;
	float fIz;
	float fNz;
};

struct tagVU1_PRIM_BUF
{
	float fS;
	float fT;
	float fQ;
	unsigned int ulKick;
	float fR;
	float fG;
	float fB;
	float fA;
	float fX;
	float fY;
	float fZ;
	float fF;
};

struct _anon0
{
	_anon4 node[12];
	unsigned int nodeNum;
	float pad[3];
};

struct _anon1
{
	float x;
	float y;
	float z;
	float w;
};

struct _anon2
{
	_anon0 triangle;
	_anon0 narray[2];
	_anon0* in;
	_anon0* out;
	unsigned int rotflag;
	unsigned int flipflag;
};

struct _anon3
{
	float x;
	float y;
	float z;
};

struct _anon4
{
	float vertex[4];
	float color[4];
	float texUV[4];
	float clipV[4];
};

struct _anon5
{
	_anon6 plane[5];
	unsigned int planeNum;
};

struct _anon6
{
	unsigned int xyzflag;
	unsigned int clipmask;
};

struct tagVU1_COLOR
{
	float fR;
	float fG;
	float fB;
	float fA;
};

void(*pColorCalcFuncTbl)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*)[11];
tagVU1_COLOR vu1Diffuse;
tagVU1_COLOR vu1Specula;
tagVU1_COLOR vu1Ambient;
float fVu1AlphaRatio;
_anon5 planeset;
_anon2 scissorflip;
_anon4 node;
float _fNaViwClipFar;
float _fNaViwClipNear;
float fVu1Projection;
float ClipMatrix2[4][4];
float fVu1InvNearClip;
float fVu1NearClip;
float fVu1FarClip;
float fVu1OffsetY;
float fVu1OffsetX;
float fVu1AspectH;
float fVu1AspectW;
tagVU1_PRIM_BUF vu1ScessorBuf[16];
unsigned char Ps2_DRAW_TMP[16384];
float Ps2AddPrimPrio;

void vu1SetScreenProjection(float fProjection);
void vu1SetNearFarClip(float fNear, float fFar);
void vu1SetScreenOffset(float fOffsetX, float fOffsetY);
void vu1SetScreenAspect(float fAspectW, float fAspectH);
void vu1SetDiffuseMaterial(tagVU1_COLOR* pDiffuse);
void vu1SetSpeculaMaterial(tagVU1_COLOR* pSpecula);
void vu1SetAmbient(tagVU1_COLOR* pAmbient);
void vu1SetAlphaRatio(float fAlpha);
void InitNodeArraySet(_anon2* scissor);
void InitScissorPlane(_anon5* sp);
void _Init_ScissorSystem();
int _Clip_ViewVolume(float* clip, float local_clip[4], float* vertex);
void PushTriangleNodeArray(_anon2* scissor);
void ResetNodeArraySet(_anon2* scissor);
void ScissorTriangle(_anon2* scissor, _anon5* plane_set);
int _Check_DisplayAreaPoint(_anon3* vec);
void DrawScissorPolygonOpaque(_anon2* scissor, unsigned long ulType);
void vu1DrawTriangleStripOpaqueSingle(unsigned long ulType, tagVU1_STRIP_BUF* pStripTop, unsigned short usStripMax, unsigned short usMode);
void vu1DrawTriangleStripOpaqueDouble(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode);
void vu1DrawTriangleStripTransSingle(unsigned long ulType, tagVU1_STRIP_BUF* pStripTop, unsigned short usStripMax, unsigned short usMode);
int _Clip_Screen(float* clip);
void vu1DrawTriangleStripTransDouble(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode);
void vu1GetVertexColor(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim);
void vu1GetVertexColorCM(tagVU1_PRIM_BUF* pPrim);
void vu1GetVertexColorIgnore(tagVU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDif(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifAmb(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe1(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe2(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe3(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe1Amb(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe2Amb(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim);
void vu1GetVertexColorDifSpe3Amb(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim);
void vu1RotTransStripBuf(float pMatrix[16], _anon3* pVector, tagVU1_STRIP_BUF* pBuf);
void vu1DrawTriangleStripTransDoubleI(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode);
void DrawScissorPolygonTrans1P(_anon2* scissor, unsigned long ulType);
void vu1DrawTriangleStripTransDouble1P(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode);

// 
// Start address: 0x2d38c0
void vu1SetScreenProjection(float fProjection)
{
	// Line 200, Address: 0x2d38c0, Func Offset: 0
	// Line 206, Address: 0x2d38c8, Func Offset: 0x8
	// Line 207, Address: 0x2d38d0, Func Offset: 0x10
	// Line 208, Address: 0x2d38d4, Func Offset: 0x14
	// Line 216, Address: 0x2d38d8, Func Offset: 0x18
	// Func End, Address: 0x2d38fc, Func Offset: 0x3c
}

// 
// Start address: 0x2d3900
void vu1SetNearFarClip(float fNear, float fFar)
{
	// Line 233, Address: 0x2d3900, Func Offset: 0
	// Line 234, Address: 0x2d3908, Func Offset: 0x8
	// Line 236, Address: 0x2d3910, Func Offset: 0x10
	// Line 241, Address: 0x2d3930, Func Offset: 0x30
	// Line 242, Address: 0x2d3934, Func Offset: 0x34
	// Line 243, Address: 0x2d3938, Func Offset: 0x38
	// Line 244, Address: 0x2d393c, Func Offset: 0x3c
	// Line 245, Address: 0x2d3940, Func Offset: 0x40
	// Line 246, Address: 0x2d3944, Func Offset: 0x44
	// Line 253, Address: 0x2d3948, Func Offset: 0x48
	// Func End, Address: 0x2d396c, Func Offset: 0x6c
}

// 
// Start address: 0x2d3970
void vu1SetScreenOffset(float fOffsetX, float fOffsetY)
{
	// Line 272, Address: 0x2d3970, Func Offset: 0
	// Line 273, Address: 0x2d3978, Func Offset: 0x8
	// Line 278, Address: 0x2d3980, Func Offset: 0x10
	// Line 279, Address: 0x2d3984, Func Offset: 0x14
	// Line 280, Address: 0x2d3988, Func Offset: 0x18
	// Line 281, Address: 0x2d398c, Func Offset: 0x1c
	// Line 282, Address: 0x2d3990, Func Offset: 0x20
	// Line 289, Address: 0x2d3994, Func Offset: 0x24
	// Func End, Address: 0x2d399c, Func Offset: 0x2c
}

// 
// Start address: 0x2d39a0
void vu1SetScreenAspect(float fAspectW, float fAspectH)
{
	// Line 306, Address: 0x2d39a0, Func Offset: 0
	// Line 307, Address: 0x2d39a8, Func Offset: 0x8
	// Line 313, Address: 0x2d39b0, Func Offset: 0x10
	// Line 314, Address: 0x2d39b4, Func Offset: 0x14
	// Line 315, Address: 0x2d39b8, Func Offset: 0x18
	// Line 316, Address: 0x2d39bc, Func Offset: 0x1c
	// Line 317, Address: 0x2d39c0, Func Offset: 0x20
	// Line 324, Address: 0x2d39c4, Func Offset: 0x24
	// Func End, Address: 0x2d39cc, Func Offset: 0x2c
}

// 
// Start address: 0x2d39d0
void vu1SetDiffuseMaterial(tagVU1_COLOR* pDiffuse)
{
	// Line 340, Address: 0x2d39d0, Func Offset: 0
	// Line 341, Address: 0x2d39e8, Func Offset: 0x18
	// Line 342, Address: 0x2d39f8, Func Offset: 0x28
	// Line 349, Address: 0x2d3a08, Func Offset: 0x38
	// Line 350, Address: 0x2d3a0c, Func Offset: 0x3c
	// Line 351, Address: 0x2d3a10, Func Offset: 0x40
	// Line 352, Address: 0x2d3a14, Func Offset: 0x44
	// Line 353, Address: 0x2d3a18, Func Offset: 0x48
	// Line 354, Address: 0x2d3a1c, Func Offset: 0x4c
	// Line 355, Address: 0x2d3a20, Func Offset: 0x50
	// Line 356, Address: 0x2d3a24, Func Offset: 0x54
	// Line 357, Address: 0x2d3a28, Func Offset: 0x58
	// Line 364, Address: 0x2d3a2c, Func Offset: 0x5c
	// Func End, Address: 0x2d3a34, Func Offset: 0x64
}

// 
// Start address: 0x2d3a40
void vu1SetSpeculaMaterial(tagVU1_COLOR* pSpecula)
{
	// Line 380, Address: 0x2d3a40, Func Offset: 0
	// Line 381, Address: 0x2d3a58, Func Offset: 0x18
	// Line 382, Address: 0x2d3a68, Func Offset: 0x28
	// Line 388, Address: 0x2d3a78, Func Offset: 0x38
	// Line 389, Address: 0x2d3a7c, Func Offset: 0x3c
	// Line 390, Address: 0x2d3a80, Func Offset: 0x40
	// Line 391, Address: 0x2d3a84, Func Offset: 0x44
	// Line 392, Address: 0x2d3a88, Func Offset: 0x48
	// Line 393, Address: 0x2d3a8c, Func Offset: 0x4c
	// Line 394, Address: 0x2d3a90, Func Offset: 0x50
	// Line 395, Address: 0x2d3a94, Func Offset: 0x54
	// Line 402, Address: 0x2d3a98, Func Offset: 0x58
	// Func End, Address: 0x2d3aa0, Func Offset: 0x60
}

// 
// Start address: 0x2d3aa0
void vu1SetAmbient(tagVU1_COLOR* pAmbient)
{
	// Line 417, Address: 0x2d3aa0, Func Offset: 0
	// Line 418, Address: 0x2d3aac, Func Offset: 0xc
	// Line 419, Address: 0x2d3ab8, Func Offset: 0x18
	// Line 431, Address: 0x2d3ac4, Func Offset: 0x24
	// Func End, Address: 0x2d3acc, Func Offset: 0x2c
}

// 
// Start address: 0x2d3ad0
void vu1SetAlphaRatio(float fAlpha)
{
	// Line 446, Address: 0x2d3ad0, Func Offset: 0
	// Line 448, Address: 0x2d3ae4, Func Offset: 0x14
	// Line 451, Address: 0x2d3aec, Func Offset: 0x1c
	// Line 452, Address: 0x2d3af0, Func Offset: 0x20
	// Line 459, Address: 0x2d3af4, Func Offset: 0x24
	// Func End, Address: 0x2d3afc, Func Offset: 0x2c
}

// 
// Start address: 0x2d3ff0
void InitNodeArraySet(_anon2* scissor)
{
	// Line 482, Address: 0x2d3ff0, Func Offset: 0
	// Line 483, Address: 0x2d3ff4, Func Offset: 0x4
	// Line 484, Address: 0x2d3ff8, Func Offset: 0x8
	// Line 485, Address: 0x2d3ffc, Func Offset: 0xc
	// Line 486, Address: 0x2d4000, Func Offset: 0x10
	// Line 487, Address: 0x2d4004, Func Offset: 0x14
	// Line 488, Address: 0x2d4008, Func Offset: 0x18
	// Line 489, Address: 0x2d400c, Func Offset: 0x1c
	// Line 490, Address: 0x2d4010, Func Offset: 0x20
	// Line 491, Address: 0x2d4014, Func Offset: 0x24
	// Line 495, Address: 0x2d4018, Func Offset: 0x28
	// Func End, Address: 0x2d4020, Func Offset: 0x30
}

// 
// Start address: 0x2d4020
void InitScissorPlane(_anon5* sp)
{
	// Line 503, Address: 0x2d4020, Func Offset: 0
	// Line 504, Address: 0x2d4028, Func Offset: 0x8
	// Line 505, Address: 0x2d4030, Func Offset: 0x10
	// Line 508, Address: 0x2d4038, Func Offset: 0x18
	// Line 509, Address: 0x2d4040, Func Offset: 0x20
	// Line 510, Address: 0x2d4048, Func Offset: 0x28
	// Line 511, Address: 0x2d4050, Func Offset: 0x30
	// Line 512, Address: 0x2d4058, Func Offset: 0x38
	// Line 513, Address: 0x2d4060, Func Offset: 0x40
	// Line 514, Address: 0x2d4068, Func Offset: 0x48
	// Line 516, Address: 0x2d4070, Func Offset: 0x50
	// Func End, Address: 0x2d4078, Func Offset: 0x58
}

// 
// Start address: 0x2d4080
void _Init_ScissorSystem()
{
	// Line 520, Address: 0x2d4080, Func Offset: 0
	// Line 521, Address: 0x2d4084, Func Offset: 0x4
	// Line 520, Address: 0x2d4088, Func Offset: 0x8
	// Line 521, Address: 0x2d408c, Func Offset: 0xc
	// Line 522, Address: 0x2d4094, Func Offset: 0x14
	// Line 523, Address: 0x2d40a0, Func Offset: 0x20
	// Func End, Address: 0x2d40ac, Func Offset: 0x2c
}

// 
// Start address: 0x2d40b0
int _Clip_ViewVolume(float* clip, float local_clip[4], float* vertex)
{
	int ret;
	// Line 553, Address: 0x2d40b0, Func Offset: 0
	// Line 554, Address: 0x2d40b4, Func Offset: 0x4
	// Line 555, Address: 0x2d40b8, Func Offset: 0x8
	// Line 556, Address: 0x2d40bc, Func Offset: 0xc
	// Line 557, Address: 0x2d40c0, Func Offset: 0x10
	// Line 558, Address: 0x2d40c4, Func Offset: 0x14
	// Line 559, Address: 0x2d40c8, Func Offset: 0x18
	// Line 560, Address: 0x2d40cc, Func Offset: 0x1c
	// Line 561, Address: 0x2d40d0, Func Offset: 0x20
	// Line 562, Address: 0x2d40d4, Func Offset: 0x24
	// Line 563, Address: 0x2d40d8, Func Offset: 0x28
	// Line 564, Address: 0x2d40dc, Func Offset: 0x2c
	// Line 568, Address: 0x2d40e0, Func Offset: 0x30
	// Func End, Address: 0x2d40e8, Func Offset: 0x38
}

// 
// Start address: 0x2d40f0
void PushTriangleNodeArray(_anon2* scissor)
{
	// Line 624, Address: 0x2d40f0, Func Offset: 0
	// Line 625, Address: 0x2d40f8, Func Offset: 0x8
	// Line 626, Address: 0x2d40fc, Func Offset: 0xc
	// Line 627, Address: 0x2d4110, Func Offset: 0x20
	// Line 628, Address: 0x2d4114, Func Offset: 0x24
	// Line 629, Address: 0x2d4118, Func Offset: 0x28
	// Line 630, Address: 0x2d411c, Func Offset: 0x2c
	// Line 631, Address: 0x2d4120, Func Offset: 0x30
	// Line 632, Address: 0x2d4124, Func Offset: 0x34
	// Line 633, Address: 0x2d4128, Func Offset: 0x38
	// Line 634, Address: 0x2d412c, Func Offset: 0x3c
	// Line 635, Address: 0x2d4130, Func Offset: 0x40
	// Line 636, Address: 0x2d4134, Func Offset: 0x44
	// Line 637, Address: 0x2d4138, Func Offset: 0x48
	// Line 638, Address: 0x2d413c, Func Offset: 0x4c
	// Line 639, Address: 0x2d4140, Func Offset: 0x50
	// Line 640, Address: 0x2d4148, Func Offset: 0x58
	// Line 641, Address: 0x2d414c, Func Offset: 0x5c
	// Line 647, Address: 0x2d4150, Func Offset: 0x60
	// Func End, Address: 0x2d4158, Func Offset: 0x68
}

// 
// Start address: 0x2d4160
void ResetNodeArraySet(_anon2* scissor)
{
	// Line 661, Address: 0x2d4160, Func Offset: 0
	// Line 662, Address: 0x2d4164, Func Offset: 0x4
	// Line 663, Address: 0x2d4168, Func Offset: 0x8
	// Line 664, Address: 0x2d416c, Func Offset: 0xc
	// Line 665, Address: 0x2d4170, Func Offset: 0x10
	// Line 666, Address: 0x2d4174, Func Offset: 0x14
	// Line 667, Address: 0x2d4178, Func Offset: 0x18
	// Line 668, Address: 0x2d417c, Func Offset: 0x1c
	// Line 672, Address: 0x2d4180, Func Offset: 0x20
	// Func End, Address: 0x2d4188, Func Offset: 0x28
}

// 
// Start address: 0x2d4190
void ScissorTriangle(_anon2* scissor, _anon5* plane_set)
{
	int n;
	_anon4 interN;
	_anon4* nextN;
	_anon4* currN;
	_anon0* outarray;
	_anon0* inarray;
	float sgn;
	int xyz;
	int mask;
	int clip;
	int j;
	int i;
	// Line 943, Address: 0x2d4190, Func Offset: 0
	// Line 894, Address: 0x2d4194, Func Offset: 0x4
	// Line 942, Address: 0x2d4198, Func Offset: 0x8
	// Line 949, Address: 0x2d419c, Func Offset: 0xc
	// Line 954, Address: 0x2d41a4, Func Offset: 0x14
	// Line 955, Address: 0x2d41b0, Func Offset: 0x20
	// Line 956, Address: 0x2d41b4, Func Offset: 0x24
	// Line 957, Address: 0x2d41c8, Func Offset: 0x38
	// Line 958, Address: 0x2d41cc, Func Offset: 0x3c
	// Line 959, Address: 0x2d41d0, Func Offset: 0x40
	// Line 960, Address: 0x2d41d4, Func Offset: 0x44
	// Line 961, Address: 0x2d41d8, Func Offset: 0x48
	// Line 962, Address: 0x2d41dc, Func Offset: 0x4c
	// Line 963, Address: 0x2d41e0, Func Offset: 0x50
	// Line 964, Address: 0x2d41e4, Func Offset: 0x54
	// Line 965, Address: 0x2d41e8, Func Offset: 0x58
	// Line 966, Address: 0x2d41ec, Func Offset: 0x5c
	// Line 967, Address: 0x2d41f0, Func Offset: 0x60
	// Line 968, Address: 0x2d41f4, Func Offset: 0x64
	// Line 969, Address: 0x2d41f8, Func Offset: 0x68
	// Line 970, Address: 0x2d41fc, Func Offset: 0x6c
	// Line 972, Address: 0x2d4200, Func Offset: 0x70
	// Line 975, Address: 0x2d4208, Func Offset: 0x78
	// Line 976, Address: 0x2d420c, Func Offset: 0x7c
	// Line 977, Address: 0x2d4210, Func Offset: 0x80
	// Line 978, Address: 0x2d4214, Func Offset: 0x84
	// Line 979, Address: 0x2d4228, Func Offset: 0x98
	// Line 980, Address: 0x2d422c, Func Offset: 0x9c
	// Line 981, Address: 0x2d4230, Func Offset: 0xa0
	// Line 982, Address: 0x2d4238, Func Offset: 0xa8
	// Line 983, Address: 0x2d423c, Func Offset: 0xac
	// Line 985, Address: 0x2d4240, Func Offset: 0xb0
	// Line 986, Address: 0x2d4254, Func Offset: 0xc4
	// Line 987, Address: 0x2d4258, Func Offset: 0xc8
	// Line 991, Address: 0x2d425c, Func Offset: 0xcc
	// Line 992, Address: 0x2d4260, Func Offset: 0xd0
	// Line 993, Address: 0x2d4264, Func Offset: 0xd4
	// Line 994, Address: 0x2d4268, Func Offset: 0xd8
	// Line 995, Address: 0x2d426c, Func Offset: 0xdc
	// Line 996, Address: 0x2d4270, Func Offset: 0xe0
	// Line 997, Address: 0x2d4274, Func Offset: 0xe4
	// Line 998, Address: 0x2d4278, Func Offset: 0xe8
	// Line 999, Address: 0x2d427c, Func Offset: 0xec
	// Line 1000, Address: 0x2d4280, Func Offset: 0xf0
	// Line 1002, Address: 0x2d4284, Func Offset: 0xf4
	// Line 1003, Address: 0x2d428c, Func Offset: 0xfc
	// Line 1006, Address: 0x2d4294, Func Offset: 0x104
	// Line 1007, Address: 0x2d4298, Func Offset: 0x108
	// Line 1008, Address: 0x2d42ac, Func Offset: 0x11c
	// Line 1009, Address: 0x2d42b0, Func Offset: 0x120
	// Line 1010, Address: 0x2d42b4, Func Offset: 0x124
	// Line 1011, Address: 0x2d42b8, Func Offset: 0x128
	// Line 1012, Address: 0x2d42bc, Func Offset: 0x12c
	// Line 1013, Address: 0x2d42c0, Func Offset: 0x130
	// Line 1014, Address: 0x2d42c4, Func Offset: 0x134
	// Line 1015, Address: 0x2d42c8, Func Offset: 0x138
	// Line 1016, Address: 0x2d42cc, Func Offset: 0x13c
	// Line 1017, Address: 0x2d42d0, Func Offset: 0x140
	// Line 1020, Address: 0x2d42d4, Func Offset: 0x144
	// Line 1021, Address: 0x2d42f4, Func Offset: 0x164
	// Line 1023, Address: 0x2d4310, Func Offset: 0x180
	// Line 1024, Address: 0x2d4318, Func Offset: 0x188
	// Line 1025, Address: 0x2d431c, Func Offset: 0x18c
	// Line 1026, Address: 0x2d4320, Func Offset: 0x190
	// Line 1027, Address: 0x2d4328, Func Offset: 0x198
	// Line 1028, Address: 0x2d432c, Func Offset: 0x19c
	// Line 1029, Address: 0x2d4330, Func Offset: 0x1a0
	// Line 1030, Address: 0x2d4334, Func Offset: 0x1a4
	// Line 1031, Address: 0x2d4338, Func Offset: 0x1a8
	// Line 1032, Address: 0x2d433c, Func Offset: 0x1ac
	// Line 1033, Address: 0x2d4340, Func Offset: 0x1b0
	// Line 1034, Address: 0x2d4344, Func Offset: 0x1b4
	// Line 1035, Address: 0x2d4348, Func Offset: 0x1b8
	// Line 1036, Address: 0x2d434c, Func Offset: 0x1bc
	// Line 1037, Address: 0x2d4350, Func Offset: 0x1c0
	// Line 1038, Address: 0x2d4358, Func Offset: 0x1c8
	// Line 1039, Address: 0x2d435c, Func Offset: 0x1cc
	// Line 1041, Address: 0x2d4360, Func Offset: 0x1d0
	// Line 1044, Address: 0x2d4368, Func Offset: 0x1d8
	// Line 1045, Address: 0x2d436c, Func Offset: 0x1dc
	// Line 1046, Address: 0x2d4370, Func Offset: 0x1e0
	// Line 1047, Address: 0x2d4374, Func Offset: 0x1e4
	// Line 1048, Address: 0x2d4378, Func Offset: 0x1e8
	// Line 1049, Address: 0x2d437c, Func Offset: 0x1ec
	// Line 1050, Address: 0x2d4380, Func Offset: 0x1f0
	// Line 1051, Address: 0x2d4384, Func Offset: 0x1f4
	// Line 1052, Address: 0x2d4388, Func Offset: 0x1f8
	// Line 1053, Address: 0x2d438c, Func Offset: 0x1fc
	// Line 1054, Address: 0x2d4390, Func Offset: 0x200
	// Line 1055, Address: 0x2d4394, Func Offset: 0x204
	// Line 1056, Address: 0x2d4398, Func Offset: 0x208
	// Line 1057, Address: 0x2d439c, Func Offset: 0x20c
	// Line 1058, Address: 0x2d43a0, Func Offset: 0x210
	// Line 1059, Address: 0x2d43a4, Func Offset: 0x214
	// Line 1060, Address: 0x2d43a8, Func Offset: 0x218
	// Line 1061, Address: 0x2d43ac, Func Offset: 0x21c
	// Line 1062, Address: 0x2d43b0, Func Offset: 0x220
	// Line 1063, Address: 0x2d43b4, Func Offset: 0x224
	// Line 1064, Address: 0x2d43b8, Func Offset: 0x228
	// Line 1065, Address: 0x2d43bc, Func Offset: 0x22c
	// Line 1066, Address: 0x2d43c0, Func Offset: 0x230
	// Line 1067, Address: 0x2d43c4, Func Offset: 0x234
	// Line 1068, Address: 0x2d43c8, Func Offset: 0x238
	// Line 1069, Address: 0x2d43cc, Func Offset: 0x23c
	// Line 1070, Address: 0x2d43d0, Func Offset: 0x240
	// Line 1071, Address: 0x2d43d4, Func Offset: 0x244
	// Line 1072, Address: 0x2d43d8, Func Offset: 0x248
	// Line 1073, Address: 0x2d43dc, Func Offset: 0x24c
	// Line 1077, Address: 0x2d43e0, Func Offset: 0x250
	// Line 1078, Address: 0x2d43e4, Func Offset: 0x254
	// Line 1079, Address: 0x2d43f8, Func Offset: 0x268
	// Line 1080, Address: 0x2d43fc, Func Offset: 0x26c
	// Line 1081, Address: 0x2d4400, Func Offset: 0x270
	// Line 1082, Address: 0x2d4404, Func Offset: 0x274
	// Line 1083, Address: 0x2d4408, Func Offset: 0x278
	// Line 1084, Address: 0x2d440c, Func Offset: 0x27c
	// Line 1085, Address: 0x2d4410, Func Offset: 0x280
	// Line 1086, Address: 0x2d4414, Func Offset: 0x284
	// Line 1087, Address: 0x2d4418, Func Offset: 0x288
	// Line 1088, Address: 0x2d441c, Func Offset: 0x28c
	// Line 1089, Address: 0x2d4420, Func Offset: 0x290
	// Line 1092, Address: 0x2d4424, Func Offset: 0x294
	// Line 1093, Address: 0x2d4428, Func Offset: 0x298
	// Line 1094, Address: 0x2d442c, Func Offset: 0x29c
	// Line 1095, Address: 0x2d4440, Func Offset: 0x2b0
	// Line 1096, Address: 0x2d4444, Func Offset: 0x2b4
	// Line 1097, Address: 0x2d4448, Func Offset: 0x2b8
	// Line 1098, Address: 0x2d444c, Func Offset: 0x2bc
	// Line 1099, Address: 0x2d4450, Func Offset: 0x2c0
	// Line 1100, Address: 0x2d4454, Func Offset: 0x2c4
	// Line 1101, Address: 0x2d4458, Func Offset: 0x2c8
	// Line 1102, Address: 0x2d445c, Func Offset: 0x2cc
	// Line 1103, Address: 0x2d4460, Func Offset: 0x2d0
	// Line 1104, Address: 0x2d4464, Func Offset: 0x2d4
	// Line 1107, Address: 0x2d4468, Func Offset: 0x2d8
	// Line 1109, Address: 0x2d4488, Func Offset: 0x2f8
	// Line 1110, Address: 0x2d4490, Func Offset: 0x300
	// Line 1111, Address: 0x2d4494, Func Offset: 0x304
	// Line 1112, Address: 0x2d4498, Func Offset: 0x308
	// Line 1113, Address: 0x2d44a0, Func Offset: 0x310
	// Line 1114, Address: 0x2d44a4, Func Offset: 0x314
	// Line 1115, Address: 0x2d44a8, Func Offset: 0x318
	// Line 1116, Address: 0x2d44ac, Func Offset: 0x31c
	// Line 1117, Address: 0x2d44b0, Func Offset: 0x320
	// Line 1118, Address: 0x2d44b4, Func Offset: 0x324
	// Line 1119, Address: 0x2d44b8, Func Offset: 0x328
	// Line 1120, Address: 0x2d44bc, Func Offset: 0x32c
	// Line 1121, Address: 0x2d44c0, Func Offset: 0x330
	// Line 1122, Address: 0x2d44c4, Func Offset: 0x334
	// Line 1123, Address: 0x2d44c8, Func Offset: 0x338
	// Line 1124, Address: 0x2d44d0, Func Offset: 0x340
	// Line 1125, Address: 0x2d44d4, Func Offset: 0x344
	// Line 1127, Address: 0x2d44d8, Func Offset: 0x348
	// Line 1130, Address: 0x2d44e0, Func Offset: 0x350
	// Line 1131, Address: 0x2d44e4, Func Offset: 0x354
	// Line 1132, Address: 0x2d44e8, Func Offset: 0x358
	// Line 1133, Address: 0x2d44ec, Func Offset: 0x35c
	// Line 1134, Address: 0x2d44f0, Func Offset: 0x360
	// Line 1135, Address: 0x2d44f4, Func Offset: 0x364
	// Line 1136, Address: 0x2d44f8, Func Offset: 0x368
	// Line 1137, Address: 0x2d44fc, Func Offset: 0x36c
	// Line 1138, Address: 0x2d4500, Func Offset: 0x370
	// Line 1139, Address: 0x2d4504, Func Offset: 0x374
	// Line 1140, Address: 0x2d4508, Func Offset: 0x378
	// Line 1141, Address: 0x2d450c, Func Offset: 0x37c
	// Line 1142, Address: 0x2d4510, Func Offset: 0x380
	// Line 1143, Address: 0x2d4514, Func Offset: 0x384
	// Line 1144, Address: 0x2d4518, Func Offset: 0x388
	// Line 1145, Address: 0x2d451c, Func Offset: 0x38c
	// Line 1146, Address: 0x2d4520, Func Offset: 0x390
	// Line 1147, Address: 0x2d4524, Func Offset: 0x394
	// Line 1148, Address: 0x2d4528, Func Offset: 0x398
	// Line 1149, Address: 0x2d452c, Func Offset: 0x39c
	// Line 1150, Address: 0x2d4530, Func Offset: 0x3a0
	// Line 1151, Address: 0x2d4534, Func Offset: 0x3a4
	// Line 1152, Address: 0x2d4538, Func Offset: 0x3a8
	// Line 1153, Address: 0x2d453c, Func Offset: 0x3ac
	// Line 1154, Address: 0x2d4540, Func Offset: 0x3b0
	// Line 1155, Address: 0x2d4544, Func Offset: 0x3b4
	// Line 1156, Address: 0x2d4548, Func Offset: 0x3b8
	// Line 1157, Address: 0x2d454c, Func Offset: 0x3bc
	// Line 1158, Address: 0x2d4550, Func Offset: 0x3c0
	// Line 1159, Address: 0x2d4554, Func Offset: 0x3c4
	// Line 1162, Address: 0x2d4558, Func Offset: 0x3c8
	// Line 1163, Address: 0x2d455c, Func Offset: 0x3cc
	// Line 1164, Address: 0x2d4560, Func Offset: 0x3d0
	// Line 1165, Address: 0x2d4574, Func Offset: 0x3e4
	// Line 1166, Address: 0x2d4578, Func Offset: 0x3e8
	// Line 1167, Address: 0x2d457c, Func Offset: 0x3ec
	// Line 1168, Address: 0x2d4580, Func Offset: 0x3f0
	// Line 1169, Address: 0x2d4584, Func Offset: 0x3f4
	// Line 1170, Address: 0x2d4588, Func Offset: 0x3f8
	// Line 1171, Address: 0x2d458c, Func Offset: 0x3fc
	// Line 1172, Address: 0x2d4590, Func Offset: 0x400
	// Line 1173, Address: 0x2d4594, Func Offset: 0x404
	// Line 1174, Address: 0x2d4598, Func Offset: 0x408
	// Line 1175, Address: 0x2d459c, Func Offset: 0x40c
	// Line 1178, Address: 0x2d45a0, Func Offset: 0x410
	// Line 1181, Address: 0x2d45c4, Func Offset: 0x434
	// Line 1182, Address: 0x2d45c8, Func Offset: 0x438
	// Line 1183, Address: 0x2d45cc, Func Offset: 0x43c
	// Line 1184, Address: 0x2d45d0, Func Offset: 0x440
	// Line 1185, Address: 0x2d45d4, Func Offset: 0x444
	// Line 1186, Address: 0x2d45e8, Func Offset: 0x458
	// Line 1187, Address: 0x2d45fc, Func Offset: 0x46c
	// Line 1188, Address: 0x2d4600, Func Offset: 0x470
	// Line 1189, Address: 0x2d4604, Func Offset: 0x474
	// Line 1190, Address: 0x2d4608, Func Offset: 0x478
	// Line 1191, Address: 0x2d460c, Func Offset: 0x47c
	// Line 1192, Address: 0x2d4610, Func Offset: 0x480
	// Line 1193, Address: 0x2d4614, Func Offset: 0x484
	// Line 1197, Address: 0x2d4618, Func Offset: 0x488
	// Line 1195, Address: 0x2d461c, Func Offset: 0x48c
	// Line 1196, Address: 0x2d4620, Func Offset: 0x490
	// Line 1197, Address: 0x2d4624, Func Offset: 0x494
	// Line 1199, Address: 0x2d4644, Func Offset: 0x4b4
	// Func End, Address: 0x2d464c, Func Offset: 0x4bc
}

// 
// Start address: 0x2d4650
int _Check_DisplayAreaPoint(_anon3* vec)
{
	// Line 1206, Address: 0x2d4650, Func Offset: 0
	// Line 1212, Address: 0x2d46e8, Func Offset: 0x98
	// Line 1214, Address: 0x2d46f0, Func Offset: 0xa0
	// Line 1299, Address: 0x2d46f4, Func Offset: 0xa4
	// Func End, Address: 0x2d46fc, Func Offset: 0xac
}

// 
// Start address: 0x2d4700
void DrawScissorPolygonOpaque(_anon2* scissor, unsigned long ulType)
{
	_anon0* in;
	// Line 1391, Address: 0x2d4700, Func Offset: 0
	// Line 1341, Address: 0x2d4704, Func Offset: 0x4
	// Line 1391, Address: 0x2d4708, Func Offset: 0x8
	// Line 1392, Address: 0x2d470c, Func Offset: 0xc
	// Line 1393, Address: 0x2d4710, Func Offset: 0x10
	// Line 1394, Address: 0x2d4714, Func Offset: 0x14
	// Line 1395, Address: 0x2d4718, Func Offset: 0x18
	// Line 1397, Address: 0x2d4720, Func Offset: 0x20
	// Line 1398, Address: 0x2d4724, Func Offset: 0x24
	// Line 1399, Address: 0x2d4728, Func Offset: 0x28
	// Line 1400, Address: 0x2d472c, Func Offset: 0x2c
	// Line 1401, Address: 0x2d4730, Func Offset: 0x30
	// Line 1402, Address: 0x2d4734, Func Offset: 0x34
	// Line 1403, Address: 0x2d4738, Func Offset: 0x38
	// Line 1404, Address: 0x2d473c, Func Offset: 0x3c
	// Line 1405, Address: 0x2d4740, Func Offset: 0x40
	// Line 1406, Address: 0x2d4744, Func Offset: 0x44
	// Line 1407, Address: 0x2d4748, Func Offset: 0x48
	// Line 1408, Address: 0x2d474c, Func Offset: 0x4c
	// Line 1409, Address: 0x2d4750, Func Offset: 0x50
	// Line 1410, Address: 0x2d4754, Func Offset: 0x54
	// Line 1411, Address: 0x2d4758, Func Offset: 0x58
	// Line 1412, Address: 0x2d475c, Func Offset: 0x5c
	// Line 1413, Address: 0x2d4760, Func Offset: 0x60
	// Line 1414, Address: 0x2d4764, Func Offset: 0x64
	// Line 1416, Address: 0x2d4768, Func Offset: 0x68
	// Line 1417, Address: 0x2d4770, Func Offset: 0x70
	// Line 1421, Address: 0x2d4774, Func Offset: 0x74
	// Line 1420, Address: 0x2d4778, Func Offset: 0x78
	// Line 1421, Address: 0x2d47a8, Func Offset: 0xa8
	// Func End, Address: 0x2d47bc, Func Offset: 0xbc
}

// 
// Start address: 0x2d47c0
void vu1DrawTriangleStripOpaqueSingle(unsigned long ulType, tagVU1_STRIP_BUF* pStripTop, unsigned short usStripMax, unsigned short usMode)
{
	int count;
	int flg;
	unsigned int clipflag;
	void(*pFunc)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
	unsigned short usStripCnt;
	float fIz;
	tagVU1_STRIP_BUF* pS2;
	tagVU1_STRIP_BUF* pS1;
	tagVU1_STRIP_BUF* pS0;
	tagVU1_PRIM_BUF* pP;
	// Line 1457, Address: 0x2d47c0, Func Offset: 0
	// Line 1473, Address: 0x2d47ec, Func Offset: 0x2c
	// Line 1457, Address: 0x2d47f0, Func Offset: 0x30
	// Line 1478, Address: 0x2d4800, Func Offset: 0x40
	// Line 1481, Address: 0x2d4808, Func Offset: 0x48
	// Line 1480, Address: 0x2d4814, Func Offset: 0x54
	// Line 1481, Address: 0x2d481c, Func Offset: 0x5c
	// Line 1483, Address: 0x2d482c, Func Offset: 0x6c
	// Line 1484, Address: 0x2d4838, Func Offset: 0x78
	// Line 1485, Address: 0x2d4840, Func Offset: 0x80
	// Line 1486, Address: 0x2d4844, Func Offset: 0x84
	// Line 1490, Address: 0x2d4848, Func Offset: 0x88
	// Line 1494, Address: 0x2d484c, Func Offset: 0x8c
	// Line 1486, Address: 0x2d4850, Func Offset: 0x90
	// Line 1487, Address: 0x2d4858, Func Offset: 0x98
	// Line 1488, Address: 0x2d4864, Func Offset: 0xa4
	// Line 1489, Address: 0x2d4868, Func Offset: 0xa8
	// Line 1490, Address: 0x2d486c, Func Offset: 0xac
	// Line 1491, Address: 0x2d4874, Func Offset: 0xb4
	// Line 1490, Address: 0x2d4878, Func Offset: 0xb8
	// Line 1491, Address: 0x2d4880, Func Offset: 0xc0
	// Line 1492, Address: 0x2d4890, Func Offset: 0xd0
	// Line 1493, Address: 0x2d4898, Func Offset: 0xd8
	// Line 1494, Address: 0x2d489c, Func Offset: 0xdc
	// Line 1498, Address: 0x2d48a4, Func Offset: 0xe4
	// Line 1496, Address: 0x2d48a8, Func Offset: 0xe8
	// Line 1498, Address: 0x2d48ac, Func Offset: 0xec
	// Line 1499, Address: 0x2d48b4, Func Offset: 0xf4
	// Line 1500, Address: 0x2d48bc, Func Offset: 0xfc
	// Line 1501, Address: 0x2d48c0, Func Offset: 0x100
	// Line 1505, Address: 0x2d48c4, Func Offset: 0x104
	// Line 1509, Address: 0x2d48c8, Func Offset: 0x108
	// Line 1501, Address: 0x2d48cc, Func Offset: 0x10c
	// Line 1502, Address: 0x2d48d4, Func Offset: 0x114
	// Line 1503, Address: 0x2d48e0, Func Offset: 0x120
	// Line 1504, Address: 0x2d48e4, Func Offset: 0x124
	// Line 1505, Address: 0x2d48e8, Func Offset: 0x128
	// Line 1506, Address: 0x2d48f0, Func Offset: 0x130
	// Line 1505, Address: 0x2d48f4, Func Offset: 0x134
	// Line 1506, Address: 0x2d48fc, Func Offset: 0x13c
	// Line 1507, Address: 0x2d490c, Func Offset: 0x14c
	// Line 1508, Address: 0x2d4914, Func Offset: 0x154
	// Line 1509, Address: 0x2d4918, Func Offset: 0x158
	// Line 1510, Address: 0x2d4928, Func Offset: 0x168
	// Line 1511, Address: 0x2d492c, Func Offset: 0x16c
	// Line 1513, Address: 0x2d4930, Func Offset: 0x170
	// Line 1515, Address: 0x2d493c, Func Offset: 0x17c
	// Line 1516, Address: 0x2d4948, Func Offset: 0x188
	// Line 1517, Address: 0x2d4950, Func Offset: 0x190
	// Line 1518, Address: 0x2d4954, Func Offset: 0x194
	// Line 1522, Address: 0x2d4958, Func Offset: 0x198
	// Line 1527, Address: 0x2d495c, Func Offset: 0x19c
	// Line 1518, Address: 0x2d4960, Func Offset: 0x1a0
	// Line 1519, Address: 0x2d4968, Func Offset: 0x1a8
	// Line 1520, Address: 0x2d4974, Func Offset: 0x1b4
	// Line 1521, Address: 0x2d4978, Func Offset: 0x1b8
	// Line 1522, Address: 0x2d497c, Func Offset: 0x1bc
	// Line 1523, Address: 0x2d4984, Func Offset: 0x1c4
	// Line 1522, Address: 0x2d4988, Func Offset: 0x1c8
	// Line 1523, Address: 0x2d4990, Func Offset: 0x1d0
	// Line 1524, Address: 0x2d49a0, Func Offset: 0x1e0
	// Line 1525, Address: 0x2d49a8, Func Offset: 0x1e8
	// Line 1527, Address: 0x2d49ac, Func Offset: 0x1ec
	// Line 1528, Address: 0x2d49b4, Func Offset: 0x1f4
	// Line 1530, Address: 0x2d49bc, Func Offset: 0x1fc
	// Line 1531, Address: 0x2d4a00, Func Offset: 0x240
	// Line 1532, Address: 0x2d4a04, Func Offset: 0x244
	// Line 1533, Address: 0x2d4a0c, Func Offset: 0x24c
	// Line 1534, Address: 0x2d4a28, Func Offset: 0x268
	// Line 1535, Address: 0x2d4a2c, Func Offset: 0x26c
	// Line 1536, Address: 0x2d4a3c, Func Offset: 0x27c
	// Line 1537, Address: 0x2d4a48, Func Offset: 0x288
	// Line 1538, Address: 0x2d4a50, Func Offset: 0x290
	// Line 1539, Address: 0x2d4a58, Func Offset: 0x298
	// Line 1542, Address: 0x2d4a64, Func Offset: 0x2a4
	// Line 1544, Address: 0x2d4a68, Func Offset: 0x2a8
	// Line 1543, Address: 0x2d4a7c, Func Offset: 0x2bc
	// Line 1544, Address: 0x2d4a80, Func Offset: 0x2c0
	// Line 1601, Address: 0x2d4a98, Func Offset: 0x2d8
	// Line 1602, Address: 0x2d4ab0, Func Offset: 0x2f0
	// Func End, Address: 0x2d4ae0, Func Offset: 0x320
}

// 
// Start address: 0x2d4ae0
void vu1DrawTriangleStripOpaqueDouble(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode)
{
	int count;
	unsigned int flg;
	unsigned int clipflag;
	void(*pFunc)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
	unsigned short usStripCnt;
	float fIz;
	tagVU1_PRIM_BUF* pP;
	// Line 1885, Address: 0x2d4ae0, Func Offset: 0
	// Line 1901, Address: 0x2d4b14, Func Offset: 0x34
	// Line 1906, Address: 0x2d4b1c, Func Offset: 0x3c
	// Line 1905, Address: 0x2d4b28, Func Offset: 0x48
	// Line 1906, Address: 0x2d4b30, Func Offset: 0x50
	// Line 1908, Address: 0x2d4b40, Func Offset: 0x60
	// Line 1909, Address: 0x2d4b4c, Func Offset: 0x6c
	// Line 1910, Address: 0x2d4b50, Func Offset: 0x70
	// Line 1914, Address: 0x2d4b54, Func Offset: 0x74
	// Line 1910, Address: 0x2d4b58, Func Offset: 0x78
	// Line 1911, Address: 0x2d4b60, Func Offset: 0x80
	// Line 1912, Address: 0x2d4b6c, Func Offset: 0x8c
	// Line 1914, Address: 0x2d4b70, Func Offset: 0x90
	// Line 1915, Address: 0x2d4b78, Func Offset: 0x98
	// Line 1919, Address: 0x2d4b84, Func Offset: 0xa4
	// Line 1916, Address: 0x2d4b88, Func Offset: 0xa8
	// Line 1915, Address: 0x2d4b8c, Func Offset: 0xac
	// Line 1916, Address: 0x2d4b94, Func Offset: 0xb4
	// Line 1917, Address: 0x2d4ba4, Func Offset: 0xc4
	// Line 1918, Address: 0x2d4bac, Func Offset: 0xcc
	// Line 1919, Address: 0x2d4bb0, Func Offset: 0xd0
	// Line 1924, Address: 0x2d4bb8, Func Offset: 0xd8
	// Line 1925, Address: 0x2d4bc8, Func Offset: 0xe8
	// Line 1926, Address: 0x2d4bcc, Func Offset: 0xec
	// Line 1930, Address: 0x2d4bd0, Func Offset: 0xf0
	// Line 1926, Address: 0x2d4bd4, Func Offset: 0xf4
	// Line 1927, Address: 0x2d4bdc, Func Offset: 0xfc
	// Line 1928, Address: 0x2d4be8, Func Offset: 0x108
	// Line 1930, Address: 0x2d4bec, Func Offset: 0x10c
	// Line 1931, Address: 0x2d4bf4, Func Offset: 0x114
	// Line 1935, Address: 0x2d4c00, Func Offset: 0x120
	// Line 1932, Address: 0x2d4c04, Func Offset: 0x124
	// Line 1931, Address: 0x2d4c08, Func Offset: 0x128
	// Line 1932, Address: 0x2d4c10, Func Offset: 0x130
	// Line 1933, Address: 0x2d4c20, Func Offset: 0x140
	// Line 1934, Address: 0x2d4c28, Func Offset: 0x148
	// Line 1935, Address: 0x2d4c2c, Func Offset: 0x14c
	// Line 1936, Address: 0x2d4c38, Func Offset: 0x158
	// Line 1937, Address: 0x2d4c3c, Func Offset: 0x15c
	// Line 1938, Address: 0x2d4c40, Func Offset: 0x160
	// Line 1940, Address: 0x2d4c44, Func Offset: 0x164
	// Line 1942, Address: 0x2d4c50, Func Offset: 0x170
	// Line 1943, Address: 0x2d4c5c, Func Offset: 0x17c
	// Line 1944, Address: 0x2d4c60, Func Offset: 0x180
	// Line 1948, Address: 0x2d4c64, Func Offset: 0x184
	// Line 1944, Address: 0x2d4c68, Func Offset: 0x188
	// Line 1945, Address: 0x2d4c70, Func Offset: 0x190
	// Line 1946, Address: 0x2d4c7c, Func Offset: 0x19c
	// Line 1948, Address: 0x2d4c80, Func Offset: 0x1a0
	// Line 1949, Address: 0x2d4c88, Func Offset: 0x1a8
	// Line 1954, Address: 0x2d4c94, Func Offset: 0x1b4
	// Line 1950, Address: 0x2d4c98, Func Offset: 0x1b8
	// Line 1949, Address: 0x2d4c9c, Func Offset: 0x1bc
	// Line 1950, Address: 0x2d4ca4, Func Offset: 0x1c4
	// Line 1951, Address: 0x2d4cb4, Func Offset: 0x1d4
	// Line 1952, Address: 0x2d4cbc, Func Offset: 0x1dc
	// Line 1954, Address: 0x2d4cc0, Func Offset: 0x1e0
	// Line 1955, Address: 0x2d4cc8, Func Offset: 0x1e8
	// Line 1957, Address: 0x2d4cd0, Func Offset: 0x1f0
	// Line 1958, Address: 0x2d4cec, Func Offset: 0x20c
	// Line 1959, Address: 0x2d4cf0, Func Offset: 0x210
	// Line 1960, Address: 0x2d4d00, Func Offset: 0x220
	// Line 1961, Address: 0x2d4d0c, Func Offset: 0x22c
	// Line 1962, Address: 0x2d4d14, Func Offset: 0x234
	// Line 1963, Address: 0x2d4d1c, Func Offset: 0x23c
	// Line 1968, Address: 0x2d4d28, Func Offset: 0x248
	// Line 1967, Address: 0x2d4d34, Func Offset: 0x254
	// Line 1968, Address: 0x2d4d38, Func Offset: 0x258
	// Line 2023, Address: 0x2d4d50, Func Offset: 0x270
	// Line 2024, Address: 0x2d4d64, Func Offset: 0x284
	// Func End, Address: 0x2d4d90, Func Offset: 0x2b0
}

// 
// Start address: 0x2d4d90
void vu1DrawTriangleStripTransSingle(unsigned long ulType, tagVU1_STRIP_BUF* pStripTop, unsigned short usStripMax, unsigned short usMode)
{
	int count;
	int flg;
	unsigned int clipflag;
	void(*pFunc)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
	unsigned short usStripCnt;
	float fIz;
	tagVU1_STRIP_BUF* pS2;
	tagVU1_STRIP_BUF* pS1;
	tagVU1_STRIP_BUF* pS0;
	tagVU1_PRIM_BUF* pP;
	// Line 2502, Address: 0x2d4d90, Func Offset: 0
	// Line 2517, Address: 0x2d4dbc, Func Offset: 0x2c
	// Line 2502, Address: 0x2d4dc0, Func Offset: 0x30
	// Line 2522, Address: 0x2d4dd0, Func Offset: 0x40
	// Line 2525, Address: 0x2d4dd8, Func Offset: 0x48
	// Line 2524, Address: 0x2d4de4, Func Offset: 0x54
	// Line 2525, Address: 0x2d4dec, Func Offset: 0x5c
	// Line 2527, Address: 0x2d4dfc, Func Offset: 0x6c
	// Line 2528, Address: 0x2d4e08, Func Offset: 0x78
	// Line 2529, Address: 0x2d4e10, Func Offset: 0x80
	// Line 2530, Address: 0x2d4e14, Func Offset: 0x84
	// Line 2534, Address: 0x2d4e18, Func Offset: 0x88
	// Line 2538, Address: 0x2d4e1c, Func Offset: 0x8c
	// Line 2530, Address: 0x2d4e20, Func Offset: 0x90
	// Line 2531, Address: 0x2d4e28, Func Offset: 0x98
	// Line 2532, Address: 0x2d4e34, Func Offset: 0xa4
	// Line 2533, Address: 0x2d4e38, Func Offset: 0xa8
	// Line 2534, Address: 0x2d4e3c, Func Offset: 0xac
	// Line 2535, Address: 0x2d4e44, Func Offset: 0xb4
	// Line 2534, Address: 0x2d4e48, Func Offset: 0xb8
	// Line 2535, Address: 0x2d4e50, Func Offset: 0xc0
	// Line 2536, Address: 0x2d4e60, Func Offset: 0xd0
	// Line 2537, Address: 0x2d4e68, Func Offset: 0xd8
	// Line 2538, Address: 0x2d4e6c, Func Offset: 0xdc
	// Line 2542, Address: 0x2d4e74, Func Offset: 0xe4
	// Line 2540, Address: 0x2d4e78, Func Offset: 0xe8
	// Line 2542, Address: 0x2d4e7c, Func Offset: 0xec
	// Line 2543, Address: 0x2d4e84, Func Offset: 0xf4
	// Line 2544, Address: 0x2d4e8c, Func Offset: 0xfc
	// Line 2545, Address: 0x2d4e90, Func Offset: 0x100
	// Line 2549, Address: 0x2d4e94, Func Offset: 0x104
	// Line 2553, Address: 0x2d4e98, Func Offset: 0x108
	// Line 2545, Address: 0x2d4e9c, Func Offset: 0x10c
	// Line 2546, Address: 0x2d4ea4, Func Offset: 0x114
	// Line 2547, Address: 0x2d4eb0, Func Offset: 0x120
	// Line 2548, Address: 0x2d4eb4, Func Offset: 0x124
	// Line 2549, Address: 0x2d4eb8, Func Offset: 0x128
	// Line 2550, Address: 0x2d4ec0, Func Offset: 0x130
	// Line 2549, Address: 0x2d4ec4, Func Offset: 0x134
	// Line 2550, Address: 0x2d4ecc, Func Offset: 0x13c
	// Line 2551, Address: 0x2d4edc, Func Offset: 0x14c
	// Line 2552, Address: 0x2d4ee4, Func Offset: 0x154
	// Line 2553, Address: 0x2d4ee8, Func Offset: 0x158
	// Line 2554, Address: 0x2d4ef8, Func Offset: 0x168
	// Line 2555, Address: 0x2d4efc, Func Offset: 0x16c
	// Line 2557, Address: 0x2d4f00, Func Offset: 0x170
	// Line 2559, Address: 0x2d4f0c, Func Offset: 0x17c
	// Line 2560, Address: 0x2d4f18, Func Offset: 0x188
	// Line 2561, Address: 0x2d4f20, Func Offset: 0x190
	// Line 2562, Address: 0x2d4f24, Func Offset: 0x194
	// Line 2566, Address: 0x2d4f28, Func Offset: 0x198
	// Line 2571, Address: 0x2d4f2c, Func Offset: 0x19c
	// Line 2562, Address: 0x2d4f30, Func Offset: 0x1a0
	// Line 2563, Address: 0x2d4f38, Func Offset: 0x1a8
	// Line 2564, Address: 0x2d4f44, Func Offset: 0x1b4
	// Line 2565, Address: 0x2d4f48, Func Offset: 0x1b8
	// Line 2566, Address: 0x2d4f4c, Func Offset: 0x1bc
	// Line 2567, Address: 0x2d4f54, Func Offset: 0x1c4
	// Line 2566, Address: 0x2d4f58, Func Offset: 0x1c8
	// Line 2567, Address: 0x2d4f60, Func Offset: 0x1d0
	// Line 2568, Address: 0x2d4f70, Func Offset: 0x1e0
	// Line 2569, Address: 0x2d4f78, Func Offset: 0x1e8
	// Line 2571, Address: 0x2d4f7c, Func Offset: 0x1ec
	// Line 2572, Address: 0x2d4f84, Func Offset: 0x1f4
	// Line 2574, Address: 0x2d4f8c, Func Offset: 0x1fc
	// Line 2575, Address: 0x2d4fd0, Func Offset: 0x240
	// Line 2576, Address: 0x2d4fd4, Func Offset: 0x244
	// Line 2577, Address: 0x2d4fdc, Func Offset: 0x24c
	// Line 2578, Address: 0x2d4ff8, Func Offset: 0x268
	// Line 2579, Address: 0x2d4ffc, Func Offset: 0x26c
	// Line 2580, Address: 0x2d500c, Func Offset: 0x27c
	// Line 2581, Address: 0x2d5018, Func Offset: 0x288
	// Line 2582, Address: 0x2d5020, Func Offset: 0x290
	// Line 2583, Address: 0x2d5028, Func Offset: 0x298
	// Line 2586, Address: 0x2d5034, Func Offset: 0x2a4
	// Line 2588, Address: 0x2d5038, Func Offset: 0x2a8
	// Line 2587, Address: 0x2d504c, Func Offset: 0x2bc
	// Line 2588, Address: 0x2d5050, Func Offset: 0x2c0
	// Line 2645, Address: 0x2d5068, Func Offset: 0x2d8
	// Line 2646, Address: 0x2d5080, Func Offset: 0x2f0
	// Func End, Address: 0x2d50b0, Func Offset: 0x320
}

// 
// Start address: 0x2d50b0
int _Clip_Screen(float* clip)
{
	int ret;
	float para[4][2];
	// Line 2987, Address: 0x2d50b0, Func Offset: 0
	// Line 2988, Address: 0x2d50b8, Func Offset: 0x8
	// Line 2989, Address: 0x2d50bc, Func Offset: 0xc
	// Line 2990, Address: 0x2d50c0, Func Offset: 0x10
	// Line 2991, Address: 0x2d50c4, Func Offset: 0x14
	// Line 2992, Address: 0x2d50c8, Func Offset: 0x18
	// Line 2993, Address: 0x2d50cc, Func Offset: 0x1c
	// Line 2994, Address: 0x2d50d0, Func Offset: 0x20
	// Line 2995, Address: 0x2d50d4, Func Offset: 0x24
	// Line 2996, Address: 0x2d50d8, Func Offset: 0x28
	// Line 2997, Address: 0x2d50dc, Func Offset: 0x2c
	// Line 2998, Address: 0x2d50e0, Func Offset: 0x30
	// Line 2999, Address: 0x2d50e4, Func Offset: 0x34
	// Line 3002, Address: 0x2d50e8, Func Offset: 0x38
	// Func End, Address: 0x2d50f0, Func Offset: 0x40
}

// 
// Start address: 0x2d50f0
void vu1DrawTriangleStripTransDouble(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode)
{
	int clipswitch;
	int count;
	int flg;
	unsigned int clipflag;
	unsigned short usStripCnt;
	float fIz;
	tagVU1_PRIM_BUF* pP;
	// Line 3071, Address: 0x2d50f0, Func Offset: 0
	// Line 3080, Address: 0x2d5128, Func Offset: 0x38
	// Line 3087, Address: 0x2d512c, Func Offset: 0x3c
	// Line 3090, Address: 0x2d5130, Func Offset: 0x40
	// Line 3091, Address: 0x2d5134, Func Offset: 0x44
	// Line 3092, Address: 0x2d5138, Func Offset: 0x48
	// Line 3097, Address: 0x2d5140, Func Offset: 0x50
	// Line 3103, Address: 0x2d5144, Func Offset: 0x54
	// Line 3135, Address: 0x2d514c, Func Offset: 0x5c
	// Line 3137, Address: 0x2d5160, Func Offset: 0x70
	// Line 3138, Address: 0x2d5164, Func Offset: 0x74
	// Line 3139, Address: 0x2d5168, Func Offset: 0x78
	// Line 3141, Address: 0x2d5170, Func Offset: 0x80
	// Line 3142, Address: 0x2d5174, Func Offset: 0x84
	// Line 3143, Address: 0x2d5178, Func Offset: 0x88
	// Line 3144, Address: 0x2d517c, Func Offset: 0x8c
	// Line 3145, Address: 0x2d5180, Func Offset: 0x90
	// Line 3146, Address: 0x2d5184, Func Offset: 0x94
	// Line 3147, Address: 0x2d5188, Func Offset: 0x98
	// Line 3148, Address: 0x2d518c, Func Offset: 0x9c
	// Line 3149, Address: 0x2d5190, Func Offset: 0xa0
	// Line 3150, Address: 0x2d5194, Func Offset: 0xa4
	// Line 3151, Address: 0x2d5198, Func Offset: 0xa8
	// Line 3152, Address: 0x2d519c, Func Offset: 0xac
	// Line 3153, Address: 0x2d51a0, Func Offset: 0xb0
	// Line 3154, Address: 0x2d51a4, Func Offset: 0xb4
	// Line 3155, Address: 0x2d51a8, Func Offset: 0xb8
	// Line 3156, Address: 0x2d51ac, Func Offset: 0xbc
	// Line 3162, Address: 0x2d51b0, Func Offset: 0xc0
	// Line 3166, Address: 0x2d51bc, Func Offset: 0xcc
	// Line 3167, Address: 0x2d51c0, Func Offset: 0xd0
	// Line 3175, Address: 0x2d51c4, Func Offset: 0xd4
	// Line 3171, Address: 0x2d51cc, Func Offset: 0xdc
	// Line 3172, Address: 0x2d51d0, Func Offset: 0xe0
	// Line 3175, Address: 0x2d51d4, Func Offset: 0xe4
	// Line 3177, Address: 0x2d51e0, Func Offset: 0xf0
	// Line 3178, Address: 0x2d51e4, Func Offset: 0xf4
	// Line 3179, Address: 0x2d51e8, Func Offset: 0xf8
	// Line 3181, Address: 0x2d51f0, Func Offset: 0x100
	// Line 3182, Address: 0x2d51f4, Func Offset: 0x104
	// Line 3183, Address: 0x2d51f8, Func Offset: 0x108
	// Line 3184, Address: 0x2d51fc, Func Offset: 0x10c
	// Line 3185, Address: 0x2d5200, Func Offset: 0x110
	// Line 3186, Address: 0x2d5204, Func Offset: 0x114
	// Line 3187, Address: 0x2d5208, Func Offset: 0x118
	// Line 3188, Address: 0x2d520c, Func Offset: 0x11c
	// Line 3189, Address: 0x2d5210, Func Offset: 0x120
	// Line 3190, Address: 0x2d5214, Func Offset: 0x124
	// Line 3191, Address: 0x2d5218, Func Offset: 0x128
	// Line 3192, Address: 0x2d521c, Func Offset: 0x12c
	// Line 3193, Address: 0x2d5220, Func Offset: 0x130
	// Line 3194, Address: 0x2d5224, Func Offset: 0x134
	// Line 3195, Address: 0x2d5228, Func Offset: 0x138
	// Line 3196, Address: 0x2d522c, Func Offset: 0x13c
	// Line 3202, Address: 0x2d5230, Func Offset: 0x140
	// Line 3206, Address: 0x2d5240, Func Offset: 0x150
	// Line 3207, Address: 0x2d5244, Func Offset: 0x154
	// Line 3211, Address: 0x2d5248, Func Offset: 0x158
	// Line 3212, Address: 0x2d524c, Func Offset: 0x15c
	// Line 3214, Address: 0x2d5250, Func Offset: 0x160
	// Line 3217, Address: 0x2d5258, Func Offset: 0x168
	// Line 3219, Address: 0x2d526c, Func Offset: 0x17c
	// Line 3220, Address: 0x2d5270, Func Offset: 0x180
	// Line 3221, Address: 0x2d5274, Func Offset: 0x184
	// Line 3223, Address: 0x2d527c, Func Offset: 0x18c
	// Line 3224, Address: 0x2d5280, Func Offset: 0x190
	// Line 3225, Address: 0x2d5284, Func Offset: 0x194
	// Line 3226, Address: 0x2d5288, Func Offset: 0x198
	// Line 3227, Address: 0x2d528c, Func Offset: 0x19c
	// Line 3228, Address: 0x2d5290, Func Offset: 0x1a0
	// Line 3229, Address: 0x2d5294, Func Offset: 0x1a4
	// Line 3230, Address: 0x2d5298, Func Offset: 0x1a8
	// Line 3231, Address: 0x2d529c, Func Offset: 0x1ac
	// Line 3232, Address: 0x2d52a0, Func Offset: 0x1b0
	// Line 3233, Address: 0x2d52a4, Func Offset: 0x1b4
	// Line 3234, Address: 0x2d52a8, Func Offset: 0x1b8
	// Line 3235, Address: 0x2d52ac, Func Offset: 0x1bc
	// Line 3236, Address: 0x2d52b0, Func Offset: 0x1c0
	// Line 3237, Address: 0x2d52b4, Func Offset: 0x1c4
	// Line 3238, Address: 0x2d52b8, Func Offset: 0x1c8
	// Line 3244, Address: 0x2d52bc, Func Offset: 0x1cc
	// Line 3247, Address: 0x2d52c8, Func Offset: 0x1d8
	// Line 3248, Address: 0x2d52cc, Func Offset: 0x1dc
	// Line 3249, Address: 0x2d52d0, Func Offset: 0x1e0
	// Line 3254, Address: 0x2d52d4, Func Offset: 0x1e4
	// Line 3255, Address: 0x2d52ec, Func Offset: 0x1fc
	// Line 3256, Address: 0x2d52f0, Func Offset: 0x200
	// Line 3257, Address: 0x2d5300, Func Offset: 0x210
	// Line 3258, Address: 0x2d530c, Func Offset: 0x21c
	// Line 3259, Address: 0x2d5314, Func Offset: 0x224
	// Line 3260, Address: 0x2d531c, Func Offset: 0x22c
	// Line 3264, Address: 0x2d5328, Func Offset: 0x238
	// Line 3265, Address: 0x2d5330, Func Offset: 0x240
	// Line 3266, Address: 0x2d5354, Func Offset: 0x264
	// Line 3271, Address: 0x2d535c, Func Offset: 0x26c
	// Line 3272, Address: 0x2d5360, Func Offset: 0x270
	// Line 3276, Address: 0x2d5368, Func Offset: 0x278
	// Line 3277, Address: 0x2d536c, Func Offset: 0x27c
	// Line 3281, Address: 0x2d5370, Func Offset: 0x280
	// Line 3277, Address: 0x2d5374, Func Offset: 0x284
	// Line 3278, Address: 0x2d537c, Func Offset: 0x28c
	// Line 3279, Address: 0x2d5388, Func Offset: 0x298
	// Line 3280, Address: 0x2d538c, Func Offset: 0x29c
	// Line 3281, Address: 0x2d5390, Func Offset: 0x2a0
	// Line 3282, Address: 0x2d5398, Func Offset: 0x2a8
	// Line 3281, Address: 0x2d539c, Func Offset: 0x2ac
	// Line 3282, Address: 0x2d53a4, Func Offset: 0x2b4
	// Line 3283, Address: 0x2d53b4, Func Offset: 0x2c4
	// Line 3284, Address: 0x2d53bc, Func Offset: 0x2cc
	// Line 3287, Address: 0x2d53c4, Func Offset: 0x2d4
	// Line 3288, Address: 0x2d53c8, Func Offset: 0x2d8
	// Line 3291, Address: 0x2d53cc, Func Offset: 0x2dc
	// Line 3292, Address: 0x2d53d4, Func Offset: 0x2e4
	// Line 3293, Address: 0x2d53d8, Func Offset: 0x2e8
	// Line 3298, Address: 0x2d53dc, Func Offset: 0x2ec
	// Line 3299, Address: 0x2d53e0, Func Offset: 0x2f0
	// Line 3303, Address: 0x2d53e8, Func Offset: 0x2f8
	// Line 3304, Address: 0x2d53ec, Func Offset: 0x2fc
	// Line 3308, Address: 0x2d53f0, Func Offset: 0x300
	// Line 3304, Address: 0x2d53f4, Func Offset: 0x304
	// Line 3305, Address: 0x2d53fc, Func Offset: 0x30c
	// Line 3306, Address: 0x2d5408, Func Offset: 0x318
	// Line 3307, Address: 0x2d540c, Func Offset: 0x31c
	// Line 3308, Address: 0x2d5410, Func Offset: 0x320
	// Line 3309, Address: 0x2d5418, Func Offset: 0x328
	// Line 3308, Address: 0x2d541c, Func Offset: 0x32c
	// Line 3309, Address: 0x2d5424, Func Offset: 0x334
	// Line 3310, Address: 0x2d5434, Func Offset: 0x344
	// Line 3311, Address: 0x2d543c, Func Offset: 0x34c
	// Line 3314, Address: 0x2d5444, Func Offset: 0x354
	// Line 3315, Address: 0x2d5448, Func Offset: 0x358
	// Line 3318, Address: 0x2d544c, Func Offset: 0x35c
	// Line 3319, Address: 0x2d5454, Func Offset: 0x364
	// Line 3320, Address: 0x2d5458, Func Offset: 0x368
	// Line 3321, Address: 0x2d545c, Func Offset: 0x36c
	// Line 3326, Address: 0x2d5464, Func Offset: 0x374
	// Line 3327, Address: 0x2d5468, Func Offset: 0x378
	// Line 3331, Address: 0x2d5470, Func Offset: 0x380
	// Line 3332, Address: 0x2d5474, Func Offset: 0x384
	// Line 3336, Address: 0x2d5478, Func Offset: 0x388
	// Line 3332, Address: 0x2d547c, Func Offset: 0x38c
	// Line 3333, Address: 0x2d5484, Func Offset: 0x394
	// Line 3334, Address: 0x2d5490, Func Offset: 0x3a0
	// Line 3335, Address: 0x2d5494, Func Offset: 0x3a4
	// Line 3336, Address: 0x2d5498, Func Offset: 0x3a8
	// Line 3337, Address: 0x2d54a0, Func Offset: 0x3b0
	// Line 3336, Address: 0x2d54a4, Func Offset: 0x3b4
	// Line 3337, Address: 0x2d54ac, Func Offset: 0x3bc
	// Line 3338, Address: 0x2d54bc, Func Offset: 0x3cc
	// Line 3339, Address: 0x2d54c4, Func Offset: 0x3d4
	// Line 3342, Address: 0x2d54cc, Func Offset: 0x3dc
	// Line 3343, Address: 0x2d54d0, Func Offset: 0x3e0
	// Line 3346, Address: 0x2d54d4, Func Offset: 0x3e4
	// Line 3347, Address: 0x2d54dc, Func Offset: 0x3ec
	// Line 3349, Address: 0x2d54e4, Func Offset: 0x3f4
	// Line 3350, Address: 0x2d54f4, Func Offset: 0x404
	// Line 3351, Address: 0x2d54fc, Func Offset: 0x40c
	// Line 3352, Address: 0x2d5500, Func Offset: 0x410
	// Line 3353, Address: 0x2d5524, Func Offset: 0x434
	// Line 3355, Address: 0x2d5528, Func Offset: 0x438
	// Line 3360, Address: 0x2d553c, Func Offset: 0x44c
	// Func End, Address: 0x2d556c, Func Offset: 0x47c
}

// 
// Start address: 0x2d5570
void vu1GetVertexColor(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim)
{
	// Line 3663, Address: 0x2d5570, Func Offset: 0
	// Line 3664, Address: 0x2d5580, Func Offset: 0x10
	// Line 3665, Address: 0x2d5584, Func Offset: 0x14
	// Line 3666, Address: 0x2d5588, Func Offset: 0x18
	// Line 3667, Address: 0x2d558c, Func Offset: 0x1c
	// Line 3668, Address: 0x2d5590, Func Offset: 0x20
	// Line 3669, Address: 0x2d5594, Func Offset: 0x24
	// Line 3670, Address: 0x2d5598, Func Offset: 0x28
	// Line 3671, Address: 0x2d559c, Func Offset: 0x2c
	// Line 3672, Address: 0x2d55a0, Func Offset: 0x30
	// Line 3673, Address: 0x2d55a4, Func Offset: 0x34
	// Line 3677, Address: 0x2d55a8, Func Offset: 0x38
	// Func End, Address: 0x2d55b0, Func Offset: 0x40
}

// 
// Start address: 0x2d55b0
void vu1GetVertexColorCM(tagVU1_PRIM_BUF* pPrim)
{
	// Line 3705, Address: 0x2d55b0, Func Offset: 0
	// Line 3706, Address: 0x2d55b8, Func Offset: 0x8
	// Line 3707, Address: 0x2d55bc, Func Offset: 0xc
	// Line 3708, Address: 0x2d55c4, Func Offset: 0x14
	// Line 3709, Address: 0x2d55c8, Func Offset: 0x18
	// Line 3713, Address: 0x2d55cc, Func Offset: 0x1c
	// Func End, Address: 0x2d55d4, Func Offset: 0x24
}

// 
// Start address: 0x2d55e0
void vu1GetVertexColorIgnore(tagVU1_PRIM_BUF* pPrim)
{
	// Line 3742, Address: 0x2d55e0, Func Offset: 0
	// Line 3743, Address: 0x2d55e4, Func Offset: 0x4
	// Line 3744, Address: 0x2d55e8, Func Offset: 0x8
	// Line 3745, Address: 0x2d55ec, Func Offset: 0xc
	// Line 3746, Address: 0x2d55f4, Func Offset: 0x14
	// Line 3747, Address: 0x2d55f8, Func Offset: 0x18
	// Line 3748, Address: 0x2d55fc, Func Offset: 0x1c
	// Line 3752, Address: 0x2d5600, Func Offset: 0x20
	// Func End, Address: 0x2d5608, Func Offset: 0x28
}

// 
// Start address: 0x2d5610
void vu1GetVertexColorDif(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim)
{
	// Line 3790, Address: 0x2d5610, Func Offset: 0
	// Line 3791, Address: 0x2d5618, Func Offset: 0x8
	// Line 3792, Address: 0x2d561c, Func Offset: 0xc
	// Line 3793, Address: 0x2d5620, Func Offset: 0x10
	// Line 3794, Address: 0x2d5628, Func Offset: 0x18
	// Line 3795, Address: 0x2d562c, Func Offset: 0x1c
	// Line 3796, Address: 0x2d5630, Func Offset: 0x20
	// Line 3797, Address: 0x2d5634, Func Offset: 0x24
	// Line 3798, Address: 0x2d5638, Func Offset: 0x28
	// Line 3802, Address: 0x2d563c, Func Offset: 0x2c
	// Func End, Address: 0x2d5644, Func Offset: 0x34
}

// 
// Start address: 0x2d5650
void vu1GetVertexColorDifAmb(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim)
{
	// Line 3843, Address: 0x2d5650, Func Offset: 0
	// Line 3846, Address: 0x2d5654, Func Offset: 0x4
	// Line 3847, Address: 0x2d565c, Func Offset: 0xc
	// Line 3849, Address: 0x2d5660, Func Offset: 0x10
	// Line 3850, Address: 0x2d5664, Func Offset: 0x14
	// Line 3851, Address: 0x2d5668, Func Offset: 0x18
	// Line 3853, Address: 0x2d566c, Func Offset: 0x1c
	// Line 3854, Address: 0x2d5670, Func Offset: 0x20
	// Line 3858, Address: 0x2d5674, Func Offset: 0x24
	// Func End, Address: 0x2d567c, Func Offset: 0x2c
}

// 
// Start address: 0x2d5680
void vu1GetVertexColorDifSpe1(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim)
{
	// Line 3909, Address: 0x2d5680, Func Offset: 0
	// Line 3912, Address: 0x2d5684, Func Offset: 0x4
	// Line 3910, Address: 0x2d5688, Func Offset: 0x8
	// Line 3911, Address: 0x2d568c, Func Offset: 0xc
	// Line 3912, Address: 0x2d5690, Func Offset: 0x10
	// Line 3913, Address: 0x2d5694, Func Offset: 0x14
	// Line 3914, Address: 0x2d5698, Func Offset: 0x18
	// Line 3915, Address: 0x2d569c, Func Offset: 0x1c
	// Line 3916, Address: 0x2d56a0, Func Offset: 0x20
	// Line 3917, Address: 0x2d56a4, Func Offset: 0x24
	// Line 3918, Address: 0x2d56a8, Func Offset: 0x28
	// Line 3919, Address: 0x2d56ac, Func Offset: 0x2c
	// Line 3920, Address: 0x2d56b0, Func Offset: 0x30
	// Line 3921, Address: 0x2d56b4, Func Offset: 0x34
	// Line 3922, Address: 0x2d56b8, Func Offset: 0x38
	// Line 3926, Address: 0x2d56bc, Func Offset: 0x3c
	// Func End, Address: 0x2d56c4, Func Offset: 0x44
}

// 
// Start address: 0x2d56d0
void vu1GetVertexColorDifSpe2(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim)
{
	// Line 3976, Address: 0x2d56d0, Func Offset: 0
	// Line 3978, Address: 0x2d56e8, Func Offset: 0x18
	// Line 3979, Address: 0x2d56ec, Func Offset: 0x1c
	// Line 3980, Address: 0x2d56f0, Func Offset: 0x20
	// Line 3981, Address: 0x2d56f4, Func Offset: 0x24
	// Line 3982, Address: 0x2d56f8, Func Offset: 0x28
	// Line 3983, Address: 0x2d5700, Func Offset: 0x30
	// Line 3984, Address: 0x2d5704, Func Offset: 0x34
	// Line 3985, Address: 0x2d5708, Func Offset: 0x38
	// Line 3986, Address: 0x2d570c, Func Offset: 0x3c
	// Line 3987, Address: 0x2d5710, Func Offset: 0x40
	// Line 3988, Address: 0x2d5714, Func Offset: 0x44
	// Line 3989, Address: 0x2d5718, Func Offset: 0x48
	// Line 3990, Address: 0x2d571c, Func Offset: 0x4c
	// Line 3991, Address: 0x2d5720, Func Offset: 0x50
	// Line 3992, Address: 0x2d5724, Func Offset: 0x54
	// Line 3993, Address: 0x2d5728, Func Offset: 0x58
	// Line 3997, Address: 0x2d572c, Func Offset: 0x5c
	// Func End, Address: 0x2d5734, Func Offset: 0x64
}

// 
// Start address: 0x2d5740
void vu1GetVertexColorDifSpe3(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim)
{
	// Line 4044, Address: 0x2d5740, Func Offset: 0
	// Line 4045, Address: 0x2d5750, Func Offset: 0x10
	// Line 4046, Address: 0x2d5754, Func Offset: 0x14
	// Line 4047, Address: 0x2d5758, Func Offset: 0x18
	// Line 4048, Address: 0x2d575c, Func Offset: 0x1c
	// Line 4049, Address: 0x2d5764, Func Offset: 0x24
	// Line 4050, Address: 0x2d5768, Func Offset: 0x28
	// Line 4051, Address: 0x2d576c, Func Offset: 0x2c
	// Line 4053, Address: 0x2d5770, Func Offset: 0x30
	// Line 4054, Address: 0x2d5774, Func Offset: 0x34
	// Line 4055, Address: 0x2d5778, Func Offset: 0x38
	// Line 4056, Address: 0x2d578c, Func Offset: 0x4c
	// Line 4057, Address: 0x2d5790, Func Offset: 0x50
	// Line 4058, Address: 0x2d5794, Func Offset: 0x54
	// Line 4059, Address: 0x2d5798, Func Offset: 0x58
	// Line 4060, Address: 0x2d579c, Func Offset: 0x5c
	// Line 4061, Address: 0x2d57a0, Func Offset: 0x60
	// Line 4062, Address: 0x2d57a4, Func Offset: 0x64
	// Line 4063, Address: 0x2d57a8, Func Offset: 0x68
	// Line 4064, Address: 0x2d57ac, Func Offset: 0x6c
	// Line 4068, Address: 0x2d57b0, Func Offset: 0x70
	// Func End, Address: 0x2d57b8, Func Offset: 0x78
}

// 
// Start address: 0x2d57c0
void vu1GetVertexColorDifSpe1Amb(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim)
{
	// Line 4122, Address: 0x2d57c0, Func Offset: 0
	// Line 4123, Address: 0x2d57d8, Func Offset: 0x18
	// Line 4124, Address: 0x2d57dc, Func Offset: 0x1c
	// Line 4125, Address: 0x2d57e0, Func Offset: 0x20
	// Line 4126, Address: 0x2d57e4, Func Offset: 0x24
	// Line 4127, Address: 0x2d57e8, Func Offset: 0x28
	// Line 4128, Address: 0x2d57f0, Func Offset: 0x30
	// Line 4129, Address: 0x2d57f4, Func Offset: 0x34
	// Line 4130, Address: 0x2d57f8, Func Offset: 0x38
	// Line 4131, Address: 0x2d57fc, Func Offset: 0x3c
	// Line 4132, Address: 0x2d5800, Func Offset: 0x40
	// Line 4133, Address: 0x2d5804, Func Offset: 0x44
	// Line 4134, Address: 0x2d5808, Func Offset: 0x48
	// Line 4135, Address: 0x2d580c, Func Offset: 0x4c
	// Line 4136, Address: 0x2d5810, Func Offset: 0x50
	// Line 4137, Address: 0x2d5814, Func Offset: 0x54
	// Line 4138, Address: 0x2d5818, Func Offset: 0x58
	// Line 4142, Address: 0x2d581c, Func Offset: 0x5c
	// Func End, Address: 0x2d5824, Func Offset: 0x64
}

// 
// Start address: 0x2d5830
void vu1GetVertexColorDifSpe2Amb(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim)
{
	// Line 4192, Address: 0x2d5830, Func Offset: 0
	// Line 4193, Address: 0x2d5848, Func Offset: 0x18
	// Line 4194, Address: 0x2d584c, Func Offset: 0x1c
	// Line 4195, Address: 0x2d5850, Func Offset: 0x20
	// Line 4196, Address: 0x2d5854, Func Offset: 0x24
	// Line 4197, Address: 0x2d5858, Func Offset: 0x28
	// Line 4198, Address: 0x2d5860, Func Offset: 0x30
	// Line 4199, Address: 0x2d5864, Func Offset: 0x34
	// Line 4200, Address: 0x2d5868, Func Offset: 0x38
	// Line 4201, Address: 0x2d586c, Func Offset: 0x3c
	// Line 4202, Address: 0x2d5870, Func Offset: 0x40
	// Line 4203, Address: 0x2d5874, Func Offset: 0x44
	// Line 4204, Address: 0x2d5878, Func Offset: 0x48
	// Line 4205, Address: 0x2d587c, Func Offset: 0x4c
	// Line 4206, Address: 0x2d5880, Func Offset: 0x50
	// Line 4207, Address: 0x2d5884, Func Offset: 0x54
	// Line 4208, Address: 0x2d5888, Func Offset: 0x58
	// Line 4212, Address: 0x2d588c, Func Offset: 0x5c
	// Func End, Address: 0x2d5894, Func Offset: 0x64
}

// 
// Start address: 0x2d58a0
void vu1GetVertexColorDifSpe3Amb(tagVU1_STRIP_BUF* pStrip, tagVU1_PRIM_BUF* pPrim)
{
	// Line 4259, Address: 0x2d58a0, Func Offset: 0
	// Line 4260, Address: 0x2d58b8, Func Offset: 0x18
	// Line 4261, Address: 0x2d58bc, Func Offset: 0x1c
	// Line 4262, Address: 0x2d58c0, Func Offset: 0x20
	// Line 4263, Address: 0x2d58c4, Func Offset: 0x24
	// Line 4264, Address: 0x2d58c8, Func Offset: 0x28
	// Line 4265, Address: 0x2d58d0, Func Offset: 0x30
	// Line 4266, Address: 0x2d58d4, Func Offset: 0x34
	// Line 4267, Address: 0x2d58d8, Func Offset: 0x38
	// Line 4268, Address: 0x2d58dc, Func Offset: 0x3c
	// Line 4270, Address: 0x2d58e0, Func Offset: 0x40
	// Line 4271, Address: 0x2d58e4, Func Offset: 0x44
	// Line 4272, Address: 0x2d58e8, Func Offset: 0x48
	// Line 4273, Address: 0x2d58fc, Func Offset: 0x5c
	// Line 4274, Address: 0x2d5900, Func Offset: 0x60
	// Line 4275, Address: 0x2d5904, Func Offset: 0x64
	// Line 4276, Address: 0x2d5908, Func Offset: 0x68
	// Line 4277, Address: 0x2d590c, Func Offset: 0x6c
	// Line 4279, Address: 0x2d5910, Func Offset: 0x70
	// Line 4280, Address: 0x2d5914, Func Offset: 0x74
	// Line 4281, Address: 0x2d5918, Func Offset: 0x78
	// Line 4282, Address: 0x2d591c, Func Offset: 0x7c
	// Line 4286, Address: 0x2d5920, Func Offset: 0x80
	// Func End, Address: 0x2d5928, Func Offset: 0x88
}

// 
// Start address: 0x2d5930
void vu1RotTransStripBuf(float pMatrix[16], _anon3* pVector, tagVU1_STRIP_BUF* pBuf)
{
	float fIz;
	float fZ;
	// Line 4303, Address: 0x2d5930, Func Offset: 0
	// Line 4307, Address: 0x2d5940, Func Offset: 0x10
	// Line 4309, Address: 0x2d5948, Func Offset: 0x18
	// Line 4310, Address: 0x2d5954, Func Offset: 0x24
	// Line 4312, Address: 0x2d595c, Func Offset: 0x2c
	// Line 4309, Address: 0x2d5960, Func Offset: 0x30
	// Line 4312, Address: 0x2d5964, Func Offset: 0x34
	// Line 4313, Address: 0x2d596c, Func Offset: 0x3c
	// Line 4310, Address: 0x2d5970, Func Offset: 0x40
	// Line 4312, Address: 0x2d5974, Func Offset: 0x44
	// Line 4313, Address: 0x2d5980, Func Offset: 0x50
	// Line 4316, Address: 0x2d5994, Func Offset: 0x64
	// Line 4320, Address: 0x2d59a0, Func Offset: 0x70
	// Func End, Address: 0x2d59b0, Func Offset: 0x80
}

// 
// Start address: 0x2d59b0
void vu1DrawTriangleStripTransDoubleI(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode)
{
	int flg;
	unsigned int clipflag;
	void(*pFunc)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
	unsigned short usStripCnt;
	tagVU1_PRIM_BUF* pP;
	// Line 4578, Address: 0x2d59b0, Func Offset: 0
	// Line 4588, Address: 0x2d59d8, Func Offset: 0x28
	// Line 4583, Address: 0x2d59ec, Func Offset: 0x3c
	// Line 4588, Address: 0x2d59f0, Func Offset: 0x40
	// Line 4629, Address: 0x2d59f8, Func Offset: 0x48
	// Line 4628, Address: 0x2d5a04, Func Offset: 0x54
	// Line 4629, Address: 0x2d5a0c, Func Offset: 0x5c
	// Line 4631, Address: 0x2d5a1c, Func Offset: 0x6c
	// Line 4633, Address: 0x2d5a24, Func Offset: 0x74
	// Line 4634, Address: 0x2d5a30, Func Offset: 0x80
	// Line 4639, Address: 0x2d5a3c, Func Offset: 0x8c
	// Line 4640, Address: 0x2d5a40, Func Offset: 0x90
	// Line 4641, Address: 0x2d5a44, Func Offset: 0x94
	// Line 4642, Address: 0x2d5a48, Func Offset: 0x98
	// Line 4643, Address: 0x2d5a4c, Func Offset: 0x9c
	// Line 4644, Address: 0x2d5a50, Func Offset: 0xa0
	// Line 4645, Address: 0x2d5a54, Func Offset: 0xa4
	// Line 4649, Address: 0x2d5a58, Func Offset: 0xa8
	// Line 4650, Address: 0x2d5a5c, Func Offset: 0xac
	// Line 4651, Address: 0x2d5a60, Func Offset: 0xb0
	// Line 4653, Address: 0x2d5a64, Func Offset: 0xb4
	// Line 4654, Address: 0x2d5a68, Func Offset: 0xb8
	// Line 4655, Address: 0x2d5a6c, Func Offset: 0xbc
	// Line 4656, Address: 0x2d5a70, Func Offset: 0xc0
	// Line 4657, Address: 0x2d5a74, Func Offset: 0xc4
	// Line 4662, Address: 0x2d5a78, Func Offset: 0xc8
	// Line 4663, Address: 0x2d5a7c, Func Offset: 0xcc
	// Line 4664, Address: 0x2d5a80, Func Offset: 0xd0
	// Line 4665, Address: 0x2d5a84, Func Offset: 0xd4
	// Line 4666, Address: 0x2d5a88, Func Offset: 0xd8
	// Line 4667, Address: 0x2d5a8c, Func Offset: 0xdc
	// Line 4668, Address: 0x2d5a90, Func Offset: 0xe0
	// Line 4669, Address: 0x2d5a94, Func Offset: 0xe4
	// Line 4671, Address: 0x2d5a98, Func Offset: 0xe8
	// Line 4672, Address: 0x2d5a9c, Func Offset: 0xec
	// Line 4673, Address: 0x2d5ab0, Func Offset: 0x100
	// Line 4674, Address: 0x2d5ab4, Func Offset: 0x104
	// Line 4675, Address: 0x2d5ab8, Func Offset: 0x108
	// Line 4676, Address: 0x2d5abc, Func Offset: 0x10c
	// Line 4677, Address: 0x2d5ac0, Func Offset: 0x110
	// Line 4678, Address: 0x2d5ac4, Func Offset: 0x114
	// Line 4679, Address: 0x2d5ac8, Func Offset: 0x118
	// Line 4680, Address: 0x2d5acc, Func Offset: 0x11c
	// Line 4681, Address: 0x2d5ad0, Func Offset: 0x120
	// Line 4682, Address: 0x2d5ad8, Func Offset: 0x128
	// Line 4683, Address: 0x2d5adc, Func Offset: 0x12c
	// Line 4685, Address: 0x2d5ae0, Func Offset: 0x130
	// Line 4688, Address: 0x2d5ae4, Func Offset: 0x134
	// Line 4690, Address: 0x2d5af0, Func Offset: 0x140
	// Line 4691, Address: 0x2d5b20, Func Offset: 0x170
	// Line 4692, Address: 0x2d5b28, Func Offset: 0x178
	// Line 4694, Address: 0x2d5b3c, Func Offset: 0x18c
	// Line 4695, Address: 0x2d5b50, Func Offset: 0x1a0
	// Line 4697, Address: 0x2d5b60, Func Offset: 0x1b0
	// Line 4698, Address: 0x2d5b6c, Func Offset: 0x1bc
	// Line 4700, Address: 0x2d5b70, Func Offset: 0x1c0
	// Line 4702, Address: 0x2d5b74, Func Offset: 0x1c4
	// Line 4700, Address: 0x2d5b80, Func Offset: 0x1d0
	// Line 4702, Address: 0x2d5b84, Func Offset: 0x1d4
	// Line 4701, Address: 0x2d5b88, Func Offset: 0x1d8
	// Line 4700, Address: 0x2d5b8c, Func Offset: 0x1dc
	// Line 4702, Address: 0x2d5b90, Func Offset: 0x1e0
	// Line 4704, Address: 0x2d5ba4, Func Offset: 0x1f4
	// Line 4705, Address: 0x2d5bb4, Func Offset: 0x204
	// Func End, Address: 0x2d5bdc, Func Offset: 0x22c
}

// 
// Start address: 0x2d5be0
void DrawScissorPolygonTrans1P(_anon2* scissor, unsigned long ulType)
{
	_anon0* in;
	// Line 4750, Address: 0x2d5be0, Func Offset: 0
	// Line 4748, Address: 0x2d5be4, Func Offset: 0x4
	// Line 4750, Address: 0x2d5be8, Func Offset: 0x8
	// Line 4751, Address: 0x2d5bec, Func Offset: 0xc
	// Line 4752, Address: 0x2d5bf0, Func Offset: 0x10
	// Line 4753, Address: 0x2d5bf4, Func Offset: 0x14
	// Line 4754, Address: 0x2d5bf8, Func Offset: 0x18
	// Line 4756, Address: 0x2d5c00, Func Offset: 0x20
	// Line 4757, Address: 0x2d5c04, Func Offset: 0x24
	// Line 4758, Address: 0x2d5c08, Func Offset: 0x28
	// Line 4759, Address: 0x2d5c0c, Func Offset: 0x2c
	// Line 4760, Address: 0x2d5c10, Func Offset: 0x30
	// Line 4761, Address: 0x2d5c14, Func Offset: 0x34
	// Line 4762, Address: 0x2d5c18, Func Offset: 0x38
	// Line 4763, Address: 0x2d5c1c, Func Offset: 0x3c
	// Line 4764, Address: 0x2d5c20, Func Offset: 0x40
	// Line 4765, Address: 0x2d5c24, Func Offset: 0x44
	// Line 4766, Address: 0x2d5c28, Func Offset: 0x48
	// Line 4767, Address: 0x2d5c2c, Func Offset: 0x4c
	// Line 4768, Address: 0x2d5c30, Func Offset: 0x50
	// Line 4769, Address: 0x2d5c34, Func Offset: 0x54
	// Line 4770, Address: 0x2d5c38, Func Offset: 0x58
	// Line 4771, Address: 0x2d5c3c, Func Offset: 0x5c
	// Line 4772, Address: 0x2d5c40, Func Offset: 0x60
	// Line 4773, Address: 0x2d5c44, Func Offset: 0x64
	// Line 4775, Address: 0x2d5c48, Func Offset: 0x68
	// Line 4776, Address: 0x2d5c50, Func Offset: 0x70
	// Line 4779, Address: 0x2d5c54, Func Offset: 0x74
	// Line 4778, Address: 0x2d5c58, Func Offset: 0x78
	// Line 4779, Address: 0x2d5c88, Func Offset: 0xa8
	// Func End, Address: 0x2d5c9c, Func Offset: 0xbc
}

// 
// Start address: 0x2d5ca0
void vu1DrawTriangleStripTransDouble1P(unsigned long ulType, tagVU1_STRIP_BUF* pS, unsigned short usStripMax, unsigned short usMode)
{
	int flg;
	unsigned int clipflag;
	void(*pFunc)(tagVU1_STRIP_BUF*, tagVU1_PRIM_BUF*);
	unsigned short usStripCnt;
	float sam;
	float fIz;
	tagVU1_PRIM_BUF* pP;
	// Line 4792, Address: 0x2d5ca0, Func Offset: 0
	// Line 4802, Address: 0x2d5cd0, Func Offset: 0x30
	// Line 4797, Address: 0x2d5ce4, Func Offset: 0x44
	// Line 4802, Address: 0x2d5ce8, Func Offset: 0x48
	// Line 4807, Address: 0x2d5cf0, Func Offset: 0x50
	// Line 4806, Address: 0x2d5cfc, Func Offset: 0x5c
	// Line 4811, Address: 0x2d5d04, Func Offset: 0x64
	// Line 4807, Address: 0x2d5d08, Func Offset: 0x68
	// Line 4811, Address: 0x2d5d18, Func Offset: 0x78
	// Line 4812, Address: 0x2d5d2c, Func Offset: 0x8c
	// Line 4813, Address: 0x2d5d30, Func Offset: 0x90
	// Line 4812, Address: 0x2d5d38, Func Offset: 0x98
	// Line 4813, Address: 0x2d5d40, Func Offset: 0xa0
	// Line 4814, Address: 0x2d5d50, Func Offset: 0xb0
	// Line 4823, Address: 0x2d5d94, Func Offset: 0xf4
	// Line 4825, Address: 0x2d5da0, Func Offset: 0x100
	// Line 4826, Address: 0x2d5dac, Func Offset: 0x10c
	// Line 4827, Address: 0x2d5db0, Func Offset: 0x110
	// Line 4836, Address: 0x2d5db4, Func Offset: 0x114
	// Line 4831, Address: 0x2d5dc0, Func Offset: 0x120
	// Line 4827, Address: 0x2d5dc4, Func Offset: 0x124
	// Line 4836, Address: 0x2d5dc8, Func Offset: 0x128
	// Line 4827, Address: 0x2d5dd0, Func Offset: 0x130
	// Line 4828, Address: 0x2d5dd4, Func Offset: 0x134
	// Line 4829, Address: 0x2d5de0, Func Offset: 0x140
	// Line 4831, Address: 0x2d5de4, Func Offset: 0x144
	// Line 4832, Address: 0x2d5dec, Func Offset: 0x14c
	// Line 4831, Address: 0x2d5df0, Func Offset: 0x150
	// Line 4832, Address: 0x2d5df8, Func Offset: 0x158
	// Line 4833, Address: 0x2d5e08, Func Offset: 0x168
	// Line 4834, Address: 0x2d5e10, Func Offset: 0x170
	// Line 4836, Address: 0x2d5e18, Func Offset: 0x178
	// Line 4837, Address: 0x2d5e24, Func Offset: 0x184
	// Line 4838, Address: 0x2d5e30, Func Offset: 0x190
	// Line 4837, Address: 0x2d5e34, Func Offset: 0x194
	// Line 4838, Address: 0x2d5e38, Func Offset: 0x198
	// Line 4839, Address: 0x2d5e40, Func Offset: 0x1a0
	// Line 4838, Address: 0x2d5e44, Func Offset: 0x1a4
	// Line 4839, Address: 0x2d5e48, Func Offset: 0x1a8
	// Line 4840, Address: 0x2d5e50, Func Offset: 0x1b0
	// Line 4839, Address: 0x2d5e58, Func Offset: 0x1b8
	// Line 4840, Address: 0x2d5e5c, Func Offset: 0x1bc
	// Line 4841, Address: 0x2d5e60, Func Offset: 0x1c0
	// Line 4843, Address: 0x2d5e78, Func Offset: 0x1d8
	// Line 4844, Address: 0x2d5ea0, Func Offset: 0x200
	// Line 4845, Address: 0x2d5ea8, Func Offset: 0x208
	// Line 4846, Address: 0x2d5ebc, Func Offset: 0x21c
	// Line 4847, Address: 0x2d5ed0, Func Offset: 0x230
	// Line 4848, Address: 0x2d5ee0, Func Offset: 0x240
	// Line 4850, Address: 0x2d5eec, Func Offset: 0x24c
	// Line 4854, Address: 0x2d5ef0, Func Offset: 0x250
	// Line 4852, Address: 0x2d5efc, Func Offset: 0x25c
	// Line 4853, Address: 0x2d5f00, Func Offset: 0x260
	// Line 4854, Address: 0x2d5f04, Func Offset: 0x264
	// Line 4856, Address: 0x2d5f18, Func Offset: 0x278
	// Line 4857, Address: 0x2d5f30, Func Offset: 0x290
	// Func End, Address: 0x2d5f60, Func Offset: 0x2c0
}

