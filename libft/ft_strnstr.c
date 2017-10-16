/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:33:03 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/01 16:33:05 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*res;
	const char	*lit;
	const char	*bg;
	size_t		i;

	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		i = len;
		res = big;
		bg = big;
		lit = little;
		while (*bg == *lit && i && *bg && *lit)
		{
			bg++;
			lit++;
			i--;
		}
		if (!*lit)
			return ((char *)res);
		big++;
		len--;
	}
	return (NULL);
}
