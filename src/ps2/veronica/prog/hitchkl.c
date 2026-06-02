#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"

static NJS_PLANE PLANE;

// 100% matching!
ATR_WORK* bhCollisionCheckLine(NJS_VECTOR* p1, NJS_VECTOR* p2)
{
    ATR_WORK* hp; 
    ATR_WORK* ret; 
    int i;
    int wal_n; 
    NJS_VECTOR vec; 

    ret = NULL;
    
    vec.x = p2->x - p1->x;
    vec.y = p2->y - p1->y;
    vec.z = p2->z - p1->z;
    
    wal_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < wal_n; i++)
    {
        if (i < rom->wal_n)
        {
            hp = &rom->walp[i];
        }
        else 
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        if (((hp->flg & 0x1)) && (bhCollisionCheckLineMain(hp, &vec, p1, p2) != 0))
        {
            ret = hp;
        }
    }
    
    return ret; 
}

// 100% matching!
ATR_WORK* bhCollisionCheckLine2(NJS_POINT3* p1, NJS_POINT3* p2, unsigned int flg, char flr_no)
{
	ATR_WORK* hp; 
    ATR_WORK* ret; 
    int i;
    int wal_n; 
    NJS_VECTOR vec; 

    ret = NULL;
    
    vec.x = p2->x - p1->x;
    vec.y = p2->y - p1->y;
    vec.z = p2->z - p1->z;
    
    wal_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < wal_n; i++)
    {
        if (i < rom->wal_n)
        {
            hp = &rom->walp[i];
        }
        else 
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        if (((hp->flg & 0x1)) && ((hp->type == 7) || ((!(hp->type & 0x1)) || (!(flg & 0x400))) && ((!(hp->attr & 0x1)) || (hp->flr_no == flr_no)) && ((!(hp->attr & 0x2)) || (!(flg & 0x4000)))) && (bhCollisionCheckLineMain(hp, &vec, p1, p2) != 0))
        {
            ret = hp;
        }
    }
    
    return ret;
}

// 100% matching!
ATR_WORK* bhCollisionCheckLine3(NJS_POINT3* p1, NJS_POINT3* p2, unsigned int flg, char flr_no)
{
    ATR_WORK* hp; 
    ATR_WORK* ret; 
    int i;
    int wal_n; 
    NJS_VECTOR vec; 

    ret = NULL;
    
    vec.x = p2->x - p1->x;
    vec.y = p2->y - p1->y;
    vec.z = p2->z - p1->z;
    
    wal_n = rom->wal_n + sys->mwal_n;
    
    for (i = 0; i < wal_n; i++)
    {
        if (i < rom->wal_n)
        {
            hp = &rom->walp[i];
        }
        else 
        {
            hp = &sys->mwalp[i - rom->wal_n];
        }
        
        if (((hp->flg & 0x1)) && ((hp->type == 7) || ((!(hp->type & 0x1)) || (!(flg & 0x400))) && ((!(hp->attr & 0x1)) || (hp->flr_no == flr_no)) && ((!(hp->attr & 0x2)) || (!(flg & 0x4000))) && (!(hp->attr & 0x4))) && (bhCollisionCheckLineMain(hp, &vec, p1, p2) != 0))
        {
            ret = hp;
        }
    }
    
    return ret;
}

