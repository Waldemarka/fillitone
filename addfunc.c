/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:30:38 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/06 19:30:40 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_colindex(char **split, int index)
{
	int q;
	int dex;
	int i;

	q = 0;
	i = 0;
	dex = index;
	while (i != 4)
	{
		index = dex;
		while (index != 4 + dex)
		{
			if (split[index][i] == '#')
				return (i);
			index++;
		}
		i++;
	}
	return (0);
}

int		ft_rowindex(char **split, int index)
{
	int dex;
	int i;

	dex = index;
	while (index != dex + 4)
	{
		i = 0;
		while (split[index][i])
		{
			if (split[index][i] == '#')
				return (index - dex);
			i++;
		}
		index++;
	}
	return (0);
}

void	changeline(char **str)
{
	int		q;
	int		i;
	char	letter;

	q = 0;
	letter = 'A';
	while (str[q])
	{
		i = 0;
		while (str[q][i])
		{
			if (str[q][i] == '#')
				str[q][i] = letter;
			i++;
		}
		letter++;
		q++;
	}
}

int		ft_conect(char **str, int second, int first, int count)
{
	if (second != 0 && str[first][second - 1] == '#')
		count++;
	if (second != 3 && str[first][second + 1] == '#')
		count++;
	if ((first % 4) != 0 && str[first - 1][second] == '#')
		count++;
	if (((first + 1) % 4 != 0) && str[first + 1][second] == '#')
		count++;
	return (count);
}

char	ret_sumbol(char **str)
{
	int		q;
	char	a;

	q = 0;
	a = 'A';
	while (str[q])
	{
		if (str[q + 1] != 0)
			a++;
		q++;
	}
	return (a);
}
