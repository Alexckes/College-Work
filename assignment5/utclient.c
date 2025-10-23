// Client side implementation of UDP client-server model
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
	struct UDPsegment UDPsegment1;
	//promt user for server ip address
	printf("Server IP address: ");
	char ipadd[16];
	scanf("%s",ipadd);
	//prompt user for port number
	printf("\nPort: ");
	char port[10];
	scanf("%s",port);
	int portno = atoi(port);
	//prompt user for input file name
	printf("\nInput text: ");
	char inFile[255];
	for(int x = 0; x < 255; x++){
		inFile[x] = '\0';
	}
	scanf("%s",inFile);
	printf("\n");
	printf("checkpoint");
	int sockfd;
	char buffer[MAXLINE];
	const char *hello = "Hello from client";
	struct sockaddr_in	 servaddr;
printf("checkpoint");
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(portno);
	servaddr.sin_addr.s_addr = inet_addr(ipadd);
	
	int n;
	socklen_t len;
	printf("checkpoint");
	char sourcePort[16];
	//send dummy message to server
	sendto(sockfd, (const char *)sourcePort, strlen(sourcePort), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
	printf("checkpoint");
	//receive client's source port from server
	n = recvfrom(sockfd, (char *)sourcePort, MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
	printf("checkpoint");
	sourcePort[n] = '\0';
	//assign it as UDPsegment1's source port
	UDPsegment1.source_port = 0;
	for(int i = 0; i < n; i++){
		UDPsegment1.source_port+=(10^(n-i-1))*sourcePort[i];
	}
	//assign UDPsegment1's destination port
	UDPsegment1.destination_port = portno;
	//assign UDPsegment1's length
	UDPsegment1.length = 264;
	//assign UDPsegment1's payload, but not before filling the payload with nulls
	for(int x = 0; x < 256; x++){
		UDPsegment1.payload[x] = '\0';
	}
	for(int y = 0; y < sizeof(inFile); y++){
		UDPsegment1.payload[y] = inFile[y];
	}
	//generate checksum
	int binsourceport = toBinary(UDPsegment1.source_port);
	int bindestport = toBinary(UDPsegment1.destination_port);
	int binlength = toBinary(UDPsegment1.length);
	int checkSum = checksum(binsourceport,bindestport);
	checkSum = checksum(checkSum,binlength);
	//checksum part for payload
	for(int z = 0; z < 256; z+=2){
		//convert two chars at a time into a single 16 digit binary int
		int char1 = toBinary(UDPsegment1.payload[z]);
		int char2 = toBinary(UDPsegment1.payload[z+1]);
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
	//invert the checksum
	checkSum = 1111111111111111 - checkSum;
	//convert binary checksum to decimal
	
	int dec = 0, i = 0, rem;
	while (checkSum!=0) {
    	rem = checkSum % 10;
    	checkSum /= 10;
    	dec += rem * (2^i);
    	++i;
  	}
	UDPsegment1.checksum = dec;
	//print UDPsegment
	printf("source port: %d\n",UDPsegment1.source_port);
	printf("destination port: %d\n",UDPsegment1.destination_port);
	printf("length: %d bytes\n",UDPsegment1.length);
	printf("checksum: %d\n",UDPsegment1.checksum);
	printf("payload: 256 bytes\n");
	FILE * clientlog;
	clientlog = fopen("client.log","w+");
	fprintf(clientlog,"source port: %d\n",UDPsegment1.source_port);
	fprintf(clientlog,"destination port: %d\n",UDPsegment1.destination_port);
	fprintf(clientlog,"length: %d bytes\n",UDPsegment1.length);
	fprintf(clientlog,"checksum: %d\n",UDPsegment1.checksum);
	fprintf(clientlog,"payload: 256 bytes\n");
	fclose(clientlog);
	printf("client.log written\n");
	//send the UDPsegment
	sendto(sockfd, (struct UDPsegment*) &UDPsegment1, UDPsegment1.length, MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
	close(sockfd);
	return 0;
}
