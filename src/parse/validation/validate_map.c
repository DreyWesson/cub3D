/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:19:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/03 22:38:46 by oduwoledare      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static int	check_map_is_at_the_end(t_data *data)
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

static int	add_player_position(t_data *data, char **map)
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

int	set_player_dir(char dir)
{
	if (dir == 'N')
		return (0);
	else if (dir == 'S')
		return (1);
	else if (dir == 'E')
		return (2);
	return (3);
}

static int	check_map_elements(t_data *data, char **map)
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
				return (ft_error("Map: Invalid map"), FAILURE);
			if (ft_strchr("NEWS", map[i][j]) && data->player_dir != '0')
				return (ft_error("Map: Invalid map"), FAILURE);
			if (ft_strchr("NEWS", map[i][j]) && data->player_dir == '0')
				data->player_dir = set_player_dir(map[i][j]);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	validate_map(t_data *data, char **map)
{
	if (!data->map)
		return (ft_error("Map: no map found"), FAILURE);
	if (check_map_elements(data, map) == FAILURE)
		return (FAILURE);
	if (add_player_position(data, map) == FAILURE)
		return (FAILURE);
	if (check_map_is_at_the_end(data) == FAILURE)
		return (ft_error("Map: Should be the last element in file"), FAILURE);
	make_map_rectangular(data);
	if (validate_walls(data) == FAILURE)
		return (ft_error("Map: Should be surrounded by walls"), FAILURE);
	return (SUCCESS);
}