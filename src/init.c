/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:30:39 by eramusho          #+#    #+#             */
/*   Updated: 2023/10/09 14:12:49 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_data(t_data *d)
{
	d->game = ft_calloc(1, sizeof(t_game));
	d->player = ft_calloc(1, sizeof(t_player));
	d->img = ft_calloc(1, sizeof(t_img));
	d->img_game = ft_calloc(1, sizeof(t_img));
	d->rays_dist = ft_calloc(1, sizeof(double) * WIN_WIDTH);
	d->rays_x = ft_calloc(1, sizeof(double) * WIN_WIDTH);
	d->rays_y = ft_calloc(1, sizeof(double) * WIN_WIDTH);
	d->ray_angle = ft_calloc(1, sizeof(double) * WIN_WIDTH);
	d->is_horizontal = ft_calloc(1, sizeof(int) * WIN_WIDTH);
}

void	init_imgs(t_data *d)
{
	d->img_game->img = mlx_new_image(d->mlx, WIN_WIDTH, WIN_HEIGHT);
	d->img_game->addr = (int *)mlx_get_data_addr(d->img_game->img, \
&d->img_game->bits_per_pixel, &d->img_game->line_length, &d->img_game->endian);
	d->img->img = mlx_new_image(d->mlx, MINI_S * MINI_M, MINI_S * MINI_M);
	d->img->addr = (int *)mlx_get_data_addr(d->img->img, \
&d->img->bits_per_pixel, &d->img->line_length, &d->img->endian);
}

void	init_map_data(t_dt *data)
{
	data->cub_path = NULL;
	data->cub_height = 0;
	data->cub_file = NULL;
	data->cub_fd = -42;

	data->tex_east = NULL;
	data->tex_north = NULL;
	data->tex_south = NULL;
	data->tex_west = NULL;

	data->col_ceiling = NULL;
	data->col_floor = NULL;
	data->col_ceiling_int = 0;
	data->col_floor_int = 0;

	data->map_height = 0;
	data->map_width = 0;
	data->map = NULL;
	data->map_end_idx = 0;

	data->player_dir = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->player_pos_x = 0;
	data->player_pos_y = 0;
	data->player_dir_x = 0;
	data->player_dir_y = 0;
	data->player_plane_x = 0;
	data->player_plane_y = 0;

	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
}
