#ifndef __MYFUNC__H
#define __MYFUNC__H

#include <stdio.h>

#define FILE_NAME_LEN 100
#define FILE_NAME "test.txt"
#define FILE_LENGTH 1024

typedef struct File_handle
{
    size_t cur_file_length;
	char name[FILE_NAME_LEN];
	FILE* fp;
	// ...
}File_handle;

int init_file_handle();

int write_file_handle(File_handle* fh, void* buf, unsigned int len);

int destory_file_handle(File_handle* fh);

#endif
