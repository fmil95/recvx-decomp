static ADX_XPDOBJ adxpd_obj[8];

// ADXPD_Create
// ADXPD_Destroy
// ADXPD_EntryMono
// ADXPD_EntrySte
// adxpd_error
// ADXPD_ExecHndl
// ADXPD_ExecServer
// ADXPD_GetNumBlk
// ADXPD_GetStat

// 100% matching!
void ADXPD_Init(void) 
{
    memset(adxpd_obj, 0, sizeof(adxpd_obj));
}

// 100% matching!
void ADXPD_Reset(ADXPD xpd)
{
    if (xpd->stat == 3) 
    {
        xpd->stat = 0;
    }
}

// 100% matching!
void ADXPD_SetCoef(ADXPD xpd, Sint32 sfreq, Sint32 cof) 
{
    ADX_GetCoefficient(cof, sfreq, &xpd->k[0], &xpd->k[1]);
}

// ADXPD_SetMode
// ADXPD_Start
// ADXPD_Stop