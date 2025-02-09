/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:40:47 by rbouquet          #+#    #+#             */
/*   Updated: 2025/02/09 12:05:09 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static void	move(t_global *global, double next_x, double next_y, char sign)
{
	int	old_x;
	int	old_y;

	old_x = (int)global->player->pos->x;
	old_y = (int)global->player->pos->y;
	if (sign == '+')
	{
		if (global->map->map_tab[(int)global->player->pos->y][(int)(global->player->pos->x
				+ next_x)] != '1')
			global->player->pos->x += next_x;
		if (global->map->map_tab[(int)(global->player->pos->y
				+ next_y)][(int)global->player->pos->x] != '1')
			global->player->pos->y += next_y;
	}
	else if (sign == '-')
	{
		if (global->map->map_tab[(int)global->player->pos->y][(int)(global->player->pos->x
				- next_x)] != '1')
			global->player->pos->x -= next_x;
		if (global->map->map_tab[(int)(global->player->pos->y
				- next_y)][(int)global->player->pos->x] != '1')
			global->player->pos->y -= next_y;
	}
}

int	key_handler(int keycode, t_global *global)
{
	if (keycode == XK_Escape)
		free_all(global);
	else if (keycode == XK_W || keycode == XK_w)
		move(global, global->player->dir->x * global->player->speed,
			global->player->dir->y * global->player->speed, '+');
	else if (keycode == XK_S || keycode == XK_s)
		move(global, global->player->dir->x * global->player->speed,
			global->player->dir->y * global->player->speed, '-');
	else if (keycode == XK_A || keycode == XK_a)
		move(global, global->player->plan_vect->x * global->player->speed,
			global->player->plan_vect->y * global->player->speed, '-');
	else if (keycode == XK_D || keycode == XK_d)
		move(global, global->player->plan_vect->x * global->player->speed,
			global->player->plan_vect->y * global->player->speed, '+');
	else if (keycode == XK_Left)
		;
	else if (keycode == XK_Right)
		;
	return (true);
}
