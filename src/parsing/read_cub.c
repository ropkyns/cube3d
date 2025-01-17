/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:10:47 by palu              #+#    #+#             */
/*   Updated: 2025/01/17 11:33:02 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static bool	get_path(int fd, char *direction, char *path)
{
	char	*line;

	line = get_next_line(fd);
	while (strcmp(line, "\n") == 0)
		line = get_next_line(fd);
	if (strcmp(line, direction) == 0)
		path = ft_strdup(*(line + 3));
	else
		return (print_error(INVALID_INFO), false);
	return (true);
}

static bool	get_color_code(int fd, char *direction, int *code)
{
	char	*line;
	char	*color;
	int		i;
	int		n;

	i = 2;
	n = 0;
	code = (int)malloc(sizeof(int) * 3);
	if (!code)
		return (false);
	line = get_next_line(fd);
	while (strcmp(line, "\n") == 0)
		line = get_next_line(fd);
	if (strcmp(line, direction) != 0)
		return (print_error(INVALID_INFO), false);
	while (line[i] && line[i + 1] && n <= 3)
	{
		line = &line[i + 1];
		i = 0;
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (line[i] != ",")
			return (print_error(INVALID_INFO), false);
		color = ft_substr(line, 0, i);
		code[n] = ft_atoi(color);
		if (code[n] < 0 || code[n] > 255)
			return (print_error(INVALID_INFO), false);
		free(color);
		n++;
	}
	if (n > 3 || n < 3)
		return (print_error(INVALID_INFO), false);
	return (true);
}

char	**maploc(int fd, int count_line, t_map *map)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(char *) * (count_line + 1));
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (count_line > ++i)
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

bool	get_map(t_map *map, char *path, int fd)
{
	int		fd_tmp;
	char	*line;
	int		count_line;

	fd_tmp = fd;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd_tmp);
		count_line++;
		free(line);
	}
	map->map_tab = maploc(fd, count_line, map);
	if (!map->map_tab)
		return (false);
	return (true);
}

bool	read_file(t_map *map, char *map_path)
{
	int	fd;
	int	i;

	fd = open(map_path, O_RDONLY);
	if (!get_path(fd, "NO ", map->no_path))
		return (false);
	if (!get_path(fd, "SO ", map->so_path))
		return (false);
	if (!get_path(fd, "EA ", map->ea_path))
		return (false);
	if (!get_path(fd, "WE ", map->we_path))
		return (false);
	if (!get_color_code(fd, "C ", map->c_code))
		return (false);
	if (!get_color_code(fd, "F ", map->f_code))
		return (false);
	if (!get_map(map, map_path, fd))
		return (false);
	close(fd);
	return (true);
}
