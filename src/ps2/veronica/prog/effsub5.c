#include "../../../ps2/veronica/prog/effsub5.h"
#include "../../../ps2/veronica/prog/effsub2.h"
#include "../../../ps2/veronica/prog/effsub6.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"

#pragma divbyzerocheck on 

// 100% matching!
void bhEff200(O_WRK* op) 
{
    EFF5UV* pInfo;
	static EFF5UV Eff200UvInfo[8] = 
	{
		{   0,   0 }, {  32,   0 }, {  64,   0 }, {  96,   0 },
		{ 128,   0 }, { 160,   0 }, { 192,   0 }, { 224,   0 }
	};
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0)
    {                       
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 58;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = 8.0f * (-rand() / -2.1474836E9f);
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = 0xC0FFFFFF;
        
        op->mode0 = 1;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 8) 
        {
            op->ct0 = 0;
        }
        
        break;
    }
    
    op->az = op->ax;
    
    pInfo = &Eff200UvInfo[op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 31) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 31) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff201(O_WRK* op)
{
    EFF5UV* pInfo;
	static EFF5UV Eff201UvInfo[16] = 
	{
		{   0,   0 }, {  64,   0 }, { 128,   0 }, { 192,   0 },
		{   0,  64 }, {  64,  64 }, { 128,  64 }, { 192,  64 },
		{   0, 128 }, {  64, 128 }, { 128, 128 }, { 192, 128 },
		{   0, 192 }, {  64, 192 }, { 128, 192 }, { 192, 192 }
	};
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0)
    {                       
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 59;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = 16.0f * (-rand() / -2.1474836E9f);
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 16) 
        {
            op->ct0 = 0;
        }
        
        break;
    }
    
    pInfo = &Eff201UvInfo[op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 63) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 63) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff202(O_WRK* op) 
{
    EF_WORK* pEffect;  
    NJS_POINT3 Offset; 
    int lNumber;      
    unsigned short usType[4] = 
	{ 
		1, 2, 1, 2 
	};                

    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type != 0) 
    {
        op->flg |= 0x1000000;
        
        if (op->sz <= 0) 
        {
            op->sz = 0.1f;
        }
        
        op->type = ((op->type - 1) % 4) + 1;
        
        switch (op->mode0) 
        {                        
        case 0:                                     
            op->ct0 = 0;
            op->ct1 = 0;
            op->ct2 = 0;
            
            op->mode0 = 1;
        case 1:                                     
            op->spd = (2.5f * njSin(op->ct1)) + (6.0f * njSin(op->ct2));
            
            op->ct1 = (unsigned short)(op->ct1 + 1024);
            op->ct2 = (unsigned short)(op->ct2 + 64);
            op->ct0++;
            
            if (op->ct0 >= op->lkono) 
            {
                op->ct0 = 0;
                
                pEffect = &sys->ef;
                
                pEffect->flg = 1;
                
                pEffect->id = 203;
                
                pEffect->type = usType[op->type - 1];
                
                pEffect->flr_no = 0;
                
                pEffect->mdlver = (unsigned int)(4.0f * (-rand() / -2.1474836E9f)) & 0xFF;
                
                pEffect->sx = op->sx + ((op->sx * (-rand() / -2.1474836E9f)) / 4.0f);
                pEffect->sy = op->sx + ((op->sx * (-rand() / -2.1474836E9f)) / 4.0f);
                pEffect->sz = op->sz                                         / 10.0f;
                
                if ((int)(2.0f * (-rand() / -2.1474836E9f)) != 0) 
                {
                    pEffect->sx *= -1.0f;
                }
                
                if ((int)(2.0f * (-rand() / -2.1474836E9f)) != 0) 
                {
                    pEffect->sy *= -1.0f;
                }
                
                switch (op->type)
                {              
                case 1:                             
                    op->ax = 0;
                    op->ay = 16384;
                case 3:                             
                    pEffect->ax = (int)(7281.0f * (-rand() / -2.1474836E9f)) - 3640;
                    pEffect->ay = (int)(7281.0f * (-rand() / -2.1474836E9f)) - 3640;
                    break;
                case 2:                             
                case 4:                             
                    pEffect->ay = op->ay;
                    pEffect->ax = op->ax;
                    break;
                }
                
                switch (op->type) 
                {               
                case 1:                             
                case 2:                             
                case 3:                             
                    Offset.x = Offset.z = 0;
                    
                    if (op->type == 1) 
                    {
                        Offset.y = 300.0f;
                    } 
                    else if (op->type == 2) 
                    {
                        Offset.y = 250.0f * (-rand() / -2.1474836E9f);
                    }
                    else 
                    {
                        Offset.y = 10.0f * op->sy;
                    }
                    
                    njPushMatrixEx();
                    
                    njUnitMatrix(NULL);
                    
                    njRotateY(NULL, op->ay);
                    njRotateX(NULL, op->ax);
                    njRotateZ(NULL, 65535.0f * (-rand() / -2.1474836E9f));
                    
                    njCalcPoint(NULL, &Offset, &Offset);
                    
                    njPopMatrixEx();
                    
                    pEffect->px = op->px + Offset.x;
                    pEffect->py = op->py + Offset.y;
                    pEffect->pz = op->pz + Offset.z;
                    break;
                case 4:                             
                    pEffect->px = op->px;
                    pEffect->py = op->py;
                    pEffect->pz = op->pz;
                    break;
                }
                
                lNumber = bhSetEffectTb(pEffect, NULL, NULL, 0);
                
                if (lNumber != -1) 
                {
                    eff[lNumber].exp0 = (unsigned char*)op;
                }
            }
            
            break;
        }
    }
}

// 99.80% matching (matches on NGC)
void bhEff203(O_WRK* op)
{
    EFF5UV* pInfo;
    NJS_POINT3 Vector;
    O_WRK* opp;
	static EFF5UV Eff203UvInfo[4] = 
	{
		{   0,   0 }, { 128,   0 }, {   0, 128 }, { 128, 128 }
	};
    
    opp = (O_WRK*)op->exp0;
    
    if ((opp->stflg & 0x1000000)) 
    {
        op->flg = 0;
        return; 
    }
    
    switch (op->type) 
    {                              
    case 1:                                         
        switch (op->mode0) 
        {                          
        case 0:                                     
            op->flg |= 0x4180000;
            
            op->tex_id = 60;
            
            op->ani_ct = 0;
            
            op->bl_src = 8;
            op->bl_dst = 3;
            
            op->ct0 = 0;
            op->ct1 = 60.0f / op->sz;
            
            if (op->ct1 < 0) 
            {
                op->ct1 = 1;
            }
            
            pInfo = &Eff203UvInfo[op->mdlver];
            
            op->tv[0].u = op->tv[2].u = pInfo->u         / 256.0f;
            op->tv[1].u = op->tv[3].u = (pInfo->u + 127) / 256.0f;
            
            op->tv[0].v = op->tv[1].v = pInfo->v         / 256.0f;
            op->tv[2].v = op->tv[3].v = (pInfo->v + 127) / 256.0f;
            
            op->mode0 = 1;
            break;
        case 1:                                     
            op->ct0++;
            
            if (op->ct1 <= op->ct0) 
            {
                op->flg = 0;
                return;
            }
            
            Vector.x = 0;
            Vector.y = 0;
            Vector.z = 35.533333f * op->sz;
            
            njPushMatrixEx();
            
            njUnitMatrix(NULL);
            
            njRotateY(NULL, opp->ay);
            njRotateX(NULL, opp->ax);
            
            njRotateY(NULL, op->ay);
            njRotateX(NULL, op->ax);
            
            njCalcPoint(NULL, &Vector, &Vector);
            
            njPopMatrixEx();
            
            op->px += Vector.x;
            op->py += Vector.y;
            op->pz += Vector.z;
            
            op->py += ((O_WRK*)op->exp0)->spd * op->sz;
            
            op->ax = (short)((op->ax * (int)(100.0 - (5.0 * op->sz))) / 100);
            op->ay = (short)((op->ay * (int)(100.0 - (5.0 * op->sz))) / 100);
            
            op->sx *= 1.0f - (0.01f * op->sz);
            op->sy *= 1.0f - (0.01f * op->sz);
            break;
        }
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = ((0xFF - ((op->ct0 * 0xFF) / op->ct1)) << 24) | 0xFFFFFF;
        break; 
    case 2:                                         
        switch (op->mode0) 
        {                        
        case 0:
            op->flg |= 0x4180000;
            
            op->tex_id = 60;
            
            op->ani_ct = 0;
            
            op->bl_src = 8;
            op->bl_dst = 3;
            
            op->ct0 = 0;
            op->ct1 = 30.0f / op->sz;
            
            if (op->ct1 < 0) 
            {
                op->ct1 = 1;
            }
            
            op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
            
            pInfo = &Eff203UvInfo[op->mdlver];
            
            op->tv[0].u = op->tv[2].u = pInfo->u         / 256.0f;
            op->tv[1].u = op->tv[3].u = (pInfo->u + 127) / 256.0f;
            
            op->tv[0].v = op->tv[1].v = pInfo->v         / 256.0f;
            op->tv[2].v = op->tv[3].v = (pInfo->v + 127) / 256.0f;
            
            Vector.x = 0;
            Vector.y = 0;
            Vector.z = 35.533333f * op->sz; 
            
            njPushMatrixEx();
            
            njUnitMatrix(NULL);
            
            njRotateY(NULL, op->ay);
            njRotateX(NULL, op->ax);
            
            njCalcPoint(NULL, &Vector, (NJS_POINT3*)&op->xn);
            
            njPopMatrixEx();
            
            op->mode0 = 1;
            break;
        case 1:                                    
            op->ct0++;
            
            if (op->ct1 <= op->ct0)
            {
                op->flg = 0;
                return;
            }
            
            op->px += op->xn;
            op->py += op->yn;
            op->pz += op->zn;
            break;
        }
        
        break;
    }

    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff204(O_WRK* op)
{
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0) 
    {
    case 0:
        op->flg |= 0x4080000;
        
        op->tex_id = 449;
        
        sys->ef_tn[op->tex_id] = 7;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = 0xFF000000;
        
        op->tv[0].u = op->tv[2].u = 0;
        op->tv[1].u = op->tv[3].u = 0.99609375f;
            
        op->tv[0].v = op->tv[1].v = 0;
        op->tv[2].v = op->tv[3].v = 0.99609375f;
        
        op->mode0 = 1;
        break;
    }
    
    if (sys->ef_opqn < 512) 
    {
        sys->ef_opq[sys->ef_opqn] = op;
        
        sys->ef_opqn++;
    }
}

// 99.12% matching (matches on NGC)
void bhEff205(O_WRK* op) 
{
    EFF5UV* pInfo;
	static EFF5UV Eff205UvInfo1[14] = 
	{
		{   0,   0 }, {  80,   0 }, { 160,   0 }, {   0,  32 }, 
		{  80,  32 }, { 160,  32 }, {   0,  64 }, {  80,  64 }, 
		{ 160,  64 }, {   0,  96 }, {  80,  96 }, { 160,  96 },
		{   0, 128 }, {  80, 128 }
	};
	static EFF5UV Eff205UvInfo2[2] = 
	{
		{ 160, 128 }, {   0, 160 }
	};
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        
        op->mode0 = 0;
        return;
    }
    
    op->flg &= ~0x1000000;

    switch (op->mode0)
    {                       
    case 0:
        op->flg |= 0x4080000;
        
        op->tex_id = 61;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;

        op->ct0 = 0;
        op->ct1 = 0;

        op->mode0 = 1;
    case 1:
        pInfo = &Eff205UvInfo1[op->ct0];
        
        op->ct1++;
        
        if ((int)op->sz <= op->ct1) 
        {
            op->ct0++;
            
            if (op->ct0 >= 14) 
            {
                op->ct0   = 0;
                op->mode0 = 2;
            }
            
            op->ct1 = 0;
        }
        
        break;
    case 2:
        pInfo = &Eff205UvInfo2[op->ct0];
        
        op->ct0++;
        
        if (op->ct0 >= 2) 
        {
            op->ct0 = 0;
        }
        
        break;
    }
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 79) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 31) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff206(O_WRK* op) 
{
    EF_WORK* pEffect;
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0) 
    {                          
    case 0:
        op->ct0   = 0;
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 6) 
        {
            pEffect = &sys->ef;
            
            pEffect->flg = 1;
            
            pEffect->id = 207;
            
            pEffect->type = op->type - 1;
            
            pEffect->flr_no = 0;
            
            pEffect->mdlver = 0;
            
            pEffect->px = op->px;
            pEffect->py = op->py;
            pEffect->pz = op->pz;
            
            pEffect->sx = op->sx;
            pEffect->sy = op->sy;
            pEffect->sz = op->sz;
            
            pEffect->ay = op->ay;
            pEffect->ax = op->ax;
            
            bhSetEffectTb(pEffect, NULL, NULL, 0xFF);
            
            op->ct0 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEff207(O_WRK* op) 
{
    EFF5UV* pInfo;
	static EFF5UV Eff207UvInfo[24] = 
	{
		{   0,   0 }, {  48,   0 }, {  96,   0 }, { 144,   0 }, 
		{ 192,   0 }, {   0,  48 }, {  48,  48 }, {  96,  48 }, 
		{ 144,  48 }, { 192,  48 }, {   0,  96 }, {  48,  96 }, 
		{  96,  96 }, { 144,  96 }, { 192,  96 }, {   0, 144 }, 
		{  48, 144 }, {  96, 144 }, { 144, 144 }, { 192, 144 },
		{   0, 192 }, {  48, 192 }, {  96, 192 }, { 144, 192 }
	};
    
    switch (op->mode0) 
    {                             
    case 0:
        if (((op->type / 2) % 2) != 0) 
        {
            op->flg |= 0x4080000;
        } 
        else
        {
            op->flg |= 0x4180000;
        }
        
        op->tex_id = 62;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = 0;
        
        op->xn = 0;
        op->yn = op->sz / 10.0f;
        op->zn = 0;
        
        njPushMatrixEx();
        
        njUnitMatrix(NULL);
        
        if ((op->type % 2) != 0)
        {
            njRotateY(NULL, op->ay + ((((short)(1024.0f * (-rand() / -2.1474836E9f)))) - 512));
            njRotateX(NULL, op->ax + ((((short)(1024.0f * (-rand() / -2.1474836E9f)))) - 512));
        } 
        else 
        {
            njRotateY(NULL, op->ay + ((((short)(3072.0f * (-rand() / -2.1474836E9f)))) - 1536));
            njRotateX(NULL, op->ax + ((((short)(3072.0f * (-rand() / -2.1474836E9f)))) - 1536));
        }
        
        njCalcPoint(NULL, (NJS_POINT3*)&op->xn, (NJS_POINT3*)&op->xn);
        
        njPopMatrixEx();
        
        if (((op->type / 2) % 2) != 0)
        {
            op->ax = 0;
        }
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 24) 
        {
            op->flg = 0;
            return;
        }
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        if ((op->type % 2) != 0)
        {
            op->yn -= op->sz / 160.0f;
            
            op->xn *= 0.95f;
            op->zn *= 0.95f;
        } 
        else 
        {
            op->yn -= 0.0326f;
            op->yn *= 0.95f;
        }
        
        break;
    }

    pInfo = &Eff207UvInfo[op->ct0];
    
    op->tv[0].u = pInfo->u        / 256.0f;
    op->tv[1].u = (pInfo->u + 47) / 256.0f;
    op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[3].u = (pInfo->u + 47) / 256.0f;
    
    if ((op->type % 2) != 0) 
    {
        op->tv[0].v = (pInfo->v + 47) / 256.0f;
        op->tv[1].v = (pInfo->v + 47) / 256.0f;
        op->tv[2].v = pInfo->v        / 256.0f;
        op->tv[3].v = pInfo->v        / 256.0f;
    } 
    else
    {
        op->tv[0].v = pInfo->v        / 256.0f;
        op->tv[1].v = pInfo->v        / 256.0f;
        op->tv[2].v = (pInfo->v + 47) / 256.0f;
        op->tv[3].v = (pInfo->v + 47) / 256.0f;
    }
    
    if (sys->ef_trsn < 512)
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff208(O_WRK* op) 
{
    EF_WORK* pEffect;
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0) 
    {                          
    case 0:
        op->ct0   = 0;
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 6) 
        {
            pEffect = &sys->ef;
            
            pEffect->flg = 1;
            
            pEffect->id = 209;
            
            pEffect->type = 0;
            
            pEffect->flr_no = 0;
            
            pEffect->mdlver = 0;
            
            pEffect->px = op->px;
            pEffect->py = op->py;
            pEffect->pz = op->pz;
            
            pEffect->sx = op->sx;
            pEffect->sy = op->sy;
            pEffect->sz = op->sz;
            
            pEffect->ay = op->ay;
            pEffect->ax = op->ax;
            
            bhSetEffectTb(pEffect, NULL, NULL, 0xFF);
            
            op->ct0 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEff209(O_WRK* op) 
{
    EFF5UVWH* pInfo;
	static EFF5UVWH Eff209UvInfo[21] = 
	{
		{   0,   0,  16,  16 },
		{  16,   0,  16,  16 },
		{  32,   0,  24,  24 },
		{   0,  16,  32,  32 },
		{   0,  48,  32,  32 },
		{   0,  80,  32,  32 },
		{   0, 112,  32,  32 },
		{  32,  24,  40,  40 },
		{  32,  64,  40,  40 },
		{  72,   0,  48,  48 },
		{ 120,   0,  48,  48 },
		{  72,  48,  56,  56 },
		{ 128,  48,  56,  56 },
		{ 192,   0,  64,  64 },
		{ 192,  64,  64,  64 },
		{ 192, 128,  64,  64 },
		{ 192, 192,  64,  64 },
		{  48, 112,  72,  72 },
		{ 120, 112,  72,  72 },
		{  48, 184,  72,  72 },
		{ 120, 184,  72,  72 }
	};

    switch (op->mode0) 
    {                           
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 63;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = 0;
        
        op->xn = 0;
        op->yn = -1.6f;
        op->zn = 0;
        
        njPushMatrixEx();
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, op->ay);
        njRotateX(NULL, op->ax);
        
        njCalcPoint(NULL, (NJS_POINT3*)&op->xn, (NJS_POINT3*)&op->xn);
        
        njPopMatrixEx();
        
        op->az = (short)((65536.0f * op->sz) / 360.0f);
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 21) 
        {
            op->flg = 0;
            return;
        }
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->yn -= 0.0326f;
        
        op->xn *= 0.95f;
        op->yn *= 0.95f;
        op->zn *= 0.95f;
        break;
    }

    pInfo = &Eff209UvInfo[op->ct0];

    op->tv[0].u = op->tv[2].u = pInfo->u              / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + pInfo->w) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v              / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + pInfo->h) / 256.0f;

    if (sys->ef_trsn < 512)
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 99.50% matching (matches on NGC)
void bhEff210(O_WRK* op)
{
	EFF5UV* pInfo;
	static EFF5UV Eff210UvInfo[20] = 
	{
		{ 0,     0 }, { 64,    0 }, { 128,   0 }, { 192,   0 },
		{ 0,    48 }, { 64,   48 }, { 128,  48 }, { 192,  48 },
		{ 0,    96 }, { 64,   96 }, { 128,  96 }, { 192,  96 },
		{ 0,   144 }, { 64,  144 }, { 128, 144 }, { 192, 144 },
		{ 0,   192 }, { 64,  192 }, { 128, 144 }, { 192, 192 }
	};

    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0)
    {                       
    case 0:
        op->flg |= 0x4080000;
        
        op->tex_id = 65;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = 0;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 20) 
        {
            op->mode0 = 0;
    
            op->type = op->mode1 = 0;
            return;
        }

        break;
    }

    op->az = (short)((65536.0f * op->sz) / 360.0f);
    
    pInfo = &Eff210UvInfo[op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 63) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 47) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 99.50% matching (matches on NGC)
