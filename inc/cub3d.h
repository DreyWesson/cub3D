/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:22:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/03 15:17:03 by doduwole         ###   ########.fr       */
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

typedef struct s_game
{
	void			*mlx;
	void			*window;
}	t_game;

typedef struct s_compass
{
    int n;
    int s;
    int e;
    int w;
} t_compass;

int     handle_validation(int argc, char **argv, t_game *game);
int     ft_error(char *message);
void    ft_warning(char *message);
int	validate_arg(int argc, char **argv);
int	handle_map(char **argv, t_game *game);
size_t	ft_strlen_ln(const char *str);
int	line_counter(char *file_name);
void	check_fd(int fd);
void	print_grid(char **map, int row_nbr);
void	ft_free2d(char **ptr);
void	free_exit(char **map);

#endif