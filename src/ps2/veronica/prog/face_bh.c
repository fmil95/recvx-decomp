#include "../../../ps2/veronica/prog/face.h"
#include "../../../ps2/veronica/prog/face_bh.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaMem.h"
#include "../../../ps2/veronica/prog/pwksub.h"

// 100% matching!
void fmSetLipSyncParam(MASK_WORK* fm, PARAM_WORK* base, LIP_WORK* lip, unsigned int mask)
{
    float rate, level;

    if (lip->cnt >= lip->time)
    {
        lip->cnt -= lip->time;
        
        if (*lip->ptr == 0xFF)
        {
            lip->cur = 0;
            
            lip->flag = 0;
        } 
        else 
        {
            lip->cur = *lip->ptr++;
            
            lip->time = *lip->ptr++;
            
            if (*lip->ptr == 0xFF)
            {
                lip->next = 0;
            }
            else
            {
                lip->next = *lip->ptr;
            }
        }
    }
    
    if (((lip->time - lip->cnt) < 10) && (lip->flag != 0))
    {
        if (lip->time < 10)
        {
            rate = (float)lip->cnt / lip->time;
            level = lip->time / 10.0f;
        } 
        else 
        {
            rate = (10 - (lip->time - lip->cnt)) / 10.0f;
            level = 1.0f;
        }
        
        fmCnkSetInterParamLip(fm, &base[lip->cur], &base[lip->next], rate, level, mask);
    } 
    else 
    {
        fmCnkSetParamLip(fm, &base[lip->cur], mask);
    }
    
    if (lip->flag != 0) 
    {
        lip->cnt += 2;
    }
}

// 100% matching!
void _fmSetObjP(ML_WORK* mlwP) 
{
    NJS_CNK_OBJECT* obj; 
    NJS_CNK_OBJECT* obj2; 
    NJS_CNK_OBJECT* stack[256]; 
    int sp;   

    obj = mlwP->objP;
    obj2 = mlwP->objP = (NJS_CNK_OBJECT*)bhGetFreeMemory(mlwP->obj_num * sizeof(NJS_CNK_OBJECT), 64);
    
    mlwP->owP = (O_WORK*)bhGetFreeMemory(mlwP->obj_num * sizeof(O_WORK), 64); 
    
    sp = 0;
    
    while (obj != NULL) 
    {
        njMemCopy(obj2, obj, sizeof(NJS_CNK_OBJECT));
        
        obj2++;
        
        if (obj->sibling != NULL) 
        { 
            stack[sp++] = obj->sibling;
        }
        
        if (obj->child != NULL)
        {
            obj = obj->child;
            continue;
        }
        
        if (sp != 0) 
        {
            obj = stack[--sp];
        }
        else 
        { 
            obj = NULL;
        }
    }
}

// 100% matching!
NJS_CNK_OBJECT* _fmCnkSearchObject(MASK_WORK* fm, NJS_CNK_OBJECT* root, char id)
{
    NJS_CNK_OBJECT* obj; 
    NJS_CNK_OBJECT* stack[256]; 
    int sp; 
    int n; 
    int i;
    int dummy; 
    
    if (id == -1) 
    {
        return NULL;
    }
    
    obj = root;
    
    sp = 0;
    n = 0;
    
    while (obj != NULL)
    {
        if (obj->model != NULL)
        {
            if (n++ == id) 
            { 
                break;
            }
        }
        
        if (obj->sibling != NULL) 
        { 
            stack[sp++] = obj->sibling; 
        }
        
        dummy = 0;
        
        if (obj == fm->tangorg) 
        {
            dummy = 1;
        }
        
        if (obj == fm->toothsrc)
        { 
            dummy = 1;
        }

        for (i = 0; i < 9; i++)
        {
            if (obj == fm->eyesrc[i]) 
            {
                dummy = 1;
            }
        }

        if ((obj->child != NULL) && (dummy == 0))
        {
            obj = obj->child;
            continue;
        }
        
        if (sp != 0) 
        {
            obj = stack[--sp];
        }
        else 
        { 
            obj = NULL;
        }
    }
    
    return obj;
}

// 100% matching!
void _fmGetVChunkType(MASK_WORK* fm)
{
    fm->vtype = *(unsigned short*)*(unsigned int*)fm->src;

    switch (fm->vtype)
    {
    case 32:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
        fm->vtop = 2;
        fm->ntop = 6;
        
        fm->vofs = 8;
        break;
    case 33:
        fm->vtop = 2;
        fm->ntop = 2;
        
        fm->vofs = 3;
        
        fm->mode |= 0x1;
        break;
    case 34:
        fm->vtop = 2;
        fm->ntop = 2;
        
        fm->vofs = 4;
        
        fm->mode |= 0x1;
        break;
    case 41:
        fm->vtop = 2;
        fm->ntop = 5;
        
        fm->vofs = 6;
        break;
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
        fm->vtop = 2;
        fm->ntop = 5;
        
        fm->vofs = 7;
        break;
    case 48:
        fm->vtop = 2;
        fm->ntop = 5;
        
        fm->vofs = 4;
        
        fm->mode |= 0x1;
        break;
    case 49:
    case 50:
        fm->vtop = 2;
        fm->ntop = 5;
        
        fm->vofs = 5;
        
        fm->mode |= 0x1;
        break;
    case 51:
        fm->vtop = 16;
        fm->ntop = 20;
        
        fm->vofs = 8;
        
        fm->mode |= 0x1;
        break;
    default:
        fm->vtop = 2;
        fm->ntop = 2;
        
        fm->vofs = 0;
        
        fm->mode |= 0x1;
        break;
    }
}

