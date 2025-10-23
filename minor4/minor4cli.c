//Alex Kesler
//ack0136

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
 
int main(int argc, char *argv[])
{
	int sockfd = 0, n = 0, portno;
	char recvBuff[1025];
	printf("1\n");
	struct sockaddr_in serv_addr;
	struct hostent *host;
	host = gethostbyname(argv[2]);
 	printf("hi");
	memset(recvBuff, '0', sizeof(recvBuff));
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("socket error\n");
		exit(EXIT_FAILURE);
	}
	printf("hi");
	serv_addr.sin_family = AF_INET;
	portno = atoi(argv[2]);
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = *(long *)(host->h_addr_list[0]);

 	if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("connect error\n");
		exit(EXIT_FAILURE);
	}
 
	while ((n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
	{
		//recvBuff[n] = 0;
		if (fputs(recvBuff, stdout) == EOF)
		{
			printf("fputs error\n");
		}
	}
 
	if (n < 0)
	{
		printf("read error\n");
	}
	for (int i = 0; i < 10; i++){
		send(sockfd, recvBuff, sizeof(recvBuff)-1,0);
		sleep(1);
	}
 
	return 0;
}

