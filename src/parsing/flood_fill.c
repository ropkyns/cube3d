/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:53:59 by romain            #+#    #+#             */
/*   Updated: 2025/01/11 11:01:09 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

char	**dup_map(t_map *data, char **map)
{
	char	**tmp_map;
	int		i;

	tmp_map = malloc((data->line + 1) * sizeof(char *));
	if (!tmp_map)
		check_error(data, 1);
	i = -1;
	while (++i < data->line)
	{
		tmp_map[i] = ft_strdup(map[i]);
		if (!tmp_map)
		{
			free_array(tmp_map);
			check_error(data, 1);
		}
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}

void	fill(t_map *data, char **map, int y, int x)
{
	if (y < 0 || y > data->line || x < 0 || x > data->column
		|| (map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'P'))
		return ;
	map[y][x] = 'x';
	fill(data, map, (y + 1), x);
	fill(data, map, (y - 1), x);
	fill(data, map, y, (x + 1));
	fill(data, map, y, (x - 1));
}

bool	check_fill(t_map *data, char **tmp_map)
{
	int	x;
	int	y;

	y = data->line;
	while (y--)
	{
		x = data->column;
		while (x--)
		{
			if (tmp_map[y][x] == 'C')
				return (false);
			if (tmp_map[y][x] == 'E' && (tmp_map[y + 1][x] != 'x' && tmp_map[y
					- 1][x] != 'x' && tmp_map[y][x + 1] != 'x' && tmp_map[y][x
					- 1] != 'x'))
				return (false);
		}
	}
	return (true);
}

void	flood_fill(t_map *data)
{
	char	**tmp_map;

	tmp_map = dup_map(data, data->map);
	if (!tmp_map)
		check_error(data, 1);
	fill(data, tmp_map, data->player_y, data->player_x);
	if (!check_fill(data, tmp_map))
	{
		free_array(tmp_map);
		check_error(data, 12);
	}
	free_array(tmp_map);
}
