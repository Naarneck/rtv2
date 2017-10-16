/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:26:39 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/07 16:21:15 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		digit_count(int n)
{
	int			i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long long	num;
	int			i;
	char		*str;

	num = n;
	i = digit_count(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		num = num * -1;
		str[0] = '-';
	}
	while (num >= 10)
	{
		str[i - 1] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	str[i - 1] = num + '0';
	return (str);
}
