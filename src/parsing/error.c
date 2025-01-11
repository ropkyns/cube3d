/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:28:54 by rbouquet          #+#    #+#             */
/*   Updated: 2025/01/11 14:09:33 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

char	print_error(char *error)
{
	if (error == "PROBLEM_ARGUMENTS")
		ft_printf("Not enough or too many arguments.");
}
