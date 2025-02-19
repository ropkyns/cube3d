/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:28:54 by rbouquet          #+#    #+#             */
/*   Updated: 2025/02/19 16:56:40 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static void	print_error2(int error)
{
	if (error == INVALID_MAP)
		ft_putstr_fd("Error\nInvalid map\n", 2);
	else if (error == SPEED_LIMIT)
		ft_putstr_fd("Error\nToo fast as fuck boy (or too slow)\n", 2);
	else if (error == SIZE_WINDOW)
		ft_putstr_fd("Error\nInvalid size for window\n", 2);
}

void	print_error(int error)
{
	print_error2(error);
	if (error == PROBLEM_ARGUMENTS)
		ft_putstr_fd("Error\nNot enough or too many arguments.\n", 2);
	else if (error == OPEN_FAILED)
		ft_putstr_fd("Error\nFailed to open file\n", 2);
	else if (error == INVALID_CHARACTER_ON_MAP)
		ft_putstr_fd("Error\nInvalid character on map\n", 2);
	else if (error == INVALID_INFO)
		ft_putstr_fd("Error\nInvalid informations in the .cub files\n", 2);
	else if (error == INCORRECT_PLAYER)
		ft_putstr_fd("Error\nIncorrect number of player\n", 2);
	else if (error == ERROR_MALLOC)
		ft_putstr_fd("Error\nError Malloc\n", 2);
	else if (error == ERROR_MLX)
		ft_putstr_fd("Error\nError in MLX\n", 2);
	else if (error == BAD_EXTENSION)
		ft_putstr_fd("Error\nBad extension\n", 2);
	else if (error == INVALID_INPUT)
		ft_putstr_fd("Error\nInvalid input\n", 2);
	else if (error == EMPTY_FILE)
		ft_putstr_fd("Error\nEmpty file\n", 2);
	else if (error == ERROR_INIT_IMG)
		ft_putstr_fd("Error\nPath texture is incorrect\n", 2);
	else if (error == INVALID_MAP)
		ft_putstr_fd("Error\nInvalid map\n", 2);
}
