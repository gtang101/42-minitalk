/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <ktang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:40:37 by ktang             #+#    #+#             */
/*   Updated: 2022/07/18 17:16:27 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_type(const char c, va_list arg, int *i)
{
	if (c == 'c')
		return (ft_char_print(va_arg(arg, int)));
	if (c == 's')
		return (ft_str_print(va_arg(arg, char *)));
	if (c == 'i' || c == 'd')
		return (ft_num_print(va_arg(arg, int)));
	if (c == 'u')
		return (ft_num_print(va_arg(arg, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(arg, unsigned int), c));
	if (c == 'p')
		return (ft_print_hex(va_arg(arg, unsigned long), c));
	if (c == '%')
		return (ft_char_print(c));
	if (!c)
		return (0);
	else
		*i = *i - 1;
	return (0);
}
