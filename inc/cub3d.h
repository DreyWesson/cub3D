/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:22:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/12 15:56:58 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// MLX_LIB
# ifdef __APPLE__
#  include "../mlx/mlx.h"
# else
#  include "../minilibx-linux/mlx.h"
# endif

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * START
 */
# include <math.h>

# define DEBUG 1

// KEYS //
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define EXIT 69

// MACROS ERMAL
# define TRUE 1
# define FALSE 0
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define PI M_PI // neeeded for rotation
# define ROTATE_SPEED 0.05
# define PLAYER_SPEED 5
# define FOV 1.0471975512 // Field of View
// ->60° (common first - person games) in radian,
// 	check later if 90° is better
# define MINI_M 30 // size Minimap
# define MINI_S 6  // scale Minimap
# define VIEW_RANGE 1
// more visible at greater distance the higher view_range is -> fog effect

// ERMAL STRUCTS //

typedef struct s_img
{
	unsigned int	*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				height;
	int				width;
	int				endian;
	int				img_loaded;
}					t_img;

typedef struct s_sprite
{
	int x; // location of the sprite x & y
	int				y;
	int				distance;
	// knowing the distance you can render the sprites size correctly
	t_img			*north;
	// important cause every side has it's own texture therefore the img_pointer
	t_img			*south;
	t_img			*west;
	t_img			*east;
}					t_sprite;

typedef struct minimap
{
	int				p_pos_box;
	int				box;
}					t_minimap;

typedef struct s_player
{
	void *p_img; // img_pointer
	int				width;
	// width & height important rendering on minimap and for collision detection
	int				height;
	double x; // player pos x & y, important to check for movement
	double			y;
	int turn_direction; // determine which direction to update the players pos.
	// ->are flags int walk_direction;
	int				rotation_direction;
	double			angle;
	char cardinal_dir; // view // N, E, S, W

}					t_player;

typedef struct s_game
{
	char			**map;
	// map representatiton ---------------------------------------> important for you DRE!
	int				map_height;
	int				map_width;
	char			*north;
	// important for walls cause every side has it's own texture therefore the img_pointer
	char			*south;
	char			*west;
	char			*east;
	int floor_color;   // RGB color for the floor
	int ceiling_color; // RGB color for the ceiling
}					t_game;

typedef struct s_distance // it's used for calculations
{
	double x_ray_dis_wall; // distance to hit the wall
	double y_ray_dis_wall;
	double x_delta;
	double y_delta;
	int ray_len;
	// keep track of the number of steps the ray has taken or reached maximum len
}					t_distance;

typedef struct s_data
{
	int				box_size;
	void			*mlx;
	void			*win;
	t_game			*game;
	t_sprite		*sprite;
	t_player		*player;
	t_img *img;      // mini map
	t_img *img_game; // game
	t_minimap		*minimap;
	double *rays_dist; // distance player until hit the wall
	double *rays_x;    // intersection points with the wall
	double			*rays_y;
	double *ray_angle;  // angle of which ray was cast
	int *is_horizontal; // true or false -> true ray hit horizontal wall,
						// flase ray hit vertical wall
}					t_data;

enum				e_status
{
	FAILURE = -42,
	SUCCESS = 0,
	TEXTURE_ADDED = 1
};

typedef struct s_dfs
{
	char			**map;
	int				h;
	int				w;
	int				valid;
	int				dr[4];
	int				dc[4];
}					t_dfs;

typedef struct s_dt
{
	// ------- saved .cub file -------
	char			**cub_file;
	char			*cub_path;
	int				cub_height;
	int				cub_fd;

	//  ****** rectangular map *******
	char			**map;
	int				map_height;
	int				map_width;
	int				map_end_idx;

	// ------- path to texture -------
	char			*tex_north;
	char			*tex_east;
	char			*tex_south;
	char			*tex_west;

	// ------- color related data -------
	int				*col_ceiling;
	int				*col_floor;
	int				col_ceiling_int;
	int				col_floor_int;

	char			player_dir;
	int				player_x;
	int				player_y;

	void			*mlx_ptr;
	void			*mlx_win;
}					t_dt;

/**
 * ******** PARSING ************
 */
int					parsing(t_dt *data, char **argv);
// ***** Validations *******
// int					is_valid_cub(char *str);
int					is_valid_exe(char *str, char *exe);
int					validate_map(t_dt *data, char **map);
int					validate_textures(t_dt *data);
int					validate_walls(t_dt *data);
// ******** Utils *********
void				clean_exit(t_dt *data, int exitstatus);
void				check_fd(int fd);
int					line_counter(char *file_name);
size_t				ft_strlen_ln(const char *str);
size_t				ft_strlen_no_newline(const char *str);
size_t				find_max_width(t_dt *data, int i);
bool				ft_isspace(char c);
bool				ft_isprint_no_space(int c);
bool				is_texture_or_color(char c);
bool				is_texture(char c1, char c2);
int					is_last_char_one(const char *line);
// ******** Prints *********
int					ft_error(char *message);
void				ft_err(char *message);
void				print_grid(char **map, int row_nbr);
void				print_array_2d(char **array_2d);
void				print_array_2d_newline(char **array_2d);
void				print_map(t_dt *data, char *str);
// ******** Free *********
void				ft_free2d(char **ptr);
void				free_data(t_dt *data);
void				free_colors(t_dt *data);
void				free_textures(t_dt *data);
void				free_cub(t_dt *data);
void				free_array_2d(void **array_2d);
// **** player dir *****
// void				add_player_direction(t_dt *data);
// ****** Map file *******
void				handle_cub(char *cub_path, t_dt *data);
void				map_reader(t_dt *data);
void				make_map_rectangular(t_dt *data);
// ****** Search *******
int					dfs(t_dt *data, char **map_clone);
// ****** init_data2 *******
void				init_data2(t_dt *data);
// ****** extractions *******
int					retrieve_file_data(t_dt *data, char **cub_file);
int					set_textures(t_dt *data, char *line, int j);
int					add_colors(t_dt *data, char *line, int j);
int					add_map(t_dt *data, char **cub_file, int i);
// ****** debugger *******
void				debugger(t_dt *data);
#endif