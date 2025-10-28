#ifndef _ADX_SUHT_H_
#define _ADX_SUHT_H_

void adxt_err_host(void *obj, const char *msg, void *hndl);
Sint32 ADXT_LoadFpCacheHost(ADXT_SPRM *sprm);
void ADXT_SetOpMode(ADXT_SPRM *sprm);
void ADXT_SetupHostFs(ADXT_SPRM *sprm);

#endif
