/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:30:39 by eramusho          #+#    #+#             */
/*   Updated: 2023/11/01 00:33:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	init_data(t_data *data)
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
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
}
