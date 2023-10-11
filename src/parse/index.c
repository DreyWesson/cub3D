/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:15:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/11 11:09:32 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	parsing(t_dt *data, char **argv)
{
	if (!is_valid_cub(argv[1]))
		return (ft_error("Expecting a .cub file"));
	handle_map(argv[1], data);
	if (retrieve_file_data(data, data->cub_file) == FAILURE)
		return (FAILURE);
	if (DEBUG)
		debugger(data);
	exit(1);
	if (validate_map(data, data->map) == FAILURE)
		return (FAILURE);
	if (validate_textures(data) == FAILURE)
		return (FAILURE);
	add_player_direction(data);
	return (SUCCESS);
}