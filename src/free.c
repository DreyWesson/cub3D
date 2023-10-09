/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:12:05 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/09 14:50:27 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

void	free_cub(t_dt *data)
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

void	free_textures(t_dt *data)
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

void	free_colors(t_dt *data)
{
	if (data->col_ceiling)
	{
		free(data->col_ceiling);
		data->col_ceiling = NULL ;
	}
	if (data->col_floor)
	{
		free(data->col_floor);
		data->col_floor = NULL ;
	}
}

void	free_data(t_dt *data)
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