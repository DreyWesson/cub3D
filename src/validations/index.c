/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:34:04 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/06 20:30:51 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	handle_validation(int argc, char **argv)
{
	if (!validate_arg(argc, argv))
		return (0);
	if (!handle_map(argv))
	{
		return (0);
	}
	return (1);
}