// 99.97% matching (matches on NGC)
int bhCollisionCheckLineMain(ATR_WORK* hp, NJS_VECTOR* vec, NJS_POINT3* p1, NJS_POINT3* p2)
{
	int ret;
    int j;
    NJS_POINT3 area[8];  
    NJS_POINT3 pos; 
    float h; // not from DWARF

    ret = 0;

    h = hp->h ? hp->h : rom->h;
    
    switch (hp->type)
    {
    case 0:
    case 1:
        if ((((hp->px > p1->x) && (hp->px > p2->x)) || ((hp->pz > p1->z) && (hp->pz > p2->z))) || (((hp->px + hp->w) < p1->x) && ((hp->px + hp->w) < p2->x)) || (((hp->pz + hp->d) < p1->z) && ((hp->pz + hp->d) < p2->z))) 
        {
            break;
        }
        
        if ((vec->y < 0) && ((p1->y >= (hp->py + h)) && (p2->y < (hp->py + h)))) 
        {
            pos.x = hp->px;
            pos.y = hp->py + h;
            pos.z = hp->pz;
            
            if (bhCollisionCheckL2XZPL(p1, p2, &pos, hp->w, hp->d, 0) != 0)
            {
                ret = 1;
                
                p2->y = hp->py + h;
            }
        }
        
        if ((vec->z > 0) && ((p1->z <= hp->pz) && (p2->z > hp->pz))) 
        {
            pos.x = hp->px;
            pos.y = hp->py;
            pos.z = hp->pz;
            
            if (bhCollisionCheckL2XYPL(p1, p2, &pos, hp->w, h, 1) != 0)
            {
                ret = 1;
                
                p2->z = hp->pz;
            }
        }
        
        if ((vec->x > 0) && ((p1->x <= hp->px) && (p2->x > hp->px)))
        {
            pos.x = hp->px;
            pos.y = hp->py;
            pos.z = hp->pz;
            
            if (bhCollisionCheckL2YZPL(p1, p2, &pos, h, hp->d, 1) != 0)
            {
                ret = 1;
                
                p2->x = hp->px;
            }
        }
        
        if ((vec->z < 0) && ((p1->z >= (hp->pz + hp->d)) && (p2->z < (hp->pz + hp->d)))) 
        {
            pos.x = hp->px;
            pos.y = hp->py;
            pos.z = hp->pz + hp->d;
            
            if (bhCollisionCheckL2XYPL(p1, p2, &pos, hp->w, h, 0) != 0)
            {
                ret = 1;
                
                p2->z = hp->pz + hp->d;
            }
        }
        
        if ((vec->x < 0) && ((p1->x >= (hp->px + hp->w)) && (p2->x < (hp->px + hp->w))))
        {
            pos.x = hp->px + hp->w;
            pos.y = hp->py;
            pos.z = hp->pz;
            
            if (bhCollisionCheckL2YZPL(p1, p2, &pos, h, hp->d, 0) != 0) 
            {
                ret = 1;
                
                p2->x = hp->px + hp->w;
            }
        }
        
        if ((vec->y > 0) && ((p1->y <= hp->py) && (p2->y > hp->py)))
        {
            pos.x = hp->px;
            pos.y = hp->py;
            pos.z = hp->pz;
            
            if (bhCollisionCheckL2XZPL(p1, p2, &pos, hp->w, hp->d, 1) != 0) 
            {
                ret = 1;
                
                p2->y = hp->py;
            }
        }
        
        break;
    case 7:
        if ((((hp->px <= p1->x) || (hp->px <= p2->x)) && ((hp->pz <= p1->z) || (hp->pz <= p2->z))) && (((hp->px + hp->w) >= p1->x) || ((hp->px + hp->w) >= p2->x)) && (((hp->pz + hp->d) >= p1->z) || ((hp->pz + hp->d) >= p2->z)))
        {
            if ((vec->y > 0) && ((p1->y <= (hp->py + hp->h)) && (p2->y > (hp->py + hp->h)))) 
            {
                pos.x = hp->px;
                pos.y = hp->py + hp->h;
                pos.z = hp->pz;
                
                if (bhCollisionCheckL2XZPL(p1, p2, &pos, hp->w, hp->d, 1) != 0) 
                {
                    ret = 1;
                    
                    p2->y = hp->py + hp->h;
                }
            }
            
            if ((vec->y < 0) && ((p1->y >= hp->py) && (p2->y < hp->py)))
            {
                pos.x = hp->px;
                pos.y = hp->py;
                pos.z = hp->pz;
                
                if (bhCollisionCheckL2XZPL(p1, p2, &pos, hp->w, hp->d, 0) != 0)
                {
                    ret = 1;
                    
                    p2->y = hp->py;
                }
            }
            
            if ((vec->z > 0) && ((p1->z <= hp->pz) && (p2->z > hp->pz) && (hp->h)))
            {
                pos.x = hp->px;
                pos.y = hp->py + hp->h;
                pos.z = hp->pz;
                
                if (bhCollisionCheckL2XYPL(p1, p2, &pos, hp->w, -hp->h, 1) != 0) 
                {
                    ret = 1;
                    
                    p2->z = hp->pz;
                }
            }
            
            if ((vec->x > 0) && ((p1->x <= hp->px) && (p2->x > hp->px) && (hp->h))) 
            {
                pos.x = hp->px;
                pos.y = hp->py + hp->h;
                pos.z = hp->pz;
                
                if (bhCollisionCheckL2YZPL(p1, p2, &pos, -hp->h, hp->d, 1) != 0)
                {
                    ret = 1;
                    
                    p2->x = hp->px;
                }
            }
            
            if ((vec->z < 0) && ((p1->z >= (hp->pz + hp->d)) && (p2->z < (hp->pz + hp->d)) && (hp->h)))
            {
                pos.x = hp->px;
                pos.y = hp->py + hp->h;
                pos.z = hp->pz + hp->d;
                
                if (bhCollisionCheckL2XYPL(p1, p2, &pos, hp->w, -hp->h, 0) != 0) 
                {
                    ret = 1;
                    
                    p2->z = hp->pz + hp->d;
                }
            }
            
            if ((vec->x < 0) && ((p1->x <= (hp->px + hp->w)) && (p2->x > (hp->px + hp->w)) && (hp->h)))
            {
                pos.x = hp->px + hp->w;
                pos.y = hp->py + hp->h;
                pos.z = hp->pz;
                
                if (bhCollisionCheckL2YZPL(p1, p2, &pos, -hp->h, hp->d, 0) != 0)
                {
                    ret = 1;
                    
                    p2->x = hp->px + hp->w;
                }
            }
        }
        
        break;
    case 2:
    case 3:
        if (((((hp->px - hp->w) <= p1->x) || ((hp->px - hp->w) <= p2->x)) && (((hp->pz - hp->w) <= p1->z) || ((hp->pz - hp->w) <= p2->z))) && ((((hp->px + hp->w) >= p1->x) || ((hp->px + hp->w) >= p2->x)) && (((hp->pz + hp->w) >= p1->z) || ((hp->pz + hp->w) >= p2->z))))
        {
            area[0].x = hp->px + hp->w;
            area[0].y = hp->py;
            area[0].z = hp->pz;
            
            area[1].x = hp->px + hp->w;
            area[1].y = hp->py + h;
            area[1].z = hp->pz;
            
            area[2].y = hp->py + h;
            area[3].y = hp->py;

            for (j = 1; j <= 8; j++)
            {
                area[2].x = area[1].x;
                area[2].z = area[1].z;
                
                area[3].x = area[0].x;
                area[3].z = area[0].z;
                
                area[0].x = area[1].x = hp->px + (hp->w * njCos(182.04445f * ((360 * j) / 8)));
                area[0].z = area[1].z = hp->pz - (hp->w * njSin(182.04445f * ((360 * j) / 8)));
                
                if (bhCollisionCheckL2PL(p1, p2, area, 4) != 0)
                {
                    ret = 1;
                }
            }
            
            if (vec->y < 0) 
            {
                for (j = 0; j < 8; j++)
                {
                    area[j].x = hp->px + (hp->w * njCos(182.04445f * ((360 * j) / 8)));
                    area[j].y = hp->py + h;
                    area[j].z = hp->pz - (hp->w * njSin(182.04445f * ((360 * j) / 8)));
                    
                    if (bhCollisionCheckL2PL(p1, p2, area, 8) != 0) 
                    {
                        ret = 1;
                        
                        p2->y = area[0].y;
                    }
                } 
            }
        }
        
        break;
    case 4: 
    case 5: 
        if ((hp->id == 0) || (hp->id == 1))
        {
            if ((hp->px > p1->x) && (hp->px > p2->x)) 
            {
                break;
            }
            else if (((hp->px + hp->w) < p1->x) && ((hp->px + hp->w) < p2->x))
            {
                break;
            }
        }
        else if ((((hp->px + hp->w) > p1->x) && ((hp->px + hp->w) > p2->x)) || ((hp->px < p1->x) && (hp->px < p2->x))) 
        { 
            break;
        }

        if ((hp->id == 0) || (hp->id == 2))
        {
            if ((hp->pz > p1->z) && (hp->pz > p2->z)) 
            {
                break;
            }
            else if (((hp->pz + hp->d) < p1->z) && ((hp->pz + hp->d) < p2->z))
            {
                break;
            }
        }
        else if ((((hp->pz + hp->d) > p1->z) && ((hp->pz + hp->d) > p2->z)) || ((hp->pz < p1->z) && (hp->pz < p2->z)))
        {
            break;
        }

        if ((hp->id == 0) || (hp->id == 3)) 
        {
            if (vec->y < 0)
            {
                area[0].x = hp->px;
                area[0].y = hp->py + h;
                area[0].z = hp->pz;

                area[1].x = hp->px;
                area[1].y = hp->py + h;
                area[1].z = hp->pz + hp->d;

                area[2].x = hp->px + hp->w;
                area[2].y = hp->py + h;
                area[2].z = hp->pz;
                
                if (bhCollisionCheckL2PL(p1, p2, area, 3) != 0)
                {
                    ret = 1;
                    
                    p2->y = area[0].y;
                }
            }
            
            area[0].x = hp->px;
            area[0].y = hp->py;
            area[0].z = hp->pz;
            
            area[1].x = hp->px;
            area[1].y = hp->py;
            area[1].z = hp->pz + hp->d;
            
            area[2].x = hp->px;
            area[2].y = hp->py + h;
            area[2].z = hp->pz + hp->d;
            
            area[3].x = hp->px;
            area[3].y = hp->py + h;
            area[3].z = hp->pz;
            
            if (bhCollisionCheckL2PL(p1, p2, area, 4) != 0)
            {
                ret = 1;
                
                p2->x = area[0].x;
            }
            
            area[0].x = hp->px;
            area[0].y = hp->py;
            area[0].z = hp->pz;
            
            area[1].x = hp->px;
            area[1].y = hp->py + h;
            area[1].z = hp->pz;
            
            area[2].x = hp->px + hp->w;
            area[2].y = hp->py + h;
            area[2].z = hp->pz;
            
            area[3].x = hp->px + hp->w;
            area[3].y = hp->py;
            area[3].z = hp->pz;
            
            if (bhCollisionCheckL2PL(p1, p2, area, 4) != 0)
            {
                ret = 1;
                
                p2->z = area[0].z;
            }
            
            area[0].x = hp->px + hp->w;
            area[0].y = hp->py;
            area[0].z = hp->pz;
            
            area[1].x = hp->px + hp->w;
            area[1].y = hp->py + h;
            area[1].z = hp->pz;
            
            area[2].x = hp->px;
            area[2].y = hp->py + h;
            area[2].z = hp->pz + hp->d;
            
            area[3].x = hp->px;
            area[3].y = hp->py;
            area[3].z = hp->pz + hp->d;
            
            if (bhCollisionCheckL2PL(p1, p2, area, 4) != 0) 
            {
                ret = 1;
            }
        } 
        else 
        {
            if (vec->y < 0) 
            {
                area[0].x = hp->px;
                area[0].y = hp->py + h;
                area[0].z = hp->pz;
                
                area[2].x = hp->px;
                area[2].y = hp->py + h;
                area[2].z = hp->pz + hp->d;
                
                area[1].x = hp->px + hp->w;
                area[1].y = hp->py + h;
                area[1].z = hp->pz;
                
                if (bhCollisionCheckL2PL(p1, p2, area, 3) != 0) 
                {
                    ret = 1;
                    
                    p2->y = area[0].y;
                }
            }
            
            area[0].x = hp->px;
            area[0].y = hp->py;
            area[0].z = hp->pz;
            
            area[3].x = hp->px;
            area[3].y = hp->py;
            area[3].z = hp->pz + hp->d;
            
            area[2].x = hp->px;
            area[2].y = hp->py + h;
            area[2].z = hp->pz + hp->d;
            
            area[1].x = hp->px;
            area[1].y = hp->py + h;
            area[1].z = hp->pz;
            
            if (bhCollisionCheckL2PL(p1, p2, area, 4) != 0) 
            {
                ret = 1;
                
                p2->x = area[0].x;
            }
            
            area[0].x = hp->px;
            area[0].y = hp->py;
            area[0].z = hp->pz;
            
            area[3].x = hp->px;
            area[3].y = hp->py + h;
            area[3].z = hp->pz;
            
            area[2].x = hp->px + hp->w;
            area[2].y = hp->py + h;
            area[2].z = hp->pz;
            
            area[1].x = hp->px + hp->w;
            area[1].y = hp->py;
            area[1].z = hp->pz;
            
            if (bhCollisionCheckL2PL(p1, p2, area, 4) != 0) 
            {
                ret = 1;
                
                p2->z = area[0].z;
            }
            
            area[0].x = hp->px + hp->w;
            area[0].y = hp->py;
            area[0].z = hp->pz;
            
            area[3].x = hp->px+ hp->w;
            area[3].y = hp->py + h;
            area[3].z = hp->pz;
            
            area[2].x = hp->px;
            area[2].y = hp->py + h;
            area[2].z = hp->pz + hp->d;
            
            area[1].x = hp->px;
            area[1].y = hp->py;
            area[1].z = hp->pz + hp->d;
            
            if (bhCollisionCheckL2PL(p1, p2, area, 4) != 0) 
            {
                ret = 1;
            }
        }
        
        break;
    case 6:
        if ((((hp->px <= p1->x) || (hp->px <= p2->x)) && ((hp->pz <= p1->z) || (hp->pz <= p2->z))) && ((((hp->px + hp->w) >= p1->x) || ((hp->px + hp->w) >= p2->x)) && (((hp->pz + hp->d) >= p1->z) || ((hp->pz + hp->d) >= p2->z))))  
        {
            area[0].x = hp->px; 
            area[0].y = hp->py;
            area[0].z = hp->pz;
            
            area[1].x = hp->px;
            area[1].y = hp->py;
            area[1].z = hp->pz + hp->d;
            
            area[2].x = hp->px + hp->w;
            area[2].y = hp->py;
            area[2].z = hp->pz + hp->d;
            
            area[3].x = hp->px+ hp->w;
            area[3].y = hp->py;
            area[3].z = hp->pz;
            
            switch (hp->id)
            { 
            case 0:
                area[2].y = area[3].y = hp->py + h;
                break;
            case 1:
                area[0].y = area[3].y = hp->py + h;
                break;
            case 2:
                area[1].y = area[2].y = hp->py + h;
                break;
            case 3:
                area[0].y = area[1].y = hp->py + h;
                break;
            }
            
            if (bhCollisionCheckL2PL(p1, p2, area, 4) != 0)
            {
                ret = 1;
            }
        }
    }
    
    return ret;
}

