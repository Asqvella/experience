#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 22000
#define MAX_CONNECTIONS 10
#define BUFFER 1024
#define IP "127.0.0.1"
