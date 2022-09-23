/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:43:48 by ktang             #+#    #+#             */
/*   Updated: 2022/03/01 22:58:20 by ktang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freemem(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		free(str);
		i++;
	}
	free(str);
}

static int	ft_strcount(char *str, char a)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != a)
		{
			count++;
			while (str[i] != a && str[i] != '\0')
			{
				i++;
			}
			if (str[i] == '\0')
			{
				return (count);
			}
		}
		i++;
	}
	return (count);
}

static void	ft_strcpy(char *miniarr, char *str, char c, int b)
{
	int	i;

	i = 0;
	while (str[b] != '\0' && str[b] == c)
	{
		b++;
	}
	while (str[b + i] != c && str[b + i] != '\0')
	{
		miniarr[i] = str[b + i];
		i++;
	}
	miniarr[i] = '\0';
}

static char	*ft_stralloc(char *str, char c, int *a)
{
	char	*miniarr;
	int		b;

	b = *a;
	miniarr = NULL;
	while (str[*a] != '\0')
	{
		if (str[*a] != c)
		{
			while (str[*a] != '\0' && str[*a] != c)
			{
				*a += 1;
			}
			miniarr = malloc(sizeof(char) * (*a + 1));
			if (miniarr == NULL)
			{
				return (NULL);
			}
			break ;
		}
		*a += 1;
	}
	ft_strcpy(miniarr, str, c, b);
	return (miniarr);
}

char	**ft_split(char const *s, char c)
{
	char	**newstr;
	int		i;
	int		j;
	int		pos;

	if (s == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_strcount((char *)s, c);
	newstr = malloc(sizeof(char *) * (j + 1));
	if (newstr == 0)
		return (0);
	newstr[j] = NULL;
	while (i < j)
	{
		newstr[i] = ft_stralloc(((char *)s), c, &pos);
		if (newstr[i] == 0)
		{
			ft_freemem(newstr[i]);
		}
		i++;
	}
	return (newstr);
}
