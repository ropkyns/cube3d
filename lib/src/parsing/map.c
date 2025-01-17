/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:42 by romain            #+#    #+#             */
/*   Updated: 2025/01/17 10:09:03 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	start_player_pos(t_map *map, char direction, int i, int j)
{
	map->player_x = j;
	map->player_y = i;
	map->player_direction = direction;
	if (direction == 'N')
	{
		map->player_direction_x = 0;
		map->player_direction_y = -1;
	}
	else if (direction == 'S')
	{
		map->player_direction_x = 0;
		map->player_direction_y = 1;
	}
	else if (direction == 'W')
	{
		map->player_direction_x = -1;
		map->player_direction_y = 0;
	}
	else if (direction == 'E')
	{
		map->player_direction_x = 1;
		map->player_direction_y = 0;
	}
}

void	map_size(t_map *map, char **array, int i, int j)
{
	int	tmp;
	int	nbr_player;

	tmp = 0;
	nbr_player = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (is_valid_char(array[i][j], "NSEW"))
			{
				nbr_player += 1;
				start_player_pos(map, array[i][j], i, j);
			}
			j++;
		}
		if (j > tmp)
			tmp = j;
		i++;
	}
	if (nbr_player != 1)
		return ;
	map->column_map = tmp;
	map->line_map = i;
}
