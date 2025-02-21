/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:28:39 by rbouquet          #+#    #+#             */
/*   Updated: 2025/02/17 17:29:50 by paulmart         ###   ########.fr       */
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
				img_pix_put(global, x, y, create_trgb(0, global->map->c_code[0],
						global->map->c_code[1], global->map->c_code[2]));
			else
				img_pix_put(global, x, y, create_trgb(0, global->map->f_code[0],
						global->map->f_code[1], global->map->f_code[2]));
			y++;
		}
		++x;
	}
}

void	img_pix_put(t_global *global, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > global->win->height_win - 1 || x < 0
		|| x > global->win->lenght_win - 1)
		return ;
	pixel = (global->img[4]->addr + (y * global->img[4]->line_len + x
				* (global->img[4]->bpp / 8)));
	*(int *)pixel = color;
}

int	render(t_global *global)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	if (!ray)
		return (1);
	background(global);
	while (ray->curr_x < WIN_LENGHT)
		raycasting(global, ray);
	mlx_put_image_to_window(global->win->mlx_ptr, global->win->mlx_win,
		global->img[4]->img, 0, 0);
	free(ray);
	execute_move(global, global->control);
	return (0);
}
