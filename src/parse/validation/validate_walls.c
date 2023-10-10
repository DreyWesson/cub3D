/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:13:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/10 19:16:21 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

int	validate_walls(t_dt *data)
{
	char	**map_clone;
	int		i;
	int		valid;

	i = 0;
	while (i < data->map_height)
	{
		if (is_last_char_one(data->map[i]) == FAILURE)
			return (FAILURE);
		i++;
	}
	map_clone = malloc(data->map_height * sizeof(char *));
	i = -1;
	while (++i < data->map_height)
		map_clone[i] = ft_strdup(data->map[i]);
	valid = dfs(data, map_clone);
	i = -1;
	while (++i < data->map_height)
		free(map_clone[i]);
	free(map_clone);
	if (valid)
		return (SUCCESS);
	return (FAILURE);
}
