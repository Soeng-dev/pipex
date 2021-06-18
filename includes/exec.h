/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:15:42 by soekim            #+#    #+#             */
/*   Updated: 2021/06/18 18:17:24 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "libft/libft.h"
# include "utils.h"

void	exec_cmd(char **envp);
void	pipex(t_arg *arg, int in_fd);

#endif
