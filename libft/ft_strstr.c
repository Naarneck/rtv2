/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:49:28 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/01 14:49:29 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *res;
	const char *lit;
	const char *bg;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		res = big;
		bg = big;
		lit = little;
		while (*bg == *lit && *bg && *lit)
		{
			bg++;
			lit++;
		}
		if (!*lit)
			return ((char *)res);
		big++;
	}
	return (0);
}
