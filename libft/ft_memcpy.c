/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:03:06 by izelensk          #+#    #+#             */
/*   Updated: 2016/11/28 19:03:08 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*tempdst;
	char			*tempsrc;

	tempdst = (char *)dst;
	tempsrc = (char *)src;
	while (n > 0)
	{
		*tempdst++ = *tempsrc++;
		n--;
	}
	return (dst);
}
