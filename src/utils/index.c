/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:50:32 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/09 22:18:27 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\t'))
		return (true);
	return (false);
}

bool	ft_isprint_no_space(int c)
{
	if (c >= '!' && c <= '~')
		return (true);
	else
		return (false);
}

bool	is_texture_or_color(char c)
{
	return (ft_isprint_no_space(c) && !ft_isdigit(c));
}

bool	is_texture(char c1, char c2)
{
	return (c2 && ft_isprint_no_space(c2) && !ft_isdigit(c1));
}
