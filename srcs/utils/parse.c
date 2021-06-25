/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adhoc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 22:37:02 by soekim            #+#    #+#             */
/*   Updated: 2021/06/22 16:15:25 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

int		is_correct_path(char *path, char *cmd)
{
}

char	*find_cmdpath(char *cmd, char **envp)
{
	char	**path_list;
	char	**to_free;
	char	*path;

	while (*envp)
	{
		if (!strdelcpy("PATH", *envp, '='))
			break;
	}
	path_list = ft_split(*envp + 5, ':');
	to_free = path_list;
	while (path_list)
	{
		if (is_correct_path(*path_list, cmd))
			path = *path_list;
		++path_list;
	}
	path = ft_strdup(iter);
	free_double(to_free);
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
