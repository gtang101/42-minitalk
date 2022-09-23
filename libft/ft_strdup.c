/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:06:15 by ktang             #+#    #+#             */
/*   Updated: 2022/02/26 17:42:17 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		len;

	len = ft_strlen(s1) + 1;
	dst = (char *)malloc(sizeof(char) * len);
	if (dst == 0)
		return (0);
	ft_memcpy(dst, s1, len);
	return (dst);
}
