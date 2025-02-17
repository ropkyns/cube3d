/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:01 by romain            #+#    #+#             */
/*   Updated: 2025/02/17 18:06:46 by paulmart         ###   ########.fr       */
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
		return (free_all(global), print_error(PROBLEM_ARGUMENTS), 1);
	if (!test_map(argv[1], global))
		return (free_all(global), 1);
	if (!ft_launch_game(global))
		return (free_all(global), 1);
	return (0);
}
