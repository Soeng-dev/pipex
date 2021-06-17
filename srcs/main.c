/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:21:29 by soekim            #+#    #+#             */
/*   Updated: 2021/06/17 21:44:03 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fchtl.h>

#include "../vars.h"

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

void	exec_cmd(t_arg *arg, int in_fd)
{
	
int		main(int argc, char **argv)
{
	int		input;
	int		output;
	t_arg	arg;

	if (argc <= 2)
		return (0);
	arg.cnt = argc;
	arg.vec = argv;
	input = open_file(argv[1], O_RDONLY);
	return (0);
}
