/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:39:42 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/27 12:26:42 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

int	ft_launch_game(t_win *win)
{
	// init_game_stat(win);
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		return (print_error(ERROR_MLX), false);
	win->mlx_win = mlx_new_window(win->mlx_ptr, WIN_LENGHT,
			WIN_HEIGHT, "Wolfromain3D");
	if (!win->mlx_win)
		return (print_error(ERROR_MLX), false);
	return (true);
}
