#include "light.h"
#include "ps2_NaMath.h"
#include "ps2_NaMatrix.h"
#include "ps2_NaView.h"
#include "ps2_NinjaCnk.h"
#include "main.h"

LGT_WORK lgttab[5] = 
{
    // lgttab[0]
    {
        0x00000001, // flg
        0x00000064, // type
        0,          // aspd
        1,          // lkflg
        0,          // lkno
        9,          // lkono
        4,          // lsrc
        0.0f,       // px
        0.0f,       // py
        0.0f,       // pz
        0.0f,       // lx
        0.0f,       // ly
        0.0f,       // lz
        0.0f,       // vx
        1.0f,       // vy
        0.0f,       // vz
        1.0f,       // spc
        1.0f,       // dif
        1.0f,       // amb
        6.0f,       // r
        6.0f,       // g
        6.0f,       // b
        5.0f,       // nr
        60.0f,      // fr
        0,          // iang
        0,          // oang
        0,          // ax
        0,          // ay
        0,          // az
    },
    // lgttab[1]
    {
        0x00000001, // flg
        0x00000004, // type
        30,         // aspd
        1,          // lkflg
        0,          // lkno
        9,          // lkono
        4,          // lsrc
        0.0f,       // px
        0.0f,       // py
        0.0f,       // pz
        0.3f,       // lx
        0.0f,       // ly
        -1.5f,      // lz
        0.0f,       // vx
        1.0f,       // vy
        0.0f,       // vz
        0.0f,       // spc
        0.0f,       // dif
        0.0f,       // amb
        3.16f,      // r
        2.06f,      // g
        0.7f,       // b
        8.0f,       // nr
        400.0f,     // fr
        0,          // iang
        0,          // oang
        0,          // ax
        0,          // ay
        0,          // az
    },
    // lgttab[2]
    {
        0x00000001, // flg
        0x00000000, // type
        0,          // aspd
        0,          // lkflg
        0,          // lkno
        0,          // lkono
        4,          // lsrc
        0.0f,       // px
        0.0f,       // py
        0.0f,       // pz
        0.0f,       // lx
        0.0f,       // ly
        0.0f,       // lz
        0.0f,       // vx
        0.0f,       // vy
        0.0f,       // vz
        0.0f,       // spc
        0.0f,       // dif
        0.0f,       // amb
        0.0f,       // r
        0.0f,       // g
        0.0f,       // b
        0.0f,       // nr
        0.0f,       // fr
        0,          // iang
        0,          // oang
        0,          // ax
        0,          // ay
        0,          // az
    },
    // lgttab[3]
    {
        0x00000001, // flg
        0x00000000, // type
        0,          // aspd
        0,          // lkflg
        0,          // lkno
        0,          // lkono
        4,          // lsrc
        0.0f,       // px
        0.0f,       // py
        0.0f,       // pz
        0.0f,       // lx
        0.0f,       // ly
        0.0f,       // lz
        0.0f,       // vx
        0.0f,       // vy
        0.0f,       // vz
        0.0f,       // spc
        0.0f,       // dif
        0.0f,       // amb
        0.0f,       // r
        0.0f,       // g
        0.0f,       // b
        0.0f,       // nr
        0.0f,       // fr
        0,          // iang
        0,          // oang
        0,          // ax
        0,          // ay
        0,          // az
    },
    // lgttab[4]
    {
        0x00000003, // flg
        0x00000000, // type
        0,          // aspd
        0,          // lkflg
        0,          // lkno
        0,          // lkono
        2,          // lsrc
        0.0f,       // px
        50.0f,      // py
        -16.0f,     // pz
        0.0f,       // lx
        0.0f,       // ly
        0.0f,       // lz
        0.0f,       // vx
        0.0f,       // vy
        0.0f,       // vz
        1.0f,       // spc
        1.0f,       // dif
        0.1f,       // amb
        1.0f,       // r
        1.0f,       // g
        1.0f,       // b
        0.0f,       // nr
        0.0f,       // fr
        0,          // iang
        0,          // oang
        -16384,     // ax
        0,          // ay
        0,          // az
    },
};

