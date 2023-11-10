/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:27:01 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 13:04:33 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_error("Wrong arguments - pass ./cub3d ./path_to_map"));
	ft_memset((void *)&data, 0, sizeof(data));
	if (parsing(&data, argv) == FAILURE)
		return (free_data(&data), FAILURE);
	// debugger(&data);
	build_graphics(&data);
	mlx_hook(data.mlx_win, 17, 0, end_program, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press_handler, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, key_release_handler, &data);
	mlx_loop_hook(data.mlx_ptr, update, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (free_data(&data), SUCCESS);
}
