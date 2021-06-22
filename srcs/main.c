/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:21:29 by soekim            #+#    #+#             */
/*   Updated: 2021/06/22 16:41:01 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CHILD	0

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#include "../libft/libft.h"
#include "../vars.h"

int		main(int argc, char **argv, char **envp)
{
	t_arg	arg;
	t_inout	inout;

	if (argc <= 2)
		return (0)
	arg.cnt = argc;
	arg.vec = argv;
	
	init_inout(&inout, &arg);

	pipex(&arg, envp, &inout);

	//redirection result of pipex and exec_cmd to the out.fd
	close(inout.out.fd);
	return (0);
}
