#include "common_header.h"

int main(void) 
{
	int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_fd < 0) 
	{
		printf("socket() = fail!\n");
	}

	struct sockaddr_in addr;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htons(INADDR_ANY);
	addr.sin_port = htons(PORT);

	int rc = bind(listen_fd, (struct sockaddr *)&addr, sizeof(addr));
	if (rc < 0) 
	{
		printf("bind() = fail!\n");
	}

	rc = listen(listen_fd, MAX_CONNECTIONS);
	if (rc < 0) 
	{
		printf("listen() = fail!\n");
	}

	int comm_fd = accept(listen_fd, NULL, NULL);
	if (comm_fd < 0) 
	{
		printf("accept() = fail!\n");
	}

	while (1) 
	{ 
		char str[BUFFER];
		bzero(str, BUFFER);
		read(comm_fd, str, BUFFER);	
		printf("Recvline: %s", str);
		write(comm_fd, str, strlen(str)+1);
	}

	close(comm_fd);
	close(listen_fd);
	return 0;
}
