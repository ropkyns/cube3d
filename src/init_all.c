/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:04:36 by paulmart          #+#    #+#             */
/*   Updated: 2025/01/30 12:32:47 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	init_map_struct(t_global *global)
{
	global->map = ft_calloc(1, sizeof(t_map));
	global->map->player = ft_calloc(1, sizeof(t_player));
	global->map->player->pos = ft_calloc(1, sizeof(t_pos));
	global->map->player->player_dir = ft_calloc(1, sizeof(t_pos));
	global->map->column_map = 0;
	global->map->line_map = 0;
}

void	init_game_stat(t_win *win)
{
	win->lenght_win = WIN_LENGHT;
	win->height_win = WIN_HEIGHT;
	win->player->speed = 0.09;
	win->player->rotation_speed = 0.09;
}
