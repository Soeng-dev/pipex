/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:12:16 by soekim            #+#    #+#             */
/*   Updated: 2021/06/26 20:12:34 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int		strdelcpy(char *s1, char *s2, int del)
{
	while (*s1 && *s2 && *s1 != del && *s2 != del)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
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

void	init_pipe(int *pipeline, int input_fd)
{

	if (pipe(pipeline) < 0)
		perror_exit("Error : pipe");
	if (input_fd >= 0)
		transfer_data(input_fd, pipeline[WR]);
	return ;
}
