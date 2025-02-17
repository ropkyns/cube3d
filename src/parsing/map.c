/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:42 by romain            #+#    #+#             */
/*   Updated: 2025/02/17 09:19:50 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	set_player_stat(t_player *player, double dir_y, double p_x, double p_y)
{
	player->dir->y = dir_y;
	player->plan_vect->x = p_x;
	player->plan_vect->y = p_y;
}

void	start_player_pos(t_global *global, char direction, int i, int j)
{
	global->player->pos->x = (double)j;
	global->player->pos->y = (double)i;
	global->player->direction = direction;
	if (direction == 'N')
	{
		global->player->dir->x = 0.00;
		set_player_stat(global->player, -1.00, 0.66, 0.00);
	}
	if (direction == 'S')
	{
		global->player->dir->x = 0.00;
		set_player_stat(global->player, 1.00, -0.66, 0.00);
	}
	else if (direction == 'W')
	{
		global->player->dir->x = -1.00;
		set_player_stat(global->player, 0.00, 0.00, -0.66);
	}
	else if (direction == 'E')
	{
		global->player->dir->x = 1.00;
		set_player_stat(global->player, 0.00, 0.00, 0.66);
	}
}

bool	map_size(t_global *global, char **array, int i, int j)
{
	int	tmp;
	int	nbr_player;

	tmp = 0;
	nbr_player = 0;
	while (array[i])
	{
		j = -1;
		while (array[i][++j])
		{
			if (is_valid_char(array[i][j], "NSEW"))
			{
				nbr_player += 1;
				if (nbr_player > 1)
					return (false);
				start_player_pos(global, array[i][j], i, j);
			}
		}
		if (j > tmp)
			tmp = j;
		i++;
	}
	if (nbr_player != 1)
		return (false);
	global->map->height_map = i;
	global->map->lenght_map = tmp;
	return (true);
}

bool	ft_resize_map(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map_size(global, global->map->map_tab, i, j))
		return (print_error(INCORRECT_PLAYER), false);
	while (global->map->map_tab[i])
	{
		if ((int)ft_strlen(global->map->map_tab[i]) < global->map->lenght_map)
		{
			global->map->map_tab[i] = ft_resize_line(global->map->map_tab[i],
					global->map->lenght_map);
			if (!global->map->map_tab[i])
				return (print_error(ERROR_MALLOC), false);
		}
		i++;
	}
	if (!ft_wall_error(global))
	{
		print_error(INVALID_INFO);
		return (false);
	}
	return (true);
}

char	*ft_resize_line(char *map, int size)
{
	int		i;
	char	*tmp_line;

	if (size <= 0)
		return (NULL);
	tmp_line = malloc(sizeof(char) * (size + 1));
	if (!tmp_line)
		return (NULL);
	i = 0;
	while (map[i] && map[i] != '\n' && i < size - 1)
	{
		tmp_line[i] = map[i];
		i++;
	}
	while (i < size - 1)
	{
		tmp_line[i] = ' ';
		i++;
	}
	tmp_line[i++] = '\n';
	tmp_line[i] = '\0';
	if (map)
	{
		free(map);
		map = NULL;
	}
	return (tmp_line);
}
