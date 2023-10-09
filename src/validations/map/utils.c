/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:14:43 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/09 15:02:50 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	check_fd(int fd)
{
	if (fd < 0)
	{
		ft_error("File error");
		exit(1);
	}
}

int	line_counter(char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(file_name, O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

size_t	ft_strlen_ln(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}
