/* ************************************************************************** */
/*                                                                            */
/*                                                       ::     :::::::   */
/*   get_next_line_bonus.c                             +:     +:   +:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:38:17 by rbouquet          #+#    #+#             */
/*   Updated: 2024/06/17 12:09:37 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd);

char	*get_line(int fd, char *stock)
{
	char	*buf;
	int		nb_line;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nb_line = 1;
	while (ft_strchr_gnl(stock, '\n') == 0 && nb_line != 0)
	{
		nb_line = read(fd, buf, BUFFER_SIZE);
		if (nb_line == -1)
		{
			free(buf);
			free(stock);
			return (NULL);
		}
		buf[nb_line] = '\0';
		if (!stock)
			stock = ft_strdup_gnl(buf);
		else
			stock = ft_strjoin_gnl(stock, buf);
	}
	free(buf);
	return (stock);
}

char	*putline(char *stock)
{
	int		len_line;
	char	*next_line;

	len_line = 0;
	if (!(*stock))
		return (NULL);
	while (stock[len_line] != '\n' && stock[len_line])
		len_line++;
	next_line = malloc(sizeof(char) * (len_line + 2));
	if (!next_line)
		return (NULL);
	len_line = 0;
	while (stock[len_line] != '\n' && stock[len_line])
	{
		next_line[len_line] = stock[len_line];
		len_line++;
	}
	if (stock[len_line] == '\n')
	{
		next_line[len_line] = stock[len_line];
		len_line++;
	}
	next_line[len_line] = '\0';
	return (next_line);
}

char	*del_for_next_line(char *stock)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	i++;
	tmp = malloc(sizeof(char) * (ft_strlen_gnl(stock) - i + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	while (stock[i])
		tmp[j++] = stock[i++];
	tmp[j] = '\0';
	free(stock);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = get_line(fd, stock);
	if (!stock)
		return (NULL);
	next_line = putline(stock);
	stock = del_for_next_line(stock);
	return (next_line);
}