// 100% matching! 
void bhInitLight()
{
    LGT_WORK* lp;
    int i;

    lp = rom->lgtp;
    
    for (i = 0; i < rom->lgt_n; i++, lp++) 
    {
        if (i < 4)
        {
            lp->flg &= ~0x2;
        }
        
        lp->mode = 0;
        
        lp->ct0 = lp->ct1 = lp->ct2 = lp->ct3 = 0;
        
        lp->light = NULL;
    }
}

// 100% matching! 
void bhSetLightTab(LGT_WORK* lt, int lno) 
{ 
    LGT_WORK* lp;

    lp = &rom->lgtp[lno];

    lp->flg =  lt->flg;
    
    lp->type =  lt->type;
    
    lp->aspd =  lt->aspd;
    
    lp->lkflg =  lt->lkflg;
    
    lp->lkno = lt->lkno;
	lp->lkono = lt->lkono;
	
    lp->lsrc = lt->lsrc;
	
    lp->px = lt->px;
	lp->py = lt->py;
	lp->pz = lt->pz;
    
	lp->lx = lt->lx;
	lp->ly = lt->ly;
	lp->lz = lt->lz;
    
	lp->vx = lt->vx;
	lp->vy = lt->vy;
	lp->vz = lt->vz;
    
	lp->spc = lt->spc;
    
	lp->dif = lt->dif;
    
	lp->amb = lt->amb;
    
	lp->r = lt->r;
	lp->g = lt->g;
	lp->b = lt->b;
    
	lp->nr = lt->nr;
	lp->fr = lt->fr;
    
	lp->iang = lt->iang;
	lp->oang = lt-> oang;
    
	lp->ax = lt->ax;
	lp->ay = lt->ay;
	lp->az = lt->az;
    
    lp->mode = 0;
    
    lp->ct0 = lp->ct1 = lp->ct2 = lp->ct3 = 0;
    
    lp->wspc = lp->spc;
    
    lp->wdif = lp->dif;
    
    lp->wamb = lp->amb;
    
    lp->wr = lp->r;
    lp->wg = lp->g;
    lp->wb = lp->b;
    
    lp->wnr = lp->nr;
    lp->wfr = lp->fr;
    
    lp->wiang = lp->iang;
    lp->woang = lp->oang;
    
    lp->wax = lp->ax;
    lp->way = lp->ay;
    lp->waz = lp->az;
    
    lp->lkwkp =  NULL;
    
    lp->light = NULL;
    
    bhGetLightVector(lt->ax, lt->ay, lt->az, (NJS_VECTOR*)&lp->vx);
}

// 99.90% matching 
void bhSetEasyDirLight(float it) 
{
    LGT_WORK* lp;
    float fl;
    
    lp = rom->lgtp;
    
    fl = it;
    
    if ((lp->flg & 0x2))
    {
        switch (lp->type) 
        {                         
        case 100:
            switch (lp->mode) 
            {                   
            case 0:                                
                lp->mode++;
        
                fl *= 3.0f;
                break;
            case 1:                                 
                lp->flg &= ~0x2;
                break;
            }
            
            break;
        case 101:
            fl = njCos(lp->ct0);
            
            fl = 3.0f * fl;
            
            lp->ct0 += lp->aspd * 256;
            
            if (lp->ct0 > 16383)
            {
                lp->flg &= ~0x2;
            }
            
            break;
        }
    }
    
    njCnkSetEasyLightColor(1.0f, 1.0f, 1.0f);
    njCnkSetEasyLightIntensity(fl, 0.2f);
    njCnkSetEasyLight(0, 0.3f, 0.7f);
    
    njCnkSetSimpleLightColor(1.0f, 1.0f, 1.0f);
    njCnkSetSimpleLightIntensity(fl, 0.2f);
    njCnkSetSimpleLight(0, 0.3f, 0.7f);
}

