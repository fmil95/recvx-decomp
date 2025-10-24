#include "adx_xpnd.h"

static ADX_XPDOBJ adxpd_obj[8] = { 0 };
static Sint32 adxpd_internal_error;

// 100% matching!
ADXPD ADXPD_Create(void)
{
    Sint32 no;
	ADXPD xpd1;
    ADXPD xpd2;

    for (no = 0; no < 8; no++) 
    {
        xpd1 = &adxpd_obj[no];
        
        if (xpd1->used == FALSE) 
        {
            break;
        }
    } 

    if (no == 8) 
    {
        return NULL;
    }

    xpd2 = &adxpd_obj[no];
    
    memset(xpd2, 0, sizeof(ADX_XPDOBJ));
    
    xpd2->used = TRUE;
    
    xpd2->xno = no;
    
    xpd2->mode = 0;
    
    xpd2->stat = 0;
    
    ADX_GetCoefficient(500, 44100, &xpd2->k[0], &xpd2->k[1]);
    
    memset(xpd2->dly, 0, sizeof(xpd2->dly));

    return xpd2;
}

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

// 100% matching!
Sint32 ADXPD_EntrySte(ADXPD xpd, Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *obuf_r)
{
    if (xpd->stat == 0)
    {
        xpd->xprm.nch = 2;
        
        xpd->xprm.ibuf = ibuf;
        
        xpd->xprm.nblk = nblk;
        
        xpd->xprm.obuf_l = obuf_l;
        xpd->xprm.obuf_r = obuf_r;
        
        return 1;
    }
    
    return 0;
}

// 100% matching!
void adxpd_error(void) 
{
    adxpd_internal_error = 1;
}

// 100% matching!
void ADXPD_ExecHndl(ADXPD xpd)
{
    if (xpd->stat == 1) 
    {
        xpd->stat = 2;
    }
    
    if (xpd->stat == 2) 
    {
        if (xpd->xprm.nch == 1) 
        {
            xpd->ndecblk = ADX_DecodeMonoFloat(xpd->xprm.ibuf, xpd->xprm.nblk, xpd->xprm.obuf_l, &xpd->dly[0][0], xpd->k[0], xpd->k[1]);
        } 
        else
        {
            xpd->ndecblk = ADX_DecodeSteFloat(xpd->xprm.ibuf, xpd->xprm.nblk, xpd->xprm.obuf_l, &xpd->dly[0][0], xpd->xprm.obuf_r, &xpd->dly[1][0], xpd->k[0], xpd->k[1]);
           
            if ((xpd->ndecblk - ((xpd->ndecblk / 2) * 2)) == 1)
            {
                adxpd_error();
            }
        }
        
        xpd->stat = 3;
    }
}

// 100% matching!
void ADXPD_ExecServer(void) 
{
    ADXPD xpd;
    Sint32 no;

    for (no = 0; no < 8; no++) 
    {
        xpd = &adxpd_obj[no];

        if (xpd->used == TRUE)
        {
            ADXPD_ExecHndl(xpd);
        }
    }
}

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