// 100% matching!
void _fmCnkSetFaceObject(MASK_WORK* fm, NJS_CNK_OBJECT* face)
{
    if (face != NULL) 
    {
        fm->obj = face;
        
        fm->src = face->model;
        fm->dst = (NJS_CNK_MODEL*)bhGetFreeMemory(sizeof(NJS_CNK_MODEL), 64);
        
        njMemCopy(fm->dst, fm->src, sizeof(NJS_CNK_MODEL));
        
        face->model = fm->dst;
        
        _fmGetVChunkType(fm);
        
        fm->dst->vlist = (int*)bhGetFreeMemory((((fm->src->vlist[1] >> 16) * fm->vofs) + 128) * 4, 64);
        
        njMemCopy(fm->dst->vlist, fm->src->vlist, (((fm->src->vlist[1] >> 16) * fm->vofs) + 128) * 4);
    }
}

// 100% matching!
void _fmCnkSetEyeballObject(MASK_WORK* fm, unsigned int id, NJS_CNK_OBJECT* eye, NJS_CNK_OBJECT* root)
{   
    int i; 
    NJS_CNK_OBJECT* obj; 
    NJS_CNK_OBJECT* stack[256]; 
    int sp; 

    obj = root;

    if ((id >= 9) || (eye == NULL)) 
    {
        return;
    }
    
    njMemCopy(&fm->eye[id], eye, sizeof(NJS_CNK_OBJECT));
    
    fm->eye[id].child = NULL;
    fm->eye[id].sibling = eye->child;
    
    eye->child = &fm->eye[id];
    
    eye->evalflags |= 0xA0000008;
    
    eye->evalflags &= ~0x10;
    eye->evalflags &= ~0x2;
    
    for (i = 0; i < 3; i++)
    {
        fm->eyepos[id][i] = eye->pos[i];
        fm->eyeang[id][i] = eye->ang[i];
        
        fm->eye[id].pos[i] = 0;
        
        eye->scl[i] = 1.0f;
        eye->ang[i] = 0;
    }
    
    fm->eyesrc[id] = eye;
    
    njPushMatrix(NULL);
    njUnitMatrix(NULL);
    
    sp = 0;
    
    while (TRUE)
    {
        if (obj->sibling != NULL) 
        {
            njPushMatrix(NULL);
            
            stack[sp++] = obj->sibling;
        }
        
        njTranslate(NULL, obj->pos[0], obj->pos[1], obj->pos[2]);
        njRotateXYZ(NULL, obj->ang[0], obj->ang[1], obj->ang[2]);
        njScale(NULL, obj->scl[0], obj->scl[1], obj->scl[2]);
        
        if (obj == fm->eyesrc[id])
        {
            njGetMatrix(&fm->eyemat[id]);
            break;
        }

        if (obj->child != NULL)
        {
            obj = obj->child;
            continue;
        }
        
        if (sp == 0) 
        {
            break;
        }
            
        njPopMatrix(1);
        
        obj = stack[--sp];
    }
    
    njPopMatrix(1);
}

// 100% matching!
void _fmCnkSetTangObject(MASK_WORK* fm, NJS_CNK_OBJECT* tang)
{
    int i; 
    u_long128* src_128; 
    u_long128* dst_128; 

    if (tang != NULL) 
    {
        fm->tangsrc = tang->model;
        fm->tangdst = (NJS_CNK_MODEL*)bhGetFreeMemory(sizeof(NJS_CNK_MODEL), 64);
        
        njMemCopy(fm->tangdst, fm->tangsrc, sizeof(NJS_CNK_MODEL));
        
        tang->model = fm->tangdst;
        
        fm->tangdst->vlist = (int*)bhGetFreeMemory((((fm->tangsrc->vlist[1] >> 16) * fm->vofs) + 128) * 4, 64);
        
        src_128 = (u_long128*)fm->tangsrc->vlist;
        dst_128 = (u_long128*)fm->tangdst->vlist;
        
        for (i = ((((unsigned int)(fm->tangsrc->vlist[1] >> 16) * fm->vofs) + 128) * 4) >> 2; i > 0; i--)
        {
            *dst_128++ = *src_128++;
        }
        
        njMemCopy(&fm->tangobj, tang, sizeof(NJS_CNK_OBJECT));
        
        fm->tangobj.child = NULL;
        fm->tangobj.sibling = tang->child;
        
        tang->child = &fm->tangobj;
        
        tang->evalflags |= 0xA0000008;
        
        tang->evalflags &= ~0x10;
        tang->evalflags &= ~0x2;

        for (i = 0; i < 3; i++)
        {
            fm->tangpos[i] = tang->pos[i];
            fm->tangang[i] = tang->ang[i];
            
            fm->tangobj.pos[i] = 0;
            
            tang->scl[i] = 1.0f;
            tang->ang[i] = 0;
        }
        
        fm->tangorg = tang;
    }
}

