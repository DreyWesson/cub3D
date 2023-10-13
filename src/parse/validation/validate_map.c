/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:19:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/13 09:39:56 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

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



int	fill(char **tab, t_point size,	int x, int y)
{
	if (y < 0 || y >= size.y || x < 0 || x >= size.x)
		return (ft_err("Map not surrounded by wall"), FAILURE);
	if (tab[y][x] == 'C' || tab[y][x] == '1' || tab[y][x] == ' ')
		return (1);
	tab[y][x] = 'C';
	fill(tab, size, x, y + 1);
	fill(tab, size, x, y - 1);
	fill(tab, size, x - 1, y);
	fill(tab, size, x + 1, y);
	return (SUCCESS);
}

void	flood_fill(char **tab, t_point size, int x, int y)
{
	fill(tab, size, x, y);
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
	data->map[data->player_y][data->player_x] = data->player_dir;
	// print_map(data, "Extracted Map");
	flood_fill(data->map, (t_point){data->map_width, data->map_height}, data->player_x, data->player_y);
	debugger(data);
	// if (validate_walls(data) == FAILURE)
	// 	return (ft_error("Map: Should be surrounded by walls"), FAILURE);
	// make_map_rectangular(data);
	return (SUCCESS);
}