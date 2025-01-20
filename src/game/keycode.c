/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:40:47 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/20 15:25:00 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static int	win_close(t_global *global)
{
	ft_putstr_fd("Close Window", 1);
	free_all(global);
	exit(0);
}

int	key_handler(int keycode, t_global *global)
{
	if (keycode == XK_Escape)
		win_close(global);
}

void	moves(t_map *map, double next_x, double next_y, char sign)
{
	if (sign == '+')
	{
	}
	else if (sign == '-')
	{
	}
}
