/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:13:04 by soekim            #+#    #+#             */
/*   Updated: 2021/06/21 23:39:20 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exec.h"

//output of exec cmd redirects to piped arr data, but when data==NULL just stdout

//typedef		void	*(exec_cmd)(char **, int **)	t_exec;
//
//struct s_execinfo
//{
//	int		**data;
//	t_exec	cmd;
//};
//typedef struct	s_execinfo	t_execinfo;
//
//void	exec_pipe(t_execinfo front)
//{


//read_cmd_arg써주기
void	exec_ls(char **arg, int **data)
{
	int		pid;

	pid = fork();
	if (pid < 0)
		perror_exit("Error : fork");
	if (pid == CHILD)
	{
		if (data)
			dup2(data[C_TO_P][WRITE], STDOUT);
		execve("/bin/ls", arg, NULL);
	}
	return ;
}

void	exec_grep(char **arg, int **data)
{
	int		pid;

	pid = fork();
	if (pid < 0)
		perror_exit("Error : fork");
	if (pid == CHILD)
	{
		if (data)
			dup2(data[C_TO_P][WRITE], STDOUT);
		execve("/usr/bin/grep", arg, data);
	}
	return ;
}

void	exec_cmd(char *cmd, char **envp, int **data)
{
	char	*path;
	char	*input;
	char	**cmd_arg;

	path = find_path(envp);
	cmd_arg = read_cmd_arg(data[C_TO_P][READ]);
	execve(path, cmd_arg, NULL);
}

