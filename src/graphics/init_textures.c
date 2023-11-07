/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:59:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/07 14:58:51 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_texture_pixels(t_data *data)
{
	int	i;

	i = 0;
	if (data->tex_pixels)
		free_array_2d((void **)data->tex_pixels);
	data->tex_pixels = ft_calloc(data->win_height + 1,
			sizeof * data->tex_pixels);
	if (!data->tex_pixels)
		clean_exit(data, FAILURE);
	while (i < data->win_height)
	{
		data->tex_pixels[i] = ft_calloc(data->win_width + 1,
				sizeof * data->tex_pixels);
		if (!data->tex_pixels[i])
			clean_exit(data, FAILURE);
		i++;
	}
}

// void	init_img_null(t_img *img)
// {
// 	img->img = NULL;
// 	img->addr = NULL;
// 	img->pixel_bits = 0;
// 	img->size_line = 0;
// 	img->endian = 0;
// }

void	init_texture_img(t_data *data, t_img *image_details, char *path)
{
	ft_memset((void *)image_details, 0, sizeof(*image_details));
	image_details->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->tile_w,
			&data->tile_h);
	if (image_details->img == NULL)
	{
		ft_error("Malloc failed!");
		clean_exit(data, FAILURE);
	}
	image_details->addr = (int *)mlx_get_data_addr(image_details->img, &image_details->pixel_bits,
			&image_details->size_line, &image_details->endian);
}

static int	*xpm_to_img(t_data *data, char *tex_path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	y = 0;
	init_texture_img(data, &tmp, tex_path);
    buffer = ft_calloc(sizeof(*buffer), data->tex_size * data->tex_size);
	if (!buffer)
		clean_exit(data, FAILURE);
	while (y < data->tex_size)
	{
		x = 0;
		while (x < data->tex_size)
		{
			buffer[y * data->tex_size + x]
				= tmp.addr[y * data->tex_size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx_ptr, tmp.img);
	return (buffer);
}

void	texture_init(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		clean_exit(data, FAILURE);
	data->textures[NORTH] = xpm_to_img(data, data->north_tex);
	data->textures[SOUTH] = xpm_to_img(data, data->south_tex);
	data->textures[EAST] = xpm_to_img(data, data->east_tex);
	data->textures[WEST] = xpm_to_img(data, data->west_tex);
}
