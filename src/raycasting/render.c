/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:28:39 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/31 17:13:02 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	background(t_global *global)
{
	int	x;
	int	y;

	x = 0;
	while (x < global->win->lenght_win)
	{
		y = 0;
		while (y < global->win->height_win)
		{
			if (y < global->win->height_win / 2)
				mlx_pixel_put(global->win, global->win->mlx_win, x, y,
					create_trgb(0, global->map->c_code[0],
						global->map->c_code[1], global->map->c_code[2]));
			else
				mlx_pixel_put(global->win, global->win->mlx_win, x, y,
					create_trgb(0, global->map->f_code[0],
						global->map->f_code[1], global->map->f_code[2]));
			y++;
		}
		x++;
	}
}

int	rendu(t_global *global)
{
	global->ray = ft_calloc(1, sizeof(t_ray));
	background(global);
	while (global->ray->curr_x < WIN_LENGHT)
		raycasting(global);
	return (0);
}
