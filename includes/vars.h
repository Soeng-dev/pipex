/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:37:46 by soekim            #+#    #+#             */
/*   Updated: 2021/06/22 17:25:00 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# define RD		0
# define WR		1

# define STDOUT	1

struct	s_arg
{
	int		cnt;
	char	**vec;
};
typedef struct	s_arg	t_arg;

struct	s_file
{
	int		fd;
	int		o_flag;
};
typedef struct	s_file	t_file;

struct	s_inout
{
	t_file	in;
	t_file	out;
};
typedef struct s_inout	t_inout;

#endif
