/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:27:01 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/08 13:24:47 by loandrad         ###   ########.fr       */
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
	printf("data->textures: %d\n", data->textures[0][0]);
	printf("data->textures: %d\n", data->textures[1][0]);
	printf("data->textures: %d\n", data->textures[2][0]);
	printf("data->textures: %d\n", data->textures[3][0]);
	printf("data->tex_size: %d\n", data->tex_size);
	printf("data->tex_pixel former_impl\n");
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

void	init_img(t_data *data, t_img *image, int width, int height)
{
	ft_memset((void *)image, 0, sizeof(*image));
	image->img = mlx_new_image(data->mlx_ptr, width, height);
	if (image->img == NULL)
		clean_exit(data, FAILURE);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

static void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->tex_pixels[y][x] > 0)
		set_image_pixel(image, x, y, data->tex_pixels[y][x]);
	else if (y < data->win_height / 2)
		set_image_pixel(image, x, y, data->col_ceiling_int);
	else if (y < data->win_height - 1)
		set_image_pixel(image, x, y, data->col_floor_int);
}

void	render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(data, &image, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, image.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, image.img);
}

static void	get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->tex_index = WEST;
		else
			data->tex_index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->tex_index = SOUTH;
		else
			data->tex_index = NORTH;
	}
}

void	update_texture_pixels(t_data *data, t_ray *ray, int x)
{
	int	y;
	int	color;

	get_texture_index(data, ray);
	data->tex_x = (int)(ray->wall_x * data->tex_size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		data->tex_x = data->tex_size - data->tex_x - 1;
	data->tex_step = 1.0 * data->tex_size / ray->line_height;
	data->tex_pos = (ray->draw_start - data->win_height / 2
			+ ray->line_height / 2) * data->tex_step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		data->tex_y = (int)data->tex_pos & (data->tex_size - 1);
		data->tex_pos += data->tex_step;
		color = data->textures[data->tex_index][data->tex_size
			* data->tex_y + data->tex_x];
		if (data->tex_index == NORTH || data->tex_index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->tex_pixels[y][x] = color;
		y++;
	}
}

static void	calculate_line_height(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(data->win_height / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_end >= data->win_height)
		ray->draw_end = data->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = data->player.pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = data->player.pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

static void	perform_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25
			|| ray->map_y > data->map_height - 0.25
			|| ray->map_x > data->map_width - 1.25)
			break ;
		else if (data->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}

static void	set_dda(t_ray *ray, t_data *data)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (data->player.pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x
			= (ray->map_x + 1.0 - data->player.pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (data->player.pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y
			= (ray->map_y + 1.0 - data->player.pos_y) * ray->deltadist_y;
	}
}

static void	init_raycasting_info(int x, t_ray *ray, t_data *data)
{
	ft_memset((void *)&data->ray, 0, sizeof(data->ray));
	ray->camera_x = 2 * x / (double)data->win_width - 1;
	ray->dir_x = data->player.dir_x + data->player.plane_x * ray->camera_x;
	ray->dir_y = data->player.dir_y + data->player.plane_y * ray->camera_x;
	ray->map_x = (int)data->player.pos_x;
	ray->map_y = (int)data->player.pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

int	raycasting(t_data *data)
{
	t_ray	*ray;
	int		x;

	x = 0;
	ray = &data->ray;
	while (x < data->win_width)
	{
		init_raycasting_info(x, ray, data);
		set_dda(ray, data);
		perform_dda(data, ray);
		calculate_line_height(ray, data);
		update_texture_pixels(data, ray, x);
		x++;
	}
	return (SUCCESS);
}

static int	rotate_left_right(t_data *data, double rotspeed)
{
	double		tmp_x;

	tmp_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(rotspeed)
		- data->player.dir_y * sin(rotspeed);
	data->player.dir_y
		= tmp_x * sin(rotspeed) + data->player.dir_y * cos(rotspeed);
	tmp_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rotspeed)
		- data->player.plane_y * sin(rotspeed);
	data->player.plane_y
		= tmp_x * sin(rotspeed) + data->player.plane_y * cos(rotspeed);
	return (1);
}

int	rotate_player(t_data *data, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTSPEED * rotdir;
	moved += rotate_left_right(data, rotspeed);
	return (moved);
}

static bool	is_valid_pos_in_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->map_width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->map_height -0.25)
		return (false);
	return (true);
}

static bool	is_valid_pos(t_data *data, double x, double y)
{
	if (is_valid_pos_in_map(data, x, y))
		return (true);
	return (false);
}

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}

static int	move_player_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * MOVESPEED;
	new_y = data->player.pos_y + data->player.dir_y * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_player_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * MOVESPEED;
	new_y = data->player.pos_y - data->player.dir_y * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_player_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_y * MOVESPEED;
	new_y = data->player.pos_y - data->player.dir_x * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_player_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_y * MOVESPEED;
	new_y = data->player.pos_y + data->player.dir_x * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved += move_player_forward(data);
	if (data->player.move_y == -1)
		moved += move_player_backward(data);
	if (data->player.move_x == -1)
		moved += move_player_left(data);
	if (data->player.move_x == 1)
		moved += move_player_right(data);
	if (data->player.rotate != 0)
		moved += rotate_player(data, data->player.rotate);
	return (moved);
}

void	render_images(t_data *data)
{
	init_texture_pixels(data);
	ft_memset((void *)&data->ray, 0, sizeof(data->ray));
	raycasting(data);
	render_frame(data);
}

int	update(t_data *data)
{
	data->player.has_moved += move_player(data);
	if (data->player.has_moved == 0)
		return (0);
	render_images(data);
	return (0);
}

int build_graphics(t_data *data)
{
	game_init(data);
	texture_init(data);
	render_images(data);
	return (1);
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
	mlx_hook(data.mlx_win, 17, 0, end_program, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press_handler, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, key_release_handler, &data);
	mlx_loop_hook(data.mlx_ptr, update, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (free_data(&data), SUCCESS);
}