// 100% matching!
int bhCollisionCheckL2PL(NJS_POINT3* p1, NJS_POINT3* p2, NJS_POINT3* area, int num)
{
	NJS_LINE pl; 
    NJS_LINE ln;   
    NJS_POINT3 cp;  
    NJS_POINT3 dv;   
    int ret;
    float len, wlen;    

    ret = 0;
    
    ln.px = p1->x;
    ln.py = p1->y;
    ln.pz = p1->z;
    
    ln.vx = p2->x - p1->x;
    ln.vy = p2->y - p1->y;
    ln.vz = p2->z - p1->z;
    
    wlen = njScalor((NJS_VECTOR*)&ln.vx);
    
    njGetPlaneNormal(area, (NJS_VECTOR*)&pl.vx);
    
    pl.px = area->x;
    pl.py = area->y;
    pl.pz = area->z;
    
    if ((njInnerProduct((NJS_VECTOR*)&ln.vx, (NJS_VECTOR*)&pl.vx) < 0) && (njDistanceL2PL((NJS_LINE*)&ln.px, (NJS_LINE*)&pl.px, &cp) == 0))
    {
        dv.x = cp.x - ln.px;
        dv.y = cp.y - ln.py;
        dv.z = cp.z - ln.pz;
        
        if ((njInnerProduct((NJS_VECTOR*)&ln.vx, &dv) >= 0) && (wlen > njDistanceP2P(&cp, p1)) && (bhInOutCheck(&cp, area, (NJS_POINT3*)&pl.vx, num) != 0)) 
        {
            ret = 1;
            
            p2->x = cp.x;
            p2->y = cp.y;
            p2->z = cp.z;
            
            PLANE = pl;
        }
    }
    
    return ret;
}

