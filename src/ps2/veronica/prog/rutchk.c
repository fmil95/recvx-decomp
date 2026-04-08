#include "../../../ps2/veronica/prog/rutchk.h"
#include "../../../ps2/veronica/prog/main.h"

// 100% matching! 
unsigned char bhCheckRoute(NJS_POINT3* ps0, NJS_POINT3* ps1, NJS_POINT3* ps2)
{
    ATR_WORK* rp;      
    unsigned char now; 
    unsigned char nxt; 
    unsigned char rid; 
    
    rid = bhCheckRouteID(ps0);
    
    if (rid == 0xFF) 
    {
        return 0xFF;
    }
    
    nxt = bhCheckRouteID(ps1);

    if (nxt == 0xFF) 
    {
        return 0xFF;
    }
    
    if (rid == nxt) 
    {
        ps2->x = ps1->x;
        ps2->y = ps1->y;
        ps2->z = ps1->z;
        
        return 0xFF;
    } 

    now = *((rom->ruttp + (rom->rut_n * nxt)) + rid);
        
    rp = &rom->rutp[now];
        
    ps2->x = rp->px + (0.5f * rp->w);
    ps2->y = rp->py + (0.5f * rp->h);
    ps2->z = rp->pz + (0.5f * rp->d);
    
    return now;
}

// 100% matching!
unsigned char bhCheckRouteID(NJS_POINT3* ps)
{
    ATR_WORK* rp;
    int i;

    rp = rom->rutp;
    
    for (i = 0; i < rom->rut_n; i++, rp++) 
    {
        if (((rp->px <= ps->x) && ((rp->px + rp->w) >= ps->x)) && ((rp->py <= ps->y) && ((rp->py + rp->h) >= ps->y)) && ((rp->pz <= ps->z) && ((rp->pz + rp->d) >= ps->z)))
        {
            return i;
        }
    }

    return 0xFF;
}
