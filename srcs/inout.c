/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inout.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:08:24 by soekim            #+#    #+#             */
/*   Updated: 2021/06/29 16:29:01 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/inout.h"

void	init_inout(t_inout *inout, t_arg *arg)
{
	ft_memset(inout, sizeof(t_inout), 0);
	inout->in.o_flag = O_RDONLY;
	inout->in.fd = open_file(arg->vec[1], inout->in.o_flag);
	if (!ft_strcmp(arg->vec[1], "here_doc"))
		inout->out.o_flag = O_RDWR;
	else
		inout->out.o_flag = O_RDWR | O_CREAT | O_TRUNC;
	if (arg->cnt > 4)	
		inout->out.fd = open_file(arg->vec[arg->cnt - 1], inout->out.o_flag);
	if (inout->out.o_flag == O_RDWR)
	{
	//when bonus, move filepointer to the last line use while loop and read(SIZE_MAX)
	}
	return ;
}
