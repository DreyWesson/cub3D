/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:19:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/12 18:41:05 by doduwole         ###   ########.fr       */
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



void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	if (cur.x - 1 >= 0 && tab[cur.x - 1][cur.y] != '1')
		fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	if (cur.x + 1 <= size.x && tab[cur.x + 1][cur.y] != '1')
		fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	if (cur.y - 1 >= 0 && tab[cur.x][cur.y - 1] != '1')
		fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	if (cur.y + 1 <= size.y && tab[cur.x][cur.y + 1] != '1')
		fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
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
	// print_map(data, "Extracted Map");
	debugger(data);
	// exit(1);
	// flood_fill(data->map, (t_point){data->map_width, data->map_height}, (t_point){data->player_x, data->player_y});
	// printf("Here\n");
	if (validate_walls(data) == FAILURE)
		return (ft_error("Map: Should be surrounded by walls"), FAILURE);
	// make_map_rectangular(data);
	return (SUCCESS);
}