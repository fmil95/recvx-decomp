/*typedef struct _HM;


typedef unsigned int type_0[12];
typedef unsigned char type_1[13422592];

struct _HM
{
	unsigned int Use_size;
	unsigned int Total_size;
	unsigned int dummy;
	_HM* pNext_work;
	unsigned int dummy64[12];
};

unsigned int __free_malloc_size;
_HM* Ps2_malloc_p;
unsigned char Ps2_malloc_mem[13422592];
unsigned int __max_malloc_size;

void syFree(void* ap);
void* syMalloc(unsigned int nbytes);
void syMallocFinish();
void syMallocInit();
void syMallocStat(unsigned int* wholeFreeSize, unsigned int* biggestFreeBlockSize);

// 
// Start address: 0x2d99f0
void syFree(void* ap)
{
	_HM* search_work;
	// Line 88, Address: 0x2d99f0, Func Offset: 0
	// Line 96, Address: 0x2d99f8, Func Offset: 0x8
	// Line 99, Address: 0x2d99fc, Func Offset: 0xc
	// Line 101, Address: 0x2d9a04, Func Offset: 0x14
	// Line 102, Address: 0x2d9a10, Func Offset: 0x20
	// Line 103, Address: 0x2d9a18, Func Offset: 0x28
	// Line 102, Address: 0x2d9a1c, Func Offset: 0x2c
	// Line 103, Address: 0x2d9a28, Func Offset: 0x38
	// Line 104, Address: 0x2d9a44, Func Offset: 0x54
	// Line 105, Address: 0x2d9a4c, Func Offset: 0x5c
	// Line 110, Address: 0x2d9a54, Func Offset: 0x64
	// Line 112, Address: 0x2d9a58, Func Offset: 0x68
	// Line 116, Address: 0x2d9a64, Func Offset: 0x74
	// Func End, Address: 0x2d9a6c, Func Offset: 0x7c
}*/

// 
// Start address: 0x2d9a70
void* syMalloc(unsigned int nbytes)
{
	//_HM* search_work;
	// Line 144, Address: 0x2d9a70, Func Offset: 0
	// Line 147, Address: 0x2d9a74, Func Offset: 0x4
	// Line 144, Address: 0x2d9a78, Func Offset: 0x8
	// Line 147, Address: 0x2d9a7c, Func Offset: 0xc
	// Line 151, Address: 0x2d9a84, Func Offset: 0x14
	// Line 153, Address: 0x2d9a8c, Func Offset: 0x1c
	// Line 158, Address: 0x2d9aa4, Func Offset: 0x34
	// Line 160, Address: 0x2d9aa8, Func Offset: 0x38
	// Line 162, Address: 0x2d9ab4, Func Offset: 0x44
	// Line 174, Address: 0x2d9ad0, Func Offset: 0x60
	// Line 181, Address: 0x2d9ad8, Func Offset: 0x68
	// Line 183, Address: 0x2d9ae0, Func Offset: 0x70
	// Line 184, Address: 0x2d9af8, Func Offset: 0x88
	// Line 185, Address: 0x2d9afc, Func Offset: 0x8c
	// Line 191, Address: 0x2d9b04, Func Offset: 0x94
	// Line 192, Address: 0x2d9b1c, Func Offset: 0xac
	// Line 195, Address: 0x2d9b24, Func Offset: 0xb4
	// Line 201, Address: 0x2d9b30, Func Offset: 0xc0
	// Line 195, Address: 0x2d9b38, Func Offset: 0xc8
	// Line 196, Address: 0x2d9b44, Func Offset: 0xd4
	// Line 198, Address: 0x2d9b4c, Func Offset: 0xdc
	// Line 201, Address: 0x2d9b54, Func Offset: 0xe4
	// Line 203, Address: 0x2d9b64, Func Offset: 0xf4
	// Line 204, Address: 0x2d9b6c, Func Offset: 0xfc
	// Func End, Address: 0x2d9b74, Func Offset: 0x104
	scePrintf("syMalloc - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x2d9b80
void syMallocFinish()
{
	// Line 225, Address: 0x2d9b80, Func Offset: 0
	// Func End, Address: 0x2d9b88, Func Offset: 0x8
}

// 
// Start address: 0x2d9b90
void syMallocInit()
{
	// Line 257, Address: 0x2d9b90, Func Offset: 0
	// Line 258, Address: 0x2d9ba0, Func Offset: 0x10
	// Line 259, Address: 0x2d9ba8, Func Offset: 0x18
	// Line 258, Address: 0x2d9bb0, Func Offset: 0x20
	// Line 259, Address: 0x2d9bb4, Func Offset: 0x24
	// Line 260, Address: 0x2d9bc0, Func Offset: 0x30
	// Line 261, Address: 0x2d9bcc, Func Offset: 0x3c
	// Line 262, Address: 0x2d9bd0, Func Offset: 0x40
	// Func End, Address: 0x2d9bd8, Func Offset: 0x48
}

// 
// Start address: 0x2d9be0
void syMallocStat(unsigned int* wholeFreeSize, unsigned int* biggestFreeBlockSize)
{
	_HM* search_work;
	// Line 292, Address: 0x2d9be0, Func Offset: 0
	// Line 290, Address: 0x2d9be8, Func Offset: 0x8
	// Line 293, Address: 0x2d9bf0, Func Offset: 0x10
	// Line 294, Address: 0x2d9bf8, Func Offset: 0x18
	// Line 295, Address: 0x2d9c18, Func Offset: 0x38
	// Line 298, Address: 0x2d9c20, Func Offset: 0x40
	// Line 299, Address: 0x2d9c24, Func Offset: 0x44
	// Line 300, Address: 0x2d9c30, Func Offset: 0x50
	// Line 301, Address: 0x2d9c3c, Func Offset: 0x5c
	// Line 302, Address: 0x2d9c44, Func Offset: 0x64
	// Func End, Address: 0x2d9c4c, Func Offset: 0x6c
}*/
