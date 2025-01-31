/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:28:39 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/31 13:12:03 by rbouquet         ###   ########.fr       */
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
	background(global);
	// raycasting(win->ray);
	return (0);
}
