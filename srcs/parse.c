/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 22:37:02 by soekim            #+#    #+#             */
/*   Updated: 2021/07/09 16:16:43 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void	ls_grep_sh(char *path, char *cmd)
{
	char	*arg[4];
	int		pid;

	pid = fork();
	if (pid == CHILD)
	{
		arg[0] = "./ls_grep.sh";
		arg[1] = path;
		arg[2] = cmd;
		arg[3] = NULL;
		execve("ls_grep.sh", arg, NULL);
	}
	waitpid(CHILD, NULL, 0);
	return ;
}

int		is_correct_path(char *path, char *cmd)
{
	int		gnl_result;
	char	*grepped;
	int		fd;

	ls_grep_sh(path, cmd);
	fd = open("./grepped", O_RDONLY);
	gnl_result = SUCCESS;
	while (gnl_result == SUCCESS)
	{
		gnl_result = get_next_line(fd, &grepped);
		if (!ft_strcmp(grepped, cmd))
		{
			free(grepped);
			close(fd);
			return (TRUE);
		}
		free(grepped);
	}
	close(fd);
	return (FALSE);
}

char	**get_path_list(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!strdelcpy("PATH", envp[i], '='))
			break ;
		++i;
	}
	return (ft_split(envp[i] + 5, ':'));
}

char	*find_cmdpath(char *cmd, char **envp)
{
	char	**path_list;
	char	**to_free;
	char	**to_find;
	char	*to_cat;
	char	*path;

	if (!ft_strncmp(cmd, "./", 2) || !ft_strncmp(cmd, "../", 3))
		return (*ft_split(cmd, ' '));
	to_find = ft_split(cmd, ' ');
	path_list = get_path_list(envp);
	to_free = path_list;
	while (*path_list)
	{
		if (is_correct_path(*path_list, *to_find))
			break ;
		++path_list;
	}
	if (!(*path_list))
		cmd_not_found(*to_find);
	to_cat = ft_strjoin("/", *to_find);
	path = ft_strjoin(*path_list, to_cat);
	free(to_cat);
	free_char_ptr2d(to_find);
	free_char_ptr2d(to_free);
	return (path);
}
