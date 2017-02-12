#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>

void server_exit(void){
    printf("server退出\n");
    exit(-1);
}

int main(void){
    int fd = socket(AF_INET , SOCK_STREAM , 0); //创建套接字
    if( -1 == fd ){
        printf("get fd error\n");
        server_exit();
    }
    else{
        printf("fd is %d\n", fd);
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    //server_addr.sin_addr.s_addr = htonl(0);
    inet_aton("127.0.0.1", &server_addr.sin_addr );
    server_addr.sin_port = htons(9000);

    int bind_result = bind(fd, (struct sockaddr * ) &server_addr, sizeof(server_addr));
    if(0 == bind_result){
        printf("绑定[%s]:%d 成功\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
    }
    else{
        printf("绑定[%s]:%d 失败\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
        printf("错误码%d\n", bind_result);
        server_exit();
    }

    listen(fd, 10);

    struct sockaddr_in client_addr;
    bzero(&client_addr, sizeof(client_addr));
    socklen_t len = sizeof(client_addr);

    for(;;){
        int conn_fd = accept(fd, (struct sockaddr *) &client_addr, &len);
        if(0 == fork()){
            /*child process*/
            printf("client[%s]:%d connect success!!\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            close(conn_fd);
        }
        else{
            /*father process*/
            close(conn_fd);
        }
    }
    close(fd);
    return 0;
}


