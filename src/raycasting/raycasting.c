/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:45:34 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/30 17:50:30 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static void	init_values(t_ray *ray, t_player *player)
{
	ray->curr_x = player->pos->x;
	ray->cam_x = (2 * ray->curr_x) / (double) WIN_LENGHT - 1;
	ray->ray_dir->x =
}
void	raycasting(t_ray *ray)
{
}