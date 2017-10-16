/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:56:17 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/06 14:56:18 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		end_index(char const *s, size_t i, char c)
{
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		if (s[i + 1] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

static size_t		count_words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c) || (i == 0 && s[i] != c))
			j++;
		i++;
	}
	return (j);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char*) * count_words(s, c) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (!(str[j] = ft_strsub(s, i, end_index(s, i, c) - i)))
				return (NULL);
			i = end_index(s, i, c);
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
	str[j] = NULL;
	return (str);
}
