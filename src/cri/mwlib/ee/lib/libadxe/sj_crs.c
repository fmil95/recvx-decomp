Sint32 sjcrs_lvl;

// 100% matching!
void SJCRS_Init(void) 
{
    sjcrs_lvl = 0;
}

// 100% matching!
void SJCRS_Lock(void) 
{
    sjcrs_lvl++;
}

// SJCRS_Unlock