void bhEff211(O_WRK* op) 
{
    EFF5UV* pInfo;
	static EFF5UV Eff211UvInfo[10] = 
	{
		{   0,   0 }, {  64,   0 }, { 128,   0 }, { 192,   0 },
		{   0,  48 }, {  64,  48 }, { 128,  48 }, { 192,  48 },
		{   0,  96 }, {  64,  96 }
	};

    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0)
    {                       
    case 0:
        op->flg |= 0x4080000;
        
        op->tex_id = 65;
        
        op->ani_ct = 1;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = 0;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 10) 
        {
            op->mode0 = 0;
    
            op->type = op->mode1 = 0;
            return;
        }

        break;
    }

    op->az = (short)((65536.0f * op->sz) / 360.0f);
    
    pInfo = &Eff211UvInfo[op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 63) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 47) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 99.60% matching (matches on NGC)
void bhEff212(O_WRK* op) 
{
    EFF5UV* pInfo;
	static EFF5UV Eff212UvInfo[16] = 
	{
		{   0,   0 }, {  64,   0 }, { 128,   0 }, { 192,   0 },
		{   0,  48 }, {  64,  48 }, { 128,  48 }, { 192,  48 },
		{   0,  96 }, {  64,  96 }, { 128,  96 }, { 192,  96 },
		{   0, 144 }, {  64, 144 }, { 128, 144 }, { 192, 144 }
	};

    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0)
    {                       
    case 0:
        op->flg |= 0x4080000;
        
        op->tex_id = 65;
        
        op->ani_ct = 2;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = 0;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = 0x80FFFFFF;
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 16) 
        {
            op->ct0 = 0;
        }
        
        break;
    }
    
    op->az = (short)((65536.0f * op->sz) / 360.0f);
    
    pInfo = &Eff212UvInfo[op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 63) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 47) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 99.62% matching (matches on NGC)
void bhEff213(O_WRK* op)
{
    EFF5UV* pInfo;
	static EFF5UV Eff213UvInfo[3][3] = 
	{
		{ { 0,   0 }, { 80,   0 }, { 160,   0 } },
		{ { 0,  60 }, { 80,  60 }, { 160,  60 } },
		{ { 0, 120 }, { 80, 120 }, { 160, 120 } }
	};

    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0)
    {                       
    case 0:
        op->flg |= 0x4080000;
        
        op->tex_id = 67;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = 0;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 3) 
        {
            op->ct0 = 0;
        }
        
        break;
    }
    
    op->az = (short)((65536.0f * op->sz) / 360.0f);
    
    pInfo = &Eff213UvInfo[(op->type - 1) % 3][op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 79) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 59) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff214(O_WRK* op) 
{
    EF_WORK* pEffect;
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    pEffect = &sys->ef;
    
    pEffect->flg = 1;
    
    pEffect->id = 11;
    
    pEffect->type = 0;
    
    pEffect->flr_no = 0;
    
    pEffect->mdlver = 0;
    
    pEffect->px = op->px;
    pEffect->py = op->py;
    pEffect->pz = op->pz;
    
    pEffect->sx = op->sx;
    pEffect->sy = op->sy;
    pEffect->sz = op->sz;
    
    pEffect->ay = op->ay;
    pEffect->ax = op->ax;
    
    bhSetEffectTb(pEffect, NULL, NULL, 0xFF);
    
    op->type = op->mode1 = 0;
}

// 100% matching!
void bhEff215(O_WRK* op)
{
    EF_WORK* pEffect;
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    pEffect = &sys->ef;
    
    op->type = (op->type - 1) % 9;
    
    if (op->type < 6) 
    {
        pEffect->id   = 216;
        pEffect->type = op->type;
    } 
    else 
    {
        pEffect->id   = 217;
        pEffect->type = op->type - 6;
    }
    
    pEffect->flg = 1;
    
    pEffect->flr_no = 0;
    
    pEffect->mdlver = 0;
    
    pEffect->px = op->px;
    pEffect->py = op->py;
    pEffect->pz = op->pz;
    
    pEffect->sx = op->sx;
    pEffect->sy = op->sy;
    pEffect->sz = op->sz;
    
    pEffect->ay = op->ay;
    pEffect->ax = op->ax;
    
    bhSetEffectTb(pEffect, NULL, NULL, 0xFF);
    
    op->type = op->mode1 = 0;
}

// 99.19% matching (matches on NGC)
void bhEff216(O_WRK* op) 
{
    EFF5UVWH* uvp;
	static EFF5UVWH uvinfo0[15] = 
	{
		{ 9,    24,   7,   6 },
		{ 9,    24,   7,   6 },
		{ 81,   32,  15,  14 },
		{ 1,     0,  23,  22 },
		{ 25,    0,  23,  22 },
		{ 49,    0,  23,  22 },
		{ 73,    0,  23,  22 },
		{ 1,    24,  23,  22 },
		{ 25,   24,  23,  22 },
		{ 49,   24,  31,  30 },
		{ 97,    0,  31,  30 },
		{ 129,   0,  39,  38 },
		{ 169,   0,  39,  38 },
		{ 209,   0,  39,  38 },
		{ -1,    0,   0,   0 }
	};
	static EFF5UVWH uvinfo1[15] = 
	{
		{ 1,    96,   7,   6 },
		{ 9,    96,   7,   6 },
		{ 1,   104,  15,  14 },
		{ 17,   96,  23,  22 },
		{ 41,   96,  23,  22 },
		{ 65,   96,  23,  22 },
		{ 89,   96,  31,  30 },
		{ 121,  96,  31,  30 },
		{ 1,    56,  39,  38 },
		{ 41,   56,  39,  38 },
		{ 81,   56,  39,  38 },
		{ 121,  56,  39,  38 },
		{ 161,  56,  39,  38 },
		{ 201,  56,  39,  38 },
		{ -1,    0,   0,   0 }
	};
	static EFF5UVWH uvinfo2[11] = 
	{
		{   0, 145,  48,  47 },
		{  48, 145,  48,  47 },
		{  96, 145,  48,  47 },
		{ 144, 145,  48,  47 },
		{ 192, 145,  48,  47 },
		{   0, 193,  48,  47 },
		{  48, 193,  48,  47 },
		{  96, 193,  48,  47 },
		{ 144, 193,  48,  47 },
		{ 192, 193,  48,  47 },
		{  -1,   0,   0,   0 }
	};
	static EFF5UVWH* uvtble[6] = 
	{
		uvinfo0, uvinfo1, uvinfo2,
		uvinfo0, uvinfo1, uvinfo2
	};
    
    switch (op->mode0) 
    {                             
    case 0:
        if ((double)op->sz != 0) 
        {
            op->tv[0].x = op->tv[2].x = -1.0f;
            op->tv[1].x = op->tv[3].x = 1.0f;
            
            op->tv[0].y = op->tv[1].y = -2.0f;
            op->tv[2].y = op->tv[3].y = 0;
            
            op->tv[0].z = op->tv[1].z = op->tv[2].z =op->tv[3].z = 0;
        }
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = 0xFF404040;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->tex_id = 66;
        
        op->flg |= 0x4180000;
        
        op->ani_ct = (op->type / 3) % 2;
        
        op->ct0 = 0;
        
        op->sxb = op->sx;
        op->syb = op->sy;
        
        if ((double)op->sz != 0)
        {
            op->xn = 0;
            op->yn = op->sz / 4.0f;
            op->zn = 0;
            
            njPushMatrixEx();
            
            njUnitMatrix(NULL);
            
            njRotateY(NULL, op->ay);
            njRotateX(NULL, op->ax);
            
            njCalcPoint(NULL, (NJS_POINT3*)&op->xn, (NJS_POINT3*)&op->xn);
            
            njPopMatrixEx();
        }
        
        op->mode0 = 1;
    case 1:
        uvp = uvtble[op->type % 6] + op->ct0;
        
        if (uvp->u < 0) 
        {
            op->flg = 0;
            return;
        }
        
        op->ct0++;
        
        if (op->sz != 0) 
        {
            op->px += op->xn;
            op->py += op->yn;
            op->pz += op->zn;
            
            op->yn -= 0.1f;
        }
        
        op->tv[0].u = op->tv[2].u = uvp->u                  / 256.0f;
        op->tv[1].u = op->tv[3].u = ((uvp->u + uvp->w) - 1) / 256.0f;
        
        op->tv[0].v = op->tv[1].v = uvp->v                  / 256.0f;
        op->tv[2].v = op->tv[3].v = ((uvp->v + uvp->h) - 1) / 256.0f;
        
        op->sx = (op->sxb * uvp->w) / 16.0f;
        op->sy = (op->syb * uvp->h) / 16.0f;
        
        if (sys->ef_trsn < 512) 
        {
            sys->ef_trs[sys->ef_trsn] = op;
            
            sys->ef_trsn++;
        }

        break;
    }
}

// 99.94% matching
void bhEff217(O_WRK* op)
{
    P_WRK* pp;            
    NJS_POINT3* p;      
    NJS_VECTOR* v;       
    int i;               
    unsigned int col[3] = 
	{
		0xFF332417, 0xFF322320, 0xFF211816
	};
    float fAngleDev;      
	
    switch (op->mode0) 
    {                          
    case 0:
        pp = (P_WRK*)bhSetExtraEffectWork();
        
        if (pp == NULL) 
        {
            op->flg = 0;
            break;
        }
        
        op->exp0 = (unsigned char*)pp;
        
        p = pp->pos;
        v = pp->vec;
        
        pp->num = 16;
        
        for (i = 0; i < pp->num; i++, p++, v++) 
        {
            p->x = (op->px + (op->sx * (-rand() / -2.1474836E9f))) - (op->sx * (-rand() / -2.1474836E9f));
            p->y = (op->py + (op->sx * (-rand() / -2.1474836E9f))) - (op->sx * (-rand() / -2.1474836E9f));
            p->z = (op->pz + (op->sx * (-rand() / -2.1474836E9f))) - (op->sx * (-rand() / -2.1474836E9f));
            
            v->x = 0;
            v->y = op->sz;
            v->z = 0;
            
            njPushMatrixEx();
            
            fAngleDev = 65536.0f * (op->sy / 360.0f);
            
            njUnitMatrix(NULL);
            
            njRotateY(NULL, (op->ay + (((short)(fAngleDev * (-rand() / -2.1474836E9f))))) - (fAngleDev / 2.0f));
            njRotateX(NULL, (op->ax + (((short)(fAngleDev * (-rand() / -2.1474836E9f))))) - (fAngleDev / 2.0f));
            
            njCalcPoint(NULL, v, v);
            
            njPopMatrixEx();
        }
        
        pp->sx = 1.0f;
        pp->sy = 1.0f;
        
        pp->col = col[op->type];
        
        op->ct0 = 10.0f + (10.0f * (-rand() / -2.1474836E9f));
        
        op->flg |= 0x20000000;
        
        op->func = (void*)bhEff_E00_DrawParticlePly;
        
        op->mode0++;
        break;
    case 1:
        pp = (P_WRK*)op->exp0;
        
        p = pp->pos;
        v = pp->vec;
        
        for (i = 0; i < pp->num; i++, p++, v++) 
        {
            p->x += v->x;
            p->y += v->y;
            p->z += v->z;
            
            v->y -= 0.4f;
            v->x *= 0.8f;
            v->z *= 0.8f;
        }
        
        if (op->ct0-- == 0) 
        {
            op->flg = 0;
            pp->flg = 0;
            break;
        }
        
        if (sys->ef_fncn < 128) 
        {
            sys->ef_fnc[sys->ef_fncn] = op;
            
            sys->ef_fncn++;
        }
        
        break;
    }
}

