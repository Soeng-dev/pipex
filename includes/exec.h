/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:45:13 by soekim            #+#    #+#             */
/*   Updated: 2021/07/01 22:53:21 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <unistd.h>

# include "vars.h"
# include "utils.h"
# include "parse.h"

void	exec_arg(t_arg *arg, char **envp, t_inout *inout);
void	exec_cmd(char *cmd, char **envp, int (*pipes)[2]);

#endif
