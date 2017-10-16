/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arralloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:43:36 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/12 18:43:37 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_arralloc(size_t rows, size_t cols)
{
	char	**arr;
	size_t	i;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * rows);
	if (!arr)
		return (NULL);
	while (i < cols)
	{
		arr[i] = (char *)malloc(sizeof(char) * cols);
		i++;
	}
	return (arr);
}