// 100% matching!
int bhInOutCheck(NJS_POINT3* p, NJS_POINT3* area, NJS_POINT3* normal, int num)
{
    int i;        
    NJS_POINT3* p1, *p2; 
    NJS_POINT3 n; 
    float v1x, v1y, v1z;      
    float v2x, v2y, v2z;   

    if (num < 3) 
    {
        return 0;
    }
    
    if (normal != NULL) 
    {
        n.x = normal->x;
        n.y = normal->y;
        n.z = normal->z;
    } 
    else 
    {
        njGetPlaneNormal(area, &n);
    }
    
    p1 = area;
    
    for (i = 0; i < num; i++)
    {
        p2 = p1++;
        
        if (i == (num - 1))
        {
            p1 = area;
        }
        
        v1x = p1->x - p2->x;
        v1y = p1->y - p2->y;
        v1z = p1->z - p2->z;
        
        v2x = p->x - p2->x;
        v2y = p->y - p2->y;
        v2z = p->z - p2->z;
        
        if (((n.z * ((v1x * v2y) - (v1y * v2x))) + ((n.x * ((v1y * v2z) - (v1z * v2y))) + (n.y * ((v1z * v2x) - (v1x * v2z))))) < 0)
        {
            return 0;
        }
    }
    
    return 1;
}

