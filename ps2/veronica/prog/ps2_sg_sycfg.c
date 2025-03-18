int SoundMode;

Sint32 syCfgExit( Void  ) ;
Sint32 syCfgGetSoundMode( Sint32* pnMode ) ;
Sint32 syCfgInit( Void* ) ;
Sint32 syCfgSetSoundMode( Sint32 nMode ) ;

// 100% matching! 
Sint32 syCfgExit( Void  )
{

}

// 100% matching! 
Sint32 syCfgGetSoundMode( Sint32* pnMode )
{ 
    *pnMode = SoundMode; 
    
    return 0;
}

// 100% matching! 
Sint32 syCfgInit( Void* )
{

}

// 100% matching! 
Sint32 syCfgSetSoundMode( Sint32 nMode )
{ 
    SoundMode = nMode; 
}
