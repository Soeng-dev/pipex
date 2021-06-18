/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_element.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:19:36 by soekim            #+#    #+#             */
/*   Updated: 2021/06/16 11:19:39 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_element(const char *set, char c)
{
	if (!set)
		return (-1);
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
