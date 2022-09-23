/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <ktang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:03:48 by ktang             #+#    #+#             */
/*   Updated: 2022/07/18 17:16:27 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_num(size_t n)
{
	if (n > 9)
	{
		ft_put_num(n / 10);
		ft_put_num(n % 10);
	}
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
}

int	ft_num_print(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		count++;
	}
	ft_put_num(n);
	count += ft_num_count(n, 10);
	return (count);
}
