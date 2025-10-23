//Authors: James Heath, Alexander Kesler
//Class: CSCE 3600.004
//Date: 10/21/2022
//Description: A shell program

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

char buffer[512];
char* execargs[512];
char** commands[512];


enum mode_type {SHELL, BATCH};
enum mode_type mode;

int issep(char c) {
    return isspace(c) || iscntrl(c);
}

int main(int argc, char *argv[]) {
    //command line arguments handler
    mode = SHELL;
    if (argc == 2) {
        int fd = open(argv[1], O_RDONLY);
        if (fd < 0) {
            fprintf(stderr, "Error accessing batch filename\n");
            exit(1);
        }

        //lets us call the batchfile stdin to simplify code
        dup2(fd, 0);
        close(fd);
        mode = BATCH;
    }
    else if (argc > 2) {
        fprintf(stderr, "Incorrect command usage. Correct usage: ./newshell [batchfile]\n");
        exit(1);
    }

    char junk;
    int exit_b = 0;
    while(!feof(stdin)) {
        //prompt
        if(mode == SHELL) {
            printf("Enter command: ");
        }

        //input
        memset(buffer, '\0', 512);
        scanf(" %511[^\n]%c", buffer, &junk);

        //input processing. tokenizes input by whitespaces into execargs 
        int nws = 0;
        int numArgs = 0;
        int numCommands = 0;
        execargs[0] = NULL;
        commands[0] = NULL;
        for(int i = 0; i < 512; i++) {
            char c = buffer[i];
            if (issep(c)) {
                buffer[i] = '\0';
                nws = 0;
            }
            else if (c == ';') {
                buffer[i] = '\0';
                nws = 0;
                if(commands[numCommands] != NULL) {
                    numCommands++;
                    execargs[numArgs+1] = NULL;
                    numArgs++;
                }
            }
            else if (!nws && !issep(c)) {
                if(commands[numCommands] == NULL) {
                    commands[numCommands] = &execargs[numArgs];
                    commands[numCommands+1] = NULL;
                }
                execargs[numArgs] = &buffer[i];
                execargs[numArgs+1] = NULL;
                numArgs++;
                nws = 1;
            }
            
            
        }

        //execution
        for(int i = 0; commands[i] != NULL; i++) {
            if (mode == BATCH) {
                printf("Executing command: ");
                for(int j = 0; commands[i][j] != NULL; j++) {
                    printf("%s ", commands[i][j]);
                }
                printf("\n");
            }
            
            //Exit branch
            if(strcmp(commands[i][0], "exit") == 0) {
                exit_b = 1;
            }
            //Exec branch
            else {
                int branch = fork();
                if (branch == 0) {
                    execvp(commands[i][0],commands[i]);

                    //exec error
                    fprintf(stderr, "Execution error\n");
                    exit(1);
                }
                //fork error
                else if (branch < 0) {
                    printf("Fork error\n");
                }

                //sychronization
                wait(NULL);
                printf("\n");
            }
            
        }        

        if(exit_b) {
            exit(0);
        }

    }
    return 0;
}
