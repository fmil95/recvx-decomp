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

// 
// Start address: 0x299d30
void _fmCnkCalcMuscle(MASK_WORK* fm)
{
	float rsum;
	unsigned int vofs;
	float para;
	//_anon3* jaw;
	float rate;
	float sum;
	float* mrp;
	//_anon0** mvp;
	float mrate[32];
	//_anon0* mvec[32];
	float* param;
	//_anon6* list;
	//_anon7* con;
	float* dvp;
	float* svp;
	int m;
	int n;
	int i;
	// Line 1513, Address: 0x299d30, Func Offset: 0
	// Line 1514, Address: 0x299d34, Func Offset: 0x4
	// Line 1513, Address: 0x299d38, Func Offset: 0x8
	// Line 1517, Address: 0x299d3c, Func Offset: 0xc
	// Line 1492, Address: 0x299d40, Func Offset: 0x10
	// Line 1513, Address: 0x299d44, Func Offset: 0x14
	// Line 1514, Address: 0x299d48, Func Offset: 0x18
	// Line 1513, Address: 0x299d4c, Func Offset: 0x1c
	// Line 1536, Address: 0x299d50, Func Offset: 0x20
	// Line 1514, Address: 0x299d54, Func Offset: 0x24
	// Line 1513, Address: 0x299d58, Func Offset: 0x28
	// Line 1536, Address: 0x299d5c, Func Offset: 0x2c
	// Line 1537, Address: 0x299d6c, Func Offset: 0x3c
	// Line 1539, Address: 0x299d78, Func Offset: 0x48
	// Line 1541, Address: 0x299d80, Func Offset: 0x50
	// Line 1544, Address: 0x299d8c, Func Offset: 0x5c
	// Line 1545, Address: 0x299d98, Func Offset: 0x68
	// Line 1546, Address: 0x299d9c, Func Offset: 0x6c
	// Line 1547, Address: 0x299da0, Func Offset: 0x70
	// Line 1548, Address: 0x299da4, Func Offset: 0x74
	// Line 1549, Address: 0x299da8, Func Offset: 0x78
	// Line 1550, Address: 0x299dac, Func Offset: 0x7c
	// Line 1551, Address: 0x299db0, Func Offset: 0x80
	// Line 1561, Address: 0x299dbc, Func Offset: 0x8c
	// Line 1562, Address: 0x299dc0, Func Offset: 0x90
	// Line 1564, Address: 0x299dc4, Func Offset: 0x94
	// Line 1566, Address: 0x299dc8, Func Offset: 0x98
	// Line 1571, Address: 0x299ddc, Func Offset: 0xac
	// Line 1567, Address: 0x299de4, Func Offset: 0xb4
	// Line 1568, Address: 0x299de8, Func Offset: 0xb8
	// Line 1569, Address: 0x299dec, Func Offset: 0xbc
	// Line 1571, Address: 0x299df0, Func Offset: 0xc0
	// Line 1570, Address: 0x299df8, Func Offset: 0xc8
	// Line 1571, Address: 0x299dfc, Func Offset: 0xcc
	// Line 1572, Address: 0x299e08, Func Offset: 0xd8
	// Line 1573, Address: 0x299e0c, Func Offset: 0xdc
	// Line 1574, Address: 0x299e14, Func Offset: 0xe4
	// Line 1575, Address: 0x299e24, Func Offset: 0xf4
	// Line 1576, Address: 0x299e34, Func Offset: 0x104
	// Line 1577, Address: 0x299e38, Func Offset: 0x108
	// Line 1576, Address: 0x299e3c, Func Offset: 0x10c
	// Line 1577, Address: 0x299e40, Func Offset: 0x110
	// Line 1580, Address: 0x299e5c, Func Offset: 0x12c
	// Line 1577, Address: 0x299e60, Func Offset: 0x130
	// Line 1579, Address: 0x299e64, Func Offset: 0x134
	// Line 1578, Address: 0x299e6c, Func Offset: 0x13c
	// Line 1579, Address: 0x299e70, Func Offset: 0x140
	// Line 1581, Address: 0x299e74, Func Offset: 0x144
	// Line 1582, Address: 0x299e78, Func Offset: 0x148
	// Line 1583, Address: 0x299e7c, Func Offset: 0x14c
	// Line 1584, Address: 0x299e80, Func Offset: 0x150
	// Line 1586, Address: 0x299e90, Func Offset: 0x160
	// Line 1587, Address: 0x299e9c, Func Offset: 0x16c
	// Line 1607, Address: 0x299ea4, Func Offset: 0x174
	// Line 1587, Address: 0x299eac, Func Offset: 0x17c
	// Line 1588, Address: 0x299ebc, Func Offset: 0x18c
	// Line 1587, Address: 0x299ec8, Func Offset: 0x198
	// Line 1588, Address: 0x299ecc, Func Offset: 0x19c
	// Line 1609, Address: 0x299ed0, Func Offset: 0x1a0
	// Line 1611, Address: 0x299edc, Func Offset: 0x1ac
	// Line 1612, Address: 0x299ee0, Func Offset: 0x1b0
	// Line 1613, Address: 0x299ee4, Func Offset: 0x1b4
	// Line 1614, Address: 0x299ee8, Func Offset: 0x1b8
	// Line 1615, Address: 0x299eec, Func Offset: 0x1bc
	// Line 1616, Address: 0x299ef0, Func Offset: 0x1c0
	// Line 1617, Address: 0x299ef4, Func Offset: 0x1c4
	// Line 1618, Address: 0x299ef8, Func Offset: 0x1c8
	// Line 1619, Address: 0x299efc, Func Offset: 0x1cc
	// Line 1621, Address: 0x299f00, Func Offset: 0x1d0
	// Line 1622, Address: 0x299f04, Func Offset: 0x1d4
	// Line 1623, Address: 0x299f08, Func Offset: 0x1d8
	// Line 1624, Address: 0x299f0c, Func Offset: 0x1dc
	// Line 1625, Address: 0x299f10, Func Offset: 0x1e0
	// Line 1626, Address: 0x299f14, Func Offset: 0x1e4
	// Line 1627, Address: 0x299f18, Func Offset: 0x1e8
	// Line 1628, Address: 0x299f1c, Func Offset: 0x1ec
	// Line 1629, Address: 0x299f20, Func Offset: 0x1f0
	// Line 1630, Address: 0x299f24, Func Offset: 0x1f4
	// Line 1631, Address: 0x299f28, Func Offset: 0x1f8
	// Line 1632, Address: 0x299f2c, Func Offset: 0x1fc
	// Line 1633, Address: 0x299f30, Func Offset: 0x200
	// Line 1634, Address: 0x299f34, Func Offset: 0x204
	// Line 1635, Address: 0x299f38, Func Offset: 0x208
	// Line 1637, Address: 0x299f44, Func Offset: 0x214
	// Line 1638, Address: 0x299f48, Func Offset: 0x218
	// Line 1639, Address: 0x299f4c, Func Offset: 0x21c
	// Line 1644, Address: 0x299f50, Func Offset: 0x220
	// Line 1645, Address: 0x299f54, Func Offset: 0x224
	// Line 1646, Address: 0x299f58, Func Offset: 0x228
	// Line 1652, Address: 0x299f60, Func Offset: 0x230
	// Func End, Address: 0x299f68, Func Offset: 0x238
	scePrintf("_fmCnkCalcMuscle - UNIMPLEMENTED!\n");
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
