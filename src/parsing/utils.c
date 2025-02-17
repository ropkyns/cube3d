/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:54:59 by romain            #+#    #+#             */
/*   Updated: 2025/02/17 11:54:22 by paulmart         ###   ########.fr       */
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

bool	ft_isdigit_str(char *str)
{
	while (*str && str)
	{
		if (!ft_isdigit(*str))
			return (false);
		else
			str++;
	}
	return (true);
}

bool	check_str(char *str, char *valid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_valid_char(str[i], valid))
			return (false);
		i++;
	}
	return (true);
}
