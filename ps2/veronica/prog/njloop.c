#include "njloop.h"
#include "main.h"
#include "ps2_NaSystem.h"

// 100% matching!
void main() 
{
    njUserInit(); 
    
    while (TRUE) 
    { 
        if (njUserMain() < 0) 
        { 
            break;
        } 
        
        njWaitVSync();
    } 
    
    njUserExit(); 
} 
