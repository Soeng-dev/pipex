/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 22:37:02 by soekim            #+#    #+#             */
/*   Updated: 2021/06/26 20:48:40 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void	ls_grep_sh(char *path, char *cmd, int *pipeline)
{
	char	*arg[4];

	arg[0] = "./ls_grep.sh";
	arg[1] = path;
	arg[2] = cmd;
	arg[3] = NULL;
	dup2(pipeline[WR], STDOUT);
	execve("ls_grep.sh", arg, NULL);
	return ;
}

int		is_correct_path(char *path, char *cmd)
{
	int		pipeline[2];
	int		pid;
	int		gnl_result;
	char	*grepped;

	init_pipe(pipeline, -1);
	write(pipeline[WR], cmd, ft_strlen(cmd));
	pid = fork();
	if (pid == CHILD)
	{
		ls_grep_sh(path, cmd, pipeline);
		exit (0);
	}
	waitpid(CHILD, NULL, 0);
	gnl_result = SUCCESS;
	while (gnl_result != END || gnl_result != ERROR)
	{
	//test here
		gnl_result = get_next_line(pipeline[RD], &grepped);
		if (!ft_strcmp(grepped, cmd))
		{
			free(grepped);
			return (TRUE);
		}
		free(grepped);
	}
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
		if (is_correct_path(*path_list, cmd))
			path = *path_list;
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
