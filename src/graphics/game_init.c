/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:00:58 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/07 14:50:29 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int game_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_error("MLX failed to initialize!");
		return(FAILURE);
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, "Cub3D");
	if (!data->mlx_win)
	{
		ft_error("MLX failed to initialize!");
		return(FAILURE);
	}
	return (SUCCESS);
}
