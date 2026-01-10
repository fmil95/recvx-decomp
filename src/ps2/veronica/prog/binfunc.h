#ifndef _BINFUNC_H_
#define _BINFUNC_H_

typedef struct NJS_MDATA2_MOD
{
    // total size: 0x8
    void* p[2]; // offset 0x0, size 0x8
} NJS_MDATA2_MOD; 

int bhMlbBinRealize(void* bin_datP, ML_WORK* mlwP);
int bhBscBinRealize(NJS_MODEL* mdlP, unsigned int dat_off);
int bhCnkBinRealize(NJS_CNK_MODEL* mdlP, unsigned int dat_off);
int bhMnbBinRealize(void* bin_datP, MN_WORK* mnwP);

#endif