// 99.25% matching
void bhControlLight()
{
    BH_PWORK* pwp;    
    LGT_WORK* lp;      
    LPTB* lptb;       
    CAM_KEYF_WORK* ci; 
    NJS_POINT3 vec;    
    float px, py, pz;  
    float vx, vy, vz;  
    float r, g, b;     
    float nr, fr;      
    int lgt_n;         
    int i;             
    int lct;           
    int dirf;          
    float fl;          
    NJS_POINT3 npos;   
    NJS_POINT2 lpos;   
    float clp;         
    
    if ((cam.flg & 0x2))
    {
        sys->lgtp = rom->evlp;
        
        sys->st_flg |= 0x1000000;
    } 
    else 
    {
        sys->lgtp = rom->lgtp;
        
        sys->st_flg &= ~0x1000000;
    }
    
    sys->lg_pnt = 0;
    
    if ((sys->gm_flg & 0x80)) 
    {
        bhSetEasyDirLight(1.0f);
        return; 
    }

    lptb = sys->lg_ptb;
    
    // this line matches on GC
    ci = (CAM_KEYF_WORK*)&rom->cutp[cam.ncut].cam[cam.camver];

    dirf = 0;
    
    lct = 2;
    
    if ((sys->st_flg & 0x1000000)) 
    {
        lgt_n = rom->evl_n + 4;
    }
    else 
    {
        lgt_n = rom->lgt_n;
    }
    
    for (i = 0; i < lgt_n; i++) 
    {
        if ((sys->st_flg & 0x1000000)) 
        {
            if (i < 4) 
            {
                lp = &rom->lgtp[i];
            } 
            else
            {
                lp = &rom->evlp[i - 4];
            }
        } 
        else 
        {
            lp = &rom->lgtp[i];
        }
        
        if (((lp->flg & 0x1)) && ((lp->flg & 0x2))) 
        {
            if ((sys->sp_flg & 0x80))
            {
                px = lp->px;
                py = lp->py;
                pz = lp->pz;
                
                vx = lp->vx;
                vy = lp->vy;
                vz = lp->vz;
                
                r = lp->r;
                g = lp->g;
                b = lp->b;
                
                nr = lp->nr;
                fr = lp->fr;
                
                switch (lp->type) 
                {
                case 0:
                    break;
                case 1:                       
                    fl = njSin(lp->ct0) * 0.25f;
                    
                    r = (fl * lp->r) + (lp->r * 0.75f);
                    g = (fl * lp->g) + (lp->g * 0.75f);
                    b = (fl * lp->b) + (lp->b * 0.75f);
                    
                    lp->ct0 = (lp->ct0 + (lp->aspd << 8)) & 0x7FFF;
                    break;
                case 2:                       
                    fl = njSin(lp->ct0) * 0.5f;
                    
                    r = (fl * lp->r) + (lp->r * 0.5f);
                    g = (fl * lp->g) + (lp->g * 0.5f);
                    b = (fl * lp->b) + (lp->b * 0.5f);
                    
                    lp->ct0 = (lp->ct0 + (lp->aspd << 8)) & 0x7FFF;
                    break;
                case 3:                       
                    fl = njSin(lp->ct0);
                    
                    r = fl * lp->r;
                    g = fl * lp->g;
                    b = fl * lp->b;
                    
                    lp->ct0 = (lp->ct0 + (lp->aspd << 8)) & 0x7FFF;
                    break;
                case 4:                       
                    fl = njSin(lp->ct0) * 0.25f;
                    
                    r = (fl * lp->r) + (lp->r * 0.75f);
                    g = (fl * lp->g) + (lp->g * 0.75f);
                    b = (fl * lp->b) + (lp->b * 0.75f);
                    
                    lp->ct0 = (lp->ct0 + (unsigned int)((lp->aspd << 8) * (-rand() / -2.1474836e9f))) & 0x7FFF;
                    break;
                case 5:                       
                    fl = njSin(lp->ct0) * 0.5f;
                    
                    r = (fl * lp->r) + (lp->r * 0.5f);
                    g = (fl * lp->g) + (lp->g * 0.5f);
                    b = (fl * lp->b) + (lp->b * 0.5f);
                    
                    lp->ct0 = (lp->ct0 + (unsigned int)((lp->aspd << 8) * (-rand() / -2.1474836e9f))) & 0x7FFF;
                    break;
                case 6:                       
                    fl = njSin(lp->ct0);
                    
                    r = fl * lp->r;
                    g = fl * lp->g;
                    b = fl * lp->b;
                    
                    lp->ct0 = (lp->ct0 + (unsigned int)((lp->aspd << 8) * (-rand() / -2.1474836e9f))) & 0x7FFF;
                    break;
                case 7:                       
                    fl = fabsf(njSin(sys->thunder << 6));
                    
                    r = fl;
                    g = fl;
                    b = fl;
                    break;
                case 8:                       
                    lp->way -= (int)(182.04445f * (0.5f * lp->aspd)) & 0xFFFF;
                    
                    bhGetLightVector(lp->wax, lp->way, lp->waz, &vec);
                    
                    vx = vec.x;
                    vy = vec.y;
                    vz = vec.z;
                    break;
                case 9:                       
                    lp->way += (int)(182.04445f * (0.5f * lp->aspd)) & 0xFFFF;
                    
                    bhGetLightVector(lp->wax, lp->way, lp->waz, &vec);
                    
                    vx = vec.x;
                    vy = vec.y; 
                    vz = vec.z;
                    break;
                case 10:                       
                    switch (lp->mode) 
                    {          
                    case 0:                     
                        lp->spc = r;
                        lp->dif = lp->g;
                        lp->amb = lp->b;
                        
                        lp->mode++;
                        break;
                    case 1:                     
                        lp->spc = r;
                        lp->dif = lp->g;
                        lp->amb = lp->b;
                        
                        if ((-rand() / -2.1474836e9f) <= ((float)lp->aspd * 0.01)) 
                        {
                            lp->ct0 = (int)(6.0f * (-rand() / -2.1474836e9f)) + 3;
                            
                            lp->mode++;
                        }
                        
                        break;
                    case 2:                     
                        lp->spc += 0.5f * ((0.333f * r) - lp->spc);
                        lp->dif += 0.5f * ((0.333f * lp->g) - lp->dif);
                        lp->amb += 0.5f * ((0.333f * lp->b) - lp->amb); 
                        
                        lp->ct0--;
                        
                        if (lp->ct0 <= 0) 
                        {
                            lp->spc = lp->r;
                            lp->dif = lp->g;
                            lp->amb = lp->b;
                            
                            lp->ct0 = (int)(6.0f * (-rand() / -2.1474836e9f)) + 3;
                            
                            lp->mode++;
                        }
                        
                        break;
                    case 3:                     
                        lp->spc += 0.5f * ((0.333f * r) - lp->spc);
                        lp->dif += 0.5f * ((0.333f * lp->g) - lp->dif);
                        lp->amb += 0.5f * ((0.333f * lp->b) - lp->amb);
                        
                        lp->ct0--;
                        
                        if (lp->ct0 <= 0)
                        {
                            lp->spc = lp->r;
                            lp->dif = lp->g;
                            lp->amb = lp->b;
                            
                            lp->mode = 1;
                        }
                        
                        break;
                    }
                    
                    r = lp->spc;
                    g = lp->dif;
                    b = lp->amb;
                    break;
                case 11:                       
                    switch (lp->mode)
                    {        
                    case 0:                     
                        lp->spc = r;
                        lp->dif = lp->g;
                        lp->amb = lp->b;
                        
                        lp->mode++;
                        break;
                    case 1:                     
                        lp->spc += 0.5f * ((0.333f * r) - lp->spc);
                        lp->dif += 0.5f * ((0.333f * lp->g) - lp->dif);
                        lp->amb += 0.5f * ((0.333f * lp->b) - lp->amb);
                        
                        if ((-rand() / -2.1474836e9f) <= ((float)lp->aspd * 0.01)) 
                        {
                            lp->spc = lp->r;
                            lp->dif = lp->g;
                            lp->amb = lp->b;
                            
                            lp->ct0 = (int)(6.0f * (-rand() / -2.1474836e9f)) + 3;
                            
                            lp->mode++;
                        }
                        
                        break;
                    case 2:                     
                        lp->spc += 0.5f * ((0.333f * r) - lp->spc);
                        lp->dif += 0.5f * ((0.333f * lp->g) - lp->dif);
                        lp->amb += 0.5f * ((0.333f * lp->b) - lp->amb);
                        
                        lp->ct0--;
                        
                        if (lp->ct0 <= 0) 
                        {
                            lp->spc = lp->r;
                            lp->dif = lp->g;
                            lp->amb = lp->b;
                            
                            lp->mode = 1;
                        }
                        
                        break;
                    }
                    
                    r = lp->spc;
                    g = lp->dif;
                    b = lp->amb;
                    break;
                case 12:                       
                    switch (lp->mode) 
                    {        
                    case 0:                     
                        lp->ct0--;
                        
                        if (lp->ct0 <= 0)
                        {
                            lp->ct0 = (int)(lp->aspd * (-rand() / -2.1474836e9f)) + 1;
                            
                            lp->mode++;
                        }
                        
                        break;
                    case 1:                     
                        r = r * 0.5f;
                        g = g * 0.5f;
                        b = b * 0.5f; 
                        
                        lp->ct0--;
                        
                        if (lp->ct0 <= 0)
                        {
                            lp->ct0 = (int)(lp->aspd * (-rand() / -2.1474836e9f)) + 1;
                            
                            lp->mode = 0;
                        }
                        
                        break;
                    }
                    
                    break;
                case 13:                       
                    fl = njCos(lp->ct0);
                    
                    r = fl * lp->r;
                    g = fl * lp->g;
                    b = fl * lp->b;
                    
                    lp->ct0 += lp->aspd << 8;
                    
                    if (lp->ct0 > 16383) 
                    {
                        lp->flg &= ~0x1;
                    }
                    
                    break;
                case 100:                      
                    switch (lp->mode) 
                    {        
                    case 0:                     
                        lp->mode++;
                        break;
                    case 1:                     
                        lp->flg &= ~0x2;
                        break;
                    }
                    
                    break;
                case 101:                      
                    fl = njCos(lp->ct0);
                    
                    r = fl * lp->r;
                    g = fl * lp->g;
                    b = fl * lp->b;
                    
                    lp->ct0 += lp->aspd << 8;
                    
                    if (lp->ct0 > 16383)
                    {
                        lp->flg &= ~0x2;
                    }
                    
                    break;
                }
            } 
            else 
            {
                px = lp->wpx;
                py = lp->wpy;
                pz = lp->wpz;
                
                vx = lp->wvx;
                vy = lp->wvy;
                vz = lp->wvz;
                
                r = lp->wr;
                g = lp->wg;
                b = lp->wb;
                
                nr = lp->wnr;
                fr = lp->wfr;
            }
            
            switch (lp->lkflg) 
            {                
            case 0: 
                break;
            case 1:                             
                pwp = plp;
                break;
            case 2:                             
                pwp = &ene[rom->enep[lp->lkno].wrk_no];
                break;
            case 3:                             
                pwp = (BH_PWORK*)&sys->obwp[lp->lkno];
                break;
            case 4:                             
                pwp = (BH_PWORK*)&sys->itwp[lp->lkno];
                break;
            case 5:                             
                pwp = (BH_PWORK*)&eff[sys->efid[lp->lkno]];
                break;
            default:                            
                lp->lkflg = 0;
                lp->lkno = 0;
                break;
            }
            
            if (lp->lkflg != 0) 
            {
                if (!(pwp->flg & 0x1)) 
                {
                    lp->flg &= ~0x3;
                }
                else 
                {
                    if (lp->lkono == 0) 
                    {
                        njCalcPoint(pwp->mtx, (NJS_POINT3*)&lp->lx, (NJS_POINT3*)&lp->px);
                    } 
                    else 
                    {
                        njCalcPoint(&pwp->mlwP->owP[lp->lkono].mtx, (NJS_POINT3*)&lp->lx, (NJS_POINT3*)&lp->px);
                    }
                    
                    px = lp->px;
                    py = lp->py;
                    pz = lp->pz;
                    goto label;
                }
            }
            else 
            {
label:
                switch (lp->lsrc) 
                {            
                case 2:                         
                    if (dirf == 0) 
                    {
                        dirf = 1;
                        
                        sys->lg_vx = vx;
                        sys->lg_vy = vy;
                        sys->lg_vz = vz;
                        
                        sys->lg_r = r;
                        sys->lg_g = g;
                        sys->lg_b = b;
                    }
                    
                    break;
                case 4:                         
                    if (lct < 5) 
                    {
                        if (!(sys->st_flg & 0x1000000))
                        {
                            if ((ci->flg & 0x10)) 
                            {
                                npos.x = px;
                                npos.y = py;
                                npos.z = pz;
                               
                                clp = 2.0f * (unsigned char)ci->frame;
                                
                                njProjectScreen(cam.mtx, &npos, &lpos);
                                
                                if (!((lpos.x >= ((-clp + fNaViwOffsetX) - 320.0f)) && (lpos.x <= (((640.0f + clp) + fNaViwOffsetX) - 320.0f)) && (lpos.y >= ((-clp + fNaViwOffsetY) - 240.0f)) && (lpos.y <= (((480.0f + clp) + fNaViwOffsetY) - 240.0f))))
                                {
                                    break;
                                }
                            } 
                        } 
                        
                        njCnkSetEasyMultiLightPoint(lct, px, py, pz);
                        njCnkSetEasyMultiLightRange(lct, nr, fr);
                        njCnkSetEasyMultiLightColor(lct, r, g, b);
                        njCnkSetEasyMultiLightSwitch(lct, 1);
                        
                        njCnkSetSimpleMultiLightPoint(lct, px, py, pz);
                        njCnkSetSimpleMultiLightRange(lct, nr, fr);
                        njCnkSetSimpleMultiLightColor(lct, r, g, b);
                        njCnkSetSimpleMultiLightSwitch(lct, 1);
                        
                        lptb->ps.x = px;
                        lptb->ps.y = py;
                        lptb->ps.z = pz;
                        
                        lptb->nr = nr;
                        lptb->fr = fr;
                        
                        lptb->cr = r;
                        lptb->cg = g;
                        lptb->cb = b;
                        
                        lptb++;
                        lct++;
                        sys->lg_pnt++;
                    }
                    
                    break;
                }
                
                if ((sys->sp_flg & 0x80)) 
                {
                    lp->wpx = px;
                    lp->wpy = py;
                    lp->wpz = pz;
                    
                    lp->wvx = vx;
                    lp->wvy = vy;
                    lp->wvz = vz;
                    
                    lp->wr = r;
                    lp->wg = g;
                    lp->wb = b;
                    
                    lp->wnr = nr;
                    lp->wfr = fr;
                }
            }
        }
    } 
    
    njSetMatrix(NULL, cam.mtx);
    
    if (dirf == 0) 
    {
        sys->st_flg &= ~0x10000; 
        
        njCnkSetEasyMultiLightColor(1, 0, 0, 0);
        njCnkSetEasyMultiLightSwitch(1, 0);
        
        njCnkSetSimpleMultiLightColor(1, 0, 0, 0);
        njCnkSetSimpleMultiLightSwitch(1, 0);
        
        njCnkSetEasyLightColor(0, 0, 0);
        njCnkSetEasyLightIntensity(0, 0);
        njCnkSetEasyLight(0, 0, 1.0f);
        
        njCnkSetSimpleLightColor(0, 0, 0);
        njCnkSetSimpleLightIntensity(0, 0);
        njCnkSetSimpleLight(0, 0, 1.0f);
        
        sys->lg_vx = 0;
        sys->lg_vy = 0;
        sys->lg_vz = 0;
        
        sys->lg_r = 0;
        sys->lg_g = 0;
        sys->lg_b = 0;
    } 
    else 
    {
        sys->st_flg |= 0x10000;
        
        njCnkSetEasyMultiLightColor(1, sys->lg_r, sys->lg_g, sys->lg_b);
        njCnkSetEasyMultiLightVector(sys->lg_vx, sys->lg_vy, sys->lg_vz);
        njCnkSetEasyMultiLightSwitch(1, 1);
        
        njCnkSetSimpleMultiLightColor(1, sys->lg_r, sys->lg_g, sys->lg_b);
        njCnkSetSimpleMultiLightVector(sys->lg_vx, sys->lg_vy, sys->lg_vz);
        njCnkSetSimpleMultiLightSwitch(1, 1);
        
        njCalcVector(cam.mtx, (NJS_POINT3*)&sys->lg_vx, &vec);
        
        njCnkSetEasyLightColor(sys->lg_r, sys->lg_g, sys->lg_b);
        njCnkSetEasyLightIntensity(1.0f, 0);
        njCnkSetEasyLight(vec.x, vec.y, vec.z);
        
        njCnkSetSimpleLightColor(sys->lg_r, sys->lg_g, sys->lg_b);
        njCnkSetSimpleLightIntensity(1.0f, 0);
        njCnkSetSimpleLight(vec.x, vec.y, vec.z); 
    }
    
    if (lct < 5)
    {
        for (i = lct; i <= 4; i++) 
        {
            njCnkSetEasyMultiLightSwitch(i, 0);
            njCnkSetSimpleMultiLightSwitch(i, 0);
        }  
    }
    
    njCnkSetEasyMultiLight(lct - 1);
    njCnkSetEasyMultiLightMatrices();
    
    njCnkSetSimpleMultiLight(lct - 1);
    njCnkSetSimpleMultiLightMatrices();
}

