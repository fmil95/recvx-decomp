volatile Sint32 adxf_build;
Sint32 adxf_init_cnt;

void ADXF_Finish(void)
{
    scePrintf("ADXF_Finish - UNIMPLEMENTED!\n");
}

// 100% matching!
void ADXF_Init(void) 
{
    adxf_build;
    
    if (adxf_init_cnt == 0)
    {
        memset(adxf_obj, 0, sizeof(adxf_obj));
        memset(adxf_ptinfo, 0, sizeof(adxf_ptinfo)); 
        memset(adxf_cmd_hstry, ADXF_CMD_HSTRY_MAX - 1, sizeof(adxf_cmd_hstry));
        memset(adxf_cmd_ncall, 0, sizeof(adxf_cmd_ncall));
        
        adxf_hstry_no = 0;
        
        adxf_ocbi_fg = 0;
        
        adxf_flno = 0;
        
        adxf_ldptnw_hn = 0;
        adxf_ldptnw_ptid = -1; 
    }
    
    adxf_init_cnt++;
} 
