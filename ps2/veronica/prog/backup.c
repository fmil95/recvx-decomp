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

/******** �������J�[�h���\���� *******************************************/
/******** Memory card information structure ********************************/
typedef struct {
	Uint16 Ready;               /* �������J�[�h���}�E���g����Ă��邩      */
	                            /* Is memory card mounted ?                */
	Uint16 IsFormat;            /* �t�H�[�}�b�g����Ă��邩�ǂ���          */
	                            /* Is memory card formatted ?              */
	Uint32 LastError;           /* �Ō�ɔ��������G���[�R�[�h              */
	                            /* Error code which occured last.          */
	Uint32 ProgressCount;       /* �����o�߃J�E���g                        */
	                            /* Operation progress count.               */
	Uint32 ProgressMax;         /* �����o�߃J�E���g�ő�                    */
	                            /* Operattion progress count maximum.      */
	Uint32 Operation;           /* �������̃I�y���[�V�����R�[�h            */
	                            /* Operation code in handling now.         */
	BUS_DISKINFO DiskInfo;      /* �h���C�u���                            */
	                            /* Drive information.                      */
	Uint32 Connect;             /* �������[�J�[�h���ڑ�����Ă��邩        */
	                            /* Is memory card connected ?              */
	void* Work;                 /* ���[�N�A�h���X                          */
	                            /* Work address.                           */
	Uint32 WorkSize;            /* ���[�N�T�C�Y                            */
	                            /* Work size (bytes).                      */
	Uint32 Capacity;            /* �������J�[�h�̗e�ʃt���O(BUD_CAPACITY)  */
	                            /* Capacity flag of memory card.           */
    Sint32 MemMode;             // manually added
} BACKUPINFO;

/*===============================================================*/
/* �Ή����郁�����[�J�[�h�̍ő�e��                              */
/* Mamimum volume to use.                                        */
/*===============================================================*/

#define MAX_CAPS BUD_CAPACITY_1MB

/*===============================================================*/
/* �Ή����郁�����[�J�[�h�̃h���C�u��                            */
/* Number of memory card to use.                                 */
/*===============================================================*/

#define MAX_DRIVES 8
#define USE_DRIVES BUD_USE_DRIVE_ALL

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
    while (buExit() != 0) 
    {
        
    } 
} 

/*// 
// Start address: 0x2c9ae0
void ClearInfo(int drive)
{
	_anon0* info;
	// Line 206, Address: 0x2c9ae0, Func Offset: 0
	// Line 207, Address: 0x2c9af8, Func Offset: 0x18
	// Line 208, Address: 0x2c9afc, Func Offset: 0x1c
	// Line 209, Address: 0x2c9b00, Func Offset: 0x20
	// Line 210, Address: 0x2c9b04, Func Offset: 0x24
	// Line 211, Address: 0x2c9b08, Func Offset: 0x28
	// Line 213, Address: 0x2c9b0c, Func Offset: 0x2c
	// Line 212, Address: 0x2c9b14, Func Offset: 0x34
	// Line 213, Address: 0x2c9b18, Func Offset: 0x38
	// Func End, Address: 0x2c9b20, Func Offset: 0x40
}*/

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

// 
// Start address: 0x2c9c40
static Sint32 BupProgress(Sint32 drive, Sint32 op, Sint32 count, Sint32 max)
{
	//_anon0* info;
	// Line 278, Address: 0x2c9c40, Func Offset: 0
	// Line 281, Address: 0x2c9c58, Func Offset: 0x18
	// Line 282, Address: 0x2c9c5c, Func Offset: 0x1c
	// Line 283, Address: 0x2c9c60, Func Offset: 0x20
	// Line 286, Address: 0x2c9c64, Func Offset: 0x24
	// Func End, Address: 0x2c9c6c, Func Offset: 0x2c
	scePrintf("BupProgress - UNIMPLEMENTED!\n");
}

// 100% matching! 
static void BupInitCallback(void)
{ 
    buSetCompleteCallback(BupComplete); 
    buSetProgressCallback(BupProgress); 
} 
