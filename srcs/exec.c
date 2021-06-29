/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:56:55 by soekim            #+#    #+#             */
/*   Updated: 2021/06/29 16:32:06 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exec.h"

void	exec_arg(t_arg *arg, char **envp, t_inout *inout)
{
	int		i;
	int		last_cmd;
	int		pipeline[2];

	if (arg->cnt == 3 || arg->cnt == 4)
		last_cmd = arg->cnt;
	else if (arg->cnt >= 5)
		last_cmd = arg->cnt - 1;
	else
		return ;
	init_pipe(pipeline, inout->in.fd);
	i = 2;
	while (i < last_cmd)
	{
		exec_cmd(arg->vec[i], envp, pipeline);
		transfer_data(pipeline[RD], pipeline[WR]);
		++i;
	}
	if (arg->cnt >= 5)
		transfer_data(pipeline[RD], inout->out.fd);
	return ;
}

void	exec_cmd(char *cmd, char **envp, int *pipeline)
{
	int		pid;
	char	*path;
	char	**cmd_arg;

	pid = fork();
	if (pid < 0)
		perror_exit("Error : fork");
	if (pid == CHILD)
	{
		path = find_cmdpath(cmd, envp);
		cmd_arg = read_cmd_arg(pipeline[RD]);
		ft_putstr_fd("arg fin\n", 1);//test
		dup2(pipeline[WR], STDOUT);
		execve(path, cmd_arg, NULL);
	}
	waitpid(CHILD, NULL, 0);
	return ;
}
