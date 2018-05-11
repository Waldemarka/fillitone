/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhromads <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:59:58 by dhromads          #+#    #+#             */
/*   Updated: 2018/05/11 14:01:42 by dhromads         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fseter(t_map *map, t_figur *tetr, int x, int y)
{
	int j;
	int k;

	j = 0;
	while (j < tetr->row)
	{
		k = 0;
		while (k < tetr->col)
		{
			if (tetr->type[j][k] != '.')
				map->field[y + j][x + k] = tetr->type[j][k];
			k++;
		}
		j++;
	}
	return (1);
}

int		fclener(t_map *map, t_figur *tetr, int x, int y)
{
	int j;
	int k;

	j = 0;
	while (j < tetr->row)
	{
		k = 0;
		while (k < tetr->col)
		{
			if (tetr->type[j][k] != '.')
				map->field[y + j][x + k] = '.';
			k++;
		}
		j++;
	}
	return (1);
}

int		map_solver(t_map *map, t_figur *list)
{
	int x;
	int y;

	y = 0;
	if (list == NULL)
		return (1);
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (col_check(map, list, x, y))
			{
				if (!map_solver(map, list->next))
					fclener(map, list, x, y);
				else
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	solve(t_figur *list)
{
	t_map	*map;
	int		size;

	size = get_min_squre(list);
	map = new_map(size);
	while (!map_solver(map, list))
	{
		map->size++;
		map = new_map(map->size);
	}
	print_map(map);
	free(map);
}
