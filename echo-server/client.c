#include "common_header.h"
#include <arpa/inet.h>
#include <stdlib.h>

int main(void) 
{
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0) 
	{
		printf("socket() = fail!\n");
	}

	struct sockaddr_in addr;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	inet_pton(AF_INET, IP, &(addr.sin_addr));
	addr.sin_port = htons(PORT);

	int rc = connect(socket_fd, (struct sockaddr *)&addr, sizeof(addr));
	if (rc < 0) 
	{
		printf("connect() = fail!\n");
	}

	while (1) 
	{
		char sendline[BUFFER], recvline[BUFFER];
		bzero(sendline, BUFFER);
		bzero(recvline, BUFFER);

		printf("Sendline: ");
		fgets(sendline, BUFFER, stdin);

		write(socket_fd, sendline, strlen(sendline)+1);

		read(socket_fd, recvline, BUFFER);
		printf("Recvline: %s",recvline);
	}

	close(socket_fd);
	return 0;
}
