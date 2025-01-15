/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:10:47 by palu              #+#    #+#             */
/*   Updated: 2025/01/15 14:22:49 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

bool	wall_path(t_map *map, int fd, char *direction, char	*path)
{
	char	*line;

	line = get_next_line(fd);
	while (strcmp(line, "\n") == 0)
		line = get_next_line(fd);
	if (strcmp(line, direction) == 0)
		path = ft_strdup(*(line + 3));
	else
		return (print_error(INVALID_INFO), false);
}

bool	read_file(t_map *map, char *map_path)
{
	int		fd;
	int		i;

	fd = open(map_path, 0);
	if (!wall_path(map, fd, "NO ", map->no_path))
		return (false);
	if (!wall_path(map, fd, "SO ", map->so_path))
		return (false);
	if (!wall_path(map, fd, "EA ", map->ea_path))
		return (false);
	if (!wall_path(map, fd, "WE ", map->we_path))
		return (false);
}
