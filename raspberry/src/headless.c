#include"headless.h"

/************************************************************
Function:	server

Type:		int

Return:		0 for 'q' keypress

Description:	Starts a socket to get keypresses from client.
		Passes these inputs to the headlessinput function
		in the headlessinput header.
*************************************************************/

int server(void)
{
	int server_input;
	char server_read[2];
	int listen_fd, comm_fd;
	struct sockaddr_in servaddr;
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&servaddr, '\0', sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(22000);
	bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	listen(listen_fd, 10);
	comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
	while(1)
	{
		server_input = 0;
		memset(server_read, '\0', 2);
		if(read(comm_fd, server_read, 2) == -1)
		{
			return 1;
		}
		server_input = server_read[0];
		if(server_input == 'q')
		{
			headlessinput('q');
			init(0);
			return 0;
		}
		headlessinput(server_input);
	}
}

