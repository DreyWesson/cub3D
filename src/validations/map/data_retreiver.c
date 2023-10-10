/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_retreiver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:22:39 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/10 16:02:18 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

// static char	*add_tex_path(char *line, int j)
// {
// 	int		len;
// 	int		i;
// 	char	*path;

// 	while (line[j] && ft_isspace(line[j]))
// 		j++;
// 	len = j;
// 	while (line[len] && !ft_isspace(line[j]))
// 		len++;
// 	path = malloc(sizeof(char) * (len - j + 1));
// 	if (!path)
// 		return (NULL);
// 	i = 0;
// 	while (line[j] && (!ft_isspace(line[j]) && line[j] != '\n'))
// 		path[i++] = line[j++];
// 	printf("%s", path);
// 	path[i] = '\0';
// 	while (line[j] && (ft_isspace(line[j])))
// 		j++;
// 	if (line[j] && line[j] != '\n')
// 	{
// 		free(path);
// 		path = NULL;
// 	}
// 	return (path);
// }

// static int	set_textures(t_dt *data, char *line, int j)
// {
// 	if (line[j + 2] && ft_isprint_no_space(line[j + 2]))
// 		return (ft_error("Textures: Invalid"), FAILURE);
// 	if (line[j] == 'N' && line[j + 1] == 'O' && !(data->tex_north))
// 		data->tex_north = add_tex_path(line, j + 2);
// 	else if (line[j] == 'S' && line[j + 1] == 'O' && !(data->tex_south))
// 		data->tex_south = add_tex_path(line, j + 2);
// 	else if (line[j] == 'W' && line[j + 1] == 'E' && !(data->tex_west))
// 		data->tex_west = add_tex_path(line, j + 2);
// 	else if (line[j] == 'E' && line[j + 1] == 'A' && !(data->tex_east))
// 		data->tex_east = add_tex_path(line, j + 2);
// 	else
// 		return (ft_error("Textures: Invalid"), FAILURE);
// 	return (SUCCESS);
// }

static int	handle_extraction(t_dt *data, char **cub_file, int i, int j)
{
	(void)data;
	while (ft_isspace(cub_file[i][j]) || cub_file[i][j] == '\n')
		j++;
	if (is_texture_or_color(cub_file[i][j]))
	{
		if (is_texture(cub_file[i][j], cub_file[i][j + 1]))
		{
			if (set_textures(data, cub_file[i], j) == FAILURE)
				return (FAILURE);
			return (TEXTURE_ADDED);
		}
		else
		{
			// if (DEBUG)
			// 	printf("%c\n", cub_file[i][j]);
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
			status = handle_extraction(data, cub_file, i, j);
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