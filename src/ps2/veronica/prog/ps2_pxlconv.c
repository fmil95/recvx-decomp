#include "ps2_pxlconv.h"
#include "main.h"

#include <string.h>

unsigned char* Ps2_PXLCONV __attribute__((aligned(64)));

// 100% matching! 
void Tim2_Format_Check(void* tim2_ptr)
{
    TIM2_PICTUREHEADER* ph;
    unsigned char* pImage;  
    unsigned char* output;  
	
    output = Ps2_PXLCONV;
    
    if (((TIM2_PICTUREHEADER_EX*)tim2_ptr)->FormatId != 0) 
    {
        ph = (TIM2_PICTUREHEADER*)&((unsigned char*)tim2_ptr)[128];
    } 
    else 
    {
        ph = (TIM2_PICTUREHEADER*)&((unsigned char*)tim2_ptr)[16]; 
    }
    
    if (((TIM2_PICTUREHEADER_EX*)tim2_ptr)->FormatId == 0) 
    {
        pImage = (unsigned char*)ph + ph->HeaderSize;
    }
    else if ((((TIM2_PICTUREHEADER_EX*)tim2_ptr)->FormatId & 0xFF) == 1) 
    {
        pImage = &((unsigned char*)ph)[128];
    } 
    else 
    {
        printf("FormatId of this TIM2 FILE is not Supported\n");
        
        exit(0);
    }
    
    if (ph->ImageType == TIM2_IDTEX4)
    {
        Conv4to32(ph->ImageWidth, ph->ImageHeight, pImage, output);
    } 
    else if (ph->ImageType == TIM2_IDTEX8) 
    {
        Conv8to32(ph->ImageWidth, ph->ImageHeight, pImage, output);
    } 
    else 
    {
        printf("This file is illegal Image Type\n");
        
        exit(0);
    }
    
    memcpy(pImage, output, ph->ImageSize);
}

// 99.70% matching
int BlockConv4to32(u_char *p_input, u_char *p_output) 
{
    static int lut[256] = 
    {
        0, 68, 8,  76, 16, 84, 24, 92,
        1, 69, 9,  77, 17, 85, 25, 93,
        2, 70, 10, 78, 18, 86, 26, 94,
        3, 71, 11, 79, 19, 87, 27, 95,
        4, 64, 12, 72, 20, 80, 28, 88,
        5, 65, 13, 73, 21, 81, 29, 89,
        6, 66, 14, 74, 22, 82, 30, 90,
        7, 67, 15, 75, 23, 83, 31, 91,

        32, 100, 40, 108, 48, 116, 56, 124,
        33, 101, 41, 109, 49, 117, 57, 125,
        34, 102, 42, 110, 50, 118, 58, 126,
        35, 103, 43, 111, 51, 119, 59, 127,
        36, 96,  44, 104, 52, 112, 60, 120,
        37, 97,  45, 105, 53, 113, 61, 121,
        38, 98,  46, 106, 54, 114, 62, 122,
        39, 99,  47, 107, 55, 115, 63, 123,
    
        4, 64, 12, 72, 20, 80, 28, 88,
        5, 65, 13, 73, 21, 81, 29, 89,
        6, 66, 14, 74, 22, 82, 30, 90,
        7, 67, 15, 75, 23, 83, 31, 91,
        0, 68, 8,  76, 16, 84, 24, 92,
        1, 69, 9,  77, 17, 85, 25, 93,
        2, 70, 10, 78, 18, 86, 26, 94,
        3, 71, 11, 79, 19, 87, 27, 95,
        
        36, 96,  44, 104, 52, 112, 60, 120,
        37, 97,  45, 105, 53, 113, 61, 121,
        38, 98,  46, 106, 54, 114, 62, 122,
        39, 99,  47, 107, 55, 115, 63, 123,
        32, 100, 40, 108, 48, 116, 56, 124,
        33, 101, 41, 109, 49, 117, 57, 125,
        34, 102, 42, 110, 50, 118, 58, 126,
        35, 103, 43, 111, 51, 119, 59, 127
    };
    unsigned int i, j, k, i0, i1, i2;
    unsigned int index0, index1;
    unsigned char c_in, c_out;
    unsigned char *pIn;

    pIn = p_input;

    index1 = 0;

    for (k = 0; k < 4; k++) 
    {
        index0 = (k % 2) * 128;

        for (i = 0; i < 16; i++) 
        {
            for (j = 0; j < 4; j++)
            {
                c_out = 0;

                i0 = lut[index0++];
                i2 = (i0 & 0x1) * 4;
                
                c_in = (pIn[i0 / 2] & (15 << i2)) >> i2; 
                c_out = c_out | c_in;
                
                i0 = lut[index0++];
                i1 = i0 / 2;
                i2 = (i0 & 0x1) * 4;
                
                c_in = (pIn[i0 / 2] & (15 << i2)) >> i2;
                c_out = c_out | ((c_in << 4) & 0xF0);

                p_output[index1++] = c_out;
            }
        }
        
        pIn += 64;
    }

    return 0;
}

