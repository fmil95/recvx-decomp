Sint32 rna_crs_lvl;

// 100% matching!
void RNACRS_Finish(void) 
{
    rna_crs_lvl = 0;
}

// 100% matching!
void RNACRS_Init(void) 
{
    rna_crs_lvl = 0;
}

// 100% matching!
void RNACRS_Lock(void) 
{
    rna_crs_lvl++;
}

// RNACRS_Unlock