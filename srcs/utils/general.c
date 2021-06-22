/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:12:16 by soekim            #+#    #+#             */
/*   Updated: 2021/06/22 17:51:26 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int		strdelcpy(char *s1, char *s2, int del)
{
	while (*s1 && *s2 && *s1 != del, *s2 != del)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (*s1 == del || *s2 == del)
		return (0);
	else
		return (*s1 - *s2);
}

int		open_file(char *name, int mode)
{
	int		fd;

	if (!name)
		return (-1);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		exit(0);
	return (fd);
}

void	free_double(char **ptr)
{
	char	**iter;

	iter = ptr;
	while (iter)
	{
		if (*iter)
			free(*iter);
		++iter;
	}
	free(ptr);
	return ;
}

void	transfer_data(int fd_src, int fd_target)
{
	char	line[33];
	int		read_result;

	line[32] = 0;
	read_result = 1;
	while (read_result != 0)
	{
		read_result = read(fd_src, line, 32);
		ft_putstr_fd(line, fd_target);
	}
	return ;
}
