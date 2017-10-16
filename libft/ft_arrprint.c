/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:06:18 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/14 15:06:20 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arrprint(char **arr, size_t rows, size_t cols)
{
	size_t	j;
	size_t	i;

	j = 0;
	while (j < rows)
	{
		i = 0;
		while (i < cols)
		{
			write(1, &arr[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}