// 99.72% matching 
void bhSetLight()
{
    LPTB* lptb;
    NJS_VECTOR vec;
    int i;

    if ((sys->gm_flg & 0x80)) 
    {
        bhSetEasyDirLight(1.0f);
        return;
    }
    
    if (!(sys->st_flg & 0x10000)) 
    {
        njCnkSetEasyMultiLightColor(1, 0, 0, 0);
        njCnkSetEasyMultiLightSwitch(1, 0);
        
        njCnkSetSimpleMultiLightColor(1, 0, 0, 0);
        njCnkSetSimpleMultiLightSwitch(1, 0);
        
        njCnkSetEasyLightColor(0, 0, 0);
        njCnkSetEasyLightIntensity(0, 0);
        njCnkSetEasyLight(0, 0, 1.0f);
        
        njCnkSetSimpleLightColor(0, 0, 0);
        njCnkSetSimpleLightIntensity(0, 0);
        njCnkSetSimpleLight(0, 0, 1.0f);
    } 
    else
    {
        njCnkSetEasyMultiLightColor(1, sys->lg_r, sys->lg_g, sys->lg_b);
        njCnkSetEasyMultiLightVector(sys->lg_vx, sys->lg_vy, sys->lg_vz);
        njCnkSetEasyMultiLightSwitch(1, 1);
        
        njCnkSetSimpleMultiLightColor(1, sys->lg_r, sys->lg_g, sys->lg_b);
        njCnkSetSimpleMultiLightVector(sys->lg_vx, sys->lg_vy, sys->lg_vz);
        njCnkSetSimpleMultiLightSwitch(1, 1);
        
        njCalcVector(cam.mtx, (NJS_VECTOR*)&sys->lg_vx, &vec);
        
        njCnkSetEasyLightColor(sys->lg_r, sys->lg_g, sys->lg_b);
        njCnkSetEasyLightIntensity(1.0f, 0);
        njCnkSetEasyLight(vec.x, vec.y, vec.z);
        
        njCnkSetSimpleLightColor(sys->lg_r, sys->lg_g, sys->lg_b);
        njCnkSetSimpleLightIntensity(1.0f, 0);
        njCnkSetSimpleLight(vec.x, vec.y, vec.z);
    }

    lptb = sys->lg_ptb;
    
    for (i = 0; i < sys->lg_pnt; i++, lptb++) 
    {
        njCnkSetEasyMultiLightColor(i + 2, lptb->cr, lptb->cg, lptb->cb);
        njCnkSetSimpleMultiLightColor(i + 2, lptb->cr, lptb->cg, lptb->cb);
    }
    
    njSetMatrix(NULL, cam.mtx);
    
    njCnkSetEasyMultiLightMatrices();
    njCnkSetSimpleMultiLightMatrices();
}

