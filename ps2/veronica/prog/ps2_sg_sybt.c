Void   syBtExit     ( Void );
Sint32 syBtGetBootSystemID   ( SYS_BT_SYSTEMID* pData ) ;

// 100% matching!
Void   syBtExit     ( Void )
{

}

// 100% matching!
Sint32 syBtGetBootSystemID   ( SYS_BT_SYSTEMID* pData ) 
{ 
    int i;
    
    if (pData == NULL) 
    {
        return 0;
    }
    
    pData->nNo = 1;
    pData->nAll = 2; 
    
    for (i = 0; i < 16; i++)
    { 
        pData->szProduct[i] = 0; 
    } 
    
    return 1; 
} 
