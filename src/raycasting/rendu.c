/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:28:39 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/30 11:48:32 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	background(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	while (x < win->lenght_win)
	{
		y = 0;
		while (y < win->height_win)
		{
			if (y < win->height_win / 2)
				lx_pixel_put(win, win->mlx_win, x, y, );
			else
				mlx_pixel_put(win, win->mlx_win, x, y, );
			y++;
		}
		x++;
	}
}

int	rendu(t_win *win)
{
	background(win);
	raycasting(win->ray);
}