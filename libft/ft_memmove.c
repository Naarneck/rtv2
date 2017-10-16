/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:51:03 by izelensk          #+#    #+#             */
/*   Updated: 2016/11/28 20:51:05 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tempdest;
	unsigned const char	*tempsrc;
	size_t				templen;

	tempdest = (unsigned char *)dst;
	tempsrc = (unsigned const char *)src;
	if (tempsrc > tempdest)
	{
		templen = 0;
		while (templen != len)
		{
			tempdest[templen] = tempsrc[templen];
			templen++;
		}
	}
	else
	{
		templen = len;
		while (templen > 0)
		{
			tempdest[templen - 1] = tempsrc[templen - 1];
			templen--;
		}
	}
	return (void *)(dst);
}
