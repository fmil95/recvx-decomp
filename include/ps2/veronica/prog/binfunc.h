#ifndef _BINFUNC_H_
#define _BINFUNC_H_

#include "types.h"

int bhMlbBinRealize(void* bin_datP, ML_WORK* mlwP);
int bhBscBinRealize(NJS_MODEL* mdlP, unsigned int dat_off);
int bhCnkBinRealize(NJS_CNK_MODEL* mdlP, unsigned int dat_off);
int bhMnbBinRealize(void* bin_datP, MN_WORK* mnwP);

#endif
