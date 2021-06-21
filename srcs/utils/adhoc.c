/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adhoc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 22:37:02 by soekim            #+#    #+#             */
/*   Updated: 2021/06/21 23:39:02 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int		target_in_path(char *target, char *path)
{
	int		pid;
	int		data[2][2];
	char	*ls_arg[3];

	init_pipe(data);
	ls_arg[0] = ft_strdup("ls");
	ls_arg[1] = path;
	ls_arg[2] = NULL;
	exec_ls(ls_arg, data);
	data[P_TO_C][SEND] = data[C_TO_P][SEND];
	
}
char	*find_cmdpath(char *cmd, char **envp)
{
	char	**path_list;
	char	**iter;
	char	*path;

	while (*envp)
	{
		if (!strdelcpy("PATH", *envp, '='))
			break;
	}
	path_list = ft_split(*envp + 5, ':');
	iter = path_list;
	while (iter)
	{
		
		++iter;
	}
	path = ft_strdup(iter);
	free_double(path_list);
	
}

char	**read_cmd_arg(int fd)
{
	char	*new;
	char	*old;
	char	*input;
	char	**cmd_arg;

	while (1)
	{
		new = NULL;
		if (get_next_line(fd, &new) == END)
			break;
		input = ft_strjoin(input, new);
		old = input;
		free(old);
		free(new);
	}
	cmd_arg = ft_split(input, ' ');
	return (cmd_arg);
}
