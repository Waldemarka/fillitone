/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhromads <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:14:39 by dhromads          #+#    #+#             */
/*   Updated: 2018/05/11 14:14:41 by dhromads         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*new_map(int size)
{
	t_map	*map;
	int		i;
	int		k;

	map = (t_map *)malloc(sizeof(t_map));
	map->size = size;
	map->field = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		k = 0;
		map->field[i] = ft_strnew(size);
		while (k < size)
		{
			map->field[i][k] = '.';
			k++;
		}
		i++;
	}
	return (map);
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
		ft_putendl(map->field[i++]);
}

int		get_min_squre(t_figur *list)
{
	int		count;
	t_figur	*tmp;
	int		i;

	tmp = list;
	count = 0;
	i = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	while (i <= count)
	{
		if ((i * i) < (count * 4))
			i++;
		else
			break ;
	}
	return (i);
}
