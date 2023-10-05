/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:05:33 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/03 12:53:41 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

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

# ifdef __APPLE__
#  define A 0
#  define S 1
#  define D 2
#  define W 13
#  define R 15
#  define X 53
# else
#  define A 97
#  define S 115
#  define D 100
#  define W 119
#  define R 15
#  define X 65307
# endif

# define IMG_SIZE 64

enum	e_pos
{
	NORTH = 'N',
	SOUTH = 'S',
	EAST = 'E',
	WEST = 'W'
} t_pos;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	// PLAYER_POS = t_pos,

}	t_tiletype;

typedef enum e_compass
{
	UP = 'U',
	DOWN = 'D',
	LEFT = 'L',
	RIGHT = 'R'
}	t_compass;

typedef struct s_axis
{
	int	x;
	int	y;
}	t_axis;

/* Color */
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_cell
{
	char			val;
	int				x_axis;
	int				y_axis;
	char			status;
	t_tiletype		type;
	t_tiletype		cache;
	t_axis			position;
	struct s_cell	*up;
	struct s_cell	*down;
	struct s_cell	*left;
	struct s_cell	*right;
}	t_cell;

typedef struct s_nodes
{
	t_cell			*cell;
	struct s_nodes	*next;
	struct s_nodes	*prev;
}	t_nodes;

typedef struct s_tile
{
	t_axis			position;
	t_tiletype		type;
	t_tiletype		mem_type;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

enum e_keycode
{
	KEY_UP = W,
	KEY_DOWN = S,
	KEY_LEFT = A,
	KEY_RIGHT = D,
	RESET = R,
	ESC = X
};

typedef struct s_game
{
	void			*mlx;
	void			*window;
	int				collects;
	int				moves;
	void			*door_open_img;
	void			*door_close_img;;
	t_cell			**grid;
	t_axis			window_size;
	t_axis			img_size;
	t_cell			current_cell;
}	t_game;

/**
 * UTILS FUNCTION
*/
int			ft_error(char *message);
void		ft_warning(char *message);
int			ft_trim(char const *s1, char const *set);
int			handle_validation(int argc, char **argv, t_game *game);
/**
 * MAP -> Reader
*/
int			handle_map(char **argv, t_game *game);
t_cell		**validate_map(char **map, t_nodes **queue);
int			line_counter(char *file_name);
size_t		ft_strlen_ln(const char *str);
char		**map_reader(char *s, int row_nbr);
/**
 * MAP -> Validator
*/
int			is_valid(char *str);
int			validate_composition(char s);
int			validate_walls(char *s, int row_nbr, int j, int i);
// void		save_start(int x, int y, t_details *details);


#endif