// 100% matching!
void _fmCnkSetToothObject(MASK_WORK* fm, NJS_CNK_OBJECT* tooth)
{
    int i;

    if (tooth != NULL) 
    {
        njMemCopy(&fm->tooth, tooth, sizeof(NJS_CNK_OBJECT));
        
        fm->tooth.child = NULL;
        fm->tooth.sibling = tooth->child;
        
        tooth->child = &fm->tooth;
        
        tooth->evalflags |= 0xA0000008;
        
        tooth->evalflags &= ~0x10;
        tooth->evalflags &= ~0x2;

        for (i = 0; i < 3; i++)
        {
            fm->toothpos[i] = tooth->pos[i];
            fm->toothang[i] = tooth->ang[i];
            
            fm->tooth.pos[i] = 0;
            
            tooth->scl[i] = 1.0f;
            tooth->ang[i] = 0;
        }
        
        fm->toothsrc = tooth;
    }
}

// 90.70% matching
void _fmCnkSetJaw(MASK_WORK* fm, unsigned int v0, unsigned int v1)
{   
    float* svp;       
    float x;           
    float y;          
    float z;       
    int ry;           
    int rz;           
    unsigned int vofs; 
    float svp0[4];     

    vofs = fm->vofs;
    
    svp = (float*)&fm->src->vlist[fm->vtop];
    
    *(u_long128*)svp0 = *(u_long128*)&svp[v0 * vofs];
    
    x = svp[(v1 * vofs) + 0] - svp0[0];
    y = svp[(v1 * vofs) + 1] - svp0[1];
    z = svp[(v1 * vofs) + 2] - svp0[2];
    
    ry = (65536.0f / PI_2) * atanf(y / x);
    rz = (65536.0f / PI_2) * atanf(z * njInvertSqrt((x * x) + (y * y)));
    
    njPushMatrixEx();
    njUnitMatrix(&fm->jmat1);
    
    njRotateY(&fm->jmat1, -rz);
    njRotateZ(&fm->jmat1, -ry);
    
    njTranslate(&fm->jmat1, -svp0[0], -svp0[1], -svp0[2]);
    
    njUnitMatrix(&fm->jmat2);
    
    njTranslate(&fm->jmat2, svp0[0], svp0[1], svp0[2]);
    
    njRotateZ(&fm->jmat2, ry);
    njRotateY(&fm->jmat2, rz);
    
    njPopMatrixEx();
    
    if (fm->toothsrc != NULL)
    {
        fm->toothsrc->ang[1] = rz;
        fm->toothsrc->ang[2] = ry;
    }
    
    if (fm->tangorg != NULL)
    {
        fm->tangorg->ang[1] = rz;
        fm->tangorg->ang[2] = ry;
    }
}

// 100% matching!
void fmCnkInitContext(MASK_WORK* fm, void* data, NJS_CNK_OBJECT* root, ML_WORK* mlwP)
{
    VLIST_WORK* vlist;
	unsigned int* nlist;
    int* dvp;
    int i;
    int j;
    NJS_CNK_OBJECT* obj;
    unsigned int vofs;

    memset(fm, 0, sizeof(MASK_WORK));
    
    fm->head = data;
    
    _fmCnkSetFaceObject(fm, _fmCnkSearchObject(fm, root, fm->head->faceId));
    
    obj = _fmCnkSearchObject(fm, root, fm->head->toothId);
    
    if (obj != NULL) 
    {
        _fmCnkSetToothObject(fm, obj);
        
        mlwP->obj_num++;
    }
    
    obj = _fmCnkSearchObject(fm, root, fm->head->tangId);
    
    if (obj != NULL) 
    {
        _fmCnkSetTangObject(fm, obj);
        
        mlwP->obj_num++;
    }
    
    for (i = 0; i < 9; i++) 
    {
        obj = _fmCnkSearchObject(fm, root, fm->head->eyeId[i]);
        
        if (obj != NULL) 
        {
            _fmCnkSetEyeballObject(fm, i, obj, root);
            
            mlwP->obj_num++;
        }
    }
    
    fm->vlist = (VLIST_WORK*)&fm->head[1];
    
    fm->nvpt = (NJS_POINT3*)&fm->vlist[fm->head->nList];
    
    nlist = (unsigned int*)fm->nvpt;
    vlist = fm->vlist;
    
    dvp = &fm->dst->vlist[fm->vtop];
    
    vofs = fm->vofs;
    
    for (i = 0; i++ < fm->head->nList; vlist++) 
    {
        for (j = 0; j++ < vlist->nvnum; ) 
        {
            *nlist++ = (int)&dvp[*nlist * vofs];
        } 
    }
    
    fm->list = (LIST_WORK*)nlist;
    
    fm->jaw = (TANG_WORK*)&fm->list[fm->head->nConnect];
    
    fm->tang = &fm->jaw[fm->head->nJaw];
    
    fm->face = (PARAM_WORK*)&fm->tang[fm->head->nTang];
    
    fm->lnum = fm->head->nList;
    fm->jnum = fm->head->nJaw;
    fm->tnum = fm->head->nTang;
    fm->fnum = fm->head->nFace;
    
    _fmCnkSetJaw(fm, fm->head->jawId[0], fm->head->jawId[1]);
    _fmSetObjP(mlwP);
}

// 100% matching!
void fmCnkSetParam(MASK_WORK* fm, PARAM_WORK* param)
{
	njMemCopy(&fm->param, param, sizeof(PARAM_WORK));
}

