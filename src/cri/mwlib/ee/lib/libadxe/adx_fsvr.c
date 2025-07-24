void ADXT_ExecFsSvr(void);

// 100% matching!
void ADXT_ExecFsSvr(void)
{
    cvFsExecServer();
    ADXF_ExecServer();
    ADXSTM_ExecServer();
}
