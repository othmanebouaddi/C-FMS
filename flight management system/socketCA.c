//socketCA.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>



void socketCA()
{
	//creat socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	// specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9003);
	server_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	//check for errour with connection
	if (connection_status == -1)
	{
		printf("There is a problem with connection! \n\n");
	}

	//recive data from the server
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0);

	//print out the server's response
	printf("The server sent the data : %s\n", server_response );


	//Close the socket
	close(network_socket);
}