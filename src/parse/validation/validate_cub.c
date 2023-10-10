/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:54:45 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/10 22:18:03 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	check_len(int len)
{
	if (len == 4)
	{
		ft_error("File name doesn't exist");
		exit(0);
	}
}

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_trim(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	return (start);
}

int	is_valid_cub(char *str)
{
	char	*s;
	int		len;
	int		res;

	res = 0;
	s = NULL;
	len = ft_trim(str, "./");
	while (str[len])
	{
		if (str[len] == '.')
		{
			s = ft_substr(&str[len], 0, 4);
			if (ft_strncmp(s, ".cub", 4) == 0 && !str[len + 4])
				res = 1;
			else
				break ;
		}
		len++;
	}
	check_len(len);
	free(s);
	return (res);
}
