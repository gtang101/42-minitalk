/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:39:40 by ktang             #+#    #+#             */
/*   Updated: 2022/03/08 20:29:00 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*hold;

	if (lst)
	{
		while (*lst)
		{
			hold = (*lst)-> next;
			ft_lstdelone(*lst, del);
			*lst = hold;
		}
	}
}
