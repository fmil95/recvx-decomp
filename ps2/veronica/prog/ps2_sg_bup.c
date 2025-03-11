/*typedef struct _anon0;
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

unsigned short visula_size[4];*/
int(*__bu_completecallback_func)(int, int, int, unsigned int);
int(*__bu_progresscallback_func)(int, int, int, int);

/*int buExit();
int buGetDiskInfo();
int buInit(void(*func)());
void buSetCompleteCallback(int(*func)(int, int, int, unsigned int));
void buSetProgressCallback(int(*func)(int, int, int, int));*/

// 
// Start address: 0x2d8c50
int buExit()
{
	// Line 132, Address: 0x2d8c50, Func Offset: 0
	// Func End, Address: 0x2d8c58, Func Offset: 0x8
	scePrintf("buExit - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x2d8c60
int buGetDiskInfo()
{
	// Line 240, Address: 0x2d8c60, Func Offset: 0
	// Func End, Address: 0x2d8c68, Func Offset: 0x8
	scePrintf("buGetDiskInfo - UNIMPLEMENTED!\n");
}

// 100% matching!
Sint32 buInit(Sint32 capacity, Sint32 drives, void* work, BU_INITCALLBACK func)
{ 
    int result;
    int retry;
    
    for (retry = 0; retry < 10; retry++) 
    {
        result = sceMcInit(); 
        
        if (result == 0)
        { 
            func(); 
            
            return 0; 
        }
        
        if (result == -101)
        { 
            printf("sceMcInitError\n"); 
        }
        else 
        { 
            if (result == -120) 
            { 
                printf("old irx version ... mcserv.irx\n"); 
                
                return -256; 
            }
            
            if (result == -121)
            { 
                printf("old irx version ... mcman.irx\n"); 
                
                return -256; 
            }
        }
    } 
    
    return -256;
}

// 100% matching! 
void buSetCompleteCallback(BU_COMPLETECALLBACK func)
{
    __bu_completecallback_func = func;
}

// 100% matching! 
void buSetProgressCallback(BU_PROGRESSCALLBACK func)
{
    __bu_progresscallback_func = func;
}
