/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <ktang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:22:10 by ktang             #+#    #+#             */
/*   Updated: 2022/07/18 17:16:27 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[++i])
		{
			count += ft_char_type(str[i], arg, &i);
			i++;
		}
		if (str[i] && str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i++;
			count++;
		}
	}
	va_end(arg);
	return (count);
}
