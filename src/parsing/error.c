/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:28:54 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/15 12:17:16 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

char	print_error(char *error)
{
	if (error == "PROBLEM_ARGUMENTS")
		ft_printf("Error\nNot enough or too many arguments.\n");
	else if (error == "OPEN_FAILED")
		ft_printf("Error\nFailed to open file\n");
	else if (error == "INVALID_CHARACTER")
		ft_printf("Error\nInvalid character on map\n");
}
