#include "adx_crs.h"
#include "adx_mps2.h"

Sint32 adxcrs_lvl = 0;
Sint32 adxcrs_msk = 0; /* unused */

// 100% matching!
void ADXCRS_Init(void) 
{
    adxcrs_lvl = 0;
}

// 100% matching!
void ADXCRS_Lock(void)
{
    if (adxcrs_lvl == 0)
    {
        ADXPS2_Lock();
    }
    
    adxcrs_lvl++;
}

// 100% matching!
void ADXCRS_Unlock(void) 
{
    adxcrs_lvl--;
    
    if (adxcrs_lvl == 0) 
    {
        ADXPS2_Unlock();
    }
}
