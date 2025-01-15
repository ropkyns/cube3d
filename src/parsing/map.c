/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:42 by romain            #+#    #+#             */
/*   Updated: 2025/01/15 14:24:14 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	start_player_pos(t_map *map, char direction, int i, int j)
{
	map->player_x = j;
	map->player_y = i;
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
