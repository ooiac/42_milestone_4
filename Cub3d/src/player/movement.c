/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:08:39 by smetz             #+#    #+#             */
/*   Updated: 2026/03/27 11:08:42 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_wall(t_cub3d *cub, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= cub->map.width
		|| map_y < 0 || map_y >= cub->map.height)
		return (1);
	if (cub->map.grid[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	move_forward(t_cub3d *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos_x + cub->player.dir_x * cub->player.move_speed;
	new_y = cub->player.pos_y + cub->player.dir_y * cub->player.move_speed;
	if (!is_wall(cub, new_x, cub->player.pos_y))
		cub->player.pos_x = new_x;
	if (!is_wall(cub, cub->player.pos_x, new_y))
		cub->player.pos_y = new_y;
}

void	move_backward(t_cub3d *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos_x - cub->player.dir_x * cub->player.move_speed;
	new_y = cub->player.pos_y - cub->player.dir_y * cub->player.move_speed;
	if (!is_wall(cub, new_x, cub->player.pos_y))
		cub->player.pos_x = new_x;
	if (!is_wall(cub, cub->player.pos_x, new_y))
		cub->player.pos_y = new_y;
}

void	strafe_left(t_cub3d *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos_x - cub->player.plane_x * cub->player.move_speed;
	new_y = cub->player.pos_y - cub->player.plane_y * cub->player.move_speed;
	if (!is_wall(cub, new_x, cub->player.pos_y))
		cub->player.pos_x = new_x;
	if (!is_wall(cub, cub->player.pos_x, new_y))
		cub->player.pos_y = new_y;
}

void	strafe_right(t_cub3d *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos_x + cub->player.plane_x * cub->player.move_speed;
	new_y = cub->player.pos_y + cub->player.plane_y * cub->player.move_speed;
	if (!is_wall(cub, new_x, cub->player.pos_y))
		cub->player.pos_x = new_x;
	if (!is_wall(cub, cub->player.pos_x, new_y))
		cub->player.pos_y = new_y;
}
