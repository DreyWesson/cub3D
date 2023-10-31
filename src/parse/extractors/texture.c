/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:52:22 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/10 22:19:52 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static char	*add_tex_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && ft_isspace(line[j]))
		j++;
	len = j;
	while (line[len] && !ft_isspace(line[j]))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (!ft_isspace(line[j]) && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (ft_isspace(line[j])))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

int	set_textures(t_data *data, char *line, int j)
{
	if (line[j + 2] && ft_isprint_no_space(line[j + 2]))
		return (ft_error("Textures: Invalid"), FAILURE);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(data->tex_north))
		data->tex_north = add_tex_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(data->tex_south))
		data->tex_south = add_tex_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(data->tex_west))
		data->tex_west = add_tex_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(data->tex_east))
		data->tex_east = add_tex_path(line, j + 2);
	else
		return (ft_error("Textures: Invalid"), FAILURE);
	return (SUCCESS);
}