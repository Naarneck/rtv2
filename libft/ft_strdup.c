/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:31:26 by izelensk          #+#    #+#             */
/*   Updated: 2016/11/29 16:31:29 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *str;

	str = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1);
	return (str);
}
