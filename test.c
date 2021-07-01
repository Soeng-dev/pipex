
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "includes/vars.h"
#include "includes/get_next_line.h"
#include "includes/libft/libft.h"


void	test_arrptr(int (*ptr)[2])
{
	printf("%p	%d	%d\n", ptr[0], ptr[0][0], ptr[0][1]);
	printf("%p	%d	%d\n",ptr[1], ptr[1][0], ptr[1][1]);
}

int		main(int argc, char **argv, char **envp)
{
//	int arr[2][2];
//	arr[0][0] = 0; arr[0][1] = 1;
//	arr[1][0] = 10; arr[1][1] = 11;
//	test_arrptr(arr);

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


//don't know how to use dup2 and pipe
//
//	int		status;
//	int		pipeline[2];
//
//	pipe(pipeline);
//	int		pid = fork();
//	if (pid == 0)
//	{
//		int fd = open("./hi", O_RDWR);
//		char arr[101];
//
//		arr[100] = 0;
//		read(fd, arr, 100);
//
//		write(1, "child\n", 6);
//		write(1, arr, 100);
//
//		write(pipeline[WR], arr, 100);
//		write(1, "\nwrited\n", 8);
//		return (0);
//	}
//	char	hi[101];
//
//	waitpid(0, NULL, 0);
//	read(pipeline[RD], hi, 100);
//
//	hi[100] = 0;
//	write(1, "\nparent\n", 8);
//	write(1, hi, 100);
//
//	write(pipeline[WR], hi, 100);
//
//	pid = fork();
//	if (pid == 0)
//	{
//		char	arr[101];
//
//		write(1, "\nchild2\n", 8);
//		read(pipeline[RD], arr, 100);
//		write(1, arr, 100);
//
//		int		fd = open("./bye", O_RDWR);
//
//		read(fd, arr, 100);
//		write(pipeline[WR], arr, 100);
//		return (0);
//	}
//	waitpid(0, NULL, 0);
//
//	read(pipeline[RD], hi, 100);
//	hi[100] = 0;
//	write(1, "\nparent\n", 8);
//	write(1, hi, 100);
	
//	char *ho;
//	int fd = open("./end", O_RDWR);
//	get_next_line(fd, &ho);
//	printf("ft_strlen %d, cont :%s\n", ft_strlen(ho), ho);
//	free(ho);

	char *arg[4];
	arg[0] = "grep";
	arg[1] = "sr";
	arg[2] = NULL;//"a";
	arg[3] = NULL;
	execve("/usr/bin/grep", arg, NULL);

//	char *pre = NULL;
//	char *post = "abcd";
//	char *joined=ft_strjoin(pre, post);
//

	return (0);
}
