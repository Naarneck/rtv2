/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izelensk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:41:19 by izelensk          #+#    #+#             */
/*   Updated: 2016/12/08 17:41:20 by izelensk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*fres;

	if (!lst || !(*f))
		return (NULL);
	temp = NULL;
	fres = f(lst);
	temp = fres;
	while (lst->next)
	{
		fres->next = f(lst->next);
		fres = fres->next;
		lst = lst->next;
	}
	return (temp);
}
