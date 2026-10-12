#include "../../../cri/mwlib/ee/lib/libadxe/adx_crs.h"
#include "../../../cri/mwlib/ee/lib/libadxe/adx_mps2.h"

// 100% byte-matching object! 

Sint32 adxcrs_lvl = 0;
Sint32 adxcrs_msk = 0; /* unused */

void ADXCRS_Init(void) 
{
    adxcrs_lvl = 0;
}

void ADXCRS_Lock(void)
{
    if (adxcrs_lvl == 0)
    {
        ADXPS2_Lock();
    }
    
    adxcrs_lvl++;
}

void ADXCRS_Unlock(void) 
{
    adxcrs_lvl--;
    
    if (adxcrs_lvl == 0) 
    {
        ADXPS2_Unlock();
    }
}
