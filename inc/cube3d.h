/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:31:05 by romain            #+#    #+#             */
/*   Updated: 2025/01/27 14:57:37 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../lib/libft/libft.h"
# include "../lib/mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

# define WIN_LENGHT 1280
# define WIN_HEIGHT 720

# define PI 3.14159265359

enum			e_error
{
	PROBLEM_ARGUMENTS,
	OPEN_FAILED,
	INVALID_CHARACTER_ON_MAP,
	INVALID_INFO,
	INCORRECT_PLAYER,
	ERROR_MALLOC,
	ERROR_MLX,
	BAD_EXTENSION,
	EMPTY_FILE,
	INVALID_INPUT,
};

enum			e_img
{
	WALL_N,
	WALL_S,
	WALL_W,
	WALL_E,
};

typedef struct s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct s_player
{
	// PLAYER
	t_pos		*pos;
	t_pos		*player_dir;
	double		speed;
}				t_player;

typedef struct s_ray
{
}				t_ray;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*mlx_win;
	// int			height_win;
	// int			lenght_win;

}				t_win;

typedef struct s_map
{
	char		**map_tab;

	// MAP_STAT
	int			line_map;
	int			column_map;
	int			height_map;
	int			lenght_map;

	// PLAYER
	t_player	*player;

	// MAP_CUB
	char		*no_path;
	char		*so_path;
	char		*ea_path;
	char		*we_path;
	int			*c_code;
	int			*f_code;
	int			gnl_count;

}				t_map;

typedef struct s_global
{
	char		*line;
	char		*arg;
	t_map		*map;
	t_win		*win;
	t_ray		*ray;

}				t_global;

// INIT_GAME.C
int				ft_launch_game(t_win *win);

// KEYCODE.C
int				key_handler(int keycode, t_global *global);

// CHECK_ARGS.C
// bool		is_dir(char *arg);
bool			is_good_file(char *arg);
int				test_map(char *argv, t_map *map);

// ERROR.C
void			print_error(int error);

// MAP.C
void			start_player_pos(t_map *map, char direction, int i, int j);
bool			map_size(t_map *map, char **array, int i, int j);
bool			ft_resize_map(t_map *map);
char			*ft_resize_line(char *map, int size);

// READ_CUB.C
bool			read_file(t_map *map, char *map_path);
bool			get_map(t_map *map, int fd, char *path);
char			**maploc(int fd, int count_line);

// UTILS.C
bool			is_valid_char(char c, char *valid_char);
bool			is_space(char c);
bool			ft_isdigit_str(char *str);
bool			check_str(char *str, char *valid);

// WALL_ERROR.C
bool			check_line(char **line, int y, int x, int size_y);
bool			correct_line(t_map *map, int y, int x);
bool			ft_wall_error(t_map *map);

// FREE.C
int				free_all(t_global *global);
void			free_tab(char **tab);
int				win_close(t_global *data);

// INIT_ALL.C
void			init_map_struct(t_global *global);
void			init_game_stat(t_win *win);

// MAIN.C

#endif
