BACKUPINFO gBupInfo[8];

void BupInit(void);
void BupExit(void);
static void ClearInfo(Sint32 drive);
static Sint32 BupComplete(Sint32 drive, Sint32 op, Sint32 stat, Uint32 param);
static Sint32 BupProgress(Sint32 drive, Sint32 op, Sint32 count, Sint32 max);
static void BupInitCallback(void);

// 100% matching!
void BupInit(void)
{
	memset(gBupInfo, 0, sizeof(gBupInfo));
    
	buInit(MAX_CAPS, USE_DRIVES, 0, BupInitCallback);
}

// 100% matching!
void BupExit(void)
{
	do 
    {
        
    } while (buExit() != BUD_ERR_OK);
}

// 100% matching! 
static void ClearInfo(Sint32 drive)
{
	BACKUPINFO* info;

	info = &gBupInfo[drive];
    
	info->ProgressCount = 0;
	info->ProgressMax = 0;
    
	info->Operation = 0;
    
	info->Ready = FALSE;
    
	info->IsFormat = FALSE;
    
	info->Work = NULL;
    
	memset(&info->DiskInfo, 0, sizeof(BUS_DISKINFO));
}

// 100% matching! 
static Sint32 BupComplete(Sint32 drive, Sint32 op, Sint32 stat, Uint32 param)
{
	BACKUPINFO* info;
	Sint32 ret;

	info = &gBupInfo[drive];

	switch (op) 
    {
    case BUD_OP_CONNECT:
        info->Connect = TRUE;
        
        info->WorkSize = BUM_WORK_SIZE(stat, 1);
        
        info->Capacity = stat;
        break;
    case BUD_OP_MOUNT:
        if (stat == BUD_ERR_OK) 
        {
            info->Ready = TRUE;
            
            ret = buGetDiskInfo(drive, &info->DiskInfo);
            
            if (ret == BUD_ERR_OK)
            {
                info->IsFormat = TRUE;
            }
            
            info->LastError = BUD_ERR_OK;
        }
        
        break;
    case BUD_OP_UNMOUNT:
        if ((info->Work != NULL) && (info->MemMode == 0)) 
        { 
            syFree(info->Work); 
        }
        
        ClearInfo(drive);
        
        info->Connect = FALSE;
        break;
    case BUD_OP_SAVEFILE:
        info->LastError = stat; 
        break;
    case BUD_OP_LOADFILE:
        info->LastError = stat; 
        break;
    default:
        info->LastError = stat;

        buGetDiskInfo(drive, &info->DiskInfo);
	}

	info->Operation = 0;

	return BUD_CBRET_OK;
}

// 100% matching! 
static Sint32 BupProgress(Sint32 drive, Sint32 op, Sint32 count, Sint32 max)
{
	BACKUPINFO* info;

	info = &gBupInfo[drive];

	info->ProgressCount = count;
	info->ProgressMax = max;
    
	info->Operation = op;

	return BUD_CBRET_OK; 
}

// 100% matching! 
static void BupInitCallback(void)
{ 
    buSetCompleteCallback(BupComplete); 
    buSetProgressCallback(BupProgress); 
} 
