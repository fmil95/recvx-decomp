#include "../../../cri/mwlib/ee/lib/libadxe/adx_fsvr.h"
#include "../../../cri/mwlib/ee/lib/libadxe/adx_stmc.h"

// 100% byte-matching object! 

void ADXT_ExecFsSvr(void)
{
    cvFsExecServer();
    ADXF_ExecServer();
    ADXSTM_ExecServer();
}
