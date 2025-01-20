/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:01 by romain            #+#    #+#             */
/*   Updated: 2025/01/20 12:39:17 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_global	*global;
	t_map		map;

	init_map_struct(&map);
	if (argc != 2)
		return (print_error(PROBLEM_ARGUMENTS), 1);
	if (!test_file(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (print_error(OPEN_FAILED), 1);
	ft_launch_game(&map);
	return (0);
}

// static void	calloc_global_struct(t_global **global_data)
// {
// 	*global_data = ft_calloc(1, sizeof(t_global));
// 	if (!*global_data)
// 		return (perror("error, global struct calloc failed"));
// }

// int	main(int argc, char **argv)
// {
// 	t_global	*global;

// 	(void)argc;
// 	(void)argv;
// 	calloc_global_struct(&global);
// 	global->win->lenght_win = 1920;
// 	global->win->height_win = 1080;
// 	init_mlx(global);
// 	mlx_loop(global->win->mlx_ptr);
// 	return (0);
// }
