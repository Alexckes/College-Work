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

int main()
{
	while(1){
	//URL from user
	char url[4069];
	printf("\nURL: ");
	scanf("%s",url);
	if(!strcmp(url,"quit")){
		return 0;
	}
	
	//convert URL to host
	struct hostent *host;
	host = gethostbyname(url);
	
	//port number from user
	char port[10];
	printf("\nPORT: ");
	scanf("%s",port);
	
	int portno = atoi(port);
	int sockfd = 0, n = 0;
	char buff[81820];
	struct sockaddr_in serv_addr;
	memset(buff, '0', sizeof(buff));
	
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("socket error\n");
		exit(EXIT_FAILURE);
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = *(long *)(host->h_addr_list[0]);
	
 	
	//checks to see if list.txt exists, if not makes it
	FILE * list;
	list = fopen("list.txt","r+");
	if(list==NULL){
		list = fopen("list.txt","w+");
	}
	//check cache for requested page
	
	char mystring[100];
	char accessTime[100];
	int cacheFound = 0;
	while(!feof(list)){
		//saves the time for later as well
		fscanf(list,"%s %s",mystring,accessTime);
		if(strcmp(mystring,url) == 0){
			cacheFound = 1;
			break;
		}
	}
	fclose(list);
	
	int kl = 0;
	
	//cache is not in list
	if(cacheFound == 0){
		//connect
		
		if (kl = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
		{
			printf("connect error\n");
			exit(EXIT_FAILURE);
		}
		if (n < 0)
		{
			printf("read error\n");
		}
		
		//send GET request
		char writeBuff[100] = "GET / HTTP/1.1\r\nHost: ";
		strcat(writeBuff,url);
		strcat(writeBuff,":");
		strcat(writeBuff,port);
		strcat(writeBuff,"\r\nConnection: Close\r\n\r\n");
		int h = 0;
		
		while(h < sizeof(writeBuff)){
		h = send(sockfd, writeBuff, sizeof(writeBuff),0);
		}
		
		sleep(2);
		//receive response after 2 seconds
		int kel = 0;
		int kel2 = 0;
		while(1){
			kel += read(sockfd,buff,sizeof(buff));
			if(kel == kel2)
				break;
			kel2 = kel;
		}
		
		char ok[12];
		strncpy(ok,buff,12);
		printf("%s\n",buff);
		//check HTTP response
		if(strcmp("HTTP/1.1 200",ok) == 0){
			printf("\ncheckpoint");
			//getting time
			char temp1[50];
			char * temp6;
			temp6 = strstr(buff,"Date: ");
			strncpy(temp1,temp6,35);
			//convert month to number
			char numMon[3];
			strcpy(numMon,"00");
			if(strstr(temp1,"Jan")){
				strcpy(numMon,"01");
			}
			else if(strstr(temp1,"Feb")){
				strcpy(numMon,"02");
			}
			else if(strstr(temp1,"Mar")){
				strcpy(numMon,"03");
			}
			else if(strstr(temp1,"Apr")){
				strcpy(numMon,"04");
			}
			else if(strstr(temp1,"May")){
				strcpy(numMon,"05");
			}
			else if(strstr(temp1,"Jun")){
				strcpy(numMon,"06");
			}
			else if(strstr(temp1,"Jul")){
				strcpy(numMon,"07");
			}
			else if(strstr(temp1,"Aug")){
				strcpy(numMon,"08");
			}
			else if(strstr(temp1,"Sep")){
				strcpy(numMon,"09");
			}
			else if(strstr(temp1,"Oct")){
				strcpy(numMon,"10");
			}
			else if(strstr(temp1,"Nov")){
				strcpy(numMon,"11");
			}
			else{
				strcpy(numMon,"12");
			}
			//create filename
			char date[15];
			date[0] = temp1[18];
			date[1] = temp1[19];
			date[2] = temp1[20];
			date[3] = temp1[21];
			date[4] = numMon[0];
			date[5] = numMon[1];
			date[6] = temp1[11];
			date[7] = temp1[12];
			date[8] = temp1[23];
			date[9] = temp1[24];
			date[10] = temp1[26];
			date[11] = temp1[27];
			date[12] = temp1[29];
			date[13] = temp1[30];
			//create cache file
			FILE * cache = fopen(date,"w+");
			//copy buffer into cache file
			fprintf(cache,"%s",buff);
			fclose(cache);
			list = fopen("list.txt","r");
			FILE * tempFile = fopen("tempFile","w");
			char listed[256];
			strcat(listed,url);
			strcat(listed," ");
			strcat(listed,date);
			strcat(listed,"\n");
			//add url and filename to list, replacing the oldest instance if there are 6
			int zc = 0;
			char olddate[] = "first";
			int oldind = 0;
			char durl[100];
			char ddate[100];
			//find the oldest date
			while(zc < 6 && !feof(list)){
				fscanf(list,"%s %s",durl,ddate);
				if(strcmp(olddate,"first") == 0){
					strcpy(olddate,ddate);
				}
				if(strcmp(olddate,ddate) > 0){
					strcpy(olddate,ddate);
					oldind = zc;
				}
				zc++;
			}
			//replace oldest date if list is full
			rewind(list);
			int tzc = 0;
			while(tzc < 6 && !feof(list)){
				fscanf(list,"%s %s",durl,ddate);
				if(tzc == oldind && zc ==6){
					fprintf(tempFile,"%s\n", listed);
				}
				else{
					fprintf(tempFile,"%s %s\n",durl,ddate);
				}
				tzc++;
			}
			//append to end of list if not full
			if(zc != 6){
				fprintf(tempFile,"%s",listed);
			}
			else{
				//remove oldest file
				remove(olddate);
			}
			//replace old list with new list
			fclose(list);
			fclose(tempFile);
			remove("list.txt");
			rename("tempFile","list.txt");
			printf("Action: Page cached as: filename - %s\n",date);
		}
		//if HTTP response wasn't 200
		else{
			char * notok;
			notok = strchr(ok,' ');
			char ntk[8];
			strcpy(ntk,notok);
			printf("Response:%s\nAction: Not cached\n",ntk);
		}
	}
	//cache is in list
	else{
		printf("Action: Page found in cache, filename - %s\nCheck if modified: ",accessTime);
		char modquery1[8];
		scanf("%s",modquery1);
		printf("\n");
		//check the if-modified-since on the website
		if(strstr(modquery1,"Yes")){
			char modquery2[128];
			printf("Date: ");
			scanf("%30c",modquery2);
			modquery2[0] = ' ';
			printf("%s\n",modquery2);
			printf("\n");
			//connect
			if (kl = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
			{
				printf("connect error\n");
				exit(EXIT_FAILURE);
			}
			if (n < 0)
			{
				printf("read error\n");
			}
			char writeBuff2[1000] = "GET / HTTP/1.1\r\nHost: ";
			char modquery3[30];
			strcpy(modquery3,modquery2);
			strcat(writeBuff2,url);
			strcat(writeBuff2,":");
			strcat(writeBuff2,port);
			strcat(writeBuff2,"\r\nIf-Modified-Since:");
			strcat(writeBuff2,modquery3);
			
			strcat(writeBuff2,"\r\nConnection: Close\r\n\r\n");
			printf("%s\n",writeBuff2);
			//send it
			int h = 0;
			while(h < sizeof(writeBuff2)){
			h = send(sockfd, writeBuff2, sizeof(writeBuff2),0);
			}
			sleep(2);
			//receive response after 2 seconds
			int kel = 0;
			while(kel < 100){
				read(sockfd,buff,sizeof(buff));
				kel++;
			}
			
			printf("%s\n",buff);
			char ok2[12];
			strncpy(ok2,buff,12);
			if(strcmp("HTTP/1.1 200",ok2) == 0){
				char temp1[50];
				char * temp6;
				temp6 = strstr(buff,"Date: ");
				strncpy(temp1,temp6,35);
				//convert month to number
				char numMon[3];
				strcpy(numMon,"00");
				if(strstr(temp1,"Jan")){
					strcpy(numMon,"01");
				}
				else if(strstr(temp1,"Feb")){
					strcpy(numMon,"02");
				}
				else if(strstr(temp1,"Mar")){
					strcpy(numMon,"03");
				}
				else if(strstr(temp1,"Apr")){
					strcpy(numMon,"04");
				}
				else if(strstr(temp1,"May")){
					strcpy(numMon,"05");
				}
				else if(strstr(temp1,"Jun")){
					strcpy(numMon,"06");
				}
				else if(strstr(temp1,"Jul")){
					strcpy(numMon,"07");
				}
				else if(strstr(temp1,"Aug")){
					strcpy(numMon,"08");
				}
				else if(strstr(temp1,"Sep")){
					strcpy(numMon,"09");
				}
				else if(strstr(temp1,"Oct")){
					strcpy(numMon,"10");
				}
				else if(strstr(temp1,"Nov")){
					strcpy(numMon,"11");
				}
				else{
					strcpy(numMon,"12");
				}
				//create filename
				char date[15];
				date[0] = temp1[18];
				date[1] = temp1[19];
				date[2] = temp1[20];
				date[3] = temp1[21];
				date[4] = numMon[0];
				date[5] = numMon[1];
				date[6] = temp1[11];
				date[7] = temp1[12];
				date[8] = temp1[23];
				date[9] = temp1[24];
				date[10] = temp1[26];
				date[11] = temp1[27];
				date[12] = temp1[29];
				date[13] = temp1[30];
				//create cache file
				FILE * cache = fopen(date,"w+");
				//copy buffer into cache file
				fprintf(cache,"%s",buff);
				fclose(cache);
				list = fopen("list.txt","r");
				FILE * tempFile = fopen("tempFile","w");
				char listed[256];
				strcat(listed,url);
				strcat(listed," ");
				strcat(listed,date);
				strcat(listed,"\n");
				//replace old url's filename with new one
				char durl[100];
				char ddate[100];
				while(!feof(list)){
					fscanf(list,"%s %s",durl,ddate);
					if(strcmp(durl,url)==0){
						fprintf(tempFile,"%s\n",listed);
					}
					else{
						fprintf(tempFile,"%s %s\n",durl,ddate);
					}
				}
				//replace old list with new list
				fclose(list);
				fclose(tempFile);
				remove("list.txt");
				rename("tempFile","list.txt");
				printf("Action: Page cached as: filename - %s\n",date);
				remove(accessTime);
			}
			else{
				char * notok2;
				notok2 = strchr(ok2,' ');
				char ntk2[8];
				strcpy(ntk2,notok2);
				printf("Response:%s\nAction: Not cached\n",ntk2);
			}
		}
	}
	}
}
	/*
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
	*/
 	


