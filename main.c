/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:27:01 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/02 01:00:05 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

// void	clean_exit(t_data *data, int exitstatus)
// {
// 	if (data)
// 		free_data(data);
// 	exit(exitstatus);
// }



int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_error("Wrong arguments - pass ./cub3d ./path_to_map"));
	if (parsing(&data, argv) == FAILURE)
		return (free_data(&data), FAILURE);
	// build graphics implementation
		// initialize the game
		// load the images
		// initialize mlx and window

	build_graphics(&data);
		
	free_data(&data);
	return (0);
}
