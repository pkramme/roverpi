#include"headless.h"

int server()
{
	char server_read[2];
	int listen_fd, comm_fd;
	struct sockaddr_in servaddr;
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	//memset(server_read, '\0', 8);
	memset(&servaddr, '\0', sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(22000);
	bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	listen(listen_fd, 10);
	comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
	while(1)
	{
		memset(server_read, '\0', 2);
		read(comm_fd, server_read, 2);
		printf("%s", server_read);
	}
}
