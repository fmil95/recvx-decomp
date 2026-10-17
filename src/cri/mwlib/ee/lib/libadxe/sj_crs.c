#include "../../../cri/mwlib/ee/lib/libadxe/sj_crs.h"

// 100% byte-matching object! 

Sint32 sjcrs_lvl = 0;
Sint32 sjcrs_msk = 0; // unused 

void SJCRS_Init(void) 
{
    sjcrs_lvl = 0;
}

void SJCRS_Lock(void) 
{
    sjcrs_lvl++;
}

void SJCRS_Unlock(void) 
{
    sjcrs_lvl--;
}
