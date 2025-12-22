#include "adx_errs.h"

#include <string.h>

void (*adxerr_func)(void *obj, const Sint8 *msg) = NULL;
void *adxerr_obj = NULL;
Sint8 adxerr_msg[256] __attribute__((aligned(64))) = { 0 }; 

// 100% matching!
void ADXERR_CallErrFunc1(const Sint8 *msg) 
{
    strncpy((char*)adxerr_msg, (char*)msg, sizeof(adxerr_msg) - 1);

    if (adxerr_func != NULL)
    {
        adxerr_func(adxerr_obj, adxerr_msg);
    }
}

// 100% matching! 
void ADXERR_CallErrFunc2(const Sint8 *msg1, const Sint8 *msg2)
{
    strncpy((char*)adxerr_msg, (char*)msg1, sizeof(adxerr_msg) - 1);
    strncat((char*)adxerr_msg, (char*)msg2, sizeof(adxerr_msg) - 1);

    if (adxerr_func != NULL) 
    {
        adxerr_func(adxerr_obj, adxerr_msg);
    }
}

// 100% matching! 
void ADXERR_EntryErrFunc(void (*func)(), void *obj)
{
    adxerr_func = func; 
    adxerr_obj = obj;
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

    ncol = strlen((const char*)&buf);
    
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
    
    strncat((char*)str, " ", (len - strlen((const char*)str)) - 1);
    
    ADXERR_ItoA(val2, &str[strlen((const char*)str)], 4 - strlen((const char*)str));
}
