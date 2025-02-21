/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:10:47 by palu              #+#    #+#             */
/*   Updated: 2025/02/21 09:37:14 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static void	set_path(t_map *map, char *line, int dir)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	line[strlen(line) - 1] = '\0';
	if (dir == WALL_N)
		map->no_path = ft_strdup(line + i);
	else if (dir == WALL_S)
		map->so_path = ft_strdup(line + i);
	else if (dir == WALL_E)
		map->ea_path = ft_strdup(line + i);
	else if (dir == WALL_W)
		map->we_path = ft_strdup(line + i);
}

static bool	get_path(char *line, t_map *map)
{
	if (ft_strncmp(line, "NO", 2) == 0 && !map->no_path)
		set_path(map, line + 3, WALL_N);
	else if (ft_strncmp(line, "SO", 2) == 0 && !map->so_path)
		set_path(map, line + 3, WALL_S);
	else if (ft_strncmp(line, "WE", 2) == 0 && !map->we_path)
		set_path(map, line + 3, WALL_W);
	else if (ft_strncmp(line, "EA", 2) == 0 && !map->ea_path)
		set_path(map, line + 3, WALL_E);
	else
		return (false);
	return (true);
}

void	free_color(char **color)
{
	int	i;

	i = -1;
	while (color[++i])
		free(color[i]);
	free(color);
}

static bool	find_path(char *keep_line, t_map *map, int fd, char *line)
{
	while (is_space(keep_line[0]) && keep_line[1])
		keep_line++;
	if (!get_path(keep_line, map) && !get_color_code(keep_line, map))
	{
		while (keep_line)
		{
			keep_line = get_next_line(fd);
			free(keep_line);
		}
		return (close(fd), free(line), print_error(INVALID_INFO), false);
	}
	free(line);
	return (true);
}

bool	read_file(t_map *map, char *map_path)
{
	char	*line;
	int		fd;
	char	*keep_line;
	int		n;

	fd = open(map_path, O_RDONLY);
	n = -1;
	while (++n <= 5)
	{
		line = get_next_line(fd);
		map->gnl_count++;
		while (ft_strcmp(line, "\n") == 0)
		{
			free(line);
			line = get_next_line(fd);
			map->gnl_count++;
		}
		keep_line = line;
		if (!find_path(keep_line, map, fd, line))
			return (false);
	}
	if (!get_map(map, fd, map_path))
		return (close(fd), print_error(INVALID_MAP), false);
	return (close(fd), true);
}
