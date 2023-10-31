/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:22:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/14 14:31:11 by doduwole         ###   ########.fr       */
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
# else
#  include "../minilibx-linux/mlx.h"
# endif


# define DEBUG 0

enum				e_status
{
	FAILURE = -42,
	SUCCESS = 0,
	TEXTURE_ADDED = 1
};

typedef struct s_wall_img
{
	void	*blocks;
	void	*north;
	void	*east;
	void	*south;
	void	*west;
}	t_wall_img;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

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
void				init_data2(t_data *data);
// ****** extractions *******
int					retrieve_file_data(t_data *data, char **cub_file);
int					set_textures(t_data *data, char *line, int j);
int					add_colors(t_data *data, char *line, int j);
int					add_map(t_data *data, char **cub_file, int i);
// ****** debugger *******
void				debugger(t_data *data);
#endif