// 100% matching!
void fmCnkSetParamLip(MASK_WORK* fm, PARAM_WORK* param, unsigned int flag)
{
    int i;
    
    for (i = 0; i < 32; i++)
    {
        if ((flag & (1 << i)))  
        {
            fm->param.muscle[i] = param->muscle[i];
        }
    }
    
    fm->param.jawang = 0.005493164f * *(int*)&param->jawang;
    
    fm->param.jawtrans = param->jawtrans;
    
    fm->param.tangx = 0.005493164f * *(int*)&param->tangx;
    fm->param.tangy = 0.005493164f * *(int*)&param->tangy;
    fm->param.tangz = param->tangz;
}

// 99.53% matching (matches on GC)
void fmCnkSetInterParam(MASK_WORK* fm, PARAM_WORK* p1, PARAM_WORK* p2, float t, float lv, unsigned int mask)
{
    int i;
    float rate;
    float pp; // not from DWARF

    switch (p1->flag) 
    {
    case 0:
        rate = t;
        break;
    case 1:
        rate = t * t;
        break;
    case 2:
        rate = njSqrt(t);
        break; 
    case 3:
        rate = 0.5f - (0.5f * njCos((65536 / 2) * t));
        break;
    case 4:
        rate = 0;
        break;
    default:
        rate = t;
        break;
    }
    
    for (i = 0; i < 32; i++) 
    {
        if ((mask & (1 << i))) 
        {
            pp = p1->muscle[i] + (rate * (p2->muscle[i] - p1->muscle[i]));
            
            fm->param.muscle[i] = pp * lv;
        }
    }
    
    fm->param.jawang = lv * (p1->jawang + (rate * (p2->jawang - p1->jawang)));
    fm->param.jawtrans = lv * (p1->jawtrans + (rate * (p2->jawtrans - p1->jawtrans)));
    
    fm->param.eye.x = p1->eye.x + (rate * (p2->eye.x - p1->eye.x));
    fm->param.eye.y = p1->eye.y + (rate * (p2->eye.y - p1->eye.y));
    fm->param.eye.z = p1->eye.z + (rate * (p2->eye.z - p1->eye.z));
    
    fm->param.tangx = lv * (p1->tangx + (rate * (p2->tangx - p1->tangx)));
    fm->param.tangy = lv * (p1->tangy + (rate * (p2->tangy - p1->tangy)));
    fm->param.tangz = lv * (p1->tangz + (rate * (p2->tangz - p1->tangz)));
}

// 99.54% matching (matches on GC)
void fmCnkSetInterParamLip(MASK_WORK* fm, PARAM_WORK* p1, PARAM_WORK* p2, float t, float lv, unsigned int mask)
{
	int i;
    float rate;
    float* fm_muscle;
    float pp; // not from DWARF

    switch (p1->flag) 
    {
    case 0:
        rate = t;
        break;
    case 1:
        rate = t * t;
        break;
    case 2:
        rate = njSqrt(t);
        break; 
    case 3:
        rate = 0.5f - (0.5f * njCos((65536 / 2) * t));
        break;
    case 4:
        rate = 0;
        break;
    default:
        rate = t; 
        break;
    }
    
    fm_muscle = fm->param.muscle;
    
    for (i = 0; i < 32; i++) 
    {
        if ((mask & (1 << i))) 
        {
            pp = p1->muscle[i] + (rate * (p2->muscle[i] - p1->muscle[i]));
            
            fm_muscle[i] = pp * lv;
        }
    }
    
    fm->param.jawang = lv * ((0.005493164f * *(int*)&p1->jawang) + (rate * (0.005493164f * (*(int*)&p2->jawang - *(int*)&p1->jawang))));
    fm->param.jawtrans = lv * (p1->jawtrans + (rate * (p2->jawtrans - p1->jawtrans)));
    
    fm->param.tangx = lv * ((0.005493164f * *(int*)&p1->tangx) + (rate * (0.005493164f * (*(int*)&p2->tangx - *(int*)&p1->tangx))));
    fm->param.tangy = lv * ((0.005493164f * *(int*)&p1->tangy) + (rate * (0.005493164f * (*(int*)&p2->tangy - *(int*)&p1->tangy))));
    fm->param.tangz = lv * (p1->tangz + (rate * (p2->tangz - p1->tangz)));
}

// 100% matching!
void fmCnkSetCurrentFrame(MASK_WORK* fm, float frame)
{
    int i;
    unsigned int key;

    for (i = 0; i < fm->fnum; i++)
    {
        if (fm->face[i].frame > (unsigned int)frame)
        {
            break;
        }
    }
    
    if (i == 0) 
    {
        fmCnkSetParam(fm, fm->face);
    }
    else if (i == fm->fnum) 
    {
        fmCnkSetParam(fm, &fm->face[fm->fnum - 1]);
    }
    else
    {
        key = i - 1;
        
        fmCnkSetInterParam(fm, &fm->face[key], &fm->face[key + 1], (frame - fm->face[key].frame) / ((float)fm->face[key + 1].frame - fm->face[key].frame), 1.0f, -1);
    }
}

// 100% matching! 
unsigned int fmCnkGetLastFrame(MASK_WORK* fm)
{
	return fm->face[fm->fnum - 1].frame;
}

