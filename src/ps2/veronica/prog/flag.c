#include "flag.h"

// 100% matching! 
void bhStFlg(unsigned int* flg, unsigned int bit)
{
    flg[bit / 32] |= 0x80000000 >> (bit & 31); 
} 

// 100% matching! 
void bhCrFlg(unsigned int* flg, unsigned int bit)
{
    flg[bit / 32] &= ~(0x80000000 >> (bit & 31));
}

// 100% matching! 
int bhCkFlg(unsigned int* flg, unsigned int bit)
{
    return flg[bit / 32] & (0x80000000 >> (bit & 31)); 
} 
