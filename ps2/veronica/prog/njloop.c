#include "njloop.h"

// 100% matching!
int main(int argc, char *argv[])
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
