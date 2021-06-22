/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:56:55 by soekim            #+#    #+#             */
/*   Updated: 2021/06/22 20:39:56 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

void	init_pipe(int *pipeline, int input_fd)
{

	if (pipe(pipeline) < 0)
		perror_exit("Error : pipe");
	transfer_data(inout->in.fd, pipeline[P_WRITE]);
	return ;
}

void	pipex(t_arg *arg, char **envp, t_inout *inout)
{
	int		i;
	int		pipeline[2];

	init_pipe(pipeline, inout->in.fd);
	i = 1;
	while (i < arg->cnt - 1)
	{
		exec_cmd(arg->vec[i], envp, pipeline);
		transfer_data(pipeline[P_READ], pipeline[P_WRITE]);
		++i;
	}
	
	return ;
}

void	exec_cmd(char *cmd, char **envp, int *pipeline)
{
	int		pid;
	int		status;
	char	*path;
	char	**cmd_arg;

	pid = fork();
	if (pid < 0)
		perrror_exit("Error : fork");
	if (pid == CHILD)
	{
		path = find_cmdpath(cmd, envp);
		cmd_arg = read_cmd_arg(pipeline[C_READ]);
		dup2(pipeline[C_WRITE], STDOUT);
		execve(path, cmd_arg, NULL);
	}
	else
		waitpid(CHILD, &status, 0);
	return ;
}

