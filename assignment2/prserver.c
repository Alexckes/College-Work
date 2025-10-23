//Alex Kesler
//ack0136

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
 
int main(int argc, char *argv[])
{
	int listenfd = 0, connfd = 0, cli_size, portno;

	struct sockaddr_in serv_addr, cli_addr;
	char sendBuff[4096];  
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("socket error\n");
		exit(EXIT_FAILURE);
	}

	int on = 1; 
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)); 

	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));

	serv_addr.sin_family = AF_INET;    
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
	portno = atoi(argv[1]);
	serv_addr.sin_port = htons(portno);    

	if (bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
	{
		printf("usage: ./minor4svr <port>\n");
		exit(EXIT_FAILURE);
	}


	if (listen(listenfd, 3) == -1)
	{
		printf("listen error\n");
		exit(EXIT_FAILURE);
	}
	cli_size = sizeof(cli_addr);
	if ((connfd = accept(listenfd, (struct sockaddr*)&serv_addr, (socklen_t*)&cli_size)) == -1)
	{
		printf("accept error\n");
		exit(EXIT_FAILURE);
	}
	//loop 4 times, once for each packet being sent
	for(int i = 0; i < 4; i++){
		//reads the whole packet into buffer
		while(1){
			int bytesRead = recv(connfd,sendBuff,sizeof(sendBuff),0);
		
			if(bytesRead == 4096)
			break;
		}
		//send the whole buffer back to client
		while(1){
			int bytesSent = send(connfd,sendBuff,sizeof(sendBuff),0);
	
			if(bytesSent == 4096)
			break;
		}
		//reset the buffer
		bzero(sendBuff,4096);
	}
	close(connfd);    
	sleep(1);
	
 	
	return 0;
}