// 100% matching!
// TODO: while this code matches, this is not how they wrote the function and it needs binding to the inline ASM all of the local variables 
void _fmCnkCalcMuscle(MASK_WORK* fm)  
{
    float rsum;           // needs use    
    unsigned int vofs;    // needs use
    float para;           // needs use     
    TANG_WORK* jaw;      
    float rate;           // needs use         
    float sum;            // needs use        
    float* mrp;           // needs use         
    NJS_POINT3** mvp;     // needs use    
    float mrate[32];      // needs use   
    NJS_POINT3* mvec[32]; // needs use
    float* param;         // needs use     
    VLIST_WORK list;      // needs use    
    LIST_WORK* con;       // needs use    
    float* dvp, *svp;     // need use        
    int m, n, i;          // need use            

    asm volatile
    ("
    .set noreorder
        lw     a1, MASK_WORK.vtop(%0)
        lw     v1, MASK_WORK.src(%0)
        lw     a2, MASK_WORK.dst(%0)
        lw     %1, MASK_WORK.jaw(%0)
        
        addiu  sp, sp, -0x100
        
        sll    a3, a1, 2
        
        lw     a1, 0x0(v1)
        lw     a2, 0x0(a2)
        lw     v1, 0x0(%1)
        
        addu   t4, a1, a3
        addu   t5, a2, a3
    
        sll    a1, v1, 5
    
        addu   v1, t4, a1
        
        lq     v1, 0x0(v1)
        
        pref   0x00, 0x0(v1)
        
        addu   v1, t5, a1
    
        lq     v1, 0x0(v1)
        
        pref   0x00, 0x0(v1)
        
        lw     v1, MASK_WORK.jnum(%0)
        nop
    
        slt    at, zero, v1
        beqz   at, l_00299DBC
    
        lw     t0, 0x0(%1)
        
    l_00299D8C:
        muli   t0, t0, 0x20  
    
        add    t1, t5, t0 
        add    t2, t4, t0 
    
        lq     t3, 0x0(t2)
        
        addi   %1, %1, 0x8 
        addi   v1, v1, -0x1 
        
        lw     t0, 0x0(%1)
        
        slt    at, zero, v1
        bnez   at, l_00299D8C
    
        sq     t3, 0x0(t1)
        
    l_00299DBC:
        lw     a1, MASK_WORK.list(%0)
        lw     a2, MASK_WORK.vlist(%0)
        lw     v1, MASK_WORK.lnum(%0)
        
        li     t0, 0x3F800000
        
        mtc1   zero, f9
        mtc1   t0, f0
    
        b      l_00299F58
    
        addiu  a3, %0, MASK_WORK.param
        
    l_00299DDC:
        lw     t5, MASK_WORK.dst(%0)
        lh     t0, 0x0(a2)
    
        mtc1   zero, f2
    
        paddub t3, zero, zero
    
        addiu  t1, sp, 0x0
    
        lw     t5, 0x0(t5)
        
        sll    t0, t0, 5
    
        addiu  t2, sp, 0x80
        addu   t0, t0, t5
        
        lw     t0, 0x40(t0)
        
        pref   0x00, 0x0(t0)
        pref   0x00, 0x0(t6)
        
        b      l_00299E88
    
        lb     t5, 0x2(a2)
        
    l_00299E14:
        lw     t0, 0x0(a1)
        
        sll    t0, t0, 2
    
        addu   t0, a3, t0
        
        lwc1   f4, 0x0(t0)
        
        c.eq.s f9, f4
        nop
        bc1tl  l_00299E7C
    
        addiu  a1, a1, 0x14
        addiu  t0, a1, 0x4
        
        c.lt.s f4, f9
        
        sw     t0, 0x0(t1)
        
        bc1f   l_00299E50
    
        addiu  t1, t1, 0x4
    
        b      l_00299E58
    
        neg.s  f3, f4
        
    l_00299E50:
        mov.s  f3, f4
        nop
    
    l_00299E58:
        lwc1   f1, 0x10(a1)
    
        addiu  t3, t3, 0x1
        
        mul.s  f3, f1, f3
        mul.s  f1, f4, f3
        
        swc1   f1, 0x0(t2)
        
        add.s  f2, f2, f3
        
        addiu  t2, t2, 0x4
        nop
        addiu  a1, a1, 0x14
    
    l_00299E7C:
        pref   0x00, 0x0(t7)
        
        addiu  t5, t5, -0x1
        nop
        
    l_00299E88:
        bgtz   t5, l_00299E14
        nop
        nop
        nop
    
        div.s  f1, f0, f2
        
        lh     t9, 0x0(a2)
        lw     t0, MASK_WORK.dst(%0)
        
        paddub t6, t1, zero
        paddub t7, t2, zero
    
        sll    t5, t9, 3
    
        addiu  %1, t5, 0x10
        
        lw     t5, 0x0(t0)
        
        sll    %1, %1, 2
        sll    t0, t9, 5
        
        addu   t0, t4, t0
        
        lq     t0, 0x0(t0)
        
        addu   t5, t5, %1
    
        sq     t0, 0x0(t5)
        
        slt    at, zero, t3
        beqz   at, l_00299F50
    
        mfc1   t0, f1
    
        addi   t6, t1, -0x4 
        addi   t7, t2, -0x4 
        addi   t3, t3, -0x1 
        
        mtc1   t0, f8
        
        lwc1   f7, 0x0(t7)
        
        lw     t1, 0x0(t6)
        
        lwc1   f1, 0x0(t5)
        lwc1   f2, 0x4(t5)
        lwc1   f3, 0x8(t5)
        
    l_00299F00:
        mul.s  f7, f7, f8
        
        lwc1   f4, 0x0(t1)
        lwc1   f5, 0x4(t1)
        lwc1   f6, 0x8(t1)
        
        addi   t7, t7, -0x4 
        
        mul.s  f4, f4, f7
        mul.s  f5, f5, f7
        mul.s  f6, f6, f7
        
        addi   t6, t6, -0x4 
        
        add.s  f1, f1, f4
        add.s  f2, f2, f5
        add.s  f3, f3, f6
        
        addi   t3, t3, -0x1 
        
        lwc1   f7, 0x0(t7)
        
        slt    at, t3, zero
        beqz   at, l_00299F00
    
        lw     t1, 0x0(t6)
        
        swc1   f1, 0x0(t5)
        swc1   f2, 0x4(t5)
        swc1   f3, 0x8(t5)
        
    l_00299F50:
        addiu  a2, a2, 0x4
        addiu  v1, v1, -0x1
        
    l_00299F58:
        bgtz   v1, l_00299DDC
        nop
    .set reorder
    " : : "r"(fm), "r"(jaw) : 
    ); 

    asm("addiu  sp, sp, 0x100");
}

