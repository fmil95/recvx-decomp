#ifndef _PS2_NINJACNK_H_
#define _PS2_NINJACNK_H_

#include "types.h"

void	njInit3D( NJS_VERTEX_BUF *vbuf, Int vn );
/*void njDrawModel(_anon18* pModel);*/
void	njControl3D( Uint32 flag );
/*void njSetConstantAttr(unsigned int ulAnd, unsigned int ulOr);
void njSetConstantMaterial(_anon4* pMaterial);
void njSetCnkBlendMode(unsigned int ulAttr);
void njCnkModDrawModel(_anon5* pModel);*/
void    njCnkSetEasyLight( Float x,Float y,Float z );
void    njCnkSetEasyLightIntensity( Float inten, Float ambient );
void    njCnkSetEasyLightColor( Float r, Float g, Float b );
/*void njCnkSetEasyMultiLight(int iLightMax);*/
void    njCnkSetEasyMultiLightSwitch(Int light, Int flag);
void    njCnkSetEasyMultiAmbient(Float ar, Float ag, Float ab);
void    njCnkSetEasyMultiLightColor(Int light, Float lr, Float lg, Float lb);
void    njCnkSetEasyMultiLightVector(Float vx, Float vy, Float vz);
/*void njCnkSetEasyMultiLightPoint(int iLightNum, float fX, float fY, float fZ);
void njCnkSetEasyMultiLightRange(int iLightNum, float fNear, float fFar);*/
void    njCnkSetEasyMultiLightMatrices(void);
void    njCnkSetSimpleLight( Float x,Float y,Float z );
void    njCnkSetSimpleLightIntensity( Float inten, Float ambient );
void    njCnkSetSimpleLightColor( Float r, Float g, Float b );
void    njCnkSetSimpleMultiLight(Int num);
void    njCnkSetSimpleMultiLightSwitch(Int light, Int flag);
void    njCnkSetSimpleMultiAmbient(Float ar, Float ag, Float ab);
void    njCnkSetSimpleMultiLightColor(Int light, Float lr, Float lg, Float lb);
void    njCnkSetSimpleMultiLightVector(Float vx, Float vy, Float vz);
/*void njCnkSetSimpleMultiLightPoint(int iLightNum, float fX, float fY, float fZ);
void njCnkSetSimpleMultiLightRange(int iLightNum, float fNear, float fFar);*/
void    njCnkSetSimpleMultiLightMatrices(void);
/*void njCnkEasyDrawModel(_anon5* pModel);*/
void    njCnkEasyDrawObject( NJS_CNK_OBJECT *model );
/*void njCnkEasyMultiDrawModel(_anon5* pModel);*/
void    njCnkEasyMultiDrawObject( NJS_CNK_OBJECT *model );
/*void njCnkSimpleDrawModel(_anon5* pModel);
void njCnkSimpleMultiDrawModel(_anon5* pModel);*/
void njCnkSetCurrentDrawMode(unsigned int ulMode);
int njCnkDrawModelLocal(NJS_CNK_MODEL* pModel);
/*int njCnkDrawModelLocalMod(_anon5* pModel);
tagCHUNK_HEAD* njCnkCn(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCbBa(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCbDa(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCbExp(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCtTid(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCmD(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCmA(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCmDa(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCmS(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCmDs(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCmAs(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCmDas(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCoP4(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCoSt(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCvVn(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCvVnPs2(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCvVMod(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCoP3(tagCHUNK_HEAD* pCnk);
tagCHUNK_HEAD* njCnkCs(tagCHUNK_HEAD* pCnk);*/
int _CVV(float* v0);
CHUNK_HEAD* njCnkDefaultLong(CHUNK_HEAD* pCnk);
CHUNK_HEAD* njCnkDefaultShort(CHUNK_HEAD* pCnk);
/*void njCnkEasyMultiDrawObjectI(cnkobj* pObject);*/

