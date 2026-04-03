#include "face.h"
#include "face_bh.h"
#include "ps2_NaMatrix.h"
#include "ps2_NaMem.h"
#include "pwksub.h"

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

/*// 
// Start address: 0x299280
void _fmCnkSetJaw(MASK_WORK* fm, unsigned int v0, unsigned int v1)
{
	float svp0[4];
	unsigned int vofs;
	int rz;
	int ry;
	float z;
	float y;
	float x;
	float* svp;
	// Line 797, Address: 0x299280, Func Offset: 0
	// Line 804, Address: 0x2992a8, Func Offset: 0x28
	// Line 806, Address: 0x2992ac, Func Offset: 0x2c
	// Line 807, Address: 0x2992b4, Func Offset: 0x34
	// Line 812, Address: 0x2992b8, Func Offset: 0x38
	// Line 811, Address: 0x2992bc, Func Offset: 0x3c
	// Line 806, Address: 0x2992c0, Func Offset: 0x40
	// Line 813, Address: 0x2992c8, Func Offset: 0x48
	// Line 806, Address: 0x2992cc, Func Offset: 0x4c
	// Line 807, Address: 0x2992d0, Func Offset: 0x50
	// Line 811, Address: 0x2992d4, Func Offset: 0x54
	// Line 806, Address: 0x2992d8, Func Offset: 0x58
	// Line 807, Address: 0x2992dc, Func Offset: 0x5c
	// Line 811, Address: 0x2992e8, Func Offset: 0x68
	// Line 807, Address: 0x2992ec, Func Offset: 0x6c
	// Line 811, Address: 0x2992f0, Func Offset: 0x70
	// Line 812, Address: 0x2992f8, Func Offset: 0x78
	// Line 813, Address: 0x299300, Func Offset: 0x80
	// Line 811, Address: 0x299308, Func Offset: 0x88
	// Line 812, Address: 0x29930c, Func Offset: 0x8c
	// Line 814, Address: 0x299310, Func Offset: 0x90
	// Line 813, Address: 0x299314, Func Offset: 0x94
	// Line 814, Address: 0x299318, Func Offset: 0x98
	// Line 816, Address: 0x29933c, Func Offset: 0xbc
	// Line 821, Address: 0x299368, Func Offset: 0xe8
	// Line 823, Address: 0x299370, Func Offset: 0xf0
	// Line 824, Address: 0x299378, Func Offset: 0xf8
	// Line 825, Address: 0x299384, Func Offset: 0x104
	// Line 826, Address: 0x299390, Func Offset: 0x110
	// Line 829, Address: 0x2993b0, Func Offset: 0x130
	// Line 830, Address: 0x2993b8, Func Offset: 0x138
	// Line 831, Address: 0x2993cc, Func Offset: 0x14c
	// Line 832, Address: 0x2993d8, Func Offset: 0x158
	// Line 834, Address: 0x2993e4, Func Offset: 0x164
	// Line 837, Address: 0x2993ec, Func Offset: 0x16c
	// Line 844, Address: 0x2993f8, Func Offset: 0x178
	// Line 845, Address: 0x2993fc, Func Offset: 0x17c
	// Line 849, Address: 0x299404, Func Offset: 0x184
	// Line 856, Address: 0x299410, Func Offset: 0x190
	// Line 857, Address: 0x299414, Func Offset: 0x194
	// Line 859, Address: 0x29941c, Func Offset: 0x19c
	// Func End, Address: 0x299448, Func Offset: 0x1c8
}*/

