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
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
 
int main(int argc, char *argv[])
{
	int sockfd = 0, n = 0, portno;
	char recvBuff[4096], writeBuff[4096];
	struct sockaddr_in serv_addr;
	struct hostent *host;
	host = gethostbyname(argv[1]);
	memset(recvBuff, '0', sizeof(recvBuff));
	memset(writeBuff, '0', sizeof(writeBuff));
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("socket error\n");
		exit(EXIT_FAILURE);
	}
	serv_addr.sin_family = AF_INET;
	portno = atoi(argv[2]);
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = *(long *)(host->h_addr_list[0]);

 	if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("connect error\n");
		exit(EXIT_FAILURE);
	}
 
	if (n < 0)
	{
		printf("read error\n");
	}
	//open the files
	int fd = open(argv[3], O_RDONLY);
	int fno = open(argv[4], O_WRONLY);
	//start timer
	struct timeval delayStart;
	struct timeval delayEnd;
	gettimeofday(&delayStart,NULL);
	//loop 4 times, once for each packet being sent
	for (int i = 0; i < 4; i++){
		//reads a fourth of the file into a buffer
		while(1){
		int bytesReadFile = read(fd, writeBuff, sizeof(writeBuff));
		if(bytesReadFile == 4096)
		break;
		}
		//sends that whole buffer to the server
		while(1){
		int bytesSent = send(sockfd, writeBuff, sizeof(writeBuff),0);
		if(bytesSent == 4096)
		break;
		}
		//receives the whole packet back from server into a new buffer
		while(1){
		int bytesReadBuff = recv(sockfd,recvBuff,sizeof(recvBuff),0);
		if(bytesReadBuff == 4096)
		break;
		}
		//writes the whole received packet from a buffer into the output file
		while(1){
		int bytesWrite = write(fno,recvBuff,sizeof(recvBuff));
		if(bytesWrite == 4096)
		break;
		}
		//reset the buffers
		bzero(recvBuff,4096);
		bzero(writeBuff,4096);
	}
	//end timer
	gettimeofday(&delayEnd,NULL);
	//calculate the time
	double delay = (((double)delayEnd.tv_sec) * 1000.0 + ((double)delayEnd.tv_usec) / 1000.0) - (((double)delayStart.tv_sec) * 1000.0 + ((double)delayStart.tv_usec) / 1000.0);
	//calculate the throughput
	double through = 0.016/(delay/1000);
	//print results
	printf("Round Trip Time: %.3f ms\n", delay*2);
	printf("End-to-end Time: %.3f ms\n", delay);
	printf("Throughput: %.3f Mbps\n", through);

 	close(sockfd);
	return 0;
}

