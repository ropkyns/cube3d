/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:39:42 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/22 13:52:50 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

int	ft_launch_game(t_win *win)
{
	init_game_stat(win);
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		return (print_error(ERROR_MLX), 1);
	win->mlx_win = mlx_new_window(win->mlx_ptr, win->lenght_win,
			win->height_win, "Cube3D");
	if (!win->mlx_win)
		return (print_error(ERROR_MLX), 1);
}
