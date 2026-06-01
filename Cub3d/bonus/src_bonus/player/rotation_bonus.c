/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:50:55 by caida-si          #+#    #+#             */
/*   Updated: 2026/03/27 13:56:44 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	rotate_right(t_cub3d *cub)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot;

	rot = cub->player.rot_speed;
	old_dir_x = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(rot)
		- cub->player.dir_y * sin(rot);
	cub->player.dir_y = old_dir_x * sin(rot)
		+ cub->player.dir_y * cos(rot);
	old_plane_x = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x * cos(rot)
		- cub->player.plane_y * sin(rot);
	cub->player.plane_y = old_plane_x * sin(rot)
		+ cub->player.plane_y * cos(rot);
}

void	rotate_left(t_cub3d *cub)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot;

	rot = -cub->player.rot_speed;
	old_dir_x = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(rot)
		- cub->player.dir_y * sin(rot);
	cub->player.dir_y = old_dir_x * sin(rot)
		+ cub->player.dir_y * cos(rot);
	old_plane_x = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x * cos(rot)
		- cub->player.plane_y * sin(rot);
	cub->player.plane_y = old_plane_x * sin(rot)
		+ cub->player.plane_y * cos(rot);
}
