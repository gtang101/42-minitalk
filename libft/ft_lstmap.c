/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:51:31 by ktang             #+#    #+#             */
/*   Updated: 2022/03/08 20:47:27 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*element;

	newlst = NULL;
	if (!lst)
		return (0);
	while (lst)
	{
		element = ft_lstnew((*f)(lst -> content));
		if (!element)
			ft_lstclear(&element, *del);
		else
			ft_lstadd_back(&newlst, element);
		lst = lst -> next;
	}
	return (newlst);
}
