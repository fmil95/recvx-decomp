#include "adx_fsvr.h"

// 100% matching!
void ADXT_ExecFsSvr(void)
{
    cvFsExecServer();
    ADXF_ExecServer();
    ADXSTM_ExecServer();
}
