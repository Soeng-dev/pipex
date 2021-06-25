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

#include "../includes/exec.h"

void	init_pipe(int *pipeline, int input_fd)
{

	if (pipe(pipeline) < 0)
		perror_exit("Error : pipe");
	if (input_fd >= 0)
			transfer_data(input_fd, pipeline[P_WRITE]);
	return ;
}

void	exec_arg(t_arg *arg, char **envp, t_inout *inout)
{
	int		i;
	int		num_of_cmd;
	int		pipeline[2];

	if (arg->cnt - 1 == 2 && arg->cnt - 1 == 3)
		num_of_cmd = arg->cnt - 1;
	else if (arg->cnt - 1 >= 4)
		num_of_cmd = arg->cnt - 2;
	else
		return ;
	init_pipe(pipeline, inout->in.fd);
	i = 1;
	while (i < num_of_cmd)
	{
		exec_cmd(arg->vec[i], envp, pipeline);
		transfer_data(pipeline[RD], pipeline[WR]);
		++i;
	}
	if (arg->cnt - 1 >= 4)
		transfer_data(pipeline[RD], inout->out.fd);
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
		dup2(pipeline[WR], STDOUT);
		execve(path, cmd_arg, NULL);
	}
	else
		waitpid(CHILD, &status, 0);
	return ;
}
