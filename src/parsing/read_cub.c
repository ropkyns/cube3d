/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:10:47 by palu              #+#    #+#             */
/*   Updated: 2025/02/19 11:27:29 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static void	set_path(t_map *map, char *line, int dir)
{
	int	i;

	i = -1;
	while (line[++i] && is_space(line[i]))
		;
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
	if (ft_strncmp(line, "NO ", 3) == 0 && !map->no_path)
		set_path(map, line + 3, WALL_N);
	else if (ft_strncmp(line, "SO ", 3) == 0 && !map->so_path)
		set_path(map, line + 3, WALL_S);
	else if (ft_strncmp(line, "WE ", 3) == 0 && !map->we_path)
		set_path(map, line + 3, WALL_W);
	else if (ft_strncmp(line, "EA ", 3) == 0 && !map->ea_path)
		set_path(map, line + 3, WALL_E);
	else
		return (false);
	return (true);
}

static void	free_color(char **color)
{
	int	i;

	i = -1;
	while (color[++i])
		free(color[i]);
	free(color);
}

static bool	get_color_code(char *line, t_map *map)
{
	char	**color;
	int		*code;
	int		i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (ft_strncmp(line, "C ", 2) != 0 && ft_strncmp(line, "F ", 2) != 0)
		return (false);
	code = (int *)malloc(sizeof(int) * 3);
	if (!code)
		return (false);
	while (line[++i] && is_space(line[i]))
		;
	color = ft_split(line + i, ',');
	i = -1;
	if (!color[3])
	{
		while (++i <= 2)
		{
			if (i == 2)
				color[i][ft_strlen(color[i]) - 1] = '\0';
			if (!ft_isdigit_str(color[i]))
				return (free_color(color), free(code), false);
			code[i] = ft_atoi(color[i]);
			if (code[i] > 255 || code[i] < 0)
				return (free_color(color), free(code), false);
		}
		if (ft_strncmp(line, "C ", 2) == 0 && !map->c_code)
			map->c_code = code;
		else if (ft_strncmp(line, "F ", 2) == 0 && !map->f_code)
			map->f_code = code;
		else
			return (free_color(color), free(code), false);
	}
	else
		return (free_color(color), free(code), false);
	return (free_color(color), true);
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
		while (is_space(keep_line[0]) && keep_line[1])
			keep_line++;
		if (!get_path(keep_line, map) && !get_color_code(keep_line, map))
			return (close(fd), free(line), print_error(INVALID_INFO), false);
		free(line);
	}
	if (!get_map(map, fd, map_path))
		return (close(fd), print_error(INVALID_INFO), false);
	return (close(fd), true);
}
