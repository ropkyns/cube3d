/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:44:26 by paulmart          #+#    #+#             */
/*   Updated: 2025/01/22 11:58:22 by rbouquet         ###   ########.fr       */
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

int	test_file(char *argv)
{
	int		fd;
	int		result;
	char	test;

	if (!is_good_file(argv))
	{
		ft_printf("Error\nBad extension\n");
		return (0);
	}
	fd = open(argv, O_RDONLY);
	result = read(fd, &test, 1);
	if (result <= 0)
	{
		if (result == 0)
			ft_printf("Error\nEmpty file\n");
		else if (result < 0)
			ft_printf("Error\nInvalid input\n");
		return (0);
	}
	close(fd);
	return (1);
}
