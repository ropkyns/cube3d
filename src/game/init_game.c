/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:39:42 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/31 13:11:34 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

int	ft_launch_game(t_global *global)
{
	init_game_stat(global);
	global->win->mlx_ptr = mlx_init();
	if (!global->win->mlx_ptr)
		return (print_error(ERROR_MLX), false);
	global->win->mlx_win = mlx_new_window(global->win->mlx_ptr,
			global->win->lenght_win, global->win->height_win, "Wolfromain3D");
	if (!global->win->mlx_win)
		return (print_error(ERROR_MLX), false);
	// ft_init_img(win);
	mlx_loop_hook(global->win->mlx_ptr, &rendu, global);
	mlx_hook(global->win->mlx_win, 2, 1L << 0, key_handler, global);
	mlx_hook(global->win->mlx_win, 17, 0, win_close, global);
	mlx_loop(global->win->mlx_ptr);
	return (true);
}
