/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:04:36 by paulmart          #+#    #+#             */
/*   Updated: 2025/01/20 10:42:56 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	init_map_struct(t_map *map)
{
	// int	i;
	// i = -1;
	map->player_x = 0;
	map->player_y = 0;
	map->player_direction = 0;
	map->player_direction_y = 0;
	map->player_direction_x = 0;
	map->column_map = 0;
	map->line_map = 0;
	// while (++i < 5)
	// {
	// 	map->img[i].mlx_img = NULL;
	// 	map->img[i].path = NULL;
	// }
}

void	init_mlx(t_global *data)
{
	data->win->mlx_ptr = mlx_init();
	if (!data->win->mlx_ptr)
		print_error(ERROR_MLX);
	data->win->mlx_win = mlx_new_window(data->win->mlx_ptr,
			(data->win->lenght_win), (data->win->height_win), "Wolfgame");
	if (!data->win->mlx_win)
	{
		mlx_destroy_display(data->win->mlx_ptr);
		free(data->win->mlx_ptr);
		print_error(ERROR_MLX);
	}
}
