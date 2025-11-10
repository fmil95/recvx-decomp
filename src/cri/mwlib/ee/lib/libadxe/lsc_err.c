#include "lsc_err.h"

#include <stdio.h>

LSC_ERRFN lsc_err_func = NULL;
void *lsc_err_obj = NULL;
Sint8 lsc_err_msg[256] = { 0 }; 

// 100% matching! 
void LSC_CallErrFunc(const char *fmt, ...) // according to the symbols it is Sint8 instead of char, but char compiles easier
{
    __gnuc_va_list ap;

    va_start(ap, fmt);
    
    vsprintf((char*)lsc_err_msg, fmt, ap);
    
    if (lsc_err_func != NULL) 
    {
        lsc_err_func(lsc_err_obj, lsc_err_msg);
        
    }
    
    va_end(ap); 
}

// 100% matching! 
void LSC_EntryErrFunc(LSC_ERRFN errfn, void *obj) 
{
    if (errfn == NULL) 
    {
        lsc_err_func = NULL; 
        lsc_err_obj = NULL;
    }
    else
    {
        lsc_err_func = errfn; 
        lsc_err_obj = obj;
    }
}