// 99.71% matching
int BlockConv8to32(u_char *p_input, u_char *p_output)
{
    static int lut[128] = 
    {
        0, 36, 8,  44,
        1, 37, 9,  45,
        2, 38, 10, 46,
        3, 39, 11, 47,
        4, 32, 12, 40,
        5, 33, 13, 41,
        6, 34, 14, 42,
        7, 35, 15, 43,

        16, 52, 24, 60,
        17, 53, 25, 61,
        18, 54, 26, 62,
        19, 55, 27, 63, 
        20, 48, 28, 56,
        21, 49, 29, 57,
        22, 50, 30, 58,
        23, 51, 31, 59,

        4, 32, 12, 40,
        5, 33, 13, 41,
        6, 34, 14, 42,
        7, 35, 15, 43,
        0, 36, 8,  44,
        1, 37, 9,  45,
        2, 38, 10, 46,
        3, 39, 11, 47,

        20, 48, 28, 56,
        21, 49, 29, 57,
        22, 50, 30, 58,
        23, 51, 31, 59,
        16, 52, 24, 60,
        17, 53, 25, 61,
        18, 54, 26, 62,
        19, 55, 27, 63
    };
    unsigned int i, j, k, i0;
    unsigned int index0, index1;
    unsigned char *pIn;

    pIn = p_input;

    index1 = 0;

    for (k = 0; k < 4; k++) 
    {
        index0 = (k % 2) * 64;

        for (i = 0; i < 16; i++) 
        {
            for (j = 0; j < 4; j++)
            {
                i0 = lut[index0++];
                
                p_output[index1++] = pIn[i0];
            }
        }
        
        pIn += 64;
    }

    return 0;
}

// 99.86% matching
int PageConv4to32(int width, int height, u_char *p_input, u_char *p_output)
{
    static unsigned int block_table4[32] = 
    {
         0,  2,  8, 10,
         1,  3,  9, 11,
         4,  6, 12, 14,
         5,  7, 13, 15,
        16, 18, 24, 26,
        17, 19, 25, 27,
        20, 22, 28, 30,
        21, 23, 29, 31
    }; // TODO: find out where the data location for these values is, can't find it in game.data.s
    static unsigned int block_table32[32] = 
    {
         0,  1,  4,  5, 16, 17, 20, 21,
         2,  3,  6,  7, 18, 19, 22, 23,
         8,  9, 12, 13, 24, 25, 28, 29,
        10, 11, 14, 15, 26, 27, 30, 31
    };
    unsigned int index32_h[128];
    unsigned int index32_v[128];
    unsigned int in_block_nb;
    unsigned char input_block[16 * 16] = { 0 };
    unsigned char output_block[16 * 16] = { 0 };
    unsigned char *pi0, *pi1, *po0, *po1;
    int index0, index1;
    int i, j, k; 
    int n_width, n_height;
    int input_page_line_size, output_page_line_size;

    index0 = 0;
    
    for (i = 0; i < 4; i++) 
    {
        for (j = 0; j < 8; j++) 
        {
            index1 = block_table32[index0];
            
            index32_h[index1] = j;
            index32_v[index1] = i;
            
            index0++;
        }
    }

    n_width = width / 32;
    n_height = height / 16;

    input_page_line_size = 16;   
    output_page_line_size = 256;      

    for (i = 0; i < n_height; i++) 
    {
        for (j = 0; j < n_width; j++) 
        {
            pi0 = input_block;
            pi1 = (p_input + ((64 * i) * input_page_line_size)) + (j * 16);

            in_block_nb = block_table4[(i * n_width) + j]; 

            for (k = 0; k < PSMT4_BLOCK_HEIGHT; k++) 
            {
                memcpy(pi0, pi1, PSMT4_BLOCK_WIDTH / 2);
                
                pi0 += PSMT4_BLOCK_WIDTH / 2;
                pi1 += input_page_line_size * 4;
            }
            
            BlockConv4to32(input_block, output_block);

            po0 = output_block;
            po1 = (p_output + ((8 * index32_v[in_block_nb]) * output_page_line_size)) + (index32_h[in_block_nb] * 32);
            
            for (k = 0; k < PSMCT32_BLOCK_HEIGHT; k++) 
            {
                memcpy(po1, po0, PSMCT32_BLOCK_WIDTH * 4);
                
                po0 += PSMCT32_BLOCK_WIDTH * 4;
                po1 += output_page_line_size;   
            }
        }
    }

    return 0;
}

