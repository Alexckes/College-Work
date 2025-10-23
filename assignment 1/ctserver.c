/* Server Code */
/* Run the server on cell01 and the server listens on port 22000 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
 
void func(int connfd)
{
    char buff[255];
    int n;
    // infinite loop for chat
    for (;;) {
        bzero(buff, 255);
   
        // read the message from client and copy it in buffer
        //read(connfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        //printf("From client: %s\t To client : ", buff);
        bzero(buff, 255);
        n = 0;
        // copy server message in the buffer
       // while ((buff[n++] = getchar()) != '\n')
       //     ;
   
        // and send that buffer to client
        write(connfd, "please not hello world", sizeof(255));
   
        // if msg contains "Exit" then server exit and chat ended.
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}

int main()
{
 
    char str[200];
    int listen_fd, conn_fd;
    struct sockaddr_in servaddr;
 
    /* AF_INET - IPv4 IP , Type of socket, protocol*/
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 
    bzero(&servaddr, sizeof(servaddr));
 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000);
 
    /* Binds the above details to the socket */
	bind(listen_fd,  (struct sockaddr *) &servaddr, sizeof(servaddr));
	
	/* Start listening to incoming connections */
	listen(listen_fd, 10);

	func(conn_fd);

  /*  while(1)
    {
           conn_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL);
      bzero(str, 255);
      strcpy(str, "Input: \n\r\0");
      write(conn_fd, str, strlen(str)); // write to the client
	read(conn_fd, str, 255);
	write(conn_fd, str, strlen(str));
if(str == "quit"){ */
     
 close (conn_fd); //close the connection

//	}
  //  }
}
