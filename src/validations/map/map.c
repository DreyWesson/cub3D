/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:07:25 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/03 15:15:09 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

char	**map_reader(char *s, int row_nbr)
{
	char	**ptr;
	char	*str;
	int		i;
	int		len;
	int		fd;

	fd = open(s, O_RDONLY);
	check_fd(fd);
	row_nbr = line_counter(s);
	ptr = (char **)ft_calloc(sizeof(char *), row_nbr + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < row_nbr)
	{
		str = get_next_line(fd);
		len = ft_strlen_ln(str);
		ptr[i] = ft_substr(str, 0, len);
		ptr[i][len] = '\0';
		i++;
		free(str);
	}
	return (ptr);
}

int	validate_composition(char s, t_compass *val)
{
	char	*set;

	set = "01NSEW";
	if (!ft_strchr(set, s))
	{
		ft_error("=>Invalid composition");
		return (0);
	}
	else
	{
		if (s == 'N')
			(*val).n += 1;
		else if (s == 'S')
			(*val).s += 1;
		else if (s == 'E')
			(*val).e += 1;
		else if (s == 'W')
			(*val).w += 1;
	}
	return (1);
}

int	validate_walls(char *s, int row_nbr, int j, int i)
{
	if (s[j] != '1' && (i == 0 || i == row_nbr - 1
			|| j == 0 || s[j + 1] == '\0'))
	{
		ft_error("Should be surrounded by walls");
		return (0);
	}
	return (1);
}

void validate_map(char **map, int row_nbr)
{
	int			y;
	int			x;
	t_compass	val;

	y = 0;
	val.e = 0;
	val.n = 0;
	val.s = 0;
	val.w = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!validate_composition(map[y][x], &val)
			|| !validate_walls(map[y], row_nbr, x, y))
				free_exit(map);
			x++;
		}

		y++;
	}
	if ((val.n + val.e + val.s + val.w) > 1)
	{
		ft_error("Invalid composition");
		free_exit(map);
	}
}

int	handle_map(char **argv, t_game *game)
{
	char		**ptr;
	int row_nbr;
    (void)game;

	row_nbr = line_counter(argv[1]);
	ptr = map_reader(argv[1], row_nbr);
	validate_map(ptr, row_nbr);
	print_grid(ptr, row_nbr);

	return (1);
}