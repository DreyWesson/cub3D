/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:50:32 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/09 18:53:32 by doduwole         ###   ########.fr       */
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

bool    none_num(char c)
{
    return (ft_isprint_no_space(c) && !ft_isdigit(c));
}

bool    contiguous_alpha(char c1, char c2)
{
    return (c2 && ft_isprint_no_space(c2) && !ft_isdigit(c1));
}