// 99.61% matching
void bhEff218(O_WRK* op) 
{
    EFF5UV* pInfo;
    int lType;
	static EFF5UV Fire13[10] = 
	{
		{ 0,     0 },
		{ 40,    0 },
		{ 80,    0 },
		{ 120,   0 },
		{ 160,   0 },
		{ 200,   0 },
		{ 0,    40 },
		{ 40,   40 },
		{ 80,   40 },
		{ 120,  40 }
	};
	static EFF5UV Fire16[12] = 
	{
		{ 0,    80 },
		{ 40,   80 },
		{ 80,   80 },
		{ 120,  80 },
		{ 160,  80 },
		{ 200,  80 },
		{ 0,   120 },
		{ 40,  120 },
		{ 80,  120 },
		{ 120, 120 },
		{ 160, 120 },
		{ 200, 120 }
	};
	static EFF5UV Fire14[12] = 
	{
		{ 0,   160 },
		{ 40,  160 },
		{ 80,  160 },
		{ 120, 160 },
		{ 160, 160 },
		{ 200, 160 },
		{ 0,   200 },
		{ 40,  200 },
		{ 80,  200 },
		{ 120, 200 },
		{ 160, 200 },
		{ 200, 200 }
	};
	static EFF5UV Fire02[8] = 
	{
		{ 0,     0 },
		{ 56,    0 },
		{ 112,   0 },
		{ 168,   0 },
		{ 0,    56 },
		{ 56,   56 },
		{ 112,  56 },
		{ 168,  56 }
	};
	static EFF5UV Fire04[10] = 
	{
		{ 0,   112 },
		{ 24,  112 },
		{ 48,  112 },
		{ 72,  112 },
		{ 96,  112 },
		{ 120, 112 },
		{ 144, 112 },
		{ 168, 112 },
		{ 192, 112 },
		{ 216, 112 }
	};
	static EFF5UV Fire07[10] = 
	{
		{ 0,   136 },
		{ 48,  136 },
		{ 96,  136 },
		{ 144, 136 },
		{ 192, 136 },
		{ 0,   184 },
		{ 48,  184 },
		{ 96,  184 },
		{ 144, 184 },
		{ 192, 184 }
	};
	static EFF5UV Fire03[8] = 
	{
		{ 0,     0 },
		{ 56,    0 },
		{ 112,   0 },
		{ 168,   0 },
		{ 0,    56 },
		{ 56,   56 },
		{ 112,  56 },
		{ 168,  56 }
	};
	static EFF5UV Fire06[10] = 
	{
		{ 0,   112 },
		{ 48,  112 },
		{ 96,  112 },
		{ 144, 112 },
		{ 192, 112 },
		{ 0,   168 },
		{ 48,  168 },
		{ 96,  168 },
		{ 144, 168 },
		{ 192, 168 }
	};
	static EFF5UV Fire08[10] = 
	{
		{ 0,     0 },
		{ 48,    0 },
		{ 96,    0 },
		{ 144,   0 },
		{ 192,   0 },
		{ 0,    48 },
		{ 48,   48 },
		{ 96,   48 },
		{ 144,  48 },
		{ 192,  48 }
	};
	static EFF5UV Fire05[10] = 
	{
		{ 0,    96 },
		{ 48,   96 },
		{ 96,   96 },
		{ 144,  96 },
		{ 192,  96 },
		{ 0,   144 },
		{ 48,  144 },
		{ 96,  144 },
		{ 144, 144 },
		{ 192, 144 }
	};
	static EFF5UV Fire09[10] = 
	{
		{ 0,     0 },
		{ 56,    0 },
		{ 112,   0 },
		{ 168,   0 },
		{ 0,    56 },
		{ 56,   56 },
		{ 112,  56 },
		{ 168,  56 },
		{ 0,   112 },
		{ 56,  112 }
	};
	static EFF5UV Fire01[10] = 
	{
		{ 0,     0 },
		{ 40,    0 },
		{ 80,    0 },
		{ 120,   0 },
		{ 160,   0 },
		{ 200,   0 },
		{ 0,    40 },
		{ 40,   40 },
		{ 80,   40 },
		{ 120,  40 }
	};
	static EFF5UV Fire10[10] = 
	{
		{ 0,     0 },
		{ 48,    0 },
		{ 96,    0 },
		{ 144,   0 },
		{ 192,   0 },
		{ 0,    48 },
		{ 48,   48 },
		{ 96,   48 },
		{ 144,  48 },
		{ 192,  48 }
	};
	static EFF5UV Fire11[12] = 
	{
		{ 0,     0 },
		{ 56,    0 },
		{ 112,   0 },
		{ 168,   0 },
		{ 0,    56 },
		{ 56,   56 },
		{ 112,  56 },
		{ 168,  56 },
		{ 0,   112 },
		{ 56,  112 },
		{ 112, 112 },
		{ 168, 112 }
	};
	static EFF5UV Fire12[14] = 
	{
		{ 0,     0 },
		{ 32,    0 },
		{ 64,    0 },
		{ 96,    0 },
		{ 128,   0 },
		{ 160,   0 },
		{ 192,   0 },
		{ 0,    32 },
		{ 32,   32 },
		{ 64,   32 },
		{ 96,   32 },
		{ 128,  32 },
		{ 160,  32 },
		{ 192,  32 }
	};
	static EFF5UV Fire00[8] = 
	{
		{ 0,    64 },
		{ 56,   64 },
		{ 112,  64 },
		{ 168,  64 },
		{ 0,   120 },
		{ 56,  120 },
		{ 112, 120 },
		{ 168, 120 }
	};
	static EFF5UV Fire15[12] = 
	{
		{ 0,     0 },
		{ 40,    0 },
		{ 80,    0 },
		{ 120,   0 },
		{ 160,   0 },
		{ 200,   0 },
		{ 0,    40 },
		{ 40,   40 },
		{ 80,   40 },
		{ 120,  40 },
		{ 160,  40 },
		{ 200,  40 }
	};
	static EFF5UVTBL Eff218[17] = 
	{
		{ Fire13, 10, 70,  0,  0, 40, 40 },
		{ Fire16, 12, 70,  0,  0, 40, 40 },
		{ Fire14, 12, 70,  0,  0, 40, 40 },
		{ Fire02,  8, 71,  0,  0, 56, 56 },
		{ Fire04, 10, 71,  0,  0, 24, 24 },
		{ Fire07, 10, 71,  0,  0, 48, 48 },
		{ Fire03,  8, 72,  0,  0, 56, 56 },
		{ Fire06, 10, 72,  0,  0, 48, 56 },
		{ Fire08, 10, 73,  0,  0, 48, 48 },
		{ Fire05, 10, 73,  0,  0, 48, 48 },
		{ Fire09, 10, 74,  0,  0, 56, 56 },
		{ Fire01, 10, 75,  0,  0, 40, 40 },
		{ Fire10, 10, 76,  0,  0, 48, 48 },
		{ Fire11, 12, 77,  0,  0, 56, 56 },
		{ Fire12, 14, 78,  0,  0, 32, 32 },
		{ Fire00,  8, 78,  0,  0, 56, 56 },
		{ Fire15, 12, 79,  0,  0, 40, 40 }
	};
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    lType = (op->type - 1) % 17;
    
    switch (op->mode0) 
    {                            
    case 0:
        op->flg |= 0x4180000;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->tv[0].x = op->tv[2].x = -1.0f;
        op->tv[1].x = op->tv[3].x = 1.0f;
        
        op->tv[0].y = op->tv[1].y = -2.0f;
        op->tv[2].y = op->tv[3].y = 0;
        
        op->tv[0].z = op->tv[1].z = op->tv[2].z = op->tv[3].z = 0;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->ct0 = Eff218[lType].lTblMax * (-rand() / -2.1474836E9f);
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (Eff218[lType].lTblMax <= op->ct0) 
        {
            op->ct0 = 0;
        }
        
        break;
    }
    
    op->tex_id = Eff218[lType].lTexID;
    op->ani_ct = Eff218[lType].lAniCt;
    
    pInfo = &Eff218[lType].pTblTop[op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u                           / 256.0f;
    op->tv[1].u = op->tv[3].u = ((pInfo->u + Eff218[lType].w) - 1) / 256.0f;
    
    if (pInfo->v) 
    {
        op->tv[0].v = op->tv[1].v = (pInfo->v + 1) / 256.0f;
    } 
    else 
    {
        op->tv[0].v = op->tv[1].v = pInfo->v       / 256.0f;
    }
    
    op->tv[2].v = op->tv[3].v = (pInfo->v + Eff218[lType].h) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff219(O_WRK* op) 
{
    EFF5SNOWRECT* pSnow;
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type != 0)
    {
        op->flg |= 0x1000000;
        
        op->type = ((op->type - 1) % 3) + 1;
        
        switch (op->mode0) 
        {
        case 0:
            if ((pSnow = CreateEff5SnowRect(850)) == NULL) 
            {
                op->flg = 0;
                return;
            }
            
            if (op->type == 3)
            {
                SetEff5SnowRectAreaCenterAndSize(pSnow, op->px, op->py, op->pz, op->sx, op->sx, op->sx);
            } 
            else
            {
                SetEff5SnowRectAreaCenterAndSize(pSnow, cam.wpx + (40.0f * cam.vx), cam.wpy + (40.0f * cam.vy), cam.wpz + (40.0f * cam.vz), 65.0f, 65.0f, 65.0f);
            }
            
            SetEff5SnowRectParticleTexture(pSnow, &sys->ef_tlist, sys->ef_tn[409], 0, 0, 1.0f, 0, 0, 1.0f, 1.0f, 1.0f);
            SetEff5SnowRectParticleColor(pSnow, 0xA0FFFFFF, 0xA0FFFFFF, 0xA0FFFFFF, 0xA0FFFFFF);
            
            ArrangeEff5SnowRectParticle(pSnow);
            
            SetEff5SnowRectParticleMax(pSnow, (op->ax * 850) / 32760);
            
            op->exp0 = (unsigned char*)pSnow;
            
            op->func = (void*)DrawEff5SnowRect;
            
            op->mode0 = 1;
            break;
        }
        
        pSnow = (EFF5SNOWRECT*)op->exp0;
        
        switch (op->type) 
        {                      
        case 1:
        case 2:
            SetEff5SnowRectAreaCenter(pSnow, cam.wpx + (40.0f * cam.vx), cam.wpy + (40.0f * cam.vy), cam.wpz + (40.0f * cam.vz));
            SetEff5SnowRectParticleSize(pSnow, (0.3f * op->sx) / 4.0f, (0.3f * op->sy) / 4.0f);
            break;
        case 3:
            SetEff5SnowRectAreaCenterAndSize(pSnow, op->px, op->py, op->pz, op->sx, op->sx, op->sx);
            SetEff5SnowRectParticleSize(pSnow, (0.3f * op->sy) / 4.0f, (0.3f * op->sy) / 4.0f);
            break;
        }
        
        if (op->ax < 0) 
        {
            op->ax = 0;
        }
        
        MovEff5SnowRectParticleMax(pSnow, (op->ax * 850) / 32760, 150);
        
        ExecEff5SnowRect(pSnow);
        
        if (sys->ef_fncn < 128) 
        {
            sys->ef_fnc[sys->ef_fncn] = op;
            
            sys->ef_fncn++;
        }
    }
}

// 99.87% matching (matches on NGC)
void bhEff220(O_WRK* op) 
{
    NJS_VECTOR vc0, vc1; 
    int i, j;        
    int ct;     
    float r;       
    float spd;     
    float xn, yn;      
    float spq;      
    int lNumber;    
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    ct = op->lkono;
    
    r   = op->sy;
    spd = op->sz;
    
    sys->ef.sx = sys->ef.sy = sys->ef.sz = op->sx;
    
    vc0.x = vc0.y = 0;
    vc0.z = -1.0f;
    
    sys->ef.id = 221;
    
    sys->ef.flg = 1;
    
    sys->ef.type = op->type;
    
    if (((op->type - 1) % 2) != 0) 
    {
        sys->ef.flr_no = 0;
    } 
    else 
    {
        sys->ef.flr_no = 7;
    }
    
    spq = fabsf(njSqrt(ct));
    
    xn = 120.0f / spq;
    yn = 140.0f / spq;
    
    j = spq;
    
    for (i = 0; i < ct; i++) 
    {
        sys->ef.ax = op->ax + ((int)(182.04445f * (((30.0f * (-rand() / -2.1474836E9f)) - 15.0f) + ((xn * ((i + 1) / j)) - 60.0f))) & 0xFFFF);
        sys->ef.ay = op->ay + ((int)(182.04445f * (((30.0f * (-rand() / -2.1474836E9f)) - 15.0f) + ((yn * ((i + 1) % j)) - 70.0f))) & 0xFFFF);
        
        sys->ef.mdlver = (unsigned char)((i * 4) % 55);
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, sys->ef.ax, sys->ef.ay, 0);
        njCalcVector(NULL, &vc0, &vc1);
        
        sys->ef.px = op->px + (vc1.x * r);
        sys->ef.py = op->py + (vc1.y * r);
        sys->ef.pz = op->pz + (vc1.z * r);
        
        vc1.x *= spd;
        vc1.y *= spd;
        vc1.z *= spd;
        
        lNumber = bhSetEffectTb(&sys->ef, &vc1, NULL, 0);
        
        if (lNumber != -1) 
        {
            eff[lNumber].tex_id = 417;
        }
    } 
    
    op->type = op->mode1 = 0;
}

// 99.49% matching (matches on NGC)
void bhEff221(O_WRK* op) 
{
    NJS_VECTOR vc0;        
    NJS_TEXTUREH_VTX* tvp; 
    int pt;                
    float u, v;             
    int is;               
    float fs;     

    switch (op->mode0)
    {                            
    case 0:
        op->flg |= 0x6000000;
        
        op->tvp = (NJS_TEXTURE_VTX*)op->pv;
        tvp     = (NJS_TEXTUREH_VTX*)op->pvp;
        
        tvp[0].x = -1.0f;
        tvp[0].y = -1.0f;
        tvp[0].z = 0.0f;
        
        tvp[1].x = 1.0f;
        tvp[1].y = -1.0f;
        tvp[1].z = 0;
        
        tvp[2].x = -1.0f;
        tvp[2].y = 1.0f;
        tvp[2].z = 0;
        
        tvp[3].x = 1.0f;
        tvp[3].y = 1.0f;
        tvp[3].z = 0;
        
        tvp[0].bcol = -1;
        tvp[1].bcol = -1;
        tvp[2].bcol = -1;
        tvp[3].bcol = -1;
        
        is = op->mdlver;
        
        if (is > 28)
        {
            v = ((is - 29) * 16) / 256.0f;
            
            tvp[0].u = v;
            tvp[0].v = 0.9375f;
            
            u = 0.0625f + v;
            
            tvp[1].u = u; 
            tvp[1].v = 0.9375f;
            
            tvp[2].u = v;
            tvp[2].v = 1.0f;
            
            tvp[3].u = u;
            tvp[3].v = 1.0f;
            
            op->sx = 6.0f * (0.0625f * op->sxb);
            op->sy = 6.0f * (0.0625f * op->syb);
            op->sz = 6.0f * (0.0625f * op->szb);
        } 
        else if (is > 14) 
        {
            u = (((is  - 15) % 8) * 32)        / 256.0f;
            v = ((((is - 15) / 8) * 32) + 144) / 256.0f;
            
            tvp[0].u = u;
            tvp[0].v = v;
            
            tvp[1].u = 0.125f + u;
            tvp[1].v = v;
            
            tvp[2].u = u;
            tvp[2].v = 0.125f + v;
            
            tvp[3].u = 0.125f + u;
            tvp[3].v = 0.125f + v;
            
            op->sx = 7.0f * (0.125f * op->sxb);
            op->sy = 7.0f * (0.125f * op->syb);
            op->sz = 7.0f * (0.125f * op->szb);
        }
        else 
        {
            u = (((is  - 15) % 5)  * 48) / 256.0f;
            v = ((((is - 15) / 5)) * 48) / 256.0f;
            
            tvp[0].u = u;
            tvp[0].v = v;
            
            tvp[1].u = 0.1875f + u;
            tvp[1].v = v;
            
            tvp[2].u = u;
            tvp[2].v = 0.1875f + v;
            
            tvp[3].u = 0.1875f + u;
            tvp[3].v = 0.1875f + v;
            
            op->sx = 8.0f * (0.1875f * op->sxb);
            op->sy = 8.0f * (0.1875f * op->syb);
            op->sz = 8.0f * (0.1875f * op->szb);
        }
        
        vc0.x = op->lox;
        vc0.y = op->loy;
        vc0.z = op->loz;
        
        njUnitVector(&vc0);
        
        op->axp = (int)(182.04445f * (10.0f + (10.0f * (-rand() / -2.1474836E9f)))) & 0xFFFF;
        op->ayp = (int)(182.04445f * (10.0f + (10.0f * (-rand() / -2.1474836E9f)))) & 0xFFFF;
        
        op->yn = op->loy;
        
        if ((op->flr_no & 0x1)) 
        {
            op->bl_src = 8;
            op->bl_dst = 10;
        } 
        else 
        {
            op->bl_src = 8;
            op->bl_dst = 10;
        }
        
        op->ct0 = op->ani_ct = 0;
        
        op->func = (void*)bhDrawEff221;
        
        op->mode0 = 1;
        
        op->spd = op->py - 10.0f;
    case 1:
        if ((sys->st_flg & 0x2000000)) 
        {
            pt = sys->ef_slow;
            
            fs = pt;
            
            op->ax += op->axp / pt;
            op->ay += op->ayp / pt;
            
            op->px += op->lox / fs;
            op->pz += op->loz / fs;
            
            op->lox -= (0.06f * op->lox) / fs;
            op->loz -= (0.06f * op->loz) / fs;
            
            op->py += op->yn / fs;
            
            if (op->yn > -1.0f) 
            {
                op->yn -= 0.05f / fs; 
            }
        } 
        else 
        {
            op->ax += op->axp;
            op->ay += op->ayp;
            
            op->px += op->lox;
            op->pz += op->loz;
            
            op->lox -= 0.06f * op->lox;
            op->loz -= 0.06f * op->loz;
            
            op->py += op->yn;
            
            if (op->yn > -1.0f) 
            {
                op->yn -= 0.05f;
            }
        }
        
        if (op->py <= op->spd) 
        {
            op->flg = 0;
            return;
        }

        break;
    }

    if (sys->ef_fncn < 128) 
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
}

// 100% matching!
void bhDrawEff221(O_WRK* op) 
{
    NJS_TEXTUREH_VTX* tvp;
    NJS_POINT3 vc0, vc1;
    float it;
    int pt;

    if ((op->flr_no & 0x4)) 
    {
        vc0.x = vc0.y = 0;
        vc0.z = -1.0f;
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, op->ax, op->ay, 0);
        njCalcVector(NULL, &vc0, &vc1);
        
        it = fabsf(njInnerProduct((NJS_VECTOR*)&vc1, (NJS_VECTOR*)&cam.vx));
        
        pt = (int)(128.0f * njCos((int)(182.04445f * (360.0f * it)) & 0xFFFF)) + 127;
    }
    else
    {
        pt = 0;
    }
    
    tvp = (NJS_TEXTUREH_VTX*)op->tvp;
        
    tvp[3].ocol = tvp[2].ocol = tvp[1].ocol = tvp[0].ocol = (pt << 0) | ((pt << 8) | ((pt << 24) | (pt << 16)));
    
    njTextureFilterMode(1);
    
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[op->tex_id]);
    
    if ((op->flr_no & 0x2)) 
    {
        njSetMatrix(NULL, cam.mtx);
        
        njTranslateEx((NJS_VECTOR*)&op->px);
        njRotateEx(&op->ax, 0);
        njScaleEx((NJS_VECTOR*)&op->sx);
    }
    else 
    {
        njSetMatrix(NULL, cam.mtx);
        
        njTranslateEx((NJS_VECTOR*)&op->px);
        njUnitRotPortion(NULL);
        njScaleEx((NJS_VECTOR*)&op->sx);
    }
    
    njColorBlendingMode(0, op->bl_src);
    njColorBlendingMode(1, op->bl_dst);
    
    njDrawTexture3DHEx(tvp, 4, 1);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
}

// 100% matching!
void bhEff222(O_WRK* op) 
{
    EF_WORK* pEffect;
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    if (op->sz <= 0) 
    {
        op->sz = 0.1f;
    }
    
    switch (op->mode0) 
    {                            
    case 0:
        op->ct0   = 0;
        op->mode0 = 1;
    case 1:
        op->ct0++;
        
        if (op->lkono <= op->ct0) 
        {
            pEffect = &sys->ef;
            
            pEffect->flg = 1;
            
            pEffect->id = 223;
            
            pEffect->type = (op->type - 1) % 4;
            
            pEffect->flr_no = 0;
            
            pEffect->mdlver = 0;
            
            pEffect->px = op->px;
            pEffect->py = (op->py + (6.0f * (-rand() / -2.1474836E9f))) - 3.0f;
            pEffect->pz = (op->pz + (6.0f * (-rand() / -2.1474836E9f))) - 3.0f;
            
            pEffect->sx = op->sx;
            pEffect->sy = op->sy;
            pEffect->sz = op->sz / 10.0f;
            
            pEffect->ay = op->ay;
            pEffect->ax = op->ax;
            
            bhSetEffectTb(pEffect, NULL, NULL, 0);
            
            op->ct0 = 0;
        }
        
        break;
    }
}

