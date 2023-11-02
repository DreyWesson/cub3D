/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:27:01 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/02 02:53:51 by doduwole         ###   ########.fr       */
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
	printf("The END");
	clean_exit(data, 0);
	return (0);
}

int	input(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == ESC)
		end_program(data);
	if (key == W)
		printf("W\n");
	if (key == A)
		printf("A\n");
	if (key == S)
		printf("S\n");
	if (key == D)
		printf("D\n");
	return (0);
}


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
			return (ft_error("Wrong arguments - pass ./cub3d ./path_to_map"));
	if (parsing(&data, argv) == FAILURE)
		return (free_data(&data), FAILURE);
	/// @note build graphics implementation
		// initialize the necessary data
		// load the images
		// initialize mlx and window

	build_graphics(&data);
	mlx_hook(data.mlx_win, 2, 0, input, (void *)&data);
	mlx_hook(data.mlx_win, 17, 0, end_program, &data);
	mlx_loop_hook(data.mlx_ptr, update, (void *)&data);
	mlx_loop(data.mlx_ptr);
	// When we start handling end program with user input we'll need to remove this
	// free_data(&data);
	return (0);
}
