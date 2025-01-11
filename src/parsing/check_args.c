/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:44:26 by jchen             #+#    #+#             */
/*   Updated: 2025/01/11 11:50:22 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

bool	is_dir(char *arg)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(arg, O_DIRECTORY);
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
	if (arg[len - 4] != '.' || arg[len - 3] != 'c' || arg[len - 2] != 'u'
		|| arg[len - 1] != 'b')
		return (false);
	if (arg[len - 4] != '.' || arg[len - 3] != 'x' || arg[len - 2] != 'p'
		|| arg[len - 1] != 'm')
		return (false);
	return (true);
}
