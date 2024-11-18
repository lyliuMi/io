#include "myfun.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

File_handle* fh = NULL;

int init_file_handle(const char* name)
{
	fh = (File_handle*)malloc(sizeof(File_handle));
	if(!fh)
    {
        fprintf(stderr, "can't alloc memory from heap\n");
        return -1;
    }
	fh->fp = fopen(name, "w+");
	if(!fh->fp)
    {
        fprintf(stderr, "can't open file %s", name);
        return -1;
    }
	strncpy(fh->name, name, FILE_LEN);	
	return 0;
}

int write_file_handle(File_handle* fh, void* buf, unsigned int len)
{
	if(!fwrite(buf, 1, len, fh->fp))
	{
		fprintf(stderr, "write fp fail\n");
		return -1;
	}

	return 0;
}	

int destory_file_handle(File_handle* fh)
{
	if(fh->fp) fclose(fh->fp);
	if(fh) free(fh);

    return 0;
}

