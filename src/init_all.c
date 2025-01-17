/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:04:36 by paulmart          #+#    #+#             */
/*   Updated: 2025/01/17 09:54:01 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	init_map_struct(t_map *map)
{
	// int	i;
	// i = -1;
	map->player_x = 0;
	map->player_y = 0;
	map->column_map = 0;
	map->line_map = 0;
	// while (++i < 5)
	// {
	// 	map->img[i].mlx_img = NULL;
	// 	map->img[i].path = NULL;
	// }
}
