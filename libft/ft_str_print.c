/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <ktang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:49:24 by ktang             #+#    #+#             */
/*   Updated: 2022/07/18 17:16:27 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_print(char *str)
{
	int		count;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (count);
}
