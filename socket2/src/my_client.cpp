#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <iostream>

#define MAXLINE 4096
#define SERVER_ADDR "127.0.0.1"

using namespace std;

void sendMsg(int sock_fd, char sendline[])
{
    if( send(sock_fd, sendline, strlen(sendline), 0) < 0)
    {
        printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
    }
    else
    {
        cout<<"send: "<<sock_fd<<endl;
    }
}

int main(int argc, char const *argv[])
{
    int sock_fd;

    char  recvline[4096];
    struct sockaddr_in  servaddr;
    char msg[100];

    if( (sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
        return 0;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    if( inet_pton(AF_INET, SERVER_ADDR, &servaddr.sin_addr) <= 0)
    {
        printf("inet_pton error for %s\n",SERVER_ADDR);
        return 0;
    }

    if( connect(sock_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
        return 0;
    }

    printf("send msg to server: \n");

    while (true)
    {
        char sendline[4096];
        fgets(sendline, 4096, stdin);
        sendMsg(sock_fd, sendline);
        memset(sendline, 0, sizeof(sendline));
    }
    close(sock_fd);
    return 0;
}

