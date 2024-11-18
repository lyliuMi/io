#include "common/myfun.h"
#include <stdlib.h>
#include <string.h>

extern File_handle* fh;

void test01()
{
    init_file_handle(FILE_NAME);

    char buf[FILE_LEN] = "hello, world\n";

    write_file_handle(fh, buf, strlen(buf));

    destory_file_handle(fh);
}

int main(void)
{
    test01();
    return 0;
}