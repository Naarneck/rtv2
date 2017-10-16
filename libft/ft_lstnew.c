/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:34:27 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/07 17:34:29 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*test;

	test = (t_list*)malloc(sizeof(t_list));
	if (!test)
		return (NULL);
	if (!content)
	{
		test->content = NULL;
		test->content_size = 0;
		return (test);
	}
	test->content = malloc(sizeof(content));
	ft_memcpy(test->content, content, content_size);
	test->content_size = content_size;
	test->next = NULL;
	return (test);
}
