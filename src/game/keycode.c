/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:40:47 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/27 14:38:32 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

int	key_handler(int keycode, t_global *global)
{
	if (keycode == XK_Escape)
		free_all(global);
	else if (keycode == XK_W || keycode == XK_w)
		;
	else if (keycode == XK_S || keycode == XK_s)
		;
	else if (keycode == XK_A || keycode == XK_a)
		;
	else if (keycode == XK_D || keycode == XK_d)
		;
	else if (keycode == XK_Left)
		;
	else if (keycode == XK_Right)
		;
	return (true);
}

// void	moves(t_map *map, double next_x, double next_y, char sign)
// {
// 	if (sign == '+')
// 	{
// 	}
// 	else if (sign == '-')
// 	{
// 	}
// }
