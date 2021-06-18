/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:43:55 by soekim            #+#    #+#             */
/*   Updated: 2021/06/18 23:08:51 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../../libft/libft.h"
# include "get_next_line.h"

/*
**		general
*/
int		strdelcpy(char *s1, char *s2, int del);
int		open_file(char *name, int mode);

/*
**		adhoc
*/
char	*find_path(char *cmd, char **envp);
char	**read_input(int fd);
#endif
