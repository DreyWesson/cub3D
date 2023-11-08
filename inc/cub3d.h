/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:22:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/08 11:46:59 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

// MLX_LIB
# ifdef __APPLE__
#  include "../mlx/mlx.h"
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define ESC 53
#  define ARROW_LEFT 123
#  define ARROW_RIGHT 124
#  define ARROW_DOWN 125
#  define ARROW_UP 123


# else
#  include "../minilibx-linux/mlx.h"
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define ESC 65307
#  define ARROW_LEFT 65361
#  define ARROW_RIGHT 65363
#  define X 33
# endif


# define WIN_WIDTH 1200
# define WIN_HEIGHT 900
# define TILE_W  128
# define TILE_H 128
# define DEBUG 0
# define MOVESPEED 0.0275
# define ROTSPEED 0.015

enum				e_status
{
	FAILURE = -42,
	SUCCESS = 0,
	TEXTURE_ADDED = 1
};

enum e_tex_idx
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		endian;
	int		size_line;
	int		pixel_bits;
}	t_img;


typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_player
{
	char			dir;
	int				x;
	int				y;
	double			pos_y;
	double			pos_x;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				move_x;
	int				move_y;
	int				rotate;
	int				has_moved;
} t_player;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_data
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
	char			*north_tex;
	char			*east_tex;
	char			*south_tex;
	char			*west_tex;
	int		**textures;
	int				tex_size;
	int		**tex_pixels;
		int		tex_x;
	int		tex_y;

	int		win_height;
	int		win_width;
	//t_img image_details;


	// ------- color related data -------
	int				*col_ceiling;
	int				*col_floor;
	int				col_ceiling_int;
	int				col_floor_int;
	t_player 		player;
	void			*mlx_ptr;
	void			*mlx_win;
	int				tile_w;
	int 			tile_h;
	int		tex_index;
	double	tex_step;
	double	tex_pos;
	t_ray	ray;
}					t_data;

/**
 * ******** PARSING ************
 */
int					parsing(t_data *data, char **argv);
// ***** Validations *******
// int					is_valid_cub(char *str);
int					is_valid_exe(char *str, char *exe);
int					validate_map(t_data *data, char **map);
int					validate_textures(t_data *data);
int					validate_walls(t_data *data);
// ******** Utils *********
void				clean_exit(t_data *data, int exitstatus);
void				check_fd(int fd);
int					line_counter(char *file_name);
size_t				ft_strlen_ln(const char *str);
size_t				ft_strlen_no_newline(const char *str);
size_t				find_max_width(t_data *data, int i);
bool				ft_isspace(char c);
bool				ft_isprint_no_space(int c);
bool				is_texture_or_color(char c);
bool				is_texture(char c1, char c2);
int					is_last_char_one(const char *line);
char				*ft_strdup2(const char *s1, int len);
// ******** Prints *********
int					ft_error(char *message);
void				ft_err(char *message);
void				print_grid(char **map, int row_nbr);
void				print_array_2d(char **array_2d);
void				print_array_2d_newline(char **array_2d);
void				print_map(t_data *data, char *str);
// ******** Free *********
void				ft_free2d(char **ptr);
void				free_data(t_data *data);
void				free_colors(t_data *data);
void				free_textures(t_data *data);
void				free_cub(t_data *data);
void				free_array_2d(void **array_2d);
// **** player dir *****
// void				add_player_direction(t_data *data);
// ****** Map file *******
void				handle_cub(char *cub_path, t_data *data);
void				map_reader(t_data *data);
void				make_map_rectangular(t_data *data);
// ****** Search *******
int					dfs(t_data *data, char **map_clone);
int					flood_fill(char **tab, t_point size, int x, int y);
// ****** init_data2 *******
void				init_data(t_data *data);
// ****** extractions *******
int					retrieve_file_data(t_data *data, char **cub_file);
int					set_textures(t_data *data, char *line, int j);
int					add_colors(t_data *data, char *line, int j);
int					add_map(t_data *data, char **cub_file, int i);
// ****** debugger *******
void				debugger(t_data *data);



// BUILD GRAPHICS
int game_init(t_data *data);
int build_graphics(t_data *data);
void	init_img_null(t_img *img);
void	init_texture_pixels(t_data *data);
void	texture_init(t_data *data);
void	init_texture_img(t_data *data, t_img *image_details, char *path);

#endif