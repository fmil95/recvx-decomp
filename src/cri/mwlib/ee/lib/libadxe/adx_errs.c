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
// ADXERR_Finish
// ADXERR_Init
// ADXERR_ItoA
// ADXERR_ItoA2
