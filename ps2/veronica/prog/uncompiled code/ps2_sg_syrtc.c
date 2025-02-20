typedef struct _anon0;
typedef struct _SYS_RTC_DATE;



struct _anon0
{
	unsigned char stat;
	unsigned char second;
	unsigned char minute;
	unsigned char hour;
	unsigned char pad;
	unsigned char day;
	unsigned char month;
	unsigned char year;
};

struct _SYS_RTC_DATE
{
	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	unsigned char dayofweek;
	unsigned char ageofmoon;
};


void syRtcFinish();
int syRtcGetDate(_SYS_RTC_DATE* date);
int syRtcInit();

// 
// Start address: 0x2ddf80
void syRtcFinish()
{
	// Line 38, Address: 0x2ddf80, Func Offset: 0
	// Func End, Address: 0x2ddf88, Func Offset: 0x8
}

// 
// Start address: 0x2ddf90
int syRtcGetDate(_SYS_RTC_DATE* date)
{
	_anon0 get_rtc;
	// Line 61, Address: 0x2ddf90, Func Offset: 0
	// Line 65, Address: 0x2ddfa0, Func Offset: 0x10
	// Line 68, Address: 0x2ddfa8, Func Offset: 0x18
	// Line 69, Address: 0x2ddfdc, Func Offset: 0x4c
	// Line 70, Address: 0x2de00c, Func Offset: 0x7c
	// Line 71, Address: 0x2de03c, Func Offset: 0xac
	// Line 72, Address: 0x2de06c, Func Offset: 0xdc
	// Line 73, Address: 0x2de09c, Func Offset: 0x10c
	// Line 76, Address: 0x2de0cc, Func Offset: 0x13c
	// Line 77, Address: 0x2de0d0, Func Offset: 0x140
	// Line 79, Address: 0x2de0d4, Func Offset: 0x144
	// Line 80, Address: 0x2de0d8, Func Offset: 0x148
	// Func End, Address: 0x2de0e8, Func Offset: 0x158
}

// 
// Start address: 0x2de0f0
int syRtcInit()
{
	// Line 104, Address: 0x2de0f0, Func Offset: 0
	// Func End, Address: 0x2de0f8, Func Offset: 0x8
}

