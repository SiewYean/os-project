#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main() {
	
	int sd;
	struct sockaddr_in addr;

	sd = socket(PF_INET,SOCK_STREAM,0);
	//SOCK_STREAM == TCP -> stream of data
	
	int one = 1; 
	//1 means enable
	setsockopt(sd, SOL_SOCKET, SO_REUSEADDR|SO_REUSEPORT, &one, sizeof(one));
	//prevent server from crashing as the socket was not released in time for another client

	addr.sin_family = AF_INET;
	//sin.family -> socket internet family
	addr.sin_port = htons(33333);
	//htons -> converts number into network format to prevent errors
	addr.sin_addr.s_addr = INADDR_ANY;
	//it can listen to any IP address -> not hardcoded to listen to only one address

	bind(sd, &addr, sizeof(addr));
	//bind function -> bind address to socket
	
	listen(sd, 20);
	//can be any number, not must 20
	//listen for connection from any client
	
	int addr_len = sizeof(addr);
	int clientsd = accept(sd, &addr, &addr_len);
	//& -> pass by reference -> it is a pointer
	
	char buf[64] = {};
	memset(buf, 0, 64);

	recv(clientsd, buf, 64, 0);

	printf("Client -> %s\n",buf);

	close(clientsd);
	close(sd);

	return 0;
}
