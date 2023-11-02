/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:06:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/02 00:32:53 by doduwole         ###   ########.fr       */
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
	if (data->east_tex)
	{
		free(data->east_tex);
		data->east_tex = NULL;
	}
	if (data->north_tex)
	{
		free(data->north_tex);
		data->north_tex = NULL;
	}
	if (data->west_tex)
	{
		free(data->west_tex);
		data->west_tex = NULL;
	}
	if (data->south_tex)
	{
		free(data->south_tex);
		data->south_tex = NULL;
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