#include "../../../cri/mwlib/ee/lib/libadxe/rna_crs.h"

// 100% byte-matching object! 

Sint32 rna_crs_lvl = 0;
Sint32 rna_crs_msk = 0; // unused 

void RNACRS_Init(void) 
{
    rna_crs_lvl = 0;
}

void RNACRS_Finish(void) 
{
    rna_crs_lvl = 0;
}

void RNACRS_Lock(void) 
{
    rna_crs_lvl++;
}

void RNACRS_Unlock(void) 
{
    rna_crs_lvl--;
}
