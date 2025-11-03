#ifndef _PS2_NADEBUGFONTFUNCTION_H_
#define _PS2_NADEBUGFONTFUNCTION_H_

#include "types.h"

void 	njInitPrint(Uint32 *texture,Uint32 size,Uint32 attr);
void 	njExitPrint(void);
void	njPrintSize(Uint16 size);
void	njPrintColor(Uint32 c);
void	njPrintC(Int loc,const char *s);

#endif
