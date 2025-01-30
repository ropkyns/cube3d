/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:39:42 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/30 11:56:05 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

int	ft_launch_game(t_win *win)
{
	init_game_stat(win);
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		return (print_error(ERROR_MLX), false);
	win->mlx_win = mlx_new_window(win->mlx_ptr, win->lenght_win,
			win->height_win, "Wolfromain3D");
	if (!win->mlx_win)
		return (print_error(ERROR_MLX), false);
	// ft_init_img(win);
	mlx_loop_hook(win->mlx_ptr, &rendu, win);
	mlx_hook(win->mlx_win, 2, 1L << 0, key_handler, win);
	mlx_hook(win->mlx_win, 17, 0, win_close, win);
	mlx_loop(win->mlx_ptr);
	return (true);
}
