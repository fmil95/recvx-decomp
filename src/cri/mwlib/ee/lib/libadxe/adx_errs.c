void (*adxerr_func)(void* adxerr_obj, Char8* adxerr_msg);
Char8 adxerr_msg[255];
void* adxerr_obj;

// 100% matching!
void ADXERR_CallErrFunc1(Char8* msg) 
{
    strncpy(adxerr_msg, msg, 255);

    if (adxerr_func != NULL)
    {
        adxerr_func(adxerr_obj, adxerr_msg);
    }
}

// ADXERR_CallErrFunc2
// ADXERR_EntryErrFunc
// ADXERR_Finish
// ADXERR_Init
// ADXERR_ItoA
// ADXERR_ItoA2
