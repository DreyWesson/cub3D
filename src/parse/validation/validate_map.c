/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:19:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/13 11:34:15 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static int	check_map_is_at_the_end(t_dt *data)
{
	int	i;
	int	j;

	i = data->map_end_idx;
	while (data->cub_file[i])
	{
		j = 0;
		while (data->cub_file[i][j])
		{
			if (!ft_isspace(data->cub_file[i][j])
				&& data->cub_file[i][j] != '\n')
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	add_player_position(t_dt *data, char **map)
{
	int	i;
	int	j;

	if (data->player_dir == '0')
		return (ft_error("Map: no player found"), FAILURE);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NEWS", map[i][j]))
			{
				data->player_x = j;
				data->player_y = i;
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	check_map_elements(t_dt *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	data->player_dir = '0';
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			while (ft_isspace(data->map[i][j]))
				j++;
			if (!(ft_strchr("10NEWS", map[i][j])))
				return (ft_error("Map: Contains invalid character"), FAILURE);
			if (ft_strchr("NEWS", map[i][j]) && data->player_dir != '0')
				return (ft_error("Map: has more than one player"), FAILURE);
			if (ft_strchr("NEWS", map[i][j]) && data->player_dir == '0')
				data->player_dir = map[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int validate_walls2(t_dt *data)
{
	char	**map_clone;
	int		i;
	int		valid;

	// i = 0;
	// while (i < data->map_height)
	// {
	// 	if (is_last_char_one(data->map[i]) == FAILURE)
	// 		return (FAILURE);
	// 	i++;
	// }
	map_clone = malloc(data->map_height * sizeof(char *));
	i = -1;
	while (++i < data->map_height)
		map_clone[i] = ft_strdup2(data->map[i], data->map_width);
	valid = flood_fill(map_clone, (t_point){data->map_width, data->map_height},
			data->player_x, data->player_y);
	i = -1;
	while (++i < data->map_height)
		free(map_clone[i]);
	free(map_clone);

	return (valid);
}

int	validate_map(t_dt *data, char **map)
{
	if (!data->map)
		return (ft_error("Map: no player found"), FAILURE);
	if (data->map_height < 3)
		return (ft_error("Map: Should contain at least 3 lines"), FAILURE);
	if (check_map_elements(data, map) == FAILURE)
		return (FAILURE);
	if (add_player_position(data, map) == FAILURE)
		return (FAILURE);
	if (check_map_is_at_the_end(data) == FAILURE)
		return (ft_error("Map: Should be the last element in file"), FAILURE);
	make_map_rectangular(data);
	if (validate_walls2(data) == FAILURE)
		return (ft_error("Map: Should be surrounded by walls"), FAILURE);
	return (SUCCESS);
}