// 99.84% matching
int PageConv8to32(int width, int height, u_char *p_input, u_char *p_output)
{
    static unsigned int block_table8[32] = 
    {
         0,  1,  4,  5, 16, 17, 20, 21,
         2,  3,  6,  7, 18, 19, 22, 23,
         8,  9, 12, 13, 24, 25, 28, 29,
        10, 11, 14, 15, 26, 27, 30, 31
    }; 
    static unsigned int block_table32[32] = 
    {
         0,  1,  4,  5, 16, 17, 20, 21,
         2,  3,  6,  7, 18, 19, 22, 23,
         8,  9, 12, 13, 24, 25, 28, 29,
        10, 11, 14, 15, 26, 27, 30, 31
    };
    unsigned int index32_h[128];
    unsigned int index32_v[128];
    unsigned int in_block_nb;
    unsigned char input_block[16 * 16];
    unsigned char output_block[16 * 16];
    unsigned char *pi0, *pi1, *po0, *po1;
    int index0, index1;
    int i, j, k; 
    int n_width, n_height;
    int input_page_line_size, output_page_line_size;

    index0 = 0;
    
    for (i = 0; i < 4; i++) 
    {
        for (j = 0; j < 8; j++) 
        {
            index1 = block_table32[index0];
            
            index32_h[index1] = j;
            index32_v[index1] = i;
            
            index0++;
        }
    }

    n_width = width / PSMT8_BLOCK_WIDTH;
    n_height = height / PSMT8_BLOCK_HEIGHT;

    input_page_line_size = 128;   
    output_page_line_size = 256;      

    for (i = 0; i < n_height; i++) 
    {
        for (j = 0; j < n_width; j++) 
        {
            pi0 = input_block;
            pi1 = (p_input + ((PSMT8_BLOCK_HEIGHT * i) * input_page_line_size)) + (j * PSMT8_BLOCK_WIDTH);

            in_block_nb = block_table8[(i * n_width) + j]; 

            for (k = 0; k < PSMT8_BLOCK_HEIGHT; k++) 
            {
                memcpy(pi0, pi1, PSMT8_BLOCK_WIDTH);
                
                pi0 += PSMT8_BLOCK_WIDTH;
                pi1 += input_page_line_size;
            }
            
            BlockConv8to32(input_block, output_block);

            po0 = output_block;
            po1 = (p_output + ((8 * index32_v[in_block_nb]) * output_page_line_size)) + (index32_h[in_block_nb] * 32);
            
            for (k = 0; k < PSMCT32_BLOCK_HEIGHT; k++) 
            {
                memcpy(po1, po0, PSMCT32_BLOCK_WIDTH * 4);
                
                po0 += PSMCT32_BLOCK_WIDTH * 4;
                po1 += output_page_line_size;   
            }
        }
    }

    return 0;
}

