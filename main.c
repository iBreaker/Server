#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(void)
{
    int fd = socket(AF_INET , SOCK_STREAM , 0);
    if( -1 == fd )
    {
        printf("get fd error\n");

    }
    else
    {
        printf("fd is %d\n", fd);
    }

    close(fd);
    return 0;
}