// 99.43% matching (matches on NGC)
void bhEff223(O_WRK* op) 
{
    EFF5UV* pInfo;
	static EFF5UV Eff223UvInfo[2][18] = 
	{
		{ 
			{   0,   0 }, {  40,   0 }, {  80,   0 },
	    	{ 120,   0 }, { 160,   0 }, { 200,   0 },
	    	{   0,  40 }, {  40,  40 }, {  80,  40 },
	    	{ 120,  40 }, { 160,  40 }, { 200,  40 },
	    	{   0,  80 }, {  40,  80 }, {  80,  80 },
	    	{ 120,  80 }, { 160,  80 }, { 200,  80 } 
		},
		{ 
			{   0, 120 }, {  40, 120 }, {  80, 120 },
			{ 120, 120 }, { 160, 120 }, { 200, 120 },
			{   0, 160 }, {  40, 160 }, {  80, 160 },
			{ 120, 160 }, { 160, 160 }, { 200, 160 },
			{   0, 200 }, {  40, 200 }, {  80, 200 },
			{ 120, 200 }, { 160, 200 }, { 200, 200 } 
		}
	};
        
    switch (op->mode0) 
    {                            
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 411;
        
        op->ani_ct = op->type / 2;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = 0;
        op->ct1 = 7.5f / op->sz;
        
        if (op->ct1 < 0)
        {
            op->ct1 = 1;
        }
        
        op->ct2 = 18.0f      * (-rand() / -2.1474836E9f);
        op->ct3 = (int)(2.0f * (-rand() / -2.1474836E9f)) + 1;
        
        if ((int)(2.0f * (-rand() / -2.1474836E9f)) != 0) 
        {
            op->ct3 = -op->ct3;
        }
        
        if ((int)(2.0f * (-rand() / -2.1474836E9f)) != 0) 
        {
            op->tv[0].x *= -1.0f;
            op->tv[1].x *= -1.0f;
            op->tv[2].x *= -1.0f;
            op->tv[3].x *= -1.0f;
        }
        
        if ((int)(2.0f * (-rand() / -2.1474836E9f)) != 0) 
        {
            op->tv[0].y *= -1.0f;
            op->tv[1].y *= -1.0f;
            op->tv[2].y *= -1.0f;
            op->tv[3].y *= -1.0f;
        }
        
        op->az = (op->ax  * (-rand() / -2.1474836E9f)) - (op->ax / 2);
        op->ax = 65536.0f * (-rand() / -2.1474836E9f);
        
        op->spd = op->sz * (35.533333f * (1.0f + (-rand() / -2.1474836E9f)));
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct1 <= op->ct0) 
        {
            op->flg = 0;
            return;
        }
        
        op->ct2 += op->ct3;
        
        if (op->ct2 < 0) 
        {
            op->ct2 = 17;
        } 
        else if (op->ct2 >= 18) 
        {
            op->ct2 = 0;
        }
        
        op->xn = op->spd;
        op->yn = 0;
        op->zn = 0;
        
        njPushMatrixEx();
        
        njUnitMatrix(NULL);
        
        njRotateX(NULL, op->ax);
        njRotateZ(NULL, op->az);
        
        njCalcPoint(NULL, (NJS_POINT3*)&op->xn, (NJS_POINT3*)&op->xn);
        
        njPopMatrixEx();
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->az *= 1.0f - (op->ay / 32760.0f);
        break;
    }

    pInfo = &Eff223UvInfo[op->type % 2][op->ct2 % 18];
    
    op->tv[0].u = op->tv[2].u = (pInfo->u + 2)  / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 39) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 39) / 256.0f;
    
    op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = ((0xFF - ((op->ct0 * 0xFF) / op->ct1)) << 24) | 0xFFFFFF;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff224(O_WRK* op)
{
    EF_WORK* pEffect;
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    pEffect = &sys->ef;
    
    pEffect->flg = 1;
    
    pEffect->id = 225;
    
    pEffect->type = (op->type - 1) % 4; 
    
    pEffect->mdlver = 0;

    pEffect->flr_no = 0;
    
    pEffect->px = op->px;
    pEffect->py = op->py;
    pEffect->pz = op->pz;
    
    pEffect->sx = op->sx;
    pEffect->sy = op->sy;
    pEffect->sz = op->sz;
    
    pEffect->ay = op->ay;
    pEffect->ax = op->ax;
    
    bhSetEffectTb(pEffect, NULL, NULL, 0);
    
    op->type = op->mode1 = 0;
}

// 100% matching!
void bhEff225(O_WRK* op)
{
    EFF5UVWHUC* pInfo;
	static EFF5UVWHUC Eff225UvInfo1[11] = 
	{
		{   0,  64,  16,  16 },
		{   0,  40,  24,  24 },
		{  24,  40,  32,  32 },
		{  56,  40,  40,  40 },
		{  96,  40,  40,  40 },
		{   0,   0,  40,  40 },
		{  40,   0,  40,  40 },
		{  80,   0,  40,  40 },
		{ 120,   0,  40,  40 },
		{ 160,   0,  40,  40 },
		{ 200,   0,  40,  40 }
	};
	static EFF5UVWHUC Eff225UvInfo2[9] = 
	{
		{  16,  80,  32,  32 },
		{  48,  80,  32,  32 },
		{  80,  80,  32,  32 },
		{ 112,  80,  32,  32 },
		{ 144,  80,  32,  32 },
		{ 176,  80,  32,  32 },
		{ 208,  80,  32,  32 },
		{  16, 112,  32,  32 },
		{  48, 112,  32,  32 }
	};
	static EFF5UVWHUC Eff225UvInfo3[13] = 
	{
		{  84, 116,   8,   8 },
		{  96, 116,  20,  24 },
		{ 116, 116,  20,  24 },
		{ 136, 116,  24,  24 },
		{ 160, 116,  24,  24 },
		{ 184, 116,  24,  24 },
		{ 208, 112,  32,  32 },
		{   0, 144,  40,  40 },
		{  40, 144,  40,  40 },
		{  80, 144,  40,  40 },
		{ 120, 144,  40,  40 },
		{ 160, 144,  40,  40 },
		{ 200, 144,  40,  40 }
	};
	static EFF5UVWHUC Eff225UvInfo4[10] = 
	{
		{  60, 184,  24,  24 },
		{  84, 184,  24,  24 },
		{ 108, 184,  32,  32 },
		{ 140, 184,  32,  32 },
		{   0, 216,  32,  32 },
		{  32, 216,  40,  40 },
		{  72, 216,  40,  40 },
		{ 112, 216,  40,  40 },
		{ 152, 216,  40,  40 },
		{ 192, 216,  40,  40 }
	};
	static EFF5UVWHUC* pEff225UvInfoTop[4] = 
	{
		Eff225UvInfo1, Eff225UvInfo2, Eff225UvInfo3, Eff225UvInfo4
	};
	static int lEff225UvInfoMax[4] = 
	{
		11, 9, 13, 10
	};

    switch (op->mode0) 
    {                             
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 428;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->sxb = op->sx;
        op->syb = op->sy;
        
        op->ct0   = 0;
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (lEff225UvInfoMax[op->type] <= op->ct0) 
        {
            op->flg = 0;
            return;
        }
        
        break;
    }

    pInfo = &pEff225UvInfoTop[op->type][op->ct0];
    
    op->sx = 4.0f * (op->sxb * (pInfo->w / 256.0f));
    op->sy = 4.0f * (op->syb * (pInfo->h / 256.0f));
    
    op->tv[0].u = op->tv[2].u = pInfo->u                    / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + (pInfo->w - 1)) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v                    / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + (pInfo->h - 1)) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff226(O_WRK* op)
{
    EF_WORK* pEffect;
    int lLoop, lNumber;

    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0)
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0)
    {
    case 0:
        pEffect = &sys->ef;
        
        pEffect->flg = 1;
        
        pEffect->id = 227;
        
        pEffect->flr_no = 0;
        
        pEffect->px = op->px;
        pEffect->py = op->py;
        pEffect->pz = op->pz;
        
        pEffect->sx = op->sx;
        pEffect->sy = op->sx;
        pEffect->sz = 1.0f;
        
        pEffect->ax = pEffect->ay = 0;
        
        for (lLoop = 0; lLoop < 8; lLoop++) 
        {
            pEffect->type = (int)(2.0f * (-rand() / -2.1474836E9f));
            
            pEffect->mdlver = (unsigned char)lLoop;
            
            lNumber = bhSetEffectTb(pEffect, NULL, NULL, 0);
            
            if (lNumber != -1) 
            {
                eff[lNumber].exp0 = (unsigned char*)op;
            }
        } 
        
        op->mode0 = 1;
        op->mode1 = 0;
        break;
    }
}

// 100% matching!
void bhEff227(O_WRK* op) 
{
    EFF5UV* pInfo;
    O_WRK* opp;
	static EFF5UV Eff227UvInfo1[2][6] = 
	{
		{ 
		  {   0,   0 }, {  48,   0 }, {  96,   0 },
		  { 144,   0 }, { 192,   0 }, {   0,  48 } 
		},
		{ 
		  {  48,  48 }, {  96,  48 }, { 144,  48 },
		  { 192,  48 }, {   0,  96 }, {  48,  96 } 
		}
	};
	static EFF5UV Eff227UvInfo2[13] = 
	{
		{  96,  96 }, { 144,  96 }, { 192,  96 }, {   0, 144 }, 
		{  48, 144 }, {  96, 144 }, { 144, 144 }, { 192, 144 }, 
		{   0, 192 }, {  48, 192 }, {  96, 192 }, { 144, 192 },
		{ 192, 192 }
	};
    
    opp = (O_WRK*)op->exp0;
    
    switch (op->mode0) 
    {                      
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 413;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->ct0 = 0;
        
        pInfo = Eff227UvInfo1[op->type];
        
        op->mode0 = 1;
        break;
    case 1:
        if ((opp->stflg & 0x1000000)) 
        {
            op->flg = 0;
            return;
        }
        
        if (opp->mode1 == 1) 
        {
            op->ct0 = 0;
            
            pInfo = Eff227UvInfo2;
            
            op->mode0 = 2;
        } 
        else 
        {
            op->ct0++;
            
            if (op->ct0 >= 6) 
            {
                op->ct0 = 0;
            }
        
            pInfo = &Eff227UvInfo1[op->type][op->ct0];
        }
        
        break;
    case 2:
        op->ct0++;
        
        if (op->ct0 >= 13) 
        {
            op->flg = 0;
            return;
        }
        
        pInfo = &Eff227UvInfo2[op->ct0];
        break;
    }

    njPushMatrixEx();
    
    op->px = 0;
    op->py = 0;
    op->pz = opp->sy;
    
    njUnitMatrix(NULL);
    
    njRotateY(NULL, opp->ay);
    njRotateX(NULL, opp->ax);
    njRotateY(NULL, (op->mdlver * 0xFFFF) / 8);
    
    njCalcPoint(NULL, (NJS_POINT3*)&op->px, (NJS_POINT3*)&op->px);
    
    njPopMatrixEx();
    
    op->px += opp->px;
    op->py += opp->py;
    op->pz += opp->pz;
    
    op->sx = op->sy = opp->sx;
    op->sz = 1.0f;
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 47) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 47) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    } 
}

// 100% matching!
void bhEff228(O_WRK* op) 
{
    EF_WORK* pEffect;
    int lNumber;
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0) 
    {                           
    case 0:
        op->ct0 = 0;
        op->ct1 = 0;
        
        op->mode0 = 1;
    case 1:
        op->ct0++;
        
        if (op->lkono <= op->ct0) 
        {
            pEffect = &sys->ef;
            
            pEffect->flg = 1;
            
            pEffect->id   = 229;
            pEffect->type = 0;
            
            pEffect->flr_no = 2;
            
            pEffect->px = op->px;
            pEffect->py = op->py;
            pEffect->pz = op->pz;
            
            pEffect->sx = 3.0f * (op->sx / 4.0f);
            pEffect->sy = 3.0f * (op->sy / 4.0f);
            pEffect->sz = 3.0f * (op->sz / 4.0f);
            
            pEffect->ay = op->ay;
            pEffect->ax = op->ax;
            
            if ((op->ct1 % 3) == 0) 
            {
                pEffect->mdlver = 1;
            } 
            else 
            {
                pEffect->mdlver = 0;
            }
            
            op->ct1++;
            
            lNumber = bhSetEffectTb(pEffect, NULL, NULL, 0);
            
            if (lNumber != -1) 
            {
                eff[lNumber].az = 8192;
            }
            
            pEffect->flg = 0x4100001;
            
            pEffect->id   = 2;
            pEffect->type = 6;
            
            pEffect->flr_no = 2;
            
            pEffect->mdlver = 1;
            
            pEffect->px = 0;
            pEffect->py = 0;
            pEffect->pz = 1.5f;
            
            njPushMatrixEx();
            
            njUnitMatrix(NULL);
            
            njRotateY(NULL, op->ay);
            njRotateX(NULL, op->ax);
            
            njCalcPoint(NULL, (NJS_POINT3*)&pEffect->px, (NJS_POINT3*)&pEffect->px);
            
            njPopMatrixEx();
            
            pEffect->px += op->px;
            pEffect->py += op->py;
            pEffect->pz += op->pz;
            
            pEffect->sx = 2.5f * (op->sx / 4.0f);
            pEffect->sy = 2.5f * (op->sx / 4.0f);
            pEffect->sz = 2.5f * (op->sz / 4.0f);
            
            pEffect->ax = op->ax;
            pEffect->ay = op->ay;
            
            bhSetEffectTb(pEffect, NULL, NULL, 0);
            
            op->ct0 = 0;
        }
        
        break;
    }
}

// 100% matching!
void bhEff229(O_WRK* op)
{
    switch (op->mode0) 
    {                            
    case 0:
        op->tex_id = 3;
        
        op->func = (void*)bhDrawWeaponEffect2;
        
        op->tvp->col = -1;
        
        op->bl_src = 8;
        op->bl_dst = 10;
        
        op->ani_ct = 0;
        
        op->ct0 = op->ct1 = 0;
        
        op->mode0 = 1;
    case 1:
        if (op->ct0 != 1) 
        {
            op->spd = 0.8f;
        }
        else 
        {
            op->spd = 1.0f;
        }
        
        sys->ef_fnc[sys->ef_fncn++] = op;
        
        op->ct0++;
        
        if (op->ct0 >= op->flr_no) 
        {
            op->mode0 = 2;
        }
        
        break;
    case 2:
        op->flg = 0;
        break; 
    }
}

