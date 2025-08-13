static Sint32 dtr_init_cnt;

void* DTR_Create(SJ sjo, SJ sji)
{
    scePrintf("DTR_Create - UNIMPLEMENTED!\n");
}

void DTR_Destroy(void* dtr)
{
    scePrintf("DTR_Destroy - UNIMPLEMENTED!\n");
}

// DTR_ExecHndl

void DTR_ExecServer(void)
{
    scePrintf("DTR_ExecServer - UNIMPLEMENTED!\n");
}

// 100% matching!
void DTR_Finish(void) 
{
    dtr_init_cnt--;
}

// DTR_Init

void DTR_Start(void* dtr)
{
    scePrintf("DTR_Start - UNIMPLEMENTED!\n");
}

void DTR_Stop(void* dtr)
{
    scePrintf("DTR_Stop - UNIMPLEMENTED!\n");
}
