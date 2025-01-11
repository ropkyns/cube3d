/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:31:05 by romain            #+#    #+#             */
/*   Updated: 2025/01/10 16:09:07 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <stdbool.h>
# include <signal.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include "lib/mlx/mlx.h"
# include "lib/libft/libft.h"

typedef struct		s_win
{
	void	*mlx_ptr;
	void	*mlx_win;
}					t_win;

typedef struct s_map
{
	char	**map;
    
    int     line;
    int     column;
    int     player_nbr;
    
    void	*wall;
	void	*floor;
    void	*playern;
	void	*players;
	void	*playere;
	void	*playerw;

    int		player_x;
	int		player_y;
	int		next_x;
	int		next_y;
    
}           t_map;

typedef struct global
{
    char    *line;
    char    *arg;
    t_map   *map;
}           t_global;


#endif
