/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:15:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/09 17:19:01 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	parsing(t_dt *data, char **argv)
{
	// char	**cub_file;

    (void)data;
	if (!is_valid_cub(argv[1]))
		return (ft_error("Expecting a .cub file"));
    handle_map(argv[1], data);
	if (retrieve_file_data(data, data->cub_file) == FAILURE)
		return (FAILURE);
	// cub_file = data->cub_file;
	// if (retrieve_file_data(data, cub_file) == FAILURE)
	// 	return (FAILURE);
	// if (DEBUG)
	// {
	// 	printf("\nSaved map (**map after filling spaces):\n");
	// 	print_array_2d_newline(data->map);
	// 	printf("\n");
	// 	printf("Saved textures:\n");
	// 	printf("South: %s\n", data->tex_south);
	// 	printf("North: %s\n", data->tex_north);
	// 	printf("West: %s\n", data->tex_west);
	// 	printf("East: %s\n", data->tex_east);
	// }
	// if (validate_map(data, data->map) == FAILURE)
	// 	return (FAILURE);
	// if (validate_textures(data) == FAILURE)
	// 	return (FAILURE);
	// add_player_direction(data);
	return (SUCCESS);
}