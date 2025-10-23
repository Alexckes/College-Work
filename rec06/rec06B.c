#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const char *name;
pid_t pid = fork();

int main(){
	if(pid == 0){
		printf("child: %d started\n",getpid());
		printf("child: parent = %d\n",getppid());
		printf("child: %d is going to sleep\n",getpid());
		sleep(20);
		printf("child: %d woke up\n",getpid());
	}
	else if(pid > 0){
		printf("parent: %d started\n",getpid());
		printf("parent: parent = %d\n",getppid());
	}
	else{
		perror("fork error");
	}
	(pid == 0) ? (name = "child") : (name = "parent");
	printf("%s: terminating...\n",name);
}