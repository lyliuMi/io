#include "myfun.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

File_handle* fh = NULL;

static int init_file_name()
{
    struct timeval tm;
    gettimeofday(&tm, NULL);
    struct tm* t = localtime(&tm.tv_sec);
    snprintf(fh->name, FILE_NAME_LEN, "%02d_%02d_%02d_%02d_%02d_%02d.txt", 
        t->tm_year+1900, 
        t->tm_mon+1, 
        t->tm_mday,
        t->tm_hour,
        t->tm_min,
        t->tm_sec
        );
    return 0;
}

int init_file_handle()
{
	fh = (File_handle*)malloc(sizeof(File_handle));
	if(!fh)
    {
        fprintf(stderr, "can't alloc memory from heap\n");
        return -1;
    }
    fh->cur_file_length = 0;
    init_file_name();
	fh->fp = fopen(fh->name, "w+");
	if(!fh->fp)
    {
        fprintf(stderr, "can't open file %s", fh->name);
        return -1;
    }

	return 0;
}

int write_file_handle(File_handle* fh, void* buf, unsigned int len)
{
    if(!fh)
        return -1;
    
    if(fh->cur_file_length + len < FILE_LENGTH)
    {
        if(!fwrite(buf, 1, len, fh->fp))
        {
            fprintf(stderr, "write fp fail\n");
            return -1;
        }
        fh->cur_file_length += len;
    }
	else
    {
        destory_file_handle(fh);
        init_file_handle();
        write_file_handle(fh, buf, len);
    }

	return 0;
}	

int destory_file_handle(File_handle* fh)
{
	if(fh->fp) fclose(fh->fp);
	if(fh) free(fh);

    return 0;
}

