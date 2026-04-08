#ifndef _PS2_DVD_IMAGE_H_
#define _PS2_DVD_IMAGE_H_

// the second field of the struct below was originally char* but got turned into char** because it matches gdFsInit() higher
typedef struct DVD_IMAGE_DATA
{
	// total size: 0x8
    char* file_name;  // offset 0x0, size 0x4
    char** link_file; // offset 0x4, size 0x4
} DVD_IMAGE_DATA;

extern char* rdx_files[205];
extern DVD_IMAGE_DATA dvd_image_data[19];
extern int dvd_image_data_max;
extern int rdx_image_data_max;

#endif
