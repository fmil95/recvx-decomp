#ifndef _ADX_SUHT_H_
#define _ADX_SUHT_H_

#include <adx_ps2.h>

// TODO: struct already defined in adx_sudv, define it somewhere else only once
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

void adxt_err_host(void *obj, const char *msg, void *hndl);
Sint32 ADXT_LoadFpCacheHost(ADXT_SPRM *sprm);
void ADXT_SetOpMode(ADXT_SPRM *sprm);
void ADXT_SetupHostFs(ADXT_SPRM *sprm);

#endif
