/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:37:32 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/09 15:36:50 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_error(char *message)
{
	ft_printf("\033[1;31m" "Error\n" "\033[0m");
	ft_printf("\033[3m\033[2;37m" " %s\n" "\033[0m", message);
	return (0);
}

void	ft_err(char *message)
{
	ft_printf("\033[1;31m" "Error\n" "\033[0m");
	ft_printf("\033[3m\033[2;37m" " %s\n" "\033[0m", message);
}