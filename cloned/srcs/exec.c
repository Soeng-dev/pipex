/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:56:55 by soekim            #+#    #+#             */
/*   Updated: 2021/07/01 20:42:23 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exec.h"

void	init_pipe(int (*pipes)[2])
{
	if (pipe(pipes[PTOC]) < 0)
		perror_exit("Error : pipe");
	if (pipe(pipes[CTOP]) < 0)
		perror_exit("Error : pipe");
	return ;
}

void	exec_arg(t_arg *arg, char **envp, t_inout *inout)
{
	int		i;
	int		cmd_num;
	int		pipes[2][2];

	if (arg->cnt == 3 || arg->cnt == 4)
		cmd_num = arg->cnt - 2;
	else if (arg->cnt >= 5)
		cmd_num = arg->cnt - 3;
	else
		return ;
	printf("cmd num : %d\n", cmd_num);
	init_pipe(pipes);
	transfer_data(inout->in.fd, pipes[PTOC][WR]);
	i = 0;
	while (1)
	{
		ft_putstr_fd("while\n",1);
		exec_cmd(arg->vec[i + 2], envp, pipes[i]);
		if (i > cmd_num - 1)
			break ;
		dup2(pipes[CTOP][RD], pipes[PTOC][WR]);
		++i;
	}
	ft_putstr_fd("executed\n",1);
	transfer_data(pipes[i][CTOP][RD], inout->out.fd);
	return ;
}

void	exec_cmd(char *cmd, char **envp, int **pipes)
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
		cmd_arg = (char **)malloc(2 * sizeof(char *));
		cmd_arg[0] = ft_strdup(cmd);
		cmd_arg[1] = NULL;
		dup2(pipes[PTOC][RD], STDIN);
		dup2(pipes[CTOP][WR], STDOUT);
		execve(path, cmd_arg, NULL);
		exit(0);
	}
	else
	{
		close(pipes[PTOC][RD]);
		close(pipes[CTOP][WR]);
		waitpid(CHILD, NULL, 0);
	}
	return ;
}