// 
// Start address: 0x26b200
int bhCollisionCheckL2MDL(NJS_POINT3* p1, NJS_POINT3* p2, NJS_CNK_MODEL* mdl, NJS_MATRIX mtx)
{
	//_anon37 ln;
	//_anon2 center;
	//_anon2 area[4];
	//_anon2* pd;
	short pnum;
	int j;
	int i;
	int ret;
	int* pVtx;
	short* pPol;
	// Line 849, Address: 0x26b200, Func Offset: 0
	// Line 857, Address: 0x26b234, Func Offset: 0x34
	// Line 858, Address: 0x26b248, Func Offset: 0x48
	// Line 864, Address: 0x26b24c, Func Offset: 0x4c
	// Line 858, Address: 0x26b258, Func Offset: 0x58
	// Line 859, Address: 0x26b25c, Func Offset: 0x5c
	// Line 860, Address: 0x26b264, Func Offset: 0x64
	// Line 861, Address: 0x26b26c, Func Offset: 0x6c
	// Line 862, Address: 0x26b27c, Func Offset: 0x7c
	// Line 863, Address: 0x26b28c, Func Offset: 0x8c
	// Line 864, Address: 0x26b298, Func Offset: 0x98
	// Line 866, Address: 0x26b2bc, Func Offset: 0xbc
	// Line 876, Address: 0x26b2c0, Func Offset: 0xc0
	// Line 867, Address: 0x26b2c8, Func Offset: 0xc8
	// Line 876, Address: 0x26b2cc, Func Offset: 0xcc
	// Line 877, Address: 0x26b2d0, Func Offset: 0xd0
	// Line 876, Address: 0x26b2d8, Func Offset: 0xd8
	// Line 872, Address: 0x26b2e4, Func Offset: 0xe4
	// Line 877, Address: 0x26b2e8, Func Offset: 0xe8
	// Line 876, Address: 0x26b2ec, Func Offset: 0xec
	// Line 872, Address: 0x26b2f0, Func Offset: 0xf0
	// Line 876, Address: 0x26b2f4, Func Offset: 0xf4
	// Line 873, Address: 0x26b2f8, Func Offset: 0xf8
	// Line 877, Address: 0x26b2fc, Func Offset: 0xfc
	// Line 880, Address: 0x26b310, Func Offset: 0x110
	// Line 882, Address: 0x26b318, Func Offset: 0x118
	// Line 883, Address: 0x26b320, Func Offset: 0x120
	// Line 885, Address: 0x26b360, Func Offset: 0x160
	// Line 886, Address: 0x26b37c, Func Offset: 0x17c
	// Line 911, Address: 0x26b380, Func Offset: 0x180
	// Line 913, Address: 0x26b394, Func Offset: 0x194
	// Line 914, Address: 0x26b398, Func Offset: 0x198
	// Func End, Address: 0x26b3c0, Func Offset: 0x1c0
	scePrintf("bhCollisionCheckL2MDL - UNIMPLEMENTED!\n");
}

