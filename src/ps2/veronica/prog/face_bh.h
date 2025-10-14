#ifndef _FACE_BH_H_
#define _FACE_BH_H_

/*typedef struct _anon0;
typedef struct cnkobj;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;
typedef struct _anon11;
typedef struct _anon12;
typedef struct npobj;
typedef struct _anon13;


typedef float type_0[3];
typedef int type_1[3];
typedef float type_2[3];
typedef unsigned char type_3[64];
typedef float type_4[16];
typedef char type_5[4];
typedef unsigned short type_6[2];
typedef unsigned int type_7[3];
typedef cnkobj type_8[9];
typedef cnkobj* type_9[9];
typedef float type_10[3];
typedef float type_11[3][9];
typedef int type_12[3];
typedef int type_13[3][9];
typedef unsigned int type_14[4];
typedef unsigned int type_15[3];
typedef float type_16[16][9];
typedef unsigned char type_17[64];
typedef unsigned char type_18[64];
typedef char type_19[9];
typedef unsigned int type_20[2];
typedef float type_21[3];
typedef int type_22[3];
typedef float type_23[3];
typedef int type_24[3];
typedef float type_25[3];
typedef float type_26[3];
typedef float type_27[32];
typedef int type_28[3];
typedef float type_29[4];
typedef npobj* type_30[256];
typedef cnkobj* type_31[256];
typedef cnkobj* type_32[256];
typedef _anon0* type_33[32];
typedef float type_34[32];

struct _anon0
{
	float x;
	float y;
	float z;
};

struct cnkobj
{
	unsigned int evalflags;
	_anon1* model;
	float pos[3];
	int ang[3];
	float scl[3];
	cnkobj* child;
	cnkobj* sibling;
};

struct _anon1
{
	int* vlist;
	short* plist;
	_anon0 center;
	float r;
};

struct _anon2
{
	_anon1* src;
	_anon1* dst;
	_anon7* list;
	_anon6* vlist;
	_anon0** nvpt;
	int lnum;
	cnkobj* obj;
	_anon3* jaw;
	int jnum;
	unsigned int Dummy[3];
	float jmat1[16];
	float jmat2[16];
	_anon4 param;
	cnkobj eye[9];
	cnkobj* eyesrc[9];
	float eyepos[3][9];
	int eyeang[3][9];
	unsigned int Dummy2[3];
	float eyemat[16][9];
	_anon3* tang;
	int tnum;
	_anon1* tangsrc;
	_anon1* tangdst;
	cnkobj tangobj;
	cnkobj* tangorg;
	float tangpos[3];
	int tangang[3];
	cnkobj tooth;
	cnkobj* toothsrc;
	float toothpos[3];
	int toothang[3];
	unsigned int mode;
	_anon4* face;
	int fnum;
	int vtype;
	int vtop;
	int ntop;
	int vofs;
	_anon8* head;
};

struct _anon3
{
	int id;
	float rate;
};

struct _anon4
{
	float muscle[32];
	float jawang;
	float jawtrans;
	_anon0 eye;
	float tangx;
	float tangy;
	float tangz;
	short frame;
	short flag;
};

struct _anon5
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon11* texP;
	_anon12* owP;
};

struct _anon6
{
	short id;
	char mnum;
	char nvnum;
};

struct _anon7
{
	int id;
	_anon0 vec;
	float scal;
};

struct _anon8
{
	char id[4];
	unsigned short version;
	unsigned short flag;
	unsigned short jawId[2];
	unsigned int nAttr;
	unsigned int nList;
	unsigned int nConnect;
	unsigned int nJaw;
	unsigned int nTang;
	unsigned int nFace;
	unsigned int reserve[4];
	char faceId;
	char tangId;
	char toothId;
	char eyeId[9];
};

struct _anon9
{
	unsigned char* top;
	unsigned char* ptr;
	short cnt;
	short time;
	unsigned char cur;
	unsigned char next;
	unsigned short flag;
};

struct _anon10
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon11
{
	_anon10* textures;
	unsigned int nbTexture;
};

struct _anon12
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct npobj
{
	unsigned int evalflags;
	_anon1* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon13
{
	float x;
	float y;
	float z;
	float w;
};*/

#endif