// 
// Start address: 0x299450
void fmCnkInitContext(MASK_WORK* fm, void* data, NJS_CNK_OBJECT* root, ML_WORK* mlwP)
{
	unsigned int vofs;
	NJS_CNK_OBJECT* obj;
	int j;
	int i;
	int* dvp;
	unsigned int* nlist;
	//_anon6* vlist;
	// Line 937, Address: 0x299450, Func Offset: 0
	// Line 945, Address: 0x299470, Func Offset: 0x20
	// Line 947, Address: 0x299484, Func Offset: 0x34
	// Line 949, Address: 0x299488, Func Offset: 0x38
	// Line 950, Address: 0x2994a8, Func Offset: 0x58
	// Line 951, Address: 0x2994bc, Func Offset: 0x6c
	// Line 952, Address: 0x2994c4, Func Offset: 0x74
	// Line 953, Address: 0x2994d0, Func Offset: 0x80
	// Line 955, Address: 0x2994dc, Func Offset: 0x8c
	// Line 956, Address: 0x2994f0, Func Offset: 0xa0
	// Line 957, Address: 0x2994f8, Func Offset: 0xa8
	// Line 958, Address: 0x299504, Func Offset: 0xb4
	// Line 961, Address: 0x299510, Func Offset: 0xc0
	// Line 962, Address: 0x299514, Func Offset: 0xc4
	// Line 963, Address: 0x29952c, Func Offset: 0xdc
	// Line 964, Address: 0x299534, Func Offset: 0xe4
	// Line 965, Address: 0x299548, Func Offset: 0xf8
	// Line 966, Address: 0x299554, Func Offset: 0x104
	// Line 967, Address: 0x299558, Func Offset: 0x108
	// Line 970, Address: 0x299568, Func Offset: 0x118
	// Line 975, Address: 0x29956c, Func Offset: 0x11c
	// Line 970, Address: 0x299570, Func Offset: 0x120
	// Line 971, Address: 0x299578, Func Offset: 0x128
	// Line 974, Address: 0x299590, Func Offset: 0x140
	// Line 972, Address: 0x299598, Func Offset: 0x148
	// Line 973, Address: 0x29959c, Func Offset: 0x14c
	// Line 976, Address: 0x2995a0, Func Offset: 0x150
	// Line 974, Address: 0x2995a4, Func Offset: 0x154
	// Line 977, Address: 0x2995ac, Func Offset: 0x15c
	// Line 979, Address: 0x2995b4, Func Offset: 0x164
	// Line 980, Address: 0x2995bc, Func Offset: 0x16c
	// Line 981, Address: 0x2995d0, Func Offset: 0x180
	// Line 982, Address: 0x2995d4, Func Offset: 0x184
	// Line 986, Address: 0x2995ec, Func Offset: 0x19c
	// Line 987, Address: 0x2995f0, Func Offset: 0x1a0
	// Line 988, Address: 0x299608, Func Offset: 0x1b8
	// Line 989, Address: 0x29960c, Func Offset: 0x1bc
	// Line 990, Address: 0x29962c, Func Offset: 0x1dc
	// Line 992, Address: 0x299644, Func Offset: 0x1f4
	// Line 993, Address: 0x29965c, Func Offset: 0x20c
	// Line 994, Address: 0x299668, Func Offset: 0x218
	// Line 995, Address: 0x299674, Func Offset: 0x224
	// Line 996, Address: 0x299680, Func Offset: 0x230
	// Line 997, Address: 0x29968c, Func Offset: 0x23c
	// Line 999, Address: 0x2996a0, Func Offset: 0x250
	// Line 1000, Address: 0x2996a8, Func Offset: 0x258
	// Func End, Address: 0x2996c4, Func Offset: 0x274
	scePrintf("fmCnkInitContext - UNIMPLEMENTED!\n");
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

/*// 
// Start address: 0x299770
void fmCnkSetInterParam(MASK_WORK* fm, PARAM_WORK* p1, PARAM_WORK* p2, float t, float lv, unsigned int mask)
{
	float rate;
	int i;
	// Line 1250, Address: 0x299770, Func Offset: 0
	// Line 1255, Address: 0x299790, Func Offset: 0x20
	// Line 1261, Address: 0x2997dc, Func Offset: 0x6c
	// Line 1263, Address: 0x2997e4, Func Offset: 0x74
	// Line 1264, Address: 0x2997ec, Func Offset: 0x7c
	// Line 1267, Address: 0x2997f4, Func Offset: 0x84
	// Line 1268, Address: 0x299818, Func Offset: 0xa8
	// Line 1270, Address: 0x299820, Func Offset: 0xb0
	// Line 1277, Address: 0x299824, Func Offset: 0xb4
	// Line 1278, Address: 0x299834, Func Offset: 0xc4
	// Line 1280, Address: 0x299848, Func Offset: 0xd8
	// Line 1281, Address: 0x299864, Func Offset: 0xf4
	// Line 1282, Address: 0x299868, Func Offset: 0xf8
	// Line 1280, Address: 0x299870, Func Offset: 0x100
	// Line 1282, Address: 0x299878, Func Offset: 0x108
	// Line 1285, Address: 0x299880, Func Offset: 0x110
	// Line 1286, Address: 0x29989c, Func Offset: 0x12c
	// Line 1288, Address: 0x2998b8, Func Offset: 0x148
	// Line 1289, Address: 0x2998d0, Func Offset: 0x160
	// Line 1290, Address: 0x2998e8, Func Offset: 0x178
	// Line 1294, Address: 0x299900, Func Offset: 0x190
	// Line 1295, Address: 0x29991c, Func Offset: 0x1ac
	// Line 1296, Address: 0x299938, Func Offset: 0x1c8
	// Line 1297, Address: 0x299954, Func Offset: 0x1e4
	// Func End, Address: 0x299974, Func Offset: 0x204
}*/

// 
// Start address: 0x299980
void fmCnkSetInterParamLip(MASK_WORK* fm, PARAM_WORK* p1, PARAM_WORK* p2, float t, float lv, unsigned int mask)
{
	float* fm_muscle;
	float rate;
	int i;
	// Line 1313, Address: 0x299980, Func Offset: 0
	// Line 1321, Address: 0x2999a0, Func Offset: 0x20
	// Line 1327, Address: 0x2999ec, Func Offset: 0x6c
	// Line 1329, Address: 0x2999f4, Func Offset: 0x74
	// Line 1330, Address: 0x2999fc, Func Offset: 0x7c
	// Line 1333, Address: 0x299a04, Func Offset: 0x84
	// Line 1334, Address: 0x299a28, Func Offset: 0xa8
	// Line 1336, Address: 0x299a30, Func Offset: 0xb0
	// Line 1345, Address: 0x299a34, Func Offset: 0xb4
	// Line 1346, Address: 0x299a38, Func Offset: 0xb8
	// Line 1347, Address: 0x299a44, Func Offset: 0xc4
	// Line 1349, Address: 0x299a58, Func Offset: 0xd8
	// Line 1350, Address: 0x299a74, Func Offset: 0xf4
	// Line 1351, Address: 0x299a78, Func Offset: 0xf8
	// Line 1349, Address: 0x299a80, Func Offset: 0x100
	// Line 1351, Address: 0x299a88, Func Offset: 0x108
	// Line 1360, Address: 0x299a90, Func Offset: 0x110
	// Line 1361, Address: 0x299acc, Func Offset: 0x14c
	// Line 1362, Address: 0x299ae8, Func Offset: 0x168
	// Line 1363, Address: 0x299b1c, Func Offset: 0x19c
	// Line 1364, Address: 0x299b50, Func Offset: 0x1d0
	// Line 1365, Address: 0x299b6c, Func Offset: 0x1ec
	// Func End, Address: 0x299b8c, Func Offset: 0x20c
	scePrintf("fmCnkSetInterParamLip - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x299b90
void fmCnkSetCurrentFrame(MASK_WORK* fm, float frame)
{
	unsigned int key;
	int i;
	// Line 1376, Address: 0x299b90, Func Offset: 0
	// Line 1381, Address: 0x299bb0, Func Offset: 0x20
	// Line 1382, Address: 0x299bc8, Func Offset: 0x38
	// Line 1385, Address: 0x299bec, Func Offset: 0x5c
	// Line 1390, Address: 0x299c00, Func Offset: 0x70
	// Line 1391, Address: 0x299c08, Func Offset: 0x78
	// Line 1392, Address: 0x299c14, Func Offset: 0x84
	// Line 1393, Address: 0x299c1c, Func Offset: 0x8c
	// Line 1394, Address: 0x299c24, Func Offset: 0x94
	// Line 1395, Address: 0x299c4c, Func Offset: 0xbc
	// Line 1397, Address: 0x299c54, Func Offset: 0xc4
	// Line 1400, Address: 0x299c58, Func Offset: 0xc8
	// Line 1402, Address: 0x299cd8, Func Offset: 0x148
	// Func End, Address: 0x299cfc, Func Offset: 0x16c
	scePrintf("fmCnkSetCurrentFrame - UNIMPLEMENTED!\n");
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

// 
// Start address: 0x299f70
void _fmCnkCalcJaw(MASK_WORK* fm)
{
	float jawtrans;
	float jawang;
	float jmat2[16];
	float jmat1[16];
	unsigned int vofs;
	//_anon13 vec;
	//_anon13* dvp1;
	float* dvp;
	float mat2[16];
	float mat[16];
	unsigned char mt2[64];
	unsigned char mt1[64];
	//_anon3* jaw;
	int i;
	// Line 2051, Address: 0x299f70, Func Offset: 0
	// Line 2076, Address: 0x299fa4, Func Offset: 0x34
	// Line 2058, Address: 0x299fa8, Func Offset: 0x38
	// Line 2059, Address: 0x299fac, Func Offset: 0x3c
	// Line 2076, Address: 0x299fb0, Func Offset: 0x40
	// Line 2082, Address: 0x299fb8, Func Offset: 0x48
	// Line 2085, Address: 0x299fbc, Func Offset: 0x4c
	// Line 2083, Address: 0x299fc0, Func Offset: 0x50
	// Line 2084, Address: 0x299fc4, Func Offset: 0x54
	// Line 2087, Address: 0x299fc8, Func Offset: 0x58
	// Line 2082, Address: 0x299fcc, Func Offset: 0x5c
	// Line 2087, Address: 0x299fd0, Func Offset: 0x60
	// Line 2088, Address: 0x299fd8, Func Offset: 0x68
	// Line 2089, Address: 0x299ff8, Func Offset: 0x88
	// Line 2090, Address: 0x29a00c, Func Offset: 0x9c
	// Line 2093, Address: 0x29a018, Func Offset: 0xa8
	// Line 2094, Address: 0x29a020, Func Offset: 0xb0
	// Line 2095, Address: 0x29a024, Func Offset: 0xb4
	// Line 2096, Address: 0x29a028, Func Offset: 0xb8
	// Line 2093, Address: 0x29a02c, Func Offset: 0xbc
	// Line 2096, Address: 0x29a038, Func Offset: 0xc8
	// Line 2097, Address: 0x29a040, Func Offset: 0xd0
	// Line 2098, Address: 0x29a044, Func Offset: 0xd4
	// Line 2097, Address: 0x29a050, Func Offset: 0xe0
	// Line 2098, Address: 0x29a054, Func Offset: 0xe4
	// Line 2097, Address: 0x29a058, Func Offset: 0xe8
	// Line 2098, Address: 0x29a060, Func Offset: 0xf0
	// Line 2102, Address: 0x29a068, Func Offset: 0xf8
	// Line 2104, Address: 0x29a06c, Func Offset: 0xfc
	// Line 2105, Address: 0x29a070, Func Offset: 0x100
	// Line 2106, Address: 0x29a074, Func Offset: 0x104
	// Line 2107, Address: 0x29a078, Func Offset: 0x108
	// Line 2108, Address: 0x29a07c, Func Offset: 0x10c
	// Line 2109, Address: 0x29a080, Func Offset: 0x110
	// Line 2110, Address: 0x29a084, Func Offset: 0x114
	// Line 2111, Address: 0x29a088, Func Offset: 0x118
	// Line 2112, Address: 0x29a08c, Func Offset: 0x11c
	// Line 2113, Address: 0x29a090, Func Offset: 0x120
	// Line 2114, Address: 0x29a094, Func Offset: 0x124
	// Line 2115, Address: 0x29a098, Func Offset: 0x128
	// Line 2116, Address: 0x29a09c, Func Offset: 0x12c
	// Line 2117, Address: 0x29a0a0, Func Offset: 0x130
	// Line 2118, Address: 0x29a0a4, Func Offset: 0x134
	// Line 2119, Address: 0x29a0a8, Func Offset: 0x138
	// Line 2120, Address: 0x29a0ac, Func Offset: 0x13c
	// Line 2121, Address: 0x29a0b0, Func Offset: 0x140
	// Line 2125, Address: 0x29a0b4, Func Offset: 0x144
	// Line 2131, Address: 0x29a0bc, Func Offset: 0x14c
	// Line 2139, Address: 0x29a0c8, Func Offset: 0x158
	// Line 2140, Address: 0x29a0f4, Func Offset: 0x184
	// Line 2142, Address: 0x29a0f8, Func Offset: 0x188
	// Line 2143, Address: 0x29a0fc, Func Offset: 0x18c
	// Line 2144, Address: 0x29a100, Func Offset: 0x190
	// Line 2145, Address: 0x29a104, Func Offset: 0x194
	// Line 2146, Address: 0x29a108, Func Offset: 0x198
	// Line 2147, Address: 0x29a10c, Func Offset: 0x19c
	// Line 2148, Address: 0x29a110, Func Offset: 0x1a0
	// Line 2149, Address: 0x29a114, Func Offset: 0x1a4
	// Line 2150, Address: 0x29a118, Func Offset: 0x1a8
	// Line 2151, Address: 0x29a11c, Func Offset: 0x1ac
	// Line 2152, Address: 0x29a120, Func Offset: 0x1b0
	// Line 2153, Address: 0x29a124, Func Offset: 0x1b4
	// Line 2154, Address: 0x29a128, Func Offset: 0x1b8
	// Line 2155, Address: 0x29a12c, Func Offset: 0x1bc
	// Line 2156, Address: 0x29a130, Func Offset: 0x1c0
	// Line 2157, Address: 0x29a134, Func Offset: 0x1c4
	// Line 2158, Address: 0x29a138, Func Offset: 0x1c8
	// Line 2159, Address: 0x29a13c, Func Offset: 0x1cc
	// Line 2160, Address: 0x29a140, Func Offset: 0x1d0
	// Line 2161, Address: 0x29a144, Func Offset: 0x1d4
	// Line 2162, Address: 0x29a148, Func Offset: 0x1d8
	// Line 2163, Address: 0x29a14c, Func Offset: 0x1dc
	// Line 2164, Address: 0x29a150, Func Offset: 0x1e0
	// Line 2165, Address: 0x29a154, Func Offset: 0x1e4
	// Line 2166, Address: 0x29a158, Func Offset: 0x1e8
	// Line 2167, Address: 0x29a15c, Func Offset: 0x1ec
	// Line 2168, Address: 0x29a160, Func Offset: 0x1f0
	// Line 2169, Address: 0x29a164, Func Offset: 0x1f4
	// Line 2170, Address: 0x29a168, Func Offset: 0x1f8
	// Line 2171, Address: 0x29a16c, Func Offset: 0x1fc
	// Line 2172, Address: 0x29a170, Func Offset: 0x200
	// Line 2173, Address: 0x29a174, Func Offset: 0x204
	// Line 2174, Address: 0x29a178, Func Offset: 0x208
	// Line 2175, Address: 0x29a17c, Func Offset: 0x20c
	// Line 2176, Address: 0x29a180, Func Offset: 0x210
	// Line 2177, Address: 0x29a184, Func Offset: 0x214
	// Line 2178, Address: 0x29a188, Func Offset: 0x218
	// Line 2179, Address: 0x29a18c, Func Offset: 0x21c
	// Line 2180, Address: 0x29a190, Func Offset: 0x220
	// Line 2181, Address: 0x29a194, Func Offset: 0x224
	// Line 2182, Address: 0x29a198, Func Offset: 0x228
	// Line 2186, Address: 0x29a19c, Func Offset: 0x22c
	// Line 2187, Address: 0x29a1a0, Func Offset: 0x230
	// Line 2191, Address: 0x29a1a8, Func Offset: 0x238
	// Line 2192, Address: 0x29a1ac, Func Offset: 0x23c
	// Line 2187, Address: 0x29a1b0, Func Offset: 0x240
	// Line 2192, Address: 0x29a1b4, Func Offset: 0x244
	// Line 2195, Address: 0x29a1c0, Func Offset: 0x250
	// Line 2196, Address: 0x29a1cc, Func Offset: 0x25c
	// Line 2200, Address: 0x29a1ec, Func Offset: 0x27c
	// Line 2201, Address: 0x29a1f8, Func Offset: 0x288
	// Line 2206, Address: 0x29a218, Func Offset: 0x2a8
	// Func End, Address: 0x29a250, Func Offset: 0x2e0
	scePrintf("_fmCnkCalcJaw - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x29a250
void _fmCnkCalcEye(MASK_WORK* fm)
{
	int i;
	//_anon0 r3;
	//_anon0 q3;
	//_anon0 t3;
	//cnkobj* obj;
	float dz;
	float dy;
	float dx;
	// Line 2294, Address: 0x29a250, Func Offset: 0
	// Line 2304, Address: 0x29a270, Func Offset: 0x20
	// Line 2305, Address: 0x29a274, Func Offset: 0x24
	// Line 2306, Address: 0x29a278, Func Offset: 0x28
	// Line 2307, Address: 0x29a284, Func Offset: 0x34
	// Line 2308, Address: 0x29a28c, Func Offset: 0x3c
	// Line 2309, Address: 0x29a298, Func Offset: 0x48
	// Line 2310, Address: 0x29a2a0, Func Offset: 0x50
	// Line 2325, Address: 0x29a2a8, Func Offset: 0x58
	// Line 2327, Address: 0x29a2c8, Func Offset: 0x78
	// Line 2328, Address: 0x29a2cc, Func Offset: 0x7c
	// Line 2329, Address: 0x29a2d0, Func Offset: 0x80
	// Line 2330, Address: 0x29a2d4, Func Offset: 0x84
	// Line 2331, Address: 0x29a2d8, Func Offset: 0x88
	// Line 2332, Address: 0x29a2dc, Func Offset: 0x8c
	// Line 2333, Address: 0x29a2e0, Func Offset: 0x90
	// Line 2334, Address: 0x29a2e4, Func Offset: 0x94
	// Line 2335, Address: 0x29a2e8, Func Offset: 0x98
	// Line 2336, Address: 0x29a2ec, Func Offset: 0x9c
	// Line 2337, Address: 0x29a2f0, Func Offset: 0xa0
	// Line 2338, Address: 0x29a2f4, Func Offset: 0xa4
	// Line 2339, Address: 0x29a2f8, Func Offset: 0xa8
	// Line 2340, Address: 0x29a2fc, Func Offset: 0xac
	// Line 2341, Address: 0x29a300, Func Offset: 0xb0
	// Line 2342, Address: 0x29a304, Func Offset: 0xb4
	// Line 2343, Address: 0x29a308, Func Offset: 0xb8
	// Line 2344, Address: 0x29a30c, Func Offset: 0xbc
	// Line 2345, Address: 0x29a310, Func Offset: 0xc0
	// Line 2346, Address: 0x29a314, Func Offset: 0xc4
	// Line 2347, Address: 0x29a318, Func Offset: 0xc8
	// Line 2348, Address: 0x29a31c, Func Offset: 0xcc
	// Line 2349, Address: 0x29a320, Func Offset: 0xd0
	// Line 2350, Address: 0x29a324, Func Offset: 0xd4
	// Line 2351, Address: 0x29a328, Func Offset: 0xd8
	// Line 2352, Address: 0x29a32c, Func Offset: 0xdc
	// Line 2353, Address: 0x29a330, Func Offset: 0xe0
	// Line 2354, Address: 0x29a334, Func Offset: 0xe4
	// Line 2355, Address: 0x29a338, Func Offset: 0xe8
	// Line 2356, Address: 0x29a33c, Func Offset: 0xec
	// Line 2357, Address: 0x29a340, Func Offset: 0xf0
	// Line 2358, Address: 0x29a344, Func Offset: 0xf4
	// Line 2359, Address: 0x29a348, Func Offset: 0xf8
	// Line 2360, Address: 0x29a34c, Func Offset: 0xfc
	// Line 2361, Address: 0x29a350, Func Offset: 0x100
	// Line 2362, Address: 0x29a354, Func Offset: 0x104
	// Line 2363, Address: 0x29a358, Func Offset: 0x108
	// Line 2364, Address: 0x29a35c, Func Offset: 0x10c
	// Line 2365, Address: 0x29a360, Func Offset: 0x110
	// Line 2375, Address: 0x29a364, Func Offset: 0x114
	// Line 2369, Address: 0x29a36c, Func Offset: 0x11c
	// Line 2370, Address: 0x29a370, Func Offset: 0x120
	// Line 2375, Address: 0x29a374, Func Offset: 0x124
	// Line 2377, Address: 0x29a384, Func Offset: 0x134
	// Line 2381, Address: 0x29a3ac, Func Offset: 0x15c
	// Line 2384, Address: 0x29a3b4, Func Offset: 0x164
	// Line 2388, Address: 0x29a3e4, Func Offset: 0x194
	// Line 2389, Address: 0x29a3e8, Func Offset: 0x198
	// Line 2390, Address: 0x29a400, Func Offset: 0x1b0
	// Line 2391, Address: 0x29a430, Func Offset: 0x1e0
	// Line 2393, Address: 0x29a438, Func Offset: 0x1e8
	// Line 2394, Address: 0x29a474, Func Offset: 0x224
	// Line 2396, Address: 0x29a478, Func Offset: 0x228
	// Line 2397, Address: 0x29a484, Func Offset: 0x234
	// Line 2398, Address: 0x29a488, Func Offset: 0x238
	// Line 2402, Address: 0x29a49c, Func Offset: 0x24c
	// Func End, Address: 0x29a4c0, Func Offset: 0x270
	scePrintf("_fmCnkCalcEye - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x29a4c0
void _fmCnkCalcTang(MASK_WORK* fm)
{
	unsigned int calc_ofs;
	float tangz;
	float tangy;
	float tangx;
	unsigned int vofs;
	float* dvp;
	float* svp;
	float mat[16];
	unsigned char mt1[64];
	//_anon3* tang;
	int i;
	// Line 2446, Address: 0x29a4c0, Func Offset: 0
	// Line 2464, Address: 0x29a4ec, Func Offset: 0x2c
	// Line 2474, Address: 0x29a4f8, Func Offset: 0x38
	// Line 2475, Address: 0x29a4fc, Func Offset: 0x3c
	// Line 2474, Address: 0x29a500, Func Offset: 0x40
	// Line 2470, Address: 0x29a504, Func Offset: 0x44
	// Line 2471, Address: 0x29a508, Func Offset: 0x48
	// Line 2472, Address: 0x29a50c, Func Offset: 0x4c
	// Line 2474, Address: 0x29a510, Func Offset: 0x50
	// Line 2475, Address: 0x29a514, Func Offset: 0x54
	// Line 2473, Address: 0x29a518, Func Offset: 0x58
	// Line 2476, Address: 0x29a51c, Func Offset: 0x5c
	// Line 2474, Address: 0x29a520, Func Offset: 0x60
	// Line 2499, Address: 0x29a528, Func Offset: 0x68
	// Line 2517, Address: 0x29a530, Func Offset: 0x70
	// Line 2518, Address: 0x29a534, Func Offset: 0x74
	// Line 2519, Address: 0x29a538, Func Offset: 0x78
	// Line 2520, Address: 0x29a53c, Func Offset: 0x7c
	// Line 2521, Address: 0x29a540, Func Offset: 0x80
	// Line 2522, Address: 0x29a544, Func Offset: 0x84
	// Line 2523, Address: 0x29a548, Func Offset: 0x88
	// Line 2524, Address: 0x29a54c, Func Offset: 0x8c
	// Line 2527, Address: 0x29a550, Func Offset: 0x90
	// Line 2528, Address: 0x29a57c, Func Offset: 0xbc
	// Line 2529, Address: 0x29a5a8, Func Offset: 0xe8
	// Line 2531, Address: 0x29a5b0, Func Offset: 0xf0
	// Line 2533, Address: 0x29a5bc, Func Offset: 0xfc
	// Line 2534, Address: 0x29a5c0, Func Offset: 0x100
	// Line 2535, Address: 0x29a5c4, Func Offset: 0x104
	// Line 2536, Address: 0x29a5c8, Func Offset: 0x108
	// Line 2537, Address: 0x29a5cc, Func Offset: 0x10c
	// Line 2538, Address: 0x29a5d0, Func Offset: 0x110
	// Line 2539, Address: 0x29a5d4, Func Offset: 0x114
	// Line 2540, Address: 0x29a5d8, Func Offset: 0x118
	// Line 2541, Address: 0x29a5dc, Func Offset: 0x11c
	// Line 2542, Address: 0x29a5e0, Func Offset: 0x120
	// Line 2543, Address: 0x29a5e4, Func Offset: 0x124
	// Line 2544, Address: 0x29a5e8, Func Offset: 0x128
	// Line 2546, Address: 0x29a5ec, Func Offset: 0x12c
	// Line 2547, Address: 0x29a5f0, Func Offset: 0x130
	// Line 2548, Address: 0x29a5f4, Func Offset: 0x134
	// Line 2549, Address: 0x29a5f8, Func Offset: 0x138
	// Line 2551, Address: 0x29a5fc, Func Offset: 0x13c
	// Line 2552, Address: 0x29a600, Func Offset: 0x140
	// Line 2553, Address: 0x29a604, Func Offset: 0x144
	// Line 2554, Address: 0x29a608, Func Offset: 0x148
	// Line 2555, Address: 0x29a60c, Func Offset: 0x14c
	// Line 2559, Address: 0x29a610, Func Offset: 0x150
	// Line 2560, Address: 0x29a614, Func Offset: 0x154
	// Line 2564, Address: 0x29a620, Func Offset: 0x160
	// Func End, Address: 0x29a650, Func Offset: 0x190
	scePrintf("_fmCnkCalcTang - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x29a650
void _fmCnkCalcNormal(MASK_WORK* fm)
{
	unsigned int vofs;
	//_anon0** nvp;
	//_anon6* list;
	//_anon0 norm;
	//_anon0* dnp1;
	//_anon0* dvp1;
	float* dnp;
	float* dvp;
	int n;
	int i;
	// Line 2683, Address: 0x29a650, Func Offset: 0
	// Line 2693, Address: 0x29a67c, Func Offset: 0x2c
	// Line 2694, Address: 0x29a684, Func Offset: 0x34
	// Line 2695, Address: 0x29a688, Func Offset: 0x38
	// Line 2696, Address: 0x29a68c, Func Offset: 0x3c
	// Line 2698, Address: 0x29a690, Func Offset: 0x40
	// Line 2693, Address: 0x29a694, Func Offset: 0x44
	// Line 2697, Address: 0x29a6a0, Func Offset: 0x50
	// Line 2694, Address: 0x29a6a4, Func Offset: 0x54
	// Line 2693, Address: 0x29a6a8, Func Offset: 0x58
	// Line 2694, Address: 0x29a6ac, Func Offset: 0x5c
	// Line 2699, Address: 0x29a6b0, Func Offset: 0x60
	// Line 2700, Address: 0x29a6b8, Func Offset: 0x68
	// Line 2703, Address: 0x29a6bc, Func Offset: 0x6c
	// Line 2700, Address: 0x29a6c0, Func Offset: 0x70
	// Line 2701, Address: 0x29a6cc, Func Offset: 0x7c
	// Line 2702, Address: 0x29a6d0, Func Offset: 0x80
	// Line 2704, Address: 0x29a6dc, Func Offset: 0x8c
	// Line 2705, Address: 0x29a6e4, Func Offset: 0x94
	// Line 2706, Address: 0x29a6f8, Func Offset: 0xa8
	// Line 2707, Address: 0x29a700, Func Offset: 0xb0
	// Line 2710, Address: 0x29a708, Func Offset: 0xb8
	// Line 2707, Address: 0x29a70c, Func Offset: 0xbc
	// Line 2708, Address: 0x29a714, Func Offset: 0xc4
	// Line 2709, Address: 0x29a724, Func Offset: 0xd4
	// Line 2711, Address: 0x29a734, Func Offset: 0xe4
	// Line 2712, Address: 0x29a74c, Func Offset: 0xfc
	// Line 2713, Address: 0x29a754, Func Offset: 0x104
	// Line 2714, Address: 0x29a758, Func Offset: 0x108
	// Line 2715, Address: 0x29a76c, Func Offset: 0x11c
	// Func End, Address: 0x29a79c, Func Offset: 0x14c
	scePrintf("_fmCnkCalcNormal - UNIMPLEMENTED!\n");
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

// 
// Start address: 0x29a800
void fmCnkSetMode(MASK_WORK* fm, unsigned int mode)
{
	float* dnp;
	float* snp;
	int i;
	// Line 2895, Address: 0x29a800, Func Offset: 0
	// Line 2896, Address: 0x29a81c, Func Offset: 0x1c
	// Line 2897, Address: 0x29a824, Func Offset: 0x24
	// Line 2896, Address: 0x29a828, Func Offset: 0x28
	// Line 2897, Address: 0x29a830, Func Offset: 0x30
	// Line 2896, Address: 0x29a834, Func Offset: 0x34
	// Line 2898, Address: 0x29a838, Func Offset: 0x38
	// Line 2897, Address: 0x29a83c, Func Offset: 0x3c
	// Line 2898, Address: 0x29a840, Func Offset: 0x40
	// Line 2899, Address: 0x29a84c, Func Offset: 0x4c
	// Line 2908, Address: 0x29a850, Func Offset: 0x50
	// Line 2899, Address: 0x29a854, Func Offset: 0x54
	// Line 2904, Address: 0x29a858, Func Offset: 0x58
	// Line 2905, Address: 0x29a85c, Func Offset: 0x5c
	// Line 2908, Address: 0x29a860, Func Offset: 0x60
	// Line 2912, Address: 0x29a868, Func Offset: 0x68
	// Func End, Address: 0x29a870, Func Offset: 0x70
	scePrintf("fmCnkSetMode - UNIMPLEMENTED!\n");
}
