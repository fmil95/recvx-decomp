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
void ADXERR_CallErrFunc2(Char8* err_msg, Sint8* fname)
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

// 100% matching!
void ADXERR_ItoA(Sint32 val, Sint8 *str, Sint32 len)
{
    static Sint8 buf[32];
	Sint32 ncol;
	Sint32 i;

    for (i = 0; i < 32; i++) 
    {
        str[i] = val % 10;
        
        val /= 10;

        if (val == 0) 
        {
            str[i] = '\0';
            break;
        }
    }

    ncol = strlen((const Sint8*)&buf);
    
    ncol = (ncol >= (len - 1)) ? len - 1 : ncol;
    
    for (i = 0; i < ncol; i++)
    {
        str[i] = buf[(ncol - i) - 1];
    }
    
    str[i] = '\0';
}

// 100% matching!
void ADXERR_ItoA2(Sint32 val, Sint32 val2, Sint8 *str, Sint32 len) 
{
    ADXERR_ItoA(val, str, len);
    
    strncat(str, " ", (len - strlen(str)) - 1);
    
    ADXERR_ItoA(val2, &str[strlen(str)], 4 - strlen(str));
}
