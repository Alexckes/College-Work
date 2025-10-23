// Server side implementation of UDP client-server model
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


#define MAXLINE 1024

struct UDPsegment{
	unsigned short int source_port;
	unsigned short int destination_port;
	unsigned short int length;
	unsigned short int checksum;
	char payload[256];
};

int toBinary(int dec){
	int bin=0,remain,f=1;
	while(dec!=0){
		remain = dec % 2;
		bin = bin + remain * f;
		f = f * 10;
		dec = dec/2;
	}
	
	return bin;
}

int checksum(int binary1, int binary2){
	int remainder = 0, i = 0, sum[20];
	while (binary1 != 0 || binary2 != 0)
    {
        sum[i++] =(binary1 % 10 + binary2 % 10 + remainder) % 2;
        remainder =(binary1 % 10 + binary2 % 10 + remainder) / 2;
        binary1 = binary1 / 10;
        binary2 = binary2 / 10;
    }
    if (remainder != 0)
        sum[i++] = remainder;
		--i;
	int sumsum = 0;
	while(i >= 0){
		sumsum += sum[i--]*10^(i-1);
	}
	return sumsum;
}

// Driver code
int main() {
	printf("Port: ");
	char port[10];
	scanf("%s",port);
	int portno = atoi(port);
	printf("\n");
	int sockfd;
	char buffer[MAXLINE];
	const char *hello = "Hello from server";
	struct sockaddr_in servaddr, cliaddr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(portno);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	socklen_t len;
	int n;
	printf("checkpoint");
	len = sizeof(cliaddr); //len is value/result
	//receive dummy message from client
	n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
	buffer[n] = '\0';
	printf("checkpoint");
	//use dummy message to get client port number
	int clientport;
	clientport = ntohs(cliaddr.sin_port);
	char sourcePort[16];
	sprintf(sourcePort,"%d",clientport);
	//send client port number to client
	sendto(sockfd, (const char *)sourcePort, strlen(sourcePort), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
	//recieve UDPsegment from client
	printf("checkpoint");
	struct UDPsegment * UDPsegment2 = malloc(sizeof(struct UDPsegment));
	n = recvfrom(sockfd, UDPsegment2, sizeof(*UDPsegment2), MSG_WAITALL, (struct sockaddr *) &cliaddr, &len);
	//verify checksum
	printf("checkpoint");
	int binsourceport = toBinary(UDPsegment2->source_port);
	int bindestport = toBinary(UDPsegment2->destination_port);
	int binlength = toBinary(UDPsegment2->length);
	int bincheck = toBinary(UDPsegment2->checksum);
	int checkSum = checksum(binsourceport,bindestport);
	checkSum = checksum(checkSum,binlength);
	checkSum = checksum(checkSum,bincheck);
	//checksum part for payload
	for(int z = 0; z < 256; z+=2){
		//convert two chars at a time into a single 16 digit binary int
		int char1 = toBinary(UDPsegment2->payload[z]);
		int char2 = toBinary(UDPsegment2->payload[z+1]);
		char tempchars[16];
		int charstotal = 0;
		for(int a = 0; a < 16; a++){
			tempchars[a]='0';
		}
		for(int b = 0; b < 8; b++){
			tempchars[b] = char1%(10^b);
		}
		for(int c = 0; c < 8; c++){
			tempchars[c+8] = char2%(10^c);
		}
		for(int d = 0; d < 16; d++){
			charstotal += tempchars[d]*(10^d);
		}
		checkSum = checksum(checkSum,charstotal);
	}
	//convert binary checksum to decimal
	int dec = 0, i = 0, rem;
	while (checkSum!=0) {
    	rem = checkSum % 10;
    	checkSum /= 10;
    	dec += rem * (2^i);
    	++i;
  	}
	printf("source port: %d\n",UDPsegment2->source_port);
	printf("destination port: %d\n",UDPsegment2->destination_port);
	printf("length: %d bytes\n",UDPsegment2->length);
	printf("checksum: %d\n",UDPsegment2->checksum);
	printf("payload: 256 bytes\n");
	printf("computed checksum: %d\n",dec);
	
	FILE * serverlog;
	serverlog = fopen("server.log","w+");
	fprintf(serverlog,"source port: %d\n",UDPsegment2->source_port);
	fprintf(serverlog,"destination port: %d\n",UDPsegment2->destination_port);
	fprintf(serverlog,"length: %d bytes\n",UDPsegment2->length);
	fprintf(serverlog,"checksum: %d\n",UDPsegment2->checksum);
	fprintf(serverlog,"payload: 256 bytes\n");
	if(dec == UDPsegment2->checksum){
		printf("Checksum matched!\n");
		fprintf(serverlog,"checksum matched!\n");
	}
	else{
		printf("checksum mismatch!\n");
		fprintf(serverlog,"checksum mismatched!\n");
	}
	fclose(serverlog);
	printf("server.log written\n");
	return 0;
}
