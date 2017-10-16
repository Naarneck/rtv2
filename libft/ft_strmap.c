/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:48:45 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/05 14:48:47 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	k;
	char	*str;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	while (s[i++] != '\0')
		if (f(s[i]))
			k++;
	str = ft_strnew(k);
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0')
		if (f(s[i]))
			str[k++] = f(s[i++]);
	return (str);
}
