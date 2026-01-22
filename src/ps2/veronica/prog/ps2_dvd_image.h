#ifndef _PS2_DVD_IMAGE_H_
#define _PS2_DVD_IMAGE_H_

// the link_file field in the struct below was originally char* but got turned into char** because it matches gdFsInit() higher
typedef struct DVD_IMAGE_DATA
{
	// total size: 0x8
    char* file_name;  // offset 0x0, size 0x4
    char** link_file; // offset 0x4, size 0x4
} DVD_IMAGE_DATA;

extern char* rdx_files[205];
extern int rdx_image_data_max;

/*typedef struct _anon0;


typedef char* type_0[205];
typedef _anon0 type_1[19];
typedef char* type_2[18];

struct _anon0
{
	char* file_name;
	char* link_file;
};*/

#endif
