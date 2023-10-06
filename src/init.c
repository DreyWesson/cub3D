/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:30:39 by eramusho          #+#    #+#             */
/*   Updated: 2023/10/06 20:28:00 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_data(t_data *d)
{
	d->game = ft_calloc(1, sizeof(t_game));
	d->player = ft_calloc(1, sizeof(t_player));
	d->img = ft_calloc(1, sizeof(t_img));
	d->img_game = ft_calloc(1, sizeof(t_img));
	d->rays_dist = ft_calloc(1, sizeof(double) * WIN_WIDTH);
	d->rays_x = ft_calloc(1, sizeof(double) * WIN_WIDTH);
	d->rays_y = ft_calloc(1, sizeof(double) * WIN_WIDTH);
	d->ray_angle = ft_calloc(1, sizeof(double) * WIN_WIDTH);
	d->is_horizontal = ft_calloc(1, sizeof(int) * WIN_WIDTH);
}

void	init_imgs(t_data *d)
{
	d->img_game->img = mlx_new_image(d->mlx, WIN_WIDTH, WIN_HEIGHT);
	d->img_game->addr = (int *)mlx_get_data_addr(d->img_game->img, \
&d->img_game->bits_per_pixel, &d->img_game->line_length, &d->img_game->endian);
	d->img->img = mlx_new_image(d->mlx, MINI_S * MINI_M, MINI_S * MINI_M);
	d->img->addr = (int *)mlx_get_data_addr(d->img->img, \
&d->img->bits_per_pixel, &d->img->line_length, &d->img->endian);
}
