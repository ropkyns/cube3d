/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:01 by romain            #+#    #+#             */
/*   Updated: 2025/01/15 12:15:02 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	init_map_struct(t_map *map)
{
	// int	i;
	// i = -1;
	map->player_x = 0;
	map->player_y = 0;
	map->player_nbr = 0;
	map->column_map = 0;
	map->line_map = 0;
	// while (++i < 5)
	// {
	// 	map->img[i].mlx_img = NULL;
	// 	map->img[i].path = NULL;
	// }
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	init_map_struct(&map);
	if (argc != 2)
		return (print_error("PROBLEM_ARGUMENTS"), 1);
	if (!test_file(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (print_error("OPEN_FAILED"), 1);
}
