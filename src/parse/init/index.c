/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:30:39 by eramusho          #+#    #+#             */
/*   Updated: 2023/11/03 22:31:52 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	init_img_null(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	init_file(t_data *data)
{
	data->cub_path = NULL;
	data->cub_height = 0;
	data->cub_file = NULL;
	data->cub_fd = -42;
	data->map_height = 0;
	data->map_width = 0;
	data->map = NULL;
	data->map_end_idx = 0;
}

void init_player(t_data *data)
{
	data->player_dir = 0;
	data->player_x = 0;
	data->player_y = 0;
}

void init_tex(t_data *data)
{
		data->east_tex = NULL;
	data->north_tex = NULL;
	data->south_tex = NULL;
	data->west_tex = NULL;
	data->tex_size = TILE_WIDTH;
	data->textures = NULL;
	data->tex_pixels = NULL;
	data->tex_x = 0;
	data->tex_y = 0;
	
	data->col_ceiling = NULL;
	data->col_floor = NULL;
	data->col_ceiling_int = 0;
	data->col_floor_int = 0;
}

void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	init_tex(data);
	init_player(data);
	init_file(data);
	init_img_null(&data->image_details);
}
