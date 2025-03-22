



/*void bhStFlg(unsigned int* flg, unsigned int bit);
void bhCrFlg(unsigned int* flg, unsigned int bit);
int bhCkFlg(unsigned int* flg, unsigned int bit);

// 
// Start address: 0x280e40
void bhStFlg(unsigned int* flg, unsigned int bit)
{
	// Line 37, Address: 0x280e40, Func Offset: 0
	// Line 38, Address: 0x280e60, Func Offset: 0x20
	// Func End, Address: 0x280e68, Func Offset: 0x28
}*/

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
