/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:44:26 by paulmart          #+#    #+#             */
/*   Updated: 2025/01/31 13:13:02 by rbouquet         ###   ########.fr       */
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
	{
		print_error(BAD_EXTENSION);
		return (false);
	}
	fd = open(argv, O_RDONLY);
	result = read(fd, &test, 1);
	if (result <= 0)
	{
		if (result == 0)
			print_error(EMPTY_FILE);
		else if (result < 0)
			print_error(INVALID_INPUT);
		return (false);
	}
	if (!read_file(global->map, argv))
		return (false);
	if (!ft_resize_map(global))
		return (false);
	close(fd);
	return (true);
}
