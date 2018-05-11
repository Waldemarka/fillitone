/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 16:13:17 by vomelchu          #+#    #+#             */
/*   Updated: 2018/05/11 15:50:56 by vomelchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

size_t	ft_strlen(const char *str)
{
	size_t q;

	q = -1;
	while (str[++q])
		;
	return (q);
}

int		checkmulti(char *str)
{
	int q;
	int count;

	q = 0;
	count = 0;
	while (str[q])
	{
		if (count == 4 && str[q] == '\n')
		{
			q++;
			count = 0;
		}
		if (str[q] == '\n')
			count++;
		if (count == 4 && str[q + 1] != '\n' && str[q + 1] != '\0')
			ft_error();
		q++;
	}
	if (str[q - 1] == '\n' && (str[q - 2] == '.' | str[q - 2] == '#'))
		return (1);
	else
		ft_error();
	return (1);
}

int		forsquare(char **str, int first)
{
	int sec;
	int count;

	count = 0;
	while (str[first])
	{
		sec = 0;
		while (str[first][sec])
		{
			if (str[first][sec] == '#')
			{
				if (str[first][sec + 1] == '#' && str[first + 1][sec] == '#'
					&& str[first + 1][sec + 1] == '#')
					return (1);
				else
					ft_error();
			}
			sec++;
		}
		first++;
	}
	return (0);
}

int		rightfigure(char **str)
{
	int first;
	int second;
	int count;

	first = -1;
	count = 0;
	while (str[++first])
	{
		second = -1;
		while (str[first][++second])
			if (str[first][second] == '#')
				count = ft_conect(str, second, first, count);
		if ((first + 1) % 4 == 0)
		{
			if ((count == 8 && forsquare(str, first - 3) == 1) || count == 6)
				count = 0;
			else
				ft_error();
		}
	}
	return (1);
}
