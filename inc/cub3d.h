/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:22:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/06 20:31:15 by doduwole         ###   ########.fr       */
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
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

/**
 * START
*/
# include <math.h>

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
# define FOV 1.0471975512 //Field of View -> 60° (common first-person games) in radian, check later if 90° is better
# define MINI_M 30 //size Minimap
# define MINI_S 6 // scale Minimap
# define VIEW_RANGE 1// more visible at greater distance the higher view_range is -> fog effect

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
}				t_img;

typedef struct s_sprite
{
	int				x; // location of the sprite x & y
	int				y;
	int				distance; // knowing the distance you can render the sprites size correctly
	t_img			*north; // important cause every side has it's own texture therefore the img_pointer
	t_img			*south;
	t_img			*west;
	t_img			*east;
}				t_sprite;

typedef struct minimap
{
	int					p_pos_box;
	int					box;
}				t_minimap;

typedef struct s_player
{
	void			*p_img;// img_pointer
	int				width;// width & height important rendering on minimap and for collision detection
	int				height;
	double			x;// player pos x & y, important to check for movement
	double			y;
	int				turn_direction;// determine which direction to update the players pos. -> are flags
	int				walk_direction;
	int				rotation_direction;
	double			angle;
	char			cardinal_dir;//view // N, E, S, W

}				t_player;

typedef struct s_game
{
	char			**map;// map representatiton ---------------------------------------> important for you DRE!
	int				map_height;
	int				map_width;
	char			*north;//important for walls cause every side has it's own texture therefore the img_pointer
	char			*south;
	char			*west;
	char			*east;
	int				floor_color; // RGB color for the floor
	int				ceiling_color;// RGB color for the ceiling
}				t_game;

typedef struct s_distance // it's used for calculations
{
	double			x_ray_dis_wall;// distance to hit the wall
	double			y_ray_dis_wall;
	double			x_delta;
	double			y_delta;
	int				ray_len;// keep track of the number of steps the ray has taken or reached maximum len
}				t_distance;

typedef struct s_data
{
	int			box_size;
	void		*mlx;
	void		*win;
	t_game		*game;
	t_sprite	*sprite;
	t_player	*player;
	t_img		*img;//mini map
	t_img		*img_game;//game
	t_minimap	*minimap;
	double		*rays_dist;//distance player until hit the wall
	double		*rays_x;// intersection points with the wall
	double		*rays_y;
	double		*ray_angle;// angle of which ray was cast
	int			*is_horizontal;//true or false -> true ray hit horizontal wall, flase ray hit vertical wall
}				t_data;

/**
 * END
*/

typedef struct s_compass
{
    int n;
    int s;
    int e;
    int w;
} t_compass;

int     handle_validation(int argc, char **argv);
int     ft_error(char *message);
void    ft_warning(char *message);
int	validate_arg(int argc, char **argv);
int	handle_map(char **argv);
size_t	ft_strlen_ln(const char *str);
int	line_counter(char *file_name);
void	check_fd(int fd);
void	print_grid(char **map, int row_nbr);
void	ft_free2d(char **ptr);
void	free_exit(char **map);
int	is_valid(char *str);

/**
 * ERMAL
*/


#endif