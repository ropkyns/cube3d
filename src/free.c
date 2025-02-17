/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:44:18 by rbouquet          #+#    #+#             */
/*   Updated: 2025/02/17 12:08:08 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static void	free_win(t_global *global)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (global->img[i])
		{
			if (global->img[i]->img)
				mlx_destroy_image(global->win->mlx_ptr, global->img[i]->img);
			free(global->img[i]);
		}
		i++;
	}
	if (global->win)
	{
		if (global->win->mlx_win)
			mlx_destroy_window(global->win->mlx_ptr, global->win->mlx_win);
		if (global->win->mlx_ptr)
		{
			mlx_destroy_display(global->win->mlx_ptr);
			free(global->win->mlx_ptr);
		}
		free(global->win);
	}
}

static void	free_struct(t_global *global)
{
	if (global->map)
	{
		if (global->map->c_code)
			free(global->map->c_code);
		if (global->map->f_code)
			free(global->map->f_code);
		if (global->map->no_path)
			free(global->map->no_path);
		if (global->map->so_path)
			free(global->map->so_path);
		if (global->map->ea_path)
			free(global->map->ea_path);
		if (global->map->we_path)
			free(global->map->we_path);
		if (global->map->map_tab)
			free_tab(global->map->map_tab);
		free(global->map);
	}
	if (global->player)
	{
		free(global->player->pos);
		free(global->player->dir);
		free(global->player->plan_vect);
		free(global->player);
	}
}

int	free_all(t_global *global)
{
	if (!global)
		return (0);
	free_struct(global);
	free_win(global);
	free(global);
	exit(0);
}

// int	win_close(t_global *global)
// {
// 	ft_printf("Close the window\n");
// 	free_all(global);
// 	exit(0);
// }
