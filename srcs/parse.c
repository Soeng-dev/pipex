/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 22:37:02 by soekim            #+#    #+#             */
/*   Updated: 2021/06/28 17:47:55 by soekim           ###   ########.fr       */
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
		for (int i = 0; i < 3; ++i)
			ft_putendl_fd(arg[i], 1);
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
	char	*path;

	while (*envp)
	{
		if (!strdelcpy("PATH", *envp, '='))
			break;
		++envp;
	}
	path_list = ft_split(*envp + 5, ':');
	to_free = path_list;
	while (path_list)
	{
		ft_putstr_fd("bf check\n", 1);
		if (is_correct_path(*path_list, cmd))
			path = *path_list;
		ft_putstr_fd("aft check\n", 1);
		++path_list;
	}


	path = ft_strdup(*path_list);
	free_char_ptr2d(to_free);
	return (path);
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
