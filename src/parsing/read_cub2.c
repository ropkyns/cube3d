/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:22:16 by rbouquet          #+#    #+#             */
/*   Updated: 2025/02/19 09:23:23 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

bool	get_map(t_map *map, int fd, char *path)
{
	char	*line;
	int		count_line;

	count_line = 0;
	line = get_next_line(fd);
	while (ft_strcmp(line, "\n") == 0)
	{
		free(line);
		line = get_next_line(fd);
		map->gnl_count++;
	}
	while (line != NULL && ft_strcmp(line, "\n") != 0)
	{
		free(line);
		count_line++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	fd = open(path, O_RDONLY);
	while (map->gnl_count-- > 1)
	{
		line = get_next_line(fd);
		free(line);
	}
	map->map_tab = maploc(fd, count_line);
	if (!map->map_tab)
		return (false);
	return (true);
}
