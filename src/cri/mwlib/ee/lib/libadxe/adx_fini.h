#ifndef _ADX_FINI_H_
#define _ADX_FINI_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxf.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxf.h>

extern ADX_FS adxf_obj[ADXF_OBJ_MAX];
extern ADXF_PTINFO *adxf_ptinfo[ADXF_PART_MAX];
extern Sint32 adxf_ocbi_fg;
extern ADXF_CMD_HSTRY adxf_cmd_hstry[ADXF_CMD_HSTRY_MAX];
extern Uint16 adxf_cmd_ncall[ADXF_CMD_NUM_MAX];
extern Sint32 adxf_hstry_no;
extern Sint32 adxf_flno;
extern ADXF adxf_ldptnw_hn;
extern Sint32 adxf_ldptnw_ptid;

void ADXF_Finish(void);
void ADXF_Init(void);

#endif
