/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:38:37 by ktang             #+#    #+#             */
/*   Updated: 2022/03/01 20:01:56 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	a;
	unsigned int	len;

	len = num_count(n);
	str = malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		a = -n;
	}
	else
		a = n;
	if (a == 0)
		str[0] = '0';
	str[len] = '\0';
	while (a != 0)
	{
		str[len - 1] = (a % 10) + '0';
		a = a / 10;
		len--;
	}
	return (str);
}