// 100% matching!
void bhDrawWeaponEffect2(O_WRK* op) 
{
    UV_WORK* uvp;         
    int i;                
    int ani;               
    NJS_TEXTURE_VTX tv[4], tvb[4];  
    float off;              
	static UV_WORK uvinfo_t01[2][6] = 
	{
		{
			{ 0.625f,         0.0f,   0.0625f,  0.0625f  },
			{ 0.796875f,   0.0625f,  0.09375f,  0.0625f  },
			{ 0.96875f,     0.125f,  0.03125f,  0.09375f },
			{ 0.21875f,    0.1875f,   0.0625f,  0.0625f  },
			{ 0.0f,        0.1875f,  0.09375f,  0.0625f  },
			{ 0.65625f,   0.34375f,   0.0625f,  0.125f   }
		},
		{
			{ 0.546875f,      0.0f,   0.0625f,   0.0625f  },
			{  0.90625f,   0.0625f,  0.09375f,   0.0625f  },
			{ 0.921875f,    0.125f,  0.03125f,   0.09375f },
			{ 0.296875f,   0.1875f,   0.0625f,   0.0625f  },
			{ 0.109375f,   0.1875f,  0.09375f,   0.0625f  },
			{  0.71875f,  0.34375f,   0.0625f,   0.125f   }
		}
	};
	static short akpal[2][3] = 
	{
		{ 0, 0, 1 }, { 0, 1, 1 }
	};

    njPushMatrixEx();
    
    njUnitMatrix(NULL);
    
    if ((op->flg & 0x20000000))
    {
        njTextureFilterMode(0);
    } 
    else
    {
        njTextureFilterMode(1);
    }
    
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[op->tex_id] + op->ani_ct);
    
    njSetMatrix(op->mtx, &((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
    
    njTranslate(op->mtx, op->lox, op->loy, op->loz);
    njRotateXYZ(op->mtx, op->ax,  op->ay,  op->az);
    
    njSetMatrix(NULL, cam.mtx);
    
    njMultiMatrix(NULL, op->mtx);
    njScale(NULL, op->sx, op->sx, op->sz);
    
    njColorBlendingMode(0, op->bl_src);
    njColorBlendingMode(1, op->bl_dst);

    for (i = 0; i < op->pn; i++) 
    {
        tv[i].col = tvb[i].col = op->tvp->col;
    }

    ani = op->ct0 - 1;
    
    njSetTextureNum(sys->ef_tn[op->tex_id] + akpal[0][ani]);
    
    if (op->mdlver != 0) 
    {
        off = 0.2f;
    } 
    else 
    {
        off = 0;
    }

    uvp = &uvinfo_t01[op->mdlver][ani * 3];

    tv[0].z = 0.3f;
    tv[0].y = -0.25f - off;
    tv[0].x = -0.25f - off;

    tv[1].z = 0.3f;
    tv[1].y = 0.25f + off;
    tv[1].x = -0.25f - off;
    
    tv[2].z = 0.3f;
    tv[2].y = -0.25f - off;
    tv[2].x = 0.25f + off;
    
    tv[3].z = 0.3f;
    tv[3].y = 0.25f + off;
    tv[3].x = 0.25f + off;
    
    tv[0].u = uvp->u;
    tv[0].v = uvp->v;
    
    tv[1].u = uvp->u + uvp->xs;
    tv[1].v = uvp->v;
    
    tv[2].u = uvp->u;
    tv[2].v = uvp->v + uvp->ys;
    
    tv[3].u = uvp->u + uvp->xs;
    tv[3].v = uvp->v + uvp->ys;

    njDrawTexture3DEx(tv, op->pn, 1);

    uvp = &uvinfo_t01[op->mdlver][(ani * 3) + 1];

    tv[0].z = 0;
    tv[0].y = 0;
    tv[0].x = -0.45f - off;
    
    tv[1].z = 1.5f;
    tv[1].y = 0;
    tv[1].x = -0.45f - off;
    
    tv[2].z = 0;
    tv[2].y = 0;
    tv[2].x = 0.45f + off;
    
    tv[3].z = 1.5f;
    tv[3].y = 0;
    tv[3].x = 0.45f + off;
    
    tv[1].u = uvp->u;
    tv[1].v = uvp->v;
    
    tv[0].u = uvp->u + uvp->xs;
    tv[0].v = uvp->v;
    
    tv[3].u = uvp->u;
    tv[3].v = uvp->v + uvp->ys;
    
    tv[2].u = uvp->u + uvp->xs;
    tv[2].v = uvp->v + uvp->ys;

    njDrawTexture3DEx(tv, op->pn, 1);

    tv[0].z = 0;
    tv[0].y = -0.45f - off;
    tv[0].x = 0;
    
    tv[1].z = 1.5f;
    tv[1].y = -0.45f - off;
    tv[1].x = 0;
    
    tv[2].z = 0;
    tv[2].y = 0.45f + off;
    tv[2].x = 0;
    
    tv[3].z = 1.5f;
    tv[3].y = 0.45f + off;
    tv[3].x = 0;

    njDrawTexture3DEx(tv, op->pn, 1);

    njSetTextureNum(sys->ef_tn[op->tex_id] + akpal[1][ani]);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 10);

    uvp = &uvinfo_t01[op->mdlver][(ani * 3) + 2];

    tv[0].z = 0.3f;
    tv[0].y = -0.2f - off;
    tv[0].x = -1.0f - off;
    
    tv[1].z = 0.3f;
    tv[1].y = 0.2f + off;
    tv[1].x = -1.0f - off;
    
    tv[2].z = 0;
    tv[2].y = -0.2f - off;
    tv[2].x = 0;
    
    tv[3].z = 0;
    tv[3].y = 0.2f + off;
    tv[3].x = 0;

    tvb[0].z = 0.1f - off;
    tvb[0].y = 0; 
    tvb[0].x = -1.0f - off;
     
    tvb[1].z = 0.5f + off;
    tvb[1].y = 0;
    tvb[1].x = -1.0f - off;
    
    tvb[2].z = -0.2f - off;
    tvb[2].y = 0; 
    tvb[2].x = 0;
    
    tvb[3].z = 0.2f + off;
    tvb[3].y = 0; 
    tvb[3].x = 0;

    tv[0].u = uvp->u;
    tv[0].v = uvp->v;
    
    tv[1].u = uvp->u + uvp->xs;
    tv[1].v = uvp->v;
    
    tv[2].u = uvp->u;
    tv[2].v = uvp->v + uvp->ys;
    
    tv[3].u = uvp->u + uvp->xs;
    tv[3].v = uvp->v + uvp->ys;
    
    tvb[0].u = uvp->u;
    tvb[0].v = uvp->v;
    
    tvb[1].u = uvp->u + uvp->xs;
    tvb[1].v = uvp->v;
    
    tvb[2].u = uvp->u;
    tvb[2].v = uvp->v + uvp->ys;
    
    tvb[3].u = uvp->u + uvp->xs;
    tvb[3].v = uvp->v + uvp->ys;

    if ((op->type == 2) || (op->mdlver != 0)) 
    {
        for (i = 0; i < 4; i++)
        { 
            njDrawTexture3DEx(tv,  op->pn, 1);
            njDrawTexture3DEx(tvb, op->pn, 1);
            
            njRotateZ(NULL, 16384);
        }
    } 
    else 
    {
        for (i = 0; i < 6; i++) 
        {
            njDrawTexture3DEx(tv,  op->pn, 1);
            njDrawTexture3DEx(tvb, op->pn, 1);
            
            njRotateZ(NULL, 10922);
        }
    }

    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    njPopMatrixEx();
}

// 100% matching!
void bhEff230(O_WRK* op) 
{
    EFF5UV* pInfo;
	static EFF5UV Eff230UvInfo1[8] = 
	{
		{   0, 32 }, {  32, 32 }, {  64, 32 }, {  96, 32 },
		{ 128, 32 }, { 160, 32 }, { 192, 32 }, { 224, 32 }
	};
	static EFF5UV Eff230UvInfo2[8] = 
	{
		{   0, 64 }, {  32, 64 }, {  64, 64 }, {  96, 64 },
		{ 128, 64 }, { 160, 64 }, { 192, 64 }, { 224, 64 }
	};
	static EFF5UV Eff230UvInfo3[8] =
	{
		{   0, 96 }, {  32, 96 }, {  64, 96 }, {  96, 96 },
		{ 128, 96 }, { 160, 96 }, { 192, 96 }, { 224, 96 }
	};
	static EFF5UV Eff230UvInfo4[3] = 
	{
		{  0,  0 }, { 32,  0 }, { 64,  0 }
	};
	static EFF5UV* pEff230UvInfoTop[4] = 
	{
		Eff230UvInfo1, Eff230UvInfo2, Eff230UvInfo3, Eff230UvInfo4
	};
	static unsigned int ulEff230UvInfoMax[4] = 
	{
		8, 8, 8, 3
	};

    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0) 
    {                         
    case 0:
        op->flg |= 0x4080000;
        
        op->tex_id = 414;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->ct0 = 0;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (ulEff230UvInfoMax[op->lkono % 4] <= op->ct0) 
        { 
            op->ct0 = 0;
        }
        
        break;
    }
    
    op->ani_ct = (op->type - 1) % 6;
    
    pInfo = &pEff230UvInfoTop[op->lkono % 4][op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 31) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 31) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff231(O_WRK* op) 
{
    EF_WORK* pEffect;
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    pEffect = &sys->ef;
    
    pEffect->flg = 1;
    
    pEffect->id = 232;
    
    pEffect->type = (op->type - 1) % 4; 
    
    pEffect->flr_no = 0;

    pEffect->mdlver = 0;
    
    pEffect->px = op->px;
    pEffect->py = op->py;
    pEffect->pz = op->pz;
    
    pEffect->sx = op->sx;
    pEffect->sy = op->sy;
    pEffect->sz = 1.0f;
    
    pEffect->ay = op->ay;
    pEffect->ax = op->ax;
    
    if (!op->sz) 
    {
        bhSetEffectTb(pEffect, NULL, NULL, 0);
        
        op->mode1 = op->type = 0;
        return; 
    }
    
    if (op->ct1 <= 0) 
    {
        bhSetEffectTb(pEffect, NULL, NULL, 0);
        
        op->ct1 = op->sz;
    }
    
    op->ct1--;
}

// 100% matching!
void bhEff232(O_WRK* op) 
{
    EFF5UV* pInfo;
    static EFF5UV Eff232UvInfo[2][10] = 
    {
        { {   0,   0 }, {  40,   0 }, {  80,   0 }, { 120,   0 },
          { 160,   0 }, { 200,   0 }, {   0,  40 }, {  40,  40 },
          {  80,  40 }, { 120,  40 } },
        { {   0,  80 }, {  40,  80 }, {  80,  80 }, { 120,  80 },
          { 160,  80 }, { 200,  80 }, {   0, 120 }, {  40, 120 },
          {  80, 120 }, { 120, 120 } }
    };

    switch (op->mode0)
    {                            
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 415;
        
        op->ani_ct = op->type / 2;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->ct0   = 0;
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 10) 
        {
            op->flg = 0;
            return;
        }
        
        break;
    }

    pInfo = &Eff232UvInfo[op->type % 2][op->ct0];

    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 39) / 256.0f;
    
	op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 39) / 256.0f;

    if (sys->ef_trsn < 512)
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 98.17% matching (matches on NGC)
void bhEff233(O_WRK* op)
{
    EFF5UV* pInfo;
	static EFF5UV Eff233UvInfo[4] = 
	{
		{ 0,  0 }, { 0, 32 }, { 0, 64 }, { 0, 96 }
	};
	static float fLeft[3] = 
	{
		-1.0f, 0.0f, -2.0f
	};
	static float fRight[3] = 
	{
		1.0f, 2.0f, 0.0f
	};
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    if (op->sz < 1.0f)
    {
        op->sz = 1.0f;
    }
    
    switch (op->mode0) 
    {                         
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 416;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->tv[0].x = op->tv[2].x = fLeft[op->lkono  % 3];
        op->tv[1].x = op->tv[3].x = fRight[op->lkono % 3];
        
        op->tv[0].y = op->tv[1].y = -1.0f;
        op->tv[2].y = op->tv[3].y = 1.0f;
        
        op->tv[0].z = op->tv[1].z = op->tv[2].z = op->tv[3].z = 0;
        
        op->ct0   = 0;
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (((int)op->sz * 4) <= op->ct0) 
        {
            op->mode1 = 0;
            op->type = op->mode0 = 0;
            return;
        }
        
        break;
    }
        
    op->az = op->ax;
    
    pInfo = &Eff233UvInfo[op->ct0 / (int)op->sz];
    
    op->tv[0].u = op->tv[2].u = pInfo->u         / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 223) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v         / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 32)  / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 99.42% matching (matches on NGC)
void bhEff234(O_WRK* op) 
{
    EFF5UV* pInfo;
	static EFF5UV Eff234UvInfo1[2][6] = 
	{
		{
			{   0,   0 }, {  48,   0 }, {  96,   0 },
			{ 144,   0 }, { 192,   0 }, {   0,  48 }
		},
		{
			{  48,  48 }, {  96,  48 }, { 144,  48 },
			{ 192,  48 }, {   0,  96 }, {  48,  96 }
		}
	};
	static EFF5UV Eff234UvInfo2[13] = 
	{
		{  96,  96 }, { 144,  96 }, { 192,  96 }, {   0, 144 },
		{  48, 144 }, {  96, 144 }, { 144, 144 }, { 192, 144 },
		{   0, 192 }, {  48, 192 }, {  96, 192 }, { 144, 192 },
		{ 192, 192 }
	};
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0) 
    {                           
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 413;
        
        op->ani_ct = 1;
        
        op->bl_src = 8;
        op->bl_dst = 6;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->ct0 = 0;
        
        pInfo = Eff234UvInfo1[(op->type - 1) % 2];
        
        op->mode0 = 1;
        break;
    case 1:
        if (op->mode1 == 1) 
        {
            op->ct0 = 0;
            
            pInfo = Eff234UvInfo2;
            
            op->mode0 = 2;
        } 
        else 
        {
            op->ct0++;
            
            if (op->ct0 >= 6) 
            {
                op->ct0 = 0;
            }
            
            pInfo = &Eff234UvInfo1[(op->type - 1) % 2][op->ct0];
        }
        
        break;
    case 2:
        op->ct0++;
        
        if (((int)op->sz * 13) <= op->ct0) 
        {
            op->flg = 0;
            return;
        }
        
        pInfo = &Eff234UvInfo2[op->ct0 / (int)op->sz];
        break;
    }

    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 47) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 47) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 98.93% matching (matches on NGC)
void bhEff235(O_WRK* op) 
{
    int lType; 
    int lCnt; // not from DWARF
    int lMode;  
    int lColor; 
    static unsigned int ulColor[3] =
    {
        0xFFFFFFFF, 0xFFFF0000, 0xFF0000FF
    };
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    lType = op->type - 1;
    
    lMode  = lType        % 2;
    lCnt   = (lType / 2)  % 6;
    lColor = (lType / 12) % 3;

    switch (op->mode0) 
    {                          
    case 0:
        op->flg |= 0x4080000;
        
        op->tex_id = 418;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = op->ct1 = 0;
        
        op->mode0 = 1;
    case 1:
        if (lMode == 0) 
        {
            if (op->sz < 1.0f) 
            {
                op->sz = 1.0f;
            }
            
            op->ct1 = (op->ct0 * 3) / (int)op->sz;
            op->ct0++;
            
            if ((int)op->sz <= op->ct0) 
            {
                op->ct0 = 0;
            }
        }
        
        break;
    }
    
    op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = ulColor[lColor];
    
    if (lMode == 1) 
    {
        op->tv[0].u = op->tv[2].u = 0.703125f;
        op->tv[1].u = op->tv[3].u = 0.93359375f;
    } 
    else 
    {
        op->tv[0].u = op->tv[2].u = (op->ct1  * 60)       / 256.0f;
        op->tv[1].u = op->tv[3].u = ((op->ct1 * 60) + 59) / 256.0f;
    }
    
    op->tv[2].v = op->tv[3].v = (lCnt  * 40)       / 256.0f;
    op->tv[0].v = op->tv[1].v = ((lCnt * 40) + 39) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff236(O_WRK* op)
{
    EFF5UV* pInfo;  
    int lType;      
    BH_PWORK* pp;  
    NJS_POINT3 Tmp; 
    float px, py, pz; // not from DWARF
	static EFF5UV Eff236UvInfo1[8] = 
	{
		{   0,   0 }, {  32,   0 }, {  64,   0 }, {  96,   0 },
		{ 128,   0 }, { 160,   0 }, { 192,   0 }, { 224,   0 }
	};
	static EFF5UV Eff236UvInfo2[12] = 
	{
		{   0,  48 }, {  32,  48 }, {  64,  48 }, {  96,  48 },
		{ 128,  48 }, { 160,  48 }, { 192,  48 }, { 224,  48 },
		{   0,  96 }, {  32,  96 }, {  64,  96 }, {  96,  96 }
	};
	static EFF5UV Eff236UvInfo3[20] = 
	{
		{ 128,  96 }, { 160,  96 }, { 192,  96 }, { 224,  96 },
		{   0, 144 }, {  32, 144 }, {  64, 144 }, {  96, 144 },
		{ 128, 144 }, { 160, 144 }, { 192, 144 }, { 224, 144 },
		{   0, 192 }, {  32, 192 }, {  64, 192 }, {  96, 192 },
		{ 128, 192 }, { 160, 192 }, { 192, 192 }, { 224, 192 }
	};
	static EFF5UV* pEff236UvInfoTop[3] = 
	{
		Eff236UvInfo1, Eff236UvInfo2, Eff236UvInfo3
	};
	static int lEff236UvInfoMax[3] = 
	{
		8, 12, 20
	};

    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    if (op->ax < 0) 
    {
        pp = plp;
    } 
    else 
    {
        pp = &ene[rom->enep[op->ax % rom->ene_n].wrk_no];
    }
    
    if (pp != NULL) 
    {
        lType = (op->type - 1) % 3;
        
        switch (op->mode0) 
        {
        case 0:
            op->flg |= 0x4080000;
            
            op->tex_id = 419;
            
            op->ani_ct = 0;
            
            op->bl_src = 8;
            op->bl_dst = 3;
            
            op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
            
            op->func = (void*)bhDrawEff236;
            
            op->ct0 = op->ct1 = 0;
            
            op->mode0 = 1;
            break;
        }
        
        njPushMatrixEx();
        
        op->tv[0].x = -op->sz;
        op->tv[1].x = op->sz;
        
        op->tv[0].y = 0;
        op->tv[1].y = 0;
        
        op->tv[0].z = 0;
        op->tv[1].z = 0;
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, op->ay);
        njCalcPoint(NULL, (NJS_POINT3*)&op->tv[0].x, &Tmp);
        
        op->tv[0].x = Tmp.x + op->px;
        op->tv[0].y = Tmp.y + op->py;
        op->tv[0].z = Tmp.z + op->pz;
        
        njCalcPoint(NULL, (NJS_POINT3*)&op->tv[1].x, &Tmp);
        
        op->tv[1].x = Tmp.x + op->px;
        op->tv[1].y = Tmp.y + op->py;
        op->tv[1].z = Tmp.z + op->pz;
        
        px = pp->mlwP->owP[1].mtx[12];
        py = pp->mlwP->owP[1].mtx[13];
        pz = pp->mlwP->owP[1].mtx[14];
        
        op->tv[2].x = op->sx - op->sz;
        op->tv[3].x = op->sx + op->sz;
        
        op->tv[3].y = op->tv[2].y = op->sy;
        op->tv[3].z = op->tv[2].z = 0;
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, pp->ay);
        njCalcPoint(NULL, (NJS_POINT3*)&op->tv[2].x, &Tmp);
        
        op->tv[2].x = Tmp.x + px;
        op->tv[2].y = Tmp.y + py;
        op->tv[2].z = Tmp.z + pz;
        
        njCalcPoint(NULL, (NJS_POINT3*)&op->tv[3].x, &Tmp);
        
        op->tv[3].x = Tmp.x + px;
        op->tv[3].y = Tmp.y + py;
        op->tv[3].z = Tmp.z + pz;
        
        njPopMatrixEx();
        
        if (op->ct0 <= op->lkono) 
        {
            op->ct1 = (op->ct0 * (lEff236UvInfoMax[lType] - 1)) / op->lkono;
            op->ct0++;
        }
        
        pInfo = &pEff236UvInfoTop[lType][op->ct1];
        
        op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
        op->tv[1].u = op->tv[3].u = (pInfo->u + 31) / 256.0f;
        
        op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
        op->tv[2].v = op->tv[3].v = (pInfo->v + 47) / 256.0f;
        
        if (sys->ef_fncn < 128) 
        {
            sys->ef_fnc[sys->ef_fncn] = op;
            
            sys->ef_fncn++;
        }
    }
}

// 100% matching!
void bhDrawEff236(O_WRK* op)
{
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[op->tex_id] + op->ani_ct);
    
    njTextureFilterMode(1);
    
    njColorBlendingMode(0, op->bl_src);
    njColorBlendingMode(1, op->bl_dst);
    
    njDrawTexture3DEx(op->tvp, 4, 1);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
}

