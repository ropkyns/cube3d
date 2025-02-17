/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:31:05 by romain            #+#    #+#             */
/*   Updated: 2025/02/17 12:08:35 by paulmart         ###   ########.fr       */
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
	ERROR_INIT_IMG,
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
	t_pos		*dir;
	t_pos		*plan_vect;
	char		direction;
	double		speed;
	double		rotation_speed;
}				t_player;

typedef struct s_ray
{
	int			curr_x;
	int			map_x;
	int			map_y;
	double		cam_x;
	t_pos		*ray_dir;
	t_pos		*side_dist;
	t_pos		*delta_dist;
	double		prep_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			height_win;
	int			lenght_win;

}				t_win;

typedef struct s_map
{
	char		**map_tab;

	// MAP_STAT
	int			line_map;
	int			column_map;
	int			height_map;
	int			lenght_map;

	// MAP_CUB
	char		*no_path;
	char		*so_path;
	char		*ea_path;
	char		*we_path;
	int			*c_code;
	int			*f_code;
	int			gnl_count;

}				t_map;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			height;
	int			width;

}				t_image;

typedef struct s_global
{
	char		*line;
	char		*arg;
	t_map		*map;
	t_player	*player;
	t_win		*win;
	// t_ray		*ray;
	t_image		*img[5];

}				t_global;

// INIT_GAME.C
int				ft_launch_game(t_global *global);

// KEYCODE.C
int				key_handler(int keycode, t_global *global);
int				move_mouse(int x, int y, t_global *global);

// CHECK_ARGS.C
// bool		is_dir(char *arg);
bool			is_good_file(char *arg);
int				test_map(char *argv, t_global *global);

// ERROR.C
void			print_error(int error);

// MAP.C
void			start_player_pos(t_global *global, char direction, int i,
					int j);
bool			map_size(t_global *global, char **array, int i, int j);
bool			ft_resize_map(t_global *global);
char			*ft_resize_line(char *map, int size);
void			set_player_stat(t_player *player, double dir_y, double p_x,
					double p_y);

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
bool			correct_line(t_global *global, int y, int x);
bool			ft_wall_error(t_global *global);

// RAYCASTING.C
void			raycasting(t_global *glob, t_ray *ray);

// DRAW.C
void			draw_texture(t_global *glob, t_ray *ray, t_player *player);
void			draw_line(t_global *glob, t_ray *ray, double wall_x, int e_img);

// RENDU.C
int				render(t_global *global);
void			background(t_global *global);
void			img_pix_put(t_global *global, int x, int y, int color);

// FREE.C
int				free_all(t_global *global);
void			free_tab(char **tab);

// INIT_ALL.C
void			init_map_struct(t_global *global);
void			init_game_stat(t_global *global);

// MAIN.C

#endif
