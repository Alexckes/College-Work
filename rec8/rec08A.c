/*
 * usage: ./a.out text_pattern input_file output_file
 * Executes the command "grep text_pattern < input_file > output_file"
 */

#include <stdio.h>
#include <string>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	int ifp, ofp;

	if (argc == 4)
	{
		std::string g = "grep";
		int n = g.length();
		char c[n + 1];
		strcpy(c,g.c_str());
		// grep on text_pattern 
  		char *grep_args[] = {c, argv[1], NULL};

		// open input and output files
		ifp = open(argv[2], O_RDONLY);
		ofp = open(argv[3], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

		// duplicate input file to stdin
        dup2(ifp,fileno(stdin));

		// duplicate output file to stdout
	dup2(ofp,fileno(stdout));

		// close unused input file descriptor
	close(2);
        
		// close unused output file descriptor
        close(3);

		// execute grep
		execvp("grep", grep_args);
	}
	else
	{
		printf("usage: %s text_pattern input_file output_file\n", argv[0]);
	}
}
