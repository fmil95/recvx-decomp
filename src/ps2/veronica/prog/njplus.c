#include "njplus.h"
#include "ps2_dummy.h"
#include "ps2_NaColi.h"
#include "ps2_NaMatrix.h"
#include "main.h"

NP_WORK np;

// 100% matching!
void npPlusInit() 
{
    int i;
    int j;
    
    np.buff = njpmemp; 
    np.buff2 = njpmemp + 131072;
    
    np.bp = np.buff; 
    np.bp2 = np.buff2; 
    
    for (i = 0; i < 128; i++) 
    { 
        for (j = 0; j < 2; j++) 
        { 
            np.mxp[i][j] = (NJS_MATRIX*)np.bp; 
            
            np.bp += sizeof(NJS_MATRIX);  
        } 
    } 
} 

// 100% matching!
int npCollisionCheckCC(NJS_CAPSULE* cpa, NJS_CAPSULE* cpb) 
{
    NJS_LINE lna;   
    NJS_LINE lnb;    
    NJS_LINE lnc;     
    NJS_CAPSULE* capa;
    NJS_CAPSULE* capb; 
    NJS_SPHERE sa;     
    NJS_SPHERE sb;    
    NJS_VECTOR vec;    
    float inn;        
    float lena;        
    float lenb;      
    float sca;        
    float temp; // not from DWARF

    lna.px = cpa->c1.x;
    lna.py = cpa->c1.y;
    lna.pz = cpa->c1.z;
    
    capb = cpa;
    
    lna.vx = cpa->c2.x - lna.px;
    lna.vy = cpa->c2.y - lna.py;
    lna.vz = cpa->c2.z - lna.pz;
    
    lnb.px = cpb->c1.x;
    lnb.py = cpb->c1.y;
    lnb.pz = cpb->c1.z; 
    
    lnb.vx = cpb->c2.x - lnb.px;
    lnb.vy = cpb->c2.y - lnb.py;
    lnb.vz = cpb->c2.z - lnb.pz;
    
    lena = njScalor((NJS_VECTOR*)&lna.vx);
    lenb = njScalor((NJS_VECTOR*)&lnb.vx);
    
    if (lena > lenb) 
    {
        capa = cpb;
        cpb = cpa;
        capb = cpb;
        
        lnc = lna;
        lna = lnb;
        lnb = lnc;
        
        temp = lena;
        lena = lenb;
        lenb = temp;
    } 
    else 
    {
        capa = cpa;
        capb = cpb;
    }
    
    njDistanceL2L(&lna, &lnb, (NJS_POINT3*)&sa.c, (NJS_POINT3*)&sb.c);
    
    sa.r = capa->r;
    sb.r = capb->r;
    
    vec.x = sa.c.x - lna.px;
    vec.y = sa.c.y - lna.py;
    vec.z = sa.c.z - lna.pz;
    
    sca = njScalor(&vec);
    
    njUnitVector(&vec);
    njUnitVector((NJS_VECTOR*)&lna.vx);
    
    inn = njInnerProduct(&vec, (NJS_VECTOR*)&lna.vx);
    
    if (inn > 0) 
    {
        if (sca > lena) 
        {
            sa.c.x = capa->c2.x;
            sa.c.y = capa->c2.y;
            sa.c.z = capa->c2.z;
        }
    } 
    else
    {
        sa.c.x = capa->c1.x;
        sa.c.y = capa->c1.y;
        sa.c.z = capa->c1.z;
    }
    
    vec.x = sb.c.x - lnb.px;
    vec.y = sb.c.y - lnb.py;
    vec.z = sb.c.z - lnb.pz;
    
    sca = njScalor(&vec);
    
    njUnitVector(&vec);
    njUnitVector((NJS_VECTOR*)&lnb.vx);
    
    inn = njInnerProduct((NJS_VECTOR*)&vec,(NJS_VECTOR*)&lnb.vx);
    
    if (inn > 0) 
    {
        if (sca > lenb)
        {
            sb.c.x = capb->c2.x;
            sb.c.y = capb->c2.y;
            sb.c.z = capb->c2.z;
        }
    } 
    else 
    {
        sb.c.x = capb->c1.x;
        sb.c.y = capb->c1.y;
        sb.c.z = capb->c1.z;
    }
    
    if (njCollisionCheckSS((NJS_SPHERE*)&sa, (NJS_SPHERE*)&sb) != 0) 
    {
        return 1;
    }
    
    sa.c.x = capa->c1.x;
    sa.c.y = capa->c1.y;
    sa.c.z = capa->c1.z;
    
    njDistanceP2L(&sa.c, &lnb, (NJS_POINT3*)&sb.c);
    
    vec.x = sb.c.x - lnb.px;
    vec.y = sb.c.y - lnb.py;
    vec.z = sb.c.z - lnb.pz;
    
    sca = njScalor(&vec);
    
    njUnitVector(&vec);
    
    inn = njInnerProduct(&vec, (NJS_VECTOR*)&lnb.vx);
    
    if (inn > 0)
    {
        if (sca > lenb)
        {
            sb.c.x = capb->c2.x;
            sb.c.y = capb->c2.y;
            sb.c.z = capb->c2.z;
        }
    }
    else
    {
        sb.c.x = capb->c1.x;
        sb.c.y = capb->c1.y;
        sb.c.z = capb->c1.z;
    }
    
    if (njCollisionCheckSS(&sa, &sb) != 0) 
    {
        return 1;
    }
    
    sa.c.x = capa->c2.x;
    sa.c.y = capa->c2.y;
    sa.c.z = capa->c2.z;
    
    njDistanceP2L(&sa.c, &lnb, (NJS_POINT3*)&sb.c);
    
    vec.x = sb.c.x - lnb.px;
    vec.y = sb.c.y - lnb.py;
    vec.z = sb.c.z - lnb.pz;
    
    sca = njScalor(&vec);
    
    njUnitVector(&vec);
    
    inn = njInnerProduct(&vec, (NJS_VECTOR*)&lnb.vx);
    
    if (inn > 0) 
    {
        if (sca > lenb) 
        {
            sb.c.x = capb->c2.x;
            sb.c.y = capb->c2.y;
            sb.c.z = capb->c2.z;
        }
    } 
    else 
    {
        sb.c.x = capb->c1.x;
        sb.c.y = capb->c1.y;
        sb.c.z = capb->c1.z;
    }
    
    if (njCollisionCheckSS(&sa, &sb) != 0) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

// 100% matching!
int npCollisionCheckCCEx(NJS_CAPSULE* cpa, NJS_CAPSULE* cpb, NJS_POINT3* pos)
{
    NJS_LINE lna;  
    NJS_LINE lnb;       
    NJS_LINE lnc;      
    NJS_CAPSULE* capa; 
    NJS_CAPSULE* capb; 
    NJS_SPHERE sa;      
    NJS_SPHERE sb;      
    NJS_VECTOR vec;     
    float inn;         
    float lena;        
    float lenb;       
    float sca;               
    float temp; // not from DWARF

    lna.px = cpa->c1.x;
    lna.py = cpa->c1.y;
    lna.pz = cpa->c1.z;
    
    capb = cpa;
    
    lna.vx = cpa->c2.x - lna.px;
    lna.vy = cpa->c2.y - lna.py;
    lna.vz = cpa->c2.z - lna.pz;
    
    lnb.px = cpb->c1.x;
    lnb.py = cpb->c1.y;
    lnb.pz = cpb->c1.z; 
    
    lnb.vx = cpb->c2.x - lnb.px;
    lnb.vy = cpb->c2.y - lnb.py;
    lnb.vz = cpb->c2.z - lnb.pz;
    
    lena = njScalor((NJS_VECTOR*)&lna.vx);
    lenb = njScalor((NJS_VECTOR*)&lnb.vx);
    
    if (lena > lenb) 
    {
        capa = cpb;
        cpb = cpa;
        capb = cpb;
        
        lnc = lna;
        lna = lnb;
        lnb = lnc;
        
        temp = lena;
        lena = lenb;
        lenb = temp;
    } 
    else 
    {
        capa = cpa;
        capb = cpb;
    }
    
    njDistanceL2L(&lna, &lnb, (NJS_POINT3*)&sa.c, (NJS_POINT3*)&sb.c);
    
    sa.r = capa->r;
    sb.r = capb->r;
    
    vec.x = sa.c.x - lna.px;
    vec.y = sa.c.y - lna.py;
    vec.z = sa.c.z - lna.pz;
    
    sca = njScalor(&vec);
    
    njUnitVector(&vec);
    njUnitVector((NJS_VECTOR*)&lna.vx);
    
    inn = njInnerProduct(&vec, (NJS_VECTOR*)&lna.vx);
    
    if (inn > 0) 
    {
        if (sca > lena) 
        {
            sa.c.x = capa->c2.x;
            sa.c.y = capa->c2.y;
            sa.c.z = capa->c2.z;
        }
    } 
    else
    {
        sa.c.x = capa->c1.x;
        sa.c.y = capa->c1.y;
        sa.c.z = capa->c1.z;
    }
    
    vec.x = sb.c.x - lnb.px;
    vec.y = sb.c.y - lnb.py;
    vec.z = sb.c.z - lnb.pz;
    
    sca = njScalor(&vec);
    
    njUnitVector(&vec);
    njUnitVector((NJS_VECTOR*)&lnb.vx);
    
    inn = njInnerProduct((NJS_VECTOR*)&vec,(NJS_VECTOR*)&lnb.vx);
    
    if (inn > 0) 
    {
        if (sca > lenb)
        {
            sb.c.x = capb->c2.x;
            sb.c.y = capb->c2.y;
            sb.c.z = capb->c2.z;
        }
    } 
    else 
    {
        sb.c.x = capb->c1.x;
        sb.c.y = capb->c1.y;
        sb.c.z = capb->c1.z;
    }
    
    if (njCollisionCheckSS((NJS_SPHERE*)&sa, (NJS_SPHERE*)&sb) != 0) 
    {
        NJS_POINT3 scl; 
        
        scl.x = sb.c.x - sa.c.x;
        scl.y = sb.c.y - sa.c.y;
        scl.z = sb.c.z - sa.c.z; 
        
        if (njScalor(&scl) > sa.r) 
        {
            njUnitVector(&scl);
            
            pos->x = sa.c.x + (scl.x * sa.r);
            pos->y = sa.c.y + (scl.y * sa.r);
            pos->z = sa.c.z + (scl.z * sa.r);
        }
        else 
        {
            pos->x = sb.c.x;
            pos->y = sb.c.y;
            pos->z = sb.c.z;
        }
        
        return 1;
    }
    
    sa.c.x = capa->c1.x;
    sa.c.y = capa->c1.y;
    sa.c.z = capa->c1.z;
    
    njDistanceP2L(&sa.c, &lnb, (NJS_POINT3*)&sb.c);
    
    vec.x = sb.c.x - lnb.px;
    vec.y = sb.c.y - lnb.py;
    vec.z = sb.c.z - lnb.pz;
    
    sca = njScalor(&vec);
    
    njUnitVector(&vec);
    
    inn = njInnerProduct(&vec, (NJS_VECTOR*)&lnb.vx);
    
    if (inn > 0)
    {
        if (sca > lenb)
        {
            sb.c.x = capb->c2.x;
            sb.c.y = capb->c2.y;
            sb.c.z = capb->c2.z;
        }
    }
    else
    {
        sb.c.x = capb->c1.x;
        sb.c.y = capb->c1.y;
        sb.c.z = capb->c1.z;
    }
    
    if (njCollisionCheckSS(&sa, &sb) != 0) 
    {
        NJS_POINT3 scl; 
        
        scl.x = sb.c.x - sa.c.x;
        scl.y = sb.c.y - sa.c.y;
        scl.z = sb.c.z - sa.c.z; 
        
        if (njScalor(&scl) > sa.r) 
        {
            njUnitVector(&scl);
            
            pos->x = sa.c.x + (scl.x * sa.r);
            pos->y = sa.c.y + (scl.y * sa.r);
            pos->z = sa.c.z + (scl.z * sa.r);
        }
        else 
        {
            pos->x = sb.c.x;
            pos->y = sb.c.y;
            pos->z = sb.c.z;
        }
        
        return 1;
    }
    
    sa.c.x = capa->c2.x;
    sa.c.y = capa->c2.y;
    sa.c.z = capa->c2.z;
    
    njDistanceP2L(&sa.c, &lnb, (NJS_POINT3*)&sb.c);
    
    vec.x = sb.c.x - lnb.px;
    vec.y = sb.c.y - lnb.py;
    vec.z = sb.c.z - lnb.pz;
    
    sca = njScalor(&vec);
    
    njUnitVector(&vec);
    
    inn = njInnerProduct(&vec, (NJS_VECTOR*)&lnb.vx);
    
    if (inn > 0) 
    {
        if (sca > lenb) 
        {
            sb.c.x = capb->c2.x;
            sb.c.y = capb->c2.y;
            sb.c.z = capb->c2.z;
        }
    } 
    else 
    {
        sb.c.x = capb->c1.x;
        sb.c.y = capb->c1.y;
        sb.c.z = capb->c1.z;
    }
    
    if (njCollisionCheckSS(&sa, &sb) != 0) 
    {
        NJS_POINT3 scl; 
        
        scl.x = sb.c.x - sa.c.x;
        scl.y = sb.c.y - sa.c.y;
        scl.z = sb.c.z - sa.c.z; 
        
        if (njScalor(&scl) > sa.r) 
        {
            njUnitVector(&scl);
            
            pos->x = sa.c.x + (scl.x * sa.r);
            pos->y = sa.c.y + (scl.y * sa.r);
            pos->z = sa.c.z + (scl.z * sa.r);
        }
        else 
        {
            pos->x = sb.c.x;
            pos->y = sb.c.y;
            pos->z = sb.c.z;
        }
        
        return 1;
    }
    else 
    {
        return 0;
    }
}

// 100% matching! 
int npCollisionCheckSC(NJS_SPHERE* sa, NJS_CAPSULE* cpb) 
{
    NJS_LINE lnb;  
    NJS_SPHERE sb; 
    NJS_POINT3 vec; 
    float inn;      
    float lr;      
    float lenb;    
    float sca;     
    
    lr = sa->r + cpb->r;
    
    lnb.px = cpb->c1.x;
    lnb.py = cpb->c1.y;
    lnb.pz = cpb->c1.z;
    
    lnb.vx = cpb->c2.x - lnb.px;
    lnb.vy = cpb->c2.y - lnb.py;
    lnb.vz = cpb->c2.z - lnb.pz;
    
    njDistanceP2L(&sa->c, &lnb, &sb.c);
    
    sb.r = cpb->r;
    
    lenb = njScalor((NJS_VECTOR*)&lnb.vx);
    
    vec.x = sb.c.x - lnb.px;
    vec.y = sb.c.y - lnb.py;
    vec.z = sb.c.z - lnb.pz;
    
    sca = njScalor(&vec);
    
    njUnitVector(&vec);
    njUnitVector((NJS_VECTOR*)&lnb.vx);
    
    inn = njInnerProduct(&vec, (NJS_VECTOR*)&lnb.vx);
    
    if (inn > 0)
    {
        if (sca > (lenb + lr)) 
        {
            return 0;
        }

        if (sca > lenb)
        {
            sb.c.x = cpb->c2.x;
            sb.c.y = cpb->c2.y;
            sb.c.z = cpb->c2.z;
        }
    }
    else
    {
        if (sca > lr) 
        {
            return 0;
        }

        sb.c.x = cpb->c1.x;
        sb.c.y = cpb->c1.y;
        sb.c.z = cpb->c1.z;
    } 
    
    return (njCollisionCheckSS(sa, &sb) != 0) ? 1 : 0;
}

// 100% matching!
void npDistanceP2C(NJS_POINT3* pos, NJS_CAPSULE* cap, NJS_POINT3* htp) 
{
	NJS_LINE ln;   
    NJS_VECTOR vec;
    float inn;    
    float len;      
    float sca;     

    ln.px = cap->c1.x;
    ln.py = cap->c1.y;
    ln.pz = cap->c1.z;

    ln.vx = cap->c2.x - ln.px;
    ln.vy = cap->c2.y - ln.py;
    ln.vz = cap->c2.z - ln.pz;
    
    njDistanceP2L(pos, &ln, htp);
    
    len = njScalor((NJS_VECTOR*)&ln.vx);
    
    vec.x = htp->x - ln.px;
    vec.y = htp->y - ln.py;
    vec.z = htp->z - ln.pz; 
    
    sca = njScalor(&vec);
    
    njUnitVector(&vec);
    njUnitVector((NJS_VECTOR*)&ln.vx);

    inn = njInnerProduct(&vec, (NJS_VECTOR*)&ln.vx); 
    
    if (inn > 0) 
    {
        if (sca > len) 
        {
            htp->x = cap->c2.x;
            htp->y = cap->c2.y;
            htp->z = cap->c2.z;
        }
    } 
    else 
    {
        htp->x = cap->c1.x;
        htp->y = cap->c1.y;
        htp->z = cap->c1.z;
    }
    
    vec.x = pos->x - htp->x;
    vec.y = pos->y - htp->y;
    vec.z = pos->z - htp->z;
    
    if (cap->r < njScalor(&vec))
    {
        njUnitVector(&vec);
        
        htp->x += vec.x * cap->r;
        htp->y += vec.y * cap->r;
        htp->z += vec.z * cap->r;
    } 
    else 
    {
        htp->x = pos->x;
        htp->y = pos->y;
        htp->z = pos->z;
    }
}

// 100% matching!
void npDrawPlane(NJS_POINT3* ps0, NJS_POINT3* ps1, NJS_POINT3* ps2, NJS_POINT3* ps3, unsigned int argb)
{
    NJS_POINT3COL p3c;
    NJS_POINT3 p3[4];
    NJS_COLOR col[4];

    if (argb == 0) 
    {
        argb = 0x80808080; 
    }
    
    p3c.p = p3;
    
    p3c.col = col;
    
    p3c.tex = NULL;
    
    p3c.num = 1;
    
    ((int*)&p3c.col->color)[0] = argb;
    ((int*)&p3c.col->color)[1] = argb;
    ((int*)&p3c.col->color)[2] = argb; 
    ((int*)&p3c.col->color)[3] = argb;
    
    p3[0].x = ps0->x;
    p3[0].y = ps0->y;
    p3[0].z = ps0->z;
    
    p3[1].x = ps1->x;
    p3[1].y = ps1->y;
    p3[1].z = ps1->z;
    
    p3[2].x = ps2->x;
    p3[2].y = ps2->y;
    p3[2].z = ps2->z;
    
    p3[3].x = ps3->x;
    p3[3].y = ps3->y;
    p3[3].z = ps3->z;
    
    njDrawPolygon3D(&p3c, 4, 96);
}

// 99.57% matching
void npCalcMorphing(NJS_CNK_OBJECT* obj_a, NJS_CNK_OBJECT* obj_b, float no, int obj_n)
{
    int i;
    int nb; 
    unsigned int ulSize; 
    
    njPushMatrix(NULL);
    
    np.mxp[128][2] = np.mxp[128][1];
    
    for (i = 0; i < obj_n; i++) 
    {
        if ((obj_a[i].model != NULL) && (!(obj_a[i].evalflags & 0x8))) 
        {
            obj_a[i].pos[0] = (no * (0.001f * (obj_b[i].pos[0] - obj_a[i].pos[0]))) + obj_a[i].pos[0];
            obj_a[i].pos[1] = (no * (0.001f * (obj_b[i].pos[1] - obj_a[i].pos[1]))) + obj_a[i].pos[1];
            obj_a[i].pos[2] = (no * (0.001f * (obj_b[i].pos[2] - obj_a[i].pos[2]))) + obj_a[i].pos[2];

            nb = ((unsigned short*)obj_a[i].model->vlist)[3];

            np.vlp2[i] = (int*)np.mxp[128][2]; 
            
            ulSize = (nb * 32) + 76;
            
            ulSize += 64 - (ulSize & 0x3F);
            
            np.mxp[128][2] = (NJS_MATRIX*)((int)np.mxp[128][2] + ulSize);
            
            npTransform(&obj_a[i], &obj_b[i], no, i);
        }
    } 
    
    njPopMatrix(1);
}

// 99.95% matching
void npTransform(NJS_CNK_OBJECT* srcobj, NJS_CNK_OBJECT* dstobj, register float no, int ono)
{
    int s_nb;
    register NJS_POINT4* dp; 
    register NJS_POINT4* fp; 
    register NJS_POINT4* sp; 
    HDR_PS* pSrc;
    HDR_PS* pDst; 

    pSrc = (HDR_PS*)srcobj->model->vlist; 
    fp = (NJS_POINT4*)dstobj->model->vlist; 

    s_nb = pSrc->usIndexMax; 

    if (s_nb != ((HDR_PS*)fp)->usIndexMax)
    {
        return; 
    }

    sp = (NJS_POINT4*)(pSrc + 1); 
    dp = (NJS_POINT4*)((HDR_PS*)fp + 1); 
    fp = (NJS_POINT4*)np.vlp2[ono]; 

    fp = (NJS_POINT4*)((int)fp | 0x30000000); 

    ((HDR_PS*)fp)->ucType = pSrc->ucType; 
    ((HDR_PS*)fp)->ucAttr = pSrc->ucAttr; 
    
    ((HDR_PS*)fp)->usSize = pSrc->usSize; 
    
    ((HDR_PS*)fp)->usIndexOfs = pSrc->usIndexOfs; 
    ((HDR_PS*)fp)->usIndexMax = s_nb; 

    no *= 0.001f; 
    
    fp = (NJS_POINT4*)((HDR_PS*)fp + 1);
    
    for ( ; s_nb != 0; s_nb--) 
    { 
        if ((sp->x != dp->x) || (sp->y != dp->y) || (sp->z != dp->z)) 
        { 
            asm volatile 
            {
            .set noreorder
                
                mfc1      t0, no 
                
                lqc2      vf4, 0x0(sp)
                lqc2      vf5, 0x0(dp) 
                lqc2      vf6, 0x10(sp) 
                lqc2      vf7, 0x10(dp) 
                
                qmtc2     t0, vf12 
                
                vsub.xyz  vf5xyz, vf5xyz, vf4xyz 
                vsub.xyz  vf7xyz, vf7xyz, vf6xyz 
                
                vmulx.xyz vf5xyz, vf5xyz, vf12x 
                vmulx.xyz vf7xyz, vf7xyz, vf12x 
                
                vadd.xyz  vf5xyz, vf5xyz, vf4xyz 
                vadd.xyz  vf7xyz, vf7xyz, vf6xyz 
                
                sqc2      vf5, 0x0(fp) 
                sqc2      vf7, 0x10(fp) 

            .set reorder
            }
                
            fp += 2; 
            sp += 2; 
            dp += 2;
        } 
        else 
        { 
            asm volatile
            {
                .set noreorder
                
                lqc2 vf4, 0x0(sp) 
                lqc2 vf6, 0x10(sp)
                    
                sqc2 vf4, 0x0(fp)
                sqc2 vf6, 0x10(fp)

                .set reorder
            }
            
            fp += 2; 
            sp += 2;
            dp += 2;
        } 
    } 

    ((HDR_PS*)fp)->ucType = 0xFF; 

    srcobj->model->vlist = np.vlp2[ono]; 
} 

// 100% matching!
void npPushMdlstr(NJS_CNK_OBJECT* objp, int obj_n)
{
    int i; 
    
    for (i = 0; i < obj_n; i++, objp++) 
    {
        if (objp->model != NULL) 
        {
            np.vlist[i] = objp->model->vlist;
        } 
    } 
}

// 100% matching!
void npPopMdlstr(NJS_CNK_OBJECT* objp, int obj_n)
{
    int i; 
    
    for (i = 0; i < obj_n; i++, objp++) 
    {
        if (objp->model != NULL) 
        {
            objp->model->vlist = np.vlist[i];
        } 
    } 
}

// 100% matching!
void npPushMdlstr2(NJS_CNK_OBJECT* objp, int obj_n)
{
    int i; 
    
    for (i = 0; i < obj_n; i++, objp++) 
    {
        if ((objp->model != NULL) && (!(objp->evalflags & 0x8))) 
        {
            np.mdlstr2[i].pos[0] = objp->pos[0];
            np.mdlstr2[i].pos[1] = objp->pos[1];
            np.mdlstr2[i].pos[2] = objp->pos[2];
            
            np.mdlstr2[i].vlist = objp->model->vlist;
            np.mdlstr2[i].plist = objp->model->plist;
        } 
    } 
}

// 100% matching!
void npPopMdlstr2(NJS_CNK_OBJECT* objp, int obj_n)
{
    int i; 
    
    for (i = 0; i < obj_n; i++, objp++) 
    {
        if ((objp->model != NULL) && (!(objp->evalflags & 0x8))) 
        {
            objp->pos[0] = np.mdlstr2[i].pos[0];
            objp->pos[1] = np.mdlstr2[i].pos[1];
            objp->pos[2] = np.mdlstr2[i].pos[2];
            
            objp->model->vlist = np.mdlstr2[i].vlist;
            objp->model->plist = np.mdlstr2[i].plist;
        } 
    } 
}

// 100% matching!
void npCnkFlatOff(NJS_CNK_OBJECT* objp)
{
    int offset;
    short* plP;
    short head; 

    if (objp->model != NULL) 
    {
        plP = objp->model->plist;
        
        while (TRUE)
        {
            head = (unsigned char)*plP++; 
            
            if ((head >= 64) && (head < 67)) 
            { 
                plP[-1] &= ~0x2000; 
                
                offset = *plP++;
                plP += offset; 
            } 
            else if (head == 8) 
            { 
                plP++;
            }
            else if ((head >= 17) && (head < 24)) 
            { 
                offset = *plP++; 
                plP += offset; 
            } 
            else if ((head >= 56) && (head < 59))
            {
                offset = *plP++; 
                plP += offset; 
            } 
            else if (head == 255)
            {  
                break;
            }
        }
    }
    
    if (objp->child != NULL) 
    {
        npCnkFlatOff(objp->child);
    }
    
    if (objp->sibling != NULL) 
    {
        npCnkFlatOff(objp->sibling);
    }
}

// 100% matching!
void npClrTranslate() 
{
    njGetMatrix(lcmat);
   
    lcmat[0][14] = lcmat[0][13] = lcmat[0][12] = 0;
    
    njSetMatrix(NULL, lcmat); 
}

// 100% matching!
void npSetMemory(unsigned char* memp, unsigned int size, char dat)
{
    while (size-- != 0) 
    {
        *memp++ = dat;
    }
}

// 100% matching!
void npSetMemoryL(unsigned int* memp, unsigned int size, int dat) 
{ 
    while (size-- != 0) 
    {
        *memp++ = dat;
    }
}

// 100% matching!
void npCopyMemory(unsigned char* dst, unsigned char* src, unsigned int size)
{
    while (size-- != 0)
    {
        *dst++ = *src++;
    }
}

// 100% matching!
void npGetWHDSizeSub(NJS_CNK_OBJECT* objp, NJS_POINT3* whd)
{
	NJS_POINT3* ps3;   
	NJS_POINT3 pd3;    
	NJS_POINT4* ps4;  
    NJS_POINT4 pd4;    
	int i;           
    HDR_CV* pHdrCv; 
    HDR_PS* pHdrPs;

    njPushMatrix(NULL);
    
    njTranslate(NULL, objp->pos[0], objp->pos[1], objp->pos[2]);
    
    njRotateXYZ(NULL, objp->ang[0], objp->ang[1], objp->ang[2]);
    
    if ((objp->model != NULL) && (!(objp->evalflags & 0x8))) 
    { 
        pHdrPs = (HDR_PS*)objp->model->vlist;
        
        if (pHdrPs->ucType == 51)
        {
            ps4 = (NJS_POINT4*)((unsigned int)pHdrPs + 64);
            
            for (i = pHdrPs->usIndexMax; i-- != 0; )
            {
                njCalcPoint4(NULL, ps4, &pd4);
                
                if (fabsf(pd4.x) >= whd->x)
                {
                    whd->x = fabsf(pd4.x); 
                }
                
                if (fabsf(pd4.y) >= whd->y) 
                {
                    whd->y = fabsf(pd4.y);
                }
                
                if (fabsf(pd4.z) >= whd->z) 
                {
                    whd->z = fabsf(pd4.z);
                }
                
                ps4 = (NJS_POINT4*)((unsigned int)ps4 + 32);
            }
        } 
        else 
        {
            ps3 = (NJS_POINT3*)((unsigned int)pHdrPs + 8);
            
            for (i = pHdrPs->usIndexMax; i-- != 0; ) 
            {
                njCalcPoint(NULL, ps3, &pd3);
                
                if (fabsf(pd3.x) >= whd->x) 
                {
                    whd->x = fabsf(pd3.x);
                }
                
                if (fabsf(pd3.y) >= whd->y) 
                {
                    whd->y = fabsf(pd3.y);
                }
                
                if (fabsf(pd3.z) >= whd->z)
                {
                    whd->z = fabsf(pd3.z);
                }
                
                ps3 = (NJS_POINT3*)((unsigned int)ps3 + 24);
            }
        }
    }
    
    if (objp->child != NULL) 
    {
        npGetWHDSizeSub(objp->child, whd);
    }
    
    njPopMatrix(1);
    
    if (objp->sibling != NULL) 
    {
        npGetWHDSizeSub(objp->sibling, whd);
    }
}

// 100% matching!
void npGetWHDSize(NJS_CNK_OBJECT* objp, NJS_POINT3* whd) 
{
    whd->x = whd->y = whd->z = 0;
    
    njUnitMatrix(NULL);
    
    npGetWHDSizeSub(objp, whd);
}

// 100% matching!
void npSkinConvPreparation(NJS_CNK_OBJECT* objp)
{
    NJS_POINT3 ps = { 0 }; 
    int flg;      
    int mno;       
    int nb;       
    
    njPushMatrix(NULL);
    
    if (!(objp->evalflags & 0x20000000)) 
    {
        flg = *np.sknp++;
        
        if (flg != 0) 
        {
            if ((flg & 0x2)) 
            {
                mno = *np.sknp++;
                
                nb = *np.sknp++;

                np.cobj[mno] = objp;
                
                np.sktp[mno] = np.sknp;
                
                np.sknp += nb;
            } 
            else 
            {
                mno = *np.sknp++;
            }
        }
        
        njTranslate(NULL, objp->pos[0], objp->pos[1], objp->pos[2]);
        
        if ((flg & 0x2))
        {
            njCalcPoint(NULL, &ps, &np.op[mno]);
        }
    }
    
    if (objp->child != NULL)
    {
        npSkinConvPreparation(objp->child);
    }
    
    njPopMatrix(1);
    
    if (objp->sibling != NULL) 
    {
        npSkinConvPreparation(objp->sibling);
    }
}

// 100% matching!
void npSkinConvSub(NJS_CNK_OBJECT* objp)
{
    NJS_POINT4 ps = { 0, 0, 0, 0 }; 
    NJS_POINT4 pd;         
    NJS_POINT4* p0;        
    int* skp;              
    int nb;                
    int i;                 
    int dt;                
    int flg;               
    int mno;               
    HDR_PS* pHdr;      
    unsigned short max; // not from the debugging symbols
    float x, y, z; // not from the debugging symbols

    flg = *np.sknp++;
    
    if (flg != 0) 
    {
        if ((flg & 0x2)) 
        {
            objp->evalflags |= 0x80000000;
            
            mno = *np.sknp++;
            
            nb = *np.sknp++;
            
            np.sknp = &np.sknp[nb];
        } 
        else 
        {
            mno = *np.sknp++;
        }
        
        skp = np.sktp[mno];
    }
    
    njTranslate(NULL, objp->pos[0], objp->pos[1], objp->pos[2]);
    
    ps.z = 0;
    ps.y = 0;
    ps.x = 0;
    ps.w = 1.0f;
    
    njCalcPoint4(NULL, &ps, &pd);
    
    if ((flg & 0x1))
    {
        pHdr = (HDR_PS*)np.cobj[mno]->model->vlist;
        
        max = pHdr->usIndexMax;
        
        p0 = (NJS_POINT4*)&pHdr[1];
        
        i = 0;
        
        if (0 < max)
        {
            do 
            {
                if (np.obj_now == (*skp++ >> 24)) 
                {
                    x = p0->x + np.op[mno].x;
                    y = p0->y + np.op[mno].y;
                    z = p0->z + np.op[mno].z;
    
                    p0->x = x - pd.x;
                    p0->y = y - pd.y;
                    p0->z = z - pd.z;
                }
                
                p0 += 2;
                
                i++;
            } while (i < max);
        }
    }
}

// 100% matching!
void npSkinConvMain(NJS_CNK_OBJECT* objp)
{
    njPushMatrix(NULL);
    
    if (!(objp->evalflags & 0x20000000)) 
    {
        npSkinConvSub(objp);
        
        np.obj_now++;
    }
    
    if (objp->child != NULL) 
    {
        npSkinConvMain(objp->child);
    }
    
    njPopMatrix(1);
    
    if (objp->sibling != NULL) 
    {
        npSkinConvMain(objp->sibling);
    }
}

// 100% matching!
void npSkinConvert(NJS_CNK_OBJECT* objp, int* sknp)
{
    np.sknp = sknp;
    
    njUnitMatrix(NULL);
    
    npSkinConvPreparation(objp);
    
    np.sknp = sknp;
    
    np.obj_now = 0;
    
    njUnitMatrix(NULL);
    
    npSkinConvMain(objp);
}

// 100% matching!
void npRetSkinConvMain(NJS_CNK_OBJECT* objp)
{
    NJS_POINT4 ps = { 0 }; 
    NJS_POINT4 pd;      
    NJS_POINT4* p0;     
    int* skp;         
    int nb;            
    int i;              
    int dt;          
    int flg;            
    int mno;             
    HDR_PS* pHdr;    
    unsigned short max; // not from DWARF
    
    njPushMatrix(NULL);
    
    if (!(objp->evalflags & 0x20000000)) 
    {
        flg = *np.sknp++;
        
        if (flg != 0) 
        {
            if ((flg & 0x2)) 
            {
                mno = *np.sknp++;
                
                nb = *np.sknp++;
                
                np.sknp = &np.sknp[nb];
            }
            else 
            {
                mno = *np.sknp++;
            }
            
            skp = np.sktp[mno];
        }
        
        njTranslate(NULL, objp->pos[0], objp->pos[1], objp->pos[2]);
        
        ps.z = 0;
        ps.y = 0;
        ps.x = 0;
        ps.w = 1.0f;
        
        njCalcPoint4(NULL, &ps, &pd); 
        
        if ((flg & 0x1)) 
        {
            pHdr = (HDR_PS*)np.cobj[mno]->model->vlist;
            
            max = pHdr->usIndexMax;
            
            p0 = (NJS_POINT4*)&pHdr[1];
            
            i = 0;
            
            if (0 < max)
            {
                do 
                {
                    if (np.obj_now == (*skp++ >> 24)) 
                    {
                        p0->x = p0->x + (pd.x - np.op[mno].x);
                        p0->y = p0->y + (pd.y - np.op[mno].y);
                        p0->z = p0->z + (pd.z - np.op[mno].z);
                    }
                    
                    p0 += 2;
                    
                    i++;
                } while (i < max);
            }
        }
        
        np.obj_now++;
    }
    
    if (objp->child != NULL) 
    {
        npRetSkinConvMain(objp->child);
    }
    
    njPopMatrix(1);
    
    if (objp->sibling != NULL) 
    {
        npRetSkinConvMain(objp->sibling);
    }
}

// 100% matching!
void npRetSkinConvert(NJS_CNK_OBJECT* objp, int* sknp) 
{
    np.sknp = sknp;
    
    njUnitMatrix(NULL);
    
    npSkinConvPreparation(objp);
    
    np.sknp = sknp;
    
    np.obj_now = 0;
    
    njUnitMatrix(NULL);
    
    npRetSkinConvMain(objp);
}

// 100% matching!
unsigned int npGetMatColor(NJS_CNK_OBJECT* objp, int obj_n)
{
	int i;
    unsigned int* pnt;

    for (i = 0; i < obj_n; i++, objp++) 
    {
        if ((objp->model != NULL) && (!(objp->evalflags & 0x8))) 
        {
            pnt = (unsigned int*)objp->model->plist;
        
            return *++pnt;
        }
    }
    
    return 0;
}

// 100% matching!
void npSetAllMatColor(NJS_CNK_OBJECT* objp, int obj_n, unsigned int argb)
{
    int i;         
    int offset;     
    short head;         
    short* plp;         
    unsigned char* mat; 
    unsigned char a;    
    unsigned char r;    
    unsigned char g;    
    unsigned char b;    
    
    a = ((argb & 0xFF000000) >> 24) & 0xFF;
    r = ((argb & 0xFF0000) >> 16) & 0xFF;
    g = ((argb & 0xFF00) >> 8) & 0xFF;
    b = argb & 0xFF;
    
    for (i = 0; i < obj_n; i++, objp++)
    {
        if ((objp->model != NULL) && (!(objp->evalflags & 0x8))) 
        {
            plp = objp->model->plist;
            
            while (TRUE) 
            {
                head = (unsigned char)*plp++; 
                
                if ((head >= 64) && (head < 67)) 
                {
                    offset = *plp++; 
                    plp += offset;
                }
                else if (head == 8) 
                {
                    plp++;
                }
                else if ((head >= 17) && (head < 24)) 
                {
                    mat = (unsigned char*)plp + 2;
                    
                    switch (head) 
                    {    
                    case 17:
                    case 21:
                        *mat++ = b;
                        *mat++ = g;
                        *mat++ = r;
                        
                        if (*mat != 0) 
                        {
                            *mat = a;
                        }
                        
                        break;
                    case 19:
                    case 23:
                        *mat++ = b;
                        *mat++ = g;
                        *mat++ = r;
                        
                        if (*mat != 0) 
                        {
                            *mat = a;
                        }
                        
                        mat++;
                        
                        *mat++ = b;
                        *mat++ = g;
                        *mat++ = r;
                        
                        if (*mat != 0) 
                        {
                            *mat = a;
                        }
                        
                        break;
                    }
                    
                    offset = *plp++; 
                    plp += offset;
                }
                else if ((head >= 56) && (head < 59)) 
                {
                    offset = *plp++; 
                    plp += offset;
                }
                else if (head == 255)
                { 
                    break;
                }
            } 
        }
    }
}

// 100% matching!
void npChangeMatAlphaColor(NJS_CNK_OBJECT* objp, int obj_n, unsigned char alpha)
{
	int i;
    unsigned char* pnt;
    
    for (i = 0; i < obj_n; i++, objp++)
    {
        if ((objp->model != NULL) && (!(objp->evalflags & 0x8))) 
        {
            pnt = (unsigned char*)objp->model->plist;

            pnt += 7;
            
            *pnt = alpha;

            pnt += 4;
            
            *pnt = alpha;
        }
    } 
}

// 100% matching!
void npSetAllMatAlphaColor(NJS_CNK_OBJECT* objp, int obj_n, unsigned char alpha)
{
    int i;
    int offset;
    short head;
    short* plp;
    unsigned char* mat;
    
    for (i = 0; i < obj_n; i++, objp++)
    {
        if ((objp->model != NULL) && (!(objp->evalflags & 0x8))) 
        {
            plp = objp->model->plist;
            
            while (TRUE) 
            {
                head = (unsigned char)*plp++; 
                
                if ((head >= 64) && (head < 67)) 
                {
                    offset = *plp++; 
                    plp += offset;
                }
                else if (head == 8) 
                {
                    plp++;
                }
                else if ((head >= 17) && (head < 24)) 
                {
                    mat = (unsigned char*)plp + 2;
                    
                    switch (head) 
                    {    
                    case 17:
                    case 21:
                        mat += 3;
                        
                        *mat = alpha;
                        break;
                    case 19:
                    case 23:
                        mat += 3;
                        
                        *mat = alpha;

                        mat += 4;
                        
                        *mat = alpha;
                        break;
                    }
                    
                    offset = *plp++; 
                    plp += offset;
                }
                else if ((head >= 56) && (head < 59)) 
                {
                    offset = *plp++; 
                    plp += offset;
                }
                else if (head == 255)
                { 
                    break;
                }
            } 
        }
    }
}

// 100% matching!
void npSetOffsetUV(NJS_CNK_MODEL* mdlp, short offu, short offv)
{
	int offset; 
    int srp_num; 
    int usr_num;
    short head; 
    short* plp;  

    plp = mdlp->plist; 
    
    while (TRUE) 
    {
        head = (unsigned char)*plp++; 
        
        if ((head >= 64) && (head < 67)) 
        {
            offset = *plp++; 
            
            usr_num = (*plp >> 14) & 0x3; 
            srp_num = *plp++ & ~0xC000; 
            
            if (head == 64) 
            { 
                plp += offset; 
            } 
            else 
            {
                asm volatile 
                ("
                .set noreorder
                
                l_0012DE68: 
                    lh   t2, 0(%0) 
                    
                    bgez t2, l_0012DE78
                    add  %0, %0, 2
                    
                    neg  t2, t2
                    
                l_0012DE78:
                    lh   t0, 2(%0)
                    lh   t1, 4(%0)
                    
                    add  t0, t0, %1
                    add  t1, t1, %2
                    
                    sh   t0, 2(%0)
                    sh   t1, 4(%0)
                    
                    add  t2, t2, -1

                    bgtz t2, l_0012DE78
                    add  %0, %0, 6
                    
                    add  %0, %0, %3
                    add  %4, %4, -1
                    
                    bgtz %4, l_0012DE68
                    add  %0, %0, %3
                    
                    add  %0, %0, zero
                    
                .set reorder
                " : "=r"(plp) : "r"(offu), "r"(offv), "r"(usr_num), "r"(srp_num) : "t0", "t1", "t2"
                );
            }
        }
        else if (head == 8) 
        { 
            plp++; 
        } 
        else if ((head >= 17) && (head < 24)) 
        { 
            offset = *plp++; 
            plp += offset;
        } 
        else if ((head >= 56) && (head < 59)) 
        { 
            offset = *plp++; 
            plp += offset; 
        }
        else if (head == 255)
        { 
            break;
        }
    }
}

// 100% matching!
void npSetOffsetUV2(NJS_CNK_MODEL* mdlp, short offu, short offv)
{
    int srp_num; 
    int usr_num;
    short head; 
    short* plp;  

    plp = mdlp->plist; 
    
    while (TRUE) 
    {
        head = (unsigned char)*plp++; 
        
        if (head == 66)
        { 
            usr_num = (*++plp >> 14) & 0x3; 
            srp_num = *plp++ & ~0xC000;
           
            asm volatile 
            ("
            .set noreorder
            
            l_0012DFA8: 
                lh   t2, 0(%0) 
                
                bgez t2, l_0012DFB8
                add  %0, %0, 2
                
                neg  t2, t2
                
            l_0012DFB8:
                lh   t0, 2(%0)
                lh   t1, 4(%0)
                
                add  t0, t0, %1
                add  t1, t1, %2
                
                sh   t0, 2(%0)
                sh   t1, 4(%0)
                
                add  t2, t2, -1

                bgtz t2, l_0012DFB8
                add  %0, %0, 6
                
                add  %0, %0, %3
                add  %4, %4, -1
                
                bgtz %4, l_0012DFA8
                add  %0, %0, %3
                
            .set reorder
            " : "=r"(plp) : "r"(offu), "r"(offv), "r"(usr_num), "r"(srp_num) : "t0", "t1", "t2"
            );

            break;
        }
        else if (head != 255)
        { 
            *plp++;  
        }
        else 
        {
            break;
        }
    }
}

// 100% matching!
int npCopyVlist(int* dstp, int* srcp)
{
    HDR_PS* pPs;
    int nb;
	
    pPs = (HDR_PS*)srcp;

    if (pPs->ucType == 41)
    {
        nb = ((*(int*)&pPs->usIndexOfs >> 16) * 24) + 12;
        
        njMemCopy4(dstp, srcp, nb / 4);
    } 
    else 
    {
        nb = (pPs->usIndexMax * 32) + 72;
        
        njMemCopy4(dstp, srcp, nb / 4);
    }
    
    return nb;
}

// 100% matching!
void npCutSkin() 
{
    
}

// 100% matching!
void npInitCalcSkin(void* pwp, int obj_n, int* sknp)
{ 
	NJS_MATRIX mat;        
	O_WORK* owp;     
	NJS_CNK_OBJECT* op;    
	int i;                
	int flg;               
	int nb;               
	int mno;              
    unsigned int ulSize;    
	unsigned char matb[64]; 

    owp = ((BH_PWORK*)pwp)->mlwP->owP; 
    
    np.bp = np.buff + (obj_n * 128); 
    
    njUnitMatrix(NULL);
    
    np.sknp = sknp; 
    
    op = ((BH_PWORK*)pwp)->mlwP->objP; 
    
    for (i = 0; i < obj_n; i++, op++, owp++)
    { 
        flg = *np.sknp++;
        
        if (flg != 0) 
        { 
            if ((flg & 0x2)) 
            { 
                mno = *np.sknp++;
                
                nb = *np.sknp++; 
                
                np.sknp += nb; 
                
                np.vlp[mno] = (int*)np.bp;
                
                ulSize = (nb * 32) + 32;
                
                ulSize += 64 - (ulSize & 0x3F); 
                
                np.bp += ulSize; 
            } 
            else 
            { 
                np.sknp++; 
            }
            
            asm volatile 
            ("
            .set noreorder
            
                ldl      t0, 7(%1) 
                ldr      t0, 0(%1)
                
                lw       t1, 8(%1)
                
                pcpyld   t0, t1, t0
            
                qmtc2    t0, vf8
            
                lqc2     vf7, 48(%0)
                lqc2     vf4, 0(%0)
                lqc2     vf5, 16(%0)
                lqc2     vf6, 32(%0)
                
                vsub.xyz vf7xyz, vf7xyz, vf8xyz
                
                sqc2     vf4, 0(%2)
                sqc2     vf5, 16(%2)
                sqc2     vf6, 32(%2)
                sqc2     vf7, 48(%2)
                sqc2     vf4, 64(%2)
                sqc2     vf5, 80(%2)
                sqc2     vf6, 96(%2)
                sqc2     vf7, 112(%2) 
            
            .set reorder
            " : : "r"(&owp->mtx), "r"(&((BH_PWORK*)pwp)->px), "r"(np.mxp[i][0]), "r"(owp) 
            );
                
            njRotXYZ(np.mxp[i][0], -op->ang[0], -op->ang[1], -op->ang[2]); 
        }
    } 
} 

// 99.93% matching
void npCalcSkin(void* pwp, int obj_n, int* sknp)
{ 
    NJS_POINT4* p0;
    NJS_CNK_OBJECT* op;
    float lv;
    float* p1;
    int i;
    int j;
    int flg;
    int rg0;
    int nb;
    HDR_PS* pHdr0;
    HDR_PS* pHdr1;
    static float level[10] = { 0.1000000015f, 0.200000003f, 0.3000000119f, 0.400000006f, 0.5f, 0.6000000238f, 0.6999999881f, 0.8000000119f, 0.8999999762f, 1.0f };

    if (sknp != NULL)
    { 
        njPushMatrixEx(); 

        npInitCalcSkin(pwp, obj_n, sknp); 
        
        np.sknp = sknp; 
        
        op = (NJS_CNK_OBJECT*)((O_WRK*)pwp)->mlwP->objP; 
        
        for (i = 0; i < obj_n; i++, op++) 
        { 
            flg = *np.sknp++; 
            
            if (flg != 0) 
            { 
                if ((flg & 0x2)) 
                { 
                    pHdr0 = (HDR_PS*)op->model->vlist;
                    
                    rg0 = *np.sknp++; 
                    
                    op->model->vlist = np.vlp[rg0]; 
                    
                    pHdr1 = (HDR_PS*)np.vlp[rg0]; 
                    
                    nb = *np.sknp++;
    
                    pHdr1 = (HDR_PS*)((int)pHdr1 | 0x30000000); 
    
                    pHdr1->ucType = pHdr0->ucType;
                    pHdr1->ucAttr = pHdr0->ucAttr; 
                    
                    pHdr1->usSize = pHdr0->usSize;
                    
                    pHdr1->usIndexOfs = pHdr0->usIndexOfs; 
                    pHdr1->usIndexMax = pHdr0->usIndexMax; 
                    
                    p0 = (NJS_POINT4*)(pHdr0 + 1); 
                    p1 = (float*)(pHdr1 + 1); 
    
                    for (j = 0; j < nb; j++) 
                    { 
                        rg0 = *np.sknp++; 
                        
                        lv = level[(rg0 >> 16) & 0xFF]; 
                        
                        rg0 >>= 24;
                        
                        if (lv != 1.0f) 
                        { 
                            asm volatile 
                            ("
                            .set noreorder
                            
                                mfc1        t0, %0 
                                
                                qmtc2       t0, vf13
                                
                                lqc2        vf4, 0(%1)
                                lqc2        vf5, 0(%3)
                                lqc2        vf6, 0x10(%3)
                                lqc2        vf7, 0x20(%3)
                                lqc2        vf8, 0x30(%3)
                                
                                vmulax.xyz  ACC, vf5, vf4x
                                
                                vmadday.xyz ACC, vf6, vf4y
                                vmaddaz.xyz ACC, vf7, vf4z
                                
                                vmaddw.xyz  vf9, vf8, vf0w
                                
                                lqc2        vf5, 0(%4)
                                lqc2        vf6, 0x10(%4)
                                lqc2        vf7, 0x20(%4)
                                lqc2        vf8, 0x30(%4)
                                
                                vmulax.xyz  ACC, vf5, vf4x
                                
                                vmadday.xyz ACC, vf6, vf4y
                                vmaddaz.xyz ACC, vf7, vf4z
                                
                                vmaddw.xyz  vf10, vf8, vf0w
                                
                                vsub.xyz    vf5, vf10, vf9
                                
                                vmulx.xyz   vf6, vf5, vf13x
                                
                                vadd.xyz    vf7, vf6, vf9
                                
                                sqc2        vf7, 0(%2) 
                                
                            .set reorder
                            " : : "f"(lv), "r"(p0), "r"(p1), "r"(np.mxp[rg0][0]), "r"(np.mxp[rg0][1]) : "t0" 
                            );
                            
                            p1 += 4; 
                            p0++; 
                            
                            asm volatile 
                            ("
                            .set noreorder
                                             
                                mfc1        t0, %0 
                                
                                qmtc2       t0, vf13
                                
                                lqc2        vf4, 0(%1)
                                lqc2        vf5, 0(%3)
                                lqc2        vf6, 0x10(%3)
                                lqc2        vf7, 0x20(%3)
                                lqc2        vf8, 0(%4)
                                lqc2        vf9, 0x10(%4)
                                lqc2        vf10, 0x20(%4)
                                
                                vmulax.xyz  ACC, vf5, vf4x
                                
                                vmadday.xyz ACC, vf6, vf4y
                                
                                vmaddz.xyz  vf11, vf7, vf4z
                                
                                vmulax.xyz  ACC, vf8, vf4x
                                
                                vmadday.xyz ACC, vf9, vf4y
                                
                                vmaddz.xyz  vf12, vf10, vf4z
                                
                                vsub.xyz    vf5, vf12, vf11
                                
                                vmulx.xyz   vf6, vf5, vf13x
                                
                                vadd.xyz    vf7, vf6, vf11
                                
                                sqc2        vf7, 0(%2) 
                                
                            .set reorder
                            " : : "f"(lv), "r"(p0),  "r"(p1), "r"(np.mxp[rg0][0]), "r"(np.mxp[rg0][1]) : "t0" 
                            );
                            
                            p1 += 4; 
                            p0++;
                        } 
                        else 
                        { 
                            asm volatile 
                            ("
                            .set noreorder
                                              
                                lqc2        vf4, 0(%0) 
                                lqc2        vf11, 0x10(%0)
                                lqc2        vf5, 0(%2)
                                lqc2        vf6, 0x10(%2)
                                lqc2        vf7, 0x20(%2)
                                lqc2        vf8, 0x30(%2)
                                
                                vmulax.xyz  ACC, vf5xyz, vf4x
                                
                                vmadday.xyz ACC, vf6xyz, vf4y
                                vmaddaz.xyz ACC, vf7xyz, vf4z
                                
                                vmaddw.xyz  vf9, vf8xyz, vf0w
                                
                                vmulax.xyz  ACC, vf5xyz, vf11x
                                
                                vmadday.xyz ACC, vf6xyz, vf11y
                                
                                vmaddz.xyz  vf10xyz, vf7xyz, vf11z
                                
                                sqc2        vf9, 0(%1)
                                sqc2        vf10, 0x10(%1) 
                                
                            .set reorder
                            " : : "r"(p0), "r"(p1), "r"(np.mxp[rg0][1]), "r"(op)
                            ); 
                            
                            p0 += 2; 
                            p1 += 8; 
                        }
                    } 
                    
                    *(int*)p1 = 255; 
                } 
                else 
                { 
                    np.sknp++;
                } 
            }
        } 
    
        njPopMatrixEx(); 
    }
} 

// 100% matching!
void npInitCalcSkinFM(void* pwp, int obj_n, int* sknp)
{ 
	NJS_MATRIX mat;        
	O_WORK* owp;     
	NJS_CNK_OBJECT* op;    
	int i;                
	int flg;               
	int nb;               
	int mno;              
    unsigned int ulSize;    
	unsigned char matb[64]; 

    owp = ((BH_PWORK*)pwp)->mlwP->owP; 
    
    np.bp = np.buff + (obj_n * 128); 
    
    njUnitMatrix(NULL);
    
    np.sknp = sknp; 
    
    op = ((BH_PWORK*)pwp)->mlwP->objP; 
    
    for (i = 0; i < obj_n; i++, op++, owp++)
    { 
        if ((i < 11) || (i > 14))
        {
            flg = *np.sknp++;
        
            if (flg != 0) 
            { 
                if ((flg & 0x2)) 
                { 
                    mno = *np.sknp++;
                    
                    nb = *np.sknp++; 
                    
                    np.sknp += nb; 
                    
                    np.vlp[mno] = (int*)np.bp;
                    
                    ulSize = (nb * 32) + 96;
                    
                    ulSize += 64 - (ulSize & 0x3F); 
                    
                    np.bp += ulSize; 
                } 
                else 
                { 
                    np.sknp++; 
                }
                
                asm volatile 
                ("
                .set noreorder
                
                    ldl      t0, 7(%1) 
                    ldr      t0, 0(%1)
                    
                    lw       t1, 8(%1)
                    
                    pcpyld   t0, t1, t0
                
                    qmtc2    t0, vf8
                
                    lqc2     vf7, 48(%0)
                    lqc2     vf4, 0(%0)
                    lqc2     vf5, 16(%0)
                    lqc2     vf6, 32(%0)
                    
                    vsub.xyz vf7xyz, vf7xyz, vf8xyz
                    
                    sqc2     vf4, 0(%2)
                    sqc2     vf5, 16(%2)
                    sqc2     vf6, 32(%2)
                    sqc2     vf7, 48(%2)
                    sqc2     vf4, 64(%2)
                    sqc2     vf5, 80(%2)
                    sqc2     vf6, 96(%2)
                    sqc2     vf7, 112(%2) 
                
                .set reorder
                " : : "r"(&owp->mtx), "r"(&((BH_PWORK*)pwp)->px), "r"(np.mxp[i][0]), "r"(owp) 
                );
                    
                njRotXYZ(np.mxp[i][0], -op->ang[0], -op->ang[1], -op->ang[2]); 
            }
        }
    } 
} 

// 99.93% matching
void npCalcSkinFM(void* pwp, int obj_n, int* sknp)
{ 
    NJS_POINT4* p0;
    NJS_CNK_OBJECT* op;
    float lv;
    float* p1;
    int i;
    int j;
    int flg;
    int rg0;
    int nb;
    HDR_PS* pHdr0;
    HDR_PS* pHdr1;
    static float level[10] = { 0.1000000015f, 0.200000003f, 0.3000000119f, 0.400000006f, 0.5f, 0.6000000238f, 0.6999999881f, 0.8000000119f, 0.8999999762f, 1.0f };

    if (sknp != NULL)
    { 
        njPushMatrixEx(); 

        npInitCalcSkinFM(pwp, obj_n, sknp); 
        
        np.sknp = sknp; 
        
        op = (NJS_CNK_OBJECT*)((O_WRK*)pwp)->mlwP->objP; 
        
        for (i = 0; i < obj_n; i++, op++) 
        { 
            if ((i < 11) || (i > 14))
            {
                flg = *np.sknp++; 
                
                if (flg != 0) 
                { 
                    if ((flg & 0x2)) 
                    { 
                        pHdr0 = (HDR_PS*)op->model->vlist;
                        
                        rg0 = *np.sknp++; 
                        
                        op->model->vlist = np.vlp[rg0]; 
                        
                        pHdr1 = (HDR_PS*)np.vlp[rg0]; 
                        
                        nb = *np.sknp++;
        
                        pHdr1 = (HDR_PS*)((int)pHdr1 | 0x30000000); 
        
                        pHdr1->ucType = pHdr0->ucType;
                        pHdr1->ucAttr = pHdr0->ucAttr; 
                        
                        pHdr1->usSize = pHdr0->usSize;
                        
                        pHdr1->usIndexOfs = pHdr0->usIndexOfs; 
                        pHdr1->usIndexMax = pHdr0->usIndexMax; 
                        
                        p0 = (NJS_POINT4*)(pHdr0 + 1); 
                        p1 = (float*)(pHdr1 + 1); 
        
                        for (j = 0; j < nb; j++) 
                        { 
                            rg0 = *np.sknp++; 
                            
                            lv = level[(rg0 >> 16) & 0xFF]; 
                            
                            rg0 >>= 24;

                            if (rg0 > 10)
                            {
                                rg0 += 4;
                            }
                            
                            if (lv != 1.0f) 
                            { 
                                asm volatile 
                                ("
                                .set noreorder
                                
                                    mfc1        t0, %0 
                                    
                                    qmtc2       t0, vf13
                                    
                                    lqc2        vf4, 0(%1)
                                    lqc2        vf5, 0(%3)
                                    lqc2        vf6, 0x10(%3)
                                    lqc2        vf7, 0x20(%3)
                                    lqc2        vf8, 0x30(%3)
                                    
                                    vmulax.xyz  ACC, vf5, vf4x
                                    
                                    vmadday.xyz ACC, vf6, vf4y
                                    vmaddaz.xyz ACC, vf7, vf4z
                                    
                                    vmaddw.xyz  vf9, vf8, vf0w
                                    
                                    lqc2        vf5, 0(%4)
                                    lqc2        vf6, 0x10(%4)
                                    lqc2        vf7, 0x20(%4)
                                    lqc2        vf8, 0x30(%4)
                                    
                                    vmulax.xyz  ACC, vf5, vf4x
                                    
                                    vmadday.xyz ACC, vf6, vf4y
                                    vmaddaz.xyz ACC, vf7, vf4z
                                    
                                    vmaddw.xyz  vf10, vf8, vf0w
                                    
                                    vsub.xyz    vf5, vf10, vf9
                                    
                                    vmulx.xyz   vf6, vf5, vf13x
                                    
                                    vadd.xyz    vf7, vf6, vf9
                                    
                                    sqc2        vf7, 0(%2) 
                                    
                                .set reorder
                                " : : "f"(lv), "r"(p0), "r"(p1), "r"(np.mxp[rg0][0]), "r"(np.mxp[rg0][1]) : "t0" 
                                );
                                
                                p1 += 4; 
                                p0++; 
                                
                                asm volatile 
                                ("
                                .set noreorder
                                                 
                                    mfc1        t0, %0 
                                    
                                    qmtc2       t0, vf13
                                    
                                    lqc2        vf4, 0(%1)
                                    lqc2        vf5, 0(%3)
                                    lqc2        vf6, 0x10(%3)
                                    lqc2        vf7, 0x20(%3)
                                    lqc2        vf8, 0(%4)
                                    lqc2        vf9, 0x10(%4)
                                    lqc2        vf10, 0x20(%4)
                                    
                                    vmulax.xyz  ACC, vf5, vf4x
                                    
                                    vmadday.xyz ACC, vf6, vf4y
                                    
                                    vmaddz.xyz  vf11, vf7, vf4z
                                    
                                    vmulax.xyz  ACC, vf8, vf4x
                                    
                                    vmadday.xyz ACC, vf9, vf4y
                                    
                                    vmaddz.xyz  vf12, vf10, vf4z
                                    
                                    vsub.xyz    vf5, vf12, vf11
                                    
                                    vmulx.xyz   vf6, vf5, vf13x
                                    
                                    vadd.xyz    vf7, vf6, vf11
                                    
                                    sqc2        vf7, 0(%2) 
                                    
                                .set reorder
                                " : : "f"(lv), "r"(p0),  "r"(p1), "r"(np.mxp[rg0][0]), "r"(np.mxp[rg0][1]) : "t0" 
                                );
                                
                                p1 += 4; 
                                p0++;
                            } 
                            else 
                            { 
                                asm volatile 
                                ("
                                .set noreorder
                                                  
                                    lqc2        vf4, 0(%0) 
                                    lqc2        vf11, 0x10(%0)
                                    lqc2        vf5, 0(%2)
                                    lqc2        vf6, 0x10(%2)
                                    lqc2        vf7, 0x20(%2)
                                    lqc2        vf8, 0x30(%2)
                                    
                                    vmulax.xyz  ACC, vf5xyz, vf4x
                                    
                                    vmadday.xyz ACC, vf6xyz, vf4y
                                    vmaddaz.xyz ACC, vf7xyz, vf4z
                                    
                                    vmaddw.xyz  vf9, vf8xyz, vf0w
                                    
                                    vmulax.xyz  ACC, vf5xyz, vf11x
                                    
                                    vmadday.xyz ACC, vf6xyz, vf11y
                                    
                                    vmaddz.xyz  vf10xyz, vf7xyz, vf11z
                                    
                                    sqc2        vf9, 0(%1)
                                    sqc2        vf10, 0x10(%1) 
                                    
                                .set reorder
                                " : : "r"(p0), "r"(p1), "r"(np.mxp[rg0][1]), "r"(op)
                                ); 
                                
                                p0 += 2; 
                                p1 += 8; 
                            }
                        } 
                        
                        *(int*)p1 = 255; 
                    } 
                    else 
                    { 
                        np.sknp++;
                    } 
                }
            }
        } 
    
        njPopMatrixEx(); 
    }
} 
