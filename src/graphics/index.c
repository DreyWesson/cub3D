/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:39:39 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/14 15:37:59 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// int	east_wall(t_dt *data, t_wall_img *walls, int *x, int *y)
// {
//     walls->east = mlx_xpm_file_to_image(data->mlx_ptr,
// 			data->tex_east, x, y);
// }

// int	west_wall(t_dt *data, t_wall_img *walls, int *x, int *y)
// {
//     walls->west = mlx_xpm_file_to_image(data->mlx_ptr,
// 			data->tex_west, x, y);
// }
// int	north_wall(t_dt *data, t_wall_img *walls, int *x, int *y)
// {
//     walls->north = mlx_xpm_file_to_image(data->mlx_ptr,
// 			data->tex_north, x, y);
// }

// int	south_wall(t_dt *data, t_wall_img *walls, int *x, int *y)
// {
//     walls->south = mlx_xpm_file_to_image(data->mlx_ptr,
//         data->tex_south, x, y);
// }


// int load_images(t_dt *data, t_wall_img *walls, int *x, int *y)
// {
//     north_wall(data, walls, x, y);
//     east_wall(data, walls, x, y);
//     west_wall(data, walls, x, y);
//     south_wall(data, walls, x, y);
// }

// static void	draw_images()
// {
    // if (pos.x == 0 
        // || pos.y == 0 
        // || pos.x == game.window_size.x - IMG_SIZE 
        // || pos.y == game.window_size.y - IMG_SIZE)
    // {
            // if (pos.x == 0)
            // 	draw west
            // else if (pos.y == 0)
            // 	draw north
            // else if (pos.x == game.window_size.x - IMG_SIZE)
            // 	draw east
            // else if (pos.y == game.window_size.y - IMG_SIZE)
            // 	draw west
    // }
    // else
    // {
            // if (current_cell == 1)
            //      draw block
            // else if (current_cell == 0)
            //      draw space
            // else if (ft_strchr("NEWS", current_cell))
            //      draw player
    // }
// }

// void	render(t_dt *data)
// {
// 	int		x;
// 	int		y;

//     char current_cell;

// 	y = 0;
// 	mlx_clear_window(game.mlx, game.window);
// 	while (y < data->map_height)
// 	{
// 		x = 0;
// 		while (x < data->map_width)
// 		{
// 			current_cell = data->map[y][x];
// 			draw_image(data);
// 			x++;
// 		}
// 		y++;
// 	}
// }
