/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transpose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:47:13 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/14 13:47:15 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_transpose(char **arr, size_t rows, size_t cols)
{
	char	**newarr;
	size_t	i;
	size_t	j;
	size_t	temp;

	if (cols > rows)
		temp = cols;
	else
		temp = rows;
	newarr = ft_arralloc(temp, temp);
	j = 0;
	while (j < temp)
	{
		i = 0;
		while (i < temp)
		{
			if (i < cols)
				newarr[j][i] = arr[i][j];
			i++;
		}
		newarr[j][i] = '\0';
		j++;
	}
	return (newarr);
}
