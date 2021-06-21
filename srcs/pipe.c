/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 22:56:55 by soekim            #+#    #+#             */
/*   Updated: 2021/06/21 23:11:33 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

void	init_pipe(int **data)
{
	if (pipe(data[P_TO_C]) < 0)
		perror_exit("Error : pipe from parent to children");
	if (pipe(data[C_TO_P]) < 0)
		perror_exit("Error : pipe from children to parent");
	return ;
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
			perror_exit("Error : fork");
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
