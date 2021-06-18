/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adhoc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 22:37:02 by soekim            #+#    #+#             */
/*   Updated: 2021/06/18 23:08:46 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*find_path(char *cmd, char **envp)
{
	char	*path;

	while (*envp)
	{
		if (!strdelcpy("PATH", *envp, '='))
			break;
	}
	//undone
}

char	**read_cmd_arg(int fd)
{
	int		result;
	char	*new;
	char	*old;
	char	*input;
	char	**cmd_arg;

	while (1)
	{
		new = NULL;
		result = get_next_line(fd, &new);
		if (result == END)
			break;
		input = ft_strjoin(input, new);
		old = input;
		free(old);
		free(new);
	}
	cmd_arg = ft_split(input, ' ');
	return (cmd_arg);
}
