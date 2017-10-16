/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrprint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:06:27 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/14 15:06:32 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arrprint_fd(char **arr, size_t rows, size_t cols, int fd)
{
	size_t	j;
	size_t	i;

	j = 0;
	while (j < rows)
	{
		i = 0;
		while (i < cols)
		{
			write(fd, &arr[j][i], 1);
			i++;
		}
		write(fd, "\n", 1);
		j++;
	}
}
