/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:54:14 by romain            #+#    #+#             */
/*   Updated: 2025/02/18 19:22:50 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

// bool	check_line(char **line, int y, int x, int size_y)
// {
// 	if ((y == 0 || y == size_y - 1 || line[y] == NULL) && !check_str(line[y],
// 			"1 \n"))
// 		return (false);
// 	if (y > 0 && y < size_y - 1)
// 	{
// 		if ((line[y][0] != '1' && line[y][0] != ' ')
// 			|| (line[y][ft_strlen(line[y]) - 2] != '1'
// 				&& line[y][ft_strlen(line[y]) - 2] != ' '))
// 			return (false);
// 		if (line[y + 1][x] != '1' && line[y + 1][x] != ' ')
// 			return (false);
// 		while (line[y][x] != '\n')
// 			if (!is_valid_char(line[y][x++], "10NSEW "))
// 				return (false);
// 	}
// 	return (true);
// }

// bool	correct_line(t_global *global, int y, int x)
// {
// 	int	i;

// 	while (y < global->map->height_map && global->map->map_tab[y][x])
// 	{
// 		if (!check_line(global->map->map_tab, y, 0, global->map->height_map))
// 			return (false);
// 		y++;
// 	}
// 	return (true);
// }

// bool	ft_wall_error(t_global *global)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	x = 0;
// 	if (!correct_line(global, y, x))
// 		return (false);
// 	return (true);
// }

static char	**dup_map(t_map *map)
{
	char	**tmp_map;
	int		i;

	tmp_map = malloc((map->lenght_map + 1) * sizeof(char *));
	if (!tmp_map)
		return (NULL);
	i = -1;
	while (++i < map->lenght_map && map->map_tab[i])
	{
		tmp_map[i] = ft_strdup(map->map_tab[i]);
		if (!tmp_map)
		{
			free_tab(tmp_map);
			return (NULL);
		}
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}

static void	fill(t_map *map, char **tmp_map, int y, int x)
{
	if (y >= 0 && y < map->height_map && x >= 0 && x < map->lenght_map && tmp_map[y][x] == '0')
		map->ff = 1;
	if (y < 0 || y >= map->height_map || x < 0 || x >= map->lenght_map
		|| (tmp_map[y][x] == '1' || tmp_map[y][x] == '0' || tmp_map[y][x] == 'x'))
		return ;
	tmp_map[y][x] = 'x';
	fill(map, tmp_map, (y + 1), x);
	fill(map, tmp_map, (y - 1), x);
	fill(map, tmp_map, y, (x + 1));
	fill(map, tmp_map, y, (x - 1));
}

// bool	check_fill(t_global *global, char **tmp_map)
// {
// 	int	x;
// 	int	y;

// 	y = global->line;
// 	while (y--)
// 	{
// 		x = global->column;
// 		while (x--)
// 		{
// 			if (tmp_map[y][x] == 'E' && (tmp_map[y + 1][x] != 'x'
// 				&& tmp_map[y - 1][x] != 'x' && tmp_map[y][x + 1] != 'x'
// 				&& tmp_map[y][x - 1] != 'x'))
// 				return (false);
// 		}
// 	}
// 	return (true);
// }

bool	flood_fill(t_map *map, int y, int x)
{
	char	**tmp_map;

	tmp_map = dup_map(map);
	if (!tmp_map)
		return (false);
	fill(map, tmp_map, y, x);
	// if (!check_fill(map, tmp_map))
	// {
	// 	free_tab(tmp_map);
	// 	return (false);
	// }
	if (map->ff==1)
	{
		free_tab(tmp_map);
		return (false);
	}
	free_tab(tmp_map);
	return (true);
}