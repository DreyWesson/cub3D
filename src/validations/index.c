/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:34:04 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/03 15:14:10 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	handle_validation(int argc, char **argv, t_game *game)
{
	if (!validate_arg(argc, argv))
		return (0);
	if (!handle_map(argv, game))
	{
		return (0);
	}
	return (1);
}
