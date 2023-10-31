/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:35:16 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/12 15:40:50 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

// static void	fill_up_spaces(char *new_line, t_data *data)
// {
// 	int	j;

// 	j = 0;
// 	while (j < data->map_width)
// 	{
// 		new_line[j] = '1';
// 		j++;
// 	}
// 	new_line[j] = '\0';
// }

// static void	copy_line(char *new_line, char *old_line)
// {
// 	int	j;

// 	j = 0;
// 	while (old_line[j])
// 	{
// 		if (old_line[j] != ' ')
// 			new_line[j] = old_line[j];
// 		j++;
// 	}
// }

void	fill_up_gaps(char *new_line, t_data *data, int line_num)
{
	int	i;
	int	line_width;

	i = 0;
	line_width = ft_strlen(data->map[line_num]);
	while (i < line_width)
	{
		if (data->map[line_num][i] == ' ')
			new_line[i] = '0';
		else
			new_line[i] = data->map[line_num][i];
		i++;
	}
	while (i < data->map_width)
	{
		new_line[i] = '0';
		i++;
	}
	new_line[i] = '\0';
}

void	make_map_rectangular(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	while (i < data->map_height)
	{
		line = (char *)malloc(sizeof(char) * (data->map_width + 1));
		if (!line)
		{
			ft_error("Malloc failed");
			return ;
		}
		// fill_up_spaces(line, data);
		// copy_line(line, data->map[i]);
		fill_up_gaps(line, data, i);
		free(data->map[i]);
		data->map[i] = line;
		i++;
	}
}
