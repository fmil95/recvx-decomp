static ADX_XPDOBJ adxpd_obj[8];

// ADXPD_Create

// 100% matching!
void ADXPD_Destroy(ADXPD xpd)
{
    if (xpd != NULL) 
    {
        xpd->used = FALSE;
        
        memset(xpd, 0, sizeof(ADX_XPDOBJ));
    }
}

// 100% matching!
Sint32 ADXPD_EntryMono(ADXPD xpd, Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l)
{
    if (xpd->stat == 0)
    {
        xpd->xprm.ibuf = ibuf;
        
        xpd->xprm.nch = 1;
        
        xpd->xprm.nblk = nblk;
        
        xpd->xprm.obuf_l = obuf_l;
        xpd->xprm.obuf_r = NULL;
        
        return 1;
    }
    
    return 0;
}

// ADXPD_EntrySte
// adxpd_error
// ADXPD_ExecHndl
// ADXPD_ExecServer

// 100% matching!
Sint32 ADXPD_GetNumBlk(ADXPD xpd)
{
    return xpd->ndecblk;
}

// 100% matching!
Sint32 ADXPD_GetStat(ADXPD xpd)
{
    return xpd->stat;
}

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

// 100% matching!
void ADXPD_SetMode(ADXPD xpd, Sint32 mode)
{
    xpd->mode = mode;
}

// 100% matching!
void ADXPD_Start(ADXPD xpd)
{
    if (xpd->stat == 0)
    {
        xpd->ndecblk = 0;
        
        xpd->stat = 1;
    }
}

// 100% matching!
void ADXPD_Stop(ADXPD xpd)
{
    xpd->stat = 0;
    
    memset(xpd->dly, 0, sizeof(xpd->dly));
}