// 99.32% matching
void _fmCnkCalcJaw(MASK_WORK* fm) 
{
    int i;                
    TANG_WORK* jaw;       
    unsigned char mt1[64], mt2[64];
    NJS_MATRIX* mat, *mat2;       
    float* dvp;           
    NJS_POINT4* dvp1;      
    NJS_POINT4 vec;       
    unsigned int vofs;    
    NJS_MATRIX* jmat1, *jmat2;   
    float jawang, jawtrans;         

    mat = (NJS_MATRIX*)mt1;
    mat2 = (NJS_MATRIX*)mt2;

    if (fm->jnum != 0) 
    {
        jawang = -fm->param.jawang;
        jawtrans = fm->param.jawtrans;
        
        jmat1 = &fm->jmat1;
        jmat2 = &fm->jmat2;
        
        njSetMatrix(mat, jmat2);
        
        njRotateX(mat, (int)(182.04445f * jawang) & 0xFFFF);
        njTranslate(mat, jawtrans, 0, 0);
        
        njMultiMatrix(mat, jmat1);
        
        jaw = fm->jaw;
        
        vofs = fm->vofs;
        
        dvp = (float*)&fm->dst->vlist[fm->vtop];
        
        for (i = fm->jnum; i > 0; i--)  
        {
            dvp1 = (NJS_POINT4*)&dvp[jaw->id * vofs];
            
            if (jaw->rate == 1.0f) 
            {
                asm volatile
                ("
                .set noreorder
                    ldl         t0, 0x7(%2) 
                    ldr         t0,   0(%2)
                    
                    lw          t1, NJS_POINT4.z(%2) 
                    
                    pcpyld      t0, t1, t0
                
                    qmtc2       t0, vf4
                
                    lqc2        vf5,    0(%1)
                    lqc2        vf6, 0x10(%1)
                    lqc2        vf7, 0x20(%1) 
                    lqc2        vf8, 0x30(%1) 
                    
                    vmulax.xyz  ACC,  vf5, vf4
                    
                    vmadday.xyz ACC,  vf6, vf4
                    vmaddaz.xyz ACC,  vf7, vf4
                    vmaddw.xyz  vf18, vf8, vf0w
                    
                    qmfc2       t0, vf18
                
                    pcpyud      t1, t0, t0
                
                    sdl         t0, 0x7(%0)
                    sdr         t0,   0(%0) 
                    
                    sw          t1, NJS_POINT4.z(%0) 
                .set reorder
                " : : "r"(&vec), "r"(mat), "r"(dvp1) : 
                ); 
            } 
            else 
            {
                njCopyMatrix(mat2, jmat2);
                
                njRotateX(mat2, (int)(182.04445f * (jawang * jaw->rate)) & 0xFFFF);
                
                asm volatile
                ("
                .set noreorder
                    mfc1        t0, %4
                    
                    lqc2        vf5,    0(%3)
                    lqc2        vf6, 0x10(%3)
                    lqc2        vf7, 0x20(%3)
                    lqc2        vf8, 0x30(%3) 
                    
                    qmtc2       t0, vf4 
                
                    lqc2        vf9,     0(%2)  
                    lqc2        vf10, 0x10(%2)
                    lqc2        vf11, 0x20(%2)
                    lqc2        vf12, 0x30(%2)
                    
                    vmulax.xyz  ACC, vf5, vf4
                    
                    vmaddax.xyz ACC, vf6, vf0
                    vmaddax.xyz ACC, vf7, vf0
                    vmaddw.xyz  vf8, vf8, vf0w
                    
                    ldl         t0, 0x7(%1) 
                    ldr         t0,   0(%1) 
                    
                    lw          t1, NJS_POINT4.z(%1) 
                    
                    vmulax.xyz  ACC, vf5, vf9
                    
                    vmadday.xyz ACC, vf6, vf9
                    vmaddz.xyz  vf9, vf7, vf9
                    
                    pcpyld      t0, t1, t0
                
                    vmulax.xyz  ACC,  vf5, vf10
                    
                    vmadday.xyz ACC,  vf6, vf10
                    vmaddz.xyz  vf10, vf7, vf10
                    
                    qmtc2       t0, vf13
                
                    vmulax.xyz  ACC,  vf5, vf11
                    
                    vmadday.xyz ACC,  vf6, vf11
                    vmaddz.xyz  vf11, vf7, vf11
                    
                    vmulax.xyz  ACC,  vf5, vf12
                    
                    vmadday.xyz ACC,  vf6, vf12
                    vmaddaz.xyz ACC,  vf7, vf12
                    vmaddw.xyz  vf12, vf8, vf0w
                    
                    vmulax.xyz  ACC,  vf9,  vf13
                    
                    vmadday.xyz ACC,  vf10, vf13
                    vmaddaz.xyz ACC,  vf11, vf13
                    vmaddw.xyz  vf18, vf12, vf0w
                    
                    qmfc2       t0, vf18 
                
                    pcpyud      t1, t0, t0
                
                    sdl         t0, 0x7(%0) 
                    sdr         t0,   0(%0) 
                    
                    sw          t1, NJS_POINT4.z(%0) 
                .set reorder
                " : : "r"(&vec), "r"(dvp1), "r"(jmat1), "r"(mat2), "f"(jawtrans) : 
                ); 
            }
            
            *(u_long128*)dvp1 = *(u_long128*)&vec;
            
            jaw++;
        }
        
        if (fm->toothsrc != NULL) 
        {
            fm->toothsrc->ang[0] = (int)(182.04445f * jawang) & 0xFFFF;
        }
        
        if (fm->tangorg != NULL) 
        {
            fm->tangorg->ang[0] = (int)(182.04445f * jawang) & 0xFFFF;
        }
    }
}

