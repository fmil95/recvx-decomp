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

// ADXPD_Reset
// ADXPD_SetCoef
// ADXPD_SetMode
// ADXPD_Start
// ADXPD_Stop