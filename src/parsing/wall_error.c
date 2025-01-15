/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:54:14 by romain            #+#    #+#             */
/*   Updated: 2025/01/15 12:35:28 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

bool	check_column(char **column, int y, int x, int size_y)
{
	while (y < size_y)
	{
		if (y == 0 && !is_valid_char(column[y][x], "1 "))
			return (false);
		if (!is_valid_char(column[y][x], "10NSEW"))
			return (print_error("INVALID_CHARACTER"), 1);
		if (is_space(column[y][x]) == true)
		{
			if (y > 0 && column[y - 1][x] != '1')
				return (false);
			while (y < size_y && column[y][x] == ' ')
				y++;
			if (y < size_y && column[y][x] != '1')
				return (false);
		}
		if (y < size_y)
			y++;
	}
	if (!is_valid_char(column[y - 1][x], "1 "))
		return (false);
	return (true);
}

bool	vertical_check(t_map *map, int y, int x)
{
	while (map->map_tab[y][x])
	{
		if (!check_column(map->map_tab, y, x, map->column_map))
			return (false);
		x++;
	}
	return (true);
}

bool	check_line(t_map *map, char *line, int x)
{
	while (line[x])
	{
		if (x == 0 && !is_valid_char(line[x], "1 "))
			return (false);
		if (!is_valid_char(line[x], "10NSEW "))
			return (print_error("INVALID_CHARACTER"), 1);
		if (line[x] == ' ')
		{
			if (x > 0 && line[x - 1] != '1')
				return (false);
			while (line[x] && line[x] == ' ')
				x++;
			if (line[x] && line[x] != '1')
				return (false);
		}
		if (line[x])
			x++;
	}
	if (!is_valid_char(line[x - 1], "1 "))
		return (false);
	return (true);
}

bool	horizontal_check(t_map *map, int y, int x)
{
	while (map->map_tab[y])
	{
		if (!check_line(map, map->map_tab[y], x))
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
	if (!horizontal_check(map, y, x) || !vertical_check(map, y, x))
		return (false);
	return (true);
}
