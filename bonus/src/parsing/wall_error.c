/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:54:14 by romain            #+#    #+#             */
/*   Updated: 2025/02/19 09:32:40 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

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
	if (y >= 0 && y < map->height_map && x >= 0
		&& x < map->lenght_map && is_valid_char(tmp_map[y][x], "0NSEW"))
		map->ff = 1;
	if (y < 0 || y >= map->height_map || x < 0 || x >= map->lenght_map
		|| (tmp_map[y][x] == '1' || tmp_map[y][x] == '0'
		|| tmp_map[y][x] == 'x'))
		return ;
	tmp_map[y][x] = 'x';
	fill(map, tmp_map, (y + 1), x);
	fill(map, tmp_map, (y - 1), x);
	fill(map, tmp_map, y, (x + 1));
	fill(map, tmp_map, y, (x - 1));
}

bool	flood_fill(t_map *map, int y, int x)
{
	char	**tmp_map;

	tmp_map = dup_map(map);
	if (!tmp_map)
		return (false);
	fill(map, tmp_map, y, x);
	if (map->ff == 1)
	{
		free_tab(tmp_map);
		return (false);
	}
	free_tab(tmp_map);
	return (true);
}
