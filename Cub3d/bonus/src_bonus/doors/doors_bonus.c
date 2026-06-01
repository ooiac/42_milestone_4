/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:12:35 by smetz             #+#    #+#             */
/*   Updated: 2026/03/27 11:12:37 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int	count_doors(t_cub3d *cub)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (cub->map.grid[y] && cub->map.grid[y][x])
		{
			if (cub->map.grid[y][x] == 'D')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	add_door(t_cub3d *cub, int x, int y, int *index)
{
	cub->doors[*index].x = x;
	cub->doors[*index].y = y;
	cub->doors[*index].state = DOOR_CLOSED;
	cub->doors[*index].anim_frame = 0;
	cub->doors[*index].anim_timer = 0;
	(*index)++;
}

static void	fill_doors(t_cub3d *cub)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (cub->map.grid[y] && cub->map.grid[y][x])
		{
			if (cub->map.grid[y][x] == 'D')
				add_door(cub, x, y, &index);
			x++;
		}
		y++;
	}
}

void	init_doors(t_cub3d *cub)
{
	cub->door_count = count_doors(cub);
	if (cub->door_count == 0)
	{
		cub->doors = NULL;
		return ;
	}
	cub->doors = malloc(sizeof(t_door) * cub->door_count);
	if (!cub->doors)
		err_exit(cub, ERR_MALLOC);
	fill_doors(cub);
}
