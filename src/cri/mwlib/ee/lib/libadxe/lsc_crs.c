

// 0% matching - devs made a mistake and defined this function to return an int
void LSC_LockCrs(void) 
{
    SJCRS_Lock(); 
}

// 100% matching!
void LSC_UnlockCrs(void) 
{
    SJCRS_Unlock();
}
