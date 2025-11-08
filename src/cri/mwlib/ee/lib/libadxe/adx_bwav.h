#ifndef _ADX_BWAV_H_
#define _ADX_BWAV_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxt.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>
#include "macros.h"

typedef struct tWAVEFORMATEX 
{
	Uint16 wFormatTag;
	Uint16 nChannels;
	Uint32 nSamplesPerSec;
	Uint32 nAvgBytesPerSec;
	Uint16 nBlockAlign;
	Uint16 wBitsPerSample;
	Uint16 cbSize;
} WAVEFORMATEX;

Sint32 ADX_DecodeInfoWav(Sint8 *ibuf, Sint32 ibuflen, Sint16 *dlen, Sint8 *code, Sint8 *bps, Sint8 *blksize, Sint8 *nch, Sint32 *sfreq, Sint32 *total_nsmpl, Sint32 *nsmpl_blk, Sint16 *cdc);
Sint32 ADXB_CheckWav(Sint8 *ibuf);
Sint32 ADXB_DecodeHeaderWav(ADXB adxb, Sint8 *ibuf, Sint32 ibuflen);
void ADXB_ExecOneWav(ADXB adxb);
void ADXB_ExecOneWav4(ADXB adxb);
void ADXB_ExecOneWav8(ADXB adxb);
void ADXB_ExecOneWav16(ADXB adxb);

#endif
