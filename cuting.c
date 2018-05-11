/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuting.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 16:16:10 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/06 16:16:11 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		sizearray(char **str)
{
	int q;

	q = -1;
	while (str[++q])
		;
	return (q);
}

int		ft_numrow(char **split, int index)
{
	int q;
	int j;
	int count;

	q = 0;
	count = 0;
	while (q != 4)
	{
		j = 0;
		while (split[index][j])
		{
			if (split[index][j] == '#')
			{
				count++;
				break ;
			}
			j++;
		}
		index++;
		q++;
	}
	return (count);
}

int		ft_numcol(char **split, int index)
{
	int q;
	int j;
	int count;
	int dex;

	q = 0;
	j = 0;
	count = 0;
	dex = index;
	while (j != 4)
	{
		index = dex;
		while (index != dex + 4)
		{
			if (split[index][j] == '#')
			{
				count++;
				break ;
			}
			index++;
		}
		j++;
	}
	return (count);
}

char	*oneline(char **split, int first, int numcol, int numrow)
{
	char	*res;
	int		q;
	int		colindex;
	int		rowindex;

	q = 0;
	res = NULL;
	numrow = ft_numrow(split, first);
	numcol = ft_numcol(split, first);
	colindex = ft_colindex(split, first);
	rowindex = ft_rowindex(split, first);
	if (!(res = (char *)malloc(sizeof(char) * (numrow * numcol + numrow))))
		return (NULL);
	while (q != numrow)
	{
		res = ft_strjoin(res, ft_strsub(split[first + q + rowindex],
			colindex, numcol));
		res = ft_strjoin(res, "\n");
		q++;
	}
	res[numrow * numcol + numrow - 1] = '\0';
	return (res);
}

char	**cutfigure(char **split)
{
	int		q;
	int		size;
	int		numcol;
	int		numrow;
	char	**res;

	q = 0;
	size = sizearray(split) / 4;
	if (!(res = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	res[size] = 0;
	numcol = 0;
	numrow = 0;
	while (q != size)
	{
		res[q] = oneline(split, q * 4, numcol, numrow);
		q++;
	}
	return (res);
}
