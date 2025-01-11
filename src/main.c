/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:01 by romain            #+#    #+#             */
/*   Updated: 2025/01/11 14:13:58 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	init_map_struct(t_map *data)
{
	data->player_x = 0;
	data->player_y = 0;
	data->player_nbr = 0;
	data->column = 0;
	data->line = 0;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (print_error("PROBLEM_ARGUMENTS"), 1);
}
