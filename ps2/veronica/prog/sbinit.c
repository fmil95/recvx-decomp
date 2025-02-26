/*

typedef unsigned char type_0[49184];
typedef unsigned char type_1[49184];*/

unsigned char gMapleSendBuf[1024 * 24 * 2 + 32];
unsigned char gMapleRecvBuf[1024 * 24 * 2 + 32];
Uint8* _BSG_END;

/*void sbInitSystem(int mode, int frame, int count);
void sbExitSystem();*/

#define set_imask(mask)             _builtin_set_imask(mask)

/* SH-4 program area address. */
#define P1AREA   0x80000000

/* Define work RAM end address (16 MB). */
#define WORK_END (((Uint32) _BSG_END) & 0xe0000000 | 0x0d000000)

#define HEAP_AREA ((void*) ((((Uint32) _BSG_END | P1AREA) & 0xffffffe0) + 0x20))
#define HEAP_SIZE (WORK_END - (Uint32) HEAP_AREA)

void sbExitSystem(void); // TODO: remove this declaration
// 100% matching!
void sbInitSystem(Int mode, Int frame, Int count)
{
    set_imask(15); 
    
    syHwInit();
    syMallocInit(HEAP_AREA, HEAP_SIZE);
    
    njSetTextureMemorySize(1310720); 
    
    njInitSystem(mode, frame, count); 
    
    syHwInit2(); 
    
    pdInitPeripheral(PDD_PLOGIC_ACTIVE, &gMapleRecvBuf, &gMapleSendBuf); 
    
    syRtcInit(); 

    set_imask(0); 
    
    if (InitGdSystemEx(256) != 0) 
    { 
        sbExitSystem(); 
        
        syBtExit(); 
    }
}

// 
// Start address: 0x12b620
void sbExitSystem(void)
{ 
	// Line 179, Address: 0x12b620, Func Offset: 0
	// Line 183, Address: 0x12b628, Func Offset: 0x8
	// Line 191, Address: 0x12b630, Func Offset: 0x10
	// Line 194, Address: 0x12b638, Func Offset: 0x18
	// Line 197, Address: 0x12b640, Func Offset: 0x20
	// Line 205, Address: 0x12b648, Func Offset: 0x28
	// Line 208, Address: 0x12b650, Func Offset: 0x30
	// Line 211, Address: 0x12b658, Func Offset: 0x38
	// Line 212, Address: 0x12b660, Func Offset: 0x40
	// Func End, Address: 0x12b66c, Func Offset: 0x4c
	scePrintf("sbExitSystem - UNIMPLEMENTED!\n");
} 
