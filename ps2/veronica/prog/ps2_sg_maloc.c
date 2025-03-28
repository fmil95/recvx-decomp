unsigned int __free_malloc_size;
_HM* Ps2_malloc_p;
unsigned char Ps2_malloc_mem[13422592];
unsigned int __max_malloc_size;

#define ALIGN(x, y) (((((int)x) + (y-1)) / y) * y)
#define GET_DATA_PTR(x) ((void*)(((unsigned int)x) + sizeof(struct _HM)))
#define GET_NEXT_WRK(x) ((int)search_work) + (int)search_work->Use_size + (int)sizeof(struct _HM)

void syFree(void* ap);
void* syMalloc(unsigned int nbytes);
Void syMallocFinish(Void);
Void syMallocInit(Void *heap, Uint32 size);
Void syMallocStat(Uint32 *wholeFreeSize, Uint32 *biggestFreeBlockSize);

// 100% matching! 
void syFree(void* ap)
{
    _HM* search_work;

    if (ap == NULL) 
    {
        return;
    }
    
    for (search_work = Ps2_malloc_p; search_work->pNext_work != NULL; search_work = search_work->pNext_work) 
    {
        if (ap == (search_work->pNext_work + 1)) 
        {
            search_work->Total_size += search_work->pNext_work->Total_size + sizeof(_HM);
            __free_malloc_size += search_work->pNext_work->Use_size + sizeof(_HM);
            
            search_work->pNext_work = search_work->pNext_work->pNext_work;
            return;
        }
    }
}

// 100% matching!
void* syMalloc(unsigned int nbytes) // this function might have actually been based on njMalloc
{
    _HM* search_work; 
    
    nbytes = ALIGN(nbytes, sizeof(_HM)); 

    search_work = Ps2_malloc_p; 

    while (search_work->pNext_work != NULL) 
    { 
        if ((search_work->Total_size - search_work->Use_size) >= (nbytes + sizeof(_HM))) 
        { 
            goto label;
        } 
        else
        {
            search_work = search_work->pNext_work;
        }
    } 
    
    if ((search_work->Total_size - search_work->Use_size) < (nbytes + sizeof(_HM))) 
    { 
        return NULL; 
    }

    label:
    if (search_work->pNext_work == NULL) 
    { 
        search_work->pNext_work = (_HM*)ALIGN(GET_NEXT_WRK(search_work), 4);
        
        search_work->pNext_work->pNext_work = NULL; 
    } 
    else 
    { 
        _HM* temp; // not from the debugging symbols

        temp = search_work->pNext_work;
        
        search_work->pNext_work = (_HM*)ALIGN(GET_NEXT_WRK(search_work), 4); 
        
        search_work->pNext_work->pNext_work = temp; 
    }
    
    search_work->pNext_work->Total_size = search_work->Total_size - (search_work->Use_size + sizeof(_HM));
    search_work->pNext_work->Use_size = nbytes; 
    
    search_work->Total_size = search_work->Use_size; 
    
    __free_malloc_size -= nbytes + sizeof(_HM);
    
    return GET_DATA_PTR(search_work->pNext_work); 
} 

// 100% matching!
Void syMallocFinish(Void)
{

}

// 100% matching!
Void syMallocInit(Void *heap, Uint32 size)
{
    Ps2_malloc_p = (_HM*)&Ps2_malloc_mem;
    
    Ps2_malloc_p->Use_size = 0;
    Ps2_malloc_p->Total_size = 13422528;
    
    Ps2_malloc_p->pNext_work = NULL;
    
    __free_malloc_size = 13422528;
}

// 100% matching!
Void syMallocStat(Uint32 *wholeFreeSize, Uint32 *biggestFreeBlockSize)
{
    _HM* search_work;

    __max_malloc_size = 0;
    
    for (search_work = Ps2_malloc_p; search_work != NULL; search_work = search_work->pNext_work) 
    {
        if (__max_malloc_size < (search_work->Total_size - search_work->Use_size)) 
        {
            __max_malloc_size = search_work->Total_size - search_work->Use_size;
        }
    }
    
    *wholeFreeSize = __free_malloc_size;
    *biggestFreeBlockSize = __max_malloc_size;
}
