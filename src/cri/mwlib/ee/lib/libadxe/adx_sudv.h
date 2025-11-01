#ifndef _ADX_SUDV_H_
#define _ADX_SUDV_H_

#include <adx_ps2.h>

typedef struct ADXT_SPRM
{
    char* fname; 
    char* fpc;   
    int size;   
    int nrtry;   
    int speed;   
    int dtype;   
    int opmode;  
} ADXT_SPRM;

void adxt_err_dvd(void *obj, const char *msg, void *hndl);
Sint32 ADXT_LoadFpCacheDvd(ADXT_SPRM *sprm);
void ADXT_SetRdMode(ADXT_SPRM *sprm);
void ADXT_SetupDvdFs(ADXT_SPRM *sprm);

#endif
