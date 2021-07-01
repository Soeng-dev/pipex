/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:56:55 by soekim            #+#    #+#             */
/*   Updated: 2021/06/30 17:40:47 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exec.h"

void	exec_arg(t_arg *arg, char **envp, t_inout *inout)
{
	int		pipes[2][2];
	int		i;
	int		last_cmd;

	init_pipe(pipes, inout->in.fd);
	i = 1;
	if (arg->cnt <= 4)
		last_cmd = arg->cnt;
	while (i < 
}

void	exec_cmd(char *cmd, char **envp, int (*pipes)[2])
{
	int		pid;
}
