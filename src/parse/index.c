/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:15:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/03 21:51:23 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	parsing(t_data *data, char **argv)
{
	init_data(data);
	handle_cub(argv[1], data);
	if (retrieve_file_data(data, data->cub_file) == FAILURE)
		return (FAILURE);
	if (validate_map(data, data->map) == FAILURE)
		return (FAILURE);
	if (validate_textures(data) == FAILURE)
		return (FAILURE);
	// debugger(data);
	// add_player_direction(data);
	return (SUCCESS);
}
