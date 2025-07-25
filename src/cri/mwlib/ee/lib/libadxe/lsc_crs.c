

// 0% matching - devs made a mistake and defined this function to return an int
void LSC_LockCrs(Sint32* unused)
{
    SJCRS_Lock(); 
}

// 100% matching!
void LSC_UnlockCrs(Sint32* unused)
{
    SJCRS_Unlock();
}
