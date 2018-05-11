/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openvalid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 16:09:57 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/06 16:09:58 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**fileopen(char *str)
{
	char	*array;
	int		handle;
	int		bytes;
	char	**res;

	res = NULL;
	array = malloc(2000);
	if ((handle = open(str, O_RDONLY)) == -1)
		ft_error();
	if ((bytes = read(handle, array, 2000)) == -1)
		ft_error();
	if (checkmulti(array) == 1)
		res = ft_strsplit(array, '\n');
	else
		ft_error();
	if (close(handle) < 0)
		ft_error();
	free(array);
	return (res);
}

int		checksize(char **str)
{
	int q;

	q = -1;
	while (str[++q] != '\0')
		if (ft_strlen(str[q]) != 4)
			ft_error();
	return (1);
}

int		checksizemap(char **str)
{
	int q;

	q = -1;
	while (str[++q])
		if (q > 104)
			ft_error();
	if (q % 4 != 0)
		ft_error();
	if (q < 1)
		ft_error();
	return (1);
}

int		checksymbol(char **str)
{
	int q;
	int i;

	q = 0;
	while (str[q])
	{
		i = 0;
		while (str[q][i])
		{
			if (str[q][i] != '#' && str[q][i] != '.')
				ft_error();
			i++;
		}
		q++;
	}
	return (1);
}

int		checkcountsymb(char **str)
{
	int q;
	int i;
	int count;

	q = 0;
	while (str[q])
	{
		if (q % 4 == 0)
			count = 0;
		i = 0;
		while (str[q][i])
		{
			if (str[q][i] == '#')
				count++;
			i++;
		}
		if ((q + 1) % 4 == 0 && count != 4)
			ft_error();
		q++;
	}
	return (1);
}
