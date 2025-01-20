/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:44:18 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/20 12:52:41 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_all(t_global *global)
{
	if (global->map->map_tab)
		free_tab(global->map->map_tab);
	if (global->win->mlx_win)
		mlx_destroy_window(global->win->mlx_ptr, global->win->mlx_win);
	if (global->win->mlx_ptr)
	{
		mlx_destroy_display(global->win->mlx_ptr);
		free(global->win->mlx_ptr);
	}
	if (global)
		free(global);
}
