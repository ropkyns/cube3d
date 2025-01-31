/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:45:34 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/31 13:20:32 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static void	init_values(t_ray *ray, t_player *player)
{
	ray->curr_x = player->pos->x;
	ray->cam_x = (2 * ray->curr_x) / (double)WIN_LENGHT - 1;
	ray->ray_dir->x = player->dir->x + player->plan_vect->x * ray->cam_x;
	ray->ray_dir->y = player->dir->y + player->plan_vect->y * ray->cam_y;
	ray->map_x = player->pos->x;
	ray->map_y = player->pos->y;
	ray->delta_dist->x = fabs(1 / ray->ray_dir->x);
	ray->delta_dist->y = fabs(1 / ray->ray_dir->y);
	ray->hit = 0;
}
void	raycasting(t_ray *ray)
{
}
