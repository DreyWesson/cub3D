/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:13:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/10 20:45:12 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_grid(char **map, int row_nbr)
{
	int	y;

	y = 0;
	while (y < row_nbr)
	{
		printf("%s\n", map[y]);
		y++;
	}
}

void	print_array_2d(char **array_2d)
{
	int	i;

	i = 0;
	while (array_2d[i])
	{
		printf("%s", array_2d[i]);
		i++;
	}
}

void	print_array_2d_newline(char **array_2d)
{
	int	i;

	i = 0;
	while (array_2d[i])
	{
		// printf("line idx %d\n", i);
		printf("%s", array_2d[i]);
		printf("\n");
		i++;
	}
}
