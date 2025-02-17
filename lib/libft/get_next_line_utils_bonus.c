/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:21:11 by rbouquet          #+#    #+#             */
/*   Updated: 2025/02/17 10:24:36 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	int		len;
	char	*concat;
	int		i;
	int		j;

	len = ft_strlen_gnl(s1) + ft_strlen_gnl((char *)s2);
	concat = malloc(sizeof(char) * (len + 1));
	if (concat == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		concat[i] = s2[j];
		i++;
		j++;
	}
	concat[i] = '\0';
	free(s1);
	return (concat);
}

size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen_gnl((char *)s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, (char *)s, len);
	dup[len] = '\0';
	return (dup);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int					i;
	unsigned char		*destination;
	const unsigned char	*source;

	i = 0;
	destination = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		destination[i] = source[i];
		i++;
		n--;
	}
	return (destination);
}
