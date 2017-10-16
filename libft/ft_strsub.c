/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:17:17 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/05 16:17:18 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (s)
	{
		str = ft_strnew(len);
		if (!str)
			return (NULL);
		while (len > 0)
		{
			str[i] = s[start];
			start++;
			i++;
			len--;
		}
		return (str);
	}
	return (NULL);
}
