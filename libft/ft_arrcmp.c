/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:42:56 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/14 14:42:57 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arrcmp(char **arr1, char **arr2)
{
	size_t	j;
	int		res;

	j = 0;
	res = 0;
	while (arr1[j] || arr2[j])
	{
		res = ft_strcmp(arr1[j], arr2[j]);
		if (res != 0)
			return (res);
		j++;
		if (!arr1[j] || !arr2[j])
			return (res);
	}
	return (res);
}
