/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:53:04 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/12 15:38:45 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static int	map_to_2d(t_dt *data, char **map, int index)
{
	int	i;
	int	j;

	data->map_width = find_max_width(data, index);
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		map[i] = ft_calloc(sizeof(char), (data->map_width + 1));
		if (!map[i])
			return (ft_error("Malloc failed"), FAILURE);
		while (data->cub_file[index][j] && data->cub_file[index][j] != '\n')
		{
			/// @note can check for tabs here rather than another no_tabs func
			if (data->cub_file[index][j] == '\t')
			{
				map[i] = NULL;
				return (ft_error("Map: Tab instead of space"), FAILURE);
			}
			map[i][j] = data->cub_file[index][j];
			j++;
		}
		i++;
		index++;
	}
	map[i] = NULL;
	return (SUCCESS);
}

static int	count_map_lines(t_dt *data, char **file, int i)
{
	int	index_val;
	int	j;

	index_val = i;
	while (file[i])
	{
		j = 0;
		while (ft_isspace(file[i][j]))
			j++;
		if (file[i][j] && file[i][j] != '1')
			break ;
		i++;
	}
	data->map_end_idx = i;
	return (i - index_val);
}

// int	no_tabs(t_dt *data)
// {
// 	char	**map;
// 	int		i;
// 	int		j;

// 	map = data->map;
// 	i = 0;
// 	while (i < data->map_height)
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == '\t')
// 				return (ft_error("Map: Tab instead of space"), FAILURE);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (SUCCESS);
// }

static int	retrieve_map_data(t_dt *data, char **cub_file, int i)
{
	data->map_height = count_map_lines(data, cub_file, i);
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		return (ft_error("Malloc failed"), FAILURE);
	if (map_to_2d(data, data->map, i) == FAILURE)
		return (FAILURE);
	if (DEBUG)
		print_map(data, "Extracted Map");
	// if (no_tabs(data) == FAILURE)
	// 	return (FAILURE);
	return (SUCCESS);
}

int	add_map(t_dt *data, char **cub_file, int i)
{
	if (retrieve_map_data(data, cub_file, i) == FAILURE)
		return (FAILURE);
	if (validate_map(data, data->map) == FAILURE)
		return (FAILURE);
	// printf("%c %d %d\n", data->player_dir, data->player_y, data->player_x);
	return (SUCCESS);
}
