/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:21:29 by soekim            #+#    #+#             */
/*   Updated: 2021/06/26 20:19:24 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int		main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	t_inout	inout;

	if (argc <= 2)
		return (0);
	arg.cnt = argc;
	arg.vec = argv;
	
	init_inout(&inout, &arg);
	
	ft_putstr_fd("inouted\n", 1);
	exec_arg(&arg, envp, &inout);

	//redirection result of pipex and exec_cmd to the out.fd
	close(inout.out.fd);
	return (0);
}
