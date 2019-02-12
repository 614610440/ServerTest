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

#define SOCK_PORT 8080
#define MAX_SIZE 1024
#define IP_FOUND "IP_FOUND"
#define IP_FOUND_ACK "IP_FOUND_ACK"

int main()
{
    char buffer[MAX_SIZE];
    // 设置超时时间
    struct timeval timeout;
	timeout.tv_sec = 2;
	timeout.tv_usec = 0;

    //建立数据报套接字
    int server_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_sock < 0)
    {
        perror("socket");
        return 1;
    }

    // 设置服务器地址
    struct sockaddr_in server_addr;
    memset((void*) &server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SOCK_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // 绑定
    int bind_fd = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (bind_fd < 0)
    {
        perror("bind");
        return 2;
    }

    /**
	 * 循环等待客户端
	*/
    while (1)
    {
        fd_set read_fd; //读文件描述符集合
        timeout.tv_sec = 100;
		timeout.tv_usec = 0;

        //文件描述符集合清0
		FD_ZERO(&read_fd);
 
		//将套接字描述符加入到文件描述符集合
		FD_SET(server_sock, &read_fd);

        //select侦听是否有数据到来
        int ret = select(server_sock + 1, &read_fd, NULL, NULL, &timeout);

        switch (ret)
        {
            case -1:
                perror("select error:");
                break;
            
            case 0: //超时
                printf("select timeout\n");
                break;
        
            default:
                if (FD_ISSET(server_sock, &read_fd))
                {
                    struct sockaddr_in from_addr; //客户端地址
                    int count = recvfrom(server_sock, buffer, MAX_SIZE, 0, (struct sockaddr*)&from_addr, 0);

                    //from_addr保存客户端的地址结构

                    if (strstr(buffer, IP_FOUND))
                    {
                        //响应客户端请求
                        //打印客户端的IP地址和端口号
                        printf("\nClient connection information:\n\t IP: %s, Port: %d\n",
                                (char *)inet_ntoa(from_addr.sin_addr),
                                ntohs(from_addr.sin_port));
    
                        //将数据发送给客户端
                        memcpy(buffer, IP_FOUND_ACK, strlen(IP_FOUND_ACK) + 1);
                        scanf("%s", buffer);
                        count = sendto(server_sock, buffer, strlen(buffer), 0,
                                (struct sockaddr*) &from_addr, sizeof(struct sockaddr_in));
                    }
                }
                else
                {
                    printf(">>>>\n");
                }
                
                break;
        }
    }
    
   return 0; 
}