/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:22:16 by rbouquet          #+#    #+#             */
/*   Updated: 2025/02/19 15:55:06 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static bool	set_color(t_map *map, char **color, int *code, char *line)
{
	int	i;

	i = -1;
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
	if (ft_strncmp(line, "C", 1) == 0 && !map->c_code)
		map->c_code = code;
	else if (ft_strncmp(line, "F", 1) == 0 && !map->f_code)
		map->f_code = code;
	else
		return (free_color(color), free(code), false);
	return (true);
}

bool	get_color_code(char *line, t_map *map)
{
	char	**color;
	int		*code;
	int		i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (ft_strncmp(line, "C", 1) != 0 && ft_strncmp(line, "F", 1) != 0)
		return (false);
	code = (int *)malloc(sizeof(int) * 3);
	if (!code)
		return (false);
	while (line[++i] && is_space(line[i]))
		;
	color = ft_split(line + i, ',');
	if (!color[3] && !set_color(map, color, code, line))
		return (false);
	return (free_color(color), true);
}

static int	get_map_size(t_map *map, int count_line, char *line, int fd)
{
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
	if (line)
	{
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
		free(line);
		return (-1);
	}
	return (count_line);
}

bool	get_map(t_map *map, int fd, char *path)
{
	char	*line;
	int		count_line;

	count_line = 0;
	count_line = get_map_size(map, count_line, line, fd);
	if (count_line == -1)
		return (false);
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
