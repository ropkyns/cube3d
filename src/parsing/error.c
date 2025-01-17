/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:28:54 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/17 13:55:41 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	print_error(int error)
{
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
}
