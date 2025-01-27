/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:42 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 09:30:39 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	start_player_pos(t_map *map, char direction, int i, int j)
{
	map->player->pos->x = (double)j;
	map->player->pos->y = (double)i;
	map->player->direction = direction;
	if (direction == 'N')
	{
		map->player->player_dir->x = 0;
		map->player->player_dir->y = -1;
	}
	else if (direction == 'S')
	{
		map->player->player_dir->x = 0;
		map->player->player_dir->y = 1;
	}
	else if (direction == 'W')
	{
		map->player->player_dir->x = -1;
		map->player->player_dir->y = 0;
	}
	else if (direction == 'E')
	{
		map->player->player_dir->x = 1;
		map->player->player_dir->y = 0;
	}
}

bool	map_size(t_map *map, char **array, int i, int j)
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
		return (false);
	map->height_map = tmp;
	map->lenght_map = i;
	return (true);
}

bool	ft_resize_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (map_size(map, map->map_tab, i, j) == false)
		return (print_error(INCORRECT_PLAYER), false);
	while (map->map_tab[i])
	{
		if (ft_strlen(map->map_tab[i]) < map->lenght_map)
		{
			map->map_tab[i] = ft_resize_line(map->map_tab[i], map->lenght_map);
			if (!map->map_tab[i])
				return (print_error(ERROR_MALLOC), false);
		}
		i++;
	}
	return (true);
}

char	*ft_resize_line(char *map, int size)
{
	int		i;
	char	*tmp_line;

	i = 0;
	tmp_line = malloc(sizeof(char) * size + 1);
	if (!tmp_line)
		return (NULL);
	while (map[i] && map[i] != '\n')
	{
		tmp_line[i] = map[i];
		i++;
	}
	while (i < size)
	{
		tmp_line[i] = ' ';
		i++;
	}
	tmp_line[i] = '\n';
	if (map)
		free(map);
	return (tmp_line);
}
