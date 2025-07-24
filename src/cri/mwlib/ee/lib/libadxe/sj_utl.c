

// 100% matching!
void SJ_SplitChunk(SJCK *ck, Sint32 nbyte, SJCK *ck1, SJCK *ck2)
{
    *ck1 = *ck;
    
    ck2->len = ck1->len;

    if (nbyte < ck1->len) 
    {
        ck1->len = nbyte;
    }

    ck2->len -= ck1->len;

    if (ck2->len == 0)
    {
        ck2->data = NULL;
    } 
    else
    {
        ck2->data = ck1->data + ck1->len;
    } 
}
