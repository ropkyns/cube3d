/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:54:59 by romain            #+#    #+#             */
/*   Updated: 2025/01/20 12:44:38 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

bool	is_valid_char(char c, char *valid_char)
{
	int	i;

	i = 0;
	while (valid_char[i])
	{
		if (c == valid_char[i])
			return (true);
		i++;
	}
	return (false);
}

bool	is_space(char c)
{
	if ((c && (c >= 9 && c <= 13)) || (c == ' '))
		return (true);
	return (false);
}
