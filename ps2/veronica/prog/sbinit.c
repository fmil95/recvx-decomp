#include "types.h"

unsigned char gMapleSendBuf[49184];
unsigned char gMapleRecvBuf[49184];
unsigned char* _BSG_END;

void sbInitSystem(int mode, int frame, int count);
void sbExitSystem();

























































































/* 100% match */
void sbInitSystem(int mode, int frame, int count) { // Line 99, Address: 0x12b530
    int temp; // not originally outputted by dwarf2cpp






    
    _builtin_set_imask(0xF); // Line 108, Address: 0x12b548

    
    syHwInit(); // Line 111, Address: 0x12b558

    
    temp = (((int)_BSG_END | 0x80000000) & ~0x1F) + 32; // Line 114, Address: 0x12b560






    
    syMallocInit(temp, (((int)_BSG_END & ~0x1FFFFFFF) | 0xD000000) - temp, _BSG_END); // Line 122, Address: 0x12b594
    
    
    njSetTextureMemorySize(1310720); // Line 125, Address: 0x12b59c

    
    njInitSystem(mode, frame, count); // Line 128, Address: 0x12b5ac

    
    syHwInit2(); // Line 131, Address: 0x12b5b4

    
    pdInitPeripheral(PDD_PLOGIC_ACTIVE, &gMapleRecvBuf, &gMapleSendBuf); // Line 134, Address: 0x12b5cc

    
    syRtcInit(); // Line 137, Address: 0x12b5d4






    
    _builtin_set_imask(0); // Line 145, Address: 0x12b5dc
    if (InitGdSystemEx(256) != 0) { // Line 146, Address: 0x12b5ec
        sbExitSystem(); // Line 147, Address: 0x12b5f4
        
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
        syBtExit(); // Line 171, Address: 0x12b5fc
    }
}

// 100% matching!
void sbExitSystem() 
{ 
    ExitGdSystem(); 
    
    syRtcFinish(); 
    
    pdExitPeripheral(); 
    
    njExitSystem(); 
    
    syMallocFinish(); 
    syHwFinish(); 
    
    _builtin_set_imask(0xF); 
}