// 100% matching! 
void _fmCnkCalcEye(MASK_WORK* fm) 
{
    float dx;            
    float dy;         
    float dz;          
    NJS_CNK_OBJECT* obj;
    NJS_POINT3 t3;      
    NJS_POINT3 q3;      
    NJS_POINT3 r3;       
    int i;             

    t3.x = 0;
    t3.y = 0;
    t3.z = -100.0f;
    
    for (i = 0; i < 9; i++) 
    {
        obj = fm->eyesrc[i];
        
        if (obj != NULL) 
        { 
            njPushMatrix(NULL);
            
            asm volatile
            ("
            .set noreorder
                ldl         t0, 7(%1)
                ldr         t0, 0(%1)
                lw          t1, NJS_POINT3.z(%1)
                
                pcpyld      t0, t1, t0
            
                qmtc2       t0, vf4
            
                ldl         t2, 7(%3)
                ldr         t2, 0(%3)
                lw          t3, NJS_POINT3.z(%3)
                
                pcpyld      t2, t3, t2
            
                qmtc2       t2, vf5
            
                ldl         t4, 7(%5)
                ldr         t4, 0(%5)
                lw          t5, NJS_POINT3.z(%5)
                
                pcpyld      t4, t5, t4
        
                qmtc2       t4, vf6
            
                lqc2        vf7,     0(%0)
                lqc2        vf8,  0x10(%0)
                lqc2        vf9,  0x20(%0)
                lqc2        vf10, 0x30(%0)
                
                vmulax.xyz  ACC,  vf7,  vf4
                
                vmadday.xyz ACC,  vf8,  vf4
                vmaddaz.xyz ACC,  vf9,  vf4
                vmaddw.xyz  vf11, vf10, vf0
                
                vmulax.xyz  ACC,  vf7,  vf5
                
                vmadday.xyz ACC,  vf8,  vf5
                vmaddaz.xyz ACC,  vf9,  vf5
                vmaddw.xyz  vf12, vf10, vf0
                
                vadd.xyz    vf7,  vf11, vf6
                vsub.xyz    vf8,  vf7,  vf11
                
                qmfc2       t0, vf12
                qmfc2       t2, vf8
            
                pcpyud      t1, t0, t0
                pcpyud      t3, t2, t2
            
                sdl         t0, 7(%4)
                sdr         t0, 0(%4)
                sw          t1, NJS_POINT3.z(%4)
                
                sdl         t2, 7(%2)
                sdr         t2, 0(%2)
                sw          t3, NJS_POINT3.z(%2)
            .set reorder
            " : : "r"(&fm->eyemat[i]), "r"(&obj->pos), "r"(&q3), "r"(&t3), "r"(&r3), "r"(&fm->param.eye) : 
            ); 

            dx = q3.x;
            dy = q3.y;
            dz = q3.z;
           
            if (r3.z < 0) 
            {
                obj->ang[0] = (int)(10430.381f * atanf(dy * njInvertSqrt((dx * dx) + (dz * dz))));
            } 
            else 
            {
                obj->ang[0] = -(int)(10430.381f * atanf(dy * njInvertSqrt((dx * dx) + (dz * dz))));
            }
            
            if (dz < 0) 
            {
                obj->ang[1] = (int)(10430.381f * atanf(dx / dz));
            }
            else 
            {
                obj->ang[1] = (int)(10430.381f * atanf(dx / dz)) + (32767 + 1);
            }
            
            obj->ang[2] = 0;
            
            njPopMatrix(1);
        }
    }
}

