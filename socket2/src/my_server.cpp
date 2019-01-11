#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 4096
#define SERVER_ADDR "192.168.1.111"

using namespace std;

char buff[4096];

bool server(int listen_fd, int conn_fd)
{
    cout<<"hh: "<<listen_fd<<endl;
    if( (conn_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL)) == -1)
    {
        printf("accept socket error: %s(errno: %d)",strerror(errno),errno);

        return false;
    }

    printf("Hello\n");
    int n = recv(conn_fd, buff, MAXLINE, 0);
    buff[n] = '\0';
    printf("recv msg from client: %s\n", buff);

    return true;
}

int main(int argc, char const *argv[])
{
    int listen_fd, conn_fd;
    struct sockaddr_in servaddr;

    bool serving = true;

    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
        return 0;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(6666);

    if( bind(listen_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
        return 0;
    }

    if( listen(listen_fd, 10) == -1){
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
        return 0;
    }

    printf("======waiting for client's request======\n");

    while (serving)
    {
        server(listen_fd, conn_fd);
    }

    close(listen_fd);
    return 0;
}
