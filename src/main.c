/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:01 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 12:28:33 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_global	*global;

	global = ft_calloc(1, sizeof(t_global));
	// init_map_struct(global->map);
	if (argc != 2)
		return (print_error(PROBLEM_ARGUMENTS), 1);
	global->map = ft_calloc(1, sizeof(t_map));
	global->map->player = ft_calloc(1, sizeof(t_player));
	global->map->player->pos = ft_calloc(1, sizeof(t_pos));
	global->map->player->player_dir = ft_calloc(1, sizeof(t_pos));
	if (!test_map(argv[1], global->map))
		return (1);
	global->win = ft_calloc(1, sizeof(t_win));
	if (!ft_launch_game(global->win))
		return (1);
	mlx_hook(global->win->mlx_win, 2, 1L << 0, key_handler, global);
	mlx_hook(global->win->mlx_win, 17, 0, free_all, global);
	mlx_loop(global->win->mlx_ptr);
	return (0);
}