// 99.35% matching
void _fmCnkCalcTang(MASK_WORK* fm) 
{
    int i;                
    TANG_WORK* tang;       
    unsigned char mt1[64]; 
    NJS_MATRIX* mat;       
    float* svp, *dvp;         
    unsigned int vofs;     
    float tangx, tangy, tangz;           
    unsigned int calc_ofs; 
    
    i = fm->tnum;

    mat = (NJS_MATRIX*)mt1;
    
    if (i != 0) 
    {
        svp = (float*)&fm->tangsrc->vlist[fm->vtop];
        dvp = (float*)&fm->tangdst->vlist[fm->vtop];
        
        tangx = fm->param.tangx;
        tangy = fm->param.tangy;
        tangz = fm->param.tangz;
        
        vofs = fm->vofs;
        
        tang = fm->tang;
       
        for ( ; i > 0; i--) 
        { 
            asm volatile
            ("
            .set noreorder
                vmulw.xyzw vf4, vf0, vf0w
                
                vmr32.xyzw vf5, vf4
                vmr32.xyzw vf6, vf5
                vmr32.xyzw vf7, vf6
                
                sqc2       vf4, 0x30(%0)
                sqc2       vf5, 0x20(%0)
                sqc2       vf6, 0x10(%0)
                sqc2       vf7,    0(%0)
            .set reorder
            " : : "r"(mat) : 
            ); 
            
            njRotateX(mat, (int)(182.04445f * (tangx * tang->rate)) & 0xFFFF);
            njRotateY(mat, (int)(182.04445f * (tangy * tang->rate)) & 0xFFFF);
            
            calc_ofs = tang->id * vofs;
            
            asm volatile  
            ("
            .set noreorder
                mfc1        t2, %2
                
                ldl         t0, 0x7(%0)
                ldr         t0,   0(%0)
                
                lw          t1, 0x8(%0)
                
                pcpyld      t0, t1, t0
            
                qmtc2       t2, vf9
                qmtc2       t0, vf4
            
                lqc2        vf5,    0(%3)
                lqc2        vf6, 0x10(%3)
                lqc2        vf7, 0x20(%3)
                lqc2        vf8, 0x30(%3)
                
                vmulx.xyz   vf7,  vf7, vf9x
                vmulax.xyz  ACC,  vf5, vf4x
                
                vmadday.xyz ACC,  vf6, vf4y
                vmaddaz.xyz ACC,  vf7, vf4z
                vmaddw.xyz  vf18, vf8, vf0w
                
                qmfc2       t0, vf18
            
                pcpyud      t1, t0, t0
            
                sdl         t0, 7(%1)
                sdr         t0, 0(%1)
                
                sw          t1, 8(%1)
            .set reorder
            " : : "r"(&svp[calc_ofs]), "r"(&dvp[calc_ofs]), "f"(tangz), "r"(mat) : 
            );
            
            tang++; 
        }
    }
}

// 100% matching! 
void _fmCnkCalcNormal(MASK_WORK* fm) 
{
    int i, n;             
    float* dvp, *dnp;        
    NJS_POINT3* dvp1, *dnp1;  
    NJS_POINT3 norm;   
    VLIST_WORK* list;  
    NJS_POINT3** nvp;  
    unsigned int vofs; 

    dvp = (float*)&fm->dst->vlist[fm->vtop];
    dnp = (float*)&fm->dst->vlist[fm->ntop];
    
    list = fm->vlist;
    
    nvp = (NJS_POINT3**)fm->nvpt;
    
    vofs = fm->vofs;
    
    for (n = 0; n++ < fm->lnum; list++) 
    {
        dvp1 = (NJS_POINT3*)&dvp[list->id * vofs];
        dnp1 = (NJS_POINT3*)&dnp[list->id * vofs];
        
        dnp1->z = 0;
        dnp1->y = 0;
        dnp1->x = 0;
        
        for (i = 0; i++ < list->nvnum; )
        {
            njGetPlaneNormal2(dvp1, nvp[0], nvp[1], &norm);
            
            njUnitVector(&norm);
            
            nvp += 2; 
            
            dnp1->x += norm.x;
            dnp1->y += norm.y;
            dnp1->z += norm.z;
        }
        
        njUnitVector(dnp1);
    }
}

// 100% matching!
void fmCnkCalcFace(MASK_WORK* fm) 
{
    if (fm->dst != NULL) 
    {
        _fmCnkCalcMuscle(fm);
        _fmCnkCalcJaw(fm);
        _fmCnkCalcTang(fm);
        _fmCnkCalcEye(fm);
        
        if (!(fm->mode & 0x1)) 
        {
            _fmCnkCalcNormal(fm);
        }
    }
}

// 100% matching!
void fmCnkSetMode(MASK_WORK* fm, unsigned int mode)
{	
    float* snp, *dnp;
    int i;

    if ((!(fm->mode & 0x1)) && ((mode & 0x1))) 
    {
        snp = (float*)&fm->src->vlist[fm->ntop];
        dnp = (float*)&fm->dst->vlist[fm->ntop];

        for (i = fm->src->vlist[1] >> 16; i > 0; i--, snp += 8, dnp += 8)
        {
            *(u_long128*)dnp = *(u_long128*)snp;
        }
    }
    
    fm->mode = mode;
}
