typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;


typedef unsigned char type_0[16384];
typedef unsigned char type_1[450560];
typedef int type_2[15];

struct _anon0
{
	int status;
	int dummy[15];
};

struct _anon1
{
	int Frame_rate;
	int Data_size;
	short Width;
	short Height;
	int Nframe;
};

struct _anon2
{
	unsigned char v[450560];
};

struct _anon3
{
	unsigned char data[16384];
	_anon1 Ipu_header;
	int status;
	int put;
	int count;
	int size;
};

struct _anon4
{
	int pts;
	int dts;
	int pos;
	int len;
};

_anon4* timeStamp;
char* videoDecStack;
unsigned char* audioBuff;
_anon3* readBuf;
<unknown fundamental type (0xa510)>* viBufData;
<unknown fundamental type (0xa510)>* viBufTag;
_anon2* voBufData;
_anon0* voBufTag;
unsigned char* mpegWork;
void* vpWorkMemoryTop;


