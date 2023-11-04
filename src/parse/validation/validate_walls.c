/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:13:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/04 11:04:36 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

int	validate_walls(t_data *data)
{
	return (flood_fill(data->map, (t_point){data->map_width, data->map_height},
		data->player.x, data->player.y));
}