// 100% matching!
void bhEff237(O_WRK* op)
{
    EFF5UV* pInfo;
	static EFF5UV Eff237UvInfo[16] = 
	{
		{   0,   0 }, {  64,   0 }, { 128,   0 }, { 192,   0 },
		{   0,  64 }, {  64,  64 }, { 128,  64 }, { 192,  64 },
		{   0, 128 }, {  64, 128 }, { 128, 128 }, { 192, 128 },
		{   0, 192 }, {  64, 192 }, { 128, 192 }, { 192, 192 }
	};

    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0)
    {                             
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 420;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = 0;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->xn = op->yn = 0;
        op->zn = op->sz / 10.0f;
        
        njPushMatrixEx();
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, op->ay);
        njRotateX(NULL, op->ax);
        
        njCalcPoint(NULL, (NJS_POINT3*)&op->xn, (NJS_POINT3*)&op->xn);
        
        njPopMatrixEx();
        
        op->lox = op->px;
        op->loy = op->py;
        op->loz = op->pz;
        
        op->mode0 = 1;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 16) 
        {
            op->px = op->lox;
            op->py = op->loy;
            op->pz = op->loz;
            
            op->mode1 = 0;
            op->type = op->mode0 = 0;
            return;
        }
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->yn -= 0.0489f;
        break;
    }

    pInfo = &Eff237UvInfo[op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 63) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 63) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff238(O_WRK* op) 
{
    EF_WORK* pEffect;
    int lNumber;
    O_WRK* opp;
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->mode0 = 0;
        
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0) 
    {                         
    case 0:
        op->ct0   = 0;
        op->mode0 = 1;
    case 1:
        pEffect = &sys->ef;
        
        pEffect->flg = 1;
        
        pEffect->id   = 239;
        pEffect->type = 0;
        
        pEffect->flr_no = 0;
        
        pEffect->px = op->px;
        pEffect->py = op->py;
        pEffect->pz = op->pz;
        
        pEffect->mdlver = 0;
        
        pEffect->sx = op->sx;
        pEffect->sy = op->sy;
        pEffect->sz = 1.0f;
        
        pEffect->ax = op->ax;
        pEffect->ay = op->ay;
        
        lNumber = bhSetEffectTb(pEffect, NULL, NULL, 0);
        
        if (lNumber != -1) 
        {
            opp = &eff[lNumber];
            
            opp->xn = opp->yn = 0;
            opp->zn = (((double)-op->sz / 4.0) * 1.2) / 10.0;
            
            njPushMatrixEx();
            
            njUnitMatrix(NULL);
            
            if ((!(op->flg & 0x80)) || ((op->flg & 0x200000)))
            {
                njRotateY(NULL, op->ay);
                njRotateX(NULL, op->ax);
            } 
            else
            {
                njSetMatrix(NULL, &((O_WRK*)op->lkwkp)->mlwP->owP[op->lkono].mtx);
                
                njUnitTransPortion(NULL); 
                
                njRotateY(NULL, op->ay);
                njRotateX(NULL, op->ax);
            }
            
            njCalcPoint(NULL, (NJS_POINT3*)&opp->xn, (NJS_POINT3*)&opp->xn);
            
            njPopMatrixEx();
        }
        
        if (op->type == 0xFF) 
        {
            op->type = op->mode0 = 0;
            break;
        }
        
        op->mode0 = 2;
        break;
    case 2:
        op->ct0++;
        
        if (op->type <= op->ct0) 
        {
            op->ct0   = 0;
            op->mode0 = 1;
        }
        
        break;
    }
}

// 99.49% matching (matches on NGC)
void bhEff239(O_WRK* op) 
{
    EFF5UV* pInfo;
    int lAlpha;
	static EFF5UV Eff239UvInfo[15] = 
	{
		{   0,   0 }, {  16,   0 }, {   0,  16 }, {  16,  16 },
		{  32,   0 }, {  64,   0 }, {  96,   0 }, { 128,   0 },
		{ 160,   0 }, { 192,   0 }, { 224,   0 }, {   0,  32 },
		{  48,  32 }, {  96,  32 }, {   0,  80 }
	};
	static float fEff239Size[15] = 
	{
		0.0625f, 0.0625f, 0.0625f, 0.0625f,
		 0.125f,  0.125f,  0.125f,  0.125f,
		 0.125f,  0.125f,  0.125f, 0.1875f, 
		0.1875f, 0.1875f, 0.1875f
	};
    
    switch (op->mode0) 
    {
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 2;
        
        op->ani_ct = 1;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = op->mdlver;
        
        op->sxb = op->sx;
        op->spd = op->sy;
        
        op->mode0 = 1;
        break;
    }
    
    op->ct0++;
    
    if (op->ct0 >= 15)
    {
        op->flg = 0;
        return;
    }
    
    op->sx = op->sy = 0.8f * (op->sxb * fEff239Size[op->ct0]);
    
    lAlpha = 16.0f * op->spd;
    lAlpha -= (lAlpha * op->ct0) / 15;
    
    if (lAlpha < 0) 
    {
        lAlpha = 0;
    } 
    else if (lAlpha > 0xFF) 
    {
        lAlpha = 0xFF;
    }
    
    if (op->ct0 == 12)
    {
        lAlpha = (lAlpha * 3) / 4;
    } 
    else if (op->ct0 == 13) 
    {
        lAlpha = (lAlpha * 2) / 4;
    } 
    else if (op->ct0 == 14) 
    {
        lAlpha /= 4;
    }
    
    op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = (lAlpha << 24) + 0xFFFFFF;
    
    op->px += op->xn;
    op->py += op->yn;
    op->pz += op->zn;
    
    op->xn *= 0.97f;
    op->yn *= 0.97f;
    op->zn *= 0.97f;
    
    pInfo = &Eff239UvInfo[op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u  / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u / 256.0f) + fEff239Size[op->ct0];
    
    op->tv[0].v = op->tv[1].v = pInfo->v  / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v / 256.0f) + fEff239Size[op->ct0];
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 99.87% matching (matches on NGC)
void bhEff240(O_WRK* op)
{
    NJS_VECTOR vc0, vc1; 
    int i, j;        
    int ct;     
    float r;       
    float spd;     
    float xn, yn;      
    float spq;      
    int lNumber;    
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    ct = op->lkono;
    
    r   = op->sy;
    spd = op->sz;
    
    sys->ef.sx = sys->ef.sy = sys->ef.sz = op->sx;
    
    vc0.x = vc0.y = 0;
    vc0.z = -1.0f;
    
    sys->ef.id = 221;
    
    sys->ef.flg = 1;
    
    sys->ef.type = op->type;
    
    if (((op->type - 1) % 2) != 0) 
    {
        sys->ef.flr_no = 0;
    } 
    else 
    {
        sys->ef.flr_no = 2;
    }
    
    spq = fabsf(njSqrt(ct));
    
    xn = 120.0f / spq;
    yn = 140.0f / spq;
    
    j = spq;
    
    for (i = 0; i < ct; i++) 
    {
        sys->ef.ax = op->ax + ((int)(182.04445f * (((30.0f * (-rand() / -2.1474836E9f)) - 15.0f) + ((xn * ((i + 1) / j)) - 60.0f))) & 0xFFFF);
        sys->ef.ay = op->ay + ((int)(182.04445f * (((30.0f * (-rand() / -2.1474836E9f)) - 15.0f) + ((yn * ((i + 1) % j)) - 70.0f))) & 0xFFFF);
        
        sys->ef.mdlver = (unsigned char)((i * 4) % 55);
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, sys->ef.ax, sys->ef.ay, 0);
        njCalcVector(NULL, &vc0, &vc1);
        
        sys->ef.px = op->px + (vc1.x * r);
        sys->ef.py = op->py + (vc1.y * r);
        sys->ef.pz = op->pz + (vc1.z * r);
        
        vc1.x *= spd;
        vc1.y *= spd;
        vc1.z *= spd;
        
        lNumber = bhSetEffectTb(&sys->ef, &vc1, NULL, 0);
        
        if (lNumber != -1) 
        {
            eff[lNumber].tex_id = 421;
        }
    } 
    
    op->type = op->mode1 = 0;
}

// 100% matching!
void bhEff241(O_WRK* op) 
{
    EF_WORK* pEffect;
    int lLoop;

    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    for (lLoop = 0; lLoop < op->lkono; lLoop++)
    {
        pEffect = &sys->ef;
    
        pEffect->flg = 1;
        
        pEffect->id = 242;

        pEffect->type = op->type - 1; 
    
        pEffect->flr_no = 0;

        pEffect->mdlver = 0;
    
        pEffect->ax = op->ax;
        pEffect->ay = op->ay;
        
        pEffect->px = op->px;
        pEffect->py = op->py;
        pEffect->pz = op->pz;
        
        pEffect->sx = op->sx;
        pEffect->sy = op->sy;
        pEffect->sz = op->sz;
        
        bhSetEffectTb(pEffect, NULL, NULL, 0);
    }
    
    op->mode1 = 0;
    
    op->type = op->mode0 = 0;
}

// 99.95% matching
void bhEff242(O_WRK* op) 
{
    EFF5UV* pInfo;   
    float fScale, fRadius, fChoak;     
    float fBaseSpeed, fDeviSpeed; 
    float fSizeW, fSizeH;     
	static EFF5UV Eff242UvInfo1[37] = 
	{
		{   0,   0 }, {   0,   8 }, {   0,  16 }, {   0,  24 },
		{   8,   0 }, {   8,   8 }, {   8,  16 }, {   8,  24 },
		{  24,   0 }, {  40,   0 }, {  56,   0 }, {  72,   0 },
		{  88,   0 }, { 104,   0 }, { 120,   0 }, { 136,   0 },
		{ 152,   0 }, {  24,  16 }, {  40,  16 }, {  56,  16 },
		{  72,  16 }, {  88,  16 }, { 104,  16 }, { 120,  16 },
		{ 136,  16 }, { 152,  16 }, { 168,   0 }, { 192,   0 },
		{ 216,   0 }, { 168,  16 }, { 192,  16 }, { 216,  16 },
		{   0,  32 }, {  24,  32 }, {  48,  32 }, {  72,  32 },
		{  96,  32 }
	};
	static EFF5UV Eff242UvInfo2[31] = 
	{
		{ 168,  64 }, { 168,  72 }, { 168,  80 }, { 168,  88 },
		{ 120,  32 }, { 120,  40 }, { 120,  48 }, { 120,  56 },
		{ 136,  32 }, { 152,  32 }, { 168,  32 }, { 184,  32 },
		{ 200,  32 }, { 216,  32 }, { 136,  48 }, { 152,  48 },
		{ 168,  48 }, { 184,  48 }, { 200,  48 }, { 216,  48 },
		{ 232,  32 }, {   0,  64 }, {  24,  64 }, { 232,  48 },
		{   0,  80 }, {  24,  80 }, {  48,  64 }, {  72,  64 },
		{  96,  64 }, { 120,  64 }, { 144,  64 }
	};
	static EFF5UV* pEff242UvInfoTop[2] = 
	{
		Eff242UvInfo1, Eff242UvInfo2
	};
	static int lEff242UvInfoMax[2] = 
	{
		37, 31
	};
    
    switch (op->mode0) 
    {                         
    case 0:
        op->flg |= 0x4080000;

        op->tex_id = 422;
        
        op->ani_ct = op->type % 2;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        fScale  = op->sx;
        fRadius = floorf(op->sy) / 10.0f;
        fChoak  = 81920.0f * ((op->sy - floorf(op->sy)) / 9.0f);
        
        fBaseSpeed = floorf(op->sz) / 10.0f;
        fDeviSpeed = 10.0f * ((op->sz - floorf(op->sz)) / 9.0f);
        
        op->ct0 = lEff242UvInfoMax[op->ani_ct] * (-rand() / -2.1474836E9f);
        
        if (op->ani_ct == 0) 
        {
            if (op->ct0 < 4)
            {
                fSizeW = 0.03125f;
                fSizeH = 0.03125f;
            }
            else if (op->ct0 < 8) 
            {
                fSizeW = 0.0625f;
                fSizeH = 0.03125f;
            }
            else if (op->ct0 < 26) 
            {
                fSizeW = 0.0625f;
                fSizeH = 0.0625f;
            } 
            else if (op->ct0 < 32) 
            {
                fSizeW = 0.09375f;
                fSizeH = 0.0625f;
            } 
            else if (op->ct0 < 34) 
            {
                fSizeW = 0.09375f;
                fSizeH = 0.09375f;
            }
            else 
            {
                fSizeW = 0.09375f;
                fSizeH = 0.125f;
            }
        }
        else 
        {
            if (op->ct0 < 4) 
            {
                fSizeW = 0.03125f;
                fSizeH = 0.03125f;
            } 
            else if (op->ct0 < 8) 
            {
                fSizeW = 0.0625f;
                fSizeH = 0.03125f;
            } 
            else if (op->ct0 < 20)
            {
                fSizeW = 0.0625f;
                fSizeH = 0.0625f;
            } 
            else if (op->ct0 < 26)
            {
                fSizeW = 0.09375f;
                fSizeH = 0.0625f;
            } 
            else if (op->ct0 < 28) 
            {
                fSizeW = 0.09375f;
                fSizeH = 0.09375f;
            } 
            else 
            {
                fSizeW = 0.09375f;
                fSizeH = 0.125f;
            }
        }
        
        op->sxb = fSizeW;
        op->syb = fSizeH;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->sx = (op->sxb * fScale) / 4.0f;
        op->sy = (op->syb * fScale) / 4.0f;
        op->sz = 1.0f;
        
        njPushMatrixEx();
        
        op->lox = op->loz = 0;
        op->loy = fRadius * (-rand() / -2.1474836E9f);
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, op->ay);
        njRotateX(NULL, op->ax);
        njRotateZ(NULL, 65536.0f * (-rand() / -2.1474836E9f));
        
        njCalcPoint(NULL, (NJS_POINT3*)&op->lox, (NJS_POINT3*)&op->lox);
        
        op->px += op->lox;
        op->py += op->loy;
        op->pz += op->loz;
        
        op->xn = op->yn = 0;
        op->zn = fBaseSpeed - (fDeviSpeed * ((fBaseSpeed * (-rand() / -2.1474836E9f)) * (-rand() / -2.1474836E9f)));
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, op->ay);
        njRotateX(NULL, op->ax);
        
        njRotateZ(NULL, 65536.0f * (-rand() / -2.1474836E9f));
        njRotateX(NULL, fChoak);
        
        njCalcPoint(NULL, (NJS_POINT3*)&op->xn, (NJS_POINT3*)&op->xn);
        
        njPopMatrixEx();
        
        op->az = 0;
        
        op->aox = 2048.0f + (8192.0f * (-rand() / -2.1474836E9f));
        op->aoy = 2048.0f + (8192.0f * (-rand() / -2.1474836E9f)); 
        op->aoz = 2048.0f + (8192.0f * (-rand() / -2.1474836E9f));
        
        op->spd = op->py - 20.0f;
        
        op->mode0 = 1;
        break;
    case 1:
        if (op->py < op->spd) 
        {
            op->flg = 0;
            return;
        }
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->yn -= 0.0489f;
        
        njPushMatrixEx();
        
        njUnitMatrix(NULL);
        
        njRotateY(NULL, op->ay);
        njRotateX(NULL, op->ax);
        njRotateZ(NULL, op->az);
        
        njCalcPoint(NULL, (NJS_POINT3*)&op->xn, (NJS_POINT3*)&op->lox);
        
        njPopMatrixEx();
        
        op->xn += op->lox / 10.0f;
        op->yn += op->loy / 10.0f;
        op->zn += op->loz / 10.0f;
        
        op->xn *= 0.92f;
        op->yn *= 0.92f;
        op->zn *= 0.92f;
        
        op->ax += (int)op->aox;
        op->ay += (int)op->aoy;
        op->az += (int)op->aoz;
        
        op->aox *= 0.99f;
        op->aoy *= 0.99f;
        op->aoz *= 0.99f;
        break;
    }

    pInfo = &pEff242UvInfoTop[op->ani_ct][op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u  / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u / 256.0f) + op->sxb;
    
    op->tv[0].v = op->tv[1].v = pInfo->v  / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v / 256.0f) + op->syb;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff243(O_WRK* op) 
{
    EFF5UV* pInfo; 
	int lType;    
	static EFF5UV Eff243UvInfo1[4] = 
	{
		{   0,   0 }, {  64,   0 }, { 128,   0 }, { 192,   0 }
	};
	static EFF5UV Eff243UvInfo2[12] = 
	{
		{   0,  32 }, {  64,  32 }, { 128,  32 }, { 192,  32 },
		{   0,  64 }, {  64,  64 }, { 128,  64 }, { 192,  64 },
		{   0,  96 }, {  64,  96 }, { 128,  96 }, { 192,  96 }
	};
	static EFF5UV* pEff243UvInfoTop[2] = 
	{
		Eff243UvInfo1, Eff243UvInfo2
	};
	static const unsigned int ulColor[7] = 
	{
		0xFF0000FF, 0xFF00FF00, 0xFF00FFFF, 0xFFFF0000,
        0xFFFF00FF, 0xFFFFFF00, 0xFFFFFFFF
	};
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    lType = (op->type - 1) % 2;
    
    switch (op->mode0) 
    {                     
    case 0:
        op->flg |= 0x4080000;
        
        op->tex_id = 423;
        
        op->ani_ct = 0;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->tv[0].x = op->tv[1].x = -0.125f;
        op->tv[2].x = op->tv[3].x = 0.125f;
        
        op->tv[0].y = op->tv[1].y = op->tv[2].y = op->tv[3].y = 0;
        
        op->tv[0].z = op->tv[2].z = 0;
        op->tv[1].z = op->tv[3].z = 0.5f;
        
        op->ct0 = op->ct1 = op->ct2 = 0;
        
        op->func = (void*)bhDrawEff243;
        
        op->mode0 = 1;
    case 1:
        if (lType == 0) 
        {
            op->ct0++;
            
            if (op->ct0 >= 4) 
            {
                op->ct0 = 0;
            }
            
            op->ct2 = op->ct0;
            break;
        }
        
        op->ct1++;
        
        if (op->ct1 >= 12) 
        {
            op->mode1 = 0;
            op->type = op->mode0 = 0;
            return;
        }

        op->ct2 = op->ct1;
        break;
    }
    
    njPushMatrixEx();

    {
    NJS_POINT3 VecY = { 0.0f, 1.0f, 0.0f }; 
    NJS_POINT3 VecZ = { 0.0f, 0.0f, 1.0f }; 
    
    njSetMatrix(NULL, cam.mtx);
    
    njRotateY(NULL, op->ay);
    njRotateX(NULL, op->ax);
    
    njCalcVector(NULL, &VecY, &VecY);
    njCalcVector(NULL, &VecZ, &VecZ);
    
    njUnitMatrix(NULL);
    
    njRotateZ(NULL, -((int)(10430.381f * atan2f(VecZ.y, VecZ.x)) + 16384));
    
    njCalcVector(NULL, &VecY, &VecY);
    
    op->az = (int)(10430.381f * atan2f(VecY.x, VecY.z)) - 32768;
    
    njPopMatrixEx();
    
    op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = ulColor[op->lkono % 7];
    
    pInfo = &pEff243UvInfoTop[lType][op->ct2];
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 63) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 31) / 256.0f;
    
    if (sys->ef_fncn < 128) 
    {
        sys->ef_fnc[sys->ef_fncn] = op;
        
        sys->ef_fncn++;
    }
    }
}

