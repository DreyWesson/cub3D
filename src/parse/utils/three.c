/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:12:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/12 18:49:38 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	clean_exit(t_dt *data, int exitstatus)
{
	if (data)
		free_data(data);
	exit(exitstatus);
}

char	*ft_strdup2(const char *s1, int len)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((len+ 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
