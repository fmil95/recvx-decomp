#ifndef _PS2_PXLCONV_H_
#define _PS2_PXLCONV_H_

#include "types.h"

#define PSMT4_BLOCK_WIDTH 32
#define PSMT4_BLOCK_HEIGHT 16

#define PSMT8_BLOCK_WIDTH  16
#define PSMT8_BLOCK_HEIGHT 16

#define PSMCT32_BLOCK_WIDTH 8
#define PSMCT32_BLOCK_HEIGHT 8

#define PSMT4_PAGE_WIDTH    128
#define PSMT4_PAGE_HEIGHT   128

#define PSMT8_PAGE_WIDTH    128
#define PSMT8_PAGE_HEIGHT   64

#define PSMCT32_PAGE_WIDTH  64
#define PSMCT32_PAGE_HEIGHT 32

void Tim2_Format_Check(void* tim2_ptr);
int BlockConv4to32(u_char *p_input, u_char *p_output);
int BlockConv8to32(u_char *p_input, u_char *p_output);
int PageConv4to32(int width, int height, u_char *p_input, u_char *p_output);
int PageConv8to32(int width, int height, u_char *p_input, u_char *p_output);
int Conv4to32(int width, int height, u_char *p_input, u_char *p_output);
int Conv8to32(int width, int height, u_char *p_input, u_char *p_output);

extern unsigned char* Ps2_PXLCONV;

#endif
