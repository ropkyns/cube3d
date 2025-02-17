/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:45:34 by rbouquet          #+#    #+#             */
/*   Updated: 2025/02/17 09:50:21 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static void	init_values(t_ray *ray, t_player *player)
{
	ray->cam_x = (2 * ray->curr_x) / (double)WIN_LENGHT - 1;
	ray->ray_dir = malloc(sizeof(t_pos));
	ray->ray_dir->x = player->dir->x + player->plan_vect->x * ray->cam_x;
	ray->ray_dir->y = player->dir->y + player->plan_vect->y * ray->cam_x;
	ray->map_x = player->pos->x;
	ray->map_y = player->pos->y;
	ray->delta_dist = malloc(sizeof(t_pos));
	ray->delta_dist->x = fabs(1 / ray->ray_dir->x);
	ray->delta_dist->y = fabs(1 / ray->ray_dir->y);
	ray->hit = 0;
	ray->side_dist = malloc(sizeof(t_pos));
}

static void	get_step(t_ray *ray, t_player *player)
{
	if (ray->ray_dir->x < 0)
	{
		ray->step_x = -1;
		ray->side_dist->x = (player->pos->x - ray->map_x) * ray->delta_dist->x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist->x = (ray->map_x + 1.0 - player->pos->x)
			* ray->delta_dist->x;
	}
	if (ray->ray_dir->y < 0)
	{
		ray->step_y = -1;
		ray->side_dist->y = (player->pos->y - ray->map_y) * ray->delta_dist->y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist->y = (ray->map_y + 1.0 - player->pos->y)
			* ray->delta_dist->y;
	}
}

static void	get_next_wall(t_global *glob, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->side_dist->x < ray->side_dist->y)
		{
			ray->side_dist->x += ray->delta_dist->x;
			ray->map_x += ray->step_x;
			if (ray->step_x == -1)
				ray->side = WALL_E;
			else
				ray->side = WALL_W;
		}
		else
		{
			ray->side_dist->y += ray->delta_dist->y;
			ray->map_y += ray->step_y;
			if (ray->step_y == -1)
				ray->side = WALL_S;
			else
				ray->side = WALL_N;
		}
		if (glob->map->map_tab[ray->map_y][ray->map_x] == '1'
			|| glob->map->map_tab[ray->map_y][ray->map_x] == ' ')
			ray->hit = 1;
	}
}

static void	get_height(t_ray *ray, t_player *player)
{
	if (ray->side == WALL_E || ray->side == WALL_W)
		ray->prep_wall_dist = ((double)ray->map_x - player->pos->x + (1
					- ray->step_x) / 2) / ray->ray_dir->x;
	else
		ray->prep_wall_dist = ((double)ray->map_y - player->pos->y + (1
					- ray->step_y) / 2) / ray->ray_dir->y;
	ray->line_height = WIN_HEIGHT / ray->prep_wall_dist;
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start <= 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	raycasting(t_global *glob, t_ray *ray)
{
	t_player	*player;

	player = glob->player;
	init_values(ray, player);
	get_step(ray, player);
	get_next_wall(glob, ray);
	get_height(ray, player);
	draw_texture(glob, ray, player);
	free(ray->ray_dir);
	free(ray->side_dist);
	free(ray->delta_dist);
	ray->curr_x++;
}
