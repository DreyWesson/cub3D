/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:07:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/11 20:09:32 by doduwole         ###   ########.fr       */
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
		printf("\n");
}

void color_data(int *data, char *str)
{
	printf("\033[1;33m""%s color data:\n""\033[0m", str);
	int i;

	i = 0;
	while (i < 3)
	{
		printf("%d", data[i]);
		if (i != 2)
			printf(" ");
		i++;
	}
	printf("\n");
}

void debugger(t_dt *data)
{
    texture_data(data);
	color_data(data->col_ceiling, "Ceiling");
	color_data(data->col_floor, "Floor");
    print_map(data, "Rectangular map");
	player_data(data);
}
