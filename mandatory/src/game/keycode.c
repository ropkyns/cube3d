/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:40:47 by rbouquet          #+#    #+#             */
/*   Updated: 2025/02/21 10:00:04 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	execute_move(t_global *global, t_control *control)
{
	if (control->forward == 1)
		move_forward(global, global->player->dir->x * global->player->speed,
			global->player->dir->y * global->player->speed);
	if (control->backward == 1)
		move_backward(global, global->player->dir->x * global->player->speed,
			global->player->dir->y * global->player->speed);
	if (control->left == 1)
		move_left(global, global->player->plan_vect->x * global->player->speed,
			global->player->plan_vect->y * global->player->speed);
	if (control->right == 1)
		move_right(global, global->player->plan_vect->x * global->player->speed,
			global->player->plan_vect->y * global->player->speed);
	if ((control->rotation_left == 1 && (global->player->direction == 'N'
				|| global->player->direction == 'S'))
		|| (control->rotation_left == 1 && (global->player->direction == 'E'
				|| global->player->direction == 'W')))
		rotate(global->player, -global->player->rotation_speed);
	if ((control->rotation_right == 1 && (global->player->direction == 'E'
				|| global->player->direction == 'W'))
		|| (control->rotation_right == 1 && (global->player->direction == 'N'
				|| global->player->direction == 'S')))
		rotate(global->player, global->player->rotation_speed);
}

int	key_handler(int keycode, t_global *global)
{
	if (keycode == XK_Escape)
		free_all(global);
	if (keycode == XK_W || keycode == XK_w)
		global->control->forward = 1;
	if (keycode == XK_S || keycode == XK_s)
		global->control->backward = 1;
	if (keycode == XK_A || keycode == XK_a)
		global->control->left = 1;
	if (keycode == XK_D || keycode == XK_d)
		global->control->right = 1;
	if (keycode == XK_Left)
		global->control->rotation_left = 1;
	if (keycode == XK_Right)
		global->control->rotation_right = 1;
	return (true);
}

int	key_release(int keycode, t_global *global)
{
	if (keycode == XK_W || keycode == XK_w)
		global->control->forward = 0;
	if (keycode == XK_S || keycode == XK_s)
		global->control->backward = 0;
	if (keycode == XK_A || keycode == XK_a)
		global->control->left = 0;
	if (keycode == XK_D || keycode == XK_d)
		global->control->right = 0;
	if (keycode == XK_Left)
		global->control->rotation_left = 0;
	if (keycode == XK_Right)
		global->control->rotation_right = 0;
	return (true);
}

