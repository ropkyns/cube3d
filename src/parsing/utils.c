/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:54:59 by romain            #+#    #+#             */
/*   Updated: 2025/01/16 18:24:28 by palu             ###   ########.fr       */
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
			return (false);
		i++;
	}
	return (true);
}

bool	is_space(char c)
{
	if ((c && (c >= 9 && c <= 13)) || (c == ' '))
		return (true);
	return (false);
}

int	ft_strlen_cube3d(char *s)
{
	int i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