// 100% matching!
void bhDrawEff243(O_WRK* op)
{
    njSetTexture(&sys->ef_tlist);
    njSetTextureNum(sys->ef_tn[op->tex_id] + op->ani_ct);
    
    njTextureFilterMode(1);
    
    njColorBlendingMode(0, op->bl_src);
    njColorBlendingMode(1, op->bl_dst);
    
    njPushMatrixEx();
    njTranslateEx((NJS_VECTOR*)&op->px);
    
    njRotateY(NULL, op->ay);
    njRotateX(NULL, op->ax);
    njRotateZ(NULL, op->az);
    
    njScaleEx((NJS_VECTOR*)&op->sx);
    
    njDrawTexture3DEx(op->tvp, 4, 1);
    
    njPopMatrixEx();
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
}

// 99.13% matching (matches on NGC)
void bhEff244(O_WRK* op) 
{
    EFF5UV* pInfo;
    int lType, lColor;
	static EFF5UV Eff244UvInfo1[2] = 
	{
		{  0, 136 }, { 48, 136 }
	};
	static EFF5UV Eff244UvInfo2[3] = 
	{
		{  0, 196 }, { 32, 196 }, { 64, 196 }
	};
	static float fEff244Size[2] = 
	{
		0.1875f, 0.125f
	};
	static EFF5UV* pEff244UvInfoTop[2] = 
	{
		Eff244UvInfo1, Eff244UvInfo2
	};
	static int lEff244UvInfoMax[2] = 
	{
		2, 3
	};
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    lType  = ((op->type - 1) / 4) % 2;
    lColor = (op->type  - 1)      % 4;
    
    switch (op->mode0) 
    {                    
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 424;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->ct0 = op->ct1 = 0;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->mode0 = 1;
    case 1:
        op->ani_ct = lColor;
        
        if (op->sz < 1.0f) 
        {
            op->sz = 1.0f;
        }
        
        op->ct0++;
        
        if ((int)op->sz <= op->ct0) 
        {
            op->ct0 = 0;
        }
        
        op->ct1 = (op->ct0 * lEff244UvInfoMax[lType]) / (int)op->sz;
        break;
    }
    
    pInfo = &pEff244UvInfoTop[lType][op->ct1];
    
    op->tv[0].u = op->tv[2].u = pInfo->u  / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u / 256.0f) + fEff244Size[lType];
    
    op->tv[0].v = op->tv[1].v = pInfo->v  / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v / 256.0f) + fEff244Size[lType];
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff245(O_WRK* op) 
{
    EF_WORK* pEffect;
    int lType;
    int lNumber;
    
    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    lType = (op->type - 1) / 2;
    
    switch (lType) 
    {    
    case 0:
        break;
    case 1:                                      
        switch (op->mode0) 
        {                       
        case 0:                                   
            op->ct0   = 0;
            op->mode0 = 1;
            break;
        case 1:                              
            op->ct0++;
            
            if (op->ct0 < op->lkono) 
            {
                return;
            }
            
            op->ct0 = 0;
            break;
        }
        
        break;
    }
    
    pEffect = &sys->ef;
    
    pEffect->flg = 1;
    
    pEffect->id = 246;

    pEffect->type = lType; 

    pEffect->flr_no = 0;
    
    pEffect->mdlver = (op->type - 1) % 2;

    pEffect->ax = op->ax;
    pEffect->ay = op->ay;
    
    pEffect->px = op->px;
    pEffect->py = op->py;
    pEffect->pz = op->pz;
    
    pEffect->sx = op->sx;
    pEffect->sy = op->sy;
    pEffect->sz = op->sz;
    
    lNumber = bhSetEffectTb(pEffect, NULL, NULL, 0);
    
    if (lNumber != -1) 
    {
        eff[lNumber].lkono = op->lkono;
    }
}

// 100% matching!
void bhEff246(O_WRK* op) 
{
    EFF5UV* pInfo;
	static EFF5UV Eff246UvInfo1[8] = 
	{
		{   0,   0 }, {  56,   0 }, { 112,   0 }, { 168,   0 },
		{   0,  56 }, {  56,  56 }, { 112,  56 }, { 168,  56 }
	};
	static EFF5UV Eff246UvInfo2[12] = 
	{
		{   0,  56 }, {  56,  56 }, { 112,  56 }, { 168,  56 },
		{   0, 112 }, {  56, 112 }, { 112, 112 }, { 168, 112 },
		{   0, 168 }, {  56, 168 }, { 112, 168 }, { 168, 168 }
	};
	static EFF5UV Eff246UvInfo3[16] = 
	{
		{   0,   0 }, {  56,   0 }, { 112,   0 }, { 168,   0 },
		{   0,  56 }, {  56,  56 }, { 112,  56 }, { 168,  56 },
		{   0, 112 }, {  56, 112 }, { 112, 112 }, { 168, 112 },
		{   0, 168 }, {  56, 168 }, { 112, 168 }, { 168, 168 }
	};
  
    switch (op->type)
    {                              
    case 0:                                         
        switch (op->mode0)
        {                     
        case 0:                                     
            op->flg |= 0x4180000;
            
            op->tex_id = 425;
            
            op->ani_ct = op->mdlver;
            
            op->bl_src = 8;
            op->bl_dst = 3;
            
            op->ct0 = 8.0f * (-rand() / -2.1474836E9f);
            
            pInfo = &Eff246UvInfo1[op->ct0];
            
            op->tv[0].x = op->tv[2].x = -0.21875f;
            op->tv[1].x = op->tv[3].x = 0.21875f;
            
            op->tv[0].y = op->tv[1].y = -0.21875f;
            op->tv[2].y = op->tv[3].y = 0.21875f;
            
            op->tv[0].z = op->tv[1].z = op->tv[2].z = op->tv[3].z = 0;
            
            op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
            
            op->xn = op->yn = 0;
            op->zn = op->sz / 10.0f;
            
            njPushMatrixEx();
            
            njUnitMatrix(NULL);
            
            njRotateXYZ(NULL, op->ax, op->ay, 0);
            njCalcVector(NULL, (NJS_VECTOR*)&op->xn, (NJS_VECTOR*)&op->xn);
            
            njPopMatrixEx();
            
            op->spd = 0.01f;
            
            op->mode0 = 1;
            break;
        case 1:                                     
            if (op->py <= op->lkono) 
            {
                op->py = op->lkono;
                
                njPushMatrixEx();
                
                njUnitMatrix(NULL);
                
                njRotateY(NULL, 65535.0f * (-rand() / -2.1474836E9f));
                njCalcVector(NULL, (NJS_VECTOR*)&op->xn, (NJS_VECTOR*)&op->xn);
                
                njPopMatrixEx();
                
                op->xn *= 0.5f;
                op->yn *= -0.25f;
                op->zn *= 0.5f;
                
                op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = 0xC0FFFFFF;
                
                op->ct0 = 0;
                
                pInfo = &Eff246UvInfo2[op->ct0];
                
                op->mode0 = 2;
            } 
            else 
            {
                op->ct0++;
                
                if (op->ct0 >= 8) 
                {
                    op->ct0 = 4;
                }
                
                pInfo = &Eff246UvInfo1[op->ct0];
                
                op->px += op->xn + (((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)) / 16.0f);
                op->py += op->yn + (((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)) / 16.0f);
                op->pz += op->zn + (((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)) / 16.0f);
                
                op->yn -= op->spd;
            }
            
            break;
        case 2:                                     
            op->ct0++;
            
            if (op->ct0 >= 24) 
            {
                op->flg = 0;
                return;
            }
            
            pInfo = &Eff246UvInfo2[op->ct0 / 2];
            
            op->px += op->xn + (((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)) / 16.0f);
            op->py += op->yn + (((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)) / 16.0f);
            op->pz += op->zn + (((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)) / 16.0f);
            
            op->yn -= op->spd;
            
            op->sx += 0.07f * op->sx;
            op->sy += 0.07f * op->sy;
            break;
        }
        
        break;
    case 1:                                         
        switch (op->mode0)
        {                        
        case 0:                                 
            op->flg |= 0x4180000;
            
            op->tex_id = 425;
            
            op->ani_ct = op->mdlver;
            
            op->bl_src = 8;
            op->bl_dst = 3;
            
            op->ct0 = 4.0f * (-rand() / -2.1474836E9f);
            
            op->tv[0].x = op->tv[2].x = -0.21875f;
            op->tv[1].x = op->tv[3].x = 0.21875f;
            
            op->tv[0].y = op->tv[1].y = -0.21875f;
            op->tv[2].y = op->tv[3].y = 0.21875f;
            
            op->tv[0].z = op->tv[1].z = op->tv[2].z = op->tv[3].z = 0;
            
            op->xn = op->yn = 0;
            op->zn = floorf(op->sz) / 10.0f;
            
            njPushMatrixEx();
            
            njUnitMatrix(NULL);
            
            njRotateXYZ(NULL, op->ax, op->ay, 0);
            
            njRotateZ(NULL, 65536.0f * (-rand() / -2.1474836E9f));
            njRotateX(NULL, 8192.0f  * (op->sz - floorf(op->sz)));
            
            njCalcVector(NULL, (NJS_VECTOR*)&op->xn, (NJS_VECTOR*)&op->xn);
            
            njPopMatrixEx();
            
            op->spd = 0.01f;
            
            op->aox = (op->sx - floorf(op->sx)) / 5.0f;
            op->sx  = floorf(op->sx)            / 5.0f;
            
            op->aoy = (op->sy - floorf(op->sy)) / 5.0f;
            op->sy  = floorf(op->sy)            / 5.0f;
            
            if ((int)(2.0f * (-rand() / -2.1474836E9f)) != 0) 
            {
                op->sx *= -1.0f;
            }
            
            op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
            
            op->mode0 = 1;
        case 1:                                   
            if (op->ct0 >= 16) 
            {
                op->flg = 0;
                return;
            }
            
            pInfo = &Eff246UvInfo3[op->ct0];
            
            op->ct0++;
            
            op->px += op->xn;
            op->py += op->yn;
            op->pz += op->zn;
            
            op->yn -= op->spd;
            
            op->sx += op->sx * op->aox;
            op->sy += op->sy * op->aoy;
            break;
        }
        
        break;
    }

    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 56) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 56) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff247(O_WRK* op)
{
    EF_WORK* pEffect;
    int lNumber;

    if ((op->type == 0) && (op->mode1 != 0)) 
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    pEffect = &sys->ef;
    
    pEffect->flg = 1;
    
    pEffect->id = 248;

    pEffect->type = op->type - 1; 

    pEffect->flr_no = 0;

    pEffect->mdlver = 0;

    pEffect->ax = op->ax;
    pEffect->ay = op->ay;
    
    pEffect->px = op->px;
    pEffect->py = op->py;
    pEffect->pz = op->pz;
    
    pEffect->sx = op->sx;
    pEffect->sy = op->sy;
    pEffect->sz = op->sz;
    
    lNumber = bhSetEffectTb(pEffect, NULL, NULL, 0);
    
    if (lNumber != -1) 
    {
        eff[lNumber].exp0 = (unsigned char*)op;
    }
}

// 100% matching!
void bhEff248(O_WRK* op) 
{
    EFF5UV* pInfo; 
    int lAlpha, lColor;    
    O_WRK* opp;   
	static EFF5UV Eff248UvInfo[16] = 
	{
		{   0,   0 }, {  56,   0 }, { 112,   0 }, { 168,   0 },
		{   0,  56 }, {  56,  56 }, { 112,  56 }, { 168,  56 },
		{   0, 112 }, {  56, 112 }, { 112, 112 }, { 168, 112 },
		{   0, 168 }, {  56, 168 }, { 112, 168 }, { 168, 168 }
	};
    
    opp = (O_WRK*)op->exp0;
    
    if (opp->type == 0) 
    {
        op->flg = 0;
        return;
    }
    
    switch (op->mode0) 
    {                      
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 426;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->aoy = floorf(op->sy);
        
        op->ct2 = 10.0f * (op->sy - floorf(op->sy));
        
        op->aoz = (op->sz - floorf(op->sz)) / 2.0f;
        op->sz  = floorf(op->sz);
        
        op->aox = fabs(op->sx - floorf(op->sx)) / 5.0;
        op->sx  = op->sy = floorf(op->sx);
        
        op->ct0 = 0;
        
        op->tv[0].x = op->tv[2].x = -0.21875f;
        op->tv[1].x = op->tv[3].x = 0.21875f;
        
        op->tv[0].y = op->tv[1].y = -0.21875f;
        op->tv[2].y = op->tv[3].y = 0.21875f;
        
        op->tv[0].z = op->tv[1].z = op->tv[2].z = op->tv[3].z = 0;
        
        op->xn = op->yn = 0;
        op->zn = op->sz / 10.0f;
        
        op->zn += op->aoz * (op->zn * (-rand() / -2.1474836E9f));
        
        njPushMatrixEx();
        
        if ((!(opp->flg & 0x80)) || ((opp->flg & 0x200000)))
        {
            njUnitMatrix(NULL);
        }  
        else 
        {
            njSetMatrix(NULL, &((O_WRK*)opp->lkwkp)->mlwP->owP[opp->lkono].mtx);
        }
        
        njRotateXYZ(NULL, op->ax, op->ay, 0);
        
        njRotateZ(NULL, 65536.0f * (-rand()  / -2.1474836E9f));
        njRotateX(NULL, 512.0f   * ((-rand() / -2.1474836E9f) - (-rand() / -2.1474836E9f)));
        
        njCalcVector(NULL, (NJS_VECTOR*)&op->xn, (NJS_VECTOR*)&op->xn);
        
        njPopMatrixEx();
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->ct0 >= 16) 
        {
            op->flg = 0;
            return;
        }
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->xn *= 0.95f;
        op->yn *= 0.95f;
        op->zn *= 0.95f;
        
        op->sx += op->sx * op->aox;
        op->sy += op->sy * op->aox;
        break;
    }
    
    lAlpha = (255.0f * op->aoy) / 40.0f;
    
    if (op->ct0 < op->ct2) 
    {
        lColor = (op->ct0 * 0xFF) / op->ct2;
    } 
    else
    {
        lColor = 0xFF;
    }
    
    lColor += (int)(0.2 * (lColor * (-rand() / -2.1474836E9f)));
     
    if (lColor < 0) 
    {
        lColor = 0;
    }
    else if (lColor > 0xFF) 
    {
        lColor = 0xFF;
    }
    
    op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = (lColor << 0) | (((lAlpha << 24) | 0xFF0000) | (lColor << 8));
    
    pInfo = &Eff248UvInfo[op->ct0];
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 56) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 56) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 100% matching!
void bhEff249(O_WRK* op)
{
    EFF5UV* pInfo;
	static EFF5UV Eff249UvInfo[16] = 
	{
		{   0,   0 }, {  56,   0 }, { 112,   0 }, { 168,   0 },
		{   0,  56 }, {  56,  56 }, { 112,  56 }, { 168,  56 },
		{   0, 112 }, {  56, 112 }, { 112, 112 }, { 168, 112 },
		{   0, 168 }, {  56, 168 }, { 112, 168 }, { 168, 168 }
	};
    
    if ((op->type == 0) && (op->mode1 != 0))
    {
        op->type = op->mode1;
    }
    
    if (op->type == 0) 
    {
        op->flg |= 0x1000000;
        return;
    }
    
    op->flg &= ~0x1000000;
    
    switch (op->mode0)
    {                       
    case 0:
        op->flg |= 0x4180000;
        
        op->tex_id = 427;
        
        op->bl_src = 8;
        op->bl_dst = 3;
        
        op->gpx = op->px;
        op->gpy = op->py;
        op->gpz = op->pz;
        
        op->sxb = op->sx;
        op->syb = op->sy;
        op->szb = op->sz;
        
        op->tv[0].col = op->tv[1].col = op->tv[2].col = op->tv[3].col = -1;
        
        op->ct0 = op->ct1 = 0;
        
        op->aox = fabs(op->sx - floorf(op->sx)) / 10.0;
        op->sx  = floorf(op->sx) / 5.0f;
        
        op->aoy = fabs(op->sy - floorf(op->sy)) / 10.0;
        op->sy  = floorf(op->sy) / 5.0f;
        
        op->xn = op->yn = 0;
        op->zn = op->sz / 10.0f;
        
        njPushMatrixEx();
        
        njUnitMatrix(NULL);
        
        njRotateXYZ(NULL, op->ax, op->ay, 0);
        njCalcVector(NULL, (NJS_VECTOR*)&op->xn, (NJS_VECTOR*)&op->xn);
        
        njPopMatrixEx();
        
        op->mode0 = 1;
        break;
    case 1:
        op->ct0++;
        
        if (op->lkono <= op->ct0)
        {
            op->px = op->gpx;
            op->py = op->gpy;
            op->pz = op->gpz;
            
            op->sx = op->sxb;
            op->sy = op->syb;
            op->sz = op->szb;
            
            op->mode1 = 0;
            op->type  = op->mode0 = 0;
            return;
        }
        
        op->ct1 = (op->ct0 * 16) / op->lkono;
        
        op->yn -= 0.01f;
        
        op->px += op->xn;
        op->py += op->yn;
        op->pz += op->zn;
        
        op->xn *= 0.95f;
        op->yn *= 0.95f;
        op->zn *= 0.95f;
        
        op->sx += op->sx * op->aox;
        op->sy += op->sy * op->aoy;
        break;
    }

    pInfo = &Eff249UvInfo[op->ct1];
    
    op->tv[0].u = op->tv[2].u = pInfo->u        / 256.0f;
    op->tv[1].u = op->tv[3].u = (pInfo->u + 55) / 256.0f;
    
    op->tv[0].v = op->tv[1].v = pInfo->v        / 256.0f;
    op->tv[2].v = op->tv[3].v = (pInfo->v + 55) / 256.0f;
    
    if (sys->ef_trsn < 512) 
    {
        sys->ef_trs[sys->ef_trsn] = op;
        
        sys->ef_trsn++;
    }
}

