/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:54:59 by romain            #+#    #+#             */
/*   Updated: 2025/02/17 15:59:03 by rbouquet         ###   ########.fr       */
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

char	**maploc(int fd, int count_line)
{
	char	**tab;
	char	*line;
	int		i;

	tab = malloc(sizeof(char *) * (count_line + 1));
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (count_line != ++i)
	{
		tab[i] = get_next_line(fd);
		if (tab[i] == NULL)
			return (free_tab(tab), NULL);
	}
	tab[i] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (tab);
}