/*typedef struct _anon0;
typedef struct tagCHUNK_HEAD;
typedef union _anon1;
typedef struct _anon2;
typedef struct cnkobj;
typedef struct _anon3;
typedef struct tagVU1_STRIP_BUF;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct tagCNK_PRIM_BUF;
typedef struct _anon10;
typedef struct _anon11;
typedef struct tagCNK_LIGHT;
typedef struct _anon12;
typedef struct _anon13;
typedef struct _anon14;
typedef struct tagVU1_COLOR;
typedef struct _anon15;
typedef struct _anon16;
typedef struct _anon17;
typedef struct _anon18;
typedef struct tagCNK_LIGHTING;
typedef struct _anon19;
typedef union _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct _anon23;
typedef struct _anon24;
typedef struct _anon25;
typedef struct _anon26;

typedef void(*type_3)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
typedef tagCHUNK_HEAD*(*type_5)(tagCHUNK_HEAD*);
typedef void(*type_11)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
typedef void(*type_13)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
typedef void(*type_21)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
typedef void(*type_27)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
typedef void(*type_29)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
typedef void(*type_31)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);
typedef void(*type_33)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short);

typedef int type_0[3];
typedef _anon2 type_1[2];
typedef float type_2[3];
typedef _anon6 type_4[5];
typedef tagCHUNK_HEAD*(*type_6)(tagCHUNK_HEAD*)[76];
typedef int type_7[8];
typedef float type_8[16];
typedef tagCNK_LIGHT type_9[6];
typedef unsigned short type_10[8];
typedef int type_12[8];
typedef void(*type_14)(unsigned long, tagVU1_STRIP_BUF*, unsigned short, unsigned short)[32];
typedef tagCNK_LIGHT type_15[6];
typedef float type_16[4];
typedef char type_17[4];
typedef float type_18[4];
typedef float type_19[4][4];
typedef unsigned char type_20[56];
typedef float type_22[4][11];
typedef tagCNK_LIGHTING type_23[4];
typedef unsigned short type_24[8];
typedef unsigned short type_25[8][4];
typedef unsigned int type_26[27];
typedef unsigned int type_28[5];
typedef unsigned int type_30[11];
typedef tagVU1_STRIP_BUF type_32[200];
typedef float type_34[2];
typedef _anon22 type_35[12];
typedef float type_36[3];
typedef float type_37[3];

struct _anon0
{
	void* texaddr;
	_anon23 texsurface;
};

struct tagCHUNK_HEAD
{
	unsigned char ucType;
	unsigned char ucHeadBits;
	unsigned short usSize;
};

union _anon1
{
	unsigned int color;
	_anon24 tex;
	_anon25 argb;
};

struct _anon2
{
	_anon22 node[12];
	unsigned int nodeNum;
	float pad[3];
};

struct cnkobj
{
	unsigned int evalflags;
	_anon5* model;
	float pos[3];
	int ang[3];
	float scl[3];
	cnkobj* child;
	cnkobj* sibling;
};

struct _anon3
{
	unsigned char ucType;
	unsigned char ucAttr;
	unsigned short usSize;
	unsigned short usIndexOfs;
	unsigned short usIndexMax;
};

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

struct _anon4
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon5
{
	int* vlist;
	short* plist;
	_anon9 center;
	float r;
};

struct _anon6
{
	unsigned int xyzflag;
	unsigned int clipmask;
};

struct _anon7
{
	_anon6 plane[5];
	unsigned int planeNum;
};

struct _anon8
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

struct _anon9
{
	float x;
	float y;
	float z;
};

struct tagCNK_PRIM_BUF
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

struct _anon10
{
	float x;
	float y;
	float z;
	float w;
};

struct _anon11
{
	_anon20 a;
	float sx;
	float sy;
	float oow;
	_anon9 point;
	unsigned int reserve;
	float u;
	float v;
	float inten[2];
	_anon9 vector;
	unsigned int flag;
};

struct tagCNK_LIGHT
{
	unsigned int ulState;
	unsigned int ulMode;
	float fNearRR;
	float fFarRR;
	float fR;
	float fG;
	float fB;
	float fI;
	float fWx;
	float fWy;
	float fWz;
	float pad0;
	float fCx;
	float fCy;
	float fCz;
	float pad1;
};

struct _anon12
{
	_anon1 diffuse;
	_anon1 specular;
	float exponent;
	unsigned int attr_texId;
	unsigned int attrflags;
};

struct _anon13
{
	unsigned short type_matId;
	unsigned short nbMesh;
	short* meshes;
	unsigned int* attrs;
	_anon9* normals;
	_anon1* vertcolor;
	_anon1* vertuv;
};

struct _anon14
{
	unsigned int gindex;
	unsigned int size;
	unsigned int count;
	void* addr;
	void* before;
	void* after;
};

struct tagVU1_COLOR
{
	float fR;
	float fG;
	float fB;
	float fA;
};

struct _anon15
{
	unsigned char ucType;
	unsigned char ucAttr;
	unsigned short usSize;
	unsigned short usIndexOfs;
	unsigned short usIndexMax;
	unsigned char ucPadding[56];
};

struct _anon16
{
	struct
	{
		unsigned long TBP0 : 14;
		unsigned long TBW : 6;
		unsigned long PSM : 6;
		unsigned long TW : 4;
		unsigned long TH : 4;
		unsigned long TCC : 1;
		unsigned long TFX : 2;
		unsigned long CBP : 14;
		unsigned long CPSM : 4;
		unsigned long CSM : 1;
		unsigned long CSA : 5;
		unsigned long CLD : 3;
	};
};

struct _anon17
{
	char FileId[4];
	unsigned char FormatVersion;
	unsigned char FormatId;
	unsigned short Pictures;
	unsigned int Gindex;
	unsigned char OrgColorType;
	unsigned char OrgTexType;
	unsigned short ClutChange;
	unsigned int PalNum;
	unsigned int PalData[27];
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
	_anon16 GsTex0;
	_anon19 GsTex1;
	unsigned int GsRegs;
	unsigned int GsTexClut;
	_anon14 admin;
	unsigned int TpFlag;
	unsigned int ClampFlag;
};

struct _anon18
{
	_anon9* points;
	_anon9* normals;
	int nbPoint;
	_anon13* meshsets;
	_anon12* mats;
	unsigned short nbMeshset;
	unsigned short nbMat;
	_anon9 center;
	float r;
};

struct tagCNK_LIGHTING
{
	tagCNK_LIGHT* pLightTop;
	int lLightMax;
	tagVU1_COLOR* pDiffuse;
	tagVU1_COLOR* pSpecula;
	tagVU1_COLOR* pAmbient;
	unsigned int pad[11];
};

struct _anon19
{
	struct
	{
		unsigned long LCM : 1;
		unsigned long pad01 : 1;
		unsigned long MXL : 3;
		unsigned long MMAG : 1;
		unsigned long MMIN : 3;
		unsigned long MTBA : 1;
		unsigned long pad10 : 9;
		unsigned long L : 2;
		unsigned long pad21 : 11;
		unsigned long K : 12;
		unsigned long pad44 : 20;
	};
};

union _anon20
{
	unsigned int work;
	unsigned int clip;
};

struct _anon21
{
	float dist;
	float w;
	float h;
	float cx;
	float cy;
};

struct _anon22
{
	float vertex[4];
	float color[4];
	float texUV[4];
	float clipV[4];
};

struct _anon23
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

struct _anon24
{
	short u;
	short v;
};

struct _anon25
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

struct _anon26
{
	_anon2 triangle;
	_anon2 narray[2];
	_anon2* in;
	_anon2* out;
	unsigned int rotflag;
	unsigned int flipflag;
};*/

#endif
