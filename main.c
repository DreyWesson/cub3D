/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:27:01 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/04 11:02:47 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

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

int	new_position(t_data *data, double x, double y)
{
	int	next_x;
	int	next_y;

	next_x = data->player.x + x * 1.05;
	next_y = data->player.y + y * 1.05;
	if (!data->map[(int)(data->player.x + x)][(int)(data->player.y + y)] &&
		!data->map[next_x][next_y])
	{
		data->player.x += x / 4;
		data->player.y += y / 4;
	}
	else if (!data->map[(int)(data->player.x + x)][(int)(data->player.y)] &&
		!data->map[next_x][(int)data->player.y])
		data->player.x += x / 4;
	else if (!data->map[(int)(data->player.x)][(int)(data->player.y + y)] &&
		!data->map[(int)data->player.x][next_y])
		data->player.y += y / 4;
	return (0);
}

void	set_viewing_direction(t_data *data)
{
	if (data->player.dir == EAST || data->player.dir == WEST)
	{
		data->player.view_x = 1;
		data->player.view_y = 0;
		if (data->player.dir == WEST)
			data->player.view_x = -1;
	}
	else
	{
		data->player.view_x = 0;
		data->player.view_y = -1;
		if (data->player.dir == SOUTH)
			data->player.view_y = 1;
	}
}

void	set_camera_plane(t_data *data)
{
	if (data->player.dir == EAST || data->player.dir == WEST)
	{
		data->player.plane_x = 0.0;
		data->player.plane_y = 0.66;
		if (data->player.dir == WEST)
			data->player.plane_y = -0.66;
	}
	else
	{
		data->player.plane_y = 0.0;
		data->player.plane_x = 0.66;
		if (data->player.dir == SOUTH)
			data->player.plane_x = -0.66;
	}
}

int	input(int key, t_data *data)
{
	if (key == ESC)
		end_program(data);
	if (key == W)
		new_position(data, data->player.view_x, data->player.view_y);
	if (key == A)
		new_position(data, -data->player.plane_x, -data->player.plane_y);
	if (key == S)
		new_position(data, -data->player.view_x, -data->player.view_y);
	if (key == D)
		new_position(data, data->player.plane_x, data->player.plane_y);
	// ft_render(data);
	return (0);
}


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
			return (ft_error("Wrong arguments - pass ./cub3d ./path_to_map"));
	if (parsing(&data, argv) == FAILURE)
		return (free_data(&data), FAILURE);

	build_graphics(&data);
	set_viewing_direction(&data);
	set_camera_plane(&data);
	printf("player_dir: %c\nplayer_x: %d\nplayer_y: %d\nplayer_plane_x: %f\nplayer_plane_y: %f\nplayer_view_x: %f\nplayer_view_y: %f\n\n",data.player.dir, data.player.x, data.player.y, data.player.plane_x, data.player.plane_y, data.player.view_x, data.player.view_y);
	mlx_hook(data.mlx_win, 2, 0, input, (void *)&data);
	mlx_hook(data.mlx_win, 17, 0, end_program, &data);
	mlx_loop_hook(data.mlx_ptr, update, (void *)&data);
	mlx_loop(data.mlx_ptr);
	// When we start handling end program with user input we'll need to remove this
	// free_data(&data);
	return (0);
}
