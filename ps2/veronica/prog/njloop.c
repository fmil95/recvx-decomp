

// 100% matching!
void main() 
{
    njUserInit(); 
    
    while (TRUE) 
    { 
        if (njUserMain() < 0) 
        { 
            break;
        } 
        
        njWaitVSync();
    } 
    
    njUserExit(); 
} 
