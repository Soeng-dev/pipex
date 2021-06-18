/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:44:51 by soekim            #+#    #+#             */
/*   Updated: 2021/06/18 22:57:39 by soekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*join;

	if (!(join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return ((void *)0);
	ret = join;
	if (s1)
	{
		while (*s1)
		{
			*join = *s1;
			join++;
			s1++;
		}
	}
	if (s2)
	{
		while (*s2)
		{
			*join = *s2;
			join++;
			s2++;
		}
	}
	*join = '\0';
	return (ret);
}
