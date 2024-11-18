#ifndef __MYFUNC__H
#define __MYFUNC__H

#include <stdio.h>
#define FILE_LEN 100

//static File_handle* fh = NULL;

#define FILE_NAME "test.txt"

typedef struct File_handle
{
	char name[FILE_LEN];
	FILE* fp;
	// ...
}File_handle;

int init_file_handle(const char* name);

int write_file_handle(File_handle* fh, void* buf, unsigned int len);



int destory_file_handle(File_handle* fh);

#endif
