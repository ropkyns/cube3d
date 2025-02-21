/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:55:37 by paulmart          #+#    #+#             */
/*   Updated: 2025/02/21 10:47:56 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	move_forward(t_global *global, double next_x, double next_y)
{
	if (global->map->map_tab[(int)global->player->pos->y]
		[(int)(global->player->pos->x + next_x)] != '1'
		&& global->map->map_tab[(int)global->player->pos->y]
		[(int)(global->player->pos->x + next_x)] != ' ')
		global->player->pos->x += next_x;
	if (global->map->map_tab[(int)(global->player->pos->y
			+ next_y)][(int)global->player->pos->x] != '1'
		&& global->map->map_tab[(int)(global->player->pos->y
			+ next_y)][(int)global->player->pos->x] != ' ')
		global->player->pos->y += next_y;
}

void	move_backward(t_global *global, double next_x, double next_y)
{
	if (global->map->map_tab[(int)global->player->pos->y]
		[(int)(global->player->pos->x - next_x)] != '1'
		&& global->map->map_tab[(int)global->player->pos->y]
		[(int)(global->player->pos->x - next_x)] != ' ')
		global->player->pos->x -= next_x;
	if (global->map->map_tab[(int)(global->player->pos->y
			- next_y)][(int)global->player->pos->x] != '1'
		&& global->map->map_tab[(int)(global->player->pos->y
			- next_y)][(int)global->player->pos->x] != ' ')
		global->player->pos->y -= next_y;
}

void	move_right(t_global *global, double next_x, double next_y)
{
	if (global->map->map_tab[(int)global->player->pos->y]
		[(int)(global->player->pos->x + next_x)] != '1'
		&& global->map->map_tab[(int)global->player->pos->y]
		[(int)(global->player->pos->x + next_x)] != ' ')
		global->player->pos->x += next_x;
	if (global->map->map_tab[(int)(global->player->pos->y
			+ next_y)][(int)global->player->pos->x] != '1'
		&& global->map->map_tab[(int)(global->player->pos->y
			+ next_y)][(int)global->player->pos->x] != ' ')
		global->player->pos->y += next_y;
}

void	move_left(t_global *global, double next_x, double next_y)
{
	if (global->map->map_tab[(int)global->player->pos->y]
		[(int)(global->player->pos->x - next_x)] != '1'
		&& global->map->map_tab[(int)global->player->pos->y]
		[(int)(global->player->pos->x - next_x)] != ' ')
		global->player->pos->x -= next_x;
	if (global->map->map_tab[(int)(global->player->pos->y
			- next_y)][(int)global->player->pos->x] != '1'
		&& global->map->map_tab[(int)(global->player->pos->y
			- next_y)][(int)global->player->pos->x] != ' ')
		global->player->pos->y -= next_y;
}

void	rotate(t_player *player, double rot_spd)
{
	double	tmp_dir_x;
	double	tmp_plan_vect_x;

	tmp_dir_x = player->dir->x;
	tmp_plan_vect_x = player->plan_vect->x;
	player->dir->x = player->dir->x * cos(rot_spd) - player->dir->y
		* sin(rot_spd);
	player->dir->y = tmp_dir_x * sin(rot_spd) + player->dir->y * cos(rot_spd);
	player->plan_vect->x = player->plan_vect->x * cos(rot_spd)
		- player->plan_vect->y * sin(rot_spd);
	player->plan_vect->y = tmp_plan_vect_x * sin(rot_spd) + player->plan_vect->y
		* cos(rot_spd);
}
