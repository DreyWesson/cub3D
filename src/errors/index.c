/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:05:13 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/03 12:07:25 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_error(char *message)
{
	ft_printf("\033[1;31m" "Error\n" "\033[0m");
	ft_printf("\033[3m\033[2;37m" " %s\n" "\033[0m", message);
	return (0);
}

void	ft_warning(char *message)
{
	ft_printf("\033[1;33m" "Warning\n" "\033[0m");
	ft_printf("\033[3m\033[2;37m" " %s\n" "\033[0m", message);
}

