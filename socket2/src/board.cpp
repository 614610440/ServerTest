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
#define BUFFER_LENGTH 1024
#define MAX_CONN_LIMIT 512

static void bail(const char* on_what)
{
    
}