#ifndef _ADX_TLK2_H_
#define _ADX_TLK2_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxt.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>
#include "macros.h"

void ADXT_StartAfs(ADXT adxt, Sint32 patid, Sint32 fid);
void ADXT_StartFname(ADXT adxt, Char8 *fname);
void ADXT_StartMem(ADXT adxt, void *adxdat);
void ADXT_StartMem2(ADXT adxt, void *adxdat, Sint32 datlen);
void ADXT_StartMemIdx(ADXT adxt, void *acx, Sint32 no);

#endif
