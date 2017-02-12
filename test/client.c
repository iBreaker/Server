#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <errno.h>

extern int errno;
int main(int argc, char * argv[]){
    if(argc != 3){
        printf("simple client usage -h\t help\n./clinet IP port\n");
        return -1;
    }

    char * ip_addr = argv[1];
    int port = atoi(argv[2]);
    struct sockaddr_in conn_addr;
    int conn_fd;

    conn_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == conn_fd) {
        printf("无法获取文件描述符\n");
        return -1;
    }
    printf("获取文件描述符成功:%d\n", conn_fd);

    bzero(&conn_addr, sizeof(conn_addr));
    conn_addr.sin_family = AF_INET;
    inet_aton(ip_addr, &conn_addr.sin_addr);
    conn_addr.sin_port = htons(port);

    printf("连接[%s:%d]\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));
    int result = connect(conn_fd, (struct sockaddr *)&conn_addr, sizeof(conn_addr));
    if(0 != result){
        printf("连接失败,错误:%s\n", strerror(errno));
        return -1;
    }
    return 0;
}

