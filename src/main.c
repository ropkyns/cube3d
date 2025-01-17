/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:01 by romain            #+#    #+#             */
/*   Updated: 2025/01/17 10:27:38 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	init_map_struct(&map);
	if (argc != 2)
		return (print_error(PROBLEM_ARGUMENTS), 1);
	if (!test_file(argv[1]))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (print_error(OPEN_FAILED), 1);
}
