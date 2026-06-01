/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetz <smetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:10:29 by smetz             #+#    #+#             */
/*   Updated: 2026/03/27 11:10:31 by smetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	rotate_player(t_cub3d *cub, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(angle)
		- cub->player.dir_y * sin(angle);
	cub->player.dir_y = old_dir_x * sin(angle)
		+ cub->player.dir_y * cos(angle);
	old_plane_x = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x * cos(angle)
		- cub->player.plane_y * sin(angle);
	cub->player.plane_y = old_plane_x * sin(angle)
		+ cub->player.plane_y * cos(angle);
}

int	mouse_move(int x, int y, t_cub3d *cub)
{
	int		delta_x;
	double	rotation;

	(void)y;
	delta_x = x - cub->last_mouse_x;
	cub->last_mouse_x = x;
	if (delta_x == 0)
		return (0);
	rotation = delta_x * MOUSE_SENS;
	rotate_player(cub, rotation);
	if (x < 100 || x > WIN_WIDTH - 100)
	{
		mlx_mouse_move(cub->mlx, cub->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		cub->last_mouse_x = WIN_WIDTH / 2;
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_cub3d *cub)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT)
		shoot_weapon(cub);
	return (0);
}