// 100% matching!
int bhCollisionCheckL2XZPL(NJS_POINT3* p1, NJS_POINT3* p2, NJS_POINT3* pos, float w, float d, int flg)
{
	NJS_LINE pl;   
    NJS_LINE ln;   
    NJS_POINT3 cp;   
    int ret;

    ret = 0;

    ln.px = p1->x;
    ln.py = p1->y;
    ln.pz = p1->z;
    
    ln.vx = p2->x - p1->x;
    ln.vy = p2->y - p1->y;
    ln.vz = p2->z - p1->z;
    
    pl.vx = 0;
    pl.vy = flg ? -1.0f : 1.0f;
    pl.vz = 0;
    
    pl.px = pos->x;
    pl.py = pos->y;
    pl.pz = pos->z;
    
    if ((njDistanceL2PL(&ln, &pl, &cp) == 0) && (((cp.x >= pos->x) && (cp.x <= (pos->x + w))) && ((cp.z >= pos->z) && (cp.z <= (pos->z + d)))))
    {
        p2->x = cp.x;
        p2->y = cp.y;
        p2->z = cp.z;
        
        PLANE = pl;

        ret = 1;
    }
    
    return ret;
}

// 100% matching!
int bhCollisionCheckL2XYPL(NJS_POINT3* p1, NJS_POINT3* p2, NJS_POINT3* pos, float w, float h, int flg)
{
    NJS_LINE pl;   
    NJS_LINE ln;   
    NJS_POINT3 cp;   
    int ret;

    ret = 0;

    ln.px = p1->x;
    ln.py = p1->y;
    ln.pz = p1->z;
    
    ln.vx = p2->x - p1->x;
    ln.vy = p2->y - p1->y;
    ln.vz = p2->z - p1->z;
    
    pl.vx = 0;
    pl.vy = 0;
    pl.vz = flg ? -1.0f : 1.0f;
    
    pl.px = pos->x;
    pl.py = pos->y;
    pl.pz = pos->z;
    
    if ((njDistanceL2PL(&ln, &pl, &cp) == 0) && (((cp.x >= pos->x) && (cp.x <= (pos->x + w))) && ((cp.y >= pos->y) && (cp.y <= (pos->y + h)))))
    {
        p2->x = cp.x;
        p2->y = cp.y;
        p2->z = cp.z;
        
        PLANE = pl;

        ret = 1;
    }
    
    return ret;
}

