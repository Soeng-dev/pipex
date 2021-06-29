/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:56:55 by soekim            #+#    #+#             */
/*   Updated: 2021/06/29 20:43:53 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exec.h"

void	exec_arg(t_arg *arg, char **envp, t_inout *inout)
{
	int		i;
	int		last_cmd;
	int		pipes[2][2];

	if (arg->cnt == 3 || arg->cnt == 4)
		last_cmd = arg->cnt;
	else if (arg->cnt >= 5)
		last_cmd = arg->cnt - 1;
	else
		return ;
	init_pipe(pipes, inout->in.fd);
	i = 2;
	while (i < last_cmd)
	{
		exec_cmd(arg->vec[i], envp, pipes);
		transfer_data(pipes[CTOP][RD], pipes[PTOC][WR]);
		++i;
	}
	if (arg->cnt >= 5)
		transfer_data(pipes[CTOP][RD], inout->out.fd);
	else
		transfer_data(pipes[CTOP][RD], STDOUT);
	return ;
}

void	exec_cmd(char *cmd, char **envp, int (*pipes)[2])
{
	int		pid;
	char	*path;
	char	**cmd_arg;

	pid = fork();
	if (pid < 0)
		perror_exit("Error : fork");
	if (pid == CHILD)
	{
		close(pipes[PTOC][WR]);
		close(pipes[CTOP][RD]);
		path = find_cmdpath(cmd, envp);
		cmd_arg = read_cmd_arg(pipes[PTOC][RD]);
		ft_putstr_fd("arg fin\n", 1);//test
		dup2(pipes[CTOP][WR], STDOUT);
		execve(path, cmd_arg, NULL);
	}
	waitpid(CHILD, NULL, 0);
	return ;
}
