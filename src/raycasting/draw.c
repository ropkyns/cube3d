/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:27:30 by paulmart          #+#    #+#             */
/*   Updated: 2025/02/12 13:04:13 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	draw_line(t_global *glob, t_ray *ray, double wall_x, double *tex_pos, int e_img)
{
	t_image	*img;
	int		tex_x;
	int		tex_y;
	int		color;

	img = glob->img[e_img];
	tex_y = (int)*tex_pos & (img->height -1);
	*tex_pos += 1.0 * img->height / ray->line_height;
	tex_x = ((int)wall_x * img->width);
	if ((ray->side == WALL_W || ray->side == WALL_E)
		&& ray->ray_dir->x > 0)
		tex_x = img->width - tex_x - 1;
	else if ((ray->side == WALL_N || ray->side == WALL_S)
		&& ray->ray_dir->y < 0)
		tex_x = img->width - tex_x - 1;
	color = *(int *)(img->addr
			+ (tex_y * img->line_len + tex_x * (img->bpp / 8)));
	img_pix_put(glob, ray->curr_x, ray->draw_start, color);
}

void	draw_texture(t_global *glob, t_ray *ray, t_player *player)
{
	double	wall_x;
	double	tex_pos;

	if (ray->side == WALL_E || ray->side == WALL_W)
		wall_x = player->pos->y + ray->prep_wall_dist * ray->ray_dir->y;
	else
		wall_x = player->pos->x + ray->prep_wall_dist * ray->ray_dir->x;
	wall_x -= floor(wall_x);
	tex_pos = (ray->draw_start - glob->win->height_win / 2
			+ ray->line_height / 2)
		* (1.0 * glob->img[0]->height / ray->line_height);
	while (ray->draw_start < ray->draw_end)
	{
		if (ray->side == WALL_N)
			draw_line(glob, ray, wall_x, &tex_pos, WALL_N);
		else if (ray->side == WALL_S)
			draw_line(glob, ray, wall_x, &tex_pos, WALL_S);
		else if (ray->side == WALL_E)
			draw_line(glob, ray, wall_x, &tex_pos, WALL_E);
		else if (ray->side == WALL_W)
			draw_line(glob, ray, wall_x, &tex_pos, WALL_W);
		ray->draw_start++;
	}
}
