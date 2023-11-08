/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:15:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/08 13:25:27 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	player_north_south(t_data *data)
{
	if (data->player.dir == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
	}
	else if (data->player.dir == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	}
	else
		return ;
}

/*
West player direction: 
direction vector to (-1, 0),
the plane vector to (0, -0.66)

East player direction:
direction vector to (1, 0),
plane vector to (0, 0.66)
*/
static void	player_east_west(t_data *data)
{
	if (data->player.dir == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
	}
	else if (data->player.dir == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
	}
	else
		return ;
}

void	add_player_direction(t_data *data)
{
	player_north_south(data);
	player_east_west(data);
	if (DEBUG)
	{
		printf("Player data:\n");
		printf("player_dir (NEWS - direction player is looking at): %c\n",
			data->player.dir);
		printf("player_x (idx on **map): %i\n", data->player.x);
		printf("player_y (idx on **map): %i\n", data->player.y);
		printf("player_pos_x (+0.5 to idx to get real position on a grid): %f\n",
			data->player.pos_x);
		printf("player_pos_y (+0.5 to idx to get real position on a grid): %f\n",
			data->player.pos_y);
		printf("player_dir_x: %f\n", data->player.dir_x);
		printf("player_dir_y: %f\n", data->player.dir_y);
		printf("player_plane_x: %f\n", data->player.plane_x);
		printf("player_plane_y: %f\n", data->player.plane_y);
	}
}

int	parsing(t_data *data, char **argv)
{
	init_data(data);
	handle_cub(argv[1], data);
	if (retrieve_file_data(data, data->cub_file) == FAILURE)
		return (FAILURE);
	if (validate_map(data, data->map) == FAILURE)
		return (FAILURE);
	if (validate_textures(data) == FAILURE)
		return (FAILURE);
	add_player_direction(data);
	return (SUCCESS);
}
