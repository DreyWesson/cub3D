/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:31:57 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/11 20:06:15 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

/*
if player's direction is South, it sets:
direction vector to (0, 1),
plane (camera) vector to (-0.66, 0), for the orthogonal direction.

if the player's direction is North, it sets:
direction vector to (0, -1),
plane vector to (0.66, 0)
*/
// static void	player_north_south(t_dt *data)
// {
// 	if (data->player_dir == 'S')
// 	{
// 		data->player_dir_x = 0;
// 		data->player_dir_y = 1;
// 		data->player_plane_x = -0.66;
// 		data->player_plane_y = 0;
// 	}
// 	else if (data->player_dir == 'N')
// 	{
// 		data->player_dir_x = 0;
// 		data->player_dir_y = -1;
// 		data->player_plane_x = 0.66;
// 		data->player_plane_y = 0;
// 	}
// 	else
// 		return ;
// }

/*
West player direction:
direction vector to (-1, 0),
the plane vector to (0, -0.66)

East player direction:
direction vector to (1, 0),
plane vector to (0, 0.66)
*/
// static void	player_east_west(t_dt *data)
// {
// 	if (data->player_dir == 'W')
// 	{
// 		data->player_dir_x = -1;
// 		data->player_dir_y = 0;
// 		data->player_plane_x = 0;
// 		data->player_plane_y = -0.66;
// 	}
// 	else if (data->player_dir == 'E')
// 	{
// 		data->player_dir_x = 1;
// 		data->player_dir_y = 0;
// 		data->player_plane_x = 0;
// 		data->player_plane_y = 0.66;
// 	}
// 	else
// 		return ;
// }

// void	add_player_direction(t_dt *data)
// {
// 	player_north_south(data);
// 	player_east_west(data);
// }
