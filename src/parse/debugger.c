/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:07:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/11 15:00:11 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


void texture_data(t_dt *data)
{
		printf("\033[1;33m""Saved textures:\n""\033[0m");
		printf("South: %s\n", data->tex_south);
		printf("North: %s\n", data->tex_north);
		printf("West: %s\n", data->tex_west);
		printf("East: %s\n", data->tex_east);
		printf("\n");
}

void player_data(t_dt *data)
{
		printf("\033[1;33m""Player data:\n""\033[0m");
		printf("player_dir (NEWS - direction player is looking at): %c\n",
			data->player_dir);
		printf("player_x (idx on **map): %i\n", data->player_x);
		printf("player_y (idx on **map): %i\n", data->player_y);
		printf("player_pos_x (+0.5 to idx to get real position on a grid):%f\n",
			data->player_pos_x);
		printf("player_pos_y (+0.5 to idx to get real position on a grid):%f\n",
			data->player_pos_y);
		printf("player_dir_x: %f\n", data->player_dir_x);
		printf("player_dir_y: %f\n", data->player_dir_y);
		printf("player_plane_x: %f\n", data->player_plane_x);
		printf("player_plane_y: %f\n", data->player_plane_y);
		printf("\n");
}

void debugger(t_dt *data)
{
    texture_data(data);
    print_map(data, "Rectangular map");
	player_data(data);
}
