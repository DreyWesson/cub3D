/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:59:52 by loandrad          #+#    #+#             */
/*   Updated: 2023/11/09 11:13:15 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	key_release_handler(int key, t_data *data)
{
	if (key == ESC)
		end_program(data);
	if (key == W && data->player.move_y == 1)
		data->player.move_y = 0;
	if (key == S && data->player.move_y == -1)
		data->player.move_y = 0;
	if (key == A && data->player.move_x == -1)
		data->player.move_x += 1;
	if (key == D && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (key == ARROW_LEFT && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == ARROW_RIGHT && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}

int	key_press_handler(int key, t_data *data)
{
	if (key == ESC)
		end_program(data);
	if (key == ARROW_LEFT)
		data->player.rotate -= 1;
	if (key == ARROW_RIGHT)
		data->player.rotate += 1;
	if (key == W)
		data->player.move_y = 1;
	if (key == A)
		data->player.move_x = -1;
	if (key == S)
		data->player.move_y = -1;
	if (key == D)
		data->player.move_x = 1;
	return (0);
}
