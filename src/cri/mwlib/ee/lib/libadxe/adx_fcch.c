void ADXF_Ocbi(Sint8* buf, Sint64 bsize);

// 100% matching!
void ADXF_Ocbi(Sint8* buf, Sint64 bsize)
{
    InvalidDCache(buf, (buf + bsize) - 1);
}
