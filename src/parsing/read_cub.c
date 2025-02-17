/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:10:47 by palu              #+#    #+#             */
/*   Updated: 2025/02/17 10:09:15 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static bool	get_path(char *line, t_map *map)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && !map->no_path)
	{
		map->no_path = ft_strdup(line + 3);
		map->no_path[ft_strlen(map->no_path) - 1] = '\0';
	}
	else if (ft_strncmp(line, "SO ", 3) == 0 && !map->so_path)
	{
		map->so_path = ft_strdup(line + 3);
		map->so_path[ft_strlen(map->so_path) - 1] = '\0';
	}
	else if (ft_strncmp(line, "WE ", 3) == 0 && !map->we_path)
	{
		map->we_path = ft_strdup(line + 3);
		map->we_path[ft_strlen(map->we_path) - 1] = '\0';
	}
	else if (ft_strncmp(line, "EA ", 3) == 0 && !map->ea_path)
	{
		map->ea_path = ft_strdup(line + 3);
		map->ea_path[ft_strlen(map->ea_path) - 1] = '\0';
	}
	else
		return (false);
	return (true);
}

static bool	get_color_code(char *line, t_map *map)
{
	char	**color;
	int		*code;
	int		i;

	i = 0;
	if (ft_strncmp(line, "C ", 2) != 0 && ft_strncmp(line, "F ", 2) != 0)
		return (false);
	code = (int *)malloc(sizeof(int) * 3);
	if (!code)
		return (false);
	i = -1;
	color = ft_split(line + 2, ',');
	if (!color[3])
	{
		while (++i <= 2)
		{
			if (i == 2)
				color[i][ft_strlen(color[i]) - 1] = '\0';
			if (!ft_isdigit_str(color[i]))
				return (free(color), free(code), false);
			code[i] = ft_atoi(color[i]);
			if (code[i] > 255 || code[i] < 0)
				return (free(color), free(code), false);
		}
		if (ft_strncmp(line, "C ", 2) == 0 && !map->c_code)
		{
			map->c_code = (int *)malloc(sizeof(int) * 3);
			map->c_code = code;
		}
		else if (ft_strncmp(line, "F ", 2) == 0 && !map->f_code)
		{
			map->f_code = (int *)malloc(sizeof(int) * 3);
			map->f_code = code;
		}
		else
			return (free(color), free(code), false);
	}
	else
		return (free(color), false);
	return (free(color), free(code), true);
}

char	**maploc(int fd, int count_line)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(char *) * (count_line + 1));
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (count_line != ++i)
	{
		tab[i] = get_next_line(fd);
		if (tab[i] == NULL)
		{
			free_tab(tab);
			return (NULL);
		}
	}
	tab[i] = NULL;
	return (tab);
}

bool	get_map(t_map *map, int fd, char *path)
{
	char	*line;
	int		count_line;

	count_line = 0;
	line = get_next_line(fd);
	while (ft_strcmp(line, "\n") == 0)
	{
		line = get_next_line(fd);
		map->gnl_count++;
	}
	while (line != NULL && ft_strcmp(line, "\n") != 0)
	{
		count_line++;
		line = get_next_line(fd);
	}
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

bool	read_file(t_map *map, char *map_path)
{
	char	*line;
	int		fd;
	int		n;

	fd = open(map_path, O_RDONLY);
	n = -1;
	map->gnl_count = 1;
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
		while (is_space(line[0]) && line[1])
			line = &line[1];
		if (!get_path(line, map) && !get_color_code(line, map))
			return (print_error(INVALID_INFO), false);
		free(line);
	}
	if (!get_map(map, fd, map_path))
		return (print_error(INVALID_INFO), false);
	close(fd);
	return (true);
}
