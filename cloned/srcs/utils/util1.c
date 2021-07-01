/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:12:16 by soekim            #+#    #+#             */
/*   Updated: 2021/07/01 20:39:03 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int		strdelcpy(char *s1, char *s2, int del)
{
	while (*s1 && *s2 && *s1 != del && *s2 != del)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
	}
	if (*s1 == del || *s2 == del)
		return (0);
	else
		return (*s1 - *s2);
}

void	perror_exit(char *str)
{
	perror(str);
	exit(1);
}

int		open_file(char *name, int mode)
{
	int		fd;

	if (!name)
		return (-1);
	fd = open(name, mode);
	if (fd < 0)
		exit(0);
	return (fd);
}
//
//int		***get_pipes(int cmd_num)
//{
//	int		***pipes;
//	int		i;
//
//	pipes = (int ***)malloc((cmd_num + 1) * sizeof(int **));
//	pipes[cmd_num] = NULL;
//	i = -1;
//	ft_putstr_fd("hi\n",1);
//	while (++i < cmd_num)
//	{
//		pipes[i] = (int **)malloc(3 * sizeof(int *));
//		pipes[i][0] = (int *)malloc(2 * sizeof(int));
//		pipes[i][1] = (int *)malloc(2 * sizeof(int));
//		pipes[i][2] = NULL;
//		if (pipe(pipes[i][0]) < 0)
//			perror_exit("Error : pipe");
//		if (pipe(pipes[i][1]) < 0)
//			perror_exit("Error : pipe");
//		printf("\npipe%d		%d	%d\n", i, pipes[i][0][0], pipes[i][0][1]);
//		printf("\npipe%d		%d	%d\n", i, pipes[i][1][0], pipes[i][1][1]);
//	}
//	return (pipes);
//}
//
