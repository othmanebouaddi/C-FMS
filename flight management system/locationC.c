//locationC.c


//socketCA.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>



void location(char *address1)
{
	//creat socket
	char *address;
	address = address1;
	int client_socket;
	client_socket = socket(AF_INET, SOCK_STREAM, 0);

	// specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(80);
	inet_aton(address, &server_address.sin_addr.s_addr);



	connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));


	//recive data from the server
	char request[] = "GET / HTTP/1.1\r\n\r\n";
	char response[4096];

	send(client_socket, request, sizeof(request), 0);
	recv(client_socket, &response, sizeof(response), 0);

	//print out the server's response
	printf("The server sent the data : %s\n", response );


	//Close the socket
	close(client_socket);
}