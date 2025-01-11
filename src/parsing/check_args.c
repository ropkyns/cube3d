/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:44:26 by paulmart          #+#    #+#             */
/*   Updated: 2025/01/11 14:09:20 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

bool	is_dir(char *arg)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(arg, __O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		ret = true;
	}
	return (ret);
}

bool	is_good_file(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (ft_strcmp(&arg[len - 4], ".cub") == 0
		|| ft_strcmp(&arg[len - 4], ".xpm") == 0)
		return (true);
	return (false);
}
