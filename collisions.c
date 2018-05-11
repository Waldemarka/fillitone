/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhromads <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:14:48 by dhromads          #+#    #+#             */
/*   Updated: 2018/05/11 14:14:50 by dhromads         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		wall_col_check(t_map *map, t_figur *tetr, int x, int y)
{
	if (tetr->row <= map->size - y && tetr->col <= map->size - x)
		return (0);
	return (1);
}

int		collision_check(t_map *map, t_figur *tetr, int x, int y)
{
	int j;
	int k;

	j = 0;
	while (j < tetr->row)
	{
		k = 0;
		while (k < tetr->col)
		{
			if (tetr->type[j][k] != '.' && map->field[y + j][x + k] != '.')
				return (1);
			k++;
		}
		j++;
	}
	fseter(map, tetr, x, y);
	return (0);
}

int		col_check(t_map *map, t_figur *tetri, int x, int y)
{
	if (!wall_col_check(map, tetri, x, y))
	{
		if (!collision_check(map, tetri, x, y))
			return (1);
	}
	return (0);
}
