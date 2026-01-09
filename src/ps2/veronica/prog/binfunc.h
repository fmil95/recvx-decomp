#ifndef _BINFUNC_H_
#define _BINFUNC_H_

typedef struct NJS_MDATA2_MOD
{
    // total size: 0x8
    void* p[2]; // offset 0x0, size 0x8
} NJS_MDATA2_MOD; 

/*typedef struct _anon0;
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
};*/

#endif
