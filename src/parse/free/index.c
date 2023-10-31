/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:06:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/10 22:19:19 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	free_array_2d(void **array_2d)
{
	int	i;

	i = 0;
	if (!array_2d)
		return ;
	while (array_2d[i])
	{
		free(array_2d[i]);
		i++;
	}
	free(array_2d);
}

void	free_cub(t_data *data)
{
	data->cub_path = NULL;
	if (data->cub_file)
	{
		free_array_2d((void **)data->cub_file);
		data->cub_file = NULL;
	}
	if (data->cub_fd > 0)
		close(data->cub_fd);
}

void	free_textures(t_data *data)
{
	if (data->tex_east)
	{
		free(data->tex_east);
		data->tex_east = NULL;
	}
	if (data->tex_north)
	{
		free(data->tex_north);
		data->tex_north = NULL;
	}
	if (data->tex_west)
	{
		free(data->tex_west);
		data->tex_west = NULL;
	}
	if (data->tex_south)
	{
		free(data->tex_south);
		data->tex_south = NULL;
	}
}

void	free_colors(t_data *data)
{
	if (data->col_ceiling)
	{
		free(data->col_ceiling);
		data->col_ceiling = NULL;
	}
	if (data->col_floor)
	{
		free(data->col_floor);
		data->col_floor = NULL;
	}
}

void	free_data(t_data *data)
{
	free_cub(data);
	free_textures(data);
	free_colors(data);
	if (data->map)
	{
		free_array_2d((void **)data->map);
		data->map = NULL;
	}
}