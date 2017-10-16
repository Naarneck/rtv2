/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:48:12 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/05 17:48:14 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_index(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (i);
		i++;
	}
	return (i);
}

static int	end_index(char const *s)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (i + 1);
		i--;
	}
	return (ft_strlen(s));
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = start_index(s);
	end = end_index(s);
	str = ft_strsub(s, start, end - start);
	if (!str)
		return (NULL);
	return (str);
}
