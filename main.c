/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:27:01 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/09 14:48:46 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"

int main(int argc, char **argv)
{
    t_dt data;
    
    if (argc != 2)
        return (ft_error("Wrong arguments - pass ./cub3d ./path_to_map"));
    init_map_data(&data);
    if (parsing(&data, argv) == FAILURE)
		return (free_data(&data), FAILURE);

    return (0);
}
