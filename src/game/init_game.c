/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:39:42 by rbouquet          #+#    #+#             */
/*   Updated: 2025/02/19 17:18:28 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	*read_xpm(t_global *global, char *path, int n)
{
	void	*img;
	int		height;
	int		width;

	img = mlx_xpm_file_to_image(global->win->mlx_ptr, path,
			&global->img[n]->width, &global->img[n]->height);
	if (!img)
	{
		print_error(ERROR_INIT_IMG);
		return (free_all(global), NULL);
	}
	return (img);
}

static void	ft_init_img(t_global *global)
{
	int	i;

	i = -1;
	global->img[0]->img = read_xpm(global, global->map->no_path, 0);
	global->img[1]->img = read_xpm(global, global->map->so_path, 1);
	global->img[2]->img = read_xpm(global, global->map->we_path, 2);
	global->img[3]->img = read_xpm(global, global->map->ea_path, 3);
	global->img[4]->img = mlx_new_image(global->win->mlx_ptr, WIN_LENGHT,
			WIN_HEIGHT);
	if (!global->img[4]->img)
	{
		print_error(ERROR_INIT_IMG);
		free_all(global);
	}
	while (++i < 5)
	{
		global->img[i]->addr = mlx_get_data_addr(global->img[i]->img,
				&global->img[i]->bpp, &global->img[i]->line_len,
				&global->img[i]->endian);
		if (!global->img[i]->addr)
		{
			print_error(ERROR_INIT_IMG);
			free_all(global);
		}
	}
}

int	ft_launch_game(t_global *global)
{
	init_game_stat(global);
	if (global->player->speed < 0 || global->player->speed > 1)
		return (print_error(SPEED_LIMIT), false);
	if ((global->win->height_win > 1080 || global->win->height_win <= 0)
		|| (global->win->lenght_win > 1920 || global->win->lenght_win <= 0))
		return (print_error(SIZE_WINDOW), false);
	global->win->mlx_ptr = mlx_init();
	if (!global->win->mlx_ptr)
		return (print_error(ERROR_MLX), false);
	global->win->mlx_win = mlx_new_window(global->win->mlx_ptr,
			global->win->lenght_win, global->win->height_win, "Wolfromain3D");
	if (!global->win->mlx_win)
		return (print_error(ERROR_MLX), false);
	ft_init_img(global);
	mlx_loop_hook(global->win->mlx_ptr, &render, global);
	mlx_hook(global->win->mlx_win, 2, 1L << 0, key_handler, global);
	mlx_hook(global->win->mlx_win, 3, 1L << 1, key_release, global);
	mlx_hook(global->win->mlx_win, 6, 1L << 6, move_mouse, global);
	mlx_hook(global->win->mlx_win, 17, 0, free_all, global);
	mlx_loop(global->win->mlx_ptr);
	return (true);
}
