/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:40:47 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/24 10:08:04 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"


int	key_handler(int keycode, t_global *global)
{
	if (keycode == XK_Escape)
		free_all(global);
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
