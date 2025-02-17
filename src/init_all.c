/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:04:36 by paulmart          #+#    #+#             */
/*   Updated: 2025/02/17 18:10:50 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	init_map_struct(t_global *global)
{
	int	i;

	i = 0;
	global->map = ft_calloc(1, sizeof(t_map));
	global->player = ft_calloc(1, sizeof(t_player));
	global->player->pos = ft_calloc(1, sizeof(t_pos));
	global->player->dir = ft_calloc(1, sizeof(t_pos));
	global->player->plan_vect = ft_calloc(1, sizeof(t_pos));
	global->win = ft_calloc(1, sizeof(t_win));
	while (i < 5)
		global->img[i++] = ft_calloc(1, sizeof(t_image));
	global->map->column_map = 0;
	global->map->line_map = 0;
	global->control = ft_calloc(1, sizeof(t_control));
}

void	init_game_stat(t_global *global)
{
	global->win->lenght_win = WIN_LENGHT;
	global->win->height_win = WIN_HEIGHT;
	global->player->speed = 0.05;
	global->player->rotation_speed = 0.03;
}
