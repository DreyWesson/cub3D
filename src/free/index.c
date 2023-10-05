/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:06:31 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/03 12:54:30 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../inc/cub3d.h"

void	free_grid(t_cell **grid, int row_nbr, int status)
{
	int	i;

	i = 0;
	while (i < row_nbr)
	{
		free(grid[i]->up);
		free(grid[i]->left);
		free(grid[i]->right);
		free(grid[i]->down);
		free(grid[i]);
		i++;
	}
	free(grid);
	exit(status);
}

void	alt_free_grid(t_cell **grid, int row_nbr)
{
	int	i;

	i = 0;
	while (i < row_nbr)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_list(t_nodes **head_ref)
{
	t_nodes	*tmp;

	if (!*head_ref)
	{
		free(head_ref);
		return ;
	}
	tmp = *head_ref;
	while (tmp)
	{
		tmp = (*head_ref)->next;
		free(*head_ref);
		*head_ref = tmp;
	}
}

void	free_all(char **ptr, t_cell **grid, t_nodes **queue)
{
	(void)grid;
	// free_grid(grid, count_row(ptr), 0);
	ft_free2d(ptr);
	free_list(queue);
}
