/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 22:37:02 by soekim            #+#    #+#             */
/*   Updated: 2021/06/30 14:27:52 by soekim           ###   ########.fr       */
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
		exit(0);
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
	//test here
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

char	*find_cmdpath(char *cmd, char **envp)
{
	char	**path_list;
	char	**to_free;
	char	**to_find;
	char	*path;
	char	*to_cat;

	while (*envp)
	{
		if (!strdelcpy("PATH", *envp, '='))
			break;
		++envp;
	}
	path_list = ft_split(*envp + 5, ':');
	to_find = ft_split(cmd, ' ');
	to_free = path_list;
	to_cat = ft_strjoin("/", *ft_split(cmd, ' '));
	while (*path_list)
	{
		if (is_correct_path(*path_list, *to_find))
			path = ft_strjoin(*path_list, to_cat);
		++path_list;
	}
	free_char_ptr2d(to_find);
	free_char_ptr2d(to_free);
	free(to_cat);
	return (path);
}

char	**read_cmd_arg(int fd)
{
	char	buf[256];
	char	**cmd_arg;
	char	*joined;
	int		rdlen;

	buf[255] = 0;
	rdlen = 1;
	joined = NULL;
	while (rdlen > 0)
	{
		rdlen = read(fd, buf, 255);
		buf[rdlen] = 0;
		joined = ft_strjoin(joined, buf);
	}
	cmd_arg = ft_split(joined, '\n');
	free(joined);
	
	return (cmd_arg);
}
