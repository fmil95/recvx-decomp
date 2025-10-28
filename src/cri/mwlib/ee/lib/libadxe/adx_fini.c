#include "adx_fini.h"

static char* volatile adxf_build = "\nADXF Ver 6.07 Build:Mar 13 2001 11:41:26\n";
static Sint32 adxf_init_cnt = 0;
static ADX_FS adxf_obj[ADXF_OBJ_MAX] = { 0 };
static ADXF_PTINFO *adxf_ptinfo[ADXF_PART_MAX] = { 0 };
static Sint32 adxf_ocbi_fg = 0;
static ADXF_CMD_HSTRY adxf_cmd_hstry[ADXF_CMD_HSTRY_MAX] = { 0 };
static Uint16 adxf_cmd_ncall[ADXF_CMD_NUM_MAX] = { 0 };
static Sint32 adxf_hstry_no = 0;
static Sint32 adxf_flno = 0;
static ADXF adxf_ldptnw_hn = NULL;
static Sint32 adxf_ldptnw_ptid = 0;

// 100% matching!
void ADXF_Finish(void)
{
    if (--adxf_init_cnt == 0)
    {
        ADXF_CloseAll();

        adxf_ldptnw_ptid = -1; 
        adxf_ldptnw_hn = NULL;

        adxf_flno = 0;

        adxf_ocbi_fg = 0;
        
        adxf_hstry_no = 0;
        
        memset(adxf_cmd_ncall, 0, sizeof(adxf_cmd_ncall));
        memset(adxf_cmd_hstry, ADXF_CMD_HSTRY_MAX - 1, sizeof(adxf_cmd_hstry));
        memset(adxf_ptinfo, 0, sizeof(adxf_ptinfo)); 
        memset(adxf_obj, 0, sizeof(adxf_obj));
    }
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
        
        adxf_ldptnw_hn = NULL;
        adxf_ldptnw_ptid = -1; 
    }
    
    adxf_init_cnt++;
} 
