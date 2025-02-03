/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:28:39 by rbouquet          #+#    #+#             */
/*   Updated: 2025/02/03 11:12:33 by rbouquet         ###   ########.fr       */
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
				;
			else
				;
			y++;
		}
		x++;
	}
}

int	render(t_global *global)
{
	global->ray = ft_calloc(1, sizeof(t_ray));
	background(global);
	while (global->ray->curr_x < WIN_LENGHT)
		raycasting(global);
	return (0);
}
