#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <exception>

#define SOCK_PORT 8888
#define BUFFER_LENGTH 1024
#define MAX_CONN_LIMIT 512

void * dataHandle(void* sock_fd)
{
    int handle_fd = *((int *)sock_fd);

    char recv_line[BUFFER_LENGTH];
    char send_line[BUFFER_LENGTH];

    while (1)
    {
        printf("%d waiting for request...\n", handle_fd);

        // memset(recv_line, 0, sizeof(recv_line));

        if (recv(handle_fd, recv_line, sizeof(recv_line), 0) < 0)
        {
            printf ("%d recive faile!\n", handle_fd);
        }
        else
        {
            printf("recive: %s", recv_line);
        }

        printf ("server send: ");

        // fgets(send_line, BUFFER_LENGTH, stdin);
        scanf("%s", send_line);

        if (send(handle_fd, send_line, strlen(send_line), 0) < 0)
        {
            printf ("send faile!\n");
        }
    }
}

int main(int argc, char const *argv[])
{
    int sockfd_server = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_server < 0)
    {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr_server;
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(SOCK_PORT);
    // addr_server.sin_addr.s_addr = inet_addr(ip);
    addr_server.sin_addr.s_addr =  htonl(INADDR_ANY);     // 使用自己的地址
    /*inet_addr函数将用点分十进制字符串表示的
	  IPv4地址转化为用网络字节序整数表示的IPv4地址 */

    int bind_fd = bind(sockfd_server, (struct sockaddr *)&addr_server, sizeof(addr_server));
    if (bind_fd < 0)
    {
        perror("bind");
        return 2;
    }

    int listen_fd = listen(sockfd_server, 5);
    if (listen_fd < 0)
    {
        perror("listen");
        return 3;
    }

    while (1)
    {
        printf("waiting for new connection...\n");
        pthread_t thread_id;

        struct sockaddr_in addr_client;
        socklen_t addr_len;

        int accept_fd = accept(sockfd_server, (struct sockaddr*)&addr_client, &addr_len);
        if (accept_fd < 0)
        {
            printf("accept faile, accept_fd: %d", accept_fd);   
            continue;
        }

        char buf[1024];
        printf("connect from %s, port %d \n", inet_ntop(AF_INET,&addr_client.sin_addr, buf, 1024), ntohs(addr_client.sin_port));

        int thread_create = pthread_create(&thread_id, NULL, dataHandle, (void *)&accept_fd);
        if (thread_create < 0)
        {
            printf("pthread_create error!\n");
            continue;
        }

    }

    close(sockfd_server);

    printf("Server shut down\n");
    return 0;
}
