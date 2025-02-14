/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:40:47 by rbouquet          #+#    #+#             */
/*   Updated: 2025/02/14 10:14:11 by rbouquet         ###   ########.fr       */
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
				+ next_x)] != '1'
			&& global->map->map_tab[(int)global->player->pos->y][(int)(global->player->pos->x
				+ next_x)] != ' ')
			global->player->pos->x += next_x;
		if (global->map->map_tab[(int)(global->player->pos->y
				+ next_y)][(int)global->player->pos->x] != '1'
			&& global->map->map_tab[(int)(global->player->pos->y
				+ next_y)][(int)global->player->pos->x] != ' ')
			global->player->pos->y += next_y;
	}
	else if (sign == '-')
	{
		if (global->map->map_tab[(int)global->player->pos->y][(int)(global->player->pos->x
				- next_x)] != '1'
			&& global->map->map_tab[(int)global->player->pos->y][(int)(global->player->pos->x
				- next_x)] != ' ')
			global->player->pos->x -= next_x;
		if (global->map->map_tab[(int)(global->player->pos->y
				- next_y)][(int)global->player->pos->x] != '1'
			&& global->map->map_tab[(int)(global->player->pos->y
				- next_y)][(int)global->player->pos->x] != ' ')
			global->player->pos->y -= next_y;
	}
}

static void	rotate(t_player *player, double rot_spd)
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
	else if ((keycode == XK_Left && (global->player->direction == 'N'
				|| global->player->direction == 'S')) || (keycode == XK_Right
			&& (global->player->direction == 'E'
				|| global->player->direction == 'W')))
		rotate(global->player, -global->player->rotation_speed);
	else if ((keycode == XK_Left && (global->player->direction == 'E'
				|| global->player->direction == 'W')) || (keycode == XK_Right
			&& (global->player->direction == 'N'
				|| global->player->direction == 'S')))
		rotate(global->player, global->player->rotation_speed);
	return (true);
}

int	move_mouse(int x, int y, t_global *global)
{
	(void)y;
	if (global->player->direction == 'N' || global->player->direction == 'S')
	{
		if (x > (int)(WIN_LENGHT / 1.2))
			rotate(global->player, global->player->rotation_speed / 3);
		else if (x < WIN_LENGHT / 6)
			rotate(global->player, -global->player->rotation_speed / 3);
	}
	else
	{
		if (x > (int)(WIN_LENGHT / 1.2))
			rotate(global->player, -global->player->rotation_speed / 3);
		else if (x < WIN_LENGHT / 6)
			rotate(global->player, global->player->rotation_speed / 3);
	}
	return (0);
}
