typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;

typedef int(*type_0)(int, int, int, unsigned int);
typedef int(*type_1)(int, int, int, int);
typedef void(*type_6)();

typedef unsigned short type_2[4];
typedef char type_3[18];
typedef char type_4[34];
typedef unsigned char type_5[16];
typedef unsigned char type_7[32];

struct _anon0
{
	unsigned int filesize;
	unsigned short blocks;
	unsigned char type;
	unsigned char copyflag;
	unsigned short headerofs;
	_anon5 time;
};

struct _anon1
{
	char vms_comment[18];
	char btr_comment[34];
	unsigned char game_name[16];
	void* icon_palette;
	void* icon_data;
	unsigned short icon_num;
	unsigned short icon_speed;
	void* visual_data;
	unsigned short visual_type;
	unsigned short reserved;
	void* save_data;
	unsigned int save_size;
};

struct _anon2
{
	_anon3 _Create;
	_anon4 _Modify;
	unsigned int FileSizeByte;
	unsigned short AttrFile;
	unsigned short Reserve1;
	unsigned int Reserve2;
	unsigned int PdaAplNo;
	unsigned char EntryName[32];
};

struct _anon3
{
	unsigned char Resv2;
	unsigned char Sec;
	unsigned char Min;
	unsigned char Hour;
	unsigned char Day;
	unsigned char Month;
	unsigned short Year;
};

struct _anon4
{
	unsigned char Resv2;
	unsigned char Sec;
	unsigned char Min;
	unsigned char Hour;
	unsigned char Day;
	unsigned char Month;
	unsigned short Year;
};

struct _anon5
{
	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned char dayofweek;
};

unsigned short visula_size[4];
int(*__bu_completecallback_func)(int, int, int, unsigned int);
int(*__bu_progresscallback_func)(int, int, int, int);

int buExit();
int buGetDiskInfo();
int buInit(void(*func)());
void buSetCompleteCallback(int(*func)(int, int, int, unsigned int));
void buSetProgressCallback(int(*func)(int, int, int, int));

// 
// Start address: 0x2d8c50
int buExit()
{
	// Line 132, Address: 0x2d8c50, Func Offset: 0
	// Func End, Address: 0x2d8c58, Func Offset: 0x8
}

// 
// Start address: 0x2d8c60
int buGetDiskInfo()
{
	// Line 240, Address: 0x2d8c60, Func Offset: 0
	// Func End, Address: 0x2d8c68, Func Offset: 0x8
}

// 
// Start address: 0x2d8c70
int buInit(void(*func)())
{
	int retry;
	int result;
	// Line 340, Address: 0x2d8c70, Func Offset: 0
	// Line 345, Address: 0x2d8c84, Func Offset: 0x14
	// Line 347, Address: 0x2d8c88, Func Offset: 0x18
	// Line 349, Address: 0x2d8c90, Func Offset: 0x20
	// Line 353, Address: 0x2d8c98, Func Offset: 0x28
	// Line 355, Address: 0x2d8ca0, Func Offset: 0x30
	// Line 361, Address: 0x2d8ca8, Func Offset: 0x38
	// Line 363, Address: 0x2d8cb4, Func Offset: 0x44
	// Line 364, Address: 0x2d8cc0, Func Offset: 0x50
	// Line 365, Address: 0x2d8cc8, Func Offset: 0x58
	// Line 367, Address: 0x2d8cd4, Func Offset: 0x64
	// Line 369, Address: 0x2d8ce0, Func Offset: 0x70
	// Line 371, Address: 0x2d8ce8, Func Offset: 0x78
	// Line 373, Address: 0x2d8cf4, Func Offset: 0x84
	// Line 375, Address: 0x2d8d00, Func Offset: 0x90
	// Line 378, Address: 0x2d8d08, Func Offset: 0x98
	// Line 380, Address: 0x2d8d18, Func Offset: 0xa8
	// Line 381, Address: 0x2d8d1c, Func Offset: 0xac
	// Func End, Address: 0x2d8d30, Func Offset: 0xc0
}

// 
// Start address: 0x2d8d30
void buSetCompleteCallback(int(*func)(int, int, int, unsigned int))
{
	// Line 726, Address: 0x2d8d30, Func Offset: 0
	// Line 727, Address: 0x2d8d34, Func Offset: 0x4
	// Func End, Address: 0x2d8d3c, Func Offset: 0xc
}

// 
// Start address: 0x2d8d40
void buSetProgressCallback(int(*func)(int, int, int, int))
{
	// Line 1218, Address: 0x2d8d40, Func Offset: 0
	// Line 1219, Address: 0x2d8d44, Func Offset: 0x4
	// Func End, Address: 0x2d8d4c, Func Offset: 0xc
}

