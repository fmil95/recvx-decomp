#include "sbinit.h"

unsigned char gMapleSendBuf[1024 * 24 * 2 + 32];
unsigned char gMapleRecvBuf[1024 * 24 * 2 + 32];
Uint8* _BSG_END;

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

// 100% matching!
void sbExitSystem(void)
{ 
    ExitGdSystem(); 
    
    syRtcFinish(); 
    
    pdExitPeripheral(); 
    
    njExitSystem(); 
    
    syMallocFinish(); 
    syHwFinish(); 
    
    set_imask(15); 
} 
