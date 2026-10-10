#ifndef _MWCC_HACKS_H_
#define _MWCC_HACKS_H_

/* When a source file has a function with a double op or literal, MWCC will stop using the $a0 and $a1 registers as temporary ones and use $a2/$a3 
   instead of them. Since the linker removes unreferenced functions which might have contained the doubles on a compile unit, next is a hack that 
   forcefully triggers that condition. */

#define STRIPPED_DOUBLE_CODE() \
    static double __stripped_double_code(double x) { return (x * 2.5) + 1.0; }

#endif
