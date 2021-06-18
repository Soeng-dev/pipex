/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:13:04 by soekim            #+#    #+#             */
/*   Updated: 2021/06/18 23:13:10 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exec.h"

void	init_pipe(int **data)
{
	if (pipe(data[P_TO_C]) < 0)
	{
		perror("Error : pipe from parent to children");
		exit(1);
	}
	if (pipe(data[C_TO_P]) < 0)
	{
		perror("Error : pipe from children to parent");
		exit(1);
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

void	pipex(t_arg *arg, char **envp, int **data)
{
	int		i;
	int		pid;

	i = 2;
	while (i < arg->cnt)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Error : fork");
			exit (1);
		}
		if (pid == CHILD)
		{
			exec_cmd();
		}
		else
		{
			waitpid(CHILD);
			
		}
	}
	return ;
}
