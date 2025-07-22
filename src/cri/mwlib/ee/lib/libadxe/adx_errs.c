void (*adxerr_func)(void* err_obj, Char8* err_msg);
Char8 adxerr_msg[255];
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

void ADXERR_CallErrFunc2(Char8* err_msg, Char8* fname)
{
    scePrintf("ADXERR_CallErrFunc2 - UNIMPLEMENTED!\n");
}

// ADXERR_EntryErrFunc

void ADXERR_Finish(void)
{
    scePrintf("ADXERR_Finish - UNIMPLEMENTED!\n");
}

// ADXERR_Init
// ADXERR_ItoA

void ADXERR_ItoA2(Sint32 ptid, Sint32 flid, Char8* err_msg, Sint32 msg_len)
{
    scePrintf("ADXERR_ItoA2 - UNIMPLEMENTED!\n");
}
