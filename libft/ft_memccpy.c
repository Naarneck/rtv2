/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:20:32 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/07 16:20:34 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tempsrc;
	unsigned char	*tempdest;

	tempsrc = (unsigned char *)src;
	tempdest = (unsigned char *)dst;
	while (n > 0)
	{
		if ((*tempdest++ = *tempsrc++) == (unsigned char)c)
			return ((void *)tempdest);
		n--;
	}
	return (NULL);
}
