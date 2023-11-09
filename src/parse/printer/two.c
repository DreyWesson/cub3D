/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:21:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 11:10:16 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void print_map(t_data *data, char *str)
{
		printf("\033[1;33m""\n%s:\n""\033[0m", str);
		print_array_2d_newline(data->map);
		printf("\n");    
}

void print_all_data(t_data *data)
{
	printf("data->cub_path: %s\n", data->cub_path);
	printf("data->cub_height: %d\n",data->cub_height);
	printf("data->map_height %d\n", data->map_height);
	printf("data->map_width %d\n", data->map_width);
	printf("\n");
	printf("data->north_tex: %s\n",data->north_tex);
	printf("data->south_tex: %s\n",data->south_tex);
	printf("data->east_tex: %s\n",data->east_tex);
	printf("data->west_tex: %s\n",data->west_tex);
	printf("data->textures: %d\n", data->textures[0][0]);
	printf("data->textures: %d\n", data->textures[1][0]);
	printf("data->textures: %d\n", data->textures[2][0]);
	printf("data->textures: %d\n", data->textures[3][0]);
	printf("data->tex_size: %d\n", data->tex_size);
	printf("data->tex_x: %d\n",data->tex_x);
	printf("data->tex_y: %d\n",data->tex_y);
	printf("\n");
	printf("data->win_height: %d\n", data->win_height);
	printf("data->win_width: %d\n", data->win_width);
	printf("\n");
	printf("\n");
	printf("data->col_ceiling %d %d %d\n", data->col_ceiling[0], data->col_ceiling[1], data->col_ceiling[2]);
	printf("data->col_floor %d %d %d\n", data->col_floor[0], data->col_floor[1], data->col_floor[2]);
	printf("data->col_ceiling_int %d\n",  data->col_ceiling_int);
	printf("data->col_floor_int %d\n", data->col_floor_int);
	printf("\n");
	printf("PLAYER dir: %c, x: %d, y: %d, view_y: %f, view_x: %f, plane_y: %f, plane_x: %f, dir_x: %f, dir_y: %f\n", data->player.dir,data->player.x, data->player.y, data->player.pos_x, data->player.pos_y, data->player.plane_y, data->player.plane_x, data->player.dir_x, data->player.dir_y);
	printf("\n");
	printf("data->tile_h %d\n", data->tile_h);
	printf("data->tile_w %d\n", data->tile_w);
	printf("tex_index: %d, tex_step: %f, tex_pos: %f\n", data->tex_index, data->tex_step, data->tex_pos);
	printf("\n");
	printf("\n");
	printf("\n");
}
