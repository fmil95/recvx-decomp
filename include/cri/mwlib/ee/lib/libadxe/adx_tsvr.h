#ifndef _ADX_TSVR_H_
#define _ADX_TSVR_H_

#include <../../../recvx-decomp-cri/cri/mwlib/ee/include/cri_xpt.h>
#include <../../../recvx-decomp-cri/cri/mwlib/include/sj.h>
#include "override_adxt.h"
#include <../../../recvx-decomp-cri/cri/mwlib/include/cri_adxt.h>

void adxt_eos_entry(void *obj);
void ADXT_ExecErrChk(ADXT adxt);
void ADXT_ExecErrChkPS2(ADXT adxt);
void ADXT_ExecHndl(ADXT adxt);
void adxt_nlp_trap_entry(void *obj);
void adxt_RcvrReplay(ADXT adxt);
void adxt_set_outpan(ADXT adxt);
void adxt_stat_decend(ADXT adxt);
void adxt_stat_decinfo(ADXT adxt);
void adxt_stat_playend(ADXT adxt);
void adxt_stat_playing(ADXT adxt);
void adxt_stat_prep(ADXT adxt);
void adxt_trap_entry(void *obj);

#endif
