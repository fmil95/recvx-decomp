#ifndef	_MACROS_H_
#define	_MACROS_H_

#define PI 3.141592f
#define PI_2 (PI * 2.0f)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

#define CLAMP(val, min, max) (MAX(MIN((val), (max)), (min)))

#define ALIGN_UP(num, n) ((num + (n - 1)) & ~(n - 1))
#define ALIGN_DOWN(num, n) (num & ~(n - 1))

#define SET_SYS_MN_MODE(m0, m1, m2, m3) *(int*)&sys->mn_mode0 = m0 | (m1 << 8) | (m2 << 16) | (m3 << 24)
#define SET_SYS_MN_MD(m0, m1, m2, m3) *(int*)&sys->mn_md0 = m0 | (m1 << 8) | (m2 << 16) | (m3 << 24)

#define MAKE_MAGIC(A, B, C, D) ((A) | (B) << 8 | (C) << 16 | (D) << 24)

#define ALIGN(x, y) (((((int)x) + (y-1)) / y) * y)
#define GET_DATA_PTR(x) ((void*)(((unsigned int)x) + sizeof(HM)))
#define GET_NEXT_WRK(x) ((int)search_work) + (int)search_work->Use_size + (int)sizeof(HM)

#define	CheckCmdReq(vol, pan, pitch) (0x00|0|((vol)&1)|(((pan)&1)<<1)|(((pitch)&1)<<2))
#define	CheckCmdChg(vol, pan, pitch) (0x00|8|((vol)&1)|(((pan)&1)<<1)|(((pitch)&1)<<2))

#define SPR_ADDR(_val) ((0x70000000) | _val)

#define JOIN_TAGS(_lo, _hi) ((_lo) | ((long)(_hi) << 0x20))

#define SCE_UPF_V4_32  (0x0c) /* 0b1100 */

#define SET_VEC4_AT(_src, _off, _data) (*((u_long128*)(((unsigned char*)(_src)) + _off)) = *(u_long128*)_data)
#define SET_DATA_AT(_src, _off, _type, _data) (*((_type*)(((unsigned char*)(_src)) + _off)) = _data)

#define EXP0_UC(o) (*(unsigned char  *)((char *)epw->exp0 + (o)))
#define EXP0_S(o) (*(short *)((char *)epw->exp0 + (o)))
#define EXP0_I(o) (*(int   *)((char *)epw->exp0 + (o)))
#define EXP0_F(o) (*(float *)((char *)epw->exp0 + (o)))

#define EXP1_C(o) (*(char  *)((char *)plp->exp1 + (o)))
#define EXP1_S(o) (*(short *)((char *)plp->exp1 + (o)))
#define EXP1_I(o) (*(int   *)((char *)plp->exp1 + (o)))
#define EXP1_F(o) (*(float *)((char *)plp->exp1 + (o)))

#define EP_EXP0_I(o) (*(int   *)((char *)ep->exp0 + (o)))

#define PEXP0_UC(o) (*(unsigned char  *)((char *)plp->exp0 + (o)))
#define PEXP0_S(o) (*(short *)((char *)plp->exp0 + (o)))
#define PEXP0_I(o) (*(int   *)((char *)plp->exp0 + (o)))
#define PEXP0_F(o) (*(float *)((char *)plp->exp0 + (o)))

#define PREFETCH(_v) asm("pref 0x0,0(%0)": : "r"(_v) : "memory")

#define SCE_GIF_PRIM(prim, iip, tme, fge, abe, aa1, fst, ctxt, fix) SCE_GIF_SET_TAG(0, 0, 0, SCE_GS_SET_PRIM(prim, iip, tme, fge, abe, aa1, fst, ctxt, fix), 0, 0)

#define RAND_MAX 0x7fffffff

#ifndef RAND_MAX
#define RAND_MAX  32767
#endif

/*
 *  ANGLE MACRO
 */
#define NJM_RAD_ANG(n)  ((Angle)((n) * (65536.0f / PI_2)))
#define NJM_ANG_DEG(n)  ((n) * 360.0f / 65536.0f)
#define NJM_DEG_ANG(n)  ((Angle)(((n) * 65536.0f) / 360.0f))
#define njRandom()       ((Float)((Float)-rand()/(Float)(RAND_MAX+1)))
#define bhRandomAngle(deg)      njRandom() * ((Float)(NJM_DEG_ANG(deg)) * 2) - NJM_DEG_ANG(deg)

#define njArcSin(n)      ((Angle)NJM_RAD_ANG(asinf  ((Float)(n)) ))
#define njArcTan2(y,x)   ((Angle)NJM_RAD_ANG(atan2f ((Float)(y),(Float)(x)) ))

#endif
