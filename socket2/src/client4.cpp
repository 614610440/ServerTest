#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include<errno.h> 

const int port = 8888;

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf ("usage: ./client4 <ipaddress>\n");
        return 0;
    }

    const char* ip = argv[1];

    int clt_sock = socket(AF_INET, SOCK_STREAM, 0);  //create socket
    if (clt_sock < 0)
    {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;  //绑定信息，即命名socket 
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
     /*inet_addr函数将用点分十进制字符串表示的
	  IPv4地址转化为用网络字节序整数表示的IPv4地址 */

    //发起连接
    int connect_fd = connect(clt_sock, (struct sockaddr*)&addr, sizeof(addr));
    if (connect_fd < 0)
    {
        perror("connect");
        return 2;
    }

    char sendline[1024], recvline[1024];
    while (1)
    {
        memset(sendline, '\0', sizeof(sendline));
        printf("please enter: ");
        fgets(sendline, 1024, stdin);

        // if ()

        printf("read is done...\n");
        
        if (send(clt_sock, sendline, strlen(sendline), 0) < 0)
        {
            printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
        }

        printf("send is done...\nwaiting server msg...");

        // printf("sizeof: %d,  strlen: %d", sizeof(sendline), strlen(sendline));
        if (recv(clt_sock, recvline, sizeof(recvline), 0) < 0)
        {
            printf("recv faile,,.\n");
        }
        printf ("recive: %s\n", recvline);
    }

    return 0;
}
