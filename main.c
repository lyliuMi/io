#include "common/myfun.h"
#include <stdlib.h>
#include <string.h>

extern File_handle* fh;

void test01()
{
    init_file_handle();

    char buf[1024] = "hello, world\n";

    while(1)
    {
        write_file_handle(fh, buf, strlen(buf));
    }

    destory_file_handle(fh);
}

int main(void)
{
    test01();
    return 0;
}