// 98.87% matching
void bhSetHalfLight()
{
    LPTB* lptb;
    NJS_VECTOR vec;
    float r;
    float g;
    float b;
    int i;

    if ((sys->gm_flg & 0x80)) 
    {
        bhSetEasyDirLight(0.6f);
        return;
    }

    if (!(sys->st_flg & 0x10000)) 
    {
        njCnkSetEasyMultiLightColor(1, 0, 0, 0);
        njCnkSetEasyMultiLightSwitch(1, 0);
        
        njCnkSetSimpleMultiLightColor(1, 0, 0, 0);
        njCnkSetSimpleMultiLightSwitch(1, 0);
        
        njCnkSetEasyLightColor(0, 0, 0);
        njCnkSetEasyLightIntensity(0, 0);
        njCnkSetEasyLight(0, 0, 1.0f);
        
        njCnkSetSimpleLightColor(0, 0, 0);
        njCnkSetSimpleLightIntensity(0, 0);
        njCnkSetSimpleLight(0, 0, 1.0f);
    }
    else
    {
        r = 0.5f * sys->lg_r;
        g = 0.5f * sys->lg_g;
        b = 0.5f * sys->lg_b;
        
        njCnkSetEasyMultiLightColor(1, r, g, b);
        njCnkSetEasyMultiLightVector(sys->lg_vx, sys->lg_vy, sys->lg_vz);
        njCnkSetEasyMultiLightSwitch(1, 1);
        
        njCnkSetSimpleMultiLightColor(1, r, g, b);
        njCnkSetSimpleMultiLightVector(sys->lg_vx, sys->lg_vy, sys->lg_vz);
        njCnkSetSimpleMultiLightSwitch(1, 1);
        
        njCalcVector(cam.mtx, (NJS_VECTOR*)&sys->lg_vx, &vec);
        
        njCnkSetEasyLightColor(r, g, b);
        njCnkSetEasyLightIntensity(1.0f,  0);
        njCnkSetEasyLight(vec.x, vec.y, vec.z);
        
        njCnkSetSimpleLightColor(r, g, b);
        njCnkSetSimpleLightIntensity(1.0f, 0);
        njCnkSetSimpleLight(vec.x, vec.y, vec.z);
    }

    lptb = sys->lg_ptb;
    
    for (i = 0; i < sys->lg_pnt; i++, lptb++) 
    {
        r = 0.5f * lptb->cr;
        g = 0.5f * lptb->cg;
        b = 0.5f * lptb->cb;
        
        njCnkSetEasyMultiLightColor(i + 2, r, g, b);
        njCnkSetSimpleMultiLightColor(i + 2, r, g, b);
    }

    njSetMatrix(NULL, cam.mtx);
    
    njCnkSetEasyMultiLightMatrices();
    njCnkSetSimpleMultiLightMatrices();
}

// 100% matching! 
void bhGetLightVector(int xr, int yr, int zr, NJS_VECTOR* vec) 
{
    NJS_VECTOR pos = { 0, 0, -1.0f };
    
    njUnitMatrix(NULL);
    
    njRotateZ(NULL, zr);
    njRotateY(NULL, yr);
    njRotateX(NULL, xr);
    
    njCalcPoint(NULL, &pos, vec);
}
