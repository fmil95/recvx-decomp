/*typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _SYS_RTC_DATE;
typedef struct _anon3;

typedef int(*type_3)(int, int, int, unsigned int);
typedef int(*type_4)(int, int, int, int);
typedef void(*type_7)();

typedef char type_0[18];
typedef char type_1[34];
typedef unsigned char type_2[16];
typedef int type_5[4];
typedef _anon0 type_6[8];
typedef unsigned char type_8[32];

struct _anon0
{
	unsigned short Ready;
	unsigned short IsFormat;
	unsigned int LastError;
	unsigned int ProgressCount;
	unsigned int ProgressMax;
	unsigned int Operation;
	_anon3 DiskInfo;
	unsigned int Connect;
	void* Work;
	unsigned int WorkSize;
	unsigned int Capacity;
	int MemMode;
};

struct _anon1
{
	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned char dayofweek;
};

struct _anon2
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

struct _SYS_RTC_DATE
{
	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned char dayofweek;
	unsigned char ageofmoon;
};

struct _anon3
{
	unsigned char volume[32];
	unsigned short total_blocks;
	unsigned short total_user_blocks;
	unsigned short free_blocks;
	unsigned short free_user_blocks;
	unsigned short total_exe_blocks;
	unsigned short free_exe_blocks;
	unsigned short block_size;
	unsigned short icon_no;
	_anon1 time;
};*/

static void BupInitCallback(void);
BACKUPINFO gBupInfo[8];
/*int(*BupProgress)(int, int, int, int);
int(*BupComplete)(int, int, int, unsigned int);

void BupInit();
void BupExit();
void ClearInfo(int drive);
int BupComplete(int drive, int op, int stat);
int BupProgress(int drive, int op, int count, int max);
void BupInitCallback();*/

// 100% matching!
void BupInit(void)
{
	memset(gBupInfo, 0, sizeof(gBupInfo));
    
	buInit(MAX_CAPS, USE_DRIVES, 0, BupInitCallback);
}

// 100% matching!
void BupExit(void)
{
	do 
    {
        
    } while (buExit() != BUD_ERR_OK);
}

// 100% matching! 
static void ClearInfo(Sint32 drive)
{
	BACKUPINFO* info;

	info = &gBupInfo[drive];
    
	info->ProgressCount = 0;
	info->ProgressMax = 0;
    
	info->Operation = 0;
    
	info->Ready = FALSE;
    
	info->IsFormat = FALSE;
    
	info->Work = NULL;
    
	memset(&info->DiskInfo, 0, sizeof(BUS_DISKINFO));
}

// 
// Start address: 0x2c9b20
static Sint32 BupComplete(Sint32 drive, Sint32 op, Sint32 stat, Uint32 param)
{
	int ret;
	//_anon0* info;
	// Line 222, Address: 0x2c9b20, Func Offset: 0
	// Line 218, Address: 0x2c9b28, Func Offset: 0x8
	// Line 222, Address: 0x2c9b2c, Func Offset: 0xc
	// Line 218, Address: 0x2c9b30, Func Offset: 0x10
	// Line 222, Address: 0x2c9b38, Func Offset: 0x18
	// Line 218, Address: 0x2c9b40, Func Offset: 0x20
	// Line 222, Address: 0x2c9b44, Func Offset: 0x24
	// Line 224, Address: 0x2c9b48, Func Offset: 0x28
	// Line 228, Address: 0x2c9b8c, Func Offset: 0x6c
	// Line 227, Address: 0x2c9b94, Func Offset: 0x74
	// Line 228, Address: 0x2c9b98, Func Offset: 0x78
	// Line 230, Address: 0x2c9b9c, Func Offset: 0x7c
	// Line 233, Address: 0x2c9ba4, Func Offset: 0x84
	// Line 235, Address: 0x2c9bac, Func Offset: 0x8c
	// Line 236, Address: 0x2c9bb8, Func Offset: 0x98
	// Line 237, Address: 0x2c9bc0, Func Offset: 0xa0
	// Line 242, Address: 0x2c9bc8, Func Offset: 0xa8
	// Line 245, Address: 0x2c9bd0, Func Offset: 0xb0
	// Line 246, Address: 0x2c9bdc, Func Offset: 0xbc
	// Line 247, Address: 0x2c9be8, Func Offset: 0xc8
	// Line 250, Address: 0x2c9bf0, Func Offset: 0xd0
	// Line 252, Address: 0x2c9bfc, Func Offset: 0xdc
	// Line 255, Address: 0x2c9c04, Func Offset: 0xe4
	// Line 258, Address: 0x2c9c0c, Func Offset: 0xec
	// Line 264, Address: 0x2c9c14, Func Offset: 0xf4
	// Line 268, Address: 0x2c9c20, Func Offset: 0x100
	// Line 271, Address: 0x2c9c24, Func Offset: 0x104
	// Line 270, Address: 0x2c9c30, Func Offset: 0x110
	// Line 271, Address: 0x2c9c34, Func Offset: 0x114
	// Func End, Address: 0x2c9c3c, Func Offset: 0x11c
	scePrintf("BupComplete - UNIMPLEMENTED!\n");
}

// 100% matching! 
static Sint32 BupProgress(Sint32 drive, Sint32 op, Sint32 count, Sint32 max)
{
	BACKUPINFO* info;

	info = &gBupInfo[drive];

	info->ProgressCount = count;
	info->ProgressMax = max;
    
	info->Operation = op;

	return BUD_CBRET_OK; 
}

// 100% matching! 
static void BupInitCallback(void)
{ 
    buSetCompleteCallback(BupComplete); 
    buSetProgressCallback(BupProgress); 
} 
