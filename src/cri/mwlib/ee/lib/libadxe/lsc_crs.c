#include "../../../cri/mwlib/ee/lib/libadxe/lsc_crs.h"

// 100% byte-matching object! 

void LSC_LockCrs(LSC_CRS *crs)
{
    Sint32 temp; // FAKE: the compiler decided not to do tail-call for this function, and this temp forces the stack usage 
    
    SJCRS_Lock(); 

    temp = 0;
}

void LSC_UnlockCrs(LSC_CRS *crs)
{
    SJCRS_Unlock();
}
