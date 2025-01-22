/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:01 by romain            #+#    #+#             */
/*   Updated: 2025/01/22 15:11:14 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	main(int argc, char **argv)
{
	int fd;
	t_global *global;

	global = ft_calloc(1, sizeof(t_global));
	init_map_struct(global->map);
	if (argc != 2)
		return (print_error(PROBLEM_ARGUMENTS), 1);
	if (!test_file(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (print_error(OPEN_FAILED), 1);
	if (!ft_launch_game(global->win))
		return (1);
	mlx_hook(global->win, 2, 1L << 0, key_handler, &global);
	// mlx_hook(global.win, 17, 0, free_all, &global);
	mlx_loop(global->win->mlx_ptr);
	return (0);
}
