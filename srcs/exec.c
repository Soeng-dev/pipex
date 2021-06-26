/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:56:55 by soekim            #+#    #+#             */
/*   Updated: 2021/06/26 20:27:02 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exec.h"

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
		ft_putstr_fd("hi\n", 1);
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
	char	*path;
	char	**cmd_arg;

	pid = fork();
	if (pid < 0)
		perror_exit("Error : fork");
	if (pid == CHILD)
	{
		path = find_cmdpath(cmd, envp);

		ft_putstr_fd("path fin\n", 1);//test
		cmd_arg = read_cmd_arg(pipeline[RD]);
		dup2(pipeline[WR], STDOUT);
		execve(path, cmd_arg, NULL);
	}
	waitpid(CHILD, NULL, 0);
	return ;
}
