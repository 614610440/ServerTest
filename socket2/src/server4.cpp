#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

const int port = 8888;
const char* ip = "192.168.1.111"; //服务器端IP

int main()
{
    int ser_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (ser_sock < 0)
    {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr; //绑定信息，即命名socket
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip); 
    // addr.sin_addr.s_addr =  htonl(INADDR_ANY);     // 使用自己的地址
    /*inet_addr函数将用点分十进制字符串表示的
	  IPv4地址转化为用网络字节序整数表示的IPv4地址 */

    int bind_fd = bind(ser_sock, (struct sockaddr*)&addr, sizeof(addr));
    if (bind_fd < 0)
    {
        perror("bind");
        return 2;
    }

    int listen_sock = listen(ser_sock, 5);
    if (listen_sock < 0)
    {
        perror("listen");
        return 3;
    }

    struct sockaddr_in peer;
    socklen_t peer_len;
    int accept_fd = accept(ser_sock, (struct sockaddr*)&peer, &peer_len);
    if (accept_fd < 0)
    {
        perror("accept");
        return 4;
    }
    else
    {
        char buf[1024];
        printf("connect from %s, port %d \n", inet_ntop(AF_INET,&peer.sin_addr, buf, 1024), ntohs(peer.sin_port));
    }

    char sendline[1024], recvline[1024];
    while (1)
    {
        // memset(recvline, '\0', sizeof(recvline));
        printf ("server waiting...\n");

        // if (accept(ser_sock, (struct sockaddr*)NULL, NULL) < 0)
        // {
        //     printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
        //     continue;   
        // }

        if (recv(accept_fd, recvline, sizeof(recvline), 0) < 0)
        {
            printf ("recv faile!\n");
        }
        printf ("recive: %s\n", recvline);

        // printf ("server: ");

        // fgets(sendline, 1024, stdin);

        // if (send(ser_sock, sendline, sizeof(sendline), 0) < 0)
        // {
        //     printf ("send faile!\n");
        // }
    }

    close(ser_sock);
    return 0;
}