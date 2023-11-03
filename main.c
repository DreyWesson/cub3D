/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:27:01 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/03 22:52:10 by oduwoledare      ###   ########.fr       */
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

	next_x = data->player_x + x * 1.05;
	next_y = data->player_y + y * 1.05;
	if (!data->map[(int)(data->player_x + x)][(int)(data->player_y + y)] &&
		!data->map[next_x][next_y])
	{
		data->player_x += x / 4;
		data->player_y += y / 4;
	}
	else if (!data->map[(int)(data->player_x + x)][(int)(data->player_y)] &&
		!data->map[next_x][(int)data->player_y])
		data->player_x += x / 4;
	else if (!data->map[(int)(data->player_x)][(int)(data->player_y + y)] &&
		!data->map[(int)data->player_x][next_y])
		data->player_y += y / 4;
	return (0);
}

void	set_viewing_direction(t_data *data)
{
	if (data->player_dir == EAST || data->player_dir == WEST)
	{
		data->player_view_x = 1;
		data->player_view_y = 0;
		if (data->player_dir == WEST)
			data->player_view_x = -1;
	}
	else
	{
		data->player_view_x = 0;
		data->player_view_y = -1;
		if (data->player_dir == SOUTH)
			data->player_view_y = 1;
	}
}

void	set_camera_plane(t_data *data)
{
	if (data->player_dir == EAST || data->player_dir == WEST)
	{
		data->player_plane_x = 0.0;
		data->player_plane_y = 0.66;
		if (data->player_dir == WEST)
			data->player_plane_y = -0.66;
	}
	else
	{
		data->player_plane_y = 0.0;
		data->player_plane_x = 0.66;
		if (data->player_dir == SOUTH)
			data->player_plane_x = -0.66;
	}
}

int	input(int key, t_data *data)
{
	if (key == ESC)
		end_program(data);
	if (key == W)
		new_position(data, data->player_view_x, data->player_view_y);
	if (key == A)
		new_position(data, -data->player_plane_x, -data->player_plane_y);
	if (key == S)
		new_position(data, -data->player_view_x, -data->player_view_y);
	if (key == D)
		new_position(data, data->player_plane_x, data->player_plane_y);
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
	printf("player_dir: %c\nplayer_x: %d\nplayer_y: %d\nplayer_plane_x: %f\nplayer_plane_y: %f\nplayer_view_x: %f\nplayer_view_y: %f\n\n",data.player_dir, data.player_x, data.player_y, data.player_plane_x, data.player_plane_y, data.player_view_x, data.player_view_y);
	mlx_hook(data.mlx_win, 2, 0, input, (void *)&data);
	mlx_hook(data.mlx_win, 17, 0, end_program, &data);
	mlx_loop_hook(data.mlx_ptr, update, (void *)&data);
	mlx_loop(data.mlx_ptr);
	// When we start handling end program with user input we'll need to remove this
	// free_data(&data);
	return (0);
}
