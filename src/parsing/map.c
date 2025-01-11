/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:30:42 by romain            #+#    #+#             */
/*   Updated: 2025/01/11 14:01:26 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void	load_map(t_map *data, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		check_error(data, 5);
	line = get_next_line(fd);
	if (line != 0)
		data->column = ft_strlen(line) - 1;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		data->line++;
	}
	free(line);
	close(fd);
	data->map = malloc_map(data, map);
}