// 100% matching!
int bhCollisionCheckL2YZPL(NJS_POINT3* p1, NJS_POINT3* p2, NJS_POINT3* pos, float h, float d, int flg)
{
    NJS_LINE pl;   
    NJS_LINE ln;   
    NJS_POINT3 cp;   
    int ret;

    ret = 0;

    ln.px = p1->x;
    ln.py = p1->y;
    ln.pz = p1->z;
    
    ln.vx = p2->x - p1->x;
    ln.vy = p2->y - p1->y;
    ln.vz = p2->z - p1->z;
    
    pl.vx = flg ? -1.0f : 1.0f;
    pl.vy = 0;
    pl.vz = 0;
    
    pl.px = pos->x;
    pl.py = pos->y;
    pl.pz = pos->z;
    
    if ((njDistanceL2PL(&ln, &pl, &cp) == 0) && (((cp.z >= pos->z) && (cp.z <= (pos->z + d))) && ((cp.y >= pos->y) && (cp.y <= (pos->y + h)))))
    {
        p2->x = cp.x;
        p2->y = cp.y;
        p2->z = cp.z;
        
        PLANE = pl;

        ret = 1;
    }

    return ret;
}

// 100% matching!
void bhGetHitCollisionNormal(NJS_POINT3* n)
{
	n->x = PLANE.vx;
	n->y = PLANE.vy;
	n->z = PLANE.vz;
}
