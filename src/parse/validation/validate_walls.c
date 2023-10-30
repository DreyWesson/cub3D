/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:13:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/30 12:29:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

// int	validate_walls(t_dt *data)
// {
// 	char	**map_clone;
// 	int		i;
// 	int		valid;

// 	i = 0;
// 	while (i < data->map_height)
// 	{
// 		if (is_last_char_one(data->map[i]) == FAILURE)
// 			return (FAILURE);
// 		i++;
// 	}
// 	map_clone = malloc(data->map_height * sizeof(char *));
// 	i = -1;
// 	while (++i < data->map_height)
// 		map_clone[i] = ft_strdup2(data->map[i], data->map_width);
// 	// valid = dfs(data, map_clone);
// 	print_array_2d(map_clone);
// 	valid = flood_fill(map_clone, (t_point){data->map_width, data->map_height},
// 		data->player_x, data->player_y);
// 	i = -1;
// 	while (++i < data->map_height)
// 		free(map_clone[i]);
// 	free(map_clone);
// 	if (valid != FAILURE)
// 		return (SUCCESS);
// 	return (FAILURE);
// }

int	validate_walls(t_dt *data)
{
	return (flood_fill(data->map, (t_point){data->map_width, data->map_height},
		data->player_x, data->player_y));
}
