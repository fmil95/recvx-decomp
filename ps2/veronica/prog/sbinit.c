#include "common.h"
#include "types.h"

unsigned char gMapleSendBuf[49184];
unsigned char gMapleRecvBuf[49184];
unsigned char* _BSG_END;

void sbInitSystem(int mode, int frame, int count);
void sbExitSystem();

// 100% matching!
void sbInitSystem(int mode, int frame, int count) 
{ 
    int temp; // not from the debugging symbols

    _builtin_set_imask(0xF); 
    
    syHwInit(); 
    
    temp = (((int)_BSG_END | 0x80000000) & ~0x1F) + 32; 
    
    syMallocInit(temp, (((int)_BSG_END & 0xE0000000) | 0xD000000) - temp, _BSG_END);
    
    njSetTextureMemorySize(1310720); 
    
    njInitSystem(mode, frame, count); 
    
    syHwInit2(); 
    
    pdInitPeripheral(PDD_PLOGIC_ACTIVE, &gMapleRecvBuf, &gMapleSendBuf); 
    
    syRtcInit(); 

    _builtin_set_imask(0); 
    
    if (InitGdSystemEx(256) != 0) 
    { 
        sbExitSystem(); 
        
        syBtExit(); 
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
