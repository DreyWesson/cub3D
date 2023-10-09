/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_retreiver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:22:39 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/09 22:18:33 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static int	skip_spaces(t_dt *data, char **cub_file, int i, int j)
{
	(void)data;
	while (ft_isspace(cub_file[i][j]) || cub_file[i][j] == '\n')
		j++;
	if (is_texture_or_color(cub_file[i][j]))
	{
		if (is_texture(cub_file[i][j], cub_file[i][j + 1]))
		{
			if (DEBUG)
				printf("%c %c\n", cub_file[i][j], cub_file[i][j + 1]);
			// if (add_textures(data, cub_file[i], j) == FAILURE)
			// 	return (FAILURE);
			return (TEXTURE_ADDED);
		}
		else
		{
			if (DEBUG)
				printf("%c\n", cub_file[i][j]);
			// if (add_colors(data, cub_file[i], j) == FAILURE)
			// 	return (FAILURE);
			return (TEXTURE_ADDED);
		}
	}
	else if (ft_isdigit(cub_file[i][j]))
	{
		// if (add_map(data, cub_file, i) == FAILURE)
		// 	return (FAILURE);
		return (SUCCESS);
	}
	return (42);
}

int	retrieve_file_data(t_dt *data, char **cub_file)
{
	int i;
	int j;
	int status;

	i = 0;
	while (cub_file[i])
	{
		j = 0;
		while (cub_file[i][j])
		{
			status = skip_spaces(data, cub_file, i, j);
			if (status == FAILURE)
				return (FAILURE);
			else if (status == SUCCESS)
				return (SUCCESS);
			else if (status == TEXTURE_ADDED)
				break ;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}