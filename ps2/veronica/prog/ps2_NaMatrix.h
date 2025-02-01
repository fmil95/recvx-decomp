#include "common.h"

void	njGetMatrix(NJS_MATRIX *m);
void	njInitMatrix(NJS_MATRIX *m, Sint32 n, Int flag);
Bool	njPopMatrix(Uint32 n);
Bool	njPushMatrix(NJS_MATRIX *m); 
void	njSetMatrix(NJS_MATRIX *md, NJS_MATRIX *ms);