// 100% matching! 
int Conv4to32(int width, int height, u_char *p_input, u_char *p_output)
{
    int i, j, k;
    int n_page_h, n_page_w, n_page4_width_byte, n_page32_width_byte;
    unsigned char *pi0, *pi1, *po0, *po1;
    int n_input_width_byte, n_output_width_byte, n_input_height, n_output_height;
    unsigned char input_page[(PSMT4_PAGE_WIDTH / 2) * PSMT4_PAGE_HEIGHT] = { 0 };
    unsigned char output_page[(PSMCT32_PAGE_WIDTH * 4) * PSMCT32_PAGE_HEIGHT] = { 0 }; 

    for (i = 0; i < 14; i++) 
    {
        if (width == (8192 >> i)) 
        {
            break;
        }
    }
    
    if (i == 14)
    {
        return -1;
    }

    for (i = 0; i < 14; i++) 
    {
        if (width == (8192 >> i))
        {
            break;
        }
    }

    for (i = 0; i < 14; i++) 
    {
        if (height == (8192 >> i)) 
        {
            break;
        }
    }
    
    if (i == 14)
    {
        return -1;
    }

    n_page_w = ((width - 1) / PSMT4_PAGE_WIDTH) + 1;
    n_page_h = ((height - 1) / PSMT4_PAGE_HEIGHT) + 1;

    n_page4_width_byte = PSMT4_PAGE_WIDTH / 2;
    n_page32_width_byte = PSMCT32_PAGE_WIDTH * 4;

    if (n_page_w == 1) 
    {
        n_input_width_byte = width / 2;
        n_output_height = width / 4;
    } 
    else 
    {
        n_input_width_byte = n_page4_width_byte;
        n_output_height = PSMCT32_PAGE_HEIGHT;
    }

    if (n_page_h == 1) 
    {
        n_input_height = height;
        n_output_width_byte = height * 2;
    } 
    else 
    {
        n_input_height = PSMT4_PAGE_HEIGHT;
        n_output_width_byte = n_page32_width_byte;
    }

    for (i = 0; i < n_page_h; i++) 
    {
        for (j = 0; j < n_page_w; j++)
        {
            pi0 = (p_input + (((n_input_width_byte * PSMT4_PAGE_HEIGHT) * n_page_w) * i)) + (n_input_width_byte * j);
            pi1 = input_page;

            for (k = 0; k < n_input_height; k++) 
            {
                memcpy(pi1, pi0, n_input_width_byte);
                
                pi0 += n_input_width_byte * n_page_w;
                pi1 += n_page4_width_byte;
            }

            PageConv4to32(PSMT4_PAGE_WIDTH, PSMT4_PAGE_HEIGHT, input_page, output_page);

            po0 = (p_output + (((n_output_width_byte * PSMCT32_PAGE_HEIGHT) * n_page_w) * i)) + (n_output_width_byte * j);
            po1 = output_page;
            
            for (k = 0; k < n_output_height; k++) 
            {
                memcpy(po0, po1, n_output_width_byte);
                
                po0 += n_output_width_byte * n_page_w;
                po1 += n_page32_width_byte;
            }          
        }
    }

    return 0;
}

// 100% matching! 
int Conv8to32(int width, int height, u_char *p_input, u_char *p_output)
{
    int i, j, k;
    int n_page_h, n_page_w, n_page8_width_byte, n_page32_width_byte;
    int n_input_width_byte, n_output_width_byte, n_input_height, n_output_height;
    unsigned char *pi0, *pi1, *po0, *po1;
    unsigned char input_page[PSMT8_PAGE_WIDTH * PSMT8_PAGE_HEIGHT] = { 0 };
    unsigned char output_page[(PSMCT32_PAGE_WIDTH * 4) * PSMCT32_PAGE_HEIGHT] = { 0 }; 

    for (i = 0; i < 13; i++) 
    {
        if (width == (4096 >> i)) 
        {
            break;
        }
    }
    
    if (i == 13)
    {
        return -1;
    }

    for (i = 0; i < 13; i++) 
    {
        if (height == (4096 >> i))
        {
            break;
        }
    }
    
    if (i == 13)
    {
        return -1;
    }

    n_page_w = ((width - 1) / PSMT8_PAGE_WIDTH) + 1;
    n_page_h = ((height - 1) / PSMT8_PAGE_HEIGHT) + 1;

    n_page8_width_byte = PSMT8_PAGE_WIDTH;
    n_page32_width_byte = PSMCT32_PAGE_WIDTH * 4;

    if (n_page_w == 1) 
    {
        n_input_width_byte = width;
        n_output_width_byte = width * 2;
    } 
    else 
    {
        n_input_width_byte = n_page8_width_byte;
        n_output_width_byte = n_page32_width_byte;
    }

    if (n_page_h == 1) 
    {
        n_input_height = height;
        n_output_height = height / 2;
    } 
    else 
    {
        n_input_height = PSMT8_PAGE_HEIGHT;
        n_output_height = PSMCT32_PAGE_HEIGHT;
    }

    for (i = 0; i < n_page_h; i++) 
    {
        for (j = 0; j < n_page_w; j++)
        {
            pi0 = (p_input + (((n_input_width_byte * PSMT8_PAGE_HEIGHT) * n_page_w) * i)) + (n_input_width_byte * j);
            pi1 = input_page;

            for (k = 0; k < n_input_height; k++) 
            {
                memcpy(pi1, pi0, n_input_width_byte);
                
                pi0 += n_input_width_byte * n_page_w;
                pi1 += n_page8_width_byte;
            }

            PageConv8to32(PSMT8_PAGE_WIDTH, PSMT8_PAGE_HEIGHT, input_page, output_page);

            po0 = (p_output + (((n_output_width_byte * n_output_height) * n_page_w) * i)) + (n_output_width_byte * j);
            po1 = output_page;
            
            for (k = 0; k < n_output_height; k++) 
            {
                memcpy(po0, po1, n_output_width_byte);
                
                po0 += n_output_width_byte * n_page_w;
                po1 += n_page32_width_byte;
            }          
        }
    }

    return 0;
}
