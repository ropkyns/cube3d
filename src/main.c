/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:01 by romain            #+#    #+#             */
/*   Updated: 2025/01/31 13:11:25 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_global	*global;

	global = ft_calloc(1, sizeof(t_global));
	init_map_struct(global);
	if (argc != 2)
		return (print_error(PROBLEM_ARGUMENTS), 1);
	if (!test_map(argv[1], global))
		return (1);
	if (!ft_launch_game(global))
		return (1);
	return (0);
}
