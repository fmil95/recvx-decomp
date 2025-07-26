void (*lsc_err_func)(void* err_obj, Char8* err_msg);
void* lsc_err_obj;
Char8 lsc_err_msg[256] = { 0 }; 

// LSC_CallErrFunc

// 100% matching! 
void LSC_EntryErrFunc(void (*err_func)(void* err_obj, Char8* err_msg), void* err_obj) 
{
    if (err_func == NULL) 
    {
        lsc_err_func = NULL; 
        lsc_err_obj = NULL;
    }
    else
    {
        lsc_err_func = err_func; 
        lsc_err_obj = err_obj;
    }
}