// 94.57% matching (matches on NGC)
EFF5SNOWRECT* CreateEff5SnowRect(int lSnowMax)
{
    EFF5SNOWRECT* pSnow;
    EFF5SNOWGRP* pSnowGrp;
    NJS_POINT3* pVector;
    int lSnowRest, lCnt;
    
    if ((pSnow = (EFF5SNOWRECT*)bhSetExtraEffectWork()) == NULL) 
    {
        return NULL;
    }
    
    pSnow->ulFrame = 0;
    
    pSnow->AreaCenter.x = pSnow->AreaCenter.y = pSnow->AreaCenter.z = 0.0f;
    
    pSnow->fAreaSizeX = pSnow->fAreaSizeY = pSnow->fAreaSizeZ = 1.0f;
    
    pSnow->fAreaMinX = -0.5f;
    pSnow->fAreaMaxX = 0.5f;
    
    pSnow->fAreaMinY = -0.5f;
    pSnow->fAreaMaxY = 0.5f;
    
    pSnow->fAreaMinZ = -0.5f;
    pSnow->fAreaMaxZ = 0.5f;
    
    if (lSnowMax <= 0)
    {
        return NULL;
    }
    
    if (lSnowMax > 2000) 
    {
        lSnowMax = 2000;
    }
    
    pSnow->lSnowTotalMax = lSnowMax;
    
    pSnow->pSnowVector = NULL;
    
    pSnowGrp = (EFF5SNOWGRP*)&pSnow->SnowGrp;
    
    pSnow->lSnowGrpMax = 0;
    
    for (lSnowRest = lSnowMax; lSnowRest > 0; lSnowRest -= 100) 
    {
        pSnowGrp->pPointTop = (NJS_POINT3*)bhSetExtraEffectWork();
        
        if (pSnowGrp->pPointTop == NULL) 
        {
            DeleteEff5SnowRect(pSnow);
            
            return NULL;
        }
        
        pSnowGrp->pPointTop = (NJS_POINT3*)((int)pSnowGrp->pPointTop + 4);
        
        if (lSnowRest >= 100) 
        {
            pSnowGrp->lPointMax = 100;
        }
        else 
        {
            pSnowGrp->lPointMax = lSnowRest;
        }
        
        pSnowGrp++;
        pSnow->lSnowGrpMax++;
    } 
    
    pSnow->pSnowVector = (NJS_POINT3*)bhSetExtraEffectWork();
    
    if (pSnow->pSnowVector == NULL) 
    {
        DeleteEff5SnowRect(pSnow);
        
        return NULL;
    }
    
    pSnow->pSnowVector = (NJS_POINT3*)((int)pSnow->pSnowVector + 4);
    
    pVector = pSnow->pSnowVector; 
    
    for (lCnt = 100; lCnt != 0; lCnt--)
    {
        pVector->x = (0.1f  * (-rand() / -2.1474836E9f)) - 0.05f;
        pVector->y = -(0.1f * (-rand() / -2.1474836E9f));
        pVector->z = (0.1f  * (-rand() / -2.1474836E9f)) - 0.05f;
        
        pVector++;
    } 
    
    pSnow->lSnowExistNext = lSnowMax;
    pSnow->lSnowExistCrnt = lSnowMax;
    pSnow->lSnowExistPrev = lSnowMax;
    
    pSnow->lSnowTimerCnt = pSnow->lSnowTimerMax = 0;
    
    return pSnow;
}

// 100% matching!
void DeleteEff5SnowRect(EFF5SNOWRECT* pSnow)
{
	EFF5SNOWGRP* pSnowGrp;
	int lGrpCnt;

    pSnowGrp = pSnow->SnowGrp;

    for (lGrpCnt = pSnow->lSnowGrpMax; lGrpCnt != 0; lGrpCnt--) 
	{
		pSnowGrp->pPointTop[-1].z = 0;
		
		pSnowGrp++;
    }

    if (pSnow->pSnowVector != NULL) 
	{
        pSnow->pSnowVector[-1].z = 0;
    }

    pSnow->flg = 0;
}

// 100% matching!
void ExecEff5SnowRect(EFF5SNOWRECT* pSnow) 
{
    EFF5SNOWGRP* pSnowGrp;
    int lDrawRest, lDrawCnt, lDrawMax;         
    NJS_POINT3* pPoint;  
    NJS_VECTOR* pVector;  
    NJS_VECTOR Vector;    
    float fMinX, fMaxX, fSizeX;           
    float fMinY, fMaxY, fSizeY;          
    float fMinZ, fMaxZ, fSizeZ;          
   
    pSnow->ulFrame++;
    
    if (pSnow->lSnowExistCrnt != pSnow->lSnowExistNext)
    {
        pSnow->lSnowTimerCnt++;
        
        if (pSnow->lSnowTimerCnt == pSnow->lSnowTimerMax) 
        {
            pSnow->lSnowExistCrnt = pSnow->lSnowExistNext;
        } 
        else 
        {
            pSnow->lSnowExistCrnt = pSnow->lSnowExistPrev + ((pSnow->lSnowTimerCnt * (pSnow->lSnowExistNext - pSnow->lSnowExistPrev)) / pSnow->lSnowTimerMax);
        }
    }
    
    GetEff5SnowRectCurrentWindVector(pSnow, &Vector);
    
    Vector.y -= 0.33f;
    
    fSizeX = pSnow->fAreaSizeX;
    fSizeY = pSnow->fAreaSizeY;
    fSizeZ = pSnow->fAreaSizeZ;
    
    fMinX = pSnow->fAreaMinX;
    fMaxX = pSnow->fAreaMaxX;
    
    fMinY = pSnow->fAreaMinY;
    fMaxY = pSnow->fAreaMaxY;
    
    fMinZ = pSnow->fAreaMinZ;
    fMaxZ = pSnow->fAreaMaxZ;
    
    pSnowGrp = pSnow->SnowGrp;
    
    for (lDrawRest = pSnow->lSnowExistCrnt; lDrawRest != 0; lDrawRest -= lDrawMax) 
    {
        lDrawMax = (lDrawRest > pSnowGrp->lPointMax) ? pSnowGrp->lPointMax : lDrawRest;
        
        pVector = pSnow->pSnowVector;
        pPoint  = pSnowGrp->pPointTop;
                
        for (lDrawCnt = lDrawMax; lDrawCnt != 0; lDrawCnt--) 
        {
            pPoint->x += Vector.x + pVector->x; 
            pPoint->y += Vector.y + pVector->y;
            pPoint->z += Vector.z + pVector->z;
            
            if (pPoint->x < fMinX) 
            {
                pPoint->x = fMaxX - (fSizeX * njFraction((fMinX - pPoint->x) / fSizeX));
            }
            else if (fMaxX < pPoint->x)
            {
                pPoint->x = fMinX + (fSizeX * njFraction((pPoint->x - fMaxX) / fSizeX));
            }
            
            if (pPoint->y < fMinY) 
            {
                pPoint->y = fMaxY - (fSizeY * njFraction((fMinY - pPoint->y) / fSizeY));
            }
            else if (fMaxY < pPoint->y)
            {
                pPoint->y = fMinY + (fSizeY * njFraction((pPoint->y - fMaxY) / fSizeY));
            }
            
            if (pPoint->z < fMinZ) 
            {
                pPoint->z = fMaxZ - (fSizeZ * njFraction((fMinZ - pPoint->z) / fSizeZ));
            }
            else if (fMaxZ < pPoint->z) 
            {
                pPoint->z = fMinZ + (fSizeZ * njFraction((pPoint->z - fMaxZ) / fSizeZ));
            }
            
            pVector++;
            pPoint++;
        } 
        
        pSnowGrp++;
    }
}

// 94.71% matching
void DrawEff5SnowRect(O_WRK* op) 
{
    EFF5SNOWRECT* pSnow;    
    EFF5SNOWGRP* pSnowGrp; 
    int lDrawRest, lDrawCnt, lDrawMax;         
    NJS_POINT3* pPoint;      
    NJS_MATRIX Matrix; // should be a pointer?
    NJS_TEXTURE_VTX* pModel; 
    int aAngleZ;             
    NJS_POINT3 Vector;      

    pSnow = (EFF5SNOWRECT*)op->exp0;
    
    njSetTexture(pSnow->pSnowTexList);
    njSetTextureNum(pSnow->ulSnowTexNum);
    
    njTextureFilterMode(0);
    
    pModel = pSnow->SnowModel;
    
    GetEff5SnowRectCurrentWindVector(pSnow, &Vector);
    
    Vector.y -= 0.38000003f;
    
    njCalcVector(NULL, &Vector, &Vector);
    
    aAngleZ = (int)(10430.381f * atan2f(Vector.y, Vector.x)) + 16384;
    
    switch (op->type) 
    {                            
    case 1:
    case 3:
        njPushMatrixEx();
        
        njGetMatrix(&Matrix);
        
        pSnowGrp = pSnow->SnowGrp;
        
        for (lDrawRest = pSnow->lSnowExistCrnt; lDrawRest != 0; lDrawRest -= lDrawMax) 
        {
            lDrawMax = MIN(pSnowGrp->lPointMax, lDrawRest);
            
            pPoint = pSnowGrp->pPointTop;
            
            for (lDrawCnt = lDrawMax; lDrawCnt != 0; lDrawCnt--)
            {
                njSetMatrix(NULL, &Matrix);
                
                njTranslateEx(pPoint);
                njUnitRotPortion(NULL);
                
                njRotateZ(NULL, aAngleZ);
                
                njDrawTexture3DEx(pModel, 4, 1);
                
                pPoint++;
            } 
            
            pSnowGrp++;
        }
        
        njPopMatrixEx();
        break;
    case 2:
        if (op->sz < 1.0f) 
        {
            op->sz = 1.0f;
        }
        
        njPushMatrixEx();
        
        njGetMatrix(&Matrix);
        
        pSnowGrp = pSnow->SnowGrp;
        
        for (lDrawRest = pSnow->lSnowExistCrnt; lDrawRest != 0; lDrawRest -= lDrawMax)
        {
            lDrawMax = MIN(pSnowGrp->lPointMax, lDrawRest);
            
            pPoint = pSnowGrp->pPointTop;
            
            for (lDrawCnt = lDrawMax; lDrawCnt != 0; lDrawCnt--) 
            {
                njSetMatrix(NULL, &Matrix);
                
                njTranslateEx(pPoint);
                njUnitRotPortion(NULL);
                
                njRotateZ(NULL, aAngleZ);
                njRotateY(NULL, ((int)((pPoint->z + (pPoint->x + pPoint->y)) / op->sz) % 4) * 16384);
                
                njDrawTexture3DEx(pModel, 4, 1);
                
                pPoint++;
            }
            
            pSnowGrp++;
        }
        
        njPopMatrixEx();
        break;
    }
}

// 100% matching!
void SetEff5SnowRectAreaCenter(EFF5SNOWRECT* pSnow, float fPointX, float fPointY, float fPointZ)
{
	pSnow->AreaCenter.x = fPointX;
    pSnow->AreaCenter.y = fPointY;
    pSnow->AreaCenter.z = fPointZ;

    pSnow->fAreaMinX = fPointX - (pSnow->fAreaSizeX / 2.0f);
    pSnow->fAreaMaxX = fPointX + (pSnow->fAreaSizeX / 2.0f);

    pSnow->fAreaMinY = fPointY - (pSnow->fAreaSizeY / 2.0f);
    pSnow->fAreaMaxY = fPointY + (pSnow->fAreaSizeY / 2.0f);

    pSnow->fAreaMinZ = fPointZ - (pSnow->fAreaSizeZ / 2.0f);
    pSnow->fAreaMaxZ = fPointZ + (pSnow->fAreaSizeZ / 2.0f);
}

// 100% matching!
void SetEff5SnowRectAreaCenterAndSize(EFF5SNOWRECT* pSnow, float fCenterX, float fCenterY, float fCenterZ, float fSizeX, float fSizeY, float fSizeZ)
{
    pSnow->AreaCenter.x = fCenterX;
    pSnow->AreaCenter.y = fCenterY;
    pSnow->AreaCenter.z = fCenterZ;

    pSnow->fAreaSizeX = fSizeX;
    pSnow->fAreaSizeY = fSizeY;
    pSnow->fAreaSizeZ = fSizeZ;

    pSnow->fAreaMinX = fCenterX - (fSizeX / 2.0f);
    pSnow->fAreaMaxX = fCenterX + (fSizeX / 2.0f);
    pSnow->fAreaMinY = fCenterY - (fSizeY / 2.0f);

    pSnow->fAreaMaxY = fCenterY + (fSizeY / 2.0f);
    pSnow->fAreaMinZ = fCenterZ - (fSizeZ / 2.0f);
    pSnow->fAreaMaxZ = fCenterZ + (fSizeZ / 2.0f);
}

// 100% matching!
void SetEff5SnowRectParticleMax(EFF5SNOWRECT* pSnow, int lSnowMax)
{
    if ((lSnowMax < 0) || (pSnow->lSnowTotalMax < lSnowMax))
    {
        lSnowMax = pSnow->lSnowTotalMax;
    }

    pSnow->lSnowExistPrev = pSnow->lSnowExistCrnt = pSnow->lSnowExistNext = lSnowMax;

    pSnow->lSnowTimerCnt = pSnow->lSnowTimerMax = 0;
}

// 100% matching!
void MovEff5SnowRectParticleMax(EFF5SNOWRECT* pSnow, int lSnowMax, int lTimeMax)
{
    if ((lSnowMax < 0) || (pSnow->lSnowTotalMax < lSnowMax))
    {
        lSnowMax = pSnow->lSnowTotalMax;
    }

    if (lSnowMax != pSnow->lSnowExistNext)
    {
        pSnow->lSnowExistPrev = pSnow->lSnowExistCrnt;
        pSnow->lSnowExistNext = lSnowMax;

        pSnow->lSnowTimerCnt = 0;
        pSnow->lSnowTimerMax = lTimeMax;
    }
}

// 100% matching!
void ArrangeEff5SnowRectParticle(EFF5SNOWRECT* pSnow)
{
	// modified order of local variables in regards to DWARF
	EFF5SNOWGRP* pSnowGrp;
	NJS_POINT3* pPoint;
	int lGrpCnt, lCnt;

    pSnowGrp = pSnow->SnowGrp;
	
	for (lGrpCnt = pSnow->lSnowGrpMax; lGrpCnt != 0; lGrpCnt--, pSnowGrp++)
	{
		pPoint = pSnowGrp->pPointTop;
		
		for (lCnt = pSnowGrp->lPointMax; lCnt != 0; lCnt--, pPoint++)
		{
			pPoint->x = pSnow->fAreaMinX + (pSnow->fAreaSizeX * (-rand() / -2.1474836E9f));
			pPoint->y = pSnow->fAreaMinY + (pSnow->fAreaSizeY * (-rand() / -2.1474836E9f));
			pPoint->z = pSnow->fAreaMinZ + (pSnow->fAreaSizeZ * (-rand() / -2.1474836E9f));
		} 
	} 
}

// 100% matching!
void SetEff5SnowRectParticleTexture(EFF5SNOWRECT* pSnow, NJS_TEXLIST* pTexList, unsigned int ulTexNum, float fU0, float fV0, float fU1, float fV1, float fU2, float fV2, float fU3, float fV3)
{
	NJS_TEXTURE_VTX* pTex;

	pSnow->pSnowTexList = pTexList;
	
	pSnow->ulSnowTexNum = ulTexNum;

	pTex = pSnow->SnowModel;

	pTex[0].u = fU0;
	pTex[0].v = fV0;

	pTex[1].u = fU1;
	pTex[1].v = fV1;

	pTex[2].u = fU2;
	pTex[2].v = fV2;

	pTex[3].u = fU3;
	pTex[3].v = fV3;
}

// 100% matching!
void SetEff5SnowRectParticleColor(EFF5SNOWRECT* pSnow, unsigned int ulColor0, unsigned int ulColor1, unsigned int ulColor2, unsigned int ulColor3)
{
	NJS_TEXTURE_VTX* pTex;

	pTex = pSnow->SnowModel;

	pTex[0].col = ulColor0;
	pTex[1].col = ulColor1;
	pTex[2].col = ulColor2;
	pTex[3].col = ulColor3;
}

// 100% matching!
void SetEff5SnowRectParticleSize(EFF5SNOWRECT* pSnow, float fWidth, float fHeight)
{
	NJS_TEXTURE_VTX* pSnowModel;

	pSnowModel = pSnow->SnowModel;

    pSnow->SnowModel[0].x = pSnow->SnowModel[2].x = -fWidth / 2.0f;
    pSnow->SnowModel[1].x = pSnow->SnowModel[3].x = fWidth  / 2.0f;

    pSnow->SnowModel[0].y = pSnow->SnowModel[1].y = -fHeight / 2.0f;
    pSnow->SnowModel[2].y = pSnow->SnowModel[3].y = fHeight  / 2.0f;

    pSnow->SnowModel[0].z = pSnow->SnowModel[1].z = pSnow->SnowModel[2].z = pSnow->SnowModel[3].z = 0;
}

// 100% matching!
NJS_VECTOR* GetEff5SnowRectCurrentWindVector(void* unused, NJS_VECTOR* pVector) // first parameter not present on DWARF
{
    pVector->x = (sys->winds * -njSin(sys->windr)) / 10.0f;
    pVector->y = 0;
    pVector->z = (sys->winds * -njCos(sys->windr)) / 10.0f;

    return pVector;
}
