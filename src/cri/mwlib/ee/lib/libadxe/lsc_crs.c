#include "lsc_crs.h"

// 100% matching!
void LSC_LockCrs(LSC_CRS *crs)
{
    SJCRS_Lock(); 

    // devs made a mistake and defined this function to return the output of SJCRS_Lock(), the following line simulates the return
    if (0 != 0) { while (TRUE); }
}

// 100% matching!
void LSC_UnlockCrs(LSC_CRS *crs)
{
    SJCRS_Unlock();
}
