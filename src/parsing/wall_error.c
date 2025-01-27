/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:54:14 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 12:07:48 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

bool	check_line(char **line, int y, int x, int size_y)
{
	if ((y == 0 || y == size_y - 1 || line[y] == NULL) && !check_str(line[y],
			"1 \n"))
		return (false);
	if (y > 0 && y < size_y - 1)
	{
		if ((line[y][0] != '1' && line[y][0] != ' ')
			|| (line[y][ft_strlen(line[y]) - 2] != '1'
				&& line[y][ft_strlen(line[y]) - 2] != ' '))
			return (false);
		if (line[y + 1][x] != '1' && line[y + 1][x] != ' ')
			return (false);
		while (line[y][x] != '\n')
			if (!is_valid_char(line[y][x++], "10NSEW "))
				return (false);
	}
	return (true);
}

bool	correct_line(t_map *map, int y, int x)
{
	int	i;

	while (y < map->height_map && map->map_tab[y][x])
	{
		if (!check_line(map->map_tab, y, 0, map->height_map))
			return (false);
		y++;
	}
	return (true);
}

bool	ft_wall_error(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!correct_line(map, y, x))
		return (false);
	return (true);
}
