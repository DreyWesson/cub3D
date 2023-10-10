/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:25:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/10 21:29:47 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static unsigned long	rgb_to_int(int *rgb_arr)
{
	int	r;
	int	g;
	int	b;

	r = rgb_arr[0];
	g = rgb_arr[1];
	b = rgb_arr[2];
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

static int	validate_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (ft_error("Color: Invalid RGB value"), FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_xpm_file_extension(char *filename)
{
	size_t	filename_length;

	filename_length = ft_strlen(filename);
	if (filename_length < 4)
		return (FAILURE);
	if (ft_strncmp(&filename[filename_length - 4], ".xpm", 4) == 0)
		return (SUCCESS);
	else
		return (FAILURE);
}

int	validate_xpm_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error("Couldn't open file"), FAILURE);
	close(fd);
	if (check_xpm_file_extension(filename) == FAILURE)
		return (ft_error("Invalid file extention"), FAILURE);
	return (SUCCESS);
}

int	validate_textures(t_dt *data)
{
	if (!data->tex_north || !data->tex_east || !data->tex_west
		|| !data->tex_south)
		return (ft_error("Textures: Missing data"), FAILURE);
	if (!data->col_floor || !data->col_ceiling)
		return (ft_error("Color: Missing"), FAILURE);
	if (validate_xpm_file(data->tex_north) == FAILURE
		|| validate_xpm_file(data->tex_east) == FAILURE
		|| validate_xpm_file(data->tex_west) == FAILURE
		|| validate_xpm_file(data->tex_south) == FAILURE
		|| validate_rgb(data->col_floor) == FAILURE
		|| validate_rgb(data->col_ceiling) == FAILURE)
		return (FAILURE);
	data->col_ceiling_int = rgb_to_int(data->col_ceiling);
	data->col_floor_int = rgb_to_int(data->col_floor);
	if (DEBUG)
		printf("\nSaved color settings:\nceiling %d\nfloor %d\n\n",
			data->col_ceiling_int, data->col_floor_int);
	return (SUCCESS);
}