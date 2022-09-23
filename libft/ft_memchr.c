/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:05:56 by ktang             #+#    #+#             */
/*   Updated: 2022/03/01 19:41:58 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	a;

	str = (unsigned char *)s;
	a = (unsigned char)c;
	while (n != '\0')
	{
		if (*str == a)
			return (str);
		str++;
		n--;
	}
	return (0);
}
