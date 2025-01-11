/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:31:05 by romain            #+#    #+#             */
/*   Updated: 2025/01/11 11:58:57 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

# define ESC 65307
# define A 97
# define W 119
# define D 100
# define S 115
# define RIGHT 65361
# define LEFT 65363

typedef struct s_win
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_win;

typedef struct s_map
{
	char	**map;

	int		line;
	int		column;
	int		player_nbr;

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

}			t_map;

typedef struct global
{
	char	*line;
	char	*arg;
	t_map	*map;

}			t_global;

// CHECK_ARGS.C
bool		is_dir(char *arg);
bool		is_good_file(char *arg);

// ERROR.C
char		print_errors(char *error);

// FLOOD_FILL.C
char		**dup_map(t_map *data, char **map);
void		fill(t_map *data, char **map, int y, int x);
bool		check_fill(t_map *data, char **tmp_map);
void		flood_fill(t_map *data);

// MAP.C
void		load_map(t_map *data, char *map);

// MAIN.C
void		init_map_struct(t_map *data);

#endif
