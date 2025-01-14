/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:31:05 by romain            #+#    #+#             */
/*   Updated: 2025/01/15 14:30:54 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
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

enum		e_error
{
	PROBLEM_ARGUMENTS,
	OPEN_FAILED,
	INVALID_CHARACTER_ON_MAP,
	INVALID_INFO,
};

enum		e_img
{
	WALL_N,
	WALL_S,
	WALL_W,
	WALL_E,
	// FLOOR,
	// CEILING,
};

typedef struct s_win
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_win;

typedef struct s_map
{
	char	**map_tab;

	int		line_map;
	int		column_map;
	int		player_nbr;

	// void	*wall;
	// void	*floor;
	// void	*playern;
	// void	*players;
	// void	*playere;
	// void	*playerw;

	int		player_x;
	int		player_y;
	int		player_direction_x;
	int		player_direction_y;
	int		next_x;
	int		next_y;

	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	int		*c_color;
	int		*f_color;

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
int			test_file(char *argv);

// ERROR.C
char		print_error(int *error);

// MAP.C
void		load_map(t_map *data, char *map);

// UTILS.C
bool		is_valid_char(char c, char *valid_char);
bool		is_space(char c);

// WALL_ERROR.C
bool		check_column(char **column, int y, int x, int size_y);
bool		vertical_check(t_map *map, int y, int x);
bool		check_line(t_map *map, char *line, int x);
bool		horizontal_check(t_map *map, int y, int x);
bool		ft_wall_error(t_map *map);

// INIT_ALL.C
void		init_map_struct(t_map *data);

// MAIN.C

#endif
