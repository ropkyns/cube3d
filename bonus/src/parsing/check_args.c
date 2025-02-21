/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:44:26 by paulmart          #+#    #+#             */
/*   Updated: 2025/02/18 16:08:38 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

bool	is_good_file(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (ft_strcmp(&arg[len - 4], ".cub") == 0 || ft_strcmp(&arg[len - 4],
			".xpm") == 0)
		return (true);
	return (false);
}

int	test_map(char *argv, t_global *global)
{
	int		fd;
	int		result;
	char	test;

	if (!is_good_file(argv))
		return (print_error(BAD_EXTENSION), false);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (print_error(OPEN_FAILED), false);
	result = read(fd, &test, 1);
	if (result <= 0)
	{
		if (result == 0)
			print_error(EMPTY_FILE);
		else if (result < 0)
			print_error(INVALID_INPUT);
		return (close(fd), false);
	}
	close(fd);
	global->map->gnl_count = 1;
	if (!read_file(global->map, argv))
		return (false);
	if (!ft_resize_map(global))
		return (false);
	return (true);
}
