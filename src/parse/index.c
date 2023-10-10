/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:15:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/10 20:51:48 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	parsing(t_dt *data, char **argv)
{
	if (!is_valid_cub(argv[1]))
		return (ft_error("Expecting a .cub file"));
	handle_map(argv[1], data);
	if (retrieve_file_data(data, data->cub_file) == FAILURE)
		return (FAILURE);
	if (DEBUG)
	{
		printf("\nRectangular Map:\n");
		print_array_2d_newline(data->map);
		printf("\n");
		printf("Saved textures:\n");
		printf("South: %s\n", data->tex_south);
		printf("North: %s\n", data->tex_north);
		printf("West: %s\n", data->tex_west);
		printf("East: %s\n", data->tex_east);
	}
	// if (validate_map(data, data->map) == FAILURE)
	// 	return (FAILURE);
	// if (validate_textures(data) == FAILURE)
	// 	return (FAILURE);
	// add_player_direction(data);
	return (SUCCESS);
}