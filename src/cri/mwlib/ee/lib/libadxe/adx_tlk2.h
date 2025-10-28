#ifndef _ADX_TLK2_H_
#define _ADX_TLK2_H_

#define BSWAP_S32(_val) (Sint32)(((Uint32)_val >> 24) | (_val << 24) | (((_val << 8) & 0xFF0000) | ((_val >> 8) & 0xFF00))) // TODO: move this macro somewhere else

void ADXT_StartAfs(ADXT adxt, Sint32 patid, Sint32 fid);
void ADXT_StartFname(ADXT adxt, Char8 *fname);
void ADXT_StartMem(ADXT adxt, void *adxdat);
void ADXT_StartMem2(ADXT adxt, void *adxdat, Sint32 datlen);
void ADXT_StartMemIdx(ADXT adxt, void *acx, Sint32 no);

#endif
