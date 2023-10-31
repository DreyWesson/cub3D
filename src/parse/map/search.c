/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:17:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/13 11:48:43 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

int	flood_fill(char **tab, t_point size, int x, int y)
{
	int	result;

	if (y < 0 || y >= size.y || x < 0 || x >= size.x)
		return (FAILURE);
	if (tab[y][x] == 'v' || tab[y][x] == '1')
		return (1);
	tab[y][x] = 'v';
	result = flood_fill(tab, size, x, y + 1);
	if (result != FAILURE)
		result = flood_fill(tab, size, x, y - 1);
	if (result != FAILURE)
		result = flood_fill(tab, size, x - 1, y);
	if (result != FAILURE)
		result = flood_fill(tab, size, x + 1, y);
	return (result);
}
