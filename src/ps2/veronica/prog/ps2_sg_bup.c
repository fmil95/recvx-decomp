#include "ps2_sg_bup.h"

unsigned short visula_size[4]; /* unused */
int(*__bu_completecallback_func)(int, int, int, unsigned int);
int(*__bu_progresscallback_func)(int, int, int, int);

// 100% matching! 
Sint32 buExit(void)
{
    return 0;
}

// 100% matching! 
Sint32 buGetDiskInfo(Sint32 drive, BUS_DISKINFO* info)
{
    return 0;
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
