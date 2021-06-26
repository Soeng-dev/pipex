/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:02:56 by soekim            #+#    #+#             */
/*   Updated: 2021/06/26 20:03:59 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	free_char_ptrarr(char **ptrarr)
{
	while (*ptrarr)
	{
		free(*ptrarr);
		++ptrarr;
	}
	return ;
}

void	free_char_ptr2d(char **ptr2d)
{
	free_char_ptrarr(ptr2d);
	free(ptr2d);
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
