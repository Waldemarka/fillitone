/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:57:48 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/06 17:59:55 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_strnewword(char const *stroka, int index, char c)
{
	char	*str;
	int		q;
	int		j;

	q = 0;
	j = index;
	while (stroka[j] != '\0' && stroka[j] != c)
		j++;
	if (!(str = (char *)malloc(sizeof(char) * j - index + 1)))
		return (NULL);
	q = 0;
	while (stroka[index] != '\0' && stroka[index] != c)
	{
		str[q] = stroka[index];
		q++;
		index++;
	}
	str[q] = '\0';
	return (str);
}

static char		*ft_sepereteword(char const *str, char c, int wor, int i)
{
	char	*res;
	int		q;

	q = 0;
	res = NULL;
	while (str[q] != '\0')
	{
		if (str[q] == c || (q == 0 && str[q] != c))
		{
			while (str[q] == c)
				q++;
			i++;
		}
		if (wor == i - 1)
		{
			while (str[q] == c)
				q++;
			res = ft_strnewword(str, q, c);
			return (res);
		}
		if (str[q] != c && str[q] != '\0')
			while (str[q] != c && str[q] != '\0')
				q++;
	}
	return (res);
}

static int		words(char const *str, char c)
{
	int q;
	int i;

	q = 0;
	i = 0;
	while (str[q] != '\0')
	{
		while (str[q] == c)
			q++;
		if (str[q] != c && str[q] != '\0')
		{
			while (str[q] != c && str[q] != '\0')
				q++;
			i++;
		}
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		q;
	int		slova;
	int		x;

	q = 0;
	if (!s || !c)
		return (NULL);
	slova = words(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * slova + 1)))
		return (NULL);
	while (q != slova)
	{
		x = 0;
		str[q] = ft_sepereteword(s, c, q, x);
		q++;
	}
	str[q] = NULL;
	return (str);
}
