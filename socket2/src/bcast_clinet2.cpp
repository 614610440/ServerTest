#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>
 
#define IP_FOUND "IP_FOUND"
#define IP_FOUND_ACK "IP_FOUND_ACK"
#define IFNAME "eth0"
#define MAX_SIZE 1024
#define MCAST_PORT 8080

int main(int argc, char*argv[])
{
    char buffer[MAX_SIZE];
    struct ifreq *ifr;
    struct ifconf ifc;

    struct sockaddr_in broadcast_addr; //广播地址
    int so_broadcast = 1;
    //建立数据报套接字
    int client_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_sock < 0)
    {
        perror("create socket failed:");
        return 1;
    }

    // 获取所有套接字接口
    ifc.ifc_len = sizeof(buffer);
	ifc.ifc_buf = buffer;
    if (ioctl(client_sock, SIOCGIFCONF, (char *) &ifc) < 0)
	{
		perror("ioctl-conf:");
		return 2;
	}
    ifr = ifc.ifc_req;
    int i;
    for (i = ifc.ifc_len / sizeof(struct ifreq); --i >=0; ifr++)
    {
        if (!strcmp(ifr->ifr_name, "eth0"))
        {
            if (ioctl(client_sock, SIOCGIFFLAGS, (char *) ifr) < 0)
			{
				perror("ioctl-get flag failed:");
			}
			break;
        }
    }
    
    memcpy(&broadcast_addr, (char *)&ifr->ifr_broadaddr, sizeof(struct sockaddr_in));
    printf("\nBroadcast-IP: %s\n", inet_ntoa(broadcast_addr.sin_addr));
	broadcast_addr.sin_family = AF_INET;
	broadcast_addr.sin_port = htons(MCAST_PORT);

    //默认的套接字描述符sock是不支持广播，必须设置套接字描述符以支持广播
	int ret = setsockopt(client_sock, SOL_SOCKET, SO_BROADCAST, &so_broadcast,
			sizeof(so_broadcast));

    return 0;
}