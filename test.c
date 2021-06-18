
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


int		main(int argc, char **argv)//, char **envp)
{

//	// test for pid when multi-forked
//	int pid = fork();
//
//	if (pid > 0)
//		printf("parent %d\n", pid);
//	else
//	{
//		printf("\nchild before 2nd fork %d\n\n", pid);
//		pid = fork();
//		printf("child after 2nd fork %d\n", pid);
//		if (pid > 0)
//			return (0);
//		pid = fork();
//		if (pid  == 0)
//			printf("this is 3rd child %d\n", pid);
//		else
//			printf("this is 3rd parent%d\n", pid);
//	}
//
//	//result : seems that when forked again in child process, 
//	//the pid of child process get higher than 0
	
//
//	//test for research how to pass arg to cmd
//	//result : should parse to be delimited by space
//	char **cmd_argv;
//
//	cmd_argv = (char **)malloc(3 * sizeof(char *));
//	cmd_argv[0] = strdup("ls");
//	cmd_argv[1] = ""; //for blank string, just pass it
//	cmd_argv[2] = NULL;
//	execve("/bin/ls", cmd_argv, NULL);
//
//	need to do pipe test, if child exited fd in pipe function remains
}
