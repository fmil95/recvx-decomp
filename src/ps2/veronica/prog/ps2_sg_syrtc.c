#include "ps2_sg_syrtc.h"

// 100% matching! 
void syRtcFinish( void )
{

}

// 100% matching!
Sint32 syRtcGetDate( SYS_RTC_DATE *date )
{ 
    sceCdCLOCK get_rtc;
    
    sceCdReadClock(&get_rtc); 
    
    date->year = (get_rtc.year % 16) + ((get_rtc.year / 16) * 10) + 2000; 
    date->month = (get_rtc.month % 16) + ((get_rtc.month / 16) * 10); 
    date->day = (get_rtc.day % 16) + ((get_rtc.day / 16) * 10); 
    
    date->hour = (get_rtc.hour % 16) + ((get_rtc.hour / 16) * 10); 
    date->minute = (get_rtc.minute % 16) + ((get_rtc.minute / 16) * 10);
    date->second = (get_rtc.second % 16) + ((get_rtc.second / 16) * 10); 
    
    date->dayofweek = 0; 
    date->ageofmoon = 0; 
    
    return get_rtc.stat; 
} 

// 100% matching!
Sint32 syRtcInit( void )
{ 
    return 0;
}
