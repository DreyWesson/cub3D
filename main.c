/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:27:01 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/07 15:22:08 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

void all_data(t_data *data)
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
	// printf("data->textures: %d\n", data->textures[NO][0]);
	// printf("data->textures: %d\n", data->textures[SO][0]);
	// printf("data->textures: %d\n", data->textures[EA][0]);
	// printf("data->textures: %d\n", data->textures[WE][0]);
	printf("data->tex_size: %d\n", data->tex_size);
	printf("data->tex_pixel former_impl\n");
	printf("data->tex_x: %d\n",data->tex_x);
	printf("data->tex_y: %d\n",data->tex_y);
	printf("\n");
	printf("data->win_height: %d\n", data->win_height);
	printf("data->win_width: %d\n", data->win_width);
	// printf("data->screen_x: %d\n",data->screen_x);
	// printf("data->screen_y: %d\n",data->screen_y);
	// printf("data->frame: %d\n",data->frame);
	printf("\n");
	//printf("Image details addr: %d, size_line: %d, pixel_bits:  %d, endian: %d\n", *(data->image_details.addr), data->image_details.size_line, data->image_details.pixel_bits, data->image_details.endian);
	printf("\n");
	// printf("TEX_NO addr: %d, size_line: %d, pixel_bits: %d tex_h: %d, tex_w: %d, endian: %d\n", *(data->tex_no.addr), data->tex_no.size_line, data->tex_no.pixel_bits, data->tex_no.tex_height, data->tex_no.tex_width, data->tex_no.endian);
	// printf("TEX_SO addr: %d, size_line: %d, pixel_bits: %d tex_h: %d, tex_w: %d, endian: %d\n", *(data->tex_so.addr), data->tex_so.size_line, data->tex_so.pixel_bits, data->tex_so.tex_height, data->tex_so.tex_width, data->tex_so.endian);
	// printf("TEX_WE addr: %d, size_line: %d, pixel_bits: %d tex_h: %d, tex_w: %d, endian: %d\n", *(data->tex_we.addr), data->tex_we.size_line, data->tex_we.pixel_bits, data->tex_we.tex_height, data->tex_we.tex_width, data->tex_we.endian);
	// printf("TEX_EA addr: %d, size_line: %d, pixel_bits: %d tex_h: %d, tex_w: %d, endian: %d\n", *(data->tex_ea.addr), data->tex_ea.size_line, data->tex_ea.pixel_bits, data->tex_ea.tex_height, data->tex_ea.tex_width, data->tex_ea.endian);
	// printf("data->col_ceiling %d %d %d\n", data->col_ceiling[0], data->col_ceiling[1], data->col_ceiling[2]);
	// printf("data->col_floor %d %d %d\n", data->col_floor[0], data->col_floor[1], data->col_floor[2]);
	// printf("data->col_ceiling_int %d\n",  data->col_ceiling_int);
	// printf("data->col_floor_int %d\n", data->col_floor_int);
	printf("\n");
	//printf("PLAYER dir: %c, x: %d, y: %d, view_y: %f, view_x: %f, plane_y: %f, plane_x: %f\n", data->player.dir,data->player.x, data->player.y, data->player.view_x, data->player.view_y, data->player.plane_y, data->player.plane_x);
	printf("\n");
	// printf("data->tex_h %d\n", data->tex_h);
	// printf("data->tex_w %d\n", data->tex_w);
	printf("\n");
	// printf("sidedist_x: %f, sidedist_y: %f, deltadist_y: %f, deltadist_x: %f\n",data->sidedist_x, data->sidedist_y, data->deltadist_y, data->deltadist_x);
	printf("\n");
	// printf("data->hit: %d data->its: %d data->map_x: %d data->map_y: %d data->line_height: %d data->draw_start: %d data->draw_end: %d data->side: %d data->step_x: %d data->step_y: %d data->wall_color: %d\n", data->hit, data->its, data->map_x, data->map_y, data->line_height, data->draw_start, data->draw_end, data->side, data->step_x, data->step_y, data->wall_color);
	printf("\n");
	// printf("data->camera_x: %f, data->ray_dir_x: %f, data->ray_dir_y: %f, data->perpwalldist: %f, data->wall_hit: %f\n",data->camera_x, data->ray_dir_x, data->ray_dir_y, data->perpwalldist, data->wall_hit);
	// printf("TEX_FLOOR addr: %d, size_line: %d, pixel_bits: %d tex_h: %d, tex_w: %d, endian: %d\n", *(data->tex_floor.addr), data->tex_floor.size_line, data->tex_floor.pixel_bits, data->tex_floor.tex_height, data->tex_floor.tex_width, data->tex_floor.endian);
	// printf("TEX_CEIL addr: %d, size_line: %d, pixel_bits: %d tex_h: %d, tex_w: %d, endian: %d\n", *(data->tex_ceil.addr), data->tex_ceil.size_line, data->tex_ceil.pixel_bits, data->tex_ceil.tex_height, data->tex_ceil.tex_width, data->tex_ceil.endian);
}

int	update(t_data *data)
{
	(void)data;
	return (0);
}

int	end_program(t_data *data)
{
	clean_exit(data, 0);
	return (0);
}

static int	key_release_handler(int key, t_data *data)
{
	if (key == ESC)
		end_program(data);
	if (key == W && data->player.move_y == 1)
		data->player.move_y = 0;
	if (key == S && data->player.move_y == -1)
		data->player.move_y = 0;
	if (key == A && data->player.move_x == -1)
		data->player.move_x += 1;
	if (key == D && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (key == ARROW_LEFT && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == ARROW_RIGHT && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}

static int	key_press_handler(int key, t_data *data)
{
	if (key == ESC)
		end_program(data);
	if (key == ARROW_LEFT)
		data->player.rotate -= 1;
	if (key == ARROW_RIGHT)
		data->player.rotate += 1;
	if (key == W)
		data->player.move_y = 1;
	if (key == A)
		data->player.move_x = -1;
	if (key == S)
		data->player.move_y = -1;
	if (key == D)
		data->player.move_x = 1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
			return (ft_error("Wrong arguments - pass ./cub3d ./path_to_map"));
	ft_memset((void *)&data, 0, sizeof(data));
	if (parsing(&data, argv) == FAILURE)
		return (free_data(&data), FAILURE);
	build_graphics(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press_handler, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, key_release_handler, &data);
	// mlx_hook(data.mlx_win, 2, 0, input, (void *)&data);
	mlx_hook(data.mlx_win, 17, 0, end_program, &data);
	mlx_loop_hook(data.mlx_ptr, update, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
