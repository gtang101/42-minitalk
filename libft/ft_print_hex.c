/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <ktang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:55:14 by ktang             #+#    #+#             */
/*   Updated: 2022/07/18 17:16:27 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned long n, char c)
{
	int	count;

	count = ft_num_count(n, 16);
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		count += 2;
		c = 'x';
	}
	if (n >= 16)
	{
		ft_print_hex(n / 16, c);
		ft_print_hex(n % 16, c);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + 48, 1);
		else if (c == 'x')
			ft_putchar_fd(n - 10 + 'a', 1);
		else
			ft_putchar_fd(n - 10 + 'A', 1);
	}
	return (count);
}
