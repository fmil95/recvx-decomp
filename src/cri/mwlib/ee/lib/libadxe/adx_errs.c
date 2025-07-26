void (*adxerr_func)(void* err_obj, Char8* err_msg);
Char8 adxerr_msg[256] = { 0 };
void* adxerr_obj;

// 100% matching!
void ADXERR_CallErrFunc1(Char8* err_msg) 
{
    strncpy(adxerr_msg, err_msg, 255);

    if (adxerr_func != NULL)
    {
        adxerr_func(adxerr_obj, adxerr_msg);
    }
}

// 100% matching! 
void ADXERR_CallErrFunc2(Char8* err_msg, Char8* fname)
{
    strncpy(adxerr_msg, err_msg, 255);
    strncat(adxerr_msg, fname, 255);

    if (adxerr_func != NULL) 
    {
        adxerr_func(adxerr_obj, adxerr_msg);
    }
}

// 100% matching! 
void ADXERR_EntryErrFunc(void (*err_func)(void* err_obj, Char8* err_msg), void* err_obj) 
{
    adxerr_func = err_func; 
    adxerr_obj = err_obj;
}

// 100% matching!
void ADXERR_Finish(void) 
{
    memset(adxerr_msg, 0, sizeof(adxerr_msg));
    
    adxerr_func = NULL;
    adxerr_obj = NULL;
}

// 100% matching!
void ADXERR_Init(void)
{
    memset(adxerr_msg, 0, sizeof(adxerr_msg));
    
    adxerr_func = NULL;
    adxerr_obj = NULL;
}

// ADXERR_ItoA

void ADXERR_ItoA2(Sint32 ptid, Sint32 flid, Char8* err_msg, Sint32 msg_len)
{
    scePrintf("ADXERR_ItoA2 - UNIMPLEMENTED!\n");
}
