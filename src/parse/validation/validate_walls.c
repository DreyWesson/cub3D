/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:13:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/14 13:00:19 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

int	validate_walls(t_data *data)
{
	return (flood_fill(data->map, (t_point){data->map_width, data->map_height},
		data->player_x, data->player_y));
}
