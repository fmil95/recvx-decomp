
static Sint32 sjx_init_cnt;

void* SJX_Create(SJ sj, Sint8 *work, Sint32 wksize)
{
    scePrintf("SJX_Create - UNIMPLEMENTED!\n");
}

void SJX_Destroy(void* sjx)
{
    scePrintf("SJX_Destroy - UNIMPLEMENTED!\n");
}

void SJX_ExecServer(void)
{
    scePrintf("SJX_ExecServer - UNIMPLEMENTED!\n");
}

// 100% matching!
void SJX_Finish(void) 
{
    sjx_init_cnt--;
}

void SJX_Init(void)
{
    scePrintf("SJX_Init - UNIMPLEMENTED!\n");
}

// sjx_rcvcbf
// SJX_Reset
// sjx_sndcbf
