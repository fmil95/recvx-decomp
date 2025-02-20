typedef enum SDE_DATA_TYPE;



enum SDE_DATA_TYPE
{
	SDE_DATA_TYPE_SND_DRV = 0x56524453,
	SDE_DATA_TYPE_MULTI_UNIT = 0x544c4d53,
	SDE_DATA_TYPE_MIDI_DRM_BANK = 0x42444d53,
	SDE_DATA_TYPE_MIDI_SEQ_BANK = 0x42534d53,
	SDE_DATA_TYPE_MIDI_PRG_BANK = 0x42504d53,
	SDE_DATA_TYPE_SHOT_BANK = 0x42534f53,
	SDE_DATA_TYPE_PSTM_RING_BUF = 0x52535053,
	SDE_DATA_TYPE_FX_OUT_BANK = 0x424f4653,
	SDE_DATA_TYPE_FX_PRG_BANK = 0x42504653,
	SDE_DATA_TYPE_FX_PRG_WRK = 0x57504653
};

int GdDaPlayFlag;
unsigned int SddFirstFlag;
char SdcGdDaVolume;

void InitSdcParameter();
int InitSoundDriver(char* SddFileName, char* MufFileName);

// 
// Start address: 0x290810
void InitSdcParameter()
{
	// Line 23, Address: 0x290810, Func Offset: 0
	// Line 24, Address: 0x290818, Func Offset: 0x8
	// Line 26, Address: 0x290828, Func Offset: 0x18
	// Line 27, Address: 0x290830, Func Offset: 0x20
	// Line 28, Address: 0x290838, Func Offset: 0x28
	// Line 29, Address: 0x290840, Func Offset: 0x30
	// Line 31, Address: 0x290848, Func Offset: 0x38
	// Line 32, Address: 0x290850, Func Offset: 0x40
	// Line 34, Address: 0x290858, Func Offset: 0x48
	// Line 35, Address: 0x290864, Func Offset: 0x54
	// Func End, Address: 0x290870, Func Offset: 0x60
}

// 
// Start address: 0x290870
int InitSoundDriver(char* SddFileName, char* MufFileName)
{
	int FileSize;
	unsigned int* Address;
	// Line 49, Address: 0x290870, Func Offset: 0
	// Line 53, Address: 0x29088c, Func Offset: 0x1c
	// Line 54, Address: 0x290898, Func Offset: 0x28
	// Line 55, Address: 0x2908a0, Func Offset: 0x30
	// Line 56, Address: 0x2908a8, Func Offset: 0x38
	// Line 57, Address: 0x2908bc, Func Offset: 0x4c
	// Line 59, Address: 0x2908c4, Func Offset: 0x54
	// Line 60, Address: 0x2908d0, Func Offset: 0x60
	// Line 62, Address: 0x2908d8, Func Offset: 0x68
	// Line 63, Address: 0x2908e0, Func Offset: 0x70
	// Line 64, Address: 0x2908ec, Func Offset: 0x7c
	// Line 65, Address: 0x2908f4, Func Offset: 0x84
	// Line 66, Address: 0x2908fc, Func Offset: 0x8c
	// Line 67, Address: 0x290910, Func Offset: 0xa0
	// Line 69, Address: 0x290918, Func Offset: 0xa8
	// Line 70, Address: 0x290924, Func Offset: 0xb4
	// Line 73, Address: 0x29092c, Func Offset: 0xbc
	// Line 76, Address: 0x290934, Func Offset: 0xc4
	// Line 75, Address: 0x290948, Func Offset: 0xd8
	// Line 76, Address: 0x29094c, Func Offset: 0xdc
	// Func End, Address: 0x290954, Func Offset: 0xe4
}

