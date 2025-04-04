#define ALIGN_UP(num, n) ((num + (n - 1)) & ~(n - 1))
#define ALIGN_DOWN(num, n) (num & ~(n - 1))

#define SET_SYS_MN_MODE(m0, m1, m2, m3) *(int*)&sys->mn_mode0 = m0 | (m1 << 8) | (m2 << 16) | (m3 << 24)
#define SET_SYS_MN_MD(m0, m1, m2, m3) *(int*)&sys->mn_md0 = m0 | (m1 << 8) | (m2 << 16) | (m3 << 24)

#define MAKE_MAGIC(A, B, C, D) ((A) | (B) << 8 | (C) << 16 | (D) << 24)