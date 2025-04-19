Sint32 adxcrs_lvl;

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

void ADXCRS_Unlock()
{
    scePrintf("ADXCRS_Unlock - UNIMPLEMENTED!\n");
}
