/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:27:01 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/10 20:28:08 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_dt	data;

	if (argc != 2)
		return (ft_error("Wrong arguments - pass ./cub3d ./path_to_map"));
	init_data2(&data);
	if (parsing(&data, argv) == FAILURE)
		return (free_data(&data), FAILURE);
	return (0);
}
