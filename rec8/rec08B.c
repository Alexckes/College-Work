/*
 * usage: ./a.out input_file text_pattern
 * Executes the command "cat input_file | grep text_pattern | cut -b 1-10".
 * Note only minimal error checking is done for simplicity/shortness of code.
 */
#include <stdio.h>
#include <string>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int status;
	int i;

	if (argc == 3)
	{
		std::string cat1 = "cat";
		int n1 = cat1.length();
		char cat2[n1 + 1];
		strcpy(cat2,cat1.c_str());

		std::string g = "grep";
		int n2 = g.length();
		char c[n2 + 1];
		strcpy(c,g.c_str());

		std::string cut1 = "cut";
		int n3 = cut1.length();
		char cut2[n3 + 1];
		strcpy(cut2,cut1.c_str());

		std::string b1 = "-b";
		int n4 = b1.length();
		char b2[n4 + 1];
		strcpy(b2,b1.c_str());

		std::string oneten1 = "1-10";
		int n5 = oneten1.length();
		char oneten2[n5 + 1];
		strcpy(oneten2,oneten1.c_str());

		// arguments for commands
		char *cat_args[]  = {cat2, argv[1], NULL};
		char *grep_args[] = {c, argv[2], NULL};
		char *cut_args[]  = {cut2, b2, oneten2, NULL};

		// file descriptors for 2 pipes: fd1 for cat-to-grep, fd2 for grep-to-cut
		int fd1[2], fd2[2];

        // make pipe for cat to grep
		// fd1[0] = read  end of cat->grep pipe (read by grep)
		// fd1[1] = write end of cat->grep pipe (written by cat)
		pipe(fd1);
		write(fd1[1],cat_args,strlen("cat") + 1);
		read(fd1[0],grep_args,strlen("grep")+1);

        // make pipe for grep to cut
		// fd2[0] = read  end of grep->cut pipe (read by cut)
		// fd2[1] = write end of grep->cut pipe (written by grep)
		pipe(fd2);
		read(fd2[0],cut_args,strlen("cut")+1);
		write(fd2[1],grep_args,strlen("grep")+1);
		
		// fork the first child (to execute cat)
		if (fork() == 0)
		{
			// duplicate write end of cat->grep pipe to stdout
			dup2(fd1[1],fileno(stdout));

			// close both ends of all created fd# pipes (very important!)
      			close(fd1[0]);
			close(fd1[1]);
			close(fd2[0]);
			close(fd2[1]);
      			
      			
      			

            execvp(*cat_args, cat_args);
 	 	}
  		else // parent (assume no error)
        {
            // fork second child (to execute grep)
            if (fork() == 0)
			{
	  			// duplicate read end of cat->grep pipe to stdin (of grep)
	  			dup2(fd1[0],fileno(stdin));

	  			// duplicate write end of grep->cut pipe to stdout (of grep)
	  			dup2(fd2[1],fileno(stdout));

	  			// close both ends of all created fd# pipes (very important!)
	  			close(fd1[0]);
			close(fd1[1]);
			close(fd2[0]);
			close(fd2[1]);

	  			
	  			
	  			

	  			execvp(*grep_args, grep_args);
			}
            else // parent (assume no error)
			{
	  			// fork third child (to execute cut)
	  			if (fork() == 0)
                {
                    // duplicate read end of grep->cut pipe to stadin (of cut)
	      			dup2(fd2[0],fileno(stdin));	

                    // close both ends of all created fd# pipes (very important!)
	      				close(fd1[0]);
			close(fd1[1]);
			close(fd2[0]);
			close(fd2[1]);

	      				
	      				
	      				

                    execvp(*cut_args, cut_args);
                }
			}
        }
      
  		// only the parent gets here, close all pipes and wait for 3 children to finish
  		close(fd1[0]);
  		close(fd1[1]);
  		close(fd2[0]);
  		close(fd2[1]);

  		for (i = 0; i < 3; i++)
		{
    			wait(&status);
		}
	}
	else
	{
		printf("usage: %s input_file text_pattern\n", argv[0]);
	}

	return 0;
}
