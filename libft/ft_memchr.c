/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:20:06 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/07 16:20:08 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp;
	size_t	i;
	char	sy;

	i = 0;
	temp = (char *)s;
	sy = (char)c;
	while (n > 0)
	{
		if (temp[i] == sy)
			return ((char *)s + i);
		i++;
		n--;
	}
	return (NULL);
}
