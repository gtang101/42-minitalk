/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:56:40 by ktang             #+#    #+#             */
/*   Updated: 2022/02/26 12:23:09 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n > 0
		&& ((unsigned char)s2[i] != '\0' || (unsigned char)s1[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			n--;
			i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char			str1[] = "Hello";
	char			str2[] = "Hello There";
	unsigned int	i = 8;	

	printf("i =  %d\n", i);
	printf("strncmp: %d\n", strncmp(str1, str2, i));
	printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, i));
	printf("strncmp: %d\n", strncmp(str2, str1, i));
	printf("ft_strncmp: %d\n", ft_strncmp(str2, str1, i));
}*/
