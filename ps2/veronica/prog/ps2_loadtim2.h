

// 100% matching!
void *UncAddr(void *val)
{
    return (void*)(((u_int)val & UNCMASK)|UNCBASE);
}
