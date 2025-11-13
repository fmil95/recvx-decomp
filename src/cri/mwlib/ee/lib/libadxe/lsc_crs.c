#include "lsc_crs.h"

// 100% matching!
void LSC_LockCrs(LSC_CRS *crs)
{
    Sint32 temp; // FAKE: this var is not really needed, for some reason the compiler decided not to do tail-call for this function and this temp prevents it as well 
    
    SJCRS_Lock(); 

    temp = 0;
}

// 100% matching!
void LSC_UnlockCrs(LSC_CRS *crs)
{
    SJCRS_Unlock();
}
